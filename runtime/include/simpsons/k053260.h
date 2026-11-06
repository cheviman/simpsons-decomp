/**
 *    Name:        k053260.h
 *    Description: Konami 053260 (KDSC) sound chip: four PCM or KADPCM voices from a sample ROM of up to 2 MB, and
 *                 a timer whose SH1 line is the Z80's NMI on this board
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    06-11-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    The game's own K053260 (no MAME code): every sample is the one MAME 0.289's k053260.cpp (Ernesto Corvi,
 *    Alex W. Jackson) makes from the same writes and reads (kref --sound-check compares them). A sample is made
 *    every 64 clocks of the chip (the sound board's 3.579545 MHz, SIMPSONS_SOUND_CLOCK): a left and a right
 *    one, each as MAME's stream clamps it to 16 bits (MAME's float is the value / 32768). The host makes the
 *    samples up to the present before every write and before a read of the voices' status (register 29), as
 *    MAME's stream does; a read of the ROM (register 2E) moves voice 0 on without that.
 *
 *    The timer steps every 16 clocks, the first 16 clocks after the reset (simpsons_k053260_step_timer): SH1 goes
 *    up at one step in four and down at the next, SH2 two steps later, and TIM2 pulses at every 112th fall of
 *    SH1 (2 ms). simpsons.cpp wires SH1 to the Z80's NMI (z80_nmi_w); SH2 and TIM2 go nowhere.
 *
 *    The four ports between the two CPUs (registers 0-3; 1FC6-1FC7 on the 053248's side) are the board's
 *    (simpsons_machine's sound_ports, runtime/src/machine.c and sound.c): the board answers them and hands the
 *    chip the rest of the Z80's FC00-FC2F, so here registers 0-3 read 0 and take no writes.
 */
#ifndef SIMPSONS_K053260_H
#define SIMPSONS_K053260_H

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SIMPSONS_K053260_VOICES        4
#define SIMPSONS_K053260_CLOCKS        64      /* the chip's clocks per sample */
#define SIMPSONS_K053260_TIMER_CLOCKS  16      /* the chip's clocks per step of its timer */

typedef struct
{
	/* where it plays */
	uint32_t position;              /* bytes (PCM) or nibbles (KADPCM) from the start, moved on before each read */
	int32_t pan_volume[2];          /* the volume times the pan's multiplier (1.16), left and right */
	uint16_t counter;               /* the pitch's up counter: a step of the position each time it passes 0x1000 */
	int8_t output;                  /* the last PCM byte, or the KADPCM sum */
	bool playing;
	/* its registers (8-27, eight a voice) and its bits of 28, 2A and 2C-2D */
	uint32_t start;                 /* 21 bits: one before the first byte played */
	uint16_t length;
	uint16_t pitch;                 /* 12 bits */
	uint8_t volume;                 /* 7 bits */
	uint8_t pan;                    /* 0 silent, 1-7 from left to right */
	bool loop;
	bool kadpcm;
	bool reverse;
} simpsons_k053260_voice;

typedef struct
{
	const uint8_t *rom;             /* the samples (the region repeats over the chip's 2 MB) */
	uint32_t rom_size;
	uint8_t key_on;                 /* register 28 as last written */
	uint8_t mode;                   /* register 2F: bit 0 the ROM's read through 2E, bit 1 the sound's output */
	uint8_t timer_state;            /* the timer's step: 0 SH1 up, 1 SH1 down, 2 SH2 up, 3 SH2 down */
	uint8_t tim2_count;             /* SH1's falls toward the next TIM2 pulse (112) */
	bool sh1, sh2, tim2;            /* the lines */
	simpsons_k053260_voice voices[SIMPSONS_K053260_VOICES];
} simpsons_k053260;

/* Sets the chip up on its sample ROM and resets it (MAME's constructor, device_start and device_reset) */
void simpsons_k053260_init(simpsons_k053260 *chip, const uint8_t *rom, uint32_t rom_size);

/* The reset: the voices stop and forget their registers (the timer starts over: its first step is 16 clocks on) */
void simpsons_k053260_reset(simpsons_k053260 *chip);

/* The Z80's registers, FC00-FC3F (offset 0-3F; the board keeps 0-3) */
uint8_t simpsons_k053260_read(simpsons_k053260 *chip, int offset);
void simpsons_k053260_write(simpsons_k053260 *chip, int offset, uint8_t data);

/* A step of the timer (every 16 clocks): whether SH1 went up at it (on this board, the Z80's NMI) */
bool simpsons_k053260_step_timer(simpsons_k053260 *chip);

/* The next sample: left and right, each clamped to -32768..32767 (MAME's stream: value / 32768) */
void simpsons_k053260_generate(simpsons_k053260 *chip, int32_t out[2]);

#ifdef __cplusplus
}
#endif

#endif
