/**
 *    Name:        unsorted/fixed_3C.c
 *    Description: the fixed program's code, 078000-079FFF
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    07-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

uint16_t sub_078593(uint16_t x, uint16_t u)
{
	uint8_t a = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0, t2 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0;
	uint16_t t3 = 0;

	if ((mem_read8(x) & 0x20u) == 0u)
		return u;
	t1 = mem_read8(x + 0x1Eu);
	if (t1 < 0x11 || t1 > 0x15)
		return u;
	t2 = mem_read8(x + 2u);
	if ((int8_t)t2 < 0)
		return u;
	t3 = mem_read16(x + 0x25u);
	u = t3;
	t4 = mem_read8(x + 4u);
	if ((int8_t)t4 < 0)
	{
		t5 = mem_read8(u + 4u);
		if (t5 <= 3u)
		{
			t6 = mem_read8(u + 0x2Au);
			mem_write8(u + 0x2Au, t6 + 1u);
			mem_write16(u + 0x49u, x);
		}
	}
	t7 = mem_read8(u + 0x5Bu);
	stack = t7 & 0x70u;
	t8 = mem_read8(x + 0x27u);
	mem_write8(x + 0x27u, (t8 & 0x8Fu) | stack);
	mem_write8(x, 0x80u);
	t9 = mem_read8(x + 0x1Bu);
	if (t9 != 0u)
		a = 0xFFu;
	else
		a = 0xFEu;
	mem_write8(x + 2u, a);
	mem_write16(x + 0x28u, 0u);
	return u;
}

void sub_078596(uint16_t x, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t u = (uint16_t)*p_u;

	*p_u = u;
	sub_07D056(x, p_u, p_left_caller);
}

uint16_t sub_078599(uint16_t x, uint16_t u)
{
	return sub_07D0E0(x, u);
}

void sub_07859C(uint16_t x)
{
	uint8_t b = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 9u);
	b = t1 & 0xBFu;
	t2 = mem_read8(x + 0x36u);
	if ((int8_t)(t2 - 0x40u) >= 0)
		b |= 0x40u;
	mem_write8(x + 9u, b);
}

void sub_07859F(uint16_t x, uint16_t u)
{
	sub_07D10E(x, u);
}

void unused_0785A2(uint16_t x, uint16_t u)
{
	sub_07D115(x, u);
}

void sub_0785A5(uint16_t d, uint16_t *p_x, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t x = 0;

	*p_x = x;
	*p_u = u;
	sub_07936D(d, p_x, p_u);
}

void unused_0785A8(uint16_t x, uint16_t d)
{
	sub_07945C(x, d);
}

uint16_t sub_0785AB(uint16_t x, uint16_t u)
{
	return sub_07D132(x, u);
}

void unused_0785AE(void)
{
}

void sub_0785B1(uint16_t x, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d = 0;

	*p_d = d;
	sub_07D16E(x, p_d, &carry);
	*p_carry = carry;
}

void sub_0785B4(uint16_t x, uint16_t y)
{
	sub_07D1B7(x, y);
}

uint16_t sub_0785B7(uint16_t x, uint16_t u)
{
	return sub_07D1F7(x, u);
}

void sub_0785BA(uint16_t x)
{
	sub_07D1CF(x);
}

void unreached_0785BD(void)
{
	uint32_t carry = 0;

	carry = sub_07D216(0u);
}

void sub_0785C0(uint16_t d)
{
	sub_079311(d);
}

void sub_0785C3(void)
{
	sub_0795AF();
}

void sub_0785C6(uint16_t x)
{
	uint8_t a = 0;
	uint8_t t2 = 0, t3 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0xFu);
	if (t1 == 0u)
		return;
	t2 = mem_read8(x + 9u);
	a = t2;
	t3 = mem_read8(x + 0xFu);
	if ((int8_t)t3 >= 0)
		a &= 0xBFu;
	else
		a |= 0x40u;
	mem_write8(x + 9u, a);
}

void sub_0785C9(uint16_t x)
{
	sub_07D249(x);
}

void sub_0785CC(uint16_t x)
{
	sub_07D268(x);
}

void unused_0785D2(uint16_t x)
{
	sub_07D2A2(x);
}

void sub_0785D5(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;

	*p_y = y;
	*p_u = u;
	sub_07D43B(x, p_y, p_u);
}

void sub_0785DB(uint16_t x, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;

	*p_y = y;
	*p_u = u;
	sub_07D49C(x, p_y, p_u, p_left_caller);
}

void sub_0785DE(uint16_t x, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;

	*p_y = y;
	*p_u = u;
	sub_07D63B(x, p_y, p_u, p_left_caller);
}

void sub_0785E1(uint16_t x, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;

	*p_y = y;
	*p_u = u;
	sub_07D667(x, p_y, p_u, p_left_caller);
}

void sub_0785E4(uint16_t x, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;

	*p_y = y;
	*p_u = u;
	sub_07D6B2(x, p_y, p_u, p_left_caller);
}

void unused_0785E7(uint16_t x)
{
	uint16_t ignored16 = 0, ignored16_2 = 0;

	sub_07D450(x, &ignored16, &ignored16_2);
}

void sub_0785EA(uint16_t x, uint16_t d)
{
	uint8_t a = 0;
	uint16_t x_2 = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	a = (uint8_t)(d >> 8);
	stack = a;
	t1 = (((a >> 1) >> 1) >> 1) >> 1;
	a = t1;
	if (t1 == 0u)
		a = 0x10u;
	io_write8(x - 0x2000u, (uint8_t)d);
	t2 = x;
	x_2 = t2 + 1u;
	io_write8(t2, a);
	mem_write8(x_2 - 0x2000u, (uint8_t)d);
	mem_write8(x_2, stack & 0xFu);
}

void unused_0785ED(uint16_t x, uint8_t d)
{
	uint16_t ignored16 = 0, ignored16_2 = 0;

	sub_07E18F(x, d, &ignored16, &ignored16_2);
}

uint16_t sub_0785F0(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, y = 0;

	y = loaded_table_07F296_ADDRESS;
	sub_07CA8A(x, y, &ignored16, &ignored16_2, &carry);
	return y;
}

void sub_0785F3(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;

	*p_y = y;
	*p_u = u;
	sub_07E1AE(x, p_y, p_u);
}

void sub_0785F9(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;

	*p_y = y;
	*p_u = u;
	sub_07D416(x, p_y, p_u);
}

void sub_0785FC(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t negative = 0;
	uint8_t a = 0, d = 0;
	uint16_t d_2 = 0, u = 0;
	uint32_t left_caller = 0;
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = mem_read16(x + 0x28u);
	d = (uint8_t)t1;
	switch ((int8_t)(uint8_t)((uint32_t)(t1 >> 8) << 1))
	{
	case 0:
		sub_07DDC3(x, d, &y, &u, &left_caller);
		break;
	case 2:
		sub_07DDF3(x, d, &y, &u, &left_caller);
		break;
	case 4:
		sub_07DE29(x, d, &y, &u, &left_caller);
		break;
	case 6:
		sub_07DEB1(x, d, &y, &u, &left_caller);
		break;
	case 8:
		sub_07DF4C(x, d, &y, &u, &left_caller);
		break;
	case 10:
		sub_07DF60(x, d, &y, &u, &left_caller);
		break;
	case 12:
		sub_07DF9B(x, d, &y, &u, &left_caller);
		break;
	case 14:
		sub_07DFB1(x, d, &y, &u, &left_caller);
		break;
	case 16:
		sub_07E028(x, d, &y, &u, &left_caller);
		break;
	case 18:
		sub_07DE0E(x, d, &y, &u, &left_caller);
		break;
	case 20:
		sub_07E05E(x, d, &y, &u, &left_caller);
		break;
	case 22:
		sub_07E12F(x, d, &y, &u, &left_caller);
		break;
	case 24:
		sub_07E143(x, d, &y, &u, &left_caller);
		break;
	}
	if (left_caller == 0u)
	{
		t2 = unk_48B8;
		if (t2 >= 0x500u)
			u = sub_07CDE9(x, u);
		else
		{
			t3 = mem_read8(x + 0x28u);
			if (t3 != 0xCu)
			{
				d_2 = 0u;
				sub_079495(x, &d_2, &negative);
				a = (uint8_t)(d_2 >> 8);
				if ((int8_t)a < 0)
					mem_write16(x + 0x28u, VIDEO_0C00);
			}
		}
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_0785FF(void)
{
	uint8_t a = 0, d = 0;
	uint16_t x = 0;
	uint8_t stack = 0, stack_10002 = 0;
	uint8_t t3 = 0, t4 = 0;
	uint16_t t1 = 0, t2 = 0;

	x = unk_4D40_ADDRESS;
	unk_48E8 = 6u;
	do
	{
		if (mem_read8(x) != 1u)
		{
			unk_48E9 = 0x30u;
			t1 = mem_read16(x + 0x59u);
			stack = t1 >> 8;
			stack_10002 = t1;
			d = 0u;
			a = 0u;
			do
			{
				t2 = x;
				x = t2 + 2u;
				mem_write16(t2, (uint32_t)a << 8);
				t3 = unk_48E9;
				unk_48E9 = t3 - 1u;
			} while (t3 != 1u);
			mem_write16(x - 7u, ((uint32_t)stack << 8) | stack_10002);
		}
		else
			x += 0x60u;
		t4 = unk_48E8;
		unk_48E8 = t4 - 1u;
	} while (t4 != 1u);
	return x;
}

void sub_078602(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t d = 0;
	uint16_t u = 0;
	uint32_t left_caller = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x28u);
	d = (uint8_t)t1;
	switch ((int8_t)(uint8_t)((uint32_t)(t1 >> 8) << 1))
	{
	case 0:
		sub_07DDC3(x, d, &y, &u, &left_caller);
		break;
	case 2:
		sub_07DDF3(x, d, &y, &u, &left_caller);
		break;
	case 4:
		sub_07DE29(x, d, &y, &u, &left_caller);
		break;
	case 6:
		sub_07DEB1(x, d, &y, &u, &left_caller);
		break;
	case 8:
		sub_07DF4C(x, d, &y, &u, &left_caller);
		break;
	case 10:
		sub_07DF60(x, d, &y, &u, &left_caller);
		break;
	case 12:
		sub_07DF9B(x, d, &y, &u, &left_caller);
		break;
	case 14:
		sub_07DFB1(x, d, &y, &u, &left_caller);
		break;
	case 16:
		sub_07E028(x, d, &y, &u, &left_caller);
		break;
	case 18:
		sub_07DE0E(x, d, &y, &u, &left_caller);
		break;
	case 20:
		sub_07E05E(x, d, &y, &u, &left_caller);
		break;
	case 22:
		sub_07E12F(x, d, &y, &u, &left_caller);
		break;
	case 24:
		sub_07E143(x, d, &y, &u, &left_caller);
		break;
	}
	if (left_caller == 0u)
	{
		t2 = mem_read8(x + 0x28u);
		if (t2 < 0xAu)
			u = sub_07CDE9(x, u);
	}
	*p_y = y;
	*p_u = u;
}

void sub_078605(uint16_t *p_x, uint16_t *p_d)
{
	uint16_t d = 0, x = 0;

	*p_x = x;
	*p_d = d;
	sub_078EB0(p_x, p_d);
}

uint16_t sub_078608(void)
{
	uint16_t d = 0;
	uint8_t t1 = 0;

	d = 0xFE88u;
	io_write16(IO_1FC6, 0xFE88u);
	t1 = io_read8(IO_1FC4);
	return d;
}

void sub_07860B(void)
{
	uint16_t d = 0;

	d = 0xF585u;
	sub_078F30(d);
	d = 0xF484u;
	sub_078F30(d);
}

void sub_07860E(void)
{
	uint16_t d = 0;

	d = 0xF787u;
	sub_078F30(d);
	d = 0xF686u;
	sub_078F30(d);
}

void sub_078611(uint16_t *p_d, uint32_t *p_zero)
{
	uint32_t zero = *p_zero;
	uint16_t d = 0;
	uint8_t t1 = 0;

	t1 = io_read8(0x1FC7u);
	zero = (uint8_t)(0x88u - t1) == 0u;
	d = 0x88u;
	*p_d = (*p_d & 0xFF00u) | d;
	*p_zero = zero;
}

void unused_078614(void)
{
}

void sub_078617(uint16_t x, uint16_t d)
{
	sub_07CC8E(x, d);
}

void unused_07861A(uint16_t d)
{
	uint16_t ignored16 = 0;

	sub_07CCA0(&ignored16, &d);
}

uint16_t sub_07861D(uint16_t x, uint16_t u)
{
	return sub_07CCFB(x, u);
}

uint16_t sub_078620(uint16_t x)
{
	return sub_07D301(x);
}

uint16_t sub_078623(uint16_t d)
{
	return sub_07D34F((uint8_t)d);
}

void sub_078626(uint16_t x, uint16_t u)
{
	sub_07D35B(x, u);
}

void unused_078629(uint16_t x, uint16_t u)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;

	sub_07D3D7(x, &u, &ignored16, &carry);
}

void sub_07862C(uint16_t x, uint16_t y, uint16_t *p_u, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d = 0, u = 0;

	*p_u = u;
	*p_d = d;
	sub_07CA8A(x, y, p_u, p_d, &carry);
	*p_carry = carry;
}

void sub_07862F(uint16_t x, uint16_t y, uint16_t *p_u, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d = 0, ignored16 = 0, u = 0;
	uint8_t t1 = 0;

	d = 2u;
	sub_07CA54(&u, &d, &carry);
	if (carry)
	{
		t1 = mem_read8(y + 5u);
		mem_write8(u + 1u, t1);
		sub_07CAAB(x, y, u, &ignored16, &carry);
	}
	*p_u = u;
	*p_carry = carry;
}

uint16_t sub_078632(uint16_t x)
{
	uint32_t negative = 0;
	uint16_t d = 0, ignored16 = 0;

	unk_48E9 = (uint8_t)(unk_48F8 >> 8u);
	unk_48EA = (uint8_t)unk_48F8;
	unk_48ED = (uint8_t)(unk_48FA >> 8u);
	unk_48EE = (uint8_t)unk_48FA;
	sub_0794EB(x, &ignored16, &d, &negative);
	return d;
}

void sub_078638(uint16_t x, uint16_t *p_d, uint32_t *p_negative)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t negative = *p_negative;

	*p_d = d;
	sub_079495(x, p_d, &negative);
	*p_negative = negative;
}

void sub_07863B(uint16_t x, uint16_t *p_d, uint32_t *p_negative)
{
	uint32_t negative = *p_negative;
	uint16_t d = 0;

	*p_d = d;
	sub_0794D9(x, p_d, &negative);
	*p_negative = negative;
}

void unused_078641(uint16_t x)
{
	sub_07CF5F(x);
}

void sub_078644(uint16_t x, uint16_t *p_d, uint32_t *p_negative)
{
	uint32_t negative = *p_negative;
	uint16_t d = 0;

	*p_d = d;
	sub_0794B9(x, p_d, &negative);
	*p_negative = negative;
}

void sub_078647(uint16_t x, uint16_t *p_d, uint32_t *p_negative)
{
	uint32_t negative = *p_negative;
	uint16_t d = 0;

	*p_d = d;
	sub_0794C9(x, p_d, &negative);
	*p_negative = negative;
}

void sub_07864A(uint16_t x)
{
	mem_write8(x, mem_read8(x) ^ 0x84u);
}

void unused_07864D(uint16_t x)
{
	uint32_t negative = 0;
	uint8_t a = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	d = 0u;
	sub_079495(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	if ((int8_t)a >= 0)
	{
		unk_48E8 = a;
		mem_write8(x + 0x5Du, (((a & 0xFu) << 1) << 1) << 1);
		unk_48E8 &= 0x30u;
		t1 = mem_read8(x + 9u);
		mem_write8(x + 9u, (t1 & 0xCFu) | unk_48E8);
	}
}

void sub_078650(uint16_t x, uint16_t *p_u, uint16_t *p_d)
{
	uint32_t negative = 0;
	uint16_t d = 0, u = 0;

	unk_48E9 = 0u;
	unk_48EA = 0u;
	unk_48ED = 0u;
	unk_48EE = 0u;
	*p_u = u;
	*p_d = d;
	sub_0794EB(x, p_u, p_d, &negative);
}

void sub_078653(uint16_t d, uint16_t *p_x, uint32_t *p_carry)
{
	uint16_t x = (uint16_t)*p_x;
	uint32_t carry = *p_carry;

	*p_x = x;
	sub_079784(d, p_x, &carry);
	*p_carry = carry;
}

void sub_078656(uint16_t d)
{
	sub_0797B7(d);
}

void sub_078659(void)
{
	sub_078F24();
}

void sub_07865C(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t t1 = 0;

	u = loaded_table_07F29E_ADDRESS;
	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		u = sub_07E1E8(x, u);
		break;
	case 2:
		y = sub_07E247(x, y);
		break;
	case 4:
		sub_07E25C(x);
		break;
	case 6:
		sub_07E270(x, &y, &u);
		break;
	case 8:
		u = sub_07E299(x, u);
		break;
	case 10:
		sub_07E2AF(x);
		break;
	case 12:
		y = sub_07E2C0(x, y);
		break;
	}
	if (mem_read8(x) != 0u)
	{
		sub_07D1CF(x);
		u = sub_07CDE9(x, u);
	}
	*p_y = y;
	*p_u = u;
}

uint32_t sub_078662(uint16_t x)
{
	return sub_07D1B0(x);
}

void unused_078668(uint16_t x)
{
	unused_07CD90(x);
}

uint16_t sub_07866B(uint16_t x, uint16_t u, uint16_t d)
{
	return sub_07CCDD(x, u, d);
}

void unused_07866E(void)
{
}

uint16_t sub_078671(uint16_t x, uint16_t u, uint16_t d)
{
	return sub_07CCF0(x, u, (uint8_t)d);
}

void sub_078674(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, u = 0;
	uint8_t t1 = 0;

	mem_write8(x, mem_read8(x) & 0xDFu);
	mem_write8(x + 0x1Eu, 0u);
	u = unk_4F80_ADDRESS;
	unk_48F1 = 8u;
	do
	{
		if ((mem_read8(u) & 0x40u) != 0u)
		{
			sub_07C13A(x, u, &ignored16, &carry);
			if (carry)
				sub_07C2D9(x, u);
		}
		u += 0x60u;
		t1 = unk_48F1;
		unk_48F1 = t1 - 1u;
	} while (t1 != 1u);
}

void sub_078677(uint16_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;

	*p_y = y;
	*p_u = u;
	sub_07BAC7(d, p_y, p_u);
}

void unused_07867A(uint16_t x)
{
	unused_07C10D(x);
}

void sub_07867D(uint16_t d, uint16_t *p_u, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t u = 0;

	*p_u = u;
	sub_07CA54(p_u, &d, &carry);
	*p_carry = carry;
}

uint32_t sub_078680(uint16_t d)
{
	return sub_0797D3(d);
}

uint32_t sub_078683(uint16_t x, uint32_t carry)
{
	uint16_t d = 0;
	uint16_t t1 = 0;

	if (mem_read8(x) != 0u)
	{
		t1 = mem_read16(x + 0xCu);
		d = t1 - 0x40u;
		carry = d < 0x180u;
		if (d >= 0x180u)
		{
			carry = 0u;
			mem_write8(x, 0u);
		}
	}
	return carry;
}

void sub_078686(uint16_t x, uint16_t *p_u, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint16_t d_2 = 0, u_2 = 0;
	uint8_t stack = 0;
	uint16_t stack_3 = 0;
	uint8_t t1 = 0, t2 = 0, t9 = 0;
	uint16_t t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t10 = 0;

	t1 = io_read8(VIDEO_1874);
	if (t1 != 0u)
	{
		stack = 4u;
		u_2 = unk_4A40_ADDRESS;
		d_2 = 0x7FFFu;
		unk_48EC = 0x7Fu;
		unk_48ED = 0xFFu;
		do
		{
			if (mem_read8(u_2) != 0u)
			{
				t2 = mem_read8(u_2 + 2u);
				if ((int8_t)t2 >= 0)
				{
					t3 = mem_read16(x + 0xCu);
					t4 = mem_read16(u_2 + 0xCu);
					t5 = t3 - t4;
					d_2 = t5;
					if ((int16_t)t5 < 0)
						d_2 = 0u - d_2;
					stack_3 = d_2;
					t6 = mem_read16(x + 0x11u);
					t7 = mem_read16(u_2 + 0x11u);
					t8 = t6 - t7;
					d_2 = t8;
					if ((int16_t)t8 < 0)
						d_2 = 0u - d_2;
					d_2 += stack_3;
					if (d_2 < (((uint32_t)unk_48EC << 8u) | unk_48ED))
					{
						unk_48EC = (uint8_t)(d_2 >> 8u);
						unk_48ED = (uint8_t)d_2;
						io_write16(VIDEO_1872, u_2);
					}
				}
			}
			u_2 += 0xC0u;
			t9 = stack;
			stack = t9 - 1u;
		} while (t9 != 1u);
		t10 = io_read16(VIDEO_1872);
		u = t10;
		d = (d_2 & 0xFFu) | ((uint32_t)unk_48EC << 8);
		carry = d >> 8 < 0x7Fu;
	}
	else
	{
		carry = 0u;
		d &= 0xFFu;
	}
	*p_u = u;
	*p_d = d;
	*p_carry = carry;
}

uint32_t sub_078689(uint16_t d)
{
	return sub_0797E3(d);
}

void sub_07868C(uint16_t *p_x, uint16_t *p_u)
{
	uint16_t u = 0, x = 0;

	*p_x = x;
	*p_u = u;
	sub_07955F(p_x, p_u);
}

void sub_07868F(uint16_t *p_x, uint16_t *p_y)
{
	uint16_t x = 0, y = 0;

	*p_x = x;
	*p_y = y;
	sub_0792DD(p_x, p_y);
}

uint16_t sub_078692(uint16_t x, uint16_t d)
{
	return sub_07947D(x, d);
}

uint16_t sub_078695(void)
{
	return sub_079270();
}

uint16_t sub_078698(void)
{
	return sub_079275();
}

void sub_07869B(uint16_t *p_x, uint16_t *p_d)
{
	uint16_t d = 0, x = 0;

	*p_x = x;
	*p_d = d;
	sub_07927A(p_x, p_d);
}

void sub_07869E(uint16_t d)
{
	uint32_t carry = 0;

	carry = sub_0797ED(d);
}

void sub_0786A1(uint16_t d)
{
	sub_079743(d);
}

uint16_t sub_0786A4(uint16_t d)
{
	uint32_t carry = 0;

	sub_079718(&d, &carry);
	return d;
}

void sub_0786A7(uint16_t x, uint16_t d)
{
	uint8_t a = 0;
	uint16_t x_2 = 0;
	uint8_t stack = 0, stack_2 = 0;
	uint8_t t1 = 0, t3 = 0, t5 = 0;
	uint16_t t2 = 0, t4 = 0, t6 = 0;

	a = (uint8_t)(d >> 8);
	stack = a;
	t1 = (((a >> 1) >> 1) >> 1) >> 1;
	a = t1;
	if (t1 == 0u)
		a = 0x10u;
	mem_write8(x - 0x2000u, 0u);
	t2 = x;
	x_2 = t2 + 1u;
	mem_write8(t2, a);
	t3 = stack & 0xFu;
	a = t3;
	if (t3 == 0u)
		a = 0x10u;
	mem_write8(x_2 - 0x2000u, 0u);
	t4 = x_2;
	x_2 = t4 + 1u;
	mem_write8(t4, a);
	a = (uint8_t)d;
	stack_2 = a;
	t5 = (((a >> 1) >> 1) >> 1) >> 1;
	a = t5;
	if (t5 == 0u && stack == 0u)
		a = 0x10u;
	mem_write8(x_2 - 0x2000u, 0u);
	t6 = x_2;
	x_2 = t6 + 1u;
	mem_write8(t6, a);
	mem_write8(x_2 - 0x2000u, 0u);
	mem_write8(x_2, stack_2 & 0xFu);
}

void sub_0786AA(uint8_t d, uint16_t *p_u, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t u = 0;

	*p_u = u;
	sub_07CA50(d, p_u, &carry);
	*p_carry = carry;
}

void sub_0786AD(uint16_t d, uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, x = 0, y = 0;

	*p_x = x;
	*p_y = y;
	*p_u = u;
	sub_07C4A3(d, p_x, p_y, p_u);
}

void sub_0786B0(void)
{
	sub_07C931();
}

void sub_0786B3(uint16_t x, uint16_t d)
{
	uint8_t a = 0;
	uint16_t u = 0;
	uint8_t stack = 0, stack_2 = 0;
	uint8_t t2 = 0, t3 = 0;
	uint16_t t1 = 0;

	a = (uint8_t)(d >> 8);
	stack = a;
	a = unk_480F | 2u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
	a = 0xFFu;
	do
	{
		t1 = mem_read16(x + 0x59u);
		u = t1;
		stack_2 = 8u;
		do
		{
			mem_write8(x, 1u);
			mem_write8(u + 1u, a);
			u += 0x10u;
			a--;
			t2 = stack_2;
			stack_2 = t2 - 1u;
		} while (t2 != 1u);
		x += 0x60u;
		t3 = stack;
		stack = t3 - 1u;
	} while (t3 != 1u);
	a = unk_480F & ~3u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
}

void sub_0786B6(uint16_t u)
{
	sub_079384(u);
}

uint32_t sub_0786B9(uint16_t x)
{
	uint8_t a = 0;
	uint16_t ignored16 = 0;
	uint32_t left_caller = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	sub_07CFEC(x, &ignored16, &left_caller);
	if (left_caller != 0u)
	{
		left_caller = 0u;
		return left_caller;
	}
	t1 = mem_read8(x + 0x1Bu);
	if (t1 == 0u)
	{
		t2 = mem_read8(x + 0x33u);
		if (t2 == 0u)
			a = 0xBu;
		else
			a = 0xAu;
		mem_write8(x + 0x28u, a);
		mem_write8(x + 0x29u, 0u);
		return left_caller;
	}
	t3 = mem_read8(x + 0x1Eu);
	switch ((int8_t)(uint8_t)((t3 - 0x11u) << 1))
	{
	case 0:
	case 2:
		sub_07D071(x);
		return left_caller;
	case 4:
		sub_07D097(x);
		return left_caller;
	case 6:
		sub_07D0A9(x);
		return left_caller;
	}
	unreachable();
}

void sub_0786BC(void)
{
	sub_07BA93();
}

uint16_t sub_0786BF(uint16_t x, uint16_t y, uint16_t d)
{
	uint8_t a = 0, b = 0;
	uint16_t d_2 = 0, u = 0;
	uint8_t t1 = 0, t3 = 0, t5 = 0, t6 = 0, t7 = 0;
	uint16_t t2 = 0, normal = 0, t4 = 0, normal_2 = 0;
	uint32_t unk_48E8_halfword = 0;

	a = (uint8_t)(d >> 8);
	b = (uint8_t)d;
	unk_48E8_halfword = ((uint32_t)a << 8) | b;
	unk_48E8 = (uint8_t)(unk_48E8_halfword >> 8u);
	unk_48E9 = (uint8_t)unk_48E8_halfword;
	unk_48EA = 0u;
	t1 = mem_read8(x + 0x1Bu);
	if (t1 == 0u)
	{
		t2 = mem_read16(x + 0x54u);
		u = t2;
		if (t2 != 0u)
		{
			a = unk_48EA;
			t3 = mem_read8(x + 0x53u);
			if (a < t3)
			{
				mem_write8(x + 0x53u, a);
				unk_487E = 8u;
				y = hurt_effect_rows[(int8_t)((uint8_t)((uint32_t)unk_48E9 << 1)) / 2];
				normal = HURT_EFFECT_ROW(y + (int8_t)((uint32_t)unk_48EA << 1))->normal;
				d_2 = normal;
				sub_07BAC7(d_2, &y, &u);
			}
		}
		return y;
	}
	t4 = mem_read16(x + 0x54u);
	u = t4;
	if (t4 == 0u)
	{
		mem_write8(x + 0x53u, 5u);
		t5 = mem_read8(x + 0x1Bu);
		mem_write8(x + 0x56u, t5);
		unk_487E = 2u;
		u = hurt_effect_rows_ADDRESS;
		normal_2 = HURT_EFFECT_ROW(hurt_effect_rows[(int8_t)((uint8_t)((uint32_t)unk_48E9 << 1)) / 2])->normal;
		d_2 = normal_2;
		sub_07BAC7(d_2, &y, &u);
		mem_write16(x + 0x54u, u);
		return y;
	}
	unk_48EE = a * 5u;
	t6 = mem_read8(x + 0x56u);
	unk_48EE = t6 - unk_48EE;
	t7 = mem_read8(x + 0x1Bu);
	unk_48EE = t7 - unk_48EE;
	a = unk_48E8;
	unk_48EA++;
	while (a < unk_48EE)
	{
		a += unk_48E8;
		unk_48EA++;
		if (unk_48EA == 5u)
			return y;
	}
	a = unk_48EA;
	t3 = mem_read8(x + 0x53u);
	if (a < t3)
	{
		mem_write8(x + 0x53u, a);
		unk_487E = 8u;
		y = hurt_effect_rows[(int8_t)((uint8_t)((uint32_t)unk_48E9 << 1)) / 2];
		normal = HURT_EFFECT_ROW(y + (int8_t)((uint32_t)unk_48EA << 1))->normal;
		d_2 = normal;
		sub_07BAC7(d_2, &y, &u);
	}
	return y;
}

void sub_0786C2(uint16_t d)
{
	sub_07B632(d);
}

void sub_0786C5(uint16_t d)
{
	sub_07B64C(d);
}

void sub_0786C8(uint16_t u, uint16_t d)
{
	uint8_t a = 0, b = 0;
	uint16_t x = 0;
	uint16_t t1 = 0, t2 = 0;

	a = (uint8_t)(d >> 8);
	a += 2u;
	for (;;)
	{
		t1 = u;
		u = t1 + 2u;
		x = mem_read16(t1);
		for (;;)
		{
			t2 = u;
			u = t2 + 1u;
			b = mem_read8(t2);
			if (b == 0x23u)
				return;
			if (b == 0x2Fu)
				break;
			b = ((b - 0x30u) << 1) << 1;
			mem_write8(x - 0x2000u, a);
			mem_write8(x, b);
			b++;
			mem_write8(x - 0x1FFFu, a);
			mem_write8(x + 1u, b);
			b++;
			mem_write8(x - 0x1FC0u, a);
			mem_write8(x + 0x40u, b);
			mem_write8(x - 0x1FBFu, a);
			mem_write8(x + 0x41u, b + 1u);
			x += 2u;
		}
	}
}

void sub_0786CB(uint16_t u)
{
	uint8_t b = 0;
	uint16_t x = 0;
	uint16_t t1 = 0, t2 = 0;

	for (;;)
	{
		t1 = u;
		u = t1 + 2u;
		x = mem_read16(t1);
		for (;;)
		{
			t2 = u;
			u = t2 + 1u;
			b = mem_read8(t2);
			if (b == 0x23u)
				return;
			if (b == 0x2Fu)
				break;
			mem_write8(x - 0x2000u, 0u);
			mem_write8(x, 0x10u);
			mem_write8(x - 0x1FFFu, 0u);
			mem_write8(x + 1u, 0x10u);
			mem_write8(x - 0x1FC0u, 0u);
			mem_write8(x + 0x40u, 0x10u);
			mem_write8(x - 0x1FBFu, 0u);
			mem_write8(x + 0x41u, 0x10u);
			x += 2u;
		}
	}
}

void sub_0791D8(uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t b = 0;
	uint16_t d_2 = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0;

	stack = d >> 8;
	t1 = ~(unk_483D | unk_483E) & unk_483F & stack;
	b = t1;
	if (t1 == 0u)
	{
		carry = 0u;
		d_2 = ((uint32_t)stack << 8) | b;
	}
	else
	{
		b = 2u;
		d_2 = 0x4002u;
		carry = sub_0797ED(d_2);
		unk_4851++;
		carry = 1u;
		d_2 = ((uint32_t)stack << 8) | b;
	}
	*p_d = d_2;
	*p_carry = carry;
}

uint16_t sub_0791F7(uint16_t u, uint8_t d)
{
	uint8_t a = 0, b = 0;
	uint16_t d_2 = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t8 = 0, t9 = 0, t10 = 0;
	uint16_t t7 = 0, t11 = 0;

	b = (uint8_t)d;
	t1 = mem_read8(u + 2u);
	mem_write8(u + 2u, t1 + 1u);
	if (unk_483B == 0u)
	{
		t2 = mem_read8(u + 3u);
		mem_write8(u + 3u, t2 + 1u);
		t3 = mem_read8(u + 2u);
		a = t3;
		t4 = mem_read8(u + 5u);
		if (t4 <= a)
		{
			t5 = mem_read8(u + 5u);
			mem_write8(u + 2u, a - t5);
			t6 = mem_read8(u + 6u);
			t7 = t6 + unk_4837;
			a = (uint8_t)(t7 >> 8);
			b = (uint8_t)t7;
			unk_4837 = ((uint32_t)a << 8) | b;
		}
		d_2 = ((uint32_t)a << 8) | b;
		return d_2;
	}
	unk_481A++;
	a = unk_481C;
	t8 = mem_read8(u + 7u);
	b = t8;
	if (t8 == 0u)
		a += unk_483A;
	t9 = mem_read8(u + 2u);
	if (a <= t9)
	{
		stack = a;
		t10 = mem_read8(u + 2u);
		mem_write8(u + 2u, t10 - stack);
		t11 = unk_481D + mem_read16(u);
		b = (uint8_t)t11;
		mem_write16(u, ((uint32_t)(t11 >> 8) << 8) | b);
		a = 1u;
		mem_write8(u + 7u, 1u);
	}
	d_2 = ((uint32_t)a << 8) | b;
	return d_2;
}

void sub_079248(uint16_t x, uint16_t u)
{
	if (unk_4811 != 0u)
		return;
	sub_07924D(x, u);
}

void sub_07924D(uint16_t x, uint16_t u)
{
	uint8_t t1 = 0, t2 = 0;

	mem_write8(x + 1u, mem_read8(x));
	mem_write8(x, ~mem_read8(u));
	t1 = mem_read8(x + 1u);
	mem_write8(x + 3u, t1 & mem_read8(x));
	t2 = mem_read8(x + 1u);
	mem_write8(x + 2u, ~t2 & mem_read8(x));
}

void sub_079269(void)
{
	uint16_t ignored16 = 0, ignored16_3 = 0;

	sub_079270();
	sub_079275();
	sub_07927A(&ignored16, &ignored16_3);
}

uint16_t sub_079270(void)
{
	uint16_t d = 0, x = 0, y = 0;
	uint16_t t1 = 0, t2 = 0;

	x = 0x800u;
	d = 0x1010u;
	y = 0x400u;
	do
	{
		mem_write16(x + VIDEO_2000, d);
		t1 = x;
		x = t1 + 2u;
		mem_write16(t1, 0u);
		t2 = y - 1u;
		y = t2;
	} while (t2 != 0u);
	return y;
}

uint16_t sub_079275(void)
{
	uint16_t d = 0, x = 0, y = 0;
	uint16_t t1 = 0, t2 = 0;

	x = 0x1000u;
	d = 0x1010u;
	y = 0x400u;
	do
	{
		mem_write16(x + VIDEO_2000, d);
		t1 = x;
		x = t1 + 2u;
		mem_write16(t1, 0u);
		t2 = y - 1u;
		y = t2;
	} while (t2 != 0u);
	return y;
}

void sub_07927A(uint16_t *p_x, uint16_t *p_d)
{
	uint8_t a = 0, d = 0;
	uint16_t d_2 = 0, x = 0;
	uint8_t stack = 0, stack_2 = 0, stack_3 = 0, stack_4 = 0, stack_5 = 0;
	uint8_t t2 = 0, t3 = 0, t6 = 0;
	uint16_t t1 = 0, t4 = 0, t5 = 0;

	x = 0x200Eu;
	stack = 0x20u;
	do
	{
		stack_3 = x >> 8;
		stack_2 = (uint8_t)x;
		stack_4 = 0x12u;
		do
		{
			mem_write16(x - 0x2000u, 0u);
			t1 = x;
			x = t1 + 2u;
			mem_write16(t1, 0x1010u);
			t2 = stack_4;
			stack_4 = t2 - 1u;
		} while (t2 != 1u);
		x = (((uint32_t)stack_3 << 8) | stack_2) + 0x40u;
		t3 = stack;
		stack = t3 - 1u;
	} while (t3 != 1u);
	x = 0x200Cu;
	stack = 0x20u;
	stack_2 = 0u;
	stack_3 = 0u;
	stack_4 = 0x3Fu;
	stack_5 = 0x3Fu;
	do
	{
		t4 = ((uint32_t)stack_5 << 8) | stack_4;
		d = (uint8_t)t4;
		a = (uint8_t)(t4 >> 8);
		mem_write16(x, ((uint32_t)a << 8) | (d & 0xFFu));
		mem_write16(x + 0x26u, ((uint32_t)a << 8) | (d & 0xFFu));
		t5 = ((uint32_t)stack_3 << 8) | stack_2;
		d = (uint8_t)t5;
		a = (uint8_t)(t5 >> 8);
		mem_write16(x - 0x2000u, (uint32_t)a << 8);
		mem_write16(x - 0x1FDAu, (uint32_t)a << 8);
		x += 0x40u;
		t6 = stack;
		stack = t6 - 1u;
	} while (t6 != 1u);
	d_2 = (uint32_t)a << 8;
	*p_x = x;
	*p_d = d_2;
}

void sub_0792DD(uint16_t *p_x, uint16_t *p_y)
{
	uint8_t a = 0, b = 0;
	uint16_t x = 0, y = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0, t3 = 0;

	a = unk_480F | 2u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
	x = VIDEO_2000;
	y = 0x1000u;
	do
	{
		b = 8u;
		do
		{
			t1 = x;
			x = t1 + 2u;
			mem_write16(t1, 0u);
			t2 = b;
			b = t2 - 1u;
		} while (t2 != 1u);
		t3 = y - 0x10u;
		y = t3;
	} while (t3 != 0u);
	a = unk_480F & ~3u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
	*p_x = x;
	*p_y = y;
}

uint16_t sub_079311(uint16_t d)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d_2 = 0, ignored16 = 0, u = 0;
	uint8_t saved_unk_480E = 0, stack = 0;

	b = (uint8_t)d;
	unk_48E8 = d >> 8;
	saved_unk_480E = unk_480E;
	a = unk_48E8;
	carry = (int8_t)b < 0;
	b = (uint32_t)b << 1;
	if (carry)
	{
		stack = b & 0x7Fu;
		unk_480E = 0x12u;
		set_lines(unk_480E);
		u = GAME_TEXT_ENTRY(game_texts_address[0] + stack);
		u = sub_079384(u);
		unk_480E = saved_unk_480E;
		set_lines(unk_480E);
		return u;
	}
	stack = b & 0x7Fu;
	unk_480E = 0x12u;
	set_lines(unk_480E);
	u = GAME_TEXT_ENTRY(game_texts_address[0] + stack);
	d_2 = (d & 0xFFu) | ((uint32_t)a << 8);
	sub_07936D(d_2, &ignored16, &u);
	unk_480E = saved_unk_480E;
	set_lines(unk_480E);
	return u;
}

void sub_07936D(uint16_t d, uint16_t *p_x, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint8_t b = 0;
	uint16_t x = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	for (;;)
	{
		t1 = u;
		u = t1 + 2u;
		x = mem_read16(t1);
		for (;;)
		{
			t2 = u;
			u = t2 + 1u;
			b = mem_read8(t2);
			if (b == 0x23u)
			{
				*p_x = x;
				*p_u = u;
				return;
			}
			if (b == 0x2Fu)
				break;
			b -= 0x30u;
			mem_write8(x - 0x2000u, ((d & ~0xFFu) | b) >> 8);
			t3 = x;
			x = t3 + 1u;
			mem_write8(t3, b);
		}
	}
}

uint16_t sub_079384(uint16_t u)
{
	uint8_t b = 0;
	uint16_t x = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	for (;;)
	{
		t1 = u;
		u = t1 + 2u;
		x = mem_read16(t1);
		for (;;)
		{
			t2 = u;
			u = t2 + 1u;
			b = mem_read8(t2);
			if (b == 0x23u)
				return u;
			if (b == 0x2Fu)
				break;
			mem_write8(x - 0x2000u, 0u);
			t3 = x;
			x = t3 + 1u;
			mem_write8(t3, 0x10u);
		}
	}
	unreachable();
}

void sub_079423(void)
{
	lost_stack(0x079423u);
}

uint16_t sub_07945C(uint16_t x, uint16_t d)
{
	uint8_t a = 0;
	uint16_t x_2 = 0;
	uint8_t stack = 0;
	uint16_t t1 = 0, t2 = 0;

	a = (uint8_t)(d >> 8);
	stack = a;
	a = hex_digit_tiles[((((a & ~0xFu) >> 1) >> 1) >> 1) >> 1];
	io_write8(x - 0x2000u, (uint8_t)d);
	t1 = x;
	x_2 = t1 + 1u;
	io_write8(t1, a);
	a = hex_digit_tiles[stack & 0xFu];
	mem_write8(x_2 - 0x2000u, (uint8_t)d);
	t2 = x_2;
	x_2 = t2 + 1u;
	mem_write8(t2, a);
	return x_2;
}

uint16_t sub_07947D(uint16_t x, uint16_t d)
{
	uint8_t a = 0, b = 0;
	uint16_t d_2 = 0;
	uint8_t stack = 0;

	stack = (uint8_t)d;
	d_2 = (d & ~0xFFu) | unk_48F0;
	x = sub_07945C(x, d_2);
	b = unk_48F0;
	d_2 = ((uint32_t)stack << 8) | b;
	sub_07945C(x, d_2);
	a = (uint8_t)(d_2 >> 8);
	d_2 = ((uint32_t)a << 8) | b;
	return d_2;
}

void sub_079495(uint16_t x, uint16_t *p_d, uint32_t *p_negative)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t negative = *p_negative;
	uint16_t d_2 = 0, ignored16 = 0;

	unk_48E9 = d >> 8;
	unk_48EA = 0u;
	unk_48ED = (uint8_t)d;
	unk_48EE = 0u;
	*p_d = d_2;
	sub_0794EB(x, &ignored16, p_d, &negative);
	*p_negative = negative;
}

void sub_0794B9(uint16_t x, uint16_t *p_d, uint32_t *p_negative)
{
	uint32_t negative = *p_negative;
	uint16_t d = 0, ignored16 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0xFu);
	unk_48E9 = (uint8_t)(t1 >> 8u);
	unk_48EA = (uint8_t)t1;
	unk_48ED = 0u;
	unk_48EE = 0u;
	*p_d = d;
	sub_0794EB(x, &ignored16, p_d, &negative);
	*p_negative = negative;
}

void sub_0794C9(uint16_t x, uint16_t *p_d, uint32_t *p_negative)
{
	uint32_t negative = *p_negative;
	uint16_t d = 0, ignored16 = 0;
	uint16_t t1 = 0;

	unk_48E9 = 0u;
	unk_48EA = 0u;
	t1 = mem_read16(x + 0x14u);
	unk_48ED = (uint8_t)(t1 >> 8u);
	unk_48EE = (uint8_t)t1;
	*p_d = d;
	sub_0794EB(x, &ignored16, p_d, &negative);
	*p_negative = negative;
}

void sub_0794D9(uint16_t x, uint16_t *p_d, uint32_t *p_negative)
{
	uint32_t negative = *p_negative;
	uint16_t d = 0, ignored16 = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = mem_read16(x + 0xFu);
	unk_48E9 = (uint8_t)(t1 >> 8u);
	unk_48EA = (uint8_t)t1;
	t2 = mem_read16(x + 0x14u);
	unk_48ED = (uint8_t)(t2 >> 8u);
	unk_48EE = (uint8_t)t2;
	*p_d = d;
	sub_0794EB(x, &ignored16, p_d, &negative);
	*p_negative = negative;
}

void sub_0794EB(uint16_t x, uint16_t *p_u, uint16_t *p_d, uint32_t *p_negative)
{
	uint32_t negative = *p_negative;
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, u = 0;
	uint8_t t4 = 0, t10 = 0, t13 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t11 = 0, t12 = 0;
	uint32_t unk_48EC_halfword = 0;

	unk_48E8 = 0u;
	t1 = (((uint32_t)unk_48E9 << 8u) | unk_48EA);
	a = (uint8_t)(t1 >> 8);
	b = (uint8_t)t1;
	if ((int16_t)t1 < 0)
		unk_48E8 = ~unk_48E8;
	t2 = mem_read16(x + 0xDu);
	t3 = ((uint32_t)a << 8) | b;
	carry = (uint16_t)(t3 + t2) < t3;
	t4 = mem_read8(x + 0xCu);
	t5 = (((uint32_t)(uint8_t)(t4 + unk_48E8 + carry) << 8) | ((uint16_t)(t3 + t2) >> 8)) + unk_48AC;
	t6 = t5 - 0x40u;
	carry = ((t6 >> 8) >> 0) & 1u;
	unk_48E8 = 0u;
	unk_48E9 = ((uint8_t)(((uint8_t)t6 >> 1) | (carry << 7)) >> 1) >> 1;
	unk_48EC = 0u;
	t7 = (((uint32_t)unk_48ED << 8u) | unk_48EE);
	a = (uint8_t)(t7 >> 8);
	b = (uint8_t)t7;
	if ((int16_t)t7 < 0)
		unk_48EC = ~unk_48EC;
	t8 = mem_read16(x + 0x12u);
	t9 = ((uint32_t)a << 8) | b;
	carry = (uint16_t)(t9 + t8) < t9;
	t10 = mem_read8(x + 0x11u);
	a = t10 + unk_48EC + carry;
	unk_48EC_halfword = ((uint32_t)a << 8) | ((uint16_t)(t9 + t8) >> 8);
	unk_48EC = (uint8_t)(unk_48EC_halfword >> 8u);
	unk_48ED = (uint8_t)unk_48EC_halfword;
	t11 = 0x40u * ((((uint8_t)((((uint32_t)a << 8) | (uint8_t)((((uint32_t)a << 8) | 0x70u) - (((uint32_t)unk_48EC << 8u) | unk_48ED))) + unk_48B2) >> 1) >> 1) >> 1);
	t12 = t11 + (((uint32_t)unk_48E8 << 8u) | unk_48E9);
	b = (uint8_t)t12;
	u = unk_4000_ADDRESS + (((uint32_t)(t12 >> 8) << 8) | b);
	t13 = mem_read8(u);
	negative = t13 >> 7;
	d = ((uint32_t)t13 << 8) | b;
	*p_u = u;
	*p_d = d;
	*p_negative = negative;
}

void sub_079548(void)
{
	uint16_t d = 0;
	uint16_t stack = 0;

	d = AT16(unk_4858, -1);
	stack = d;
	d += AT16(unk_4858, -1);
	AT16(unk_4858, -1) = d;
	AT16(unk_4858, -1) = d + AT16(unk_4858, -1) + stack + 0x3711u;
}

void sub_07955F(uint16_t *p_x, uint16_t *p_u)
{
	uint8_t a = 0, d = 0;
	uint16_t u = 0, x = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	x = unk_4A40_ADDRESS;
	u = VIDEO_2000;
	do
	{
		unk_48E8 = 0x30u;
		d = 0u;
		a = 0u;
		do
		{
			t1 = x;
			x = t1 + 2u;
			mem_write16(t1, (uint32_t)a << 8);
			t2 = unk_48E8;
			unk_48E8 = t2 - 1u;
		} while (t2 != 1u);
		mem_write16(x - 7u, u);
		u += 0x80u;
	} while (x != 0x56A0u);
	*p_x = x;
	*p_u = u;
}

void sub_07957F(void)
{
	uint8_t a = 0, d = 0;
	uint16_t x = 0;
	uint8_t stack = 0, stack_10002 = 0;
	uint8_t t3 = 0, t4 = 0;
	uint16_t t1 = 0, t2 = 0;

	x = unk_4F80_ADDRESS;
	unk_48E8 = 8u;
	do
	{
		if (mem_read8(x) != 1u)
		{
			unk_48E9 = 0x30u;
			t1 = mem_read16(x + 0x59u);
			stack = t1 >> 8;
			stack_10002 = t1;
			d = 0u;
			a = 0u;
			do
			{
				t2 = x;
				x = t2 + 2u;
				mem_write16(t2, (uint32_t)a << 8);
				t3 = unk_48E9;
				unk_48E9 = t3 - 1u;
			} while (t3 != 1u);
			mem_write16(x - 7u, ((uint32_t)stack << 8) | stack_10002);
		}
		else
			x += 0x60u;
		t4 = unk_48E8;
		unk_48E8 = t4 - 1u;
	} while (t4 != 1u);
}

void sub_0795AF(void)
{
	uint8_t a = 0, d = 0;
	uint16_t x = 0;
	uint8_t stack = 0, stack_10002 = 0;
	uint8_t t3 = 0, t4 = 0;
	uint16_t t1 = 0, t2 = 0;

	x = 0x5280u;
	unk_48E8 = 0xAu;
	do
	{
		if (mem_read8(x) != 1u)
		{
			unk_48E9 = 0x30u;
			t1 = mem_read16(x + 0x59u);
			stack = t1 >> 8;
			stack_10002 = t1;
			d = 0u;
			a = 0u;
			do
			{
				t2 = x;
				x = t2 + 2u;
				mem_write16(t2, (uint32_t)a << 8);
				t3 = unk_48E9;
				unk_48E9 = t3 - 1u;
			} while (t3 != 1u);
			mem_write16(x - 7u, ((uint32_t)stack << 8) | stack_10002);
		}
		else
			x += 0x60u;
		t4 = unk_48E8;
		unk_48E8 = t4 - 1u;
	} while (t4 != 1u);
}

uint16_t sub_07960F(void)
{
	uint16_t u = 0, x = 0, y = 0;

	y = unk_4870_ADDRESS;
	x = unk_4871_ADDRESS;
	unk_4870 = 0u;
	u = 0x8Fu;
	while (u != 0u)
	{
		mem_write8(x, mem_read8(y));
		y++;
		x++;
		u--;
	}
	return sub_07961A();
}

uint16_t sub_07961A(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, u = 0, x = 0, y = 0;

	if (unk_485F != 0u)
	{
		io_write16(IO_1FA0, 0x255u);
		unk_4886 = 0x255u;
		io_write16(IO_1FA2, 0x71u);
		unk_4889 = 0x71u;
	}
	else
	{
		io_write16(IO_1FA0, 0x15u);
		unk_4886 = 0x15u;
		io_write16(IO_1FA2, 0x261u);
		unk_4889 = 0x261u;
	}
	unk_4888 = 0u;
	unk_488B = 0u;
	sub_07955F(&ignored16, &ignored16_2);
	y = VIDEO_18E0;
	x = VIDEO_18E1;
	io_write8(VIDEO_18E0, 0u);
	u = 0x1Fu;
	while (u != 0u)
	{
		mem_write8(x, mem_read8(y));
		y++;
		x++;
		u--;
	}
	y = VIDEO_1860;
	x = 0x1861u;
	io_write8(VIDEO_1860, 0u);
	u = 0x7Fu;
	while (u != 0u)
	{
		mem_write8(x, mem_read8(y));
		y++;
		x++;
		u--;
	}
	y = VIDEO_1840;
	x = VIDEO_1841;
	io_write8(VIDEO_1840, 0u);
	u = 0x1Fu;
	while (u != 0u)
	{
		mem_write8(x, mem_read8(y));
		y++;
		x++;
		u--;
	}
	sub_07955F(&ignored16, &ignored16_2);
	y = VIDEO_3C00;
	x = 0x3C01u;
	io_write8(VIDEO_3C00, 0u);
	u = 0x1FFu;
	while (u != 0u)
	{
		mem_write8(x, mem_read8(y));
		y++;
		x++;
		u--;
	}
	unk_49D3 = 0u;
	unk_49DB = 0u;
	unk_49E3 = 0u;
	unk_49EB = 0u;
	return u;
}

uint16_t sub_079692(void)
{
	unk_49D4 = 0u;
	unk_49DC = 0u;
	unk_49E4 = 0u;
	unk_49EC = 0u;
	return sub_0796A3();
}

uint16_t sub_0796A3(void)
{
	uint16_t u = 0, x = 0, y = 0;

	y = unk_4860_ADDRESS;
	x = unk_4861_ADDRESS;
	unk_4860 = 0u;
	u = 0x9Fu;
	while (u != 0u)
	{
		mem_write8(x, mem_read8(y));
		y++;
		x++;
		u--;
	}
	y = VIDEO_3840;
	x = 0x3841u;
	io_write8(VIDEO_3840, 0u);
	u = VIDEO_002F;
	while (u != 0u)
	{
		mem_write8(x, mem_read8(y));
		y++;
		x++;
		u--;
	}
	unk_49D6 = 0u;
	unk_49DE = 0u;
	unk_49E6 = 0u;
	unk_49EE = 0u;
	unk_4A02 = 0u;
	unk_4A04 = 0u;
	unk_4A06 = 0u;
	unk_4A09 = 0u;
	unk_4A0B = 0u;
	unk_4A0D = 0u;
	unk_4A10 = 0u;
	unk_4A12 = 0u;
	unk_4A14 = 0u;
	unk_4A17 = 0u;
	unk_4A19 = 0u;
	unk_4A1B = 0u;
	return sub_07961A();
}

void sub_0796FD(uint16_t x, uint8_t d)
{
	uint32_t carry = 0, half_carry = 0;
	uint8_t a = 0, high = 0;
	uint16_t score_addition = 0;
	uint8_t low = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	score_addition = score_additions_ADDRESS + (int8_t)((uint32_t)d << 1);
	low = SCORE_ADDITION(score_addition)->low;
	a = low;
	t1 = mem_read8(x + 1u);
	t2 = a + t1;
	half_carry = ((a ^ t1 ^ t2) >> 4) & 1u;
	carry = (uint8_t)(a + t1) < a;
	a = t2;
	t3 = konami_daa(a, half_carry, carry);
	carry = konami_daa_carry(a, half_carry, carry);
	mem_write8(x + 1u, t3);
	high = SCORE_ADDITION(score_addition)->high;
	t4 = mem_read8(x);
	t5 = high + t4 + carry;
	half_carry = ((high ^ t4 ^ t5) >> 4) & 1u;
	carry = konami_carry_add8(high, t4, carry);
	mem_write8(x, konami_daa(t5, half_carry, carry));
}

void sub_079718(uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t d_2 = 0;
	uint16_t d_3 = 0, x = 0;
	uint16_t t1 = 0;

	unk_48E8 = (uint8_t)(d >> 8u);
	unk_48E9 = (uint8_t)d;
	x = 0x4983u;
	unk_48EA = 0u;
	for (;;)
	{
		t1 = (((uint32_t)unk_48E8 << 8u) | unk_48E9);
		d_2 = (uint8_t)t1;
		if (mem_read16(x) <= (uint16_t)(((uint32_t)(t1 >> 8) << 8) | (d_2 & 0xFFu)))
		{
			carry = 1u;
			d_3 = (d_2 & 0xFFu) | ((uint32_t)unk_48EA << 8);
			break;
		}
		x += 8u;
		unk_48EA++;
		if (unk_48EA == 0xAu)
		{
			carry = 0u;
			d_3 = (d_2 & 0xFFu) | ((uint32_t)unk_48EA << 8);
			break;
		}
	}
	*p_d = d_3;
	*p_carry = carry;
}

uint16_t sub_079743(uint16_t d)
{
	uint8_t a = 0;
	uint16_t d_2 = 0, u = 0, x = 0;
	uint8_t t1 = 0, t4 = 0, t8 = 0;
	uint16_t t2 = 0, t3 = 0, t5 = 0, t6 = 0, t7 = 0;

	unk_48E8 = d >> 8;
	unk_48E9 = 9u;
	x = 0x49C8u;
	for (;;)
	{
		a = unk_48E8;
		if (a == unk_48E9)
			break;
		t1 = unk_48E9 - 1u;
		unk_48E9 = t1;
		if ((int8_t)t1 < 0)
		{
			d_2 = (d & 0xFFu) | ((uint32_t)a << 8);
			return d_2;
		}
		unk_48EA = 4u;
		do
		{
			t2 = mem_read16(x - 8u);
			d = t2;
			t3 = x;
			x = t3 + 2u;
			mem_write16(t3, ((uint32_t)(t2 >> 8) << 8) | (d & 0xFFu));
			t4 = unk_48EA;
			unk_48EA = t4 - 1u;
		} while (t4 != 1u);
		x -= 0x10u;
	}
	unk_48EA = 3u;
	u = unk_48F0_ADDRESS;
	do
	{
		t5 = u;
		u = t5 + 2u;
		t6 = mem_read16(t5);
		d = t6;
		a = (uint8_t)(t6 >> 8);
		t7 = x;
		x = t7 + 2u;
		mem_write16(t7, ((uint32_t)a << 8) | (d & 0xFFu));
		t8 = unk_48EA;
		unk_48EA = t8 - 1u;
	} while (t8 != 1u);
	d_2 = (d & 0xFFu) | ((uint32_t)a << 8);
	return d_2;
}

void sub_079784(uint16_t d, uint16_t *p_x, uint32_t *p_carry)
{
	uint16_t x = (uint16_t)*p_x;
	uint32_t carry = *p_carry;
	uint8_t b = 0;

	if (unk_4878 <= d >> 8)
	{
		unk_4878++;
		carry = 0u;
	}
	else
	{
		unk_48F0 = 0u;
		b = unk_4850;
		for (;;)
		{
			if (unk_48F0 == 4u)
			{
				carry = 0u;
				break;
			}
			if ((b & 1u) != 0u)
			{
				x = player_presses_ADDRESS;
				if ((mem_read8(player_presses[(int8_t)((uint8_t)((uint32_t)unk_48F0 << 1)) / 2]) & 0x30u) != 0u)
				{
					unk_4878 = 0u;
					carry = 1u;
					break;
				}
			}
			b = b >> 1;
			unk_48F0++;
		}
	}
	*p_x = x;
	*p_carry = carry;
}

void sub_0797B7(uint16_t d)
{
	uint16_t x = 0;
	uint16_t t1 = 0;

	if (d >> 8 == 0u)
		unk_485D++;
	t1 = unk_4940;
	x = t1 + 2u;
	mem_write16(t1, d);
	if (x >= 0x4980u)
		x = 0x4944u;
	unk_4940 = x;
}

uint32_t sub_0797D3(uint16_t d)
{
	uint32_t carry = 0;

	carry = d < 0xFFFFu;
	if (d == 0xFFFFu || (unk_4811 != 0u && unk_4813 == 0u))
		return carry;
	return sub_0797ED(d);
}

uint32_t sub_0797E3(uint16_t d)
{
	uint32_t carry = 0;

	carry = d < 0xFFFFu;
	if (d == 0xFFFFu || unk_4811 != 0u)
		return carry;
	return sub_0797ED(d);
}

uint32_t sub_0797ED(uint16_t d)
{
	uint32_t carry = 0;
	uint16_t x = 0;
	uint16_t t1 = 0;

	carry = d < 0xFFFFu;
	if (d == 0xFFFFu)
		return carry;
	t1 = unk_4900;
	x = t1 + 2u;
	mem_write16(t1, d);
	carry = x < 0x493Fu;
	if (x > 0x493Fu)
		x = 0x4904u;
	unk_4900 = x;
	return carry;
}

void sub_079808(uint8_t d)
{
	switch ((int8_t)(uint8_t)((uint32_t)d << 1))
	{
	case 0:
		sub_079812();
		break;
	case 2:
		sub_079815();
		break;
	case 4:
		sub_079818();
		break;
	case 6:
		sub_07981B();
		break;
	}
	unk_485D = 0u;
}

void sub_079812(void)
{
	sub_079269();
}

void sub_079815(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0;

	sub_07927A(&ignored16, &ignored16_2);
}

void sub_079818(void)
{
	sub_079270();
}

void sub_07981B(void)
{
	sub_079275();
}

void sub_07981E(uint8_t d)
{
	uint16_t d_2 = 0;

	d_2 = (d & 0xFFu) | ((uint32_t)unk_4871 << 8);
	sub_079311(d_2);
}

void sub_079824(uint8_t d)
{
	unk_4871 = d;
}

void sub_079828(uint8_t d)
{
	uint16_t x = 0;

	x = unk_49D4_ADDRESS;
	sub_0796FD(x, d);
}

void sub_07982E(uint8_t d)
{
	uint16_t x = 0;

	x = unk_49DC_ADDRESS;
	sub_0796FD(x, d);
}

void sub_079834(uint8_t d)
{
	uint16_t x = 0;

	x = unk_49E4_ADDRESS;
	sub_0796FD(x, d);
}

void sub_07983A(uint8_t d)
{
	uint16_t x = 0;

	x = unk_49EC_ADDRESS;
	sub_0796FD(x, d);
}

void sub_079840(void)
{
}

void sub_079841(void)
{
	uint8_t a = 0;

	if (unk_4879 != 0u)
		return;
	sub_079ADD();
	a = unk_480F | 2u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
	sub_079873();
	sub_0798F5();
	sub_079A37();
	a = unk_480F & ~3u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
}

void sub_079873(void)
{
	uint8_t a = 0;
	uint16_t x = 0;
	uint8_t t1 = 0;

	x = unk_4A40_ADDRESS;
	do
	{
		t1 = mem_read8(x);
		a = t1;
		if (t1 == 0u)
			sub_07988E(x);
		else if (a != 1u)
			x = sub_0798BD(x);
		x += 0x60u;
	} while (x != 0x5640u);
}

void sub_07988E(uint16_t x)
{
	uint8_t a = 0, d = 0;
	uint16_t u = 0, y = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0, t3 = 0, t4 = 0;

	t1 = mem_read16(x + 0x59u);
	u = t1;
	unk_48E8 = 8u;
	d = 0u;
	a = 0u;
	while (mem_read8(u) != 0u)
	{
		mem_write16(u, (uint32_t)a << 8);
		u += 0x10u;
		t2 = unk_48E8;
		unk_48E8 = t2 - 1u;
		if (t2 != 1u)
			continue;
		t3 = mem_read16(u - 2u);
		y = t3;
		if (t3 == 0u)
			break;
		unk_48E8 = 8u;
		d = 0u;
		a = 0u;
		mem_write16(u - 2u, 0u);
		mem_write8(y, 0u);
		t4 = mem_read16(y + 0x59u);
		u = t4;
	}
}

uint16_t sub_0798BD(uint16_t x)
{
	uint8_t a = 0;
	uint16_t y = 0;
	uint8_t t1 = 0, t3 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0;
	uint16_t t2 = 0, t4 = 0;

	t1 = mem_read8(x + 5u);
	if ((int8_t)t1 < 0)
	{
		t2 = mem_read16(x + 0x59u);
		y = t2;
		x = sub_079AE9(x, y);
		return x;
	}
	t3 = mem_read8(x + 6u);
	a = t3;
	if ((int8_t)t3 < 0)
	{
		t4 = mem_read16(x + 0x59u);
		y = t4;
		t5 = mem_read8(x + 8u);
		if (t5 == 0u)
			return sub_079AE9(x, y);
		x = sub_079AE9(x, y);
		t6 = mem_read8(x + 8u);
		mem_write8(x + 8u, t6 - 1u);
		return x;
	}
	if ((a & 0x40u) != 0u)
	{
		mem_write8(x + 6u, 0u);
		return x;
	}
	if ((mem_read8(x) & 0x10u) != 0u)
	{
		t4 = mem_read16(x + 0x59u);
		y = t4;
		t5 = mem_read8(x + 8u);
		if (t5 == 0u)
			return sub_079AE9(x, y);
		x = sub_079AE9(x, y);
		t6 = mem_read8(x + 8u);
		mem_write8(x + 8u, t6 - 1u);
		return x;
	}
	t7 = mem_read8(x + 8u);
	if (t7 != 0u)
	{
		t8 = mem_read8(x + 8u);
		mem_write8(x + 8u, t8 - 1u);
		mem_write8(x + 6u, 0u);
		return x;
	}
	t2 = mem_read16(x + 0x59u);
	y = t2;
	x = sub_079AE9(x, y);
	return x;
}

void sub_0798F5(void)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t u = 0, x = 0, y = 0;
	uint8_t t8 = 0, t14 = 0, t21 = 0, t22 = 0, t29 = 0, t33 = 0, t39 = 0, t43 = 0, t50 = 0, t51 = 0, t59 = 0, t60 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0, t15 = 0, t16 = 0, t17 = 0, t18 = 0, t19 = 0, t20 = 0, t23 = 0, t24 = 0, t25 = 0, t26 = 0, t27 = 0, t28 = 0, t30 = 0, t31 = 0, t32 = 0, t34 = 0, t35 = 0, t36 = 0, t37 = 0, t38 = 0, t40 = 0, t41 = 0, t42 = 0, t44 = 0, t45 = 0, t46 = 0, t47 = 0, t48 = 0, t49 = 0, t52 = 0, t53 = 0, t54 = 0, t55 = 0, t56 = 0, t57 = 0, t58 = 0;
	uint32_t unk_48F0_halfword = 0, unk_48F2_halfword = 0;

	if ((int16_t)unk_48DE < 0)
	{
		t1 = (int8_t)(unk_48B0 - (uint8_t)unk_48AC);
		a = (uint8_t)(t1 >> 8);
		b = (uint8_t)t1;
	}
	else
	{
		t2 = (int8_t)(0u - ((uint8_t)unk_48AC - unk_48B0));
		a = (uint8_t)(t2 >> 8);
		b = (uint8_t)t2;
	}
	unk_48F0_halfword = ((uint32_t)a << 8) | b;
	unk_48F0 = (uint8_t)(unk_48F0_halfword >> 8u);
	unk_48F1 = (uint8_t)unk_48F0_halfword;
	if ((int16_t)unk_48E0 < 0)
	{
		t3 = (int8_t)(0u - (unk_48B6 - (uint8_t)unk_48B2));
		a = (uint8_t)(t3 >> 8);
		b = (uint8_t)t3;
	}
	else
	{
		t4 = (int8_t)((uint8_t)unk_48B2 - unk_48B6);
		a = (uint8_t)(t4 >> 8);
		b = (uint8_t)t4;
	}
	unk_48F2_halfword = ((uint32_t)a << 8) | b;
	unk_48F2 = (uint8_t)(unk_48F2_halfword >> 8u);
	unk_48F3 = (uint8_t)unk_48F2_halfword;
	x = unk_4A40_ADDRESS;
	do
	{
		if (mem_read8(x) > 1u)
		{
			t5 = mem_read16(x + 0xFu);
			t6 = ((uint32_t)unk_48F1 << 8) + t5;
			a = (uint8_t)(t6 >> 8);
			b = (uint8_t)t6;
			if (t6 != 0u)
			{
				t7 = mem_read16(x + 0xDu);
				t8 = mem_read8(x + 0xDu);
				t9 = (int8_t)(((uint16_t)((((uint32_t)a << 8) | b) + t7) >> 8) - t8);
				unk_48FC = t9;
				unk_48F6 = (unk_48F6 & 0xFFu) | 0x800u;
				t10 = mem_read16(x + 0x59u);
				u = t10;
				while (mem_read8(u) != 0u)
				{
					t11 = unk_48FC;
					t12 = mem_read16(u + 6u);
					t13 = t11 + t12;
					mem_write16(u + 6u, t13);
					u += 0x10u;
					t14 = (uint8_t)(unk_48F6 >> 8u);
					unk_48F6 = (unk_48F6 & 0xFFu) | ((t14 - 1u & 0xFFu) << 8u);
					if (t14 != 1u)
						continue;
					t15 = mem_read16(u - 2u);
					y = t15;
					if (t15 == 0u)
						break;
					t16 = mem_read16(y + 0x59u);
					u = t16;
					unk_48F6 = (unk_48F6 & 0xFFu) | 0x800u;
				}
			}
			t17 = mem_read16(x + 0xDu);
			t18 = mem_read16(x + 0xFu);
			t19 = t17;
			t20 = t19 + t18;
			carry = (uint16_t)(t19 + t18) < t19;
			mem_write16(x + 0xDu, t20);
			t21 = mem_read8(x + 0xFu);
			t22 = mem_read8(x + 0xCu);
			mem_write8(x + 0xCu, ((uint16_t)(int8_t)t21 >> 8) + t22 + carry);
			t23 = (((uint32_t)unk_48F0 << 8u) | unk_48F1);
			t24 = mem_read16(x + 0xCu);
			t25 = t23 + t24;
			mem_write16(x + 0xCu, t25);
			t26 = mem_read16(x + 0x14u);
			t27 = ((uint32_t)unk_48F3 << 8) + t26;
			t28 = mem_read16(x + 0x12u);
			t29 = mem_read8(x + 0x12u);
			t30 = (int8_t)(((uint16_t)(t27 + t28) >> 8) - t29);
			unk_48FE = t30;
			t31 = mem_read16(x + 0x19u);
			t32 = mem_read16(x + 0x17u);
			t33 = mem_read8(x + 0x17u);
			t34 = (int8_t)(((uint16_t)(t31 + t32) >> 8) - t33);
			t35 = t34 + unk_48FE;
			t36 = t35;
			unk_48FC = t36;
			if (t36 != 0u || (mem_read8(x) & 8u) != 0u)
			{
				unk_48F6 = (unk_48F6 & 0xFFu) | 0x800u;
				t37 = mem_read16(x + 0x59u);
				u = t37;
				while (mem_read8(u) != 0u)
				{
					t38 = unk_48FC;
					a = (uint8_t)(t38 >> 8);
					b = (uint8_t)t38;
					t39 = mem_read8(u + 0xCu);
					if ((int8_t)t39 < 0)
					{
						t40 = unk_48FE;
						a = (uint8_t)(t40 >> 8);
						b = (uint8_t)t40;
					}
					t41 = mem_read16(u + 4u);
					t42 = (((uint32_t)a << 8) | b) + t41;
					mem_write16(u + 4u, t42);
					u += 0x10u;
					t43 = (uint8_t)(unk_48F6 >> 8u);
					unk_48F6 = (unk_48F6 & 0xFFu) | ((t43 - 1u & 0xFFu) << 8u);
					if (t43 != 1u)
						continue;
					t44 = mem_read16(u - 2u);
					y = t44;
					if (t44 == 0u)
						break;
					t45 = mem_read16(y + 0x59u);
					u = t45;
					unk_48F6 = (unk_48F6 & 0xFFu) | 0x800u;
				}
			}
			t46 = mem_read16(x + 0x12u);
			t47 = mem_read16(x + 0x14u);
			t48 = t46;
			t49 = t48 + t47;
			carry = (uint16_t)(t48 + t47) < t48;
			mem_write16(x + 0x12u, t49);
			t50 = mem_read8(x + 0x14u);
			t51 = mem_read8(x + 0x11u);
			mem_write8(x + 0x11u, ((uint16_t)(int8_t)t50 >> 8) + t51 + carry);
			t52 = (((uint32_t)unk_48F2 << 8u) | unk_48F3);
			t53 = mem_read16(x + 0x11u);
			t54 = t52 + t53;
			mem_write16(x + 0x11u, t54);
			t55 = mem_read16(x + 0x19u);
			a = (uint8_t)(t55 >> 8);
			b = (uint8_t)t55;
			if (t55 != 0u)
			{
				t56 = mem_read16(x + 0x17u);
				t57 = ((uint32_t)a << 8) | b;
				t58 = t57 + t56;
				carry = (uint16_t)(t57 + t56) < t57;
				mem_write16(x + 0x17u, t58);
				t59 = mem_read8(x + 0x19u);
				t60 = mem_read8(x + 0x16u);
				mem_write8(x + 0x16u, ((uint16_t)(int8_t)t59 >> 8) + t60 + carry);
			}
		}
		x += 0x60u;
	} while (x != 0x5640u);
}

void sub_079A37(void)
{
	uint8_t a = 0, b = 0;
	uint16_t u = 0, x = 0, y = 0;
	uint8_t stack_10001 = 0, stack_10002 = 0;
	uint16_t stack = 0;
	uint8_t t8 = 0, t12 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t9 = 0, t10 = 0, t11 = 0;

	x = unk_4A40_ADDRESS;
	u = 0x3000u;
	do
	{
		if (mem_read8(x) > 1u)
		{
			t1 = mem_read16(x + 0x11u);
			a = (uint8_t)(t1 >> 8);
			b = (uint8_t)t1;
			if ((int16_t)t1 >= 0)
			{
				if ((int16_t)(((uint32_t)a << 8) | b) <= 0x17F)
				{
					t2 = mem_read16(x + 0x11u);
					a = (uint8_t)(t2 >> 8);
					b = (uint8_t)t2;
				}
				else
				{
					a = 1u;
					b = 0x7Fu;
				}
			}
			else
			{
				a = 0u;
				b = 0u;
			}
			b &= ~1u;
			t3 = io_read16(u + (((uint32_t)a << 8) | b));
			y = t3;
			if (t3 == 0u)
				io_write16(u + (((uint32_t)a << 8) | b), x);
			else
			{
				stack = y;
				a = (uint8_t)(stack >> 8);
				b = (uint8_t)stack;
				do
				{
					stack_10001 = a;
					stack_10002 = b;
					y = ((uint32_t)stack_10001 << 8) | stack_10002;
					t4 = io_read16(y + 0x5Eu);
					a = (uint8_t)(t4 >> 8);
					b = (uint8_t)t4;
				} while (t4 != 0u);
				io_write16(y + 0x5Eu, x);
			}
		}
		x += 0x60u;
	} while (x != 0x5640u);
	y = 0x3000u;
	unk_48F1 = 1u;
	unk_48F0 = 0xC0u;
	do
	{
		t5 = y;
		y = t5 + 2u;
		t6 = mem_read16(t5);
		x = t6;
		if (t6 != 0u)
		{
			mem_write16(y - 2u, 0u);
			for (;;)
			{
				t7 = mem_read16(x + 0x59u);
				u = t7;
				unk_48F2 = 8u;
				while (mem_read8(u) != 0u)
				{
					a = unk_48F1;
					if ((int8_t)mem_read8(x) >= 0)
						a = 0u;
					mem_write8(u + 1u, a);
					unk_48F1++;
					u += 0x10u;
					t8 = unk_48F2;
					unk_48F2 = t8 - 1u;
					if (t8 != 1u)
						continue;
					t9 = mem_read16(u - 2u);
					a = (uint8_t)(t9 >> 8);
					b = (uint8_t)t9;
					if (t9 == 0u)
						break;
					stack_10001 = a;
					stack_10002 = b;
					t10 = io_read16((((uint32_t)stack_10001 << 8) | stack_10002) + 0x59u);
					u = t10;
					unk_48F2 = 8u;
				}
				t11 = mem_read16(x + 0x5Eu);
				u = t11;
				if (t11 == 0u)
					break;
				mem_write16(x + 0x5Eu, 0u);
				x = u;
			}
		}
		t12 = unk_48F0;
		unk_48F0 = t12 - 1u;
	} while (t12 != 1u);
}

void sub_079ADD(void)
{
	unk_48FA = (unk_48FA & 0xFFu) | ((step_sprite_priorities[(int8_t)unk_4803] & 0xFFu) << 8u);
}

uint16_t sub_079AE9(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0, index = 0;
	uint16_t u = 0, x_2 = 0;
	uint8_t stack = 0, stack_2 = 0;
	uint8_t t1 = 0, t2 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t11 = 0, t12 = 0, t18 = 0, t19 = 0;
	uint16_t t3 = 0, t4 = 0, t10 = 0, t13 = 0, t14 = 0, t15 = 0, t16 = 0, t17 = 0, t20 = 0;

	unk_48F6 &= 0xFF00u;
	unk_48F3 = 0u;
	if ((mem_read8(x) & 8u) != 0u)
		unk_48F6 = (unk_48F6 & 0xFF00u) | ((uint8_t)unk_48F6 + 1u & 0xFFu);
	t1 = mem_read8(x + 6u);
	unk_48F6 = (unk_48F6 & 0xFFu) | ((t1 & 0xFFu) << 8u);
	mem_write8(x + 6u, 0u);
	a = 0u;
	t2 = mem_read8(x + 4u);
	b = t2;
	if ((int8_t)t2 < 0)
	{
		b &= 0x7Fu;
		carry = (int8_t)b < 0;
		t3 = animation_sets_high_ADDRESS + (((((uint32_t)a << 1) | carry) << 8) | (uint8_t)((uint32_t)b << 1));
		unk_480E = ANIMATION_SET(t3)->bank;
		set_lines(unk_480E);
		index = ANIMATION_SET(t3)->index;
	}
	else
	{
		carry = (int8_t)b < 0;
		t4 = animation_sets_ADDRESS + (((((uint32_t)a << 1) | carry) << 8) | (uint8_t)((uint32_t)b << 1));
		unk_480E = ANIMATION_SET(t4)->bank;
		set_lines(unk_480E);
		index = ANIMATION_SET(t4)->index;
	}
	t5 = mem_read8(x + 8u);
	if (t5 == 0u)
	{
		t6 = mem_read8(x + 7u);
		mem_write8(x + 7u, t6 + 1u);
	}
	u = ANIMATION_SET_INDEX(BANK_WINDOW + index);
	unk_48F4 = 0xC0u;
	t7 = mem_read8(x + 9u);
	if ((t7 & 0x40u) != 0u)
		unk_48F4 |= 0x10u;
	a = 0u;
	t8 = mem_read8(x + 5u);
	b = t8;
	if ((int8_t)t8 < 0)
	{
		mem_write8(x + 8u, 0u);
		mem_write8(x + 7u, 0u);
		b &= 0x7Fu;
		mem_write8(x + 5u, b);
	}
	carry = (int8_t)b < 0;
	t9 = mem_read8(x + 7u);
	t10 = mem_read16(u + (((((uint32_t)a << 1) | carry) << 8) | (uint8_t)((uint32_t)b << 1))) + (int8_t)(((uint32_t)t9 << 1) << 1);
	u = t10 + 1u;
	t11 = mem_read8(t10);
	a = t11;
	if ((int8_t)t11 < 0)
	{
		t12 = mem_read8(x + 6u);
		mem_write8(x + 6u, t12 | 1u);
		if ((a & 1u) != 0u)
		{
			t13 = u;
			mem_write8(x + 7u, mem_read8(t13));
			u = mem_read16(t13 + 1u);
		}
		else
		{
			mem_write8(x + 7u, 0u);
			t14 = u;
			mem_write8(x + 5u, mem_read8(t14));
			u = mem_read16(t14 + 1u);
		}
		t15 = u;
		a = mem_read8(t15);
		unk_48F1 = a & 0x10u;
		unk_48F2 = a & 0xFu;
		t16 = t15 + 1u;
		u = t16 + 1u;
		mem_write8(x + 8u, io_read8(t16));
	}
	else
	{
		unk_48F1 = a & 0x10u;
		unk_48F2 = a & 0xFu;
		t17 = u;
		u = t17 + 1u;
		a = mem_read8(t17);
		t18 = mem_read8(x + 8u);
		if (t18 == 0u)
			mem_write8(x + 8u, a);
	}
	if (unk_48F1 != 0u)
	{
		t19 = mem_read8(x + 6u);
		mem_write8(x + 6u, t19 | 2u);
	}
	u = mem_read16(u);
	sub_079DE2(x);
	unk_48F3 = 0u;
	if ((uint8_t)(unk_48F2 + (uint8_t)unk_48F6) < 8u)
		return sub_079C02(x, y, u);
	stack_2 = x >> 8;
	stack = (uint8_t)x;
	t20 = mem_read16(y + 0x7Eu);
	x_2 = t20;
	if (t20 != 0u)
	{
		mem_write16(y + 0x7Eu, x_2);
		x_2 = ((uint32_t)stack_2 << 8) | stack;
		return sub_079C02(x_2, y, u);
	}
	sub_079CBD(&x_2, &carry);
	if (carry)
	{
		mem_write16(y + 0x7Eu, x_2);
		x_2 = ((uint32_t)stack_2 << 8) | stack;
		return sub_079C02(x_2, y, u);
	}
	x_2 = ((uint32_t)stack_2 << 8) | stack;
	sub_07988E(x_2);
	return x_2;
}

void sub_079C00(void)
{
	lost_stack(0x079C00u);
}

uint16_t sub_079C02(uint16_t x, uint16_t y, uint16_t u)
{
	uint32_t negative = 0, carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t u_2 = 0, y_2 = 0;
	uint8_t stack = 0, stack_2 = 0, stack_3 = 0, stack_4 = 0, stack_5 = 0, stack_6 = 0;
	uint8_t t3 = 0, t6 = 0, t8 = 0, t16 = 0, t18 = 0, t40 = 0;
	uint16_t t1 = 0, t2 = 0, t4 = 0, t5 = 0, t7 = 0, t9 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0, t15 = 0, t17 = 0, t19 = 0, t21 = 0, t22 = 0, t23 = 0, t24 = 0, t25 = 0, t26 = 0, t27 = 0, t28 = 0, t29 = 0, t30 = 0, t31 = 0, t32 = 0, t33 = 0, t34 = 0, t35 = 0, t36 = 0, t37 = 0, t38 = 0, t39 = 0, t41 = 0, t42 = 0;
	uint32_t t10 = 0, t20 = 0;

	do
	{
		unk_48F5 = 0u;
		t1 = u;
		u_2 = t1 + 2u;
		t2 = mem_read16(t1);
		a = (uint8_t)(t2 >> 8);
		b = (uint8_t)t2;
		if ((int16_t)t2 >= 0)
			mem_write16(y + 2u, ((uint32_t)a << 8) | b);
		else
		{
			mem_write16(y + 2u, ((a & 0x7Fu) << 8) | b);
			unk_48F5 = 0x10u;
		}
		a = (uint8_t)unk_48FA;
		t3 = mem_read8(x + 9u);
		b = t3;
		if ((int8_t)t3 < 0)
		{
			u_2++;
			b &= 0xFu;
		}
		else
		{
			t4 = u_2;
			u_2 = t4 + 1u;
			b = mem_read8(t4);
		}
		mem_write16(y + 0xCu, ((uint32_t)a << 8) | b);
		t5 = u_2;
		u_2 = t5 + 1u;
		mem_write8(y, (unk_48F4 ^ unk_48F5) | mem_read8(t5));
		if ((mem_read8(x) & 0x10u) != 0u)
		{
			stack = unk_480E;
			mem_write8(y, mem_read8(y) & 0xBFu);
			t6 = mem_read8(x + 0xAu);
			b = t6;
			if (b < 0x10u)
				b = 0x10u;
			mem_write8(y + 0xBu, b);
			b -= 0x10u;
			unk_48F0 = 0u;
			t7 = u_2;
			u_2 = t7 + 1u;
			t8 = mem_read8(t7);
			negative = t8 >> 7;
			a = t8;
			if (t8 == 0u)
			{
				t9 = mem_read16(x + 0xCu);
				a = (uint8_t)(t9 >> 8);
				b = (uint8_t)t9;
			}
			else
			{
				if (negative)
				{
					a = 0u - a;
					unk_48F0--;
				}
				unk_48EB = a;
				unk_48E9 = (uint8_t)(x >> 8u);
				unk_48EA = (uint8_t)x;
				stack_3 = y >> 8;
				stack_2 = (uint8_t)y;
				stack_4 = b;
				unk_480E = 0x1Du;
				set_lines(unk_480E);
				b = stack_4;
				carry = (int8_t)b < 0;
				stack_4 = unk_48EB;
				stack_5 = 0u;
				t10 = (uint32_t)mem_read16(zoom_steps_address[0] + ((carry << 8) | (uint8_t)((uint32_t)b << 1))) * (uint16_t)(((uint32_t)stack_5 << 8) | stack_4);
				stack_5 = (uint16_t)t10 >> 8;
				stack_6 = t10 >> 16;
				t11 = ((uint32_t)stack_6 << 8) | stack_5;
				unk_48FE = t11;
				y = ((uint32_t)stack_3 << 8) | stack_2;
				x = (((uint32_t)unk_48E9 << 8u) | unk_48EA);
				if (((unk_48F4 ^ unk_48F0) & 0x10u) != 0u)
				{
					t12 = io_read16(x + 0xCu);
					t13 = t12 - unk_48FE;
					a = (uint8_t)(t13 >> 8);
					b = (uint8_t)t13;
				}
				else
				{
					t14 = io_read16(x + 0xCu);
					t15 = t14 + unk_48FE;
					a = (uint8_t)(t15 >> 8);
					b = (uint8_t)t15;
				}
			}
			mem_write16(y + 6u, ((uint32_t)a << 8) | b);
			stack_3 = u_2 >> 8;
			stack_2 = (uint8_t)u_2;
			unk_480E = stack;
			set_lines(unk_480E);
			u_2 = ((uint32_t)stack_3 << 8) | stack_2;
			t16 = mem_read8(x + 0xBu);
			b = t16;
			if (b < 0x10u)
				b = 0x10u;
			mem_write8(y + 9u, b);
			b -= 0x10u;
			unk_48F0 = 0u;
			t17 = u_2;
			u = t17 + 1u;
			t18 = mem_read8(t17);
			negative = t18 >> 7;
			a = t18;
			if (t18 == 0u)
			{
				t19 = mem_read16(x + 0x11u);
				a = (uint8_t)(t19 >> 8);
				b = (uint8_t)t19;
			}
			else
			{
				if (negative)
				{
					a = 0u - a;
					unk_48F0--;
				}
				unk_48EB = a;
				unk_48E9 = (uint8_t)(x >> 8u);
				unk_48EA = (uint8_t)x;
				stack_3 = y >> 8;
				stack_2 = (uint8_t)y;
				stack_4 = b;
				unk_480E = 0x1Du;
				set_lines(unk_480E);
				b = stack_4;
				carry = (int8_t)b < 0;
				stack_4 = unk_48EB;
				stack_5 = 0u;
				t20 = (uint32_t)mem_read16(zoom_steps_address[0] + ((carry << 8) | (uint8_t)((uint32_t)b << 1))) * (uint16_t)(((uint32_t)stack_5 << 8) | stack_4);
				stack_5 = (uint16_t)t20 >> 8;
				stack_6 = t20 >> 16;
				t21 = ((uint32_t)stack_6 << 8) | stack_5;
				unk_48FE = t21;
				y = ((uint32_t)stack_3 << 8) | stack_2;
				x = (((uint32_t)unk_48E9 << 8u) | unk_48EA);
				if (unk_48F0 != 0u)
				{
					t22 = io_read16(x + 0x11u);
					t23 = t22 - unk_48FE;
					a = (uint8_t)(t23 >> 8);
					b = (uint8_t)t23;
				}
				else
				{
					t24 = io_read16(x + 0x11u);
					t25 = t24 + unk_48FE;
					a = (uint8_t)(t25 >> 8);
					b = (uint8_t)t25;
				}
			}
			t26 = mem_read16(x + 0x16u);
			t27 = (((uint32_t)a << 8) | b) + t26;
			mem_write16(y + 4u, t27);
			unk_480E = stack;
			set_lines(unk_480E);
		}
		else
		{
			t28 = u_2;
			u_2 = t28 + 1u;
			b = mem_read8(t28);
			if ((unk_48F4 & 0x10u) != 0u)
				b = 0u - b;
			t29 = (int8_t)b;
			t30 = mem_read16(x + 0xCu);
			t31 = t29 + t30;
			mem_write16(y + 6u, t31);
			t32 = u_2;
			u = t32 + 1u;
			t33 = (int8_t)mem_read8(t32);
			t34 = mem_read16(x + 0x11u);
			t35 = t33 + t34;
			t36 = mem_read16(x + 0x16u);
			t37 = t35 + t36;
			mem_write16(y + 4u, t37);
			mem_write8(y + 9u, 0x40u);
		}
		y += 0x10u;
		unk_48F3++;
		if (unk_48F3 == 8u)
		{
			t38 = mem_read16(y - 2u);
			stack = t38;
			stack_2 = t38 >> 8;
			t39 = io_read16((((uint32_t)stack_2 << 8) | stack) + 0x59u);
			y = t39;
			unk_48F3 = 0u;
		}
		t40 = unk_48F2 - 1u;
		unk_48F2 = t40;
	} while ((int8_t)t40 >= 0);
	mem_write8(x, mem_read8(x) & 0xEFu);
	if ((uint8_t)unk_48F6 != 0u)
	{
		y = sub_079DFE(x, y);
		unk_48F3++;
	}
	for (;;)
	{
		if (unk_48F3 == 8u)
		{
			t41 = mem_read16(y - 2u);
			u_2 = t41;
			if (t41 == 0u)
				break;
			mem_write16(y - 2u, 0u);
			y_2 = u_2;
			mem_write8(y_2, 0u);
			t42 = mem_read16(y_2 + 0x59u);
			y = t42;
			unk_48F3 = 0u;
		}
		if (mem_read8(y) == 0u)
			break;
		mem_write16(y, 0u);
		y += 0x10u;
		unk_48F3++;
	}
	return x;
}

void sub_079CBD(uint16_t *p_x, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t x = 0;

	x = unk_55E0_ADDRESS;
	for (;;)
	{
		if (mem_read8(x) == 0u)
		{
			mem_write8(x, 1u);
			carry = 1u;
			break;
		}
		x -= 0x60u;
		if (x == unk_4D40_ADDRESS)
		{
			carry = 0u;
			break;
		}
	}
	*p_x = x;
	*p_carry = carry;
}

void sub_079DE2(uint16_t x)
{
	uint8_t a = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 9u);
	t2 = t1 & 0x30u;
	a = t2;
	if (t2 == 0u)
	{
		unk_48FA = (unk_48FA & 0xFF00u) | ((uint8_t)(unk_48FA >> 8u) & 0xFFu);
		return;
	}
	a = (a >> 1) >> 1;
	unk_48FA = (unk_48FA & 0xFF00u) | (a & 0xFFu);
	unk_48FA = (unk_48FA & 0xFF00u) | (((a >> 1) >> 1) | (uint8_t)unk_48FA & 0xFFu);
}

uint16_t sub_079DFE(uint16_t x, uint16_t y)
{
	uint16_t shadow_sprite = 0;
	uint8_t t5 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t6 = 0, code = 0;

	t1 = mem_read16(x + 0x5Cu);
	t2 = mem_read16(x + 0x11u);
	t3 = t1 + t2;
	mem_write16(y + 4u, t3);
	t4 = mem_read16(x + 0xCu);
	mem_write16(y + 6u, t4);
	t5 = mem_read8(x + 0x5Bu);
	t6 = shadow_sprites_ADDRESS + (uint8_t)(((t5 & 0xFu) << 1) << 1);
	shadow_sprite = t6 + 1u;
	mem_write8(y, SHADOW_SPRITE(t6)->attributes);
	sub_079DE2(x);
	mem_write16(y + 0xCu, ((uint8_t)unk_48FA | 0x80u) << 8);
	code = SHADOW_SPRITE(shadow_sprite - 0x1u)->code;
	mem_write16(y + 2u, code);
	mem_write8(y + 9u, 0x40u);
	y += 0x10u;
	return y;
}

void sub_079E39(uint16_t y, uint16_t u)
{
	uint8_t a = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	unk_4811 = 1u;
	unk_486A = 0u;
	if (unk_483B != 0u)
	{
		t1 = unk_4817;
		a = (uint8_t)(t1 >> 8);
		if (t1 == 0u)
		{
			t2 = unk_481F;
			a = (uint8_t)(t2 >> 8);
			if (t2 == 0u)
			{
				t3 = unk_4827;
				a = (uint8_t)(t3 >> 8);
				if (t3 == 0u)
				{
					t4 = unk_482F;
					a = (uint8_t)(t4 >> 8);
					if (t4 == 0u)
					{
						if (unk_4851 != 0u)
						{
							unk_4801++;
							unk_4802 = 0u;
							unk_4803 = 0u;
							unk_4804 = 0u;
							unk_4805 = 0u;
							unk_4801 = 5u;
						}
						switch ((int8_t)(uint8_t)((uint32_t)unk_4801 << 1))
						{
						case 0:
							sub_079EDA(y, u);
							break;
						case 2:
							sub_07A075(y, u);
							break;
						case 4:
							sub_079F36(y, u);
							break;
						case 6:
							sub_07A209(y, u);
							break;
						case 8:
							sub_07A2CD(y, u);
							break;
						case 10:
							sub_07A34E(y, u);
							break;
						case 12:
							sub_079EE3();
							break;
						case 14:
							sub_079EF6();
							break;
						case 16:
							sub_079F08(y, u);
							break;
						case 18:
							sub_079F17();
							break;
						case 20:
							sub_079F3F();
							break;
						case 22:
							sub_079F52(u);
							break;
						case 24:
							sub_07A007();
							break;
						case 26:
							sub_07A024();
							break;
						case 28:
							sub_07A07E();
							break;
						case 30:
							sub_07A12B(u);
							break;
						case 32:
							sub_07A212(u);
							break;
						case 34:
							sub_07A240();
							break;
						case 36:
							sub_07A28C(u);
							break;
						case 38:
							sub_07A29B(u);
							break;
						case 40:
							sub_07A2D6(u);
							break;
						case 42:
							sub_07A2EB();
							break;
						case 44:
							sub_07A314();
							break;
						case 46:
							sub_07A329(u);
							break;
						case 48:
							sub_07A357();
							break;
						case 50:
							sub_07A35F();
							break;
						case 52:
							sub_07A384();
							break;
						}
						return;
					}
				}
			}
		}
	}
	else
	{
		t5 = unk_4837;
		a = (uint8_t)(t5 >> 8);
		if (t5 == 0u)
		{
			if (unk_4851 != 0u)
			{
				unk_4801++;
				unk_4802 = 0u;
				unk_4803 = 0u;
				unk_4804 = 0u;
				unk_4805 = 0u;
				unk_4801 = 5u;
			}
			switch ((int8_t)(uint8_t)((uint32_t)unk_4801 << 1))
			{
			case 0:
				sub_079EDA(y, u);
				break;
			case 2:
				sub_07A075(y, u);
				break;
			case 4:
				sub_079F36(y, u);
				break;
			case 6:
				sub_07A209(y, u);
				break;
			case 8:
				sub_07A2CD(y, u);
				break;
			case 10:
				sub_07A34E(y, u);
				break;
			case 12:
				sub_079EE3();
				break;
			case 14:
				sub_079EF6();
				break;
			case 16:
				sub_079F08(y, u);
				break;
			case 18:
				sub_079F17();
				break;
			case 20:
				sub_079F3F();
				break;
			case 22:
				sub_079F52(u);
				break;
			case 24:
				sub_07A007();
				break;
			case 26:
				sub_07A024();
				break;
			case 28:
				sub_07A07E();
				break;
			case 30:
				sub_07A12B(u);
				break;
			case 32:
				sub_07A212(u);
				break;
			case 34:
				sub_07A240();
				break;
			case 36:
				sub_07A28C(u);
				break;
			case 38:
				sub_07A29B(u);
				break;
			case 40:
				sub_07A2D6(u);
				break;
			case 42:
				sub_07A2EB();
				break;
			case 44:
				sub_07A314();
				break;
			case 46:
				sub_07A329(u);
				break;
			case 48:
				sub_07A357();
				break;
			case 50:
				sub_07A35F();
				break;
			case 52:
				sub_07A384();
				break;
			}
			return;
		}
		unk_485B = 0u;
	}
	unk_485B = a;
	unk_49D0 = 0u;
	unk_49D8 = 0u;
	unk_49E0 = 0u;
	unk_49E8 = 0u;
	unk_49D7 = 0u;
	unk_49DF = 0u;
	unk_49E7 = 0u;
	unk_49EF = 0u;
	unk_4811 = 0u;
	unk_4850 = 0u;
	unk_4800++;
	unk_4801 = 0u;
	unk_4802 = 0u;
	unk_4803 = 0u;
	unk_4804 = 0u;
	unk_4805 = 0u;
	unk_4800 = 2u;
	unk_4807 = 0u;
	unk_4809 = 0u;
	unk_480A = 0u;
	AT16(unk_480B, -1) = 0u;
	unk_480D = 0u;
}

void sub_079EDA(uint16_t y, uint16_t u)
{
	for (;;)
	{
		switch ((int8_t)(uint8_t)((uint32_t)unk_4802 << 1))
		{
		case 0:
			sub_079EE3();
			return;
		case 2:
			sub_079EF6();
			return;
		case 4:
			sub_079F08(y, u);
			return;
		case 6:
			sub_079F17();
			return;
		case 8:
			sub_079F3F();
			return;
		case 10:
			sub_079F52(u);
			return;
		case 12:
			sub_07A007();
			return;
		case 14:
			sub_07A024();
			return;
		case 16:
			sub_07A07E();
			return;
		case 18:
			sub_07A12B(u);
			return;
		case 20:
			sub_07A212(u);
			return;
		case 22:
			sub_07A240();
			return;
		case 24:
			sub_07A28C(u);
			return;
		case 26:
			sub_07A29B(u);
			return;
		case 28:
			sub_07A2D6(u);
			return;
		case 30:
			sub_07A2EB();
			return;
		case 32:
			sub_07A314();
			return;
		case 34:
			sub_07A329(u);
			return;
		case 36:
			sub_07A357();
			return;
		case 38:
			sub_07A35F();
			return;
		case 40:
			break;
		case -12:
			continue;
		case -10:
			sub_07A075(y, u);
			return;
		case -8:
			sub_079F36(y, u);
			return;
		case -6:
			sub_07A209(y, u);
			return;
		case -4:
			sub_07A2CD(y, u);
			return;
		case -2:
			sub_07A34E(y, u);
			return;
		}
		break;
	}
	sub_07A384();
}

void sub_079EE3(void)
{
	uint16_t d = 0;

	d = 0u;
	sub_0797B7(d);
	unk_48BE = 0xFFF0u;
	unk_48CE = 0xFFF0u;
	unk_4802++;
}

void sub_079EF6(void)
{
	if (unk_485D != 0u)
		return;
	unk_4875 = 0u;
	unk_4876 = 0u;
	sub_07C931();
	unk_4802++;
}

void sub_079F08(uint16_t y, uint16_t u)
{
	uint8_t a = 0;
	uint16_t d = 0, x = 0;

	unk_480E = 0x20u;
	set_lines(unk_480E);
	x = loaded_table_041000_ADDRESS;
	a = (uint32_t)unk_4803 << 1;
	switch ((int8_t)a)
	{
	case 0:
		sub_04001E(y, u);
		return;
	case 2:
		sub_0400FF(y, u);
		return;
	case 4:
		sub_0401AE(y, u);
		return;
	case 6:
		sub_0402A5(y, u);
		return;
	case 8:
		sub_040358(y, u);
		return;
	case 10:
		sub_040471(y, u);
		return;
	case 12:
		sub_04063D(y, u);
		return;
	case 14:
		sub_040700(y, u);
		return;
	case 16:
		sub_040027(u);
		return;
	case 18:
		sub_0400AA();
		return;
	case 20:
		sub_040108();
		return;
	case 22:
		sub_04014B();
		return;
	case 24:
		sub_04019F();
		return;
	case 26:
		sub_0401B7();
		return;
	case 28:
		sub_040215();
		return;
	case 30:
		sub_040247();
		return;
	case 32:
		sub_040250();
		return;
	case 34:
		sub_040274();
		return;
	case 36:
		sub_04028D(u);
		return;
	case 38:
		sub_0402AE();
		return;
	case 40:
		sub_0402EC();
		return;
	case 42:
		sub_040300();
		return;
	case 44:
		sub_04030F();
		return;
	case 46:
		sub_040330();
		return;
	case 48:
		sub_04034B();
		return;
	case 50:
		sub_040361();
		return;
	case 52:
		sub_0403B1();
		return;
	case 54:
		sub_0403E4();
		return;
	case 56:
		sub_0403F3();
		return;
	case 58:
		sub_040414();
		return;
	case 60:
		sub_04042F(u);
		return;
	case 62:
		sub_04047A();
		return;
	case 64:
		sub_040500();
		return;
	case 66:
		sub_040517();
		return;
	case 68:
		sub_040547();
		return;
	case 70:
		sub_0405A3(u);
		return;
	case 72:
		sub_0405E4();
		return;
	case 74:
		sub_040618();
		return;
	case 76:
		sub_040646();
		return;
	case 78:
		sub_040687();
		return;
	case 80:
		sub_0406A2();
		return;
	case 82:
		sub_0406CA();
		return;
	case 84:
		sub_0406EB();
		return;
	case 86:
		sub_040709(u);
		return;
	case 88:
		sub_040758(u);
		return;
	case 90:
		d = (uint32_t)a << 8;
		sub_04079E(x, y, d);
		return;
	case 92:
	case 98:
		sub_0407CA(x);
		return;
	case 94:
		d = (uint32_t)a << 8;
		sub_0407E0(x, d);
		return;
	case 96:
		sub_0407EC(x, y);
		return;
	case 100:
		sub_04080C();
		return;
	}
}

void sub_079F17(void)
{
	uint32_t carry = 0;
	uint16_t d = 0;

	unk_48BE = 0u;
	unk_48CE = 0u;
	d = 0u;
	carry = sub_0797D3(d);
	unk_4801++;
	unk_4802 = 0u;
	unk_4803 = 0u;
	unk_4804 = 0u;
	unk_4805 = 0u;
}

void sub_079F36(uint16_t y, uint16_t u)
{
	for (;;)
	{
		switch ((int8_t)(uint8_t)((uint32_t)unk_4802 << 1))
		{
		case 0:
			sub_079F3F();
			return;
		case 2:
			sub_079F52(u);
			return;
		case 4:
			sub_07A007();
			return;
		case 6:
			sub_07A024();
			return;
		case 8:
			sub_07A07E();
			return;
		case 10:
			sub_07A12B(u);
			return;
		case 12:
			sub_07A212(u);
			return;
		case 14:
			sub_07A240();
			return;
		case 16:
			sub_07A28C(u);
			return;
		case 18:
			sub_07A29B(u);
			return;
		case 20:
			sub_07A2D6(u);
			return;
		case 22:
			sub_07A2EB();
			return;
		case 24:
			sub_07A314();
			return;
		case 26:
			sub_07A329(u);
			return;
		case 28:
			sub_07A357();
			return;
		case 30:
			sub_07A35F();
			return;
		case 32:
			break;
		case -20:
			sub_079EDA(y, u);
			return;
		case -18:
			sub_07A075(y, u);
			return;
		case -16:
			continue;
		case -14:
			sub_07A209(y, u);
			return;
		case -12:
			sub_07A2CD(y, u);
			return;
		case -10:
			sub_07A34E(y, u);
			return;
		case -8:
			sub_079EE3();
			return;
		case -6:
			sub_079EF6();
			return;
		case -4:
			sub_079F08(y, u);
			return;
		case -2:
			sub_079F17();
			return;
		}
		break;
	}
	sub_07A384();
}

void sub_079F3F(void)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0;

	d = 0u;
	carry = sub_0797D3(d);
	sub_07955F(&ignored16, &ignored16_2);
	d = 0u;
	sub_0797B7(d);
	unk_4802++;
}

void sub_079F52(uint16_t u)
{
	if (unk_485D != 0u)
		return;
	sub_079F58(u);
}

void sub_079F58(uint16_t u)
{
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, u_2 = 0;

	d = 0x10u;
	sub_07B632(d);
	d = 0u;
	sub_07B64C(d);
	unk_487E = 3u;
	d = 0x7A53u;
	sub_07BAC7(d, &ignored16, &u);
	unk_487E = 1u;
	d = 0xF07u;
	sub_07BAC7(d, &ignored16, &u);
	unk_4875 = 0u;
	unk_4876 = 0u;
	sub_07C931();
	io_write8(IO_1FB9, 0x3Fu);
	io_write8(IO_1FBA, 0x36u);
	d = 0x26u;
	sub_07C4A3(d, &ignored16_2, &ignored16, &ignored16_3);
	d = 0x126u;
	sub_07C4A3(d, &ignored16_2, &ignored16, &ignored16_3);
	unk_48C5 = 0x20u;
	unk_48D5 = 0x20u;
	io_write8(IO_1FB9, 0x13u);
	io_write8(IO_1FBA, 0x2Cu);
	unk_4F80 = 0x80u;
	unk_4F86 = 0x80u;
	unk_4F84 = 0xE9Fu;
	unk_4F8C = 0xD0u;
	unk_4F91 = 0x128u;
	d = 0u;
	sub_079311(d);
	d = 5u;
	sub_079311(d);
	d = 2u;
	sub_079311(d);
	d = 0x103u;
	sub_079311(d);
	d = 0x7304u;
	u_2 = sub_079311(d);
	unk_487E = 4u;
	d = 0x1640u;
	sub_07BAC7(d, &ignored16, &u_2);
	unk_4809 = 0u;
	unk_4802++;
}
