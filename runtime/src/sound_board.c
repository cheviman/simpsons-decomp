/**
 *    Name:        sound_board.c
 *    Description: the game's own sound board: the Z80's memory map, the sound chips and their samples, the
 *                 frame's hashes and mix
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    06-11-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    Behavior follows MAME's konami/simpsons.cpp (Ernesto Corvi): z80_map, z80_bankswitch_w and the audio bank's
 *    entries, z80_arm_nmi_w, the routes' gains; sound/k053260.cpp's ports between the two CPUs; and how MAME's
 *    sound streams make their samples, as tools/core/konami/reference/sound/ksound_053260.cpp keeps them for the
 *    reference. MAME's terms are in tools/core/konami/reference/mame/LICENSE. Every chip catches up with the
 *    present (the running block's time) before the program writes it, and before it reads the YM2151 or the
 *    K053260's voices' status, as MAME's streams update before those.
 */
#include "sound_internal.h"

#include "game/data.h"
#include "sound/support.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

simpsons_sound_board simpsons_sound;

#define SAMPLE_CLOCKS 64    /* both chips' samples, on the Z80's clock */
#define TIMER_CLOCKS  16    /* the K053260's timer step */
#define NO_TIME UINT64_MAX

/* how many samples start before Z80 cycle 'cycle' */
static uint64_t samples_before(uint64_t cycle)
{
	return (cycle + SAMPLE_CLOCKS - 1) / SAMPLE_CLOCKS;
}

/* ---- a chip's samples: its two outputs interleaved, from sample number 'first' on ---- */

typedef struct
{
	float *data;
	size_t count, capacity;     /* values, not samples */
	uint64_t first;
	uint64_t made;              /* samples made so far */
	float *taken;               /* the frame's, taken out */
	size_t taken_count;
} samples;

static samples g_fm_samples, g_pcm_samples;

static void out_of_memory(void)
{
	fprintf(stderr, "The sound board ran out of memory for its samples\n");
	exit(3);
}

static void push(samples *source, const int32_t values[2])
{
	if (source->count + 2 > source->capacity)
	{
		source->capacity = source->count + 2 + source->count / 2 + 1024;
		source->data = (float *)realloc(source->data, source->capacity * sizeof(float));
		if (!source->data)
			out_of_memory();
	}
	/* as MAME's streams hand them: the value / 32768 */
	source->data[source->count++] = (float)values[0] * (1.0f / 32768.0f);
	source->data[source->count++] = (float)values[1] * (1.0f / 32768.0f);
	source->made++;
}

static void reset_samples(samples *source)
{
	source->count = 0;
	source->first = source->made = 0;
	source->taken_count = 0;
}

/* ---- time ---- */

static uint64_t g_now_override = NO_TIME;    /* while a timer runs out, its own time */

static uint64_t now(void)
{
	return g_now_override != NO_TIME ? g_now_override : sound_cpu_access();
}

/* ---- the YM2151 (its IRQ goes nowhere on this board) ---- */

static uint64_t g_deadline[2] = { NO_TIME, NO_TIME };
static uint64_t g_busy_until;

static void fm_catch_up(uint64_t cycle)
{
	const uint64_t due = samples_before(cycle);

	while (g_fm_samples.made < due)
	{
		int32_t output[2];

		simpsons_ym2151_generate(&simpsons_sound.fm, output);
		push(&g_fm_samples, output);
	}
}

static void fm_set_timer(void *host, int timer, int32_t clocks)
{
	(void)host;
	g_deadline[timer] = clocks < 0 ? NO_TIME : now() + (uint64_t)clocks;
}

static void fm_set_busy_end(void *host, uint32_t clocks)
{
	(void)host;
	g_busy_until = now() + clocks;
}

static bool fm_is_busy(void *host)
{
	(void)host;
	return now() < g_busy_until;
}

/* ---- the K053260 ---- */

static uint64_t g_timer_steps;    /* the timer's steps taken: step n is at Z80 cycle 16 (n + 1) */

static void pcm_catch_up(uint64_t cycle)
{
	const uint64_t due = samples_before(cycle);

	while (g_pcm_samples.made < due)
	{
		int32_t output[2];

		simpsons_k053260_generate(&simpsons_sound.pcm, output);
		push(&g_pcm_samples, output);
	}
}

void sound_timers_due(uint64_t cycle)
{
	for (;;)
	{
		const int timer = g_deadline[0] <= g_deadline[1] ? 0 : 1;
		const uint64_t when = g_deadline[timer];

		if (when > cycle)
			break;
		g_deadline[timer] = NO_TIME;
		fm_catch_up(when);
		g_now_override = when;
		simpsons_ym2151_timer_expired(&simpsons_sound.fm, timer);
		g_now_override = NO_TIME;
	}
	/* (its SH1 pulses are the NMI's, which the timing model works out: sound_cpu.c) */
	while (TIMER_CLOCKS * (g_timer_steps + 1) <= cycle)
	{
		(void)simpsons_k053260_step_timer(&simpsons_sound.pcm);
		g_timer_steps++;
	}
}

/* ---- the Z80's bus ---- */

const uint8_t *simpsons_sound_data_at(uint32_t address)
{
	address &= 0xFFFFu;
	if (address < 0x8000u)
		return &game_sound[address];
	if (address < 0xC000u)
	{
		/* the bank: entries 0-1 the region's 10000, then 4000 more each (simpsons.cpp's audio bank) */
		const uint32_t entry = simpsons_sound.bank;
		const uint32_t base = 0x10000u + (entry < 2u ? 0u : (entry - 2u) * 0x4000u);

		return &game_sound[base + (address - 0x8000u)];
	}
	fprintf(stderr, "Sound program data read at %04X, where no data is\n", (unsigned)address);
	exit(3);
}

uint8_t sound_bus_read(uint16_t address)
{
	if (address < 0xC000u)
		return *simpsons_sound_data_at(address);
	if (address >= 0xF000u && address < 0xF800u)
		return simpsons_sound.ram[address - 0xF000u];
	if (address == 0xF800u || address == 0xF801u)
	{
		fm_catch_up(now());
		return simpsons_ym2151_read(&simpsons_sound.fm, address & 1);
	}
	if (address >= 0xFC00u && address < 0xFC30u)
	{
		/* the 053248's two ports (the board's), then the chip's registers (the voices' status after its
		   samples up to the present) */
		if (address < 0xFC02u)
			return simpsons_board.sound_ports[address - 0xFC00u];
		if (address == 0xFC29u)
			pcm_catch_up(now());
		return simpsons_k053260_read(&simpsons_sound.pcm, address - 0xFC00u);
	}
	return 0;
}

void sound_bus_write(uint16_t address, uint8_t data)
{
	if (address >= 0xF000u && address < 0xF800u)
		simpsons_sound.ram[address - 0xF000u] = data;
	else if (address == 0xF800u || address == 0xF801u)
	{
		fm_catch_up(now());
		simpsons_ym2151_write(&simpsons_sound.fm, address & 1, data);
	}
	else if (address == 0xFA00u)
		sound_cpu_arm_nmi();
	else if (address >= 0xFC00u && address < 0xFC30u)
	{
		if (address == 0xFC02u || address == 0xFC03u)
		{
			/* the Z80's two ports, which the 053248 reads */
			simpsons_sound.answers[address - 0xFC02u] = data;
			if (simpsons_sound.answers_to_board)
				simpsons_board.sound_ports[address - 0xFC00u] = data;
		}
		else
		{
			pcm_catch_up(now());
			simpsons_k053260_write(&simpsons_sound.pcm, address - 0xFC00u, data);
		}
	}
	else if (address == 0xFE00u)
		simpsons_sound.bank = data & 7u;
}

/* ---- the board ---- */

const char *simpsons_sound_init(void)
{
	memset(&simpsons_sound, 0, sizeof(simpsons_sound));
	g_deadline[0] = g_deadline[1] = NO_TIME;
	g_busy_until = 0;
	g_now_override = NO_TIME;
	g_timer_steps = 0;
	reset_samples(&g_fm_samples);
	reset_samples(&g_pcm_samples);
	sound_cpu_reset(sound_z80_time(simpsons_board.cycles));

	simpsons_sound.fm.set_timer = fm_set_timer;
	simpsons_sound.fm.set_busy_end = fm_set_busy_end;
	simpsons_sound.fm.is_busy = fm_is_busy;
	simpsons_ym2151_init(&simpsons_sound.fm);
	simpsons_k053260_init(&simpsons_sound.pcm, game_samples, GAME_SAMPLES_SIZE);

	/* the tables the program reads by name: game/data.h's game_sound, which the tools fill from the ROM set and
	   the game from its assets */
	for (size_t index = 0; index < sound_table_count; index++)
		*sound_tables[index].data = &game_sound[sound_tables[index].address];
	return NULL;
}

void simpsons_sound_run(uint64_t time)
{
	sound_cpu_run(time);
}

static void sync_with_board(void)
{
	sound_cpu_run(simpsons_board.cycles);
}

void simpsons_sound_attach(void)
{
	simpsons_board.sound_sync = sync_with_board;
	simpsons_board.sound_irq = simpsons_sound_irq;
	simpsons_sound.answers_to_board = true;
}

void simpsons_sound_irq(void)
{
	sound_cpu_irq();
}

uint64_t simpsons_sound_z80_cycles(void)
{
	return sound_cpu_clock();
}

/* ---- the frame ---- */

static uint64_t g_frame_samples_hash;
static uint64_t g_source_hashes[2];
static int16_t *g_mix;
static size_t g_mix_count, g_mix_capacity;

static uint64_t hash_bytes(const void *data, size_t size, uint64_t hash)
{
	const uint8_t *bytes = (const uint8_t *)data;

	for (size_t index = 0; index < size; index++)
		hash = (hash ^ bytes[index]) * 0x100000001b3ull;
	return hash;
}

/* the chip's samples that start before 'due' out of it (into its 'taken'), into the hash */
static uint64_t take(samples *source, uint64_t due, uint64_t hash)
{
	const uint64_t available = source->count / 2;
	const uint64_t wanted = due - source->first;
	const size_t count = (size_t)(wanted < available ? wanted : available) * 2;

	free(source->taken);
	source->taken = (float *)malloc((count ? count : 1) * sizeof(float));
	if (!source->taken)
		out_of_memory();
	memcpy(source->taken, source->data, count * sizeof(float));
	source->taken_count = count;
	memmove(source->data, source->data + count, (source->count - count) * sizeof(float));
	source->count -= count;
	source->first += count / 2;
	return hash_bytes(source->taken, count * sizeof(float), hash);
}

static int16_t to_sample(float value)
{
	const int scaled = (int)(value * 32768.0f);

	return (int16_t)(scaled < -32768 ? -32768 : scaled > 32767 ? 32767 : scaled);
}

void simpsons_sound_end_frame(uint64_t time)
{
	const uint64_t cycle = sound_z80_time(time);
	uint64_t hash = 0xcbf29ce484222325ull;
	size_t count;

	sound_cpu_run(time);
	fm_catch_up(cycle);
	pcm_catch_up(cycle);

	/* the samples that start before the frame's end */
	hash = take(&g_fm_samples, samples_before(cycle), hash);
	g_frame_samples_hash = take(&g_pcm_samples, samples_before(cycle), hash);
	g_source_hashes[0] = hash_bytes(g_fm_samples.taken, g_fm_samples.taken_count * sizeof(float), 0xcbf29ce484222325ull);
	g_source_hashes[1] = hash_bytes(g_pcm_samples.taken, g_pcm_samples.taken_count * sizeof(float), 0xcbf29ce484222325ull);

	/* the mix (simpsons.cpp's routes to its stereo speaker): the YM2151's first output to both sides at 0.5, the
	   K053260's two to theirs at 0.5 */
	count = (g_fm_samples.taken_count < g_pcm_samples.taken_count ? g_fm_samples.taken_count : g_pcm_samples.taken_count) / 2;
	if (g_mix_capacity < count * 2)
	{
		g_mix_capacity = count * 2 + 1024;
		g_mix = (int16_t *)realloc(g_mix, g_mix_capacity * sizeof(int16_t));
		if (!g_mix)
			out_of_memory();
	}
	g_mix_count = 0;
	for (size_t index = 0; index < count; index++)
	{
		const float fm = g_fm_samples.taken[index * 2];

		g_mix[g_mix_count++] = to_sample(0.5f * fm + 0.5f * g_pcm_samples.taken[index * 2]);
		g_mix[g_mix_count++] = to_sample(0.5f * fm + 0.5f * g_pcm_samples.taken[index * 2 + 1]);
	}
}

uint64_t simpsons_sound_samples_hash(void)
{
	return g_frame_samples_hash;
}

void simpsons_sound_source_hashes(uint64_t hashes[2])
{
	hashes[0] = g_source_hashes[0];
	hashes[1] = g_source_hashes[1];
}

uint64_t simpsons_sound_state_hash(void)
{
	const size_t stack = SIMPSONS_SOUND_STACK_START - 0xF000u, above = SIMPSONS_SOUND_STACK_END - 0xF000u;
	uint64_t hash = hash_bytes(simpsons_sound.ram, stack, 0xcbf29ce484222325ull);

	hash = hash_bytes(simpsons_sound.ram + above, SIMPSONS_SOUND_RAM_SIZE - above, hash);
	return hash_bytes(simpsons_sound.answers, sizeof(simpsons_sound.answers), hash);
}

const int16_t *simpsons_sound_mix(size_t *count)
{
	*count = g_mix_count;
	return g_mix;
}

uint32_t simpsons_sound_mix_rate(void)
{
	return (uint32_t)(SIMPSONS_SOUND_CLOCK / SAMPLE_CLOCKS);
}
