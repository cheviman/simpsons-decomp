/**
 *    Name:        k053260.c
 *    Description: Konami 053260 (KDSC) sound chip: four PCM or KADPCM voices from a sample ROM of up to 2 MB, and
 *                 a timer whose SH1 line is the Z80's NMI on this board
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    06-11-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    Behavior follows MAME 0.289's sound/k053260.cpp (Ernesto Corvi, Alex W. Jackson; BSD-3-Clause) sample for
 *    sample, and its sample ROM as the reference maps it (tools/core/konami/reference/sound/dirom.h: a region
 *    smaller than the 2 MB address space repeats over it). kref --sound-check compares the two. MAME's terms are
 *    in tools/core/konami/reference/mame/LICENSE.
 *
 *    How a voice plays: each sample its up counter goes 64 clocks on, and every time it passes 0x1000 it starts
 *    over from the pitch and the voice takes its next byte (PCM: the byte is the output) or nibble (KADPCM: the
 *    low nibble, then the high one, each a step from a table added to the output). The position moves on before
 *    it is read, so the first byte played is the one after the start; a voice in reverse reads down from the
 *    start. Past the length the voice stops, or starts over from the start's byte when it loops. Its output
 *    goes to each side times the volume and the pan's multiplier, and the four voices' sum is clamped to 16
 *    bits; with the output's bit of the mode register clear the chip is silent and its voices stand still.
 */
#include "simpsons/k053260.h"

#include <string.h>

#define ADDRESS_MASK        0x1fffffu   /* the ROM's 21 address lines */
#define COUNTER_WRAP        0x1000u     /* the up counter: a step of the position each time it passes this */
#define TIM2_PERIOD         112u        /* SH1's falls per TIM2 pulse: 56 kHz down to 500 Hz */

/* The registers the code names (the voices' are 08-27, eight each: pitch, length, start, volume) */
#define REG_VOICES          0x08
#define REG_VOICES_END      0x27
#define REG_KEY             0x28       /* bits 0-3 key on, 4-7 reverse */
#define REG_STATUS          0x29       /* read: the voices playing */
#define REG_LOOP_KADPCM     0x2a       /* bits 0-3 loop, 4-7 KADPCM */
#define REG_PAN_01          0x2c       /* bits 0-2 voice 0, 3-5 voice 1 */
#define REG_PAN_23          0x2d       /* voices 2 and 3 */
#define REG_ROM             0x2e       /* read: the ROM at voice 0's start plus its position */
#define REG_MODE            0x2f
#define MODE_ROM_READ       0x01
#define MODE_OUTPUT         0x02

/* The pan's multipliers, left and right, in 1.16: pan 0 is silent, 1-7 go from the left to the right at whole
   angles (0, 24, 35, 45, 55, 66 and 90 degrees) */
static const int32_t pan_multipliers[8][2] =
{
	{     0,     0 },
	{ 65536,     0 },
	{ 59870, 26656 },
	{ 53684, 37950 },
	{ 46341, 46341 },
	{ 37950, 53684 },
	{ 26656, 59870 },
	{     0, 65536 }
};

/* The step a KADPCM nibble adds to the output */
static const int8_t kadpcm_steps[16] = { 0, 1, 2, 4, 8, 16, 32, 64, -128, -64, -32, -16, -8, -4, -2, -1 };

static uint8_t rom_byte(const simpsons_k053260 *chip, uint32_t address)
{
	if (chip->rom == NULL || chip->rom_size == 0)
		return 0;
	return chip->rom[(address & ADDRESS_MASK) % chip->rom_size];
}

static int32_t clamp(int32_t value, int32_t low, int32_t high)
{
	if (value < low)
		return low;
	if (value > high)
		return high;
	return value;
}

/* ---- a voice ---- */

static void update_pan_volume(simpsons_k053260_voice *voice)
{
	voice->pan_volume[0] = voice->volume * pan_multipliers[voice->pan][0];
	voice->pan_volume[1] = voice->volume * pan_multipliers[voice->pan][1];
}

static void reset_voice(simpsons_k053260_voice *voice)
{
	memset(voice, 0, sizeof(*voice));
	update_pan_volume(voice);
}

/* One of its eight registers (the low 3 bits of 'offset') */
static void set_voice_register(simpsons_k053260_voice *voice, int offset, uint8_t data)
{
	switch (offset & 7)
	{
	case 0:     /* pitch, low 8 bits */
		voice->pitch = (uint16_t)((voice->pitch & 0x0f00u) | data);
		break;
	case 1:     /* pitch, high 4 bits */
		voice->pitch = (uint16_t)((voice->pitch & 0x00ffu) | (((uint32_t)data << 8) & 0x0f00u));
		break;
	case 2:     /* length, low 8 bits */
		voice->length = (uint16_t)((voice->length & 0xff00u) | data);
		break;
	case 3:     /* length, high 8 bits */
		voice->length = (uint16_t)((voice->length & 0x00ffu) | ((uint32_t)data << 8));
		break;
	case 4:     /* start, low 8 bits */
		voice->start = (voice->start & 0x1fff00u) | data;
		break;
	case 5:     /* start, middle 8 bits */
		voice->start = (voice->start & 0x1f00ffu) | ((uint32_t)data << 8);
		break;
	case 6:     /* start, high 5 bits */
		voice->start = (voice->start & 0x00ffffu) | (((uint32_t)data << 16) & 0x1f0000u);
		break;
	default:    /* volume, 7 bits */
		voice->volume = data & 0x7f;
		update_pan_volume(voice);
		break;
	}
}

static void set_pan(simpsons_k053260_voice *voice, uint8_t data)
{
	voice->pan = data & 7;
	update_pan_volume(voice);
}

/* Key on: the counter just short of its first step, so that the first sample takes the first byte. A KADPCM
   voice counts nibbles, its position's low bit the nibble: it starts at 1 since the position moves on before
   it is read */
static void voice_key_on(simpsons_k053260_voice *voice)
{
	voice->position = voice->kadpcm ? 1 : 0;
	voice->counter = (uint16_t)(COUNTER_WRAP - SIMPSONS_K053260_CLOCKS);
	voice->output = 0;
	voice->playing = true;
}

static void voice_key_off(simpsons_k053260_voice *voice)
{
	voice->position = 0;
	voice->output = 0;
	voice->playing = false;
}

/* A sample of a voice that plays, added to the outputs */
static void play_voice(const simpsons_k053260 *chip, simpsons_k053260_voice *voice, int32_t out[2])
{
	voice->counter = (uint16_t)(voice->counter + SIMPSONS_K053260_CLOCKS);
	while (voice->counter >= COUNTER_WRAP)
	{
		voice->counter = (uint16_t)(voice->counter - COUNTER_WRAP + voice->pitch);

		uint32_t byte = ++voice->position >> (voice->kadpcm ? 1 : 0);

		if (byte > voice->length)
		{
			if (!voice->loop)
			{
				voice->playing = false;
				return;
			}
			voice->position = 0;
			voice->output = 0;
			byte = 0;
		}

		uint8_t data = rom_byte(chip, voice->start + (voice->reverse ? 0u - byte : byte));

		if (voice->kadpcm)
		{
			/* the low nibble, then the high one */
			if (voice->position & 1)
				data >>= 4;
			voice->output = (int8_t)(voice->output + kadpcm_steps[data & 0xf]);
		}
		else
			voice->output = (int8_t)data;
	}
	out[0] += (voice->output * voice->pan_volume[0]) >> 15;
	out[1] += (voice->output * voice->pan_volume[1]) >> 15;
}

/* Register 2E: the ROM at voice 0's start plus its position, which moves on */
static uint8_t read_rom(const simpsons_k053260 *chip, simpsons_k053260_voice *voice)
{
	const uint32_t address = voice->start + voice->position;

	voice->position = (voice->position + 1) & 0xffffu;
	return rom_byte(chip, address);
}

/* ---- the chip ---- */

void simpsons_k053260_init(simpsons_k053260 *chip, const uint8_t *rom, uint32_t rom_size)
{
	memset(chip, 0, sizeof(*chip));
	chip->rom = rom;
	chip->rom_size = rom_size;
	simpsons_k053260_reset(chip);
}

void simpsons_k053260_reset(simpsons_k053260 *chip)
{
	for (int index = 0; index < SIMPSONS_K053260_VOICES; index++)
		reset_voice(&chip->voices[index]);
}

uint8_t simpsons_k053260_read(simpsons_k053260 *chip, int offset)
{
	offset &= 0x3f;
	switch (offset)
	{
	case REG_STATUS:
	{
		uint8_t status = 0;

		for (int index = 0; index < SIMPSONS_K053260_VOICES; index++)
			if (chip->voices[index].playing)
				status |= (uint8_t)(1u << index);
		return status;
	}
	case REG_ROM:
		if (chip->mode & MODE_ROM_READ)
			return read_rom(chip, &chip->voices[0]);
		return 0;
	default:
		/* 0-1 are the board's ports; the rest reads nothing */
		return 0;
	}
}

void simpsons_k053260_write(simpsons_k053260 *chip, int offset, uint8_t data)
{
	offset &= 0x3f;
	if (offset >= REG_VOICES && offset <= REG_VOICES_END)
	{
		set_voice_register(&chip->voices[(offset - REG_VOICES) / 8], offset, data);
		return;
	}
	switch (offset)
	{
	case REG_KEY:
	{
		/* a voice keys on where its bit goes up, and off where it is 0 */
		const uint8_t rising = (uint8_t)(data & ~chip->key_on);

		for (int index = 0; index < SIMPSONS_K053260_VOICES; index++)
		{
			simpsons_k053260_voice *voice = &chip->voices[index];

			voice->reverse = ((data >> (index | 4)) & 1) != 0;
			if ((rising >> index) & 1)
				voice_key_on(voice);
			else if (!((data >> index) & 1))
				voice_key_off(voice);
		}
		chip->key_on = data;
		break;
	}
	case REG_LOOP_KADPCM:
		for (int index = 0; index < SIMPSONS_K053260_VOICES; index++)
		{
			chip->voices[index].loop = ((data >> index) & 1) != 0;
			chip->voices[index].kadpcm = ((data >> (index | 4)) & 1) != 0;
		}
		break;
	case REG_PAN_01:
		set_pan(&chip->voices[0], data);
		set_pan(&chip->voices[1], (uint8_t)(data >> 3));
		break;
	case REG_PAN_23:
		set_pan(&chip->voices[2], data);
		set_pan(&chip->voices[3], (uint8_t)(data >> 3));
		break;
	case REG_MODE:
		/* bit 0 the ROM's read through 2E, bit 1 the output; bit 2 (the YM2151's input) and 3 change nothing */
		chip->mode = data;
		break;
	default:
		/* 0-3 are the board's ports; 4-7 and 2B are not used */
		break;
	}
}

bool simpsons_k053260_step_timer(simpsons_k053260 *chip)
{
	bool sh1_up = false;

	switch (chip->timer_state)
	{
	case 0:
		chip->sh1 = true;
		sh1_up = true;
		break;
	case 1:
		chip->sh1 = false;
		/* TIM2: two counters in series, a pulse every 112 falls of SH1 */
		if (++chip->tim2_count >= TIM2_PERIOD)
		{
			chip->tim2_count = 0;
			chip->tim2 = true;
		}
		else if (chip->tim2_count == 1)
			chip->tim2 = false;
		break;
	case 2:
		chip->sh2 = true;
		break;
	default:
		chip->sh2 = false;
		break;
	}
	chip->timer_state = (uint8_t)((chip->timer_state + 1) & 3);
	return sh1_up;
}

void simpsons_k053260_generate(simpsons_k053260 *chip, int32_t out[2])
{
	int32_t sum[2] = { 0, 0 };

	if (chip->mode & MODE_OUTPUT)
		for (int index = 0; index < SIMPSONS_K053260_VOICES; index++)
			if (chip->voices[index].playing)
				play_voice(chip, &chip->voices[index], sum);
	out[0] = clamp(sum[0], -32768, 32767);
	out[1] = clamp(sum[1], -32768, 32767);
}
