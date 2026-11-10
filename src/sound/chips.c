/**
 *    Name:        chips.c
 *    Description: the records' handlers and the chips: the YM2151's registers, patches, volumes, pitches, keys, LFO and pan; the K053260's voices
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the Z80 sound program decompiled into C by
 *    tools/decompile_sound.py, with the names of sound_symbols.txt.
 */
#include "sound.h"

/* Stops what the record plays: key off, the fastest release, its sound and priority 0, its handler
   channel_idle. */
void stop_channel(uint16_t channel)
{
	uint16_t handler = 0;

	z80_block(17);
	key_off(channel);
	z80_block(17);
	fast_release(channel);
	z80_block(48);
	CHANNEL(channel)->sound = 0u;
	CHANNEL(channel)->priority = 0u;
	handler = channel_idle_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The routine that runs the record from its next pass on. */
void set_channel_handler(uint16_t handler, uint16_t channel)
{
	z80_block(38);
	CHANNEL(channel)->handler = handler;
	channel_idle();
}

/* A free record's handler: nothing. */
void channel_idle(void)
{
	z80_block(10);
}

/* Writes a register of the record's YM2151 channel: the register given plus its chip_channel. */
void write_fm_channel_register(uint16_t fm_write, uint16_t channel)
{
	z80_block(27);
	fm_write = (fm_write & 0xFFu) | ((uint32_t)(uint8_t)(CHANNEL(channel)->chip_channel + (fm_write >> 8)) << 8);
	write_fm_register(fm_write);
}

/* Writes a register of the YM2151, each byte once the chip's busy flag is clear. */
void write_fm_register(uint16_t fm_write)
{
	for (;;)
	{
		z80_block(27);
		if ((z80_read8(FM_F801) & 0x80u) == 0u)
			break;
		z80_cycles(5);
	}
	z80_block(17);
	z80_write8(FM_F800, fm_write >> 8);
	for (;;)
	{
		z80_block(27);
		if ((z80_read8(FM_F801) & 0x80u) == 0u)
			break;
		z80_cycles(5);
	}
	z80_block(27);
	z80_write8(FM_F801, (uint8_t)fm_write);
}

/* Starts the YM2151's timer B again (register 12 at F9: some 2 ms) and clears its flag: the main loop's
   pace. */
void restart_frame_timer(void)
{
	uint16_t fm_write = 0;

	z80_block(27);
	fm_write = 0x1420u;
	write_fm_register(fm_write);
	z80_block(27);
	fm_write = 0x12F9u;
	write_fm_register(fm_write);
	z80_block(20);
	fm_write = 0x140Au;
	write_fm_register(fm_write);
}

/* Loads a patch into the record's channel: on the YM2151 (keyed off and released at the fastest first)
   its 25 bytes into the operators' registers, the connection, the total levels and the release rates
   kept in the record, then update_volume; on the K053260, pcm_load_patch. */
void load_patch(uint16_t patch, uint16_t channel)
{
	uint8_t c1_release = 0, c2_release = 0, connection = 0, m1_release = 0, m2_release = 0;
	uint16_t fm_write = 0;

	z80_block(36);
	if (CHANNEL(channel)->chip_channel >= 8u)
	{
		pcm_load_patch(patch, channel);
		return;
	}
	z80_block(17);
	key_off(channel);
	z80_block(17);
	fast_release(channel);
	z80_block(50);
	connection = FM_PATCH(patch)->connection;
	CHANNEL(channel)->connection = connection;
	fm_write = 0x2000u | connection;
	write_fm_channel_register(fm_write, channel);
	z80_block(37);
	patch++;
	fm_write = 0x4000u | FM_PATCH(patch - 0x1u)->m1_detune_multiple;
	write_fm_channel_register(fm_write, channel);
	z80_block(69);
	patch++;
	CHANNEL(channel)->m1_total_level = FM_PATCH(patch - 0x2u)->m1_total_level;
	patch++;
	fm_write = 0x8000u | FM_PATCH(patch - 0x3u)->m1_attack;
	write_fm_channel_register(fm_write, channel);
	z80_block(37);
	patch++;
	fm_write = 0xA000u | FM_PATCH(patch - 0x4u)->m1_decay_1;
	write_fm_channel_register(fm_write, channel);
	z80_block(37);
	patch++;
	fm_write = 0xC000u | FM_PATCH(patch - 0x5u)->m1_decay_2;
	write_fm_channel_register(fm_write, channel);
	z80_block(56);
	patch++;
	m1_release = FM_PATCH(patch - 0x6u)->m1_release;
	CHANNEL(channel)->m1_release = m1_release;
	fm_write = 0xE000u | m1_release;
	write_fm_channel_register(fm_write, channel);
	z80_block(37);
	patch++;
	fm_write = 0x5000u | FM_PATCH(patch - 0x7u)->c1_detune_multiple;
	write_fm_channel_register(fm_write, channel);
	z80_block(69);
	patch++;
	CHANNEL(channel)->c1_total_level = FM_PATCH(patch - 0x8u)->c1_total_level;
	patch++;
	fm_write = 0x9000u | FM_PATCH(patch - 0x9u)->c1_attack;
	write_fm_channel_register(fm_write, channel);
	z80_block(37);
	patch++;
	fm_write = 0xB000u | FM_PATCH(patch - 0xAu)->c1_decay_1;
	write_fm_channel_register(fm_write, channel);
	z80_block(37);
	patch++;
	fm_write = 0xD000u | FM_PATCH(patch - 0xBu)->c1_decay_2;
	write_fm_channel_register(fm_write, channel);
	z80_block(56);
	patch++;
	c1_release = FM_PATCH(patch - 0xCu)->c1_release;
	CHANNEL(channel)->c1_release = c1_release;
	fm_write = 0xF000u | c1_release;
	write_fm_channel_register(fm_write, channel);
	z80_block(37);
	patch++;
	fm_write = 0x4800u | FM_PATCH(patch - 0xDu)->m2_detune_multiple;
	write_fm_channel_register(fm_write, channel);
	z80_block(69);
	patch++;
	CHANNEL(channel)->m2_total_level = FM_PATCH(patch - 0xEu)->m2_total_level;
	patch++;
	fm_write = 0x8800u | FM_PATCH(patch - 0xFu)->m2_attack;
	write_fm_channel_register(fm_write, channel);
	z80_block(37);
	patch++;
	fm_write = 0xA800u | FM_PATCH(patch - 0x10u)->m2_decay_1;
	write_fm_channel_register(fm_write, channel);
	z80_block(37);
	patch++;
	fm_write = 0xC800u | FM_PATCH(patch - 0x11u)->m2_decay_2;
	write_fm_channel_register(fm_write, channel);
	z80_block(56);
	patch++;
	m2_release = FM_PATCH(patch - 0x12u)->m2_release;
	CHANNEL(channel)->m2_release = m2_release;
	fm_write = 0xE800u | m2_release;
	write_fm_channel_register(fm_write, channel);
	z80_block(37);
	patch++;
	fm_write = 0x5800u | FM_PATCH(patch - 0x13u)->c2_detune_multiple;
	write_fm_channel_register(fm_write, channel);
	z80_block(69);
	patch++;
	CHANNEL(channel)->c2_total_level = FM_PATCH(patch - 0x14u)->c2_total_level;
	patch++;
	fm_write = 0x9800u | FM_PATCH(patch - 0x15u)->c2_attack;
	write_fm_channel_register(fm_write, channel);
	z80_block(37);
	patch++;
	fm_write = 0xB800u | FM_PATCH(patch - 0x16u)->c2_decay_1;
	write_fm_channel_register(fm_write, channel);
	z80_block(37);
	patch++;
	fm_write = 0xD800u | FM_PATCH(patch - 0x17u)->c2_decay_2;
	write_fm_channel_register(fm_write, channel);
	z80_block(56);
	c2_release = FM_PATCH(patch - 0x17u)->c2_release;
	CHANNEL(channel)->c2_release = c2_release;
	fm_write = 0xF800u | c2_release;
	write_fm_channel_register(fm_write, channel);
	z80_block(10);
	update_volume(channel);
}

/* A K053260 voice's patch: the voice keyed off, its sample's registers (samples) into the voice's, the
   voice's KADPCM bit as the sample's kadpcm says, the patch's level and decay_step into the record, then
   update_volume. */
void pcm_load_patch(uint16_t patch, uint16_t channel)
{
	uint8_t keys = 0, modes = 0;
	uint16_t pcm_patch = 0, sample_entry = 0;
	uint16_t saved_patch = 0;

	z80_block(255);
	keys = pcm_keys & CHANNEL(channel)->pcm.key_mask;
	pcm_keys = keys;
	z80_write8(PCM_FC28, keys);
	saved_patch = patch;
	sample_entry = PCM_PATCH(patch)->sample * 2u * 2u * 2u + samples_ADDRESS;
	move_block(sample_entry, CHANNEL(channel)->pcm.registers, 7u, 1u);
	modes = pcm_modes & CHANNEL(channel)->pcm.kadpcm_mask;
	if (SAMPLE(sample_entry)->kadpcm & 1u)
	{
		z80_block(19);
		modes |= CHANNEL(channel)->pcm.kadpcm_bit;
	}
	z80_block(110);
	pcm_modes = modes;
	z80_write8(PCM_FC2A, modes);
	pcm_patch = saved_patch + 1u;
	CHANNEL(channel)->pcm.level = PCM_PATCH(pcm_patch - 0x1u)->level;
	CHANNEL(channel)->pcm.decay_step = PCM_PATCH(pcm_patch - 0x1u)->decay_step;
	update_volume(channel);
}

/* The record's volume (an attenuation: 0 the loudest, 7F silent), then update_volume. */
void set_volume(uint16_t channel, uint8_t volume)
{
	z80_block(19);
	CHANNEL(channel)->volume = volume;
	update_volume(channel);
}

/* The record's volume to its chip: on the YM2151 the four operators' total levels, the volume added to
   the carriers' (carrier_masks, by the algorithm in connection); on the K053260, pcm_update_volume. */
void update_volume(uint16_t channel)
{
	uint8_t c1_total_level = 0, c2_total_level = 0, m1_total_level = 0, m2_total_level = 0;
	uint16_t carriers = 0, fm_write = 0;

	z80_block(36);
	if (CHANNEL(channel)->chip_channel >= 8u)
	{
		pcm_update_volume(channel);
		return;
	}
	z80_block(108);
	carriers = carrier_masks[CHANNEL(channel)->connection & 7u];
	m1_total_level = CHANNEL(channel)->m1_total_level;
	fm_write = 0x6000u;
	carriers = write_operator_level(fm_write, carriers, channel, m1_total_level);
	z80_block(43);
	m2_total_level = CHANNEL(channel)->m2_total_level;
	fm_write = 0x6800u;
	carriers = write_operator_level(fm_write, carriers, channel, m2_total_level);
	z80_block(43);
	c1_total_level = CHANNEL(channel)->c1_total_level;
	fm_write = 0x7000u;
	carriers = write_operator_level(fm_write, carriers, channel, c1_total_level);
	z80_block(26);
	c2_total_level = CHANNEL(channel)->c2_total_level;
	fm_write = 0x7800u;
	write_operator_level(fm_write, carriers, channel, c2_total_level);
}

/* One operator's total level: the volume added (at most 7F) when the carriers' mask says it is a
   carrier; hands the mask back shifted for the next operator. */
uint16_t write_operator_level(uint16_t fm_write, uint16_t carriers, uint16_t channel, uint8_t level)
{
	uint32_t carry = 0;
	uint8_t mask = 0;
	uint16_t next_carriers = 0;
	uint8_t t1 = 0;

	mask = (uint8_t)carriers;
	z80_block(18);
	carry = mask >> 7;
	mask = (uint32_t)mask << 1;
	if (carry)
	{
		z80_block(29);
		t1 = level + CHANNEL(channel)->volume;
		level = t1;
		if ((int8_t)t1 < 0)
		{
			z80_block(7);
			level = 0x7Fu;
		}
	}
	z80_block(14);
	fm_write = (fm_write & ~0xFFu) | level;
	next_carriers = (carriers & ~0xFFu) | mask;
	write_fm_channel_register(fm_write, channel);
	return next_carriers;
}

/* A K053260 voice's volume register: 7F less the volume, the patch's level and the decay (each sum at
   most 7F), and 0 below 4. */
void pcm_update_volume(uint16_t channel)
{
	uint8_t attenuation = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(48);
	t1 = CHANNEL(channel)->volume + CHANNEL(channel)->pcm.level;
	attenuation = t1;
	if ((int8_t)t1 < 0)
	{
		z80_block(7);
		attenuation = 0x7Fu;
	}
	z80_block(29);
	t2 = attenuation + CHANNEL(channel)->pcm.decay;
	attenuation = t2;
	if ((int8_t)t2 < 0)
	{
		z80_block(7);
		attenuation = 0x7Fu;
	}
	z80_block(28);
	attenuation = ~attenuation & 0x7Fu;
	if (attenuation < 4u)
	{
		z80_block(4);
		attenuation = 0u;
	}
	z80_block(76);
	z80_write8((uint16_t)(CHANNEL(channel)->pcm.registers + 7u), attenuation);
}

/* The record's pitch to its chip: on the YM2151 the key fraction and the key code (note_codes; its high
   byte's octaves wrap past 8); on the K053260, pcm_set_pitch. */
void set_pitch(uint16_t pitch, uint16_t channel)
{
	uint8_t note = 0;
	uint16_t fm_write = 0;
	uint8_t t1 = 0;

	z80_block(36);
	if (CHANNEL(channel)->chip_channel >= 8u)
	{
		pcm_set_pitch(pitch, channel);
		return;
	}
	z80_block(11);
	note = (pitch >> 8) & 0x1Fu;
	do
	{
		z80_block(17);
		t1 = note;
		note = t1 - 0x18u;
	} while (t1 >= 0x18u);
	z80_block(61);
	pitch = ((pitch & 0xFFu) | ((uint32_t)(uint8_t)(note + 0x18u) << 8)) * 2u * 2u;
	fm_write = 0x3000u | (uint8_t)pitch;
	write_fm_channel_register(fm_write, channel);
	z80_block(56);
	fm_write = 0x2800u | note_codes[pitch >> 8];
	write_fm_channel_register(fm_write, channel);
}

/* A K053260 voice's pitch registers. */
void pcm_set_pitch(uint16_t pitch, uint16_t channel)
{
	uint16_t registers = 0, voice_pitch = 0;

	z80_block(72);
	voice_pitch = pitch;
	registers = CHANNEL(channel)->pcm.registers;
	z80_write16(registers, voice_pitch);
}

/* Keys the record's channel on: on the YM2151 its four operators; on the K053260, pcm_key_on. */
void key_on(uint16_t channel)
{
	uint8_t chip_channel = 0;
	uint16_t fm_write = 0;

	z80_block(36);
	chip_channel = CHANNEL(channel)->chip_channel;
	if (chip_channel >= 8u)
	{
		pcm_key_on(channel);
		return;
	}
	z80_block(28);
	fm_write = 0x800u | chip_channel | 0x78u;
	write_fm_register(fm_write);
}

/* Keys a K053260 voice on, unless pcm_keyed says it is: its key bit off, then the NMI armed and a wait
   for it (the chip takes the new sample), the key bit on, pcm_keyed set, the decay back to 0 and
   update_volume. */
void pcm_key_on(uint16_t channel)
{
	uint8_t keys = 0;

	z80_block(37);
	if ((pcm_keyed & CHANNEL(channel)->pcm.key_bit) != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(165);
	keys = pcm_keys & CHANNEL(channel)->pcm.key_mask;
	pcm_keys = keys;
	z80_write8(PCM_FC28, keys);
	pcm_keyed |= CHANNEL(channel)->pcm.key_bit;
	keys = pcm_keys | CHANNEL(channel)->pcm.key_bit;
	pcm_keys = keys;
	z80_write8(NMI_ARM_FA00, keys);
	z80_halt();
	z80_block(42);
	z80_write8(PCM_FC28, keys);
	CHANNEL(channel)->pcm.decay = 0u;
	update_volume(channel);
}

/* Keys the record's channel off: on the YM2151 its four operators; on the K053260, pcm_key_off. */
void key_off(uint16_t channel)
{
	uint8_t chip_channel = 0;
	uint16_t fm_write = 0;

	z80_block(36);
	chip_channel = CHANNEL(channel)->chip_channel;
	if (chip_channel >= 8u)
	{
		pcm_key_off(channel);
		return;
	}
	z80_block(21);
	fm_write = 0x800u | chip_channel;
	write_fm_register(fm_write);
}

/* Clears a K053260 voice's bit of pcm_keyed, if set: its sample plays on to its end. */
void pcm_key_off(uint16_t channel)
{
	z80_block(37);
	if ((pcm_keyed & CHANNEL(channel)->pcm.key_bit) == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(55);
	pcm_keyed &= CHANNEL(channel)->pcm.key_mask;
}

/* On the YM2151 the four operators' release at its fastest; on the K053260, pcm_fast_release. */
void fast_release(uint16_t channel)
{
	uint16_t fm_write = 0;

	z80_block(36);
	if (CHANNEL(channel)->chip_channel >= 8u)
	{
		pcm_fast_release(channel);
		return;
	}
	z80_block(31);
	fm_write = 0xE0FFu;
	write_fm_channel_register(fm_write, channel);
	z80_block(31);
	fm_write = 0xF0FFu;
	write_fm_channel_register(fm_write, channel);
	z80_block(31);
	fm_write = 0xE8FFu;
	write_fm_channel_register(fm_write, channel);
	z80_block(24);
	fm_write = 0xF8FFu;
	write_fm_channel_register(fm_write, channel);
}

/* A K053260 voice's decay at 7F: silent at the next volume. */
void pcm_fast_release(uint16_t channel)
{
	z80_block(29);
	CHANNEL(channel)->pcm.decay = 0x7Fu;
}

/* Unused: puts a YM2151 channel's release rates back as its patch had them (after fast_release). */
void restore_release(uint16_t channel)
{
	uint16_t fm_write = 0;

	z80_block(31);
	if (CHANNEL(channel)->chip_channel >= 8u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(43);
	fm_write = 0xE000u | CHANNEL(channel)->m1_release;
	write_fm_channel_register(fm_write, channel);
	z80_block(43);
	fm_write = 0xF000u | CHANNEL(channel)->c1_release;
	write_fm_channel_register(fm_write, channel);
	z80_block(43);
	fm_write = 0xE800u | CHANNEL(channel)->m2_release;
	write_fm_channel_register(fm_write, channel);
	z80_block(36);
	fm_write = 0xF800u | CHANNEL(channel)->c2_release;
	write_fm_channel_register(fm_write, channel);
}

/* The YM2151's LFO phase modulation depth (register 19 with bit 7). */
void set_lfo_pm_depth(uint8_t depth)
{
	uint16_t fm_write = 0;

	z80_block(28);
	fm_write = 0x1900u | depth | 0x80u;
	write_fm_register(fm_write);
}

/* The YM2151's LFO amplitude modulation depth (register 19 without bit 7). */
void set_lfo_am_depth(uint8_t depth)
{
	uint16_t fm_write = 0;

	z80_block(28);
	fm_write = 0x1900u | (depth & 0x7Fu);
	write_fm_register(fm_write);
}

/* A YM2151 channel's phase modulation sensitivity (register 38's bits 4-6), kept in lfo_sensitivity;
   nothing on the K053260. */
void set_channel_pm_sensitivity(uint16_t channel, uint8_t sensitivity)
{
	uint8_t bits = 0, lfo_sensitivity = 0;
	uint16_t fm_write = 0;

	z80_block(58);
	sensitivity &= 7u;
	sensitivity = ((uint32_t)sensitivity << 1) | (sensitivity >> 7);
	sensitivity = ((uint32_t)sensitivity << 1) | (sensitivity >> 7);
	sensitivity = ((uint32_t)sensitivity << 1) | (sensitivity >> 7);
	bits = ((uint32_t)sensitivity << 1) | (sensitivity >> 7);
	if (CHANNEL(channel)->chip_channel >= 8u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(70);
	lfo_sensitivity = (CHANNEL(channel)->lfo_sensitivity & 3u) | bits;
	CHANNEL(channel)->lfo_sensitivity = lfo_sensitivity;
	fm_write = 0x3800u | lfo_sensitivity;
	write_fm_channel_register(fm_write, channel);
}

/* A YM2151 channel's amplitude modulation sensitivity (register 38's bits 0-1), kept in lfo_sensitivity;
   nothing on the K053260. */
void set_channel_am_sensitivity(uint16_t channel, uint8_t sensitivity)
{
	uint8_t bits = 0, lfo_sensitivity = 0;
	uint16_t fm_write = 0;

	z80_block(42);
	bits = sensitivity & 3u;
	if (CHANNEL(channel)->chip_channel >= 8u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(70);
	lfo_sensitivity = (CHANNEL(channel)->lfo_sensitivity & 0x70u) | bits;
	CHANNEL(channel)->lfo_sensitivity = lfo_sensitivity;
	fm_write = 0x3800u | lfo_sensitivity;
	write_fm_channel_register(fm_write, channel);
}

/* The YM2151's LFO frequency (register 18). */
void set_lfo_frequency(uint8_t frequency)
{
	uint16_t fm_write = 0;

	z80_block(21);
	fm_write = 0x1800u | frequency;
	write_fm_register(fm_write);
}

/* The YM2151's LFO waveform (register 1B). */
void set_lfo_waveform(uint8_t waveform)
{
	uint16_t fm_write = 0;

	z80_block(21);
	fm_write = 0x1B00u | waveform;
	write_fm_register(fm_write);
}

/* The record's pan: a YM2151 channel's outputs (1 left, 2 right, 3 both: register 20's bits 6-7, kept in
   connection), or a K053260 voice's pan (1 left to 7 right) in its pan register, kept in pcm_pans_1 or
   pcm_pans_2. */
void set_pan(uint16_t channel, uint8_t pan)
{
	uint8_t bits = 0, chip_channel = 0, connection = 0, pans = 0;
	uint16_t fm_write = 0;

	z80_block(40);
	bits = pan;
	chip_channel = CHANNEL(channel)->chip_channel;
	if (chip_channel >= 8u)
	{
		z80_block(10);
		if (chip_channel == 8u)
		{
			z80_block(60);
			pans = (pcm_pans_1 & 0x38u) | bits;
			pcm_pans_1 = pans;
			z80_write8(PCM_FC2C, pans);
			return;
		}
		z80_block(17);
		if (chip_channel == 9u)
		{
			z80_block(84);
			pans = (pcm_pans_1 & 7u) | ((((uint32_t)bits << 1) << 1) << 1);
			pcm_pans_1 = pans;
			z80_write8(PCM_FC2C, pans);
			return;
		}
		z80_block(17);
		if (chip_channel == 0xAu)
		{
			z80_block(60);
			pans = (pcm_pans_2 & 0x38u) | bits;
			pcm_pans_2 = pans;
			z80_write8(PCM_FC2D, pans);
			return;
		}
		z80_block(84);
		pans = (pcm_pans_2 & 7u) | ((((uint32_t)bits << 1) << 1) << 1);
		pcm_pans_2 = pans;
		z80_write8(PCM_FC2D, pans);
		return;
	}
	z80_block(86);
	bits = (bits >> 1) | ((uint32_t)bits << 7);
	connection = (CHANNEL(channel)->connection & 0x3Fu) | (bits >> 1) | ((uint32_t)bits << 7);
	CHANNEL(channel)->connection = connection;
	fm_write = 0x2000u | connection;
	write_fm_channel_register(fm_write, channel);
}

/* On FM_7, the YM2151's noise off (register 0F). */
void noise_off(uint16_t channel)
{
	uint16_t fm_write = 0;

	z80_block(31);
	if (CHANNEL(channel)->chip_channel != 7u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(24);
	fm_write = 0xF00u;
	write_fm_register(fm_write);
}

/* Unused: on FM_7, the YM2151's noise on at the frequency given (register 0F). */
void noise_on(uint16_t channel, uint8_t noise_frequency)
{
	uint8_t noise = 0;
	uint16_t fm_write = 0;

	z80_block(42);
	noise = noise_frequency | 0x80u;
	if (CHANNEL(channel)->chip_channel != 7u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(17);
	fm_write = 0xF00u | noise;
	write_fm_register(fm_write);
}

/* Whether the record's K053260 voice still plays (its bit of the chip's status); a YM2151 record says it
   does. */
uint32_t pcm_voice_playing(uint16_t channel)
{
	uint32_t zero = 0;
	uint8_t chip_channel = 0;

	z80_block(31);
	chip_channel = CHANNEL(channel)->chip_channel;
	zero = (uint8_t)(chip_channel - 8u) == 0u;
	if (chip_channel < 8u)
	{
		z80_cycles(6);
		return zero;
	}
	z80_block(42);
	zero = (z80_read8(PCM_FC29) & CHANNEL(channel)->pcm.key_bit) == 0u;
	return zero;
}

/* Unused: the byte at byte_pointer, which moves on by one within its page (sound_main points it at the
   program's bytes). */
uint8_t next_pointer_byte(void)
{
	uint8_t value = 0;
	uint16_t pointer = 0;

	z80_block(53);
	pointer = byte_pointer;
	value = z80_read8(pointer);
	byte_pointer = IN_PAGE(pointer, (uint8_t)(pointer + 1u));
	return value;
}
