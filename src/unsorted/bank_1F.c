/**
 *    Name:        unsorted/bank_1F.c
 *    Description: bank 1F's code
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    06-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

uint16_t sub_03E000(uint16_t u)
{
	uint16_t ignored16 = 0, x = 0;

	x = 0x5640u;
	io_write16(VIDEO_1852, 0x5640u);
	unk_5670 = 0x10u;
	sub_03E05A(&x, &ignored16, &u);
	return u;
}

void sub_03E003(void)
{
	uint8_t a = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, x = 0, y = 0;
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0, t4 = 0, t5 = 0;

	x = 0x5640u;
	unk_5670 = 0x14u;
	sub_03E05A(&x, &ignored16, &ignored16_2);
	t1 = mem_read16(x + 0x47u);
	y = t1;
	mem_write8(y + 0x5Bu, 1u);
	t2 = mem_read16(y + 0x16u);
	if ((int16_t)t2 < 0)
	{
		mem_write16(y + 0x16u, 0u);
		t3 = mem_read8(y + 6u);
		a = t3 | 0x80u;
		mem_write8(y + 6u, a);
		t4 = mem_read16(x + 0x43u);
		y = t4;
		mem_write16(y + 0x16u, 0u);
		mem_write8(y + 6u, a);
		t5 = mem_read16(x + 0x45u);
		y = t5;
		mem_write16(y + 0x16u, 0u);
		mem_write8(y + 6u, a);
	}
}

void sub_03E006(uint32_t y, uint16_t *p_x, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t u = (uint16_t)*p_u;
	uint16_t ignored16 = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0, t3 = 0, t4 = 0;

	if (mem_read8(x) != 4u)
		sub_03E05A(&x, &ignored16, &u);
	else
	{
		t1 = mem_read16(x + 0x40u);
		t2 = mem_read8(t1 + 4u);
		mem_write8(x + 4u, t2);
		t3 = mem_read16(x + 0x16u);
		t4 = t3 + 0x40u;
		mem_write16(x + 0x16u, t4);
		sub_03E05A(&x, &ignored16, &u);
	}
	*p_x = x;
	*p_u = u;
}

void sub_03E009(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, x = 0;

	x = 0x5640u;
	unk_5670 = 0x2Cu;
	sub_03E05A(&x, &ignored16, &ignored16_2);
}

void unused_03E00C(void)
{
}

void unused_03E00F(void)
{
}

void sub_03E012(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, x = 0;

	x = 0x5640u;
	unk_5670 = 0x1Cu;
	sub_03E05A(&x, &ignored16, &ignored16_2);
}

uint16_t sub_03E015(uint16_t x)
{
	uint16_t ignored16 = 0, ignored16_2 = 0;

	io_write16(VIDEO_1852, x);
	mem_write8(x + 0x30u, 0x20u);
	sub_03E05A(&x, &ignored16, &ignored16_2);
	return x;
}

void sub_03E018(uint32_t y, uint16_t *p_x, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t u = (uint16_t)*p_u;
	uint16_t ignored16 = 0;

	io_write16(VIDEO_1854, x);
	*p_x = x;
	*p_u = u;
	sub_03E05A(p_x, &ignored16, p_u);
}

void sub_03E01B(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, x = 0;

	x = 0x5640u;
	unk_5670 = 0x30u;
	sub_03E05A(&x, &ignored16, &ignored16_2);
}

void sub_03E01E(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, x = 0;
	uint16_t t1 = 0;

	x = 0x5640u;
	io_write16(VIDEO_1854, 0x5640u);
	unk_5670 = 0xCu;
	t1 = io_read16(VIDEO_1852);
	unk_5685 = t1;
	sub_03E05A(&x, &ignored16, &ignored16_2);
}

void sub_03E021(void)
{
}

void sub_03E024(uint32_t y, uint16_t *p_x, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t u = (uint16_t)*p_u;
	uint16_t ignored16 = 0;

	*p_x = x;
	*p_u = u;
	sub_03E05A(p_x, &ignored16, p_u);
}

void sub_03E027(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, x = 0;

	io_write16(VIDEO_1852, 0x4AA0u);
	x = 0x5640u;
	sub_03E05A(&x, &ignored16, &ignored16_2);
}

void sub_03E02A(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, x = 0;

	x = 0x5640u;
	unk_5670 = 0x38u;
	sub_03E05A(&x, &ignored16, &ignored16_2);
}

void unused_03E02D(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, x = 0;

	x = 0x5640u;
	io_write16(VIDEO_1854, 0x5640u);
	unk_5670 = 0x24u;
	sub_03E05A(&x, &ignored16, &ignored16_2);
}

void sub_03E030(uint32_t y, uint16_t *p_x, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t u = (uint16_t)*p_u;
	uint16_t ignored16 = 0;

	*p_x = x;
	*p_u = u;
	sub_03E05A(p_x, &ignored16, p_u);
}

void sub_03E033(uint32_t y, uint16_t *p_x, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t u = (uint16_t)*p_u;
	uint16_t ignored16 = 0;

	*p_x = x;
	*p_u = u;
	sub_03E05A(p_x, &ignored16, p_u);
}

uint16_t sub_03E036(uint16_t u)
{
	uint16_t ignored16 = 0, x = 0;

	x = 0x5640u;
	io_write16(VIDEO_1854, 0x5640u);
	unk_5670 = 0x24u;
	sub_03E05A(&x, &ignored16, &u);
	return u;
}

void sub_03E039(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, x = 0;

	x = 0x5640u;
	unk_5670 = 0x30u;
	sub_03E05A(&x, &ignored16, &ignored16_2);
}

void sub_03E03C(uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t x = 0;

	x = 0x5640u;
	io_write16(VIDEO_1852, 0x5640u);
	unk_5670 = 0x34u;
	*p_y = y;
	*p_u = u;
	sub_03E05A(&x, p_y, p_u);
}

uint16_t sub_03E03F(void)
{
	uint16_t u = 0, x = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t4 = 0;
	uint16_t t3 = 0;

	u = unk_4A40_ADDRESS;
	sub_03EAB3(u);
	u = unk_4B00_ADDRESS;
	sub_03EAB3(u);
	u = unk_4BC0_ADDRESS;
	sub_03EAB3(u);
	u = unk_4C80_ADDRESS;
	sub_03EAB3(u);
	t1 = io_read8(VIDEO_184D);
	if ((int8_t)t1 >= 2)
	{
		unk_48F0 = 4u;
		u = unk_4A40_ADDRESS;
		do
		{
			t2 = mem_read8(u + 0x30u);
			if (t2 == 0x2Cu)
			{
				mem_write16(u + 0x30u, 0x2D0Fu);
				t3 = mem_read16(u + 0x3Fu);
				y = t3;
				mem_write8(y + 2u, 3u);
				mem_write16(y + 0x16u, 0x20u);
				mem_write8(u + 5u, 0xCBu);
				mem_write8(u, 0x80u);
				mem_write8(u + 0x41u, 0u);
			}
			u += 0xC0u;
			t4 = unk_48F0;
			unk_48F0 = t4 - 1u;
		} while (t4 != 1u);
	}
	if (unk_48E6 == 0u)
		return u;
	if ((int16_t)unk_48E6 >= 0)
		x = 0x200u;
	else
		x = 0xFE00u;
	unk_48E6 = x;
	return u;
}

void sub_03E042(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, x = 0;

	x = 0x5640u;
	unk_5670 = 0x4Cu;
	sub_03E05A(&x, &ignored16, &ignored16_2);
}

void unused_03E045(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, x = 0;

	x = 0x5640u;
	unk_5670 = 0x50u;
	sub_03E05A(&x, &ignored16, &ignored16_2);
}

void sub_03E048(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, x = 0;

	x = 0x5640u;
	unk_5670 = 0x54u;
	sub_03E05A(&x, &ignored16, &ignored16_2);
}

uint16_t sub_03E04B(uint16_t u)
{
	uint16_t ignored16 = 0, x = 0;

	x = 0x5640u;
	unk_5670 = 0x58u;
	sub_03E05A(&x, &ignored16, &u);
	return u;
}

void sub_03E04E(void)
{
	uint8_t a = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, x = 0;
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	x = 0x5640u;
	unk_5670 = 0x5Cu;
	t1 = io_read8(VIDEO_1854);
	a = t1;
	if (t1 == 0u)
	{
		sub_03E05A(&x, &ignored16, &ignored16_2);
		return;
	}
	t2 = io_read16(VIDEO_1852);
	mem_write8(t2 + 0x2Au, a - 1u);
	t3 = io_read8(VIDEO_1854);
	io_write8(VIDEO_1854, 0u);
	sub_03E05A(&x, &ignored16, &ignored16_2);
}

void sub_03E051(uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t zero = 0;
	uint8_t a = 0, b = 0;
	uint16_t u = 0, x = 0;
	uint16_t stack = 0;
	uint8_t t3 = 0, t4 = 0;
	uint16_t t1 = 0, t2 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0;

	x = 0x5640u;
	unk_5671 = 0u;
	t1 = io_read16(VIDEO_1852);
	u = t1;
	t2 = mem_read16(u + 0xCu);
	a = (uint8_t)(t2 >> 8);
	b = (uint8_t)t2;
	if ((int16_t)(((uint32_t)a << 8) | b) < 0xAF)
	{
		a = 0xFEu;
		b = 0u;
		unk_5671 = ((uint32_t)a << 8) | b;
		mem_write16(x + 0x33u, 0xFF00u);
	}
	else if ((int16_t)(((uint32_t)a << 8) | b) > 0xB1)
	{
		a = 2u;
		b = 0u;
		unk_5671 = ((uint32_t)a << 8) | b;
		mem_write16(x + 0x33u, 0xFF00u);
	}
	stack = x;
	x = sub_03E7F3();
	do
	{
		t3 = mem_read8(x);
		a = t3;
		if (t3 != 0u)
		{
			mem_write8(x, a | 0x40u);
			t4 = mem_read8(x + 4u);
			t5 = (int8_t)((((((uint32_t)t4 << 1) << 1) << 1) << 1) << 1);
			t6 = io_read16(VIDEO_1852);
			u = t6;
			t7 = mem_read16(u + 0xCu);
			t8 = t5 + t7;
			mem_write16(x + 0x6Cu, t8);
			t9 = mem_read16(u + 0x11u);
			t10 = t9 + 0x10u;
			mem_write16(x + 0x71u, t10);
		}
		sub_03E7FC(&x, &zero);
	} while (zero == 0u);
	x = stack;
	unk_5670 = 0x60u;
	*p_y = y;
	*p_u = u;
	sub_03E05A(&x, p_y, p_u);
}

void sub_03E054(uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t zero = 0;
	uint8_t a = 0, b = 0;
	uint16_t x = 0;
	uint16_t stack = 0;
	uint8_t t2 = 0, t3 = 0;
	uint16_t t1 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0;

	x = 0x5640u;
	unk_5670 = 0x64u;
	unk_5671 = 0u;
	t1 = unk_48AC;
	a = (uint8_t)(t1 >> 8);
	b = (uint8_t)t1;
	if ((int16_t)(((uint32_t)a << 8) | b) < 0x33C)
	{
		a = 2u;
		b = 0u;
		unk_5671 = ((uint32_t)a << 8) | b;
	}
	else if ((int16_t)(((uint32_t)a << 8) | b) > 0x33E)
	{
		a = 0xFEu;
		b = 0u;
		unk_5671 = ((uint32_t)a << 8) | b;
	}
	stack = x;
	x = sub_03E7F3();
	do
	{
		t2 = mem_read8(x);
		a = t2;
		if (t2 != 0u)
		{
			mem_write8(x, a | 0x40u);
			t3 = mem_read8(x + 4u);
			t4 = (int8_t)((((((uint32_t)t3 << 1) << 1) << 1) << 1) << 1);
			t5 = t4 + 0x3EDu;
			t6 = t5 - unk_48AC;
			mem_write16(x + 0x6Cu, t6);
			t7 = 0xB0u + unk_48B2;
			mem_write16(x + 0x71u, t7);
		}
		sub_03E7FC(&x, &zero);
	} while (zero == 0u);
	x = stack;
	mem_write16(x + 0x33u, 0x100u);
	*p_y = y;
	*p_u = u;
	sub_03E05A(&x, p_y, p_u);
}

void sub_03E057(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, x = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	y = loaded_table_03FEDC_ADDRESS + (int8_t)((((uint32_t)unk_4867 << 1) << 1) << 1);
	x = VIDEO_1840;
	u = 8u;
	while (u != 0u)
	{
		mem_write8(x, mem_read8(y));
		y++;
		x++;
		u--;
	}
	t1 = io_read8(VIDEO_184B);
	io_write8(VIDEO_184B, 0u);
	t2 = io_read8(VIDEO_184E);
	io_write8(VIDEO_184E, 0u);
	t3 = io_read8(VIDEO_1850);
	io_write8(VIDEO_1850, 0u);
	t4 = io_read8(VIDEO_185A);
	io_write8(VIDEO_185A, 0u);
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

void sub_03E05A(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t negative = 0, carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, u_2 = 0, x_2 = 0, y_2 = 0;
	uint8_t stack = 0, stack_2 = 0, stack_3 = 0;
	uint8_t t1 = 0, t2 = 0, t5 = 0, t6 = 0, t16 = 0, t23 = 0, t25 = 0, t26 = 0, t27 = 0, t28 = 0, t29 = 0, t30 = 0, t31 = 0, t44 = 0, t45 = 0, t47 = 0, t48 = 0, t49 = 0, t51 = 0, t52 = 0, t55 = 0, t56 = 0, t57 = 0, t58 = 0, t59 = 0, t66 = 0, t67 = 0;
	uint16_t t3 = 0, t4 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0, t15 = 0, t17 = 0, t18 = 0, t19 = 0, t20 = 0, t21 = 0, t22 = 0, t24 = 0, t32 = 0, t33 = 0, t34 = 0, t35 = 0, t36 = 0, t37 = 0, t38 = 0, t39 = 0, t40 = 0, t41 = 0, t42 = 0, t43 = 0, t46 = 0, t50 = 0, t53 = 0, t54 = 0, t60 = 0, t61 = 0, t62 = 0, t63 = 0, t64 = 0, t65 = 0;

	t1 = mem_read8(x);
	a = t1;
	if (t1 != 0u)
	{
		if (a == 4u)
		{
			mem_write8(x, 0x80u);
			mem_write16(x + 0xAu, 0u);
			mem_write16(x + 0xFu, 0u);
			mem_write16(x + 0x14u, 0u);
			mem_write16(x + 0x19u, 0u);
			t2 = mem_read8(x + 0x30u);
			t3 = mem_read16(x + 0x40u);
			y_2 = t3;
			stack_2 = x >> 8;
			stack = (uint8_t)x;
			stack_3 = t2;
			a = 0u;
			b = 0u;
			x += 0x28u;
			u = 0x18u;
			while (u != 0u)
			{
				mem_write8(x, a);
				mem_write8(x + 1u, b);
				x += 2u;
				u--;
			}
			b = stack_3;
			x = ((uint32_t)stack_2 << 8) | stack;
			io_write8(x + 0x30u, b);
			io_write16(x + 0x40u, y_2);
			io_write8(x + 0x58u, 0u);
			io_write8(x + 0x2Du, 1u);
			y = DATA16(story_scripts_ADDRESS + (uint8_t)((uint32_t)b << 1));
			io_write16(x + 0x2Eu, y);
		}
	}
	else
	{
		if (x != 0x5640u)
			return;
		mem_write8(x, 0x80u);
		mem_write16(x + 0xAu, 0u);
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
		mem_write16(x + 0x19u, 0u);
		t2 = mem_read8(x + 0x30u);
		t3 = mem_read16(x + 0x40u);
		y_2 = t3;
		stack_2 = x >> 8;
		stack = (uint8_t)x;
		stack_3 = t2;
		a = 0u;
		b = 0u;
		x += 0x28u;
		u = 0x18u;
		while (u != 0u)
		{
			mem_write8(x, a);
			mem_write8(x + 1u, b);
			x += 2u;
			u--;
		}
		b = stack_3;
		x = ((uint32_t)stack_2 << 8) | stack;
		io_write8(x + 0x30u, b);
		io_write16(x + 0x40u, y_2);
		io_write8(x + 0x58u, 0u);
		io_write8(x + 0x2Du, 1u);
		y = DATA16(story_scripts_ADDRESS + (uint8_t)((uint32_t)b << 1));
		io_write16(x + 0x2Eu, y);
	}
	if (x != 0x5640u)
	{
		t4 = mem_read16(x + 0x37u);
		u = t4;
		if (t4 != 0u)
		{
			t5 = mem_read8(x + 0x1Fu);
			unk_48F8 = t5;
			t6 = mem_read8(x + 0x39u);
			t7 = (int8_t)(0u - t6);
			t8 = mem_read16(x + 0xCu);
			t9 = t7 + t8;
			unk_48FA = t9;
			t10 = unk_48FA;
			t11 = t10 - unk_48F8;
			t12 = mem_read16(u + 0xCu);
			if ((int16_t)t11 < (int16_t)t12)
			{
				t13 = unk_48FA;
				t14 = t13 + unk_48F8;
				t15 = mem_read16(u + 0xCu);
				if ((int16_t)t15 < (int16_t)t14)
				{
					t16 = mem_read8(x + 0x20u);
					unk_48F8 = t16;
					t17 = mem_read16(x + 0x11u);
					t18 = t17 - unk_48F8;
					t19 = mem_read16(u + 0x11u);
					if ((int16_t)t18 < (int16_t)t19)
					{
						t20 = mem_read16(x + 0x11u);
						t21 = t20 + unk_48F8;
						t22 = mem_read16(u + 0x11u);
						if ((int16_t)t22 < (int16_t)t21)
						{
							mem_write16(x + 0xFu, 0u);
							mem_write16(x + 0x14u, 0u);
							mem_write16(x + 0x19u, 0u);
							mem_write16(x + 0x37u, 0u);
							t23 = mem_read8(x + 6u);
							mem_write8(x + 6u, t23 | 0x40u);
							mem_write16(x + 0x37u, 0u);
							t24 = mem_read16(x + 0x2Eu);
							y_2 = t24;
							*p_x = x;
							*p_y = y_2;
							*p_u = u;
							sub_03E273(p_x, p_y, p_u);
							return;
						}
					}
				}
			}
			t25 = mem_read8(x + 0x39u);
			b = t25;
			t26 = mem_read8(x + 4u);
			a = t26;
			if (a <= 3u)
			{
				t27 = mem_read8(x + 0x39u);
				t28 = mem_read8(x + 0x39u);
				stack = (int8_t)t28 >> 1;
				b = (uint32_t)a * b - t27 - stack;
			}
			d = b;
			d = sub_078671(x, u, d);
			a = (uint8_t)(d >> 8);
			t29 = mem_read8(x + 0x3Au);
			d = ((uint32_t)a << 8) | t29;
			sub_078617(x, d);
			t30 = mem_read8(x + 0x42u);
			if ((t30 & 1u) == 0u)
			{
				t31 = mem_read8(x + 9u);
				a = t31 & 0xBFu;
				t32 = mem_read16(x + 0xFu);
				u = t32;
				if ((int16_t)t32 < 0)
					a |= 0x40u;
				mem_write8(x + 9u, a);
			}
		}
		t33 = mem_read16(x + 0xFu);
		t34 = mem_read16(x + VIDEO_0031);
		t35 = t33 + t34;
		mem_write16(x + 0xFu, t35);
		t36 = mem_read16(x + 0x14u);
		t37 = mem_read16(x + 0x33u);
		t38 = t36 + t37;
		mem_write16(x + 0x14u, t38);
		t39 = mem_read16(x + 0x19u);
		t40 = mem_read16(x + 0x35u);
		t41 = t39 + t40;
		mem_write16(x + 0x19u, t41);
	}
	else
	{
		y = unk_48B2;
		mem_write16(x + 0x11u, y);
		t42 = mem_read16(x + VIDEO_0031);
		unk_48E4 = t42;
		t43 = mem_read16(x + 0x33u);
		unk_48E6 = t43;
	}
	t44 = mem_read8(x + 0x42u);
	if ((t44 & 2u) != 0u && (unk_4815 & 0xFu) == 0u)
	{
		d = 0x4A00u;
		carry = sub_078680(d);
	}
	t45 = mem_read8(x + 0x42u);
	if ((t45 & 4u) != 0u)
	{
		*p_y = y;
		*p_u = u;
		sub_03E67F(x, p_y, p_u);
		*p_x = x;
		return;
	}
	t46 = mem_read16(x + 0x2Au);
	y_2 = t46;
	if (t46 != 0u)
	{
		t47 = mem_read8(y_2 + 0x2Du);
		if (t47 != 1u)
		{
			*p_y = y_2;
			*p_u = u;
			sub_03E67F(x, p_y, p_u);
			*p_x = x;
			return;
		}
		mem_write16(x + 0x2Au, 0u);
		mem_write16(x + 0x37u, 0u);
		t24 = mem_read16(x + 0x2Eu);
		y_2 = t24;
		*p_x = x;
		*p_y = y_2;
		*p_u = u;
		sub_03E273(p_x, p_y, p_u);
		return;
	}
	t48 = mem_read8(x + 0x29u);
	if (t48 != 0u)
	{
		t49 = io_read8(VIDEO_184E);
		if (t49 == 0u)
		{
			*p_y = y_2;
			*p_u = u;
			sub_03E67F(x, p_y, p_u);
			*p_x = x;
			return;
		}
		mem_write8(x + 0x29u, 0u);
		stack_2 = x >> 8;
		stack = (uint8_t)x;
		x_2 = 0x4A68u;
		sub_03E1CB(x_2);
		x_2 = 0x4B28u;
		sub_03E1CB(x_2);
		x_2 = 0x4BE8u;
		sub_03E1CB(x_2);
		x_2 = 0x4CA8u;
		u_2 = sub_03E1CB(x_2);
		x_2 = ((uint32_t)stack_2 << 8) | stack;
		mem_write16(x_2 + 0x37u, 0u);
		t24 = mem_read16(x_2 + 0x2Eu);
		y_2 = t24;
		*p_x = x_2;
		*p_y = y_2;
		*p_u = u_2;
		sub_03E273(p_x, p_y, p_u);
		return;
	}
	t50 = mem_read16(x + VIDEO_003C);
	a = (uint8_t)(t50 >> 8);
	b = (uint8_t)t50;
	if (t50 != 0u)
	{
		if ((int16_t)unk_48AC <= (int16_t)(((uint32_t)a << 8) | b))
		{
			*p_y = y_2;
			*p_u = u;
			sub_03E67F(x, p_y, p_u);
			*p_x = x;
			return;
		}
		mem_write16(x + VIDEO_003C, 0u);
		mem_write16(x + 0x37u, 0u);
		t24 = mem_read16(x + 0x2Eu);
		y_2 = t24;
		*p_x = x;
		*p_y = y_2;
		*p_u = u;
		sub_03E273(p_x, p_y, p_u);
		return;
	}
	t51 = mem_read8(x + 0x42u);
	if ((t51 & 0x10u) != 0u)
	{
		t52 = mem_read8(x + 4u);
		t53 = 4u * t52;
		t54 = t53 + unk_4842_ADDRESS;
		stack = t54;
		stack_2 = t54 >> 8;
		u_2 = ((uint32_t)stack_2 << 8) | stack;
		if (mem_read8(u_2) != 0u)
		{
			t55 = mem_read8(x + 0x1Du);
			a = t55;
			if (t55 != 0u)
			{
				a--;
				mem_write8(x + 0x1Du, a);
				t56 = mem_read8(x + 0x1Cu);
				a += t56;
				if (a <= 0xE0u)
					mem_write8(x + 0x1Cu, a);
			}
		}
		t57 = mem_read8(x + 0x1Cu);
		mem_write8(x + 0x1Cu, t57 - 1u);
		if (t57 != 1u)
		{
			*p_y = y_2;
			*p_u = u_2;
			sub_03E67F(x, p_y, p_u);
			*p_x = x;
			return;
		}
		t58 = mem_read8(x + 0x42u);
		mem_write8(x + 0x42u, t58 & 0xEFu);
		mem_write16(x + 0x37u, 0u);
		t24 = mem_read16(x + 0x2Eu);
		y_2 = t24;
		*p_x = x;
		*p_y = y_2;
		*p_u = u_2;
		sub_03E273(p_x, p_y, p_u);
		return;
	}
	t59 = mem_read8(x + 0x3Bu);
	b = t59;
	if (t59 != 0u)
	{
		a = 0u;
		t60 = mem_read16(x + 0x16u);
		if ((int16_t)b < (int16_t)t60)
		{
			*p_y = y_2;
			*p_u = u;
			sub_03E67F(x, p_y, p_u);
			*p_x = x;
			return;
		}
		mem_write16(x + 0x16u, ((uint32_t)a << 8) | (uint8_t)(b - 1u));
		mem_write8(x + 0x18u, 0u);
		mem_write8(x + 0x3Bu, 0u);
		mem_write16(x + 0x37u, 0u);
		t24 = mem_read16(x + 0x2Eu);
		y_2 = t24;
		*p_x = x;
		*p_y = y_2;
		*p_u = u;
		sub_03E273(p_x, p_y, p_u);
		return;
	}
	t61 = mem_read16(x + 0x3Eu);
	a = (uint8_t)(t61 >> 8);
	b = (uint8_t)t61;
	if (t61 != 0u)
	{
		t62 = (((uint32_t)a << 8) | b) - unk_48AC;
		a = (uint8_t)(t62 >> 8);
		b = (uint8_t)t62;
		t63 = mem_read16(x + 0xCu);
		if ((int16_t)t63 < (int16_t)(((uint32_t)a << 8) | b))
		{
			*p_y = y_2;
			*p_u = u;
			sub_03E67F(x, p_y, p_u);
			*p_x = x;
			return;
		}
		t64 = (((uint32_t)a << 8) | b) - 1u;
		mem_write16(x + 0xCu, t64);
		mem_write8(x + 0xEu, 0u);
		mem_write16(x + 0x3Eu, 0u);
		mem_write16(x + 0x37u, 0u);
		t24 = mem_read16(x + 0x2Eu);
		y_2 = t24;
		*p_x = x;
		*p_y = y_2;
		*p_u = u;
		sub_03E273(p_x, p_y, p_u);
		return;
	}
	t65 = mem_read16(x + 0xAu);
	if (t65 == 0u)
	{
		t66 = mem_read8(x + 0x2Du);
		mem_write8(x + 0x2Du, t66 - 1u);
		if (t66 != 1u)
		{
			*p_y = y_2;
			*p_u = u;
			sub_03E67F(x, p_y, p_u);
			*p_x = x;
			return;
		}
		mem_write16(x + 0x37u, 0u);
		t24 = mem_read16(x + 0x2Eu);
		y_2 = t24;
		*p_x = x;
		*p_y = y_2;
		*p_u = u;
		sub_03E273(p_x, p_y, p_u);
		return;
	}
	sub_07863B(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	t67 = mem_read8(x + 0xBu);
	if ((a & 0xFu) != t67)
	{
		*p_y = y_2;
		*p_u = u;
		sub_03E67F(x, p_y, p_u);
		*p_x = x;
		return;
	}
	mem_write16(x + 0xAu, 0u);
	mem_write16(x + 0x37u, 0u);
	t24 = mem_read16(x + 0x2Eu);
	y_2 = t24;
	*p_x = x;
	*p_y = y_2;
	*p_u = u;
	sub_03E273(p_x, p_y, p_u);
}

uint16_t sub_03E1CB(uint16_t x)
{
	uint16_t d = 0, u = 0;

	d = 0u;
	u = VIDEO_002F;
	while (u != 0u)
	{
		mem_write8(x, d >> 8);
		x++;
		u--;
	}
	return u;
}

void sub_03E273(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint8_t a = 0;
	uint16_t y_2 = 0;
	uint16_t t1 = 0;

	t1 = y;
	y_2 = t1 + 1u;
	a = mem_read8(t1);
	if (a == 0xFFu)
		sub_03E711(x, &y_2, &u);
	else
	{
		u = loaded_table_03F000_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)a << 1))
		{
		case 0:
			sub_03E280(&x, &y_2, &u);
			break;
		case 2:
			sub_03E288(&x, &y_2, &u);
			break;
		case 4:
			sub_03E290(&x, &y_2, &u);
			break;
		case 6:
			sub_03E2AA(&x, &y_2, &u);
			break;
		case 8:
			sub_03E2BC(&x, &y_2, &u);
			break;
		case 10:
			sub_03E2E1(&x, &y_2, &u);
			break;
		case 12:
			sub_03E2FB(&x, &y_2, &u);
			break;
		case 14:
			sub_03E3B0(x, &y_2, &u);
			break;
		case 16:
			sub_03E3BB(&x, &y_2, &u);
			break;
		case 18:
			sub_03E3C8(&x, &y_2, &u);
			break;
		case 20:
			sub_03E40B(&x, &y_2, &u);
			break;
		case 22:
			sub_03E44D(&x, &y_2, &u);
			break;
		case 24:
			sub_03E455(x, &y_2, &u);
			break;
		case 26:
			sub_03E463(&x, &y_2, &u);
			break;
		case 28:
			sub_03E473(&x, &y_2, &u);
			break;
		case 30:
			sub_03E2D8(&x, &y_2, &u);
			break;
		case 32:
			sub_03E47E(x, &y_2, &u);
			break;
		case 34:
			sub_03E48B(&x, &y_2, &u);
			break;
		case 36:
			sub_03E4A1(&x, &y_2, &u);
			break;
		case 38:
			sub_03E4C6(&x, &y_2, &u);
			break;
		case 40:
			sub_03E4EA(&x, &y_2, &u);
			break;
		case 42:
			sub_03E50B(x, &y_2, &u);
			break;
		case 44:
			sub_03E51B(&x, &y_2, &u);
			break;
		case 46:
			sub_03E528(x, &y_2, &u);
			break;
		case 48:
			sub_03E533(&x, &y_2, &u);
			break;
		case 50:
			sub_03E53C(&x, &y_2, &u);
			break;
		case 52:
			sub_03E2CE(&x, &y_2, &u);
			break;
		case 54:
			sub_03E550(x, &y_2, &u);
			break;
		case 56:
			sub_03E55C(&x, &y_2, &u);
			break;
		case 58:
			sub_03E59F(&x, &y_2, &u);
			break;
		case 60:
			sub_03E441(&x, &y_2, &u);
			break;
		case 62:
			sub_03E5C6(x, &y_2, &u);
			break;
		case 64:
			sub_03E420(&x, &y_2, &u);
			break;
		case 66:
			sub_03E5D6(&x, &y_2, &u);
			break;
		case 68:
			sub_03E63E(&x, &y_2, &u);
			break;
		case 70:
			sub_03E649(&x, &y_2, &u);
			break;
		case 72:
			sub_03E654(x, &y_2, &u);
			break;
		case 74:
			sub_03E667(&x, &y_2, &u);
			break;
		}
	}
	*p_x = x;
	*p_y = y_2;
	*p_u = u;
}

void sub_03E280(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t y_2 = 0;
	uint16_t t1 = 0;

	t1 = y;
	y_2 = t1 + 2u;
	mem_write16(x + 4u, mem_read16(t1));
	*p_x = x;
	*p_y = y_2;
	*p_u = u;
	sub_03E67C(p_x, p_y, p_u);
}

void sub_03E288(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t y_2 = 0;
	uint16_t t1 = 0;

	t1 = y;
	y_2 = t1 + 1u;
	mem_write8(x + 5u, mem_read8(t1));
	*p_x = x;
	*p_y = y_2;
	*p_u = u;
	sub_03E67C(p_x, p_y, p_u);
}

void sub_03E290(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t y_2 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	t1 = y;
	mem_write16(x + 0xCu, mem_read16(t1));
	t2 = t1 + 2u;
	mem_write16(x + 0x11u, mem_read16(t2));
	t3 = t2 + 2u;
	y_2 = t3 + 2u;
	mem_write16(x + 0x16u, mem_read16(t3));
	*p_x = x;
	*p_y = y_2;
	*p_u = u;
	sub_03E67C(p_x, p_y, p_u);
}

void sub_03E2AA(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t y_2 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	t1 = y;
	mem_write16(x + 0xFu, mem_read16(t1));
	t2 = t1 + 2u;
	mem_write16(x + 0x14u, mem_read16(t2));
	t3 = t2 + 2u;
	y_2 = t3 + 2u;
	mem_write16(x + 0x19u, mem_read16(t3));
	*p_x = x;
	*p_y = y_2;
	*p_u = u;
	sub_03E67C(p_x, p_y, p_u);
}

void sub_03E2BC(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t y_2 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	t1 = y;
	mem_write16(x + VIDEO_0031, mem_read16(t1));
	t2 = t1 + 2u;
	mem_write16(x + 0x33u, mem_read16(t2));
	t3 = t2 + 2u;
	y_2 = t3 + 2u;
	mem_write16(x + 0x35u, mem_read16(t3));
	*p_x = x;
	*p_y = y_2;
	*p_u = u;
	sub_03E67C(p_x, p_y, p_u);
}

void sub_03E2CE(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x42u);
	mem_write8(x + 0x42u, t1 | 1u);
	*p_x = x;
	*p_y = y;
	*p_u = u;
	sub_03E2E9(p_x, p_y, p_u);
}

void sub_03E2D8(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t d = 0;
	uint16_t stack = 0;

	stack = x;
	d = stack + 0x60u;
	*p_x = x;
	*p_y = y;
	*p_u = u;
	sub_03E2ED(d, p_x, p_y, p_u);
}

void sub_03E2E1(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x42u);
	mem_write8(x + 0x42u, t1 & ~1u);
	*p_x = x;
	*p_y = y;
	*p_u = u;
	sub_03E2E9(p_x, p_y, p_u);
}

void sub_03E2E9(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t d = 0, u = 0, y_2 = 0;
	uint16_t t1 = 0;

	t1 = y;
	y_2 = t1 + 2u;
	u = mem_read16(t1);
	d = mem_read16(u);
	*p_x = x;
	*p_y = y_2;
	*p_u = u;
	sub_03E2ED(d, p_x, p_y, p_u);
}

void sub_03E2ED(uint16_t d, uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t d_2 = 0, y_2 = 0;
	uint16_t t1 = 0;

	mem_write16(x + 0x37u, d);
	t1 = y;
	y_2 = t1 + 2u;
	d_2 = mem_read16(t1);
	mem_write16(x + 0x39u, d_2);
	*p_x = x;
	*p_y = y_2;
	*p_u = u;
	sub_03E67C(p_x, p_y, p_u);
}

void sub_03E2FB(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t zero = 0, carry = 0;
	uint8_t a = 0;
	uint16_t ignored16 = 0, x_2 = 0;
	uint16_t stack = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t16 = 0, t17 = 0, t18 = 0;
	uint16_t t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0, t15 = 0;

	t1 = mem_read8(y + 5u);
	a = t1;
	if (a != 4u)
	{
		if (a != 5u)
		{
			stack = y;
			sub_07862C(x, y, &u, &ignored16, &carry);
			y = stack + 8u;
			if (carry == 0u)
				sub_03E67C(&x, &y, &u);
			else
			{
				if (mem_read8(y - 3u) != 2u)
				{
					unk_48F0 = 0xBu;
					stack = x;
					x += 0x43u;
					for (;;)
					{
						if (mem_read16(x) != 0u)
						{
							x += 2u;
							t2 = unk_48F0;
							unk_48F0 = t2 - 1u;
							if (t2 == 1u)
								break;
							continue;
						}
						mem_write16(x, u);
						break;
					}
					x = stack;
				}
				sub_03E67C(&x, &y, &u);
			}
		}
		else
		{
			unk_48F0 = 4u;
			u = 0x4AA0u;
			for (;;)
			{
				if (mem_read8(u) != 0u)
				{
					u += 0xC0u;
					t3 = unk_48F0;
					unk_48F0 = t3 - 1u;
					if (t3 != 1u)
						continue;
					y += 8u;
					sub_03E67C(&x, &y, &u);
					break;
				}
				mem_write8(u, 4u);
				t4 = y;
				t5 = mem_read16(t4);
				t6 = mem_read16(x + 0xCu);
				t7 = t5 + t6;
				mem_write16(u + 0xCu, t7);
				t8 = t4 + 2u;
				t9 = mem_read16(t8);
				t10 = mem_read16(x + 0x11u);
				t11 = t9 + t10;
				mem_write16(u + 0x11u, t11);
				t12 = t8 + 2u;
				t13 = mem_read16(x + 0x16u);
				t14 = mem_read8(t12) + t13;
				mem_write16(u + 0x16u, t14);
				t15 = t12 + 2u;
				y = t15 + 2u;
				mem_write8(u + 0x30u, mem_read8(t15));
				sub_03E67C(&x, &y, &u);
				break;
			}
		}
	}
	else
	{
		unk_48F1 = unk_4885;
		stack = x;
		x_2 = sub_03E7F3();
		do
		{
			mem_write8(x_2 + 0x60u, 0u);
			t16 = unk_48F1;
			carry = (t16 >> 0) & 1u;
			unk_48F1 = t16 >> 1;
			if (carry)
				mem_write8(x_2, 4u);
			t17 = mem_read8(y + 6u);
			mem_write8(x_2 + 0x30u, t17);
			t18 = mem_read8(y + 7u);
			mem_write8(x_2 + 4u, 4u - unk_48F0 + t18);
			sub_03E7FC(&x_2, &zero);
		} while (zero == 0u);
		x = stack;
		y += 8u;
		sub_03E67C(&x, &y, &u);
	}
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

void sub_03E3B0(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t y_2 = 0;
	uint16_t t1 = 0;

	t1 = y;
	y_2 = t1 + 1u;
	mem_write8(x + 0x2Du, mem_read8(t1));
	mem_write16(x + 0x2Eu, y_2);
	*p_y = y_2;
	*p_u = u;
	sub_03E67F(x, p_y, p_u);
}

void sub_03E3BB(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t y_2 = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = y;
	mem_write16(x + VIDEO_0031, mem_read16(t1));
	t2 = t1 + 2u;
	y_2 = t2 + 2u;
	mem_write16(x + 0x33u, mem_read16(t2));
	*p_x = x;
	*p_y = y_2;
	*p_u = u;
	sub_03E67C(p_x, p_y, p_u);
}

void sub_03E3C8(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint32_t zero = 0;
	uint8_t a = 0, b = 0;
	uint16_t u = 0, x_2 = 0;
	uint16_t stack = 0;
	uint8_t t1 = 0, t8 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t9 = 0, t10 = 0, t11 = 0;

	u = loaded_table_03F04C_ADDRESS + (unk_4858 & 0xCu);
	stack = x;
	x_2 = sub_03E7F3();
	do
	{
		b = 4u - unk_48F0;
		t1 = mem_read8(y + 6u);
		a = t1;
		if ((int8_t)t1 < 0)
		{
			t2 = (uint32_t)(uint8_t)(0u - a) * b;
			t3 = 0u - t2;
			a = (uint8_t)(t3 >> 8);
			b = (uint8_t)t3;
		}
		else
		{
			t4 = (uint32_t)a * b;
			a = (uint8_t)(t4 >> 8);
			b = (uint8_t)t4;
		}
		t5 = (((uint32_t)a << 8) | b) + mem_read16(y);
		mem_write16(x_2 + 0xCu, t5);
		t6 = mem_read16(y + 2u);
		mem_write16(x_2 + 0x11u, t6);
		t7 = u;
		u = t7 + 1u;
		t8 = mem_read8(y + 7u);
		t9 = (uint32_t)t8 * mem_read8(t7);
		t10 = mem_read16(y + 4u);
		t11 = t9 + t10;
		mem_write16(x_2 + 0x16u, t11);
		sub_03E7FC(&x_2, &zero);
	} while (zero == 0u);
	x_2 = stack;
	y += 8u;
	*p_x = x_2;
	*p_y = y;
	*p_u = u;
	sub_03E67C(p_x, p_y, p_u);
}

void sub_03E40B(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t y_2 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	mem_write8(x, mem_read8(x) | 0x40u);
	t1 = y;
	t2 = mem_read16(t1);
	mem_write16(x + 0x1Fu, t2);
	t3 = t1 + 2u;
	y_2 = t3 + 1u;
	mem_write8(x + 0x21u, mem_read8(t3));
	*p_x = x;
	*p_y = y_2;
	*p_u = u;
	sub_03E67C(p_x, p_y, p_u);
}

void sub_03E420(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint16_t d = 0, u = 0, x_2 = 0, y_2 = 0;
	uint8_t stack_10003 = 0, stack_10004 = 0;
	uint16_t stack = 0;
	uint8_t t5 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = y;
	u = mem_read16(t1);
	t2 = t1 + 2u;
	y_2 = t2 + 1u;
	t3 = 0xC0u * mem_read8(t2);
	t4 = t3 + unk_4A40_ADDRESS;
	stack = x;
	stack_10003 = t4 >> 8;
	stack_10004 = t4;
	t5 = mem_read8(((uint32_t)stack_10003 << 8) | stack_10004);
	x_2 = stack;
	if (t5 == 0u)
		sub_03E67C(&x_2, &y_2, &u);
	else
	{
		stack = u;
		d = stack;
		carry = sub_078680(d);
		sub_03E67C(&x_2, &y_2, &u);
	}
	*p_x = x_2;
	*p_y = y_2;
	*p_u = u;
}

void sub_03E441(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t d = 0, y_2 = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0, t3 = 0;

	t1 = mem_read8(x + 4u);
	t2 = y;
	y_2 = t2 + 2u;
	t3 = t1 + mem_read16(t2);
	d = t3;
	carry = sub_078680(d);
	*p_x = x;
	*p_y = y_2;
	*p_u = u;
	sub_03E67C(p_x, p_y, p_u);
}

void sub_03E44D(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t d = 0, y_2 = 0;
	uint16_t t1 = 0;

	t1 = y;
	y_2 = t1 + 2u;
	d = mem_read16(t1);
	carry = sub_078680(d);
	*p_x = x;
	*p_y = y_2;
	*p_u = u;
	sub_03E67C(p_x, p_y, p_u);
}

void sub_03E455(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x42u);
	mem_write8(x + 0x42u, t1 | 4u);
	mem_write16(x + 0x2Eu, y);
	*p_y = y;
	*p_u = u;
	sub_03E67F(x, p_y, p_u);
}

void sub_03E463(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t y_2 = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = y;
	y_2 = t1 + 1u;
	mem_write8(x + 9u, mem_read8(t1));
	t2 = mem_read8(x + 6u);
	mem_write8(x + 6u, t2 | 0x80u);
	*p_x = x;
	*p_y = y_2;
	*p_u = u;
	sub_03E67C(p_x, p_y, p_u);
}

void sub_03E473(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;

	mem_write8(x, mem_read8(x) ^ 8u);
	*p_x = x;
	*p_y = y;
	*p_u = u;
	sub_03E67C(p_x, p_y, p_u);
}

void sub_03E47E(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0, y_2 = 0;
	uint16_t t1 = 0;

	t1 = y;
	y_2 = t1 + 2u;
	u = mem_read16(t1);
	mem_write16(x + 0x2Au, mem_read16(u));
	mem_write16(x + 0x2Eu, y_2);
	*p_y = y_2;
	*p_u = u;
	sub_03E67F(x, p_y, p_u);
}

void sub_03E48B(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint8_t t1 = 0;

	t1 = io_read8(VIDEO_184E);
	if (t1 != 0u)
		sub_03E67C(&x, &y, &u);
	else
	{
		mem_write8(x + 0x29u, 1u);
		io_write8(VIDEO_184B, 1u);
		mem_write16(x + 0x2Eu, y);
		sub_03E67F(x, &y, &u);
	}
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

void sub_03E4A1(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint8_t a = 0;
	uint16_t u = 0, x_2 = 0, y_2 = 0;
	uint16_t stack = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0, t3 = 0, t4 = 0, t5 = 0;

	stack = x;
	x_2 = sub_03E7BA();
	t1 = y;
	mem_write8(x_2 + 5u, mem_read8(t1));
	t2 = mem_read8(x_2 + 9u);
	a = t2 & 0xBFu;
	t3 = t1 + 1u;
	y_2 = t3 + 2u;
	t4 = io_read16(mem_read16(mem_read16(t3)) + 0xCu);
	u = t4;
	t5 = mem_read16(x_2 + 0xCu);
	if ((int16_t)u < (int16_t)t5)
		a |= 0x40u;
	mem_write8(x_2 + 9u, a);
	x_2 = stack;
	*p_x = x_2;
	*p_y = y_2;
	*p_u = u;
	sub_03E67C(p_x, p_y, p_u);
}

void sub_03E4C6(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t zero = 0;
	uint16_t x_2 = 0;
	uint16_t stack = 0;
	uint8_t t1 = 0, t2 = 0;

	stack = x;
	x_2 = sub_03E7F3();
	do
	{
		if (mem_read8(x_2) == 0u)
		{
			t1 = mem_read8(x_2 + 5u);
			if (t1 != mem_read8(y))
			{
				t2 = mem_read8(y + 1u);
				mem_write8(x_2 + 5u, t2);
			}
		}
		sub_03E7FC(&x_2, &zero);
	} while (zero == 0u);
	x_2 = stack;
	y += 2u;
	*p_x = x_2;
	*p_y = y;
	*p_u = u;
	sub_03E67C(p_x, p_y, p_u);
}

void sub_03E4EA(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint8_t a = 0;
	uint16_t u = 0, y_2 = 0;
	uint8_t t1 = 0, t5 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0;

	t1 = mem_read8(x + 9u);
	a = t1 & 0xBFu;
	t2 = y;
	y_2 = t2 + 2u;
	t3 = io_read16(mem_read16(mem_read16(t2)) + 0xCu);
	u = t3;
	t4 = mem_read16(x + 0xCu);
	if ((int16_t)u < (int16_t)t4)
		a |= 0x40u;
	mem_write8(x + 9u, a);
	t5 = mem_read8(x + 6u);
	mem_write8(x + 6u, t5 | 0x80u);
	*p_x = x;
	*p_y = y_2;
	*p_u = u;
	sub_03E67C(p_x, p_y, p_u);
}

void sub_03E50B(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint8_t a = 0;
	uint16_t y_2 = 0;
	uint16_t t1 = 0;

	t1 = y;
	y_2 = t1 + 1u;
	a = mem_read8(t1) + 1u;
	mem_write8(x + 0x3Bu, a);
	io_write8(VIDEO_184B, a);
	mem_write16(x + 0x2Eu, y_2);
	*p_y = y_2;
	*p_u = u;
	sub_03E67F(x, p_y, p_u);
}

void sub_03E51B(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint16_t ignored16 = 0, u = 0, y_2 = 0;
	uint16_t stack = 0;

	stack = y;
	sub_07862C(x, y, &u, &ignored16, &carry);
	y_2 = stack + 8u;
	*p_x = x;
	*p_y = y_2;
	*p_u = u;
	sub_03E67C(p_x, p_y, p_u);
}

void sub_03E528(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t y_2 = 0;
	uint16_t t1 = 0;

	t1 = y;
	y_2 = t1 + 2u;
	mem_write16(x + VIDEO_003C, mem_read16(t1));
	mem_write16(x + 0x2Eu, y_2);
	*p_y = y_2;
	*p_u = u;
	sub_03E67F(x, p_y, p_u);
}

void sub_03E533(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0, y_2 = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = y;
	u = mem_read16(t1);
	t2 = t1 + 2u;
	y_2 = t2 + 1u;
	mem_write8(u, mem_read8(t2));
	*p_x = x;
	*p_y = y_2;
	*p_u = u;
	sub_03E67C(p_x, p_y, p_u);
}

void sub_03E53C(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;

	unk_4A7F = 0u;
	unk_4B3F = 0u;
	unk_4BFF = 0u;
	unk_4CBF = 0u;
	*p_x = x;
	*p_y = y;
	*p_u = u;
	sub_03E67C(p_x, p_y, p_u);
}

void sub_03E550(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t y_2 = 0;
	uint16_t t1 = 0;

	t1 = y;
	y_2 = t1 + 2u;
	mem_write16(x + 0x3Eu, mem_read16(t1) + 1u);
	mem_write16(x + 0x2Eu, y_2);
	*p_y = y_2;
	*p_u = u;
	sub_03E67F(x, p_y, p_u);
}

void sub_03E55C(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint32_t zero = 0;
	uint16_t u = 0, x_2 = 0, y_2 = 0;
	uint16_t stack = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	t1 = y;
	unk_48F8 = mem_read16(t1);
	t2 = t1 + 2u;
	y_2 = t2 + 2u;
	unk_48FA = mem_read16(t2);
	stack = x;
	u = loaded_table_03F05C_ADDRESS;
	x_2 = sub_03E7F3();
	do
	{
		t3 = u;
		mem_write16(x_2 + 0xCu, mem_read16(t3) + unk_48F8);
		t4 = t3 + 2u;
		u = t4 + 2u;
		mem_write16(x_2 + 0x11u, mem_read16(t4) + unk_48FA);
		sub_03E7FC(&x_2, &zero);
	} while (zero == 0u);
	x_2 = stack;
	t5 = y_2;
	y_2 = t5 + 1u;
	if (mem_read8(t5) == 0u)
		sub_03E67C(&x_2, &y_2, &u);
	else
	{
		unk_4A40 = 4u;
		unk_4B00 = 4u;
		unk_4BC0 = 4u;
		unk_4C80 = 4u;
		sub_03E67C(&x_2, &y_2, &u);
	}
	*p_x = x_2;
	*p_y = y_2;
	*p_u = u;
}

void sub_03E59F(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint32_t zero = 0, carry = 0;
	uint8_t b = 0;
	uint16_t u = 0, x_2 = 0;
	uint16_t stack = 0;

	u = DATA16(0x70F8u + (unk_4858 & 6u));
	b = unk_4850;
	stack = x;
	x_2 = sub_03E7F3();
	do
	{
		carry = (b >> 0) & 1u;
		b = b >> 1;
		if (carry == 0u)
		{
			mem_write8(x_2 + 0x2Du, 1u);
			mem_write16(x_2 + 0x2Eu, u);
		}
		sub_03E7FC(&x_2, &zero);
	} while (zero == 0u);
	x_2 = stack;
	*p_x = x_2;
	*p_y = y;
	*p_u = u;
	sub_03E67C(p_x, p_y, p_u);
}

void sub_03E5C6(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t y_2 = 0;
	uint16_t t1 = 0;

	t1 = y;
	y_2 = t1 + 1u;
	mem_write8(x + 0xBu, mem_read8(t1));
	mem_write8(x + 0xAu, 1u);
	mem_write16(x + 0x2Eu, y_2);
	*p_y = y_2;
	*p_u = u;
	sub_03E67F(x, p_y, p_u);
}

void sub_03E5D6(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, x_2 = 0;
	uint8_t stack_10003 = 0, stack_10004 = 0;
	uint16_t stack = 0;
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0;

	stack = x;
	x_2 = sub_03E7BA();
	t1 = mem_read8(x_2 + 4u);
	t2 = mem_read16(y + (int8_t)((uint32_t)t1 << 1));
	a = (uint8_t)(t2 >> 8);
	b = (uint8_t)t2;
	if ((uint16_t)(((uint32_t)a << 8) | b) < 0x3F08u || (uint16_t)(((uint32_t)a << 8) | b) > 0x3F0Bu)
	{
		if ((uint16_t)(((uint32_t)a << 8) | b) < 0x3F14u || (uint16_t)(((uint32_t)a << 8) | b) > 0x3F17u)
		{
			d = ((uint32_t)a << 8) | b;
			carry = sub_078680(d);
			y += 8u;
			x_2 = stack;
			*p_x = x_2;
			*p_y = y;
			*p_u = u;
			sub_03E67C(p_x, p_y, p_u);
			return;
		}
		stack_10003 = a;
		stack_10004 = b;
		t3 = mem_read8(x_2 + 4u);
		mem_write16(x_2 + 0x64u, 0xB100u | (uint8_t)(t3 - 0x6Cu));
		a = 0x13u;
	}
	else
	{
		stack_10003 = a;
		stack_10004 = b;
		a = 0x33u;
	}
	mem_write8(x_2 + 0x90u, a);
	mem_write8(x_2 + 0x60u, 4u);
	t4 = mem_read16(x_2 + 0xCu);
	mem_write16(x_2 + 0x6Cu, t4);
	t5 = mem_read16(x_2 + 0x11u);
	t6 = t5 - 2u;
	mem_write16(x_2 + 0x71u, t6);
	t7 = mem_read16(x_2 + 0x16u);
	t8 = t7 + 0x42u;
	mem_write16(x_2 + 0x76u, t8);
	a = stack_10003;
	b = stack_10004;
	d = ((uint32_t)a << 8) | b;
	carry = sub_078680(d);
	y += 8u;
	x_2 = stack;
	*p_x = x_2;
	*p_y = y;
	*p_u = u;
	sub_03E67C(p_x, p_y, p_u);
}

void sub_03E63E(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x42u);
	mem_write8(x + 0x42u, t1 ^ 2u);
	*p_x = x;
	*p_y = y;
	*p_u = u;
	sub_03E67C(p_x, p_y, p_u);
}

void sub_03E649(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x42u);
	mem_write8(x + 0x42u, t1 ^ 8u);
	*p_x = x;
	*p_y = y;
	*p_u = u;
	sub_03E67C(p_x, p_y, p_u);
}

void sub_03E654(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t y_2 = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x42u);
	mem_write8(x + 0x42u, t1 | 0x10u);
	t2 = y;
	y_2 = t2 + 2u;
	t3 = mem_read16(t2);
	mem_write16(x + 0x1Cu, t3);
	mem_write16(x + 0x2Eu, y_2);
	*p_y = y_2;
	*p_u = u;
	sub_03E67F(x, p_y, p_u);
}

void sub_03E667(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;

	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write16(x + 0x19u, 0u);
	mem_write16(x + VIDEO_0031, 0u);
	mem_write16(x + 0x33u, 0u);
	mem_write16(x + 0x35u, 0u);
	*p_x = x;
	*p_y = y;
	*p_u = u;
	sub_03E67C(p_x, p_y, p_u);
}

void sub_03E67C(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;

	*p_x = x;
	*p_y = y;
	*p_u = u;
	sub_03E273(p_x, p_y, p_u);
}

void sub_03E67F(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint8_t a = 0;
	uint16_t ignored16 = 0, x_2 = 0;
	uint8_t stack_3 = 0;
	uint16_t stack = 0, stack_5 = 0;
	uint8_t t3 = 0, t4 = 0, t5 = 0;
	uint16_t t1 = 0, t2 = 0, t6 = 0, t7 = 0;

	if ((int16_t)x < 0x4A40 || (int16_t)x > 0x4CE0)
	{
		a = 0xBu;
		stack = x;
		y = x + 0x43u;
		do
		{
			stack_3 = a;
			t1 = y;
			y = t1 + 2u;
			t2 = mem_read16(t1);
			x_2 = t2;
			if (t2 != 0u)
			{
				stack_5 = y;
				sub_03E05A(&x_2, &ignored16, &u);
				y = stack_5;
			}
			t3 = stack_3;
			a = t3 - 1u;
		} while (t3 != 1u);
		x = stack;
	}
	if (x == 0x5640u)
	{
		t4 = io_read8(VIDEO_184E);
		if (t4 != 0u)
		{
			stack = x;
			x_2 = unk_4A40_ADDRESS;
			sub_03E05A(&x_2, &y, &u);
			x_2 = 0x4AA0u;
			sub_03E05A(&x_2, &y, &u);
			x_2 = unk_4B00_ADDRESS;
			sub_03E05A(&x_2, &y, &u);
			x_2 = 0x4B60u;
			sub_03E05A(&x_2, &y, &u);
			x_2 = unk_4BC0_ADDRESS;
			sub_03E05A(&x_2, &y, &u);
			x_2 = 0x4C20u;
			sub_03E05A(&x_2, &y, &u);
			x_2 = unk_4C80_ADDRESS;
			sub_03E05A(&x_2, &y, &u);
			x_2 = 0x4CE0u;
			sub_03E05A(&x_2, &y, &u);
			x = stack;
		}
	}
	if (x != 0x5640u)
	{
		t5 = mem_read8(x + 0x30u);
		a = t5;
		if (a != 0x21u && a != 0xDu)
		{
			t6 = mem_read16(x + 0xCu);
			y = t6;
			if ((int16_t)y >= 0x190 || (int16_t)y < 0)
				sub_03E711(x, &y, &u);
			else
			{
				t7 = mem_read16(x + 0x16u);
				y = t7;
				if ((int16_t)y >= 0x280 || (int16_t)y <= -0x200)
					sub_03E711(x, &y, &u);
			}
		}
	}
	*p_y = y;
	*p_u = u;
}

void sub_03E711(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint32_t zero = 0;
	uint8_t a = 0;
	uint16_t ignored16 = 0, u_2 = 0, x_2 = 0, y = 0;
	uint16_t stack = 0, stack_4 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t7 = 0;
	uint16_t t5 = 0, t6 = 0;

	if (x == 0x5640u)
	{
		unk_4872 = 0u;
		t1 = io_read8(VIDEO_184B);
		io_write8(VIDEO_184B, 0u);
		t2 = io_read8(VIDEO_184E);
		io_write8(VIDEO_184E, 0u);
		io_write16(VIDEO_1852, 0u);
		io_write16(VIDEO_1854, 0u);
		io_write16(VIDEO_1856, 0u);
		io_write16(VIDEO_1858, 0u);
		mem_write8(x, 0u);
		stack = x;
		x_2 = sub_03E7F3();
		do
		{
			if (mem_read8(x_2) != 0u)
			{
				mem_write8(x_2 + 0x30u, 0u);
				mem_write8(x_2 + 0x90u, 0u);
				mem_write8(x_2 + 0x60u, 0u);
				t3 = mem_read8(x_2 + 9u);
				mem_write8(x_2 + 9u, t3 & 0xBFu);
				mem_write16(x_2 + 0xFu, 0u);
				mem_write16(x_2 + 0x14u, 0u);
				mem_write16(x_2 + 0x19u, 0u);
				stack_4 = x_2;
				x_2 += 0x1Cu;
				u_2 = 0x3Du;
				a = 0u;
				while (u_2 != 0u)
				{
					mem_write8(x_2, a);
					x_2++;
					u_2--;
				}
				x_2 = stack_4;
				t4 = mem_read8(x_2 + 0x34u);
				mem_write8(x_2 + 0x34u, t4 | 2u);
			}
			mem_write8(x_2 + 0x60u, 0u);
			mem_write8(x_2 + 0x90u, 0u);
			mem_write8(x_2 + 4u, 4u - unk_48F0);
			sub_03E7FC(&x_2, &zero);
		} while (zero == 0u);
		u_2 = stack;
		*p_u = u_2;
		sub_03E7A3(p_u, &ignored16);
		return;
	}
	mem_write8(x, 0u);
	t5 = mem_read16(x + 0x40u);
	y = t5 + 0x43u;
	unk_48F0 = 0xBu;
	do
	{
		t6 = y;
		y = t6 + 2u;
		if (x == mem_read16(t6))
		{
			mem_write16(y - 2u, 0u);
			break;
		}
		t7 = unk_48F0;
		unk_48F0 = t7 - 1u;
	} while (t7 != 1u);
	*p_y = y;
}

void sub_03E7A3(uint16_t *p_u, uint16_t *p_d)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t d = (uint16_t)*p_d;
	uint8_t a = 0;
	uint16_t d_2 = 0, u_2 = 0, x = 0;
	uint8_t stack = 0;
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0;

	stack = d >> 8;
	a = 0xBu;
	x = u + 0x43u;
	do
	{
		t1 = x;
		x = t1 + 2u;
		t2 = mem_read16(t1);
		u_2 = t2;
		if (t2 != 0u)
		{
			mem_write8(u_2, 0u);
			d_2 = (uint32_t)a << 8;
			sub_03E7A3(&u_2, &d_2);
			a = (uint8_t)(d_2 >> 8);
		}
		t3 = a;
		a = t3 - 1u;
	} while (t3 != 1u);
	d_2 = (uint32_t)stack << 8;
	*p_u = u_2;
	*p_d = (*p_d & 0xFFu) | d_2;
}

uint16_t sub_03E7BA(void)
{
	uint32_t zero = 0, carry = 0;
	uint8_t a = 0;
	uint16_t x = 0;
	uint8_t stack = 0, stack_10002 = 0;
	uint8_t t3 = 0, t4 = 0, t5 = 0, t6 = 0;
	uint16_t t1 = 0, t2 = 0;

	unk_48F1 = unk_4885;
	t1 = (unk_4858 & 3u) * 0xC0u;
	t2 = t1 + unk_4A40_ADDRESS;
	stack = t2 >> 8;
	stack_10002 = t2;
	x = ((uint32_t)stack << 8) | stack_10002;
	t3 = io_read8(x + 4u);
	a = t3;
	if (t3 != 0u)
	{
		do
		{
			unk_48F1 = unk_48F1 >> 1;
			t4 = a;
			a = t4 - 1u;
		} while (t4 != 1u);
	}
	t5 = unk_48F1;
	carry = (t5 >> 0) & 1u;
	unk_48F1 = t5 >> 1;
	if (carry)
		return x;
	unk_48F1 = unk_4885;
	x = sub_03E7F3();
	do
	{
		t6 = unk_48F1;
		carry = (t6 >> 0) & 1u;
		unk_48F1 = t6 >> 1;
		if (carry)
			break;
		sub_03E7FC(&x, &zero);
	} while (zero == 0u);
	return x;
}

uint16_t sub_03E7F3(void)
{
	uint16_t x = 0;

	unk_48F0 = 4u;
	x = unk_4A40_ADDRESS;
	return x;
}

void sub_03E7FC(uint16_t *p_x, uint32_t *p_zero)
{
	uint16_t x = (uint16_t)*p_x;
	uint32_t zero = *p_zero;
	uint8_t t1 = 0;

	x += 0xC0u;
	t1 = unk_48F0 - 1u;
	zero = t1 == 0u;
	unk_48F0 = t1;
	*p_x = x;
	*p_zero = zero;
}

void sub_03EAB3(uint16_t u)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(u + 0x60u);
	if (t1 == 0u)
	{
		sub_03ED16(u);
		return;
	}
	t2 = mem_read8(u + 0x90u);
	switch ((int8_t)(uint8_t)((uint32_t)t2 << 1))
	{
	case 0:
	case 22:
		sub_03ED16(u);
		return;
	case 2:
		sub_03ECAA(u);
		return;
	case 4:
		sub_03EC60(u);
		return;
	case 6:
		sub_03EC36(u);
		return;
	case 8:
		sub_03EC08(u);
		return;
	case 10:
		sub_03EBF0(u);
		return;
	case 12:
		sub_03EBE5(u);
		return;
	case 14:
		sub_03EB8A(u);
		return;
	case 16:
		sub_03EB18(u);
		return;
	case 18:
		sub_03EBBB(u);
		return;
	case 20:
		sub_03EB25(u);
		return;
	case 24:
		sub_03EAEF(u);
		return;
	case 26:
		sub_03ED0B(u);
		return;
	}
}

void sub_03EAC3(uint16_t u)
{
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read16(u + 0xCu);
	mem_write16(u + 0x6Cu, t1);
	t2 = mem_read16(u + 0x11u);
	mem_write16(u + 0x71u, t2 - 0x40u);
	t3 = mem_read16(u + 0x16u);
	mem_write16(u + 0x76u, t3 + 0x80u);
}

void sub_03EADC(uint16_t u)
{
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read16(u + 0xFu);
	mem_write16(u + 0x6Fu, t1);
	t2 = mem_read16(u + 0x14u);
	mem_write16(u + 0x74u, t2);
	t3 = mem_read16(u + 0x19u);
	mem_write16(u + 0x79u, t3);
}

void sub_03EAEF(uint16_t u)
{
	uint8_t t4 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read16(u + 0xCu);
	mem_write16(u + 0x6Cu, t1);
	t2 = mem_read16(u + 0x11u);
	mem_write16(u + 0x71u, t2 - 0x7Fu);
	t3 = mem_read16(u + 0x16u);
	t4 = mem_read8(u + 4u);
	mem_write16(u + 0x76u, t3 + (int8_t)DATA8(indexed_table_03FE77_ADDRESS + (int8_t)t4) + 0x7Fu);
	sub_03EADC(u);
	sub_03ED16(u);
}

void sub_03EB18(uint16_t u)
{
	uint16_t d = 0, y = 0;

	mem_write8(u + 0x60u, 0xC0u);
	d = 0x411u;
	y = 0xA00u;
	sub_03EB30(y, u, d);
}

void sub_03EB25(uint16_t u)
{
	uint16_t d = 0, y = 0;

	mem_write8(u + 0x60u, 0xC8u);
	d = 0x811u;
	y = 0x300u;
	sub_03EB30(y, u, d);
}

void sub_03EB30(uint16_t y, uint16_t u, uint16_t d)
{
	uint8_t b = 0;
	uint8_t stack = 0, stack_2 = 0, stack_3 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t8 = 0, t10 = 0;
	uint16_t t4 = 0, t5 = 0, t6 = 0, t7 = 0, t9 = 0;

	mem_write16(u + 0x7Cu, d);
	b = 4u;
	t1 = mem_read8(u + 9u);
	t2 = t1 & 0x40u;
	stack = t2;
	if (t2 != 0u)
	{
		stack_3 = y >> 8;
		stack_2 = (uint8_t)y;
		stack_3 = 0u - stack_3;
		y = ((uint32_t)stack_3 << 8) | stack_2;
		b = 0u - b;
	}
	t3 = mem_read8(u + 0x69u);
	mem_write8(u + 0x69u, (t3 & 0xBFu) | stack);
	mem_write16(u + 0x6Fu, y);
	mem_write16(u + 0x74u, 0u);
	mem_write16(u + 0x79u, 0u);
	t4 = (int8_t)b;
	t5 = mem_read16(u + 0xCu);
	t6 = t4 + t5;
	mem_write16(u + 0x6Cu, t6);
	t7 = mem_read16(u + 0x11u);
	mem_write16(u + 0x71u, t7);
	t8 = mem_read8(u + 4u);
	t9 = mem_read16(u + 0x16u);
	mem_write16(u + 0x76u, t9 + (int8_t)DATA8(indexed_table_03FE7B_ADDRESS + (int8_t)t8));
	mem_write8(u + 0x7Fu, 4u);
	mem_write8(u + 0x80u, 4u);
	mem_write8(u + 0x81u, 4u);
	t10 = mem_read8(u + 0x90u);
	mem_write8(u + 0x90u, t10 - 1u);
	sub_03EB8A(u);
}

void sub_03EB8A(uint16_t u)
{
	uint8_t t1 = 0;

	t1 = mem_read8(u + 0x60u);
	if ((t1 & 0x20u) == 0u)
	{
		sub_03EBBB(u);
		return;
	}
	sub_03EB91(u);
}

void sub_03EB91(uint16_t u)
{
	uint16_t t1 = 0, t2 = 0;

	mem_write8(u + 0x90u, 6u);
	mem_write16(u + 0x64u, 0xEBFu);
	t1 = mem_read16(u + 0x71u);
	mem_write16(u + 0x71u, t1 - 0x10u);
	t2 = mem_read16(u + 0x76u);
	mem_write16(u + 0x76u, t2 + 0x10u);
	mem_write16(u + 0x6Fu, 0u);
	mem_write16(u + 0x74u, 0u);
	mem_write16(u + 0x79u, 0u);
	sub_03ED16(u);
}

void sub_03EBBB(uint16_t u)
{
	uint32_t negative = 0;
	uint8_t a = 0;
	uint16_t d = 0, x = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read16(u + 0x6Cu);
	x = t1;
	if ((int16_t)x <= 0x44 || (int16_t)x >= 0x17C)
	{
		sub_03ED0B(u);
		return;
	}
	x = u + 0x60u;
	sub_078644(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	if ((int8_t)a < 0)
	{
		sub_03EB91(u);
		return;
	}
	t2 = (uint8_t)((((a & 0xFu) << 1) << 1) << 1);
	t3 = mem_read16(u + 0x76u);
	if ((int16_t)t2 <= (int16_t)t3)
	{
		sub_03ED16(u);
		return;
	}
	sub_03EB91(u);
}

void sub_03EBE5(uint16_t u)
{
	uint8_t t1 = 0;

	t1 = mem_read8(u + 0x66u);
	if ((t1 & 1u) == 0u)
	{
		sub_03ED16(u);
		return;
	}
	sub_03ED0B(u);
}

void sub_03EBF0(uint16_t u)
{
	sub_03EAC3(u);
	mem_write16(u + 0x6Fu, 0u);
	mem_write16(u + 0x74u, 0u);
	mem_write16(u + 0x79u, 0u);
	mem_write8(u + 0x90u, 4u);
	mem_write8(u + 0x9Du, 1u);
	sub_03EC08(u);
}

void sub_03EC08(uint16_t u)
{
	uint8_t a = 0, d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	mem_write8(u + 0x69u, 0u);
	t1 = mem_read8(u + 0x9Du);
	mem_write8(u + 0x9Du, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(u + 0x9Du, 0x3Cu);
		d = 0x80u;
		a = 0xB1u;
		mem_write16(u + 0x64u, ((uint32_t)a << 8) | (d & 0xFFu));
		t2 = mem_read8(u + 6u);
		mem_write8(u + 6u, t2 & ~2u);
		sub_03ED16(u);
		return;
	}
	t3 = mem_read8(u + 0x9Du);
	if (t3 != 0x1Eu)
	{
		sub_03ED16(u);
		return;
	}
	d = 0x81u;
	a = 0xB1u;
	mem_write16(u + 0x64u, ((uint32_t)a << 8) | (d & 0xFFu));
	t2 = mem_read8(u + 6u);
	mem_write8(u + 6u, t2 & ~2u);
	sub_03ED16(u);
}

void sub_03EC36(uint16_t u)
{
	uint8_t a = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	sub_03EAC3(u);
	sub_03EADC(u);
	t1 = mem_read8(u + 0x9Eu);
	mem_write8(u + 0x9Eu, t1 - 1u);
	if (t1 == 1u)
	{
		sub_03ED0B(u);
		return;
	}
	t2 = mem_read8(u + 0x9Eu);
	t3 = t2 & 0x3Fu;
	a = t3;
	if (t3 == 0u)
	{
		mem_write8(u + 0x60u, 0x80u);
		sub_03ED16(u);
		return;
	}
	if (a != 0x10u)
	{
		sub_03ED16(u);
		return;
	}
	mem_write8(u + 0x60u, 4u);
	sub_03ED16(u);
}

void sub_03EC60(uint16_t u)
{
	uint8_t a = 0, b = 0;
	uint16_t y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t5 = 0, t6 = 0;
	uint16_t t4 = 0;

	t1 = io_read8(VIDEO_185A);
	if (t1 != 0u)
	{
		sub_03ED0B(u);
		return;
	}
	t2 = mem_read8(u + VIDEO_00A0);
	a = t2;
	b = DATA8(indexed_table_03FE7F_ADDRESS + (int8_t)a);
	if (a != 3u)
	{
		t3 = mem_read8(u + 4u);
		b += t3;
	}
	else
	{
		t4 = mem_read16(u + 0x32u);
		y = t4;
		mem_write8(y + 0x60u, 0u);
		mem_write8(y + 0x90u, 0u);
		t5 = mem_read8(y + 4u);
		t6 = mem_read8(u + 4u);
		b += DATA8(indexed_table_03FE84_ADDRESS + (int8_t)((((uint32_t)t5 << 1) << 1) + t6));
	}
	mem_write16(u + 0x64u, 0xB100u | b);
	mem_write8(u + 0x90u, 1u);
	mem_write8(u + 0xA1u, 0x50u);
	sub_03EAC3(u);
	mem_write8(u + 0x69u, 0u);
	sub_03ED16(u);
}

void sub_03ECAA(uint16_t u)
{
	uint16_t d = 0, x = 0;
	uint16_t stack = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t5 = 0, t6 = 0;
	uint16_t t4 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0;

	t1 = mem_read8(u + 0xA1u);
	mem_write8(u + 0xA1u, t1 - 1u);
	if (t1 == 1u)
	{
		sub_03ED0B(u);
		return;
	}
	t2 = mem_read8(u + 0x39u);
	if ((int8_t)t2 >= 0)
	{
		sub_03EAC3(u);
		sub_03EADC(u);
		sub_03ED16(u);
		return;
	}
	t3 = mem_read8(u + 0x36u);
	if (t3 != 0u)
	{
		sub_03EAC3(u);
		sub_03EADC(u);
		sub_03ED16(u);
		return;
	}
	t4 = mem_read16(u + 0x32u);
	t5 = mem_read8(t4 + 4u);
	t6 = mem_read8(u + 4u);
	d = ((uint32_t)DATA8(indexed_table_03FE84_ADDRESS + (int8_t)((uint16_t)((uint32_t)(uint8_t)(((uint16_t)((uint32_t)(uint8_t)((uint32_t)((uint16_t)((uint32_t)(uint8_t)((uint32_t)((uint16_t)((uint32_t)t5 << 8) >> 8) << 1) << 8) >> 8) << 1) << 8) >> 8) + t6) << 8) >> 8)) << 8) | 0xC0u;
	stack = (uint32_t)(d >> 8) * (uint8_t)d + unk_4A40_ADDRESS;
	x = stack;
	t7 = mem_read16(x + 0xCu);
	mem_write16(u + 0x6Cu, t7);
	t8 = mem_read16(x + 0x11u);
	mem_write16(u + 0x71u, t8 - 0x40u);
	t9 = mem_read16(x + 0x16u);
	mem_write16(u + 0x76u, t9 + 0x80u);
	t10 = mem_read16(x + 0xFu);
	mem_write16(u + 0x6Fu, t10);
	t11 = mem_read16(x + 0x14u);
	mem_write16(u + 0x74u, t11);
	t12 = mem_read16(x + 0x19u);
	mem_write16(u + 0x79u, t12);
	sub_03ED16(u);
}

void sub_03ED0B(uint16_t u)
{
	mem_write8(u + 0x60u, 0u);
	mem_write8(u + 0x90u, 0u);
	sub_03ED16(u);
}

void sub_03ED16(uint16_t u)
{
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(u + 0x5Bu);
	mem_write8(u + 0xBBu, t1 & 0x30u);
	t2 = mem_read8(u + 0x1Bu);
	mem_write8(u + 0x52u, t2);
	t3 = mem_read8(u + 0x30u);
	mem_write8(u + 2u, DATA8(indexed_table_03FE94_ADDRESS + (int8_t)t3));
}
