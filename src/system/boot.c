/**
 *    Name:        system/boot.c
 *    Description: the reset: the board set up, the RAM and ROM checks, the main loop that runs the jobs
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    07-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

void sub_0786CE(void)
{
	uint32_t zero = 0;
	uint8_t a = 0, b = 0, d_2 = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, u = 0, x = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t7 = 0, t11 = 0, t13 = 0, t14 = 0, t16 = 0, t19 = 0, t20 = 0, t21 = 0, t22 = 0, t23 = 0, t24 = 0, t25 = 0, t26 = 0, t28 = 0, t29 = 0, t34 = 0, t35 = 0, t36 = 0;
	uint16_t t5 = 0, t6 = 0, t8 = 0, t9 = 0, t10 = 0, t12 = 0, t15 = 0, t17 = 0, t18 = 0, t27 = 0, t30 = 0, t31 = 0, t32 = 0, t33 = 0, t37 = 0, t38 = 0;

	a = 0u;
	do
	{
		t1 = a + 1u;
		a = t1;
	} while (t1 != 0u);
	mem_write8(0x7C00u, 0x13u);
	io_write8(VIDEO_1D00, 0xFBu);
	io_write8(IO_1FC2, 0u);
	io_write8(IO_1FA4, 0x24u);
	io_write8(IO_1FC0, 0x30u);
	io_write8(VIDEO_1D80, 0x10u);
	io_write8(VIDEO_1F00, 0x32u);
	t2 = io_read8(VIDEO_1C80);
	io_write8(VIDEO_1C80, 0u);
	io_write16(IO_1FC6, 0u);
	t3 = io_read8(IO_1FC4);
	t4 = io_read8(VIDEO_1E80);
	io_write8(VIDEO_1E80, 0u);
	io_write16(IO_1FA0, 0u);
	io_write16(IO_1FA2, 0u);
	io_write8(IO_1FB0, 0x3Fu);
	io_write8(IO_1FB2, 4u);
	io_write8(IO_1FB3, 0x28u);
	io_write8(IO_1FB4, 0x18u);
	io_write8(IO_1FB6, 0x17u);
	io_write8(IO_1FB7, 0x27u);
	io_write8(IO_1FB8, 0x37u);
	io_write8(IO_1FB9, 0x13u);
	io_write8(IO_1FBA, 0x2Cu);
	io_write8(IO_1FBB, 0u);
	io_write8(IO_1FBC, 5u);
	a = 0u;
	do
	{
		u = unk_5D00_ADDRESS;
		x = 0x300u;
		do
		{
			t5 = u;
			u = t5 + 1u;
			mem_write8(t5, a);
			t6 = x - 1u;
			x = t6;
		} while (t6 != 0u);
		t7 = io_read8(IO_1FCA);
		u = unk_5D00_ADDRESS;
		x = 0x300u;
		do
		{
			t8 = u;
			u = t8 + 1u;
			if (a != mem_read8(t8))
			{
				b = 0x1Bu;
				u = loaded_table_07E3D0_ADDRESS;
				x = 0x2313u;
				do
				{
					mem_write8(x - 0x2000u, 0u);
					t9 = u;
					u = t9 + 1u;
					t10 = x;
					x = t10 + 1u;
					mem_write8(t10, mem_read8(t9) - 0x30u);
					t11 = b;
					b = t11 - 1u;
				} while (t11 != 1u);
				a = 8u;
				do
				{
					x = 0u;
					do
					{
						t12 = x - 1u;
						x = t12;
					} while (t12 != 0u);
					t13 = io_read8(IO_1FCA);
					t14 = a;
					a = t14 - 1u;
				} while (t14 != 1u);
				sub_078F24();
				sub_0786CE();
				return;
			}
			t15 = x - 1u;
			x = t15;
		} while (t15 != 0u);
		t16 = io_read8(IO_1FCA);
		a += 0x55u;
	} while (a != 0x54u);
	u = unk_5D00_ADDRESS;
	x = 0x300u;
	do
	{
		t17 = u;
		u = t17 + 1u;
		mem_write8(t17, 0u);
		t18 = x - 1u;
		x = t18;
	} while (t18 != 0u);
	zero = sub_078B11();
	if (zero == 0u)
	{
		b = 0x1Bu;
		u = loaded_table_07E3D0_ADDRESS;
		x = 0x2313u;
		do
		{
			mem_write8(x - 0x2000u, 0u);
			t9 = u;
			u = t9 + 1u;
			t10 = x;
			x = t10 + 1u;
			mem_write8(t10, mem_read8(t9) - 0x30u);
			t11 = b;
			b = t11 - 1u;
		} while (t11 != 1u);
		a = 8u;
		do
		{
			x = 0u;
			do
			{
				t12 = x - 1u;
				x = t12;
			} while (t12 != 0u);
			t13 = io_read8(IO_1FCA);
			t14 = a;
			a = t14 - 1u;
		} while (t14 != 1u);
		sub_078F24();
		sub_0786CE();
		return;
	}
	y = unk_4000_ADDRESS;
	x = 0x4001u;
	unk_4000 = 0u;
	u = 0x1FFFu;
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
	u = 0x1BFu;
	while (u != 0u)
	{
		mem_write8(x, mem_read8(y));
		y++;
		x++;
		u--;
	}
	io_write8(IO_1FC2, 0u);
	y = VIDEO_3840;
	x = 0x3841u;
	io_write8(VIDEO_3840, 0u);
	u = 0x1BFu;
	while (u != 0u)
	{
		mem_write8(x, mem_read8(y));
		y++;
		x++;
		u--;
	}
	y = VIDEO_3C00;
	x = 0x3C01u;
	io_write8(VIDEO_3C00, 0u);
	u = 0x3FFu;
	while (u != 0u)
	{
		mem_write8(x, mem_read8(y));
		y++;
		x++;
		u--;
	}
	io_write8(IO_1FC2, 2u);
	y = VIDEO_2000;
	x = 0x2001u;
	io_write8(VIDEO_2000, 0u);
	u = 0x1FFFu;
	while (u != 0u)
	{
		mem_write8(x, mem_read8(y));
		y++;
		x++;
		u--;
	}
	io_write8(IO_1FC2, 1u);
	y = 0u;
	x = 1u;
	io_write8(0u, 0u);
	u = 0xFFFu;
	while (u != 0u)
	{
		mem_write8(x, mem_read8(y));
		y++;
		x++;
		u--;
	}
	io_write8(IO_1FC2, 1u);
	t19 = io_read8(IO_1FCA);
	enable_firq();
	take_interrupts();
	unk_480F = 4u;
	io_write8(IO_1FC2, 4u);
	unk_4855 = 0x34u;
	io_write8(IO_1FA5, 0x34u);
	unk_4856 = 1u;
	do
	{
		t20 = unk_4856;
		frame_wait(SIMPSONS_BOOT_WAIT);
		take_interrupts();
	} while (t20 != 0u);
	t21 = io_read8(IO_1F81);
	if ((t21 & 1u) == 0u)
	{
		sub_078D8C();
		a = unk_480F & ~3u;
		unk_480F = a;
		io_write8(IO_1FC2, a);
		sub_079269();
		t22 = io_read8(IO_1FCA);
		d = 6u;
		sub_079311(d);
		unk_480E = 0x2Fu;
		set_lines(unk_480E);
		d = sub_05E000();
		a = (uint8_t)(d >> 8);
		if (a != 0u)
		{
			d = 8u;
			sub_079311(d);
			for (;;)
			{
			}
		}
		d = 7u;
		sub_079311(d);
		d = 9u;
		sub_079311(d);
		unk_480E = 0x2Fu;
		set_lines(unk_480E);
		sub_05E006();
		d = 0xAu;
		sub_079311(d);
		do
		{
			t23 = io_read8(IO_1F81);
			frame_wait(SIMPSONS_SWITCH_WAIT);
			take_interrupts();
		} while ((t23 & 1u) == 0u);
	}
	unk_480E = 0x2Fu;
	set_lines(unk_480E);
	d |= 0x6F00u;
	d = sub_05E012(d);
	b = (uint8_t)d;
	if (b != 0u)
		io_write8(VIDEO_1E80, 1u);
	else
	{
		t24 = io_read8(VIDEO_1E80);
		io_write8(VIDEO_1E80, 0u);
	}
	sub_078B1C();
	io_write8(IO_1FA5, 0x24u);
	unk_4855 = 0x24u;
	io_write16(VIDEO_1A00, 0u);
	io_write16(VIDEO_3A00, 0u);
	io_write8(VIDEO_180C, 0u);
	io_write8(VIDEO_380C, 0u);
	x = 0u;
	u = loaded_table_05F1E0_ADDRESS;
	d = (d & 0xFFu) | 0xF00u;
	d = sub_07BF51(x, u, d);
	x = 0x400u;
	u = 0x6F00u;
	d = (d & 0xFFu) | 0x300u;
	d = sub_07BF51(x, u, d);
	x = 0x800u;
	u = 0x6000u;
	d = (d & 0xFFu) | 0x300u;
	d = sub_07BF51(x, u, d);
	x = 0xA00u;
	u = 0x6860u;
	d = (d & 0xFFu) | 0x300u;
	sub_07BF51(x, u, d);
	sub_079269();
	t25 = io_read8(IO_1FCA);
	sub_079269();
	t26 = io_read8(IO_1FCA);
	unk_4856 = 1u;
	sub_078ADE();
	a = 3u;
	do
	{
		x = 0u;
		do
		{
			t27 = x - 1u;
			x = t27;
		} while (t27 != 0u);
		t28 = io_read8(IO_1FCA);
		t29 = a;
		a = t29 - 1u;
	} while (t29 != 1u);
	x = 0x4944u;
	unk_4940 = 0x4944u;
	unk_4942 = 0x4944u;
	a = 0xFFu;
	b = 0xFFu;
	do
	{
		t30 = x;
		x = t30 + 2u;
		mem_write16(t30, ((uint32_t)a << 8) | b);
	} while (x != 0x4980u);
	x = 0x4904u;
	unk_4900 = 0x4904u;
	unk_4902 = 0x4904u;
	a = 0xFFu;
	b = 0xFFu;
	do
	{
		t31 = x;
		x = t31 + 2u;
		mem_write16(t31, ((uint32_t)a << 8) | b);
	} while (x != unk_4940_ADDRESS);
	u = 0x4980u;
	x = loaded_table_07E380_ADDRESS;
	b = 0x50u;
	do
	{
		t32 = x;
		x = t32 + 1u;
		t33 = u;
		u = t33 + 1u;
		mem_write8(t33, mem_read8(t32));
		t34 = b;
		b = t34 - 1u;
	} while (t34 != 1u);
	sub_07955F(&ignored16_2, &ignored16);
	t35 = io_read8(IO_1FCA);
	unk_480E = 0x2Fu;
	set_lines(unk_480E);
	sub_05E00F();
	sub_078A1A();
	unk_4800 = 1u;
	io_write8(IO_1FC0, unk_4810);
	t36 = io_read8(IO_1FCA);
	unk_4812 = 0u;
	unk_4856 = 1u;
	a = unk_480F & ~3u;
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
	enable_irq();
	take_interrupts();
	io_write8(VIDEO_1D00, 0xFFu);
	for (;;)
	{
		unk_480E = 0x20u;
		set_lines(unk_480E);
		sub_040003();
		x = unk_4942;
		t37 = mem_read16(x);
		a = (uint8_t)(t37 >> 8);
		b = (uint8_t)t37;
		frame_wait(SIMPSONS_FRAME_WAIT);
		take_interrupts();
		if ((int16_t)t37 < 0)
			continue;
		t38 = x;
		x = t38 + 2u;
		mem_write16(t38, 0xFFFFu);
		if (x >= 0x497Fu)
			x = 0x4944u;
		unk_4942 = x;
		a = (uint32_t)a << 1;
		d_2 = b;
		switch ((int8_t)a)
		{
		case 0:
			sub_079808(d_2);
			break;
		case 2:
			sub_07981E(d_2);
			break;
		case 4:
			sub_079824(d_2);
			break;
		case 6:
			sub_079828(d_2);
			break;
		case 8:
			sub_07982E(d_2);
			break;
		case 10:
			sub_079834(d_2);
			break;
		case 12:
			sub_07983A(d_2);
			break;
		case 14:
		case 16:
		case 18:
		case 20:
		case 22:
		case 24:
		case 26:
		case 28:
		case 30:
			sub_079840();
			break;
		}
	}
}

void sub_0789EC(void)
{
}

void sub_078A1A(void)
{
	uint8_t a = 0;
	uint16_t x = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;

	x = unk_59F1_ADDRESS;
	a = coinages[(int8_t)unk_59F1];
	stack = a;
	a &= 0xFu;
	unk_481D = a;
	unk_4825 = a;
	a = (((stack >> 1) >> 1) >> 1) >> 1;
	unk_481C = a;
	unk_4824 = a;
	if (unk_59F8 == 0u)
	{
		unk_483B = 1u;
		unk_4839 = 1u;
	}
	else
	{
		unk_483B = 0u;
		unk_4839 = 0u;
	}
	t1 = mem_read8(x + 4u);
	unk_485A = t1 + 1u;
	t2 = mem_read8(x + 3u);
	unk_4814 = t2;
	t3 = mem_read8(x + 5u);
	unk_4813 = t3;
	t4 = mem_read8(x + 6u);
	if (t4 != 0u)
	{
		io_write8(VIDEO_1E80, 1u);
		a = unk_4855 | 3u;
		unk_4855 = a;
		io_write8(IO_1FA5, a);
		unk_485F = 1u;
		io_write16(IO_1FA0, 0x255u);
		unk_4886 = 0x255u;
		io_write16(IO_1FA2, 0x71u);
		unk_4889 = 0x71u;
	}
	else
	{
		io_write8(VIDEO_1E80, 0u);
		a = unk_4855 & ~3u;
		unk_4855 = a;
		io_write8(IO_1FA5, a);
		unk_485F = 0u;
		io_write16(IO_1FA0, 0x15u);
		unk_4886 = 0x15u;
		io_write16(IO_1FA2, 0x261u);
		unk_4889 = 0x261u;
	}
	unk_4888 = 0u;
	unk_488B = 0u;
	a = 0x30u;
	t5 = mem_read8(x + 8u);
	if (t5 != 0u)
		a |= 4u;
	unk_4810 = a;
	t6 = mem_read8(x + 9u);
	unk_483A = t6;
}

void sub_078ADE(void)
{
	uint8_t a = 0, b = 0;
	uint16_t u = 0, x = 0;
	uint8_t t2 = 0, t4 = 0, t5 = 0;
	uint16_t t1 = 0, t3 = 0;

	a = unk_480F & ~3u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
	x = 0x200Eu;
	b = 0x10u;
	do
	{
		a = 0x12u;
		u = 0x2F2Eu;
		do
		{
			t1 = x;
			x = t1 + 2u;
			mem_write16(t1, u);
			t2 = a;
			a = t2 - 1u;
		} while (t2 != 1u);
		x += 0x1Cu;
		a = 0x12u;
		u = 0x2D2Cu;
		do
		{
			t3 = x;
			x = t3 + 2u;
			mem_write16(t3, u);
			t4 = a;
			a = t4 - 1u;
		} while (t4 != 1u);
		x += 0x1Cu;
		t5 = b;
		b = t5 - 1u;
	} while (t5 != 1u);
}

uint32_t sub_078B11(void)
{
	uint32_t zero = 0;
	uint16_t d = 0, u = 0, y = 0;

	u = unk_4000_ADDRESS;
	y = 0xE80u;
	d = sub_078DCF(y, u);
	zero = (uint8_t)d == 0u;
	return zero;
}

void sub_078B1C(void)
{
	uint8_t a = 0, b = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_3 = 0, u = 0, x = 0, y = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0, t8 = 0, t9 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0;

	unk_5D02 = 0u;
	unk_5D03 = 0u;
	do
	{
	} while (unk_4856 != 0u);
	io_write8(IO_1FC2, 6u);
	u = VIDEO_2000;
	y = 0x1000u;
	d = sub_078DCF(y, u);
	b = (uint8_t)d;
	unk_5D04 = b;
	io_write8(IO_1FC2, 4u);
	u = VIDEO_2000;
	y = VIDEO_0C00;
	d = sub_078DCF(y, u);
	b = (uint8_t)d;
	unk_5D05 = b;
	u = VIDEO_1840;
	y = 0xE0u;
	d = sub_078DCF(y, u);
	b = (uint8_t)d;
	unk_5D05 |= b;
	u = 0u;
	y = VIDEO_0C00;
	d = sub_078DCF(y, u);
	b = (uint8_t)d;
	unk_5D06 = b;
	u = VIDEO_3840;
	y = 0xE0u;
	d = sub_078DCF(y, u);
	b = (uint8_t)d;
	unk_5D06 |= b;
	u = VIDEO_3C00;
	y = 0x200u;
	d = sub_078DCF(y, u);
	b = (uint8_t)d;
	unk_5D06 |= b;
	io_write8(IO_1FC2, 5u);
	u = 1u;
	y = 0x800u;
	d = sub_078E19(y, u);
	b = (uint8_t)d;
	unk_5D07 = b;
	io_write8(IO_1FC2, 5u);
	u = 0u;
	y = 0x800u;
	d = sub_078E19(y, u);
	b = (uint8_t)d;
	unk_5D08 = b;
	unk_480E = 0x2Fu;
	set_lines(unk_480E);
	d = sub_05E00C();
	b = (uint8_t)d;
	unk_5D09 = b;
	sub_079269();
	t1 = io_read8(IO_1FCA);
	d = 0xBu;
	sub_079311(d);
	u = 0x2122u;
	d = unk_5D03;
	sub_078E7F(u, (uint8_t)d);
	u = 0x21A2u;
	d = unk_5D04;
	sub_078E7F(u, (uint8_t)d);
	u = 0x2222u;
	d = unk_5D05;
	sub_078E7F(u, (uint8_t)d);
	u = 0x22A2u;
	d = unk_5D06;
	sub_078E7F(u, (uint8_t)d);
	u = 0x2322u;
	d = unk_5D07;
	sub_078E7F(u, (uint8_t)d);
	u = 0x23A2u;
	d = unk_5D08;
	sub_078E7F(u, (uint8_t)d);
	u = 0x2422u;
	d = unk_5D09;
	sub_078E7F(u, (uint8_t)d);
	sub_078D8C();
	unk_48FA = 0u;
	stack = 0x20u;
	do
	{
		unk_480E = stack;
		set_lines(unk_480E);
		sub_078E5B();
		stack = stack + 1u;
	} while (stack != 0x30u);
	t2 = unk_48FA;
	if (t2 != rom_13c_sum[0])
		b = 3u;
	else
		b = 0u;
	u = 0x24A2u;
	d = b;
	d = sub_078E7F(u, (uint8_t)d);
	x = 0x24A6u;
	sub_078DBD(x, (uint8_t)d);
	unk_48FA = 0u;
	x = loaded_table_078000_ADDRESS;
	u = loaded_table_078000_ADDRESS;
	sub_078E63(x, u);
	stack = 0x30u;
	do
	{
		unk_480E = stack;
		set_lines(unk_480E);
		sub_078E5B();
		stack = stack + 1u;
	} while (stack != 0x3Cu);
	t3 = unk_48FA;
	if (t3 != rom_15c_sum[0])
		b = 3u;
	else
		b = 0u;
	u = 0x2522u;
	d = b;
	d = sub_078E7F(u, (uint8_t)d);
	x = 0x2526u;
	sub_078DBD(x, (uint8_t)d);
	unk_48FA = 0u;
	stack = 0u;
	do
	{
		unk_480E = stack;
		set_lines(unk_480E);
		sub_078E5B();
		stack = stack + 1u;
	} while (stack != 0x10u);
	t4 = unk_48FA;
	if (t4 != rom_16c_sum[0])
		b = 3u;
	else
		b = 0u;
	u = 0x25A2u;
	d = b;
	d = sub_078E7F(u, (uint8_t)d);
	x = 0x25A6u;
	sub_078DBD(x, (uint8_t)d);
	unk_48FA = 0u;
	stack = 0x10u;
	do
	{
		unk_480E = stack;
		set_lines(unk_480E);
		sub_078E5B();
		stack = stack + 1u;
	} while (stack != 0x20u);
	t5 = unk_48FA;
	if (t5 != rom_17c_sum[0])
		b = 3u;
	else
		b = 0u;
	u = 0x2622u;
	d = b;
	d = sub_078E7F(u, (uint8_t)d);
	x = 0x2626u;
	sub_078DBD(x, (uint8_t)d);
	sub_078EB0(&ignored16, &d);
	a = (uint8_t)(d >> 8);
	if ((int8_t)a >= 0)
	{
		d = sub_078ED2();
		a = (uint8_t)(d >> 8);
		b = (uint8_t)d;
		unk_48FA = ((uint32_t)a << 8) | b;
		sub_078EB0(&ignored16, &d);
		a = (uint8_t)(d >> 8);
		b = 0u;
		if ((a & 2u) != 0u)
			b = 3u;
		u = 0x26A2u;
		d = b;
		d = sub_078E7F(u, (uint8_t)d);
		x = 0x26A6u;
		sub_078DBD(x, (uint8_t)d);
		sub_078EB0(&ignored16, &d);
		a = (uint8_t)(d >> 8);
		b = 0u;
		if ((a & 1u) != 0u)
			b = 3u;
		u = 0x2722u;
		d = b;
		sub_078E7F(u, (uint8_t)d);
	}
	else
	{
		u = 0x26A2u;
		d = 3u;
		sub_078E7F(u, (uint8_t)d);
		u = 0x2722u;
		d = 3u;
		sub_078E7F(u, (uint8_t)d);
		unk_5D02 = 1u;
	}
	unk_48F2 = 0x10u;
	do
	{
		a = 0u;
		b = 0u;
		do
		{
			t6 = ((uint32_t)a << 8) | b;
			t7 = t6 - 1u;
			a = (uint8_t)(t7 >> 8);
			b = (uint8_t)t7;
		} while (t6 != 1u);
		t8 = io_read8(IO_1FCA);
		t9 = unk_48F2;
		unk_48F2 = t9 - 1u;
	} while (t9 != 1u);
	if (unk_5D02 != 0u)
	{
		sub_0786CE();
		return;
	}
	sub_07927A(&ignored16, &ignored16_3);
}

void sub_078D8C(void)
{
	uint8_t a = 0, d = 0;
	uint16_t x = 0;
	uint8_t stack = 0;
	uint8_t t2 = 0, t4 = 0;
	uint16_t t1 = 0, t3 = 0;

	io_write8(IO_1FC2, 5u);
	x = 0x400u;
	stack = 0xFu;
	d = 0xFFu;
	a = 0xFFu;
	do
	{
		t1 = x;
		x = t1 + 2u;
		mem_write16(t1, ((uint32_t)a << 8) | (d & 0xFFu));
		t2 = stack;
		stack = t2 - 1u;
	} while (t2 != 1u);
	mem_write16(x, 0u);
	x = 0x420u;
	stack = 0x10u;
	d = 0x1Fu;
	a = 0u;
	do
	{
		t3 = x;
		x = t3 + 2u;
		mem_write16(t3, ((uint32_t)a << 8) | d);
		t4 = stack;
		stack = t4 - 1u;
	} while (t4 != 1u);
}

void sub_078DBD(uint16_t x, uint8_t d)
{
	uint8_t b = 0;
	uint16_t d_2 = 0;

	b = (uint8_t)d;
	unk_48F0 = 0u;
	if (b != 0u)
		b = 0x40u;
	unk_48F0 = b;
	d_2 = unk_48FA;
	sub_07947D(x, d_2);
}

uint16_t sub_078DCF(uint16_t y, uint16_t u)
{
	uint16_t d = 0, u_2 = 0, x = 0;
	uint16_t stack = 0;
	uint8_t t2 = 0, t4 = 0, t6 = 0;
	uint16_t t1 = 0, t3 = 0, t5 = 0, t7 = 0, t8 = 0;

	x = 0xFFFFu;
	unk_5D00 = u;
	do
	{
		stack = y;
		d = stack;
		u_2 = unk_5D00;
		do
		{
			t1 = u_2;
			u_2 = t1 + 2u;
			mem_write16(t1, x);
			t2 = io_read8(IO_1FCA);
			t3 = d;
			d = t3 - 1u;
		} while (t3 != 1u);
		d = 0x1000u;
		do
		{
			t4 = io_read8(IO_1FCA);
			t5 = d;
			d = t5 - 1u;
		} while (t5 != 1u);
		stack = y;
		d = stack;
		u_2 = unk_5D00;
		do
		{
			t6 = io_read8(IO_1FCA);
			t7 = u_2;
			u_2 = t7 + 2u;
			if (x != mem_read16(t7))
			{
				d = (d & ~0xFFu) | 3u;
				return d;
			}
			t8 = d;
			d = t8 - 1u;
		} while (t8 != 1u);
		x -= 0x5555u;
	} while (x != 0xAAABu);
	d &= ~0xFFu;
	return d;
}

uint16_t sub_078E19(uint16_t y, uint16_t u)
{
	uint8_t a = 0;
	uint16_t d = 0, u_2 = 0, x = 0;
	uint8_t t2 = 0, t4 = 0, t6 = 0;
	uint16_t t1 = 0, t3 = 0, t5 = 0, t7 = 0, t8 = 0;

	a = 0xFFu;
	unk_5D00 = u;
	do
	{
		x = y;
		u_2 = unk_5D00;
		do
		{
			t1 = u_2;
			u_2 = t1 + 2u;
			mem_write8(t1, a);
			t2 = io_read8(IO_1FCA);
			t3 = x - 1u;
			x = t3;
		} while (t3 != 0u);
		x = 0x1000u;
		do
		{
			t4 = io_read8(IO_1FCA);
			t5 = x - 1u;
			x = t5;
		} while (t5 != 0u);
		x = y;
		u_2 = unk_5D00;
		do
		{
			t6 = io_read8(IO_1FCA);
			t7 = u_2;
			u_2 = t7 + 2u;
			if (a != mem_read8(t7))
			{
				d = ((uint32_t)a << 8) | 3u;
				return d;
			}
			t8 = x - 1u;
			x = t8;
		} while (t8 != 0u);
		a -= 0x55u;
	} while (a != 0xABu);
	d = (uint32_t)a << 8;
	return d;
}

void sub_078E5B(void)
{
	uint16_t u = 0, x = 0;

	x = 0x6000u;
	u = VIDEO_2000;
	add_rom_bytes(x, u);
}

void sub_078E63(uint16_t x, uint16_t u)
{
	unk_48FA = 0u;
	add_rom_bytes(x, u);
}

void BOARD_ORIGINAL(add_rom_bytes)(uint16_t x, uint16_t u)
{
	uint32_t carry = 0;
	uint8_t b = 0;
	uint8_t t3 = 0, t4 = 0;
	uint16_t t1 = 0, t2 = 0;

	do
	{
		t1 = unk_48FA;
		b = (uint8_t)t1;
		t2 = x;
		x = t2 + 1u;
		t3 = mem_read8(t2);
		carry = (uint8_t)(b + t3) < b;
		unk_48FA = ((uint32_t)(uint8_t)((t1 >> 8) + carry) << 8) | (uint8_t)(b + t3);
		u--;
	} while (u != 0u);
	t4 = io_read8(IO_1FCA);
}

uint16_t sub_078E7F(uint16_t u, uint8_t d)
{
	uint8_t a = 0, b = 0;
	uint16_t d_2 = 0, x = 0;
	uint8_t stack = 0;
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0;

	b = (uint8_t)d;
	stack = b;
	unk_5D02 |= b;
	b = stack;
	io_write8(IO_1FC2, 4u);
	x = loaded_table_07E41B_ADDRESS;
	if (b != 0u)
	{
		x += b;
		b = 0x40u;
	}
	unk_48F0 = 3u;
	do
	{
		mem_write8(u - 0x2000u, b);
		t1 = x;
		x = t1 + 1u;
		a = mem_read8(t1) - 0x30u;
		t2 = u;
		u = t2 + 1u;
		mem_write8(t2, a);
		t3 = unk_48F0;
		unk_48F0 = t3 - 1u;
	} while (t3 != 1u);
	d_2 = ((uint32_t)a << 8) | stack;
	return d_2;
}

void sub_078EB0(uint16_t *p_x, uint16_t *p_d)
{
	uint8_t d = 0;
	uint16_t d_2 = 0, x = 0;
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0, t4 = 0;

	d = 0x81u;
	io_write16(IO_1FC6, 0xF181u);
	t1 = io_read8(IO_1FC4);
	x = VIDEO_2000;
	for (;;)
	{
		t2 = x - 1u;
		x = t2;
		if (t2 == 0u)
		{
			d_2 = 0x8F00u;
			break;
		}
		t3 = io_read8(0x1FC7u);
		if ((uint8_t)d == t3)
		{
			t4 = io_read16(IO_1FC6);
			d_2 = t4;
			break;
		}
	}
	*p_x = x;
	*p_d = d_2;
}

uint16_t sub_078ED2(void)
{
	uint8_t a = 0;
	uint16_t d = 0;
	uint8_t stack = 0;

	d = 0xF383u;
	d = sub_078F30(d);
	a = (uint8_t)(d >> 8);
	stack = a;
	d = 0xF282u;
	d = sub_078F30(d);
	a = (uint8_t)(d >> 8);
	d = ((uint32_t)stack << 8) | a;
	return d;
}

void sub_078F24(void)
{
	uint8_t t1 = 0;

	io_write16(IO_1FC6, 0xFF00u);
	t1 = io_read8(IO_1FC4);
}

uint16_t sub_078F30(uint16_t d)
{
	uint16_t d_2 = 0;
	uint8_t t1 = 0, t2 = 0;
	uint16_t t3 = 0;

	io_write16(IO_1FC6, d);
	t1 = io_read8(IO_1FC4);
	do
	{
		t2 = io_read8(0x1FC7u);
	} while ((uint8_t)d != t2);
	t3 = io_read16(IO_1FC6);
	d_2 = t3;
	return d_2;
}
