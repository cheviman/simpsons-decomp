/**
 *    Name:        cpu.h
 *    Description: the Konami CPU (the 053248) as the translated program sees it: its registers and flags, and the
 *                 board's bus
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    06-11-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    The registers as tools/core/konami_cpu/emit_c.py writes them: A, B (D is A:B), X, Y, U, S, DP and PC, each in a
 *    uint32_t that never holds bits above its width, and the condition code register's flags apart: E F H I N Z V C.
 *    Memory is the board's (simpsons/machine.h), a byte at a time.
 */
#ifndef KONAMI_CPU_H
#define KONAMI_CPU_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct konami_cpu
{
	uint32_t a, b, x, y, u, s, dp, pc;
	uint8_t e, f, h, i, n, z, v, c;
	uint32_t interrupts;           /* the interrupts taken */
} konami_cpu;

extern konami_cpu cpu;

uint32_t mem_read8(uint32_t address);
void mem_write8(uint32_t address, uint8_t data);

#ifdef __cplusplus
}
#endif

#endif
