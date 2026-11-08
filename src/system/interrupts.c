/**
 *    Name:        system/interrupts.c
 *    Description: the IRQ's handler (the K052109's, at VBLANK: the inputs, the coin counters, the jobs) and the FIRQ's (the sprite DMA's)
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    07-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

void sub_078F43(void)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0, d_2 = 0;
	uint16_t d = 0, u = 0, x = 0, y = 0;
	uint8_t saved_unk_480F = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t6 = 0, t7 = 0;
	uint16_t t4 = 0, t5 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0, t15 = 0, t16 = 0, t17 = 0, t18 = 0, t19 = 0, t20 = 0;

	disable_irq();
	io_write8(VIDEO_1D00, 0xFBu);
	enable_irq();
	take_interrupts();
	io_write8(VIDEO_1D00, 0xFFu);
	saved_unk_480F = unk_480F;
	unk_4851 = 0u;
	unk_483F = unk_483E;
	unk_483E = unk_483D;
	t1 = io_read8(IO_1F80);
	unk_483D = ~t1;
	t2 = unk_4800;
	firq_point();
	take_interrupts();
	if (t2 != 0u)
	{
		if (unk_481B == 0u)
		{
			if (unk_481A != 0u)
			{
				unk_481A--;
				a = unk_4810 | 1u;
				unk_4810 = a;
				io_write8(IO_1FC0, a);
				unk_481B = 8u;
			}
		}
		else
		{
			unk_481B--;
			if (unk_481B != 4u)
			{
				a = unk_4810 & ~1u;
				unk_4810 = a;
				io_write8(IO_1FC0, a);
			}
		}
		if (unk_4839 == 0u)
		{
			if (unk_4823 == 0u)
			{
				if (unk_4822 != 0u)
				{
					unk_4822--;
					a = unk_4810 | 2u;
					unk_4810 = a;
					io_write8(IO_1FC0, a);
					unk_4823 = 8u;
				}
			}
			else
			{
				unk_4823--;
				if (unk_4823 != 4u)
				{
					a = unk_4810 & ~2u;
					unk_4810 = a;
					io_write8(IO_1FC0, a);
				}
			}
		}
		d = 0x100u;
		sub_0791D8(&d, &carry);
		if (carry)
		{
			u = unk_4817_ADDRESS;
			sub_0791F7(u, (uint8_t)d);
		}
		d = 0x200u;
		sub_0791D8(&d, &carry);
		b = (uint8_t)d;
		if (carry)
		{
			u = unk_481F_ADDRESS;
			d = sub_0791F7(u, (uint8_t)d);
			b = (uint8_t)d;
		}
		if (unk_4839 != 0u)
		{
			d = 0x400u;
			sub_0791D8(&d, &carry);
			if (carry)
			{
				u = unk_4827_ADDRESS;
				sub_0791F7(u, (uint8_t)d);
			}
			d = 0x800u;
			sub_0791D8(&d, &carry);
			b = (uint8_t)d;
			if (carry)
			{
				u = unk_482F_ADDRESS;
				d = sub_0791F7(u, (uint8_t)d);
				b = (uint8_t)d;
			}
		}
		t3 = io_read8(IO_1F81);
		if ((t3 & 1u) == 0u)
		{
			unk_487E = 3u;
			d = 0u;
			sub_07BAC7(d, &y, &u);
			b = 0u;
			unk_4811 = 0u;
			unk_4800 = 0u;
			unk_4801 = 0u;
			unk_4802 = 0u;
			unk_4803 = 0u;
		}
	}
	x = unk_4902;
	if (x != unk_4900)
	{
		t4 = x;
		x = t4 + 2u;
		t5 = mem_read16(t4);
		b = (uint8_t)t5;
		io_write16(IO_1FC6, ((uint32_t)(t5 >> 8) << 8) | b);
		t6 = io_read8(IO_1FC4);
		if (x > 0x493Fu)
			x = 0x4904u;
		unk_4902 = x;
	}
	if (unk_4812 != 0u)
	{
		a = saved_unk_480F;
		unk_480F = a;
		io_write8(IO_1FC2, a);
		return;
	}
	unk_4815++;
	unk_4812 = 1u;
	t7 = io_read8(IO_1FCA);
	d_2 = b;
	y = sub_07BC8B(y, d_2);
	u = IO_1F90;
	x = unk_4840_ADDRESS;
	sub_079248(x, u);
	u = 0x1F91u;
	x = unk_4844_ADDRESS;
	sub_079248(x, u);
	u = 0x1F92u;
	x = unk_4848_ADDRESS;
	sub_079248(x, u);
	u = 0x1F93u;
	x = unk_484C_ADDRESS;
	sub_079248(x, u);
	t8 = unk_48BE;
	t9 = t8 - 0x5Au;
	a = (t9 >> 8) & 1u;
	t10 = a | 0x1000u;
	io_write16(VIDEO_1A00, ((uint32_t)(uint8_t)t9 << 8) | (uint8_t)t10);
	io_write8(VIDEO_180C, (uint8_t)unk_48C5 - 0x10u);
	a = unk_480F & ~3u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
	t11 = unk_48CE;
	t12 = t11 - 0x5Au;
	a = (t12 >> 8) & 1u;
	t13 = a | 0x1000u;
	io_write16(VIDEO_3A00, ((uint32_t)(uint8_t)t12 << 8) | (uint8_t)t13);
	io_write8(VIDEO_380C, (uint8_t)unk_48D5 - 0x10u);
	t14 = unk_48BE;
	unk_48C1 = t14;
	t15 = unk_48C5;
	unk_48C8 = t15;
	t16 = unk_48CE;
	unk_48D1 = t16;
	t17 = unk_48D5;
	unk_48D8 = t17;
	unk_48AF = (uint8_t)(unk_48AC >> 8u);
	t18 = AT16(unk_48AC, -1);
	AT16(unk_48B0, -1) = t18;
	unk_48B5 = (uint8_t)(unk_48B2 >> 8u);
	t19 = AT16(unk_48B2, -1);
	AT16(unk_48B6, -1) = t19;
	unk_48BB = (uint8_t)(unk_48B8 >> 8u);
	t20 = AT16(unk_48B8, -1);
	b = (uint8_t)t20;
	unk_48BC = ((uint32_t)(t20 >> 8) << 8) | b;
	do
	{
	} while (unk_4856 != 0u);
	unk_4856 = 1u;
	d_2 = b;
	switch ((int8_t)(uint8_t)((uint32_t)unk_4800 << 1))
	{
	case 0:
		sub_079184(y, u, d_2);
		break;
	case 2:
		sub_079E39(y, u);
		break;
	case 4:
		sub_07A396(u);
		break;
	case 6:
		sub_07918D();
		break;
	case 8:
		sub_0791A2(y, d_2);
		break;
	}
	sub_07C367();
	sub_079841();
	a = saved_unk_480F;
	unk_480F = a;
	io_write8(IO_1FC2, a);
	enable_firq();
	take_interrupts();
	a = unk_480F | 4u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
	a = unk_4855 | 0x10u;
	unk_4855 = a;
	io_write8(IO_1FA5, a);
	unk_480E = 0x20u;
	set_lines(unk_480E);
	unk_4812 = 0u;
}

void sub_079184(uint16_t y, uint16_t u, uint8_t d)
{
	for (;;)
	{
		switch ((int8_t)(uint8_t)((uint32_t)unk_4801 << 1))
		{
		case 0:
			sub_07918D();
			return;
		case 2:
			break;
		case -6:
			continue;
		case -4:
			sub_079E39(y, u);
			return;
		case -2:
			sub_07A396(u);
			return;
		}
		break;
	}
	sub_0791A2(y, d);
}

void sub_07918D(void)
{
	uint16_t u = 0, x = 0, y = 0;

	sub_079269();
	sub_079692();
	y = unk_5900_ADDRESS;
	x = 0x5901u;
	unk_5900 = 0u;
	u = 0xEFu;
	while (u != 0u)
	{
		mem_write8(x, mem_read8(y));
		y++;
		x++;
		u--;
	}
	unk_4801++;
}

void sub_0791A2(uint16_t y, uint8_t d)
{
	uint8_t d_2 = 0;
	uint8_t stack = 0;

	stack = d;
	unk_480E = 0x2Fu;
	set_lines(unk_480E);
	d_2 = stack;
	sub_05E009(y, d_2);
}

void sub_0791B2(void)
{
	uint8_t a = 0;

	disable_firq();
	a = unk_480F & ~4u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
	a = unk_4855 & 0xEFu;
	unk_4855 = a;
	io_write8(IO_1FA5, a);
	unk_4856 = 0u;
}
