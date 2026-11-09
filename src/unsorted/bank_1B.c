/**
 *    Name:        unsorted/bank_1B.c
 *    Description: bank 1B's code
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

void sub_036018(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_036539_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_03631D(x, &y, &u);
		break;
	case 2:
		sub_036344(x);
		break;
	case 4:
		sub_036350(x);
		break;
	case 6:
		sub_036378(x, &y, &u);
		break;
	case 8:
		sub_036369(x);
		break;
	case 10:
		sub_0363B8(x);
		break;
	case 12:
		sub_0363C5();
		break;
	}
	carry = sub_078683(x, carry);
	*p_y = y;
	*p_u = u;
}

void sub_03601B(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_0364EC_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_0362AE(x, &y, &u);
		break;
	case -118:
	case 2:
		sub_036344(x);
		break;
	case 4:
		sub_0362D8(x);
		break;
	case 6:
		sub_03630B(x, &y, &u);
		break;
	case 8:
		sub_036301(x);
		break;
	case -108:
	case 10:
		sub_0363C5();
		break;
	}
	carry = sub_078683(x, carry);
	*p_y = y;
	*p_u = u;
}

void sub_03601E(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;
	uint16_t t1 = 0, t2 = 0;

	b = (uint8_t)d;
	u = loaded_table_036474_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_03624E(x, &y, &u);
		break;
	case 2:
	case 122:
		sub_036344(x);
		break;
	case 4:
		sub_036275(x);
		break;
	case 6:
		sub_03628E(x, &y, &u);
		break;
	case 8:
		sub_036369(x);
		break;
	case 10:
		sub_036297(x);
		break;
	case 12:
		sub_0363C5();
		break;
	}
	if (mem_read8(x) != 0u)
	{
		t1 = mem_read16(x + 0xCu);
		t2 = t1 - 0x30u;
		if (t2 >= 0x190u)
			mem_write8(x, 0u);
	}
	*p_y = y;
	*p_u = u;
}

void sub_036021(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = hit_box_036418_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_036030(x, &y, &u);
		break;
	case 2:
		sub_036049(x);
		break;
	case 4:
		sub_036055(x);
		break;
	case 6:
		sub_03606B(x);
		break;
	case 8:
		sub_03607F(x);
		break;
	case 10:
		sub_036098(x);
		break;
	case 12:
		sub_0360B5(x);
		break;
	case 14:
	case 20:
		sub_0360EC(x);
		break;
	case 16:
		sub_036108(x);
		break;
	case 18:
		sub_0360D6(x);
		break;
	case 22:
		sub_036107();
		break;
	}
	carry = sub_078683(x, carry);
	*p_y = y;
	*p_u = u;
}

void sub_036024(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;
	uint16_t t1 = 0;

	b = (uint8_t)d;
	u = loaded_table_036436_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_036133(x, &y, &u);
		break;
	case 2:
		sub_036142(x);
		break;
	case 4:
		sub_036153(x);
		break;
	case 6:
		sub_03615C(x);
		break;
	case 8:
		sub_036175(x);
		break;
	case 10:
	case 18:
		sub_036188(x);
		break;
	case 12:
		sub_036197(x, &y, &u);
		break;
	case 14:
		sub_0361E7(x);
		break;
	case 16:
		sub_036206(x);
		break;
	case 20:
		sub_036219(x);
		break;
	case 22:
		sub_036233();
		break;
	}
	t1 = mem_read16(x + 0xCu);
	if (t1 < 0x30u)
		mem_write8(x, 0u);
	*p_y = y;
	*p_u = u;
}

void sub_036030(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0;

	u = object_setup_036430_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t1 & 0xCFu) | 0x20u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_036049(uint16_t x)
{
	uint8_t t1 = 0;

	if (unk_48AC >= 0x120u)
	{
		t1 = mem_read8(x + 2u);
		mem_write8(x + 2u, t1 + 1u);
	}
}

void sub_036055(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write16(x + 0xFu, 0x200u);
	mem_write8(x + 5u, 0x82u);
	mem_write8(x + 0x3Bu, 0x2Cu);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	sub_0785C6(x);
}

void sub_03606B(uint16_t x)
{
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	d = player_variable_records_ADDRESS + 0xFu;
	sub_078617(x, d);
	mem_write8(x + 5u, 0x81u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
}

void sub_03607F(uint16_t x)
{
	uint32_t negative = 0;
	uint8_t a = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	d = 0u;
	sub_078638(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	if ((int8_t)a < 0 || (a & 0xFu) != 0u)
		return;
	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t1 & 0xCFu) | 0x10u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
}

void sub_036098(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write16(x + 0x14u, 0x80u);
	mem_write16(x + 0xFu, 0x140u);
	mem_write8(x + 5u, 0x82u);
	mem_write8(x + 0x3Bu, 0xCu);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	sub_0785C6(x);
}

void sub_0360B5(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
		mem_write8(x + 5u, 0x83u);
		t2 = mem_read8(x + 9u);
		mem_write8(x + 9u, t2 | 0x40u);
		mem_write8(x + 0x3Bu, 0x40u);
		t3 = mem_read8(x + 2u);
		mem_write8(x + 2u, t3 + 1u);
	}
}

void sub_0360D6(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 5u, 0x83u);
		mem_write16(x + 0xFu, 0u);
		mem_write8(x + 0x3Bu, 0x40u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_0360EC(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
	{
		sub_036107();
		return;
	}
	mem_write8(x + 5u, 0x82u);
	mem_write16(x + 0xFu, 0xFE00u);
	mem_write8(x + 0x3Bu, 0x10u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	sub_0785C6(x);
}

void sub_036107(void)
{
}

void sub_036108(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 5u, 0x84u);
		mem_write8(x + 0x3Bu, 0x18u);
		mem_write16(x + 0xFu, 0xFB00u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_036133(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0;

	u = object_setup_03644E_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_036142(uint16_t x)
{
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = unk_48AC;
	if (t1 >= 0x120u)
	{
		mem_write8(x + 0x3Bu, 0x2Cu);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_036153(uint16_t x)
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

void sub_03615C(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	mem_write8(x, 0xC0u);
	d = spawn_lists_ADDRESS;
	carry = sub_078680(d);
	mem_write8(x + 5u, 0x8Au);
	mem_write8(x + 0x3Bu, 0x10u);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
}

void sub_036175(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x, 0x80u);
		mem_write8(x + 5u, 0x8Bu);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_036188(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if (t1 & 1u)
	{
		mem_write8(x + 0x3Bu, 0x20u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_036197(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint8_t a = 0;
	uint16_t u_2 = 0, y_2 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = mem_read8(x + 0x3Bu);
	a = t1;
	if (a >= 0x18u)
	{
		t2 = mem_read8(x + 0x17u);
		mem_write8(x + 0x17u, (a & 1u) ^ t2);
	}
	t3 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t3 - 1u);
	if (t3 != 1u)
		return;
	sub_0361B9(x, &y_2, &u_2);
	mem_write8(x + 0x3Bu, 0x36u);
	mem_write8(x + 0x17u, 0u);
	t4 = mem_read8(x + 2u);
	mem_write8(x + 2u, t4 + 1u);
	*p_y = y_2;
	*p_u = u_2;
}

void sub_0361B9(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint32_t carry = 0;
	uint8_t players = 0;
	uint16_t ignored16 = 0, u = 0, y = 0;
	uint8_t t1 = 0, t3 = 0, t4 = 0, t5 = 0;
	uint16_t t2 = 0;

	mem_write8(x + 0x3Au, 0u);
	u = door_spawn_lists_ADDRESS;
	t1 = mem_read8(x + 0x30u);
	y = door_spawn_lists[(int8_t)((uint8_t)((uint32_t)t1 << 1)) / 2];
	for (;;)
	{
		t2 = y;
		y = t2 + 1u;
		players = DOOR_SPAWN(t2)->players;
		if (players == 0x7Fu)
			break;
		t3 = io_read8(VIDEO_1874);
		if (players < t3)
		{
			t4 = mem_read8(x + 0x3Au);
			mem_write8(x + 0x3Au, t4 + 1u);
			sub_07862C(x, y, &u, &ignored16, &carry);
		}
		y += 8u;
	}
	t5 = mem_read8(x + 0x3Au);
	mem_write8(x + 0x3Au, ((((uint32_t)t5 << 1) << 1) << 1) << 1);
	*p_y = y;
	*p_u = u;
}

void sub_0361E7(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(x, 0xC0u);
	t2 = mem_read8(x + 0x3Au);
	mem_write8(x + 0x3Bu, t2);
	d = spawn_lists_ADDRESS;
	carry = sub_078680(d);
	mem_write8(x + 5u, 0x8Cu);
	t3 = mem_read8(x + 2u);
	mem_write8(x + 2u, t3 + 1u);
}

void sub_036206(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 5u, 0x8Du);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
	mem_write8(x, 0x80u);
}

void sub_036219(uint16_t x)
{
	uint8_t a = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = mem_read8(x + 0x3Bu);
	a = t1;
	if (a >= 0x18u)
	{
		t2 = mem_read8(x + 0x17u);
		mem_write8(x + 0x17u, (a & 1u) ^ t2);
	}
	t3 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t3 - 1u);
	if (t3 != 1u)
	{
		sub_036233();
		return;
	}
	mem_write8(x + 0x17u, 0u);
	t4 = mem_read8(x + 2u);
	mem_write8(x + 2u, t4 + 1u);
	sub_036233();
}

void sub_036233(void)
{
}

void sub_03624E(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t opening = 0, u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0;
	uint16_t x_2 = 0, wait = 0;

	u = object_setup_036482_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 0x30u);
	opening = kind_12_door_openings_ADDRESS + (int8_t)(((uint32_t)t1 << 1) << 1);
	x_2 = DOOR_OPENING(opening)->x;
	mem_write16(x + 0x3Eu, x_2);
	wait = (((uint32_t)DOOR_OPENING(opening)->wait << 8u) | DOOR_OPENING(opening)->list);
	mem_write8(x + 0x30u, wait);
	mem_write8(x + 9u, 0u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	*p_y = y;
	*p_u = opening;
}

void sub_036275(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	mem_write8(x, 0xC0u);
	mem_write8(x + 0x1Du, 8u);
	d = spawn_lists_ADDRESS;
	carry = sub_078680(d);
	mem_write8(x + 5u, 0x8Au);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
}

void sub_03628E(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;

	mem_write8(x + 0x3Au, 0u);
	u = indexed_table_036498_ADDRESS;
	*p_y = y;
	*p_u = u;
	sub_03637E(x, p_y, p_u);
}

void sub_036297(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 5u, 0x8Bu);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_0362AE(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t opening = 0, u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0;
	uint16_t x_2 = 0, wait = 0;

	u = object_setup_0364F8_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 0x30u);
	opening = kind_10_door_openings_ADDRESS + (int8_t)(((uint32_t)t1 << 1) << 1);
	x_2 = DOOR_OPENING(opening)->x;
	mem_write16(x + 0x3Eu, x_2);
	wait = (((uint32_t)DOOR_OPENING(opening)->wait << 8u) | DOOR_OPENING(opening)->list);
	mem_write8(x + 0x3Bu, wait >> 8);
	mem_write8(x + 0x30u, wait);
	mem_write8(x + 9u, 0u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	*p_y = y;
	*p_u = opening;
}

void sub_0362D8(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(x, 0xC0u);
	mem_write8(x + 0x1Du, 8u);
	d = spawn_lists_ADDRESS;
	carry = sub_078680(d);
	mem_write16(x + 4u, 0xF95u);
	t2 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t2 & 0x30u) | 0x83u);
	t3 = mem_read8(x + 2u);
	mem_write8(x + 2u, t3 + 1u);
}

void sub_036301(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	if (t1 & 1u)
		mem_write8(x, 0u);
}

void sub_03630B(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;

	mem_write8(x + 0x3Au, 0u);
	u = indexed_table_03650A_ADDRESS;
	*p_y = y;
	*p_u = u;
	sub_03637E(x, p_y, p_u);
}

void sub_03631D(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t opening = 0, u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0;
	uint16_t x_2 = 0, wait = 0;

	u = object_setup_036547_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 0x30u);
	opening = kind_0f_door_openings_ADDRESS + (int8_t)(((uint32_t)t1 << 1) << 1);
	x_2 = DOOR_OPENING(opening)->x;
	mem_write16(x + 0x3Eu, x_2);
	wait = (((uint32_t)DOOR_OPENING(opening)->wait << 8u) | DOOR_OPENING(opening)->list);
	mem_write8(x + 0x30u, wait);
	mem_write8(x + 9u, 0u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	*p_y = y;
	*p_u = opening;
}

void sub_036344(uint16_t x)
{
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = mem_read16(x + 0xCu);
	t2 = mem_read16(x + 0x3Eu);
	if (t1 < t2)
	{
		t3 = mem_read8(x + 2u);
		mem_write8(x + 2u, t3 + 1u);
	}
}

void sub_036350(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	mem_write8(x, 0xC0u);
	mem_write8(x + 0x1Du, 8u);
	d = spawn_lists_ADDRESS;
	carry = sub_078680(d);
	mem_write8(x + 5u, 0x8Fu);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
}

void sub_036369(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if (t1 & 1u)
	{
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
	mem_write8(x, 0x80u);
}

void sub_036378(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;

	mem_write8(x + 0x3Au, 0u);
	u = indexed_table_03655D_ADDRESS;
	*p_y = y;
	*p_u = u;
	sub_03637E(x, p_y, p_u);
}

void sub_03637E(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t ignored16 = 0, y = 0;
	uint8_t t1 = 0, t3 = 0, t4 = 0, t6 = 0, t7 = 0, t8 = 0;
	uint16_t t2 = 0, t5 = 0;

	t1 = mem_read8(x + 0x30u);
	t2 = mem_read16(u + (int8_t)((uint32_t)t1 << 1));
	y = t2 + 1u;
	a = mem_read8(t2);
	if (a != 0x7Fu)
	{
		do
		{
			t3 = io_read8(VIDEO_1874);
			if (a < t3)
			{
				t4 = mem_read8(x + 0x3Au);
				mem_write8(x + 0x3Au, t4 + 1u);
				sub_07862C(x, y, &u, &ignored16, &carry);
			}
			y += 8u;
			t5 = y;
			y = t5 + 1u;
			a = mem_read8(t5);
		} while (a != 0x7Fu);
		t6 = mem_read8(x + 0x3Au);
		mem_write8(x + 0x3Bu, ((((uint32_t)t6 << 1) << 1) << 1) << 1);
		t7 = mem_read8(x + 2u);
		mem_write8(x + 2u, t7 + 1u);
	}
	else
	{
		mem_write8(x + 0x3Bu, 0x18u);
		t8 = mem_read8(x + 2u);
		mem_write8(x + 2u, t8 + 1u);
	}
	*p_y = y;
	*p_u = u;
}

void sub_0363B8(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
	{
		sub_0363C5();
		return;
	}
	mem_write8(x + 5u, 0x90u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	sub_0363C5();
}

void sub_0363C5(void)
{
}
