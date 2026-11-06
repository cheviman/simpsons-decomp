/**
 *    Name:        konami_ops.c
 *    Description: the helpers of the translated Konami CPU program's IR: the shifts by a count, DAA, DIV X,B
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    06-11-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    Behavior follows MAME's Konami CPU core (konami.lst: LSRDI, RORDI, ASRDI, ASLDI, ROLDI; konami.cpp: divx;
 *    m6809inl.h: daa; Nathan Woods), as tools/core/konami_cpu/interpreter.py does it
 *    (tools/core/konami/reference/compare_konami_ops.py checks the two on all their inputs).
 */
#include "konami/ops.h"

uint32_t konami_shift(int op, int part, uint32_t value, uint32_t count, uint32_t n, uint32_t z, uint32_t v,
	uint32_t c)
{
	for (uint32_t step = count & 0x0Fu; step; step--)
	{
		uint32_t carry;

		switch (op)
		{
		case KONAMI_LSRDI:
		case KONAMI_ASRDI:
			c = value & 1u;
			value = value >> 1 | (op == KONAMI_ASRDI ? value & 0x8000u : 0u);
			n = value >> 15 & 1u;
			z = value == 0;
			break;
		case KONAMI_RORDI:
			carry = value & 1u;
			value = value >> 1 | c << 15;
			c = carry;
			n = value >> 15 & 1u;
			z = value == 0;
			break;
		case KONAMI_ASLDI:
		{
			const uint32_t r = value << 1;

			n = r >> 15 & 1u;
			z = (r & 0xFFFFu) == 0;
			v = ((r ^ r >> 1) >> 15) & 1u;
			c = r >> 16 & 1u;
			value = r & 0xFFFFu;
			break;
		}
		default:    /* ROLDI */
			carry = value >> 15 & 1u;
			value = (value << 1 | c) & 0xFFFFu;
			c = carry;
			n = value >> 15 & 1u;
			z = value == 0;
			v = 0;
			break;
		}
	}
	switch (part)
	{
	case KONAMI_N: return n;
	case KONAMI_Z: return z;
	case KONAMI_V: return v;
	case KONAMI_C: return c;
	default: return value;
	}
}

static uint32_t daa_total(uint32_t a, uint32_t h, uint32_t c)
{
	const uint32_t msn = a & 0xF0u, lsn = a & 0x0Fu;
	uint32_t cf = 0;

	if (lsn > 0x09u || h)
		cf |= 0x06u;
	if (msn > 0x80u && lsn > 0x09u)
		cf |= 0x60u;
	if (msn > 0x90u || c)
		cf |= 0x60u;
	return a + cf;
}

uint32_t konami_daa(uint32_t a, uint32_t h, uint32_t c)
{
	return daa_total(a, h, c) & 0xFFu;
}

uint32_t konami_daa_carry(uint32_t a, uint32_t h, uint32_t c)
{
	return c | (daa_total(a, h, c) >> 8 & 1u);
}

uint32_t konami_divx(uint32_t x, uint32_t b)
{
	return b ? (x / b) & 0xFFFFu : 0u;
}

uint32_t konami_divx_remainder(uint32_t x, uint32_t b)
{
	return b ? (x % b) & 0xFFu : 0u;
}
