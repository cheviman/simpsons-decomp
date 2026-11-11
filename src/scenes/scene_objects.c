/**
 *    Name:        scenes/scene_objects.c
 *    Description: the scripted scenes' placements and the blanked places of absent players
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    10-11-2026
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
	uint8_t value_high = 0, value_low = 0;
	uint16_t object = 0, place = 0, placement = 0;
	uint16_t exchanged = 0, placement_record = 0, kind_at = 0, kind = 0, x_at = 0, t1 = 0, placement_z = 0;
	uint32_t kind_halfword = 0;

	value_high = (uint8_t)(record_number >> 8);
	exchanged = value_high | 0x1000u;
	value_low = (uint8_t)exchanged;
	carry = (int8_t)value_low < 0;
	value_low = (uint32_t)value_low << 1;
	value_high = (uint8_t)(((uint32_t)(uint8_t)((uint32_t)value_high << 8) << 1) | carry);
	carry = (int8_t)value_low < 0;
	value_low = (uint32_t)value_low << 1;
	value_high = (uint8_t)(((uint32_t)value_high << 1) | carry);
	carry = (int8_t)value_low < 0;
	placement_record = object_12_placements_ADDRESS + (((((uint32_t)value_high << 1) | carry) << 8) | (uint8_t)((uint32_t)value_low << 1));
	place = placement_record + 2u;
	object = PLACEMENT(placement_record)->object;
	if (object == 0xFFFFu)
		object = default_object;
	OBJECT(object)->flags = 0x80u;
	kind_at = place;
	kind = PLACEMENT(kind_at - 0x2u)->kind;
	kind_halfword = ((uint32_t)(kind >> 8) << 8) | (uint8_t)(kind | 0x80u);
	OBJECT(object)->kind = (uint8_t)(kind_halfword >> 8u);
	OBJECT(object)->animation = (uint8_t)kind_halfword;
	x_at = kind_at + 2u;
	placement = x_at + 2u;
	t1 = PLACEMENT(x_at - 0x4u)->x;
	value_high = (uint8_t)(t1 >> 8);
	value_low = (uint8_t)t1;
	if ((uint16_t)(((uint32_t)value_high << 8) | value_low) != 0xFFFFu)
		OBJECT(object)->x = ((uint32_t)value_high << 8) | value_low;
	OBJECT(object)->y = 0x80u;
	placement_z = PLACEMENT(placement - 0x6u)->z;
	value_high = (uint8_t)(placement_z >> 8);
	value_low = (uint8_t)placement_z;
	if ((uint16_t)(((uint32_t)value_high << 8) | value_low) != 0xFFFFu)
		OBJECT(object)->z = ((uint32_t)value_high << 8) | value_low;
	return object;
}

/* A scripted scene: covers a player's place with blank tiles (the given record of absent_player_blanks). */
void blank_absent_player(uint16_t player_and_blank)
{
	uint8_t colour = 0, tile = 0;
	uint16_t place = 0;
	uint8_t stack = 0;
	uint8_t columns_left = 0, rows_left = 0;
	uint16_t blank = 0, height_at = 0, tile_at = 0, colour_at = 0, tile_place = 0;

	blank_player = player_and_blank >> 8;
	blank = absent_player_blanks[player_and_blank & 0x7Fu];
	blank_width = PLAYER_BLANK(blank)->width;
	height_at = blank + 1u;
	blank_rows_left = PLAYER_BLANK(height_at - 0x1u)->height;
	tile_at = height_at + 1u;
	colour_at = tile_at + 1u;
	colour = PLAYER_BLANK(colour_at - 0x3u)->colour;
	stack = PLAYER_BLANK(tile_at - 0x2u)->tile;
	place = PLAYER_BLANK(colour_at + (int8_t)((uint32_t)blank_player << 1) - 0x3u)->marge_place;
	tile = stack;
	do
	{
		stack = tile;
		blank_columns_left = blank_width;
		tile = stack;
		do
		{
			mem_write8(place - 0x2000u, colour);
			tile_place = place;
			place = tile_place + 1u;
			mem_write8(tile_place, tile);
			columns_left = blank_columns_left;
			blank_columns_left = columns_left - 1u;
		} while (columns_left != 1u);
		stack = colour;
		place += (int8_t)(0x40u - blank_width);
		colour = stack;
		rows_left = blank_rows_left;
		blank_rows_left = rows_left - 1u;
	} while (rows_left != 1u);
}
