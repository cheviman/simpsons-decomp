/**
 *    Name:        enemies/enemy_targets.c
 *    Description: the nearest player, the direction and distance to it, the attack ranges, the random number
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Makes the nearest player in play (by the x and the y distance added) the enemy's target; with no
   players, the last one found. */
uint16_t enemy_target_nearest_player(uint16_t object)
{
	uint16_t distance = 0, object_2 = 0, target = 0;
	uint8_t stack = 0;
	uint16_t stack_3 = 0;
	uint8_t t1 = 0, t9 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0;

	t1 = io_read8(0x1874u);
	if (t1 == 0u)
	{
		t2 = io_read16(0x1872u);
		target = t2;
		OBJECT(object)->target = target;
		return target;
	}
	stack = 4u;
	object_2 = OBJECT_ADDRESS(0);
	nearest_player_distance = 0x7FFFu;
	do
	{
		if (OBJECT(object_2)->flags != 0u)
		{
			t3 = OBJECT(object)->x;
			t4 = OBJECT(object_2)->x;
			t5 = t3 - t4;
			distance = t5;
			if ((int16_t)t5 < 0)
				distance = 0u - distance;
			stack_3 = distance;
			t6 = OBJECT(object)->y;
			t7 = OBJECT(object_2)->y;
			t8 = t6 - t7;
			distance = t8;
			if ((int16_t)t8 < 0)
				distance = 0u - distance;
			distance += stack_3;
			if (distance < nearest_player_distance)
			{
				nearest_player_distance = distance;
				io_write16(0x1872u, object_2);
			}
		}
		object_2 += 0xC0u;
		t9 = stack;
		stack = t9 - 1u;
	} while (t9 != 1u);
	t2 = io_read16(0x1872u);
	target = t2;
	OBJECT(object)->target = target;
	return target;
}

/* A random number for the enemies' choices: the frame's random number added to the last one. */
uint16_t enemy_random(uint8_t d)
{
	uint8_t value = 0;
	uint16_t roll = 0;
	uint8_t t1 = 0;

	t1 = io_read8(0x189Eu);
	value = t1 + random_number;
	io_write8(0x189Eu, value);
	roll = (d & 0xFFu) | ((uint32_t)value << 8);
	return roll;
}

/* Measures the enemy's distance to its target in x and in depth, the direction to it in eighths of a
   turn, and whether it stands close behind a target that faces away. */
void enemy_look_at_target(uint16_t object, uint16_t target)
{
	uint8_t distance_high = 0, distance_low = 0;
	uint8_t target_direction = 0, target_direction_2 = 0, target_direction_3 = 0, attributes = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, target_dx = 0, target_dy = 0, target_dx_2 = 0, target_dy_2 = 0, target_dy_3 = 0, target_dx_3 = 0;

	target_left_bit = 0u;
	OBJECT(object)->target_direction = 0u;
	t1 = OBJECT(target)->x;
	t2 = OBJECT(object)->x;
	t3 = t1 - t2;
	distance_low = (uint8_t)t3;
	distance_high = (uint8_t)(t3 >> 8);
	if ((int16_t)t3 >= 0)
		OBJECT(object)->target_dx = ((uint32_t)distance_high << 8) | (distance_low & 0xFFu);
	else
	{
		t4 = 0u - (((uint32_t)distance_high << 8) | (distance_low & 0xFFu));
		OBJECT(object)->target_dx = t4;
		OBJECT(object)->target_direction = 0x40u;
		target_left_bit = 0x40u;
	}
	t5 = OBJECT(target)->y;
	t6 = OBJECT(object)->y;
	t7 = t5 - t6;
	distance_low = (uint8_t)t7;
	distance_high = (uint8_t)(t7 >> 8);
	if ((int16_t)t7 >= 0)
		OBJECT(object)->target_dy = ((uint32_t)distance_high << 8) | (distance_low & 0xFFu);
	else
	{
		t8 = 0u - (((uint32_t)distance_high << 8) | (distance_low & 0xFFu));
		OBJECT(object)->target_dy = t8;
		target_direction = OBJECT(object)->target_direction;
		OBJECT(object)->target_direction = target_direction ^ 0xC0u;
	}
	target_direction_2 = OBJECT(object)->target_direction;
	if ((target_direction_2 & 0x40u) != 0u)
	{
		target_dx = OBJECT(object)->target_dx;
		target_dy = OBJECT(object)->target_dy;
		if (target_dy <= target_dx)
		{
			target_direction_3 = OBJECT(object)->target_direction;
			OBJECT(object)->target_direction = target_direction_3 | 0x20u;
		}
	}
	else
	{
		target_dx_2 = OBJECT(object)->target_dx;
		target_dy_2 = OBJECT(object)->target_dy;
		if (target_dx_2 < target_dy_2)
		{
			target_direction_3 = OBJECT(object)->target_direction;
			OBJECT(object)->target_direction = target_direction_3 | 0x20u;
			attributes = OBJECT(target)->attributes;
			if ((int8_t)((uint32_t)(target_left_bit ^ attributes) << 1) >= 0)
			{
				target_dy_3 = OBJECT(object)->target_dy;
				if (target_dy_3 < 8u)
				{
					target_dx_3 = OBJECT(object)->target_dx;
					if (target_dx_3 < 0x40u)
					{
						OBJECT(object)->enemy.not_behind_target = 0u;
						return;
					}
				}
			}
			OBJECT(object)->enemy.not_behind_target = 0x80u;
			return;
		}
	}
	attributes = OBJECT(target)->attributes;
	if ((int8_t)((uint32_t)(target_left_bit ^ attributes) << 1) >= 0)
	{
		target_dy_3 = OBJECT(object)->target_dy;
		if (target_dy_3 < 8u)
		{
			target_dx_3 = OBJECT(object)->target_dx;
			if (target_dx_3 < 0x40u)
			{
				OBJECT(object)->enemy.not_behind_target = 0u;
				return;
			}
		}
	}
	OBJECT(object)->enemy.not_behind_target = 0x80u;
}

/* Finds the first of its behaviour's 4 attack ranges its target is in (within the range's depth and
   between its least and most x distance): carry set, with the range's chance to attack. */
void enemy_find_attack_range(uint16_t object, uint16_t *p_range, uint16_t *p_chance, uint32_t *p_carry)
{
	uint16_t range = (uint16_t)*p_range;
	uint32_t carry = *p_carry;
	uint8_t a = 0, x_distance = 0;
	uint16_t chance = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;
	uint16_t target_dx = 0, target_dy = 0;

	target_dx = OBJECT(object)->target_dx;
	a = (uint8_t)(target_dx >> 8);
	if ((uint16_t)(((uint32_t)a << 8) | (uint8_t)target_dx) >= 0x100u)
	{
		carry = 0u;
		chance = (uint32_t)a << 8;
	}
	else
	{
		target_dy = OBJECT(object)->target_dy;
		a = (uint8_t)(target_dy >> 8);
		if ((uint16_t)(((uint32_t)a << 8) | (uint8_t)target_dy) >= 0x100u)
		{
			carry = 0u;
			chance = (uint32_t)a << 8;
		}
		else
		{
			a = 4u;
			for (;;)
			{
				t1 = (uint8_t)OBJECT(object)->target_dy;
				if (mem_read8(range) < t1)
				{
					carry = 0u;
					chance = (uint32_t)a << 8;
					break;
				}
				t2 = (uint8_t)OBJECT(object)->target_dx;
				x_distance = t2;
				t3 = mem_read8(range + 1u);
				if (t3 <= x_distance)
				{
					t4 = mem_read8(range + 2u);
					if (x_distance <= t4)
					{
						carry = 1u;
						t5 = mem_read8(range + 3u);
						chance = ((uint32_t)t5 << 8) | (uint8_t)~x_distance;
						break;
					}
				}
				range += 0xCu;
				t6 = a;
				a = t6 - 1u;
				if (t6 == 1u)
				{
					carry = 0u;
					chance = (uint32_t)a << 8;
					break;
				}
			}
		}
	}
	*p_range = range;
	*p_chance = chance;
	*p_carry = carry;
}
