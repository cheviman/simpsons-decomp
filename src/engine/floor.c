/**
 *    Name:        engine/floor.c
 *    Description: the floor map (work RAM 4000): the cell under an object or where its speeds take it
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* The floor map's cell at the object's place moved A pixels across and B on the floor: bits 0-3 the
   floor's height in steps of 8, bits 4-5 the sprites' priority there, bit 7 no floor. */
void floor_at_offset(uint16_t object, uint16_t *p_offsets, uint32_t *p_negative)
{
	uint16_t offsets = (uint16_t)*p_offsets;
	uint32_t negative = *p_negative;
	uint16_t d = 0, ignored16 = 0;

	floor_offset_x_pixels = offsets >> 8;
	floor_offset_x_fraction = 0u;
	floor_offset_y_pixels = (uint8_t)offsets;
	floor_offset_y_fraction = 0u;
	*p_offsets = d;
	floor_cell_at(object, &ignored16, p_offsets, &negative);
	*p_negative = negative;
}

/* The floor map's cell where the object's x speed takes it next. */
void floor_ahead_x(uint16_t object, uint16_t *p_cell, uint32_t *p_negative)
{
	uint32_t negative = *p_negative;
	uint16_t cell = 0, ignored16 = 0;
	uint16_t x_speed = 0;

	x_speed = OBJECT(object)->x_speed;
	floor_offset_x = x_speed;
	floor_offset_y = 0;
	*p_cell = cell;
	floor_cell_at(object, &ignored16, p_cell, &negative);
	*p_negative = negative;
}

/* The floor map's cell where the object's y speed takes it next. */
void floor_ahead_y(uint16_t object, uint16_t *p_cell, uint32_t *p_negative)
{
	uint32_t negative = *p_negative;
	uint16_t cell = 0, ignored16 = 0;
	uint16_t y_speed = 0;

	floor_offset_x = 0;
	y_speed = OBJECT(object)->y_speed;
	floor_offset_y = y_speed;
	*p_cell = cell;
	floor_cell_at(object, &ignored16, p_cell, &negative);
	*p_negative = negative;
}

/* The floor map's cell where the object's x and y speeds take it next. */
void floor_ahead(uint16_t object, uint16_t *p_cell, uint32_t *p_negative)
{
	uint32_t negative = *p_negative;
	uint16_t cell = 0, ignored16 = 0;
	uint16_t x_speed = 0, y_speed = 0;

	x_speed = OBJECT(object)->x_speed;
	floor_offset_x = x_speed;
	y_speed = OBJECT(object)->y_speed;
	floor_offset_y = y_speed;
	*p_cell = cell;
	floor_cell_at(object, &ignored16, p_cell, &negative);
	*p_negative = negative;
}

/* The floor map's cell (work RAM 4000: 40 cells of 8 pixels a row) at the object's place moved by the
   8.8 offsets at 48E9 (across) and 48ED (on the floor): its address in U, its value in A (negative: no
   floor). */
void floor_cell_at(uint16_t object, uint16_t *p_cell_address, uint16_t *p_cell, uint32_t *p_negative)
{
	uint32_t negative = *p_negative;
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t cell = 0, cell_address = 0;
	uint8_t t4 = 0, t10 = 0, t13 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t11 = 0, t12 = 0;

	floor_offset_x_sign = 0u;
	t1 = floor_offset_x;
	a = (uint8_t)(t1 >> 8);
	b = (uint8_t)t1;
	if ((int16_t)t1 < 0)
		floor_offset_x_sign = ~floor_offset_x_sign;
	t2 = (((uint32_t)(OBJECT(object)->x & 0xFFu) << 8u) | OBJECT(object)->x_fraction);
	t3 = ((uint32_t)a << 8) | b;
	carry = (uint16_t)(t3 + t2) < t3;
	t4 = (uint8_t)(OBJECT(object)->x >> 8u);
	t5 = (((uint32_t)(uint8_t)(t4 + floor_offset_x_sign + carry) << 8) | ((uint16_t)(t3 + t2) >> 8)) + camera_x;
	t6 = t5 - 0x40u;
	carry = (t6 >> 8) & 1u;
	floor_offset_x_sign = 0u;
	floor_cell_column_low = ((uint8_t)(((uint8_t)t6 >> 1) | (carry << 7)) >> 1) >> 1;
	floor_offset_y_sign = 0u;
	t7 = floor_offset_y;
	a = (uint8_t)(t7 >> 8);
	b = (uint8_t)t7;
	if ((int16_t)t7 < 0)
		floor_offset_y_sign = ~floor_offset_y_sign;
	t8 = (((uint32_t)(OBJECT(object)->y & 0xFFu) << 8u) | OBJECT(object)->y_fraction);
	t9 = ((uint32_t)a << 8) | b;
	carry = (uint16_t)(t9 + t8) < t9;
	t10 = (uint8_t)(OBJECT(object)->y >> 8u);
	a = t10 + floor_offset_y_sign + carry;
	floor_place_y = ((uint32_t)a << 8) | ((uint16_t)(t9 + t8) >> 8);
	t11 = 0x40u * ((((uint8_t)((((uint32_t)a << 8) | (uint8_t)((((uint32_t)a << 8) | 0x70u) - floor_place_y)) + camera_y) >> 1) >> 1) >> 1);
	t12 = t11 + floor_cell_column;
	b = (uint8_t)t12;
	cell_address = floor_map_ADDRESS + (((uint32_t)(t12 >> 8) << 8) | b);
	t13 = mem_read8(cell_address);
	negative = t13 >> 7;
	cell = ((uint32_t)t13 << 8) | b;
	*p_cell_address = cell_address;
	*p_cell = cell;
	*p_negative = negative;
}

/* Unused: on a floor, takes the floor cell's sprite priority under the object and marks it active. */
void unused_take_floor_priority(uint16_t x)
{
	uint32_t negative = 0;
	uint8_t floor_cell = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	d = 0u;
	floor_at_offset(x, &d, &negative);
	floor_cell = (uint8_t)(d >> 8);
	if ((int8_t)floor_cell >= 0)
	{
		floor_priority_bits = floor_cell & 0x30u;
		t1 = mem_read8(x + 9u);
		mem_write8(x + 9u, (t1 & 0xCFu) | floor_priority_bits);
		mem_write8(x, 0xC0u);
	}
}

/* Sets the object's speed up to jump onto a floor the given level (in steps of 8 pixels) by how many
   steps it is above the one it is on (climb_speeds). */
uint16_t set_climb_speed(uint16_t object, uint16_t target_level)
{
	uint16_t u = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	u = climb_speeds_ADDRESS;
	t1 = (uint8_t)OBJECT(object)->floor_z;
	stack = ((t1 >> 1) >> 1) >> 1;
	t2 = (uint32_t)climb_speeds[(int8_t)((uint8_t)((target_level >> 8) - stack))] << 4;
	OBJECT(object)->z_speed = t2;
	return u;
}

/* Reads the floor map under the object (its cell, its floor's height, its priority) and, while it moves,
   where its speeds take it: on another floor or no floor there, checks the way ahead. */
uint16_t check_floor(uint16_t object, uint16_t object_2)
{
	uint32_t negative = 0;
	uint8_t floor_cell = 0;
	uint16_t cell = 0, d = 0;
	uint8_t blocked = 0, blocked_2 = 0, attributes = 0, blocked_3 = 0, next_floor_cell = 0;
	uint16_t z = 0, floor_z = 0, x_speed = 0, y_speed = 0;

	blocked = OBJECT(object)->blocked;
	OBJECT(object)->blocked = blocked & 0x10u;
	z = OBJECT(object)->z;
	floor_z = OBJECT(object)->floor_z;
	if (z != floor_z)
	{
		blocked_2 = OBJECT(object)->blocked;
		OBJECT(object)->blocked = blocked_2 | 0x40u;
		OBJECT(object)->flags |= 8u;
	}
	d = 0u;
	floor_at_offset(object, &d, &negative);
	floor_cell = (uint8_t)(d >> 8);
	floor_cell_here = floor_cell;
	OBJECT(object)->floor_cell = floor_cell;
	OBJECT(object)->floor_z = (OBJECT(object)->floor_z & 0xFF00u) | ((((floor_cell & 0xFu) << 1) << 1) << 1 & 0xFFu);
	floor_cell_probe = floor_cell_here & 0x30u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | floor_cell_probe;
	x_speed = OBJECT(object)->x_speed;
	if (x_speed != 0u)
	{
		floor_ahead(object, &cell, &negative);
		floor_cell = (uint8_t)(cell >> 8);
		floor_cell_ahead = floor_cell;
		OBJECT(object)->next_floor_cell = floor_cell;
		if (floor_cell != floor_cell_here)
			return check_floor_ahead(object, object_2);
		blocked_3 = OBJECT(object)->blocked;
		OBJECT(object)->blocked = blocked_3 & 0xEFu;
		return object_2;
	}
	y_speed = OBJECT(object)->y_speed;
	if (y_speed == 0u)
	{
		next_floor_cell = OBJECT(object)->next_floor_cell;
		floor_cell_ahead = next_floor_cell;
		return check_floor_ahead(object, object_2);
	}
	floor_ahead(object, &cell, &negative);
	floor_cell = (uint8_t)(cell >> 8);
	floor_cell_ahead = floor_cell;
	OBJECT(object)->next_floor_cell = floor_cell;
	if (floor_cell != floor_cell_here)
		return check_floor_ahead(object, object_2);
	blocked_3 = OBJECT(object)->blocked;
	OBJECT(object)->blocked = blocked_3 & 0xEFu;
	return object_2;
}

/* Checks the floor where the object is going: before a step it notes the step's level and the way it met
   it (front, back, left, right) and stops, and notes whether its target is beyond it; before a gap or a
   wall it stops (sliding along one way first when it was already looking for a way round). */
uint16_t check_floor_ahead(uint16_t object, uint16_t object_2)
{
	uint32_t zero = 0, negative = 0;
	uint8_t blocked = 0, floor_cell = 0;
	uint16_t cell = 0;
	uint8_t x_speed = 0, enemy_class = 0, state = 0, action = 0, y_speed_2 = 0, blocked_2 = 0, blocked_3 = 0, blocked_4 = 0, blocked_5 = 0, step_level = 0;
	uint16_t x_speed_2 = 0, y_speed = 0, target = 0, floor_z = 0, floor_z_2 = 0, t1 = 0, z = 0;

	if ((int8_t)floor_cell_ahead >= 0)
	{
		floor_ahead_y(object, &cell, &negative);
		floor_cell = (uint8_t)(cell >> 8);
		floor_cell_probe = floor_cell;
		if (((floor_cell ^ floor_cell_here) & 0xFu) == 0u)
		{
			floor_ahead_x(object, &cell, &negative);
			floor_cell = (uint8_t)(cell >> 8);
			floor_cell_probe = floor_cell;
			if (((floor_cell ^ floor_cell_here) & 0xFu) != 0u)
			{
				OBJECT(object)->enemy.step_level = floor_cell_probe & 0xFu;
				x_speed = (uint8_t)(OBJECT(object)->x_speed >> 8u);
				if ((int8_t)x_speed >= 0)
					blocked = 0x83u;
				else
					blocked = 0x82u;
			}
			else
			{
				if (((floor_cell_ahead ^ floor_cell_here) & 0xFu) == 0u)
				{
					enemy_class = OBJECT(object)->enemy_class;
					zero = enemy_class == 0u;
					if ((int8_t)enemy_class >= 0 && zero == 0u)
					{
						state = OBJECT(object)->state;
						action = OBJECT(object)->action;
					}
					return object_2;
				}
				x_speed_2 = OBJECT(object)->x_speed;
				if (x_speed_2 == 0u)
				{
					y_speed = OBJECT(object)->y_speed;
					if (y_speed == 0u)
					{
						enemy_class = OBJECT(object)->enemy_class;
						zero = enemy_class == 0u;
						if ((int8_t)enemy_class >= 0 && zero == 0u)
						{
							state = OBJECT(object)->state;
							action = OBJECT(object)->action;
						}
						return object_2;
					}
				}
				floor_cell = floor_cell_ahead;
				OBJECT(object)->enemy.step_level = floor_cell & 0xFu;
				y_speed_2 = (uint8_t)(OBJECT(object)->y_speed >> 8u);
				if ((int8_t)y_speed_2 >= 0)
					blocked = 0x81u;
				else
					blocked = 0x80u;
			}
		}
		else
		{
			floor_cell = floor_cell_probe;
			OBJECT(object)->enemy.step_level = floor_cell & 0xFu;
			y_speed_2 = (uint8_t)(OBJECT(object)->y_speed >> 8u);
			if ((int8_t)y_speed_2 >= 0)
				blocked = 0x81u;
			else
				blocked = 0x80u;
		}
	}
	else
	{
		blocked_2 = OBJECT(object)->blocked;
		floor_cell = blocked_2;
		if ((floor_cell & 0x10u) == 0u)
		{
			OBJECT(object)->blocked = floor_cell | 0x88u;
			OBJECT(object)->x_speed = 0;
			OBJECT(object)->y_speed = 0;
			return object_2;
		}
		floor_ahead_x(object, &cell, &negative);
		floor_cell = (uint8_t)(cell >> 8);
		floor_cell_probe = floor_cell;
		if ((int8_t)floor_cell < 0)
		{
			floor_ahead_y(object, &cell, &negative);
			floor_cell = (uint8_t)(cell >> 8);
			floor_cell_probe = floor_cell;
			if ((int8_t)floor_cell < 0)
			{
				OBJECT(object)->blocked = floor_cell | 0x88u;
				OBJECT(object)->x_speed = 0;
				OBJECT(object)->y_speed = 0;
				return object_2;
			}
			OBJECT(object)->x_speed = 0;
			floor_cell_ahead = floor_cell;
			if (((floor_cell ^ floor_cell_here) & 0xFu) == 0u)
			{
				enemy_class = OBJECT(object)->enemy_class;
				zero = enemy_class == 0u;
				if ((int8_t)enemy_class >= 0 && zero == 0u)
				{
					state = OBJECT(object)->state;
					action = OBJECT(object)->action;
				}
				return object_2;
			}
			floor_cell = floor_cell_probe;
			OBJECT(object)->enemy.step_level = floor_cell & 0xFu;
			y_speed_2 = (uint8_t)(OBJECT(object)->y_speed >> 8u);
			if ((int8_t)y_speed_2 >= 0)
				blocked = 0x81u;
			else
				blocked = 0x80u;
		}
		else
		{
			OBJECT(object)->y_speed = 0;
			floor_cell_ahead = floor_cell;
			if (((floor_cell ^ floor_cell_here) & 0xFu) == 0u)
			{
				enemy_class = OBJECT(object)->enemy_class;
				zero = enemy_class == 0u;
				if ((int8_t)enemy_class >= 0 && zero == 0u)
				{
					state = OBJECT(object)->state;
					action = OBJECT(object)->action;
				}
				return object_2;
			}
			OBJECT(object)->enemy.step_level = floor_cell_probe & 0xFu;
			x_speed = (uint8_t)(OBJECT(object)->x_speed >> 8u);
			if ((int8_t)x_speed >= 0)
				blocked = 0x83u;
			else
				blocked = 0x82u;
		}
	}
	blocked_3 = OBJECT(object)->blocked;
	blocked |= blocked_3;
	OBJECT(object)->blocked = blocked;
	if ((blocked & 0x40u) == 0u)
	{
		target = OBJECT(object)->target;
		object_2 = target;
		floor_z = OBJECT(object_2)->floor_z;
		floor_z_2 = OBJECT(object)->floor_z;
		if (floor_z != floor_z_2)
		{
			OBJECT(object)->x_speed = 0;
			OBJECT(object)->y_speed = 0;
			blocked_4 = OBJECT(object)->blocked;
			OBJECT(object)->blocked = blocked_4 | 0x20u;
			enemy_class = OBJECT(object)->enemy_class;
			zero = enemy_class == 0u;
			if ((int8_t)enemy_class >= 0 && zero == 0u)
			{
				state = OBJECT(object)->state;
				action = OBJECT(object)->action;
			}
			return object_2;
		}
		blocked_5 = OBJECT(object)->blocked;
		blocked = blocked_5;
		if ((blocked & 0x10u) != 0u)
		{
			blocked |= 0x20u;
			OBJECT(object)->blocked = blocked;
		}
		OBJECT(object)->blocked = blocked | 0x10u;
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0;
		enemy_class = OBJECT(object)->enemy_class;
		zero = enemy_class == 0u;
		if ((int8_t)enemy_class >= 0 && zero == 0u)
		{
			state = OBJECT(object)->state;
			action = OBJECT(object)->action;
		}
		return object_2;
	}
	OBJECT(object)->blocked = blocked & 0xEFu;
	step_level = OBJECT(object)->enemy.step_level;
	t1 = (uint32_t)step_level << 3;
	z = OBJECT(object)->z;
	if (z <= t1)
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0;
		enemy_class = OBJECT(object)->enemy_class;
		zero = enemy_class == 0u;
		if ((int8_t)enemy_class >= 0 && zero == 0u)
		{
			state = OBJECT(object)->state;
			action = OBJECT(object)->action;
		}
		return object_2;
	}
	enemy_class = OBJECT(object)->enemy_class;
	zero = enemy_class == 0u;
	if ((int8_t)enemy_class >= 0 && zero == 0u)
	{
		state = OBJECT(object)->state;
		action = OBJECT(object)->action;
	}
	return object_2;
}

/* When the floor check stopped the enemy on the ground at a step it means to take (its target is on
   another floor, or it met the step twice): starts climbing it (state 5), up when the step is higher
   than its floor, hopping down otherwise, the way it met it. */
void enemy_start_climbing(uint16_t object)
{
	uint8_t blocked_bits = 0;
	uint8_t blocked = 0, blocked_2 = 0, step_level = 0, blocked_3 = 0, blocked_4 = 0;
	uint16_t t1 = 0, floor_z = 0;

	blocked = OBJECT(object)->blocked;
	if ((blocked & 0x40u) == 0u)
	{
		blocked_2 = OBJECT(object)->blocked;
		blocked_bits = blocked_2;
		if ((int8_t)blocked_2 < 0 && (blocked_bits & 8u) == 0u && (blocked_bits & 0x20u) != 0u)
		{
			step_level = OBJECT(object)->enemy.step_level;
			t1 = (uint32_t)step_level << 3;
			floor_z = OBJECT(object)->floor_z;
			if (t1 <= floor_z)
			{
				blocked_3 = OBJECT(object)->blocked;
				OBJECT(object)->blocked = blocked_3 | 4u;
			}
			blocked_4 = OBJECT(object)->blocked;
			OBJECT(object)->action = blocked_4 & 7u;
			OBJECT(object)->action_step = 0u;
			OBJECT(object)->state = 5u;
		}
	}
}
