/**
 *    Name:        unsorted/fixed_3F.c
 *    Description: the fixed program's code, 07E000-07FFFF
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    06-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

void sub_07E010(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x19u);
	mem_write16(x + 0x19u, t1 - 0x20u);
	carry = sub_078662(x);
	if (carry == 0u)
		return;
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	sub_07DE7C(x);
}

void sub_07E028(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;

	u = loaded_table_07F26E_ADDRESS;
	*p_left_caller = 0u;
	switch ((int8_t)(uint8_t)((uint32_t)d << 1))
	{
	case 0:
		sub_07E031(x);
		break;
	case -4:
	case 2:
		sub_07DFE7(x);
		break;
	case -2:
	case 4:
		sub_07E010(x);
		break;
	case 6:
		sub_07E064(x);
		break;
	case 8:
	case 14:
		sub_07E0AC(x);
		break;
	case 10:
	case 16:
		sub_07E0EC(x, &u, p_left_caller);
		break;
	case 12:
		sub_07E135(x);
		break;
	case 18:
		sub_07E149(x);
		break;
	case 20:
		sub_07E155(x, &u, p_left_caller);
		break;
	case -38:
		sub_07DDC9(x);
		break;
	case -36:
	case -32:
	case -28:
	case -14:
		y = sub_07DDDE(x, y);
		break;
	case -34:
		sub_07DDF9(x);
		break;
	case -30:
		sub_07DE14(x);
		break;
	case -26:
		sub_07DE32(x);
		break;
	case -24:
		sub_07DE68(x);
		break;
	case -22:
		sub_07DEBA(x);
		break;
	case -20:
		sub_07DEF0(x);
		break;
	case -18:
		sub_07DF3B(x);
		break;
	case -16:
		sub_07DF52(x);
		break;
	case -12:
		sub_07DF66(x);
		break;
	case -10:
		sub_07DF83(x, &u, p_left_caller);
		break;
	case -8:
		sub_07DFA1(x);
		break;
	case -6:
		sub_07DFBA(x);
		break;
	}
	if (*p_left_caller == 0u)
		sub_0785BA(x);
	*p_y = y;
	*p_u = u;
}

void sub_07E031(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t4 = 0;
	uint16_t t2 = 0, t3 = 0;

	mem_write8(x + 0x3Bu, 0x20u);
	d = 0x6300u;
	carry = sub_078680(d);
	mem_write8(x + 5u, 0x97u);
	mem_write16(x + 0xFu, 0xFE00u);
	mem_write16(x + 0x14u, 0u);
	t1 = mem_read8(x + 9u);
	if ((t1 & 0x40u) != 0u)
	{
		t2 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t2);
	}
	t3 = mem_read16(x + 0xFu);
	mem_write16(x + 0x3Eu, t3);
	t4 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t4 + 1u);
}

void sub_07E05E(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint32_t left_caller = 0;

	u = loaded_table_07F274_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)d << 1))
	{
	case 0:
		left_caller = 0u;
		sub_07E064(x);
		break;
	case 2:
	case 8:
		left_caller = 0u;
		sub_07E0AC(x);
		break;
	case 4:
	case 10:
		sub_07E0EC(x, &u, &left_caller);
		break;
	case 6:
		left_caller = 0u;
		sub_07E135(x);
		break;
	case 12:
		left_caller = 0u;
		sub_07E149(x);
		break;
	case 14:
		sub_07E155(x, &u, &left_caller);
		break;
	case -44:
		left_caller = 0u;
		sub_07DDC9(x);
		break;
	case -42:
	case -38:
	case -34:
	case -20:
		left_caller = 0u;
		y = sub_07DDDE(x, y);
		break;
	case -40:
		left_caller = 0u;
		sub_07DDF9(x);
		break;
	case -36:
		left_caller = 0u;
		sub_07DE14(x);
		break;
	case -32:
		left_caller = 0u;
		sub_07DE32(x);
		break;
	case -30:
		left_caller = 0u;
		sub_07DE68(x);
		break;
	case -28:
		left_caller = 0u;
		sub_07DEBA(x);
		break;
	case -26:
		left_caller = 0u;
		sub_07DEF0(x);
		break;
	case -24:
		left_caller = 0u;
		sub_07DF3B(x);
		break;
	case -22:
		left_caller = 0u;
		sub_07DF52(x);
		break;
	case -18:
		left_caller = 0u;
		sub_07DF66(x);
		break;
	case -16:
		sub_07DF83(x, &u, &left_caller);
		break;
	case -14:
		left_caller = 0u;
		sub_07DFA1(x);
		break;
	case -12:
		left_caller = 0u;
		sub_07DFBA(x);
		break;
	case -10:
	case -4:
		left_caller = 0u;
		sub_07DFE7(x);
		break;
	case -8:
	case -2:
		left_caller = 0u;
		sub_07E010(x);
		break;
	case -6:
		left_caller = 0u;
		sub_07E031(x);
		break;
	}
	*p_y = y;
	*p_u = u;
	*p_left_caller = left_caller;
}

void sub_07E064(uint16_t x)
{
	mem_write8(x + 5u, 0x8Eu);
	mem_write16(x + 0xFu, 0x80u);
	sub_07E06F(x);
}

void sub_07E06F(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t4 = 0, t6 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t5 = 0;

	mem_write8(x, 0x88u);
	d = 0x6300u;
	carry = sub_078680(d);
	mem_write16(x + 0x19u, 0x200u);
	mem_write16(x + 0x14u, 0x100u);
	mem_write8(x + 0x3Bu, 0x68u);
	t1 = mem_read16(x + 0x11u);
	t2 = t1 - unk_48B2;
	if (t2 < VIDEO_00A0)
	{
		mem_write8(x + 0x3Bu, 0x48u);
		t3 = mem_read16(x + 0x14u);
		mem_write16(x + 0x14u, 0u - t3);
	}
	t4 = mem_read8(x + 9u);
	if ((t4 & 0x40u) != 0u)
	{
		t5 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t5);
	}
	t6 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t6 + 1u);
}

void sub_07E0AC(uint16_t x)
{
	uint32_t negative = 0, carry = 0;
	uint8_t a = 0;
	uint16_t d = 0;
	uint8_t t3 = 0, t4 = 0, t5 = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = mem_read16(x + 0x19u);
	t2 = t1 - 0x20u;
	mem_write16(x + 0x19u, t2);
	carry = sub_078662(x);
	if (carry)
	{
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
		mem_write16(x + 0x28u, 0x500u);
		return;
	}
	d = 0u;
	sub_078638(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	if ((int8_t)a >= 0)
		return;
	t3 = mem_read8(x + 0x14u);
	if ((int8_t)t3 >= 0)
	{
		t4 = mem_read8(x + 9u);
		mem_write8(x + 9u, (t4 & 0xCFu) | 0x20u);
	}
	mem_write8(x, 0x80u);
	mem_write16(x + 0xAu, 0x4040u);
	t5 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t5 + 1u);
}

void sub_07E0EC(uint16_t x, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t d = 0;
	uint32_t left_caller = 0;
	uint8_t t3 = 0, t4 = 0, t6 = 0;
	uint16_t t1 = 0, t2 = 0, t5 = 0;

	t1 = mem_read16(x + 0x19u);
	t2 = t1 - 0x20u;
	d = t2;
	if ((int16_t)t2 >= 0 || d >= 0xFC00u)
		mem_write16(x + 0x19u, d);
	t3 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t3 - 1u);
	if (t3 != 1u)
	{
		t4 = mem_read8(x + 0x3Bu);
		if ((uint16_t)((uint32_t)t4 << 8) >> 8 < 0x18u)
		{
			mem_write16(x + 0x14u, 0u);
			mem_write8(x, 0x90u);
			t5 = mem_read16(x + 0xAu);
			mem_write16(x + 0xAu, t5 + 0x101u);
		}
		t6 = mem_read8(x + 0x3Bu);
		if ((uint16_t)((uint32_t)t6 << 8) >> 8 != 0x40u)
			left_caller = 0u;
		else
		{
			d = 0x301u;
			left_caller = 0u;
			carry = sub_078680(d);
		}
	}
	else
	{
		mem_write8(x, 0u);
		u = sub_078599(x, u);
		left_caller = 1u;
	}
	*p_u = u;
	*p_left_caller = left_caller;
}

void sub_07E12F(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint32_t left_caller = 0;

	u = loaded_table_07F27A_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)d << 1))
	{
	case 0:
		left_caller = 0u;
		sub_07E135(x);
		break;
	case -4:
	case 2:
		left_caller = 0u;
		sub_07E0AC(x);
		break;
	case -2:
	case 4:
		sub_07E0EC(x, &u, &left_caller);
		break;
	case 6:
		left_caller = 0u;
		sub_07E149(x);
		break;
	case 8:
		sub_07E155(x, &u, &left_caller);
		break;
	case -50:
		left_caller = 0u;
		sub_07DDC9(x);
		break;
	case -48:
	case -44:
	case -40:
	case -26:
		left_caller = 0u;
		y = sub_07DDDE(x, y);
		break;
	case -46:
		left_caller = 0u;
		sub_07DDF9(x);
		break;
	case -42:
		left_caller = 0u;
		sub_07DE14(x);
		break;
	case -38:
		left_caller = 0u;
		sub_07DE32(x);
		break;
	case -36:
		left_caller = 0u;
		sub_07DE68(x);
		break;
	case -34:
		left_caller = 0u;
		sub_07DEBA(x);
		break;
	case -32:
		left_caller = 0u;
		sub_07DEF0(x);
		break;
	case -30:
		left_caller = 0u;
		sub_07DF3B(x);
		break;
	case -28:
		left_caller = 0u;
		sub_07DF52(x);
		break;
	case -24:
		left_caller = 0u;
		sub_07DF66(x);
		break;
	case -22:
		sub_07DF83(x, &u, &left_caller);
		break;
	case -20:
		left_caller = 0u;
		sub_07DFA1(x);
		break;
	case -18:
		left_caller = 0u;
		sub_07DFBA(x);
		break;
	case -16:
	case -10:
		left_caller = 0u;
		sub_07DFE7(x);
		break;
	case -14:
	case -8:
		left_caller = 0u;
		sub_07E010(x);
		break;
	case -12:
		left_caller = 0u;
		sub_07E031(x);
		break;
	case -6:
		left_caller = 0u;
		sub_07E064(x);
		break;
	}
	*p_y = y;
	*p_u = u;
	*p_left_caller = left_caller;
}

void sub_07E135(uint16_t x)
{
	mem_write8(x + 5u, 0x8Cu);
	mem_write16(x + 0xFu, 0xFF80u);
	sub_07E06F(x);
}

void sub_07E143(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint32_t left_caller = 0;

	u = loaded_table_07F280_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)d << 1))
	{
	case 0:
		left_caller = 0u;
		sub_07E149(x);
		break;
	case 2:
		sub_07E155(x, &u, &left_caller);
		break;
	case -56:
		left_caller = 0u;
		sub_07DDC9(x);
		break;
	case -54:
	case -50:
	case -46:
	case -32:
		left_caller = 0u;
		y = sub_07DDDE(x, y);
		break;
	case -52:
		left_caller = 0u;
		sub_07DDF9(x);
		break;
	case -48:
		left_caller = 0u;
		sub_07DE14(x);
		break;
	case -44:
		left_caller = 0u;
		sub_07DE32(x);
		break;
	case -42:
		left_caller = 0u;
		sub_07DE68(x);
		break;
	case -40:
		left_caller = 0u;
		sub_07DEBA(x);
		break;
	case -38:
		left_caller = 0u;
		sub_07DEF0(x);
		break;
	case -36:
		left_caller = 0u;
		sub_07DF3B(x);
		break;
	case -34:
		left_caller = 0u;
		sub_07DF52(x);
		break;
	case -30:
		left_caller = 0u;
		sub_07DF66(x);
		break;
	case -28:
		sub_07DF83(x, &u, &left_caller);
		break;
	case -26:
		left_caller = 0u;
		sub_07DFA1(x);
		break;
	case -24:
		left_caller = 0u;
		sub_07DFBA(x);
		break;
	case -22:
	case -16:
		left_caller = 0u;
		sub_07DFE7(x);
		break;
	case -20:
	case -14:
		left_caller = 0u;
		sub_07E010(x);
		break;
	case -18:
		left_caller = 0u;
		sub_07E031(x);
		break;
	case -12:
		left_caller = 0u;
		sub_07E064(x);
		break;
	case -10:
	case -4:
		left_caller = 0u;
		sub_07E0AC(x);
		break;
	case -8:
	case -2:
		sub_07E0EC(x, &u, &left_caller);
		break;
	case -6:
		left_caller = 0u;
		sub_07E135(x);
		break;
	}
	*p_y = y;
	*p_u = u;
	*p_left_caller = left_caller;
}

void sub_07E149(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 0x3Bu, 0x40u);
	mem_write8(x + 0x1Bu, 0u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

void sub_07E155(uint16_t x, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint8_t a = 0, d_2 = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t6 = 0;
	uint16_t t3 = 0, t4 = 0, t5 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
	{
		t2 = mem_read8(x + 0x3Bu);
		if (t2 == 0x38u)
		{
			d = 0x301u;
			carry = sub_078680(d);
		}
		t3 = mem_read16(x + 0x19u);
		t4 = t3 - 0x40u;
		d_2 = (uint8_t)t4;
		a = (uint8_t)(t4 >> 8);
		if ((int16_t)t4 >= 0 || (uint16_t)(((uint32_t)a << 8) | (d_2 & 0xFFu)) >= 0xFC00u)
			mem_write16(x + 0x19u, ((uint32_t)a << 8) | (d_2 & 0xFFu));
		t5 = mem_read16(x + 0x16u);
		if ((int16_t)t5 < 0)
		{
			t6 = mem_read8(x + 9u);
			mem_write8(x + 9u, (t6 & 0xCFu) | 0x20u);
		}
		*p_left_caller = 0u;
	}
	else
	{
		mem_write8(x, 0u);
		u = sub_078599(x, u);
		*p_left_caller = 1u;
	}
	*p_u = u;
}

void sub_07E18F(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;

	u = loaded_table_07F28C_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)d << 1))
	{
	case 0:
		sub_07E195(x, &y, &u);
		break;
	case 2:
		sub_07E1A4(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_07E195(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0;

	u = object_setup_07F290_ADDRESS;
	y = sub_07D132(x, u);
	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_07E1A4(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
		mem_write8(x, 0u);
}

void sub_07E1AE(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 9u);
	mem_write8(x + 0x47u, t1);
	sub_07D450(x, &y, &u);
	mem_write8(x + 5u, 0x8Du);
	mem_write8(x + 0x3Bu, 0x18u);
	mem_write8(x + 2u, 4u);
	mem_write16(x + 0x28u, 0x400u);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_07E1E8(uint16_t x, uint16_t u)
{
	uint32_t zero = 0, carry = 0;
	uint8_t a = 0;
	uint16_t d = 0, u_2 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;
	uint16_t t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0;

	d = 0x6300u;
	carry = sub_0797D3(d);
	t1 = mem_read8(x + 0x1Bu);
	if (t1 == 0u)
	{
		mem_write8(x + 0x29u, 2u);
		sub_07E25C(x);
		return u;
	}
	u_2 = indexed_table_07F2AC_ADDRESS;
	t2 = mem_read8(x + 0x28u);
	a = t2;
	if (a < 2u)
	{
		t3 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t3 + 1u);
		mem_write8(x + 5u, DATA8(u_2 + (int8_t)a) | 0x80u);
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
		return u_2;
	}
	mem_write8(x + 5u, DATA8(u_2 + (int8_t)a) | 0x80u);
	mem_write16(x + 0x14u, 0u);
	mem_write16(x + 0x19u, 0x400u);
	mem_write16(x + 0xFu, 0xFE00u);
	t4 = mem_read16(x + 0x25u);
	u_2 = t4;
	t5 = mem_read16(u_2 + 0xFu);
	zero = t5 == 0u;
	if ((int16_t)t5 < 0)
	{
		mem_write8(x + 0x29u, 5u);
		return u_2;
	}
	if (zero)
	{
		t6 = mem_read16(u_2 + 0xCu);
		t7 = mem_read16(x + 0xCu);
		if (t6 < t7)
		{
			t8 = mem_read16(x + 0xFu);
			mem_write16(x + 0xFu, 0u - t8);
		}
		mem_write8(x + 0x29u, 5u);
		return u_2;
	}
	t8 = mem_read16(x + 0xFu);
	mem_write16(x + 0xFu, 0u - t8);
	mem_write8(x + 0x29u, 5u);
	return u_2;
}

uint16_t sub_07E247(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t y_2 = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
		return y;
	mem_write8(x, 0xC0u);
	t2 = mem_read16(x + 0x48u);
	y_2 = t2;
	sub_07D1B7(x, y_2);
	mem_write8(x + 2u, 2u);
	mem_write8(x + 0x3Bu, 0u);
	return y_2;
}

void sub_07E25C(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;
	uint8_t t1 = 0;

	sub_07D16E(x, &ignored16, &carry);
	if (carry)
	{
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
		mem_write8(x + 5u, 0x88u);
		t1 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t1 + 1u);
	}
}

void sub_07E270(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint32_t carry = 0;
	uint8_t a = 0, d = 0;
	uint16_t d_2 = 0, u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;
	uint16_t t5 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		t2 = mem_read8(x + 0x43u);
		if (t2 == 0u)
		{
			mem_write16(x + 0xFu, 0u);
			*p_y = y;
			*p_u = u;
			sub_07E1AE(x, p_y, p_u);
			return;
		}
		mem_write8(x + 0x3Bu, 0x10u);
		t3 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t3 + 1u);
	}
	t4 = mem_read8(x + 6u);
	if ((t4 & 2u) == 0u)
		return;
	t5 = mem_read16(x + 0x4Cu);
	d = (uint8_t)t5;
	a = (uint8_t)(t5 >> 8);
	if (t5 == 0u)
		return;
	d_2 = (d & 0xFFu) | ((uint32_t)a << 8);
	carry = sub_0797D3(d_2);
}

uint16_t sub_07E299(uint16_t x, uint16_t u)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
	{
		mem_write8(x, (mem_read8(x) ^ 0x80u) | 4u);
		return u;
	}
	mem_write8(x, 0u);
	return sub_07D0E0(x, u);
}

void sub_07E2AF(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;
	uint8_t t1 = 0;

	sub_07D16E(x, &ignored16, &carry);
	if (carry)
	{
		mem_write16(x + 0xFu, 0u);
		mem_write8(x + 0x3Bu, 0x10u);
		t1 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t1 + 1u);
	}
}

uint16_t sub_07E2C0(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return y;
	t2 = mem_read16(x + 0x48u);
	y = t2;
	sub_07D1B7(x, y);
	mem_write8(x, 0xC0u);
	mem_write8(x + 5u, 0x8Fu);
	mem_write8(x + 0x29u, 1u);
	return y;
}
