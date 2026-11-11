/**
 *    Name:        support.h
 *    Description: what the decompiled 053248 program (src/) uses besides its own C: the work RAM, the program's data
 *                 from the assets, the board's devices on the bus, the bank, the frame and the interrupts, and the
 *                 CPU's arithmetic where the IR does not spell it out
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    07-11-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    The work RAM is the board's (simpsons/machine.h), which keeps it the other way round (the byte at the RAM's last
 *    address first), so that a value of the big-endian 053248 at any address is a plain lvalue of the host's, which
 *    is little endian: RAM16(address) is the 16-bit variable there, and ram.h (tools/decompile.py) names them. An
 *    array of the work RAM runs the other way in the host's memory: ram.h writes its elements as NAME(index), a macro
 *    of each element's place. A part of a variable is the host's part of it (AS8, AT8). The build turns strict
 *    aliasing off for this code.
 *
 *    The program's data is its assets' (game/assets.h), read through the bank the CPU has, as the program reads it: a
 *    table the C reads by name is NAME[i], a copy the loader makes of it with each element in the host's byte order
 *    (src/table.c's registry gives its place and the width of its elements); an address the program keeps in its
 *    variables (a pointer into its data) is a CPU address, which data_at() finds through the bank, and DATA16(address)
 *    reads the data there as the program has it, big endian. The board's devices (0000-3FFF: the palette, the
 *    K052109, the sprite RAM, the ports) are reached through the bus, by name: io_write8(IO_1FC2, value).
 */
#ifndef GAME_SUPPORT_H
#define GAME_SUPPORT_H

#include "konami/ops.h"
#include "simpsons/frame.h"
#include "simpsons/machine.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Functions that stop the game: the C compiler knows they do not come back */
#if defined(_MSC_VER)
#define GAME_NORETURN __declspec(noreturn)
#else
#define GAME_NORETURN _Noreturn
#endif

/* A game function the board puts its own in place of (runtime/replaced.txt): tools/decompile.py writes its
   definition as BOARD_ORIGINAL(name), which keeps the original as original_name */
#define BOARD_ORIGINAL(name) original_##name

/* ---- the work RAM ---- */

#define RAM8(address)   (*(uint8_t *)simpsons_work_ram_at((uint16_t)(address), 1u))
#define RAM16(address)  (*(uint16_t *)simpsons_work_ram_at((uint16_t)(address), 2u))
#define RAM8S(address)  (*(int8_t *)simpsons_work_ram_at((uint16_t)(address), 1u))
#define RAM16S(address) (*(int16_t *)simpsons_work_ram_at((uint16_t)(address), 2u))

/* A part of a variable, or a variable read with another width: 'offset' bytes from the host's start of it */
#define AS8(variable)  (*(uint8_t *)&(variable))
#define AS16(variable) (*(uint16_t *)&(variable))
#define AT8(variable, offset)  (*(uint8_t *)((uint8_t *)&(variable) + (offset)))
#define AT16(variable, offset) (*(uint16_t *)((uint8_t *)&(variable) + (offset)))

/* A structure of the game's in work RAM at 'address', 'size' bytes: the host's place of it, where it runs the other
   way round, so that ram.h declares its fields from its end */
#define ram(address, size) simpsons_work_ram_at((uint16_t)(address), (size))

/* ---- the program's data ---- */

/* The data at a CPU address the program holds, through the bank the CPU has: the assets' byte there (the work RAM's
   where the program set the pointer there). Where the assets have none (the program's code), the program stops */
const uint8_t *data_at(uint32_t address);

static inline uint32_t data8(uint32_t address)
{
	return *data_at(address);
}

static inline uint32_t data16(uint32_t address)
{
	return (uint32_t)*data_at(address) << 8 | *data_at((address + 1u) & 0xFFFFu);
}

/* A record of the program's data at an address the program holds: its 'size' bytes the other way round, as the work
   RAM's structures, so that ram.h declares its fields from its end too */
const void *data_record(uint32_t address, uint32_t size);

#define DATA8(address)   data8(address)
#define DATA16(address)  data16(address)
#define DATA8S(address)  ((int8_t)data8(address))
#define DATA16S(address) ((int16_t)data16(address))

/* A table the C reads by name (the registry, src/table.c): its name, its place in the program (the assets'), the
   pointer the loader sets to its copy, and the bytes of its elements, which the copy has in the host's order */
typedef struct
{
	const char *name;
	uint32_t place;
	const void **data;
	uint32_t element;
} game_table;

extern const game_table game_tables[];
extern const size_t game_table_count;

/* A table read with another width than its elements': 'offset' bytes into it, as the program has it */
#define TABLE8(table, offset)  DATA8(table##_ADDRESS + (offset))
#define TABLE16(table, offset) DATA16(table##_ADDRESS + (offset))

/* The start of the program bank's window (6000-7FFF), whatever bank the CPU's lines chose: where the fixed program reads
   data a bank holds at the same place in each (an animation bank's set index), in the bank it chose by a table */
#define BANK_WINDOW 0x6000u

/* A place in the 256-byte page 'base' points into, 'low' bytes from its start */
#define IN_PAGE(base, low) (((base) & ~0xFFu) | (low))

/* ---- the bus: the board's devices (0000-3FFF), and what a computed address reaches ---- */

static inline uint32_t mem_read8(uint32_t address)
{
	return simpsons_read((uint16_t)address);
}

static inline uint32_t mem_read16(uint32_t address)
{
	const uint32_t high = simpsons_read((uint16_t)address);

	return high << 8 | simpsons_read((uint16_t)(address + 1u));
}

static inline void mem_write8(uint32_t address, uint32_t data)
{
	simpsons_write((uint16_t)address, (uint8_t)data);
}

static inline void mem_write16(uint32_t address, uint32_t data)
{
	simpsons_write((uint16_t)address, (uint8_t)(data >> 8));
	simpsons_write((uint16_t)(address + 1u), (uint8_t)data);
}

#define io_read8(address)          mem_read8(address)
#define io_read16(address)         mem_read16(address)
#define io_write8(address, data)   mem_write8((address), (data))
#define io_write16(address, data)  mem_write16((address), (data))

/* ---- the CPU's arithmetic the IR leaves to helpers: the carry and the overflow of a + b + c, a - b - c ---- */

static inline uint32_t konami_carry_add8(uint32_t a, uint32_t b, uint32_t c)
{
	return (a & 0xFFu) + (b & 0xFFu) + (c & 1u) > 0xFFu;
}

static inline uint32_t konami_carry_add16(uint32_t a, uint32_t b, uint32_t c)
{
	return (a & 0xFFFFu) + (b & 0xFFFFu) + (c & 1u) > 0xFFFFu;
}

static inline uint32_t konami_carry_sub8(uint32_t a, uint32_t b, uint32_t c)
{
	return (a & 0xFFu) < (b & 0xFFu) + (c & 1u);
}

static inline uint32_t konami_carry_sub16(uint32_t a, uint32_t b, uint32_t c)
{
	return (a & 0xFFFFu) < (b & 0xFFFFu) + (c & 1u);
}

static inline uint32_t konami_overflow_add8(uint32_t a, uint32_t b, uint32_t c)
{
	const uint32_t r = a + b + (c & 1u);

	return ((a ^ r) & (b ^ r) & 0x80u) != 0;
}

static inline uint32_t konami_overflow_add16(uint32_t a, uint32_t b, uint32_t c)
{
	const uint32_t r = a + b + (c & 1u);

	return ((a ^ r) & (b ^ r) & 0x8000u) != 0;
}

static inline uint32_t konami_overflow_sub8(uint32_t a, uint32_t b, uint32_t c)
{
	const uint32_t r = a - b - (c & 1u);

	return ((a ^ b) & (a ^ r) & 0x80u) != 0;
}

static inline uint32_t konami_overflow_sub16(uint32_t a, uint32_t b, uint32_t c)
{
	const uint32_t r = a - b - (c & 1u);

	return ((a ^ b) & (a ^ r) & 0x8000u) != 0;
}

/* ---- the bank, the frame and the interrupts ---- */

/* SETLN: the CPU's output lines, the program bank at 6000-7FFF */
void set_lines(uint32_t value);

/* Where the program finds nothing to do until its next frame (simpsons/frame.h's waits): the board moves on to its
   next VBLANK (frame timing: instructions take no time); then the program takes the interrupts the board raised,
   and where its IRQ handler takes the sprite DMA's FIRQ (firq_point) */
void frame_wait(uint32_t wait);
void take_interrupts(void);
void firq_point(void);

/* The CC's interrupt mask (I: the IRQ, F: the FIRQ), the runtime's: ORCC and ANDCC set and clear it, a PULLS of the
   CC puts back what a PUSHS of it saved (with interrupt_mask(): the mask's bits of the CC) */
void enable_irq(void);
void disable_irq(void);
void enable_firq(void);
void disable_firq(void);
void and_mask(uint32_t cc);
void or_mask(uint32_t cc);
void restore_mask(uint32_t cc);
uint32_t interrupt_mask(void);

/* The code the board runs by itself (src/table.c) */
void game_entry(void);      /* the reset's */
void game_irq(void);        /* the IRQ's handler */
void game_firq(void);       /* the FIRQ's handler */

/* What the code carries in its registers from one routine to a later one, which the C keeps as globals (src/game.h,
   src/table.c): the runtime puts back what an interrupt's handler found there when the handler returns, as the CPU's
   RTI does */
extern uint16_t *const game_context[];
extern const size_t game_context_count;

/* The default of a switch on a jump's target, with decompile.py --checks: the original would jump to 'address', which
   no case handles */
GAME_NORETURN void invalid_jump(uint32_t address);

/* A function the C cannot follow the stack of, which only a mistaken table leads to: the program cannot go on */
GAME_NORETURN void lost_stack(uint32_t place);

/* An opcode the CPU does not know (MAME logs it and goes on): no code the analysis finds runs one */
void illegal_opcode(uint32_t opcode);

/* With tools/decompile.py --trace, every function calls game_trace when it starts and every block of code
   game_trace_block: the last ones are shown when the program stops */
void game_trace(uint32_t place);
void game_trace_block(uint32_t place);

#ifdef __cplusplus
}
#endif

/* where the C never goes: past a switch whose every case returns (C23's unreachable()) */
#ifndef unreachable
#if defined(_MSC_VER)
#define unreachable() __assume(0)
#else
#define unreachable() __builtin_unreachable()
#endif
#endif

#endif
