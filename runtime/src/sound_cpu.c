/**
 *    Name:        sound_cpu.c
 *    Description: runs the decompiled sound program on the sound board's time: the Z80's timing model
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    06-11-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    The sound program is C (src/sound/, tools/decompile_sound.py) and keeps the Z80's time itself: every
 *    basic block of the original starts with z80_block(cycles). The rules, the same that
 *    tools/core/konami/reference/sound/ksound_053260.cpp keeps around MAME's Z80 with kref --sound-timing (the
 *    table tools/decompile_sound.py writes, build/sound/timing.txt), so that the two compare sample for sample:
 *      - the Z80's time counts in its own cycles from the board's time 0 and moves on by each block's cycles
 *        (tools/core/z80/timing.py) and the extra cycles of a condition's longer way; the board's time is
 *        SIMPSONS_CPU_CLOCK / SIMPSONS_SOUND_CLOCK board cycles a Z80 cycle, rounded down;
 *      - when a block starts, the YM2151's timers due by then run out and the K053260's timer steps, and the
 *        Z80 takes the 053248's interrupt if the line is up and it lets interrupts in (not right after an EI
 *        that ended the block before): 13 cycles, the line goes down (MAME's HOLD_LINE), then the handler
 *        (sound_command, 0038); after it returns the same is looked at again. The main loop lets interrupts in
 *        for four NOPs (EI ... DI): a block starts after the first of them (game_profile's
 *        SOUND_INTERRUPT_WINDOWS), where the interrupt comes in;
 *      - everything a block reads and writes happens at the time it starts;
 *      - HALT (z80_halt; the program's only one waits for the K053260 to see a voice keyed off, 0EB3): a write
 *        of FA00 lowered the NMI's line, and the K053260's SH1 raises it at its first pulse 4 cycles after the
 *        write or later (simpsons.cpp's z80_arm_nmi_w and z80_nmi_w); SH1 pulses at every fourth step of the
 *        K053260's timer, which steps every 16 cycles from cycle 16 (the pulses at cycles 16 + 64 k). The
 *        halted Z80 runs NOPs of 4 cycles from the HALT on, and takes the NMI after the one in which it came:
 *        11 cycles, then its handler (nmi_return, 0066: RETN) and the block after the HALT;
 *      - LDIR and LDDR (move_block): the block counts the last byte's 16 cycles, every other byte adds 21;
 *      - the board runs the program whenever its time moves on (simpsons_sound_run): from its reset, then the
 *        main loop again and again until the Z80's time is past the board's (the loop's top, 0B3D, where the
 *        program polls the YM2151's timer B: sound_symbols.txt's "loop" line). A pass waits there for timer B
 *        (some 2 ms), so the Z80 may be a pass ahead of the board; the 053248 only reaches it through the ports
 *        and the interrupt, which the Z80 takes at the next pass's EI.
 *    The reset's ROM test is the board's (runtime/sound_replaced.txt): the game has no program ROM to add up.
 *    A jump of the program to its reset (command FF, 0499) leaves whatever it was in: the board starts the
 *    reset again from its own loop, as the Z80's stack starts over (sound_reset).
 */
#include "sound_internal.h"

#include "sound.h"

#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>

#define INTERRUPT_CYCLES 13     /* IM 1: the acknowledge, RST 38 */
#define NMI_CYCLES       11     /* the NMI's acknowledge: the return address pushed, on to 0066 */
#define HALT_STEP        4      /* the NOP a halted Z80 runs */
#define REPEAT_CYCLES    21     /* a repeat of LDIR or LDDR */
#define SH1_FIRST        16     /* the K053260's first SH1 pulse, and the pulses' period */
#define SH1_PERIOD       64
#define NMI_BLOCK        4      /* z80_arm_nmi_w: a pulse within 4 cycles of the write does not raise the NMI */

static struct
{
	uint64_t clock;             /* where the next block starts, Z80 cycles */
	uint64_t access;            /* where the running block's reads and writes happen */
	uint64_t nmi_from;          /* the first cycle an SH1 pulse raises the NMI at: 4 after FA00's write */
	bool interrupts;            /* IFF1 */
	bool after_ei;              /* EI ended the block before */
	bool line;                  /* the 053248's IRQ, up until the Z80 takes it */
	bool running;               /* past the reset code: the main loop runs */
	bool in_program;            /* the board's loop runs the program: a jump to the reset starts it over */
	jmp_buf loop_top;           /* where that reset hands the board back its loop */
} z80;

void sound_cpu_reset(uint64_t cycle)
{
	z80.clock = z80.access = cycle;
	z80.nmi_from = 0;
	z80.interrupts = z80.after_ei = z80.line = z80.running = z80.in_program = false;
}

uint64_t sound_cpu_access(void)
{
	return z80.access;
}

uint64_t sound_cpu_clock(void)
{
	return z80.clock;
}

void sound_cpu_irq(void)
{
	z80.line = true;
}

void sound_cpu_arm_nmi(void)
{
	z80.nmi_from = z80.access + NMI_BLOCK;
}

void sound_cpu_run(uint64_t until)
{
	if (setjmp(z80.loop_top) == 0 && !z80.running)
	{
		z80.running = true;
		(void)BOARD_ORIGINAL(sound_reset)();
	}
	/* (after a jump to the reset, the reset has run up to the loop's top: the loop goes on from there) */
	z80.in_program = true;
	while (sound_board_time(z80.clock) < until)
		sound_main_loop();
	z80.in_program = false;
}

/* ---- what the program calls ---- */

void z80_block(int cycles)
{
	for (;;)
	{
		sound_timers_due(z80.clock);
		if (!z80.interrupts || z80.after_ei || !z80.line)
			break;
		z80.interrupts = false;
		z80.line = false;
		z80.clock += INTERRUPT_CYCLES;
		sound_command();
	}
	z80.after_ei = false;
	z80.access = z80.clock;
	z80.clock += (uint64_t)cycles;
}

void z80_cycles(int cycles)
{
	z80.clock += (uint64_t)cycles;
}

void z80_halt(void)
{
	const bool interrupts = z80.interrupts;
	uint64_t nmi = SH1_FIRST;

	/* the first SH1 pulse that raises the NMI, and the halted NOPs up to the one it comes in */
	if (z80.nmi_from > SH1_FIRST)
		nmi = SH1_FIRST + (z80.nmi_from - SH1_FIRST + SH1_PERIOD - 1) / SH1_PERIOD * SH1_PERIOD;
	if (nmi > z80.clock)
		z80.clock += (nmi - z80.clock + HALT_STEP - 1) / HALT_STEP * HALT_STEP;
	/* the NMI: IFF1 off for its handler, back from IFF2 (unchanged) at its RETN */
	z80.clock += NMI_CYCLES;
	z80.interrupts = false;
	nmi_return();
	z80.interrupts = interrupts;
}

void interrupts_on(void)
{
	z80.interrupts = true;
}

void interrupts_on_after_block(void)
{
	z80.interrupts = true;
	z80.after_ei = true;
}

void interrupts_off(void)
{
	z80.interrupts = false;
}

uint8_t z80_read8(uint16_t address)
{
	return sound_bus_read(address);
}

uint16_t z80_read16(uint16_t address)
{
	const uint8_t low = sound_bus_read(address);

	return (uint16_t)(low | sound_bus_read((uint16_t)(address + 1u)) << 8);
}

void z80_write8(uint16_t address, uint8_t value)
{
	sound_bus_write(address, value);
}

void z80_write16(uint16_t address, uint16_t value)
{
	sound_bus_write(address, (uint8_t)value);
	sound_bus_write((uint16_t)(address + 1u), (uint8_t)(value >> 8));
}

void move_block(uint16_t source, uint16_t destination, uint16_t count, uint32_t upward)
{
	const uint32_t bytes = count ? count : 0x10000u;

	for (uint32_t moved = 0; moved < bytes; moved++)
	{
		sound_bus_write(destination, sound_bus_read(source));
		source = (uint16_t)(upward ? source + 1u : source - 1u);
		destination = (uint16_t)(upward ? destination + 1u : destination - 1u);
	}
	z80.clock += (uint64_t)REPEAT_CYCLES * (bytes - 1u);
}

void sound_invalid_jump(uint32_t address)
{
	fprintf(stderr, "Sound program: a jump to %04X, which no handler has\n", (unsigned)address);
	exit(3);
}

/* ---- the board's own in place of the program's (runtime/sound_replaced.txt) ---- */

/* The reset. Run by the board at power on, it runs up to the main loop's top and returns; reached by the program
   itself (command FF: "JP 0000" from the interrupt's handler), it does the same, and then the board leaves what
   the program was in and goes on with its loop, as the Z80 does from the reset's "LD SP,F800" */
uint16_t sound_reset(void)
{
	(void)BOARD_ORIGINAL(sound_reset)();
	if (z80.in_program)
		longjmp(z80.loop_top, 1);
	return 0;
}

/* The ROM test. The original, BOARD_ORIGINAL(check_rom), adds up the program's 32 KB (0000-7FFF) and the banks
   2-7 (8000-BFFF, choosing each at FE00) a byte at a time into program_rom_sum, and marks the test failed (bit 1
   of self_test_failures) unless the sum is 072E, before it goes on to sound_main. The game has no program ROM to
   add up: the board answers as good chips do, leaves the bank where the test leaves it, and the test takes the
   time it takes on them, its blocks as the original's C counts them (20 cycles, then 56 a byte; 30 before each
   bank's; 71 at the end) */
uint16_t check_rom(void)
{
	z80_block(20);
	for (uint32_t address = 0; address < 0x8000u; address++)
		z80_block(56);
	for (uint8_t bank = 2; bank <= 7; bank++)
	{
		z80_block(30);
		z80_write8(0xFE00u, bank);
		for (uint32_t address = 0x8000u; address < 0xC000u; address++)
			z80_block(56);
	}
	z80_block(71);
	program_rom_sum = 0x072Eu;
	return sound_main();
}
