/**
 *    Name:        unsorted/fixed_3E.c
 *    Description: the fixed program's code, 07C000-07DFFF
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

void sub_07C016(uint16_t *p_u, uint16_t *p_d)
{
	uint16_t d = 0, u = 0;

	d = sub_07C023();
	d = sub_07C03A(d);
	d = sub_07C071(d);
	d = sub_07C0A9(d);
	*p_u = u;
	*p_d = d;
	sub_07C1E0(p_u, p_d);
}

uint16_t sub_07C023(void)
{
	uint8_t a = 0, b = 0;
	uint16_t d = 0, x = 0;
	uint8_t t1 = 0;

	x = unk_4A40_ADDRESS;
	a = 0x20u;
	do
	{
		b = mem_read8(x) & 0xDFu;
		mem_write8(x, b);
		mem_write8(x + 0x1Eu, 0u);
		x += 0x60u;
		t1 = a;
		a = t1 - 1u;
	} while (t1 != 1u);
	d = ((uint32_t)a << 8) | b;
	return d;
}

uint16_t sub_07C03A(uint16_t d)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d_2 = 0, u = 0, x = 0;
	uint8_t t1 = 0, t2 = 0;

	x = unk_4A40_ADDRESS;
	unk_48F0 = 8u;
	do
	{
		a = mem_read8(x);
		if ((a & 0x40u) != 0u)
		{
			u = unk_4F80_ADDRESS;
			unk_48F1 = 8u;
			do
			{
				a = mem_read8(u);
				if ((a & 0x40u) != 0u)
				{
					sub_07C13A(x, u, &d, &carry);
					a = (uint8_t)(d >> 8);
					if (carry)
					{
						sub_07C26D(x, u);
						a = (uint8_t)(d >> 8);
					}
				}
				u += 0x60u;
				t1 = unk_48F1;
				unk_48F1 = t1 - 1u;
			} while (t1 != 1u);
		}
		x += 0x60u;
		t2 = unk_48F0;
		unk_48F0 = t2 - 1u;
	} while (t2 != 1u);
	d_2 = (d & 0xFFu) | ((uint32_t)a << 8);
	return d_2;
}

uint16_t sub_07C071(uint16_t d)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d_2 = 0, u = 0, x = 0;
	uint8_t t1 = 0, t2 = 0;

	x = unk_4A40_ADDRESS;
	unk_48F0 = 4u;
	do
	{
		a = mem_read8(x);
		if ((a & 0x40u) != 0u)
		{
			u = unk_4D40_ADDRESS;
			unk_48F3 = 6u;
			do
			{
				a = mem_read8(u);
				if ((a & 0x40u) != 0u)
				{
					sub_07C13A(x, u, &d, &carry);
					a = (uint8_t)(d >> 8);
					if (carry)
					{
						sub_07C2D2(x, u);
						a = (uint8_t)(d >> 8);
					}
				}
				u += 0x60u;
				t1 = unk_48F3;
				unk_48F3 = t1 - 1u;
			} while (t1 != 1u);
		}
		x += 0xC0u;
		t2 = unk_48F0;
		unk_48F0 = t2 - 1u;
	} while (t2 != 1u);
	d_2 = (d & 0xFFu) | ((uint32_t)a << 8);
	return d_2;
}

uint16_t sub_07C0A9(uint16_t d)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d_2 = 0, u = 0, x = 0;
	uint8_t t1 = 0, t2 = 0;

	x = unk_4A40_ADDRESS;
	unk_48F0 = 8u;
	do
	{
		a = mem_read8(x);
		if ((a & 0x40u) != 0u)
		{
			u = 0x5280u;
			unk_48F2 = 0xAu;
			do
			{
				a = mem_read8(u);
				if ((a & 0x40u) != 0u)
				{
					sub_07C13A(x, u, &d, &carry);
					a = (uint8_t)(d >> 8);
					if (carry)
					{
						sub_07C2D2(x, u);
						a = (uint8_t)(d >> 8);
					}
				}
				u += 0x60u;
				t1 = unk_48F2;
				unk_48F2 = t1 - 1u;
			} while (t1 != 1u);
		}
		x += 0x60u;
		t2 = unk_48F0;
		unk_48F0 = t2 - 1u;
	} while (t2 != 1u);
	d_2 = (d & 0xFFu) | ((uint32_t)a << 8);
	return d_2;
}

void unused_07C10D(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, u = 0;
	uint8_t t1 = 0;

	mem_write8(x, mem_read8(x) & 0xDFu);
	mem_write8(x + 0x1Eu, 0u);
	u = 0x5280u;
	unk_48F2 = 0xAu;
	do
	{
		if ((mem_read8(u) & 0x40u) != 0u)
		{
			sub_07C13A(x, u, &ignored16, &carry);
			if (carry)
				sub_07C2D2(x, u);
		}
		u += 0x60u;
		t1 = unk_48F2;
		unk_48F2 = t1 - 1u;
	} while (t1 != 1u);
}

void sub_07C13A(uint16_t x, uint16_t u, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t a = 0, b = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t5 = 0, t11 = 0, t12 = 0, t13 = 0, t15 = 0, t20 = 0, t22 = 0, t29 = 0, t30 = 0, t31 = 0, t34 = 0, t39 = 0, t40 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t14 = 0, t16 = 0, t17 = 0, t18 = 0, t19 = 0, t21 = 0, t23 = 0, t24 = 0, t25 = 0, t26 = 0, t27 = 0, t28 = 0, t32 = 0, t33 = 0, t35 = 0, t36 = 0, t37 = 0, t38 = 0;

	t1 = mem_read8(x + 0x23u);
	t2 = (int8_t)t1;
	t3 = mem_read16(x + 0x11u);
	t4 = t2 + t3;
	unk_48F6 = t4;
	t5 = mem_read8(u + 0x23u);
	t6 = (int8_t)t5;
	t7 = mem_read16(u + 0x11u);
	t8 = t6 + t7;
	t9 = t8 - unk_48F6;
	a = (uint8_t)(t9 >> 8);
	b = (uint8_t)t9;
	if ((int16_t)t9 < 0)
	{
		t10 = 0u - (((uint32_t)a << 8) | b);
		a = (uint8_t)(t10 >> 8);
		b = (uint8_t)t10;
	}
	unk_48F6 = ((uint32_t)a << 8) | b;
	t11 = mem_read8(x + 0x20u);
	b = t11;
	t12 = mem_read8(u + 0x20u);
	carry = (uint8_t)(b + t12) < b;
	b += t12;
	if ((uint16_t)((carry << 8) | b) < unk_48F6)
	{
		carry = 0u;
		d = b;
	}
	else
	{
		t13 = mem_read8(x + 0x22u);
		t14 = (int8_t)t13;
		unk_48F4 = (uint8_t)(t14 >> 8u);
		unk_48F5 = (uint8_t)t14;
		t15 = mem_read8(x + 9u);
		if ((t15 & 0x40u) == 0u)
		{
			t16 = mem_read16(x + 0xCu);
			t17 = t16 + (((uint32_t)unk_48F4 << 8u) | unk_48F5);
			a = (uint8_t)(t17 >> 8);
			b = (uint8_t)t17;
		}
		else
		{
			t18 = mem_read16(x + 0xCu);
			t19 = t18 - (((uint32_t)unk_48F4 << 8u) | unk_48F5);
			a = (uint8_t)(t19 >> 8);
			b = (uint8_t)t19;
		}
		unk_48F6 = ((uint32_t)a << 8) | b;
		t20 = mem_read8(u + 0x22u);
		t21 = (int8_t)t20;
		unk_48F4 = (uint8_t)(t21 >> 8u);
		unk_48F5 = (uint8_t)t21;
		t22 = mem_read8(u + 9u);
		if ((t22 & 0x40u) == 0u)
		{
			t23 = mem_read16(u + 0xCu);
			t24 = t23 + (((uint32_t)unk_48F4 << 8u) | unk_48F5);
			a = (uint8_t)(t24 >> 8);
			b = (uint8_t)t24;
		}
		else
		{
			t25 = mem_read16(u + 0xCu);
			t26 = t25 - (((uint32_t)unk_48F4 << 8u) | unk_48F5);
			a = (uint8_t)(t26 >> 8);
			b = (uint8_t)t26;
		}
		t27 = (((uint32_t)a << 8) | b) - unk_48F6;
		a = (uint8_t)(t27 >> 8);
		b = (uint8_t)t27;
		if ((int16_t)t27 < 0)
		{
			t28 = 0u - (((uint32_t)a << 8) | b);
			a = (uint8_t)(t28 >> 8);
			b = (uint8_t)t28;
		}
		unk_48F6 = ((uint32_t)a << 8) | b;
		t29 = mem_read8(x + 0x1Fu);
		b = t29;
		t30 = mem_read8(u + 0x1Fu);
		carry = (uint8_t)(b + t30) < b;
		b += t30;
		if ((uint16_t)((carry << 8) | b) < unk_48F6)
		{
			carry = 0u;
			d = b;
		}
		else
		{
			t31 = mem_read8(x + 0x24u);
			t32 = mem_read16(x + 0x16u);
			t33 = t31 + t32;
			unk_48F6 = t33;
			t34 = mem_read8(u + 0x24u);
			t35 = mem_read16(u + 0x16u);
			t36 = t34 + t35;
			t37 = t36 - unk_48F6;
			a = (uint8_t)(t37 >> 8);
			b = (uint8_t)t37;
			if ((int16_t)t37 < 0)
			{
				t38 = 0u - (((uint32_t)a << 8) | b);
				a = (uint8_t)(t38 >> 8);
				b = (uint8_t)t38;
			}
			unk_48F6 = ((uint32_t)a << 8) | b;
			t39 = mem_read8(x + 0x21u);
			b = t39;
			t40 = mem_read8(u + 0x21u);
			carry = (uint8_t)(b + t40) < b;
			b += t40;
			a = carry;
			if (unk_48F6 <= (uint16_t)(((uint32_t)a << 8) | b))
			{
				carry = 1u;
				d = ((uint32_t)(uint8_t)~a << 8) | b;
			}
			else
			{
				carry = 0u;
				d = b;
			}
		}
	}
	*p_d = d;
	*p_carry = carry;
}

void sub_07C1E0(uint16_t *p_u, uint16_t *p_d)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d_2 = 0, u = 0, x = 0;
	uint8_t t1 = 0, t2 = 0;

	x = unk_4A40_ADDRESS;
	u = unk_4B00_ADDRESS;
	if ((unk_4A40 & 0x40u) != 0u)
	{
		unk_48F0 = 2u;
		do
		{
			if ((mem_read8(u) & 0x40u) != 0u)
			{
				sub_07C13A(x, u, &d, &carry);
				if (carry)
					sub_07C336(x, u);
			}
			u += 0xC0u;
			t1 = unk_48F0;
			unk_48F0 = t1 - 1u;
		} while (t1 != 1u);
	}
	x = unk_4B00_ADDRESS;
	u = unk_4BC0_ADDRESS;
	if ((unk_4B00 & 0x40u) != 0u)
	{
		unk_48F0 = 2u;
		do
		{
			if ((mem_read8(u) & 0x40u) != 0u)
			{
				sub_07C13A(x, u, &d, &carry);
				if (carry)
					sub_07C336(x, u);
			}
			u += 0xC0u;
			t2 = unk_48F0;
			unk_48F0 = t2 - 1u;
		} while (t2 != 1u);
	}
	x = unk_4BC0_ADDRESS;
	u = unk_4C80_ADDRESS;
	if ((unk_4BC0 & 0x40u) != 0u && (unk_4C80 & 0x40u) != 0u)
	{
		sub_07C13A(x, u, &d, &carry);
		if (carry)
			sub_07C336(x, u);
	}
	x = unk_4C80_ADDRESS;
	u = unk_4A40_ADDRESS;
	a = unk_4C80;
	if ((a & 0x40u) != 0u)
	{
		a = unk_4A40;
		if ((a & 0x40u) != 0u)
		{
			sub_07C13A(x, u, &d, &carry);
			a = (uint8_t)(d >> 8);
			if (carry)
			{
				sub_07C336(x, u);
				a = (uint8_t)(d >> 8);
			}
		}
	}
	d_2 = (d & 0xFFu) | ((uint32_t)a << 8);
	*p_u = u;
	*p_d = d_2;
}

void sub_07C26D(uint16_t x, uint16_t u)
{
	uint8_t a = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;

	if ((mem_read8(x) & 4u) != 0u)
	{
		sub_07C29B(x, u);
		return;
	}
	t1 = mem_read8(x + 0x1Bu);
	t2 = mem_read8(u + 0x1Cu);
	t3 = t1;
	a = t3 - t2;
	if (t3 < t2)
		a = 0u;
	mem_write8(x + 0x1Bu, a);
	t4 = mem_read8(x + 0x1Eu);
	a = t4;
	if (t4 != 0u)
	{
		t5 = mem_read8(u + 0x1Du);
		if ((int8_t)a <= (int8_t)t5)
		{
			t6 = mem_read8(u + 0x1Du);
			mem_write8(x + 0x1Eu, t6);
			mem_write16(x + 0x25u, u);
		}
		mem_write8(x, mem_read8(x) | 0x20u);
		sub_07C29B(x, u);
		return;
	}
	t6 = mem_read8(u + 0x1Du);
	mem_write8(x + 0x1Eu, t6);
	mem_write16(x + 0x25u, u);
	mem_write8(x, mem_read8(x) | 0x20u);
	sub_07C29B(x, u);
}

void sub_07C29B(uint16_t x, uint16_t u)
{
	uint8_t a = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0;

	if ((mem_read8(u) & 4u) != 0u)
		return;
	t1 = mem_read8(x + 0x1Cu);
	a = t1;
	if (t1 != 0u)
	{
		unk_48E8 = a;
		t2 = mem_read8(u + 0x1Bu);
		t3 = unk_48E8;
		t4 = t2;
		a = t4 - t3;
		if (t4 < t3)
			a = 0u;
		mem_write8(u + 0x1Bu, a);
	}
	t5 = mem_read8(u + 0x1Eu);
	a = t5;
	if (t5 != 0u)
	{
		t6 = mem_read8(x + 0x1Du);
		if ((int8_t)a <= (int8_t)t6)
		{
			t7 = mem_read8(x + 0x1Du);
			mem_write8(u + 0x1Eu, t7);
			mem_write16(u + 0x25u, x);
		}
		mem_write8(u, mem_read8(u) | 0x20u);
		return;
	}
	t7 = mem_read8(x + 0x1Du);
	mem_write8(u + 0x1Eu, t7);
	mem_write16(u + 0x25u, x);
	mem_write8(u, mem_read8(u) | 0x20u);
}

void sub_07C2D2(uint16_t x, uint16_t u)
{
	if ((mem_read8(x) & 2u) != 0u)
	{
		sub_07C29B(x, u);
		return;
	}
	sub_07C2D9(x, u);
}

void sub_07C2D9(uint16_t x, uint16_t u)
{
	uint8_t a = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0;

	if ((mem_read8(x) & 4u) == 0u)
	{
		t1 = mem_read8(x + 0x1Bu);
		t2 = mem_read8(u + 0x1Cu);
		t3 = t1;
		a = t3 - t2;
		if (t3 < t2)
			a = 0u;
		mem_write8(x + 0x1Bu, a);
		t4 = mem_read8(x + 0x1Eu);
		a = t4;
		if (t4 == 0u)
		{
			t5 = mem_read8(u + 0x1Du);
			mem_write8(x + 0x1Eu, t5);
			mem_write16(x + 0x25u, u);
		}
		else
		{
			t6 = mem_read8(u + 0x1Du);
			if ((int8_t)a <= (int8_t)t6)
			{
				t5 = mem_read8(u + 0x1Du);
				mem_write8(x + 0x1Eu, t5);
				mem_write16(x + 0x25u, u);
			}
		}
		mem_write8(x, mem_read8(x) | 0x20u);
	}
	if ((mem_read8(u) & 4u) != 0u)
		return;
	t7 = mem_read8(u + 0x1Bu);
	t8 = mem_read8(x + 0x1Cu);
	t9 = t7;
	a = t9 - t8;
	if (t9 < t8)
		a = 0u;
	mem_write8(u + 0x1Bu, a);
	t10 = mem_read8(u + 0x1Eu);
	a = t10;
	if (t10 != 0u)
	{
		t11 = mem_read8(x + 0x1Du);
		if ((int8_t)a <= (int8_t)t11)
		{
			t12 = mem_read8(x + 0x1Du);
			mem_write8(u + 0x1Eu, t12);
			mem_write16(u + 0x25u, x);
		}
		mem_write8(u, mem_read8(u) | 0x20u);
		return;
	}
	t12 = mem_read8(x + 0x1Du);
	mem_write8(u + 0x1Eu, t12);
	mem_write16(u + 0x25u, x);
	mem_write8(u, mem_read8(u) | 0x20u);
}

void sub_07C336(uint16_t x, uint16_t u)
{
	uint8_t t1 = 0, t2 = 0;

	if ((mem_read8(x) & 0x20u) == 0u && (mem_read8(u) & 0x20u) == 0u)
	{
		t1 = mem_read8(u + 0x1Du);
		mem_write8(x + 0x1Eu, t1);
		mem_write16(x + 0x25u, u);
		mem_write8(x, mem_read8(x) | 0x20u);
		t2 = mem_read8(x + 0x1Du);
		mem_write8(u + 0x1Eu, t2);
		mem_write16(u + 0x25u, x);
		mem_write8(u, mem_read8(u) | 0x20u);
	}
}

void sub_07C367(void)
{
	uint8_t a = 0;
	uint8_t stack = 0, stack_2 = 0;
	uint8_t t1 = 0, t2 = 0;

	if (unk_48A9 != 0u)
	{
		if (unk_489C != 0u && ((unk_48C1 == 0u && unk_48BE != 0u) || (((uint8_t)unk_48BE ^ (uint8_t)unk_48C1) & 8u) != 0u))
		{
			a = unk_489A | 2u;
			if (unk_48A6 == 0u)
				a |= 4u;
			unk_489A = a;
		}
		if (unk_489D != 0u && ((unk_48C8 == 0u && unk_48C5 != 0u) || (((uint8_t)unk_48C5 ^ (uint8_t)unk_48C8) & 8u) != 0u))
		{
			a = unk_489B | 2u;
			if (unk_48A6 == 0u)
				a |= 4u;
			unk_489B = a;
		}
	}
	if (unk_48AA != 0u)
	{
		if (unk_489C != 0u && ((unk_48D1 == 0u && unk_48CE != 0u) || (((uint8_t)unk_48CE ^ (uint8_t)unk_48D1) & 8u) != 0u))
		{
			a = unk_489A | 1u;
			if (unk_48A6 != 0u)
				a |= 4u;
			unk_489A = a;
		}
		if (unk_489D != 0u && ((unk_48D8 == 0u && unk_48D5 != 0u) || (((uint8_t)unk_48D5 ^ (uint8_t)unk_48D8) & 8u) != 0u))
		{
			a = unk_489B | 1u;
			if (unk_48A6 != 0u)
				a |= 4u;
			unk_489B = a;
		}
	}
	stack = 4u;
	stack_2 = 3u;
	do
	{
		if ((stack & unk_489A) != 0u)
		{
			switch ((int8_t)(uint8_t)((uint32_t)stack_2 << 1))
			{
			case 0:
			case 6:
				sub_07C46D();
				break;
			case 2:
				sub_07C489();
				break;
			case 4:
				sub_07C481();
				break;
			case 8:
			case 14:
				sub_07C477();
				break;
			case 10:
				sub_07C49A();
				break;
			case 12:
				sub_07C492();
				break;
			}
			unk_489A &= ~stack;
			if (unk_4899 == 0u)
				break;
		}
		stack = stack >> 1;
		t1 = stack_2;
		stack_2 = t1 - 1u;
	} while (t1 != 1u);
	stack = 4u;
	stack_2 = 3u;
	do
	{
		if ((stack & unk_489B) != 0u)
		{
			switch ((int8_t)(uint8_t)((uint32_t)stack_2 << 1))
			{
			case 0:
			case 6:
				sub_07C477();
				break;
			case 2:
				sub_07C49A();
				break;
			case 4:
				sub_07C492();
				break;
			case -8:
			case -2:
				sub_07C46D();
				break;
			case -6:
				sub_07C489();
				break;
			case -4:
				sub_07C481();
				break;
			}
			unk_489B &= ~stack;
			if (unk_4899 == 0u)
				break;
		}
		stack = stack >> 1;
		t2 = stack_2;
		stack_2 = t2 - 1u;
	} while (t2 != 1u);
}

void sub_07C46D(void)
{
	uint16_t d = 0, ignored16 = 0, y = 0;

	d = (uint32_t)unk_48A6 << 8;
	sub_07C573(&y, &ignored16, &d);
	sub_07C789(y, (uint8_t)d);
}

void sub_07C477(void)
{
	uint16_t d = 0, ignored16 = 0, y = 0;

	d = (uint32_t)unk_48A6 << 8;
	sub_07C618(&y, &ignored16, &d);
	sub_07C840(y, (uint8_t)d);
}

void sub_07C481(void)
{
	uint16_t d = 0, u = 0, y = 0;

	d = 0u;
	sub_07C573(&y, &u, &d);
	sub_07C744((uint8_t)d, &y, &u);
}

void sub_07C489(void)
{
	uint16_t d = 0, u = 0, y = 0;

	d = 0x100u;
	sub_07C573(&y, &u, &d);
	sub_07C744((uint8_t)d, &y, &u);
}

void sub_07C492(void)
{
	uint16_t d = 0, u = 0, y = 0;

	d = 0u;
	sub_07C618(&y, &u, &d);
	sub_07C7F2(y, u, (uint8_t)d);
}

void sub_07C49A(void)
{
	uint16_t d = 0, u = 0, y = 0;

	d = 0x100u;
	sub_07C618(&y, &u, &d);
	sub_07C7F2(y, u, (uint8_t)d);
}

void sub_07C4A3(uint16_t d, uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint8_t a = 0;
	uint16_t d_2 = 0, u = 0, x = 0, y = 0;
	uint8_t stack = 0, stack_2 = 0, saved_unk_480E = 0, stack_4 = 0, stack_5 = 0;
	uint8_t t5 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t6 = 0;

	a = (uint8_t)(d >> 8);
	stack = (uint8_t)d;
	stack_2 = a;
	x = layer_maps[a & 0x7Fu];
	saved_unk_480E = unk_480E;
	do
	{
		stack_5 = x >> 8;
		stack_4 = (uint8_t)x;
		d_2 = (uint32_t)stack_2 << 8;
		sub_07C573(&y, &u, &d_2);
		sub_07C744((uint8_t)d_2, &y, &u);
		x = ((uint32_t)stack_5 << 8) | stack_4;
		t1 = io_read16(x + 0xAu);
		t2 = mem_read16(t1);
		t3 = t2 + 8u;
		t4 = io_read16(x + 0xAu);
		mem_write16(t4, t3);
		t5 = stack;
		stack = t5 - 1u;
	} while (t5 != 1u);
	t6 = io_read16(x + 0xAu);
	mem_write16(t6, 0u);
	unk_480E = saved_unk_480E;
	set_lines(unk_480E);
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

void sub_07C4E1(uint16_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint8_t a = 0;
	uint16_t d_2 = 0, layer_map = 0, u = 0, x = 0, y = 0;
	uint8_t stack = 0, stack_2 = 0, stack_3 = 0, stack_4 = 0;
	uint8_t t5 = 0;
	uint16_t offset_x = 0, offset_y = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t6 = 0;

	a = (uint8_t)(d >> 8);
	stack = (uint8_t)d;
	stack_2 = a;
	layer_map = layer_maps[a & 0x7Fu];
	offset_x = LAYER_MAP(layer_map)->offset_x;
	mem_write16(offset_x, 0u);
	offset_y = LAYER_MAP(layer_map)->offset_y;
	mem_write16(offset_y, 0u);
	do
	{
		stack_4 = layer_map >> 8;
		stack_3 = (uint8_t)layer_map;
		d_2 = (uint32_t)stack_2 << 8;
		sub_07C573(&y, &u, &d_2);
		sub_07C744((uint8_t)d_2, &y, &u);
		x = ((uint32_t)stack_4 << 8) | stack_3;
		stack_4 = x >> 8;
		stack_3 = (uint8_t)x;
		d_2 = (uint32_t)stack_2 << 8;
		sub_07C573(&y, &u, &d_2);
		y = sub_07C789(y, (uint8_t)d_2);
		layer_map = ((uint32_t)stack_4 << 8) | stack_3;
		t1 = io_read16(layer_map + 0xAu);
		t2 = mem_read16(t1);
		t3 = t2 + 8u;
		t4 = io_read16(layer_map + 0xAu);
		mem_write16(t4, t3);
		t5 = stack;
		stack = t5 - 1u;
	} while (t5 != 1u);
	t6 = io_read16(layer_map + 0xAu);
	mem_write16(t6, 0u);
	*p_y = y;
	*p_u = u;
}

void sub_07C51C(uint16_t d)
{
	uint8_t a = 0, b = 0;
	uint16_t picture = 0, places = 0, u = 0, x = 0;
	uint8_t t7 = 0, t8 = 0;
	uint16_t tile_picture_entry = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;

	a = (uint8_t)(d >> 8);
	places = tile_pictures_ADDRESS;
	if ((int8_t)a < 0)
	{
		a = 0u;
		unk_48F4++;
	}
	tile_picture_entry = TILE_PICTURE_ENTRY(places + (a & 0x7Fu) * 0x2u);
	unk_480E = TILE_PICTURE_PLACE(tile_picture_entry)->bank;
	set_lines(unk_480E);
	t1 = tile_picture_entry + 1u;
	x = TILE_PICTURE_PLACE(t1 - 0x1u)->tiles;
	picture = TILE_PICTURE_PLACE(t1 - 0x1u)->picture;
	t2 = picture;
	unk_48F0 = TILE_PICTURE(t2)->width;
	t3 = t2 + 1u;
	unk_48F2 = TILE_PICTURE(t3 - 0x1u)->height;
	t4 = t3 + 1u;
	u = t4 + 1u;
	unk_48F3 = TILE_PICTURE(t4 - 0x2u)->colour;
	do
	{
		unk_48F1 = unk_48F0;
		b = unk_48F3;
		do
		{
			mem_write8(x - 0x2000u, b);
			t5 = u;
			u = t5 + 1u;
			a = mem_read8(t5);
			if (unk_48F4 != 0u)
				a = 1u;
			t6 = x;
			x = t6 + 1u;
			mem_write8(t6, a);
			t7 = unk_48F1;
			unk_48F1 = t7 - 1u;
		} while (t7 != 1u);
		x += (int8_t)(0x40u - unk_48F0);
		t8 = unk_48F2;
		unk_48F2 = t8 - 1u;
	} while (t8 != 1u);
}

void sub_07C573(uint16_t *p_y, uint16_t *p_u, uint16_t *p_d)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d_2 = 0, layer_map = 0, scene_area = 0, u = 0, y = 0;
	uint8_t stack = 0, stack_2 = 0;
	uint8_t t8 = 0, bank = 0, bank_2 = 0;
	uint16_t scroll_x = 0, t1 = 0, offset_x = 0, t2 = 0, scroll_y = 0, t3 = 0, t4 = 0, t5 = 0, scroll_x_2 = 0, t6 = 0, offset_x_2 = 0, t7 = 0, maps = 0, maps_high = 0, scroll_x_3 = 0, t9 = 0, offset_x_3 = 0, t10 = 0, scroll_y_2 = 0, t11 = 0, offset_y2 = 0, t12 = 0, t13 = 0, scroll_x_4 = 0, t14 = 0, offset_x_4 = 0, t15 = 0;
	uint32_t unk_48F0_halfword = 0;

	a = (uint8_t)(d >> 8);
	unk_48E8 = a;
	layer_map = layer_maps[(int8_t)((uint8_t)((uint32_t)a << 1)) / 2];
	u = LAYER_MAP(layer_map)->tiles;
	scroll_x = LAYER_MAP(layer_map)->scroll_x;
	t1 = mem_read16(scroll_x);
	offset_x = LAYER_MAP(layer_map)->offset_x;
	t2 = t1 + mem_read16(offset_x);
	carry = (t2 >> 8) & 1u;
	unk_48F0_halfword = ((uint8_t)(((uint8_t)t2 >> 1) | (carry << 7)) >> 1) >> 1;
	unk_48F0 = 0u;
	unk_48F1 = (uint8_t)unk_48F0_halfword;
	scroll_y = LAYER_MAP(layer_map)->scroll_y;
	t3 = mem_read16(scroll_y);
	b = (uint8_t)t3;
	unk_48F8 = ((uint32_t)(t3 >> 8) << 8) | b;
	t4 = 0x40u * ((((b & 0xE0u) >> 1) >> 1) >> 1);
	t5 = t4 + (((uint32_t)unk_48F0 << 8u) | unk_48F1);
	u += t5;
	scroll_x_2 = LAYER_MAP(layer_map)->scroll_x;
	t6 = mem_read16(scroll_x_2);
	offset_x_2 = LAYER_MAP(layer_map)->offset_x;
	t7 = t6 + mem_read16(offset_x_2);
	carry = (t7 >> 8) & 1u;
	unk_48FA = unk_4000_ADDRESS + (((uint8_t)(((uint8_t)t7 >> 1) | (carry << 7)) >> 1) >> 1);
	maps = LAYER_MAP(layer_map)->maps;
	y = maps;
	t8 = unk_4875;
	a = t8;
	if ((int8_t)t8 < 0)
	{
		maps_high = LAYER_MAP(layer_map)->maps_high;
		y = maps_high;
		a &= 0x7Fu;
	}
	scene_area = SCENE_AREA_LIST(y + (int8_t)((uint32_t)a << 1)) + (int8_t)(((uint32_t)unk_4876 << 1) << 1);
	bank = SCENE_AREA(scene_area)->bank;
	unk_489E = bank;
	bank_2 = SCENE_AREA(scene_area)->bank;
	unk_480E = bank_2;
	set_lines(unk_480E);
	scroll_x_3 = LAYER_MAP(layer_map)->scroll_x;
	t9 = mem_read16(scroll_x_3);
	offset_x_3 = LAYER_MAP(layer_map)->offset_x;
	t10 = t9 + mem_read16(offset_x_3);
	y = mem_read16(SCENE_AREA(scene_area)->address + (int8_t)((uint32_t)(t10 >> 8) << 1));
	b = (((((uint8_t)t10 >> 1) >> 1) >> 1) >> 1) & 0xEu;
	unk_48F0 = 0u;
	unk_48F1 = (uint8_t)b;
	stack_2 = y >> 8;
	stack = (uint8_t)y;
	unk_48FC = y + b;
	scroll_y_2 = LAYER_MAP(layer_map)->scroll_y;
	t11 = mem_read16(scroll_y_2);
	a = (uint8_t)(t11 >> 8);
	b = (uint8_t)t11;
	unk_48F8 = ((uint32_t)a << 8) | b;
	offset_y2 = LAYER_MAP(layer_map)->offset_y2;
	t12 = (((uint32_t)a << 8) | b) + mem_read16(offset_y2);
	a = (uint8_t)(t12 >> 8);
	carry = a & 1u;
	t13 = (((uint32_t)(uint8_t)((int8_t)a >> 1) << 8) | ((((uint8_t)t12 >> 1) | (carry << 7)) & 0xF0u)) + (((uint32_t)unk_48F0 << 8u) | unk_48F1);
	y = (((uint32_t)stack_2 << 8) | stack) + t13;
	scroll_x_4 = LAYER_MAP(layer_map)->scroll_x;
	t14 = mem_read16(scroll_x_4);
	offset_x_4 = LAYER_MAP(layer_map)->offset_x;
	t15 = t14 + mem_read16(offset_x_4);
	d_2 = ((uint32_t)(t15 >> 8) << 8) | (((((uint8_t)t15 >> 1) >> 1) >> 1) & 3u);
	*p_y = y;
	*p_u = u;
	*p_d = d_2;
}

void sub_07C618(uint16_t *p_y, uint16_t *p_u, uint16_t *p_d)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t address = 0, d_2 = 0, layer_map = 0, scene_area = 0, u = 0, x = 0, y = 0;
	uint8_t stack = 0, stack_2 = 0, stack_3 = 0, stack_4 = 0;
	uint8_t t4 = 0, bank = 0, bank_2 = 0;
	uint16_t scroll_x = 0, t1 = 0, scroll_y = 0, offset_y = 0, t2 = 0, t3 = 0, maps = 0, maps_high = 0, scroll_x_2 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0, t15 = 0, t16 = 0, t17 = 0, t18 = 0, t19 = 0, t20 = 0, t21 = 0;
	uint32_t unk_48F0_halfword = 0, unk_48F0_halfword_2 = 0;

	a = (uint8_t)(d >> 8);
	unk_48E8 = a;
	layer_map = layer_maps[(int8_t)((uint8_t)((uint32_t)a << 1)) / 2];
	u = LAYER_MAP(layer_map)->tiles;
	scroll_x = LAYER_MAP(layer_map)->scroll_x;
	t1 = mem_read16(scroll_x);
	a = (uint8_t)(t1 >> 8);
	b = (uint8_t)t1;
	unk_48F8 = ((uint32_t)a << 8) | b;
	carry = a & 1u;
	unk_48F0_halfword = ((uint8_t)(((b & 0xE0u) >> 1) | (carry << 7)) >> 1) >> 1;
	unk_48F0 = 0u;
	unk_48F1 = (uint8_t)unk_48F0_halfword;
	scroll_y = LAYER_MAP(layer_map)->scroll_y;
	offset_y = LAYER_MAP(layer_map)->offset_y;
	t2 = 0x40u * ((((uint8_t)((uint8_t)mem_read16(scroll_y) + mem_read16(offset_y)) >> 1) >> 1) >> 1);
	t3 = t2 + (((uint32_t)unk_48F0 << 8u) | unk_48F1);
	a = (uint8_t)(t3 >> 8);
	b = (uint8_t)t3;
	u += ((uint32_t)a << 8) | b;
	unk_48FA = unk_4000_ADDRESS + (((uint32_t)a << 8) | b);
	maps = LAYER_MAP(layer_map)->maps;
	y = maps;
	t4 = unk_4875;
	a = t4;
	if ((int8_t)t4 < 0)
	{
		maps_high = LAYER_MAP(layer_map)->maps_high;
		y = maps_high;
		a &= 0x7Fu;
	}
	scene_area = SCENE_AREA_LIST(y + (int8_t)((uint32_t)a << 1)) + (int8_t)(((uint32_t)unk_4876 << 1) << 1);
	bank = SCENE_AREA(scene_area)->bank;
	unk_489E = bank;
	bank_2 = SCENE_AREA(scene_area)->bank;
	unk_480E = bank_2;
	set_lines(unk_480E);
	address = SCENE_AREA(scene_area)->address;
	scroll_x_2 = LAYER_MAP(layer_map)->scroll_x;
	t5 = mem_read16(scroll_x_2);
	a = (uint32_t)(t5 >> 8) << 1;
	stack_2 = layer_map >> 8;
	stack = (uint8_t)layer_map;
	stack_3 = t5;
	stack_4 = a;
	unk_48FC = mem_read16(address + (int8_t)a);
	t6 = mem_read16(address + (int8_t)(a + 2u));
	t7 = t6 - unk_48FC;
	t8 = t7 - 0x10u;
	unk_48FC = t8;
	x = ((uint32_t)stack_2 << 8) | stack;
	y = mem_read16(address + (int8_t)stack_4);
	unk_48F0_halfword_2 = ((((stack_3 >> 1) >> 1) >> 1) >> 1) & 0xEu;
	unk_48F0 = 0u;
	unk_48F1 = (uint8_t)unk_48F0_halfword_2;
	t9 = io_read16(x + 4u);
	t10 = mem_read16(t9);
	t11 = io_read16(x + 0xCu);
	t12 = t10 + mem_read16(t11);
	t13 = io_read16(x + 0xEu);
	t14 = t12 + mem_read16(t13);
	a = (uint8_t)(t14 >> 8);
	carry = a & 1u;
	t15 = (((uint32_t)(uint8_t)((int8_t)a >> 1) << 8) | ((((uint8_t)t14 >> 1) | (carry << 7)) & 0xF0u)) + (((uint32_t)unk_48F0 << 8u) | unk_48F1);
	y += t15;
	t16 = io_read16(x + 4u);
	t17 = mem_read16(t16);
	t18 = io_read16(x + 0xCu);
	t19 = t17 + mem_read16(t18);
	t20 = io_read16(x + 0xEu);
	t21 = t19 + mem_read16(t20);
	d_2 = ((uint32_t)(t21 >> 8) << 8) | (((uint8_t)t21 >> 1) & 0xCu);
	*p_y = y;
	*p_u = u;
	*p_d = d_2;
}

uint16_t sub_07C6BD(uint16_t x, uint16_t u, uint16_t d)
{
	uint8_t a = 0, b = 0;
	uint16_t x_2 = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	unk_48A3 = 4u;
	t1 = x;
	b = mem_read8(t1);
	x_2 = t1 + 2u + (int8_t)(d >> 8);
	do
	{
		a = mem_read8(x_2);
		mem_write8(u - 0x2000u, b);
		mem_write8(u, a);
		x_2 += 4u;
		u += 0x40u;
		t2 = unk_48A3;
		unk_48A3 = t2 - 1u;
	} while (t2 != 1u);
	return u;
}

uint16_t sub_07C6DA(uint16_t x, uint16_t u, uint16_t d)
{
	uint8_t a = 0, b = 0;
	uint16_t x_2 = 0;
	uint8_t t4 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	unk_48A3 = 4u;
	t1 = x;
	b = mem_read8(t1);
	x_2 = t1 + 2u + (int8_t)(d >> 8);
	do
	{
		t2 = x_2;
		x_2 = t2 + 1u;
		a = mem_read8(t2);
		mem_write8(u - 0x2000u, b);
		t3 = u;
		u = t3 + 1u;
		mem_write8(t3, a);
		t4 = unk_48A3;
		unk_48A3 = t4 - 1u;
	} while (t4 != 1u);
	return u;
}

uint16_t sub_07C6F1(uint16_t x, uint16_t y, uint16_t d)
{
	uint16_t x_2 = 0;
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	unk_48A1 = d >> 8;
	t1 = mem_read8(x + 1u);
	unk_48A2 = t1;
	t2 = unk_48A2 * 0x10u;
	x_2 = block_tile_flags_ADDRESS + t2 + (int8_t)unk_48A1;
	unk_48A3 = 4u;
	do
	{
		mem_write8(y, mem_read8(x_2));
		x_2 += 4u;
		y += 0x40u;
		t3 = unk_48A3;
		unk_48A3 = t3 - 1u;
	} while (t3 != 1u);
	return y;
}

uint16_t sub_07C71F(uint16_t x, uint16_t y)
{
	uint16_t x_2 = 0;
	uint8_t t1 = 0, t5 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0;

	t1 = mem_read8(x + 1u);
	unk_48A2 = t1;
	t2 = unk_48A2 * 0x10u;
	x_2 = block_tile_flags_ADDRESS + t2 + (int8_t)unk_48A1;
	unk_48A3 = 4u;
	do
	{
		t3 = x_2;
		x_2 = t3 + 1u;
		t4 = y;
		y = t4 + 1u;
		mem_write8(t4, mem_read8(t3));
		t5 = unk_48A3;
		unk_48A3 = t5 - 1u;
	} while (t5 != 1u);
	return y;
}

void sub_07C744(uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint8_t a = 0, b = 0;
	uint16_t d_2 = 0, x = 0;
	uint8_t t4 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	unk_48F1 = d;
	unk_48F0 = 8u;
	do
	{
		unk_480E = unk_489E;
		set_lines(unk_480E);
		t1 = mem_read16(y);
		unk_48F2 = (uint8_t)(y >> 8u);
		unk_48F3 = (uint8_t)y;
		d_2 = (((t1 >> 8) & 3u) << 8) | (uint8_t)t1;
		x = sub_07C8B1(d_2);
		d_2 = (d_2 & 0xFFu) | ((uint32_t)unk_48F1 << 8);
		u = sub_07C6BD(x, u, d_2);
		t2 = unk_48F8;
		t3 = t2 + 0x20u;
		b = (uint8_t)t3;
		a = (t3 >> 8) ^ (uint8_t)(unk_48F8 >> 8u);
		if ((a & 1u) != 0u)
			u -= 0x800u;
		unk_48F8 = ((uint32_t)a << 8) | b;
		y = (((uint32_t)unk_48F2 << 8u) | unk_48F3) + 0x10u;
		t4 = unk_48F0;
		unk_48F0 = t4 - 1u;
	} while (t4 != 1u);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_07C789(uint16_t y, uint8_t d)
{
	uint8_t a = 0, b = 0;
	uint16_t d_2 = 0, x = 0, y_2 = 0;
	uint8_t t4 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	a = unk_480F | 2u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
	unk_48F1 = d;
	unk_48F0 = 8u;
	do
	{
		unk_480E = unk_489E;
		set_lines(unk_480E);
		t1 = mem_read16(y);
		unk_48F2 = (uint8_t)(y >> 8u);
		unk_48F3 = (uint8_t)y;
		d_2 = t1;
		x = sub_07C8B1(d_2);
		y_2 = unk_48FA;
		d_2 = (d_2 & 0xFFu) | ((uint32_t)unk_48F1 << 8);
		y_2 = sub_07C6F1(x, y_2, d_2);
		t2 = unk_48F8;
		t3 = t2 + 0x20u;
		b = (uint8_t)t3;
		a = (t3 >> 8) ^ (uint8_t)(unk_48F8 >> 8u);
		if ((a & 1u) != 0u)
			y_2 -= 0x800u;
		unk_48F8 = ((uint32_t)a << 8) | b;
		unk_48FA = y_2;
		y = (((uint32_t)unk_48F2 << 8u) | unk_48F3) + 0x10u;
		t4 = unk_48F0;
		unk_48F0 = t4 - 1u;
	} while (t4 != 1u);
	a = unk_480F & ~3u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
	return y;
}

void sub_07C7F2(uint16_t y, uint16_t u, uint8_t d)
{
	uint8_t a = 0;
	uint16_t d_2 = 0, x = 0, y_2 = 0;
	uint8_t stack = 0, stack_2 = 0;
	uint8_t t7 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;
	uint32_t unk_48F4_halfword = 0;

	unk_48F0 = d;
	unk_48F1 = 0xCu;
	do
	{
		unk_480E = unk_489E;
		set_lines(unk_480E);
		t1 = y;
		y_2 = t1 + 2u;
		t2 = mem_read16(t1);
		stack_2 = y_2 >> 8;
		stack = (uint8_t)y_2;
		d_2 = (((t2 >> 8) & 3u) << 8) | (uint8_t)t2;
		x = sub_07C8B1(d_2);
		d_2 = (d_2 & 0xFFu) | ((uint32_t)unk_48F0 << 8);
		u = sub_07C6DA(x, u, d_2);
		t3 = unk_48F8;
		t4 = t3 + 0x20u;
		a = (uint8_t)(t4 >> 8);
		unk_48F4_halfword = ((uint32_t)a << 8) | (uint8_t)t4;
		unk_48F4 = (uint8_t)(unk_48F4_halfword >> 8u);
		unk_48F5 = (uint8_t)unk_48F4_halfword;
		a ^= (uint8_t)(unk_48F8 >> 8u);
		if ((a & 2u) != 0u)
			u -= 0x40u;
		y = ((uint32_t)stack_2 << 8) | stack;
		if ((a & 1u) != 0u)
		{
			t5 = unk_48FC;
			y += t5;
		}
		t6 = (((uint32_t)unk_48F4 << 8u) | unk_48F5);
		unk_48F8 = t6;
		t7 = unk_48F1;
		unk_48F1 = t7 - 1u;
	} while (t7 != 1u);
}

void sub_07C840(uint16_t y, uint8_t d)
{
	uint8_t a = 0;
	uint16_t d_2 = 0, x = 0, y_2 = 0;
	uint8_t stack = 0, stack_2 = 0;
	uint8_t t7 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;
	uint32_t unk_48F4_halfword = 0;

	a = unk_480F | 2u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
	unk_48F0 = d;
	unk_48F1 = 0xBu;
	do
	{
		unk_480E = unk_489E;
		set_lines(unk_480E);
		t1 = y;
		y_2 = t1 + 2u;
		t2 = mem_read16(t1);
		stack_2 = y_2 >> 8;
		stack = (uint8_t)y_2;
		d_2 = t2;
		x = sub_07C8B1(d_2);
		y_2 = unk_48FA;
		y_2 = sub_07C71F(x, y_2);
		t3 = unk_48F8;
		t4 = t3 + 0x20u;
		a = (uint8_t)(t4 >> 8);
		unk_48F4_halfword = ((uint32_t)a << 8) | (uint8_t)t4;
		unk_48F4 = (uint8_t)(unk_48F4_halfword >> 8u);
		unk_48F5 = (uint8_t)unk_48F4_halfword;
		a ^= (uint8_t)(unk_48F8 >> 8u);
		if ((a & 2u) != 0u)
			y_2 -= 0x40u;
		unk_48FA = y_2;
		y = ((uint32_t)stack_2 << 8) | stack;
		if ((a & 1u) != 0u)
		{
			t5 = unk_48FC;
			y += t5;
		}
		t6 = (((uint32_t)unk_48F4 << 8u) | unk_48F5);
		unk_48F8 = t6;
		t7 = unk_48F1;
		unk_48F1 = t7 - 1u;
	} while (t7 != 1u);
	a = unk_480F & ~3u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
}

uint16_t sub_07C8B1(uint16_t d)
{
	unk_48FE = d;
	switch ((int8_t)(uint8_t)((uint32_t)unk_48E8 << 1))
	{
	case 0:
		return sub_07C8BD();
	case 2:
		return sub_07C8F7();
	}
	unreachable();
}

uint16_t sub_07C8BD(void)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t address = 0, scene_area = 0, scene_lists = 0, x = 0;
	uint8_t t1 = 0, bank = 0;
	uint16_t t2 = 0, t3 = 0;

	scene_lists = block_scenes_a_ADDRESS;
	t1 = unk_4875;
	a = t1;
	if ((int8_t)t1 < 0)
	{
		scene_lists = block_scenes_a_high_ADDRESS;
		a &= 0x7Fu;
	}
	scene_area = SCENE_AREA_LIST(scene_lists + (int8_t)((uint32_t)a << 1)) + (int8_t)(((uint32_t)unk_4876 << 1) << 1);
	bank = SCENE_AREA(scene_area)->bank;
	unk_480E = bank;
	set_lines(unk_480E);
	address = SCENE_AREA(scene_area)->address;
	t2 = unk_48FE;
	b = (uint8_t)t2;
	carry = (int8_t)b < 0;
	b = (uint32_t)b << 1;
	a = (uint8_t)(((uint32_t)(t2 >> 8) << 1) | carry);
	unk_48FE = ((uint32_t)a << 8) | b;
	carry = (int8_t)b < 0;
	b = (uint32_t)b << 1;
	a = (uint8_t)(((uint32_t)a << 1) | carry);
	carry = (int8_t)b < 0;
	b = (uint32_t)b << 1;
	a = (uint8_t)(((uint32_t)a << 1) | carry);
	carry = (int8_t)b < 0;
	t3 = (((uint32_t)(uint8_t)(((uint32_t)a << 1) | carry) << 8) | (uint8_t)((uint32_t)b << 1)) + unk_48FE;
	x = address + t3;
	return x;
}

uint16_t sub_07C8F7(void)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t address = 0, scene_area = 0, scene_lists = 0, x = 0;
	uint8_t t1 = 0, bank = 0;
	uint16_t t2 = 0, t3 = 0;

	scene_lists = block_scenes_b_ADDRESS;
	t1 = unk_4875;
	a = t1;
	if ((int8_t)t1 < 0)
	{
		scene_lists = block_scenes_b_high_ADDRESS;
		a &= 0x7Fu;
	}
	scene_area = SCENE_AREA_LIST(scene_lists + (int8_t)((uint32_t)a << 1)) + (int8_t)(((uint32_t)unk_4876 << 1) << 1);
	bank = SCENE_AREA(scene_area)->bank;
	unk_480E = bank;
	set_lines(unk_480E);
	address = SCENE_AREA(scene_area)->address;
	t2 = unk_48FE;
	b = (uint8_t)t2;
	carry = (int8_t)b < 0;
	b = (uint32_t)b << 1;
	a = (uint8_t)(((uint32_t)(t2 >> 8) << 1) | carry);
	unk_48FE = ((uint32_t)a << 8) | b;
	carry = (int8_t)b < 0;
	b = (uint32_t)b << 1;
	a = (uint8_t)(((uint32_t)a << 1) | carry);
	carry = (int8_t)b < 0;
	b = (uint32_t)b << 1;
	a = (uint8_t)(((uint32_t)a << 1) | carry);
	carry = (int8_t)b < 0;
	t3 = (((uint32_t)(uint8_t)(((uint32_t)a << 1) | carry) << 8) | (uint8_t)((uint32_t)b << 1)) + unk_48FE;
	x = address + t3;
	return x;
}

void sub_07C931(void)
{
	uint8_t a = 0, tile_banks = 0;
	uint16_t mode_lists = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	mode_lists = layer_modes_ADDRESS;
	t1 = unk_4875;
	a = t1;
	if ((int8_t)t1 < 0)
	{
		mode_lists = layer_modes_high_ADDRESS;
		a &= 0x7Fu;
	}
	t2 = LAYER_MODE_LIST(mode_lists + (int8_t)((uint32_t)a << 1)) + (int8_t)((uint32_t)unk_4876 << 1);
	io_write8(VIDEO_1D80, LAYER_MODE(t2)->tile_banks_01);
	tile_banks = LAYER_MODE(t2)->tile_banks_23;
	io_write8(VIDEO_1F00, tile_banks);
}

uint32_t sub_07C954(uint16_t y, uint32_t left_caller)
{
	uint16_t ignored16 = 0, ignored16_2 = 0;
	uint8_t t1 = 0;

	io_write16(VIDEO_1872, unk_4A40_ADDRESS);
	t1 = io_read8(VIDEO_1876);
	io_write8(VIDEO_1876, 0u);
	unk_480E = 0x1Bu;
	set_lines(unk_480E);
	unk_4873 = mem_read16(spawn_list_places[(int8_t)((uint8_t)((uint32_t)unk_4867 << 1)) / 2]);
	sub_07C985();
	left_caller = sub_07CB3C(y, left_caller);
	sub_07CB9F(&ignored16, &ignored16_2, &left_caller);
	sub_07CBD2(ignored16_2);
	sub_07CC05();
	return left_caller;
}

void sub_07C985(void)
{
	uint32_t carry = 0;
	uint8_t b = 0, d = 0;
	uint16_t u = 0, x = 0;
	uint8_t t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t15 = 0, t18 = 0, t24 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t12 = 0, t13 = 0, t14 = 0, t16 = 0, t17 = 0, t19 = 0, t20 = 0, t21 = 0, t22 = 0, t23 = 0;

	b = spawn_ranges[(int8_t)unk_4861];
	t1 = (uint32_t)b << 1;
	carry = 0u;
	io_write16(VIDEO_1886, t1);
	io_write8(VIDEO_1874, unk_4857);
	if (unk_488D != 0u)
	{
		unk_480E = 0x1Bu;
		set_lines(unk_480E);
	}
	else
	{
		carry = sub_07CAEA(carry);
		if (carry)
			return;
		unk_480E = 0x1Bu;
		set_lines(unk_480E);
	}
	for (;;)
	{
		x = unk_4873;
		if (mem_read8(x) == 0xFFu)
			break;
		if (unk_488D == 0u)
		{
			t2 = unk_48AC;
			t3 = t2 + 0x150u;
			if (t3 < mem_read16(x))
				break;
		}
		else
		{
			t4 = unk_48B8;
			t5 = mem_read16(x);
			t6 = t4;
			carry = t6 < t5;
			if (t6 < t5)
				break;
			t7 = io_read8(x + 4u);
			if ((t7 & 0xCu) == 0u)
			{
				carry = sub_07CAEA(carry);
				if (carry)
				{
					unk_4873 = x + 8u;
					continue;
				}
			}
		}
		t8 = io_read8(x + 6u);
		if (unk_486B < t8)
		{
			unk_4873 = x + 8u;
			continue;
		}
		t9 = io_read8(x + 4u);
		d = t9;
		sub_07CA50(d, &u, &carry);
		if (carry == 0u)
		{
			unk_4873 = x + 8u;
			continue;
		}
		t10 = io_read8(x + 7u);
		mem_write8(u + 1u, t10);
		mem_write16(u + 2u, 0u);
		t11 = io_read8(x + 5u);
		mem_write8(u + 0x30u, t11);
		t12 = mem_read16(x);
		t13 = t12 - unk_48AC;
		t14 = t13 + 0x40u;
		mem_write16(u + 0xCu, t14);
		t15 = io_read8(x + 4u);
		if ((int8_t)t15 < 0)
		{
			t16 = mem_read16(u + 0xCu);
			t17 = t16 - 0x160u;
			mem_write16(u + 0xCu, t17);
		}
		mem_write8(u + 0xEu, 0u);
		t18 = io_read8(x + 2u);
		t19 = (int8_t)t18;
		t20 = (uint32_t)t19 << 3;
		t21 = 0u - t20;
		t22 = t21 + unk_48B2;
		t23 = t22 + 0x190u;
		mem_write16(u + 0x11u, t23);
		mem_write8(u + 0x13u, 0u);
		t24 = io_read8(x + 3u);
		b = t24;
		mem_write16(u + 0x16u, b);
		mem_write8(u + 0x18u, 0u);
		mem_write16(u + 0x5Cu, b);
		mem_write8(u + 0x3Du, 0u);
		mem_write8(u + VIDEO_0031, 0u);
		unk_4873 = x + 8u;
	}
}

void sub_07CA50(uint16_t d, uint16_t *p_u, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t u = 0;

	d = ((d & 0xCu) >> 1) >> 1;
	*p_u = u;
	sub_07CA54(p_u, &d, &carry);
	*p_carry = carry;
}

void sub_07CA54(uint16_t *p_u, uint16_t *p_d, uint32_t *p_carry)
{
	uint8_t d = (uint8_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t a = 0, b = 0;
	uint16_t d_2 = 0, u = 0, x = 0;
	uint16_t stack = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0, t3 = 0;

	b = (uint8_t)d;
	a = object_list_sizes[(int8_t)b];
	u = object_lists[(int8_t)((uint8_t)((uint32_t)b << 1)) / 2];
	for (;;)
	{
		if (mem_read8(u) != 0u)
		{
			u += 0x60u;
			t1 = a;
			a = t1 - 1u;
			if (t1 != 1u)
				continue;
			carry = 0u;
			d_2 = (uint32_t)a << 8;
			break;
		}
		t2 = mem_read16(u + 0x59u);
		unk_48E8 = (uint8_t)(t2 >> 8u);
		unk_48E9 = (uint8_t)t2;
		stack = u;
		a = 0u;
		b = 0u;
		x = u;
		u = 0x30u;
		while (u != 0u)
		{
			mem_write8(x, a);
			mem_write8(x + 1u, b);
			x += 2u;
			u--;
		}
		u = stack;
		t3 = (((uint32_t)unk_48E8 << 8u) | unk_48E9);
		a = (uint8_t)(t3 >> 8);
		mem_write16(u + 0x59u, ((uint32_t)a << 8) | (uint8_t)t3);
		mem_write8(u, 4u);
		carry = 1u;
		d_2 = ((uint32_t)a << 8) | 0xFBu;
		break;
	}
	*p_u = u;
	*p_d = d_2;
	*p_carry = carry;
}

void sub_07CA8A(uint16_t x, uint16_t y, uint16_t *p_u, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t b = 0;
	uint16_t d = 0, u = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(y + 5u);
	d = t1;
	sub_07CA54(&u, &d, &carry);
	if (carry)
	{
		t2 = mem_read16(y + 6u);
		b = (uint8_t)t2;
		mem_write8(u + 0x30u, ((t2 & ~0xFFu) | b) >> 8);
		mem_write8(u + 1u, b);
		sub_07CAAB(x, y, u, &d, &carry);
	}
	*p_u = u;
	*p_d = d;
	*p_carry = carry;
}

void sub_07CAAB(uint16_t x, uint16_t y, uint16_t u, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t a = 0, b = 0;
	uint16_t d = 0;
	uint8_t t2 = 0, t3 = 0, t10 = 0;
	uint16_t t1 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t11 = 0, t12 = 0;
	uint32_t unk_48E8_halfword = 0;

	mem_write16(u + 0x40u, x);
	mem_write16(u + 2u, 0u);
	t1 = mem_read16(y);
	unk_48E8 = (uint8_t)(t1 >> 8u);
	unk_48E9 = (uint8_t)t1;
	t2 = mem_read8(x + 9u);
	if ((t2 & 0x40u) != 0u)
	{
		t3 = mem_read8(u + 9u);
		mem_write8(u + 9u, t3 | 0x40u);
		unk_48E8_halfword = 0u - (((uint32_t)unk_48E8 << 8u) | unk_48E9);
		unk_48E8 = (uint8_t)(unk_48E8_halfword >> 8u);
		unk_48E9 = (uint8_t)unk_48E8_halfword;
	}
	t4 = (((uint32_t)unk_48E8 << 8u) | unk_48E9);
	t5 = mem_read16(x + 0xCu);
	t6 = t4 + t5;
	mem_write16(u + 0xCu, t6);
	t7 = mem_read16(y + 2u);
	t8 = mem_read16(x + 0x11u);
	t9 = t7 + t8;
	mem_write16(u + 0x11u, t9);
	t10 = mem_read8(y + 4u);
	t11 = mem_read16(x + 0x16u);
	t12 = t10 + t11;
	a = (uint8_t)(t12 >> 8);
	b = (uint8_t)t12;
	mem_write16(u + 0x16u, ((uint32_t)a << 8) | b);
	mem_write8(u + 0x3Du, 0u);
	carry = 1u;
	d = ((uint32_t)(uint8_t)~a << 8) | b;
	*p_d = d;
	*p_carry = carry;
}

uint32_t sub_07CAEA(uint32_t carry)
{
	uint8_t a = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	if (unk_488D != 0u)
	{
		a = cemetery_enemy_limits_by_players[(int8_t)unk_4857];
		io_write8(VIDEO_1885, a);
		switch ((int8_t)(uint8_t)((uint32_t)unk_4867 << 1))
		{
		case 0:
		case 2:
		case 6:
		case 10:
		case 12:
		case 16:
		case 18:
		case 22:
			d = (uint32_t)a << 8;
			return sub_07CB2B(d);
		case 4:
		case 8:
		case 14:
		case 20:
			d = (uint32_t)a << 8;
			return sub_07CB37(d);
		}
	}
	t1 = io_read8(VIDEO_189C);
	if (t1 != 0u)
	{
		unk_48A7 = 1u;
		unk_48A8 = 1u;
		return carry;
	}
	io_write8(VIDEO_1885, enemy_limits_by_difficulty[(int8_t)unk_486B]);
	t2 = io_read8(VIDEO_1885);
	a = extra_enemies_by_scene[(int8_t)unk_4867] + t2;
	io_write8(VIDEO_1885, a);
	switch ((int8_t)(uint8_t)((uint32_t)unk_4867 << 1))
	{
	case 0:
	case 2:
	case 6:
	case 10:
	case 12:
	case 16:
	case 18:
	case 22:
		d = (uint32_t)a << 8;
		return sub_07CB2B(d);
	case 4:
	case 8:
	case 14:
	case 20:
		d = (uint32_t)a << 8;
		return sub_07CB37(d);
	}
	unreachable();
}

uint32_t sub_07CB2B(uint16_t d)
{
	uint32_t carry = 0;
	uint8_t b = 0;
	uint8_t t1 = 0, t2 = 0;

	b = 0u;
	t1 = io_read8(VIDEO_1876);
	t2 = d >> 8;
	carry = t2 < t1;
	if (t2 < t1)
		b--;
	unk_48A7 = b;
	return carry;
}

uint32_t sub_07CB37(uint16_t d)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	t1 = io_read8(VIDEO_1876);
	carry = d >> 8 < t1;
	return carry;
}

uint32_t sub_07CB3C(uint16_t y, uint32_t left_caller)
{
	uint8_t a = 0, d = 0;
	uint16_t u = 0, x = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0;
	uint16_t t5 = 0;

	unk_480E = 0x1Au;
	set_lines(unk_480E);
	sub_034009();
	sub_07CC5A();
	t1 = io_read8(VIDEO_1876);
	io_write8(VIDEO_1880, t1);
	t2 = io_read8(VIDEO_1876);
	io_write8(VIDEO_1876, 0u);
	t3 = io_read8(VIDEO_1883);
	io_write8(VIDEO_1883, 0u);
	t4 = io_read8(VIDEO_1878);
	io_write8(VIDEO_1878, 0u);
	x = unk_4F80_ADDRESS;
	do
	{
		if (mem_read8(x) > 1u)
		{
			t5 = mem_read16(x + 1u);
			a = (uint8_t)(t5 >> 8);
			stack = t5;
			unk_480E = enemy_banks[(int8_t)a];
			set_lines(unk_480E);
			u = loaded_table_07F2EC_ADDRESS;
			a = (uint32_t)a << 1;
			d = stack;
			switch ((int8_t)a)
			{
			case 0:
				sub_07D40A(x, d, &y, &left_caller);
				break;
			case 2:
				sub_028072(x, d, &y, &left_caller);
				break;
			case 4:
				sub_02E009(x, d, &y, &left_caller);
				break;
			case 6:
				sub_02801B(x, d, &y, &u, &left_caller);
				break;
			case 8:
				sub_07CC8C();
				break;
			case 10:
				sub_026000(&x, &y);
				break;
			case 12:
				sub_028054(x, d, &y, &left_caller);
				break;
			case 14:
				sub_02E015(x, d, &y, &left_caller);
				break;
			case 16:
				sub_028066(x, d, &y, &left_caller);
				break;
			case 18:
				sub_02E021(x, d, &y, &left_caller);
				break;
			case 20:
				sub_028075(x, d, &y, &left_caller);
				break;
			case 22:
				y = sub_03C00C(x, y);
				break;
			case 24:
				sub_02801E(x, d, &y, &u, &left_caller);
				break;
			case 26:
				sub_028078(x, d, &y, &left_caller);
				break;
			case 28:
				sub_02A051(x, d, &y, &left_caller);
				break;
			case 30:
				sub_02A003(x, d, &y, &left_caller);
				break;
			case 32:
				sub_030009(x, d, &y, &left_caller);
				break;
			case 34:
				y = sub_03000C(x, y, d);
				break;
			case 36:
				sub_02A015(x, d, &y, &left_caller);
				break;
			case 38:
				sub_02A033(x, d, &y, &left_caller);
				break;
			case 40:
				sub_03003C(x, d, &y, &left_caller);
				break;
			case 42:
				sub_028045(x, d, &y, &left_caller);
				break;
			case 44:
				sub_028048(x, d, &y, &left_caller);
				break;
			case 46:
				sub_02804E(x, d, &y, &left_caller);
				break;
			case 48:
				sub_028051(x, d, &y, &left_caller);
				break;
			case 50:
				y = sub_03C000(x, u);
				break;
			case 52:
				sub_02E036(x, d, &y, &left_caller);
				break;
			case 54:
				sub_02806C(x, d, &y, &left_caller);
				break;
			case 56:
				sub_028021(x, d, &y, &left_caller);
				break;
			case 58:
				sub_028057(x, d, &y, &left_caller);
				break;
			case 60:
				sub_02805A(x, d, &y, &left_caller);
				break;
			case 62:
				y = sub_020006(x, y, d);
				break;
			case 64:
				sub_03C009(u, &x, &y);
				break;
			case 66:
				y = sub_030006(x, y, d);
				break;
			case 68:
				y = sub_030000(x, y, d);
				break;
			case 70:
				y = sub_030021(x, y, d);
				break;
			case 72:
				y = sub_030027(x, y, d);
				break;
			case 74:
				sub_028027(x, d, &y, &u, &left_caller);
				break;
			case 76:
				sub_02802A(x, d, &y, &u, &left_caller);
				break;
			case 78:
				sub_028069(x, d, &y, &left_caller);
				break;
			case 80:
				sub_02A01E(x, d, &y, &left_caller);
				break;
			case 82:
				sub_0280A2(x, d, &y, &left_caller);
				break;
			case 84:
				sub_0280A5(x, d, &y, &left_caller);
				break;
			case 86:
				sub_028024(x, d, &y, &u, &left_caller);
				break;
			case 88:
				sub_02A021(x, d, &y, &left_caller);
				break;
			case 90:
				sub_02A024(x, d, &y, &left_caller);
				break;
			case 92:
				sub_028015(x, d, &y, &u, &left_caller);
				break;
			case 94:
				sub_030030(x, d, &y, &left_caller);
				break;
			case 96:
				sub_032000(x, d, &y, &left_caller);
				break;
			case 98:
				sub_030036(x, d, &y, &left_caller);
				break;
			case 100:
				sub_032012(x, d, &y, &left_caller);
				break;
			case 102:
				sub_032033(x, d, &y, &left_caller);
				break;
			case 104:
				sub_02806F(x, d, &y, &left_caller);
				break;
			case 106:
				sub_02A018(x, d, &y, &left_caller);
				break;
			case 108:
				sub_02A030(x, d, &y, &left_caller);
				break;
			case 110:
				y = sub_022009(x, y);
				break;
			case 112:
				sub_02A03F(x, d, &y, &left_caller);
				break;
			case 114:
				sub_02803F(x, d, &y, &u, &left_caller);
				break;
			case 116:
				sub_02A048(x, d, &y, &left_caller);
				break;
			case 118:
				sub_028000(x, d, &y, &left_caller);
				break;
			case 120:
				sub_02802D(x, d, &y, &u, &left_caller);
				break;
			case 122:
				sub_032048(x, d, &y, &left_caller);
				break;
			case 124:
				y = sub_03C018(x);
				break;
			case 126:
				sub_02809F(x, d, &y, &left_caller);
				break;
			case -54:
				y = sub_02E06F(x, y, d);
				break;
			case -52:
				sub_02A07E(x, d, &y, &left_caller);
				break;
			case -50:
				sub_02807B(x, d, &y, &left_caller);
				break;
			case -48:
				sub_03C015(x, &y, &u);
				break;
			case -46:
				sub_02A006(x, d, &y, &u);
				break;
			case -44:
				sub_03A024(x);
				break;
			case -42:
				sub_028063(x, d, &y, &left_caller);
				break;
			case -40:
				y = sub_03A009(x, y);
				break;
			case -38:
				sub_028060(x, d, &y, &left_caller);
				break;
			case -36:
				sub_02803C(x, d, &y, &left_caller);
				break;
			case -34:
				sub_02A054(x, d, &y, &left_caller);
				break;
			case -32:
				sub_02A057(x, d, &y, &left_caller);
				break;
			case -30:
				sub_028039(x, d, &y, &u, &left_caller);
				break;
			case -28:
				y = sub_03004E(x, y, d);
				break;
			case -26:
				sub_028036(x, d, &y, &left_caller);
				break;
			case -24:
				sub_0280A8(x, d, &y, &left_caller);
				break;
			case -22:
				sub_030048(x, d, &y, &left_caller);
				break;
			case -20:
				y = sub_03A000(x, u);
				break;
			case -18:
				y = sub_034018(x, y, d);
				break;
			case -16:
				y = sub_03400F(x, y, d);
				break;
			case -14:
				y = sub_03C01B(x, y);
				break;
			case -12:
				sub_02A04E(x, d, &y, &left_caller);
				break;
			case -10:
				sub_02A000(x, d, &y, &left_caller);
				break;
			case -8:
				y = sub_03204E(x, y, d);
				break;
			case -6:
				sub_03204B(x, d, &y, &left_caller);
				break;
			case -4:
				sub_034015(x, d, &y, &u);
				break;
			case -2:
				sub_034012(x, d, &y, &u);
				break;
			}
			t6 = mem_read8(x + 0x42u);
			if ((int8_t)t6 >= 0)
			{
				t7 = io_read8(VIDEO_1876);
				io_write8(VIDEO_1876, t7 + 1u);
			}
			t8 = mem_read8(x + 0x57u);
			if (t8 == 0u)
			{
				t9 = io_read8(VIDEO_1883);
				io_write8(VIDEO_1883, t9 + 1u);
			}
		}
		x += 0x60u;
	} while (x < 0x5280u);
	return left_caller;
}

void sub_07CB9F(uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint8_t a = 0, d = 0;
	uint16_t x = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	t1 = io_read8(VIDEO_1879);
	io_write8(VIDEO_1879, 0u);
	x = 0x5280u;
	do
	{
		if (mem_read8(x) > 1u)
		{
			t2 = mem_read16(x + 1u);
			a = (uint8_t)(t2 >> 8);
			stack = t2;
			unk_480E = object_list_1_banks[(int8_t)a];
			set_lines(unk_480E);
			u = loaded_table_07F40D_ADDRESS;
			carry = (int8_t)a < 0;
			a = (uint32_t)a << 1;
			d = stack;
			switch ((int8_t)a)
			{
			case 0:
				sub_02C00F(x, carry, &y, &u, p_left_caller);
				break;
			case 2:
				sub_02C012(x, carry, &y, &u);
				break;
			case 4:
				sub_02E02A(x, d, &y, &u);
				break;
			case 6:
				sub_02C04B(x, d, &y, &u);
				break;
			case 8:
				sub_07E18F(x, d, &y, &u);
				break;
			case 10:
				sub_02C015(x, d, &y, &u);
				break;
			case 12:
				sub_02C01B(x, d, &y, &u);
				break;
			case 14:
				sub_02A072(x, d, &y, &u);
				break;
			case 16:
				sub_02C021(x, d, &y, &u);
				break;
			case 18:
				sub_02C024(x, d, &y, &u);
				break;
			case 20:
				sub_02E033();
				break;
			case 22:
				sub_03601B(x, d, &y, &u);
				break;
			case 24:
				sub_036018(x, d, &y, &u);
				break;
			case 26:
				sub_02804B(x, d, &y, &u);
				break;
			case 28:
				y = sub_03C00C(x, y);
				break;
			case 30:
				sub_02E039(x, d, &y, &u);
				break;
			case 34:
				sub_02C000(x, d, &y, &u);
				break;
			case 36:
				sub_036024(x, d, &y, &u);
				break;
			case 38:
				sub_02C036();
				break;
			case 40:
				sub_02C039();
				break;
			case 42:
				sub_02E030(x, d, &y, &u);
				break;
			case 44:
				sub_02C03F(x, d, &y, &u);
				break;
			case 46:
				sub_02C042(x, d, &y, &u);
				break;
			case 48:
				sub_03000F(x, d, &y, &u);
				break;
			case 50:
				sub_030012();
				break;
			case 52:
				sub_02C003(x, d, &y, &u);
				break;
			case 54:
				sub_02C009(x, d, &y, &u);
				break;
			case 56:
				sub_02E048(x, d, &y, &u);
				break;
			case 58:
				sub_030018(x, d, &y, &u);
				break;
			case 60:
				sub_03E021();
				break;
			case 62:
				sub_02C045(x, d, &y, &u);
				break;
			case 64:
				sub_03001B(x, d, &y, &u);
				break;
			case 66:
				sub_02C048(x, d, &y, &u, p_left_caller);
				break;
			case 68:
				sub_03001E(x, d, &y, &u);
				break;
			case 70:
				sub_02C018(x, d, &y, &u);
				break;
			case 72:
				sub_02E012();
				break;
			case 74:
				sub_02E000(x, d, &y, &u);
				break;
			case 76:
				sub_02C027(x, d, &y, &u);
				break;
			case 78:
				sub_02E003(x, d, &y, &u);
				break;
			case 80:
				sub_02C006(x, d, &y, &u);
				break;
			case 82:
				sub_02E018(x, d, &y, &u);
				break;
			case 84:
				sub_036021(x, d, &y, &u);
				break;
			case 86:
				sub_02C04E(x, d, &y, &u);
				break;
			case 88:
				sub_02C051(x, d, &y, &u);
				break;
			case 90:
				sub_02C054(x, d, &y, &u);
				break;
			case 92:
				sub_02C03C(x, d, &y, &u);
				break;
			case 94:
				sub_02C05A(x, d, &y, &u);
				break;
			case 96:
				sub_02E051(x, d, &y, &u);
				break;
			case 98:
				sub_026003(&x, &y, &u);
				break;
			case 100:
				sub_02E072(x, d, &y, &u);
				break;
			case 102:
				sub_032027(x, d, &y, &u);
				break;
			case 104:
				sub_02A01B(x, d, &y, &u);
				break;
			case 106:
				sub_03C012(x, &y, &u);
				break;
			case 108:
				sub_03C01E(x);
				break;
			case 110:
				sub_02200C(x, &y, &u);
				break;
			case 112:
				sub_03601E(x, d, &y, &u);
				break;
			case 114:
				sub_032036(d, &x, &y, &u, p_left_caller);
				break;
			case 116:
				sub_032039(x, d, &y, &u);
				break;
			case 118:
				sub_02E01B(x, d, &y, &u, p_left_caller);
				break;
			case 120:
				sub_02E054(x, d, &y, &u);
				break;
			case 122:
				sub_02A036(x, d, &y, &u);
				break;
			case 124:
				sub_02A039(x, d, &y, &u);
				break;
			case 126:
				sub_02E057(x, d, &y, &u);
				break;
			case -70:
				sub_02A084(x, d, &y, &u);
				break;
			case -68:
				sub_03205A(x, d, &y, &u);
				break;
			case -66:
				sub_02C02D(x, d, &y, &u, p_left_caller);
				break;
			case -64:
				sub_02C01E(x, carry, &y, &u, p_left_caller);
				break;
			case -62:
				sub_02C02A(x, d, &y, &u, p_left_caller);
				break;
			case -60:
				sub_03A027(x, d, &y, &u);
				break;
			case -58:
				sub_03400C(x, d, &y, &u);
				break;
			case -56:
				sub_03A012(x, d, &y, &u);
				break;
			case -54:
				sub_03A015(x, d, &y, &u);
				break;
			case -52:
				sub_03A018(x, d, &y, &u);
				break;
			case -50:
				sub_03A01B(x, d, &y, &u);
				break;
			case -48:
				sub_02E06C(x, d, &y, &u);
				break;
			case -46:
				sub_03C015(x, &y, &u);
				break;
			case -44:
				sub_03401E(x, d, &y, &u);
				break;
			case -42:
				sub_02A06C(x, d, &y, &u);
				break;
			case -40:
				sub_02A006(x, d, &y, &u);
				break;
			case -38:
				u = sub_026030(x);
				break;
			case -36:
				sub_02A069(x, d, &y, &u);
				break;
			case -34:
				sub_02A066(x, d, &y, &u);
				break;
			case -32:
				sub_02A063(x, d, &y, &u);
				break;
			case -30:
				sub_03A006(x, &y, &u);
				break;
			case -28:
				sub_02C05D(x, d, &y, &u);
				break;
			case -26:
				sub_03205D(x, d, &y, &u);
				break;
			case -24:
				sub_07CC8C();
				break;
			case -22:
				sub_032045(x, d, &y, &u);
				break;
			case -20:
				sub_032042(x, d, &y, &u);
				break;
			case -18:
				sub_02A045(x, d, &y, &u);
				break;
			case -16:
				sub_02A042(x, d, &y, &u);
				break;
			case -14:
				sub_02E060(x, d, &y, &u);
				break;
			case -12:
				sub_02E05D(x, d, &y, &u);
				break;
			case -10:
				sub_03203F(x, d, &y, &u);
				break;
			case -8:
				sub_02E05A(x, d, &y, &u);
				break;
			case -6:
				sub_02A03C(x, d, &y, &u);
				break;
			case -4:
				sub_034015(x, d, &y, &u);
				break;
			case -2:
				sub_034012(x, d, &y, &u);
				break;
			}
			t3 = io_read8(VIDEO_1879);
			io_write8(VIDEO_1879, t3 + 1u);
		}
		x += 0x60u;
	} while (x < 0x5640u);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_07CBD2(uint16_t u)
{
	uint8_t a = 0, d = 0;
	uint16_t ignored16 = 0, x = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	t1 = io_read8(VIDEO_187A);
	io_write8(VIDEO_187A, 0u);
	x = unk_4D40_ADDRESS;
	do
	{
		if (mem_read8(x) > 1u)
		{
			t2 = mem_read16(x + 1u);
			a = (uint8_t)(t2 >> 8);
			stack = t2;
			unk_480E = child_object_banks[(int8_t)a];
			set_lines(unk_480E);
			u = loaded_table_07F4F4_ADDRESS;
			a = (uint32_t)a << 1;
			d = stack;
			switch ((int8_t)a)
			{
			case 0:
			case 68:
			case 70:
			case 72:
				sub_07CC8C();
				break;
			case 2:
				sub_03C00C(x, ignored16);
				break;
			case 4:
				u = sub_02A075(x, ignored16, d);
				break;
			case 6:
				sub_02A078();
				break;
			case 8:
				sub_02A07B();
				break;
			case 10:
				sub_03C003(x, ignored16);
				break;
			case 12:
				u = sub_03C006(x, ignored16, u);
				break;
			case 14:
				sub_03E024(ignored16, &x, &u);
				break;
			case 16:
				u = sub_03C00F(x, u);
				break;
			case 18:
				u = sub_02E027(x, ignored16, d);
				break;
			case 20:
				u = sub_02E00F(x, ignored16, d);
				break;
			case 22:
				u = sub_02E045(x, ignored16, d);
				break;
			case 24:
				sub_03E018(ignored16, &x, &u);
				break;
			case 26:
				u = sub_02C00C(x, ignored16, d);
				break;
			case 28:
				u = sub_02E006(x, ignored16, d);
				break;
			case 30:
				sub_03E006(ignored16, &x, &u);
				break;
			case 32:
				sub_026003(&x, &ignored16, &u);
				break;
			case 34:
				u = sub_03002A(x, ignored16, d);
				break;
			case 36:
				u = sub_02E04E(x, ignored16, d);
				break;
			case 38:
				sub_07E18F(x, d, &ignored16, &u);
				break;
			case 40:
				sub_03E030(ignored16, &x, &u);
				break;
			case 42:
				sub_03E033(ignored16, &x, &u);
				break;
			case 44:
				u = sub_028018(x, ignored16, d);
				break;
			case 46:
				u = sub_032018(x, ignored16, d);
				break;
			case 48:
				u = sub_02E04B(x, ignored16, d);
				break;
			case 50:
				u = sub_032021(x, ignored16, d);
				break;
			case 52:
				u = sub_02E063(x, ignored16, d);
				break;
			case 56:
				u = sub_03A003(x, u);
				break;
			case 58:
				sub_03A006(x, &ignored16, &u);
				break;
			case 60:
				u = sub_02E03C(x, (uint8_t)ignored16, d);
				break;
			case 62:
				u = sub_026033(x);
				break;
			case 64:
				u = sub_03401B(x, ignored16, d);
				break;
			case 66:
				u = sub_03A00F(x, ignored16, d);
				break;
			case 74:
				u = sub_03A021(x, ignored16, d);
				break;
			case 76:
				u = sub_03A01E(x, ignored16);
				break;
			case 78:
				u = sub_02A06F(x, ignored16, d);
				break;
			case 80:
				u = sub_030051(x, ignored16, d);
				break;
			case 82:
				u = sub_02000F(x);
				break;
			case 84:
				sub_03C015(x, &ignored16, &u);
				break;
			case -4:
				sub_034015(x, d, &ignored16, &u);
				break;
			case -2:
				sub_034012(x, d, &ignored16, &u);
				break;
			}
			t3 = io_read8(VIDEO_187A);
			io_write8(VIDEO_187A, t3 + 1u);
		}
		x += 0x60u;
	} while (x < unk_4F80_ADDRESS);
	return u;
}

void sub_07CC05(void)
{
	uint8_t a = 0, d = 0;
	uint16_t x = 0;
	uint8_t stack = 0;
	uint16_t t1 = 0;

	x = 0x5640u;
	do
	{
		if (mem_read8(x) > 1u)
		{
			t1 = mem_read16(x + 1u);
			a = (uint8_t)(t1 >> 8);
			stack = t1;
			unk_480E = stage_event_banks[(int8_t)a];
			set_lines(unk_480E);
			a = (uint32_t)a << 1;
			d = stack;
			switch ((int8_t)a)
			{
			case 0:
				sub_02A05A(x, d);
				break;
			case 2:
				sub_02A05D(x, d);
				break;
			case 4:
				sub_034006();
				break;
			case 6:
				x = sub_03E015(x);
				break;
			case 8:
				sub_02A060(x, d);
				break;
			}
		}
		x += 0x60u;
	} while (x < 0x56A0u);
}

void unused_07CC30(void)
{
	io_write8(VIDEO_1874, unk_4857);
}

void sub_07CC38(void)
{
	uint8_t a = 0, b = 0;
	uint16_t u = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0, t2 = 0;

	b = 4u;
	stack = 0x7Fu;
	u = unk_4A40_ADDRESS;
	do
	{
		if (mem_read8(u) != 0u)
		{
			t1 = mem_read8(u + 0x45u);
			a = t1;
			if (a < stack)
			{
				stack = a;
				io_write16(VIDEO_1870, u);
			}
		}
		u += 0xC0u;
		t2 = b;
		b = t2 - 1u;
	} while (t2 != 1u);
}

void sub_07CC5A(void)
{
	uint8_t a = 0, b = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = io_read8(VIDEO_1876);
	if (t1 >= 0x10u)
	{
		io_write8(VIDEO_1877, 4u);
		return;
	}
	t2 = io_read8(VIDEO_1876);
	b = t2;
	t3 = io_read8(VIDEO_1874);
	a = t3;
	if (t3 == 0u)
		return;
	t4 = a;
	a = t4 - 1u;
	if (t4 != 1u)
	{
		io_write8(VIDEO_1877, TABLE8(attackers_per_player, (uint16_t)((int8_t)(((((a - 1u) << 1) << 1) << 1) << 1) + (int8_t)b)));
		return;
	}
	io_write8(VIDEO_1877, b);
}

void sub_07CC8C(void)
{
}

void sub_07CC8E(uint16_t x, uint16_t d)
{
	uint16_t d_2 = 0, u = 0;
	uint16_t stack = 0;

	stack = d;
	sub_07CCA0(&u, &d);
	mem_write16(x + 0x14u, d);
	d_2 = (stack & 0xFFu) | ((uint32_t)(uint8_t)((stack >> 8) + 0x40u) << 8);
	d_2 = sub_07CCA3(u, d_2);
	mem_write16(x + 0xFu, d_2);
}

void sub_07CCA0(uint16_t *p_u, uint16_t *p_d)
{
	uint16_t d = (uint16_t)*p_d;
	uint16_t u = 0;

	u = sines_ADDRESS;
	d = sub_07CCA3(u, d);
	*p_u = u;
	*p_d = d;
}

uint16_t sub_07CCA3(uint16_t u, uint16_t d)
{
	uint8_t a = 0, d_2 = 0;
	uint16_t d_3 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	a = (uint8_t)(d >> 8);
	unk_48EC = a;
	a &= 0x7Fu;
	if ((a & 0x40u) != 0u)
		a = 0u - ((a & 0x3Fu) - 0x40u);
	a = mem_read8(u + (int8_t)a);
	if ((uint8_t)d != 0u)
	{
		t1 = (uint32_t)a * (uint8_t)d;
		d = t1;
		a = (uint8_t)(t1 >> 8);
	}
	t2 = (uint16_t)(((uint32_t)a << 8) | (d & 0xFFu)) >> 4;
	d_2 = (uint8_t)t2;
	a = (uint8_t)(t2 >> 8);
	if ((int8_t)unk_48EC < 0)
	{
		t3 = 0u - (((uint32_t)a << 8) | (d_2 & 0xFFu));
		d_2 = (uint8_t)t3;
		a = (uint8_t)(t3 >> 8);
	}
	d_3 = (d_2 & 0xFFu) | ((uint32_t)a << 8);
	return d_3;
}

void sub_07CCC0(uint16_t *p_u, uint16_t *p_d)
{
	uint16_t d = (uint16_t)*p_d;
	uint16_t u = 0;

	u = sines_20_ADDRESS;
	d = sub_07CCC3(u, d);
	*p_u = u;
	*p_d = d;
}

uint16_t sub_07CCC3(uint16_t u, uint16_t d)
{
	uint8_t a = 0, b = 0;
	uint16_t d_2 = 0;
	uint16_t t1 = 0, t2 = 0;

	a = (uint8_t)(d >> 8);
	unk_48EC = a;
	a &= 0x7Fu;
	if ((a & 0x40u) != 0u)
		a = 0u - ((a & 0x3Fu) - 0x40u);
	t1 = (uint32_t)mem_read8(u + (int8_t)a) << 4;
	a = (uint8_t)(t1 >> 8);
	b = (uint8_t)t1;
	if ((int8_t)unk_48EC < 0)
	{
		t2 = 0u - (((uint32_t)a << 8) | b);
		a = (uint8_t)(t2 >> 8);
		b = (uint8_t)t2;
	}
	d_2 = ((uint32_t)a << 8) | b;
	return d_2;
}

uint16_t sub_07CCDD(uint16_t x, uint16_t u, uint16_t d)
{
	uint8_t a = 0, b = 0;
	uint16_t d_2 = 0, u_2 = 0;
	uint8_t stack = 0, stack_2 = 0, stack_4 = 0;

	stack_2 = u >> 8;
	stack = (uint8_t)u;
	stack_4 = d >> 8;
	sub_07CCC0(&u_2, &d);
	a = (uint8_t)(d >> 8);
	b = (uint8_t)d;
	mem_write16(x + 0x14u, ((uint32_t)a << 8) | b);
	d_2 = (d & 0xFFu) | ((uint32_t)(uint8_t)(stack_4 + 0x40u) << 8);
	d_2 = sub_07CCC3(u_2, d_2);
	a = (uint8_t)(d_2 >> 8);
	b = (uint8_t)d_2;
	mem_write16(x + 0xFu, ((uint32_t)a << 8) | b);
	u_2 = ((uint32_t)stack_2 << 8) | stack;
	return u_2;
}

uint16_t sub_07CCF0(uint16_t x, uint16_t u, uint8_t d)
{
	uint8_t a = 0, b = 0;
	uint16_t d_2 = 0;
	uint8_t stack = 0;
	uint8_t t13 = 0, t14 = 0, t15 = 0, t16 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0;
	uint32_t unk_48EA_halfword = 0, unk_48EA_halfword_2 = 0, unk_48E8_halfword = 0, unk_48E8_halfword_2 = 0, unk_48E8_halfword_3 = 0, unk_48EA_halfword_3 = 0, unk_48EA_halfword_4 = 0;

	b = (uint8_t)d;
	stack = b;
	t1 = (int8_t)b;
	t2 = mem_read16(u + 0xCu);
	t3 = t1 + t2;
	t4 = mem_read16(x + 0xCu);
	t5 = t3 - t4;
	a = (uint8_t)(t5 >> 8);
	b = (uint8_t)t5;
	unk_48EC = a;
	t6 = ((uint32_t)a << 8) | b;
	t7 = t6 >> 15 ? 0u - t6 : t6;
	unk_48E8 = (uint8_t)(t7 >> 8u);
	unk_48E9 = (uint8_t)t7;
	t8 = mem_read16(u + 0x11u);
	t9 = mem_read16(x + 0x11u);
	t10 = t8 - t9;
	a = (uint8_t)(t10 >> 8);
	unk_48ED = a;
	t11 = ((uint32_t)a << 8) | (uint8_t)t10;
	t12 = t11 >> 15 ? 0u - t11 : t11;
	a = (uint8_t)(t12 >> 8);
	b = (uint8_t)t12;
	unk_48EA_halfword = ((uint32_t)a << 8) | b;
	unk_48EA = (uint8_t)(unk_48EA_halfword >> 8u);
	unk_48EB = (uint8_t)unk_48EA_halfword;
	if ((((uint32_t)unk_48E8 << 8u) | unk_48E9) < (uint16_t)(((uint32_t)a << 8) | b))
	{
		a = 6u;
		while (unk_48EA != 0u)
		{
			unk_48EA_halfword_2 = (((uint32_t)unk_48EA << 8u) | unk_48EB) >> 1;
			unk_48EA = (uint8_t)(unk_48EA_halfword_2 >> 8u);
			unk_48EB = (uint8_t)unk_48EA_halfword_2;
			a--;
		}
		if (a != 0u)
		{
			if ((int8_t)a >= 0)
			{
				do
				{
					unk_48E8_halfword = (uint32_t)(((uint32_t)unk_48E8 << 8u) | unk_48E9) << 1;
					unk_48E8 = (uint8_t)(unk_48E8_halfword >> 8u);
					unk_48E9 = (uint8_t)unk_48E8_halfword;
					t13 = a;
					a = t13 - 1u;
				} while (t13 != 1u);
			}
			else
			{
				do
				{
					unk_48E8_halfword_2 = (((uint32_t)unk_48E8 << 8u) | unk_48E9) >> 1;
					unk_48E8 = (uint8_t)(unk_48E8_halfword_2 >> 8u);
					unk_48E9 = (uint8_t)unk_48E8_halfword_2;
					t14 = a + 1u;
					a = t14;
				} while (t14 != 0u);
			}
		}
		a = 0u - (arctangents[konami_divx((((uint32_t)unk_48E8 << 8u) | unk_48E9), unk_48EB)] - 0x40u);
	}
	else
	{
		a = 6u;
		while (unk_48E8 != 0u)
		{
			unk_48E8_halfword_3 = (((uint32_t)unk_48E8 << 8u) | unk_48E9) >> 1;
			unk_48E8 = (uint8_t)(unk_48E8_halfword_3 >> 8u);
			unk_48E9 = (uint8_t)unk_48E8_halfword_3;
			a--;
		}
		if (a != 0u)
		{
			if ((int8_t)a >= 0)
			{
				do
				{
					unk_48EA_halfword_3 = (uint32_t)(((uint32_t)unk_48EA << 8u) | unk_48EB) << 1;
					unk_48EA = (uint8_t)(unk_48EA_halfword_3 >> 8u);
					unk_48EB = (uint8_t)unk_48EA_halfword_3;
					t15 = a;
					a = t15 - 1u;
				} while (t15 != 1u);
			}
			else
			{
				do
				{
					unk_48EA_halfword_4 = (((uint32_t)unk_48EA << 8u) | unk_48EB) >> 1;
					unk_48EA = (uint8_t)(unk_48EA_halfword_4 >> 8u);
					unk_48EB = (uint8_t)unk_48EA_halfword_4;
					t16 = a + 1u;
					a = t16;
				} while (t16 != 0u);
			}
		}
		a = arctangents[konami_divx((((uint32_t)unk_48EA << 8u) | unk_48EB), unk_48E9)];
	}
	if ((int8_t)unk_48EC >= 0)
	{
		if ((int8_t)unk_48ED < 0)
			a = 0u - a;
		d_2 = ((uint32_t)a << 8) | stack;
		return d_2;
	}
	a += 0x80u;
	if ((int8_t)unk_48ED >= 0)
		a = 0u - a;
	d_2 = ((uint32_t)a << 8) | stack;
	return d_2;
}

uint16_t sub_07CCFB(uint16_t x, uint16_t u)
{
	uint8_t a = 0, b = 0;
	uint16_t d = 0;
	uint8_t stack = 0;
	uint8_t t11 = 0, t12 = 0, t13 = 0, t14 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0;
	uint32_t unk_48EA_halfword = 0, unk_48EA_halfword_2 = 0, unk_48E8_halfword = 0, unk_48E8_halfword_2 = 0, unk_48E8_halfword_3 = 0, unk_48EA_halfword_3 = 0, unk_48EA_halfword_4 = 0;

	stack = b;
	t1 = mem_read16(u + 0xCu);
	t2 = mem_read16(x + 0xCu);
	t3 = t1 - t2;
	a = (uint8_t)(t3 >> 8);
	unk_48EC = a;
	t4 = ((uint32_t)a << 8) | (uint8_t)t3;
	t5 = t4 >> 15 ? 0u - t4 : t4;
	unk_48E8 = (uint8_t)(t5 >> 8u);
	unk_48E9 = (uint8_t)t5;
	t6 = mem_read16(u + 0x11u);
	t7 = mem_read16(x + 0x11u);
	t8 = t6 - t7;
	a = (uint8_t)(t8 >> 8);
	unk_48ED = a;
	t9 = ((uint32_t)a << 8) | (uint8_t)t8;
	t10 = t9 >> 15 ? 0u - t9 : t9;
	a = (uint8_t)(t10 >> 8);
	b = (uint8_t)t10;
	unk_48EA_halfword = ((uint32_t)a << 8) | b;
	unk_48EA = (uint8_t)(unk_48EA_halfword >> 8u);
	unk_48EB = (uint8_t)unk_48EA_halfword;
	if ((((uint32_t)unk_48E8 << 8u) | unk_48E9) < (uint16_t)(((uint32_t)a << 8) | b))
	{
		a = 6u;
		while (unk_48EA != 0u)
		{
			unk_48EA_halfword_2 = (((uint32_t)unk_48EA << 8u) | unk_48EB) >> 1;
			unk_48EA = (uint8_t)(unk_48EA_halfword_2 >> 8u);
			unk_48EB = (uint8_t)unk_48EA_halfword_2;
			a--;
		}
		if (a != 0u)
		{
			if ((int8_t)a >= 0)
			{
				do
				{
					unk_48E8_halfword = (uint32_t)(((uint32_t)unk_48E8 << 8u) | unk_48E9) << 1;
					unk_48E8 = (uint8_t)(unk_48E8_halfword >> 8u);
					unk_48E9 = (uint8_t)unk_48E8_halfword;
					t11 = a;
					a = t11 - 1u;
				} while (t11 != 1u);
			}
			else
			{
				do
				{
					unk_48E8_halfword_2 = (((uint32_t)unk_48E8 << 8u) | unk_48E9) >> 1;
					unk_48E8 = (uint8_t)(unk_48E8_halfword_2 >> 8u);
					unk_48E9 = (uint8_t)unk_48E8_halfword_2;
					t12 = a + 1u;
					a = t12;
				} while (t12 != 0u);
			}
		}
		a = 0u - (arctangents[konami_divx((((uint32_t)unk_48E8 << 8u) | unk_48E9), unk_48EB)] - 0x40u);
	}
	else
	{
		a = 6u;
		while (unk_48E8 != 0u)
		{
			unk_48E8_halfword_3 = (((uint32_t)unk_48E8 << 8u) | unk_48E9) >> 1;
			unk_48E8 = (uint8_t)(unk_48E8_halfword_3 >> 8u);
			unk_48E9 = (uint8_t)unk_48E8_halfword_3;
			a--;
		}
		if (a != 0u)
		{
			if ((int8_t)a >= 0)
			{
				do
				{
					unk_48EA_halfword_3 = (uint32_t)(((uint32_t)unk_48EA << 8u) | unk_48EB) << 1;
					unk_48EA = (uint8_t)(unk_48EA_halfword_3 >> 8u);
					unk_48EB = (uint8_t)unk_48EA_halfword_3;
					t13 = a;
					a = t13 - 1u;
				} while (t13 != 1u);
			}
			else
			{
				do
				{
					unk_48EA_halfword_4 = (((uint32_t)unk_48EA << 8u) | unk_48EB) >> 1;
					unk_48EA = (uint8_t)(unk_48EA_halfword_4 >> 8u);
					unk_48EB = (uint8_t)unk_48EA_halfword_4;
					t14 = a + 1u;
					a = t14;
				} while (t14 != 0u);
			}
		}
		a = arctangents[konami_divx((((uint32_t)unk_48EA << 8u) | unk_48EB), unk_48E9)];
	}
	if ((int8_t)unk_48EC >= 0)
	{
		if ((int8_t)unk_48ED < 0)
			a = 0u - a;
		d = ((uint32_t)a << 8) | stack;
		return d;
	}
	a += 0x80u;
	if ((int8_t)unk_48ED >= 0)
		a = 0u - a;
	d = ((uint32_t)a << 8) | stack;
	return d;
}

void unused_07CD90(uint16_t x)
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
		unk_48E8 = a & 0x30u;
		t1 = mem_read8(x + 9u);
		mem_write8(x + 9u, (t1 & 0xCFu) | unk_48E8);
		mem_write8(x, 0xC0u);
	}
}

uint16_t sub_07CDD3(uint16_t x, uint16_t d)
{
	uint16_t u = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	u = climb_speeds_ADDRESS;
	t1 = mem_read8(x + 0x5Du);
	stack = ((t1 >> 1) >> 1) >> 1;
	t2 = (uint32_t)climb_speeds[(int8_t)((uint8_t)((d >> 8) - stack))] << 4;
	mem_write16(x + 0x19u, t2);
	return u;
}

uint16_t sub_07CDE9(uint16_t x, uint16_t u)
{
	uint32_t negative = 0;
	uint8_t a = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t4 = 0, t5 = 0, t7 = 0, t9 = 0;
	uint16_t t2 = 0, t3 = 0, t6 = 0, t8 = 0;

	t1 = mem_read8(x + VIDEO_0031);
	mem_write8(x + VIDEO_0031, t1 & 0x10u);
	t2 = mem_read16(x + 0x16u);
	t3 = mem_read16(x + 0x5Cu);
	if (t2 != t3)
	{
		t4 = mem_read8(x + VIDEO_0031);
		mem_write8(x + VIDEO_0031, t4 | 0x40u);
		mem_write8(x, mem_read8(x) | 8u);
	}
	d = 0u;
	sub_079495(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	unk_48F0 = a;
	mem_write8(x + 0x46u, a);
	mem_write8(x + 0x5Du, (((a & 0xFu) << 1) << 1) << 1);
	unk_48F2 = unk_48F0 & 0x30u;
	t5 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t5 & 0xCFu) | unk_48F2);
	t6 = mem_read16(x + 0xFu);
	if (t6 != 0u)
	{
		sub_0794D9(x, &d, &negative);
		a = (uint8_t)(d >> 8);
		unk_48F1 = a;
		mem_write8(x + 0x47u, a);
		if (a != unk_48F0)
			return sub_07CE88(x, u);
		t7 = mem_read8(x + VIDEO_0031);
		mem_write8(x + VIDEO_0031, t7 & 0xEFu);
		return u;
	}
	t8 = mem_read16(x + 0x14u);
	if (t8 == 0u)
	{
		t9 = mem_read8(x + 0x47u);
		unk_48F1 = t9;
		return sub_07CE88(x, u);
	}
	sub_0794D9(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	unk_48F1 = a;
	mem_write8(x + 0x47u, a);
	if (a != unk_48F0)
		return sub_07CE88(x, u);
	t7 = mem_read8(x + VIDEO_0031);
	mem_write8(x + VIDEO_0031, t7 & 0xEFu);
	return u;
}

uint16_t sub_07CE88(uint16_t x, uint16_t u)
{
	uint32_t zero = 0, negative = 0;
	uint8_t a = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t7 = 0, t8 = 0, t9 = 0, t13 = 0, t14 = 0, t15 = 0;
	uint16_t t5 = 0, t6 = 0, t10 = 0, t11 = 0, t12 = 0, t16 = 0, t17 = 0;

	if ((int8_t)unk_48F1 >= 0)
	{
		sub_0794C9(x, &d, &negative);
		a = (uint8_t)(d >> 8);
		unk_48F2 = a;
		if (((a ^ unk_48F0) & 0xFu) == 0u)
		{
			sub_0794B9(x, &d, &negative);
			a = (uint8_t)(d >> 8);
			unk_48F2 = a;
			if (((a ^ unk_48F0) & 0xFu) != 0u)
			{
				mem_write8(x + 0x45u, unk_48F2 & 0xFu);
				t1 = mem_read8(x + 0xFu);
				if ((int8_t)t1 >= 0)
					a = 0x83u;
				else
					a = 0x82u;
			}
			else
			{
				if (((unk_48F1 ^ unk_48F0) & 0xFu) == 0u)
				{
					t2 = mem_read8(x + 0x42u);
					zero = t2 == 0u;
					if ((int8_t)t2 >= 0 && zero == 0u)
					{
						t3 = mem_read8(x + 2u);
						t4 = mem_read8(x + 0x28u);
					}
					return u;
				}
				t5 = mem_read16(x + 0xFu);
				if (t5 == 0u)
				{
					t6 = mem_read16(x + 0x14u);
					if (t6 == 0u)
					{
						t2 = mem_read8(x + 0x42u);
						zero = t2 == 0u;
						if ((int8_t)t2 >= 0 && zero == 0u)
						{
							t3 = mem_read8(x + 2u);
							t4 = mem_read8(x + 0x28u);
						}
						return u;
					}
				}
				a = unk_48F1;
				mem_write8(x + 0x45u, a & 0xFu);
				t7 = mem_read8(x + 0x14u);
				if ((int8_t)t7 >= 0)
					a = 0x81u;
				else
					a = 0x80u;
			}
		}
		else
		{
			a = unk_48F2;
			mem_write8(x + 0x45u, a & 0xFu);
			t7 = mem_read8(x + 0x14u);
			if ((int8_t)t7 >= 0)
				a = 0x81u;
			else
				a = 0x80u;
		}
	}
	else
	{
		t8 = mem_read8(x + VIDEO_0031);
		a = t8;
		if ((a & 0x10u) == 0u)
		{
			mem_write8(x + VIDEO_0031, a | 0x88u);
			mem_write16(x + 0xFu, 0u);
			mem_write16(x + 0x14u, 0u);
			return u;
		}
		sub_0794B9(x, &d, &negative);
		a = (uint8_t)(d >> 8);
		unk_48F2 = a;
		if ((int8_t)a < 0)
		{
			sub_0794C9(x, &d, &negative);
			a = (uint8_t)(d >> 8);
			unk_48F2 = a;
			if ((int8_t)a < 0)
			{
				mem_write8(x + VIDEO_0031, a | 0x88u);
				mem_write16(x + 0xFu, 0u);
				mem_write16(x + 0x14u, 0u);
				return u;
			}
			mem_write16(x + 0xFu, 0u);
			unk_48F1 = a;
			if (((a ^ unk_48F0) & 0xFu) == 0u)
			{
				t2 = mem_read8(x + 0x42u);
				zero = t2 == 0u;
				if ((int8_t)t2 >= 0 && zero == 0u)
				{
					t3 = mem_read8(x + 2u);
					t4 = mem_read8(x + 0x28u);
				}
				return u;
			}
			a = unk_48F2;
			mem_write8(x + 0x45u, a & 0xFu);
			t7 = mem_read8(x + 0x14u);
			if ((int8_t)t7 >= 0)
				a = 0x81u;
			else
				a = 0x80u;
		}
		else
		{
			mem_write16(x + 0x14u, 0u);
			unk_48F1 = a;
			if (((a ^ unk_48F0) & 0xFu) == 0u)
			{
				t2 = mem_read8(x + 0x42u);
				zero = t2 == 0u;
				if ((int8_t)t2 >= 0 && zero == 0u)
				{
					t3 = mem_read8(x + 2u);
					t4 = mem_read8(x + 0x28u);
				}
				return u;
			}
			mem_write8(x + 0x45u, unk_48F2 & 0xFu);
			t1 = mem_read8(x + 0xFu);
			if ((int8_t)t1 >= 0)
				a = 0x83u;
			else
				a = 0x82u;
		}
	}
	t9 = mem_read8(x + VIDEO_0031);
	a |= t9;
	mem_write8(x + VIDEO_0031, a);
	if ((a & 0x40u) == 0u)
	{
		t10 = mem_read16(x + 0x38u);
		u = t10;
		t11 = mem_read16(u + 0x5Cu);
		t12 = mem_read16(x + 0x5Cu);
		if (t11 != t12)
		{
			mem_write16(x + 0xFu, 0u);
			mem_write16(x + 0x14u, 0u);
			t13 = mem_read8(x + VIDEO_0031);
			mem_write8(x + VIDEO_0031, t13 | 0x20u);
			t2 = mem_read8(x + 0x42u);
			zero = t2 == 0u;
			if ((int8_t)t2 >= 0 && zero == 0u)
			{
				t3 = mem_read8(x + 2u);
				t4 = mem_read8(x + 0x28u);
			}
			return u;
		}
		t14 = mem_read8(x + VIDEO_0031);
		a = t14;
		if ((a & 0x10u) != 0u)
		{
			a |= 0x20u;
			mem_write8(x + VIDEO_0031, a);
		}
		mem_write8(x + VIDEO_0031, a | 0x10u);
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
		t2 = mem_read8(x + 0x42u);
		zero = t2 == 0u;
		if ((int8_t)t2 >= 0 && zero == 0u)
		{
			t3 = mem_read8(x + 2u);
			t4 = mem_read8(x + 0x28u);
		}
		return u;
	}
	mem_write8(x + VIDEO_0031, a & 0xEFu);
	t15 = mem_read8(x + 0x45u);
	t16 = (uint32_t)t15 << 3;
	t17 = mem_read16(x + 0x16u);
	if (t17 <= t16)
	{
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
		t2 = mem_read8(x + 0x42u);
		zero = t2 == 0u;
		if ((int8_t)t2 >= 0 && zero == 0u)
		{
			t3 = mem_read8(x + 2u);
			t4 = mem_read8(x + 0x28u);
		}
		return u;
	}
	t2 = mem_read8(x + 0x42u);
	zero = t2 == 0u;
	if ((int8_t)t2 >= 0 && zero == 0u)
	{
		t3 = mem_read8(x + 2u);
		t4 = mem_read8(x + 0x28u);
	}
	return u;
}

void sub_07CF5F(uint16_t x)
{
	uint8_t a = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t6 = 0, t7 = 0;
	uint16_t t4 = 0, t5 = 0;

	t1 = mem_read8(x + VIDEO_0031);
	if ((t1 & 0x40u) == 0u)
	{
		t2 = mem_read8(x + VIDEO_0031);
		a = t2;
		if ((int8_t)t2 < 0 && (a & 8u) == 0u && (a & 0x20u) != 0u)
		{
			t3 = mem_read8(x + 0x45u);
			t4 = (uint32_t)t3 << 3;
			t5 = mem_read16(x + 0x5Cu);
			if (t4 <= t5)
			{
				t6 = mem_read8(x + VIDEO_0031);
				mem_write8(x + VIDEO_0031, t6 | 4u);
			}
			t7 = mem_read8(x + VIDEO_0031);
			mem_write8(x + 0x28u, t7 & 7u);
			mem_write8(x + 0x29u, 0u);
			mem_write8(x + 2u, 5u);
		}
	}
}

void sub_07CFEC(uint16_t x, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t u = (uint16_t)*p_u;
	uint32_t zero = 0, negative = 0;
	uint16_t u_2 = 0;
	uint32_t left_caller = 0;
	uint8_t t1 = 0, t2 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0;
	uint16_t t3 = 0, t8 = 0, t9 = 0;

	if ((mem_read8(x) & 0x20u) == 0u)
		left_caller = 1u;
	else
	{
		t1 = mem_read8(x + 0x1Eu);
		if (t1 < 0x11 || t1 > 0x14)
			left_caller = 1u;
		else
		{
			t2 = mem_read8(x + 2u);
			if ((int8_t)t2 < 0)
				left_caller = 1u;
			else
			{
				t3 = mem_read16(x + 0x25u);
				u_2 = t3;
				t4 = mem_read8(x + 4u);
				if ((int8_t)t4 < 0)
				{
					t5 = mem_read8(u_2 + 4u);
					if (t5 <= 3u)
					{
						t6 = mem_read8(u_2 + 0x2Au);
						mem_write8(u_2 + 0x2Au, t6 + 1u);
						mem_write16(u_2 + 0x49u, x);
					}
				}
				mem_write8(x, 0x80u);
				mem_write8(x + 2u, 4u);
				t7 = mem_read8(x + 9u);
				mem_write8(x + 0x33u, t7 & 0x40u);
				t8 = mem_read16(x + 0x25u);
				u = t8;
				t9 = mem_read16(u + 0xFu);
				negative = t9 >> 15;
				zero = t9 == 0u;
				left_caller = 0u;
				sub_07D030(x, u, zero, negative);
			}
		}
	}
	*p_u = u;
	*p_left_caller = left_caller;
}

void sub_07D030(uint16_t x, uint16_t u, uint32_t zero, uint32_t negative)
{
	uint8_t stack = 0;
	uint8_t t1 = 0, t2 = 0, t5 = 0;
	uint16_t t3 = 0, t4 = 0;

	if (negative)
	{
		t1 = mem_read8(u + 0x5Bu);
		stack = t1 & 0x70u;
		t2 = mem_read8(x + 0x27u);
		mem_write8(x + 0x27u, (t2 & 0x8Fu) | stack);
		return;
	}
	if (zero)
	{
		t3 = mem_read16(u + 0xCu);
		t4 = mem_read16(x + 0xCu);
		if (t3 < t4)
		{
			t5 = mem_read8(x + 0x33u);
			mem_write8(x + 0x33u, t5 ^ 0x40u);
		}
		t1 = mem_read8(u + 0x5Bu);
		stack = t1 & 0x70u;
		t2 = mem_read8(x + 0x27u);
		mem_write8(x + 0x27u, (t2 & 0x8Fu) | stack);
		return;
	}
	t5 = mem_read8(x + 0x33u);
	mem_write8(x + 0x33u, t5 ^ 0x40u);
	t1 = mem_read8(u + 0x5Bu);
	stack = t1 & 0x70u;
	t2 = mem_read8(x + 0x27u);
	mem_write8(x + 0x27u, (t2 & 0x8Fu) | stack);
}

void sub_07D056(uint16_t x, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t u = (uint16_t)*p_u;
	uint8_t t1 = 0;

	sub_07CFEC(x, &u, p_left_caller);
	if (*p_left_caller != 0u)
		*p_left_caller = 0u;
	else
	{
		u = loaded_table_07F134_ADDRESS;
		t1 = mem_read8(x + 0x1Eu);
		switch ((int8_t)(uint8_t)((t1 - 0x11u) << 1))
		{
		case 0:
		case 2:
			sub_07D071(x);
			break;
		case 4:
			sub_07D097(x);
			break;
		case 6:
			sub_07D0A9(x);
			break;
		}
	}
	*p_u = u;
}

void sub_07D071(uint16_t x)
{
	uint8_t a = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t5 = 0, t6 = 0;
	uint16_t t4 = 0;

	t1 = mem_read8(x + 0x1Bu);
	if (t1 == 0u)
	{
		t2 = io_read8(VIDEO_187B);
		io_write8(VIDEO_187B, t2 - 1u);
		t3 = io_read8(VIDEO_187B);
		if ((t3 & 1u) == 0u)
		{
			sub_07D0A9(x);
			return;
		}
		sub_07D097(x);
		return;
	}
	t4 = mem_read16(x + 0x19u);
	if (t4 != 0u)
	{
		t2 = io_read8(VIDEO_187B);
		io_write8(VIDEO_187B, t2 - 1u);
		t3 = io_read8(VIDEO_187B);
		if ((t3 & 1u) == 0u)
		{
			sub_07D0A9(x);
			return;
		}
		sub_07D097(x);
		return;
	}
	t5 = mem_read8(x + 0x33u);
	if (t5 == 0u)
	{
		t6 = mem_read8(x + 0x1Eu);
		if (t6 == 0x11u)
			a = 9u;
		else
			a = 1u;
	}
	else
		a = 0u;
	mem_write8(x + 0x28u, a);
	mem_write8(x + 0x29u, 0u);
}

void sub_07D097(uint16_t x)
{
	uint8_t a = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x33u);
	if (t1 == 0u)
		a = 8u;
	else
		a = 7u;
	mem_write8(x + 0x28u, a);
	mem_write8(x + 0x29u, 0u);
}

void sub_07D0A9(uint16_t x)
{
	uint8_t a = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x33u);
	if (t1 == 0u)
		a = 3u;
	else
		a = 2u;
	mem_write8(x + 0x28u, a);
	mem_write8(x + 0x29u, 0u);
}

uint16_t sub_07D0E0(uint16_t x, uint16_t u)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x27u);
	mem_write8(x + 0x27u, t1 | 0x80u);
	return sub_07D0E8(x, u);
}

uint16_t sub_07D0E8(uint16_t x, uint16_t u)
{
	uint8_t t1 = 0, t3 = 0, t4 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 0x42u);
	if ((int8_t)t1 < 0)
		return u;
	t2 = mem_read16(x + 0x38u);
	u = t2;
	t3 = mem_read8(u + 0x45u);
	t4 = t3 - 1u;
	mem_write8(u + 0x45u, t4);
	if ((int8_t)t4 < 0)
		mem_write8(u + 0x45u, 0u);
	sub_07D115(x, u);
	return u;
}

void sub_07D10E(uint16_t x, uint16_t u)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x30u);
	if (t1 != 1u)
		return;
	sub_07D115(x, u);
}

void sub_07D115(uint16_t x, uint16_t u)
{
	uint8_t a = 0, b = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(u + 0x46u);
	b = t1;
	t2 = mem_read8(x + 0x37u);
	a = t2;
	if ((int8_t)t2 >= 0)
		b &= 0x7Fu;
	else
	{
		mem_write8(x + 0x37u, a & 0x7Fu);
		b &= 0xBFu;
	}
	mem_write8(u + 0x46u, b);
	mem_write8(x + 0x30u, 0u);
	mem_write8(x + 0x3Bu, 0u);
}

uint16_t sub_07D132(uint16_t x, uint16_t u)
{
	uint32_t negative = 0;
	uint8_t a = 0;
	uint16_t d = 0, y = 0;
	uint8_t t3 = 0, t4 = 0, t5 = 0;
	uint16_t t1 = 0, t2 = 0;

	mem_write8(x, 0xC0u);
	t1 = mem_read16(u);
	mem_write16(x + 4u, ((uint32_t)(t1 >> 8) << 8) | (uint8_t)(t1 | 0x80u));
	t2 = mem_read16(u + 2u);
	y = t2;
	mem_write16(x + 0x48u, y);
	sub_07D1B7(x, y);
	t3 = mem_read8(u + 4u);
	mem_write8(x + 0x1Bu, t3);
	t4 = mem_read8(u + 5u);
	mem_write8(x + 0x27u, t4 & 0x7Fu);
	t5 = mem_read8(x + 9u);
	unk_48F0 = t5 & 0xCFu;
	d = 0u;
	sub_079495(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	mem_write8(x + 0x47u, a);
	mem_write8(x + 9u, (a & 0x30u) | unk_48F0);
	return y;
}

void sub_07D16E(uint16_t x, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x19u);
	d = t1 - 0x60u;
	mem_write16(x + 0x19u, d);
	if ((int16_t)d >= 0)
	{
		carry = 0u;
		d &= 0xFFu;
	}
	else
		sub_07D179(x, &d, &carry);
	*p_d = d;
	*p_carry = carry;
}

void sub_07D179(uint16_t x, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t a = 0, d_3 = 0;
	uint16_t d_2 = 0;
	uint8_t t5 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	if (d >> 8 < 0xF8u)
		mem_write8(x + 0x19u, 0xF8u);
	t1 = mem_read16(x + 0x5Cu);
	t2 = t1 + 7u;
	unk_48E8 = (uint8_t)(t2 >> 8u);
	unk_48E9 = (uint8_t)t2;
	t3 = mem_read16(x + 0x16u);
	d_2 = t3;
	if ((((uint32_t)unk_48E8 << 8u) | unk_48E9) < (uint16_t)(((uint32_t)(t3 >> 8) << 8) | (d_2 & 0xFFu)))
	{
		carry = 0u;
		d_2 &= 0xFFu;
	}
	else
	{
		mem_write16(x + 0x19u, 0u);
		t4 = mem_read16(x + 0x5Cu);
		d_3 = (uint8_t)t4;
		mem_write16(x + 0x16u, ((uint32_t)(t4 >> 8) << 8) | (d_3 & 0xFFu));
		mem_write8(x, mem_read8(x) & ~8u);
		t5 = mem_read8(x + 6u);
		a = t5 | 0x80u;
		mem_write8(x + 6u, a);
		carry = 1u;
		d_2 = (d_3 & 0xFFu) | ((uint32_t)(uint8_t)~a << 8);
	}
	*p_d = d_2;
	*p_carry = carry;
}

uint32_t sub_07D1B0(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x19u);
	a = t1;
	if ((int8_t)t1 >= 0)
	{
		carry = 0u;
		return carry;
	}
	d = (uint32_t)a << 8;
	sub_07D179(x, &d, &carry);
	return carry;
}

void sub_07D1B7(uint16_t x, uint16_t y)
{
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	mem_write16(x + 0x1Cu, mem_read16(y));
	t1 = mem_read16(y + 2u);
	mem_write16(x + 0x1Fu, t1);
	t2 = mem_read16(y + 4u);
	mem_write16(x + 0x21u, t2);
	t3 = mem_read16(y + 6u);
	mem_write16(x + 0x23u, t3);
}

void sub_07D1CF(uint16_t x)
{
	uint16_t t1 = 0;

	if (mem_read8(x) != 0u)
	{
		t1 = mem_read16(x + 0xCu);
		if (t1 < 0x10 || t1 > 0x1AF)
			mem_write16(x + 0xFu, 0u);
	}
}

uint16_t sub_07D1F7(uint16_t x, uint16_t u)
{
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	if (mem_read8(x) == 0u)
		return u;
	t1 = mem_read16(x + 0xCu);
	if (t1 < 0x1C0u)
		return u;
	mem_write8(x, 0u);
	if (x >= 0x5280u)
		return u;
	t2 = mem_read8(x + 0x1Bu);
	if (t2 == 0u)
		return sub_07D0E0(x, u);
	return sub_07D0E8(x, u);
}

uint32_t sub_07D216(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0xCu);
	carry = t1 >= 0x50 && t1 <= 0x16F;
	return carry;
}

void sub_07D249(uint16_t x)
{
	uint8_t b = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 9u);
	b = t1;
	t2 = mem_read8(x + 0x36u);
	if ((int8_t)(t2 - 0x40u) >= 0)
		b |= 0x40u;
	else
		b &= 0xBFu;
	mem_write8(x + 9u, b);
}

void sub_07D25D(uint16_t x)
{
	uint8_t t1 = 0;

	sub_07D291(x);
	t1 = mem_read8(x + 5u);
	mem_write8(x + 5u, t1 | 0x80u);
}

void sub_07D268(uint16_t x)
{
	uint8_t a = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0, t5 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x2Eu);
	if (t1 < 0x10u)
	{
		t2 = mem_read8(x + 0x36u);
		mem_write8(x + 0x34u, t2 & 0xC0u);
		a = 1u;
		mem_write8(x + 5u, a);
		sub_07D249(x);
		return;
	}
	t3 = mem_read8(x + 0x36u);
	a = t3 & 0xC0u;
	t4 = mem_read8(x + 0x34u);
	if (a != t4)
	{
		mem_write8(x + 0x34u, a);
		sub_07D291(x);
		return;
	}
	t5 = mem_read8(x + 5u);
	if (t5 == 1u)
	{
		sub_07D291(x);
		return;
	}
}

void sub_07D291(uint16_t x)
{
	uint8_t a = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x36u);
	if ((int8_t)t1 >= 0)
		a = 3u;
	else
		a = 2u;
	mem_write8(x + 5u, a);
	sub_07D249(x);
}

void sub_07D2A2(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x36u);
	mem_write8(x + 0x35u, t1);
	sub_07D268(x);
}

uint16_t sub_07D301(uint16_t x)
{
	uint16_t d = 0, u = 0;
	uint8_t stack = 0;
	uint16_t stack_3 = 0;
	uint8_t t1 = 0, t9 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0;

	t1 = io_read8(VIDEO_1874);
	if (t1 == 0u)
	{
		t2 = io_read16(VIDEO_1872);
		u = t2;
		mem_write16(x + 0x38u, u);
		return u;
	}
	stack = 4u;
	u = unk_4A40_ADDRESS;
	unk_48EC = 0x7Fu;
	unk_48ED = 0xFFu;
	do
	{
		if (mem_read8(u) != 0u)
		{
			t3 = mem_read16(x + 0xCu);
			t4 = mem_read16(u + 0xCu);
			t5 = t3 - t4;
			d = t5;
			if ((int16_t)t5 < 0)
				d = 0u - d;
			stack_3 = d;
			t6 = mem_read16(x + 0x11u);
			t7 = mem_read16(u + 0x11u);
			t8 = t6 - t7;
			d = t8;
			if ((int16_t)t8 < 0)
				d = 0u - d;
			d += stack_3;
			if (d < (((uint32_t)unk_48EC << 8u) | unk_48ED))
			{
				unk_48EC = (uint8_t)(d >> 8u);
				unk_48ED = (uint8_t)d;
				io_write16(VIDEO_1872, u);
			}
		}
		u += 0xC0u;
		t9 = stack;
		stack = t9 - 1u;
	} while (t9 != 1u);
	t2 = io_read16(VIDEO_1872);
	u = t2;
	mem_write16(x + 0x38u, u);
	return u;
}

uint16_t sub_07D34F(uint8_t d)
{
	uint8_t a = 0;
	uint16_t d_2 = 0;
	uint8_t t1 = 0;

	t1 = io_read8(VIDEO_189E);
	a = t1 + unk_4858;
	io_write8(VIDEO_189E, a);
	d_2 = (d & 0xFFu) | ((uint32_t)a << 8);
	return d_2;
}

void sub_07D35B(uint16_t x, uint16_t u)
{
	uint8_t a = 0, d = 0;
	uint8_t t9 = 0, t10 = 0, t13 = 0, t16 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t11 = 0, t12 = 0, t14 = 0, t15 = 0, t17 = 0, t18 = 0;

	unk_48F0 = 0u;
	mem_write8(x + 0x36u, 0u);
	t1 = mem_read16(u + 0xCu);
	t2 = mem_read16(x + 0xCu);
	t3 = t1 - t2;
	d = (uint8_t)t3;
	a = (uint8_t)(t3 >> 8);
	if ((int16_t)t3 >= 0)
		mem_write16(x + 0x2Cu, ((uint32_t)a << 8) | (d & 0xFFu));
	else
	{
		t4 = 0u - (((uint32_t)a << 8) | (d & 0xFFu));
		mem_write16(x + 0x2Cu, t4);
		mem_write8(x + 0x36u, 0x40u);
		unk_48F0 = 0x40u;
	}
	t5 = mem_read16(u + 0x11u);
	t6 = mem_read16(x + 0x11u);
	t7 = t5 - t6;
	d = (uint8_t)t7;
	a = (uint8_t)(t7 >> 8);
	if ((int16_t)t7 >= 0)
		mem_write16(x + 0x2Eu, ((uint32_t)a << 8) | (d & 0xFFu));
	else
	{
		t8 = 0u - (((uint32_t)a << 8) | (d & 0xFFu));
		mem_write16(x + 0x2Eu, t8);
		t9 = mem_read8(x + 0x36u);
		mem_write8(x + 0x36u, t9 ^ 0xC0u);
	}
	t10 = mem_read8(x + 0x36u);
	if ((t10 & 0x40u) != 0u)
	{
		t11 = mem_read16(x + 0x2Cu);
		t12 = mem_read16(x + 0x2Eu);
		if (t12 <= t11)
		{
			t13 = mem_read8(x + 0x36u);
			mem_write8(x + 0x36u, t13 | 0x20u);
		}
	}
	else
	{
		t14 = mem_read16(x + 0x2Cu);
		t15 = mem_read16(x + 0x2Eu);
		if (t14 < t15)
		{
			t13 = mem_read8(x + 0x36u);
			mem_write8(x + 0x36u, t13 | 0x20u);
			t16 = mem_read8(u + 9u);
			if ((int8_t)((uint32_t)(unk_48F0 ^ t16) << 1) >= 0)
			{
				t17 = mem_read16(x + 0x2Eu);
				if (t17 < 8u)
				{
					t18 = mem_read16(x + 0x2Cu);
					if (t18 < 0x40u)
					{
						mem_write8(x + 0x32u, 0u);
						return;
					}
				}
			}
			mem_write8(x + 0x32u, 0x80u);
			return;
		}
	}
	t16 = mem_read8(u + 9u);
	if ((int8_t)((uint32_t)(unk_48F0 ^ t16) << 1) >= 0)
	{
		t17 = mem_read16(x + 0x2Eu);
		if (t17 < 8u)
		{
			t18 = mem_read16(x + 0x2Cu);
			if (t18 < 0x40u)
			{
				mem_write8(x + 0x32u, 0u);
				return;
			}
		}
	}
	mem_write8(x + 0x32u, 0x80u);
}

void sub_07D3D7(uint16_t x, uint16_t *p_u, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = *p_carry;
	uint8_t a = 0, b = 0;
	uint16_t d = 0;
	uint8_t t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = mem_read16(x + 0x2Cu);
	a = (uint8_t)(t1 >> 8);
	if ((uint16_t)(((uint32_t)a << 8) | (uint8_t)t1) >= 0x100u)
	{
		carry = 0u;
		d = (uint32_t)a << 8;
	}
	else
	{
		t2 = mem_read16(x + 0x2Eu);
		a = (uint8_t)(t2 >> 8);
		if ((uint16_t)(((uint32_t)a << 8) | (uint8_t)t2) >= 0x100u)
		{
			carry = 0u;
			d = (uint32_t)a << 8;
		}
		else
		{
			a = 4u;
			for (;;)
			{
				t3 = mem_read8(x + VIDEO_002F);
				if (mem_read8(u) < t3)
				{
					carry = 0u;
					d = (uint32_t)a << 8;
					break;
				}
				t4 = mem_read8(x + 0x2Du);
				b = t4;
				t5 = mem_read8(u + 1u);
				if (t5 <= b)
				{
					t6 = mem_read8(u + 2u);
					if (b <= t6)
					{
						carry = 1u;
						t7 = mem_read8(u + 3u);
						d = ((uint32_t)t7 << 8) | (uint8_t)~b;
						break;
					}
				}
				u += 0xCu;
				t8 = a;
				a = t8 - 1u;
				if (t8 == 1u)
				{
					carry = 0u;
					d = (uint32_t)a << 8;
					break;
				}
			}
		}
	}
	*p_u = u;
	*p_d = d;
	*p_carry = carry;
}

void sub_07D40A(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	switch ((int8_t)(uint8_t)((uint32_t)d << 1))
	{
	case 0:
		sub_07D43B(x, &y, &ignored16);
		break;
	case 4:
		sub_07D49C(x, &y, &ignored16, &ignored);
		break;
	case 6:
		sub_07D63B(x, &y, &ignored16, &ignored);
		break;
	case 8:
		sub_07D667(x, &y, &ignored16, &ignored);
		break;
	case 10:
		sub_07D6B2(x, &y, &ignored16, &ignored);
		break;
	}
	sub_07D056(x, &ignored16, p_left_caller);
	sub_07D1F7(x, ignored16);
	*p_y = y;
}

void sub_07D416(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0;

	u = object_setup_07F1A8_ADDRESS;
	y = sub_07D132(x, u);
	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, t1 | 0x40u);
	mem_write8(x + 0x42u, 1u);
	u = sub_07D301(x);
	sub_07D35B(x, u);
	u = enemy_behaviour_07F144_ADDRESS;
	mem_write16(x + 0x2Au, enemy_behaviour_07F144_ADDRESS);
	mem_write8(x + 0x3Au, 0x10u);
	*p_y = y;
	*p_u = u;
}

void sub_07D43B(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0;

	sub_07D416(x, &y, &u);
	t1 = mem_read8(x + 0x30u);
	if (t1 != 0u)
		mem_write8(x + 0x1Bu, 1u);
	mem_write8(x + 0x30u, 0u);
	mem_write8(x + 2u, 2u);
	*p_y = y;
	*p_u = u;
}

void sub_07D450(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	u = object_setup_07F1A8_ADDRESS;
	y = sub_07D132(x, u);
	t1 = mem_read8(x + 0x42u);
	if ((int8_t)t1 >= 0)
	{
		t2 = mem_read16(x + 0x38u);
		u = t2;
		sub_07D10E(x, u);
	}
	mem_write8(x + 0x42u, 1u);
	u = enemy_behaviour_07F144_ADDRESS;
	mem_write16(x + 0x2Au, enemy_behaviour_07F144_ADDRESS);
	mem_write8(x + 0x3Au, 0x10u);
	mem_write8(x + 0x30u, 0u);
	mem_write8(x + 0x3Bu, 0u);
	mem_write16(x + 1u, 2u);
	*p_y = y;
	*p_u = u;
}

void unused_07D47E(uint16_t x)
{
	uint8_t a = 0;
	uint16_t d = 0, u = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = mem_read16(x + 0x38u);
	u = t1;
	sub_07D35B(x, u);
	t2 = mem_read16(x + 0x28u);
	a = (uint8_t)(t2 >> 8);
	unk_480E = unused_object_banks[(int8_t)a];
	set_lines(unk_480E);
	u = unused_object_handlers_ADDRESS;
	d = (uint32_t)(uint8_t)((uint32_t)a << 1) << 8;
	unused_07D47E_dispatch(u, d);
}

void unused_07D47E_dispatch(uint16_t u, uint16_t d)
{
	invalid_jump(mem_read16(u + (int8_t)(d >> 8)));
}

void sub_07D49C(uint16_t x, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	bool L_07D53B = false, L_07D59B = false;
	uint32_t carry = 0;
	uint8_t a = 0, b = 0, d_2 = 0;
	uint16_t d = 0, u = 0;
	uint8_t stack = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t8 = 0, t12 = 0, t13 = 0, t14 = 0, t15 = 0, t18 = 0, t21 = 0, t22 = 0, t23 = 0, t24 = 0, t25 = 0, t26 = 0, t27 = 0, t28 = 0, t30 = 0, t31 = 0, t40 = 0, t41 = 0, t42 = 0, t44 = 0, t45 = 0, t46 = 0, t47 = 0;
	uint16_t t1 = 0, t7 = 0, t9 = 0, t10 = 0, t11 = 0, t16 = 0, t17 = 0, t19 = 0, t20 = 0, t29 = 0, t32 = 0, t33 = 0, t34 = 0, t35 = 0, t36 = 0, t37 = 0, t38 = 0, t39 = 0, t43 = 0;

	t1 = mem_read16(x + 0x38u);
	u = t1;
	sub_07D35B(x, u);
	t2 = mem_read8(x + 0x3Au);
	mem_write8(x + 0x3Au, t2 - 1u);
	if (t2 == 1u)
	{
		mem_write8(x + 0x3Au, 0x10u);
		unk_48F0 = (uint8_t)(u >> 8u);
		unk_48F1 = (uint8_t)u;
		t3 = mem_read8(u + 0x45u);
		t4 = t3 - 1u;
		mem_write8(u + 0x45u, t4);
		if ((int8_t)t4 < 0)
			mem_write8(u + 0x45u, 0u);
		u = sub_07D301(x);
		t5 = mem_read8(u + 0x45u);
		t6 = io_read8(VIDEO_1877);
		if (t6 <= t5)
		{
			sub_07CC38();
			t7 = io_read16(VIDEO_1870);
			u = t7;
			mem_write16(x + 0x38u, u);
		}
		t8 = mem_read8(u + 0x45u);
		mem_write8(u + 0x45u, t8 + 1u);
		if (u != (((uint32_t)unk_48F0 << 8u) | unk_48F1))
		{
			u = (((uint32_t)unk_48F0 << 8u) | unk_48F1);
			sub_07D10E(x, u);
			t9 = mem_read16(x + 0x38u);
			u = t9;
		}
	}
	if (unk_487D != 0u)
	{
		mem_write8(x, 0u);
		*p_u = u;
		return;
	}
	t10 = mem_read16(x + 0x16u);
	t11 = mem_read16(x + 0x5Cu);
	if (t10 != t11)
		sub_07D16E(x, &d, &carry);
	t12 = mem_read8(x + 0x30u);
	if (t12 != 0u)
	{
		t13 = mem_read8(x + 0x30u);
		if (t13 != 1u)
		{
			t14 = mem_read8(x + 0x30u);
			if (t14 == 2u)
			{
				t15 = mem_read8(u + 0x46u);
				if (t15 < 0xC0u)
				{
					mem_write8(x + 0x30u, 0u);
					mem_write8(x + 0x3Bu, 0u);
				}
			}
		}
		else
		{
			t16 = mem_read16(x + 0x2Cu);
			if (t16 >= 0x50u)
				sub_07D115(x, u);
			else
			{
				t17 = mem_read16(x + 0x2Eu);
				if (t17 >= 0x50u)
					sub_07D115(x, u);
			}
		}
	}
	else
	{
		t18 = mem_read8(u + 0x46u);
		if (t18 < 0xC0u)
		{
			t19 = mem_read16(x + 0x2Cu);
			if (t19 < 0x40u)
			{
				t20 = mem_read16(x + 0x2Eu);
				if (t20 < 0x40u)
				{
					mem_write8(x + 0x30u, 1u);
					mem_write8(x + 0x3Bu, 0u);
					t21 = mem_read8(x + 0x36u);
					do
					{
						if (L_07D53B || t21 <= 0x40u)
						{
							for (;;)
							{
								L_07D53B = false;
								t22 = mem_read8(u + 0x46u);
								a = t22;
								if ((a & 0x40u) != 0u)
								{
									t23 = mem_read8(u + 0x46u);
									a = t23;
									if ((int8_t)t23 < 0)
										continue;
									mem_write8(u + 0x46u, a | 0x80u);
									t24 = mem_read8(x + 0x37u);
									mem_write8(x + 0x37u, t24 & 0x7Fu);
									break;
								}
								mem_write8(u + 0x46u, a | 0x40u);
								t25 = mem_read8(x + 0x37u);
								mem_write8(x + 0x37u, t25 | 0x80u);
								break;
							}
						}
						else
						{
							t23 = mem_read8(u + 0x46u);
							a = t23;
							L_07D53B = (int8_t)t23 < 0;
							if (!L_07D53B)
							{
								mem_write8(u + 0x46u, a | 0x80u);
								t24 = mem_read8(x + 0x37u);
								mem_write8(x + 0x37u, t24 & 0x7Fu);
							}
						}
					} while (L_07D53B);
				}
			}
		}
		else
		{
			mem_write8(x + 0x30u, 2u);
			mem_write8(x + 0x3Bu, 0u);
		}
	}
	t26 = mem_read8(u + 2u);
	L_07D59B = (int8_t)t26 >= 0;
	if (!L_07D59B)
	{
		t27 = mem_read8(x + 0x30u);
		L_07D59B = t27 != 1u;
		if (!L_07D59B)
		{
			sub_07D115(x, u);
			mem_write8(x + 0x30u, 3u);
			mem_write8(x + 0x3Bu, 0u);
			t28 = mem_read8(x + 0x3Bu);
			if (t28 != 0u)
			{
				t29 = mem_read16(x + 0x28u);
				u = loaded_table_07F586_ADDRESS;
				a = (uint32_t)(t29 >> 8) << 1;
				d_2 = (uint8_t)t29;
				switch ((int8_t)a)
				{
				case 0:
					sub_07D994(x, d_2, &y, &u, p_left_caller);
					break;
				case 2:
					sub_07DA09(x, d_2, &y, &u, p_left_caller);
					break;
				case 4:
					sub_07DABE(x, d_2, &y, &u, p_left_caller);
					break;
				case 6:
					sub_07DB7A(x, d_2, &y, &u, p_left_caller);
					break;
				case 8:
					sub_07DC02();
					break;
				case 10:
					sub_07DC03(x, d_2, &y, &u, p_left_caller);
					break;
				case 12:
					sub_07DC3E(x, d_2, &y, &u, p_left_caller);
					break;
				case 14:
					sub_07DD0B(x, d_2, &y, &u, p_left_caller);
					break;
				case 16:
					sub_07DD77(x, d_2, &y, &u, p_left_caller);
					break;
				case 18:
					sub_07DB71(x, d_2, &y, &u, p_left_caller);
					break;
				case 20:
					sub_07D8E2(x, d_2, &y, &u, p_left_caller);
					break;
				case 22:
					sub_07DC9C(x, d_2, &y, &u, p_left_caller);
					break;
				case 24:
					sub_07D880(x, d_2, &y, &u, p_left_caller);
					break;
				case 26:
					sub_07D7FA(x, d_2, &y, &u, p_left_caller);
					break;
				case -114:
				case -90:
				case 28:
				case 78:
				case 98:
					sub_028003(x, d_2, &y, &u);
					break;
				case -118:
				case -116:
				case -88:
				case 30:
				case 100:
					sub_028006(x, d_2, &y, &u);
					break;
				case 32:
				case 46:
				case 102:
					sub_028009(x, d_2, &y, &u);
					break;
				case -120:
				case 34:
				case 44:
				case 48:
				case 108:
					sub_02800C(x, d_2, &y, &u);
					break;
				case -126:
				case -80:
				case -64:
				case 36:
				case 50:
				case 112:
					sub_02800F(x, d_2, &y, &u);
					break;
				case 38:
				case 52:
					sub_028012(x, d_2, &y, &u, p_left_caller);
					break;
				case 40:
					sub_028084(x, d_2, &y, &u);
					break;
				case 42:
					sub_0280AE(x, d_2, &y, &u);
					break;
				case 54:
				case 88:
				case 94:
				case 122:
					sub_02802D(x, d_2, &y, &u, p_left_caller);
					break;
				case -112:
				case 56:
				case 120:
					sub_02802A(x, d_2, &y, &u, p_left_caller);
					break;
				case 58:
				case 92:
				case 116:
					sub_028042(x, d_2, &y, &u, p_left_caller);
					break;
				case -70:
				case 60:
				case 118:
					sub_02801E(x, d_2, &y, &u, p_left_caller);
					break;
				case 62:
					sub_028087(x, d_2, &y, &u);
					break;
				case 64:
					sub_02808A(x, d_2, &y, &u);
					break;
				case 66:
					sub_02808D(x, d_2, &y, &u);
					break;
				case 68:
					sub_028090(x, d_2, &y, &u);
					break;
				case 70:
					sub_028093(x, d_2, &y, &u);
					break;
				case 72:
					sub_0280B4(x, d_2, &y, &u);
					break;
				case 74:
					sub_0280B7(x, d_2, &y, &u);
					break;
				case 76:
					sub_02805D(x, d_2, &y, &u);
					break;
				case -62:
				case -6:
				case 80:
					sub_028015(x, d_2, &y, &u, p_left_caller);
					break;
				case -106:
				case 82:
				case 124:
					sub_028030(x, d_2, &y, &u);
					break;
				case 84:
				case 86:
					sub_028024(x, d_2, &y, &u, p_left_caller);
					break;
				case 90:
				case 126:
					sub_02803F(x, d_2, &y, &u, p_left_caller);
					break;
				case -104:
				case -84:
				case 96:
					sub_028033(x, d_2, &y, &u);
					break;
				case 104:
					sub_028039(x, d_2, &y, &u, p_left_caller);
					break;
				case 106:
					sub_0280BA(x, d_2, &y, &u);
					break;
				case -128:
				case 110:
					sub_028027(x, d_2, &y, &u, p_left_caller);
					break;
				case -82:
				case 114:
					sub_02801B(x, d_2, &y, &u, p_left_caller);
					break;
				}
				u = sub_07CDE9(x, u);
				sub_07CF5F(x);
				*p_y = y;
				*p_u = u;
				return;
			}
		}
	}
	if (L_07D59B)
	{
		t30 = mem_read8(x + 0x3Bu);
		if (t30 != 0u)
		{
			carry = sub_07D216(x);
			if (carry)
			{
				t31 = mem_read8(u + 2u);
				if ((int8_t)t31 >= 0)
				{
					t32 = mem_read16(u + 0x5Cu);
					t33 = mem_read16(x + 0x5Cu);
					t34 = t32 - t33;
					t35 = t34;
					t36 = t35 >> 15 ? 0u - t35 : t35;
					if (t36 <= 0x20u)
					{
						t37 = mem_read16(x + 0x16u);
						t38 = mem_read16(x + 0x5Cu);
						if (t37 == t38)
						{
							t39 = mem_read16(x + 0x2Au);
							u = t39 + 0x28u;
							sub_07D3D7(x, &u, &d, &carry);
							a = (uint8_t)(d >> 8);
							if (carry)
							{
								stack = a;
								d = sub_07D34F((uint8_t)d);
								a = (uint8_t)(d >> 8);
								if (a < stack)
								{
									d = sub_07D34F((uint8_t)d);
									a = (uint8_t)(d >> 8);
									b = 4u;
									u += 7u;
									do
									{
										t40 = mem_read8(u + (int8_t)b);
										t41 = a;
										a = t41 - t40;
										if (t41 < t40)
										{
											u -= 4u;
											mem_write8(x + 0x28u, mem_read8(u + (int8_t)b));
											mem_write8(x + 2u, 3u);
											mem_write8(x + 0x29u, 0u);
											mem_write16(x + 0xFu, 0u);
											mem_write16(x + 0x14u, 0u);
											mem_write16(x + 0x19u, 0u);
											*p_u = u;
											return;
										}
										t42 = b;
										b = t42 - 1u;
									} while (t42 != 1u);
								}
							}
						}
					}
				}
			}
			t28 = mem_read8(x + 0x3Bu);
			if (t28 != 0u)
			{
				t29 = mem_read16(x + 0x28u);
				u = loaded_table_07F586_ADDRESS;
				a = (uint32_t)(t29 >> 8) << 1;
				d_2 = (uint8_t)t29;
				switch ((int8_t)a)
				{
				case 0:
					sub_07D994(x, d_2, &y, &u, p_left_caller);
					break;
				case 2:
					sub_07DA09(x, d_2, &y, &u, p_left_caller);
					break;
				case 4:
					sub_07DABE(x, d_2, &y, &u, p_left_caller);
					break;
				case 6:
					sub_07DB7A(x, d_2, &y, &u, p_left_caller);
					break;
				case 8:
					sub_07DC02();
					break;
				case 10:
					sub_07DC03(x, d_2, &y, &u, p_left_caller);
					break;
				case 12:
					sub_07DC3E(x, d_2, &y, &u, p_left_caller);
					break;
				case 14:
					sub_07DD0B(x, d_2, &y, &u, p_left_caller);
					break;
				case 16:
					sub_07DD77(x, d_2, &y, &u, p_left_caller);
					break;
				case 18:
					sub_07DB71(x, d_2, &y, &u, p_left_caller);
					break;
				case 20:
					sub_07D8E2(x, d_2, &y, &u, p_left_caller);
					break;
				case 22:
					sub_07DC9C(x, d_2, &y, &u, p_left_caller);
					break;
				case 24:
					sub_07D880(x, d_2, &y, &u, p_left_caller);
					break;
				case 26:
					sub_07D7FA(x, d_2, &y, &u, p_left_caller);
					break;
				case -114:
				case -90:
				case 28:
				case 78:
				case 98:
					sub_028003(x, d_2, &y, &u);
					break;
				case -118:
				case -116:
				case -88:
				case 30:
				case 100:
					sub_028006(x, d_2, &y, &u);
					break;
				case 32:
				case 46:
				case 102:
					sub_028009(x, d_2, &y, &u);
					break;
				case -120:
				case 34:
				case 44:
				case 48:
				case 108:
					sub_02800C(x, d_2, &y, &u);
					break;
				case -126:
				case -80:
				case -64:
				case 36:
				case 50:
				case 112:
					sub_02800F(x, d_2, &y, &u);
					break;
				case 38:
				case 52:
					sub_028012(x, d_2, &y, &u, p_left_caller);
					break;
				case 40:
					sub_028084(x, d_2, &y, &u);
					break;
				case 42:
					sub_0280AE(x, d_2, &y, &u);
					break;
				case 54:
				case 88:
				case 94:
				case 122:
					sub_02802D(x, d_2, &y, &u, p_left_caller);
					break;
				case -112:
				case 56:
				case 120:
					sub_02802A(x, d_2, &y, &u, p_left_caller);
					break;
				case 58:
				case 92:
				case 116:
					sub_028042(x, d_2, &y, &u, p_left_caller);
					break;
				case -70:
				case 60:
				case 118:
					sub_02801E(x, d_2, &y, &u, p_left_caller);
					break;
				case 62:
					sub_028087(x, d_2, &y, &u);
					break;
				case 64:
					sub_02808A(x, d_2, &y, &u);
					break;
				case 66:
					sub_02808D(x, d_2, &y, &u);
					break;
				case 68:
					sub_028090(x, d_2, &y, &u);
					break;
				case 70:
					sub_028093(x, d_2, &y, &u);
					break;
				case 72:
					sub_0280B4(x, d_2, &y, &u);
					break;
				case 74:
					sub_0280B7(x, d_2, &y, &u);
					break;
				case 76:
					sub_02805D(x, d_2, &y, &u);
					break;
				case -62:
				case -6:
				case 80:
					sub_028015(x, d_2, &y, &u, p_left_caller);
					break;
				case -106:
				case 82:
				case 124:
					sub_028030(x, d_2, &y, &u);
					break;
				case 84:
				case 86:
					sub_028024(x, d_2, &y, &u, p_left_caller);
					break;
				case 90:
				case 126:
					sub_02803F(x, d_2, &y, &u, p_left_caller);
					break;
				case -104:
				case -84:
				case 96:
					sub_028033(x, d_2, &y, &u);
					break;
				case 104:
					sub_028039(x, d_2, &y, &u, p_left_caller);
					break;
				case 106:
					sub_0280BA(x, d_2, &y, &u);
					break;
				case -128:
				case 110:
					sub_028027(x, d_2, &y, &u, p_left_caller);
					break;
				case -82:
				case 114:
					sub_02801B(x, d_2, &y, &u, p_left_caller);
					break;
				}
				u = sub_07CDE9(x, u);
				sub_07CF5F(x);
				*p_y = y;
				*p_u = u;
				return;
			}
		}
	}
	t43 = mem_read16(x + 0x2Au);
	t44 = mem_read8(x + 0x30u);
	u = t43 + (int8_t)((((uint32_t)t44 << 1) << 1) << 1);
	d = sub_07D34F((uint8_t)d);
	a = (uint8_t)(d >> 8);
	b = 4u;
	u += 3u;
	do
	{
		t45 = mem_read8(u + (int8_t)b);
		t46 = a;
		a = t46 - t45;
		if (t46 < t45)
		{
			b--;
			break;
		}
		t47 = b;
		b = t47 - 1u;
	} while (t47 != 1u);
	mem_write8(x + 0x28u, mem_read8(u - 3u + (int8_t)b));
	mem_write8(x + 0x29u, 0u);
	t29 = mem_read16(x + 0x28u);
	u = loaded_table_07F586_ADDRESS;
	a = (uint32_t)(t29 >> 8) << 1;
	d_2 = (uint8_t)t29;
	switch ((int8_t)a)
	{
	case 0:
		sub_07D994(x, d_2, &y, &u, p_left_caller);
		break;
	case 2:
		sub_07DA09(x, d_2, &y, &u, p_left_caller);
		break;
	case 4:
		sub_07DABE(x, d_2, &y, &u, p_left_caller);
		break;
	case 6:
		sub_07DB7A(x, d_2, &y, &u, p_left_caller);
		break;
	case 8:
		sub_07DC02();
		break;
	case 10:
		sub_07DC03(x, d_2, &y, &u, p_left_caller);
		break;
	case 12:
		sub_07DC3E(x, d_2, &y, &u, p_left_caller);
		break;
	case 14:
		sub_07DD0B(x, d_2, &y, &u, p_left_caller);
		break;
	case 16:
		sub_07DD77(x, d_2, &y, &u, p_left_caller);
		break;
	case 18:
		sub_07DB71(x, d_2, &y, &u, p_left_caller);
		break;
	case 20:
		sub_07D8E2(x, d_2, &y, &u, p_left_caller);
		break;
	case 22:
		sub_07DC9C(x, d_2, &y, &u, p_left_caller);
		break;
	case 24:
		sub_07D880(x, d_2, &y, &u, p_left_caller);
		break;
	case 26:
		sub_07D7FA(x, d_2, &y, &u, p_left_caller);
		break;
	case -114:
	case -90:
	case 28:
	case 78:
	case 98:
		sub_028003(x, d_2, &y, &u);
		break;
	case -118:
	case -116:
	case -88:
	case 30:
	case 100:
		sub_028006(x, d_2, &y, &u);
		break;
	case 32:
	case 46:
	case 102:
		sub_028009(x, d_2, &y, &u);
		break;
	case -120:
	case 34:
	case 44:
	case 48:
	case 108:
		sub_02800C(x, d_2, &y, &u);
		break;
	case -126:
	case -80:
	case -64:
	case 36:
	case 50:
	case 112:
		sub_02800F(x, d_2, &y, &u);
		break;
	case 38:
	case 52:
		sub_028012(x, d_2, &y, &u, p_left_caller);
		break;
	case 40:
		sub_028084(x, d_2, &y, &u);
		break;
	case 42:
		sub_0280AE(x, d_2, &y, &u);
		break;
	case 54:
	case 88:
	case 94:
	case 122:
		sub_02802D(x, d_2, &y, &u, p_left_caller);
		break;
	case -112:
	case 56:
	case 120:
		sub_02802A(x, d_2, &y, &u, p_left_caller);
		break;
	case 58:
	case 92:
	case 116:
		sub_028042(x, d_2, &y, &u, p_left_caller);
		break;
	case -70:
	case 60:
	case 118:
		sub_02801E(x, d_2, &y, &u, p_left_caller);
		break;
	case 62:
		sub_028087(x, d_2, &y, &u);
		break;
	case 64:
		sub_02808A(x, d_2, &y, &u);
		break;
	case 66:
		sub_02808D(x, d_2, &y, &u);
		break;
	case 68:
		sub_028090(x, d_2, &y, &u);
		break;
	case 70:
		sub_028093(x, d_2, &y, &u);
		break;
	case 72:
		sub_0280B4(x, d_2, &y, &u);
		break;
	case 74:
		sub_0280B7(x, d_2, &y, &u);
		break;
	case 76:
		sub_02805D(x, d_2, &y, &u);
		break;
	case -62:
	case -6:
	case 80:
		sub_028015(x, d_2, &y, &u, p_left_caller);
		break;
	case -106:
	case 82:
	case 124:
		sub_028030(x, d_2, &y, &u);
		break;
	case 84:
	case 86:
		sub_028024(x, d_2, &y, &u, p_left_caller);
		break;
	case 90:
	case 126:
		sub_02803F(x, d_2, &y, &u, p_left_caller);
		break;
	case -104:
	case -84:
	case 96:
		sub_028033(x, d_2, &y, &u);
		break;
	case 104:
		sub_028039(x, d_2, &y, &u, p_left_caller);
		break;
	case 106:
		sub_0280BA(x, d_2, &y, &u);
		break;
	case -128:
	case 110:
		sub_028027(x, d_2, &y, &u, p_left_caller);
		break;
	case -82:
	case 114:
		sub_02801B(x, d_2, &y, &u, p_left_caller);
		break;
	}
	u = sub_07CDE9(x, u);
	sub_07CF5F(x);
	*p_y = y;
	*p_u = u;
}

void sub_07D63B(uint16_t x, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t a = 0, d = 0;
	uint16_t u = 0;
	uint8_t stack = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = mem_read16(x + 0x16u);
	t2 = mem_read16(x + 0x5Cu);
	if (t1 != t2)
		carry = sub_07D1B0(x);
	t3 = mem_read16(x + 0x38u);
	u = t3;
	sub_07D35B(x, u);
	t4 = mem_read16(x + 0x28u);
	a = (uint8_t)(t4 >> 8);
	stack = t4;
	unk_480E = action_banks[(int8_t)a];
	set_lines(unk_480E);
	u = loaded_table_07F5A2_ADDRESS;
	a = (uint32_t)a << 1;
	d = stack;
	switch ((int8_t)a)
	{
	case 0:
		sub_028003(x, d, &y, &u);
		break;
	case 2:
		sub_028006(x, d, &y, &u);
		break;
	case 4:
		sub_028009(x, d, &y, &u);
		break;
	case 6:
		sub_02800C(x, d, &y, &u);
		break;
	case 8:
		sub_02800F(x, d, &y, &u);
		break;
	case 10:
		sub_028012(x, d, &y, &u, p_left_caller);
		break;
	case 12:
		sub_028084(x, d, &y, &u);
		break;
	case 14:
		sub_0280AE(x, d, &y, &u);
		break;
	case 16:
		sub_02E00C(x, d, &y, &u);
		break;
	case 18:
		sub_02A009(x, d, &y, &u);
		break;
	case 20:
		sub_02A00C(x, d, &y, &u);
		break;
	case 22:
		sub_02A00F(x, d, &y, &u);
		break;
	case 24:
		sub_02A012(x, d, &y, &u);
		break;
	case 26:
		sub_02A02D(x, d, &y, &u);
		break;
	case 28:
		sub_02A02A(x, d, &y, &u);
		break;
	case 30:
		sub_028042(x, d, &y, &u, p_left_caller);
		break;
	case 32:
		sub_02E01E(x, d, &y, &u);
		break;
	case 34:
		sub_028087(x, d, &y, &u);
		break;
	case 36:
		sub_02808A(x, d, &y, &u);
		break;
	case 38:
		sub_02808D(x, d, &y, &u);
		break;
	case 40:
		sub_028090(x, d, &y, &u);
		break;
	case 42:
		sub_028093(x, d, &y, &u);
		break;
	case 44:
		sub_0280B4(x, d, &y, &u);
		break;
	case 46:
		sub_0280B7(x, d, &y, &u);
		break;
	case 48:
		sub_02805D(x, d, &y, &u);
		break;
	case 50:
		sub_030003();
		break;
	case 52:
		sub_030015(x, d, &y, &u);
		break;
	case 54:
		sub_028030(x, d, &y, &u);
		break;
	case 56:
		sub_02E024(x, d, &y, &u);
		break;
	case 58:
		sub_030024(x, d, &y, &u);
		break;
	case 60:
		sub_02E02D(x, d, &y, &u);
		break;
	case 62:
		sub_02E03F(x, d, &y, &u);
		break;
	case 64:
		sub_02E042(x, d, &y, &u);
		break;
	case 66:
		sub_03002D(x, d, &y, &u);
		break;
	case 68:
		sub_030033(x, d, &y, &u);
		break;
	case 70:
		sub_032003(x, d, &y, &u);
		break;
	case 72:
		sub_032006(x, d, &y, &u);
		break;
	case 74:
		sub_032009(x, d, &y, &u);
		break;
	case 76:
		sub_030039(x, d, &y, &u);
		break;
	case 78:
		sub_0280BA(x, d, &y, &u);
		break;
	case 80:
		sub_03200C(x, d, &y, &u);
		break;
	case 82:
		sub_02A027(x, d, &y, &u);
		break;
	case 84:
		sub_03200F(x, d, &y, &u);
		break;
	case 86:
		sub_03201B(x, d, &y, &u);
		break;
	case 88:
		sub_030042(x, d, &y, &u);
		break;
	case 90:
		sub_03201E(x, d, &y, &u);
		break;
	case 92:
		sub_03202A(x, d, &y, &u);
		break;
	case 94:
		sub_03202D(x, d, &y, &u);
		break;
	case 96:
		sub_032030(x, d, &y, &u);
		break;
	case 98:
		sub_03003F(x, d, &y, &u);
		break;
	case 100:
		sub_03203C(x, d, &y, &u);
		break;
	case 102:
		sub_028033(x, d, &y, &u);
		break;
	case 104:
		u = sub_02E066(x, d);
		break;
	case 106:
		u = sub_030045(x, d);
		break;
	case 108:
		sub_02E069(x, d, &y, &u);
		break;
	case 110:
		sub_032015(x, d, &y, &u);
		break;
	case 112:
		sub_02A04B(x, d, &y, &u);
		break;
	case 114:
		sub_032051(x, d, &y, &u);
		break;
	case 116:
		sub_032054(x, d, &y, &u);
		break;
	case 118:
		sub_032057(x, d, &y, &u);
		break;
	case 120:
		sub_03004B(x, d, &y, &u);
		break;
	case 122:
		sub_0280AB(x, d, &y, &u);
		break;
	case 124:
		sub_02A081(x, d, &y, &u);
		break;
	case -28:
		sub_07D994(x, d, &y, &u, p_left_caller);
		break;
	case -26:
		sub_07DA09(x, d, &y, &u, p_left_caller);
		break;
	case -24:
		sub_07DABE(x, d, &y, &u, p_left_caller);
		break;
	case -22:
		sub_07DB7A(x, d, &y, &u, p_left_caller);
		break;
	case -20:
		sub_07DC02();
		break;
	case -18:
		sub_07DC03(x, d, &y, &u, p_left_caller);
		break;
	case -16:
		sub_07DC3E(x, d, &y, &u, p_left_caller);
		break;
	case -14:
		sub_07DD0B(x, d, &y, &u, p_left_caller);
		break;
	case -12:
		sub_07DD77(x, d, &y, &u, p_left_caller);
		break;
	case -10:
		sub_07DB71(x, d, &y, &u, p_left_caller);
		break;
	case -8:
		sub_07D8E2(x, d, &y, &u, p_left_caller);
		break;
	case -6:
		sub_07DC9C(x, d, &y, &u, p_left_caller);
		break;
	case -4:
		sub_07D880(x, d, &y, &u, p_left_caller);
		break;
	case -2:
		sub_07D7FA(x, d, &y, &u, p_left_caller);
		break;
	}
	u = sub_07CDE9(x, u);
	*p_y = y;
	*p_u = u;
}

void sub_07D667(uint16_t x, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t d = 0;
	uint16_t u = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x28u);
	d = (uint8_t)t1;
	switch ((int8_t)(uint8_t)((uint32_t)(t1 >> 8) << 1))
	{
	case 0:
		sub_07DDC3(x, d, &y, &u, p_left_caller);
		break;
	case 2:
		sub_07DDF3(x, d, &y, &u, p_left_caller);
		break;
	case 4:
		sub_07DE29(x, d, &y, &u, p_left_caller);
		break;
	case 6:
		sub_07DEB1(x, d, &y, &u, p_left_caller);
		break;
	case 8:
		sub_07DF4C(x, d, &y, &u, p_left_caller);
		break;
	case 10:
		sub_07DF60(x, d, &y, &u, p_left_caller);
		break;
	case 12:
		sub_07DF9B(x, d, &y, &u, p_left_caller);
		break;
	case 14:
		sub_07DFB1(x, d, &y, &u, p_left_caller);
		break;
	case 16:
		sub_07E028(x, d, &y, &u, p_left_caller);
		break;
	case 18:
		sub_07DE0E(x, d, &y, &u, p_left_caller);
		break;
	case 20:
		sub_07E05E(x, d, &y, &u, p_left_caller);
		break;
	case 22:
		sub_07E12F(x, d, &y, &u, p_left_caller);
		break;
	case 24:
		sub_07E143(x, d, &y, &u, p_left_caller);
		break;
	}
	if (*p_left_caller != 0u)
		*p_left_caller = 0u;
	else if (mem_read8(x) != 0u)
		u = sub_07CDE9(x, u);
	*p_y = y;
	*p_u = u;
}

void sub_07D6B2(uint16_t x, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t d = 0;
	uint16_t u = 0;
	uint16_t t1 = 0;

	u = loaded_table_07F1AE_ADDRESS;
	t1 = mem_read16(x + 0x28u);
	d = (uint8_t)t1;
	switch ((int8_t)(uint8_t)((uint32_t)(t1 >> 8) << 1))
	{
	case 0:
		sub_07D6BE(x, d, &y, &u, p_left_caller);
		break;
	case 2:
		sub_07D6F7(x, d, &y, &u, p_left_caller);
		break;
	case 4:
		sub_07D721(x, d, &y, &u, p_left_caller);
		break;
	case 6:
		sub_07D74B(x, d, &y, &u, p_left_caller);
		break;
	case 8:
		sub_07D787(x, d, &y, &u, p_left_caller);
		break;
	case 10:
		sub_07D7A6(x, d, &y, &u, p_left_caller);
		break;
	case 12:
		sub_07D7C5(x, d, &y, &u, p_left_caller);
		break;
	case 14:
		sub_07D7CB(x, d, &y, &u, p_left_caller);
		break;
	case 16:
		u = sub_07D6C4(x);
		break;
	case 18:
	case 42:
		sub_07D6E0(x);
		break;
	case 20:
	case 26:
	case 32:
	case 38:
	case 44:
	case 50:
	case 56:
	case 62:
		sub_07D6E9(x);
		break;
	case 22:
		u = sub_07D6FD(x);
		break;
	case 24:
	case 48:
		sub_07D719(x);
		break;
	case 28:
		u = sub_07D727(x);
		break;
	case 30:
	case 54:
		sub_07D743(x);
		break;
	case 34:
		u = sub_07D751(x);
		break;
	case 36:
	case 60:
		sub_07D76D(x);
		break;
	case 40:
	case 52:
	case 58:
		sub_07D78D(x);
		break;
	case 46:
		sub_07D7AC(x);
		break;
	case 64:
		u = sub_07D806(x, u);
		break;
	case 66:
		u = sub_07D833(x, u);
		break;
	case 68:
		sub_07D87C(x);
		break;
	case 70:
	case 80:
		sub_07D99A(x);
		break;
	case 72:
		u = sub_07D886(x);
		break;
	case 74:
		sub_07D8E8(x);
		break;
	case 76:
		sub_07D8F3(x);
		break;
	case 78:
		u = sub_07D948(x, u);
		break;
	case 82:
		u = sub_07D9B9(x);
		break;
	case 84:
		sub_07DA0F(x);
		break;
	case 86:
		sub_07DA1A(x);
		break;
	case 88:
		u = sub_07DA71(x, u);
		break;
	case 90:
		sub_07DAC4(x);
		break;
	case 92:
		u = sub_07DAD8(x, u);
		break;
	case 94:
		sub_07DB35(x);
		break;
	case 96:
		u = sub_07DB4C(x, u);
		break;
	case 98:
		sub_07DBD8(x);
		break;
	case 100:
	case 106:
		u = sub_07DBF3(x);
		break;
	case 102:
		sub_07DB95(x);
		break;
	case 104:
		u = sub_07DBB3(x, u);
		break;
	case 108:
		sub_07DC09(x);
		break;
	case 110:
		sub_07DC35(x);
		break;
	case 112:
		u = sub_07DC4B(x, u);
		break;
	case 114:
		u = sub_07DC86(x, u);
		break;
	case 116:
		u = sub_07DCA2(x, u);
		break;
	case 118:
		u = sub_07DCD8(x, u);
		break;
	case 120:
		u = sub_07DCFB(x, u);
		break;
	case 122:
		sub_07DD11(x);
		break;
	case 124:
		sub_07DD3E(x);
		break;
	case 126:
		sub_07DD63(x);
		break;
	}
	u = sub_07CDE9(x, u);
	*p_y = y;
	*p_u = u;
}

void sub_07D6BE(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0, d_2 = 0;
	uint16_t u = 0;

	for (;;)
	{
		u = loaded_table_07F1BE_ADDRESS;
		b = (uint32_t)d << 1;
		switch ((int8_t)b)
		{
		case 0:
			u = sub_07D6C4(x);
			break;
		case 2:
		case 26:
			sub_07D6E0(x);
			break;
		case 4:
		case 10:
		case 16:
		case 22:
		case 28:
		case 34:
		case 40:
		case 46:
			sub_07D6E9(x);
			break;
		case 6:
			u = sub_07D6FD(x);
			break;
		case 8:
		case 32:
			sub_07D719(x);
			break;
		case 12:
			u = sub_07D727(x);
			break;
		case 14:
		case 38:
			sub_07D743(x);
			break;
		case 18:
			u = sub_07D751(x);
			break;
		case 20:
		case 44:
			sub_07D76D(x);
			break;
		case 24:
		case 36:
		case 42:
			sub_07D78D(x);
			break;
		case 30:
			sub_07D7AC(x);
			break;
		case 48:
			u = sub_07D806(x, u);
			break;
		case 50:
			u = sub_07D833(x, u);
			break;
		case 52:
			sub_07D87C(x);
			break;
		case 54:
		case 64:
			sub_07D99A(x);
			break;
		case 56:
			u = sub_07D886(x);
			break;
		case 58:
			sub_07D8E8(x);
			break;
		case 60:
			sub_07D8F3(x);
			break;
		case 62:
			u = sub_07D948(x, u);
			break;
		case 66:
			u = sub_07D9B9(x);
			break;
		case 68:
		case 112:
			sub_07DA0F(x);
			break;
		case 70:
		case 114:
			sub_07DA1A(x);
			break;
		case 72:
			u = sub_07DA71(x, u);
			break;
		case 74:
			sub_07DAC4(x);
			break;
		case 76:
			u = sub_07DAD8(x, u);
			break;
		case 78:
			sub_07DB35(x);
			break;
		case 80:
			u = sub_07DB4C(x, u);
			break;
		case 82:
			sub_07DBD8(x);
			break;
		case 84:
		case 90:
			u = sub_07DBF3(x);
			break;
		case 86:
			sub_07DB95(x);
			break;
		case 88:
			u = sub_07DBB3(x, u);
			break;
		case 92:
			sub_07DC09(x);
			break;
		case 94:
			sub_07DC35(x);
			break;
		case 96:
			u = sub_07DC4B(x, u);
			break;
		case 98:
			u = sub_07DC86(x, u);
			break;
		case 100:
			u = sub_07DCA2(x, u);
			break;
		case 102:
			u = sub_07DCD8(x, u);
			break;
		case 104:
			u = sub_07DCFB(x, u);
			break;
		case 106:
			sub_07DD11(x);
			break;
		case 108:
			sub_07DD3E(x);
			break;
		case 110:
			sub_07DD63(x);
			break;
		case 116:
			sub_07DD7D(x);
			break;
		case 118:
			sub_07DDA0(x);
			break;
		case 120:
			sub_07DDB9(x);
			break;
		case -24:
			sub_07D6B2(x, &y, &u, p_left_caller);
			break;
		case -16:
			continue;
		case -14:
			d_2 = b;
			sub_07D6F7(x, d_2, &y, &u, p_left_caller);
			break;
		case -12:
			d_2 = b;
			sub_07D721(x, d_2, &y, &u, p_left_caller);
			break;
		case -10:
			d_2 = b;
			sub_07D74B(x, d_2, &y, &u, p_left_caller);
			break;
		case -8:
			d_2 = b;
			sub_07D787(x, d_2, &y, &u, p_left_caller);
			break;
		case -6:
			d_2 = b;
			sub_07D7A6(x, d_2, &y, &u, p_left_caller);
			break;
		case -4:
			d_2 = b;
			sub_07D7C5(x, d_2, &y, &u, p_left_caller);
			break;
		case -2:
			d_2 = b;
			sub_07D7CB(x, d_2, &y, &u, p_left_caller);
			break;
		}
		break;
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_07D6C4(uint16_t x)
{
	uint16_t d = 0, u = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 0x42u);
	if (t1 != 0u)
		mem_write8(x + 5u, 0x84u);
	t2 = mem_read8(x + 0x45u);
	d = (uint32_t)t2 << 8;
	u = sub_07CDD3(x, d);
	mem_write16(x + 0xFu, 0u);
	t3 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t3 + 1u);
	return u;
}

void sub_07D6E0(uint16_t x)
{
	mem_write16(x + 0x14u, rom_07FFC0_ADDRESS);
	sub_07D773(x);
}

void sub_07D6E9(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(x, 0xC0u);
	mem_write8(x + 2u, 2u);
	mem_write8(x + 0x3Bu, 0u);
}

void sub_07D6F7(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0, d_2 = 0;
	uint16_t u = 0;

	for (;;)
	{
		u = loaded_table_07F1C4_ADDRESS;
		b = (uint32_t)d << 1;
		switch ((int8_t)b)
		{
		case 0:
			u = sub_07D6FD(x);
			break;
		case 2:
		case 26:
			sub_07D719(x);
			break;
		case -2:
		case 4:
		case 10:
		case 16:
		case 22:
		case 28:
		case 34:
		case 40:
			sub_07D6E9(x);
			break;
		case 6:
			u = sub_07D727(x);
			break;
		case 8:
		case 32:
			sub_07D743(x);
			break;
		case 12:
			u = sub_07D751(x);
			break;
		case 14:
		case 38:
			sub_07D76D(x);
			break;
		case 18:
		case 30:
		case 36:
			sub_07D78D(x);
			break;
		case -4:
		case 20:
			sub_07D6E0(x);
			break;
		case 24:
			sub_07D7AC(x);
			break;
		case 42:
			u = sub_07D806(x, u);
			break;
		case 44:
			u = sub_07D833(x, u);
			break;
		case 46:
			sub_07D87C(x);
			break;
		case 48:
		case 58:
			sub_07D99A(x);
			break;
		case 50:
			u = sub_07D886(x);
			break;
		case 52:
			sub_07D8E8(x);
			break;
		case 54:
			sub_07D8F3(x);
			break;
		case 56:
			u = sub_07D948(x, u);
			break;
		case 60:
			u = sub_07D9B9(x);
			break;
		case 62:
		case 106:
			sub_07DA0F(x);
			break;
		case 64:
		case 108:
			sub_07DA1A(x);
			break;
		case 66:
			u = sub_07DA71(x, u);
			break;
		case 68:
			sub_07DAC4(x);
			break;
		case 70:
			u = sub_07DAD8(x, u);
			break;
		case 72:
			sub_07DB35(x);
			break;
		case 74:
			u = sub_07DB4C(x, u);
			break;
		case 76:
			sub_07DBD8(x);
			break;
		case 78:
		case 84:
			u = sub_07DBF3(x);
			break;
		case 80:
			sub_07DB95(x);
			break;
		case 82:
			u = sub_07DBB3(x, u);
			break;
		case 86:
			sub_07DC09(x);
			break;
		case 88:
			sub_07DC35(x);
			break;
		case 90:
			u = sub_07DC4B(x, u);
			break;
		case 92:
			u = sub_07DC86(x, u);
			break;
		case 94:
			u = sub_07DCA2(x, u);
			break;
		case 96:
			u = sub_07DCD8(x, u);
			break;
		case 98:
			u = sub_07DCFB(x, u);
			break;
		case 100:
			sub_07DD11(x);
			break;
		case 102:
			sub_07DD3E(x);
			break;
		case 104:
			sub_07DD63(x);
			break;
		case 110:
			sub_07DD7D(x);
			break;
		case 112:
			sub_07DDA0(x);
			break;
		case 114:
			sub_07DDB9(x);
			break;
		case -32:
			sub_07D667(x, &y, &u, p_left_caller);
			break;
		case -22:
			d_2 = b;
			sub_07D6BE(x, d_2, &y, &u, p_left_caller);
			break;
		case -20:
			continue;
		case -18:
			d_2 = b;
			sub_07D721(x, d_2, &y, &u, p_left_caller);
			break;
		case -16:
			d_2 = b;
			sub_07D74B(x, d_2, &y, &u, p_left_caller);
			break;
		case -14:
			d_2 = b;
			sub_07D787(x, d_2, &y, &u, p_left_caller);
			break;
		case -12:
			d_2 = b;
			sub_07D7A6(x, d_2, &y, &u, p_left_caller);
			break;
		case -10:
			d_2 = b;
			sub_07D7C5(x, d_2, &y, &u, p_left_caller);
			break;
		case -8:
			d_2 = b;
			sub_07D7CB(x, d_2, &y, &u, p_left_caller);
			break;
		case -6:
			u = sub_07D6C4(x);
			break;
		}
		break;
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_07D6FD(uint16_t x)
{
	uint16_t d = 0, u = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 0x42u);
	if (t1 != 0u)
		mem_write8(x + 5u, 0x85u);
	t2 = mem_read8(x + 0x45u);
	d = (uint32_t)t2 << 8;
	u = sub_07CDD3(x, d);
	mem_write16(x + 0xFu, 0u);
	t3 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t3 + 1u);
	return u;
}

void sub_07D719(uint16_t x)
{
	mem_write16(x + 0x14u, 0x40u);
	sub_07D773(x);
}

void sub_07D721(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0, d_2 = 0;
	uint16_t u = 0;

	for (;;)
	{
		u = loaded_table_07F1CA_ADDRESS;
		b = (uint32_t)d << 1;
		switch ((int8_t)b)
		{
		case 0:
			u = sub_07D727(x);
			break;
		case 2:
		case 26:
			sub_07D743(x);
			break;
		case -8:
		case -2:
		case 4:
		case 10:
		case 16:
		case 22:
		case 28:
		case 34:
			sub_07D6E9(x);
			break;
		case 6:
			u = sub_07D751(x);
			break;
		case 8:
		case 32:
			sub_07D76D(x);
			break;
		case 12:
		case 24:
		case 30:
			sub_07D78D(x);
			break;
		case -10:
		case 14:
			sub_07D6E0(x);
			break;
		case 18:
			sub_07D7AC(x);
			break;
		case -4:
		case 20:
			sub_07D719(x);
			break;
		case 36:
			u = sub_07D806(x, u);
			break;
		case 38:
			u = sub_07D833(x, u);
			break;
		case 40:
			sub_07D87C(x);
			break;
		case 42:
		case 52:
			sub_07D99A(x);
			break;
		case 44:
			u = sub_07D886(x);
			break;
		case 46:
			sub_07D8E8(x);
			break;
		case 48:
			sub_07D8F3(x);
			break;
		case 50:
			u = sub_07D948(x, u);
			break;
		case 54:
			u = sub_07D9B9(x);
			break;
		case 56:
		case 100:
			sub_07DA0F(x);
			break;
		case 58:
		case 102:
			sub_07DA1A(x);
			break;
		case 60:
			u = sub_07DA71(x, u);
			break;
		case 62:
			sub_07DAC4(x);
			break;
		case 64:
			u = sub_07DAD8(x, u);
			break;
		case 66:
			sub_07DB35(x);
			break;
		case 68:
			u = sub_07DB4C(x, u);
			break;
		case 70:
			sub_07DBD8(x);
			break;
		case 72:
		case 78:
			u = sub_07DBF3(x);
			break;
		case 74:
			sub_07DB95(x);
			break;
		case 76:
			u = sub_07DBB3(x, u);
			break;
		case 80:
			sub_07DC09(x);
			break;
		case 82:
			sub_07DC35(x);
			break;
		case 84:
			u = sub_07DC4B(x, u);
			break;
		case 86:
			u = sub_07DC86(x, u);
			break;
		case 88:
			u = sub_07DCA2(x, u);
			break;
		case 90:
			u = sub_07DCD8(x, u);
			break;
		case 92:
			u = sub_07DCFB(x, u);
			break;
		case 94:
			sub_07DD11(x);
			break;
		case 96:
			sub_07DD3E(x);
			break;
		case 98:
			sub_07DD63(x);
			break;
		case 104:
			sub_07DD7D(x);
			break;
		case 106:
			sub_07DDA0(x);
			break;
		case 108:
			sub_07DDB9(x);
			break;
		case -28:
			d_2 = b;
			sub_07D6BE(x, d_2, &y, &u, p_left_caller);
			break;
		case -26:
			d_2 = b;
			sub_07D6F7(x, d_2, &y, &u, p_left_caller);
			break;
		case -24:
			continue;
		case -22:
			d_2 = b;
			sub_07D74B(x, d_2, &y, &u, p_left_caller);
			break;
		case -20:
			d_2 = b;
			sub_07D787(x, d_2, &y, &u, p_left_caller);
			break;
		case -18:
			d_2 = b;
			sub_07D7A6(x, d_2, &y, &u, p_left_caller);
			break;
		case -16:
			d_2 = b;
			sub_07D7C5(x, d_2, &y, &u, p_left_caller);
			break;
		case -14:
			d_2 = b;
			sub_07D7CB(x, d_2, &y, &u, p_left_caller);
			break;
		case -12:
			u = sub_07D6C4(x);
			break;
		case -6:
			u = sub_07D6FD(x);
			break;
		}
		break;
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_07D727(uint16_t x)
{
	uint16_t d = 0, u = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 0x42u);
	if (t1 != 0u)
		mem_write8(x + 5u, 0x84u);
	t2 = mem_read8(x + 0x45u);
	d = (uint32_t)t2 << 8;
	u = sub_07CDD3(x, d);
	mem_write16(x + 0x14u, 0u);
	t3 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t3 + 1u);
	return u;
}

void sub_07D743(uint16_t x)
{
	mem_write16(x + 0xFu, 0xFF80u);
	sub_07D773(x);
}

void sub_07D74B(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0, d_2 = 0;
	uint16_t u = 0;

	for (;;)
	{
		u = loaded_table_07F1D0_ADDRESS;
		b = (uint32_t)d << 1;
		switch ((int8_t)b)
		{
		case 0:
			u = sub_07D751(x);
			break;
		case 2:
		case 26:
			sub_07D76D(x);
			break;
		case -14:
		case -8:
		case -2:
		case 4:
		case 10:
		case 16:
		case 22:
		case 28:
			sub_07D6E9(x);
			break;
		case 6:
		case 18:
		case 24:
			sub_07D78D(x);
			break;
		case -16:
		case 8:
			sub_07D6E0(x);
			break;
		case 12:
			sub_07D7AC(x);
			break;
		case -10:
		case 14:
			sub_07D719(x);
			break;
		case -4:
		case 20:
			sub_07D743(x);
			break;
		case 30:
			u = sub_07D806(x, u);
			break;
		case 32:
			u = sub_07D833(x, u);
			break;
		case 34:
			sub_07D87C(x);
			break;
		case 36:
		case 46:
			sub_07D99A(x);
			break;
		case 38:
			u = sub_07D886(x);
			break;
		case 40:
			sub_07D8E8(x);
			break;
		case 42:
			sub_07D8F3(x);
			break;
		case 44:
			u = sub_07D948(x, u);
			break;
		case 48:
			u = sub_07D9B9(x);
			break;
		case 50:
		case 94:
			sub_07DA0F(x);
			break;
		case 52:
		case 96:
			sub_07DA1A(x);
			break;
		case 54:
			u = sub_07DA71(x, u);
			break;
		case 56:
			sub_07DAC4(x);
			break;
		case 58:
			u = sub_07DAD8(x, u);
			break;
		case 60:
			sub_07DB35(x);
			break;
		case 62:
			u = sub_07DB4C(x, u);
			break;
		case 64:
			sub_07DBD8(x);
			break;
		case 66:
		case 72:
			u = sub_07DBF3(x);
			break;
		case 68:
			sub_07DB95(x);
			break;
		case 70:
			u = sub_07DBB3(x, u);
			break;
		case 74:
			sub_07DC09(x);
			break;
		case 76:
			sub_07DC35(x);
			break;
		case 78:
			u = sub_07DC4B(x, u);
			break;
		case 80:
			u = sub_07DC86(x, u);
			break;
		case 82:
			u = sub_07DCA2(x, u);
			break;
		case 84:
			u = sub_07DCD8(x, u);
			break;
		case 86:
			u = sub_07DCFB(x, u);
			break;
		case 88:
			sub_07DD11(x);
			break;
		case 90:
			sub_07DD3E(x);
			break;
		case 92:
			sub_07DD63(x);
			break;
		case 98:
			sub_07DD7D(x);
			break;
		case 100:
			sub_07DDA0(x);
			break;
		case 102:
			sub_07DDB9(x);
			break;
		case -48:
			sub_07D49C(x, &y, &u, p_left_caller);
			break;
		case -34:
			d_2 = b;
			sub_07D6BE(x, d_2, &y, &u, p_left_caller);
			break;
		case -32:
			d_2 = b;
			sub_07D6F7(x, d_2, &y, &u, p_left_caller);
			break;
		case -30:
			d_2 = b;
			sub_07D721(x, d_2, &y, &u, p_left_caller);
			break;
		case -28:
			continue;
		case -26:
			d_2 = b;
			sub_07D787(x, d_2, &y, &u, p_left_caller);
			break;
		case -24:
			d_2 = b;
			sub_07D7A6(x, d_2, &y, &u, p_left_caller);
			break;
		case -22:
			d_2 = b;
			sub_07D7C5(x, d_2, &y, &u, p_left_caller);
			break;
		case -20:
			d_2 = b;
			sub_07D7CB(x, d_2, &y, &u, p_left_caller);
			break;
		case -18:
			u = sub_07D6C4(x);
			break;
		case -12:
			u = sub_07D6FD(x);
			break;
		case -6:
			u = sub_07D727(x);
			break;
		}
		break;
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_07D751(uint16_t x)
{
	uint16_t d = 0, u = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 0x42u);
	if (t1 != 0u)
		mem_write8(x + 5u, 0x84u);
	t2 = mem_read8(x + 0x45u);
	d = (uint32_t)t2 << 8;
	u = sub_07CDD3(x, d);
	mem_write16(x + 0x14u, 0u);
	t3 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t3 + 1u);
	return u;
}

void sub_07D76D(uint16_t x)
{
	mem_write16(x + 0xFu, 0x80u);
	sub_07D773(x);
}

void sub_07D773(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;
	uint8_t t1 = 0;

	sub_07D16E(x, &ignored16, &carry);
	if (carry)
	{
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
		mem_write8(x + 0x3Bu, 4u);
		t1 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t1 + 1u);
	}
}

void sub_07D787(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0, d_2 = 0;
	uint16_t u = 0;

	for (;;)
	{
		u = loaded_table_07F1D6_ADDRESS;
		b = (uint32_t)d << 1;
		switch ((int8_t)b)
		{
		case 0:
		case 12:
		case 18:
			sub_07D78D(x);
			break;
		case -22:
		case 2:
			sub_07D6E0(x);
			break;
		case -20:
		case -14:
		case -8:
		case -2:
		case 4:
		case 10:
		case 16:
		case 22:
			sub_07D6E9(x);
			break;
		case 6:
			sub_07D7AC(x);
			break;
		case -16:
		case 8:
			sub_07D719(x);
			break;
		case -10:
		case 14:
			sub_07D743(x);
			break;
		case -4:
		case 20:
			sub_07D76D(x);
			break;
		case 24:
			u = sub_07D806(x, u);
			break;
		case 26:
			u = sub_07D833(x, u);
			break;
		case 28:
			sub_07D87C(x);
			break;
		case 30:
		case 40:
			sub_07D99A(x);
			break;
		case 32:
			u = sub_07D886(x);
			break;
		case 34:
			sub_07D8E8(x);
			break;
		case 36:
			sub_07D8F3(x);
			break;
		case 38:
			u = sub_07D948(x, u);
			break;
		case 42:
			u = sub_07D9B9(x);
			break;
		case 44:
		case 88:
			sub_07DA0F(x);
			break;
		case 46:
		case 90:
			sub_07DA1A(x);
			break;
		case 48:
			u = sub_07DA71(x, u);
			break;
		case 50:
			sub_07DAC4(x);
			break;
		case 52:
			u = sub_07DAD8(x, u);
			break;
		case 54:
			sub_07DB35(x);
			break;
		case 56:
			u = sub_07DB4C(x, u);
			break;
		case 58:
			sub_07DBD8(x);
			break;
		case 60:
		case 66:
			u = sub_07DBF3(x);
			break;
		case 62:
			sub_07DB95(x);
			break;
		case 64:
			u = sub_07DBB3(x, u);
			break;
		case 68:
			sub_07DC09(x);
			break;
		case 70:
			sub_07DC35(x);
			break;
		case 72:
			u = sub_07DC4B(x, u);
			break;
		case 74:
			u = sub_07DC86(x, u);
			break;
		case 76:
			u = sub_07DCA2(x, u);
			break;
		case 78:
			u = sub_07DCD8(x, u);
			break;
		case 80:
			u = sub_07DCFB(x, u);
			break;
		case 82:
			sub_07DD11(x);
			break;
		case 84:
			sub_07DD3E(x);
			break;
		case 86:
			sub_07DD63(x);
			break;
		case 92:
			sub_07DD7D(x);
			break;
		case 94:
			sub_07DDA0(x);
			break;
		case 96:
			sub_07DDB9(x);
			break;
		case -48:
			sub_07D6B2(x, &y, &u, p_left_caller);
			break;
		case -40:
			d_2 = b;
			sub_07D6BE(x, d_2, &y, &u, p_left_caller);
			break;
		case -38:
			d_2 = b;
			sub_07D6F7(x, d_2, &y, &u, p_left_caller);
			break;
		case -36:
			d_2 = b;
			sub_07D721(x, d_2, &y, &u, p_left_caller);
			break;
		case -34:
			d_2 = b;
			sub_07D74B(x, d_2, &y, &u, p_left_caller);
			break;
		case -32:
			continue;
		case -30:
			d_2 = b;
			sub_07D7A6(x, d_2, &y, &u, p_left_caller);
			break;
		case -28:
			d_2 = b;
			sub_07D7C5(x, d_2, &y, &u, p_left_caller);
			break;
		case -26:
			d_2 = b;
			sub_07D7CB(x, d_2, &y, &u, p_left_caller);
			break;
		case -24:
			u = sub_07D6C4(x);
			break;
		case -18:
			u = sub_07D6FD(x);
			break;
		case -12:
			u = sub_07D727(x);
			break;
		case -6:
			u = sub_07D751(x);
			break;
		}
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_07D78D(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 0x42u);
	if (t1 != 0u)
		mem_write8(x + 5u, 0x84u);
	mem_write16(x + 0x19u, 0x600u);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
}

void sub_07D7A6(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0, d_2 = 0;
	uint16_t u = 0;

	for (;;)
	{
		u = loaded_table_07F1DC_ADDRESS;
		b = (uint32_t)d << 1;
		switch ((int8_t)b)
		{
		case 0:
			sub_07D7AC(x);
			break;
		case -22:
		case 2:
			sub_07D719(x);
			break;
		case -26:
		case -20:
		case -14:
		case -8:
		case -2:
		case 4:
		case 10:
		case 16:
			sub_07D6E9(x);
			break;
		case -6:
		case 6:
		case 12:
			sub_07D78D(x);
			break;
		case -16:
		case 8:
			sub_07D743(x);
			break;
		case -10:
		case 14:
			sub_07D76D(x);
			break;
		case 18:
			u = sub_07D806(x, u);
			break;
		case 20:
			u = sub_07D833(x, u);
			break;
		case 22:
			sub_07D87C(x);
			break;
		case 24:
		case 34:
			sub_07D99A(x);
			break;
		case 26:
			u = sub_07D886(x);
			break;
		case 28:
			sub_07D8E8(x);
			break;
		case 30:
			sub_07D8F3(x);
			break;
		case 32:
			u = sub_07D948(x, u);
			break;
		case 36:
			u = sub_07D9B9(x);
			break;
		case 38:
		case 82:
			sub_07DA0F(x);
			break;
		case 40:
		case 84:
			sub_07DA1A(x);
			break;
		case 42:
			u = sub_07DA71(x, u);
			break;
		case 44:
			sub_07DAC4(x);
			break;
		case 46:
			u = sub_07DAD8(x, u);
			break;
		case 48:
			sub_07DB35(x);
			break;
		case 50:
			u = sub_07DB4C(x, u);
			break;
		case 52:
			sub_07DBD8(x);
			break;
		case 54:
		case 60:
			u = sub_07DBF3(x);
			break;
		case 56:
			sub_07DB95(x);
			break;
		case 58:
			u = sub_07DBB3(x, u);
			break;
		case 62:
			sub_07DC09(x);
			break;
		case 64:
			sub_07DC35(x);
			break;
		case 66:
			u = sub_07DC4B(x, u);
			break;
		case 68:
			u = sub_07DC86(x, u);
			break;
		case 70:
			u = sub_07DCA2(x, u);
			break;
		case 72:
			u = sub_07DCD8(x, u);
			break;
		case 74:
			u = sub_07DCFB(x, u);
			break;
		case 76:
			sub_07DD11(x);
			break;
		case 78:
			sub_07DD3E(x);
			break;
		case 80:
			sub_07DD63(x);
			break;
		case 86:
			sub_07DD7D(x);
			break;
		case 88:
			sub_07DDA0(x);
			break;
		case 90:
			sub_07DDB9(x);
			break;
		case -46:
			d_2 = b;
			sub_07D6BE(x, d_2, &y, &u, p_left_caller);
			break;
		case -44:
			d_2 = b;
			sub_07D6F7(x, d_2, &y, &u, p_left_caller);
			break;
		case -42:
			d_2 = b;
			sub_07D721(x, d_2, &y, &u, p_left_caller);
			break;
		case -40:
			d_2 = b;
			sub_07D74B(x, d_2, &y, &u, p_left_caller);
			break;
		case -38:
			d_2 = b;
			sub_07D787(x, d_2, &y, &u, p_left_caller);
			break;
		case -36:
			continue;
		case -34:
			d_2 = b;
			sub_07D7C5(x, d_2, &y, &u, p_left_caller);
			break;
		case -32:
			d_2 = b;
			sub_07D7CB(x, d_2, &y, &u, p_left_caller);
			break;
		case -30:
			u = sub_07D6C4(x);
			break;
		case -28:
		case -4:
			sub_07D6E0(x);
			break;
		case -24:
			u = sub_07D6FD(x);
			break;
		case -18:
			u = sub_07D727(x);
			break;
		case -12:
			u = sub_07D751(x);
			break;
		}
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_07D7AC(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 0x42u);
	if (t1 != 0u)
		mem_write8(x + 5u, 0x85u);
	mem_write16(x + 0x19u, 0x600u);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
}

void sub_07D7C5(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0, d_2 = 0;
	uint16_t u = 0;

	for (;;)
	{
		u = loaded_table_07F1E2_ADDRESS;
		b = (uint32_t)d << 1;
		switch ((int8_t)b)
		{
		case -12:
		case 0:
		case 6:
			sub_07D78D(x);
			break;
		case -22:
		case 2:
			sub_07D743(x);
			break;
		case -32:
		case -26:
		case -20:
		case -14:
		case -8:
		case -2:
		case 4:
		case 10:
			sub_07D6E9(x);
			break;
		case -16:
		case 8:
			sub_07D76D(x);
			break;
		case 12:
			u = sub_07D806(x, u);
			break;
		case 14:
			u = sub_07D833(x, u);
			break;
		case 16:
			sub_07D87C(x);
			break;
		case 18:
		case 28:
			sub_07D99A(x);
			break;
		case 20:
			u = sub_07D886(x);
			break;
		case 22:
			sub_07D8E8(x);
			break;
		case 24:
			sub_07D8F3(x);
			break;
		case 26:
			u = sub_07D948(x, u);
			break;
		case 30:
			u = sub_07D9B9(x);
			break;
		case 32:
		case 76:
			sub_07DA0F(x);
			break;
		case 34:
		case 78:
			sub_07DA1A(x);
			break;
		case 36:
			u = sub_07DA71(x, u);
			break;
		case 38:
			sub_07DAC4(x);
			break;
		case 40:
			u = sub_07DAD8(x, u);
			break;
		case 42:
			sub_07DB35(x);
			break;
		case 44:
			u = sub_07DB4C(x, u);
			break;
		case 46:
			sub_07DBD8(x);
			break;
		case 48:
		case 54:
			u = sub_07DBF3(x);
			break;
		case 50:
			sub_07DB95(x);
			break;
		case 52:
			u = sub_07DBB3(x, u);
			break;
		case 56:
			sub_07DC09(x);
			break;
		case 58:
			sub_07DC35(x);
			break;
		case 60:
			u = sub_07DC4B(x, u);
			break;
		case 62:
			u = sub_07DC86(x, u);
			break;
		case 64:
			u = sub_07DCA2(x, u);
			break;
		case 66:
			u = sub_07DCD8(x, u);
			break;
		case 68:
			u = sub_07DCFB(x, u);
			break;
		case 70:
			sub_07DD11(x);
			break;
		case 72:
			sub_07DD3E(x);
			break;
		case 74:
			sub_07DD63(x);
			break;
		case 80:
			sub_07DD7D(x);
			break;
		case 82:
			sub_07DDA0(x);
			break;
		case 84:
			sub_07DDB9(x);
			break;
		case -64:
			sub_07D63B(x, &y, &u, p_left_caller);
			break;
		case -52:
			d_2 = b;
			sub_07D6BE(x, d_2, &y, &u, p_left_caller);
			break;
		case -50:
			d_2 = b;
			sub_07D6F7(x, d_2, &y, &u, p_left_caller);
			break;
		case -48:
			d_2 = b;
			sub_07D721(x, d_2, &y, &u, p_left_caller);
			break;
		case -46:
			d_2 = b;
			sub_07D74B(x, d_2, &y, &u, p_left_caller);
			break;
		case -44:
			d_2 = b;
			sub_07D787(x, d_2, &y, &u, p_left_caller);
			break;
		case -42:
			d_2 = b;
			sub_07D7A6(x, d_2, &y, &u, p_left_caller);
			break;
		case -40:
			continue;
		case -38:
			d_2 = b;
			sub_07D7CB(x, d_2, &y, &u, p_left_caller);
			break;
		case -36:
			u = sub_07D6C4(x);
			break;
		case -34:
		case -10:
			sub_07D6E0(x);
			break;
		case -30:
			u = sub_07D6FD(x);
			break;
		case -28:
		case -4:
			sub_07D719(x);
			break;
		case -24:
			u = sub_07D727(x);
			break;
		case -18:
			u = sub_07D751(x);
			break;
		case -6:
			sub_07D7AC(x);
			break;
		}
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_07D7CB(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0, d_2 = 0;
	uint16_t u = 0;

	for (;;)
	{
		u = loaded_table_07F1E8_ADDRESS;
		b = (uint32_t)d << 1;
		switch ((int8_t)b)
		{
		case -18:
		case -6:
		case 0:
			sub_07D78D(x);
			break;
		case -22:
		case 2:
			sub_07D76D(x);
			break;
		case -38:
		case -32:
		case -26:
		case -20:
		case -14:
		case -8:
		case -2:
		case 4:
			sub_07D6E9(x);
			break;
		case 6:
			u = sub_07D806(x, u);
			break;
		case 8:
			u = sub_07D833(x, u);
			break;
		case 10:
			sub_07D87C(x);
			break;
		case 12:
		case 22:
			sub_07D99A(x);
			break;
		case 14:
			u = sub_07D886(x);
			break;
		case 16:
			sub_07D8E8(x);
			break;
		case 18:
			sub_07D8F3(x);
			break;
		case 20:
			u = sub_07D948(x, u);
			break;
		case 24:
			u = sub_07D9B9(x);
			break;
		case 26:
		case 70:
			sub_07DA0F(x);
			break;
		case 28:
		case 72:
			sub_07DA1A(x);
			break;
		case 30:
			u = sub_07DA71(x, u);
			break;
		case 32:
			sub_07DAC4(x);
			break;
		case 34:
			u = sub_07DAD8(x, u);
			break;
		case 36:
			sub_07DB35(x);
			break;
		case 38:
			u = sub_07DB4C(x, u);
			break;
		case 40:
			sub_07DBD8(x);
			break;
		case 42:
		case 48:
			u = sub_07DBF3(x);
			break;
		case 44:
			sub_07DB95(x);
			break;
		case 46:
			u = sub_07DBB3(x, u);
			break;
		case 50:
			sub_07DC09(x);
			break;
		case 52:
			sub_07DC35(x);
			break;
		case 54:
			u = sub_07DC4B(x, u);
			break;
		case 56:
			u = sub_07DC86(x, u);
			break;
		case 58:
			u = sub_07DCA2(x, u);
			break;
		case 60:
			u = sub_07DCD8(x, u);
			break;
		case 62:
			u = sub_07DCFB(x, u);
			break;
		case 64:
			sub_07DD11(x);
			break;
		case 66:
			sub_07DD3E(x);
			break;
		case 68:
			sub_07DD63(x);
			break;
		case 74:
			sub_07DD7D(x);
			break;
		case 76:
			sub_07DDA0(x);
			break;
		case 78:
			sub_07DDB9(x);
			break;
		case 96:
			sub_07DDC9(x);
			break;
		case 112:
			sub_07DEBA(x);
			break;
		case -58:
			d_2 = b;
			sub_07D6BE(x, d_2, &y, &u, p_left_caller);
			break;
		case -56:
			d_2 = b;
			sub_07D6F7(x, d_2, &y, &u, p_left_caller);
			break;
		case -54:
			d_2 = b;
			sub_07D721(x, d_2, &y, &u, p_left_caller);
			break;
		case -52:
			d_2 = b;
			sub_07D74B(x, d_2, &y, &u, p_left_caller);
			break;
		case -50:
			d_2 = b;
			sub_07D787(x, d_2, &y, &u, p_left_caller);
			break;
		case -48:
			d_2 = b;
			sub_07D7A6(x, d_2, &y, &u, p_left_caller);
			break;
		case -46:
			d_2 = b;
			sub_07D7C5(x, d_2, &y, &u, p_left_caller);
			break;
		case -44:
			continue;
		case -42:
			u = sub_07D6C4(x);
			break;
		case -40:
		case -16:
			sub_07D6E0(x);
			break;
		case -36:
			u = sub_07D6FD(x);
			break;
		case -34:
		case -10:
			sub_07D719(x);
			break;
		case -30:
			u = sub_07D727(x);
			break;
		case -28:
		case -4:
			sub_07D743(x);
			break;
		case -24:
			u = sub_07D751(x);
			break;
		case -12:
			sub_07D7AC(x);
			break;
		}
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_07D7D1(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x42u);
	if (t1 != 0u)
	{
		sub_07D2A2(x);
		return;
	}
	sub_07D249(x);
}

void sub_07D7DA(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x42u);
	if (t1 != 0u)
	{
		sub_07D268(x);
		return;
	}
	sub_07D249(x);
}

void unreached_07D7E3(uint16_t x)
{
	uint8_t a = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;
	uint16_t t3 = 0;

	t1 = mem_read8(x + 0x36u);
	a = t1;
	t2 = mem_read8(x + 0x3Du);
	if (t2 != 0u)
		a += 0x60u;
	else
		a -= 0x20u;
	d = ((uint32_t)a << 8) | 0x30u;
	sub_07CC8E(x, d);
	t3 = mem_read16(x + 0x14u);
	mem_write16(x + 0x14u, (int16_t)t3 >> 1);
}

void sub_07D7FA(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0, d_2 = 0;
	uint16_t u = 0;
	uint8_t t1 = 0;

	u = loaded_table_07F1EE_ADDRESS;
	b = (uint32_t)d << 1;
	d_2 = b;
	switch ((int8_t)b)
	{
	case 0:
		u = sub_07D806(x, u);
		break;
	case 2:
		u = sub_07D833(x, u);
		break;
	case 4:
		sub_07D87C(x);
		break;
	case 6:
	case 16:
		sub_07D99A(x);
		break;
	case 8:
		u = sub_07D886(x);
		break;
	case 10:
		sub_07D8E8(x);
		break;
	case 12:
		sub_07D8F3(x);
		break;
	case 14:
		u = sub_07D948(x, u);
		break;
	case 18:
		u = sub_07D9B9(x);
		break;
	case 20:
	case 64:
		sub_07DA0F(x);
		break;
	case 22:
	case 66:
		sub_07DA1A(x);
		break;
	case 24:
		u = sub_07DA71(x, u);
		break;
	case 26:
		sub_07DAC4(x);
		break;
	case 28:
		u = sub_07DAD8(x, u);
		break;
	case 30:
		sub_07DB35(x);
		break;
	case 32:
		u = sub_07DB4C(x, u);
		break;
	case 34:
		sub_07DBD8(x);
		break;
	case 36:
	case 42:
		u = sub_07DBF3(x);
		break;
	case 38:
		sub_07DB95(x);
		break;
	case 40:
		u = sub_07DBB3(x, u);
		break;
	case 44:
		sub_07DC09(x);
		break;
	case 46:
		sub_07DC35(x);
		break;
	case 48:
		u = sub_07DC4B(x, u);
		break;
	case 50:
		u = sub_07DC86(x, u);
		break;
	case 52:
		u = sub_07DCA2(x, u);
		break;
	case 54:
		u = sub_07DCD8(x, u);
		break;
	case 56:
		u = sub_07DCFB(x, u);
		break;
	case 58:
		sub_07DD11(x);
		break;
	case 60:
		sub_07DD3E(x);
		break;
	case 62:
		sub_07DD63(x);
		break;
	case 68:
		sub_07DD7D(x);
		break;
	case 70:
		sub_07DDA0(x);
		break;
	case 72:
		sub_07DDB9(x);
		break;
	case -64:
		sub_07D6BE(x, d_2, &y, &u, p_left_caller);
		break;
	case -62:
		sub_07D6F7(x, d_2, &y, &u, p_left_caller);
		break;
	case -60:
		sub_07D721(x, d_2, &y, &u, p_left_caller);
		break;
	case -58:
		sub_07D74B(x, d_2, &y, &u, p_left_caller);
		break;
	case -56:
		sub_07D787(x, d_2, &y, &u, p_left_caller);
		break;
	case -54:
		sub_07D7A6(x, d_2, &y, &u, p_left_caller);
		break;
	case -52:
		sub_07D7C5(x, d_2, &y, &u, p_left_caller);
		break;
	case -50:
		sub_07D7CB(x, d_2, &y, &u, p_left_caller);
		break;
	case -48:
		u = sub_07D6C4(x);
		break;
	case -46:
	case -22:
		sub_07D6E0(x);
		break;
	case -44:
	case -38:
	case -32:
	case -26:
	case -20:
	case -14:
	case -8:
	case -2:
		sub_07D6E9(x);
		break;
	case -42:
		u = sub_07D6FD(x);
		break;
	case -40:
	case -16:
		sub_07D719(x);
		break;
	case -36:
		u = sub_07D727(x);
		break;
	case -34:
	case -10:
		sub_07D743(x);
		break;
	case -30:
		u = sub_07D751(x);
		break;
	case -28:
	case -4:
		sub_07D76D(x);
		break;
	case -24:
	case -12:
	case -6:
		sub_07D78D(x);
		break;
	case -18:
		sub_07D7AC(x);
		break;
	}
	t1 = mem_read8(x + 0x29u);
	if (t1 != 0u)
		sub_07D7D1(x);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_07D806(uint16_t x, uint16_t u)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x42u);
	if (t1 == 0u)
		mem_write8(x + 5u, 0x81u);
	else
		sub_07D25D(x);
	mem_write8(x + 0x3Bu, 0x60u);
	mem_write8(x + VIDEO_003C, 3u);
	if ((int8_t)unk_4858 >= 0)
		mem_write8(x + 0x3Du, 0xFFu);
	else
		mem_write8(x + 0x3Du, 0u);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	return sub_07DC71(x, u);
}

uint16_t sub_07D833(uint16_t x, uint16_t u)
{
	uint16_t u_2 = 0;
	uint8_t t1 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		t2 = mem_read16(x + 0x38u);
		u_2 = t2;
		sub_07D10E(x, u_2);
		return u_2;
	}
	t3 = mem_read8(x + VIDEO_0031);
	if ((int8_t)t3 >= 0)
	{
		t4 = mem_read8(x + 0x36u);
		t5 = mem_read8(x + 0x35u);
		if (t4 != t5)
			return sub_07DC71(x, u);
		return u;
	}
	t6 = mem_read8(x + VIDEO_003C);
	mem_write8(x + VIDEO_003C, t6 - 1u);
	if (t6 != 1u)
	{
		t7 = mem_read8(x + 0x3Du);
		mem_write8(x + 0x3Du, ~t7);
		return sub_07DC71(x, u);
	}
	mem_write8(x + 0x3Bu, 0x10u);
	t8 = mem_read8(x + VIDEO_0031);
	if ((t8 & 2u) != 0u)
	{
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0xFF00u);
	}
	else
	{
		mem_write16(x + 0xFu, 0x100u);
		mem_write16(x + 0x14u, 0u);
	}
	t9 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t9 + 1u);
	return u;
}

void sub_07D87C(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
}

void sub_07D880(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0, d_2 = 0;
	uint16_t u = 0;

	u = loaded_table_07F1F4_ADDRESS;
	b = (uint32_t)d << 1;
	switch ((int8_t)b)
	{
	case 0:
	case 10:
		sub_07D99A(x);
		break;
	case 2:
		u = sub_07D886(x);
		break;
	case 4:
		sub_07D8E8(x);
		break;
	case 6:
		sub_07D8F3(x);
		break;
	case 8:
		u = sub_07D948(x, u);
		break;
	case 12:
		u = sub_07D9B9(x);
		break;
	case 14:
	case 58:
		sub_07DA0F(x);
		break;
	case 16:
	case 60:
		sub_07DA1A(x);
		break;
	case 18:
		u = sub_07DA71(x, u);
		break;
	case 20:
		sub_07DAC4(x);
		break;
	case 22:
		u = sub_07DAD8(x, u);
		break;
	case 24:
		sub_07DB35(x);
		break;
	case 26:
		u = sub_07DB4C(x, u);
		break;
	case 28:
		sub_07DBD8(x);
		break;
	case 30:
	case 36:
		u = sub_07DBF3(x);
		break;
	case 32:
		sub_07DB95(x);
		break;
	case 34:
		u = sub_07DBB3(x, u);
		break;
	case 38:
		sub_07DC09(x);
		break;
	case 40:
		sub_07DC35(x);
		break;
	case 42:
		u = sub_07DC4B(x, u);
		break;
	case 44:
		u = sub_07DC86(x, u);
		break;
	case 46:
		u = sub_07DCA2(x, u);
		break;
	case 48:
		u = sub_07DCD8(x, u);
		break;
	case 50:
		u = sub_07DCFB(x, u);
		break;
	case 52:
		sub_07DD11(x);
		break;
	case 54:
		sub_07DD3E(x);
		break;
	case 56:
		sub_07DD63(x);
		break;
	case 62:
		sub_07DD7D(x);
		break;
	case 64:
		sub_07DDA0(x);
		break;
	case 66:
		sub_07DDB9(x);
		break;
	case -70:
		d_2 = b;
		sub_07D6BE(x, d_2, &y, &u, p_left_caller);
		break;
	case -68:
		d_2 = b;
		sub_07D6F7(x, d_2, &y, &u, p_left_caller);
		break;
	case -66:
		d_2 = b;
		sub_07D721(x, d_2, &y, &u, p_left_caller);
		break;
	case -64:
		d_2 = b;
		sub_07D74B(x, d_2, &y, &u, p_left_caller);
		break;
	case -62:
		d_2 = b;
		sub_07D787(x, d_2, &y, &u, p_left_caller);
		break;
	case -60:
		d_2 = b;
		sub_07D7A6(x, d_2, &y, &u, p_left_caller);
		break;
	case -58:
		d_2 = b;
		sub_07D7C5(x, d_2, &y, &u, p_left_caller);
		break;
	case -56:
		d_2 = b;
		sub_07D7CB(x, d_2, &y, &u, p_left_caller);
		break;
	case -54:
		u = sub_07D6C4(x);
		break;
	case -52:
	case -28:
		sub_07D6E0(x);
		break;
	case -50:
	case -44:
	case -38:
	case -32:
	case -26:
	case -20:
	case -14:
	case -8:
		sub_07D6E9(x);
		break;
	case -48:
		u = sub_07D6FD(x);
		break;
	case -46:
	case -22:
		sub_07D719(x);
		break;
	case -42:
		u = sub_07D727(x);
		break;
	case -40:
	case -16:
		sub_07D743(x);
		break;
	case -36:
		u = sub_07D751(x);
		break;
	case -34:
	case -10:
		sub_07D76D(x);
		break;
	case -30:
	case -18:
	case -12:
		sub_07D78D(x);
		break;
	case -24:
		sub_07D7AC(x);
		break;
	case -6:
		u = sub_07D806(x, u);
		break;
	case -4:
		u = sub_07D833(x, u);
		break;
	case -2:
		sub_07D87C(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_07D886(uint16_t x)
{
	uint8_t a = 0, b = 0;
	uint16_t d = 0, u = 0;
	uint8_t t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	sub_07D7DA(x);
	t1 = mem_read16(x + 0x38u);
	u = t1;
	t2 = mem_read16(x + 0x5Cu);
	t3 = mem_read16(u + 0x5Cu);
	if (t2 == t3)
	{
		t4 = mem_read16(x + 0x2Eu);
		if (t4 >= 8u)
		{
			t5 = mem_read8(x + 0x3Bu);
			mem_write8(x + 0x3Bu, t5 - 1u);
			if (t5 != 1u)
			{
				t6 = mem_read8(x + VIDEO_0031);
				if ((t6 & 8u) != 0u)
					mem_write16(x + 0x28u, 0xD00u);
				return u;
			}
			mem_write8(x + 0x3Bu, 8u);
			b = 0x50u;
			t7 = mem_read8(x + 0x36u);
			if ((int8_t)(t7 - 0x40u) < 0)
				b = 0u - b;
			d = b;
			d = sub_07CCF0(x, u, (uint8_t)d);
			a = (uint8_t)(d >> 8);
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			u = sub_07CCDD(x, u, d);
			t6 = mem_read8(x + VIDEO_0031);
			if ((t6 & 8u) != 0u)
				mem_write16(x + 0x28u, 0xD00u);
			return u;
		}
		t8 = mem_read8(x + 0x3Bu);
		mem_write8(x + 0x3Bu, t8 - 1u);
		if (t8 != 1u)
		{
			t6 = mem_read8(x + VIDEO_0031);
			if ((t6 & 8u) != 0u)
				mem_write16(x + 0x28u, 0xD00u);
			return u;
		}
		mem_write8(x + 0x3Bu, 8u);
		d = sub_07CCFB(x, u);
		return sub_07CCDD(x, u, d);
	}
	t9 = mem_read8(x + VIDEO_0031);
	mem_write8(x + VIDEO_0031, t9 | 0x10u);
	t10 = mem_read8(x + 0x36u);
	a = t10;
	d = (d & 0xFFu) | ((uint32_t)a << 8);
	u = sub_07CCDD(x, u, d);
	t6 = mem_read8(x + VIDEO_0031);
	if ((t6 & 8u) != 0u)
		mem_write16(x + 0x28u, 0xD00u);
	return u;
}

void sub_07D8E2(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0, d_2 = 0;
	uint16_t u = 0;

	u = loaded_table_07F1F8_ADDRESS;
	b = (uint32_t)d << 1;
	switch ((int8_t)b)
	{
	case 0:
		sub_07D8E8(x);
		break;
	case 2:
		sub_07D8F3(x);
		break;
	case 4:
		u = sub_07D948(x, u);
		break;
	case -4:
	case 6:
		sub_07D99A(x);
		break;
	case 8:
		u = sub_07D9B9(x);
		break;
	case 10:
	case 54:
		sub_07DA0F(x);
		break;
	case 12:
	case 56:
		sub_07DA1A(x);
		break;
	case 14:
		u = sub_07DA71(x, u);
		break;
	case 16:
		sub_07DAC4(x);
		break;
	case 18:
		u = sub_07DAD8(x, u);
		break;
	case 20:
		sub_07DB35(x);
		break;
	case 22:
		u = sub_07DB4C(x, u);
		break;
	case 24:
		sub_07DBD8(x);
		break;
	case 26:
	case 32:
		u = sub_07DBF3(x);
		break;
	case 28:
		sub_07DB95(x);
		break;
	case 30:
		u = sub_07DBB3(x, u);
		break;
	case 34:
		sub_07DC09(x);
		break;
	case 36:
		sub_07DC35(x);
		break;
	case 38:
		u = sub_07DC4B(x, u);
		break;
	case 40:
		u = sub_07DC86(x, u);
		break;
	case 42:
		u = sub_07DCA2(x, u);
		break;
	case 44:
		u = sub_07DCD8(x, u);
		break;
	case 46:
		u = sub_07DCFB(x, u);
		break;
	case 48:
		sub_07DD11(x);
		break;
	case 50:
		sub_07DD3E(x);
		break;
	case 52:
		sub_07DD63(x);
		break;
	case 58:
		sub_07DD7D(x);
		break;
	case 60:
		sub_07DDA0(x);
		break;
	case 62:
		sub_07DDB9(x);
		break;
	case -74:
		d_2 = b;
		sub_07D6BE(x, d_2, &y, &u, p_left_caller);
		break;
	case -72:
		d_2 = b;
		sub_07D6F7(x, d_2, &y, &u, p_left_caller);
		break;
	case -70:
		d_2 = b;
		sub_07D721(x, d_2, &y, &u, p_left_caller);
		break;
	case -68:
		d_2 = b;
		sub_07D74B(x, d_2, &y, &u, p_left_caller);
		break;
	case -66:
		d_2 = b;
		sub_07D787(x, d_2, &y, &u, p_left_caller);
		break;
	case -64:
		d_2 = b;
		sub_07D7A6(x, d_2, &y, &u, p_left_caller);
		break;
	case -62:
		d_2 = b;
		sub_07D7C5(x, d_2, &y, &u, p_left_caller);
		break;
	case -60:
		d_2 = b;
		sub_07D7CB(x, d_2, &y, &u, p_left_caller);
		break;
	case -58:
		u = sub_07D6C4(x);
		break;
	case -56:
	case -32:
		sub_07D6E0(x);
		break;
	case -54:
	case -48:
	case -42:
	case -36:
	case -30:
	case -24:
	case -18:
	case -12:
		sub_07D6E9(x);
		break;
	case -52:
		u = sub_07D6FD(x);
		break;
	case -50:
	case -26:
		sub_07D719(x);
		break;
	case -46:
		u = sub_07D727(x);
		break;
	case -44:
	case -20:
		sub_07D743(x);
		break;
	case -40:
		u = sub_07D751(x);
		break;
	case -38:
	case -14:
		sub_07D76D(x);
		break;
	case -34:
	case -22:
	case -16:
		sub_07D78D(x);
		break;
	case -28:
		sub_07D7AC(x);
		break;
	case -10:
		u = sub_07D806(x, u);
		break;
	case -8:
		u = sub_07D833(x, u);
		break;
	case -6:
		sub_07D87C(x);
		break;
	case -2:
		u = sub_07D886(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_07D8E8(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 0x3Bu, 0xFFu);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	sub_07D25D(x);
}

void sub_07D8F3(uint16_t x)
{
	uint8_t t1 = 0, t3 = 0, t5 = 0, t6 = 0, t8 = 0, t9 = 0, t10 = 0;
	uint16_t t2 = 0, t4 = 0, t7 = 0, t11 = 0;

	sub_07D7DA(x);
	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	t2 = mem_read16(x + 0x2Cu);
	if (t2 < 0x40u)
	{
		mem_write16(x + 0x14u, 0u);
		mem_write16(x + 0xFu, 0x100u);
		t3 = mem_read8(x + 0x37u);
		if ((int8_t)t3 < 0)
		{
			t4 = mem_read16(x + 0xFu);
			mem_write16(x + 0xFu, 0u - t4);
		}
	}
	else
	{
		t5 = mem_read8(x + 0x36u);
		t6 = mem_read8(x + 0x37u);
		if ((int8_t)(t5 - 0x40u - t6) < 0)
		{
			mem_write16(x + 0x14u, 0u);
			mem_write16(x + 0xFu, 0x100u);
			t3 = mem_read8(x + 0x37u);
			if ((int8_t)t3 < 0)
			{
				t4 = mem_read16(x + 0xFu);
				mem_write16(x + 0xFu, 0u - t4);
			}
			t7 = mem_read16(x + 0x2Eu);
			if (t7 < 3u)
			{
				t8 = mem_read8(x + 0x29u);
				mem_write8(x + 0x29u, t8 + 1u);
			}
			t9 = mem_read8(x + VIDEO_0031);
			if ((t9 & 8u) != 0u)
				mem_write16(x + 0x28u, 0xD00u);
			return;
		}
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0x100u);
		t10 = mem_read8(x + 0x36u);
		if ((int8_t)t10 < 0)
		{
			t11 = mem_read16(x + 0x14u);
			mem_write16(x + 0x14u, 0u - t11);
		}
	}
	t7 = mem_read16(x + 0x2Eu);
	if (t7 < 3u)
	{
		t8 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t8 + 1u);
	}
	t9 = mem_read8(x + VIDEO_0031);
	if ((t9 & 8u) != 0u)
		mem_write16(x + 0x28u, 0xD00u);
}

uint16_t sub_07D948(uint16_t x, uint16_t u)
{
	uint8_t t1 = 0, t3 = 0, t6 = 0;
	uint16_t t2 = 0, t4 = 0, t5 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0;

	sub_07D7DA(x);
	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	t2 = mem_read16(x + 0x2Cu);
	if (t2 >= 0x20u)
	{
		mem_write16(x + 0x14u, 0u);
		mem_write16(x + 0xFu, 0x100u);
		t3 = mem_read8(x + 0x36u);
		if ((int8_t)(((uint16_t)((uint32_t)t3 << 8) >> 8) - 0x40u) >= 0)
		{
			t4 = mem_read16(x + 0xFu);
			mem_write16(x + 0xFu, 0u - t4);
		}
	}
	else
		mem_write16(x + 0xFu, 0u);
	t5 = mem_read16(x + 0x2Eu);
	if (t5 >= 3u)
	{
		t6 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t6 - 1u);
		return u;
	}
	t7 = mem_read16(x + 0x2Cu);
	if (t7 < 0x20u)
	{
		t8 = mem_read16(x + 0x38u);
		u = t8;
		t9 = mem_read16(x + 0x5Cu);
		t10 = mem_read16(u + 0x5Cu);
		if (t9 != t10)
			mem_write16(x + 0x28u, 0u);
	}
	return u;
}

void sub_07D994(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0, d_2 = 0;
	uint16_t u = 0;

	u = loaded_table_07F1FE_ADDRESS;
	b = (uint32_t)d << 1;
	switch ((int8_t)b)
	{
	case -10:
	case 0:
		sub_07D99A(x);
		break;
	case 2:
		u = sub_07D9B9(x);
		break;
	case 4:
	case 48:
		sub_07DA0F(x);
		break;
	case 6:
	case 50:
		sub_07DA1A(x);
		break;
	case 8:
		u = sub_07DA71(x, u);
		break;
	case 10:
		sub_07DAC4(x);
		break;
	case 12:
		u = sub_07DAD8(x, u);
		break;
	case 14:
		sub_07DB35(x);
		break;
	case 16:
		u = sub_07DB4C(x, u);
		break;
	case 18:
		sub_07DBD8(x);
		break;
	case 20:
	case 26:
		u = sub_07DBF3(x);
		break;
	case 22:
		sub_07DB95(x);
		break;
	case 24:
		u = sub_07DBB3(x, u);
		break;
	case 28:
		sub_07DC09(x);
		break;
	case 30:
		sub_07DC35(x);
		break;
	case 32:
		u = sub_07DC4B(x, u);
		break;
	case 34:
		u = sub_07DC86(x, u);
		break;
	case 36:
		u = sub_07DCA2(x, u);
		break;
	case 38:
		u = sub_07DCD8(x, u);
		break;
	case 40:
		u = sub_07DCFB(x, u);
		break;
	case 42:
		sub_07DD11(x);
		break;
	case 44:
		sub_07DD3E(x);
		break;
	case 46:
		sub_07DD63(x);
		break;
	case 52:
		sub_07DD7D(x);
		break;
	case 54:
		sub_07DDA0(x);
		break;
	case 56:
		sub_07DDB9(x);
		break;
	case -80:
		d_2 = b;
		sub_07D6BE(x, d_2, &y, &u, p_left_caller);
		break;
	case -78:
		d_2 = b;
		sub_07D6F7(x, d_2, &y, &u, p_left_caller);
		break;
	case -76:
		d_2 = b;
		sub_07D721(x, d_2, &y, &u, p_left_caller);
		break;
	case -74:
		d_2 = b;
		sub_07D74B(x, d_2, &y, &u, p_left_caller);
		break;
	case -72:
		d_2 = b;
		sub_07D787(x, d_2, &y, &u, p_left_caller);
		break;
	case -70:
		d_2 = b;
		sub_07D7A6(x, d_2, &y, &u, p_left_caller);
		break;
	case -68:
		d_2 = b;
		sub_07D7C5(x, d_2, &y, &u, p_left_caller);
		break;
	case -66:
		d_2 = b;
		sub_07D7CB(x, d_2, &y, &u, p_left_caller);
		break;
	case -64:
		u = sub_07D6C4(x);
		break;
	case -62:
	case -38:
		sub_07D6E0(x);
		break;
	case -60:
	case -54:
	case -48:
	case -42:
	case -36:
	case -30:
	case -24:
	case -18:
		sub_07D6E9(x);
		break;
	case -58:
		u = sub_07D6FD(x);
		break;
	case -56:
	case -32:
		sub_07D719(x);
		break;
	case -52:
		u = sub_07D727(x);
		break;
	case -50:
	case -26:
		sub_07D743(x);
		break;
	case -46:
		u = sub_07D751(x);
		break;
	case -44:
	case -20:
		sub_07D76D(x);
		break;
	case -40:
	case -28:
	case -22:
		sub_07D78D(x);
		break;
	case -34:
		sub_07D7AC(x);
		break;
	case -16:
		u = sub_07D806(x, u);
		break;
	case -14:
		u = sub_07D833(x, u);
		break;
	case -12:
		sub_07D87C(x);
		break;
	case -8:
		u = sub_07D886(x);
		break;
	case -6:
		sub_07D8E8(x);
		break;
	case -4:
		sub_07D8F3(x);
		break;
	case -2:
		u = sub_07D948(x, u);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_07D99A(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = io_read8(VIDEO_1878);
	io_write8(VIDEO_1878, t1 + 1u);
	t2 = io_read8(VIDEO_1878);
	mem_write8(x + 0x3Bu, t2);
	mem_write8(x + 5u, 0x81u);
	t3 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t3 + 1u);
	t4 = mem_read8(x + 0x42u);
	if (t4 != 0u)
	{
		sub_07D25D(x);
		return;
	}
	mem_write8(x + 5u, 0x81u);
}

uint16_t sub_07D9B9(uint16_t x)
{
	uint8_t a = 0;
	uint16_t d = 0, u = 0;
	uint8_t t6 = 0, t7 = 0, t8 = 0, t9 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	sub_07D7DA(x);
	t1 = mem_read16(x + 0x38u);
	u = t1;
	t2 = mem_read16(x + 0x5Cu);
	d = t2;
	t3 = mem_read16(u + 0x5Cu);
	if ((uint16_t)(((uint32_t)(t2 >> 8) << 8) | (d & 0xFFu)) == t3)
	{
		t4 = mem_read16(x + 0x2Cu);
		if (t4 < 0x20u)
		{
			t5 = mem_read16(x + 0x2Eu);
			if (t5 < 0x20u)
			{
				mem_write16(x + 0xFu, 0u);
				mem_write16(x + 0x14u, 0u);
				return u;
			}
		}
		t6 = mem_read8(x + 0x3Bu);
		mem_write8(x + 0x3Bu, t6 - 1u);
		if (t6 != 1u)
		{
			t7 = mem_read8(x + VIDEO_0031);
			if ((t7 & 8u) != 0u)
				mem_write16(x + 0x28u, 0xD00u);
			return u;
		}
		mem_write8(x + 0x3Bu, 8u);
		d = sub_07CCFB(x, u);
		a = (uint8_t)(d >> 8);
	}
	else
	{
		t8 = mem_read8(x + VIDEO_0031);
		mem_write8(x + VIDEO_0031, t8 | 0x10u);
		t9 = mem_read8(x + 0x36u);
		a = t9;
	}
	d = (d & 0xFFu) | ((uint32_t)a << 8);
	u = sub_07CCDD(x, u, d);
	t7 = mem_read8(x + VIDEO_0031);
	if ((t7 & 8u) != 0u)
		mem_write16(x + 0x28u, 0xD00u);
	return u;
}

void sub_07DA09(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0, d_2 = 0;
	uint16_t u = 0;

	u = loaded_table_07F202_ADDRESS;
	b = (uint32_t)d << 1;
	switch ((int8_t)b)
	{
	case 0:
	case 44:
		sub_07DA0F(x);
		break;
	case 2:
	case 46:
		sub_07DA1A(x);
		break;
	case 4:
		u = sub_07DA71(x, u);
		break;
	case 6:
		sub_07DAC4(x);
		break;
	case 8:
		u = sub_07DAD8(x, u);
		break;
	case 10:
		sub_07DB35(x);
		break;
	case 12:
		u = sub_07DB4C(x, u);
		break;
	case 14:
		sub_07DBD8(x);
		break;
	case 16:
	case 22:
		u = sub_07DBF3(x);
		break;
	case 18:
		sub_07DB95(x);
		break;
	case 20:
		u = sub_07DBB3(x, u);
		break;
	case 24:
		sub_07DC09(x);
		break;
	case 26:
		sub_07DC35(x);
		break;
	case 28:
		u = sub_07DC4B(x, u);
		break;
	case 30:
		u = sub_07DC86(x, u);
		break;
	case 32:
		u = sub_07DCA2(x, u);
		break;
	case 34:
		u = sub_07DCD8(x, u);
		break;
	case 36:
		u = sub_07DCFB(x, u);
		break;
	case 38:
		sub_07DD11(x);
		break;
	case 40:
		sub_07DD3E(x);
		break;
	case 42:
		sub_07DD63(x);
		break;
	case 48:
		sub_07DD7D(x);
		break;
	case 50:
		sub_07DDA0(x);
		break;
	case 52:
		sub_07DDB9(x);
		break;
	case -84:
		d_2 = b;
		sub_07D6BE(x, d_2, &y, &u, p_left_caller);
		break;
	case -82:
		d_2 = b;
		sub_07D6F7(x, d_2, &y, &u, p_left_caller);
		break;
	case -80:
		d_2 = b;
		sub_07D721(x, d_2, &y, &u, p_left_caller);
		break;
	case -78:
		d_2 = b;
		sub_07D74B(x, d_2, &y, &u, p_left_caller);
		break;
	case -76:
		d_2 = b;
		sub_07D787(x, d_2, &y, &u, p_left_caller);
		break;
	case -74:
		d_2 = b;
		sub_07D7A6(x, d_2, &y, &u, p_left_caller);
		break;
	case -72:
		d_2 = b;
		sub_07D7C5(x, d_2, &y, &u, p_left_caller);
		break;
	case -70:
		d_2 = b;
		sub_07D7CB(x, d_2, &y, &u, p_left_caller);
		break;
	case -68:
		u = sub_07D6C4(x);
		break;
	case -66:
	case -42:
		sub_07D6E0(x);
		break;
	case -64:
	case -58:
	case -52:
	case -46:
	case -40:
	case -34:
	case -28:
	case -22:
		sub_07D6E9(x);
		break;
	case -62:
		u = sub_07D6FD(x);
		break;
	case -60:
	case -36:
		sub_07D719(x);
		break;
	case -56:
		u = sub_07D727(x);
		break;
	case -54:
	case -30:
		sub_07D743(x);
		break;
	case -50:
		u = sub_07D751(x);
		break;
	case -48:
	case -24:
		sub_07D76D(x);
		break;
	case -44:
	case -32:
	case -26:
		sub_07D78D(x);
		break;
	case -38:
		sub_07D7AC(x);
		break;
	case -20:
		u = sub_07D806(x, u);
		break;
	case -18:
		u = sub_07D833(x, u);
		break;
	case -16:
		sub_07D87C(x);
		break;
	case -14:
	case -4:
		sub_07D99A(x);
		break;
	case -12:
		u = sub_07D886(x);
		break;
	case -10:
		sub_07D8E8(x);
		break;
	case -8:
		sub_07D8F3(x);
		break;
	case -6:
		u = sub_07D948(x, u);
		break;
	case -2:
		u = sub_07D9B9(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_07DA0F(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 0x3Bu, 0xFFu);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	sub_07D25D(x);
}

void sub_07DA1A(uint16_t x)
{
	uint8_t t1 = 0, t4 = 0, t6 = 0, t7 = 0, t9 = 0, t10 = 0, t12 = 0;
	uint16_t t2 = 0, t3 = 0, t5 = 0, t8 = 0, t11 = 0, t13 = 0;

	sub_07D7DA(x);
	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	t2 = mem_read16(x + 0x2Cu);
	if (t2 < 0x20u)
	{
		mem_write16(x + 0x14u, 0u);
		t3 = io_read16(VIDEO_1886);
		mem_write16(x + 0xFu, t3);
		t4 = mem_read8(x + 0x37u);
		if ((int8_t)t4 < 0)
		{
			t5 = mem_read16(x + 0xFu);
			mem_write16(x + 0xFu, 0u - t5);
		}
	}
	else
	{
		t6 = mem_read8(x + 0x36u);
		t7 = mem_read8(x + 0x37u);
		if ((int8_t)(t6 - 0x40u - t7) < 0)
		{
			mem_write16(x + 0x14u, 0u);
			t3 = io_read16(VIDEO_1886);
			mem_write16(x + 0xFu, t3);
			t4 = mem_read8(x + 0x37u);
			if ((int8_t)t4 < 0)
			{
				t5 = mem_read16(x + 0xFu);
				mem_write16(x + 0xFu, 0u - t5);
			}
			t8 = mem_read16(x + 0x2Eu);
			if (t8 < 3u)
			{
				t9 = mem_read8(x + 0x29u);
				mem_write8(x + 0x29u, t9 + 1u);
			}
			t10 = mem_read8(x + VIDEO_0031);
			if ((t10 & 8u) != 0u)
				mem_write16(x + 0x28u, 0xD00u);
			return;
		}
		mem_write16(x + 0xFu, 0u);
		t11 = io_read16(VIDEO_1886);
		mem_write16(x + 0x14u, t11);
		t12 = mem_read8(x + 0x36u);
		if ((int8_t)t12 < 0)
		{
			t13 = mem_read16(x + 0x14u);
			mem_write16(x + 0x14u, 0u - t13);
		}
	}
	t8 = mem_read16(x + 0x2Eu);
	if (t8 < 3u)
	{
		t9 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t9 + 1u);
	}
	t10 = mem_read8(x + VIDEO_0031);
	if ((t10 & 8u) != 0u)
		mem_write16(x + 0x28u, 0xD00u);
}

uint16_t sub_07DA71(uint16_t x, uint16_t u)
{
	uint8_t t1 = 0, t4 = 0, t7 = 0;
	uint16_t t2 = 0, t3 = 0, t5 = 0, t6 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0;

	sub_07D7DA(x);
	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	t2 = mem_read16(x + 0x2Cu);
	if (t2 >= 0x10u)
	{
		mem_write16(x + 0x14u, 0u);
		t3 = io_read16(VIDEO_1886);
		mem_write16(x + 0xFu, t3);
		t4 = mem_read8(x + 0x36u);
		if ((int8_t)(((uint16_t)((uint32_t)t4 << 8) >> 8) - 0x40u) >= 0)
		{
			t5 = mem_read16(x + 0xFu);
			mem_write16(x + 0xFu, 0u - t5);
		}
	}
	else
		mem_write16(x + 0xFu, 0u);
	t6 = mem_read16(x + 0x2Eu);
	if (t6 >= 3u)
	{
		t7 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t7 - 1u);
		return u;
	}
	t8 = mem_read16(x + 0x2Cu);
	if (t8 < 0x10u)
	{
		t9 = mem_read16(x + 0x38u);
		u = t9;
		t10 = mem_read16(x + 0x5Cu);
		t11 = mem_read16(u + 0x5Cu);
		if (t10 != t11)
			mem_write16(x + 0x28u, 0u);
	}
	return u;
}

void sub_07DABE(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0, d_2 = 0;
	uint16_t u = 0;

	u = loaded_table_07F208_ADDRESS;
	b = (uint32_t)d << 1;
	switch ((int8_t)b)
	{
	case 0:
		sub_07DAC4(x);
		break;
	case 2:
		u = sub_07DAD8(x, u);
		break;
	case 4:
		sub_07DB35(x);
		break;
	case 6:
		u = sub_07DB4C(x, u);
		break;
	case 8:
		sub_07DBD8(x);
		break;
	case 10:
	case 16:
		u = sub_07DBF3(x);
		break;
	case 12:
		sub_07DB95(x);
		break;
	case 14:
		u = sub_07DBB3(x, u);
		break;
	case 18:
		sub_07DC09(x);
		break;
	case 20:
		sub_07DC35(x);
		break;
	case 22:
		u = sub_07DC4B(x, u);
		break;
	case 24:
		u = sub_07DC86(x, u);
		break;
	case 26:
		u = sub_07DCA2(x, u);
		break;
	case 28:
		u = sub_07DCD8(x, u);
		break;
	case 30:
		u = sub_07DCFB(x, u);
		break;
	case 32:
		sub_07DD11(x);
		break;
	case 34:
		sub_07DD3E(x);
		break;
	case 36:
		sub_07DD63(x);
		break;
	case -6:
	case 38:
		sub_07DA0F(x);
		break;
	case -4:
	case 40:
		sub_07DA1A(x);
		break;
	case 42:
		sub_07DD7D(x);
		break;
	case 44:
		sub_07DDA0(x);
		break;
	case 46:
		sub_07DDB9(x);
		break;
	case -90:
		d_2 = b;
		sub_07D6BE(x, d_2, &y, &u, p_left_caller);
		break;
	case -88:
		d_2 = b;
		sub_07D6F7(x, d_2, &y, &u, p_left_caller);
		break;
	case -86:
		d_2 = b;
		sub_07D721(x, d_2, &y, &u, p_left_caller);
		break;
	case -84:
		d_2 = b;
		sub_07D74B(x, d_2, &y, &u, p_left_caller);
		break;
	case -82:
		d_2 = b;
		sub_07D787(x, d_2, &y, &u, p_left_caller);
		break;
	case -80:
		d_2 = b;
		sub_07D7A6(x, d_2, &y, &u, p_left_caller);
		break;
	case -78:
		d_2 = b;
		sub_07D7C5(x, d_2, &y, &u, p_left_caller);
		break;
	case -76:
		d_2 = b;
		sub_07D7CB(x, d_2, &y, &u, p_left_caller);
		break;
	case -74:
		u = sub_07D6C4(x);
		break;
	case -72:
	case -48:
		sub_07D6E0(x);
		break;
	case -70:
	case -64:
	case -58:
	case -52:
	case -46:
	case -40:
	case -34:
	case -28:
		sub_07D6E9(x);
		break;
	case -68:
		u = sub_07D6FD(x);
		break;
	case -66:
	case -42:
		sub_07D719(x);
		break;
	case -62:
		u = sub_07D727(x);
		break;
	case -60:
	case -36:
		sub_07D743(x);
		break;
	case -56:
		u = sub_07D751(x);
		break;
	case -54:
	case -30:
		sub_07D76D(x);
		break;
	case -50:
	case -38:
	case -32:
		sub_07D78D(x);
		break;
	case -44:
		sub_07D7AC(x);
		break;
	case -26:
		u = sub_07D806(x, u);
		break;
	case -24:
		u = sub_07D833(x, u);
		break;
	case -22:
		sub_07D87C(x);
		break;
	case -20:
	case -10:
		sub_07D99A(x);
		break;
	case -18:
		u = sub_07D886(x);
		break;
	case -16:
		sub_07D8E8(x);
		break;
	case -14:
		sub_07D8F3(x);
		break;
	case -12:
		u = sub_07D948(x, u);
		break;
	case -8:
		u = sub_07D9B9(x);
		break;
	case -2:
		u = sub_07DA71(x, u);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_07DAC4(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	mem_write8(x + 0x3Bu, 0xFFu);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	t2 = mem_read8(x + 0x42u);
	if (t2 != 0u)
	{
		sub_07D25D(x);
		return;
	}
	mem_write8(x + 5u, 0x81u);
}

uint16_t sub_07DAD8(uint16_t x, uint16_t u)
{
	uint8_t a = 0, b = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t4 = 0, t5 = 0, t7 = 0, t8 = 0, t10 = 0, t11 = 0;
	uint16_t t2 = 0, t3 = 0, t6 = 0, t9 = 0;

	sub_07D7DA(x);
	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	t2 = mem_read16(x + 0x2Cu);
	if (t2 < 0x50u)
	{
		t3 = mem_read16(x + 0x2Eu);
		if (t3 < 0x20u)
		{
			t4 = mem_read8(x + 0x36u);
			a = t4 - 0x80u;
			d = (uint32_t)a << 8;
			u = sub_07CCDD(x, u, d);
			mem_write8(x + 5u, 0x81u);
			t5 = mem_read8(x + 0x29u);
			mem_write8(x + 0x29u, t5 + 1u);
			return u;
		}
	}
	t6 = mem_read16(x + 0x2Cu);
	if (t6 >= 0x70u)
	{
		t7 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t7 + 1u);
		t8 = mem_read8(x + 0x36u);
		a = t8;
		d = (uint32_t)a << 8;
		u = sub_07CCDD(x, u, d);
		mem_write8(x + 5u, 0x81u);
		t5 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t5 + 1u);
		return u;
	}
	t9 = mem_read16(x + 0x2Eu);
	if (t9 >= 0x40u)
	{
		t7 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t7 + 1u);
		t8 = mem_read8(x + 0x36u);
		a = t8;
		d = (uint32_t)a << 8;
		u = sub_07CCDD(x, u, d);
		mem_write8(x + 5u, 0x81u);
		t5 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t5 + 1u);
		return u;
	}
	t10 = mem_read8(x + 0x42u);
	if (t10 != 0u)
	{
		t11 = mem_read8(x + 0x36u);
		if ((int8_t)t11 >= 0)
			b = 0x94u;
		else
			b = 0x86u;
	}
	else
		b = 0x87u;
	mem_write8(x + 5u, b);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	return u;
}

void sub_07DB35(uint16_t x)
{
	uint16_t t1 = 0, t2 = 0;

	sub_07D7DA(x);
	t1 = mem_read16(x + 0x2Cu);
	if (t1 < 0x50u)
	{
		t2 = mem_read16(x + 0x2Eu);
		if (t2 >= 0x20u)
			mem_write8(x + 0x29u, 0u);
		return;
	}
	mem_write8(x + 0x29u, 0u);
}

uint16_t sub_07DB4C(uint16_t x, uint16_t u)
{
	uint8_t d = 0;
	uint16_t d_2 = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0, t3 = 0;

	sub_07D7DA(x);
	t1 = mem_read16(x + 0x2Cu);
	d = (uint8_t)t1;
	if ((uint16_t)(((uint32_t)(t1 >> 8) << 8) | (d & 0xFFu)) >= 0x70u)
	{
		if ((unk_4815 & 0xFu) == 0u)
		{
			t2 = mem_read8(x + 0x36u);
			d_2 = (d & 0xFFu) | ((uint32_t)t2 << 8);
			u = sub_07CCDD(x, u, d_2);
		}
		return u;
	}
	t3 = mem_read16(x + 0x2Eu);
	d = (uint8_t)t3;
	if ((uint16_t)(((uint32_t)(t3 >> 8) << 8) | (d & 0xFFu)) < 0x40u)
	{
		mem_write8(x + 0x29u, 0u);
		return u;
	}
	if ((unk_4815 & 0xFu) == 0u)
	{
		t2 = mem_read8(x + 0x36u);
		d_2 = (d & 0xFFu) | ((uint32_t)t2 << 8);
		u = sub_07CCDD(x, u, d_2);
	}
	return u;
}

void sub_07DB71(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint16_t t1 = 0;

	u = loaded_table_07F210_ADDRESS;
	d = (uint8_t)((uint32_t)d << 1);
	switch ((int8_t)d)
	{
	case 0:
		sub_07DBD8(x);
		break;
	case 2:
	case 8:
		u = sub_07DBF3(x);
		break;
	case 4:
		sub_07DB95(x);
		break;
	case 6:
		u = sub_07DBB3(x, u);
		break;
	case 10:
		sub_07DC09(x);
		break;
	case 12:
		sub_07DC35(x);
		break;
	case 14:
		u = sub_07DC4B(x, u);
		break;
	case 16:
		u = sub_07DC86(x, u);
		break;
	case 18:
		u = sub_07DCA2(x, u);
		break;
	case 20:
		u = sub_07DCD8(x, u);
		break;
	case 22:
		u = sub_07DCFB(x, u);
		break;
	case 24:
		sub_07DD11(x);
		break;
	case 26:
		sub_07DD3E(x);
		break;
	case 28:
		sub_07DD63(x);
		break;
	case -14:
	case 30:
		sub_07DA0F(x);
		break;
	case -12:
	case 32:
		sub_07DA1A(x);
		break;
	case 34:
		sub_07DD7D(x);
		break;
	case 36:
		sub_07DDA0(x);
		break;
	case 38:
		sub_07DDB9(x);
		break;
	case -98:
		sub_07D6BE(x, d, &y, &u, p_left_caller);
		break;
	case -96:
		sub_07D6F7(x, d, &y, &u, p_left_caller);
		break;
	case -94:
		sub_07D721(x, d, &y, &u, p_left_caller);
		break;
	case -92:
		sub_07D74B(x, d, &y, &u, p_left_caller);
		break;
	case -90:
		sub_07D787(x, d, &y, &u, p_left_caller);
		break;
	case -88:
		sub_07D7A6(x, d, &y, &u, p_left_caller);
		break;
	case -86:
		sub_07D7C5(x, d, &y, &u, p_left_caller);
		break;
	case -84:
		sub_07D7CB(x, d, &y, &u, p_left_caller);
		break;
	case -82:
		u = sub_07D6C4(x);
		break;
	case -80:
	case -56:
		sub_07D6E0(x);
		break;
	case -78:
	case -72:
	case -66:
	case -60:
	case -54:
	case -48:
	case -42:
	case -36:
		sub_07D6E9(x);
		break;
	case -76:
		u = sub_07D6FD(x);
		break;
	case -74:
	case -50:
		sub_07D719(x);
		break;
	case -70:
		u = sub_07D727(x);
		break;
	case -68:
	case -44:
		sub_07D743(x);
		break;
	case -64:
		u = sub_07D751(x);
		break;
	case -62:
	case -38:
		sub_07D76D(x);
		break;
	case -58:
	case -46:
	case -40:
		sub_07D78D(x);
		break;
	case -52:
		sub_07D7AC(x);
		break;
	case -34:
		u = sub_07D806(x, u);
		break;
	case -32:
		u = sub_07D833(x, u);
		break;
	case -30:
		sub_07D87C(x);
		break;
	case -28:
	case -18:
		sub_07D99A(x);
		break;
	case -26:
		u = sub_07D886(x);
		break;
	case -24:
		sub_07D8E8(x);
		break;
	case -22:
		sub_07D8F3(x);
		break;
	case -20:
		u = sub_07D948(x, u);
		break;
	case -16:
		u = sub_07D9B9(x);
		break;
	case -10:
		u = sub_07DA71(x, u);
		break;
	case -8:
		sub_07DAC4(x);
		break;
	case -6:
		u = sub_07DAD8(x, u);
		break;
	case -4:
		sub_07DB35(x);
		break;
	case -2:
		u = sub_07DB4C(x, u);
		break;
	}
	t1 = mem_read16(x + 0xCu);
	if (t1 < 0x40 || t1 > 0x17F)
	{
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
	}
	*p_y = y;
	*p_u = u;
}

void sub_07DB7A(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint16_t t1 = 0;

	u = loaded_table_07F214_ADDRESS;
	d = (uint8_t)((uint32_t)d << 1);
	switch ((int8_t)d)
	{
	case 0:
		sub_07DB95(x);
		break;
	case 2:
		u = sub_07DBB3(x, u);
		break;
	case -2:
	case 4:
		u = sub_07DBF3(x);
		break;
	case 6:
		sub_07DC09(x);
		break;
	case 8:
		sub_07DC35(x);
		break;
	case 10:
		u = sub_07DC4B(x, u);
		break;
	case 12:
		u = sub_07DC86(x, u);
		break;
	case 14:
		u = sub_07DCA2(x, u);
		break;
	case 16:
		u = sub_07DCD8(x, u);
		break;
	case 18:
		u = sub_07DCFB(x, u);
		break;
	case 20:
		sub_07DD11(x);
		break;
	case 22:
		sub_07DD3E(x);
		break;
	case 24:
		sub_07DD63(x);
		break;
	case -18:
	case 26:
		sub_07DA0F(x);
		break;
	case -16:
	case 28:
		sub_07DA1A(x);
		break;
	case 30:
		sub_07DD7D(x);
		break;
	case 32:
		sub_07DDA0(x);
		break;
	case 34:
		sub_07DDB9(x);
		break;
	case -102:
		sub_07D6BE(x, d, &y, &u, p_left_caller);
		break;
	case -100:
		sub_07D6F7(x, d, &y, &u, p_left_caller);
		break;
	case -98:
		sub_07D721(x, d, &y, &u, p_left_caller);
		break;
	case -96:
		sub_07D74B(x, d, &y, &u, p_left_caller);
		break;
	case -94:
		sub_07D787(x, d, &y, &u, p_left_caller);
		break;
	case -92:
		sub_07D7A6(x, d, &y, &u, p_left_caller);
		break;
	case -90:
		sub_07D7C5(x, d, &y, &u, p_left_caller);
		break;
	case -88:
		sub_07D7CB(x, d, &y, &u, p_left_caller);
		break;
	case -86:
		u = sub_07D6C4(x);
		break;
	case -84:
	case -60:
		sub_07D6E0(x);
		break;
	case -82:
	case -76:
	case -70:
	case -64:
	case -58:
	case -52:
	case -46:
	case -40:
		sub_07D6E9(x);
		break;
	case -80:
		u = sub_07D6FD(x);
		break;
	case -78:
	case -54:
		sub_07D719(x);
		break;
	case -74:
		u = sub_07D727(x);
		break;
	case -72:
	case -48:
		sub_07D743(x);
		break;
	case -68:
		u = sub_07D751(x);
		break;
	case -66:
	case -42:
		sub_07D76D(x);
		break;
	case -62:
	case -50:
	case -44:
		sub_07D78D(x);
		break;
	case -56:
		sub_07D7AC(x);
		break;
	case -38:
		u = sub_07D806(x, u);
		break;
	case -36:
		u = sub_07D833(x, u);
		break;
	case -34:
		sub_07D87C(x);
		break;
	case -32:
	case -22:
		sub_07D99A(x);
		break;
	case -30:
		u = sub_07D886(x);
		break;
	case -28:
		sub_07D8E8(x);
		break;
	case -26:
		sub_07D8F3(x);
		break;
	case -24:
		u = sub_07D948(x, u);
		break;
	case -20:
		u = sub_07D9B9(x);
		break;
	case -14:
		u = sub_07DA71(x, u);
		break;
	case -12:
		sub_07DAC4(x);
		break;
	case -10:
		u = sub_07DAD8(x, u);
		break;
	case -8:
		sub_07DB35(x);
		break;
	case -6:
		u = sub_07DB4C(x, u);
		break;
	case -4:
		sub_07DBD8(x);
		break;
	}
	t1 = mem_read16(x + 0xCu);
	if (t1 < 0x40 || t1 > 0x17F)
	{
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
	}
	*p_y = y;
	*p_u = u;
}

void sub_07DB95(uint16_t x)
{
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	mem_write8(x + 0x3Bu, 0x20u);
	t1 = mem_read8(x + 0x36u);
	d = ((uint32_t)(uint8_t)(t1 - 0x80u) << 8) | 0x20u;
	sub_07CC8E(x, d);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	t3 = mem_read8(x + 0x42u);
	if (t3 != 0u)
	{
		sub_07D25D(x);
		return;
	}
	mem_write8(x + 5u, 0x81u);
}

uint16_t sub_07DBB3(uint16_t x, uint16_t u)
{
	uint8_t t1 = 0, t3 = 0, t4 = 0, t5 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return u;
	t2 = mem_read16(x + 0x38u);
	u = t2;
	t3 = mem_read8(u + 0x1Bu);
	if (t3 != 0u)
	{
		mem_write8(x + 5u, 0x80u);
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
		mem_write8(x + 0x3Bu, 0x40u);
		t4 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t4 + 1u);
		return u;
	}
	t5 = mem_read8(x + 0x42u);
	if (t5 == 0u)
	{
		mem_write8(x + 5u, 0x87u);
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
		mem_write8(x + 0x3Bu, 0x40u);
		t4 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t4 + 1u);
		return u;
	}
	if ((int8_t)(uint8_t)unk_4815 < 0)
	{
		sub_07DBD8(x);
		return u;
	}
	mem_write8(x + 5u, 0x93u);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write8(x + 0x3Bu, 0x40u);
	t4 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t4 + 1u);
	return u;
}

void sub_07DBD8(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 5u, 0x87u);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write8(x + 0x3Bu, 0x40u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

uint16_t sub_07DBF3(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x38u);
	u = t1;
	t2 = mem_read8(u + 2u);
	if ((int8_t)t2 >= 0)
	{
		mem_write8(x + 0x30u, 0u);
		mem_write8(x + 0x3Bu, 0u);
	}
	return u;
}

void sub_07DC02(void)
{
}

void sub_07DC03(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0, d_2 = 0;
	uint16_t u = 0;

	u = loaded_table_07F21A_ADDRESS;
	b = (uint32_t)d << 1;
	switch ((int8_t)b)
	{
	case 0:
		sub_07DC09(x);
		break;
	case 2:
		sub_07DC35(x);
		break;
	case 4:
		u = sub_07DC4B(x, u);
		break;
	case 6:
		u = sub_07DC86(x, u);
		break;
	case 8:
		u = sub_07DCA2(x, u);
		break;
	case 10:
		u = sub_07DCD8(x, u);
		break;
	case 12:
		u = sub_07DCFB(x, u);
		break;
	case 14:
		sub_07DD11(x);
		break;
	case 16:
		sub_07DD3E(x);
		break;
	case 18:
		sub_07DD63(x);
		break;
	case -24:
	case 20:
		sub_07DA0F(x);
		break;
	case -22:
	case 22:
		sub_07DA1A(x);
		break;
	case 24:
		sub_07DD7D(x);
		break;
	case 26:
		sub_07DDA0(x);
		break;
	case 28:
		sub_07DDB9(x);
		break;
	case -108:
		d_2 = b;
		sub_07D6BE(x, d_2, &y, &u, p_left_caller);
		break;
	case -106:
		d_2 = b;
		sub_07D6F7(x, d_2, &y, &u, p_left_caller);
		break;
	case -104:
		d_2 = b;
		sub_07D721(x, d_2, &y, &u, p_left_caller);
		break;
	case -102:
		d_2 = b;
		sub_07D74B(x, d_2, &y, &u, p_left_caller);
		break;
	case -100:
		d_2 = b;
		sub_07D787(x, d_2, &y, &u, p_left_caller);
		break;
	case -98:
		d_2 = b;
		sub_07D7A6(x, d_2, &y, &u, p_left_caller);
		break;
	case -96:
		d_2 = b;
		sub_07D7C5(x, d_2, &y, &u, p_left_caller);
		break;
	case -94:
		d_2 = b;
		sub_07D7CB(x, d_2, &y, &u, p_left_caller);
		break;
	case -92:
		u = sub_07D6C4(x);
		break;
	case -90:
	case -66:
		sub_07D6E0(x);
		break;
	case -88:
	case -82:
	case -76:
	case -70:
	case -64:
	case -58:
	case -52:
	case -46:
		sub_07D6E9(x);
		break;
	case -86:
		u = sub_07D6FD(x);
		break;
	case -84:
	case -60:
		sub_07D719(x);
		break;
	case -80:
		u = sub_07D727(x);
		break;
	case -78:
	case -54:
		sub_07D743(x);
		break;
	case -74:
		u = sub_07D751(x);
		break;
	case -72:
	case -48:
		sub_07D76D(x);
		break;
	case -68:
	case -56:
	case -50:
		sub_07D78D(x);
		break;
	case -62:
		sub_07D7AC(x);
		break;
	case -44:
		u = sub_07D806(x, u);
		break;
	case -42:
		u = sub_07D833(x, u);
		break;
	case -40:
		sub_07D87C(x);
		break;
	case -38:
	case -28:
		sub_07D99A(x);
		break;
	case -36:
		u = sub_07D886(x);
		break;
	case -34:
		sub_07D8E8(x);
		break;
	case -32:
		sub_07D8F3(x);
		break;
	case -30:
		u = sub_07D948(x, u);
		break;
	case -26:
		u = sub_07D9B9(x);
		break;
	case -20:
		u = sub_07DA71(x, u);
		break;
	case -18:
		sub_07DAC4(x);
		break;
	case -16:
		u = sub_07DAD8(x, u);
		break;
	case -14:
		sub_07DB35(x);
		break;
	case -12:
		u = sub_07DB4C(x, u);
		break;
	case -10:
		sub_07DBD8(x);
		break;
	case -8:
	case -2:
		u = sub_07DBF3(x);
		break;
	case -6:
		sub_07DB95(x);
		break;
	case -4:
		u = sub_07DBB3(x, u);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_07DC09(uint16_t x)
{
	uint8_t t1 = 0, t3 = 0, t4 = 0;
	uint16_t t2 = 0;

	mem_write8(x + 5u, 0x87u);
	mem_write8(x + 0x3Bu, 0x40u);
	mem_write16(x + 0xFu, VIDEO_00C0);
	t1 = mem_read8(x + 0x36u);
	if ((int8_t)(t1 - 0x40u) >= 0)
	{
		t2 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t2);
	}
	mem_write16(x + 0x14u, 0u);
	t3 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t3 + 1u);
	t4 = mem_read8(x + 0x42u);
	if (t4 != 0u)
	{
		sub_07D25D(x);
		return;
	}
	mem_write8(x + 5u, 0x81u);
}

void sub_07DC35(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
		mem_write16(x + 0xFu, 0u);
}

void sub_07DC3E(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0, d_2 = 0;
	uint16_t u = 0;
	uint8_t t1 = 0;

	u = loaded_table_07F21E_ADDRESS;
	b = (uint32_t)d << 1;
	d_2 = b;
	switch ((int8_t)b)
	{
	case 0:
		u = sub_07DC4B(x, u);
		break;
	case 2:
		u = sub_07DC86(x, u);
		break;
	case 4:
		u = sub_07DCA2(x, u);
		break;
	case 6:
		u = sub_07DCD8(x, u);
		break;
	case 8:
		u = sub_07DCFB(x, u);
		break;
	case 10:
		sub_07DD11(x);
		break;
	case 12:
		sub_07DD3E(x);
		break;
	case 14:
		sub_07DD63(x);
		break;
	case -28:
	case 16:
		sub_07DA0F(x);
		break;
	case -26:
	case 18:
		sub_07DA1A(x);
		break;
	case 20:
		sub_07DD7D(x);
		break;
	case 22:
		sub_07DDA0(x);
		break;
	case 24:
		sub_07DDB9(x);
		break;
	case -112:
		sub_07D6BE(x, d_2, &y, &u, p_left_caller);
		break;
	case -110:
		sub_07D6F7(x, d_2, &y, &u, p_left_caller);
		break;
	case -108:
		sub_07D721(x, d_2, &y, &u, p_left_caller);
		break;
	case -106:
		sub_07D74B(x, d_2, &y, &u, p_left_caller);
		break;
	case -104:
		sub_07D787(x, d_2, &y, &u, p_left_caller);
		break;
	case -102:
		sub_07D7A6(x, d_2, &y, &u, p_left_caller);
		break;
	case -100:
		sub_07D7C5(x, d_2, &y, &u, p_left_caller);
		break;
	case -98:
		sub_07D7CB(x, d_2, &y, &u, p_left_caller);
		break;
	case -96:
		u = sub_07D6C4(x);
		break;
	case -94:
	case -70:
		sub_07D6E0(x);
		break;
	case -92:
	case -86:
	case -80:
	case -74:
	case -68:
	case -62:
	case -56:
	case -50:
		sub_07D6E9(x);
		break;
	case -90:
		u = sub_07D6FD(x);
		break;
	case -88:
	case -64:
		sub_07D719(x);
		break;
	case -84:
		u = sub_07D727(x);
		break;
	case -82:
	case -58:
		sub_07D743(x);
		break;
	case -78:
		u = sub_07D751(x);
		break;
	case -76:
	case -52:
		sub_07D76D(x);
		break;
	case -72:
	case -60:
	case -54:
		sub_07D78D(x);
		break;
	case -66:
		sub_07D7AC(x);
		break;
	case -48:
		u = sub_07D806(x, u);
		break;
	case -46:
		u = sub_07D833(x, u);
		break;
	case -44:
		sub_07D87C(x);
		break;
	case -42:
	case -32:
		sub_07D99A(x);
		break;
	case -40:
		u = sub_07D886(x);
		break;
	case -38:
		sub_07D8E8(x);
		break;
	case -36:
		sub_07D8F3(x);
		break;
	case -34:
		u = sub_07D948(x, u);
		break;
	case -30:
		u = sub_07D9B9(x);
		break;
	case -24:
		u = sub_07DA71(x, u);
		break;
	case -22:
		sub_07DAC4(x);
		break;
	case -20:
		u = sub_07DAD8(x, u);
		break;
	case -18:
		sub_07DB35(x);
		break;
	case -16:
		u = sub_07DB4C(x, u);
		break;
	case -14:
		sub_07DBD8(x);
		break;
	case -12:
	case -6:
		u = sub_07DBF3(x);
		break;
	case -10:
		sub_07DB95(x);
		break;
	case -8:
		u = sub_07DBB3(x, u);
		break;
	case -4:
		sub_07DC09(x);
		break;
	case -2:
		sub_07DC35(x);
		break;
	}
	t1 = mem_read8(x + 0x29u);
	if (t1 != 0u)
		sub_07D7D1(x);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_07DC4B(uint16_t x, uint16_t u)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x42u);
	if (t1 == 0u)
		mem_write8(x + 5u, 0x81u);
	else
		sub_07D25D(x);
	mem_write8(x + 0x3Bu, 0xFFu);
	if ((int8_t)unk_4858 >= 0)
		mem_write8(x + 0x3Du, 0xFFu);
	else
		mem_write8(x + 0x3Du, 0u);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	return sub_07DC71(x, u);
}

uint16_t sub_07DC71(uint16_t x, uint16_t u)
{
	uint8_t a = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;
	uint16_t t3 = 0;

	t1 = mem_read8(x + 0x36u);
	a = t1;
	t2 = mem_read8(x + 0x3Du);
	if (t2 != 0u)
		a += 0x50u;
	else
		a -= 0x30u;
	d = (uint32_t)a << 8;
	u = sub_07CCDD(x, u, d);
	t3 = mem_read16(x + 0x14u);
	mem_write16(x + 0x14u, (int16_t)t3 >> 1);
	return u;
}

uint16_t sub_07DC86(uint16_t x, uint16_t u)
{
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	t2 = mem_read8(x + VIDEO_0031);
	if ((int8_t)t2 < 0)
	{
		t3 = mem_read8(x + 0x3Du);
		mem_write8(x + 0x3Du, ~t3);
		return sub_07DC71(x, u);
	}
	t4 = mem_read8(x + 0x36u);
	t5 = mem_read8(x + 0x35u);
	if (t4 != t5)
		return sub_07DC71(x, u);
	return u;
}

void sub_07DC9C(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0, d_2 = 0;
	uint16_t u = 0;

	u = loaded_table_07F222_ADDRESS;
	b = (uint32_t)d << 1;
	switch ((int8_t)b)
	{
	case 0:
		u = sub_07DCA2(x, u);
		break;
	case 2:
		u = sub_07DCD8(x, u);
		break;
	case 4:
		u = sub_07DCFB(x, u);
		break;
	case 6:
		sub_07DD11(x);
		break;
	case 8:
		sub_07DD3E(x);
		break;
	case 10:
		sub_07DD63(x);
		break;
	case -32:
	case 12:
		sub_07DA0F(x);
		break;
	case -30:
	case 14:
		sub_07DA1A(x);
		break;
	case 16:
		sub_07DD7D(x);
		break;
	case 18:
		sub_07DDA0(x);
		break;
	case 20:
		sub_07DDB9(x);
		break;
	case -116:
		d_2 = b;
		sub_07D6BE(x, d_2, &y, &u, p_left_caller);
		break;
	case -114:
		d_2 = b;
		sub_07D6F7(x, d_2, &y, &u, p_left_caller);
		break;
	case -112:
		d_2 = b;
		sub_07D721(x, d_2, &y, &u, p_left_caller);
		break;
	case -110:
		d_2 = b;
		sub_07D74B(x, d_2, &y, &u, p_left_caller);
		break;
	case -108:
		d_2 = b;
		sub_07D787(x, d_2, &y, &u, p_left_caller);
		break;
	case -106:
		d_2 = b;
		sub_07D7A6(x, d_2, &y, &u, p_left_caller);
		break;
	case -104:
		d_2 = b;
		sub_07D7C5(x, d_2, &y, &u, p_left_caller);
		break;
	case -102:
		d_2 = b;
		sub_07D7CB(x, d_2, &y, &u, p_left_caller);
		break;
	case -100:
		u = sub_07D6C4(x);
		break;
	case -98:
	case -74:
		sub_07D6E0(x);
		break;
	case -96:
	case -90:
	case -84:
	case -78:
	case -72:
	case -66:
	case -60:
	case -54:
		sub_07D6E9(x);
		break;
	case -94:
		u = sub_07D6FD(x);
		break;
	case -92:
	case -68:
		sub_07D719(x);
		break;
	case -88:
		u = sub_07D727(x);
		break;
	case -86:
	case -62:
		sub_07D743(x);
		break;
	case -82:
		u = sub_07D751(x);
		break;
	case -80:
	case -56:
		sub_07D76D(x);
		break;
	case -76:
	case -64:
	case -58:
		sub_07D78D(x);
		break;
	case -70:
		sub_07D7AC(x);
		break;
	case -52:
		u = sub_07D806(x, u);
		break;
	case -50:
		u = sub_07D833(x, u);
		break;
	case -48:
		sub_07D87C(x);
		break;
	case -46:
	case -36:
		sub_07D99A(x);
		break;
	case -44:
		u = sub_07D886(x);
		break;
	case -42:
		sub_07D8E8(x);
		break;
	case -40:
		sub_07D8F3(x);
		break;
	case -38:
		u = sub_07D948(x, u);
		break;
	case -34:
		u = sub_07D9B9(x);
		break;
	case -28:
		u = sub_07DA71(x, u);
		break;
	case -26:
		sub_07DAC4(x);
		break;
	case -24:
		u = sub_07DAD8(x, u);
		break;
	case -22:
		sub_07DB35(x);
		break;
	case -20:
		u = sub_07DB4C(x, u);
		break;
	case -18:
		sub_07DBD8(x);
		break;
	case -16:
	case -10:
		u = sub_07DBF3(x);
		break;
	case -14:
		sub_07DB95(x);
		break;
	case -12:
		u = sub_07DBB3(x, u);
		break;
	case -8:
		sub_07DC09(x);
		break;
	case -6:
		sub_07DC35(x);
		break;
	case -4:
		u = sub_07DC4B(x, u);
		break;
	case -2:
		u = sub_07DC86(x, u);
		break;
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_07DCA2(uint16_t x, uint16_t u)
{
	uint8_t t1 = 0, t2 = 0;

	mem_write8(x + 0x3Bu, 7u);
	t1 = mem_read8(x + 0x36u);
	mem_write8(x + 0x3Eu, t1);
	if ((int8_t)unk_4858 >= 0)
		mem_write8(x + 0x3Du, 0xFFu);
	else
		mem_write8(x + 0x3Du, 0u);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	return sub_07DCBF(x, u);
}

uint16_t sub_07DCBF(uint16_t x, uint16_t u)
{
	uint8_t a = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	mem_write8(x + 5u, 0x81u);
	t1 = mem_read8(x + 0x3Eu);
	a = t1;
	t2 = mem_read8(x + 0x3Du);
	if (t2 != 0u)
		a += 0x50u;
	else
		a -= 0x30u;
	mem_write8(x + 0x3Eu, a);
	d = (uint32_t)a << 8;
	return sub_07CCDD(x, u, d);
}

uint16_t sub_07DCD8(uint16_t x, uint16_t u)
{
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = mem_read8(x + VIDEO_0031);
	if ((int8_t)t1 < 0)
	{
		t2 = mem_read8(x + 0x3Du);
		mem_write8(x + 0x3Du, ~t2);
		return sub_07DCBF(x, u);
	}
	t3 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t3 - 1u);
	if (t3 == 1u)
	{
		mem_write8(x + 0x3Bu, 0x48u);
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
		mem_write8(x + 5u, 0x86u);
		t4 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t4 + 1u);
	}
	return u;
}

uint16_t sub_07DCFB(uint16_t x, uint16_t u)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return u;
	mem_write8(x + 0x3Bu, 7u);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 - 1u);
	return sub_07DCBF(x, u);
}

void sub_07DD0B(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0, d_2 = 0;
	uint16_t u = 0;

	u = loaded_table_07F228_ADDRESS;
	b = (uint32_t)d << 1;
	switch ((int8_t)b)
	{
	case 0:
		sub_07DD11(x);
		break;
	case 2:
		sub_07DD3E(x);
		break;
	case 4:
		sub_07DD63(x);
		break;
	case -38:
	case 6:
		sub_07DA0F(x);
		break;
	case -36:
	case 8:
		sub_07DA1A(x);
		break;
	case 10:
		sub_07DD7D(x);
		break;
	case 12:
		sub_07DDA0(x);
		break;
	case 14:
		sub_07DDB9(x);
		break;
	case -122:
		d_2 = b;
		sub_07D6BE(x, d_2, &y, &u, p_left_caller);
		break;
	case -120:
		d_2 = b;
		sub_07D6F7(x, d_2, &y, &u, p_left_caller);
		break;
	case -118:
		d_2 = b;
		sub_07D721(x, d_2, &y, &u, p_left_caller);
		break;
	case -116:
		d_2 = b;
		sub_07D74B(x, d_2, &y, &u, p_left_caller);
		break;
	case -114:
		d_2 = b;
		sub_07D787(x, d_2, &y, &u, p_left_caller);
		break;
	case -112:
		d_2 = b;
		sub_07D7A6(x, d_2, &y, &u, p_left_caller);
		break;
	case -110:
		d_2 = b;
		sub_07D7C5(x, d_2, &y, &u, p_left_caller);
		break;
	case -108:
		d_2 = b;
		sub_07D7CB(x, d_2, &y, &u, p_left_caller);
		break;
	case -106:
		u = sub_07D6C4(x);
		break;
	case -104:
	case -80:
		sub_07D6E0(x);
		break;
	case -102:
	case -96:
	case -90:
	case -84:
	case -78:
	case -72:
	case -66:
	case -60:
		sub_07D6E9(x);
		break;
	case -100:
		u = sub_07D6FD(x);
		break;
	case -98:
	case -74:
		sub_07D719(x);
		break;
	case -94:
		u = sub_07D727(x);
		break;
	case -92:
	case -68:
		sub_07D743(x);
		break;
	case -88:
		u = sub_07D751(x);
		break;
	case -86:
	case -62:
		sub_07D76D(x);
		break;
	case -82:
	case -70:
	case -64:
		sub_07D78D(x);
		break;
	case -76:
		sub_07D7AC(x);
		break;
	case -58:
		u = sub_07D806(x, u);
		break;
	case -56:
		u = sub_07D833(x, u);
		break;
	case -54:
		sub_07D87C(x);
		break;
	case -52:
	case -42:
		sub_07D99A(x);
		break;
	case -50:
		u = sub_07D886(x);
		break;
	case -48:
		sub_07D8E8(x);
		break;
	case -46:
		sub_07D8F3(x);
		break;
	case -44:
		u = sub_07D948(x, u);
		break;
	case -40:
		u = sub_07D9B9(x);
		break;
	case -34:
		u = sub_07DA71(x, u);
		break;
	case -32:
		sub_07DAC4(x);
		break;
	case -30:
		u = sub_07DAD8(x, u);
		break;
	case -28:
		sub_07DB35(x);
		break;
	case -26:
		u = sub_07DB4C(x, u);
		break;
	case -24:
		sub_07DBD8(x);
		break;
	case -22:
	case -16:
		u = sub_07DBF3(x);
		break;
	case -20:
		sub_07DB95(x);
		break;
	case -18:
		u = sub_07DBB3(x, u);
		break;
	case -14:
		sub_07DC09(x);
		break;
	case -12:
		sub_07DC35(x);
		break;
	case -10:
		u = sub_07DC4B(x, u);
		break;
	case -8:
		u = sub_07DC86(x, u);
		break;
	case -6:
		u = sub_07DCA2(x, u);
		break;
	case -4:
		u = sub_07DCD8(x, u);
		break;
	case -2:
		u = sub_07DCFB(x, u);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_07DD11(uint16_t x)
{
	uint8_t t1 = 0, t4 = 0;
	uint16_t t2 = 0, t3 = 0;

	mem_write8(x + 5u, 0x90u);
	mem_write8(x + 0x3Bu, 0x40u);
	mem_write16(x + 0x14u, 0u);
	mem_write16(x + 0xFu, 0x200u);
	mem_write16(x + 0x3Eu, 0xFFE0u);
	t1 = mem_read8(x + 0x36u);
	if ((int8_t)(t1 - 0x40u) >= 0)
	{
		t2 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t2);
		t3 = mem_read16(x + 0x3Eu);
		mem_write16(x + 0x3Eu, 0u - t3);
	}
	sub_07D249(x);
	t4 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t4 + 1u);
}

void sub_07DD3E(uint16_t x)
{
	uint8_t a = 0;
	uint8_t t1 = 0, t4 = 0;
	uint16_t t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	t2 = mem_read16(x + 0x2Cu);
	if (t2 > 0x40u)
		return;
	t3 = mem_read16(x + 0x2Eu);
	if (t3 < 0x10u || (int8_t)(uint8_t)unk_4815 >= 0)
		a = 8u;
	else
		a = 0x28u;
	mem_write8(x + 0x3Bu, a);
	t4 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t4 + 1u);
}

void sub_07DD63(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;
	uint16_t t3 = 0, t4 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	t2 = mem_read8(x + 0x3Bu);
	if ((uint16_t)((uint32_t)t2 << 8) >> 8 < 8u)
	{
		t3 = mem_read16(x + 0xFu);
		t4 = mem_read16(x + 0x3Eu);
		mem_write16(x + 0xFu, t3 + t4);
	}
}

void sub_07DD77(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0, d_2 = 0;
	uint16_t u = 0;

	u = loaded_table_07F22E_ADDRESS;
	b = (uint32_t)d << 1;
	switch ((int8_t)b)
	{
	case -44:
	case 0:
		sub_07DA0F(x);
		break;
	case -42:
	case 2:
		sub_07DA1A(x);
		break;
	case 4:
		sub_07DD7D(x);
		break;
	case 6:
		sub_07DDA0(x);
		break;
	case 8:
		sub_07DDB9(x);
		break;
	case -128:
		d_2 = b;
		sub_07D6BE(x, d_2, &y, &u, p_left_caller);
		break;
	case -126:
		d_2 = b;
		sub_07D6F7(x, d_2, &y, &u, p_left_caller);
		break;
	case -124:
		d_2 = b;
		sub_07D721(x, d_2, &y, &u, p_left_caller);
		break;
	case -122:
		d_2 = b;
		sub_07D74B(x, d_2, &y, &u, p_left_caller);
		break;
	case -120:
		d_2 = b;
		sub_07D787(x, d_2, &y, &u, p_left_caller);
		break;
	case -118:
		d_2 = b;
		sub_07D7A6(x, d_2, &y, &u, p_left_caller);
		break;
	case -116:
		d_2 = b;
		sub_07D7C5(x, d_2, &y, &u, p_left_caller);
		break;
	case -114:
		d_2 = b;
		sub_07D7CB(x, d_2, &y, &u, p_left_caller);
		break;
	case -112:
		u = sub_07D6C4(x);
		break;
	case -110:
	case -86:
		sub_07D6E0(x);
		break;
	case -108:
	case -102:
	case -96:
	case -90:
	case -84:
	case -78:
	case -72:
	case -66:
		sub_07D6E9(x);
		break;
	case -106:
		u = sub_07D6FD(x);
		break;
	case -104:
	case -80:
		sub_07D719(x);
		break;
	case -100:
		u = sub_07D727(x);
		break;
	case -98:
	case -74:
		sub_07D743(x);
		break;
	case -94:
		u = sub_07D751(x);
		break;
	case -92:
	case -68:
		sub_07D76D(x);
		break;
	case -88:
	case -76:
	case -70:
		sub_07D78D(x);
		break;
	case -82:
		sub_07D7AC(x);
		break;
	case -64:
		u = sub_07D806(x, u);
		break;
	case -62:
		u = sub_07D833(x, u);
		break;
	case -60:
		sub_07D87C(x);
		break;
	case -58:
	case -48:
		sub_07D99A(x);
		break;
	case -56:
		u = sub_07D886(x);
		break;
	case -54:
		sub_07D8E8(x);
		break;
	case -52:
		sub_07D8F3(x);
		break;
	case -50:
		u = sub_07D948(x, u);
		break;
	case -46:
		u = sub_07D9B9(x);
		break;
	case -40:
		u = sub_07DA71(x, u);
		break;
	case -38:
		sub_07DAC4(x);
		break;
	case -36:
		u = sub_07DAD8(x, u);
		break;
	case -34:
		sub_07DB35(x);
		break;
	case -32:
		u = sub_07DB4C(x, u);
		break;
	case -30:
		sub_07DBD8(x);
		break;
	case -28:
	case -22:
		u = sub_07DBF3(x);
		break;
	case -26:
		sub_07DB95(x);
		break;
	case -24:
		u = sub_07DBB3(x, u);
		break;
	case -20:
		sub_07DC09(x);
		break;
	case -18:
		sub_07DC35(x);
		break;
	case -16:
		u = sub_07DC4B(x, u);
		break;
	case -14:
		u = sub_07DC86(x, u);
		break;
	case -12:
		u = sub_07DCA2(x, u);
		break;
	case -10:
		u = sub_07DCD8(x, u);
		break;
	case -8:
		u = sub_07DCFB(x, u);
		break;
	case -6:
		sub_07DD11(x);
		break;
	case -4:
		sub_07DD3E(x);
		break;
	case -2:
		sub_07DD63(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_07DD7D(uint16_t x)
{
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	sub_07D7DA(x);
	mem_write8(x + 0x3Bu, 0x20u);
	mem_write8(x + VIDEO_003C, 4u);
	mem_write16(x + 0x14u, 0u);
	mem_write16(x + 0xFu, 0x100u);
	t1 = mem_read8(x + 0x36u);
	if ((int8_t)(t1 - 0x40u) >= 0)
	{
		t2 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t2);
	}
	t3 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t3 + 1u);
}

void sub_07DDA0(uint16_t x)
{
	uint8_t t1 = 0, t3 = 0, t4 = 0;
	uint16_t t2 = 0;

	sub_07D7DA(x);
	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 0x3Bu, 0x20u);
		t2 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t2);
		t3 = mem_read8(x + VIDEO_003C);
		mem_write8(x + VIDEO_003C, t3 - 1u);
		if (t3 == 1u)
		{
			t4 = mem_read8(x + 0x29u);
			mem_write8(x + 0x29u, t4 + 1u);
		}
	}
}

void sub_07DDB9(uint16_t x)
{
	mem_write8(x + 0x3Bu, 0u);
}

void unused_07DDBD(void)
{
	uint32_t carry = 0;
	uint16_t d = 0;

	d = 0x6300u;
	carry = sub_078680(d);
}

void sub_07DDC3(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint32_t left_caller = 0;

	u = loaded_table_07F248_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)d << 1))
	{
	case 0:
		left_caller = 0u;
		sub_07DDC9(x);
		break;
	case 2:
	case 6:
	case 10:
	case 24:
		left_caller = 0u;
		y = sub_07DDDE(x, y);
		break;
	case 4:
		left_caller = 0u;
		sub_07DDF9(x);
		break;
	case 8:
		left_caller = 0u;
		sub_07DE14(x);
		break;
	case 12:
		left_caller = 0u;
		sub_07DE32(x);
		break;
	case 14:
		left_caller = 0u;
		sub_07DE68(x);
		break;
	case 16:
		left_caller = 0u;
		sub_07DEBA(x);
		break;
	case 18:
		left_caller = 0u;
		sub_07DEF0(x);
		break;
	case 20:
		left_caller = 0u;
		sub_07DF3B(x);
		break;
	case 22:
		left_caller = 0u;
		sub_07DF52(x);
		break;
	case 26:
		left_caller = 0u;
		sub_07DF66(x);
		break;
	case 28:
		sub_07DF83(x, &u, &left_caller);
		break;
	case 30:
		left_caller = 0u;
		sub_07DFA1(x);
		break;
	case 32:
		left_caller = 0u;
		sub_07DFBA(x);
		break;
	case 34:
	case 40:
		left_caller = 0u;
		sub_07DFE7(x);
		break;
	case 36:
	case 42:
		left_caller = 0u;
		sub_07E010(x);
		break;
	case 38:
		left_caller = 0u;
		sub_07E031(x);
		break;
	case 44:
		left_caller = 0u;
		sub_07E064(x);
		break;
	case 46:
	case 52:
		left_caller = 0u;
		sub_07E0AC(x);
		break;
	case 48:
	case 54:
		sub_07E0EC(x, &u, &left_caller);
		break;
	case 50:
		left_caller = 0u;
		sub_07E135(x);
		break;
	case 56:
		left_caller = 0u;
		sub_07E149(x);
		break;
	case 58:
		sub_07E155(x, &u, &left_caller);
		break;
	}
	*p_y = y;
	*p_u = u;
	*p_left_caller = left_caller;
}

void sub_07DDC9(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	d = 0x6300u;
	carry = sub_078680(d);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write8(x + 5u, 0x8Bu);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

uint16_t sub_07DDDE(uint16_t x, uint16_t y)
{
	uint16_t y_2 = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) == 0u)
		return y;
	mem_write8(x, 0xC0u);
	t2 = mem_read16(x + 0x48u);
	y_2 = t2;
	sub_0785B4(x, y_2);
	mem_write8(x + 2u, 2u);
	mem_write8(x + 0x3Bu, 0u);
	return y_2;
}

void sub_07DDF3(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint32_t left_caller = 0;

	u = loaded_table_07F24C_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)d << 1))
	{
	case 0:
		left_caller = 0u;
		sub_07DDF9(x);
		break;
	case -2:
	case 2:
	case 6:
	case 20:
		left_caller = 0u;
		y = sub_07DDDE(x, y);
		break;
	case 4:
		left_caller = 0u;
		sub_07DE14(x);
		break;
	case 8:
		left_caller = 0u;
		sub_07DE32(x);
		break;
	case 10:
		left_caller = 0u;
		sub_07DE68(x);
		break;
	case 12:
		left_caller = 0u;
		sub_07DEBA(x);
		break;
	case 14:
		left_caller = 0u;
		sub_07DEF0(x);
		break;
	case 16:
		left_caller = 0u;
		sub_07DF3B(x);
		break;
	case 18:
		left_caller = 0u;
		sub_07DF52(x);
		break;
	case 22:
		left_caller = 0u;
		sub_07DF66(x);
		break;
	case 24:
		sub_07DF83(x, &u, &left_caller);
		break;
	case 26:
		left_caller = 0u;
		sub_07DFA1(x);
		break;
	case 28:
		left_caller = 0u;
		sub_07DFBA(x);
		break;
	case 30:
	case 36:
		left_caller = 0u;
		sub_07DFE7(x);
		break;
	case 32:
	case 38:
		left_caller = 0u;
		sub_07E010(x);
		break;
	case 34:
		left_caller = 0u;
		sub_07E031(x);
		break;
	case 40:
		left_caller = 0u;
		sub_07E064(x);
		break;
	case 42:
	case 48:
		left_caller = 0u;
		sub_07E0AC(x);
		break;
	case 44:
	case 50:
		sub_07E0EC(x, &u, &left_caller);
		break;
	case 46:
		left_caller = 0u;
		sub_07E135(x);
		break;
	case 52:
		left_caller = 0u;
		sub_07E149(x);
		break;
	case 54:
		sub_07E155(x, &u, &left_caller);
		break;
	case -4:
		left_caller = 0u;
		sub_07DDC9(x);
		break;
	}
	*p_y = y;
	*p_u = u;
	*p_left_caller = left_caller;
}

void sub_07DDF9(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	d = 0x6300u;
	carry = sub_078680(d);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write8(x + 5u, 0x8Au);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

void sub_07DE0E(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint32_t left_caller = 0;

	u = loaded_table_07F250_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)d << 1))
	{
	case 0:
		left_caller = 0u;
		sub_07DE14(x);
		break;
	case -6:
	case -2:
	case 2:
	case 16:
		left_caller = 0u;
		y = sub_07DDDE(x, y);
		break;
	case 4:
		left_caller = 0u;
		sub_07DE32(x);
		break;
	case 6:
		left_caller = 0u;
		sub_07DE68(x);
		break;
	case 8:
		left_caller = 0u;
		sub_07DEBA(x);
		break;
	case 10:
		left_caller = 0u;
		sub_07DEF0(x);
		break;
	case 12:
		left_caller = 0u;
		sub_07DF3B(x);
		break;
	case 14:
		left_caller = 0u;
		sub_07DF52(x);
		break;
	case 18:
		left_caller = 0u;
		sub_07DF66(x);
		break;
	case 20:
		sub_07DF83(x, &u, &left_caller);
		break;
	case 22:
		left_caller = 0u;
		sub_07DFA1(x);
		break;
	case 24:
		left_caller = 0u;
		sub_07DFBA(x);
		break;
	case 26:
	case 32:
		left_caller = 0u;
		sub_07DFE7(x);
		break;
	case 28:
	case 34:
		left_caller = 0u;
		sub_07E010(x);
		break;
	case 30:
		left_caller = 0u;
		sub_07E031(x);
		break;
	case 36:
		left_caller = 0u;
		sub_07E064(x);
		break;
	case 38:
	case 44:
		left_caller = 0u;
		sub_07E0AC(x);
		break;
	case 40:
	case 46:
		sub_07E0EC(x, &u, &left_caller);
		break;
	case 42:
		left_caller = 0u;
		sub_07E135(x);
		break;
	case 48:
		left_caller = 0u;
		sub_07E149(x);
		break;
	case 50:
		sub_07E155(x, &u, &left_caller);
		break;
	case -8:
		left_caller = 0u;
		sub_07DDC9(x);
		break;
	case -4:
		left_caller = 0u;
		sub_07DDF9(x);
		break;
	}
	*p_y = y;
	*p_u = u;
	*p_left_caller = left_caller;
}

void sub_07DE14(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	d = 0x6300u;
	carry = sub_078680(d);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write8(x + 5u, 0x89u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

void sub_07DE29(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint32_t left_caller = 0;

	u = loaded_table_07F254_ADDRESS;
	left_caller = 0u;
	switch ((int8_t)(uint8_t)((uint32_t)d << 1))
	{
	case 0:
		sub_07DE32(x);
		break;
	case 2:
		sub_07DE68(x);
		break;
	case 4:
		sub_07DEBA(x);
		break;
	case 6:
		sub_07DEF0(x);
		break;
	case 8:
		sub_07DF3B(x);
		break;
	case 10:
		sub_07DF52(x);
		break;
	case -10:
	case -6:
	case -2:
	case 12:
		y = sub_07DDDE(x, y);
		break;
	case 14:
		sub_07DF66(x);
		break;
	case 16:
		sub_07DF83(x, &u, &left_caller);
		break;
	case 18:
		sub_07DFA1(x);
		break;
	case 20:
		sub_07DFBA(x);
		break;
	case 22:
	case 28:
		sub_07DFE7(x);
		break;
	case 24:
	case 30:
		sub_07E010(x);
		break;
	case 26:
		sub_07E031(x);
		break;
	case 32:
		sub_07E064(x);
		break;
	case 34:
	case 40:
		sub_07E0AC(x);
		break;
	case 36:
	case 42:
		sub_07E0EC(x, &u, &left_caller);
		break;
	case 38:
		sub_07E135(x);
		break;
	case 44:
		sub_07E149(x);
		break;
	case 46:
		sub_07E155(x, &u, &left_caller);
		break;
	case -12:
		sub_07DDC9(x);
		break;
	case -8:
		sub_07DDF9(x);
		break;
	case -4:
		sub_07DE14(x);
		break;
	}
	if (left_caller != 0u)
		left_caller = 0u;
	else
		sub_0785BA(x);
	*p_y = y;
	*p_u = u;
	*p_left_caller = left_caller;
}

void sub_07DE32(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t4 = 0, t6 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t5 = 0;

	d = 0x6300u;
	carry = sub_078680(d);
	mem_write8(x + 5u, 0x8Eu);
	mem_write16(x + 0xFu, 0x200u);
	mem_write16(x + 0x14u, 0u);
	t1 = mem_read16(x + 0x16u);
	t2 = mem_read16(x + 0x5Cu);
	t3 = t1 - t2;
	if (t3 < 0x20u)
		mem_write16(x + 0x19u, 0x200u);
	t4 = mem_read8(x + 9u);
	if ((t4 & 0x40u) != 0u)
	{
		t5 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t5);
	}
	t6 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t6 + 1u);
}

void sub_07DE68(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t4 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read16(x + 0x19u);
	t2 = t1 - 0x20u;
	mem_write16(x + 0x19u, t2);
	carry = sub_078662(x);
	if (carry)
	{
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
		sub_07DE7C(x);
		return;
	}
	t3 = mem_read16(x + 0xFu);
	if (t3 != 0u)
		return;
	t4 = mem_read8(x + 0x42u);
	if (t4 != 0u)
		mem_write8(x + 5u, 0x95u);
	else
		mem_write8(x + 5u, 0x85u);
	mem_write16(x + 0x28u, 0x600u);
}

void sub_07DE7C(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x1Bu);
	if (t1 != 0u)
	{
		mem_write16(x + 0x28u, 0x400u);
		mem_write8(x + 0x3Bu, 0x20u);
		return;
	}
	mem_write16(x + 0x28u, 0x500u);
}

void sub_07DEB1(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint32_t left_caller = 0;

	u = loaded_table_07F258_ADDRESS;
	left_caller = 0u;
	switch ((int8_t)(uint8_t)((uint32_t)d << 1))
	{
	case 0:
		sub_07DEBA(x);
		break;
	case 2:
		sub_07DEF0(x);
		break;
	case 4:
		sub_07DF3B(x);
		break;
	case 6:
		sub_07DF52(x);
		break;
	case -14:
	case -10:
	case -6:
	case 8:
		y = sub_07DDDE(x, y);
		break;
	case 10:
		sub_07DF66(x);
		break;
	case 12:
		sub_07DF83(x, &u, &left_caller);
		break;
	case 14:
		sub_07DFA1(x);
		break;
	case 16:
		sub_07DFBA(x);
		break;
	case 18:
	case 24:
		sub_07DFE7(x);
		break;
	case 20:
	case 26:
		sub_07E010(x);
		break;
	case 22:
		sub_07E031(x);
		break;
	case 28:
		sub_07E064(x);
		break;
	case 30:
	case 36:
		sub_07E0AC(x);
		break;
	case 32:
	case 38:
		sub_07E0EC(x, &u, &left_caller);
		break;
	case 34:
		sub_07E135(x);
		break;
	case 40:
		sub_07E149(x);
		break;
	case 42:
		sub_07E155(x, &u, &left_caller);
		break;
	case -16:
		sub_07DDC9(x);
		break;
	case -12:
		sub_07DDF9(x);
		break;
	case -8:
		sub_07DE14(x);
		break;
	case -4:
		sub_07DE32(x);
		break;
	case -2:
		sub_07DE68(x);
		break;
	}
	if (left_caller != 0u)
		left_caller = 0u;
	else
		sub_0785BA(x);
	*p_y = y;
	*p_u = u;
	*p_left_caller = left_caller;
}

void sub_07DEBA(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t4 = 0, t6 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t5 = 0;

	d = 0x6300u;
	carry = sub_078680(d);
	mem_write8(x + 5u, 0x8Cu);
	mem_write16(x + 0xFu, 0xFE00u);
	mem_write16(x + 0x14u, 0u);
	t1 = mem_read16(x + 0x16u);
	t2 = mem_read16(x + 0x5Cu);
	t3 = t1 - t2;
	if (t3 < 0x20u)
		mem_write16(x + 0x19u, 0x200u);
	t4 = mem_read8(x + 9u);
	if ((t4 & 0x40u) != 0u)
	{
		t5 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t5);
	}
	t6 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t6 + 1u);
}

void sub_07DEF0(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t3 = 0, t4 = 0, t6 = 0;
	uint16_t t1 = 0, t2 = 0, t5 = 0;

	t1 = mem_read16(x + 0x19u);
	t2 = t1 - 0x20u;
	mem_write16(x + 0x19u, t2);
	carry = sub_078662(x);
	if (carry)
	{
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
		mem_write8(x + 5u, 0x8Du);
		t3 = mem_read8(x + 0x1Bu);
		if (t3 != 0u)
		{
			mem_write8(x + 0x3Bu, 4u);
			t4 = mem_read8(x + 0x29u);
			mem_write8(x + 0x29u, t4 + 1u);
			return;
		}
		mem_write16(x + 0x28u, 0x500u);
		return;
	}
	t5 = mem_read16(x + 0xFu);
	if (t5 != 0u)
		return;
	t6 = mem_read8(x + 0x42u);
	if (t6 != 0u)
		mem_write8(x + 5u, 0x96u);
	else
		mem_write8(x + 5u, 0x84u);
	mem_write16(x + 0x28u, 0x600u);
}

void sub_07DF3B(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 0x3Bu, 0x10u);
		mem_write16(x + 0x28u, 0x400u);
	}
}

void sub_07DF4C(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint32_t left_caller = 0;

	u = loaded_table_07F25E_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)d << 1))
	{
	case 0:
		left_caller = 0u;
		sub_07DF52(x);
		break;
	case -20:
	case -16:
	case -12:
	case 2:
		left_caller = 0u;
		y = sub_07DDDE(x, y);
		break;
	case 4:
		left_caller = 0u;
		sub_07DF66(x);
		break;
	case 6:
		sub_07DF83(x, &u, &left_caller);
		break;
	case 8:
		left_caller = 0u;
		sub_07DFA1(x);
		break;
	case 10:
		left_caller = 0u;
		sub_07DFBA(x);
		break;
	case 12:
	case 18:
		left_caller = 0u;
		sub_07DFE7(x);
		break;
	case 14:
	case 20:
		left_caller = 0u;
		sub_07E010(x);
		break;
	case 16:
		left_caller = 0u;
		sub_07E031(x);
		break;
	case 22:
		left_caller = 0u;
		sub_07E064(x);
		break;
	case 24:
	case 30:
		left_caller = 0u;
		sub_07E0AC(x);
		break;
	case 26:
	case 32:
		sub_07E0EC(x, &u, &left_caller);
		break;
	case 28:
		left_caller = 0u;
		sub_07E135(x);
		break;
	case 34:
		left_caller = 0u;
		sub_07E149(x);
		break;
	case 36:
		sub_07E155(x, &u, &left_caller);
		break;
	case -22:
		left_caller = 0u;
		sub_07DDC9(x);
		break;
	case -18:
		left_caller = 0u;
		sub_07DDF9(x);
		break;
	case -14:
		left_caller = 0u;
		sub_07DE14(x);
		break;
	case -10:
		left_caller = 0u;
		sub_07DE32(x);
		break;
	case -8:
		left_caller = 0u;
		sub_07DE68(x);
		break;
	case -6:
		left_caller = 0u;
		sub_07DEBA(x);
		break;
	case -4:
		left_caller = 0u;
		sub_07DEF0(x);
		break;
	case -2:
		left_caller = 0u;
		sub_07DF3B(x);
		break;
	}
	*p_y = y;
	*p_u = u;
	*p_left_caller = left_caller;
}

void sub_07DF52(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 5u, 0x8Fu);
		t2 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t2 + 1u);
	}
}

void sub_07DF60(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint32_t left_caller = 0;

	u = loaded_table_07F262_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)d << 1))
	{
	case 0:
		left_caller = 0u;
		sub_07DF66(x);
		break;
	case 2:
		sub_07DF83(x, &u, &left_caller);
		break;
	case 4:
		left_caller = 0u;
		sub_07DFA1(x);
		break;
	case 6:
		left_caller = 0u;
		sub_07DFBA(x);
		break;
	case 8:
	case 14:
		left_caller = 0u;
		sub_07DFE7(x);
		break;
	case 10:
	case 16:
		left_caller = 0u;
		sub_07E010(x);
		break;
	case 12:
		left_caller = 0u;
		sub_07E031(x);
		break;
	case 18:
		left_caller = 0u;
		sub_07E064(x);
		break;
	case 20:
	case 26:
		left_caller = 0u;
		sub_07E0AC(x);
		break;
	case 22:
	case 28:
		sub_07E0EC(x, &u, &left_caller);
		break;
	case 24:
		left_caller = 0u;
		sub_07E135(x);
		break;
	case 30:
		left_caller = 0u;
		sub_07E149(x);
		break;
	case 32:
		sub_07E155(x, &u, &left_caller);
		break;
	case -26:
		left_caller = 0u;
		sub_07DDC9(x);
		break;
	case -24:
	case -20:
	case -16:
	case -2:
		left_caller = 0u;
		y = sub_07DDDE(x, y);
		break;
	case -22:
		left_caller = 0u;
		sub_07DDF9(x);
		break;
	case -18:
		left_caller = 0u;
		sub_07DE14(x);
		break;
	case -14:
		left_caller = 0u;
		sub_07DE32(x);
		break;
	case -12:
		left_caller = 0u;
		sub_07DE68(x);
		break;
	case -10:
		left_caller = 0u;
		sub_07DEBA(x);
		break;
	case -8:
		left_caller = 0u;
		sub_07DEF0(x);
		break;
	case -6:
		left_caller = 0u;
		sub_07DF3B(x);
		break;
	case -4:
		left_caller = 0u;
		sub_07DF52(x);
		break;
	}
	*p_y = y;
	*p_u = u;
	*p_left_caller = left_caller;
}

void sub_07DF66(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 5u);
	if (t1 != 0xEu)
		mem_write8(x + 5u, 0x88u);
	mem_write8(x, mem_read8(x) & ~4u);
	mem_write8(x + 0x3Bu, 0x20u);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
}

void sub_07DF83(uint16_t x, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t u = (uint16_t)*p_u;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	if (t1 < 0x10u)
		sub_07864A(x);
	t2 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t2 - 1u);
	if (t2 != 1u)
		*p_left_caller = 0u;
	else
	{
		mem_write8(x, 0u);
		u = sub_078599(x, u);
		*p_left_caller = 1u;
	}
	*p_u = u;
}

void sub_07DF9B(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint32_t left_caller = 0;

	u = loaded_table_07F266_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)d << 1))
	{
	case 0:
		left_caller = 0u;
		sub_07DFA1(x);
		break;
	case 2:
		left_caller = 0u;
		sub_07DFBA(x);
		break;
	case 4:
	case 10:
		left_caller = 0u;
		sub_07DFE7(x);
		break;
	case 6:
	case 12:
		left_caller = 0u;
		sub_07E010(x);
		break;
	case 8:
		left_caller = 0u;
		sub_07E031(x);
		break;
	case 14:
		left_caller = 0u;
		sub_07E064(x);
		break;
	case 16:
	case 22:
		left_caller = 0u;
		sub_07E0AC(x);
		break;
	case 18:
	case 24:
		sub_07E0EC(x, &u, &left_caller);
		break;
	case 20:
		left_caller = 0u;
		sub_07E135(x);
		break;
	case 26:
		left_caller = 0u;
		sub_07E149(x);
		break;
	case 28:
		sub_07E155(x, &u, &left_caller);
		break;
	case -30:
		left_caller = 0u;
		sub_07DDC9(x);
		break;
	case -28:
	case -24:
	case -20:
	case -6:
		left_caller = 0u;
		y = sub_07DDDE(x, y);
		break;
	case -26:
		left_caller = 0u;
		sub_07DDF9(x);
		break;
	case -22:
		left_caller = 0u;
		sub_07DE14(x);
		break;
	case -18:
		left_caller = 0u;
		sub_07DE32(x);
		break;
	case -16:
		left_caller = 0u;
		sub_07DE68(x);
		break;
	case -14:
		left_caller = 0u;
		sub_07DEBA(x);
		break;
	case -12:
		left_caller = 0u;
		sub_07DEF0(x);
		break;
	case -10:
		left_caller = 0u;
		sub_07DF3B(x);
		break;
	case -8:
		left_caller = 0u;
		sub_07DF52(x);
		break;
	case -4:
		left_caller = 0u;
		sub_07DF66(x);
		break;
	case -2:
		sub_07DF83(x, &u, &left_caller);
		break;
	}
	*p_y = y;
	*p_u = u;
	*p_left_caller = left_caller;
}

void sub_07DFA1(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x19u);
	mem_write16(x + 0x19u, t1 - 0x10u);
	carry = sub_078662(x);
	if (carry)
	{
		sub_07DE7C(x);
		return;
	}
}

void sub_07DFB1(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint32_t left_caller = 0;

	u = loaded_table_07F268_ADDRESS;
	left_caller = 0u;
	switch ((int8_t)(uint8_t)((uint32_t)d << 1))
	{
	case 0:
		sub_07DFBA(x);
		break;
	case 2:
	case 8:
		sub_07DFE7(x);
		break;
	case 4:
	case 10:
		sub_07E010(x);
		break;
	case 6:
		sub_07E031(x);
		break;
	case 12:
		sub_07E064(x);
		break;
	case 14:
	case 20:
		sub_07E0AC(x);
		break;
	case 16:
	case 22:
		sub_07E0EC(x, &u, &left_caller);
		break;
	case 18:
		sub_07E135(x);
		break;
	case 24:
		sub_07E149(x);
		break;
	case 26:
		sub_07E155(x, &u, &left_caller);
		break;
	case -32:
		sub_07DDC9(x);
		break;
	case -30:
	case -26:
	case -22:
	case -8:
		y = sub_07DDDE(x, y);
		break;
	case -28:
		sub_07DDF9(x);
		break;
	case -24:
		sub_07DE14(x);
		break;
	case -20:
		sub_07DE32(x);
		break;
	case -18:
		sub_07DE68(x);
		break;
	case -16:
		sub_07DEBA(x);
		break;
	case -14:
		sub_07DEF0(x);
		break;
	case -12:
		sub_07DF3B(x);
		break;
	case -10:
		sub_07DF52(x);
		break;
	case -6:
		sub_07DF66(x);
		break;
	case -4:
		sub_07DF83(x, &u, &left_caller);
		break;
	case -2:
		sub_07DFA1(x);
		break;
	}
	if (left_caller != 0u)
		left_caller = 0u;
	else
		sub_0785BA(x);
	*p_y = y;
	*p_u = u;
	*p_left_caller = left_caller;
}

void sub_07DFBA(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t4 = 0;
	uint16_t t2 = 0, t3 = 0;

	mem_write8(x + 0x3Bu, 0x20u);
	d = 0x6300u;
	carry = sub_078680(d);
	mem_write8(x + 5u, 0x98u);
	mem_write16(x + 0xFu, 0x200u);
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

void sub_07DFE7(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t4 = 0, t5 = 0;
	uint16_t t3 = 0, t6 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		t2 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t2 + 1u);
	}
	t3 = mem_read16(x + 0x19u);
	mem_write16(x + 0x19u, t3 - 0x20u);
	carry = sub_078662(x);
	t4 = mem_read8(x + VIDEO_0031);
	d = (uint32_t)t4 << 8;
	if (((d >> 8) & 0x80u) != 0u && ((d >> 8) & 8u) == 0u)
	{
		t5 = mem_read8(x + 0x17u);
		mem_write8(x + 0x17u, t5 + 1u);
		t6 = mem_read16(x + 0x3Eu);
		mem_write16(x + 0xFu, t6);
	}
}
