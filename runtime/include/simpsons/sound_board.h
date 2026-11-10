/**
 *    Name:        sound_board.h
 *    Description: the game's own sound board: the decompiled sound program (src/sound/) on its Z80's timing
 *                 model, the YM2151 and the K053260
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    06-11-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    Behavior follows MAME's konami/simpsons.cpp (z80_map, z80_bankswitch_w, z80_arm_nmi_w, z80_nmi_w, the
 *    routes' gains) and sound/k053260.cpp (its ports), as tools/core/konami/reference/sound/ksound_053260.cpp runs
 *    it with MAME's own chips: every sample and every byte of the Z80's RAM compare with it (kref
 *    --sound-board-check). No MAME code: the chips are runtime/src/ym2151.c and k053260.c.
 *
 *    The game drives it from the board's time (the 053248's cycles, SIMPSONS_CPU_CLOCK): the ports between the
 *    two CPUs are the board model's (simpsons_board.sound_ports: 0-1 the 053248 writes, which the Z80 reads at
 *    FC00-FC01; 2-3 the Z80's answers, FC02-FC03); before the 053248 reads or writes them or raises the Z80's
 *    IRQ (its read of 1FC4), the sound board catches up with the present (simpsons_sound_run); the IRQ stays
 *    up until the Z80 takes it, as MAME's HOLD_LINE (simpsons_sound_irq); at the end of a frame the frame's
 *    samples close (simpsons_sound_end_frame). The Z80's NMI is the K053260's: its timer's SH1 line, which
 *    raises it where a write of FA00 lowered it, after which the program waits for it (HALT).
 *
 *    The samples: the YM2151 and the K053260 each make one every 64 clocks of the Z80's clock (two outputs
 *    each); sample n of a chip is the one it makes from Z80 cycle 64 n on.
 */
#ifndef SIMPSONS_SOUND_BOARD_H
#define SIMPSONS_SOUND_BOARD_H

#include "simpsons/k053260.h"
#include "simpsons/machine.h"
#include "simpsons/ym2151.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* The Z80's stack (SP starts at F800; the deepest the program goes is a few calls and the interrupts' return
   addresses): the decompiled program keeps what the original pushes in its own variables, so the RAM's hash
   leaves these bytes out, the reference's too (ksound_053260.cpp). Nothing else of the program lives in
   F3D2-F7FF (its variables and records end at F3D1) */
#define SIMPSONS_SOUND_STACK_START   0xF780u
#define SIMPSONS_SOUND_STACK_END     0xF800u

typedef struct
{
	uint8_t ram[SIMPSONS_SOUND_RAM_SIZE];    /* the Z80's, F000-F7FF */
	uint8_t bank;                            /* FE00: the bank at 8000-BFFF (0-7) */
	uint8_t answers[2];                      /* FC02-FC03 as the Z80 last wrote them (the board's ports 2-3) */
	bool answers_to_board;                   /* the answers go to simpsons_board.sound_ports too (the game) */
	simpsons_ym2151 fm;
	simpsons_k053260 pcm;
} simpsons_sound_board;

extern simpsons_sound_board simpsons_sound;

/* Where the sound program's data byte at a place (its region's offset: 0000-7FFF, the banks' from 10000) is: the
   game's assets' pieces (game/assets.h's game_assets_sound_at); unset, game/data.h's game_sound, the ROM set's (the
   tools that check the board against MAME's). NULL where there is none (the program's code) */
extern const uint8_t *(*simpsons_sound_data)(uint32_t place);

/* The sound board at power on, at the board's present (simpsons_board.cycles): its chips on the samples' memory
   (game/data.h's game_samples), the program's tables and data where simpsons_sound_data says. NULL, or what
   failed */
const char *simpsons_sound_init(void);

/* Hooks it to the board model, for the game: before the 053248 reads or writes the ports or raises the Z80's
   IRQ (simpsons_board.sound_sync and sound_irq), the sound board catches up with the board's present
   (simpsons_board.cycles), and the Z80's answers go to the board's ports */
void simpsons_sound_attach(void);

/* The board's time moves on to 'time': the program runs up to its main loop's top past it */
void simpsons_sound_run(uint64_t time);

/* The 053248 raises the Z80's IRQ (its read of 1FC4): up until the Z80 takes it */
void simpsons_sound_irq(void);

/* Runs the board up to 'time' and closes the frame's samples: the ones each chip starts before it */
void simpsons_sound_end_frame(uint64_t time);

/* FNV-1a hashes of the frame just closed, as kref's --sound-hashes writes them: the samples of the two chips
   (the YM2151's, then the K053260's, each as MAME's floats), and the Z80's RAM without its stack, with the
   two answers */
uint64_t simpsons_sound_samples_hash(void);
uint64_t simpsons_sound_state_hash(void);

/* The frame's samples of each chip alone (0 the YM2151, 1 the K053260): which one differs */
void simpsons_sound_source_hashes(uint64_t hashes[2]);

/* The frame's samples mixed as MAME's routes do (the YM2151's first output to both sides at 0.5, the K053260's
   two to theirs at 0.5), stereo, at the chips' rate */
const int16_t *simpsons_sound_mix(size_t *count);
uint32_t simpsons_sound_mix_rate(void);

/* The Z80's time: the cycles of the timing model so far */
uint64_t simpsons_sound_z80_cycles(void);

/* The program's data at an address it holds (0000-7FFF the program, 8000-BFFF the bank FE00 chose): the
   program stops where no data is */
const uint8_t *simpsons_sound_data_at(uint32_t address);
/* The bytes at an address of the program's data as one record (a patch, a sample's, a song's header), a copy that
   holds until a few more are made: the assets keep each piece apart, and a record the program reads can run from one
   piece into the next (an FM patch's 25 bytes past a shorter piece) */
const void *simpsons_sound_record(uint32_t address);

#ifdef __cplusplus
}
#endif

#endif
