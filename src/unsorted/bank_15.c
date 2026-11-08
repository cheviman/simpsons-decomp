/**
 *    Name:        unsorted/bank_15.c
 *    Description: bank 15's code
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    07-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

void sub_02A000(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		y = sub_02A110(x);
		break;
	case 4:
	case 22:
	case 34:
	case 46:
	case 66:
	case 78:
	case 116:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case 6:
	case 24:
	case 36:
	case 48:
	case 68:
	case 80:
	case 118:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case 8:
	case 26:
	case 38:
	case 50:
	case 70:
	case 82:
	case 120:
		sub_0785E1(x, &y, &ignored16, &ignored);
		break;
	case 10:
	case 28:
	case 40:
	case 52:
	case 72:
	case 84:
	case 122:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_02A003(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		y = sub_02A1B1(x);
		break;
	case -38:
	case -20:
	case -8:
	case 4:
	case 24:
	case 36:
	case 74:
	case 94:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case -36:
	case -18:
	case -6:
	case 6:
	case 26:
	case 38:
	case 76:
	case 96:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case -34:
	case -16:
	case -4:
	case 8:
	case 28:
	case 40:
	case 78:
	case 98:
		sub_0785E1(x, &y, &ignored16, &ignored);
		break;
	case -32:
	case -14:
	case -2:
	case 10:
	case 30:
	case 42:
	case 80:
	case 100:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	case -24:
		y = sub_02A13C(x);
		break;
	case -12:
		y = sub_02A188(x);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_02A006(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02BF51_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02B44E(x, &y, &u);
		break;
	case 2:
		sub_02B477(x);
		break;
	case 4:
		u = sub_02B499(x, u);
		break;
	case 6:
		u = sub_02B4F0(x, u);
		break;
	case 8:
		u = sub_02B4FA(x, u);
		break;
	case 10:
		u = sub_02B516(x, u);
		break;
	case 12:
		sub_02B427(x);
		break;
	case 14:
		sub_02B436(x);
		break;
	case 16:
		sub_02B435();
		break;
	case -4:
	case -2:
		sub_02B41E(x, &y, &u);
		break;
	}
	carry = sub_078683(x, carry);
	*p_y = y;
	*p_u = u;
}

void sub_02A009(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = 0x7950u;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02A887(x);
		break;
	case 2:
		u = sub_02A8AB(x, u);
		break;
	case 4:
		sub_02A8E7(x);
		break;
	case 6:
		y = sub_02A8F5(x, y);
		break;
	case 8:
	case 32:
		y = sub_02A906(x);
		break;
	case 10:
	case 34:
		sub_02A90F(x);
		break;
	case 12:
		sub_02A91F(x);
		break;
	case 14:
		sub_02A92A(x);
		break;
	case 16:
		y = sub_02A95A(x, y);
		break;
	case 18:
		sub_02A986(x);
		break;
	case 20:
		sub_02A9A1(x);
		break;
	case -12:
		sub_02A7DF(x);
		break;
	case -10:
		sub_02A802(x);
		break;
	case -8:
		sub_02A811(x);
		break;
	case -6:
		y = sub_02A824(x, y);
		break;
	case -4:
		y = sub_02A856(x, y);
		break;
	case -2:
		sub_02A87A(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_02A00C(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = 0x795Cu;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02A91F(x);
		break;
	case 2:
		sub_02A92A(x);
		break;
	case 4:
		y = sub_02A95A(x, y);
		break;
	case 6:
		sub_02A986(x);
		break;
	case 8:
		sub_02A9A1(x);
		break;
	case -4:
	case 20:
		y = sub_02A906(x);
		break;
	case -2:
	case 22:
		sub_02A90F(x);
		break;
	case -24:
		sub_02A7DF(x);
		break;
	case -22:
		sub_02A802(x);
		break;
	case -20:
		sub_02A811(x);
		break;
	case -18:
		y = sub_02A824(x, y);
		break;
	case -16:
		y = sub_02A856(x, y);
		break;
	case -14:
		sub_02A87A(x);
		break;
	case -12:
		sub_02A887(x);
		break;
	case -10:
		u = sub_02A8AB(x, u);
		break;
	case -8:
		sub_02A8E7(x);
		break;
	case -6:
		y = sub_02A8F5(x, y);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_02A00F(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = 0x796Au;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		u = sub_02A9B0(x);
		break;
	case 2:
		sub_02A9DC(x);
		break;
	case 4:
		y = sub_02A9ED(x, y);
		break;
	case -18:
	case 6:
		y = sub_02A906(x);
		break;
	case -16:
	case 8:
		sub_02A90F(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_02A012(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02B979_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		u = sub_02A9B0(x);
		break;
	case 2:
		sub_02AA04(x);
		break;
	case 4:
		y = sub_02AA15(x, y);
		break;
	case 6:
	case 16:
		y = sub_02A906(x);
		break;
	case 8:
	case 18:
		sub_02A90F(x);
		break;
	case 10:
		sub_02AA2C();
		break;
	case 12:
		sub_02AA33(x);
		break;
	case 14:
		y = sub_02AA3F(x, y);
		break;
	case 20:
		u = sub_02AA5C(x);
		break;
	case 22:
		sub_02AA94(x, &y, &u);
		break;
	case 24:
		u = sub_02AB52(x);
		break;
	case 26:
		u = sub_02ABB0(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_02A015(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02A4D6(x, &y, &ignored16);
		break;
	case 2:
		sub_02A4F2(x, &y, &ignored16);
		break;
	case -106:
	case -86:
	case -38:
	case -22:
	case 4:
	case 32:
	case 66:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case -104:
	case -84:
	case -36:
	case -20:
	case 6:
	case 34:
	case 68:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case -102:
	case -82:
	case -34:
	case -18:
	case 8:
	case 36:
	case 70:
		sub_0785E1(x, &y, &ignored16, &ignored);
		break;
	case -100:
	case -80:
	case -32:
	case -16:
	case 10:
	case 38:
	case 72:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	case 12:
		sub_02A4FE(x, &y, &ignored16);
		break;
	case 14:
		sub_02A535(x);
		break;
	case 16:
		sub_02A5C5(x, 0u);
		break;
	case 18:
		sub_02A5F3(x);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_02A018(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t zero = 0, negative = 0;
	uint8_t b = 0;
	uint16_t ignored16 = 0, u = 0;
	uint32_t ignored = 0;
	uint8_t t1 = 0;

	b = (uint8_t)d;
	u = loaded_table_02B8D6_ADDRESS;
	t1 = (uint32_t)b << 1;
	negative = t1 >> 7;
	zero = t1 == 0u;
	switch ((int8_t)t1)
	{
	case 0:
		sub_02A6AE(x, &y, &u);
		break;
	case 2:
		sub_02A70F(x, &y, &u);
		break;
	case -100:
	case -84:
	case -58:
	case -30:
	case 4:
		sub_0785DB(x, &y, &u, &ignored);
		break;
	case -98:
	case -82:
	case -56:
	case -28:
	case 6:
		sub_0785DE(x, &y, &u, &ignored);
		break;
	case -96:
	case -80:
	case -54:
	case -26:
	case 8:
		sub_0785E1(x, &y, &u, &ignored);
		break;
	case -94:
	case -78:
	case -52:
	case -24:
	case 10:
		sub_0785E4(x, &y, &u, &ignored);
		break;
	case 12:
		sub_02A71B(x, u);
		break;
	case 14:
		sub_02A75D(x, u);
		break;
	case -108:
	case -4:
		sub_02A5FC(x);
		break;
	case -106:
	case -2:
		sub_02A62C(x);
		break;
	case -20:
	case -16:
	case -12:
	case -8:
		sub_07D030(x, u, zero, negative);
		break;
	case -6:
		sub_02A68E(x);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_02A01B(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02B8F6_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02A77B(x, &y, &u);
		break;
	case 2:
		sub_02A789();
		break;
	case 4:
		u = sub_02A78A(x);
		break;
	case 6:
		sub_02A7C4(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_02A01E(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02A3B3(x, &y, &ignored16);
		break;
	case 2:
		sub_02A3C3(x, &y, &ignored16);
		break;
	case -114:
	case -102:
	case -64:
	case -44:
	case 4:
	case 20:
	case 46:
	case 74:
	case 108:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case -112:
	case -100:
	case -62:
	case -42:
	case 6:
	case 22:
	case 48:
	case 76:
	case 110:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case -110:
	case -98:
	case -60:
	case -40:
	case 8:
	case 24:
	case 50:
	case 78:
	case 112:
		sub_0785E1(x, &y, &ignored16, &ignored);
		break;
	case -128:
	case -108:
	case -96:
	case -58:
	case -38:
	case 10:
	case 26:
	case 52:
	case 80:
	case 114:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	case 12:
		sub_02A3F2(x);
		break;
	case 14:
		sub_02A40D(x, 0u);
		break;
	case 16:
		sub_02A431(x, &y, &ignored16);
		break;
	case 18:
		sub_02A454(x, &y, &ignored16);
		break;
	case 28:
		sub_02A45D(x);
		break;
	case 30:
		sub_02A47E(x, 0u);
		break;
	case 32:
		sub_02A4A2(x, 0u);
		break;
	case -4:
	case 100:
		sub_02A5FC(x);
		break;
	case -50:
	case -2:
	case 102:
		sub_02A62C(x);
		break;
	case -54:
	case -6:
		sub_02A398(x);
		break;
	case -12:
		sub_02A362(x);
		break;
	case -10:
		sub_02A376(x);
		break;
	case -8:
		sub_02A384(x);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_02A021(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		y = sub_02A64F(x);
		break;
	case 2:
		y = sub_02A685(x, y);
		break;
	case -114:
	case -66:
	case -50:
	case -24:
	case 4:
	case 38:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case -112:
	case -64:
	case -48:
	case -22:
	case 6:
	case 40:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case -110:
	case -62:
	case -46:
	case -20:
	case 8:
	case 42:
		sub_0785E1(x, &y, &ignored16, &ignored);
		break;
	case -128:
	case -108:
	case -60:
	case -44:
	case -18:
	case 10:
	case 44:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_02A024(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02A431(x, &y, &ignored16);
		break;
	case 2:
		sub_02A454(x, &y, &ignored16);
		break;
	case -118:
	case -80:
	case -60:
	case -12:
	case 4:
	case 30:
	case 58:
	case 92:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case -128:
	case -116:
	case -78:
	case -58:
	case -10:
	case 6:
	case 32:
	case 60:
	case 94:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case -126:
	case -114:
	case -76:
	case -56:
	case -8:
	case 8:
	case 34:
	case 62:
	case 96:
		sub_0785E1(x, &y, &ignored16, &ignored);
		break;
	case -124:
	case -112:
	case -74:
	case -54:
	case -6:
	case 10:
	case 36:
	case 64:
	case 98:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	case 12:
		sub_02A45D(x);
		break;
	case 14:
		sub_02A47E(x, 0u);
		break;
	case 16:
		sub_02A4A2(x, 0u);
		break;
	case -20:
	case 84:
		sub_02A5FC(x);
		break;
	case -66:
	case -18:
	case 86:
		sub_02A62C(x);
		break;
	case -70:
	case -22:
		sub_02A398(x);
		break;
	case -28:
		sub_02A362(x);
		break;
	case -26:
		sub_02A376(x);
		break;
	case -24:
		sub_02A384(x);
		break;
	case -16:
		sub_02A3B3(x, &y, &ignored16);
		break;
	case -14:
		sub_02A3C3(x, &y, &ignored16);
		break;
	case -4:
		sub_02A3F2(x);
		break;
	case -2:
		sub_02A40D(x, 0u);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_02A027(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = 0x7948u;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02A811(x);
		break;
	case 2:
		y = sub_02A824(x, y);
		break;
	case 4:
		y = sub_02A856(x, y);
		break;
	case 6:
		sub_02A87A(x);
		break;
	case 8:
		sub_02A887(x);
		break;
	case 10:
		u = sub_02A8AB(x, u);
		break;
	case 12:
		sub_02A8E7(x);
		break;
	case 14:
		y = sub_02A8F5(x, y);
		break;
	case 16:
	case 40:
		y = sub_02A906(x);
		break;
	case 18:
	case 42:
		sub_02A90F(x);
		break;
	case 20:
		sub_02A91F(x);
		break;
	case 22:
		sub_02A92A(x);
		break;
	case 24:
		y = sub_02A95A(x, y);
		break;
	case 26:
		sub_02A986(x);
		break;
	case 28:
		sub_02A9A1(x);
		break;
	case -4:
		sub_02A7DF(x);
		break;
	case -2:
		sub_02A802(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_02A02A(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02B985_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02AA33(x);
		break;
	case 2:
		y = sub_02AA3F(x, y);
		break;
	case -6:
	case 4:
		y = sub_02A906(x);
		break;
	case -4:
	case 6:
		sub_02A90F(x);
		break;
	case 8:
		u = sub_02AA5C(x);
		break;
	case 10:
		sub_02AA94(x, &y, &u);
		break;
	case 12:
		u = sub_02AB52(x);
		break;
	case 14:
		u = sub_02ABB0(x);
		break;
	case -12:
		u = sub_02A9B0(x);
		break;
	case -10:
		sub_02AA04(x);
		break;
	case -8:
		y = sub_02AA15(x, y);
		break;
	case -2:
		sub_02AA2C();
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_02A02D(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02B983_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02AA2C();
		break;
	case 2:
		sub_02AA33(x);
		break;
	case 4:
		y = sub_02AA3F(x, y);
		break;
	case -4:
	case 6:
		y = sub_02A906(x);
		break;
	case -2:
	case 8:
		sub_02A90F(x);
		break;
	case 10:
		u = sub_02AA5C(x);
		break;
	case 12:
		sub_02AA94(x, &y, &u);
		break;
	case 14:
		u = sub_02AB52(x);
		break;
	case 16:
		u = sub_02ABB0(x);
		break;
	case -10:
		u = sub_02A9B0(x);
		break;
	case -8:
		sub_02AA04(x);
		break;
	case -6:
		y = sub_02AA15(x, y);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_02A030(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case -20:
	case 0:
		y = sub_02A334(x);
		break;
	case 2:
		y = sub_02A359(x, y);
		break;
	case -128:
	case -110:
	case -98:
	case -86:
	case -66:
	case -54:
	case -16:
	case 4:
	case 52:
	case 68:
	case 94:
	case 122:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case -126:
	case -108:
	case -96:
	case -84:
	case -64:
	case -52:
	case -14:
	case 6:
	case 54:
	case 70:
	case 96:
	case 124:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case -124:
	case -106:
	case -94:
	case -82:
	case -62:
	case -50:
	case -12:
	case 8:
	case 56:
	case 72:
	case 98:
	case 126:
		sub_0785E1(x, &y, &ignored16, &ignored);
		break;
	case -122:
	case -104:
	case -92:
	case -80:
	case -60:
	case -48:
	case -10:
	case 10:
	case 58:
	case 74:
	case 100:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	case -6:
	case 42:
		sub_02A398(x);
		break;
	case -2:
	case 46:
		sub_02A62C(x);
		break;
	case -18:
		y = sub_02A2E5(x, y);
		break;
	case -8:
		sub_02A2EE(x);
		break;
	case -4:
		sub_02A2FC(x);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_02A033(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		y = sub_02A205(x);
		break;
	case 2:
		y = sub_02A21B(x, y);
		break;
	case -70:
	case -52:
	case -40:
	case -28:
	case -8:
	case 4:
	case 42:
	case 62:
	case 110:
	case 126:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case -68:
	case -50:
	case -38:
	case -26:
	case -6:
	case 6:
	case 44:
	case 64:
	case 112:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case -66:
	case -48:
	case -36:
	case -24:
	case -4:
	case 8:
	case 46:
	case 66:
	case 114:
		sub_0785E1(x, &y, &ignored16, &ignored);
		break;
	case -64:
	case -46:
	case -34:
	case -22:
	case -2:
	case 10:
	case 48:
	case 68:
	case 116:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	case 12:
		sub_02A225(x);
		break;
	case 14:
		sub_02A234(x, 0u);
		break;
	case 16:
		sub_02A258(x);
		break;
	case 18:
	case 28:
		sub_02A26A(x);
		break;
	case 20:
		sub_02A28E(x);
		break;
	case 22:
		sub_02A29D(x);
		break;
	case 24:
		sub_02A2AE(x);
		break;
	case 26:
		sub_02A2C2(x);
		break;
	case -12:
		y = sub_02A1CA(x);
		break;
	case -10:
		sub_02A1E3(x);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_02A036(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02BE19_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02B0AF(x, &y, &u);
		break;
	case 2:
		sub_02B0D9(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_02A039(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02BDFD_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02AFF8(x, &y, &u);
		break;
	case 2:
		u = sub_02B022(x);
		break;
	case 4:
		sub_02B050(x);
		break;
	case 6:
		sub_02B07A(x);
		break;
	case 8:
		sub_02B08A(x);
		break;
	case 10:
		sub_02B098(x);
		break;
	case 12:
		sub_02B021();
		break;
	}
	carry = sub_078683(x, carry);
	*p_y = y;
	*p_u = u;
}

void sub_02A03C(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02BDB0_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02AF36(x, &y, &u);
		break;
	case 2:
		sub_02AF6E(x);
		break;
	case 4:
		sub_02AF7A(x, &y, &u);
		break;
	case 6:
		sub_02AFBE(x);
		break;
	case 8:
		sub_02AFD5(x);
		break;
	case 10:
		sub_02AFE3(x);
		break;
	}
	carry = sub_078683(x, carry);
	*p_y = y;
	*p_u = u;
}

void sub_02A03F(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
	case 20:
		y = sub_02A334(x);
		break;
	case 2:
		y = sub_02A2E5(x, y);
		break;
	case -108:
	case -90:
	case -78:
	case -66:
	case -46:
	case -34:
	case 4:
	case 24:
	case 72:
	case 88:
	case 114:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case -106:
	case -88:
	case -76:
	case -64:
	case -44:
	case -32:
	case 6:
	case 26:
	case 74:
	case 90:
	case 116:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case -104:
	case -86:
	case -74:
	case -62:
	case -42:
	case -30:
	case 8:
	case 28:
	case 76:
	case 92:
	case 118:
		sub_0785E1(x, &y, &ignored16, &ignored);
		break;
	case -102:
	case -84:
	case -72:
	case -60:
	case -40:
	case -28:
	case 10:
	case 30:
	case 78:
	case 94:
	case 120:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	case 12:
		sub_02A2EE(x);
		break;
	case 14:
	case 62:
		sub_02A398(x);
		break;
	case 16:
		sub_02A2FC(x);
		break;
	case 18:
	case 66:
		sub_02A62C(x);
		break;
	case 22:
		y = sub_02A359(x, y);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_02A042(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02BD96_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02AEA5(x, &y, &u);
		break;
	case 2:
		sub_02AEB9(x);
		break;
	case 4:
		sub_02AECE(x, &y, &u);
		break;
	case 6:
		u = sub_02AF03(x, u);
		break;
	case 8:
		sub_02AF1D(x);
		break;
	case 10:
		sub_02AF2C();
		break;
	}
	carry = sub_078683(x, carry);
	*p_y = y;
	*p_u = u;
}

void sub_02A045(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02BD80_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02AE76(x, &y, &u);
		break;
	case 2:
		sub_02AE85();
		break;
	case 4:
		sub_02AE86(x, &y, &u);
		break;
	case 6:
		sub_02AE9B();
		break;
	}
	carry = sub_078683(x, carry);
	*p_y = y;
	*p_u = u;
}

void sub_02A048(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		y = sub_02A1CA(x);
		break;
	case 2:
		sub_02A1E3(x);
		break;
	case -58:
	case -40:
	case -28:
	case -16:
	case 4:
	case 16:
	case 54:
	case 74:
	case 122:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case -56:
	case -38:
	case -26:
	case -14:
	case 6:
	case 18:
	case 56:
	case 76:
	case 124:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case -54:
	case -36:
	case -24:
	case -12:
	case 8:
	case 20:
	case 58:
	case 78:
	case 126:
		sub_0785E1(x, &y, &ignored16, &ignored);
		break;
	case -52:
	case -34:
	case -22:
	case -10:
	case 10:
	case 22:
	case 60:
	case 80:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	case 12:
		y = sub_02A205(x);
		break;
	case 14:
		y = sub_02A21B(x, y);
		break;
	case 24:
		sub_02A225(x);
		break;
	case 26:
		sub_02A234(x, 0u);
		break;
	case 28:
		sub_02A258(x);
		break;
	case 30:
	case 40:
		sub_02A26A(x);
		break;
	case 32:
		sub_02A28E(x);
		break;
	case 34:
		sub_02A29D(x);
		break;
	case 36:
		sub_02A2AE(x);
		break;
	case 38:
		sub_02A2C2(x);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_02A04B(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02B98D_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		u = sub_02AA5C(x);
		break;
	case 2:
		sub_02AA94(x, &y, &u);
		break;
	case 4:
		u = sub_02AB52(x);
		break;
	case 6:
		u = sub_02ABB0(x);
		break;
	case -20:
		u = sub_02A9B0(x);
		break;
	case -18:
		sub_02AA04(x);
		break;
	case -16:
		y = sub_02AA15(x, y);
		break;
	case -14:
	case -4:
		y = sub_02A906(x);
		break;
	case -12:
	case -2:
		sub_02A90F(x);
		break;
	case -10:
		sub_02AA2C();
		break;
	case -8:
		sub_02AA33(x);
		break;
	case -6:
		y = sub_02AA3F(x, y);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_02A04E(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		y = sub_02A13C(x);
		break;
	case -14:
	case 4:
	case 16:
	case 28:
	case 48:
	case 60:
	case 98:
	case 118:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case -12:
	case 6:
	case 18:
	case 30:
	case 50:
	case 62:
	case 100:
	case 120:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case -10:
	case 8:
	case 20:
	case 32:
	case 52:
	case 64:
	case 102:
	case 122:
		sub_0785E1(x, &y, &ignored16, &ignored);
		break;
	case -8:
	case 10:
	case 22:
	case 34:
	case 54:
	case 66:
	case 104:
	case 124:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	case 12:
		y = sub_02A188(x);
		break;
	case 24:
		y = sub_02A1B1(x);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_02A051(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		y = sub_02A0B8(x);
		break;
	case 4:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case 6:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case 8:
		sub_0785E1(x, &y, &ignored16, &ignored);
		break;
	case 10:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_02A054(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		y = sub_02ABCC(x);
		break;
	case 2:
		y = sub_02AC15(x, y);
		break;
	case 4:
	case 24:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case 6:
	case 26:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case 8:
	case 28:
		sub_0785FC(x, &y, &ignored16);
		break;
	case 10:
	case 30:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_02A057(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		y = sub_02AC7C(x);
		break;
	case 2:
		y = sub_02ACC0(x, y);
		break;
	case -16:
	case 4:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case -14:
	case 6:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case -12:
	case 8:
		sub_0785FC(x, &y, &ignored16);
		break;
	case -10:
	case 10:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	case -4:
		sub_02AC1E(x);
		break;
	case -2:
		sub_02AC5D(x, 0u);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_02A05A(uint16_t x, uint8_t d)
{
	uint8_t b = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02AD71(x);
		return;
	case 2:
		sub_02AD74(x);
		return;
	case 4:
		sub_02AD8F(x);
		return;
	case 6:
		sub_02ADB8(x);
		return;
	case 8:
		sub_02AE21(x);
		return;
	case 10:
		sub_02AE31(x);
		return;
	}
}

void sub_02A05D(uint16_t x, uint8_t d)
{
	uint8_t b = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02AD8F(x);
		break;
	case 2:
		sub_02ADB8(x);
		break;
	case 4:
		sub_02AE21(x);
		break;
	case 6:
		sub_02AE31(x);
		break;
	case -4:
		sub_02AD71(x);
		break;
	case -2:
		sub_02AD74(x);
		break;
	}
	unk_48A7--;
}

void sub_02A060(uint16_t x, uint8_t d)
{
	uint8_t b = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02AD21(x);
		return;
	case 2:
		sub_02AD47(x, 0u, 0u);
		return;
	case -4:
		sub_02ACC9(x);
		return;
	case -2:
		sub_02AD08(x, 0u);
		return;
	}
}

void sub_02A063(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint16_t t1 = 0;

	u = loaded_table_02BEA1_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)d << 1))
	{
	case 0:
		sub_02B211(x, &y, &u);
		break;
	case 2:
		sub_02B23A(x);
		break;
	}
	t1 = mem_read16(x + 0x16u);
	if ((uint16_t)(t1 + 0x80u) >= 0x120u)
		mem_write8(x, 0u);
	*p_y = y;
	*p_u = u;
}

void sub_02A066(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02BE53_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02B0EB(x, &y, &u);
		break;
	case 2:
		sub_02B0FE();
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_02A069(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02BE5D_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02B105(x, &y, &u);
		break;
	case 2:
		sub_02B131(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_02A06C(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02BE6F_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02B146(x, &y, &u);
		break;
	case 2:
		sub_02B15A(x);
		break;
	case 4:
		sub_02B16F(x);
		break;
	case 6:
		sub_02B18E(x);
		break;
	case 8:
		sub_02B159();
		break;
	}
	carry = sub_078683(x, carry);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_02A06F(uint16_t x, uint32_t y, uint8_t d)
{
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02BE7F_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		return sub_02B1A4(x);
	case 2:
		sub_02B1DA(x);
		return u;
	}
	unreachable();
}

void sub_02A072(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02BEDF_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02B24A(x, &y, &u);
		break;
	case 2:
		sub_02B283(x, &y, &u);
		break;
	case 4:
		sub_02B282();
		break;
	}
	carry = sub_078683(x, carry);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_02A075(uint16_t x, uint32_t y, uint8_t d)
{
	uint8_t b = 0;
	uint16_t ignored16 = 0, u = 0;
	uint8_t t2 = 0, t3 = 0;
	uint16_t t1 = 0;

	b = (uint8_t)d;
	u = 0x7F37u;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02B392(x, &ignored16, &u);
		break;
	case 2:
		sub_02B3C5(x);
		break;
	case 4:
		u = sub_02B3E4(x, u);
		break;
	case 6:
		sub_02B3C4();
		break;
	case -8:
		sub_02B32E(x);
		break;
	case -6:
		sub_02B31B(x);
		break;
	case -4:
	case -2:
		sub_02B325(x, &ignored16, &u);
		break;
	}
	u = sub_02B400(x, u);
	sub_02B33B(x);
	u = sub_078593(x, u);
	t1 = mem_read16(x + 0xCu);
	if (t1 >= 0x1C0u)
		mem_write8(x, 0u);
	t2 = mem_read8(x + 2u);
	if ((int8_t)t2 < 0)
		return u;
	t3 = mem_read8(x + 0x3Bu);
	if ((t3 & 3u) != 0u)
	{
		mem_write16(x + 0x1Cu, 0u);
		return u;
	}
	mem_write16(x + 0x1Cu, 0x201u);
	return u;
}

void sub_02A078(void)
{
}

void sub_02A07B(void)
{
}

void sub_02A07E(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		y = sub_02A188(x);
		break;
	case -26:
	case -8:
	case 4:
	case 16:
	case 36:
	case 48:
	case 86:
	case 106:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case -24:
	case -6:
	case 6:
	case 18:
	case 38:
	case 50:
	case 88:
	case 108:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case -22:
	case -4:
	case 8:
	case 20:
	case 40:
	case 52:
	case 90:
	case 110:
		sub_0785E1(x, &y, &ignored16, &ignored);
		break;
	case -20:
	case -2:
	case 10:
	case 22:
	case 42:
	case 54:
	case 92:
	case 112:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	case 12:
		y = sub_02A1B1(x);
		break;
	case -12:
		y = sub_02A13C(x);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_02A081(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = 0x7944u;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02A7DF(x);
		break;
	case 2:
		sub_02A802(x);
		break;
	case 4:
		sub_02A811(x);
		break;
	case 6:
		y = sub_02A824(x, y);
		break;
	case 8:
		y = sub_02A856(x, y);
		break;
	case 10:
		sub_02A87A(x);
		break;
	case 12:
		sub_02A887(x);
		break;
	case 14:
		u = sub_02A8AB(x, u);
		break;
	case 16:
		sub_02A8E7(x);
		break;
	case 18:
		y = sub_02A8F5(x, y);
		break;
	case 20:
	case 44:
		y = sub_02A906(x);
		break;
	case 22:
	case 46:
		sub_02A90F(x);
		break;
	case 24:
		sub_02A91F(x);
		break;
	case 26:
		sub_02A92A(x);
		break;
	case 28:
		y = sub_02A95A(x, y);
		break;
	case 30:
		sub_02A986(x);
		break;
	case 32:
		sub_02A9A1(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_02A084(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02BD6C_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02AE47(x, &y, &u);
		break;
	case 2:
		sub_02AE5B(x, &y, &u);
		break;
	case 4:
		sub_02AE5A();
		break;
	}
	carry = sub_078683(x, carry);
	*p_y = y;
	*p_u = u;
}

void sub_02A093(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0;

	u = object_setup_02B64C_ADDRESS;
	y = sub_0785AB(x, u);
	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, t1 | 0x40u);
	mem_write8(x + 0x42u, 2u);
	u = sub_078620(x);
	sub_078626(x, u);
	u = enemy_behaviour_02B5E8_ADDRESS;
	mem_write16(x + 0x2Au, enemy_behaviour_02B5E8_ADDRESS);
	mem_write8(x + 0x3Au, 0x10u);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_02A0B8(uint16_t x)
{
	uint16_t ignored16 = 0, y = 0;
	uint8_t t1 = 0;

	sub_02A093(x, &y, &ignored16);
	t1 = mem_read8(x + 0x30u);
	if (t1 != 0u)
		mem_write8(x + 0x1Bu, 8u);
	mem_write8(x + 0x30u, 0u);
	mem_write8(x + 2u, 2u);
	return y;
}

void unused_02A0CD(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	u = object_setup_02B64C_ADDRESS;
	sub_0785AB(x, u);
	t1 = mem_read8(x + 0x42u);
	if ((int8_t)t1 >= 0)
	{
		t2 = mem_read16(x + 0x38u);
		u = t2;
		sub_07859F(x, u);
	}
	mem_write8(x + 0x42u, 2u);
	mem_write16(x + 0x2Au, enemy_behaviour_02B5E8_ADDRESS);
	mem_write8(x + 0x3Au, 0x10u);
	mem_write8(x + 0x30u, 0u);
	mem_write8(x + 0x3Bu, 0u);
	mem_write16(x + 1u, 0xE02u);
}

void sub_02A107(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;

	y = sub_02A149(x);
	u = enemy_behaviour_02B65A_ADDRESS;
	mem_write16(x + 0x2Au, enemy_behaviour_02B65A_ADDRESS);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_02A110(uint16_t x)
{
	uint16_t ignored16 = 0, y = 0;
	uint8_t t1 = 0;

	sub_02A107(x, &y, &ignored16);
	sub_02A168(x);
	t1 = mem_read8(x + 0x30u);
	if (t1 != 0u)
		mem_write8(x + 0x1Bu, 8u);
	mem_write8(x + 0x30u, 0u);
	mem_write8(x + 2u, 2u);
	return y;
}

void sub_02A133(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;

	y = sub_02A149(x);
	u = enemy_behaviour_02B6B2_ADDRESS;
	mem_write16(x + 0x2Au, enemy_behaviour_02B6B2_ADDRESS);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_02A13C(uint16_t x)
{
	uint16_t ignored16 = 0, y = 0;

	sub_02A133(x, &y, &ignored16);
	sub_02A168(x);
	mem_write8(x + 0x30u, 0u);
	mem_write8(x + 2u, 2u);
	return y;
}

uint16_t sub_02A149(uint16_t x)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0;

	u = object_setup_02B7C6_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x + 0x3Au, 0x10u);
	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, t1 | 0x40u);
	mem_write8(x + 0x42u, 2u);
	u = sub_078620(x);
	sub_078626(x, u);
	return y;
}

void sub_02A168(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x30u);
	if (t1 != 0u)
		mem_write8(x + 0x1Bu, 8u);
}

void sub_02A17F(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;

	y = sub_02A149(x);
	u = enemy_behaviour_02B70A_ADDRESS;
	mem_write16(x + 0x2Au, enemy_behaviour_02B70A_ADDRESS);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_02A188(uint16_t x)
{
	uint16_t ignored16 = 0, y = 0;

	sub_02A17F(x, &y, &ignored16);
	sub_02A168(x);
	mem_write8(x + 0x30u, 0u);
	mem_write8(x + 2u, 2u);
	return y;
}

void sub_02A1A1(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;

	y = sub_02A149(x);
	sub_02A168(x);
	mem_write8(x + 4u, 0x85u);
	u = enemy_behaviour_02B762_ADDRESS;
	mem_write16(x + 0x2Au, enemy_behaviour_02B762_ADDRESS);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_02A1B1(uint16_t x)
{
	uint16_t ignored16 = 0, y = 0;

	sub_02A1A1(x, &y, &ignored16);
	sub_02A168(x);
	mem_write8(x + 0x30u, 0u);
	mem_write8(x + 2u, 2u);
	return y;
}

uint16_t sub_02A1CA(uint16_t x)
{
	uint16_t ignored16 = 0, y = 0;
	uint8_t t1 = 0;

	sub_02A093(x, &y, &ignored16);
	mem_write8(x + 5u, 0xB3u);
	mem_write8(x + 0x57u, 1u);
	mem_write8(x + 0x30u, 0u);
	mem_write8(x + 0x3Au, 0x10u);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	return y;
}

void sub_02A1E3(uint16_t x)
{
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	if ((mem_read8(x) & 0x20u) == 0u)
	{
		t1 = mem_read16(x + 0xCu);
		if (t1 < 0x100u)
		{
			mem_write8(x + 0x57u, 0u);
			t2 = mem_read8(x + 2u);
			mem_write8(x + 2u, t2 + 1u);
		}
		return;
	}
	mem_write8(x + 0x57u, 0u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
}

uint16_t sub_02A205(uint16_t x)
{
	uint16_t ignored16 = 0, y = 0;
	uint8_t t1 = 0;

	sub_02A093(x, &y, &ignored16);
	mem_write8(x, 0x80u);
	mem_write8(x + 9u, 0x20u);
	mem_write8(x + 5u, 0xB3u);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	return y;
}

uint16_t sub_02A21B(uint16_t x, uint16_t y)
{
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		t1 = mem_read8(x + 0x29u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			sub_02A225(x);
			return y;
		case 2:
			sub_02A234(x, 0u);
			return y;
		case 4:
			sub_02A258(x);
			return y;
		case 6:
		case 16:
			sub_02A26A(x);
			return y;
		case 8:
			sub_02A28E(x);
			return y;
		case 10:
			sub_02A29D(x);
			return y;
		case 12:
			sub_02A2AE(x);
			return y;
		case 14:
			break;
		case -82:
		case -64:
		case -52:
		case -40:
		case -20:
		case -8:
		case 30:
		case 50:
		case 98:
		case 114:
			sub_0785DB(x, &y, &ignored16, &ignored);
			return y;
		case -80:
		case -62:
		case -50:
		case -38:
		case -18:
		case -6:
		case 32:
		case 52:
		case 100:
		case 116:
			sub_0785DE(x, &y, &ignored16, &ignored);
			return y;
		case -78:
		case -60:
		case -48:
		case -36:
		case -16:
		case -4:
		case 34:
		case 54:
		case 102:
		case 118:
			sub_0785E1(x, &y, &ignored16, &ignored);
			return y;
		case -76:
		case -58:
		case -46:
		case -34:
		case -14:
		case -2:
		case 36:
		case 56:
		case 104:
		case 120:
			sub_0785E4(x, &y, &ignored16, &ignored);
			return y;
		case -24:
			return sub_02A1CA(x);
		case -22:
			sub_02A1E3(x);
			return y;
		case -12:
			return sub_02A205(x);
		case -10:
			continue;
		}
		break;
	}
	sub_02A2C2(x);
	return y;
}

void sub_02A225(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write16(x + 0x19u, 0xFF00u);
	mem_write8(x + 0x3Bu, 0x60u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

void sub_02A234(uint16_t x, uint32_t u)
{
	uint8_t d = 0;
	uint16_t fat_goon_drop_route = 0;
	uint8_t t1 = 0, t2 = 0, wait = 0;
	uint16_t next_step = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(x + 0x19u, 0u);
		t2 = mem_read8(x + 0x30u);
		fat_goon_drop_route = fat_goon_drop_routes_ADDRESS + (int8_t)(((uint32_t)t2 << 1) << 1);
		next_step = (((uint32_t)FAT_GOON_DROP_ROUTE(fat_goon_drop_route)->next_step << 8u) | FAT_GOON_DROP_ROUTE(fat_goon_drop_route)->floor);
		d = (uint8_t)next_step;
		mem_write8(x + 0x29u, next_step >> 8);
		mem_write8(x + 0x3Du, d);
		mem_write8(x + 0x5Du, d);
		wait = FAT_GOON_DROP_ROUTE(fat_goon_drop_route)->wait;
		mem_write8(x + VIDEO_003C, wait);
	}
}

void sub_02A258(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write16(x + 0xFu, 0xFF80u);
	mem_write16(x + 0x14u, 0xFF80u);
	mem_write8(x + 5u, 0x91u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

void sub_02A26A(uint16_t x)
{
	uint32_t negative = 0;
	uint8_t a = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	d = 0u;
	sub_078638(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	t1 = mem_read8(x + 0x3Du);
	if ((uint8_t)((((a & 0xFu) << 1) << 1) << 1) != t1)
	{
		t2 = mem_read8(x + VIDEO_003C);
		mem_write8(x + VIDEO_003C, t2 - 1u);
		if (t2 == 1u)
			mem_write8(x + 9u, 0x10u);
		return;
	}
	mem_write8(x + 0x30u, 0u);
	mem_write8(x, 0xC0u);
	mem_write8(x + 2u, 2u);
	mem_write8(x + 0x3Bu, 0u);
}

void sub_02A28E(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write16(x + 0xFu, 0x80u);
	mem_write8(x + 0x3Bu, 0x20u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

void sub_02A29D(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(x + 0xFu, 0u);
		mem_write8(x + 0x3Bu, 0x60u);
		t2 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t2 + 1u);
	}
}

void sub_02A2AE(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(x + 0x19u, 0xFF00u);
		mem_write8(x + 0x3Bu, 0x60u);
		t2 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t2 + 1u);
	}
}

void sub_02A2C2(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(x + 0x14u, 0xFF80u);
		mem_write16(x + 0x19u, 0u);
		mem_write8(x + 5u, 0x91u);
		t2 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t2 + 1u);
	}
}

uint16_t sub_02A2E5(uint16_t x, uint16_t y)
{
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		t1 = mem_read8(x + 0x29u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			sub_02A2EE(x);
			return y;
		case 2:
		case 50:
			sub_02A398(x);
			return y;
		case 4:
			sub_02A2FC(x);
			return y;
		case 6:
		case 54:
			sub_02A62C(x);
			return y;
		case -12:
		case 8:
			return sub_02A334(x);
		case 10:
			break;
		case -120:
		case -102:
		case -90:
		case -78:
		case -58:
		case -46:
		case -8:
		case 12:
		case 60:
		case 76:
		case 102:
			sub_0785DB(x, &y, &ignored16, &ignored);
			return y;
		case -118:
		case -100:
		case -88:
		case -76:
		case -56:
		case -44:
		case -6:
		case 14:
		case 62:
		case 78:
		case 104:
			sub_0785DE(x, &y, &ignored16, &ignored);
			return y;
		case -116:
		case -98:
		case -86:
		case -74:
		case -54:
		case -42:
		case -4:
		case 16:
		case 64:
		case 80:
		case 106:
			sub_0785E1(x, &y, &ignored16, &ignored);
			return y;
		case -114:
		case -96:
		case -84:
		case -72:
		case -52:
		case -40:
		case -2:
		case 18:
		case 66:
		case 82:
		case 108:
			sub_0785E4(x, &y, &ignored16, &ignored);
			return y;
		case -10:
			continue;
		}
		break;
	}
	return sub_02A359(x, y);
}

void sub_02A2EE(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x, 0x80u);
	mem_write8(x + 9u, 0x10u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

void sub_02A2FC(uint16_t x)
{
	uint32_t negative = 0;
	uint8_t a = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	d = 0u;
	sub_078638(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	if ((int8_t)a >= 0)
	{
		unk_48F1 = a;
		mem_write8(x + 0x47u, a);
		unk_48F0 = a & 0x30u;
		t1 = mem_read8(x + 9u);
		mem_write8(x + 9u, (t1 & 0xCFu) | unk_48F0);
		mem_write8(x + 0x5Du, (((unk_48F1 & 0xFu) << 1) << 1) << 1);
		t2 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t2 + 1u);
	}
}

uint16_t sub_02A334(uint16_t x)
{
	uint16_t ignored16 = 0, y = 0;
	uint8_t t1 = 0, t2 = 0;
	uint16_t wait = 0;

	sub_02A093(x, &y, &ignored16);
	mem_write8(x, 0x80u);
	mem_write8(x + 5u, 0x91u);
	t1 = mem_read8(x + 0x30u);
	wait = (((uint32_t)GOON_ENTRANCE(fat_goon_entrances_ADDRESS + (int8_t)((uint32_t)t1 << 1))->wait << 8u) | GOON_ENTRANCE(fat_goon_entrances_ADDRESS + (int8_t)((uint32_t)t1 << 1))->attributes);
	mem_write8(x + VIDEO_003C, wait >> 8);
	mem_write8(x + 9u, wait);
	mem_write8(x + 0x3Bu, 8u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	return y;
}

uint16_t sub_02A359(uint16_t x, uint16_t y)
{
	uint16_t ignored16 = 0, y_2 = 0;
	uint32_t ignored = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_02A362(x);
		return y;
	case 2:
		sub_02A376(x);
		return y;
	case 4:
		sub_02A384(x);
		return y;
	case -42:
	case 6:
		sub_02A398(x);
		return y;
	case 8:
	case 112:
		sub_02A5FC(x);
		return y;
	case -38:
	case 10:
	case 114:
		sub_02A62C(x);
		return y;
	case 12:
		sub_02A3B3(x, &y_2, &ignored16);
		return y_2;
	case 14:
		sub_02A3C3(x, &y, &ignored16);
		return y;
	case -122:
	case -102:
	case -90:
	case -52:
	case -32:
	case 16:
	case 32:
	case 58:
	case 86:
	case 120:
		sub_0785DB(x, &y, &ignored16, &ignored);
		return y;
	case -120:
	case -100:
	case -88:
	case -50:
	case -30:
	case 18:
	case 34:
	case 60:
	case 88:
	case 122:
		sub_0785DE(x, &y, &ignored16, &ignored);
		return y;
	case -118:
	case -98:
	case -86:
	case -48:
	case -28:
	case 20:
	case 36:
	case 62:
	case 90:
	case 124:
		sub_0785E1(x, &y, &ignored16, &ignored);
		return y;
	case -128:
	case -116:
	case -96:
	case -84:
	case -46:
	case -26:
	case 22:
	case 38:
	case 64:
	case 92:
	case 126:
		sub_0785E4(x, &y, &ignored16, &ignored);
		return y;
	case 24:
		sub_02A3F2(x);
		return y;
	case 26:
		sub_02A40D(x, 0u);
		return y;
	case 28:
		sub_02A431(x, &y_2, &ignored16);
		return y_2;
	case 30:
		sub_02A454(x, &y, &ignored16);
		return y;
	case 40:
		sub_02A45D(x);
		return y;
	case 42:
		sub_02A47E(x, 0u);
		return y;
	case 44:
		sub_02A4A2(x, 0u);
		return y;
	}
	unreachable();
}

void sub_02A362(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 0x30u);
	if ((int8_t)t1 >= 0)
	{
		mem_write8(x + 0x29u, 3u);
		return;
	}
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
}

void sub_02A376(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + VIDEO_003C);
	mem_write8(x + VIDEO_003C, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 5u, 0xB1u);
		t2 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t2 + 1u);
	}
}

void sub_02A384(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		mem_write8(x + VIDEO_003C, 1u);
		mem_write8(x + 5u, 0x91u);
		t2 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t2 + 1u);
	}
}

void sub_02A398(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + VIDEO_003C);
	mem_write8(x + VIDEO_003C, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(x + 0x14u, 0xFF00u);
		t2 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t2 + 1u);
	}
}

void sub_02A3B3(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0;

	sub_02A093(x, &y, &u);
	t1 = mem_read8(x + 0x30u);
	mem_write8(x + 0x3Bu, t1);
	mem_write8(x + 0x30u, 0u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_02A3C3(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t negative = 0;
	uint8_t a = 0;
	uint16_t d = 0, u = 0;
	uint32_t ignored = 0;
	uint8_t t1 = 0, t2 = 0;

	u = loaded_table_02B87A_ADDRESS;
	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_02A3F2(x);
		break;
	case 2:
		u = sub_02A40D(x, u);
		break;
	case 4:
		sub_02A431(x, &y, &u);
		break;
	case 6:
		sub_02A454(x, &y, &u);
		break;
	case -126:
	case -114:
	case -76:
	case -56:
	case -8:
	case 8:
	case 34:
	case 62:
	case 96:
		sub_0785DB(x, &y, &u, &ignored);
		break;
	case -124:
	case -112:
	case -74:
	case -54:
	case -6:
	case 10:
	case 36:
	case 64:
	case 98:
		sub_0785DE(x, &y, &u, &ignored);
		break;
	case -122:
	case -110:
	case -72:
	case -52:
	case -4:
	case 12:
	case 38:
	case 66:
	case 100:
		sub_0785E1(x, &y, &u, &ignored);
		break;
	case -120:
	case -108:
	case -70:
	case -50:
	case -2:
	case 14:
	case 40:
	case 68:
	case 102:
		sub_0785E4(x, &y, &u, &ignored);
		break;
	case 16:
		u = sub_02A45D(x);
		break;
	case 18:
		u = sub_02A47E(x, u);
		break;
	case 20:
		u = sub_02A4A2(x, u);
		break;
	case -16:
	case 88:
		sub_02A5FC(x);
		break;
	case -62:
	case -14:
	case 90:
		sub_02A62C(x);
		break;
	case -66:
	case -18:
		sub_02A398(x);
		break;
	case -24:
		sub_02A362(x);
		break;
	case -22:
		sub_02A376(x);
		break;
	case -20:
		sub_02A384(x);
		break;
	case -12:
		sub_02A3B3(x, &y, &u);
		break;
	case -10:
		sub_02A3C3(x, &y, &u);
		break;
	}
	d = 0u;
	sub_078638(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	if ((int8_t)a >= 0)
	{
		unk_48F1 = a;
		unk_48F0 = a & 0x30u;
		t2 = mem_read8(x + 9u);
		mem_write8(x + 9u, (t2 & 0xCFu) | unk_48F0);
		mem_write8(x + 0x5Du, (((unk_48F1 & 0xFu) << 1) << 1) << 1);
	}
	*p_y = y;
	*p_u = u;
}

void sub_02A3F2(uint16_t x)
{
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	mem_write8(x + 5u, 0x90u);
	mem_write16(x + 0xFu, 0x200u);
	t1 = mem_read8(x + 0x36u);
	if ((int8_t)(t1 - 0x40u) >= 0)
	{
		t2 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t2);
	}
	t3 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t3 + 1u);
	sub_0785C9(x);
}

uint16_t sub_02A40D(uint16_t x, uint16_t u)
{
	uint16_t d = 0, u_2 = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return u;
	u_2 = sub_078620(x);
	sub_078626(x, u_2);
	t2 = mem_read8(x + 0x36u);
	d = (uint32_t)t2 << 8;
	u_2 = sub_07866B(x, u_2, d);
	sub_0785C9(x);
	mem_write8(x + 2u, 2u);
	mem_write8(x + 0x3Bu, 0u);
	return u_2;
}

void sub_02A431(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t ignored16 = 0, u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0;

	sub_02A093(x, &y, &ignored16);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	mem_write8(x + 5u, 0x83u);
	mem_write8(x, 0x80u);
	t2 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t2 & 0xCFu) | 0x10u);
	u = sub_078620(x);
	sub_078626(x, u);
	sub_0785C9(x);
	*p_y = y;
	*p_u = u;
}

void sub_02A454(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint32_t ignored = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_02B88A_ADDRESS;
		t1 = mem_read8(x + 0x29u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			u = sub_02A45D(x);
			break;
		case 2:
			u = sub_02A47E(x, u);
			break;
		case 4:
			u = sub_02A4A2(x, u);
			break;
		case -92:
		case -72:
		case -24:
		case -8:
		case 18:
		case 46:
		case 80:
			sub_0785DB(x, &y, &u, &ignored);
			break;
		case -128:
		case -90:
		case -70:
		case -22:
		case -6:
		case 20:
		case 48:
		case 82:
			sub_0785DE(x, &y, &u, &ignored);
			break;
		case -126:
		case -88:
		case -68:
		case -20:
		case -4:
		case 22:
		case 50:
		case 84:
			sub_0785E1(x, &y, &u, &ignored);
			break;
		case -124:
		case -86:
		case -66:
		case -18:
		case -2:
		case 24:
		case 52:
		case 86:
			sub_0785E4(x, &y, &u, &ignored);
			break;
		case -32:
		case 72:
			sub_02A5FC(x);
			break;
		case -78:
		case -30:
		case 74:
			sub_02A62C(x);
			break;
		case -82:
		case -34:
			sub_02A398(x);
			break;
		case -40:
			sub_02A362(x);
			break;
		case -38:
			sub_02A376(x);
			break;
		case -36:
			sub_02A384(x);
			break;
		case -28:
			sub_02A3B3(x, &y, &u);
			break;
		case -26:
			sub_02A3C3(x, &y, &u);
			break;
		case -16:
			sub_02A3F2(x);
			break;
		case -14:
			u = sub_02A40D(x, u);
			break;
		case -12:
			sub_02A431(x, &y, &u);
			break;
		case -10:
			continue;
		}
		break;
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_02A45D(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	mem_write8(x, 0x80u);
	u = fat_goon_from_back_xs_ADDRESS;
	t1 = mem_read8(x + 0x30u);
	t2 = fat_goon_from_back_xs[(int8_t)((uint8_t)((uint32_t)t1 << 1)) / 2];
	mem_write16(x + 0xCu, t2);
	mem_write16(x + 0x11u, 0x40u);
	mem_write16(x + 0x14u, 0x100u);
	t3 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t3 + 1u);
	return u;
}

uint16_t sub_02A47E(uint16_t x, uint16_t u)
{
	uint32_t negative = 0;
	uint8_t a = 0;
	uint16_t d = 0, u_2 = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	d = 0u;
	sub_078638(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	if ((int8_t)a >= 0)
	{
		mem_write8(x + 0x47u, a);
		mem_write8(x + 0x5Du, (((a & 0xFu) << 1) << 1) << 1);
		mem_write8(x + 0x30u, 0u);
		mem_write8(x, 0xC0u);
		mem_write8(x + 0x3Bu, 0x20u);
		t1 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t1 + 1u);
	}
	if ((unk_4815 & 7u) != 0u)
		return u;
	t2 = mem_read16(x + 0x38u);
	u_2 = t2;
	sub_078626(x, u_2);
	sub_0785C9(x);
	return u_2;
}

uint16_t sub_02A4A2(uint16_t x, uint16_t u)
{
	uint16_t u_2 = 0;
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
	{
		if ((unk_4815 & 7u) != 0u)
			return u;
		t2 = mem_read16(x + 0x38u);
		u_2 = t2;
		sub_078626(x, u_2);
		sub_0785C9(x);
		return u_2;
	}
	t3 = mem_read8(x + 2u);
	mem_write8(x + 2u, t3 + 1u);
	return u;
}

void sub_02A4D6(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint32_t negative = 0;
	uint8_t a = 0;
	uint16_t d = 0, u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x30u);
	mem_write8(x + VIDEO_003C, t1);
	sub_02A093(x, &y, &u);
	mem_write8(x + 5u, 0xA6u);
	d = 0u;
	sub_078638(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	mem_write8(x + 0x45u, a);
	mem_write8(x + 0x30u, 0u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_02A4F2(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t negative = 0;
	uint8_t a = 0;
	uint16_t d = 0, u = 0;
	uint32_t ignored = 0;
	uint8_t t1 = 0, t2 = 0;

	u = loaded_table_02B8A4_ADDRESS;
	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_02A4FE(x, &y, &u);
		break;
	case 2:
		u = sub_02A535(x);
		break;
	case 4:
		u = sub_02A5C5(x, u);
		break;
	case 6:
		sub_02A5F3(x);
		break;
	case -118:
	case -98:
	case -50:
	case -34:
	case -8:
	case 20:
	case 54:
		sub_0785DB(x, &y, &u, &ignored);
		break;
	case -116:
	case -96:
	case -48:
	case -32:
	case -6:
	case 22:
	case 56:
		sub_0785DE(x, &y, &u, &ignored);
		break;
	case -114:
	case -94:
	case -46:
	case -30:
	case -4:
	case 24:
	case 58:
		sub_0785E1(x, &y, &u, &ignored);
		break;
	case -112:
	case -92:
	case -44:
	case -28:
	case -2:
	case 26:
	case 60:
		sub_0785E4(x, &y, &u, &ignored);
		break;
	case -12:
		sub_02A4D6(x, &y, &u);
		break;
	case -10:
		sub_02A4F2(x, &y, &u);
		break;
	}
	sub_07863B(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	t2 = mem_read8(x + 0x45u);
	if (a != t2)
	{
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
	}
	*p_y = y;
	*p_u = u;
}

void sub_02A4FE(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint32_t carry = 0;
	uint8_t a = 0, d = 0;
	uint16_t ignored16 = 0, u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	mem_write8(x + 0x3Bu, 0x40u);
	t1 = mem_read8(x + 0x36u);
	if ((int8_t)(t1 - 0x40u) < 0)
	{
		d = 0u;
		a = 2u;
	}
	else
	{
		d = 0u;
		a = 0xFFu;
	}
	mem_write16(x + 0xFu, (uint32_t)a << 8);
	y = child_object_02B8AC_ADDRESS;
	sub_07862C(x, y, &u, &ignored16, &carry);
	if (carry == 0u)
	{
		mem_write8(x + 2u, 2u);
		mem_write8(x + 0x3Bu, 0u);
	}
	else
	{
		mem_write16(x + 0x40u, u);
		t2 = mem_read8(x + VIDEO_003C);
		mem_write8(u + 0x30u, t2);
		mem_write8(u + 0x3Du, 1u);
		mem_write8(x + VIDEO_003C, 8u);
		t3 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t3 + 1u);
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_02A535(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t9 = 0;
	uint16_t t1 = 0, t7 = 0, t8 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0, t15 = 0, t16 = 0, t17 = 0;

	t1 = mem_read16(x + 0x40u);
	u = t1;
	mem_write8(u + 0x3Du, 1u);
	t2 = mem_read8(u + 2u);
	if ((int8_t)t2 < 0)
	{
		mem_write8(x + 2u, 4u);
		mem_write16(x + 0x28u, 0u);
		return u;
	}
	u = sub_078620(x);
	sub_078626(x, u);
	t3 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t3 - 1u);
	if (t3 == 1u)
	{
		mem_write8(x + 0x3Bu, 0x10u);
		t4 = mem_read8(x + VIDEO_003C);
		mem_write8(x + VIDEO_003C, t4 - 1u);
		if (t4 == 1u)
		{
			mem_write8(x + 5u, 0xA7u);
			mem_write8(x + 0x3Bu, 0x10u);
			mem_write16(x + 0xFu, 0u);
			mem_write16(x + 0x14u, 0u);
			t5 = mem_read8(x + 0x29u);
			mem_write8(x + 0x29u, t5 + 1u);
			sub_0785C9(x);
			return u;
		}
		mem_write16(x + 0xFu, 4u);
		mem_write16(x + 0x14u, 0x40u);
		t6 = mem_read8(x + 0x36u);
		if ((int8_t)t6 < 0)
		{
			t7 = mem_read16(x + 0x14u);
			mem_write16(x + 0x14u, 0u - t7);
		}
	}
	t8 = mem_read16(x + 0x40u);
	u = t8;
	t9 = mem_read8(u + 6u);
	mem_write8(u + 6u, t9 | 0x80u);
	t10 = mem_read16(x + 0xCu);
	mem_write16(u + 0xCu, t10);
	t11 = mem_read16(x + 0x11u);
	mem_write16(u + 0x11u, t11);
	t12 = mem_read16(x + 0x16u);
	t13 = t12 + 0x44u;
	mem_write16(u + 0x16u, t13);
	t14 = mem_read16(x + 0x2Eu);
	if (t14 >= 0x10u)
	{
		sub_0785C9(x);
		return u;
	}
	t15 = mem_read16(x + 0x2Cu);
	if (t15 >= 0x60u)
	{
		sub_0785C9(x);
		return u;
	}
	t16 = mem_read16(x + 0xCu);
	t17 = t16 - 0x60u;
	if (t17 >= 0x100u)
	{
		sub_0785C9(x);
		return u;
	}
	mem_write8(x + 5u, 0xA7u);
	mem_write8(x + 0x3Bu, 0x10u);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	t5 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t5 + 1u);
	sub_0785C9(x);
	return u;
}

uint16_t sub_02A5C5(uint16_t x, uint16_t u)
{
	uint8_t t1 = 0, t3 = 0, t5 = 0;
	uint16_t t2 = 0, t4 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) == 0u)
		return u;
	t2 = mem_read16(x + 0x40u);
	u = t2;
	mem_write8(u + 2u, 2u);
	mem_write16(u + 0xFu, 0x380u);
	mem_write16(u + 0x19u, 0x100u);
	t3 = mem_read8(x + 9u);
	if ((t3 & 0x40u) != 0u)
	{
		t4 = mem_read16(u + 0xFu);
		mem_write16(u + 0xFu, 0u - t4);
	}
	mem_write8(x + 0x3Bu, 0x20u);
	t5 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t5 + 1u);
	return u;
}

void sub_02A5F3(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(x + 2u, 2u);
	mem_write8(x + 0x3Bu, 0u);
}

void sub_02A5FC(uint16_t x)
{
	uint32_t negative = 0;
	uint8_t a = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	d = 0u;
	sub_078638(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	if ((int8_t)a >= 0 && (a & 0xFu) == 0u)
	{
		unk_48F1 = a;
		mem_write8(x + 0x47u, a);
		unk_48F0 = a & 0x30u;
		t1 = mem_read8(x + 9u);
		mem_write8(x + 9u, (t1 & 0xCFu) | unk_48F0);
		mem_write8(x + 0x5Du, (((unk_48F1 & 0xFu) << 1) << 1) << 1);
		t2 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t2 + 1u);
	}
}

void sub_02A62C(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 0x30u, 0u);
		mem_write8(x, 0xC0u);
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

uint16_t sub_02A64F(uint16_t x)
{
	uint16_t delayed_start = 0, ignored16 = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;
	uint16_t wait = 0, direction = 0;

	sub_02A133(x, &y, &ignored16);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	mem_write8(x + 5u, 0x82u);
	t2 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t2 & 0xCFu) | 0x20u);
	mem_write8(x, 8u);
	t3 = mem_read8(x + 0x30u);
	delayed_start = delayed_fat_goon_starts_ADDRESS + (int8_t)(((uint32_t)t3 << 1) << 1);
	wait = (((uint32_t)DELAYED_START(delayed_start)->wait << 8u) | DELAYED_START(delayed_start)->floor_wait);
	mem_write8(x + VIDEO_003C, wait >> 8);
	mem_write8(x + 0x3Bu, wait);
	direction = (((uint32_t)DELAYED_START(delayed_start)->direction << 8u) | DELAYED_START(delayed_start)->speed);
	mem_write16(x + 0x3Eu, direction);
	mem_write8(x + 0x30u, 0u);
	return y;
}

uint16_t sub_02A685(uint16_t x, uint16_t y)
{
	uint32_t zero = 0, negative = 0;
	uint16_t ignored16 = 0, u = 0, y_2 = 0;
	uint32_t ignored = 0;
	uint8_t t1 = 0, t2 = 0;

	u = loaded_table_02B8D0_ADDRESS;
	t1 = mem_read8(x + 0x29u);
	t2 = (uint32_t)t1 << 1;
	negative = t2 >> 7;
	zero = t2 == 0u;
	switch ((int8_t)t2)
	{
	case 0:
		sub_02A68E(x);
		return y;
	case -102:
	case 2:
		sub_02A5FC(x);
		return y;
	case -100:
	case 4:
		sub_02A62C(x);
		return y;
	case 6:
		sub_02A6AE(x, &y_2, &ignored16);
		return y_2;
	case 8:
		sub_02A70F(x, &y, &ignored16);
		return y;
	case -94:
	case -78:
	case -52:
	case -24:
	case 10:
		sub_0785DB(x, &y, &ignored16, &ignored);
		return y;
	case -92:
	case -76:
	case -50:
	case -22:
	case 12:
		sub_0785DE(x, &y, &ignored16, &ignored);
		return y;
	case -90:
	case -74:
	case -48:
	case -20:
	case 14:
		sub_0785E1(x, &y, &ignored16, &ignored);
		return y;
	case -88:
	case -72:
	case -46:
	case -18:
	case 16:
		sub_0785E4(x, &y, &ignored16, &ignored);
		return y;
	case 18:
		sub_02A71B(x, u);
		return y;
	case 20:
		sub_02A75D(x, u);
		return y;
	case -14:
	case -10:
	case -6:
	case -2:
		sub_07D030(x, u, zero, negative);
		return y;
	}
	unreachable();
}

void sub_02A68E(uint16_t x)
{
	uint16_t d = 0;
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + VIDEO_003C);
	mem_write8(x + VIDEO_003C, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(x, 0x80u);
	t2 = mem_read16(x + 0x3Eu);
	d = t2;
	sub_078617(x, d);
	t3 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t3 + 1u);
}

void sub_02A6AE(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint32_t carry = 0;
	uint16_t descent_start = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, y = 0;
	uint8_t t1 = 0, t2 = 0;
	uint16_t x_2 = 0, x_speed = 0;

	sub_02A093(x, &ignored16, &ignored16_2);
	y = child_object_02B8E6_ADDRESS;
	sub_07862C(x, y, &descent_start, &ignored16_3, &carry);
	if (carry)
	{
		mem_write16(x + 0x40u, descent_start);
		mem_write8(x + 5u, 0xAFu);
		mem_write8(x + 0x3Bu, 0x68u);
		t1 = mem_read8(x + 0x30u);
		descent_start = fat_goon_descent_starts_ADDRESS + (int8_t)(((uint32_t)t1 << 1) << 1);
		x_2 = DESCENT_START(descent_start)->x;
		mem_write16(x + 0xCu, x_2);
		mem_write16(x + 0x11u, 0x60u);
		mem_write16(x + 0x16u, 0xE0u);
		x_speed = DESCENT_START(descent_start)->x_speed;
		mem_write16(x + 0xFu, x_speed);
		mem_write16(x + 0x14u, 0x100u);
		mem_write16(x + 0x19u, 0xFE00u);
		mem_write16(x + 0x5Cu, 0u);
		mem_write16(x + 0xAu, 0x1010u);
		mem_write8(x + 0x30u, 0u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
	else
	{
		mem_write8(x + 0x3Bu, 0u);
		mem_write8(x + 0x30u, 0u);
		mem_write8(x + 2u, 2u);
	}
	*p_y = y;
	*p_u = descent_start;
}

void sub_02A70F(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t zero = 0, negative = 0;
	uint16_t u = 0;
	uint32_t ignored = 0;
	uint8_t t1 = 0, t2 = 0;

	u = loaded_table_02B8E2_ADDRESS;
	t1 = mem_read8(x + 0x29u);
	t2 = (uint32_t)t1 << 1;
	negative = t2 >> 7;
	zero = t2 == 0u;
	switch ((int8_t)t2)
	{
	case 0:
		u = sub_02A71B(x, u);
		break;
	case 2:
		u = sub_02A75D(x, u);
		break;
	case -120:
	case -16:
		sub_02A5FC(x);
		break;
	case -118:
	case -14:
		sub_02A62C(x);
		break;
	case -112:
	case -96:
	case -70:
	case -42:
	case -8:
		sub_0785DB(x, &y, &u, &ignored);
		break;
	case -110:
	case -94:
	case -68:
	case -40:
	case -6:
		sub_0785DE(x, &y, &u, &ignored);
		break;
	case -108:
	case -92:
	case -66:
	case -38:
	case -4:
		sub_0785E1(x, &y, &u, &ignored);
		break;
	case -106:
	case -90:
	case -64:
	case -36:
	case -2:
		sub_0785E4(x, &y, &u, &ignored);
		break;
	case -32:
	case -28:
	case -24:
	case -20:
		sub_07D030(x, u, zero, negative);
		break;
	case -18:
		sub_02A68E(x);
		break;
	case -12:
		sub_02A6AE(x, &y, &u);
		break;
	case -10:
		sub_02A70F(x, &y, &u);
		break;
	}
	sub_0785C9(x);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_02A71B(uint16_t x, uint16_t u)
{
	uint32_t negative = 0, carry = 0;
	uint8_t a = 0, d_2 = 0;
	uint16_t d = 0;
	uint8_t t3 = 0, t5 = 0;
	uint16_t t1 = 0, t2 = 0, t4 = 0;

	d = 0u;
	sub_078638(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	if ((int8_t)a >= 0)
		mem_write8(x + 0x5Du, (((a & 0xFu) << 1) << 1) << 1);
	t1 = mem_read16(x + 0xAu);
	t2 = t1 + 0x101u;
	d_2 = (uint8_t)t2;
	a = (uint8_t)(t2 >> 8);
	if ((uint16_t)(((uint32_t)a << 8) | (d_2 & 0xFFu)) <= 0x4040u)
	{
		mem_write16(x + 0xAu, ((uint32_t)a << 8) | (d_2 & 0xFFu));
		mem_write8(x, 0x98u);
	}
	t3 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t3 - 1u);
	if (t3 == 1u)
	{
		mem_write16(x + 0x14u, 0u);
		t4 = mem_read16(x + 0x40u);
		u = t4;
		mem_write8(u + 2u, 2u);
		mem_write8(x, 0xC8u);
		mem_write8(x + 5u, 0xA8u);
		t5 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t5 + 1u);
	}
	carry = sub_078662(x);
	return u;
}

uint16_t sub_02A75D(uint16_t x, uint16_t u)
{
	uint32_t carry = 0;
	uint16_t d = 0, u_2 = 0;
	uint8_t t1 = 0;

	sub_0785B1(x, &d, &carry);
	if (carry == 0u)
		return u;
	u_2 = sub_078620(x);
	sub_078626(x, u_2);
	t1 = mem_read8(x + 0x36u);
	d = (d & 0xFFu) | ((uint32_t)t1 << 8);
	u_2 = sub_07866B(x, u_2, d);
	sub_0785C9(x);
	mem_write8(x + 2u, 2u);
	mem_write8(x + 0x3Bu, 0u);
	return u_2;
}

void sub_02A77B(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0;

	u = object_setup_02B8FE_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 4u);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	sub_02A789();
	*p_y = y;
	*p_u = u;
}

void sub_02A789(void)
{
}

uint16_t sub_02A78A(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t2 = 0, t3 = 0, t8 = 0;
	uint16_t t1 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0;

	mem_write8(x, 0x88u);
	t1 = mem_read16(x + 0x40u);
	u = t1;
	t2 = mem_read8(u + 9u);
	unk_48F0 = t2 & 0x30u;
	t3 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t3 & 0xCFu) | unk_48F0);
	t4 = mem_read16(u + 0xCu);
	mem_write16(x + 0xCu, t4);
	t5 = mem_read16(u + 0x11u);
	mem_write16(x + 0x11u, t5);
	t6 = mem_read16(u + 0x16u);
	t7 = t6 + VIDEO_003C;
	mem_write16(x + 0x16u, t7);
	mem_write16(x + 0x19u, 0x100u);
	t8 = mem_read8(x + 2u);
	mem_write8(x + 2u, t8 + 1u);
	return u;
}

void sub_02A7C4(uint16_t x)
{
	uint16_t t1 = 0, t2 = 0;

	t1 = mem_read16(x + 0x19u);
	mem_write16(x + 0x19u, t1 + 4u);
	t2 = mem_read16(x + 0x16u);
	if (t2 >= 0xF0u)
		mem_write8(x, 0u);
}

void sub_02A7DF(uint16_t x)
{
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	sub_07859C(x);
	mem_write8(x + 5u, 0x86u);
	mem_write16(x + 0xFu, 0x100u);
	t1 = mem_read8(x + 0x36u);
	if ((int8_t)(t1 - 0x40u) < 0)
	{
		t2 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t2);
	}
	mem_write8(x + 0x3Bu, 0x20u);
	t3 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t3 + 1u);
	sub_0785C9(x);
}

void sub_02A802(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(x + 2u, 2u);
	mem_write8(x + 0x3Bu, 0u);
}

void sub_02A811(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 5u, 0xB2u);
	mem_write8(x + 0x3Bu, 0x40u + unk_4861);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	sub_07859C(x);
}

uint16_t sub_02A824(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t d = 0, y_2 = 0;
	uint8_t t1 = 0, t2 = 0, t4 = 0, t5 = 0;
	uint16_t t3 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) == 0u)
		return y;
	mem_write16(x + 0xFu, 0x80u);
	t2 = mem_read8(x + 9u);
	if ((t2 & 0x40u) != 0u)
	{
		t3 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t3);
	}
	t4 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t4 + 1u);
	sub_0785C6(x);
	t5 = mem_read8(x + 9u);
	mem_write8(x + 9u, t5 ^ 0x40u);
	d = 0x7600u;
	carry = sub_078680(d);
	y_2 = hit_box_02B90C_ADDRESS;
	sub_0785B4(x, y_2);
	return y_2;
}

uint16_t sub_02A856(uint16_t x, uint16_t y)
{
	uint16_t y_2 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return y;
	mem_write16(x + 0xFu, 0u);
	t2 = mem_read8(x + 9u);
	mem_write8(x + 9u, t2 ^ 0x40u);
	mem_write8(x + 5u, 0x93u);
	t3 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t3 + 1u);
	mem_write8(x + 0x3Bu, 0x20u);
	y_2 = hit_box_02B904_ADDRESS;
	sub_0785B4(x, y_2);
	return y_2;
}

void sub_02A87A(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 2u, 2u);
		mem_write8(x + 0x3Bu, 0u);
		return;
	}
}

void sub_02A887(uint16_t x)
{
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	mem_write8(x + 5u, 0x90u);
	sub_07859C(x);
	mem_write16(x + 0xFu, 0x180u);
	mem_write16(x + 0x14u, 0u);
	t1 = mem_read8(x + 0x36u);
	if ((int8_t)(t1 - 0x40u) >= 0)
	{
		t2 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t2);
	}
	mem_write8(x + 0x3Bu, 0x40u);
	t3 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t3 + 1u);
}

uint16_t sub_02A8AB(uint16_t x, uint16_t u)
{
	uint16_t u_2 = 0;
	uint8_t t1 = 0, t6 = 0, t7 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 2u, 2u);
		mem_write8(x + 0x3Bu, 0u);
		return u;
	}
	t2 = mem_read16(x + 0x38u);
	u_2 = t2;
	sub_078626(x, u_2);
	t3 = mem_read16(x + 0x2Cu);
	if (t3 >= 0x20u)
		return u_2;
	mem_write16(x + 0xFu, 0u);
	t4 = mem_read16(u_2 + 0x16u);
	t5 = mem_read16(u_2 + 0x5Cu);
	if (t4 != t5)
	{
		mem_write8(x + 0x3Bu, 1u);
		t6 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t6 + 1u);
		return u_2;
	}
	mem_write8(x + 5u, 0xAAu);
	u_2 = fat_goon_strike_waits_by_players_ADDRESS;
	mem_write8(x + 0x3Bu, fat_goon_strike_waits_by_players[(int8_t)unk_4857]);
	t7 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t7 + 1u);
	return u_2;
}

void sub_02A8E7(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 5u, 0xA4u);
		t2 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t2 + 1u);
	}
}

uint16_t sub_02A8F5(uint16_t x, uint16_t y)
{
	uint16_t y_2 = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) == 0u)
		return y;
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	y_2 = hit_box_02B914_ADDRESS;
	sub_0785B4(x, y_2);
	return y_2;
}

uint16_t sub_02A906(uint16_t x)
{
	uint16_t y = 0;
	uint8_t t1 = 0;

	y = hit_box_02B904_ADDRESS;
	sub_0785B4(x, y);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	sub_02A90F(x);
	return y;
}

void sub_02A90F(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
		return;
	mem_write8(x + 2u, 2u);
	mem_write8(x + 0x3Bu, 0u);
}

void sub_02A91F(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 5u, 0xAAu);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	sub_07859C(x);
}

void sub_02A92A(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0, t4 = 0, t5 = 0;
	uint16_t t3 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
		return;
	mem_write16(x + 0xFu, 0x200u);
	t2 = mem_read8(x + 9u);
	if ((t2 & 0x40u) != 0u)
	{
		t3 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t3);
	}
	t4 = mem_read8(x + 0xFu);
	mem_write8(x + 0x3Eu, t4);
	mem_write16(x + 0x19u, 0x600u);
	mem_write8(x + 5u, 0xA8u);
	mem_write8(x + 0x3Bu, 0x20u);
	t5 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t5 + 1u);
}

uint16_t sub_02A95A(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t y_2 = 0;
	uint8_t t2 = 0, t3 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x19u);
	mem_write16(x + 0x19u, t1 - 0x40u);
	carry = sub_078662(x);
	if (carry == 0u)
	{
		t2 = mem_read8(x + 0x3Bu);
		mem_write8(x + 0x3Bu, t2 - 1u);
		if (t2 != 1u)
			return y;
		y_2 = hit_box_02B91C_ADDRESS;
		sub_0785B4(x, y_2);
		return y_2;
	}
	mem_write16(x + 0xFu, 0u);
	y_2 = hit_box_02B904_ADDRESS;
	sub_0785B4(x, y_2);
	mem_write8(x + 0x3Bu, 4u);
	t3 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t3 + 1u);
	return y_2;
}

void sub_02A986(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0, t4 = 0;
	uint16_t t3 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(x + 5u, 0xA9u);
	t2 = mem_read8(x + 0x3Eu);
	if ((int8_t)t2 >= 0)
	{
		t3 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t3);
	}
	mem_write8(x + 0x3Bu, 8u);
	t4 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t4 + 1u);
}

void sub_02A9A1(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(x + 2u, 2u);
	mem_write8(x + 0x3Bu, 0u);
}

uint16_t sub_02A9B0(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t4 = 0, t5 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read16(x + 0x38u);
	u = t1;
	t2 = mem_read16(u + 0x16u);
	t3 = mem_read16(u + 0x5Cu);
	if (t2 != t3)
	{
		mem_write8(x + 0x3Bu, 1u);
		t4 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t4 + 1u);
		sub_07859C(x);
		return u;
	}
	mem_write8(x + 5u, 0xAAu);
	u = fat_goon_strike_waits_by_players_ADDRESS;
	mem_write8(x + 0x3Bu, fat_goon_strike_waits_by_players[(int8_t)unk_4857]);
	t5 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t5 + 1u);
	sub_07859C(x);
	return u;
}

void sub_02A9DC(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(x + 5u, 0xABu);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	sub_07859C(x);
}

uint16_t sub_02A9ED(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) == 0u)
		return y;
	y = hit_box_02B924_ADDRESS;
	sub_0785B4(x, y);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	return y;
}

void sub_02AA04(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(x + 5u, 0xA3u);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	sub_07859C(x);
}

uint16_t sub_02AA15(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) == 0u)
		return y;
	y = hit_box_02B92C_ADDRESS;
	sub_0785B4(x, y);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	return y;
}

void sub_02AA2C(void)
{
}

void sub_02AA33(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 5u, 0xA3u);
	sub_07859C(x);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

uint16_t sub_02AA3F(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t d = 0, y_2 = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) == 0u)
		return y;
	y_2 = hit_box_02B934_ADDRESS;
	sub_0785B4(x, y_2);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	d = VIDEO_2000;
	carry = sub_078680(d);
	return y_2;
}

uint16_t sub_02AA5C(uint16_t x)
{
	uint8_t a = 0;
	uint16_t d = 0, u = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x38u);
	u = t1;
	t2 = mem_read8(u + 2u);
	if ((int8_t)t2 < 0)
	{
		mem_write8(x + 2u, 2u);
		mem_write8(x + 0x3Bu, 0u);
		return u;
	}
	t3 = mem_read8(u + 0x3Du);
	if (t3 != 0u)
	{
		mem_write8(x + 2u, 2u);
		mem_write8(x + 0x3Bu, 0u);
		return u;
	}
	sub_07859C(x);
	mem_write8(x + 0x3Bu, 0x40u);
	d = sub_07861D(x, u);
	a = (uint8_t)(d >> 8);
	d = ((uint32_t)a << 8) | 0x30u;
	sub_078617(x, d);
	t4 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t4 + 1u);
	sub_07D25D(x);
	return u;
}

void sub_02AA94(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, u = 0;
	uint8_t stack = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t14 = 0, t15 = 0, t16 = 0, t17 = 0, t18 = 0, t19 = 0;
	uint16_t t1 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0;

	t1 = mem_read16(x + 0x38u);
	u = t1;
	if ((mem_read8(x) & 0x20u) == 0u)
	{
		t2 = mem_read8(u + 2u);
		if ((int8_t)t2 < 0)
		{
			mem_write8(x + 2u, 2u);
			mem_write8(x + 0x3Bu, 0u);
		}
		else
		{
			t3 = mem_read8(x + 0x3Bu);
			mem_write8(x + 0x3Bu, t3 - 1u);
			if (t3 != 1u)
			{
				d = sub_07861D(x, u);
				a = (uint8_t)(d >> 8);
				d = ((uint32_t)a << 8) | 0x20u;
				sub_078617(x, d);
				sub_0785CC(x);
			}
			else
			{
				mem_write8(x + 2u, 2u);
				mem_write8(x + 0x3Bu, 0u);
			}
		}
	}
	else
	{
		t4 = mem_read8(u + 0x3Eu);
		if (t4 != 0u)
		{
			a = 0xBu;
			b = 0u;
			mem_write16(x + 0x28u, ((uint32_t)a << 8) | b);
			mem_write16(x + 0xFu, 0u);
			mem_write16(x + 0x14u, 0u);
		}
		else
		{
			t5 = mem_read8(u + 0x3Du);
			if (t5 != 0u)
			{
				a = 0xCu;
				b = 0u;
				mem_write16(x + 0x28u, ((uint32_t)a << 8) | b);
				mem_write16(x + 0xFu, 0u);
				mem_write16(x + 0x14u, 0u);
			}
			else
			{
				t6 = mem_read16(x + 0x25u);
				if (u != t6)
				{
					t2 = mem_read8(u + 2u);
					if ((int8_t)t2 < 0)
					{
						mem_write8(x + 2u, 2u);
						mem_write8(x + 0x3Bu, 0u);
					}
					else
					{
						t3 = mem_read8(x + 0x3Bu);
						mem_write8(x + 0x3Bu, t3 - 1u);
						if (t3 != 1u)
						{
							d = sub_07861D(x, u);
							a = (uint8_t)(d >> 8);
							d = ((uint32_t)a << 8) | 0x20u;
							sub_078617(x, d);
							sub_0785CC(x);
						}
						else
						{
							mem_write8(x + 2u, 2u);
							mem_write8(x + 0x3Bu, 0u);
						}
					}
				}
				else
				{
					t7 = mem_read16(x + 0x2Cu);
					if (t7 >= 8u)
					{
						t2 = mem_read8(u + 2u);
						if ((int8_t)t2 < 0)
						{
							mem_write8(x + 2u, 2u);
							mem_write8(x + 0x3Bu, 0u);
						}
						else
						{
							t3 = mem_read8(x + 0x3Bu);
							mem_write8(x + 0x3Bu, t3 - 1u);
							if (t3 != 1u)
							{
								d = sub_07861D(x, u);
								a = (uint8_t)(d >> 8);
								d = ((uint32_t)a << 8) | 0x20u;
								sub_078617(x, d);
								sub_0785CC(x);
							}
							else
							{
								mem_write8(x + 2u, 2u);
								mem_write8(x + 0x3Bu, 0u);
							}
						}
					}
					else
					{
						t8 = mem_read16(x + 0x2Eu);
						if (t8 >= 4u)
						{
							t2 = mem_read8(u + 2u);
							if ((int8_t)t2 < 0)
							{
								mem_write8(x + 2u, 2u);
								mem_write8(x + 0x3Bu, 0u);
							}
							else
							{
								t3 = mem_read8(x + 0x3Bu);
								mem_write8(x + 0x3Bu, t3 - 1u);
								if (t3 != 1u)
								{
									d = sub_07861D(x, u);
									a = (uint8_t)(d >> 8);
									d = ((uint32_t)a << 8) | 0x20u;
									sub_078617(x, d);
									sub_0785CC(x);
								}
								else
								{
									mem_write8(x + 2u, 2u);
									mem_write8(x + 0x3Bu, 0u);
								}
							}
						}
						else
						{
							t9 = mem_read16(u + 0x5Cu);
							a = (uint8_t)(t9 >> 8);
							b = (uint8_t)t9;
							t10 = mem_read16(u + 0x16u);
							if ((uint16_t)(((uint32_t)a << 8) | b) != t10)
							{
								t2 = mem_read8(u + 2u);
								if ((int8_t)t2 < 0)
								{
									mem_write8(x + 2u, 2u);
									mem_write8(x + 0x3Bu, 0u);
								}
								else
								{
									t3 = mem_read8(x + 0x3Bu);
									mem_write8(x + 0x3Bu, t3 - 1u);
									if (t3 != 1u)
									{
										d = sub_07861D(x, u);
										a = (uint8_t)(d >> 8);
										d = ((uint32_t)a << 8) | 0x20u;
										sub_078617(x, d);
										sub_0785CC(x);
									}
									else
									{
										mem_write8(x + 2u, 2u);
										mem_write8(x + 0x3Bu, 0u);
									}
								}
							}
							else
							{
								t11 = mem_read16(x + 0x5Cu);
								if ((uint16_t)(((uint32_t)a << 8) | b) != t11)
								{
									t2 = mem_read8(u + 2u);
									if ((int8_t)t2 < 0)
									{
										mem_write8(x + 2u, 2u);
										mem_write8(x + 0x3Bu, 0u);
									}
									else
									{
										t3 = mem_read8(x + 0x3Bu);
										mem_write8(x + 0x3Bu, t3 - 1u);
										if (t3 != 1u)
										{
											d = sub_07861D(x, u);
											a = (uint8_t)(d >> 8);
											d = ((uint32_t)a << 8) | 0x20u;
											sub_078617(x, d);
											sub_0785CC(x);
										}
										else
										{
											mem_write8(x + 2u, 2u);
											mem_write8(x + 0x3Bu, 0u);
										}
									}
								}
								else
								{
									sub_07859F(x, u);
									mem_write16(u + 0x4Bu, x);
									mem_write8(u + 0x3Du, 0xCu);
									mem_write8(u, mem_read8(u) | 0x20u);
									mem_write8(u + 0x1Eu, 3u);
									mem_write16(x + 0xFu, 0u);
									mem_write16(x + 0x14u, 0u);
									t12 = mem_read16(u + 0xCu);
									mem_write16(x + 0xCu, t12);
									t13 = mem_read16(u + 0x11u);
									mem_write16(x + 0x11u, t13);
									t14 = mem_read8(u + 9u);
									unk_48F0 = (t14 & 0x40u) ^ 0x40u;
									t15 = mem_read8(x + 9u);
									mem_write8(x + 9u, (t15 & 0xBFu) | unk_48F0);
									t16 = mem_read8(u + 0x5Bu);
									stack = t16 & 0x70u;
									t17 = mem_read8(x + 0x27u);
									mem_write8(x + 0x27u, (t17 & 0x8Fu) | stack);
									y = fat_goon_hold_animations_ADDRESS;
									t18 = mem_read8(u + 0x5Bu);
									mem_write8(x + 5u, fat_goon_hold_animations[(((t18 >> 1) >> 1) >> 1) >> 1] | 0x80u);
									mem_write8(x + 0x3Bu, 6u);
									t19 = mem_read8(x + 0x29u);
									mem_write8(x + 0x29u, t19 + 1u);
								}
							}
						}
					}
				}
			}
		}
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_02AB52(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d = 0, u = 0;
	uint8_t t1 = 0, t2 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0;
	uint16_t t3 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	t2 = mem_read8(x + 0x3Bu);
	if ((t2 & 0xFu) == 0u)
	{
		d = VIDEO_2000;
		carry = sub_078680(d);
	}
	mem_write8(x + 0x1Du, 0u);
	t3 = mem_read16(x + 0x38u);
	u = t3;
	t4 = mem_read8(u + 0x3Du);
	if (t4 == 0u)
	{
		t5 = mem_read8(x + 0x1Bu);
		a = t5 - 3u;
		mem_write8(x + 0x1Bu, a);
		if ((int8_t)a < 0)
			mem_write8(x + 0x1Bu, 0u);
		mem_write8(x + 0x1Du, 0u);
		mem_write8(x, 0x88u);
		mem_write8(x + 2u, 4u);
		mem_write8(x + 0x28u, (unk_4858 & 1u) + 2u);
		mem_write8(x + 0x29u, 0u);
		return u;
	}
	t6 = mem_read8(u + 0x1Bu);
	if (t6 == 0u)
	{
		mem_write8(x + 0x1Du, 0u);
		mem_write8(x + 2u, 2u);
		mem_write8(x + 0x3Bu, 0u);
		return u;
	}
	t7 = mem_read8(x + 0x58u);
	if (t7 == 2u)
	{
		t8 = mem_read8(x + 0x58u);
		mem_write8(x + 0x58u, t8 + 1u);
		mem_write8(x + 0x29u, 3u);
	}
	return u;
}

uint16_t sub_02ABB0(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		mem_write8(x + 0x58u, 1u);
		t2 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t2 - 1u);
	}
	return sub_02AB52(x);
}

uint16_t sub_02ABCC(uint16_t x)
{
	uint16_t ignored16 = 0, y = 0;
	uint8_t t1 = 0, t3 = 0, t6 = 0;
	uint16_t t2 = 0, t4 = 0, t5 = 0, t7 = 0;

	t1 = mem_read8(x + 0x30u);
	t2 = fat_goon_jump_in_xs[(int8_t)((uint8_t)((uint32_t)t1 << 1)) / 2];
	mem_write16(x + 0xCu, t2);
	t3 = mem_read8(x + 0x30u);
	if ((int8_t)t3 < 0)
		mem_write8(x + 0x1Bu, 1u);
	mem_write8(x + 0x30u, 0u);
	sub_02A133(x, &y, &ignored16);
	mem_write8(x, 0x80u);
	mem_write8(x + 9u, 0x20u);
	mem_write8(x + 5u, 0x90u);
	mem_write16(x + 0xFu, 0x200u);
	t4 = mem_read16(x + 0xCu);
	if (t4 >= 0xE0u)
	{
		t5 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t5);
	}
	t6 = mem_read8(x + 2u);
	mem_write8(x + 2u, t6 + 1u);
	sub_0785C6(x);
	t7 = unk_48E2;
	mem_write16(x + 0x19u, t7);
	return y;
}

uint16_t sub_02AC15(uint16_t x, uint16_t y)
{
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_02AC1E(x);
		return y;
	case 2:
		sub_02AC5D(x, 0u);
		return y;
	case 4:
		return sub_02AC7C(x);
	case 6:
		return sub_02ACC0(x, y);
	case -12:
	case 8:
		sub_0785DB(x, &y, &ignored16, &ignored);
		return y;
	case -10:
	case 10:
		sub_0785DE(x, &y, &ignored16, &ignored);
		return y;
	case -8:
	case 12:
		sub_0785FC(x, &y, &ignored16);
		return y;
	case -6:
	case 14:
		sub_0785E4(x, &y, &ignored16, &ignored);
		return y;
	}
	unreachable();
}

void sub_02AC1E(uint16_t x)
{
	uint32_t negative = 0;
	uint8_t a = 0;
	uint16_t d = 0;
	uint8_t t2 = 0, t3 = 0;
	uint16_t t1 = 0;

	sub_078644(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	unk_48F0 = a;
	mem_write8(x + 0x46u, a);
	if ((int8_t)a < 0)
	{
		t1 = unk_48E2;
		mem_write16(x + 0x19u, t1);
		return;
	}
	mem_write8(x + 0x5Du, (((a & 0xFu) << 1) << 1) << 1);
	unk_48F0 &= 0x30u;
	t2 = mem_read8(x + 9u);
	mem_write8(x + 9u, t2 & 0xC0u);
	mem_write16(x + 0x19u, 0x400u);
	mem_write8(x, 0x88u);
	mem_write8(x + 5u, 0x84u);
	t3 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t3 + 1u);
}

void sub_02AC5D(uint16_t x, uint32_t u)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry == 0u)
		return;
	mem_write8(x, 0xC0u);
	sub_078620(x);
	mem_write8(x + 2u, 2u);
}

uint16_t sub_02AC7C(uint16_t x)
{
	uint16_t ignored16 = 0, y = 0;
	uint8_t t1 = 0, t4 = 0, t6 = 0;
	uint16_t t2 = 0, t3 = 0, t5 = 0;

	t1 = mem_read8(x + 0x30u);
	t2 = fat_goon_from_below_xs[(int8_t)((uint8_t)((uint32_t)t1 << 1)) / 2];
	mem_write16(x + 0xCu, t2);
	mem_write8(x + 0x30u, 0u);
	mem_write16(x + 0x16u, 0xFF80u);
	sub_02A107(x, &y, &ignored16);
	mem_write8(x, 0x80u);
	mem_write8(x + 9u, 0x20u);
	mem_write8(x + 5u, 0x86u);
	mem_write16(x + 0x5Cu, 0u);
	t3 = mem_read16(x + 0xCu);
	if (t3 >= 0xE0u)
	{
		t4 = mem_read8(x + 9u);
		mem_write8(x + 9u, t4 | 0x40u);
	}
	t5 = unk_48E2;
	mem_write16(x + 0x19u, t5);
	t6 = mem_read8(x + 2u);
	mem_write8(x + 2u, t6 + 1u);
	return y;
}

uint16_t sub_02ACC0(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_02ACC9(x);
		return y;
	case 2:
		sub_02AD08(x, 0u);
		return y;
	case 4:
		return sub_02AD21(x);
	case 6:
		return sub_02AD47(x, y, 0u);
	}
	unreachable();
}

void sub_02ACC9(uint16_t x)
{
	uint8_t a = 0, d = 0;
	uint8_t t3 = 0, t4 = 0, t6 = 0;
	uint16_t t1 = 0, t2 = 0, t5 = 0;

	t1 = mem_read16(x + 0x16u);
	d = (uint8_t)t1;
	a = (uint8_t)(t1 >> 8);
	if ((int16_t)t1 < 0 || (uint16_t)(((uint32_t)a << 8) | (d & 0xFFu)) < 0u)
	{
		t2 = unk_48E2;
		mem_write16(x + 0x19u, t2);
		return;
	}
	t3 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t3 & 0xCFu) | 0x10u);
	mem_write16(x + 0x19u, 0x400u);
	mem_write16(x + 0xFu, 0x200u);
	t4 = mem_read8(x + 9u);
	if ((t4 & 0x40u) != 0u)
	{
		t5 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t5);
	}
	mem_write8(x, 0x88u);
	mem_write8(x + 5u, 0x84u);
	t6 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t6 + 1u);
}

void sub_02AD08(uint16_t x, uint32_t u)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry == 0u)
		return;
	mem_write8(x, 0xC0u);
	sub_078620(x);
	mem_write8(x + 2u, 2u);
}

uint16_t sub_02AD21(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, u = 0, y = 0;
	uint8_t t1 = 0;

	mem_write16(x + 0xCu, 0xE0u);
	y = child_object_02B9C5_ADDRESS;
	sub_07862C(x, y, &u, &ignored16, &carry);
	if (carry)
		mem_write16(u + 0x2Au, x);
	if (unk_486B < 3u)
	{
		t1 = mem_read8(x + 2u);
		mem_write8(x + 2u, t1 + 1u);
		return sub_02AD47(x, y, u);
	}
	y = child_object_02B9CD_ADDRESS;
	sub_07862C(x, y, &u, &ignored16, &carry);
	if (carry)
		mem_write16(u + 0x2Au, x);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	return sub_02AD47(x, y, u);
}

uint16_t sub_02AD47(uint16_t x, uint16_t y, uint32_t u)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, y_2 = 0;
	uint8_t t1 = 0;

	t1 = io_read8(VIDEO_1876);
	if (t1 != 0u)
	{
		unk_48A7--;
		return y;
	}
	unk_4880 = 2u;
	d = 0x9300u;
	carry = sub_078680(d);
	mem_write8(x, 0u);
	y_2 = child_object_02B9D5_ADDRESS;
	sub_07862C(x, y_2, &ignored16, &ignored16_2, &carry);
	y_2 = child_object_02B9DD_ADDRESS;
	sub_07862C(x, y_2, &ignored16, &ignored16_2, &carry);
	return y_2;
}

void sub_02AD71(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	sub_02AD74(x);
}

void sub_02AD74(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = io_read8(VIDEO_1876);
	t2 = mem_read8(x + 0x30u);
	if (t2 < t1)
	{
		unk_48A7--;
		return;
	}
	mem_write8(x, 0u);
}

void sub_02AD8F(uint16_t x)
{
	uint8_t a = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x30u);
	a = t1;
	mem_write8(x + 0x3Du, object_15_times[(int8_t)a]);
	a = (uint32_t)a << 1;
	mem_write16(x + 0x2Au, TABLE16(object_15_spawn_lists, (int8_t)a));
	mem_write8(x + 0x30u, TABLE8(object_15_next_kinds, (uint16_t)((int8_t)((uint32_t)a << 1) + ((unk_4857 - 1u) & 3u))));
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
}

void sub_02ADB8(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t b = 0, d = 0;
	uint16_t u = 0, y = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t7 = 0, t9 = 0, t12 = 0, t13 = 0;
	uint16_t t1 = 0, t6 = 0, t8 = 0, t10 = 0, t11 = 0;

	t1 = mem_read16(x + 0x2Au);
	y = t1;
	if (mem_read8(y) == 0xFFu)
	{
		mem_write8(x + 2u, 3u);
		return;
	}
	for (;;)
	{
		t2 = mem_read8(x + 0x28u);
		if (mem_read8(y) != t2)
			break;
		t3 = mem_read8(y + 4u);
		t4 = io_read8(VIDEO_1874);
		if (t3 < t4)
		{
			t5 = mem_read8(y + 5u);
			d = t5;
			sub_0786AA(d, &u, &carry);
			if (carry)
			{
				t6 = mem_read16(y + 6u);
				mem_write8(u + 0x30u, t6 >> 8);
				mem_write8(u + 1u, t6);
				t7 = mem_read8(y + 1u);
				t8 = (uint32_t)t7 << 3;
				mem_write16(u + 0xCu, t8);
				t9 = mem_read8(y + 2u);
				t10 = (uint32_t)t9 << 3;
				t11 = t10 + unk_48B2;
				mem_write16(u + 0x11u, t11);
				t12 = mem_read8(y + 3u);
				b = t12;
				mem_write16(u + 0x16u, b);
				mem_write16(u + 0x5Cu, b);
			}
		}
		y += 8u;
	}
	mem_write16(x + 0x2Au, y);
	t13 = mem_read8(x + 2u);
	mem_write8(x + 2u, t13 + 1u);
}

void sub_02AE21(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = io_read8(VIDEO_1876);
	t2 = mem_read8(x + 0x30u);
	if (t1 <= t2)
	{
		t3 = mem_read8(x + 0x28u);
		mem_write8(x + 0x28u, t3 + 1u);
		t4 = mem_read8(x + 2u);
		mem_write8(x + 2u, t4 - 1u);
	}
}

void sub_02AE31(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = io_read8(VIDEO_1876);
	t2 = mem_read8(x + 0x3Du);
	if (t1 <= t2)
		mem_write8(x, 0u);
}

void sub_02AE47(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0;

	u = object_setup_02BD72_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 0x80u);
	mem_write8(x + 9u, 0x50u);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	sub_02AE5A();
	*p_y = y;
	*p_u = u;
}

void sub_02AE5A(void)
{
}

void sub_02AE5B(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t ignored16 = 0, u_2 = 0, y_2 = 0;
	uint8_t t1 = 0;

	if (unk_48AC < 0x190u)
		return;
	y_2 = child_object_02BD78_ADDRESS;
	sub_07862C(x, y_2, &u_2, &ignored16, &carry);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	*p_y = y_2;
	*p_u = u_2;
}

void sub_02AE76(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0;

	u = object_setup_02BD88_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x + 9u, 0x10u);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_02AE85(void)
{
}

void sub_02AE86(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, u = 0, y = 0;
	uint8_t t1 = 0;

	mem_write8(x, 0x80u);
	y = child_object_02BD8E_ADDRESS;
	sub_07862C(x, y, &u, &ignored16, &carry);
	if (carry == 0u)
		sub_02AE9B();
	else
	{
		mem_write8(x + 5u, 0x82u);
		t1 = mem_read8(x + 2u);
		mem_write8(x + 2u, t1 + 1u);
		sub_02AE9B();
	}
	*p_y = y;
	*p_u = u;
}

void sub_02AE9B(void)
{
}

void sub_02AEA5(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0;

	u = object_setup_02BDA2_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x + 9u, 0x10u);
	mem_write8(x + VIDEO_003C, 3u);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_02AEB9(uint16_t x)
{
	uint8_t t1 = 0;

	if ((mem_read8(x) & 0x20u) != 0u)
	{
		mem_write8(x, 0x80u);
		mem_write8(x + 5u, 0x82u);
		t1 = mem_read8(x + 2u);
		mem_write8(x + 2u, t1 + 1u);
	}
}

void sub_02AECE(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t ignored16 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		mem_write8(x + 0x3Du, 0u);
		y = child_object_02BDA8_ADDRESS;
		sub_07862C(x, y, &u, &ignored16, &carry);
		if (carry)
		{
			mem_write16(x + 0x40u, u);
			t2 = mem_read8(x + 0x3Du);
			mem_write8(x + 0x3Du, t2 + 1u);
		}
		mem_write8(x + 0x3Bu, 0x40u);
		mem_write8(x + 5u, 0x81u);
		t3 = mem_read8(x + VIDEO_003C);
		mem_write8(x + VIDEO_003C, t3 - 1u);
		if (t3 != 1u)
		{
			t4 = mem_read8(x + 2u);
			mem_write8(x + 2u, t4 + 1u);
		}
		else
		{
			mem_write8(x + 5u, 0x80u);
			mem_write8(x + 2u, 5u);
		}
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_02AF03(uint16_t x, uint16_t u)
{
	uint16_t u_2 = 0;
	uint8_t t1 = 0, t2 = 0, t4 = 0, t5 = 0;
	uint16_t t3 = 0;

	t1 = mem_read8(x + 0x3Du);
	if (t1 == 0u)
	{
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
		return u;
	}
	t3 = mem_read16(x + 0x40u);
	u_2 = t3;
	t4 = mem_read8(u_2 + 2u);
	if (t4 == 2u)
	{
		t5 = mem_read8(x + 2u);
		mem_write8(x + 2u, t5 + 1u);
		mem_write8(x + 0x3Du, 0u);
	}
	return u_2;
}

void sub_02AF1D(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
	{
		sub_02AF2C();
		return;
	}
	mem_write8(x, 0xC0u);
	mem_write8(x + 2u, 1u);
	sub_02AF2C();
}

void sub_02AF2C(void)
{
}

void sub_02AF36(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t door_release = 0, krustyland_door = 0, u = 0;
	uint8_t t1 = 0, t3 = 0;
	uint16_t wait = 0, t2 = 0, releases = 0, players = 0;

	u = object_setup_02BDBC_ADDRESS;
	sub_0785AB(x, u);
	mem_write8(x, 0x80u);
	mem_write8(x + 9u, 0x20u);
	t1 = mem_read8(x + 0x30u);
	krustyland_door = krustyland_doors_ADDRESS + (int8_t)(((uint32_t)t1 << 1) << 1);
	wait = (((uint32_t)KRUSTYLAND_DOOR(krustyland_door)->wait << 8u) | KRUSTYLAND_DOOR(krustyland_door)->trigger_x);
	mem_write8(x + 0x3Bu, wait >> 8);
	t2 = (wait & 0xFFu) << 4;
	mem_write16(x + 0x3Eu, t2);
	releases = KRUSTYLAND_DOOR(krustyland_door)->releases;
	door_release = releases;
	mem_write16(x + 0x2Au, door_release);
	players = (((uint32_t)DOOR_RELEASE(door_release - 0x2u)->players << 8u) | DOOR_RELEASE(door_release - 0x2u)->wait);
	mem_write16(x + 0x38u, players);
	mem_write8(x + 0x3Du, 0u);
	t3 = mem_read8(x + 2u);
	mem_write8(x + 2u, t3 + 1u);
	*p_y = door_release;
	*p_u = krustyland_door;
}

void sub_02AF6E(uint16_t x)
{
	uint8_t t1 = 0;

	if (unk_48AC >= 0x4E0u)
	{
		t1 = mem_read8(x + 2u);
		mem_write8(x + 2u, t1 + 1u);
	}
}

void sub_02AF7A(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint8_t a = 0, d_2 = 0;
	uint16_t d = 0, ignored16 = 0;
	uint8_t t1 = 0, t2 = 0, t5 = 0, t6 = 0, t8 = 0;
	uint16_t t3 = 0, t4 = 0, t7 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		t2 = io_read8(VIDEO_1876);
		if (t2 <= 4u)
		{
			d = 0x1400u;
			carry = sub_078680(d);
			mem_write8(x + 5u, 0xA3u);
			t3 = mem_read16(x + 0x2Au);
			y = t3;
			t4 = mem_read16(y);
			d_2 = (uint8_t)t4;
			a = (uint8_t)(t4 >> 8);
			if ((int16_t)t4 < 0)
			{
				t5 = mem_read8(x + 0x3Du);
				mem_write8(x + 0x3Du, t5 + 1u);
				t6 = mem_read8(x + 2u);
				mem_write8(x + 2u, t6 + 1u);
			}
			else
			{
				mem_write8(x + 0x3Bu, d_2);
				y += 2u;
				mem_write16(x + 0x2Au, y);
				if (a < unk_4857)
				{
					t7 = mem_read16(x + 0x38u);
					y = t7;
					sub_07862C(x, y, &u, &ignored16, &carry);
				}
				t8 = mem_read8(x + 2u);
				mem_write8(x + 2u, t8 + 1u);
			}
		}
		else
			mem_write8(x + 0x3Bu, 1u);
	}
	*p_y = y;
	*p_u = u;
}

void sub_02AFBE(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
		mem_write8(x + VIDEO_003C, 0x60u);
		t3 = mem_read8(x + 0x3Du);
		if (t3 != 0u)
			mem_write8(x, 0u);
	}
}

void sub_02AFD5(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + VIDEO_003C);
	mem_write8(x + VIDEO_003C, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 5u, 0xA4u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_02AFE3(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
		mem_write8(x + 2u, 2u);
}

void sub_02AFF8(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, u = 0, y = 0;
	uint8_t t1 = 0;

	u = object_setup_02BE13_ADDRESS;
	sub_0785AB(x, u);
	mem_write8(x, 0x80u);
	mem_write8(x + 0x5Bu, 0x40u);
	mem_write8(x + 9u, 0x10u);
	y = child_object_02BE0B_ADDRESS;
	sub_07862C(x, y, &u, &ignored16, &carry);
	if (carry == 0u)
	{
		mem_write8(x + 2u, 6u);
		sub_02B021();
	}
	else
	{
		mem_write16(x + 0x40u, u);
		t1 = mem_read8(x + 2u);
		mem_write8(x + 2u, t1 + 1u);
	}
	*p_y = y;
	*p_u = u;
}

void sub_02B021(void)
{
}

uint16_t sub_02B022(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0, u = 0;
	uint8_t t2 = 0, t3 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x40u);
	u = t1;
	t2 = mem_read8(u + 2u);
	if (t2 != 3u)
		return u;
	d = 0x5C00u;
	carry = sub_078680(d);
	mem_write16(x + 0x5Cu, 0u);
	mem_write16(x + 0xFu, 0x80u);
	mem_write16(x + 0x14u, 0xFF00u);
	mem_write16(x + 0x19u, 0x600u);
	mem_write8(x + 0x3Bu, 0x10u);
	t3 = mem_read8(x + 2u);
	mem_write8(x + 2u, t3 + 1u);
	return u;
}

void sub_02B050(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0;
	uint8_t t1 = 0, t2 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry == 0u)
	{
		t1 = mem_read8(x + 0x3Bu);
		mem_write8(x + 0x3Bu, t1 - 1u);
		if (t1 == 1u)
			mem_write8(x + 5u, 0x84u);
		return;
	}
	d = unk_5D00_ADDRESS;
	carry = sub_078680(d);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write8(x, 0xC0u);
	mem_write8(x + 0x3Bu, 0x20u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
}

void sub_02B07A(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x, 0x80u);
	mem_write8(x + 0x1Du, 0x14u);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	sub_078674(x);
}

void sub_02B08A(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 0x3Bu, 0x10u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_02B098(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x, mem_read8(x) ^ 0x84u);
	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
		mem_write8(x, 0u);
}

void sub_02B0AF(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t prop = 0, u = 0, y = 0;
	uint8_t t1 = 0, t3 = 0;
	uint16_t kind = 0, attributes = 0, t2 = 0;

	u = object_setup_02BE1D_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 0x30u);
	prop = props_ADDRESS + (int8_t)(((uint32_t)t1 << 1) << 1);
	kind = (((uint32_t)PROP(prop)->kind << 8u) | PROP(prop)->animation);
	mem_write16(x + 4u, kind);
	attributes = (((uint32_t)PROP(prop)->attributes << 8u) | PROP(prop)->leave_x);
	mem_write8(x + 9u, attributes >> 8);
	t2 = (attributes & 0xFFu) << 4;
	mem_write16(x + 0x3Eu, t2);
	t3 = mem_read8(x + 2u);
	mem_write8(x + 2u, t3 + 1u);
	*p_y = y;
	*p_u = prop;
}

void sub_02B0D9(uint16_t x)
{
	uint16_t t1 = 0, t2 = 0;

	t1 = mem_read16(x + 0xCu);
	t2 = mem_read16(x + 0x3Eu);
	if (t1 < t2)
		mem_write8(x, 0u);
}

void sub_02B0EB(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0;

	u = object_setup_02BE57_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 0x80u);
	mem_write8(x + 9u, 0x10u);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	sub_02B0FE();
	*p_y = y;
	*p_u = u;
}

void sub_02B0FE(void)
{
}

void sub_02B105(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0;

	u = object_setup_02BE61_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	t2 = mem_read8(x + 0x30u);
	if (t2 != 0u)
	{
		mem_write8(x + 9u, 0x10u);
		mem_write8(x + 5u, 0x84u);
		mem_write16(x + 0x16u, 0u);
	}
	else
	{
		mem_write8(x + 9u, 0x20u);
		y = child_object_02BE67_ADDRESS;
		sub_07862C(x, y, &u, &ignored16, &carry);
	}
	*p_y = y;
	*p_u = u;
}

void sub_02B131(uint16_t x)
{
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0xCu);
	if (t1 < 0x20u)
		mem_write8(x, 0u);
}

void sub_02B146(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0;

	u = object_setup_02BE79_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x + 9u, 0x60u);
	mem_write8(x + VIDEO_003C, 3u);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	sub_02B159();
	*p_y = y;
	*p_u = u;
}

void sub_02B159(void)
{
}

void sub_02B15A(uint16_t x)
{
	uint8_t t1 = 0;

	if ((mem_read8(x) & 0x20u) != 0u)
	{
		mem_write8(x, 0x80u);
		mem_write8(x + 5u, 0x81u);
		t1 = mem_read8(x + 2u);
		mem_write8(x + 2u, t1 + 1u);
	}
}

void sub_02B16F(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
		return;
	mem_write8(x + 0x3Bu, 0x80u);
	mem_write8(x + 5u, 0x80u);
	t2 = mem_read8(x + VIDEO_003C);
	mem_write8(x + VIDEO_003C, t2 - 1u);
	if (t2 != 1u)
	{
		t3 = mem_read8(x + 2u);
		mem_write8(x + 2u, t3 + 1u);
		return;
	}
	mem_write8(x + 2u, 4u);
}

void sub_02B18E(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x, 0xC0u);
		mem_write8(x + 2u, 1u);
	}
}

uint16_t sub_02B1A4(uint16_t x)
{
	uint16_t kind_d1_fling = 0, u = 0;
	uint8_t t1 = 0, t2 = 0;
	uint16_t x_speed = 0, z_speed = 0;

	u = object_setup_02BE83_ADDRESS;
	sub_0785AB(x, u);
	mem_write8(x + 9u, 0x10u);
	mem_write16(x + 0xAu, 0x6060u);
	mem_write8(x, 0x90u);
	t1 = mem_read8(x + 0x30u);
	kind_d1_fling = kind_d1_flings_ADDRESS + (uint8_t)(((t1 & 3u) << 1) << 1);
	x_speed = KIND_D1_FLING(kind_d1_fling)->x_speed;
	mem_write16(x + 0xFu, x_speed);
	z_speed = KIND_D1_FLING(kind_d1_fling)->z_speed;
	mem_write16(x + 0x19u, z_speed);
	mem_write8(x + 0x3Bu, 0x40u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	return kind_d1_fling;
}

void sub_02B1DA(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	mem_write8(x, 0x90u);
	t1 = mem_read16(x + 0xAu);
	d = t1 - 0x101u;
	if (d >= 0x1010u)
		mem_write16(x + 0xAu, d);
	t2 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t2 - 1u);
	if (t2 != 1u)
		return;
	d = VIDEO_2000;
	carry = sub_078680(d);
	mem_write8(x, 0u);
}

void sub_02B211(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t cemetery_piece = 0, u = 0, y = 0;
	uint8_t t1 = 0, animation = 0, t2 = 0;
	uint16_t z = 0;

	u = object_setup_02BED1_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write16(x + 0xCu, 0x9Au);
	t1 = mem_read8(x + 0x30u);
	cemetery_piece = cemetery_pieces_ADDRESS + (int8_t)(((uint32_t)t1 << 1) << 1);
	z = CEMETERY_PIECE(cemetery_piece)->z;
	mem_write16(x + 0x16u, z);
	animation = CEMETERY_PIECE(cemetery_piece)->animation;
	mem_write8(x + 5u, animation);
	mem_write8(x + 9u, 0x20u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	sub_02B23A(x);
	*p_y = y;
	*p_u = cemetery_piece;
}

void sub_02B23A(uint16_t x)
{
	mem_write16(x + 0x19u, unk_48E2);
}

void sub_02B24A(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t d = 0, u = 0, y = 0;
	uint16_t stack = 0;
	uint8_t t2 = 0, t3 = 0;
	uint16_t t1 = 0;

	u = object_setup_02BEE5_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 0x80u);
	mem_write16(x + 0xCu, 0x180u);
	t1 = mem_read16(x + 0x11u);
	mem_write16(x + 0x11u, t1 - 2u);
	t2 = mem_read8(x + VIDEO_0031);
	mem_write8(x + VIDEO_0031, t2 + 1u);
	sub_078650(x, &u, &d);
	mem_write8(x + 0x33u, d >> 8);
	mem_write16(x + 0x2Au, u);
	stack = u;
	mem_write16(x + 0x38u, stack & ~0x3Fu);
	mem_write8(x + 0x37u, 0u);
	mem_write8(x + VIDEO_0031, 0u);
	t3 = mem_read8(x + 2u);
	mem_write8(x + 2u, t3 + 1u);
	sub_02B282();
	*p_y = y;
	*p_u = u;
}

void sub_02B282(void)
{
}

void sub_02B283(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t t1 = 0;

	u = loaded_table_02BEEB_ADDRESS;
	t1 = mem_read8(x + 0x37u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_02B28C(x, &y, &u);
		break;
	case 2:
		sub_02B29E(x, &y, &u);
		break;
	case 4:
		sub_02B2B0(x, &y, &u);
		break;
	case 6:
		sub_02B2C1();
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_02B28C(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t u_2 = 0, y_2 = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0xCu);
	if (t1 >= 0x180u)
		return;
	y_2 = loaded_table_02BEF3_ADDRESS;
	sub_02B2C2(x, &y_2, &u_2);
	t2 = mem_read8(x + 0x37u);
	mem_write8(x + 0x37u, t2 + 1u);
	*p_y = y_2;
	*p_u = u_2;
}

void sub_02B29E(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t u_2 = 0, y_2 = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0xCu);
	if (t1 >= 0x160u)
		return;
	y_2 = loaded_table_02BEFF_ADDRESS;
	sub_02B2C2(x, &y_2, &u_2);
	t2 = mem_read8(x + 0x37u);
	mem_write8(x + 0x37u, t2 + 1u);
	*p_y = y_2;
	*p_u = u_2;
}

void sub_02B2B0(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0xCu);
	if (t1 >= 0x140u)
	{
		sub_02B2C1();
		return;
	}
	y = loaded_table_02BF0B_ADDRESS;
	sub_02B2C2(x, &y, &u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	sub_02B2C1();
	*p_y = y;
	*p_u = u;
}

void sub_02B2C1(void)
{
}

void sub_02B2C2(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t a = 0, b = 0;
	uint16_t u = 0;
	uint8_t stack = 0;
	uint8_t t2 = 0, t4 = 0, t5 = 0, t6 = 0;
	uint16_t t1 = 0, t3 = 0;

	a = unk_480F | 2u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
	t1 = mem_read16(x + 0x2Au);
	t2 = mem_read8(x + 0x37u);
	stack = t1 + (int8_t)(((uint32_t)t2 << 1) << 1);
	b = stack;
	mem_write8(x + 0x34u, b);
	b -= 3u;
	unk_48F4 = 4u;
	do
	{
		t3 = mem_read16(x + 0x38u);
		b &= 0x3Fu;
		u = t3 + b;
		mem_write8(u - 0x40u, mem_read8(y));
		t4 = mem_read8(y + 4u);
		mem_write8(u, t4);
		t5 = mem_read8(y + 8u);
		mem_write8(u + 0x40u, t5);
		b++;
		y++;
		t6 = unk_48F4;
		unk_48F4 = t6 - 1u;
	} while (t6 != 1u);
	a = unk_480F & ~3u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
	*p_y = y;
	*p_u = u;
}

void sub_02B31B(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
		mem_write8(x, 0u);
}

void sub_02B325(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = 0x7F2Fu;
		t1 = mem_read8(x + 0x29u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			sub_02B32E(x);
			break;
		case 2:
			sub_02B31B(x);
			break;
		case 4:
		case 6:
			continue;
		case 8:
			sub_02B392(x, &y, &u);
			break;
		case 10:
			sub_02B3C5(x);
			break;
		case 12:
			u = sub_02B3E4(x, u);
			break;
		case 14:
			sub_02B3C4();
			break;
		}
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_02B32E(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write16(x + 4u, 0x480u);
	mem_write16(x + 0xFu, 0u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

void sub_02B33B(uint16_t x)
{
	uint32_t negative = 0;
	uint8_t a = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	d = 0u;
	sub_078638(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	if ((int8_t)a >= 0)
	{
		unk_48F0 = a;
		mem_write8(x + 0x5Cu, (((a & 0xFu) << 1) << 1) << 1);
		unk_48F0 &= 0x30u;
		t1 = mem_read8(x + 9u);
		mem_write8(x + 9u, (t1 & 0xCFu) | unk_48F0);
	}
}

void sub_02B392(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t3 = 0, t5 = 0;
	uint16_t t1 = 0, t2 = 0, t4 = 0;

	u = object_setup_02BF3F_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 0xC8u);
	mem_write8(x + 0x3Bu, 0x20u);
	mem_write8(x + VIDEO_0031, 0x20u);
	t1 = mem_read16(x + 0x40u);
	u = t1;
	t2 = mem_read16(u + 0x5Cu);
	mem_write16(x + 0x5Cu, t2);
	mem_write16(x + 0xFu, 0x480u);
	t3 = mem_read8(u + 9u);
	if ((t3 & 0x40u) != 0u)
	{
		t4 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t4);
	}
	t5 = mem_read8(x + 2u);
	mem_write8(x + 2u, t5 + 1u);
	sub_0785C6(x);
	*p_y = y;
	*p_u = u;
}

void sub_02B3C4(void)
{
}

void sub_02B3C5(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0, t4 = 0;
	uint16_t t3 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(x + 0x3Bu, 0x20u);
	t2 = mem_read8(x + VIDEO_0031);
	if (t2 == 0u)
	{
		mem_write8(x + 2u, 3u);
		return;
	}
	t3 = mem_read16(x + 0xFu);
	mem_write16(x + 0xFu, 0u - t3);
	t4 = mem_read8(x + 2u);
	mem_write8(x + 2u, t4 + 1u);
	sub_0785C6(x);
}

uint16_t sub_02B3E4(uint16_t x, uint16_t u)
{
	uint8_t t1 = 0, t2 = 0, t4 = 0, t5 = 0;
	uint16_t t3 = 0;

	t1 = mem_read8(x + VIDEO_0031);
	if (t1 == 0u)
	{
		mem_write8(x + 2u, 3u);
		return u;
	}
	t2 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t2 - 1u);
	if (t2 != 1u)
		return u;
	t3 = mem_read16(x + 0x40u);
	u = t3;
	t4 = mem_read8(u + 2u);
	if (t4 != 4u)
	{
		mem_write8(x, 0u);
		return u;
	}
	t5 = mem_read8(x + 2u);
	mem_write8(x + 2u, t5 + 1u);
	return u;
}

uint16_t sub_02B400(uint16_t x, uint16_t u)
{
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + VIDEO_0031);
	if (t1 != 0u)
	{
		t2 = mem_read16(x + 0x40u);
		u = t2;
		t3 = mem_read8(u + 2u);
		if (t3 == 4u)
			mem_write8(x + VIDEO_0031, 0u);
	}
	return u;
}

void sub_02B41E(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_02BF5D_ADDRESS;
		t1 = mem_read8(x + 0x29u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			sub_02B427(x);
			break;
		case 2:
			sub_02B436(x);
			break;
		case 4:
			sub_02B435();
			break;
		case -16:
		case -14:
			continue;
		case -12:
			sub_02B44E(x, &y, &u);
			break;
		case -10:
			sub_02B477(x);
			break;
		case -8:
			u = sub_02B499(x, u);
			break;
		case -6:
			u = sub_02B4F0(x, u);
			break;
		case -4:
			u = sub_02B4FA(x, u);
			break;
		case -2:
			u = sub_02B516(x, u);
			break;
		}
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_02B427(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	d = 0x6300u;
	carry = sub_078680(d);
	mem_write8(x + 5u, 0x85u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	sub_02B435();
}

void sub_02B435(void)
{
}

void sub_02B436(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
		return;
	mem_write8(x + 5u, 0x81u);
	mem_write16(x + 0xFu, 0x200u);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	sub_0785C6(x);
}

void sub_02B44E(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t police_car_arrival = 0, u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0;
	uint16_t x_speed = 0, frames = 0;

	u = object_setup_02BF63_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 0x30u);
	police_car_arrival = police_car_arrivals_ADDRESS + (int8_t)(((uint32_t)t1 << 1) << 1);
	x_speed = POLICE_CAR_ARRIVAL(police_car_arrival)->x_speed;
	mem_write16(x + 0xFu, x_speed);
	frames = (((uint32_t)POLICE_CAR_ARRIVAL(police_car_arrival)->frames << 8u) | POLICE_CAR_ARRIVAL(police_car_arrival)->kind);
	mem_write8(x + 0x3Bu, frames >> 8);
	mem_write8(x + 4u, frames);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	sub_0785C6(x);
	*p_y = y;
	*p_u = police_car_arrival;
}

void sub_02B477(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	if (unk_4867 == 0u)
		unk_48A7--;
	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x, 0xC0u);
		io_write8(VIDEO_1884, 0xC0u);
		mem_write16(x + 0xFu, 0u);
		mem_write8(x + 5u, 0x89u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

uint16_t sub_02B499(uint16_t x, uint16_t u)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		mem_write8(x + 5u, 0x80u);
		mem_write8(x + 0x3Bu, 0x80u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
	u = sub_02B4B7(x, u);
	if (unk_4867 == 0u)
		return u;
	sub_078674(x);
	return sub_02B4B7(x, u);
}

uint16_t sub_02B4B7(uint16_t x, uint16_t u)
{
	uint8_t t1 = 0, t2 = 0, t4 = 0, t5 = 0, t6 = 0;
	uint16_t t3 = 0;

	if ((mem_read8(x) & 0x20u) == 0u)
		return u;
	t1 = mem_read8(x + 0x1Eu);
	if (t1 < 1 || t1 > 0x15)
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
	mem_write8(x, 0x80u);
	mem_write8(x + 2u, 0xFFu);
	mem_write16(x + 0x28u, 0u);
	return u;
}

uint16_t sub_02B4F0(uint16_t x, uint16_t u)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
	u = sub_02B4B7(x, u);
	if (unk_4867 == 0u)
		return u;
	sub_078674(x);
	return sub_02B4B7(x, u);
}

uint16_t sub_02B4FA(uint16_t x, uint16_t u)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
		return sub_02B516(x, u);
	mem_write8(x, 0x80u);
	mem_write8(x + 5u, 0x81u);
	mem_write16(x + 0xFu, 0x200u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	sub_0785C6(x);
	return u;
}

uint16_t sub_02B516(uint16_t x, uint16_t u)
{
	u = sub_02B4B7(x, u);
	if (unk_4867 == 0u)
		return u;
	sub_078674(x);
	return sub_02B4B7(x, u);
}
