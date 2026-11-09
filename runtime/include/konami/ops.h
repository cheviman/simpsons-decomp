/**
 *    Name:        ops.h
 *    Description: what the translated Konami CPU program calls: the helpers and effects of its IR, its calls,
 *                 jumps and returns through the runtime, its interrupts and its frames
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    Behavior follows MAME's Konami CPU core (src/devices/cpu/m6809: konami.lst, base6x09.lst; Nathan Woods), as
 *    tools/core/konami_cpu/interpreter.py does it (the lift's oracle checks that one against MAME's core).
 *    It needs none of the translation scaffold's CPU (konami/cpu.h): the decompiled program uses these helpers with
 *    its own memory access (game/support.h).
 */
#ifndef KONAMI_OPS_H
#define KONAMI_OPS_H

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ---- the IR's operators (v60/emit_c.py writes them for every CPU) ---- */

static inline uint32_t shl32(uint32_t value, int count)
{
	return (count & 31) ? value << (count & 31) : value;
}

static inline uint32_t shr32(uint32_t value, int count)
{
	return (count & 31) ? value >> (count & 31) : value;
}

static inline int32_t sar32(int32_t value, int count)
{
	return value >> (count & 31);
}

/* ---- the helpers ---- */

enum { KONAMI_LSRDI, KONAMI_RORDI, KONAMI_ASRDI, KONAMI_ASLDI, KONAMI_ROLDI };
enum { KONAMI_RESULT, KONAMI_N, KONAMI_Z, KONAMI_V, KONAMI_C };

/* LSRDI, RORDI, ASRDI, ASLDI and ROLDI: the count's low 4 bits steps; 'part' of what they leave (the value or a
   flag), the flags as they were for no step */
uint32_t konami_shift(int op, int part, uint32_t value, uint32_t count, uint32_t n, uint32_t z, uint32_t v,
	uint32_t c);
/* DAA: A adjusted, and the carry (only ever set) */
uint32_t konami_daa(uint32_t a, uint32_t h, uint32_t c);
uint32_t konami_daa_carry(uint32_t a, uint32_t h, uint32_t c);
/* DIV X,B: the quotient and the remainder, 0 and 0 when B is 0 */
uint32_t konami_divx(uint32_t x, uint32_t b);
uint32_t konami_divx_remainder(uint32_t x, uint32_t b);

/* ---- the effects ---- */

void konami_set_lines(uint32_t value);
void konami_rti(void);
void konami_bmove(void);
void konami_bset(void);
void konami_bsetw(void);
void konami_illegal(uint32_t opcode);

/* ---- calls, jumps, returns ---- */

/* A call waits for its return address (a CPU address) */
void konami_calls_push(uint32_t address);
/* The call made from 'from' (a place) returned: true when to 'expected', where its caller goes on */
bool konami_returned_to(uint32_t expected, uint32_t from);
/* The code at CPU address 'address', in the bank the CPU has: a call, a jump (a return to a waiting call, or a
   tail call) */
void konami_call(uint32_t address, uint32_t from);
void konami_jump(uint32_t address, uint32_t from);

/* ---- interrupts and frames ---- */

/* The interrupts the board's lines hold, as the CC lets them through, taken before the code at 'resume' */
void konami_take_interrupts(uint32_t resume);
/* The instruction at 'pc' waits for the next frame: the board moves on to it when the program finds nothing to do */
void konami_frame_wait(uint32_t pc);
/* The IRQ handler's FIRQ point: the sprite DMA's FIRQ held for it comes now */
void konami_firq_point(void);

#ifdef __cplusplus
}
#endif

#endif
