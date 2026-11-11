/**
 *    Name:        enemies/ninja.c
 *    Description: stage 7's ninjas (types 32, 33, 3D), their way in, their actions and their star
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Sets a star-throwing ninja up with its behaviour ninja_thrower_behaviour. */
void ninja_thrower_setup(uint16_t object)
{
	uint16_t setup = 0;
	uint8_t attributes = 0;

	setup = ninja_object_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->behaviour = 0x79B0u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0x30u) | 0x86u;
	ninja_setup_common(object);
}

/* Sets a hand-to-hand ninja up with its behaviour ninja_fighter_behaviour. */
void ninja_fighter_setup(uint16_t object)
{
	uint16_t setup = 0;
	uint8_t attributes = 0;

	setup = ninja_object_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->behaviour = 0x7900u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0x30u) | 0x86u;
	ninja_setup_common(object);
}

/* The ninja called away (step 6), by field 29: it vanishes in smoke. */
void ninja_leave(uint16_t object)
{
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;
	uint8_t action_step = 0;

	for (;;)
	{
		action_step = OBJECT(object)->action_step;
		switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
		{
		case 0:
			ninja_leave_start(object);
			return;
		case 2:
			break;
		case -38:
			ninja_thrower_setup(object);
			return;
		case -36:
		case -24:
		case -12:
			ninja_come_in(object);
			return;
		case -34:
		case -22:
		case -10:
			vector_enemy_think(object, &ignored16, &ignored);
			return;
		case -32:
		case -20:
		case -8:
			vector_enemy_act(object, &ignored16, &ignored);
			return;
		case -30:
		case -18:
		case -6:
			enemy_hurt(object);
			return;
		case -28:
		case -16:
		case -4:
			vector_enemy_climb(object, &ignored16, &ignored);
			return;
		case -26:
			ninja_fighter_setup(object);
			return;
		case -14:
			ninja_setup(object);
			return;
		case -2:
			continue;
		}
		break;
	}
	ninja_leave_end(object);
}

/* Plays the ninja vanishing in a puff of smoke. */
void ninja_leave_start(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->animation = 0x95u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Frees the ninja's slot when the smoke ends. */
void ninja_leave_end(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
		OBJECT(object)->flags = 0u;
}

/* Sets a ninja of type 32 up with its behaviour ninja_behaviour. */
void ninja_setup(uint16_t object)
{
	uint16_t setup = 0;

	setup = ninja_object_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->behaviour = 0x7958u;
	ninja_setup_common(object);
}

/* The ninjas' common setup: turned to the nearest player; state 0 fights at once, the others stay hidden
   for their way in. */
void ninja_setup_common(uint16_t object)
{
	uint16_t nearest_player = 0;
	uint8_t parameter = 0, state = 0;

	OBJECT(object)->enemy_class = 1;
	nearest_player = vector_choose_nearest_player(object);
	vector_measure_target(object, nearest_player);
	OBJECT(object)->ninja.vanishes = 1u;
	OBJECT(object)->retarget_time = 0x10u;
	parameter = OBJECT(object)->parameter;
	if (parameter == 0u)
	{
		OBJECT(object)->parameter = 0u;
		OBJECT(object)->state = 2u;
		return;
	}
	OBJECT(object)->flags = 4u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* The ninja's way in, by field 29 (kind_a1_entrance_steps gives the step it starts at). */
void ninja_come_in(uint16_t object)
{
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		ninja_choose_entrance(object);
		return;
	case 2:
		ninja_run_in(object);
		return;
	case 4:
		ninja_run_in_end(object);
		return;
	case 6:
	case 34:
		ninja_appear(object);
		return;
	case 8:
		ninja_appear_end(object);
		return;
	case 10:
		ninja_drop_in(object);
		return;
	case 12:
		ninja_drop_forward(object);
		return;
	case 14:
		ninja_drop_land(object);
		return;
	case 16:
		ninja_leap_in(object);
		return;
	case 18:
		ninja_leap_forward(object);
		return;
	case 20:
	case 30:
		ninja_leap_stop_forward(object);
		return;
	case 22:
	case 32:
		ninja_leap_land(object);
		return;
	case 24:
		ninja_run_and_jump_in(object);
		return;
	case 26:
		ninja_jump_onto_ledge(object);
		return;
	case 28:
		ninja_jump_back(object);
		return;
	case 36:
		ninja_split(object);
		return;
	case 38:
		ninja_split_move(object);
		return;
	case 40:
		ninja_split_flicker(object);
		return;
	case 42:
		ninja_split_copy(object);
		return;
	case 44:
		ninja_wait_to_step_out(object);
		return;
	case 46:
		ninja_step_out(object);
		return;
	case 48:
		ninja_step_out_end(object);
		return;
	case 50:
		ninja_dash_in(object);
		return;
	case 52:
		ninja_dash_in_end(object);
		return;
	case 54:
		ninja_fall_in(object);
		return;
	case 56:
		ninja_fall_in_land(object);
		return;
	}
}

/* Takes the step the ninja's way in starts at from kind_a1_entrance_steps by its state. */
void ninja_choose_entrance(uint16_t object)
{
	uint8_t parameter = 0;

	parameter = OBJECT(object)->parameter;
	OBJECT(object)->action_step = kind_a1_entrance_steps[(int8_t)parameter];
	OBJECT(object)->parameter = 0u;
}

/* Shows the ninja running in at its player for 48 frames. */
void ninja_run_in(uint16_t object)
{
	uint8_t target_direction = 0, action_step = 0;
	uint16_t x_speed = 0;

	OBJECT(object)->flags = 0xC0u;
	OBJECT(object)->timer = 0x30u;
	OBJECT(object)->animation = 0x90u;
	OBJECT(object)->x_speed = 0x200;
	target_direction = OBJECT(object)->target_direction;
	if ((int8_t)(target_direction - 0x40u) >= 0)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	face_movement(object);
}

/* Counts the run down, then lets the ninja fight. */
void ninja_run_in_end(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Shows the ninja appearing in a puff of smoke, with its sound. */
void ninja_appear(uint16_t object)
{
	uint16_t command = 0;
	uint8_t action_step = 0;

	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->animation = 0x96u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	command = 0x6C00u;
	vector_queue_sound(command);
}

/* When the smoke ends, makes the ninja hittable and lets it fight. */
void ninja_appear_end(uint16_t object)
{
	uint8_t animation_flags = 0, state = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		OBJECT(object)->flags = 0xC0u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Shows the ninja coming down from the top, slowly, for 128 frames. */
void ninja_drop_in(uint16_t object)
{
	uint8_t attributes = 0, action_step = 0;

	OBJECT(object)->flags = 0x80u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0x20u;
	OBJECT(object)->animation = 0xA6u;
	OBJECT(object)->z_speed = 0x100;
	OBJECT(object)->timer = 0x80u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Counts down, then moves the dropping ninja toward the front. */
void ninja_drop_forward(uint16_t object)
{
	uint8_t timer = 0, attributes = 0, action_step = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		attributes = OBJECT(object)->attributes;
		OBJECT(object)->attributes = (attributes & 0xCFu) | 0x10u;
		OBJECT(object)->y_speed = -0x200;
		OBJECT(object)->z_speed = 0x100;
		OBJECT(object)->animation = 0x84u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* Pulls the ninja down onto the floor under it; when it lands it can be hit and fights. */
void ninja_drop_land(uint16_t object)
{
	uint32_t negative = 0, landed = 0;
	uint8_t floor_value = 0;
	uint16_t floor_cell = 0;
	uint8_t state = 0;
	uint16_t z_speed = 0, falling_z_speed = 0, y_speed = 0;

	z_speed = OBJECT(object)->z_speed;
	falling_z_speed = z_speed - 0x20u;
	OBJECT(object)->z_speed = falling_z_speed;
	landed = vector_check_landing(object);
	if (landed)
	{
		OBJECT(object)->flags = 0xC0u;
		OBJECT(object)->y_speed = 0;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
		return;
	}
	y_speed = OBJECT(object)->y_speed;
	if (y_speed == 0u)
		return;
	floor_cell = 0u;
	vector_floor_at_offset(object, &floor_cell, &negative);
	floor_value = (uint8_t)(floor_cell >> 8);
	if ((int8_t)floor_value >= 0)
	{
		OBJECT(object)->floor_z = (OBJECT(object)->floor_z & 0xFF00u) | ((((floor_value & 0xFu) << 1) << 1) << 1 & 0xFFu);
		OBJECT(object)->y_speed = 0;
	}
}

/* Shows the ninja leaping in high from behind. */
void ninja_leap_in(uint16_t object)
{
	uint8_t attributes = 0, action_step = 0;

	OBJECT(object)->flags = 0x80u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0x20u;
	OBJECT(object)->animation = 0x84u;
	OBJECT(object)->z_speed = 0x600;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Moves the leaping ninja toward the front. */
void ninja_leap_forward(uint16_t object)
{
	OBJECT(object)->y_speed = -0x200;
	ninja_leap_find_floor(object);
}

/* Takes the floor under the leaping ninja once it is below its height. */
void ninja_leap_find_floor(uint16_t object)
{
	uint32_t negative = 0;
	uint8_t floor_value = 0;
	uint16_t floor_cell = 0;
	uint8_t z_low = 0, attributes = 0, action_step = 0;

	floor_cell = 0u;
	vector_floor_at_offset(object, &floor_cell, &negative);
	floor_value = (uint8_t)(floor_cell >> 8);
	if ((int8_t)floor_value < 0)
	{
		ninja_leap_land(object);
		return;
	}
	floor_value = (((floor_value & 0xFu) << 1) << 1) << 1;
	z_low = (uint8_t)OBJECT(object)->z;
	if (z_low <= floor_value)
	{
		ninja_leap_stop_forward(object);
		return;
	}
	OBJECT(object)->floor_z = (OBJECT(object)->floor_z & 0xFF00u) | (floor_value & 0xFFu);
	OBJECT(object)->flags = 0x88u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0x10u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Stops the ninja's move toward the front and lets it fall. */
void ninja_leap_stop_forward(uint16_t object)
{
	OBJECT(object)->y_speed = 0;
	ninja_leap_land(object);
}

/* Pulls the ninja down until it lands crouching, then lets it fight. */
void ninja_leap_land(uint16_t object)
{
	uint32_t landed = 0;
	uint8_t state = 0;
	uint16_t z_speed = 0, falling_z_speed = 0;

	z_speed = OBJECT(object)->z_speed;
	falling_z_speed = z_speed - 0x20u;
	OBJECT(object)->z_speed = falling_z_speed;
	landed = vector_check_landing(object);
	if (landed)
	{
		OBJECT(object)->animation = 0x9Eu;
		OBJECT(object)->flags = 0xC0u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Shows the ninja running in from the side for 32 frames. */
void ninja_run_and_jump_in(uint16_t object)
{
	uint8_t attributes = 0, action_step = 0;
	uint16_t ninja_x = 0, x_speed = 0;

	OBJECT(object)->flags = 0x80u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0x10u;
	OBJECT(object)->timer = 0x20u;
	OBJECT(object)->animation = 0x90u;
	OBJECT(object)->x_speed = 0x200;
	ninja_x = OBJECT(object)->x;
	if (ninja_x >= 0xE0u)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	face_movement(object);
}

/* Counts the run down, then jumps the ninja up toward a floor 32 high. */
void ninja_jump_onto_ledge(uint16_t object)
{
	uint8_t timer = 0, action_step = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->z_speed = 0x400;
		OBJECT(object)->animation = 0x98u;
		OBJECT(object)->floor_z = 0x20u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* Moves the jumping ninja toward the back once it is high enough. */
void ninja_jump_back(uint16_t object)
{
	uint16_t z = 0;

	z = OBJECT(object)->z;
	if (z < 0x28u)
	{
		ninja_leap_find_floor(object);
		return;
	}
	OBJECT(object)->y_speed = 0x400;
	ninja_leap_find_floor(object);
}

/* When its animation ends, puts in another ninja (type 32, state 7) at its place; with no free slot it
   fights at once. */
void ninja_split(uint16_t object)
{
	uint32_t slot_found = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0;
	uint8_t animation_flags = 0, state = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	leftover_y = ninja_split_child_ADDRESS;
	vector_spawn_child(object, &ignored16, &ignored16_2, &ignored16_3, &slot_found);
	if (slot_found == 0u)
	{
		OBJECT(object)->flags = 0xC0u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
		return;
	}
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Moves the ninja right for 64 frames with a sound. */
void ninja_split_move(uint16_t object)
{
	uint16_t command = 0;
	uint8_t action_step = 0;

	command = 0x2800u;
	vector_queue_sound(command);
	OBJECT(object)->timer = 0x40u;
	OBJECT(object)->x_speed = 0x100;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Flickers the ninja in and out of sight, then makes it hittable and lets it fight. */
void ninja_split_flicker(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	OBJECT(object)->flags ^= 0x84u;
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->flags = 0xC0u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* The ninja put in by another: shows it leaving the first one, moving left, flickering. */
void ninja_split_copy(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->animation = 0x97u;
	OBJECT(object)->timer = 0x40u;
	OBJECT(object)->x_speed = -0x100;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step - 1u;
}

/* Waits 8 frames. */
void ninja_wait_to_step_out(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->timer = 8u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Counts down, then shows the ninja walking toward the front. */
void ninja_step_out(uint16_t object)
{
	uint8_t timer = 0, action_step = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->flags = 0x80u;
		OBJECT(object)->animation = 0x81u;
		OBJECT(object)->y_speed = -0x100;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* Once the ninja is on a floor, makes it hittable and lets it fight. */
void ninja_step_out_end(uint16_t object)
{
	uint32_t negative = 0;
	uint8_t floor_value = 0;
	uint16_t floor_cell = 0;
	uint8_t state = 0;

	floor_cell = 0u;
	vector_floor_at_offset(object, &floor_cell, &negative);
	floor_value = (uint8_t)(floor_cell >> 8);
	if ((int8_t)floor_value >= 0)
	{
		OBJECT(object)->flags = 0xC0u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Shows the ninja dashing in at its player for three runs of its animation. */
void ninja_dash_in(uint16_t object)
{
	uint8_t target_direction = 0, action_step = 0;
	uint16_t x_speed = 0;

	OBJECT(object)->flags = 0xC0u;
	OBJECT(object)->ninja.loops = 3u;
	OBJECT(object)->animation = 0xA2u;
	OBJECT(object)->x_speed = 0x200;
	target_direction = OBJECT(object)->target_direction;
	if ((int8_t)(target_direction - 0x40u) >= 0)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	face_movement(object);
}

/* Counts the dash's runs down, then stops the ninja and lets it fight. */
void ninja_dash_in_end(uint16_t object)
{
	uint8_t animation_flags = 0, loops = 0, state = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		loops = OBJECT(object)->ninja.loops;
		OBJECT(object)->ninja.loops = loops - 1u;
		if (loops == 1u)
		{
			OBJECT(object)->x_speed = 0;
			state = OBJECT(object)->state;
			OBJECT(object)->state = state + 1u;
		}
	}
}

/* Shows the ninja falling in, facing the nearest player, onto the floor under it. */
void ninja_fall_in(uint16_t object)
{
	uint32_t negative = 0;
	uint8_t floor_value = 0;
	uint16_t floor_cell = 0, nearest_player = 0;
	uint8_t action_step = 0;

	OBJECT(object)->flags = 0xC8u;
	OBJECT(object)->animation = 0x84u;
	nearest_player = vector_choose_nearest_player(object);
	vector_measure_target(object, nearest_player);
	floor_cell = 0u;
	vector_floor_at_offset(object, &floor_cell, &negative);
	floor_value = (uint8_t)(floor_cell >> 8);
	OBJECT(object)->floor_z = (OBJECT(object)->floor_z & 0xFF00u) | ((((floor_value & 0xFu) << 1) << 1) << 1 & 0xFFu);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	vector_face_direction(object);
}

/* Pulls the ninja down until it lands, then lets it fight. */
void ninja_fall_in_land(uint16_t object)
{
	uint32_t landed = 0;
	uint8_t state = 0;
	uint16_t z_speed = 0;

	z_speed = OBJECT(object)->z_speed;
	OBJECT(object)->z_speed = z_speed - 0x20u;
	landed = vector_check_landing(object);
	if (landed)
	{
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Starts the ninja's strike, turned to its player. */
void ninja_hop_strike_start(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->animation = 0x99u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	face_target(object);
}

/* On the marked frame, hops the ninja back with its attacking hit box. */
void ninja_hop_strike_hit(uint16_t object)
{
	uint8_t animation_flags = 0, action_step = 0, attributes = 0;
	uint16_t x_speed = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) == 0u)
		return;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	OBJECT(object)->x_speed = 0x200;
	attributes = OBJECT(object)->attributes;
	if ((attributes & 0x40u) == 0u)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	leftover_y = ninja_hop_strike_hit_box_ADDRESS;
	vector_set_hit_box(object);
}

/* Starts the ninja's throw, turned to its player. */
void ninja_throw_start(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->animation = 0x92u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	face_target(object);
}

/* On the marked frame, puts in the star (4D40 type 19). */
uint16_t ninja_throw_release(uint16_t object, uint16_t steps)
{
	uint32_t child_placed = 0;
	uint16_t child_object = 0, star = 0;
	uint8_t animation_flags = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) == 0u)
		return steps;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	leftover_y = ninja_throw_release_child_ADDRESS;
	child_object = ninja_throw_release_child_ADDRESS;
	spawn_list_2_child(object, child_object, &star, &child_placed);
	return star;
}

/* Sets the star up on its thrower's floor, flying fast the way it faces. */
uint16_t ninja_star_setup(uint16_t object)
{
	uint8_t floor_level = 0;
	uint16_t setup = 0;
	uint8_t next_floor_cell = 0, attributes = 0, state = 0;
	uint16_t x_speed = 0;

	setup = ninja_star_object_setup_ADDRESS;
	vector_object_setup(object, setup);
	next_floor_cell = OBJECT(object)->next_floor_cell;
	floor_level = next_floor_cell;
	if ((int8_t)next_floor_cell >= 0)
		OBJECT(object)->floor_z = (OBJECT(object)->floor_z & 0xFF00u) | ((((floor_level & 0xFu) << 1) << 1) << 1 & 0xFFu);
	OBJECT(object)->x_speed = 0x400;
	attributes = OBJECT(object)->attributes;
	if ((attributes & 0x40u) != 0u)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	ninja_star_fly();
	return setup;
}

/* The star's flight: nothing to do, it moves by its speed. */
void ninja_star_fly(void)
{
}

/* Starts the ninja's slash, turned to its player. */
void ninja_slash_start(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->animation = 0x91u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	face_target(object);
}

/* On the marked frame, gives the ninja its attacking hit box. */
void ninja_slash_hit(uint16_t object)
{
	uint8_t animation_flags = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) == 0u)
		return;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	leftover_y = ninja_hop_strike_hit_box_ADDRESS;
	vector_set_hit_box(object);
}

/* Shows the ninja crouching for the wait kind_a1_attack_delays_by_players gives. */
uint16_t ninja_crouch(uint16_t object)
{
	uint16_t attack_delays = 0;
	uint8_t action_step = 0;

	OBJECT(object)->animation = 0xA7u;
	attack_delays = kind_a1_attack_delays_by_players_ADDRESS;
	OBJECT(object)->timer = kind_a1_attack_delays_by_players[(int8_t)player_count];
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	return attack_delays;
}

/* Counts the crouch down, then starts the strike, turned to its player. */
void ninja_crouch_strike_start(uint16_t object)
{
	uint8_t timer = 0, action_step = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->animation = 0xA4u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	face_target(object);
}

/* On the marked frame, gives the ninja its low attacking hit box. */
void ninja_crouch_strike_hit(uint16_t object)
{
	uint8_t animation_flags = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) == 0u)
		return;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	leftover_y = ninja_crouch_strike_hit_box_ADDRESS;
	vector_set_hit_box(object);
}

/* Gives the ninja back its plain hit box and ends the action when the attack ends. */
void ninja_attack_recover(uint16_t object)
{
	uint8_t action_step = 0;

	leftover_y = ninja_body_box_ADDRESS;
	vector_set_hit_box(object);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	ninja_attack_end(object);
}

/* Ends the ninja's action when its animation ends. */
void ninja_attack_end(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	OBJECT(object)->state = 2u;
	OBJECT(object)->timer = 0u;
}

/* Crouches the ninja, turned to its player, keeping the direction to jump in. */
uint16_t ninja_jump_attack_start(uint16_t object)
{
	uint16_t target_player = 0;
	uint8_t target_direction = 0, action_step = 0;
	uint16_t target = 0;

	OBJECT(object)->animation = 0x9Au;
	face_target(object);
	target = OBJECT(object)->target;
	target_player = target;
	vector_measure_target(object, target_player);
	target_direction = OBJECT(object)->target_direction;
	OBJECT(object)->ninja.jump_direction = target_direction;
	OBJECT(object)->ninja.loops = 2u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	return target_player;
}

/* When the crouch ends, jumps the ninja high toward its player. */
void ninja_jump_attack_take_off(uint16_t object)
{
	uint8_t animation_flags = 0, jump_direction = 0, action_step = 0;
	uint16_t x_speed = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	OBJECT(object)->animation = 0x98u;
	OBJECT(object)->x_speed = 0x100;
	jump_direction = OBJECT(object)->ninja.jump_direction;
	if ((int8_t)(jump_direction - 0x40u) >= 0)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	OBJECT(object)->z_speed = 0x600;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Plays the jump's somersault twice, then the dive. */
void ninja_jump_attack_spin(uint16_t object)
{
	uint8_t animation_flags = 0, loops = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		loops = OBJECT(object)->ninja.loops;
		OBJECT(object)->ninja.loops = loops - 1u;
		if (loops == 1u)
		{
			OBJECT(object)->animation = 0x9Cu;
			action_step = OBJECT(object)->action_step;
			OBJECT(object)->action_step = action_step + 1u;
			ninja_jump_attack_dive(object);
			return;
		}
	}
	ninja_jump_attack_dive(object);
}

/* Pulls the diving ninja down, with its attacking hit box on the marked frame; near the floor it lands. */
void ninja_jump_attack_dive(uint16_t object)
{
	uint16_t z_speed = 0;
	uint8_t animation_flags = 0, action_step = 0;
	uint16_t z = 0, floor_z = 0, z_speed_2 = 0;

	z = OBJECT(object)->z;
	floor_z = OBJECT(object)->floor_z;
	if ((uint16_t)(z - floor_z) >= 4u)
	{
		animation_flags = OBJECT(object)->animation_flags;
		if ((((uint16_t)((uint32_t)animation_flags << 8) >> 8) & 2u) != 0u)
		{
			leftover_y = ninja_jump_attack_dive_box_ADDRESS;
			vector_set_hit_box(object);
		}
	}
	else
	{
		OBJECT(object)->animation = 0x9Du;
		leftover_y = ninja_body_box_ADDRESS;
		vector_set_hit_box(object);
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
	z_speed_2 = OBJECT(object)->z_speed;
	z_speed = z_speed_2 - 0x20u;
	ninja_jump_attack_land(object, z_speed);
}

/* Pulls the ninja down slowly. */
void ninja_jump_attack_fall(uint16_t object)
{
	uint16_t z_speed = 0;
	uint16_t z_speed_2 = 0;

	z_speed_2 = OBJECT(object)->z_speed;
	z_speed = z_speed_2 - 0x10u;
	ninja_jump_attack_land(object, z_speed);
}

/* When the ninja lands, gives it back its plain hit box and ends the action. */
void ninja_jump_attack_land(uint16_t object, uint16_t z_speed)
{
	uint32_t landed = 0;

	OBJECT(object)->z_speed = z_speed;
	landed = vector_check_landing(object);
	if (landed == 0u)
		return;
	leftover_y = ninja_body_box_ADDRESS;
	vector_set_hit_box(object);
	OBJECT(object)->animation = 0x9Du;
	OBJECT(object)->state = 2u;
	OBJECT(object)->timer = 0u;
}

/* Near its player leaps at him at once; otherwise starts running at him. */
void ninja_rush_start(uint16_t object)
{
	uint8_t bounced = 0, action_step = 0, attributes = 0;
	uint16_t ninja_x = 0, screen_offset = 0, target_dx = 0, x_speed = 0;

	OBJECT(object)->ninja.bounced = 0u;
	ninja_x = OBJECT(object)->x;
	screen_offset = ninja_x - 0x40u;
	if (screen_offset >= 0x140u)
	{
		bounced = OBJECT(object)->ninja.bounced;
		OBJECT(object)->ninja.bounced = bounced + 1u;
	}
	target_dx = OBJECT(object)->target_dx;
	if (target_dx >= 0x80u)
	{
		OBJECT(object)->animation = 0xA2u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
	else
	{
		OBJECT(object)->animation = 0x98u;
		OBJECT(object)->z_speed = 0x500;
		OBJECT(object)->action_step = 2u;
	}
	face_target(object);
	OBJECT(object)->x_speed = 0x200;
	attributes = OBJECT(object)->attributes;
	if ((attributes & 0x40u) != 0u)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	OBJECT(object)->timer = 3u;
}

/* Runs the ninja at its player; once near, leaps at him; after three runs of the animation gives up. */
void ninja_rush_run(uint16_t object)
{
	uint8_t animation_flags = 0, timer = 0, action_step = 0;
	uint16_t target_dx = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	target_dx = OBJECT(object)->target_dx;
	if (target_dx >= 0x80u)
	{
		timer = OBJECT(object)->timer;
		OBJECT(object)->timer = timer - 1u;
		if (timer == 1u)
			OBJECT(object)->action_step = 3u;
		return;
	}
	OBJECT(object)->z_speed = 0x500;
	OBJECT(object)->animation = 0x98u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Pulls the leaping ninja down; it bounces once off the screen's edge, and when it lands it goes on with
   a slash (action 2B). */
void ninja_rush_leap(uint16_t object)
{
	uint32_t landed = 0;
	uint8_t bounced = 0, bounced_2 = 0;
	uint16_t z_speed = 0, ninja_x = 0, x_speed = 0;

	z_speed = OBJECT(object)->z_speed;
	OBJECT(object)->z_speed = z_speed - 0x20u;
	landed = vector_check_landing(object);
	if (landed)
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->action = 0x2Bu;
		OBJECT(object)->action_step = 0u;
		leftover_y = ninja_body_box_ADDRESS;
		vector_set_hit_box(object);
		return;
	}
	bounced = OBJECT(object)->ninja.bounced;
	if (bounced == 0u)
	{
		ninja_x = OBJECT(object)->x;
		if (ninja_x < 0x48 || ninja_x > 0x177)
		{
			x_speed = OBJECT(object)->x_speed;
			OBJECT(object)->x_speed = 0u - x_speed;
			OBJECT(object)->z_speed = 0x200;
			OBJECT(object)->animation = 0x84u;
			leftover_y = ninja_jump_attack_dive_box_ADDRESS;
			vector_set_hit_box(object);
			bounced_2 = OBJECT(object)->ninja.bounced;
			OBJECT(object)->ninja.bounced = bounced_2 + 1u;
			face_movement(object);
			return;
		}
	}
}

/* Ends the ninja's action when its animation ends. */
void ninja_rush_end(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	OBJECT(object)->state = 2u;
	OBJECT(object)->timer = 0u;
}

/* Starts the ninja vanishing in smoke. */
void ninja_vanish_start(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->animation = 0x95u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* On the marked frame, makes the ninja unhittable with the smoke's sound. */
void ninja_vanish_puff(uint16_t object)
{
	uint16_t command = 0;
	uint8_t animation_flags = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) == 0u)
		return;
	OBJECT(object)->flags = 0x80u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	command = 0x6C00u;
	vector_queue_sound(command);
}

/* When the smoke ends, hides the ninja and moves it toward its player for 64 frames. */
void ninja_vanish_move(uint16_t object)
{
	uint8_t animation_flags = 0, target_direction = 0, action_step = 0;
	uint16_t x_speed = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	OBJECT(object)->flags = 4u;
	OBJECT(object)->x_speed = 0x200;
	target_direction = OBJECT(object)->target_direction;
	if ((int8_t)(target_direction - 0x40u) >= 0)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	OBJECT(object)->timer = 0x40u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Counts the move down, then shows the ninja appearing in smoke, with its sound. */
void ninja_vanish_reappear(uint16_t object)
{
	uint16_t command = 0;
	uint8_t timer = 0, action_step = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->animation = 0x96u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	command = 0x6C00u;
	vector_queue_sound(command);
}

/* On the marked frame, makes the ninja hittable again. */
void ninja_vanish_solid(uint16_t object)
{
	uint8_t animation_flags = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) != 0u)
	{
		OBJECT(object)->flags = 0xC0u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* Ends the action when the appearing animation ends. */
void ninja_vanish_end(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	OBJECT(object)->state = 2u;
	OBJECT(object)->timer = 0u;
}
