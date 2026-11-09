/**
 *    Name:        unsorted/bank_10.c
 *    Description: bank 10's code
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

void sub_020000(uint16_t y)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, x = 0;
	uint8_t t1 = 0;

	unk_48F8 = 0x7Cu;
	unk_48FA = 0x98u;
	unk_48F0 = 0x10u;
	y = sub_021189(y);
	d = sub_020904();
	x = loaded_table_021B86_ADDRESS;
	t1 = io_read8(VIDEO_18E0);
	a = (uint32_t)t1 << 1;
	switch ((int8_t)a)
	{
	case 0:
		sub_020107(&ignored16, &y, &d, &carry);
		return;
	case 2:
		sub_02016F(&ignored16, &ignored16_2, &ignored16_3, &carry);
		return;
	case 4:
		sub_0201F2(&ignored16, &y, &d, &carry);
		return;
	case 6:
		sub_020116(&ignored16, &ignored16_2, &ignored16_3, &carry);
		return;
	case 8:
		sub_02013F(&ignored16, &ignored16_2, &ignored16_3, &carry);
		return;
	case 10:
		sub_020182(&ignored16_3, &carry);
		return;
	case 12:
		sub_02018D(&ignored16, &ignored16_2, &ignored16_3, &carry);
		return;
	case 14:
		sub_0201FC(&ignored16_3, &carry);
		return;
	case 16:
		sub_020207(&ignored16, &ignored16_2, &ignored16_3, &carry);
		return;
	case 18:
		sub_020264(&ignored16, &ignored16_2, &ignored16_3, &carry);
		return;
	case 20:
		sub_0202DD(&ignored16, &y, &d, &carry);
		return;
	case 22:
		d = (d & 0xFFu) | ((uint32_t)a << 8);
		sub_020316(&d, &carry);
		return;
	case 24:
		sub_020519(&x, &y, &d, &carry);
		return;
	case 26:
		sub_0205C0(&x, &y, &d, &carry);
		return;
	case 28:
		sub_020522(x, &ignored16_2, &ignored16_3);
		return;
	case 30:
		sub_020553(x, &ignored16_2, &ignored16_3);
		return;
	case 32:
		sub_02056B(x, &ignored16_2, &ignored16_3, &carry);
		return;
	case 34:
		sub_020584(x, &ignored16_2, &ignored16_3, &carry);
		return;
	case 36:
		sub_0205D3(x, &ignored16_3, &carry);
		return;
	case 38:
		sub_020600(x, &ignored16_3, &carry);
		return;
	case 40:
		sub_02061F(x);
		return;
	case 42:
		sub_020628();
		return;
	case 44:
		sub_020922(y, &ignored16_3, &carry);
		return;
	case 46:
		sub_020937(&ignored16, &ignored16_3, &carry);
		return;
	case 48:
	case 52:
		carry = sub_020975();
		return;
	case 50:
		sub_02097E(x, &ignored16_2, &ignored16_3, &carry);
		return;
	case 54:
		sub_020996(x, &ignored16_2, &ignored16_3, &carry);
		return;
	case 56:
		sub_0209CA();
		return;
	case 58:
		d = (uint32_t)a << 8;
		sub_0209D6(&x, &ignored16_2, &d, &carry);
		return;
	case 60:
		sub_0209F7();
		return;
	case -6:
		sub_020020(&ignored16, &y, &d, &carry);
		return;
	case -4:
		sub_02002A(&ignored16, &ignored16_2, &ignored16_3, &carry);
		return;
	case -2:
		sub_0200B4(&ignored16, &y, &ignored16_3, &carry);
		return;
	}
}

void sub_020003(uint16_t y)
{
	uint8_t a = 0;
	uint8_t t1 = 0;

	t1 = io_read8(VIDEO_1840);
	a = t1;
	if ((int8_t)a < 3)
	{
		a = 3u;
		io_write8(VIDEO_1840, 3u);
	}
	switch ((int8_t)(uint8_t)((uint32_t)a << 1))
	{
	case 0:
		sub_020A3C();
		return;
	case 2:
		sub_020A47(y);
		return;
	case 4:
		sub_020AB4(y);
		return;
	case 6:
		sub_020AE3();
		return;
	case 8:
		sub_020B9B();
		return;
	case 10:
		sub_020BB6();
		return;
	case 12:
		sub_020BE3();
		return;
	case 14:
		sub_020C14();
		return;
	}
}

uint16_t sub_020006(uint16_t x, uint16_t y, uint16_t d)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0, d_2 = 0;
	uint16_t d_3 = 0, u = 0;
	uint8_t t1 = 0;

	sub_0216D2(x, &y, &d);
	b = (uint8_t)d;
	u = loaded_table_021E2F_ADDRESS;
	t1 = mem_read8(x + 2u);
	a = t1;
	carry = (int8_t)a < 0;
	a = (uint32_t)a << 1;
	d_2 = b;
	switch ((int8_t)a)
	{
	case 0:
		y = sub_0213EA(x, y, d_2);
		break;
	case 2:
		y = sub_021565(x, y);
		break;
	case 4:
		y = sub_02158F(x, y, d_2);
		break;
	case 6:
		y = sub_0215E3(x, y, d_2);
		break;
	case 8:
	case 10:
		y = sub_021605(x, y, d_2);
		break;
	case 12:
		y = sub_02168C(x, y, d_2);
		break;
	case 14:
		y = sub_0216C8(x, y);
		break;
	case 16:
		y = sub_02131E(x, y, u);
		break;
	case 18:
		sub_021338(x, d_2, carry);
		break;
	case 20:
		sub_021385(x);
		break;
	case 22:
		sub_0213AE(x);
		break;
	case 24:
		y = sub_0213BC(x, y);
		break;
	case 26:
		sub_0213D3(x);
		break;
	case 28:
		y = sub_0213DE(x, y);
		break;
	case 30:
		y = sub_0213F3(x, y);
		break;
	case 32:
		sub_021488(x);
		break;
	case 34:
		y = sub_0214B5(x, y, u);
		break;
	case 36:
		sub_0214DD(x);
		break;
	case 38:
		y = sub_0214F1(x, y, u);
		break;
	case 40:
		sub_021529(x);
		break;
	case 42:
		sub_021537(x);
		break;
	case 44:
		sub_021557(x);
		break;
	case 46:
		sub_021598(x);
		break;
	case 48:
		sub_0215B2(x);
		break;
	case 50:
		y = sub_0215D7(x, y);
		break;
	case 52:
		y = sub_0215EC(x, y);
		break;
	case 54:
		sub_02160E(x);
		break;
	case 56:
		sub_02161F(x);
		break;
	case 58:
		sub_02164C(x);
		break;
	case 60:
		y = sub_021673(x, y, u);
		break;
	case 62:
		sub_021695(x);
		break;
	case 64:
		y = sub_0216B7(x, y, u);
		break;
	case -6:
		y = sub_021315(x, y, d_2);
		break;
	case -4:
		y = sub_02137C(x, y, d_2);
		break;
	case -2:
		y = sub_0213CA(x, y, d_2);
		break;
	}
	sub_021795(x);
	d_3 = (uint32_t)wrestler_gauge_piece_health_by_players[(int8_t)((uint8_t)(unk_4857 - 1u))] << 8;
	y = sub_0786BF(x, y, d_3);
	return y;
}

void sub_020009(uint16_t y)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, x = 0;
	uint8_t t1 = 0;

	d = 0u;
	sub_0209C0(&y, &d);
	x = loaded_table_021B80_ADDRESS;
	t1 = io_read8(VIDEO_18E0);
	a = (uint32_t)t1 << 1;
	switch ((int8_t)a)
	{
	case 0:
		sub_020020(&ignored16, &y, &d, &carry);
		return;
	case 2:
		sub_02002A(&ignored16, &ignored16_2, &ignored16_3, &carry);
		return;
	case 4:
		sub_0200B4(&ignored16, &y, &ignored16_3, &carry);
		return;
	case 6:
		sub_020107(&ignored16, &y, &d, &carry);
		return;
	case 8:
		sub_02016F(&ignored16, &ignored16_2, &ignored16_3, &carry);
		return;
	case 10:
		sub_0201F2(&ignored16, &y, &d, &carry);
		return;
	case 12:
		sub_020116(&ignored16, &ignored16_2, &ignored16_3, &carry);
		return;
	case 14:
		sub_02013F(&ignored16, &ignored16_2, &ignored16_3, &carry);
		return;
	case 16:
		sub_020182(&ignored16_3, &carry);
		return;
	case 18:
		sub_02018D(&ignored16, &ignored16_2, &ignored16_3, &carry);
		return;
	case 20:
		sub_0201FC(&ignored16_3, &carry);
		return;
	case 22:
		sub_020207(&ignored16, &ignored16_2, &ignored16_3, &carry);
		return;
	case 24:
		sub_020264(&ignored16, &ignored16_2, &ignored16_3, &carry);
		return;
	case 26:
		sub_0202DD(&ignored16, &y, &d, &carry);
		return;
	case 28:
		d = (d & 0xFFu) | ((uint32_t)a << 8);
		sub_020316(&d, &carry);
		return;
	case 30:
		sub_020519(&x, &y, &d, &carry);
		return;
	case 32:
		sub_0205C0(&x, &y, &d, &carry);
		return;
	case 34:
		sub_020522(x, &ignored16_2, &ignored16_3);
		return;
	case 36:
		sub_020553(x, &ignored16_2, &ignored16_3);
		return;
	case 38:
		sub_02056B(x, &ignored16_2, &ignored16_3, &carry);
		return;
	case 40:
		sub_020584(x, &ignored16_2, &ignored16_3, &carry);
		return;
	case 42:
		sub_0205D3(x, &ignored16_3, &carry);
		return;
	case 44:
		sub_020600(x, &ignored16_3, &carry);
		return;
	case 46:
		sub_02061F(x);
		return;
	case 48:
		sub_020628();
		return;
	case 50:
		sub_020922(y, &ignored16_3, &carry);
		return;
	case 52:
		sub_020937(&ignored16, &ignored16_3, &carry);
		return;
	case 54:
	case 58:
		carry = sub_020975();
		return;
	case 56:
		sub_02097E(x, &ignored16_2, &ignored16_3, &carry);
		return;
	case 60:
		sub_020996(x, &ignored16_2, &ignored16_3, &carry);
		return;
	case 62:
		sub_0209CA();
		return;
	case 64:
		d = (uint32_t)a << 8;
		sub_0209D6(&x, &ignored16_2, &d, &carry);
		return;
	case 66:
		sub_0209F7();
		return;
	}
}

void sub_02000C(uint16_t y)
{
	uint8_t t1 = 0;

	t1 = io_read8(VIDEO_1840);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_020A3C();
		return;
	case 2:
		sub_020A47(y);
		return;
	case 4:
		sub_020AB4(y);
		return;
	case 6:
		sub_020AE3();
		return;
	case 8:
		sub_020B9B();
		return;
	case 10:
		sub_020BB6();
		return;
	case 12:
		sub_020BE3();
		return;
	case 14:
		sub_020C14();
		return;
	}
}

uint16_t sub_02000F(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 2u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		return sub_0219F5(x);
	case 2:
		return sub_021A1C(x);
	}
	unreachable();
}

void sub_020020(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint16_t x = 0;
	uint8_t t1 = 0;

	sub_020919(&x, &y, &d, &carry);
	if (carry)
	{
		t1 = io_read8(VIDEO_18E0);
		io_write8(VIDEO_18E0, t1 + 1u);
	}
	*p_x = x;
	*p_y = y;
	*p_d = d;
	*p_carry = carry;
}

void sub_02002A(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t a = 0;
	uint16_t d = 0, ignored16 = 0, u = 0, x = 0, y = 0;
	uint8_t t1 = 0, t8 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0;

	sub_0209AE();
	sub_0208E9();
	sub_02072E(&ignored16, &y, &d, &carry);
	x = unk_4A40_ADDRESS;
	unk_48F1 = 0u;
	unk_48F2 = 0u;
	do
	{
		t1 = mem_read8(x + 0x3Eu);
		if (t1 == 0u || unk_48F2 != 0u)
		{
			mem_write8(x, 0u);
			t2 = mem_read16(x + 0x33u);
			mem_write8(t2, 0u);
			t3 = mem_read16(x + 0x35u);
			mem_write8(t3, 0u);
			t4 = mem_read16(x + 0x37u);
			mem_write8(t4, 0u);
		}
		else
		{
			mem_write8(x + 9u, 0x30u);
			io_write8(VIDEO_18EE, unk_48F1);
			unk_48F2++;
			mem_write16(x + 0xCu, 0x9Cu);
			mem_write16(x + 0x11u, 0xE8u);
			mem_write16(x + 0x16u, 0x28u);
			t5 = mem_read16(x + 0x37u);
			u = t5;
			mem_write16(u + 0xCu, 0xAEu);
			mem_write16(u + 0x11u, 0xE8u);
			mem_write16(u + 0x16u, 0u);
			t6 = mem_read16(x + 0x33u);
			mem_write8(t6, 0u);
			t7 = mem_read16(x + 0x35u);
			u = t7;
			mem_write16(u + 0xCu, 0xAEu);
			mem_write16(u + 0x11u, 0xE8u);
			d = 0u;
			mem_write16(u + 0x16u, 0u);
		}
		x += 0xC0u;
		unk_48F1++;
		a = unk_48F1;
		carry = a < 4u;
	} while (a != 4u);
	t8 = io_read8(VIDEO_18E0);
	io_write8(VIDEO_18E0, t8 + 1u);
	d = (d & 0xFFu) | ((uint32_t)a << 8);
	*p_x = x;
	*p_y = y;
	*p_d = d;
	*p_carry = carry;
}

void sub_0200B4(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = *p_carry;
	uint16_t bonus_player = 0, d = 0, ignored16 = 0, ignored16_2 = 0, u = 0, x = 0, y_2 = 0;
	uint16_t stack = 0, stack_4 = 0;
	uint8_t t1 = 0, t2 = 0;
	uint16_t object = 0;

	sub_020967(y);
	t1 = io_read8(VIDEO_18EE);
	bonus_player = bonus_1_player_records[(int8_t)((uint8_t)((uint32_t)t1 << 1)) / 2];
	object = BONUS_PLAYER(bonus_player)->object;
	x = object;
	mem_write8(x, mem_read8(x) | 0x10u);
	mem_write8(BONUS_PLAYER(bonus_player)->presses, 0u);
	if ((unk_4815 & 3u) == 0u)
		mem_write8(BONUS_PLAYER(bonus_player)->presses, 0x10u);
	stack = bonus_player;
	stack_4 = x;
	sub_0208AB(&ignored16, &ignored16_2, &carry);
	x = stack_4;
	u = stack;
	t2 = io_read8(VIDEO_18EE);
	d = (uint32_t)t2 << 8;
	*p_x = x;
	*p_y = y_2;
	*p_d = d;
	sub_02034A(u, p_x, p_y, p_d, &carry);
	*p_carry = carry;
}

void sub_020107(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t a = 0;
	uint16_t x = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		unk_48F0 = 0x10u;
		x = loaded_table_021B8C_ADDRESS;
		t1 = io_read8(VIDEO_18E1);
		a = t1;
		carry = (int8_t)a < 0;
		a = (uint32_t)a << 1;
		switch ((int8_t)a)
		{
		case 0:
			sub_020116(&x, &y, &d, &carry);
			break;
		case 2:
			sub_02013F(&x, &y, &d, &carry);
			break;
		case 4:
			sub_020182(&d, &carry);
			break;
		case 6:
			sub_02018D(&x, &y, &d, &carry);
			break;
		case 8:
			sub_0201FC(&d, &carry);
			break;
		case 10:
			sub_020207(&x, &y, &d, &carry);
			break;
		case 12:
			sub_020264(&x, &y, &d, &carry);
			break;
		case 14:
			sub_0202DD(&x, &y, &d, &carry);
			break;
		case 16:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			sub_020316(&d, &carry);
			break;
		case 18:
			sub_020519(&x, &y, &d, &carry);
			break;
		case 20:
			sub_0205C0(&x, &y, &d, &carry);
			break;
		case 22:
			sub_020522(x, &y, &d);
			break;
		case 24:
			sub_020553(x, &y, &d);
			break;
		case 26:
			sub_02056B(x, &y, &d, &carry);
			break;
		case 28:
			sub_020584(x, &y, &d, &carry);
			break;
		case 30:
			sub_0205D3(x, &d, &carry);
			break;
		case 32:
			sub_020600(x, &d, &carry);
			break;
		case 34:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			sub_02061F(x);
			break;
		case 36:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			sub_020628();
			break;
		case 38:
			sub_020922(y, &d, &carry);
			break;
		case 40:
			sub_020937(&x, &d, &carry);
			break;
		case 42:
		case 46:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			carry = sub_020975();
			break;
		case 44:
			sub_02097E(x, &y, &d, &carry);
			break;
		case 48:
			sub_020996(x, &y, &d, &carry);
			break;
		case 50:
			d = sub_0209CA();
			break;
		case 52:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			sub_0209D6(&x, &y, &d, &carry);
			break;
		case 54:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			sub_0209F7();
			break;
		case -12:
			sub_020020(&x, &y, &d, &carry);
			break;
		case -10:
			sub_02002A(&x, &y, &d, &carry);
			break;
		case -8:
			sub_0200B4(&x, &y, &d, &carry);
			break;
		case -6:
			continue;
		case -4:
			sub_02016F(&x, &y, &d, &carry);
			break;
		case -2:
			sub_0201F2(&x, &y, &d, &carry);
			break;
		}
		break;
	}
	*p_x = x;
	*p_y = y;
	*p_d = d;
	*p_carry = carry;
}

void sub_020116(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d = 0, x = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	t1 = io_read8(0x18E8u);
	io_write8(0x18E8u, 0u);
	t2 = io_read8(VIDEO_18E9);
	io_write8(VIDEO_18E9, 0u);
	t3 = io_read8(VIDEO_18EA);
	io_write8(VIDEO_18EA, 0u);
	t4 = io_read8(VIDEO_18EB);
	io_write8(VIDEO_18EB, 0u);
	unk_487A = 0x10u;
	sub_0208E9();
	sub_020829();
	sub_02072E(&x, &y, &d, &carry);
	io_write8(VIDEO_18E2, 0x60u);
	t5 = io_read8(VIDEO_18E1);
	io_write8(VIDEO_18E1, t5 + 1u);
	d = (d & 0xFFu) | 0x6000u;
	*p_x = x;
	*p_y = y;
	*p_d = d;
	*p_carry = carry;
}

void sub_02013F(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d = 0, ignored16 = 0, x = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	sub_020ED3();
	sub_020324(&x, &y, &ignored16);
	unk_48F8 = 0xB8u;
	unk_48FA = 0xB8u;
	sub_020706();
	d = unk_48F8;
	carry = (uint16_t)(d + 0x28u) < d;
	d += 0x28u;
	unk_48F8 = d;
	sub_020685();
	t1 = io_read8(VIDEO_18E2);
	io_write8(VIDEO_18E2, t1 - 1u);
	if (t1 == 1u)
	{
		t2 = io_read8(VIDEO_18E0);
		io_write8(VIDEO_18E0, t2 + 1u);
		t3 = io_read8(VIDEO_18E1);
		carry = 0u;
		io_write8(VIDEO_18E1, 0u);
	}
	*p_x = x;
	*p_y = y;
	*p_d = d;
	*p_carry = carry;
}

void sub_02016F(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t a = 0;
	uint16_t d = 0, ignored16 = 0, x = 0, y = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		sub_020803();
		sub_020874();
		sub_020324(&ignored16, &y, &d);
		x = loaded_table_021B90_ADDRESS;
		t1 = io_read8(VIDEO_18E1);
		a = t1;
		carry = (int8_t)a < 0;
		a = (uint32_t)a << 1;
		switch ((int8_t)a)
		{
		case 0:
			*p_d = d;
			sub_020182(p_d, &carry);
			*p_x = x;
			*p_y = y;
			*p_carry = carry;
			return;
		case 2:
			*p_x = x;
			*p_y = y;
			*p_d = d;
			sub_02018D(p_x, p_y, p_d, &carry);
			*p_carry = carry;
			return;
		case 4:
			*p_d = d;
			sub_0201FC(p_d, &carry);
			*p_x = x;
			*p_y = y;
			*p_carry = carry;
			return;
		case 6:
			*p_x = x;
			*p_y = y;
			*p_d = d;
			sub_020207(p_x, p_y, p_d, &carry);
			*p_carry = carry;
			return;
		case 8:
			*p_x = x;
			*p_y = y;
			*p_d = d;
			sub_020264(p_x, p_y, p_d, &carry);
			*p_carry = carry;
			return;
		case 10:
			*p_x = x;
			*p_y = y;
			*p_d = d;
			sub_0202DD(p_x, p_y, p_d, &carry);
			*p_carry = carry;
			return;
		case 12:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			*p_d = d;
			sub_020316(p_d, &carry);
			*p_x = x;
			*p_y = y;
			*p_carry = carry;
			return;
		case 14:
			*p_x = x;
			*p_y = y;
			*p_d = d;
			sub_020519(p_x, p_y, p_d, &carry);
			*p_carry = carry;
			return;
		case 16:
			*p_x = x;
			*p_y = y;
			*p_d = d;
			sub_0205C0(p_x, p_y, p_d, &carry);
			*p_carry = carry;
			return;
		case 18:
			*p_y = y;
			*p_d = d;
			sub_020522(x, p_y, p_d);
			*p_x = x;
			*p_carry = carry;
			return;
		case 20:
			*p_y = y;
			*p_d = d;
			sub_020553(x, p_y, p_d);
			*p_x = x;
			*p_carry = carry;
			return;
		case 22:
			*p_y = y;
			*p_d = d;
			sub_02056B(x, p_y, p_d, &carry);
			*p_x = x;
			*p_carry = carry;
			return;
		case 24:
			*p_y = y;
			*p_d = d;
			sub_020584(x, p_y, p_d, &carry);
			*p_x = x;
			*p_carry = carry;
			return;
		case 26:
			*p_d = d;
			sub_0205D3(x, p_d, &carry);
			*p_x = x;
			*p_y = y;
			*p_carry = carry;
			return;
		case 28:
			*p_d = d;
			sub_020600(x, p_d, &carry);
			*p_x = x;
			*p_y = y;
			*p_carry = carry;
			return;
		case 30:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			sub_02061F(x);
			*p_x = x;
			*p_y = y;
			*p_d = d;
			*p_carry = carry;
			return;
		case 32:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			sub_020628();
			*p_x = x;
			*p_y = y;
			*p_d = d;
			*p_carry = carry;
			return;
		case 34:
			*p_d = d;
			sub_020922(y, p_d, &carry);
			*p_x = x;
			*p_y = y;
			*p_carry = carry;
			return;
		case 36:
			*p_x = x;
			*p_d = d;
			sub_020937(p_x, p_d, &carry);
			*p_y = y;
			*p_carry = carry;
			return;
		case 38:
		case 42:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			carry = sub_020975();
			*p_x = x;
			*p_y = y;
			*p_d = d;
			*p_carry = carry;
			return;
		case 40:
			*p_y = y;
			*p_d = d;
			sub_02097E(x, p_y, p_d, &carry);
			*p_x = x;
			*p_carry = carry;
			return;
		case 44:
			*p_y = y;
			*p_d = d;
			sub_020996(x, p_y, p_d, &carry);
			*p_x = x;
			*p_carry = carry;
			return;
		case 46:
			d = sub_0209CA();
			*p_x = x;
			*p_y = y;
			*p_d = d;
			*p_carry = carry;
			return;
		case 48:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			*p_x = x;
			*p_y = y;
			*p_d = d;
			sub_0209D6(p_x, p_y, p_d, &carry);
			*p_carry = carry;
			return;
		case 50:
			break;
		case -16:
			*p_x = x;
			*p_y = y;
			*p_d = d;
			sub_020020(p_x, p_y, p_d, &carry);
			*p_carry = carry;
			return;
		case -14:
			*p_x = x;
			*p_y = y;
			*p_d = d;
			sub_02002A(p_x, p_y, p_d, &carry);
			*p_carry = carry;
			return;
		case -12:
			*p_x = x;
			*p_y = y;
			*p_d = d;
			sub_0200B4(p_x, p_y, p_d, &carry);
			*p_carry = carry;
			return;
		case -10:
			*p_x = x;
			*p_y = y;
			*p_d = d;
			sub_020107(p_x, p_y, p_d, &carry);
			*p_carry = carry;
			return;
		case -8:
			continue;
		case -6:
			*p_x = x;
			*p_y = y;
			*p_d = d;
			sub_0201F2(p_x, p_y, p_d, &carry);
			*p_carry = carry;
			return;
		case -4:
			*p_x = x;
			*p_y = y;
			*p_d = d;
			sub_020116(p_x, p_y, p_d, &carry);
			*p_carry = carry;
			return;
		case -2:
			*p_x = x;
			*p_y = y;
			*p_d = d;
			sub_02013F(p_x, p_y, p_d, &carry);
			*p_carry = carry;
			return;
		}
		break;
	}
	d = (d & 0xFFu) | ((uint32_t)a << 8);
	sub_0209F7();
	*p_x = x;
	*p_y = y;
	*p_d = d;
	*p_carry = carry;
}

void sub_020182(uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d = 0;
	uint8_t t1 = 0;

	d = 0x8900u;
	carry = sub_078689(d);
	t1 = io_read8(VIDEO_18E1);
	io_write8(VIDEO_18E1, t1 + 1u);
	*p_d = d;
	*p_carry = carry;
}

void sub_02018D(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = *p_carry;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, x = 0, y_2 = 0;
	uint8_t stack = 0;
	uint8_t t2 = 0, t6 = 0, t7 = 0, t8 = 0;
	uint16_t t1 = 0, t3 = 0, t4 = 0, t5 = 0, t9 = 0, t10 = 0;

	sub_020F01();
	sub_02062D(&x, &carry);
	if (carry)
	{
		x = unk_4A40_ADDRESS;
		stack = 4u;
		do
		{
			t1 = mem_read16(x + 0x37u);
			y_2 = t1;
			b = 0x81u;
			t2 = mem_read8(x + 0x3Eu);
			if (t2 == 0u)
				b = 0xA9u;
			mem_write8(y_2 + 5u, b);
			t3 = mem_read16(x + 0x35u);
			y = t3;
			mem_write8(y + 5u, 0x81u);
			t4 = mem_read16(x + 0x30u);
			t5 = t4 - VIDEO_00A0;
			b = (uint8_t)(t5 >> 2);
			mem_write8(x + 1u, b);
			x += 0xC0u;
			t6 = stack;
			stack = t6 - 1u;
		} while (t6 != 1u);
		t7 = io_read8(VIDEO_18E0);
		io_write8(VIDEO_18E0, t7 + 1u);
		t8 = io_read8(VIDEO_18E1);
		carry = 0u;
		io_write8(VIDEO_18E1, 0u);
		d = ((uint32_t)stack << 8) | b;
	}
	else
	{
		carry = sub_02064A();
		if (carry)
		{
			x = unk_4A40_ADDRESS;
			stack = 4u;
			do
			{
				t1 = mem_read16(x + 0x37u);
				y_2 = t1;
				b = 0x81u;
				t2 = mem_read8(x + 0x3Eu);
				if (t2 == 0u)
					b = 0xA9u;
				mem_write8(y_2 + 5u, b);
				t3 = mem_read16(x + 0x35u);
				y = t3;
				mem_write8(y + 5u, 0x81u);
				t4 = mem_read16(x + 0x30u);
				t5 = t4 - VIDEO_00A0;
				b = (uint8_t)(t5 >> 2);
				mem_write8(x + 1u, b);
				x += 0xC0u;
				t6 = stack;
				stack = t6 - 1u;
			} while (t6 != 1u);
			t7 = io_read8(VIDEO_18E0);
			io_write8(VIDEO_18E0, t7 + 1u);
			t8 = io_read8(VIDEO_18E1);
			carry = 0u;
			io_write8(VIDEO_18E1, 0u);
			d = ((uint32_t)stack << 8) | b;
		}
		else
		{
			unk_48F8 = 0xB8u;
			unk_48FA = 0xB8u;
			sub_020706();
			t9 = unk_48F8;
			t10 = t9;
			carry = (uint16_t)(t10 + 0x28u) < t10;
			a = (uint8_t)((uint16_t)(t10 + 0x28u) >> 8);
			b = (uint8_t)(t10 + 0x28u);
			unk_48F8 = ((uint32_t)a << 8) | b;
			sub_020685();
			d = ((uint32_t)a << 8) | b;
		}
	}
	*p_x = x;
	*p_y = y;
	*p_d = d;
	*p_carry = carry;
}

void sub_0201F2(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t a = 0;
	uint16_t x = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		x = loaded_table_021B94_ADDRESS;
		t1 = io_read8(VIDEO_18E1);
		a = t1;
		carry = (int8_t)a < 0;
		a = (uint32_t)a << 1;
		switch ((int8_t)a)
		{
		case 0:
			sub_0201FC(&d, &carry);
			break;
		case 2:
			sub_020207(&x, &y, &d, &carry);
			break;
		case 4:
			sub_020264(&x, &y, &d, &carry);
			break;
		case 6:
			sub_0202DD(&x, &y, &d, &carry);
			break;
		case 8:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			sub_020316(&d, &carry);
			break;
		case 10:
			sub_020519(&x, &y, &d, &carry);
			break;
		case 12:
			sub_0205C0(&x, &y, &d, &carry);
			break;
		case 14:
			sub_020522(x, &y, &d);
			break;
		case 16:
			sub_020553(x, &y, &d);
			break;
		case 18:
			sub_02056B(x, &y, &d, &carry);
			break;
		case 20:
			sub_020584(x, &y, &d, &carry);
			break;
		case 22:
			sub_0205D3(x, &d, &carry);
			break;
		case 24:
			sub_020600(x, &d, &carry);
			break;
		case 26:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			sub_02061F(x);
			break;
		case 28:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			sub_020628();
			break;
		case 30:
			sub_020922(y, &d, &carry);
			break;
		case 32:
			sub_020937(&x, &d, &carry);
			break;
		case 34:
		case 38:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			carry = sub_020975();
			break;
		case 36:
			sub_02097E(x, &y, &d, &carry);
			break;
		case 40:
			sub_020996(x, &y, &d, &carry);
			break;
		case 42:
			d = sub_0209CA();
			break;
		case 44:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			sub_0209D6(&x, &y, &d, &carry);
			break;
		case 46:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			sub_0209F7();
			break;
		case -20:
			sub_020020(&x, &y, &d, &carry);
			break;
		case -18:
			sub_02002A(&x, &y, &d, &carry);
			break;
		case -16:
			sub_0200B4(&x, &y, &d, &carry);
			break;
		case -14:
			sub_020107(&x, &y, &d, &carry);
			break;
		case -12:
			sub_02016F(&x, &y, &d, &carry);
			break;
		case -10:
			continue;
		case -8:
			sub_020116(&x, &y, &d, &carry);
			break;
		case -6:
			sub_02013F(&x, &y, &d, &carry);
			break;
		case -4:
			sub_020182(&d, &carry);
			break;
		case -2:
			sub_02018D(&x, &y, &d, &carry);
			break;
		}
		break;
	}
	*p_x = x;
	*p_y = y;
	*p_d = d;
	*p_carry = carry;
}

void sub_0201FC(uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d = 0;
	uint8_t t1 = 0;

	d = 0x8800u;
	carry = sub_078689(d);
	t1 = io_read8(VIDEO_18E1);
	io_write8(VIDEO_18E1, t1 + 1u);
	*p_d = d;
	*p_carry = carry;
}

void sub_020207(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t a = 0, b = 0;
	uint16_t d_2 = 0, u = 0, x = 0, y_2 = 0;
	uint8_t stack = 0;
	uint16_t stack_3 = 0;
	uint8_t t2 = 0, t4 = 0, t7 = 0;
	uint16_t t1 = 0, t3 = 0, t5 = 0, t6 = 0;

	sub_020F39(&x, &y, &d, &carry);
	a = (uint8_t)(d >> 8);
	b = (uint8_t)d;
	if (carry == 0u)
		d_2 = ((uint32_t)a << 8) | b;
	else
	{
		x = unk_4A40_ADDRESS;
		u = unk_48F0_ADDRESS;
		y = VIDEO_18E4;
		stack = 0u;
		do
		{
			mem_write8(x + 0x43u, 0u);
			mem_write8(x + 0x44u, 0u);
			mem_write8(x + 0x3Fu, 0u);
			t1 = mem_read16(x + 0x30u);
			if (t1 <= 0x160u)
			{
				t2 = mem_read8(x + 0x3Fu);
				mem_write8(x + 0x3Fu, t2 + 1u);
				stack_3 = y;
				t3 = mem_read16(x + 0x37u);
				y_2 = t3;
				a = 0x82u;
				t4 = mem_read8(x + 0x3Eu);
				if (t4 == 0u)
					a = 0xAAu;
				mem_write8(y_2 + 5u, a);
				t5 = mem_read16(x + 0x35u);
				mem_write8(t5 + 5u, 0x81u);
				y = stack_3;
			}
			t6 = u;
			u = t6 + 1u;
			b = 0xFu * mem_read8(t6);
			mem_write8(y, b);
			y++;
			x += 0xC0u;
			stack = stack + 1u;
			a = stack;
			carry = a < 4u;
		} while (a != 4u);
		t7 = io_read8(VIDEO_18E1);
		io_write8(VIDEO_18E1, t7 + 1u);
		d_2 = ((uint32_t)stack << 8) | b;
	}
	*p_x = x;
	*p_y = y;
	*p_d = d_2;
	*p_carry = carry;
}

void sub_020264(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = *p_carry;
	uint8_t a = 0, b = 0;
	uint16_t bonus_player = 0, d = 0, x = 0, y_2 = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0, t4 = 0, t6 = 0, t7 = 0;
	uint16_t t2 = 0, t3 = 0, t5 = 0;

	unk_48F0 = 0u;
	x = unk_4A40_ADDRESS;
	stack = 0u;
	do
	{
		t1 = mem_read8(x + 0x3Fu);
		if (t1 != 0u)
		{
			t2 = mem_read16(x + 0x30u);
			if (t2 > 0x160u)
			{
				mem_write8(x + 0x3Fu, 0u);
				t3 = mem_read16(x + 0x37u);
				y_2 = t3;
				a = 0x81u;
				t4 = mem_read8(x + 0x3Eu);
				if (t4 == 0u)
					a = 0xA9u;
				mem_write8(y_2 + 5u, a);
				t5 = mem_read16(x + 0x35u);
				y = t5;
				mem_write8(y + 5u, 0x81u);
			}
			else
			{
				bonus_player = bonus_1_player_records[(int8_t)((uint8_t)((uint32_t)stack << 1)) / 2];
				mem_write8(BONUS_PLAYER(bonus_player)->presses, 0u);
				if ((unk_4815 & 1u) == 0u)
					mem_write8(BONUS_PLAYER(bonus_player)->presses, 0x10u);
				d = (uint32_t)stack << 8;
				sub_02034A(bonus_player, &x, &y, &d, &carry);
			}
		}
		t6 = mem_read8(x + 0x3Fu);
		unk_48F0 |= t6;
		x += 0xC0u;
		stack = stack + 1u;
	} while (stack != 4u);
	if (unk_48F0 == 0u)
	{
		d = 0xAD00u;
		carry = sub_078680(d);
		t7 = io_read8(VIDEO_18E1);
		io_write8(VIDEO_18E1, t7 + 1u);
	}
	sub_0208AB(&x, &d, &carry);
	b = (uint8_t)d;
	d = ((uint32_t)stack << 8) | b;
	*p_x = x;
	*p_y = y;
	*p_d = d;
	*p_carry = carry;
}

void sub_0202DD(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t a = 0;
	uint16_t d_2 = 0, u = 0, x = 0;
	uint8_t stack = 0;
	uint16_t stack_3 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = io_read8(VIDEO_18EC);
	io_write8(VIDEO_18EC, 0u);
	x = unk_4A40_ADDRESS;
	u = VIDEO_18E4;
	stack = 0u;
	do
	{
		if (mem_read8(u) != 0u)
			mem_write8(u, mem_read8(u) - 1u);
		else
		{
			stack_3 = u;
			sub_020510(&x, &y, &d);
			u = stack_3;
		}
		x += 0xC0u;
		u++;
		stack = stack + 1u;
	} while (stack != 4u);
	t2 = io_read8(VIDEO_18EC);
	a = t2;
	carry = a < 4u;
	if (a == 4u)
	{
		t3 = io_read8(VIDEO_18E1);
		io_write8(VIDEO_18E1, t3 + 1u);
	}
	d_2 = (d & 0xFFu) | ((uint32_t)stack << 8);
	*p_x = x;
	*p_y = y;
	*p_d = d_2;
	*p_carry = carry;
}

void sub_020316(uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint16_t d_2 = 0;
	uint16_t stack = 0;

	sub_0209F8(&d, &carry);
	unk_4804++;
	stack = d;
	unk_4805 = d;
	d_2 = stack;
	*p_d = d_2;
	*p_carry = carry;
}

void sub_020324(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, u = 0, x = 0, y = 0;

	sub_0208AB(&ignored16, &ignored16_2, &carry);
	x = unk_4A40_ADDRESS;
	unk_48F1 = 0u;
	do
	{
		u = bonus_1_player_records[(int8_t)((uint8_t)((uint32_t)unk_48F1 << 1)) / 2];
		d = (uint32_t)unk_48F1 << 8;
		sub_02034A(u, &x, &y, &d, &carry);
		x += 0xC0u;
		unk_48F1++;
		a = unk_48F1;
	} while (a != 4u);
	d = (d & 0xFFu) | ((uint32_t)a << 8);
	*p_x = x;
	*p_y = y;
	*p_d = d;
}

void sub_02034A(uint16_t u, uint16_t *p_x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t a = 0, b = 0;
	uint16_t d_2 = 0, x_2 = 0, y = 0;
	uint8_t stack_10001 = 0, stack_10002 = 0;
	uint16_t stack = 0, stack_4 = 0;
	uint8_t t1 = 0, t3 = 0, t4 = 0, t5 = 0, t7 = 0, t8 = 0, t9 = 0, t11 = 0, t13 = 0, t14 = 0, t16 = 0, t19 = 0, t20 = 0, t21 = 0, t22 = 0, t23 = 0, t24 = 0, t26 = 0, t27 = 0, t28 = 0;
	uint16_t t2 = 0, t6 = 0, t10 = 0, t12 = 0, t15 = 0, t17 = 0, t18 = 0;
	uint32_t t25 = 0;

	unk_48F3 = d >> 8;
	t1 = io_read8(VIDEO_18E0);
	b = t1;
	carry = b < 0u;
	if (b == 0u)
	{
		t2 = mem_read16(x + 0x37u);
		y = t2;
		t3 = mem_read8(y + 6u);
		a = t3 | 0x40u;
		mem_write8(y + 6u, a);
		d_2 = ((uint32_t)a << 8) | b;
	}
	else
	{
		t4 = mem_read8(x + 6u);
		mem_write8(x + 6u, t4 & 0xBFu);
		mem_write16(x + 0x2Du, 0u);
		if ((mem_read8(BONUS_PLAYER(u)->presses) & 0x30u) == 0u)
		{
			t5 = mem_read8(x + 0x32u);
			if (t5 == 0u)
			{
				t6 = mem_read16(x + 0x37u);
				y = t6;
				t7 = mem_read8(y + 6u);
				if ((t7 & 1u) != 0u)
					mem_write8(x + 0x3Bu, 1u);
				t8 = mem_read8(x + 0x3Bu);
				if (t8 != 0u)
				{
					t9 = mem_read8(y + 6u);
					mem_write8(y + 6u, t9 | 0x40u);
					t10 = mem_read16(x + 0x35u);
					mem_write8(t10 + 5u, 0x81u);
				}
				mem_write16(x + 0x2Du, scene_routines_ADDRESS + 0x2Du);
			}
			else
			{
				t11 = mem_read8(x + 0x32u);
				mem_write8(x + 0x32u, t11 - 1u);
			}
		}
		else
		{
			mem_write8(x + 0x3Bu, 0u);
			t12 = mem_read16(x + 0x37u);
			y = t12;
			a = 2u;
			t13 = mem_read8(x + 0x3Eu);
			if (t13 == 0u)
				a = 0x2Au;
			mem_write8(y + 5u, a);
			t14 = mem_read8(y + 6u);
			mem_write8(y + 6u, t14 & 0xBFu);
			t15 = mem_read16(x + 0x35u);
			y = t15;
			a = 2u;
			t16 = mem_read8(y + 5u);
			if (2u != t16)
				mem_write8(y + 5u, a | 0x80u);
			mem_write16(x + 0x2Du, 0x1C00u);
			mem_write8(x + 0x32u, 0x10u);
		}
		unk_48F2 = 0u;
		t17 = mem_read16(x + 0x2Du);
		if ((int16_t)t17 >= 0)
		{
			if ((mem_read8(x) & 0x20u) != 0u)
			{
				carry = sub_0204D2(x);
				if (carry)
					carry = sub_020494(x);
			}
			else if ((unk_4858 & 3u) != 0u)
			{
				carry = sub_0204D2(x);
				if (carry)
					carry = sub_020494(x);
			}
			else
			{
				carry = sub_020494(x);
				if (carry)
					carry = sub_0204D2(x);
			}
		}
		else
		{
			t18 = mem_read16(x + 0x2Du);
			mem_write16(x + 0x2Du, 0u - t18);
			unk_48F2++;
			if ((unk_4858 & 3u) != 0u)
			{
				carry = sub_0204D2(x);
				if (carry)
					carry = sub_020494(x);
			}
			else
			{
				carry = sub_020494(x);
				if (carry)
					carry = sub_0204D2(x);
			}
		}
		t19 = mem_read8(x + 0x29u);
		mem_write8(x + 0xAu, t19);
		t20 = mem_read8(x + 0x2Bu);
		mem_write8(x + 0xBu, t20);
		t21 = mem_read8(x + 0x29u);
		stack_10001 = 0u;
		stack_10002 = 0u - t21;
		t22 = mem_read8(x + 0x2Bu);
		b = 0u - t22;
		mem_write16(x + 0x30u, b + (((uint32_t)stack_10001 << 8) | stack_10002));
		stack = x;
		t23 = mem_read8(x + 0xAu);
		stack_4 = konami_divx(0x4000u, t23) * 0x20u;
		x_2 = stack;
		mem_write8(x_2 + 0x1Fu, stack_4 >> 8);
		mem_write8(x_2 + 0x20u, 0x40u);
		stack = x_2;
		t24 = mem_read8(x_2 + 0xAu);
		t25 = konami_divx(0x4000u, t24) * 0u;
		y = (uint16_t)t25;
		carry = t25 >> 15;
		stack_4 = y;
		b = (uint8_t)stack_4;
		x = stack;
		mem_write8(x + 0x22u, stack_4 >> 8);
		mem_write8(x + 0x23u, 0x20u);
		mem_write8(x + 0x21u, 1u);
		t26 = mem_read8(x + 0x3Eu);
		a = t26;
		if (t26 != 0u)
		{
			mem_write8(x + 5u, 0x86u);
			t27 = mem_read8(x + 0x29u);
			a = t27;
			carry = a < 0xB0u;
			if (a == 0xB0u)
			{
				t28 = mem_read8(x + 0x2Bu);
				a = t28;
				carry = a < 0xB0u;
				if (a == 0xB0u)
				{
					mem_write8(x + 5u, 0x85u);
					mem_write8(x + 0xAu, 0x40u);
					a = 0x40u;
					mem_write8(x + 0xBu, 0x40u);
				}
			}
		}
		d_2 = ((uint32_t)a << 8) | b;
	}
	*p_x = x;
	*p_y = y;
	*p_d = d_2;
	*p_carry = carry;
}

uint32_t sub_020494(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0, x_2 = 0;
	uint16_t stack = 0, stack_4 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	stack = x;
	t1 = mem_read16(x + 0x2Du);
	stack_4 = t1;
	t2 = mem_read16(x + 0x29u);
	stack_4 = ((((uint32_t)t2 * t2) >> 16) * stack_4) >> 16;
	d = stack_4;
	x_2 = stack;
	if (unk_48F2 == 0u)
		d = 0u - d;
	t3 = mem_read16(x_2 + 0x29u);
	d += t3;
	if (d > 0xB000u)
	{
		mem_write16(x_2 + 0x29u, 0xB000u);
		carry = 1u;
		return carry;
	}
	if (d >= unk_4000_ADDRESS)
	{
		mem_write16(x_2 + 0x29u, d);
		carry = 0u;
		return carry;
	}
	mem_write16(x_2 + 0x29u, unk_4000_ADDRESS);
	carry = 1u;
	return carry;
}

uint32_t sub_0204D2(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0, x_2 = 0;
	uint16_t stack = 0, stack_4 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	stack = x;
	t1 = mem_read16(x + 0x2Du);
	stack_4 = t1;
	t2 = mem_read16(x + 0x2Bu);
	stack_4 = ((((uint32_t)t2 * t2) >> 16) * stack_4) >> 16;
	d = stack_4;
	x_2 = stack;
	if (unk_48F2 == 0u)
		d = 0u - d;
	t3 = mem_read16(x_2 + 0x2Bu);
	d += t3;
	if (d > 0xB000u)
	{
		mem_write16(x_2 + 0x2Bu, 0xB000u);
		carry = 1u;
		return carry;
	}
	if (d >= VIDEO_2000)
	{
		mem_write16(x_2 + 0x2Bu, d);
		carry = 0u;
		return carry;
	}
	mem_write16(x_2 + 0x2Bu, VIDEO_2000);
	carry = 1u;
	return carry;
}

void sub_020510(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = 0;
	uint8_t a = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x43u);
	a = (uint32_t)t1 << 1;
	switch ((int8_t)a)
	{
	case 0:
		sub_020519(&x, &y, &d, &carry);
		break;
	case 2:
		sub_0205C0(&x, &y, &d, &carry);
		break;
	case 4:
		sub_020522(x, &y, &d);
		break;
	case 6:
		sub_020553(x, &y, &d);
		break;
	case 8:
		sub_02056B(x, &y, &d, &carry);
		break;
	case 10:
		sub_020584(x, &y, &d, &carry);
		break;
	case 12:
		sub_0205D3(x, &d, &carry);
		break;
	case 14:
		sub_020600(x, &d, &carry);
		break;
	case 16:
		d = (d & 0xFFu) | ((uint32_t)a << 8);
		sub_02061F(x);
		break;
	case 18:
		d = (d & 0xFFu) | ((uint32_t)a << 8);
		sub_020628();
		break;
	case 20:
		sub_020922(y, &d, &carry);
		break;
	case 22:
		sub_020937(&x, &d, &carry);
		break;
	case 24:
	case 28:
		d = (d & 0xFFu) | ((uint32_t)a << 8);
		carry = sub_020975();
		break;
	case 26:
		sub_02097E(x, &y, &d, &carry);
		break;
	case 30:
		sub_020996(x, &y, &d, &carry);
		break;
	case 32:
		d = sub_0209CA();
		break;
	case 34:
		d = (d & 0xFFu) | ((uint32_t)a << 8);
		sub_0209D6(&x, &y, &d, &carry);
		break;
	case 36:
		d = (d & 0xFFu) | ((uint32_t)a << 8);
		sub_0209F7();
		break;
	case -30:
		sub_020020(&x, &y, &d, &carry);
		break;
	case -28:
		sub_02002A(&x, &y, &d, &carry);
		break;
	case -26:
		sub_0200B4(&x, &y, &d, &carry);
		break;
	case -24:
		sub_020107(&x, &y, &d, &carry);
		break;
	case -22:
		sub_02016F(&x, &y, &d, &carry);
		break;
	case -20:
		sub_0201F2(&x, &y, &d, &carry);
		break;
	case -18:
		sub_020116(&x, &y, &d, &carry);
		break;
	case -16:
		sub_02013F(&x, &y, &d, &carry);
		break;
	case -14:
		sub_020182(&d, &carry);
		break;
	case -12:
		sub_02018D(&x, &y, &d, &carry);
		break;
	case -10:
		sub_0201FC(&d, &carry);
		break;
	case -8:
		sub_020207(&x, &y, &d, &carry);
		break;
	case -6:
		sub_020264(&x, &y, &d, &carry);
		break;
	case -4:
		sub_0202DD(&x, &y, &d, &carry);
		break;
	case -2:
		d = (d & 0xFFu) | ((uint32_t)a << 8);
		sub_020316(&d, &carry);
		break;
	}
	*p_x = x;
	*p_y = y;
	*p_d = d;
}

void sub_020519(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t a = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		t1 = mem_read8(x + 0x44u);
		a = t1;
		carry = (int8_t)a < 0;
		a = (uint32_t)a << 1;
		switch ((int8_t)a)
		{
		case 0:
			sub_020522(x, &y, &d);
			break;
		case 2:
			sub_020553(x, &y, &d);
			break;
		case 4:
			sub_02056B(x, &y, &d, &carry);
			break;
		case 6:
			sub_020584(x, &y, &d, &carry);
			break;
		case 8:
			sub_0205D3(x, &d, &carry);
			break;
		case 10:
			sub_020600(x, &d, &carry);
			break;
		case 12:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			sub_02061F(x);
			break;
		case 14:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			sub_020628();
			break;
		case 16:
			sub_020922(y, &d, &carry);
			break;
		case 18:
			sub_020937(&x, &d, &carry);
			break;
		case 20:
		case 24:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			carry = sub_020975();
			break;
		case 22:
			sub_02097E(x, &y, &d, &carry);
			break;
		case 26:
			sub_020996(x, &y, &d, &carry);
			break;
		case 28:
			d = sub_0209CA();
			break;
		case 30:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			sub_0209D6(&x, &y, &d, &carry);
			break;
		case 32:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			sub_0209F7();
			break;
		case -34:
			sub_020020(&x, &y, &d, &carry);
			break;
		case -32:
			sub_02002A(&x, &y, &d, &carry);
			break;
		case -30:
			sub_0200B4(&x, &y, &d, &carry);
			break;
		case -28:
			sub_020107(&x, &y, &d, &carry);
			break;
		case -26:
			sub_02016F(&x, &y, &d, &carry);
			break;
		case -24:
			sub_0201F2(&x, &y, &d, &carry);
			break;
		case -22:
			sub_020116(&x, &y, &d, &carry);
			break;
		case -20:
			sub_02013F(&x, &y, &d, &carry);
			break;
		case -18:
			sub_020182(&d, &carry);
			break;
		case -16:
			sub_02018D(&x, &y, &d, &carry);
			break;
		case -14:
			sub_0201FC(&d, &carry);
			break;
		case -12:
			sub_020207(&x, &y, &d, &carry);
			break;
		case -10:
			sub_020264(&x, &y, &d, &carry);
			break;
		case -8:
			sub_0202DD(&x, &y, &d, &carry);
			break;
		case -6:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			sub_020316(&d, &carry);
			break;
		case -4:
			continue;
		case -2:
			sub_0205C0(&x, &y, &d, &carry);
			break;
		}
		break;
	}
	*p_x = x;
	*p_y = y;
	*p_d = d;
	*p_carry = carry;
}

void sub_020522(uint16_t x, uint16_t *p_y, uint16_t *p_d)
{
	uint8_t a = 0, b = 0;
	uint16_t d = 0, y = 0;
	uint8_t t2 = 0, t5 = 0;
	uint16_t t1 = 0, t3 = 0, t4 = 0;

	t1 = mem_read16(x + 0x33u);
	y = t1;
	mem_write8(y, 0x80u);
	a = 0x83u;
	t2 = mem_read8(x + 0x3Eu);
	b = t2;
	if (t2 == 0u)
		a = 0xABu;
	mem_write8(y + 5u, a);
	t3 = mem_read16(x + 0x35u);
	mem_write8(t3 + 5u, 0x83u);
	t4 = mem_read16(x + 0x37u);
	y = t4;
	mem_write8(y + 4u, 0xAu);
	mem_write8(y + 5u, 0x8Fu);
	mem_write8(x + 0x3Du, 0x20u);
	t5 = mem_read8(x + 0x44u);
	mem_write8(x + 0x44u, t5 + 1u);
	d = 0x2000u | b;
	*p_y = y;
	*p_d = d;
}

void sub_020553(uint16_t x, uint16_t *p_y, uint16_t *p_d)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t d = 0;
	uint8_t t1 = 0, t4 = 0;
	uint16_t t2 = 0, t3 = 0;

	d = VIDEO_00A0;
	mem_write16(x + 0x19u, VIDEO_00A0);
	t1 = mem_read8(x + 0x3Du);
	mem_write8(x + 0x3Du, t1 - 1u);
	if (t1 == 1u)
	{
		t2 = mem_read16(x + 0x33u);
		y = t2;
		t3 = mem_read16(x + 0x19u);
		d = t3;
		mem_write16(y + 0x19u, d);
		t4 = mem_read8(x + 0x44u);
		mem_write8(x + 0x44u, t4 + 1u);
	}
	*p_y = y;
	*p_d = d;
}

void sub_02056B(uint16_t x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d = 0, y = 0;
	uint8_t t4 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read16(x + 0x19u);
	mem_write16(x + 0x19u, t1 + 8u);
	t2 = mem_read16(x + 0x33u);
	y = t2;
	t3 = mem_read16(y + 0x19u);
	d = t3;
	carry = (uint16_t)(d + 8u) < d;
	d += 8u;
	mem_write16(y + 0x19u, d);
	t4 = mem_read8(x + 0x44u);
	mem_write8(x + 0x44u, t4 + 1u);
	*p_y = y;
	*p_d = d;
	*p_carry = carry;
}

void sub_020584(uint16_t x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d = 0, y = 0;
	uint8_t t4 = 0, t8 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t5 = 0, t6 = 0, t7 = 0;

	t1 = mem_read16(x + 0x19u);
	mem_write16(x + 0x19u, t1 + 8u);
	t2 = mem_read16(x + 0x33u);
	y = t2;
	t3 = mem_read16(y + 0x19u);
	mem_write16(y + 0x19u, t3 + 8u);
	t4 = mem_read8(x + 0x3Eu);
	if (t4 == 0u)
	{
		t5 = mem_read16(x + 0x16u);
		if (t5 > 0x80u)
		{
			mem_write8(x + 0x43u, 1u);
			mem_write8(x + 0x44u, 0u);
		}
	}
	t6 = mem_read16(x + 0x16u);
	d = t6;
	carry = d < 0x180u;
	if (d > 0x180u)
	{
		mem_write8(x, 0u);
		t7 = mem_read16(x + 0x33u);
		carry = 0u;
		mem_write8(t7, 0u);
		t8 = io_read8(VIDEO_18EC);
		io_write8(VIDEO_18EC, t8 + 1u);
	}
	*p_y = y;
	*p_d = d;
	*p_carry = carry;
}

void sub_0205C0(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint8_t d = (uint8_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t a = 0;
	uint16_t d_2 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x44u);
	a = t1;
	carry = (int8_t)a < 0;
	a = (uint32_t)a << 1;
	d_2 = (d & 0xFFu) | ((uint32_t)a << 8);
	switch ((int8_t)a)
	{
	case 0:
		sub_0205D3(x, &d_2, &carry);
		break;
	case 2:
		sub_020600(x, &d_2, &carry);
		break;
	case 4:
		sub_02061F(x);
		break;
	case 6:
		sub_020628();
		break;
	case 8:
		sub_020922(y, &d_2, &carry);
		break;
	case 10:
		sub_020937(&x, &d_2, &carry);
		break;
	case 12:
	case 16:
		carry = sub_020975();
		break;
	case 14:
		sub_02097E(x, &y, &d_2, &carry);
		break;
	case 18:
		sub_020996(x, &y, &d_2, &carry);
		break;
	case 20:
		d_2 = sub_0209CA();
		break;
	case 22:
		sub_0209D6(&x, &y, &d_2, &carry);
		break;
	case 24:
		sub_0209F7();
		break;
	case -42:
		sub_020020(&x, &y, &d_2, &carry);
		break;
	case -40:
		sub_02002A(&x, &y, &d_2, &carry);
		break;
	case -38:
		sub_0200B4(&x, &y, &d_2, &carry);
		break;
	case -36:
		sub_020107(&x, &y, &d_2, &carry);
		break;
	case -34:
		sub_02016F(&x, &y, &d_2, &carry);
		break;
	case -32:
		sub_0201F2(&x, &y, &d_2, &carry);
		break;
	case -30:
		sub_020116(&x, &y, &d_2, &carry);
		break;
	case -28:
		sub_02013F(&x, &y, &d_2, &carry);
		break;
	case -26:
		sub_020182(&d_2, &carry);
		break;
	case -24:
		sub_02018D(&x, &y, &d_2, &carry);
		break;
	case -22:
		sub_0201FC(&d_2, &carry);
		break;
	case -20:
		sub_020207(&x, &y, &d_2, &carry);
		break;
	case -18:
		sub_020264(&x, &y, &d_2, &carry);
		break;
	case -16:
		sub_0202DD(&x, &y, &d_2, &carry);
		break;
	case -14:
		sub_020316(&d_2, &carry);
		break;
	case -12:
		sub_020519(&x, &y, &d_2, &carry);
		break;
	case -10:
		sub_0205C0(&x, &y, &d_2, &carry);
		break;
	case -8:
		sub_020522(x, &y, &d_2);
		break;
	case -6:
		sub_020553(x, &y, &d_2);
		break;
	case -4:
		sub_02056B(x, &y, &d_2, &carry);
		break;
	case -2:
		sub_020584(x, &y, &d_2, &carry);
		break;
	}
	t2 = mem_read8(x + 6u);
	t3 = t2 & 1u;
	a = t3;
	if (t3 != 0u)
	{
		carry = 0u;
		mem_write8(x, 0u);
	}
	d_2 = (d_2 & 0xFFu) | ((uint32_t)a << 8);
	*p_x = x;
	*p_y = y;
	*p_d = d_2;
	*p_carry = carry;
}

void sub_0205D3(uint16_t x, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d = 0, u = 0;
	uint8_t t2 = 0, t3 = 0;
	uint16_t t1 = 0;

	d = 0x6C00u;
	carry = sub_078680(d);
	mem_write8(x + 4u, 0x90u);
	mem_write8(x + 5u, 0x93u);
	carry = 0u;
	mem_write16(x + 0x19u, 0u);
	t1 = mem_read16(x + 0x33u);
	u = t1;
	mem_write8(u + 4u, 0x80u);
	t2 = mem_read8(u + 9u);
	mem_write8(u + 9u, t2 | 0x40u);
	mem_write8(u + 5u, 0x8Du);
	t3 = mem_read8(x + 0x44u);
	mem_write8(x + 0x44u, t3 + 1u);
	d = 0x8D00u;
	*p_d = d;
	*p_carry = carry;
}

void sub_020600(uint16_t x, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t a = 0;
	uint16_t d = 0, x_2 = 0;
	uint16_t stack = 0;
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = mem_read16(x + 0x33u);
	stack = x;
	x_2 = t1;
	sub_0785B1(x_2, &d, &carry);
	a = (uint8_t)(d >> 8);
	x_2 = stack;
	if (carry)
	{
		t2 = mem_read16(x_2 + 0x33u);
		mem_write8(t2 + 5u, 0x8Eu);
		a = 0x60u;
		mem_write8(x_2 + 0x40u, 0x60u);
		t3 = mem_read8(x_2 + 0x44u);
		mem_write8(x_2 + 0x44u, t3 + 1u);
	}
	d = (d & 0xFFu) | ((uint32_t)a << 8);
	*p_d = d;
	*p_carry = carry;
}

void sub_02061F(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x40u);
	mem_write8(x + 0x40u, t1 - 1u);
	if (t1 == 1u)
	{
		t2 = mem_read8(x + 0x44u);
		mem_write8(x + 0x44u, t2 + 1u);
	}
}

void sub_020628(void)
{
	uint8_t t1 = 0;

	t1 = io_read8(VIDEO_18EC);
	io_write8(VIDEO_18EC, t1 + 1u);
}

void sub_02062D(uint16_t *p_x, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t x = 0;
	uint8_t stack = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	x = unk_4A40_ADDRESS;
	stack = 4u;
	for (;;)
	{
		t1 = mem_read16(x + 0x30u);
		if (t1 >= 0x1A0u)
		{
			carry = 1u;
			break;
		}
		x += 0xC0u;
		t2 = stack;
		stack = t2 - 1u;
		if (t2 == 1u)
		{
			carry = 0u;
			break;
		}
	}
	*p_x = x;
	*p_carry = carry;
}

uint32_t sub_02064A(void)
{
	uint32_t carry = 0, half_carry = 0;
	uint8_t a = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = unk_487B;
	a = t1;
	if (t1 == 0u)
	{
		unk_487B = a;
		t2 = unk_487A;
		a = t2;
		if (t2 == 0u)
		{
			unk_48F8 = 0xE0u;
			unk_48FA = 0xB8u;
			sub_020685();
			carry = 1u;
			return carry;
		}
		half_carry = ((uint8_t)(a ^ 0x99u ^ (a - 0x67u)) >> 4) & 1u;
		carry = (uint8_t)(a - 0x67u) < a;
		unk_487A = konami_daa((uint8_t)(a - 0x67u), half_carry, carry);
		unk_487B = 0x98u;
		carry = 0u;
		return carry;
	}
	half_carry = ((uint8_t)(a ^ 0x99u ^ (a - 0x67u)) >> 4) & 1u;
	carry = (uint8_t)(a - 0x67u) < a;
	a = konami_daa((uint8_t)(a - 0x67u), half_carry, carry);
	if (a == 0u)
	{
		unk_487B = a;
		t2 = unk_487A;
		a = t2;
		if (t2 == 0u)
		{
			unk_48F8 = 0xE0u;
			unk_48FA = 0xB8u;
			sub_020685();
			carry = 1u;
			return carry;
		}
		half_carry = ((uint8_t)(a ^ 0x99u ^ (a - 0x67u)) >> 4) & 1u;
		carry = (uint8_t)(a - 0x67u) < a;
		unk_487A = konami_daa((uint8_t)(a - 0x67u), half_carry, carry);
		unk_487B = 0x98u;
		carry = 0u;
		return carry;
	}
	half_carry = ((uint8_t)(a ^ 0x99u ^ (a - 0x67u)) >> 4) & 1u;
	carry = (uint8_t)(a - 0x67u) < a;
	a = konami_daa((uint8_t)(a - 0x67u), half_carry, carry);
	if (a != 0u)
	{
		unk_487B = a;
		carry = 0u;
		return carry;
	}
	unk_487B = a;
	t2 = unk_487A;
	a = t2;
	if (t2 == 0u)
	{
		unk_48F8 = 0xE0u;
		unk_48FA = 0xB8u;
		sub_020685();
		carry = 1u;
		return carry;
	}
	half_carry = ((uint8_t)(a ^ 0x99u ^ (a - 0x67u)) >> 4) & 1u;
	carry = (uint8_t)(a - 0x67u) < a;
	unk_487A = konami_daa((uint8_t)(a - 0x67u), half_carry, carry);
	unk_487B = 0x98u;
	carry = 0u;
	return carry;
}

void sub_020685(void)
{
}

void unused_020686(void)
{
	uint8_t a = 0, d = 0;
	uint16_t x = 0;
	uint8_t stack = 0;
	uint8_t t6 = 0, t7 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	x = unk_4DA0_ADDRESS;
	stack = 4u;
	do
	{
		mem_write8(x, 0x80u);
		mem_write8(x + 4u, 0xEu);
		t1 = unk_48F8;
		d = (uint8_t)t1;
		a = (uint8_t)(t1 >> 8);
		mem_write16(x + 0xCu, ((uint32_t)a << 8) | (d & 0xFFu));
		t2 = (((uint32_t)a << 8) | (d & 0xFFu)) + 0x10u;
		unk_48F8 = t2;
		mem_write16(x + 0x11u, VIDEO_00A0);
		t3 = unk_48FA;
		mem_write16(x + 0x16u, t3);
		if (stack == 3u)
		{
			t4 = unk_48F8;
			t5 = t4 + 8u;
			unk_48F8 = t5;
		}
		x += 0x60u;
		t6 = stack;
		stack = t6 - 1u;
	} while (t6 != 1u);
	x = unk_4DA0_ADDRESS;
	t7 = (((unk_487A >> 1) >> 1) >> 1) >> 1;
	a = t7;
	if (t7 == 0u)
		unk_4DA0 = 0u;
	mem_write8(x + 5u, a - 0x50u);
	x += 0x60u;
	mem_write8(x + 5u, (unk_487A & 0xFu) - 0x50u);
	x += 0x60u;
	mem_write8(x + 5u, ((((unk_487B >> 1) >> 1) >> 1) >> 1) - 0x50u);
	mem_write8(x + 0x65u, (unk_487B & 0xFu) - 0x50u);
}

void sub_020706(void)
{
}

void unused_020707(void)
{
	uint16_t t1 = 0, t2 = 0;

	unk_4D40 = 0x80u;
	unk_4D44 = 0xEu;
	unk_4D45 = 0x8Fu;
	t1 = unk_48F8;
	unk_4D4C = t1;
	unk_4D51 = VIDEO_00A0;
	t2 = unk_48FA;
	unk_4D56 = t2;
}

void sub_02072E(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, x = 0, y = 0;
	uint8_t stack = 0, stack_2 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;
	uint16_t t5 = 0;

	x = unk_4A40_ADDRESS;
	a = 0u;
	do
	{
		stack = a;
		d = (uint32_t)a << 8;
		sub_0207C7(x, &y, &d, &carry);
		t1 = mem_read8(x + 0x3Eu);
		if (t1 == 0u)
		{
			d = 0x1000u;
			sub_0207C7(x, &y, &d, &carry);
		}
		mem_write8(y, mem_read8(y));
		mem_write8(x + 0x3Bu, 1u);
		b = 0x40u;
		t2 = mem_read8(x + 0x3Eu);
		if (t2 == 0u)
			b = 0xB0u;
		mem_write8(x + 0xAu, b);
		mem_write8(x + 0x29u, 0xB0u);
		b = 0x40u;
		t3 = mem_read8(x + 0x3Eu);
		if (t3 == 0u)
			b = 0xB0u;
		mem_write8(x + 0xBu, b);
		mem_write8(x + 0x2Bu, 0xB0u);
		x += 0xC0u;
		a = stack + 1u;
	} while (a != 4u);
	x = unk_4A40_ADDRESS;
	unk_48F0 = 0u;
	do
	{
		unk_48F1 = 0u;
		do
		{
			d = (uint32_t)(uint8_t)((((uint32_t)unk_48F1 << 1) << 1) + unk_48F0 + 4u) << 8;
			sub_0207C7(x, &y, &d, &carry);
			t4 = mem_read8(x + 0x3Eu);
			if (t4 == 0u)
			{
				stack_2 = x >> 8;
				stack = (uint8_t)x;
				x = y;
				d = (uint32_t)(uint8_t)(0x11u + unk_48F1) << 8;
				sub_0207C7(x, &y, &d, &carry);
				x = ((uint32_t)stack_2 << 8) | stack;
			}
			b = ((uint32_t)unk_48F1 << 1) + 0x33u;
			mem_write16(x + (int8_t)b, y);
			unk_48F1++;
		} while (unk_48F1 != 3u);
		t5 = mem_read16(x + 0x33u);
		mem_write8(t5, 0u);
		x += 0xC0u;
		unk_48F0++;
		a = unk_48F0;
		carry = a < 4u;
	} while (a != 4u);
	d = ((uint32_t)a << 8) | b;
	*p_x = x;
	*p_y = y;
	*p_d = d;
	*p_carry = carry;
}

void sub_0207C7(uint16_t x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t a = 0, b = 0;
	uint16_t d_2 = 0, placement = 0, u = 0, y = 0;
	uint16_t t1 = 0, t2 = 0, kind = 0, t3 = 0, x_2 = 0, z = 0, t4 = 0;

	t1 = bonus_placements[(int8_t)((uint8_t)((uint32_t)(d >> 8) << 1)) / 2];
	u = t1 + 2u;
	y = PLACEMENT(t1)->object;
	if (y == 0xFFFFu)
		y = x;
	mem_write8(y, mem_read8(y) | 0x80u);
	t2 = u;
	kind = PLACEMENT(t2 - 0x2u)->kind;
	mem_write16(y + 4u, ((uint32_t)(kind >> 8) << 8) | (uint8_t)(kind | 0x80u));
	t3 = t2 + 2u;
	placement = t3 + 2u;
	x_2 = PLACEMENT(t3 - 0x4u)->x;
	a = (uint8_t)(x_2 >> 8);
	b = (uint8_t)x_2;
	if ((uint16_t)(((uint32_t)a << 8) | b) != 0xFFFFu)
		mem_write16(y + 0xCu, ((uint32_t)a << 8) | b);
	mem_write16(y + 0x11u, 0xB0u);
	z = PLACEMENT(placement - 0x6u)->z;
	a = (uint8_t)(z >> 8);
	b = (uint8_t)z;
	t4 = ((uint32_t)a << 8) | b;
	carry = t4 < 0xFFFFu;
	if (t4 != 0xFFFFu)
		mem_write16(y + 0x16u, ((uint32_t)a << 8) | b);
	d_2 = ((uint32_t)a << 8) | b;
	*p_y = y;
	*p_d = d_2;
	*p_carry = carry;
}

void sub_020803(void)
{
	uint16_t bonus_player = 0, x = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0;
	uint16_t controls_pressed = 0;

	x = unk_4A40_ADDRESS;
	stack = 0u;
	do
	{
		t1 = mem_read8(x + 0x3Eu);
		if (t1 != 0u)
		{
			bonus_player = bonus_1_player_records[(int8_t)((uint8_t)((uint32_t)stack << 1)) / 2];
			controls_pressed = BONUS_PLAYER(bonus_player)->controls_pressed;
			mem_write8(BONUS_PLAYER(bonus_player)->presses, mem_read8(controls_pressed));
		}
		x += 0xC0u;
		stack = stack + 1u;
	} while (stack != 4u);
}

void sub_020829(void)
{
	uint16_t x = 0;
	uint8_t stack = 0, stack_2 = 0;
	uint8_t t1 = 0, t2 = 0;
	uint16_t object = 0;

	unk_48F0 = 0u;
	stack = 0u;
	stack_2 = unk_4858 & 3u;
	do
	{
		object = BONUS_PLAYER(bonus_1_player_records[stack_2 & 0x7Fu])->object;
		x = object;
		t1 = mem_read8(x + 0x3Eu);
		if (t1 == 0u)
		{
			if (unk_48F0 == 0u)
			{
				unk_48F0++;
				mem_write8(x + 0x42u, 0u);
			}
			else
				mem_write8(x + 0x42u, stack + stack_2);
		}
		t2 = mem_read8(x + 0x42u);
		mem_write8(x + 0x42u, t2 + 5u);
		stack_2 = (stack_2 + 1u) & 3u;
		stack = stack + 1u;
	} while (stack != 4u);
}

void sub_020874(void)
{
	uint16_t bonus_player = 0, x = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	x = unk_4A40_ADDRESS;
	stack = 0u;
	do
	{
		t1 = mem_read8(x + 0x3Eu);
		if (t1 == 0u)
		{
			bonus_player = bonus_1_player_records[(int8_t)((uint8_t)((uint32_t)stack << 1)) / 2];
			t2 = mem_read8(x + 0x41u);
			if (t2 != 0u)
			{
				mem_write8(BONUS_PLAYER(bonus_player)->presses, 0u);
				t3 = mem_read8(x + 0x41u);
				mem_write8(x + 0x41u, t3 - 1u);
			}
			else
			{
				mem_write8(BONUS_PLAYER(bonus_player)->presses, 0x10u);
				t4 = mem_read8(x + 0x42u);
				mem_write8(x + 0x41u, t4);
			}
		}
		x += 0xC0u;
		stack = stack + 1u;
	} while (stack != 4u);
}

void sub_0208AB(uint16_t *p_x, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, u = 0, x = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;

	t1 = io_read8(VIDEO_18ED);
	if ((int8_t)t1 >= 0)
	{
		t2 = io_read8(VIDEO_18ED);
		io_write8(VIDEO_18ED, t2 + 1u);
	}
	a = 0u;
	stack = 0u;
	x = bonus_1_player_records_ADDRESS;
	do
	{
		u = mem_read16(x);
		t3 = mem_read8(x + 0x3Eu);
		if (t3 != 0u)
			a |= mem_read8(mem_read16(u));
		x += 2u;
		stack = stack + 1u;
		b = stack;
		carry = b < 4u;
	} while (b != 4u);
	t4 = a & 0x3Fu;
	a = t4;
	if (t4 != 0u)
	{
		t5 = io_read8(VIDEO_18ED);
		a = t5;
		carry = a < 0x20u;
		if (a > 0x20u)
		{
			t6 = io_read8(VIDEO_18ED);
			io_write8(VIDEO_18ED, 0u);
			a = 0x29u;
			b = 0u;
			d = 0x2900u;
			carry = sub_078680(d);
		}
	}
	d = ((uint32_t)a << 8) | b;
	*p_x = x;
	*p_d = d;
	*p_carry = carry;
}

void sub_0208E9(void)
{
	uint8_t a = 0, b = 0;
	uint16_t x = 0;
	uint8_t t1 = 0, t2 = 0;

	x = unk_4A40_ADDRESS;
	a = 1u;
	b = 4u;
	do
	{
		mem_write8(x + 0x3Eu, 0u);
		if ((a & unk_4850) != 0u)
		{
			t1 = mem_read8(x + 0x3Eu);
			mem_write8(x + 0x3Eu, t1 + 1u);
		}
		a = (uint32_t)a << 1;
		x += 0xC0u;
		t2 = b;
		b = t2 - 1u;
	} while (t2 != 1u);
}

uint16_t sub_020904(void)
{
	uint8_t a = 0, b = 0;
	uint16_t d = 0, x = 0;
	uint8_t t1 = 0;

	x = unk_4A40_ADDRESS;
	b = 4u;
	do
	{
		a = mem_read8(x) | 0x10u;
		mem_write8(x, a);
		x += 0xC0u;
		t1 = b;
		b = t1 - 1u;
	} while (t1 != 1u);
	d = ((uint32_t)a << 8) | b;
	return d;
}

void sub_020919(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t a = 0;
	uint16_t x = 0;

	x = loaded_table_021BB2_ADDRESS;
	a = (uint8_t)(unk_4805 >> 8u);
	carry = (int8_t)a < 0;
	a = (uint32_t)a << 1;
	switch ((int8_t)a)
	{
	case 0:
		sub_020922(y, &d, &carry);
		break;
	case 2:
		sub_020937(&x, &d, &carry);
		break;
	case 4:
	case 8:
		d = (d & 0xFFu) | ((uint32_t)a << 8);
		carry = sub_020975();
		break;
	case 6:
		sub_02097E(x, &y, &d, &carry);
		break;
	case 10:
		sub_020996(x, &y, &d, &carry);
		break;
	case 12:
		d = sub_0209CA();
		break;
	case 14:
		d = (d & 0xFFu) | ((uint32_t)a << 8);
		sub_0209D6(&x, &y, &d, &carry);
		break;
	case 16:
		d = (d & 0xFFu) | ((uint32_t)a << 8);
		sub_0209F7();
		break;
	case -50:
		sub_020020(&x, &y, &d, &carry);
		break;
	case -48:
		sub_02002A(&x, &y, &d, &carry);
		break;
	case -46:
		sub_0200B4(&x, &y, &d, &carry);
		break;
	case -44:
		sub_020107(&x, &y, &d, &carry);
		break;
	case -42:
		sub_02016F(&x, &y, &d, &carry);
		break;
	case -40:
		sub_0201F2(&x, &y, &d, &carry);
		break;
	case -38:
		sub_020116(&x, &y, &d, &carry);
		break;
	case -36:
		sub_02013F(&x, &y, &d, &carry);
		break;
	case -34:
		sub_020182(&d, &carry);
		break;
	case -32:
		sub_02018D(&x, &y, &d, &carry);
		break;
	case -30:
		sub_0201FC(&d, &carry);
		break;
	case -28:
		sub_020207(&x, &y, &d, &carry);
		break;
	case -26:
		sub_020264(&x, &y, &d, &carry);
		break;
	case -24:
		sub_0202DD(&x, &y, &d, &carry);
		break;
	case -22:
		d = (d & 0xFFu) | ((uint32_t)a << 8);
		sub_020316(&d, &carry);
		break;
	case -20:
		sub_020519(&x, &y, &d, &carry);
		break;
	case -18:
		sub_0205C0(&x, &y, &d, &carry);
		break;
	case -16:
		sub_020522(x, &y, &d);
		break;
	case -14:
		sub_020553(x, &y, &d);
		break;
	case -12:
		sub_02056B(x, &y, &d, &carry);
		break;
	case -10:
		sub_020584(x, &y, &d, &carry);
		break;
	case -8:
		sub_0205D3(x, &d, &carry);
		break;
	case -6:
		sub_020600(x, &d, &carry);
		break;
	case -4:
		d = (d & 0xFFu) | ((uint32_t)a << 8);
		sub_02061F(x);
		break;
	case -2:
		d = (d & 0xFFu) | ((uint32_t)a << 8);
		sub_020628();
		break;
	}
	*p_x = x;
	*p_y = y;
	*p_d = d;
	*p_carry = carry;
}

void sub_020922(uint16_t y, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d = 0;

	mem_write8(y, 0x80u);
	mem_write16(y + 0x11u, 0x70u);
	mem_write8(y + 9u, 0x20u);
	unk_4805 = (unk_4805 & 0xFFu) | (((uint8_t)(unk_4805 >> 8u) + 1u & 0xFFu) << 8u);
	carry = 0u;
	d = 0x70u;
	*p_d = d;
	*p_carry = carry;
}

void sub_020937(uint16_t *p_x, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t b = 0;
	uint16_t d = 0, x = 0;
	uint16_t t1 = 0, t2 = 0;

	x = unk_4D40_ADDRESS;
	unk_4D59 = 0x300u;
	t1 = unk_48C5;
	t2 = t1;
	b = (uint8_t)(t2 + 3u);
	unk_48C5 = ((uint32_t)((uint16_t)(t2 + 3u) >> 8) << 8) | b;
	if (t2 <= (uint16_t)(t2 + 3u))
	{
		carry = 0u;
		d = b;
	}
	else
	{
		x = unk_4D40_ADDRESS;
		unk_48C5 = 0u;
		unk_4D59 = 0u;
		unk_4D56 = 0xCFu;
		unk_4D46 = 0x80u;
		unk_4805 &= 0xFFu;
		carry = 1u;
		d = 0x7FCFu;
	}
	*p_x = x;
	*p_d = d;
	*p_carry = carry;
}

uint16_t sub_020967(uint16_t y)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, x = 0, y_2 = 0;
	uint16_t t1 = 0;

	t1 = ((uint8_t)unk_4815 & 0x60u) >> 5;
	a = (uint8_t)(t1 >> 8);
	x = loaded_table_021BB6_ADDRESS;
	b = (uint32_t)t1 << 1;
	switch ((int8_t)b)
	{
	case 0:
	case 4:
		carry = sub_020975();
		return y;
	case 2:
		sub_02097E(x, &y_2, &ignored16_2, &carry);
		return y_2;
	case 6:
		sub_020996(x, &y_2, &ignored16_2, &carry);
		return y_2;
	case 8:
		sub_0209CA();
		return y;
	case 10:
		d = (uint32_t)a << 8;
		sub_0209D6(&x, &y, &d, &carry);
		return y;
	case 12:
		sub_0209F7();
		return y;
	case -54:
		d = b;
		sub_020020(&ignored16, &y, &d, &carry);
		return y;
	case -52:
		sub_02002A(&ignored16, &y_2, &ignored16_2, &carry);
		return y_2;
	case -50:
		sub_0200B4(&ignored16, &y, &ignored16_2, &carry);
		return y;
	case -48:
		d = b;
		sub_020107(&ignored16, &y, &d, &carry);
		return y;
	case -46:
		sub_02016F(&ignored16, &y_2, &ignored16_2, &carry);
		return y_2;
	case -44:
		d = b;
		sub_0201F2(&ignored16, &y, &d, &carry);
		return y;
	case -42:
		sub_020116(&ignored16, &y_2, &ignored16_2, &carry);
		return y_2;
	case -40:
		sub_02013F(&ignored16, &y_2, &ignored16_2, &carry);
		return y_2;
	case -38:
		sub_020182(&ignored16_2, &carry);
		return y;
	case -36:
		sub_02018D(&ignored16, &y, &ignored16_2, &carry);
		return y;
	case -34:
		sub_0201FC(&ignored16_2, &carry);
		return y;
	case -32:
		sub_020207(&ignored16, &y, &ignored16_2, &carry);
		return y;
	case -30:
		sub_020264(&ignored16, &y, &ignored16_2, &carry);
		return y;
	case -28:
		d = b;
		sub_0202DD(&ignored16, &y, &d, &carry);
		return y;
	case -26:
		d = ((uint32_t)a << 8) | b;
		sub_020316(&d, &carry);
		return y;
	case -24:
		d = b;
		sub_020519(&x, &y, &d, &carry);
		return y;
	case -22:
		d = b;
		sub_0205C0(&x, &y, &d, &carry);
		return y;
	case -20:
		sub_020522(x, &y_2, &ignored16_2);
		return y_2;
	case -18:
		sub_020553(x, &y, &ignored16_2);
		return y;
	case -16:
		sub_02056B(x, &y_2, &ignored16_2, &carry);
		return y_2;
	case -14:
		sub_020584(x, &y_2, &ignored16_2, &carry);
		return y_2;
	case -12:
		sub_0205D3(x, &ignored16_2, &carry);
		return y;
	case -10:
		sub_020600(x, &ignored16_2, &carry);
		return y;
	case -8:
		sub_02061F(x);
		return y;
	case -6:
		sub_020628();
		return y;
	case -4:
		sub_020922(y, &ignored16_2, &carry);
		return y;
	case -2:
		sub_020937(&ignored16, &ignored16_2, &carry);
		return y;
	}
	unreachable();
}

uint32_t sub_020975(void)
{
	uint32_t carry = 0;

	unk_4DA0 = 0u;
	carry = 0u;
	unk_4E00 = 0u;
	return carry;
}

void sub_02097E(uint16_t x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d = 0, y = 0;

	d = 0x1500u;
	sub_0207C7(x, &y, &d, &carry);
	mem_write8(y, 0x80u);
	d = 0x1600u;
	sub_0207C7(x, &y, &d, &carry);
	mem_write8(y, 0x80u);
	mem_write8(y + 9u, 0x20u);
	d = (d & 0xFFu) | 0x2000u;
	*p_y = y;
	*p_d = d;
	*p_carry = carry;
}

void sub_020996(uint16_t x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d = 0, y = 0;

	d = 0x1700u;
	sub_0207C7(x, &y, &d, &carry);
	mem_write8(y, 0x80u);
	d = 0x1800u;
	sub_0207C7(x, &y, &d, &carry);
	mem_write8(y, 0x80u);
	mem_write8(y + 9u, 0x20u);
	d = (d & 0xFFu) | 0x2000u;
	*p_y = y;
	*p_d = d;
	*p_carry = carry;
}

void sub_0209AE(void)
{
	uint32_t carry = 0;
	uint16_t d = 0, x = 0, y = 0;

	x = mem_read16(bonus_placements[25]);
	if (mem_read8(x) != 0u)
		return;
	d = 0x1900u;
	sub_0207C7(x, &y, &d, &carry);
	mem_write8(y, 0x80u);
}

void sub_0209C0(uint16_t *p_y, uint16_t *p_d)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t ignored16 = 0, x = 0;
	uint8_t t1 = 0;

	x = loaded_table_021BBE_ADDRESS;
	t1 = io_read8(VIDEO_18F1);
	b = (uint32_t)t1 << 1;
	switch ((int8_t)b)
	{
	case 0:
		d = sub_0209CA();
		break;
	case 2:
		d |= b;
		sub_0209D6(&x, &y, &d, &carry);
		break;
	case 4:
		d |= b;
		sub_0209F7();
		break;
	case -62:
		d = b;
		sub_020020(&ignored16, &y, &d, &carry);
		break;
	case -60:
		sub_02002A(&ignored16, &y, &d, &carry);
		break;
	case -58:
		sub_0200B4(&ignored16, &y, &d, &carry);
		break;
	case -56:
		d = b;
		sub_020107(&ignored16, &y, &d, &carry);
		break;
	case -54:
		sub_02016F(&ignored16, &y, &d, &carry);
		break;
	case -52:
		d = b;
		sub_0201F2(&ignored16, &y, &d, &carry);
		break;
	case -50:
		sub_020116(&ignored16, &y, &d, &carry);
		break;
	case -48:
		sub_02013F(&ignored16, &y, &d, &carry);
		break;
	case -46:
		sub_020182(&d, &carry);
		break;
	case -44:
		sub_02018D(&ignored16, &y, &d, &carry);
		break;
	case -42:
		sub_0201FC(&d, &carry);
		break;
	case -40:
		d = b;
		sub_020207(&ignored16, &y, &d, &carry);
		break;
	case -38:
		sub_020264(&ignored16, &y, &d, &carry);
		break;
	case -36:
		d = b;
		sub_0202DD(&ignored16, &y, &d, &carry);
		break;
	case -34:
		d |= b;
		sub_020316(&d, &carry);
		break;
	case -32:
		d = b;
		sub_020519(&x, &y, &d, &carry);
		break;
	case -30:
		d = b;
		sub_0205C0(&x, &y, &d, &carry);
		break;
	case -28:
		sub_020522(x, &y, &d);
		break;
	case -26:
		sub_020553(x, &y, &d);
		break;
	case -24:
		sub_02056B(x, &y, &d, &carry);
		break;
	case -22:
		sub_020584(x, &y, &d, &carry);
		break;
	case -20:
		sub_0205D3(x, &d, &carry);
		break;
	case -18:
		sub_020600(x, &d, &carry);
		break;
	case -16:
		d |= b;
		sub_02061F(x);
		break;
	case -14:
		d |= b;
		sub_020628();
		break;
	case -12:
		sub_020922(y, &d, &carry);
		break;
	case -10:
		sub_020937(&ignored16, &d, &carry);
		break;
	case -8:
	case -4:
		d |= b;
		carry = sub_020975();
		break;
	case -6:
		sub_02097E(x, &y, &d, &carry);
		break;
	case -2:
		sub_020996(x, &y, &d, &carry);
		break;
	}
	*p_y = y;
	*p_d = d;
}

uint16_t sub_0209CA(void)
{
	uint16_t d = 0;
	uint8_t t1 = 0;

	d = VIDEO_00C0;
	io_write16(VIDEO_18EF, VIDEO_00C0);
	t1 = io_read8(VIDEO_18F1);
	io_write8(VIDEO_18F1, t1 + 1u);
	return d;
}

void sub_0209D6(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t a = 0;
	uint16_t d_2 = 0;
	uint8_t stack = 0;
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0;

	a = (uint8_t)(d >> 8);
	t1 = io_read16(VIDEO_18EF);
	carry = t1 == 0u;
	io_write16(VIDEO_18EF, t1 - 1u);
	if (t1 == 1u)
	{
		stack = a;
		d_2 = (uint32_t)(uint8_t)(a + 0x1Au) << 8;
		sub_0207C7(x, &y, &d_2, &carry);
		mem_write8(y, 0x80u);
		x = bonus_intro_sounds_ADDRESS;
		t2 = bonus_intro_sounds[(int8_t)((uint8_t)((uint32_t)stack << 1)) / 2];
		d = t2;
		a = (uint8_t)(t2 >> 8);
		carry = sub_078680(d);
		t3 = io_read8(VIDEO_18F1);
		io_write8(VIDEO_18F1, t3 + 1u);
	}
	d_2 = (d & 0xFFu) | ((uint32_t)a << 8);
	*p_x = x;
	*p_y = y;
	*p_d = d_2;
	*p_carry = carry;
}

void sub_0209F7(void)
{
}

void sub_0209F8(uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t a = 0;
	uint16_t d_2 = 0, u = 0, x = 0;
	uint8_t stack = 0, stack_6 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	stack = d >> 8;
	x = unk_4F80_ADDRESS;
	u = 0x49D2u;
	stack_6 = 4u;
	do
	{
		t1 = mem_read8(x + VIDEO_002F);
		a = t1;
		carry = a < 3u;
		if (a == 3u)
		{
			t2 = mem_read8(x + 0x45u);
			a = t2;
			carry = a == 0u;
			if (a == 1u)
			{
				t3 = mem_read8(x + 0x48u);
				if (t3 == 0u)
				{
					a = mem_read8(u) + 0x14u;
					carry = a < 0x28u;
					if (a > 0x28u)
						a = 0x28u;
					mem_write8(u, a);
				}
			}
		}
		x += 0xC0u;
		u += 8u;
		t4 = stack_6;
		stack_6 = t4 - 1u;
	} while (t4 != 1u);
	d_2 = (uint32_t)stack << 8;
	*p_d = (*p_d & 0xFFu) | d_2;
	*p_carry = carry;
}

void sub_020A3C(void)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	d = 0x8700u;
	carry = sub_078680(d);
	t1 = io_read8(VIDEO_1840);
	io_write8(VIDEO_1840, t1 + 1u);
}

void sub_020A47(uint16_t y)
{
	uint32_t negative = 0, carry = 0;
	uint8_t a = 0;
	uint16_t d = 0, ignored16 = 0, u = 0, x = 0;
	uint8_t stack = 0, stack_10002 = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	d = 0x100u;
	sub_0209C0(&y, &d);
	sub_020919(&ignored16, &y, &d, &carry);
	if (carry == 0u)
		return;
	sub_0209AE();
	sub_02128C(&d, &negative);
	a = (uint8_t)(d >> 8);
	if (negative)
	{
		t1 = io_read8(VIDEO_1840);
		io_write8(VIDEO_1840, t1 + 1u);
		return;
	}
	unk_48F0 = a;
	unk_48F1 = 0xFu;
	u = unk_4A40_ADDRESS;
	sub_020B37(u);
	unk_4A70 = 1u;
	t2 = 0xA8u - unk_4A4C;
	stack = t2 >> 8;
	stack_10002 = t2;
	x = ((uint32_t)stack << 8) | stack_10002;
	d = 0xCu;
	sub_020A90(x, u, d);
	x = 0x28u;
	d = 0x16u;
	sub_020A90(x, u, d);
	mem_write8(u + 9u, 0x30u);
	t1 = io_read8(VIDEO_1840);
	io_write8(VIDEO_1840, t1 + 1u);
}

void sub_020A90(uint16_t x, uint16_t u, uint16_t d)
{
	uint16_t t1 = 0, t2 = 0;

	unk_48F8 = x;
	u += d;
	mem_write16(u, mem_read16(u) + unk_48F8);
	t1 = mem_read16(u + 0x60u);
	mem_write16(u + 0x60u, t1 + unk_48F8);
	t2 = mem_read16(u + 0x840u);
	mem_write16(u + 0x840u, t2 + unk_48F8);
}

void sub_020AB4(uint16_t y)
{
	uint32_t carry = 0;
	uint16_t d = 0, u = 0, x = 0;

	y = sub_020967(y);
	d = 0x100u;
	sub_0209C0(&y, &d);
	unk_48F0 = 0u;
	u = unk_4A40_ADDRESS;
	x = unk_49D0_ADDRESS;
	d = (uint32_t)unk_4842 << 8;
	sub_020C8E(x, u, &d, &carry);
}

void sub_020AE3(void)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, u = 0;

	u = unk_4A40_ADDRESS;
	unk_48F0 = 0u;
	unk_48F1 = unk_4850;
	do
	{
		sub_020B37(u);
		u += 0xC0u;
		unk_48F0++;
	} while (unk_48F0 != 4u);
	unk_49D3 = 0u;
	unk_49DB = 0u;
	unk_49E3 = 0u;
	unk_49EB = 0u;
	sub_020C3F(&ignored16, &carry);
	io_write16(VIDEO_1840, 0x464u);
	sub_020ED3();
	unk_487A = 0x10u;
	unk_48F8 = 0xE0u;
	unk_48FA = 0xB8u;
	sub_020EA8();
	sub_020685();
	sub_020C2A();
}

void sub_020B37(uint16_t u)
{
	uint8_t a = 0;
	uint16_t x = 0;
	uint8_t t1 = 0;

	mem_write8(u, 0x80u);
	mem_write8(u + 0x60u, 0x80u);
	mem_write8(u + 0x840u, 0x80u);
	a = unk_48F0 + 0xAu;
	mem_write8(u + 4u, a);
	mem_write8(u + 0x64u, a);
	mem_write8(u + 5u, 0x88u);
	mem_write8(u + 0x65u, 0x91u);
	x = sub_020E66();
	mem_write16(u + 0xCu, x);
	mem_write8(u + 0x12u, 0xC0u);
	unk_48F2 = 0u;
	x = sub_020E80(u);
	mem_write8(u + 0x844u, 0xEu);
	mem_write16(u + 0x84Cu, x + bonus_2_side_object_x_offsets[(int8_t)unk_48F0]);
	mem_write8(u + 0x852u, 0x90u);
	mem_write8(u + 0x857u, 0x30u);
	a = 0x88u;
	t1 = unk_48F1;
	unk_48F1 = t1 >> 1;
	if ((t1 & 1u) == 0u)
		a = 0xC5u;
	mem_write8(u + 0x845u, a);
	mem_write8(u + 0x883u, a);
}

void sub_020B9B(void)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0;
	uint8_t t1 = 0;

	sub_020C3F(&ignored16, &carry);
	t1 = io_read8(VIDEO_1841);
	io_write8(VIDEO_1841, t1 - 1u);
	if (t1 != 1u)
	{
		sub_020C2A();
		return;
	}
	d = 0x8A00u;
	carry = sub_078680(d);
	io_write8(VIDEO_1840, 5u);
	sub_020C2A();
}

void sub_020BB6(void)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0;

	sub_020F01();
	sub_020C3F(&ignored16, &carry);
	if (carry)
	{
		d = 0x8800u;
		carry = sub_078680(d);
		io_write16(VIDEO_1840, 0x628u);
		sub_020C2A();
		return;
	}
	carry = sub_02064A();
	if (carry)
	{
		d = 0x8800u;
		carry = sub_078680(d);
		io_write16(VIDEO_1840, 0x628u);
		sub_020C2A();
		return;
	}
	unk_48F8 = 0xE0u;
	unk_48FA = 0xB8u;
	sub_020685();
	sub_020C2A();
}

void sub_020BE3(void)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = io_read8(VIDEO_1841);
	if (t1 != 0u)
	{
		t2 = io_read8(VIDEO_1841);
		io_write8(VIDEO_1841, t2 - 1u);
	}
	sub_020C3F(&ignored16, &carry);
	sub_020F39(&ignored16_2, &ignored16_3, &ignored16, &carry);
	if (carry)
	{
		t3 = io_read8(VIDEO_1841);
		io_write16(VIDEO_1840, 0x70Au);
		unk_4A70 = 6u;
		unk_4B30 = 6u;
		unk_4BF0 = 6u;
		unk_4CB0 = 6u;
	}
	sub_020C2A();
}

void sub_020C14(void)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	sub_020C3F(&d, &carry);
	t1 = io_read8(VIDEO_1841);
	io_write8(VIDEO_1841, t1 - 1u);
	if (t1 != 1u)
	{
		sub_020C2A();
		return;
	}
	sub_0209F8(&d, &carry);
	unk_4804++;
	unk_4805 = d;
	sub_020C2A();
}

void sub_020C2A(void)
{
	unk_48F8 = 0x78u;
	unk_48FA = 0xA8u;
	unk_48F0 = 0x90u;
	sub_021189(0u);
}

void sub_020C3F(uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, u = 0, x = 0;

	unk_48F0 = 0u;
	u = unk_4A40_ADDRESS;
	x = unk_49D0_ADDRESS;
	d = ((uint32_t)unk_4842 << 8) | 1u;
	sub_020C8E(x, u, &d, &carry);
	a = (uint8_t)(d >> 8);
	b = (uint8_t)d;
	if (carry == 0u)
	{
		unk_48F0 = 1u;
		u = unk_4B00_ADDRESS;
		x = unk_49D8_ADDRESS;
		d = ((uint32_t)unk_4846 << 8) | 2u;
		sub_020C8E(x, u, &d, &carry);
		a = (uint8_t)(d >> 8);
		b = (uint8_t)d;
		if (carry == 0u)
		{
			unk_48F0 = 2u;
			u = unk_4BC0_ADDRESS;
			x = unk_49E0_ADDRESS;
			d = ((uint32_t)unk_484A << 8) | 4u;
			sub_020C8E(x, u, &d, &carry);
			a = (uint8_t)(d >> 8);
			b = (uint8_t)d;
			if (carry == 0u)
			{
				unk_48F0 = 3u;
				u = unk_4C80_ADDRESS;
				x = unk_49E8_ADDRESS;
				d = ((uint32_t)unk_484E << 8) | 8u;
				sub_020C8E(x, u, &d, &carry);
				a = (uint8_t)(d >> 8);
				b = (uint8_t)d;
			}
		}
	}
	d = ((uint32_t)a << 8) | b;
	*p_d = d;
	*p_carry = carry;
}

void sub_020C8E(uint16_t x, uint16_t u, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	unk_48F2 = 0u;
	mem_write8(u + VIDEO_002F, d >> 8);
	unk_48F1 = (uint8_t)d;
	unk_48F8 = x;
	t1 = mem_read8(u + 0x56Fu);
	if (t1 != 3u)
	{
		mem_write8(u + VIDEO_002F, 0u);
		t2 = mem_read8(u + 4u);
		if ((int8_t)(((t2 - 0xAu) ^ unk_4858) & 0xFu) < 2)
			mem_write8(u + VIDEO_002F, 0x10u);
	}
	t3 = mem_read8(u + 0x846u);
	if ((t3 & 2u) != 0u)
	{
		d = unk_4900_ADDRESS;
		carry = sub_078680(d);
	}
	t4 = mem_read8(u + 0x30u);
	switch ((int8_t)(uint8_t)((uint32_t)t4 << 1))
	{
	case 0:
		sub_020CD1(u, &d, &carry);
		break;
	case 2:
		sub_020DCB(u, &d, &carry);
		break;
	case 4:
	case 6:
	case 8:
	case 10:
		sub_020E64(&d, &carry);
		break;
	case 12:
		sub_020CE0(u, &d, &carry);
		break;
	case 14:
		sub_020D03(u, &d, &carry);
		break;
	case 16:
		sub_020D14(u, &d, &carry);
		break;
	case 18:
		sub_020D36(u, &d, &carry);
		break;
	case 20:
		sub_020D62(u, &d, &carry);
		break;
	case 22:
		sub_020D90(u, &d, &carry);
		break;
	}
	*p_d = d;
	*p_carry = carry;
}

void sub_020CD1(uint16_t u, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d = 0;
	uint8_t t1 = 0;

	t1 = io_read8(VIDEO_1840);
	if (t1 == 5u)
		mem_write8(u + 0x30u, 1u);
	carry = 0u;
	d = 0u;
	*p_d = (*p_d & 0xFFu) | d;
	*p_carry = carry;
}

void sub_020CE0(uint16_t u, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(u + 0x30u);
	mem_write8(u + 0x30u, t1 + 1u);
	mem_write8(u + 1u, 0x5Cu);
	t2 = mem_read8(u + 0x585u);
	if (t2 != 1u)
		sub_020DCB(u, &d, &carry);
	else
	{
		mem_write8(u + 5u, 0x8Au);
		t3 = mem_read8(u + 0x883u);
		mem_write8(u + 0x845u, t3 + 2u);
		sub_020DCB(u, &d, &carry);
	}
	*p_d = d;
	*p_carry = carry;
}

void sub_020D03(uint16_t u, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(u + 4u);
	if ((uint8_t)(unk_4858 + t1) != 0u)
		sub_020E64(&d, &carry);
	else
	{
		mem_write8(u + 0x65u, 0x8Bu);
		sub_020E64(&d, &carry);
	}
	*p_d = (*p_d & 0xFFu) | d;
	*p_carry = carry;
}

void sub_020D14(uint16_t u, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d = 0, x = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = mem_read8(u + VIDEO_0031);
	mem_write8(u + VIDEO_0031, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(u + 0x30u, 1u);
		x = sub_020E66();
		mem_write16(u + 0xCu, x);
		t2 = mem_read8(u + 0x883u);
		mem_write8(u + 0x845u, t2);
		sub_020DCB(u, &d, &carry);
	}
	else
	{
		x = sub_020E66();
		t3 = mem_read8(u + VIDEO_0031);
		mem_write16(u + 0xCu, x + bonus_2_shake_x_offsets[t3 >> 1]);
		t4 = mem_read8(u + 5u);
		mem_write8(u + 5u, t4 | 0x80u);
		sub_020DCB(u, &d, &carry);
	}
	*p_d = d;
	*p_carry = carry;
}

void sub_020D36(uint16_t u, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, x = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = mem_read8(u + VIDEO_0031);
	mem_write8(u + VIDEO_0031, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(u + 0x30u, 1u);
		x = sub_020E66();
		mem_write16(u + 0xCu, x);
		t2 = mem_read8(u + 0x883u);
		mem_write8(u + 0x845u, t2);
		sub_020DCB(u, &d, &carry);
	}
	else
	{
		t3 = mem_read8(u + 1u);
		if ((int8_t)t3 <= 0x30)
			sub_020DCB(u, &d, &carry);
		else
		{
			mem_write8(u, 0x90u);
			mem_write8(u + 0x60u, 0x90u);
			t4 = mem_read8(u + VIDEO_0031);
			a = t4 >> 1;
			b = bonus_2_squash_zooms_y[a];
			a = bonus_2_squash_zooms_x[a];
			mem_write16(u + 0xAu, ((uint32_t)a << 8) | b);
			mem_write16(u + 0x6Au, ((uint32_t)a << 8) | b);
			sub_020DCB(u, &d, &carry);
		}
	}
	*p_d = d;
	*p_carry = carry;
}

void sub_020D62(uint16_t u, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t a = 0;
	uint16_t d = 0, x = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = mem_read8(u + VIDEO_0031);
	mem_write8(u + VIDEO_0031, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(u + 0x30u, 1u);
		x = sub_020E66();
		mem_write16(u + 0xCu, x);
		t2 = mem_read8(u + 0x883u);
		mem_write8(u + 0x845u, t2);
		sub_020DCB(u, &d, &carry);
	}
	else
	{
		t3 = mem_read8(u + 1u);
		if ((int8_t)t3 <= 0x48)
			sub_020DCB(u, &d, &carry);
		else
		{
			t4 = mem_read8(u + VIDEO_0031);
			a = t4 >> 1;
			unk_48F2 = TABLE8(bonus_2_level_object_x_moves, (uint16_t)(a + (int8_t)((((uint32_t)unk_48F0 << 1) << 1) << 1)));
			if (a != 7u)
				sub_020DCB(u, &d, &carry);
			else
			{
				mem_write8(u + 5u, 0x89u);
				sub_020DCB(u, &d, &carry);
			}
		}
	}
	*p_d = d;
	*p_carry = carry;
}

void sub_020D90(uint16_t u, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d = 0, x = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	t1 = mem_read8(u + VIDEO_0031);
	mem_write8(u + VIDEO_0031, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(u + 0x30u, 1u);
		x = sub_020E66();
		mem_write16(u + 0xCu, x);
		t2 = mem_read8(u + 0x883u);
		mem_write8(u + 0x845u, t2);
		sub_020DCB(u, &d, &carry);
	}
	else
	{
		t3 = mem_read8(u + 1u);
		if ((int8_t)t3 <= 0x18)
			sub_020DCB(u, &d, &carry);
		else
		{
			t4 = mem_read8(u + VIDEO_0031);
			mem_write16(u + 0x11u, VIDEO_00C0 + (int8_t)((((t4 & 2u) << 1) << 1) - 4u));
			t5 = mem_read8(u + 5u);
			mem_write8(u + 5u, t5 | 0x80u);
			sub_020DCB(u, &d, &carry);
		}
	}
	*p_d = d;
	*p_carry = carry;
}

void sub_020DCB(uint16_t u, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t a = 0, b = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t5 = 0, t6 = 0, t9 = 0, t12 = 0, t13 = 0, t16 = 0, t17 = 0;
	uint16_t t3 = 0, t4 = 0, t7 = 0, t8 = 0, t10 = 0, t11 = 0;
	uint32_t t14 = 0, t15 = 0;

	sub_020E80(u);
	t1 = mem_read8(u + 1u);
	a = (t1 >> 1) >> 1;
	b = a;
	mem_write8(u + 0x65u, ((a >> 1) >> 1) - 0x6Fu);
	if (b <= 0x14u)
	{
		t2 = io_read8(VIDEO_1840);
		a = t2;
		if (a == 2u || a == 5u)
		{
			t3 = mem_read16(u + 1u);
			t4 = t3 - 8u;
			a = (uint8_t)(t4 >> 8);
			b = (uint8_t)t4;
			if ((int16_t)t4 < 0)
			{
				a = 0u;
				b = 0u;
			}
			mem_write16(u + 1u, ((uint32_t)a << 8) | b);
			t5 = mem_read8(u + VIDEO_002F);
			if ((t5 & 0x30u) == 0u)
			{
				t6 = mem_read8(u + 0x3Fu);
				if (t6 == 0xFu)
				{
					t7 = mem_read16(u + 1u);
					t8 = t7 - 0xB0u;
					a = (uint8_t)(t8 >> 8);
					b = (uint8_t)t8;
					if ((int16_t)t8 < 0)
					{
						a = 0u;
						b = 0u;
						mem_write8(u + 0x3Fu, 0u);
					}
					mem_write16(u + 1u, ((uint32_t)a << 8) | b);
					d = b;
					sub_020E64(&d, &carry);
				}
				else
				{
					t9 = mem_read8(u + 0x3Fu);
					mem_write8(u + 0x3Fu, t9 + 1u);
					d = b;
					sub_020E64(&d, &carry);
				}
			}
			else
			{
				t10 = mem_read16(u + 1u);
				t11 = t10 + 0x180u;
				b = (uint8_t)t11;
				mem_write16(u + 1u, ((uint32_t)(t11 >> 8) << 8) | b);
				mem_write8(u + 0x3Fu, 0u);
				t12 = mem_read8(u + 0x30u);
				a = t12;
				carry = a < 3u;
				if ((int8_t)a < 3)
				{
					t13 = b & 3u;
					b = t13;
					if (t13 == 0u)
					{
						a = unk_4858;
						t14 = ((uint32_t)a << 1) | carry;
						carry = a >> 7;
						a = (uint8_t)t14;
						t15 = ((uint32_t)a << 1) | carry;
						carry = a >> 7;
						b = 0x10u;
						mem_write16(u + 0x30u, ((uint32_t)(uint8_t)(((((uint32_t)(uint8_t)t15 << 1) | carry) & 3u) + 8u) << 8) | 0x10u);
						mem_write8(u + 5u, 0x88u);
						t16 = mem_read8(u + 0x883u);
						mem_write8(u + 0x845u, t16 + 1u);
						mem_write16(u + 0x11u, VIDEO_00C0);
					}
				}
				d = b;
				sub_020E64(&d, &carry);
			}
		}
		else
		{
			d = b;
			sub_020E64(&d, &carry);
		}
	}
	else
	{
		t17 = mem_read8(u + 0x30u);
		a = t17;
		if ((int8_t)a < 8)
		{
			b = 7u;
			mem_write8(u + 0x30u, 7u);
		}
		carry = 1u;
		d = ((uint32_t)(uint8_t)~a << 8) | b;
	}
	*p_d = d;
	*p_carry = carry;
}

void sub_020E64(uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d = 0;

	carry = 0u;
	d = 0u;
	*p_d = (*p_d & 0xFFu) | d;
	*p_carry = carry;
}

uint16_t sub_020E66(void)
{
	uint16_t x = 0;
	uint8_t stack = 0, stack_10002 = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	t1 = io_read8(VIDEO_1840);
	if (t1 != 2u)
	{
		t2 = bonus_2_player_x[(int8_t)((uint8_t)((uint32_t)unk_48F0 << 1)) / 2];
		stack = t2 >> 8;
		stack_10002 = t2;
		x = ((uint32_t)stack << 8) | stack_10002;
		return x;
	}
	x = 0xA8u;
	return x;
}

uint16_t sub_020E80(uint16_t u)
{
	uint16_t x = 0;
	uint8_t t1 = 0;
	uint16_t dx = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = mem_read8(u + 4u);
	dx = (((uint32_t)(uint8_t)XZ_OFFSET(bonus_2_level_object_offsets_ADDRESS + (int8_t)((uint32_t)t1 << 1))->dx << 8u) | (uint8_t)XZ_OFFSET(bonus_2_level_object_offsets_ADDRESS + (int8_t)((uint32_t)t1 << 1))->dz);
	t2 = mem_read16(u + 0xCu);
	x = t2 + (int8_t)(dx >> 8) + (int8_t)unk_48F2;
	mem_write16(u + 0x6Cu, x);
	t3 = mem_read16(u + 0x11u);
	mem_write16(u + 0x71u, t3 - 2u);
	t4 = mem_read16(u + 0x16u);
	mem_write16(u + 0x76u, t4 + (int8_t)dx);
	return x;
}

void sub_020EA8(void)
{
}

void unused_020EA9(void)
{
	unk_55E0 = 0x80u;
	unk_55EC = unk_48F8 - 0x28u;
	unk_55F1 = VIDEO_00A0;
	unk_55F6 = unk_48FA;
	unk_55E4 = 0xE8Fu;
}

void unused_020ECD(void)
{
}

void unreached_020ECE(void)
{
	unk_55E0 = 0u;
}

void sub_020ED3(void)
{
	uint32_t carry = 0;
	uint16_t d = 0, u = 0;

	u = unk_5580_ADDRESS;
	if ((unk_5580 & 0x80u) == 0u)
	{
		unk_5580 = 0x80u;
		unk_558C = 0xE8u;
		unk_5591 = 0x11Cu;
		AT16(unk_5581, -1) = VIDEO_00A0;
		unk_5584 = 0xE86u;
		d = 0x3F32u;
		carry = sub_078680(d);
	}
}

void sub_020F01(void)
{
	uint32_t carry = 0;
	uint16_t d = 0, u = 0;
	uint16_t t1 = 0, t2 = 0;

	u = unk_5580_ADDRESS;
	t1 = AT16(unk_5581, -1);
	d = t1;
	if (t1 == 0u)
		return;
	if (d == VIDEO_00A0)
	{
		d = 0x3F33u;
		carry = sub_078680(d);
	}
	t2 = AT16(unk_5581, -1);
	AT16(unk_5581, -1) = t2 - 1u;
	if (t2 != 1u)
	{
		unk_558C = 0xE8u;
		unk_5591 = 0x11Cu;
		unk_5584 = 0xE87u;
		return;
	}
	unk_5580 = 0u;
	unk_558C = 0u;
	unk_5591 = 0u;
}

void sub_020F39(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint16_t x = 0;
	uint8_t t1 = 0;

	t1 = io_read8(VIDEO_1842);
	x = loaded_table_021D8D_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_020F43(&x, &y, &d, &carry);
		break;
	case 2:
		sub_020F7F(&x, &y, &d, &carry);
		break;
	case 4:
		sub_020F87(&x, &y, &d, &carry);
		break;
	case 6:
		sub_020F99(&x, &y, &d, &carry);
		break;
	case 8:
		sub_020FAB(&x, &y, &d, &carry);
		break;
	case 10:
		sub_020FBD(&x, &y, &d, &carry);
		break;
	case 12:
		sub_020FCC(&x, &y, &d, &carry);
		break;
	case 14:
		sub_021017(&x, &y, &d, &carry);
		break;
	}
	*p_x = x;
	*p_y = y;
	*p_d = d;
	*p_carry = carry;
}

void sub_020F43(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = *p_carry;
	uint16_t d = 0, u = 0, x = 0;
	uint8_t t1 = 0, t2 = 0;

	io_write8(VIDEO_1842, 1u);
	io_write8(VIDEO_1844, 0xFFu);
	unk_48F0 = 4u;
	u = unk_4F80_ADDRESS;
	x = 0x2310u;
	unk_48F8 = 0x2310u;
	do
	{
		mem_write16(u + 0x30u, 0u);
		mem_write16(u + 0x40u, x);
		x += 9u;
		mem_write8(u + 0x42u, 0xFFu);
		u += 0xC0u;
		t1 = unk_48F0;
		unk_48F0 = t1 - 1u;
	} while (t1 != 1u);
	io_write8(VIDEO_1846, 1u);
	t2 = io_read8(VIDEO_1845);
	io_write8(VIDEO_1845, 0u);
	*p_x = x;
	*p_y = y;
	*p_d = d;
	sub_020F7F(p_x, p_y, p_d, &carry);
	*p_carry = carry;
}

void sub_020F7F(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = *p_carry;
	uint16_t d = 0, x = 0;

	x = 0xE8Bu;
	sub_0210A5(&x, &y, &d);
	*p_x = x;
	*p_y = y;
	*p_d = d;
	sub_020FD9(p_x, p_y, p_d, &carry);
	*p_carry = carry;
}

void sub_020F87(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t t1 = 0, t2 = 0;

	t1 = io_read8(0x1843u);
	io_write8(0x1843u, t1 - 1u);
	if (t1 != 1u)
		sub_020FD9(&x, &y, &d, &carry);
	else
	{
		t2 = io_read8(0x1843u);
		io_write8(0x1843u, t2 + 1u);
		x = 0xE8Cu;
		sub_0210A5(&x, &y, &d);
		sub_020FD9(&x, &y, &d, &carry);
	}
	*p_x = x;
	*p_y = y;
	*p_d = d;
	*p_carry = carry;
}

void sub_020F99(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t t1 = 0, t2 = 0;

	t1 = io_read8(0x1843u);
	io_write8(0x1843u, t1 - 1u);
	if (t1 != 1u)
		sub_020FD9(&x, &y, &d, &carry);
	else
	{
		t2 = io_read8(0x1843u);
		io_write8(0x1843u, t2 + 1u);
		x = 0xE8Du;
		sub_0210A5(&x, &y, &d);
		sub_020FD9(&x, &y, &d, &carry);
	}
	*p_x = x;
	*p_y = y;
	*p_d = d;
	*p_carry = carry;
}

void sub_020FAB(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t t1 = 0, t2 = 0;

	t1 = io_read8(0x1843u);
	io_write8(0x1843u, t1 - 1u);
	if (t1 != 1u)
		sub_020FD9(&x, &y, &d, &carry);
	else
	{
		t2 = io_read8(0x1843u);
		io_write8(0x1843u, t2 + 1u);
		x = 0xE8Eu;
		sub_0210A5(&x, &y, &d);
		sub_020FD9(&x, &y, &d, &carry);
	}
	*p_x = x;
	*p_y = y;
	*p_d = d;
	*p_carry = carry;
}

void sub_020FBD(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t t1 = 0;

	t1 = io_read8(0x1843u);
	io_write8(0x1843u, t1 - 1u);
	if (t1 != 1u)
		sub_020FD9(&x, &y, &d, &carry);
	else
	{
		d = 0x63Cu;
		io_write16(VIDEO_1842, 0x63Cu);
		sub_020FD9(&x, &y, &d, &carry);
	}
	*p_x = x;
	*p_y = y;
	*p_d = d;
	*p_carry = carry;
}

void sub_020FCC(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t t1 = 0;

	t1 = io_read8(0x1843u);
	io_write8(0x1843u, t1 - 1u);
	if (t1 != 1u)
		sub_020FD9(&x, &y, &d, &carry);
	else
	{
		d = 0x704u;
		io_write16(VIDEO_1842, 0x704u);
		sub_020FD9(&x, &y, &d, &carry);
	}
	*p_x = x;
	*p_y = y;
	*p_d = d;
	*p_carry = carry;
}

void sub_020FD9(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t a = 0;
	uint16_t u = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	unk_48F1 = 4u;
	u = unk_4F80_ADDRESS;
	do
	{
		t1 = mem_read8(u + VIDEO_0031);
		if (t1 != 0u)
		{
			t2 = mem_read8(u + VIDEO_0031);
			mem_write8(u + VIDEO_0031, t2 - 1u);
			if (t2 == 1u)
				mem_write8(u + 0x42u, 4u);
		}
		unk_48F0 = 0u;
		sub_021213(u, &y, &d);
		t3 = mem_read8(u + 0x47u);
		a = t3;
		if (t3 != 0u)
		{
			t4 = mem_read8(u + 0x47u);
			mem_write8(u + 0x47u, t4 - 1u);
			x = bonus_results_hop_speeds_ADDRESS;
			a = bonus_results_hop_speeds[(int8_t)a];
			mem_write8(u + 0x19u, a);
			mem_write8(u + 0x79u, a);
		}
		u += 0xC0u;
		t5 = unk_48F1;
		unk_48F1 = t5 - 1u;
	} while (t5 != 1u);
	sub_021081();
	carry = 0u;
	d &= 0xFFu;
	*p_x = x;
	*p_y = y;
	*p_d = d;
	*p_carry = carry;
}

void sub_021017(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint8_t d = (uint8_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t a = 0, b = 0;
	uint16_t d_2 = 0, u = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;

	b = (uint8_t)d;
	t1 = io_read8(0x1843u);
	io_write8(0x1843u, t1 - 1u);
	if (t1 != 1u)
	{
		carry = 0u;
		d_2 = b;
	}
	else
	{
		io_write8(0x1843u, 4u);
		unk_48F0 = 4u;
		u = unk_4F80_ADDRESS;
		unk_48F8 = 0x2411u;
		unk_48F1 = 0u;
		do
		{
			t2 = mem_read8(u + 0x46u);
			a = t2 + 1u;
			if (a == mem_read8(u - 0x53Fu))
			{
				unk_48F1++;
				t3 = mem_read8(u + 0x2Eu);
				if (t3 == 0u)
				{
					d_2 = 0xA01u;
					carry = sub_078680(d_2);
					t4 = mem_read8(u + 0x2Eu);
					mem_write8(u + 0x2Eu, t4 + 1u);
				}
			}
			else
			{
				mem_write8(u + 0x46u, a);
				d_2 = (uint32_t)a << 8;
				sub_02125F(&y, &d_2);
				t5 = mem_read8(u + VIDEO_002F);
			}
			x = unk_48F8 + 9u;
			unk_48F8 = x;
			u += 0xC0u;
			t6 = unk_48F0;
			unk_48F0 = t6 - 1u;
		} while (t6 != 1u);
		d_2 = 0x801u;
		carry = sub_078680(d_2);
		b = unk_48F1;
		sub_021081();
		if (b == 4u)
		{
			io_write16(VIDEO_1842, 0u);
			carry = 1u;
			d_2 = 0xFF00u;
		}
		else
		{
			carry = 0u;
			d_2 = b;
		}
	}
	*p_x = x;
	*p_y = y;
	*p_d = d_2;
	*p_carry = carry;
}

void sub_021081(void)
{
	unk_48F0 = unk_4FC5;
	unk_48F1 = unk_5085;
	unk_48F2 = unk_5145;
	unk_48F3 = unk_5205;
}

void sub_0210A5(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint8_t a = 0, b = 0, d_2 = 0;
	uint16_t d = 0, u = 0, y_2 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0;

	unk_48F8 = x;
	unk_48F0 = 0u;
	unk_48F1 = 0u;
	a = 4u;
	u = unk_4A40_ADDRESS;
	do
	{
		t1 = mem_read8(u + 1u);
		b = t1;
		t2 = io_read8(VIDEO_1844);
		if (b < t2 && unk_48F1 <= b)
		{
			unk_48F0++;
			unk_48F1 = b;
		}
		u += 0xC0u;
		t3 = a;
		a = t3 - 1u;
	} while (t3 != 1u);
	if (unk_48F0 != 0u)
	{
		io_write8(VIDEO_1844, unk_48F1);
		unk_48F0 = 0u;
		unk_48F1 = 4u;
		u = unk_4F80_ADDRESS;
		x = 0x78u;
		do
		{
			t4 = mem_read8(u + VIDEO_002F);
			b = t4;
			unk_48F0++;
			t5 = io_read8(VIDEO_1844);
			if (mem_read8(u - 0x53Fu) == t5)
			{
				mem_write8(u, 0x80u);
				mem_write8(u + 0x60u, 0x80u);
				mem_write16(u + 0xCu, x);
				mem_write16(u + 0x6Cu, x);
				mem_write16(u + 0x11u, 0x60u);
				mem_write16(u + 0x71u, 0x60u);
				mem_write16(u + 0x16u, 0xD0u);
				mem_write16(u + 0x76u, 0xD0u);
				y_2 = unk_48F8;
				mem_write16(u + 4u, y_2);
				mem_write16(u + 0x64u, y_2 + 5u);
				mem_write8(u + 0x47u, 0x1Fu);
				mem_write8(u + VIDEO_0031, 0xAu);
				t6 = io_read8(VIDEO_1846);
				a = t6;
				if (b == 3u)
				{
					y = loaded_table_021DCF_ADDRESS;
					if (mem_read8(u - 0x53Fu) == 0u)
					{
						y = loaded_table_021DE3_ADDRESS;
						mem_write8(u + 0x48u, 1u);
						a = 4u;
					}
				}
				else
					y = loaded_table_021DBC_ADDRESS;
				mem_write16(u + 0x43u, y);
				mem_write8(u + 0x45u, a);
				d_2 = b;
				x = sub_0212A9(x, u, d_2);
				mem_write8(u - 0x53Fu, mem_read8(u - 0x53Fu) + 1u);
				t7 = io_read8(VIDEO_1845);
				io_write8(VIDEO_1845, t7 + 1u);
			}
			u += 0xC0u;
			x += 0x48u;
			t8 = unk_48F1;
			unk_48F1 = t8 - 1u;
		} while (t8 != 1u);
		t9 = io_read8(VIDEO_1845);
		a = t9;
		if (a == unk_48F0)
			a = 5u;
		else
			a++;
		io_write16(VIDEO_1842, ((uint32_t)a << 8) | 0xEu);
		t10 = io_read8(VIDEO_1846);
		io_write8(VIDEO_1846, t10 + 1u);
		d = ((uint32_t)a << 8) | 0xEu;
	}
	else
		d = ((uint32_t)a << 8) | b;
	*p_x = x;
	*p_y = y;
	*p_d = d;
}

uint16_t sub_021189(uint16_t y)
{
	uint8_t a = 0, b = 0;
	uint16_t u = 0;
	uint8_t stack = 0, stack_10002 = 0, saved_unk_48F0 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;
	uint16_t t6 = 0, t7 = 0, t8 = 0;

	unk_48F1 = 0u;
	u = unk_4F80_ADDRESS;
	a = unk_4850;
	do
	{
		stack = a;
		t1 = mem_read8(u + VIDEO_002F);
		b = t1;
		if (t1 != 0u)
		{
			t2 = b;
			b = t2 - 1u;
			if (t2 != 1u)
			{
				if (b != 1u)
				{
					t3 = mem_read8(u + 4u);
					if (t3 != 0xEu)
					{
						t4 = mem_read8(u + 2u);
						mem_write8(u + 2u, t4 - 1u);
						if (t4 == 1u)
							mem_write8(u, 0u);
					}
				}
				else
				{
					t5 = io_read8(VIDEO_1842);
					if (t5 == 0u && (a & 1u) != 0u)
					{
						y = 0xEC2u;
						a = 1u;
						mem_write8(u + VIDEO_002F, a);
						mem_write16(u + 4u, y);
						mem_write8(u, 0x80u);
						t6 = unk_48F1 * 0x48u;
						t7 = t6 + unk_48F8;
						mem_write16(u + 0xCu, t7);
						t8 = unk_48FA;
						mem_write16(u + 0x11u, t8);
						mem_write16(u + 0x16u, 0u);
					}
				}
			}
		}
		else if ((a & 1u) != 0u)
		{
			mem_write8(u + 2u, 0xFFu);
			stack_10002 = unk_48F1 + 0xAu;
			saved_unk_48F0 = unk_48F0;
			y = ((uint32_t)stack_10002 << 8) | saved_unk_48F0;
			a = 3u;
			mem_write8(u + VIDEO_002F, a);
			mem_write16(u + 4u, y);
			mem_write8(u, 0x80u);
			t6 = unk_48F1 * 0x48u;
			t7 = t6 + unk_48F8;
			mem_write16(u + 0xCu, t7);
			t8 = unk_48FA;
			mem_write16(u + 0x11u, t8);
			mem_write16(u + 0x16u, 0u);
		}
		else
		{
			y = 0xEAEu;
			a = 2u;
			mem_write8(u + VIDEO_002F, a);
			mem_write16(u + 4u, y);
			mem_write8(u, 0x80u);
			t6 = unk_48F1 * 0x48u;
			t7 = t6 + unk_48F8;
			mem_write16(u + 0xCu, t7);
			t8 = unk_48FA;
			mem_write16(u + 0x11u, t8);
			mem_write16(u + 0x16u, 0u);
		}
		a = stack >> 1;
		u += 0xC0u;
		unk_48F1++;
	} while (unk_48F1 != 4u);
	return y;
}

void sub_021213(uint16_t u, uint16_t *p_y, uint16_t *p_d)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t d = (uint16_t)*p_d;
	uint8_t a = 0;
	uint16_t d_2 = 0;
	uint8_t t1 = 0, t2 = 0, t5 = 0;
	uint16_t t3 = 0, t4 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0;

	a = (uint8_t)(d >> 8);
	t1 = mem_read8(u + 0x42u);
	if ((int8_t)t1 >= 0)
	{
		t2 = mem_read8(u + 0x42u);
		mem_write8(u + 0x42u, t2 - 1u);
		if (t2 == 1u)
		{
			for (;;)
			{
				t3 = mem_read16(u + 0x43u);
				t4 = t3;
				y = t4 + 1u;
				t5 = mem_read8(t4);
				a = t5;
				if (t5 == 0u)
				{
					a = 0xFFu;
					break;
				}
				if (a == 0x24u)
				{
					t6 = y;
					t7 = mem_read16(t6);
					d = t7;
					mem_write16(u + 0x43u, t6 + 2u);
					t8 = mem_read16(u + 0x40u);
					mem_write16(u + 0x40u, t8 + (((uint32_t)(t7 >> 8) << 8) | (d & 0xFFu)));
					continue;
				}
				mem_write16(u + 0x43u, y);
				if (a == 0x25u)
				{
					a = unk_48F0;
					t9 = mem_read16(u + 0x40u);
					unk_48F8 = t9;
					d = (d & 0xFFu) | ((uint32_t)a << 8);
					sub_02125F(&y, &d);
				}
				else
				{
					t10 = mem_read16(u + 0x40u);
					t11 = t10;
					y = t11 + 1u;
					mem_write8(t11, a - 0x30u);
					mem_write16(u + 0x40u, y);
				}
				a = 4u;
				break;
			}
			mem_write8(u + 0x42u, a);
		}
	}
	d_2 = (d & 0xFFu) | ((uint32_t)a << 8);
	*p_y = y;
	*p_d = d_2;
}

void sub_02125F(uint16_t *p_y, uint16_t *p_d)
{
	uint16_t d = (uint16_t)*p_d;
	uint8_t a = 0, b = 0;
	uint16_t d_2 = 0, y = 0;
	uint16_t t1 = 0, t2 = 0;

	a = (uint8_t)(d >> 8);
	b = (uint8_t)d;
	y = unk_48F8 + 1u;
	if (a < 0xAu)
	{
		io_write8(y, a);
		d_2 = ((uint32_t)a << 8) | b;
	}
	else
	{
		if (a >= 0x64u)
		{
			a -= 0x64u;
			b = 1u;
			if (a >= 0x64u)
			{
				a -= 0x64u;
				b++;
			}
			t1 = y;
			y = t1 + 1u;
			io_write8(t1, b);
		}
		b = 0u;
		while (a >= 0xAu)
		{
			a -= 0xAu;
			b++;
		}
		t2 = y;
		y = t2 + 1u;
		mem_write8(t2, b);
		mem_write8(y, a);
		d_2 = ((uint32_t)a << 8) | b;
	}
	*p_y = y;
	*p_d = d_2;
}

void sub_02128C(uint16_t *p_d, uint32_t *p_negative)
{
	uint32_t negative = *p_negative;
	uint8_t b = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	b = unk_4850;
	unk_48F0 = 4u;
	do
	{
		t1 = b;
		b = t1 >> 1;
		if (t1 & 1u)
			break;
		t2 = unk_48F0;
		unk_48F0 = t2 - 1u;
	} while (t2 != 1u);
	t3 = 4u - unk_48F0;
	negative = t3 >> 7;
	d = ((uint32_t)t3 << 8) | b;
	*p_d = d;
	*p_negative = negative;
}

uint16_t sub_0212A9(uint16_t x, uint16_t u, uint8_t d)
{
	uint8_t a = 0, b = 0;
	uint16_t u_2 = 0, x_2 = 0, y = 0;
	uint8_t stack_9 = 0, stack_1000A = 0, stack_1000B = 0;
	uint16_t stack = 0, stack_B = 0;
	uint8_t t5 = 0, t6 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	stack = x;
	a = 0xB2u;
	if (d != 3u)
		a = 0xF2u;
	stack_9 = a;
	stack_B = x;
	t1 = io_read16(VIDEO_00A0);
	t2 = stack_B - t1;
	t3 = t2 >> 3;
	t4 = t3 + 0x22C0u;
	stack_1000A = t4 >> 8;
	stack_1000B = t4;
	x_2 = ((uint32_t)stack_1000A << 8) | stack_1000B;
	a = stack_9;
	b = 7u;
	if (mem_read8(u - 0x53Fu) == 0u)
		b = 4u;
	stack_9 = b;
	b = stack_9;
	y = indexed_table_021DF1_ADDRESS;
	stack_B = x_2;
	do
	{
		u_2 = 8u;
		while (u_2 != 0u)
		{
			mem_write8(x_2, mem_read8(y));
			y++;
			x_2++;
			u_2--;
		}
		x_2 += 0x38u;
		t5 = b;
		b = t5 - 1u;
	} while (t5 != 1u);
	x_2 = stack_B - 0x2000u;
	b = stack_9;
	do
	{
		u_2 = 8u;
		while (u_2 != 0u)
		{
			mem_write8(x_2, a);
			x_2++;
			u_2--;
		}
		x_2 += 0x38u;
		t6 = b;
		b = t6 - 1u;
	} while (t6 != 1u);
	x_2 = stack;
	return x_2;
}

uint16_t sub_021315(uint16_t x, uint16_t y, uint8_t d)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_021E3F_ADDRESS;
		t1 = mem_read8(x + 0x28u);
		a = t1;
		carry = (int8_t)a < 0;
		switch ((int8_t)(uint8_t)((uint32_t)a << 1))
		{
		case 0:
			return sub_02131E(x, y, u);
		case 2:
			sub_021338(x, d, carry);
			return y;
		case 4:
			sub_021385(x);
			return y;
		case 6:
			sub_0213AE(x);
			return y;
		case 8:
			return sub_0213BC(x, y);
		case 10:
			sub_0213D3(x);
			return y;
		case 12:
			return sub_0213DE(x, y);
		case 14:
			return sub_0213F3(x, y);
		case 16:
			sub_021488(x);
			return y;
		case 18:
			return sub_0214B5(x, y, u);
		case 20:
			sub_0214DD(x);
			return y;
		case 22:
			return sub_0214F1(x, y, u);
		case 24:
			sub_021529(x);
			return y;
		case 26:
			sub_021537(x);
			return y;
		case 28:
			sub_021557(x);
			return y;
		case 30:
			sub_021598(x);
			return y;
		case 32:
			sub_0215B2(x);
			return y;
		case 34:
			return sub_0215D7(x, y);
		case 36:
			return sub_0215EC(x, y);
		case 38:
			sub_02160E(x);
			return y;
		case 40:
			sub_02161F(x);
			return y;
		case 42:
			sub_02164C(x);
			return y;
		case 44:
			return sub_021673(x, y, u);
		case 46:
			sub_021695(x);
			return y;
		case 48:
			break;
		case -22:
			continue;
		case -20:
			return sub_02137C(x, y, d);
		case -18:
			return sub_0213CA(x, y, d);
		case -16:
			return sub_0213EA(x, y, d);
		case -14:
			return sub_021565(x, y);
		case -12:
			return sub_02158F(x, y, d);
		case -10:
			return sub_0215E3(x, y, d);
		case -8:
		case -6:
			return sub_021605(x, y, d);
		case -4:
			return sub_02168C(x, y, d);
		case -2:
			return sub_0216C8(x, y);
		}
		break;
	}
	return sub_0216B7(x, y, u);
}

uint16_t sub_02131E(uint16_t x, uint16_t y, uint16_t u)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 - 1u);
	if (t1 != 1u)
		return y;
	unk_487E = 2u;
	d = 0x20u;
	sub_078677(d, &y, &u);
	d = 0x6700u;
	carry = sub_078680(d);
	t2 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t2 + 1u);
	return y;
}

void sub_021338(uint16_t x, uint8_t d, uint32_t carry)
{
	uint8_t a = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;
	uint16_t t5 = 0;

	mem_write8(x, mem_read8(x) & 0x7Fu);
	a = (uint8_t)unk_4815 & 1u;
	t1 = (a >> 1) | (carry << 7);
	carry = a;
	mem_write8(x, (t1 >> 1) | (carry << 7) | mem_read8(x));
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	t3 = mem_read8(x + 0x29u);
	if (t3 == 0x40u)
	{
		t4 = mem_read8(x + 0x27u);
		mem_write8(x + 0x27u, t4 | 0x81u);
		mem_write8(x, 0u);
		t5 = mem_read16(x + 0x33u);
		mem_write8(t5, 0u);
		unk_487D = 1u;
		unk_4804++;
		unk_4805 = 0x100u | (d & 0xFFu);
	}
}

uint16_t sub_02137C(uint16_t x, uint16_t y, uint8_t d)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_021E43_ADDRESS;
		t1 = mem_read8(x + 0x28u);
		a = t1;
		carry = (int8_t)a < 0;
		switch ((int8_t)(uint8_t)((uint32_t)a << 1))
		{
		case 0:
			sub_021385(x);
			return y;
		case 2:
			sub_0213AE(x);
			return y;
		case 4:
			return sub_0213BC(x, y);
		case 6:
			sub_0213D3(x);
			return y;
		case 8:
			return sub_0213DE(x, y);
		case 10:
			return sub_0213F3(x, y);
		case 12:
			sub_021488(x);
			return y;
		case 14:
			return sub_0214B5(x, y, u);
		case 16:
			sub_0214DD(x);
			return y;
		case 18:
			return sub_0214F1(x, y, u);
		case 20:
			sub_021529(x);
			return y;
		case 22:
			sub_021537(x);
			return y;
		case 24:
			sub_021557(x);
			return y;
		case 26:
			sub_021598(x);
			return y;
		case 28:
			sub_0215B2(x);
			return y;
		case 30:
			return sub_0215D7(x, y);
		case 32:
			return sub_0215EC(x, y);
		case 34:
			sub_02160E(x);
			return y;
		case 36:
			sub_02161F(x);
			return y;
		case 38:
			sub_02164C(x);
			return y;
		case 40:
			return sub_021673(x, y, u);
		case 42:
			sub_021695(x);
			return y;
		case 44:
			break;
		case -26:
			return sub_021315(x, y, d);
		case -24:
			continue;
		case -22:
			return sub_0213CA(x, y, d);
		case -20:
			return sub_0213EA(x, y, d);
		case -18:
			return sub_021565(x, y);
		case -16:
			return sub_02158F(x, y, d);
		case -14:
			return sub_0215E3(x, y, d);
		case -12:
		case -10:
			return sub_021605(x, y, d);
		case -8:
			return sub_02168C(x, y, d);
		case -6:
			return sub_0216C8(x, y);
		case -4:
			return sub_02131E(x, y, u);
		case -2:
			sub_021338(x, d, carry);
			return y;
		}
		break;
	}
	return sub_0216B7(x, y, u);
}

void sub_021385(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0;
	uint8_t t1 = 0, t4 = 0, t5 = 0;
	uint16_t t2 = 0, t3 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry == 0u)
		return;
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	t1 = mem_read8(x + 0x1Bu);
	if (t1 <= wrestler_beaten_health_by_players[(int8_t)((uint8_t)(unk_4857 - 1u))])
	{
		d = 0x9800u;
		carry = sub_078689(d);
		mem_write8(x, (mem_read8(x) & 0xBFu) | 4u);
		t2 = mem_read16(x + 0x33u);
		mem_write16(t2 + 0x19u, 0x100u);
		d = 0x600u;
		sub_021766(x, &d, &carry);
		t3 = mem_read16(x + 0x25u);
		t4 = mem_read8(t3 + 0x5Bu);
		mem_write8(x + 0x27u, t4 & ~0xFu);
		mem_write8(x + 0x29u, 0x40u);
		mem_write8(x + 0x1Bu, 0u);
		mem_write8(x + 2u, 0xFDu);
		mem_write8(x + 0x28u, 0u);
		return;
	}
	d = 0xD00u;
	sub_021766(x, &d, &carry);
	mem_write8(x + 0x29u, 0x40u);
	t5 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t5 + 1u);
}

void sub_0213AE(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 - 1u);
	if (t1 != 1u)
		return;
	d = 0x500u;
	sub_021766(x, &d, &carry);
	t2 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t2 + 1u);
}

uint16_t sub_0213BC(uint16_t x, uint16_t y)
{
	uint16_t u = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) == 0u)
		return y;
	u = sub_021816(x);
	return sub_021708(x, y, u);
}

uint16_t sub_0213CA(uint16_t x, uint16_t y, uint8_t d)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_021E49_ADDRESS;
		t1 = mem_read8(x + 0x28u);
		a = t1;
		carry = (int8_t)a < 0;
		switch ((int8_t)(uint8_t)((uint32_t)a << 1))
		{
		case 0:
			sub_0213D3(x);
			return y;
		case 2:
			return sub_0213DE(x, y);
		case 4:
			return sub_0213F3(x, y);
		case 6:
			sub_021488(x);
			return y;
		case 8:
			return sub_0214B5(x, y, u);
		case 10:
			sub_0214DD(x);
			return y;
		case 12:
			return sub_0214F1(x, y, u);
		case 14:
			sub_021529(x);
			return y;
		case 16:
			sub_021537(x);
			return y;
		case 18:
			sub_021557(x);
			return y;
		case 20:
			sub_021598(x);
			return y;
		case 22:
			sub_0215B2(x);
			return y;
		case 24:
			return sub_0215D7(x, y);
		case 26:
			return sub_0215EC(x, y);
		case 28:
			sub_02160E(x);
			return y;
		case 30:
			sub_02161F(x);
			return y;
		case 32:
			sub_02164C(x);
			return y;
		case 34:
			return sub_021673(x, y, u);
		case 36:
			sub_021695(x);
			return y;
		case 38:
			break;
		case -32:
			return sub_021315(x, y, d);
		case -30:
			return sub_02137C(x, y, d);
		case -28:
			continue;
		case -26:
			return sub_0213EA(x, y, d);
		case -24:
			return sub_021565(x, y);
		case -22:
			return sub_02158F(x, y, d);
		case -20:
			return sub_0215E3(x, y, d);
		case -18:
		case -16:
			return sub_021605(x, y, d);
		case -14:
			return sub_02168C(x, y, d);
		case -12:
			return sub_0216C8(x, y);
		case -10:
			return sub_02131E(x, y, u);
		case -8:
			sub_021338(x, d, carry);
			return y;
		case -6:
			sub_021385(x);
			return y;
		case -4:
			sub_0213AE(x);
			return y;
		case -2:
			return sub_0213BC(x, y);
		}
		break;
	}
	return sub_0216B7(x, y, u);
}

void sub_0213D3(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) != 0u)
	{
		t2 = mem_read8(x + 0x28u);
		mem_write8(x + 0x28u, t2 + 1u);
	}
}

uint16_t sub_0213DE(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, u = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry == 0u)
		return y;
	u = sub_021816(x);
	y = sub_021708(x, y, u);
	return y;
}

uint16_t sub_0213EA(uint16_t x, uint16_t y, uint8_t d)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_021E4D_ADDRESS;
		t1 = mem_read8(x + 0x28u);
		a = t1;
		carry = (int8_t)a < 0;
		switch ((int8_t)(uint8_t)((uint32_t)a << 1))
		{
		case 0:
			return sub_0213F3(x, y);
		case 2:
			sub_021488(x);
			return y;
		case 4:
			return sub_0214B5(x, y, u);
		case 6:
			sub_0214DD(x);
			return y;
		case 8:
			return sub_0214F1(x, y, u);
		case 10:
			sub_021529(x);
			return y;
		case 12:
			sub_021537(x);
			return y;
		case 14:
			sub_021557(x);
			return y;
		case 16:
			sub_021598(x);
			return y;
		case 18:
			sub_0215B2(x);
			return y;
		case 20:
			return sub_0215D7(x, y);
		case 22:
			return sub_0215EC(x, y);
		case 24:
			sub_02160E(x);
			return y;
		case 26:
			sub_02161F(x);
			return y;
		case 28:
			sub_02164C(x);
			return y;
		case 30:
			return sub_021673(x, y, u);
		case 32:
			sub_021695(x);
			return y;
		case 34:
			break;
		case -36:
			return sub_021315(x, y, d);
		case -34:
			return sub_02137C(x, y, d);
		case -32:
			return sub_0213CA(x, y, d);
		case -30:
			continue;
		case -28:
			return sub_021565(x, y);
		case -26:
			return sub_02158F(x, y, d);
		case -24:
			return sub_0215E3(x, y, d);
		case -22:
		case -20:
			return sub_021605(x, y, d);
		case -18:
			return sub_02168C(x, y, d);
		case -16:
			return sub_0216C8(x, y);
		case -14:
			return sub_02131E(x, y, u);
		case -12:
			sub_021338(x, d, carry);
			return y;
		case -10:
			sub_021385(x);
			return y;
		case -8:
			sub_0213AE(x);
			return y;
		case -6:
			return sub_0213BC(x, y);
		case -4:
			sub_0213D3(x);
			return y;
		case -2:
			return sub_0213DE(x, y);
		}
		break;
	}
	return sub_0216B7(x, y, u);
}

uint16_t sub_0213F3(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t d_2 = 0;
	uint16_t d = 0, u = 0;
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0;

	mem_write8(x + 0x57u, 1u);
	if (unk_4892 != 0u)
		return y;
	mem_write8(x, 0x88u);
	mem_write8(x + 0x5Bu, 1u);
	d = 0xE00u;
	sub_021766(x, &d, &carry);
	d &= 0xFFu;
	sub_021775(x, d);
	mem_write16(x + 0xCu, 0xE0u);
	mem_write16(x + 0x11u, 0x82u);
	t1 = 0x100u - unk_48B2;
	mem_write16(x + 0x16u, t1);
	mem_write16(x + 0x19u, 0xFF00u);
	mem_write8(x + 0x1Bu, 0xC0u);
	mem_write8(x + VIDEO_002F, 0xC0u);
	unk_487C++;
	d_2 = 2u;
	sub_07867D(d_2, &u, &carry);
	mem_write8(u, 0x80u);
	mem_write8(u + 6u, 0x80u);
	mem_write8(u + 1u, 0u);
	mem_write16(u + 4u, 0xF91u);
	mem_write16(u + 0xCu, 0xE0u);
	mem_write16(u + 0x11u, 0x80u);
	t2 = 0x158u - unk_48B2;
	mem_write16(u + 0x16u, t2);
	mem_write16(u + 0x19u, 0xFF00u);
	mem_write16(x + 0x33u, u);
	mem_write8(x + 0x57u, 0u);
	unk_487E = 2u;
	d = 0x16u;
	sub_078677(d, &y, &u);
	unk_487E = 2u;
	d = 0x17u;
	sub_078677(d, &y, &u);
	t3 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t3 + 1u);
	return y;
}

void sub_021488(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t5 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = mem_read16(x + 0x33u);
	u = t1;
	t2 = mem_read16(u + 0x16u);
	t3 = mem_read16(u + 0x11u);
	if ((uint16_t)(t2 + t3 - unk_48B2) <= 0x130u)
	{
		t4 = mem_read16(u + 0x11u);
		mem_write16(u + 0x16u, 0x130u + unk_48B2 - t4);
		mem_write8(x + 0x29u, 0x20u);
		mem_write16(x + 0x19u, 0u);
		mem_write16(u + 0x19u, 0u);
		t5 = mem_read8(x + 0x28u);
		mem_write8(x + 0x28u, t5 + 1u);
	}
}

uint16_t sub_0214B5(uint16_t x, uint16_t y, uint16_t u)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 - 1u);
	if (t1 != 1u)
		return y;
	unk_487E = 2u;
	d = 0xCu;
	sub_078677(d, &y, &u);
	d = 0x6700u;
	carry = sub_078680(d);
	d = 0xF00u;
	sub_021766(x, &d, &carry);
	mem_write8(x + 0x29u, 0x40u);
	t2 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t2 + 1u);
	return y;
}

void sub_0214DD(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 - 1u);
	if (t1 != 1u)
		return;
	d = 0x400u;
	sub_021766(x, &d, &carry);
	mem_write16(x + 0x14u, 0x100u);
	t2 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t2 + 1u);
}

uint16_t sub_0214F1(uint16_t x, uint16_t y, uint16_t u)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0;
	uint8_t t1 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry == 0u)
		return y;
	unk_487E = 2u;
	d = 0x21u;
	sub_078677(d, &y, &u);
	unk_487E = 2u;
	d = 0x26u;
	sub_078677(d, &y, &u);
	unk_4897 = 1u;
	d = 0x6400u;
	carry = sub_078680(d);
	mem_write16(x + 0x14u, 0u);
	d = 0xB00u;
	sub_021766(x, &d, &carry);
	mem_write8(x + 0x29u, 0x40u);
	t1 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t1 + 1u);
	return y;
}

void sub_021529(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 - 1u);
	if (t1 != 1u)
		return;
	d = 0x500u;
	sub_021766(x, &d, &carry);
	t2 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t2 + 1u);
}

void sub_021537(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) == 0u)
		return;
	d = 0x3F2Du;
	carry = sub_078680(d);
	mem_write8(x, 0xC0u);
	d = 0xA00u;
	sub_021766(x, &d, &carry);
	mem_write8(x + 0x29u, 0x40u);
	t2 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t2 + 1u);
}

void sub_021557(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 0x28u, 0u);
		mem_write8(x + 2u, 1u);
	}
}

uint16_t sub_021565(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t d = 0, u = 0;
	uint8_t t1 = 0, t2 = 0;

	sub_0216E4(x, &u, &carry);
	if (carry)
		return y;
	sub_021708(x, y, u);
	t1 = mem_read8(x + 5u);
	if (t1 != 0u)
	{
		d = 0x100u;
		sub_021766(x, &d, &carry);
	}
	sub_02172D(x);
	t2 = mem_read8(x + 0x2Du);
	y = wrestler_speeds_by_rank_ADDRESS;
	d = ((uint32_t)t2 << 8) | wrestler_speeds_by_rank[unk_4861 >> 1];
	sub_078617(x, d);
	sub_02174B(x);
	return y;
}

uint16_t sub_02158F(uint16_t x, uint16_t y, uint8_t d)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_021E5D_ADDRESS;
		t1 = mem_read8(x + 0x28u);
		a = t1;
		carry = (int8_t)a < 0;
		switch ((int8_t)(uint8_t)((uint32_t)a << 1))
		{
		case 0:
			sub_021598(x);
			return y;
		case 2:
			sub_0215B2(x);
			return y;
		case 4:
			return sub_0215D7(x, y);
		case 6:
			return sub_0215EC(x, y);
		case 8:
			sub_02160E(x);
			return y;
		case 10:
			sub_02161F(x);
			return y;
		case 12:
			sub_02164C(x);
			return y;
		case 14:
			return sub_021673(x, y, u);
		case 16:
			sub_021695(x);
			return y;
		case 18:
			break;
		case -52:
			return sub_021315(x, y, d);
		case -50:
			return sub_02137C(x, y, d);
		case -48:
			return sub_0213CA(x, y, d);
		case -46:
			return sub_0213EA(x, y, d);
		case -44:
			return sub_021565(x, y);
		case -42:
			continue;
		case -40:
			return sub_0215E3(x, y, d);
		case -38:
		case -36:
			return sub_021605(x, y, d);
		case -34:
			return sub_02168C(x, y, d);
		case -32:
			return sub_0216C8(x, y);
		case -30:
			return sub_02131E(x, y, u);
		case -28:
			sub_021338(x, d, carry);
			return y;
		case -26:
			sub_021385(x);
			return y;
		case -24:
			sub_0213AE(x);
			return y;
		case -22:
			return sub_0213BC(x, y);
		case -20:
			sub_0213D3(x);
			return y;
		case -18:
			return sub_0213DE(x, y);
		case -16:
			return sub_0213F3(x, y);
		case -14:
			sub_021488(x);
			return y;
		case -12:
			return sub_0214B5(x, y, u);
		case -10:
			sub_0214DD(x);
			return y;
		case -8:
			return sub_0214F1(x, y, u);
		case -6:
			sub_021529(x);
			return y;
		case -4:
			sub_021537(x);
			return y;
		case -2:
			sub_021557(x);
			return y;
		}
		break;
	}
	return sub_0216B7(x, y, u);
}

void sub_021598(uint16_t x)
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
	d = 0x200u;
	sub_021766(x, &d, &carry);
	mem_write8(x, mem_read8(x) | 4u);
	t3 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t3 + 1u);
}

void sub_0215B2(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	a = 0u;
	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) != 0u)
		a = 1u;
	d = (uint32_t)a << 8;
	sub_021775(x, d);
	t2 = mem_read8(x + 6u);
	if ((t2 & 1u) == 0u)
		return;
	d = 0u;
	sub_021766(x, &d, &carry);
	d &= 0xFFu;
	sub_021775(x, d);
	mem_write8(x + 0x29u, 0x10u);
	t3 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t3 + 1u);
}

uint16_t sub_0215D7(uint16_t x, uint16_t y)
{
	uint16_t u = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 - 1u);
	if (t1 != 1u)
		return y;
	u = sub_021816(x);
	y = sub_021708(x, y, u);
	return y;
}

uint16_t sub_0215E3(uint16_t x, uint16_t y, uint8_t d)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_021E63_ADDRESS;
		t1 = mem_read8(x + 0x28u);
		a = t1;
		carry = (int8_t)a < 0;
		switch ((int8_t)(uint8_t)((uint32_t)a << 1))
		{
		case 0:
			return sub_0215EC(x, y);
		case 2:
			sub_02160E(x);
			return y;
		case 4:
			sub_02161F(x);
			return y;
		case 6:
			sub_02164C(x);
			return y;
		case 8:
			return sub_021673(x, y, u);
		case 10:
			sub_021695(x);
			return y;
		case 12:
			break;
		case -58:
			return sub_021315(x, y, d);
		case -56:
			return sub_02137C(x, y, d);
		case -54:
			return sub_0213CA(x, y, d);
		case -52:
			return sub_0213EA(x, y, d);
		case -50:
			return sub_021565(x, y);
		case -48:
			return sub_02158F(x, y, d);
		case -46:
			continue;
		case -44:
		case -42:
			return sub_021605(x, y, d);
		case -40:
			return sub_02168C(x, y, d);
		case -38:
			return sub_0216C8(x, y);
		case -36:
			return sub_02131E(x, y, u);
		case -34:
			sub_021338(x, d, carry);
			return y;
		case -32:
			sub_021385(x);
			return y;
		case -30:
			sub_0213AE(x);
			return y;
		case -28:
			return sub_0213BC(x, y);
		case -26:
			sub_0213D3(x);
			return y;
		case -24:
			return sub_0213DE(x, y);
		case -22:
			return sub_0213F3(x, y);
		case -20:
			sub_021488(x);
			return y;
		case -18:
			return sub_0214B5(x, y, u);
		case -16:
			sub_0214DD(x);
			return y;
		case -14:
			return sub_0214F1(x, y, u);
		case -12:
			sub_021529(x);
			return y;
		case -10:
			sub_021537(x);
			return y;
		case -8:
			sub_021557(x);
			return y;
		case -6:
			sub_021598(x);
			return y;
		case -4:
			sub_0215B2(x);
			return y;
		case -2:
			return sub_0215D7(x, y);
		}
		break;
	}
	return sub_0216B7(x, y, u);
}

uint16_t sub_0215EC(uint16_t x, uint16_t y)
{
	uint8_t a = 0;
	uint16_t d = 0, u = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 - 1u);
	if (t1 == 1u)
	{
		u = sub_021816(x);
		return sub_021708(x, y, u);
	}
	a = 0u;
	t2 = mem_read8(x + 6u);
	if ((t2 & 2u) != 0u)
		a = 2u;
	d = (uint32_t)a << 8;
	sub_021775(x, d);
	return y;
}

uint16_t sub_021605(uint16_t x, uint16_t y, uint8_t d)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_021E65_ADDRESS;
		t1 = mem_read8(x + 0x28u);
		a = t1;
		carry = (int8_t)a < 0;
		switch ((int8_t)(uint8_t)((uint32_t)a << 1))
		{
		case 0:
			sub_02160E(x);
			return y;
		case 2:
			sub_02161F(x);
			return y;
		case 4:
			sub_02164C(x);
			return y;
		case 6:
			return sub_021673(x, y, u);
		case 8:
			sub_021695(x);
			return y;
		case 10:
			break;
		case -60:
			return sub_021315(x, y, d);
		case -58:
			return sub_02137C(x, y, d);
		case -56:
			return sub_0213CA(x, y, d);
		case -54:
			return sub_0213EA(x, y, d);
		case -52:
			return sub_021565(x, y);
		case -50:
			return sub_02158F(x, y, d);
		case -48:
			return sub_0215E3(x, y, d);
		case -46:
		case -44:
			continue;
		case -42:
			return sub_02168C(x, y, d);
		case -40:
			return sub_0216C8(x, y);
		case -38:
			return sub_02131E(x, y, u);
		case -36:
			sub_021338(x, d, carry);
			return y;
		case -34:
			sub_021385(x);
			return y;
		case -32:
			sub_0213AE(x);
			return y;
		case -30:
			return sub_0213BC(x, y);
		case -28:
			sub_0213D3(x);
			return y;
		case -26:
			return sub_0213DE(x, y);
		case -24:
			return sub_0213F3(x, y);
		case -22:
			sub_021488(x);
			return y;
		case -20:
			return sub_0214B5(x, y, u);
		case -18:
			sub_0214DD(x);
			return y;
		case -16:
			return sub_0214F1(x, y, u);
		case -14:
			sub_021529(x);
			return y;
		case -12:
			sub_021537(x);
			return y;
		case -10:
			sub_021557(x);
			return y;
		case -8:
			sub_021598(x);
			return y;
		case -6:
			sub_0215B2(x);
			return y;
		case -4:
			return sub_0215D7(x, y);
		case -2:
			return sub_0215EC(x, y);
		}
		break;
	}
	return sub_0216B7(x, y, u);
}

void sub_02160E(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0;
	uint8_t t1 = 0, t2 = 0;

	sub_0785B1(x, &ignored16, &carry);
	t1 = mem_read8(x + 0x19u);
	if (t1 != 0u)
		return;
	d = 0x900u;
	sub_021766(x, &d, &carry);
	t2 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t2 + 1u);
}

void sub_02161F(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0;
	uint8_t t1 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry == 0u)
		return;
	mem_write8(x, mem_read8(x) | 0x40u);
	unk_4897 = 1u;
	d = 0x6400u;
	carry = sub_078680(d);
	mem_write8(x, mem_read8(x) | 0x40u);
	d = 0x300u;
	sub_021775(x, d);
	mem_write16(x + 0xFu, 0u);
	t1 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t1 + 1u);
}

void sub_02164C(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	d = 0u;
	sub_021775(x, d);
	mem_write8(x + 0x29u, 0x30u);
	b = mem_read8(x) & 0xBFu;
	mem_write8(x, b);
	if ((b & 0x20u) == 0u)
	{
		d = 0xB00u;
		sub_021766(x, &d, &carry);
		t1 = mem_read8(x + 0x28u);
		mem_write8(x + 0x28u, t1 + 1u);
		return;
	}
	d = VIDEO_0C00;
	sub_021766(x, &d, &carry);
	t2 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t2 + 1u);
}

uint16_t sub_021673(uint16_t x, uint16_t y, uint16_t u)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x, mem_read8(x) | 0x40u);
		mem_write8(x + 2u, 1u);
		mem_write8(x + 0x28u, 0u);
		y = sub_021708(x, y, u);
	}
	return y;
}

uint16_t sub_02168C(uint16_t x, uint16_t y, uint8_t d)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_021E6D_ADDRESS;
		t1 = mem_read8(x + 0x28u);
		a = t1;
		carry = (int8_t)a < 0;
		switch ((int8_t)(uint8_t)((uint32_t)a << 1))
		{
		case 0:
			sub_021695(x);
			return y;
		case 2:
			break;
		case -68:
			return sub_021315(x, y, d);
		case -66:
			return sub_02137C(x, y, d);
		case -64:
			return sub_0213CA(x, y, d);
		case -62:
			return sub_0213EA(x, y, d);
		case -60:
			return sub_021565(x, y);
		case -58:
			return sub_02158F(x, y, d);
		case -56:
			return sub_0215E3(x, y, d);
		case -54:
		case -52:
			return sub_021605(x, y, d);
		case -50:
			continue;
		case -48:
			return sub_0216C8(x, y);
		case -46:
			return sub_02131E(x, y, u);
		case -44:
			sub_021338(x, d, carry);
			return y;
		case -42:
			sub_021385(x);
			return y;
		case -40:
			sub_0213AE(x);
			return y;
		case -38:
			return sub_0213BC(x, y);
		case -36:
			sub_0213D3(x);
			return y;
		case -34:
			return sub_0213DE(x, y);
		case -32:
			return sub_0213F3(x, y);
		case -30:
			sub_021488(x);
			return y;
		case -28:
			return sub_0214B5(x, y, u);
		case -26:
			sub_0214DD(x);
			return y;
		case -24:
			return sub_0214F1(x, y, u);
		case -22:
			sub_021529(x);
			return y;
		case -20:
			sub_021537(x);
			return y;
		case -18:
			sub_021557(x);
			return y;
		case -16:
			sub_021598(x);
			return y;
		case -14:
			sub_0215B2(x);
			return y;
		case -12:
			return sub_0215D7(x, y);
		case -10:
			return sub_0215EC(x, y);
		case -8:
			sub_02160E(x);
			return y;
		case -6:
			sub_02161F(x);
			return y;
		case -4:
			sub_02164C(x);
			return y;
		case -2:
			return sub_021673(x, y, u);
		}
		break;
	}
	return sub_0216B7(x, y, u);
}

void sub_021695(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0;
	uint8_t t1 = 0;

	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	sub_078686(x, &ignored16, &ignored16_2, &carry);
	if (carry == 0u)
		return;
	mem_write8(x, mem_read8(x) | 0x40u);
	mem_write8(x + 0x29u, 0x60u);
	d = 0xA00u;
	sub_021766(x, &d, &carry);
	t1 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t1 + 1u);
}

uint16_t sub_0216B7(uint16_t x, uint16_t y, uint16_t u)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 2u, 1u);
		mem_write8(x + 0x28u, 0u);
		y = sub_021708(x, y, u);
	}
	return y;
}

uint16_t sub_0216C8(uint16_t x, uint16_t y)
{
	uint16_t y_2 = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(y + 0x2Bu);
	y_2 = t1;
	t2 = mem_read8(y_2 + 2u);
	if ((int8_t)t2 >= 0)
	{
		sub_021816(x);
		return y_2;
	}
	return y_2;
}

void sub_0216D2(uint16_t x, uint16_t *p_y, uint16_t *p_d)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t d = (uint8_t)*p_d;
	uint32_t negative = 0;
	uint8_t a = 0, b = 0;
	uint16_t d_2 = 0;
	uint8_t t1 = 0;

	b = (uint8_t)d;
	a = mem_read8(x);
	if ((a & 0x20u) != 0u)
	{
		t1 = mem_read8(x + 0x1Eu);
		negative = t1 >> 7;
		b = t1;
		if (t1 != 0u && negative == 0u)
		{
			sub_02188B(x, &y, &d_2);
			a = (uint8_t)(d_2 >> 8);
			b = (uint8_t)d_2;
		}
	}
	d_2 = ((uint32_t)a << 8) | b;
	*p_y = y;
	*p_d = d_2;
}

void sub_0216E4(uint16_t x, uint16_t *p_u, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, u = 0;
	uint8_t t4 = 0, t5 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t6 = 0;

	t1 = mem_read16(x + 0x2Bu);
	u = t1;
	t2 = mem_read16(x + 0xCu);
	t3 = mem_read16(u + 0xCu);
	if ((int16_t)t2 < (int16_t)t3)
	{
		t4 = mem_read8(x + 9u);
		if ((t4 & 0x40u) != 0u)
		{
			carry = 0u;
			*p_u = u;
			*p_carry = carry;
			return;
		}
	}
	else
	{
		t5 = mem_read8(x + 9u);
		if ((t5 & 0x40u) == 0u)
		{
			carry = 0u;
			*p_u = u;
			*p_carry = carry;
			return;
		}
	}
	carry = sub_0217C9(x, u);
	if (carry == 0u)
	{
		carry = 0u;
		*p_u = u;
		*p_carry = carry;
		return;
	}
	t6 = mem_read16(x + 0x2Bu);
	u = t6;
	t7 = mem_read8(u + 2u);
	if ((int8_t)t7 < 0)
	{
		carry = sub_02186F(x);
		*p_u = u;
		*p_carry = carry;
		return;
	}
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	sub_02174B(x);
	mem_write8(x + 0x29u, 0u);
	u = wrestler_quick_attack_chances_by_players_ADDRESS;
	if (wrestler_quick_attack_chances_by_players[(int8_t)((uint8_t)(unk_4857 - 1u))] <= unk_4858)
	{
		t8 = mem_read8(x + VIDEO_002F);
		t9 = mem_read8(x + 0x1Bu);
		if ((uint8_t)(t8 - t9) < 0xCu)
		{
			mem_write8(x + 2u, 2u);
			mem_write8(x + 0x28u, 0u);
			mem_write8(x + 0x29u, 0x20u);
			carry = 1u;
			*p_u = u;
			*p_carry = carry;
			return;
		}
	}
	t10 = mem_read8(x + 0x1Bu);
	mem_write8(x + VIDEO_002F, t10);
	carry = sub_0217E5(x);
	if (carry)
	{
		u = wrestler_guard_chances_by_players_ADDRESS;
		if (unk_4858 < wrestler_guard_chances_by_players[(int8_t)((uint8_t)(unk_4857 - 1u))])
		{
			mem_write8(x, mem_read8(x) | 4u);
			mem_write8(x + 0x29u, 0x40u);
			mem_write8(x + 2u, 3u);
			mem_write8(x + 0x28u, 0u);
			d = 0x800u;
			sub_021766(x, &d, &carry);
			sub_02174B(x);
			carry = 1u;
			*p_u = u;
			*p_carry = carry;
			return;
		}
	}
	u = wrestler_jump_chances_by_rank_ADDRESS;
	a = wrestler_jump_chances_by_rank[unk_4861 >> 1];
	unk_48F0 = unk_4858 + (uint8_t)unk_4815;
	if (a <= unk_48F0)
	{
		mem_write8(x + 2u, 2u);
		mem_write8(x + 0x28u, 0u);
		carry = 1u;
		*p_u = u;
		*p_carry = carry;
		return;
	}
	mem_write8(x + 2u, 4u);
	mem_write8(x + 0x28u, 0u);
	d = 0x700u;
	sub_021766(x, &d, &carry);
	sub_02174B(x);
	t11 = mem_read8(x + 9u);
	if ((t11 & 0x40u) == 0u)
	{
		a = 1u;
		b = 0x80u;
	}
	else
	{
		a = 0xFEu;
		b = 0x80u;
	}
	mem_write16(x + 0xFu, ((uint32_t)a << 8) | b);
	mem_write16(x + 0x14u, 0u);
	mem_write16(x + 0x19u, 0x700u);
	mem_write8(x, (mem_read8(x) & 0xBFu) | 8u);
	carry = 1u;
	*p_u = u;
	*p_carry = carry;
}

uint16_t sub_021708(uint16_t x, uint16_t y, uint16_t u)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, y_2 = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0;
	uint16_t t1 = 0;

	sub_078686(x, &u, &ignored16, &carry);
	if (carry == 0u)
	{
		carry = sub_02186F(x);
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

void sub_02172D(uint16_t x)
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

void sub_02174B(uint16_t x)
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

void sub_021766(uint16_t x, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t a = 0, b = 0;
	uint16_t d_2 = 0;
	uint16_t t1 = 0;

	a = (uint8_t)(d >> 8);
	carry = (int8_t)a < 0;
	t1 = wrestler_animations[a & 0x7Fu];
	a = (uint8_t)(t1 >> 8);
	b = t1 | 0x80u;
	mem_write16(x + 4u, ((uint32_t)a << 8) | b);
	d_2 = ((uint32_t)a << 8) | b;
	*p_d = d_2;
	*p_carry = carry;
}

uint16_t sub_021775(uint16_t x, uint16_t d)
{
	uint16_t u = 0;
	uint16_t t1 = 0, field_1c = 0, t2 = 0, field_1f = 0, t3 = 0, field = 0, t4 = 0, field_23 = 0;

	t1 = wrestler_hit_boxes_ADDRESS + (uint8_t)((((uint32_t)(d >> 8) << 1) << 1) << 1);
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
	mem_write16(x + 0x23u, field_23);
	return u;
}

void sub_021795(uint16_t x)
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
	if ((int16_t)d <= 0x57F || (int16_t)d >= 0x69F)
		mem_write16(x + 0xFu, 0u);
}

uint32_t sub_0217C9(uint16_t x, uint16_t u)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = mem_read16(x + 0xCu);
	t2 = mem_read16(u + 0xCu);
	d = t1 - t2;
	if ((int16_t)(d >> 15 ? 0u - d : d) <= 0x40)
	{
		t3 = mem_read16(x + 0x11u);
		t4 = mem_read16(u + 0x11u);
		d = t3 - t4;
		if ((int16_t)(d >> 15 ? 0u - d : d) <= 4)
		{
			carry = 1u;
			return carry;
		}
	}
	carry = 0u;
	return carry;
}

uint32_t sub_0217E5(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t u = 0;
	uint8_t stack = 0, stack_2 = 0;
	uint8_t t1 = 0, t2 = 0;

	if (unk_4857 == 1u)
	{
		carry = 1u;
		return carry;
	}
	u = unk_4A40_ADDRESS;
	stack = 0u;
	stack_2 = 4u;
	do
	{
		if (mem_read8(u) != 0u)
		{
			t1 = mem_read8(u + 2u);
			if ((int8_t)t1 >= 0)
			{
				carry = sub_0217C9(x, u);
				if (carry)
					stack = stack + 1u;
			}
		}
		u += 0xC0u;
		t2 = stack_2;
		stack_2 = t2 - 1u;
	} while (t2 != 1u);
	if (stack < 2u)
	{
		carry = 0u;
		return carry;
	}
	carry = 1u;
	return carry;
}

uint16_t sub_021816(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0, u = 0;

	d = 0x100u;
	sub_021766(x, &d, &carry);
	mem_write8(x, (mem_read8(x) | 0x40u) & ~4u);
	d &= 0xFFu;
	u = sub_021775(x, d);
	mem_write8(x + 2u, 1u);
	mem_write8(x + 0x28u, 0u);
	mem_write8(x + 0x29u, 0u);
	return u;
}

uint32_t sub_02186F(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;

	d = 0x6800u;
	carry = sub_078680(d);
	mem_write8(x + 2u, 6u);
	mem_write8(x + 0x28u, 0u);
	d = 0x100u;
	sub_021766(x, &d, &carry);
	mem_write8(x, mem_read8(x) & 0xBFu);
	return carry;
}

void sub_02188B(uint16_t x, uint16_t *p_y, uint16_t *p_d)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint16_t d = 0, u = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x25u);
	u = t1;
	mem_write8(u + 0x2Au, 1u);
	mem_write16(u + 0x49u, x);
	mem_write8(x, mem_read8(x) & 0xBBu);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write16(x + 0x19u, 0u);
	unk_487E = 2u;
	d = 2u;
	sub_078677(d, &y, &u);
	d = 0x6600u;
	carry = sub_078680(d);
	d = 0u;
	sub_021775(x, d);
	t2 = mem_read8(x + 0x1Bu);
	if (t2 == 0u)
	{
		d = 0x6600u;
		carry = sub_078689(d);
		mem_write8(x + 0x30u, 0u);
		d = 0x400u;
		sub_021766(x, &d, &carry);
		mem_write8(x + 2u, 0xFEu);
		mem_write8(x + 0x28u, 0u);
		mem_write16(x + 0x14u, 0u);
		mem_write16(x + 0x19u, 0x400u);
		t3 = mem_read8(x + 0x2Eu);
		if ((uint8_t)(t3 + 0x40u) < 0x80u)
		{
			d = 0xFD00u;
			mem_write16(x + 0xFu, 0xFD00u);
		}
		else
		{
			d = 0x300u;
			mem_write16(x + 0xFu, 0x300u);
		}
	}
	else
	{
		t4 = mem_read8(x + 0x1Eu);
		if (t4 == 0x13u)
		{
			d = 0x6900u;
			carry = sub_078680(d);
			mem_write8(x + 0x30u, 0u);
			d = 0x400u;
			sub_021766(x, &d, &carry);
			mem_write8(x + 2u, 0xFEu);
			mem_write8(x + 0x28u, 0u);
			mem_write16(x + 0x14u, 0u);
			mem_write16(x + 0x19u, 0x400u);
			t3 = mem_read8(x + 0x2Eu);
			if ((uint8_t)(t3 + 0x40u) < 0x80u)
			{
				d = 0xFD00u;
				mem_write16(x + 0xFu, 0xFD00u);
			}
			else
			{
				d = 0x300u;
				mem_write16(x + 0xFu, 0x300u);
			}
		}
		else
		{
			t5 = mem_read8(x + 0x30u);
			if (t5 == 4u)
			{
				d = 0x6900u;
				carry = sub_078680(d);
				mem_write8(x + 0x30u, 0u);
				d = 0x400u;
				sub_021766(x, &d, &carry);
				mem_write8(x + 2u, 0xFEu);
				mem_write8(x + 0x28u, 0u);
				mem_write16(x + 0x14u, 0u);
				mem_write16(x + 0x19u, 0x400u);
				t3 = mem_read8(x + 0x2Eu);
				if ((uint8_t)(t3 + 0x40u) < 0x80u)
				{
					d = 0xFD00u;
					mem_write16(x + 0xFu, 0xFD00u);
				}
				else
				{
					d = 0x300u;
					mem_write16(x + 0xFu, 0x300u);
				}
			}
			else
			{
				t6 = mem_read8(x + 0x30u);
				mem_write8(x + 0x30u, t6 + 1u);
				d = 0x300u;
				sub_021766(x, &d, &carry);
				mem_write8(x + 2u, 0xFFu);
				mem_write8(x + 0x28u, 0u);
				d = (d & 0xFFu) | 0xFF00u;
			}
		}
	}
	*p_y = y;
	*p_d = d;
}

uint16_t sub_0219F5(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t5 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t6 = 0, t7 = 0;

	mem_write8(x, 0x80u);
	t1 = mem_read16(x + 0x29u);
	u = t1;
	t2 = mem_read16(u + 0xCu);
	mem_write16(x + 0xCu, t2 - 0x20u);
	t3 = mem_read16(u + 0x11u);
	mem_write16(x + 0x11u, t3 - 2u);
	t4 = mem_read16(u + 0x16u);
	mem_write16(x + 0x16u, t4 + 0x6Cu);
	t5 = mem_read8(x + 2u);
	mem_write8(x + 2u, t5 + 1u);
	t6 = mem_read16(u + 0xFu);
	mem_write16(x + 0xFu, t6);
	t7 = mem_read16(u + 0x14u);
	mem_write16(x + 0x14u, t7);
	return u;
}

uint16_t sub_021A1C(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0, t3 = 0, t4 = 0;

	t1 = mem_read16(x + 0x29u);
	u = t1;
	t2 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t2 - 1u);
	if (t2 != 1u)
	{
		t3 = mem_read16(u + 0xFu);
		mem_write16(x + 0xFu, t3);
		t4 = mem_read16(u + 0x14u);
		mem_write16(x + 0x14u, t4);
		return u;
	}
	mem_write8(x, 0u);
	return u;
}
