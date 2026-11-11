/**
 *    Name:        engine/objects.c
 *    Description: clearing the objects' slots, all of them or a list's
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    10-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Clears the 33 objects, giving each its 8 sprites' place in the sprite RAM (2000 + 80 each). */
void clear_objects(uint16_t *p_object_place, uint16_t *p_sprite_place)
{
	uint8_t blank_high = 0, blank_low = 0;
	uint16_t object_place = 0, sprite_place = 0;
	uint8_t words_left = 0;
	uint16_t cleared_word = 0;

	object_place = OBJECT_ADDRESS(0);
	sprite_place = 0x2000u;
	do
	{
		cleared_words_left = 0x30u;
		blank_low = 0u;
		blank_high = 0u;
		do
		{
			cleared_word = object_place;
			object_place = cleared_word + 2u;
			mem_write16(cleared_word, (uint32_t)blank_high << 8);
			words_left = cleared_words_left;
			cleared_words_left = words_left - 1u;
		} while (words_left != 1u);
		mem_write16(object_place - 7u, sprite_place);
		sprite_place += 0x80u;
	} while (object_place != 0x56A0u);
	*p_object_place = object_place;
	*p_sprite_place = sprite_place;
}

/* Clears the 8 objects of list 0, the enemies (4F80), all but the ones lending their sprites, keeping
   their sprite slots. */
void clear_enemy_objects(void)
{
	uint8_t blank_high = 0, blank_low = 0;
	uint16_t object_place = 0;
	uint8_t stack = 0, stack_10002 = 0;
	uint8_t words_left = 0, objects_left = 0;
	uint16_t kept_sprites = 0, cleared_word = 0;

	object_place = OBJECT_ADDRESS(14);
	cleared_objects_left = 8u;
	do
	{
		if (mem_read8(object_place) != 1u)
		{
			cleared_object_words_left = 0x30u;
			kept_sprites = mem_read16(object_place + 0x59u);
			stack = kept_sprites >> 8;
			stack_10002 = kept_sprites;
			blank_low = 0u;
			blank_high = 0u;
			do
			{
				cleared_word = object_place;
				object_place = cleared_word + 2u;
				mem_write16(cleared_word, (uint32_t)blank_high << 8);
				words_left = cleared_object_words_left;
				cleared_object_words_left = words_left - 1u;
			} while (words_left != 1u);
			mem_write16(object_place - 7u, ((uint32_t)stack << 8) | stack_10002);
		}
		else
			object_place += 0x60u;
		objects_left = cleared_objects_left;
		cleared_objects_left = objects_left - 1u;
	} while (objects_left != 1u);
}

/* Clears the 10 objects of list 1 (5280), all but the ones lending their sprites, keeping their sprite
   slots. */
void clear_list_1_objects(void)
{
	uint8_t blank_high = 0, blank_low = 0;
	uint16_t object_place = 0;
	uint8_t stack = 0, stack_10002 = 0;
	uint8_t words_left = 0, objects_left = 0;
	uint16_t kept_sprites = 0, cleared_word = 0;

	object_place = OBJECT_ADDRESS(22);
	cleared_objects_left = 0xAu;
	do
	{
		if (mem_read8(object_place) != 1u)
		{
			cleared_object_words_left = 0x30u;
			kept_sprites = mem_read16(object_place + 0x59u);
			stack = kept_sprites >> 8;
			stack_10002 = kept_sprites;
			blank_low = 0u;
			blank_high = 0u;
			do
			{
				cleared_word = object_place;
				object_place = cleared_word + 2u;
				mem_write16(cleared_word, (uint32_t)blank_high << 8);
				words_left = cleared_object_words_left;
				cleared_object_words_left = words_left - 1u;
			} while (words_left != 1u);
			mem_write16(object_place - 7u, ((uint32_t)stack << 8) | stack_10002);
		}
		else
			object_place += 0x60u;
		objects_left = cleared_objects_left;
		cleared_objects_left = objects_left - 1u;
	} while (objects_left != 1u);
}
