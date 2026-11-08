/**
 *    Name:        unsorted/bank_11.c
 *    Description: bank 11's code
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    07-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

uint32_t sub_022003(void)
{
	uint8_t a = 0;
	uint8_t t1 = 0;

	a = unk_480F & ~3u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
	t1 = io_read8(VIDEO_3840);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		return sub_022029();
	case 2:
		return sub_022212();
	case 4:
		return sub_0222B0();
	}
	unreachable();
}

void sub_022006(uint16_t u)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0;
	uint8_t t1 = 0;

	d = 0xC000u;
	sub_078653(d, &ignored16, &carry);
	if (carry)
	{
		sub_07868C(&ignored16, &ignored16_2);
		unk_4872 = 0u;
		return;
	}
	unk_486A = 0u;
	t1 = io_read8(VIDEO_18E0);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_0227B5(u);
		return;
	case 2:
		sub_0227F4();
		return;
	case 4:
		sub_022847();
		return;
	case 6:
		sub_02285C();
		return;
	case 8:
		sub_02289A();
		return;
	case 10:
		sub_0228B4(u);
		return;
	case 12:
		sub_0228F3(u);
		return;
	}
}

uint16_t sub_022009(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d = 0, u = 0;
	uint8_t t1 = 0;

	y = sub_022DE0(x, y);
	u = loaded_table_023A13_ADDRESS;
	t1 = mem_read8(x + 2u);
	a = t1;
	carry = (int8_t)a < 0;
	switch ((int8_t)(uint8_t)((uint32_t)a << 1))
	{
	case 0:
		y = sub_022B3A(x, y);
		break;
	case 2:
		y = sub_022C80(x, y);
		break;
	case 4:
		y = sub_022CAA(x, y);
		break;
	case 6:
		y = sub_022CFE(x, y);
		break;
	case 8:
		y = sub_022D79(x, y);
		break;
	case 10:
		y = sub_022DB6(x, y, u);
		break;
	case 12:
		y = sub_022DD6(x, y);
		break;
	case 14:
		sub_022A79(x);
		break;
	case 16:
		sub_022A88(x, carry);
		break;
	case 18:
		sub_022AD5(x);
		break;
	case 20:
		sub_022AFE(x);
		break;
	case 22:
		y = sub_022B0C(x, y);
		break;
	case 24:
		sub_022B23(x);
		break;
	case 26:
		y = sub_022B2E(x, y);
		break;
	case 28:
		y = sub_022B43(x);
		break;
	case 30:
		sub_022BC8(x);
		break;
	case 32:
		sub_022BE7(x);
		break;
	case 34:
		sub_022C10(x);
		break;
	case 36:
		sub_022C22(x);
		break;
	case 38:
		sub_022C5D(x);
		break;
	case 40:
		sub_022C6D(x);
		break;
	case 42:
		sub_022CB3(x);
		break;
	case 44:
		sub_022CD1(x);
		break;
	case 46:
		y = sub_022CF2(x, y);
		break;
	case 48:
		sub_022D07(x);
		break;
	case 50:
		y = sub_022D6D(x, y);
		break;
	case 52:
		sub_022D82(x);
		break;
	case 54:
		sub_022D95(x);
		break;
	case 56:
		sub_022DAD(x);
		break;
	case -8:
		sub_079423();
		break;
	case -6:
		y = sub_022A70(x, y);
		break;
	case -4:
		y = sub_022ACC(x, y);
		break;
	case -2:
		y = sub_022B1A(x, y);
		break;
	}
	sub_022ECD(x);
	sub_022F01(x);
	y = sub_022F3A(x, y);
	d = ((uint32_t)stage_7_boss_gauge_piece_health_by_players[(int8_t)((uint8_t)(unk_4857 - 1u))] << 8) | 4u;
	y = sub_0786BF(x, y, d);
	return y;
}

void sub_02200C(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t t1 = 0;

	u = loaded_table_023AF1_ADDRESS;
	t1 = mem_read8(x + 2u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_02317A();
		break;
	case 2:
	case 4:
	case 6:
	case 8:
	case 10:
	case 12:
		sub_02317B(x, &y, &u);
		break;
	case 14:
		sub_0231CC(x, &y, &u);
		break;
	case 16:
		u = sub_023184(x);
		break;
	case 18:
		y = sub_02319C(x);
		break;
	case 20:
		sub_0231D5(x);
		break;
	case 22:
		sub_0231E9(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

uint32_t sub_022029(void)
{
	uint32_t carry = 0, half_carry = 0;
	uint8_t a = 0;
	uint16_t d = 0, name_entry_player = 0, place_suffix = 0, u = 0, x = 0, y = 0;
	uint8_t t8 = 0, t18 = 0, t19 = 0, t22 = 0, t23 = 0, t26 = 0, t27 = 0, t32 = 0, t36 = 0, t37 = 0;
	uint16_t t1 = 0, score = 0, t2 = 0, t3 = 0, t4 = 0, sprites = 0, t5 = 0, t6 = 0, sprites_2 = 0, score_2 = 0, t7 = 0, place_x = 0, place_y = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0, t15 = 0, t16 = 0, t17 = 0, t20 = 0, t21 = 0, t24 = 0, t25 = 0, t28 = 0, t29 = 0, t30 = 0, t31 = 0, t33 = 0, t34 = 0, t35 = 0;

	x = unk_4A40_ADDRESS;
	d = 0x800u;
	sub_0786B3(x, d);
	sub_022307();
	unk_48F4 = 0u;
	x = VIDEO_3860;
	do
	{
		t1 = x;
		x = t1 + 1u;
		a = (uint32_t)mem_read8(t1) << 1;
		name_entry_player = TABLE16(name_entry_player_records, (int8_t)a);
		u = 0x3842u + (int8_t)((uint32_t)a << 1);
		score = NAME_ENTRY_PLAYER(name_entry_player)->score;
		t2 = mem_read16(score);
		d = t2;
		d = sub_0786A4(d);
		a = (uint8_t)(d >> 8);
		a += unk_48F4;
		if (a > 9u)
		{
			t3 = x;
			x = t3 + 1u;
			mem_write8(t3, 0xFFu);
			t4 = u;
			io_write8(t4, 0xFFu);
			sprites = NAME_ENTRY_PLAYER(name_entry_player)->sprites;
			mem_write16(t4 + 1u, sprites);
		}
		else
		{
			t5 = x;
			x = t5 + 1u;
			mem_write8(t5, a);
			t6 = u;
			io_write8(t6, a);
			sprites_2 = NAME_ENTRY_PLAYER(name_entry_player)->sprites;
			mem_write16(t6 + 1u, sprites_2);
		}
		unk_48F4++;
	} while (unk_48F4 != 4u);
	x = 0x3842u;
	unk_48F0 = 0u;
	do
	{
		name_entry_player = name_entry_player_records[(int8_t)((uint8_t)((uint32_t)unk_48F0 << 1)) / 2];
		unk_48FC = name_entry_player;
		u = NAME_ENTRY_PLAYER(name_entry_player)->sprites;
		score_2 = NAME_ENTRY_PLAYER(name_entry_player)->score;
		t7 = mem_read16(score_2);
		unk_48FE = t7;
		if ((int8_t)mem_read8(x) >= 0)
		{
			d = unk_48F0;
			sub_022491(d);
			d = ((uint32_t)unk_48F0 << 8) | (uint8_t)(4u + unk_48F0);
			sub_022491(d);
			place_x = NAME_ENTRY_PLAYER(name_entry_player)->place_x;
			unk_48F8 = place_x;
			place_y = NAME_ENTRY_PLAYER(name_entry_player)->place_y;
			unk_48FA = place_y;
			a = mem_read8(x);
			half_carry = ((uint8_t)(a ^ 1u ^ (a + 1u)) >> 4) & 1u;
			carry = (uint8_t)(a + 1u) < a;
			a = konami_daa((uint8_t)(a + 1u), half_carry, carry);
			unk_48F1 = a;
			t8 = (((a >> 1) >> 1) >> 1) >> 1;
			a = t8;
			if (t8 != 0u)
			{
				d = ((uint32_t)(uint8_t)(a + 0x30u) << 8) | (uint8_t)(0xAu + unk_48F0);
				u = sub_022730(u, d);
			}
			t9 = unk_48F8;
			t10 = t9 + 0x10u;
			unk_48F8 = t10;
			d = ((uint32_t)(uint8_t)((unk_48F1 & 0xFu) + 0x30u) << 8) | (uint8_t)(0xAu + unk_48F0);
			u = sub_022730(u, d);
			t11 = unk_48F8;
			t12 = t11 + 0x10u;
			unk_48F8 = t12;
			t13 = place_suffixes_ADDRESS + (int8_t)((uint32_t)mem_read8(x) << 1);
			place_suffix = t13 + 1u;
			d = ((uint32_t)PLACE_SUFFIX(t13)->first << 8) | (uint8_t)(0xAu + unk_48F0);
			u = sub_022730(u, d);
			t14 = unk_48F8;
			t15 = t14 + 0x10u;
			unk_48F8 = t15;
			d = ((uint32_t)PLACE_SUFFIX(place_suffix - 0x1u)->second << 8) | (uint8_t)(0xAu + unk_48F0);
			u = sub_022730(u, d);
			unk_48F1 = 0u;
			y = unk_48FC;
			t16 = io_read16(y + 0x14u);
			unk_48F8 = t16;
			t17 = io_read16(y + 0x16u);
			unk_48FA = t17;
			unk_48F1++;
			t18 = ((((uint8_t)(unk_48FE >> 8u) >> 1) >> 1) >> 1) >> 1;
			a = t18;
			if (t18 == 0u)
			{
				t19 = unk_48F1;
				unk_48F1 = t19 - 1u;
				if (t19 == 1u)
					a = 0x10u;
			}
			d = ((uint32_t)(uint8_t)(a + 0x30u) << 8) | (uint8_t)(0xAu + unk_48F0);
			u = sub_022467(u, d);
			t20 = unk_48F8;
			t21 = t20 + 0x10u;
			unk_48F8 = t21;
			unk_48F1++;
			t22 = (uint8_t)(unk_48FE >> 8u) & 0xFu;
			a = t22;
			if (t22 == 0u)
			{
				t23 = unk_48F1;
				unk_48F1 = t23 - 1u;
				if (t23 == 1u)
					a = 0x10u;
			}
			d = ((uint32_t)(uint8_t)(a + 0x30u) << 8) | (uint8_t)(0xAu + unk_48F0);
			u = sub_022467(u, d);
			t24 = unk_48F8;
			t25 = t24 + 0x10u;
			unk_48F8 = t25;
			unk_48F1++;
			t26 = ((((uint8_t)unk_48FE >> 1) >> 1) >> 1) >> 1;
			a = t26;
			if (t26 == 0u)
			{
				t27 = unk_48F1;
				unk_48F1 = t27 - 1u;
				if (t27 == 1u)
					a = 0x10u;
			}
			d = ((uint32_t)(uint8_t)(a + 0x30u) << 8) | (uint8_t)(unk_48F0 + 0xAu);
			u = sub_022467(u, d);
			t28 = unk_48F8;
			t29 = t28 + 0x10u;
			unk_48F8 = t29;
			d = ((uint32_t)(uint8_t)(((uint8_t)unk_48FE & 0xFu) + 0x30u) << 8) | (uint8_t)(unk_48F0 + 0xAu);
			sub_022467(u, d);
		}
		x += 4u;
		unk_48F0++;
	} while (unk_48F0 != 4u);
	x = 0x3852u;
	unk_48F0 = 4u;
	do
	{
		t30 = x;
		mem_write8(t30, 0x41u);
		t31 = t30 + 1u;
		x = t31 + 2u;
		mem_write16(t31, 0x4040u);
		t32 = unk_48F0;
		unk_48F0 = t32 - 1u;
	} while (t32 != 1u);
	unk_48F0 = 7u;
	unk_48F2 = 0u;
	unk_48F3 = 0u;
	x = unk_4D40_ADDRESS;
	do
	{
		mem_write8(x, 0x80u);
		mem_write8(x + 9u, 0x20u);
		mem_write8(x + 4u, 0x11u);
		mem_write8(x + 5u, 1u);
		t33 = 0x30u + (((uint32_t)unk_48F2 << 8u) | unk_48F3);
		mem_write16(x + 0xCu, t33);
		mem_write16(x + 0x11u, VIDEO_00A0);
		mem_write16(x + 0xFu, 0x100u);
		t34 = (((uint32_t)unk_48F2 << 8u) | unk_48F3);
		t35 = t34 + 0x30u;
		unk_48F2 = (uint8_t)(t35 >> 8u);
		unk_48F3 = (uint8_t)t35;
		x += 0x60u;
		t36 = unk_48F0;
		unk_48F0 = t36 - 1u;
	} while (t36 != 1u);
	carry = 0u;
	io_write16(VIDEO_385E, 0u);
	t37 = io_read8(VIDEO_3840);
	io_write8(VIDEO_3840, t37 + 1u);
	return carry;
}

uint32_t sub_022212(void)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, u = 0, x = 0;
	uint8_t stack = 0, stack_10002 = 0;
	uint8_t t4 = 0, t5 = 0, t6 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t7 = 0, t8 = 0;

	t1 = io_read16(VIDEO_385E);
	t2 = t1 + 1u;
	a = (uint8_t)(t2 >> 8);
	b = (uint8_t)t2;
	io_write16(VIDEO_385E, ((uint32_t)a << 8) | b);
	if ((uint16_t)(((uint32_t)a << 8) | b) == 0x700u)
		return sub_0222CD();
	if ((uint16_t)(((uint32_t)a << 8) | b) == 0x6C0u)
	{
		stack = a;
		stack_10002 = b;
		d = 0xFD00u;
		sub_07869E(d);
		a = stack;
		b = stack_10002;
	}
	if ((int16_t)(((uint32_t)a << 8) | b) <= 0x580)
	{
		x = unk_4D40_ADDRESS;
		unk_48F0 = 7u;
		do
		{
			t3 = mem_read16(x + 0xCu);
			if ((int16_t)t3 >= 0x180)
				mem_write16(x + 0xCu, 0x30u);
			x += 0x60u;
			t4 = unk_48F0;
			unk_48F0 = t4 - 1u;
		} while (t4 != 1u);
	}
	x = 0x3842u;
	a = 0x80u;
	b = 4u;
	do
	{
		a &= mem_read8(x);
		x += 4u;
		t5 = b;
		b = t5 - 1u;
	} while (t5 != 1u);
	if ((int8_t)a < 0)
	{
		io_write16(VIDEO_385E, 0u);
		t6 = io_read8(VIDEO_3840);
		io_write8(VIDEO_3840, t6 + 1u);
		carry = 0u;
		return carry;
	}
	x = 0x3842u;
	unk_48F0 = 0u;
	unk_48F8 = 0x60u;
	unk_48FA = 0xD8u;
	do
	{
		u = name_entry_player_records[(int8_t)((uint8_t)((uint32_t)unk_48F0 << 1)) / 2];
		t7 = unk_48F8;
		stack = t7 >> 8;
		stack_10002 = t7;
		if ((int8_t)mem_read8(x) >= 0)
			x = sub_022367(x, u);
		t8 = (((uint32_t)stack << 8) | stack_10002) + 0x48u;
		unk_48F8 = t8;
		x += 4u;
		unk_48F0++;
	} while (unk_48F0 != 4u);
	carry = 0u;
	return carry;
}

uint32_t sub_0222B0(void)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint16_t t1 = 0;

	t1 = io_read16(VIDEO_385E);
	d = t1 + 1u;
	io_write16(VIDEO_385E, d);
	if (d == 0x100u)
		return sub_0222CD();
	if (d == VIDEO_00C0)
	{
		d = 0xFD00u;
		sub_07869E(d);
	}
	carry = 0u;
	return carry;
}

uint32_t sub_0222CD(void)
{
	uint32_t carry = 0;
	uint8_t a = 0, d = 0;
	uint16_t d_2 = 0, name_entry_player = 0, x = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0, t5 = 0, t6 = 0;
	uint16_t initials = 0, t2 = 0, t3 = 0, score = 0, t4 = 0;
	uint32_t unk_48F3_halfword = 0;

	x = VIDEO_3860;
	stack = 4u;
	do
	{
		t1 = mem_read8(x + 1u);
		if ((int8_t)t1 >= 0)
		{
			a = mem_read8(x);
			unk_48F5 = a;
			name_entry_player = name_entry_player_records[(int8_t)((uint8_t)((uint32_t)a << 1)) / 2];
			initials = NAME_ENTRY_PLAYER(name_entry_player)->initials;
			t2 = initials;
			t3 = mem_read16(t2);
			unk_48F0 = (uint8_t)(t3 >> 8u);
			unk_48F1 = (uint8_t)t3;
			a = mem_read8(t2 + 2u);
			unk_48F2 = a;
			score = NAME_ENTRY_PLAYER(name_entry_player)->score;
			t4 = mem_read16(score);
			d = (uint8_t)t4;
			unk_48F3_halfword = ((uint32_t)(t4 >> 8) << 8) | (d & 0xFFu);
			unk_48F3 = (uint8_t)(unk_48F3_halfword >> 8u);
			unk_48F4 = (uint8_t)unk_48F3_halfword;
			t5 = mem_read8(x + 1u);
			d_2 = (d & 0xFFu) | ((uint32_t)t5 << 8);
			sub_0786A1(d_2);
		}
		x += 2u;
		t6 = stack;
		stack = t6 - 1u;
	} while (t6 != 1u);
	carry = 1u;
	return carry;
}

void sub_022307(void)
{
	uint8_t a = 0;
	uint16_t score_addresses = 0, u = 0, y = 0;
	uint16_t t1 = 0, t2 = 0;

	u = VIDEO_3860;
	io_write8(VIDEO_3860, 0u);
	io_write8(VIDEO_3862, 1u);
	io_write8(VIDEO_3864, 2u);
	io_write8(VIDEO_3866, 3u);
	score_addresses = player_score_addresses_ADDRESS;
	unk_48E8 = 0u;
	do
	{
		y = u + 2u;
		a = unk_48E8 + 1u;
		if (a != 4u)
		{
			unk_48E9 = a;
			do
			{
				t1 = mem_read16(SCORE_ADDRESS(score_addresses + (int8_t)((uint32_t)mem_read8(y) << 1)));
				unk_48EA = (uint8_t)(t1 >> 8u);
				unk_48EB = (uint8_t)t1;
				t2 = mem_read16(SCORE_ADDRESS(score_addresses + (int8_t)((uint32_t)mem_read8(u) << 1)));
				if (t2 <= (((uint32_t)unk_48EA << 8u) | unk_48EB))
				{
					a = mem_read8(u);
					mem_write8(u, mem_read8(y));
					mem_write8(y, a);
				}
				y += 2u;
				unk_48E9++;
			} while (unk_48E9 != 4u);
		}
		u += 2u;
		unk_48E8++;
	} while (unk_48E8 != 4u);
}

uint16_t sub_022367(uint16_t x, uint16_t u)
{
	bool L_022382 = false, L_0223B2 = false;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, u_2 = 0, y = 0;
	uint8_t stack = 0, stack_2 = 0;
	uint8_t t1 = 0, t3 = 0, t5 = 0, t6 = 0, t8 = 0, t11 = 0;
	uint16_t repeat_wait = 0, repeat_wait_2 = 0, controls_pressed = 0, repeat_wait_3 = 0, controls_held = 0, repeat_wait_4 = 0, initials = 0, t2 = 0, controls_pressed_2 = 0, repeat_wait_5 = 0, controls_held_2 = 0, repeat_wait_6 = 0, initials_2 = 0, t4 = 0, controls_pressed_3 = 0, initials_3 = 0, initials_4 = 0, t7 = 0, t9 = 0, t10 = 0;

	repeat_wait = NAME_ENTRY_PLAYER(u)->repeat_wait;
	if (mem_read8(repeat_wait) != 0u)
	{
		repeat_wait_2 = NAME_ENTRY_PLAYER(u)->repeat_wait;
		mem_write8(repeat_wait_2, mem_read8(repeat_wait_2) - 1u);
	}
	controls_pressed = NAME_ENTRY_PLAYER(u)->controls_pressed;
	if ((mem_read8(controls_pressed) & 2u) != 0u)
		L_022382 = true;
	else
	{
		repeat_wait_3 = NAME_ENTRY_PLAYER(u)->repeat_wait;
		if (mem_read8(repeat_wait_3) == 0u)
		{
			controls_held = NAME_ENTRY_PLAYER(u)->controls_held;
			L_022382 = (mem_read8(controls_held) & 2u) != 0u;
		}
	}
	if (L_022382)
	{
		repeat_wait_4 = NAME_ENTRY_PLAYER(u)->repeat_wait;
		mem_write8(repeat_wait_4, 0xFu);
		d = 0x4500u;
		sub_07869E(d);
		t1 = mem_read8(x + 3u);
		a = t1;
		initials = NAME_ENTRY_PLAYER(u)->initials;
		y = initials;
		t2 = y + (int8_t)a;
		mem_write8(t2, mem_read8(t2) + 1u);
		b = mem_read8(y + (int8_t)a);
		if (b > 0x62u)
			b = 0x40u;
		mem_write8(y + (int8_t)a, b);
	}
	controls_pressed_2 = NAME_ENTRY_PLAYER(u)->controls_pressed;
	if ((mem_read8(controls_pressed_2) & 1u) != 0u)
		L_0223B2 = true;
	else
	{
		repeat_wait_5 = NAME_ENTRY_PLAYER(u)->repeat_wait;
		if (mem_read8(repeat_wait_5) == 0u)
		{
			controls_held_2 = NAME_ENTRY_PLAYER(u)->controls_held;
			L_0223B2 = (mem_read8(controls_held_2) & 1u) != 0u;
		}
	}
	if (L_0223B2)
	{
		repeat_wait_6 = NAME_ENTRY_PLAYER(u)->repeat_wait;
		mem_write8(repeat_wait_6, 0xFu);
		d = 0x4500u;
		sub_07869E(d);
		t3 = mem_read8(x + 3u);
		a = t3;
		initials_2 = NAME_ENTRY_PLAYER(u)->initials;
		y = initials_2;
		t4 = y + (int8_t)a;
		mem_write8(t4, mem_read8(t4) - 1u);
		b = mem_read8(y + (int8_t)a);
		if (b < 0x40u)
			b = 0x62u;
		mem_write8(y + (int8_t)a, b);
	}
	controls_pressed_3 = NAME_ENTRY_PLAYER(u)->controls_pressed;
	if ((mem_read8(controls_pressed_3) & 0x30u) != 0u)
	{
		d = 0x4400u;
		sub_07869E(d);
		t5 = mem_read8(x + 3u);
		a = t5;
		if (a == 2u)
			io_write8(x, 0xFFu);
		else
		{
			a++;
			initials_3 = NAME_ENTRY_PLAYER(u)->initials;
			mem_write8(initials_3 + (int8_t)a, 0x41u);
			mem_write8(x + 3u, a);
		}
	}
	unk_48FC = u;
	initials_4 = NAME_ENTRY_PLAYER(u)->initials;
	y = initials_4;
	u_2 = NAME_ENTRY_PLAYER(u)->sprites + 0x80u;
	t6 = mem_read8(x + 3u);
	unk_48F1 = t6 + 1u;
	do
	{
		stack_2 = u_2 >> 8;
		stack = (uint8_t)u_2;
		t7 = y;
		y = t7 + 1u;
		t8 = io_read8(unk_48FC + 0x18u);
		u_2 = ((uint32_t)stack_2 << 8) | stack;
		d = ((uint32_t)mem_read8(t7) << 8) | (uint8_t)(t8 + 0xAu);
		u_2 = sub_022730(u_2, d);
		if (mem_read8(x) != 0xFFu && unk_48F1 == 1u)
		{
			a = unk_480F | 2u;
			unk_480F = a;
			io_write8(IO_1FC2, a);
			stack_2 = x >> 8;
			stack = (uint8_t)x;
			mem_write8(u_2 - 7u, name_entry_cursor_zooms[((uint8_t)unk_4815 & 0x1Fu) >> 1]);
			x = ((uint32_t)stack_2 << 8) | stack;
			a = unk_480F & ~3u;
			unk_480F = a;
			io_write8(IO_1FC2, a);
		}
		t9 = unk_48F8;
		t10 = t9 + 0x10u;
		unk_48F8 = t10;
		t11 = unk_48F1;
		unk_48F1 = t11 - 1u;
	} while (t11 != 1u);
	return x;
}

uint16_t sub_022467(uint16_t u, uint16_t d)
{
	uint8_t a = 0;

	u = sub_022730(u, d);
	a = unk_480F | 2u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
	mem_write16(u - 8u, 0x30u);
	a = unk_480F & ~3u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
	return u;
}

void sub_022491(uint16_t d)
{
	uint8_t a = 0, b = 0;
	uint16_t u = 0, x = 0;
	uint8_t stack_E = 0, stack_F = 0, stack = 0, stack_11 = 0, stack_12 = 0, stack_13 = 0, stack_14 = 0, stack_15 = 0, stack_16 = 0;
	uint8_t t7 = 0, t8 = 0;
	uint16_t column = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t9 = 0;

	a = (uint8_t)(d >> 8);
	stack_16 = a;
	stack = a & 0x7Fu;
	stack_F = (uint8_t)d;
	column = (((uint32_t)NAME_ENTRY_COLUMN(name_entry_columns_ADDRESS + (int8_t)((uint32_t)stack << 1))->column << 8u) | NAME_ENTRY_COLUMN(name_entry_columns_ADDRESS + (int8_t)((uint32_t)stack << 1))->palette);
	stack_11 = column >> 8;
	stack_13 = column;
	x = name_entry_pictures[(int8_t)((uint8_t)((uint32_t)stack_F << 1)) / 2];
	do
	{
		t1 = x;
		u = mem_read16(t1) + (int8_t)stack_11;
		t2 = t1 + 2u;
		stack_15 = mem_read8(t2);
		t3 = t2 + 1u;
		stack_14 = mem_read8(t3);
		t4 = t3 + 1u;
		x = t4 + 1u;
		a = mem_read8(t4) | stack_13;
		if ((int8_t)stack_16 < 0)
			a = 0u;
		stack_E = a;
		do
		{
			stack_12 = stack_15;
			b = stack_E;
			do
			{
				mem_write8(u - 0x2000u, b);
				t5 = x;
				x = t5 + 1u;
				t6 = u;
				u = t6 + 1u;
				mem_write8(t6, mem_read8(t5));
				t7 = stack_12;
				stack_12 = t7 - 1u;
			} while (t7 != 1u);
			u += (int8_t)(0x40u - stack_15);
			t8 = stack_14;
			stack_14 = t8 - 1u;
		} while (t8 != 1u);
		t9 = x;
		x = t9 + 1u;
	} while (mem_read8(t9) == 0u);
}

void sub_02250C(void)
{
	unk_4F80 = 0x80u;
	unk_4F86 = 0x40u;
	unk_4F84 = 0xF9Fu;
	unk_4F8C = 0x138u;
	unk_4F91 = 0x98u;
	sub_02252B();
}

void sub_02252B(void)
{
	uint16_t d = 0, x = 0;

	x = unk_4A40_ADDRESS;
	d = 0x800u;
	sub_0786B3(x, d);
	unk_480A = 0xC0u;
	unk_4803++;
}

void sub_02253C(void)
{
	uint32_t carry = 0;
	uint16_t d = 0, x = 0;
	uint8_t t1 = 0;

	unk_4F86 = 0x40u;
	x = 0x4980u;
	d = 0x100u;
	sub_02263C(x, d);
	t1 = unk_480A;
	unk_480A = t1 - 1u;
	if (t1 != 1u)
		return;
	io_write8(VIDEO_1C80, 3u);
	unk_480A = 0x80u;
	d = 0x700u;
	carry = sub_078680(d);
	unk_4803++;
}

void sub_022564(void)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, x = 0;
	uint8_t t1 = 0, t2 = 0, t6 = 0;
	uint16_t t3 = 0, t4 = 0, t5 = 0;

	t1 = unk_480A;
	unk_480A = t1 - 1u;
	if (t1 == 1u)
	{
		d = 0u;
		carry = sub_078680(d);
		t2 = io_read8(VIDEO_1C80);
		io_write8(VIDEO_1C80, 0u);
		sub_07868F(&ignored16, &ignored16_2);
		unk_4803++;
		return;
	}
	x = VIDEO_1A00;
	unk_48F0 = 0u;
	unk_48F1 = 0xDu * (uint8_t)unk_4815;
	do
	{
		t3 = 0xDu * unk_48F1;
		t4 = t3 - 0x7001u;
		b = (uint8_t)t4;
		t5 = x;
		x = t5 + 2u;
		mem_write16(t5, ((uint32_t)(t4 >> 8) << 8) | b);
		unk_48F1 = b;
		t6 = unk_48F0;
		unk_48F0 = t6 - 1u;
	} while (t6 != 1u);
	unk_48F1 = 0xDu * (uint8_t)unk_4815;
	a = unk_480F | 2u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
	x = VIDEO_2000;
	while (mem_read8(x) != 0u)
	{
		b = 0xDu * unk_48F1;
		if (b < 0x30u)
			b = 0x30u;
		mem_write8(x + 0xBu, b);
		x += 0x10u;
	}
	a = unk_480F & ~3u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
}

void sub_0225E1(void)
{
	uint32_t carry = 0;
	uint16_t d = 0, x = 0;
	uint8_t t1 = 0;

	unk_4F86 = 0x40u;
	x = 0x49A8u;
	d = 0x600u;
	sub_02263C(x, d);
	t1 = unk_480A;
	unk_480A = t1 - 1u;
	if (t1 != 1u)
		return;
	io_write8(VIDEO_1C80, 3u);
	unk_480A = 0x80u;
	d = 0x700u;
	carry = sub_078680(d);
	unk_4803++;
}

void sub_022608(uint16_t u)
{
	uint16_t d = 0, ignored16 = 0;

	unk_487E = 3u;
	d = 0u;
	sub_078677(d, &ignored16, &u);
	sub_078695();
	unk_480A = 0x40u;
	unk_4803++;
}

void sub_02261F(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0;
	uint8_t t1 = 0;

	unk_4F86 = 0x40u;
	t1 = unk_480A;
	unk_480A = t1 - 1u;
	if (t1 != 1u)
		return;
	sub_07868C(&ignored16, &ignored16_2);
	unk_4802++;
	unk_4803 = 0u;
	unk_4804 = 0u;
	unk_4805 = 0u;
}

void sub_02263C(uint16_t x, uint16_t d)
{
	uint32_t carry = 0, half_carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d_2 = 0, icons = 0, u = 0, x_2 = 0;
	uint8_t stack = 0, stack_2 = 0, stack_3 = 0, stack_4 = 0, stack_5 = 0;
	uint8_t t1 = 0, t7 = 0, t15 = 0, t18 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0, t16 = 0, t17 = 0;

	u = VIDEO_2000;
	unk_48F0 = d >> 8;
	unk_48F1 = 5u;
	unk_48F8 = 0x88u;
	unk_48FA = 0x130u;
	do
	{
		stack_2 = x >> 8;
		stack = (uint8_t)x;
		t1 = (((unk_48F0 >> 1) >> 1) >> 1) >> 1;
		a = t1;
		if (t1 != 0u)
		{
			d_2 = (uint32_t)(uint8_t)(a + 0x30u) << 8;
			u = sub_022730(u, d_2);
		}
		t2 = unk_48F8;
		t3 = t2 + 0x10u;
		unk_48F8 = t3;
		d_2 = (uint32_t)(uint8_t)((unk_48F0 & 0xFu) + 0x30u) << 8;
		u = sub_022730(u, d_2);
		unk_48F2 = 3u;
		unk_48F8 = 0xB8u;
		do
		{
			t4 = x;
			x = t4 + 1u;
			d_2 = (uint32_t)mem_read8(t4) << 8;
			u = sub_022730(u, d_2);
			t5 = unk_48F8;
			t6 = t5 + 0x10u;
			unk_48F8 = t6;
			t7 = unk_48F2;
			unk_48F2 = t7 - 1u;
		} while (t7 != 1u);
		unk_48F8 = 0xE0u;
		unk_48F2 = 4u;
		t8 = x;
		x_2 = t8 + 2u;
		t9 = mem_read16(t8);
		stack_3 = t9;
		stack_4 = t9 >> 8;
		unk_48F3 = 0u;
		do
		{
			if (unk_48F3 != 0u || unk_48F2 == 1u || (stack_4 & ~0xFu) != 0u)
			{
				d_2 = (uint32_t)(uint8_t)(((((stack_4 >> 1) >> 1) >> 1) >> 1) + 0x30u) << 8;
				u = sub_022730(u, d_2);
				unk_48F3++;
			}
			t10 = ((uint32_t)stack_4 << 8) | stack_3;
			t11 = (uint32_t)t10 << 4;
			t12 = t11;
			stack_4 = t12 >> 8;
			stack_3 = t12;
			t13 = unk_48F8;
			t14 = t13 + 0x10u;
			unk_48F8 = t14;
			t15 = unk_48F2;
			unk_48F2 = t15 - 1u;
		} while (t15 != 1u);
		unk_48F8 = 0x128u;
		stack_3 = mem_read8(x_2);
		icons = high_score_icons_ADDRESS;
		stack_5 = u >> 8;
		stack_4 = (uint8_t)u;
		b = ((((uint8_t)(((uint16_t)(((uint32_t)stack_5 << 8) | stack_4) >> 3) + (uint8_t)unk_4815) >> 1) >> 1) >> 1) >> 1;
		if ((b & 4u) == 0u)
			b = 0u;
		d_2 = (uint32_t)(uint8_t)((b & 3u) + HIGH_SCORE_ICON(icons + (int8_t)stack_3)) << 8;
		u = sub_022730(u, d_2);
		unk_48F8 = 0x88u;
		t16 = unk_48FA;
		t17 = t16 - 0x18u;
		unk_48FA = t17;
		a = unk_48F0;
		half_carry = ((uint8_t)(a ^ 1u ^ (a + 1u)) >> 4) & 1u;
		carry = (uint8_t)(a + 1u) < a;
		unk_48F0 = konami_daa((uint8_t)(a + 1u), half_carry, carry);
		x = (((uint32_t)stack_2 << 8) | stack) + 8u;
		t18 = unk_48F1;
		unk_48F1 = t18 - 1u;
	} while (t18 != 1u);
}

uint16_t sub_022730(uint16_t u, uint16_t d)
{
	uint16_t d_2 = 0;
	uint8_t stack = 0;
	uint32_t unk_48E8_halfword = 0;

	stack = (uint8_t)d;
	unk_48E8_halfword = ((uint32_t)sprite_font_code_high[0] << 8) | sprite_font_codes[(int8_t)((uint8_t)((d >> 8) - 0x30u))];
	unk_48E8 = (uint8_t)(unk_48E8_halfword >> 8u);
	unk_48E9 = (uint8_t)unk_48E8_halfword;
	d_2 = stack;
	u = sub_022757(u, d_2);
	return u;
}

void unused_022748(uint16_t x, uint16_t u)
{
	uint16_t d = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + (int8_t)((uint32_t)unk_48EA << 1));
	unk_48E8 = (uint8_t)(t1 >> 8u);
	unk_48E9 = (uint8_t)t1;
	d = 0xFu;
	sub_022757(u, d);
}

uint16_t sub_022757(uint16_t u, uint16_t d)
{
	uint8_t a = 0;
	uint8_t stack = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	stack = d >> 8;
	a = unk_480F | 2u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
	io_write8(u, stack | 0x80u);
	mem_write16(u + 0xCu, d | 0x20u);
	t1 = (((uint32_t)unk_48E8 << 8u) | unk_48E9);
	mem_write16(u + 2u, t1);
	t2 = unk_48F8;
	mem_write16(u + 6u, t2);
	t3 = unk_48FA;
	mem_write16(u + 4u, t3);
	mem_write16(u + 8u, 0x40u);
	mem_write16(u + 0xAu, 0x40u);
	u += 0x10u;
	a = unk_480F & ~3u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
	return u;
}

void sub_0227B5(uint16_t u)
{
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, x = 0;
	uint8_t t1 = 0, t2 = 0;

	d = 0u;
	sub_078656(d);
	unk_487E = 1u;
	d = 0xF90u;
	sub_078677(d, &ignored16, &u);
	unk_487E = 2u;
	d = 0x3Au;
	sub_078677(d, &ignored16, &u);
	d = 0xFFF0u;
	sub_0786C2(d);
	d = 0u;
	sub_0786C5(d);
	sub_07868C(&ignored16_2, &ignored16_3);
	sub_07868F(&ignored16_2, &ignored16);
	x = unk_4F80_ADDRESS;
	d = 0x800u;
	sub_0786B3(x, d);
	t1 = io_read8(VIDEO_18E6);
	io_write8(VIDEO_18E6, 0u);
	t2 = io_read8(VIDEO_18E0);
	io_write8(VIDEO_18E0, t2 + 1u);
}

void sub_0227F4(void)
{
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, y = 0;
	uint8_t t1 = 0;

	if (unk_485D != 0u)
		return;
	io_write8(IO_1FB9, 0x3Fu);
	io_write8(IO_1FBA, 0x36u);
	unk_4875 = 0x8Eu;
	unk_4876 = 0u;
	sub_0786B0();
	d = 0x26u;
	sub_0786AD(d, &ignored16, &ignored16_2, &ignored16_3);
	d = 0x126u;
	sub_0786AD(d, &ignored16, &ignored16_2, &ignored16_3);
	io_write8(IO_1FB9, 0x13u);
	io_write8(IO_1FBA, 0x2Cu);
	d &= 0xFFu;
	sub_022A1C(d);
	d |= 0x100u;
	y = sub_022A1C(d);
	mem_write8(y + 0xAu, 0x40u);
	mem_write8(y + 0xBu, 0x40u);
	t1 = io_read8(VIDEO_18E0);
	io_write8(VIDEO_18E0, t1 + 1u);
}

void sub_022847(void)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	sub_022940(0u);
	sub_02298F();
	carry = sub_02291E();
	if (carry == 0u)
		return;
	d = 0x400u;
	sub_022A1C(d);
	t1 = io_read8(VIDEO_18E0);
	io_write8(VIDEO_18E0, t1 + 1u);
}

void sub_02285C(void)
{
	uint32_t carry = 0;
	uint16_t d = 0, y = 0;
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0;

	sub_022940(0u);
	unk_4DA6 = 0x40u;
	if ((unk_4D46 & 2u) == 0u)
		return;
	d = 0x101u;
	carry = sub_078680(d);
	d = 0x501u;
	y = sub_022A1C(d);
	t1 = mem_read16(y + 0x11u);
	t2 = t1 - 2u;
	mem_write16(y + 0x11u, t2);
	mem_write16(y + 0xFu, 0xFFF0u);
	mem_write16(y + 0x19u, 0x1E0u);
	mem_write8(y + 0xAu, 0x40u);
	mem_write8(y + 0xBu, 0x40u);
	t3 = io_read8(VIDEO_18E0);
	io_write8(VIDEO_18E0, t3 + 1u);
}

void sub_02289A(void)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	sub_022940(0u);
	carry = sub_0229C0();
	unk_4DA6 = 0x40u;
	if ((unk_4D46 & 1u) == 0u)
		return;
	t1 = io_read8(VIDEO_18E0);
	io_write8(VIDEO_18E0, t1 + 1u);
}

void sub_0228B4(uint16_t u)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0;
	uint8_t t1 = 0;

	unk_4DA6 = 0x40u;
	u = sub_022940(u);
	carry = sub_0229C0();
	if (carry)
	{
		unk_487E = 4u;
		d = 0x440u;
		sub_078677(d, &ignored16, &u);
		unk_487E = 4u;
		d = 0x840u;
		sub_078677(d, &ignored16, &u);
		unk_487E = 4u;
		d = 0x220u;
		sub_078677(d, &ignored16, &u);
		io_write16(VIDEO_18E2, 0x180u);
		t1 = io_read8(VIDEO_18E0);
		io_write8(VIDEO_18E0, t1 + 1u);
		return;
	}
	sub_0229FF();
}

void sub_0228F3(uint16_t u)
{
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0;
	uint16_t t1 = 0, t2 = 0;

	unk_4DA6 = 0x40u;
	sub_0229FF();
	t1 = io_read16(VIDEO_18E2);
	io_write16(VIDEO_18E2, t1 - 1u);
	if (t1 == 1u)
	{
		sub_07868C(&ignored16_2, &ignored16_3);
		unk_4872 = 0u;
		return;
	}
	t2 = io_read16(VIDEO_18E2);
	if (t2 == 0x80u)
	{
		unk_487E = 2u;
		d = 0x48u;
		sub_078677(d, &ignored16, &u);
	}
}

uint32_t sub_02291E(void)
{
	uint32_t carry = 0;
	uint8_t a = 0, d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;
	uint16_t t4 = 0, t5 = 0;

	t1 = io_read8(VIDEO_18EA);
	if (t1 != 0x68u)
	{
		t2 = io_read8(VIDEO_18EA);
		io_write8(VIDEO_18EA, t2 + 1u);
		carry = 0u;
		return carry;
	}
	t3 = io_read8(VIDEO_18EA);
	io_write8(VIDEO_18EA, 0u);
	t4 = unk_48C5;
	d = (uint8_t)t4;
	a = (uint8_t)(t4 >> 8);
	if ((uint16_t)(((uint32_t)a << 8) | (d & 0xFFu)) == 0x1Bu)
	{
		carry = 1u;
		return carry;
	}
	t5 = (((uint32_t)a << 8) | (d & 0xFFu)) + 1u;
	unk_48C5 = t5;
	t2 = io_read8(VIDEO_18EA);
	io_write8(VIDEO_18EA, t2 + 1u);
	carry = 0u;
	return carry;
}

uint16_t sub_022940(uint16_t u)
{
	uint16_t d = 0, ignored16 = 0, u_2 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0;

	t1 = io_read8(VIDEO_18E4);
	if (t1 != 0u)
	{
		t2 = io_read8(VIDEO_18E4);
		io_write8(VIDEO_18E4, t2 - 1u);
		return u;
	}
	t3 = io_read8(VIDEO_18E6);
	u_2 = staff_roll_names[(int8_t)((uint8_t)((uint32_t)t3 << 1)) / 2];
	sub_0786CB(u_2);
	t4 = io_read8(VIDEO_18E6);
	u_2 = staff_roll_titles[(int8_t)((uint8_t)((uint32_t)t4 << 1)) / 2];
	sub_0786B6(u_2);
	t5 = io_read8(VIDEO_18E6);
	io_write8(VIDEO_18E6, t5 + 1u);
	t6 = io_read8(VIDEO_18E6);
	u_2 = staff_roll_names[(int8_t)((uint8_t)((uint32_t)t6 << 1)) / 2];
	d = unk_4000_ADDRESS;
	sub_0786C8(u_2, d);
	t7 = io_read8(VIDEO_18E6);
	u_2 = staff_roll_titles[(int8_t)((uint8_t)((uint32_t)t7 << 1)) / 2];
	d = 0u;
	sub_0785A5(d, &ignored16, &u_2);
	io_write8(VIDEO_18E4, 0xA0u);
	return u_2;
}

void sub_02298F(void)
{
	uint8_t a = 0, d = 0;
	uint16_t d_2 = 0;
	uint8_t t1 = 0, t5 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0;

	t1 = io_read8(VIDEO_18E9);
	t2 = ending_family_waits[(int8_t)((uint8_t)((uint32_t)t1 << 1)) / 2];
	d = (uint8_t)t2;
	a = (uint8_t)(t2 >> 8);
	if ((uint16_t)(((uint32_t)a << 8) | (d & 0xFFu)) == 0xFFFFu)
		return;
	t3 = io_read16(VIDEO_18E7);
	if (t3 < (uint16_t)(((uint32_t)a << 8) | (d & 0xFFu)))
	{
		t4 = io_read16(VIDEO_18E7);
		io_write16(VIDEO_18E7, t4 + 1u);
		return;
	}
	if ((unk_4D46 & 1u) == 0u)
		return;
	d_2 = (d & 0xFFu) | 0x200u;
	sub_022A1C(d_2);
	io_write16(VIDEO_18E7, 0u);
	t5 = io_read8(VIDEO_18E9);
	io_write8(VIDEO_18E9, t5 + 1u);
}

uint32_t sub_0229C0(void)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t x = 0;
	uint8_t t3 = 0, t4 = 0, t5 = 0;
	uint16_t t1 = 0, t2 = 0;

	x = unk_4E00_ADDRESS;
	unk_4E00 |= 0x10u;
	t1 = unk_4E19;
	t2 = t1 - 4u;
	unk_4E19 = t2;
	unk_4E28++;
	if (unk_4E28 != 3u)
	{
		carry = 0u;
		return carry;
	}
	unk_4E28 = 0u;
	t3 = mem_read8(x + 0xAu);
	a = t3 - 1u;
	if (a != 0x30u)
	{
		mem_write8(x + 0xAu, a);
		mem_write8(x + 0xBu, a);
		carry = 0u;
		return carry;
	}
	t4 = mem_read8(x + 5u);
	if (t4 == 7u)
	{
		unk_4E00 = 0u;
		carry = 1u;
		return carry;
	}
	t5 = mem_read8(x + 5u);
	mem_write8(x + 5u, t5 + 1u);
	a = 0x60u;
	mem_write8(x + 0xAu, a);
	mem_write8(x + 0xBu, a);
	carry = 0u;
	return carry;
}

void sub_0229FF(void)
{
	uint16_t x = 0;
	uint8_t t1 = 0, t2 = 0;

	x = unk_4D40_ADDRESS;
	unk_4D40 |= 0x10u;
	unk_4D59 = 4u;
	if ((unk_4815 & 0xFu) == 0u)
	{
		t1 = unk_4D4A;
		unk_4D4A = t1 + 1u;
		t2 = mem_read8(x + 0xBu);
		mem_write8(x + 0xBu, t2 + 1u);
	}
}

uint16_t sub_022A1C(uint16_t d)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t object = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, kind = 0, t4 = 0, x = 0, z = 0;

	a = (uint8_t)(d >> 8);
	t1 = a | 0x1000u;
	b = (uint8_t)t1;
	carry = (int8_t)b < 0;
	b = (uint32_t)b << 1;
	a = (uint8_t)(((uint32_t)(uint8_t)((uint32_t)a << 8) << 1) | carry);
	carry = (int8_t)b < 0;
	b = (uint32_t)b << 1;
	a = (uint8_t)(((uint32_t)a << 1) | carry);
	carry = (int8_t)b < 0;
	t2 = ending_placements_ADDRESS + (((((uint32_t)a << 1) | carry) << 8) | (uint8_t)((uint32_t)b << 1));
	object = PLACEMENT(t2)->object;
	mem_write8(object, 0x80u);
	t3 = t2 + 2u;
	kind = PLACEMENT(t3 - 0x2u)->kind;
	io_write16(object + 4u, ((uint32_t)(kind >> 8) << 8) | (uint8_t)(kind | 0x80u));
	t4 = t3 + 2u;
	x = PLACEMENT(t4 - 0x4u)->x;
	io_write16(object + 0xCu, x);
	io_write16(object + 0x11u, 0x80u);
	z = PLACEMENT(t4 - 0x4u)->z;
	io_write16(object + 0x16u, z);
	return object;
}

uint16_t sub_022A70(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_023A21_ADDRESS;
		t1 = mem_read8(x + 0x28u);
		a = t1;
		carry = (int8_t)a < 0;
		switch ((int8_t)(uint8_t)((uint32_t)a << 1))
		{
		case 0:
			sub_022A79(x);
			return y;
		case 2:
			sub_022A88(x, carry);
			return y;
		case 4:
			sub_022AD5(x);
			return y;
		case 6:
			sub_022AFE(x);
			return y;
		case 8:
			return sub_022B0C(x, y);
		case 10:
			sub_022B23(x);
			return y;
		case 12:
			return sub_022B2E(x, y);
		case 14:
			return sub_022B43(x);
		case 16:
			sub_022BC8(x);
			return y;
		case 18:
			sub_022BE7(x);
			return y;
		case 20:
			sub_022C10(x);
			return y;
		case 22:
			sub_022C22(x);
			return y;
		case 24:
			sub_022C5D(x);
			return y;
		case 26:
			sub_022C6D(x);
			return y;
		case 28:
			sub_022CB3(x);
			return y;
		case 30:
			sub_022CD1(x);
			return y;
		case 32:
			return sub_022CF2(x, y);
		case 34:
			sub_022D07(x);
			return y;
		case 36:
			return sub_022D6D(x, y);
		case 38:
			sub_022D82(x);
			return y;
		case 40:
			sub_022D95(x);
			return y;
		case 42:
			break;
		case -22:
			sub_079423();
			return y;
		case -20:
			continue;
		case -18:
			return sub_022ACC(x, y);
		case -16:
			return sub_022B1A(x, y);
		case -14:
			return sub_022B3A(x, y);
		case -12:
			return sub_022C80(x, y);
		case -10:
			return sub_022CAA(x, y);
		case -8:
			return sub_022CFE(x, y);
		case -6:
			return sub_022D79(x, y);
		case -4:
			return sub_022DB6(x, y, u);
		case -2:
			return sub_022DD6(x, y);
		}
		break;
	}
	sub_022DAD(x);
	return y;
}

void sub_022A79(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 - 1u);
	if (t1 != 1u)
		return;
	d = 0x3F3Bu;
	carry = sub_078680(d);
	t2 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t2 + 1u);
}

void sub_022A88(uint16_t x, uint32_t carry)
{
	uint8_t a = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	mem_write8(x, mem_read8(x) & 0x7Fu);
	a = (uint8_t)unk_4815 & 1u;
	t1 = (a >> 1) | (carry << 7);
	carry = a >> 0;
	mem_write8(x, (t1 >> 1) | (carry << 7) | mem_read8(x));
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	t3 = mem_read8(x + 0x29u);
	if (t3 != 0xC0u)
		return;
	d = 0x9600u;
	carry = sub_078680(d);
	t4 = mem_read8(x + 0x27u);
	mem_write8(x + 0x27u, t4 | 0x81u);
	mem_write8(x, 0u);
	unk_487D = 1u;
	unk_4804++;
	unk_4805 = 0x100u;
}

uint16_t sub_022ACC(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_023A25_ADDRESS;
		t1 = mem_read8(x + 0x28u);
		a = t1;
		carry = (int8_t)a < 0;
		switch ((int8_t)(uint8_t)((uint32_t)a << 1))
		{
		case 0:
			sub_022AD5(x);
			return y;
		case 2:
			sub_022AFE(x);
			return y;
		case 4:
			return sub_022B0C(x, y);
		case 6:
			sub_022B23(x);
			return y;
		case 8:
			return sub_022B2E(x, y);
		case 10:
			return sub_022B43(x);
		case 12:
			sub_022BC8(x);
			return y;
		case 14:
			sub_022BE7(x);
			return y;
		case 16:
			sub_022C10(x);
			return y;
		case 18:
			sub_022C22(x);
			return y;
		case 20:
			sub_022C5D(x);
			return y;
		case 22:
			sub_022C6D(x);
			return y;
		case 24:
			sub_022CB3(x);
			return y;
		case 26:
			sub_022CD1(x);
			return y;
		case 28:
			return sub_022CF2(x, y);
		case 30:
			sub_022D07(x);
			return y;
		case 32:
			return sub_022D6D(x, y);
		case 34:
			sub_022D82(x);
			return y;
		case 36:
			sub_022D95(x);
			return y;
		case 38:
			break;
		case -26:
			sub_079423();
			return y;
		case -24:
			return sub_022A70(x, y);
		case -22:
			continue;
		case -20:
			return sub_022B1A(x, y);
		case -18:
			return sub_022B3A(x, y);
		case -16:
			return sub_022C80(x, y);
		case -14:
			return sub_022CAA(x, y);
		case -12:
			return sub_022CFE(x, y);
		case -10:
			return sub_022D79(x, y);
		case -8:
			return sub_022DB6(x, y, u);
		case -6:
			return sub_022DD6(x, y);
		case -4:
			sub_022A79(x);
			return y;
		case -2:
			sub_022A88(x, carry);
			return y;
		}
		break;
	}
	sub_022DAD(x);
	return y;
}

void sub_022AD5(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t4 = 0, t5 = 0;
	uint16_t t3 = 0;

	sub_0785B1(x, &d, &carry);
	if (carry == 0u)
		return;
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	t1 = mem_read8(x + 0x1Bu);
	if (t1 <= stage_7_boss_beaten_health_by_players[(int8_t)((uint8_t)(unk_4857 - 1u))])
	{
		mem_write8(x, (mem_read8(x) & 0xBFu) | 4u);
		d = (d & 0xFFu) | 0x800u;
		carry = sub_022E9E(x, d);
		t2 = io_read8(VIDEO_187E);
		io_write8(VIDEO_187E, t2 + 1u);
		d = 0x9800u;
		carry = sub_078680(d);
		t3 = mem_read16(x + 0x25u);
		t4 = mem_read8(t3 + 0x5Bu);
		mem_write8(x + 0x27u, t4 & ~0xFu);
		mem_write8(x + 0x29u, 0xC0u);
		mem_write8(x + 0x1Bu, 0u);
		mem_write8(x + 2u, 0xFDu);
		mem_write8(x + 0x28u, 0u);
		return;
	}
	d = (d & 0xFFu) | 0xB00u;
	carry = sub_022E9E(x, d);
	mem_write8(x + 0x29u, 0x40u);
	t5 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t5 + 1u);
}

void sub_022AFE(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 - 1u);
	if (t1 != 1u)
		return;
	d = 0x700u;
	carry = sub_022E9E(x, d);
	t2 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t2 + 1u);
}

uint16_t sub_022B0C(uint16_t x, uint16_t y)
{
	uint16_t u = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) == 0u)
		return y;
	u = sub_022FAC(x);
	return sub_022E40(x, y, u);
}

uint16_t sub_022B1A(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_023A2B_ADDRESS;
		t1 = mem_read8(x + 0x28u);
		a = t1;
		carry = (int8_t)a < 0;
		switch ((int8_t)(uint8_t)((uint32_t)a << 1))
		{
		case 0:
			sub_022B23(x);
			return y;
		case 2:
			return sub_022B2E(x, y);
		case 4:
			return sub_022B43(x);
		case 6:
			sub_022BC8(x);
			return y;
		case 8:
			sub_022BE7(x);
			return y;
		case 10:
			sub_022C10(x);
			return y;
		case 12:
			sub_022C22(x);
			return y;
		case 14:
			sub_022C5D(x);
			return y;
		case 16:
			sub_022C6D(x);
			return y;
		case 18:
			sub_022CB3(x);
			return y;
		case 20:
			sub_022CD1(x);
			return y;
		case 22:
			return sub_022CF2(x, y);
		case 24:
			sub_022D07(x);
			return y;
		case 26:
			return sub_022D6D(x, y);
		case 28:
			sub_022D82(x);
			return y;
		case 30:
			sub_022D95(x);
			return y;
		case 32:
			break;
		case -32:
			sub_079423();
			return y;
		case -30:
			return sub_022A70(x, y);
		case -28:
			return sub_022ACC(x, y);
		case -26:
			continue;
		case -24:
			return sub_022B3A(x, y);
		case -22:
			return sub_022C80(x, y);
		case -20:
			return sub_022CAA(x, y);
		case -18:
			return sub_022CFE(x, y);
		case -16:
			return sub_022D79(x, y);
		case -14:
			return sub_022DB6(x, y, u);
		case -12:
			return sub_022DD6(x, y);
		case -10:
			sub_022A79(x);
			return y;
		case -8:
			sub_022A88(x, carry);
			return y;
		case -6:
			sub_022AD5(x);
			return y;
		case -4:
			sub_022AFE(x);
			return y;
		case -2:
			return sub_022B0C(x, y);
		}
		break;
	}
	sub_022DAD(x);
	return y;
}

void sub_022B23(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) != 0u)
	{
		t2 = mem_read8(x + 0x28u);
		mem_write8(x + 0x28u, t2 + 1u);
	}
}

uint16_t sub_022B2E(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, u = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry == 0u)
		return y;
	u = sub_022FAC(x);
	y = sub_022E40(x, y, u);
	return y;
}

uint16_t sub_022B3A(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_023A2F_ADDRESS;
		t1 = mem_read8(x + 0x28u);
		a = t1;
		carry = (int8_t)a < 0;
		switch ((int8_t)(uint8_t)((uint32_t)a << 1))
		{
		case 0:
			return sub_022B43(x);
		case 2:
			sub_022BC8(x);
			return y;
		case 4:
			sub_022BE7(x);
			return y;
		case 6:
			sub_022C10(x);
			return y;
		case 8:
			sub_022C22(x);
			return y;
		case 10:
			sub_022C5D(x);
			return y;
		case 12:
			sub_022C6D(x);
			return y;
		case 14:
			sub_022CB3(x);
			return y;
		case 16:
			sub_022CD1(x);
			return y;
		case 18:
			return sub_022CF2(x, y);
		case 20:
			sub_022D07(x);
			return y;
		case 22:
			return sub_022D6D(x, y);
		case 24:
			sub_022D82(x);
			return y;
		case 26:
			sub_022D95(x);
			return y;
		case 28:
			break;
		case -36:
			sub_079423();
			return y;
		case -34:
			return sub_022A70(x, y);
		case -32:
			return sub_022ACC(x, y);
		case -30:
			return sub_022B1A(x, y);
		case -28:
			continue;
		case -26:
			return sub_022C80(x, y);
		case -24:
			return sub_022CAA(x, y);
		case -22:
			return sub_022CFE(x, y);
		case -20:
			return sub_022D79(x, y);
		case -18:
			return sub_022DB6(x, y, u);
		case -16:
			return sub_022DD6(x, y);
		case -14:
			sub_022A79(x);
			return y;
		case -12:
			sub_022A88(x, carry);
			return y;
		case -10:
			sub_022AD5(x);
			return y;
		case -8:
			sub_022AFE(x);
			return y;
		case -6:
			return sub_022B0C(x, y);
		case -4:
			sub_022B23(x);
			return y;
		case -2:
			return sub_022B2E(x, y);
		}
		break;
	}
	sub_022DAD(x);
	return y;
}

uint16_t sub_022B43(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t d = 0;
	uint16_t d_2 = 0, helper_start = 0, u = 0;
	uint8_t t7 = 0;
	uint16_t t1 = 0, t2 = 0, x_2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;

	unk_48F0 = 0u;
	do
	{
		d = 1u;
		sub_07867D(d, &u, &carry);
		mem_write8(u, 0x80u);
		mem_write8(u + 4u, 0x12u);
		t1 = stage_7_boss_helper_starts_ADDRESS + (int8_t)(((uint32_t)unk_48F0 << 1) << 1);
		mem_write8(u + 5u, HELPER_START(t1)->animation);
		mem_write8(u + 9u, 0x20u);
		t2 = t1 + 1u;
		helper_start = t2 + 2u;
		x_2 = HELPER_START(t2 - 0x1u)->x;
		t3 = x_2 + 0x91Fu;
		t4 = t3 - unk_48AC;
		mem_write16(u + 0xCu, t4);
		t5 = 0xC8u + unk_48B2;
		mem_write16(u + 0x11u, t5);
		mem_write16(u + 0x16u, 0x20u);
		mem_write8(u + 1u, 0x37u);
		mem_write16(x + (int8_t)HELPER_START(helper_start - 0x3u)->slot, u);
		unk_48F0++;
	} while (unk_48F0 != 4u);
	mem_write8(x, 0x80u);
	mem_write8(x + 9u, 0x20u);
	mem_write8(x + 0x57u, 1u);
	mem_write8(x + 0x5Bu, 1u);
	d_2 = 0x101u;
	carry = sub_022E9E(x, d_2);
	t6 = 0x96Fu - unk_48AC;
	mem_write16(x + 0xCu, t6);
	mem_write8(x + 0x1Bu, 0xE0u);
	mem_write8(x + VIDEO_002F, 0xE0u);
	mem_write16(x + 0x5Cu, 0x20u);
	t7 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t7 + 1u);
	return helper_start;
}

void sub_022BC8(uint16_t x)
{
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0;

	if (unk_4892 == 0u)
	{
		mem_write8(x + 0x57u, 0u);
		unk_487C++;
		t1 = mem_read16(x + 0x35u);
		mem_write8(t1 + 2u, 3u);
		t2 = mem_read16(x + 0x37u);
		mem_write8(t2 + 2u, 1u);
		t3 = mem_read8(x + 0x28u);
		mem_write8(x + 0x28u, t3 + 1u);
	}
}

void sub_022BE7(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t2 = 0, t6 = 0;
	uint16_t t1 = 0, t3 = 0, t4 = 0, t5 = 0;

	t1 = mem_read16(x + 0x35u);
	u = t1;
	t2 = mem_read8(u + 2u);
	if (t2 == 0u)
	{
		mem_write8(u + 2u, 3u);
		t3 = mem_read16(x + 0x37u);
		mem_write8(t3 + 2u, 1u);
		t4 = mem_read16(x + 0x33u);
		mem_write8(t4 + 2u, 3u);
		t5 = mem_read16(x + 0x39u);
		mem_write8(t5 + 2u, 1u);
		t6 = mem_read8(x + 0x28u);
		mem_write8(x + 0x28u, t6 + 1u);
	}
}

void sub_022C10(uint16_t x)
{
	uint8_t t2 = 0, t3 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x35u);
	t2 = mem_read8(t1 + 2u);
	if (t2 == 0u)
	{
		mem_write16(x + 0x14u, rom_07FFC0_ADDRESS);
		t3 = mem_read8(x + 0x28u);
		mem_write8(x + 0x28u, t3 + 1u);
	}
}

void sub_022C22(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t7 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;

	t1 = mem_read16(x + 0x11u);
	t2 = t1 - unk_48B2;
	if ((int16_t)t2 > 0xC8)
		return;
	mem_write8(x + 9u, 0u);
	mem_write16(x + 0x14u, 0u);
	d = 0xD00u;
	carry = sub_022E9E(x, d);
	t3 = mem_read16(x + 0x35u);
	mem_write8(t3 + 2u, 6u);
	t4 = mem_read16(x + 0x37u);
	mem_write8(t4 + 2u, 5u);
	t5 = mem_read16(x + 0x33u);
	mem_write8(t5 + 2u, 4u);
	t6 = mem_read16(x + 0x39u);
	mem_write8(t6 + 2u, 2u);
	t7 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t7 + 1u);
}

void sub_022C5D(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) != 0u)
	{
		mem_write8(x + 0x29u, 0x40u);
		t2 = mem_read8(x + 0x28u);
		mem_write8(x + 0x28u, t2 + 1u);
	}
}

void sub_022C6D(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x, 0xC0u);
		mem_write8(x + 0x28u, 0u);
		mem_write8(x + 2u, 1u);
	}
}

uint16_t sub_022C80(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t d = 0, u = 0;
	uint8_t t1 = 0, t2 = 0;

	sub_022DF2(x, &u, &carry);
	if (carry)
		return y;
	sub_022E40(x, y, u);
	t1 = mem_read8(x + 5u);
	if (t1 != 0u)
	{
		d = 0x100u;
		carry = sub_022E9E(x, d);
	}
	sub_022E65(x);
	t2 = mem_read8(x + 0x2Du);
	y = stage_7_boss_speeds_by_rank_ADDRESS;
	d = ((uint32_t)t2 << 8) | stage_7_boss_speeds_by_rank[unk_4861 >> 1];
	sub_078617(x, d);
	sub_022E83(x);
	return y;
}

uint16_t sub_022CAA(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_023A3D_ADDRESS;
		t1 = mem_read8(x + 0x28u);
		a = t1;
		carry = (int8_t)a < 0;
		switch ((int8_t)(uint8_t)((uint32_t)a << 1))
		{
		case 0:
			sub_022CB3(x);
			return y;
		case 2:
			sub_022CD1(x);
			return y;
		case 4:
			return sub_022CF2(x, y);
		case 6:
			sub_022D07(x);
			return y;
		case 8:
			return sub_022D6D(x, y);
		case 10:
			sub_022D82(x);
			return y;
		case 12:
			sub_022D95(x);
			return y;
		case 14:
			break;
		case -50:
			sub_079423();
			return y;
		case -48:
			return sub_022A70(x, y);
		case -46:
			return sub_022ACC(x, y);
		case -44:
			return sub_022B1A(x, y);
		case -42:
			return sub_022B3A(x, y);
		case -40:
			return sub_022C80(x, y);
		case -38:
			continue;
		case -36:
			return sub_022CFE(x, y);
		case -34:
			return sub_022D79(x, y);
		case -32:
			return sub_022DB6(x, y, u);
		case -30:
			return sub_022DD6(x, y);
		case -28:
			sub_022A79(x);
			return y;
		case -26:
			sub_022A88(x, carry);
			return y;
		case -24:
			sub_022AD5(x);
			return y;
		case -22:
			sub_022AFE(x);
			return y;
		case -20:
			return sub_022B0C(x, y);
		case -18:
			sub_022B23(x);
			return y;
		case -16:
			return sub_022B2E(x, y);
		case -14:
			return sub_022B43(x);
		case -12:
			sub_022BC8(x);
			return y;
		case -10:
			sub_022BE7(x);
			return y;
		case -8:
			sub_022C10(x);
			return y;
		case -6:
			sub_022C22(x);
			return y;
		case -4:
			sub_022C5D(x);
			return y;
		case -2:
			sub_022C6D(x);
			return y;
		}
		break;
	}
	sub_022DAD(x);
	return y;
}

void sub_022CB3(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x29u);
	if (t1 != 0u)
	{
		t2 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t2 - 1u);
		return;
	}
	d = 0x6A00u;
	carry = sub_078680(d);
	d = 0x200u;
	carry = sub_022E9E(x, d);
	mem_write8(x, mem_read8(x) | 4u);
	t3 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t3 + 1u);
}

void sub_022CD1(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d = 0, ignored16 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	a = 0u;
	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) != 0u)
		a = 1u;
	d = (uint32_t)a << 8;
	sub_022EAD(x, &ignored16, &d);
	t2 = mem_read8(x + 6u);
	if ((t2 & 1u) == 0u)
		return;
	d &= 0xFFu;
	carry = sub_022E9E(x, d);
	mem_write8(x + 0x29u, 0x10u);
	t3 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t3 + 1u);
}

uint16_t sub_022CF2(uint16_t x, uint16_t y)
{
	uint16_t u = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 - 1u);
	if (t1 != 1u)
		return y;
	u = sub_022FAC(x);
	y = sub_022E40(x, y, u);
	return y;
}

uint16_t sub_022CFE(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_023A43_ADDRESS;
		t1 = mem_read8(x + 0x28u);
		a = t1;
		carry = (int8_t)a < 0;
		switch ((int8_t)(uint8_t)((uint32_t)a << 1))
		{
		case 0:
			sub_022D07(x);
			return y;
		case 2:
			return sub_022D6D(x, y);
		case 4:
			sub_022D82(x);
			return y;
		case 6:
			sub_022D95(x);
			return y;
		case 8:
			break;
		case -56:
			sub_079423();
			return y;
		case -54:
			return sub_022A70(x, y);
		case -52:
			return sub_022ACC(x, y);
		case -50:
			return sub_022B1A(x, y);
		case -48:
			return sub_022B3A(x, y);
		case -46:
			return sub_022C80(x, y);
		case -44:
			return sub_022CAA(x, y);
		case -42:
			continue;
		case -40:
			return sub_022D79(x, y);
		case -38:
			return sub_022DB6(x, y, u);
		case -36:
			return sub_022DD6(x, y);
		case -34:
			sub_022A79(x);
			return y;
		case -32:
			sub_022A88(x, carry);
			return y;
		case -30:
			sub_022AD5(x);
			return y;
		case -28:
			sub_022AFE(x);
			return y;
		case -26:
			return sub_022B0C(x, y);
		case -24:
			sub_022B23(x);
			return y;
		case -22:
			return sub_022B2E(x, y);
		case -20:
			return sub_022B43(x);
		case -18:
			sub_022BC8(x);
			return y;
		case -16:
			sub_022BE7(x);
			return y;
		case -14:
			sub_022C10(x);
			return y;
		case -12:
			sub_022C22(x);
			return y;
		case -10:
			sub_022C5D(x);
			return y;
		case -8:
			sub_022C6D(x);
			return y;
		case -6:
			sub_022CB3(x);
			return y;
		case -4:
			sub_022CD1(x);
			return y;
		case -2:
			return sub_022CF2(x, y);
		}
		break;
	}
	sub_022DAD(x);
	return y;
}

void sub_022D07(uint16_t x)
{
	uint32_t negative = 0, carry = 0;
	uint8_t a = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, u = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0;
	uint16_t t1 = 0;

	d = 0u;
	sub_022EAD(x, &u, &d);
	if ((unk_4815 & 0x3Fu) == 0u)
	{
		d = 0x7600u;
		carry = sub_078680(d);
	}
	t1 = mem_read16(x + 0x3Fu);
	mem_write16(x + 0x3Fu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 0x29u, 0x20u);
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
		d = 0u;
		sub_022EAD(x, &ignored16_2, &d);
		t2 = mem_read8(x + 0x28u);
		mem_write8(x + 0x28u, t2 + 1u);
		return;
	}
	sub_078686(x, &u, &ignored16, &carry);
	if (carry == 0u)
	{
		mem_write8(x + 0x29u, 0x20u);
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
		d = 0u;
		sub_022EAD(x, &ignored16_2, &d);
		t2 = mem_read8(x + 0x28u);
		mem_write8(x + 0x28u, t2 + 1u);
		return;
	}
	t3 = mem_read8(x + 6u);
	if ((t3 & 2u) != 0u)
	{
		d = 0x200u;
		sub_022EAD(x, &u, &d);
	}
	d = sub_07861D(x, u);
	a = (uint8_t)(d >> 8);
	t4 = mem_read8(x + 0x32u);
	negative = (uint8_t)(a - t4) >> 7;
	if (a == t4)
	{
		t5 = mem_read8(x + 0x32u);
		d = ((uint32_t)t5 << 8) | 0x40u;
		sub_078617(x, d);
		t6 = mem_read8(x + 9u);
		a = t6 & 0xBFu;
		t7 = mem_read8(x + 0x32u);
		if ((int8_t)(t7 + 0x40u) < 0)
			a |= 0x40u;
		mem_write8(x + 9u, a);
		return;
	}
	if (negative == 0u)
	{
		t8 = mem_read8(x + 0x32u);
		mem_write8(x + 0x32u, t8 + 1u);
		t5 = mem_read8(x + 0x32u);
		d = ((uint32_t)t5 << 8) | 0x40u;
		sub_078617(x, d);
		t6 = mem_read8(x + 9u);
		a = t6 & 0xBFu;
		t7 = mem_read8(x + 0x32u);
		if ((int8_t)(t7 + 0x40u) < 0)
			a |= 0x40u;
		mem_write8(x + 9u, a);
		return;
	}
	t9 = mem_read8(x + 0x32u);
	mem_write8(x + 0x32u, t9 - 1u);
	t5 = mem_read8(x + 0x32u);
	d = ((uint32_t)t5 << 8) | 0x40u;
	sub_078617(x, d);
	t6 = mem_read8(x + 9u);
	a = t6 & 0xBFu;
	t7 = mem_read8(x + 0x32u);
	if ((int8_t)(t7 + 0x40u) < 0)
		a |= 0x40u;
	mem_write8(x + 9u, a);
}

uint16_t sub_022D6D(uint16_t x, uint16_t y)
{
	uint16_t u = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 - 1u);
	if (t1 != 1u)
		return y;
	u = sub_022FAC(x);
	y = sub_022E40(x, y, u);
	return y;
}

uint16_t sub_022D79(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_023A47_ADDRESS;
		t1 = mem_read8(x + 0x28u);
		a = t1;
		carry = (int8_t)a < 0;
		switch ((int8_t)(uint8_t)((uint32_t)a << 1))
		{
		case 0:
			sub_022D82(x);
			return y;
		case 2:
			sub_022D95(x);
			return y;
		case 4:
			break;
		case -60:
			sub_079423();
			return y;
		case -58:
			return sub_022A70(x, y);
		case -56:
			return sub_022ACC(x, y);
		case -54:
			return sub_022B1A(x, y);
		case -52:
			return sub_022B3A(x, y);
		case -50:
			return sub_022C80(x, y);
		case -48:
			return sub_022CAA(x, y);
		case -46:
			return sub_022CFE(x, y);
		case -44:
			continue;
		case -42:
			return sub_022DB6(x, y, u);
		case -40:
			return sub_022DD6(x, y);
		case -38:
			sub_022A79(x);
			return y;
		case -36:
			sub_022A88(x, carry);
			return y;
		case -34:
			sub_022AD5(x);
			return y;
		case -32:
			sub_022AFE(x);
			return y;
		case -30:
			return sub_022B0C(x, y);
		case -28:
			sub_022B23(x);
			return y;
		case -26:
			return sub_022B2E(x, y);
		case -24:
			return sub_022B43(x);
		case -22:
			sub_022BC8(x);
			return y;
		case -20:
			sub_022BE7(x);
			return y;
		case -18:
			sub_022C10(x);
			return y;
		case -16:
			sub_022C22(x);
			return y;
		case -14:
			sub_022C5D(x);
			return y;
		case -12:
			sub_022C6D(x);
			return y;
		case -10:
			sub_022CB3(x);
			return y;
		case -8:
			sub_022CD1(x);
			return y;
		case -6:
			return sub_022CF2(x, y);
		case -4:
			sub_022D07(x);
			return y;
		case -2:
			return sub_022D6D(x, y);
		}
		break;
	}
	sub_022DAD(x);
	return y;
}

void sub_022D82(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	sub_0785B1(x, &d, &carry);
	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) == 0u)
		return;
	d = (d & 0xFFu) | 0xC00u;
	carry = sub_022E9E(x, d);
	t2 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t2 + 1u);
}

void sub_022D95(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0;
	uint8_t t1 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry == 0u)
		return;
	mem_write16(x + 0xFu, 0u);
	mem_write8(x, mem_read8(x) & ~8u);
	d = 0xA00u;
	carry = sub_022E9E(x, d);
	t1 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t1 + 1u);
}

void sub_022DAD(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) != 0u)
	{
		sub_022FAC(x);
		return;
	}
}

uint16_t sub_022DB6(uint16_t x, uint16_t y, uint16_t u)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;

	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	sub_078686(x, &u, &ignored16, &carry);
	if (carry)
	{
		mem_write8(x, mem_read8(x) | 0x40u);
		mem_write8(x + 2u, 1u);
		mem_write8(x + 0x28u, 0u);
		y = sub_022E40(x, y, u);
	}
	return y;
}

uint16_t sub_022DD6(uint16_t x, uint16_t y)
{
	uint16_t y_2 = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(y + 0x2Bu);
	y_2 = t1;
	t2 = mem_read8(y_2 + 2u);
	if ((int8_t)t2 >= 0)
	{
		sub_022FAC(x);
		return y_2;
	}
	return y_2;
}

uint16_t sub_022DE0(uint16_t x, uint16_t y)
{
	uint32_t negative = 0;
	uint8_t t1 = 0;

	if ((mem_read8(x) & 0x20u) != 0u)
	{
		t1 = mem_read8(x + 0x1Eu);
		negative = t1 >> 7;
		if (t1 != 0u && negative == 0u)
			y = sub_023016(x, y);
	}
	return y;
}

void sub_022DF2(uint16_t x, uint16_t *p_u, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t a = 0;
	uint16_t d = 0, u = 0, wait = 0;
	uint8_t t4 = 0, t6 = 0, t19 = 0, t20 = 0, t21 = 0, t22 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t5 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0, t15 = 0, t16 = 0, t17 = 0, t18 = 0;

	t1 = mem_read16(x + 0x2Bu);
	wait = t1;
	t2 = mem_read16(x + 0xCu);
	t3 = mem_read16(wait + 0xCu);
	if ((int16_t)t2 < (int16_t)t3)
	{
		t4 = mem_read8(x + 9u);
		if ((t4 & 0x40u) != 0u)
		{
			t5 = mem_read16(x + 0x3Du);
			mem_write16(x + 0x3Du, t5 + 1u);
			carry = 0u;
			*p_u = wait;
			*p_carry = carry;
			return;
		}
	}
	else
	{
		t6 = mem_read8(x + 9u);
		if ((t6 & 0x40u) == 0u)
		{
			t5 = mem_read16(x + 0x3Du);
			mem_write16(x + 0x3Du, t5 + 1u);
			carry = 0u;
			*p_u = wait;
			*p_carry = carry;
			return;
		}
	}
	t7 = mem_read16(x + 0xCu);
	t8 = mem_read16(wait + 0xCu);
	t9 = t7 - t8;
	t10 = t9;
	t11 = t10 >> 15 ? 0u - t10 : t10;
	if ((int16_t)t11 > 0x40)
	{
		wait = stage_7_boss_charge_waits_by_players_ADDRESS + (int8_t)((unk_4857 - 1u) << 1);
		t12 = mem_read16(x + 0x3Du);
		if ((int16_t)t12 < (int16_t)CHARGE_WAIT(wait))
		{
			t5 = mem_read16(x + 0x3Du);
			mem_write16(x + 0x3Du, t5 + 1u);
			carry = 0u;
			*p_u = wait;
			*p_carry = carry;
			return;
		}
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
		mem_write16(x + 0x3Du, 0u);
		mem_write8(x + 2u, 3u);
		mem_write8(x + 0x28u, 0u);
		d = 0x300u;
		carry = sub_022E9E(x, d);
		d = 0x200u;
		sub_022EAD(x, &wait, &d);
		sub_078686(x, &wait, &d, &carry);
		d = sub_078671(x, wait, d);
		a = (uint8_t)(d >> 8);
		mem_write8(x + 0x32u, a);
		d = ((uint32_t)a << 8) | 0x40u;
		sub_078617(x, d);
		mem_write16(x + 0x3Fu, VIDEO_00A0);
		carry = 1u;
		*p_u = wait;
		*p_carry = carry;
		return;
	}
	t13 = mem_read16(x + 0x11u);
	t14 = mem_read16(wait + 0x11u);
	t15 = t13 - t14;
	t16 = t15;
	t17 = t16 >> 15 ? 0u - t16 : t16;
	if ((int16_t)t17 > 8)
	{
		t5 = mem_read16(x + 0x3Du);
		mem_write16(x + 0x3Du, t5 + 1u);
		carry = 0u;
		*p_u = wait;
		*p_carry = carry;
		return;
	}
	t18 = mem_read16(x + 0x2Bu);
	u = t18;
	t19 = mem_read8(u + 2u);
	if ((int8_t)t19 < 0)
	{
		carry = sub_023000(x);
		*p_u = u;
		*p_carry = carry;
		return;
	}
	mem_write8(x + 0x29u, 0u);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write8(x + 2u, 2u);
	mem_write8(x + 0x28u, 0u);
	d = 0x100u;
	carry = sub_022E9E(x, d);
	sub_022E83(x);
	wait = stage_7_boss_quick_attack_chances_by_players_ADDRESS;
	if (stage_7_boss_quick_attack_chances_by_players[(int8_t)((uint8_t)(unk_4857 - 1u))] <= unk_4858)
	{
		t20 = mem_read8(x + VIDEO_002F);
		t21 = mem_read8(x + 0x1Bu);
		if ((uint8_t)(t20 - t21) < 0x14u)
		{
			mem_write8(x + 0x29u, 0x20u);
			carry = 1u;
			*p_u = wait;
			*p_carry = carry;
			return;
		}
	}
	t22 = mem_read8(x + 0x1Bu);
	mem_write8(x + VIDEO_002F, t22);
	carry = 1u;
	*p_u = wait;
	*p_carry = carry;
}

uint16_t sub_022E40(uint16_t x, uint16_t y, uint16_t u)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, y_2 = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0;
	uint16_t t1 = 0;

	sub_078686(x, &u, &ignored16, &carry);
	if (carry == 0u)
	{
		carry = sub_023000(x);
		return y;
	}
	t1 = mem_read16(x + 0x2Bu);
	y_2 = t1;
	if (mem_read8(y_2) != 0u)
	{
		t2 = mem_read8(y_2 + 2u);
		if ((int8_t)t2 >= 0)
		{
			t3 = mem_read8(x + 0x2Au);
			if (t3 != 0u)
			{
				t4 = mem_read8(x + 0x2Au);
				mem_write8(x + 0x2Au, t4 - 1u);
				return y_2;
			}
		}
	}
	mem_write8(x + 0x2Au, 0x40u);
	mem_write16(x + 0x2Bu, u);
	return y_2;
}

void sub_022E65(uint16_t x)
{
	uint8_t b = 0;
	uint16_t d = 0, u = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read16(x + 0x2Bu);
	u = t1;
	t2 = mem_read16(x + 0xCu);
	t3 = mem_read16(u + 0xCu);
	if ((int16_t)t3 < (int16_t)t2)
		b = 0x20u;
	else
		b = 0xE0u;
	d = b;
	d = sub_078671(x, u, d);
	mem_write8(x + 0x2Du, ((d & ~0xFFu) | b) >> 8);
	d = sub_07861D(x, u);
	mem_write8(x + 0x2Eu, (d | b) >> 8);
}

void sub_022E83(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x2Eu);
	if ((uint8_t)(t1 + 0x40u) >= 0x80u)
	{
		t2 = mem_read8(x + 9u);
		mem_write8(x + 9u, t2 | 0x40u);
		return;
	}
	t3 = mem_read8(x + 9u);
	mem_write8(x + 9u, t3 & 0xBFu);
}

uint32_t sub_022E9E(uint16_t x, uint16_t d)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t t1 = 0;

	a = (uint8_t)(d >> 8);
	carry = (int8_t)a < 0;
	t1 = stage_7_boss_animations[a & 0x7Fu];
	mem_write16(x + 4u, ((uint32_t)(t1 >> 8) << 8) | (uint8_t)(t1 | 0x80u));
	return carry;
}

void sub_022EAD(uint16_t x, uint16_t *p_u, uint16_t *p_d)
{
	uint16_t d = (uint16_t)*p_d;
	uint16_t d_2 = 0, u = 0;
	uint16_t t1 = 0, field_1c = 0, t2 = 0, field_1f = 0, t3 = 0, field = 0, t4 = 0, field_23 = 0;

	t1 = stage_7_boss_hit_boxes_ADDRESS + (uint8_t)((((uint32_t)(d >> 8) << 1) << 1) << 1);
	field_1c = HIT_BOX(t1)->field_1c;
	mem_write16(x + 0x1Cu, field_1c);
	t2 = t1 + 2u;
	field_1f = HIT_BOX(t2 - 0x2u)->field_1f;
	mem_write16(x + 0x1Fu, field_1f);
	t3 = t2 + 2u;
	field = HIT_BOX(t3 - 0x4u)->field_21;
	mem_write16(x + 0x21u, field);
	t4 = t3 + 2u;
	u = t4 + 2u;
	field_23 = HIT_BOX(t4 - 0x6u)->field_23;
	d_2 = field_23;
	mem_write16(x + 0x23u, ((uint32_t)(field_23 >> 8) << 8) | (d_2 & 0xFFu));
	*p_u = u;
	*p_d = d_2;
}

void sub_022ECD(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t3 = 0, t4 = 0;
	uint16_t t1 = 0, t2 = 0, t5 = 0;
	uint32_t unk_48F1_halfword = 0, unk_48F1_halfword_2 = 0;

	t1 = mem_read16(x + 0xDu);
	d = t1;
	t2 = mem_read16(x + 0xFu);
	carry = (uint16_t)(d + t2) < d;
	unk_48F1_halfword = d + t2;
	unk_48F1 = (uint8_t)(unk_48F1_halfword >> 8u);
	unk_48F2 = (uint8_t)unk_48F1_halfword;
	t3 = mem_read8(x + 0xFu);
	t4 = mem_read8(x + 0xCu);
	unk_48F0 = (uint16_t)((uint32_t)(uint8_t)(((uint16_t)(int8_t)t3 >> 8) + t4 + carry) << 8) >> 8;
	d = (((uint32_t)unk_48F1 << 8u) | unk_48F2);
	t5 = AT16(unk_48AC, -1);
	carry = (uint16_t)(d + t5) < d;
	unk_48F1_halfword_2 = d + t5;
	unk_48F1 = (uint8_t)(unk_48F1_halfword_2 >> 8u);
	unk_48F2 = (uint8_t)unk_48F1_halfword_2;
	d = ((uint32_t)(uint8_t)(((uint16_t)((uint32_t)(uint8_t)(unk_48AC >> 8u) << 8) >> 8) + unk_48F0 + carry) << 8) | unk_48F1;
	if ((int16_t)d <= 0x8B0 || (int16_t)d >= 0xA0F)
		mem_write16(x + 0xFu, 0u);
}

void sub_022F01(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint8_t t1 = 0, t6 = 0, t7 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0;

	t1 = mem_read8(x + 2u);
	if (t1 != 0u)
	{
		t2 = mem_read16(x + 0x12u);
		t3 = mem_read16(x + 0x14u);
		t4 = t2;
		t5 = t4 + t3;
		carry = (uint16_t)(t4 + t3) < t4;
		unk_48F1 = (uint8_t)(t5 >> 8u);
		unk_48F2 = (uint8_t)t5;
		t6 = mem_read8(x + 0x14u);
		t7 = mem_read8(x + 0x11u);
		unk_48F0 = ((uint16_t)(int8_t)t6 >> 8) + t7 + carry;
		t8 = (((uint32_t)unk_48F1 << 8u) | unk_48F2);
		t9 = AT16(unk_48B2, -1);
		t10 = t8;
		t11 = t10 - t9;
		carry = t10 < t9;
		unk_48F1 = (uint8_t)(t11 >> 8u);
		unk_48F2 = (uint8_t)t11;
		a = (uint8_t)(unk_48B2 >> 8u) + unk_48F0 + carry;
		b = unk_48F1;
		if ((int16_t)(((uint32_t)a << 8) | b) <= 0x78 || (int16_t)(((uint32_t)a << 8) | b) >= 0xC8)
			mem_write16(x + 0x14u, 0u);
	}
}

uint16_t sub_022F3A(uint16_t x, uint16_t y)
{
	uint32_t negative = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0, t2 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0;
	uint16_t t3 = 0, t4 = 0, t5 = 0, t6 = 0;

	t1 = mem_read8(x + 2u);
	if (t1 != 0u)
	{
		t2 = mem_read8(x + 0x1Bu);
		if (t2 != 0u)
		{
			t3 = mem_read16(x + 0x3Bu);
			t4 = t3 + 1u;
			mem_write16(x + 0x3Bu, t4);
			t5 = stage_7_boss_helper_attack_times_by_rank[(int8_t)(unk_4861 & ~1u) / 2];
			t6 = mem_read16(x + 0x3Bu);
			if ((int16_t)t5 <= (int16_t)t6)
			{
				mem_write16(x + 0x3Bu, 0u);
				unk_48F0 = unk_4858 & 3u;
				t7 = io_read8(VIDEO_1880);
				b = t7 - 1u;
				stack = b;
				t8 = ((uint8_t)(unk_4857 - 1u) >> 1) + 1u;
				t9 = t8 - stack;
				negative = t9 >> 7;
				a = t9;
				if (t8 != stack && negative == 0u)
				{
					unk_48F1 = a;
					do
					{
						d = ((unk_48F0 & 3u) << 8) | b;
						y = sub_022F91(x, y, d);
						b = (uint8_t)d;
						unk_48F0++;
						t10 = unk_48F1;
						unk_48F1 = t10 - 1u;
					} while (t10 != 1u);
				}
			}
		}
	}
	return y;
}

uint16_t sub_022F91(uint16_t x, uint16_t y, uint16_t d)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, x_2 = 0;
	uint8_t t1 = 0;

	x_2 = mem_read16(x + (uint8_t)(((uint32_t)(d >> 8) << 1) + 0x33u));
	t1 = io_read8(x_2 + 2u);
	if (t1 != 0u)
		return y;
	y = child_object_023AE9_ADDRESS;
	sub_07862C(x_2, y, &ignored16, &ignored16_2, &carry);
	if (carry)
		io_write8(x_2 + 2u, 7u);
	return y;
}

uint16_t sub_022FAC(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0, u = 0;

	d = 0x100u;
	carry = sub_022E9E(x, d);
	d = 0u;
	sub_022EAD(x, &u, &d);
	mem_write8(x, (mem_read8(x) | 0x40u) & ~4u);
	mem_write8(x + 2u, 1u);
	mem_write8(x + 0x28u, 0u);
	mem_write8(x + 0x29u, 0u);
	return u;
}

uint32_t sub_023000(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;

	mem_write8(x + 2u, 5u);
	mem_write8(x + 0x28u, 0u);
	d = 0xA00u;
	carry = sub_022E9E(x, d);
	mem_write8(x, mem_read8(x) & 0xBFu);
	return carry;
}

uint16_t sub_023016(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, u = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t8 = 0, t9 = 0;
	uint16_t t1 = 0, t7 = 0;

	t1 = mem_read16(x + 0x25u);
	u = t1;
	mem_write8(u + 0x2Au, 1u);
	mem_write16(u + 0x49u, x);
	mem_write8(x, mem_read8(x) & 0xBBu);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write16(x + 0x19u, 0u);
	unk_487E = 2u;
	d = 0x28u;
	sub_078677(d, &y, &u);
	d = 0x6600u;
	carry = sub_078680(d);
	d = 0u;
	sub_022EAD(x, &ignored16, &d);
	t2 = mem_read8(x + 0x1Bu);
	if (t2 == 0u)
	{
		d = 0x6600u;
		carry = sub_078689(d);
		d = (d & 0xFFu) | 0x500u;
		carry = sub_022E9E(x, d);
		mem_write8(x + 2u, 0xFEu);
		mem_write8(x + 0x28u, 0u);
		mem_write16(x + 0x14u, 0u);
		mem_write16(x + 0x19u, 0x400u);
		t3 = mem_read8(x + 0x2Eu);
		if ((uint8_t)(t3 + 0x40u) < 0x80u)
		{
			mem_write16(x + 0xFu, 0xFD00u);
			return y;
		}
		mem_write16(x + 0xFu, 0x300u);
		return y;
	}
	t4 = mem_read8(x + 0x1Eu);
	if (t4 != 0x13u)
	{
		t5 = mem_read8(x + 0x30u);
		if (t5 != 2u)
		{
			t6 = mem_read8(x + 0x30u);
			mem_write8(x + 0x30u, t6 + 1u);
			d = (d & 0xFFu) | 0x400u;
			carry = sub_022E9E(x, d);
			mem_write8(x + 2u, 0xFFu);
			mem_write8(x + 0x28u, 0u);
			return y;
		}
	}
	mem_write8(x + 0x30u, 0u);
	if (stage_7_boss_jump_away_chances_by_players[(int8_t)((uint8_t)(unk_4857 - 1u))] < unk_4858)
	{
		d = (d & 0xFFu) | 0x500u;
		carry = sub_022E9E(x, d);
		mem_write8(x + 2u, 0xFEu);
		mem_write8(x + 0x28u, 0u);
		mem_write16(x + 0x14u, 0u);
		mem_write16(x + 0x19u, 0x400u);
		t3 = mem_read8(x + 0x2Eu);
		if ((uint8_t)(t3 + 0x40u) < 0x80u)
		{
			mem_write16(x + 0xFu, 0xFD00u);
			return y;
		}
		mem_write16(x + 0xFu, 0x300u);
		return y;
	}
	mem_write8(x, (mem_read8(x) & 0xBFu) | 8u);
	t7 = mem_read16(x + 0xCu);
	if ((int16_t)t7 <= 0xE0)
	{
		t8 = mem_read8(x + 9u);
		mem_write8(x + 9u, t8 | 0x40u);
		mem_write16(x + 0xFu, 0x300u);
	}
	else
	{
		t9 = mem_read8(x + 9u);
		mem_write8(x + 9u, t9 & 0xBFu);
		mem_write16(x + 0xFu, 0xFD00u);
	}
	mem_write16(x + 0x19u, 0x900u);
	d = 0x900u;
	carry = sub_022E9E(x, d);
	mem_write8(x + 2u, 4u);
	mem_write8(x + 0x28u, 0u);
	return y;
}

void sub_02317A(void)
{
}

void sub_02317B(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_023B01_ADDRESS;
		t1 = mem_read8(x + 0x28u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			u = sub_023184(x);
			break;
		case 2:
			y = sub_02319C(x);
			break;
		case 4:
			sub_0231D5(x);
			break;
		case 6:
			sub_0231E9(x);
			break;
		case -16:
			sub_02317A();
			break;
		case -14:
		case -12:
		case -10:
		case -8:
		case -6:
		case -4:
			continue;
		case -2:
			sub_0231CC(x, &y, &u);
			break;
		}
		break;
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_023184(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	u = stage_7_boss_helper_speeds_ADDRESS;
	t1 = mem_read8(x + 2u);
	t2 = stage_7_boss_helper_speeds[(int8_t)((uint8_t)((t1 - 1u) << 1)) / 2];
	mem_write16(x + 0xFu, t2);
	mem_write16(x + 0x29u, 0u);
	mem_write8(x + 0x2Bu, 0u);
	t3 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t3 + 1u);
	return u;
}

uint16_t sub_02319C(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t distance = 0;
	uint8_t t1 = 0, t6 = 0, t7 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t8 = 0, t9 = 0, t10 = 0;

	t1 = mem_read8(x + 2u);
	distance = stage_7_boss_helper_distances_ADDRESS + (int8_t)((t1 - 1u) << 1);
	t2 = mem_read16(x + 0x2Au);
	t3 = mem_read16(x + 0xFu);
	t4 = t2;
	t5 = t4 + t3;
	carry = (uint16_t)(t4 + t3) < t4;
	mem_write16(x + 0x2Au, t5);
	t6 = mem_read8(x + 0xFu);
	t7 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, ((uint16_t)(int8_t)t6 >> 8) + t7 + carry);
	t8 = mem_read16(x + 0x29u);
	t9 = t8;
	t10 = t9 >> 15 ? 0u - t9 : t9;
	if (t10 == HELPER_DISTANCE(distance))
	{
		mem_write16(x + 0xFu, 0u);
		mem_write8(x + 2u, 0u);
		mem_write8(x + 0x28u, 0u);
	}
	return distance;
}

void sub_0231CC(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_023B05_ADDRESS;
		t1 = mem_read8(x + 0x28u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			sub_0231D5(x);
			break;
		case 2:
			sub_0231E9(x);
			break;
		case -20:
			sub_02317A();
			break;
		case -18:
		case -16:
		case -14:
		case -12:
		case -10:
		case -8:
			sub_02317B(x, &y, &u);
			break;
		case -6:
			continue;
		case -4:
			u = sub_023184(x);
			break;
		case -2:
			y = sub_02319C(x);
			break;
		}
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_0231D5(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	d = 0x6000u;
	carry = sub_078680(d);
	t1 = mem_read8(x + 5u);
	mem_write8(x + 5u, (t1 - 3u) | 0x80u);
	t2 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t2 + 1u);
}

void sub_0231E9(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) != 0u)
	{
		t2 = mem_read8(x + 5u);
		mem_write8(x + 5u, t2 - 0x7Du);
		mem_write8(x + 2u, 0u);
		mem_write8(x + 0x28u, 0u);
	}
}
