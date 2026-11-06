/**
 *    Name:        konami_cpu.c
 *    Description: the runtime of the translated 053248 program: the helpers and effects of its IR, calls and jumps
 *                 through computed addresses in the bank the CPU has, the interrupts and the frame
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    06-11-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    Behavior follows MAME's Konami CPU core (src/devices/cpu/m6809: konami.lst, base6x09.lst; Nathan Woods), as
 *    tools/core/konami_cpu/interpreter.py does it: an IRQ pushes the entire state (E set: PC, U, Y, X, DP, B, A, CC)
 *    and sets I; a FIRQ pushes the PC and the CC (E clear) and sets I and F; then the vector is read. The FIRQ goes
 *    first, as the core's MAIN takes it. The frame timing is tools/core/konami/reference/kref's --timing frames
 *    (simpsons/frame.h).
 */
#include "konami/code.h"
#include "konami/cpu.h"
#include "konami/ops.h"
#include "simpsons/frame.h"
#include "simpsons/machine.h"
#include "simpsons/program.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CALLS 4096
#define VECTOR_FIRQ 0xFFF6u
#define VECTOR_IRQ 0xFFF8u
#define VECTOR_RESET 0xFFFEu

konami_cpu cpu;
void (*program_frame)(void);

static uint32_t calls[MAX_CALLS];     /* the return addresses the calls wait for, the last one on top */
static size_t call_depth;

/* the last call that came back somewhere else (konami_returned_to), for the messages */
static uint32_t past_from;
static uint32_t past_expected;
static uint32_t past_to;

/* ---- the bus ---- */

uint32_t mem_read8(uint32_t address)
{
	return simpsons_read((uint16_t)address);
}

void mem_write8(uint32_t address, uint8_t data)
{
	simpsons_write((uint16_t)address, data);
}

/* ---- the CC and the stack ---- */

static uint32_t read_cc(void)
{
	return (uint32_t)cpu.e << 7 | (uint32_t)cpu.f << 6 | (uint32_t)cpu.h << 5 | (uint32_t)cpu.i << 4
		| (uint32_t)cpu.n << 3 | (uint32_t)cpu.z << 2 | (uint32_t)cpu.v << 1 | cpu.c;
}

static void write_cc(uint32_t value)
{
	cpu.e = (uint8_t)(value >> 7 & 1u);
	cpu.f = (uint8_t)(value >> 6 & 1u);
	cpu.h = (uint8_t)(value >> 5 & 1u);
	cpu.i = (uint8_t)(value >> 4 & 1u);
	cpu.n = (uint8_t)(value >> 3 & 1u);
	cpu.z = (uint8_t)(value >> 2 & 1u);
	cpu.v = (uint8_t)(value >> 1 & 1u);
	cpu.c = (uint8_t)(value & 1u);
}

static void push8(uint32_t value)
{
	cpu.s = (cpu.s - 1u) & 0xFFFFu;
	mem_write8(cpu.s, (uint8_t)value);
}

static void push16(uint32_t value)
{
	push8(value & 0xFFu);
	push8(value >> 8 & 0xFFu);
}

static uint32_t pull8(void)
{
	const uint32_t value = mem_read8(cpu.s);

	cpu.s = (cpu.s + 1u) & 0xFFFFu;
	return value;
}

static uint32_t pull16(void)
{
	const uint32_t high = pull8();

	return high << 8 | pull8();
}

/* ---- the effects ---- */

void konami_set_lines(uint32_t value)
{
	simpsons_set_lines((uint8_t)value);
}

void konami_rti(void)
{
	write_cc(pull8());
	if (cpu.e)
	{
		cpu.a = pull8();
		cpu.b = pull8();
		cpu.dp = pull8();
		cpu.x = pull16();
		cpu.y = pull16();
		cpu.u = pull16();
	}
	cpu.pc = pull16();
}

void konami_bmove(void)
{
	while (cpu.u)
	{
		const uint32_t value = mem_read8(cpu.y);

		cpu.y = (cpu.y + 1u) & 0xFFFFu;
		mem_write8(cpu.x, (uint8_t)value);
		cpu.x = (cpu.x + 1u) & 0xFFFFu;
		cpu.u = (cpu.u - 1u) & 0xFFFFu;
	}
}

void konami_bset(void)
{
	while (cpu.u)
	{
		mem_write8(cpu.x, (uint8_t)cpu.a);
		cpu.x = (cpu.x + 1u) & 0xFFFFu;
		cpu.u = (cpu.u - 1u) & 0xFFFFu;
	}
}

void konami_bsetw(void)
{
	while (cpu.u)
	{
		mem_write8(cpu.x, (uint8_t)cpu.a);
		cpu.x = (cpu.x + 1u) & 0xFFFFu;
		mem_write8(cpu.x, (uint8_t)cpu.b);
		cpu.x = (cpu.x + 1u) & 0xFFFFu;
		cpu.u = (cpu.u - 1u) & 0xFFFFu;
	}
}

void konami_illegal(uint32_t opcode)
{
	/* (MAME logs it and goes on: no program the analysis finds runs one) */
	(void)opcode;
}

/* ---- calls and jumps through computed addresses ---- */

/* The place of a CPU address in the bank the CPU has: the window's bank, the fixed program above */
static int32_t place_of(uint32_t address)
{
	return simpsons_program_offset((uint16_t)address);
}

static const konami_code_entry *find_code(uint32_t place)
{
	size_t low = 0, high = konami_code_entry_count;

	while (low < high)
	{
		const size_t middle = (low + high) / 2;
		if (konami_code_entries[middle].place < place)
			low = middle + 1;
		else
			high = middle;
	}
	return low < konami_code_entry_count && konami_code_entries[low].place == place ? &konami_code_entries[low]
		: NULL;
}

static void run_code(uint32_t address, uint32_t from)
{
	const int32_t place = place_of(address);
	const konami_code_entry *code = place >= 0 ? find_code((uint32_t)place) : NULL;

	if (!code)
	{
		fprintf(stderr, "No translated code starts at %04X (bank %02X), reached from %06X (frame %llu)\n",
			address & 0xFFFFu, simpsons_board.bank, from, (unsigned long long)simpsons_board.frame);
		exit(3);
	}
	code->function();
}

void konami_calls_push(uint32_t address)
{
	if (call_depth == MAX_CALLS)
	{
		fprintf(stderr, "More than %d calls nest (frame %llu)\n", MAX_CALLS, (unsigned long long)simpsons_board.frame);
		exit(3);
	}
	calls[call_depth++] = address & 0xFFFFu;
}

bool konami_returned_to(uint32_t expected, uint32_t from)
{
	if (call_depth)
		call_depth--;
	if ((cpu.pc & 0xFFFFu) == (expected & 0xFFFFu))
		return true;
	past_from = from;
	past_expected = expected;
	past_to = cpu.pc;
	return false;
}

void konami_call(uint32_t address, uint32_t from)
{
	run_code(address, from);
}

void konami_jump(uint32_t address, uint32_t from)
{
	/* to a return address a call waits for: a return, to that call */
	for (size_t depth = call_depth; depth > 0; depth--)
		if (calls[depth - 1] == (address & 0xFFFFu))
		{
			cpu.pc = address & 0xFFFFu;
			return;
		}
	run_code(address, from);
}

/* ---- interrupts and frames ---- */

void konami_take_interrupts(uint32_t resume)
{
	for (;;)
	{
		const uint32_t sp = cpu.s;
		uint32_t vector, handler;

		if (simpsons_board.firq && !cpu.f)
		{
			cpu.e = 0;
			push16(resume);
			push8(read_cc());
			cpu.i = cpu.f = 1;
			vector = VECTOR_FIRQ;
		}
		else if (simpsons_board.irq && !cpu.i)
		{
			cpu.e = 1;
			push16(resume);
			push16(cpu.u);
			push16(cpu.y);
			push16(cpu.x);
			push8(cpu.dp);
			push8(cpu.b);
			push8(cpu.a);
			push8(read_cc());
			cpu.i = 1;
			vector = VECTOR_IRQ;
		}
		else
			return;
		handler = mem_read8(vector) << 8 | mem_read8(vector + 1u);
		cpu.interrupts++;
		konami_calls_push(resume);
		run_code(handler, resume);
		/* the handler comes back into the code it interrupted, on its stack */
		if (!konami_returned_to(resume, handler) || cpu.s != sp)
		{
			fprintf(stderr, "The interrupt taken before %04X came back to %04X with S %04X (it was %04X) (frame %llu)\n",
				resume & 0xFFFFu, cpu.pc & 0xFFFFu, cpu.s, sp, (unsigned long long)simpsons_board.frame);
			exit(3);
		}
	}
}

void konami_frame_wait(uint32_t pc)
{
	if (simpsons_frame_idle((uint16_t)pc) && program_frame)
		program_frame();
}

void konami_firq_point(void)
{
	simpsons_firq_point();
}

/* ---- the program as a port runs it (simpsons/program.h) ---- */

void program_reset(void)
{
	/* (MAME's reset: DP 0, I and F set, the PC from the reset vector, read as data) */
	memset(&cpu, 0, sizeof(cpu));
	call_depth = 0;
	cpu.i = cpu.f = 1;
	cpu.pc = mem_read8(VECTOR_RESET) << 8 | mem_read8(VECTOR_RESET + 1u);
}

void program_run(void)
{
	const uint32_t start = cpu.pc;

	run_code(start, start);
	fprintf(stderr, "The program came to its end at %04X (frame %llu)\n", cpu.pc & 0xFFFFu,
		(unsigned long long)simpsons_board.frame);
	if (past_to)
		fprintf(stderr, "The last call that came back somewhere else: from %06X, to %04X instead of %04X\n",
			past_from, past_to & 0xFFFFu, past_expected & 0xFFFFu);
	exit(3);
}

uint32_t program_interrupts(void)
{
	return cpu.interrupts;
}
