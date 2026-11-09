/**
 *    Name:        unsorted/bank_13.c
 *    Description: bank 13's code
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

void sub_026000(uint16_t *p_x, uint16_t *p_y)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d = 0, u = 0;
	uint8_t t1 = 0;

	mem_write8(x, mem_read8(x) | 0x10u);
	y = sub_02691C(x, y);
	u = loaded_table_027C64_ADDRESS;
	t1 = mem_read8(x + 2u);
	a = t1;
	carry = (int8_t)a < 0;
	switch ((int8_t)(uint8_t)((uint32_t)a << 1))
	{
	case 0:
		sub_026608(&x, &y);
		break;
	case 2:
		y = sub_02672A(x, y);
		break;
	case 4:
		sub_026751(&x, &y);
		break;
	case 6:
		sub_0267C0(&x, &y);
		break;
	case 8:
		sub_0268B8(&x, &y);
		break;
	case 10:
		y = sub_0268F8(x, y);
		break;
	case 12:
		sub_02653D(x);
		break;
	case 14:
		sub_026554(x);
		break;
	case 16:
		sub_026563(x);
		break;
	case 18:
		sub_026573(x);
		break;
	case 20:
		sub_0265C7(x);
		break;
	case 22:
		sub_0265FE(x, u);
		break;
	case 24:
		y = sub_026611(x, y, u);
		break;
	case 26:
		sub_026692(x);
		break;
	case 28:
		sub_0266B3(x);
		break;
	case 30:
		sub_0266DA(x);
		break;
	case 32:
		sub_026702(x);
		break;
	case 34:
		sub_026721(&x, &y);
		break;
	case 36:
		sub_02675A(x);
		break;
	case 38:
		sub_026772(x);
		break;
	case 40:
		y = sub_0267AD(x, y, u);
		break;
	case 42:
		sub_0267C9(x);
		break;
	case 44:
		sub_026838(&x, &y);
		break;
	case 46:
		sub_02687B(x);
		break;
	case 48:
		sub_02688C(x);
		break;
	case 50:
		sub_026895(x, u);
		break;
	case 52:
		sub_0268C1(x);
		break;
	case 54:
		sub_0268F5(&x, &y);
		break;
	case 56:
		y = sub_026A45(u, carry);
		break;
	case 58:
		y = sub_026A55(u, carry);
		break;
	case 60:
		y = sub_026A4D(u, carry);
		break;
	case 62:
		sub_026A8F(x);
		break;
	case 64:
		sub_026AA3(x);
		break;
	case 66:
		sub_026AB7(x);
		break;
	case 68:
		sub_026AD3(x);
		break;
	case 70:
		sub_026B00(x);
		break;
	case 72:
		y = sub_026B14(x, y, u);
		break;
	case -6:
		sub_026532(&x, &y);
		break;
	case -4:
		sub_0265BE(&x, &y);
		break;
	case -2:
		sub_026601(&x, &y);
		break;
	}
	sub_026D01(x);
	sub_026D35(x);
	d = ((uint32_t)krusty_balloon_gauge_piece_health_by_players[(int8_t)((uint8_t)(unk_4857 - 1u))] << 8) | 1u;
	y = sub_0786BF(x, y, d);
	*p_x = x;
	*p_y = y;
}

void sub_026003(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t t1 = 0;

	if ((mem_read8(x) & 0x20u) != 0u)
	{
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
		mem_write16(x + 0x19u, 0u);
		sub_026D8F(x);
	}
	u = loaded_table_027D3A_ADDRESS;
	t1 = mem_read8(x + 2u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_026DB8(x);
		break;
	case 2:
		sub_026DD3(x);
		break;
	case 4:
		sub_026DFA(x);
		break;
	case 6:
		sub_026E16(x);
		break;
	case 8:
		sub_026E32(&x, &y, &u);
		break;
	case 10:
		sub_026F1E(&x, &y, &u);
		break;
	case 12:
	case 16:
	case 22:
	case 28:
		sub_026E2F(&y, &u);
		break;
	case 14:
		sub_026F5D(&x, &y, &u);
		break;
	case 18:
		sub_026FB9(&x, &y, &u);
		break;
	case 20:
		sub_026FF8(&x, &y, &u);
		break;
	case 24:
		sub_027059(&x, &y, &u);
		break;
	case 26:
		sub_027098(&x, &y, &u);
		break;
	case 30:
		sub_027135(&x, &y, &u);
		break;
	case 32:
		sub_026E4E();
		break;
	case 34:
		sub_026E8C(&x, &y, &u);
		break;
	case 36:
	case 60:
	case 66:
	case 74:
	case 80:
		x = sub_026EE4();
		break;
	case 38:
	case 50:
		sub_026E76();
		break;
	case 40:
		sub_026F3A(&x, &y, &u);
		break;
	case 42:
		x = sub_026ED4();
		break;
	case 44:
		sub_026F79();
		break;
	case 46:
		sub_026F83(&x, &y, &u);
		break;
	case 48:
		x = sub_026EB4();
		break;
	case 52:
		sub_026FD5(&x, &y, &u);
		break;
	case 54:
		x = sub_026EC4();
		break;
	case 56:
		sub_027014();
		break;
	case 58:
		sub_02701E(&x, &y, &u);
		break;
	case 62:
		sub_026E6E();
		break;
	case 64:
		sub_027075(&x, &y, &u);
		break;
	case 68:
		sub_026E5E();
		break;
	case 70:
		sub_0270B4(&x, &y, &u);
		break;
	case 72:
		sub_0270E9(&x, &y);
		break;
	case 76:
		sub_026E56();
		break;
	case 78:
		sub_027151(&x, &y, &u);
		break;
	case -2:
		sub_026DA8(x);
		break;
	}
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

void sub_026006(uint16_t u)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, x = 0;

	unk_486A = 0u;
	if (unk_4811 != 0u)
	{
		sub_027200(&ignored16, &u);
		unk_4805 &= 0xFFu;
		unk_4804++;
		return;
	}
	x = loaded_table_027D42_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)unk_4867 << 1))
	{
	case 0:
		sub_026E32(&ignored16_2, &ignored16, &u);
		return;
	case 2:
		sub_026F1E(&ignored16_2, &ignored16, &u);
		return;
	case 4:
	case 8:
	case 14:
	case 20:
		sub_026E2F(&ignored16, &u);
		return;
	case 6:
		sub_026F5D(&ignored16_2, &ignored16, &u);
		return;
	case 10:
		sub_026FB9(&ignored16_2, &ignored16, &u);
		return;
	case 12:
		sub_026FF8(&ignored16_2, &ignored16, &u);
		return;
	case 16:
		sub_027059(&ignored16_2, &ignored16, &u);
		return;
	case 18:
		sub_027098(&ignored16_2, &ignored16, &u);
		return;
	case 22:
		sub_027135(&ignored16_2, &ignored16, &u);
		return;
	case 24:
		sub_026E4E();
		return;
	case 26:
		sub_026E8C(&ignored16_2, &ignored16, &u);
		return;
	case 28:
	case 52:
	case 58:
	case 66:
	case 72:
		sub_026EE4();
		return;
	case 30:
	case 42:
		sub_026E76();
		return;
	case 32:
		sub_026F3A(&ignored16_2, &ignored16, &u);
		return;
	case 34:
		sub_026ED4();
		return;
	case 36:
		sub_026F79();
		return;
	case 38:
		sub_026F83(&ignored16_2, &ignored16, &u);
		return;
	case 40:
		sub_026EB4();
		return;
	case 44:
		sub_026FD5(&ignored16_2, &ignored16, &u);
		return;
	case 46:
		sub_026EC4();
		return;
	case 48:
		sub_027014();
		return;
	case 50:
		sub_02701E(&ignored16_2, &ignored16, &u);
		return;
	case 54:
		sub_026E6E();
		return;
	case 56:
		sub_027075(&ignored16_2, &ignored16, &u);
		return;
	case 60:
		sub_026E5E();
		return;
	case 62:
		sub_0270B4(&ignored16_2, &ignored16, &u);
		return;
	case 64:
		sub_0270E9(&ignored16_2, &ignored16);
		return;
	case 68:
		sub_026E56();
		return;
	case 70:
		sub_027151(&ignored16_2, &ignored16, &u);
		return;
	case -10:
		sub_026DA8(x);
		return;
	case -8:
		sub_026DB8(x);
		return;
	case -6:
		sub_026DD3(x);
		return;
	case -4:
		sub_026DFA(x);
		return;
	case -2:
		sub_026E16(x);
		return;
	}
}

uint16_t sub_026009(uint16_t u)
{
	unk_48DE = 0u;
	unk_48E0 = 0u;
	u = sub_0261C1(u);
	switch ((int8_t)(uint8_t)((uint32_t)unk_4803 << 1))
	{
	case 0:
	case 6:
	case 10:
	case 20:
	case 24:
	case 28:
	case 32:
		sub_026199();
		return u;
	case 2:
		sub_02619A();
		return u;
	case 4:
	case 8:
	case 12:
	case 16:
	case 30:
		return sub_026049();
	case 14:
		return sub_02604D(u);
	case 18:
		return sub_02615E();
	case 22:
		return sub_027968();
	case 26:
		return sub_0279E6();
	case 34:
		sub_026056();
		return u;
	case 36:
		sub_026071();
		return u;
	case 38:
		sub_026096();
		return u;
	case 40:
		sub_0260A5();
		return u;
	case 42:
		return sub_0260F1(u);
	case 44:
		return sub_026110();
	case 46:
	case 48:
	case 50:
	case 52:
	case 54:
	case 56:
	case 58:
	case 60:
		return sub_026172(u);
	case 62:
		sub_026185();
		return u;
	}
	unreachable();
}

void sub_02602A(uint16_t u)
{
	uint16_t ignored16 = 0;

	sub_027200(&ignored16, &u);
}

void sub_02602D(uint16_t u)
{
	uint16_t x = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	x = loaded_table_027ED1_ADDRESS;
	t1 = io_read8(VIDEO_18E0);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_02724D(u);
		break;
	case 2:
		sub_0272CA(u);
		break;
	case 4:
		sub_027369(x);
		break;
	case 6:
		sub_0273DB(u);
		break;
	case 8:
		sub_02748A(u);
		break;
	case 10:
		sub_027523(u);
		break;
	case 12:
		sub_0273F4();
		break;
	case 14:
		sub_027417(u);
		break;
	case 16:
		sub_027448();
		break;
	case 18:
		sub_027494(x);
		break;
	case 20:
		sub_0274C8(x);
		break;
	case 22:
		sub_027534();
		break;
	case 24:
		sub_02753F();
		break;
	case 26:
	case 30:
	case 34:
	case 38:
		sub_02755C();
		break;
	case 28:
	case 32:
	case 36:
	case 40:
		sub_027573();
		break;
	case 42:
		sub_02759A(x);
		break;
	case 44:
		sub_0275C7(x);
		break;
	case 46:
		sub_0275E5(x);
		break;
	case 48:
		sub_027619(x);
		break;
	case 50:
		sub_027637(x);
		break;
	case 52:
		sub_0275D0();
		break;
	case 54:
	case 60:
	case 64:
	case 68:
		sub_027655();
		break;
	case 56:
		sub_0275EE();
		break;
	case 58:
		sub_027608(x);
		break;
	case 62:
		sub_027622();
		break;
	case 66:
		sub_027640();
		break;
	case 70:
		sub_027680(x);
		break;
	case 72:
		sub_027701(x);
		break;
	case 74:
		sub_02771E(x);
		break;
	case 76:
		sub_027689();
		break;
	case 78:
		sub_0276A3(x);
		break;
	case 80:
		sub_0276C6(x);
		break;
	case 82:
		sub_0276E3(x);
		break;
	case 84:
		sub_027700();
		break;
	case 86:
		sub_02770A();
		break;
	case 88:
	case 96:
		sub_02773B(x);
		break;
	case 90:
	case 98:
		sub_027749(x);
		break;
	case 92:
	case 100:
		sub_027766();
		break;
	case 94:
		sub_027727();
		break;
	case 102:
		sub_027773();
		break;
	case 104:
		sub_027782(x);
		break;
	case 106:
		sub_027799(x);
		break;
	case 108:
		sub_0277A6();
		break;
	case 110:
		sub_0277B8(x);
		break;
	case 112:
		sub_0277CC(x);
		break;
	}
	t2 = io_read8(VIDEO_18E2);
	if (t2 == 0u)
		return;
	t3 = io_read8(VIDEO_18E2);
	io_write8(VIDEO_18E2, 0u);
	t4 = io_read8(VIDEO_18E0);
	io_write8(VIDEO_18E0, t4 + 1u);
	t5 = io_read8(VIDEO_18E1);
	io_write8(VIDEO_18E1, 0u);
}

uint16_t sub_026030(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t1 = 0;

	u = loaded_table_027FED_ADDRESS;
	t1 = mem_read8(x + 2u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		return sub_027805(x);
	case 2:
	case 8:
		return sub_027865(x, u);
	case 4:
	case 10:
		return sub_02787F(x, u);
	case 6:
		return sub_0278A8(x);
	}
	unreachable();
}

uint16_t sub_026033(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	u = loaded_table_027FF3_ADDRESS;
	t1 = mem_read8(x + 2u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		u = sub_0278A8(x);
		break;
	case -4:
	case 2:
		u = sub_027865(x, u);
		break;
	case -2:
	case 4:
		u = sub_02787F(x, u);
		break;
	case -6:
		u = sub_027805(x);
		break;
	}
	t2 = unk_48AC;
	if ((int16_t)t2 >= 0x320)
		mem_write8(x, 0u);
	return u;
}

uint16_t sub_026049(void)
{
	uint16_t u = 0;

	u = sub_026237();
	return u;
}

uint16_t sub_02604D(uint16_t u)
{
	for (;;)
	{
		switch ((int8_t)(uint8_t)((uint32_t)unk_48AB << 1))
		{
		case 0:
			sub_026056();
			return u;
		case 2:
			sub_026071();
			return u;
		case 4:
			sub_026096();
			return u;
		case 6:
			sub_0260A5();
			return u;
		case 8:
			return sub_0260F1(u);
		case 10:
			return sub_026110();
		case 12:
		case 14:
		case 16:
		case 18:
		case 20:
		case 22:
		case 24:
		case 26:
			return sub_026172(u);
		case 28:
			break;
		case -34:
		case -28:
		case -24:
		case -14:
		case -10:
		case -6:
		case -2:
			sub_026199();
			return u;
		case -32:
			sub_02619A();
			return u;
		case -30:
		case -26:
		case -22:
		case -18:
		case -4:
			return sub_026049();
		case -20:
			continue;
		case -16:
			return sub_02615E();
		case -12:
			return sub_027968();
		case -8:
			return sub_0279E6();
		}
		break;
	}
	sub_026185();
	return u;
}

void sub_026056(void)
{
	uint32_t carry = 0;
	uint16_t d = 0;

	unk_48A9 = 1u;
	unk_489D = 1u;
	unk_48A6 = 1u;
	d = unk_5A00_ADDRESS;
	carry = sub_078680(d);
	unk_4880++;
	sub_0786BC();
	unk_48AB++;
}

void sub_026071(void)
{
	uint16_t d = 0;

	if ((((uint16_t)((uint32_t)(uint8_t)unk_4815 << 8) >> 8) & 1u) != 0u)
	{
		sub_026123();
		return;
	}
	d = unk_48E2 + 1u;
	if ((int16_t)d >= 0x90)
	{
		unk_48E2 = 0x90u;
		unk_48AB++;
		sub_026123();
		return;
	}
	unk_48E2 = d;
	sub_026123();
}

void sub_026096(void)
{
	sub_026123();
	if ((int16_t)unk_48B8 > 0x4E0)
		unk_48AB++;
}

void sub_0260A5(void)
{
	uint32_t carry = 0;
	uint8_t d = 0;
	uint16_t d_2 = 0, x = 0;
	uint16_t stack = 0;
	uint8_t t2 = 0, t3 = 0;
	uint16_t t1 = 0;

	unk_48E2--;
	sub_026123();
	if ((int16_t)unk_48B8 < 0x500)
		return;
	unk_48E2 = 0u;
	unk_48C5 = 0x500u;
	unk_48B8 = 0x500u;
	x = 0x4460u;
	unk_48F0 = 6u;
	do
	{
		unk_48F1 = 9u;
		d = 0x10u;
		stack = x;
		do
		{
			t1 = x;
			x = t1 + 1u;
			mem_write8(t1, d);
			t2 = unk_48F1;
			unk_48F1 = t2 - 1u;
		} while (t2 != 1u);
		x = stack + 0x40u;
		t3 = unk_48F0;
		unk_48F0 = t3 - 1u;
	} while (t3 != 1u);
	d_2 = 0x5B00u;
	carry = sub_078680(d_2);
	unk_48AB++;
}

uint16_t sub_0260F1(uint16_t u)
{
	uint32_t carry = 0;
	uint8_t d = 0;
	uint16_t u_2 = 0;
	uint8_t t1 = 0;

	t1 = io_read8(VIDEO_1876);
	if (t1 > 2u)
		return u;
	d = 0u;
	sub_07867D(d, &u_2, &carry);
	mem_write8(u_2 + 1u, 0x3Eu);
	d = 1u;
	sub_07867D(d, &u, &carry);
	mem_write8(u + 1u, 0xEDu);
	unk_48AB++;
	return u;
}

uint16_t sub_026110(void)
{
	uint16_t u = 0;

	u = sub_026237();
	unk_48C3 = 0x130u;
	unk_48D3 = 0x130u;
	unk_48CC = 0xFF00u;
	return u;
}

void sub_026123(void)
{
	uint32_t carry = 0;
	uint8_t a = 0, d = 0;
	uint16_t step_word = 0;
	uint16_t t1 = 0, until = 0, layer_step_word = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	t1 = stage_3_part_2_layer_offsets_ADDRESS + (int8_t)(((uint32_t)unk_488E << 1) << 1);
	step_word = t1 + 2u;
	until = LAYER_OFFSET_STEP(t1)->until;
	if ((int16_t)until <= (int16_t)unk_48C5)
	{
		unk_488E++;
		step_word += 2u;
	}
	layer_step_word = LAYER_STEP_WORD(step_word);
	unk_48CA = layer_step_word;
	t2 = AT16(unk_48B8, -1);
	t3 = unk_48E2;
	t4 = t2;
	t5 = t4 + t3;
	carry = (uint16_t)(t4 + t3) < t4;
	d = (uint8_t)t5;
	a = (uint8_t)(t5 >> 8);
	AT16(unk_48C5, -1) = ((uint32_t)a << 8) | (d & 0xFFu);
	AT16(unk_48B8, -1) = ((uint32_t)a << 8) | (d & 0xFFu);
	a = (uint8_t)(unk_48B8 >> 8u) + carry;
	unk_48B8 = (unk_48B8 & 0xFFu) | ((a & 0xFFu) << 8u);
	unk_48C5 = (unk_48C5 & 0xFFu) | ((a & 0xFFu) << 8u);
	unk_48E4 = 0u;
	unk_48E6 = 0u;
}

uint16_t sub_02615E(void)
{
	uint8_t a = 0;
	uint16_t u = 0;

	for (;;)
	{
		sub_026237();
		a = (uint32_t)unk_48AB << 1;
		u = loaded_table_027948_ADDRESS + (int8_t)((uint32_t)a << 1);
		switch ((int8_t)a)
		{
		case 0:
		case 2:
		case 4:
		case 6:
		case 8:
		case 10:
		case 12:
		case 14:
			return sub_026172(u);
		case 16:
			break;
		case -46:
		case -40:
		case -36:
		case -26:
		case -22:
		case -18:
		case -14:
			sub_026199();
			return u;
		case -44:
			sub_02619A();
			return u;
		case -42:
		case -38:
		case -34:
		case -30:
		case -16:
			return sub_026049();
		case -32:
			return sub_02604D(u);
		case -28:
			continue;
		case -24:
			return sub_027968();
		case -20:
			return sub_0279E6();
		case -12:
			sub_026056();
			return u;
		case -10:
			sub_026071();
			return u;
		case -8:
			sub_026096();
			return u;
		case -6:
			sub_0260A5();
			return u;
		case -4:
			return sub_0260F1(u);
		case -2:
			return sub_026110();
		}
		break;
	}
	sub_026185();
	return u;
}

uint16_t sub_026172(uint16_t u)
{
	uint32_t carry = 0;
	uint16_t d = 0, u_2 = 0;
	uint16_t t1 = 0;

	t1 = u;
	u_2 = t1 + 2u;
	if ((int16_t)mem_read16(t1) <= (int16_t)unk_48AC)
	{
		unk_48AB++;
		unk_4880++;
		d = mem_read16(u_2);
		carry = sub_078680(d);
	}
	return u_2;
}

void sub_026185(void)
{
}

void sub_026186(void)
{
	if ((int16_t)unk_48AC >= 0x610)
	{
		unk_48AB++;
		unk_4880++;
		sub_0786BC();
	}
}

void sub_026198(void)
{
}

void sub_026199(void)
{
}

void sub_02619A(void)
{
	uint32_t carry = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0;

	t1 = AT16(unk_48BE, -1);
	t2 = unk_48DE;
	t3 = t1;
	t4 = t3 + t2;
	carry = (uint16_t)(t3 + t2) < t3;
	AT16(unk_48BE, -1) = t4;
	unk_48BE = (unk_48BE & 0xFFu) | ((((uint16_t)(int8_t)(uint8_t)(unk_48DE >> 8u) >> 8) + (uint8_t)(unk_48BE >> 8u) + carry & 0xFFu) << 8u);
	t5 = AT16(unk_48C5, -1);
	t6 = unk_48E0;
	t7 = t5;
	t8 = t7 + t6;
	carry = (uint16_t)(t7 + t6) < t7;
	AT16(unk_48C5, -1) = t8;
	unk_48C5 = (unk_48C5 & 0xFFu) | ((((uint16_t)(int8_t)(uint8_t)(unk_48E0 >> 8u) >> 8) + (uint8_t)(unk_48C5 >> 8u) + carry & 0xFFu) << 8u);
}

uint16_t sub_0261C1(uint16_t u)
{
	switch ((int8_t)(uint8_t)((uint32_t)unk_4897 << 1))
	{
	case 0:
		sub_0261CA();
		return u;
	case 2:
		return sub_0261CB(u);
	case 4:
	case 6:
	case 8:
		return sub_0261D4(u);
	case -4:
		sub_026186();
		return u;
	case -2:
		sub_026198();
		return u;
	}
	unreachable();
}

void sub_0261CA(void)
{
}

uint16_t sub_0261CB(uint16_t u)
{
	for (;;)
	{
		switch ((int8_t)(uint8_t)((uint32_t)unk_4898 << 1))
		{
		case 0:
		case 2:
		case 4:
			break;
		case -8:
			sub_026186();
			return u;
		case -6:
			sub_026198();
			return u;
		case -4:
			sub_0261CA();
			return u;
		case -2:
			continue;
		}
		break;
	}
	return sub_0261D4(u);
}

uint16_t sub_0261D4(uint16_t u)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t shake = 0;
	uint16_t t1 = 0, pixels = 0, t2 = 0, t3 = 0, t4 = 0, pixels_2 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0;

	if (unk_4895 != 1u)
	{
		unk_4895++;
		return u;
	}
	unk_4895 = 0u;
	shake = screen_shake_steps_ADDRESS + (uint8_t)((unk_4896 & 7u) << 1);
	t1 = AT16(unk_48BE, -1);
	pixels = (((uint32_t)(uint8_t)SHAKE_STEP(shake)->pixels << 8u) | SHAKE_STEP(shake)->fraction);
	t2 = t1;
	t3 = t2 + pixels;
	carry = (uint16_t)(t2 + pixels) < t2;
	AT16(unk_48BE, -1) = t3;
	unk_48BE = (unk_48BE & 0xFFu) | ((((uint16_t)SHAKE_STEP(shake)->pixels >> 8) + (uint8_t)(unk_48BE >> 8u) + carry & 0xFFu) << 8u);
	t4 = AT16(unk_48CE, -1);
	pixels_2 = (((uint32_t)(uint8_t)SHAKE_STEP(shake)->pixels << 8u) | SHAKE_STEP(shake)->fraction);
	t5 = t4;
	t6 = t5 + pixels_2;
	carry = (uint16_t)(t5 + pixels_2) < t5;
	AT16(unk_48CE, -1) = t6;
	unk_48CE = (unk_48CE & 0xFFu) | ((((uint16_t)SHAKE_STEP(shake)->pixels >> 8) + (uint8_t)(unk_48CE >> 8u) + carry & 0xFFu) << 8u);
	t7 = (int8_t)(0u - SHAKE_STEP(shake)->pixels);
	t8 = t7 + unk_4886;
	a = (uint8_t)(t8 >> 8);
	b = (uint8_t)t8;
	unk_4886 = ((uint32_t)a << 8) | b;
	io_write16(IO_1FA0, ((uint32_t)a << 8) | b);
	unk_4896++;
	u = screen_shake_lengths_ADDRESS;
	if (unk_4896 != screen_shake_lengths[(int8_t)unk_4898])
	{
		unk_4895++;
		return u;
	}
	unk_4896 = 0u;
	unk_4897 = 0u;
	unk_4898 = 0u;
	return u;
}

uint16_t sub_026237(void)
{
	uint32_t carry = 0;
	uint16_t u = 0, x = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0, t15 = 0, t16 = 0, t17 = 0, t18 = 0;

	if (unk_48A7 != 0u)
		unk_48E4 = 0u;
	if (unk_48A8 != 0u)
		unk_48E6 = 0u;
	if (unk_48E4 != 0u && (int16_t)unk_48E4 >= 0)
		unk_4865 = 0u;
	unk_48FE &= 0xFFu;
	x = unk_48A4;
	t1 = io_read16(x + 2u);
	u = t1;
	t2 = unk_48DE;
	t3 = t2 + unk_48E4;
	unk_48DE = t3;
	t4 = unk_48E0;
	t5 = t4 - unk_48E6;
	unk_48E0 = t5;
	sub_0262E4(&x, &u);
	u = sub_0263A3(x, u);
	t6 = AT16(unk_48AC, -1);
	t7 = unk_48DE;
	t8 = t6;
	t9 = t8 + t7;
	carry = (uint16_t)(t8 + t7) < t8;
	AT16(unk_48AC, -1) = t9;
	unk_48AC = (unk_48AC & 0xFFu) | ((((uint16_t)(int8_t)(uint8_t)(unk_48DE >> 8u) >> 8) + (uint8_t)(unk_48AC >> 8u) + carry & 0xFFu) << 8u);
	t10 = AT16(unk_48B2, -1);
	t11 = unk_48E0;
	t12 = t10;
	t13 = t12 + t11;
	carry = (uint16_t)(t12 + t11) < t12;
	AT16(unk_48B2, -1) = t13;
	unk_48B2 = (unk_48B2 & 0xFFu) | ((((uint16_t)(int8_t)(uint8_t)(unk_48E0 >> 8u) >> 8) + (uint8_t)(unk_48B2 >> 8u) + carry & 0xFFu) << 8u);
	u = sub_026413(u);
	t14 = u;
	unk_48A9 = mem_read8(t14);
	t15 = t14 + 1u;
	unk_48AA = mem_read8(t15);
	t16 = t15 + 1u;
	unk_489C = mem_read8(t16);
	t17 = t16 + 1u;
	u = t17 + 1u;
	unk_489D = mem_read8(t17);
	unk_4892 = mem_read8(u);
	if ((uint8_t)(unk_48FE >> 8u) != 0u)
		unk_48A4 += 4u;
	if (unk_4899 == 0u && unk_489C != 0u)
	{
		t18 = unk_48DE;
		if ((int16_t)t18 >= 0x300)
			unk_48DE = 0x300u;
	}
	unk_48E4 = 0u;
	unk_48E6 = 0u;
	return u;
}

void sub_0262E4(uint16_t *p_x, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t u = (uint16_t)*p_u;

	if ((int16_t)unk_48DE < 0)
	{
		u += 3u;
		switch ((int8_t)(uint8_t)((uint32_t)mem_read8(u) << 1))
		{
		case 0:
			sub_026378(u);
			break;
		case -8:
		case 2:
			sub_026399();
			break;
		case 4:
			sub_026377();
			break;
		case -4:
		case 6:
			sub_026346(x, u);
			break;
		case -2:
		case 8:
			sub_02635E(x, u);
			break;
		case 10:
			sub_0263C3();
			break;
		case 12:
			sub_0263C6(u);
			break;
		case 14:
		case 22:
			sub_026409();
			break;
		case 16:
		case 24:
			sub_0263E7();
			break;
		case 18:
			sub_0263C4();
			break;
		case 20:
			sub_0263E8(u);
			break;
		case -10:
			sub_026304(u);
			break;
		case -6:
			sub_026325(&x, &u);
			break;
		}
		u += 3u;
	}
	else
	{
		switch ((int8_t)(uint8_t)((uint32_t)mem_read8(u) << 1))
		{
		case 0:
			sub_026304(u);
			break;
		case 2:
		case 12:
			sub_026399();
			break;
		case 4:
			sub_026325(&x, &u);
			break;
		case 6:
		case 16:
			sub_026346(x, u);
			break;
		case 8:
		case 18:
			sub_02635E(x, u);
			break;
		case 10:
			sub_026378(u);
			break;
		case 14:
			sub_026377();
			break;
		case 20:
			sub_0263C3();
			break;
		case 22:
			sub_0263C6(u);
			break;
		case 24:
		case 32:
			sub_026409();
			break;
		case 26:
		case 34:
			sub_0263E7();
			break;
		case 28:
			sub_0263C4();
			break;
		case 30:
			sub_0263E8(u);
			break;
		}
		u += 6u;
	}
	*p_x = x;
	*p_u = u;
}

void sub_026304(uint16_t u)
{
	uint32_t carry = 0;
	uint8_t stack = 0;
	uint8_t t5 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t6 = 0;

	t1 = unk_48DE;
	t2 = AT16(unk_48AC, -1);
	t3 = t1;
	carry = (uint16_t)(t3 + t2) < t3;
	stack = (uint16_t)(t3 + t2) >> 8;
	t4 = mem_read16(u + 1u);
	if ((int16_t)t4 <= (int16_t)(((uint32_t)(uint8_t)(((uint16_t)(int8_t)(uint8_t)(unk_48DE >> 8u) >> 8) + (uint8_t)(unk_48AC >> 8u) + carry) << 8) | stack))
	{
		t5 = mem_read8(u + 2u);
		t6 = ((uint32_t)t5 << 8) - AT16(unk_48AC, -1);
		unk_48DE = t6;
	}
}

void sub_026325(uint16_t *p_x, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint8_t stack = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	if (unk_48A7 == 0u)
		unk_4865++;
	t1 = unk_48DE;
	t2 = AT16(unk_48AC, -1);
	t3 = t1;
	carry = (uint16_t)(t3 + t2) < t3;
	stack = (uint16_t)(t3 + t2) >> 8;
	if (mem_read16(x) <= (uint16_t)(((uint32_t)(uint8_t)(((uint16_t)(int8_t)(uint8_t)(unk_48DE >> 8u) >> 8) + (uint8_t)(unk_48AC >> 8u) + carry) << 8) | stack))
		sub_0264AB(&x, &u);
	*p_x = x;
	*p_u = u;
}

void sub_026346(uint16_t x, uint16_t u)
{
	uint16_t d = 0;
	uint8_t t1 = 0;

	sub_026399();
	if ((int16_t)unk_48E0 < 0)
	{
		sub_026409();
		return;
	}
	d = unk_48E0;
	unk_48F0 = (uint8_t)(d >> 8u);
	unk_48F1 = (uint8_t)d;
	t1 = mem_read8(u + 1u);
	d = (d & 0xFFu) | ((uint32_t)t1 << 8);
	d = sub_0264E1(x, d);
	unk_48DE = d;
}

void sub_02635E(uint16_t x, uint16_t u)
{
	uint16_t d = 0;
	uint8_t t1 = 0;

	sub_026399();
	if ((int16_t)unk_48E0 >= 0)
	{
		sub_026409();
		return;
	}
	d = 0u - unk_48E0;
	unk_48F0 = (uint8_t)(d >> 8u);
	unk_48F1 = (uint8_t)d;
	t1 = mem_read8(u + 1u);
	d = (d & 0xFFu) | ((uint32_t)t1 << 8);
	d = sub_0264E1(x, d);
	unk_48DE = d;
}

void sub_026377(void)
{
}

void sub_026378(uint16_t u)
{
	uint32_t carry = 0;
	uint8_t stack = 0;
	uint8_t t5 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t6 = 0;

	t1 = unk_48DE;
	t2 = AT16(unk_48AC, -1);
	t3 = t1;
	carry = (uint16_t)(t3 + t2) < t3;
	stack = (uint16_t)(t3 + t2) >> 8;
	t4 = mem_read16(u + 1u);
	if ((int16_t)(((uint32_t)(uint8_t)(((uint16_t)(int8_t)(uint8_t)(unk_48DE >> 8u) >> 8) + (uint8_t)(unk_48AC >> 8u) + carry) << 8) | stack) <= (int16_t)t4)
	{
		t5 = mem_read8(u + 2u);
		t6 = ((uint32_t)t5 << 8) - AT16(unk_48AC, -1);
		unk_48DE = t6;
	}
}

void sub_026399(void)
{
	unk_48DE -= unk_48E4;
}

uint16_t sub_0263A3(uint16_t x, uint16_t u)
{
	if ((int16_t)unk_48E0 < 0)
	{
		u += 3u;
		switch ((int8_t)(uint8_t)((uint32_t)mem_read8(u) << 1))
		{
		case 0:
			sub_0263C4();
			break;
		case 2:
			sub_0263E8(u);
			break;
		case -4:
		case 4:
			sub_026409();
			break;
		case -2:
		case 6:
			sub_0263E7();
			break;
		case -28:
			sub_026304(u);
			break;
		case -26:
		case -16:
			sub_026399();
			break;
		case -24:
			sub_026325(&x, &u);
			break;
		case -22:
		case -12:
			sub_026346(x, u);
			break;
		case -20:
		case -10:
			sub_02635E(x, u);
			break;
		case -18:
			sub_026378(u);
			break;
		case -14:
			sub_026377();
			break;
		case -8:
			sub_0263C3();
			break;
		case -6:
			sub_0263C6(u);
			break;
		}
		u += 3u;
		return u;
	}
	switch ((int8_t)(uint8_t)((uint32_t)mem_read8(u) << 1))
	{
	case 0:
		sub_0263C3();
		break;
	case 2:
		sub_0263C6(u);
		break;
	case 4:
	case 12:
		sub_026409();
		break;
	case 6:
	case 14:
		sub_0263E7();
		break;
	case 8:
		sub_0263C4();
		break;
	case 10:
		sub_0263E8(u);
		break;
	case -20:
		sub_026304(u);
		break;
	case -18:
	case -8:
		sub_026399();
		break;
	case -16:
		sub_026325(&x, &u);
		break;
	case -14:
	case -4:
		sub_026346(x, u);
		break;
	case -12:
	case -2:
		sub_02635E(x, u);
		break;
	case -10:
		sub_026378(u);
		break;
	case -6:
		sub_026377();
		break;
	}
	u += 6u;
	return u;
}

void sub_0263C3(void)
{
}

void sub_0263C4(void)
{
}

void sub_0263C6(uint16_t u)
{
	uint32_t carry = 0;
	uint8_t stack = 0;
	uint8_t t5 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t6 = 0;

	t1 = unk_48E0;
	t2 = AT16(unk_48B2, -1);
	t3 = t1;
	carry = (uint16_t)(t3 + t2) < t3;
	stack = (uint16_t)(t3 + t2) >> 8;
	t4 = mem_read16(u + 1u);
	if ((int16_t)t4 <= (int16_t)(((uint32_t)(uint8_t)(((uint16_t)(int8_t)(uint8_t)(unk_48E0 >> 8u) >> 8) + (uint8_t)(unk_48B2 >> 8u) + carry) << 8) | stack))
	{
		t5 = mem_read8(u + 2u);
		t6 = ((uint32_t)t5 << 8) - AT16(unk_48B2, -1);
		unk_48E0 = t6;
	}
}

void sub_0263E7(void)
{
}

void sub_0263E8(uint16_t u)
{
	uint32_t carry = 0;
	uint8_t stack = 0;
	uint8_t t5 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t6 = 0;

	t1 = unk_48E0;
	t2 = AT16(unk_48B2, -1);
	t3 = t1;
	carry = (uint16_t)(t3 + t2) < t3;
	stack = (uint16_t)(t3 + t2) >> 8;
	t4 = mem_read16(u + 1u);
	if ((int16_t)(((uint32_t)(uint8_t)(((uint16_t)(int8_t)(uint8_t)(unk_48E0 >> 8u) >> 8) + (uint8_t)(unk_48B2 >> 8u) + carry) << 8) | stack) <= (int16_t)t4)
	{
		t5 = mem_read8(u + 2u);
		t6 = ((uint32_t)t5 << 8) - AT16(unk_48B2, -1);
		unk_48E0 = t6;
	}
}

void sub_026409(void)
{
	unk_48E0 += unk_48E6;
}

uint16_t sub_026413(uint16_t u)
{
	uint16_t d = 0, u_2 = 0, x = 0;
	uint8_t stack = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = u;
	u_2 = t1 + 1u;
	d = (uint32_t)mem_read8(t1) << 8;
	unk_48A6 = d >> 8;
	x = LAYER_SCROLL(layer_scrolls_ADDRESS + (int8_t)((uint16_t)((uint32_t)(uint8_t)((uint32_t)(d >> 8) << 1) << 8) >> 8) - 0x4u)->x;
	unk_48F2 = (uint8_t)(unk_48DE >> 8u);
	unk_48F3 = (uint8_t)unk_48DE;
	unk_48F4 = (uint8_t)(unk_48E0 >> 8u);
	unk_48F5 = (uint8_t)unk_48E0;
	sub_026483(x);
	x = LAYER_SCROLL(layer_scrolls_ADDRESS + ((uint16_t)((uint32_t)(uint8_t)((uint32_t)((uint16_t)((((uint16_t)((uint32_t)(uint8_t)(((uint16_t)((uint32_t)unk_48A6 << 8) >> 8) + 1u) << 8) >> 8) & 1u) << 8) >> 8) << 1) << 8) >> 8) - 0x4u)->x;
	d = unk_48DE;
	unk_48F0 = (uint8_t)(d >> 8u);
	unk_48F1 = (uint8_t)d;
	t2 = u_2;
	u_2 = t2 + 1u;
	d = (d & 0xFFu) | ((uint32_t)mem_read8(t2) << 8);
	stack = d >> 8;
	d = sub_0264E1(x, d);
	unk_48F2 = (uint8_t)(d >> 8u);
	unk_48F3 = (uint8_t)d;
	d = unk_48E0;
	unk_48F0 = (uint8_t)(d >> 8u);
	unk_48F1 = (uint8_t)d;
	d = (d & 0xFFu) | ((uint32_t)stack << 8);
	d = sub_0264E1(x, d);
	unk_48F4 = (uint8_t)(d >> 8u);
	unk_48F5 = (uint8_t)d;
	sub_026483(x);
	unk_48C3 = 0u;
	unk_48D3 = 0u;
	if ((int16_t)unk_48DE >= 0)
	{
		unk_48C3 = 0x160u;
		unk_48D3 = 0x160u;
	}
	unk_48CA = 0u;
	unk_48DA = 0u;
	if ((int16_t)unk_48E0 >= 0)
	{
		unk_48CA = 0xE0u;
		unk_48DA = 0xE0u;
	}
	return u_2;
}

void sub_026483(uint16_t scroll)
{
	uint32_t carry = 0;
	uint16_t x = 0, y = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, y_2 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0;

	x = LAYER_SCROLL(scroll)->x;
	t1 = (((uint32_t)unk_48F2 << 8u) | unk_48F3);
	t2 = io_read16(x + 1u);
	t3 = t1;
	t4 = t3 + t2;
	carry = (uint16_t)(t3 + t2) < t3;
	io_write16(x + 1u, t4);
	mem_write8(x, ((uint16_t)(int8_t)unk_48F2 >> 8) + mem_read8(x) + carry);
	y_2 = LAYER_SCROLL(scroll)->y;
	y = y_2;
	t5 = (((uint32_t)unk_48F4 << 8u) | unk_48F5);
	t6 = mem_read16(y + 1u);
	t7 = t5;
	t8 = t7 + t6;
	carry = (uint16_t)(t7 + t6) < t7;
	mem_write16(y + 1u, t8);
	mem_write8(y, ((uint16_t)(int8_t)unk_48F4 >> 8) + mem_read8(y) + carry);
}

void sub_0264AB(uint16_t *p_x, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t u = 0;
	uint16_t t1 = 0;

	x += 4u;
	unk_48A4 = x;
	t1 = mem_read16(x + 2u);
	u = t1;
	switch ((int8_t)(uint8_t)((uint32_t)mem_read8(u) << 1))
	{
	case 0:
	case 4:
		sub_0264BC();
		break;
	case 2:
		sub_0264D5(x);
		break;
	case 6:
		sub_0264BD(x);
		break;
	case 8:
		sub_0264C7(x);
		break;
	case 10:
		sub_0264E7();
		break;
	case 12:
		sub_0264EF();
		break;
	case 14:
	case 18:
		sub_0264F5();
		break;
	case 16:
		sub_0264F9();
		break;
	case 20:
		sub_0264FB();
		break;
	case 22:
		sub_026501();
		break;
	}
	*p_x = x;
	*p_u = u;
}

void sub_0264BC(void)
{
}

uint16_t sub_0264BD(uint16_t x)
{
	if ((int16_t)unk_48E0 < 0)
		sub_026409();
	unk_489F = AT16(unk_48B2, -1);
	return sub_0264D5(x);
}

uint16_t sub_0264C7(uint16_t x)
{
	if ((int16_t)unk_48E0 >= 0)
		sub_026409();
	unk_489F = AT16(unk_48B2, -1);
	return sub_0264D5(x);
}

uint16_t sub_0264D5(uint16_t x)
{
	uint8_t a = 0, b = 0;
	uint16_t d = 0;
	uint16_t t1 = 0;

	t1 = ((uint32_t)mem_read8(x - 3u) << 8) - AT16(unk_48AC, -1);
	b = (uint8_t)t1;
	a = (t1 >> 8) + 1u;
	unk_48DE = ((uint32_t)a << 8) | b;
	d = ((uint32_t)a << 8) | b;
	return d;
}

uint16_t sub_0264E1(uint16_t x, uint16_t d)
{
	uint8_t a = 0;
	uint16_t d_2 = 0;

	a = (uint32_t)(d >> 8) << 1;
	switch ((int8_t)a)
	{
	case 0:
		return sub_0264F9();
	case -2:
	case 2:
		return sub_0264F5();
	case 4:
		return sub_0264FB();
	case 6:
		return sub_026501();
	case -16:
	case -12:
		d_2 = (d & 0xFFu) | ((uint32_t)a << 8);
		sub_0264BC();
		return d_2;
	case -14:
		return sub_0264D5(x);
	case -10:
		return sub_0264BD(x);
	case -8:
		return sub_0264C7(x);
	case -6:
		return sub_0264E7();
	case -4:
		return sub_0264EF();
	}
	unreachable();
}

uint16_t sub_0264E7(void)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0;
	uint16_t t1 = 0;

	t1 = (((uint32_t)unk_48F0 << 8u) | unk_48F1);
	a = (uint8_t)(t1 >> 8);
	carry = a & 1u;
	a = (int8_t)a >> 1;
	b = ((uint8_t)t1 >> 1) | (carry << 7);
	carry = a & 1u;
	d = ((uint32_t)(uint8_t)((int8_t)a >> 1) << 8) | (uint8_t)((b >> 1) | (carry << 7));
	return d;
}

uint16_t sub_0264EF(void)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d = 0;
	uint16_t t1 = 0;

	t1 = (((uint32_t)unk_48F0 << 8u) | unk_48F1);
	a = (uint8_t)(t1 >> 8);
	carry = a & 1u;
	d = ((uint32_t)(uint8_t)((int8_t)a >> 1) << 8) | (uint8_t)(((uint8_t)t1 >> 1) | (carry << 7));
	return d;
}

uint16_t sub_0264F5(void)
{
	uint16_t d = 0;

	d = (((uint32_t)unk_48F0 << 8u) | unk_48F1);
	return d;
}

uint16_t sub_0264F9(void)
{
	uint16_t d = 0;

	d = 0u;
	return d;
}

uint16_t sub_0264FB(void)
{
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t d = 0;
	uint16_t t1 = 0;

	t1 = (((uint32_t)unk_48F0 << 8u) | unk_48F1);
	b = (uint8_t)t1;
	carry = (int8_t)b < 0;
	d = ((uint32_t)(uint8_t)(((uint32_t)(t1 >> 8) << 1) | carry) << 8) | (uint8_t)((uint32_t)b << 1);
	return d;
}

uint16_t sub_026501(void)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0;
	uint16_t t1 = 0;

	t1 = (((uint32_t)unk_48F0 << 8u) | unk_48F1);
	b = (uint8_t)t1;
	carry = (int8_t)b < 0;
	b = (uint32_t)b << 1;
	a = (uint8_t)(((uint32_t)(t1 >> 8) << 1) | carry);
	carry = (int8_t)b < 0;
	d = ((uint32_t)(uint8_t)(((uint32_t)a << 1) | carry) << 8) | (uint8_t)((uint32_t)b << 1);
	return d;
}

void sub_026532(uint16_t *p_x, uint16_t *p_y)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t u = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0, t3 = 0;

	u = loaded_table_027C70_ADDRESS;
	t1 = mem_read8(x + 0x28u);
	a = t1;
	carry = (int8_t)a < 0;
	switch ((int8_t)(uint8_t)((uint32_t)a << 1))
	{
	case 0:
		sub_02653D(x);
		break;
	case 2:
		sub_026554(x);
		break;
	case 4:
		sub_026563(x);
		break;
	case 6:
		sub_026573(x);
		break;
	case 8:
		sub_0265C7(x);
		break;
	case 10:
		sub_0265FE(x, u);
		break;
	case 12:
		y = sub_026611(x, y, u);
		break;
	case 14:
		sub_026692(x);
		break;
	case 16:
		sub_0266B3(x);
		break;
	case 18:
		sub_0266DA(x);
		break;
	case 20:
		sub_026702(x);
		break;
	case 22:
		sub_026721(&x, &y);
		break;
	case 24:
		sub_02675A(x);
		break;
	case 26:
		sub_026772(x);
		break;
	case 28:
		y = sub_0267AD(x, y, u);
		break;
	case 30:
		sub_0267C9(x);
		break;
	case 32:
		sub_026838(&x, &y);
		break;
	case 34:
		sub_02687B(x);
		break;
	case 36:
		sub_02688C(x);
		break;
	case 38:
		sub_026895(x, u);
		break;
	case 40:
		sub_0268C1(x);
		break;
	case 42:
		sub_0268F5(&x, &y);
		break;
	case 44:
		y = sub_026A45(u, carry);
		break;
	case 46:
		y = sub_026A55(u, carry);
		break;
	case 48:
		y = sub_026A4D(u, carry);
		break;
	case 50:
		sub_026A8F(x);
		break;
	case 52:
		sub_026AA3(x);
		break;
	case 54:
		sub_026AB7(x);
		break;
	case 56:
		sub_026AD3(x);
		break;
	case 58:
		sub_026B00(x);
		break;
	case 60:
		y = sub_026B14(x, y, u);
		break;
	case -18:
		sub_026532(&x, &y);
		break;
	case -16:
		sub_0265BE(&x, &y);
		break;
	case -14:
		sub_026601(&x, &y);
		break;
	case -12:
		sub_026608(&x, &y);
		break;
	case -10:
		y = sub_02672A(x, y);
		break;
	case -8:
		sub_026751(&x, &y);
		break;
	case -6:
		sub_0267C0(&x, &y);
		break;
	case -4:
		sub_0268B8(&x, &y);
		break;
	case -2:
		y = sub_0268F8(x, y);
		break;
	}
	mem_write16(x + 0xFu, 0x400u);
	t2 = mem_read16(x + 0xCu);
	if ((int16_t)t2 > 0xD0)
	{
		t3 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t3);
	}
	*p_x = x;
	*p_y = y;
}

void sub_02653D(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = mem_read8(x + 0xAu);
	if (t1 < 0x20u)
	{
		mem_write8(x + 0x29u, 0x20u);
		t2 = mem_read8(x + 0x28u);
		mem_write8(x + 0x28u, t2 + 1u);
		return;
	}
	t3 = mem_read8(x + 0xAu);
	mem_write8(x + 0xAu, t3 - 1u);
	t4 = mem_read8(x + 0xBu);
	mem_write8(x + 0xBu, t4 - 1u);
}

void sub_026554(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 - 1u);
	if (t1 == 1u)
	{
		io_write8(VIDEO_184B, 1u);
		t2 = mem_read8(x + 0x28u);
		mem_write8(x + 0x28u, t2 + 1u);
	}
}

void sub_026563(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = io_read8(VIDEO_184E);
	if (t1 != 0u)
	{
		unk_4885 = unk_4850;
		t2 = mem_read8(x + 0x28u);
		mem_write8(x + 0x28u, t2 + 1u);
	}
}

void sub_026573(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0;
	uint8_t t1 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry == 0u)
		return;
	t1 = mem_read8(x + 0x27u);
	mem_write8(x + 0x27u, t1 | 0x81u);
	d = 0u;
	carry = sub_078680(d);
	d = 0x6C00u;
	carry = sub_078680(d);
	unk_4897 = 1u;
	unk_4898 = 0u;
	io_write16(VIDEO_1852, x);
	unk_487D = 1u;
	unk_4804++;
	unk_4805 = 0x100u;
}

void sub_0265BE(uint16_t *p_x, uint16_t *p_y)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_027C78_ADDRESS;
		t1 = mem_read8(x + 0x28u);
		a = t1;
		carry = (int8_t)a < 0;
		switch ((int8_t)(uint8_t)((uint32_t)a << 1))
		{
		case 0:
			sub_0265C7(x);
			break;
		case 2:
			sub_0265FE(x, u);
			break;
		case 4:
			y = sub_026611(x, y, u);
			break;
		case 6:
			sub_026692(x);
			break;
		case 8:
			sub_0266B3(x);
			break;
		case 10:
			sub_0266DA(x);
			break;
		case 12:
			sub_026702(x);
			break;
		case 14:
			sub_026721(&x, &y);
			break;
		case 16:
			sub_02675A(x);
			break;
		case 18:
			sub_026772(x);
			break;
		case 20:
			y = sub_0267AD(x, y, u);
			break;
		case 22:
			sub_0267C9(x);
			break;
		case 24:
			sub_026838(&x, &y);
			break;
		case 26:
			sub_02687B(x);
			break;
		case 28:
			sub_02688C(x);
			break;
		case 30:
			sub_026895(x, u);
			break;
		case 32:
			sub_0268C1(x);
			break;
		case 34:
			sub_0268F5(&x, &y);
			break;
		case 36:
			y = sub_026A45(u, carry);
			break;
		case 38:
			y = sub_026A55(u, carry);
			break;
		case 40:
			y = sub_026A4D(u, carry);
			break;
		case 42:
			sub_026A8F(x);
			break;
		case 44:
			sub_026AA3(x);
			break;
		case 46:
			sub_026AB7(x);
			break;
		case 48:
			sub_026AD3(x);
			break;
		case 50:
			sub_026B00(x);
			break;
		case 52:
			y = sub_026B14(x, y, u);
			break;
		case -26:
			sub_026532(&x, &y);
			break;
		case -24:
			continue;
		case -22:
			sub_026601(&x, &y);
			break;
		case -20:
			sub_026608(&x, &y);
			break;
		case -18:
			y = sub_02672A(x, y);
			break;
		case -16:
			sub_026751(&x, &y);
			break;
		case -14:
			sub_0267C0(&x, &y);
			break;
		case -12:
			sub_0268B8(&x, &y);
			break;
		case -10:
			y = sub_0268F8(x, y);
			break;
		case -8:
			sub_02653D(x);
			break;
		case -6:
			sub_026554(x);
			break;
		case -4:
			sub_026563(x);
			break;
		case -2:
			sub_026573(x);
			break;
		}
		break;
	}
	*p_x = x;
	*p_y = y;
}

void sub_0265C7(uint16_t x)
{
	uint8_t a = 0, b = 0;
	uint8_t t5 = 0, t6 = 0, t8 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t7 = 0;

	t1 = mem_read16(x + 0x16u);
	if ((int16_t)t1 < 0x80)
	{
		t2 = mem_read16(x + 0xCu);
		a = (uint8_t)(t2 >> 8);
		b = (uint8_t)t2;
		if ((int16_t)(((uint32_t)a << 8) | b) < 0x40 || (int16_t)(((uint32_t)a << 8) | b) > 0x17F)
		{
			t3 = mem_read16(x + 0xFu);
			t4 = 0u - t3;
			mem_write16(x + 0xFu, t4);
			return;
		}
		return;
	}
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x19u, 0u);
	t5 = mem_read8(x + 0x1Bu);
	if (krusty_balloon_beaten_health_by_players[(int8_t)((uint8_t)(unk_4857 - 1u))] < t5)
	{
		t6 = mem_read8(x + 0x28u);
		mem_write8(x + 0x28u, t6 + 1u);
		t2 = mem_read16(x + 0xCu);
		a = (uint8_t)(t2 >> 8);
		b = (uint8_t)t2;
		if ((int16_t)(((uint32_t)a << 8) | b) < 0x40 || (int16_t)(((uint32_t)a << 8) | b) > 0x17F)
		{
			t3 = mem_read16(x + 0xFu);
			t4 = 0u - t3;
			mem_write16(x + 0xFu, t4);
			return;
		}
		return;
	}
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write16(x + 0x19u, 0u);
	t7 = mem_read16(x + 0x25u);
	t8 = mem_read8(t7 + 0x5Bu);
	mem_write8(x + 0x27u, t8 & ~0xFu);
	mem_write8(x + 0x1Bu, 0u);
	mem_write8(x + 2u, 0xFDu);
	mem_write8(x + 0x28u, 0u);
	mem_write8(x + 0x35u, 0u);
}

void sub_0265FE(uint16_t x, uint16_t u)
{
	sub_026CAA(x, u);
}

void sub_026601(uint16_t *p_x, uint16_t *p_y)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;

	sub_026A74(&x, &y, &carry);
	if (carry)
		sub_026B33(x);
	*p_x = x;
	*p_y = y;
}

void sub_026608(uint16_t *p_x, uint16_t *p_y)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_027C7C_ADDRESS;
		t1 = mem_read8(x + 0x28u);
		a = t1;
		carry = (int8_t)a < 0;
		switch ((int8_t)(uint8_t)((uint32_t)a << 1))
		{
		case 0:
			y = sub_026611(x, y, u);
			break;
		case 2:
			sub_026692(x);
			break;
		case 4:
			sub_0266B3(x);
			break;
		case 6:
			sub_0266DA(x);
			break;
		case 8:
			sub_026702(x);
			break;
		case 10:
			sub_026721(&x, &y);
			break;
		case 12:
			sub_02675A(x);
			break;
		case 14:
			sub_026772(x);
			break;
		case 16:
			y = sub_0267AD(x, y, u);
			break;
		case 18:
			sub_0267C9(x);
			break;
		case 20:
			sub_026838(&x, &y);
			break;
		case 22:
			sub_02687B(x);
			break;
		case 24:
			sub_02688C(x);
			break;
		case 26:
			sub_026895(x, u);
			break;
		case 28:
			sub_0268C1(x);
			break;
		case 30:
			sub_0268F5(&x, &y);
			break;
		case 32:
			y = sub_026A45(u, carry);
			break;
		case 34:
			y = sub_026A55(u, carry);
			break;
		case 36:
			y = sub_026A4D(u, carry);
			break;
		case 38:
			sub_026A8F(x);
			break;
		case 40:
			sub_026AA3(x);
			break;
		case 42:
			sub_026AB7(x);
			break;
		case 44:
			sub_026AD3(x);
			break;
		case 46:
			sub_026B00(x);
			break;
		case 48:
			y = sub_026B14(x, y, u);
			break;
		case -30:
			sub_026532(&x, &y);
			break;
		case -28:
			sub_0265BE(&x, &y);
			break;
		case -26:
			sub_026601(&x, &y);
			break;
		case -24:
			continue;
		case -22:
			y = sub_02672A(x, y);
			break;
		case -20:
			sub_026751(&x, &y);
			break;
		case -18:
			sub_0267C0(&x, &y);
			break;
		case -16:
			sub_0268B8(&x, &y);
			break;
		case -14:
			y = sub_0268F8(x, y);
			break;
		case -12:
			sub_02653D(x);
			break;
		case -10:
			sub_026554(x);
			break;
		case -8:
			sub_026563(x);
			break;
		case -6:
			sub_026573(x);
			break;
		case -4:
			sub_0265C7(x);
			break;
		case -2:
			sub_0265FE(x, u);
			break;
		}
		break;
	}
	*p_x = x;
	*p_y = y;
}

uint16_t sub_026611(uint16_t x, uint16_t y, uint16_t u)
{
	uint16_t d = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	mem_write8(x + 0x57u, 1u);
	if (unk_4892 != 0u)
		return y;
	mem_write8(x, 0x98u);
	mem_write8(x + 0x5Bu, 1u);
	d = 0u;
	sub_026969(x, d);
	d = 0u;
	sub_026978(x, d);
	mem_write16(x + 0xCu, VIDEO_00C0);
	t1 = 0x100u + unk_48B2;
	mem_write16(x + 0x11u, t1);
	mem_write16(x + 0x16u, rom_07FFC0_ADDRESS);
	mem_write16(x + 0x19u, 0x100u);
	mem_write8(x + 0xAu, 0x60u);
	mem_write8(x + 0xBu, 0x60u);
	mem_write8(x + 9u, 0x20u);
	mem_write8(x + 0x29u, 0x80u);
	mem_write8(x + 0x5Bu, 1u);
	mem_write8(x + 0x1Bu, 0xA0u);
	mem_write8(x + VIDEO_002F, 0xA0u);
	mem_write8(x + 0x57u, 0u);
	unk_487E = 2u;
	d = 0x18u;
	sub_078677(d, &y, &u);
	unk_487E = 2u;
	d = 0x19u;
	sub_078677(d, &y, &u);
	unk_487E = 2u;
	d = 0x1Au;
	sub_078677(d, &y, &u);
	unk_487C++;
	t2 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t2 + 1u);
	return y;
}

void sub_026692(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 - 1u);
	if (t1 != 1u)
		return;
	d = 0x7900u;
	carry = sub_078689(d);
	mem_write16(x + 0x14u, 0xFF80u);
	mem_write8(x + 0x29u, 0xC0u);
	mem_write8(x + 9u, 0u);
	mem_write16(x + 0x19u, 0u);
	t2 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t2 + 1u);
}

void sub_0266B3(uint16_t x)
{
	uint8_t a = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(x + 0x14u, 0x80u);
		mem_write8(x + 0x29u, 0x50u);
		t2 = mem_read8(x + 0x28u);
		mem_write8(x + 0x28u, t2 + 1u);
		return;
	}
	if ((unk_4815 & 3u) == 0u)
	{
		t3 = mem_read8(x + 0xAu);
		a = t3 - 1u;
		mem_write8(x + 0xAu, a);
		mem_write8(x + 0xBu, a);
	}
}

void sub_0266DA(uint16_t x)
{
	uint8_t a = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 - 1u);
	if (t1 != 1u)
	{
		if ((unk_4815 & 3u) == 0u)
		{
			t2 = mem_read8(x + 0xAu);
			a = t2 + 1u;
			mem_write8(x + 0xAu, a);
			mem_write8(x + 0xBu, a);
		}
		return;
	}
	mem_write8(x + 0xAu, 0x40u);
	mem_write8(x + 0xBu, 0x40u);
	mem_write16(x + 0x14u, 0u);
	t3 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t3 + 1u);
}

void sub_026702(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0;
	uint8_t t1 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry == 0u)
		return;
	d = 0x6500u;
	carry = sub_078680(d);
	unk_4897 = 1u;
	mem_write8(x, mem_read8(x) | 0x48u);
	d = 0x100u;
	sub_026978(x, d);
	t1 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t1 + 1u);
}

void sub_026721(uint16_t *p_x, uint16_t *p_y)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t u = 0, y_2 = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		mem_write8(x, mem_read8(x) & 0xBFu);
		u = loaded_table_027CAA_ADDRESS;
		t1 = mem_read8(x + 0x35u);
		a = t1;
		carry = (int8_t)a < 0;
		switch ((int8_t)(uint8_t)((uint32_t)a << 1))
		{
		case 0:
			sub_026B00(x);
			*p_x = x;
			*p_y = y;
			return;
		case 2:
			break;
		case -76:
			*p_x = x;
			*p_y = y;
			sub_026532(p_x, p_y);
			return;
		case -74:
			*p_x = x;
			*p_y = y;
			sub_0265BE(p_x, p_y);
			return;
		case -72:
			*p_x = x;
			*p_y = y;
			sub_026601(p_x, p_y);
			return;
		case -70:
			*p_x = x;
			*p_y = y;
			sub_026608(p_x, p_y);
			return;
		case -68:
			y = sub_02672A(x, y);
			*p_x = x;
			*p_y = y;
			return;
		case -66:
			*p_x = x;
			*p_y = y;
			sub_026751(p_x, p_y);
			return;
		case -64:
			*p_x = x;
			*p_y = y;
			sub_0267C0(p_x, p_y);
			return;
		case -62:
			*p_x = x;
			*p_y = y;
			sub_0268B8(p_x, p_y);
			return;
		case -60:
			y = sub_0268F8(x, y);
			*p_x = x;
			*p_y = y;
			return;
		case -58:
			sub_02653D(x);
			*p_x = x;
			*p_y = y;
			return;
		case -56:
			sub_026554(x);
			*p_x = x;
			*p_y = y;
			return;
		case -54:
			sub_026563(x);
			*p_x = x;
			*p_y = y;
			return;
		case -52:
			sub_026573(x);
			*p_x = x;
			*p_y = y;
			return;
		case -50:
			sub_0265C7(x);
			*p_x = x;
			*p_y = y;
			return;
		case -48:
			sub_0265FE(x, u);
			*p_x = x;
			*p_y = y;
			return;
		case -46:
			y = sub_026611(x, y, u);
			*p_x = x;
			*p_y = y;
			return;
		case -44:
			sub_026692(x);
			*p_x = x;
			*p_y = y;
			return;
		case -42:
			sub_0266B3(x);
			*p_x = x;
			*p_y = y;
			return;
		case -40:
			sub_0266DA(x);
			*p_x = x;
			*p_y = y;
			return;
		case -38:
			sub_026702(x);
			*p_x = x;
			*p_y = y;
			return;
		case -36:
			continue;
		case -34:
			sub_02675A(x);
			*p_x = x;
			*p_y = y;
			return;
		case -32:
			sub_026772(x);
			*p_x = x;
			*p_y = y;
			return;
		case -30:
			y = sub_0267AD(x, y, u);
			*p_x = x;
			*p_y = y;
			return;
		case -28:
			sub_0267C9(x);
			*p_x = x;
			*p_y = y;
			return;
		case -26:
			*p_x = x;
			*p_y = y;
			sub_026838(p_x, p_y);
			return;
		case -24:
			sub_02687B(x);
			*p_x = x;
			*p_y = y;
			return;
		case -22:
			sub_02688C(x);
			*p_x = x;
			*p_y = y;
			return;
		case -20:
			sub_026895(x, u);
			*p_x = x;
			*p_y = y;
			return;
		case -18:
			sub_0268C1(x);
			*p_x = x;
			*p_y = y;
			return;
		case -16:
			*p_x = x;
			*p_y = y;
			sub_0268F5(p_x, p_y);
			return;
		case -14:
			y_2 = sub_026A45(u, carry);
			*p_x = x;
			*p_y = y_2;
			return;
		case -12:
			y_2 = sub_026A55(u, carry);
			*p_x = x;
			*p_y = y_2;
			return;
		case -10:
			y_2 = sub_026A4D(u, carry);
			*p_x = x;
			*p_y = y_2;
			return;
		case -8:
			sub_026A8F(x);
			*p_x = x;
			*p_y = y;
			return;
		case -6:
			sub_026AA3(x);
			*p_x = x;
			*p_y = y;
			return;
		case -4:
			sub_026AB7(x);
			*p_x = x;
			*p_y = y;
			return;
		case -2:
			sub_026AD3(x);
			*p_x = x;
			*p_y = y;
			return;
		}
		break;
	}
	y = sub_026B14(x, y, u);
	*p_x = x;
	*p_y = y;
}

uint16_t sub_02672A(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t d = 0, u = 0;
	uint8_t t1 = 0, t2 = 0;

	sub_02693A(x, &u, &carry);
	if (carry)
		return y;
	sub_0269B9(x, y, u);
	t1 = mem_read8(x + 5u);
	if (t1 != 1u)
	{
		d = 0x100u;
		sub_026969(x, d);
	}
	sub_02699B(x);
	t2 = mem_read8(x + 0x2Du);
	y = krusty_balloon_speeds_by_rank_ADDRESS;
	d = ((uint32_t)t2 << 8) | krusty_balloon_speeds_by_rank[unk_4861 >> 1];
	sub_078617(x, d);
	return y;
}

void sub_026751(uint16_t *p_x, uint16_t *p_y)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_027C88_ADDRESS;
		t1 = mem_read8(x + 0x28u);
		a = t1;
		carry = (int8_t)a < 0;
		switch ((int8_t)(uint8_t)((uint32_t)a << 1))
		{
		case 0:
			sub_02675A(x);
			break;
		case 2:
			sub_026772(x);
			break;
		case 4:
			y = sub_0267AD(x, y, u);
			break;
		case 6:
			sub_0267C9(x);
			break;
		case 8:
			sub_026838(&x, &y);
			break;
		case 10:
			sub_02687B(x);
			break;
		case 12:
			sub_02688C(x);
			break;
		case 14:
			sub_026895(x, u);
			break;
		case 16:
			sub_0268C1(x);
			break;
		case 18:
			sub_0268F5(&x, &y);
			break;
		case 20:
			y = sub_026A45(u, carry);
			break;
		case 22:
			y = sub_026A55(u, carry);
			break;
		case 24:
			y = sub_026A4D(u, carry);
			break;
		case 26:
			sub_026A8F(x);
			break;
		case 28:
			sub_026AA3(x);
			break;
		case 30:
			sub_026AB7(x);
			break;
		case 32:
			sub_026AD3(x);
			break;
		case 34:
			sub_026B00(x);
			break;
		case 36:
			y = sub_026B14(x, y, u);
			break;
		case -42:
			sub_026532(&x, &y);
			break;
		case -40:
			sub_0265BE(&x, &y);
			break;
		case -38:
			sub_026601(&x, &y);
			break;
		case -36:
			sub_026608(&x, &y);
			break;
		case -34:
			y = sub_02672A(x, y);
			break;
		case -32:
			continue;
		case -30:
			sub_0267C0(&x, &y);
			break;
		case -28:
			sub_0268B8(&x, &y);
			break;
		case -26:
			y = sub_0268F8(x, y);
			break;
		case -24:
			sub_02653D(x);
			break;
		case -22:
			sub_026554(x);
			break;
		case -20:
			sub_026563(x);
			break;
		case -18:
			sub_026573(x);
			break;
		case -16:
			sub_0265C7(x);
			break;
		case -14:
			sub_0265FE(x, u);
			break;
		case -12:
			y = sub_026611(x, y, u);
			break;
		case -10:
			sub_026692(x);
			break;
		case -8:
			sub_0266B3(x);
			break;
		case -6:
			sub_0266DA(x);
			break;
		case -4:
			sub_026702(x);
			break;
		case -2:
			sub_026721(&x, &y);
			break;
		}
		break;
	}
	*p_x = x;
	*p_y = y;
}

void sub_02675A(uint16_t x)
{
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
	sub_026969(x, d);
	mem_write8(x, mem_read8(x) | 4u);
	t3 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t3 + 1u);
}

void sub_026772(uint16_t x)
{
	uint8_t a = 0;
	uint16_t d = 0, u = 0, x_2 = 0;
	uint16_t stack = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x38u);
	u = t1;
	mem_write8(u, mem_read8(u) & 0xBFu);
	a = 0u;
	t2 = mem_read8(x + 6u);
	if ((t2 & 2u) != 0u)
	{
		mem_write8(u, mem_read8(u) | 0x40u);
		stack = x;
		x_2 = u;
		d = 0x400u;
		sub_026978(x_2, d);
		x = stack;
		a = 1u;
	}
	d = (uint32_t)a << 8;
	sub_026978(x, d);
	t3 = mem_read8(x + 6u);
	if ((t3 & 1u) == 0u)
		return;
	d = 0u;
	sub_026978(x, d);
	mem_write8(x + 0x29u, 0x20u);
	t4 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t4 + 1u);
}

uint16_t sub_0267AD(uint16_t x, uint16_t y, uint16_t u)
{
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 - 1u);
	if (t1 != 1u)
		return y;
	t2 = mem_read16(x + 0x38u);
	mem_write8(t2, 0u);
	mem_write16(x + 0x38u, 0u);
	sub_026B33(x);
	y = sub_0269B9(x, y, u);
	return y;
}

void sub_0267C0(uint16_t *p_x, uint16_t *p_y)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_027C8E_ADDRESS;
		t1 = mem_read8(x + 0x28u);
		a = t1;
		carry = (int8_t)a < 0;
		switch ((int8_t)(uint8_t)((uint32_t)a << 1))
		{
		case 0:
			sub_0267C9(x);
			break;
		case 2:
			sub_026838(&x, &y);
			break;
		case 4:
			sub_02687B(x);
			break;
		case 6:
			sub_02688C(x);
			break;
		case 8:
			sub_026895(x, u);
			break;
		case 10:
			sub_0268C1(x);
			break;
		case 12:
			sub_0268F5(&x, &y);
			break;
		case 14:
			y = sub_026A45(u, carry);
			break;
		case 16:
			y = sub_026A55(u, carry);
			break;
		case 18:
			y = sub_026A4D(u, carry);
			break;
		case 20:
			sub_026A8F(x);
			break;
		case 22:
			sub_026AA3(x);
			break;
		case 24:
			sub_026AB7(x);
			break;
		case 26:
			sub_026AD3(x);
			break;
		case 28:
			sub_026B00(x);
			break;
		case 30:
			y = sub_026B14(x, y, u);
			break;
		case -48:
			sub_026532(&x, &y);
			break;
		case -46:
			sub_0265BE(&x, &y);
			break;
		case -44:
			sub_026601(&x, &y);
			break;
		case -42:
			sub_026608(&x, &y);
			break;
		case -40:
			y = sub_02672A(x, y);
			break;
		case -38:
			sub_026751(&x, &y);
			break;
		case -36:
			continue;
		case -34:
			sub_0268B8(&x, &y);
			break;
		case -32:
			y = sub_0268F8(x, y);
			break;
		case -30:
			sub_02653D(x);
			break;
		case -28:
			sub_026554(x);
			break;
		case -26:
			sub_026563(x);
			break;
		case -24:
			sub_026573(x);
			break;
		case -22:
			sub_0265C7(x);
			break;
		case -20:
			sub_0265FE(x, u);
			break;
		case -18:
			y = sub_026611(x, y, u);
			break;
		case -16:
			sub_026692(x);
			break;
		case -14:
			sub_0266B3(x);
			break;
		case -12:
			sub_0266DA(x);
			break;
		case -10:
			sub_026702(x);
			break;
		case -8:
			sub_026721(&x, &y);
			break;
		case -6:
			sub_02675A(x);
			break;
		case -4:
			sub_026772(x);
			break;
		case -2:
			y = sub_0267AD(x, y, u);
			break;
		}
		break;
	}
	*p_x = x;
	*p_y = y;
}

void sub_0267C9(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d = 0;
	uint8_t t8 = 0, t12 = 0, t13 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t9 = 0, t10 = 0, t11 = 0;

	mem_write8(x + 0x36u, 0u);
	t1 = mem_read16(x + 0xCu);
	t2 = t1 - 0xE0u;
	t3 = t2;
	t4 = t3 >> 15 ? 0u - t3 : t3;
	if ((int16_t)t4 > 0x10)
		mem_write16(x + 0xFu, 0u);
	t5 = 0x100u + unk_48B2;
	t6 = mem_read16(x + 0x11u);
	if ((int16_t)t5 <= (int16_t)t6)
		mem_write16(x + 0x14u, 0u);
	t7 = mem_read16(x + 0x16u);
	if ((int16_t)t7 >= 0x38)
		mem_write16(x + 0x19u, 0u);
	t8 = mem_read8(x + 0xAu);
	a = t8;
	if (a <= 0x60u)
	{
		a++;
		mem_write8(x + 0xAu, a);
		mem_write8(x + 0xBu, a);
	}
	t9 = mem_read16(x + 0xFu);
	if (t9 == 0u)
	{
		t10 = mem_read16(x + 0x14u);
		if (t10 == 0u)
		{
			t11 = mem_read16(x + 0x19u);
			if (t11 == 0u)
			{
				t12 = mem_read8(x + 0xAu);
				if (t12 > 0x60u)
				{
					d = 0x7900u;
					carry = sub_078680(d);
					mem_write8(x, mem_read8(x) & ~8u);
					mem_write8(x + VIDEO_0031, 0u);
					mem_write8(x + 0x29u, 4u);
					mem_write8(x + 0x32u, 0u);
					t13 = mem_read8(x + 0x28u);
					mem_write8(x + 0x28u, t13 + 1u);
				}
			}
		}
	}
}

void sub_026838(uint16_t *p_x, uint16_t *p_y)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0;

	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 - 1u);
	if (t1 == 1u)
	{
		t2 = mem_read8(x + VIDEO_0031);
		mem_write8(x + VIDEO_0031, t2 + 1u);
		t3 = mem_read8(x + VIDEO_0031);
		if (t3 == 0xCu)
		{
			d = 0u;
			sub_026969(x, d);
			mem_write8(x + 0x29u, 1u);
			t4 = mem_read8(x + 0x28u);
			mem_write8(x + 0x28u, t4 + 1u);
		}
		else
		{
			t5 = mem_read8(x + 0x32u);
			d = (uint32_t)t5 << 8;
			sub_0269E0(d, &x, &y, &carry);
			if (carry)
			{
				d = 0u;
				sub_026969(x, d);
				mem_write8(x + 0x29u, 1u);
				t4 = mem_read8(x + 0x28u);
				mem_write8(x + 0x28u, t4 + 1u);
			}
			else
			{
				t6 = mem_read8(x + 0x32u);
				d = (uint32_t)(uint8_t)(4u + t6) << 8;
				sub_026969(x, d);
				t7 = mem_read8(x + 0x32u);
				a = t7 + 1u;
				if (a == 3u)
					a = 0u;
				mem_write8(x + 0x32u, a);
				mem_write8(x + 0x29u, (unk_4858 & 7u) + 4u);
			}
		}
	}
	*p_x = x;
	*p_y = y;
}

void sub_02687B(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 0x29u, 0x40u);
		t2 = mem_read8(x + 0x36u);
		mem_write8(x + 0x36u, t2 + 1u);
		t3 = mem_read8(x + 0x28u);
		mem_write8(x + 0x28u, t3 + 1u);
	}
}

void sub_02688C(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 - 1u);
	if (t1 == 1u)
	{
		t2 = mem_read8(x + 0x28u);
		mem_write8(x + 0x28u, t2 + 1u);
	}
}

void sub_026895(uint16_t x, uint16_t u)
{
	uint8_t a = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 0xAu);
	a = t1 - 1u;
	if (a > 0x40u)
	{
		mem_write8(x + 0xAu, a);
		mem_write8(x + 0xBu, a);
		return;
	}
	t2 = 0xFFu - unk_48B2;
	mem_write16(x + 0x11u, t2);
	mem_write8(x + 0xAu, 0x40u);
	mem_write8(x + 0xBu, 0x40u);
	sub_026CAA(x, u);
}

void sub_0268B8(uint16_t *p_x, uint16_t *p_y)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_027C98_ADDRESS;
		t1 = mem_read8(x + 0x28u);
		a = t1;
		carry = (int8_t)a < 0;
		switch ((int8_t)(uint8_t)((uint32_t)a << 1))
		{
		case 0:
			sub_0268C1(x);
			break;
		case 2:
			sub_0268F5(&x, &y);
			break;
		case 4:
			y = sub_026A45(u, carry);
			break;
		case 6:
			y = sub_026A55(u, carry);
			break;
		case 8:
			y = sub_026A4D(u, carry);
			break;
		case 10:
			sub_026A8F(x);
			break;
		case 12:
			sub_026AA3(x);
			break;
		case 14:
			sub_026AB7(x);
			break;
		case 16:
			sub_026AD3(x);
			break;
		case 18:
			sub_026B00(x);
			break;
		case 20:
			y = sub_026B14(x, y, u);
			break;
		case -58:
			sub_026532(&x, &y);
			break;
		case -56:
			sub_0265BE(&x, &y);
			break;
		case -54:
			sub_026601(&x, &y);
			break;
		case -52:
			sub_026608(&x, &y);
			break;
		case -50:
			y = sub_02672A(x, y);
			break;
		case -48:
			sub_026751(&x, &y);
			break;
		case -46:
			sub_0267C0(&x, &y);
			break;
		case -44:
			continue;
		case -42:
			y = sub_0268F8(x, y);
			break;
		case -40:
			sub_02653D(x);
			break;
		case -38:
			sub_026554(x);
			break;
		case -36:
			sub_026563(x);
			break;
		case -34:
			sub_026573(x);
			break;
		case -32:
			sub_0265C7(x);
			break;
		case -30:
			sub_0265FE(x, u);
			break;
		case -28:
			y = sub_026611(x, y, u);
			break;
		case -26:
			sub_026692(x);
			break;
		case -24:
			sub_0266B3(x);
			break;
		case -22:
			sub_0266DA(x);
			break;
		case -20:
			sub_026702(x);
			break;
		case -18:
			sub_026721(&x, &y);
			break;
		case -16:
			sub_02675A(x);
			break;
		case -14:
			sub_026772(x);
			break;
		case -12:
			y = sub_0267AD(x, y, u);
			break;
		case -10:
			sub_0267C9(x);
			break;
		case -8:
			sub_026838(&x, &y);
			break;
		case -6:
			sub_02687B(x);
			break;
		case -4:
			sub_02688C(x);
			break;
		case -2:
			sub_026895(x, u);
			break;
		}
		break;
	}
	*p_x = x;
	*p_y = y;
}

void sub_0268C1(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry == 0u)
	{
		t1 = mem_read16(x + 0x11u);
		if ((int16_t)t1 < 0x90)
			mem_write16(x + 0x11u, 0x90u);
		return;
	}
	d = 0x6500u;
	carry = sub_078680(d);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	unk_4897 = 1u;
	mem_write8(x, mem_read8(x) | 0x48u);
	d = 0x100u;
	sub_026978(x, d);
	t2 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t2 + 1u);
	t1 = mem_read16(x + 0x11u);
	if ((int16_t)t1 < 0x90)
		mem_write16(x + 0x11u, 0x90u);
}

void sub_0268F5(uint16_t *p_x, uint16_t *p_y)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t u = 0, y_2 = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_027CAA_ADDRESS;
		t1 = mem_read8(x + 0x35u);
		a = t1;
		carry = (int8_t)a < 0;
		switch ((int8_t)(uint8_t)((uint32_t)a << 1))
		{
		case 0:
			sub_026B00(x);
			*p_x = x;
			*p_y = y;
			return;
		case 2:
			break;
		case -76:
			*p_x = x;
			*p_y = y;
			sub_026532(p_x, p_y);
			return;
		case -74:
			*p_x = x;
			*p_y = y;
			sub_0265BE(p_x, p_y);
			return;
		case -72:
			*p_x = x;
			*p_y = y;
			sub_026601(p_x, p_y);
			return;
		case -70:
			*p_x = x;
			*p_y = y;
			sub_026608(p_x, p_y);
			return;
		case -68:
			y = sub_02672A(x, y);
			*p_x = x;
			*p_y = y;
			return;
		case -66:
			*p_x = x;
			*p_y = y;
			sub_026751(p_x, p_y);
			return;
		case -64:
			*p_x = x;
			*p_y = y;
			sub_0267C0(p_x, p_y);
			return;
		case -62:
			*p_x = x;
			*p_y = y;
			sub_0268B8(p_x, p_y);
			return;
		case -60:
			y = sub_0268F8(x, y);
			*p_x = x;
			*p_y = y;
			return;
		case -58:
			sub_02653D(x);
			*p_x = x;
			*p_y = y;
			return;
		case -56:
			sub_026554(x);
			*p_x = x;
			*p_y = y;
			return;
		case -54:
			sub_026563(x);
			*p_x = x;
			*p_y = y;
			return;
		case -52:
			sub_026573(x);
			*p_x = x;
			*p_y = y;
			return;
		case -50:
			sub_0265C7(x);
			*p_x = x;
			*p_y = y;
			return;
		case -48:
			sub_0265FE(x, u);
			*p_x = x;
			*p_y = y;
			return;
		case -46:
			y = sub_026611(x, y, u);
			*p_x = x;
			*p_y = y;
			return;
		case -44:
			sub_026692(x);
			*p_x = x;
			*p_y = y;
			return;
		case -42:
			sub_0266B3(x);
			*p_x = x;
			*p_y = y;
			return;
		case -40:
			sub_0266DA(x);
			*p_x = x;
			*p_y = y;
			return;
		case -38:
			sub_026702(x);
			*p_x = x;
			*p_y = y;
			return;
		case -36:
			*p_x = x;
			*p_y = y;
			sub_026721(p_x, p_y);
			return;
		case -34:
			sub_02675A(x);
			*p_x = x;
			*p_y = y;
			return;
		case -32:
			sub_026772(x);
			*p_x = x;
			*p_y = y;
			return;
		case -30:
			y = sub_0267AD(x, y, u);
			*p_x = x;
			*p_y = y;
			return;
		case -28:
			sub_0267C9(x);
			*p_x = x;
			*p_y = y;
			return;
		case -26:
			*p_x = x;
			*p_y = y;
			sub_026838(p_x, p_y);
			return;
		case -24:
			sub_02687B(x);
			*p_x = x;
			*p_y = y;
			return;
		case -22:
			sub_02688C(x);
			*p_x = x;
			*p_y = y;
			return;
		case -20:
			sub_026895(x, u);
			*p_x = x;
			*p_y = y;
			return;
		case -18:
			sub_0268C1(x);
			*p_x = x;
			*p_y = y;
			return;
		case -16:
			continue;
		case -14:
			y_2 = sub_026A45(u, carry);
			*p_x = x;
			*p_y = y_2;
			return;
		case -12:
			y_2 = sub_026A55(u, carry);
			*p_x = x;
			*p_y = y_2;
			return;
		case -10:
			y_2 = sub_026A4D(u, carry);
			*p_x = x;
			*p_y = y_2;
			return;
		case -8:
			sub_026A8F(x);
			*p_x = x;
			*p_y = y;
			return;
		case -6:
			sub_026AA3(x);
			*p_x = x;
			*p_y = y;
			return;
		case -4:
			sub_026AB7(x);
			*p_x = x;
			*p_y = y;
			return;
		case -2:
			sub_026AD3(x);
			*p_x = x;
			*p_y = y;
			return;
		}
		break;
	}
	y = sub_026B14(x, y, u);
	*p_x = x;
	*p_y = y;
}

uint16_t sub_0268F8(uint16_t x, uint16_t y)
{
	uint8_t a = 0;
	uint16_t u = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x2Bu);
	u = t1;
	if (mem_read8(u) != 0u)
	{
		t2 = mem_read8(u + 2u);
		if ((int8_t)t2 < 0)
			return y;
	}
	t3 = mem_read8(x + 0x33u);
	a = t3;
	if (a != 4u)
	{
		sub_026B33(x);
		return sub_0269B9(x, y, u);
	}
	mem_write8(x + 2u, a);
	t4 = mem_read8(x + 0x34u);
	mem_write8(x + 0x28u, t4);
	return y;
}

uint16_t sub_02691C(uint16_t x, uint16_t y)
{
	uint32_t negative = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0, t3 = 0;

	if ((mem_read8(x) & 0x20u) != 0u)
	{
		t1 = mem_read8(x + 0x1Eu);
		negative = t1 >> 7;
		if (t1 != 0u && negative == 0u)
		{
			t2 = mem_read16(x + 0x38u);
			if (t2 != 0u)
			{
				t3 = mem_read16(x + 0x38u);
				mem_write8(t3, 0u);
				mem_write16(x + 0x38u, 0u);
			}
			y = sub_026B79(x, y);
		}
	}
	return y;
}

void sub_02693A(uint16_t x, uint16_t *p_u, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t a = 0, b = 0, d = 0;
	uint16_t d_2 = 0, u = 0;
	uint8_t t2 = 0, t14 = 0, t15 = 0, t16 = 0;
	uint16_t t1 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0;

	t1 = mem_read16(x + 0x2Bu);
	u = t1;
	if (mem_read8(u) == 0u)
		carry = sub_026CD8(x);
	else
	{
		t2 = mem_read8(u + 2u);
		if ((int8_t)t2 < 0)
			carry = sub_026CD8(x);
		else
		{
			t3 = mem_read16(x + 0x11u);
			t4 = mem_read16(u + 0x11u);
			t5 = t3 - t4;
			a = (uint8_t)(t5 >> 8);
			b = (uint8_t)t5;
			if ((int16_t)t5 < 0 || (int16_t)(((uint32_t)a << 8) | b) > 0x10)
				carry = 0u;
			else
			{
				t6 = mem_read16(x + 0xCu);
				t7 = mem_read16(u + 0xCu);
				t8 = t6 - t7;
				t9 = t8;
				t10 = t9 >> 15 ? 0u - t9 : t9;
				a = (uint8_t)(t10 >> 8);
				b = (uint8_t)t10;
				if ((int16_t)(((uint32_t)a << 8) | b) > 0x40 || (int16_t)(((uint32_t)a << 8) | b) < 0x10)
					carry = 0u;
				else
				{
					mem_write16(x + 0xFu, 0u);
					mem_write16(x + 0x14u, 0u);
					d = 0u;
					sub_07867D(d, &u, &carry);
					if (carry)
					{
						mem_write8(u + 1u, 4u);
						t11 = mem_read16(x + 0xCu);
						mem_write16(u + 0xCu, t11);
						t12 = mem_read16(x + 0x11u);
						mem_write16(u + 0x11u, t12);
						t13 = mem_read16(x + 0x16u);
						mem_write16(u + 0x16u, t13);
						mem_write16(x + 0x38u, u);
						mem_write8(x + 0x29u, 0u);
						mem_write8(x + 2u, 2u);
						mem_write8(x + 0x28u, 0u);
						mem_write8(x + 0x35u, 0u);
						d_2 = 0u;
						sub_026969(x, d_2);
						u = krusty_balloon_quick_attack_chances_by_players_ADDRESS;
						if (unk_4858 < krusty_balloon_quick_attack_chances_by_players[(int8_t)((uint8_t)(unk_4857 - 1u))])
						{
							t14 = mem_read8(x + 0x1Bu);
							mem_write8(x + VIDEO_002F, t14);
							carry = 1u;
						}
						else
						{
							t15 = mem_read8(x + VIDEO_002F);
							t16 = mem_read8(x + 0x1Bu);
							if ((uint8_t)(t15 - t16) >= 0xCu)
							{
								t14 = mem_read8(x + 0x1Bu);
								mem_write8(x + VIDEO_002F, t14);
								carry = 1u;
							}
							else
							{
								mem_write8(x + 0x29u, 0x20u);
								carry = 1u;
							}
						}
					}
				}
			}
		}
	}
	*p_u = u;
	*p_carry = carry;
}

void sub_026969(uint16_t x, uint16_t d)
{
	uint16_t t1 = 0;

	t1 = krusty_balloon_animations[(int8_t)((uint8_t)((uint32_t)(d >> 8) << 1)) / 2];
	mem_write16(x + 4u, ((uint32_t)(t1 >> 8) << 8) | (uint8_t)(t1 | 0x80u));
}

void sub_026978(uint16_t x, uint16_t d)
{
	uint16_t t1 = 0, field_1c = 0, t2 = 0, field_1f = 0, t3 = 0, field = 0, field_23 = 0;

	t1 = krusty_balloon_hit_boxes_ADDRESS + (uint8_t)((((uint32_t)(d >> 8) << 1) << 1) << 1);
	field_1c = HIT_BOX(t1)->field_1c;
	mem_write16(x + 0x1Cu, field_1c);
	t2 = t1 + 2u;
	field_1f = HIT_BOX(t2 - 0x2u)->field_1f;
	mem_write16(x + 0x1Fu, field_1f);
	t3 = t2 + 2u;
	field = HIT_BOX(t3 - 0x4u)->field_21;
	mem_write16(x + 0x21u, field);
	field_23 = HIT_BOX(t3 - 0x4u)->field_23;
	mem_write16(x + 0x23u, field_23);
}

void sub_02699B(uint16_t x)
{
	uint8_t b = 0;
	uint16_t d = 0, u = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read16(x + 0x2Bu);
	u = t1;
	t2 = mem_read16(x + 0xCu);
	t3 = mem_read16(u + 0xCu);
	if ((int16_t)t3 < (int16_t)t2)
		b = 0x40u;
	else
		b = 0xC0u;
	d = b;
	d = sub_078671(x, u, d);
	mem_write8(x + 0x2Du, ((d & ~0xFFu) | b) >> 8);
	d = sub_07861D(x, u);
	mem_write8(x + 0x2Eu, (d | b) >> 8);
}

uint16_t sub_0269B9(uint16_t x, uint16_t y, uint16_t u)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, y_2 = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0;
	uint16_t t1 = 0;

	sub_078686(x, &u, &ignored16, &carry);
	if (carry == 0u)
	{
		carry = sub_026CD8(x);
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

void sub_0269E0(uint16_t d, uint16_t *p_x, uint16_t *p_y, uint32_t *p_carry)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = *p_carry;
	uint8_t a = 0;
	uint16_t d_2 = 0, u = 0, x_2 = 0, y_2 = 0;
	uint8_t stack = 0;
	uint16_t stack_3 = 0, stack_5 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	stack = d >> 8;
	d_2 = 1u;
	sub_07867D(d_2, &u, &carry);
	if (carry)
		a = 0x31u;
	else
	{
		d_2 = 2u;
		sub_07867D(d_2, &u, &carry);
		if (carry == 0u)
		{
			carry = 1u;
			*p_carry = carry;
			return;
		}
		a = 0x10u;
	}
	mem_write8(u + 1u, a);
	mem_write8(u, 0xC8u);
	t1 = mem_read16(x + 0xCu);
	mem_write16(u + 0xCu, t1);
	t2 = mem_read16(x + 0x11u);
	mem_write16(u + 0x11u, t2);
	t3 = mem_read16(x + 0x16u);
	mem_write16(u + 0x16u, t3);
	mem_write16(u + 0x29u, x);
	mem_write8(u + 0x5Bu, 2u);
	stack_3 = u;
	stack_5 = x;
	x_2 = u;
	d_2 |= 0x800u;
	sub_026969(x_2, d_2);
	d_2 = (d_2 & 0xFFu) | 0x200u;
	sub_026978(x_2, d_2);
	x_2 = stack_5;
	u = stack_3;
	mem_write16(u + 0xFu, 0u);
	mem_write16(u + 0x19u, 0x280u);
	y_2 = loaded_table_027C9C_ADDRESS;
	a = stack;
	carry = (int8_t)a < 0;
	switch ((int8_t)(uint8_t)((uint32_t)a << 1))
	{
	case 0:
		y_2 = sub_026A45(u, carry);
		break;
	case 2:
		y_2 = sub_026A55(u, carry);
		break;
	case 4:
		y_2 = sub_026A4D(u, carry);
		break;
	case 6:
		sub_026A8F(x_2);
		break;
	case 8:
		sub_026AA3(x_2);
		break;
	case 10:
		sub_026AB7(x_2);
		break;
	case 12:
		sub_026AD3(x_2);
		break;
	case 14:
		sub_026B00(x_2);
		break;
	case 16:
		y_2 = sub_026B14(x_2, y_2, u);
		break;
	case -62:
		sub_026532(&x_2, &y_2);
		break;
	case -60:
		sub_0265BE(&x_2, &y_2);
		break;
	case -58:
		sub_026601(&x_2, &y_2);
		break;
	case -56:
		sub_026608(&x_2, &y_2);
		break;
	case -54:
		y_2 = sub_02672A(x_2, y_2);
		break;
	case -52:
		sub_026751(&x_2, &y_2);
		break;
	case -50:
		sub_0267C0(&x_2, &y_2);
		break;
	case -48:
		sub_0268B8(&x_2, &y_2);
		break;
	case -46:
		y_2 = sub_0268F8(x_2, y_2);
		break;
	case -44:
		sub_02653D(x_2);
		break;
	case -42:
		sub_026554(x_2);
		break;
	case -40:
		sub_026563(x_2);
		break;
	case -38:
		sub_026573(x_2);
		break;
	case -36:
		sub_0265C7(x_2);
		break;
	case -34:
		sub_0265FE(x_2, u);
		break;
	case -32:
		y_2 = sub_026611(x_2, y_2, u);
		break;
	case -30:
		sub_026692(x_2);
		break;
	case -28:
		sub_0266B3(x_2);
		break;
	case -26:
		sub_0266DA(x_2);
		break;
	case -24:
		sub_026702(x_2);
		break;
	case -22:
		sub_026721(&x_2, &y_2);
		break;
	case -20:
		sub_02675A(x_2);
		break;
	case -18:
		sub_026772(x_2);
		break;
	case -16:
		y_2 = sub_0267AD(x_2, y_2, u);
		break;
	case -14:
		sub_0267C9(x_2);
		break;
	case -12:
		sub_026838(&x_2, &y_2);
		break;
	case -10:
		sub_02687B(x_2);
		break;
	case -8:
		sub_02688C(x_2);
		break;
	case -6:
		sub_026895(x_2, u);
		break;
	case -4:
		sub_0268C1(x_2);
		break;
	case -2:
		sub_0268F5(&x_2, &y_2);
		break;
	}
	d_2 = 0x2600u;
	carry = sub_078689(d_2);
	carry = 0u;
	*p_x = x_2;
	*p_y = y_2;
	*p_carry = carry;
}

uint16_t sub_026A45(uint16_t u, uint32_t carry)
{
	mem_write16(u + 0xFu, 0x280u);
	return sub_026A55(u, carry);
}

uint16_t sub_026A4D(uint16_t u, uint32_t carry)
{
	mem_write16(u + 0xFu, 0xFD80u);
	return sub_026A55(u, carry);
}

uint16_t sub_026A55(uint16_t u, uint32_t carry)
{
	uint16_t y = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = (int8_t)unk_4858;
	t2 = mem_read16(u + 0xFu);
	t3 = (((uint32_t)(uint8_t)((uint32_t)(t1 >> 8) << 1) << 8) | (uint8_t)(((uint32_t)(uint8_t)t1 << 1) | carry)) + t2;
	mem_write16(u + 0xFu, t3);
	y = krusty_balloon_throw_z_speeds_ADDRESS;
	t4 = 0u - (((uint32_t)(krusty_balloon_throw_z_speeds[unk_4858 & 7u] >> 8) << 8) | unk_4858);
	mem_write16(u + 0x14u, t4);
	return y;
}

void sub_026A74(uint16_t *p_x, uint16_t *p_y, uint32_t *p_carry)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = *p_carry;
	uint8_t a = 0;
	uint16_t u = 0;
	uint8_t t1 = 0, t2 = 0;

	u = loaded_table_027CA2_ADDRESS;
	t1 = mem_read8(x + 0x35u);
	a = t1;
	carry = (int8_t)a < 0;
	switch ((int8_t)(uint8_t)((uint32_t)a << 1))
	{
	case 0:
		sub_026A8F(x);
		break;
	case 2:
		sub_026AA3(x);
		break;
	case 4:
		sub_026AB7(x);
		break;
	case 6:
		sub_026AD3(x);
		break;
	case 8:
		sub_026B00(x);
		break;
	case 10:
		y = sub_026B14(x, y, u);
		break;
	case -68:
		sub_026532(&x, &y);
		break;
	case -66:
		sub_0265BE(&x, &y);
		break;
	case -64:
		sub_026601(&x, &y);
		break;
	case -62:
		sub_026608(&x, &y);
		break;
	case -60:
		y = sub_02672A(x, y);
		break;
	case -58:
		sub_026751(&x, &y);
		break;
	case -56:
		sub_0267C0(&x, &y);
		break;
	case -54:
		sub_0268B8(&x, &y);
		break;
	case -52:
		y = sub_0268F8(x, y);
		break;
	case -50:
		sub_02653D(x);
		break;
	case -48:
		sub_026554(x);
		break;
	case -46:
		sub_026563(x);
		break;
	case -44:
		sub_026573(x);
		break;
	case -42:
		sub_0265C7(x);
		break;
	case -40:
		sub_0265FE(x, u);
		break;
	case -38:
		y = sub_026611(x, y, u);
		break;
	case -36:
		sub_026692(x);
		break;
	case -34:
		sub_0266B3(x);
		break;
	case -32:
		sub_0266DA(x);
		break;
	case -30:
		sub_026702(x);
		break;
	case -28:
		sub_026721(&x, &y);
		break;
	case -26:
		sub_02675A(x);
		break;
	case -24:
		sub_026772(x);
		break;
	case -22:
		y = sub_0267AD(x, y, u);
		break;
	case -20:
		sub_0267C9(x);
		break;
	case -18:
		sub_026838(&x, &y);
		break;
	case -16:
		sub_02687B(x);
		break;
	case -14:
		sub_02688C(x);
		break;
	case -12:
		sub_026895(x, u);
		break;
	case -10:
		sub_0268C1(x);
		break;
	case -8:
		sub_0268F5(&x, &y);
		break;
	case -6:
		y = sub_026A45(u, carry);
		break;
	case -4:
		y = sub_026A55(u, carry);
		break;
	case -2:
		y = sub_026A4D(u, carry);
		break;
	}
	t2 = mem_read8(x + 0x35u);
	if (t2 != 4u)
		carry = 0u;
	else
	{
		mem_write8(x + 0x35u, 0u);
		carry = 1u;
	}
	*p_x = x;
	*p_y = y;
	*p_carry = carry;
}

void sub_026A8F(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0xAu);
	if (t1 >= 0x60u)
	{
		t2 = mem_read8(x + 0x35u);
		mem_write8(x + 0x35u, t2 + 1u);
		return;
	}
	t3 = mem_read8(x + 0xAu);
	mem_write8(x + 0xAu, t3 + 4u);
}

void sub_026AA3(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0xAu);
	if (t1 <= 0x40u)
	{
		t2 = mem_read8(x + 0x35u);
		mem_write8(x + 0x35u, t2 + 1u);
		return;
	}
	t3 = mem_read8(x + 0xAu);
	mem_write8(x + 0xAu, t3 - 4u);
}

void sub_026AB7(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = mem_read8(x + 0xAu);
	if (t1 <= 0x20u)
	{
		t2 = mem_read8(x + 0x35u);
		mem_write8(x + 0x35u, t2 + 1u);
		return;
	}
	t3 = mem_read8(x + 0xAu);
	mem_write8(x + 0xAu, t3 - 4u);
	t4 = mem_read8(x + 0xBu);
	mem_write8(x + 0xBu, t4 + 4u);
}

void sub_026AD3(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = mem_read8(x + 0xAu);
	if (t1 >= 0x40u)
	{
		mem_write8(x + 0xAu, 0x40u);
		mem_write8(x + 0xBu, 0x40u);
		t2 = mem_read8(x + 0x35u);
		mem_write8(x + 0x35u, t2 + 1u);
		return;
	}
	t3 = mem_read8(x + 0xAu);
	mem_write8(x + 0xAu, t3 + 4u);
	t4 = mem_read8(x + 0xBu);
	mem_write8(x + 0xBu, t4 - 4u);
}

void sub_026B00(uint16_t x)
{
	uint16_t d = 0;
	uint8_t t1 = 0;

	mem_write8(x, mem_read8(x) & 0xBBu);
	d = 0u;
	sub_026978(x, d);
	mem_write16(x + 0x19u, 0x80u);
	t1 = mem_read8(x + 0x35u);
	mem_write8(x + 0x35u, t1 + 1u);
}

uint16_t sub_026B14(uint16_t x, uint16_t y, uint16_t u)
{
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x16u);
	if ((int16_t)t1 < 0x20)
		return y;
	mem_write16(x + 0x19u, 0u);
	mem_write16(x + 0x16u, 0x20u);
	mem_write8(x, mem_read8(x) | 0x40u);
	y = sub_0269B9(x, y, u);
	sub_026B33(x);
	return y;
}

void sub_026B33(uint16_t x)
{
	uint16_t d = 0;

	d = 0x100u;
	sub_026969(x, d);
	d = 0u;
	sub_026978(x, d);
	mem_write8(x, (mem_read8(x) | 0x40u) & ~4u);
	mem_write8(x + 2u, 1u);
	mem_write8(x + 0x28u, 0u);
	mem_write8(x + 0x35u, 0u);
	mem_write8(x + 0x29u, 0u);
}

uint16_t sub_026B79(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t d = 0, u = 0;
	uint8_t t2 = 0, t6 = 0, t7 = 0, t8 = 0;
	uint16_t t1 = 0, t3 = 0, t4 = 0, t5 = 0, t9 = 0, t10 = 0;

	t1 = mem_read16(x + 0x25u);
	u = t1;
	mem_write8(u + 0x2Au, 1u);
	mem_write16(u + 0x49u, x);
	d = 0x6501u;
	carry = sub_078680(d);
	mem_write8(x, mem_read8(x) & 0xBBu);
	d = 0x701u;
	sub_026969(x, d);
	d &= 0xFFu;
	sub_026978(x, d);
	u = krusty_balloon_beaten_health_by_players_ADDRESS;
	t2 = mem_read8(x + 0x1Bu);
	if (t2 <= krusty_balloon_beaten_health_by_players[(int8_t)((uint8_t)(unk_4857 - 1u))])
	{
		mem_write16(x + 0x19u, 0x300u);
		t3 = mem_read16(x + 0x25u);
		t4 = mem_read16(x + 0xCu);
		t5 = mem_read16(t3 + 0xCu);
		if ((int16_t)t5 < (int16_t)t4)
			mem_write16(x + 0xFu, 0x600u);
		else
			mem_write16(x + 0xFu, 0xFA00u);
		mem_write8(x + 2u, 0xFEu);
		mem_write8(x + 0x28u, 0u);
		mem_write8(x + 0x35u, 0u);
		return y;
	}
	unk_487E = 2u;
	d = 0xDu;
	sub_078677(d, &y, &u);
	t6 = mem_read8(x + 0x1Eu);
	if (t6 != 0x13u)
	{
		t7 = mem_read8(x + 0x30u);
		mem_write8(x + 0x30u, t7 + 1u);
		t8 = mem_read8(x + 0x30u);
		if (t8 < krusty_balloon_hit_limits_by_players[(int8_t)((uint8_t)(unk_4857 - 1u))])
		{
			mem_write16(x + 0xFu, 0u);
			mem_write16(x + 0x14u, 0u);
			mem_write8(x + 2u, 0xFFu);
			mem_write8(x + 0x28u, 0u);
			mem_write8(x + 0x35u, 0u);
			return y;
		}
	}
	mem_write8(x + 0x30u, 0u);
	y = krusty_balloon_fly_off_chances_by_rank_ADDRESS;
	if (unk_4858 <= krusty_balloon_fly_off_chances_by_rank[unk_4861 >> 1])
	{
		sub_026969(x, d);
		mem_write16(x + 0xFu, 0x600u);
		t9 = mem_read16(x + 0xCu);
		if ((int16_t)t9 > 0xE0)
		{
			t10 = mem_read16(x + 0xFu);
			mem_write16(x + 0xFu, 0u - t10);
		}
		mem_write16(x + 0x14u, 0x600u);
		mem_write16(x + 0x19u, 0x600u);
		mem_write8(x + 2u, 3u);
		mem_write8(x + 0x28u, 0u);
		mem_write8(x + 0x35u, 0u);
		return y;
	}
	mem_write16(x + 0x19u, 0x300u);
	t3 = mem_read16(x + 0x25u);
	t4 = mem_read16(x + 0xCu);
	t5 = mem_read16(t3 + 0xCu);
	if ((int16_t)t5 < (int16_t)t4)
		mem_write16(x + 0xFu, 0x600u);
	else
		mem_write16(x + 0xFu, 0xFA00u);
	mem_write8(x + 2u, 0xFEu);
	mem_write8(x + 0x28u, 0u);
	mem_write8(x + 0x35u, 0u);
	return y;
}

void sub_026CAA(uint16_t x, uint16_t u)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d = 0, ignored16 = 0;

	mem_write8(x, mem_read8(x) | 0x4Cu);
	d = 0x500u;
	sub_026978(x, d);
	sub_078686(x, &u, &ignored16, &carry);
	d = sub_07861D(x, u);
	a = (uint8_t)(d >> 8);
	d = ((uint32_t)a << 8) | 0xC0u;
	sub_078617(x, d);
	mem_write16(x + 0x19u, 0xFC00u);
	mem_write8(x + 2u, 4u);
	mem_write8(x + 0x28u, 0u);
	mem_write8(x + 0x35u, 0u);
	d = (d & 0xFFu) | 0x100u;
	sub_026969(x, d);
}

uint32_t sub_026CD8(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t d = 0;
	uint16_t d_2 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 2u);
	mem_write8(x + 0x33u, t1);
	t2 = mem_read8(x + 0x28u);
	mem_write8(x + 0x34u, t2);
	d = 0u;
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write8(x + 2u, 5u);
	mem_write8(x + 0x28u, 0u);
	mem_write8(x + 0x35u, 0u);
	t3 = mem_read8(x + 5u);
	if (t3 != 0u)
	{
		d_2 = 0u;
		sub_026969(x, d_2);
	}
	carry = 1u;
	return carry;
}

void sub_026D01(uint16_t x)
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
	if ((int16_t)d <= 0x76F || (int16_t)d >= 0x8E0)
		mem_write16(x + 0xFu, 0u);
}

void sub_026D35(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint8_t t1 = 0, t6 = 0, t7 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0;

	t1 = mem_read8(x + 2u);
	a = t1;
	if (t1 != 0u && a != 3u)
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
		a = unk_48F0 - (uint8_t)(unk_48B2 >> 8u) - carry;
		b = unk_48F1;
		if ((int16_t)(((uint32_t)a << 8) | b) <= 0x60 || (int16_t)(((uint32_t)a << 8) | b) >= 0x100)
			mem_write16(x + 0x14u, 0u);
	}
}

void sub_026D8F(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	d = 0x6F00u;
	carry = sub_078680(d);
	a = 0xBu;
	t1 = mem_read8(x + 2u);
	if (t1 >= 3u)
		a++;
	d = (uint32_t)a << 8;
	sub_026969(x, d);
	mem_write8(x + 2u, 0xFFu);
}

void sub_026DA8(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x, mem_read8(x) & 0xBFu);
	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) != 0u)
		mem_write8(x, 0u);
}

void sub_026DB8(uint16_t x)
{
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) == 0u)
		return;
	d = 0x900u;
	sub_026969(x, d);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write8(x + 0x28u, 0x20u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	sub_026DD3(x);
}

void sub_026DD3(uint16_t x)
{
	uint16_t stack = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	mem_write16(x + 0xFu, 0x80u);
	stack = x;
	if (((stack + (uint8_t)unk_4815) & 0x20u) == 0u)
	{
		t1 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t1);
	}
	mem_write16(x + 0x19u, rom_07FFC0_ADDRESS);
	t2 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t2 - 1u);
	if (t2 != 1u)
		return;
	sub_026D8F(x);
	mem_write8(x + 2u, 2u);
}

void sub_026DFA(uint16_t x)
{
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) == 0u)
		return;
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x19u, 0u);
	d = 0x300u;
	sub_026978(x, d);
	d = 0xA00u;
	sub_026969(x, d);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
}

void sub_026E16(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry)
	{
		sub_026D8F(x);
		return;
	}
}

void sub_026E2F(uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;

	sub_027200(&y, &u);
	unk_4805 &= 0xFFu;
	unk_4804++;
	*p_y = y;
	*p_u = u;
}

void sub_026E32(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t d = 0;

	for (;;)
	{
		unk_4805 = (unk_4805 & 0xFFu) | (((uint8_t)(unk_4805 >> 8u) + 1u & 0xFFu) << 8u);
		if ((uint8_t)(unk_4805 >> 8u) == 0xC0u)
		{
			sub_02716F(&x, &y, &u);
			break;
		}
		d = unk_4000_ADDRESS;
		sub_078653(d, &x, &carry);
		if (carry)
		{
			sub_02716F(&x, &y, &u);
			break;
		}
		x = loaded_table_027D5A_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)unk_4877 << 1))
		{
		case 0:
			sub_026E4E();
			break;
		case 2:
			sub_026E8C(&x, &y, &u);
			break;
		case 4:
		case 28:
		case 34:
		case 42:
		case 48:
			x = sub_026EE4();
			break;
		case 6:
		case 18:
			sub_026E76();
			break;
		case 8:
			sub_026F3A(&x, &y, &u);
			break;
		case 10:
			x = sub_026ED4();
			break;
		case 12:
			sub_026F79();
			break;
		case 14:
			sub_026F83(&x, &y, &u);
			break;
		case 16:
			x = sub_026EB4();
			break;
		case 20:
			sub_026FD5(&x, &y, &u);
			break;
		case 22:
			x = sub_026EC4();
			break;
		case 24:
			sub_027014();
			break;
		case 26:
			sub_02701E(&x, &y, &u);
			break;
		case 30:
			sub_026E6E();
			break;
		case 32:
			sub_027075(&x, &y, &u);
			break;
		case 36:
			sub_026E5E();
			break;
		case 38:
			sub_0270B4(&x, &y, &u);
			break;
		case 40:
			sub_0270E9(&x, &y);
			break;
		case 44:
			sub_026E56();
			break;
		case 46:
			sub_027151(&x, &y, &u);
			break;
		case -34:
			sub_026DA8(x);
			break;
		case -32:
			sub_026DB8(x);
			break;
		case -30:
			sub_026DD3(x);
			break;
		case -28:
			sub_026DFA(x);
			break;
		case -26:
			sub_026E16(x);
			break;
		case -24:
			continue;
		case -22:
			sub_026F1E(&x, &y, &u);
			break;
		case -20:
		case -16:
		case -10:
		case -4:
			sub_026E2F(&y, &u);
			break;
		case -18:
			sub_026F5D(&x, &y, &u);
			break;
		case -14:
			sub_026FB9(&x, &y, &u);
			break;
		case -12:
			sub_026FF8(&x, &y, &u);
			break;
		case -8:
			sub_027059(&x, &y, &u);
			break;
		case -6:
			sub_027098(&x, &y, &u);
			break;
		case -2:
			sub_027135(&x, &y, &u);
			break;
		}
		break;
	}
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

void sub_026E4E(void)
{
	uint32_t carry = 0;
	uint16_t d = 0;

	d = 0x5400u;
	carry = sub_078680(d);
	sub_026E76();
}

void sub_026E56(void)
{
	uint32_t carry = 0;
	uint16_t d = 0;

	d = unk_5800_ADDRESS;
	carry = sub_078680(d);
	sub_026E76();
}

void sub_026E5E(void)
{
	uint32_t carry = 0;
	uint16_t d = 0;

	d = 0x5700u;
	carry = sub_078680(d);
	sub_026E76();
}

void sub_026E66(void)
{
	uint32_t carry = 0;
	uint16_t d = 0;

	d = 0x5600u;
	carry = sub_078680(d);
	sub_026E76();
}

void sub_026E6E(void)
{
	uint32_t carry = 0;
	uint16_t d = 0;

	d = 0x3003u;
	carry = sub_078680(d);
	sub_026E76();
}

void sub_026E76(void)
{
	uint16_t d = 0;

	d = 0xFFF0u;
	sub_0786C2(d);
	d = 0u;
	sub_0786C5(d);
	d = 1u;
	sub_078656(d);
	unk_4877++;
}

void sub_026E8C(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t d = 0, u_2 = 0, x_2 = 0, y_2 = 0;

	if (unk_485D != 0u)
		return;
	sub_0271F5(u);
	sub_0271CF();
	u_2 = text_027D8C_ADDRESS;
	d = 0u;
	sub_0785A5(d, &x_2, &u_2);
	d = 0u;
	y_2 = sub_02719A(d);
	mem_write16(y_2 + 0xFu, 0xFE00u);
	d = 0x900u;
	y_2 = sub_02719A(d);
	mem_write8(y_2 + 9u, 0u);
	unk_4877++;
	*p_x = x_2;
	*p_y = y_2;
	*p_u = u_2;
}

uint16_t sub_026EB4(void)
{
	uint32_t carry = 0;
	uint16_t d = 0;

	if ((unk_4D46 & 2u) == 0u)
		return sub_026EE4();
	d = 0x5500u;
	carry = sub_078680(d);
	return sub_026EE4();
}

uint16_t sub_026EC4(void)
{
	uint32_t carry = 0;
	uint16_t d = 0;

	if ((unk_4D46 & 2u) == 0u)
		return sub_026EE4();
	d = 0x2C02u;
	carry = sub_078680(d);
	return sub_026EE4();
}

uint16_t sub_026ED4(void)
{
	uint32_t carry = 0;
	uint16_t d = 0;

	if ((unk_4D46 & 2u) == 0u)
		return sub_026EE4();
	d = 0xF00u;
	carry = sub_078680(d);
	return sub_026EE4();
}

uint16_t sub_026EE4(void)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d = 0, x = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	io_write8(IO_1FB9, 0x13u);
	io_write8(IO_1FBA, 0x2Cu);
	x = unk_4DA0_ADDRESS;
	a = unk_4DC8;
	if (a <= 0x40u)
	{
		t1 = unk_4DC8;
		unk_4DC8 = t1 + 1u;
		return x;
	}
	if (a == 0xA0u)
	{
		t2 = unk_4DC8;
		unk_4DC8 = t2 + 1u;
		d = 0x700u;
		carry = sub_078680(d);
		return x;
	}
	if (a >= 0xA0u)
		return x;
	t3 = unk_4DC8;
	unk_4DC8 = t3 + 1u;
	t4 = unk_4DA6;
	unk_4DA6 = t4 | 0x40u;
	return x;
}

void sub_026F1E(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t d = 0;

	for (;;)
	{
		unk_4805 = (unk_4805 & 0xFFu) | (((uint8_t)(unk_4805 >> 8u) + 1u & 0xFFu) << 8u);
		if ((uint8_t)(unk_4805 >> 8u) == 0xC0u)
		{
			sub_02716F(&x, &y, &u);
			break;
		}
		d = unk_4000_ADDRESS;
		sub_078653(d, &x, &carry);
		if (carry)
		{
			sub_02716F(&x, &y, &u);
			break;
		}
		x = loaded_table_027D60_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)unk_4877 << 1))
		{
		case 0:
		case 12:
			sub_026E76();
			break;
		case 2:
			sub_026F3A(&x, &y, &u);
			break;
		case 4:
			x = sub_026ED4();
			break;
		case 6:
			sub_026F79();
			break;
		case 8:
			sub_026F83(&x, &y, &u);
			break;
		case 10:
			x = sub_026EB4();
			break;
		case 14:
			sub_026FD5(&x, &y, &u);
			break;
		case 16:
			x = sub_026EC4();
			break;
		case 18:
			sub_027014();
			break;
		case 20:
			sub_02701E(&x, &y, &u);
			break;
		case -2:
		case 22:
		case 28:
		case 36:
		case 42:
			x = sub_026EE4();
			break;
		case 24:
			sub_026E6E();
			break;
		case 26:
			sub_027075(&x, &y, &u);
			break;
		case 30:
			sub_026E5E();
			break;
		case 32:
			sub_0270B4(&x, &y, &u);
			break;
		case 34:
			sub_0270E9(&x, &y);
			break;
		case 38:
			sub_026E56();
			break;
		case 40:
			sub_027151(&x, &y, &u);
			break;
		case -40:
			sub_026DA8(x);
			break;
		case -38:
			sub_026DB8(x);
			break;
		case -36:
			sub_026DD3(x);
			break;
		case -34:
			sub_026DFA(x);
			break;
		case -32:
			sub_026E16(x);
			break;
		case -30:
			sub_026E32(&x, &y, &u);
			break;
		case -28:
			continue;
		case -26:
		case -22:
		case -16:
		case -10:
			sub_026E2F(&y, &u);
			break;
		case -24:
			sub_026F5D(&x, &y, &u);
			break;
		case -20:
			sub_026FB9(&x, &y, &u);
			break;
		case -18:
			sub_026FF8(&x, &y, &u);
			break;
		case -14:
			sub_027059(&x, &y, &u);
			break;
		case -12:
			sub_027098(&x, &y, &u);
			break;
		case -8:
			sub_027135(&x, &y, &u);
			break;
		case -6:
			sub_026E4E();
			break;
		case -4:
			sub_026E8C(&x, &y, &u);
			break;
		}
		break;
	}
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

void sub_026F3A(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t d = 0, u_2 = 0, x_2 = 0, y_2 = 0;

	if (unk_485D != 0u)
		return;
	sub_0271F5(u);
	sub_0271CF();
	u_2 = text_027DAD_ADDRESS;
	d = 0u;
	sub_0785A5(d, &x_2, &u_2);
	d = 0x100u;
	sub_02719A(d);
	d = 0x900u;
	y_2 = sub_02719A(d);
	mem_write8(y_2 + 9u, 0u);
	unk_4877++;
	*p_x = x_2;
	*p_y = y_2;
	*p_u = u_2;
}

void sub_026F5D(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t d = 0;

	for (;;)
	{
		unk_4805 = (unk_4805 & 0xFFu) | (((uint8_t)(unk_4805 >> 8u) + 1u & 0xFFu) << 8u);
		if ((uint8_t)(unk_4805 >> 8u) == 0xC0u)
		{
			sub_02716F(&x, &y, &u);
			break;
		}
		d = unk_4000_ADDRESS;
		sub_078653(d, &x, &carry);
		if (carry)
		{
			sub_02716F(&x, &y, &u);
			break;
		}
		x = loaded_table_027D66_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)unk_4877 << 1))
		{
		case 0:
			sub_026F79();
			break;
		case 2:
			sub_026F83(&x, &y, &u);
			break;
		case 4:
			x = sub_026EB4();
			break;
		case -6:
		case 6:
			sub_026E76();
			break;
		case 8:
			sub_026FD5(&x, &y, &u);
			break;
		case 10:
			x = sub_026EC4();
			break;
		case 12:
			sub_027014();
			break;
		case 14:
			sub_02701E(&x, &y, &u);
			break;
		case -8:
		case 16:
		case 22:
		case 30:
		case 36:
			x = sub_026EE4();
			break;
		case 18:
			sub_026E6E();
			break;
		case 20:
			sub_027075(&x, &y, &u);
			break;
		case 24:
			sub_026E5E();
			break;
		case 26:
			sub_0270B4(&x, &y, &u);
			break;
		case 28:
			sub_0270E9(&x, &y);
			break;
		case 32:
			sub_026E56();
			break;
		case 34:
			sub_027151(&x, &y, &u);
			break;
		case -46:
			sub_026DA8(x);
			break;
		case -44:
			sub_026DB8(x);
			break;
		case -42:
			sub_026DD3(x);
			break;
		case -40:
			sub_026DFA(x);
			break;
		case -38:
			sub_026E16(x);
			break;
		case -36:
			sub_026E32(&x, &y, &u);
			break;
		case -34:
			sub_026F1E(&x, &y, &u);
			break;
		case -32:
		case -28:
		case -22:
		case -16:
			sub_026E2F(&y, &u);
			break;
		case -30:
			continue;
		case -26:
			sub_026FB9(&x, &y, &u);
			break;
		case -24:
			sub_026FF8(&x, &y, &u);
			break;
		case -20:
			sub_027059(&x, &y, &u);
			break;
		case -18:
			sub_027098(&x, &y, &u);
			break;
		case -14:
			sub_027135(&x, &y, &u);
			break;
		case -12:
			sub_026E4E();
			break;
		case -10:
			sub_026E8C(&x, &y, &u);
			break;
		case -4:
			sub_026F3A(&x, &y, &u);
			break;
		case -2:
			x = sub_026ED4();
			break;
		}
		break;
	}
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

void sub_026F79(void)
{
	sub_026E76();
	unk_48C5 = 0x20u;
}

void sub_026F83(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, u_2 = 0, x_2 = 0, y_2 = 0;

	if (unk_485D != 0u)
		return;
	sub_0271F5(u);
	sub_0271CF();
	unk_4875 = 0x86u;
	unk_4876 = 1u;
	sub_0786B0();
	d = 0x2Cu;
	sub_0786AD(d, &ignored16, &ignored16_2, &ignored16_3);
	u_2 = text_027DC4_ADDRESS;
	sub_0785A5(d, &x_2, &u_2);
	d |= 0x200u;
	sub_02719A(d);
	d = (d & 0xFFu) | 0x900u;
	y_2 = sub_02719A(d);
	mem_write8(y_2 + 9u, 0u);
	unk_4877++;
	*p_x = x_2;
	*p_y = y_2;
	*p_u = u_2;
}

void sub_026FB9(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t d = 0;

	for (;;)
	{
		unk_4805 = (unk_4805 & 0xFFu) | (((uint8_t)(unk_4805 >> 8u) + 1u & 0xFFu) << 8u);
		if ((uint8_t)(unk_4805 >> 8u) == 0xC0u)
		{
			sub_02716F(&x, &y, &u);
			break;
		}
		d = unk_4000_ADDRESS;
		sub_078653(d, &x, &carry);
		if (carry)
		{
			sub_02716F(&x, &y, &u);
			break;
		}
		x = loaded_table_027D6C_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)unk_4877 << 1))
		{
		case -12:
		case 0:
			sub_026E76();
			break;
		case 2:
			sub_026FD5(&x, &y, &u);
			break;
		case 4:
			x = sub_026EC4();
			break;
		case 6:
			sub_027014();
			break;
		case 8:
			sub_02701E(&x, &y, &u);
			break;
		case -14:
		case 10:
		case 16:
		case 24:
		case 30:
			x = sub_026EE4();
			break;
		case 12:
			sub_026E6E();
			break;
		case 14:
			sub_027075(&x, &y, &u);
			break;
		case 18:
			sub_026E5E();
			break;
		case 20:
			sub_0270B4(&x, &y, &u);
			break;
		case 22:
			sub_0270E9(&x, &y);
			break;
		case 26:
			sub_026E56();
			break;
		case 28:
			sub_027151(&x, &y, &u);
			break;
		case -52:
			sub_026DA8(x);
			break;
		case -50:
			sub_026DB8(x);
			break;
		case -48:
			sub_026DD3(x);
			break;
		case -46:
			sub_026DFA(x);
			break;
		case -44:
			sub_026E16(x);
			break;
		case -42:
			sub_026E32(&x, &y, &u);
			break;
		case -40:
			sub_026F1E(&x, &y, &u);
			break;
		case -38:
		case -34:
		case -28:
		case -22:
			sub_026E2F(&y, &u);
			break;
		case -36:
			sub_026F5D(&x, &y, &u);
			break;
		case -32:
			continue;
		case -30:
			sub_026FF8(&x, &y, &u);
			break;
		case -26:
			sub_027059(&x, &y, &u);
			break;
		case -24:
			sub_027098(&x, &y, &u);
			break;
		case -20:
			sub_027135(&x, &y, &u);
			break;
		case -18:
			sub_026E4E();
			break;
		case -16:
			sub_026E8C(&x, &y, &u);
			break;
		case -10:
			sub_026F3A(&x, &y, &u);
			break;
		case -8:
			x = sub_026ED4();
			break;
		case -6:
			sub_026F79();
			break;
		case -4:
			sub_026F83(&x, &y, &u);
			break;
		case -2:
			x = sub_026EB4();
			break;
		}
		break;
	}
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

void sub_026FD5(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t d = 0, u_2 = 0, x_2 = 0, y_2 = 0;

	if (unk_485D != 0u)
		return;
	sub_0271F5(u);
	sub_0271CF();
	u_2 = text_027DF0_ADDRESS;
	d = 0u;
	sub_0785A5(d, &x_2, &u_2);
	d = 0x300u;
	sub_02719A(d);
	d = 0x900u;
	y_2 = sub_02719A(d);
	mem_write8(y_2 + 9u, 0u);
	unk_4877++;
	*p_x = x_2;
	*p_y = y_2;
	*p_u = u_2;
}

void sub_026FF8(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t d = 0;

	for (;;)
	{
		unk_4805 = (unk_4805 & 0xFFu) | (((uint8_t)(unk_4805 >> 8u) + 1u & 0xFFu) << 8u);
		if ((uint8_t)(unk_4805 >> 8u) == 0xC0u)
		{
			sub_02716F(&x, &y, &u);
			break;
		}
		d = unk_4000_ADDRESS;
		sub_078653(d, &x, &carry);
		if (carry)
		{
			sub_02716F(&x, &y, &u);
			break;
		}
		x = loaded_table_027D72_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)unk_4877 << 1))
		{
		case 0:
			sub_027014();
			break;
		case 2:
			sub_02701E(&x, &y, &u);
			break;
		case -20:
		case 4:
		case 10:
		case 18:
		case 24:
			x = sub_026EE4();
			break;
		case 6:
			sub_026E6E();
			break;
		case 8:
			sub_027075(&x, &y, &u);
			break;
		case 12:
			sub_026E5E();
			break;
		case 14:
			sub_0270B4(&x, &y, &u);
			break;
		case 16:
			sub_0270E9(&x, &y);
			break;
		case 20:
			sub_026E56();
			break;
		case 22:
			sub_027151(&x, &y, &u);
			break;
		case -58:
			sub_026DA8(x);
			break;
		case -56:
			sub_026DB8(x);
			break;
		case -54:
			sub_026DD3(x);
			break;
		case -52:
			sub_026DFA(x);
			break;
		case -50:
			sub_026E16(x);
			break;
		case -48:
			sub_026E32(&x, &y, &u);
			break;
		case -46:
			sub_026F1E(&x, &y, &u);
			break;
		case -44:
		case -40:
		case -34:
		case -28:
			sub_026E2F(&y, &u);
			break;
		case -42:
			sub_026F5D(&x, &y, &u);
			break;
		case -38:
			sub_026FB9(&x, &y, &u);
			break;
		case -36:
			continue;
		case -32:
			sub_027059(&x, &y, &u);
			break;
		case -30:
			sub_027098(&x, &y, &u);
			break;
		case -26:
			sub_027135(&x, &y, &u);
			break;
		case -24:
			sub_026E4E();
			break;
		case -22:
			sub_026E8C(&x, &y, &u);
			break;
		case -18:
		case -6:
			sub_026E76();
			break;
		case -16:
			sub_026F3A(&x, &y, &u);
			break;
		case -14:
			x = sub_026ED4();
			break;
		case -12:
			sub_026F79();
			break;
		case -10:
			sub_026F83(&x, &y, &u);
			break;
		case -8:
			x = sub_026EB4();
			break;
		case -4:
			sub_026FD5(&x, &y, &u);
			break;
		case -2:
			x = sub_026EC4();
			break;
		}
		break;
	}
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

void sub_027014(void)
{
	sub_026E66();
	unk_48C5 = 0x28u;
}

void sub_02701E(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, u_2 = 0, x_2 = 0, y_2 = 0;

	if (unk_485D != 0u)
		return;
	sub_0271F5(u);
	sub_0271CF();
	unk_4875 = 0x89u;
	unk_4876 = 2u;
	sub_0786B0();
	unk_4876 = 4u;
	d = 0x2Cu;
	sub_0786AD(d, &ignored16, &ignored16_2, &ignored16_3);
	u_2 = text_027E09_ADDRESS;
	sub_0785A5(d, &x_2, &u_2);
	d |= 0x400u;
	sub_02719A(d);
	d = (d & 0xFFu) | 0x900u;
	y_2 = sub_02719A(d);
	mem_write8(y_2 + 9u, 0u);
	unk_4877++;
	*p_x = x_2;
	*p_y = y_2;
	*p_u = u_2;
}

void sub_027059(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t d = 0;

	for (;;)
	{
		unk_4805 = (unk_4805 & 0xFFu) | (((uint8_t)(unk_4805 >> 8u) + 1u & 0xFFu) << 8u);
		if ((uint8_t)(unk_4805 >> 8u) == 0xC0u)
		{
			sub_02716F(&x, &y, &u);
			break;
		}
		d = unk_4000_ADDRESS;
		sub_078653(d, &x, &carry);
		if (carry)
		{
			sub_02716F(&x, &y, &u);
			break;
		}
		x = loaded_table_027D78_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)unk_4877 << 1))
		{
		case 0:
			sub_026E6E();
			break;
		case 2:
			sub_027075(&x, &y, &u);
			break;
		case -26:
		case -2:
		case 4:
		case 12:
		case 18:
			x = sub_026EE4();
			break;
		case 6:
			sub_026E5E();
			break;
		case 8:
			sub_0270B4(&x, &y, &u);
			break;
		case 10:
			sub_0270E9(&x, &y);
			break;
		case 14:
			sub_026E56();
			break;
		case 16:
			sub_027151(&x, &y, &u);
			break;
		case -64:
			sub_026DA8(x);
			break;
		case -62:
			sub_026DB8(x);
			break;
		case -60:
			sub_026DD3(x);
			break;
		case -58:
			sub_026DFA(x);
			break;
		case -56:
			sub_026E16(x);
			break;
		case -54:
			sub_026E32(&x, &y, &u);
			break;
		case -52:
			sub_026F1E(&x, &y, &u);
			break;
		case -50:
		case -46:
		case -40:
		case -34:
			sub_026E2F(&y, &u);
			break;
		case -48:
			sub_026F5D(&x, &y, &u);
			break;
		case -44:
			sub_026FB9(&x, &y, &u);
			break;
		case -42:
			sub_026FF8(&x, &y, &u);
			break;
		case -38:
			continue;
		case -36:
			sub_027098(&x, &y, &u);
			break;
		case -32:
			sub_027135(&x, &y, &u);
			break;
		case -30:
			sub_026E4E();
			break;
		case -28:
			sub_026E8C(&x, &y, &u);
			break;
		case -24:
		case -12:
			sub_026E76();
			break;
		case -22:
			sub_026F3A(&x, &y, &u);
			break;
		case -20:
			x = sub_026ED4();
			break;
		case -18:
			sub_026F79();
			break;
		case -16:
			sub_026F83(&x, &y, &u);
			break;
		case -14:
			x = sub_026EB4();
			break;
		case -10:
			sub_026FD5(&x, &y, &u);
			break;
		case -8:
			x = sub_026EC4();
			break;
		case -6:
			sub_027014();
			break;
		case -4:
			sub_02701E(&x, &y, &u);
			break;
		}
		break;
	}
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

void sub_027075(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t d = 0, u_2 = 0, x_2 = 0, y_2 = 0;

	if (unk_485D != 0u)
		return;
	sub_0271F5(u);
	sub_0271CF();
	u_2 = text_027E27_ADDRESS;
	d = 0u;
	sub_0785A5(d, &x_2, &u_2);
	d = 0x500u;
	sub_02719A(d);
	d = 0x900u;
	y_2 = sub_02719A(d);
	mem_write8(y_2 + 9u, 0u);
	unk_4877++;
	*p_x = x_2;
	*p_y = y_2;
	*p_u = u_2;
}

void sub_027098(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t d = 0;

	for (;;)
	{
		unk_4805 = (unk_4805 & 0xFFu) | (((uint8_t)(unk_4805 >> 8u) + 1u & 0xFFu) << 8u);
		if ((uint8_t)(unk_4805 >> 8u) == 0xC0u)
		{
			sub_02716F(&x, &y, &u);
			break;
		}
		d = unk_4000_ADDRESS;
		sub_078653(d, &x, &carry);
		if (carry)
		{
			sub_02716F(&x, &y, &u);
			break;
		}
		x = loaded_table_027D7E_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)unk_4877 << 1))
		{
		case 0:
			sub_026E5E();
			break;
		case 2:
			sub_0270B4(&x, &y, &u);
			break;
		case 4:
			sub_0270E9(&x, &y);
			break;
		case -32:
		case -8:
		case -2:
		case 6:
		case 12:
			x = sub_026EE4();
			break;
		case 8:
			sub_026E56();
			break;
		case 10:
			sub_027151(&x, &y, &u);
			break;
		case -70:
			sub_026DA8(x);
			break;
		case -68:
			sub_026DB8(x);
			break;
		case -66:
			sub_026DD3(x);
			break;
		case -64:
			sub_026DFA(x);
			break;
		case -62:
			sub_026E16(x);
			break;
		case -60:
			sub_026E32(&x, &y, &u);
			break;
		case -58:
			sub_026F1E(&x, &y, &u);
			break;
		case -56:
		case -52:
		case -46:
		case -40:
			sub_026E2F(&y, &u);
			break;
		case -54:
			sub_026F5D(&x, &y, &u);
			break;
		case -50:
			sub_026FB9(&x, &y, &u);
			break;
		case -48:
			sub_026FF8(&x, &y, &u);
			break;
		case -44:
			sub_027059(&x, &y, &u);
			break;
		case -42:
			continue;
		case -38:
			sub_027135(&x, &y, &u);
			break;
		case -36:
			sub_026E4E();
			break;
		case -34:
			sub_026E8C(&x, &y, &u);
			break;
		case -30:
		case -18:
			sub_026E76();
			break;
		case -28:
			sub_026F3A(&x, &y, &u);
			break;
		case -26:
			x = sub_026ED4();
			break;
		case -24:
			sub_026F79();
			break;
		case -22:
			sub_026F83(&x, &y, &u);
			break;
		case -20:
			x = sub_026EB4();
			break;
		case -16:
			sub_026FD5(&x, &y, &u);
			break;
		case -14:
			x = sub_026EC4();
			break;
		case -12:
			sub_027014();
			break;
		case -10:
			sub_02701E(&x, &y, &u);
			break;
		case -6:
			sub_026E6E();
			break;
		case -4:
			sub_027075(&x, &y, &u);
			break;
		}
		break;
	}
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

void sub_0270B4(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t d = 0, u_2 = 0, x = 0, y = 0;

	sub_0271F5(u);
	sub_0271CF();
	u_2 = text_027E3D_ADDRESS;
	d = 0u;
	sub_0785A5(d, &x, &u_2);
	d = 0x600u;
	y = sub_02719A(d);
	mem_write16(y + 0x11u, 0x82u);
	mem_write16(y + 0xFu, 0xFF00u);
	mem_write16(y + 0x19u, 0x100u);
	d = 0x900u;
	y = sub_02719A(d);
	mem_write8(y + 9u, 0u);
	unk_4805 = (unk_4805 & 0xFF00u) | 0x80u;
	unk_4877++;
	*p_x = x;
	*p_y = y;
	*p_u = u_2;
}

void sub_0270E9(uint16_t *p_x, uint16_t *p_y)
{
	uint8_t d = 0;
	uint16_t d_2 = 0, x = 0, y = 0;
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0;

	unk_4DA6 |= 0x40u;
	io_write8(IO_1FB9, 0x13u);
	io_write8(IO_1FBA, 0x2Cu);
	x = unk_4D40_ADDRESS;
	t1 = unk_4D4C;
	if (t1 == 0xE0u)
		unk_4D4F = 0u;
	t2 = unk_4D56;
	d = (uint8_t)t2;
	if ((uint16_t)(((uint32_t)(t2 >> 8) << 8) | (d & 0xFFu)) == 0x46u)
	{
		d = 0u;
		unk_4D59 = 0u;
	}
	t3 = (uint8_t)unk_4805;
	unk_4805 = (unk_4805 & 0xFF00u) | (t3 - 1u & 0xFFu);
	if (t3 != 1u)
	{
		x = sub_026EE4();
		*p_x = x;
		return;
	}
	d_2 = (d & 0xFFu) | 0x700u;
	y = sub_02719A(d_2);
	mem_write16(y + 0x11u, 0x82u);
	unk_4877++;
	x = sub_026EE4();
	*p_x = x;
	*p_y = y;
}

void sub_027135(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t d = 0;

	for (;;)
	{
		unk_4805 = (unk_4805 & 0xFFu) | (((uint8_t)(unk_4805 >> 8u) + 1u & 0xFFu) << 8u);
		if ((uint8_t)(unk_4805 >> 8u) == 0xC0u)
		{
			sub_02716F(&x, &y, &u);
			break;
		}
		d = unk_4000_ADDRESS;
		sub_078653(d, &x, &carry);
		if (carry)
		{
			sub_02716F(&x, &y, &u);
			break;
		}
		x = loaded_table_027D86_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)unk_4877 << 1))
		{
		case 0:
			sub_026E56();
			break;
		case 2:
			sub_027151(&x, &y, &u);
			break;
		case -40:
		case -16:
		case -10:
		case -2:
		case 4:
			x = sub_026EE4();
			break;
		case -78:
			sub_026DA8(x);
			break;
		case -76:
			sub_026DB8(x);
			break;
		case -74:
			sub_026DD3(x);
			break;
		case -72:
			sub_026DFA(x);
			break;
		case -70:
			sub_026E16(x);
			break;
		case -68:
			sub_026E32(&x, &y, &u);
			break;
		case -66:
			sub_026F1E(&x, &y, &u);
			break;
		case -64:
		case -60:
		case -54:
		case -48:
			sub_026E2F(&y, &u);
			break;
		case -62:
			sub_026F5D(&x, &y, &u);
			break;
		case -58:
			sub_026FB9(&x, &y, &u);
			break;
		case -56:
			sub_026FF8(&x, &y, &u);
			break;
		case -52:
			sub_027059(&x, &y, &u);
			break;
		case -50:
			sub_027098(&x, &y, &u);
			break;
		case -46:
			continue;
		case -44:
			sub_026E4E();
			break;
		case -42:
			sub_026E8C(&x, &y, &u);
			break;
		case -38:
		case -26:
			sub_026E76();
			break;
		case -36:
			sub_026F3A(&x, &y, &u);
			break;
		case -34:
			x = sub_026ED4();
			break;
		case -32:
			sub_026F79();
			break;
		case -30:
			sub_026F83(&x, &y, &u);
			break;
		case -28:
			x = sub_026EB4();
			break;
		case -24:
			sub_026FD5(&x, &y, &u);
			break;
		case -22:
			x = sub_026EC4();
			break;
		case -20:
			sub_027014();
			break;
		case -18:
			sub_02701E(&x, &y, &u);
			break;
		case -14:
			sub_026E6E();
			break;
		case -12:
			sub_027075(&x, &y, &u);
			break;
		case -8:
			sub_026E5E();
			break;
		case -6:
			sub_0270B4(&x, &y, &u);
			break;
		case -4:
			sub_0270E9(&x, &y);
			break;
		}
		break;
	}
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

void sub_027151(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t d = 0, u_2 = 0, x = 0, y = 0;

	sub_0271F5(u);
	sub_0271CF();
	u_2 = text_027E53_ADDRESS;
	d = 0u;
	sub_0785A5(d, &x, &u_2);
	d = 0x800u;
	sub_02719A(d);
	d = 0x900u;
	y = sub_02719A(d);
	mem_write8(y + 9u, 0u);
	unk_4877++;
	*p_x = x;
	*p_y = y;
	*p_u = u_2;
}

void sub_02716F(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, u_2 = 0, x = 0, y = 0;

	d = 0u;
	carry = sub_078680(d);
	unk_487E = 1u;
	d = 0x880u;
	sub_078677(d, &ignored16, &u);
	sub_07869B(&ignored16_2, &ignored16_3);
	y = sub_078695();
	sub_07868C(&x, &u_2);
	unk_4805 &= 0xFFu;
	unk_4804++;
	*p_x = x;
	*p_y = y;
	*p_u = u_2;
}

uint16_t sub_02719A(uint16_t d)
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
	t2 = stage_title_placements_ADDRESS + (((((uint32_t)a << 1) | carry) << 8) | (uint8_t)((uint32_t)b << 1));
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
	io_write8(object + 9u, 0x20u);
	return object;
}

void sub_0271CF(void)
{
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, ignored16_4 = 0;

	sub_07869B(&ignored16, &ignored16_2);
	unk_4875 = 2u;
	unk_4876 = 0u;
	sub_0786B0();
	io_write8(IO_1FB9, 0x3Fu);
	io_write8(IO_1FBA, 0x36u);
	d = 0x12Cu;
	sub_0786AD(d, &ignored16, &ignored16_3, &ignored16_4);
}

void sub_0271F5(uint16_t u)
{
	uint16_t d = 0, ignored16 = 0;

	unk_487E = 1u;
	d = 0xF0Cu;
	sub_078677(d, &ignored16, &u);
	sub_027200(&ignored16, &u);
}

void sub_027200(uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t d = 0;

	unk_487E = 2u;
	d = 7u;
	sub_078677(d, &y, &u);
	unk_487E = 2u;
	d = 8u;
	sub_078677(d, &y, &u);
	unk_487E = 2u;
	d = 9u;
	sub_078677(d, &y, &u);
	unk_487E = 2u;
	d = 0xAu;
	*p_y = y;
	*p_u = u;
	sub_078677(d, p_y, p_u);
}

uint16_t sub_02724D(uint16_t u)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, u_2 = 0, x = 0;
	uint8_t t1 = 0;

	d = 0u;
	sub_0786C2(d);
	d = 0x10u;
	sub_0786C5(d);
	unk_487E = 1u;
	d = 0xE81u;
	sub_078677(d, &ignored16, &u);
	unk_487E = 1u;
	d = 0x805u;
	sub_078677(d, &ignored16, &u);
	d = 0x9100u;
	carry = sub_078680(d);
	d = 0x4600u;
	carry = sub_078680(d);
	io_write8(IO_1FB9, 0x3Fu);
	io_write8(IO_1FBA, 0x36u);
	unk_4875 = 0x82u;
	unk_4876 = 0u;
	sub_0786B0();
	d = 0x2Cu;
	sub_0786AD(d, &ignored16_2, &ignored16, &ignored16_3);
	d = 0x12Cu;
	sub_0786AD(d, &ignored16_2, &ignored16, &ignored16_3);
	io_write8(IO_1FB9, 0x13u);
	io_write8(IO_1FBA, 0x2Cu);
	u_2 = object_start_027F9D_ADDRESS;
	sub_0277D6(u_2);
	u_2 = object_start_027FB1_ADDRESS;
	x = sub_0277D6(u_2);
	io_write8(0x18E3u, 0xB0u);
	t1 = io_read8(VIDEO_18E2);
	io_write8(VIDEO_18E2, t1 + 1u);
	return x;
}

uint16_t sub_0272CA(uint16_t u)
{
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, u_2 = 0, x = 0;
	uint8_t t1 = 0, t2 = 0;

	d = 0x4000u | b;
	sub_078653(d, &ignored16, &carry);
	if (carry == 0u)
	{
		t1 = io_read8(0x18E3u);
		io_write8(0x18E3u, t1 - 1u);
		if (t1 != 1u)
		{
			sub_0275AB();
			sub_027656();
			sub_027767();
			x = sub_0277A7();
			return x;
		}
	}
	unk_487E = 1u;
	d = 0xF05u;
	sub_078677(d, &ignored16_2, &u);
	io_write8(IO_1FB9, 0x3Fu);
	io_write8(IO_1FBA, 0x36u);
	unk_48BE = 0xFFF0u;
	unk_48C5 = 0u;
	unk_4875 = 0x81u;
	unk_4876 = 0u;
	sub_0786B0();
	d = 0x2Cu;
	sub_0786AD(d, &ignored16, &ignored16_2, &u_2);
	sub_078698();
	io_write8(IO_1FB9, 0x13u);
	io_write8(IO_1FBA, 0x2Cu);
	unk_4878 = 0u;
	unk_487E = 2u;
	d = 3u;
	sub_078677(d, &ignored16_2, &u_2);
	io_write16(VIDEO_18E7, u_2);
	d = 0x3F25u;
	carry = sub_078680(d);
	sub_07868C(&ignored16, &ignored16_3);
	u_2 = object_start_027FBB_ADDRESS;
	x = sub_0277D6(u_2);
	mem_write16(x + 0x14u, 0x180u);
	unk_4897 = 1u;
	unk_4898 = 1u;
	io_write8(0x18E3u, 0x50u);
	t2 = io_read8(VIDEO_18E2);
	io_write8(VIDEO_18E2, t2 + 1u);
	return x;
}

uint16_t sub_027369(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, u = 0;
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	d = 0x4000u | b;
	sub_078653(d, &x, &carry);
	if (carry == 0u)
	{
		t1 = io_read8(0x18E3u);
		io_write8(0x18E3u, t1 - 1u);
		if (t1 != 1u)
			return x;
	}
	t2 = io_read16(VIDEO_18E7);
	mem_write8(t2, 0u);
	unk_48CE = 0xFFF0u;
	unk_48D5 = 0u;
	unk_4876 = 0u;
	io_write8(IO_1FB9, 0x3Fu);
	io_write8(IO_1FBA, 0x36u);
	d = 0x124u;
	sub_0786AD(d, &ignored16, &ignored16_2, &ignored16_3);
	unk_48CE = 0xF0u;
	unk_48BE = 0x10u;
	unk_48C5 = 0x200u;
	unk_4876 = 1u;
	d = 0x2Cu;
	sub_0786AD(d, &ignored16, &ignored16_2, &ignored16_3);
	io_write8(IO_1FB9, 0x13u);
	io_write8(IO_1FBA, 0x2Cu);
	sub_07868C(&ignored16, &ignored16_3);
	u = object_start_027FC5_ADDRESS;
	x = sub_0277D6(u);
	t3 = io_read8(VIDEO_18E2);
	io_write8(VIDEO_18E2, t3 + 1u);
	return x;
}

uint16_t sub_0273DB(uint16_t u)
{
	uint32_t carry = 0;
	uint16_t d = 0, x = 0;
	uint8_t t1 = 0, t2 = 0;

	for (;;)
	{
		d = unk_4000_ADDRESS;
		sub_078653(d, &x, &carry);
		if (carry)
		{
			t1 = io_read8(VIDEO_18E0);
			io_write8(VIDEO_18E0, t1 + 1u);
			return sub_0274CF();
		}
		x = loaded_table_027EDD_ADDRESS;
		t2 = io_read8(VIDEO_18E1);
		switch ((int8_t)(uint8_t)((uint32_t)t2 << 1))
		{
		case 0:
			sub_0273F4();
			return x;
		case 2:
			sub_027417(u);
			return x;
		case 4:
			sub_027448();
			return x;
		case 6:
			return sub_027494(x);
		case 8:
			return sub_0274C8(x);
		case 10:
			sub_027534();
			return x;
		case 12:
			sub_02753F();
			return x;
		case 14:
		case 18:
		case 22:
		case 26:
			sub_02755C();
			return x;
		case 16:
		case 20:
		case 24:
		case 28:
			sub_027573();
			return x;
		case 30:
			return sub_02759A(x);
		case 32:
			return sub_0275C7(x);
		case 34:
			return sub_0275E5(x);
		case 36:
			return sub_027619(x);
		case 38:
			return sub_027637(x);
		case 40:
			return sub_0275D0();
		case 42:
		case 48:
		case 52:
		case 56:
			sub_027655();
			return x;
		case 44:
			return sub_0275EE();
		case 46:
			sub_027608(x);
			return x;
		case 50:
			return sub_027622();
		case 54:
			return sub_027640();
		case 58:
			return sub_027680(x);
		case 60:
			return sub_027701(x);
		case 62:
			return sub_02771E(x);
		case 64:
			return sub_027689();
		case 66:
			sub_0276A3(x);
			return x;
		case 68:
			sub_0276C6(x);
			return x;
		case 70:
			sub_0276E3(x);
			return x;
		case 72:
			sub_027700();
			return x;
		case 74:
			return sub_02770A();
		case 76:
		case 84:
			sub_02773B(x);
			return x;
		case 78:
		case 86:
			sub_027749(x);
			return x;
		case 80:
		case 88:
			sub_027766();
			return x;
		case 82:
			return sub_027727();
		case 90:
			return sub_027773();
		case 92:
			sub_027782(x);
			return x;
		case 94:
			sub_027799(x);
			return x;
		case 96:
			sub_0277A6();
			return x;
		case 98:
			sub_0277B8(x);
			return x;
		case 100:
			break;
		case -12:
			return sub_02724D(u);
		case -10:
			return sub_0272CA(u);
		case -8:
			return sub_027369(x);
		case -6:
			continue;
		case -4:
			return sub_02748A(u);
		case -2:
			return sub_027523(u);
		}
		break;
	}
	sub_0277CC(x);
	return x;
}

void sub_0273F4(void)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	unk_48CA = 0u;
	io_write16(0x18E5u, 0xFA00u);
	unk_48A9 = 1u;
	unk_489D = 1u;
	unk_4899 = 1u;
	d = 0x101u;
	carry = sub_078680(d);
	t1 = io_read8(VIDEO_18E1);
	io_write8(VIDEO_18E1, t1 + 1u);
}

void sub_027417(uint16_t u)
{
	uint8_t a = 0;
	uint16_t d = 0, ignored16 = 0;
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0;

	unk_4F99 = 0x70u;
	t1 = io_read16(0x18E5u);
	t2 = t1 + 0xAu;
	a = (uint8_t)(t2 >> 8);
	io_write16(0x18E5u, ((uint32_t)a << 8) | (t2 & 0xFFu));
	if (a != 0u)
	{
		sub_027460();
		return;
	}
	unk_487E = 2u;
	d = 4u;
	sub_078677(d, &ignored16, &u);
	io_write8(0x18E3u, 0x98u);
	unk_48CA = 0xE0u;
	t3 = io_read8(VIDEO_18E1);
	io_write8(VIDEO_18E1, t3 + 1u);
}

void sub_027448(void)
{
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	t1 = io_read8(0x18E3u);
	io_write8(0x18E3u, t1 - 1u);
	if (t1 != 1u)
	{
		t2 = io_read16(0x18E5u);
		io_write16(0x18E5u, t2 + 0xAu);
		unk_4F99 = rom_07FFA0_ADDRESS;
		sub_027460();
		return;
	}
	unk_48A9 = 0u;
	unk_489D = 0u;
	unk_4899 = 0u;
	io_write8(0x18E3u, 0x18u);
	t3 = io_read8(VIDEO_18E2);
	io_write8(VIDEO_18E2, t3 + 1u);
}

void sub_027460(void)
{
	uint32_t carry = 0;
	uint8_t t5 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = AT16(unk_48C5, -1);
	t2 = io_read16(0x18E5u);
	t3 = t1;
	t4 = t3 + t2;
	carry = (uint16_t)(t3 + t2) < t3;
	AT16(unk_48C5, -1) = t4;
	t5 = io_read8(0x18E5u);
	unk_48C5 = (unk_48C5 & 0xFFu) | ((((uint16_t)(int8_t)t5 >> 8) + (uint8_t)(unk_48C5 >> 8u) + carry & 0xFFu) << 8u);
}

uint16_t sub_02748A(uint16_t u)
{
	uint16_t x = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		x = loaded_table_027EE3_ADDRESS;
		t1 = io_read8(VIDEO_18E1);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			return sub_027494(x);
		case 2:
			return sub_0274C8(x);
		case 4:
			sub_027534();
			return x;
		case 6:
			sub_02753F();
			return x;
		case 8:
		case 12:
		case 16:
		case 20:
			sub_02755C();
			return x;
		case 10:
		case 14:
		case 18:
		case 22:
			sub_027573();
			return x;
		case 24:
			return sub_02759A(x);
		case 26:
			return sub_0275C7(x);
		case 28:
			return sub_0275E5(x);
		case 30:
			return sub_027619(x);
		case 32:
			return sub_027637(x);
		case 34:
			return sub_0275D0();
		case 36:
		case 42:
		case 46:
		case 50:
			sub_027655();
			return x;
		case 38:
			return sub_0275EE();
		case 40:
			sub_027608(x);
			return x;
		case 44:
			return sub_027622();
		case 48:
			return sub_027640();
		case 52:
			return sub_027680(x);
		case 54:
			return sub_027701(x);
		case 56:
			return sub_02771E(x);
		case 58:
			return sub_027689();
		case 60:
			sub_0276A3(x);
			return x;
		case 62:
			sub_0276C6(x);
			return x;
		case 64:
			sub_0276E3(x);
			return x;
		case 66:
			sub_027700();
			return x;
		case 68:
			return sub_02770A();
		case 70:
		case 78:
			sub_02773B(x);
			return x;
		case 72:
		case 80:
			sub_027749(x);
			return x;
		case 74:
		case 82:
			sub_027766();
			return x;
		case 76:
			return sub_027727();
		case 84:
			return sub_027773();
		case 86:
			sub_027782(x);
			return x;
		case 88:
			sub_027799(x);
			return x;
		case 90:
			sub_0277A6();
			return x;
		case 92:
			sub_0277B8(x);
			return x;
		case 94:
			break;
		case -18:
			return sub_02724D(u);
		case -16:
			return sub_0272CA(u);
		case -14:
			return sub_027369(x);
		case -12:
			return sub_0273DB(u);
		case -10:
			continue;
		case -8:
			return sub_027523(u);
		case -6:
			sub_0273F4();
			return x;
		case -4:
			sub_027417(u);
			return x;
		case -2:
			sub_027448();
			return x;
		}
		break;
	}
	sub_0277CC(x);
	return x;
}

uint16_t sub_027494(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0, u = 0, x_2 = 0;
	uint8_t t1 = 0, t2 = 0;
	uint16_t t3 = 0, t4 = 0;

	t1 = io_read8(0x18E3u);
	io_write8(0x18E3u, t1 - 1u);
	if (t1 == 1u)
	{
		u = object_start_027FCF_ADDRESS;
		x_2 = sub_0277D6(u);
		mem_write16(x_2 + 0x19u, 0u);
		d = 0x4400u;
		carry = sub_078680(d);
		io_write8(0x18E3u, 0x40u);
		t2 = io_read8(VIDEO_18E1);
		io_write8(VIDEO_18E1, t2 + 1u);
		return x_2;
	}
	t3 = AT16(unk_48CE, -1);
	t4 = t3;
	carry = (uint16_t)(t4 + 0xA00u) < t4;
	AT16(unk_48CE, -1) = t4 + 0xA00u;
	unk_48CE = (unk_48CE & 0xFFu) | ((0u + (uint8_t)(unk_48CE >> 8u) + carry & 0xFFu) << 8u);
	return x;
}

uint16_t sub_0274C8(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = io_read8(0x18E3u);
	io_write8(0x18E3u, t1 - 1u);
	if (t1 == 1u)
		return sub_0274CF();
	return x;
}

uint16_t sub_0274CF(void)
{
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, u = 0, x = 0;
	uint8_t t1 = 0;

	unk_48BE = 0x110u;
	unk_48C5 = 0u;
	unk_48CE = 0x110u;
	unk_48D5 = 0u;
	io_write8(IO_1FB9, 0x3Fu);
	io_write8(IO_1FBA, 0x36u);
	unk_4876 = 0u;
	d = 0x2Cu;
	sub_0786AD(d, &ignored16, &ignored16_2, &ignored16_3);
	d = 0x12Cu;
	sub_0786AD(d, &ignored16, &ignored16_2, &ignored16_3);
	io_write8(IO_1FB9, 0x13u);
	io_write8(IO_1FBA, 0x2Cu);
	sub_07868C(&ignored16, &ignored16_3);
	u = object_start_027FD9_ADDRESS;
	x = sub_0277D6(u);
	t1 = io_read8(VIDEO_18E2);
	io_write8(VIDEO_18E2, t1 + 1u);
	return x;
}

uint16_t sub_027523(uint16_t u)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, x = 0;
	uint8_t t1 = 0, t2 = 0;

	for (;;)
	{
		d = unk_4000_ADDRESS;
		sub_078653(d, &x, &carry);
		if (carry)
			break;
		x = loaded_table_027EE7_ADDRESS;
		t1 = io_read8(VIDEO_18E1);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			sub_027534();
			return x;
		case 2:
			sub_02753F();
			return x;
		case 4:
		case 8:
		case 12:
		case 16:
			sub_02755C();
			return x;
		case 6:
		case 10:
		case 14:
		case 18:
			sub_027573();
			return x;
		case 20:
			return sub_02759A(x);
		case 22:
			return sub_0275C7(x);
		case 24:
			return sub_0275E5(x);
		case 26:
			return sub_027619(x);
		case 28:
			return sub_027637(x);
		case 30:
			return sub_0275D0();
		case 32:
		case 38:
		case 42:
		case 46:
			sub_027655();
			return x;
		case 34:
			return sub_0275EE();
		case 36:
			sub_027608(x);
			return x;
		case 40:
			return sub_027622();
		case 44:
			return sub_027640();
		case 48:
			return sub_027680(x);
		case 50:
			return sub_027701(x);
		case 52:
			return sub_02771E(x);
		case 54:
			return sub_027689();
		case 56:
			sub_0276A3(x);
			return x;
		case 58:
			sub_0276C6(x);
			return x;
		case 60:
			sub_0276E3(x);
			return x;
		case 62:
			sub_027700();
			return x;
		case 64:
			return sub_02770A();
		case 66:
		case 74:
			sub_02773B(x);
			return x;
		case 68:
		case 76:
			sub_027749(x);
			return x;
		case 70:
		case 78:
			sub_027766();
			return x;
		case 72:
			return sub_027727();
		case 80:
			return sub_027773();
		case 82:
			sub_027782(x);
			return x;
		case 84:
			sub_027799(x);
			return x;
		case 86:
			sub_0277A6();
			return x;
		case 88:
			sub_0277B8(x);
			return x;
		case 90:
			sub_0277CC(x);
			return x;
		case -22:
			return sub_02724D(u);
		case -20:
			return sub_0272CA(u);
		case -18:
			return sub_027369(x);
		case -16:
			return sub_0273DB(u);
		case -14:
			return sub_02748A(u);
		case -12:
			continue;
		case -10:
			sub_0273F4();
			return x;
		case -8:
			sub_027417(u);
			return x;
		case -6:
			sub_027448();
			return x;
		case -4:
			return sub_027494(x);
		case -2:
			return sub_0274C8(x);
		}
	}
	unk_4872 = 0u;
	sub_07868C(&x, &ignored16);
	t2 = io_read8(VIDEO_18E2);
	io_write8(VIDEO_18E2, t2 + 1u);
	return x;
}

void sub_027534(void)
{
	uint8_t t1 = 0;

	io_write8(0x18E3u, 0x20u);
	t1 = io_read8(VIDEO_18E1);
	io_write8(VIDEO_18E1, t1 + 1u);
}

void sub_02753F(void)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	io_write8(0x18E3u, 0x38u);
	d = 0x3F09u;
	carry = sub_078680(d);
	d = 0x3F0Au;
	carry = sub_078680(d);
	d = 0x3F0Bu;
	carry = sub_078680(d);
	t1 = io_read8(VIDEO_18E1);
	io_write8(VIDEO_18E1, t1 + 1u);
}

void sub_02755C(void)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = io_read8(0x18E3u);
	io_write8(0x18E3u, t1 - 1u);
	if (t1 == 1u)
	{
		unk_4F80 = 4u;
		io_write8(0x18E3u, 8u);
		t2 = io_read8(VIDEO_18E1);
		io_write8(VIDEO_18E1, t2 + 1u);
	}
}

void sub_027573(void)
{
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = io_read8(0x18E3u);
	io_write8(0x18E3u, t1 - 1u);
	if (t1 != 1u)
		return;
	d = 0x4A00u;
	carry = sub_078680(d);
	unk_4F80 = 0x80u;
	b = 8u;
	t2 = io_read8(VIDEO_18E1);
	if (t2 == 9u)
		b = 0x80u;
	io_write8(0x18E3u, b);
	t3 = io_read8(VIDEO_18E1);
	io_write8(VIDEO_18E1, t3 + 1u);
}

uint16_t sub_02759A(uint16_t x)
{
	uint16_t ignored16 = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = io_read8(0x18E3u);
	io_write8(0x18E3u, t1 - 1u);
	if (t1 != 1u)
		return x;
	unk_4872 = 0u;
	sub_07868C(&x, &ignored16);
	t2 = io_read8(VIDEO_18E2);
	io_write8(VIDEO_18E2, t2 + 1u);
	return x;
}

void sub_0275AB(void)
{
	uint16_t u = 0, x = 0;
	uint8_t stack = 0;

	x = unk_4A40_ADDRESS;
	stack = 0u;
	do
	{
		u = loaded_table_027EFD_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)stack << 1))
		{
		case 0:
			x = sub_0275C7(x);
			break;
		case 2:
			x = sub_0275E5(x);
			break;
		case 4:
			x = sub_027619(x);
			break;
		case 6:
			x = sub_027637(x);
			break;
		case 8:
			x = sub_0275D0();
			break;
		case 10:
		case 16:
		case 20:
		case 24:
			sub_027655();
			break;
		case 12:
			x = sub_0275EE();
			break;
		case 14:
			sub_027608(x);
			break;
		case 18:
			x = sub_027622();
			break;
		case 22:
			x = sub_027640();
			break;
		case 26:
			x = sub_027680(x);
			break;
		case 28:
			x = sub_027701(x);
			break;
		case 30:
			x = sub_02771E(x);
			break;
		case 32:
			x = sub_027689();
			break;
		case 34:
			sub_0276A3(x);
			break;
		case 36:
			sub_0276C6(x);
			break;
		case 38:
			sub_0276E3(x);
			break;
		case 40:
			sub_027700();
			break;
		case 42:
			x = sub_02770A();
			break;
		case 44:
		case 52:
			sub_02773B(x);
			break;
		case 46:
		case 54:
			sub_027749(x);
			break;
		case 48:
		case 56:
			sub_027766();
			break;
		case 50:
			x = sub_027727();
			break;
		case 58:
			x = sub_027773();
			break;
		case 60:
			sub_027782(x);
			break;
		case 62:
			sub_027799(x);
			break;
		case 64:
			sub_0277A6();
			break;
		case 66:
			sub_0277B8(x);
			break;
		case 68:
			sub_0277CC(x);
			break;
		case -44:
			x = sub_02724D(u);
			break;
		case -42:
			x = sub_0272CA(u);
			break;
		case -40:
			x = sub_027369(x);
			break;
		case -38:
			x = sub_0273DB(u);
			break;
		case -36:
			x = sub_02748A(u);
			break;
		case -34:
			x = sub_027523(u);
			break;
		case -32:
			sub_0273F4();
			break;
		case -30:
			sub_027417(u);
			break;
		case -28:
			sub_027448();
			break;
		case -26:
			x = sub_027494(x);
			break;
		case -24:
			x = sub_0274C8(x);
			break;
		case -22:
			sub_027534();
			break;
		case -20:
			sub_02753F();
			break;
		case -18:
		case -14:
		case -10:
		case -6:
			sub_02755C();
			break;
		case -16:
		case -12:
		case -8:
		case -4:
			sub_027573();
			break;
		case -2:
			x = sub_02759A(x);
			break;
		}
		x += 0xC0u;
		stack = stack + 1u;
	} while (stack != 4u);
}

uint16_t sub_0275C7(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_027F05_ADDRESS;
		t1 = mem_read8(x + 1u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			return sub_0275D0();
		case 2:
		case 8:
		case 12:
		case 16:
			sub_027655();
			return x;
		case 4:
			return sub_0275EE();
		case 6:
			sub_027608(x);
			return x;
		case 10:
			return sub_027622();
		case 14:
			return sub_027640();
		case 18:
			return sub_027680(x);
		case 20:
			return sub_027701(x);
		case 22:
			return sub_02771E(x);
		case 24:
			return sub_027689();
		case 26:
			sub_0276A3(x);
			return x;
		case 28:
			sub_0276C6(x);
			return x;
		case 30:
			sub_0276E3(x);
			return x;
		case 32:
			sub_027700();
			return x;
		case 34:
			return sub_02770A();
		case 36:
		case 44:
			sub_02773B(x);
			return x;
		case 38:
		case 46:
			sub_027749(x);
			return x;
		case 40:
		case 48:
			sub_027766();
			return x;
		case 42:
			return sub_027727();
		case 50:
			return sub_027773();
		case 52:
			sub_027782(x);
			return x;
		case 54:
			sub_027799(x);
			return x;
		case 56:
			sub_0277A6();
			return x;
		case 58:
			sub_0277B8(x);
			return x;
		case 60:
			break;
		case -52:
			return sub_02724D(u);
		case -50:
			return sub_0272CA(u);
		case -48:
			return sub_027369(x);
		case -46:
			return sub_0273DB(u);
		case -44:
			return sub_02748A(u);
		case -42:
			return sub_027523(u);
		case -40:
			sub_0273F4();
			return x;
		case -38:
			sub_027417(u);
			return x;
		case -36:
			sub_027448();
			return x;
		case -34:
			return sub_027494(x);
		case -32:
			return sub_0274C8(x);
		case -30:
			sub_027534();
			return x;
		case -28:
			sub_02753F();
			return x;
		case -26:
		case -22:
		case -18:
		case -14:
			sub_02755C();
			return x;
		case -24:
		case -20:
		case -16:
		case -12:
			sub_027573();
			return x;
		case -10:
			return sub_02759A(x);
		case -8:
			continue;
		case -6:
			return sub_0275E5(x);
		case -4:
			return sub_027619(x);
		case -2:
			return sub_027637(x);
		}
		break;
	}
	sub_0277CC(x);
	return x;
}

uint16_t sub_0275D0(void)
{
	uint16_t u = 0, x = 0;
	uint8_t t1 = 0;

	u = object_start_027F43_ADDRESS;
	x = sub_0277D6(u);
	mem_write8(x + 9u, 0x40u);
	mem_write16(x + 0xFu, 0xFF00u);
	t1 = mem_read8(x + 1u);
	mem_write8(x + 1u, t1 + 1u);
	return x;
}

uint16_t sub_0275E5(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_027F09_ADDRESS;
		t1 = mem_read8(x + 1u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			return sub_0275EE();
		case 2:
			sub_027608(x);
			return x;
		case -2:
		case 4:
		case 8:
		case 12:
			sub_027655();
			return x;
		case 6:
			return sub_027622();
		case 10:
			return sub_027640();
		case 14:
			return sub_027680(x);
		case 16:
			return sub_027701(x);
		case 18:
			return sub_02771E(x);
		case 20:
			return sub_027689();
		case 22:
			sub_0276A3(x);
			return x;
		case 24:
			sub_0276C6(x);
			return x;
		case 26:
			sub_0276E3(x);
			return x;
		case 28:
			sub_027700();
			return x;
		case 30:
			return sub_02770A();
		case 32:
		case 40:
			sub_02773B(x);
			return x;
		case 34:
		case 42:
			sub_027749(x);
			return x;
		case 36:
		case 44:
			sub_027766();
			return x;
		case 38:
			return sub_027727();
		case 46:
			return sub_027773();
		case 48:
			sub_027782(x);
			return x;
		case 50:
			sub_027799(x);
			return x;
		case 52:
			sub_0277A6();
			return x;
		case 54:
			sub_0277B8(x);
			return x;
		case 56:
			break;
		case -56:
			return sub_02724D(u);
		case -54:
			return sub_0272CA(u);
		case -52:
			return sub_027369(x);
		case -50:
			return sub_0273DB(u);
		case -48:
			return sub_02748A(u);
		case -46:
			return sub_027523(u);
		case -44:
			sub_0273F4();
			return x;
		case -42:
			sub_027417(u);
			return x;
		case -40:
			sub_027448();
			return x;
		case -38:
			return sub_027494(x);
		case -36:
			return sub_0274C8(x);
		case -34:
			sub_027534();
			return x;
		case -32:
			sub_02753F();
			return x;
		case -30:
		case -26:
		case -22:
		case -18:
			sub_02755C();
			return x;
		case -28:
		case -24:
		case -20:
		case -16:
			sub_027573();
			return x;
		case -14:
			return sub_02759A(x);
		case -12:
			return sub_0275C7(x);
		case -10:
			continue;
		case -8:
			return sub_027619(x);
		case -6:
			return sub_027637(x);
		case -4:
			return sub_0275D0();
		}
		break;
	}
	sub_0277CC(x);
	return x;
}

uint16_t sub_0275EE(void)
{
	uint16_t u = 0, x = 0;
	uint8_t t1 = 0;

	u = object_start_027F4D_ADDRESS;
	x = sub_0277D6(u);
	mem_write8(x + 9u, 0x40u);
	mem_write16(x + 0xFu, 0xFF00u);
	mem_write8(x + 0x28u, 0xA8u);
	t1 = mem_read8(x + 1u);
	mem_write8(x + 1u, t1 + 1u);
	return x;
}

void sub_027608(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 5u, 0xD1u);
		mem_write16(x + 0xFu, 0u);
		t2 = mem_read8(x + 1u);
		mem_write8(x + 1u, t2 + 1u);
	}
}

uint16_t sub_027619(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_027F0F_ADDRESS;
		t1 = mem_read8(x + 1u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			return sub_027622();
		case -8:
		case -2:
		case 2:
		case 6:
			sub_027655();
			return x;
		case 4:
			return sub_027640();
		case 8:
			return sub_027680(x);
		case 10:
			return sub_027701(x);
		case 12:
			return sub_02771E(x);
		case 14:
			return sub_027689();
		case 16:
			sub_0276A3(x);
			return x;
		case 18:
			sub_0276C6(x);
			return x;
		case 20:
			sub_0276E3(x);
			return x;
		case 22:
			sub_027700();
			return x;
		case 24:
			return sub_02770A();
		case 26:
		case 34:
			sub_02773B(x);
			return x;
		case 28:
		case 36:
			sub_027749(x);
			return x;
		case 30:
		case 38:
			sub_027766();
			return x;
		case 32:
			return sub_027727();
		case 40:
			return sub_027773();
		case 42:
			sub_027782(x);
			return x;
		case 44:
			sub_027799(x);
			return x;
		case 46:
			sub_0277A6();
			return x;
		case 48:
			sub_0277B8(x);
			return x;
		case 50:
			break;
		case 104:
			sub_079C00();
			return x;
		case -62:
			return sub_02724D(u);
		case -60:
			return sub_0272CA(u);
		case -58:
			return sub_027369(x);
		case -56:
			return sub_0273DB(u);
		case -54:
			return sub_02748A(u);
		case -52:
			return sub_027523(u);
		case -50:
			sub_0273F4();
			return x;
		case -48:
			sub_027417(u);
			return x;
		case -46:
			sub_027448();
			return x;
		case -44:
			return sub_027494(x);
		case -42:
			return sub_0274C8(x);
		case -40:
			sub_027534();
			return x;
		case -38:
			sub_02753F();
			return x;
		case -36:
		case -32:
		case -28:
		case -24:
			sub_02755C();
			return x;
		case -34:
		case -30:
		case -26:
		case -22:
			sub_027573();
			return x;
		case -20:
			return sub_02759A(x);
		case -18:
			return sub_0275C7(x);
		case -16:
			return sub_0275E5(x);
		case -14:
			continue;
		case -12:
			return sub_027637(x);
		case -10:
			return sub_0275D0();
		case -6:
			return sub_0275EE();
		case -4:
			sub_027608(x);
			return x;
		}
		break;
	}
	sub_0277CC(x);
	return x;
}

uint16_t sub_027622(void)
{
	uint16_t u = 0, x = 0;
	uint8_t t1 = 0;

	u = object_start_027F57_ADDRESS;
	x = sub_0277D6(u);
	mem_write8(x + 9u, 0x40u);
	mem_write16(x + 0xFu, 0xFF00u);
	t1 = mem_read8(x + 1u);
	mem_write8(x + 1u, t1 + 1u);
	return x;
}

uint16_t sub_027637(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = indexed_table_027F13_ADDRESS;
		t1 = mem_read8(x + 1u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			return sub_027640();
		case -12:
		case -6:
		case -2:
		case 2:
			sub_027655();
			return x;
		case 4:
			return sub_027680(x);
		case 6:
			return sub_027701(x);
		case 8:
			return sub_02771E(x);
		case 10:
			return sub_027689();
		case 12:
			sub_0276A3(x);
			return x;
		case 14:
			sub_0276C6(x);
			return x;
		case 16:
			sub_0276E3(x);
			return x;
		case 18:
			sub_027700();
			return x;
		case 20:
			return sub_02770A();
		case 22:
		case 30:
			sub_02773B(x);
			return x;
		case 24:
		case 32:
			sub_027749(x);
			return x;
		case 26:
		case 34:
			sub_027766();
			return x;
		case 28:
			return sub_027727();
		case 36:
			return sub_027773();
		case 38:
			sub_027782(x);
			return x;
		case 40:
			sub_027799(x);
			return x;
		case 42:
			sub_0277A6();
			return x;
		case 44:
			sub_0277B8(x);
			return x;
		case 46:
			break;
		case -66:
			return sub_02724D(u);
		case -64:
			return sub_0272CA(u);
		case -62:
			return sub_027369(x);
		case -60:
			return sub_0273DB(u);
		case -58:
			return sub_02748A(u);
		case -56:
			return sub_027523(u);
		case -54:
			sub_0273F4();
			return x;
		case -52:
			sub_027417(u);
			return x;
		case -50:
			sub_027448();
			return x;
		case -48:
			return sub_027494(x);
		case -46:
			return sub_0274C8(x);
		case -44:
			sub_027534();
			return x;
		case -42:
			sub_02753F();
			return x;
		case -40:
		case -36:
		case -32:
		case -28:
			sub_02755C();
			return x;
		case -38:
		case -34:
		case -30:
		case -26:
			sub_027573();
			return x;
		case -24:
			return sub_02759A(x);
		case -22:
			return sub_0275C7(x);
		case -20:
			return sub_0275E5(x);
		case -18:
			return sub_027619(x);
		case -16:
			continue;
		case -14:
			return sub_0275D0();
		case -10:
			return sub_0275EE();
		case -8:
			sub_027608(x);
			return x;
		case -4:
			return sub_027622();
		}
		break;
	}
	sub_0277CC(x);
	return x;
}

uint16_t sub_027640(void)
{
	uint16_t u = 0, x = 0;
	uint8_t t1 = 0;

	u = object_start_027F61_ADDRESS;
	x = sub_0277D6(u);
	mem_write8(x + 9u, 0x40u);
	mem_write16(x + 0xFu, 0xFF00u);
	t1 = mem_read8(x + 1u);
	mem_write8(x + 1u, t1 + 1u);
	return x;
}

void sub_027655(void)
{
}

void sub_027656(void)
{
	uint8_t a = 0;
	uint16_t u = 0, x = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0, t2 = 0;

	x = 0x4FE0u;
	stack = 0u;
	do
	{
		u = indexed_table_027F17_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)stack << 1))
		{
		case 0:
			x = sub_027680(x);
			break;
		case 2:
			x = sub_027701(x);
			break;
		case 4:
			x = sub_02771E(x);
			break;
		case 6:
			x = sub_027689();
			break;
		case 8:
			sub_0276A3(x);
			break;
		case 10:
			sub_0276C6(x);
			break;
		case 12:
			sub_0276E3(x);
			break;
		case 14:
			sub_027700();
			break;
		case 16:
			x = sub_02770A();
			break;
		case 18:
		case 26:
			sub_02773B(x);
			break;
		case 20:
		case 28:
			sub_027749(x);
			break;
		case 22:
		case 30:
			sub_027766();
			break;
		case 24:
			x = sub_027727();
			break;
		case 32:
			x = sub_027773();
			break;
		case 34:
			sub_027782(x);
			break;
		case 36:
			sub_027799(x);
			break;
		case 38:
			sub_0277A6();
			break;
		case 40:
			sub_0277B8(x);
			break;
		case 42:
			sub_0277CC(x);
			break;
		case -70:
			x = sub_02724D(u);
			break;
		case -68:
			x = sub_0272CA(u);
			break;
		case -66:
			x = sub_027369(x);
			break;
		case -64:
			x = sub_0273DB(u);
			break;
		case -62:
			x = sub_02748A(u);
			break;
		case -60:
			x = sub_027523(u);
			break;
		case -58:
			sub_0273F4();
			break;
		case -56:
			sub_027417(u);
			break;
		case -54:
			sub_027448();
			break;
		case -52:
			x = sub_027494(x);
			break;
		case -50:
			x = sub_0274C8(x);
			break;
		case -48:
			sub_027534();
			break;
		case -46:
			sub_02753F();
			break;
		case -44:
		case -40:
		case -36:
		case -32:
			sub_02755C();
			break;
		case -42:
		case -38:
		case -34:
		case -30:
			sub_027573();
			break;
		case -28:
			x = sub_02759A(x);
			break;
		case -26:
			x = sub_0275C7(x);
			break;
		case -24:
			x = sub_0275E5(x);
			break;
		case -22:
			x = sub_027619(x);
			break;
		case -20:
			x = sub_027637(x);
			break;
		case -18:
			x = sub_0275D0();
			break;
		case -16:
		case -10:
		case -6:
		case -2:
			sub_027655();
			break;
		case -14:
			x = sub_0275EE();
			break;
		case -12:
			sub_027608(x);
			break;
		case -8:
			x = sub_027622();
			break;
		case -4:
			x = sub_027640();
			break;
		}
		t1 = mem_read8(x + 9u);
		a = t1 & 0xBFu;
		t2 = mem_read8(x + 0xFu);
		if ((int8_t)t2 < 0)
			a |= 0x40u;
		mem_write8(x + 9u, a);
		x += 0x60u;
		stack = stack + 1u;
	} while (stack != 3u);
}

uint16_t sub_027680(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = indexed_table_027F1D_ADDRESS;
		t1 = mem_read8(x + 1u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			return sub_027689();
		case 2:
			sub_0276A3(x);
			return x;
		case 4:
			sub_0276C6(x);
			return x;
		case 6:
			sub_0276E3(x);
			return x;
		case 8:
			sub_027700();
			return x;
		case 10:
			return sub_02770A();
		case 12:
		case 20:
			sub_02773B(x);
			return x;
		case 14:
		case 22:
			sub_027749(x);
			return x;
		case 16:
		case 24:
			sub_027766();
			return x;
		case 18:
			return sub_027727();
		case 26:
			return sub_027773();
		case 28:
			sub_027782(x);
			return x;
		case 30:
			sub_027799(x);
			return x;
		case 32:
			sub_0277A6();
			return x;
		case 34:
			sub_0277B8(x);
			return x;
		case 36:
			break;
		case -76:
			return sub_02724D(u);
		case -74:
			return sub_0272CA(u);
		case -72:
			return sub_027369(x);
		case -70:
			return sub_0273DB(u);
		case -68:
			return sub_02748A(u);
		case -66:
			return sub_027523(u);
		case -64:
			sub_0273F4();
			return x;
		case -62:
			sub_027417(u);
			return x;
		case -60:
			sub_027448();
			return x;
		case -58:
			return sub_027494(x);
		case -56:
			return sub_0274C8(x);
		case -54:
			sub_027534();
			return x;
		case -52:
			sub_02753F();
			return x;
		case -50:
		case -46:
		case -42:
		case -38:
			sub_02755C();
			return x;
		case -48:
		case -44:
		case -40:
		case -36:
			sub_027573();
			return x;
		case -34:
			return sub_02759A(x);
		case -32:
			return sub_0275C7(x);
		case -30:
			return sub_0275E5(x);
		case -28:
			return sub_027619(x);
		case -26:
			return sub_027637(x);
		case -24:
			return sub_0275D0();
		case -22:
		case -16:
		case -12:
		case -8:
			sub_027655();
			return x;
		case -20:
			return sub_0275EE();
		case -18:
			sub_027608(x);
			return x;
		case -14:
			return sub_027622();
		case -10:
			return sub_027640();
		case -6:
			continue;
		case -4:
			return sub_027701(x);
		case -2:
			return sub_02771E(x);
		}
		break;
	}
	sub_0277CC(x);
	return x;
}

uint16_t sub_027689(void)
{
	uint16_t u = 0, x = 0;
	uint8_t t1 = 0;

	u = object_start_027F75_ADDRESS;
	x = sub_0277D6(u);
	mem_write16(x + 0xFu, 0xFE00u);
	mem_write8(x + 0x29u, 0xA0u);
	mem_write8(x + 9u, 0x60u);
	t1 = mem_read8(x + 1u);
	mem_write8(x + 1u, t1 + 1u);
	return x;
}

void sub_0276A3(uint16_t x)
{
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = mem_read16(x + 0xCu);
	if ((int16_t)t1 <= 0xA0)
	{
		mem_write8(x + 5u, 0x8Du);
		mem_write8(x + 9u, 0x88u);
		mem_write16(x + 0xFu, 0u);
		t2 = mem_read16(x + 0x11u);
		mem_write16(x + 0x11u, t2 - 8u);
		t3 = mem_read8(x + 1u);
		mem_write8(x + 1u, t3 + 1u);
	}
}

void sub_0276C6(uint16_t x)
{
	uint16_t u = 0, x_2 = 0;
	uint16_t stack = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) == 0u)
		return;
	mem_write8(x + 9u, 0u);
	u = object_start_027FE3_ADDRESS;
	stack = x;
	sub_0277D6(u);
	x_2 = stack;
	mem_write8(x_2 + 5u, 0x80u);
	t2 = mem_read8(x_2 + 1u);
	mem_write8(x_2 + 1u, t2 + 1u);
}

void sub_0276E3(uint16_t x)
{
	uint8_t a = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x29u);
	t2 = t1;
	a = t2 + 2u;
	mem_write8(x + 0x29u, a);
	if ((uint8_t)(t2 + 2u) < t2)
	{
		mem_write16(x + 0xFu, 0x200u);
		mem_write16(x + 0x14u, 0u);
		t3 = mem_read8(x + 1u);
		mem_write8(x + 1u, t3 + 1u);
		return;
	}
	d = ((uint32_t)a << 8) | 0x40u;
	sub_078617(x, d);
}

void sub_027700(void)
{
}

uint16_t sub_027701(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_027F27_ADDRESS;
		t1 = mem_read8(x + 1u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			return sub_02770A();
		case 2:
		case 10:
			sub_02773B(x);
			return x;
		case 4:
		case 12:
			sub_027749(x);
			return x;
		case 6:
		case 14:
			sub_027766();
			return x;
		case 8:
			return sub_027727();
		case 16:
			return sub_027773();
		case 18:
			sub_027782(x);
			return x;
		case 20:
			sub_027799(x);
			return x;
		case 22:
			sub_0277A6();
			return x;
		case 24:
			sub_0277B8(x);
			return x;
		case 26:
			break;
		case -86:
			return sub_02724D(u);
		case -84:
			return sub_0272CA(u);
		case -82:
			return sub_027369(x);
		case -80:
			return sub_0273DB(u);
		case -78:
			return sub_02748A(u);
		case -76:
			return sub_027523(u);
		case -74:
			sub_0273F4();
			return x;
		case -72:
			sub_027417(u);
			return x;
		case -70:
			sub_027448();
			return x;
		case -68:
			return sub_027494(x);
		case -66:
			return sub_0274C8(x);
		case -64:
			sub_027534();
			return x;
		case -62:
			sub_02753F();
			return x;
		case -60:
		case -56:
		case -52:
		case -48:
			sub_02755C();
			return x;
		case -58:
		case -54:
		case -50:
		case -46:
			sub_027573();
			return x;
		case -44:
			return sub_02759A(x);
		case -42:
			return sub_0275C7(x);
		case -40:
			return sub_0275E5(x);
		case -38:
			return sub_027619(x);
		case -36:
			return sub_027637(x);
		case -34:
			return sub_0275D0();
		case -32:
		case -26:
		case -22:
		case -18:
			sub_027655();
			return x;
		case -30:
			return sub_0275EE();
		case -28:
			sub_027608(x);
			return x;
		case -24:
			return sub_027622();
		case -20:
			return sub_027640();
		case -16:
			return sub_027680(x);
		case -14:
			continue;
		case -12:
			return sub_02771E(x);
		case -10:
			return sub_027689();
		case -8:
			sub_0276A3(x);
			return x;
		case -6:
			sub_0276C6(x);
			return x;
		case -4:
			sub_0276E3(x);
			return x;
		case -2:
			sub_027700();
			return x;
		}
		break;
	}
	sub_0277CC(x);
	return x;
}

uint16_t sub_02770A(void)
{
	uint16_t u = 0, x = 0;
	uint8_t t1 = 0;

	u = object_start_027F7F_ADDRESS;
	x = sub_0277D6(u);
	mem_write8(x + 0x28u, 0x60u);
	mem_write8(x + 0x29u, 0xA0u);
	t1 = mem_read8(x + 1u);
	mem_write8(x + 1u, t1 + 1u);
	return x;
}

uint16_t sub_02771E(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = indexed_table_027F2F_ADDRESS;
		t1 = mem_read8(x + 1u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			return sub_027727();
		case -6:
		case 2:
			sub_02773B(x);
			return x;
		case -4:
		case 4:
			sub_027749(x);
			return x;
		case -2:
		case 6:
			sub_027766();
			return x;
		case 8:
			return sub_027773();
		case 10:
			sub_027782(x);
			return x;
		case 12:
			sub_027799(x);
			return x;
		case 14:
			sub_0277A6();
			return x;
		case 16:
			sub_0277B8(x);
			return x;
		case 18:
			break;
		case -94:
			return sub_02724D(u);
		case -92:
			return sub_0272CA(u);
		case -90:
			return sub_027369(x);
		case -88:
			return sub_0273DB(u);
		case -86:
			return sub_02748A(u);
		case -84:
			return sub_027523(u);
		case -82:
			sub_0273F4();
			return x;
		case -80:
			sub_027417(u);
			return x;
		case -78:
			sub_027448();
			return x;
		case -76:
			return sub_027494(x);
		case -74:
			return sub_0274C8(x);
		case -72:
			sub_027534();
			return x;
		case -70:
			sub_02753F();
			return x;
		case -68:
		case -64:
		case -60:
		case -56:
			sub_02755C();
			return x;
		case -66:
		case -62:
		case -58:
		case -54:
			sub_027573();
			return x;
		case -52:
			return sub_02759A(x);
		case -50:
			return sub_0275C7(x);
		case -48:
			return sub_0275E5(x);
		case -46:
			return sub_027619(x);
		case -44:
			return sub_027637(x);
		case -42:
			return sub_0275D0();
		case -40:
		case -34:
		case -30:
		case -26:
			sub_027655();
			return x;
		case -38:
			return sub_0275EE();
		case -36:
			sub_027608(x);
			return x;
		case -32:
			return sub_027622();
		case -28:
			return sub_027640();
		case -24:
			return sub_027680(x);
		case -22:
			return sub_027701(x);
		case -20:
			continue;
		case -18:
			return sub_027689();
		case -16:
			sub_0276A3(x);
			return x;
		case -14:
			sub_0276C6(x);
			return x;
		case -12:
			sub_0276E3(x);
			return x;
		case -10:
			sub_027700();
			return x;
		case -8:
			return sub_02770A();
		}
		break;
	}
	sub_0277CC(x);
	return x;
}

uint16_t sub_027727(void)
{
	uint16_t u = 0, x = 0;
	uint8_t t1 = 0;

	u = object_start_027F89_ADDRESS;
	x = sub_0277D6(u);
	mem_write8(x + 0x28u, 0x60u);
	mem_write8(x + 0x29u, 0x80u);
	t1 = mem_read8(x + 1u);
	mem_write8(x + 1u, t1 + 1u);
	return x;
}

void sub_02773B(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 5u, 0x90u);
		t2 = mem_read8(x + 1u);
		mem_write8(x + 1u, t2 + 1u);
	}
}

void sub_027749(uint16_t x)
{
	uint8_t a = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x29u);
	t2 = t1;
	a = t2 + 2u;
	mem_write8(x + 0x29u, a);
	if ((uint8_t)(t2 + 2u) < t2)
	{
		mem_write16(x + 0xFu, 0x200u);
		mem_write16(x + 0x14u, 0u);
		t3 = mem_read8(x + 1u);
		mem_write8(x + 1u, t3 + 1u);
		return;
	}
	d = ((uint32_t)a << 8) | 0x20u;
	sub_078617(x, d);
}

void sub_027766(void)
{
}

void sub_027767(void)
{
	uint16_t u = 0, x = 0;

	u = indexed_table_027F37_ADDRESS;
	x = unk_4F80_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)unk_4F81 << 1))
	{
	case 0:
		sub_027773();
		return;
	case 2:
		sub_027782(x);
		return;
	case 4:
		sub_027799(x);
		return;
	case 6:
		sub_0277A6();
		return;
	case 8:
		sub_0277B8(x);
		return;
	case 10:
		sub_0277CC(x);
		return;
	case -102:
		sub_02724D(u);
		return;
	case -100:
		sub_0272CA(u);
		return;
	case -98:
		sub_027369(x);
		return;
	case -96:
		sub_0273DB(u);
		return;
	case -94:
		sub_02748A(u);
		return;
	case -92:
		sub_027523(u);
		return;
	case -90:
		sub_0273F4();
		return;
	case -88:
		sub_027417(u);
		return;
	case -86:
		sub_027448();
		return;
	case -84:
		sub_027494(x);
		return;
	case -82:
		sub_0274C8(x);
		return;
	case -80:
		sub_027534();
		return;
	case -78:
		sub_02753F();
		return;
	case -76:
	case -72:
	case -68:
	case -64:
		sub_02755C();
		return;
	case -74:
	case -70:
	case -66:
	case -62:
		sub_027573();
		return;
	case -60:
		sub_02759A(x);
		return;
	case -58:
		sub_0275C7(x);
		return;
	case -56:
		sub_0275E5(x);
		return;
	case -54:
		sub_027619(x);
		return;
	case -52:
		sub_027637(x);
		return;
	case -50:
		sub_0275D0();
		return;
	case -48:
	case -42:
	case -38:
	case -34:
		sub_027655();
		return;
	case -46:
		sub_0275EE();
		return;
	case -44:
		sub_027608(x);
		return;
	case -40:
		sub_027622();
		return;
	case -36:
		sub_027640();
		return;
	case -32:
		sub_027680(x);
		return;
	case -30:
		sub_027701(x);
		return;
	case -28:
		sub_02771E(x);
		return;
	case -26:
		sub_027689();
		return;
	case -24:
		sub_0276A3(x);
		return;
	case -22:
		sub_0276C6(x);
		return;
	case -20:
		sub_0276E3(x);
		return;
	case -18:
		sub_027700();
		return;
	case -16:
		sub_02770A();
		return;
	case -14:
	case -6:
		sub_02773B(x);
		return;
	case -12:
	case -4:
		sub_027749(x);
		return;
	case -10:
	case -2:
		sub_027766();
		return;
	case -8:
		sub_027727();
		return;
	}
}

uint16_t sub_027773(void)
{
	uint16_t u = 0, x = 0;
	uint8_t t1 = 0;

	u = object_start_027F6B_ADDRESS;
	x = sub_0277D6(u);
	mem_write8(x + 0x28u, 0x20u);
	t1 = mem_read8(x + 1u);
	mem_write8(x + 1u, t1 + 1u);
	return x;
}

void sub_027782(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 6u);
	mem_write8(x + 6u, t1 | 0x40u);
	t2 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t2 - 1u);
	if (t2 != 1u)
		return;
	d = unk_5900_ADDRESS;
	carry = sub_078680(d);
	t3 = mem_read8(x + 1u);
	mem_write8(x + 1u, t3 + 1u);
}

void sub_027799(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) != 0u)
	{
		mem_write8(x, 0u);
		t2 = mem_read8(x + 1u);
		mem_write8(x + 1u, t2 + 1u);
	}
}

void sub_0277A6(void)
{
}

uint16_t sub_0277A7(void)
{
	uint16_t u = 0, x = 0;
	uint8_t t1 = 0;

	x = unk_4D40_ADDRESS;
	if (unk_4D40 == 0u)
		return x;
	u = loaded_table_027F3F_ADDRESS;
	t1 = mem_read8(x + 1u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_0277B8(x);
		return x;
	case 2:
		sub_0277CC(x);
		return x;
	case -110:
		return sub_02724D(u);
	case -108:
		return sub_0272CA(u);
	case -106:
		return sub_027369(x);
	case -104:
		return sub_0273DB(u);
	case -102:
		return sub_02748A(u);
	case -100:
		return sub_027523(u);
	case -98:
		sub_0273F4();
		return x;
	case -96:
		sub_027417(u);
		return x;
	case -94:
		sub_027448();
		return x;
	case -92:
		return sub_027494(x);
	case -90:
		return sub_0274C8(x);
	case -88:
		sub_027534();
		return x;
	case -86:
		sub_02753F();
		return x;
	case -84:
	case -80:
	case -76:
	case -72:
		sub_02755C();
		return x;
	case -82:
	case -78:
	case -74:
	case -70:
		sub_027573();
		return x;
	case -68:
		return sub_02759A(x);
	case -66:
		return sub_0275C7(x);
	case -64:
		return sub_0275E5(x);
	case -62:
		return sub_027619(x);
	case -60:
		return sub_027637(x);
	case -58:
		return sub_0275D0();
	case -56:
	case -50:
	case -46:
	case -42:
		sub_027655();
		return x;
	case -54:
		return sub_0275EE();
	case -52:
		sub_027608(x);
		return x;
	case -48:
		return sub_027622();
	case -44:
		return sub_027640();
	case -40:
		return sub_027680(x);
	case -38:
		return sub_027701(x);
	case -36:
		return sub_02771E(x);
	case -34:
		return sub_027689();
	case -32:
		sub_0276A3(x);
		return x;
	case -30:
		sub_0276C6(x);
		return x;
	case -28:
		sub_0276E3(x);
		return x;
	case -26:
		sub_027700();
		return x;
	case -24:
		return sub_02770A();
	case -22:
	case -14:
		sub_02773B(x);
		return x;
	case -20:
	case -12:
		sub_027749(x);
		return x;
	case -18:
	case -10:
		sub_027766();
		return x;
	case -16:
		return sub_027727();
	case -8:
		return sub_027773();
	case -6:
		sub_027782(x);
		return x;
	case -4:
		sub_027799(x);
		return x;
	case -2:
		sub_0277A6();
		return x;
	}
	unreachable();
}

void sub_0277B8(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0;
	uint8_t t1 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry == 0u)
		return;
	d = 0x6F00u;
	carry = sub_078680(d);
	mem_write8(x + 5u, 0x8Au);
	t1 = mem_read8(x + 1u);
	mem_write8(x + 1u, t1 + 1u);
}

void sub_0277CC(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) != 0u)
		mem_write8(x, 0u);
}

uint16_t sub_0277D6(uint16_t u)
{
	uint16_t x = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0;

	t1 = u;
	x = mem_read16(t1);
	io_write8(x + 6u, 0x80u);
	mem_write8(x, 0x80u);
	t2 = t1 + 2u;
	io_write8(x + 4u, mem_read8(t2));
	t3 = t2 + 1u;
	io_write8(x + 5u, mem_read8(t3) | 0x80u);
	t4 = t3 + 1u;
	t5 = mem_read16(t4);
	io_write16(x + 0xCu, t5);
	t6 = t4 + 2u;
	t7 = mem_read16(t6);
	io_write16(x + 0x11u, t7);
	t8 = mem_read16(t6 + 2u);
	io_write16(x + 0x16u, t8);
	return x;
}

uint16_t sub_027805(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t d = 0;
	uint16_t u = 0;
	uint8_t t5 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	io_write16(VIDEO_1852, x);
	d = 1u;
	sub_07867D(d, &u, &carry);
	if (carry)
	{
		mem_write8(u + 1u, 0xF4u);
		mem_write16(x + 0x28u, u);
		mem_write8(x, 0x80u);
		t1 = 0x2E0u - unk_48AC;
		mem_write16(x + 0xCu, t1);
		t2 = 0x2E8u - unk_48AC;
		mem_write16(u + 0xCu, t2);
		t3 = 0x108u + unk_48B2;
		mem_write16(x + 0x11u, t3);
		t4 = 0xC8u + unk_48B2;
		mem_write16(u + 0x11u, t4);
		mem_write16(x + 0x16u, 0xFFE0u);
		mem_write16(u + 0x16u, 0x20u);
		mem_write8(x + 4u, 0x13u);
		mem_write8(u + 4u, 0x13u);
		mem_write8(x + 5u, 0x85u);
		mem_write8(x + 9u, 0x60u);
		mem_write8(u + 9u, 0x60u);
		t5 = mem_read8(x + 2u);
		mem_write8(x + 2u, t5 + 1u);
	}
	return u;
}

uint16_t sub_027865(uint16_t x, uint16_t u)
{
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 0x2Au);
	if (t1 != 0u)
	{
		mem_write8(x + 5u, 0x86u);
		t2 = mem_read16(x + 0x28u);
		u = t2;
		mem_write8(u, 0x80u);
		mem_write8(u + 5u, 0x87u);
		t3 = mem_read8(x + 2u);
		mem_write8(x + 2u, t3 + 1u);
	}
	return u;
}

uint16_t sub_02787F(uint16_t x, uint16_t u)
{
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 0x2Au);
	if (t1 == 0u)
	{
		mem_write8(x + 5u, 0x85u);
		t2 = mem_read16(x + 0x28u);
		u = t2;
		mem_write8(u, 4u);
		t3 = mem_read8(x + 2u);
		mem_write8(x + 2u, t3 - 1u);
	}
	return u;
}

uint16_t sub_0278A8(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t d = 0;
	uint16_t u = 0;
	uint8_t t5 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	io_write16(VIDEO_1852, x);
	d = 2u;
	sub_07867D(d, &u, &carry);
	if (carry)
	{
		mem_write16(x + 0x28u, u);
		mem_write8(x, 0x80u);
		t1 = 0x330u - unk_48AC;
		mem_write16(x + 0xCu, t1);
		t2 = 0x328u - unk_48AC;
		mem_write16(u + 0xCu, t2);
		t3 = 0xD0u + unk_48B2;
		mem_write16(x + 0x11u, t3);
		t4 = 0x90u + unk_48B2;
		mem_write16(u + 0x11u, t4);
		mem_write16(x + 0x16u, 0xFFE0u);
		mem_write16(u + 0x16u, 0x20u);
		mem_write8(x + 4u, 0x13u);
		mem_write8(u + 4u, 0x13u);
		mem_write8(x + 5u, 0x85u);
		mem_write8(x + 9u, 0x20u);
		mem_write8(u + 9u, 0x20u);
		t5 = mem_read8(x + 2u);
		mem_write8(x + 2u, t5 + 1u);
	}
	return u;
}

uint16_t sub_027968(void)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t u = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0;

	t1 = AT16(unk_48C5, -1);
	t2 = t1;
	carry = (uint16_t)(t2 + 0x100u) < t2;
	AT16(unk_48C5, -1) = t2 + 0x100u;
	unk_48C5 = (unk_48C5 & 0xFFu) | ((((uint8_t)(unk_48C5 >> 8u) + carry) & 1u & 0xFFu) << 8u);
	a = unk_48AB;
	if ((a & 0x20u) != 0u)
	{
		if ((a & 7u) == 0u)
		{
			t3 = unk_48D5;
			t4 = t3 - 1u;
			unk_48D5 = t4;
		}
	}
	else if ((a & 7u) == 0u)
	{
		t5 = unk_48D5;
		t6 = t5 + 1u;
		unk_48D5 = t6;
	}
	a = unk_48AB;
	if (unk_485F != 0u)
		a = ~a;
	if ((a & 0x20u) != 0u)
	{
		if ((unk_48AB & 7u) == 0u)
		{
			t7 = unk_4889;
			t8 = t7 - 1u;
			unk_4889 = t8;
		}
	}
	else if ((unk_48AB & 7u) == 0u)
	{
		t9 = unk_4889;
		t10 = t9 + 1u;
		unk_4889 = t10;
	}
	unk_48AB++;
	t11 = unk_4886;
	io_write16(IO_1FA0, t11);
	t12 = unk_4889;
	io_write16(IO_1FA2, t12);
	u = sub_026237();
	return u;
}

uint16_t sub_0279E6(void)
{
	uint16_t u = 0;

	u = sub_026237();
	switch ((int8_t)(uint8_t)((uint32_t)unk_48AB << 1))
	{
	case 0:
		sub_026186();
		return u;
	case 2:
		sub_026198();
		return u;
	case 4:
		sub_0261CA();
		return u;
	case 6:
		return sub_0261CB(u);
	case 8:
	case 10:
	case 12:
		return sub_0261D4(u);
	}
	unreachable();
}
