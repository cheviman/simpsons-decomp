/**
 *    Name:        unsorted/bank_17.c
 *    Description: bank 17's code
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    06-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

void sub_02E000(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02FA08_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
	case 50:
		sub_02E07B(x, &y, &u);
		break;
	case 2:
		sub_02E0AA(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_02E003(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02FAC4_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02E2DD(x, &y, &u);
		break;
	case 2:
		sub_02E2F6();
		break;
	case -56:
	case 4:
	case 34:
		sub_02E306(x);
		break;
	case -54:
	case 6:
	case 36:
		sub_02E331(x);
		break;
	case -52:
	case 8:
	case 38:
		sub_02E353(x);
		break;
	}
	carry = sub_078683(x, carry);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_02E006(uint16_t x, uint32_t y, uint8_t d)
{
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t ignored16 = 0, u = 0;

	b = (uint8_t)d;
	u = loaded_table_02FA88_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02E217(x, &ignored16, &u);
		break;
	case 2:
		sub_02E279(x);
		break;
	case 4:
	case 64:
	case 94:
		sub_02E306(x);
		break;
	case 6:
	case 66:
	case 96:
		sub_02E331(x);
		break;
	case 8:
	case 68:
	case 98:
		sub_02E353(x);
		break;
	case 10:
		sub_02E2B2(x);
		break;
	case 12:
		sub_02E2CA(x);
		break;
	}
	carry = sub_078683(x, carry);
	return u;
}

void sub_02E009(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		y = sub_02E6AE(x);
		break;
	case 2:
		y = sub_02E71C(x, y);
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

void sub_02E00C(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02FC6D_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02E78A(x);
		break;
	case 2:
		sub_02E793(x, &y, &u);
		break;
	case 4:
		sub_02E7B9(x);
		break;
	case -8:
		u = sub_02E725(x, u);
		break;
	case -6:
		sub_02E744(x);
		break;
	case -4:
		sub_02E765(x);
		break;
	case -2:
		sub_02E770(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_02E00F(uint16_t x, uint32_t y, uint8_t d)
{
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02FC79_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		return sub_02E7E4(x);
	case 2:
		sub_02E809(x);
		return u;
	case 4:
		sub_02E819(x);
		return u;
	case 6:
		sub_02E821(x);
		return u;
	}
	unreachable();
}

void sub_02E012(void)
{
}

void sub_02E015(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02EF0F(x, &y, &ignored16);
		break;
	case 2:
		sub_02EF44(x, &y, &ignored16);
		break;
	case -8:
	case 4:
	case 66:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case -6:
	case 6:
	case 68:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case -4:
	case 8:
	case 70:
		sub_07865C(x, &y, &ignored16);
		break;
	case -2:
	case 10:
	case 72:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	case -20:
		sub_02EE18(x);
		break;
	case -18:
		sub_02EE24(x);
		break;
	case -16:
		sub_02EE76(x);
		break;
	case -14:
		y = sub_02EEB1(x);
		break;
	case -12:
		sub_0785D5(x, &y, &ignored16);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	sub_0785B7(x, ignored16);
	*p_y = y;
}

void sub_02E018(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = hit_box_02FBC3_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02E635(x, &y, &u);
		break;
	case 2:
		u = sub_02E673(x, u);
		break;
	case 4:
		u = sub_02E686(x, u);
		break;
	case 6:
		sub_02E6A1();
		break;
	}
	carry = sub_078683(x, carry);
	*p_y = y;
	*p_u = u;
}

void sub_02E01B(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;
	uint32_t ignored = 0;

	b = (uint8_t)d;
	u = loaded_table_02FE0F_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_0785D5(x, &y, &u);
		break;
	case 4:
	case 16:
	case 78:
		sub_0785DB(x, &y, &u, &ignored);
		break;
	case 6:
	case 18:
	case 80:
		sub_0785DE(x, &y, &u, &ignored);
		break;
	case 8:
	case 20:
	case 82:
		sub_07865C(x, &y, &u);
		break;
	case 10:
	case 22:
	case 84:
		sub_0785E4(x, &y, &u, &ignored);
		break;
	case 12:
		sub_02EF0F(x, &y, &u);
		break;
	case 14:
		sub_02EF44(x, &y, &u);
		break;
	case -8:
		sub_02EE18(x);
		break;
	case -6:
		sub_02EE24(x);
		break;
	case -4:
		sub_02EE76(x);
		break;
	case -2:
		y = sub_02EEB1(x);
		break;
	}
	sub_078596(x, &u, p_left_caller);
	u = sub_0785B7(x, u);
	*p_y = y;
	*p_u = u;
}

void sub_02E01E(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02FE3B_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02EFD5(x);
		break;
	case 2:
		y = sub_02EFE1(x, y);
		break;
	case 4:
		y = sub_02EFF2(x);
		break;
	case 6:
		sub_02EFFB(x);
		break;
	case 8:
	case 10:
		sub_02F00F(x, &y, &u);
		break;
	case 12:
		sub_02F02C(x, &y, &u);
		break;
	case 14:
	case 16:
		sub_02F055(x);
		break;
	case 18:
		sub_02F068(x);
		break;
	case 20:
		sub_02F018(x);
		break;
	case 22:
		sub_02F022(x);
		break;
	case -14:
		sub_02EF4D(x);
		break;
	case -12:
		sub_02EF67(x);
		break;
	case -10:
		sub_02EF6B(x);
		break;
	case -8:
		sub_02EF79(x);
		break;
	case -6:
		sub_02EF8D(x);
		break;
	case -4:
		sub_02EFA5(x);
		break;
	case -2:
		sub_02EFC6(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_02E021(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;
	uint8_t t1 = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		y = sub_02F08C(x);
		break;
	case 2:
		sub_02F0D8(x);
		break;
	case -70:
	case -58:
	case 4:
		sub_0785DB(x, &y, &ignored16, &ignored);
		break;
	case -68:
	case -56:
	case 6:
		sub_0785DE(x, &y, &ignored16, &ignored);
		break;
	case -66:
	case -54:
	case 8:
		sub_07865C(x, &y, &ignored16);
		break;
	case -64:
	case -52:
	case 10:
		sub_0785E4(x, &y, &ignored16, &ignored);
		break;
	}
	sub_078596(x, &ignored16, p_left_caller);
	t1 = mem_read8(x + 2u);
	if (t1 != 4u)
		sub_0785B7(x, ignored16);
	else
	{
		mem_write8(x + 0x42u, 0u);
		mem_write8(x + 0x57u, 0u);
		sub_0785B7(x, ignored16);
	}
	*p_y = y;
}

void sub_02E024(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02FE73_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02F0F0(x);
		break;
	case 2:
		y = sub_02F0F9(x);
		break;
	case 4:
		sub_02F111(x);
		break;
	case 6:
		y = sub_02F13E(x);
		break;
	case 8:
		y = sub_02F16D(x);
		break;
	case 10:
		y = sub_02F17C(x);
		break;
	case 12:
		y = sub_02F19B(x);
		break;
	case 14:
		y = sub_02F1B3(x, y);
		break;
	case 16:
		u = sub_02F1DE(x);
		break;
	case 18:
		sub_02F204(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_02E027(uint16_t x, uint16_t y, uint8_t d)
{
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02FE47_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02F02C(x, &y, &u);
		break;
	case 2:
	case 4:
		sub_02F055(x);
		break;
	case 6:
		sub_02F068(x);
		break;
	case 8:
		sub_02F018(x);
		break;
	case 10:
		sub_02F022(x);
		break;
	case -26:
		sub_02EF4D(x);
		break;
	case -24:
		sub_02EF67(x);
		break;
	case -22:
		sub_02EF6B(x);
		break;
	case -20:
		sub_02EF79(x);
		break;
	case -18:
		sub_02EF8D(x);
		break;
	case -16:
		sub_02EFA5(x);
		break;
	case -14:
		sub_02EFC6(x);
		break;
	case -12:
		sub_02EFD5(x);
		break;
	case -10:
		sub_02EFE1(x, y);
		break;
	case -8:
		sub_02EFF2(x);
		break;
	case -6:
		sub_02EFFB(x);
		break;
	case -4:
	case -2:
		sub_02F00F(x, &y, &u);
		break;
	}
	u = sub_078593(x, u);
	carry = sub_078683(x, carry);
	return u;
}

void sub_02E02A(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02FFC9_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02F7B6(x, &y, &u);
		break;
	case 2:
		u = sub_02F7C5(x);
		break;
	case 4:
		u = sub_02F7F1(x, u);
		break;
	case 6:
		sub_02F83E(x);
		break;
	case 8:
		sub_02F852(x);
		break;
	case 10:
		u = sub_02F826(x);
		break;
	case -4:
		sub_02F7B5();
		break;
	case -2:
		sub_02F7AB(x);
		break;
	}
	u = sub_078593(x, u);
	carry = sub_078683(x, carry);
	*p_y = y;
	*p_u = u;
}

void sub_02E02D(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02FE77_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02F111(x);
		break;
	case 2:
		y = sub_02F13E(x);
		break;
	case 4:
		y = sub_02F16D(x);
		break;
	case 6:
		y = sub_02F17C(x);
		break;
	case 8:
		y = sub_02F19B(x);
		break;
	case 10:
		y = sub_02F1B3(x, y);
		break;
	case 12:
		u = sub_02F1DE(x);
		break;
	case 14:
		sub_02F204(x);
		break;
	case -4:
		sub_02F0F0(x);
		break;
	case -2:
		y = sub_02F0F9(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_02E030(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02FFA3_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02F75C(x, &y, &u);
		break;
	case 2:
		u = sub_02F787(x, u);
		break;
	}
	carry = sub_078683(x, carry);
	*p_y = y;
	*p_u = u;
}

void sub_02E033(void)
{
}

void sub_02E036(uint16_t x, uint8_t d, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		y = sub_02EC09(x);
		break;
	case 2:
		sub_02EC3B(x);
		break;
	case 4:
		sub_02EC59(x);
		break;
	case 6:
		sub_02EC82(x);
		break;
	case 8:
		y = sub_02ECE3(x, y);
		break;
	case 10:
		sub_02ED4F(x);
		break;
	case 12:
		y = sub_02ED8A(x);
		break;
	case 14:
		y = sub_02ED93(x, y);
		break;
	case 16:
		sub_02EDFC(x, &y, p_left_caller);
		break;
	case 18:
		y = sub_02EEC7(x, y);
		break;
	case 20:
		y = sub_02EEE5(x, y);
		break;
	case -4:
		y = sub_02EB33(x);
		break;
	case -2:
		y = sub_02EB5B(x, y);
		break;
	}
	sub_078593(x, 0u);
	t1 = mem_read8(x + 2u);
	if (t1 < 3u)
	{
		t2 = mem_read16(x + 0x40u);
		if (mem_read8(t2) == 0u)
		{
			mem_write16(x + 0xFu, 0u);
			mem_write16(x + 0x14u, 0u);
			mem_write8(x + 2u, 0xFFu);
		}
	}
	*p_y = y;
}

void sub_02E039(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0;
	uint16_t t1 = 0, t5 = 0;

	b = (uint8_t)d;
	u = loaded_table_02FD96_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02E8D8(x, &y, &u);
		break;
	case 2:
		sub_02E8FE(x, &y, &u);
		break;
	case 4:
		sub_02E945(x);
		break;
	case 6:
		sub_02E954(x);
		break;
	case 8:
		sub_02E95D(x);
		break;
	case 10:
		sub_02E969(x, &y, &u);
		break;
	}
	if (mem_read8(x) != 0u)
	{
		t1 = mem_read16(x + 0xCu);
		if (t1 < 0xE0u)
			unk_48A7--;
		mem_write8(x + 0x3Du, 0u);
		u = indexed_table_02FDA2_ADDRESS;
		t2 = io_read8(VIDEO_1874);
		t3 = mem_read8(x + VIDEO_0031);
		if (DATA8(indexed_table_02FDA2_ADDRESS + (int8_t)t2) < t3)
		{
			t4 = mem_read8(x + 0x3Du);
			mem_write8(x + 0x3Du, t4 + 1u);
		}
		t5 = mem_read16(x + 0xCu);
		if (t5 >= 0x1E0u)
			mem_write8(x, 0u);
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_02E03C(uint16_t x, uint8_t y, uint8_t d)
{
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02FDB5_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		return sub_02E983(x);
	case 2:
		return sub_02E9E8(x, y);
	case 4:
		return sub_02EA06(x);
	case 6:
		return sub_02EA29(x, u);
	case 8:
		return sub_02EA3E(x, u);
	}
	unreachable();
}

void sub_02E03F(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint16_t t1 = 0;

	u = loaded_table_02FE7B_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)d << 1))
	{
	case 0:
		y = sub_02F16D(x);
		break;
	case 2:
		y = sub_02F17C(x);
		break;
	case 4:
		y = sub_02F19B(x);
		break;
	case 6:
		y = sub_02F1B3(x, y);
		break;
	case 8:
		u = sub_02F1DE(x);
		break;
	case 10:
		sub_02F204(x);
		break;
	case -8:
		sub_02F0F0(x);
		break;
	case -6:
		y = sub_02F0F9(x);
		break;
	case -4:
		sub_02F111(x);
		break;
	case -2:
		y = sub_02F13E(x);
		break;
	}
	t1 = mem_read16(x + 0xCu);
	if (t1 < 0x60 || t1 > 0x15F)
		mem_write16(x + 0xFu, 0u);
	*p_y = y;
	*p_u = u;
}

void sub_02E042(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02FE83_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		u = sub_02F1DE(x);
		break;
	case 2:
		sub_02F204(x);
		break;
	case -16:
		sub_02F0F0(x);
		break;
	case -14:
		y = sub_02F0F9(x);
		break;
	case -12:
		sub_02F111(x);
		break;
	case -10:
		y = sub_02F13E(x);
		break;
	case -8:
		y = sub_02F16D(x);
		break;
	case -6:
		y = sub_02F17C(x);
		break;
	case -4:
		y = sub_02F19B(x);
		break;
	case -2:
		y = sub_02F1B3(x, y);
		break;
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_02E045(uint16_t x, uint32_t y, uint8_t d)
{
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02FDCD_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		return sub_02EA8F(x);
	case 2:
		sub_02EACF(x);
		return u;
	case 4:
		sub_02EAFA(x);
		return u;
	}
	unreachable();
}

void sub_02E048(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	b = (uint8_t)d;
	u = loaded_table_02FF4F_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02F507(x, &y, &u);
		break;
	case 2:
		sub_02F573(x);
		break;
	case 4:
		sub_02F58D(x);
		break;
	case 6:
		sub_02F5B0(x);
		break;
	case 8:
		sub_02F5F7(x);
		break;
	case 10:
		sub_02F61C(x);
		break;
	case 12:
		sub_02F62D(x);
		break;
	case 14:
		sub_02F645(x);
		break;
	case 16:
		u = sub_02F657(x);
		break;
	case 18:
		u = sub_02F6A7(x, u);
		break;
	case 20:
		u = sub_02F6FE(x);
		break;
	}
	t1 = mem_read8(x + 2u);
	if (t1 == 7u && mem_read8(x) != 0u)
	{
		t2 = mem_read16(x + 0xCu);
		if (t2 >= 0x1C0u)
			mem_write8(x, 0u);
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_02E04B(uint16_t x, uint32_t y, uint8_t d)
{
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t ignored16 = 0, u = 0;

	b = (uint8_t)d;
	u = loaded_table_02FF3D_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02F3ED(x, &ignored16, &u);
		break;
	case 2:
		sub_02F425(x);
		break;
	case 4:
		sub_02F456(x);
		break;
	case 6:
		u = sub_02F469(x);
		break;
	case 8:
		sub_02F4D7(x);
		break;
	case 10:
		sub_02F4D6();
		break;
	}
	carry = sub_078683(x, carry);
	return u;
}

uint16_t sub_02E04E(uint16_t x, uint32_t y, uint8_t d)
{
	uint8_t b = 0;
	uint16_t ignored16 = 0, u = 0;

	b = (uint8_t)d;
	u = loaded_table_02FAE4_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02E367(x, &ignored16, &u);
		return u;
	case -88:
	case -28:
	case 2:
		sub_02E306(x);
		return u;
	case -86:
	case -26:
	case 4:
		sub_02E331(x);
		return u;
	case -84:
	case -24:
	case 6:
		sub_02E353(x);
		return u;
	case 8:
		sub_02E39E(x, &ignored16, &u);
		return u;
	case 10:
		sub_02E3EE(x);
		return u;
	case 12:
		sub_02E406(x, &ignored16, &u);
		return u;
	case 14:
		sub_02E435(x);
		return u;
	case 16:
		sub_02E46C();
		return u;
	case 18:
		sub_02E479(x);
		return u;
	case 20:
		sub_02E486(x);
		return u;
	}
	unreachable();
}

void sub_02E051(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint16_t t1 = 0;

	u = loaded_table_02FAEC_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)d << 1))
	{
	case 0:
		sub_02E39E(x, &y, &u);
		break;
	case 2:
		sub_02E3EE(x);
		break;
	case 4:
		sub_02E406(x, &y, &u);
		break;
	case 6:
		sub_02E435(x);
		break;
	case 8:
		sub_02E46C();
		break;
	case 10:
		sub_02E479(x);
		break;
	case 12:
		sub_02E486(x);
		break;
	case -96:
	case -36:
	case -6:
		sub_02E306(x);
		break;
	case -94:
	case -34:
	case -4:
		sub_02E331(x);
		break;
	case -92:
	case -32:
	case -2:
		sub_02E353(x);
		break;
	case -8:
		sub_02E367(x, &y, &u);
		break;
	}
	t1 = mem_read16(x + 0xCu);
	if (t1 < 0x40 || t1 > 0x1CF)
		mem_write8(x, 0u);
	*p_y = y;
	*p_u = u;
}

void sub_02E054(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02FF29_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02F33E(x, &y, &u);
		break;
	case 2:
		u = sub_02F350(x, u);
		break;
	case 4:
		y = sub_02F3A1(x);
		break;
	case 6:
		y = sub_02F3AB(x);
		break;
	case 8:
		sub_02F3BA(x);
		break;
	case 10:
		sub_02F3D3(x);
		break;
	}
	carry = sub_078683(x, carry);
	*p_y = y;
	*p_u = u;
}

void sub_02E057(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02FF17_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02F2B3(x, &y, &u);
		break;
	case 2:
		sub_02F2C2(x);
		break;
	case 4:
		sub_02F2D3(x);
		break;
	case 6:
		sub_02F2EC(x);
		break;
	case 8:
		sub_02F310(x);
		break;
	case 10:
		sub_02F334();
		break;
	}
	carry = sub_078683(x, carry);
	*p_y = y;
	*p_u = u;
}

void sub_02E05A(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02FA68_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02E1FA(x, &y, &u);
		break;
	case 2:
	case 4:
		sub_02E209();
		break;
	case 6:
		sub_02E20A(x);
		break;
	}
	carry = sub_078683(x, carry);
	*p_y = y;
	*p_u = u;
}

void sub_02E05D(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;
	uint16_t t1 = 0, t2 = 0;

	b = (uint8_t)d;
	u = loaded_table_02FB50_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02E4B6(x, &y, &u);
		break;
	case 2:
		sub_02E4CD(x);
		break;
	case 4:
		sub_02E4DB(x, &y, &u);
		break;
	case 6:
		sub_02E4F7(x);
		break;
	case 8:
		sub_02E50A();
		break;
	case 10:
		sub_02E50B(x);
		break;
	case 12:
		sub_02E514(x);
		break;
	}
	if (mem_read8(x) != 0u)
	{
		t1 = mem_read16(x + 0xCu);
		t2 = t1 - 0x10u;
		if (t2 >= 0x1B0u)
			mem_write8(x, 0u);
	}
	*p_y = y;
	*p_u = u;
}

void sub_02E060(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02FB6C_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02E533(x, &y, &u);
		break;
	case 2:
		sub_02E553(x);
		break;
	case 4:
		sub_02E561(x, &y, &u);
		break;
	case 6:
		sub_02E595(x);
		break;
	case 8:
		sub_02E5A9();
		break;
	case 10:
		sub_02E5AA(x);
		break;
	case 12:
		sub_02E5B7(x);
		break;
	}
	carry = sub_078683(x, carry);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_02E063(uint16_t x, uint32_t y, uint8_t d)
{
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02FBB0_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		return sub_02E5D3(x);
	case 2:
		sub_02E5F8(x);
		return u;
	case 4:
		sub_02E331(x);
		return u;
	case 6:
		sub_02E353(x);
		return u;
	}
	unreachable();
}

uint16_t sub_02E066(uint16_t x, uint8_t d)
{
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02FE8B_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02F211(x);
		return u;
	case 2:
		sub_02F235(x);
		return u;
	}
	unreachable();
}

void sub_02E069(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02FE37_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02EFA5(x);
		break;
	case 2:
		sub_02EFC6(x);
		break;
	case 4:
		sub_02EFD5(x);
		break;
	case 6:
		y = sub_02EFE1(x, y);
		break;
	case 8:
		y = sub_02EFF2(x);
		break;
	case 10:
		sub_02EFFB(x);
		break;
	case 12:
	case 14:
		sub_02F00F(x, &y, &u);
		break;
	case 16:
		sub_02F02C(x, &y, &u);
		break;
	case 18:
	case 20:
		sub_02F055(x);
		break;
	case 22:
		sub_02F068(x);
		break;
	case 24:
		sub_02F018(x);
		break;
	case 26:
		sub_02F022(x);
		break;
	case -10:
		sub_02EF4D(x);
		break;
	case -8:
		sub_02EF67(x);
		break;
	case -6:
		sub_02EF6B(x);
		break;
	case -4:
		sub_02EF79(x);
		break;
	case -2:
		sub_02EF8D(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_02E06C(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02FA3A_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case -50:
	case 0:
		sub_02E07B(x, &y, &u);
		break;
	case 2:
		sub_02E0B9(x);
		break;
	case 4:
		sub_02E0CD(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_02E06F(uint16_t x, uint16_t y, uint8_t d)
{
	uint32_t carry = 0;
	uint8_t b = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		y = sub_02E0EA(x);
		break;
	case 2:
		sub_02E10D(x);
		break;
	case 4:
		sub_02E130(x);
		break;
	case 6:
		sub_02E147(x);
		break;
	}
	carry = sub_078683(x, carry);
	return y;
}

void sub_02E072(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02FC8F_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02E834(x, &y, &u);
		break;
	case 2:
		u = sub_02E84D(x, u);
		break;
	case 4:
		sub_02E87D(x);
		break;
	case 6:
		sub_02E890(x);
		break;
	case 8:
		sub_02E89F();
		break;
	}
	carry = sub_078683(x, carry);
	*p_y = y;
	*p_u = u;
}

void sub_02E07B(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t4 = 0;
	uint16_t t2 = 0, t3 = 0;

	u = object_setup_02FA0C_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 0x80u);
	mem_write16(x + 0xCu, 0x1A0u);
	t1 = mem_read8(x + 0x30u);
	u = loaded_table_02FA12_ADDRESS + (int8_t)(((uint32_t)t1 << 1) << 1);
	t2 = DATA16(u);
	mem_write16(x + 0xFu, t2);
	t3 = mem_read16(u + 2u);
	mem_write8(x + 5u, (t3 >> 8) | 0x80u);
	mem_write8(x + 9u, t3);
	t4 = mem_read8(x + 2u);
	mem_write8(x + 2u, t4 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_02E0AA(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0xCu);
	mem_write8(x + 0xCu, t1 & 1u);
}

void sub_02E0B9(uint16_t x)
{
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 0xCu);
	mem_write8(x + 0xCu, t1 & 1u);
	t2 = unk_48AC;
	if (t2 >= 0x6B0u)
	{
		t3 = mem_read8(x + 2u);
		mem_write8(x + 2u, t3 + 1u);
	}
}

void sub_02E0CD(uint16_t x)
{
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 0xCu);
	mem_write8(x + 0xCu, t1 & 1u);
	t2 = mem_read16(x + 0xCu);
	if (t2 >= 0x1C0u)
		mem_write8(x, 0u);
}

uint16_t sub_02E0EA(uint16_t x)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0;

	u = object_setup_02FA50_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 0xC8u);
	mem_write16(x + 0x5Cu, 0u);
	mem_write16(x + 0xFu, 0xFE00u);
	t1 = mem_read8(x + 0x30u);
	if (t1 != 0u)
	{
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
		return y;
	}
	mem_write8(x + 2u, 3u);
	return y;
}

void sub_02E10D(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x19u);
	mem_write16(x + 0x19u, t1 - 0x40u);
	carry = sub_078662(x);
	if (carry == 0u)
		return;
	mem_write8(x, 0xC8u);
	mem_write16(x + 0x19u, 0x600u);
	d = VIDEO_2000;
	carry = sub_078680(d);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
}

void sub_02E130(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x19u);
	mem_write16(x + 0x19u, t1 - 0x40u);
	carry = sub_078662(x);
	if (carry == 0u)
		return;
	d = VIDEO_2000;
	carry = sub_078680(d);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	sub_02E147(x);
}

void sub_02E147(uint16_t x)
{
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0xFu);
	mem_write16(x + 0xFu, t1 - 0x10u);
}

void unused_02E1A9(uint16_t x, uint8_t d)
{
	switch ((int8_t)(uint8_t)((uint32_t)d << 1))
	{
	case 0:
		sub_02E1D5(x);
		break;
	case 2:
		sub_02E1F0();
		break;
	case 4:
		sub_02E1BC(x);
		break;
	case 6:
		sub_02E1CB(x);
		break;
	case -4:
	case -2:
		sub_02E1B3(x);
		break;
	}
	sub_078593(x, 0u);
}

void sub_02E1B3(uint16_t x)
{
	uint8_t t1 = 0;

	for (;;)
	{
		t1 = mem_read8(x + 0x29u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			sub_02E1BC(x);
			return;
		case 2:
			break;
		case -8:
		case -6:
			continue;
		case -4:
			sub_02E1D5(x);
			return;
		case -2:
			sub_02E1F0();
			return;
		}
		break;
	}
	sub_02E1CB(x);
}

void sub_02E1BC(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	mem_write8(x + 5u, 0x80u);
	d = 0x6C00u;
	carry = sub_078680(d);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

void sub_02E1CB(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
		mem_write8(x, 0u);
}

void sub_02E1D5(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0, u = 0;
	uint8_t t1 = 0;

	u = object_setup_02FA62_ADDRESS;
	sub_0785AB(x, u);
	mem_write16(x + 0xCu, 0x200u);
	mem_write8(x + 9u, 0x10u);
	d = 0x6700u;
	carry = sub_078680(d);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
}

void sub_02E1F0(void)
{
}

void sub_02E1FA(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x30u);
	u = DATA16(indexed_table_02FA70_ADDRESS + (int8_t)((uint32_t)t1 << 1));
	y = sub_0785AB(x, u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	sub_02E209();
	*p_y = y;
	*p_u = u;
}

void sub_02E209(void)
{
}

void sub_02E20A(uint16_t x)
{
	mem_write8(x, 0u);
}

void sub_02E217(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t6 = 0, t11 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0;

	u = object_setup_02FA96_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 0x30u);
	u = DATA16(indexed_table_02FA9C_ADDRESS + (uint8_t)((t1 & 3u) << 1));
	t2 = mem_read16(u);
	mem_write8(x + 5u, (t2 >> 8) | 0x80u);
	mem_write8(x + 0x1Du, t2);
	t3 = io_read16(u + 2u);
	mem_write16(x + 0x3Eu, t3);
	t4 = io_read16(u + 4u);
	mem_write16(x + 0xFu, t4);
	a = unk_4858;
	carry = (a >> 0) & 1u;
	a = a >> 1;
	if (carry == 0u)
		mem_write8(x + 0x10u, a);
	t5 = io_read16(u + 6u);
	mem_write16(x + 0x19u, t5);
	mem_write16(x + 0xAu, 0x4040u);
	t6 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t6 & 0xCFu) | 0x10u);
	t7 = mem_read16(x + 0x2Au);
	u = t7;
	t8 = mem_read16(u + 0xCu);
	t9 = mem_read16(x + 0xCu);
	if (t8 < t9)
	{
		t10 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t10);
	}
	mem_write8(x + VIDEO_003C, 3u);
	t11 = mem_read8(x + 2u);
	mem_write8(x + 2u, t11 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_02E279(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t4 = 0, t5 = 0, t6 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read16(x + 0x19u);
	t2 = mem_read16(x + 0x3Eu);
	t3 = t1 - t2;
	mem_write16(x + 0x19u, t3);
	carry = sub_078662(x);
	if (carry == 0u)
		return;
	t4 = mem_read8(x + 0x30u);
	if (t4 < 2u)
	{
		mem_write8(x, 0u);
		return;
	}
	mem_write8(x, 0xC0u);
	t5 = mem_read8(x + VIDEO_003C);
	mem_write8(x + VIDEO_003C, t5 - 1u);
	if (t5 == 1u)
	{
		mem_write16(x + 0xFu, 0u);
		mem_write8(x + 0x3Bu, 0x40u);
		mem_write8(x + 2u, 5u);
		return;
	}
	t6 = mem_read8(x + VIDEO_003C);
	mem_write8(x + 0x19u, (uint32_t)t6 << 1);
}

void sub_02E2B2(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 4u, 4u);
		mem_write8(x + 5u, 0x80u);
		mem_write8(x, 0x80u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_02E2CA(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
		mem_write8(x, 0u);
}

void sub_02E2DD(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0;

	u = object_setup_02FADE_ADDRESS;
	y = sub_0785AB(x, u);
	u = sub_02E2F7(x);
	mem_write16(x + 0xAu, 0x4040u);
	t1 = mem_read8(x + 0x30u);
	mem_write8(x + 5u, t1 | 0x80u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	sub_02E2F6();
	*p_y = y;
	*p_u = u;
}

void sub_02E2F6(void)
{
}

uint16_t sub_02E2F7(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t1 = 0;

	u = indexed_table_02FACE_ADDRESS;
	t1 = mem_read8(x + 0x30u);
	mem_write8(x + 0x1Du, DATA8(indexed_table_02FACE_ADDRESS + ((t1 & 0x7Fu) >> 1)));
	return u;
}

void sub_02E306(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, t1 & 0xBFu);
	mem_write8(x, 0x80u);
	d = 0x2401u;
	carry = sub_078680(d);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0xFF80u);
	mem_write16(x + 0x19u, 0x300u);
	mem_write8(x + 0x3Bu, 0x20u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
}

void sub_02E331(uint16_t x)
{
	uint8_t t3 = 0, t4 = 0;
	uint16_t t1 = 0, t2 = 0;

	mem_write8(x, 0x90u);
	t1 = mem_read16(x + 0xAu);
	t2 = t1 - 0x101u;
	mem_write16(x + 0xAu, t2);
	t3 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t3 - 1u);
	if (t3 == 1u)
	{
		mem_write8(x + 0x3Bu, 0x10u);
		mem_write16(x + 0x14u, 0u);
		mem_write16(x + 0x19u, 0u);
		t4 = mem_read8(x + 2u);
		mem_write8(x + 2u, t4 + 1u);
	}
}

void sub_02E353(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x, 0x90u);
	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
		mem_write8(x, 0u);
}

void sub_02E367(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0;

	u = object_setup_02FADE_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 0x80u);
	mem_write8(x + 9u, 0x10u);
	mem_write16(x + 0xAu, 0x4040u);
	t1 = mem_read8(x + 0x30u);
	mem_write8(x + 5u, t1 | 0x80u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_02E39E(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t ignored16 = 0, u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0;

	u = object_setup_02FAFA_ADDRESS;
	y = sub_0785AB(x, u);
	u = sub_02E2F7(x);
	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t1 & 0xCFu) | 0x10u);
	t2 = io_read8(VIDEO_187C);
	io_write8(VIDEO_187C, 0u);
	t3 = io_read8(VIDEO_187D);
	io_write8(VIDEO_187D, 0u);
	mem_write8(x + 0x3Du, 0u);
	t4 = mem_read8(x + 0x30u);
	a = t4;
	if ((int8_t)t4 >= 0)
	{
		t5 = io_read8(VIDEO_1874);
		if (t5 > 2u)
		{
			y = DATA16(indexed_table_02FB00_ADDRESS + (uint8_t)((a & 3u) << 1));
			sub_07862C(x, y, &u, &ignored16, &carry);
		}
	}
	t6 = mem_read8(x + 0x30u);
	mem_write8(x + 5u, ((uint32_t)t6 << 1) | 0x80u);
	mem_write8(x + 0x3Bu, 0x40u);
	mem_write16(x + 0xFu, 0xFF00u);
	t7 = mem_read8(x + 2u);
	mem_write8(x + 2u, t7 + 1u);
	sub_0785C6(x);
	*p_y = y;
	*p_u = u;
}

void sub_02E3EE(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(x + 0xFu, 0u);
		mem_write8(x + 2u, 5u);
		return;
	}
	t2 = io_read8(VIDEO_187C);
	if (t2 != 0u)
	{
		t3 = mem_read8(x + 2u);
		mem_write8(x + 2u, t3 + 1u);
	}
}

void sub_02E406(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t ignored16 = 0, u_2 = 0, y_2 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	mem_write16(x + 0xFu, 0u);
	t1 = mem_read8(x + 0x3Du);
	if (t1 == 0u)
	{
		mem_write8(x + 0x3Bu, 0u);
		mem_write8(x + 2u, 5u);
		return;
	}
	t2 = io_read8(VIDEO_187C);
	io_write8(VIDEO_187C, t2 + 1u);
	t3 = mem_read8(x + 0x30u);
	y_2 = DATA16(indexed_table_02FB28_ADDRESS + (int8_t)((uint32_t)t3 << 1));
	sub_07862C(x, y_2, &u_2, &ignored16, &carry);
	mem_write8(x, 0x80u);
	mem_write8(x + 5u, 0x8Au);
	t4 = mem_read8(x + 2u);
	mem_write8(x + 2u, t4 + 1u);
	*p_y = y_2;
	*p_u = u_2;
}

void sub_02E435(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
	{
		sub_02E46C();
		return;
	}
	t2 = mem_read8(x + 0x3Du);
	if (t2 != 0u)
	{
		t3 = mem_read8(x + 2u);
		mem_write8(x + 2u, t3 + 1u);
		mem_write8(x + 5u, 0x88u);
		sub_02E44E(x);
		return;
	}
	mem_write8(x + 2u, 6u);
}

void sub_02E44E(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0, t3 = 0, t5 = 0;
	uint16_t t4 = 0, t6 = 0;

	mem_write16(x + 0xFu, 0x180u);
	t1 = io_read8(VIDEO_187D);
	io_write8(VIDEO_187D, t1 + 1u);
	t2 = io_read8(VIDEO_187D);
	if (t2 == 1u)
	{
		t3 = mem_read8(x + 0x30u);
		if ((int8_t)t3 < 0)
		{
			sub_0785C6(x);
			return;
		}
		t4 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t4);
		sub_0785C6(x);
		return;
	}
	t5 = mem_read8(x + 0x30u);
	if ((int8_t)t5 >= 0)
	{
		sub_0785C6(x);
		return;
	}
	t6 = mem_read16(x + 0xFu);
	mem_write16(x + 0xFu, 0u - t6);
	sub_0785C6(x);
}

void sub_02E46C(void)
{
}

void sub_02E479(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 5u);
	mem_write8(x + 5u, (t1 + 1u) | 0x80u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
}

void sub_02E486(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	t2 = mem_read8(x + 0x30u);
	mem_write8(x + 5u, ((uint32_t)t2 << 1) | 0x80u);
	mem_write8(x + 2u, 4u);
	sub_02E44E(x);
}

void sub_02E4B6(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0;

	u = object_setup_02FB5E_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write16(x + 0xFu, 0xFF00u);
	mem_write8(x + 0x3Bu, 0x40u);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	sub_0785C6(x);
	*p_y = y;
	*p_u = u;
}

void sub_02E4CD(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(x + 0xFu, 0u);
		mem_write8(x + 2u, 5u);
	}
}

void sub_02E4DB(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t ignored16 = 0, u_2 = 0, y_2 = 0;
	uint8_t t1 = 0, t2 = 0;

	mem_write16(x + 0xFu, 0u);
	t1 = mem_read8(x + 0x3Du);
	if (t1 == 0u)
		return;
	y_2 = child_object_02FB64_ADDRESS;
	sub_07862C(x, y_2, &u_2, &ignored16, &carry);
	mem_write8(x, 0x80u);
	mem_write8(x + 5u, 0x82u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	*p_y = y_2;
	*p_u = u_2;
}

void sub_02E4F7(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
	{
		sub_02E50A();
		return;
	}
	mem_write16(x + 0xFu, 0xFE00u);
	mem_write8(x + 5u, 0x80u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	sub_02E50A();
}

void sub_02E50A(void)
{
}

void sub_02E50B(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 5u, 0x83u);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
}

void sub_02E514(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 5u, 0x81u);
		mem_write16(x + 0xFu, 0xFF00u);
		mem_write8(x + 2u, 4u);
	}
}

void sub_02E533(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x30u);
	u = DATA16(indexed_table_02FB7A_ADDRESS + (int8_t)((uint32_t)t1 << 1));
	y = sub_0785AB(x, u);
	mem_write8(x + 0x3Du, 0u);
	mem_write8(x + 0x3Bu, 0x40u);
	mem_write16(x + 0xFu, 0xFF00u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	sub_0785C6(x);
	*p_y = y;
	*p_u = u;
}

void sub_02E553(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(x + 0xFu, 0u);
		mem_write8(x + 2u, 5u);
	}
}

void sub_02E561(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0;

	mem_write16(x + 0xFu, 0u);
	t1 = mem_read8(x + 0x30u);
	y = DATA16(indexed_table_02FB92_ADDRESS + (int8_t)((uint32_t)t1 << 1));
	sub_07862C(x, y, &u, &ignored16, &carry);
	if (carry == 0u)
	{
		mem_write16(x + 0x38u, 0xFFFFu);
		mem_write16(x + 0xFu, 0xFE80u);
		mem_write8(x + 2u, 4u);
	}
	else
	{
		mem_write16(x + 0x38u, u);
		mem_write8(x, 0x80u);
		mem_write8(x + 5u, 0x84u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
	*p_y = y;
	*p_u = u;
}

void sub_02E595(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
	{
		sub_02E5A9();
		return;
	}
	mem_write8(x + 5u, 0x80u);
	mem_write16(x + 0xFu, 0xFE80u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	sub_02E5A9();
}

void sub_02E5A9(void)
{
}

void sub_02E5AA(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 5u);
	mem_write8(x + 5u, (t1 + 1u) | 0x80u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
}

void sub_02E5B7(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 5u, 0x81u);
		mem_write16(x + 0xFu, 0xFF00u);
		mem_write8(x + 2u, 4u);
	}
}

uint16_t sub_02E5D3(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t1 = 0, t2 = 0;

	u = object_setup_02FB80_ADDRESS;
	sub_0785AB(x, u);
	mem_write8(x + 5u, 0x80u);
	u = indexed_table_02FBB8_ADDRESS;
	t1 = mem_read8(x + 0x30u);
	mem_write8(x + 4u, DATA8(indexed_table_02FBB8_ADDRESS + (int8_t)t1));
	mem_write8(x, 0x80u);
	mem_write16(x + 0xAu, 0x4040u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	return u;
}

void sub_02E5F8(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 5u);
	mem_write8(x + 5u, (t1 + 1u) | 0x80u);
	t2 = mem_read8(x + 9u);
	mem_write8(x + 9u, t2 & 0xBFu);
	mem_write8(x, 0x80u);
	d = 0x2401u;
	carry = sub_078680(d);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0xFF80u);
	mem_write16(x + 0x19u, 0x100u);
	mem_write8(x + 0x3Bu, 0x20u);
	t3 = mem_read8(x + 2u);
	mem_write8(x + 2u, t3 + 1u);
}

void sub_02E635(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint8_t b = 0;
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t5 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0;

	u = object_setup_02FBD9_ADDRESS;
	sub_0785AB(x, u);
	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 0x30u);
	u = 0x7BCBu + (int8_t)(((uint32_t)t1 << 1) << 1);
	t2 = DATA16(u);
	b = (uint8_t)t2;
	mem_write8(x + 4u, t2 >> 8);
	if ((int8_t)b < 0)
	{
		mem_write8(x + 9u, 0x40u);
		b &= 0x7Fu;
	}
	t3 = (uint32_t)b << 4;
	mem_write16(x + 0x3Eu, t3);
	t4 = mem_read16(u + 2u);
	y = t4;
	mem_write16(x + 0x2Au, y);
	mem_write8(x + 5u, mem_read8(y));
	mem_write8(x + 0x3Bu, 0x40u);
	t5 = mem_read8(x + 2u);
	mem_write8(x + 2u, t5 + 1u);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_02E673(uint16_t x, uint16_t u)
{
	uint8_t t1 = 0, t3 = 0, t4 = 0;
	uint16_t t2 = 0;

	t1 = io_read8(VIDEO_1884);
	if (t1 != 0u)
	{
		t2 = mem_read16(x + 0x2Au);
		u = t2;
		t3 = mem_read8(u + 1u);
		mem_write8(x + 5u, t3);
		t4 = mem_read8(x + 2u);
		mem_write8(x + 2u, t4 + 1u);
	}
	return u;
}

uint16_t sub_02E686(uint16_t x, uint16_t u)
{
	uint32_t carry = 0;
	uint16_t u_2 = 0;
	uint8_t t1 = 0, t3 = 0, t4 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
	{
		sub_02E6A1();
		return u;
	}
	mem_write16(x + 0xFu, 0xFE00u);
	t2 = mem_read16(x + 0x2Au);
	u_2 = t2;
	t3 = mem_read8(u_2 + 2u);
	mem_write8(x + 5u, t3);
	t4 = mem_read8(x + 2u);
	mem_write8(x + 2u, t4 + 1u);
	sub_0785C6(x);
	return u_2;
}

void sub_02E6A1(void)
{
}

uint16_t sub_02E6AE(uint16_t x)
{
	uint8_t a = 0, d = 0;
	uint16_t u = 0, y = 0;
	uint8_t t3 = 0, t4 = 0, t6 = 0, t7 = 0, t9 = 0;
	uint16_t t1 = 0, t2 = 0, t5 = 0, t8 = 0;

	u = object_setup_02FC53_ADDRESS;
	y = sub_0785AB(x, u);
	t1 = mem_read16(x + 0x11u);
	t2 = t1 + 2u;
	mem_write16(x + 0x11u, t2);
	mem_write16(x + 0x5Cu, 0u);
	t3 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t3 & 0xCFu) | 0x20u);
	mem_write8(x + 0x57u, 0xFFu);
	mem_write8(x, 4u);
	mem_write8(x + 0x42u, 0xFFu);
	mem_write8(x + 0x43u, 1u);
	mem_write16(x + 0x2Au, enemy_behaviour_02FBEF_ADDRESS);
	mem_write8(x + 0x3Au, 0x10u);
	t4 = mem_read8(x + 0x30u);
	u = loaded_table_02FC59_ADDRESS + (int8_t)(((uint32_t)t4 << 1) << 1);
	t5 = DATA16(u);
	d = (uint8_t)t5;
	a = (uint8_t)(t5 >> 8);
	mem_write16(x + 0x3Eu, ((uint32_t)a << 8) | (d & 0xFFu));
	if ((uint16_t)(((uint32_t)a << 8) | (d & 0xFFu)) >= 0x100u)
	{
		t6 = mem_read8(x + 9u);
		a = t6 | 0x40u;
	}
	else
	{
		t7 = mem_read8(x + 9u);
		a = t7 & 0xBFu;
	}
	mem_write8(x + 9u, a);
	t8 = mem_read16(u + 2u);
	mem_write16(x + 0x3Bu, t8);
	mem_write8(x + 0x30u, 0u);
	t9 = mem_read8(x + 2u);
	mem_write8(x + 2u, t9 + 1u);
	return y;
}

uint16_t sub_02E71C(uint16_t x, uint16_t y)
{
	uint16_t ignored16 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_02E725(x, 0u);
		return y;
	case 2:
		sub_02E744(x);
		return y;
	case 4:
		sub_02E765(x);
		return y;
	case 6:
		sub_02E770(x);
		return y;
	case 8:
		sub_02E78A(x);
		return y;
	case 10:
		sub_02E793(x, &y, &ignored16);
		return y;
	case 12:
		sub_02E7B9(x);
		return y;
	}
	unreachable();
}

uint16_t sub_02E725(uint16_t x, uint16_t u)
{
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = unk_48AC;
	if (t1 < 0x3D0u)
		return u;
	mem_write8(x, 0x80u);
	mem_write8(x + 0x57u, 0u);
	u = sub_078620(x);
	sub_078626(x, u);
	mem_write8(x + 5u, 0x86u);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	return u;
}

void sub_02E744(uint16_t x)
{
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(x + 0x42u, 0u);
	d = rom_07E040_ADDRESS;
	sub_078617(x, d);
	t2 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t2 & 0xCFu) | 0x10u);
	mem_write8(x + 5u, 0x82u);
	t3 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t3 + 1u);
}

void sub_02E765(uint16_t x)
{
	uint32_t negative = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	d = 0u;
	sub_078638(x, &d, &negative);
	if ((int8_t)(d >> 8) >= 0)
	{
		t1 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t1 + 1u);
	}
}

void sub_02E770(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry == 0u)
		return;
	mem_write8(x, 0xC0u);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write8(x + 2u, 2u);
	mem_write8(x + 0x3Bu, 0u);
}

void sub_02E78A(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 5u, 0x90u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

void sub_02E793(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		if (unk_486B >= 3u)
		{
			sub_02E7C1(x, &y, &u, &carry);
			if (carry == 0u)
				sub_02E7B9(x);
			else
			{
				t2 = mem_read8(x + 0x29u);
				mem_write8(x + 0x29u, t2 + 1u);
				d = 0x6100u;
				carry = sub_078680(d);
			}
		}
		else
		{
			t3 = mem_read8(x + VIDEO_003C);
			mem_write8(x + VIDEO_003C, t3 - 1u);
			t4 = mem_read8(x + VIDEO_003C);
			if ((t4 & 3u) == 0u)
				sub_02E7B9(x);
			else
			{
				sub_02E7C1(x, &y, &u, &carry);
				if (carry == 0u)
					sub_02E7B9(x);
				else
				{
					t2 = mem_read8(x + 0x29u);
					mem_write8(x + 0x29u, t2 + 1u);
					d = 0x6100u;
					carry = sub_078680(d);
				}
			}
		}
	}
	*p_y = y;
	*p_u = u;
}

void sub_02E7B9(uint16_t x)
{
	mem_write8(x + 5u, 0x81u);
	mem_write8(x + 2u, 2u);
	mem_write8(x + 0x3Bu, 0u);
}

void sub_02E7C1(uint16_t x, uint16_t *p_y, uint16_t *p_u, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t ignored16 = 0, u = 0, y = 0;
	uint8_t t2 = 0, t3 = 0;
	uint16_t t1 = 0;

	y = child_object_02FC73_ADDRESS;
	sub_07862F(x, y, &ignored16, &carry);
	t1 = mem_read16(x + 0x40u);
	u = t1;
	t2 = mem_read8(u + 9u);
	unk_48F0 = t2 & 0x30u;
	t3 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t3 & 0xCFu) | unk_48F0);
	*p_y = y;
	*p_u = u;
	*p_carry = carry;
}

uint16_t sub_02E7E4(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0;
	uint16_t t1 = 0;

	u = object_setup_02FC81_ADDRESS;
	sub_0785AB(x, u);
	mem_write8(x, 0x80u);
	t1 = mem_read16(x + 0x40u);
	u = t1;
	t2 = mem_read8(u + 9u);
	unk_48F0 = t2 & 0x70u;
	t3 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t3 & 0x8Fu) | unk_48F0);
	t4 = mem_read8(x + 2u);
	mem_write8(x + 2u, t4 + 1u);
	return u;
}

void sub_02E809(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) != 0u)
	{
		mem_write8(x, 0xC0u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_02E819(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	sub_02E821(x);
}

void sub_02E821(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
		mem_write8(x, 0u);
}

void sub_02E834(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0;

	u = object_setup_02FC99_ADDRESS;
	y = sub_0785AB(x, u);
	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t1 & 0xCFu) | 0x20u);
	mem_write8(x + VIDEO_003C, 6u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_02E84D(uint16_t x, uint16_t u)
{
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	if ((mem_read8(x) & 0x20u) == 0u)
		return u;
	t1 = mem_read8(x + VIDEO_003C);
	mem_write8(x + VIDEO_003C, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 5u, 0x83u);
		mem_write8(x + 2u, 4u);
		return u;
	}
	u = indexed_table_02FC9F_ADDRESS;
	t2 = mem_read8(x + VIDEO_003C);
	mem_write8(x + 5u, DATA8(indexed_table_02FC9F_ADDRESS + (int8_t)t2));
	mem_write8(x, 0x80u);
	mem_write8(x + 0x3Bu, 0x20u);
	t3 = mem_read8(x + 2u);
	mem_write8(x + 2u, t3 + 1u);
	return u;
}

void sub_02E87D(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 5u, 0x80u);
		mem_write8(x + 0x3Bu, 0x40u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_02E890(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
	{
		sub_02E89F();
		return;
	}
	mem_write8(x, 0xC0u);
	mem_write8(x + 2u, 1u);
	sub_02E89F();
}

void sub_02E89F(void)
{
}

void sub_02E8D8(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t5 = 0;
	uint16_t t3 = 0, t4 = 0;

	u = object_setup_02FDBF_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 4u);
	t1 = io_read8(VIDEO_1881);
	io_write8(VIDEO_1881, 0u);
	t2 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t2 & 0xCFu) | 0x20u);
	t3 = mem_read16(x + 0xCu);
	t4 = t3 + 0x40u;
	mem_write16(x + 0xCu, t4);
	t5 = mem_read8(x + 2u);
	mem_write8(x + 2u, t5 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_02E8FE(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint8_t a = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	unk_48A7--;
	t1 = io_read8(VIDEO_1876);
	if (t1 < 2u)
	{
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
		mem_write8(x + 0x3Au, 0u);
		unk_48F0 = 3u;
		unk_48F1 = 0x40u;
		do
		{
			y = child_object_02FDA7_ADDRESS;
			sub_07862F(x, y, &u, &carry);
			if (carry == 0u)
				break;
			mem_write16(u + 0x38u, x);
			t3 = mem_read8(x + 0x3Au);
			mem_write8(x + 0x3Au, t3 + 1u);
			mem_write8(u + 0x3Fu, 0x80u);
			a = unk_48F1;
			mem_write8(u + 0x3Eu, a);
			unk_48F1 = a + 0x55u;
			mem_write8(u + 0x32u, (((uint32_t)unk_48F0 << 1) << 1) << 1);
			t4 = unk_48F0;
			unk_48F0 = t4 - 1u;
		} while (t4 != 1u);
	}
	*p_y = y;
	*p_u = u;
}

void sub_02E945(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = io_read8(VIDEO_1884);
	if (t1 != 0u)
	{
		mem_write8(x + 0x3Bu, 0x40u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_02E954(uint16_t x)
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

void sub_02E95D(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = io_read8(VIDEO_1876);
	if (t1 < 2u)
	{
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_02E969(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t ignored16 = 0, u_2 = 0, y_2 = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Au);
	if (t1 != 0u)
		return;
	t2 = mem_read8(x + VIDEO_0031);
	if (t2 != 0u)
		return;
	mem_write8(x, 0u);
	y_2 = child_object_02FDAD_ADDRESS;
	*p_u = u_2;
	sub_07862C(x, y_2, p_u, &ignored16, &carry);
	*p_y = y_2;
}

uint16_t sub_02E983(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	u = object_setup_02FDBF_ADDRESS;
	sub_0785AB(x, u);
	mem_write8(x, 4u);
	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t1 & 0xCFu) | 0x10u);
	mem_write8(x + 0x3Bu, 1u);
	u = sub_02EA59(x);
	t2 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t2 + 1u);
	t3 = mem_read8(x + 2u);
	mem_write8(x + 2u, t3 + 1u);
	return u;
}

uint16_t sub_02E9A7(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t ignored16 = 0, u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	mem_write8(x + 0x3Au, 0u);
	mem_write8(x + 0x30u, 0u);
	unk_48F0 = 2u;
	unk_48F1 = 0x40u;
	do
	{
		y = child_object_02FDC5_ADDRESS;
		sub_07862C(x, y, &u, &ignored16, &carry);
		if (carry == 0u)
			break;
		t1 = mem_read8(x + 0x3Au);
		mem_write8(x + 0x3Au, t1 + 1u);
		t2 = mem_read8(x + 0x30u);
		mem_write8(x + 0x30u, t2 + 1u);
		mem_write8(u + 0x3Fu, 0x40u);
		a = unk_48F1;
		mem_write8(u + 0x3Eu, a);
		unk_48F1 = a - 0x80u;
		a = unk_48F0;
		mem_write8(u + 0x3Du, a);
		t3 = mem_read8(x + 0x32u);
		mem_write8(u + 0x32u, a + t3);
		mem_write8(u + 0x3Bu, 1u);
		t4 = unk_48F0;
		unk_48F0 = t4 - 1u;
	} while (t4 != 1u);
	return y;
}

uint16_t sub_02E9E8(uint16_t x, uint32_t y)
{
	uint16_t u = 0;
	uint8_t t1 = 0, t3 = 0, t4 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 0x28u);
	if (t1 != 0u)
	{
		mem_write8(x + 0x28u, 0u);
		sub_02E9A7(x);
	}
	t2 = mem_read16(x + 0x38u);
	u = t2;
	t3 = mem_read8(u + 2u);
	if (t3 == 2u)
	{
		mem_write8(x + 0x3Bu, 1u);
		t4 = mem_read8(x + 2u);
		mem_write8(x + 2u, t4 + 1u);
	}
	return u;
}

uint16_t sub_02EA06(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t1 = 0, t3 = 0, t4 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 0x3Bu, 1u);
		sub_02EA59(x);
	}
	t2 = mem_read16(x + 0x38u);
	u = t2;
	t3 = mem_read8(u + 2u);
	if (t3 == 3u)
	{
		mem_write8(x + 0x3Bu, 1u);
		mem_write8(x + VIDEO_003C, 0x40u);
		t4 = mem_read8(x + 2u);
		mem_write8(x + 2u, t4 + 1u);
	}
	return u;
}

uint16_t sub_02EA29(uint16_t x, uint16_t u)
{
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return u;
	mem_write8(x + 0x3Bu, 1u);
	u = sub_02EA59(x);
	t2 = mem_read8(x + VIDEO_003C);
	mem_write8(x + VIDEO_003C, t2 - 1u);
	if (t2 == 1u)
	{
		t3 = mem_read8(x + 2u);
		mem_write8(x + 2u, t3 + 1u);
	}
	return u;
}

uint16_t sub_02EA3E(uint16_t x, uint16_t u)
{
	uint8_t t1 = 0, t2 = 0, t4 = 0;
	uint16_t t3 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 0x3Bu, 1u);
		u = sub_02EA59(x);
	}
	t2 = mem_read8(x + 0x3Au);
	if (t2 == 0u)
	{
		t3 = mem_read16(x + 0x38u);
		u = t3;
		t4 = mem_read8(u + 0x3Au);
		mem_write8(u + 0x3Au, t4 - 1u);
		mem_write8(x, 0u);
	}
	return u;
}

uint16_t sub_02EA59(uint16_t x)
{
	uint16_t d = 0, u = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;
	uint32_t unk_48EA_halfword = 0;

	t1 = mem_read16(x + 0x38u);
	u = t1;
	t2 = mem_read16(x + 0x3Eu);
	d = (t2 & 0xFFu) | ((uint32_t)(uint8_t)((t2 >> 8) - 1u) << 8);
	mem_write8(x + 0x3Eu, d >> 8);
	sub_02F257(d);
	t3 = mem_read16(u + 0xCu);
	t4 = mem_read16(x + 0xCu);
	mem_write16(x + 0xFu, (uint32_t)(uint8_t)(t3 + (((uint32_t)unk_48E8 << 8u) | unk_48E9) - t4) << 8);
	unk_48EA_halfword = (int16_t)(((uint32_t)unk_48EA << 8u) | unk_48EB) >> 1;
	unk_48EA = (uint8_t)(unk_48EA_halfword >> 8u);
	unk_48EB = (uint8_t)unk_48EA_halfword;
	t5 = mem_read16(u + 0x11u);
	t6 = mem_read16(x + 0x11u);
	mem_write16(x + 0x14u, (uint32_t)(uint8_t)(t5 + (((uint32_t)unk_48EA << 8u) | unk_48EB) - t6) << 8);
	return u;
}

uint16_t sub_02EA8F(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t u = 0;
	uint8_t t2 = 0, t3 = 0, t6 = 0;
	uint16_t t1 = 0, t4 = 0, t5 = 0;

	u = object_setup_02FDD3_ADDRESS;
	sub_0785AB(x, u);
	t1 = mem_read16(x + 0x40u);
	u = t1;
	t2 = mem_read8(u + 9u);
	mem_write8(x + 9u, t2 & 0x30u);
	mem_write8(x, 0x88u);
	mem_write16(x + 0x19u, 0x400u);
	b = unk_4858;
	mem_write16(x + 0xFu, 0x100u | b);
	carry = (b >> 0) & 1u;
	if (carry)
	{
		t3 = mem_read8(x + 0x3Du);
		mem_write8(x + 0x3Du, t3 + 1u);
		mem_write8(x + 5u, 0xB9u);
	}
	t4 = mem_read16(x + 0xCu);
	if (t4 >= 0xE0u)
	{
		t5 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t5);
	}
	t6 = mem_read8(x + 2u);
	mem_write8(x + 2u, t6 + 1u);
	sub_0785C6(x);
	return u;
}

void sub_02EACF(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t3 = 0, t4 = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = mem_read16(x + 0x19u);
	t2 = t1 - 0x18u;
	mem_write16(x + 0x19u, t2);
	carry = sub_078662(x);
	if (carry == 0u)
		return;
	t3 = mem_read8(x + 0x3Du);
	if (t3 == 0u)
		mem_write8(x + 5u, 0xBBu);
	else
		mem_write8(x + 5u, 0xBAu);
	mem_write16(x + 0xFu, 0u);
	mem_write8(x + 0x3Bu, 0x20u);
	t4 = mem_read8(x + 2u);
	mem_write8(x + 2u, t4 + 1u);
}

void sub_02EAFA(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x, (mem_read8(x) ^ 0x80u) | 4u);
	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
		mem_write8(x, 0u);
}

uint16_t sub_02EB33(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, u = 0, y = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0;
	uint16_t t1 = 0;

	d = 0x6C00u;
	carry = sub_078680(d);
	t1 = mem_read16(x + 0x2Au);
	u = t1;
	t2 = mem_read8(u + VIDEO_0031);
	mem_write8(u + VIDEO_0031, t2 - 1u);
	t3 = mem_read8(u + VIDEO_0031);
	if ((int8_t)t3 < 0)
		mem_write8(u + VIDEO_0031, 0u);
	mem_write8(x, 0u);
	t4 = mem_read8(x + 0x27u);
	mem_write8(x + 0x27u, t4 | 0x80u);
	y = child_object_02FDF3_ADDRESS;
	sub_07862F(x, y, &ignored16, &carry);
	return sub_0785F0(x);
}

uint16_t sub_02EB5B(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_02EB81(x);
		break;
	case 2:
		sub_02EBCA(x);
		break;
	case 4:
		sub_02EC08();
		break;
	}
	return sub_02EDA9(x, y);
}

void sub_02EB67(uint16_t x)
{
	uint8_t a = 0;
	uint16_t u = 0;
	uint8_t t1 = 0, t2 = 0;

	u = constant_table_02FDFF_ADDRESS;
	t1 = mem_read8(x + 0x1Bu);
	if (t1 >= 7u)
		a = 1u;
	else
		a = 0u;
	t2 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t2 & 0x30u) | DATA8(u + a));
}

void sub_02EB81(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t6 = 0;
	uint16_t t3 = 0, t4 = 0, t5 = 0;

	mem_write8(x + 5u, 0x84u);
	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t1 & ~0xFu) | 9u);
	mem_write8(x, 0x88u);
	mem_write8(x + 0x3Bu, 0x10u);
	mem_write16(x + 0xFu, 0x200u);
	t2 = mem_read8(x + VIDEO_0031);
	if (t2 != 0u)
	{
		t3 = mem_read16(x + 0xCu);
		if (t3 >= 0xE0u)
		{
			t4 = mem_read16(x + 0xFu);
			mem_write16(x + 0xFu, 0u - t4);
		}
	}
	else
	{
		carry = (unk_4858 >> 0) & 1u;
		if (carry)
		{
			t5 = mem_read16(x + 0xFu);
			mem_write16(x + 0xFu, 0u - t5);
		}
	}
	mem_write16(x + 0x19u, 0x200u);
	t6 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t6 + 1u);
	d = 0x6300u;
	carry = sub_078680(d);
}

void sub_02EBCA(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t7 = 0;
	uint16_t t5 = 0, t6 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	t2 = mem_read8(x + 0x3Bu);
	if (t2 > 0x10u)
		sub_02EB67(x);
	else
	{
		t3 = mem_read8(x + 9u);
		mem_write8(x + 9u, t3 ^ 0x80u);
		t4 = mem_read8(x + 6u);
		mem_write8(x + 6u, t4 | 0x80u);
	}
	t5 = mem_read16(x + 0x19u);
	t6 = t5 - 0x20u;
	mem_write16(x + 0x19u, t6);
	carry = sub_078662(x);
	if (carry == 0u)
	{
		sub_02EC08();
		return;
	}
	d = 0x6B00u;
	carry = sub_078680(d);
	mem_write8(x + 5u, 0x83u);
	t7 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t7 + 1u);
	sub_02EB67(x);
}

void sub_02EC08(void)
{
}

uint16_t sub_02EC09(uint16_t x)
{
	uint16_t u = 0, y = 0;
	uint8_t t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0;
	uint16_t t1 = 0, t2 = 0;

	u = object_setup_02FE01_ADDRESS;
	y = sub_0785AB(x, u);
	t1 = mem_read16(x + 0x40u);
	t2 = mem_read16(t1 + 0x38u);
	mem_write16(x + 0x2Au, t2);
	mem_write8(x + 0x5Bu, 1u);
	t3 = mem_read8(x + 0x57u);
	mem_write8(x + 0x57u, t3 + 1u);
	t4 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t4 & 0xCFu) | 0x20u);
	mem_write8(x, 4u);
	t5 = mem_read8(x + 0x42u);
	mem_write8(x + 0x42u, t5 - 1u);
	t6 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t6 + 1u);
	sub_02EC9C(x);
	t7 = mem_read8(x + 2u);
	mem_write8(x + 2u, t7 + 1u);
	return y;
}

void sub_02EC3B(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0, t4 = 0, t5 = 0;
	uint16_t t3 = 0;

	t1 = mem_read8(x + 0x28u);
	if (t1 != 0u)
	{
		t2 = mem_read8(x + 0x32u);
		mem_write8(x + 8u, t2);
		mem_write8(x + 0x28u, 0u);
	}
	t3 = mem_read16(x + 0x40u);
	t4 = mem_read8(t3 + 2u);
	if (t4 != 2u)
		return;
	t5 = mem_read8(x + 2u);
	mem_write8(x + 2u, t5 + 1u);
	sub_02EC9C(x);
}

void sub_02EC59(uint16_t x)
{
	uint8_t t1 = 0, t3 = 0, t4 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x, 0x80u);
		mem_write8(x + 0x3Bu, 1u);
		sub_02EC9C(x);
	}
	t2 = mem_read16(x + 0x40u);
	t3 = mem_read8(t2 + 2u);
	if (t3 == 3u)
	{
		mem_write8(x + 4u, 0x88u);
		mem_write8(x + 5u, 0x82u);
		t4 = mem_read8(x + 2u);
		mem_write8(x + 2u, t4 + 1u);
	}
}

void sub_02EC82(uint16_t x)
{
	uint8_t t1 = 0, t3 = 0, t4 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 0x3Bu, 1u);
		sub_02EC9C(x);
	}
	t2 = mem_read16(x + 0x40u);
	t3 = mem_read8(t2 + 2u);
	if (t3 == 4u)
	{
		t4 = mem_read8(x + 2u);
		mem_write8(x + 2u, t4 + 1u);
	}
}

void sub_02EC9C(uint16_t x)
{
	uint8_t a = 0;
	uint16_t d = 0, u = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0, t5 = 0;
	uint16_t t1 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0;
	uint32_t unk_48EA_halfword = 0, unk_48EA_halfword_2 = 0;

	t1 = mem_read16(x + 0x40u);
	u = t1;
	t2 = mem_read8(x + 0x30u);
	if (t2 != 1u)
	{
		t3 = mem_read8(x + 0x3Eu);
		a = t3 + 2u;
	}
	else
	{
		t4 = mem_read8(x + 0x3Eu);
		a = t4 + 4u;
	}
	mem_write8(x + 0x3Eu, a);
	t5 = mem_read8(x + 0x3Fu);
	mem_write8(x + 0x3Eu, a);
	d = ((uint32_t)a << 8) | t5;
	sub_02F257(d);
	t6 = mem_read16(u + 0xCu);
	t7 = mem_read16(x + 0xCu);
	a = (uint8_t)((((uint32_t)a << 8) | (uint8_t)((((uint32_t)a << 8) | (uint8_t)t6) + (((uint32_t)unk_48E8 << 8u) | unk_48E9))) - t7);
	mem_write16(x + 0xFu, (uint32_t)a << 8);
	unk_48EA_halfword = (int16_t)(((uint32_t)unk_48EA << 8u) | unk_48EB) >> 1;
	unk_48EA = (uint8_t)(unk_48EA_halfword >> 8u);
	unk_48EB = (uint8_t)unk_48EA_halfword;
	unk_48EA_halfword_2 = (int16_t)(((uint32_t)unk_48EA << 8u) | unk_48EB) >> 1;
	unk_48EA = (uint8_t)(unk_48EA_halfword_2 >> 8u);
	unk_48EB = (uint8_t)unk_48EA_halfword_2;
	t8 = mem_read16(u + 0x11u);
	t9 = mem_read16(x + 0x11u);
	mem_write16(x + 0x14u, (uint32_t)(uint8_t)((((uint32_t)a << 8) | (uint8_t)((((uint32_t)a << 8) | (uint8_t)t8) + (((uint32_t)unk_48EA << 8u) | unk_48EB))) - t9) << 8);
}

uint16_t sub_02ECE3(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t u = 0;
	uint8_t t2 = 0, t3 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t12 = 0, t13 = 0;
	uint16_t t1 = 0, t4 = 0, t10 = 0, t11 = 0;

	sub_02EC9C(x);
	t1 = mem_read16(x + 0x40u);
	u = t1;
	t2 = mem_read8(u + 0x3Au);
	t3 = mem_read8(x + 0x3Du);
	if (t2 <= t3)
	{
		t4 = mem_read16(x + 0x2Au);
		y = t4;
		t5 = mem_read8(y + 0x3Du);
		if (t5 == 0u)
		{
			t6 = mem_read8(u + 0x3Eu);
			if ((uint8_t)(t6 + 0x60u) < 0x40u)
			{
				t7 = mem_read8(x + 0x3Eu);
				if ((t7 & 0x7Fu) < 8u)
					return y;
				t8 = mem_read8(u + 0x30u);
				mem_write8(u + 0x30u, t8 - 1u);
				t9 = mem_read8(y + VIDEO_0031);
				mem_write8(y + VIDEO_0031, t9 + 1u);
				t10 = (uint32_t)unk_4858 << 1;
				mem_write16(x + 0xFu, t10);
				carry = (unk_4858 >> 0) & 1u;
				if (carry)
				{
					t11 = mem_read16(x + 0xFu);
					mem_write16(x + 0xFu, 0u - t11);
				}
				mem_write16(x + 0x14u, 0xFE00u);
				mem_write16(x + 0x19u, 0x400u);
				mem_write8(x, 0xCCu);
				mem_write8(x + 0x57u, 0u);
				t12 = mem_read8(x + 9u);
				mem_write8(x + 9u, (t12 & 0xCFu) | 0x10u);
				t13 = mem_read8(x + 2u);
				mem_write8(x + 2u, t13 + 1u);
				y = hit_box_02FCD6_ADDRESS;
				sub_0785B4(x, y);
				mem_write8(x + 0x24u, 0x30u);
			}
		}
	}
	return y;
}

void sub_02ED4F(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0, u = 0;
	uint8_t t4 = 0, t5 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read16(x + 0x19u);
	t2 = t1 - 0x20u;
	mem_write16(x + 0x19u, t2);
	carry = sub_078662(x);
	if (carry == 0u)
		return;
	d = 0x6B00u;
	carry = sub_078680(d);
	t3 = mem_read16(x + 0x40u);
	u = t3;
	t4 = mem_read8(u + 0x3Au);
	mem_write8(u + 0x3Au, t4 - 1u);
	mem_write8(x + 5u, 0x80u);
	mem_write8(x + 0x42u, 0u);
	mem_write8(x, 0xC0u);
	mem_write8(x + 0x24u, 0x10u);
	mem_write8(x + 0x3Bu, 0x40u);
	mem_write8(x + VIDEO_0031, 0u);
	mem_write8(x + 0x30u, 0u);
	t5 = mem_read8(x + 2u);
	mem_write8(x + 2u, t5 + 1u);
}

uint16_t sub_02ED8A(uint16_t x)
{
	uint16_t y = 0;
	uint8_t t1 = 0;

	y = hit_box_02FCCE_ADDRESS;
	sub_0785B4(x, y);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	return sub_02ED93(x, y);
}

uint16_t sub_02ED93(uint16_t x, uint16_t y)
{
	uint16_t u = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return sub_02EDA9(x, y);
	mem_write8(x + 5u, 0x81u);
	u = sub_078620(x);
	sub_078626(x, u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	mem_write8(x + 0x29u, 0u);
	return sub_02EDA9(x, y);
}

uint16_t sub_02EDA9(uint16_t x, uint16_t y)
{
	uint32_t negative = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0;
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0;

	t1 = mem_read16(x + 0xCu);
	t2 = t1 - 0x40u;
	if (t2 < 0x140u)
		mem_write8(x + VIDEO_0031, 0u);
	else
	{
		t3 = mem_read8(x + VIDEO_0031);
		if (t3 != 0u)
		{
			sub_078647(x, &d, &negative);
			a = (uint8_t)(d >> 8);
			if ((int8_t)a < 0)
			{
				t4 = mem_read16(x + 0x14u);
				mem_write16(x + 0x14u, 0u - t4);
			}
			return y;
		}
		t5 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, (int16_t)t5 >> 1);
		t6 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t6);
		mem_write8(x + VIDEO_0031, 1u);
		b = unk_4858;
		mem_write16(x + 0x14u, 0xFF00u | b);
		if ((int8_t)b >= 0)
		{
			t7 = mem_read16(x + 0x14u);
			mem_write16(x + 0x14u, 0u - t7);
		}
		mem_write16(x + 0x19u, 0x200u);
		mem_write8(x, 0x88u);
		mem_write8(x + 2u, 9u);
		y = hit_box_02FCCE_ADDRESS;
		sub_0785B4(x, y);
		mem_write8(x + 5u, 0x81u);
	}
	sub_078647(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	if ((int8_t)a < 0)
	{
		t4 = mem_read16(x + 0x14u);
		mem_write16(x + 0x14u, 0u - t4);
	}
	return y;
}

void sub_02EDFC(uint16_t x, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t ignored16 = 0, u = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_02EE18(x);
		break;
	case 2:
		sub_02EE24(x);
		break;
	case 4:
		sub_02EE76(x);
		break;
	case 6:
		y = sub_02EEB1(x);
		break;
	case 8:
		sub_0785D5(x, &y, &ignored16);
		break;
	case 12:
	case 24:
	case 86:
		sub_0785DB(x, &y, &ignored16, p_left_caller);
		break;
	case 14:
	case 26:
	case 88:
		sub_0785DE(x, &y, &ignored16, p_left_caller);
		break;
	case 16:
	case 28:
	case 90:
		sub_07865C(x, &y, &ignored16);
		break;
	case 18:
	case 30:
	case 92:
		sub_0785E4(x, &y, &ignored16, p_left_caller);
		break;
	case 20:
		sub_02EF0F(x, &y, &ignored16);
		break;
	case 22:
		sub_02EF44(x, &y, &ignored16);
		break;
	}
	if ((unk_4815 & 0xFu) == 0u)
		sub_078620(x);
	t2 = mem_read16(x + 0x38u);
	u = t2;
	sub_078626(x, u);
	y = sub_02EDA9(x, y);
	*p_y = y;
}

void sub_02EE18(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x37u);
	mem_write8(x + 0x37u, t1 ^ 0x80u);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
}

void sub_02EE24(uint16_t x)
{
	uint8_t t2 = 0, t4 = 0, t5 = 0, t7 = 0, t8 = 0;
	uint16_t t1 = 0, t3 = 0, t6 = 0, t9 = 0;

	t1 = mem_read16(x + 0x2Cu);
	if (t1 < 0x40u)
	{
		mem_write16(x + 0x14u, 0u);
		mem_write16(x + 0xFu, 0x100u);
		t2 = mem_read8(x + 0x37u);
		if ((int8_t)t2 < 0)
		{
			t3 = mem_read16(x + 0xFu);
			mem_write16(x + 0xFu, 0u - t3);
		}
	}
	else
	{
		t4 = mem_read8(x + 0x36u);
		t5 = mem_read8(x + 0x37u);
		if ((int8_t)(t4 - 0x40u - t5) < 0)
		{
			mem_write16(x + 0x14u, 0u);
			mem_write16(x + 0xFu, 0x100u);
			t2 = mem_read8(x + 0x37u);
			if ((int8_t)t2 < 0)
			{
				t3 = mem_read16(x + 0xFu);
				mem_write16(x + 0xFu, 0u - t3);
			}
			t6 = mem_read16(x + 0x2Eu);
			if (t6 < 3u)
			{
				mem_write8(x + 0x3Bu, 0x10u);
				mem_write8(x + 5u, 0x82u);
				mem_write16(x + 0xFu, 0u);
				mem_write16(x + 0x14u, 0u);
				t7 = mem_read8(x + 0x29u);
				mem_write8(x + 0x29u, t7 + 1u);
			}
			return;
		}
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0x100u);
		t8 = mem_read8(x + 0x36u);
		if ((int8_t)t8 < 0)
		{
			t9 = mem_read16(x + 0x14u);
			mem_write16(x + 0x14u, 0u - t9);
		}
	}
	t6 = mem_read16(x + 0x2Eu);
	if (t6 < 3u)
	{
		mem_write8(x + 0x3Bu, 0x10u);
		mem_write8(x + 5u, 0x82u);
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
		t7 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t7 + 1u);
	}
}

void sub_02EE76(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0, t5 = 0, t6 = 0, t8 = 0, t9 = 0;
	uint16_t t3 = 0, t4 = 0, t7 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write16(x + 0x14u, 0u);
	mem_write16(x + 0xFu, 0x300u);
	t2 = mem_read8(x + VIDEO_0031);
	if (t2 != 0u)
	{
		t3 = mem_read16(x + 0xCu);
		if (t3 >= 0xE0u)
		{
			t4 = mem_read16(x + 0xFu);
			mem_write16(x + 0xFu, 0u - t4);
		}
		t5 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t5 + 1u);
		return;
	}
	t6 = mem_read8(x + 0x36u);
	if ((int8_t)(t6 - 0x40u) >= 0)
	{
		t7 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t7);
	}
	sub_0785C6(x);
	t8 = mem_read8(x + 9u);
	mem_write8(x + 9u, t8 ^ 0x40u);
	t9 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t9 + 1u);
}

uint16_t sub_02EEB1(uint16_t x)
{
	uint16_t y = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	t2 = mem_read8(x + 0x3Bu);
	if ((t2 & 7u) != 0u)
	{
		y = hit_box_02FCCE_ADDRESS;
		sub_0785B4(x, y);
		return y;
	}
	y = hit_box_02FCD6_ADDRESS;
	sub_0785B4(x, y);
	return y;
}

uint16_t sub_02EEC7(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0;
	uint8_t t1 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry == 0u)
		return sub_02EDA9(x, y);
	sub_02EB67(x);
	d = 0x6B00u;
	carry = sub_078680(d);
	mem_write8(x + 0x3Bu, 0x40u);
	mem_write8(x, 0xC0u);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	return sub_02EDA9(x, y);
}

uint16_t sub_02EEE5(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 0x3Bu, 0x10u);
		mem_write8(x + 2u, 7u);
	}
	return sub_02EDA9(x, y);
}

void sub_02EF0F(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	u = object_setup_02FE27_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x + 0x43u, 1u);
	t1 = mem_read8(x + 0x44u);
	mem_write8(x + 0x44u, t1 + 1u);
	u = enemy_behaviour_02FCE6_ADDRESS;
	mem_write16(x + 0x2Au, enemy_behaviour_02FCE6_ADDRESS);
	mem_write8(x + 0x3Au, 0x10u);
	t2 = mem_read8(x + 0x30u);
	if (t2 == 0u)
	{
		mem_write8(x + 0x30u, 0u);
		mem_write8(x + 2u, 2u);
	}
	else
	{
		mem_write8(x, 0x80u);
		mem_write8(x + 9u, 0x20u);
		t3 = mem_read8(x + 2u);
		mem_write8(x + 2u, t3 + 1u);
	}
	*p_y = y;
	*p_u = u;
}

void sub_02EF44(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t t1 = 0;

	u = loaded_table_02FE2D_ADDRESS;
	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_02EF4D(x);
		break;
	case 2:
		sub_02EF67(x);
		break;
	case 4:
		sub_02EF6B(x);
		break;
	case 6:
		sub_02EF79(x);
		break;
	case 8:
		sub_02EF8D(x);
		break;
	case 10:
		sub_02EFA5(x);
		break;
	case 12:
		sub_02EFC6(x);
		break;
	case 14:
		sub_02EFD5(x);
		break;
	case 16:
		y = sub_02EFE1(x, y);
		break;
	case 18:
		y = sub_02EFF2(x);
		break;
	case 20:
		sub_02EFFB(x);
		break;
	case 22:
	case 24:
		sub_02F00F(x, &y, &u);
		break;
	case 26:
		sub_02F02C(x, &y, &u);
		break;
	case 28:
	case 30:
		sub_02F055(x);
		break;
	case 32:
		sub_02F068(x);
		break;
	case 34:
		sub_02F018(x);
		break;
	case 36:
		sub_02F022(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_02EF4D(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 0x3Bu, 0x40u);
	mem_write16(x + 0x16u, 4u);
	mem_write8(x + 5u, 0x86u);
	mem_write16(x + 0x5Cu, 0u);
	mem_write8(x + 0x30u, 0u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

void sub_02EF67(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

void sub_02EF6B(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 0x3Bu, 0x20u);
		t2 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t2 + 1u);
	}
}

void sub_02EF79(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(x + 0x14u, 0xFF00u);
		mem_write8(x + 5u, 0x81u);
		t2 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t2 + 1u);
	}
}

void sub_02EF8D(uint16_t x)
{
	uint32_t negative = 0;
	uint8_t a = 0;
	uint16_t d = 0;

	d = 0u;
	sub_078638(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	if ((int8_t)a >= 0)
	{
		mem_write8(x, 0xC0u);
		mem_write8(x + 2u, 2u);
	}
}

void sub_02EFA5(uint16_t x)
{
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	mem_write8(x + 5u, 0x87u);
	sub_07859C(x);
	mem_write8(x + 0x3Bu, 0x20u);
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

void sub_02EFC6(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(x + 2u, 2u);
	mem_write8(x + 0x3Bu, 0u);
}

void sub_02EFD5(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 5u, 0x90u);
	sub_07859C(x);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

uint16_t sub_02EFE1(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) == 0u)
		return y;
	y = hit_box_02FCB6_ADDRESS;
	sub_0785B4(x, y);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	return y;
}

uint16_t sub_02EFF2(uint16_t x)
{
	uint16_t y = 0;
	uint8_t t1 = 0;

	y = hit_box_02FCA6_ADDRESS;
	sub_0785B4(x, y);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	sub_02EFFB(x);
	return y;
}

void sub_02EFFB(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		mem_write8(x + 2u, 2u);
		mem_write8(x + 0x3Bu, 0u);
		return;
	}
}

void sub_02F00F(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_02FE4F_ADDRESS;
		t1 = mem_read8(x + 0x28u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			sub_02F018(x);
			break;
		case 2:
			sub_02F022(x);
			break;
		case -34:
			sub_02EF4D(x);
			break;
		case -32:
			sub_02EF67(x);
			break;
		case -30:
			sub_02EF6B(x);
			break;
		case -28:
			sub_02EF79(x);
			break;
		case -26:
			sub_02EF8D(x);
			break;
		case -24:
			sub_02EFA5(x);
			break;
		case -22:
			sub_02EFC6(x);
			break;
		case -20:
			sub_02EFD5(x);
			break;
		case -18:
			y = sub_02EFE1(x, y);
			break;
		case -16:
			y = sub_02EFF2(x);
			break;
		case -14:
			sub_02EFFB(x);
			break;
		case -12:
		case -10:
			continue;
		case -8:
			sub_02F02C(x, &y, &u);
			break;
		case -6:
		case -4:
			sub_02F055(x);
			break;
		case -2:
			sub_02F068(x);
			break;
		}
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_02F018(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write16(x + 4u, 0x480u);
	t1 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t1 + 1u);
}

void sub_02F022(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
		mem_write8(x, 0u);
}

void sub_02F02C(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint32_t carry = 0;
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0;

	u = object_setup_02FE53_ADDRESS;
	y = sub_0785AB(x, u);
	t1 = mem_read8(x + 0x30u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
		mem_write16(x + 4u, 0xC091u);
	mem_write16(x + 0x14u, rom_07FFC0_ADDRESS);
	mem_write16(x + 0x19u, 0x400u);
	mem_write8(x + 2u, 2u);
	mem_write8(x, 0x88u);
	*p_y = y;
	*p_u = u;
}

void sub_02F055(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;
	uint8_t t1 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry)
	{
		mem_write8(x + 4u, 4u);
		mem_write8(x + 5u, 0x80u);
		t1 = mem_read8(x + 2u);
		mem_write8(x + 2u, t1 + 1u);
	}
}

void sub_02F068(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
		mem_write8(x, 0u);
}

uint16_t sub_02F08C(uint16_t x)
{
	uint8_t a = 0;
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	u = object_setup_02FE65_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x + 0x43u, 1u);
	t1 = mem_read8(x + 0x44u);
	mem_write8(x + 0x44u, t1 + 1u);
	mem_write16(x + 0x2Au, enemy_behaviour_02FD3E_ADDRESS);
	mem_write8(x + 0x3Au, 0x10u);
	u = loaded_table_02FE6B_ADDRESS;
	t2 = mem_read8(x + 0x30u);
	a = t2;
	if ((int8_t)t2 >= 0)
	{
		mem_write8(x + 0x30u, 0u);
		mem_write8(x + 2u, 2u);
		return y;
	}
	u += (int8_t)((uint32_t)a << 1);
	mem_write8(x + 5u, DATA8(u));
	t3 = mem_read8(x + 9u);
	t4 = mem_read8(u + 1u);
	mem_write8(x + 9u, (t3 & 0xCFu) | t4);
	mem_write8(x + 0x30u, 0u);
	mem_write8(x + 0x57u, 0xFFu);
	mem_write8(x + 0x42u, 0xFFu);
	t5 = mem_read8(x + 2u);
	mem_write8(x + 2u, t5 + 1u);
	return y;
}

void sub_02F0D8(uint16_t x)
{
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0xCu);
	if (t1 < 0xE0u)
	{
		mem_write8(x + 0x42u, 0u);
		mem_write8(x + 0x57u, 0u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_02F0F0(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 5u, 0x90u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

uint16_t sub_02F0F9(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t y = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
	{
		t2 = mem_read8(x + 6u);
		if ((t2 & 2u) == 0u)
		{
			y = hit_box_02FCBE_ADDRESS;
			sub_0785B4(x, y);
			return y;
		}
		y = hit_box_02FCC6_ADDRESS;
		sub_0785B4(x, y);
		return y;
	}
	y = hit_box_02FCBE_ADDRESS;
	sub_0785B4(x, y);
	mem_write8(x + 2u, 2u);
	mem_write8(x + 0x3Bu, 0u);
	return y;
}

void sub_02F111(uint16_t x)
{
	uint8_t t2 = 0, t4 = 0;
	uint16_t t1 = 0, t3 = 0;

	mem_write8(x + 5u, 0x90u);
	mem_write16(x + 0x19u, 0x600u);
	t1 = mem_read16(x + 0x2Cu);
	if (t1 >= 0x20u)
	{
		mem_write16(x + 0x19u, 0x400u);
		mem_write16(x + 0xFu, 0x180u);
		t2 = mem_read8(x + 0x36u);
		if ((int8_t)(t2 - 0x40u) >= 0)
		{
			t3 = mem_read16(x + 0xFu);
			mem_write16(x + 0xFu, 0u - t3);
		}
	}
	t4 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t4 + 1u);
}

uint16_t sub_02F13E(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t y = 0;
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = mem_read16(x + 0x19u);
	t2 = t1 - 0x20u;
	mem_write16(x + 0x19u, t2);
	carry = sub_078662(x);
	if (carry == 0u)
	{
		t3 = mem_read8(x + 6u);
		if ((t3 & 2u) == 0u)
		{
			y = hit_box_02FCBE_ADDRESS;
			sub_0785B4(x, y);
			return y;
		}
		y = hit_box_02FCC6_ADDRESS;
		sub_0785B4(x, y);
		return y;
	}
	y = hit_box_02FCBE_ADDRESS;
	sub_0785B4(x, y);
	mem_write8(x + 2u, 2u);
	mem_write8(x + 0x3Bu, 0u);
	return y;
}

uint16_t sub_02F16D(uint16_t x)
{
	uint16_t y = 0;
	uint8_t t1 = 0, t2 = 0;

	mem_write8(x + 5u, 0x90u);
	mem_write8(x + 0x3Bu, 0x20u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	t2 = mem_read8(x + 6u);
	if ((t2 & 2u) == 0u)
	{
		y = hit_box_02FCBE_ADDRESS;
		sub_0785B4(x, y);
		return y;
	}
	y = hit_box_02FCC6_ADDRESS;
	sub_0785B4(x, y);
	return y;
}

uint16_t sub_02F17C(uint16_t x)
{
	uint16_t y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t5 = 0;
	uint16_t t4 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
	{
		t2 = mem_read8(x + 6u);
		if ((t2 & 2u) == 0u)
		{
			y = hit_box_02FCBE_ADDRESS;
			sub_0785B4(x, y);
			return y;
		}
		y = hit_box_02FCC6_ADDRESS;
		sub_0785B4(x, y);
		return y;
	}
	mem_write8(x + 0x3Bu, 0x20u);
	mem_write16(x + 0xFu, 0x200u);
	t3 = mem_read8(x + 0x36u);
	if ((int8_t)(t3 - 0x40u) >= 0)
	{
		t4 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t4);
	}
	t5 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t5 + 1u);
	t2 = mem_read8(x + 6u);
	if ((t2 & 2u) == 0u)
	{
		y = hit_box_02FCBE_ADDRESS;
		sub_0785B4(x, y);
		return y;
	}
	y = hit_box_02FCC6_ADDRESS;
	sub_0785B4(x, y);
	return y;
}

uint16_t sub_02F19B(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t y = 0;
	uint8_t t1 = 0, t2 = 0, t4 = 0;
	uint16_t t3 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
	{
		t2 = mem_read8(x + 6u);
		if ((t2 & 2u) == 0u)
		{
			y = hit_box_02FCBE_ADDRESS;
			sub_0785B4(x, y);
			return y;
		}
		y = hit_box_02FCC6_ADDRESS;
		sub_0785B4(x, y);
		return y;
	}
	carry = (unk_4858 >> 0) & 1u;
	if (carry)
	{
		t3 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t3);
	}
	mem_write8(x + 0x3Bu, 0x28u);
	t4 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t4 + 1u);
	t2 = mem_read8(x + 6u);
	if ((t2 & 2u) == 0u)
	{
		y = hit_box_02FCBE_ADDRESS;
		sub_0785B4(x, y);
		return y;
	}
	y = hit_box_02FCC6_ADDRESS;
	sub_0785B4(x, y);
	return y;
}

uint16_t sub_02F1B3(uint16_t x, uint16_t y)
{
	uint16_t y_2 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return y;
	mem_write16(x + 0xFu, 0u);
	y_2 = hit_box_02FCBE_ADDRESS;
	sub_0785B4(x, y_2);
	mem_write8(x + 2u, 2u);
	mem_write8(x + 0x3Bu, 0u);
	return y_2;
}

uint16_t sub_02F1DE(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t u = 0;
	uint8_t t1 = 0, t2 = 0;

	mem_write8(x + 5u, 0x86u);
	carry = (unk_4858 >> 0) & 1u;
	if (carry)
	{
		t1 = mem_read8(x + 5u);
		mem_write8(x + 5u, (t1 + 1u) | 0x80u);
	}
	u = indexed_table_02FE87_ADDRESS;
	mem_write8(x + 0x3Bu, DATA8(indexed_table_02FE87_ADDRESS + (((unk_4861 >> 1) >> 1) >> 1)));
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	return u;
}

void sub_02F204(uint16_t x)
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

void sub_02F211(uint16_t x)
{
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	mem_write8(x + 5u, 0x90u);
	mem_write8(x + VIDEO_003C, 4u);
	mem_write16(x + 0x19u, 0x600u);
	mem_write16(x + 0xFu, 0xFF80u);
	t1 = mem_read8(x + 0x36u);
	if ((int8_t)(t1 - 0x40u) >= 0)
	{
		t2 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t2);
	}
	t3 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t3 + 1u);
}

void sub_02F235(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry == 0u)
	{
		t1 = mem_read16(x + 0xCu);
		if (t1 < 0x40 || t1 > 0x17F)
			mem_write16(x + 0xFu, 0u);
		return;
	}
	t2 = mem_read8(x + VIDEO_003C);
	mem_write8(x + VIDEO_003C, t2 - 1u);
	if (t2 == 1u)
	{
		mem_write8(x + 2u, 2u);
		mem_write8(x + 0x3Bu, 0u);
		return;
	}
	mem_write16(x + 0x19u, 0x400u);
	t1 = mem_read16(x + 0xCu);
	if (t1 < 0x40 || t1 > 0x17F)
		mem_write16(x + 0xFu, 0u);
}

void sub_02F257(uint16_t d)
{
	uint8_t a = 0, b = 0;
	uint8_t t1 = 0;
	uint32_t unk_48EC_halfword = 0, unk_48EA_halfword = 0, unk_48E8_halfword = 0;

	a = (uint8_t)(d >> 8);
	b = (uint8_t)d;
	unk_48EC_halfword = ((uint32_t)a << 8) | b;
	unk_48EC = (uint8_t)(unk_48EC_halfword >> 8u);
	unk_48ED = (uint8_t)unk_48EC_halfword;
	a &= 0x3Fu;
	unk_48EF = a;
	unk_48E9 = (uint16_t)((uint32_t)DATA8(indexed_table_02FE8F_ADDRESS + a) * b) >> 8;
	unk_48EB = (uint16_t)((uint32_t)DATA8(indexed_table_02FE8F_ADDRESS + (int8_t)(0x3Fu - unk_48EF)) * unk_48ED) >> 8;
	unk_48E8 = 0u;
	unk_48EA = 0u;
	if ((unk_48EC & 0x40u) != 0u)
	{
		b = unk_48EB;
		unk_48EB = unk_48E9;
		unk_48E9 = b;
	}
	if ((int8_t)unk_48EC < 0)
	{
		unk_48EA_halfword = 0u - (((uint32_t)unk_48EA << 8u) | unk_48EB);
		unk_48EA = (uint8_t)(unk_48EA_halfword >> 8u);
		unk_48EB = (uint8_t)unk_48EA_halfword;
	}
	t1 = unk_48EC & 0xC0u;
	a = t1;
	if (t1 != 0u && a != 0xC0u)
	{
		unk_48E8_halfword = 0u - (((uint32_t)unk_48E8 << 8u) | unk_48E9);
		unk_48E8 = (uint8_t)(unk_48E8_halfword >> 8u);
		unk_48E9 = (uint8_t)unk_48E8_halfword;
	}
}

void sub_02F2B3(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0;

	u = object_setup_02FF23_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x + 9u, 0xADu);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_02F2C2(uint16_t x)
{
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = unk_48AC;
	if (t1 >= 0x420u)
	{
		mem_write8(x + 0x3Bu, 0x20u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_02F2D3(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	d = 0x7400u;
	carry = sub_078680(d);
	mem_write8(x + 5u, 0x81u);
	mem_write8(x + 0x3Bu, 0x40u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
}

void sub_02F2EC(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	d = 0x7300u;
	carry = sub_078680(d);
	mem_write16(x + 0x14u, 0xFF00u);
	mem_write8(x + 0x3Bu, 0x20u);
	mem_write8(x + 5u, 0x80u);
	mem_write8(x + 9u, 0x9Du);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
}

void sub_02F310(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(x + 0xFu, 0x200u);
		mem_write16(x + 0x14u, 0u);
		mem_write16(x + 0x16u, 0u);
		mem_write8(x + 5u, 0x8Du);
		mem_write8(x + 0x5Bu, 1u);
		mem_write8(x, 0xC8u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_02F334(void)
{
}

void sub_02F33E(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0;

	u = object_setup_02FF35_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x + 9u, 0x10u);
	mem_write8(x + 0x44u, 0x10u);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_02F350(uint16_t x, uint16_t u)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0;
	uint16_t t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x44u);
	if (t1 != 0u)
	{
		t2 = mem_read16(x + 0xCu);
		if (t2 < 0x130u)
		{
			t3 = mem_read16(x + 0x11u);
			if (t3 < 0x120u)
			{
				mem_write8(x + 0x44u, 0u);
				d = 0x6800u;
				carry = sub_078680(d);
			}
		}
	}
	if ((mem_read8(x) & 0x20u) != 0u)
	{
		mem_write8(x + 5u, 0x85u);
		mem_write8(x + 0x44u, 0u);
		t4 = mem_read8(x + 2u);
		mem_write8(x + 2u, t4 + 1u);
		return u;
	}
	t5 = mem_read8(x + 0x44u);
	if (t5 == 0u)
	{
		t6 = mem_read8(x + 0x3Bu);
		mem_write8(x + 0x3Bu, t6 - 1u);
		t7 = mem_read8(x + 0x3Bu);
		if ((t7 & 0x7Fu) == 0u)
		{
			u = indexed_table_02FF3B_ADDRESS;
			t8 = mem_read8(x + 0x3Du);
			mem_write8(x + 0x3Du, t8 + 1u);
			t9 = mem_read8(x + 0x3Du);
			mem_write8(x + 5u, DATA8(indexed_table_02FF3B_ADDRESS + (t9 & 1u)));
		}
	}
	return u;
}

uint16_t sub_02F3A1(uint16_t x)
{
	uint16_t y = 0;
	uint8_t t1 = 0;

	y = hit_box_02FEDF_ADDRESS;
	sub_0785B4(x, y);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	return y;
}

uint16_t sub_02F3AB(uint16_t x)
{
	uint16_t y = 0;
	uint8_t t1 = 0;

	y = hit_box_02FED7_ADDRESS;
	sub_0785B4(x, y);
	mem_write8(x + 0x3Bu, 0x80u);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	return y;
}

void sub_02F3BA(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	d = 0x6800u;
	carry = sub_078680(d);
	mem_write8(x + 5u, 0x81u);
	mem_write8(x + 0x3Bu, 0x60u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
}

void sub_02F3D3(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 2u, 1u);
		mem_write8(x + 0x3Bu, 1u);
		mem_write8(x + 0x3Du, 1u);
	}
}

void sub_02F3ED(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint32_t carry = 0;
	uint16_t d = 0, u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0;

	u = object_setup_02FF49_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t1 & 0xCFu) | 0x10u);
	mem_write16(x + 0x19u, 0x40u);
	mem_write8(x + 0x3Bu, 0x20u);
	mem_write8(x + 0x3Fu, 1u);
	mem_write8(x + 0x3Du, 0x40u);
	mem_write8(x + VIDEO_003C, 4u);
	d = 0x7200u;
	carry = sub_078680(d);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_02F425(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
	{
		sub_02F43A(x);
		return;
	}
	mem_write16(x + 0x19u, 0u);
	mem_write8(x + 5u, 0x9Eu);
	mem_write8(x + 0x3Bu, 0x20u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	sub_02F43A(x);
}

void sub_02F43A(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;

	t1 = mem_read8(x + 0x3Bu);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
		return;
	t2 = mem_read8(x + 0x3Fu);
	mem_write8(x + 0x3Fu, t2 + 1u);
	t3 = mem_read8(x + 0x3Du);
	mem_write8(x + 0x3Du, t3 - 1u);
	t4 = mem_read8(x + 0x3Eu);
	t5 = mem_read8(x + 0x3Fu);
	a = t4 + t5;
	mem_write8(x + 0x3Eu, a);
	t6 = mem_read8(x + 0x3Du);
	d = ((uint32_t)a << 8) | t6;
	sub_078617(x, d);
}

void sub_02F456(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
	{
		sub_02F43A(x);
		return;
	}
	mem_write8(x + 0x3Bu, 1u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	mem_write8(x, 0xC0u);
}

uint16_t sub_02F469(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, u = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t9 = 0, t10 = 0, t11 = 0;
	uint16_t t1 = 0, t6 = 0, t7 = 0, t8 = 0;

	t1 = mem_read16(x + 0x38u);
	u = t1;
	t2 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t2 - 1u);
	if (t2 != 1u)
	{
		t3 = mem_read8(u + 2u);
		if ((int8_t)t3 < 0)
		{
			t4 = mem_read8(x + 0x3Eu);
			a = t4 + 0x10u;
			mem_write8(x + 0x3Eu, a);
			d = ((uint32_t)a << 8) | 0x40u;
			sub_078617(x, d);
			sub_02F4D6();
			return u;
		}
		t5 = mem_read8(x + 0x3Bu);
		if ((t5 & 0xFu) == 0u)
		{
			t6 = mem_read16(u + 0x16u);
			t7 = t6 + 0x30u;
			t8 = mem_read16(x + 0x16u);
			if (t8 <= t7)
			{
				a = 0u;
				b = 0x40u;
			}
			else
			{
				a = 0xFFu;
				b = 0xC0u;
			}
			mem_write16(x + 0x19u, ((uint32_t)a << 8) | b);
		}
		t9 = mem_read8(x + 0x3Bu);
		if (t9 >= 0xFu)
		{
			d = sub_07861D(x, u);
			a = (uint8_t)(d >> 8);
			mem_write8(x + 0x3Eu, a);
			d = ((uint32_t)a << 8) | 0x40u;
			sub_078617(x, d);
			return u;
		}
		t4 = mem_read8(x + 0x3Eu);
		a = t4 + 0x10u;
		mem_write8(x + 0x3Eu, a);
		d = ((uint32_t)a << 8) | 0x40u;
		sub_078617(x, d);
		sub_02F4D6();
		return u;
	}
	d = 0x7200u;
	carry = sub_078680(d);
	mem_write8(x + 0x3Bu, 0x40u);
	u = sub_078620(x);
	t10 = mem_read8(x + VIDEO_003C);
	mem_write8(x + VIDEO_003C, t10 - 1u);
	if (t10 != 1u)
	{
		d = sub_07861D(x, u);
		a = (uint8_t)(d >> 8);
		mem_write8(x + 0x3Eu, a);
		d = ((uint32_t)a << 8) | 0x40u;
		sub_078617(x, d);
		return u;
	}
	mem_write8(x, 0x80u);
	mem_write16(x + 0x19u, 0u);
	mem_write8(x + 0x3Bu, 0x20u);
	t11 = mem_read8(x + 2u);
	mem_write8(x + 2u, t11 + 1u);
	return u;
}

void sub_02F4D6(void)
{
}

void sub_02F4D7(uint16_t x)
{
	uint8_t a = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(x + 0xFu, 0xFC00u);
		mem_write16(x + 0x14u, 0u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
		return;
	}
	t3 = mem_read8(x + 0x3Eu);
	a = t3 + 0x10u;
	mem_write8(x + 0x3Eu, a);
	d = ((uint32_t)a << 8) | 0x40u;
	sub_078617(x, d);
	sub_02F4D6();
}

void sub_02F507(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint8_t a = 0;
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t7 = 0, t8 = 0, t9 = 0;
	uint16_t t4 = 0, t5 = 0, t6 = 0;

	u = object_setup_02FF65_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x + 0x5Bu, 2u);
	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t1 & 0xCFu) | 0x10u);
	t2 = mem_read8(x + 0x30u);
	a = t2;
	if ((int8_t)t2 >= 0)
	{
		mem_write8(x, 0x88u);
		t3 = mem_read8(x + 0x30u);
		u = loaded_table_02FF6B_ADDRESS + (int8_t)((((uint32_t)t3 << 1) << 1) << 1);
		t4 = DATA16(u);
		mem_write16(x + 0x19u, t4);
		t5 = mem_read16(u + 2u);
		mem_write16(x + 0xFu, t5);
		t6 = mem_read16(u + 4u);
		mem_write16(x + 0xCu, t6);
		t7 = mem_read8(u + 6u);
		mem_write8(x + 0x3Bu, t7);
		sub_02F57E(x);
		t8 = mem_read8(x + 2u);
		mem_write8(x + 2u, t8 + 1u);
		sub_0785C6(x);
	}
	else
	{
		t9 = a & 0x7Fu;
		a = t9;
		if (t9 == 0u)
		{
			mem_write8(x + 5u, 0x83u);
			mem_write8(x + 2u, 3u);
		}
		else
		{
			mem_write8(x + 0x30u, a - 1u);
			mem_write8(x, 4u);
			mem_write8(x + 5u, 0x82u);
			mem_write8(x + 2u, 8u);
		}
	}
	*p_y = y;
	*p_u = u;
}

void sub_02F573(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
	{
		sub_02F57E(x);
		return;
	}
	mem_write16(x + 0xFu, 0u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	sub_02F57E(x);
}

void sub_02F57E(uint16_t x)
{
	uint32_t negative = 0;
	uint8_t a = 0;
	uint16_t d = 0;

	d = 0u;
	sub_078638(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	if (negative == 0u)
		mem_write8(x + 0x5Du, (((a & 0xFu) << 1) << 1) << 1);
}

void sub_02F58D(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = mem_read16(x + 0x19u);
	t2 = t1 - 0x20u;
	mem_write16(x + 0x19u, t2);
	carry = sub_078662(x);
	if (carry)
	{
		mem_write8(x + 5u, 0x81u);
		mem_write8(x, 0xC0u);
		mem_write8(x + 0x3Bu, 0x80u);
		mem_write8(x + 2u, 4u);
	}
}

void sub_02F5B0(uint16_t x)
{
	uint8_t t2 = 0, t3 = 0;
	uint16_t t1 = 0;

	if ((mem_read8(x) & 0x20u) == 0u)
	{
		t1 = mem_read16(x + 0xCu);
		if (t1 >= 0xE0u)
		{
			if ((unk_4815 & 0x3Fu) == 0u)
			{
				t2 = mem_read8(x + 5u);
				mem_write8(x + 5u, (t2 ^ 2u) | 0x80u);
				t3 = mem_read8(x + 9u);
				mem_write8(x + 9u, t3 ^ 0x40u);
			}
			return;
		}
	}
	mem_write16(x + 0x5Cu, 0u);
	mem_write8(x, 0x88u);
	mem_write8(x + 5u, 0x82u);
	mem_write16(x + 0x19u, 0x200u);
	mem_write8(x + 0x3Bu, 0x10u);
	mem_write8(x + 2u, 5u);
}

void sub_02F5F7(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	if ((mem_read8(x) & 0x20u) == 0u)
	{
		t1 = mem_read8(x + 0x3Bu);
		mem_write8(x + 0x3Bu, t1 - 1u);
		if (t1 == 1u)
		{
			mem_write8(x, 0x88u);
			mem_write8(x + 5u, 0x82u);
			mem_write16(x + 0x19u, 0x200u);
			mem_write8(x + 0x3Bu, 0x10u);
			t2 = mem_read8(x + 2u);
			mem_write8(x + 2u, t2 + 1u);
		}
		return;
	}
	mem_write8(x, 0x88u);
	mem_write8(x + 5u, 0x82u);
	mem_write16(x + 0x19u, 0x200u);
	mem_write8(x + 0x3Bu, 0x10u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
}

void sub_02F61C(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(x + 0x19u, 0u);
		mem_write8(x + 0x3Bu, 0x20u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_02F62D(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write16(x + 0xFu, 0x100u);
	mem_write16(x + 0x19u, 0x80u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	sub_0785C6(x);
}

void sub_02F645(uint16_t x)
{
	uint16_t d = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0xFu);
	d = t1 + 8u;
	if (d >= 0x200u)
	{
		sub_02F57E(x);
		return;
	}
	mem_write16(x + 0xFu, d);
	sub_02F57E(x);
}

uint16_t sub_02F657(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t3 = 0, t8 = 0, t9 = 0;
	uint16_t t1 = 0, t2 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0;

	t1 = mem_read16(x + 0x40u);
	u = t1;
	t2 = mem_read16(u + 0xCu);
	if (t2 >= 0x160u)
		return u;
	mem_write8(x, 0x88u);
	t3 = mem_read8(x + 0x30u);
	u = loaded_table_02FF8B_ADDRESS + (int8_t)((((uint32_t)t3 << 1) << 1) << 1);
	t4 = DATA16(u);
	mem_write16(x + 0xFu, t4);
	t5 = mem_read16(u + 2u);
	mem_write16(x + 0x14u, t5);
	t6 = mem_read16(u + 4u);
	mem_write16(x + 0x19u, t6);
	t7 = mem_read16(u + 6u);
	mem_write16(x + 0x3Eu, t7);
	t8 = mem_read8(x + 0x30u);
	if (t8 == 2u)
	{
		mem_write8(x + 5u, 0x84u);
		mem_write16(x + 0xAu, 0x1010u);
	}
	mem_write8(x + 0x3Bu, 0x40u);
	t9 = mem_read8(x + 2u);
	mem_write8(x + 2u, t9 + 1u);
	sub_0785C6(x);
	return u;
}

uint16_t sub_02F6A7(uint16_t x, uint16_t u)
{
	uint8_t a = 0;
	uint16_t u_2 = 0;
	uint8_t t1 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;
	uint16_t t2 = 0, t7 = 0, t8 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
		mem_write16(x + 0x19u, 0u);
		mem_write8(x, 0xC0u);
		t2 = mem_read16(x + 0x40u);
		u_2 = t2;
		mem_write8(u_2 + 2u, 0xFDu);
		t3 = mem_read8(x + 0x30u);
		if (t3 != 0u)
			mem_write8(x + 5u, 0x83u);
		else
			mem_write8(x + 5u, 0x81u);
		t4 = mem_read8(x + 2u);
		mem_write8(x + 2u, t4 + 1u);
		return u_2;
	}
	t5 = mem_read8(x + 0x30u);
	a = t5;
	if (a != 2u)
	{
		if (a == 8u)
			mem_write8(x + 5u, 0x82u);
		return u;
	}
	mem_write8(x, 0x98u);
	t6 = mem_read8(x + 0x3Bu);
	a = t6;
	if (a >= 0x30u)
	{
		t7 = mem_read16(x + 0xAu);
		t8 = t7 + 0x303u;
		mem_write16(x + 0xAu, t8);
		return u;
	}
	if (a == 8u)
		mem_write8(x + 5u, 0x82u);
	return u;
}

uint16_t sub_02F6FE(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;
	uint16_t t4 = 0, t5 = 0, t6 = 0;

	t1 = mem_read8(x + 0x30u);
	if (((unk_4858 + t1) & 0x3Fu) == 0u)
	{
		t2 = mem_read8(x + 5u);
		mem_write8(x + 5u, (t2 ^ 2u) | 0x80u);
		t3 = mem_read8(x + 9u);
		mem_write8(x + 9u, t3 ^ 0x40u);
	}
	t4 = mem_read16(x + 0x40u);
	u = t4;
	if ((mem_read8(u) & 0x40u) == 0u)
	{
		mem_write8(x, 0x88u);
		mem_write8(x + 5u, 0x82u);
		mem_write16(x + 0x19u, 0x200u);
		mem_write8(x + 0x3Bu, 1u);
		mem_write8(x + 2u, 6u);
		return u;
	}
	if ((mem_read8(x) & 0x20u) == 0u)
	{
		t5 = mem_read16(u + 0xCu);
		t6 = mem_read16(x + 0x3Eu);
		if (t6 <= t5)
			return u;
	}
	mem_write8(u + 2u, 0xFDu);
	mem_write8(x, 0x88u);
	mem_write8(x + 5u, 0x82u);
	mem_write16(x + 0x19u, 0x200u);
	mem_write8(x + 0x3Bu, 1u);
	mem_write8(x + 2u, 6u);
	return u;
}

void sub_02F75C(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t4 = 0;
	uint16_t t2 = 0, t3 = 0;

	u = object_setup_02FFA7_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 0x30u);
	u = loaded_table_02FFAD_ADDRESS + (int8_t)(((uint32_t)t1 << 1) << 1);
	t2 = DATA16(u);
	mem_write8(x + 4u, t2 >> 8);
	mem_write8(x + 9u, t2);
	t3 = mem_read16(u + 2u);
	mem_write16(x + 0x2Au, t3);
	mem_write8(x + 0x3Bu, 1u);
	t4 = mem_read8(x + 2u);
	mem_write8(x + 2u, t4 + 1u);
	u = sub_02F787(x, u);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_02F787(uint16_t x, uint16_t u)
{
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		t2 = mem_read16(x + 0x2Au);
		u = t2;
		t3 = mem_read8(x + 0xDu);
		mem_write8(x + 5u, mem_read8(u + ((unk_4858 + t3) & 3u)) | 0x80u);
	}
	return u;
}

void sub_02F7AB(uint16_t x)
{
	mem_write8(x + 5u, 0x81u);
	mem_write8(x + 2u, 0xFEu);
	sub_02F7B5();
}

void sub_02F7B5(void)
{
}

void sub_02F7B6(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0;

	u = object_setup_02FFD5_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x + 0x3Bu, 1u);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_02F7C5(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t1 = 0, t6 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 0x3Bu, 0x10u);
		sub_078620(x);
	}
	t2 = mem_read16(x + 0x38u);
	u = t2;
	sub_078626(x, u);
	t3 = mem_read16(x + 0x2Eu);
	t4 = mem_read16(x + 0x2Cu);
	t5 = t3 + t4;
	if (t5 < 0x40u)
	{
		mem_write8(x, 0xC0u);
		mem_write8(x + 5u, 0xAFu);
		t6 = mem_read8(x + 2u);
		mem_write8(x + 2u, t6 + 1u);
	}
	return u;
}

uint16_t sub_02F7F1(uint16_t x, uint16_t u)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0;
	uint16_t t3 = 0;

	if ((mem_read8(x) & 0x20u) == 0u)
	{
		t1 = mem_read8(x + 6u);
		carry = (t1 >> 0) & 1u;
		if (carry)
		{
			mem_write8(x + 5u, 0xAFu);
			t2 = mem_read8(x + 2u);
			mem_write8(x + 2u, t2 + 1u);
		}
		return u;
	}
	t3 = mem_read16(x + 0x25u);
	u = t3;
	if (u >= unk_4F80_ADDRESS)
	{
		t1 = mem_read8(x + 6u);
		carry = (t1 >> 0) & 1u;
		if (carry)
		{
			mem_write8(x + 5u, 0xAFu);
			t2 = mem_read8(x + 2u);
			mem_write8(x + 2u, t2 + 1u);
		}
		return u;
	}
	mem_write16(x + 0x38u, u);
	mem_write8(x + 5u, 0xB8u);
	mem_write8(u + VIDEO_0031, 0x10u);
	mem_write8(u + 0x3Du, 6u);
	mem_write8(x + 2u, 5u);
	return u;
}

uint16_t sub_02F826(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t2 = 0, t3 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x38u);
	u = t1;
	t2 = mem_read8(u + 0x1Bu);
	if (t2 != 0u)
	{
		t3 = mem_read8(u + 0x3Du);
		if (t3 == 0u)
		{
			mem_write8(x + 5u, 0xAFu);
			mem_write8(x + 2u, 3u);
		}
		return u;
	}
	mem_write8(x + 5u, 0xAFu);
	mem_write8(x + 2u, 3u);
	return u;
}

void sub_02F83E(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		mem_write8(x + 5u, 0x80u);
		mem_write8(x + 0x3Bu, 0x40u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_02F852(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
		mem_write8(x + 2u, 1u);
}
