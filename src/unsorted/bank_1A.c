/**
 *    Name:        unsorted/bank_1A.c
 *    Description: bank 1A's code
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    06-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

void sub_034006(void)
{
}

void sub_034009(void)
{
}

void sub_03400C(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_034FA7(x, &y, &u);
		break;
	case 2:
		u = sub_034FBB(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_03400F(uint16_t x, uint16_t y, uint8_t d)
{
	return sub_034077(x, y, d);
}

void sub_034012(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		y = sub_0350A8(x);
		break;
	case 2:
		y = sub_035184(x);
		break;
	case 4:
		y = sub_03524C(x);
		break;
	case 6:
		y = sub_03527C(x);
		break;
	case 8:
		y = sub_035285(x);
		break;
	case 10:
		sub_03506E(x);
		break;
	case 12:
		y = sub_035088(x, y);
		break;
	case 14:
		sub_03509F(x);
		break;
	case -4:
	case -2:
		y = sub_03505B(x, y);
		break;
	}
	u = sub_035038(x);
	*p_y = y;
	*p_u = u;
}

void sub_034015(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		y = sub_03530C(x);
		break;
	case 2:
		y = sub_035352(x, y);
		break;
	case 4:
		y = sub_0353A2(x, y);
		break;
	case 6:
		y = sub_0353DD(x, y);
		break;
	case 8:
		y = sub_035401(x, y);
		break;
	case 10:
		y = sub_03542F(x, y);
		break;
	case -4:
	case -2:
		y = sub_03505B(x, y);
		break;
	}
	u = sub_035038(x);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_034018(uint16_t x, uint16_t y, uint8_t d)
{
	uint8_t b = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		return sub_034FE8(x);
	case 2:
		return sub_034FF7(x, y);
	case 4:
		sub_035010(x);
		return y;
	}
	unreachable();
}

uint16_t sub_03401B(uint16_t x, uint32_t y, uint8_t d)
{
	uint8_t b = 0;
	uint16_t ignored16 = 0, u = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	b = (uint8_t)d;
	u = loaded_table_035914_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_034E3A(x, &ignored16, &u);
		break;
	case 2:
		sub_034E8B(x, &ignored16, &u);
		break;
	case 4:
		sub_034ED8(x, &ignored16, &u);
		break;
	case 6:
		sub_034F24(x, &ignored16, &u);
		break;
	case 8:
	case 14:
		sub_034F6B(x);
		break;
	case 10:
	case 16:
		sub_034F73(x);
		break;
	case 12:
		sub_034E1C(x);
		break;
	}
	if ((mem_read8(x) & 0x20u) != 0u)
		mem_write8(x + 2u, 6u);
	t1 = mem_read16(x + 0x14u);
	t2 = t1;
	t3 = t2 >> 15 ? 0u - t2 : t2;
	mem_write8(x + 0xAu, (t3 >> 3) + 0x40u);
	mem_write8(x, mem_read8(x) | 0x10u);
	sub_0785C6(x);
	return u;
}

void sub_03401E(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_035944_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_034F83(x, &y, &u);
		break;
	case 2:
		sub_034F97(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void unreached_034023(void)
{
	uint16_t d = 0, x = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0;

	x = DATA16(unused_spawn_0356DD_ADDRESS + 0x3u);
	d = (uint32_t)unk_4F9B << 8;
	unused_0785A8(x, d);
	t1 = io_read8(VIDEO_188C);
	x = DATA16(unused_spawn_0356DD_ADDRESS + 0x5u);
	d = (uint32_t)t1 << 8;
	unused_0785A8(x, d);
	t2 = unk_48AC;
	t3 = t2 + 0x150u;
	unk_48F0 = (uint8_t)(t3 >> 8u);
	unk_48F1 = (uint8_t)t3;
	x = AT16(unused_tile_places[7], -1);
	d = (uint32_t)unk_48F0 << 8;
	unused_0785A8(x, d);
	x = AT16(unused_tile_places[9], -1);
	d = (uint32_t)unk_48F1 << 8;
	unused_0785A8(x, d);
	t4 = unk_48B8;
	unk_48F0 = (uint8_t)(t4 >> 8u);
	unk_48F1 = (uint8_t)t4;
	x = AT16(unused_tile_places[11], -1);
	d = (uint32_t)unk_48F0 << 8;
	unused_0785A8(x, d);
	x = AT16(unused_tile_places[13], -1);
	d = (uint32_t)unk_48F1 << 8;
	unused_0785A8(x, d);
}

uint16_t sub_034077(uint16_t x, uint16_t y, uint8_t d)
{
	switch ((int8_t)(uint8_t)((uint32_t)d << 1))
	{
	case 0:
		y = sub_0340BE(x);
		break;
	case 2:
		y = sub_034103(x, y);
		break;
	case 4:
	case 36:
		y = sub_034242(x, y);
		break;
	case 6:
		y = sub_034281(x, y);
		break;
	case 8:
		y = sub_034327(x, y);
		break;
	case 10:
		y = sub_034495(x, y);
		break;
	case 12:
		y = sub_034408(x, y);
		break;
	case 14:
		y = sub_0345C9(x, y);
		break;
	case 16:
		y = sub_03463D(x, y);
		break;
	case 18:
		y = sub_034719(x, y);
		break;
	case 20:
		y = sub_03479C(x, y);
		break;
	case 22:
		y = sub_034858(x, y);
		break;
	case 24:
		y = sub_03492B(x, y);
		break;
	case 26:
		y = sub_03498F(x, y);
		break;
	case 28:
		y = sub_034A6C(x, y);
		break;
	case 30:
		y = sub_034AFA(x, y);
		break;
	case 32:
		sub_034BF8(x);
		break;
	case 34:
		y = sub_034C46(x, y);
		break;
	case 38:
		y = sub_034C83(x, y);
		break;
	case -4:
		y = sub_034083(x);
		break;
	case -2:
		y = sub_034095(x);
		break;
	}
	sub_078593(x, 0u);
	sub_03438C(x);
	return y;
}

uint16_t sub_034083(uint16_t x)
{
	uint16_t y = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x48u);
	y = t1;
	sub_0785B4(x, y);
	t2 = mem_read8(x + VIDEO_0031);
	mem_write8(x + 2u, DATA8(object_1a_next_states_ADDRESS + (int8_t)t2));
	return y;
}

uint16_t sub_034095(uint16_t x)
{
	uint8_t a = 0;
	uint16_t y = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0, t5 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x48u);
	y = t1;
	sub_0785B4(x, y);
	t2 = mem_read8(x + VIDEO_0031);
	a = mem_read8(DATA16(object_1a_level_rows_ADDRESS + (int8_t)((uint32_t)t2 << 1)) + (int8_t)unk_4857);
	io_write8(VIDEO_188C, a);
	t3 = mem_read8(x + 0x1Bu);
	if (t3 <= a)
	{
		t4 = mem_read8(x + VIDEO_0031);
		mem_write8(x + 2u, DATA8(object_1a_next_states_ADDRESS + (int8_t)t4));
		return y;
	}
	t5 = mem_read8(x + VIDEO_0031);
	mem_write8(x + 2u, DATA8(object_1a_states_after_ADDRESS + (int8_t)t5));
	return y;
}

uint16_t sub_0340BE(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0, u = 0, y = 0;

	u = object_setup_0357D0_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 4u);
	mem_write8(x + 0x50u, 4u);
	mem_write8(x + 0x51u, 4u);
	mem_write8(x + 0x5Bu, 1u);
	mem_write16(x + 0x5Cu, 0u);
	mem_write8(x + 9u, 0x10u);
	mem_write8(x + 0x1Bu, 0xFFu);
	d = 0x6700u;
	carry = sub_078680(d);
	mem_write8(x + VIDEO_0031, 0u);
	mem_write8(x + 0x42u, 0xFFu);
	mem_write8(x + 0x57u, 0xFFu);
	mem_write8(x + 2u, 1u);
	mem_write8(x + 0x45u, 1u);
	mem_write8(x + 0x52u, 0u);
	mem_write8(x + 0x4Eu, 0u);
	return y;
}

uint16_t sub_034103(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x52u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_03410C(x);
		return y;
	case 2:
		return sub_034148(x, y);
	case 4:
		return sub_034170(x, y);
	case 6:
		sub_03418C(x);
		return y;
	case 8:
		sub_0341A2(x);
		return y;
	case 10:
		sub_0341D0(x);
		return y;
	case 12:
		sub_0341E7(x);
		return y;
	case 14:
		sub_0341FD(x);
		return y;
	case 16:
		sub_034252(x);
		return y;
	case 18:
		return sub_034268(x, y);
	case 20:
		sub_03428A(x);
		return y;
	case 22:
		sub_03429E(x);
		return y;
	case 24:
		sub_0342D7(x);
		return y;
	case 26:
		sub_0342E0(x);
		return y;
	case 28:
		sub_0342E7(x);
		return y;
	case 30:
		sub_034302(x);
		return y;
	}
	unreachable();
}

void sub_03410C(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	if (unk_4892 != 0u)
		return;
	mem_write8(x, 0x98u);
	mem_write8(x + 0x42u, 0u);
	mem_write8(x + 0x57u, 0u);
	mem_write16(x + 0xAu, 0x1010u);
	mem_write8(x + 5u, 0x80u);
	d = 0xFD00u;
	carry = sub_078680(d);
	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, t1 | 0x40u);
	mem_write16(x + 0xCu, 0x120u);
	mem_write16(x + 0x16u, 0x160u);
	unk_48A7--;
	t2 = mem_read8(x + 0x52u);
	mem_write8(x + 0x52u, t2 + 1u);
}

uint16_t sub_034148(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	mem_write8(x, 0x98u);
	carry = sub_0343D1(x);
	if (carry == 0u)
	{
		unk_48A7--;
		return y;
	}
	mem_write8(x, 0xDCu);
	y = hit_box_035770_ADDRESS;
	sub_0785B4(x, y);
	mem_write16(x + 0x19u, 0x200u);
	d = 0x6400u;
	carry = sub_078680(d);
	t1 = mem_read8(x + 0x52u);
	mem_write8(x + 0x52u, t1 + 1u);
	unk_48A7--;
	return y;
}

uint16_t sub_034170(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;
	uint8_t t1 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry == 0u)
	{
		mem_write8(x, 0x98u);
		unk_48A7--;
		return y;
	}
	y = hit_box_035768_ADDRESS;
	sub_0785B4(x, y);
	mem_write8(x + 0x3Bu, 0x40u);
	t1 = mem_read8(x + 0x52u);
	mem_write8(x + 0x52u, t1 + 1u);
	mem_write8(x, 0x98u);
	unk_48A7--;
	return y;
}

void sub_03418C(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	mem_write8(x, 0x98u);
	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 0x3Bu, 0x80u);
		t2 = mem_read8(x + 0x52u);
		mem_write8(x + 0x52u, t2 + 1u);
	}
	unk_48A7--;
}

void sub_0341A2(uint16_t x)
{
	uint8_t a = 0, d = 0;
	uint8_t t3 = 0, t4 = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = mem_read16(x + 0xAu);
	t2 = t1 + 0x101u;
	d = (uint8_t)t2;
	a = (uint8_t)(t2 >> 8);
	if ((uint16_t)(((uint32_t)a << 8) | (d & 0xFFu)) < 0x4040u)
	{
		mem_write16(x + 0xAu, ((uint32_t)a << 8) | (d & 0xFFu));
		mem_write8(x, 0x98u);
	}
	t3 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t3 - 1u);
	if (t3 == 1u)
	{
		mem_write8(x, 0xC8u);
		mem_write8(x + 5u, 0x81u);
		unk_487C = 1u;
		t4 = mem_read8(x + 0x52u);
		mem_write8(x + 0x52u, t4 + 1u);
	}
	unk_48A7--;
}

void sub_0341D0(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		mem_write8(x + 5u, 0x82u);
		mem_write8(x + 0x3Bu, 0x40u);
		t2 = mem_read8(x + 0x52u);
		mem_write8(x + 0x52u, t2 + 1u);
	}
	unk_48A7--;
}

void sub_0341E7(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 5u, 0x83u);
		mem_write8(x + 0x3Bu, 0x80u);
		t2 = mem_read8(x + 0x52u);
		mem_write8(x + 0x52u, t2 + 1u);
	}
	unk_48A7--;
}

void sub_0341FD(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + VIDEO_0031, 1u);
		mem_write8(x + 0x1Bu, 0xFFu);
		mem_write8(x + 0x52u, 0u);
		mem_write8(x + 2u, 3u);
		mem_write8(x + 0x45u, 3u);
	}
}

void sub_034218(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, t1 | 0x80u);
	mem_write8(x + 6u, 0x80u);
}

void sub_034226(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, t1 & 0x7Fu);
	mem_write8(x + 6u, 0x80u);
}

void sub_034234(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, t1 ^ 0x80u);
	mem_write8(x + 6u, 0x80u);
}

uint16_t sub_034242(uint16_t x, uint16_t y)
{
	uint8_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_034252(x);
		break;
	case 2:
		y = sub_034268(x, y);
		break;
	case 4:
		sub_03428A(x);
		break;
	case 6:
		sub_03429E(x);
		break;
	case 8:
		sub_0342D7(x);
		break;
	case 10:
		sub_0342E0(x);
		break;
	case 12:
		sub_0342E7(x);
		break;
	case 14:
		sub_034302(x);
		break;
	case -16:
		sub_03410C(x);
		break;
	case -14:
		y = sub_034148(x, y);
		break;
	case -12:
		y = sub_034170(x, y);
		break;
	case -10:
		sub_03418C(x);
		break;
	case -8:
		sub_0341A2(x);
		break;
	case -6:
		sub_0341D0(x);
		break;
	case -4:
		sub_0341E7(x);
		break;
	case -2:
		sub_0341FD(x);
		break;
	}
	t2 = mem_read8(x + 0x45u);
	d = t2;
	return sub_034077(x, y, d);
}

void sub_034252(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	mem_write8(x, 0x88u);
	sub_034218(x);
	d = 0x6600u;
	carry = sub_078680(d);
	mem_write8(x + 0x53u, 8u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

uint16_t sub_034268(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x53u);
	mem_write8(x + 0x53u, t1 - 1u);
	if (t1 != 1u)
		return y;
	mem_write8(x, 0xC8u);
	y = hit_box_035768_ADDRESS;
	sub_0785B4(x, y);
	sub_034226(x);
	t2 = mem_read8(x + 0x45u);
	mem_write8(x + 2u, t2);
	return y;
}

uint16_t sub_034281(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x52u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_03428A(x);
		return y;
	case 2:
		sub_03429E(x);
		return y;
	case 4:
		sub_0342D7(x);
		return y;
	case 6:
		sub_0342E0(x);
		return y;
	case 8:
		sub_0342E7(x);
		return y;
	case 10:
		sub_034302(x);
		return y;
	case -20:
		sub_03410C(x);
		return y;
	case -18:
		return sub_034148(x, y);
	case -16:
		return sub_034170(x, y);
	case -14:
		sub_03418C(x);
		return y;
	case -12:
		sub_0341A2(x);
		return y;
	case -10:
		sub_0341D0(x);
		return y;
	case -8:
		sub_0341E7(x);
		return y;
	case -6:
		sub_0341FD(x);
		return y;
	case -4:
		sub_034252(x);
		return y;
	case -2:
		return sub_034268(x, y);
	}
	unreachable();
}

void sub_03428A(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x, 0xC8u);
	sub_034226(x);
	mem_write8(x + 5u, 0x86u);
	mem_write8(x + VIDEO_003C, 8u);
	t1 = mem_read8(x + 0x52u);
	mem_write8(x + 0x52u, t1 + 1u);
	sub_03429E(x);
}

void sub_03429E(uint16_t x)
{
	uint8_t a = 0;
	uint16_t d = 0, u = 0;
	uint8_t t6 = 0, t7 = 0, t8 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	u = sub_078620(x);
	t1 = mem_read16(u + 0x11u);
	t2 = mem_read16(x + 0x11u);
	t3 = t1 - t2;
	t4 = t3;
	t5 = t4 >> 15 ? 0u - t4 : t4;
	if (t5 < 4u)
	{
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
		t6 = mem_read8(x + VIDEO_003C);
		mem_write8(x + VIDEO_003C, t6 - 1u);
		if (t6 == 1u)
		{
			mem_write8(x + 0x52u, 4u);
			return;
		}
		t7 = mem_read8(x + VIDEO_003C);
		mem_write8(x + 0x3Bu, DATA8(indexed_table_0357FE_ADDRESS + (int8_t)t7));
		t8 = mem_read8(x + 0x52u);
		mem_write8(x + 0x52u, t8 + 1u);
		return;
	}
	d = sub_07861D(x, u);
	a = (uint8_t)(d >> 8);
	d = ((uint32_t)a << 8) | 0x30u;
	sub_078617(x, d);
	t6 = mem_read8(x + VIDEO_003C);
	mem_write8(x + VIDEO_003C, t6 - 1u);
	if (t6 == 1u)
	{
		mem_write8(x + 0x52u, 4u);
		return;
	}
	t7 = mem_read8(x + VIDEO_003C);
	mem_write8(x + 0x3Bu, DATA8(indexed_table_0357FE_ADDRESS + (int8_t)t7));
	t8 = mem_read8(x + 0x52u);
	mem_write8(x + 0x52u, t8 + 1u);
}

void sub_0342D7(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		t2 = mem_read8(x + 0x52u);
		mem_write8(x + 0x52u, t2 + 1u);
	}
}

void sub_0342E0(uint16_t x)
{
	mem_write8(x + 0x52u, 1u);
	sub_03430C(x);
}

void sub_0342E7(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		mem_write8(x + 5u, 0x82u);
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
		mem_write8(x + 0x3Bu, 0x40u);
		t2 = mem_read8(x + 0x52u);
		mem_write8(x + 0x52u, t2 + 1u);
	}
	sub_03430C(x);
}

void sub_034302(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
	{
		sub_03430C(x);
		return;
	}
	mem_write8(x + 0x52u, 0u);
	sub_03430C(x);
}

void sub_03430C(uint16_t x)
{
	uint16_t d = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read16(x + 0x38u);
	t2 = mem_read16(t1 + 0x11u);
	t3 = mem_read16(x + 0x11u);
	d = t2 - t3;
	if ((uint16_t)(d >> 15 ? 0u - d : d) < 4u)
	{
		mem_write8(x + 0x52u, 0u);
		mem_write8(x + 2u, 4u);
		mem_write8(x + 0x45u, 4u);
	}
}

uint16_t sub_034327(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x52u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_034330(x);
		return y;
	case 2:
		return sub_034349(x, y);
	case 4:
		return sub_034371(x, y);
	case 6:
		sub_034411(x);
		return y;
	case 8:
		return sub_034437(x, y);
	case 10:
		return sub_034463(x, y);
	}
	unreachable();
}

void sub_034330(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x, 0xC8u);
	mem_write8(x + 5u, 0x86u);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write8(x + 0x3Bu, 0x40u);
	t1 = mem_read8(x + 0x52u);
	mem_write8(x + 0x52u, t1 + 1u);
}

uint16_t sub_034349(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0, t6 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return y;
	mem_write16(x + 0xFu, 0x800u);
	t2 = mem_read16(x + 0x38u);
	t3 = mem_read16(t2 + 0xCu);
	t4 = mem_read16(x + 0xCu);
	if (t3 < t4)
	{
		t5 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t5);
	}
	y = hit_box_035770_ADDRESS;
	sub_0785B4(x, y);
	mem_write8(x + 0x3Bu, 0x30u);
	t6 = mem_read8(x + 0x52u);
	mem_write8(x + 0x52u, t6 + 1u);
	return y;
}

uint16_t sub_034371(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return y;
	y = hit_box_035768_ADDRESS;
	sub_0785B4(x, y);
	mem_write8(x + 2u, 3u);
	mem_write8(x + 0x45u, 3u);
	mem_write8(x + 0x52u, 0u);
	return y;
}

void sub_03438C(uint16_t x)
{
	uint32_t negative = 0;
	uint8_t a = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t5 = 0, t6 = 0, t9 = 0, t10 = 0;
	uint16_t t4 = 0, t7 = 0, t8 = 0, t11 = 0;

	sub_07863B(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	if ((int8_t)a >= 0)
	{
		mem_write16(x + 0x50u, 0u);
		return;
	}
	t1 = mem_read8(x + 0x51u);
	if (t1 == 0u)
	{
		sub_078647(x, &d, &negative);
		a = (uint8_t)(d >> 8);
		if ((int8_t)a < 0)
		{
			t2 = mem_read8(x + 0x37u);
			mem_write8(x + 0x37u, t2 ^ 0x80u);
			t3 = mem_read8(x + 0x51u);
			mem_write8(x + 0x51u, t3 + 1u);
			t4 = mem_read16(x + 0x14u);
			mem_write16(x + 0x14u, 0u - t4);
		}
	}
	t5 = mem_read8(x + 0x50u);
	if (t5 != 0u)
		return;
	sub_078644(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	if ((int8_t)a >= 0)
	{
		t6 = mem_read8(x + 0x51u);
		if (t6 == 0u)
		{
			t7 = mem_read16(x + 0xFu);
			mem_write16(x + 0xFu, 0u - t7);
			t8 = mem_read16(x + 0x14u);
			mem_write16(x + 0x14u, 0u - t8);
		}
		return;
	}
	t9 = mem_read8(x + 0x37u);
	mem_write8(x + 0x37u, t9 ^ 0x80u);
	t10 = mem_read8(x + 0x50u);
	mem_write8(x + 0x50u, t10 + 1u);
	t11 = mem_read16(x + 0xFu);
	mem_write16(x + 0xFu, 0u - t11);
}

uint32_t sub_0343D1(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;
	uint32_t unk_48E8_halfword = 0;

	t1 = mem_read16(x + 0x19u);
	d = t1 - VIDEO_00C0;
	mem_write16(x + 0x19u, d);
	if ((int16_t)d >= 0)
	{
		carry = 0u;
		return carry;
	}
	if (d >> 8 < 0xF0u)
		mem_write8(x + 0x19u, 0xF0u);
	t2 = mem_read16(x + 0x5Cu);
	unk_48E8_halfword = t2 + 0x10u;
	unk_48E8 = (uint8_t)(unk_48E8_halfword >> 8u);
	unk_48E9 = (uint8_t)unk_48E8_halfword;
	t3 = mem_read16(x + 0x16u);
	if ((((uint32_t)unk_48E8 << 8u) | unk_48E9) < t3)
	{
		carry = 0u;
		return carry;
	}
	mem_write16(x + 0x19u, 0u);
	t4 = mem_read16(x + 0x5Cu);
	mem_write16(x + 0x16u, t4);
	mem_write8(x + 6u, 0x80u);
	carry = 1u;
	return carry;
}

uint16_t sub_034408(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x4Eu);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_034411(x);
		return y;
	case 2:
		return sub_034437(x, y);
	case 4:
		return sub_034463(x, y);
	case -6:
		sub_034330(x);
		return y;
	case -4:
		return sub_034349(x, y);
	case -2:
		return sub_034371(x, y);
	}
	unreachable();
}

void sub_034411(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x, 0xC8u);
	mem_write8(x + 0x45u, 6u);
	mem_write8(x + VIDEO_0031, 0u);
	mem_write8(x + 5u, 0x81u);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write16(x + 0x19u, 0u);
	mem_write8(x + 0x3Bu, 0x80u);
	t1 = mem_read8(x + 0x4Eu);
	mem_write8(x + 0x4Eu, t1 + 1u);
}

uint16_t sub_034437(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0;
	uint8_t t1 = 0, t2 = 0;

	sub_034234(x);
	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return y;
	d = VIDEO_2000;
	carry = sub_078680(d);
	mem_write8(x + 4u, 0xBBu);
	mem_write8(x + 5u, 0x84u);
	y = child_object_035812_ADDRESS;
	sub_07862C(x, y, &ignored16, &ignored16_2, &carry);
	mem_write8(x, 0x80u);
	mem_write8(x + 0x3Bu, 0x40u);
	t2 = mem_read8(x + 0x4Eu);
	mem_write8(x + 0x4Eu, t2 + 1u);
	return y;
}

uint16_t sub_034463(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0;

	sub_034234(x);
	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return y;
	sub_034226(x);
	mem_write8(x + VIDEO_0031, 2u);
	mem_write8(x + 0x1Bu, 0xFFu);
	mem_write8(x, 0xC0u);
	y = hit_box_035768_ADDRESS;
	sub_0785B4(x, y);
	mem_write8(x + 2u, 7u);
	mem_write8(x + 0x45u, 7u);
	mem_write8(x + 0x52u, 0u);
	mem_write8(x + 0x4Eu, 0u);
	mem_write8(x + 0x43u, 0u);
	return y;
}

uint16_t sub_034495(uint16_t x, uint16_t y)
{
	uint8_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_0344E0(x);
		break;
	case 2:
		y = sub_034540(x, y);
		break;
	case 4:
		y = sub_034546(x, y);
		break;
	case 6:
		y = sub_03455F(x, y);
		break;
	case 8:
		sub_034597(x);
		break;
	case 10:
		sub_0345B0(x);
		break;
	case -4:
		sub_0344AB(x);
		break;
	case -2:
		sub_0344C4(x);
		break;
	}
	t2 = mem_read8(x + 0x43u);
	if (t2 == 0u)
		return y;
	t3 = mem_read8(x + 0x45u);
	d = t3;
	return sub_034077(x, y, d);
}

void sub_0344AB(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x53u);
	mem_write8(x + 0x53u, t1 - 1u);
	if (t1 != 1u)
		return;
	sub_034226(x);
	mem_write8(x, 0xC8u);
	mem_write8(x + 2u, 4u);
	mem_write8(x + 0x45u, 4u);
	mem_write8(x + 0x29u, 0u);
}

void sub_0344C4(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x53u);
	mem_write8(x + 0x53u, t1 - 1u);
	if (t1 != 1u)
		return;
	sub_034226(x);
	mem_write8(x, 0xC8u);
	mem_write8(x + 2u, 4u);
	mem_write8(x + 0x45u, 4u);
	mem_write8(x + 0x52u, 0u);
	mem_write8(x + 0x29u, 0u);
}

void sub_0344E0(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t7 = 0, t8 = 0;
	uint16_t t3 = 0, t4 = 0, t5 = 0, t6 = 0;

	mem_write8(x, 0x88u);
	sub_034218(x);
	d = 0x6600u;
	carry = sub_078680(d);
	t1 = mem_read8(x + 0x4Fu);
	mem_write8(x + 0x4Fu, t1 - 1u);
	t2 = mem_read8(x + 0x4Fu);
	if ((t2 & 7u) == 0u)
	{
		mem_write8(x + 0x43u, 0u);
		mem_write8(x + 5u, 0x85u);
		mem_write16(x + 0xFu, 0x100u);
		mem_write16(x + 0x19u, 0xD00u);
		t3 = mem_read16(x + 0x38u);
		t4 = mem_read16(t3 + 0xCu);
		t5 = mem_read16(x + 0xCu);
		if (t4 < t5)
		{
			t6 = mem_read16(x + 0xFu);
			mem_write16(x + 0xFu, 0u - t6);
		}
		mem_write8(x + 0x3Bu, 0x20u);
		t7 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t7 + 1u);
		return;
	}
	mem_write8(x + 0x43u, 1u);
	mem_write8(x + 0x53u, 8u);
	t8 = mem_read8(x + 0x45u);
	if (t8 != 4u)
	{
		mem_write8(x + 0x29u, 0xFFu);
		return;
	}
	mem_write8(x + 0x29u, 0xFEu);
}

uint16_t sub_034540(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0;

	sub_034226(x);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	return sub_034546(x, y);
}

uint16_t sub_034546(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, y_2 = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x19u);
	if ((int16_t)t1 < 0)
	{
		t2 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t2 + 1u);
		mem_write8(x, 0xCCu);
		y_2 = hit_box_035770_ADDRESS;
		sub_0785B4(x, y_2);
		return y_2;
	}
	sub_0785B1(x, &ignored16, &carry);
	if (carry)
		return sub_034564(x);
	return y;
}

uint16_t sub_03455F(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;

	carry = sub_0343D1(x);
	if (carry == 0u)
		return y;
	return sub_034564(x);
}

uint16_t sub_034564(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0, y = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Au);
	mem_write8(x + 0x3Au, t1 - 1u);
	t2 = mem_read8(x + 0x3Au);
	mem_write8(x + 5u, DATA8(indexed_table_03582A_ADDRESS + (t2 & 3u)));
	mem_write8(x, 0x88u);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write16(x + 0x19u, 0x400u);
	d = 0x6400u;
	carry = sub_078680(d);
	mem_write8(x + 0x29u, 4u);
	y = hit_box_035768_ADDRESS;
	sub_0785B4(x, y);
	return y;
}

void sub_034597(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	carry = sub_0343D1(x);
	if (carry == 0u)
		return;
	mem_write8(x, 0x88u);
	mem_write8(x + 0x3Bu, 0x20u);
	d = 0x6400u;
	carry = sub_078680(d);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

void sub_0345B0(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x, 0xC8u);
		mem_write8(x + 2u, 3u);
		mem_write8(x + 0x45u, 3u);
		mem_write8(x + 0x29u, 0u);
		mem_write8(x + 0x52u, 0u);
	}
}

uint16_t sub_0345C9(uint16_t x, uint16_t y)
{
	uint16_t u = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 0x52u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		y = sub_0345DB(x);
		break;
	case 2:
		y = sub_03461C(x, y);
		break;
	}
	t2 = mem_read16(x + 0x38u);
	u = t2;
	sub_078626(x, u);
	sub_03438C(x);
	return y;
}

uint16_t sub_0345DB(uint16_t x)
{
	uint8_t a = 0;
	uint16_t y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0;

	mem_write8(x, 0xC0u);
	y = hit_box_035768_ADDRESS;
	sub_0785B4(x, y);
	sub_034226(x);
	mem_write8(x + 0x43u, 0u);
	t1 = mem_read8(x + 0x4Fu);
	mem_write8(x + 0x4Fu, t1 - 1u);
	t2 = mem_read8(x + 0x4Fu);
	if ((t2 & 3u) != 0u)
	{
		t3 = mem_read8(x + 0x43u);
		mem_write8(x + 0x43u, t3 + 1u);
	}
	t4 = mem_read8(x + 0x3Au);
	mem_write8(x + 0x3Au, t4 - 1u);
	t5 = mem_read8(x + 0x3Au);
	t6 = DATA8(indexed_table_035832_ADDRESS + (t5 & 7u));
	a = t6;
	if ((int8_t)t6 < 0)
		return sub_034621(x);
	mem_write8(x + 0x3Bu, a);
	t7 = mem_read8(x + 0x3Au);
	mem_write8(x + 5u, DATA8(indexed_table_03583A_ADDRESS + (t7 & 7u)));
	t8 = mem_read8(x + 0x52u);
	mem_write8(x + 0x52u, t8 + 1u);
	return y;
}

uint16_t sub_03461C(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
	{
		sub_0785C9(x);
		return y;
	}
	return sub_034621(x);
}

uint16_t sub_034621(uint16_t x)
{
	uint16_t y = 0;

	mem_write8(x + 0x52u, 0u);
	mem_write8(x + 2u, 8u);
	mem_write8(x + 0x45u, 8u);
	sub_034226(x);
	mem_write8(x, 0xC0u);
	y = hit_box_035768_ADDRESS;
	sub_0785B4(x, y);
	sub_0785C9(x);
	return y;
}

uint16_t sub_03463D(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x52u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		y = sub_034649(x);
		break;
	case 2:
		sub_034673(x);
		break;
	case 4:
		y = sub_0346B2(x, y);
		break;
	case 6:
		y = sub_0346C5(x, y);
		break;
	case 8:
		y = sub_0346EC(x, y);
		break;
	case 10:
		y = sub_0346F4(x, y);
		break;
	}
	sub_03438C(x);
	return y;
}

uint16_t sub_034649(uint16_t x)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0;

	mem_write8(x, 0xC0u);
	sub_034226(x);
	y = hit_box_035768_ADDRESS;
	sub_0785B4(x, y);
	mem_write8(x + 0x43u, 1u);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	u = sub_078620(x);
	sub_078626(x, u);
	mem_write8(x + 5u, 0x8Bu);
	t1 = mem_read8(x + 0x52u);
	mem_write8(x + 0x52u, t1 + 1u);
	sub_0785C9(x);
	return y;
}

void sub_034673(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d = 0, u = 0;
	uint8_t t1 = 0, t4 = 0, t5 = 0, t6 = 0;
	uint16_t t2 = 0, t3 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
		return;
	d = 0x3800u;
	carry = sub_078680(d);
	t2 = mem_read16(x + 0x2Cu);
	mem_write8(x + 0x44u, (t2 >> 4) & 0xFu);
	t3 = mem_read16(x + 0x38u);
	u = t3;
	d = sub_07861D(x, u);
	a = (uint8_t)(d >> 8);
	t4 = mem_read8(x + 0x44u);
	d = ((uint32_t)a << 8) | DATA8(indexed_table_03584E_ADDRESS + (int8_t)t4);
	sub_078617(x, d);
	t5 = mem_read8(x + 0x44u);
	mem_write16(x + 0x19u, (uint32_t)DATA8(indexed_table_03585E_ADDRESS + (int8_t)t5) << 8);
	mem_write8(x, 0x80u);
	t6 = mem_read8(x + 0x52u);
	mem_write8(x + 0x52u, t6 + 1u);
	sub_0785C9(x);
}

uint16_t sub_0346B2(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	mem_write8(x, 0x80u);
	t1 = mem_read16(x + 0x19u);
	if ((int16_t)t1 < 0)
	{
		t2 = mem_read8(x + 0x52u);
		mem_write8(x + 0x52u, t2 + 1u);
	}
	sub_0785B1(x, &ignored16, &carry);
	if (carry)
		return sub_0346CA(x);
	return y;
}

uint16_t sub_0346C5(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;

	carry = sub_0343D1(x);
	if (carry == 0u)
		return y;
	return sub_0346CA(x);
}

uint16_t sub_0346CA(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0, y = 0;

	mem_write8(x, 0xC4u);
	y = hit_box_035770_ADDRESS;
	sub_0785B4(x, y);
	d = 0x6400u;
	carry = sub_078680(d);
	mem_write8(x + 5u, 0x84u);
	mem_write16(x + 0x19u, 0x400u);
	mem_write8(x + 0x52u, 4u);
	return y;
}

uint16_t sub_0346EC(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0;

	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 0x52u);
	mem_write8(x + 0x52u, t1 + 1u);
	return sub_0346F4(x, y);
}

uint16_t sub_0346F4(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, y_2 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry == 0u)
		return y;
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write8(x + 2u, 7u);
	mem_write8(x + 0x45u, 7u);
	mem_write8(x + 0x52u, 0u);
	sub_034226(x);
	mem_write8(x, 0xC0u);
	y_2 = hit_box_035768_ADDRESS;
	sub_0785B4(x, y_2);
	return y_2;
}

uint16_t sub_034719(uint16_t x, uint16_t y)
{
	uint8_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_034749(x);
		break;
	case 2:
		y = sub_034776(x, y);
		break;
	case 4:
		y = sub_03477C(x, y);
		break;
	case 6:
		sub_0347A5(x);
		break;
	case 8:
		sub_0347BD(x);
		break;
	case 10:
		sub_0347DE(x);
		break;
	case 12:
		sub_0347F9(x);
		break;
	case 14:
		y = sub_034814(x, y);
		break;
	case 16:
		sub_03486C(x);
		break;
	case 18:
		sub_034892(x);
		break;
	case 20:
		sub_0348F0(x);
		break;
	case 22:
		sub_034937(x);
		break;
	case 24:
		y = sub_03495B(x, y);
		break;
	case 26:
		sub_03496B(x);
		break;
	case -2:
		y = sub_03472F(x, y);
		break;
	}
	t2 = mem_read8(x + 0x43u);
	if (t2 == 0u)
		return y;
	t3 = mem_read8(x + 0x45u);
	d = t3;
	return sub_034077(x, y, d);
}

uint16_t sub_03472F(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x53u);
	mem_write8(x + 0x53u, t1 - 1u);
	if (t1 != 1u)
		return y;
	mem_write8(x, 0xC0u);
	y = hit_box_035768_ADDRESS;
	sub_0785B4(x, y);
	sub_034226(x);
	t2 = mem_read8(x + 0x45u);
	mem_write8(x + 2u, t2);
	return y;
}

void sub_034749(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	mem_write8(x, 0x80u);
	sub_034218(x);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	d = 0x6600u;
	carry = sub_078680(d);
	t1 = mem_read8(x + 0x43u);
	if (t1 == 0u)
	{
		mem_write8(x + 5u, 0x89u);
		t2 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t2 + 1u);
		return;
	}
	mem_write8(x + 0x53u, 8u);
	mem_write8(x + 0x29u, 0xFFu);
}

uint16_t sub_034776(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0;

	sub_034226(x);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	return sub_03477C(x, y);
}

uint16_t sub_03477C(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
		return y;
	mem_write8(x, 0xC0u);
	y = hit_box_035768_ADDRESS;
	sub_0785B4(x, y);
	mem_write8(x + 2u, 7u);
	mem_write8(x + 0x45u, 7u);
	mem_write8(x + 0x29u, 0u);
	mem_write8(x + 0x52u, 0u);
	return y;
}

uint16_t sub_03479C(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x4Eu);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_0347A5(x);
		return y;
	case 2:
		sub_0347BD(x);
		return y;
	case 4:
		sub_0347DE(x);
		return y;
	case 6:
		sub_0347F9(x);
		return y;
	case 8:
		return sub_034814(x, y);
	case 10:
		sub_03486C(x);
		return y;
	case 12:
		sub_034892(x);
		return y;
	case 14:
		sub_0348F0(x);
		return y;
	case 16:
		sub_034937(x);
		return y;
	case 18:
		return sub_03495B(x, y);
	case 20:
		sub_03496B(x);
		return y;
	case -8:
		return sub_03472F(x, y);
	case -6:
		sub_034749(x);
		return y;
	case -4:
		return sub_034776(x, y);
	case -2:
		return sub_03477C(x, y);
	}
	unreachable();
}

void sub_0347A5(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	mem_write8(x, 0xC8u);
	mem_write8(x + 0x45u, 0xAu);
	mem_write8(x + VIDEO_0031, 0u);
	d = 0x6600u;
	carry = sub_078680(d);
	t1 = mem_read8(x + 0x4Eu);
	mem_write8(x + 0x4Eu, t1 + 1u);
	sub_0347BD(x);
}

void sub_0347BD(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;
	uint8_t t1 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry)
	{
		mem_write8(x, 0xC8u);
		mem_write8(x + 5u, 0x85u);
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
		mem_write16(x + 0x19u, 0u);
		mem_write8(x + 0x3Bu, 0x80u);
		t1 = mem_read8(x + 0x4Eu);
		mem_write8(x + 0x4Eu, t1 + 1u);
	}
}

void sub_0347DE(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	sub_034234(x);
	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 4u, 0xBAu);
		mem_write8(x + 5u, 0x81u);
		mem_write8(x + 0x3Bu, 0x40u);
		t2 = mem_read8(x + 0x4Eu);
		mem_write8(x + 0x4Eu, t2 + 1u);
	}
}

void sub_0347F9(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	sub_034234(x);
	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 4u, 0xD0u);
		mem_write8(x + 5u, 0x85u);
		mem_write8(x + 0x3Bu, 0x40u);
		t2 = mem_read8(x + 0x4Eu);
		mem_write8(x + 0x4Eu, t2 + 1u);
	}
}

uint16_t sub_034814(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0;

	sub_034234(x);
	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return y;
	sub_034226(x);
	mem_write8(x + VIDEO_0031, 3u);
	mem_write8(x + 0x1Bu, 0xFFu);
	mem_write8(x, 0xC8u);
	y = hit_box_035768_ADDRESS;
	sub_0785B4(x, y);
	mem_write8(x + 2u, 0xBu);
	mem_write8(x + 0x45u, 0xBu);
	mem_write8(x + 0x52u, 0u);
	mem_write8(x + 0x4Eu, 0u);
	mem_write8(x + 0x43u, 0u);
	return y;
}

void sub_034846(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		mem_write8(x + 2u, 0xCu);
		mem_write8(x + 0x45u, 0xCu);
		mem_write8(x + 0x52u, 0u);
	}
}

uint16_t sub_034858(uint16_t x, uint16_t y)
{
	uint16_t u = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 0x52u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_03486C(x);
		break;
	case 2:
		sub_034892(x);
		break;
	case 4:
		sub_0348F0(x);
		break;
	case 6:
		sub_034937(x);
		break;
	case 8:
		y = sub_03495B(x, y);
		break;
	case 10:
		sub_03496B(x);
		break;
	case -18:
		y = sub_03472F(x, y);
		break;
	case -16:
		sub_034749(x);
		break;
	case -14:
		y = sub_034776(x, y);
		break;
	case -12:
		y = sub_03477C(x, y);
		break;
	case -10:
		sub_0347A5(x);
		break;
	case -8:
		sub_0347BD(x);
		break;
	case -6:
		sub_0347DE(x);
		break;
	case -4:
		sub_0347F9(x);
		break;
	case -2:
		y = sub_034814(x, y);
		break;
	}
	sub_034846(x);
	t2 = mem_read16(x + 0x38u);
	u = t2;
	sub_078626(x, u);
	sub_03438C(x);
	return y;
}

void sub_03486C(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	mem_write8(x, 0xC8u);
	sub_034226(x);
	mem_write8(x + 0x43u, 1u);
	mem_write8(x + 5u, 0x86u);
	sub_078620(x);
	t1 = mem_read8(x + 0x37u);
	mem_write8(x + 0x37u, t1 ^ 0x80u);
	mem_write8(x + 0x3Bu, 0xFFu);
	t2 = mem_read8(x + 0x52u);
	mem_write8(x + 0x52u, t2 + 1u);
}

void sub_034892(uint16_t x)
{
	uint8_t t2 = 0, t4 = 0, t5 = 0, t6 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0;
	uint16_t t1 = 0, t3 = 0, t7 = 0, t8 = 0;

	t1 = mem_read16(x + 0x2Cu);
	if (t1 < 0x100u)
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
		}
		else
		{
			mem_write16(x + 0xFu, 0u);
			mem_write16(x + 0x14u, 0x100u);
			t6 = mem_read8(x + 0x36u);
			if ((int8_t)t6 < 0)
			{
				t7 = mem_read16(x + 0x14u);
				mem_write16(x + 0x14u, 0u - t7);
			}
		}
	}
	t8 = mem_read16(x + 0x2Eu);
	if (t8 < 3u)
	{
		t9 = mem_read8(x + 0x52u);
		mem_write8(x + 0x52u, t9 + 1u);
	}
	t10 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t10 - 1u);
	t11 = mem_read8(x + 0x3Bu);
	if (t11 == 0u)
	{
		t12 = mem_read8(x + 0x37u);
		mem_write8(x + 0x37u, t12 ^ 0x80u);
	}
	t13 = mem_read8(x + 0x3Bu);
	if ((t13 & 0x1Fu) == 0u)
		sub_078620(x);
	sub_0785C9(x);
}

void sub_0348F0(uint16_t x)
{
	uint8_t t2 = 0, t5 = 0, t6 = 0, t7 = 0;
	uint16_t t1 = 0, t3 = 0, t4 = 0;

	t1 = mem_read16(x + 0x2Cu);
	if (t1 >= 0xE0u)
	{
		mem_write16(x + 0x14u, 0u);
		mem_write16(x + 0xFu, 0x100u);
		t2 = mem_read8(x + 0x36u);
		if ((int8_t)(t2 - 0x40u) >= 0)
		{
			t3 = mem_read16(x + 0xFu);
			mem_write16(x + 0xFu, 0u - t3);
		}
	}
	else
		mem_write16(x + 0xFu, 0u);
	t4 = mem_read16(x + 0x2Eu);
	if (t4 >= 3u)
	{
		t5 = mem_read8(x + 0x52u);
		mem_write8(x + 0x52u, t5 - 1u);
	}
	t6 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t6 - 1u);
	t7 = mem_read8(x + 0x3Bu);
	if ((t7 & 0x1Fu) == 0u)
		sub_078620(x);
	sub_0785C9(x);
}

uint16_t sub_03492B(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x52u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_034937(x);
		break;
	case 2:
		y = sub_03495B(x, y);
		break;
	case 4:
		sub_03496B(x);
		break;
	case -24:
		y = sub_03472F(x, y);
		break;
	case -22:
		sub_034749(x);
		break;
	case -20:
		y = sub_034776(x, y);
		break;
	case -18:
		y = sub_03477C(x, y);
		break;
	case -16:
		sub_0347A5(x);
		break;
	case -14:
		sub_0347BD(x);
		break;
	case -12:
		sub_0347DE(x);
		break;
	case -10:
		sub_0347F9(x);
		break;
	case -8:
		y = sub_034814(x, y);
		break;
	case -6:
		sub_03486C(x);
		break;
	case -4:
		sub_034892(x);
		break;
	case -2:
		sub_0348F0(x);
		break;
	}
	sub_03438C(x);
	return y;
}

void sub_034937(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t1 = 0;

	mem_write8(x, 0xC8u);
	sub_034226(x);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write8(x + 0x43u, 1u);
	mem_write8(x + 5u, 0x87u);
	t1 = mem_read8(x + 0x52u);
	mem_write8(x + 0x52u, t1 + 1u);
	u = sub_078620(x);
	sub_078626(x, u);
	sub_0785C9(x);
}

uint16_t sub_03495B(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, y_2 = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) == 0u)
	{
		sub_03496B(x);
		return y;
	}
	t2 = mem_read8(x + 0x52u);
	mem_write8(x + 0x52u, t2 + 1u);
	y_2 = child_object_03588C_ADDRESS;
	sub_07862F(x, y_2, &ignored16, &carry);
	return y_2;
}

void sub_03496B(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		mem_write8(x + 2u, 0xBu);
		mem_write8(x + 0x45u, 0xBu);
		mem_write8(x + 0x52u, 0u);
		mem_write8(x, 0xC8u);
		t2 = mem_read8(x + 9u);
		mem_write8(x + 9u, t2 & 0x7Fu);
		mem_write8(x + 6u, 0x80u);
	}
}

uint16_t sub_03498F(uint16_t x, uint16_t y)
{
	uint8_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_0349DA(x);
		break;
	case 2:
		sub_034A21(x);
		break;
	case 4:
		sub_034A27(x);
		break;
	case 6:
		sub_034A36(x);
		break;
	case 8:
		sub_034A50(x);
		break;
	case -4:
		sub_0349A5(x);
		break;
	case -2:
		sub_0349BE(x);
		break;
	}
	t2 = mem_read8(x + 0x43u);
	if (t2 == 0u)
		return y;
	t3 = mem_read8(x + 0x45u);
	d = t3;
	return sub_034077(x, y, d);
}

void sub_0349A5(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x53u);
	mem_write8(x + 0x53u, t1 - 1u);
	if (t1 != 1u)
		return;
	sub_034226(x);
	mem_write8(x, 0xC8u);
	mem_write8(x + 2u, 0xCu);
	mem_write8(x + 0x45u, 0xCu);
	mem_write8(x + 0x29u, 0u);
}

void sub_0349BE(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x53u);
	mem_write8(x + 0x53u, t1 - 1u);
	if (t1 != 1u)
		return;
	sub_034226(x);
	mem_write8(x, 0xC8u);
	mem_write8(x + 2u, 0xCu);
	mem_write8(x + 0x45u, 0xCu);
	mem_write8(x + 0x52u, 0u);
	mem_write8(x + 0x29u, 0u);
}

void sub_0349DA(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	mem_write8(x, 0x88u);
	sub_034218(x);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	d = 0x6600u;
	carry = sub_078680(d);
	t1 = mem_read8(x + 0x4Fu);
	mem_write8(x + 0x4Fu, t1 - 1u);
	t2 = mem_read8(x + 0x4Fu);
	if ((t2 & 7u) == 0u)
	{
		mem_write8(x + 0x43u, 0u);
		mem_write8(x + 5u, 0x83u);
		t3 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t3 + 1u);
		return;
	}
	mem_write8(x + 0x43u, 1u);
	mem_write8(x + 0x53u, 8u);
	t4 = mem_read8(x + 0x45u);
	if (t4 != 0xCu)
	{
		mem_write8(x + 0x29u, 0xFFu);
		return;
	}
	mem_write8(x + 0x29u, 0xFEu);
}

void sub_034A21(uint16_t x)
{
	uint8_t t1 = 0;

	sub_034226(x);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	sub_034A27(x);
}

void sub_034A27(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		mem_write8(x + 5u, 0x84u);
		t2 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t2 + 1u);
	}
}

void sub_034A36(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		t2 = mem_read8(x + 0x3Au);
		mem_write8(x + 0x3Au, t2 - 1u);
		t3 = mem_read8(x + 0x3Au);
		mem_write8(x + 5u, DATA8(indexed_table_0358A0_ADDRESS + (t3 & 3u)));
		t4 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t4 + 1u);
	}
}

void sub_034A50(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		mem_write8(x + 5u, 0x86u);
		mem_write8(x, 0xC8u);
		mem_write8(x + 2u, 0xBu);
		mem_write8(x + 0x45u, 0xBu);
		mem_write8(x + 0x29u, 0u);
	}
}

uint16_t sub_034A6C(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x4Eu);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_034A75(x);
		return y;
	case 2:
		sub_034A9B(x);
		return y;
	case 4:
		sub_034AB1(x);
		return y;
	case 6:
		sub_034ACC(x);
		return y;
	case 8:
		sub_034B03(x);
		return y;
	case 10:
		sub_034B21(x);
		return y;
	case 12:
		sub_034B40(x);
		return y;
	case 14:
		sub_034B5F(x);
		return y;
	case 16:
		sub_034B7E(x);
		return y;
	case 18:
		sub_034BB7(x);
		return y;
	case 20:
		return sub_034BC0(x);
	case 22:
		sub_034BDD(x);
		return y;
	}
	unreachable();
}

void sub_034A75(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x, 0xC8u);
	mem_write8(x + 0x45u, 0xEu);
	mem_write8(x + VIDEO_0031, 0u);
	mem_write8(x + 5u, 0x83u);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write16(x + 0x19u, 0u);
	mem_write8(x + 0x3Bu, 0x80u);
	t1 = mem_read8(x + 0x4Eu);
	mem_write8(x + 0x4Eu, t1 + 1u);
}

void sub_034A9B(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	sub_034234(x);
	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 5u, 0x8Au);
		mem_write8(x + 0x3Bu, 0x40u);
		t2 = mem_read8(x + 0x4Eu);
		mem_write8(x + 0x4Eu, t2 + 1u);
	}
}

void sub_034AB1(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	sub_034234(x);
	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 4u, 0xBAu);
		mem_write8(x + 5u, 0x81u);
		mem_write8(x + 0x3Bu, 0x40u);
		t2 = mem_read8(x + 0x4Eu);
		mem_write8(x + 0x4Eu, t2 + 1u);
	}
}

void sub_034ACC(uint16_t x)
{
	uint8_t t1 = 0;

	sub_034234(x);
	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	sub_034226(x);
	mem_write8(x + 5u, 0x82u);
	mem_write8(x + VIDEO_0031, 0u);
	mem_write8(x + 0x1Bu, 0xFFu);
	mem_write8(x, 0xC8u);
	mem_write8(x + 2u, 0xFu);
	mem_write8(x + 0x45u, 0xFu);
	mem_write8(x + 0x52u, 0u);
	mem_write8(x + 0x4Eu, 0u);
}

uint16_t sub_034AFA(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x52u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_034B03(x);
		return y;
	case 2:
		sub_034B21(x);
		return y;
	case 4:
		sub_034B40(x);
		return y;
	case 6:
		sub_034B5F(x);
		return y;
	case 8:
		sub_034B7E(x);
		return y;
	case 10:
		sub_034BB7(x);
		return y;
	case 12:
		return sub_034BC0(x);
	case 14:
		sub_034BDD(x);
		return y;
	case -8:
		sub_034A75(x);
		return y;
	case -6:
		sub_034A9B(x);
		return y;
	case -4:
		sub_034AB1(x);
		return y;
	case -2:
		sub_034ACC(x);
		return y;
	}
	unreachable();
}

void sub_034B03(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x, 0xC8u);
	mem_write16(x + 0xAu, 0x4040u);
	mem_write8(x + 0x3Bu, 2u);
	mem_write8(x + VIDEO_003C, 4u);
	mem_write8(x + 0x3Au, 4u);
	t1 = mem_read8(x + 0x52u);
	mem_write8(x + 0x52u, t1 + 1u);
}

void sub_034B21(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	mem_write8(x, mem_read8(x) | 0xD8u);
	t1 = mem_read8(x + 0xBu);
	t2 = mem_read8(x + VIDEO_003C);
	mem_write8(x + 0xBu, t1 + t2);
	t3 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t3 - 1u);
	if (t3 == 1u)
	{
		mem_write8(x + 0x3Bu, 2u);
		t4 = mem_read8(x + 0x52u);
		mem_write8(x + 0x52u, t4 + 1u);
	}
}

void sub_034B40(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	mem_write8(x, mem_read8(x) | 0xD8u);
	t1 = mem_read8(x + 0xBu);
	t2 = mem_read8(x + VIDEO_003C);
	mem_write8(x + 0xBu, t1 - t2);
	t3 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t3 - 1u);
	if (t3 == 1u)
	{
		mem_write8(x + 0x3Bu, 2u);
		t4 = mem_read8(x + 0x52u);
		mem_write8(x + 0x52u, t4 + 1u);
	}
}

void sub_034B5F(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	mem_write8(x, mem_read8(x) | 0xD8u);
	t1 = mem_read8(x + 0xAu);
	t2 = mem_read8(x + VIDEO_003C);
	mem_write8(x + 0xAu, t1 + t2);
	t3 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t3 - 1u);
	if (t3 == 1u)
	{
		mem_write8(x + 0x3Bu, 2u);
		t4 = mem_read8(x + 0x52u);
		mem_write8(x + 0x52u, t4 + 1u);
	}
}

void sub_034B7E(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;

	mem_write8(x, mem_read8(x) | 0xD8u);
	t1 = mem_read8(x + 0xAu);
	t2 = mem_read8(x + VIDEO_003C);
	mem_write8(x + 0xAu, t1 - t2);
	t3 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t3 - 1u);
	if (t3 != 1u)
		return;
	mem_write8(x + 0x3Bu, 2u);
	t4 = mem_read8(x + VIDEO_003C);
	mem_write8(x + VIDEO_003C, t4 - 1u);
	if (t4 != 1u)
	{
		mem_write8(x + 0x52u, 1u);
		return;
	}
	t5 = mem_read8(x + 0x3Au);
	mem_write8(x + 0x3Au, t5 - 1u);
	if (t5 == 1u)
	{
		mem_write8(x + 0x3Bu, 0x80u);
		t6 = mem_read8(x + 0x52u);
		mem_write8(x + 0x52u, t6 + 1u);
		return;
	}
	mem_write8(x + VIDEO_003C, 4u);
	mem_write8(x + 0x52u, 1u);
}

void sub_034BB7(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		t2 = mem_read8(x + 0x52u);
		mem_write8(x + 0x52u, t2 + 1u);
	}
}

uint16_t sub_034BC0(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, u = 0, y = 0;
	uint8_t t1 = 0;

	y = child_object_0358BC_ADDRESS;
	sub_07862C(x, y, &u, &ignored16, &carry);
	if (carry)
	{
		mem_write16(u + 0x38u, x);
		mem_write16(x + 0x40u, u);
		io_write8(VIDEO_185A, 1u);
		mem_write8(x + 0x3Bu, 0x80u);
		t1 = mem_read8(x + 0x52u);
		mem_write8(x + 0x52u, t1 + 1u);
	}
	return y;
}

void sub_034BDD(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 0x1Bu, 0xFFu);
		mem_write8(x + VIDEO_0031, 4u);
		mem_write8(x + 2u, 0x10u);
		mem_write8(x + 0x45u, 0x10u);
		mem_write8(x + 0x52u, 0u);
	}
}

void sub_034BF8(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x52u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_034C02(x);
		break;
	case 2:
		sub_034C29(x);
		break;
	}
}

void sub_034C02(uint16_t x)
{
	uint8_t a = 0;
	uint16_t d = 0, u = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	mem_write8(x, 0xC8u);
	sub_034226(x);
	u = sub_078620(x);
	d = sub_07861D(x, u);
	a = (uint8_t)(d >> 8);
	d = ((uint32_t)a << 8) | 0x20u;
	sub_078617(x, d);
	t1 = mem_read8(x + 0x4Fu);
	mem_write8(x + 0x4Fu, t1 - 1u);
	t2 = mem_read8(x + 0x4Fu);
	mem_write8(x + 0x3Bu, DATA8(indexed_table_0358C8_ADDRESS + (t2 & 0xFu)));
	t3 = mem_read8(x + 0x52u);
	mem_write8(x + 0x52u, t3 + 1u);
}

void sub_034C29(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	d = 0x6700u;
	carry = sub_078680(d);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write8(x + 2u, 0x11u);
	mem_write8(x + 0x45u, 0x11u);
	mem_write8(x + 0x52u, 0u);
}

uint16_t sub_034C46(uint16_t x, uint16_t y)
{
	uint8_t b = 0, d = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x52u);
	b = (uint32_t)t1 << 1;
	switch ((int8_t)b)
	{
	case 0:
		sub_034C4F(x);
		return y;
	case 2:
		sub_034C71(x);
		return y;
	case 4:
		sub_034C90(x);
		return y;
	case 6:
		sub_034CBE(x);
		return y;
	case 8:
		sub_034CDD(x);
		return y;
	case 10:
		return sub_034CF6(x, y);
	case 12:
		return sub_034D31(x, y);
	case 14:
		sub_034D88(x);
		return y;
	case 16:
		sub_034DA2(x);
		return y;
	case 18:
		d = b;
		sub_034DBB(x, d);
		return y;
	}
	unreachable();
}

void sub_034C4F(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0;

	mem_write8(x, 0xC8u);
	t1 = mem_read16(x + 0x40u);
	t2 = mem_read16(t1 + 0x40u);
	mem_write8(t2 + 2u, 2u);
	u = sub_078620(x);
	sub_078626(x, u);
	sub_0785C9(x);
	mem_write8(x + 0x3Bu, 0x80u);
	t3 = mem_read8(x + 0x52u);
	mem_write8(x + 0x52u, t3 + 1u);
}

void sub_034C71(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 2u, 0x10u);
		mem_write8(x + 0x45u, 0x10u);
		mem_write8(x + 0x52u, 0u);
	}
}

uint16_t sub_034C83(uint16_t x, uint16_t y)
{
	uint8_t b = 0, d = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x29u);
	b = (uint32_t)t1 << 1;
	d = b;
	switch ((int8_t)b)
	{
	case 0:
		sub_034C90(x);
		break;
	case 2:
		sub_034CBE(x);
		break;
	case 4:
		sub_034CDD(x);
		break;
	case 6:
		y = sub_034CF6(x, y);
		break;
	case 8:
		y = sub_034D31(x, y);
		break;
	case 10:
		sub_034D88(x);
		break;
	case 12:
		sub_034DA2(x);
		break;
	case 14:
		sub_034DBB(x, d);
		break;
	case -4:
		sub_034C4F(x);
		break;
	case -2:
		sub_034C71(x);
		break;
	}
	unk_48A7--;
	return y;
}

void sub_034C90(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t5 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	mem_write8(x, 0x88u);
	t1 = mem_read16(x + 0x40u);
	t2 = mem_read16(t1 + 0x40u);
	mem_write8(t2 + 2u, 5u);
	sub_034226(x);
	d = 0xFD00u;
	carry = sub_078680(d);
	mem_write16(x + 0xFu, 0x100u);
	t3 = mem_read16(x + 0xCu);
	if (t3 >= 0xE0u)
	{
		t4 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t4);
	}
	t5 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t5 + 1u);
}

void sub_034CBE(uint16_t x)
{
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = mem_read16(x + 0xCu);
	t2 = t1 - VIDEO_00C0;
	if (t2 < 0x40u)
	{
		mem_write8(x + 5u, 0x81u);
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
		mem_write8(x + 0x3Bu, 0x40u);
		t3 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t3 + 1u);
	}
}

void sub_034CDD(uint16_t x)
{
	uint8_t t1 = 0, t4 = 0;
	uint16_t t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		t2 = mem_read16(x + 0x40u);
		t3 = mem_read16(t2 + 0x40u);
		mem_write8(t3 + 2u, 0xFEu);
		mem_write8(x + 0x3Bu, 0x80u);
		t4 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t4 + 1u);
	}
}

uint16_t sub_034CF6(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return y;
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	d = 0x9800u;
	carry = sub_078680(d);
	d = 0x7100u;
	carry = sub_078680(d);
	mem_write16(x + 0x16u, 0x40u);
	mem_write8(x + 4u, 0xD1u);
	mem_write8(x + 5u, 0x88u);
	y = hit_box_035778_ADDRESS;
	sub_0785B4(x, y);
	mem_write8(x, 0xC4u);
	mem_write8(x + 0x3Bu, 0x80u);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	return y;
}

uint16_t sub_034D31(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0;

	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 0x3Bu);
	a = t1;
	if (a >= 0x40u && (a & 0x1Fu) == 0u)
	{
		t2 = mem_read8(x + VIDEO_003C);
		mem_write8(x + VIDEO_003C, t2 - 1u);
		t3 = mem_read8(x + VIDEO_003C);
		y = DATA16(indexed_table_0358EC_ADDRESS + (uint8_t)((t3 & 3u) << 1));
		sub_07862C(x, y, &ignored16, &ignored16_2, &carry);
	}
	t4 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t4 - 1u);
	if (t4 == 1u)
	{
		mem_write8(x + 5u, 0x81u);
		mem_write16(x + 0x19u, 0x400u);
		mem_write8(x, 0x88u);
		t5 = mem_read8(x + 0x5Bu);
		mem_write8(x + 0x5Bu, t5 & ~0xFu);
		t6 = mem_read8(x + 9u);
		mem_write8(x + 9u, t6 | 0x40u);
		t7 = mem_read8(x + 0x27u);
		mem_write8(x + 0x27u, t7 | 0x80u);
		mem_write8(x + 0x3Bu, 0x40u);
		t8 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t8 + 1u);
	}
	return y;
}

void sub_034D88(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0;
	uint8_t t1 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry == 0u)
		return;
	d = VIDEO_2000;
	carry = sub_078680(d);
	mem_write16(x + 0x19u, 0x400u);
	mem_write8(x, 0x88u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

void sub_034DA2(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0;
	uint8_t t1 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry == 0u)
		return;
	mem_write8(x, 0x88u);
	d = VIDEO_2000;
	carry = sub_078680(d);
	mem_write8(x + 0x3Bu, 0x80u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

void sub_034DBB(uint16_t x, uint8_t d)
{
	uint32_t carry = 0;
	uint16_t d_2 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x3Bu);
	if (t1 < 0x40u)
		mem_write8(x, mem_read8(x) ^ 0x84u);
	t2 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t2 - 1u);
	if (t2 == 1u)
	{
		mem_write8(x, 0u);
		unk_487D = 1u;
		unk_4804++;
		unk_4805 = 0x100u | d;
		return;
	}
	t3 = mem_read8(x + 0x3Bu);
	if (t3 == 0x40u)
	{
		d_2 = 0x9600u;
		carry = sub_078680(d_2);
	}
}

void sub_034E1C(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	mem_write8(x, 0x80u);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write16(x + 0x19u, 0u);
	d = 0x6C00u;
	carry = sub_078680(d);
	mem_write16(x + 4u, 0x480u);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
}

void sub_034E3A(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint32_t carry = 0;
	uint16_t d = 0, u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t5 = 0;
	uint16_t t4 = 0;

	u = object_setup_03592E_ADDRESS;
	y = sub_0785AB(x, u);
	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t1 & 0xCFu) | 0x10u);
	mem_write8(x, 0xC8u);
	mem_write16(x + 0xAu, 0x4040u);
	u = loaded_table_035926_ADDRESS + (uint8_t)((unk_4858 & 3u) << 1);
	mem_write16(x + 0xFu, (uint32_t)DATA8(u) << 8);
	t2 = mem_read8(u + 1u);
	mem_write8(x + 0x3Bu, t2);
	mem_write8(x + 0x3Eu, 0u);
	t3 = mem_read8(x + 9u);
	if ((t3 & 0x40u) != 0u)
	{
		t4 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t4);
		mem_write8(x + 0x3Eu, 0x80u);
	}
	d = VIDEO_1D00;
	carry = sub_078680(d);
	u = sub_078620(x);
	t5 = mem_read8(x + 2u);
	mem_write8(x + 2u, t5 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_034E8B(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0;
	uint8_t t1 = 0, t3 = 0, t4 = 0, t5 = 0;
	uint16_t t2 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		t2 = mem_read16(x + 0x38u);
		u = t2;
		d = sub_07861D(x, u);
		a = (uint8_t)(d >> 8);
		mem_write8(x + 0x36u, a);
		t3 = mem_read8(x + 0x3Eu);
		a = (int8_t)((int8_t)((int8_t)(a - t3) >> 1) >> 1) >> 1;
		mem_write8(x + 0x3Fu, a);
		if (a >= 2u)
			a = 0xAu;
		else
			a = 1u;
		mem_write8(x + 0x3Bu, a);
		t4 = mem_read8(x + 2u);
		mem_write8(x + 2u, t4 + 1u);
	}
	t5 = mem_read8(x + 0x3Bu);
	if ((t5 & 1u) == 0u)
	{
		y = child_object_03593C_ADDRESS;
		sub_07862C(x, y, &ignored16, &ignored16_2, &carry);
		t6 = mem_read16(x + 0x38u);
		u = t6;
		t7 = mem_read16(u + 0xCu);
		t8 = mem_read16(x + 0xCu);
		t9 = t7 - t8;
		t10 = t9;
		t11 = t10 >> 15 ? 0u - t10 : t10;
		if (t11 >= 0x20u)
		{
			t12 = mem_read16(x + 0x19u);
			t13 = t12 + 0x40u;
			mem_write16(x + 0x19u, t13);
		}
	}
	*p_y = y;
	*p_u = u;
}

void sub_034ED8(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d = 0, ignored16 = 0, u_2 = 0;
	uint8_t t1 = 0, t3 = 0, t4 = 0, t5 = 0, t8 = 0, t9 = 0, t10 = 0;
	uint16_t t2 = 0, t6 = 0, t7 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 0x3Bu, 0x40u);
		t2 = mem_read16(x + 0x38u);
		u_2 = t2;
		t3 = mem_read8(x + 0x36u);
		d = ((uint32_t)t3 << 8) | 0x80u;
		sub_078617(x, d);
		t4 = mem_read8(x + 2u);
		mem_write8(x + 2u, t4 + 1u);
		*p_y = y;
		*p_u = u_2;
		sub_034F24(x, p_y, p_u);
		return;
	}
	t5 = mem_read8(x + 0x3Bu);
	if ((t5 & 1u) == 0u)
	{
		y = child_object_03593C_ADDRESS;
		sub_07862C(x, y, &u, &ignored16, &carry);
	}
	t6 = mem_read16(x + 0x19u);
	t7 = t6 - 0x80u;
	mem_write16(x + 0x19u, t7);
	carry = sub_078662(x);
	if (carry)
	{
		mem_write8(x + 0x3Bu, 0x20u);
		t8 = mem_read8(x + 2u);
		mem_write8(x + 2u, t8 + 1u);
	}
	t9 = mem_read8(x + 0x3Eu);
	t10 = mem_read8(x + 0x3Fu);
	a = t9 + t10;
	mem_write8(x + 0x3Eu, a);
	d = ((uint32_t)a << 8) | 0x40u;
	sub_078617(x, d);
	*p_y = y;
	*p_u = u;
}

void sub_034F24(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t negative = 0, carry = 0;
	uint16_t d = 0, ignored16 = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x19u);
	mem_write16(x + 0x19u, t1 - 0x20u);
	carry = sub_078662(x);
	if (carry == 0u)
	{
		t2 = mem_read8(x + 0x3Bu);
		mem_write8(x + 0x3Bu, t2 - 1u);
		if (t2 != 1u)
		{
			t3 = mem_read8(x + 0x3Bu);
			if ((((uint16_t)((uint32_t)t3 << 8) >> 8) & 1u) == 0u)
			{
				y = child_object_03593C_ADDRESS;
				sub_07862C(x, y, &u, &ignored16, &carry);
			}
		}
		else
		{
			y = hit_box_035788_ADDRESS;
			sub_0785B4(x, y);
			mem_write16(x + 0xFu, 0u);
			mem_write16(x + 0x14u, 0u);
			mem_write16(x + 0x19u, 0u);
			d = 0x6C00u;
			carry = sub_078680(d);
			mem_write16(x + 4u, 0x480u);
			t4 = mem_read8(x + 2u);
			mem_write8(x + 2u, t4 + 1u);
		}
	}
	else
	{
		d = 0u;
		sub_078638(x, &d, &negative);
		if ((int8_t)(d >> 8) < 0)
		{
			mem_write16(x + 0xFu, 0u);
			mem_write16(x + 0x14u, 0u);
			mem_write16(x + 0x19u, 0u);
			d = 0x6C00u;
			carry = sub_078680(d);
			mem_write16(x + 4u, 0x480u);
			t4 = mem_read8(x + 2u);
			mem_write8(x + 2u, t4 + 1u);
		}
		else
		{
			t2 = mem_read8(x + 0x3Bu);
			mem_write8(x + 0x3Bu, t2 - 1u);
			if (t2 != 1u)
			{
				t3 = mem_read8(x + 0x3Bu);
				if ((((uint16_t)((uint32_t)t3 << 8) >> 8) & 1u) == 0u)
				{
					y = child_object_03593C_ADDRESS;
					sub_07862C(x, y, &u, &ignored16, &carry);
				}
			}
			else
			{
				y = hit_box_035788_ADDRESS;
				sub_0785B4(x, y);
				mem_write16(x + 0xFu, 0u);
				mem_write16(x + 0x14u, 0u);
				mem_write16(x + 0x19u, 0u);
				d = 0x6C00u;
				carry = sub_078680(d);
				mem_write16(x + 4u, 0x480u);
				t4 = mem_read8(x + 2u);
				mem_write8(x + 2u, t4 + 1u);
			}
		}
	}
	*p_y = y;
	*p_u = u;
}

void sub_034F6B(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	sub_034F73(x);
}

void sub_034F73(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
		mem_write8(x, 0u);
}

void sub_034F83(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0;

	u = object_setup_035948_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 0x80u);
	mem_write8(x + 9u, 0x10u);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_034F97(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
		mem_write8(x, 0u);
}

void sub_034FA7(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0;

	u = object_setup_035952_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 0x80u);
	mem_write8(x + 9u, 0x10u);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_034FBB(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;

	t1 = mem_read16(x + 0x40u);
	u = t1;
	t2 = mem_read8(u + 2u);
	if ((uint16_t)((uint32_t)t2 << 8) >> 8 == 0xAu)
	{
		mem_write8(x, 0u);
		return u;
	}
	t3 = mem_read16(u + 0xCu);
	t4 = mem_read16(x + 0xCu);
	mem_write16(x + 0xFu, (uint32_t)(uint8_t)(t3 - t4) << 8);
	t5 = mem_read16(u + 0x11u);
	t6 = mem_read16(x + 0x11u);
	mem_write16(x + 0x14u, (uint32_t)(uint8_t)(t5 - t6) << 8);
	return u;
}

uint16_t sub_034FE8(uint16_t x)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0;

	u = object_setup_03596E_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x + 0x3Bu, 0x80u);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	return y;
}

uint16_t sub_034FF7(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, u = 0, y_2 = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return y;
	unk_487C = 1u;
	y_2 = child_object_035966_ADDRESS;
	sub_07862C(x, y_2, &u, &ignored16, &carry);
	if (carry)
		mem_write16(u + 0x38u, x);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	return y_2;
}

void sub_035010(uint16_t x)
{
	uint8_t a = 0;
	uint16_t u = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0, t3 = 0;

	if ((uint8_t)unk_4815 != 0u)
		return;
	t1 = mem_read8(x + 5u);
	mem_write8(x + 5u, t1 | 0x80u);
	u = sub_078620(x);
	t2 = mem_read16(x + 0xCu);
	t3 = mem_read16(u + 0xCu);
	if (t3 <= t2)
		a = 0x40u;
	else
		a = 0u;
	mem_write8(x + 9u, a);
}

uint16_t sub_035038(uint16_t x)
{
	uint8_t a = 0, b = 0;
	uint16_t u = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x38u);
	u = t1;
	t2 = mem_read8(u + 9u);
	a = t2;
	t3 = mem_read8(x + 0x44u);
	if (a == t3)
		return u;
	mem_write8(x + 0x44u, a);
	t4 = mem_read8(x + 9u);
	b = t4;
	if ((int8_t)a >= 0)
		b &= 0x7Fu;
	else
		b |= 0x83u;
	mem_write8(x + 9u, b);
	mem_write8(x + 6u, 0x80u);
	return u;
}

uint16_t sub_03505B(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_03506E(x);
		break;
	case 2:
		y = sub_035088(x, y);
		break;
	case 4:
		sub_03509F(x);
		break;
	}
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write16(x + 0x19u, 0u);
	return y;
}

void sub_03506E(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	d = 0x6C00u;
	carry = sub_078680(d);
	mem_write8(x, 0x80u);
	mem_write16(x + 4u, 0xD185u);
	mem_write8(x + 0x3Bu, 4u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
}

uint16_t sub_035088(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		t2 = mem_read16(x + 0x2Eu);
		y = t2;
		mem_write8(y + 2u, 0xFEu);
		mem_write8(x + 0x3Bu, 4u);
		t3 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t3 + 1u);
	}
	return y;
}

void sub_03509F(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
		mem_write8(x, 0u);
}

uint16_t sub_0350A8(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0, d = 0;
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t8 = 0;
	uint16_t t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0;

	u = object_setup_035988_ADDRESS;
	sub_0785AB(x, u);
	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t1 & 0xCFu) | 0x10u);
	mem_write8(x, 4u);
	mem_write8(x + 0x42u, 0xFFu);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	unk_48F4 = 0x16u;
	mem_write16(x + 0x3Eu, 2u);
	mem_write16(x + 0x35u, 2u);
	mem_write8(x + 0x34u, 2u);
	mem_write8(x + 0x37u, 2u);
	mem_write8(x + VIDEO_003C, 0x10u);
	t3 = mem_read16(x + 0x38u);
	y = t3;
	mem_write16(x + 0x2Eu, y);
	mem_write16(x + 0x2Au, x);
	d = 2u;
	sub_07867D(d, &u, &carry);
	if (carry == 0u)
	{
		mem_write8(x, 0u);
		return y;
	}
	unk_48F2 = (uint8_t)(u >> 8u);
	unk_48F3 = (uint8_t)u;
	y = x;
	do
	{
		if (unk_48F4 == 1u)
		{
			u = (((uint32_t)unk_48F2 << 8u) | unk_48F3);
			a = 0xFEu;
			b = 0u;
			mem_write16(u + 1u, ((uint32_t)a << 8) | b);
			mem_write8(x + 0x34u, 0u);
			t4 = mem_read16(y + 0xCu);
			mem_write16(u + 0xCu, t4);
			t5 = mem_read16(y + 0x11u);
			mem_write16(u + 0x11u, t5);
			t6 = mem_read16(y + 0x16u);
			mem_write16(u + 0x16u, t6);
			mem_write16(u + 0x3Eu, 2u);
			mem_write16(u + 0x35u, 2u);
			mem_write8(u + 0x37u, 0u);
			mem_write8(u + VIDEO_003C, 0x10u);
			t7 = mem_read16(x + 0x38u);
			mem_write16(u + 0x38u, t7);
			mem_write16(u + 0x2Au, x);
			mem_write16(u + 0x2Eu, y);
			mem_write16(y + 0x2Cu, u);
			mem_write16(u + 0x50u, 0u);
			mem_write16(u + 0x52u, 0u);
			mem_write8(u + 0x32u, unk_48F4);
			y = u;
		}
		else
		{
			sub_035442(&u, &carry);
			if (carry)
			{
				a = 0xFFu;
				b = 2u;
				mem_write16(u + 1u, ((uint32_t)a << 8) | b);
				mem_write8(x + 0x34u, 0u);
				t4 = mem_read16(y + 0xCu);
				mem_write16(u + 0xCu, t4);
				t5 = mem_read16(y + 0x11u);
				mem_write16(u + 0x11u, t5);
				t6 = mem_read16(y + 0x16u);
				mem_write16(u + 0x16u, t6);
				mem_write16(u + 0x3Eu, 2u);
				mem_write16(u + 0x35u, 2u);
				mem_write8(u + 0x37u, 0u);
				mem_write8(u + VIDEO_003C, 0x10u);
				t7 = mem_read16(x + 0x38u);
				mem_write16(u + 0x38u, t7);
				mem_write16(u + 0x2Au, x);
				mem_write16(u + 0x2Eu, y);
				mem_write16(y + 0x2Cu, u);
				mem_write16(u + 0x50u, 0u);
				mem_write16(u + 0x52u, 0u);
				mem_write8(u + 0x32u, unk_48F4);
				y = u;
			}
		}
		t8 = unk_48F4;
		unk_48F4 = t8 - 1u;
	} while (t8 != 1u);
	u = loaded_table_03598E_ADDRESS;
	y = x;
	do
	{
		t9 = (((uint32_t)unk_48F2 << 8u) | unk_48F3);
		mem_write16(y + 0x40u, t9);
		t10 = u;
		u = t10 + 1u;
		mem_write8(y + 0x30u, mem_read8(t10));
		t11 = mem_read16(y + 0x2Cu);
		y = t11;
	} while (y != (((uint32_t)unk_48F2 << 8u) | unk_48F3));
	t12 = (((uint32_t)unk_48F2 << 8u) | unk_48F3);
	mem_write16(y + 0x40u, t12);
	mem_write8(y + 0x30u, mem_read8(u));
	return y;
}

void unused_0350C7(void)
{
}

uint16_t sub_035184(uint16_t x)
{
	uint16_t d = 0, y = 0;
	uint8_t t1 = 0, t4 = 0, t11 = 0, t12 = 0;
	uint16_t t2 = 0, t3 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0;

	t1 = mem_read8(x + 9u);
	mem_write8(x + 0x34u, (uint16_t)((uint32_t)t1 << 8) >> 8);
	t2 = mem_read16(x + 0x2Cu);
	y = t2;
	t3 = mem_read16(x + 0x3Eu);
	d = t3;
	mem_write8(y + 0x35u, d >> 8);
	t4 = mem_read8(x + 0x37u);
	d = (d & 0xFFu) | ((uint32_t)t4 << 8);
	sub_035472(d);
	mem_write16(x + 0x50u, (((uint32_t)unk_48E8 << 8u) | unk_48E9));
	mem_write16(x + 0x52u, (((uint32_t)unk_48EA << 8u) | unk_48EB));
	t5 = mem_read16(x + 0xCu);
	t6 = mem_read16(y + 0xCu);
	mem_write16(y + 0xFu, (uint32_t)(uint8_t)(t5 + (((uint32_t)unk_48E8 << 8u) | unk_48E9) - t6) << 8);
	t7 = mem_read16(x + 0x11u);
	t8 = mem_read16(y + 0x11u);
	mem_write16(y + 0x14u, (uint32_t)(uint8_t)(t7 - 2u - t8) << 8);
	t9 = mem_read16(x + 0x16u);
	t10 = mem_read16(y + 0x16u);
	mem_write16(y + 0x19u, (uint32_t)(uint8_t)(t9 + (((uint32_t)unk_48EA << 8u) | unk_48EB) - t10) << 8);
	t11 = mem_read8(x + 0x3Eu);
	mem_write8(x + 0x37u, (uint16_t)((uint32_t)t11 << 8) >> 8);
	t12 = mem_read8(x + 0x35u);
	mem_write8(x + 0x3Eu, (uint16_t)((uint32_t)t12 << 8) >> 8);
	sub_035218(x);
	return y;
}

void sub_0351E4(uint16_t u)
{
	uint16_t d = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0, t3 = 0;
	uint32_t unk_48F0_halfword = 0;

	t1 = io_read16(VIDEO_1888);
	unk_48F0_halfword = t1 + 0x10u;
	unk_48F0 = (uint8_t)(unk_48F0_halfword >> 8u);
	unk_48F1 = (uint8_t)unk_48F0_halfword;
	t2 = mem_read8(u + 9u);
	if ((((uint16_t)((uint32_t)t2 << 8) >> 8) & 0x40u) != 0u)
	{
		d = (((uint32_t)unk_48F0 << 8u) | unk_48F1) + 1u;
		if (d >= 0x20u)
			return;
		io_write16(VIDEO_1888, d - 0x10u);
		return;
	}
	t3 = (((uint32_t)unk_48F0 << 8u) | unk_48F1) - 1u;
	d = t3;
	if ((int16_t)t3 < 0)
		return;
	io_write16(VIDEO_1888, d - 0x10u);
}

void sub_035218(uint16_t x)
{
	uint16_t u = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0;

	t1 = mem_read16(x + 0x38u);
	u = t1;
	sub_0351E4(u);
	t2 = mem_read16(u + 0xCu);
	t3 = io_read16(VIDEO_1888);
	t4 = mem_read16(x + 0xCu);
	mem_write16(x + 0xFu, (uint32_t)(uint8_t)(t2 + t3 - t4) << 8);
	t5 = mem_read16(u + 0x11u);
	t6 = mem_read16(x + 0x11u);
	mem_write16(x + 0x14u, (uint32_t)(uint8_t)(t5 - 2u - t6) << 8);
	t7 = mem_read16(u + 0x16u);
	t8 = mem_read16(x + 0x16u);
	mem_write16(x + 0x19u, (uint32_t)(uint8_t)(t7 + 0x30u - t8) << 8);
}

uint16_t sub_03524C(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t1 = 0, t2 = 0, t4 = 0;
	uint16_t t3 = 0;

	u = object_setup_035988_ADDRESS;
	sub_0785AB(x, u);
	mem_write8(x, 0x80u);
	mem_write8(x + 0x42u, 0xFFu);
	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t1 & 0xCFu) | 0x10u);
	t2 = mem_read8(x + 0x30u);
	t3 = DATA16(loaded_table_0359A6_ADDRESS + (int8_t)((uint32_t)t2 << 1));
	mem_write8(x + 5u, t3 >> 8);
	mem_write8(x + 0x23u, t3);
	t4 = mem_read8(x + 2u);
	mem_write8(x + 2u, t4 + 1u);
	return sub_035285(x);
}

uint16_t sub_03527C(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x32u);
	mem_write8(x + 8u, t1);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	return sub_035285(x);
}

uint16_t sub_035285(uint16_t x)
{
	uint8_t a = 0;
	uint16_t u = 0, y = 0;
	uint8_t t14 = 0, t15 = 0, t16 = 0, t17 = 0, t18 = 0, t19 = 0, t21 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0, t20 = 0;

	t1 = mem_read16(x + 0x2Eu);
	u = t1;
	t2 = mem_read16(x + 0x2Cu);
	y = t2;
	t3 = mem_read16(x + 0xCu);
	t4 = mem_read16(x + 0x50u);
	t5 = mem_read16(y + 0xCu);
	mem_write16(y + 0xFu, (uint32_t)(uint16_t)(((uint32_t)a << 8) | (uint8_t)((((uint32_t)a << 8) | (uint8_t)((((uint32_t)a << 8) | (uint8_t)t3) + t4)) - t5)) << 8);
	t6 = mem_read16(u + 0x50u);
	a = (uint8_t)(t6 >> 8);
	mem_write16(x + 0x50u, ((uint32_t)a << 8) | (uint8_t)t6);
	t7 = mem_read16(x + 0x11u);
	t8 = mem_read16(y + 0x11u);
	a = (uint8_t)((((uint32_t)a << 8) | (uint8_t)((((uint32_t)a << 8) | (uint8_t)t7) - 2u)) - t8);
	mem_write16(y + 0x14u, (uint32_t)a << 8);
	t9 = mem_read16(x + 0x16u);
	t10 = mem_read16(x + 0x52u);
	t11 = mem_read16(y + 0x16u);
	mem_write16(y + 0x19u, (uint32_t)(uint8_t)((((uint32_t)a << 8) | (uint8_t)((((uint32_t)a << 8) | (uint8_t)t9) + t10)) - t11) << 8);
	t12 = mem_read16(u + 0x52u);
	mem_write16(x + 0x52u, t12);
	t13 = mem_read16(x + 0x2Eu);
	u = t13;
	t14 = mem_read8(x + 0x3Eu);
	a = t14;
	t15 = mem_read8(u + 9u);
	t16 = mem_read8(x + 9u);
	if ((t15 & t16) == 0u)
		a = 0u - a;
	mem_write8(x + 0x37u, a);
	t17 = mem_read8(u + 0x34u);
	mem_write8(x + 9u, t17);
	t18 = mem_read8(x + 0x35u);
	mem_write8(x + 0x3Eu, t18);
	t19 = mem_read8(x + 0x30u);
	if ((int8_t)t19 >= 0)
	{
		t20 = mem_read16(x + 0x40u);
		t21 = mem_read8(t20);
		a = t21;
		if ((int8_t)t21 < 0)
			mem_write8(x, a);
	}
	return y;
}

uint16_t sub_03530C(uint16_t x)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t5 = 0, t6 = 0;
	uint16_t t4 = 0;

	u = object_setup_0359D6_ADDRESS;
	sub_0785AB(x, u);
	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t1 & 0xCFu) | 0x10u);
	mem_write8(x + 0x42u, 0xFFu);
	mem_write8(x + 0x33u, 2u);
	y = object_1a_path_ADDRESS;
	mem_write16(x + 0x2Cu, object_1a_path_ADDRESS);
	t2 = mem_read8(x + 0x30u);
	t3 = DATA8(0x79A7u + (int8_t)((uint32_t)t2 << 1));
	mem_write8(x + 0x23u, t3);
	mem_write8(x + VIDEO_003C, 4u);
	t4 = mem_read16(x + 0x38u);
	t5 = mem_read8(t4 + 9u);
	mem_write8(x + 0x47u, t5);
	t6 = mem_read8(x + 2u);
	mem_write8(x + 2u, t6 + 1u);
	return y;
}

uint16_t sub_035352(uint16_t x, uint16_t y)
{
	uint8_t a = 0, b = 0;
	uint16_t u = 0, y_2 = 0;
	uint8_t t2 = 0, t3 = 0, t8 = 0, t10 = 0, t11 = 0;
	uint16_t t1 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t9 = 0, t12 = 0, t13 = 0, t14 = 0;

	t1 = mem_read16(x + 0x38u);
	t2 = mem_read8(t1 + 0x36u);
	if (t2 == 0u)
	{
		t3 = mem_read8(x + VIDEO_003C);
		mem_write8(x + VIDEO_003C, t3 - 1u);
		if (t3 != 1u)
			return y;
		mem_write8(x + VIDEO_003C, 1u);
	}
	t4 = mem_read16(x + 0x2Cu);
	t5 = t4;
	y = t5 + 2u;
	t6 = mem_read16(t5);
	a = (uint8_t)(t6 >> 8);
	b = (uint8_t)t6;
	if ((uint16_t)(((uint32_t)a << 8) | b) != 0xFFFFu)
	{
		unk_48F1 = b;
		t7 = mem_read16(x + 0x38u);
		t8 = mem_read8(t7 + 9u);
		if ((t8 & 0x40u) == 0u)
			a = 0u - a;
		a += 0x40u;
		t9 = mem_read16(x + 0x2Au);
		u = t9;
		mem_write16(u + 0x3Eu, ((uint32_t)a << 8) | unk_48F1);
		mem_write8(u + 0x35u, a);
		mem_write16(x + 0x2Cu, y);
		return y;
	}
	t10 = mem_read8(x + 0x33u);
	mem_write8(x + 0x33u, t10 - 1u);
	if (t10 != 1u)
		y_2 = mem_read16(y);
	else
	{
		t11 = mem_read8(y + 4u);
		mem_write8(x + 0x33u, t11);
		t12 = mem_read16(y + 2u);
		y_2 = t12;
	}
	t13 = y_2;
	y = t13 + 2u;
	t14 = mem_read16(t13);
	a = (uint8_t)(t14 >> 8);
	b = (uint8_t)t14;
	unk_48F1 = b;
	t7 = mem_read16(x + 0x38u);
	t8 = mem_read8(t7 + 9u);
	if ((t8 & 0x40u) == 0u)
		a = 0u - a;
	a += 0x40u;
	t9 = mem_read16(x + 0x2Au);
	u = t9;
	mem_write16(u + 0x3Eu, ((uint32_t)a << 8) | unk_48F1);
	mem_write8(u + 0x35u, a);
	mem_write16(x + 0x2Cu, y);
	return y;
}

uint16_t sub_0353A2(uint16_t x, uint16_t y)
{
	uint8_t a = 0;
	uint16_t u = 0;
	uint8_t t1 = 0, t2 = 0, t5 = 0;
	uint16_t t3 = 0, t4 = 0;

	mem_write8(x + 0x33u, 1u);
	t1 = mem_read8(x + 0x50u);
	mem_write8(x + 0x50u, t1 - 1u);
	t2 = mem_read8(x + 0x50u);
	a = DATA8(object_1a_path_choices_ADDRESS + (t2 & 7u));
	unk_48F0 = a;
	u = object_1a_path_starts_ADDRESS + (int8_t)(((uint32_t)a << 1) << 1);
	t3 = DATA16(u);
	mem_write16(x + 0x2Cu, t3);
	t4 = mem_read16(u + 2u);
	mem_write8(x + 0x3Bu, t4 >> 8);
	mem_write8(x + 0x3Au, t4);
	mem_write8(x + 0x4Fu, DATA8(object_1a_path_times_ADDRESS + (int8_t)unk_48F0));
	t5 = mem_read8(x + 2u);
	mem_write8(x + 2u, t5 + 1u);
	return sub_035352(x, y);
}

uint16_t sub_0353DD(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return sub_035352(x, y);
	mem_write8(x, 0xC0u);
	t2 = mem_read8(x + 9u);
	mem_write8(x + 9u, t2 | 0x83u);
	mem_write8(x + 6u, 0x80u);
	d = 0x6700u;
	carry = sub_078680(d);
	t3 = mem_read8(x + 2u);
	mem_write8(x + 2u, t3 + 1u);
	return sub_035352(x, y);
}

uint16_t sub_035401(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = mem_read8(x + 0x3Au);
	t2 = mem_read8(x + 0x4Fu);
	if (t1 == t2)
	{
		d = 0x6A00u;
		carry = sub_078680(d);
	}
	t3 = mem_read8(x + 0x3Au);
	mem_write8(x + 0x3Au, t3 - 1u);
	if (t3 != 1u)
		return sub_035352(x, y);
	mem_write8(x, 0x80u);
	t4 = mem_read8(x + 9u);
	mem_write8(x + 9u, t4 & 0x7Fu);
	mem_write8(x + 6u, 0x80u);
	mem_write8(x + 2u, 1u);
	return sub_035352(x, y);
}

uint16_t sub_03542F(uint16_t x, uint16_t y)
{
	mem_write8(x + 0x33u, 0xFFu);
	mem_write16(x + 0x2Cu, object_1a_dive_path_ADDRESS);
	mem_write8(x + 2u, 1u);
	return sub_035352(x, y);
}

void sub_035442(uint16_t *p_u, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t a = 0, b = 0;
	uint16_t u = 0, x = 0;
	uint16_t stack = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0, t3 = 0;

	u = unk_4D40_ADDRESS;
	a = 0x18u;
	for (;;)
	{
		if (mem_read8(u) != 0u)
		{
			u += 0x60u;
			t1 = a;
			a = t1 - 1u;
			if (t1 != 1u)
				continue;
			carry = 0u;
			break;
		}
		t2 = mem_read16(u + 0x59u);
		unk_48E8 = (uint8_t)(t2 >> 8u);
		unk_48E9 = (uint8_t)t2;
		stack = u;
		a = 0u;
		b = 0u;
		x = u;
		u = 0x30u;
		while (u != 0u)
		{
			mem_write8(x, a);
			mem_write8(x + 1u, b);
			x += 2u;
			u--;
		}
		u = stack;
		t3 = (((uint32_t)unk_48E8 << 8u) | unk_48E9);
		mem_write16(u + 0x59u, t3);
		mem_write8(u, 4u);
		carry = 1u;
		break;
	}
	*p_u = u;
	*p_carry = carry;
}

void sub_035472(uint16_t d)
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
	unk_48E9 = (uint16_t)((uint32_t)DATA8(indexed_table_035FA3_ADDRESS + a) * b) >> 8;
	unk_48EB = (uint16_t)((uint32_t)DATA8(indexed_table_035FA3_ADDRESS + (int8_t)(0x3Fu - unk_48EF)) * unk_48ED) >> 8;
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
