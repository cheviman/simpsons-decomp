/**
 *    Name:        enemies/donut.c
 *    Description: stage 6's walking donut (type FD), its actions 3A and 3B and what it throws
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Sets the donut up with its behaviour donut_behaviour, turned to its player: with state bit 7 it stays
   hidden for its way in, otherwise it fights at once. */
uint16_t donut_setup(uint16_t object)
{
	uint16_t setup = 0, u = 0, y = 0;
	uint8_t parameter = 0, state = 0;

	setup = donut_object_setup_ADDRESS;
	y = vector_object_setup(object, setup);
	u = vector_choose_nearest_player(object);
	vector_measure_target(object, u);
	OBJECT(object)->donut.vanishes = 1u;
	OBJECT(object)->behaviour = 0x7DB6u;
	OBJECT(object)->retarget_time = 0x10u;
	parameter = OBJECT(object)->parameter;
	if ((int8_t)parameter >= 0)
	{
		OBJECT(object)->parameter = 0u;
		OBJECT(object)->state = 2u;
		return y;
	}
	OBJECT(object)->flags = 4u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return y;
}

/* The donut's way in, by field 29 (kind_b7_entrances gives where it starts). */
void donut_come_in(uint16_t object)
{
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		donut_choose_entrance(object);
		return;
	case 2:
		donut_fall_in_start(object);
		return;
	case 4:
		donut_fly_across(object);
		return;
	case 6:
		donut_fly_into_distance(object);
		return;
	case 8:
		donut_drop_down(object);
		return;
	case 10:
		donut_drop_slow(object);
		return;
	case 12:
		donut_land(object);
		return;
	case 14:
		donut_walk_in(object);
		return;
	case 16:
		donut_walk_in_end(object);
		return;
	}
}

/* Takes the donut's wait and the step its way in starts at from kind_b7_entrances. */
void donut_choose_entrance(uint16_t object)
{
	uint8_t parameter = 0;
	uint16_t wait = 0;

	parameter = OBJECT(object)->parameter;
	wait = (((uint32_t)TIMED_STEP(kind_b7_entrances_ADDRESS + (int8_t)((uint32_t)parameter << 1))->wait << 8u) | TIMED_STEP(kind_b7_entrances_ADDRESS + (int8_t)((uint32_t)parameter << 1))->step);
	OBJECT(object)->timer = wait >> 8;
	OBJECT(object)->action_step = wait;
	OBJECT(object)->parameter = 0u;
}

/* Places the donut, big (zoom 6060), at x 00E0 for its way in. */
void donut_fall_in_start(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->x = 0xE0u;
	OBJECT(object)->animation = 0x92u;
	OBJECT(object)->zoom_x = 0x60u;
	OBJECT(object)->zoom_y = 0x60u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Counts its wait down, then sends the donut flying across with a sound. */
void donut_fly_across(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t timer = 0, action_step = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->attributes = 0x10u;
	OBJECT(object)->flags = 0x90u;
	OBJECT(object)->x_speed = 0x400;
	OBJECT(object)->timer = 0x30u;
	command = 0x2600u;
	carry = vector_queue_sound(command);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Shrinks the donut as it rises away, then puts it high over the middle of the screen. */
void donut_fly_into_distance(uint16_t object)
{
	uint16_t zoom_x = 0;
	uint8_t timer = 0, action_step = 0;
	uint16_t z_speed = 0, zoom_x_2 = 0;

	z_speed = OBJECT(object)->z_speed;
	OBJECT(object)->z_speed = z_speed + 0x20u;
	zoom_x_2 = (((uint32_t)OBJECT(object)->zoom_x << 8u) | OBJECT(object)->zoom_y);
	zoom_x = zoom_x_2 - 0x101u;
	if (zoom_x >= 0x1010u)
	{
		OBJECT(object)->zoom_x = (uint8_t)(zoom_x >> 8u);
		OBJECT(object)->zoom_y = (uint8_t)zoom_x;
	}
	OBJECT(object)->flags = 0x90u;
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->x = 0x180u;
		OBJECT(object)->y = 0xA0u;
		OBJECT(object)->z = 0xC0u;
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->z_speed = 0;
		OBJECT(object)->timer = 1u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* Drops the donut down fast toward the middle of the screen. */
void donut_drop_down(uint16_t object)
{
	uint8_t timer = 0, action_step = 0;
	uint16_t t1 = 0, x_speed = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->flags = 0x88u;
	OBJECT(object)->floor_z = 0u;
	OBJECT(object)->animation = 0x84u;
	OBJECT(object)->z_speed = -0x600;
	OBJECT(object)->x_speed = 0x180;
	t1 = OBJECT(object)->x;
	if (t1 >= 0xE0u)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	OBJECT(object)->timer = 0x40u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	face_movement(object);
}

/* Slows the donut's drop, then plays its landing animation. */
void donut_drop_slow(uint16_t object)
{
	uint8_t timer = 0, action_step = 0;
	uint16_t z_speed = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
	{
		z_speed = OBJECT(object)->z_speed;
		OBJECT(object)->z_speed = z_speed + 0x20u;
		return;
	}
	OBJECT(object)->animation = 0x91u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Pulls the donut down until it lands, then lets it fight. */
void donut_land(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	if (carry)
	{
		OBJECT(object)->flags = 0xC0u;
		OBJECT(object)->state = 2u;
	}
}

/* Counts its wait down, then walks the donut in from the right for 64 frames. */
void donut_walk_in(uint16_t object)
{
	uint8_t timer = 0, action_step = 0;
	uint16_t t1 = 0, x_speed = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
	{
		face_movement(object);
		return;
	}
	OBJECT(object)->x = 0x180u;
	OBJECT(object)->flags = 0xC0u;
	OBJECT(object)->animation = 0x81u;
	OBJECT(object)->x_speed = 0x180;
	t1 = OBJECT(object)->x;
	if (t1 >= 0xE0u)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	OBJECT(object)->timer = 0x40u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	face_movement(object);
}

/* Counts the walk down and lets the donut fight. */
void donut_walk_in_end(uint16_t object)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
		OBJECT(object)->state = 2u;
}

/* Starts the donut's roll, turned to its player. */
void donut_roll_start(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->animation = 0x93u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	face_target(object);
}

/* When the wind-up ends, rolls the donut fast with its attacking hit box for 32 frames. */
uint16_t donut_roll_go(uint16_t object, uint16_t y)
{
	uint16_t box = 0;
	uint8_t animation_flags = 0, attributes = 0, action_step = 0;
	uint16_t x_speed = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return y;
	OBJECT(object)->animation = 0x94u;
	OBJECT(object)->x_speed = 0x300;
	attributes = OBJECT(object)->attributes;
	if ((attributes & 0x40u) != 0u)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	OBJECT(object)->timer = 0x20u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	box = donut_roll_go_box_ADDRESS;
	vector_set_hit_box(object, box);
	return box;
}

/* Counts the roll down, then stops the donut with its plain hit box and ends the action. */
uint16_t donut_roll_end(uint16_t object, uint16_t y)
{
	uint16_t box = 0;
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return y;
	OBJECT(object)->x_speed = 0;
	box = donut_body_box_ADDRESS;
	vector_set_hit_box(object, box);
	OBJECT(object)->state = 2u;
	OBJECT(object)->timer = 0u;
	return box;
}

/* Starts the donut's throw, turned to its player. */
void donut_throw_start(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->animation = 0x90u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	face_target(object);
}

/* On the marked frame, puts in the small donut (5280 type DE). */
void donut_throw_release(uint16_t object, uint16_t *p_y, uint16_t *p_u)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, record = 0, u_2 = 0;
	uint8_t animation_flags = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) == 0u)
	{
		donut_throw_end(object);
		return;
	}
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	record = donut_throw_release_child_ADDRESS;
	*p_u = u_2;
	vector_spawn_child(object, record, p_u, &ignored16, &carry);
	*p_y = record;
}

/* Ends the action when the throw ends. */
void donut_throw_end(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	OBJECT(object)->state = 2u;
	OBJECT(object)->timer = 0u;
}

/* Sets the thrown small donut up flying fast the way it faces, with a sound. */
void donut_shot_setup(uint16_t object, uint16_t *p_y, uint16_t *p_setup)
{
	uint32_t carry = 0;
	uint16_t command = 0, setup = 0, y = 0;
	uint8_t attributes = 0, state = 0;
	uint16_t x_speed = 0;

	setup = donut_shot_object_setup_ADDRESS;
	y = vector_object_setup(object, setup);
	OBJECT(object)->flags = 0xC8u;
	OBJECT(object)->x_speed = 0x400;
	attributes = OBJECT(object)->attributes;
	if ((attributes & 0x40u) != 0u)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	command = 0x2600u;
	carry = vector_queue_sound(command);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	donut_shot_fly();
	*p_y = y;
	*p_setup = setup;
}

/* The thrown donut's flight: nothing to do, it moves by its speed. */
void donut_shot_fly(void)
{
}
