/**
 *    Name:        enemies/gorilla.c
 *    Description: stage 5's gorilla (type 31) and its actions 26, 2C, 35
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Sets the gorilla up with its behaviour gorilla_behaviour, turned to its player: state 0 joins the
   fight at once, the others come in first, out of the enemy count. */
void gorilla_setup(uint16_t object)
{
	uint16_t nearest_player = 0, setup = 0;
	uint8_t parameter = 0, state = 0;

	setup = gorilla_object_setup_ADDRESS;
	vector_object_setup(object, setup);
	nearest_player = vector_choose_nearest_player(object);
	vector_measure_target(object, nearest_player);
	OBJECT(object)->gorilla.vanishes = 1u;
	OBJECT(object)->behaviour = 0x7B8Eu;
	OBJECT(object)->retarget_time = 0x10u;
	parameter = OBJECT(object)->parameter;
	if (parameter == 0u)
	{
		OBJECT(object)->parameter = 0u;
		OBJECT(object)->state = 2u;
		return;
	}
	OBJECT(object)->enemy_class = -1;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* The gorilla's way in, by field 29: the steps its entrance (gorilla_entrances) starts it at. */
void gorilla_come_in(uint16_t object)
{
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		gorilla_entrance_setup(object);
		return;
	case 2:
		gorilla_wait_for_place(object);
		return;
	case 4:
		gorilla_step_forward(object);
		return;
	case 6:
	case 14:
	case 22:
		gorilla_reach_floor(object);
		return;
	case 8:
		gorilla_walk_right_in(object);
		return;
	case 10:
	case 18:
		gorilla_stop(object);
		return;
	case 12:
	case 20:
		gorilla_turn_to_front(object);
		return;
	case 16:
		gorilla_walk_left_in(object);
		return;
	}
}

/* Takes the gorilla's flags, the x it comes to, the step it starts at (hidden with bit 7) and its
   animation from gorilla_entrances. */
void gorilla_entrance_setup(uint16_t object)
{
	uint8_t action_step = 0;
	uint16_t entrance = 0;
	uint8_t parameter = 0, step = 0, animation = 0;
	uint16_t flags = 0, scaled_entrance_x = 0;

	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->entrance_pending = 0x80u;
	parameter = OBJECT(object)->parameter;
	entrance = gorilla_entrances_ADDRESS + (int8_t)(((uint32_t)parameter << 1) << 1);
	flags = (((uint32_t)GORILLA_ENTRANCE(entrance)->flags << 8u) | GORILLA_ENTRANCE(entrance)->x);
	OBJECT(object)->attributes = flags >> 8;
	scaled_entrance_x = (uint32_t)(uint8_t)flags << 4;
	OBJECT(object)->gorilla.entrance_x = scaled_entrance_x;
	step = GORILLA_ENTRANCE(entrance)->step;
	action_step = step;
	if ((int8_t)step < 0)
	{
		action_step &= 0x7Fu;
		OBJECT(object)->flags = 4u;
	}
	OBJECT(object)->action_step = action_step;
	animation = GORILLA_ENTRANCE(entrance)->animation;
	OBJECT(object)->animation = animation;
}

/* Waits for the scroll to bring the gorilla to its x, then plays animation 93 for 16 frames. */
void gorilla_wait_for_place(uint16_t object)
{
	uint8_t action_step = 0;
	uint16_t gorilla_x = 0, entrance_x = 0;

	gorilla_x = OBJECT(object)->x;
	entrance_x = OBJECT(object)->gorilla.entrance_x;
	if (gorilla_x < entrance_x)
	{
		OBJECT(object)->animation = 0x93u;
		OBJECT(object)->timer = 0x10u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* Counts down, then moves the gorilla toward the front. */
void gorilla_step_forward(uint16_t object)
{
	uint8_t timer = 0, action_step = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->y_speed = -0x100;
		OBJECT(object)->timer = 4u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* Moves the gorilla toward the front until it is on the floor it walks on, then makes it hittable,
   counts it as an enemy and lets it fight. */
void gorilla_reach_floor(uint16_t object)
{
	uint32_t negative = 0;
	uint8_t floor_value = 0;
	uint16_t floor_cell = 0;
	uint8_t own_floor = 0, state = 0, timer = 0, attributes = 0;

	floor_cell = 0u;
	vector_floor_at_offset(object, &floor_cell, &negative);
	floor_value = (uint8_t)(floor_cell >> 8);
	own_floor = (uint8_t)OBJECT(object)->floor_z;
	if ((uint8_t)((((floor_value & 0xFu) << 1) << 1) << 1) == own_floor)
	{
		OBJECT(object)->parameter = 0u;
		OBJECT(object)->flags = 0xC0u;
		OBJECT(object)->entrance_pending = 0u;
		OBJECT(object)->enemy_class = 0;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		attributes = OBJECT(object)->attributes;
		OBJECT(object)->attributes = (attributes & 0xCFu) | 0x10u;
	}
}

/* When the scroll brings the gorilla to its x, walks it right for 64 frames. */
void gorilla_walk_right_in(uint16_t object)
{
	uint8_t action_step = 0;
	uint16_t gorilla_x = 0, entrance_x = 0;

	gorilla_x = OBJECT(object)->x;
	entrance_x = OBJECT(object)->gorilla.entrance_x;
	if (entrance_x <= gorilla_x)
		return;
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->animation = 0x81u;
	OBJECT(object)->x_speed = 0x100;
	OBJECT(object)->timer = 0x40u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	face_movement(object);
}

/* Counts the walk down, then stops the gorilla with animation 86. */
void gorilla_stop(uint16_t object)
{
	uint8_t timer = 0, action_step = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->animation = 0x86u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* When that animation ends, walks the gorilla toward the front. */
void gorilla_turn_to_front(uint16_t object)
{
	uint8_t animation_flags = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		OBJECT(object)->animation = 0x81u;
		OBJECT(object)->y_speed = -0x100;
		OBJECT(object)->timer = 4u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* When the scroll brings the gorilla to its x, walks it left for 64 frames. */
void gorilla_walk_left_in(uint16_t object)
{
	uint8_t action_step = 0;
	uint16_t gorilla_x = 0, entrance_x = 0;

	gorilla_x = OBJECT(object)->x;
	entrance_x = OBJECT(object)->gorilla.entrance_x;
	if (entrance_x <= gorilla_x)
		return;
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->animation = 0x81u;
	OBJECT(object)->x_speed = -0x100;
	OBJECT(object)->timer = 0x40u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	face_movement(object);
}

/* Starts the gorilla's blow, turned to its player. */
void gorilla_punch_start(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->animation = 0x90u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	face_target(object);
}

/* On the blow's marked frame, gives the gorilla its attacking hit box. */
void gorilla_punch_hit(uint16_t object)
{
	uint8_t animation_flags = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) == 0u)
		return;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	leftover_y = gorilla_punch_hit_box_ADDRESS;
	vector_set_hit_box(object);
}

/* Gives the gorilla back its plain hit box and ends the action when the blow ends. */
void gorilla_punch_end(uint16_t object)
{
	uint8_t action_step = 0, animation_flags = 0;

	leftover_y = gorilla_body_box_ADDRESS;
	vector_set_hit_box(object);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	OBJECT(object)->state = 2u;
	OBJECT(object)->timer = 0u;
}

/* Sends the gorilla leaping at its player, as high as gorilla_leap_speeds gives for the stage's
   difficulty. */
uint16_t gorilla_leap_take_off(uint16_t object)
{
	uint16_t leap_speeds = 0;
	uint8_t attributes = 0, action_step = 0;
	uint16_t leap_speed = 0, x_speed = 0;

	OBJECT(object)->animation = 0x91u;
	OBJECT(object)->timer = 8u;
	OBJECT(object)->x_speed = 0x200;
	leap_speeds = gorilla_leap_speeds_ADDRESS;
	leap_speed = gorilla_leap_speeds[(int8_t)((uint8_t)((uint32_t)difficulty << 1)) / 2];
	OBJECT(object)->z_speed = leap_speed;
	face_target(object);
	attributes = OBJECT(object)->attributes;
	if ((attributes & 0x40u) != 0u)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	return leap_speeds;
}

/* Pulls the gorilla down; 8 frames into the leap gives it its attacking hit box. */
void gorilla_leap_rise(uint16_t object)
{
	uint32_t landed = 0;
	uint8_t timer = 0, action_step = 0;
	uint16_t z_speed = 0;

	z_speed = OBJECT(object)->z_speed;
	OBJECT(object)->z_speed = z_speed - 0x30u;
	landed = vector_check_landing(object);
	if (landed)
	{
		gorilla_leap_land(object);
		return;
	}
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	leftover_y = gorilla_leap_rise_box_ADDRESS;
	vector_set_hit_box(object);
}

/* Pulls the gorilla down until it lands. */
void gorilla_leap_fall(uint16_t object)
{
	uint32_t landed = 0;
	uint16_t z_speed = 0;

	z_speed = OBJECT(object)->z_speed;
	OBJECT(object)->z_speed = z_speed - 0x30u;
	landed = vector_check_landing(object);
	if (landed == 0u)
		return;
	gorilla_leap_land(object);
}

/* Stops the landed gorilla with its plain hit box and ends the action. */
void gorilla_leap_land(uint16_t object)
{
	OBJECT(object)->x_speed = 0;
	leftover_y = gorilla_body_box_ADDRESS;
	vector_set_hit_box(object);
	OBJECT(object)->state = 2u;
	OBJECT(object)->timer = 0u;
}

/* Walks the gorilla away from its player for 32 frames. */
void gorilla_back_off_start(uint16_t object)
{
	uint8_t attributes = 0, action_step = 0;
	uint16_t x_speed = 0;

	OBJECT(object)->animation = 0x81u;
	OBJECT(object)->timer = 0x20u;
	OBJECT(object)->x_speed = -0x180;
	face_target(object);
	attributes = OBJECT(object)->attributes;
	if ((attributes & 0x40u) != 0u)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Ends the action when the walk's time is up. */
void gorilla_back_off_end(uint16_t object)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->state = 2u;
	OBJECT(object)->timer = 0u;
}
