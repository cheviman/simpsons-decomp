/**
 *    Name:        objects/kind_a0.c
 *    Description: the small kind A0 creature that comes in or is launched from the shaking scenery
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Sets the creature up by its spawn's state: coming in, sitting still, or hidden on the shaking scenery. */
void kind_a0_start(uint16_t object, uint16_t *p_box, uint16_t *p_kind_a0_entry)
{
	uint8_t parameter_low = 0, spawn_parameter = 0;
	uint16_t box = 0, kind_a0_entry = 0;
	uint8_t attributes = 0, parameter = 0, parameter_2 = 0, frames = 0, state = 0, t2 = 0;
	uint16_t z_speed = 0, x_speed = 0, t1 = 0;

	kind_a0_entry = kind_a0_setup_ADDRESS;
	box = vector_object_setup(object, kind_a0_entry);
	OBJECT(object)->shadow_player = 2u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0x10u;
	parameter = OBJECT(object)->parameter;
	spawn_parameter = parameter;
	if ((int8_t)parameter >= 0)
	{
		OBJECT(object)->flags = 0x88u;
		parameter_2 = OBJECT(object)->parameter;
		kind_a0_entry = kind_a0_entries_ADDRESS + (int8_t)((((uint32_t)parameter_2 << 1) << 1) << 1);
		z_speed = KIND_A0_ENTRY(kind_a0_entry)->z_speed;
		OBJECT(object)->z_speed = z_speed;
		x_speed = KIND_A0_ENTRY(kind_a0_entry)->x_speed;
		OBJECT(object)->x_speed = x_speed;
		t1 = KIND_A0_ENTRY(kind_a0_entry)->x;
		OBJECT(object)->x = t1;
		frames = KIND_A0_ENTRY(kind_a0_entry)->frames;
		OBJECT(object)->timer = frames;
		kind_a0_take_floor(object);
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
		face_movement(object);
	}
	else
	{
		t2 = spawn_parameter & 0x7Fu;
		parameter_low = t2;
		if (t2 == 0u)
		{
			OBJECT(object)->animation = 0x83u;
			OBJECT(object)->state = 3u;
		}
		else
		{
			OBJECT(object)->parameter = parameter_low - 1u;
			OBJECT(object)->flags = 4u;
			OBJECT(object)->animation = 0x82u;
			OBJECT(object)->state = 8u;
		}
	}
	*p_box = box;
	*p_kind_a0_entry = kind_a0_entry;
}

/* Moves in for its frames, then stops moving across. */
void kind_a0_enter(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
	{
		kind_a0_take_floor(object);
		return;
	}
	OBJECT(object)->x_speed = 0;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	kind_a0_take_floor(object);
}

/* Takes the height of the floor under it. */
void kind_a0_take_floor(uint16_t object)
{
	uint32_t negative = 0;
	uint8_t floor_value = 0;
	uint16_t floor_cell = 0;

	floor_cell = 0u;
	vector_floor_at_offset(object, &floor_cell, &negative);
	floor_value = (uint8_t)(floor_cell >> 8);
	if (negative == 0u)
		OBJECT(object)->floor_z = (OBJECT(object)->floor_z & 0xFF00u) | ((((floor_value & 0xFu) << 1) << 1) << 1 & 0xFFu);
}

/* Falls and, on landing, sits. */
void kind_a0_land(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t z_speed = 0, t1 = 0;

	z_speed = OBJECT(object)->z_speed;
	t1 = z_speed - 0x20u;
	OBJECT(object)->z_speed = t1;
	carry = vector_check_landing(object);
	if (carry)
	{
		OBJECT(object)->animation = 0x81u;
		OBJECT(object)->flags = 0xC0u;
		OBJECT(object)->timer = 0x80u;
		OBJECT(object)->state = 4u;
	}
}

/* Sits, looking round, until it is hit; then jumps. */
void kind_a0_sit(uint16_t object)
{
	uint8_t animation = 0, attributes = 0;
	uint16_t t1 = 0;

	if ((OBJECT(object)->flags & 0x20u) == 0u)
	{
		t1 = OBJECT(object)->x;
		if (t1 >= 0xE0u)
		{
			if ((frame_count & 0x3Fu) == 0u)
			{
				animation = OBJECT(object)->animation;
				OBJECT(object)->animation = (animation ^ 2u) | 0x80u;
				attributes = OBJECT(object)->attributes;
				OBJECT(object)->attributes = attributes ^ 0x40u;
			}
			return;
		}
	}
	OBJECT(object)->floor_z = 0u;
	OBJECT(object)->flags = 0x88u;
	OBJECT(object)->animation = 0x82u;
	OBJECT(object)->z_speed = 0x200;
	OBJECT(object)->timer = 0x10u;
	OBJECT(object)->state = 5u;
}

/* Sits for its time, or until hit, then jumps. */
void kind_a0_sit_for_time(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	if ((OBJECT(object)->flags & 0x20u) == 0u)
	{
		timer = OBJECT(object)->timer;
		OBJECT(object)->timer = timer - 1u;
		if (timer == 1u)
		{
			OBJECT(object)->flags = 0x88u;
			OBJECT(object)->animation = 0x82u;
			OBJECT(object)->z_speed = 0x200;
			OBJECT(object)->timer = 0x10u;
			state = OBJECT(object)->state;
			OBJECT(object)->state = state + 1u;
		}
		return;
	}
	OBJECT(object)->flags = 0x88u;
	OBJECT(object)->animation = 0x82u;
	OBJECT(object)->z_speed = 0x200;
	OBJECT(object)->timer = 0x10u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* After its jump's 16 frames, levels off. */
void kind_a0_jump(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->z_speed = 0;
		OBJECT(object)->timer = 0x20u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* After 32 frames runs off to the right with a hop. */
void kind_a0_run_off(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->x_speed = 0x100;
	OBJECT(object)->z_speed = 0x80;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	face_movement(object);
}

/* Runs faster each frame up to 0200. */
void kind_a0_speed_up(uint16_t object)
{
	uint16_t x_speed = 0;
	uint16_t x_speed_2 = 0;

	x_speed_2 = OBJECT(object)->x_speed;
	x_speed = x_speed_2 + 8u;
	if (x_speed >= 0x200u)
	{
		kind_a0_take_floor(object);
		return;
	}
	OBJECT(object)->x_speed = x_speed;
	kind_a0_take_floor(object);
}

/* Waits hidden until the shaking scenery comes left of x 0160, then is launched by its state. */
uint16_t kind_a0_wait_launch(uint16_t object)
{
	uint16_t kind_a0_launch = 0, scenery = 0;
	uint8_t parameter = 0, parameter_2 = 0, state = 0;
	uint16_t parent = 0, t1 = 0, x_speed = 0, y_speed = 0, z_speed = 0, parent_x = 0;

	parent = OBJECT(object)->parent;
	scenery = parent;
	t1 = OBJECT(scenery)->x;
	if (t1 >= 0x160u)
		return scenery;
	OBJECT(object)->flags = 0x88u;
	parameter = OBJECT(object)->parameter;
	kind_a0_launch = kind_a0_launches_ADDRESS + (int8_t)((((uint32_t)parameter << 1) << 1) << 1);
	x_speed = KIND_A0_LAUNCH(kind_a0_launch)->x_speed;
	OBJECT(object)->x_speed = x_speed;
	y_speed = KIND_A0_LAUNCH(kind_a0_launch)->y_speed;
	OBJECT(object)->y_speed = y_speed;
	z_speed = KIND_A0_LAUNCH(kind_a0_launch)->z_speed;
	OBJECT(object)->z_speed = z_speed;
	parent_x = KIND_A0_LAUNCH(kind_a0_launch)->parent_x;
	OBJECT(object)->kind_a0.parent_x = parent_x;
	parameter_2 = OBJECT(object)->parameter;
	if (parameter_2 == 2u)
	{
		OBJECT(object)->animation = 0x84u;
		OBJECT(object)->zoom_x = 0x10u;
		OBJECT(object)->zoom_y = 0x10u;
	}
	OBJECT(object)->timer = 0x40u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	face_movement(object);
	return kind_a0_launch;
}

/* Flies out of the scenery (the third growing as it comes out), then lands on it, setting it shaking
   from above. */
uint16_t kind_a0_launch_fly(uint16_t object, uint16_t states)
{
	uint8_t a = 0;
	uint16_t scenery = 0;
	uint8_t timer = 0, parameter = 0, state = 0, parameter_2 = 0, timer_2 = 0;
	uint16_t parent = 0, zoom_x = 0, t1 = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0;
		OBJECT(object)->z_speed = 0;
		OBJECT(object)->flags = 0xC0u;
		parent = OBJECT(object)->parent;
		scenery = parent;
		OBJECT(scenery)->state = 0xFDu;
		parameter = OBJECT(object)->parameter;
		if (parameter != 0u)
			OBJECT(object)->animation = 0x83u;
		else
			OBJECT(object)->animation = 0x81u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
		return scenery;
	}
	parameter_2 = OBJECT(object)->parameter;
	a = parameter_2;
	if (a != 2u)
	{
		if (a == 8u)
			OBJECT(object)->animation = 0x82u;
		return states;
	}
	OBJECT(object)->flags = 0x98u;
	timer_2 = OBJECT(object)->timer;
	a = timer_2;
	if (a >= 0x30u)
	{
		zoom_x = (((uint32_t)OBJECT(object)->zoom_x << 8u) | OBJECT(object)->zoom_y);
		t1 = zoom_x + 0x303u;
		OBJECT(object)->zoom_x = (uint8_t)(t1 >> 8u);
		OBJECT(object)->zoom_y = (uint8_t)t1;
		return states;
	}
	if (a == 8u)
		OBJECT(object)->animation = 0x82u;
	return states;
}

/* Sits on the scenery, looking round, until it stops shaking, is hit, or comes left of its x; then jumps
   off. */
uint16_t kind_a0_sit_on_scenery(uint16_t object)
{
	uint16_t scenery = 0;
	uint8_t parameter = 0, animation = 0, attributes = 0;
	uint16_t parent = 0, t1 = 0, parent_x = 0;

	parameter = OBJECT(object)->parameter;
	if (((random_number + parameter) & 0x3Fu) == 0u)
	{
		animation = OBJECT(object)->animation;
		OBJECT(object)->animation = (animation ^ 2u) | 0x80u;
		attributes = OBJECT(object)->attributes;
		OBJECT(object)->attributes = attributes ^ 0x40u;
	}
	parent = OBJECT(object)->parent;
	scenery = parent;
	if ((OBJECT(scenery)->flags & 0x40u) == 0u)
	{
		OBJECT(object)->flags = 0x88u;
		OBJECT(object)->animation = 0x82u;
		OBJECT(object)->z_speed = 0x200;
		OBJECT(object)->timer = 1u;
		OBJECT(object)->state = 6u;
		return scenery;
	}
	if ((OBJECT(object)->flags & 0x20u) == 0u)
	{
		t1 = OBJECT(scenery)->x;
		parent_x = OBJECT(object)->kind_a0.parent_x;
		if (parent_x <= t1)
			return scenery;
	}
	OBJECT(scenery)->state = 0xFDu;
	OBJECT(object)->flags = 0x88u;
	OBJECT(object)->animation = 0x82u;
	OBJECT(object)->z_speed = 0x200;
	OBJECT(object)->timer = 1u;
	OBJECT(object)->state = 6u;
	return scenery;
}
