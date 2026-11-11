/**
 *    Name:        enemies/enemy_targets.c
 *    Description: the nearest player, the direction and distance to it, the attack ranges, the random number
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    10-11-2026
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
	uint8_t players_counted = 0, slots_before = 0;
	uint16_t nearest_player = 0, enemy_x = 0, player_x = 0, dx = 0, enemy_y = 0, player_y = 0, dy = 0;

	players_counted = io_read8(0x1874u);
	if (players_counted == 0u)
	{
		nearest_player = io_read16(0x1872u);
		target = nearest_player;
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
			enemy_x = OBJECT(object)->x;
			player_x = OBJECT(object_2)->x;
			dx = enemy_x - player_x;
			distance = dx;
			if ((int16_t)dx < 0)
				distance = 0u - distance;
			stack_3 = distance;
			enemy_y = OBJECT(object)->y;
			player_y = OBJECT(object_2)->y;
			dy = enemy_y - player_y;
			distance = dy;
			if ((int16_t)dy < 0)
				distance = 0u - distance;
			distance += stack_3;
			if (distance < nearest_player_distance)
			{
				nearest_player_distance = distance;
				io_write16(0x1872u, object_2);
			}
		}
		object_2 += 0xC0u;
		slots_before = stack;
		stack = slots_before - 1u;
	} while (slots_before != 1u);
	nearest_player = io_read16(0x1872u);
	target = nearest_player;
	OBJECT(object)->target = target;
	return target;
}

/* A random number for the enemies' choices: the frame's random number added to the last one. */
uint16_t enemy_random(uint8_t d)
{
	uint8_t value = 0;
	uint16_t roll = 0;
	uint8_t last_roll = 0;

	last_roll = io_read8(0x189Eu);
	value = last_roll + random_number;
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
	uint16_t target_x = 0, enemy_x = 0, dx = 0, x_distance = 0, target_y = 0, enemy_y = 0, dy = 0, y_distance = 0, target_dx = 0, target_dy = 0, target_dx_2 = 0, target_dy_2 = 0, target_dy_3 = 0, target_dx_3 = 0;

	target_left_bit = 0u;
	OBJECT(object)->target_direction = 0u;
	target_x = OBJECT(target)->x;
	enemy_x = OBJECT(object)->x;
	dx = target_x - enemy_x;
	distance_low = (uint8_t)dx;
	distance_high = (uint8_t)(dx >> 8);
	if ((int16_t)dx >= 0)
		OBJECT(object)->target_dx = ((uint32_t)distance_high << 8) | (distance_low & 0xFFu);
	else
	{
		x_distance = 0u - (((uint32_t)distance_high << 8) | (distance_low & 0xFFu));
		OBJECT(object)->target_dx = x_distance;
		OBJECT(object)->target_direction = 0x40u;
		target_left_bit = 0x40u;
	}
	target_y = OBJECT(target)->y;
	enemy_y = OBJECT(object)->y;
	dy = target_y - enemy_y;
	distance_low = (uint8_t)dy;
	distance_high = (uint8_t)(dy >> 8);
	if ((int16_t)dy >= 0)
		OBJECT(object)->target_dy = ((uint32_t)distance_high << 8) | (distance_low & 0xFFu);
	else
	{
		y_distance = 0u - (((uint32_t)distance_high << 8) | (distance_low & 0xFFu));
		OBJECT(object)->target_dy = y_distance;
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
	uint8_t distance_high = 0, x_distance = 0;
	uint16_t chance = 0;
	uint8_t dy_low = 0, dx_low = 0, range_least_dx = 0, range_most_dx = 0, range_chance = 0, ranges_before = 0;
	uint16_t target_dx = 0, target_dy = 0;

	target_dx = OBJECT(object)->target_dx;
	distance_high = (uint8_t)(target_dx >> 8);
	if ((uint16_t)(((uint32_t)distance_high << 8) | (uint8_t)target_dx) >= 0x100u)
	{
		carry = 0u;
		chance = (uint32_t)distance_high << 8;
	}
	else
	{
		target_dy = OBJECT(object)->target_dy;
		distance_high = (uint8_t)(target_dy >> 8);
		if ((uint16_t)(((uint32_t)distance_high << 8) | (uint8_t)target_dy) >= 0x100u)
		{
			carry = 0u;
			chance = (uint32_t)distance_high << 8;
		}
		else
		{
			distance_high = 4u;
			for (;;)
			{
				dy_low = (uint8_t)OBJECT(object)->target_dy;
				if (ATTACK_RANGE(range)->most_dy < dy_low)
				{
					carry = 0u;
					chance = (uint32_t)distance_high << 8;
					break;
				}
				dx_low = (uint8_t)OBJECT(object)->target_dx;
				x_distance = dx_low;
				range_least_dx = ATTACK_RANGE(range)->least_dx;
				if (range_least_dx <= x_distance)
				{
					range_most_dx = ATTACK_RANGE(range)->most_dx;
					if (x_distance <= range_most_dx)
					{
						carry = 1u;
						range_chance = ATTACK_RANGE(range)->chance;
						chance = ((uint32_t)range_chance << 8) | (uint8_t)~x_distance;
						break;
					}
				}
				range += 0xCu;
				ranges_before = distance_high;
				distance_high = ranges_before - 1u;
				if (ranges_before == 1u)
				{
					carry = 0u;
					chance = (uint32_t)distance_high << 8;
					break;
				}
			}
		}
	}
	*p_range = range;
	*p_chance = chance;
	*p_carry = carry;
}
