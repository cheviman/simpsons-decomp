/**
 *    Name:        game_program.c
 *    Description: the decompiled 053248 program (src/, tools/decompile.py) as a port runs it: its reset, its run,
 *                 the frames, the bank, the interrupt mask and the interrupts, and the program's data, from the
 *                 assets, by name and by the addresses it keeps
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    07-11-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    The program runs with frame timing, as the translation scaffold does (runtime/src/konami_cpu.c) and kref does
 *    by default (simpsons/frame.h): instructions take no time, and the board moves on to its next VBLANK where the
 *    program finds nothing to do (frame_wait, the port's program_frame). The interrupts the board raised are taken
 *    there, after the IRQ handler's FIRQ point, and after what can lift the mask (ANDCC, a PULLS of the CC), as MAME's
 *    core takes them between two instructions: the FIRQ first, when the CC's F lets it in, then the IRQ (I). The
 *    handler runs with its mask set (the FIRQ: I and F; the IRQ: I), and its RTI puts back the mask the interrupt
 *    found; it hands the interrupted code nothing: what the original pushes for it, the C keeps in its own variables
 *    (the 053248's stack is no state of the game's: the state hash leaves it out).
 *
 *    The program's data is its assets' (game/assets.h): the board's program region holds the bytes the assets give
 *    (runtime/src/game.c), and the program reads them through the bank the CPU has, as the original does: by name,
 *    the tables of src/table.c's registry, copied once with each element in the host's byte order; by the addresses
 *    the program keeps, data_at(). A byte only the original's code holds stops the program.
 */
#include "game/support.h"

#include "game/data.h"
#include "simpsons/frame.h"
#include "simpsons/machine.h"
#include "simpsons/program.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CC_F         0x40u
#define CC_I         0x10u
#define MASK_BITS    (CC_F | CC_I)
#define RECORD_COPIES 32
#define RECORD_SLACK  4u        /* the bytes past a record a read through it may reach (data_record) */
#define RECORD_MAX    64u

void (*program_frame)(void);

static uint32_t mask = CC_F | CC_I;     /* the CC's F and I: the reset sets both */
static uint32_t interrupts;
static bool tables_loaded;

/* ---- what the last code to run was (tools/decompile.py --trace): shown when the program stops ---- */
/* With SIMPSONS_TRACE=FILE and SIMPSONS_TRACE_FRAMES=FIRST-LAST in the environment, a traced build also writes every
   function and block those frames run, in order ("FRAME F|B PLACE"), to compare with kref --order (a development
   aid) */

#define TRACE_SIZE 48
static uint32_t traced[TRACE_SIZE];
static unsigned traced_count;
static FILE *trace_file;
static unsigned long long trace_first, trace_last;
static bool trace_opened;

static void trace_to_file(char kind, uint32_t place)
{
	if (!trace_opened)
	{
		const char *path = getenv("SIMPSONS_TRACE"), *frames = getenv("SIMPSONS_TRACE_FRAMES");

		trace_opened = true;
		if (path && frames && sscanf(frames, "%llu-%llu", &trace_first, &trace_last) == 2)
			trace_file = fopen(path, "w");
	}
	if (trace_file && simpsons_board.frame >= trace_first && simpsons_board.frame <= trace_last)
		fprintf(trace_file, "%llu %c %06X\n", (unsigned long long)simpsons_board.frame, kind, (unsigned)place);
}

void game_trace(uint32_t place)
{
	traced[traced_count++ % TRACE_SIZE] = place;
	trace_to_file('F', place);
}

void game_trace_block(uint32_t place)
{
	traced[traced_count++ % TRACE_SIZE] = place | 0x80000000u;
	trace_to_file('B', place);
}

static void show_trace(void)
{
	if (!traced_count)
		return;
	fprintf(stderr, "the last functions (F) and blocks (B) that ran:");
	for (unsigned index = traced_count > TRACE_SIZE ? traced_count - TRACE_SIZE : 0; index < traced_count; index++)
		fprintf(stderr, " %c%06X", traced[index % TRACE_SIZE] & 0x80000000u ? 'B' : 'F',
			(unsigned)traced[index % TRACE_SIZE] & 0xFFFFFFu);
	fprintf(stderr, "\n");
}

static GAME_NORETURN void stop(const char *what, uint32_t value)
{
	show_trace();
	fprintf(stderr, "053248 stopped: %s %06X (frame %llu)\n", what, (unsigned)value,
		(unsigned long long)simpsons_board.frame);
	exit(3);
}

/* ---- the program's data ---- */

/* The program's byte at a place (its region's offset): the assets' piece the board was given
   (simpsons_board.program_at), else game/data.h's game_program; NULL where there is none (code) */
static const uint8_t *program_byte(uint32_t place)
{
	return simpsons_board.program_at ? simpsons_board.program_at(place) : &game_program[place];
}

const uint8_t *data_at(uint32_t address)
{
	const int32_t place = simpsons_program_offset((uint16_t)address);
	const uint8_t *byte;

	if (place < 0)
	{
		if ((address & 0xFFFFu) >= SIMPSONS_WORK_RAM)
			return simpsons_work_ram_byte((uint16_t)address);    /* (a pointer the program set to the work RAM) */
		stop("the program read data at", address & 0xFFFFu);
	}
	if ((byte = program_byte((uint32_t)place)) == NULL)
		stop("the program read its code as data at", (uint32_t)place);
	return byte;
}

/* A record of the program's data, its bytes the other way round: from the work RAM where the program set the
   pointer there, else into one of a few copies (a record is read where the C names it: no pointer to one outlives
   its expression) */
const void *data_record(uint32_t address, uint32_t size)
{
	static uint8_t copies[RECORD_COPIES][RECORD_MAX + RECORD_SLACK];
	static unsigned next;
	uint8_t *copy;

	address &= 0xFFFFu;
	if (address >= SIMPSONS_WORK_RAM && address + size <= SIMPSONS_WORK_RAM + SIMPSONS_WORK_RAM_SIZE)
		return simpsons_work_ram_at((uint16_t)address, size);
	if (size > RECORD_MAX)
		stop("the program read a record too long at", address);
	copy = copies[next++ % RECORD_COPIES];
	/* (the record's first byte must be the program's data; the ones after it, where the assets give them, else 0: a
	   pointer the code walks to the end of a table names a record that runs into code, whose fields it does not read;
	   stage 3 at frame 7117 copied one from the end of an enemy's behaviour, 029910-029967, into the code at 029968) */
	copy[size + RECORD_SLACK - 1u] = *data_at(address);
	for (uint32_t at = 1; at < size; at++)
	{
		const int32_t place = simpsons_program_offset((uint16_t)(address + at));
		const uint8_t *byte = place >= 0 ? program_byte((uint32_t)place) : NULL;

		copy[size + RECORD_SLACK - 1u - at] = byte ? *byte : 0u;
	}
	/* (and the few bytes after it, where the assets give them: a word the program reads across the record's last
	   byte, which the C reads as a part of that field, AT16(record->field, -1)) */
	for (uint32_t at = size; at < size + RECORD_SLACK; at++)
	{
		const int32_t place = simpsons_program_offset((uint16_t)(address + at));
		const uint8_t *byte = place >= 0 ? program_byte((uint32_t)place) : NULL;

		copy[size + RECORD_SLACK - 1u - at] = byte ? *byte : 0u;
	}
	return copy + RECORD_SLACK;
}

/* How far before its place a table can be read: the CPU adds an index register's byte signed (A,X), so a table the C
   reads by such an index (NAME[(int8_t)a]) reaches back up to 128 bytes */
#define TABLE_BEFORE 0x80u

/* Every table of the registry: a copy of the data around its place, as far as the assets give bytes there (in its
   bank, or the fixed program): from its place on, and up to TABLE_BEFORE bytes before it in whole elements, each
   element in the host's byte order. The table's pointer is its place in the copy. NULL, or what failed */
static const char *load_tables(void)
{
	static char problem[160];

	for (size_t index = 0; index < game_table_count; index++)
	{
		const game_table *table = &game_tables[index];
		const uint32_t start = table->place >= GAME_PROGRAM_SIZE - 0x8000u ? GAME_PROGRAM_SIZE - 0x8000u
			: table->place / 0x2000u * 0x2000u;
		const uint32_t end = table->place >= GAME_PROGRAM_SIZE - 0x8000u ? GAME_PROGRAM_SIZE
			: (table->place / 0x2000u + 1u) * 0x2000u;
		uint32_t length = 0, before = 0;
		uint8_t *copy;

		if (!table->name)
			continue;
		while (table->place + length < end && program_byte(table->place + length))
			length++;
		if (!length)
		{
			snprintf(problem, sizeof(problem), "the program's table %s is in no asset", table->name);
			return problem;
		}
		while (before < TABLE_BEFORE && table->place - before > start && program_byte(table->place - before - 1u))
			before++;
		before -= before % table->element;
		copy = malloc(before + length + 4u);
		if (!copy)
		{
			snprintf(problem, sizeof(problem), "no memory for the program's table %s", table->name);
			return problem;
		}
		memset(copy, 0, before + length + 4u);
		for (uint32_t offset = 0; offset < before + length; offset++)
			copy[offset] = *program_byte(table->place - before + offset);
		/* (big endian to the host's: each element's bytes the other way round) */
		if (table->element > 1)
			for (uint32_t first = 0; first + table->element <= before + length; first += table->element)
				for (uint32_t low = first, high = first + table->element - 1u; low < high; low++, high--)
				{
					const uint8_t byte = copy[low];

					copy[low] = copy[high];
					copy[high] = byte;
				}
		*table->data = copy + before;
	}
	return NULL;
}

/* ---- what stops the program ---- */

void invalid_jump(uint32_t address)
{
	stop("a jump to an address no case of its switch has:", address & 0xFFFFu);
}

void lost_stack(uint32_t place)
{
	stop("a function the C cannot follow the stack of ran, at", place);
}

void illegal_opcode(uint32_t opcode)
{
	/* (MAME logs it and goes on: no code the analysis finds runs one) */
	(void)opcode;
}

/* ---- the bank, the mask, the interrupts and the frame ---- */

void set_lines(uint32_t value)
{
	simpsons_set_lines((uint8_t)value);
}

void enable_irq(void)
{
	mask &= ~CC_I;
}

void disable_irq(void)
{
	mask |= CC_I;
}

void enable_firq(void)
{
	mask &= ~CC_F;
}

void disable_firq(void)
{
	mask |= CC_F;
}

void and_mask(uint32_t cc)
{
	mask &= cc | ~MASK_BITS;
}

void or_mask(uint32_t cc)
{
	mask |= cc & MASK_BITS;
}

void restore_mask(uint32_t cc)
{
	mask = cc & MASK_BITS;
}

uint32_t interrupt_mask(void)
{
	return mask;
}

/* An interrupt's handler, with what the code carries in its registers (game_context) put back when it returns: the
   IRQ's handler finds every register saved on the stack and its RTI pulls them back (the 6809's E flag); the FIRQ's
   saves CC and PC only, and its handler pushes and pulls the registers it uses (0791B4 "PUSHS A"): either way the
   interrupted code finds its registers as it left them */
#define MAX_CONTEXT 8

static void run_handler(void (*handler)(void))
{
	uint16_t kept[MAX_CONTEXT];

	if (game_context_count > MAX_CONTEXT)
		stop("the program carries more values in its registers than the runtime keeps:", (uint32_t)game_context_count);
	for (size_t index = 0; index < game_context_count; index++)
		kept[index] = *game_context[index];
	handler();
	for (size_t index = 0; index < game_context_count; index++)
		*game_context[index] = kept[index];
}

void take_interrupts(void)
{
	for (;;)
	{
		const uint32_t found = mask;

		if (simpsons_board.firq && !(mask & CC_F))
		{
			mask |= CC_F | CC_I;
			interrupts++;
			run_handler(game_firq);
		}
		else if (simpsons_board.irq && !(mask & CC_I))
		{
			mask |= CC_I;
			interrupts++;
			run_handler(game_irq);
		}
		else
			return;
		mask = found;    /* (RTI: the CC the interrupt found) */
	}
}

void firq_point(void)
{
	simpsons_firq_point();
}

void frame_wait(uint32_t wait)
{
	simpsons_settle_shadow();    /* (what the program wrote through a pointer outside the work RAM, before the frame) */
	if (simpsons_frame_idle((uint16_t)wait) && program_frame)
		program_frame();
}

/* ---- the program as a port runs it (simpsons/program.h) ---- */

void program_reset(void)
{
	if (!tables_loaded)
	{
		const char *problem = load_tables();

		if (problem)
		{
			fprintf(stderr, "The game does not start: %s\n", problem);
			exit(1);
		}
		tables_loaded = true;
	}
	mask = CC_F | CC_I;
	interrupts = 0;
}

void program_run(void)
{
	game_entry();
	stop("the program came to its end after", 0);
}

uint32_t program_interrupts(void)
{
	return interrupts;
}

bool program_irq_masked(void)
{
	return (mask & CC_I) != 0;
}
