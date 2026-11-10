/**
 *    Name:        engine/objects.c
 *    Description: clearing the objects' slots, all of them or a list's
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Clears the 33 objects, giving each its 8 sprites' place in the sprite RAM (2000 + 80 each). */
void clear_objects(uint16_t *p_object_place, uint16_t *p_sprite_place)
{
	uint8_t a = 0, d = 0;
	uint16_t object_place = 0, sprite_place = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	object_place = OBJECT_ADDRESS(0);
	sprite_place = 0x2000u;
	do
	{
		cleared_words_left = 0x30u;
		d = 0u;
		a = 0u;
		do
		{
			t1 = object_place;
			object_place = t1 + 2u;
			mem_write16(t1, (uint32_t)a << 8);
			t2 = cleared_words_left;
			cleared_words_left = t2 - 1u;
		} while (t2 != 1u);
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
	uint8_t a = 0, d = 0;
	uint16_t object_place = 0;
	uint8_t stack = 0, stack_10002 = 0;
	uint8_t t3 = 0, t4 = 0;
	uint16_t t1 = 0, t2 = 0;

	object_place = OBJECT_ADDRESS(14);
	cleared_objects_left = 8u;
	do
	{
		if (mem_read8(object_place) != 1u)
		{
			cleared_object_words_left = 0x30u;
			t1 = mem_read16(object_place + 0x59u);
			stack = t1 >> 8;
			stack_10002 = t1;
			d = 0u;
			a = 0u;
			do
			{
				t2 = object_place;
				object_place = t2 + 2u;
				mem_write16(t2, (uint32_t)a << 8);
				t3 = cleared_object_words_left;
				cleared_object_words_left = t3 - 1u;
			} while (t3 != 1u);
			mem_write16(object_place - 7u, ((uint32_t)stack << 8) | stack_10002);
		}
		else
			object_place += 0x60u;
		t4 = cleared_objects_left;
		cleared_objects_left = t4 - 1u;
	} while (t4 != 1u);
}

/* Clears the 10 objects of list 1 (5280), all but the ones lending their sprites, keeping their sprite
   slots. */
void clear_list_1_objects(void)
{
	uint8_t a = 0, d = 0;
	uint16_t object_place = 0;
	uint8_t stack = 0, stack_10002 = 0;
	uint8_t t3 = 0, t4 = 0;
	uint16_t t1 = 0, t2 = 0;

	object_place = OBJECT_ADDRESS(22);
	cleared_objects_left = 0xAu;
	do
	{
		if (mem_read8(object_place) != 1u)
		{
			cleared_object_words_left = 0x30u;
			t1 = mem_read16(object_place + 0x59u);
			stack = t1 >> 8;
			stack_10002 = t1;
			d = 0u;
			a = 0u;
			do
			{
				t2 = object_place;
				object_place = t2 + 2u;
				mem_write16(t2, (uint32_t)a << 8);
				t3 = cleared_object_words_left;
				cleared_object_words_left = t3 - 1u;
			} while (t3 != 1u);
			mem_write16(object_place - 7u, ((uint32_t)stack << 8) | stack_10002);
		}
		else
			object_place += 0x60u;
		t4 = cleared_objects_left;
		cleared_objects_left = t4 - 1u;
	} while (t4 != 1u);
}
