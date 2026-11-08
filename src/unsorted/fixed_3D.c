/**
 *    Name:        unsorted/fixed_3D.c
 *    Description: the fixed program's code, 07A000-07BFFF
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    07-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

void sub_07A007(void)
{
	uint16_t d = 0;
	uint8_t t1 = 0;

	sub_07A052();
	t1 = unk_4809;
	unk_4809 = t1 - 1u;
	if (t1 != 1u)
		return;
	d = 0x82u;
	sub_079311(d);
	d = 0x10u;
	sub_079311(d);
	d = 0x11u;
	sub_079311(d);
	unk_4802++;
}

void sub_07A024(void)
{
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, u = 0;
	uint8_t t1 = 0;

	sub_07A052();
	t1 = unk_4809;
	unk_4809 = t1 - 1u;
	if (t1 != 1u)
		return;
	unk_48C5 = 0u;
	unk_48D5 = 0u;
	sub_07955F(&ignored16, &u);
	unk_487E = 3u;
	d = 0u;
	sub_07BAC7(d, &ignored16_2, &u);
	unk_4801++;
	unk_4802 = 0u;
	unk_4803 = 0u;
	unk_4804 = 0u;
	unk_4805 = 0u;
}

void sub_07A052(void)
{
	uint32_t carry = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	t1 = AT16(unk_48BE, -1);
	t2 = t1;
	t3 = t2 - 0x40u;
	carry = t2 < 0x40u;
	AT16(unk_48BE, -1) = t3;
	unk_48BE = (unk_48BE & 0xFFu) | (((uint8_t)(unk_48BE >> 8u) - carry & 0xFFu) << 8u);
	t4 = AT16(unk_48CE, -1);
	t5 = t4;
	carry = (uint16_t)(t5 + 0x40u) < t5;
	AT16(unk_48CE, -1) = t5 + 0x40u;
	unk_48CE = (unk_48CE & 0xFFu) | (((uint8_t)(unk_48CE >> 8u) + carry & 0xFFu) << 8u);
}

void sub_07A075(uint16_t y, uint16_t u)
{
	for (;;)
	{
		switch ((int8_t)(uint8_t)((uint32_t)unk_4802 << 1))
		{
		case 0:
			sub_07A07E();
			return;
		case 2:
			sub_07A12B(u);
			return;
		case 4:
			sub_07A212(u);
			return;
		case 6:
			sub_07A240();
			return;
		case 8:
			sub_07A28C(u);
			return;
		case 10:
			sub_07A29B(u);
			return;
		case 12:
			sub_07A2D6(u);
			return;
		case 14:
			sub_07A2EB();
			return;
		case 16:
			sub_07A314();
			return;
		case 18:
			sub_07A329(u);
			return;
		case 20:
			sub_07A357();
			return;
		case 22:
			sub_07A35F();
			return;
		case 24:
			break;
		case -28:
			sub_079EDA(y, u);
			return;
		case -26:
			continue;
		case -24:
			sub_079F36(y, u);
			return;
		case -22:
			sub_07A209(y, u);
			return;
		case -20:
			sub_07A2CD(y, u);
			return;
		case -18:
			sub_07A34E(y, u);
			return;
		case -16:
			sub_079EE3();
			return;
		case -14:
			sub_079EF6();
			return;
		case -12:
			sub_079F08(y, u);
			return;
		case -10:
			sub_079F17();
			return;
		case -8:
			sub_079F3F();
			return;
		case -6:
			sub_079F52(u);
			return;
		case -4:
			sub_07A007();
			return;
		case -2:
			sub_07A024();
			return;
		}
		break;
	}
	sub_07A384();
}

void sub_07A07E(void)
{
	uint16_t d = 0, ignored16 = 0, ignored16_3 = 0, inputs = 0, player = 0, record = 0, u = 0, x = 0, y = 0;
	uint8_t stack = 0, stack_2 = 0;
	uint8_t frames_2 = 0;
	uint16_t t1 = 0, t2 = 0, frames = 0, t3 = 0, state = 0, object_kind = 0, t4 = 0, lives = 0, lives_2 = 0, state_2 = 0;

	sub_079269();
	sub_0796A3();
	sub_07955F(&ignored16, &u);
	unk_487E = 1u;
	d = 0x880u;
	sub_07BAC7(d, &ignored16_3, &u);
	AT16(unk_4858, -1) = 0u;
	unk_4815 = 0u;
	y = unk_5800_ADDRESS;
	x = 0x5801u;
	unk_5800 &= 0xFFu;
	u = 0xFFu;
	while (u != 0u)
	{
		mem_write8(x, mem_read8(y));
		y++;
		x++;
		u--;
	}
	t1 = demos[(int8_t)((uint8_t)((uint32_t)unk_485E << 1)) / 2];
	unk_4850 = DEMO(t1)->players;
	t2 = t1 + 1u;
	frames = DEMO(t2 - 0x1u)->frames;
	unk_5800 = frames;
	t3 = t2 + 2u;
	x = t3 + 1u;
	unk_4803 = DEMO(t3 - 0x3u)->step;
	unk_4804 = 0u;
	unk_4805 &= 0xFFu;
	unk_4805 &= 0xFF00u;
	unk_480E = 0x2Cu;
	set_lines(unk_480E);
	y = 0x5810u;
	unk_48F0 = 0u;
	unk_48F1 = unk_4850;
	do
	{
		player = player_records[(int8_t)((uint8_t)((uint32_t)unk_48F0 << 1)) / 2];
		state = PLAYER(player)->state;
		mem_write8(state, 0u);
		stack_2 = player >> 8;
		stack = (uint8_t)player;
		object_kind = PLAYER(player)->object_kind;
		mem_write8(object_kind, unk_48F0);
		t4 = x;
		x = t4 + 2u;
		inputs = mem_read16(t4);
		mem_write16(y, inputs);
		frames_2 = DEMO_INPUT(inputs)->frames;
		mem_write8(y + 2u, frames_2);
		mem_write8(y + 3u, DEMO_INPUT(inputs)->controls);
		record = ((uint32_t)stack_2 << 8) | stack;
		lives = PLAYER(record)->lives;
		mem_write8(lives, 0u);
		if ((unk_48F1 & 1u) != 0u)
		{
			lives_2 = PLAYER(record)->lives;
			mem_write8(lives_2, 2u);
			state_2 = PLAYER(record)->state;
			mem_write8(state_2, 2u);
		}
		y += 0x10u;
		unk_48F1 = unk_48F1 >> 1;
		unk_48F0++;
	} while (unk_48F0 != 4u);
	unk_4802++;
}

void sub_07A12B(uint16_t u)
{
	uint8_t a = 0;
	uint16_t d = 0, ignored16 = 0, u_2 = 0, x = 0, y = 0;
	uint8_t t2 = 0, t3 = 0;
	uint16_t t1 = 0, object_kind = 0;

	if (unk_4804 == 2u)
	{
		unk_480E = 0x20u;
		set_lines(unk_480E);
		sub_04000C();
		unk_487E = 2u;
		d = 0xBu;
		sub_07BAC7(d, &ignored16, &u);
	}
	t1 = unk_5800;
	unk_5800 = t1 - 1u;
	if (t1 == 1u)
	{
		unk_485E++;
		if (unk_485E >= 3u)
			unk_485E = 0u;
		sub_0796A3();
		unk_4801++;
		unk_4802 = 0u;
		unk_4803 = 0u;
		unk_4804 = 0u;
		unk_4805 = 0u;
		return;
	}
	unk_480E = 0x2Cu;
	set_lines(unk_480E);
	y = 0x5810u;
	unk_48F0 = 0u;
	unk_48F1 = unk_4850;
	do
	{
		object_kind = PLAYER(player_records[(int8_t)((uint8_t)((uint32_t)unk_48F0 << 1)) / 2])->object_kind;
		mem_write8(object_kind, unk_48F0);
		u_2 = mem_read16(y);
		mem_write8(y + 3u, mem_read8(u_2));
		t2 = mem_read8(y + 2u);
		mem_write8(y + 2u, t2 - 1u);
		if (t2 == 1u)
		{
			u_2 += 2u;
			a = io_read8(u_2);
			mem_write8(y + 3u, a);
			mem_write8(y + 4u, ~a);
			t3 = mem_read8(u_2 + 1u);
			mem_write8(y + 2u, t3);
			mem_write16(y, u_2);
		}
		y += 0x10u;
		unk_48F1 = unk_48F1 >> 1;
		unk_48F0++;
	} while (unk_48F0 != 4u);
	unk_5813 = ~unk_5813;
	u_2 = unk_5813_ADDRESS;
	x = unk_4840_ADDRESS;
	sub_07924D(x, u_2);
	unk_5823 = ~unk_5823;
	u_2 = unk_5823_ADDRESS;
	x = unk_4844_ADDRESS;
	sub_07924D(x, u_2);
	unk_5833 = ~unk_5833;
	u_2 = unk_5833_ADDRESS;
	x = unk_4848_ADDRESS;
	sub_07924D(x, u_2);
	unk_5843 = ~unk_5843;
	u_2 = unk_5843_ADDRESS;
	x = unk_484C_ADDRESS;
	sub_07924D(x, u_2);
	sub_07A396(u_2);
	unk_4811 = 1u;
}

void sub_07A209(uint16_t y, uint16_t u)
{
	for (;;)
	{
		switch ((int8_t)(uint8_t)((uint32_t)unk_4802 << 1))
		{
		case 0:
			sub_07A212(u);
			return;
		case 2:
			sub_07A240();
			return;
		case 4:
			sub_07A28C(u);
			return;
		case 6:
			sub_07A29B(u);
			return;
		case 8:
			sub_07A2D6(u);
			return;
		case 10:
			sub_07A2EB();
			return;
		case 12:
			sub_07A314();
			return;
		case 14:
			sub_07A329(u);
			return;
		case 16:
			sub_07A357();
			return;
		case 18:
			sub_07A35F();
			return;
		case 20:
			break;
		case -32:
			sub_079EDA(y, u);
			return;
		case -30:
			sub_07A075(y, u);
			return;
		case -28:
			sub_079F36(y, u);
			return;
		case -26:
			continue;
		case -24:
			sub_07A2CD(y, u);
			return;
		case -22:
			sub_07A34E(y, u);
			return;
		case -20:
			sub_079EE3();
			return;
		case -18:
			sub_079EF6();
			return;
		case -16:
			sub_079F08(y, u);
			return;
		case -14:
			sub_079F17();
			return;
		case -12:
			sub_079F3F();
			return;
		case -10:
			sub_079F52(u);
			return;
		case -8:
			sub_07A007();
			return;
		case -6:
			sub_07A024();
			return;
		case -4:
			sub_07A07E();
			return;
		case -2:
			sub_07A12B(u);
			return;
		}
		break;
	}
	sub_07A384();
}

void sub_07A212(uint16_t u)
{
	uint16_t d = 0, ignored16 = 0;

	d = 0u;
	sub_0797B7(d);
	unk_487E = 3u;
	d = 0u;
	sub_07BAC7(d, &ignored16, &u);
	unk_48BE = 0xFFF0u;
	unk_48CE = 0xFFF0u;
	unk_487E = 1u;
	d = 0xF01u;
	sub_07BAC7(d, &ignored16, &u);
	unk_4809 = 0x40u;
	unk_4802++;
}

void sub_07A240(void)
{
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, u = 0;

	if (unk_485D != 0u)
		return;
	unk_4875 = 2u;
	unk_4876 = 0u;
	sub_07C931();
	io_write8(IO_1FB9, 0x3Fu);
	io_write8(IO_1FBA, 0x36u);
	d = 0x26u;
	sub_07C4A3(d, &ignored16, &ignored16_2, &ignored16_3);
	d = 0x126u;
	sub_07C4A3(d, &ignored16, &ignored16_2, &u);
	io_write8(IO_1FB9, 0x13u);
	io_write8(IO_1FBA, 0x2Cu);
	unk_487E = 3u;
	d = 0x7A53u;
	sub_07BAC7(d, &ignored16_2, &u);
	unk_4802++;
}

void sub_07A28C(uint16_t u)
{
	unk_480E = 0x11u;
	set_lines(unk_480E);
	switch ((int8_t)(uint8_t)((uint32_t)unk_4803 << 1))
	{
	case 0:
		sub_02250C();
		return;
	case 2:
		sub_02253C();
		return;
	case 4:
	case 10:
		sub_022564();
		return;
	case 6:
		sub_02252B();
		return;
	case 8:
		sub_0225E1();
		return;
	case 12:
		sub_022608(u);
		return;
	case 14:
		sub_02261F();
		return;
	}
}

void sub_07A29B(uint16_t u)
{
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0;

	unk_487E = 3u;
	d = 0u;
	sub_07BAC7(d, &ignored16, &u);
	sub_0792DD(&ignored16_2, &ignored16);
	unk_487E = 1u;
	d = 0xF00u;
	sub_07BAC7(d, &ignored16, &u);
	unk_48BE = 0u;
	unk_48CE = 0u;
	unk_4801++;
	unk_4802 = 0u;
	unk_4803 = 0u;
	unk_4804 = 0u;
	unk_4805 = 0u;
}

void sub_07A2CD(uint16_t y, uint16_t u)
{
	for (;;)
	{
		switch ((int8_t)(uint8_t)((uint32_t)unk_4802 << 1))
		{
		case 0:
			sub_07A2D6(u);
			return;
		case 2:
			sub_07A2EB();
			return;
		case 4:
			sub_07A314();
			return;
		case 6:
			sub_07A329(u);
			return;
		case 8:
			sub_07A357();
			return;
		case 10:
			sub_07A35F();
			return;
		case 12:
			break;
		case -40:
			sub_079EDA(y, u);
			return;
		case -38:
			sub_07A075(y, u);
			return;
		case -36:
			sub_079F36(y, u);
			return;
		case -34:
			sub_07A209(y, u);
			return;
		case -32:
			continue;
		case -30:
			sub_07A34E(y, u);
			return;
		case -28:
			sub_079EE3();
			return;
		case -26:
			sub_079EF6();
			return;
		case -24:
			sub_079F08(y, u);
			return;
		case -22:
			sub_079F17();
			return;
		case -20:
			sub_079F3F();
			return;
		case -18:
			sub_079F52(u);
			return;
		case -16:
			sub_07A007();
			return;
		case -14:
			sub_07A024();
			return;
		case -12:
			sub_07A07E();
			return;
		case -10:
			sub_07A12B(u);
			return;
		case -8:
			sub_07A212(u);
			return;
		case -6:
			sub_07A240();
			return;
		case -4:
			sub_07A28C(u);
			return;
		case -2:
			sub_07A29B(u);
			return;
		}
		break;
	}
	sub_07A384();
}

void sub_07A2D6(uint16_t u)
{
	sub_07A32E(u);
}

void unused_07A2D8(uint16_t u)
{
	uint16_t d = 0, ignored16 = 0;

	unk_487E = 1u;
	d = 0xF07u;
	sub_07BAC7(d, &ignored16, &u);
	d = 0u;
	sub_0797B7(d);
	unk_4802++;
}

void sub_07A2EB(void)
{
	uint16_t d = 0, ignored16 = 0, u = 0;

	if (unk_485D != 0u)
		return;
	d = 0u;
	sub_079311(d);
	d = 0x800Du;
	sub_079311(d);
	d = 0xEu;
	u = sub_079311(d);
	unk_487E = 3u;
	d = 0x6D6Bu;
	sub_07BAC7(d, &ignored16, &u);
	unk_4809 = 0u;
	unk_4802++;
}

void sub_07A314(void)
{
	uint16_t d = 0;
	uint8_t t1 = 0;

	t1 = unk_4809;
	unk_4809 = t1 - 1u;
	if (t1 != 1u)
		return;
	d = 0x8Eu;
	sub_079311(d);
	d = 0xFu;
	sub_079311(d);
	unk_4802++;
}

void sub_07A329(uint16_t u)
{
	uint8_t t1 = 0;

	t1 = unk_4809;
	unk_4809 = t1 - 1u;
	if (t1 != 1u)
		return;
	sub_07A32E(u);
}

void sub_07A32E(uint16_t u)
{
	uint16_t d = 0, ignored16 = 0;

	unk_487E = 3u;
	d = 0u;
	sub_07BAC7(d, &ignored16, &u);
	unk_4801++;
	unk_4802 = 0u;
	unk_4803 = 0u;
	unk_4804 = 0u;
	unk_4805 = 0u;
	unk_4801 = 0u;
}

void sub_07A34E(uint16_t y, uint16_t u)
{
	for (;;)
	{
		switch ((int8_t)(uint8_t)((uint32_t)unk_4802 << 1))
		{
		case 0:
			sub_07A357();
			return;
		case 2:
			sub_07A35F();
			return;
		case 4:
			break;
		case -48:
			sub_079EDA(y, u);
			return;
		case -46:
			sub_07A075(y, u);
			return;
		case -44:
			sub_079F36(y, u);
			return;
		case -42:
			sub_07A209(y, u);
			return;
		case -40:
			sub_07A2CD(y, u);
			return;
		case -38:
			continue;
		case -36:
			sub_079EE3();
			return;
		case -34:
			sub_079EF6();
			return;
		case -32:
			sub_079F08(y, u);
			return;
		case -30:
			sub_079F17();
			return;
		case -28:
			sub_079F3F();
			return;
		case -26:
			sub_079F52(u);
			return;
		case -24:
			sub_07A007();
			return;
		case -22:
			sub_07A024();
			return;
		case -20:
			sub_07A07E();
			return;
		case -18:
			sub_07A12B(u);
			return;
		case -16:
			sub_07A212(u);
			return;
		case -14:
			sub_07A240();
			return;
		case -12:
			sub_07A28C(u);
			return;
		case -10:
			sub_07A29B(u);
			return;
		case -8:
			sub_07A2D6(u);
			return;
		case -6:
			sub_07A2EB();
			return;
		case -4:
			sub_07A314();
			return;
		case -2:
			sub_07A329(u);
			return;
		}
		break;
	}
	sub_07A384();
}

void sub_07A357(void)
{
	uint16_t d = 0;

	d = 0u;
	sub_0797B7(d);
	unk_4802++;
}

void sub_07A35F(void)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, u = 0;
	uint8_t t1 = 0;

	if (unk_485D != 0u)
		return;
	sub_079692();
	t1 = io_read8(VIDEO_1C80);
	io_write8(VIDEO_1C80, 0u);
	d = 0u;
	carry = sub_0797D3(d);
	sub_07955F(&ignored16, &u);
	sub_079F58(u);
	unk_48BE = 0xFF80u;
	unk_48CE = 0x80u;
}

void sub_07A384(void)
{
	uint8_t b = 0;
	uint16_t d = 0;

	b = 0u;
	if ((unk_4815 & 0x20u) != 0u)
		b = 0x80u;
	d = 0x8000u | (uint8_t)(b + 0x12u);
	sub_079311(d);
}

void sub_07A396(uint16_t u)
{
	uint16_t y = 0;
	uint32_t left_caller = 0;

	sub_079548();
	unk_486A = 1u;
	unk_480E = 0x20u;
	set_lines(unk_480E);
	y = sub_04000F();
	sub_07BA34();
	left_caller = 0u;
	switch ((int8_t)(uint8_t)((uint32_t)unk_4802 << 1))
	{
	case 0:
		left_caller = sub_07A3C0(y, u);
		break;
	case 2:
		left_caller = sub_07A415(y, u);
		break;
	case 4:
		sub_07B458();
		break;
	case 6:
		left_caller = sub_07B464(y, u, left_caller);
		break;
	case 8:
		left_caller = sub_07B4F5(y, u, left_caller);
		break;
	case 10:
		sub_07A3CC();
		break;
	case 12:
		sub_07A3EB(u);
		break;
	case 14:
		left_caller = sub_07A41E(y, u);
		break;
	case 16:
		left_caller = sub_07A4CE(y, u);
		break;
	case 18:
		left_caller = sub_07A52E(y, u);
		break;
	case 20:
		left_caller = sub_07A656(y, u);
		break;
	case 22:
		left_caller = sub_07A76D(y, u);
		break;
	case 24:
		sub_07A8AE();
		break;
	case 26:
		left_caller = sub_07A8B8(y, u);
		break;
	case 28:
		left_caller = sub_07AA0C(y, u);
		break;
	case 30:
		left_caller = sub_07AB4F(y, u);
		break;
	case 32:
		left_caller = sub_07AC74(y, u);
		break;
	case 34:
		sub_07ADC4();
		break;
	case 36:
		left_caller = sub_07ADD2(y, u);
		break;
	case 38:
		left_caller = sub_07AF20(y, u);
		break;
	case 40:
		left_caller = sub_07B068(y, u);
		break;
	case 42:
		sub_07B1D4();
		break;
	case 44:
		left_caller = sub_07B1DE(y, u);
		break;
	case 46:
		left_caller = sub_07B40A(y, u);
		break;
	case 48:
		sub_07A427(u);
		break;
	case 50:
		sub_07A460(u);
		break;
	case 52:
		sub_07A4A5(u);
		break;
	case 54:
		sub_07A4DA();
		break;
	case 56:
		sub_07A4EA();
		break;
	case 58:
		sub_07A4F4(u);
		break;
	case 60:
		sub_07A537();
		break;
	case 62:
		sub_07A563(u);
		break;
	case 64:
		left_caller = sub_07A572(u, left_caller);
		break;
	case 66:
		sub_07A5E0();
		break;
	case 68:
		left_caller = sub_07A5E3(y, left_caller);
		break;
	case 70:
		sub_07A5F5();
		break;
	case 72:
		left_caller = sub_07A5F8(left_caller);
		break;
	case 74:
		left_caller = sub_07A5FB(y, u, left_caller);
		break;
	case 76:
		sub_07A662();
		break;
	case 78:
		sub_07A689();
		break;
	case 80:
		sub_07A6CC(y);
		break;
	case 82:
		sub_07A748(y);
		break;
	case 84:
		sub_07A75B();
		break;
	case 86:
		sub_07A776();
		break;
	case 88:
		sub_07A7A2(u);
		break;
	case 90:
		left_caller = sub_07A7B1(u, left_caller);
		break;
	case 92:
		sub_07A81F();
		break;
	case 94:
		left_caller = sub_07A822(y, left_caller);
		break;
	case 96:
		sub_07A834();
		break;
	case 98:
		sub_07A851();
		break;
	case 100:
		sub_07A876(u);
		break;
	case 102:
		sub_07A8C1();
		break;
	case 104:
		sub_07A8ED(u);
		break;
	case 106:
		left_caller = sub_07A8FC(u, left_caller);
		break;
	case 108:
		sub_07A975();
		break;
	case 110:
		left_caller = sub_07A978(y, left_caller);
		break;
	case 112:
		left_caller = sub_07A99B(y, left_caller);
		break;
	case 114:
		sub_07A9C2();
		break;
	case 116:
		left_caller = sub_07A9D2(left_caller);
		break;
	case 118:
		left_caller = sub_07A9DB();
		break;
	case 120:
		sub_07AA15();
		break;
	case 122:
		left_caller = sub_07AA3E(u, left_caller);
		break;
	case 124:
		sub_07AAEE();
		break;
	case 126:
		left_caller = sub_07AAF1(y, left_caller);
		break;
	}
	if (left_caller != 0u)
		return;
	sub_07BA50();
	unk_4811 = 0u;
}

uint32_t sub_07A3C0(uint16_t y, uint16_t u)
{
	uint32_t left_caller = 0;

	for (;;)
	{
		unk_486A = 0u;
		switch ((int8_t)(uint8_t)((uint32_t)unk_4803 << 1))
		{
		case 0:
			left_caller = 0u;
			sub_07A3CC();
			return left_caller;
		case 2:
			left_caller = 0u;
			sub_07A3EB(u);
			return left_caller;
		case 4:
			return sub_07A41E(y, u);
		case 6:
			return sub_07A4CE(y, u);
		case 8:
			return sub_07A52E(y, u);
		case 10:
			return sub_07A656(y, u);
		case 12:
			return sub_07A76D(y, u);
		case 14:
			left_caller = 0u;
			sub_07A8AE();
			return left_caller;
		case 16:
			return sub_07A8B8(y, u);
		case 18:
			return sub_07AA0C(y, u);
		case 20:
			return sub_07AB4F(y, u);
		case 22:
			return sub_07AC74(y, u);
		case 24:
			left_caller = 0u;
			sub_07ADC4();
			return left_caller;
		case 26:
			return sub_07ADD2(y, u);
		case 28:
			return sub_07AF20(y, u);
		case 30:
			return sub_07B068(y, u);
		case 32:
			left_caller = 0u;
			sub_07B1D4();
			return left_caller;
		case 34:
			return sub_07B1DE(y, u);
		case 36:
			return sub_07B40A(y, u);
		case 38:
			left_caller = 0u;
			sub_07A427(u);
			return left_caller;
		case 40:
			left_caller = 0u;
			sub_07A460(u);
			return left_caller;
		case 42:
			left_caller = 0u;
			sub_07A4A5(u);
			return left_caller;
		case 44:
			left_caller = 0u;
			sub_07A4DA();
			return left_caller;
		case 46:
			left_caller = 0u;
			sub_07A4EA();
			return left_caller;
		case 48:
			left_caller = 0u;
			sub_07A4F4(u);
			return left_caller;
		case 50:
			left_caller = 0u;
			sub_07A537();
			return left_caller;
		case 52:
			left_caller = 0u;
			sub_07A563(u);
			return left_caller;
		case 54:
			left_caller = 0u;
			return sub_07A572(u, left_caller);
		case 56:
			left_caller = 0u;
			sub_07A5E0();
			return left_caller;
		case 58:
			left_caller = 0u;
			return sub_07A5E3(y, left_caller);
		case 60:
			left_caller = 0u;
			sub_07A5F5();
			return left_caller;
		case 62:
			left_caller = 0u;
			return sub_07A5F8(left_caller);
		case 64:
			left_caller = 0u;
			return sub_07A5FB(y, u, left_caller);
		case 66:
			left_caller = 0u;
			sub_07A662();
			return left_caller;
		case 68:
			left_caller = 0u;
			sub_07A689();
			return left_caller;
		case 70:
			left_caller = 0u;
			sub_07A6CC(y);
			return left_caller;
		case 72:
			left_caller = 0u;
			sub_07A748(y);
			return left_caller;
		case 74:
			left_caller = 0u;
			sub_07A75B();
			return left_caller;
		case 76:
			left_caller = 0u;
			sub_07A776();
			return left_caller;
		case 78:
			left_caller = 0u;
			sub_07A7A2(u);
			return left_caller;
		case 80:
			left_caller = 0u;
			return sub_07A7B1(u, left_caller);
		case 82:
			left_caller = 0u;
			sub_07A81F();
			return left_caller;
		case 84:
			left_caller = 0u;
			return sub_07A822(y, left_caller);
		case 86:
			left_caller = 0u;
			sub_07A834();
			return left_caller;
		case 88:
			left_caller = 0u;
			sub_07A851();
			return left_caller;
		case 90:
			left_caller = 0u;
			sub_07A876(u);
			return left_caller;
		case 92:
			left_caller = 0u;
			sub_07A8C1();
			return left_caller;
		case 94:
			left_caller = 0u;
			sub_07A8ED(u);
			return left_caller;
		case 96:
			left_caller = 0u;
			return sub_07A8FC(u, left_caller);
		case 98:
			left_caller = 0u;
			sub_07A975();
			return left_caller;
		case 100:
			left_caller = 0u;
			return sub_07A978(y, left_caller);
		case 102:
			left_caller = 0u;
			return sub_07A99B(y, left_caller);
		case 104:
			left_caller = 0u;
			sub_07A9C2();
			return left_caller;
		case 106:
			left_caller = 0u;
			return sub_07A9D2(left_caller);
		case 108:
			return sub_07A9DB();
		case 110:
			left_caller = 0u;
			sub_07AA15();
			return left_caller;
		case 112:
			left_caller = 0u;
			return sub_07AA3E(u, left_caller);
		case 114:
			left_caller = 0u;
			sub_07AAEE();
			return left_caller;
		case 116:
			left_caller = 0u;
			return sub_07AAF1(y, left_caller);
		case 118:
			left_caller = 0u;
			sub_07AB03();
			return left_caller;
		case 120:
			left_caller = 0u;
			return sub_07AB06(left_caller);
		case 122:
			left_caller = 0u;
			return sub_07AB09(y, u, left_caller);
		case 124:
			left_caller = 0u;
			sub_07AB58();
			return left_caller;
		case 126:
			break;
		case -10:
			continue;
		case -8:
			return sub_07A415(y, u);
		case -6:
			left_caller = 0u;
			sub_07B458();
			return left_caller;
		case -4:
			left_caller = 0u;
			return sub_07B464(y, u, left_caller);
		case -2:
			left_caller = 0u;
			return sub_07B4F5(y, u, left_caller);
		}
		break;
	}
	left_caller = 0u;
	sub_07AB84(u);
	return left_caller;
}

void sub_07A3CC(void)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0;
	uint8_t t1 = 0;

	if (unk_485D != 0u)
		return;
	t1 = io_read8(VIDEO_1C80);
	io_write8(VIDEO_1C80, 0u);
	d = 0u;
	sub_0797B7(d);
	sub_0792DD(&ignored16, &ignored16_2);
	sub_079692();
	d = 0u;
	carry = sub_0797ED(d);
	unk_4803++;
}

void sub_07A3EB(uint16_t u)
{
	uint16_t d = 0, ignored16 = 0;

	if (unk_485D != 0u)
		return;
	unk_487E = 3u;
	d = 0u;
	sub_07BAC7(d, &ignored16, &u);
	unk_487E = 1u;
	d = 0xF00u;
	sub_07BAC7(d, &ignored16, &u);
	unk_4802++;
	unk_4803 = 0u;
	unk_4804 = 0u;
	unk_4805 = 0u;
}

uint32_t sub_07A415(uint16_t y, uint16_t u)
{
	uint32_t left_caller = 0;

	for (;;)
	{
		switch ((int8_t)(uint8_t)((uint32_t)unk_4803 << 1))
		{
		case 0:
			return sub_07A41E(y, u);
		case 2:
			return sub_07A4CE(y, u);
		case 4:
			return sub_07A52E(y, u);
		case 6:
			return sub_07A656(y, u);
		case 8:
			return sub_07A76D(y, u);
		case 10:
			left_caller = 0u;
			sub_07A8AE();
			return left_caller;
		case 12:
			return sub_07A8B8(y, u);
		case 14:
			return sub_07AA0C(y, u);
		case 16:
			return sub_07AB4F(y, u);
		case 18:
			return sub_07AC74(y, u);
		case 20:
			left_caller = 0u;
			sub_07ADC4();
			return left_caller;
		case 22:
			return sub_07ADD2(y, u);
		case 24:
			return sub_07AF20(y, u);
		case 26:
			return sub_07B068(y, u);
		case 28:
			left_caller = 0u;
			sub_07B1D4();
			return left_caller;
		case 30:
			return sub_07B1DE(y, u);
		case 32:
			return sub_07B40A(y, u);
		case 34:
			left_caller = 0u;
			sub_07A427(u);
			return left_caller;
		case 36:
			left_caller = 0u;
			sub_07A460(u);
			return left_caller;
		case 38:
			left_caller = 0u;
			sub_07A4A5(u);
			return left_caller;
		case 40:
			left_caller = 0u;
			sub_07A4DA();
			return left_caller;
		case 42:
			left_caller = 0u;
			sub_07A4EA();
			return left_caller;
		case 44:
			left_caller = 0u;
			sub_07A4F4(u);
			return left_caller;
		case 46:
			left_caller = 0u;
			sub_07A537();
			return left_caller;
		case 48:
			left_caller = 0u;
			sub_07A563(u);
			return left_caller;
		case 50:
			left_caller = 0u;
			return sub_07A572(u, left_caller);
		case 52:
			left_caller = 0u;
			sub_07A5E0();
			return left_caller;
		case 54:
			left_caller = 0u;
			return sub_07A5E3(y, left_caller);
		case 56:
			left_caller = 0u;
			sub_07A5F5();
			return left_caller;
		case 58:
			left_caller = 0u;
			return sub_07A5F8(left_caller);
		case 60:
			left_caller = 0u;
			return sub_07A5FB(y, u, left_caller);
		case 62:
			left_caller = 0u;
			sub_07A662();
			return left_caller;
		case 64:
			left_caller = 0u;
			sub_07A689();
			return left_caller;
		case 66:
			left_caller = 0u;
			sub_07A6CC(y);
			return left_caller;
		case 68:
			left_caller = 0u;
			sub_07A748(y);
			return left_caller;
		case 70:
			left_caller = 0u;
			sub_07A75B();
			return left_caller;
		case 72:
			left_caller = 0u;
			sub_07A776();
			return left_caller;
		case 74:
			left_caller = 0u;
			sub_07A7A2(u);
			return left_caller;
		case 76:
			left_caller = 0u;
			return sub_07A7B1(u, left_caller);
		case 78:
			left_caller = 0u;
			sub_07A81F();
			return left_caller;
		case 80:
			left_caller = 0u;
			return sub_07A822(y, left_caller);
		case 82:
			left_caller = 0u;
			sub_07A834();
			return left_caller;
		case 84:
			left_caller = 0u;
			sub_07A851();
			return left_caller;
		case 86:
			left_caller = 0u;
			sub_07A876(u);
			return left_caller;
		case 88:
			left_caller = 0u;
			sub_07A8C1();
			return left_caller;
		case 90:
			left_caller = 0u;
			sub_07A8ED(u);
			return left_caller;
		case 92:
			left_caller = 0u;
			return sub_07A8FC(u, left_caller);
		case 94:
			left_caller = 0u;
			sub_07A975();
			return left_caller;
		case 96:
			left_caller = 0u;
			return sub_07A978(y, left_caller);
		case 98:
			left_caller = 0u;
			return sub_07A99B(y, left_caller);
		case 100:
			left_caller = 0u;
			sub_07A9C2();
			return left_caller;
		case 102:
			left_caller = 0u;
			return sub_07A9D2(left_caller);
		case 104:
			return sub_07A9DB();
		case 106:
			left_caller = 0u;
			sub_07AA15();
			return left_caller;
		case 108:
			left_caller = 0u;
			return sub_07AA3E(u, left_caller);
		case 110:
			left_caller = 0u;
			sub_07AAEE();
			return left_caller;
		case 112:
			left_caller = 0u;
			return sub_07AAF1(y, left_caller);
		case 114:
			left_caller = 0u;
			sub_07AB03();
			return left_caller;
		case 116:
			left_caller = 0u;
			return sub_07AB06(left_caller);
		case 118:
			left_caller = 0u;
			return sub_07AB09(y, u, left_caller);
		case 120:
			left_caller = 0u;
			sub_07AB58();
			return left_caller;
		case 122:
			left_caller = 0u;
			sub_07AB84(u);
			return left_caller;
		case 124:
			left_caller = 0u;
			return sub_07AB93(u, left_caller);
		case 126:
			break;
		case -14:
			return sub_07A3C0(y, u);
		case -12:
			continue;
		case -10:
			left_caller = 0u;
			sub_07B458();
			return left_caller;
		case -8:
			left_caller = 0u;
			return sub_07B464(y, u, left_caller);
		case -6:
			left_caller = 0u;
			return sub_07B4F5(y, u, left_caller);
		case -4:
			left_caller = 0u;
			sub_07A3CC();
			return left_caller;
		case -2:
			left_caller = 0u;
			sub_07A3EB(u);
			return left_caller;
		}
		break;
	}
	left_caller = 0u;
	sub_07AC0C();
	return left_caller;
}

uint32_t sub_07A41E(uint16_t y, uint16_t u)
{
	uint32_t left_caller = 0;

	for (;;)
	{
		switch ((int8_t)(uint8_t)((uint32_t)unk_4804 << 1))
		{
		case 0:
			left_caller = 0u;
			sub_07A427(u);
			return left_caller;
		case 2:
			left_caller = 0u;
			sub_07A460(u);
			return left_caller;
		case 4:
			left_caller = 0u;
			sub_07A4A5(u);
			return left_caller;
		case 6:
			left_caller = 0u;
			sub_07A4DA();
			return left_caller;
		case 8:
			left_caller = 0u;
			sub_07A4EA();
			return left_caller;
		case 10:
			left_caller = 0u;
			sub_07A4F4(u);
			return left_caller;
		case 12:
			left_caller = 0u;
			sub_07A537();
			return left_caller;
		case 14:
			left_caller = 0u;
			sub_07A563(u);
			return left_caller;
		case 16:
			left_caller = 0u;
			return sub_07A572(u, left_caller);
		case 18:
			left_caller = 0u;
			sub_07A5E0();
			return left_caller;
		case 20:
			left_caller = 0u;
			return sub_07A5E3(y, left_caller);
		case 22:
			left_caller = 0u;
			sub_07A5F5();
			return left_caller;
		case 24:
			left_caller = 0u;
			return sub_07A5F8(left_caller);
		case 26:
			left_caller = 0u;
			return sub_07A5FB(y, u, left_caller);
		case 28:
			left_caller = 0u;
			sub_07A662();
			return left_caller;
		case 30:
			left_caller = 0u;
			sub_07A689();
			return left_caller;
		case 32:
			left_caller = 0u;
			sub_07A6CC(y);
			return left_caller;
		case 34:
			left_caller = 0u;
			sub_07A748(y);
			return left_caller;
		case 36:
			left_caller = 0u;
			sub_07A75B();
			return left_caller;
		case 38:
			left_caller = 0u;
			sub_07A776();
			return left_caller;
		case 40:
			left_caller = 0u;
			sub_07A7A2(u);
			return left_caller;
		case 42:
			left_caller = 0u;
			return sub_07A7B1(u, left_caller);
		case 44:
			left_caller = 0u;
			sub_07A81F();
			return left_caller;
		case 46:
			left_caller = 0u;
			return sub_07A822(y, left_caller);
		case 48:
			left_caller = 0u;
			sub_07A834();
			return left_caller;
		case 50:
			left_caller = 0u;
			sub_07A851();
			return left_caller;
		case 52:
			left_caller = 0u;
			sub_07A876(u);
			return left_caller;
		case 54:
			left_caller = 0u;
			sub_07A8C1();
			return left_caller;
		case 56:
			left_caller = 0u;
			sub_07A8ED(u);
			return left_caller;
		case 58:
			left_caller = 0u;
			return sub_07A8FC(u, left_caller);
		case 60:
			left_caller = 0u;
			sub_07A975();
			return left_caller;
		case 62:
			left_caller = 0u;
			return sub_07A978(y, left_caller);
		case 64:
			left_caller = 0u;
			return sub_07A99B(y, left_caller);
		case 66:
			left_caller = 0u;
			sub_07A9C2();
			return left_caller;
		case 68:
			left_caller = 0u;
			return sub_07A9D2(left_caller);
		case 70:
			return sub_07A9DB();
		case 72:
			left_caller = 0u;
			sub_07AA15();
			return left_caller;
		case 74:
			left_caller = 0u;
			return sub_07AA3E(u, left_caller);
		case 76:
			left_caller = 0u;
			sub_07AAEE();
			return left_caller;
		case 78:
			left_caller = 0u;
			return sub_07AAF1(y, left_caller);
		case 80:
			left_caller = 0u;
			sub_07AB03();
			return left_caller;
		case 82:
			left_caller = 0u;
			return sub_07AB06(left_caller);
		case 84:
			left_caller = 0u;
			return sub_07AB09(y, u, left_caller);
		case 86:
			left_caller = 0u;
			sub_07AB58();
			return left_caller;
		case 88:
			left_caller = 0u;
			sub_07AB84(u);
			return left_caller;
		case 90:
			left_caller = 0u;
			return sub_07AB93(u, left_caller);
		case 92:
			left_caller = 0u;
			sub_07AC0C();
			return left_caller;
		case 94:
			left_caller = 0u;
			return sub_07AC0F(y, left_caller);
		case 96:
			left_caller = 0u;
			sub_07AC21();
			return left_caller;
		case 98:
			left_caller = 0u;
			return sub_07AC24(left_caller);
		case 100:
			left_caller = 0u;
			return sub_07AC27(left_caller);
		case 102:
			left_caller = 0u;
			sub_07AC7D();
			return left_caller;
		case 104:
			left_caller = 0u;
			sub_07ACA9(u);
			return left_caller;
		case 106:
			left_caller = 0u;
			return sub_07ACB8(u, left_caller);
		case 108:
			left_caller = 0u;
			sub_07AD31();
			return left_caller;
		case 110:
			left_caller = 0u;
			return sub_07AD34(y, left_caller);
		case 112:
			left_caller = 0u;
			sub_07AD46();
			return left_caller;
		case 114:
			left_caller = 0u;
			return sub_07AD49(left_caller);
		case 116:
			left_caller = 0u;
			sub_07AD5B(u);
			return left_caller;
		case 118:
			left_caller = 0u;
			sub_07AD8F(u);
			return left_caller;
		case 120:
			left_caller = 0u;
			sub_07ADDB();
			return left_caller;
		case 122:
			left_caller = 0u;
			sub_07AE0B(u);
			return left_caller;
		case 124:
			left_caller = 0u;
			return sub_07AE1A(u, left_caller);
		case 126:
			break;
		case -48:
			return sub_07A3C0(y, u);
		case -46:
			return sub_07A415(y, u);
		case -44:
			left_caller = 0u;
			sub_07B458();
			return left_caller;
		case -42:
			left_caller = 0u;
			return sub_07B464(y, u, left_caller);
		case -40:
			left_caller = 0u;
			return sub_07B4F5(y, u, left_caller);
		case -38:
			left_caller = 0u;
			sub_07A3CC();
			return left_caller;
		case -36:
			left_caller = 0u;
			sub_07A3EB(u);
			return left_caller;
		case -34:
			continue;
		case -32:
			return sub_07A4CE(y, u);
		case -30:
			return sub_07A52E(y, u);
		case -28:
			return sub_07A656(y, u);
		case -26:
			return sub_07A76D(y, u);
		case -24:
			left_caller = 0u;
			sub_07A8AE();
			return left_caller;
		case -22:
			return sub_07A8B8(y, u);
		case -20:
			return sub_07AA0C(y, u);
		case -18:
			return sub_07AB4F(y, u);
		case -16:
			return sub_07AC74(y, u);
		case -14:
			left_caller = 0u;
			sub_07ADC4();
			return left_caller;
		case -12:
			return sub_07ADD2(y, u);
		case -10:
			return sub_07AF20(y, u);
		case -8:
			return sub_07B068(y, u);
		case -6:
			left_caller = 0u;
			sub_07B1D4();
			return left_caller;
		case -4:
			return sub_07B1DE(y, u);
		case -2:
			return sub_07B40A(y, u);
		}
		break;
	}
	left_caller = 0u;
	sub_07AE9D();
	return left_caller;
}

void sub_07A427(uint16_t u)
{
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0;

	sub_0792DD(&ignored16, &ignored16_2);
	d = 0u;
	sub_0797B7(d);
	unk_487E = 7u;
	d = 0x200u;
	sub_07BAC7(d, &ignored16_2, &u);
	unk_480E = 0x13u;
	set_lines(unk_480E);
	sub_02602A(u);
	d = 0xFFF0u;
	sub_07B632(d);
	d = 0u;
	sub_07B64C(d);
	AT16(unk_480B, -1) = 0x780u;
	unk_4804++;
}

void sub_07A460(uint16_t u)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, ignored16_4 = 0;
	uint16_t t1 = 0;

	if (unk_485D != 0u)
		return;
	t1 = AT16(unk_480B, -1);
	AT16(unk_480B, -1) = t1 - 1u;
	if (t1 == 1u)
	{
		unk_4842 = 0xA0u;
		unk_4846 = 0xA0u;
		unk_484A = 0xA0u;
		unk_484E = 0xA0u;
		sub_07B70D(&ignored16, &ignored16_2, &ignored16_3, &ignored16_4, &carry);
		sub_07A4B9();
		return;
	}
	unk_4872 = 0u;
	unk_480E = 0x2Fu;
	set_lines(unk_480E);
	sub_05E015(u);
	if (unk_4872 == 0u)
	{
		sub_07B70D(&ignored16, &ignored16_2, &ignored16_3, &ignored16_4, &carry);
		return;
	}
	if (unk_483B != 0u)
	{
		sub_07A4B9();
		return;
	}
	unk_480B = 0x40u;
	unk_4804++;
	sub_07B70D(&ignored16, &ignored16_2, &ignored16_3, &ignored16_4, &carry);
}

void sub_07A4A5(uint16_t u)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, ignored16_4 = 0;
	uint8_t t1 = 0;

	unk_480E = 0x2Fu;
	set_lines(unk_480E);
	sub_05E015(u);
	t1 = unk_480B;
	unk_480B = t1 - 1u;
	if (t1 != 1u)
	{
		sub_07B70D(&ignored16, &ignored16_2, &ignored16_3, &ignored16_4, &carry);
		return;
	}
	sub_07A4B9();
}

void sub_07A4B9(void)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, ignored16_4 = 0;

	AT16(unk_480B, -1) = 0u;
	unk_4803++;
	unk_4804 = 0u;
	unk_4805 = 0u;
	sub_07B70D(&ignored16, &ignored16_2, &ignored16_3, &ignored16_4, &carry);
}

uint32_t sub_07A4CE(uint16_t y, uint16_t u)
{
	uint32_t left_caller = 0;

	for (;;)
	{
		unk_486A = 0u;
		switch ((int8_t)(uint8_t)((uint32_t)unk_4804 << 1))
		{
		case 0:
			left_caller = 0u;
			sub_07A4DA();
			return left_caller;
		case 2:
			left_caller = 0u;
			sub_07A4EA();
			return left_caller;
		case 4:
			left_caller = 0u;
			sub_07A4F4(u);
			return left_caller;
		case 6:
			left_caller = 0u;
			sub_07A537();
			return left_caller;
		case 8:
			left_caller = 0u;
			sub_07A563(u);
			return left_caller;
		case 10:
			left_caller = 0u;
			return sub_07A572(u, left_caller);
		case 12:
			left_caller = 0u;
			sub_07A5E0();
			return left_caller;
		case 14:
			left_caller = 0u;
			return sub_07A5E3(y, left_caller);
		case 16:
			left_caller = 0u;
			sub_07A5F5();
			return left_caller;
		case 18:
			left_caller = 0u;
			return sub_07A5F8(left_caller);
		case 20:
			left_caller = 0u;
			return sub_07A5FB(y, u, left_caller);
		case 22:
			left_caller = 0u;
			sub_07A662();
			return left_caller;
		case 24:
			left_caller = 0u;
			sub_07A689();
			return left_caller;
		case 26:
			left_caller = 0u;
			sub_07A6CC(y);
			return left_caller;
		case 28:
			left_caller = 0u;
			sub_07A748(y);
			return left_caller;
		case 30:
			left_caller = 0u;
			sub_07A75B();
			return left_caller;
		case 32:
			left_caller = 0u;
			sub_07A776();
			return left_caller;
		case 34:
			left_caller = 0u;
			sub_07A7A2(u);
			return left_caller;
		case 36:
			left_caller = 0u;
			return sub_07A7B1(u, left_caller);
		case 38:
			left_caller = 0u;
			sub_07A81F();
			return left_caller;
		case 40:
			left_caller = 0u;
			return sub_07A822(y, left_caller);
		case 42:
			left_caller = 0u;
			sub_07A834();
			return left_caller;
		case 44:
			left_caller = 0u;
			sub_07A851();
			return left_caller;
		case 46:
			left_caller = 0u;
			sub_07A876(u);
			return left_caller;
		case 48:
			left_caller = 0u;
			sub_07A8C1();
			return left_caller;
		case 50:
			left_caller = 0u;
			sub_07A8ED(u);
			return left_caller;
		case 52:
			left_caller = 0u;
			return sub_07A8FC(u, left_caller);
		case 54:
			left_caller = 0u;
			sub_07A975();
			return left_caller;
		case 56:
			left_caller = 0u;
			return sub_07A978(y, left_caller);
		case 58:
			left_caller = 0u;
			return sub_07A99B(y, left_caller);
		case 60:
			left_caller = 0u;
			sub_07A9C2();
			return left_caller;
		case 62:
			left_caller = 0u;
			return sub_07A9D2(left_caller);
		case 64:
			return sub_07A9DB();
		case 66:
			left_caller = 0u;
			sub_07AA15();
			return left_caller;
		case 68:
			left_caller = 0u;
			return sub_07AA3E(u, left_caller);
		case 70:
			left_caller = 0u;
			sub_07AAEE();
			return left_caller;
		case 72:
			left_caller = 0u;
			return sub_07AAF1(y, left_caller);
		case 74:
			left_caller = 0u;
			sub_07AB03();
			return left_caller;
		case 76:
			left_caller = 0u;
			return sub_07AB06(left_caller);
		case 78:
			left_caller = 0u;
			return sub_07AB09(y, u, left_caller);
		case 80:
			left_caller = 0u;
			sub_07AB58();
			return left_caller;
		case 82:
			left_caller = 0u;
			sub_07AB84(u);
			return left_caller;
		case 84:
			left_caller = 0u;
			return sub_07AB93(u, left_caller);
		case 86:
			left_caller = 0u;
			sub_07AC0C();
			return left_caller;
		case 88:
			left_caller = 0u;
			return sub_07AC0F(y, left_caller);
		case 90:
			left_caller = 0u;
			sub_07AC21();
			return left_caller;
		case 92:
			left_caller = 0u;
			return sub_07AC24(left_caller);
		case 94:
			left_caller = 0u;
			return sub_07AC27(left_caller);
		case 96:
			left_caller = 0u;
			sub_07AC7D();
			return left_caller;
		case 98:
			left_caller = 0u;
			sub_07ACA9(u);
			return left_caller;
		case 100:
			left_caller = 0u;
			return sub_07ACB8(u, left_caller);
		case 102:
			left_caller = 0u;
			sub_07AD31();
			return left_caller;
		case 104:
			left_caller = 0u;
			return sub_07AD34(y, left_caller);
		case 106:
			left_caller = 0u;
			sub_07AD46();
			return left_caller;
		case 108:
			left_caller = 0u;
			return sub_07AD49(left_caller);
		case 110:
			left_caller = 0u;
			sub_07AD5B(u);
			return left_caller;
		case 112:
			left_caller = 0u;
			sub_07AD8F(u);
			return left_caller;
		case 114:
			left_caller = 0u;
			sub_07ADDB();
			return left_caller;
		case 116:
			left_caller = 0u;
			sub_07AE0B(u);
			return left_caller;
		case 118:
			left_caller = 0u;
			return sub_07AE1A(u, left_caller);
		case 120:
			left_caller = 0u;
			sub_07AE9D();
			return left_caller;
		case 122:
			left_caller = 0u;
			return sub_07AEA2(y, left_caller);
		case 124:
			left_caller = 0u;
			sub_07AEB4();
			return left_caller;
		case 126:
			break;
		case -54:
			return sub_07A3C0(y, u);
		case -52:
			return sub_07A415(y, u);
		case -50:
			left_caller = 0u;
			sub_07B458();
			return left_caller;
		case -48:
			left_caller = 0u;
			return sub_07B464(y, u, left_caller);
		case -46:
			left_caller = 0u;
			return sub_07B4F5(y, u, left_caller);
		case -44:
			left_caller = 0u;
			sub_07A3CC();
			return left_caller;
		case -42:
			left_caller = 0u;
			sub_07A3EB(u);
			return left_caller;
		case -40:
			return sub_07A41E(y, u);
		case -38:
			continue;
		case -36:
			return sub_07A52E(y, u);
		case -34:
			return sub_07A656(y, u);
		case -32:
			return sub_07A76D(y, u);
		case -30:
			left_caller = 0u;
			sub_07A8AE();
			return left_caller;
		case -28:
			return sub_07A8B8(y, u);
		case -26:
			return sub_07AA0C(y, u);
		case -24:
			return sub_07AB4F(y, u);
		case -22:
			return sub_07AC74(y, u);
		case -20:
			left_caller = 0u;
			sub_07ADC4();
			return left_caller;
		case -18:
			return sub_07ADD2(y, u);
		case -16:
			return sub_07AF20(y, u);
		case -14:
			return sub_07B068(y, u);
		case -12:
			left_caller = 0u;
			sub_07B1D4();
			return left_caller;
		case -10:
			return sub_07B1DE(y, u);
		case -8:
			return sub_07B40A(y, u);
		case -6:
			left_caller = 0u;
			sub_07A427(u);
			return left_caller;
		case -4:
			left_caller = 0u;
			sub_07A460(u);
			return left_caller;
		case -2:
			left_caller = 0u;
			sub_07A4A5(u);
			return left_caller;
		}
		break;
	}
	left_caller = 0u;
	return sub_07AEB9(left_caller);
}

void sub_07A4DA(void)
{
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0;

	sub_0792DD(&ignored16, &ignored16_2);
	sub_07960F();
	d = 0u;
	sub_0797B7(d);
	unk_4804++;
}

void sub_07A4EA(void)
{
	if (unk_485D == 0u)
		unk_4804++;
}

void sub_07A4F4(uint16_t u)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, ignored16_4 = 0;

	unk_4872 = 1u;
	unk_480E = 0x13u;
	set_lines(unk_480E);
	u = sub_026009(u);
	unk_480E = 0x13u;
	set_lines(unk_480E);
	sub_02602D(u);
	if (unk_4872 == 0u)
	{
		unk_4803++;
		unk_4804 = 0u;
		unk_4805 = 0u;
	}
	sub_07B70D(&ignored16, &ignored16_2, &ignored16_3, &ignored16_4, &carry);
}

uint32_t sub_07A52E(uint16_t y, uint16_t u)
{
	uint32_t left_caller = 0;

	for (;;)
	{
		switch ((int8_t)(uint8_t)((uint32_t)unk_4804 << 1))
		{
		case 0:
			left_caller = 0u;
			sub_07A537();
			return left_caller;
		case 2:
			left_caller = 0u;
			sub_07A563(u);
			return left_caller;
		case 4:
			left_caller = 0u;
			return sub_07A572(u, left_caller);
		case 6:
			left_caller = 0u;
			sub_07A5E0();
			return left_caller;
		case 8:
			left_caller = 0u;
			return sub_07A5E3(y, left_caller);
		case 10:
			left_caller = 0u;
			sub_07A5F5();
			return left_caller;
		case 12:
			left_caller = 0u;
			return sub_07A5F8(left_caller);
		case 14:
			left_caller = 0u;
			return sub_07A5FB(y, u, left_caller);
		case 16:
			left_caller = 0u;
			sub_07A662();
			return left_caller;
		case 18:
			left_caller = 0u;
			sub_07A689();
			return left_caller;
		case 20:
			left_caller = 0u;
			sub_07A6CC(y);
			return left_caller;
		case 22:
			left_caller = 0u;
			sub_07A748(y);
			return left_caller;
		case 24:
			left_caller = 0u;
			sub_07A75B();
			return left_caller;
		case 26:
			left_caller = 0u;
			sub_07A776();
			return left_caller;
		case 28:
			left_caller = 0u;
			sub_07A7A2(u);
			return left_caller;
		case 30:
			left_caller = 0u;
			return sub_07A7B1(u, left_caller);
		case 32:
			left_caller = 0u;
			sub_07A81F();
			return left_caller;
		case 34:
			left_caller = 0u;
			return sub_07A822(y, left_caller);
		case 36:
			left_caller = 0u;
			sub_07A834();
			return left_caller;
		case 38:
			left_caller = 0u;
			sub_07A851();
			return left_caller;
		case 40:
			left_caller = 0u;
			sub_07A876(u);
			return left_caller;
		case 42:
			left_caller = 0u;
			sub_07A8C1();
			return left_caller;
		case 44:
			left_caller = 0u;
			sub_07A8ED(u);
			return left_caller;
		case 46:
			left_caller = 0u;
			return sub_07A8FC(u, left_caller);
		case 48:
			left_caller = 0u;
			sub_07A975();
			return left_caller;
		case 50:
			left_caller = 0u;
			return sub_07A978(y, left_caller);
		case 52:
			left_caller = 0u;
			return sub_07A99B(y, left_caller);
		case 54:
			left_caller = 0u;
			sub_07A9C2();
			return left_caller;
		case 56:
			left_caller = 0u;
			return sub_07A9D2(left_caller);
		case 58:
			return sub_07A9DB();
		case 60:
			left_caller = 0u;
			sub_07AA15();
			return left_caller;
		case 62:
			left_caller = 0u;
			return sub_07AA3E(u, left_caller);
		case 64:
			left_caller = 0u;
			sub_07AAEE();
			return left_caller;
		case 66:
			left_caller = 0u;
			return sub_07AAF1(y, left_caller);
		case 68:
			left_caller = 0u;
			sub_07AB03();
			return left_caller;
		case 70:
			left_caller = 0u;
			return sub_07AB06(left_caller);
		case 72:
			left_caller = 0u;
			return sub_07AB09(y, u, left_caller);
		case 74:
			left_caller = 0u;
			sub_07AB58();
			return left_caller;
		case 76:
			left_caller = 0u;
			sub_07AB84(u);
			return left_caller;
		case 78:
			left_caller = 0u;
			return sub_07AB93(u, left_caller);
		case 80:
			left_caller = 0u;
			sub_07AC0C();
			return left_caller;
		case 82:
			left_caller = 0u;
			return sub_07AC0F(y, left_caller);
		case 84:
			left_caller = 0u;
			sub_07AC21();
			return left_caller;
		case 86:
			left_caller = 0u;
			return sub_07AC24(left_caller);
		case 88:
			left_caller = 0u;
			return sub_07AC27(left_caller);
		case 90:
			left_caller = 0u;
			sub_07AC7D();
			return left_caller;
		case 92:
			left_caller = 0u;
			sub_07ACA9(u);
			return left_caller;
		case 94:
			left_caller = 0u;
			return sub_07ACB8(u, left_caller);
		case 96:
			left_caller = 0u;
			sub_07AD31();
			return left_caller;
		case 98:
			left_caller = 0u;
			return sub_07AD34(y, left_caller);
		case 100:
			left_caller = 0u;
			sub_07AD46();
			return left_caller;
		case 102:
			left_caller = 0u;
			return sub_07AD49(left_caller);
		case 104:
			left_caller = 0u;
			sub_07AD5B(u);
			return left_caller;
		case 106:
			left_caller = 0u;
			sub_07AD8F(u);
			return left_caller;
		case 108:
			left_caller = 0u;
			sub_07ADDB();
			return left_caller;
		case 110:
			left_caller = 0u;
			sub_07AE0B(u);
			return left_caller;
		case 112:
			left_caller = 0u;
			return sub_07AE1A(u, left_caller);
		case 114:
			left_caller = 0u;
			sub_07AE9D();
			return left_caller;
		case 116:
			left_caller = 0u;
			return sub_07AEA2(y, left_caller);
		case 118:
			left_caller = 0u;
			sub_07AEB4();
			return left_caller;
		case 120:
			left_caller = 0u;
			return sub_07AEB9(left_caller);
		case 122:
			left_caller = 0u;
			sub_07AEBE(u);
			return left_caller;
		case 124:
			left_caller = 0u;
			sub_07AEEE(u);
			return left_caller;
		case 126:
			break;
		case -60:
			return sub_07A3C0(y, u);
		case -58:
			return sub_07A415(y, u);
		case -56:
			left_caller = 0u;
			sub_07B458();
			return left_caller;
		case -54:
			left_caller = 0u;
			return sub_07B464(y, u, left_caller);
		case -52:
			left_caller = 0u;
			return sub_07B4F5(y, u, left_caller);
		case -50:
			left_caller = 0u;
			sub_07A3CC();
			return left_caller;
		case -48:
			left_caller = 0u;
			sub_07A3EB(u);
			return left_caller;
		case -46:
			return sub_07A41E(y, u);
		case -44:
			return sub_07A4CE(y, u);
		case -42:
			continue;
		case -40:
			return sub_07A656(y, u);
		case -38:
			return sub_07A76D(y, u);
		case -36:
			left_caller = 0u;
			sub_07A8AE();
			return left_caller;
		case -34:
			return sub_07A8B8(y, u);
		case -32:
			return sub_07AA0C(y, u);
		case -30:
			return sub_07AB4F(y, u);
		case -28:
			return sub_07AC74(y, u);
		case -26:
			left_caller = 0u;
			sub_07ADC4();
			return left_caller;
		case -24:
			return sub_07ADD2(y, u);
		case -22:
			return sub_07AF20(y, u);
		case -20:
			return sub_07B068(y, u);
		case -18:
			left_caller = 0u;
			sub_07B1D4();
			return left_caller;
		case -16:
			return sub_07B1DE(y, u);
		case -14:
			return sub_07B40A(y, u);
		case -12:
			left_caller = 0u;
			sub_07A427(u);
			return left_caller;
		case -10:
			left_caller = 0u;
			sub_07A460(u);
			return left_caller;
		case -8:
			left_caller = 0u;
			sub_07A4A5(u);
			return left_caller;
		case -6:
			left_caller = 0u;
			sub_07A4DA();
			return left_caller;
		case -4:
			left_caller = 0u;
			sub_07A4EA();
			return left_caller;
		case -2:
			left_caller = 0u;
			sub_07A4F4(u);
			return left_caller;
		}
		break;
	}
	left_caller = 0u;
	sub_07AF2C();
	return left_caller;
}

void sub_07A537(void)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0;

	unk_486A = 0u;
	sub_0792DD(&ignored16, &ignored16_2);
	sub_07960F();
	d = 0u;
	carry = sub_0797D3(d);
	sub_079269();
	unk_480E = 0x13u;
	set_lines(unk_480E);
	unk_48A4 = stage_slots[0].record;
	sub_07BA87();
	unk_4804++;
}

void sub_07A563(uint16_t u)
{
	unk_480E = 0x13u;
	set_lines(unk_480E);
	sub_026006(u);
}

uint32_t sub_07A572(uint16_t u, uint32_t left_caller)
{
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, y = 0;

	unk_487E = 1u;
	d = 0xF81u;
	sub_07BAC7(d, &ignored16, &u);
	d = 0u;
	sub_07B632(d);
	d = 0x10u;
	sub_07B64C(d);
	sub_07BA93();
	io_write8(IO_1FB9, 0x3Fu);
	io_write8(IO_1FBA, 0x36u);
	unk_4875 = 0x82u;
	unk_4876 = 0u;
	sub_07C931();
	d = 0x2Cu;
	sub_07C4A3(d, &ignored16_2, &ignored16, &ignored16_3);
	d = 0x12Cu;
	sub_07C4E1(d, &y, &ignored16_3);
	left_caller = sub_07C954(y, left_caller);
	unk_480E = 0x1Fu;
	set_lines(unk_480E);
	sub_03E057(&ignored16_2, &ignored16, &ignored16_3);
	io_write8(IO_1FB9, 0x13u);
	io_write8(IO_1FBA, 0x2Cu);
	unk_4885 = unk_4850;
	unk_4804++;
	return left_caller;
}

void sub_07A5E0(void)
{
	sub_07B5A9();
}

uint32_t sub_07A5E3(uint16_t y, uint32_t left_caller)
{
	uint16_t ignored16 = 0;

	sub_07B5DD(y, &ignored16, &left_caller);
	if (unk_487C != 0u)
	{
		unk_487C = 0u;
		unk_4880++;
		sub_07BA93();
	}
	return left_caller;
}

void sub_07A5F5(void)
{
	sub_07B666();
}

uint32_t sub_07A5F8(uint32_t left_caller)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;

	sub_07B676(&ignored16, &left_caller, &carry);
	return left_caller;
}

uint32_t sub_07A5FB(uint16_t y, uint16_t u, uint32_t left_caller)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, ignored16_4 = 0, u_2 = 0;

	sub_07CB9F(&y, &u, &left_caller);
	u = sub_07CBD2(u);
	unk_480E = 0x1Fu;
	set_lines(unk_480E);
	u = sub_03E000(u);
	unk_4872 = 1u;
	unk_480E = 0x12u;
	set_lines(unk_480E);
	sub_024000(u);
	if (unk_4872 != 0u)
	{
		sub_07C016(&u_2, &ignored16_3);
		unk_480E = 0x13u;
		set_lines(unk_480E);
		sub_026009(u_2);
		sub_07B70D(&ignored16, &ignored16_2, &ignored16_4, &ignored16_3, &carry);
		return left_caller;
	}
	d = 0u;
	carry = sub_0797ED(d);
	sub_0792DD(&ignored16, &ignored16_2);
	unk_4803++;
	unk_4804 = 0u;
	unk_4805 = 0u;
	sub_07C016(&u_2, &ignored16_3);
	unk_480E = 0x13u;
	set_lines(unk_480E);
	sub_026009(u_2);
	sub_07B70D(&ignored16, &ignored16_2, &ignored16_4, &ignored16_3, &carry);
	return left_caller;
}

uint32_t sub_07A656(uint16_t y, uint16_t u)
{
	uint32_t left_caller = 0;

	for (;;)
	{
		unk_486A = 0u;
		switch ((int8_t)(uint8_t)((uint32_t)unk_4804 << 1))
		{
		case 0:
			left_caller = 0u;
			sub_07A662();
			return left_caller;
		case 2:
			left_caller = 0u;
			sub_07A689();
			return left_caller;
		case 4:
			left_caller = 0u;
			sub_07A6CC(y);
			return left_caller;
		case 6:
			left_caller = 0u;
			sub_07A748(y);
			return left_caller;
		case 8:
			left_caller = 0u;
			sub_07A75B();
			return left_caller;
		case 10:
			left_caller = 0u;
			sub_07A776();
			return left_caller;
		case 12:
			left_caller = 0u;
			sub_07A7A2(u);
			return left_caller;
		case 14:
			left_caller = 0u;
			return sub_07A7B1(u, left_caller);
		case 16:
			left_caller = 0u;
			sub_07A81F();
			return left_caller;
		case 18:
			left_caller = 0u;
			return sub_07A822(y, left_caller);
		case 20:
			left_caller = 0u;
			sub_07A834();
			return left_caller;
		case 22:
			left_caller = 0u;
			sub_07A851();
			return left_caller;
		case 24:
			left_caller = 0u;
			sub_07A876(u);
			return left_caller;
		case 26:
			left_caller = 0u;
			sub_07A8C1();
			return left_caller;
		case 28:
			left_caller = 0u;
			sub_07A8ED(u);
			return left_caller;
		case 30:
			left_caller = 0u;
			return sub_07A8FC(u, left_caller);
		case 32:
			left_caller = 0u;
			sub_07A975();
			return left_caller;
		case 34:
			left_caller = 0u;
			return sub_07A978(y, left_caller);
		case 36:
			left_caller = 0u;
			return sub_07A99B(y, left_caller);
		case 38:
			left_caller = 0u;
			sub_07A9C2();
			return left_caller;
		case 40:
			left_caller = 0u;
			return sub_07A9D2(left_caller);
		case 42:
			return sub_07A9DB();
		case 44:
			left_caller = 0u;
			sub_07AA15();
			return left_caller;
		case 46:
			left_caller = 0u;
			return sub_07AA3E(u, left_caller);
		case 48:
			left_caller = 0u;
			sub_07AAEE();
			return left_caller;
		case 50:
			left_caller = 0u;
			return sub_07AAF1(y, left_caller);
		case 52:
			left_caller = 0u;
			sub_07AB03();
			return left_caller;
		case 54:
			left_caller = 0u;
			return sub_07AB06(left_caller);
		case 56:
			left_caller = 0u;
			return sub_07AB09(y, u, left_caller);
		case 58:
			left_caller = 0u;
			sub_07AB58();
			return left_caller;
		case 60:
			left_caller = 0u;
			sub_07AB84(u);
			return left_caller;
		case 62:
			left_caller = 0u;
			return sub_07AB93(u, left_caller);
		case 64:
			left_caller = 0u;
			sub_07AC0C();
			return left_caller;
		case 66:
			left_caller = 0u;
			return sub_07AC0F(y, left_caller);
		case 68:
			left_caller = 0u;
			sub_07AC21();
			return left_caller;
		case 70:
			left_caller = 0u;
			return sub_07AC24(left_caller);
		case 72:
			left_caller = 0u;
			return sub_07AC27(left_caller);
		case 74:
			left_caller = 0u;
			sub_07AC7D();
			return left_caller;
		case 76:
			left_caller = 0u;
			sub_07ACA9(u);
			return left_caller;
		case 78:
			left_caller = 0u;
			return sub_07ACB8(u, left_caller);
		case 80:
			left_caller = 0u;
			sub_07AD31();
			return left_caller;
		case 82:
			left_caller = 0u;
			return sub_07AD34(y, left_caller);
		case 84:
			left_caller = 0u;
			sub_07AD46();
			return left_caller;
		case 86:
			left_caller = 0u;
			return sub_07AD49(left_caller);
		case 88:
			left_caller = 0u;
			sub_07AD5B(u);
			return left_caller;
		case 90:
			left_caller = 0u;
			sub_07AD8F(u);
			return left_caller;
		case 92:
			left_caller = 0u;
			sub_07ADDB();
			return left_caller;
		case 94:
			left_caller = 0u;
			sub_07AE0B(u);
			return left_caller;
		case 96:
			left_caller = 0u;
			return sub_07AE1A(u, left_caller);
		case 98:
			left_caller = 0u;
			sub_07AE9D();
			return left_caller;
		case 100:
			left_caller = 0u;
			return sub_07AEA2(y, left_caller);
		case 102:
			left_caller = 0u;
			sub_07AEB4();
			return left_caller;
		case 104:
			left_caller = 0u;
			return sub_07AEB9(left_caller);
		case 106:
			left_caller = 0u;
			sub_07AEBE(u);
			return left_caller;
		case 108:
			left_caller = 0u;
			sub_07AEEE(u);
			return left_caller;
		case 110:
			left_caller = 0u;
			sub_07AF2C();
			return left_caller;
		case 112:
			left_caller = 0u;
			sub_07AF5A();
			return left_caller;
		case 114:
			left_caller = 0u;
			sub_07AF97(y);
			return left_caller;
		case 116:
			left_caller = 0u;
			sub_07B00F(y);
			return left_caller;
		case 118:
			left_caller = 0u;
			sub_07B022();
			return left_caller;
		case 120:
			left_caller = 0u;
			sub_07B039(u);
			return left_caller;
		case 122:
			left_caller = 0u;
			sub_07B071();
			return left_caller;
		case 124:
			left_caller = 0u;
			sub_07B09D(u);
			return left_caller;
		case 126:
			break;
		case -76:
			return sub_07A3C0(y, u);
		case -74:
			return sub_07A415(y, u);
		case -72:
			left_caller = 0u;
			sub_07B458();
			return left_caller;
		case -70:
			left_caller = 0u;
			return sub_07B464(y, u, left_caller);
		case -68:
			left_caller = 0u;
			return sub_07B4F5(y, u, left_caller);
		case -66:
			left_caller = 0u;
			sub_07A3CC();
			return left_caller;
		case -64:
			left_caller = 0u;
			sub_07A3EB(u);
			return left_caller;
		case -62:
			return sub_07A41E(y, u);
		case -60:
			return sub_07A4CE(y, u);
		case -58:
			return sub_07A52E(y, u);
		case -56:
			continue;
		case -54:
			return sub_07A76D(y, u);
		case -52:
			left_caller = 0u;
			sub_07A8AE();
			return left_caller;
		case -50:
			return sub_07A8B8(y, u);
		case -48:
			return sub_07AA0C(y, u);
		case -46:
			return sub_07AB4F(y, u);
		case -44:
			return sub_07AC74(y, u);
		case -42:
			left_caller = 0u;
			sub_07ADC4();
			return left_caller;
		case -40:
			return sub_07ADD2(y, u);
		case -38:
			return sub_07AF20(y, u);
		case -36:
			return sub_07B068(y, u);
		case -34:
			left_caller = 0u;
			sub_07B1D4();
			return left_caller;
		case -32:
			return sub_07B1DE(y, u);
		case -30:
			return sub_07B40A(y, u);
		case -28:
			left_caller = 0u;
			sub_07A427(u);
			return left_caller;
		case -26:
			left_caller = 0u;
			sub_07A460(u);
			return left_caller;
		case -24:
			left_caller = 0u;
			sub_07A4A5(u);
			return left_caller;
		case -22:
			left_caller = 0u;
			sub_07A4DA();
			return left_caller;
		case -20:
			left_caller = 0u;
			sub_07A4EA();
			return left_caller;
		case -18:
			left_caller = 0u;
			sub_07A4F4(u);
			return left_caller;
		case -16:
			left_caller = 0u;
			sub_07A537();
			return left_caller;
		case -14:
			left_caller = 0u;
			sub_07A563(u);
			return left_caller;
		case -12:
			left_caller = 0u;
			return sub_07A572(u, left_caller);
		case -10:
			left_caller = 0u;
			sub_07A5E0();
			return left_caller;
		case -8:
			left_caller = 0u;
			return sub_07A5E3(y, left_caller);
		case -6:
			left_caller = 0u;
			sub_07A5F5();
			return left_caller;
		case -4:
			left_caller = 0u;
			return sub_07A5F8(left_caller);
		case -2:
			left_caller = 0u;
			return sub_07A5FB(y, u, left_caller);
		}
		break;
	}
	left_caller = 0u;
	return sub_07B0AC(u, left_caller);
}

void sub_07A662(void)
{
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, u = 0;

	sub_0792DD(&ignored16, &ignored16_2);
	d = 0u;
	sub_0797B7(d);
	u = sub_07960F();
	unk_487E = 1u;
	d = 0xF82u;
	sub_07BAC7(d, &ignored16_2, &u);
	d = 0xFFF0u;
	sub_07B632(d);
	d = 0u;
	sub_07B64C(d);
	unk_4804++;
}

void sub_07A689(void)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0;

	if (unk_485D != 0u)
		return;
	d = 0x8700u;
	carry = sub_0797E3(d);
	unk_4875 = 0x83u;
	unk_4876 = 0u;
	sub_07C931();
	io_write8(IO_1FB9, 0x3Fu);
	io_write8(IO_1FBA, 0x36u);
	d = 0x26u;
	sub_07C4A3(d, &ignored16, &ignored16_2, &ignored16_3);
	d = 0x126u;
	sub_07C4A3(d, &ignored16, &ignored16_2, &ignored16_3);
	unk_48C5 = 0xFF30u;
	unk_480A = 1u;
	unk_480B = 0x80u;
	unk_4804++;
}

void sub_07A6CC(uint16_t y)
{
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, ignored16_4 = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;
	uint32_t unk_480A_halfword = 0;

	d = 0xD000u | b;
	sub_079784(d, &ignored16, &carry);
	if (carry == 0u)
	{
		io_write8(IO_1FB9, 0x13u);
		io_write8(IO_1FBA, 0x2Cu);
		t1 = (((uint32_t)unk_480A << 8u) | unk_480B);
		unk_480A_halfword = t1 - 1u;
		unk_480A = (uint8_t)(unk_480A_halfword >> 8u);
		unk_480B = (uint8_t)unk_480A_halfword;
		if (t1 != 1u)
		{
			unk_480E = 0x10u;
			set_lines(unk_480E);
			sub_020009(y);
			sub_07B70D(&ignored16, &ignored16_3, &ignored16_2, &ignored16_4, &carry);
			return;
		}
	}
	sub_07955F(&ignored16, &ignored16_2);
	io_write8(IO_1FB9, 0x3Fu);
	io_write8(IO_1FBA, 0x36u);
	sub_079275();
	d = 0xFFF0u;
	sub_07B632(d);
	d = 0u;
	sub_07B64C(d);
	unk_4876 = 1u;
	sub_07C931();
	d = 0x26u;
	sub_07C4A3(d, &ignored16, &ignored16_3, &ignored16_2);
	io_write8(IO_1FB9, 0x13u);
	io_write8(IO_1FBA, 0x2Cu);
	t2 = io_read8(VIDEO_18E0);
	io_write8(VIDEO_18E0, 0u);
	d = 0u;
	carry = sub_0797ED(d);
	unk_4804++;
}

void sub_07A748(uint16_t y)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, ignored16_4 = 0;

	unk_480E = 0x10u;
	set_lines(unk_480E);
	sub_020000(y);
	sub_07B70D(&ignored16, &ignored16_2, &ignored16_3, &ignored16_4, &carry);
}

void sub_07A75B(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0;

	sub_0792DD(&ignored16, &ignored16_2);
	unk_4803++;
	unk_4804 = 0u;
	unk_4805 = 0u;
}

uint32_t sub_07A76D(uint16_t y, uint16_t u)
{
	uint32_t left_caller = 0;

	switch ((int8_t)(uint8_t)((uint32_t)unk_4804 << 1))
	{
	case 0:
		left_caller = 0u;
		sub_07A776();
		return left_caller;
	case 2:
		left_caller = 0u;
		sub_07A7A2(u);
		return left_caller;
	case 4:
		left_caller = 0u;
		return sub_07A7B1(u, left_caller);
	case 6:
		left_caller = 0u;
		sub_07A81F();
		return left_caller;
	case 8:
		left_caller = 0u;
		return sub_07A822(y, left_caller);
	case 10:
		left_caller = 0u;
		sub_07A834();
		return left_caller;
	case 12:
		left_caller = 0u;
		sub_07A851();
		return left_caller;
	case 14:
		left_caller = 0u;
		sub_07A876(u);
		return left_caller;
	case 16:
		left_caller = 0u;
		sub_07A8C1();
		return left_caller;
	case 18:
		left_caller = 0u;
		sub_07A8ED(u);
		return left_caller;
	case 20:
		left_caller = 0u;
		return sub_07A8FC(u, left_caller);
	case 22:
		left_caller = 0u;
		sub_07A975();
		return left_caller;
	case 24:
		left_caller = 0u;
		return sub_07A978(y, left_caller);
	case 26:
		left_caller = 0u;
		return sub_07A99B(y, left_caller);
	case 28:
		left_caller = 0u;
		sub_07A9C2();
		return left_caller;
	case 30:
		left_caller = 0u;
		return sub_07A9D2(left_caller);
	case 32:
		return sub_07A9DB();
	case 34:
		left_caller = 0u;
		sub_07AA15();
		return left_caller;
	case 36:
		left_caller = 0u;
		return sub_07AA3E(u, left_caller);
	case 38:
		left_caller = 0u;
		sub_07AAEE();
		return left_caller;
	case 40:
		left_caller = 0u;
		return sub_07AAF1(y, left_caller);
	case 42:
		left_caller = 0u;
		sub_07AB03();
		return left_caller;
	case 44:
		left_caller = 0u;
		return sub_07AB06(left_caller);
	case 46:
		left_caller = 0u;
		return sub_07AB09(y, u, left_caller);
	case 48:
		left_caller = 0u;
		sub_07AB58();
		return left_caller;
	case 50:
		left_caller = 0u;
		sub_07AB84(u);
		return left_caller;
	case 52:
		left_caller = 0u;
		return sub_07AB93(u, left_caller);
	case 54:
		left_caller = 0u;
		sub_07AC0C();
		return left_caller;
	case 56:
		left_caller = 0u;
		return sub_07AC0F(y, left_caller);
	case 58:
		left_caller = 0u;
		sub_07AC21();
		return left_caller;
	case 60:
		left_caller = 0u;
		return sub_07AC24(left_caller);
	case 62:
		left_caller = 0u;
		return sub_07AC27(left_caller);
	case 64:
		left_caller = 0u;
		sub_07AC7D();
		return left_caller;
	case 66:
		left_caller = 0u;
		sub_07ACA9(u);
		return left_caller;
	case 68:
		left_caller = 0u;
		return sub_07ACB8(u, left_caller);
	case 70:
		left_caller = 0u;
		sub_07AD31();
		return left_caller;
	case 72:
		left_caller = 0u;
		return sub_07AD34(y, left_caller);
	case 74:
		left_caller = 0u;
		sub_07AD46();
		return left_caller;
	case 76:
		left_caller = 0u;
		return sub_07AD49(left_caller);
	case 78:
		left_caller = 0u;
		sub_07AD5B(u);
		return left_caller;
	case 80:
		left_caller = 0u;
		sub_07AD8F(u);
		return left_caller;
	case 82:
		left_caller = 0u;
		sub_07ADDB();
		return left_caller;
	case 84:
		left_caller = 0u;
		sub_07AE0B(u);
		return left_caller;
	case 86:
		left_caller = 0u;
		return sub_07AE1A(u, left_caller);
	case 88:
		left_caller = 0u;
		sub_07AE9D();
		return left_caller;
	case 90:
		left_caller = 0u;
		return sub_07AEA2(y, left_caller);
	case 92:
		left_caller = 0u;
		sub_07AEB4();
		return left_caller;
	case 94:
		left_caller = 0u;
		return sub_07AEB9(left_caller);
	case 96:
		left_caller = 0u;
		sub_07AEBE(u);
		return left_caller;
	case 98:
		left_caller = 0u;
		sub_07AEEE(u);
		return left_caller;
	case 100:
		left_caller = 0u;
		sub_07AF2C();
		return left_caller;
	case 102:
		left_caller = 0u;
		sub_07AF5A();
		return left_caller;
	case 104:
		left_caller = 0u;
		sub_07AF97(y);
		return left_caller;
	case 106:
		left_caller = 0u;
		sub_07B00F(y);
		return left_caller;
	case 108:
		left_caller = 0u;
		sub_07B022();
		return left_caller;
	case 110:
		left_caller = 0u;
		sub_07B039(u);
		return left_caller;
	case 112:
		left_caller = 0u;
		sub_07B071();
		return left_caller;
	case 114:
		left_caller = 0u;
		sub_07B09D(u);
		return left_caller;
	case 116:
		left_caller = 0u;
		return sub_07B0AC(u, left_caller);
	case 118:
		left_caller = 0u;
		sub_07B125();
		return left_caller;
	case 120:
		left_caller = 0u;
		return sub_07B128(y, left_caller);
	case 122:
		left_caller = 0u;
		sub_07B13A();
		return left_caller;
	case 124:
		left_caller = 0u;
		return sub_07B13D(left_caller);
	case 126:
		left_caller = 0u;
		return sub_07B14C(y, u, left_caller);
	}
	unreachable();
}

void sub_07A776(void)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0;

	unk_486A = 0u;
	sub_0792DD(&ignored16, &ignored16_2);
	sub_079269();
	sub_07960F();
	d = 0u;
	carry = sub_0797ED(d);
	unk_480E = 0x13u;
	set_lines(unk_480E);
	unk_48A4 = stage_slots[1].record;
	sub_07BA87();
	unk_4804++;
}

void sub_07A7A2(uint16_t u)
{
	unk_480E = 0x13u;
	set_lines(unk_480E);
	sub_026006(u);
}

uint32_t sub_07A7B1(uint16_t u, uint32_t left_caller)
{
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, y = 0;

	d = 0u;
	sub_07B632(d);
	d = 0u;
	sub_07B64C(d);
	unk_487E = 1u;
	d = 0xF83u;
	sub_07BAC7(d, &ignored16, &u);
	sub_07BA93();
	io_write8(IO_1FB9, 0x3Fu);
	io_write8(IO_1FBA, 0x36u);
	unk_4875 = 0x84u;
	unk_4876 = 0u;
	sub_07C931();
	d = 0x2Cu;
	sub_07C4A3(d, &ignored16_2, &ignored16, &ignored16_3);
	d = 0x12Cu;
	sub_07C4E1(d, &y, &ignored16_3);
	left_caller = sub_07C954(y, left_caller);
	unk_480E = 0x1Fu;
	set_lines(unk_480E);
	sub_03E057(&ignored16_2, &ignored16, &ignored16_3);
	io_write8(IO_1FB9, 0x13u);
	io_write8(IO_1FBA, 0x2Cu);
	unk_4885 = unk_4850;
	unk_4804++;
	return left_caller;
}

void sub_07A81F(void)
{
	sub_07B5A9();
}

uint32_t sub_07A822(uint16_t y, uint32_t left_caller)
{
	uint16_t ignored16 = 0;

	sub_07B5DD(y, &ignored16, &left_caller);
	if (unk_487C != 0u)
	{
		unk_487C = 0u;
		unk_4880++;
		sub_07BA93();
	}
	return left_caller;
}

void sub_07A834(void)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0;

	unk_48D3 = 0u - (unk_48AC - 0x680u);
	unk_4876 = 1u;
	d = 0x13Cu;
	sub_07C4A3(d, &ignored16, &ignored16_2, &ignored16_3);
	d = 0x4F00u;
	carry = sub_0797D3(d);
	sub_07B666();
}

void sub_07A851(void)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, ignored16_4 = 0;

	unk_4872 = 1u;
	unk_480E = 0x1Fu;
	set_lines(unk_480E);
	sub_03E009();
	if (unk_4872 == 0u)
	{
		unk_4872 = 1u;
		unk_4804++;
	}
	sub_07B70D(&ignored16, &ignored16_2, &ignored16_3, &ignored16_4, &carry);
}

void sub_07A876(uint16_t u)
{
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0;

	d = 0xF000u | b;
	sub_079784(d, &ignored16, &carry);
	if (carry)
	{
		d = 0u;
		carry = sub_0797ED(d);
		sub_0792DD(&ignored16, &ignored16_2);
		unk_4803++;
		unk_4804 = 0u;
		unk_4805 = 0u;
		return;
	}
	unk_4872 = 1u;
	unk_480E = 0x12u;
	set_lines(unk_480E);
	sub_024003(u);
	if (unk_4872 != 0u)
		return;
	d = 0u;
	carry = sub_0797ED(d);
	sub_0792DD(&ignored16, &ignored16_2);
	unk_4803++;
	unk_4804 = 0u;
	unk_4805 = 0u;
}

void sub_07A8AE(void)
{
	unk_486A = 0u;
	sub_07BA87();
	unk_4803++;
}

uint32_t sub_07A8B8(uint16_t y, uint16_t u)
{
	uint32_t left_caller = 0;

	switch ((int8_t)(uint8_t)((uint32_t)unk_4804 << 1))
	{
	case 0:
		left_caller = 0u;
		sub_07A8C1();
		return left_caller;
	case 2:
		left_caller = 0u;
		sub_07A8ED(u);
		return left_caller;
	case 4:
		left_caller = 0u;
		return sub_07A8FC(u, left_caller);
	case 6:
		left_caller = 0u;
		sub_07A975();
		return left_caller;
	case 8:
		left_caller = 0u;
		return sub_07A978(y, left_caller);
	case 10:
		left_caller = 0u;
		return sub_07A99B(y, left_caller);
	case 12:
		left_caller = 0u;
		sub_07A9C2();
		return left_caller;
	case 14:
		left_caller = 0u;
		return sub_07A9D2(left_caller);
	case 16:
		return sub_07A9DB();
	case 18:
		left_caller = 0u;
		sub_07AA15();
		return left_caller;
	case 20:
		left_caller = 0u;
		return sub_07AA3E(u, left_caller);
	case 22:
		left_caller = 0u;
		sub_07AAEE();
		return left_caller;
	case 24:
		left_caller = 0u;
		return sub_07AAF1(y, left_caller);
	case 26:
		left_caller = 0u;
		sub_07AB03();
		return left_caller;
	case 28:
		left_caller = 0u;
		return sub_07AB06(left_caller);
	case 30:
		left_caller = 0u;
		return sub_07AB09(y, u, left_caller);
	case 32:
		left_caller = 0u;
		sub_07AB58();
		return left_caller;
	case 34:
		left_caller = 0u;
		sub_07AB84(u);
		return left_caller;
	case 36:
		left_caller = 0u;
		return sub_07AB93(u, left_caller);
	case 38:
		left_caller = 0u;
		sub_07AC0C();
		return left_caller;
	case 40:
		left_caller = 0u;
		return sub_07AC0F(y, left_caller);
	case 42:
		left_caller = 0u;
		sub_07AC21();
		return left_caller;
	case 44:
		left_caller = 0u;
		return sub_07AC24(left_caller);
	case 46:
		left_caller = 0u;
		return sub_07AC27(left_caller);
	case 48:
		left_caller = 0u;
		sub_07AC7D();
		return left_caller;
	case 50:
		left_caller = 0u;
		sub_07ACA9(u);
		return left_caller;
	case 52:
		left_caller = 0u;
		return sub_07ACB8(u, left_caller);
	case 54:
		left_caller = 0u;
		sub_07AD31();
		return left_caller;
	case 56:
		left_caller = 0u;
		return sub_07AD34(y, left_caller);
	case 58:
		left_caller = 0u;
		sub_07AD46();
		return left_caller;
	case 60:
		left_caller = 0u;
		return sub_07AD49(left_caller);
	case 62:
		left_caller = 0u;
		sub_07AD5B(u);
		return left_caller;
	case 64:
		left_caller = 0u;
		sub_07AD8F(u);
		return left_caller;
	case 66:
		left_caller = 0u;
		sub_07ADDB();
		return left_caller;
	case 68:
		left_caller = 0u;
		sub_07AE0B(u);
		return left_caller;
	case 70:
		left_caller = 0u;
		return sub_07AE1A(u, left_caller);
	case 72:
		left_caller = 0u;
		sub_07AE9D();
		return left_caller;
	case 74:
		left_caller = 0u;
		return sub_07AEA2(y, left_caller);
	case 76:
		left_caller = 0u;
		sub_07AEB4();
		return left_caller;
	case 78:
		left_caller = 0u;
		return sub_07AEB9(left_caller);
	case 80:
		left_caller = 0u;
		sub_07AEBE(u);
		return left_caller;
	case 82:
		left_caller = 0u;
		sub_07AEEE(u);
		return left_caller;
	case 84:
		left_caller = 0u;
		sub_07AF2C();
		return left_caller;
	case 86:
		left_caller = 0u;
		sub_07AF5A();
		return left_caller;
	case 88:
		left_caller = 0u;
		sub_07AF97(y);
		return left_caller;
	case 90:
		left_caller = 0u;
		sub_07B00F(y);
		return left_caller;
	case 92:
		left_caller = 0u;
		sub_07B022();
		return left_caller;
	case 94:
		left_caller = 0u;
		sub_07B039(u);
		return left_caller;
	case 96:
		left_caller = 0u;
		sub_07B071();
		return left_caller;
	case 98:
		left_caller = 0u;
		sub_07B09D(u);
		return left_caller;
	case 100:
		left_caller = 0u;
		return sub_07B0AC(u, left_caller);
	case 102:
		left_caller = 0u;
		sub_07B125();
		return left_caller;
	case 104:
		left_caller = 0u;
		return sub_07B128(y, left_caller);
	case 106:
		left_caller = 0u;
		sub_07B13A();
		return left_caller;
	case 108:
		left_caller = 0u;
		return sub_07B13D(left_caller);
	case 110:
		left_caller = 0u;
		return sub_07B14C(y, u, left_caller);
	case 112:
		left_caller = 0u;
		return sub_07B19B(y, u, left_caller);
	case 114:
		left_caller = 0u;
		sub_07B1E7();
		return left_caller;
	case 116:
		left_caller = 0u;
		sub_07B219(u);
		return left_caller;
	case 118:
		left_caller = 0u;
		sub_07B228(u);
		return left_caller;
	case 120:
		left_caller = 0u;
		return sub_07B245(u, left_caller);
	case 122:
		left_caller = 0u;
		sub_07B2DB();
		return left_caller;
	case 124:
		left_caller = 0u;
		return sub_07B318(y, left_caller);
	case 126:
		left_caller = 0u;
		return sub_07B32A(left_caller);
	case -6:
		left_caller = 0u;
		sub_07A834();
		return left_caller;
	case -4:
		left_caller = 0u;
		sub_07A851();
		return left_caller;
	case -2:
		left_caller = 0u;
		sub_07A876(u);
		return left_caller;
	}
	unreachable();
}

void sub_07A8C1(void)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0;

	unk_486A = 0u;
	sub_0792DD(&ignored16, &ignored16_2);
	sub_079269();
	sub_07960F();
	d = 0u;
	carry = sub_0797ED(d);
	unk_480E = 0x13u;
	set_lines(unk_480E);
	unk_48A4 = stage_slots[3].record;
	sub_07BA87();
	unk_4804++;
}

void sub_07A8ED(uint16_t u)
{
	unk_480E = 0x13u;
	set_lines(unk_480E);
	sub_026006(u);
}

uint32_t sub_07A8FC(uint16_t u, uint32_t left_caller)
{
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, y = 0;

	d = 0u;
	sub_07B632(d);
	d = 0u;
	sub_07B64C(d);
	unk_487E = 1u;
	d = 0xF85u;
	sub_07BAC7(d, &ignored16, &u);
	unk_487E = 2u;
	d = 0u;
	sub_07BAC7(d, &ignored16, &u);
	sub_07BA93();
	io_write8(IO_1FB9, 0x3Fu);
	io_write8(IO_1FBA, 0x36u);
	unk_4875 = 0x86u;
	unk_4876 = 0u;
	sub_07C931();
	d = 0x2Cu;
	sub_07C4A3(d, &ignored16_2, &ignored16, &ignored16_3);
	d = 0x12Cu;
	sub_07C4E1(d, &y, &ignored16_3);
	left_caller = sub_07C954(y, left_caller);
	unk_480E = 0x1Fu;
	set_lines(unk_480E);
	sub_03E057(&ignored16_2, &ignored16, &ignored16_3);
	io_write8(IO_1FB9, 0x13u);
	io_write8(IO_1FBA, 0x2Cu);
	unk_4885 = unk_4850;
	unk_4804++;
	return left_caller;
}

void sub_07A975(void)
{
	sub_07B5A9();
}

uint32_t sub_07A978(uint16_t y, uint32_t left_caller)
{
	uint16_t d = 0, u = 0;

	sub_07B5DD(y, &u, &left_caller);
	if (unk_4881 == 0u)
		return left_caller;
	unk_4882 = 8u;
	unk_487E = 6u;
	d = 0xE08u;
	sub_07BAC7(d, &y, &u);
	d &= 0xFFu;
	sub_07C51C(d);
	sub_0795AF();
	unk_4804++;
	return left_caller;
}

uint32_t sub_07A99B(uint16_t y, uint32_t left_caller)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, ignored16_4 = 0;
	uint8_t t1 = 0;

	sub_07B5DD(y, &ignored16, &left_caller);
	if (unk_4881 != 0u)
	{
		t1 = unk_4882;
		unk_4882 = t1 - 1u;
		if (t1 != 1u)
		{
			if (unk_487D != 0u)
			{
				io_write8(VIDEO_184B, 1u);
				unk_4804++;
			}
			sub_07B70D(&ignored16_2, &ignored16_3, &ignored16, &ignored16_4, &carry);
			return left_caller;
		}
		d = loaded_table_078000_ADDRESS;
		sub_07C51C(d);
		unk_4881 = 0u;
	}
	if (unk_487D != 0u)
	{
		io_write8(VIDEO_184B, 1u);
		unk_4804++;
	}
	sub_07B70D(&ignored16_2, &ignored16_3, &ignored16, &ignored16_4, &carry);
	return left_caller;
}

void sub_07A9C2(void)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, ignored16_4 = 0;

	d = 0x9400u;
	carry = sub_0797E3(d);
	sub_07957F();
	unk_4804++;
	sub_07B70D(&ignored16, &ignored16_2, &ignored16_3, &ignored16_4, &carry);
}

uint32_t sub_07A9D2(uint32_t left_caller)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, ignored16_4 = 0;

	sub_07B676(&ignored16, &left_caller, &carry);
	sub_07C016(&ignored16, &ignored16_2);
	sub_07B70D(&ignored16_3, &ignored16_4, &ignored16, &ignored16_2, &carry);
	return left_caller;
}

uint32_t sub_07A9DB(void)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, ignored16_4 = 0;
	uint32_t ignored = 0, left_caller = 0;

	unk_4872 = 1u;
	sub_07CB9F(&ignored16, &ignored16_2, &ignored);
	sub_07CBD2(ignored16_2);
	sub_07CC05();
	if (unk_4872 != 0u)
	{
		sub_07C016(&ignored16_2, &ignored16_4);
		sub_07B70D(&ignored16_3, &ignored16, &ignored16_2, &ignored16_4, &carry);
		left_caller = 0u;
		return left_caller;
	}
	d = 0u;
	carry = sub_0797ED(d);
	sub_0792DD(&ignored16_3, &ignored16);
	unk_4803++;
	d = 0u;
	unk_4804 = 0u;
	sub_07AA00(&ignored16_3, &ignored16, &ignored16_2, &d, &left_caller, &carry);
	return left_caller;
}

void sub_07AA00(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u, uint16_t *p_d, uint32_t *p_left_caller, uint32_t *p_carry)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint16_t d_2 = 0, ignored16 = 0, u = 0, x = 0, y = 0;

	unk_4805 = d;
	sub_07C016(&ignored16, &d_2);
	*p_x = x;
	*p_y = y;
	*p_u = u;
	*p_d = d_2;
	sub_07B70D(p_x, p_y, p_u, p_d, &carry);
	*p_left_caller = 1u;
	*p_carry = carry;
}

uint32_t sub_07AA0C(uint16_t y, uint16_t u)
{
	uint32_t left_caller = 0;

	switch ((int8_t)(uint8_t)((uint32_t)unk_4804 << 1))
	{
	case 0:
		left_caller = 0u;
		sub_07AA15();
		return left_caller;
	case 2:
		left_caller = 0u;
		return sub_07AA3E(u, left_caller);
	case 4:
		left_caller = 0u;
		sub_07AAEE();
		return left_caller;
	case 6:
		left_caller = 0u;
		return sub_07AAF1(y, left_caller);
	case 8:
		left_caller = 0u;
		sub_07AB03();
		return left_caller;
	case 10:
		left_caller = 0u;
		return sub_07AB06(left_caller);
	case 12:
		left_caller = 0u;
		return sub_07AB09(y, u, left_caller);
	case 14:
		left_caller = 0u;
		sub_07AB58();
		return left_caller;
	case 16:
		left_caller = 0u;
		sub_07AB84(u);
		return left_caller;
	case 18:
		left_caller = 0u;
		return sub_07AB93(u, left_caller);
	case 20:
		left_caller = 0u;
		sub_07AC0C();
		return left_caller;
	case 22:
		left_caller = 0u;
		return sub_07AC0F(y, left_caller);
	case 24:
		left_caller = 0u;
		sub_07AC21();
		return left_caller;
	case 26:
		left_caller = 0u;
		return sub_07AC24(left_caller);
	case 28:
		left_caller = 0u;
		return sub_07AC27(left_caller);
	case 30:
		left_caller = 0u;
		sub_07AC7D();
		return left_caller;
	case 32:
		left_caller = 0u;
		sub_07ACA9(u);
		return left_caller;
	case 34:
		left_caller = 0u;
		return sub_07ACB8(u, left_caller);
	case 36:
		left_caller = 0u;
		sub_07AD31();
		return left_caller;
	case 38:
		left_caller = 0u;
		return sub_07AD34(y, left_caller);
	case 40:
		left_caller = 0u;
		sub_07AD46();
		return left_caller;
	case 42:
		left_caller = 0u;
		return sub_07AD49(left_caller);
	case 44:
		left_caller = 0u;
		sub_07AD5B(u);
		return left_caller;
	case 46:
		left_caller = 0u;
		sub_07AD8F(u);
		return left_caller;
	case 48:
		left_caller = 0u;
		sub_07ADDB();
		return left_caller;
	case 50:
		left_caller = 0u;
		sub_07AE0B(u);
		return left_caller;
	case 52:
		left_caller = 0u;
		return sub_07AE1A(u, left_caller);
	case 54:
		left_caller = 0u;
		sub_07AE9D();
		return left_caller;
	case 56:
		left_caller = 0u;
		return sub_07AEA2(y, left_caller);
	case 58:
		left_caller = 0u;
		sub_07AEB4();
		return left_caller;
	case 60:
		left_caller = 0u;
		return sub_07AEB9(left_caller);
	case 62:
		left_caller = 0u;
		sub_07AEBE(u);
		return left_caller;
	case 64:
		left_caller = 0u;
		sub_07AEEE(u);
		return left_caller;
	case 66:
		left_caller = 0u;
		sub_07AF2C();
		return left_caller;
	case 68:
		left_caller = 0u;
		sub_07AF5A();
		return left_caller;
	case 70:
		left_caller = 0u;
		sub_07AF97(y);
		return left_caller;
	case 72:
		left_caller = 0u;
		sub_07B00F(y);
		return left_caller;
	case 74:
		left_caller = 0u;
		sub_07B022();
		return left_caller;
	case 76:
		left_caller = 0u;
		sub_07B039(u);
		return left_caller;
	case 78:
		left_caller = 0u;
		sub_07B071();
		return left_caller;
	case 80:
		left_caller = 0u;
		sub_07B09D(u);
		return left_caller;
	case 82:
		left_caller = 0u;
		return sub_07B0AC(u, left_caller);
	case 84:
		left_caller = 0u;
		sub_07B125();
		return left_caller;
	case 86:
		left_caller = 0u;
		return sub_07B128(y, left_caller);
	case 88:
		left_caller = 0u;
		sub_07B13A();
		return left_caller;
	case 90:
		left_caller = 0u;
		return sub_07B13D(left_caller);
	case 92:
		left_caller = 0u;
		return sub_07B14C(y, u, left_caller);
	case 94:
		left_caller = 0u;
		return sub_07B19B(y, u, left_caller);
	case 96:
		left_caller = 0u;
		sub_07B1E7();
		return left_caller;
	case 98:
		left_caller = 0u;
		sub_07B219(u);
		return left_caller;
	case 100:
		left_caller = 0u;
		sub_07B228(u);
		return left_caller;
	case 102:
		left_caller = 0u;
		return sub_07B245(u, left_caller);
	case 104:
		left_caller = 0u;
		sub_07B2DB();
		return left_caller;
	case 106:
		left_caller = 0u;
		return sub_07B318(y, left_caller);
	case 108:
		left_caller = 0u;
		return sub_07B32A(left_caller);
	case 110:
		left_caller = 0u;
		return sub_07B333(y, u, left_caller);
	case 112:
		left_caller = 0u;
		return sub_07B36F(y, left_caller);
	case 114:
		left_caller = 0u;
		return sub_07B389(y, left_caller);
	case 116:
		left_caller = 0u;
		sub_07B39B();
		return left_caller;
	case 118:
		left_caller = 0u;
		return sub_07B39E(left_caller);
	case 120:
		left_caller = 0u;
		return sub_07B3A1(y, left_caller);
	case 122:
		left_caller = 0u;
		return sub_07B3D5(left_caller);
	case 124:
		left_caller = 0u;
		return sub_07B3DC(u, left_caller);
	case 126:
		left_caller = 0u;
		sub_07B416();
		return left_caller;
	case -24:
		left_caller = 0u;
		sub_07A834();
		return left_caller;
	case -22:
		left_caller = 0u;
		sub_07A851();
		return left_caller;
	case -20:
		left_caller = 0u;
		sub_07A876(u);
		return left_caller;
	case -18:
		left_caller = 0u;
		sub_07A8C1();
		return left_caller;
	case -16:
		left_caller = 0u;
		sub_07A8ED(u);
		return left_caller;
	case -14:
		left_caller = 0u;
		return sub_07A8FC(u, left_caller);
	case -12:
		left_caller = 0u;
		sub_07A975();
		return left_caller;
	case -10:
		left_caller = 0u;
		return sub_07A978(y, left_caller);
	case -8:
		left_caller = 0u;
		return sub_07A99B(y, left_caller);
	case -6:
		left_caller = 0u;
		sub_07A9C2();
		return left_caller;
	case -4:
		left_caller = 0u;
		return sub_07A9D2(left_caller);
	case -2:
		return sub_07A9DB();
	}
	unreachable();
}

void sub_07AA15(void)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0;

	sub_0792DD(&ignored16, &ignored16_2);
	sub_079269();
	sub_07960F();
	d = 0u;
	carry = sub_0797ED(d);
	unk_480E = 0x13u;
	set_lines(unk_480E);
	unk_48A4 = stage_slots[4].record;
	sub_07BA87();
	unk_4804++;
}

uint32_t sub_07AA3E(uint16_t u, uint32_t left_caller)
{
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, u_2 = 0, x = 0, y = 0;

	d = 0x10u;
	sub_07B632(d);
	d = 0u;
	sub_07B64C(d);
	unk_487E = 1u;
	d = 0x880u;
	sub_07BAC7(d, &ignored16, &u);
	unk_487E = 1u;
	d = 0xF86u;
	sub_07BAC7(d, &ignored16, &u);
	unk_487E = 2u;
	d = 0x15u;
	sub_07BAC7(d, &ignored16, &u);
	unk_487E = 2u;
	d = 0x3Bu;
	sub_07BAC7(d, &ignored16, &u);
	unk_480E = 0x13u;
	set_lines(unk_480E);
	sub_02602A(u);
	sub_07BA93();
	y = unk_4000_ADDRESS;
	x = 0x4001u;
	unk_4000 = 0xFFu;
	u_2 = 0x7FFu;
	while (u_2 != 0u)
	{
		mem_write8(x, mem_read8(y));
		y++;
		x++;
		u_2--;
	}
	io_write8(IO_1FB9, 0x3Fu);
	io_write8(IO_1FBA, 0x36u);
	unk_4875 = 0x87u;
	unk_4876 = 0u;
	sub_07C931();
	d = 0x26u;
	sub_07C4A3(d, &ignored16_2, &ignored16, &ignored16_3);
	d = 0x126u;
	sub_07C4E1(d, &y, &ignored16_3);
	unk_488D = 1u;
	left_caller = sub_07C954(y, left_caller);
	unk_480E = 0x1Fu;
	set_lines(unk_480E);
	sub_03E057(&ignored16_2, &ignored16, &ignored16_3);
	io_write8(IO_1FB9, 0x13u);
	io_write8(IO_1FBA, 0x2Cu);
	unk_4885 = unk_4850;
	unk_4804++;
	return left_caller;
}

void sub_07AAE0(void)
{
	lost_stack(0x07AAE0u);
}

void sub_07AAEE(void)
{
	sub_07B5A9();
}

uint32_t sub_07AAF1(uint16_t y, uint32_t left_caller)
{
	uint16_t ignored16 = 0;

	sub_07B5DD(y, &ignored16, &left_caller);
	if (unk_487C != 0u)
	{
		unk_487C = 0u;
		unk_4880++;
		sub_07BA93();
	}
	return left_caller;
}

void sub_07AB03(void)
{
	sub_07B666();
}

uint32_t sub_07AB06(uint32_t left_caller)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;

	sub_07B676(&ignored16, &left_caller, &carry);
	return left_caller;
}

uint32_t sub_07AB09(uint16_t y, uint16_t u, uint32_t left_caller)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, ignored16_4 = 0;

	unk_4872 = 1u;
	sub_07CB9F(&y, &u, &left_caller);
	u = sub_07CBD2(u);
	unk_480E = 0x1Fu;
	set_lines(unk_480E);
	u = sub_03E04B(u);
	if (unk_4872 != 0u)
	{
		unk_480E = 0x13u;
		set_lines(unk_480E);
		sub_026009(u);
		sub_07B70D(&ignored16, &ignored16_2, &ignored16_3, &ignored16_4, &carry);
		return left_caller;
	}
	d = 0u;
	carry = sub_0797ED(d);
	unk_4803++;
	unk_4804 = 0u;
	unk_4805 = 0u;
	unk_480E = 0x13u;
	set_lines(unk_480E);
	sub_026009(u);
	sub_07B70D(&ignored16, &ignored16_2, &ignored16_3, &ignored16_4, &carry);
	return left_caller;
}

uint32_t sub_07AB4F(uint16_t y, uint16_t u)
{
	uint32_t left_caller = 0;

	switch ((int8_t)(uint8_t)((uint32_t)unk_4804 << 1))
	{
	case 0:
		left_caller = 0u;
		sub_07AB58();
		return left_caller;
	case 2:
		left_caller = 0u;
		sub_07AB84(u);
		return left_caller;
	case 4:
		left_caller = 0u;
		return sub_07AB93(u, left_caller);
	case 6:
		left_caller = 0u;
		sub_07AC0C();
		return left_caller;
	case 8:
		left_caller = 0u;
		return sub_07AC0F(y, left_caller);
	case 10:
		left_caller = 0u;
		sub_07AC21();
		return left_caller;
	case 12:
		left_caller = 0u;
		return sub_07AC24(left_caller);
	case 14:
		left_caller = 0u;
		return sub_07AC27(left_caller);
	case 16:
		left_caller = 0u;
		sub_07AC7D();
		return left_caller;
	case 18:
		left_caller = 0u;
		sub_07ACA9(u);
		return left_caller;
	case 20:
		left_caller = 0u;
		return sub_07ACB8(u, left_caller);
	case 22:
		left_caller = 0u;
		sub_07AD31();
		return left_caller;
	case 24:
		left_caller = 0u;
		return sub_07AD34(y, left_caller);
	case 26:
		left_caller = 0u;
		sub_07AD46();
		return left_caller;
	case 28:
		left_caller = 0u;
		return sub_07AD49(left_caller);
	case 30:
		left_caller = 0u;
		sub_07AD5B(u);
		return left_caller;
	case 32:
		left_caller = 0u;
		sub_07AD8F(u);
		return left_caller;
	case 34:
		left_caller = 0u;
		sub_07ADDB();
		return left_caller;
	case 36:
		left_caller = 0u;
		sub_07AE0B(u);
		return left_caller;
	case 38:
		left_caller = 0u;
		return sub_07AE1A(u, left_caller);
	case 40:
		left_caller = 0u;
		sub_07AE9D();
		return left_caller;
	case 42:
		left_caller = 0u;
		return sub_07AEA2(y, left_caller);
	case 44:
		left_caller = 0u;
		sub_07AEB4();
		return left_caller;
	case 46:
		left_caller = 0u;
		return sub_07AEB9(left_caller);
	case 48:
		left_caller = 0u;
		sub_07AEBE(u);
		return left_caller;
	case 50:
		left_caller = 0u;
		sub_07AEEE(u);
		return left_caller;
	case 52:
		left_caller = 0u;
		sub_07AF2C();
		return left_caller;
	case 54:
		left_caller = 0u;
		sub_07AF5A();
		return left_caller;
	case 56:
		left_caller = 0u;
		sub_07AF97(y);
		return left_caller;
	case 58:
		left_caller = 0u;
		sub_07B00F(y);
		return left_caller;
	case 60:
		left_caller = 0u;
		sub_07B022();
		return left_caller;
	case 62:
		left_caller = 0u;
		sub_07B039(u);
		return left_caller;
	case 64:
		left_caller = 0u;
		sub_07B071();
		return left_caller;
	case 66:
		left_caller = 0u;
		sub_07B09D(u);
		return left_caller;
	case 68:
		left_caller = 0u;
		return sub_07B0AC(u, left_caller);
	case 70:
		left_caller = 0u;
		sub_07B125();
		return left_caller;
	case 72:
		left_caller = 0u;
		return sub_07B128(y, left_caller);
	case 74:
		left_caller = 0u;
		sub_07B13A();
		return left_caller;
	case 76:
		left_caller = 0u;
		return sub_07B13D(left_caller);
	case 78:
		left_caller = 0u;
		return sub_07B14C(y, u, left_caller);
	case 80:
		left_caller = 0u;
		return sub_07B19B(y, u, left_caller);
	case 82:
		left_caller = 0u;
		sub_07B1E7();
		return left_caller;
	case 84:
		left_caller = 0u;
		sub_07B219(u);
		return left_caller;
	case 86:
		left_caller = 0u;
		sub_07B228(u);
		return left_caller;
	case 88:
		left_caller = 0u;
		return sub_07B245(u, left_caller);
	case 90:
		left_caller = 0u;
		sub_07B2DB();
		return left_caller;
	case 92:
		left_caller = 0u;
		return sub_07B318(y, left_caller);
	case 94:
		left_caller = 0u;
		return sub_07B32A(left_caller);
	case 96:
		left_caller = 0u;
		return sub_07B333(y, u, left_caller);
	case 98:
		left_caller = 0u;
		return sub_07B36F(y, left_caller);
	case 100:
		left_caller = 0u;
		return sub_07B389(y, left_caller);
	case 102:
		left_caller = 0u;
		sub_07B39B();
		return left_caller;
	case 104:
		left_caller = 0u;
		return sub_07B39E(left_caller);
	case 106:
		left_caller = 0u;
		return sub_07B3A1(y, left_caller);
	case 108:
		left_caller = 0u;
		return sub_07B3D5(left_caller);
	case 110:
		left_caller = 0u;
		return sub_07B3DC(u, left_caller);
	case 112:
		left_caller = 0u;
		sub_07B416();
		return left_caller;
	case 114:
		left_caller = 0u;
		sub_07B423(u);
		return left_caller;
	case 116:
		left_caller = 0u;
		sub_07B449();
		return left_caller;
	case 118:
		left_caller = 0u;
		sub_07B470();
		return left_caller;
	case 120:
		left_caller = 0u;
		sub_07B4A1();
		return left_caller;
	case 122:
		left_caller = 0u;
		sub_07B4BF();
		return left_caller;
	case 124:
		left_caller = 0u;
		sub_07B501(u);
		return left_caller;
	case 126:
		left_caller = 0u;
		sub_07B577();
		return left_caller;
	case -38:
		left_caller = 0u;
		sub_07A834();
		return left_caller;
	case -36:
		left_caller = 0u;
		sub_07A851();
		return left_caller;
	case -34:
		left_caller = 0u;
		sub_07A876(u);
		return left_caller;
	case -32:
		left_caller = 0u;
		sub_07A8C1();
		return left_caller;
	case -30:
		left_caller = 0u;
		sub_07A8ED(u);
		return left_caller;
	case -28:
		left_caller = 0u;
		return sub_07A8FC(u, left_caller);
	case -26:
		left_caller = 0u;
		sub_07A975();
		return left_caller;
	case -24:
		left_caller = 0u;
		return sub_07A978(y, left_caller);
	case -22:
		left_caller = 0u;
		return sub_07A99B(y, left_caller);
	case -20:
		left_caller = 0u;
		sub_07A9C2();
		return left_caller;
	case -18:
		left_caller = 0u;
		return sub_07A9D2(left_caller);
	case -16:
		return sub_07A9DB();
	case -14:
		left_caller = 0u;
		sub_07AA15();
		return left_caller;
	case -12:
		left_caller = 0u;
		return sub_07AA3E(u, left_caller);
	case -10:
		left_caller = 0u;
		sub_07AAEE();
		return left_caller;
	case -8:
		left_caller = 0u;
		return sub_07AAF1(y, left_caller);
	case -6:
		left_caller = 0u;
		sub_07AB03();
		return left_caller;
	case -4:
		left_caller = 0u;
		return sub_07AB06(left_caller);
	case -2:
		left_caller = 0u;
		return sub_07AB09(y, u, left_caller);
	}
	unreachable();
}

void sub_07AB58(void)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0;

	unk_486A = 0u;
	sub_079269();
	sub_0792DD(&ignored16, &ignored16_2);
	sub_07960F();
	d = 0u;
	carry = sub_0797ED(d);
	unk_480E = 0x13u;
	set_lines(unk_480E);
	unk_48A4 = stage_slots[5].record;
	sub_07BA87();
	unk_4804++;
}

void sub_07AB84(uint16_t u)
{
	unk_480E = 0x13u;
	set_lines(unk_480E);
	sub_026006(u);
}

uint32_t sub_07AB93(uint16_t u, uint32_t left_caller)
{
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, y = 0;

	d = 0u;
	sub_07B632(d);
	d = 0u;
	sub_07B64C(d);
	unk_487E = 1u;
	d = 0xE87u;
	sub_07BAC7(d, &ignored16, &u);
	unk_487E = 2u;
	d = VIDEO_003C;
	sub_07BAC7(d, &ignored16, &u);
	sub_07BA93();
	io_write8(IO_1FB9, 0x3Fu);
	io_write8(IO_1FBA, 0x36u);
	unk_4875 = 0x88u;
	unk_4876 = 0u;
	sub_07C931();
	d = 0x2Cu;
	sub_07C4A3(d, &ignored16_2, &ignored16, &ignored16_3);
	d = 0x12Cu;
	sub_07C4E1(d, &y, &ignored16_3);
	left_caller = sub_07C954(y, left_caller);
	unk_480E = 0x1Fu;
	set_lines(unk_480E);
	sub_03E057(&ignored16_2, &ignored16, &ignored16_3);
	io_write8(IO_1FB9, 0x13u);
	io_write8(IO_1FBA, 0x2Cu);
	unk_4885 = unk_4850;
	unk_4804++;
	return left_caller;
}

void sub_07AC00(void)
{
	lost_stack(0x07AC00u);
}

void sub_07AC0C(void)
{
	sub_07B5A9();
}

uint32_t sub_07AC0F(uint16_t y, uint32_t left_caller)
{
	uint16_t ignored16 = 0;

	sub_07B5DD(y, &ignored16, &left_caller);
	if (unk_487C != 0u)
	{
		unk_487C = 0u;
		unk_4880++;
		sub_07BA93();
	}
	return left_caller;
}

void sub_07AC21(void)
{
	sub_07B666();
}

uint32_t sub_07AC24(uint32_t left_caller)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;

	sub_07B676(&ignored16, &left_caller, &carry);
	return left_caller;
}

uint32_t sub_07AC27(uint32_t left_caller)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, ignored16_4 = 0, u = 0;

	unk_4872 = 1u;
	sub_07CB9F(&ignored16, &ignored16_2, &left_caller);
	sub_07CBD2(ignored16_2);
	unk_480E = 0x1Fu;
	set_lines(unk_480E);
	sub_03E01E();
	sub_07C016(&u, &ignored16_3);
	if (unk_4872 != 0u)
	{
		unk_480E = 0x13u;
		set_lines(unk_480E);
		sub_026009(u);
		sub_07B70D(&ignored16_4, &ignored16, &ignored16_2, &ignored16_3, &carry);
		return left_caller;
	}
	d = 0u;
	carry = sub_0797ED(d);
	sub_0792DD(&ignored16_4, &ignored16);
	unk_4803++;
	unk_4804 = 0u;
	unk_4805 = 0u;
	return left_caller;
}

uint32_t sub_07AC74(uint16_t y, uint16_t u)
{
	uint32_t left_caller = 0;

	switch ((int8_t)(uint8_t)((uint32_t)unk_4804 << 1))
	{
	case 0:
		left_caller = 0u;
		sub_07AC7D();
		return left_caller;
	case 2:
		left_caller = 0u;
		sub_07ACA9(u);
		return left_caller;
	case 4:
		left_caller = 0u;
		return sub_07ACB8(u, left_caller);
	case 6:
		left_caller = 0u;
		sub_07AD31();
		return left_caller;
	case 8:
		left_caller = 0u;
		return sub_07AD34(y, left_caller);
	case 10:
		left_caller = 0u;
		sub_07AD46();
		return left_caller;
	case 12:
		left_caller = 0u;
		return sub_07AD49(left_caller);
	case 14:
		left_caller = 0u;
		sub_07AD5B(u);
		return left_caller;
	case 16:
		left_caller = 0u;
		sub_07AD8F(u);
		return left_caller;
	case 18:
		left_caller = 0u;
		sub_07ADDB();
		return left_caller;
	case 20:
		left_caller = 0u;
		sub_07AE0B(u);
		return left_caller;
	case 22:
		left_caller = 0u;
		return sub_07AE1A(u, left_caller);
	case 24:
		left_caller = 0u;
		sub_07AE9D();
		return left_caller;
	case 26:
		left_caller = 0u;
		return sub_07AEA2(y, left_caller);
	case 28:
		left_caller = 0u;
		sub_07AEB4();
		return left_caller;
	case 30:
		left_caller = 0u;
		return sub_07AEB9(left_caller);
	case 32:
		left_caller = 0u;
		sub_07AEBE(u);
		return left_caller;
	case 34:
		left_caller = 0u;
		sub_07AEEE(u);
		return left_caller;
	case 36:
		left_caller = 0u;
		sub_07AF2C();
		return left_caller;
	case 38:
		left_caller = 0u;
		sub_07AF5A();
		return left_caller;
	case 40:
		left_caller = 0u;
		sub_07AF97(y);
		return left_caller;
	case 42:
		left_caller = 0u;
		sub_07B00F(y);
		return left_caller;
	case 44:
		left_caller = 0u;
		sub_07B022();
		return left_caller;
	case 46:
		left_caller = 0u;
		sub_07B039(u);
		return left_caller;
	case 48:
		left_caller = 0u;
		sub_07B071();
		return left_caller;
	case 50:
		left_caller = 0u;
		sub_07B09D(u);
		return left_caller;
	case 52:
		left_caller = 0u;
		return sub_07B0AC(u, left_caller);
	case 54:
		left_caller = 0u;
		sub_07B125();
		return left_caller;
	case 56:
		left_caller = 0u;
		return sub_07B128(y, left_caller);
	case 58:
		left_caller = 0u;
		sub_07B13A();
		return left_caller;
	case 60:
		left_caller = 0u;
		return sub_07B13D(left_caller);
	case 62:
		left_caller = 0u;
		return sub_07B14C(y, u, left_caller);
	case 64:
		left_caller = 0u;
		return sub_07B19B(y, u, left_caller);
	case 66:
		left_caller = 0u;
		sub_07B1E7();
		return left_caller;
	case 68:
		left_caller = 0u;
		sub_07B219(u);
		return left_caller;
	case 70:
		left_caller = 0u;
		sub_07B228(u);
		return left_caller;
	case 72:
		left_caller = 0u;
		return sub_07B245(u, left_caller);
	case 74:
		left_caller = 0u;
		sub_07B2DB();
		return left_caller;
	case 76:
		left_caller = 0u;
		return sub_07B318(y, left_caller);
	case 78:
		left_caller = 0u;
		return sub_07B32A(left_caller);
	case 80:
		left_caller = 0u;
		return sub_07B333(y, u, left_caller);
	case 82:
		left_caller = 0u;
		return sub_07B36F(y, left_caller);
	case 84:
		left_caller = 0u;
		return sub_07B389(y, left_caller);
	case 86:
		left_caller = 0u;
		sub_07B39B();
		return left_caller;
	case 88:
		left_caller = 0u;
		return sub_07B39E(left_caller);
	case 90:
		left_caller = 0u;
		return sub_07B3A1(y, left_caller);
	case 92:
		left_caller = 0u;
		return sub_07B3D5(left_caller);
	case 94:
		left_caller = 0u;
		return sub_07B3DC(u, left_caller);
	case 96:
		left_caller = 0u;
		sub_07B416();
		return left_caller;
	case 98:
		left_caller = 0u;
		sub_07B423(u);
		return left_caller;
	case 100:
		left_caller = 0u;
		sub_07B449();
		return left_caller;
	case 102:
		left_caller = 0u;
		sub_07B470();
		return left_caller;
	case 104:
		left_caller = 0u;
		sub_07B4A1();
		return left_caller;
	case 106:
		left_caller = 0u;
		sub_07B4BF();
		return left_caller;
	case 108:
		left_caller = 0u;
		sub_07B501(u);
		return left_caller;
	case 110:
		left_caller = 0u;
		sub_07B577();
		return left_caller;
	case 112:
		left_caller = 0u;
		sub_07B58C();
		return left_caller;
	case -54:
		left_caller = 0u;
		sub_07A834();
		return left_caller;
	case -52:
		left_caller = 0u;
		sub_07A851();
		return left_caller;
	case -50:
		left_caller = 0u;
		sub_07A876(u);
		return left_caller;
	case -48:
		left_caller = 0u;
		sub_07A8C1();
		return left_caller;
	case -46:
		left_caller = 0u;
		sub_07A8ED(u);
		return left_caller;
	case -44:
		left_caller = 0u;
		return sub_07A8FC(u, left_caller);
	case -42:
		left_caller = 0u;
		sub_07A975();
		return left_caller;
	case -40:
		left_caller = 0u;
		return sub_07A978(y, left_caller);
	case -38:
		left_caller = 0u;
		return sub_07A99B(y, left_caller);
	case -36:
		left_caller = 0u;
		sub_07A9C2();
		return left_caller;
	case -34:
		left_caller = 0u;
		return sub_07A9D2(left_caller);
	case -32:
		return sub_07A9DB();
	case -30:
		left_caller = 0u;
		sub_07AA15();
		return left_caller;
	case -28:
		left_caller = 0u;
		return sub_07AA3E(u, left_caller);
	case -26:
		left_caller = 0u;
		sub_07AAEE();
		return left_caller;
	case -24:
		left_caller = 0u;
		return sub_07AAF1(y, left_caller);
	case -22:
		left_caller = 0u;
		sub_07AB03();
		return left_caller;
	case -20:
		left_caller = 0u;
		return sub_07AB06(left_caller);
	case -18:
		left_caller = 0u;
		return sub_07AB09(y, u, left_caller);
	case -16:
		left_caller = 0u;
		sub_07AB58();
		return left_caller;
	case -14:
		left_caller = 0u;
		sub_07AB84(u);
		return left_caller;
	case -12:
		left_caller = 0u;
		return sub_07AB93(u, left_caller);
	case -10:
		left_caller = 0u;
		sub_07AC0C();
		return left_caller;
	case -8:
		left_caller = 0u;
		return sub_07AC0F(y, left_caller);
	case -6:
		left_caller = 0u;
		sub_07AC21();
		return left_caller;
	case -4:
		left_caller = 0u;
		return sub_07AC24(left_caller);
	case -2:
		left_caller = 0u;
		return sub_07AC27(left_caller);
	}
	unreachable();
}

void sub_07AC7D(void)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0;

	unk_486A = 0u;
	sub_0792DD(&ignored16, &ignored16_2);
	sub_079269();
	sub_07960F();
	d = 0u;
	carry = sub_0797ED(d);
	unk_480E = 0x13u;
	set_lines(unk_480E);
	unk_48A4 = stage_slots[6].record;
	sub_07BA87();
	unk_4804++;
}

void sub_07ACA9(uint16_t u)
{
	unk_480E = 0x13u;
	set_lines(unk_480E);
	sub_026006(u);
}

uint32_t sub_07ACB8(uint16_t u, uint32_t left_caller)
{
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, y = 0;

	d = 0u;
	sub_07B632(d);
	d = 0u;
	sub_07B64C(d);
	unk_487E = 1u;
	d = 0xF88u;
	sub_07BAC7(d, &ignored16, &u);
	unk_487E = 2u;
	d = 0xFu;
	sub_07BAC7(d, &ignored16, &u);
	sub_07BA93();
	io_write8(IO_1FB9, 0x3Fu);
	io_write8(IO_1FBA, 0x36u);
	unk_4875 = 0x89u;
	unk_4876 = 0u;
	sub_07C931();
	d = 0x2Cu;
	sub_07C4E1(d, &ignored16, &ignored16_2);
	d = 0x12Cu;
	sub_07C4A3(d, &ignored16_3, &y, &ignored16_2);
	left_caller = sub_07C954(y, left_caller);
	unk_480E = 0x1Fu;
	set_lines(unk_480E);
	sub_03E057(&ignored16_3, &ignored16, &ignored16_2);
	io_write8(IO_1FB9, 0x13u);
	io_write8(IO_1FBA, 0x2Cu);
	unk_4885 = unk_4850;
	unk_4804++;
	return left_caller;
}

void sub_07AD31(void)
{
	sub_07B5A9();
}

uint32_t sub_07AD34(uint16_t y, uint32_t left_caller)
{
	uint16_t ignored16 = 0;

	sub_07B5DD(y, &ignored16, &left_caller);
	if (unk_487C != 0u)
	{
		unk_487C = 0u;
		unk_4880++;
		sub_07BA93();
	}
	return left_caller;
}

void sub_07AD46(void)
{
	sub_07B666();
}

uint32_t sub_07AD49(uint32_t left_caller)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, ignored16_4 = 0;

	sub_07B676(&ignored16, &left_caller, &carry);
	if (carry)
		unk_48A4 += 4u;
	sub_07B70D(&ignored16_2, &ignored16_3, &ignored16, &ignored16_4, &carry);
	return left_caller;
}

void sub_07AD5B(uint16_t u)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, ignored16_4 = 0;

	unk_4872 = 1u;
	unk_480E = 0x1Fu;
	set_lines(unk_480E);
	u = sub_03E036(u);
	if (unk_4872 == 0u)
	{
		unk_4872 = 1u;
		unk_4804++;
	}
	unk_480E = 0x13u;
	set_lines(unk_480E);
	sub_026009(u);
	sub_07B70D(&ignored16, &ignored16_2, &ignored16_3, &ignored16_4, &carry);
}

void sub_07AD8F(uint16_t u)
{
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t d = 0, ignored16 = 0;

	d = 0xF000u | b;
	sub_079784(d, &ignored16, &carry);
	if (carry)
	{
		d = 0u;
		carry = sub_0797ED(d);
		unk_4803++;
		unk_4804 = 0u;
		unk_4805 = 0u;
		return;
	}
	unk_4872 = 1u;
	unk_480E = 0x12u;
	set_lines(unk_480E);
	sub_024006(u);
	if (unk_4872 != 0u)
		return;
	d = 0u;
	carry = sub_0797ED(d);
	unk_4803++;
	unk_4804 = 0u;
	unk_4805 = 0u;
}

void sub_07ADC4(void)
{
	uint8_t t1 = 0;

	t1 = io_read8(VIDEO_1C80);
	io_write8(VIDEO_1C80, 0u);
	unk_486A = 0u;
	sub_07BA87();
	unk_4803++;
}

uint32_t sub_07ADD2(uint16_t y, uint16_t u)
{
	uint32_t left_caller = 0;

	switch ((int8_t)(uint8_t)((uint32_t)unk_4804 << 1))
	{
	case 0:
		left_caller = 0u;
		sub_07ADDB();
		return left_caller;
	case 2:
		left_caller = 0u;
		sub_07AE0B(u);
		return left_caller;
	case 4:
		left_caller = 0u;
		return sub_07AE1A(u, left_caller);
	case 6:
		left_caller = 0u;
		sub_07AE9D();
		return left_caller;
	case 8:
		left_caller = 0u;
		return sub_07AEA2(y, left_caller);
	case 10:
		left_caller = 0u;
		sub_07AEB4();
		return left_caller;
	case 12:
		left_caller = 0u;
		return sub_07AEB9(left_caller);
	case 14:
		left_caller = 0u;
		sub_07AEBE(u);
		return left_caller;
	case 16:
		left_caller = 0u;
		sub_07AEEE(u);
		return left_caller;
	case 18:
		left_caller = 0u;
		sub_07AF2C();
		return left_caller;
	case 20:
		left_caller = 0u;
		sub_07AF5A();
		return left_caller;
	case 22:
		left_caller = 0u;
		sub_07AF97(y);
		return left_caller;
	case 24:
		left_caller = 0u;
		sub_07B00F(y);
		return left_caller;
	case 26:
		left_caller = 0u;
		sub_07B022();
		return left_caller;
	case 28:
		left_caller = 0u;
		sub_07B039(u);
		return left_caller;
	case 30:
		left_caller = 0u;
		sub_07B071();
		return left_caller;
	case 32:
		left_caller = 0u;
		sub_07B09D(u);
		return left_caller;
	case 34:
		left_caller = 0u;
		return sub_07B0AC(u, left_caller);
	case 36:
		left_caller = 0u;
		sub_07B125();
		return left_caller;
	case 38:
		left_caller = 0u;
		return sub_07B128(y, left_caller);
	case 40:
		left_caller = 0u;
		sub_07B13A();
		return left_caller;
	case 42:
		left_caller = 0u;
		return sub_07B13D(left_caller);
	case 44:
		left_caller = 0u;
		return sub_07B14C(y, u, left_caller);
	case 46:
		left_caller = 0u;
		return sub_07B19B(y, u, left_caller);
	case 48:
		left_caller = 0u;
		sub_07B1E7();
		return left_caller;
	case 50:
		left_caller = 0u;
		sub_07B219(u);
		return left_caller;
	case 52:
		left_caller = 0u;
		sub_07B228(u);
		return left_caller;
	case 54:
		left_caller = 0u;
		return sub_07B245(u, left_caller);
	case 56:
		left_caller = 0u;
		sub_07B2DB();
		return left_caller;
	case 58:
		left_caller = 0u;
		return sub_07B318(y, left_caller);
	case 60:
		left_caller = 0u;
		return sub_07B32A(left_caller);
	case 62:
		left_caller = 0u;
		return sub_07B333(y, u, left_caller);
	case 64:
		left_caller = 0u;
		return sub_07B36F(y, left_caller);
	case 66:
		left_caller = 0u;
		return sub_07B389(y, left_caller);
	case 68:
		left_caller = 0u;
		sub_07B39B();
		return left_caller;
	case 70:
		left_caller = 0u;
		return sub_07B39E(left_caller);
	case 72:
		left_caller = 0u;
		return sub_07B3A1(y, left_caller);
	case 74:
		left_caller = 0u;
		return sub_07B3D5(left_caller);
	case 76:
		left_caller = 0u;
		return sub_07B3DC(u, left_caller);
	case 78:
		left_caller = 0u;
		sub_07B416();
		return left_caller;
	case 80:
		left_caller = 0u;
		sub_07B423(u);
		return left_caller;
	case 82:
		left_caller = 0u;
		sub_07B449();
		return left_caller;
	case 84:
		left_caller = 0u;
		sub_07B470();
		return left_caller;
	case 86:
		left_caller = 0u;
		sub_07B4A1();
		return left_caller;
	case 88:
		left_caller = 0u;
		sub_07B4BF();
		return left_caller;
	case 90:
		left_caller = 0u;
		sub_07B501(u);
		return left_caller;
	case 92:
		left_caller = 0u;
		sub_07B577();
		return left_caller;
	case 94:
		left_caller = 0u;
		sub_07B58C();
		return left_caller;
	case -72:
		left_caller = 0u;
		sub_07A834();
		return left_caller;
	case -70:
		left_caller = 0u;
		sub_07A851();
		return left_caller;
	case -68:
		left_caller = 0u;
		sub_07A876(u);
		return left_caller;
	case -66:
		left_caller = 0u;
		sub_07A8C1();
		return left_caller;
	case -64:
		left_caller = 0u;
		sub_07A8ED(u);
		return left_caller;
	case -62:
		left_caller = 0u;
		return sub_07A8FC(u, left_caller);
	case -60:
		left_caller = 0u;
		sub_07A975();
		return left_caller;
	case -58:
		left_caller = 0u;
		return sub_07A978(y, left_caller);
	case -56:
		left_caller = 0u;
		return sub_07A99B(y, left_caller);
	case -54:
		left_caller = 0u;
		sub_07A9C2();
		return left_caller;
	case -52:
		left_caller = 0u;
		return sub_07A9D2(left_caller);
	case -50:
		return sub_07A9DB();
	case -48:
		left_caller = 0u;
		sub_07AA15();
		return left_caller;
	case -46:
		left_caller = 0u;
		return sub_07AA3E(u, left_caller);
	case -44:
		left_caller = 0u;
		sub_07AAEE();
		return left_caller;
	case -42:
		left_caller = 0u;
		return sub_07AAF1(y, left_caller);
	case -40:
		left_caller = 0u;
		sub_07AB03();
		return left_caller;
	case -38:
		left_caller = 0u;
		return sub_07AB06(left_caller);
	case -36:
		left_caller = 0u;
		return sub_07AB09(y, u, left_caller);
	case -34:
		left_caller = 0u;
		sub_07AB58();
		return left_caller;
	case -32:
		left_caller = 0u;
		sub_07AB84(u);
		return left_caller;
	case -30:
		left_caller = 0u;
		return sub_07AB93(u, left_caller);
	case -28:
		left_caller = 0u;
		sub_07AC0C();
		return left_caller;
	case -26:
		left_caller = 0u;
		return sub_07AC0F(y, left_caller);
	case -24:
		left_caller = 0u;
		sub_07AC21();
		return left_caller;
	case -22:
		left_caller = 0u;
		return sub_07AC24(left_caller);
	case -20:
		left_caller = 0u;
		return sub_07AC27(left_caller);
	case -18:
		left_caller = 0u;
		sub_07AC7D();
		return left_caller;
	case -16:
		left_caller = 0u;
		sub_07ACA9(u);
		return left_caller;
	case -14:
		left_caller = 0u;
		return sub_07ACB8(u, left_caller);
	case -12:
		left_caller = 0u;
		sub_07AD31();
		return left_caller;
	case -10:
		left_caller = 0u;
		return sub_07AD34(y, left_caller);
	case -8:
		left_caller = 0u;
		sub_07AD46();
		return left_caller;
	case -6:
		left_caller = 0u;
		return sub_07AD49(left_caller);
	case -4:
		left_caller = 0u;
		sub_07AD5B(u);
		return left_caller;
	case -2:
		left_caller = 0u;
		sub_07AD8F(u);
		return left_caller;
	}
	unreachable();
}

void sub_07ADDB(void)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0;
	uint8_t t1 = 0;

	unk_486A = 0u;
	sub_0792DD(&ignored16, &ignored16_2);
	sub_079269();
	sub_07960F();
	d = 0u;
	carry = sub_0797ED(d);
	unk_480E = 0x13u;
	set_lines(unk_480E);
	unk_48A4 = stage_slots[9].record;
	sub_07BA87();
	t1 = io_read8(VIDEO_1C80);
	io_write8(VIDEO_1C80, 0u);
	unk_4804++;
}

void sub_07AE0B(uint16_t u)
{
	unk_480E = 0x13u;
	set_lines(unk_480E);
	sub_026006(u);
}

uint32_t sub_07AE1A(uint16_t u, uint32_t left_caller)
{
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, y = 0;

	d = 0u;
	sub_07B632(d);
	d = 0u;
	sub_07B64C(d);
	unk_487E = 1u;
	d = 0xF8Bu;
	sub_07BAC7(d, &ignored16, &u);
	sub_07BA93();
	io_write8(IO_1FB9, 0x3Fu);
	io_write8(IO_1FBA, 0x36u);
	unk_4875 = 0x8Au;
	unk_4876 = 0u;
	sub_07C931();
	d = 0x40u;
	sub_07C4A3(d, &ignored16_2, &ignored16, &ignored16_3);
	d = 0x12Cu;
	sub_07C4E1(d, &y, &ignored16_3);
	left_caller = sub_07C954(y, left_caller);
	unk_480E = 0x1Fu;
	set_lines(unk_480E);
	sub_03E057(&ignored16_2, &ignored16, &ignored16_3);
	io_write8(VIDEO_1C80, 3u);
	unk_480E = 0x12u;
	set_lines(unk_480E);
	sub_024015();
	io_write8(IO_1FB9, 0x13u);
	io_write8(IO_1FBA, 0x2Cu);
	unk_4885 = unk_4850;
	unk_4804++;
	return left_caller;
}

void sub_07AE9D(void)
{
	uint16_t u = 0;

	u = sub_07B5A9();
	unk_480E = 0x13u;
	set_lines(unk_480E);
	sub_026009(u);
}

uint32_t sub_07AEA2(uint16_t y, uint32_t left_caller)
{
	uint16_t ignored16 = 0;

	sub_07B5DD(y, &ignored16, &left_caller);
	if (unk_487C != 0u)
	{
		unk_487C = 0u;
		unk_4880++;
		sub_07BA93();
	}
	return left_caller;
}

void sub_07AEB4(void)
{
	uint16_t u = 0;

	u = sub_07B666();
	unk_480E = 0x13u;
	set_lines(unk_480E);
	sub_026009(u);
}

uint32_t sub_07AEB9(uint32_t left_caller)
{
	uint32_t carry = 0;
	uint16_t u = 0;

	sub_07B676(&u, &left_caller, &carry);
	unk_480E = 0x13u;
	set_lines(unk_480E);
	sub_026009(u);
	return left_caller;
}

void sub_07AEBE(uint16_t u)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, u_2 = 0;

	unk_4872 = 1u;
	unk_480E = 0x12u;
	set_lines(unk_480E);
	sub_02401B(u);
	sub_07B70D(&ignored16, &ignored16_2, &u_2, &ignored16_3, &carry);
	if (unk_4872 == 0u)
	{
		unk_4804++;
		return;
	}
	unk_480E = 0x13u;
	set_lines(unk_480E);
	sub_026009(u_2);
}

void sub_07AEEE(uint16_t u)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	unk_4872 = 1u;
	unk_480E = 0x12u;
	set_lines(unk_480E);
	sub_02401E(u);
	if (unk_4872 != 0u)
		return;
	t1 = io_read8(VIDEO_1C80);
	io_write8(VIDEO_1C80, 0u);
	d = 0u;
	carry = sub_0797ED(d);
	unk_4803++;
	unk_4804 = 0u;
	unk_4805 = 0u;
}

uint32_t sub_07AF20(uint16_t y, uint16_t u)
{
	uint32_t left_caller = 0;

	unk_486A = 0u;
	switch ((int8_t)(uint8_t)((uint32_t)unk_4804 << 1))
	{
	case 0:
		left_caller = 0u;
		sub_07AF2C();
		return left_caller;
	case 2:
		left_caller = 0u;
		sub_07AF5A();
		return left_caller;
	case 4:
		left_caller = 0u;
		sub_07AF97(y);
		return left_caller;
	case 6:
		left_caller = 0u;
		sub_07B00F(y);
		return left_caller;
	case 8:
		left_caller = 0u;
		sub_07B022();
		return left_caller;
	case 10:
		left_caller = 0u;
		sub_07B039(u);
		return left_caller;
	case 12:
		left_caller = 0u;
		sub_07B071();
		return left_caller;
	case 14:
		left_caller = 0u;
		sub_07B09D(u);
		return left_caller;
	case 16:
		left_caller = 0u;
		return sub_07B0AC(u, left_caller);
	case 18:
		left_caller = 0u;
		sub_07B125();
		return left_caller;
	case 20:
		left_caller = 0u;
		return sub_07B128(y, left_caller);
	case 22:
		left_caller = 0u;
		sub_07B13A();
		return left_caller;
	case 24:
		left_caller = 0u;
		return sub_07B13D(left_caller);
	case 26:
		left_caller = 0u;
		return sub_07B14C(y, u, left_caller);
	case 28:
		left_caller = 0u;
		return sub_07B19B(y, u, left_caller);
	case 30:
		left_caller = 0u;
		sub_07B1E7();
		return left_caller;
	case 32:
		left_caller = 0u;
		sub_07B219(u);
		return left_caller;
	case 34:
		left_caller = 0u;
		sub_07B228(u);
		return left_caller;
	case 36:
		left_caller = 0u;
		return sub_07B245(u, left_caller);
	case 38:
		left_caller = 0u;
		sub_07B2DB();
		return left_caller;
	case 40:
		left_caller = 0u;
		return sub_07B318(y, left_caller);
	case 42:
		left_caller = 0u;
		return sub_07B32A(left_caller);
	case 44:
		left_caller = 0u;
		return sub_07B333(y, u, left_caller);
	case 46:
		left_caller = 0u;
		return sub_07B36F(y, left_caller);
	case 48:
		left_caller = 0u;
		return sub_07B389(y, left_caller);
	case 50:
		left_caller = 0u;
		sub_07B39B();
		return left_caller;
	case 52:
		left_caller = 0u;
		return sub_07B39E(left_caller);
	case 54:
		left_caller = 0u;
		return sub_07B3A1(y, left_caller);
	case 56:
		left_caller = 0u;
		return sub_07B3D5(left_caller);
	case 58:
		left_caller = 0u;
		return sub_07B3DC(u, left_caller);
	case 60:
		left_caller = 0u;
		sub_07B416();
		return left_caller;
	case 62:
		left_caller = 0u;
		sub_07B423(u);
		return left_caller;
	case 64:
		left_caller = 0u;
		sub_07B449();
		return left_caller;
	case 66:
		left_caller = 0u;
		sub_07B470();
		return left_caller;
	case 68:
		left_caller = 0u;
		sub_07B4A1();
		return left_caller;
	case 70:
		left_caller = 0u;
		sub_07B4BF();
		return left_caller;
	case 72:
		left_caller = 0u;
		sub_07B501(u);
		return left_caller;
	case 74:
		left_caller = 0u;
		sub_07B577();
		return left_caller;
	case 76:
		left_caller = 0u;
		sub_07B58C();
		return left_caller;
	case -90:
		left_caller = 0u;
		sub_07A834();
		return left_caller;
	case -88:
		left_caller = 0u;
		sub_07A851();
		return left_caller;
	case -86:
		left_caller = 0u;
		sub_07A876(u);
		return left_caller;
	case -84:
		left_caller = 0u;
		sub_07A8C1();
		return left_caller;
	case -82:
		left_caller = 0u;
		sub_07A8ED(u);
		return left_caller;
	case -80:
		left_caller = 0u;
		return sub_07A8FC(u, left_caller);
	case -78:
		left_caller = 0u;
		sub_07A975();
		return left_caller;
	case -76:
		left_caller = 0u;
		return sub_07A978(y, left_caller);
	case -74:
		left_caller = 0u;
		return sub_07A99B(y, left_caller);
	case -72:
		left_caller = 0u;
		sub_07A9C2();
		return left_caller;
	case -70:
		left_caller = 0u;
		return sub_07A9D2(left_caller);
	case -68:
		return sub_07A9DB();
	case -66:
		left_caller = 0u;
		sub_07AA15();
		return left_caller;
	case -64:
		left_caller = 0u;
		return sub_07AA3E(u, left_caller);
	case -62:
		left_caller = 0u;
		sub_07AAEE();
		return left_caller;
	case -60:
		left_caller = 0u;
		return sub_07AAF1(y, left_caller);
	case -58:
		left_caller = 0u;
		sub_07AB03();
		return left_caller;
	case -56:
		left_caller = 0u;
		return sub_07AB06(left_caller);
	case -54:
		left_caller = 0u;
		return sub_07AB09(y, u, left_caller);
	case -52:
		left_caller = 0u;
		sub_07AB58();
		return left_caller;
	case -50:
		left_caller = 0u;
		sub_07AB84(u);
		return left_caller;
	case -48:
		left_caller = 0u;
		return sub_07AB93(u, left_caller);
	case -46:
		left_caller = 0u;
		sub_07AC0C();
		return left_caller;
	case -44:
		left_caller = 0u;
		return sub_07AC0F(y, left_caller);
	case -42:
		left_caller = 0u;
		sub_07AC21();
		return left_caller;
	case -40:
		left_caller = 0u;
		return sub_07AC24(left_caller);
	case -38:
		left_caller = 0u;
		return sub_07AC27(left_caller);
	case -36:
		left_caller = 0u;
		sub_07AC7D();
		return left_caller;
	case -34:
		left_caller = 0u;
		sub_07ACA9(u);
		return left_caller;
	case -32:
		left_caller = 0u;
		return sub_07ACB8(u, left_caller);
	case -30:
		left_caller = 0u;
		sub_07AD31();
		return left_caller;
	case -28:
		left_caller = 0u;
		return sub_07AD34(y, left_caller);
	case -26:
		left_caller = 0u;
		sub_07AD46();
		return left_caller;
	case -24:
		left_caller = 0u;
		return sub_07AD49(left_caller);
	case -22:
		left_caller = 0u;
		sub_07AD5B(u);
		return left_caller;
	case -20:
		left_caller = 0u;
		sub_07AD8F(u);
		return left_caller;
	case -18:
		left_caller = 0u;
		sub_07ADDB();
		return left_caller;
	case -16:
		left_caller = 0u;
		sub_07AE0B(u);
		return left_caller;
	case -14:
		left_caller = 0u;
		return sub_07AE1A(u, left_caller);
	case -12:
		left_caller = 0u;
		sub_07AE9D();
		return left_caller;
	case -10:
		left_caller = 0u;
		return sub_07AEA2(y, left_caller);
	case -8:
		left_caller = 0u;
		sub_07AEB4();
		return left_caller;
	case -6:
		left_caller = 0u;
		return sub_07AEB9(left_caller);
	case -4:
		left_caller = 0u;
		sub_07AEBE(u);
		return left_caller;
	case -2:
		left_caller = 0u;
		sub_07AEEE(u);
		return left_caller;
	}
	unreachable();
}

void sub_07AF2C(void)
{
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, u = 0;
	uint8_t t1 = 0;

	t1 = io_read8(VIDEO_1C80);
	io_write8(VIDEO_1C80, 0u);
	sub_0792DD(&ignored16, &ignored16_2);
	d = 0u;
	sub_0797B7(d);
	u = sub_07960F();
	unk_487E = 1u;
	d = 0xF82u;
	sub_07BAC7(d, &ignored16_2, &u);
	d = 0xFFF0u;
	sub_07B632(d);
	d = 0u;
	sub_07B64C(d);
	sub_07BA87();
	unk_4804++;
}

void sub_07AF5A(void)
{
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0;

	if (unk_485D != 0u)
		return;
	unk_4875 = 0x8Bu;
	unk_4876 = 0u;
	sub_07C931();
	io_write8(IO_1FB9, 0x3Fu);
	io_write8(IO_1FBA, 0x36u);
	d = 0x26u;
	sub_07C4A3(d, &ignored16, &ignored16_2, &ignored16_3);
	d = 0x126u;
	sub_07C4A3(d, &ignored16, &ignored16_2, &ignored16_3);
	unk_48C5 = 0xFF30u;
	unk_480A = 1u;
	unk_480B = 0x80u;
	unk_4804++;
}

void sub_07AF97(uint16_t y)
{
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, ignored16_4 = 0;
	uint16_t t1 = 0;
	uint32_t unk_480A_halfword = 0;

	d = 0xD000u | b;
	sub_079784(d, &ignored16, &carry);
	if (carry == 0u)
	{
		io_write8(IO_1FB9, 0x13u);
		io_write8(IO_1FBA, 0x2Cu);
		t1 = (((uint32_t)unk_480A << 8u) | unk_480B);
		unk_480A_halfword = t1 - 1u;
		unk_480A = (uint8_t)(unk_480A_halfword >> 8u);
		unk_480B = (uint8_t)unk_480A_halfword;
		if (t1 != 1u)
		{
			unk_480E = 0x10u;
			set_lines(unk_480E);
			sub_02000C(y);
			sub_07B70D(&ignored16, &ignored16_3, &ignored16_2, &ignored16_4, &carry);
			return;
		}
	}
	sub_07955F(&ignored16, &ignored16_2);
	io_write8(IO_1FB9, 0x3Fu);
	io_write8(IO_1FBA, 0x36u);
	sub_079275();
	d = 0xFFF0u;
	sub_07B632(d);
	d = 0u;
	sub_07B64C(d);
	unk_4876 = 1u;
	sub_07C931();
	d = 0x26u;
	sub_07C4A3(d, &ignored16, &ignored16_3, &ignored16_2);
	io_write8(IO_1FB9, 0x13u);
	io_write8(IO_1FBA, 0x2Cu);
	d = 0u;
	carry = sub_0797ED(d);
	unk_4804++;
}

void sub_07B00F(uint16_t y)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, ignored16_4 = 0;

	unk_480E = 0x10u;
	set_lines(unk_480E);
	sub_020003(y);
	sub_07B70D(&ignored16, &ignored16_2, &ignored16_3, &ignored16_4, &carry);
}

void sub_07B022(void)
{
	unk_480B++;
	if (unk_480B == 0x40u)
	{
		unk_4885 = unk_4850;
		unk_480B = 0u;
		unk_4804++;
	}
}

void sub_07B039(uint16_t u)
{
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t d = 0, ignored16 = 0;

	d = 0xC000u | b;
	sub_079784(d, &ignored16, &carry);
	if (carry)
	{
		unk_4803++;
		unk_4804 = 0u;
		unk_4805 = 0u;
	}
	else
	{
		unk_4872 = 1u;
		unk_480E = 0x12u;
		set_lines(unk_480E);
		sub_024009(u);
		if (unk_4872 == 0u)
		{
			unk_4803++;
			unk_4804 = 0u;
			unk_4805 = 0u;
			return;
		}
	}
}

uint32_t sub_07B068(uint16_t y, uint16_t u)
{
	uint32_t left_caller = 0;

	switch ((int8_t)(uint8_t)((uint32_t)unk_4804 << 1))
	{
	case 0:
		left_caller = 0u;
		sub_07B071();
		return left_caller;
	case 2:
		left_caller = 0u;
		sub_07B09D(u);
		return left_caller;
	case 4:
		left_caller = 0u;
		return sub_07B0AC(u, left_caller);
	case 6:
		left_caller = 0u;
		sub_07B125();
		return left_caller;
	case 8:
		left_caller = 0u;
		return sub_07B128(y, left_caller);
	case 10:
		left_caller = 0u;
		sub_07B13A();
		return left_caller;
	case 12:
		left_caller = 0u;
		return sub_07B13D(left_caller);
	case 14:
		left_caller = 0u;
		return sub_07B14C(y, u, left_caller);
	case 16:
		left_caller = 0u;
		return sub_07B19B(y, u, left_caller);
	case 18:
		left_caller = 0u;
		sub_07B1E7();
		return left_caller;
	case 20:
		left_caller = 0u;
		sub_07B219(u);
		return left_caller;
	case 22:
		left_caller = 0u;
		sub_07B228(u);
		return left_caller;
	case 24:
		left_caller = 0u;
		return sub_07B245(u, left_caller);
	case 26:
		left_caller = 0u;
		sub_07B2DB();
		return left_caller;
	case 28:
		left_caller = 0u;
		return sub_07B318(y, left_caller);
	case 30:
		left_caller = 0u;
		return sub_07B32A(left_caller);
	case 32:
		left_caller = 0u;
		return sub_07B333(y, u, left_caller);
	case 34:
		left_caller = 0u;
		return sub_07B36F(y, left_caller);
	case 36:
		left_caller = 0u;
		return sub_07B389(y, left_caller);
	case 38:
		left_caller = 0u;
		sub_07B39B();
		return left_caller;
	case 40:
		left_caller = 0u;
		return sub_07B39E(left_caller);
	case 42:
		left_caller = 0u;
		return sub_07B3A1(y, left_caller);
	case 44:
		left_caller = 0u;
		return sub_07B3D5(left_caller);
	case 46:
		left_caller = 0u;
		return sub_07B3DC(u, left_caller);
	case 48:
		left_caller = 0u;
		sub_07B416();
		return left_caller;
	case 50:
		left_caller = 0u;
		sub_07B423(u);
		return left_caller;
	case 52:
		left_caller = 0u;
		sub_07B449();
		return left_caller;
	case 54:
		left_caller = 0u;
		sub_07B470();
		return left_caller;
	case 56:
		left_caller = 0u;
		sub_07B4A1();
		return left_caller;
	case 58:
		left_caller = 0u;
		sub_07B4BF();
		return left_caller;
	case 60:
		left_caller = 0u;
		sub_07B501(u);
		return left_caller;
	case 62:
		left_caller = 0u;
		sub_07B577();
		return left_caller;
	case 64:
		left_caller = 0u;
		sub_07B58C();
		return left_caller;
	case -102:
		left_caller = 0u;
		sub_07A834();
		return left_caller;
	case -100:
		left_caller = 0u;
		sub_07A851();
		return left_caller;
	case -98:
		left_caller = 0u;
		sub_07A876(u);
		return left_caller;
	case -96:
		left_caller = 0u;
		sub_07A8C1();
		return left_caller;
	case -94:
		left_caller = 0u;
		sub_07A8ED(u);
		return left_caller;
	case -92:
		left_caller = 0u;
		return sub_07A8FC(u, left_caller);
	case -90:
		left_caller = 0u;
		sub_07A975();
		return left_caller;
	case -88:
		left_caller = 0u;
		return sub_07A978(y, left_caller);
	case -86:
		left_caller = 0u;
		return sub_07A99B(y, left_caller);
	case -84:
		left_caller = 0u;
		sub_07A9C2();
		return left_caller;
	case -82:
		left_caller = 0u;
		return sub_07A9D2(left_caller);
	case -80:
		return sub_07A9DB();
	case -78:
		left_caller = 0u;
		sub_07AA15();
		return left_caller;
	case -76:
		left_caller = 0u;
		return sub_07AA3E(u, left_caller);
	case -74:
		left_caller = 0u;
		sub_07AAEE();
		return left_caller;
	case -72:
		left_caller = 0u;
		return sub_07AAF1(y, left_caller);
	case -70:
		left_caller = 0u;
		sub_07AB03();
		return left_caller;
	case -68:
		left_caller = 0u;
		return sub_07AB06(left_caller);
	case -66:
		left_caller = 0u;
		return sub_07AB09(y, u, left_caller);
	case -64:
		left_caller = 0u;
		sub_07AB58();
		return left_caller;
	case -62:
		left_caller = 0u;
		sub_07AB84(u);
		return left_caller;
	case -60:
		left_caller = 0u;
		return sub_07AB93(u, left_caller);
	case -58:
		left_caller = 0u;
		sub_07AC0C();
		return left_caller;
	case -56:
		left_caller = 0u;
		return sub_07AC0F(y, left_caller);
	case -54:
		left_caller = 0u;
		sub_07AC21();
		return left_caller;
	case -52:
		left_caller = 0u;
		return sub_07AC24(left_caller);
	case -50:
		left_caller = 0u;
		return sub_07AC27(left_caller);
	case -48:
		left_caller = 0u;
		sub_07AC7D();
		return left_caller;
	case -46:
		left_caller = 0u;
		sub_07ACA9(u);
		return left_caller;
	case -44:
		left_caller = 0u;
		return sub_07ACB8(u, left_caller);
	case -42:
		left_caller = 0u;
		sub_07AD31();
		return left_caller;
	case -40:
		left_caller = 0u;
		return sub_07AD34(y, left_caller);
	case -38:
		left_caller = 0u;
		sub_07AD46();
		return left_caller;
	case -36:
		left_caller = 0u;
		return sub_07AD49(left_caller);
	case -34:
		left_caller = 0u;
		sub_07AD5B(u);
		return left_caller;
	case -32:
		left_caller = 0u;
		sub_07AD8F(u);
		return left_caller;
	case -30:
		left_caller = 0u;
		sub_07ADDB();
		return left_caller;
	case -28:
		left_caller = 0u;
		sub_07AE0B(u);
		return left_caller;
	case -26:
		left_caller = 0u;
		return sub_07AE1A(u, left_caller);
	case -24:
		left_caller = 0u;
		sub_07AE9D();
		return left_caller;
	case -22:
		left_caller = 0u;
		return sub_07AEA2(y, left_caller);
	case -20:
		left_caller = 0u;
		sub_07AEB4();
		return left_caller;
	case -18:
		left_caller = 0u;
		return sub_07AEB9(left_caller);
	case -16:
		left_caller = 0u;
		sub_07AEBE(u);
		return left_caller;
	case -14:
		left_caller = 0u;
		sub_07AEEE(u);
		return left_caller;
	case -12:
		left_caller = 0u;
		sub_07AF2C();
		return left_caller;
	case -10:
		left_caller = 0u;
		sub_07AF5A();
		return left_caller;
	case -8:
		left_caller = 0u;
		sub_07AF97(y);
		return left_caller;
	case -6:
		left_caller = 0u;
		sub_07B00F(y);
		return left_caller;
	case -4:
		left_caller = 0u;
		sub_07B022();
		return left_caller;
	case -2:
		left_caller = 0u;
		sub_07B039(u);
		return left_caller;
	}
	unreachable();
}

void sub_07B071(void)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0;

	unk_486A = 0u;
	sub_0792DD(&ignored16, &ignored16_2);
	sub_079269();
	sub_07960F();
	d = 0u;
	carry = sub_0797ED(d);
	unk_480E = 0x13u;
	set_lines(unk_480E);
	unk_48A4 = stage_slots[7].record;
	sub_07BA87();
	unk_4804++;
}

void sub_07B09D(uint16_t u)
{
	unk_480E = 0x13u;
	set_lines(unk_480E);
	sub_026006(u);
}

uint32_t sub_07B0AC(uint16_t u, uint32_t left_caller)
{
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0;

	d = 0u;
	sub_07B632(d);
	d = 0u;
	sub_07B64C(d);
	sub_07B0B8(&ignored16, &ignored16_2, &u, &left_caller);
	return left_caller;
}

void sub_07B0B8(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, u_2 = 0, x = 0, y = 0;

	unk_487E = 1u;
	d = 0xF8Du;
	sub_07BAC7(d, &ignored16, &u);
	unk_487E = 2u;
	d = 0x29u;
	sub_07BAC7(d, &ignored16, &u);
	sub_07BA93();
	io_write8(IO_1FB9, 0x3Fu);
	io_write8(IO_1FBA, 0x36u);
	unk_4875 = 0x8Cu;
	unk_4876 = 0u;
	sub_07C931();
	d = 0x2Cu;
	sub_07C4A3(d, &ignored16_2, &ignored16, &ignored16_3);
	d = 0x12Cu;
	sub_07C4E1(d, &y, &ignored16_3);
	*p_left_caller = sub_07C954(y, *p_left_caller);
	unk_480E = 0x1Fu;
	set_lines(unk_480E);
	sub_03E057(&x, &y, &u_2);
	io_write8(IO_1FB9, 0x13u);
	io_write8(IO_1FBA, 0x2Cu);
	unk_4885 = unk_4850;
	unk_4804++;
	*p_x = x;
	*p_y = y;
	*p_u = u_2;
}

void sub_07B125(void)
{
	sub_07B5A9();
}

uint32_t sub_07B128(uint16_t y, uint32_t left_caller)
{
	uint16_t ignored16 = 0;

	sub_07B5DD(y, &ignored16, &left_caller);
	if (unk_487C != 0u)
	{
		unk_487C = 0u;
		unk_4880++;
		sub_07BA93();
	}
	return left_caller;
}

void sub_07B13A(void)
{
	sub_07B666();
}

uint32_t sub_07B13D(uint32_t left_caller)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;

	sub_07B676(&ignored16, &left_caller, &carry);
	if (carry)
		unk_48A4 += 4u;
	return left_caller;
}

uint32_t sub_07B14C(uint16_t y, uint16_t u, uint32_t left_caller)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, ignored16_4 = 0, x = 0, y_2 = 0;

	unk_4872 = 1u;
	unk_480E = 0x12u;
	set_lines(unk_480E);
	sub_02400C(&y, &u);
	unk_480E = 0x1Fu;
	set_lines(unk_480E);
	sub_03E03C(&y, &u);
	sub_07CB9F(&y, &u, &left_caller);
	u = sub_07CBD2(u);
	if (unk_4872 != 0u)
	{
		unk_480E = 0x13u;
		set_lines(unk_480E);
		sub_026009(u);
		sub_07B70D(&ignored16, &ignored16_2, &ignored16_3, &ignored16_4, &carry);
		return left_caller;
	}
	y_2 = VIDEO_18E0;
	x = VIDEO_18E1;
	io_write8(VIDEO_18E0, 0u);
	u = 0x1Fu;
	while (u != 0u)
	{
		mem_write8(x, mem_read8(y_2));
		y_2++;
		x++;
		u--;
	}
	unk_4804++;
	unk_480E = 0x13u;
	set_lines(unk_480E);
	sub_026009(u);
	sub_07B70D(&ignored16, &ignored16_2, &ignored16_3, &ignored16_4, &carry);
	return left_caller;
}

uint32_t sub_07B19B(uint16_t y, uint16_t u, uint32_t left_caller)
{
	uint16_t d = 0, ignored16 = 0;

	unk_4872 = 1u;
	unk_480E = 0x12u;
	set_lines(unk_480E);
	sub_02400F(&y, &u);
	sub_07CB9F(&y, &u, &left_caller);
	u = sub_07CBD2(u);
	if (unk_4872 == 0u)
	{
		unk_4803++;
		unk_4804 = 0u;
		unk_4805 = 0u;
		unk_487E = 3u;
		d = 0u;
		sub_07BAC7(d, &ignored16, &u);
	}
	return left_caller;
}

void sub_07B1D4(void)
{
	unk_486A = 0u;
	sub_07BA87();
	unk_4803++;
}

uint32_t sub_07B1DE(uint16_t y, uint16_t u)
{
	uint32_t left_caller = 0;

	switch ((int8_t)(uint8_t)((uint32_t)unk_4804 << 1))
	{
	case 0:
		left_caller = 0u;
		sub_07B1E7();
		return left_caller;
	case 2:
		left_caller = 0u;
		sub_07B219(u);
		return left_caller;
	case 4:
		left_caller = 0u;
		sub_07B228(u);
		return left_caller;
	case 6:
		left_caller = 0u;
		return sub_07B245(u, left_caller);
	case 8:
		left_caller = 0u;
		sub_07B2DB();
		return left_caller;
	case 10:
		left_caller = 0u;
		return sub_07B318(y, left_caller);
	case 12:
		left_caller = 0u;
		return sub_07B32A(left_caller);
	case 14:
		left_caller = 0u;
		return sub_07B333(y, u, left_caller);
	case 16:
		left_caller = 0u;
		return sub_07B36F(y, left_caller);
	case 18:
		left_caller = 0u;
		return sub_07B389(y, left_caller);
	case 20:
		left_caller = 0u;
		sub_07B39B();
		return left_caller;
	case 22:
		left_caller = 0u;
		return sub_07B39E(left_caller);
	case 24:
		left_caller = 0u;
		return sub_07B3A1(y, left_caller);
	case 26:
		left_caller = 0u;
		return sub_07B3D5(left_caller);
	case 28:
		left_caller = 0u;
		return sub_07B3DC(u, left_caller);
	case 30:
		left_caller = 0u;
		sub_07B416();
		return left_caller;
	case 32:
		left_caller = 0u;
		sub_07B423(u);
		return left_caller;
	case 34:
		left_caller = 0u;
		sub_07B449();
		return left_caller;
	case 36:
		left_caller = 0u;
		sub_07B470();
		return left_caller;
	case 38:
		left_caller = 0u;
		sub_07B4A1();
		return left_caller;
	case 40:
		left_caller = 0u;
		sub_07B4BF();
		return left_caller;
	case 42:
		left_caller = 0u;
		sub_07B501(u);
		return left_caller;
	case 44:
		left_caller = 0u;
		sub_07B577();
		return left_caller;
	case 46:
		left_caller = 0u;
		sub_07B58C();
		return left_caller;
	case -120:
		left_caller = 0u;
		sub_07A834();
		return left_caller;
	case -118:
		left_caller = 0u;
		sub_07A851();
		return left_caller;
	case -116:
		left_caller = 0u;
		sub_07A876(u);
		return left_caller;
	case -114:
		left_caller = 0u;
		sub_07A8C1();
		return left_caller;
	case -112:
		left_caller = 0u;
		sub_07A8ED(u);
		return left_caller;
	case -110:
		left_caller = 0u;
		return sub_07A8FC(u, left_caller);
	case -108:
		left_caller = 0u;
		sub_07A975();
		return left_caller;
	case -106:
		left_caller = 0u;
		return sub_07A978(y, left_caller);
	case -104:
		left_caller = 0u;
		return sub_07A99B(y, left_caller);
	case -102:
		left_caller = 0u;
		sub_07A9C2();
		return left_caller;
	case -100:
		left_caller = 0u;
		return sub_07A9D2(left_caller);
	case -98:
		return sub_07A9DB();
	case -96:
		left_caller = 0u;
		sub_07AA15();
		return left_caller;
	case -94:
		left_caller = 0u;
		return sub_07AA3E(u, left_caller);
	case -92:
		left_caller = 0u;
		sub_07AAEE();
		return left_caller;
	case -90:
		left_caller = 0u;
		return sub_07AAF1(y, left_caller);
	case -88:
		left_caller = 0u;
		sub_07AB03();
		return left_caller;
	case -86:
		left_caller = 0u;
		return sub_07AB06(left_caller);
	case -84:
		left_caller = 0u;
		return sub_07AB09(y, u, left_caller);
	case -82:
		left_caller = 0u;
		sub_07AB58();
		return left_caller;
	case -80:
		left_caller = 0u;
		sub_07AB84(u);
		return left_caller;
	case -78:
		left_caller = 0u;
		return sub_07AB93(u, left_caller);
	case -76:
		left_caller = 0u;
		sub_07AC0C();
		return left_caller;
	case -74:
		left_caller = 0u;
		return sub_07AC0F(y, left_caller);
	case -72:
		left_caller = 0u;
		sub_07AC21();
		return left_caller;
	case -70:
		left_caller = 0u;
		return sub_07AC24(left_caller);
	case -68:
		left_caller = 0u;
		return sub_07AC27(left_caller);
	case -66:
		left_caller = 0u;
		sub_07AC7D();
		return left_caller;
	case -64:
		left_caller = 0u;
		sub_07ACA9(u);
		return left_caller;
	case -62:
		left_caller = 0u;
		return sub_07ACB8(u, left_caller);
	case -60:
		left_caller = 0u;
		sub_07AD31();
		return left_caller;
	case -58:
		left_caller = 0u;
		return sub_07AD34(y, left_caller);
	case -56:
		left_caller = 0u;
		sub_07AD46();
		return left_caller;
	case -54:
		left_caller = 0u;
		return sub_07AD49(left_caller);
	case -52:
		left_caller = 0u;
		sub_07AD5B(u);
		return left_caller;
	case -50:
		left_caller = 0u;
		sub_07AD8F(u);
		return left_caller;
	case -48:
		left_caller = 0u;
		sub_07ADDB();
		return left_caller;
	case -46:
		left_caller = 0u;
		sub_07AE0B(u);
		return left_caller;
	case -44:
		left_caller = 0u;
		return sub_07AE1A(u, left_caller);
	case -42:
		left_caller = 0u;
		sub_07AE9D();
		return left_caller;
	case -40:
		left_caller = 0u;
		return sub_07AEA2(y, left_caller);
	case -38:
		left_caller = 0u;
		sub_07AEB4();
		return left_caller;
	case -36:
		left_caller = 0u;
		return sub_07AEB9(left_caller);
	case -34:
		left_caller = 0u;
		sub_07AEBE(u);
		return left_caller;
	case -32:
		left_caller = 0u;
		sub_07AEEE(u);
		return left_caller;
	case -30:
		left_caller = 0u;
		sub_07AF2C();
		return left_caller;
	case -28:
		left_caller = 0u;
		sub_07AF5A();
		return left_caller;
	case -26:
		left_caller = 0u;
		sub_07AF97(y);
		return left_caller;
	case -24:
		left_caller = 0u;
		sub_07B00F(y);
		return left_caller;
	case -22:
		left_caller = 0u;
		sub_07B022();
		return left_caller;
	case -20:
		left_caller = 0u;
		sub_07B039(u);
		return left_caller;
	case -18:
		left_caller = 0u;
		sub_07B071();
		return left_caller;
	case -16:
		left_caller = 0u;
		sub_07B09D(u);
		return left_caller;
	case -14:
		left_caller = 0u;
		return sub_07B0AC(u, left_caller);
	case -12:
		left_caller = 0u;
		sub_07B125();
		return left_caller;
	case -10:
		left_caller = 0u;
		return sub_07B128(y, left_caller);
	case -8:
		left_caller = 0u;
		sub_07B13A();
		return left_caller;
	case -6:
		left_caller = 0u;
		return sub_07B13D(left_caller);
	case -4:
		left_caller = 0u;
		return sub_07B14C(y, u, left_caller);
	case -2:
		left_caller = 0u;
		return sub_07B19B(y, u, left_caller);
	}
	unreachable();
}

void sub_07B1E7(void)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0;

	unk_486A = 0u;
	sub_0792DD(&ignored16, &ignored16_2);
	sub_079269();
	sub_07960F();
	d = 0u;
	carry = sub_0797ED(d);
	unk_480E = 0x13u;
	set_lines(unk_480E);
	unk_48A4 = stage_slots[8].record;
	sub_07BA87();
	unk_4885 = unk_4850;
	unk_4804++;
}

void sub_07B219(uint16_t u)
{
	unk_480E = 0x13u;
	set_lines(unk_480E);
	sub_026006(u);
}

void sub_07B228(uint16_t u)
{
	unk_4872 = 1u;
	unk_480E = 0x12u;
	set_lines(unk_480E);
	sub_024018(u);
	if (unk_4872 == 0u)
		unk_4804++;
}

uint32_t sub_07B245(uint16_t u, uint32_t left_caller)
{
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, y = 0;

	d = 0u;
	sub_07B632(d);
	d = 0u;
	sub_07B64C(d);
	unk_487E = 1u;
	d = 0x880u;
	sub_07BAC7(d, &ignored16, &u);
	unk_487E = 1u;
	d = 0xF8Eu;
	sub_07BAC7(d, &ignored16, &u);
	unk_487E = 1u;
	d = 0x892u;
	sub_07BAC7(d, &ignored16, &u);
	unk_487E = 2u;
	d = 0x3Du;
	sub_07BAC7(d, &ignored16, &u);
	unk_487E = 2u;
	d = 0x3Eu;
	sub_07BAC7(d, &ignored16, &u);
	sub_07BA93();
	io_write8(IO_1FB9, 0x3Fu);
	io_write8(IO_1FBA, 0x36u);
	unk_4875 = 0x8Du;
	unk_4876 = 1u;
	sub_07C931();
	d = 0x2Cu;
	sub_07C4A3(d, &ignored16_2, &ignored16, &ignored16_3);
	d = 0x12Cu;
	sub_07C4E1(d, &y, &ignored16_3);
	left_caller = sub_07C954(y, left_caller);
	unk_480E = 0x1Fu;
	set_lines(unk_480E);
	sub_03E057(&ignored16_2, &ignored16, &ignored16_3);
	io_write8(IO_1FB9, 0x13u);
	io_write8(IO_1FBA, 0x2Cu);
	unk_4804++;
	return left_caller;
}

void sub_07B2DB(void)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, ignored16_4 = 0, u = 0;

	sub_07C985();
	u = sub_07B5A9();
	if (unk_4872 != 0u)
	{
		unk_480E = 0x13u;
		set_lines(unk_480E);
		sub_026009(u);
		sub_07B70D(&ignored16, &ignored16_2, &ignored16_3, &ignored16_4, &carry);
		return;
	}
	unk_4880++;
	sub_07BA93();
	unk_48C3 = 0u;
	unk_48D3 = 0u;
	unk_48CA = 0u;
	unk_48DA = 0u;
	d = 0x40u;
	sub_07C4A3(d, &ignored16, &ignored16_2, &ignored16_3);
	d = 0x140u;
	sub_07C4E1(d, &ignored16_2, &u);
	unk_480E = 0x13u;
	set_lines(unk_480E);
	sub_026009(u);
	sub_07B70D(&ignored16, &ignored16_2, &ignored16_3, &ignored16_4, &carry);
}

uint32_t sub_07B318(uint16_t y, uint32_t left_caller)
{
	uint16_t ignored16 = 0;

	sub_07B5DD(y, &ignored16, &left_caller);
	if (unk_487C != 0u)
	{
		unk_487C = 0u;
		unk_4880++;
		sub_07BA93();
	}
	return left_caller;
}

uint32_t sub_07B32A(uint32_t left_caller)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;

	io_write8(VIDEO_184B, 1u);
	sub_07B676(&ignored16, &left_caller, &carry);
	return left_caller;
}

uint32_t sub_07B333(uint16_t y, uint16_t u, uint32_t left_caller)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, ignored16_4 = 0;

	unk_487D = 0u;
	unk_4872 = 1u;
	unk_480E = 0x1Fu;
	set_lines(unk_480E);
	sub_03E054(&y, &u);
	if (unk_4872 == 0u)
	{
		unk_4881 = 1u;
		unk_4804++;
	}
	sub_07CB9F(&y, &u, &left_caller);
	u = sub_07CBD2(u);
	unk_480E = 0x13u;
	set_lines(unk_480E);
	sub_026009(u);
	sub_07B70D(&ignored16, &ignored16_2, &ignored16_3, &ignored16_4, &carry);
	return left_caller;
}

uint32_t sub_07B36F(uint16_t y, uint32_t left_caller)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, ignored16_4 = 0;

	if (unk_487C != 0u)
	{
		unk_487C = 0u;
		unk_4880++;
		sub_07BA93();
	}
	sub_07CB9F(&y, &ignored16, &left_caller);
	left_caller = sub_07CB3C(y, left_caller);
	sub_07CBD2(ignored16);
	sub_07B70D(&ignored16_2, &ignored16_3, &ignored16, &ignored16_4, &carry);
	return left_caller;
}

uint32_t sub_07B389(uint16_t y, uint32_t left_caller)
{
	uint16_t ignored16 = 0;

	sub_07B5DD(y, &ignored16, &left_caller);
	if (unk_487C != 0u)
	{
		unk_487C = 0u;
		unk_4880++;
		sub_07BA93();
	}
	return left_caller;
}

void sub_07B39B(void)
{
	sub_07B666();
}

uint32_t sub_07B39E(uint32_t left_caller)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;

	sub_07B676(&ignored16, &left_caller, &carry);
	return left_caller;
}

uint32_t sub_07B3A1(uint16_t y, uint32_t left_caller)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, ignored16_4 = 0, u = 0;

	unk_4872 = 1u;
	unk_480E = 0x1Fu;
	set_lines(unk_480E);
	sub_03E051(&y, &u);
	sub_07CB9F(&y, &u, &left_caller);
	u = sub_07CBD2(u);
	if (unk_4872 == 0u)
		unk_4804++;
	unk_480E = 0x13u;
	set_lines(unk_480E);
	sub_026009(u);
	sub_07B70D(&ignored16, &ignored16_2, &ignored16_3, &ignored16_4, &carry);
	return left_caller;
}

uint32_t sub_07B3D5(uint32_t left_caller)
{
	uint16_t ignored16 = 0, ignored16_2 = 0;

	sub_07CB9F(&ignored16, &ignored16_2, &left_caller);
	sub_07CBD2(ignored16_2);
	return left_caller;
}

uint32_t sub_07B3DC(uint16_t u, uint32_t left_caller)
{
	uint16_t ignored16 = 0, ignored16_2 = 0;

	unk_4872 = 1u;
	unk_480E = 0x12u;
	set_lines(unk_480E);
	sub_024012(u);
	sub_07CB9F(&ignored16, &ignored16_2, &left_caller);
	sub_07CBD2(ignored16_2);
	if (unk_4872 == 0u)
	{
		unk_4803++;
		unk_4804 = 0u;
		unk_4805 = 0u;
	}
	return left_caller;
}

uint32_t sub_07B40A(uint16_t y, uint16_t u)
{
	uint32_t left_caller = 0;

	unk_486A = 0u;
	switch ((int8_t)(uint8_t)((uint32_t)unk_4804 << 1))
	{
	case 0:
		left_caller = 0u;
		sub_07B416();
		return left_caller;
	case 2:
		left_caller = 0u;
		sub_07B423(u);
		return left_caller;
	case 4:
		left_caller = 0u;
		sub_07B449();
		return left_caller;
	case 6:
		left_caller = 0u;
		sub_07B470();
		return left_caller;
	case 8:
		left_caller = 0u;
		sub_07B4A1();
		return left_caller;
	case 10:
		left_caller = 0u;
		sub_07B4BF();
		return left_caller;
	case 12:
		left_caller = 0u;
		sub_07B501(u);
		return left_caller;
	case 14:
		left_caller = 0u;
		sub_07B577();
		return left_caller;
	case 16:
		left_caller = 0u;
		sub_07B58C();
		return left_caller;
	case -128:
		return sub_07A9DB();
	case -126:
		left_caller = 0u;
		sub_07AA15();
		return left_caller;
	case -124:
		left_caller = 0u;
		return sub_07AA3E(u, left_caller);
	case -122:
		left_caller = 0u;
		sub_07AAEE();
		return left_caller;
	case -120:
		left_caller = 0u;
		return sub_07AAF1(y, left_caller);
	case -118:
		left_caller = 0u;
		sub_07AB03();
		return left_caller;
	case -116:
		left_caller = 0u;
		return sub_07AB06(left_caller);
	case -114:
		left_caller = 0u;
		return sub_07AB09(y, u, left_caller);
	case -112:
		left_caller = 0u;
		sub_07AB58();
		return left_caller;
	case -110:
		left_caller = 0u;
		sub_07AB84(u);
		return left_caller;
	case -108:
		left_caller = 0u;
		return sub_07AB93(u, left_caller);
	case -106:
		left_caller = 0u;
		sub_07AC0C();
		return left_caller;
	case -104:
		left_caller = 0u;
		return sub_07AC0F(y, left_caller);
	case -102:
		left_caller = 0u;
		sub_07AC21();
		return left_caller;
	case -100:
		left_caller = 0u;
		return sub_07AC24(left_caller);
	case -98:
		left_caller = 0u;
		return sub_07AC27(left_caller);
	case -96:
		left_caller = 0u;
		sub_07AC7D();
		return left_caller;
	case -94:
		left_caller = 0u;
		sub_07ACA9(u);
		return left_caller;
	case -92:
		left_caller = 0u;
		return sub_07ACB8(u, left_caller);
	case -90:
		left_caller = 0u;
		sub_07AD31();
		return left_caller;
	case -88:
		left_caller = 0u;
		return sub_07AD34(y, left_caller);
	case -86:
		left_caller = 0u;
		sub_07AD46();
		return left_caller;
	case -84:
		left_caller = 0u;
		return sub_07AD49(left_caller);
	case -82:
		left_caller = 0u;
		sub_07AD5B(u);
		return left_caller;
	case -80:
		left_caller = 0u;
		sub_07AD8F(u);
		return left_caller;
	case -78:
		left_caller = 0u;
		sub_07ADDB();
		return left_caller;
	case -76:
		left_caller = 0u;
		sub_07AE0B(u);
		return left_caller;
	case -74:
		left_caller = 0u;
		return sub_07AE1A(u, left_caller);
	case -72:
		left_caller = 0u;
		sub_07AE9D();
		return left_caller;
	case -70:
		left_caller = 0u;
		return sub_07AEA2(y, left_caller);
	case -68:
		left_caller = 0u;
		sub_07AEB4();
		return left_caller;
	case -66:
		left_caller = 0u;
		return sub_07AEB9(left_caller);
	case -64:
		left_caller = 0u;
		sub_07AEBE(u);
		return left_caller;
	case -62:
		left_caller = 0u;
		sub_07AEEE(u);
		return left_caller;
	case -60:
		left_caller = 0u;
		sub_07AF2C();
		return left_caller;
	case -58:
		left_caller = 0u;
		sub_07AF5A();
		return left_caller;
	case -56:
		left_caller = 0u;
		sub_07AF97(y);
		return left_caller;
	case -54:
		left_caller = 0u;
		sub_07B00F(y);
		return left_caller;
	case -52:
		left_caller = 0u;
		sub_07B022();
		return left_caller;
	case -50:
		left_caller = 0u;
		sub_07B039(u);
		return left_caller;
	case -48:
		left_caller = 0u;
		sub_07B071();
		return left_caller;
	case -46:
		left_caller = 0u;
		sub_07B09D(u);
		return left_caller;
	case -44:
		left_caller = 0u;
		return sub_07B0AC(u, left_caller);
	case -42:
		left_caller = 0u;
		sub_07B125();
		return left_caller;
	case -40:
		left_caller = 0u;
		return sub_07B128(y, left_caller);
	case -38:
		left_caller = 0u;
		sub_07B13A();
		return left_caller;
	case -36:
		left_caller = 0u;
		return sub_07B13D(left_caller);
	case -34:
		left_caller = 0u;
		return sub_07B14C(y, u, left_caller);
	case -32:
		left_caller = 0u;
		return sub_07B19B(y, u, left_caller);
	case -30:
		left_caller = 0u;
		sub_07B1E7();
		return left_caller;
	case -28:
		left_caller = 0u;
		sub_07B219(u);
		return left_caller;
	case -26:
		left_caller = 0u;
		sub_07B228(u);
		return left_caller;
	case -24:
		left_caller = 0u;
		return sub_07B245(u, left_caller);
	case -22:
		left_caller = 0u;
		sub_07B2DB();
		return left_caller;
	case -20:
		left_caller = 0u;
		return sub_07B318(y, left_caller);
	case -18:
		left_caller = 0u;
		return sub_07B32A(left_caller);
	case -16:
		left_caller = 0u;
		return sub_07B333(y, u, left_caller);
	case -14:
		left_caller = 0u;
		return sub_07B36F(y, left_caller);
	case -12:
		left_caller = 0u;
		return sub_07B389(y, left_caller);
	case -10:
		left_caller = 0u;
		sub_07B39B();
		return left_caller;
	case -8:
		left_caller = 0u;
		return sub_07B39E(left_caller);
	case -6:
		left_caller = 0u;
		return sub_07B3A1(y, left_caller);
	case -4:
		left_caller = 0u;
		return sub_07B3D5(left_caller);
	case -2:
		left_caller = 0u;
		return sub_07B3DC(u, left_caller);
	}
	unreachable();
}

void sub_07B416(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0;

	sub_0792DD(&ignored16, &ignored16_2);
	sub_079269();
	sub_07960F();
	unk_4804++;
}

void sub_07B423(uint16_t u)
{
	uint16_t d = 0;

	unk_4872 = 1u;
	unk_480E = 0x11u;
	set_lines(unk_480E);
	sub_022006(u);
	if (unk_4872 != 0u)
		return;
	unk_486A = 0u;
	d = 0u;
	sub_0797B7(d);
	unk_4804++;
}

void sub_07B449(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0;

	unk_486A = 0u;
	if (unk_485D != 0u)
		return;
	sub_07955F(&ignored16, &ignored16_2);
	sub_07B4C4();
}

void sub_07B458(void)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, u = 0;

	unk_4879 = 1u;
	sub_07B70D(&ignored16, &ignored16_2, &u, &ignored16_3, &carry);
	sub_07B8B0(u);
}

uint32_t sub_07B464(uint16_t y, uint16_t u, uint32_t left_caller)
{
	unk_486A = 0u;
	switch ((int8_t)(uint8_t)((uint32_t)unk_4803 << 1))
	{
	case 0:
		sub_07B470();
		return left_caller;
	case 2:
		sub_07B4A1();
		return left_caller;
	case 4:
		sub_07B4BF();
		return left_caller;
	case 6:
		sub_07B501(u);
		return left_caller;
	case 8:
		sub_07B577();
		return left_caller;
	case 10:
		sub_07B58C();
		return left_caller;
	case -128:
		sub_07AAEE();
		return left_caller;
	case -126:
		return sub_07AAF1(y, left_caller);
	case -124:
		sub_07AB03();
		return left_caller;
	case -122:
		return sub_07AB06(left_caller);
	case -120:
		return sub_07AB09(y, u, left_caller);
	case -118:
		sub_07AB58();
		return left_caller;
	case -116:
		sub_07AB84(u);
		return left_caller;
	case -114:
		return sub_07AB93(u, left_caller);
	case -112:
		sub_07AC0C();
		return left_caller;
	case -110:
		return sub_07AC0F(y, left_caller);
	case -108:
		sub_07AC21();
		return left_caller;
	case -106:
		return sub_07AC24(left_caller);
	case -104:
		return sub_07AC27(left_caller);
	case -102:
		sub_07AC7D();
		return left_caller;
	case -100:
		sub_07ACA9(u);
		return left_caller;
	case -98:
		return sub_07ACB8(u, left_caller);
	case -96:
		sub_07AD31();
		return left_caller;
	case -94:
		return sub_07AD34(y, left_caller);
	case -92:
		sub_07AD46();
		return left_caller;
	case -90:
		return sub_07AD49(left_caller);
	case -88:
		sub_07AD5B(u);
		return left_caller;
	case -86:
		sub_07AD8F(u);
		return left_caller;
	case -84:
		sub_07ADDB();
		return left_caller;
	case -82:
		sub_07AE0B(u);
		return left_caller;
	case -80:
		return sub_07AE1A(u, left_caller);
	case -78:
		sub_07AE9D();
		return left_caller;
	case -76:
		return sub_07AEA2(y, left_caller);
	case -74:
		sub_07AEB4();
		return left_caller;
	case -72:
		return sub_07AEB9(left_caller);
	case -70:
		sub_07AEBE(u);
		return left_caller;
	case -68:
		sub_07AEEE(u);
		return left_caller;
	case -66:
		sub_07AF2C();
		return left_caller;
	case -64:
		sub_07AF5A();
		return left_caller;
	case -62:
		sub_07AF97(y);
		return left_caller;
	case -60:
		sub_07B00F(y);
		return left_caller;
	case -58:
		sub_07B022();
		return left_caller;
	case -56:
		sub_07B039(u);
		return left_caller;
	case -54:
		sub_07B071();
		return left_caller;
	case -52:
		sub_07B09D(u);
		return left_caller;
	case -50:
		return sub_07B0AC(u, left_caller);
	case -48:
		sub_07B125();
		return left_caller;
	case -46:
		return sub_07B128(y, left_caller);
	case -44:
		sub_07B13A();
		return left_caller;
	case -42:
		return sub_07B13D(left_caller);
	case -40:
		return sub_07B14C(y, u, left_caller);
	case -38:
		return sub_07B19B(y, u, left_caller);
	case -36:
		sub_07B1E7();
		return left_caller;
	case -34:
		sub_07B219(u);
		return left_caller;
	case -32:
		sub_07B228(u);
		return left_caller;
	case -30:
		return sub_07B245(u, left_caller);
	case -28:
		sub_07B2DB();
		return left_caller;
	case -26:
		return sub_07B318(y, left_caller);
	case -24:
		return sub_07B32A(left_caller);
	case -22:
		return sub_07B333(y, u, left_caller);
	case -20:
		return sub_07B36F(y, left_caller);
	case -18:
		return sub_07B389(y, left_caller);
	case -16:
		sub_07B39B();
		return left_caller;
	case -14:
		return sub_07B39E(left_caller);
	case -12:
		return sub_07B3A1(y, left_caller);
	case -10:
		return sub_07B3D5(left_caller);
	case -8:
		return sub_07B3DC(u, left_caller);
	case -6:
		sub_07B416();
		return left_caller;
	case -4:
		sub_07B423(u);
		return left_caller;
	case -2:
		sub_07B449();
		return left_caller;
	}
	unreachable();
}

void sub_07B470(void)
{
	uint8_t a = 0;
	uint16_t d = 0, ignored16 = 0, u = 0, x = 0, y = 0;

	a = 0u;
	do
	{
		a++;
	} while (a != 4u);
	d = 1u;
	sub_0797B7(d);
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
	unk_487E = 2u;
	d = 0xBu;
	sub_07BAC7(d, &ignored16, &u);
	unk_487E = 4u;
	d = VIDEO_1E80;
	sub_07BAC7(d, &ignored16, &u);
	unk_4803++;
}

void sub_07B4A1(void)
{
	if (unk_485D != 0u)
		return;
	unk_480E = 0x20u;
	set_lines(unk_480E);
	sub_04000C();
	unk_480A = 1u;
	unk_480B = 0x80u;
	unk_4803++;
}

void sub_07B4BF(void)
{
	uint16_t t1 = 0;
	uint32_t unk_480A_halfword = 0;

	t1 = (((uint32_t)unk_480A << 8u) | unk_480B);
	unk_480A_halfword = t1 - 1u;
	unk_480A = (uint8_t)(unk_480A_halfword >> 8u);
	unk_480B = (uint8_t)unk_480A_halfword;
	if (t1 != 1u)
		return;
	sub_07B4C4();
}

void sub_07B4C4(void)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, x = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = io_read8(VIDEO_1C80);
	io_write8(VIDEO_1C80, 0u);
	sub_0792DD(&ignored16, &ignored16_2);
	sub_079269();
	x = unk_49D4_ADDRESS;
	unk_48F0 = 4u;
	do
	{
		d = mem_read16(x);
		sub_079718(&d, &carry);
		if (carry)
		{
			sub_07960F();
			unk_4802 = 4u;
			unk_4803 = 0u;
			return;
		}
		x += 8u;
		t2 = unk_48F0;
		unk_48F0 = t2 - 1u;
	} while (t2 != 1u);
	sub_07B6A6();
}

uint32_t sub_07B4F5(uint16_t y, uint16_t u, uint32_t left_caller)
{
	unk_486A = 0u;
	switch ((int8_t)(uint8_t)((uint32_t)unk_4803 << 1))
	{
	case 0:
		sub_07B501(u);
		return left_caller;
	case 2:
		sub_07B577();
		return left_caller;
	case 4:
		sub_07B58C();
		return left_caller;
	case -128:
		return sub_07AB06(left_caller);
	case -126:
		return sub_07AB09(y, u, left_caller);
	case -124:
		sub_07AB58();
		return left_caller;
	case -122:
		sub_07AB84(u);
		return left_caller;
	case -120:
		return sub_07AB93(u, left_caller);
	case -118:
		sub_07AC0C();
		return left_caller;
	case -116:
		return sub_07AC0F(y, left_caller);
	case -114:
		sub_07AC21();
		return left_caller;
	case -112:
		return sub_07AC24(left_caller);
	case -110:
		return sub_07AC27(left_caller);
	case -108:
		sub_07AC7D();
		return left_caller;
	case -106:
		sub_07ACA9(u);
		return left_caller;
	case -104:
		return sub_07ACB8(u, left_caller);
	case -102:
		sub_07AD31();
		return left_caller;
	case -100:
		return sub_07AD34(y, left_caller);
	case -98:
		sub_07AD46();
		return left_caller;
	case -96:
		return sub_07AD49(left_caller);
	case -94:
		sub_07AD5B(u);
		return left_caller;
	case -92:
		sub_07AD8F(u);
		return left_caller;
	case -90:
		sub_07ADDB();
		return left_caller;
	case -88:
		sub_07AE0B(u);
		return left_caller;
	case -86:
		return sub_07AE1A(u, left_caller);
	case -84:
		sub_07AE9D();
		return left_caller;
	case -82:
		return sub_07AEA2(y, left_caller);
	case -80:
		sub_07AEB4();
		return left_caller;
	case -78:
		return sub_07AEB9(left_caller);
	case -76:
		sub_07AEBE(u);
		return left_caller;
	case -74:
		sub_07AEEE(u);
		return left_caller;
	case -72:
		sub_07AF2C();
		return left_caller;
	case -70:
		sub_07AF5A();
		return left_caller;
	case -68:
		sub_07AF97(y);
		return left_caller;
	case -66:
		sub_07B00F(y);
		return left_caller;
	case -64:
		sub_07B022();
		return left_caller;
	case -62:
		sub_07B039(u);
		return left_caller;
	case -60:
		sub_07B071();
		return left_caller;
	case -58:
		sub_07B09D(u);
		return left_caller;
	case -56:
		return sub_07B0AC(u, left_caller);
	case -54:
		sub_07B125();
		return left_caller;
	case -52:
		return sub_07B128(y, left_caller);
	case -50:
		sub_07B13A();
		return left_caller;
	case -48:
		return sub_07B13D(left_caller);
	case -46:
		return sub_07B14C(y, u, left_caller);
	case -44:
		return sub_07B19B(y, u, left_caller);
	case -42:
		sub_07B1E7();
		return left_caller;
	case -40:
		sub_07B219(u);
		return left_caller;
	case -38:
		sub_07B228(u);
		return left_caller;
	case -36:
		return sub_07B245(u, left_caller);
	case -34:
		sub_07B2DB();
		return left_caller;
	case -32:
		return sub_07B318(y, left_caller);
	case -30:
		return sub_07B32A(left_caller);
	case -28:
		return sub_07B333(y, u, left_caller);
	case -26:
		return sub_07B36F(y, left_caller);
	case -24:
		return sub_07B389(y, left_caller);
	case -22:
		sub_07B39B();
		return left_caller;
	case -20:
		return sub_07B39E(left_caller);
	case -18:
		return sub_07B3A1(y, left_caller);
	case -16:
		return sub_07B3D5(left_caller);
	case -14:
		return sub_07B3DC(u, left_caller);
	case -12:
		sub_07B416();
		return left_caller;
	case -10:
		sub_07B423(u);
		return left_caller;
	case -8:
		sub_07B449();
		return left_caller;
	case -6:
		sub_07B470();
		return left_caller;
	case -4:
		sub_07B4A1();
		return left_caller;
	case -2:
		sub_07B4BF();
		return left_caller;
	}
	unreachable();
}

void sub_07B501(uint16_t u)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0;

	d = 0x9000u;
	carry = sub_0797ED(d);
	unk_4879 = 0u;
	d = 0xFFF0u;
	sub_07B632(d);
	d = 0u;
	sub_07B64C(d);
	unk_487E = 1u;
	d = 0x70Du;
	sub_07BAC7(d, &ignored16, &u);
	unk_487E = 1u;
	d = 0x880u;
	sub_07BAC7(d, &ignored16, &u);
	unk_487E = 1u;
	d = 0x886u;
	sub_07BAC7(d, &ignored16, &u);
	unk_487E = 3u;
	d = 0x3E36u;
	sub_07BAC7(d, &ignored16, &u);
	unk_4875 = 3u;
	unk_4876 = 0u;
	sub_07C931();
	io_write8(IO_1FB9, 0x3Fu);
	io_write8(IO_1FBA, 0x36u);
	d = 0x2Cu;
	sub_07C4A3(d, &ignored16_2, &ignored16, &ignored16_3);
	io_write8(IO_1FB9, 0x13u);
	io_write8(IO_1FBA, 0x2Cu);
	unk_4803++;
}

void sub_07B577(void)
{
	uint32_t carry = 0;

	unk_480E = 0x11u;
	set_lines(unk_480E);
	carry = sub_022003();
	if (carry)
		unk_4803++;
}

void sub_07B58C(void)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, u = 0;

	sub_0792DD(&ignored16, &ignored16_2);
	d = 0u;
	carry = sub_0797ED(d);
	u = sub_07B6A6();
	unk_487E = 3u;
	d = 0u;
	sub_07BAC7(d, &ignored16_2, &u);
	unk_4801 = 3u;
}

uint16_t sub_07B5A9(void)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, ignored16_4 = 0, u = 0;
	uint16_t t1 = 0;

	if (unk_4811 != 0u)
	{
		unk_4804++;
		sub_07C016(&ignored16, &ignored16_2);
		sub_07B70D(&ignored16_3, &ignored16_4, &u, &ignored16_2, &carry);
		return u;
	}
	unk_4872 = 1u;
	sub_07CBD2(0u);
	t1 = scene_routines_ADDRESS + (int8_t)(((uint32_t)unk_4867 << 1) << 1);
	unk_480E = SCENE_ROUTINE(t1)->bank;
	set_lines(unk_480E);
	switch ((uint16_t)(t1 + 1u))
	{
	case scene_routines_ADDRESS + 0x1u:
		sub_03E02A();
		break;
	case scene_routines_ADDRESS + 0x5u:
		sub_03E003();
		break;
	case scene_routines_ADDRESS + 0x9u:
	case scene_routines_ADDRESS + 0x1Du:
	case scene_routines_ADDRESS + 0x29u:
		carry = sub_07B6A4();
		break;
	case scene_routines_ADDRESS + 0xDu:
		sub_03E012();
		break;
	case scene_routines_ADDRESS + 0x11u:
		sub_03E048();
		break;
	case scene_routines_ADDRESS + 0x15u:
		sub_03E01B();
		break;
	case scene_routines_ADDRESS + 0x19u:
		sub_03E027();
		break;
	case scene_routines_ADDRESS + 0x21u:
		sub_03E042();
		break;
	case scene_routines_ADDRESS + 0x25u:
		sub_03E039();
		break;
	case scene_routines_ADDRESS + 0x2Du:
		sub_03E04E();
		break;
	}
	if (unk_4872 != 0u)
	{
		sub_07C016(&ignored16, &ignored16_2);
		sub_07B70D(&ignored16_3, &ignored16_4, &u, &ignored16_2, &carry);
		return u;
	}
	unk_4804++;
	sub_07C016(&ignored16, &ignored16_2);
	sub_07B70D(&ignored16_3, &ignored16_4, &u, &ignored16_2, &carry);
	return u;
}

void sub_07B5DD(uint16_t y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, ignored16_4 = 0, u = 0;

	unk_480E = 0x20u;
	set_lines(unk_480E);
	sub_040012();
	sub_07C016(&ignored16, &ignored16_2);
	sub_07C985();
	sub_07CB9F(&y, &ignored16, p_left_caller);
	*p_left_caller = sub_07CB3C(y, *p_left_caller);
	sub_07CBD2(ignored16);
	sub_07CC05();
	unk_480E = 0x1Cu;
	set_lines(unk_480E);
	sub_038000();
	unk_480E = 0x1Fu;
	set_lines(unk_480E);
	u = sub_03E03F();
	unk_480E = 0x13u;
	set_lines(unk_480E);
	sub_026009(u);
	sub_07B70D(&ignored16_3, &ignored16_4, &u, &ignored16_2, &carry);
	u = sub_07B8B0(u);
	*p_u = u;
}

void sub_07B632(uint16_t d)
{
	unk_48BE = d;
	unk_48CE = d;
	unk_48C1 = d;
	unk_48D1 = d;
	unk_48AC = d;
	unk_48AF = (uint8_t)(d >> 8u);
	unk_48B0 = (uint8_t)d;
	unk_48C3 = 0u;
	unk_48D3 = 0u;
}

void sub_07B64C(uint16_t d)
{
	unk_48C5 = d;
	unk_48D5 = d;
	unk_48C8 = d;
	unk_48D8 = d;
	unk_48B2 = d;
	unk_48B5 = (uint8_t)(d >> 8u);
	unk_48B6 = (uint8_t)d;
	unk_48CA = 0u;
	unk_48DA = 0u;
}

uint16_t sub_07B666(void)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, u = 0;

	io_write8(VIDEO_184B, 1u);
	sub_07957F();
	unk_4804++;
	sub_07B70D(&ignored16, &ignored16_2, &u, &ignored16_3, &carry);
	return u;
}

void sub_07B676(uint16_t *p_u, uint32_t *p_left_caller, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, ignored16_4 = 0, u = 0;
	uint8_t t1 = 0;

	unk_4872 = 1u;
	sub_07CB9F(&ignored16, &ignored16_2, p_left_caller);
	sub_07CBD2(ignored16_2);
	unk_480E = 0x1Cu;
	set_lines(unk_480E);
	sub_038000();
	sub_07B70D(&ignored16_3, &ignored16, &u, &ignored16_4, &carry);
	t1 = io_read8(VIDEO_184E);
	if (t1 == 0u)
		carry = sub_07B6A4();
	else
	{
		unk_4885 = unk_4850;
		unk_4804++;
		carry = 1u;
	}
	*p_u = u;
	*p_carry = carry;
}

uint32_t sub_07B6A4(void)
{
	uint32_t carry = 0;

	carry = 0u;
	return carry;
}

uint16_t sub_07B6A6(void)
{
	uint8_t b = 0;
	uint16_t d = 0, ignored16 = 0, u = 0, x = 0;
	uint8_t t1 = 0;

	unk_4801 = 0u;
	unk_4802 = 0u;
	unk_4803 = 0u;
	unk_4804 = 0u;
	unk_4805 = 0u;
	unk_48F0 = 0u;
	x = unk_49F0_ADDRESS;
	u = 0x49D2u;
	b = 4u;
	do
	{
		if (mem_read8(x) == 2u)
		{
			mem_write8(u, 0x28u);
			unk_48F0++;
		}
		x++;
		u += 8u;
		t1 = b;
		b = t1 - 1u;
	} while (t1 != 1u);
	if (unk_48F0 != 0u)
	{
		u = sub_079692();
		unk_487E = 1u;
		d = 0xF00u;
		sub_07BAC7(d, &ignored16, &u);
		unk_4800 = 2u;
		unk_4802 = 1u;
		unk_4803 = 1u;
		return u;
	}
	u = sub_0796A3();
	unk_4800 = 1u;
	unk_49D7 = 0u;
	unk_49DF = 0u;
	unk_49E7 = 0u;
	unk_49EF = 0u;
	return u;
}

void sub_07B70D(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t a = 0;
	uint16_t d_2 = 0, player = 0, u = 0, y = 0;
	uint8_t stack = 0;
	uint16_t state = 0;

	u = unk_4817_ADDRESS;
	stack = 0u;
	do
	{
		player = player_records[(int8_t)((uint8_t)((uint32_t)stack << 1)) / 2];
		y = loaded_table_07E803_ADDRESS;
		state = PLAYER(player)->state;
		switch ((int8_t)(uint8_t)((uint32_t)mem_read8(state) << 1))
		{
		case 0:
			d = sub_07B731(player, u);
			break;
		case 2:
		case 10:
			sub_07B74F(player, u, &y, &d);
			break;
		case 4:
			sub_07B7E8(player, u, &y, &d);
			break;
		case 6:
			sub_07B843(player, u, &y, &d);
			break;
		case 8:
			d = sub_07B897(player, u);
			break;
		case 12:
		case 18:
		case 20:
			sub_07B8B9();
			break;
		case 14:
			d = sub_07B8BA((uint8_t)d);
			break;
		case 16:
			sub_07B901(&player, &y, &u, &d);
			break;
		}
		u += 8u;
		stack = stack + 1u;
		a = stack;
		carry = a < 4u;
	} while (a != 4u);
	d_2 = (d & 0xFFu) | ((uint32_t)stack << 8);
	*p_x = player;
	*p_y = y;
	*p_u = u;
	*p_d = d_2;
	*p_carry = carry;
}

uint16_t sub_07B731(uint16_t x, uint16_t u)
{
	uint8_t a = 0, d = 0;
	uint16_t d_2 = 0;
	uint16_t play_status = 0, t1 = 0, state = 0, t2 = 0, state_2 = 0;

	play_status = PLAYER(x)->play_status;
	mem_write8(play_status, 0u);
	if (unk_483B != 0u)
	{
		t1 = mem_read16(u);
		d = (uint8_t)t1;
		a = (uint8_t)(t1 >> 8);
		if (t1 != 0u)
		{
			a = 1u;
			state = PLAYER(x)->state;
			mem_write8(state, 1u);
		}
		d_2 = (d & 0xFFu) | ((uint32_t)a << 8);
		return d_2;
	}
	t2 = unk_4837;
	d = (uint8_t)t2;
	a = (uint8_t)(t2 >> 8);
	if (t2 != 0u)
	{
		a = 1u;
		state_2 = PLAYER(x)->state;
		mem_write8(state_2, 1u);
	}
	d_2 = (d & 0xFFu) | ((uint32_t)a << 8);
	return d_2;
}

void sub_07B74F(uint16_t x, uint16_t u, uint16_t *p_y, uint16_t *p_d)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t d = (uint8_t)*p_d;
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d_2 = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0, t2 = 0, t5 = 0, bit = 0, initial_3 = 0, number = 0;
	uint16_t play_status = 0, lives = 0, t3 = 0, lives_2 = 0, t4 = 0, state = 0, t6 = 0, t7 = 0, lives_3 = 0, lives_4 = 0, life = 0, object_life = 0, countdown = 0, state_2 = 0, play_status_2 = 0, state_3 = 0, score = 0, t8 = 0, score_2 = 0, initial = 0;
	uint32_t unk_48F3_halfword = 0, unk_48F0_halfword = 0;

	b = (uint8_t)d;
	play_status = PLAYER(x)->play_status;
	mem_write8(play_status, 0u);
	if (unk_483B != 0u)
	{
		t1 = mem_read8(PLAYER(x)->pressed) & 0xB0u;
		a = t1;
		if (t1 == 0u)
		{
			d_2 = ((uint32_t)a << 8) | b;
			*p_d = d_2;
			return;
		}
		lives = PLAYER(x)->lives;
		b = mem_read8(lives);
		y = mem_read16(u);
		do
		{
			t2 = unk_485A;
			carry = (uint8_t)(b + t2) < b;
			b += t2;
			if (carry)
				b = 0xFFu;
			t3 = y - 1u;
			y = t3;
		} while (t3 != 0u);
		lives_2 = PLAYER(x)->lives;
		mem_write8(lives_2, b);
		mem_write16(u, 0u);
	}
	else
	{
		t4 = unk_4837;
		a = (uint8_t)(t4 >> 8);
		b = (uint8_t)t4;
		if (t4 == 0u)
		{
			state = PLAYER(x)->state;
			mem_write8(state, 0u);
			d_2 = ((uint32_t)a << 8) | b;
			*p_d = d_2;
			return;
		}
		t5 = mem_read8(PLAYER(x)->pressed) & 0xB0u;
		a = t5;
		if (t5 == 0u)
		{
			d_2 = ((uint32_t)a << 8) | b;
			*p_d = d_2;
			return;
		}
		t6 = unk_4837;
		t7 = t6 - 1u;
		unk_4837 = t7;
		lives_3 = PLAYER(x)->lives;
		lives_4 = PLAYER(x)->lives;
		mem_write8(lives_4, mem_read8(lives_3) + unk_485A);
	}
	bit = PLAYER(x)->bit;
	unk_4850 |= bit;
	life = PLAYER(x)->life;
	mem_write8(life, 0x28u);
	object_life = PLAYER(x)->object_life;
	mem_write8(object_life, 0x28u);
	b = 0u;
	countdown = PLAYER(x)->countdown;
	mem_write16(countdown, 0u);
	state_2 = PLAYER(x)->state;
	if (mem_read8(state_2) == 5u)
	{
		play_status_2 = PLAYER(x)->play_status;
		mem_write8(play_status_2, 2u);
		a = 2u;
		state_3 = PLAYER(x)->state;
		mem_write8(state_3, 2u);
		d_2 = ((uint32_t)a << 8) | b;
		*p_y = y;
		*p_d = d_2;
		return;
	}
	score = PLAYER(x)->score;
	t8 = mem_read16(score);
	a = (uint8_t)(t8 >> 8);
	b = (uint8_t)t8;
	unk_48F3_halfword = ((uint32_t)a << 8) | b;
	unk_48F3 = (uint8_t)(unk_48F3_halfword >> 8u);
	unk_48F4 = (uint8_t)unk_48F3_halfword;
	score_2 = PLAYER(x)->score;
	mem_write16(score_2, 0u);
	d_2 = ((uint32_t)a << 8) | b;
	sub_079718(&d_2, &carry);
	a = (uint8_t)(d_2 >> 8);
	b = (uint8_t)d_2;
	if (carry == 0u)
	{
		play_status_2 = PLAYER(x)->play_status;
		mem_write8(play_status_2, 2u);
		a = 2u;
		state_3 = PLAYER(x)->state;
		mem_write8(state_3, 2u);
		d_2 = ((uint32_t)a << 8) | b;
		*p_y = y;
		*p_d = d_2;
		return;
	}
	stack = a;
	initial = (((uint32_t)PLAYER(x)->initial_1 << 8u) | PLAYER(x)->initial_2);
	b = (uint8_t)initial;
	unk_48F0_halfword = ((uint32_t)(initial >> 8) << 8) | b;
	unk_48F0 = (uint8_t)(unk_48F0_halfword >> 8u);
	unk_48F1 = (uint8_t)unk_48F0_halfword;
	initial_3 = PLAYER(x)->initial_3;
	unk_48F2 = initial_3;
	number = PLAYER(x)->number;
	unk_48F5 = number;
	d_2 = ((uint32_t)stack << 8) | b;
	d_2 = sub_079743(d_2);
	b = (uint8_t)d_2;
	play_status_2 = PLAYER(x)->play_status;
	mem_write8(play_status_2, 2u);
	a = 2u;
	state_3 = PLAYER(x)->state;
	mem_write8(state_3, 2u);
	d_2 = ((uint32_t)a << 8) | b;
	*p_y = y;
	*p_d = d_2;
}

void sub_07B7E8(uint16_t x, uint16_t u, uint16_t *p_y, uint16_t *p_d)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t d = (uint8_t)*p_d;
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d_2 = 0;
	uint8_t bit = 0, number = 0, t1 = 0, t3 = 0;
	uint16_t play_status = 0, lives = 0, countdown = 0, countdown_2 = 0, play_status_2 = 0, state = 0, t2 = 0, lives_2 = 0, t4 = 0, lives_3 = 0;

	b = (uint8_t)d;
	play_status = PLAYER(x)->play_status;
	mem_write8(play_status, 2u);
	lives = PLAYER(x)->lives;
	if (mem_read8(lives) == 0u)
	{
		bit = PLAYER(x)->bit;
		unk_4850 &= ~bit;
		number = PLAYER(x)->number;
		unk_4A1D = number;
		countdown = PLAYER(x)->countdown;
		mem_write16(countdown, 0u);
		countdown_2 = PLAYER(x)->countdown;
		mem_write8(countdown_2, 0x20u);
		unk_4A1C = 0x20u;
		unk_4A22 = 0u;
		play_status_2 = PLAYER(x)->play_status;
		mem_write8(play_status_2, 1u);
		state = PLAYER(x)->state;
		mem_write8(state, 3u);
		d_2 = 0x300u;
	}
	else
	{
		t1 = unk_483B;
		a = t1;
		if (t1 != 0u)
		{
			t2 = mem_read16(u);
			a = (uint8_t)(t2 >> 8);
			b = (uint8_t)t2;
			if (t2 != 0u)
			{
				lives_2 = PLAYER(x)->lives;
				b = mem_read8(lives_2);
				y = mem_read16(u);
				do
				{
					t3 = unk_485A;
					carry = (uint8_t)(b + t3) < b;
					b += t3;
					if (carry)
						b = 0xFFu;
					t4 = y - 1u;
					y = t4;
				} while (t4 != 0u);
				lives_3 = PLAYER(x)->lives;
				mem_write8(lives_3, b);
				a = 0u;
				b = 0u;
				mem_write16(u, 0u);
			}
		}
		d_2 = ((uint32_t)a << 8) | b;
	}
	*p_y = y;
	*p_d = d_2;
}

void sub_07B843(uint16_t x, uint16_t u, uint16_t *p_y, uint16_t *p_d)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0, half_carry = 0;
	uint8_t a = 0, d = 0;
	uint16_t d_2 = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;
	uint16_t play_status = 0, t1 = 0, countdown = 0, credit_given = 0, play_status_2 = 0, state = 0, play_status_3 = 0, state_2 = 0, t7 = 0, play_status_4 = 0, state_3 = 0;

	play_status = PLAYER(x)->play_status;
	mem_write8(play_status, 1u);
	if (unk_483B != 0u)
	{
		t1 = mem_read16(u);
		d = (uint8_t)t1;
		if (t1 == 0u)
		{
			t2 = unk_486A;
			a = t2;
			if (t2 != 0u)
			{
				countdown = PLAYER(x)->countdown;
				y = countdown;
				t3 = mem_read8(y + 1u);
				mem_write8(y + 1u, t3 + 1u);
				t4 = mem_read8(y + 1u);
				a = t4;
				if (a == 0x3Cu)
				{
					mem_write8(y + 1u, 0u);
					t5 = mem_read8(y);
					t6 = 0x99u + t5;
					half_carry = ((0x99u ^ t5 ^ t6) >> 4) & 1u;
					carry = (uint8_t)(0x99u + t5) < 0x99u;
					a = konami_daa(t6, half_carry, carry);
					mem_write8(y, a);
					if (a == 0x99u)
					{
						mem_write16(y, 0u);
						credit_given = PLAYER(x)->credit_given;
						mem_write8(credit_given, 0u);
						play_status_2 = PLAYER(x)->play_status;
						mem_write8(play_status_2, 0u);
						a = 4u;
						state = PLAYER(x)->state;
						mem_write8(state, 4u);
					}
				}
			}
			d_2 = (d & 0xFFu) | ((uint32_t)a << 8);
		}
		else
		{
			play_status_3 = PLAYER(x)->play_status;
			mem_write8(play_status_3, 0u);
			state_2 = PLAYER(x)->state;
			mem_write8(state_2, 5u);
			d_2 = (d & 0xFFu) | 0x500u;
		}
	}
	else
	{
		t7 = unk_4837;
		d = (uint8_t)t7;
		if (t7 == 0u)
		{
			t2 = unk_486A;
			a = t2;
			if (t2 != 0u)
			{
				countdown = PLAYER(x)->countdown;
				y = countdown;
				t3 = mem_read8(y + 1u);
				mem_write8(y + 1u, t3 + 1u);
				t4 = mem_read8(y + 1u);
				a = t4;
				if (a == 0x3Cu)
				{
					mem_write8(y + 1u, 0u);
					t5 = mem_read8(y);
					t6 = 0x99u + t5;
					half_carry = ((0x99u ^ t5 ^ t6) >> 4) & 1u;
					carry = (uint8_t)(0x99u + t5) < 0x99u;
					a = konami_daa(t6, half_carry, carry);
					mem_write8(y, a);
					if (a == 0x99u)
					{
						mem_write16(y, 0u);
						credit_given = PLAYER(x)->credit_given;
						mem_write8(credit_given, 0u);
						play_status_2 = PLAYER(x)->play_status;
						mem_write8(play_status_2, 0u);
						a = 4u;
						state = PLAYER(x)->state;
						mem_write8(state, 4u);
					}
				}
			}
			d_2 = (d & 0xFFu) | ((uint32_t)a << 8);
		}
		else
		{
			play_status_4 = PLAYER(x)->play_status;
			mem_write8(play_status_4, 0u);
			state_3 = PLAYER(x)->state;
			mem_write8(state_3, 5u);
			d_2 = (d & 0xFFu) | 0x500u;
		}
	}
	*p_y = y;
	*p_d = d_2;
}

uint16_t sub_07B897(uint16_t x, uint16_t u)
{
	uint16_t d = 0;
	uint16_t play_status = 0, countdown = 0, countdown_2 = 0, countdown_3 = 0, state = 0;

	play_status = PLAYER(x)->play_status;
	mem_write8(play_status, 0u);
	mem_write8(u + 7u, 0u);
	countdown = PLAYER(x)->countdown;
	mem_write8(countdown, mem_read8(countdown) + 1u);
	countdown_2 = PLAYER(x)->countdown;
	if (mem_read8(countdown_2) < 0xC0u)
		return sub_07B731(x, u);
	d = 0u;
	countdown_3 = PLAYER(x)->countdown;
	mem_write16(countdown_3, 0u);
	state = PLAYER(x)->state;
	mem_write8(state, 0u);
	return d;
}

uint16_t sub_07B8B0(uint16_t u)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, x = 0;

	x = loaded_table_07E80F_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)unk_4802 << 1))
	{
	case 0:
	case 6:
	case 8:
		sub_07B8B9();
		return u;
	case 2:
		sub_07B8BA(0u);
		return u;
	case 4:
		sub_07B901(&ignored16, &ignored16_2, &u, &ignored16_3);
		return u;
	case -12:
		sub_07B731(x, u);
		return u;
	case -10:
	case -2:
		sub_07B74F(x, u, &ignored16_2, &ignored16_3);
		return u;
	case -8:
		sub_07B7E8(x, u, &ignored16_2, &ignored16_3);
		return u;
	case -6:
		sub_07B843(x, u, &ignored16_2, &ignored16_3);
		return u;
	case -4:
		sub_07B897(x, u);
		return u;
	}
	unreachable();
}

void sub_07B8B9(void)
{
}

uint16_t sub_07B8BA(uint8_t d)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d_2 = 0;

	a = unk_49F0;
	if (a != 2u)
	{
		a = unk_49F1;
		if (a != 2u)
		{
			a = unk_49F2;
			if (a != 2u)
			{
				a = unk_49F3;
				if (a == 2u)
				{
					d_2 = (d & 0xFFu) | ((uint32_t)a << 8);
					return d_2;
				}
				d_2 = 0u;
				carry = sub_0797ED(d_2);
				d_2 = 0xA100u;
				carry = sub_0797ED(d_2);
				if (unk_488F != 0u)
				{
					unk_488F = 0u;
					mem_write8(unk_4890, 0u);
				}
				d = 0u;
				unk_4893 = 0u;
				unk_4879 = 1u;
				a = 2u;
				unk_4802 = 2u;
			}
		}
	}
	d_2 = (d & 0xFFu) | ((uint32_t)a << 8);
	return d_2;
}

void sub_07B901(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u, uint16_t *p_d)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint8_t d = (uint8_t)*p_d;
	uint32_t carry = 0, half_carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d_2 = 0, player = 0, x = 0, y_2 = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;
	uint16_t countdown = 0, credit_given = 0, countdown_2 = 0, countdown_3 = 0;

	b = (uint8_t)d;
	if (unk_49F0 == 2u || unk_49F1 == 2u || unk_49F2 == 2u || unk_49F3 == 2u)
	{
		unk_480E = 0x20u;
		set_lines(unk_480E);
		sub_040009();
		sub_07BA98();
		unk_4802 = 1u;
		unk_4879 = 0u;
		sub_07927A(&x, &d_2);
		a = (uint8_t)(d_2 >> 8);
		b = (uint8_t)d_2;
		d_2 = ((uint32_t)(uint8_t)~a << 8) | b;
		*p_x = x;
		*p_d = d_2;
		return;
	}
	stack = b;
	unk_480E = 0x20u;
	set_lines(unk_480E);
	b = stack;
	sub_040006();
	player = player_records[(int8_t)((uint8_t)((uint32_t)unk_4A1D << 1)) / 2];
	unk_4A22++;
	if (unk_4A22 == 0x3Cu)
	{
		t1 = unk_4A1C;
		t2 = 0x99u + t1;
		half_carry = ((0x99u ^ t1 ^ t2) >> 4) & 1u;
		carry = (uint8_t)(0x99u + t1) < 0x99u;
		a = konami_daa(t2, half_carry, carry);
		if (a == 0x99u)
		{
			y_2 = unk_49D0_ADDRESS;
			a = 0u;
			do
			{
				t3 = mem_read8(y_2 + 7u);
				if (t3 == 3u)
				{
					stack = a;
					player = player_records[(int8_t)((uint8_t)((uint32_t)a << 1)) / 2];
					countdown = PLAYER(player)->countdown;
					u = countdown;
					mem_write16(u, 0u);
					credit_given = PLAYER(player)->credit_given;
					mem_write8(credit_given, 0u);
					mem_write8(y_2 + 7u, 4u);
					a = stack;
				}
				y_2 += 8u;
				a++;
			} while (a != 4u);
			d_2 = 0u;
			carry = sub_0797ED(d_2);
			d_2 = 0x7F00u;
			carry = sub_0797ED(d_2);
			d_2 = 0x9200u;
			carry = sub_0797ED(d_2);
			unk_4A1C = 0u;
			unk_4A1D = 0u;
			unk_4802 = 3u;
			unk_4803 = 0u;
			d_2 = 0x300u;
			*p_x = player;
			*p_y = y_2;
			*p_u = u;
			*p_d = d_2;
			return;
		}
		unk_4A1C = a;
		unk_4A22 = 0u;
	}
	if (((unk_4842 | unk_4846 | unk_484A | unk_484E) & 0x10u) == 0u)
	{
		if (unk_4A1C == unk_4A21)
		{
			a = unk_4A1C;
			unk_4A21 = a;
			d_2 = ((uint32_t)a << 8) | b;
			*p_x = player;
			*p_y = y;
			*p_u = u;
			*p_d = d_2;
			return;
		}
		b = 1u;
		d_2 = 0x501u;
		carry = sub_0797ED(d_2);
		a = unk_4A1C;
		unk_4A21 = a;
		d_2 = ((uint32_t)a << 8) | b;
		*p_x = player;
		*p_y = y;
		*p_u = u;
		*p_d = d_2;
		return;
	}
	countdown_2 = PLAYER(player)->countdown;
	u = countdown_2;
	t4 = unk_4A1C;
	t5 = 0x99u + t4;
	half_carry = ((0x99u ^ t4 ^ t5) >> 4) & 1u;
	carry = (uint8_t)(0x99u + t4) < 0x99u;
	a = konami_daa(t5, half_carry, carry);
	if (a == 0x99u)
	{
		y_2 = unk_49D0_ADDRESS;
		a = 0u;
		do
		{
			t3 = mem_read8(y_2 + 7u);
			if (t3 == 3u)
			{
				stack = a;
				player = player_records[(int8_t)((uint8_t)((uint32_t)a << 1)) / 2];
				countdown = PLAYER(player)->countdown;
				u = countdown;
				mem_write16(u, 0u);
				credit_given = PLAYER(player)->credit_given;
				mem_write8(credit_given, 0u);
				mem_write8(y_2 + 7u, 4u);
				a = stack;
			}
			y_2 += 8u;
			a++;
		} while (a != 4u);
		d_2 = 0u;
		carry = sub_0797ED(d_2);
		d_2 = 0x7F00u;
		carry = sub_0797ED(d_2);
		d_2 = 0x9200u;
		carry = sub_0797ED(d_2);
		unk_4A1C = 0u;
		unk_4A1D = 0u;
		unk_4802 = 3u;
		unk_4803 = 0u;
		d_2 = 0x300u;
		*p_x = player;
		*p_y = y_2;
		*p_u = u;
		*p_d = d_2;
		return;
	}
	unk_4A22 = 0u;
	unk_4A1C = a;
	mem_write8(u, a);
	y = unk_49D0_ADDRESS;
	a = 0u;
	do
	{
		t6 = mem_read8(y + 7u);
		b = t6;
		if (b == 3u)
		{
			stack = a;
			player = player_records[(int8_t)((uint8_t)((uint32_t)a << 1)) / 2];
			countdown_3 = PLAYER(player)->countdown;
			u = countdown_3;
			a = unk_4A1C;
			if (a <= mem_read8(u))
			{
				mem_write8(u, a);
				mem_write8(u + 1u, 0u);
			}
			a = stack;
		}
		y += 8u;
		a++;
	} while (a != 4u);
	if (unk_4A1C == unk_4A21)
	{
		a = unk_4A1C;
		unk_4A21 = a;
		d_2 = ((uint32_t)a << 8) | b;
		*p_x = player;
		*p_y = y;
		*p_u = u;
		*p_d = d_2;
		return;
	}
	b = 1u;
	d_2 = 0x501u;
	carry = sub_0797ED(d_2);
	a = unk_4A1C;
	unk_4A21 = a;
	d_2 = ((uint32_t)a << 8) | b;
	*p_x = player;
	*p_y = y;
	*p_u = u;
	*p_d = d_2;
}

void sub_07BA34(void)
{
	uint8_t a = 0, b = 0;
	uint8_t t1 = 0;

	unk_4857 = 0u;
	a = unk_4850;
	b = 4u;
	do
	{
		if ((a & 1u) != 0u)
			unk_4857++;
		a = a >> 1;
		t1 = b;
		b = t1 - 1u;
	} while (t1 != 1u);
	if (unk_4857 == 0u)
		unk_4857++;
}

void sub_07BA50(void)
{
	uint8_t a = 0;
	uint16_t d = 0, x = 0;
	uint8_t t1 = 0, t2 = 0;

	if (unk_4811 != 0u)
		return;
	x = unk_4F80_ADDRESS;
	unk_48F0 = 8u;
	do
	{
		t1 = mem_read8(x + 0x27u);
		a = t1;
		if ((int8_t)t1 < 0 && (a & 0x40u) == 0u)
		{
			unk_48F1 = a;
			d = ((uint32_t)(uint8_t)((((((unk_48F1 & 0x30u) >> 1) >> 1) >> 1) >> 1) + 3u) << 8) | (a & 0xFu);
			sub_0797B7(d);
			mem_write8(x + 0x27u, 0u);
		}
		x += 0x60u;
		t2 = unk_48F0;
		unk_48F0 = t2 - 1u;
	} while (t2 != 1u);
}

void sub_07BA87(void)
{
	unk_4867 = step_scenes[(int8_t)unk_4803];
}

void sub_07BA93(void)
{
	uint16_t x = 0;

	x = indexed_table_07E89D_ADDRESS;
	sub_07BA9B(x);
}

void sub_07BA98(void)
{
	uint16_t x = 0;

	x = indexed_table_07E8B5_ADDRESS;
	sub_07BA9B(x);
}

void sub_07BA9B(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d = 0, x_2 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	if (unk_487D != 0u)
		return;
	x_2 = mem_read16(x + (int8_t)((uint32_t)unk_4867 << 1));
	a = (uint32_t)unk_4880 << 1;
	if (unk_4867 == 6u)
		a = (uint32_t)a << 1;
	t1 = x_2 + (int8_t)a;
	x_2 = t1 + 2u;
	t2 = mem_read16(t1);
	d = t2;
	carry = sub_0797E3(d);
	if (unk_4867 == 6u)
	{
		t3 = mem_read16(x_2);
		d = t3;
		carry = sub_0797E3(d);
	}
}

void unused_07BAC6(void)
{
}

void sub_07BAC7(uint16_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t d_2 = 0;
	uint8_t stack = 0;

	stack = d >> 8;
	d_2 = (d & 0xFFu) | ((uint32_t)stack << 8);
	switch (palette_request_handlers[(int8_t)((uint8_t)((uint32_t)unk_487E << 1)) / 2])
	{
	case code_read_as_tiles_07BAEC_ADDRESS:
		u = sub_07BAEC(d_2);
		break;
	case 0xBB12u:
		u = sub_07BB12(u, d_2);
		break;
	case 0xBB1Fu:
		u = sub_07BB1F(d_2);
		break;
	case 0xBB71u:
		u = sub_07BB71(d_2);
		break;
	case 0xBB85u:
		u = sub_07BB85(d_2);
		break;
	case 0xBBF6u:
		sub_07BBF6(d_2, &y, &u);
		break;
	case 0xBC78u:
		u = sub_07BC78(d_2);
		break;
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_07BAEC(uint16_t d)
{
	uint32_t carry = 0;
	uint16_t u = 0;
	uint16_t t1 = 0;

	unk_48E8 = (uint8_t)(d >> 8u);
	unk_48E9 = (uint8_t)d;
	sub_07BF39(&u, &carry);
	if (carry == 0u)
	{
		unk_48EA = unk_480E;
		mem_write8(u, 1u);
		t1 = (((uint32_t)unk_48E8 << 8u) | unk_48E9);
		mem_write16(u + 1u, t1);
		unk_480E = unk_48EA;
		set_lines(unk_480E);
	}
	return u;
}

uint16_t sub_07BB12(uint16_t u, uint16_t d)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d_2 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;
	uint32_t unk_48E8_halfword = 0;

	b = (uint8_t)d;
	unk_48E8_halfword = ((uint32_t)(d >> 8) << 8) | b;
	unk_48E8 = (uint8_t)(unk_48E8_halfword >> 8u);
	unk_48E9 = (uint8_t)unk_48E8_halfword;
	a = io_read8(u);
	if (a != 2u)
	{
		d_2 = ((uint32_t)a << 8) | b;
		return sub_07BB1F(d_2);
	}
	unk_48EA = unk_480E;
	io_write8(u, 2u);
	unk_480E = 0x2Eu;
	set_lines(unk_480E);
	mem_write8(u + 1u, 0u);
	mem_write8(u + 7u, 0u);
	t1 = (((uint32_t)unk_48E8 << 8u) | unk_48E9);
	b = (uint8_t)t1;
	carry = (int8_t)b < 0;
	t2 = TABLE16(palette_effects, (uint16_t)(((uint32_t)(uint8_t)(((uint32_t)(t1 >> 8) << 1) | carry) << 8) | (uint8_t)((uint32_t)b << 1))) + 2u;
	mem_write8(u + 6u, io_read8(t2));
	t3 = t2 + 1u;
	a = mem_read8(t3);
	mem_write8(u + 4u, a);
	mem_write8(u + 5u, a);
	mem_write16(u + 2u, t3 + 1u);
	unk_480E = unk_48EA;
	set_lines(unk_480E);
	return u;
}

uint16_t sub_07BB1F(uint16_t d)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t u = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	unk_48E8 = (uint8_t)(d >> 8u);
	unk_48E9 = (uint8_t)d;
	sub_07BF39(&u, &carry);
	if (carry == 0u)
	{
		unk_48EA = unk_480E;
		mem_write8(u, 2u);
		unk_480E = 0x2Eu;
		set_lines(unk_480E);
		mem_write8(u + 1u, 0u);
		mem_write8(u + 7u, 0u);
		t1 = (((uint32_t)unk_48E8 << 8u) | unk_48E9);
		b = (uint8_t)t1;
		carry = (int8_t)b < 0;
		t2 = TABLE16(palette_effects, (uint16_t)(((uint32_t)(uint8_t)(((uint32_t)(t1 >> 8) << 1) | carry) << 8) | (uint8_t)((uint32_t)b << 1))) + 2u;
		mem_write8(u + 6u, io_read8(t2));
		t3 = t2 + 1u;
		a = mem_read8(t3);
		mem_write8(u + 4u, a);
		mem_write8(u + 5u, a);
		mem_write16(u + 2u, t3 + 1u);
		unk_480E = unk_48EA;
		set_lines(unk_480E);
	}
	return u;
}

uint16_t sub_07BB71(uint16_t d)
{
	uint32_t carry = 0;
	uint16_t u = 0;
	uint16_t t1 = 0;

	unk_48E8 = (uint8_t)(d >> 8u);
	unk_48E9 = (uint8_t)d;
	sub_07BF39(&u, &carry);
	if (carry == 0u)
	{
		mem_write8(u, 3u);
		t1 = (((uint32_t)unk_48E8 << 8u) | unk_48E9);
		mem_write16(u + 1u, t1);
	}
	return u;
}

uint16_t sub_07BB85(uint16_t d)
{
	uint32_t carry = 0;
	uint8_t a = 0, d_2 = 0;
	uint16_t u = 0;
	uint16_t t1 = 0;

	unk_48E8 = (uint8_t)(d >> 8u);
	unk_48E9 = (uint8_t)d;
	sub_07BF39(&u, &carry);
	if (carry)
		return u;
	mem_write8(u + 3u, 0u);
	mem_write8(u + 4u, unk_48E9);
	mem_write8(u, unk_487E);
	unk_48EA = 0u;
	unk_48EB = 0u;
	if ((unk_48E8 & 0x10u) != 0u)
		unk_48EA = 0x40u;
	if ((unk_48E8 & 8u) != 0u)
	{
		unk_48EA |= 0x3Fu;
		unk_48EB = 0xC0u;
	}
	if ((unk_48E8 & 4u) != 0u)
		unk_48EB |= 0x30u;
	if ((unk_48E8 & 2u) != 0u)
		unk_48EB |= 0xCu;
	if ((unk_48E8 & 1u) != 0u)
		unk_48EB |= 3u;
	t1 = (((uint32_t)unk_48EA << 8u) | unk_48EB);
	d_2 = (uint8_t)t1;
	a = (uint8_t)(t1 >> 8);
	mem_write16(u + 1u, ((uint32_t)a << 8) | (d_2 & 0xFFu));
	mem_write16(u + 5u, ((uint32_t)a << 8) | (d_2 & 0xFFu));
	return u;
}

void sub_07BBF6(uint16_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t u = 0, x = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	unk_48E8 = (uint8_t)(d >> 8u);
	unk_48E9 = (uint8_t)d;
	sub_07BF39(&u, &carry);
	if (carry == 0u)
	{
		a = unk_480F | 1u;
		unk_480F = a;
		io_write8(IO_1FC2, a);
		x = VIDEO_0C00;
		y = 0x100u;
		a = 0xFFu;
		b = 0xFFu;
		do
		{
			t1 = x;
			x = t1 + 2u;
			mem_write16(t1, ((uint32_t)a << 8) | b);
			t2 = y - 1u;
			y = t2;
		} while (t2 != 0u);
		a = unk_480F & ~3u;
		unk_480F = a;
		io_write8(IO_1FC2, a);
		unk_48EA = 0u;
		unk_48EB = 0u;
		b = 0x10u;
		a = unk_48E8;
		if ((a & 1u) != 0u)
			b = 0x30u;
		unk_48EA = b;
		b = 0u;
		if ((a & 8u) != 0u)
			b = 0xCu;
		unk_48EA |= b;
		b = 0x28u;
		if ((a & 4u) != 0u)
			b = 0x30u;
		unk_48EB = b;
		b = 4u;
		if ((a & 2u) != 0u)
			b = 6u;
		unk_48EB |= b;
		mem_write8(u, 6u);
		t3 = (((uint32_t)unk_48E8 << 8u) | unk_48E9);
		mem_write16(u + 1u, t3);
		t4 = (((uint32_t)unk_48EA << 8u) | unk_48EB);
		mem_write16(u + 3u, t4);
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_07BC78(uint16_t d)
{
	uint32_t carry = 0;
	uint16_t u = 0;

	unk_48E8 = d >> 8;
	sub_07BF39(&u, &carry);
	if (carry == 0u)
	{
		mem_write8(u + 1u, unk_48E8);
		mem_write8(u, 7u);
	}
	return u;
}

uint16_t sub_07BC8B(uint16_t y, uint16_t d)
{
	uint8_t a = 0;
	uint16_t u = 0;
	uint16_t stack = 0;
	uint8_t t1 = 0, t2 = 0;

	u = VIDEO_3C00;
	unk_487F = 0x40u;
	do
	{
		t1 = mem_read8(u);
		a = t1;
		if (t1 != 0u)
		{
			stack = u;
			switch ((int8_t)(uint8_t)((uint32_t)a << 1))
			{
			case 0:
			case 2:
				sub_07BCBA(u, &y, &d);
				break;
			case 4:
				sub_07BD01(u, &y, &d);
				break;
			case 6:
				d = sub_07BDE6(u);
				break;
			case 8:
				sub_07BE10(u, &y, &d);
				break;
			case 10:
				sub_07BE15(u, &y, &d);
				break;
			case 12:
				sub_07BE8B(u, &y, &d);
				break;
			case 14:
				y = sub_07BEE6(y, u);
				break;
			}
			u = stack;
		}
		u += 8u;
		t2 = unk_487F;
		unk_487F = t2 - 1u;
	} while (t2 != 1u);
	return y;
}

void sub_07BCBA(uint16_t u, uint16_t *p_y, uint16_t *p_d)
{
	uint16_t d = (uint16_t)*p_d;
	uint8_t a = 0, b = 0;
	uint16_t d_2 = 0, palette_load = 0, set_table = 0, source = 0, x = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, palettes = 0, t4 = 0;
	uint16_t destination = 0;

	unk_480E = 0x2Du;
	set_lines(unk_480E);
	io_write8(u, 0u);
	t1 = mem_read8(u + 1u);
	unk_48F0 = t1;
	set_table = palette_sets_ADDRESS;
	t2 = mem_read8(u + 2u);
	b = t2;
	if ((int8_t)t2 < 0)
	{
		set_table = palette_sets_high_ADDRESS;
		b &= 0x7Fu;
	}
	b = (uint32_t)b << 1;
	palette_load = PALETTE_SET(set_table + (int8_t)b);
	unk_48F1 = 4u;
	do
	{
		t3 = unk_48F0 & 1u;
		a = t3;
		if (t3 != 0u)
		{
			source = PALETTE_LOAD(palette_load)->source;
			destination = PALETTE_LOAD(palette_load)->destination;
			x = destination;
			palettes = PALETTE_LOAD(palette_load)->palettes;
			d = (d & 0xFFu) | ((uint32_t)palettes << 8);
			d = sub_07BF51(x, source, d);
			a = (uint8_t)(d >> 8);
			b = (uint8_t)d;
		}
		palette_load += 5u;
		unk_48F0 = unk_48F0 >> 1;
		t4 = unk_48F1;
		unk_48F1 = t4 - 1u;
	} while (t4 != 1u);
	d_2 = ((uint32_t)a << 8) | b;
	*p_y = palette_load;
	*p_d = d_2;
}

void sub_07BD01(uint16_t u, uint16_t *p_y, uint16_t *p_d)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t d = (uint8_t)*p_d;
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d_2 = 0, x = 0;
	uint32_t left_caller = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t5 = 0, t6 = 0;
	uint16_t t4 = 0;

	stack = d;
	unk_480E = 0x2Eu;
	set_lines(unk_480E);
	b = stack;
	t1 = mem_read8(u + 4u);
	a = t1;
	t2 = mem_read8(u + 5u);
	if (a != t2)
	{
		t3 = mem_read8(u + 4u);
		mem_write8(u + 4u, t3 + 1u);
		d_2 = ((uint32_t)a << 8) | b;
	}
	else
	{
		a = unk_480F | 1u;
		unk_480F = a;
		io_write8(IO_1FC2, a);
		mem_write8(u + 4u, 0u);
		t4 = mem_read16(u + 2u);
		x = t4;
		t5 = mem_read8(x);
		a = t5;
		if ((int8_t)t5 >= 0)
		{
			y = loaded_table_07E971_ADDRESS;
			t6 = mem_read8(u + 1u);
			a = (uint32_t)t6 << 1;
			left_caller = 0u;
			d_2 = ((uint32_t)a << 8) | b;
			switch ((int8_t)a)
			{
			case 0:
				sub_07BD51(u, &x, &y, &d_2);
				break;
			case 2:
				sub_07BD6C(u, &x, &y, &d_2, &carry);
				break;
			case 4:
				carry = sub_07BDB0(u);
				break;
			case 6:
				sub_07BDB4(u, &x, &carry);
				break;
			case 8:
				sub_07BDC1(u, &x, &carry);
				break;
			case 10:
				sub_07BF94(u, &d_2, &carry);
				break;
			case 12:
				sub_07BFD1(u, &d_2, &carry);
				break;
			case -76:
			case -4:
				sub_07AA00(&x, &y, &u, &d_2, &left_caller, &carry);
				break;
			case -74:
			case -2:
				sub_07AC00();
				break;
			}
			a = (uint8_t)(d_2 >> 8);
			b = (uint8_t)d_2;
			if (left_caller != 0u)
				d_2 = ((uint32_t)a << 8) | b;
			else
			{
				stack = a;
				a = unk_480F & ~3u;
				unk_480F = a;
				io_write8(IO_1FC2, a);
				d_2 = ((uint32_t)stack << 8) | b;
			}
		}
		else
		{
			d_2 = ((uint32_t)a << 8) | b;
			sub_07BDA8(&x, &y, &u, &d_2, &left_caller, &carry);
			a = (uint8_t)(d_2 >> 8);
			b = (uint8_t)d_2;
			if (left_caller != 0u)
				d_2 = ((uint32_t)a << 8) | b;
			else if (carry)
			{
				stack = a;
				a = unk_480F & ~3u;
				unk_480F = a;
				io_write8(IO_1FC2, a);
				d_2 = ((uint32_t)stack << 8) | b;
			}
			else
			{
				y = loaded_table_07E971_ADDRESS;
				t6 = mem_read8(u + 1u);
				a = (uint32_t)t6 << 1;
				left_caller = 0u;
				d_2 = ((uint32_t)a << 8) | b;
				switch ((int8_t)a)
				{
				case 0:
					sub_07BD51(u, &x, &y, &d_2);
					break;
				case 2:
					sub_07BD6C(u, &x, &y, &d_2, &carry);
					break;
				case 4:
					carry = sub_07BDB0(u);
					break;
				case 6:
					sub_07BDB4(u, &x, &carry);
					break;
				case 8:
					sub_07BDC1(u, &x, &carry);
					break;
				case 10:
					sub_07BF94(u, &d_2, &carry);
					break;
				case 12:
					sub_07BFD1(u, &d_2, &carry);
					break;
				case -76:
				case -4:
					sub_07AA00(&x, &y, &u, &d_2, &left_caller, &carry);
					break;
				case -74:
				case -2:
					sub_07AC00();
					break;
				}
				a = (uint8_t)(d_2 >> 8);
				b = (uint8_t)d_2;
				if (left_caller != 0u)
					d_2 = ((uint32_t)a << 8) | b;
				else
				{
					stack = a;
					a = unk_480F & ~3u;
					unk_480F = a;
					io_write8(IO_1FC2, a);
					d_2 = ((uint32_t)stack << 8) | b;
				}
			}
		}
	}
	*p_y = y;
	*p_d = d_2;
}

void sub_07BD51(uint16_t u, uint16_t *p_step, uint16_t *p_y, uint16_t *p_d)
{
	uint16_t step = (uint16_t)*p_step;
	uint8_t a = 0, d = 0;
	uint16_t address = 0, d_2 = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0, t4 = 0;
	uint16_t t2 = 0, t3 = 0, colour = 0;

	t1 = mem_read8(u + 6u);
	unk_48F0 = t1;
	for (;;)
	{
		t2 = step;
		address = PALETTE_EFFECT_STEP(t2)->address;
		t3 = t2 + 2u;
		step = t3 + 2u;
		colour = PALETTE_EFFECT_STEP(t3 - 0x2u)->colour;
		d = (uint8_t)colour;
		mem_write16(address, ((uint32_t)(colour >> 8) << 8) | (d & 0xFFu));
		t4 = unk_48F0;
		a = t4;
		if (t4 == 0u)
			break;
		unk_48F0--;
	}
	mem_write16(u + 2u, step);
	stack = a;
	a = unk_480F & ~3u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
	d_2 = (d & 0xFFu) | ((uint32_t)stack << 8);
	*p_step = step;
	*p_y = address;
	*p_d = d_2;
}

void sub_07BD6C(uint16_t u, uint16_t *p_step, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t step = (uint16_t)*p_step;
	uint32_t carry = *p_carry;
	uint8_t a = 0, d = 0;
	uint16_t address = 0, d_2 = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0, address_2 = 0;
	uint16_t t2 = 0, t3 = 0, colour = 0;

	t1 = mem_read8(u + 6u);
	unk_48F0 = t1;
	for (;;)
	{
		t2 = step;
		address = PALETTE_EFFECT_STEP(t2)->address;
		t3 = t2 + 2u;
		step = t3 + 2u;
		colour = PALETTE_EFFECT_STEP(t3 - 0x2u)->colour;
		d = (uint8_t)colour;
		mem_write16(address, ((uint32_t)(colour >> 8) << 8) | (d & 0xFFu));
		if (unk_48F0 == 0u)
			break;
		step -= 8u;
		unk_48F0--;
	}
	step -= 8u;
	address_2 = (uint8_t)(PALETTE_EFFECT_STEP(step)->address >> 8u);
	a = address_2;
	if ((int8_t)address_2 < 0)
	{
		carry = 0u;
		mem_write8(u + 1u, 0u);
		step += 4u;
	}
	mem_write16(u + 2u, step);
	stack = a;
	a = unk_480F & ~3u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
	d_2 = (d & 0xFFu) | ((uint32_t)stack << 8);
	*p_step = step;
	*p_y = address;
	*p_d = d_2;
	*p_carry = carry;
}

void sub_07BDA8(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u, uint16_t *p_d, uint32_t *p_left_caller, uint32_t *p_carry)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t u = (uint16_t)*p_u;
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t a = 0;
	uint16_t y = 0;
	uint32_t left_caller = 0;

	y = loaded_table_07E975_ADDRESS;
	a = (d >> 8) & 0x7Fu;
	carry = (int8_t)a < 0;
	a = (uint32_t)a << 1;
	switch ((int8_t)a)
	{
	case 0:
		left_caller = 0u;
		carry = sub_07BDB0(u);
		break;
	case 2:
		left_caller = 0u;
		sub_07BDB4(u, &x, &carry);
		break;
	case 4:
		left_caller = 0u;
		sub_07BDC1(u, &x, &carry);
		break;
	case 6:
		left_caller = 0u;
		sub_07BF94(u, &d, &carry);
		break;
	case 8:
		left_caller = 0u;
		sub_07BFD1(u, &d, &carry);
		break;
	case -80:
	case -8:
		d = (d & 0xFFu) | ((uint32_t)a << 8);
		sub_07AA00(&x, &y, &u, &d, &left_caller, &carry);
		break;
	case -78:
	case -6:
		left_caller = 0u;
		d = (d & 0xFFu) | ((uint32_t)a << 8);
		sub_07AC00();
		break;
	case -4:
		left_caller = 0u;
		sub_07BD51(u, &x, &y, &d);
		break;
	case -2:
		left_caller = 0u;
		sub_07BD6C(u, &x, &y, &d, &carry);
		break;
	}
	*p_x = x;
	*p_y = y;
	*p_u = u;
	*p_d = d;
	*p_left_caller = left_caller;
	*p_carry = carry;
}

uint32_t sub_07BDB0(uint16_t u)
{
	uint32_t carry = 0;

	io_write8(u, 0u);
	carry = 1u;
	return carry;
}

void sub_07BDB4(uint16_t u, uint16_t *p_x, uint32_t *p_carry)
{
	uint16_t x = (uint16_t)*p_x;
	uint32_t carry = *p_carry;

	mem_write8(u + 1u, 1u);
	x -= 4u;
	mem_write16(u + 2u, x);
	carry = 0u;
	*p_x = x;
	*p_carry = carry;
}

void sub_07BDC1(uint16_t u, uint16_t *p_x, uint32_t *p_carry)
{
	uint16_t x = (uint16_t)*p_x;
	uint32_t carry = *p_carry;
	uint8_t a = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;
	uint16_t spare = 0;

	t1 = (uint8_t)FADE_RANGE(x - 0x1u)->address;
	a = t1;
	if (a == 0xFFu)
	{
		spare = AT16(FADE_RANGE(x - 0x1u)->spare, -1);
		x = spare + 4u;
		mem_write16(u + 2u, x);
		carry = 0u;
	}
	else
	{
		t2 = mem_read8(u + 7u);
		if (a == t2)
		{
			mem_write8(u + 7u, 0u);
			x += 4u;
			mem_write16(u + 2u, x);
			carry = 0u;
		}
		else
		{
			t3 = mem_read8(u + 7u);
			mem_write8(u + 7u, t3 + 1u);
			spare = AT16(FADE_RANGE(x - 0x1u)->spare, -1);
			x = spare + 4u;
			mem_write16(u + 2u, x);
			carry = 0u;
		}
	}
	*p_x = x;
	*p_carry = carry;
}

uint16_t sub_07BDE6(uint16_t u)
{
	uint8_t a = 0, d = 0;
	uint16_t d_2 = 0;
	uint8_t stack = 0;
	uint16_t t1 = 0;

	a = unk_480F | 1u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
	t1 = mem_read16(u + 1u);
	d = (uint8_t)t1;
	a = (uint8_t)(t1 >> 8);
	io_write16(VIDEO_0C00, ((uint32_t)a << 8) | (d & 0xFFu));
	io_write8(u, 0u);
	stack = a;
	a = unk_480F & ~3u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
	d_2 = (d & 0xFFu) | ((uint32_t)stack << 8);
	return d_2;
}

void sub_07BE10(uint16_t u, uint16_t *p_y, uint16_t *p_d)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t d = 0;
	uint16_t t1 = 0;

	unk_48F0 = 0u;
	t1 = mem_read16(u + 3u);
	d = t1;
	if (t1 == 0u)
		io_write8(u, 0u);
	else
		sub_07BE21(u, &y, &d);
	*p_y = y;
	*p_d = d;
}

void sub_07BE15(uint16_t u, uint16_t *p_y, uint16_t *p_d)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t d = (uint16_t)*p_d;

	unk_48F0 = 1u;
	*p_y = y;
	*p_d = d;
	sub_07BE21(u, p_y, p_d);
}

void sub_07BE21(uint16_t u, uint16_t *p_y, uint16_t *p_d)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t fade_range = 0, u_2 = 0;
	uint32_t left_caller = 0;
	uint8_t stack = 0, stack_2 = 0;
	uint8_t t2 = 0, t4 = 0, t5 = 0, t7 = 0, t8 = 0, t10 = 0;
	uint16_t t1 = 0, t3 = 0, t6 = 0, t9 = 0;

	t1 = mem_read16(u + 3u);
	mem_write16(u + 3u, t1 - 1u);
	t2 = mem_read8(u + 7u);
	if (t2 == 0x10u)
	{
		t3 = mem_read16(u + 1u);
		d = t3;
		mem_write16(u + 5u, ((uint32_t)(t3 >> 8) << 8) | (d & 0xFFu));
		mem_write8(u + 7u, 0u);
	}
	t4 = mem_read8(u + 6u);
	t5 = t4 & 1u;
	a = t5;
	if (t5 == 0u)
	{
		t6 = mem_read16(u + 5u);
		mem_write16(u + 5u, t6 >> 1);
		t7 = mem_read8(u + 7u);
		mem_write8(u + 7u, t7 + 1u);
		stack = a;
		a = unk_480F & ~3u;
		unk_480F = a;
		io_write8(IO_1FC2, a);
		d = (d & 0xFFu) | ((uint32_t)stack << 8);
	}
	else
	{
		stack_2 = u >> 8;
		stack = (uint8_t)u;
		a = unk_480F | 1u;
		unk_480F = a;
		io_write8(IO_1FC2, a);
		t8 = mem_read8(u + 7u);
		t9 = fade_ranges_ADDRESS + (int8_t)(((uint32_t)t8 << 1) << 1);
		fade_range = t9 + 1u;
		unk_48F1 = FADE_RANGE(t9)->colours;
		u_2 = FADE_RANGE(fade_range - 0x1u)->address;
		for (;;)
		{
			y = loaded_table_07E97B_ADDRESS;
			a = (uint32_t)unk_48F0 << 1;
			left_caller = 0u;
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			switch ((int8_t)a)
			{
			case 0:
				sub_07BF94(u_2, &d, &carry);
				break;
			case 2:
				sub_07BFD1(u_2, &d, &carry);
				break;
			case -86:
			case -14:
				sub_07AA00(&fade_range, &y, &u_2, &d, &left_caller, &carry);
				break;
			case -84:
			case -12:
				sub_07AC00();
				break;
			case -10:
				sub_07BD51(u_2, &fade_range, &y, &d);
				break;
			case -8:
				sub_07BD6C(u_2, &fade_range, &y, &d, &carry);
				break;
			case -6:
				carry = sub_07BDB0(u_2);
				break;
			case -4:
				sub_07BDB4(u_2, &fade_range, &carry);
				break;
			case -2:
				sub_07BDC1(u_2, &fade_range, &carry);
				break;
			}
			a = (uint8_t)(d >> 8);
			if (left_caller != 0u)
				break;
			u_2 += 2u;
			t10 = unk_48F1;
			unk_48F1 = t10 - 1u;
			if (t10 == 1u)
			{
				u = ((uint32_t)stack_2 << 8) | stack;
				t6 = mem_read16(u + 5u);
				mem_write16(u + 5u, t6 >> 1);
				t7 = mem_read8(u + 7u);
				mem_write8(u + 7u, t7 + 1u);
				stack = a;
				a = unk_480F & ~3u;
				unk_480F = a;
				io_write8(IO_1FC2, a);
				d = (d & 0xFFu) | ((uint32_t)stack << 8);
				break;
			}
		}
	}
	*p_y = y;
	*p_d = d;
}

void sub_07BE8B(uint16_t u, uint16_t *p_y, uint16_t *p_d)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t d = (uint8_t)*p_d;
	uint8_t a = 0;
	uint16_t d_2 = 0, x = 0;
	uint8_t t1 = 0, t4 = 0, t5 = 0;
	uint16_t t2 = 0, t3 = 0;

	t1 = mem_read8(u + 2u);
	mem_write8(u + 2u, t1 - 1u);
	if (t1 == 1u)
	{
		a = unk_480F | 1u;
		unk_480F = a;
		io_write8(IO_1FC2, a);
		x = VIDEO_0C00;
		y = 0x100u;
		d = 0u;
		a = 0u;
		do
		{
			t2 = x;
			x = t2 + 2u;
			mem_write16(t2, (uint32_t)a << 8);
			t3 = y - 1u;
			y = t3;
		} while (t3 != 0u);
		a = unk_480F & ~3u;
		unk_480F = a;
		io_write8(IO_1FC2, a);
		io_write8(u, 0u);
		io_write8(IO_1FB9, 0x13u);
		a = 0x2Cu;
		io_write8(IO_1FBA, 0x2Cu);
	}
	else if ((unk_4815 & 1u) == 0u)
	{
		t4 = mem_read8(u + 3u);
		io_write8(IO_1FB9, t4);
		t5 = mem_read8(u + 4u);
		a = t5;
		io_write8(IO_1FBA, a);
	}
	else
	{
		io_write8(IO_1FB9, 0x13u);
		a = 0x2Cu;
		io_write8(IO_1FBA, 0x2Cu);
	}
	d_2 = (d & 0xFFu) | ((uint32_t)a << 8);
	*p_y = y;
	*p_d = d_2;
}

uint16_t sub_07BEE6(uint16_t y, uint16_t u)
{
	uint8_t a = 0;
	uint16_t address = 0, u_2 = 0, x = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0, t3 = 0;

	a = unk_480F | 1u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
	io_write8(u, 0u);
	unk_48F0 = 0u;
	t1 = mem_read8(u + 1u);
	unk_48F1 = t1;
	do
	{
		if ((unk_48F1 & 1u) != 0u)
		{
			t2 = palette_clears_ADDRESS + (int8_t)(((uint32_t)unk_48F0 << 1) << 1);
			u_2 = PALETTE_CLEAR(t2)->extra_bytes;
			address = PALETTE_CLEAR(t2)->address;
			y = address;
			t3 = address;
			x = t3 + 1u;
			mem_write8(t3, 0u);
			while (u_2 != 0u)
			{
				mem_write8(x, mem_read8(y));
				y++;
				x++;
				u_2--;
			}
		}
		unk_48F1 = unk_48F1 >> 1;
		unk_48F0++;
	} while (unk_48F0 != 4u);
	a = unk_480F & ~3u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
	return y;
}

void sub_07BF39(uint16_t *p_u, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t u = 0;
	uint8_t t1 = 0;

	u = VIDEO_3C00;
	unk_487F = 0x40u;
	for (;;)
	{
		if (mem_read8(u) == 0u)
		{
			carry = 0u;
			break;
		}
		u += 8u;
		t1 = unk_487F;
		unk_487F = t1 - 1u;
		if (t1 == 1u)
		{
			carry = 1u;
			break;
		}
	}
	*p_u = u;
	*p_carry = carry;
}

uint16_t sub_07BF51(uint16_t x, uint16_t u, uint16_t d)
{
	uint8_t a = 0, b = 0;
	uint16_t d_2 = 0;
	uint8_t stack = 0;
	uint8_t t4 = 0, t5 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	stack = d >> 8;
	a = unk_480F | 1u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
	unk_480E = 0x2Du;
	set_lines(unk_480E);
	unk_48E8 = stack;
	do
	{
		unk_48E9 = 0x10u;
		do
		{
			t1 = u;
			u = t1 + 2u;
			t2 = mem_read16(t1);
			a = (uint8_t)(t2 >> 8);
			b = (uint8_t)t2;
			t3 = x;
			x = t3 + 2u;
			mem_write16(t3, ((uint32_t)a << 8) | b);
			t4 = unk_48E9;
			unk_48E9 = t4 - 1u;
		} while (t4 != 1u);
		t5 = unk_48E8;
		unk_48E8 = t5 - 1u;
	} while (t5 != 1u);
	stack = a;
	a = unk_480F & ~3u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
	d_2 = ((uint32_t)stack << 8) | b;
	return d_2;
}

void sub_07BF94(uint16_t u, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t a = 0;
	uint16_t d = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;
	uint32_t unk_48EA_halfword = 0;

	unk_48E8 = 0u;
	unk_48E9 = 0u;
	t1 = io_read16(u);
	a = (uint8_t)(t1 >> 8);
	unk_48EA_halfword = ((uint32_t)a << 8) | (t1 & 0xFFu);
	unk_48EA = (uint8_t)(unk_48EA_halfword >> 8u);
	unk_48EB = (uint8_t)unk_48EA_halfword;
	if ((a & ~7u) != 0u)
		unk_48E8 = 8u;
	if ((unk_48EA & 3u) != 0u || (unk_48EB & 0xC0u) != 0u)
		unk_48E9 = 0x40u;
	if ((unk_48EB & 0x1Eu) != 0u)
		unk_48E9 |= 2u;
	t2 = (((uint32_t)unk_48EA << 8u) | unk_48EB);
	t3 = (((uint32_t)unk_48E8 << 8u) | unk_48E9);
	t4 = t2;
	t5 = t4 - t3;
	carry = t4 < t3;
	d = t5;
	io_write16(u, ((uint32_t)(t5 >> 8) << 8) | (d & 0xFFu));
	*p_d = d;
	*p_carry = carry;
}

void sub_07BFD1(uint16_t u, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t a = 0;
	uint16_t d = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;
	uint32_t unk_48EA_halfword = 0;

	unk_48E8 = 0u;
	unk_48E9 = 0u;
	t1 = io_read16(u);
	a = (uint8_t)(t1 >> 8);
	unk_48EA_halfword = ((uint32_t)a << 8) | (t1 & 0xFFu);
	unk_48EA = (uint8_t)(unk_48EA_halfword >> 8u);
	unk_48EB = (uint8_t)unk_48EA_halfword;
	if ((a & 0x78u) != 0x78u)
		unk_48E8 = 4u;
	if ((unk_48EA & 3u) != 3u || (unk_48EB & 0xC0u) != 0xC0u)
		unk_48E9 = 0x20u;
	if ((unk_48EB & 0x1Eu) != 0x1Eu)
		unk_48E9 |= 1u;
	t2 = (((uint32_t)unk_48EA << 8u) | unk_48EB);
	t3 = (((uint32_t)unk_48E8 << 8u) | unk_48E9);
	t4 = t2;
	t5 = t4 + t3;
	carry = (uint16_t)(t4 + t3) < t4;
	d = t5;
	io_write16(u, ((uint32_t)(t5 >> 8) << 8) | (d & 0xFFu));
	*p_d = d;
	*p_carry = carry;
}
