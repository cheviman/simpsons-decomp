/**
 *    Name:        unsorted/bank_18.c
 *    Description: bank 18's code
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    06-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

uint16_t sub_030000(uint16_t x, uint16_t y, uint8_t d)
{
	uint32_t carry = 0;
	uint8_t b = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		y = sub_03159C(x);
		break;
	case 2:
		sub_0315B3(x);
		break;
	case 4:
		sub_031556(x);
		break;
	case 6:
	case 12:
		sub_031583(x);
		break;
	case 8:
	case 14:
		sub_03159B();
		break;
	case 10:
		sub_03156E(x);
		break;
	case -6:
		y = sub_03154D(x, y);
		break;
	case -4:
	case -2:
		y = sub_031565(x, y);
		break;
	}
	sub_078593(x, 0u);
	carry = sub_078683(x, carry);
	return y;
}

void sub_030003(void)
{
}

uint16_t sub_030006(uint16_t x, uint16_t y, uint8_t d)
{
	uint8_t b = 0;
	uint16_t ignored16 = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		y = sub_031608(x);
		break;
	case 2:
		y = sub_03161B(x);
		break;
	case 4:
		sub_03164B(x);
		break;
	case 6:
		sub_031690(x);
		break;
	case 8:
		sub_0316A1(x);
		break;
	case 10:
		sub_0316B0(x);
		break;
	case 12:
		sub_0315F6(x);
		break;
	case 14:
		sub_031607();
		break;
	case -4:
	case -2:
		y = sub_0315ED(x, y);
		break;
	}
	sub_078593(x, 0u);
	sub_0785B7(x, ignored16);
	return y;
}

void sub_030009(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		y = sub_030122(x);
		break;
	case 2:
		y = sub_030173(x, y);
		break;
	case 4:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case 6:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case 8:
		sub_07865C(x, &y, &ignored16);
		break;
	case 10:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

uint16_t sub_03000C(uint16_t x, uint16_t y, uint8_t d)
{
	uint8_t b = 0;
	uint16_t ignored16 = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_03045F(x, &y, &ignored16);
		break;
	case 2:
		sub_0304A4(x);
		break;
	case 4:
		sub_0304BB(x, 0u);
		break;
	case 6:
		sub_030504(x, &y, &ignored16);
		break;
	case 8:
		y = sub_030531(x, y);
		break;
	case 10:
		sub_03054E(x);
		break;
	case 12:
		sub_0303F2(x);
		break;
	case 14:
		sub_030408(x);
		break;
	case -44:
		sub_03017C(x);
		break;
	case -42:
		sub_0301D9(x);
		break;
	case -40:
		sub_0301F4(x);
		break;
	case -38:
		sub_030219(x);
		break;
	case -36:
		sub_030223(x);
		break;
	case -34:
		sub_030247(x);
		break;
	case -32:
		sub_030250(x);
		break;
	case -30:
		sub_030295(x);
		break;
	case -28:
		sub_0302B7(x);
		break;
	case -26:
		sub_0302CE(x);
		break;
	case -24:
		sub_0302DA(x);
		break;
	case -22:
		y = sub_03030B(x, y);
		break;
	case -20:
		y = sub_030326(x, y);
		break;
	case -18:
		sub_03034C(x);
		break;
	case -16:
		sub_030367(x);
		break;
	case -14:
		sub_030379(x);
		break;
	case -12:
		y = sub_030384(x, y);
		break;
	case -10:
		y = sub_030395(x);
		break;
	case -8:
		sub_03039E(x);
		break;
	case -6:
		sub_0303C2(x);
		break;
	case -4:
		sub_030432(x, &y, &ignored16);
		break;
	case -2:
		sub_0303E9(x, &y, &ignored16);
		break;
	}
	sub_078593(x, ignored16);
	sub_0785B7(x, ignored16);
	return y;
}

void sub_03000F(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_031A38_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_030565(x, &y, &u);
		break;
	case 2:
	case 20:
		sub_030590(x);
		break;
	case 4:
	case 22:
		sub_0305A9(x);
		break;
	case 6:
		u = sub_0305B8(x, u);
		break;
	case 8:
		sub_0305D0(x);
		break;
	case 10:
		sub_0305E3(x);
		break;
	case 12:
		sub_0305F2(x);
		break;
	case 14:
		sub_03060D(x);
		break;
	case 16:
		sub_030619(x);
		break;
	case 18:
		sub_030622(x);
		break;
	case 24:
		sub_03062C(x);
		break;
	case 26:
		sub_03063B(x);
		break;
	case 28:
		sub_03064A(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_030012(void)
{
}

void sub_030015(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_031A0C_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_030379(x);
		break;
	case 2:
		y = sub_030384(x, y);
		break;
	case 4:
		y = sub_030395(x);
		break;
	case 6:
		sub_03039E(x);
		break;
	case 8:
		sub_0303C2(x);
		break;
	case 10:
		sub_030432(x, &y, &u);
		break;
	case 12:
		sub_0303E9(x, &y, &u);
		break;
	case 14:
		sub_03045F(x, &y, &u);
		break;
	case 16:
		sub_0304A4(x);
		break;
	case 18:
		u = sub_0304BB(x, u);
		break;
	case 20:
		sub_030504(x, &y, &u);
		break;
	case 22:
		y = sub_030531(x, y);
		break;
	case 24:
		sub_03054E(x);
		break;
	case 26:
		sub_0303F2(x);
		break;
	case 28:
		sub_030408(x);
		break;
	case -30:
		u = sub_03017C(x);
		break;
	case -28:
		sub_0301D9(x);
		break;
	case -26:
		sub_0301F4(x);
		break;
	case -24:
		sub_030219(x);
		break;
	case -22:
		sub_030223(x);
		break;
	case -20:
		sub_030247(x);
		break;
	case -18:
		sub_030250(x);
		break;
	case -16:
		sub_030295(x);
		break;
	case -14:
		sub_0302B7(x);
		break;
	case -12:
		sub_0302CE(x);
		break;
	case -10:
		sub_0302DA(x);
		break;
	case -8:
		y = sub_03030B(x, y);
		break;
	case -6:
		y = sub_030326(x, y);
		break;
	case -4:
		sub_03034C(x);
		break;
	case -2:
		sub_030367(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_030018(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_031F1C_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_0312F8(x, &y, &u);
		break;
	case 2:
		sub_031311(x);
		break;
	case 4:
		sub_031322(x);
		break;
	case 6:
		sub_031336(x);
		break;
	case 8:
		sub_031351(x);
		break;
	case 10:
		sub_031371(x);
		break;
	case 12:
		sub_031382();
		break;
	}
	carry = sub_078683(x, carry);
	*p_y = y;
	*p_u = u;
}

void sub_03001B(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_031F4A_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_0314E2(x, &y, &u);
		break;
	case 2:
		sub_03150C();
		break;
	case 4:
		sub_03150D(x);
		break;
	case 6:
		sub_03152E(x);
		break;
	}
	carry = sub_078683(x, carry);
	*p_y = y;
	*p_u = u;
}

void sub_03001E(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_031F30_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_03138C(x, &y, &u);
		break;
	case 2:
		u = sub_0313B8(x, u);
		break;
	case 4:
		sub_0313DB(x);
		break;
	case 6:
		sub_0313EA(x);
		break;
	case 8:
		u = sub_0313FB(x, u);
		break;
	case 10:
		sub_03141E(x);
		break;
	case 12:
		sub_03144C(x);
		break;
	case 14:
		sub_031471(x);
		break;
	case 16:
		sub_0314B6(x);
		break;
	case 18:
		sub_0314CD(x);
		break;
	}
	carry = sub_078683(x, carry);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_030021(uint16_t x, uint16_t y, uint8_t d)
{
	uint8_t b = 0;
	uint16_t ignored16 = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		y = sub_030081(x);
		break;
	case 2:
		sub_0300B0(x);
		break;
	case 4:
		sub_0300CF(x);
		break;
	case 6:
		sub_0300F0(x);
		break;
	case 8:
		sub_03010C(x);
		break;
	case 10:
		sub_030069(x);
		break;
	case 12:
		sub_030077(x);
		break;
	case -4:
	case -2:
		y = sub_030060(x, y);
		break;
	}
	sub_078593(x, 0u);
	sub_0785B7(x, ignored16);
	return y;
}

void sub_030024(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_0319F8_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_030247(x);
		break;
	case 2:
		sub_030250(x);
		break;
	case 4:
		sub_030295(x);
		break;
	case 6:
		sub_0302B7(x);
		break;
	case 8:
		sub_0302CE(x);
		break;
	case 10:
		sub_0302DA(x);
		break;
	case 12:
		y = sub_03030B(x, y);
		break;
	case 14:
		y = sub_030326(x, y);
		break;
	case 16:
		sub_03034C(x);
		break;
	case 18:
		sub_030367(x);
		break;
	case 20:
		sub_030379(x);
		break;
	case 22:
		y = sub_030384(x, y);
		break;
	case 24:
		y = sub_030395(x);
		break;
	case 26:
		sub_03039E(x);
		break;
	case 28:
		sub_0303C2(x);
		break;
	case 30:
		sub_030432(x, &y, &u);
		break;
	case 32:
		sub_0303E9(x, &y, &u);
		break;
	case 34:
		sub_03045F(x, &y, &u);
		break;
	case 36:
		sub_0304A4(x);
		break;
	case 38:
		u = sub_0304BB(x, u);
		break;
	case 40:
		sub_030504(x, &y, &u);
		break;
	case 42:
		y = sub_030531(x, y);
		break;
	case 44:
		sub_03054E(x);
		break;
	case 46:
		sub_0303F2(x);
		break;
	case 48:
		sub_030408(x);
		break;
	case -10:
		u = sub_03017C(x);
		break;
	case -8:
		sub_0301D9(x);
		break;
	case -6:
		sub_0301F4(x);
		break;
	case -4:
		sub_030219(x);
		break;
	case -2:
		sub_030223(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_030027(uint16_t x, uint16_t y, uint8_t d)
{
	uint32_t carry = 0;
	uint8_t b = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		y = sub_03129D(x);
		break;
	case 2:
		sub_0312AF(x);
		break;
	case 4:
		sub_0312BB(x);
		break;
	case 6:
		y = sub_0312C4(x, y);
		break;
	case 8:
		sub_0312D4(x);
		break;
	case 10:
		sub_0312E3(x);
		break;
	case 12:
		sub_03125E(x);
		break;
	case 14:
		sub_031279();
		break;
	case 16:
		sub_031283(x);
		break;
	case 18:
		sub_03128C(x);
		break;
	case -2:
		y = sub_031255(x, y);
		break;
	}
	sub_031243(x);
	carry = sub_078683(x, carry);
	return y;
}

uint16_t sub_03002A(uint16_t x, uint32_t y, uint8_t d)
{
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t ignored16 = 0, u = 0;

	b = (uint8_t)d;
	u = loaded_table_031EEC_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_031214(x, &ignored16, &u);
		break;
	case 2:
		sub_031237();
		break;
	case 4:
		sub_0311FE(x);
		break;
	case 6:
		sub_03120A(x);
		break;
	case -4:
	case -2:
		sub_0311F5(x, &ignored16, &u);
		break;
	}
	if ((mem_read8(x) & 0x20u) != 0u)
	{
		mem_write8(x, 0x80u);
		mem_write8(x + 2u, 0xFFu);
	}
	carry = sub_078683(x, carry);
	return u;
}

void sub_03002D(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_031A00_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_0302CE(x);
		break;
	case 2:
		sub_0302DA(x);
		break;
	case 4:
		y = sub_03030B(x, y);
		break;
	case 6:
		y = sub_030326(x, y);
		break;
	case 8:
		sub_03034C(x);
		break;
	case 10:
		sub_030367(x);
		break;
	case 12:
		sub_030379(x);
		break;
	case 14:
		y = sub_030384(x, y);
		break;
	case 16:
		y = sub_030395(x);
		break;
	case 18:
		sub_03039E(x);
		break;
	case 20:
		sub_0303C2(x);
		break;
	case 22:
		sub_030432(x, &y, &u);
		break;
	case 24:
		sub_0303E9(x, &y, &u);
		break;
	case 26:
		sub_03045F(x, &y, &u);
		break;
	case 28:
		sub_0304A4(x);
		break;
	case 30:
		u = sub_0304BB(x, u);
		break;
	case 32:
		sub_030504(x, &y, &u);
		break;
	case 34:
		y = sub_030531(x, y);
		break;
	case 36:
		sub_03054E(x);
		break;
	case 38:
		sub_0303F2(x);
		break;
	case 40:
		sub_030408(x);
		break;
	case -18:
		u = sub_03017C(x);
		break;
	case -16:
		sub_0301D9(x);
		break;
	case -14:
		sub_0301F4(x);
		break;
	case -12:
		sub_030219(x);
		break;
	case -10:
		sub_030223(x);
		break;
	case -8:
		sub_030247(x);
		break;
	case -6:
		sub_030250(x);
		break;
	case -4:
		sub_030295(x);
		break;
	case -2:
		sub_0302B7(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_030030(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		y = sub_030842(x);
		break;
	case 2:
		y = sub_03087F(x, y);
		break;
	case 4:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case 6:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case 8:
		sub_07865C(x, &y, &ignored16);
		break;
	case 10:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_030033(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_031BFE_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_0308F0(x);
		break;
	case 2:
		y = sub_030901(x, y);
		break;
	case 4:
		y = sub_030926(x);
		break;
	case 6:
		sub_03092F(x);
		break;
	case 8:
		sub_030939(x, &y, &u);
		break;
	case 10:
		u = sub_030942(x, u);
		break;
	case 12:
		sub_03095C(x);
		break;
	case -6:
		sub_030888(x);
		break;
	case -4:
		sub_0308A4(x);
		break;
	case -2:
		sub_0308C1(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_030036(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		y = sub_030977(x);
		break;
	case 2:
		sub_0309AA(x);
		break;
	case 4:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case 6:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case 8:
		sub_07865C(x, &y, &ignored16);
		break;
	case 10:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_030039(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_031C4F_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_030AB8(x);
		break;
	case 2:
		y = sub_030AC3(x, y);
		break;
	case 4:
		y = sub_030AD4(x);
		break;
	case 6:
		sub_03092F(x);
		break;
	case 8:
		u = sub_030AED(x);
		break;
	case 10:
		y = sub_030B1A(x, y);
		break;
	case 12:
		y = sub_030B37(x, y);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_03003C(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		y = sub_03066D(x);
		break;
	case 2:
		sub_0306A6(x);
		break;
	case 4:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case 6:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case 8:
		sub_07865C(x, &y, &ignored16);
		break;
	case 10:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_03003F(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		u = sub_0306FB(x);
		break;
	case 2:
		sub_030721(x, &y, &u);
		break;
	case 4:
		u = sub_0307D8(x);
		break;
	case 6:
		u = sub_030826(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_030042(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_031C57_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		u = sub_030AED(x);
		break;
	case 2:
		y = sub_030B1A(x, y);
		break;
	case 4:
		y = sub_030B37(x, y);
		break;
	case -8:
		sub_030AB8(x);
		break;
	case -6:
		y = sub_030AC3(x, y);
		break;
	case -4:
		y = sub_030AD4(x);
		break;
	case -2:
		sub_03092F(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_030045(uint16_t x, uint8_t d)
{
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_031C6B_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_030B58(x);
		return u;
	case 2:
		sub_030B79(x);
		return u;
	}
	unreachable();
}

void sub_030048(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t d_2 = 0, ignored16 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		y = sub_030C0A(x);
		break;
	case 2:
		sub_030C65(x);
		break;
	case 4:
		sub_0785DB(x, &y, &ignored16, p_left_caller);
		break;
	case 6:
		sub_0785DE(x, &y, &ignored16, p_left_caller);
		break;
	case 8:
		sub_07865C(x, &y, &ignored16);
		break;
	case 10:
		sub_0785E4(x, &y, &ignored16, p_left_caller);
		break;
	case 12:
		y = sub_030BC1(x, y, 0u);
		break;
	case 14:
		sub_030BE1(x);
		break;
	case -2:
		sub_030BB8(x, &y, p_left_caller);
		break;
	}
	t1 = mem_read8(x + 0x44u);
	if (t1 == 0u)
	{
		sub_078596(x, &ignored16, p_left_caller);
		sub_0785B7(x, ignored16);
	}
	else
	{
		t2 = mem_read8(x + 0x1Bu);
		if (t2 != 0u)
		{
			sub_078596(x, &ignored16, p_left_caller);
			sub_0785B7(x, ignored16);
		}
		else
		{
			t3 = mem_read8(x + 2u);
			if ((int8_t)t3 >= 0)
			{
				y = hit_box_031C6F_ADDRESS;
				sub_0785B4(x, y);
				d_2 = 0x6300u;
				carry = sub_078680(d_2);
				mem_write8(x, 0x80u);
				mem_write8(x + 2u, 0xFFu);
				mem_write8(x + 0x29u, 0u);
				sub_0785B7(x, ignored16);
			}
			else
			{
				sub_078596(x, &ignored16, p_left_caller);
				sub_0785B7(x, ignored16);
			}
		}
	}
	*p_y = y;
}

void sub_03004B(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_031D71_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_030E05(x);
		break;
	case 2:
		y = sub_030E10(x, y);
		break;
	case 4:
		y = sub_030E23(x, y);
		break;
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_03004E(uint16_t x, uint16_t y, uint8_t d)
{
	uint8_t b = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		y = sub_030E8F(x);
		break;
	case 2:
		sub_030ED9(x);
		break;
	case 4:
		sub_030F3D(x);
		break;
	case 6:
		sub_030F70(x);
		break;
	case 8:
		y = sub_030F87(x, y);
		break;
	case 10:
		sub_030F9B(x);
		break;
	case -4:
		sub_03102E(x);
		break;
	case -2:
		sub_030FB6(x);
		break;
	}
	sub_078593(x, 0u);
	return y;
}

uint16_t sub_030051(uint16_t x, uint32_t y, uint8_t d)
{
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_031D87_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		return sub_030E39(x);
	case 2:
		sub_030E5C(x);
		return u;
	}
	unreachable();
}

uint16_t sub_030060(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0;

	for (;;)
	{
		t1 = mem_read8(x + 0x28u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			sub_030069(x);
			return y;
		case 2:
			break;
		case -14:
		case -12:
			continue;
		case -10:
			return sub_030081(x);
		case -8:
			sub_0300B0(x);
			return y;
		case -6:
			sub_0300CF(x);
			return y;
		case -4:
			sub_0300F0(x);
			return y;
		case -2:
			sub_03010C(x);
			return y;
		}
		break;
	}
	sub_030077(x);
	return y;
}

void sub_030069(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x30u);
	mem_write8(x + 5u, (t1 + 2u) | 0x80u);
	t2 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t2 + 1u);
}

void sub_030077(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
		mem_write8(x, 0u);
}

uint16_t sub_030081(uint16_t x)
{
	uint8_t d = 0;
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t4 = 0;
	uint16_t t2 = 0, t3 = 0;

	u = object_setup_031982_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 4u);
	t1 = mem_read8(x + 0x30u);
	u = loaded_table_031988_ADDRESS + (int8_t)(((uint32_t)t1 << 1) << 1);
	t2 = DATA16(u);
	mem_write8(x + VIDEO_003C, t2 >> 8);
	mem_write8(x + 0x3Bu, t2);
	t3 = mem_read16(u + 2u);
	d = (uint8_t)t3;
	mem_write8(x + 0x3Eu, t3 >> 8);
	mem_write8(x + 0x30u, d);
	mem_write8(x + 5u, d);
	t4 = mem_read8(x + 2u);
	mem_write8(x + 2u, t4 + 1u);
	return y;
}

void sub_0300B0(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + VIDEO_003C);
	mem_write8(x + VIDEO_003C, t1 - 1u);
	if (t1 != 1u)
		return;
	u = sub_078620(x);
	sub_078626(x, u);
	mem_write8(x, 0x80u);
	t2 = mem_read8(x + 5u);
	mem_write8(x + 5u, t2 | 0x80u);
	t3 = mem_read8(x + 2u);
	mem_write8(x + 2u, t3 + 1u);
	sub_0785C9(x);
}

void sub_0300CF(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
		return;
	mem_write8(x, 0xC0u);
	t2 = mem_read8(x + 0x3Eu);
	d = (uint32_t)t2 << 8;
	sub_07866B(x, 0u, d);
	t3 = mem_read8(x + 0x30u);
	mem_write8(x + 5u, (t3 + 1u) | 0x80u);
	t4 = mem_read8(x + 2u);
	mem_write8(x + 2u, t4 + 1u);
	sub_0785C6(x);
}

void sub_0300F0(uint16_t x)
{
	uint8_t a = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
		t2 = mem_read8(x + 0x30u);
		a = (t2 + 2u) | 0x80u;
		mem_write8(x + 5u, a);
		mem_write8(x, a);
		t3 = mem_read8(x + 2u);
		mem_write8(x + 2u, t3 + 1u);
	}
}

void sub_03010C(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
		mem_write8(x, 0u);
}

uint16_t sub_030122(uint16_t x)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t4 = 0, t6 = 0;
	uint16_t t3 = 0, t5 = 0;

	u = object_setup_0319D4_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x + 0x43u, 1u);
	t1 = mem_read8(x + 0x30u);
	if ((int8_t)t1 < 0)
	{
		mem_write16(x + 0x2Au, enemy_behaviour_0318C0_ADDRESS);
		u = sub_078620(x);
		sub_078626(x, u);
		mem_write8(x + 0x30u, 0u);
		mem_write8(x + 2u, 2u);
		return y;
	}
	mem_write8(x, 4u);
	t2 = mem_read8(x + 0x30u);
	u = object_18_behaviours_ADDRESS + (int8_t)(((uint32_t)t2 << 1) << 1);
	t3 = DATA16(u);
	mem_write8(x + 0x30u, t3 >> 8);
	t4 = mem_read8(x + 9u);
	unk_48F0 = t4 & 0x30u;
	mem_write8(x + 9u, t3 | unk_48F0);
	t5 = mem_read16(u + 2u);
	mem_write16(x + 0x2Au, t5);
	t6 = mem_read8(x + 2u);
	mem_write8(x + 2u, t6 + 1u);
	return y;
}

uint16_t sub_030173(uint16_t x, uint16_t y)
{
	uint16_t ignored16 = 0, y_2 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x28u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_03017C(x);
		return y;
	case 2:
		sub_0301D9(x);
		return y;
	case 4:
		sub_0301F4(x);
		return y;
	case 6:
		sub_030219(x);
		return y;
	case 8:
		sub_030223(x);
		return y;
	case 10:
		sub_030247(x);
		return y;
	case 12:
		sub_030250(x);
		return y;
	case 14:
		sub_030295(x);
		return y;
	case 16:
		sub_0302B7(x);
		return y;
	case 18:
		sub_0302CE(x);
		return y;
	case 20:
		sub_0302DA(x);
		return y;
	case 22:
		return sub_03030B(x, y);
	case 24:
		return sub_030326(x, y);
	case 26:
		sub_03034C(x);
		return y;
	case 28:
		sub_030367(x);
		return y;
	case 30:
		sub_030379(x);
		return y;
	case 32:
		return sub_030384(x, y);
	case 34:
		return sub_030395(x);
	case 36:
		sub_03039E(x);
		return y;
	case 38:
		sub_0303C2(x);
		return y;
	case 40:
		sub_030432(x, &y, &ignored16);
		return y;
	case 42:
		sub_0303E9(x, &y, &ignored16);
		return y;
	case 44:
		sub_03045F(x, &y_2, &ignored16);
		return y_2;
	case 46:
		sub_0304A4(x);
		return y;
	case 48:
		sub_0304BB(x, 0u);
		return y;
	case 50:
		sub_030504(x, &y, &ignored16);
		return y;
	case 52:
		return sub_030531(x, y);
	case 54:
		sub_03054E(x);
		return y;
	case 56:
		sub_0303F2(x);
		return y;
	case 58:
		sub_030408(x);
		return y;
	}
	unreachable();
}

uint16_t sub_03017C(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d = 0, u = 0;
	uint8_t t1 = 0, t2 = 0, t5 = 0;
	uint16_t t3 = 0, t4 = 0;

	t1 = mem_read8(x + 0x30u);
	if ((t1 & 3u) == 3u)
		mem_write8(x + 0x1Bu, 8u);
	u = sub_078620(x);
	sub_078626(x, u);
	t2 = mem_read8(x + 0x30u);
	a = t2;
	if ((int8_t)t2 < 0)
	{
		mem_write8(x, 0x80u);
		mem_write8(x + 4u, 0x97u);
		mem_write8(x + 5u, 0x90u);
		mem_write16(x + 0xFu, 0x100u);
		t3 = mem_read16(x + 0xCu);
		if (t3 >= 0xE0u)
		{
			t4 = mem_read16(x + 0xFu);
			mem_write16(x + 0xFu, 0u - t4);
		}
		mem_write8(x + 0x3Bu, 0x80u);
		mem_write8(x + 0x28u, 4u);
		return u;
	}
	mem_write8(x + 0x30u, a & 0x7Fu);
	mem_write8(x, 0x80u);
	mem_write8(x + 5u, 0x92u);
	t5 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t5 + 1u);
	d = 0x7B00u;
	carry = sub_078680(d);
	return u;
}

void unused_0301D8(void)
{
}

void sub_0301D9(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
		return;
	mem_write8(x, 0xC0u);
	t2 = mem_read8(x + 0x30u);
	if (t2 >= 2u)
	{
		mem_write8(x + 0x3Au, 0x10u);
		mem_write8(x + 0x30u, 0u);
		t3 = mem_read8(x + 2u);
		mem_write8(x + 2u, t3 + 1u);
		return;
	}
	mem_write8(x + 5u, 0x87u);
	t4 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t4 + 1u);
}

void sub_0301F4(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
		return;
	t2 = mem_read8(x + 0x30u);
	if (t2 == 0u)
	{
		mem_write8(x, 0x80u);
		mem_write8(x + 5u, 0x93u);
		t3 = mem_read8(x + 0x28u);
		mem_write8(x + 0x28u, t3 + 1u);
		return;
	}
	mem_write8(x + 0x3Au, 0x10u);
	mem_write8(x + 0x30u, 0u);
	t4 = mem_read8(x + 2u);
	mem_write8(x + 2u, t4 + 1u);
}

void sub_030219(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
		mem_write8(x, 0u);
}

void sub_030223(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write16(x + 0xFu, 0u);
	mem_write8(x + 4u, 0x91u);
	mem_write8(x + 5u, 0x92u);
	mem_write8(x + 0x28u, 1u);
	d = 0x7B00u;
	carry = sub_078680(d);
}

void sub_030247(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 5u, 0x93u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

void sub_030250(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint8_t t1 = 0, t3 = 0, t5 = 0, t6 = 0;
	uint16_t t2 = 0, t4 = 0, t7 = 0;

	t1 = mem_read8(x + 6u);
	a = t1;
	if ((a & 2u) != 0u)
		mem_write8(x, 0x80u);
	carry = (a >> 0) & 1u;
	if (carry == 0u)
		return;
	t2 = mem_read16(x + 0x2Cu);
	if (t2 < 0x40u)
	{
		mem_write8(x + 0x3Bu, 0x20u);
		mem_write16(x + 0x14u, 0x80u);
		t3 = mem_read8(x + 0x36u);
		if ((int8_t)t3 < 0)
		{
			t4 = mem_read16(x + 0x14u);
			mem_write16(x + 0x14u, 0u - t4);
		}
		t5 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t5 + 1u);
		return;
	}
	mem_write16(x + 0xFu, 0x180u);
	t6 = mem_read8(x + 0x36u);
	if ((int8_t)(t6 - 0x40u) >= 0)
	{
		t7 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t7);
	}
	mem_write8(x + 0x3Bu, 0x50u);
	t5 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t5 + 1u);
}

void sub_030295(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(x, 0x80u);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write8(x + 5u, 0x92u);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	d = 0x7B00u;
	carry = sub_078680(d);
	sub_0785C9(x);
}

void sub_0302B7(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	a = t1;
	if ((a & 2u) != 0u)
		mem_write8(x, 0xC0u);
	carry = (a >> 0) & 1u;
	if (carry)
	{
		mem_write8(x + 2u, 2u);
		mem_write8(x + 0x3Bu, 0u);
		return;
	}
}

void sub_0302CE(uint16_t x)
{
	uint8_t t1 = 0;

	sub_07859C(x);
	mem_write8(x + 5u, 0x91u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

void sub_0302DA(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t4 = 0;
	uint16_t t3 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) == 0u)
		return;
	d = 0x301u;
	carry = sub_078680(d);
	mem_write16(x + 0xFu, 0x100u);
	mem_write16(x + 0x19u, 0x400u);
	t2 = mem_read8(x + 0x36u);
	if ((int8_t)(t2 - 0x40u) >= 0)
	{
		t3 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t3);
	}
	mem_write8(x, 0xC8u);
	mem_write8(x + 6u, 0x80u);
	t4 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t4 + 1u);
}

uint16_t sub_03030B(uint16_t x, uint16_t y)
{
	uint16_t y_2 = 0;
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = mem_read16(x + 0x19u);
	if ((int16_t)t1 >= 0)
	{
		t2 = mem_read16(x + 0x19u);
		mem_write16(x + 0x19u, t2 - 0x10u);
		return sub_03032F(x, y);
	}
	y_2 = hit_box_0318A0_ADDRESS;
	sub_0785B4(x, y_2);
	t3 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t3 + 1u);
	return sub_030326(x, y_2);
}

uint16_t sub_030326(uint16_t x, uint16_t y)
{
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x19u);
	mem_write16(x + 0x19u, t1 - 0x40u);
	return sub_03032F(x, y);
}

uint16_t sub_03032F(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	carry = sub_078662(x);
	if (carry == 0u)
		return y;
	y = hit_box_031890_ADDRESS;
	sub_0785B4(x, y);
	mem_write16(x + 0xFu, 0u);
	d = VIDEO_2000;
	carry = sub_078680(d);
	mem_write8(x + 0x3Bu, 0x20u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	return y;
}

void sub_03034C(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	mem_write8(x + 5u, 0x90u);
	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 0x3Bu, 0x20u);
		t2 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t2 + 1u);
		t3 = mem_read8(x + 9u);
		mem_write8(x + 9u, t3 ^ 0x40u);
	}
}

void sub_030367(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 5u, 0x90u);
	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 2u, 2u);
		mem_write8(x + 0x3Bu, 0u);
		return;
	}
}

void sub_030379(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 5u, 0x90u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	sub_07859C(x);
}

uint16_t sub_030384(uint16_t x, uint16_t y)
{
	uint16_t y_2 = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) == 0u)
		return y;
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	y_2 = hit_box_031898_ADDRESS;
	sub_0785B4(x, y_2);
	return y_2;
}

uint16_t sub_030395(uint16_t x)
{
	uint16_t y = 0;
	uint8_t t1 = 0;

	y = hit_box_031890_ADDRESS;
	sub_0785B4(x, y);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	sub_03039E(x);
	return y;
}

void sub_03039E(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0, t4 = 0;
	uint16_t t3 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
		return;
	mem_write8(x + 5u, 0x81u);
	mem_write16(x + 0xFu, 0xFF00u);
	t2 = mem_read8(x + 9u);
	if ((t2 & 0x40u) != 0u)
	{
		t3 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t3);
	}
	mem_write8(x + 0x3Bu, 0x20u);
	t4 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t4 + 1u);
}

void sub_0303C2(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write16(x + 0xFu, 0u);
	mem_write8(x + 2u, 2u);
	mem_write8(x + 0x3Bu, 0u);
}

void unused_0303CE(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		mem_write8(x + 0x3Bu, 1u);
		mem_write8(x + 2u, 1u);
	}
}

void sub_0303E9(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_031A26_ADDRESS;
		t1 = mem_read8(x + 0x29u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			sub_0303F2(x);
			break;
		case 2:
			sub_030408(x);
			break;
		case -56:
			u = sub_03017C(x);
			break;
		case -54:
			sub_0301D9(x);
			break;
		case -52:
			sub_0301F4(x);
			break;
		case -50:
			sub_030219(x);
			break;
		case -48:
			sub_030223(x);
			break;
		case -46:
			sub_030247(x);
			break;
		case -44:
			sub_030250(x);
			break;
		case -42:
			sub_030295(x);
			break;
		case -40:
			sub_0302B7(x);
			break;
		case -38:
			sub_0302CE(x);
			break;
		case -36:
			sub_0302DA(x);
			break;
		case -34:
			y = sub_03030B(x, y);
			break;
		case -32:
			y = sub_030326(x, y);
			break;
		case -30:
			sub_03034C(x);
			break;
		case -28:
			sub_030367(x);
			break;
		case -26:
			sub_030379(x);
			break;
		case -24:
			y = sub_030384(x, y);
			break;
		case -22:
			y = sub_030395(x);
			break;
		case -20:
			sub_03039E(x);
			break;
		case -18:
			sub_0303C2(x);
			break;
		case -16:
			sub_030432(x, &y, &u);
			break;
		case -14:
			continue;
		case -12:
			sub_03045F(x, &y, &u);
			break;
		case -10:
			sub_0304A4(x);
			break;
		case -8:
			u = sub_0304BB(x, u);
			break;
		case -6:
			sub_030504(x, &y, &u);
			break;
		case -4:
			y = sub_030531(x, y);
			break;
		case -2:
			sub_03054E(x);
			break;
		}
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_0303F2(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	mem_write16(x + 0x19u, 0u);
	mem_write8(x, 0x88u);
	mem_write8(x + 0x3Bu, 8u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	d = 0x6300u;
	carry = sub_078680(d);
}

void sub_030408(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
	{
		t2 = mem_read8(x + 9u);
		mem_write8(x + 9u, t2 ^ 0x80u);
		mem_write8(x + 6u, 0x80u);
		return;
	}
	mem_write8(x + 2u, 0xFEu);
	mem_write8(x + 0x3Bu, 1u);
	t3 = mem_read8(x + 9u);
	mem_write8(x + 9u, t3 & 0x7Fu);
	mem_write8(x + 6u, 0x80u);
}

void sub_030432(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, u_2 = 0, y_2 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry == 0u)
		return;
	mem_write8(x + 0x57u, 0u);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x19u, 0u);
	mem_write8(x + 0x5Bu, 0u);
	mem_write8(x + 0x42u, 0u);
	u_2 = sub_078620(x);
	d = 0x6C00u;
	carry = sub_078680(d);
	sub_078626(x, u_2);
	sub_0785F0(x);
	sub_0785F3(x, &y_2, &u_2);
	mem_write8(x + 0x1Bu, 1u);
	*p_y = y_2;
	*p_u = u_2;
}

void sub_03045F(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t7 = 0;
	uint16_t t3 = 0, t4 = 0, t5 = 0, t6 = 0;

	u = object_setup_031A2A_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 0xC8u);
	mem_write8(x + 0x20u, 0x10u);
	mem_write8(x + 0x5Bu, 1u);
	mem_write16(x + 0x5Cu, 0u);
	mem_write8(x + 0x57u, 1u);
	t1 = mem_read8(x + 0x42u);
	mem_write8(x + 0x42u, t1 - 1u);
	t2 = mem_read8(x + 0x30u);
	u = loaded_table_031A30_ADDRESS + (int8_t)(((uint32_t)t2 << 1) << 1);
	t3 = DATA16(u);
	mem_write16(x + 0x3Eu, t3);
	t4 = mem_read16(u + 2u);
	mem_write8(x + 0x3Du, t4 >> 8);
	mem_write8(x + 0x30u, t4);
	t5 = mem_read16(x + 0xCu);
	t6 = t5 + unk_48AC;
	mem_write16(x + 0x2Au, t6);
	t7 = mem_read8(x + 2u);
	mem_write8(x + 2u, t7 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_0304A4(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;
	uint16_t t3 = 0;

	t1 = mem_read8(x + 0x30u);
	if (t1 == 0u)
	{
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
		return;
	}
	t3 = mem_read16(x + 0xCu);
	if (t3 < 0x100u)
		mem_write8(x + 2u, 0xFEu);
}

uint16_t sub_0304BB(uint16_t x, uint16_t u)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t6 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	if ((((uint16_t)((uint32_t)(uint8_t)unk_4815 << 8) >> 8) & 3u) != 0u)
		return u;
	u = sub_078620(x);
	sub_078626(x, u);
	t1 = mem_read16(x + 0x2Cu);
	if (t1 < 0x40u)
	{
		t2 = mem_read16(x + 0x2Eu);
		if (t2 < 0x40u)
		{
			mem_write8(x + 6u, 0x80u);
			mem_write8(x, 0xC8u);
			t3 = mem_read16(x + 0x2Au);
			t4 = mem_read16(x + 0x3Eu);
			mem_write16(x + 0xCu, t3 - unk_48AC + t4);
			t5 = mem_read16(x + 0x3Eu);
			mem_write16(x + 0x3Eu, 0u - t5);
			mem_write16(x + 0x19u, 0xFE00u);
			d = 0x5000u;
			carry = sub_078680(d);
			t6 = mem_read8(x + 2u);
			mem_write8(x + 2u, t6 + 1u);
			sub_0785C9(x);
			return u;
		}
	}
	return u;
}

void sub_030504(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t u_2 = 0, y_2 = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x16u);
	if (t1 >= 0x10u)
		return;
	mem_write8(x + 0x3Bu, (unk_4858 & 0x1Fu) + 8u);
	mem_write16(x + 0x19u, 0u);
	mem_write8(x + 5u, 0x80u);
	y_2 = hit_box_0318B0_ADDRESS;
	sub_0785B4(x, y_2);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	u_2 = sub_078620(x);
	sub_078626(x, u_2);
	sub_0785C9(x);
	*p_y = y_2;
	*p_u = u_2;
}

uint16_t sub_030531(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return y;
	y = hit_box_0318A8_ADDRESS;
	sub_0785B4(x, y);
	mem_write8(x + 5u, 0x81u);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x19u, 0x200u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	return y;
}

void sub_03054E(uint16_t x)
{
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x16u);
	if (t1 >= 0x80u)
	{
		mem_write16(x + 0x19u, 0u);
		mem_write8(x + 2u, 2u);
	}
}

void sub_030565(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0, t3 = 0, t4 = 0;

	u = object_setup_031A72_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 4u);
	t1 = io_read16(VIDEO_1854);
	mem_write16(x + 0x40u, t1);
	t2 = mem_read8(x + 0x30u);
	u = loaded_table_031A56_ADDRESS + (int8_t)(((uint32_t)t2 << 1) << 1);
	t3 = DATA16(u);
	mem_write8(x + 0x3Bu, t3 >> 8);
	mem_write8(x + 9u, t3);
	t4 = mem_read16(u + 2u);
	mem_write8(x + 2u, t4 >> 8);
	*p_y = y;
	*p_u = u;
}

void sub_030590(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(x, 0x80u);
	mem_write8(x + 5u, 0x92u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	d = 0x7B00u;
	carry = sub_078680(d);
}

void sub_0305A9(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		mem_write8(x + 5u, 0x87u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

uint16_t sub_0305B8(uint16_t x, uint16_t u)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
		return u;
	t2 = mem_read16(x + 0x40u);
	u = t2;
	d = sub_07861D(x, u);
	a = (uint8_t)(d >> 8);
	mem_write8(x + 0x3Eu, a);
	mem_write8(x + 0x3Bu, 0x40u);
	t3 = mem_read8(x + 2u);
	mem_write8(x + 2u, t3 + 1u);
	return u;
}

void sub_0305D0(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 0x3Bu, 0x80u);
		mem_write8(x + 5u, 0x94u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_0305E3(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		mem_write8(x + 5u, 0x99u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_0305F2(uint16_t x)
{
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	t2 = mem_read8(x + 0x3Eu);
	d = ((uint32_t)t2 << 8) | 0xCu;
	sub_078617(x, d);
	mem_write8(x + 5u, 0x9Au);
	mem_write8(x + 0x3Bu, 0x80u);
	t3 = mem_read8(x + 2u);
	mem_write8(x + 2u, t3 + 1u);
}

void sub_03060D(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(x + 0x14u, 0u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_030619(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_030622(uint16_t x)
{
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0xFu);
	mem_write16(x + 0xFu, t1 - 1u);
}

void sub_03062C(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		mem_write8(x + 5u, 0x87u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_03063B(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		mem_write8(x + 5u, 0x94u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_03064A(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(x + 0xFu, 0x80u);
		mem_write8(x + 5u, 0x9Au);
		mem_write8(x + 2u, 9u);
	}
}

uint16_t sub_03066D(uint16_t x)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0;

	u = object_setup_031AEC_ADDRESS;
	y = sub_0785AB(x, u);
	u = sub_078620(x);
	sub_078626(x, u);
	mem_write16(x + 0x4Cu, 0x5100u);
	mem_write8(x + 0x43u, 1u);
	mem_write16(x + 0x2Au, enemy_behaviour_031A88_ADDRESS);
	mem_write8(x + 0x3Au, 0x10u);
	t1 = mem_read8(x + 0x30u);
	if (t1 == 0u)
	{
		mem_write8(x + 0x30u, 0u);
		mem_write8(x + 2u, 2u);
		return y;
	}
	mem_write8(x, 4u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	return y;
}

void sub_0306A6(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_0306AF(x);
		return;
	case 2:
		sub_0306CF(x);
		return;
	case 4:
		sub_0306E3(x);
		return;
	}
}

void sub_0306AF(uint16_t x)
{
	uint8_t t1 = 0, t4 = 0;
	uint16_t t2 = 0, t3 = 0;

	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 0x30u);
	t2 = DATA16(indexed_table_031AF8_ADDRESS + (int8_t)((uint32_t)t1 << 1));
	mem_write8(x + 0x3Bu, t2 >> 8);
	t3 = (t2 & 0xFFu) << 4;
	mem_write16(x + 0xCu, t3);
	mem_write8(x + 5u, 0x90u);
	t4 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t4 + 1u);
}

void sub_0306CF(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(x + 5u, 0x91u);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	d = unk_4800_ADDRESS;
	carry = sub_078680(d);
}

void sub_0306E3(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		mem_write8(x, 0xC0u);
		mem_write8(x + 0x30u, 0u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

uint16_t sub_0306FB(uint16_t x)
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

void sub_030721(uint16_t x, uint16_t *p_y, uint16_t *p_u)
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
			t5 = mem_read8(u + 0x3Du);
			if (t5 != 0u)
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
									y = indexed_table_031B0A_ADDRESS;
									t18 = mem_read8(u + 0x5Bu);
									mem_write8(x + 5u, DATA8(indexed_table_031B0A_ADDRESS + ((((t18 >> 1) >> 1) >> 1) >> 1)) | 0x80u);
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

uint16_t sub_0307D8(uint16_t x)
{
	uint8_t a = 0;
	uint16_t u = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;
	uint16_t t1 = 0;

	mem_write8(x + 0x1Du, 0u);
	t1 = mem_read16(x + 0x38u);
	u = t1;
	t2 = mem_read8(u + 0x3Du);
	if (t2 == 0u)
	{
		t3 = mem_read8(x + 0x1Bu);
		a = t3 - 3u;
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
	t4 = mem_read8(u + 0x1Bu);
	if (t4 == 0u)
	{
		mem_write8(x + 0x1Du, 0u);
		mem_write8(x + 2u, 2u);
		mem_write8(x + 0x3Bu, 0u);
		return u;
	}
	t5 = mem_read8(x + 0x58u);
	if (t5 == 2u)
	{
		t6 = mem_read8(x + 0x58u);
		mem_write8(x + 0x58u, t6 + 1u);
		mem_write8(x + 0x29u, 3u);
	}
	return u;
}

uint16_t sub_030826(uint16_t x)
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
	return sub_0307D8(x);
}

uint16_t sub_030842(uint16_t x)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	u = object_setup_031BF2_ADDRESS;
	y = sub_0785AB(x, u);
	u = sub_078620(x);
	sub_078626(x, u);
	mem_write8(x + 0x43u, 1u);
	mem_write16(x + 0x2Au, enemy_behaviour_031B36_ADDRESS);
	mem_write8(x + 0x3Au, 0x10u);
	t1 = mem_read8(x + 0x30u);
	if (t1 == 0u)
	{
		mem_write8(x + 0x30u, 0u);
		mem_write8(x + 2u, 2u);
		return y;
	}
	mem_write8(x, 0x80u);
	t2 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t2 & 0xCFu) | 0x20u);
	t3 = mem_read8(x + 2u);
	mem_write8(x + 2u, t3 + 1u);
	return y;
}

uint16_t sub_03087F(uint16_t x, uint16_t y)
{
	uint16_t ignored16 = 0, y_2 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_030888(x);
		return y;
	case 2:
		sub_0308A4(x);
		return y;
	case 4:
		sub_0308C1(x);
		return y;
	case 6:
		sub_0308F0(x);
		return y;
	case 8:
		return sub_030901(x, y);
	case 10:
		return sub_030926(x);
	case 12:
		sub_03092F(x);
		return y;
	case 14:
		sub_030939(x, &y_2, &ignored16);
		return y_2;
	case 16:
		sub_030942(x, 0u);
		return y;
	case 18:
		sub_03095C(x);
		return y;
	}
	unreachable();
}

void sub_030888(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;
	uint16_t t3 = 0;

	mem_write16(x + 0xFu, 0x100u);
	mem_write8(x + 0x3Bu, 0x60u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	sub_07859C(x);
	t2 = mem_read8(x + 9u);
	if ((t2 & 0x40u) != 0u)
	{
		t3 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t3);
	}
}

void sub_0308A4(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0xFF80u);
		mem_write16(x + 0x19u, 0x400u);
		mem_write8(x + 0x3Bu, 0x10u);
		t2 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t2 + 1u);
	}
}

void sub_0308C1(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t3 = 0, t4 = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = mem_read16(x + 0x19u);
	t2 = t1 - 0x30u;
	mem_write16(x + 0x19u, t2);
	carry = sub_078662(x);
	if (carry == 0u)
	{
		t3 = mem_read8(x + 0x3Bu);
		mem_write8(x + 0x3Bu, t3 - 1u);
		if (t3 == 1u)
		{
			t4 = mem_read8(x + 9u);
			mem_write8(x + 9u, (t4 & 0xCFu) | 0x10u);
		}
		return;
	}
	mem_write8(x + 0x30u, 0u);
	mem_write8(x, 0xC0u);
	mem_write8(x + 2u, 2u);
	mem_write8(x + 0x3Bu, 0u);
}

void sub_0308F0(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	mem_write8(x + 5u, 0x90u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	d = 0x6A00u;
	carry = sub_078680(d);
	sub_07859C(x);
}

uint16_t sub_030901(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) == 0u)
		return y;
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	d = 0x6A00u;
	carry = sub_078680(d);
	y = hit_box_031B16_ADDRESS;
	sub_0785B4(x, y);
	t3 = mem_read8(x + 0x3Du);
	mem_write8(x + 0x3Du, t3 - 1u);
	t4 = mem_read8(x + 0x3Du);
	carry = (t4 >> 0) & 1u;
	if (carry)
		mem_write8(x + 0x29u, 4u);
	return y;
}

uint16_t sub_030926(uint16_t x)
{
	uint16_t y = 0;
	uint8_t t1 = 0;

	y = hit_box_031B0E_ADDRESS;
	sub_0785B4(x, y);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	sub_03092F(x);
	return y;
}

void sub_03092F(uint16_t x)
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

void sub_030939(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t y = 0;
	uint8_t t1 = 0;

	y = hit_box_031B0E_ADDRESS;
	sub_0785B4(x, y);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	u = sub_030942(x, u);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_030942(uint16_t x, uint16_t u)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		mem_write8(x + 5u, 0x86u);
		u = indexed_table_031C0C_ADDRESS;
		mem_write8(x + VIDEO_003C, DATA8(indexed_table_031C0C_ADDRESS + (int8_t)unk_4857));
		t2 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t2 + 1u);
	}
	return u;
}

void sub_03095C(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		t2 = mem_read8(x + VIDEO_003C);
		mem_write8(x + VIDEO_003C, t2 - 1u);
		if (t2 == 1u)
		{
			mem_write8(x + 2u, 2u);
			mem_write8(x + 0x3Bu, 0u);
			return;
		}
	}
}

uint16_t sub_030977(uint16_t x)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0;

	u = object_setup_031C1D_ADDRESS;
	y = sub_0785AB(x, u);
	u = sub_078620(x);
	sub_078626(x, u);
	mem_write8(x + 0x43u, 1u);
	mem_write16(x + 0x2Au, enemy_behaviour_031B8E_ADDRESS);
	mem_write8(x + 0x3Au, 0x10u);
	t1 = mem_read8(x + 0x30u);
	if (t1 == 0u)
	{
		mem_write8(x + 0x30u, 0u);
		mem_write8(x + 2u, 2u);
		return y;
	}
	mem_write8(x + 0x42u, 0xFFu);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	return y;
}

void sub_0309AA(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_0309B3(x);
		return;
	case 2:
		sub_0309E6(x);
		return;
	case 4:
		sub_0309FC(x);
		return;
	case 6:
	case 14:
	case 22:
		sub_030A10(x);
		return;
	case 8:
		sub_030A3F(x);
		return;
	case 10:
	case 18:
		sub_030A63(x);
		return;
	case 12:
	case 20:
		sub_030A74(x);
		return;
	case 16:
		sub_030A8E(x);
		return;
	}
}

void sub_0309B3(uint16_t x)
{
	uint8_t a = 0;
	uint16_t u = 0;
	uint8_t t1 = 0, t4 = 0, t5 = 0;
	uint16_t t2 = 0, t3 = 0;

	mem_write8(x, 0x80u);
	mem_write8(x + 0x57u, 0x80u);
	t1 = mem_read8(x + 0x30u);
	u = loaded_table_031C3B_ADDRESS + (int8_t)(((uint32_t)t1 << 1) << 1);
	t2 = DATA16(u);
	mem_write8(x + 9u, t2 >> 8);
	t3 = (uint32_t)(uint8_t)t2 << 4;
	mem_write16(x + 0x3Eu, t3);
	t4 = mem_read8(u + 2u);
	a = t4;
	if ((int8_t)t4 < 0)
	{
		a &= 0x7Fu;
		mem_write8(x, 4u);
	}
	mem_write8(x + 0x29u, a);
	t5 = mem_read8(u + 3u);
	mem_write8(x + 5u, t5);
}

void sub_0309E6(uint16_t x)
{
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = mem_read16(x + 0xCu);
	t2 = mem_read16(x + 0x3Eu);
	if (t1 < t2)
	{
		mem_write8(x + 5u, 0x93u);
		mem_write8(x + 0x3Bu, 0x10u);
		t3 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t3 + 1u);
	}
}

void sub_0309FC(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(x + 0x14u, 0xFF00u);
		mem_write8(x + 0x3Bu, 4u);
		t2 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t2 + 1u);
	}
}

void sub_030A10(uint16_t x)
{
	uint32_t negative = 0;
	uint8_t a = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	d = 0u;
	sub_078638(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	t1 = mem_read8(x + 0x5Du);
	if ((uint8_t)((((a & 0xFu) << 1) << 1) << 1) == t1)
	{
		mem_write8(x + 0x30u, 0u);
		mem_write8(x, 0xC0u);
		mem_write8(x + 0x57u, 0u);
		mem_write8(x + 0x42u, 0u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
	t3 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t3 - 1u);
	if (t3 == 1u)
	{
		t4 = mem_read8(x + 9u);
		mem_write8(x + 9u, (t4 & 0xCFu) | 0x10u);
	}
}

void sub_030A3F(uint16_t x)
{
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = mem_read16(x + 0xCu);
	t2 = mem_read16(x + 0x3Eu);
	if (t2 <= t1)
		return;
	mem_write8(x, 0x80u);
	mem_write8(x + 5u, 0x81u);
	mem_write16(x + 0xFu, 0x100u);
	mem_write8(x + 0x3Bu, 0x40u);
	t3 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t3 + 1u);
	sub_0785C6(x);
}

void sub_030A63(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(x + 0xFu, 0u);
		mem_write8(x + 5u, 0x86u);
		t2 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t2 + 1u);
	}
}

void sub_030A74(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		mem_write8(x + 5u, 0x81u);
		mem_write16(x + 0x14u, 0xFF00u);
		mem_write8(x + 0x3Bu, 4u);
		t2 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t2 + 1u);
	}
}

void sub_030A8E(uint16_t x)
{
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = mem_read16(x + 0xCu);
	t2 = mem_read16(x + 0x3Eu);
	if (t2 <= t1)
		return;
	mem_write8(x, 0x80u);
	mem_write8(x + 5u, 0x81u);
	mem_write16(x + 0xFu, 0xFF00u);
	mem_write8(x + 0x3Bu, 0x40u);
	t3 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t3 + 1u);
	sub_0785C6(x);
}

void sub_030AB8(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 5u, 0x90u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	sub_07859C(x);
}

uint16_t sub_030AC3(uint16_t x, uint16_t y)
{
	uint16_t y_2 = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) == 0u)
		return y;
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	y_2 = hit_box_031B26_ADDRESS;
	sub_0785B4(x, y_2);
	return y_2;
}

uint16_t sub_030AD4(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t y = 0;
	uint8_t t1 = 0, t2 = 0;

	y = hit_box_031B1E_ADDRESS;
	sub_0785B4(x, y);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	t2 = mem_read8(x + 6u);
	carry = (t2 >> 0) & 1u;
	if (carry == 0u)
		return y;
	mem_write8(x + 2u, 2u);
	mem_write8(x + 0x3Bu, 0u);
	return y;
}

uint16_t sub_030AED(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t2 = 0, t4 = 0;
	uint16_t t1 = 0, t3 = 0;

	mem_write8(x + 5u, 0x91u);
	mem_write8(x + 0x3Bu, 8u);
	mem_write16(x + 0xFu, 0x200u);
	u = indexed_table_031C5D_ADDRESS;
	t1 = DATA16(indexed_table_031C5D_ADDRESS + (int8_t)((uint32_t)unk_486B << 1));
	mem_write16(x + 0x19u, t1);
	sub_07859C(x);
	t2 = mem_read8(x + 9u);
	if ((t2 & 0x40u) != 0u)
	{
		t3 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t3);
	}
	t4 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t4 + 1u);
	return u;
}

uint16_t sub_030B1A(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t y_2 = 0;
	uint8_t t2 = 0, t3 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x19u);
	mem_write16(x + 0x19u, t1 - 0x30u);
	carry = sub_078662(x);
	if (carry)
		return sub_030B45(x);
	t2 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t2 - 1u);
	if (t2 != 1u)
		return y;
	t3 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t3 + 1u);
	y_2 = hit_box_031B2E_ADDRESS;
	sub_0785B4(x, y_2);
	return y_2;
}

uint16_t sub_030B37(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x19u);
	mem_write16(x + 0x19u, t1 - 0x30u);
	carry = sub_078662(x);
	if (carry == 0u)
		return y;
	return sub_030B45(x);
}

uint16_t sub_030B45(uint16_t x)
{
	uint16_t y = 0;

	mem_write16(x + 0xFu, 0u);
	y = hit_box_031B1E_ADDRESS;
	sub_0785B4(x, y);
	mem_write8(x + 2u, 2u);
	mem_write8(x + 0x3Bu, 0u);
	return y;
}

void sub_030B58(uint16_t x)
{
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	mem_write8(x + 5u, 0x81u);
	mem_write8(x + 0x3Bu, 0x20u);
	mem_write16(x + 0xFu, 0xFE80u);
	sub_07859C(x);
	t1 = mem_read8(x + 9u);
	if ((t1 & 0x40u) != 0u)
	{
		t2 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t2);
	}
	t3 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t3 + 1u);
}

void sub_030B79(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(x + 2u, 2u);
	mem_write8(x + 0x3Bu, 0u);
}

void sub_030BB8(uint16_t x, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t ignored16 = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		t1 = mem_read8(x + 0x29u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			y = sub_030BC1(x, y, 0u);
			break;
		case 2:
			sub_030BE1(x);
			break;
		case -14:
			continue;
		case -12:
			y = sub_030C0A(x);
			break;
		case -10:
			sub_030C65(x);
			break;
		case -8:
			sub_0785DB(x, &y, &ignored16, p_left_caller);
			break;
		case -6:
			sub_0785DE(x, &y, &ignored16, p_left_caller);
			break;
		case -4:
			sub_07865C(x, &y, &ignored16);
			break;
		case -2:
			sub_0785E4(x, &y, &ignored16, p_left_caller);
			break;
		}
		break;
	}
	*p_y = y;
}

uint16_t sub_030BC1(uint16_t x, uint16_t y, uint32_t u)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, y_2 = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	sub_0785B1(x, &ignored16, &carry);
	if (carry == 0u)
		return y;
	y_2 = child_object_031CE9_ADDRESS;
	sub_07862C(x, y_2, &ignored16_2, &ignored16, &carry);
	mem_write8(x + 5u, 0x88u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	t2 = mem_read16(x + 0x38u);
	u = t2;
	sub_07859F(x, u);
	return y_2;
}

void sub_030BE1(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		t2 = mem_read8(x + 0x50u);
		mem_write8(x + 4u, t2);
		mem_write8(x + 5u, 0x80u);
		mem_write8(x, 0xC0u);
		mem_write8(x + 2u, 2u);
		mem_write8(x + 0x1Bu, 1u);
		mem_write16(x + 0x28u, 0u);
		mem_write8(x + 0x30u, 0u);
		mem_write8(x + 0x44u, 0u);
	}
}

uint16_t sub_030C0A(uint16_t x)
{
	uint8_t a = 0;
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t8 = 0;
	uint16_t t5 = 0, t6 = 0, t7 = 0;

	u = object_setup_031CF1_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x + 0x43u, 1u);
	t1 = mem_read8(x + 0x44u);
	mem_write8(x + 0x44u, t1 + 1u);
	mem_write16(x + 0x2Au, enemy_behaviour_031C7F_ADDRESS);
	mem_write8(x + 0x3Au, 0x10u);
	mem_write16(x + 0x5Cu, 0u);
	u = loaded_table_031CF7_ADDRESS;
	t2 = mem_read8(x + 0x30u);
	a = t2;
	if ((int8_t)t2 >= 0)
	{
		t3 = mem_read8(u + (int8_t)(((uint32_t)a << 1) << 1) + 2u);
		mem_write8(x + 0x50u, t3);
		mem_write8(x + 0x30u, 0u);
		mem_write8(x + 2u, 2u);
		return y;
	}
	mem_write8(x, 4u);
	t4 = mem_read8(x + 0x30u);
	u += (int8_t)(((uint32_t)t4 << 1) << 1);
	t5 = DATA16(u);
	mem_write8(x + 0x3Bu, t5 >> 8);
	mem_write8(x + 4u, t5);
	t6 = mem_read16(u + 2u);
	mem_write8(x + 0x50u, t6 >> 8);
	t7 = (t6 & 0xFFu) << 4;
	mem_write16(x + 0xCu, t7);
	t8 = mem_read8(x + 2u);
	mem_write8(x + 2u, t8 + 1u);
	return y;
}

void sub_030C65(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_030C6E(x);
		return;
	case 2:
		sub_030C84(x);
		return;
	case 4:
	case 16:
		sub_030CAF(x);
		return;
	case 6:
	case 18:
		sub_030CCB(x);
		return;
	case 8:
		sub_030D0E(x);
		return;
	case 10:
		sub_030D1C(x);
		return;
	case 12:
		sub_030D3E(x);
		return;
	case 14:
		sub_030D4E(x);
		return;
	case 20:
		sub_030D73(x);
		return;
	case 22:
		sub_030D9E(x);
		return;
	case 24:
		sub_030DCA(x);
		return;
	}
}

void sub_030C6E(uint16_t x)
{
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 0x30u);
	t2 = DATA16(loaded_table_031D51_ADDRESS + (int8_t)((uint32_t)t1 << 1));
	mem_write8(x + 0x29u, t2 >> 8);
	mem_write16(x + 0x3Eu, t2 & 0xFFu);
	mem_write8(x + 0x30u, 0u);
}

void sub_030C84(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	d = 0x301u;
	carry = sub_078680(d);
	mem_write8(x, 0x98u);
	mem_write16(x + 0xAu, 0x8080u);
	mem_write8(x + 9u, 0x20u);
	mem_write16(x + 0xFu, 0x80u);
	mem_write16(x + 0x19u, 0x300u);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
}

void sub_030CAF(uint16_t x)
{
	uint16_t d = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	sub_030CF6(x);
	t1 = mem_read16(x + 0x19u);
	d = t1 - 0x10u;
	mem_write16(x + 0x19u, d);
	if ((int16_t)d < 0)
	{
		mem_write16(x + 0x14u, 0xFF80u);
		mem_write8(x + 9u, 0x10u);
		t2 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t2 + 1u);
	}
}

void sub_030CCB(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	sub_030CF6(x);
	t1 = mem_read16(x + 0x19u);
	mem_write16(x + 0x19u, t1 - 0x20u);
	carry = sub_078662(x);
	if (carry == 0u)
		return;
	d = VIDEO_2000;
	carry = sub_078680(d);
	mem_write8(x, 0xC0u);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write16(x + 0x19u, 0u);
	mem_write16(x + 0x28u, 0u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
}

void sub_030CF6(uint16_t x)
{
	uint16_t d = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0xAu);
	d = t1 - 0x101u;
	if (d < 0x4040u)
		d = 0x8800u;
	else
	{
		mem_write16(x + 0xAu, d);
		d = 0x9800u;
	}
	mem_write8(x, d >> 8);
}

void sub_030D0E(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x, 0x80u);
	mem_write8(x + 9u, 0x50u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

void sub_030D1C(uint16_t x)
{
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0xCu);
	if (t1 < 0x160u)
	{
		mem_write16(x + 0xFu, rom_07FFC0_ADDRESS);
		mem_write16(x + 0x14u, 0xFF80u);
		mem_write8(x + 5u, 0x81u);
		mem_write8(x + 0x3Bu, 0x20u);
		t2 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t2 + 1u);
	}
}

void sub_030D3E(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x, 0xC0u);
		mem_write8(x + 2u, 2u);
	}
}

void sub_030D4E(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	d = 0x301u;
	carry = sub_078680(d);
	mem_write8(x, 0x98u);
	mem_write16(x + 0xAu, 0x8080u);
	mem_write8(x + 9u, 0x20u);
	mem_write16(x + 0x19u, 0x300u);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
}

void sub_030D73(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	d = 0x301u;
	carry = sub_078680(d);
	mem_write8(x, 0x98u);
	mem_write16(x + 0xAu, 0x8080u);
	mem_write8(x + 9u, 0x20u);
	mem_write16(x + 0xFu, 0x400u);
	mem_write16(x + 0x19u, 0x200u);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
}

void sub_030D9E(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0;

	sub_030CF6(x);
	t1 = mem_read16(x + 0xFu);
	mem_write16(x + 0xFu, t1 - 0x10u);
	t2 = mem_read16(x + 0x19u);
	d = t2 - 0x10u;
	mem_write16(x + 0x19u, d);
	if ((int16_t)d >= 0)
		return;
	d = VIDEO_2000;
	carry = sub_078680(d);
	mem_write16(x + 0x14u, 0xFF80u);
	mem_write8(x + 9u, 0x10u);
	t3 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t3 + 1u);
}

void sub_030DCA(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t4 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	sub_030CF6(x);
	t1 = mem_read16(x + 0xFu);
	t2 = mem_read16(x + 0x3Eu);
	mem_write16(x + 0xFu, t1 - t2);
	t3 = mem_read16(x + 0x19u);
	mem_write16(x + 0x19u, t3 - 0x20u);
	carry = sub_078662(x);
	if (carry == 0u)
		return;
	d = VIDEO_2000;
	carry = sub_078680(d);
	mem_write8(x, 0xC0u);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write16(x + 0x19u, 0u);
	mem_write16(x + 0x28u, 0u);
	t4 = mem_read8(x + 2u);
	mem_write8(x + 2u, t4 + 1u);
}

void sub_030E05(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 5u, 0x90u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	sub_07859C(x);
}

uint16_t sub_030E10(uint16_t x, uint16_t y)
{
	uint16_t y_2 = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) == 0u)
		return y;
	y_2 = hit_box_031C77_ADDRESS;
	sub_0785B4(x, y_2);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	return sub_030E23(x, y_2);
}

uint16_t sub_030E23(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t y_2 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
		return y;
	y_2 = hit_box_031C6F_ADDRESS;
	sub_0785B4(x, y_2);
	mem_write8(x + 2u, 2u);
	mem_write8(x + 0x3Bu, 0u);
	return y_2;
}

uint16_t sub_030E39(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0, u = 0;
	uint8_t t1 = 0, t4 = 0;
	uint16_t t2 = 0, t3 = 0;

	u = object_setup_031D8B_ADDRESS;
	sub_0785AB(x, u);
	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t1 & 0xCFu) | 0x10u);
	t2 = mem_read16(x + 0x16u);
	t3 = t2 - 0x30u;
	mem_write16(x + 0x16u, t3);
	d = 0x4C00u;
	carry = sub_078680(d);
	t4 = mem_read8(x + 2u);
	mem_write8(x + 2u, t4 + 1u);
	return u;
}

void sub_030E5C(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
		mem_write8(x, 0u);
}

uint16_t sub_030E8F(uint16_t x)
{
	uint8_t a = 0;
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t4 = 0;
	uint16_t t3 = 0;

	u = object_setup_031DC2_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 4u);
	t1 = mem_read8(x + 0x30u);
	a = t1;
	mem_write8(x + 0x3Du, DATA8(indexed_table_031DA1_ADDRESS + (int8_t)a));
	mem_write8(x + 0x2Eu, DATA8(indexed_table_031DA8_ADDRESS + (int8_t)a));
	mem_write8(x + 0x3Au, DATA8(indexed_table_031DAF_ADDRESS + (int8_t)a));
	t2 = mem_read8(x + 0x30u);
	t3 = DATA16(indexed_table_031DB6_ADDRESS + (int8_t)((uint32_t)t2 << 1));
	mem_write16(x + 0xCu, t3);
	mem_write16(x + 0x16u, 0x40u);
	mem_write8(x + 0x3Bu, 0x80u);
	mem_write16(x + 0x2Cu, 0x258u);
	sub_078620(x);
	t4 = mem_read8(x + 2u);
	mem_write8(x + 2u, t4 + 1u);
	return y;
}

void sub_030ED9(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_030EE2(x);
		return;
	case 2:
		sub_030EF9(x);
		return;
	case 4:
		sub_030F14(x);
		return;
	case 6:
		sub_030FBF(x);
		return;
	case 8:
		sub_030FE7(x);
		return;
	case 10:
		sub_031037(x);
		return;
	case 12:
		sub_031054(x);
		return;
	case 14:
		sub_031070(x);
		return;
	}
}

void sub_030EE2(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	sub_031165(x);
	mem_write8(x, 0x88u);
	d = 0x6C00u;
	carry = sub_078680(d);
	mem_write8(x + 5u, 0x84u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

void sub_030EF9(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
		return;
	mem_write8(x + 5u, 0x81u);
	t2 = mem_read8(x + 0x30u);
	if (t2 != 3u)
	{
		t3 = mem_read8(x + 0x30u);
		if (t3 == 2u)
		{
			d = unk_4B00_ADDRESS;
			carry = sub_078680(d);
		}
		sub_030F28(x);
		return;
	}
	mem_write8(x + 0x3Bu, 8u);
	t4 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t4 + 1u);
}

void sub_030F14(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	sub_030F28(x);
}

void sub_030F28(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x, 0xC8u);
	sub_078620(x);
	sub_0311CE(x);
	sub_0311AC(x);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	mem_write16(x + 0x28u, 0u);
}

void sub_030F3D(uint16_t x)
{
	uint8_t a = 0;
	uint8_t t4 = 0, t5 = 0, t9 = 0, t10 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t6 = 0, t7 = 0, t8 = 0;

	t1 = mem_read16(x + 0x2Cu);
	if (t1 == 0u)
	{
		sub_031092(x);
		mem_write16(x + 0x19u, 0x100u);
		t2 = mem_read16(x + 0x16u);
		if (t2 >= 0x100u)
			mem_write8(x, 0u);
		return;
	}
	t3 = mem_read16(x + 0x2Cu);
	mem_write16(x + 0x2Cu, t3 - 1u);
	sub_031184(x);
	sub_031092(x);
	t4 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t4 - 1u);
	if (t4 != 1u)
		return;
	mem_write8(x + 0x3Bu, 1u);
	t5 = mem_read8(x + 2u);
	mem_write8(x + 2u, t5 + 1u);
	if (mem_read8(x) == 0u)
		return;
	t6 = mem_read16(x + 0x38u);
	t7 = mem_read16(x + 0xCu);
	t8 = mem_read16(t6 + 0xCu);
	if (t8 <= t7)
	{
		t9 = mem_read8(x + 9u);
		a = t9 | 0x40u;
	}
	else
	{
		t10 = mem_read8(x + 9u);
		a = t10 & 0xBFu;
	}
	mem_write8(x + 9u, a);
}

void sub_030F70(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write16(x + 0x19u, 0u);
	mem_write8(x + 5u, 0x83u);
	mem_write8(x + 0x3Bu, 0x40u);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
}

uint16_t sub_030F87(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return y;
	y = child_object_030FAE_ADDRESS;
	sub_07862C(x, y, &ignored16, &ignored16_2, &carry);
	mem_write8(x + 0x3Bu, 0x20u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	return y;
}

void sub_030F9B(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 2u, 2u);
		mem_write8(x + 5u, 0x81u);
		sub_0311CE(x);
	}
}

void sub_030FB6(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_030FBF(x);
		return;
	case 2:
		sub_030FE7(x);
		return;
	case 4:
		sub_031037(x);
		return;
	case 6:
		sub_031054(x);
		return;
	case 8:
		sub_031070(x);
		return;
	case -6:
		sub_030EE2(x);
		return;
	case -4:
		sub_030EF9(x);
		return;
	case -2:
		sub_030F14(x);
		return;
	}
}

void sub_030FBF(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	mem_write8(x, 0x88u);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write16(x + 0x19u, 0u);
	t1 = mem_read16(x + 0x16u);
	mem_write16(x + 0x50u, t1);
	mem_write8(x + 0x3Bu, 0x1Eu);
	d = 0x6300u;
	carry = sub_078680(d);
	mem_write8(x + 5u, 0x85u);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
}

void sub_030FE7(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	sub_03107A(x);
	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
	{
		t2 = mem_read8(x + 0x3Bu);
		carry = (t2 >> 0) & 1u;
		if (carry)
		{
			t3 = mem_read8(x + 9u);
			a = (t3 & 0x30u) | 0x8Fu;
		}
		else
		{
			t4 = mem_read8(x + 9u);
			a = t4 & 0x7Fu;
		}
		mem_write8(x + 9u, a);
		mem_write8(x + 6u, 0x80u);
		return;
	}
	t5 = mem_read8(x + 9u);
	mem_write8(x + 9u, t5 & 0x7Fu);
	mem_write8(x + 5u, 0x81u);
	mem_write8(x + 2u, 2u);
	mem_write8(x, 0xC8u);
	mem_write8(x + 6u, 0x80u);
	mem_write8(x + 0x3Bu, 0x10u);
}

void sub_03102E(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_031037(x);
		return;
	case 2:
		sub_031054(x);
		return;
	case 4:
		sub_031070(x);
		return;
	case -10:
		sub_030EE2(x);
		return;
	case -8:
		sub_030EF9(x);
		return;
	case -6:
		sub_030F14(x);
		return;
	case -4:
		sub_030FBF(x);
		return;
	case -2:
		sub_030FE7(x);
		return;
	}
}

void sub_031037(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	mem_write8(x, 0x88u);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write16(x + 0x19u, 0u);
	d = 0x6300u;
	carry = sub_078680(d);
	mem_write8(x + 5u, 0x86u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

void sub_031054(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0;
	uint8_t t1 = 0, t2 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry == 0u)
		return;
	t1 = mem_read8(x + 0x27u);
	mem_write8(x + 0x27u, t1 | 0x80u);
	d = unk_4800_ADDRESS;
	carry = sub_078680(d);
	mem_write8(x + 5u, 0x88u);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
}

void sub_031070(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
		mem_write8(x, 0u);
}

void sub_03107A(uint16_t x)
{
	uint8_t a = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x3Bu);
	t2 = mem_read16(x + 0x50u);
	t3 = mem_read16(x + 0x16u);
	mem_write16(x + 0x19u, (uint32_t)(uint16_t)(((uint32_t)a << 8) | (uint8_t)((((uint32_t)a << 8) | (uint8_t)((((uint32_t)a << 8) | DATA8(indexed_table_031DD8_ADDRESS + (t1 & 3u))) + t2)) - t3)) << 8);
}

void sub_031092(uint16_t x)
{
	uint8_t a = 0, b = 0;
	uint16_t u = 0;
	uint8_t t4 = 0, t5 = 0, t9 = 0, t10 = 0, t13 = 0, t14 = 0, t15 = 0, t19 = 0, t20 = 0, t23 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t6 = 0, t7 = 0, t8 = 0, t11 = 0, t12 = 0, t16 = 0, t17 = 0, t18 = 0, t21 = 0, t22 = 0, t24 = 0, t25 = 0, t26 = 0, t27 = 0, t28 = 0, t29 = 0, t30 = 0, t31 = 0, t32 = 0, t33 = 0, t34 = 0;

	t1 = mem_read16(x + 0x38u);
	u = t1;
	if ((unk_4815 & 0x7F00u) == 0u)
		u = sub_078620(x);
	t2 = mem_read16(x + 0xCu);
	t3 = mem_read16(u + 0xCu);
	if (t2 < t3)
	{
		t4 = mem_read8(x + 0x3Du);
		if (t4 != 0u)
		{
			t5 = mem_read8(x + 0x3Au);
			t6 = 0u - t5;
			t7 = mem_read16(x + 0x2Eu);
			t8 = t6 + t7;
			a = (t8 >> 8) & 0xFu;
			mem_write16(x + 0x2Eu, ((uint32_t)a << 8) | (uint8_t)t8);
			if (a == 0xCu)
			{
				t9 = mem_read8(x + 0x3Du);
				mem_write8(x + 0x3Du, ~t9);
			}
		}
		else
		{
			t10 = mem_read8(x + 0x3Au);
			t11 = mem_read16(x + 0x2Eu);
			t12 = t10 + t11;
			a = (t12 >> 8) & 0xFu;
			mem_write16(x + 0x2Eu, ((uint32_t)a << 8) | (uint8_t)t12);
			if (a == 4u)
			{
				t13 = mem_read8(x + 0x3Du);
				mem_write8(x + 0x3Du, ~t13);
			}
		}
	}
	else
	{
		t14 = mem_read8(x + 0x3Du);
		if (t14 != 0u)
		{
			t15 = mem_read8(x + 0x3Au);
			t16 = 0u - t15;
			t17 = mem_read16(x + 0x2Eu);
			t18 = t16 + t17;
			a = (t18 >> 8) & 0xFu;
			mem_write16(x + 0x2Eu, ((uint32_t)a << 8) | (uint8_t)t18);
			if (a == 4u)
			{
				t19 = mem_read8(x + 0x3Du);
				mem_write8(x + 0x3Du, ~t19);
			}
		}
		else
		{
			t20 = mem_read8(x + 0x3Au);
			t21 = mem_read16(x + 0x2Eu);
			t22 = t20 + t21;
			a = (t22 >> 8) & 0xFu;
			mem_write16(x + 0x2Eu, ((uint32_t)a << 8) | (uint8_t)t22);
			if (a == 0xCu)
			{
				t23 = mem_read8(x + 0x3Du);
				mem_write8(x + 0x3Du, ~t23);
			}
		}
	}
	sub_0311AC(x);
	t24 = mem_read16(x + 0x38u);
	t25 = mem_read16(x + 0x11u);
	t26 = mem_read16(t24 + 0x11u);
	t27 = t25 - t26;
	a = (uint8_t)(t27 >> 8);
	unk_48F0 = a;
	t28 = ((uint32_t)a << 8) | (uint8_t)t27;
	t29 = t28 >> 15 ? 0u - t28 : t28;
	if (t29 >= 4u)
	{
		mem_write16(x + 0x14u, 0x100u);
		if ((int8_t)unk_48F0 >= 0)
		{
			t30 = mem_read16(x + 0x14u);
			mem_write16(x + 0x14u, 0u - t30);
		}
	}
	t31 = mem_read16(x + 0xCu);
	a = (uint8_t)(t31 >> 8);
	b = (uint8_t)t31;
	if ((uint16_t)(((uint32_t)a << 8) | b) < 0x60u)
	{
		b = 0x60u;
		t32 = mem_read16(x + 0xCu);
		mem_write16(x + 0xFu, (uint32_t)(uint8_t)((((uint32_t)a << 8) | b) - t32) << 8);
		t33 = mem_read16(x + 0x11u);
		a = (uint8_t)(t33 >> 8);
		b = (uint8_t)t33;
		if ((uint16_t)(((uint32_t)a << 8) | b) < 0x90u)
		{
			b = 0x90u;
			t34 = mem_read16(x + 0x11u);
			mem_write16(x + 0x14u, (uint32_t)(uint8_t)((((uint32_t)a << 8) | b) - t34) << 8);
			return;
		}
		if ((uint16_t)(((uint32_t)a << 8) | b) >= 0x100u)
		{
			b = 0xFFu;
			t34 = mem_read16(x + 0x11u);
			mem_write16(x + 0x14u, (uint32_t)(uint8_t)((((uint32_t)a << 8) | b) - t34) << 8);
		}
		return;
	}
	if ((uint16_t)(((uint32_t)a << 8) | b) >= 0x160u)
	{
		b = 0x5Fu;
		t32 = mem_read16(x + 0xCu);
		mem_write16(x + 0xFu, (uint32_t)(uint8_t)((((uint32_t)a << 8) | b) - t32) << 8);
	}
	t33 = mem_read16(x + 0x11u);
	a = (uint8_t)(t33 >> 8);
	b = (uint8_t)t33;
	if ((uint16_t)(((uint32_t)a << 8) | b) < 0x90u)
	{
		b = 0x90u;
		t34 = mem_read16(x + 0x11u);
		mem_write16(x + 0x14u, (uint32_t)(uint8_t)((((uint32_t)a << 8) | b) - t34) << 8);
		return;
	}
	if ((uint16_t)(((uint32_t)a << 8) | b) >= 0x100u)
	{
		b = 0xFFu;
		t34 = mem_read16(x + 0x11u);
		mem_write16(x + 0x14u, (uint32_t)(uint8_t)((((uint32_t)a << 8) | b) - t34) << 8);
	}
}

void sub_031165(uint16_t x)
{
	uint8_t a = 0;
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 0x37u);
	t2 = mem_read16(x + 0x16u);
	mem_write16(x + 0x19u, (uint32_t)(uint16_t)(((uint32_t)a << 8) | (uint8_t)((((uint32_t)a << 8) | (uint8_t)((((uint32_t)a << 8) | DATA8(indexed_table_031DDC_ADDRESS + (int8_t)t1)) + 0x40u)) - t2)) << 8);
	t3 = mem_read8(x + 0x37u);
	mem_write8(x + 0x37u, (t3 + 1u) & 0x1Fu);
}

void sub_031184(uint16_t x)
{
	uint8_t a = 0, b = 0;
	uint16_t u = 0;
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 0x37u);
	b = t1;
	if ((b & 0xE0u) != 0u)
		u = indexed_table_031DDC_ADDRESS;
	else
		u = indexed_table_031DFC_ADDRESS;
	t2 = mem_read16(x + 0x16u);
	mem_write16(x + 0x19u, (uint32_t)(uint16_t)(((uint32_t)a << 8) | (uint8_t)((((uint32_t)a << 8) | (uint8_t)((((uint32_t)a << 8) | (uint8_t)(int8_t)DATA8(u + (b & 0x1Fu))) + 0x40u)) - t2)) << 8);
	t3 = mem_read8(x + 0x37u);
	mem_write8(x + 0x37u, t3 + 1u);
}

void sub_0311AC(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t1 = 0, t2 = 0;
	uint16_t t3 = 0, t4 = 0;

	t1 = mem_read8(x + 2u);
	if (t1 != 2u)
		u = loaded_table_031E60_ADDRESS;
	else
		u = loaded_table_031E20_ADDRESS;
	t2 = mem_read8(x + 0x2Eu);
	u += (int8_t)(((uint32_t)t2 << 1) << 1);
	t3 = DATA16(u);
	mem_write16(x + 0xFu, t3);
	t4 = mem_read16(u + 2u);
	mem_write16(x + 0x14u, t4);
}

void sub_0311CE(uint16_t x)
{
	uint8_t a = 0;
	uint16_t d = 0;

	d = sub_078623(0u);
	a = (uint8_t)(d >> 8);
	mem_write8(x + 0x3Bu, DATA8(indexed_table_031E1C_ADDRESS + (a & 3u)));
}

void sub_0311F5(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_031EF0_ADDRESS;
		t1 = mem_read8(x + 0x29u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			sub_0311FE(x);
			break;
		case 2:
			sub_03120A(x);
			break;
		case -8:
		case -6:
			continue;
		case -4:
			sub_031214(x, &y, &u);
			break;
		case -2:
			sub_031237();
			break;
		}
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_0311FE(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write16(x + 0xFu, 0u);
	mem_write8(x + 5u, 0x80u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

void sub_03120A(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
		mem_write8(x, 0u);
}

void sub_031214(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0;

	u = object_setup_031EF4_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x + 0x1Du, 1u);
	mem_write8(x, 0xC8u);
	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t1 & 0xCFu) | 0x10u);
	mem_write16(x + 0xFu, 0xFD00u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	sub_031237();
	*p_y = y;
	*p_u = u;
}

void sub_031237(void)
{
}

void sub_031243(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 2u);
	if ((int8_t)t1 >= 0 && (mem_read8(x) & 0x20u) != 0u)
		mem_write8(x + 2u, 0xFFu);
}

uint16_t sub_031255(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0;

	for (;;)
	{
		t1 = mem_read8(x + 0x29u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			sub_03125E(x);
			return y;
		case 2:
			sub_031279();
			return y;
		case 4:
			sub_031283(x);
			return y;
		case 6:
			break;
		case -14:
			continue;
		case -12:
			return sub_03129D(x);
		case -10:
			sub_0312AF(x);
			return y;
		case -8:
			sub_0312BB(x);
			return y;
		case -6:
			return sub_0312C4(x, y);
		case -4:
			sub_0312D4(x);
			return y;
		case -2:
			sub_0312E3(x);
			return y;
		}
		break;
	}
	sub_03128C(x);
	return y;
}

void sub_03125E(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t1 & 0xCFu) | 0x10u);
	mem_write16(x + 0xFu, 0x100u);
	mem_write8(x + 5u, 0x82u);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	sub_0785C6(x);
}

void sub_031279(void)
{
}

void unused_03127A(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_031283(x);
		return;
	case 2:
		sub_03128C(x);
		return;
	case -18:
		sub_031255(x, 0u);
		return;
	case -16:
		sub_03129D(x);
		return;
	case -14:
		sub_0312AF(x);
		return;
	case -12:
		sub_0312BB(x);
		return;
	case -10:
		sub_0312C4(x, 0u);
		return;
	case -8:
		sub_0312D4(x);
		return;
	case -6:
		sub_0312E3(x);
		return;
	case -4:
		sub_03125E(x);
		return;
	case -2:
		sub_031279();
		return;
	}
}

void sub_031283(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 5u, 0x84u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

void sub_03128C(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		mem_write8(x, 0xC0u);
		mem_write8(x + 2u, 2u);
	}
}

uint16_t sub_03129D(uint16_t x)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0;

	u = object_setup_031F10_ADDRESS;
	y = sub_0785AB(x, u);
	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, t1 | 0x40u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	return y;
}

void sub_0312AF(uint16_t x)
{
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0xCu);
	if (t1 < 0x150u)
	{
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_0312BB(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 5u, 0x83u);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
}

uint16_t sub_0312C4(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, y_2 = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) == 0u)
		return y;
	y_2 = child_object_031F16_ADDRESS;
	sub_07862F(x, y_2, &ignored16, &carry);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	sub_0312D4(x);
	return y_2;
}

void sub_0312D4(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		mem_write8(x + 5u, 0x81u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_0312E3(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
		mem_write8(x + 2u, 2u);
}

void sub_0312F8(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0;

	u = object_setup_031F2A_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t1 & 0xCFu) | 0xA9u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_031311(uint16_t x)
{
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0xCu);
	if (t1 < 0x120u)
	{
		mem_write8(x + 0x3Bu, 0x20u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_031322(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(x + 0x14u, 0xFF00u);
		mem_write8(x + 0x3Bu, 0x10u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_031336(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		t2 = mem_read8(x + 9u);
		mem_write8(x + 9u, (t2 & 0xCFu) | 0x10u);
		mem_write16(x + 0x14u, 0u);
		mem_write8(x + 5u, 0x81u);
		t3 = mem_read8(x + 2u);
		mem_write8(x + 2u, t3 + 1u);
	}
}

void sub_031351(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		mem_write16(x + 0xFu, 0x100u);
		mem_write16(x + 0x14u, 0xFF00u);
		mem_write8(x + 0x3Bu, 0x40u);
		mem_write8(x + 5u, 0x80u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_031371(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
	{
		sub_031382();
		return;
	}
	mem_write16(x + 0xFu, 0x200u);
	mem_write16(x + 0x14u, 0u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	sub_031382();
}

void sub_031382(void)
{
}

void sub_03138C(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0;

	u = object_setup_031F44_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 0x80u);
	mem_write16(x + 0x16u, 0x10u);
	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t1 & 0xCFu) | 0x10u);
	mem_write16(x + 0xFu, 0xFF00u);
	mem_write8(x + 0x3Bu, 0x48u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	sub_0785C6(x);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_0313B8(uint16_t x, uint16_t u)
{
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(x + 0xFu, 0u);
		mem_write8(x + 0x3Du, 1u);
		t2 = mem_read16(x + 0x40u);
		u = t2;
		mem_write8(u, 4u);
		mem_write8(u + 6u, 0x80u);
		mem_write8(x + 5u, 0x82u);
		t3 = mem_read8(x + 2u);
		mem_write8(x + 2u, t3 + 1u);
	}
	return u;
}

void sub_0313DB(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		mem_write8(x + 5u, 0x83u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_0313EA(uint16_t x)
{
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = unk_48AC;
	if (t1 >= 0x238u)
	{
		mem_write8(x + 5u, 0x84u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

uint16_t sub_0313FB(uint16_t x, uint16_t u)
{
	uint32_t carry = 0;
	uint16_t u_2 = 0;
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
		return u;
	t2 = mem_read16(x + 0x40u);
	u_2 = t2;
	mem_write8(u_2, 0x80u);
	mem_write8(u_2 + 6u, 0x80u);
	mem_write8(x + 5u, 0x81u);
	mem_write16(x + 0xFu, 0x100u);
	t3 = mem_read8(x + 2u);
	mem_write8(x + 2u, t3 + 1u);
	sub_0785C6(x);
	return u_2;
}

void sub_03141E(uint16_t x)
{
	uint8_t t2 = 0;
	uint16_t t1 = 0, t3 = 0;

	t1 = mem_read16(x + 0xCu);
	if (t1 >= 0x100u)
	{
		mem_write16(x + 0xFu, 0u);
		mem_write8(x + 5u, 0x80u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
	t3 = unk_48AC;
	if (t3 >= 0x340u)
	{
		mem_write16(x + 0xFu, 0u);
		mem_write8(x + 5u, 0x80u);
		mem_write8(x + 0x3Bu, 0x80u);
		mem_write8(x + 2u, 8u);
	}
}

void sub_03144C(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
		return;
	mem_write8(x + 5u, 0x81u);
	mem_write8(x + 0x3Bu, 0x20u);
	mem_write16(x + 0xFu, 0x100u);
	if ((int8_t)unk_4858 < 0)
	{
		t2 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t2);
	}
	t3 = mem_read8(x + 2u);
	mem_write8(x + 2u, t3 + 1u);
	sub_0785C6(x);
}

void sub_031471(uint16_t x)
{
	uint8_t a = 0, d = 0;
	uint8_t t2 = 0, t3 = 0, t5 = 0;
	uint16_t t1 = 0, t4 = 0;

	t1 = unk_48AC;
	if (t1 < 0x340u)
	{
		t2 = mem_read8(x + 0x3Bu);
		mem_write8(x + 0x3Bu, t2 - 1u);
		if (t2 == 1u)
		{
			mem_write16(x + 0xFu, 0u);
			mem_write8(x + 5u, 0x80u);
			t3 = mem_read8(x + 2u);
			mem_write8(x + 2u, t3 - 1u);
			return;
		}
		t4 = mem_read16(x + 0xCu);
		d = (uint8_t)t4;
		a = (uint8_t)(t4 >> 8);
		if ((uint16_t)(((uint32_t)a << 8) | (d & 0xFFu)) < 0xE0u)
		{
			mem_write16(x + 0xFu, 0x100u);
			return;
		}
		if ((uint16_t)(((uint32_t)a << 8) | (d & 0xFFu)) >= 0x100u)
			mem_write16(x + 0xFu, 0xFF00u);
		return;
	}
	mem_write16(x + 0xFu, 0u);
	mem_write8(x + 5u, 0x80u);
	mem_write8(x + 0x3Bu, 0x80u);
	t5 = mem_read8(x + 2u);
	mem_write8(x + 2u, t5 + 1u);
}

void sub_0314B6(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(x + 5u, 0x81u);
	mem_write16(x + 0xFu, 0xFF00u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	sub_0785C6(x);
}

void sub_0314CD(uint16_t x)
{
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0xCu);
	if (t1 < 0x30u)
		mem_write8(x, 0u);
}

void sub_0314E2(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t3 = 0, t4 = 0;
	uint16_t t2 = 0;

	u = object_setup_031F58_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 0x30u);
	u = loaded_table_031F52_ADDRESS + (int8_t)((uint32_t)t1 << 1);
	t2 = DATA16(u);
	mem_write8(x + 9u, t2 >> 8);
	mem_write8(x + 5u, t2);
	t3 = mem_read8(x + 0x30u);
	if (t3 != 0u)
	{
		t4 = mem_read8(x + 2u);
		mem_write8(x + 2u, t4 + 1u);
		sub_03150C();
	}
	else
		mem_write8(x + 2u, 2u);
	*p_y = y;
	*p_u = u;
}

void sub_03150C(void)
{
}

void sub_03150D(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = io_read8(VIDEO_187F);
	if (t1 != 0u)
	{
		unk_4A84 = 0x9Fu;
		unk_4B44 = 0x9Fu;
		unk_4C04 = 0x9Fu;
		unk_4CC4 = 0x9Fu;
		mem_write8(x, 0xC0u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_03152E(uint16_t x)
{
	if ((mem_read8(x) & 0x20u) != 0u)
	{
		mem_write8(x, 0x80u);
		mem_write8(x + 2u, 1u);
	}
}

void unused_031540(void)
{
}

uint16_t sub_03154D(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0;

	for (;;)
	{
		t1 = mem_read8(x + 0x28u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			sub_031556(x);
			return y;
		case 2:
		case 8:
			sub_031583(x);
			return y;
		case 4:
		case 10:
			sub_03159B();
			return y;
		case 6:
			break;
		case -10:
			continue;
		case -8:
		case -6:
			return sub_031565(x, y);
		case -4:
			return sub_03159C(x);
		case -2:
			sub_0315B3(x);
			return y;
		}
		break;
	}
	sub_03156E(x);
	return y;
}

void sub_031556(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write8(x + 5u, 0x90u);
	t1 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t1 + 1u);
}

uint16_t sub_031565(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0;

	for (;;)
	{
		t1 = mem_read8(x + 0x28u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			break;
		case -4:
		case 2:
			sub_031583(x);
			return y;
		case -2:
		case 4:
			sub_03159B();
			return y;
		case -16:
			return sub_03154D(x, y);
		case -14:
		case -12:
			continue;
		case -10:
			return sub_03159C(x);
		case -8:
			sub_0315B3(x);
			return y;
		case -6:
			sub_031556(x);
			return y;
		}
		break;
	}
	sub_03156E(x);
	return y;
}

void sub_03156E(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	d = 0x6300u;
	carry = sub_078680(d);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write8(x + 5u, 0x89u);
	t1 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t1 + 1u);
}

void sub_031583(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
		return;
	mem_write16(x + 0xFu, 0xFE80u);
	mem_write8(x + 5u, 0x81u);
	t2 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t2 + 1u);
	sub_0785C6(x);
}

void sub_03159B(void)
{
}

uint16_t sub_03159C(uint16_t x)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0;

	u = object_setup_031F74_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x + 9u, 0x40u);
	mem_write8(x + 0x42u, 0xFFu);
	mem_write8(x + 0x57u, 0xFFu);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	return y;
}

void sub_0315B3(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;
	uint16_t t3 = 0;

	if ((unk_4815 & 0x7Fu) == 0u)
	{
		t1 = mem_read8(x + VIDEO_003C);
		mem_write8(x + VIDEO_003C, t1 + 1u);
		t2 = mem_read8(x + VIDEO_003C);
		mem_write8(x + 5u, DATA8(indexed_table_031F7A_ADDRESS + (t2 & 3u)));
	}
	t3 = unk_48AC;
	if (t3 >= 0x270u)
	{
		mem_write8(x, 0x80u);
		mem_write8(x + 2u, 0xFDu);
		mem_write8(x + 0x28u, 0u);
	}
}

uint16_t sub_0315ED(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0;

	for (;;)
	{
		t1 = mem_read8(x + 0x28u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			sub_0315F6(x);
			return y;
		case 2:
			break;
		case -16:
		case -14:
			continue;
		case -12:
			return sub_031608(x);
		case -10:
			return sub_03161B(x);
		case -8:
			sub_03164B(x);
			return y;
		case -6:
			sub_031690(x);
			return y;
		case -4:
			sub_0316A1(x);
			return y;
		case -2:
			sub_0316B0(x);
			return y;
		}
		break;
	}
	sub_031607();
	return y;
}

void sub_0315F6(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 5u, 0x82u);
	mem_write16(x + 0xFu, 0x200u);
	t1 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t1 + 1u);
	sub_0785C6(x);
}

void sub_031607(void)
{
}

uint16_t sub_031608(uint16_t x)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0;

	u = object_setup_031F92_ADDRESS;
	y = sub_0785AB(x, u);
	t1 = mem_read8(x + 0x42u);
	mem_write8(x + 0x42u, t1 - 1u);
	mem_write16(x + 0xFu, 0xFE00u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	return y;
}

uint16_t sub_03161B(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, u = 0, y = 0;
	uint8_t t1 = 0;

	y = child_object_031F98_ADDRESS;
	sub_07862C(x, y, &u, &ignored16, &carry);
	if (carry == 0u)
	{
		mem_write8(x + 2u, 0xFEu);
		mem_write8(x + 0x28u, 0u);
		return y;
	}
	mem_write16(x + 0x40u, u);
	mem_write8(x + 0x3Bu, 0x40u);
	mem_write8(x, 0xC0u);
	mem_write16(x + 0xFu, 0xFF00u);
	mem_write8(x + 5u, 0x81u);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	sub_0785C6(x);
	return y;
}

void sub_03164B(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t2 = 0, t4 = 0, t10 = 0, t11 = 0;
	uint16_t t1 = 0, t3 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0;

	t1 = mem_read16(x + 0x40u);
	t2 = mem_read8(t1 + 2u);
	if ((int8_t)t2 < 0)
	{
		mem_write8(x + 2u, 5u);
		return;
	}
	t3 = mem_read16(x + 0x40u);
	u = t3;
	t4 = mem_read8(u + 6u);
	mem_write8(u + 6u, t4 | 0x80u);
	t5 = mem_read16(x + 0xCu);
	mem_write16(u + 0xCu, t5);
	t6 = mem_read16(x + 0x11u);
	t7 = t6 - 4u;
	mem_write16(u + 0x11u, t7);
	t8 = mem_read16(x + 0x16u);
	t9 = t8 + 0x40u;
	mem_write16(u + 0x16u, t9);
	t10 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t10 - 1u);
	if (t10 == 1u)
	{
		mem_write8(x + 0x3Bu, 0x10u);
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
		t11 = mem_read8(x + 2u);
		mem_write8(x + 2u, t11 + 1u);
	}
}

void sub_031690(uint16_t x)
{
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	mem_write8(x + 5u, 0x84u);
	t1 = mem_read16(x + 0x40u);
	mem_write8(t1 + 2u, 2u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
}

void sub_0316A1(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		mem_write8(x + 5u, 0x83u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_0316B0(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
		return;
	mem_write8(x, 0x80u);
	mem_write8(x + 2u, 0xFEu);
	mem_write8(x + 0x28u, 0u);
}
