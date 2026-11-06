/**
 *    Name:        unsorted/bank_1D.c
 *    Description: bank 1D's code
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    06-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

uint16_t sub_03A000(uint16_t x, uint16_t u)
{
	uint8_t b = 0, d_2 = 0;
	uint16_t d = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	y = x + 0x38u;
	d = sub_03A95C(y);
	b = (uint8_t)d;
	t1 = mem_read8(x + 0x2Du);
	if (t1 != 0u)
	{
		t2 = mem_read8(x + 0x1Bu);
		b = t2;
		if (b <= 0x48u)
		{
			t3 = mem_read8(x + 0x2Du);
			mem_write8(x + 0x2Du, t3 - 1u);
			mem_write8(x + 0x1Bu, 0x80u);
		}
	}
	t4 = mem_read8(x + 0x2Eu);
	y = bank_1d_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)t4 << 1))
	{
	case 0:
		sub_03A2AA(x);
		return y;
	case 2:
		return sub_03A2D4(x, y);
	case 4:
	case 12:
	case 16:
	case 46:
	case 48:
		return sub_03A2F2(x, y);
	case 6:
	case 8:
		return sub_03A329(x);
	case 10:
		return sub_03A317(x, y);
	case 14:
		return sub_03A346(x, y);
	case 18:
		return sub_03A370(x, u);
	case 20:
		sub_03A625();
		return y;
	case 22:
	case 24:
		return sub_03A422(x, u);
	case 26:
		return sub_03A46E(x, u);
	case 28:
		return sub_03A4DE(x, u);
	case 30:
		return sub_03A516(x);
	case 32:
		return sub_03A59E(x, u);
	case 34:
		return sub_03A5FC(x, u);
	case 36:
		return sub_03A610(x, u);
	case 38:
		return sub_03A61C(x, u);
	case 40:
		return sub_03A5C0(x, u);
	case 42:
	case 60:
		return sub_03A6F3(x, y, u);
	case 44:
		return sub_03A72D(x, y);
	case 50:
	case 52:
		return sub_03A73B(x, y);
	case 54:
		return sub_03A769(x, y);
	case 56:
		d_2 = b;
		sub_03A782(x, d_2);
		return y;
	case 58:
		return sub_03A5DF(x, u);
	}
	unreachable();
}

uint16_t sub_03A003(uint16_t x, uint16_t u)
{
	uint8_t t1 = 0;

	if (mem_read8(x) != 4u)
	{
		t1 = mem_read8(x + VIDEO_002F);
		mem_write8(x + VIDEO_002F, t1 - 1u);
		if (t1 == 1u)
			mem_write8(x, 0u);
		return u;
	}
	mem_write8(x + 9u, 0u);
	mem_write8(x, 0x80u);
	u = 0xB084u;
	if (unk_4867 == 4u)
	{
		u = 0xB082u;
		mem_write8(x + 9u, 0x80u);
	}
	mem_write16(x + 4u, u);
	mem_write8(x + VIDEO_002F, 0x60u);
	t1 = mem_read8(x + VIDEO_002F);
	mem_write8(x + VIDEO_002F, t1 - 1u);
	if (t1 == 1u)
		mem_write8(x, 0u);
	return u;
}

void sub_03A006(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t y = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x2Eu);
	y = loaded_table_03BAD6_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_03A7DC(x, &y, &u);
		break;
	case 2:
		sub_03A877(x, &y, &u);
		break;
	case 4:
		sub_03A910(x);
		break;
	case 6:
		sub_03A871(x, &y, &u);
		break;
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_03A009(uint16_t x, uint16_t y)
{
	uint32_t negative = 0;
	uint8_t a = 0, d = 0;
	uint16_t d_2 = 0, u = 0;
	uint8_t t7 = 0, t8 = 0, t9 = 0, t13 = 0, t14 = 0, t17 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t10 = 0, t11 = 0, t12 = 0, t15 = 0, t16 = 0;
	uint32_t unk_48F0_halfword = 0;

	t1 = mem_read16(x + 0x3Bu);
	t2 = t1 + 1u;
	mem_write16(x + 0x3Bu, t2);
	t3 = mem_read16(x + 0x3Eu);
	t4 = t3 + 1u;
	mem_write16(x + 0x3Eu, t4);
	t5 = mem_read16(x + 0x41u);
	t6 = t5 + 1u;
	mem_write16(x + 0x41u, t6);
	t7 = mem_read8(x + 2u);
	if (t7 != 0xF9u)
		sub_03B161(x);
	u = loaded_table_03BAEE_ADDRESS;
	t8 = mem_read8(x + 2u);
	switch ((int8_t)(uint8_t)((uint32_t)t8 << 1))
	{
	case 0:
		y = sub_03AD3B(x, y);
		break;
	case 2:
		y = sub_03AE41(x, y);
		break;
	case 4:
		y = sub_03AE74(x, y);
		break;
	case 6:
	case 8:
	case 10:
		y = sub_03AEB4(x, y);
		break;
	case 12:
	case 14:
	case 16:
		y = sub_03AEEA(x, y);
		break;
	case 18:
		y = sub_03AF47(x, y);
		break;
	case 20:
		y = sub_03AFD8(x, y);
		break;
	case 22:
		y = sub_03AFE8(x);
		break;
	case 24:
		y = sub_03B084(x, y);
		break;
	case 26:
		y = sub_03B12C(x, y);
		break;
	case 28:
		sub_03A9DC(x);
		break;
	case 30:
		y = sub_03AA0F(x, y);
		break;
	case 32:
		sub_03AA64(x);
		break;
	case 34:
		y = sub_03AA6A(x, y);
		break;
	case 36:
		sub_03AA92(x);
		break;
	case 38:
	case 42:
		sub_03AB20(x);
		break;
	case 40:
		y = sub_03AAAD(x, y);
		break;
	case 44:
		y = sub_03AB38(x, y);
		break;
	case 46:
	case 60:
		sub_03AC06(x);
		break;
	case 48:
	case 62:
		sub_03AC1B(x);
		break;
	case 50:
		y = sub_03ABA2(x, y);
		break;
	case 52:
	case 66:
		sub_03AC73(x);
		break;
	case 54:
	case 68:
		sub_03AC81(x);
		break;
	case 56:
	case 70:
		sub_03AC9F(x);
		break;
	case 58:
	case 72:
		y = sub_03ACBF(x, y);
		break;
	case 64:
		y = sub_03AC40(x, y);
		break;
	case 74:
		y = sub_03AD10(x, y, u);
		break;
	case 76:
		y = sub_03AD2F(x, y);
		break;
	case 78:
		sub_03AD44(x);
		break;
	case 80:
		sub_03AD6B(x);
		break;
	case 82:
		sub_03AD79(x);
		break;
	case 84:
		sub_03AD90(x);
		break;
	case 86:
		sub_03ADA9(x);
		break;
	case 88:
		y = sub_03ADD7(x, y);
		break;
	case 90:
		sub_03AE05(x);
		break;
	case 92:
		sub_03AE28(x);
		break;
	case 94:
	case 100:
		sub_03AEF3(x);
		break;
	case 96:
	case 116:
		sub_03AF1E(x);
		break;
	case 98:
	case 118:
		y = sub_03AF41(x, y);
		break;
	case 102:
		y = sub_03AF50(x, y);
		break;
	case 104:
		sub_03AFA0(x);
		break;
	case 106:
		y = sub_03AFCA(x, y);
		break;
	case -12:
		y = sub_03A9D3(x, y);
		break;
	case -10:
		y = sub_03AAA4(x, y);
		break;
	case -8:
		y = sub_03AB17(x, y);
		break;
	case -6:
		y = sub_03AB99(x, y);
		break;
	case -4:
		y = sub_03ABFD(x, y);
		break;
	case -2:
		y = sub_03AD07(x, y);
		break;
	}
	t9 = mem_read8(x + 2u);
	if (t9 == 0u)
		return y;
	t10 = mem_read16(x + 0xFu);
	d = (uint8_t)t10;
	a = (uint8_t)(t10 >> 8);
	if ((int16_t)t10 < 0)
	{
		t11 = (((uint32_t)a << 8) | (d & 0xFFu)) - 0x20u;
		d = (uint8_t)t11;
		a = (uint8_t)(t11 >> 8);
	}
	else
	{
		t12 = (((uint32_t)a << 8) | (d & 0xFFu)) + 0x20u;
		d = (uint8_t)t12;
		a = (uint8_t)(t12 >> 8);
	}
	unk_48F8 = ((uint32_t)a << 8) | (d & 0xFFu);
	unk_48F0_halfword = ((uint32_t)a << 8) | (d & 0xFFu);
	unk_48F0 = (uint8_t)(unk_48F0_halfword >> 8u);
	unk_48F1 = (uint8_t)unk_48F0_halfword;
	unk_48FA = 0u;
	d_2 = sub_078632(x);
	a = (uint8_t)(d_2 >> 8);
	if ((int8_t)a < 0)
	{
		t13 = mem_read8(x + VIDEO_0031);
		mem_write8(x + VIDEO_0031, 0x80u - t13);
		sub_03B4FE(x);
		return y;
	}
	sub_078647(x, &d_2, &negative);
	a = (uint8_t)(d_2 >> 8);
	if ((int8_t)a < 0)
	{
		t14 = mem_read8(x + VIDEO_0031);
		mem_write8(x + VIDEO_0031, 0u - t14);
		sub_03B4FE(x);
		return y;
	}
	t15 = (((uint32_t)unk_48F0 << 8u) | unk_48F1);
	unk_48F8 = t15;
	t16 = mem_read16(x + 0x14u);
	unk_48FA = t16;
	d_2 = sub_078632(x);
	a = (uint8_t)(d_2 >> 8);
	if ((int8_t)a >= 0)
		return y;
	t17 = mem_read8(x + VIDEO_0031);
	mem_write8(x + VIDEO_0031, t17 - 0x80u);
	sub_03B4FE(x);
	return y;
}

uint16_t sub_03A00F(uint16_t x, uint32_t y, uint8_t d)
{
	uint16_t ignored16 = 0, u = 0;
	uint8_t t1 = 0;

	u = loaded_table_03BD99_ADDRESS;
	t1 = mem_read8(x + 2u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_03B5A4(x);
		return u;
	case 2:
		sub_03B5B2(x, &ignored16, &u);
		return u;
	case 4:
		return sub_03B5EC(x);
	case 6:
		return sub_03B633(x);
	case 8:
		sub_03B654(x);
		return u;
	case 10:
		sub_03B66F(x);
		return u;
	case 12:
	case 14:
	case 16:
		sub_03B6A5(x);
		return u;
	case 18:
		sub_03B68E(x);
		return u;
	case 20:
		sub_03B6FE();
		return u;
	case 22:
		return sub_03B6FF(x);
	case 24:
		return sub_03B725(x, u);
	case 26:
	case 28:
	case 30:
	case 32:
		sub_03B74F(x);
		return u;
	case 34:
		sub_03B764(x);
		return u;
	case 36:
	case 44:
		sub_03B78C(x);
		return u;
	case 38:
	case 46:
		sub_03B79F(x);
		return u;
	case 40:
	case 48:
		sub_03B7B2(x);
		return u;
	case 42:
		sub_03B761(x);
		return u;
	case 50:
		return sub_03B7D2(x);
	case 52:
		sub_03B7F4(x, d);
		return u;
	case 54:
		sub_03B82F(x);
		return u;
	case 56:
		sub_03B848(x, &ignored16, &u);
		return u;
	case 58:
		return sub_03B87C(x);
	case 60:
		sub_03B8A3(x);
		return u;
	case 62:
		sub_03B8AD(x);
		return u;
	case 64:
		sub_03B8BC(x);
		return u;
	case 66:
		return sub_03B923(x);
	case 68:
		return sub_03B937(x, u);
	case 70:
		sub_03B97C(x, d);
		return u;
	case 72:
		return sub_03B99C(x, u);
	case 74:
		sub_03B9AD(x);
		return u;
	case 76:
		sub_03B9E2();
		return u;
	case -4:
		return sub_07CE88(x, u);
	}
	unreachable();
}

void sub_03A012(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t t1 = 0;

	mem_write8(x, mem_read8(x) | 0x10u);
	u = loaded_table_03BDA1_ADDRESS;
	t1 = mem_read8(x + 2u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_03B654(x);
		break;
	case 2:
		sub_03B66F(x);
		break;
	case 4:
	case 6:
	case 8:
		sub_03B6A5(x);
		break;
	case 10:
		sub_03B68E(x);
		break;
	case 12:
		sub_03B6FE();
		break;
	case 14:
		u = sub_03B6FF(x);
		break;
	case 16:
		u = sub_03B725(x, u);
		break;
	case 18:
	case 20:
	case 22:
	case 24:
		sub_03B74F(x);
		break;
	case 26:
		sub_03B764(x);
		break;
	case 28:
	case 36:
		sub_03B78C(x);
		break;
	case 30:
	case 38:
		sub_03B79F(x);
		break;
	case 32:
	case 40:
		sub_03B7B2(x);
		break;
	case 34:
		sub_03B761(x);
		break;
	case 42:
		u = sub_03B7D2(x);
		break;
	case 44:
		sub_03B7F4(x, d);
		break;
	case 46:
		sub_03B82F(x);
		break;
	case 48:
		sub_03B848(x, &y, &u);
		break;
	case 50:
		u = sub_03B87C(x);
		break;
	case 52:
		sub_03B8A3(x);
		break;
	case 54:
		sub_03B8AD(x);
		break;
	case 56:
		sub_03B8BC(x);
		break;
	case 58:
		u = sub_03B923(x);
		break;
	case 60:
		u = sub_03B937(x, u);
		break;
	case 62:
		sub_03B97C(x, d);
		break;
	case 64:
		u = sub_03B99C(x, u);
		break;
	case 66:
		sub_03B9AD(x);
		break;
	case 68:
		sub_03B9E2();
		break;
	case -12:
		u = sub_07CE88(x, u);
		break;
	case -8:
		sub_03B5A4(x);
		break;
	case -6:
		sub_03B5B2(x, &y, &u);
		break;
	case -4:
		u = sub_03B5EC(x);
		break;
	case -2:
		u = sub_03B633(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_03A015(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t t1 = 0;

	u = loaded_table_03BDA5_ADDRESS;
	t1 = mem_read8(x + 2u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
	case 2:
	case 4:
		sub_03B6A5(x);
		break;
	case 6:
		sub_03B68E(x);
		break;
	case 8:
		sub_03B6FE();
		break;
	case 10:
		u = sub_03B6FF(x);
		break;
	case 12:
		u = sub_03B725(x, u);
		break;
	case 14:
	case 16:
	case 18:
	case 20:
		sub_03B74F(x);
		break;
	case 22:
		sub_03B764(x);
		break;
	case 24:
	case 32:
		sub_03B78C(x);
		break;
	case 26:
	case 34:
		sub_03B79F(x);
		break;
	case 28:
	case 36:
		sub_03B7B2(x);
		break;
	case 30:
		sub_03B761(x);
		break;
	case 38:
		u = sub_03B7D2(x);
		break;
	case 40:
		sub_03B7F4(x, d);
		break;
	case 42:
		sub_03B82F(x);
		break;
	case 44:
		sub_03B848(x, &y, &u);
		break;
	case 46:
		u = sub_03B87C(x);
		break;
	case 48:
		sub_03B8A3(x);
		break;
	case 50:
		sub_03B8AD(x);
		break;
	case 52:
		sub_03B8BC(x);
		break;
	case 54:
		u = sub_03B923(x);
		break;
	case 56:
		u = sub_03B937(x, u);
		break;
	case 58:
		sub_03B97C(x, d);
		break;
	case 60:
		u = sub_03B99C(x, u);
		break;
	case 62:
		sub_03B9AD(x);
		break;
	case 64:
		sub_03B9E2();
		break;
	case -16:
		u = sub_07CE88(x, u);
		break;
	case -12:
		sub_03B5A4(x);
		break;
	case -10:
		sub_03B5B2(x, &y, &u);
		break;
	case -8:
		u = sub_03B5EC(x);
		break;
	case -6:
		u = sub_03B633(x);
		break;
	case -4:
		sub_03B654(x);
		break;
	case -2:
		sub_03B66F(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_03A018(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t t1 = 0;

	u = loaded_table_03BDA5_ADDRESS;
	t1 = mem_read8(x + 2u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
	case 2:
	case 4:
		sub_03B6A5(x);
		break;
	case 6:
		sub_03B68E(x);
		break;
	case 8:
		sub_03B6FE();
		break;
	case 10:
		u = sub_03B6FF(x);
		break;
	case 12:
		u = sub_03B725(x, u);
		break;
	case 14:
	case 16:
	case 18:
	case 20:
		sub_03B74F(x);
		break;
	case 22:
		sub_03B764(x);
		break;
	case 24:
	case 32:
		sub_03B78C(x);
		break;
	case 26:
	case 34:
		sub_03B79F(x);
		break;
	case 28:
	case 36:
		sub_03B7B2(x);
		break;
	case 30:
		sub_03B761(x);
		break;
	case 38:
		u = sub_03B7D2(x);
		break;
	case 40:
		sub_03B7F4(x, d);
		break;
	case 42:
		sub_03B82F(x);
		break;
	case 44:
		sub_03B848(x, &y, &u);
		break;
	case 46:
		u = sub_03B87C(x);
		break;
	case 48:
		sub_03B8A3(x);
		break;
	case 50:
		sub_03B8AD(x);
		break;
	case 52:
		sub_03B8BC(x);
		break;
	case 54:
		u = sub_03B923(x);
		break;
	case 56:
		u = sub_03B937(x, u);
		break;
	case 58:
		sub_03B97C(x, d);
		break;
	case 60:
		u = sub_03B99C(x, u);
		break;
	case 62:
		sub_03B9AD(x);
		break;
	case 64:
		sub_03B9E2();
		break;
	case -16:
		u = sub_07CE88(x, u);
		break;
	case -12:
		sub_03B5A4(x);
		break;
	case -10:
		sub_03B5B2(x, &y, &u);
		break;
	case -8:
		u = sub_03B5EC(x);
		break;
	case -6:
		u = sub_03B633(x);
		break;
	case -4:
		sub_03B654(x);
		break;
	case -2:
		sub_03B66F(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_03A01B(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t t1 = 0;

	u = loaded_table_03BDAD_ADDRESS;
	t1 = mem_read8(x + 2u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_03B6FE();
		break;
	case 2:
		u = sub_03B6FF(x);
		break;
	case 4:
		u = sub_03B725(x, u);
		break;
	case 6:
	case 8:
	case 10:
	case 12:
		sub_03B74F(x);
		break;
	case 14:
		sub_03B764(x);
		break;
	case 16:
	case 24:
		sub_03B78C(x);
		break;
	case 18:
	case 26:
		sub_03B79F(x);
		break;
	case 20:
	case 28:
		sub_03B7B2(x);
		break;
	case 22:
		sub_03B761(x);
		break;
	case 30:
		u = sub_03B7D2(x);
		break;
	case 32:
		sub_03B7F4(x, d);
		break;
	case 34:
		sub_03B82F(x);
		break;
	case 36:
		sub_03B848(x, &y, &u);
		break;
	case 38:
		u = sub_03B87C(x);
		break;
	case 40:
		sub_03B8A3(x);
		break;
	case 42:
		sub_03B8AD(x);
		break;
	case 44:
		sub_03B8BC(x);
		break;
	case 46:
		u = sub_03B923(x);
		break;
	case 48:
		u = sub_03B937(x, u);
		break;
	case 50:
		sub_03B97C(x, d);
		break;
	case 52:
		u = sub_03B99C(x, u);
		break;
	case 54:
		sub_03B9AD(x);
		break;
	case 56:
		sub_03B9E2();
		break;
	case -24:
		u = sub_07CE88(x, u);
		break;
	case -20:
		sub_03B5A4(x);
		break;
	case -18:
		sub_03B5B2(x, &y, &u);
		break;
	case -16:
		u = sub_03B5EC(x);
		break;
	case -14:
		u = sub_03B633(x);
		break;
	case -12:
		sub_03B654(x);
		break;
	case -10:
		sub_03B66F(x);
		break;
	case -8:
	case -6:
	case -4:
		sub_03B6A5(x);
		break;
	case -2:
		sub_03B68E(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_03A01E(uint16_t x, uint32_t y)
{
	uint32_t negative = 0;
	uint8_t a = 0;
	uint16_t d = 0, ignored16 = 0, u = 0;
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0;

	sub_078644(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	if ((int8_t)a < 0)
	{
		t1 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t1);
	}
	sub_078647(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	if ((int8_t)a < 0)
	{
		t2 = mem_read16(x + 0x14u);
		mem_write16(x + 0x14u, 0u - t2);
	}
	u = loaded_table_03BDCF_ADDRESS;
	t3 = mem_read8(x + 2u);
	switch ((int8_t)(uint8_t)((uint32_t)t3 << 1))
	{
	case 0:
		sub_03B82F(x);
		return u;
	case 2:
		sub_03B848(x, &ignored16, &u);
		return u;
	case 4:
		return sub_03B87C(x);
	case 6:
		sub_03B8A3(x);
		return u;
	case 8:
		sub_03B8AD(x);
		return u;
	case 10:
		sub_03B8BC(x);
		return u;
	case 12:
		return sub_03B923(x);
	case 14:
		return sub_03B937(x, u);
	case 16:
		sub_03B97C(x, (uint8_t)d);
		return u;
	case 18:
		return sub_03B99C(x, u);
	case 20:
		sub_03B9AD(x);
		return u;
	case 22:
		sub_03B9E2();
		return u;
	case -58:
		return sub_07CE88(x, u);
	case -54:
		sub_03B5A4(x);
		return u;
	case -52:
		sub_03B5B2(x, &ignored16, &u);
		return u;
	case -50:
		return sub_03B5EC(x);
	case -48:
		return sub_03B633(x);
	case -46:
		sub_03B654(x);
		return u;
	case -44:
		sub_03B66F(x);
		return u;
	case -42:
	case -40:
	case -38:
		sub_03B6A5(x);
		return u;
	case -36:
		sub_03B68E(x);
		return u;
	case -34:
		sub_03B6FE();
		return u;
	case -32:
		return sub_03B6FF(x);
	case -30:
		return sub_03B725(x, u);
	case -28:
	case -26:
	case -24:
	case -22:
		sub_03B74F(x);
		return u;
	case -20:
		sub_03B764(x);
		return u;
	case -18:
	case -10:
		sub_03B78C(x);
		return u;
	case -16:
	case -8:
		sub_03B79F(x);
		return u;
	case -14:
	case -6:
		sub_03B7B2(x);
		return u;
	case -12:
		sub_03B761(x);
		return u;
	case -4:
		return sub_03B7D2(x);
	case -2:
		sub_03B7F4(x, d);
		return u;
	}
	unreachable();
}

uint16_t sub_03A021(uint16_t x, uint32_t y, uint8_t d)
{
	uint32_t negative = 0;
	uint8_t a = 0;
	uint16_t d_2 = 0, ignored16 = 0, u = 0;
	uint8_t t1 = 0;

	u = loaded_table_03BDD7_ADDRESS;
	t1 = mem_read8(x + 2u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_03B8AD(x);
		break;
	case 2:
		sub_03B8BC(x);
		break;
	case 4:
		u = sub_03B923(x);
		break;
	case 6:
		u = sub_03B937(x, u);
		break;
	case 8:
		sub_03B97C(x, d);
		break;
	case 10:
		u = sub_03B99C(x, u);
		break;
	case 12:
		sub_03B9AD(x);
		break;
	case 14:
		sub_03B9E2();
		break;
	case -66:
		u = sub_07CE88(x, u);
		break;
	case -62:
		sub_03B5A4(x);
		break;
	case -60:
		sub_03B5B2(x, &ignored16, &u);
		break;
	case -58:
		u = sub_03B5EC(x);
		break;
	case -56:
		u = sub_03B633(x);
		break;
	case -54:
		sub_03B654(x);
		break;
	case -52:
		sub_03B66F(x);
		break;
	case -50:
	case -48:
	case -46:
		sub_03B6A5(x);
		break;
	case -44:
		sub_03B68E(x);
		break;
	case -42:
		sub_03B6FE();
		break;
	case -40:
		u = sub_03B6FF(x);
		break;
	case -38:
		u = sub_03B725(x, u);
		break;
	case -36:
	case -34:
	case -32:
	case -30:
		sub_03B74F(x);
		break;
	case -28:
		sub_03B764(x);
		break;
	case -26:
	case -18:
		sub_03B78C(x);
		break;
	case -24:
	case -16:
		sub_03B79F(x);
		break;
	case -22:
	case -14:
		sub_03B7B2(x);
		break;
	case -20:
		sub_03B761(x);
		break;
	case -12:
		u = sub_03B7D2(x);
		break;
	case -10:
		sub_03B7F4(x, d);
		break;
	case -8:
		sub_03B82F(x);
		break;
	case -6:
		sub_03B848(x, &ignored16, &u);
		break;
	case -4:
		u = sub_03B87C(x);
		break;
	case -2:
		sub_03B8A3(x);
		break;
	}
	sub_07863B(x, &d_2, &negative);
	a = (uint8_t)(d_2 >> 8);
	if ((int8_t)a < 0)
	{
		sub_03B8C3(x);
		return u;
	}
	return u;
}

void sub_03A024(uint16_t x)
{
	uint8_t a = 0;
	uint16_t u = 0;
	uint8_t t2 = 0, t3 = 0, t9 = 0;
	uint16_t t1 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0;
	uint32_t unk_48F0_halfword = 0;

	t1 = mem_read16(x + 0x29u);
	u = t1;
	t2 = mem_read8(u + 0x43u);
	if (t2 == 0u)
	{
		mem_write8(x, 0u);
		return;
	}
	unk_48F0 = 0u;
	unk_48F1 = 0x30u;
	t3 = mem_read8(u + 9u);
	a = t3 & 0x40u;
	mem_write8(x + 9u, a);
	if (a != 0u)
	{
		unk_48F0_halfword = 0u - (((uint32_t)unk_48F0 << 8u) | unk_48F1);
		unk_48F0 = (uint8_t)(unk_48F0_halfword >> 8u);
		unk_48F1 = (uint8_t)unk_48F0_halfword;
	}
	t4 = mem_read16(u + 0xCu);
	t5 = t4 + (((uint32_t)unk_48F0 << 8u) | unk_48F1);
	mem_write16(x + 0xCu, t5);
	t6 = mem_read16(u + 0x11u);
	mem_write16(x + 0x11u, t6);
	t7 = mem_read16(u + 0xFu);
	mem_write16(x + 0xFu, t7);
	t8 = mem_read16(u + 0x14u);
	mem_write16(x + 0x14u, t8);
	t9 = mem_read8(x + 6u);
	mem_write8(x + 6u, t9 | 0x80u);
}

void sub_03A027(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t t1 = 0;

	u = loaded_table_03BDDB_ADDRESS;
	t1 = mem_read8(x + 2u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		u = sub_03B923(x);
		break;
	case 2:
		u = sub_03B937(x, u);
		break;
	case 4:
		sub_03B97C(x, d);
		break;
	case 6:
		u = sub_03B99C(x, u);
		break;
	case 8:
		sub_03B9AD(x);
		break;
	case 10:
		sub_03B9E2();
		break;
	case -70:
		u = sub_07CE88(x, u);
		break;
	case -66:
		sub_03B5A4(x);
		break;
	case -64:
		sub_03B5B2(x, &y, &u);
		break;
	case -62:
		u = sub_03B5EC(x);
		break;
	case -60:
		u = sub_03B633(x);
		break;
	case -58:
		sub_03B654(x);
		break;
	case -56:
		sub_03B66F(x);
		break;
	case -54:
	case -52:
	case -50:
		sub_03B6A5(x);
		break;
	case -48:
		sub_03B68E(x);
		break;
	case -46:
		sub_03B6FE();
		break;
	case -44:
		u = sub_03B6FF(x);
		break;
	case -42:
		u = sub_03B725(x, u);
		break;
	case -40:
	case -38:
	case -36:
	case -34:
		sub_03B74F(x);
		break;
	case -32:
		sub_03B764(x);
		break;
	case -30:
	case -22:
		sub_03B78C(x);
		break;
	case -28:
	case -20:
		sub_03B79F(x);
		break;
	case -26:
	case -18:
		sub_03B7B2(x);
		break;
	case -24:
		sub_03B761(x);
		break;
	case -16:
		u = sub_03B7D2(x);
		break;
	case -14:
		sub_03B7F4(x, d);
		break;
	case -12:
		sub_03B82F(x);
		break;
	case -10:
		sub_03B848(x, &y, &u);
		break;
	case -8:
		u = sub_03B87C(x);
		break;
	case -6:
		sub_03B8A3(x);
		break;
	case -4:
		sub_03B8AD(x);
		break;
	case -2:
		sub_03B8BC(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

uint32_t sub_03A02D(void)
{
	uint32_t carry = 0;
	uint8_t b = 0;

	b = unk_4850;
	carry = (b >> 0) & 1u;
	b = b >> 1;
	if (carry == 0u || (int8_t)unk_4A42 >= 0)
	{
		carry = (b >> 0) & 1u;
		b = b >> 1;
		if (carry == 0u || (int8_t)unk_4B02 >= 0)
		{
			carry = (b >> 0) & 1u;
			b = b >> 1;
			if (carry == 0u || (int8_t)unk_4BC2 >= 0)
			{
				carry = (b >> 0) & 1u;
				if (carry == 0u || (int8_t)unk_4C82 >= 0)
				{
					carry = 0u;
					return carry;
				}
			}
		}
	}
	carry = 1u;
	return carry;
}

void sub_03A058(uint16_t x, uint16_t y, uint16_t d)
{
	mem_write8(x + 5u, d >> 8);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write16(x + 0x2Eu, y);
}

void sub_03A072(uint16_t x)
{
	mem_write8(x, mem_read8(x) | 8u);
}

void sub_03A07B(uint16_t x)
{
	mem_write8(x, mem_read8(x) & ~8u);
}

void sub_03A084(uint16_t x, uint16_t *p_y, uint32_t *p_carry)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = *p_carry;
	uint32_t negative = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0;

	sub_07863B(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	if ((int8_t)a >= 0)
	{
		unk_48F0 = a & 0x30u;
		t1 = mem_read8(x + 9u);
		mem_write8(x + 9u, (t1 & 0xCFu) | unk_48F0);
		t2 = (uint8_t)((((a & 0xFu) << 1) << 1) << 1);
		a = (uint8_t)(t2 >> 8);
		b = (uint8_t)t2;
		t3 = mem_read16(x + 0x16u);
		if ((int16_t)t3 < (int16_t)(((uint32_t)a << 8) | b))
		{
			mem_write16(x + 0x14u, 0u);
			mem_write16(x + 0xFu, 0u);
			t4 = mem_read16(x + 0x5Cu);
			a = (uint8_t)(t4 >> 8);
			b = (uint8_t)t4;
		}
		else
			mem_write16(x + 0x5Cu, ((uint32_t)a << 8) | b);
	}
	else
	{
		sub_078644(x, &d, &negative);
		a = (uint8_t)(d >> 8);
		if (negative == 0u)
		{
			mem_write16(x + 0x14u, 0u);
			unk_48F0 = a & 0x30u;
			t1 = mem_read8(x + 9u);
			mem_write8(x + 9u, (t1 & 0xCFu) | unk_48F0);
			t2 = (uint8_t)((((a & 0xFu) << 1) << 1) << 1);
			a = (uint8_t)(t2 >> 8);
			b = (uint8_t)t2;
			t3 = mem_read16(x + 0x16u);
			if ((int16_t)t3 < (int16_t)(((uint32_t)a << 8) | b))
			{
				mem_write16(x + 0x14u, 0u);
				mem_write16(x + 0xFu, 0u);
				t4 = mem_read16(x + 0x5Cu);
				a = (uint8_t)(t4 >> 8);
				b = (uint8_t)t4;
			}
			else
				mem_write16(x + 0x5Cu, ((uint32_t)a << 8) | b);
		}
		else
		{
			mem_write16(x + 0xFu, 0u);
			sub_078647(x, &d, &negative);
			a = (uint8_t)(d >> 8);
			if (negative == 0u)
			{
				unk_48F0 = a & 0x30u;
				t1 = mem_read8(x + 9u);
				mem_write8(x + 9u, (t1 & 0xCFu) | unk_48F0);
				t2 = (uint8_t)((((a & 0xFu) << 1) << 1) << 1);
				a = (uint8_t)(t2 >> 8);
				b = (uint8_t)t2;
				t3 = mem_read16(x + 0x16u);
				if ((int16_t)t3 < (int16_t)(((uint32_t)a << 8) | b))
				{
					mem_write16(x + 0x14u, 0u);
					mem_write16(x + 0xFu, 0u);
					t4 = mem_read16(x + 0x5Cu);
					a = (uint8_t)(t4 >> 8);
					b = (uint8_t)t4;
				}
				else
					mem_write16(x + 0x5Cu, ((uint32_t)a << 8) | b);
			}
			else if (negative)
			{
				mem_write16(x + 0x14u, 0u);
				mem_write16(x + 0xFu, 0u);
				t4 = mem_read16(x + 0x5Cu);
				a = (uint8_t)(t4 >> 8);
				b = (uint8_t)t4;
			}
			else
			{
				mem_write16(x + 0x14u, 0u);
				unk_48F0 = a & 0x30u;
				t1 = mem_read8(x + 9u);
				mem_write8(x + 9u, (t1 & 0xCFu) | unk_48F0);
				t2 = (uint8_t)((((a & 0xFu) << 1) << 1) << 1);
				a = (uint8_t)(t2 >> 8);
				b = (uint8_t)t2;
				t3 = mem_read16(x + 0x16u);
				if ((int16_t)t3 < (int16_t)(((uint32_t)a << 8) | b))
				{
					mem_write16(x + 0x14u, 0u);
					mem_write16(x + 0xFu, 0u);
					t4 = mem_read16(x + 0x5Cu);
					a = (uint8_t)(t4 >> 8);
					b = (uint8_t)t4;
				}
				else
					mem_write16(x + 0x5Cu, ((uint32_t)a << 8) | b);
			}
		}
	}
	t5 = mem_read16(x + 0x16u);
	if ((int16_t)t5 <= (int16_t)(((uint32_t)a << 8) | b))
	{
		mem_write16(x + 0x16u, ((uint32_t)a << 8) | b);
		t6 = mem_read16(x + 0x19u);
		y = t6;
		if (t6 != 0u)
		{
			mem_write16(x + 0x19u, 0u);
			sub_03A07B(x);
		}
		carry = 1u;
	}
	else
	{
		t7 = mem_read16(x + 0x19u);
		t8 = t7 - 0x60u;
		mem_write16(x + 0x19u, t8);
		carry = 0u;
	}
	*p_y = y;
	*p_carry = carry;
}

void sub_03A0E7(uint16_t *p_u, uint16_t *p_d)
{
	uint32_t zero = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, u = 0;
	uint8_t stack = 0, stack_10002 = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = (unk_4858 & 3u) * 0xC0u;
	t2 = t1 + unk_4A40_ADDRESS;
	a = (uint8_t)(t2 >> 8);
	b = (uint8_t)t2;
	stack = a;
	stack_10002 = b;
	u = ((uint32_t)stack << 8) | stack_10002;
	sub_03A109(&u, &zero);
	if (zero)
	{
		sub_03A109(&u, &zero);
		if (zero)
		{
			sub_03A109(&u, &zero);
			if (zero)
				sub_03A109(&u, &zero);
		}
	}
	d = ((uint32_t)a << 8) | b;
	*p_u = u;
	*p_d = d;
}

void sub_03A109(uint16_t *p_u, uint32_t *p_zero)
{
	uint16_t u = (uint16_t)*p_u;
	uint32_t zero = *p_zero;

	u += 0xC0u;
	if (u == unk_4D40_ADDRESS)
		u = unk_4A40_ADDRESS;
	zero = mem_read8(u) == 0u;
	*p_u = u;
	*p_zero = zero;
}

uint16_t sub_03A119(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x25u);
	u = t1;
	t2 = mem_read8(u + 0x5Bu);
	mem_write8(x + 0x27u, t2 & ~0xFu);
	return u;
}

void sub_03A125(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x27u);
	mem_write8(x + 0x27u, t1 | 0x81u);
}

void sub_03A12E(uint16_t x, uint16_t *p_u, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d = 0, u = 0;

	u = unk_4A40_ADDRESS;
	d = unk_4850;
	sub_03A150(x, u, &d, &carry);
	if (carry == 0u)
	{
		u = unk_4B00_ADDRESS;
		sub_03A150(x, u, &d, &carry);
		if (carry == 0u)
		{
			u = unk_4BC0_ADDRESS;
			sub_03A150(x, u, &d, &carry);
			if (carry == 0u)
			{
				u = unk_4C80_ADDRESS;
				sub_03A150(x, u, &d, &carry);
			}
		}
	}
	*p_u = u;
	*p_carry = carry;
}

void sub_03A150(uint16_t x, uint16_t u, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint16_t d_2 = 0;
	uint8_t stack = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;

	carry = ((uint8_t)d >> 0) & 1u;
	d = (uint8_t)d >> 1;
	if (carry == 0u)
	{
		carry = 0u;
		d &= 0xFFu;
	}
	else
	{
		stack = (uint8_t)d;
		t1 = mem_read16(x + 0xCu);
		t2 = mem_read16(u + 0xCu);
		d_2 = t1 - t2;
		t3 = d_2 >> 15 ? 0u - d_2 : d_2;
		d = stack;
		if ((int16_t)unk_48F8 <= (int16_t)t3)
		{
			carry = 0u;
			d &= 0xFFu;
		}
		else
		{
			stack = (uint8_t)d;
			t4 = mem_read16(x + 0x11u);
			t5 = mem_read16(u + 0x11u);
			d_2 = t4 - t5;
			d_2 = (uint16_t)(d_2 >> 15 ? 0u - d_2 : d_2);
			t6 = d_2;
			d = (d_2 & ~0xFFu) | stack;
			if ((int16_t)unk_48FA <= (int16_t)t6)
			{
				carry = 0u;
				d &= 0xFFu;
			}
			else
			{
				carry = 1u;
				d = (d & 0xFFu) | ((uint32_t)(uint8_t)~(d >> 8) << 8);
			}
		}
	}
	*p_d = d;
	*p_carry = carry;
}

uint32_t sub_03A177(uint16_t x)
{
	uint32_t zero = 0;
	uint8_t a = 0;

	a = mem_read8(x) | 4u;
	zero = a == 0u;
	mem_write8(x, a);
	return zero;
}

void sub_03A180(uint16_t x)
{
	mem_write8(x, mem_read8(x) & ~4u);
}

void sub_03A189(uint16_t x, uint16_t y, uint16_t *p_u, uint32_t *p_zero, uint32_t *p_negative)
{
	uint16_t u = (uint16_t)*p_u;
	uint32_t zero = *p_zero;
	uint32_t negative = *p_negative;
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t3 = 0, t4 = 0;
	uint16_t t2 = 0;

	if ((mem_read8(x) & 0x20u) == 0u)
	{
		negative = 0u;
		zero = 1u;
	}
	else
	{
		t1 = mem_read8(x + 0x1Eu);
		a = t1;
		if ((int8_t)a < 0x11)
		{
			negative = 0u;
			zero = 1u;
		}
		else
		{
			mem_write16(x + 0x1Cu, 0u);
			t2 = mem_read16(x + 0x25u);
			u = t2;
			if ((int16_t)u >= 0x4A40 && u < unk_4D40_ADDRESS)
			{
				mem_write8(u + 0x2Au, a);
				mem_write16(u + 0x49u, x);
			}
			mem_write8(x, 0x80u);
			t3 = mem_read8(x + 0x1Bu);
			a = t3;
			b = unk_4857;
			if (a <= mem_read8(y + (int8_t)b))
			{
				t4 = mem_read8(x + 0x1Bu);
				a = t4;
			}
			if (a <= mem_read8(y + (int8_t)b))
			{
				mem_write8(x + 0x1Bu, 0u);
				u = sub_03A119(x);
				d = 0x6600u;
				carry = sub_078680(d);
				negative = 1u;
				zero = 0xFFu == 0u;
			}
			else
			{
				d = 0x6600u;
				carry = sub_078680(d);
				negative = 0u;
				zero = 1u == 0u;
			}
		}
	}
	*p_u = u;
	*p_zero = zero;
	*p_negative = negative;
}

uint32_t sub_03A1DE(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	mem_write8(x, (mem_read8(x) ^ 0x80u) | 4u);
	t1 = mem_read8(x + VIDEO_002F);
	mem_write8(x + VIDEO_002F, t1 - 1u);
	if (t1 != 1u)
	{
		carry = 0u;
		return carry;
	}
	mem_write8(x, 0u);
	sub_03A125(x);
	carry = 1u;
	return carry;
}

uint32_t sub_03A1F7(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) != 0u)
		sub_03A180(x);
	else
		y = 0u;
	mem_write16(x + 0x1Cu, y);
	t2 = mem_read8(x + 6u);
	carry = (t2 >> 0) & 1u;
	return carry;
}

uint16_t sub_03A20E(uint16_t x, uint16_t y)
{
	uint16_t d = 0, y_2 = 0;
	uint16_t t1 = 0;

	t1 = y;
	y_2 = t1 + 2u;
	mem_write16(x + 0x1Fu, mem_read16(t1));
	d = mem_read16(y_2);
	mem_write16(x + 0x21u, d);
	mem_write8(x + 0x24u, d >> 8);
	return y_2;
}

void sub_03A21C(uint16_t x)
{
	uint8_t a = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0;
	uint16_t t1 = 0;

	a = 0u;
	t1 = mem_read16(x + 0xFu);
	if ((int16_t)t1 < 0)
		a = 0x40u;
	t2 = mem_read8(x + 9u);
	if (((a ^ t2) & 0x40u) != 0u)
	{
		t3 = mem_read8(x + 9u);
		mem_write8(x + 9u, t3 ^ 0x40u);
		t4 = mem_read8(x + 5u);
		mem_write8(x + 5u, t4 | 0x80u);
	}
}

uint16_t sub_03A23C(uint16_t x)
{
	uint8_t a = 0;
	uint16_t u = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0, t3 = 0;

	u = sub_078620(x);
	t1 = mem_read8(x + 9u);
	a = t1 & 0xBFu;
	t2 = mem_read16(x + 0xCu);
	t3 = mem_read16(u + 0xCu);
	if ((int16_t)t3 < (int16_t)t2)
		a |= 0x40u;
	mem_write8(x + 9u, a);
	return u;
}

void unused_03A252(uint16_t x, uint16_t y, uint16_t d)
{
	uint16_t d_2 = 0;

	d_2 = (d & ~0xFFu) | mem_read8(y + (unk_4861 >> 1));
	sub_078617(x, d_2);
}

uint32_t sub_03A25B(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = mem_read16(x + 0xFu);
	if (t1 == 0u)
	{
		t2 = mem_read16(x + 0x14u);
		if (t2 == 0u)
		{
			carry = 1u;
			return carry;
		}
	}
	carry = 0u;
	return carry;
}

void unused_03A269(uint16_t x, uint16_t y, uint8_t d)
{
	uint16_t d_2 = 0;

	d_2 = (d & 0xFFu) | ((uint32_t)mem_read8(y + (int8_t)unk_4857) << 8);
	sub_0786BF(x, y, d_2);
}

uint16_t sub_03A294(uint16_t x, uint8_t d)
{
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	return sub_03A29A(x, d);
}

uint16_t sub_03A29A(uint16_t x, uint8_t d)
{
	uint8_t b = 0;
	uint16_t y = 0;
	uint16_t t1 = 0;

	b = (uint8_t)d;
	y = indexed_table_03BA3A_ADDRESS;
	mem_write8(x + 0x2Eu, b);
	t1 = DATA16(y + (int8_t)((uint32_t)b << 1));
	b = (uint8_t)t1;
	mem_write8(x + VIDEO_002F, ((t1 & ~0xFFu) | b) >> 8);
	mem_write8(x + 5u, b);
	return y;
}

void unreached_03A2A0(uint16_t x)
{
	mem_write16(x + 0x38u, 0x1234u);
	sub_03A07B(x);
}

void sub_03A2AA(uint16_t x)
{
	uint16_t t1 = 0;

	mem_write8(x + 4u, 0x9Cu);
	mem_write8(x + 0x1Bu, 0x80u);
	mem_write8(x + 0x3Du, 0x80u);
	mem_write8(x + 0x2Eu, 1u);
	mem_write8(x + 0x36u, 2u);
	t1 = AT16(unk_4858, -1);
	io_write16(VIDEO_1852, t1);
	mem_write8(x + 0x2Du, 2u);
	mem_write16(x + 0xCu, 0x1A0u);
}

uint16_t sub_03A2D4(uint16_t x, uint16_t y)
{
	uint8_t d = 0;
	uint8_t t1 = 0;

	if (unk_4892 != 0u)
		return y;
	mem_write16(x + 0xFu, 0xFE00u);
	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, t1 | 0x40u);
	d = 2u;
	return sub_03A29A(x, d);
}

uint16_t sub_03A2F2(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	unk_48A7 = 1u;
	unk_48A8 = 1u;
	sub_03A084(x, &y, &carry);
	t1 = mem_read8(x + VIDEO_002F);
	mem_write8(x + VIDEO_002F, t1 - 1u);
	if (t1 == 1u)
		return sub_03A303(x);
	return y;
}

uint16_t sub_03A303(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t d_2 = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x2Eu);
	if (t1 == 0x17u)
	{
		d = 0x4700u;
		carry = sub_078680(d);
	}
	t2 = mem_read8(x + 0x2Eu);
	d_2 = (uint8_t)(t2 + 1u);
	return sub_03A294(x, d_2);
}

uint16_t sub_03A317(uint16_t x, uint16_t y)
{
	uint8_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + VIDEO_002F);
	mem_write8(x + VIDEO_002F, t1 - 1u);
	if (t1 == 1u)
	{
		unk_487C = 1u;
		t2 = mem_read8(x + 0x2Eu);
		d = (uint8_t)(t2 + 1u);
		return sub_03A294(x, d);
	}
	return y;
}

uint16_t sub_03A329(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, y = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + VIDEO_002F);
	mem_write8(x + VIDEO_002F, t1 - 1u);
	if (t1 != 1u)
	{
		y = child_object_03BA78_ADDRESS;
		sub_07862F(x, y, &ignored16, &carry);
		d = 0x3F34u;
		carry = sub_078680(d);
		return sub_03A303(x);
	}
	t2 = mem_read8(x + 0x2Eu);
	if (t2 != 4u)
		return sub_03A303(x);
	y = child_object_03BA78_ADDRESS;
	sub_07862F(x, y, &ignored16, &carry);
	d = 0x3F34u;
	carry = sub_078680(d);
	return sub_03A303(x);
}

void unused_03A337(void)
{
}

uint16_t sub_03A346(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, y_2 = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) != 0u)
	{
		d = (uint32_t)(uint8_t)((uint32_t)unk_4857 << 1) << 8;
		sub_03A925(x, d, &y, &ignored16);
	}
	t2 = mem_read8(x + 6u);
	carry = (t2 >> 0) & 1u;
	if (carry == 0u)
		return y;
	mem_write8(x, 0xC0u);
	mem_write16(x + 0x1Cu, 0u);
	y_2 = indexed_table_03BA94_ADDRESS;
	sub_03A20E(x, y_2);
	mem_write8(x + 0x32u, 0x56u);
	return sub_03A303(x);
}

uint16_t sub_03A370(uint16_t x, uint16_t u)
{
	uint8_t t1 = 0;

	unk_48A7 = 0u;
	unk_48A8 = 0u;
	t1 = mem_read8(x + 0x2Du);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		return sub_03A4FA(x);
	case 2:
		return sub_03A441(x, u);
	case 4:
		return sub_03A37F(x, u);
	}
	unreachable();
}

uint16_t sub_03A37F(uint16_t x, uint16_t u)
{
	bool L_03A3A4 = false;
	uint32_t carry = 0;
	uint8_t a = 0, b = 0, d_2 = 0;
	uint16_t d = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0, t2 = 0, t4 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0;
	uint16_t t3 = 0, t5 = 0, t6 = 0, t7 = 0;

	t1 = mem_read8(x + 0x32u);
	if (t1 != 0u)
	{
		t2 = mem_read8(x + 0x32u);
		mem_write8(x + 0x32u, t2 - 1u);
		if (t2 != 1u)
		{
			t3 = mem_read16(x + 0xFu);
			if (t3 == 0u)
			{
				mem_write8(x + 5u, 0x90u);
				L_03A3A4 = true;
			}
			if (!L_03A3A4)
			{
				d = sub_03A991(x);
				a = (uint8_t)(d >> 8);
				b = (uint8_t)d;
			}
			if (L_03A3A4 || (int16_t)(((uint32_t)a << 8) | b) <= 0xC0 || (unk_4858 & 0x3Fu) == 0u)
			{
				t4 = mem_read8(x + 0x38u);
				a = t4;
				if ((a & 1u) == 0u)
					a &= ~3u;
				else
				{
					u = sub_078620(x);
					d = sub_07861D(x, u);
					a = (uint8_t)(d >> 8);
				}
				stack = a;
				d = ((uint32_t)stack << 8) | DATA8(indexed_table_03BAC5_ADDRESS + (int8_t)unk_4857);
				sub_078617(x, d);
				sub_03A96E(x);
				t5 = mem_read16(x + 0xFu);
				t6 = mem_read16(x + 0xFu);
				t7 = t5 + t6;
				mem_write16(x + 0xFu, t7);
			}
			t8 = mem_read8(x + VIDEO_002F);
			mem_write8(x + VIDEO_002F, t8 - 1u);
			if (t8 == 1u)
			{
				d = 0x7900u;
				carry = sub_078680(d);
				d_2 = 0x13u;
				sub_03A294(x, d_2);
				t9 = mem_read8(x + 0x35u);
				mem_write8(x + 0x35u, t9 + 1u);
				return sub_03A680(x, u);
			}
			t10 = mem_read8(x + VIDEO_003C);
			mem_write8(x + VIDEO_003C, t10 + 1u);
			t11 = mem_read8(x + VIDEO_003C);
			if (t11 <= 0x78u)
				return sub_03A680(x, u);
			mem_write8(x + VIDEO_003C, 0u);
			carry = sub_03A02D();
			if (carry == 0u)
				return sub_03A680(x, u);
			d = 0x7900u;
			carry = sub_078680(d);
			d_2 = 0x13u;
			sub_03A294(x, d_2);
			t9 = mem_read8(x + 0x35u);
			mem_write8(x + 0x35u, t9 + 1u);
			return sub_03A680(x, u);
		}
	}
	if (unk_4858 > 0xC0u)
	{
		d_2 = 0xBu;
		sub_03A294(x, d_2);
		u = sub_03A23C(x);
	}
	else
	{
		d = sub_03A991(x);
		a = (uint8_t)(d >> 8);
		b = (uint8_t)d;
		if ((int16_t)(((uint32_t)a << 8) | b) <= 0xC0)
		{
			d_2 = 0xBu;
			sub_03A294(x, d_2);
			u = sub_03A23C(x);
			mem_write8(x + 0x32u, 0x56u);
			if ((int8_t)unk_4858 <= (int8_t)DATA8(indexed_table_03BAA5_ADDRESS + (int8_t)unk_4857))
				return sub_03A626(x);
			t12 = mem_read8(x + 0x33u);
			mem_write8(x + 0x33u, t12 + 1u);
			t13 = mem_read8(x + 0x33u);
			if (t13 > 3u)
			{
				mem_write8(x + 0x33u, 0u);
				return sub_03A680(x, u);
			}
			mem_write8(x + 0x32u, 1u);
			return sub_03A680(x, u);
		}
		d_2 = 0xCu;
		sub_03A29A(x, d_2);
	}
	mem_write8(x + 0x32u, 0x56u);
	if ((int8_t)unk_4858 <= (int8_t)DATA8(indexed_table_03BAA5_ADDRESS + (int8_t)unk_4857))
		return sub_03A626(x);
	t12 = mem_read8(x + 0x33u);
	mem_write8(x + 0x33u, t12 + 1u);
	t13 = mem_read8(x + 0x33u);
	if (t13 > 3u)
	{
		mem_write8(x + 0x33u, 0u);
		return sub_03A680(x, u);
	}
	mem_write8(x + 0x32u, 1u);
	return sub_03A680(x, u);
}

uint16_t sub_03A422(uint16_t x, uint16_t u)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	a = t1;
	if ((a & 2u) == 0u)
	{
		carry = (a >> 0) & 1u;
		if (carry == 0u)
			return sub_03A626(x);
		return sub_03A5D1(x, u);
	}
	a = DATA8(indexed_table_03BAA9_ADDRESS + (int8_t)unk_4857);
	unk_48F0 = a;
	d = (uint32_t)a << 8;
	sub_03A925(x, d, &ignored16, &ignored16_2);
	return sub_03A626(x);
}

uint16_t sub_03A441(uint16_t x, uint16_t u)
{
	uint32_t negative = 0;
	uint8_t a = 0, b = 0, d = 0;
	uint16_t d_2 = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0;

	d = 0xDu;
	sub_03A29A(x, d);
	mem_write16(x + 0x14u, 0u);
	a = DATA8(indexed_table_03BAAD_ADDRESS + (int8_t)unk_4857);
	if ((int8_t)unk_4858 < 0)
		a = 0u - a;
	stack = a;
	sub_07863B(x, &d_2, &negative);
	a = (uint8_t)(d_2 >> 8);
	b = (uint8_t)d_2;
	t1 = a;
	a = stack;
	if ((int8_t)t1 < 0)
		a = 0u - a;
	mem_write16(x + 0xFu, ((uint32_t)a << 8) | b);
	mem_write8(x + 0x36u, a);
	mem_write8(x + 0x34u, 0x80u);
	return sub_03A46E(x, u);
}

uint16_t sub_03A46E(uint16_t x, uint16_t u)
{
	uint32_t negative = 0;
	uint8_t a = 0, d_2 = 0;
	uint16_t d = 0, ignored16 = 0, u_2 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0;

	t1 = mem_read8(x + 0x32u);
	if (t1 == 0u)
		sub_03A180(x);
	else
	{
		t2 = mem_read8(x + 0x32u);
		mem_write8(x + 0x32u, t2 - 1u);
		if (t2 == 1u)
			sub_03A180(x);
	}
	sub_07863B(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	if ((int8_t)a < 0)
	{
		t3 = mem_read8(x + 0x36u);
		a = 0u - t3;
		mem_write8(x + 0x36u, a);
		mem_write16(x + 0xFu, (uint32_t)a << 8);
	}
	t4 = mem_read8(x + 6u);
	if ((t4 & 2u) != 0u)
	{
		t5 = mem_read8(x + 0x3Eu);
		mem_write8(x + 0x3Eu, t5 + 1u);
		t6 = mem_read8(x + 0x3Eu);
		if ((t6 & 6u) != 0u)
		{
			a = (uint32_t)unk_4857 << 1;
			unk_48F0 = a;
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			sub_03A925(x, d, &ignored16, &u);
		}
	}
	sub_03A96E(x);
	t7 = mem_read8(x + 0x34u);
	mem_write8(x + 0x34u, t7 - 1u);
	if (t7 != 1u)
	{
		if (unk_4858 < DATA8(indexed_table_03BAB9_ADDRESS + (int8_t)unk_4857))
			return sub_03A683(x, u);
		return sub_03A626(x);
	}
	sub_03A0E7(&u_2, &d);
	d = sub_078671(x, u_2, d);
	a = (uint8_t)(d >> 8);
	d = ((uint32_t)a << 8) | DATA8(indexed_table_03BAC5_ADDRESS + (int8_t)unk_4857);
	sub_078617(x, d);
	d_2 = 0xEu;
	sub_03A29A(x, d_2);
	sub_03A21C(x);
	return sub_03A683(x, u_2);
}

uint16_t sub_03A4DE(uint16_t x, uint16_t u)
{
	uint16_t d = 0, ignored16 = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Eu);
	if ((t1 & 3u) == 0u && (unk_4815 & 3u) == 0u)
	{
		d = 0x100u;
		sub_03A925(x, d, &ignored16, &u);
	}
	t2 = mem_read8(x + VIDEO_002F);
	mem_write8(x + VIDEO_002F, t2 - 1u);
	if (t2 != 1u)
		return sub_03A626(x);
	return sub_03A5D1(x, u);
}

uint16_t sub_03A4FA(uint16_t x)
{
	uint8_t d = 0;
	uint16_t ignored16 = 0, u = 0;
	uint8_t t1 = 0;

	sub_03A0E7(&u, &ignored16);
	mem_write16(x + 0x3Au, u);
	d = 0xFu;
	sub_03A29A(x, d);
	mem_write16(x + 0xFu, 1u);
	t1 = mem_read8(x + 0x33u);
	mem_write8(x + 0x33u, t1 + 1u);
	mem_write8(x + 0x34u, 1u);
	sub_03A07B(x);
	return sub_03A516(x);
}

uint16_t sub_03A516(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t a = 0, d_2 = 0;
	uint16_t d = 0, ignored16 = 0, u = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;
	uint16_t t4 = 0;

	if ((unk_4815 & 0x3Fu) == 0u)
	{
		t1 = mem_read8(x + 0x34u);
		mem_write8(x + 0x34u, t1 - 1u);
		if (t1 == 1u)
		{
			sub_03A0E7(&u, &ignored16);
			d = 0x14u;
			d = sub_078671(x, u, d);
			a = (uint8_t)(d >> 8);
			d = ((uint32_t)a << 8) | DATA8(indexed_table_03BACD_ADDRESS + (int8_t)unk_4857);
			sub_078617(x, d);
			sub_03A21C(x);
			d_2 = 0x14u;
			sub_03A29A(x, d_2);
			mem_write8(x + 0x34u, 3u);
			return sub_03A680(x, u);
		}
		sub_03A0E7(&u, &ignored16);
		mem_write16(x + 0x3Au, u);
	}
	carry = sub_03A25B(x);
	if (carry)
	{
		d_2 = 0x10u;
		sub_03A29A(x, d_2);
		mem_write16(x + 0x19u, 0x900u);
		t2 = mem_read8(x + 0x17u);
		mem_write8(x + 0x17u, t2 + 1u);
		sub_03A0E7(&u, &ignored16);
		d = sub_07861D(x, u);
		a = (uint8_t)(d >> 8);
		u = indexed_table_03BAC9_ADDRESS;
		d = ((uint32_t)a << 8) | DATA8(indexed_table_03BAC9_ADDRESS + (int8_t)unk_4857);
		sub_078617(x, d);
		sub_03A072(x);
		sub_03A21C(x);
		mem_write8(x + 0x32u, 0u);
		mem_write8(x + 0x33u, 0u);
		return sub_03A680(x, u);
	}
	t3 = mem_read8(x + 0x33u);
	if (t3 > 5u)
	{
		d_2 = 0x10u;
		sub_03A29A(x, d_2);
		mem_write16(x + 0x19u, 0x900u);
		t2 = mem_read8(x + 0x17u);
		mem_write8(x + 0x17u, t2 + 1u);
		sub_03A0E7(&u, &ignored16);
		d = sub_07861D(x, u);
		a = (uint8_t)(d >> 8);
		u = indexed_table_03BAC9_ADDRESS;
		d = ((uint32_t)a << 8) | DATA8(indexed_table_03BAC9_ADDRESS + (int8_t)unk_4857);
		sub_078617(x, d);
		sub_03A072(x);
		sub_03A21C(x);
		mem_write8(x + 0x32u, 0u);
		mem_write8(x + 0x33u, 0u);
		return sub_03A680(x, u);
	}
	t4 = mem_read16(x + 0x3Au);
	u = t4;
	d = sub_07861D(x, u);
	a = (uint8_t)(d >> 8);
	d = ((uint32_t)(uint8_t)(a - 0x80u) << 8) | DATA8(indexed_table_03BAC1_ADDRESS + (int8_t)unk_4857);
	sub_078617(x, d);
	sub_03A21C(x);
	return sub_03A680(x, u);
}

uint16_t sub_03A59E(uint16_t x, uint16_t u)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, u_2 = 0;
	uint8_t t1 = 0, t2 = 0;

	sub_03A084(x, &ignored16, &carry);
	if (carry)
		return sub_03A5D1(x, u);
	t1 = mem_read8(x + 0x32u);
	mem_write8(x + 0x32u, t1 + 1u);
	t2 = mem_read8(x + 0x32u);
	if ((int8_t)unk_4857 <= (int8_t)DATA8(indexed_table_03BAD1_ADDRESS + (int8_t)t2))
		return sub_03A683(x, u);
	mem_write8(x + 0x32u, 0u);
	d = 0x100u;
	sub_03A925(x, d, &ignored16, &u_2);
	return sub_03A683(x, u_2);
}

uint16_t sub_03A5C0(uint16_t x, uint16_t u)
{
	uint16_t d = 0;
	uint8_t t1 = 0;

	sub_03A072(x);
	d = sub_03A991(x);
	if ((int16_t)d > 0xC0)
	{
		t1 = mem_read8(x + VIDEO_002F);
		mem_write8(x + VIDEO_002F, t1 - 1u);
		if (t1 != 1u)
			return sub_03A626(x);
	}
	return sub_03A5D1(x, u);
}

uint16_t sub_03A5D1(uint16_t x, uint16_t u)
{
	uint8_t d = 0;
	uint16_t y = 0;

	d = 9u;
	sub_03A294(x, d);
	y = indexed_table_03BA94_ADDRESS;
	sub_03A20E(x, y);
	return sub_03A683(x, u);
}

uint16_t sub_03A5DF(uint16_t x, uint16_t u)
{
	uint32_t zero = 0;
	uint8_t d = 0;
	uint16_t u_2 = 0, y = 0;
	uint8_t t1 = 0;

	sub_03A180(x);
	t1 = mem_read8(x + VIDEO_002F);
	mem_write8(x + VIDEO_002F, t1 - 1u);
	if (t1 != 1u)
		return sub_03A680(x, u);
	y = indexed_table_03BA98_ADDRESS;
	sub_03A20E(x, y);
	u_2 = sub_03A23C(x);
	zero = sub_03A177(x);
	d = 0x11u;
	sub_03A294(x, d);
	return sub_03A680(x, u_2);
}

uint16_t sub_03A5FC(uint16_t x, uint16_t u)
{
	uint32_t zero = 0, carry = 0;
	uint8_t d = 0;
	uint16_t y = 0;

	y = 0x40Au;
	carry = sub_03A1F7(x, y);
	if (carry == 0u)
		return sub_03A680(x, u);
	zero = sub_03A177(x);
	d = 0x12u;
	sub_03A294(x, d);
	return sub_03A680(x, u);
}

uint16_t sub_03A610(uint16_t x, uint16_t u)
{
	uint32_t carry = 0;
	uint16_t y = 0;

	y = 0x40Au;
	carry = sub_03A1F7(x, y);
	if (carry == 0u)
		return sub_03A680(x, u);
	return sub_03A5D1(x, u);
}

uint16_t sub_03A61C(uint16_t x, uint16_t u)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + VIDEO_002F);
	mem_write8(x + VIDEO_002F, t1 - 1u);
	if (t1 != 1u)
		return sub_03A680(x, u);
	return sub_03A5D1(x, u);
}

void sub_03A625(void)
{
}

uint16_t sub_03A626(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t d = 0;
	uint16_t u = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	unk_48F8 = 0x30u;
	unk_48FA = 0x10u;
	sub_03A12E(x, &u, &carry);
	if (carry == 0u)
		return sub_03A680(x, u);
	d = 0x1Du;
	sub_03A294(x, d);
	t1 = mem_read8(x + 0x3Du);
	t2 = mem_read8(x + 0x1Bu);
	if ((uint8_t)(t1 - t2) > 0x10u)
	{
		t3 = mem_read8(x + 0x1Bu);
		mem_write8(x + 0x3Du, t3);
		return sub_03A680(x, u);
	}
	mem_write8(x + VIDEO_002F, 0x14u);
	return sub_03A680(x, u);
}

void unreached_03A658(uint16_t x, uint16_t u)
{
	uint8_t d = 0;

	d = 0x1Du;
	sub_03A294(x, d);
	sub_03A680(x, u);
}

uint16_t sub_03A680(uint16_t x, uint16_t u)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;

	sub_03A084(x, &ignored16, &carry);
	return sub_03A683(x, u);
}

uint16_t sub_03A683(uint16_t x, uint16_t u)
{
	uint32_t zero = 0, negative = 0, carry = 0;
	uint8_t d_2 = 0;
	uint16_t d = 0, ignored16 = 0, x_2 = 0, y = 0;
	uint16_t stack = 0;
	uint8_t t1 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;
	uint16_t t2 = 0, t7 = 0, t8 = 0;

	y = indexed_table_03BABD_ADDRESS;
	sub_03A189(x, y, &u, &zero, &negative);
	if (zero)
		return y;
	if (negative)
	{
		d = 0x7900u;
		carry = sub_078680(d);
		d_2 = 0x17u;
		return sub_03A294(x, d_2);
	}
	stack = x;
	t1 = mem_read8(x + 0x2Du);
	if (t1 == 0u)
	{
		unk_487E = 2u;
		d = 0x41u;
		sub_078677(d, &ignored16, &u);
	}
	else
	{
		unk_487E = 2u;
		d = 0x40u;
		sub_078677(d, &ignored16, &u);
	}
	x_2 = stack;
	t2 = mem_read16(x_2 + 0x25u);
	t3 = mem_read8(t2 + 9u);
	t4 = mem_read8(x_2 + 9u);
	if (((t3 ^ t4) & 0x40u) == 0u)
	{
		t5 = mem_read8(x_2 + 9u);
		mem_write8(x_2 + 9u, t5 ^ 0x40u);
	}
	t6 = mem_read8(x_2 + 0x1Eu);
	if ((int8_t)t6 >= 0x13)
	{
		d_2 = 0x16u;
		return sub_03A294(x_2, d_2);
	}
	t7 = mem_read16(x_2 + 0x19u);
	if ((int16_t)t7 > 0x400)
		mem_write16(x_2 + 0x19u, 0x400u);
	t8 = mem_read16(x_2 + 0x16u);
	if (t8 != 0u)
	{
		d_2 = 0x16u;
		return sub_03A294(x_2, d_2);
	}
	d_2 = 0x15u;
	return sub_03A294(x_2, d_2);
}

uint16_t sub_03A6F3(uint16_t x, uint16_t y, uint16_t u)
{
	uint32_t zero = 0, carry = 0;
	uint8_t a = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	sub_03A084(x, &y, &carry);
	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
		return y;
	mem_write8(x, 0xC0u);
	t2 = mem_read8(x + 0x2Du);
	if (t2 != 1u)
		return sub_03A5D1(x, u);
	t3 = mem_read8(x + 0x33u);
	mem_write8(x + 0x33u, t3 + 1u);
	t4 = mem_read8(x + 0x33u);
	a = unk_4857;
	if (t4 <= mem_read8(value_03BAB1 + (int8_t)a))
		return sub_03A5D1(x, u);
	mem_write8(x + 0x33u, 0u);
	y = indexed_table_03BAB5_ADDRESS;
	mem_write8(x + 0x32u, DATA8(indexed_table_03BAB5_ADDRESS + (int8_t)a));
	zero = sub_03A177(x);
	if (zero == 0u)
		return sub_03A5D1(x, u);
	return y;
}

uint16_t sub_03A72D(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t d = 0;
	uint8_t t1 = 0;

	sub_03A084(x, &y, &carry);
	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
		return y;
	d = 0x1Eu;
	return sub_03A294(x, d);
}

uint16_t sub_03A73B(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	unk_48A7 = 1u;
	unk_48A8 = 1u;
	mem_write16(x + 0x1Cu, 0u);
	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 6u);
	a = t1;
	if ((a & 1u) != 0u)
		return sub_03A303(x);
	if ((a & 2u) == 0u)
		return y;
	d = 0x6F00u;
	carry = sub_078680(d);
	mem_write16(x + 0x1Cu, 5u);
	mem_write8(x, 0xC0u);
	return y;
}

uint16_t sub_03A769(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	unk_48A7 = 1u;
	unk_48A8 = 1u;
	sub_03A084(x, &y, &carry);
	t1 = mem_read8(x + VIDEO_002F);
	mem_write8(x + VIDEO_002F, t1 - 1u);
	if (t1 != 1u)
		return y;
	d = 0xFD00u;
	carry = sub_078680(d);
	return sub_03A303(x);
}

void sub_03A782(uint16_t x, uint8_t d)
{
	uint32_t carry = 0;

	carry = sub_03A1DE(x);
	if (carry)
	{
		unk_48A7 = 0u;
		unk_48A8 = 0u;
		unk_487D = 1u;
		unk_4804++;
		unk_4805 = 0x100u | d;
	}
}

void sub_03A7DC(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, ignored16 = 0, u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t8 = 0, t23 = 0;
	uint16_t t4 = 0, t5 = 0, t6 = 0, t7 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0, t15 = 0, t16 = 0, t17 = 0, t18 = 0, t19 = 0, t20 = 0, t21 = 0, t22 = 0;

	mem_write8(x, 0x80u);
	mem_write16(x + 4u, 0x9C89u);
	sub_03A072(x);
	mem_write8(x + 0x5Bu, 2u);
	t1 = io_read8(VIDEO_1852);
	unk_48F0 = (t1 & 7u) - 3u;
	sub_03A0E7(&u, &ignored16);
	t2 = mem_read8(u + 2u);
	if ((int8_t)t2 >= 0)
	{
		d = sub_07861D(x, u);
		a = (uint8_t)(d >> 8);
	}
	else
		a = unk_4858;
	t3 = io_read8(VIDEO_1852);
	d = ((uint32_t)(uint8_t)(a + unk_48F0) << 8) | (uint8_t)((((t3 & 0x78u) >> 1) >> 1) + 0x1Au);
	sub_078617(x, d);
	t4 = mem_read16(x + 0xFu);
	t5 = mem_read16(x + 0xFu);
	t6 = t4 + t5;
	mem_write16(x + 0xFu, t6);
	t7 = mem_read16(x + 0x40u);
	y = t7;
	t8 = mem_read8(y + 0x2Eu);
	if (t8 == 0xEu)
		mem_write16(x + 0x2Eu, 0x3A0u);
	else
	{
		t9 = mem_read16(x + 0xCu);
		t10 = mem_read16(u + 0xCu);
		t11 = t9 - t10;
		t12 = t11;
		t13 = t12 >> 15 ? 0u - t12 : t12;
		unk_48F8 = t13;
		t14 = mem_read16(x + 0x11u);
		t15 = mem_read16(u + 0x11u);
		t16 = t14 - t15;
		t17 = t16;
		t18 = t17 >> 15 ? 0u - t17 : t17;
		t19 = t18 + unk_48F8;
		t20 = t19 + unk_48F8;
		a = (uint8_t)(t20 >> 8);
		b = (uint8_t)t20;
		unk_48F8 = ((uint32_t)a << 8) | b;
		t21 = (((uint32_t)a << 8) | b) + unk_48F8;
		a = (uint8_t)(t21 >> 8);
		b = (uint8_t)t21;
		mem_write16(x + 0x19u, ((uint32_t)a << 8) | b);
		if ((int16_t)(((uint32_t)a << 8) | b) >= 0x2C0)
		{
			d = 0x301u;
			carry = sub_078680(d);
		}
		else
		{
			t22 = mem_read16(x + 0x16u);
			if (t22 > 0x40u)
			{
				d = 0x301u;
				carry = sub_078680(d);
			}
		}
		t23 = mem_read8(x + 0x2Eu);
		mem_write8(x + 0x2Eu, t23 + 1u);
		y = VIDEO_1852;
		sub_03A95C(y);
	}
	*p_y = y;
	*p_u = u;
}

void sub_03A871(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint8_t t1 = 0;

	t1 = mem_read8(x + VIDEO_002F);
	mem_write8(x + VIDEO_002F, t1 - 1u);
	if (t1 == 1u)
		y = sub_03A8E2(x);
	else
		sub_03A877(x, &y, &u);
	*p_y = y;
	*p_u = u;
}

void sub_03A877(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t negative = 0, carry = 0;
	uint16_t d = 0, u = 0;
	uint8_t t3 = 0, t4 = 0, t12 = 0, t13 = 0;
	uint16_t t1 = 0, t2 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t14 = 0;

	t1 = mem_read16(x + 0x16u);
	u = t1;
	if ((int16_t)t1 < 0)
	{
		carry = sub_03A02D();
		if (carry)
			y = sub_03A8E2(x);
		else
		{
			t2 = mem_read16(x + 0x40u);
			y = t2;
			t3 = mem_read8(y + 0x1Bu);
			if (t3 == 0u)
				y = sub_03A8E2(x);
			else
			{
				t4 = mem_read8(y + 0x2Eu);
				if ((uint16_t)((uint32_t)t4 << 8) >> 8 == 0xEu)
				{
					t5 = mem_read16(x + 0xFu);
					t6 = mem_read16(x + 0xFu);
					t7 = mem_read16(x + 0xFu);
					mem_write16(x + 0xFu, (int16_t)(t5 + t6 + t7) >> 2);
					t8 = mem_read16(x + 0x14u);
					t9 = mem_read16(x + 0x14u);
					t10 = mem_read16(x + 0x14u);
					mem_write16(x + 0x14u, (int16_t)(t8 + t9 + t10) >> 2);
					t11 = mem_read16(x + 0x19u);
					mem_write16(x + 0x19u, 0u - ((int16_t)t11 >> 1));
					mem_write16(x + 0x16u, 0u);
				}
				else
				{
					t12 = mem_read8(y + 0x2Du);
					if ((uint16_t)((uint32_t)t12 << 8) >> 8 != 1u)
						y = sub_03A8E2(x);
					else
					{
						y = VIDEO_1852;
						sub_03A95C(y);
						t13 = io_read8(VIDEO_1852);
						if ((int8_t)t13 >= 0)
							y = sub_03A8E2(x);
						else
						{
							t5 = mem_read16(x + 0xFu);
							t6 = mem_read16(x + 0xFu);
							t7 = mem_read16(x + 0xFu);
							mem_write16(x + 0xFu, (int16_t)(t5 + t6 + t7) >> 2);
							t8 = mem_read16(x + 0x14u);
							t9 = mem_read16(x + 0x14u);
							t10 = mem_read16(x + 0x14u);
							mem_write16(x + 0x14u, (int16_t)(t8 + t9 + t10) >> 2);
							t11 = mem_read16(x + 0x19u);
							mem_write16(x + 0x19u, 0u - ((int16_t)t11 >> 1));
							mem_write16(x + 0x16u, 0u);
						}
					}
				}
			}
		}
	}
	else
	{
		t14 = mem_read16(x + 0x19u);
		u = t14 - 0x18u;
		mem_write16(x + 0x19u, u);
		sub_07863B(x, &d, &negative);
		if ((uint8_t)((d >> 8) + 1u) == 0u)
		{
			mem_write16(x + 0xFu, 0u);
			mem_write16(x + 0x14u, 0u);
		}
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_03A8E2(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0, y = 0;

	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write16(x + 0x19u, 0u);
	mem_write16(x + 0x16u, 0u);
	mem_write8(x, 0xC0u);
	d = 0x6F00u;
	carry = sub_078680(d);
	sub_03A07B(x);
	y = 0x200u;
	d = 0x8A00u;
	sub_03A058(x, y, d);
	mem_write16(x + 0x1Cu, 0x405u);
	y = indexed_table_03BADE_ADDRESS;
	return sub_03A20E(x, y);
}

void sub_03A910(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	a = t1;
	if ((a & 2u) != 0u)
		mem_write8(x, 0x80u);
	carry = (a >> 0) & 1u;
	if (carry)
	{
		mem_write8(x, 0u);
		return;
	}
}

void sub_03A925(uint16_t x, uint16_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint32_t carry = 0;
	uint16_t d_2 = 0, ignored16 = 0, u = 0, y = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0;

	unk_48F0 = d >> 8;
	do
	{
		y = child_object_03BA7E_ADDRESS;
		sub_07862F(x, y, &u, &carry);
		if (carry == 0u)
		{
			y = child_object_03BA84_ADDRESS;
			*p_u = u;
			sub_07862C(x, y, p_u, &ignored16, &carry);
			*p_y = y;
			return;
		}
		t1 = unk_48F0;
		unk_48F0 = t1 - 1u;
	} while (t1 != 1u);
	t2 = mem_read16(x + 0x16u);
	if (t2 == 0u)
	{
		t3 = mem_read16(x + 0xCu);
		d_2 = t3;
		if ((int16_t)d_2 > 0x30 && (int16_t)d_2 < 0x1A0)
		{
			t4 = mem_read16(x + 0x11u);
			if ((int16_t)t4 > 0x90)
			{
				y = child_object_03BA8C_ADDRESS;
				sub_07862C(x, y, &u, &ignored16, &carry);
			}
		}
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_03A95C(uint16_t y)
{
	uint16_t d = 0;
	uint16_t stack = 0;

	d = io_read16(y);
	stack = d;
	d = d + io_read16(y) + io_read16(y) + io_read16(y) + stack + 0x3711u;
	io_write16(y, d);
	return d;
}

void sub_03A96E(uint16_t x)
{
	uint8_t a = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0xFu);
	if ((int16_t)t1 < 0)
	{
		t2 = mem_read8(x + 9u);
		a = t2;
		if ((a & 0x40u) == 0u)
		{
			mem_write8(x + 9u, a ^ 0x40u);
			t3 = mem_read8(x + 5u);
			mem_write8(x + 5u, t3 | 0x80u);
		}
		return;
	}
	t4 = mem_read8(x + 9u);
	a = t4;
	if ((a & 0x40u) == 0u)
		return;
	if ((a & 0x40u) != 0u)
	{
		mem_write8(x + 9u, a ^ 0x40u);
		t3 = mem_read8(x + 5u);
		mem_write8(x + 5u, t3 | 0x80u);
		return;
	}
	t2 = mem_read8(x + 9u);
	a = t2;
	if ((a & 0x40u) == 0u)
	{
		mem_write8(x + 9u, a ^ 0x40u);
		t3 = mem_read8(x + 5u);
		mem_write8(x + 5u, t3 | 0x80u);
	}
}

uint16_t sub_03A991(uint16_t x)
{
	uint16_t d = 0;
	uint16_t stack = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = mem_read16(x + 0xFu);
	stack = t1 >> 15 ? 0u - t1 : t1;
	t2 = mem_read16(x + 0x14u);
	d = (t2 >> 15 ? 0u - t2 : t2) + stack;
	return d;
}

uint16_t sub_03A9D3(uint16_t x, uint16_t y)
{
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_03BB0A_ADDRESS;
		t1 = mem_read8(x + 0x28u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			sub_03A9DC(x);
			return y;
		case 2:
			return sub_03AA0F(x, y);
		case 4:
			sub_03AA64(x);
			return y;
		case 6:
			return sub_03AA6A(x, y);
		case 8:
			sub_03AA92(x);
			return y;
		case 10:
		case 14:
			sub_03AB20(x);
			return y;
		case 12:
			return sub_03AAAD(x, y);
		case 16:
			return sub_03AB38(x, y);
		case 18:
		case 32:
			sub_03AC06(x);
			return y;
		case 20:
		case 34:
			sub_03AC1B(x);
			return y;
		case 22:
			return sub_03ABA2(x, y);
		case 24:
		case 38:
			sub_03AC73(x);
			return y;
		case 26:
		case 40:
			sub_03AC81(x);
			return y;
		case 28:
		case 42:
			sub_03AC9F(x);
			return y;
		case 30:
		case 44:
			return sub_03ACBF(x, y);
		case 36:
			return sub_03AC40(x, y);
		case 46:
			return sub_03AD10(x, y, u);
		case 48:
			return sub_03AD2F(x, y);
		case 50:
			sub_03AD44(x);
			return y;
		case 52:
			sub_03AD6B(x);
			return y;
		case 54:
			sub_03AD79(x);
			return y;
		case 56:
			sub_03AD90(x);
			return y;
		case 58:
			sub_03ADA9(x);
			return y;
		case 60:
			return sub_03ADD7(x, y);
		case 62:
			sub_03AE05(x);
			return y;
		case 64:
			sub_03AE28(x);
			return y;
		case 66:
		case 72:
			sub_03AEF3(x);
			return y;
		case 68:
		case 88:
			sub_03AF1E(x);
			return y;
		case 70:
		case 90:
			return sub_03AF41(x, y);
		case 74:
			return sub_03AF50(x, y);
		case 76:
			sub_03AFA0(x);
			return y;
		case 78:
			break;
		case -40:
			continue;
		case -38:
			return sub_03AAA4(x, y);
		case -36:
			return sub_03AB17(x, y);
		case -34:
			return sub_03AB99(x, y);
		case -32:
			return sub_03ABFD(x, y);
		case -30:
			return sub_03AD07(x, y);
		case -28:
			return sub_03AD3B(x, y);
		case -26:
			return sub_03AE41(x, y);
		case -24:
			return sub_03AE74(x, y);
		case -22:
		case -20:
		case -18:
			return sub_03AEB4(x, y);
		case -16:
		case -14:
		case -12:
			return sub_03AEEA(x, y);
		case -10:
			return sub_03AF47(x, y);
		case -8:
			return sub_03AFD8(x, y);
		case -6:
			return sub_03AFE8(x);
		case -4:
			return sub_03B084(x, y);
		case -2:
			return sub_03B12C(x, y);
		}
		break;
	}
	return sub_03AFCA(x, y);
}

void sub_03A9DC(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t d = 0;
	uint16_t u = 0;
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0;

	mem_write8(x + 5u, 0x84u);
	d = 1u;
	sub_07867D(d, &u, &carry);
	mem_write8(u + 1u, 0xE7u);
	t1 = 0x420u - unk_48AC;
	mem_write16(u + 0xCu, t1);
	t2 = 0xA8u + unk_48B2;
	mem_write16(u + 0x11u, t2);
	mem_write16(x + 0x38u, u);
	mem_write8(x + 0x29u, 0xC0u);
	mem_write16(x + 0x46u, 0x100u);
	t3 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t3 + 1u);
}

uint16_t sub_03AA0F(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t d = 0, u = 0, y_2 = 0;
	uint8_t t2 = 0, t3 = 0, t5 = 0;
	uint16_t t1 = 0, t4 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0;
	uint32_t unk_48F0_halfword = 0;

	t1 = mem_read16(x + 0x38u);
	u = t1;
	t2 = mem_read8(x + 0x29u);
	if (t2 != 0u)
	{
		t3 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t3 - 1u);
	}
	else
	{
		t4 = mem_read16(x + 0x46u);
		mem_write16(x + 0x46u, t4 - 1u);
		if (t4 == 1u)
		{
			d = 0x6E00u;
			carry = sub_078680(d);
			t5 = mem_read8(x + 0x28u);
			mem_write8(x + 0x28u, t5 + 1u);
			return y;
		}
		t6 = mem_read16(x + 0xCu);
		t7 = mem_read16(u + 0xCu);
		d = t6 - t7;
		if ((int16_t)(d >> 15 ? 0u - d : d) <= 0x20)
		{
			t8 = mem_read16(x + 0x11u);
			t9 = mem_read16(u + 0x11u);
			d = t8 - t9;
			if ((int16_t)(d >> 15 ? 0u - d : d) <= 0x20)
			{
				d = 0x6E00u;
				carry = sub_078680(d);
				t5 = mem_read8(x + 0x28u);
				mem_write8(x + 0x28u, t5 + 1u);
				return y;
			}
		}
	}
	d = sub_07861D(x, u);
	mem_write8(x + 0x2Du, d >> 8);
	y_2 = sub_03AED3(x);
	unk_48F0 = 3u;
	unk_48F1 = 0u;
	if ((((uint16_t)((uint32_t)(uint8_t)unk_4815 << 8) >> 8) & 1u) != 0u)
	{
		unk_48F0_halfword = 0u - (((uint32_t)unk_48F0 << 8u) | unk_48F1);
		unk_48F0 = (uint8_t)(unk_48F0_halfword >> 8u);
		unk_48F1 = (uint8_t)unk_48F0_halfword;
	}
	t10 = mem_read16(x + 0xFu);
	mem_write16(x + 0xFu, t10 + (((uint32_t)unk_48F0 << 8u) | unk_48F1));
	return y_2;
}

void sub_03AA64(uint16_t x)
{
	sub_03AB20(x);
	sub_03B4FE(x);
}

uint16_t sub_03AA6A(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t d = 0;
	uint16_t d_2 = 0, u = 0;
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) == 0u)
		return y;
	d = 1u;
	sub_07867D(d, &u, &carry);
	d_2 = 0x701u;
	sub_03B51E(x, u, d_2);
	mem_write8(u, 0x80u);
	t2 = mem_read16(x + 0x38u);
	y = t2;
	mem_write16(y + 0x2Au, u);
	mem_write16(u + 0x29u, y);
	mem_write16(x + 4u, 0xD489u);
	t3 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t3 + 1u);
	return y;
}

void sub_03AA92(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) != 0u)
	{
		t2 = mem_read8(x + 0x27u);
		mem_write8(x + 0x27u, t2 | 0x81u);
		mem_write8(x, 0u);
	}
}

uint16_t sub_03AAA4(uint16_t x, uint16_t y)
{
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_03BB14_ADDRESS;
		t1 = mem_read8(x + 0x28u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
		case 4:
			sub_03AB20(x);
			return y;
		case 2:
			return sub_03AAAD(x, y);
		case 6:
			return sub_03AB38(x, y);
		case 8:
		case 22:
			sub_03AC06(x);
			return y;
		case 10:
		case 24:
			sub_03AC1B(x);
			return y;
		case 12:
			return sub_03ABA2(x, y);
		case 14:
		case 28:
			sub_03AC73(x);
			return y;
		case 16:
		case 30:
			sub_03AC81(x);
			return y;
		case 18:
		case 32:
			sub_03AC9F(x);
			return y;
		case 20:
		case 34:
			return sub_03ACBF(x, y);
		case 26:
			return sub_03AC40(x, y);
		case 36:
			return sub_03AD10(x, y, u);
		case 38:
			return sub_03AD2F(x, y);
		case 40:
			sub_03AD44(x);
			return y;
		case 42:
			sub_03AD6B(x);
			return y;
		case 44:
			sub_03AD79(x);
			return y;
		case 46:
			sub_03AD90(x);
			return y;
		case 48:
			sub_03ADA9(x);
			return y;
		case 50:
			return sub_03ADD7(x, y);
		case 52:
			sub_03AE05(x);
			return y;
		case 54:
			sub_03AE28(x);
			return y;
		case 56:
		case 62:
			sub_03AEF3(x);
			return y;
		case 58:
		case 78:
			sub_03AF1E(x);
			return y;
		case 60:
		case 80:
			return sub_03AF41(x, y);
		case 64:
			return sub_03AF50(x, y);
		case 66:
			sub_03AFA0(x);
			return y;
		case 68:
			break;
		case -50:
			return sub_03A9D3(x, y);
		case -48:
			continue;
		case -46:
			return sub_03AB17(x, y);
		case -44:
			return sub_03AB99(x, y);
		case -42:
			return sub_03ABFD(x, y);
		case -40:
			return sub_03AD07(x, y);
		case -38:
			return sub_03AD3B(x, y);
		case -36:
			return sub_03AE41(x, y);
		case -34:
			return sub_03AE74(x, y);
		case -32:
		case -30:
		case -28:
			return sub_03AEB4(x, y);
		case -26:
		case -24:
		case -22:
			return sub_03AEEA(x, y);
		case -20:
			return sub_03AF47(x, y);
		case -18:
			return sub_03AFD8(x, y);
		case -16:
			return sub_03AFE8(x);
		case -14:
			return sub_03B084(x, y);
		case -12:
			return sub_03B12C(x, y);
		case -10:
			sub_03A9DC(x);
			return y;
		case -8:
			return sub_03AA0F(x, y);
		case -6:
			sub_03AA64(x);
			return y;
		case -4:
			return sub_03AA6A(x, y);
		case -2:
			sub_03AA92(x);
			return y;
		}
		break;
	}
	return sub_03AFCA(x, y);
}

uint16_t sub_03AAAD(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d = 0, ignored16 = 0, u = 0, y_2 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) == 0u)
		return y;
	unk_487C++;
	d = 0x300u;
	sub_03AB00(x, &ignored16, &u, &d);
	mem_write16(u + 0xFu, 0x100u);
	d = 0x8300u;
	sub_03AB00(x, &ignored16, &u, &d);
	mem_write16(u + 0xFu, 0xFF00u);
	d = 0x400u;
	sub_03AB00(x, &ignored16, &u, &d);
	a = (uint8_t)(d >> 8);
	mem_write16(u + 0xCu, (uint32_t)a << 8);
	mem_write16(u + 0xFu, 0x100u);
	d = 0x8400u;
	sub_03AB00(x, &y_2, &u, &d);
	mem_write16(u + 0xFu, 0xFF00u);
	t2 = mem_read8(x + 0x34u);
	mem_write8(x + 0x34u, t2 + 1u);
	t3 = mem_read8(x + 0x30u);
	t4 = mem_read8(x + 0x34u);
	a = DATA8(indexed_table_03BB80_ADDRESS + (int8_t)(t3 + t4));
	mem_write8(x + 0x1Bu, a);
	mem_write8(x + VIDEO_002F, a);
	sub_03B590(x);
	u = sub_03B39A(x);
	sub_03B27F(x, u, &y_2, &carry);
	return y_2;
}

void sub_03AB00(uint16_t x, uint16_t *p_y, uint16_t *p_u, uint16_t *p_d)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = 0;
	uint8_t d_2 = 0;
	uint16_t d_3 = 0, u = 0, y = 0;
	uint8_t stack = 0;

	stack = d >> 8;
	d_2 = 1u;
	sub_07867D(d_2, &u, &carry);
	d_3 = 1u | ((uint32_t)stack << 8);
	y = sub_03B51E(x, u, d_3);
	mem_write8(u, 0x88u);
	mem_write16(u + 0x19u, 0x500u);
	d_3 = 0x500u;
	*p_y = y;
	*p_u = u;
	*p_d = d_3;
}

uint16_t sub_03AB17(uint16_t x, uint16_t y)
{
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_03BB18_ADDRESS;
		t1 = mem_read8(x + 0x28u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case -4:
		case 0:
			sub_03AB20(x);
			return y;
		case 2:
			return sub_03AB38(x, y);
		case 4:
		case 18:
			sub_03AC06(x);
			return y;
		case 6:
		case 20:
			sub_03AC1B(x);
			return y;
		case 8:
			return sub_03ABA2(x, y);
		case 10:
		case 24:
			sub_03AC73(x);
			return y;
		case 12:
		case 26:
			sub_03AC81(x);
			return y;
		case 14:
		case 28:
			sub_03AC9F(x);
			return y;
		case 16:
		case 30:
			return sub_03ACBF(x, y);
		case 22:
			return sub_03AC40(x, y);
		case 32:
			return sub_03AD10(x, y, u);
		case 34:
			return sub_03AD2F(x, y);
		case 36:
			sub_03AD44(x);
			return y;
		case 38:
			sub_03AD6B(x);
			return y;
		case 40:
			sub_03AD79(x);
			return y;
		case 42:
			sub_03AD90(x);
			return y;
		case 44:
			sub_03ADA9(x);
			return y;
		case 46:
			return sub_03ADD7(x, y);
		case 48:
			sub_03AE05(x);
			return y;
		case 50:
			sub_03AE28(x);
			return y;
		case 52:
		case 58:
			sub_03AEF3(x);
			return y;
		case 54:
		case 74:
			sub_03AF1E(x);
			return y;
		case 56:
		case 76:
			return sub_03AF41(x, y);
		case 60:
			return sub_03AF50(x, y);
		case 62:
			sub_03AFA0(x);
			return y;
		case 64:
			break;
		case -54:
			return sub_03A9D3(x, y);
		case -52:
			return sub_03AAA4(x, y);
		case -50:
			continue;
		case -48:
			return sub_03AB99(x, y);
		case -46:
			return sub_03ABFD(x, y);
		case -44:
			return sub_03AD07(x, y);
		case -42:
			return sub_03AD3B(x, y);
		case -40:
			return sub_03AE41(x, y);
		case -38:
			return sub_03AE74(x, y);
		case -36:
		case -34:
		case -32:
			return sub_03AEB4(x, y);
		case -30:
		case -28:
		case -26:
			return sub_03AEEA(x, y);
		case -24:
			return sub_03AF47(x, y);
		case -22:
			return sub_03AFD8(x, y);
		case -20:
			return sub_03AFE8(x);
		case -18:
			return sub_03B084(x, y);
		case -16:
			return sub_03B12C(x, y);
		case -14:
			sub_03A9DC(x);
			return y;
		case -12:
			return sub_03AA0F(x, y);
		case -10:
			sub_03AA64(x);
			return y;
		case -8:
			return sub_03AA6A(x, y);
		case -6:
			sub_03AA92(x);
			return y;
		case -2:
			return sub_03AAAD(x, y);
		}
		break;
	}
	return sub_03AFCA(x, y);
}

void sub_03AB20(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x30u);
	t2 = mem_read8(x + 0x34u);
	d = (uint32_t)(uint8_t)(0xAu + t1 + t2) << 8;
	sub_03B2F0(x, d);
	d = 0x6E00u;
	carry = sub_078680(d);
	sub_03B509(x);
	t3 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t3 + 1u);
}

uint16_t sub_03AB38(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d = 0, ignored16 = 0, u = 0, y_2 = 0;
	uint8_t t1 = 0, t2 = 0, t5 = 0, t6 = 0, t7 = 0;
	uint16_t t3 = 0, t4 = 0;

	t1 = mem_read8(x + 6u);
	t2 = t1 & 2u;
	a = t2;
	if (t2 == 0u)
		return y;
	d = (uint32_t)a << 8;
	sub_03AB82(x, d, &ignored16, &u);
	t3 = mem_read16(x + 0xCu);
	t4 = t3 + 0x20u;
	mem_write16(u + 0xCu, t4);
	mem_write16(u + 0xFu, 0x80u);
	d = 0x8280u;
	sub_03AB82(x, d, &ignored16, &u);
	mem_write16(u + 0xFu, 0xFF00u);
	d = 0x200u;
	sub_03AB82(x, d, &y_2, &u);
	mem_write16(u + 0xFu, 0x100u);
	t5 = mem_read8(x + 0x34u);
	mem_write8(x + 0x34u, t5 + 1u);
	t6 = mem_read8(x + 0x30u);
	t7 = mem_read8(x + 0x34u);
	a = DATA8(indexed_table_03BB80_ADDRESS + (int8_t)(t6 + t7));
	mem_write8(x + 0x1Bu, a);
	mem_write8(x + VIDEO_002F, a);
	sub_03B590(x);
	u = sub_03B39A(x);
	sub_03B27F(x, u, &y_2, &carry);
	return y_2;
}

void sub_03AB82(uint16_t x, uint16_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint32_t carry = 0;
	uint8_t d_2 = 0;
	uint16_t d_3 = 0, u = 0, y = 0;
	uint8_t stack = 0;

	stack = d >> 8;
	d_2 = 1u;
	sub_07867D(d_2, &u, &carry);
	d_3 = 1u | ((uint32_t)stack << 8);
	y = sub_03B51E(x, u, d_3);
	mem_write8(u, 0x88u);
	mem_write16(u + 0x19u, 0x500u);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_03AB99(uint16_t x, uint16_t y)
{
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_03BB1C_ADDRESS;
		t1 = mem_read8(x + 0x28u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
		case 14:
			sub_03AC06(x);
			return y;
		case 2:
		case 16:
			sub_03AC1B(x);
			return y;
		case 4:
			return sub_03ABA2(x, y);
		case 6:
		case 20:
			sub_03AC73(x);
			return y;
		case 8:
		case 22:
			sub_03AC81(x);
			return y;
		case 10:
		case 24:
			sub_03AC9F(x);
			return y;
		case 12:
		case 26:
			return sub_03ACBF(x, y);
		case 18:
			return sub_03AC40(x, y);
		case 28:
			return sub_03AD10(x, y, u);
		case 30:
			return sub_03AD2F(x, y);
		case 32:
			sub_03AD44(x);
			return y;
		case 34:
			sub_03AD6B(x);
			return y;
		case 36:
			sub_03AD79(x);
			return y;
		case 38:
			sub_03AD90(x);
			return y;
		case 40:
			sub_03ADA9(x);
			return y;
		case 42:
			return sub_03ADD7(x, y);
		case 44:
			sub_03AE05(x);
			return y;
		case 46:
			sub_03AE28(x);
			return y;
		case 48:
		case 54:
			sub_03AEF3(x);
			return y;
		case 50:
		case 70:
			sub_03AF1E(x);
			return y;
		case 52:
		case 72:
			return sub_03AF41(x, y);
		case 56:
			return sub_03AF50(x, y);
		case 58:
			sub_03AFA0(x);
			return y;
		case 60:
			break;
		case -58:
			return sub_03A9D3(x, y);
		case -56:
			return sub_03AAA4(x, y);
		case -54:
			return sub_03AB17(x, y);
		case -52:
			continue;
		case -50:
			return sub_03ABFD(x, y);
		case -48:
			return sub_03AD07(x, y);
		case -46:
			return sub_03AD3B(x, y);
		case -44:
			return sub_03AE41(x, y);
		case -42:
			return sub_03AE74(x, y);
		case -40:
		case -38:
		case -36:
			return sub_03AEB4(x, y);
		case -34:
		case -32:
		case -30:
			return sub_03AEEA(x, y);
		case -28:
			return sub_03AF47(x, y);
		case -26:
			return sub_03AFD8(x, y);
		case -24:
			return sub_03AFE8(x);
		case -22:
			return sub_03B084(x, y);
		case -20:
			return sub_03B12C(x, y);
		case -18:
			sub_03A9DC(x);
			return y;
		case -16:
			return sub_03AA0F(x, y);
		case -14:
			sub_03AA64(x);
			return y;
		case -12:
			return sub_03AA6A(x, y);
		case -10:
			sub_03AA92(x);
			return y;
		case -8:
		case -4:
			sub_03AB20(x);
			return y;
		case -6:
			return sub_03AAAD(x, y);
		case -2:
			return sub_03AB38(x, y);
		}
		break;
	}
	return sub_03AFCA(x, y);
}

uint16_t sub_03ABA2(uint16_t x, uint16_t y)
{
	uint8_t d = 0;
	uint16_t d_2 = 0, ignored16 = 0, u = 0, y_2 = 0;
	uint8_t t1 = 0, t5 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) == 0u)
	{
		mem_write16(x + 0xFu, 0x300u);
		if ((unk_4815 & 1u) != 0u)
		{
			t2 = mem_read16(x + 0xFu);
			mem_write16(x + 0xFu, 0u - t2);
		}
		return y;
	}
	mem_write16(x + 0xFu, 0u);
	t3 = mem_read16(x + 0x16u);
	t4 = t3 + 0x20u;
	d = (uint8_t)t4;
	mem_write16(x + 0x16u, ((uint32_t)(t4 >> 8) << 8) | (d & 0xFFu));
	d_2 = (d & 0xFFu) | 0x8100u;
	sub_03ABEC(x, d_2, &ignored16, &u);
	mem_write16(u + 0xFu, 0x100u);
	mem_write16(u + 0x14u, rom_07FFC0_ADDRESS);
	mem_write16(u + 0x19u, 0x500u);
	d_2 = 0x100u;
	sub_03ABEC(x, d_2, &y_2, &u);
	mem_write16(u + 0xFu, 0xFF00u);
	mem_write16(u + 0x14u, 0xFFE0u);
	mem_write16(u + 0x19u, 0x300u);
	d_2 = 0x1400u;
	sub_03B2F0(x, d_2);
	t5 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t5 + 1u);
	return y_2;
}

void sub_03ABEC(uint16_t x, uint16_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint32_t carry = 0;
	uint8_t d_2 = 0;
	uint16_t d_3 = 0, u = 0, y = 0;
	uint8_t stack = 0;

	stack = d >> 8;
	d_2 = 1u;
	sub_07867D(d_2, &u, &carry);
	d_3 = 1u | ((uint32_t)stack << 8);
	y = sub_03B51E(x, u, d_3);
	mem_write8(u, 0x80u);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_03ABFD(uint16_t x, uint16_t y)
{
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_03BB2A_ADDRESS;
		t1 = mem_read8(x + 0x28u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case -14:
		case 0:
			sub_03AC06(x);
			return y;
		case -12:
		case 2:
			sub_03AC1B(x);
			return y;
		case 4:
			return sub_03AC40(x, y);
		case -8:
		case 6:
			sub_03AC73(x);
			return y;
		case -6:
		case 8:
			sub_03AC81(x);
			return y;
		case -4:
		case 10:
			sub_03AC9F(x);
			return y;
		case -2:
		case 12:
			return sub_03ACBF(x, y);
		case 14:
			return sub_03AD10(x, y, u);
		case 16:
			return sub_03AD2F(x, y);
		case 18:
			sub_03AD44(x);
			return y;
		case 20:
			sub_03AD6B(x);
			return y;
		case 22:
			sub_03AD79(x);
			return y;
		case 24:
			sub_03AD90(x);
			return y;
		case 26:
			sub_03ADA9(x);
			return y;
		case 28:
			return sub_03ADD7(x, y);
		case 30:
			sub_03AE05(x);
			return y;
		case 32:
			sub_03AE28(x);
			return y;
		case 34:
		case 40:
			sub_03AEF3(x);
			return y;
		case 36:
		case 56:
			sub_03AF1E(x);
			return y;
		case 38:
		case 58:
			return sub_03AF41(x, y);
		case 42:
			return sub_03AF50(x, y);
		case 44:
			sub_03AFA0(x);
			return y;
		case 46:
			break;
		case -72:
			return sub_03A9D3(x, y);
		case -70:
			return sub_03AAA4(x, y);
		case -68:
			return sub_03AB17(x, y);
		case -66:
			return sub_03AB99(x, y);
		case -64:
			continue;
		case -62:
			return sub_03AD07(x, y);
		case -60:
			return sub_03AD3B(x, y);
		case -58:
			return sub_03AE41(x, y);
		case -56:
			return sub_03AE74(x, y);
		case -54:
		case -52:
		case -50:
			return sub_03AEB4(x, y);
		case -48:
		case -46:
		case -44:
			return sub_03AEEA(x, y);
		case -42:
			return sub_03AF47(x, y);
		case -40:
			return sub_03AFD8(x, y);
		case -38:
			return sub_03AFE8(x);
		case -36:
			return sub_03B084(x, y);
		case -34:
			return sub_03B12C(x, y);
		case -32:
			sub_03A9DC(x);
			return y;
		case -30:
			return sub_03AA0F(x, y);
		case -28:
			sub_03AA64(x);
			return y;
		case -26:
			return sub_03AA6A(x, y);
		case -24:
			sub_03AA92(x);
			return y;
		case -22:
		case -18:
			sub_03AB20(x);
			return y;
		case -20:
			return sub_03AAAD(x, y);
		case -16:
			return sub_03AB38(x, y);
		case -10:
			return sub_03ABA2(x, y);
		}
		break;
	}
	return sub_03AFCA(x, y);
}

void sub_03AC06(uint16_t x)
{
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;
	uint16_t t4 = 0;

	t1 = mem_read8(x + 0x30u);
	t2 = mem_read8(x + 0x34u);
	d = (uint32_t)(uint8_t)(t1 + t2) << 8;
	sub_03B2F0(x, d);
	mem_write8(x + 0x29u, 0x40u);
	t3 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t3 + 1u);
	mem_write16(x + 0xFu, 0x300u);
	if ((unk_4815 & 1u) != 0u)
	{
		t4 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t4);
	}
}

void sub_03AC1B(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 - 1u);
	if (t1 != 1u)
	{
		mem_write16(x + 0xFu, 0x300u);
		if ((unk_4815 & 1u) != 0u)
		{
			t2 = mem_read16(x + 0xFu);
			mem_write16(x + 0xFu, 0u - t2);
		}
		return;
	}
	t3 = mem_read8(x + 0x30u);
	if (t3 != 1u)
		unk_487C++;
	d = 0x6E00u;
	carry = sub_078680(d);
	t4 = mem_read8(x + 0x30u);
	t5 = mem_read8(x + 0x34u);
	d = (uint32_t)(uint8_t)(0xAu + t4 + t5) << 8;
	sub_03B2F0(x, d);
	t6 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t6 + 1u);
}

uint16_t sub_03AC40(uint16_t x, uint16_t y)
{
	uint16_t d = 0, ignored16 = 0, u = 0, y_2 = 0;
	uint8_t t1 = 0, t5 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) == 0u)
	{
		mem_write16(x + 0xFu, 0x300u);
		if ((unk_4815 & 1u) != 0u)
		{
			t2 = mem_read16(x + 0xFu);
			mem_write16(x + 0xFu, 0u - t2);
		}
		return y;
	}
	mem_write16(x + 0xFu, 0u);
	t3 = mem_read16(x + 0x16u);
	t4 = t3 + 0x20u;
	d = t4;
	mem_write16(x + 0x16u, ((uint32_t)(t4 >> 8) << 8) | (d & 0xFFu));
	d &= 0xFFu;
	sub_03ACF0(x, d, &ignored16, &u);
	mem_write16(u + 0xFu, 0x100u);
	d = loaded_table_078000_ADDRESS;
	sub_03ACF0(x, d, &y_2, &u);
	mem_write16(u + 0xFu, 0xFF00u);
	d = 0x1400u;
	sub_03B2F0(x, d);
	t5 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t5 + 1u);
	return y_2;
}

void sub_03AC73(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;
	uint8_t t1 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry)
	{
		mem_write8(x + 0x29u, 0x80u);
		t1 = mem_read8(x + 0x28u);
		mem_write8(x + 0x28u, t1 + 1u);
	}
}

void sub_03AC81(uint16_t x)
{
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 - 1u);
	if (t1 != 1u)
		return;
	t2 = mem_read8(x + 0x30u);
	if (t2 != 1u)
		unk_487C++;
	t3 = mem_read8(x + 0x30u);
	t4 = mem_read8(x + 0x34u);
	d = (uint32_t)(uint8_t)(0x15u + t3 + t4) << 8;
	sub_03B2F0(x, d);
	t5 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t5 + 1u);
}

void sub_03AC9F(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) == 0u)
		return;
	t2 = mem_read8(x + 0x30u);
	mem_write8(x + 0x30u, t2 + 1u);
	t3 = mem_read8(x + 0x30u);
	d = (uint32_t)t3 << 8;
	sub_03B2F0(x, d);
	d = 0x3F35u;
	carry = sub_078680(d);
	mem_write8(x + 0x29u, 0x40u);
	t4 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t4 + 1u);
}

uint16_t sub_03ACBF(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t u = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 - 1u);
	if (t1 != 1u)
		return y;
	t2 = mem_read8(x + 0x30u);
	t3 = mem_read8(x + 0x34u);
	a = DATA8(indexed_table_03BB80_ADDRESS + (int8_t)(t2 + t3));
	mem_write8(x + 0x1Bu, a);
	mem_write8(x + VIDEO_002F, a);
	sub_03B590(x);
	u = sub_03B39A(x);
	sub_03B27F(x, u, &y, &carry);
	return y;
}

void sub_03ACF0(uint16_t x, uint16_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint32_t carry = 0;
	uint8_t d_2 = 0;
	uint16_t d_3 = 0, u = 0, y = 0;
	uint8_t stack = 0;

	stack = d >> 8;
	d_2 = 1u;
	sub_07867D(d_2, &u, &carry);
	d_3 = 1u | ((uint32_t)stack << 8);
	y = sub_03B51E(x, u, d_3);
	mem_write8(u, 0x88u);
	mem_write16(u + 0x19u, 0x500u);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_03AD07(uint16_t x, uint16_t y)
{
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_03BB38_ADDRESS;
		t1 = mem_read8(x + 0x28u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			return sub_03AD10(x, y, u);
		case 2:
			return sub_03AD2F(x, y);
		case 4:
			sub_03AD44(x);
			return y;
		case 6:
			sub_03AD6B(x);
			return y;
		case 8:
			sub_03AD79(x);
			return y;
		case 10:
			sub_03AD90(x);
			return y;
		case 12:
			sub_03ADA9(x);
			return y;
		case 14:
			return sub_03ADD7(x, y);
		case 16:
			sub_03AE05(x);
			return y;
		case 18:
			sub_03AE28(x);
			return y;
		case 20:
		case 26:
			sub_03AEF3(x);
			return y;
		case 22:
		case 42:
			sub_03AF1E(x);
			return y;
		case 24:
		case 44:
			return sub_03AF41(x, y);
		case 28:
			return sub_03AF50(x, y);
		case 30:
			sub_03AFA0(x);
			return y;
		case 32:
			break;
		case -86:
			return sub_03A9D3(x, y);
		case -84:
			return sub_03AAA4(x, y);
		case -82:
			return sub_03AB17(x, y);
		case -80:
			return sub_03AB99(x, y);
		case -78:
			return sub_03ABFD(x, y);
		case -76:
			continue;
		case -74:
			return sub_03AD3B(x, y);
		case -72:
			return sub_03AE41(x, y);
		case -70:
			return sub_03AE74(x, y);
		case -68:
		case -66:
		case -64:
			return sub_03AEB4(x, y);
		case -62:
		case -60:
		case -58:
			return sub_03AEEA(x, y);
		case -56:
			return sub_03AF47(x, y);
		case -54:
			return sub_03AFD8(x, y);
		case -52:
			return sub_03AFE8(x);
		case -50:
			return sub_03B084(x, y);
		case -48:
			return sub_03B12C(x, y);
		case -46:
			sub_03A9DC(x);
			return y;
		case -44:
			return sub_03AA0F(x, y);
		case -42:
			sub_03AA64(x);
			return y;
		case -40:
			return sub_03AA6A(x, y);
		case -38:
			sub_03AA92(x);
			return y;
		case -36:
		case -32:
			sub_03AB20(x);
			return y;
		case -34:
			return sub_03AAAD(x, y);
		case -30:
			return sub_03AB38(x, y);
		case -28:
		case -14:
			sub_03AC06(x);
			return y;
		case -26:
		case -12:
			sub_03AC1B(x);
			return y;
		case -24:
			return sub_03ABA2(x, y);
		case -22:
		case -8:
			sub_03AC73(x);
			return y;
		case -20:
		case -6:
			sub_03AC81(x);
			return y;
		case -18:
		case -4:
			sub_03AC9F(x);
			return y;
		case -16:
		case -2:
			return sub_03ACBF(x, y);
		case -10:
			return sub_03AC40(x, y);
		}
		break;
	}
	return sub_03AFCA(x, y);
}

uint16_t sub_03AD10(uint16_t x, uint16_t y, uint16_t u)
{
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	unk_487E = 2u;
	d = 0x3Fu;
	sub_078677(d, &y, &u);
	t1 = mem_read8(x + 0x30u);
	t2 = mem_read8(x + 0x34u);
	d = 0x3Fu | ((uint32_t)(uint8_t)(0x17u + t1 + t2) << 8);
	sub_03B2F0(x, d);
	mem_write8(x + 0x29u, 0x10u);
	t3 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t3 + 1u);
	return y;
}

uint16_t sub_03AD2F(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t u = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 - 1u);
	if (t1 != 1u)
		return y;
	u = sub_03B39A(x);
	sub_03B27F(x, u, &y, &carry);
	return y;
}

uint16_t sub_03AD3B(uint16_t x, uint16_t y)
{
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_03BB3C_ADDRESS;
		t1 = mem_read8(x + 0x28u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			sub_03AD44(x);
			return y;
		case 2:
			sub_03AD6B(x);
			return y;
		case 4:
			sub_03AD79(x);
			return y;
		case 6:
			sub_03AD90(x);
			return y;
		case 8:
			sub_03ADA9(x);
			return y;
		case 10:
			return sub_03ADD7(x, y);
		case 12:
			sub_03AE05(x);
			return y;
		case 14:
			sub_03AE28(x);
			return y;
		case 16:
		case 22:
			sub_03AEF3(x);
			return y;
		case 18:
		case 38:
			sub_03AF1E(x);
			return y;
		case 20:
		case 40:
			return sub_03AF41(x, y);
		case 24:
			return sub_03AF50(x, y);
		case 26:
			sub_03AFA0(x);
			return y;
		case 28:
			break;
		case -90:
			return sub_03A9D3(x, y);
		case -88:
			return sub_03AAA4(x, y);
		case -86:
			return sub_03AB17(x, y);
		case -84:
			return sub_03AB99(x, y);
		case -82:
			return sub_03ABFD(x, y);
		case -80:
			return sub_03AD07(x, y);
		case -78:
			continue;
		case -76:
			return sub_03AE41(x, y);
		case -74:
			return sub_03AE74(x, y);
		case -72:
		case -70:
		case -68:
			return sub_03AEB4(x, y);
		case -66:
		case -64:
		case -62:
			return sub_03AEEA(x, y);
		case -60:
			return sub_03AF47(x, y);
		case -58:
			return sub_03AFD8(x, y);
		case -56:
			return sub_03AFE8(x);
		case -54:
			return sub_03B084(x, y);
		case -52:
			return sub_03B12C(x, y);
		case -50:
			sub_03A9DC(x);
			return y;
		case -48:
			return sub_03AA0F(x, y);
		case -46:
			sub_03AA64(x);
			return y;
		case -44:
			return sub_03AA6A(x, y);
		case -42:
			sub_03AA92(x);
			return y;
		case -40:
		case -36:
			sub_03AB20(x);
			return y;
		case -38:
			return sub_03AAAD(x, y);
		case -34:
			return sub_03AB38(x, y);
		case -32:
		case -18:
			sub_03AC06(x);
			return y;
		case -30:
		case -16:
			sub_03AC1B(x);
			return y;
		case -28:
			return sub_03ABA2(x, y);
		case -26:
		case -12:
			sub_03AC73(x);
			return y;
		case -24:
		case -10:
			sub_03AC81(x);
			return y;
		case -22:
		case -8:
			sub_03AC9F(x);
			return y;
		case -20:
		case -6:
			return sub_03ACBF(x, y);
		case -14:
			return sub_03AC40(x, y);
		case -4:
			return sub_03AD10(x, y, u);
		case -2:
			return sub_03AD2F(x, y);
		}
		break;
	}
	return sub_03AFCA(x, y);
}

void sub_03AD44(uint16_t x)
{
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0;

	io_write16(VIDEO_1854, x);
	mem_write8(x + 0x5Bu, 1u);
	t1 = 0x420u - unk_48AC;
	mem_write16(x + 0xCu, t1);
	t2 = 0xE8u + unk_48B2;
	mem_write16(x + 0x11u, t2);
	mem_write8(x + 0x1Bu, 0xA0u);
	mem_write8(x + VIDEO_002F, 0xA0u);
	t3 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t3 + 1u);
}

void sub_03AD6B(uint16_t x)
{
	uint8_t t1 = 0;

	if (unk_4881 != 0u)
	{
		mem_write8(x + 0x29u, 0x20u);
		t1 = mem_read8(x + 0x28u);
		mem_write8(x + 0x28u, t1 + 1u);
	}
}

void sub_03AD79(uint16_t x)
{
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(x, 0x80u);
	d = 0x3200u;
	d = sub_03B2F0(x, d);
	d &= 0xFFu;
	sub_03B2FF(x, d);
	t2 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t2 + 1u);
}

void sub_03AD90(uint16_t x)
{
	uint8_t t1 = 0, t4 = 0;
	uint16_t t2 = 0, t3 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) == 0u)
	{
		t2 = mem_read16(x + 0x11u);
		t3 = t2 - 0x10u;
		mem_write16(x + 0x11u, t3);
		mem_write8(x + 0x29u, 0x40u);
		t4 = mem_read8(x + 0x28u);
		mem_write8(x + 0x28u, t4 + 1u);
	}
}

void sub_03ADA9(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t d = 0;
	uint16_t d_2 = 0, u = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 - 1u);
	if (t1 != 1u)
		return;
	d = 2u;
	sub_07867D(d, &u, &carry);
	if (carry)
	{
		mem_write8(u + 1u, 0x29u);
		mem_write16(u + 4u, 0xB083u);
		mem_write8(u + 0x28u, 0x80u);
		mem_write16(u + 0x29u, x);
	}
	d_2 = 0x3F36u;
	carry = sub_078680(d_2);
	d_2 = 0x3336u;
	sub_03B2F0(x, d_2);
	t2 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t2 + 1u);
}

uint16_t sub_03ADD7(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t d = 0;
	uint16_t d_2 = 0, u = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) == 0u)
		return y;
	d = 1u;
	sub_07867D(d, &u, &carry);
	if (carry)
	{
		d_2 = 0x801u;
		y = sub_03B51E(x, u, d_2);
		mem_write8(u, 0x80u);
		mem_write8(u + 0xAu, 0x40u);
		mem_write8(u + 0xBu, 0x40u);
		mem_write8(x + 0x29u, 0x40u);
		d_2 = 0x301u;
		carry = sub_078680(d_2);
	}
	t2 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t2 + 1u);
	return y;
}

void sub_03AE05(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 - 1u);
	if (t1 != 1u)
		return;
	d = 0x1400u;
	carry = sub_078680(d);
	unk_487C = 1u;
	d = 0x3400u;
	d = sub_03B2F0(x, d);
	a = (uint8_t)(d >> 8);
	t2 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t2 + 1u);
	unk_4804++;
	unk_4805 = ((uint32_t)a << 8) | (d & 0xFFu);
}

void sub_03AE28(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) == 0u)
		return;
	sub_03B590(x);
	mem_write8(x, mem_read8(x) | 0x40u);
	mem_write8(x + 0x28u, 0u);
	mem_write8(x + 2u, 1u);
}

uint16_t sub_03AE41(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t d = 0, u = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	sub_03B176(x, &y, &u, &carry);
	if (carry)
		return y;
	sub_03B27F(x, u, &y, &carry);
	if (carry)
		return y;
	t1 = mem_read8(x + 5u);
	if (t1 != 4u)
	{
		t2 = mem_read8(x + 0x30u);
		d = (uint32_t)(uint8_t)(5u + t2) << 8;
		sub_03B2F0(x, d);
	}
	sub_03B2A6(x);
	t3 = mem_read8(x + 0x2Du);
	mem_write8(x + VIDEO_0031, t3);
	y = sub_03B263(x);
	t4 = mem_read8(x + 6u);
	if ((t4 & 2u) != 0u)
	{
		d = unk_5A00_ADDRESS;
		carry = sub_078680(d);
	}
	return y;
}

uint16_t sub_03AE74(uint16_t x, uint16_t y)
{
	uint32_t negative = 0, carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, u = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	sub_03B1B5(x, &y, &u, &carry);
	if (carry)
		return y;
	sub_03B27F(x, u, &y, &carry);
	if (carry)
		return y;
	if ((unk_4815 & 0x3Fu) == 0u)
	{
		d = 0x1300u;
		carry = sub_078680(d);
	}
	t1 = mem_read8(x + 5u);
	if (t1 != 0u)
	{
		t2 = mem_read8(x + 0x30u);
		d = (uint32_t)(uint8_t)(5u + t2) << 8;
		sub_03B2F0(x, d);
	}
	sub_03B2A6(x);
	a = 1u;
	t3 = mem_read8(x + 0x2Du);
	b = t3;
	t4 = mem_read8(x + VIDEO_0031);
	negative = (uint8_t)(b - t4) >> 7;
	if (b == t4)
	{
		y = sub_03B263(x);
		return y;
	}
	if (negative)
		a = 0u - a;
	t5 = mem_read8(x + VIDEO_0031);
	mem_write8(x + VIDEO_0031, a + t5);
	y = sub_03B263(x);
	return y;
}

uint16_t sub_03AEB4(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t d = 0, u = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	sub_03B1FF(x, &y, &u, &carry);
	if (carry)
		return y;
	sub_03B27F(x, u, &y, &carry);
	if (carry)
		return y;
	t1 = mem_read8(x + 5u);
	if (t1 != 1u)
	{
		t2 = mem_read8(x + 0x30u);
		t3 = mem_read8(x + 0x34u);
		d = (uint32_t)(uint8_t)(5u + t2 + t3) << 8;
		sub_03B2F0(x, d);
	}
	sub_03B2A6(x);
	return sub_03AED3(x);
}

uint16_t sub_03AED3(uint16_t x)
{
	uint32_t negative = 0;
	uint8_t a = 0, b = 0;
	uint16_t y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	a = 3u;
	t1 = mem_read8(x + 0x2Du);
	b = t1;
	t2 = mem_read8(x + VIDEO_0031);
	negative = (uint8_t)(b - t2) >> 7;
	if (b == t2)
	{
		y = sub_03B263(x);
		return y;
	}
	if (negative)
		a = 0u - a;
	t3 = mem_read8(x + VIDEO_0031);
	mem_write8(x + VIDEO_0031, a + t3);
	y = sub_03B263(x);
	return y;
}

uint16_t sub_03AEEA(uint16_t x, uint16_t y)
{
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_03BB4C_ADDRESS;
		t1 = mem_read8(x + 0x28u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
		case 6:
			sub_03AEF3(x);
			return y;
		case 2:
		case 22:
			sub_03AF1E(x);
			return y;
		case 4:
		case 24:
			return sub_03AF41(x, y);
		case 8:
			return sub_03AF50(x, y);
		case 10:
			sub_03AFA0(x);
			return y;
		case 12:
			break;
		case -106:
			return sub_03A9D3(x, y);
		case -104:
			return sub_03AAA4(x, y);
		case -102:
			return sub_03AB17(x, y);
		case -100:
			return sub_03AB99(x, y);
		case -98:
			return sub_03ABFD(x, y);
		case -96:
			return sub_03AD07(x, y);
		case -94:
			return sub_03AD3B(x, y);
		case -92:
			return sub_03AE41(x, y);
		case -90:
			return sub_03AE74(x, y);
		case -88:
		case -86:
		case -84:
			return sub_03AEB4(x, y);
		case -82:
		case -80:
		case -78:
			continue;
		case -76:
			return sub_03AF47(x, y);
		case -74:
			return sub_03AFD8(x, y);
		case -72:
			return sub_03AFE8(x);
		case -70:
			return sub_03B084(x, y);
		case -68:
			return sub_03B12C(x, y);
		case -66:
			sub_03A9DC(x);
			return y;
		case -64:
			return sub_03AA0F(x, y);
		case -62:
			sub_03AA64(x);
			return y;
		case -60:
			return sub_03AA6A(x, y);
		case -58:
			sub_03AA92(x);
			return y;
		case -56:
		case -52:
			sub_03AB20(x);
			return y;
		case -54:
			return sub_03AAAD(x, y);
		case -50:
			return sub_03AB38(x, y);
		case -48:
		case -34:
			sub_03AC06(x);
			return y;
		case -46:
		case -32:
			sub_03AC1B(x);
			return y;
		case -44:
			return sub_03ABA2(x, y);
		case -42:
		case -28:
			sub_03AC73(x);
			return y;
		case -40:
		case -26:
			sub_03AC81(x);
			return y;
		case -38:
		case -24:
			sub_03AC9F(x);
			return y;
		case -36:
		case -22:
			return sub_03ACBF(x, y);
		case -30:
			return sub_03AC40(x, y);
		case -20:
			return sub_03AD10(x, y, u);
		case -18:
			return sub_03AD2F(x, y);
		case -16:
			sub_03AD44(x);
			return y;
		case -14:
			sub_03AD6B(x);
			return y;
		case -12:
			sub_03AD79(x);
			return y;
		case -10:
			sub_03AD90(x);
			return y;
		case -8:
			sub_03ADA9(x);
			return y;
		case -6:
			return sub_03ADD7(x, y);
		case -4:
			sub_03AE05(x);
			return y;
		case -2:
			sub_03AE28(x);
			return y;
		}
		break;
	}
	return sub_03AFCA(x, y);
}

void sub_03AEF3(uint16_t x)
{
	sub_03B4FE(x);
	sub_03AEF6(x);
}

void sub_03AEF6(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;

	t1 = mem_read8(x + 0x29u);
	if (t1 != 0u)
	{
		t2 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t2 - 1u);
		return;
	}
	d = 0x7D00u;
	carry = sub_078680(d);
	mem_write8(x, mem_read8(x) | 4u);
	t3 = mem_read8(x + 0x30u);
	t4 = mem_read8(x + 0x34u);
	t5 = mem_read8(x + 0x35u);
	d = (uint32_t)(uint8_t)(((uint32_t)(t3 + t4) << 1) + 0x26u + t5) << 8;
	sub_03B2F0(x, d);
	t6 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t6 + 1u);
}

void sub_03AF1E(uint16_t x)
{
	uint8_t a = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) != 0u)
	{
		t2 = mem_read8(x + 0x28u);
		mem_write8(x + 0x28u, t2 + 1u);
		return;
	}
	a = 0u;
	t3 = mem_read8(x + 6u);
	if ((t3 & 2u) != 0u)
	{
		t4 = mem_read8(x + 0x30u);
		t5 = mem_read8(x + 0x34u);
		t6 = mem_read8(x + 0x35u);
		a = ((uint32_t)(t4 + t5) << 1) + t6 + 3u;
	}
	d = (uint32_t)a << 8;
	sub_03B2FF(x, d);
}

uint16_t sub_03AF41(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t u = 0;

	u = sub_03B39A(x);
	sub_03B27F(x, u, &y, &carry);
	return y;
}

uint16_t sub_03AF47(uint16_t x, uint16_t y)
{
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_03BB52_ADDRESS;
		t1 = mem_read8(x + 0x28u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case -6:
		case 0:
			sub_03AEF3(x);
			return y;
		case 2:
			return sub_03AF50(x, y);
		case 4:
			sub_03AFA0(x);
			return y;
		case 6:
			break;
		case -4:
		case 16:
			sub_03AF1E(x);
			return y;
		case -2:
		case 18:
			return sub_03AF41(x, y);
		case -112:
			return sub_03A9D3(x, y);
		case -110:
			return sub_03AAA4(x, y);
		case -108:
			return sub_03AB17(x, y);
		case -106:
			return sub_03AB99(x, y);
		case -104:
			return sub_03ABFD(x, y);
		case -102:
			return sub_03AD07(x, y);
		case -100:
			return sub_03AD3B(x, y);
		case -98:
			return sub_03AE41(x, y);
		case -96:
			return sub_03AE74(x, y);
		case -94:
		case -92:
		case -90:
			return sub_03AEB4(x, y);
		case -88:
		case -86:
		case -84:
			return sub_03AEEA(x, y);
		case -82:
			continue;
		case -80:
			return sub_03AFD8(x, y);
		case -78:
			return sub_03AFE8(x);
		case -76:
			return sub_03B084(x, y);
		case -74:
			return sub_03B12C(x, y);
		case -72:
			sub_03A9DC(x);
			return y;
		case -70:
			return sub_03AA0F(x, y);
		case -68:
			sub_03AA64(x);
			return y;
		case -66:
			return sub_03AA6A(x, y);
		case -64:
			sub_03AA92(x);
			return y;
		case -62:
		case -58:
			sub_03AB20(x);
			return y;
		case -60:
			return sub_03AAAD(x, y);
		case -56:
			return sub_03AB38(x, y);
		case -54:
		case -40:
			sub_03AC06(x);
			return y;
		case -52:
		case -38:
			sub_03AC1B(x);
			return y;
		case -50:
			return sub_03ABA2(x, y);
		case -48:
		case -34:
			sub_03AC73(x);
			return y;
		case -46:
		case -32:
			sub_03AC81(x);
			return y;
		case -44:
		case -30:
			sub_03AC9F(x);
			return y;
		case -42:
		case -28:
			return sub_03ACBF(x, y);
		case -36:
			return sub_03AC40(x, y);
		case -26:
			return sub_03AD10(x, y, u);
		case -24:
			return sub_03AD2F(x, y);
		case -22:
			sub_03AD44(x);
			return y;
		case -20:
			sub_03AD6B(x);
			return y;
		case -18:
			sub_03AD79(x);
			return y;
		case -16:
			sub_03AD90(x);
			return y;
		case -14:
			sub_03ADA9(x);
			return y;
		case -12:
			return sub_03ADD7(x, y);
		case -10:
			sub_03AE05(x);
			return y;
		case -8:
			sub_03AE28(x);
			return y;
		}
		break;
	}
	return sub_03AFCA(x, y);
}

uint16_t sub_03AF50(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0, d = 0;
	uint16_t d_2 = 0, u = 0, x_2 = 0;
	uint16_t stack = 0;
	uint8_t t1 = 0, t2 = 0, t4 = 0;
	uint16_t t3 = 0;
	uint32_t unk_48F0_halfword = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) == 0u)
		return y;
	d = 2u;
	sub_07867D(d, &u, &carry);
	if (carry == 0u)
	{
		sub_03B39A(x);
		return y;
	}
	mem_write8(u, 0x88u);
	mem_write8(u + 0x29u, 0x10u);
	unk_48F0 = 5u;
	unk_48F1 = 0u;
	a = 5u;
	t2 = mem_read8(x + 9u);
	b = t2 & 0x40u;
	mem_write8(u + 9u, b);
	if (b != 0u)
	{
		a -= 0x80u;
		unk_48F0_halfword = 0u - (((uint32_t)unk_48F0 << 8u) | unk_48F1);
		unk_48F0 = (uint8_t)(unk_48F0_halfword >> 8u);
		unk_48F1 = (uint8_t)unk_48F0_halfword;
	}
	d_2 = 2u | ((a | 5u) << 8);
	y = sub_03B51E(x, u, d_2);
	d_2 = VIDEO_1D00;
	carry = sub_078680(d_2);
	t3 = (((uint32_t)unk_48F0 << 8u) | unk_48F1);
	mem_write16(u + 0xFu, t3);
	stack = x;
	x_2 = u;
	d_2 = 0xF00u;
	sub_03B2FF(x_2, d_2);
	x_2 = stack;
	t4 = mem_read8(x_2 + 0x28u);
	mem_write8(x_2 + 0x28u, t4 + 1u);
	return y;
}

void sub_03AFA0(uint16_t x)
{
	uint8_t a = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) == 0u)
		return;
	a = unk_4857 - 1u;
	t2 = mem_read8(x + 0x40u);
	mem_write8(x + 0x40u, t2 + 1u);
	t3 = mem_read8(x + 0x40u);
	if (t3 < DATA8(indexed_table_03BB5A_ADDRESS + (int8_t)a))
	{
		mem_write8(x + 5u, 0x8Eu);
		t4 = mem_read8(x + 0x28u);
		mem_write8(x + 0x28u, t4 - 1u);
		return;
	}
	mem_write8(x + 5u, 0x8Cu);
	t5 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t5 + 1u);
}

uint16_t sub_03AFCA(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t u = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) == 0u)
		return y;
	u = sub_03B39A(x);
	sub_03B27F(x, u, &y, &carry);
	return y;
}

uint16_t sub_03AFD8(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x28u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_03AFE1(x);
		return y;
	case 2:
		sub_03AEF6(x);
		return y;
	case -16:
	case 4:
		sub_03AF1E(x);
		return y;
	case -14:
	case 6:
		return sub_03AF41(x, y);
	case 8:
		sub_03AFF4(x);
		return y;
	case 10:
		sub_03B009(x);
		return y;
	case 12:
		return sub_03B022(x, y);
	case 14:
		return sub_03B066(x, y);
	case 16:
		sub_03B08D(x);
		return y;
	case 18:
		return sub_03B0A7(x, y);
	case 20:
		sub_03B0EF(x);
		return y;
	case 22:
		return sub_03B106(x, y);
	}
	unreachable();
}

void sub_03AFE1(uint16_t x)
{
	uint8_t t1 = 0;

	sub_03B509(x);
	t1 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t1 + 1u);
}

uint16_t sub_03AFE8(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x28u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_03AFF4(x);
		break;
	case 2:
		sub_03B009(x);
		break;
	case 4:
		sub_03B022(x, 0u);
		break;
	case 6:
		sub_03B066(x, 0u);
		break;
	case 8:
		sub_03B08D(x);
		break;
	case 10:
		sub_03B0A7(x, 0u);
		break;
	case 12:
		sub_03B0EF(x);
		break;
	case 14:
		sub_03B106(x, 0u);
		break;
	case -24:
	case -4:
		sub_03AF1E(x);
		break;
	case -22:
	case -2:
		sub_03AF41(x, 0u);
		break;
	case -8:
		sub_03AFE1(x);
		break;
	case -6:
		sub_03AEF6(x);
		break;
	}
	sub_03B2A6(x);
	return sub_03AED3(x);
}

void sub_03AFF4(uint16_t x)
{
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x30u);
	t2 = mem_read8(x + 0x34u);
	d = (uint32_t)(uint8_t)(((uint32_t)(t1 + t2) << 1) + 0x27u) << 8;
	sub_03B2F0(x, d);
	mem_write8(x + 0x29u, 0x20u);
	t3 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t3 + 1u);
}

void sub_03B009(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) == 0u)
		return;
	d = 0x1100u;
	carry = sub_078680(d);
	t2 = mem_read8(x + 0x34u);
	d = (uint32_t)(uint8_t)(0x30u + t2) << 8;
	sub_03B2F0(x, d);
	t3 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t3 + 1u);
}

uint16_t sub_03B022(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t a = 0, d = 0;
	uint16_t d_2 = 0, u = 0, x_2 = 0;
	uint16_t stack = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) == 0u)
		return y;
	mem_write8(x, mem_read8(x) & ~4u);
	d = 0u;
	sub_07867D(d, &u, &carry);
	if (carry == 0u)
	{
		mem_write8(u, 0xC0u);
		mem_write16(u + 0x29u, x);
		mem_write16(x + 0x44u, u);
		stack = x;
		x_2 = u;
		d_2 = 0x1000u;
		sub_03B2FF(x_2, d_2);
		x_2 = stack;
		mem_write8(x_2 + 0x29u, 0x40u);
		mem_write8(x_2 + 0x43u, 1u);
		t2 = mem_read8(x_2 + 0x28u);
		mem_write8(x_2 + 0x28u, t2 + 1u);
		return y;
	}
	a = 0xEu;
	t3 = mem_read8(x + 9u);
	if ((t3 & 0x40u) != 0u)
		a -= 0x80u;
	d_2 = (uint32_t)a << 8;
	y = sub_03B51E(x, u, d_2);
	mem_write8(u, 0xC0u);
	mem_write16(u + 0x29u, x);
	mem_write16(x + 0x44u, u);
	stack = x;
	x_2 = u;
	d_2 = 0x1000u;
	sub_03B2FF(x_2, d_2);
	x_2 = stack;
	mem_write8(x_2 + 0x29u, 0x40u);
	mem_write8(x_2 + 0x43u, 1u);
	t2 = mem_read8(x_2 + 0x28u);
	mem_write8(x_2 + 0x28u, t2 + 1u);
	return y;
}

uint16_t sub_03B066(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t u = 0;
	uint8_t t4 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read16(x + 0x44u);
	u = t1;
	t2 = mem_read16(x + 0xFu);
	mem_write16(u + 0xFu, t2);
	t3 = mem_read16(x + 0x14u);
	mem_write16(u + 0x14u, t3);
	t4 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t4 - 1u);
	if (t4 != 1u)
		return y;
	mem_write8(x + 0x43u, 0u);
	u = sub_03B39A(x);
	sub_03B27F(x, u, &y, &carry);
	return y;
}

uint16_t sub_03B084(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x28u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_03B08D(x);
		return y;
	case 2:
		return sub_03B0A7(x, y);
	case 4:
		sub_03B0EF(x);
		return y;
	case 6:
		return sub_03B106(x, y);
	case -32:
	case -12:
		sub_03AF1E(x);
		return y;
	case -30:
	case -10:
		return sub_03AF41(x, y);
	case -16:
		sub_03AFE1(x);
		return y;
	case -14:
		sub_03AEF6(x);
		return y;
	case -8:
		sub_03AFF4(x);
		return y;
	case -6:
		sub_03B009(x);
		return y;
	case -4:
		return sub_03B022(x, y);
	case -2:
		return sub_03B066(x, y);
	}
	unreachable();
}

void sub_03B08D(uint16_t x)
{
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = mem_read8(x + 0x30u);
	t2 = mem_read8(x + 0x34u);
	d = (uint32_t)(uint8_t)(((uint32_t)(t1 + t2) << 1) + 0x1Cu) << 8;
	sub_03B2F0(x, d);
	t3 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t3 + 1u);
	t4 = mem_read8(x + 0x30u);
	if (t4 == 2u)
	{
		sub_03B509(x);
		return;
	}
	sub_03B4FE(x);
}

uint16_t sub_03B0A7(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0, d = 0;
	uint16_t d_2 = 0, u = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t7 = 0;
	uint16_t t6 = 0, t8 = 0;
	uint32_t unk_48F2_halfword = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) == 0u)
		return y;
	d = 2u;
	sub_07867D(d, &u, &carry);
	if (carry == 0u)
	{
		t2 = mem_read8(x + 0x28u);
		mem_write8(x + 0x28u, t2 + 1u);
		return y;
	}
	mem_write8(u, 0xC8u);
	unk_48F2 = 2u;
	unk_48F3 = 0u;
	a = 9u;
	t3 = mem_read8(x + 9u);
	b = t3 & 0x40u;
	mem_write8(u + 9u, b);
	if (b != 0u)
	{
		a -= 0x80u;
		unk_48F2_halfword = 0u - (((uint32_t)unk_48F2 << 8u) | unk_48F3);
		unk_48F2 = (uint8_t)(unk_48F2_halfword >> 8u);
		unk_48F3 = (uint8_t)unk_48F2_halfword;
	}
	t4 = mem_read8(x + 0x30u);
	t5 = mem_read8(x + 0x34u);
	d_2 = 2u | ((uint32_t)(uint8_t)(a + t4 + t5) << 8);
	sub_03B51E(x, u, d_2);
	t6 = (((uint32_t)unk_48F2 << 8u) | unk_48F3);
	mem_write16(u + 0xFu, t6);
	y = indexed_table_03BB76_ADDRESS;
	t7 = mem_read8(x + 0x3Du);
	t8 = DATA16(indexed_table_03BB76_ADDRESS + (int8_t)((uint32_t)t7 << 1));
	mem_write16(u + 0x14u, t8);
	t2 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t2 + 1u);
	return y;
}

void sub_03B0EF(uint16_t x)
{
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) == 0u)
		return;
	t2 = mem_read8(x + 0x30u);
	t3 = mem_read8(x + 0x34u);
	d = (uint32_t)(uint8_t)(((uint32_t)(t2 + t3) << 1) + 0x1Du) << 8;
	sub_03B2F0(x, d);
	t4 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t4 + 1u);
}

uint16_t sub_03B106(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t u = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) == 0u)
		return y;
	t2 = mem_read8(x + 0x30u);
	t3 = mem_read8(x + 0x34u);
	if ((uint8_t)(t2 + t3) == 4u)
	{
		t4 = mem_read8(x + 0x3Du);
		mem_write8(x + 0x3Du, t4 + 1u);
		t5 = mem_read8(x + 0x3Du);
		if ((int8_t)t5 < 3)
		{
			mem_write8(x + 0x28u, 0u);
			return y;
		}
	}
	u = sub_03B39A(x);
	sub_03B27F(x, u, &y, &carry);
	return y;
}

uint16_t sub_03B12C(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x28u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_03B135(x);
		return y;
	case 2:
		return sub_03B155(x, y);
	}
	unreachable();
}

void sub_03B135(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x30u);
	if (t1 != 2u)
		sub_03B4FE(x);
	sub_078686(x, &ignored16, &ignored16_2, &carry);
	if (carry)
	{
		mem_write8(x, mem_read8(x) | 0x40u);
		mem_write8(x + 0x29u, 0x20u);
		t2 = mem_read8(x + 0x28u);
		mem_write8(x + 0x28u, t2 + 1u);
	}
}

uint16_t sub_03B155(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t u = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 - 1u);
	if (t1 != 1u)
		return y;
	u = sub_03B39A(x);
	sub_03B27F(x, u, &y, &carry);
	return y;
}

void sub_03B161(uint16_t x)
{
	uint32_t negative = 0;
	uint8_t t1 = 0;

	if ((mem_read8(x) & 0x20u) != 0u)
	{
		t1 = mem_read8(x + 0x1Eu);
		negative = t1 >> 7;
		if (t1 != 0u && negative == 0u)
		{
			mem_write8(x + 0x43u, 0u);
			sub_03B3FB(x);
		}
	}
}

void sub_03B176(uint16_t x, uint16_t *p_y, uint16_t *p_u, uint32_t *p_carry)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = *p_carry;
	uint16_t u = 0;

	sub_03B243(x, &u, &carry);
	if (carry == 0u)
		carry = 0u;
	else
	{
		sub_03B577(x, &y, &carry);
		if (carry == 0u)
		{
			unk_48F8 = 0x58u;
			unk_48FA = 0x12u;
			sub_03B371(x, &u, &carry);
			if (carry == 0u)
				carry = 0u;
			else if (unk_4858 < DATA8(indexed_table_03BBA3_ADDRESS + (int8_t)(unk_4857 - 1u)))
			{
				unk_48F0 = 1u;
				sub_03B443(x, &u, &carry);
			}
			else
			{
				unk_48F0 = 0u;
				sub_03B443(x, &u, &carry);
			}
		}
		else
		{
			carry = sub_03B566(x);
			if (carry)
				carry = sub_03B4E1(x);
			else
			{
				unk_48F8 = 0x58u;
				unk_48FA = 0x12u;
				sub_03B371(x, &u, &carry);
				if (carry == 0u)
					carry = 0u;
				else if (unk_4858 < DATA8(indexed_table_03BBA3_ADDRESS + (int8_t)(unk_4857 - 1u)))
				{
					unk_48F0 = 1u;
					sub_03B443(x, &u, &carry);
				}
				else
				{
					unk_48F0 = 0u;
					sub_03B443(x, &u, &carry);
				}
			}
		}
	}
	*p_y = y;
	*p_u = u;
	*p_carry = carry;
}

void sub_03B1B5(uint16_t x, uint16_t *p_y, uint16_t *p_u, uint32_t *p_carry)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = *p_carry;
	uint16_t d = 0, u = 0;
	uint16_t t1 = 0, t2 = 0;

	sub_03B243(x, &u, &carry);
	if (carry == 0u)
		carry = 0u;
	else
	{
		t1 = mem_read16(x + 0x2Bu);
		u = t1;
		sub_03B577(x, &y, &carry);
		if (carry)
		{
			carry = sub_03B566(x);
			if (carry)
			{
				carry = sub_03B4E1(x);
				*p_y = y;
				*p_u = u;
				*p_carry = carry;
				return;
			}
		}
		unk_48F8 = 0x58u;
		carry = sub_03B38A(x, u);
		if (carry == 0u)
		{
			t2 = mem_read16(x + 0x3Eu);
			if ((int16_t)t2 < 0x80)
				carry = 0u;
			else
			{
				unk_48FA = 0x22u;
				carry = sub_03B37B(x, u);
				if (carry == 0u)
					carry = 0u;
				else
				{
					carry = sub_03B566(x);
					if (carry)
					{
						sub_03B2D5(x);
						mem_write8(x, mem_read8(x) | 4u);
						mem_write8(x + 0x35u, 1u);
						mem_write16(x + 0x3Eu, 0u);
						mem_write8(x + 0x29u, 0u);
						mem_write8(x + 0x40u, 0u);
						d = 0x2900u;
						sub_03B2F0(x, d);
						mem_write8(x + 2u, 9u);
						mem_write8(x + 0x28u, 0u);
						carry = 1u;
					}
					else
						carry = 0u;
				}
			}
		}
		else
		{
			unk_48FA = 0x12u;
			sub_03B371(x, &u, &carry);
			if (carry)
			{
				unk_48F0 = 0u;
				*p_u = u;
				sub_03B443(x, p_u, &carry);
				*p_y = y;
				*p_carry = carry;
				return;
			}
			carry = 0u;
		}
	}
	*p_y = y;
	*p_u = u;
	*p_carry = carry;
}

void sub_03B1FF(uint16_t x, uint16_t *p_y, uint16_t *p_u, uint32_t *p_carry)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = *p_carry;
	uint16_t u = 0;
	uint8_t t1 = 0, t2 = 0;
	uint16_t t3 = 0, t4 = 0;

	sub_03B243(x, &u, &carry);
	if (carry == 0u)
		carry = 0u;
	else
	{
		sub_03B577(x, &y, &carry);
		if (carry == 0u)
		{
			unk_48F8 = 0x58u;
			unk_48FA = 0x12u;
			sub_03B371(x, &u, &carry);
			if (carry == 0u)
			{
				t1 = mem_read8(x + 0x34u);
				if (t1 == 2u)
					carry = 0u;
				else
				{
					y = indexed_table_03BBC7_ADDRESS;
					t2 = mem_read8(x + 0x34u);
					t3 = DATA16(indexed_table_03BBC7_ADDRESS + (((((uint32_t)t2 << 1) << 1) + unk_4861) & 0x1Eu));
					t4 = mem_read16(x + 0x41u);
					if ((int16_t)t3 <= (int16_t)t4)
					{
						mem_write16(x + 0x41u, 0u);
						if (unk_4857 >= 3u)
							mem_write8(x, mem_read8(x) | 4u);
						mem_write8(x + 0x29u, 0u);
						mem_write8(x + 2u, 0xBu);
						carry = 0u;
						mem_write8(x + 0x28u, 0u);
					}
					else
						carry = 0u;
				}
			}
			else
			{
				unk_48F0 = 0u;
				sub_03B443(x, &u, &carry);
			}
		}
		else
		{
			carry = sub_03B566(x);
			if (carry)
				carry = sub_03B4E1(x);
			else
			{
				unk_48F8 = 0x58u;
				unk_48FA = 0x12u;
				sub_03B371(x, &u, &carry);
				if (carry == 0u)
				{
					t1 = mem_read8(x + 0x34u);
					if (t1 == 2u)
						carry = 0u;
					else
					{
						y = indexed_table_03BBC7_ADDRESS;
						t2 = mem_read8(x + 0x34u);
						t3 = DATA16(indexed_table_03BBC7_ADDRESS + (((((uint32_t)t2 << 1) << 1) + unk_4861) & 0x1Eu));
						t4 = mem_read16(x + 0x41u);
						if ((int16_t)t3 <= (int16_t)t4)
						{
							mem_write16(x + 0x41u, 0u);
							if (unk_4857 >= 3u)
								mem_write8(x, mem_read8(x) | 4u);
							mem_write8(x + 0x29u, 0u);
							mem_write8(x + 2u, 0xBu);
							carry = 0u;
							mem_write8(x + 0x28u, 0u);
						}
						else
							carry = 0u;
					}
				}
				else
				{
					unk_48F0 = 0u;
					sub_03B443(x, &u, &carry);
				}
			}
		}
	}
	*p_y = y;
	*p_u = u;
	*p_carry = carry;
}

void sub_03B243(uint16_t x, uint16_t *p_u, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t u = 0;
	uint8_t t4 = 0, t5 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read16(x + 0x2Bu);
	u = t1;
	t2 = mem_read16(x + 0xCu);
	t3 = mem_read16(u + 0xCu);
	if ((int16_t)t2 < (int16_t)t3)
	{
		t4 = mem_read8(x + 9u);
		if ((t4 & 0x40u) != 0u)
			carry = 0u;
		else
			carry = 1u;
	}
	else
	{
		t5 = mem_read8(x + 9u);
		if ((t5 & 0x40u) == 0u)
			carry = 0u;
		else
			carry = 1u;
	}
	*p_u = u;
	*p_carry = carry;
}

uint16_t sub_03B263(uint16_t x)
{
	uint16_t d = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + VIDEO_0031);
	t2 = mem_read8(x + 0x30u);
	t3 = mem_read8(x + 0x34u);
	y = DATA16(indexed_table_03BCD7_ADDRESS + (int8_t)((uint32_t)(t2 + t3) << 1));
	d = ((uint32_t)t1 << 8) | mem_read8(y + (unk_4861 >> 1));
	sub_078617(x, d);
	sub_03B2D5(x);
	return y;
}

void sub_03B27F(uint16_t x, uint16_t u, uint16_t *p_y, uint32_t *p_carry)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = *p_carry;
	uint16_t ignored16 = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0;
	uint16_t t1 = 0;

	sub_078686(x, &u, &ignored16, &carry);
	if (carry == 0u)
		carry = sub_03B3D8(x);
	else
	{
		t1 = mem_read16(x + 0x2Bu);
		y = t1;
		if (mem_read8(y) == 0u)
		{
			mem_write8(x + 0x2Au, 0x40u);
			mem_write16(x + 0x2Bu, u);
			carry = 0u;
		}
		else
		{
			t2 = mem_read8(y + 2u);
			if ((int8_t)t2 < 0)
			{
				mem_write8(x + 0x2Au, 0x40u);
				mem_write16(x + 0x2Bu, u);
				carry = 0u;
			}
			else
			{
				t3 = mem_read8(x + 0x2Au);
				if (t3 == 0u)
				{
					mem_write8(x + 0x2Au, 0x40u);
					mem_write16(x + 0x2Bu, u);
					carry = 0u;
				}
				else
				{
					t4 = mem_read8(x + 0x2Au);
					mem_write8(x + 0x2Au, t4 - 1u);
					carry = 0u;
				}
			}
		}
	}
	*p_y = y;
	*p_carry = carry;
}

void sub_03B2A6(uint16_t x)
{
	uint32_t negative = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, u = 0, x_2 = 0;
	uint8_t stack_3 = 0;
	uint16_t stack = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read16(x + 0x2Bu);
	u = t1;
	t2 = mem_read16(x + 0xCu);
	t3 = mem_read16(u + 0xCu);
	if ((int16_t)t3 < (int16_t)t2)
		b = 0x40u;
	else
		b = 0xC0u;
	stack = x;
	stack_3 = b;
	x_2 = u;
	d = (uint32_t)(uint16_t)(((uint32_t)a << 8) | b) << 8;
	sub_078638(x_2, &d, &negative);
	a = (uint8_t)(d >> 8);
	if ((int8_t)a < 0)
		stack_3 = 0u - stack_3;
	x_2 = stack;
	d = stack_3;
	d = sub_078671(x_2, u, d);
	a = (uint8_t)(d >> 8);
	mem_write8(x_2 + 0x2Du, a);
	d = sub_07861D(x_2, u);
	a = (uint8_t)(d >> 8);
	mem_write8(x_2 + 0x2Eu, a);
}

void sub_03B2D5(uint16_t x)
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

uint16_t sub_03B2F0(uint16_t x, uint16_t d)
{
	uint8_t a = 0, b = 0;
	uint16_t d_2 = 0;
	uint16_t t1 = 0;

	t1 = DATA16(indexed_table_03BBF9_ADDRESS + (int8_t)((uint32_t)(d >> 8) << 1));
	a = (uint8_t)(t1 >> 8);
	b = t1 | 0x80u;
	mem_write16(x + 4u, ((uint32_t)a << 8) | b);
	d_2 = ((uint32_t)a << 8) | b;
	return d_2;
}

uint16_t sub_03B2FF(uint16_t x, uint16_t d)
{
	uint16_t d_2 = 0, u = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = DATA16(indexed_table_03BC65_ADDRESS + (int8_t)((uint16_t)((uint32_t)(uint8_t)((uint32_t)(d >> 8) << 1) << 8) >> 8));
	d_2 = mem_read16(t1);
	mem_write16(x + 0x1Cu, d_2);
	t2 = t1 + 2u;
	mem_write16(x + 0x1Fu, mem_read16(t2));
	t3 = t2 + 2u;
	mem_write16(x + 0x21u, mem_read16(t3));
	t4 = t3 + 2u;
	u = t4 + 2u;
	mem_write16(x + 0x23u, mem_read16(t4));
	return u;
}

void sub_03B371(uint16_t x, uint16_t *p_u, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t u = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x2Bu);
	u = t1;
	carry = sub_03B38A(x, u);
	if (carry == 0u)
		carry = 0u;
	else
		carry = sub_03B37B(x, u);
	*p_u = u;
	*p_carry = carry;
}

uint32_t sub_03B37B(uint16_t x, uint16_t u)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read16(u + 0x11u);
	t2 = mem_read16(x + 0x11u);
	t3 = t1 - t2;
	d = t3;
	if ((int16_t)t3 < 0 || (int16_t)unk_48FA < (int16_t)d)
	{
		carry = 0u;
		return carry;
	}
	carry = 1u;
	return carry;
}

uint32_t sub_03B38A(uint16_t x, uint16_t u)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = mem_read16(x + 0xCu);
	t2 = mem_read16(u + 0xCu);
	d = t1 - t2;
	if ((int16_t)unk_48F8 < (int16_t)(d >> 15 ? 0u - d : d))
	{
		carry = 0u;
		return carry;
	}
	carry = 1u;
	return carry;
}

uint16_t sub_03B39A(uint16_t x)
{
	uint16_t d = 0, u = 0;
	uint8_t t1 = 0, t2 = 0;

	mem_write8(x, (mem_read8(x) | 0x40u) & ~4u);
	t1 = mem_read8(x + 0x30u);
	d = (uint32_t)t1 << 8;
	u = sub_03B2FF(x, d);
	t2 = mem_read8(x + 0x30u);
	mem_write8(x + 2u, 1u + t2);
	mem_write8(x + 0x28u, 0u);
	mem_write8(x + 0x29u, 0u);
	return u;
}

uint32_t sub_03B3D8(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	d = 0x3F38u;
	carry = sub_078680(d);
	mem_write8(x + 2u, 0xDu);
	mem_write8(x + 0x28u, 0u);
	t1 = mem_read8(x + 0x30u);
	t2 = mem_read8(x + 0x34u);
	d = 0x38u | ((uint32_t)(uint8_t)(0xFu + t1 + t2) << 8);
	sub_03B2F0(x, d);
	mem_write8(x, mem_read8(x) & 0xBFu);
	carry = 1u;
	return carry;
}

void sub_03B3FB(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0, u = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t7 = 0, t8 = 0, t9 = 0;
	uint16_t t1 = 0, t6 = 0;

	t1 = mem_read16(x + 0x25u);
	u = t1;
	mem_write8(u + 0x2Au, 1u);
	mem_write16(u + 0x49u, x);
	mem_write8(x, mem_read8(x) & 0xBBu);
	t2 = mem_read8(x + 0x30u);
	if (t2 != 2u)
		sub_03B4FE(x);
	d = 0x6600u;
	carry = sub_078680(d);
	d = 0u;
	sub_03B2FF(x, d);
	t3 = mem_read8(x + 0x30u);
	t4 = mem_read8(x + 0x34u);
	t5 = mem_read8(x + 0x1Bu);
	if (mem_read8(DATA16(indexed_table_03BB85_ADDRESS + (int8_t)((uint32_t)(t3 + t4) << 1)) + (int8_t)(unk_4857 - 1u)) < t5)
	{
		mem_write8(x + 2u, 0xFFu);
		mem_write8(x + 0x28u, 0u);
		return;
	}
	t6 = mem_read16(x + 0x25u);
	t7 = mem_read8(t6 + 0x5Bu);
	mem_write8(x + 0x27u, t7 & ~0xFu);
	mem_write8(x, mem_read8(x) & 0xBFu);
	t8 = mem_read8(x + 0x30u);
	t9 = mem_read8(x + 0x34u);
	mem_write8(x + 2u, 0xFEu - t8 - t9);
	mem_write8(x + 0x28u, 0u);
}

void sub_03B443(uint16_t x, uint16_t *p_u, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d = 0, u = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0;
	uint16_t t1 = 0;

	mem_write8(x + 0x35u, unk_48F0);
	t1 = mem_read16(x + 0x2Bu);
	u = t1;
	t2 = mem_read8(u + 2u);
	if ((int8_t)t2 < 0)
		carry = sub_03B3D8(x);
	else
	{
		t3 = mem_read8(x + 0x30u);
		t4 = mem_read8(x + 0x35u);
		mem_write8(x + 2u, ((uint32_t)t3 << 1) + t4 + 6u);
		t5 = mem_read8(x + 0x30u);
		t6 = mem_read8(x + 0x34u);
		d = (uint32_t)(uint8_t)(t5 + t6) << 8;
		sub_03B2F0(x, d);
		mem_write8(x + 0x28u, 0u);
		mem_write8(x + 0x29u, 0u);
		t7 = mem_read8(x + 0x34u);
		t8 = mem_read8(x + 0x30u);
		u = DATA16(indexed_table_03BBE7_ADDRESS + (int8_t)((uint32_t)(t7 + t8) << 1));
		if (unk_4858 < mem_read8(u + (int8_t)(unk_4857 - 1u)))
		{
			t9 = mem_read8(x + 0x1Bu);
			mem_write8(x + VIDEO_002F, t9);
			carry = 1u;
		}
		else
		{
			t10 = mem_read8(x + VIDEO_002F);
			t11 = mem_read8(x + 0x1Bu);
			if ((uint8_t)(t10 - t11) > 0xCu)
			{
				t9 = mem_read8(x + 0x1Bu);
				mem_write8(x + VIDEO_002F, t9);
				carry = 1u;
			}
			else
			{
				mem_write8(x + 0x29u, 0x20u);
				carry = 1u;
			}
		}
	}
	*p_u = u;
	*p_carry = carry;
}

uint32_t sub_03B4E1(uint16_t x)
{
	uint32_t carry = 0;

	mem_write16(x + 0x3Bu, 0u);
	mem_write8(x + 0x3Du, 0u);
	mem_write8(x + 0x29u, 0u);
	sub_03B2D5(x);
	mem_write8(x, mem_read8(x) | 4u);
	mem_write8(x + 2u, 0xCu);
	mem_write8(x + 0x28u, 0u);
	carry = 1u;
	return carry;
}

void sub_03B4FE(uint16_t x)
{
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write16(x + 0x19u, 0u);
}

void sub_03B509(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = mem_read16(x + 0xFu);
	a = (uint8_t)(t1 >> 8);
	carry = (a >> 0) & 1u;
	a = (int8_t)a >> 1;
	b = ((uint8_t)t1 >> 1) | (carry << 7);
	carry = (a >> 0) & 1u;
	mem_write16(x + 0xFu, ((uint32_t)(uint8_t)((int8_t)a >> 1) << 8) | (uint8_t)((b >> 1) | (carry << 7)));
	t2 = mem_read16(x + 0x14u);
	a = (uint8_t)(t2 >> 8);
	carry = (a >> 0) & 1u;
	a = (int8_t)a >> 1;
	b = ((uint8_t)t2 >> 1) | (carry << 7);
	carry = (a >> 0) & 1u;
	mem_write16(x + 0x14u, ((uint32_t)(uint8_t)((int8_t)a >> 1) << 8) | (uint8_t)((b >> 1) | (carry << 7)));
}

uint16_t sub_03B51E(uint16_t x, uint16_t u, uint16_t d)
{
	uint8_t a = 0, b = 0;
	uint16_t y = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0, t15 = 0;

	a = (uint8_t)(d >> 8);
	unk_48EA = 0u;
	unk_48E8 = a;
	if ((int8_t)a < 0)
	{
		mem_write8(u + 9u, 0x40u);
		a &= 0x7Fu;
	}
	t1 = object_1d_parts_ADDRESS + (int8_t)((((uint32_t)a << 1) << 1) << 1);
	unk_48EB = DATA8(t1);
	t2 = t1 + 1u;
	t3 = (int8_t)mem_read8(t2);
	t4 = mem_read16(x + 0x11u);
	t5 = t3 + t4;
	mem_write16(u + 0x11u, t5);
	t6 = t2 + 1u;
	t7 = (int8_t)mem_read8(t6);
	t8 = mem_read16(x + 0x16u);
	t9 = t7 + t8;
	mem_write16(u + 0x16u, t9);
	t10 = t6 + 1u;
	y = t10 + 1u;
	mem_write8(u + 1u, mem_read8(t10));
	t11 = mem_read16(y);
	mem_write16(u + 4u, t11);
	t12 = (((uint32_t)unk_48EA << 8u) | unk_48EB);
	a = (uint8_t)(t12 >> 8);
	b = (uint8_t)t12;
	if ((int8_t)unk_48E8 < 0)
	{
		t13 = 0u - (((uint32_t)a << 8) | b);
		a = (uint8_t)(t13 >> 8);
		b = (uint8_t)t13;
	}
	t14 = mem_read16(x + 0xCu);
	t15 = (((uint32_t)a << 8) | b) + t14;
	mem_write16(u + 0xCu, t15);
	return y;
}

uint32_t sub_03B566(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t a = 0, d = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0xCu);
	d = (uint8_t)t1;
	a = (uint8_t)(t1 >> 8);
	if ((int16_t)(((uint32_t)a << 8) | (d & 0xFFu)) < 0x40 || (int16_t)(((uint32_t)a << 8) | (d & 0xFFu)) > 0x180)
	{
		carry = 0u;
		return carry;
	}
	carry = 1u;
	return carry;
}

void sub_03B577(uint16_t x, uint16_t *p_y, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t y = 0;
	uint8_t t1 = 0, t2 = 0;
	uint16_t t3 = 0, t4 = 0;

	y = indexed_table_03BBA7_ADDRESS;
	t1 = mem_read8(x + 0x30u);
	t2 = mem_read8(x + 0x34u);
	t3 = DATA16(indexed_table_03BBA7_ADDRESS + ((unk_4861 + t1 + t2) & 0x1Eu));
	t4 = mem_read16(x + 0x3Bu);
	if ((int16_t)t3 < (int16_t)t4)
		carry = 1u;
	else
		carry = 0u;
	*p_y = y;
	*p_carry = carry;
}

void sub_03B590(uint16_t x)
{
	mem_write16(x + 0x3Bu, 0u);
	mem_write16(x + 0x3Eu, 0u);
	mem_write16(x + 0x41u, 0u);
}

void sub_03B5A4(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x, 0x80u);
	mem_write16(x + 4u, 0xCC91u);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
}

void sub_03B5B2(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint8_t a = 0, d = 0;
	uint16_t d_2 = 0;
	uint8_t t1 = 0, t2 = 0;

	if (unk_4881 == 0u)
	{
		t1 = (uint8_t)unk_4815;
		a = t1;
		if (t1 == 0u)
			mem_write8(x + 5u, 0x91u);
		else if (a == 0x80u)
			mem_write8(x + 5u, 0x93u);
	}
	else
	{
		d = 2u;
		sub_07867D(d, &u, &carry);
		d_2 = 0x602u;
		y = sub_03B51E(x, u, d_2);
		mem_write8(u, 0x80u);
		mem_write8(u, 0x80u);
		mem_write16(u + 4u, 0x1389u);
		mem_write16(x + 0x28u, u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_03B5EC(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d = 0, u = 0;
	uint16_t stack = 0;
	uint8_t t2 = 0, t6 = 0, t7 = 0, t8 = 0;
	uint16_t t1 = 0, t3 = 0, t4 = 0, t5 = 0;

	t1 = mem_read16(x + 0x28u);
	u = t1;
	t2 = mem_read8(u + 6u);
	if ((t2 & 2u) == 0u)
		return u;
	t3 = mem_read16(u + 0x11u);
	t4 = t3 - 0x10u;
	mem_write16(u + 0x11u, t4);
	u = 0x30ACu;
	unk_48F0 = 0x10u;
	do
	{
		unk_48F1 = 0x20u;
		a = 0x10u;
		stack = u;
		do
		{
			mem_write8(u - 0x2000u, 0u);
			t5 = u;
			u = t5 + 1u;
			mem_write8(t5, a);
			t6 = unk_48F1;
			unk_48F1 = t6 - 1u;
		} while (t6 != 1u);
		u = stack + 0x40u;
		t7 = unk_48F0;
		unk_48F0 = t7 - 1u;
	} while (t7 != 1u);
	mem_write8(x, 4u);
	d = 0x4F00u;
	carry = sub_078680(d);
	t8 = mem_read8(x + 2u);
	mem_write8(x + 2u, t8 + 1u);
	return u;
}

uint16_t sub_03B633(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t2 = 0, t3 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x28u);
	u = t1;
	t2 = mem_read8(u + 6u);
	if ((t2 & 1u) != 0u)
	{
		mem_write8(x, 0u);
		mem_write8(u, 0u);
		t3 = mem_read8(x + 2u);
		mem_write8(x + 2u, t3 + 1u);
	}
	return u;
}

void sub_03B654(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write16(x + 0xFu, 0xFF00u);
	mem_write16(x + 0x19u, 0x100u);
	mem_write16(x + 0x14u, rom_07FFC0_ADDRESS);
	mem_write8(x + 0x28u, 0x80u);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
}

void sub_03B66F(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x, 0u);
		return;
	}
	if ((unk_4815 & 3u) == 0u)
	{
		t2 = mem_read8(x + 0xAu);
		mem_write8(x + 0xAu, t2 - 1u);
		t3 = mem_read8(x + 0xBu);
		mem_write8(x + 0xBu, t3 - 1u);
	}
}

void sub_03B68E(uint16_t x)
{
	uint8_t a = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x, 0u);
		return;
	}
	a = mem_read8(x) | 0x80u;
	if ((unk_4815 & 1u) != 0u)
		a &= 0x7Fu;
	mem_write8(x, a);
	sub_03B6A5(x);
}

void sub_03B6A5(uint16_t x)
{
	uint32_t negative = 0, carry = 0;
	uint16_t ignored16 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	sub_07863B(x, &ignored16, &negative);
	if (negative)
	{
		t1 = mem_read8(x + 0xFu);
		mem_write8(x + 0xFu, 0u - t1);
	}
	carry = sub_03B6CA(x);
	if (carry)
	{
		t2 = mem_read8(x + 0x19u);
		mem_write8(x + 0x19u, (int8_t)(0u - t2) >> 1);
		t3 = mem_read8(x + 2u);
		if (t3 != 3u)
		{
			t4 = mem_read8(x + 2u);
			mem_write8(x + 2u, t4 + 1u);
			mem_write8(x + 0x28u, 0x40u);
		}
	}
}

uint32_t sub_03B6CA(uint16_t x)
{
	uint32_t negative = 0, carry = 0;
	uint8_t a = 0, b = 0;
	uint8_t t6 = 0, t7 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t8 = 0;

	t1 = mem_read16(x + 0x19u);
	t2 = t1 - 0x60u;
	a = (uint8_t)(t2 >> 8);
	b = (uint8_t)t2;
	mem_write16(x + 0x19u, ((uint32_t)a << 8) | b);
	t3 = mem_read16(x + 0x17u);
	t4 = ((uint32_t)a << 8) | b;
	t5 = t4 + t3;
	carry = (uint16_t)(t4 + t3) < t4;
	mem_write16(x + 0x17u, t5);
	t6 = mem_read8(x + 0x19u);
	t7 = mem_read8(x + 0x16u);
	mem_write8(x + 0x16u, ((uint16_t)(int8_t)t6 >> 8) + t7 + carry);
	t8 = mem_read16(x + 0x16u);
	negative = t8 >> 15;
	if (t8 == 0u || negative)
	{
		mem_write16(x + 0x16u, 0u);
		mem_write8(x + 0x18u, 0u);
		carry = 1u;
		return carry;
	}
	carry = 0u;
	return carry;
}

void sub_03B6FE(void)
{
}

uint16_t sub_03B6FF(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t4 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read16(x + 0x2Au);
	u = t1;
	mem_write8(x, 0x80u);
	t2 = mem_read16(u + 0xCu);
	mem_write16(x + 0xCu, t2 + 0x20u);
	t3 = mem_read16(u + 0x11u);
	mem_write16(x + 0x11u, t3);
	mem_write16(x + 0x16u, 0x100u);
	mem_write16(x + 4u, 0xCC82u);
	t4 = mem_read8(x + 2u);
	mem_write8(x + 2u, t4 + 1u);
	return u;
}

uint16_t sub_03B725(uint16_t x, uint16_t u)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t3 = 0, t5 = 0, t6 = 0;
	uint16_t t1 = 0, t2 = 0, t4 = 0;

	carry = sub_03B6CA(x);
	t1 = mem_read16(x + 0x16u);
	if ((int16_t)t1 <= 0x10)
	{
		t2 = mem_read16(x + 0x2Au);
		u = t2;
		t3 = mem_read8(u + 0x3Au);
		mem_write8(u + 0x3Au, t3 + 1u);
		t4 = mem_read16(x + 0x19u);
		d = 0u - t4;
		t5 = d >> 8;
		carry = (t5 >> 0) & 1u;
		d = (d & 0xFFu) | ((uint32_t)(uint8_t)((int8_t)t5 >> 1) << 8);
		mem_write16(x + 0x19u, (d & ~0xFFu) | (uint8_t)(((uint8_t)d >> 1) | (carry << 7)));
		mem_write16(x + 0xFu, 0x300u);
		mem_write16(x + 0x14u, 0xFF80u);
		t6 = mem_read8(x + 2u);
		mem_write8(x + 2u, t6 + 1u);
	}
	return u;
}

void sub_03B74F(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t2 = 0, t3 = 0;
	uint16_t t1 = 0;

	carry = sub_03B6CA(x);
	if (carry)
	{
		t1 = mem_read16(x + 0x19u);
		d = 0u - t1;
		t2 = d >> 8;
		carry = (t2 >> 0) & 1u;
		d = (d & 0xFFu) | ((uint32_t)(uint8_t)((int8_t)t2 >> 1) << 8);
		mem_write16(x + 0x19u, (d & ~0xFFu) | (uint8_t)(((uint8_t)d >> 1) | (carry << 7)));
		t3 = mem_read8(x + 2u);
		mem_write8(x + 2u, t3 + 1u);
	}
}

void sub_03B761(uint16_t x)
{
	sub_03B806(0u);
	sub_03B764(x);
}

void sub_03B764(uint16_t x)
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
	d = unk_4800_ADDRESS;
	carry = sub_078680(d);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write16(x + 0x19u, 0u);
	mem_write16(x + 4u, 0x1188u);
	mem_write8(x + 0x29u, 0x20u);
	t3 = mem_read8(x + 2u);
	mem_write8(x + 2u, t3 + 1u);
}

void sub_03B78C(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 5u, 0x89u);
		mem_write8(x + 0x29u, 0x20u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_03B79F(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 5u, 0x87u);
		mem_write8(x + 0x29u, 0x40u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_03B7B2(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	sub_03B806(0u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 5u, 0x81u);
		mem_write16(x + 0xFu, 0xFF80u);
		mem_write8(x + 9u, 0x40u);
		mem_write8(x + 0x29u, 0x28u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

uint16_t sub_03B7D2(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t5 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	sub_03B806(0u);
	t1 = mem_read16(x + 0x2Au);
	u = t1;
	t2 = mem_read16(x + 0xCu);
	t3 = mem_read16(u + 0xCu);
	t4 = t2 - t3;
	if ((int16_t)t4 <= 0x60)
	{
		mem_write8(x + 5u, 0x86u);
		mem_write16(x + 0xFu, 0u);
		mem_write8(x + 0x29u, 0x80u);
		t5 = mem_read8(x + 2u);
		mem_write8(x + 2u, t5 + 1u);
	}
	return u;
}

void sub_03B7F4(uint16_t x, uint16_t d)
{
	uint8_t t1 = 0;

	d = sub_03B806(d);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 - 1u);
	if (t1 == 1u)
	{
		unk_4804++;
		unk_4805 = d;
	}
}

uint16_t sub_03B806(uint16_t d)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d_2 = 0;
	uint8_t t1 = 0;

	t1 = (uint8_t)unk_4815 & 0xFu;
	a = t1;
	if (t1 == 0u)
	{
		d = 0x4500u;
		a = 0x45u;
		carry = sub_078680(d);
	}
	d_2 = (d & 0xFFu) | ((uint32_t)a << 8);
	return d_2;
}

void sub_03B82F(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0;
	uint8_t t1 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry == 0u)
		return;
	d = 0x5200u;
	carry = sub_078680(d);
	mem_write8(x + 5u, 0x87u);
	mem_write8(x + 0x3Bu, 0x20u);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
}

void sub_03B848(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	if ((mem_read8(x) & 0x20u) != 0u)
	{
		unk_4897 = 1u;
		unk_4898 = 0u;
		d = 0x4C00u;
		carry = sub_078680(d);
		unk_487E = 6u;
		d = 0xE20u;
		sub_078677(d, &y, &u);
		mem_write8(x + 5u, 0x89u);
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
		t1 = mem_read8(x + 2u);
		mem_write8(x + 2u, t1 + 1u);
	}
	else
	{
		t2 = mem_read8(x + 0x3Bu);
		mem_write8(x + 0x3Bu, t2 - 1u);
		if (t2 == 1u)
		{
			unk_4897 = 1u;
			unk_4898 = 0u;
			d = 0x4C00u;
			carry = sub_078680(d);
			unk_487E = 6u;
			d = 0xE20u;
			sub_078677(d, &y, &u);
			mem_write8(x + 5u, 0x89u);
			mem_write16(x + 0xFu, 0u);
			mem_write16(x + 0x14u, 0u);
			t1 = mem_read8(x + 2u);
			mem_write8(x + 2u, t1 + 1u);
		}
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_03B87C(uint16_t x)
{
	uint8_t a = 0;
	uint16_t d = 0, u = 0;
	uint8_t t1 = 0, t2 = 0;

	a = 0u;
	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) != 0u)
		a = 0xEu;
	d = (uint32_t)a << 8;
	u = sub_03B2FF(x, d);
	t2 = mem_read8(x + 6u);
	if ((t2 & 1u) != 0u)
		mem_write8(x, 0u);
	return u;
}

void sub_03B8A3(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) != 0u)
		mem_write8(x, 0u);
}

void sub_03B8AD(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x, mem_read8(x) | 0x40u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_03B8BC(uint16_t x)
{
	if ((mem_read8(x) & 0x20u) != 0u)
	{
		sub_03B8C3(x);
		return;
	}
}

void sub_03B8C3(uint16_t x)
{
	sub_03B4FE(x);
	mem_write8(x, mem_read8(x) & 0xBFu);
	mem_write16(x + 4u, 0x9093u);
	mem_write8(x + 2u, 0xFFu);
}

uint16_t sub_03B923(uint16_t x)
{
	uint16_t d = 0, u = 0;
	uint8_t t1 = 0;

	mem_write8(x, mem_read8(x) | 0x40u);
	d = 0xD00u;
	u = sub_03B2FF(x, d);
	mem_write8(x + 0x2Bu, 0xC0u);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	return u;
}

uint16_t sub_03B937(uint16_t x, uint16_t u)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t6 = 0;
	uint16_t t5 = 0;

	t1 = io_read8(VIDEO_18FC);
	io_write8(VIDEO_18FC, 0u);
	t2 = mem_read8(x + 0x2Bu);
	mem_write8(x + 0x2Bu, t2 - 1u);
	if (t2 == 1u)
	{
		d = 0x9800u;
		carry = sub_078680(d);
		d = 0x3F39u;
		carry = sub_078680(d);
		mem_write8(x + 9u, 0x40u);
		mem_write8(x + 5u, 0x81u);
		mem_write8(x + 0x2Bu, 0x20u);
		t3 = mem_read8(x + 2u);
		mem_write8(x + 2u, t3 + 1u);
		return u;
	}
	if ((mem_read8(x) & 0x20u) == 0u)
		return u;
	t4 = mem_read8(x + 0x1Eu);
	if (t4 == 0u)
		return u;
	t5 = mem_read16(x + 0x25u);
	u = t5;
	t6 = mem_read8(u + 0x5Bu);
	io_write8(VIDEO_18FC, t6 & ~0xFu);
	d = 0x6300u;
	carry = sub_078680(d);
	d = 0x9800u;
	carry = sub_078680(d);
	d = 0x3F39u;
	carry = sub_078680(d);
	mem_write8(x + 9u, 0x40u);
	mem_write8(x + 5u, 0x81u);
	mem_write8(x + 0x2Bu, 0x20u);
	t3 = mem_read8(x + 2u);
	mem_write8(x + 2u, t3 + 1u);
	return u;
}

void sub_03B97C(uint16_t x, uint8_t d)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x2Bu);
	mem_write8(x + 0x2Bu, t1 - 1u);
	if (t1 == 1u)
	{
		io_write16(VIDEO_1852, x);
		unk_487D = 1u;
		unk_4804++;
		unk_4805 = 0x100u | (d & 0xFFu);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

uint16_t sub_03B99C(uint16_t x, uint16_t u)
{
	uint8_t t1 = 0, t3 = 0, t4 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) != 0u)
	{
		t2 = mem_read16(x + 0x29u);
		u = t2;
		t3 = mem_read8(u + 2u);
		mem_write8(u + 2u, t3 + 1u);
		t4 = mem_read8(x + 2u);
		mem_write8(x + 2u, t4 + 1u);
	}
	return u;
}

void sub_03B9AD(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t4 = 0;
	uint16_t t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x3Au);
	if (t1 == 0u)
		return;
	d = 0x3F2Cu;
	carry = sub_078680(d);
	t2 = mem_read16(x + 0xCu);
	io_write16(VIDEO_18F4, t2);
	t3 = mem_read16(x + 0x11u);
	io_write16(VIDEO_18F6, t3);
	io_write16(VIDEO_18F8, unk_48AC);
	io_write16(VIDEO_18FA, unk_48B2);
	mem_write8(x + 5u, 0x82u);
	mem_write8(x + 0x2Bu, 0x40u);
	t4 = mem_read8(x + 2u);
	mem_write8(x + 2u, t4 + 1u);
}

void sub_03B9E2(void)
{
}
