/**
 *    Name:        scenes/scene_objects.c
 *    Description: the scripted scenes' placements and the blanked places of absent players
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* A scripted scene: puts the given record of object_12_placements and hands back its object. */
uint16_t scene_put_placement(uint16_t default_object, uint16_t record_number)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t object = 0, place = 0, placement = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, object_2 = 0, t4 = 0, kind = 0, t5 = 0;
	uint32_t kind_halfword = 0;

	a = (uint8_t)(record_number >> 8);
	t1 = a | 0x1000u;
	b = (uint8_t)t1;
	carry = (int8_t)b < 0;
	b = (uint32_t)b << 1;
	a = (uint8_t)(((uint32_t)(uint8_t)((uint32_t)a << 8) << 1) | carry);
	carry = (int8_t)b < 0;
	b = (uint32_t)b << 1;
	a = (uint8_t)(((uint32_t)a << 1) | carry);
	carry = (int8_t)b < 0;
	t2 = object_12_placements_ADDRESS + (((((uint32_t)a << 1) | carry) << 8) | (uint8_t)((uint32_t)b << 1));
	place = t2 + 2u;
	object = PLACEMENT(t2)->object;
	if (object == 0xFFFFu)
		object = default_object;
	OBJECT(object)->flags = 0x80u;
	t3 = place;
	object_2 = PLACEMENT(t3)->object;
	kind_halfword = ((uint32_t)(object_2 >> 8) << 8) | (uint8_t)(object_2 | 0x80u);
	OBJECT(object)->kind = (uint8_t)(kind_halfword >> 8u);
	OBJECT(object)->animation = (uint8_t)kind_halfword;
	t4 = t3 + 2u;
	placement = t4 + 2u;
	kind = PLACEMENT(t4 - 0x2u)->kind;
	a = (uint8_t)(kind >> 8);
	b = (uint8_t)kind;
	if ((uint16_t)(((uint32_t)a << 8) | b) != 0xFFFFu)
		OBJECT(object)->x = ((uint32_t)a << 8) | b;
	OBJECT(object)->y = 0x80u;
	t5 = PLACEMENT(placement - 0x4u)->x;
	a = (uint8_t)(t5 >> 8);
	b = (uint8_t)t5;
	if ((uint16_t)(((uint32_t)a << 8) | b) != 0xFFFFu)
		OBJECT(object)->z = ((uint32_t)a << 8) | b;
	return object;
}

/* A scripted scene: covers a player's place with blank tiles (the given record of absent_player_blanks). */
void blank_absent_player(uint16_t player_and_blank)
{
	uint8_t colour = 0, tile = 0;
	uint16_t place = 0;
	uint8_t stack = 0;
	uint8_t t6 = 0, t7 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	blank_player = player_and_blank >> 8;
	t1 = absent_player_blanks[player_and_blank & 0x7Fu];
	blank_width = PLAYER_BLANK(t1)->width;
	t2 = t1 + 1u;
	blank_rows_left = PLAYER_BLANK(t2 - 0x1u)->height;
	t3 = t2 + 1u;
	t4 = t3 + 1u;
	colour = PLAYER_BLANK(t4 - 0x3u)->colour;
	stack = PLAYER_BLANK(t3 - 0x2u)->tile;
	place = PLAYER_BLANK(t4 + (int8_t)((uint32_t)blank_player << 1) - 0x3u)->marge_place;
	tile = stack;
	do
	{
		stack = tile;
		blank_columns_left = blank_width;
		tile = stack;
		do
		{
			mem_write8(place - 0x2000u, colour);
			t5 = place;
			place = t5 + 1u;
			mem_write8(t5, tile);
			t6 = blank_columns_left;
			blank_columns_left = t6 - 1u;
		} while (t6 != 1u);
		stack = colour;
		place += (int8_t)(0x40u - blank_width);
		colour = stack;
		t7 = blank_rows_left;
		blank_rows_left = t7 - 1u;
	} while (t7 != 1u);
}
