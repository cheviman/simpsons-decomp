/**
 *    Name:        unsorted/bank_14.c
 *    Description: bank 14's code
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    06-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

void sub_028000(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		y = sub_028FA0(x);
		break;
	case 4:
	case 22:
	case 40:
	case 58:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case 6:
	case 24:
	case 42:
	case 60:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case 8:
	case 26:
	case 44:
	case 62:
		sub_0785E1(x, &y, &ignored16, &ignored);
		break;
	case 10:
	case 28:
	case 46:
	case 64:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_028003(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_029C70_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		u = sub_028C67(x);
		break;
	case 2:
		sub_028C93(x);
		break;
	case 4:
		y = sub_028CA4(x, y);
		break;
	case -26:
	case -12:
	case 6:
		y = sub_028CB5(x);
		break;
	case -24:
	case -10:
	case 8:
		sub_028CBE(x);
		break;
	case -34:
	case -18:
		sub_028B80(x);
		break;
	case -32:
		sub_028AFC(x);
		break;
	case -30:
		y = sub_028B26(x, y);
		break;
	case -28:
		sub_028B37(x);
		break;
	case -22:
		sub_028B4E(x);
		break;
	case -20:
		sub_028B71(x);
		break;
	case -16:
		sub_028BA4(x);
		break;
	case -14:
		y = sub_028BC6(x, y);
		break;
	case -8:
		sub_028BE0(x);
		break;
	case -6:
		sub_028BFA(x);
		break;
	case -4:
		sub_028C39(x);
		break;
	case -2:
		sub_028C4D(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_028006(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_029C7F_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		u = sub_028C67(x);
		break;
	case 2:
		sub_028CCE(x);
		break;
	case 4:
		y = sub_028CA4(x, y);
		break;
	case 6:
	case 14:
	case 22:
		y = sub_028CB5(x);
		break;
	case 8:
	case 16:
	case 24:
		sub_028CBE(x);
		break;
	case 10:
		sub_028CF5(x);
		break;
	case 12:
		y = sub_028D00(x, y);
		break;
	case 18:
		sub_028D17(x);
		break;
	case 20:
		y = sub_028D23(x, y);
		break;
	case 26:
	case 68:
		u = sub_028D43(x);
		break;
	case 28:
		sub_028D7E(x);
		break;
	case 30:
	case 72:
		y = sub_028DA3(x, y);
		break;
	case 32:
	case 74:
		sub_028DD3(x);
		break;
	case 34:
		sub_028D3A(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_028009(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_029C89_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_028CF5(x);
		break;
	case 2:
		y = sub_028D00(x, y);
		break;
	case -4:
	case 4:
	case 12:
		y = sub_028CB5(x);
		break;
	case -2:
	case 6:
	case 14:
		sub_028CBE(x);
		break;
	case 8:
		sub_028D17(x);
		break;
	case 10:
		y = sub_028D23(x, y);
		break;
	case 16:
	case 58:
		u = sub_028D43(x);
		break;
	case 18:
		sub_028D7E(x);
		break;
	case 20:
	case 62:
		y = sub_028DA3(x, y);
		break;
	case 22:
	case 64:
		sub_028DD3(x);
		break;
	case 24:
		sub_028D3A(x);
		break;
	case -10:
		u = sub_028C67(x);
		break;
	case -8:
		sub_028CCE(x);
		break;
	case -6:
		y = sub_028CA4(x, y);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_02800C(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_029C91_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_028D17(x);
		break;
	case 2:
		y = sub_028D23(x, y);
		break;
	case -12:
	case -4:
	case 4:
		y = sub_028CB5(x);
		break;
	case -10:
	case -2:
	case 6:
		sub_028CBE(x);
		break;
	case 8:
	case 50:
		u = sub_028D43(x);
		break;
	case 10:
		sub_028D7E(x);
		break;
	case 12:
	case 54:
		y = sub_028DA3(x, y);
		break;
	case 14:
	case 56:
		sub_028DD3(x);
		break;
	case 16:
		sub_028D3A(x);
		break;
	case -18:
		u = sub_028C67(x);
		break;
	case -16:
		sub_028CCE(x);
		break;
	case -14:
		y = sub_028CA4(x, y);
		break;
	case -8:
		sub_028CF5(x);
		break;
	case -6:
		y = sub_028D00(x, y);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_02800F(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_029C99_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
	case 42:
		u = sub_028D43(x);
		break;
	case 2:
		sub_028D7E(x);
		break;
	case 4:
	case 46:
		y = sub_028DA3(x, y);
		break;
	case 6:
	case 48:
		sub_028DD3(x);
		break;
	case 8:
		sub_028D3A(x);
		break;
	case -26:
		u = sub_028C67(x);
		break;
	case -24:
		sub_028CCE(x);
		break;
	case -22:
		y = sub_028CA4(x, y);
		break;
	case -20:
	case -12:
	case -4:
		y = sub_028CB5(x);
		break;
	case -18:
	case -10:
	case -2:
		sub_028CBE(x);
		break;
	case -16:
		sub_028CF5(x);
		break;
	case -14:
		y = sub_028D00(x, y);
		break;
	case -8:
		sub_028D17(x);
		break;
	case -6:
		y = sub_028D23(x, y);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_028012(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_029CC3_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case -42:
	case 0:
		u = sub_028D43(x);
		break;
	case 2:
		sub_028DF0(x);
		break;
	case -38:
	case 4:
		y = sub_028DA3(x, y);
		break;
	case -36:
	case 6:
		sub_028DD3(x);
		break;
	case 8:
		u = sub_028E14(x, u);
		break;
	case 10:
		sub_028E4C(x, &y, &u);
		break;
	case 12:
		sub_028F00(x, &y, &u, p_left_caller);
		break;
	case 14:
		sub_028F5F(x, &y, &u, p_left_caller);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_028015(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	u = loaded_table_029F5B_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02937B(x, &y, &u);
		break;
	case 2:
		sub_0293AD(x, &y, &u);
		break;
	case 4:
	case 44:
	case 56:
	case 76:
	case 96:
		sub_0785DB(x, &y, &u, &ignored);
		break;
	case 6:
	case 46:
	case 58:
	case 78:
	case 98:
		sub_0785DE(x, &y, &u, &ignored);
		break;
	case 8:
		sub_0785E1(x, &y, &u, &ignored);
		break;
	case 10:
	case 50:
	case 62:
	case 82:
	case 102:
		sub_0785E4(x, &y, &u, &ignored);
		break;
	case 12:
		u = sub_0293B6(x, u);
		break;
	case 14:
		sub_0293D0(x, &y, &u);
		break;
	case 16:
		sub_0293E1(x);
		break;
	}
	sub_078596(x, &u, p_left_caller);
	u = sub_0785B7(x, u);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_028018(uint16_t x, uint16_t y, uint8_t d)
{
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = 0x7F49u;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_029312(x, &y, &u);
		break;
	case 2:
		sub_02933A(x, y);
		break;
	case 4:
		sub_02935D(x);
		break;
	case 6:
		sub_029365(x);
		break;
	case 8:
		sub_0292F8(x);
		break;
	case 10:
		sub_029308(x);
		break;
	case -4:
	case -2:
		sub_0292EF(x, &y, &u);
		break;
	}
	u = sub_078593(x, u);
	return sub_0785B7(x, u);
}

void sub_02801B(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_028184(x, &y, &u);
		break;
	case -44:
	case -32:
	case -20:
	case -8:
	case 4:
	case 60:
	case 116:
		sub_0785DB(x, &y, &u, &ignored);
		break;
	case -42:
	case -30:
	case -18:
	case -6:
	case 6:
	case 62:
	case 118:
		sub_0785DE(x, &y, &u, &ignored);
		break;
	case -40:
	case -16:
	case -4:
	case 8:
	case 64:
	case 120:
		sub_0785E1(x, &y, &u, &ignored);
		break;
	case -38:
	case -26:
	case -14:
	case -2:
	case 10:
	case 66:
	case 122:
		sub_0785E4(x, &y, &u, &ignored);
		break;
	case -48:
		sub_0280D8(x, &y, &u);
		break;
	case -36:
		sub_0785D5(x, &y, &u);
		break;
	case -28:
		sub_078602(x, &y, &u);
		break;
	case -24:
		sub_02812B(x, &y, &u);
		break;
	case -12:
		sub_028157(x, &y, &u);
		break;
	}
	sub_078596(x, &u, p_left_caller);
	u = sub_0785B7(x, u);
	*p_y = y;
	*p_u = u;
}

void sub_02801E(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_028157(x, &y, &u);
		break;
	case -32:
	case -20:
	case -8:
	case 4:
	case 16:
	case 72:
		sub_0785DB(x, &y, &u, &ignored);
		break;
	case -30:
	case -18:
	case -6:
	case 6:
	case 18:
	case 74:
		sub_0785DE(x, &y, &u, &ignored);
		break;
	case -28:
	case -4:
	case 8:
	case 20:
	case 76:
		sub_0785E1(x, &y, &u, &ignored);
		break;
	case -26:
	case -14:
	case -2:
	case 10:
	case 22:
	case 78:
		sub_0785E4(x, &y, &u, &ignored);
		break;
	case 12:
		sub_028184(x, &y, &u);
		break;
	case -36:
		sub_0280D8(x, &y, &u);
		break;
	case -24:
		sub_0785D5(x, &y, &u);
		break;
	case -16:
		sub_078602(x, &y, &u);
		break;
	case -12:
		sub_02812B(x, &y, &u);
		break;
	}
	sub_078596(x, &u, p_left_caller);
	u = sub_0785B7(x, u);
	*p_y = y;
	*p_u = u;
}

void sub_028021(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_0785D5(x, &y, &ignored16);
		break;
	case -8:
	case 4:
	case 16:
	case 28:
	case 40:
	case 96:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case -6:
	case 6:
	case 18:
	case 30:
	case 42:
	case 98:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case 8:
		sub_078602(x, &y, &ignored16);
		break;
	case -2:
	case 10:
	case 22:
	case 34:
	case 46:
	case 102:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	case 12:
		sub_02812B(x, &y, &ignored16);
		break;
	case -4:
	case 20:
	case 32:
	case 44:
	case 100:
		sub_0785E1(x, &y, &ignored16, &ignored);
		break;
	case 24:
		sub_028157(x, &y, &ignored16);
		break;
	case 36:
		sub_028184(x, &y, &ignored16);
		break;
	case -12:
		sub_0280D8(x, &y, &ignored16);
		break;
	}
	*p_left_caller = sub_0786B9(x);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_028024(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	u = loaded_table_0299DC_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_028216(x, &y, &u);
		break;
	case 2:
		sub_028264(x, &y, &u);
		break;
	case -100:
	case -88:
	case -76:
	case -64:
	case -52:
	case 4:
	case 60:
	case 80:
	case 92:
	case 108:
	case 120:
		sub_0785DB(x, &y, &u, &ignored);
		break;
	case -98:
	case -86:
	case -74:
	case -62:
	case -50:
	case 6:
	case 62:
	case 82:
	case 94:
	case 110:
	case 122:
		sub_0785DE(x, &y, &u, &ignored);
		break;
	case -96:
	case -72:
	case -60:
	case -48:
	case 8:
	case 64:
	case 84:
	case 96:
	case 112:
	case 124:
		sub_0785E1(x, &y, &u, &ignored);
		break;
	case -94:
	case -82:
	case -70:
	case -58:
	case -46:
	case 10:
	case 66:
	case 86:
	case 98:
	case 114:
	case 126:
		sub_0785E4(x, &y, &u, &ignored);
		break;
	case 12:
		u = sub_028270(x, u);
		break;
	case 14:
		u = sub_028294(x, u);
		break;
	}
	sub_078596(x, &u, p_left_caller);
	u = sub_0785B7(x, u);
	*p_y = y;
	*p_u = u;
}

void sub_028027(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	u = loaded_table_029A50_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_0283B0(x, &y, &u);
		break;
	case -38:
	case -10:
	case 2:
		sub_0283C0(x, &y, &u);
		break;
	case -112:
	case -56:
	case -36:
	case -24:
	case -8:
	case 4:
	case 20:
	case 46:
	case 80:
	case 122:
		sub_0785DB(x, &y, &u, &ignored);
		break;
	case -110:
	case -54:
	case -34:
	case -22:
	case -6:
	case 6:
	case 22:
	case 48:
	case 82:
	case 124:
		sub_0785DE(x, &y, &u, &ignored);
		break;
	case -108:
	case -52:
	case -32:
	case -20:
	case -4:
	case 8:
	case 24:
	case 50:
	case 84:
	case 126:
		sub_0785E1(x, &y, &u, &ignored);
		break;
	case -106:
	case -50:
	case -30:
	case -18:
	case -2:
	case 10:
	case 26:
	case 52:
	case 86:
		sub_0785E4(x, &y, &u, &ignored);
		break;
	case 12:
		sub_0283CC(x);
		break;
	case 14:
		u = sub_0283E7(x, u);
		break;
	case 16:
		sub_02840B(x, &y, &u);
		break;
	case 18:
		sub_02842E(x, &y, &u);
		break;
	case 28:
		u = sub_028437(x);
		break;
	case 30:
		u = sub_028456(x, u);
		break;
	case 32:
		u = sub_028477(x, u);
		break;
	case -60:
		sub_0282B8(x, &y, &u);
		break;
	case -58:
		sub_0282C7(x, &y, &u);
		break;
	case -48:
		sub_0282D3(x);
		break;
	case -46:
		sub_0282DC(x);
		break;
	case -44:
		sub_0282F0(x);
		break;
	case -42:
		sub_028307();
		break;
	case -40:
		sub_028314(x, &y, &u);
		break;
	case -28:
		sub_028330(x, &y, &u);
		break;
	case -26:
		sub_028345(x, &y, &u);
		break;
	case -16:
		sub_028351(x);
		break;
	case -14:
		y = sub_028367(x);
		break;
	case -12:
		sub_028394(x, &y, &u);
		break;
	}
	sub_078596(x, &u, p_left_caller);
	u = sub_0785B7(x, u);
	*p_y = y;
	*p_u = u;
}

void sub_02802A(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	u = loaded_table_029A60_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02840B(x, &y, &u);
		break;
	case 2:
		sub_02842E(x, &y, &u);
		break;
	case -128:
	case -72:
	case -52:
	case -40:
	case -24:
	case -12:
	case 4:
	case 30:
	case 64:
	case 106:
		sub_0785DB(x, &y, &u, &ignored);
		break;
	case -126:
	case -70:
	case -50:
	case -38:
	case -22:
	case -10:
	case 6:
	case 32:
	case 66:
	case 108:
		sub_0785DE(x, &y, &u, &ignored);
		break;
	case -124:
	case -68:
	case -48:
	case -36:
	case -20:
	case -8:
	case 8:
	case 34:
	case 68:
	case 110:
		sub_0785E1(x, &y, &u, &ignored);
		break;
	case -122:
	case -66:
	case -46:
	case -34:
	case -18:
	case -6:
	case 10:
	case 36:
	case 70:
	case 112:
		sub_0785E4(x, &y, &u, &ignored);
		break;
	case 12:
		u = sub_028437(x);
		break;
	case 14:
		u = sub_028456(x, u);
		break;
	case 16:
		u = sub_028477(x, u);
		break;
	case -76:
		sub_0282B8(x, &y, &u);
		break;
	case -74:
		sub_0282C7(x, &y, &u);
		break;
	case -64:
		sub_0282D3(x);
		break;
	case -62:
		sub_0282DC(x);
		break;
	case -60:
		sub_0282F0(x);
		break;
	case -58:
		sub_028307();
		break;
	case -56:
		sub_028314(x, &y, &u);
		break;
	case -54:
	case -26:
	case -14:
		sub_0283C0(x, &y, &u);
		break;
	case -44:
		sub_028330(x, &y, &u);
		break;
	case -42:
		sub_028345(x, &y, &u);
		break;
	case -32:
		sub_028351(x);
		break;
	case -30:
		y = sub_028367(x);
		break;
	case -28:
		sub_028394(x, &y, &u);
		break;
	case -16:
		sub_0283B0(x, &y, &u);
		break;
	case -4:
		sub_0283CC(x);
		break;
	case -2:
		u = sub_0283E7(x, u);
		break;
	}
	sub_078596(x, &u, p_left_caller);
	u = sub_0785B7(x, u);
	*p_y = y;
	*p_u = u;
}

void sub_02802D(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t zero = 0, negative = 0;
	uint8_t b = 0;
	uint16_t u = 0;
	uint32_t ignored = 0;
	uint8_t t1 = 0;

	b = (uint8_t)d;
	u = loaded_table_029AFE_ADDRESS;
	t1 = (uint32_t)b << 1;
	negative = t1 >> 7;
	zero = t1 == 0u;
	switch ((int8_t)t1)
	{
	case 0:
		sub_028722(x, &y, &u);
		break;
	case 2:
	case 14:
		sub_02877E(x, &y, &u);
		break;
	case -128:
	case -94:
	case -52:
	case -18:
	case 4:
	case 16:
	case 66:
	case 86:
	case 98:
	case 120:
		sub_0785DB(x, &y, &u, &ignored);
		break;
	case -126:
	case -92:
	case -50:
	case -16:
	case 6:
	case 18:
	case 68:
	case 88:
	case 100:
	case 122:
		sub_0785DE(x, &y, &u, &ignored);
		break;
	case -124:
	case -90:
	case -48:
	case -14:
	case 8:
	case 20:
	case 70:
	case 90:
	case 102:
	case 124:
		sub_0785E1(x, &y, &u, &ignored);
		break;
	case -122:
	case -88:
	case -46:
	case -12:
	case 10:
	case 22:
	case 72:
	case 92:
	case 104:
	case 126:
		sub_0785E4(x, &y, &u, &ignored);
		break;
	case 12:
	case 62:
		sub_028733(x, &y, &u);
		break;
	case -102:
	case -60:
	case -26:
	case -6:
	case 58:
		sub_0285E3(x);
		break;
	case -100:
	case -58:
	case -24:
	case 60:
	case 80:
		sub_028613(x);
		break;
	case -42:
	case -38:
	case -34:
	case -30:
		sub_07D030(x, u, zero, negative);
		break;
	case -28:
		sub_028672(x);
		break;
	case -22:
		sub_028692(x, &y, &u);
		break;
	case -20:
		sub_0286C2(x, &y, &u);
		break;
	case -10:
		u = sub_0286CB(x);
		break;
	case -8:
		sub_0286DF(x);
		break;
	case -4:
		sub_0286F4(x);
		break;
	case -2:
		sub_0286FD(x);
		break;
	}
	sub_078596(x, &u, p_left_caller);
	u = sub_0785B7(x, u);
	*p_y = y;
	*p_u = u;
}

void sub_028030(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_029ECF_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02909D(x);
		break;
	case 2:
		sub_0290A9(x, &y, &u);
		break;
	case 4:
	case 20:
	case 50:
	case 58:
	case 74:
		sub_029164(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_028033(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_029EDB_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
	case 30:
		u = sub_0290D2(x);
		break;
	case 2:
		sub_0290FE(x);
		break;
	case 4:
		y = sub_02910F(x, y);
		break;
	case 6:
	case 36:
	case 44:
	case 60:
		y = sub_02915B(x);
		break;
	case -8:
	case 8:
	case 38:
	case 46:
	case 62:
		sub_029164(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_028036(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		y = sub_029424(x);
		break;
	case -10:
	case 2:
		y = sub_02945B(x, y);
		break;
	case -48:
	case -8:
	case 4:
	case 24:
	case 44:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case -46:
	case -6:
	case 6:
	case 26:
	case 46:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case -4:
	case 8:
	case 28:
	case 48:
		sub_0785FC(x, &y, &ignored16);
		break;
	case -42:
	case -2:
	case 10:
	case 30:
	case 50:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	case -12:
		y = sub_0293F7(x);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_028039(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	u = loaded_table_029FA3_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_0294B9(x, &y, &u);
		break;
	case 2:
		sub_0294FE(x, &y, &u);
		break;
	case -68:
	case -28:
	case -16:
	case 4:
	case 24:
		sub_0785DB(x, &y, &u, &ignored);
		break;
	case -66:
	case -26:
	case -14:
	case 6:
	case 26:
		sub_0785DE(x, &y, &u, &ignored);
		break;
	case -24:
	case -12:
	case 8:
	case 28:
		sub_0785FC(x, &y, &u);
		break;
	case -62:
	case -22:
	case -10:
	case 10:
	case 30:
		sub_0785E4(x, &y, &u, &ignored);
		break;
	case -4:
		sub_029464(x);
		break;
	case -2:
		u = sub_02949A(x, u);
		break;
	}
	sub_078596(x, &u, p_left_caller);
	u = sub_0785B7(x, u);
	*p_y = y;
	*p_u = u;
}

void sub_02803C(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		y = sub_0293F7(x);
		break;
	case 2:
	case 14:
		y = sub_02945B(x, y);
		break;
	case -36:
	case 4:
	case 16:
	case 36:
	case 56:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case -34:
	case 6:
	case 18:
	case 38:
	case 58:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case 8:
	case 20:
	case 40:
	case 60:
		sub_0785FC(x, &y, &ignored16);
		break;
	case -30:
	case 10:
	case 22:
	case 42:
	case 62:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	case 12:
		y = sub_029424(x);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_02803F(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	u = loaded_table_029B3C_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case -50:
	case 0:
		sub_028733(x, &y, &u);
		break;
	case 2:
		sub_0287D6(x, &y, &u);
		break;
	case -114:
	case -80:
	case -58:
	case -46:
	case 4:
	case 24:
	case 36:
	case 58:
	case 84:
		sub_0785DB(x, &y, &u, &ignored);
		break;
	case -112:
	case -78:
	case -56:
	case -44:
	case 6:
	case 26:
	case 38:
	case 60:
	case 86:
		sub_0785DE(x, &y, &u, &ignored);
		break;
	case -110:
	case -76:
	case -54:
	case -42:
	case 8:
	case 28:
	case 40:
	case 62:
	case 88:
		sub_0785E1(x, &y, &u, &ignored);
		break;
	case -108:
	case -74:
	case -52:
	case -40:
	case 10:
	case 30:
	case 42:
	case 64:
	case 90:
		sub_0785E4(x, &y, &u, &ignored);
		break;
	case 12:
		sub_0287DF(x);
		break;
	case -6:
	case 14:
		sub_0287B8(x);
		break;
	case 16:
		sub_0287ED(x);
		break;
	case -120:
	case -86:
	case -2:
	case 18:
		sub_028613(x);
		break;
	case 20:
		sub_028825(x, &y, &u);
		break;
	case 22:
	case 34:
		sub_02886E(x, &y, &u);
		break;
	case 32:
		sub_028836(x, &y, &u);
		break;
	case -122:
	case -88:
	case -68:
	case -4:
		sub_0285E3(x);
		break;
	case -12:
		sub_028787(x);
		break;
	case -10:
		sub_028796(x);
		break;
	case -8:
		sub_0287A4(x);
		break;
	}
	sub_078596(x, &u, p_left_caller);
	u = sub_0785B7(x, u);
	*p_y = y;
	*p_u = u;
}

void sub_028042(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_029CCB_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		u = sub_028E14(x, u);
		break;
	case 2:
		sub_028E4C(x, &y, &u);
		break;
	case 4:
		sub_028F00(x, &y, &u, p_left_caller);
		break;
	case 6:
		sub_028F5F(x, &y, &u, p_left_caller);
		break;
	case -50:
	case -8:
		u = sub_028D43(x);
		break;
	case -46:
	case -4:
		y = sub_028DA3(x, y);
		break;
	case -44:
	case -2:
		sub_028DD3(x);
		break;
	case -6:
		sub_028DF0(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_028045(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		y = sub_02854D(x);
		break;
	case 2:
		y = sub_0285AA(x, y);
		break;
	case -112:
	case -100:
	case -84:
	case -72:
	case -56:
	case -30:
	case 4:
	case 46:
	case 80:
	case 102:
	case 114:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case -110:
	case -98:
	case -82:
	case -70:
	case -54:
	case -28:
	case 6:
	case 48:
	case 82:
	case 104:
	case 116:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case -128:
	case -108:
	case -96:
	case -80:
	case -68:
	case -52:
	case -26:
	case 8:
	case 50:
	case 84:
	case 106:
	case 118:
		sub_0785E1(x, &y, &ignored16, &ignored);
		break;
	case -126:
	case -106:
	case -94:
	case -78:
	case -66:
	case -50:
	case -24:
	case 10:
	case 52:
	case 86:
	case 108:
	case 120:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	case -4:
	case 38:
	case 72:
	case 92:
		sub_0285E3(x);
		break;
	case -2:
	case 40:
	case 74:
		sub_028613(x);
		break;
	case -10:
		y = sub_0284D4(x, y);
		break;
	case -8:
		sub_0284F0(x);
		break;
	case -6:
		y = sub_02851B(x, y);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_028048(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t zero = 0, negative = 0;
	uint8_t b = 0;
	uint16_t ignored16 = 0, u = 0;
	uint32_t ignored = 0;
	uint8_t t1 = 0;

	b = (uint8_t)d;
	u = loaded_table_029B0A_ADDRESS;
	t1 = (uint32_t)b << 1;
	negative = t1 >> 7;
	zero = t1 == 0u;
	switch ((int8_t)t1)
	{
	case 0:
	case 50:
		sub_028733(x, &y, &u);
		break;
	case -10:
	case 2:
		sub_02877E(x, &y, &u);
		break;
	case -106:
	case -64:
	case -30:
	case -8:
	case 4:
	case 54:
	case 74:
	case 86:
	case 108:
		sub_0785DB(x, &y, &u, &ignored);
		break;
	case -104:
	case -62:
	case -28:
	case -6:
	case 6:
	case 56:
	case 76:
	case 88:
	case 110:
		sub_0785DE(x, &y, &u, &ignored);
		break;
	case -102:
	case -60:
	case -26:
	case -4:
	case 8:
	case 58:
	case 78:
	case 90:
	case 112:
		sub_0785E1(x, &y, &u, &ignored);
		break;
	case -100:
	case -58:
	case -24:
	case -2:
	case 10:
	case 60:
	case 80:
	case 92:
	case 114:
		sub_0785E4(x, &y, &u, &ignored);
		break;
	case -114:
	case -72:
	case -38:
	case -18:
	case 46:
		sub_0285E3(x);
		break;
	case -112:
	case -70:
	case -36:
	case 48:
	case 68:
		sub_028613(x);
		break;
	case -54:
	case -50:
	case -46:
	case -42:
		sub_07D030(x, u, zero, negative);
		break;
	case -40:
		sub_028672(x);
		break;
	case -34:
		sub_028692(x, &y, &u);
		break;
	case -32:
		sub_0286C2(x, &y, &u);
		break;
	case -22:
		sub_0286CB(x);
		break;
	case -20:
		sub_0286DF(x);
		break;
	case -16:
		sub_0286F4(x);
		break;
	case -14:
		sub_0286FD(x);
		break;
	case -12:
		sub_028722(x, &y, &u);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_02804B(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = hit_box_0299CE_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_028197(x, &y, &u);
		break;
	case 2:
		u = sub_0281DD(x);
		break;
	case 4:
		sub_0281EB(x);
		break;
	case 6:
		sub_0281F5(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_02804E(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_028895(x, &y, &ignored16);
		break;
	case 2:
		sub_0288DB(x, &y, &ignored16);
		break;
	case -112:
	case -100:
	case -50:
	case -30:
	case -18:
	case 4:
	case 30:
	case 78:
	case 102:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case -110:
	case -98:
	case -48:
	case -28:
	case -16:
	case 6:
	case 32:
	case 80:
	case 104:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case -108:
	case -96:
	case -46:
	case -26:
	case -14:
	case 8:
	case 34:
	case 82:
	case 106:
		sub_0785E1(x, &y, &ignored16, &ignored);
		break;
	case -128:
	case -106:
	case -94:
	case -44:
	case -24:
	case -12:
	case 10:
	case 36:
	case 84:
	case 108:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	case -4:
	case 22:
		sub_02890B(x);
		break;
	case -2:
	case 24:
		sub_028925(x);
		break;
	case -6:
		sub_028877(x);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_028051(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02893D(x, &y, &ignored16);
		break;
	case 2:
		sub_028976(x, &y, &ignored16);
		break;
	case -126:
	case -76:
	case -56:
	case -44:
	case -22:
	case 4:
	case 52:
	case 76:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case -124:
	case -74:
	case -54:
	case -42:
	case -20:
	case 6:
	case 54:
	case 78:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case -122:
	case -72:
	case -52:
	case -40:
	case -18:
	case 8:
	case 56:
	case 80:
		sub_0785E1(x, &y, &ignored16, &ignored);
		break;
	case -120:
	case -70:
	case -50:
	case -38:
	case -16:
	case 10:
	case 58:
	case 82:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	case -30:
	case -4:
		sub_02890B(x);
		break;
	case -28:
	case -2:
		sub_028925(x);
		break;
	case -6:
		sub_0288E4(x, 0u);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_028054(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		y = sub_02849C(x);
		break;
	case 2:
		y = sub_0284CB(x, y);
		break;
	case -98:
	case -78:
	case -66:
	case -50:
	case -38:
	case -22:
	case 4:
	case 38:
	case 80:
	case 114:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case -96:
	case -76:
	case -64:
	case -48:
	case -36:
	case -20:
	case 6:
	case 40:
	case 82:
	case 116:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case -94:
	case -74:
	case -62:
	case -46:
	case -34:
	case -18:
	case 8:
	case 42:
	case 84:
	case 118:
		sub_0785E1(x, &y, &ignored16, &ignored);
		break;
	case -92:
	case -72:
	case -60:
	case -44:
	case -32:
	case -16:
	case 10:
	case 44:
	case 86:
	case 120:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_028057(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		y = sub_028633(x);
		break;
	case 2:
		y = sub_028669(x, y);
		break;
	case -126:
	case -114:
	case -98:
	case -72:
	case -38:
	case 4:
	case 38:
	case 60:
	case 72:
	case 122:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case -124:
	case -112:
	case -96:
	case -70:
	case -36:
	case 6:
	case 40:
	case 62:
	case 74:
	case 124:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case -122:
	case -110:
	case -94:
	case -68:
	case -34:
	case 8:
	case 42:
	case 64:
	case 76:
	case 126:
		sub_0785E1(x, &y, &ignored16, &ignored);
		break;
	case -120:
	case -108:
	case -92:
	case -66:
	case -32:
	case 10:
	case 44:
	case 66:
	case 78:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	case -46:
	case -4:
	case 30:
	case 50:
	case 114:
		sub_0285E3(x);
		break;
	case -44:
	case -2:
	case 32:
	case 116:
		sub_028613(x);
		break;
	case -8:
		sub_0285B3(x);
		break;
	case -6:
		sub_0285C4(x, 0u);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_02805A(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_028A12(x, &y, &ignored16);
		break;
	case 2:
		sub_028A3E(x, &y, &ignored16);
		break;
	case -124:
	case -104:
	case -92:
	case -70:
	case -44:
	case 4:
	case 28:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case -122:
	case -102:
	case -90:
	case -68:
	case -42:
	case 6:
	case 30:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case -120:
	case -100:
	case -88:
	case -66:
	case -40:
	case 8:
	case 32:
		sub_0785E1(x, &y, &ignored16, &ignored);
		break;
	case -118:
	case -98:
	case -86:
	case -64:
	case -38:
	case 10:
	case 34:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	case -12:
	case 16:
		sub_02897F(x);
		break;
	case -4:
	case 20:
		sub_0289F2(x);
		break;
	case -2:
	case 22:
		sub_0289F5(x);
		break;
	case -10:
		sub_02898B(x);
		break;
	case -8:
		sub_0289A1(x, 0u);
		break;
	case -6:
		sub_0289BC(x);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_02805D(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_029C68_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_028BE0(x);
		break;
	case 2:
		sub_028BFA(x);
		break;
	case 4:
		sub_028C39(x);
		break;
	case 6:
		sub_028C4D(x);
		break;
	case 8:
		u = sub_028C67(x);
		break;
	case 10:
		sub_028C93(x);
		break;
	case 12:
		y = sub_028CA4(x, y);
		break;
	case -18:
	case -4:
	case 14:
		y = sub_028CB5(x);
		break;
	case -16:
	case -2:
	case 16:
		sub_028CBE(x);
		break;
	case -26:
	case -10:
		sub_028B80(x);
		break;
	case -24:
		sub_028AFC(x);
		break;
	case -22:
		y = sub_028B26(x, y);
		break;
	case -20:
		sub_028B37(x);
		break;
	case -14:
		sub_028B4E(x);
		break;
	case -12:
		sub_028B71(x);
		break;
	case -8:
		sub_028BA4(x);
		break;
	case -6:
		y = sub_028BC6(x, y);
		break;
	}
	sub_0785C9(x);
	*p_y = y;
	*p_u = u;
}

void sub_028060(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02956B(x, &y, &ignored16);
		break;
	case 2:
		sub_0295A5(x);
		break;
	case -88:
	case -48:
	case -36:
	case -16:
	case 4:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case -86:
	case -46:
	case -34:
	case -14:
	case 6:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case -44:
	case -32:
	case -12:
	case 8:
		sub_0785FC(x, &y, &ignored16);
		break;
	case -82:
	case -42:
	case -30:
	case -10:
	case 10:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	case -4:
		sub_029507(x);
		break;
	case -2:
		sub_029546(x, &y, &ignored16);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_028063(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02812B(x, &y, &ignored16);
		break;
	case -20:
	case -8:
	case 4:
	case 16:
	case 28:
	case 84:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case -18:
	case -6:
	case 6:
	case 18:
	case 30:
	case 86:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case -16:
	case 8:
	case 20:
	case 32:
	case 88:
		sub_0785E1(x, &y, &ignored16, &ignored);
		break;
	case -14:
	case -2:
	case 10:
	case 22:
	case 34:
	case 90:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	case 12:
		sub_028157(x, &y, &ignored16);
		break;
	case 24:
		sub_028184(x, &y, &ignored16);
		break;
	case -24:
		sub_0280D8(x, &y, &ignored16);
		break;
	case -12:
		sub_0785D5(x, &y, &ignored16);
		break;
	case -4:
		sub_078602(x, &y, &ignored16);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_028066(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_028A62(x, &y, &ignored16);
		break;
	case 2:
		sub_028AAA(x);
		break;
	case -128:
	case -116:
	case -94:
	case -68:
	case -20:
	case 4:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case -126:
	case -114:
	case -92:
	case -66:
	case -18:
	case 6:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case -124:
	case -112:
	case -90:
	case -64:
	case -16:
	case 8:
		sub_0785E1(x, &y, &ignored16, &ignored);
		break;
	case -122:
	case -110:
	case -88:
	case -62:
	case -14:
	case 10:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	case -36:
	case -8:
		sub_02897F(x);
		break;
	case -28:
	case -4:
		sub_0289F2(x);
		break;
	case -26:
	case -2:
		sub_0289F5(x);
		break;
	case -6:
		sub_028A47(x);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_028069(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_0282B8(x, &y, &ignored16);
		break;
	case 2:
		sub_0282C7(x, &y, &ignored16);
		break;
	case -120:
	case -108:
	case -52:
	case 4:
	case 24:
	case 36:
	case 52:
	case 64:
	case 80:
	case 106:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case -118:
	case -106:
	case -50:
	case 6:
	case 26:
	case 38:
	case 54:
	case 66:
	case 82:
	case 108:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case -128:
	case -116:
	case -104:
	case -48:
	case 8:
	case 28:
	case 40:
	case 56:
	case 68:
	case 84:
	case 110:
		sub_0785E1(x, &y, &ignored16, &ignored);
		break;
	case -126:
	case -114:
	case -102:
	case -46:
	case 10:
	case 30:
	case 42:
	case 58:
	case 70:
	case 86:
	case 112:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	case 12:
		sub_0282D3(x);
		break;
	case 14:
		sub_0282DC(x);
		break;
	case 16:
		sub_0282F0(x);
		break;
	case 18:
		sub_028307();
		break;
	case 20:
		sub_028314(x, &y, &ignored16);
		break;
	case 22:
	case 50:
	case 62:
		sub_0283C0(x, &y, &ignored16);
		break;
	case 32:
		sub_028330(x, &y, &ignored16);
		break;
	case 34:
		sub_028345(x, &y, &ignored16);
		break;
	case 44:
		sub_028351(x);
		break;
	case 46:
		y = sub_028367(x);
		break;
	case 48:
		sub_028394(x, &y, &ignored16);
		break;
	case 60:
		sub_0283B0(x, &y, &ignored16);
		break;
	case 72:
		sub_0283CC(x);
		break;
	case 74:
		sub_0283E7(x, 0u);
		break;
	case 76:
		sub_02840B(x, &y, &ignored16);
		break;
	case 78:
		sub_02842E(x, &y, &ignored16);
		break;
	case 88:
		sub_028437(x);
		break;
	case 90:
		sub_028456(x, 0u);
		break;
	case 92:
		sub_028477(x, 0u);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_02806C(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t zero = 0, negative = 0;
	uint8_t b = 0;
	uint16_t ignored16 = 0, u = 0;
	uint32_t ignored = 0;
	uint8_t t1 = 0;

	b = (uint8_t)d;
	u = loaded_table_029AE8_ADDRESS;
	t1 = (uint32_t)b << 1;
	negative = t1 >> 7;
	zero = t1 == 0u;
	switch ((int8_t)t1)
	{
	case 0:
		sub_028692(x, &y, &u);
		break;
	case 2:
		sub_0286C2(x, &y, &u);
		break;
	case -106:
	case -72:
	case -30:
	case 4:
	case 26:
	case 38:
	case 88:
	case 108:
	case 120:
		sub_0785DB(x, &y, &u, &ignored);
		break;
	case -104:
	case -70:
	case -28:
	case 6:
	case 28:
	case 40:
	case 90:
	case 110:
	case 122:
		sub_0785DE(x, &y, &u, &ignored);
		break;
	case -128:
	case -102:
	case -68:
	case -26:
	case 8:
	case 30:
	case 42:
	case 92:
	case 112:
	case 124:
		sub_0785E1(x, &y, &u, &ignored);
		break;
	case -126:
	case -100:
	case -66:
	case -24:
	case 10:
	case 32:
	case 44:
	case 94:
	case 114:
	case 126:
		sub_0785E4(x, &y, &u, &ignored);
		break;
	case 12:
		sub_0286CB(x);
		break;
	case 14:
		sub_0286DF(x);
		break;
	case -80:
	case -38:
	case -4:
	case 16:
	case 80:
		sub_0285E3(x);
		break;
	case 18:
		sub_0286F4(x);
		break;
	case 20:
		sub_0286FD(x);
		break;
	case 22:
		sub_028722(x, &y, &u);
		break;
	case 24:
	case 36:
		sub_02877E(x, &y, &u);
		break;
	case 34:
	case 84:
		sub_028733(x, &y, &u);
		break;
	case -78:
	case -36:
	case -2:
	case 82:
	case 102:
		sub_028613(x);
		break;
	case -20:
	case -16:
	case -12:
	case -8:
		sub_07D030(x, u, zero, negative);
		break;
	case -6:
		sub_028672(x);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_02806F(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_028394(x, &y, &ignored16);
		break;
	case -26:
	case 2:
	case 14:
		sub_0283C0(x, &y, &ignored16);
		break;
	case -100:
	case -44:
	case -24:
	case -12:
	case 4:
	case 16:
	case 32:
	case 58:
	case 92:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case -98:
	case -42:
	case -22:
	case -10:
	case 6:
	case 18:
	case 34:
	case 60:
	case 94:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case -96:
	case -40:
	case -20:
	case -8:
	case 8:
	case 20:
	case 36:
	case 62:
	case 96:
		sub_0785E1(x, &y, &ignored16, &ignored);
		break;
	case -94:
	case -38:
	case -18:
	case -6:
	case 10:
	case 22:
	case 38:
	case 64:
	case 98:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	case 12:
		sub_0283B0(x, &y, &ignored16);
		break;
	case 24:
		sub_0283CC(x);
		break;
	case 26:
		sub_0283E7(x, 0u);
		break;
	case 28:
		sub_02840B(x, &y, &ignored16);
		break;
	case 30:
		sub_02842E(x, &y, &ignored16);
		break;
	case 40:
		sub_028437(x);
		break;
	case 42:
		sub_028456(x, 0u);
		break;
	case 44:
		sub_028477(x, 0u);
		break;
	case -48:
		sub_0282B8(x, &y, &ignored16);
		break;
	case -46:
		sub_0282C7(x, &y, &ignored16);
		break;
	case -36:
		sub_0282D3(x);
		break;
	case -34:
		sub_0282DC(x);
		break;
	case -32:
		sub_0282F0(x);
		break;
	case -30:
		sub_028307();
		break;
	case -28:
		sub_028314(x, &y, &ignored16);
		break;
	case -16:
		sub_028330(x, &y, &ignored16);
		break;
	case -14:
		sub_028345(x, &y, &ignored16);
		break;
	case -4:
		sub_028351(x);
		break;
	case -2:
		y = sub_028367(x);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_028072(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		y = sub_028FE6(x);
		break;
	case -14:
	case 4:
	case 22:
	case 40:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case -12:
	case 6:
	case 24:
	case 42:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case -10:
	case 8:
	case 26:
	case 44:
		sub_0785E1(x, &y, &ignored16, &ignored);
		break;
	case -8:
	case 10:
	case 28:
	case 46:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_028075(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		y = sub_029039(x);
		break;
	case -32:
	case -14:
	case 4:
	case 22:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case -30:
	case -12:
	case 6:
	case 24:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case -28:
	case -10:
	case 8:
	case 26:
		sub_0785E1(x, &y, &ignored16, &ignored);
		break;
	case -26:
	case -8:
	case 10:
	case 28:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_028078(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		y = sub_029082(x);
		break;
	case -50:
	case -32:
	case -14:
	case 4:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case -48:
	case -30:
	case -12:
	case 6:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case -46:
	case -28:
	case -10:
	case 8:
		sub_0785E1(x, &y, &ignored16, &ignored);
		break;
	case -44:
	case -26:
	case -8:
	case 10:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_02807B(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_0280D8(x, &y, &ignored16);
		break;
	case 4:
	case 16:
	case 28:
	case 40:
	case 52:
	case 108:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case 6:
	case 18:
	case 30:
	case 42:
	case 54:
	case 110:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case 8:
	case 32:
	case 44:
	case 56:
	case 112:
		sub_0785E1(x, &y, &ignored16, &ignored);
		break;
	case 10:
	case 22:
	case 34:
	case 46:
	case 58:
	case 114:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	case 12:
		sub_0785D5(x, &y, &ignored16);
		break;
	case 20:
		sub_078602(x, &y, &ignored16);
		break;
	case 24:
		sub_02812B(x, &y, &ignored16);
		break;
	case 36:
		sub_028157(x, &y, &ignored16);
		break;
	case 48:
		sub_028184(x, &y, &ignored16);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_028084(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_029F27_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02929C(x);
		break;
	case 2:
		sub_0292A7(x, &y, &u);
		break;
	case 4:
		u = sub_0292C3(x);
		break;
	case 6:
		sub_0292DA(x);
		break;
	case -84:
	case -68:
	case -38:
	case -30:
	case -14:
		sub_029164(x);
		break;
	case -76:
	case -46:
		u = sub_0290D2(x);
		break;
	case -70:
	case -40:
	case -32:
	case -16:
		y = sub_02915B(x);
		break;
	case -44:
		sub_029174(x);
		break;
	case -42:
		y = sub_029185(x, y);
		break;
	case -36:
		sub_02919C(x);
		break;
	case -34:
		y = sub_0291A8(x, y);
		break;
	case -28:
		sub_0291BF(x);
		break;
	case -26:
		y = sub_0291CB(x, y);
		break;
	case -24:
		y = sub_0291E1(x, y);
		break;
	case -22:
		sub_0291F5(x);
		break;
	case -20:
		sub_0291FE(x);
		break;
	case -18:
		y = sub_02920A(x, y);
		break;
	case -12:
		sub_029221(x);
		break;
	case -10:
		y = sub_029232(x, y);
		break;
	case -8:
	case -2:
		y = sub_029261(x, y);
		break;
	case -6:
		sub_029276(x);
		break;
	case -4:
		y = sub_029287(x, y);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_028087(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_029F13_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_0291FE(x);
		break;
	case 2:
		y = sub_02920A(x, y);
		break;
	case -50:
	case -20:
	case -12:
	case 4:
		y = sub_02915B(x);
		break;
	case -64:
	case -48:
	case -18:
	case -10:
	case 6:
		sub_029164(x);
		break;
	case 8:
		sub_029221(x);
		break;
	case 10:
		y = sub_029232(x, y);
		break;
	case 12:
	case 18:
		y = sub_029261(x, y);
		break;
	case 14:
		sub_029276(x);
		break;
	case 16:
		y = sub_029287(x, y);
		break;
	case 20:
		sub_02929C(x);
		break;
	case 22:
		sub_0292A7(x, &y, &u);
		break;
	case 24:
		u = sub_0292C3(x);
		break;
	case 26:
		sub_0292DA(x);
		break;
	case -56:
	case -26:
		u = sub_0290D2(x);
		break;
	case -24:
		sub_029174(x);
		break;
	case -22:
		y = sub_029185(x, y);
		break;
	case -16:
		sub_02919C(x);
		break;
	case -14:
		y = sub_0291A8(x, y);
		break;
	case -8:
		sub_0291BF(x);
		break;
	case -6:
		y = sub_0291CB(x, y);
		break;
	case -4:
		y = sub_0291E1(x, y);
		break;
	case -2:
		sub_0291F5(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_02808A(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_029F1B_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_029221(x);
		break;
	case 2:
		y = sub_029232(x, y);
		break;
	case 4:
	case 10:
		y = sub_029261(x, y);
		break;
	case 6:
		sub_029276(x);
		break;
	case 8:
		y = sub_029287(x, y);
		break;
	case 12:
		sub_02929C(x);
		break;
	case 14:
		sub_0292A7(x, &y, &u);
		break;
	case 16:
		u = sub_0292C3(x);
		break;
	case 18:
		sub_0292DA(x);
		break;
	case -72:
	case -56:
	case -26:
	case -18:
	case -2:
		sub_029164(x);
		break;
	case -64:
	case -34:
		u = sub_0290D2(x);
		break;
	case -58:
	case -28:
	case -20:
	case -4:
		y = sub_02915B(x);
		break;
	case -32:
		sub_029174(x);
		break;
	case -30:
		y = sub_029185(x, y);
		break;
	case -24:
		sub_02919C(x);
		break;
	case -22:
		y = sub_0291A8(x, y);
		break;
	case -16:
		sub_0291BF(x);
		break;
	case -14:
		y = sub_0291CB(x, y);
		break;
	case -12:
		y = sub_0291E1(x, y);
		break;
	case -10:
		sub_0291F5(x);
		break;
	case -8:
		sub_0291FE(x);
		break;
	case -6:
		y = sub_02920A(x, y);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_02808D(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_029F0B_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_0291BF(x);
		break;
	case 2:
		y = sub_0291CB(x, y);
		break;
	case 4:
		y = sub_0291E1(x, y);
		break;
	case 6:
		sub_0291F5(x);
		break;
	case 8:
		sub_0291FE(x);
		break;
	case 10:
		y = sub_02920A(x, y);
		break;
	case -42:
	case -12:
	case -4:
	case 12:
		y = sub_02915B(x);
		break;
	case -56:
	case -40:
	case -10:
	case -2:
	case 14:
		sub_029164(x);
		break;
	case 16:
		sub_029221(x);
		break;
	case 18:
		y = sub_029232(x, y);
		break;
	case 20:
	case 26:
		y = sub_029261(x, y);
		break;
	case 22:
		sub_029276(x);
		break;
	case 24:
		y = sub_029287(x, y);
		break;
	case 28:
		sub_02929C(x);
		break;
	case 30:
		sub_0292A7(x, &y, &u);
		break;
	case 32:
		u = sub_0292C3(x);
		break;
	case 34:
		sub_0292DA(x);
		break;
	case -48:
	case -18:
		u = sub_0290D2(x);
		break;
	case -16:
		sub_029174(x);
		break;
	case -14:
		y = sub_029185(x, y);
		break;
	case -8:
		sub_02919C(x);
		break;
	case -6:
		y = sub_0291A8(x, y);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_028090(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_029EF9_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case -30:
	case 0:
		u = sub_0290D2(x);
		break;
	case 2:
		sub_029174(x);
		break;
	case 4:
		y = sub_029185(x, y);
		break;
	case -24:
	case 6:
	case 14:
	case 30:
		y = sub_02915B(x);
		break;
	case -38:
	case -22:
	case 8:
	case 16:
	case 32:
		sub_029164(x);
		break;
	case 10:
		sub_02919C(x);
		break;
	case 12:
		y = sub_0291A8(x, y);
		break;
	case 18:
		sub_0291BF(x);
		break;
	case 20:
		y = sub_0291CB(x, y);
		break;
	case 22:
		y = sub_0291E1(x, y);
		break;
	case 24:
		sub_0291F5(x);
		break;
	case 26:
		sub_0291FE(x);
		break;
	case 28:
		y = sub_02920A(x, y);
		break;
	case 34:
		sub_029221(x);
		break;
	case 36:
		y = sub_029232(x, y);
		break;
	case 38:
	case 44:
		y = sub_029261(x, y);
		break;
	case 40:
		sub_029276(x);
		break;
	case 42:
		y = sub_029287(x, y);
		break;
	case 46:
		sub_02929C(x);
		break;
	case 48:
		sub_0292A7(x, &y, &u);
		break;
	case 50:
		u = sub_0292C3(x);
		break;
	case 52:
		sub_0292DA(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_028093(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_029EEA_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		u = sub_029126(x);
		break;
	case 2:
		sub_02913C(x);
		break;
	case 4:
		y = sub_02914A(x, y);
		break;
	case 6:
		y = sub_02915B(x);
		break;
	case 8:
		sub_029164(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void unused_028096(uint16_t x)
{
	uint16_t ignored16 = 0, ignored16_2 = 0;

	sub_028FC1(x, &ignored16, &ignored16_2);
}

void unused_028099(uint16_t x)
{
	uint16_t ignored16 = 0, ignored16_2 = 0;

	sub_029012(x, &ignored16, &ignored16_2);
}

void unreached_02809C(uint16_t x)
{
	uint16_t ignored16 = 0, ignored16_2 = 0;

	sub_02905A(x, &ignored16, &ignored16_2);
}

void sub_02809F(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_028836(x, &y, &ignored16);
		break;
	case -10:
	case 2:
		sub_02886E(x, &y, &ignored16);
		break;
	case -112:
	case -90:
	case -78:
	case -28:
	case -8:
	case 4:
	case 26:
	case 52:
	case 100:
	case 124:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case -110:
	case -88:
	case -76:
	case -26:
	case -6:
	case 6:
	case 28:
	case 54:
	case 102:
	case 126:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case -108:
	case -86:
	case -74:
	case -24:
	case -4:
	case 8:
	case 30:
	case 56:
	case 104:
		sub_0785E1(x, &y, &ignored16, &ignored);
		break;
	case -106:
	case -84:
	case -72:
	case -22:
	case -2:
	case 10:
	case 32:
	case 58:
	case 106:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	case -120:
	case -100:
	case -36:
		sub_0285E3(x);
		break;
	case -118:
	case -34:
	case -14:
		sub_028613(x);
		break;
	case -82:
	case -32:
		sub_028733(x, &y, &ignored16);
		break;
	case -44:
		sub_028787(x);
		break;
	case -42:
		sub_028796(x);
		break;
	case -40:
		sub_0287A4(x);
		break;
	case -38:
	case -18:
		sub_0287B8(x);
		break;
	case -30:
		sub_0287D6(x, &y, &ignored16);
		break;
	case -20:
		sub_0287DF(x);
		break;
	case -16:
		sub_0287ED(x);
		break;
	case -12:
		sub_028825(x, &y, &ignored16);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_0280A2(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_028330(x, &y, &ignored16);
		break;
	case 2:
		sub_028345(x, &y, &ignored16);
		break;
	case -84:
	case -28:
	case -8:
	case 4:
	case 20:
	case 32:
	case 48:
	case 74:
	case 108:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case -82:
	case -26:
	case -6:
	case 6:
	case 22:
	case 34:
	case 50:
	case 76:
	case 110:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case -80:
	case -24:
	case -4:
	case 8:
	case 24:
	case 36:
	case 52:
	case 78:
	case 112:
		sub_0785E1(x, &y, &ignored16, &ignored);
		break;
	case -78:
	case -22:
	case -2:
	case 10:
	case 26:
	case 38:
	case 54:
	case 80:
	case 114:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	case 12:
		sub_028351(x);
		break;
	case 14:
		y = sub_028367(x);
		break;
	case 16:
		sub_028394(x, &y, &ignored16);
		break;
	case -10:
	case 18:
	case 30:
		sub_0283C0(x, &y, &ignored16);
		break;
	case 28:
		sub_0283B0(x, &y, &ignored16);
		break;
	case 40:
		sub_0283CC(x);
		break;
	case 42:
		sub_0283E7(x, 0u);
		break;
	case 44:
		sub_02840B(x, &y, &ignored16);
		break;
	case 46:
		sub_02842E(x, &y, &ignored16);
		break;
	case 56:
		sub_028437(x);
		break;
	case 58:
		sub_028456(x, 0u);
		break;
	case 60:
		sub_028477(x, 0u);
		break;
	case -32:
		sub_0282B8(x, &y, &ignored16);
		break;
	case -30:
		sub_0282C7(x, &y, &ignored16);
		break;
	case -20:
		sub_0282D3(x);
		break;
	case -18:
		sub_0282DC(x);
		break;
	case -16:
		sub_0282F0(x);
		break;
	case -14:
		sub_028307();
		break;
	case -12:
		sub_028314(x, &y, &ignored16);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_0280A5(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_028314(x, &y, &ignored16);
		break;
	case 2:
	case 30:
	case 42:
		sub_0283C0(x, &y, &ignored16);
		break;
	case -128:
	case -72:
	case -16:
	case 4:
	case 16:
	case 32:
	case 44:
	case 60:
	case 86:
	case 120:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case -126:
	case -70:
	case -14:
	case 6:
	case 18:
	case 34:
	case 46:
	case 62:
	case 88:
	case 122:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case -124:
	case -68:
	case -12:
	case 8:
	case 20:
	case 36:
	case 48:
	case 64:
	case 90:
	case 124:
		sub_0785E1(x, &y, &ignored16, &ignored);
		break;
	case -122:
	case -66:
	case -10:
	case 10:
	case 22:
	case 38:
	case 50:
	case 66:
	case 92:
	case 126:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	case 12:
		sub_028330(x, &y, &ignored16);
		break;
	case 14:
		sub_028345(x, &y, &ignored16);
		break;
	case 24:
		sub_028351(x);
		break;
	case 26:
		y = sub_028367(x);
		break;
	case 28:
		sub_028394(x, &y, &ignored16);
		break;
	case 40:
		sub_0283B0(x, &y, &ignored16);
		break;
	case 52:
		sub_0283CC(x);
		break;
	case 54:
		sub_0283E7(x, 0u);
		break;
	case 56:
		sub_02840B(x, &y, &ignored16);
		break;
	case 58:
		sub_02842E(x, &y, &ignored16);
		break;
	case 68:
		sub_028437(x);
		break;
	case 70:
		sub_028456(x, 0u);
		break;
	case 72:
		sub_028477(x, 0u);
		break;
	case -20:
		sub_0282B8(x, &y, &ignored16);
		break;
	case -18:
		sub_0282C7(x, &y, &ignored16);
		break;
	case -8:
		sub_0282D3(x);
		break;
	case -6:
		sub_0282DC(x);
		break;
	case -4:
		sub_0282F0(x);
		break;
	case -2:
		sub_028307();
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_0280A8(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_028825(x, &y, &ignored16);
		break;
	case 2:
	case 14:
		sub_02886E(x, &y, &ignored16);
		break;
	case -100:
	case -78:
	case -66:
	case -16:
	case 4:
	case 16:
	case 38:
	case 64:
	case 112:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case -98:
	case -76:
	case -64:
	case -14:
	case 6:
	case 18:
	case 40:
	case 66:
	case 114:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case -96:
	case -74:
	case -62:
	case -12:
	case 8:
	case 20:
	case 42:
	case 68:
	case 116:
		sub_0785E1(x, &y, &ignored16, &ignored);
		break;
	case -128:
	case -94:
	case -72:
	case -60:
	case -10:
	case 10:
	case 22:
	case 44:
	case 70:
	case 118:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	case 12:
		sub_028836(x, &y, &ignored16);
		break;
	case -108:
	case -88:
	case -24:
		sub_0285E3(x);
		break;
	case -106:
	case -22:
	case -2:
		sub_028613(x);
		break;
	case -70:
	case -20:
		sub_028733(x, &y, &ignored16);
		break;
	case -32:
		sub_028787(x);
		break;
	case -30:
		sub_028796(x);
		break;
	case -28:
		sub_0287A4(x);
		break;
	case -26:
	case -6:
		sub_0287B8(x);
		break;
	case -18:
		sub_0287D6(x, &y, &ignored16);
		break;
	case -8:
		sub_0287DF(x);
		break;
	case -4:
		sub_0287ED(x);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_0280AB(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_029C5A_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_028B4E(x);
		break;
	case 2:
		sub_028B71(x);
		break;
	case -12:
	case 4:
		sub_028B80(x);
		break;
	case 6:
		sub_028BA4(x);
		break;
	case 8:
		y = sub_028BC6(x, y);
		break;
	case -4:
	case 10:
	case 28:
		y = sub_028CB5(x);
		break;
	case -2:
	case 12:
	case 30:
		sub_028CBE(x);
		break;
	case 14:
		sub_028BE0(x);
		break;
	case 16:
		sub_028BFA(x);
		break;
	case 18:
		sub_028C39(x);
		break;
	case 20:
		sub_028C4D(x);
		break;
	case 22:
		u = sub_028C67(x);
		break;
	case 24:
		sub_028C93(x);
		break;
	case 26:
		y = sub_028CA4(x, y);
		break;
	case -10:
		sub_028AFC(x);
		break;
	case -8:
		y = sub_028B26(x, y);
		break;
	case -6:
		sub_028B37(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_0280AE(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_029F21_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_029276(x);
		break;
	case 2:
		y = sub_029287(x, y);
		break;
	case -2:
	case 4:
		y = sub_029261(x, y);
		break;
	case 6:
		sub_02929C(x);
		break;
	case 8:
		sub_0292A7(x, &y, &u);
		break;
	case 10:
		u = sub_0292C3(x);
		break;
	case 12:
		sub_0292DA(x);
		break;
	case -78:
	case -62:
	case -32:
	case -24:
	case -8:
		sub_029164(x);
		break;
	case -70:
	case -40:
		u = sub_0290D2(x);
		break;
	case -64:
	case -34:
	case -26:
	case -10:
		y = sub_02915B(x);
		break;
	case -38:
		sub_029174(x);
		break;
	case -36:
		y = sub_029185(x, y);
		break;
	case -30:
		sub_02919C(x);
		break;
	case -28:
		y = sub_0291A8(x, y);
		break;
	case -22:
		sub_0291BF(x);
		break;
	case -20:
		y = sub_0291CB(x, y);
		break;
	case -18:
		y = sub_0291E1(x, y);
		break;
	case -16:
		sub_0291F5(x);
		break;
	case -14:
		sub_0291FE(x);
		break;
	case -12:
		y = sub_02920A(x, y);
		break;
	case -6:
		sub_029221(x);
		break;
	case -4:
		y = sub_029232(x, y);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_0280B4(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_029F03_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02919C(x);
		break;
	case 2:
		y = sub_0291A8(x, y);
		break;
	case -34:
	case -4:
	case 4:
	case 20:
		y = sub_02915B(x);
		break;
	case -48:
	case -32:
	case -2:
	case 6:
	case 22:
		sub_029164(x);
		break;
	case 8:
		sub_0291BF(x);
		break;
	case 10:
		y = sub_0291CB(x, y);
		break;
	case 12:
		y = sub_0291E1(x, y);
		break;
	case 14:
		sub_0291F5(x);
		break;
	case 16:
		sub_0291FE(x);
		break;
	case 18:
		y = sub_02920A(x, y);
		break;
	case 24:
		sub_029221(x);
		break;
	case 26:
		y = sub_029232(x, y);
		break;
	case 28:
	case 34:
		y = sub_029261(x, y);
		break;
	case 30:
		sub_029276(x);
		break;
	case 32:
		y = sub_029287(x, y);
		break;
	case 36:
		sub_02929C(x);
		break;
	case 38:
		sub_0292A7(x, &y, &u);
		break;
	case 40:
		u = sub_0292C3(x);
		break;
	case 42:
		sub_0292DA(x);
		break;
	case -40:
	case -10:
		u = sub_0290D2(x);
		break;
	case -8:
		sub_029174(x);
		break;
	case -6:
		y = sub_029185(x, y);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_0280B7(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_029C5E_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case -16:
	case 0:
		sub_028B80(x);
		break;
	case 2:
		sub_028BA4(x);
		break;
	case 4:
		y = sub_028BC6(x, y);
		break;
	case -8:
	case 6:
	case 24:
		y = sub_028CB5(x);
		break;
	case -6:
	case 8:
	case 26:
		sub_028CBE(x);
		break;
	case 10:
		sub_028BE0(x);
		break;
	case 12:
		sub_028BFA(x);
		break;
	case 14:
		sub_028C39(x);
		break;
	case 16:
		sub_028C4D(x);
		break;
	case 18:
		u = sub_028C67(x);
		break;
	case 20:
		sub_028C93(x);
		break;
	case 22:
		y = sub_028CA4(x, y);
		break;
	case -14:
		sub_028AFC(x);
		break;
	case -12:
		y = sub_028B26(x, y);
		break;
	case -10:
		sub_028B37(x);
		break;
	case -4:
		sub_028B4E(x);
		break;
	case -2:
		sub_028B71(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_0280BA(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_029C4E_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
	case 16:
		sub_028B80(x);
		break;
	case 2:
		sub_028AFC(x);
		break;
	case 4:
		y = sub_028B26(x, y);
		break;
	case 6:
		sub_028B37(x);
		break;
	case 8:
	case 22:
	case 40:
		y = sub_028CB5(x);
		break;
	case 10:
	case 24:
	case 42:
		sub_028CBE(x);
		break;
	case 12:
		sub_028B4E(x);
		break;
	case 14:
		sub_028B71(x);
		break;
	case 18:
		sub_028BA4(x);
		break;
	case 20:
		y = sub_028BC6(x, y);
		break;
	case 26:
		sub_028BE0(x);
		break;
	case 28:
		sub_028BFA(x);
		break;
	case 30:
		sub_028C39(x);
		break;
	case 32:
		sub_028C4D(x);
		break;
	case 34:
		u = sub_028C67(x);
		break;
	case 36:
		sub_028C93(x);
		break;
	case 38:
		y = sub_028CA4(x, y);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_0280C0(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0;

	y = sub_0280FE(x);
	mem_write8(x + 4u, 0x84u);
	u = enemy_behaviour_029910_ADDRESS;
	mem_write16(x + 0x2Au, enemy_behaviour_029910_ADDRESS);
	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t1 & ~0xFu) | 0x86u);
	*p_y = y;
	*p_u = u;
}

void sub_0280D8(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;

	sub_0280C0(x, &y, &u);
	sub_028164(x);
	mem_write8(x + 0x30u, 0u);
	mem_write8(x + 2u, 2u);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_0280FE(uint16_t x)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0;

	u = object_setup_0299B0_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x + 0x3Au, 0x10u);
	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, t1 | 0x40u);
	mem_write8(x + 0x42u, 1u);
	u = sub_078620(x);
	sub_078626(x, u);
	return y;
}

void sub_02811D(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;

	y = sub_0280FE(x);
	u = enemy_behaviour_0298B8_ADDRESS;
	mem_write16(x + 0x2Au, enemy_behaviour_0298B8_ADDRESS);
	mem_write8(x + 5u, 0x86u);
	*p_y = y;
	*p_u = u;
}

void sub_02812B(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;

	sub_02811D(x, &y, &u);
	sub_028164(x);
	mem_write8(x + 0x30u, 0u);
	mem_write8(x + 2u, 2u);
	*p_y = y;
	*p_u = u;
}

void sub_028144(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0;

	y = sub_0280FE(x);
	u = enemy_behaviour_029860_ADDRESS;
	mem_write16(x + 0x2Au, enemy_behaviour_029860_ADDRESS);
	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t1 & ~0xFu) | 0x86u);
	*p_y = y;
	*p_u = u;
}

void sub_028157(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;

	sub_028144(x, &y, &u);
	sub_028164(x);
	mem_write8(x + 0x30u, 0u);
	mem_write8(x + 2u, 2u);
	*p_y = y;
	*p_u = u;
}

void sub_028164(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x30u);
	if (t1 != 0u)
		mem_write8(x + 0x1Bu, 1u);
}

void sub_02817B(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;

	y = sub_0280FE(x);
	u = enemy_behaviour_029808_ADDRESS;
	mem_write16(x + 0x2Au, enemy_behaviour_029808_ADDRESS);
	*p_y = y;
	*p_u = u;
}

void sub_028184(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;

	sub_02817B(x, &y, &u);
	sub_028164(x);
	mem_write8(x + 0x30u, 0u);
	mem_write8(x + 2u, 2u);
	*p_y = y;
	*p_u = u;
}

void sub_028197(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t2 = 0, t3 = 0, t10 = 0;
	uint16_t t1 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0;

	u = object_setup_0299D6_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 0x80u);
	t1 = mem_read16(x + 0x40u);
	u = t1;
	t2 = mem_read8(u + 9u);
	unk_48F0 = t2 & 0x30u;
	t3 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t3 & 0xCFu) | unk_48F0);
	t4 = mem_read16(u + 0xFu);
	mem_write16(x + 0xFu, t4);
	t5 = mem_read16(u + 0x19u);
	mem_write16(x + 0x19u, t5);
	t6 = mem_read16(u + 0xCu);
	mem_write16(x + 0xCu, t6);
	t7 = mem_read16(u + 0x11u);
	mem_write16(x + 0x11u, t7);
	t8 = mem_read16(u + 0x16u);
	t9 = t8 + VIDEO_003C;
	mem_write16(x + 0x16u, t9);
	t10 = mem_read8(x + 2u);
	mem_write8(x + 2u, t10 + 1u);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_0281DD(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t2 = 0, t3 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x40u);
	u = t1;
	t2 = mem_read8(u + 2u);
	if (t2 == 4u)
	{
		t3 = mem_read8(x + 2u);
		mem_write8(x + 2u, t3 + 1u);
	}
	return u;
}

void sub_0281EB(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write16(x + 0x19u, 0x100u);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
}

void sub_0281F5(uint16_t x)
{
	uint16_t t1 = 0, t2 = 0;

	t1 = mem_read16(x + 0x19u);
	mem_write16(x + 0x19u, t1 + 4u);
	t2 = mem_read16(x + 0x16u);
	if (t2 >= 0xF0u)
		mem_write8(x, 0u);
}

void sub_028216(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, u = 0, y = 0;
	uint8_t t1 = 0, t4 = 0;
	uint16_t t2 = 0, t3 = 0;

	sub_0785F9(x, &ignored16, &ignored16_2);
	y = child_object_0299EC_ADDRESS;
	sub_07862C(x, y, &u, &ignored16_3, &carry);
	if (carry)
	{
		mem_write16(x + 0x40u, u);
		mem_write8(x + 5u, 0xB0u);
		mem_write8(x + 0x3Bu, 0x68u);
		t1 = mem_read8(x + 0x30u);
		u = loaded_table_0299F4_ADDRESS + (int8_t)(((uint32_t)t1 << 1) << 1);
		t2 = DATA16(u);
		mem_write16(x + 0xCu, t2);
		t3 = mem_read16(u + 2u);
		mem_write16(x + 0xFu, t3);
		mem_write8(x + 0x30u, 0u);
		mem_write8(x, 0xC8u);
		mem_write16(x + 0x19u, 0xFE00u);
		mem_write16(x + 0x5Cu, 0u);
		t4 = mem_read8(x + 2u);
		mem_write8(x + 2u, t4 + 1u);
	}
	else
	{
		mem_write8(x + 0x3Bu, 0u);
		mem_write8(x + 0x30u, 0u);
		mem_write8(x + 2u, 2u);
	}
	*p_y = y;
	*p_u = u;
}

void sub_028264(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint32_t ignored = 0;
	uint8_t t1 = 0;

	u = loaded_table_0299E8_ADDRESS;
	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		u = sub_028270(x, u);
		break;
	case 2:
		u = sub_028294(x, u);
		break;
	case -112:
	case -100:
	case -88:
	case -76:
	case -64:
	case -8:
	case 48:
	case 68:
	case 80:
	case 96:
	case 108:
	case 124:
		sub_0785DB(x, &y, &u, &ignored);
		break;
	case -110:
	case -98:
	case -86:
	case -74:
	case -62:
	case -6:
	case 50:
	case 70:
	case 82:
	case 98:
	case 110:
	case 126:
		sub_0785DE(x, &y, &u, &ignored);
		break;
	case -108:
	case -84:
	case -72:
	case -60:
	case -4:
	case 52:
	case 72:
	case 84:
	case 100:
	case 112:
		sub_0785E1(x, &y, &u, &ignored);
		break;
	case -106:
	case -94:
	case -82:
	case -70:
	case -58:
	case -2:
	case 54:
	case 74:
	case 86:
	case 102:
	case 114:
		sub_0785E4(x, &y, &u, &ignored);
		break;
	case -12:
		sub_028216(x, &y, &u);
		break;
	case -10:
		sub_028264(x, &y, &u);
		break;
	}
	sub_0785C9(x);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_028270(uint16_t x, uint16_t u)
{
	uint32_t negative = 0, carry = 0;
	uint8_t a = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	d = 0u;
	sub_078638(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	mem_write8(x + 0x5Du, (((a & 0xFu) << 1) << 1) << 1);
	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		t2 = mem_read16(x + 0x40u);
		u = t2;
		mem_write8(u + 2u, 2u);
		mem_write8(x + 5u, 0xA8u);
		t3 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t3 + 1u);
	}
	carry = sub_078662(x);
	return u;
}

uint16_t sub_028294(uint16_t x, uint16_t u)
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

void sub_0282B8(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t ignored16 = 0, u = 0, y = 0;
	uint8_t t1 = 0;

	sub_028FC1(x, &ignored16, &u);
	mem_write8(x + 0x30u, 0u);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	y = hit_box_0299BE_ADDRESS;
	sub_0785B4(x, y);
	*p_y = y;
	*p_u = u;
}

void sub_0282C7(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint32_t ignored = 0;
	uint8_t t1 = 0;

	u = loaded_table_029A20_ADDRESS;
	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_0282D3(x);
		break;
	case 2:
		sub_0282DC(x);
		break;
	case 4:
		sub_0282F0(x);
		break;
	case 6:
		sub_028307();
		break;
	case 8:
		sub_028314(x, &y, &u);
		break;
	case 10:
	case 38:
	case 50:
		sub_0283C0(x, &y, &u);
		break;
	case -120:
	case -64:
	case -8:
	case 12:
	case 24:
	case 40:
	case 52:
	case 68:
	case 94:
		sub_0785DB(x, &y, &u, &ignored);
		break;
	case -118:
	case -62:
	case -6:
	case 14:
	case 26:
	case 42:
	case 54:
	case 70:
	case 96:
		sub_0785DE(x, &y, &u, &ignored);
		break;
	case -128:
	case -116:
	case -60:
	case -4:
	case 16:
	case 28:
	case 44:
	case 56:
	case 72:
	case 98:
		sub_0785E1(x, &y, &u, &ignored);
		break;
	case -126:
	case -114:
	case -58:
	case -2:
	case 18:
	case 30:
	case 46:
	case 58:
	case 74:
	case 100:
		sub_0785E4(x, &y, &u, &ignored);
		break;
	case 20:
		sub_028330(x, &y, &u);
		break;
	case 22:
		sub_028345(x, &y, &u);
		break;
	case 32:
		sub_028351(x);
		break;
	case 34:
		y = sub_028367(x);
		break;
	case 36:
		sub_028394(x, &y, &u);
		break;
	case 48:
		sub_0283B0(x, &y, &u);
		break;
	case 60:
		sub_0283CC(x);
		break;
	case 62:
		u = sub_0283E7(x, u);
		break;
	case 64:
		sub_02840B(x, &y, &u);
		break;
	case 66:
		sub_02842E(x, &y, &u);
		break;
	case 76:
		u = sub_028437(x);
		break;
	case 78:
		u = sub_028456(x, u);
		break;
	case 80:
		u = sub_028477(x, u);
		break;
	case -12:
		sub_0282B8(x, &y, &u);
		break;
	case -10:
		sub_0282C7(x, &y, &u);
		break;
	}
	sub_028758(x);
	*p_y = y;
	*p_u = u;
}

void sub_0282D3(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 5u, 0xA2u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

void sub_0282DC(uint16_t x)
{
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 5u);
	mem_write8(x + 5u, t1 | 0x80u);
	t2 = mem_read16(x + 0xCu);
	if (t2 < 0x100u)
	{
		t3 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t3 + 1u);
	}
}

void sub_0282F0(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
	{
		sub_028307();
		return;
	}
	mem_write16(x + 0xFu, 0x200u);
	mem_write8(x + 5u, 0x90u);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	sub_0785C6(x);
}

void sub_028307(void)
{
}

void sub_028314(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0;

	sub_029012(x, &y, &u);
	t1 = mem_read8(x + 0x30u);
	mem_write8(x + 0x3Bu, t1);
	mem_write8(x + 0x30u, 0u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_028330(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0;

	sub_02905A(x, &y, &u);
	mem_write8(x + 5u, 0xA4u);
	t1 = mem_read8(x + 0x30u);
	mem_write8(x + 0x3Bu, t1);
	mem_write8(x + 0x30u, 0u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_028345(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint32_t ignored = 0;
	uint8_t t1 = 0;

	u = loaded_table_029A40_ADDRESS;
	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_028351(x);
		break;
	case 2:
		y = sub_028367(x);
		break;
	case 4:
		sub_028394(x, &y, &u);
		break;
	case -22:
	case 6:
	case 18:
		sub_0283C0(x, &y, &u);
		break;
	case -96:
	case -40:
	case -20:
	case -8:
	case 8:
	case 20:
	case 36:
	case 62:
	case 96:
		sub_0785DB(x, &y, &u, &ignored);
		break;
	case -94:
	case -38:
	case -18:
	case -6:
	case 10:
	case 22:
	case 38:
	case 64:
	case 98:
		sub_0785DE(x, &y, &u, &ignored);
		break;
	case -92:
	case -36:
	case -16:
	case -4:
	case 12:
	case 24:
	case 40:
	case 66:
	case 100:
		sub_0785E1(x, &y, &u, &ignored);
		break;
	case -90:
	case -34:
	case -14:
	case -2:
	case 14:
	case 26:
	case 42:
	case 68:
	case 102:
		sub_0785E4(x, &y, &u, &ignored);
		break;
	case 16:
		sub_0283B0(x, &y, &u);
		break;
	case 28:
		sub_0283CC(x);
		break;
	case 30:
		u = sub_0283E7(x, u);
		break;
	case 32:
		sub_02840B(x, &y, &u);
		break;
	case 34:
		sub_02842E(x, &y, &u);
		break;
	case 44:
		u = sub_028437(x);
		break;
	case 46:
		u = sub_028456(x, u);
		break;
	case 48:
		u = sub_028477(x, u);
		break;
	case -44:
		sub_0282B8(x, &y, &u);
		break;
	case -42:
		sub_0282C7(x, &y, &u);
		break;
	case -32:
		sub_0282D3(x);
		break;
	case -30:
		sub_0282DC(x);
		break;
	case -28:
		sub_0282F0(x);
		break;
	case -26:
		sub_028307();
		break;
	case -24:
		sub_028314(x, &y, &u);
		break;
	case -12:
		sub_028330(x, &y, &u);
		break;
	case -10:
		sub_028345(x, &y, &u);
		break;
	}
	sub_028758(x);
	*p_y = y;
	*p_u = u;
}

void sub_028351(uint16_t x)
{
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

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

uint16_t sub_028367(uint16_t x)
{
	uint16_t y = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
	{
		t2 = mem_read8(x + 0x3Bu);
		if ((t2 & 3u) != 0u)
		{
			y = hit_box_0299B6_ADDRESS;
			sub_0785B4(x, y);
			return y;
		}
		y = hit_box_0299C6_ADDRESS;
		sub_0785B4(x, y);
		return y;
	}
	y = hit_box_0299B6_ADDRESS;
	sub_0785B4(x, y);
	mem_write8(x + 2u, 2u);
	mem_write8(x + 0x3Bu, 0u);
	return y;
}

void sub_028394(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0;

	sub_028144(x, &y, &u);
	t1 = mem_read8(x + 0x30u);
	mem_write8(x + 0x3Bu, t1);
	mem_write8(x + 0x30u, 0u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_0283B0(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0;

	sub_0785F9(x, &y, &u);
	t1 = mem_read8(x + 0x30u);
	mem_write8(x + 0x3Bu, t1);
	mem_write8(x + 0x30u, 0u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_0283C0(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint32_t ignored = 0;
	uint8_t t1 = 0;

	u = loaded_table_029A5C_ADDRESS;
	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_0283CC(x);
		break;
	case 2:
		u = sub_0283E7(x, u);
		break;
	case 4:
		sub_02840B(x, &y, &u);
		break;
	case 6:
		sub_02842E(x, &y, &u);
		break;
	case -124:
	case -68:
	case -48:
	case -36:
	case -20:
	case -8:
	case 8:
	case 34:
	case 68:
	case 110:
		sub_0785DB(x, &y, &u, &ignored);
		break;
	case -122:
	case -66:
	case -46:
	case -34:
	case -18:
	case -6:
	case 10:
	case 36:
	case 70:
	case 112:
		sub_0785DE(x, &y, &u, &ignored);
		break;
	case -120:
	case -64:
	case -44:
	case -32:
	case -16:
	case -4:
	case 12:
	case 38:
	case 72:
	case 114:
		sub_0785E1(x, &y, &u, &ignored);
		break;
	case -118:
	case -62:
	case -42:
	case -30:
	case -14:
	case -2:
	case 14:
	case 40:
	case 74:
	case 116:
		sub_0785E4(x, &y, &u, &ignored);
		break;
	case 16:
		u = sub_028437(x);
		break;
	case 18:
		u = sub_028456(x, u);
		break;
	case 20:
		u = sub_028477(x, u);
		break;
	case -72:
		sub_0282B8(x, &y, &u);
		break;
	case -70:
		sub_0282C7(x, &y, &u);
		break;
	case -60:
		sub_0282D3(x);
		break;
	case -58:
		sub_0282DC(x);
		break;
	case -56:
		sub_0282F0(x);
		break;
	case -54:
		sub_028307();
		break;
	case -52:
		sub_028314(x, &y, &u);
		break;
	case -50:
	case -22:
	case -10:
		sub_0283C0(x, &y, &u);
		break;
	case -40:
		sub_028330(x, &y, &u);
		break;
	case -38:
		sub_028345(x, &y, &u);
		break;
	case -28:
		sub_028351(x);
		break;
	case -26:
		y = sub_028367(x);
		break;
	case -24:
		sub_028394(x, &y, &u);
		break;
	case -12:
		sub_0283B0(x, &y, &u);
		break;
	}
	sub_028758(x);
	*p_y = y;
	*p_u = u;
}

void sub_0283CC(uint16_t x)
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

uint16_t sub_0283E7(uint16_t x, uint16_t u)
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

void sub_02840B(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t ignored16 = 0, u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0;

	sub_0785F9(x, &y, &ignored16);
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

void sub_02842E(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint32_t ignored = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_029A6C_ADDRESS;
		t1 = mem_read8(x + 0x29u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			u = sub_028437(x);
			break;
		case 2:
			u = sub_028456(x, u);
			break;
		case 4:
			u = sub_028477(x, u);
			break;
		case -84:
		case -64:
		case -52:
		case -36:
		case -24:
		case -8:
		case 18:
		case 52:
		case 94:
			sub_0785DB(x, &y, &u, &ignored);
			break;
		case -82:
		case -62:
		case -50:
		case -34:
		case -22:
		case -6:
		case 20:
		case 54:
		case 96:
			sub_0785DE(x, &y, &u, &ignored);
			break;
		case -80:
		case -60:
		case -48:
		case -32:
		case -20:
		case -4:
		case 22:
		case 56:
		case 98:
			sub_0785E1(x, &y, &u, &ignored);
			break;
		case -78:
		case -58:
		case -46:
		case -30:
		case -18:
		case -2:
		case 24:
		case 58:
		case 100:
			sub_0785E4(x, &y, &u, &ignored);
			break;
		case -88:
			sub_0282B8(x, &y, &u);
			break;
		case -86:
			sub_0282C7(x, &y, &u);
			break;
		case -76:
			sub_0282D3(x);
			break;
		case -74:
			sub_0282DC(x);
			break;
		case -72:
			sub_0282F0(x);
			break;
		case -70:
			sub_028307();
			break;
		case -68:
			sub_028314(x, &y, &u);
			break;
		case -66:
		case -38:
		case -26:
			sub_0283C0(x, &y, &u);
			break;
		case -56:
			sub_028330(x, &y, &u);
			break;
		case -54:
			sub_028345(x, &y, &u);
			break;
		case -44:
			sub_028351(x);
			break;
		case -42:
			y = sub_028367(x);
			break;
		case -40:
			sub_028394(x, &y, &u);
			break;
		case -28:
			sub_0283B0(x, &y, &u);
			break;
		case -16:
			sub_0283CC(x);
			break;
		case -14:
			u = sub_0283E7(x, u);
			break;
		case -12:
			sub_02840B(x, &y, &u);
			break;
		case -10:
			continue;
		}
		break;
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_028437(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	u = indexed_table_029A72_ADDRESS;
	t1 = mem_read8(x + 0x30u);
	t2 = DATA16(indexed_table_029A72_ADDRESS + (int8_t)((uint32_t)t1 << 1));
	mem_write16(x + 0xCu, t2);
	mem_write16(x + 0x11u, 0x50u);
	mem_write16(x + 0x14u, 0x100u);
	mem_write8(x + 0x30u, 0u);
	t3 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t3 + 1u);
	return u;
}

uint16_t sub_028456(uint16_t x, uint16_t u)
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
		mem_write8(x, 0xC0u);
		mem_write8(x + 0x3Bu, 0x40u);
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

uint16_t sub_028477(uint16_t x, uint16_t u)
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

uint16_t sub_02849C(uint16_t x)
{
	uint16_t ignored16 = 0, u = 0, y = 0;
	uint8_t t1 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;
	uint16_t t2 = 0;

	sub_028FC1(x, &y, &ignored16);
	mem_write8(x + 5u, 0xB7u);
	t1 = mem_read8(x + 0x30u);
	u = loaded_table_029A86_ADDRESS + (int8_t)(((uint32_t)t1 << 1) << 1);
	t2 = DATA16(u);
	mem_write16(x + 0x3Eu, t2);
	t3 = mem_read8(u + 2u);
	mem_write8(x + 9u, t3);
	t4 = mem_read8(x + 0x30u);
	t5 = mem_read8(u + 3u);
	mem_write8(x + 0x3Du, (t4 & 0x80u) | t5);
	mem_write8(x + 0x30u, 0u);
	t6 = mem_read8(x + 2u);
	mem_write8(x + 2u, t6 + 1u);
	return y;
}

uint16_t sub_0284CB(uint16_t x, uint16_t y)
{
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		return sub_0284D4(x, y);
	case 2:
		sub_0284F0(x);
		return y;
	case 4:
		return sub_02851B(x, y);
	case 6:
	case 48:
	case 82:
	case 102:
		sub_0285E3(x);
		return y;
	case 8:
	case 50:
	case 84:
		sub_028613(x);
		return y;
	case 10:
		return sub_02854D(x);
	case 12:
		return sub_0285AA(x, y);
	case -122:
	case -102:
	case -90:
	case -74:
	case -62:
	case -46:
	case -20:
	case 14:
	case 56:
	case 90:
	case 112:
	case 124:
		sub_0785DB(x, &y, &ignored16, &ignored);
		return y;
	case -120:
	case -100:
	case -88:
	case -72:
	case -60:
	case -44:
	case -18:
	case 16:
	case 58:
	case 92:
	case 114:
	case 126:
		sub_0785DE(x, &y, &ignored16, &ignored);
		return y;
	case -118:
	case -98:
	case -86:
	case -70:
	case -58:
	case -42:
	case -16:
	case 18:
	case 60:
	case 94:
	case 116:
		sub_0785E1(x, &y, &ignored16, &ignored);
		return y;
	case -116:
	case -96:
	case -84:
	case -68:
	case -56:
	case -40:
	case -14:
	case 20:
	case 62:
	case 96:
	case 118:
		sub_0785E4(x, &y, &ignored16, &ignored);
		return y;
	}
	unreachable();
}

uint16_t sub_0284D4(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Du);
	a = t1;
	if ((int8_t)t1 < 0)
		mem_write8(x, 0x80u);
	carry = (a >> 0) & 1u;
	if (carry)
	{
		t2 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t2 + 1u);
		return y;
	}
	y = hit_box_0299BE_ADDRESS;
	sub_0785B4(x, y);
	mem_write8(x + 5u, 0xA2u);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	return y;
}

void sub_0284F0(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0, t5 = 0;
	uint16_t t3 = 0, t4 = 0;

	t1 = mem_read8(x + 0x3Du);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
	{
		t2 = mem_read8(x + 5u);
		mem_write8(x + 5u, t2 | 0x80u);
	}
	t3 = mem_read16(x + 0xCu);
	t4 = mem_read16(x + 0x3Eu);
	if (t3 < t4)
	{
		t5 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t5 + 1u);
	}
	if ((mem_read8(x) & 0x20u) != 0u)
	{
		mem_write8(x + 5u, 0xA0u);
		mem_write8(x + 0x29u, 2u);
	}
}

uint16_t sub_02851B(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
		return y;
	y = hit_box_0299B6_ADDRESS;
	sub_0785B4(x, y);
	mem_write8(x + 5u, 0x91u);
	mem_write16(x + 0xFu, 0x100u);
	mem_write16(x + 0x14u, 0xFF00u);
	mem_write8(x + 0x3Bu, 8u);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	return y;
}

uint16_t sub_02854D(uint16_t x)
{
	uint8_t a = 0, d = 0;
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t5 = 0, t6 = 0, t8 = 0;
	uint16_t t3 = 0, t4 = 0, t7 = 0;

	u = object_setup_029AA8_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 8u);
	mem_write8(x + 0x42u, 1u);
	t1 = mem_read8(x + 0x30u);
	u = loaded_table_029AAE_ADDRESS + (int8_t)(((uint32_t)t1 << 1) << 1);
	unk_48F0 = DATA8(u) & 0x30u;
	t2 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t2 & 0xCFu) | unk_48F0);
	t3 = DATA16(u);
	mem_write8(x + 0x3Au, (t3 >> 8) & 0x80u);
	t4 = (t3 & 0xFFu) << 4;
	d = (uint8_t)t4;
	a = (uint8_t)(t4 >> 8);
	mem_write16(x + 0x3Eu, ((uint32_t)a << 8) | (d & 0xFFu));
	if ((uint16_t)(((uint32_t)a << 8) | (d & 0xFFu)) >= 0x100u)
	{
		t5 = mem_read8(x + 9u);
		a = t5 | 0x40u;
	}
	else
	{
		t6 = mem_read8(x + 9u);
		a = t6 & 0xBFu;
	}
	mem_write8(x + 9u, a);
	t7 = mem_read16(u + 2u);
	mem_write8(x + VIDEO_003C, t7 >> 8);
	mem_write8(x + 0x3Bu, t7);
	mem_write8(x + 0x30u, 0u);
	t8 = mem_read8(x + 2u);
	mem_write8(x + 2u, t8 + 1u);
	return y;
}

uint16_t sub_0285AA(uint16_t x, uint16_t y)
{
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_0285B3(x);
		return y;
	case 2:
		sub_0285C4(x, 0u);
		return y;
	case -38:
	case 4:
	case 38:
	case 58:
	case 122:
		sub_0285E3(x);
		return y;
	case -36:
	case 6:
	case 40:
	case 124:
		sub_028613(x);
		return y;
	case 8:
		return sub_028633(x);
	case 10:
		return sub_028669(x, y);
	case -118:
	case -106:
	case -90:
	case -64:
	case -30:
	case 12:
	case 46:
	case 68:
	case 80:
		sub_0785DB(x, &y, &ignored16, &ignored);
		return y;
	case -116:
	case -104:
	case -88:
	case -62:
	case -28:
	case 14:
	case 48:
	case 70:
	case 82:
		sub_0785DE(x, &y, &ignored16, &ignored);
		return y;
	case -114:
	case -102:
	case -86:
	case -60:
	case -26:
	case 16:
	case 50:
	case 72:
	case 84:
		sub_0785E1(x, &y, &ignored16, &ignored);
		return y;
	case -128:
	case -112:
	case -100:
	case -84:
	case -58:
	case -24:
	case 18:
	case 52:
	case 74:
	case 86:
		sub_0785E4(x, &y, &ignored16, &ignored);
		return y;
	}
	unreachable();
}

void sub_0285B3(uint16_t x)
{
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = mem_read16(x + 0xCu);
	t2 = mem_read16(x + 0x3Eu);
	if (t1 < t2)
	{
		mem_write8(x, 0x80u);
		t3 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t3 + 1u);
	}
}

void sub_0285C4(uint16_t x, uint32_t u)
{
	uint8_t a = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + VIDEO_003C);
	mem_write8(x + VIDEO_003C, t1 - 1u);
	if (t1 != 1u)
		return;
	u = sub_078620(x);
	sub_078626(x, u);
	t2 = mem_read8(x + 0x3Au);
	if ((int8_t)t2 >= 0)
		a = 0x20u;
	else
		a = 0xE0u;
	d = ((uint32_t)a << 8) | 0x40u;
	sub_078617(x, d);
	t3 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t3 + 1u);
}

void sub_0285E3(uint16_t x)
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

void sub_028613(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x, 0xC0u);
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

uint16_t sub_028633(uint16_t x)
{
	uint16_t ignored16 = 0, u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;
	uint16_t t4 = 0, t5 = 0;

	sub_0785F9(x, &y, &ignored16);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	mem_write8(x + 5u, 0x82u);
	t2 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t2 & 0xCFu) | 0x20u);
	mem_write8(x, 8u);
	t3 = mem_read8(x + 0x30u);
	u = loaded_table_029AD2_ADDRESS + (int8_t)(((uint32_t)t3 << 1) << 1);
	t4 = DATA16(u);
	mem_write8(x + VIDEO_003C, t4 >> 8);
	mem_write8(x + 0x3Bu, t4);
	t5 = mem_read16(u + 2u);
	mem_write16(x + 0x3Eu, t5);
	mem_write8(x + 0x30u, 0u);
	return y;
}

uint16_t sub_028669(uint16_t x, uint16_t y)
{
	uint32_t zero = 0, negative = 0;
	uint16_t ignored16 = 0, u = 0, y_2 = 0;
	uint32_t ignored = 0;
	uint8_t t1 = 0, t2 = 0;

	u = loaded_table_029AE2_ADDRESS;
	t1 = mem_read8(x + 0x29u);
	t2 = (uint32_t)t1 << 1;
	negative = t2 >> 7;
	zero = t2 == 0u;
	switch ((int8_t)t2)
	{
	case 0:
		sub_028672(x);
		return y;
	case -74:
	case -32:
	case 2:
	case 22:
	case 86:
		sub_0285E3(x);
		return y;
	case -72:
	case -30:
	case 4:
	case 88:
	case 108:
		sub_028613(x);
		return y;
	case 6:
		sub_028692(x, &y_2, &ignored16);
		return y_2;
	case 8:
		sub_0286C2(x, &y, &ignored16);
		return y;
	case -126:
	case -100:
	case -66:
	case -24:
	case 10:
	case 32:
	case 44:
	case 94:
	case 114:
	case 126:
		sub_0785DB(x, &y, &ignored16, &ignored);
		return y;
	case -124:
	case -98:
	case -64:
	case -22:
	case 12:
	case 34:
	case 46:
	case 96:
	case 116:
		sub_0785DE(x, &y, &ignored16, &ignored);
		return y;
	case -122:
	case -96:
	case -62:
	case -20:
	case 14:
	case 36:
	case 48:
	case 98:
	case 118:
		sub_0785E1(x, &y, &ignored16, &ignored);
		return y;
	case -120:
	case -94:
	case -60:
	case -18:
	case 16:
	case 38:
	case 50:
	case 100:
	case 120:
		sub_0785E4(x, &y, &ignored16, &ignored);
		return y;
	case 18:
		sub_0286CB(x);
		return y;
	case 20:
		sub_0286DF(x);
		return y;
	case 24:
		sub_0286F4(x);
		return y;
	case 26:
		sub_0286FD(x);
		return y;
	case 28:
		sub_028722(x, &y_2, &ignored16);
		return y_2;
	case 30:
	case 42:
		sub_02877E(x, &y, &ignored16);
		return y;
	case 40:
	case 90:
		sub_028733(x, &y_2, &ignored16);
		return y_2;
	case -14:
	case -10:
	case -6:
	case -2:
		sub_07D030(x, u, zero, negative);
		return y;
	}
	unreachable();
}

void sub_028672(uint16_t x)
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

void sub_028692(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t ignored16 = 0, u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t4 = 0;
	uint16_t t3 = 0;

	sub_02905A(x, &y, &ignored16);
	mem_write8(x + 4u, 0x80u);
	mem_write8(x + 5u, 0xA2u);
	mem_write8(x, 8u);
	t1 = mem_read8(x + 0x42u);
	mem_write8(x + 0x42u, t1 + 1u);
	u = indexed_table_029B16_ADDRESS;
	t2 = mem_read8(x + 0x30u);
	t3 = DATA16(indexed_table_029B16_ADDRESS + (int8_t)((uint32_t)t2 << 1));
	mem_write8(x + VIDEO_003C, t3 >> 8);
	mem_write8(x + 9u, t3);
	mem_write8(x + 0x3Bu, 8u);
	mem_write8(x + 0x30u, 0u);
	t4 = mem_read8(x + 2u);
	mem_write8(x + 2u, t4 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_0286C2(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t zero = 0, negative = 0;
	uint16_t u = 0;
	uint32_t ignored = 0;
	uint8_t t1 = 0, t2 = 0;

	for (;;)
	{
		u = loaded_table_029AF4_ADDRESS;
		t1 = mem_read8(x + 0x29u);
		t2 = (uint32_t)t1 << 1;
		negative = t2 >> 7;
		zero = t2 == 0u;
		switch ((int8_t)t2)
		{
		case 0:
			u = sub_0286CB(x);
			break;
		case 2:
			sub_0286DF(x);
			break;
		case -92:
		case -50:
		case -16:
		case 4:
		case 68:
			sub_0285E3(x);
			break;
		case 6:
			sub_0286F4(x);
			break;
		case 8:
			sub_0286FD(x);
			break;
		case 10:
			sub_028722(x, &y, &u);
			break;
		case 12:
		case 24:
			sub_02877E(x, &y, &u);
			break;
		case -118:
		case -84:
		case -42:
		case -8:
		case 14:
		case 26:
		case 76:
		case 96:
		case 108:
			sub_0785DB(x, &y, &u, &ignored);
			break;
		case -116:
		case -82:
		case -40:
		case -6:
		case 16:
		case 28:
		case 78:
		case 98:
		case 110:
			sub_0785DE(x, &y, &u, &ignored);
			break;
		case -114:
		case -80:
		case -38:
		case -4:
		case 18:
		case 30:
		case 80:
		case 100:
		case 112:
			sub_0785E1(x, &y, &u, &ignored);
			break;
		case -112:
		case -78:
		case -36:
		case -2:
		case 20:
		case 32:
		case 82:
		case 102:
		case 114:
			sub_0785E4(x, &y, &u, &ignored);
			break;
		case 22:
		case 72:
			sub_028733(x, &y, &u);
			break;
		case -90:
		case -48:
		case -14:
		case 70:
		case 90:
			sub_028613(x);
			break;
		case -32:
		case -28:
		case -24:
		case -20:
			sub_07D030(x, u, zero, negative);
			break;
		case -18:
			sub_028672(x);
			break;
		case -12:
			sub_028692(x, &y, &u);
			break;
		case -10:
			continue;
		}
		break;
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_0286CB(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t1 = 0, t2 = 0;

	u = sub_078620(x);
	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 5u);
	mem_write8(x + 5u, t1 | 0x80u);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	return u;
}

void sub_0286DF(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + VIDEO_003C);
	mem_write8(x + VIDEO_003C, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(x + 0xFu, 0x80u);
		mem_write16(x + 0x14u, 0xFF80u);
		t2 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t2 + 1u);
	}
}

void sub_0286F4(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 0x3Bu, 4u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

void sub_0286FD(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 4u, 0x83u);
		mem_write8(x, 0xC0u);
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_028722(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t ignored16 = 0, u = 0, y = 0;

	sub_028FC1(x, &y, &ignored16);
	u = sub_028736(x);
	*p_y = y;
	*p_u = u;
}

void sub_028733(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t ignored16 = 0, u = 0, y = 0;

	sub_0785F9(x, &y, &ignored16);
	u = sub_028736(x);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_028736(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	mem_write8(x, 0x80u);
	mem_write8(x + 5u, 0x91u);
	u = indexed_table_029B16_ADDRESS;
	t1 = mem_read8(x + 0x30u);
	t2 = DATA16(indexed_table_029B16_ADDRESS + (int8_t)((uint32_t)t1 << 1));
	mem_write8(x + VIDEO_003C, t2 >> 8);
	mem_write8(x + 9u, t2);
	mem_write8(x + 0x3Bu, 8u);
	t3 = mem_read8(x + 2u);
	mem_write8(x + 2u, t3 + 1u);
	return u;
}

void sub_028758(uint16_t x)
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
		unk_48F1 = a;
		unk_48F0 = a & 0x30u;
		t1 = mem_read8(x + 9u);
		mem_write8(x + 9u, (t1 & 0xCFu) | unk_48F0);
		mem_write8(x + 0x5Du, (((unk_48F1 & 0xFu) << 1) << 1) << 1);
	}
}

void sub_02877E(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint32_t ignored = 0;
	uint8_t t1 = 0;

	u = loaded_table_029B30_ADDRESS;
	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_028787(x);
		break;
	case 2:
		sub_028796(x);
		break;
	case 4:
		sub_0287A4(x);
		break;
	case 6:
	case 26:
		sub_0287B8(x);
		break;
	case -110:
	case -76:
	case -56:
	case 8:
		sub_0285E3(x);
		break;
	case -108:
	case -74:
	case 10:
	case 30:
		sub_028613(x);
		break;
	case -38:
	case 12:
		sub_028733(x, &y, &u);
		break;
	case 14:
		sub_0287D6(x, &y, &u);
		break;
	case -102:
	case -68:
	case -46:
	case -34:
	case 16:
	case 36:
	case 48:
	case 70:
	case 96:
		sub_0785DB(x, &y, &u, &ignored);
		break;
	case -100:
	case -66:
	case -44:
	case -32:
	case 18:
	case 38:
	case 50:
	case 72:
	case 98:
		sub_0785DE(x, &y, &u, &ignored);
		break;
	case -98:
	case -64:
	case -42:
	case -30:
	case 20:
	case 40:
	case 52:
	case 74:
	case 100:
		sub_0785E1(x, &y, &u, &ignored);
		break;
	case -96:
	case -62:
	case -40:
	case -28:
	case 22:
	case 42:
	case 54:
	case 76:
	case 102:
		sub_0785E4(x, &y, &u, &ignored);
		break;
	case 24:
		sub_0287DF(x);
		break;
	case 28:
		sub_0287ED(x);
		break;
	case 32:
		sub_028825(x, &y, &u);
		break;
	case 34:
	case 46:
		sub_02886E(x, &y, &u);
		break;
	case 44:
		sub_028836(x, &y, &u);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_028787(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x30u);
	if ((int8_t)t1 >= 0)
	{
		mem_write8(x + 0x29u, 3u);
		return;
	}
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
}

void sub_028796(uint16_t x)
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

void sub_0287A4(uint16_t x)
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

void sub_0287B8(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + VIDEO_003C);
	mem_write8(x + VIDEO_003C, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 0x30u, 0u);
		mem_write16(x + 0x14u, 0xFF00u);
		t2 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t2 + 1u);
	}
}

void sub_0287D6(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint32_t ignored = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_029B48_ADDRESS;
		t1 = mem_read8(x + 0x29u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			sub_0287DF(x);
			break;
		case -18:
		case 2:
			sub_0287B8(x);
			break;
		case 4:
			sub_0287ED(x);
			break;
		case -98:
		case -14:
		case 6:
			sub_028613(x);
			break;
		case 8:
			sub_028825(x, &y, &u);
			break;
		case 10:
		case 22:
			sub_02886E(x, &y, &u);
			break;
		case -126:
		case -92:
		case -70:
		case -58:
		case -8:
		case 12:
		case 24:
		case 46:
		case 72:
		case 120:
			sub_0785DB(x, &y, &u, &ignored);
			break;
		case -124:
		case -90:
		case -68:
		case -56:
		case -6:
		case 14:
		case 26:
		case 48:
		case 74:
		case 122:
			sub_0785DE(x, &y, &u, &ignored);
			break;
		case -122:
		case -88:
		case -66:
		case -54:
		case -4:
		case 16:
		case 28:
		case 50:
		case 76:
		case 124:
			sub_0785E1(x, &y, &u, &ignored);
			break;
		case -120:
		case -86:
		case -64:
		case -52:
		case -2:
		case 18:
		case 30:
		case 52:
		case 78:
		case 126:
			sub_0785E4(x, &y, &u, &ignored);
			break;
		case 20:
			sub_028836(x, &y, &u);
			break;
		case -100:
		case -80:
		case -16:
			sub_0285E3(x);
			break;
		case -62:
		case -12:
			sub_028733(x, &y, &u);
			break;
		case -24:
			sub_028787(x);
			break;
		case -22:
			sub_028796(x);
			break;
		case -20:
			sub_0287A4(x);
			break;
		case -10:
			continue;
		}
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_0287DF(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x, 0x80u);
	mem_write8(x + 9u, 0x10u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

void sub_0287ED(uint16_t x)
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

void sub_028825(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t ignored16 = 0, u = 0, y = 0;

	sub_028144(x, &y, &ignored16);
	u = sub_028839(x);
	*p_y = y;
	*p_u = u;
}

void sub_028836(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t ignored16 = 0, u = 0, y = 0;

	sub_0785F9(x, &y, &ignored16);
	u = sub_028839(x);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_028839(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	mem_write8(x, 0x80u);
	mem_write16(x + 0x5Cu, 0u);
	t1 = mem_read8(x + 0x30u);
	u = loaded_table_029B68_ADDRESS + (int8_t)((uint32_t)t1 << 1);
	t2 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t2 & 0x8Fu) | DATA8(u));
	t3 = mem_read8(u + 1u);
	mem_write8(x + 0x3Bu, t3);
	t4 = mem_read8(x + 0x30u);
	if ((int8_t)t4 < 0)
		mem_write8(x + 0x1Bu, 1u);
	u = sub_078620(x);
	mem_write8(x + 0x30u, 0u);
	t5 = mem_read8(x + 2u);
	mem_write8(x + 2u, t5 + 1u);
	return u;
}

void sub_02886E(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint32_t ignored = 0;
	uint8_t t1 = 0;

	u = loaded_table_029B6C_ADDRESS;
	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		u = sub_028877(x);
		break;
	case 2:
	case 28:
		sub_02890B(x);
		break;
	case 4:
	case 30:
		sub_028925(x);
		break;
	case 6:
		sub_028895(x, &y, &u);
		break;
	case 8:
		sub_0288DB(x, &y, &u);
		break;
	case -128:
	case -106:
	case -94:
	case -44:
	case -24:
	case -12:
	case 10:
	case 36:
	case 84:
	case 108:
		sub_0785DB(x, &y, &u, &ignored);
		break;
	case -126:
	case -104:
	case -92:
	case -42:
	case -22:
	case -10:
	case 12:
	case 38:
	case 86:
	case 110:
		sub_0785DE(x, &y, &u, &ignored);
		break;
	case -124:
	case -102:
	case -90:
	case -40:
	case -20:
	case -8:
	case 14:
	case 40:
	case 88:
	case 112:
		sub_0785E1(x, &y, &u, &ignored);
		break;
	case -122:
	case -100:
	case -88:
	case -38:
	case -18:
	case -6:
	case 16:
	case 42:
	case 90:
	case 114:
		sub_0785E4(x, &y, &u, &ignored);
		break;
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_028877(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t1 = 0;

	u = sub_078620(x);
	mem_write16(x + 0xFu, 0x100u);
	mem_write8(x + 5u, 0x81u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	return u;
}

void sub_028895(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t4 = 0, t5 = 0, t6 = 0;
	uint16_t t3 = 0;

	sub_0785F9(x, &y, &ignored16);
	mem_write8(x, 4u);
	mem_write16(x + 0x5Cu, 0u);
	t1 = mem_read8(x + 0x30u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
		mem_write8(x + 0x1Bu, 1u);
	t2 = mem_read8(x + 0x30u);
	u = loaded_table_029B7E_ADDRESS + (int8_t)((uint32_t)t2 << 1);
	t3 = (uint32_t)DATA8(u) << 4;
	mem_write16(x + 0x3Eu, t3);
	t4 = mem_read8(u + 1u);
	mem_write8(x + 0x3Bu, t4);
	t5 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t5 & 0x8Fu) | 0x20u);
	mem_write8(x + 0x42u, 0xFFu);
	mem_write8(x + 0x57u, 0xFFu);
	mem_write8(x + 0x30u, 0u);
	t6 = mem_read8(x + 2u);
	mem_write8(x + 2u, t6 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_0288DB(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint32_t ignored = 0;
	uint8_t t1 = 0;

	u = loaded_table_029B86_ADDRESS;
	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		u = sub_0288E4(x, u);
		break;
	case -24:
	case 2:
		sub_02890B(x);
		break;
	case -22:
	case 4:
		sub_028925(x);
		break;
	case 6:
		sub_02893D(x, &y, &u);
		break;
	case 8:
		sub_028976(x, &y, &u);
		break;
	case -120:
	case -70:
	case -50:
	case -38:
	case -16:
	case 10:
	case 58:
	case 82:
		sub_0785DB(x, &y, &u, &ignored);
		break;
	case -118:
	case -68:
	case -48:
	case -36:
	case -14:
	case 12:
	case 60:
	case 84:
		sub_0785DE(x, &y, &u, &ignored);
		break;
	case -128:
	case -116:
	case -66:
	case -46:
	case -34:
	case -12:
	case 14:
	case 62:
	case 86:
		sub_0785E1(x, &y, &u, &ignored);
		break;
	case -126:
	case -114:
	case -64:
	case -44:
	case -32:
	case -10:
	case 16:
	case 64:
	case 88:
		sub_0785E4(x, &y, &u, &ignored);
		break;
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_0288E4(uint16_t x, uint16_t u)
{
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = mem_read16(x + 0xCu);
	t2 = mem_read16(x + 0x3Eu);
	if (t2 <= t1)
		return u;
	mem_write8(x + 0x42u, 1u);
	mem_write8(x + 0x57u, 0u);
	mem_write8(x, 0x80u);
	u = sub_078620(x);
	mem_write16(x + 0xFu, 0x200u);
	mem_write8(x + 5u, 0x82u);
	t3 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t3 + 1u);
	return u;
}

void sub_02890B(uint16_t x)
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
		mem_write8(x, 0xC0u);
		t1 = mem_read8(x + 9u);
		mem_write8(x + 9u, (t1 & 0xCFu) | 0x10u);
		t2 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t2 + 1u);
	}
}

void sub_028925(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(x + 0xFu, 0u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_02893D(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t ignored16 = 0, u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t7 = 0;
	uint16_t t5 = 0, t6 = 0;

	sub_028FC1(x, &y, &ignored16);
	mem_write8(x + 5u, 0xA2u);
	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t1 & 0xCFu) | 0x20u);
	mem_write8(x, 8u);
	t2 = mem_read8(x + 0x57u);
	mem_write8(x + 0x57u, t2 + 1u);
	t3 = mem_read8(x + 0x42u);
	mem_write8(x + 0x42u, t3 + 1u);
	t4 = mem_read8(x + 0x30u);
	u = loaded_table_029B98_ADDRESS + (int8_t)(((uint32_t)t4 << 1) << 1);
	t5 = DATA16(u);
	mem_write16(x + 0x3Eu, t5);
	t6 = mem_read16(u + 2u);
	mem_write8(x + VIDEO_003C, t6 >> 8);
	mem_write8(x + 0x30u, 0u);
	t7 = mem_read8(x + 2u);
	mem_write8(x + 2u, t7 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_028976(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint32_t ignored = 0;
	uint8_t t1 = 0;

	u = loaded_table_029BB0_ADDRESS;
	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
	case 28:
		sub_02897F(x);
		break;
	case 2:
		sub_02898B(x);
		break;
	case 4:
		u = sub_0289A1(x, u);
		break;
	case 6:
		sub_0289BC(x);
		break;
	case 8:
	case 32:
		sub_0289F2(x);
		break;
	case 10:
	case 34:
		sub_0289F5(x);
		break;
	case 12:
		sub_028A12(x, &y, &u);
		break;
	case 14:
		sub_028A3E(x, &y, &u);
		break;
	case -112:
	case -92:
	case -80:
	case -58:
	case -32:
	case 16:
	case 40:
		sub_0785DB(x, &y, &u, &ignored);
		break;
	case -110:
	case -90:
	case -78:
	case -56:
	case -30:
	case 18:
	case 42:
		sub_0785DE(x, &y, &u, &ignored);
		break;
	case -108:
	case -88:
	case -76:
	case -54:
	case -28:
	case 20:
	case 44:
		sub_0785E1(x, &y, &u, &ignored);
		break;
	case -106:
	case -86:
	case -74:
	case -52:
	case -26:
	case 22:
	case 46:
		sub_0785E4(x, &y, &u, &ignored);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_02897F(uint16_t x)
{
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = mem_read16(x + 0xCu);
	t2 = mem_read16(x + 0x3Eu);
	if (t1 < t2)
	{
		t3 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t3 + 1u);
	}
}

void sub_02898B(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + VIDEO_003C);
	mem_write8(x + VIDEO_003C, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 0x57u, 0u);
		mem_write8(x + 5u, 0xA2u);
		mem_write8(x, 0x88u);
		t2 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t2 + 1u);
	}
}

uint16_t sub_0289A1(uint16_t x, uint16_t u)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
		return u;
	mem_write16(x + 0x19u, 0x900u);
	mem_write8(x + 5u, 0x84u);
	u = sub_078620(x);
	sub_078626(x, u);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	return u;
}

void sub_0289BC(uint16_t x)
{
	uint32_t negative = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0;
	uint8_t t2 = 0, t3 = 0;
	uint16_t t1 = 0;

	mem_write16(x + 0x14u, 0xFE00u);
	sub_07863B(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	unk_48F0 = a;
	if ((int8_t)a < 0)
	{
		sub_0289F5(x);
		return;
	}
	b = (((unk_48F0 & 0xFu) << 1) << 1) << 1;
	t1 = mem_read16(x + 0x16u);
	if (t1 <= b)
	{
		sub_0289F2(x);
		return;
	}
	mem_write8(x + 0x5Du, b);
	unk_48F0 &= 0x30u;
	t2 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t2 & 0xCFu) | unk_48F0);
	t3 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t3 + 1u);
}

void sub_0289F2(uint16_t x)
{
	mem_write16(x + 0x14u, 0u);
	sub_0289F5(x);
}

void sub_0289F5(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;
	uint8_t t1 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry)
	{
		mem_write16(x + 0xFu, 0u);
		mem_write8(x, 0xC0u);
		t1 = mem_read8(x + 2u);
		mem_write8(x + 2u, t1 + 1u);
	}
}

void sub_028A12(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint32_t negative = 0;
	uint8_t a = 0;
	uint16_t d = 0, ignored16 = 0, u = 0, y = 0;
	uint8_t t2 = 0, t3 = 0, t5 = 0;
	uint16_t t1 = 0, t4 = 0;

	sub_0785F9(x, &y, &ignored16);
	d = 0u;
	sub_078638(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	t1 = (a & 0xFu) << 3;
	mem_write16(x + 0x5Cu, t1);
	mem_write8(x, 0x80u);
	t2 = mem_read8(x + 0x42u);
	mem_write8(x + 0x42u, t2 + 1u);
	u = indexed_table_029BC8_ADDRESS;
	t3 = mem_read8(x + 0x30u);
	t4 = DATA16(indexed_table_029BC8_ADDRESS + (int8_t)((uint32_t)t3 << 1));
	mem_write16(x + 0x3Eu, t4);
	mem_write8(x + 0x30u, 0u);
	t5 = mem_read8(x + 2u);
	mem_write8(x + 2u, t5 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_028A3E(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint32_t ignored = 0;
	uint8_t t1 = 0;

	u = loaded_table_029BCC_ADDRESS;
	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case -28:
	case 0:
		sub_02897F(x);
		break;
	case 2:
		u = sub_028A47(x);
		break;
	case -20:
	case 4:
		sub_0289F2(x);
		break;
	case -18:
	case 6:
		sub_0289F5(x);
		break;
	case 8:
		sub_028A62(x, &y, &u);
		break;
	case 10:
		u = sub_028AAA(x);
		break;
	case -120:
	case -108:
	case -86:
	case -60:
	case -12:
	case 12:
		sub_0785DB(x, &y, &u, &ignored);
		break;
	case -118:
	case -106:
	case -84:
	case -58:
	case -10:
	case 14:
		sub_0785DE(x, &y, &u, &ignored);
		break;
	case -116:
	case -104:
	case -82:
	case -56:
	case -8:
	case 16:
		sub_0785E1(x, &y, &u, &ignored);
		break;
	case -114:
	case -102:
	case -80:
	case -54:
	case -6:
	case 18:
		sub_0785E4(x, &y, &u, &ignored);
		break;
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_028A47(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t1 = 0;

	mem_write8(x, 0xC8u);
	u = sub_078620(x);
	sub_078626(x, u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	return u;
}

void sub_028A62(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint32_t negative = 0;
	uint8_t a = 0;
	uint16_t d = 0, ignored16 = 0, u = 0, y = 0;
	uint8_t t1 = 0, t4 = 0, t5 = 0;
	uint16_t t2 = 0, t3 = 0;

	sub_029012(x, &y, &ignored16);
	mem_write8(x + 5u, 0xA1u);
	mem_write8(x, 0xC8u);
	mem_write8(x + 0x42u, 1u);
	u = indexed_table_029BE0_ADDRESS;
	t1 = mem_read8(x + 0x30u);
	t2 = DATA16(indexed_table_029BE0_ADDRESS + (int8_t)((uint32_t)t1 << 1));
	mem_write16(x + 0xCu, t2);
	d = 0u;
	sub_078638(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	unk_48F0 = a & 0x30u;
	t3 = (a & 0xFu) << 3;
	mem_write16(x + 0x5Cu, t3);
	t4 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t4 & 0xCFu) | unk_48F0);
	mem_write8(x + 0x3Bu, 1u);
	mem_write8(x + 0x30u, 0u);
	t5 = mem_read8(x + 2u);
	mem_write8(x + 2u, t5 + 1u);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_028AAA(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t1 = 0;

	u = loaded_table_029BE8_ADDRESS;
	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		return sub_028AB3(x, u);
	case 2:
		sub_028AC5(x);
		return u;
	case 4:
		sub_028ADC(x);
		return u;
	}
	unreachable();
}

uint16_t sub_028AB3(uint16_t x, uint16_t u)
{
	uint16_t u_2 = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return u;
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	u_2 = sub_078620(x);
	sub_078626(x, u_2);
	sub_0785C9(x);
	return u_2;
}

void sub_028AC5(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x19u);
	mem_write16(x + 0x19u, t1 - 0x10u);
	carry = sub_078662(x);
	if (carry)
	{
		mem_write8(x + 5u, 0xA2u);
		t2 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t2 + 1u);
	}
}

void sub_028ADC(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
}

void unused_028AE0(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 0x3Bu, DATA8(indexed_table_029C2E_ADDRESS + (int8_t)unk_4861));
	mem_write8(x + 5u, 0x86u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	sub_07859C(x);
}

void sub_028AFC(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t2 = 0, t4 = 0;
	uint16_t t1 = 0, t3 = 0;

	t1 = mem_read16(x + 0x2Cu);
	if (t1 >= 0x40u)
	{
		t2 = mem_read8(x + 0x3Bu);
		mem_write8(x + 0x3Bu, t2 - 1u);
		if (t2 != 1u)
			return;
	}
	t3 = mem_read16(x + 0x2Eu);
	if (t3 >= 8u)
	{
		mem_write8(x + 2u, 2u);
		mem_write8(x + 0x3Bu, 0u);
		return;
	}
	mem_write8(x + 5u, 0xB9u);
	d = unk_4800_ADDRESS;
	carry = sub_078680(d);
	mem_write8(x + 0x3Bu, 0x20u);
	t4 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t4 + 1u);
}

uint16_t sub_028B26(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) == 0u)
		return y;
	y = hit_box_029C1E_ADDRESS;
	sub_0785B4(x, y);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	return y;
}

void sub_028B37(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(x + 0xFu, 0u);
		mem_write8(x + 5u, 0xBAu);
		t2 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t2 + 1u);
	}
}

void sub_028B4E(uint16_t x)
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

void sub_028B71(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(x + 2u, 2u);
	mem_write8(x + 0x3Bu, 0u);
}

void sub_028B80(uint16_t x)
{
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	sub_07859C(x);
	mem_write8(x + 5u, 0x90u);
	mem_write16(x + 0xFu, 0x200u);
	t1 = mem_read8(x + 0x36u);
	if ((int8_t)(t1 - 0x40u) >= 0)
	{
		t2 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t2);
	}
	mem_write8(x + 0x3Bu, 0x40u);
	t3 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t3 + 1u);
	sub_0785C6(x);
}

void unused_028BA3(void)
{
}

void sub_028BA4(uint16_t x)
{
	uint8_t t3 = 0, t4 = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = mem_read16(x + 0x2Cu);
	if (t1 < 0x20u)
	{
		mem_write16(x + 0xFu, 0u);
		t2 = mem_read16(x + 0x2Eu);
		if (t2 >= 8u)
		{
			mem_write8(x + 2u, 2u);
			mem_write8(x + 0x3Bu, 0u);
			return;
		}
		mem_write8(x + 5u, 0xB8u);
		t3 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t3 + 1u);
		return;
	}
	t4 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t4 - 1u);
	if (t4 != 1u)
		return;
	mem_write16(x + 0xFu, 0u);
	t2 = mem_read16(x + 0x2Eu);
	if (t2 >= 8u)
	{
		mem_write8(x + 2u, 2u);
		mem_write8(x + 0x3Bu, 0u);
		return;
	}
	mem_write8(x + 5u, 0xB8u);
	t3 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t3 + 1u);
}

uint16_t sub_028BC6(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) == 0u)
		return y;
	y = hit_box_029C16_ADDRESS;
	sub_0785B4(x, y);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	return y;
}

void sub_028BE0(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = io_read8(VIDEO_1874);
	if (t1 >= 3u)
	{
		mem_write8(x + 2u, 2u);
		mem_write8(x + 0x3Bu, 0u);
		return;
	}
	mem_write8(x + 5u, 0x86u);
	sub_07859C(x);
	mem_write8(x + 0x3Bu, 0x40u);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
}

void sub_028BFA(uint16_t x)
{
	uint8_t a = 0, d = 0;
	uint8_t t1 = 0, t3 = 0, t4 = 0, t5 = 0, t7 = 0;
	uint16_t t2 = 0, t6 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 2u, 2u);
		mem_write8(x + 0x3Bu, 0u);
		return;
	}
	t2 = mem_read16(x + 0x2Cu);
	if (t2 < 0x30u)
	{
		t3 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t3 + 1u);
		t4 = mem_read8(x + 0x36u);
		if (t4 >= 0x40u)
		{
			d = 0x80u;
			a = 0u;
		}
		else
		{
			d = 0x80u;
			a = 0xFFu;
		}
		mem_write16(x + 0xFu, ((uint32_t)a << 8) | (d & 0xFFu));
		t5 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t5 + 1u);
		return;
	}
	t6 = mem_read16(x + 0x2Cu);
	if (t6 < 0x50u)
	{
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
		return;
	}
	t7 = mem_read8(x + 0x36u);
	if (t7 >= 0x40u)
	{
		d = 0x80u;
		a = 0xFFu;
		mem_write16(x + 0xFu, ((uint32_t)a << 8) | (d & 0xFFu));
		t5 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t5 + 1u);
		return;
	}
	d = 0x80u;
	a = 0u;
	mem_write16(x + 0xFu, ((uint32_t)a << 8) | (d & 0xFFu));
	t5 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t5 + 1u);
}

void sub_028C39(uint16_t x)
{
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 2u, 2u);
		mem_write8(x + 0x3Bu, 0u);
		return;
	}
	t2 = mem_read16(x + 0x2Cu);
	if (t2 < 0x30u)
		mem_write8(x + 0x29u, 1u);
}

void sub_028C4D(uint16_t x)
{
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 2u, 2u);
		mem_write8(x + 0x3Bu, 0u);
		return;
	}
	t2 = mem_read16(x + 0x2Cu);
	if (t2 >= 0x50u)
		mem_write8(x + 0x29u, 1u);
}

uint16_t sub_028C67(uint16_t x)
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
		t4 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t4 + 1u);
		mem_write8(x + 0x3Bu, 1u);
		sub_07859C(x);
		return u;
	}
	mem_write8(x + 5u, 0x86u);
	u = indexed_table_029C7A_ADDRESS;
	mem_write8(x + 0x3Bu, DATA8(indexed_table_029C7A_ADDRESS + (int8_t)unk_4857));
	t5 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t5 + 1u);
	sub_07859C(x);
	return u;
}

void sub_028C93(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(x + 5u, 0xA4u);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	sub_07859C(x);
}

uint16_t sub_028CA4(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) == 0u)
		return y;
	y = hit_box_029BEE_ADDRESS;
	sub_0785B4(x, y);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	return y;
}

uint16_t sub_028CB5(uint16_t x)
{
	uint16_t y = 0;
	uint8_t t1 = 0;

	y = hit_box_029BF6_ADDRESS;
	sub_0785B4(x, y);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	sub_028CBE(x);
	return y;
}

void sub_028CBE(uint16_t x)
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

void sub_028CCE(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(x + 5u, 0xB2u);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	sub_07859C(x);
}

void unused_028CE5(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 5u, 0x86u);
	mem_write8(x + 0x3Bu, 4u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	sub_07859C(x);
}

void sub_028CF5(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 5u, 0xA5u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	sub_07859C(x);
}

uint16_t sub_028D00(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) == 0u)
		return y;
	y = hit_box_029BFE_ADDRESS;
	sub_0785B4(x, y);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	return y;
}

void sub_028D17(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 5u, 0xA3u);
	sub_07859C(x);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

uint16_t sub_028D23(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) == 0u)
		return y;
	y = hit_box_029C06_ADDRESS;
	sub_0785B4(x, y);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	return y;
}

void sub_028D3A(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(x + 2u, 2u);
	mem_write8(x + 0x3Bu, 0u);
}

uint16_t sub_028D43(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t1 = 0, t2 = 0;
	uint16_t t3 = 0;

	u = indexed_table_029CA3_ADDRESS;
	if (unk_4858 <= DATA8(indexed_table_029CA3_ADDRESS + (int8_t)unk_4861))
	{
		mem_write8(x + 5u, 0xA6u);
		t1 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t1 + 1u);
		sub_07859C(x);
		return u;
	}
	mem_write8(x + 5u, 0x90u);
	sub_07859C(x);
	mem_write16(x + 0xFu, 0x180u);
	t2 = mem_read8(x + 9u);
	if ((t2 & 0x40u) != 0u)
	{
		t3 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t3);
	}
	mem_write8(x + 0x3Bu, 0x10u);
	mem_write8(x + 0x29u, 4u);
	return u;
}

void sub_028D7E(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0, t4 = 0;
	uint16_t t3 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
		return;
	mem_write8(x + 5u, 0xA7u);
	mem_write16(x + 0xFu, 0x200u);
	t2 = mem_read8(x + 9u);
	if ((t2 & 0x40u) != 0u)
	{
		t3 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t3);
	}
	mem_write16(x + 0x19u, 0x400u);
	t4 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t4 + 1u);
}

uint16_t sub_028DA3(uint16_t x, uint16_t y)
{
	uint16_t d = 0;
	uint8_t t3 = 0, t4 = 0;
	uint16_t t1 = 0, t2 = 0, t5 = 0;

	t1 = mem_read16(x + 0x16u);
	t2 = mem_read16(x + 0x5Cu);
	if ((uint16_t)(t1 - t2) >= 4u)
	{
		t3 = mem_read8(x + 6u);
		if ((((uint16_t)((uint32_t)t3 << 8) >> 8) & 2u) != 0u)
		{
			y = hit_box_029C0E_ADDRESS;
			sub_0785B4(x, y);
		}
	}
	else
	{
		mem_write8(x + 5u, 0xA8u);
		y = hit_box_029BF6_ADDRESS;
		sub_0785B4(x, y);
		t4 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t4 + 1u);
	}
	t5 = mem_read16(x + 0x19u);
	d = t5 - 0x40u;
	sub_028DD9(x, d);
	return y;
}

void sub_028DD3(uint16_t x)
{
	uint16_t d = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x19u);
	d = t1 - 0x10u;
	sub_028DD9(x, d);
}

void sub_028DD9(uint16_t x, uint16_t d)
{
	uint32_t carry = 0;

	mem_write16(x + 0x19u, d);
	carry = sub_078662(x);
	if (carry == 0u)
		return;
	mem_write8(x + 5u, 0xA8u);
	mem_write8(x + 2u, 2u);
	mem_write8(x + 0x3Bu, 0u);
}

void sub_028DF0(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		mem_write8(x + 5u, 0xA7u);
		mem_write16(x + 0x19u, 0x400u);
		t2 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t2 + 1u);
	}
}

uint16_t sub_028E14(uint16_t x, uint16_t u)
{
	uint8_t a = 0;
	uint16_t d = 0, u_2 = 0;
	uint8_t t1 = 0, t3 = 0, t4 = 0, t5 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 0x32u);
	if ((int8_t)t1 < 0)
	{
		mem_write16(x + 0x28u, 0x200u);
		sub_028CF5(x);
		return u;
	}
	t2 = mem_read16(x + 0x38u);
	u_2 = t2;
	t3 = mem_read8(u_2 + 2u);
	if ((int8_t)t3 < 0)
	{
		mem_write8(x + 2u, 2u);
		mem_write8(x + 0x3Bu, 0u);
		return u_2;
	}
	t4 = mem_read8(u_2 + 0x3Du);
	if (t4 != 0u)
	{
		mem_write8(x + 2u, 2u);
		mem_write8(x + 0x3Bu, 0u);
		return u_2;
	}
	sub_07859C(x);
	mem_write8(x + 0x3Bu, 0x40u);
	d = sub_07861D(x, u_2);
	a = (uint8_t)(d >> 8);
	d = ((uint32_t)a << 8) | 0x30u;
	sub_078617(x, d);
	t5 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t5 + 1u);
	sub_07D25D(x);
	return u_2;
}

void sub_028E4C(uint16_t x, uint16_t *p_y, uint16_t *p_u)
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
				d = ((uint32_t)a << 8) | 0x30u;
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
			mem_write16(x + 0xFu, 0u);
			mem_write16(x + 0x14u, 0u);
			mem_write16(x + 0x28u, 0x200u);
		}
		else
		{
			t5 = mem_read8(u + 0x3Du);
			if (t5 != 0u)
			{
				mem_write16(x + 0xFu, 0u);
				mem_write16(x + 0x14u, 0u);
				mem_write16(x + 0x28u, 0x200u);
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
							d = ((uint32_t)a << 8) | 0x30u;
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
								d = ((uint32_t)a << 8) | 0x30u;
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
									d = ((uint32_t)a << 8) | 0x30u;
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
										d = ((uint32_t)a << 8) | 0x30u;
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
											d = ((uint32_t)a << 8) | 0x30u;
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
									unk_48F0 = t14 & 0x40u;
									t15 = mem_read8(x + 9u);
									mem_write8(x + 9u, (t15 & 0xBFu) | unk_48F0);
									t16 = mem_read8(u + 0x5Bu);
									stack = t16 & 0x70u;
									t17 = mem_read8(x + 0x27u);
									mem_write8(x + 0x27u, (t17 & 0x8Fu) | stack);
									y = indexed_table_029CD3_ADDRESS;
									t18 = mem_read8(u + 0x5Bu);
									mem_write8(x + 5u, DATA8(indexed_table_029CD3_ADDRESS + ((((t18 >> 1) >> 1) >> 1) >> 1)) | 0x80u);
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

void sub_028F00(uint16_t x, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t a = 0;
	uint16_t u = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0;
	uint16_t t1 = 0;

	mem_write8(x + 0x1Du, 0u);
	t1 = mem_read16(x + 0x38u);
	u = t1;
	t2 = mem_read8(u + 0x3Du);
	if (t2 == 0u)
	{
		t3 = mem_read8(x + 0x1Bu);
		a = t3 - 2u;
		mem_write8(x + 0x1Bu, a);
		if ((int8_t)a < 0)
			mem_write8(x + 0x1Bu, 0u);
		mem_write8(x + 0x1Du, 0u);
		mem_write8(x, 0x88u);
		mem_write8(x + 2u, 4u);
		mem_write8(x + 0x28u, (unk_4858 & 1u) + 2u);
		mem_write8(x + 0x29u, 0u);
		*p_y = y;
		*p_u = u;
		sub_0785E1(x, p_y, p_u, p_left_caller);
		return;
	}
	t4 = mem_read8(u + 0x1Bu);
	if (t4 == 0u)
	{
		mem_write8(x + 2u, 2u);
		mem_write8(x + 0x3Bu, 0u);
	}
	else
	{
		t5 = mem_read8(x + 0x58u);
		if (t5 == 2u)
		{
			t6 = mem_read8(x + 0x58u);
			mem_write8(x + 0x58u, t6 + 1u);
			y = indexed_table_029CD3_ADDRESS;
			t7 = mem_read8(u + 0x5Bu);
			mem_write8(x + 5u, (DATA8(indexed_table_029CD3_ADDRESS + ((((t7 >> 1) >> 1) >> 1) >> 1)) + 1u) | 0x80u);
			mem_write8(x + 0x29u, 3u);
		}
	}
	*p_y = y;
	*p_u = u;
}

void sub_028F5F(uint16_t x, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint16_t u = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		mem_write8(x + 0x58u, 1u);
		t2 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t2 - 1u);
	}
	*p_y = y;
	*p_u = u;
	sub_028F00(x, p_y, p_u, p_left_caller);
}

void sub_028F7B(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0;

	u = object_setup_029E4B_ADDRESS;
	y = sub_0785AB(x, u);
	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, t1 | 0x40u);
	mem_write8(x + 0x42u, 1u);
	u = sub_078620(x);
	sub_078626(x, u);
	u = enemy_behaviour_029CDF_ADDRESS;
	mem_write16(x + 0x2Au, enemy_behaviour_029CDF_ADDRESS);
	mem_write8(x + 0x3Au, 0x10u);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_028FA0(uint16_t x)
{
	uint16_t ignored16 = 0, y = 0;
	uint8_t t1 = 0;

	sub_028F7B(x, &y, &ignored16);
	t1 = mem_read8(x + 0x30u);
	if (t1 != 0u)
		mem_write8(x + 0x1Bu, 1u);
	mem_write8(x + 0x30u, 0u);
	mem_write8(x + 2u, 2u);
	return y;
}

void sub_028FC1(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0;

	u = object_setup_029E5D_ADDRESS;
	y = sub_0785AB(x, u);
	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, t1 | 0x40u);
	mem_write8(x + 0x42u, 1u);
	u = sub_078620(x);
	sub_078626(x, u);
	u = enemy_behaviour_029D37_ADDRESS;
	mem_write16(x + 0x2Au, enemy_behaviour_029D37_ADDRESS);
	mem_write8(x + 0x3Au, 0x10u);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_028FE6(uint16_t x)
{
	uint16_t ignored16 = 0, y = 0;
	uint8_t t1 = 0;

	sub_028FC1(x, &y, &ignored16);
	t1 = mem_read8(x + 0x30u);
	if (t1 != 0u)
		mem_write8(x + 0x1Bu, 1u);
	mem_write8(x + 0x30u, 0u);
	mem_write8(x + 2u, 2u);
	return y;
}

void sub_029007(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t1 & 0x70u) | 0x86u);
}

void sub_029012(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0;

	u = object_setup_029E6F_ADDRESS;
	y = sub_0785AB(x, u);
	sub_029007(x);
	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, t1 | 0x40u);
	mem_write8(x + 0x42u, 1u);
	u = sub_078620(x);
	sub_078626(x, u);
	u = enemy_behaviour_029D8F_ADDRESS;
	mem_write16(x + 0x2Au, enemy_behaviour_029D8F_ADDRESS);
	mem_write8(x + 0x3Au, 0x10u);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_029039(uint16_t x)
{
	uint16_t ignored16 = 0, y = 0;
	uint8_t t1 = 0;

	sub_029012(x, &y, &ignored16);
	t1 = mem_read8(x + 0x30u);
	if (t1 != 0u)
		mem_write8(x + 0x1Bu, 1u);
	mem_write8(x + 0x30u, 0u);
	mem_write8(x + 2u, 2u);
	return y;
}

void sub_02905A(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0;

	u = object_setup_029E81_ADDRESS;
	y = sub_0785AB(x, u);
	sub_029007(x);
	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, t1 | 0x40u);
	mem_write8(x + 0x42u, 1u);
	u = sub_078620(x);
	sub_078626(x, u);
	u = enemy_behaviour_029DE7_ADDRESS;
	mem_write16(x + 0x2Au, enemy_behaviour_029DE7_ADDRESS);
	mem_write8(x + 0x3Au, 0x10u);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_029082(uint16_t x)
{
	uint16_t ignored16 = 0, y = 0;
	uint8_t t1 = 0;

	sub_02905A(x, &y, &ignored16);
	t1 = mem_read8(x + 0x30u);
	if (t1 != 0u)
		mem_write8(x + 0x1Bu, 1u);
	mem_write8(x + 0x30u, 0u);
	mem_write8(x + 2u, 2u);
	return y;
}

void sub_02909D(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 5u, 0x91u);
	sub_07859C(x);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

void sub_0290A9(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;
	uint16_t t4 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) != 0u)
	{
		t2 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t2 + 1u);
		y = child_object_029ED5_ADDRESS;
		sub_07862F(x, y, &u, &carry);
		if (carry)
		{
			mem_write16(u + 0xFu, 0x300u);
			t3 = mem_read8(x + 9u);
			if ((t3 & 0x40u) != 0u)
			{
				t4 = mem_read16(u + 0xFu);
				mem_write16(u + 0xFu, 0u - t4);
			}
		}
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_0290D2(uint16_t x)
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
		t4 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t4 + 1u);
		mem_write8(x + 0x3Bu, 1u);
		sub_07859C(x);
		return u;
	}
	mem_write8(x + 5u, 0x80u);
	u = indexed_table_029EE5_ADDRESS;
	mem_write8(x + 0x3Bu, DATA8(indexed_table_029EE5_ADDRESS + (int8_t)unk_4857));
	t5 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t5 + 1u);
	sub_07859C(x);
	return u;
}

void sub_0290FE(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(x + 5u, 0x92u);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	sub_07859C(x);
}

uint16_t sub_02910F(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) == 0u)
		return y;
	y = hit_box_029E8F_ADDRESS;
	sub_0785B4(x, y);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	return y;
}

uint16_t sub_029126(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t1 = 0;

	mem_write8(x + 5u, 0x80u);
	u = indexed_table_029EF4_ADDRESS;
	mem_write8(x + 0x3Bu, DATA8(indexed_table_029EF4_ADDRESS + (int8_t)unk_4857));
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	sub_07859C(x);
	return u;
}

void sub_02913C(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 5u, 0x91u);
		t2 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t2 + 1u);
	}
}

uint16_t sub_02914A(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) == 0u)
		return y;
	y = hit_box_029E9F_ADDRESS;
	sub_0785B4(x, y);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	return y;
}

uint16_t sub_02915B(uint16_t x)
{
	uint16_t y = 0;
	uint8_t t1 = 0;

	y = hit_box_029E87_ADDRESS;
	sub_0785B4(x, y);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	sub_029164(x);
	return y;
}

void sub_029164(uint16_t x)
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

void sub_029174(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(x + 5u, 0xA0u);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	sub_07859C(x);
}

uint16_t sub_029185(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) == 0u)
		return y;
	y = hit_box_029E97_ADDRESS;
	sub_0785B4(x, y);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	return y;
}

void sub_02919C(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 5u, 0x91u);
	sub_07859C(x);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

uint16_t sub_0291A8(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) == 0u)
		return y;
	y = hit_box_029EBF_ADDRESS;
	sub_0785B4(x, y);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	return y;
}

void sub_0291BF(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 5u, 0x92u);
	sub_07859C(x);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

uint16_t sub_0291CB(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) == 0u)
		return y;
	y = hit_box_029EC7_ADDRESS;
	sub_0785B4(x, y);
	mem_write8(x + 0x3Bu, 0x10u);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	return y;
}

uint16_t sub_0291E1(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return y;
	y = hit_box_029E87_ADDRESS;
	sub_0785B4(x, y);
	mem_write8(x + 5u, 0xA5u);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	return y;
}

void sub_0291F5(uint16_t x)
{
	mem_write8(x + 2u, 2u);
	mem_write8(x + 0x3Bu, 0u);
}

void sub_0291FE(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 5u, 0xA0u);
	sub_07859C(x);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

uint16_t sub_02920A(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) == 0u)
		return y;
	y = hit_box_029EAF_ADDRESS;
	sub_0785B4(x, y);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	return y;
}

void sub_029221(uint16_t x)
{
	uint8_t t1 = 0;

	sub_07859C(x);
	mem_write8(x + 5u, 0x90u);
	mem_write8(x + 0x3Bu, 8u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

uint16_t sub_029232(uint16_t x, uint16_t y)
{
	uint16_t y_2 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return y;
	y_2 = hit_box_029EB7_ADDRESS;
	sub_0785B4(x, y_2);
	sub_02923D(x);
	return y_2;
}

void sub_02923D(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0, t4 = 0;
	uint16_t t3 = 0;

	t1 = mem_read8(x + 0x2Du);
	mem_write8(x + 0x3Bu, (((t1 >> 1) >> 1) >> 1) + 8u);
	mem_write16(x + 0x14u, 0u);
	mem_write16(x + 0xFu, 0x200u);
	t2 = mem_read8(x + 9u);
	if ((t2 & 0x40u) != 0u)
	{
		t3 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t3);
	}
	t4 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t4 + 1u);
}

uint16_t sub_029261(uint16_t x, uint16_t y)
{
	uint16_t y_2 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return y;
	y_2 = hit_box_029E87_ADDRESS;
	sub_0785B4(x, y_2);
	mem_write8(x + 2u, 2u);
	mem_write8(x + 0x3Bu, 0u);
	return y_2;
}

void sub_029276(uint16_t x)
{
	uint8_t t1 = 0;

	sub_07859C(x);
	mem_write8(x + 5u, 0xA4u);
	mem_write8(x + 0x3Bu, 8u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

uint16_t sub_029287(uint16_t x, uint16_t y)
{
	uint16_t y_2 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return y;
	y_2 = hit_box_029EA7_ADDRESS;
	sub_0785B4(x, y_2);
	sub_02923D(x);
	return y_2;
}

void sub_02929C(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 5u, 0xABu);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	sub_07859C(x);
}

void sub_0292A7(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) != 0u)
	{
		y = child_object_029F2F_ADDRESS;
		sub_07862F(x, y, &u, &carry);
		if (carry == 0u)
		{
			mem_write8(x + 2u, 2u);
			mem_write8(x + 0x3Bu, 0u);
		}
		else
		{
			mem_write16(x + 0x40u, u);
			mem_write8(x + 0x3Bu, 0x30u);
			t2 = mem_read8(x + 0x29u);
			mem_write8(x + 0x29u, t2 + 1u);
		}
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_0292C3(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t2 = 0, t3 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x40u);
	u = t1;
	if (mem_read8(u) == 0u)
	{
		mem_write8(x + 2u, 2u);
		mem_write8(x + 0x3Bu, 0u);
		return u;
	}
	t2 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t2 - 1u);
	if (t2 == 1u)
	{
		mem_write8(x + 5u, 0xACu);
		t3 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t3 + 1u);
	}
	return u;
}

void sub_0292DA(uint16_t x)
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

void sub_0292EF(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = 0x7F51u;
		t1 = mem_read8(x + 0x29u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			sub_0292F8(x);
			break;
		case 2:
			sub_029308(x);
			break;
		case -12:
		case -10:
			continue;
		case -8:
			sub_029312(x, &y, &u);
			break;
		case -6:
			y = sub_02933A(x, y);
			break;
		case -4:
			sub_02935D(x);
			break;
		case -2:
			sub_029365(x);
			break;
		}
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_0292F8(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x19u, 0u);
	mem_write16(x + 4u, 0x480u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

void sub_029308(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
		mem_write8(x, 0u);
}

void sub_029312(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t2 = 0, t4 = 0;
	uint16_t t1 = 0, t3 = 0;

	u = object_setup_029F55_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write16(x + 0x19u, 0x200u);
	mem_write16(x + 0xFu, 0x200u);
	t1 = mem_read16(x + 0x40u);
	u = t1;
	t2 = mem_read8(u + 9u);
	if ((t2 & 0x40u) != 0u)
	{
		t3 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t3);
	}
	mem_write8(x, 0xC8u);
	t4 = mem_read8(x + 2u);
	mem_write8(x + 2u, t4 + 1u);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_02933A(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, y_2 = 0;
	uint8_t t1 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry == 0u)
		return y;
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 4u, 0x9C8Au);
	mem_write8(x, 0xC0u);
	y_2 = hit_box_029F3D_ADDRESS;
	sub_0785B4(x, y_2);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	d = 0x6F00u;
	carry = sub_078680(d);
	return y_2;
}

void sub_02935D(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	sub_029365(x);
}

void sub_029365(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
		mem_write8(x, 0u);
}

void sub_02937B(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0;
	uint16_t t3 = 0, t4 = 0;

	sub_0785F9(x, &y, &u);
	mem_write8(x + 0x1Bu, 1u);
	mem_write8(x + 5u, 0xB3u);
	t1 = mem_read8(x + 0x30u);
	mem_write8(x + 0x3Bu, t1);
	mem_write8(x + 0x3Au, 0x10u);
	mem_write8(x + 0x30u, 0u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	mem_write16(x + 0xFu, 0x200u);
	t3 = mem_read16(x + 0xCu);
	if (t3 >= 0xE0u)
	{
		t4 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t4);
	}
	sub_0785C6(x);
	*p_y = y;
	*p_u = u;
}

void sub_0293AD(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint32_t ignored = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_029F67_ADDRESS;
		t1 = mem_read8(x + 0x29u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			u = sub_0293B6(x, u);
			break;
		case 2:
			sub_0293D0(x, &y, &u);
			break;
		case 4:
			sub_0293E1(x);
			break;
		case -8:
		case 32:
		case 44:
		case 64:
		case 84:
			sub_0785DB(x, &y, &u, &ignored);
			break;
		case -6:
		case 34:
		case 46:
		case 66:
		case 86:
			sub_0785DE(x, &y, &u, &ignored);
			break;
		case -2:
		case 38:
		case 50:
		case 70:
		case 90:
			sub_0785E4(x, &y, &u, &ignored);
			break;
		case -12:
			sub_02937B(x, &y, &u);
			break;
		case -10:
			continue;
		case -4:
			sub_0785E1(x, &y, &u, &ignored);
			break;
		}
		break;
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_0293B6(uint16_t x, uint16_t u)
{
	uint16_t u_2 = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return u;
	mem_write16(x + 0xFu, 0u);
	mem_write8(x + 5u, 0xA9u);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	u_2 = sub_078620(x);
	sub_078626(x, u_2);
	sub_07859C(x);
	return u_2;
}

void sub_0293D0(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t u_2 = 0, y_2 = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) == 0u)
		return;
	y_2 = child_object_029F6D_ADDRESS;
	sub_07862F(x, y_2, &u_2, &carry);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	*p_y = y_2;
	*p_u = u_2;
}

void sub_0293E1(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

uint16_t sub_0293F7(uint16_t x)
{
	uint16_t ignored16 = 0, y = 0;

	sub_02940A(x);
	sub_028144(x, &y, &ignored16);
	sub_029429(x);
	return y;
}

void sub_02940A(uint16_t x)
{
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 0x30u);
	t2 = DATA16(indexed_table_029F9B_ADDRESS + (int8_t)((uint32_t)t1 << 1));
	mem_write16(x + 0xCu, t2);
	t3 = mem_read8(x + 0x30u);
	if ((int8_t)t3 < 0)
		mem_write8(x + 0x1Bu, 1u);
	mem_write8(x + 0x30u, 0u);
}

uint16_t sub_029424(uint16_t x)
{
	uint16_t ignored16 = 0, y = 0;

	sub_02940A(x);
	sub_0785F9(x, &y, &ignored16);
	sub_029429(x);
	return y;
}

void sub_029429(uint16_t x)
{
	uint8_t t1 = 0, t4 = 0;
	uint16_t t2 = 0, t3 = 0, t5 = 0;

	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t1 & 0xCFu) | 0x20u);
	mem_write8(x + 5u, 0x90u);
	mem_write16(x + 0xFu, 0x200u);
	t2 = mem_read16(x + 0xCu);
	if (t2 >= 0xE0u)
	{
		t3 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t3);
	}
	t4 = mem_read8(x + 2u);
	mem_write8(x + 2u, t4 + 1u);
	sub_0785C6(x);
	t5 = unk_48E2;
	mem_write16(x + 0x19u, t5);
}

uint16_t sub_02945B(uint16_t x, uint16_t y)
{
	uint16_t ignored16 = 0, y_2 = 0;
	uint32_t ignored = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_029464(x);
		return y;
	case 2:
		sub_02949A(x, 0u);
		return y;
	case 4:
		sub_0294B9(x, &y_2, &ignored16);
		return y_2;
	case 6:
		sub_0294FE(x, &y, &ignored16);
		return y;
	case -64:
	case -24:
	case -12:
	case 8:
	case 28:
		sub_0785DB(x, &y, &ignored16, &ignored);
		return y;
	case -62:
	case -22:
	case -10:
	case 10:
	case 30:
		sub_0785DE(x, &y, &ignored16, &ignored);
		return y;
	case -20:
	case -8:
	case 12:
	case 32:
		sub_0785FC(x, &y, &ignored16);
		return y;
	case -58:
	case -18:
	case -6:
	case 14:
	case 34:
		sub_0785E4(x, &y, &ignored16, &ignored);
		return y;
	}
	unreachable();
}

void sub_029464(uint16_t x)
{
	uint32_t negative = 0;
	uint8_t a = 0;
	uint16_t d = 0;
	uint8_t t2 = 0, t3 = 0;
	uint16_t t1 = 0;

	sub_078644(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	mem_write8(x + 0x46u, a);
	if ((int8_t)a < 0)
	{
		t1 = unk_48E2;
		mem_write16(x + 0x19u, t1);
		return;
	}
	mem_write8(x + 0x5Du, (((a & 0xFu) << 1) << 1) << 1);
	t2 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t2 & 0xCFu) | 0x10u);
	mem_write16(x + 0x19u, 0x400u);
	mem_write8(x, 0x88u);
	mem_write8(x + 5u, 0x84u);
	t3 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t3 + 1u);
}

uint16_t sub_02949A(uint16_t x, uint16_t u)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry == 0u)
		return u;
	mem_write8(x, 0xC0u);
	u = sub_078620(x);
	mem_write8(x + 2u, 2u);
	return u;
}

void sub_0294B9(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t ignored16 = 0, u = 0, y = 0;
	uint8_t t1 = 0, t4 = 0, t6 = 0;
	uint16_t t2 = 0, t3 = 0, t5 = 0;

	t1 = mem_read8(x + 0x30u);
	t2 = DATA16(indexed_table_029FAF_ADDRESS + (int8_t)((uint32_t)t1 << 1));
	mem_write16(x + 0xCu, t2);
	mem_write8(x + 0x30u, 0u);
	mem_write16(x + 0x16u, 0xFF80u);
	sub_0785F9(x, &ignored16, &u);
	y = hit_box_029F7B_ADDRESS;
	sub_0785B4(x, y);
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
	*p_y = y;
	*p_u = u;
}

void sub_0294FE(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint32_t ignored = 0;
	uint8_t t1 = 0;

	u = loaded_table_029FB3_ADDRESS;
	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_029507(x);
		break;
	case 2:
		sub_029546(x, &y, &u);
		break;
	case 4:
		sub_02956B(x, &y, &u);
		break;
	case 6:
		sub_0295A5(x);
		break;
	case -84:
	case -44:
	case -32:
	case -12:
	case 8:
		sub_0785DB(x, &y, &u, &ignored);
		break;
	case -82:
	case -42:
	case -30:
	case -10:
	case 10:
		sub_0785DE(x, &y, &u, &ignored);
		break;
	case -40:
	case -28:
	case -8:
	case 12:
		sub_0785FC(x, &y, &u);
		break;
	case -78:
	case -38:
	case -26:
	case -6:
	case 14:
		sub_0785E4(x, &y, &u, &ignored);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_029507(uint16_t x)
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

void sub_029546(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t ignored16 = 0, u_2 = 0, y_2 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry == 0u)
		return;
	mem_write8(x, 0xC0u);
	y_2 = hit_box_029F73_ADDRESS;
	sub_0785B4(x, y_2);
	u_2 = sub_078620(x);
	mem_write8(x + 2u, 2u);
	*p_y = y_2;
	*p_u = u_2;
}

void sub_02956B(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t ignored16 = 0, u = 0, y = 0;
	uint8_t t1 = 0, t3 = 0, t4 = 0;
	uint16_t t2 = 0, t5 = 0;

	t1 = mem_read8(x + 0x30u);
	t2 = DATA16(indexed_table_029FC3_ADDRESS + (int8_t)((uint32_t)t1 << 1));
	mem_write16(x + 0xCu, t2);
	sub_029012(x, &y, &ignored16);
	mem_write8(x, 0x88u);
	mem_write16(x + 0x5Cu, 0u);
	mem_write8(x + 5u, 0xA1u);
	mem_write8(x + 0x3Bu, 1u);
	t3 = mem_read8(x + 0x30u);
	if ((int8_t)t3 < 0)
		mem_write8(x + 0x1Bu, 1u);
	mem_write8(x + 0x30u, 0u);
	t4 = mem_read8(x + 2u);
	mem_write8(x + 2u, t4 + 1u);
	t5 = mem_read16(x + 0x38u);
	u = t5;
	sub_078626(x, u);
	sub_0785C9(x);
	*p_y = y;
	*p_u = u;
}

void sub_0295A5(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = mem_read16(x + 0x19u);
	t2 = t1 - 0x10u;
	mem_write16(x + 0x19u, t2);
	carry = sub_078662(x);
	if (carry)
	{
		mem_write8(x, 0xC0u);
		mem_write8(x + 5u, 0xA2u);
		t3 = mem_read8(x + 2u);
		mem_write8(x + 2u, t3 + 1u);
	}
}
