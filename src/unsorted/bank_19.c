/**
 *    Name:        unsorted/bank_19.c
 *    Description: bank 19's code
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    07-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

void sub_032000(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d_2 = 0, ignored16 = 0;
	uint32_t ignored = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		y = sub_032B4C(x);
		break;
	case 4:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case 6:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case 8:
		y = sub_032D51(x, y);
		break;
	case 10:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	t1 = mem_read8(x + 2u);
	if (t1 == 2u)
	{
		t2 = mem_read8(x + 0x30u);
		if (t2 == 3u)
		{
			t3 = mem_read8(x + 5u);
			a = t3;
			if (a != 0x87u)
			{
				if (a == 0x80u)
				{
					d_2 = 0x2700u;
					carry = sub_078680(d_2);
				}
			}
			else
			{
				d_2 = 0x2700u;
				carry = sub_078680(d_2);
			}
		}
	}
	*p_y = y;
}

void sub_032003(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_033C36_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_032CDB(x);
		break;
	case -72:
	case -58:
	case 2:
		sub_032CE7(x, &y, &u);
		break;
	case -34:
	case 4:
	case 62:
		sub_032C51(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_032006(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_033C70_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_032D19(x);
		break;
	case -126:
	case -112:
	case 2:
		sub_032D25(x, &y, &u);
		break;
	case -92:
	case -54:
	case 4:
		sub_032C51(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_032009(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;
	uint8_t t1 = 0;

	b = (uint8_t)d;
	u = loaded_table_033C04_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_032C0B(x);
		break;
	case 2:
		y = sub_032C17(x, y);
		break;
	case 4:
		y = sub_032C28(x);
		break;
	case 6:
		y = sub_032C31(x, y);
		break;
	case 8:
		y = sub_032C42(x);
		break;
	case -2:
	case 10:
		sub_032C4B(x);
		break;
	case 12:
		sub_032C89(x);
		break;
	case 14:
		sub_032CA5(x, &y, &u);
		break;
	case 16:
	case 54:
	case 112:
		sub_032C51(x);
		break;
	case -22:
	case -8:
	case 52:
		sub_032CE7(x, &y, &u);
		break;
	case -18:
	case -4:
	case 110:
		sub_032D25(x, &y, &u);
		break;
	case -28:
		sub_032B9B(x);
		break;
	case -26:
	case -14:
		sub_032BAE(x);
		break;
	case -24:
	case -10:
		sub_032CDE(x);
		break;
	case -20:
	case -6:
		sub_032D1C(x);
		break;
	case -16:
		sub_032BBC(x);
		break;
	case -12:
		sub_032BCF(x);
		break;
	}
	t1 = mem_read8(x + 0x43u);
	if (t1 != 0u)
		sub_032C6D(x);
	*p_y = y;
	*p_u = u;
}

void sub_03200C(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_033BE8_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_032B9B(x);
		break;
	case 2:
	case 14:
		sub_032BAE(x);
		break;
	case 4:
	case 18:
		sub_032CDE(x);
		break;
	case 6:
	case 20:
	case 80:
		sub_032CE7(x, &y, &u);
		break;
	case 8:
	case 22:
		sub_032D1C(x);
		break;
	case 10:
	case 24:
		sub_032D25(x, &y, &u);
		break;
	case 12:
		sub_032BBC(x);
		break;
	case 16:
		sub_032BCF(x);
		break;
	case 26:
	case 38:
		sub_032C4B(x);
		break;
	case 28:
		sub_032C0B(x);
		break;
	case 30:
		y = sub_032C17(x, y);
		break;
	case 32:
		y = sub_032C28(x);
		break;
	case 34:
		y = sub_032C31(x, y);
		break;
	case 36:
		y = sub_032C42(x);
		break;
	case 40:
		sub_032C89(x);
		break;
	case 42:
		sub_032CA5(x, &y, &u);
		break;
	case 44:
	case 82:
		sub_032C51(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_03200F(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_033D08_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_032E39(x);
		break;
	case 2:
		sub_032E47(x, &y, &u);
		break;
	case 4:
		sub_032E61(x);
		break;
	case 6:
		sub_032C4B(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_032012(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;
	uint8_t t1 = 0, t2 = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		y = sub_032301(x);
		break;
	case -22:
	case -10:
	case 2:
		y = sub_032339(x, y);
		break;
	case -20:
	case -8:
	case 4:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case -18:
	case -6:
	case 6:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case -16:
	case -4:
	case 8:
		sub_07865C(x, &y, &ignored16);
		break;
	case -14:
	case -2:
	case 10:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	case 12:
		y = sub_0322E5(x, y);
		break;
	case 14:
		sub_0322EE(x);
		break;
	case 16:
		sub_0322F7(x);
		break;
	case -24:
		y = sub_032272(x);
		break;
	case -12:
		y = sub_032297(x);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	t1 = io_read8(VIDEO_187E);
	if (t1 != 0u && mem_read8(x) != 0u)
	{
		t2 = mem_read8(x + 2u);
		if (t2 != 6u)
		{
			mem_write8(x + 2u, 6u);
			mem_write16(x + 0x28u, 0u);
			mem_write16(x + 0xFu, 0u);
			mem_write16(x + 0x14u, 0u);
			mem_write16(x + 0x19u, 0u);
			mem_write8(x, 0x80u);
		}
	}
	*p_y = y;
}

void sub_032015(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_033AAB_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		u = sub_0326A0(x);
		break;
	case 2:
		sub_0326B4(x);
		break;
	case 4:
		y = sub_0326C4(x, y);
		break;
	case -34:
	case -4:
	case 6:
		y = sub_0326D5(x);
		break;
	case -32:
	case -26:
	case -2:
	case 8:
		sub_0326DE(x);
		break;
	case -8:
		sub_03267E(x);
		break;
	case -6:
		y = sub_032689(x, y);
		break;
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_032018(uint16_t x, uint32_t y, uint8_t d)
{
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_033D16_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		return sub_032E76(x);
	case 2:
		sub_032E90(x);
		return u;
	case 4:
		return sub_032EB4(x, u);
	}
	unreachable();
}

void sub_03201B(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_033AA3_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_03267E(x);
		break;
	case 2:
		y = sub_032689(x, y);
		break;
	case -26:
	case 4:
	case 14:
		y = sub_0326D5(x);
		break;
	case -24:
	case -18:
	case 6:
	case 16:
		sub_0326DE(x);
		break;
	case 8:
		u = sub_0326A0(x);
		break;
	case 10:
		sub_0326B4(x);
		break;
	case 12:
		y = sub_0326C4(x, y);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_03201E(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_033A8D_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_03260E(x);
		break;
	case 2:
		sub_032619(x, &y, &u);
		break;
	case -2:
	case 4:
	case 28:
	case 38:
		sub_0326DE(x);
		break;
	case -4:
	case 26:
	case 36:
		y = sub_0326D5(x);
		break;
	case -8:
		sub_0325DC(x);
		break;
	case -6:
		y = sub_0325E7(x, y);
		break;
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_032021(uint16_t x, uint32_t y, uint8_t d)
{
	uint32_t negative = 0, carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d_2 = 0, ignored16 = 0, u = 0;
	uint8_t t1 = 0, t2 = 0;

	b = (uint8_t)d;
	u = loaded_table_033A99_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_032651(x, &ignored16, &u);
		break;
	case 2:
		sub_032677();
		break;
	}
	carry = sub_078683(x, carry);
	t1 = mem_read8(x);
	a = t1;
	if (t1 == 0u)
		return u;
	if ((a & 0x20u) != 0u)
	{
		mem_write8(x, 0u);
		return u;
	}
	d_2 = 0u;
	sub_078638(x, &d_2, &negative);
	a = (uint8_t)(d_2 >> 8);
	if ((int8_t)a < 0)
	{
		mem_write8(x, 0u);
		return u;
	}
	t2 = mem_read8(x + 0x5Du);
	if ((uint8_t)((((a & 0xFu) << 1) << 1) << 1) <= t2)
		return u;
	mem_write8(x, 0u);
	return u;
}

void sub_032027(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_033B06_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_032A3F(x, &y, &u);
		break;
	case 2:
		sub_032A75(x);
		break;
	case 4:
		sub_032A83(x);
		break;
	case 6:
		sub_032A9C(x);
		break;
	case 8:
		sub_032AD0(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_03202A(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_033ABA_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		u = sub_0326EE(x);
		break;
	case 2:
		sub_03270B(x);
		break;
	case 4:
		y = sub_032730(x, y);
		break;
	case 6:
		y = sub_032743(x, y);
		break;
	case 8:
		y = sub_032773(x, y);
		break;
	case 10:
		sub_032796(x);
		break;
	case 12:
		sub_0327E2(x);
		break;
	case 14:
		y = sub_03280A(x, y);
		break;
	case 16:
		sub_032852(x);
		break;
	case 18:
		sub_032862(x);
		break;
	case 20:
		sub_03286B(x);
		break;
	case 22:
		sub_032881(x);
		break;
	case 24:
		sub_0328A5(x);
		break;
	case 26:
		sub_0328C1(x);
		break;
	case 28:
		sub_0328D1(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_03202D(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_033AC4_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_032796(x);
		break;
	case 2:
		sub_0327E2(x);
		break;
	case 4:
		y = sub_03280A(x, y);
		break;
	case 6:
		sub_032852(x);
		break;
	case 8:
		sub_032862(x);
		break;
	case 10:
		sub_03286B(x);
		break;
	case 12:
		sub_032881(x);
		break;
	case 14:
		sub_0328A5(x);
		break;
	case 16:
		sub_0328C1(x);
		break;
	case 18:
		sub_0328D1(x);
		break;
	case -10:
		u = sub_0326EE(x);
		break;
	case -8:
		sub_03270B(x);
		break;
	case -6:
		y = sub_032730(x, y);
		break;
	case -4:
		y = sub_032743(x, y);
		break;
	case -2:
		y = sub_032773(x, y);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_032030(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_033A85_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_0325DC(x);
		break;
	case 2:
		y = sub_0325E7(x, y);
		break;
	case 4:
	case 34:
	case 44:
		y = sub_0326D5(x);
		break;
	case 6:
	case 12:
	case 36:
	case 46:
		sub_0326DE(x);
		break;
	case 8:
		sub_03260E(x);
		break;
	case 10:
		sub_032619(x, &y, &u);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_032033(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		y = sub_032297(x);
		break;
	case -10:
	case 2:
	case 14:
		y = sub_032339(x, y);
		break;
	case -8:
	case 4:
	case 16:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case -6:
	case 6:
	case 18:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case -4:
	case 8:
	case 20:
		sub_07865C(x, &y, &ignored16);
		break;
	case -2:
	case 10:
	case 22:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	case 12:
		y = sub_032301(x);
		break;
	case 24:
		y = sub_0322E5(x, y);
		break;
	case 26:
		sub_0322EE(x);
		break;
	case 28:
		sub_0322F7(x);
		break;
	case -12:
		y = sub_032272(x);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_032036(uint8_t d, uint16_t *p_x, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_033D52_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_032EE4(x, &y, &u);
		break;
	case 2:
		sub_032F03(x, &y, &u);
		break;
	case 4:
		sub_032F2B(x);
		break;
	case 6:
		sub_032F3C(x);
		break;
	case 8:
		sub_032F50(x);
		break;
	case 10:
		sub_032F61(x);
		break;
	case 12:
		sub_032F74(x);
		break;
	case 14:
		sub_032F88(x);
		break;
	case -2:
		sub_07B0B8(&x, &y, &u, p_left_caller);
		break;
	}
	carry = sub_078683(x, carry);
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

void sub_032039(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_033D88_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_032F9A(x, &y, &u);
		break;
	case 2:
		u = sub_032FC7(x);
		break;
	case 4:
		sub_032FDB(x);
		break;
	case 6:
		sub_032FE8();
		break;
	}
	carry = sub_078683(x, carry);
	*p_y = y;
	*p_u = u;
}

void sub_03203C(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_033ACC_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_032862(x);
		break;
	case 2:
		sub_03286B(x);
		break;
	case 4:
		sub_032881(x);
		break;
	case 6:
		sub_0328A5(x);
		break;
	case 8:
		sub_0328C1(x);
		break;
	case 10:
		sub_0328D1(x);
		break;
	case -18:
		u = sub_0326EE(x);
		break;
	case -16:
		sub_03270B(x);
		break;
	case -14:
		y = sub_032730(x, y);
		break;
	case -12:
		y = sub_032743(x, y);
		break;
	case -10:
		y = sub_032773(x, y);
		break;
	case -8:
		sub_032796(x);
		break;
	case -6:
		sub_0327E2(x);
		break;
	case -4:
		y = sub_03280A(x, y);
		break;
	case -2:
		sub_032852(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_03203F(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_0338B8_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_032148(x, &y, &u);
		break;
	case 2:
	case 4:
		u = sub_0321A8(x, u);
		break;
	case 6:
		sub_0320F6(x);
		break;
	case 8:
		y = sub_032115(x, y);
		break;
	case 10:
		sub_032203(x, &y, &u);
		break;
	case 12:
		y = sub_032107(x, y);
		break;
	case 14:
		sub_032085(x);
		break;
	case 16:
		sub_03209A(x);
		break;
	case 18:
		sub_0320C9(x);
		break;
	case 20:
		sub_0320EA(x);
		break;
	case -4:
		sub_03207C(x, &y, &u);
		break;
	case -2:
		sub_032178(x);
		break;
	}
	u = sub_03206B(x, u);
	carry = sub_078683(x, carry);
	*p_y = y;
	*p_u = u;
}

void sub_032042(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_033BC8_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_032AF7(x, &y, &u);
		break;
	case 2:
		sub_032B11(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_032045(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t u = 0;
	uint8_t t1 = 0, t2 = 0;

	b = (uint8_t)d;
	u = 0x7AECu;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_03293A(x, &y, &u);
		break;
	case 2:
	case 4:
		sub_03294F();
		break;
	case 6:
		sub_032950(x);
		break;
	case 8:
		y = sub_032960(x);
		break;
	case 10:
		sub_03297D(x);
		break;
	case 12:
		sub_032980(x);
		break;
	case 14:
		sub_0329A4(x);
		break;
	case 16:
		sub_032919(x);
		break;
	case 18:
		sub_032930(x);
		break;
	case -4:
	case -2:
		sub_032910(x, &y, &u);
		break;
	}
	t1 = mem_read8(x + 2u);
	if ((int8_t)t1 >= 0)
	{
		t2 = mem_read8(x + 2u);
		if (t2 > 2u)
		{
			u = sub_078593(x, u);
			sub_0328F8(x);
		}
	}
	u = sub_0329CA(x, u);
	carry = sub_078683(x, carry);
	*p_y = y;
	*p_u = u;
}

void sub_032048(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		y = sub_032272(x);
		break;
	case 2:
	case 14:
	case 26:
		y = sub_032339(x, y);
		break;
	case 4:
	case 16:
	case 28:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case 6:
	case 18:
	case 30:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case 8:
	case 20:
	case 32:
		sub_07865C(x, &y, &ignored16);
		break;
	case 10:
	case 22:
	case 34:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	case 12:
		y = sub_032297(x);
		break;
	case 24:
		y = sub_032301(x);
		break;
	case 36:
		y = sub_0322E5(x, y);
		break;
	case 38:
		sub_0322EE(x);
		break;
	case 40:
		sub_0322F7(x);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_03204B(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		y = sub_032FF5(x);
		break;
	case 2:
		sub_033028(x);
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

uint16_t sub_03204E(uint16_t x, uint16_t y, uint8_t d)
{
	uint8_t b = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		y = sub_033226(x);
		break;
	case 2:
		sub_03329A(x);
		break;
	case 4:
		sub_033361(x);
		break;
	case 6:
		y = sub_0333AD(x, y);
		break;
	case 8:
		y = sub_0333F6(x, y);
		break;
	case -4:
		sub_033494(x);
		break;
	case -2:
		sub_03341C(x);
		break;
	}
	sub_078593(x, 0u);
	return y;
}

void sub_032051(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_033C10_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_032C89(x);
		break;
	case 2:
		sub_032CA5(x, &y, &u);
		break;
	case 4:
	case 42:
	case 100:
		sub_032C51(x);
		break;
	case -34:
	case -20:
	case 40:
		sub_032CE7(x, &y, &u);
		break;
	case -30:
	case -16:
	case 98:
		sub_032D25(x, &y, &u);
		break;
	case -40:
		sub_032B9B(x);
		break;
	case -38:
	case -26:
		sub_032BAE(x);
		break;
	case -36:
	case -22:
		sub_032CDE(x);
		break;
	case -32:
	case -18:
		sub_032D1C(x);
		break;
	case -28:
		sub_032BBC(x);
		break;
	case -24:
		sub_032BCF(x);
		break;
	case -14:
	case -2:
		sub_032C4B(x);
		break;
	case -12:
		sub_032C0B(x);
		break;
	case -10:
		y = sub_032C17(x, y);
		break;
	case -8:
		y = sub_032C28(x);
		break;
	case -6:
		y = sub_032C31(x, y);
		break;
	case -4:
		y = sub_032C42(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_032054(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_033E4A_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_03315D(x);
		break;
	case 2:
		y = sub_033168(x, y);
		break;
	case 4:
		y = sub_033192(x, y);
		break;
	case 6:
		sub_0331AA(x);
		break;
	case 8:
		sub_0331B5(x, &y, &u);
		break;
	case 10:
		sub_0331C5(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_032057(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_033E50_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_0331AA(x);
		break;
	case 2:
		sub_0331B5(x, &y, &u);
		break;
	case 4:
		sub_0331C5(x);
		break;
	case -6:
		sub_03315D(x);
		break;
	case -4:
		y = sub_033168(x, y);
		break;
	case -2:
		y = sub_033192(x, y);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_03205A(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_033E5E_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_0331D8(x, &y, &u);
		break;
	case 2:
		sub_0331FC();
		break;
	}
	carry = sub_078683(x, carry);
	*p_y = y;
	*p_u = u;
}

void sub_03205D(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_033FD5_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_033633(x, &y, &u);
		break;
	case 2:
		sub_033678(x);
		break;
	case 4:
		sub_03369A(x);
		break;
	case 6:
		sub_0336A7(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_03206B(uint16_t x, uint16_t u)
{
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 0x37u);
	if (t1 == 0u)
	{
		t2 = mem_read16(x + 0x2Au);
		u = t2;
		if (mem_read8(u) == 0u)
		{
			t3 = mem_read8(x + 0x37u);
			mem_write8(x + 0x37u, t3 + 1u);
		}
	}
	return u;
}

void sub_03207C(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_0338C6_ADDRESS;
		t1 = mem_read8(x + 0x29u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			sub_032085(x);
			break;
		case 2:
			sub_03209A(x);
			break;
		case 4:
			sub_0320C9(x);
			break;
		case 6:
			sub_0320EA(x);
			break;
		case -18:
			continue;
		case -16:
			sub_032178(x);
			break;
		case -14:
			sub_032148(x, &y, &u);
			break;
		case -12:
		case -10:
			u = sub_0321A8(x, u);
			break;
		case -8:
			sub_0320F6(x);
			break;
		case -6:
			y = sub_032115(x, y);
			break;
		case -4:
			sub_032203(x, &y, &u);
			break;
		case -2:
			y = sub_032107(x, y);
			break;
		}
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_032085(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write16(x + 0xAu, 0x4040u);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write16(x + 0x19u, 0x200u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	sub_03209A(x);
}

void sub_03209A(uint16_t x)
{
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = mem_read16(x + 0x16u);
	if (t1 < 0x40u)
		return;
	t2 = unk_48AC;
	if (t2 > 0x3A2u)
	{
		mem_write8(x + 5u, 0x95u);
		mem_write8(x + 0x29u, 3u);
		return;
	}
	mem_write8(x + 5u, 0x94u);
	mem_write16(x + 0x14u, 0x100u);
	mem_write8(x + 0x3Bu, 0x40u);
	t3 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t3 + 1u);
}

void sub_0320C9(uint16_t x)
{
	uint8_t t2 = 0;
	uint16_t t1 = 0, t3 = 0;

	t1 = mem_read16(x + 0x19u);
	mem_write16(x + 0x19u, t1 - 0x10u);
	t2 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t2 - 1u);
	if (t2 != 1u)
	{
		t3 = mem_read16(x + 0xAu);
		mem_write16(x + 0xAu, t3 + 0x303u);
		mem_write8(x, 0x90u);
		return;
	}
	mem_write8(x, 0u);
}

void sub_0320EA(uint16_t x)
{
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x16u);
	if (t1 >= 0xF0u)
		mem_write8(x, 0u);
}

void sub_0320F6(uint16_t x)
{
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write8(x, 0x80u);
	mem_write8(x + 2u, 2u);
}

uint16_t sub_032107(uint16_t x, uint16_t y)
{
	uint16_t t1 = 0;

	mem_write16(x + 0xFu, 0x200u);
	if ((int8_t)unk_4858 >= 0)
		return sub_032115(x, y);
	t1 = mem_read16(x + 0xFu);
	mem_write16(x + 0xFu, 0u - t1);
	return sub_032115(x, y);
}

uint16_t sub_032115(uint16_t x, uint16_t y)
{
	uint16_t y_2 = 0;
	uint16_t t1 = 0;

	t1 = unk_48AC;
	if (t1 > 0x3A2u)
	{
		mem_write8(x + 2u, 0xFEu);
		mem_write16(x + 0x28u, 0u);
		return y;
	}
	mem_write8(x, 0x80u);
	mem_write8(x + 5u, 0x93u);
	y_2 = hit_box_0338AC_ADDRESS;
	sub_0785B4(x, y_2);
	sub_0785C6(x);
	mem_write16(x + 0x19u, 0xFF00u);
	mem_write8(x + 2u, 5u);
	mem_write16(x + 0x28u, 0u);
	return y_2;
}

void sub_032148(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;

	u = object_setup_0338CE_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x + VIDEO_003C, 3u);
	mem_write16(x + 0x5Cu, 0u);
	mem_write8(x + 9u, 0x10u);
	mem_write8(x, 0x90u);
	mem_write16(x + 0x14u, 0xFF80u);
	mem_write16(x + 0x19u, 0x200u);
	mem_write16(x + 0xAu, 0xFFFFu);
	mem_write8(x + 2u, 0xFFu);
	*p_y = y;
	*p_u = u;
}

void sub_032178(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = mem_read16(x + 0x19u);
	mem_write16(x + 0x19u, t1 - 0x10u);
	carry = sub_078662(x);
	if (carry)
	{
		mem_write16(x + 0x14u, 0u);
		mem_write8(x, 0xC0u);
		mem_write8(x + 2u, 1u);
		return;
	}
	t2 = mem_read16(x + 0xAu);
	d = t2 - 0x808u;
	if (d >= 0x4040u)
	{
		mem_write16(x + 0xAu, d);
		mem_write8(x, 0x90u);
	}
}

uint16_t sub_0321A8(uint16_t x, uint16_t u)
{
	uint32_t negative = 0;
	uint8_t a = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t12 = 0, t13 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t14 = 0, t15 = 0;

	t1 = mem_read8(x + 0x58u);
	if (t1 != 0u)
		return u;
	if ((unk_4815 & 0x3Fu) == 0u)
	{
		u = sub_078620(x);
		t2 = mem_read16(x + 0xCu);
		t3 = mem_read16(u + 0xCu);
		t4 = t2 - t3;
		t5 = t4;
		t6 = t5 >> 15 ? 0u - t5 : t5;
		if (t6 < 0x40u)
		{
			t7 = mem_read16(x + 0x11u);
			t8 = mem_read16(u + 0x11u);
			t9 = t7 - t8;
			t10 = t9;
			t11 = t10 >> 15 ? 0u - t10 : t10;
			if (t11 < 0x40u)
			{
				mem_write16(x + 0xFu, 0u);
				mem_write16(x + 0x14u, 0u);
				t12 = mem_read8(x + 0x37u);
				if (t12 != 0u)
				{
					mem_write8(x, 0x80u);
					mem_write8(x + 2u, 0xFEu);
					mem_write16(x + 0x28u, 0u);
				}
				return u;
			}
		}
		t13 = mem_read8(x + 0x30u);
		d = t13;
		d = sub_078671(x, u, d);
		a = (uint8_t)(d >> 8);
		d = ((uint32_t)a << 8) | 0x10u;
		sub_078617(x, d);
	}
	t14 = mem_read16(x + 0xFu);
	if (t14 == 0u)
	{
		t12 = mem_read8(x + 0x37u);
		if (t12 != 0u)
		{
			mem_write8(x, 0x80u);
			mem_write8(x + 2u, 0xFEu);
			mem_write16(x + 0x28u, 0u);
		}
		return u;
	}
	t15 = mem_read16(x + 0x14u);
	if (t15 == 0u)
	{
		t12 = mem_read8(x + 0x37u);
		if (t12 != 0u)
		{
			mem_write8(x, 0x80u);
			mem_write8(x + 2u, 0xFEu);
			mem_write16(x + 0x28u, 0u);
		}
		return u;
	}
	sub_07863B(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	if ((int8_t)a >= 0)
	{
		t12 = mem_read8(x + 0x37u);
		if (t12 != 0u)
		{
			mem_write8(x, 0x80u);
			mem_write8(x + 2u, 0xFEu);
			mem_write16(x + 0x28u, 0u);
		}
		return u;
	}
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	t12 = mem_read8(x + 0x37u);
	if (t12 != 0u)
	{
		mem_write8(x, 0x80u);
		mem_write8(x + 2u, 0xFEu);
		mem_write16(x + 0x28u, 0u);
	}
	return u;
}

void sub_032203(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t t1 = 0;

	u = loaded_table_0338D4_ADDRESS;
	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		y = sub_03220C(x, y);
		break;
	case 2:
		sub_032242(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_03220C(uint16_t x, uint16_t y)
{
	uint16_t y_2 = 0;
	uint8_t t4 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read16(x + 0xCu);
	if (t1 >= 0x60 && t1 <= 0x15F)
	{
		t2 = mem_read16(x + 0x19u);
		mem_write16(x + 0x19u, t2 + 0x18u);
		sub_078674(x);
		return y;
	}
	t3 = mem_read16(x + 0xFu);
	mem_write16(x + 0xFu, 0u - t3);
	mem_write16(x + 0x19u, 0x180u);
	t4 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t4 + 1u);
	mem_write8(x + 5u, 0x95u);
	mem_write8(x + 0x58u, 0u);
	mem_write8(x, 0x88u);
	y_2 = hit_box_0338A4_ADDRESS;
	sub_0785B4(x, y_2);
	return y_2;
}

void sub_032242(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;
	uint8_t t1 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry == 0u)
		return;
	mem_write16(x + 0xFu, 0u);
	t1 = mem_read8(x + VIDEO_003C);
	mem_write8(x + VIDEO_003C, t1 - 1u);
	if (t1 != 1u)
		mem_write8(x, 0xC0u);
	else
		mem_write8(x + 0x37u, 1u);
	mem_write8(x + 5u, 0x92u);
	mem_write8(x + 2u, 2u);
}

uint16_t sub_032272(uint16_t x)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0;

	u = object_setup_033A32_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write16(x + 0x2Au, enemy_behaviour_0339B0_ADDRESS);
	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t1 & 0x30u) | 0x86u);
	sub_03230D(x);
	return y;
}

uint16_t sub_032297(uint16_t x)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0;

	u = object_setup_033A32_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write16(x + 0x2Au, enemy_behaviour_033900_ADDRESS);
	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t1 & 0x30u) | 0x86u);
	sub_03230D(x);
	return y;
}

uint16_t sub_0322E5(uint16_t x, uint16_t y)
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
			sub_0322EE(x);
			return y;
		case 2:
			break;
		case -38:
			return sub_032272(x);
		case -36:
		case -24:
		case -12:
			return sub_032339(x, y);
		case -34:
		case -22:
		case -10:
			sub_0785DB(x, &y, &ignored16, &ignored);
			return y;
		case -32:
		case -20:
		case -8:
			sub_0785DE(x, &y, &ignored16, &ignored);
			return y;
		case -30:
		case -18:
		case -6:
			sub_07865C(x, &y, &ignored16);
			return y;
		case -28:
		case -16:
		case -4:
			sub_0785E4(x, &y, &ignored16, &ignored);
			return y;
		case -26:
			return sub_032297(x);
		case -14:
			return sub_032301(x);
		case -2:
			continue;
		}
		break;
	}
	sub_0322F7(x);
	return y;
}

void sub_0322EE(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 5u, 0x95u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

void sub_0322F7(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
		mem_write8(x, 0u);
}

uint16_t sub_032301(uint16_t x)
{
	uint16_t u = 0, y = 0;

	u = object_setup_033A32_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write16(x + 0x2Au, enemy_behaviour_033958_ADDRESS);
	sub_03230D(x);
	return y;
}

void sub_03230D(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t1 = 0, t2 = 0;

	mem_write8(x + 0x42u, 1u);
	u = sub_078620(x);
	sub_078626(x, u);
	mem_write8(x + 0x43u, 1u);
	mem_write8(x + 0x3Au, 0x10u);
	t1 = mem_read8(x + 0x30u);
	if (t1 == 0u)
	{
		mem_write8(x + 0x30u, 0u);
		mem_write8(x + 2u, 2u);
		return;
	}
	mem_write8(x, 4u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
}

uint16_t sub_032339(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_032342(x);
		return y;
	case 2:
		sub_032351(x);
		return y;
	case 4:
		sub_032376(x);
		return y;
	case 6:
	case 34:
		sub_03237F(x);
		return y;
	case 8:
		sub_032392(x);
		return y;
	case 10:
		sub_0323A1(x);
		return y;
	case 12:
		sub_0323C4(x);
		return y;
	case 14:
		sub_0323E8(x);
		return y;
	case 16:
		sub_03241A(x);
		return y;
	case 18:
		sub_032438(x);
		return y;
	case 20:
	case 30:
		sub_032465(x);
		return y;
	case 22:
	case 32:
		sub_032468(x);
		return y;
	case 24:
		sub_032484(x);
		return y;
	case 26:
		sub_0324B4(x);
		return y;
	case 28:
		sub_0324D1(x);
		return y;
	case 36:
		return sub_0324E3(x, y, 0u);
	case 38:
		sub_0324F5(x);
		return y;
	case 40:
		sub_03250A(x);
		return y;
	case 42:
		sub_032520(x);
		return y;
	case 44:
		sub_032539(x);
		return y;
	case 46:
		sub_032542(x);
		return y;
	case 48:
		sub_03255B(x);
		return y;
	case 50:
		sub_03256B(x);
		return y;
	case 52:
		sub_032590(x);
		return y;
	case 54:
		sub_0325A2(x);
		return y;
	case 56:
		sub_0325C4(x);
		return y;
	}
	unreachable();
}

void sub_032342(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x30u);
	mem_write8(x + 0x29u, kind_a1_entrance_steps[(int8_t)t1]);
	mem_write8(x + 0x30u, 0u);
}

void sub_032351(uint16_t x)
{
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	mem_write8(x, 0xC0u);
	mem_write8(x + 0x3Bu, 0x30u);
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
	sub_0785C6(x);
}

void sub_032376(uint16_t x)
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

void sub_03237F(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	mem_write8(x, 0x80u);
	mem_write8(x + 5u, 0x96u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	d = 0x6C00u;
	carry = sub_078680(d);
}

void sub_032392(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		mem_write8(x, 0xC0u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_0323A1(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t1 & 0xCFu) | 0x20u);
	mem_write8(x + 5u, 0xA6u);
	mem_write16(x + 0x19u, 0x100u);
	mem_write8(x + 0x3Bu, 0x80u);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
}

void sub_0323C4(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		t2 = mem_read8(x + 9u);
		mem_write8(x + 9u, (t2 & 0xCFu) | 0x10u);
		mem_write16(x + 0x14u, 0xFE00u);
		mem_write16(x + 0x19u, 0x100u);
		mem_write8(x + 5u, 0x84u);
		t3 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t3 + 1u);
	}
}

void sub_0323E8(uint16_t x)
{
	uint32_t negative = 0, carry = 0;
	uint8_t a = 0;
	uint16_t d = 0;
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0, t4 = 0;

	t1 = mem_read16(x + 0x19u);
	t2 = t1 - 0x20u;
	mem_write16(x + 0x19u, t2);
	carry = sub_078662(x);
	if (carry)
	{
		mem_write8(x, 0xC0u);
		mem_write16(x + 0x14u, 0u);
		t3 = mem_read8(x + 2u);
		mem_write8(x + 2u, t3 + 1u);
		return;
	}
	t4 = mem_read16(x + 0x14u);
	if (t4 == 0u)
		return;
	d = 0u;
	sub_078638(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	if ((int8_t)a >= 0)
	{
		mem_write8(x + 0x5Du, (((a & 0xFu) << 1) << 1) << 1);
		mem_write16(x + 0x14u, 0u);
	}
}

void sub_03241A(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t1 & 0xCFu) | 0x20u);
	mem_write8(x + 5u, 0x84u);
	mem_write16(x + 0x19u, 0x600u);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
}

void sub_032438(uint16_t x)
{
	mem_write16(x + 0x14u, 0xFE00u);
	sub_03243E(x);
}

void sub_03243E(uint16_t x)
{
	uint32_t negative = 0;
	uint8_t a = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	d = 0u;
	sub_078638(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	if ((int8_t)a < 0)
	{
		sub_032468(x);
		return;
	}
	a = (((a & 0xFu) << 1) << 1) << 1;
	t1 = mem_read8(x + 0x17u);
	if (t1 <= a)
	{
		sub_032465(x);
		return;
	}
	mem_write8(x + 0x5Du, a);
	mem_write8(x, 0x88u);
	t2 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t2 & 0xCFu) | 0x10u);
	t3 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t3 + 1u);
}

void sub_032465(uint16_t x)
{
	mem_write16(x + 0x14u, 0u);
	sub_032468(x);
}

void sub_032468(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = mem_read16(x + 0x19u);
	t2 = t1 - 0x20u;
	mem_write16(x + 0x19u, t2);
	carry = sub_078662(x);
	if (carry)
	{
		mem_write8(x + 5u, 0x9Eu);
		mem_write8(x, 0xC0u);
		t3 = mem_read8(x + 2u);
		mem_write8(x + 2u, t3 + 1u);
	}
}

void sub_032484(uint16_t x)
{
	uint8_t t1 = 0, t4 = 0;
	uint16_t t2 = 0, t3 = 0;

	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t1 & 0xCFu) | 0x10u);
	mem_write8(x + 0x3Bu, 0x20u);
	mem_write8(x + 5u, 0x90u);
	mem_write16(x + 0xFu, 0x200u);
	t2 = mem_read16(x + 0xCu);
	if (t2 >= 0xE0u)
	{
		t3 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t3);
	}
	t4 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t4 + 1u);
	sub_0785C6(x);
}

void sub_0324B4(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x19u, 0x400u);
		mem_write8(x + 5u, 0x98u);
		mem_write16(x + 0x5Cu, 0x20u);
		t2 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t2 + 1u);
	}
}

void sub_0324D1(uint16_t x)
{
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x16u);
	if (t1 < 0x28u)
	{
		sub_03243E(x);
		return;
	}
	mem_write16(x + 0x14u, 0x400u);
	sub_03243E(x);
}

uint16_t sub_0324E3(uint16_t x, uint16_t y, uint32_t u)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
		return y;
	y = child_object_033A7D_ADDRESS;
	sub_07862C(x, y, &ignored16, &ignored16_2, &carry);
	if (carry == 0u)
	{
		mem_write8(x, 0xC0u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
		return y;
	}
	t3 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t3 + 1u);
	return y;
}

void sub_0324F5(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	d = 0x2800u;
	carry = sub_078680(d);
	mem_write8(x + 0x3Bu, 0x40u);
	mem_write16(x + 0xFu, 0x100u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

void sub_03250A(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	mem_write8(x, mem_read8(x) ^ 0x84u);
	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x, 0xC0u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_032520(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x, 0x80u);
	mem_write8(x + 5u, 0x97u);
	mem_write8(x + 0x3Bu, 0x40u);
	mem_write16(x + 0xFu, 0xFF00u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 - 1u);
}

void sub_032539(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 0x3Bu, 8u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

void sub_032542(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x, 0x80u);
		mem_write8(x + 5u, 0x81u);
		mem_write16(x + 0x14u, 0xFF00u);
		t2 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t2 + 1u);
	}
}

void sub_03255B(uint16_t x)
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
		mem_write8(x, 0xC0u);
		t1 = mem_read8(x + 2u);
		mem_write8(x + 2u, t1 + 1u);
	}
}

void sub_03256B(uint16_t x)
{
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	mem_write8(x, 0xC0u);
	mem_write8(x + VIDEO_003C, 3u);
	mem_write8(x + 5u, 0xA2u);
	mem_write16(x + 0xFu, 0x200u);
	t1 = mem_read8(x + 0x36u);
	if ((int8_t)(t1 - 0x40u) >= 0)
	{
		t2 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t2);
	}
	t3 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t3 + 1u);
	sub_0785C6(x);
}

void sub_032590(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		t2 = mem_read8(x + VIDEO_003C);
		mem_write8(x + VIDEO_003C, t2 - 1u);
		if (t2 == 1u)
		{
			mem_write16(x + 0xFu, 0u);
			t3 = mem_read8(x + 2u);
			mem_write8(x + 2u, t3 + 1u);
		}
	}
}

void sub_0325A2(uint16_t x)
{
	uint32_t negative = 0;
	uint8_t a = 0;
	uint16_t d = 0, u = 0;
	uint8_t t1 = 0;

	mem_write8(x, 0xC8u);
	mem_write8(x + 5u, 0x84u);
	u = sub_078620(x);
	sub_078626(x, u);
	d = 0u;
	sub_078638(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	mem_write8(x + 0x5Du, (((a & 0xFu) << 1) << 1) << 1);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	sub_0785C9(x);
}

void sub_0325C4(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x19u);
	mem_write16(x + 0x19u, t1 - 0x20u);
	carry = sub_078662(x);
	if (carry)
	{
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_0325DC(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 5u, 0x99u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	sub_07859C(x);
}

uint16_t sub_0325E7(uint16_t x, uint16_t y)
{
	uint16_t y_2 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;
	uint16_t t4 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) == 0u)
		return y;
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	mem_write16(x + 0xFu, 0x200u);
	t3 = mem_read8(x + 9u);
	if ((t3 & 0x40u) == 0u)
	{
		t4 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t4);
	}
	y_2 = hit_box_0338E8_ADDRESS;
	sub_0785B4(x, y_2);
	return y_2;
}

void sub_03260E(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 5u, 0x92u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	sub_07859C(x);
}

void sub_032619(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t u_2 = 0, y_2 = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) == 0u)
		return;
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	y_2 = child_object_033A93_ADDRESS;
	*p_u = u_2;
	sub_07862F(x, y_2, p_u, &carry);
	*p_y = y_2;
}

void sub_032651(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint8_t a = 0;
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t4 = 0;
	uint16_t t3 = 0;

	u = object_setup_033A9D_ADDRESS;
	y = sub_0785AB(x, u);
	t1 = mem_read8(x + 0x47u);
	a = t1;
	if ((int8_t)t1 >= 0)
		mem_write8(x + 0x5Du, (((a & 0xFu) << 1) << 1) << 1);
	mem_write16(x + 0xFu, 0x400u);
	t2 = mem_read8(x + 9u);
	if ((t2 & 0x40u) != 0u)
	{
		t3 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t3);
	}
	t4 = mem_read8(x + 2u);
	mem_write8(x + 2u, t4 + 1u);
	sub_032677();
	*p_y = y;
	*p_u = u;
}

void sub_032677(void)
{
}

void sub_03267E(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 5u, 0x91u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	sub_07859C(x);
}

uint16_t sub_032689(uint16_t x, uint16_t y)
{
	uint16_t y_2 = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) == 0u)
		return y;
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	y_2 = hit_box_0338E8_ADDRESS;
	sub_0785B4(x, y_2);
	return y_2;
}

uint16_t sub_0326A0(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t1 = 0;

	mem_write8(x + 5u, 0xA7u);
	u = kind_a1_attack_delays_by_players_ADDRESS;
	mem_write8(x + 0x3Bu, kind_a1_attack_delays_by_players[(int8_t)unk_4857]);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	return u;
}

void sub_0326B4(uint16_t x)
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

uint16_t sub_0326C4(uint16_t x, uint16_t y)
{
	uint16_t y_2 = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) == 0u)
		return y;
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	y_2 = hit_box_0338F8_ADDRESS;
	sub_0785B4(x, y_2);
	return y_2;
}

uint16_t sub_0326D5(uint16_t x)
{
	uint16_t y = 0;
	uint8_t t1 = 0;

	y = hit_box_0338D8_ADDRESS;
	sub_0785B4(x, y);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	sub_0326DE(x);
	return y;
}

void sub_0326DE(uint16_t x)
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

uint16_t sub_0326EE(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t2 = 0, t3 = 0;
	uint16_t t1 = 0;

	mem_write8(x + 5u, 0x9Au);
	sub_07859C(x);
	t1 = mem_read16(x + 0x38u);
	u = t1;
	sub_078626(x, u);
	t2 = mem_read8(x + 0x36u);
	mem_write8(x + 0x35u, t2);
	mem_write8(x + VIDEO_003C, 2u);
	t3 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t3 + 1u);
	return u;
}

void sub_03270B(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0, t4 = 0;
	uint16_t t3 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
		return;
	mem_write8(x + 5u, 0x98u);
	mem_write16(x + 0xFu, 0x100u);
	t2 = mem_read8(x + 0x35u);
	if ((int8_t)(t2 - 0x40u) >= 0)
	{
		t3 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t3);
	}
	mem_write16(x + 0x19u, 0x600u);
	t4 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t4 + 1u);
}

uint16_t sub_032730(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		t2 = mem_read8(x + VIDEO_003C);
		mem_write8(x + VIDEO_003C, t2 - 1u);
		if (t2 == 1u)
		{
			mem_write8(x + 5u, 0x9Cu);
			t3 = mem_read8(x + 0x29u);
			mem_write8(x + 0x29u, t3 + 1u);
			return sub_032743(x, y);
		}
	}
	return sub_032743(x, y);
}

uint16_t sub_032743(uint16_t x, uint16_t y)
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
			y = hit_box_0338F0_ADDRESS;
			sub_0785B4(x, y);
		}
	}
	else
	{
		mem_write8(x + 5u, 0x9Du);
		y = hit_box_0338D8_ADDRESS;
		sub_0785B4(x, y);
		t4 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t4 + 1u);
	}
	t5 = mem_read16(x + 0x19u);
	d = t5 - 0x20u;
	return sub_032779(x, y, d);
}

uint16_t sub_032773(uint16_t x, uint16_t y)
{
	uint16_t d = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x19u);
	d = t1 - 0x10u;
	return sub_032779(x, y, d);
}

uint16_t sub_032779(uint16_t x, uint16_t y, uint16_t d)
{
	uint32_t carry = 0;
	uint16_t y_2 = 0;

	mem_write16(x + 0x19u, d);
	carry = sub_078662(x);
	if (carry == 0u)
		return y;
	y_2 = hit_box_0338D8_ADDRESS;
	sub_0785B4(x, y_2);
	mem_write8(x + 5u, 0x9Du);
	mem_write8(x + 2u, 2u);
	mem_write8(x + 0x3Bu, 0u);
	return y_2;
}

void sub_032796(uint16_t x)
{
	uint8_t t3 = 0, t5 = 0, t6 = 0;
	uint16_t t1 = 0, t2 = 0, t4 = 0, t7 = 0;

	mem_write8(x + 0x3Du, 0u);
	t1 = mem_read16(x + 0xCu);
	t2 = t1 - 0x40u;
	if (t2 >= 0x140u)
	{
		t3 = mem_read8(x + 0x3Du);
		mem_write8(x + 0x3Du, t3 + 1u);
	}
	t4 = mem_read16(x + 0x2Cu);
	if (t4 >= 0x80u)
	{
		mem_write8(x + 5u, 0xA2u);
		t5 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t5 + 1u);
	}
	else
	{
		mem_write8(x + 5u, 0x98u);
		mem_write16(x + 0x19u, 0x500u);
		mem_write8(x + 0x29u, 2u);
	}
	sub_07859C(x);
	mem_write16(x + 0xFu, 0x200u);
	t6 = mem_read8(x + 9u);
	if ((t6 & 0x40u) != 0u)
	{
		t7 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t7);
	}
	mem_write8(x + 0x3Bu, 3u);
}

void sub_0327E2(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t3 = 0, t4 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
		return;
	t2 = mem_read16(x + 0x2Cu);
	if (t2 >= 0x80u)
	{
		t3 = mem_read8(x + 0x3Bu);
		mem_write8(x + 0x3Bu, t3 - 1u);
		if (t3 == 1u)
			mem_write8(x + 0x29u, 3u);
		return;
	}
	mem_write16(x + 0x19u, 0x500u);
	mem_write8(x + 5u, 0x98u);
	t4 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t4 + 1u);
}

uint16_t sub_03280A(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t y_2 = 0;
	uint8_t t2 = 0, t5 = 0;
	uint16_t t1 = 0, t3 = 0, t4 = 0;

	t1 = mem_read16(x + 0x19u);
	mem_write16(x + 0x19u, t1 - 0x20u);
	carry = sub_078662(x);
	if (carry)
	{
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x28u, 0x2B00u);
		y_2 = hit_box_0338D8_ADDRESS;
		sub_0785B4(x, y_2);
		return y_2;
	}
	t2 = mem_read8(x + 0x3Du);
	if (t2 == 0u)
	{
		t3 = mem_read16(x + 0xCu);
		if (t3 < 0x48 || t3 > 0x177)
		{
			t4 = mem_read16(x + 0xFu);
			mem_write16(x + 0xFu, 0u - t4);
			mem_write16(x + 0x19u, 0x200u);
			mem_write8(x + 5u, 0x84u);
			y_2 = hit_box_0338F0_ADDRESS;
			sub_0785B4(x, y_2);
			t5 = mem_read8(x + 0x3Du);
			mem_write8(x + 0x3Du, t5 + 1u);
			sub_0785C6(x);
			return y_2;
		}
	}
	return y;
}

void sub_032852(uint16_t x)
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

void sub_032862(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 5u, 0x95u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

void sub_03286B(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) == 0u)
		return;
	mem_write8(x, 0x80u);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	d = 0x6C00u;
	carry = sub_078680(d);
}

void sub_032881(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0, t4 = 0;
	uint16_t t3 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
		return;
	mem_write8(x, 4u);
	mem_write16(x + 0xFu, 0x200u);
	t2 = mem_read8(x + 0x36u);
	if ((int8_t)(t2 - 0x40u) >= 0)
	{
		t3 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t3);
	}
	mem_write8(x + 0x3Bu, 0x40u);
	t4 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t4 + 1u);
}

void sub_0328A5(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write16(x + 0xFu, 0u);
	mem_write8(x, 0x80u);
	mem_write8(x + 5u, 0x96u);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	d = 0x6C00u;
	carry = sub_078680(d);
}

void sub_0328C1(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) != 0u)
	{
		mem_write8(x, 0xC0u);
		t2 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t2 + 1u);
	}
}

void sub_0328D1(uint16_t x)
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

void sub_0328F8(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 2u);
	if (t1 == 5u && (mem_read8(x) & 0x20u) != 0u)
	{
		mem_write8(x + 2u, 0xFFu);
		mem_write8(x + 0x28u, 0u);
	}
}

void sub_032910(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = 0x7AFCu;
		t1 = mem_read8(x + 0x28u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			sub_032919(x);
			break;
		case 2:
			sub_032930(x);
			break;
		case -20:
		case -18:
			continue;
		case -16:
			sub_03293A(x, &y, &u);
			break;
		case -14:
		case -12:
			sub_03294F();
			break;
		case -10:
			sub_032950(x);
			break;
		case -8:
			y = sub_032960(x);
			break;
		case -6:
			sub_03297D(x);
			break;
		case -4:
			sub_032980(x);
			break;
		case -2:
			sub_0329A4(x);
			break;
		}
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_032919(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x, 0x80u);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x19u, 0x80u);
	mem_write8(x + 5u, 0x80u);
	t1 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t1 + 1u);
}

void sub_032930(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
		mem_write8(x, 0u);
}

void sub_03293A(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	u = object_setup_033B00_ADDRESS;
	y = sub_0785AB(x, u);
	t1 = mem_read8(x + 0x30u);
	mem_write8(x + 5u, t1 | 0x80u);
	t2 = mem_read8(x + VIDEO_0031);
	mem_write8(x + VIDEO_0031, t2 + 1u);
	t3 = mem_read8(x + 2u);
	mem_write8(x + 2u, t3 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_03294F(void)
{
}

void sub_032950(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + VIDEO_0031, 0u);
	mem_write8(x + 0x3Du, 1u);
	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 - 1u);
}

uint16_t sub_032960(uint16_t x)
{
	uint16_t y = 0;
	uint8_t t1 = 0, t2 = 0;

	mem_write8(x, 0x80u);
	mem_write8(x + 0x3Du, 0u);
	t1 = mem_read8(x + 5u);
	mem_write8(x + 5u, (t1 + 1u) | 0x80u);
	y = hit_box_033AE0_ADDRESS;
	sub_0785B4(x, y);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	sub_0785C6(x);
	sub_03297D(x);
	return y;
}

void sub_03297D(uint16_t x)
{
	sub_078674(x);
}

void sub_032980(uint16_t x)
{
	uint32_t negative = 0;
	uint8_t a = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	mem_write8(x, 0x88u);
	mem_write16(x + 0x19u, 0x800u);
	d = 0u;
	sub_078638(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	mem_write8(x + 0x5Du, (((a & 0xFu) << 1) << 1) << 1);
	t1 = mem_read8(x + 5u);
	mem_write8(x + 5u, (t1 + 1u) | 0x80u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
}

void sub_0329A4(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry)
	{
		mem_write8(x + 2u, 0xFFu);
		mem_write8(x + 0x28u, 0u);
	}
}

uint16_t sub_0329CA(uint16_t x, uint16_t u)
{
	uint32_t negative = 0;
	uint8_t a = 0;
	uint16_t d = 0, u_2 = 0;
	uint8_t t1 = 0, t2 = 0, t4 = 0, t5 = 0, t10 = 0;
	uint16_t t3 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0;

	t1 = mem_read8(x + VIDEO_0031);
	if (t1 != 0u)
		return u;
	t2 = mem_read8(x + 0x3Du);
	if (t2 != 0u)
	{
		t3 = mem_read16(x + 0x40u);
		u_2 = t3;
		t4 = mem_read8(u_2 + 9u);
		unk_48F0 = t4 & 0x30u;
		t5 = mem_read8(x + 9u);
		mem_write8(x + 9u, (t5 & 0xCFu) | unk_48F0);
		return u_2;
	}
	d = 0u;
	sub_078638(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	unk_48F0 = a;
	if ((int8_t)a < 0)
	{
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
		mem_write8(x + 2u, 0xFEu);
		return u;
	}
	mem_write8(x + 0x5Du, (((a & 0xFu) << 1) << 1) << 1);
	t6 = mem_read16(x + 0x16u);
	t7 = mem_read16(x + 0x5Cu);
	if (t6 != t7)
		a = mem_read8(x) | 8u;
	else
		a = mem_read8(x) & ~8u;
	mem_write8(x, a);
	sub_07863B(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	unk_48F1 = a;
	if (a == unk_48F0)
		return u;
	if ((int8_t)a >= 0)
	{
		t8 = (unk_48F1 & 0xFu) << 3;
		t9 = mem_read16(x + 0x16u);
		if (t8 < t9)
		{
			unk_48F2 = unk_48F1 & 0x30u;
			t10 = mem_read8(x + 9u);
			mem_write8(x + 9u, (t10 & 0xCFu) | unk_48F2);
			return u;
		}
	}
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write8(x + 2u, 0xFEu);
	return u;
}

void sub_032A3F(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t d = 0, piece = 0, u = 0, y = 0;
	uint8_t t1 = 0, animation = 0, direction = 0, t2 = 0;
	uint16_t rise = 0;

	u = object_setup_033B00_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 4u);
	mem_write8(x + 4u, 0x8Fu);
	t1 = mem_read8(x + 0x30u);
	piece = robot_pieces_ADDRESS + (int8_t)(((uint32_t)t1 << 1) << 1);
	rise = (((uint32_t)ROBOT_PIECE(piece)->rise << 8u) | ROBOT_PIECE(piece)->wait);
	mem_write8(x + 0x19u, rise >> 8);
	mem_write8(x + 0x3Bu, rise);
	animation = ROBOT_PIECE(piece)->animation;
	mem_write8(x + 5u, animation | 0x80u);
	direction = ROBOT_PIECE(piece)->direction;
	d = ((uint32_t)direction << 8) | 0x20u;
	sub_078617(x, d);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	*p_y = y;
	*p_u = piece;
}

void sub_032A75(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x, 0x88u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_032A83(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x19u);
	mem_write16(x + 0x19u, t1 - 0x40u);
	carry = sub_078662(x);
	if (carry)
	{
		mem_write16(x + 0x19u, 0x200u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
	sub_032ABD(x);
}

void sub_032A9C(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = mem_read16(x + 0x19u);
	t2 = t1 - 0x30u;
	mem_write16(x + 0x19u, t2);
	carry = sub_078662(x);
	if (carry == 0u)
	{
		sub_032ABD(x);
		return;
	}
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write8(x + 4u, 4u);
	mem_write8(x + 5u, 0x80u);
	t3 = mem_read8(x + 2u);
	mem_write8(x + 2u, t3 + 1u);
	sub_032ABD(x);
}

void sub_032ABD(uint16_t x)
{
	uint32_t negative = 0;
	uint16_t d = 0;
	uint16_t t1 = 0, t2 = 0;

	sub_078644(x, &d, &negative);
	if ((int8_t)(d >> 8) < 0)
	{
		t1 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t1);
	}
	sub_078647(x, &d, &negative);
	if ((int8_t)(d >> 8) < 0)
	{
		t2 = mem_read16(x + 0x14u);
		mem_write16(x + 0x14u, 0u - t2);
	}
}

void sub_032AD0(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
		return;
	t2 = mem_read8(x + 0x30u);
	if (t2 == 0u)
	{
		mem_write16(x + 1u, 0xF500u);
		mem_write16(x + 4u, 0x420u);
		mem_write8(x + 0x30u, 0x20u);
		return;
	}
	mem_write8(x, 0u);
}

void sub_032AF7(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0;

	u = object_setup_033BD0_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 0x40u);
	u = hit_spark_times_ADDRESS;
	t1 = mem_read8(x + 0x30u);
	mem_write8(x + 0x3Bu, hit_spark_times[(int8_t)t1]);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_032B11(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
		mem_write8(x, 0u);
}

uint16_t sub_032B4C(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0, u = 0, y = 0;
	uint8_t t1 = 0;

	u = object_setup_033BE2_ADDRESS;
	y = sub_0785AB(x, u);
	carry = (unk_4857 >> 0) & 1u;
	if (carry)
		mem_write8(x + 0x1Bu, 0x30u);
	u = sub_078620(x);
	sub_078626(x, u);
	mem_write8(x + VIDEO_003C, 4u);
	mem_write8(x + 0x43u, 1u);
	mem_write16(x + 0x2Au, enemy_behaviour_033B70_ADDRESS);
	mem_write8(x + 0x3Au, 0x10u);
	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t1 & ~0xFu) | 7u);
	mem_write8(x + 0x30u, 0u);
	mem_write8(x + 2u, 2u);
	unk_4880 = 1u;
	d = 0x9B00u;
	carry = sub_078689(d);
	return y;
}

void sub_032B9B(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	mem_write8(x + 5u, 0x8Bu);
	mem_write8(x + 0x3Bu, 0x40u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	d = 0x2700u;
	carry = sub_078680(d);
}

void sub_032BAE(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x, 0xC0u);
		t2 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t2 + 1u);
	}
}

void sub_032BBC(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	mem_write8(x + 5u, 0x8Bu);
	mem_write8(x + 0x3Bu, 0x20u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	d = 0x2700u;
	carry = sub_078680(d);
}

void sub_032BCF(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t1 & 0x7Fu) ^ 0x40u);
	t2 = mem_read8(x + 6u);
	mem_write8(x + 6u, t2 | 0x80u);
	t3 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t3 + 1u);
}

void unused_032BE5(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
		return;
	t2 = mem_read8(x + 9u);
	mem_write8(x + 9u, t2 & 0x7Fu);
	t3 = mem_read8(x + 6u);
	mem_write8(x + 6u, t3 | 0x80u);
	mem_write8(x + 2u, 2u);
	mem_write8(x + 0x3Bu, 0u);
}

void sub_032C0B(uint16_t x)
{
	uint8_t t1 = 0;

	sub_07859C(x);
	mem_write8(x + 5u, 0x90u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

uint16_t sub_032C17(uint16_t x, uint16_t y)
{
	uint16_t y_2 = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) == 0u)
		return y;
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	y_2 = hit_box_033B40_ADDRESS;
	sub_0785B4(x, y_2);
	return y_2;
}

uint16_t sub_032C28(uint16_t x)
{
	uint16_t y = 0;
	uint8_t t1 = 0;

	y = hit_box_033B38_ADDRESS;
	sub_0785B4(x, y);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	return sub_032C31(x, y);
}

uint16_t sub_032C31(uint16_t x, uint16_t y)
{
	uint16_t y_2 = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) == 0u)
		return y;
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	y_2 = hit_box_033B48_ADDRESS;
	sub_0785B4(x, y_2);
	return y_2;
}

uint16_t sub_032C42(uint16_t x)
{
	uint16_t y = 0;
	uint8_t t1 = 0;

	y = hit_box_033B38_ADDRESS;
	sub_0785B4(x, y);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	sub_032C4B(x);
	return y;
}

void sub_032C4B(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
		return;
	sub_032C51(x);
}

void sub_032C51(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	mem_write8(x + 0x43u, 0u);
	mem_write8(x, 0xC0u);
	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, t1 & 0x7Fu);
	t2 = mem_read8(x + 6u);
	mem_write8(x + 6u, t2 | 0x80u);
	mem_write8(x + 2u, 2u);
	mem_write8(x + 0x3Bu, 0u);
}

void sub_032C6D(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, t1 ^ 0x80u);
	t2 = mem_read8(x + 6u);
	mem_write8(x + 6u, t2 | 0x80u);
	mem_write8(x, 0xC4u);
}

void sub_032C89(uint16_t x)
{
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	sub_07859C(x);
	mem_write8(x + 5u, 0x9Du);
	mem_write16(x + 0xFu, 0x80u);
	t1 = mem_read8(x + 9u);
	if ((t1 & 0x40u) != 0u)
	{
		t2 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t2);
	}
	t3 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t3 + 1u);
}

void sub_032CA5(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d = 0, ignored16 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t5 = 0, t6 = 0;
	uint16_t t4 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) != 0u)
	{
		t2 = mem_read8(x + 7u);
		a = t2;
		if (a == 6u || a == 0xEu)
		{
			d = 0x2300u;
			carry = sub_078680(d);
		}
		t3 = mem_read8(x + 7u);
		t4 = robot_sparks_by_frame_9d[(int8_t)((uint8_t)((uint32_t)t3 << 1)) / 2];
		y = t4;
		if ((int16_t)t4 >= 0)
			sub_07862C(x, y, &u, &ignored16, &carry);
	}
	t5 = mem_read8(x + 6u);
	carry = (t5 >> 0) & 1u;
	if (carry)
	{
		t6 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t6 + 1u);
	}
	*p_y = y;
	*p_u = u;
}

void sub_032CDB(uint16_t x)
{
	sub_07859C(x);
	sub_032CDE(x);
}

void sub_032CDE(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 5u, 0x92u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

void sub_032CE7(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t5 = 0, t6 = 0;
	uint16_t t4 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) != 0u)
	{
		t2 = mem_read8(x + 7u);
		if (t2 == 6u)
		{
			d = 0x2300u;
			carry = sub_078680(d);
		}
		t3 = mem_read8(x + 7u);
		t4 = robot_sparks_by_frame_92[(int8_t)((uint8_t)((uint32_t)t3 << 1)) / 2];
		y = t4;
		if ((int16_t)t4 >= 0)
			sub_07862C(x, y, &u, &ignored16, &carry);
	}
	t5 = mem_read8(x + 6u);
	carry = (t5 >> 0) & 1u;
	if (carry)
	{
		t6 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t6 + 1u);
	}
	*p_y = y;
	*p_u = u;
}

void sub_032D19(uint16_t x)
{
	sub_07859C(x);
	sub_032D1C(x);
}

void sub_032D1C(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 5u, 0x91u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

void sub_032D25(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t7 = 0, t8 = 0;
	uint16_t t6 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) == 0u)
	{
		t2 = mem_read8(x + 6u);
		carry = (t2 >> 0) & 1u;
		if (carry)
		{
			t3 = mem_read8(x + 0x29u);
			mem_write8(x + 0x29u, t3 + 1u);
		}
	}
	else
	{
		t4 = mem_read8(x + 7u);
		if (t4 == 6u)
		{
			d = 0x2300u;
			carry = sub_078680(d);
		}
		t5 = mem_read8(x + 7u);
		t6 = robot_sparks_by_frame_91[(int8_t)((uint8_t)((uint32_t)t5 << 1)) / 2];
		y = t6;
		if ((int16_t)t6 >= 0)
			sub_07862C(x, y, &u, &ignored16, &carry);
		t7 = mem_read8(x + 6u);
		carry = (t7 >> 0) & 1u;
		if (carry)
		{
			t8 = mem_read8(x + 0x29u);
			mem_write8(x + 0x29u, t8 + 1u);
		}
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_032D51(uint16_t x, uint16_t y)
{
	uint16_t ignored16 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		y = sub_032D60(x);
		break;
	case 2:
		y = sub_032D93(x, y);
		break;
	case 4:
		y = sub_032D99(x);
		break;
	case 6:
		y = sub_032D9C(x, y);
		break;
	case 8:
		sub_032D9F(x, &y, &ignored16);
		break;
	case 10:
		sub_032DE4(x);
		break;
	case 12:
		sub_032E06(x, &y, &ignored16);
		break;
	}
	sub_0785BA(x);
	sub_07CDE9(x, ignored16);
	return y;
}

uint16_t sub_032D60(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, y = 0;
	uint8_t t2 = 0, t3 = 0;
	uint16_t t1 = 0;

	sub_032C6D(x);
	t1 = mem_read16(x + 0x48u);
	y = t1;
	sub_0785B4(x, y);
	d = 0x6300u;
	carry = sub_078680(d);
	sub_0785B1(x, &ignored16, &carry);
	if (carry == 0u)
		return y;
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	t2 = mem_read8(x + 0x1Bu);
	if (t2 != 0u)
	{
		mem_write8(x + 5u, 0x90u);
		t3 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t3 + 1u);
		return y;
	}
	mem_write8(x + 5u, 0x88u);
	mem_write8(x + 0x29u, 5u);
	return y;
}

uint16_t sub_032D93(uint16_t x, uint16_t y)
{
	sub_032C6D(x);
	return sub_032C17(x, y);
}

uint16_t sub_032D99(uint16_t x)
{
	return sub_032C28(x);
}

uint16_t sub_032D9C(uint16_t x, uint16_t y)
{
	return sub_032C31(x, y);
}

void sub_032D9F(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t y = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x48u);
	y = t1;
	sub_0785B4(x, y);
	t2 = mem_read8(x + 6u);
	carry = (t2 >> 0) & 1u;
	if (carry)
	{
		mem_write8(x, 0xC4u);
		mem_write8(x + 0x43u, 0xC4u);
		t3 = mem_read8(x + 9u);
		mem_write8(x + 9u, t3 & 0x7Fu);
		t4 = mem_read8(x + 6u);
		mem_write8(x + 6u, t4 | 0x80u);
		t5 = mem_read8(x + 0x3Du);
		mem_write8(x + 0x3Du, t5 - 1u);
		t6 = mem_read8(x + 0x3Du);
		a = t6 & 7u;
		mem_write8(x + 0x28u, robot_actions_after_hit[a]);
		mem_write8(x + 0x29u, 0u);
		u = robot_status_after_hit_ADDRESS;
		mem_write8(x, robot_status_after_hit[a]);
		mem_write8(x + 2u, 3u);
	}
	*p_y = y;
	*p_u = u;
}

void sub_032DE4(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	sub_032C6D(x);
	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		mem_write8(x + 0x3Bu, 0x40u);
		t2 = mem_read8(x + 9u);
		mem_write8(x + 9u, t2 & 0x7Fu);
		t3 = mem_read8(x + 6u);
		mem_write8(x + 6u, t3 | 0x80u);
		t4 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t4 + 1u);
	}
}

void sub_032E06(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t u_2 = 0, y_2 = 0;
	uint8_t t1 = 0;

	sub_032C6D(x);
	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	sub_032E17(x, &y_2, &u_2);
	mem_write8(x, 0u);
	u_2 = sub_078599(x, u_2);
	*p_y = y_2;
	*p_u = u_2;
}

void sub_032E17(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, u = 0, y = 0;
	uint8_t t1 = 0;

	d = 0x6E00u;
	carry = sub_078680(d);
	unk_48F4 = 8u;
	y = loaded_table_033CC8_ADDRESS;
	do
	{
		sub_07862C(x, y, &u, &ignored16, &carry);
		if (carry == 0u)
			break;
		y += 8u;
		t1 = unk_48F4;
		unk_48F4 = t1 - 1u;
	} while (t1 != 1u);
	*p_y = y;
	*p_u = u;
}

void sub_032E39(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	mem_write8(x + 5u, 0x97u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	d = 0x2700u;
	carry = sub_078680(d);
}

void sub_032E47(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t u_2 = 0, y_2 = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
		return;
	mem_write8(x, 0xC0u);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	mem_write8(x + 0x3Bu, 0x80u);
	y_2 = child_object_033D10_ADDRESS;
	*p_u = u_2;
	sub_07862F(x, y_2, p_u, &carry);
	*p_y = y_2;
}

void sub_032E61(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	d = 0x2700u;
	carry = sub_078680(d);
}

uint16_t sub_032E76(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t1 = 0;

	u = object_setup_033D1C_ADDRESS;
	sub_0785AB(x, u);
	mem_write8(x, 0x80u);
	mem_write16(x + 0xAu, 0xC0C0u);
	mem_write8(x + 0x3Bu, 0x20u);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	return u;
}

void sub_032E90(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(x + 5u, 0x99u);
	mem_write8(x, 0x90u);
	mem_write16(x + 0x14u, 0xFF80u);
	mem_write8(x + 0x3Bu, 0x30u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	d = 0x2300u;
	carry = sub_078680(d);
}

uint16_t sub_032EB4(uint16_t x, uint16_t u)
{
	uint8_t a = 0;
	uint16_t u_2 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x, 0u);
		return u;
	}
	t2 = mem_read8(x + 0x3Bu);
	if (t2 == 0x1Au)
		mem_write16(x + 0x14u, 0u);
	mem_write8(x, 0x90u);
	u_2 = robot_part_zooms_ADDRESS;
	t3 = mem_read8(x + 0x3Bu);
	a = robot_part_zooms[(int8_t)t3];
	mem_write8(x + 0xAu, a);
	mem_write8(x + 0xBu, a);
	return u_2;
}

void sub_032EE4(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_3 = 0, u = 0, y = 0;
	uint8_t t1 = 0;

	u = object_setup_033D62_ADDRESS;
	sub_0785AB(x, u);
	mem_write8(x, 4u);
	mem_write8(x + 9u, 0x20u);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	y = child_object_033D68_ADDRESS;
	sub_07862C(x, y, &ignored16, &ignored16_3, &carry);
	y = child_object_033D70_ADDRESS;
	*p_u = u;
	sub_07862C(x, y, p_u, &ignored16_3, &carry);
	*p_y = y;
}

void sub_032F03(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, u_2 = 0, y_2 = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0xCu);
	if (t1 >= 0x140u)
		return;
	mem_write8(x, 0x80u);
	mem_write16(x + 0x19u, 0xFF00u);
	mem_write8(x + 0x3Bu, 0x60u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	y_2 = child_object_033D78_ADDRESS;
	sub_07862C(x, y_2, &ignored16, &ignored16_2, &carry);
	y_2 = child_object_033D80_ADDRESS;
	*p_u = u_2;
	sub_07862C(x, y_2, p_u, &ignored16_2, &carry);
	*p_y = y_2;
}

void sub_032F2B(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(x + 0x19u, 0u);
		mem_write8(x + 0x3Bu, 0x80u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_032F3C(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(x + 0x19u, 0xFF00u);
		mem_write8(x + 0x3Bu, 0x60u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_032F50(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write16(x + 0x19u, 0u);
	mem_write8(x + 0x3Bu, 0x20u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
}

void sub_032F61(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x, 0xC0u);
		mem_write8(x + 0x3Bu, 0x60u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_032F74(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x, 0x80u);
		mem_write16(x + 0x19u, 0x100u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_032F88(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
		mem_write8(x, 0u);
}

void sub_032F9A(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t part = 0, u = 0, y = 0;
	uint8_t t1 = 0, height = 0, t2 = 0;
	uint16_t parent_step = 0;

	u = object_setup_033D90_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 0x80u);
	mem_write8(x + 9u, 0x20u);
	t1 = mem_read8(x + 0x30u);
	part = kind_12_parts_ADDRESS + (int8_t)(((uint32_t)t1 << 1) << 1);
	parent_step = (((uint32_t)KIND_12_PART(part)->parent_step << 8u) | KIND_12_PART(part)->wait);
	mem_write8(x + 0x3Du, parent_step >> 8);
	mem_write8(x + VIDEO_003C, parent_step);
	height = KIND_12_PART(part)->height;
	mem_write16(x + 0x16u, height);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	*p_y = y;
	*p_u = part;
}

uint16_t sub_032FC7(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x40u);
	u = t1;
	t2 = mem_read8(u + 2u);
	t3 = mem_read8(x + 0x3Du);
	if (t2 == t3)
	{
		mem_write8(x + 5u, 0x82u);
		t4 = mem_read8(x + 2u);
		mem_write8(x + 2u, t4 + 1u);
	}
	return u;
}

void sub_032FDB(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + VIDEO_003C);
	mem_write8(x + VIDEO_003C, t1 - 1u);
	if (t1 != 1u)
	{
		sub_032FE8();
		return;
	}
	mem_write8(x + 5u, 0x8Fu);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	sub_032FE8();
}

void sub_032FE8(void)
{
}

uint16_t sub_032FF5(uint16_t x)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0;

	u = object_setup_033E1A_ADDRESS;
	y = sub_0785AB(x, u);
	u = sub_078620(x);
	sub_078626(x, u);
	mem_write8(x + 0x43u, 1u);
	mem_write16(x + 0x2Au, enemy_behaviour_033DB6_ADDRESS);
	mem_write8(x + 0x3Au, 0x10u);
	t1 = mem_read8(x + 0x30u);
	if ((int8_t)t1 >= 0)
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

void sub_033028(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_033031(x);
		return;
	case 2:
		sub_033044(x);
		return;
	case 4:
		sub_033059(x);
		return;
	case 6:
		sub_03307D(x);
		return;
	case 8:
		sub_0330BF(x);
		return;
	case 10:
		sub_0330F3(x);
		return;
	case 12:
		sub_03310B(x);
		return;
	case 14:
		sub_03311B(x);
		return;
	case 16:
		sub_03314C(x);
		return;
	}
}

void sub_033031(uint16_t x)
{
	uint8_t t1 = 0;
	uint16_t wait = 0;

	t1 = mem_read8(x + 0x30u);
	wait = (((uint32_t)TIMED_STEP(kind_b7_entrances_ADDRESS + (int8_t)((uint32_t)t1 << 1))->wait << 8u) | TIMED_STEP(kind_b7_entrances_ADDRESS + (int8_t)((uint32_t)t1 << 1))->step);
	mem_write8(x + 0x3Bu, wait >> 8);
	mem_write8(x + 0x29u, wait);
	mem_write8(x + 0x30u, 0u);
}

void sub_033044(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write16(x + 0xCu, 0xE0u);
	mem_write8(x + 5u, 0x92u);
	mem_write16(x + 0xAu, 0x6060u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

void sub_033059(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(x + 9u, 0x10u);
	mem_write8(x, 0x90u);
	mem_write16(x + 0xFu, 0x400u);
	mem_write8(x + 0x3Bu, 0x30u);
	d = 0x2600u;
	carry = sub_078680(d);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
}

void sub_03307D(uint16_t x)
{
	uint16_t d = 0;
	uint8_t t3 = 0, t4 = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = mem_read16(x + 0x19u);
	mem_write16(x + 0x19u, t1 + 0x20u);
	t2 = mem_read16(x + 0xAu);
	d = t2 - 0x101u;
	if (d >= 0x1010u)
		mem_write16(x + 0xAu, d);
	mem_write8(x, 0x90u);
	t3 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t3 - 1u);
	if (t3 == 1u)
	{
		mem_write16(x + 0xCu, 0x180u);
		mem_write16(x + 0x11u, VIDEO_00A0);
		mem_write16(x + 0x16u, VIDEO_00C0);
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x19u, 0u);
		mem_write8(x + 0x3Bu, 1u);
		t4 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t4 + 1u);
	}
}

void sub_0330BF(uint16_t x)
{
	uint8_t t1 = 0, t4 = 0;
	uint16_t t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(x, 0x88u);
	mem_write16(x + 0x5Cu, 0u);
	mem_write8(x + 5u, 0x84u);
	mem_write16(x + 0x19u, 0xFA00u);
	mem_write16(x + 0xFu, 0x180u);
	t2 = mem_read16(x + 0xCu);
	if (t2 >= 0xE0u)
	{
		t3 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t3);
	}
	mem_write8(x + 0x3Bu, 0x40u);
	t4 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t4 + 1u);
	sub_0785C6(x);
}

void sub_0330F3(uint16_t x)
{
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
	{
		t2 = mem_read16(x + 0x19u);
		mem_write16(x + 0x19u, t2 + 0x20u);
		return;
	}
	mem_write8(x + 5u, 0x91u);
	t3 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t3 + 1u);
}

void sub_03310B(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry)
	{
		mem_write8(x, 0xC0u);
		mem_write8(x + 2u, 2u);
	}
}

void sub_03311B(uint16_t x)
{
	uint8_t t1 = 0, t4 = 0;
	uint16_t t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
	{
		sub_0785C6(x);
		return;
	}
	mem_write16(x + 0xCu, 0x180u);
	mem_write8(x, 0xC0u);
	mem_write8(x + 5u, 0x81u);
	mem_write16(x + 0xFu, 0x180u);
	t2 = mem_read16(x + 0xCu);
	if (t2 >= 0xE0u)
	{
		t3 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t3);
	}
	mem_write8(x + 0x3Bu, 0x40u);
	t4 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t4 + 1u);
	sub_0785C6(x);
}

void sub_03314C(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
		mem_write8(x + 2u, 2u);
}

void sub_03315D(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 5u, 0x93u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	sub_07859C(x);
}

uint16_t sub_033168(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t y_2 = 0;
	uint8_t t1 = 0, t2 = 0, t4 = 0;
	uint16_t t3 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
		return y;
	mem_write8(x + 5u, 0x94u);
	mem_write16(x + 0xFu, 0x300u);
	t2 = mem_read8(x + 9u);
	if ((t2 & 0x40u) != 0u)
	{
		t3 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t3);
	}
	mem_write8(x + 0x3Bu, 0x20u);
	t4 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t4 + 1u);
	y_2 = hit_box_033DA6_ADDRESS;
	sub_0785B4(x, y_2);
	return y_2;
}

uint16_t sub_033192(uint16_t x, uint16_t y)
{
	uint16_t y_2 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return y;
	mem_write16(x + 0xFu, 0u);
	y_2 = hit_box_033D9E_ADDRESS;
	sub_0785B4(x, y_2);
	mem_write8(x + 2u, 2u);
	mem_write8(x + 0x3Bu, 0u);
	return y_2;
}

void sub_0331AA(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 5u, 0x90u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	sub_07859C(x);
}

void sub_0331B5(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) == 0u)
	{
		sub_0331C5(x);
		return;
	}
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	y = child_object_033E56_ADDRESS;
	*p_u = u;
	sub_07862C(x, y, p_u, &ignored16, &carry);
	*p_y = y;
}

void sub_0331C5(uint16_t x)
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

void sub_0331D8(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint32_t carry = 0;
	uint16_t d = 0, u = 0, y = 0;
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	u = object_setup_033E62_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 0xC8u);
	mem_write16(x + 0xFu, 0x400u);
	t1 = mem_read8(x + 9u);
	if ((t1 & 0x40u) != 0u)
	{
		t2 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t2);
	}
	d = 0x2600u;
	carry = sub_078680(d);
	t3 = mem_read8(x + 2u);
	mem_write8(x + 2u, t3 + 1u);
	sub_0331FC();
	*p_y = y;
	*p_u = u;
}

void sub_0331FC(void)
{
}

void sub_033206(uint16_t x)
{
	uint8_t a = 0;
	uint8_t t4 = 0, t5 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	if (mem_read8(x) == 0u)
		return;
	t1 = mem_read16(x + 0x38u);
	t2 = mem_read16(x + 0xCu);
	t3 = mem_read16(t1 + 0xCu);
	if (t3 <= t2)
	{
		t4 = mem_read8(x + 9u);
		a = t4 | 0x40u;
	}
	else
	{
		t5 = mem_read8(x + 9u);
		a = t5 & 0xBFu;
	}
	mem_write8(x + 9u, a);
}

uint16_t sub_033226(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d = 0, u = 0, y = 0;
	uint8_t t1 = 0, t3 = 0, t5 = 0;
	uint16_t t2 = 0, t4 = 0;

	u = object_setup_033EB7_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write16(x + 0xAu, 0x8080u);
	mem_write8(x, 0x98u);
	mem_write16(x + 0x5Cu, 0u);
	t1 = mem_read8(x + 0x30u);
	a = t1;
	mem_write8(x + 0x3Du, kind_b8_sweep_ways[(int8_t)a]);
	mem_write8(x + 0x2Eu, kind_b8_headings[(int8_t)a]);
	mem_write8(x + 0x3Au, kind_b8_sweep_rates[(int8_t)a]);
	t2 = kind_b8_descent_slowdowns[(int8_t)((uint8_t)((uint32_t)a << 1)) / 2];
	mem_write16(x + 0x3Eu, t2);
	t3 = mem_read8(x + 0x30u);
	t4 = kind_b8_descent_y_speeds[(int8_t)((uint8_t)((uint32_t)t3 << 1)) / 2];
	mem_write16(x + 0x52u, t4);
	mem_write8(x + 9u, 0x20u);
	mem_write16(x + 0xCu, 0xE0u);
	d = 0x301u;
	carry = sub_078680(d);
	mem_write16(x + 0xFu, 0x300u);
	mem_write16(x + 0x14u, 0xFF80u);
	mem_write16(x + 0x19u, 0x200u);
	mem_write16(x + 0x2Cu, 0x4B0u);
	sub_078620(x);
	t5 = mem_read8(x + 2u);
	mem_write8(x + 2u, t5 + 1u);
	return y;
}

void sub_03329A(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_0332A3(x);
		return;
	case 2:
		sub_0332D4(x);
		return;
	case 4:
		sub_033318(x);
		return;
	case 6:
		sub_033334(x);
		return;
	case 8:
		sub_03334F(x);
		return;
	}
}

void sub_0332A3(uint16_t x)
{
	uint16_t d = 0;
	uint8_t t5 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	mem_write8(x, 0x98u);
	t1 = mem_read16(x + 0xAu);
	mem_write16(x + 0xAu, t1 - 0x101u);
	t2 = mem_read16(x + 0xFu);
	mem_write16(x + 0xFu, t2 - 0x10u);
	t3 = mem_read16(x + 0x19u);
	d = t3 - 0x10u;
	mem_write16(x + 0x19u, d);
	if ((int16_t)d < 0)
	{
		t4 = mem_read16(x + 0x52u);
		mem_write16(x + 0x14u, t4);
		mem_write8(x + 9u, 0x10u);
		t5 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t5 + 1u);
	}
}

void sub_0332D4(uint16_t x)
{
	uint16_t d = 0;
	uint8_t t6 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	t1 = mem_read16(x + 0xAu);
	d = t1 - 0x202u;
	if (d < 0x4040u)
		d = 0x8800u;
	else
	{
		mem_write16(x + 0xAu, d);
		d = 0x9800u;
	}
	mem_write8(x, d >> 8);
	t2 = mem_read16(x + 0x16u);
	if (t2 > 0x40u)
	{
		t3 = mem_read16(x + 0xFu);
		t4 = mem_read16(x + 0x3Eu);
		mem_write16(x + 0xFu, t3 - t4);
		t5 = mem_read16(x + 0x19u);
		mem_write16(x + 0x19u, t5 - 0x20u);
		return;
	}
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write16(x + 0x19u, 0u);
	mem_write8(x + 0x3Bu, 0x20u);
	t6 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t6 + 1u);
}

void sub_033318(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	sub_0335C2(x);
	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x, 0x88u);
		mem_write8(x + 0x3Bu, 0x12u);
		mem_write16(x + 0x19u, 0x100u);
		t2 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t2 + 1u);
	}
}

void sub_033334(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;
	uint16_t t3 = 0;

	sub_033609(x);
	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(x + 0x19u, 0u);
		t2 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t2 + 1u);
		return;
	}
	t3 = mem_read16(x + 0x16u);
	if (t3 >= 0x40u)
		mem_write16(x + 0x19u, 0u);
}

void sub_03334F(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x, 0xC8u);
	sub_078620(x);
	sub_03361F(x);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	mem_write16(x + 0x28u, 0u);
}

void sub_033361(uint16_t x)
{
	uint8_t t4 = 0, t5 = 0, t6 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read16(x + 0x2Cu);
	if (t1 == 0u)
	{
		sub_0334EF(x);
		mem_write16(x + 0x19u, 0x100u);
		t2 = mem_read16(x + 0x16u);
		if (t2 >= 0x100u)
			mem_write8(x, 0u);
		return;
	}
	t3 = mem_read16(x + 0x2Cu);
	mem_write16(x + 0x2Cu, t3 - 1u);
	sub_0335E1(x);
	sub_0334EF(x);
	t4 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t4 - 1u);
	if (t4 != 1u)
		return;
	mem_write8(x + VIDEO_003C, 4u);
	mem_write8(x + 0x3Bu, 1u);
	t5 = mem_read8(x + 0x48u);
	mem_write8(x + 0x48u, t5 - 1u);
	t6 = mem_read8(x + 0x48u);
	if ((t6 & 3u) != 0u)
	{
		mem_write8(x + 2u, 3u);
		sub_033206(x);
		return;
	}
	mem_write8(x + 2u, 4u);
	sub_033206(x);
}

uint16_t sub_0333AD(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, y_2 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	sub_0335E1(x);
	sub_0334EF(x);
	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
	{
		sub_033206(x);
		return y;
	}
	t2 = mem_read8(x + VIDEO_003C);
	if (t2 == 4u)
	{
		d = 0xF00u;
		carry = sub_078680(d);
	}
	t3 = mem_read8(x + VIDEO_003C);
	mem_write8(x + VIDEO_003C, t3 - 1u);
	if (t3 == 1u)
	{
		mem_write8(x + 2u, 2u);
		mem_write8(x + 5u, 0x80u);
		sub_03361F(x);
		return y;
	}
	mem_write8(x + 5u, 0x95u);
	t4 = mem_read8(x + VIDEO_003C);
	y_2 = kind_b8_volley_shots[t4 & 3u];
	sub_07862C(x, y_2, &ignored16, &ignored16_2, &carry);
	sub_0333E0(x);
	return y_2;
}

void sub_0333E0(uint16_t x)
{
	mem_write8(x + 0x3Bu, 7u);
	sub_033206(x);
}

uint16_t sub_0333F6(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, y_2 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	sub_0335E1(x);
	sub_0334EF(x);
	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
	{
		sub_033206(x);
		return y;
	}
	t2 = mem_read8(x + VIDEO_003C);
	mem_write8(x + VIDEO_003C, t2 - 1u);
	if (t2 == 1u)
	{
		mem_write8(x + 2u, 2u);
		mem_write8(x + 5u, 0x80u);
		sub_03361F(x);
		return y;
	}
	mem_write8(x + 5u, 0x90u);
	t3 = mem_read8(x + VIDEO_003C);
	y_2 = kind_b8_single_shots[t3 & 1u];
	sub_07862C(x, y_2, &ignored16, &ignored16_2, &carry);
	sub_0333E0(x);
	return y_2;
}

void sub_03341C(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_033425(x);
		return;
	case 2:
		sub_03344D(x);
		return;
	case 4:
		sub_03349D(x);
		return;
	case 6:
		sub_0334B7(x);
		return;
	case 8:
		sub_0334C5(x);
		return;
	}
}

void sub_033425(uint16_t x)
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
	d = 0x5300u;
	carry = sub_078680(d);
	mem_write8(x + 5u, 0x89u);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
}

void sub_03344D(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	sub_0334D7(x);
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
	mem_write8(x + 5u, 0x80u);
	mem_write8(x + 2u, 2u);
	mem_write8(x, 0xC8u);
	mem_write8(x + 6u, 0x80u);
	mem_write8(x + 0x3Bu, 0x10u);
}

void sub_033494(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_03349D(x);
		return;
	case 2:
		sub_0334B7(x);
		return;
	case 4:
		sub_0334C5(x);
		return;
	case -4:
		sub_033425(x);
		return;
	case -2:
		sub_03344D(x);
		return;
	}
}

void sub_03349D(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	d = 0x5300u;
	carry = sub_078680(d);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write8(x, 0x88u);
	mem_write8(x + 5u, 0x88u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

void sub_0334B7(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0;
	uint8_t t1 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry == 0u)
	{
		sub_0334C5(x);
		return;
	}
	d = 0x7700u;
	carry = sub_078680(d);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	sub_0334C5(x);
}

void sub_0334C5(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		t2 = mem_read8(x + 0x27u);
		mem_write8(x + 0x27u, t2 | 0x80u);
		mem_write8(x, 0u);
	}
}

void sub_0334D7(uint16_t x)
{
	uint8_t a = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x3Bu);
	t2 = mem_read16(x + 0x50u);
	t3 = mem_read16(x + 0x16u);
	mem_write16(x + 0x19u, (uint32_t)(uint16_t)(((uint32_t)a << 8) | (uint8_t)((((uint32_t)a << 8) | (uint8_t)((((uint32_t)a << 8) | kind_b8_hurt_shakes[t1 & 3u]) + t2)) - t3)) << 8);
}

void sub_0334EF(uint16_t x)
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
	sub_033609(x);
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
	if ((uint16_t)(((uint32_t)a << 8) | b) < 0x40u)
	{
		b = 0x40u;
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
	if ((uint16_t)(((uint32_t)a << 8) | b) >= 0x180u)
	{
		b = 0x7Fu;
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

void sub_0335C2(uint16_t x)
{
	uint8_t a = 0;
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 0x37u);
	t2 = mem_read16(x + 0x16u);
	mem_write16(x + 0x19u, (uint32_t)(uint16_t)(((uint32_t)a << 8) | (uint8_t)((((uint32_t)a << 8) | (uint8_t)((((uint32_t)a << 8) | kind_b8_bob_up[(int8_t)t1]) + 0x40u)) - t2)) << 8);
	t3 = mem_read8(x + 0x37u);
	mem_write8(x + 0x37u, (t3 + 1u) & 0x1Fu);
}

void sub_0335E1(uint16_t x)
{
	uint8_t a = 0, b = 0;
	uint16_t heights = 0;
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 0x37u);
	b = t1;
	if ((b & 0xE0u) != 0u)
		heights = kind_b8_bob_up_ADDRESS;
	else
		heights = kind_b8_bob_down_ADDRESS;
	t2 = mem_read16(x + 0x16u);
	mem_write16(x + 0x19u, (uint32_t)(uint16_t)(((uint32_t)a << 8) | (uint8_t)((((uint32_t)a << 8) | (uint8_t)((((uint32_t)a << 8) | (uint8_t)BOB_HEIGHT(heights + (b & 0x1Fu))) + 0x40u)) - t2)) << 8);
	t3 = mem_read8(x + 0x37u);
	mem_write8(x + 0x37u, t3 + 1u);
}

void sub_033609(uint16_t x)
{
	uint16_t speeds = 0;
	uint8_t t1 = 0;
	uint16_t x_speed = 0, y_speed = 0;

	t1 = mem_read8(x + 0x2Eu);
	speeds = kind_b8_velocities_ADDRESS + (int8_t)(((uint32_t)t1 << 1) << 1);
	x_speed = VELOCITY(speeds)->x_speed;
	mem_write16(x + 0xFu, x_speed);
	y_speed = VELOCITY(speeds)->y_speed;
	mem_write16(x + 0x14u, y_speed);
}

void sub_03361F(uint16_t x)
{
	uint8_t a = 0;
	uint16_t d = 0;

	d = sub_078623(0u);
	a = (uint8_t)(d >> 8);
	mem_write8(x + 0x3Bu, (uint8_t)(VELOCITY(kind_b8_velocities_ADDRESS + (a & 3u) - 0x4u)->x_speed >> 8u));
}

void sub_033633(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t3 = 0, t5 = 0, t6 = 0;
	uint16_t t2 = 0, t4 = 0;

	u = object_setup_033FDD_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 0x30u);
	mem_write8(x + 5u, kind_b8_shot_animations[(int8_t)t1]);
	mem_write16(x + 0x19u, 0x400u);
	u = kind_b8_shot_speeds_ADDRESS;
	t2 = kind_b8_shot_speeds[unk_4858 & 3u];
	mem_write16(x + 0xFu, t2);
	t3 = mem_read8(x + 9u);
	if ((t3 & 0x40u) != 0u)
	{
		t4 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t4);
	}
	t5 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t5 & 0x8Fu) | 0x50u);
	mem_write16(x + 0x5Cu, 0u);
	t6 = mem_read8(x + 2u);
	mem_write8(x + 2u, t6 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_033678(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;
	uint8_t t1 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry)
	{
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x19u, 0x100u);
		mem_write8(x, 0xC0u);
		mem_write16(x + 4u, 0x480u);
		mem_write8(x + 0x3Bu, 2u);
		t1 = mem_read8(x + 2u);
		mem_write8(x + 2u, t1 + 1u);
	}
}

void sub_03369A(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(x, 0x80u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	sub_0336A7(x);
}

void sub_0336A7(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
		return;
	mem_write8(x, 0u);
}
