/**
 *    Name:        sound_internal.h
 *    Description: between the game's sound board (sound_board.c) and its Z80's timing model (sound_cpu.c)
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    06-11-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 */
#ifndef SIMPSONS_SOUND_INTERNAL_H
#define SIMPSONS_SOUND_INTERNAL_H

#include "simpsons/sound_board.h"

#include <stdbool.h>
#include <stdint.h>

/* The board's time when the Z80 has run 'cycles', and the first Z80 cycle at or after board time 'time' */
static inline uint64_t sound_board_time(uint64_t cycles)
{
	return cycles * SIMPSONS_CPU_CLOCK / SIMPSONS_SOUND_CLOCK;
}

static inline uint64_t sound_z80_time(uint64_t time)
{
	return (time * SIMPSONS_SOUND_CLOCK + SIMPSONS_CPU_CLOCK - 1) / SIMPSONS_CPU_CLOCK;
}

/* ---- the Z80 (sound_cpu.c) ---- */

/* At power on, at Z80 cycle 'cycle' */
void sound_cpu_reset(uint64_t cycle);
/* The program up to its main loop's top past board time 'until' */
void sound_cpu_run(uint64_t until);
/* The 053248's IRQ goes up */
void sound_cpu_irq(void);
/* A write of FA00: the NMI's line down, and the K053260's next SH1 pulse 4 cycles on or later raises it */
void sound_cpu_arm_nmi(void);
/* The Z80's time: where the running block's accesses happen, and where the next block starts */
uint64_t sound_cpu_access(void);
uint64_t sound_cpu_clock(void);

/* ---- the board (sound_board.c) ---- */

/* The Z80's bus: memory map and chips (MAME's simpsons.cpp z80_map) */
uint8_t sound_bus_read(uint16_t address);
void sound_bus_write(uint16_t address, uint8_t data);
/* The YM2151's timers due by Z80 cycle 'cycle', in the order they run out, and the K053260's timer steps */
void sound_timers_due(uint64_t cycle);

#endif
