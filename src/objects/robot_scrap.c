/**
 *    Name:        objects/robot_scrap.c
 *    Description: what the beaten robot leaves on the floor (5280 type F5)
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    10-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* While the scrap flies (step 5), sends it into its burst (step FF) when it hits something. */
void robot_scrap_check_hit(uint16_t object)
{
	uint8_t state = 0;

	state = OBJECT(object)->state;
	if (state == 5u && (OBJECT(object)->flags & 0x20u) != 0u)
	{
		OBJECT(object)->state = 0xFFu;
		OBJECT(object)->action = 0u;
	}
}

/* The scrap's burst (steps FE, FF), by field 28. */
uint16_t robot_scrap_burst(uint16_t object)
{
	uint16_t action_handlers = 0;
	uint8_t action = 0;

	for (;;)
	{
		action_handlers = 0x7AFCu;
		action = OBJECT(object)->action;
		switch ((int8_t)(uint8_t)((uint32_t)action << 1))
		{
		case 0:
			robot_scrap_burst_start(object);
			return action_handlers;
		case 2:
			break;
		case -20:
		case -18:
			continue;
		case -16:
			return robot_scrap_setup(object);
		case -14:
		case -12:
			robot_scrap_lie();
			return action_handlers;
		case -10:
			robot_scrap_pick_up(object);
			return action_handlers;
		case -8:
			robot_scrap_throw(object);
			return action_handlers;
		case -6:
			robot_scrap_fly(object);
			return action_handlers;
		case -4:
			robot_scrap_drop(object);
			return action_handlers;
		case -2:
			robot_scrap_drop_land(object);
			return action_handlers;
		}
		break;
	}
	robot_scrap_remove(object);
	return action_handlers;
}

/* Stops the scrap, pops it up a little and plays its burst. */
void robot_scrap_burst_start(uint16_t object)
{
	uint8_t action = 0;

	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->z_speed = 0x80;
	OBJECT(object)->animation = 0x80u;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* Frees the scrap's slot when its burst ends. */
void robot_scrap_remove(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
		OBJECT(object)->flags = 0u;
}

/* Sets the scrap up with its animation from its state, held where it lies (field 31). */
uint16_t robot_scrap_setup(uint16_t object)
{
	uint16_t setup = 0;
	uint8_t parameter = 0, lying = 0, state = 0;

	setup = robot_piece_object_setup_ADDRESS;
	vector_object_setup(object, setup);
	parameter = OBJECT(object)->parameter;
	OBJECT(object)->animation = parameter | 0x80u;
	lying = OBJECT(object)->robot_scrap.lying;
	OBJECT(object)->robot_scrap.lying = lying + 1u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return setup;
}

/* The scrap lying or carried: nothing to do here. */
void robot_scrap_lie(void)
{
}

/* Marks the scrap carried by its holder (field 3D), unhittable. */
void robot_scrap_pick_up(uint16_t object)
{
	uint8_t state = 0;

	OBJECT(object)->robot_scrap.lying = 0u;
	OBJECT(object)->robot_scrap.carried = 1u;
	OBJECT(object)->flags = 0x80u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state - 1u;
}

/* Lets the thrown scrap fly with its hit box, facing the way it goes. */
void robot_scrap_throw(uint16_t object)
{
	uint8_t animation = 0, state = 0;

	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->robot_scrap.carried = 0u;
	animation = OBJECT(object)->animation;
	OBJECT(object)->animation = (animation + 1u) | 0x80u;
	leftover_y = robot_scrap_throw_box_ADDRESS;
	vector_set_hit_box(object);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	face_movement(object);
	robot_scrap_fly(object);
}

/* The scrap flying: nothing to do, it moves by its speed. */
void robot_scrap_fly(uint16_t object)
{
	check_hits_with_enemies(object);
}

/* Pops the dropped scrap up toward the floor under it. */
void robot_scrap_drop(uint16_t object)
{
	uint32_t negative = 0;
	uint8_t floor_value = 0;
	uint16_t floor_cell = 0;
	uint8_t animation = 0, state = 0;

	OBJECT(object)->flags = 0x88u;
	OBJECT(object)->z_speed = 0x800;
	floor_cell = 0u;
	vector_floor_at_offset(object, &floor_cell, &negative);
	floor_value = (uint8_t)(floor_cell >> 8);
	OBJECT(object)->floor_z = (OBJECT(object)->floor_z & 0xFF00u) | ((((floor_value & 0xFu) << 1) << 1) << 1 & 0xFFu);
	animation = OBJECT(object)->animation;
	OBJECT(object)->animation = (animation + 1u) | 0x80u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Pulls the dropped scrap down; it bursts when it lands. */
void robot_scrap_drop_land(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	if (carry)
	{
		OBJECT(object)->state = 0xFFu;
		OBJECT(object)->action = 0u;
	}
}

/* Keeps the scrap on the floor under it (or with its holder's priority while carried); off any floor, or
   under a higher one, it bursts. */
uint16_t robot_scrap_keep_on_floor(uint16_t object, uint16_t states)
{
	uint32_t negative = 0;
	uint8_t flags = 0, floor_value = 0, value_ahead = 0;
	uint16_t floor_cell = 0, object_2 = 0;
	uint8_t lying = 0, carried = 0, attributes = 0, attributes_2 = 0, attributes_3 = 0;
	uint16_t parent = 0, z = 0, floor_z = 0, height_ahead = 0, z_2 = 0;

	lying = OBJECT(object)->robot_scrap.lying;
	if (lying != 0u)
		return states;
	carried = OBJECT(object)->robot_scrap.carried;
	if (carried != 0u)
	{
		parent = OBJECT(object)->parent;
		object_2 = parent;
		attributes = OBJECT(object_2)->attributes;
		thrown_cell_here = attributes & 0x30u;
		attributes_2 = OBJECT(object)->attributes;
		OBJECT(object)->attributes = (attributes_2 & 0xCFu) | thrown_cell_here;
		return object_2;
	}
	floor_cell = 0u;
	vector_floor_at_offset(object, &floor_cell, &negative);
	floor_value = (uint8_t)(floor_cell >> 8);
	thrown_cell_here = floor_value;
	if ((int8_t)floor_value < 0)
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0;
		OBJECT(object)->state = 0xFEu;
		return states;
	}
	OBJECT(object)->floor_z = (OBJECT(object)->floor_z & 0xFF00u) | ((((floor_value & 0xFu) << 1) << 1) << 1 & 0xFFu);
	z = OBJECT(object)->z;
	floor_z = OBJECT(object)->floor_z;
	if (z != floor_z)
		flags = OBJECT(object)->flags | 8u;
	else
		flags = OBJECT(object)->flags & ~8u;
	OBJECT(object)->flags = flags;
	vector_floor_ahead(object, &floor_cell, &negative);
	value_ahead = (uint8_t)(floor_cell >> 8);
	thrown_cell_ahead = value_ahead;
	if (value_ahead == thrown_cell_here)
		return states;
	if ((int8_t)value_ahead >= 0)
	{
		height_ahead = (thrown_cell_ahead & 0xFu) << 3;
		z_2 = OBJECT(object)->z;
		if (height_ahead < z_2)
		{
			thrown_cell_priority = thrown_cell_ahead & 0x30u;
			attributes_3 = OBJECT(object)->attributes;
			OBJECT(object)->attributes = (attributes_3 & 0xCFu) | thrown_cell_priority;
			return states;
		}
	}
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->state = 0xFEu;
	return states;
}
