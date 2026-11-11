/**
 *    Name:        objects/clown_on_ball.c
 *    Description: Krustyland's clown on a ball, its attacks, and its ball
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Runs the ball's burst by field 28. */
uint16_t clown_ball_burst_steps(uint16_t object)
{
	uint16_t steps = 0;
	uint8_t action = 0;

	for (;;)
	{
		steps = clown_ball_burst_actions_ADDRESS;
		action = OBJECT(object)->action;
		switch ((int8_t)(uint8_t)((uint32_t)action << 1))
		{
		case 0:
			clown_ball_burst(object);
			return steps;
		case 2:
			break;
		case -34:
			kind_98_entrance_show(object);
			return steps;
		case -32:
			kind_98_entrance_next(object);
			return steps;
		case -30:
			kind_98_entrance_wait(object);
			return steps;
		case -28:
			kind_98_entrance_walk(object);
			return steps;
		case -26:
			kind_98_entrance_reach_floor(object);
			return steps;
		case -24:
			kind_98_step_back(object);
			return steps;
		case -22:
			kind_98_step_back_end(object);
			return steps;
		case -20:
			kind_98_strike_swing(object);
			return steps;
		case -18:
			kind_98_strike_hit(object);
			return steps;
		case -16:
			kind_98_strike_recover(object);
			return steps;
		case -14:
			kind_98_strike_end(object);
			return steps;
		case -12:
		case -10:
			continue;
		case -8:
			return clown_ball_start(object);
		case -6:
		case -4:
			clown_ball_fall(object);
			return steps;
		case -2:
			clown_ball_vanish(object);
			return steps;
		}
		break;
	}
	clown_ball_burst_end(object);
	return steps;
}

/* Turns the ball into a burst. */
void clown_ball_burst(uint16_t object)
{
	uint8_t action = 0;

	OBJECT(object)->kind = 4u;
	OBJECT(object)->animation = 0x80u;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* Takes the burst away when its animation ends. */
void clown_ball_burst_end(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
		OBJECT(object)->flags = 0u;
}

/* Sends the ball flying up the screen. */
uint16_t clown_ball_start(uint16_t object)
{
	uint16_t setup = 0;
	uint8_t parameter = 0;

	setup = clown_ball_setup_ADDRESS;
	vector_object_setup(object, setup);
	parameter = OBJECT(object)->parameter;
	if ((parameter & 1u) == 0u)
	{
		OBJECT(object)->kind = 0xC0u;
		OBJECT(object)->animation = 0x91u;
	}
	OBJECT(object)->y_speed = -0x40;
	OBJECT(object)->z_speed = 0x400;
	OBJECT(object)->state = 2u;
	OBJECT(object)->flags = 0x88u;
	return setup;
}

/* Falls and bursts on landing. */
void clown_ball_fall(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;
	uint8_t state = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	if (carry)
	{
		OBJECT(object)->kind = 4u;
		OBJECT(object)->animation = 0x80u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Takes the burst away when its animation ends. */
void clown_ball_vanish(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
		OBJECT(object)->flags = 0u;
}

/* Sets up the clown on a ball: fighting at once, or posing out of play by its spawn's state. */
void clown_on_ball_start(uint16_t object)
{
	uint8_t pose_number = 0;
	uint16_t clown_pose = 0, setup = 0;
	uint8_t setup_count = 0, parameter = 0, attributes = 0, attributes_2 = 0, state = 0;

	setup = clown_on_ball_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->clown_on_ball.vanishes = 1u;
	setup_count = OBJECT(object)->clown_on_ball.setup_count;
	OBJECT(object)->clown_on_ball.setup_count = setup_count + 1u;
	OBJECT(object)->behaviour = 0x7D3Eu;
	OBJECT(object)->retarget_time = 0x10u;
	clown_pose = clown_on_ball_poses_ADDRESS;
	parameter = OBJECT(object)->parameter;
	pose_number = parameter;
	if ((int8_t)parameter >= 0)
	{
		OBJECT(object)->parameter = 0u;
		OBJECT(object)->state = 2u;
		return;
	}
	clown_pose += (int8_t)((uint32_t)pose_number << 1);
	OBJECT(object)->animation = CLOWN_POSE(clown_pose)->animation;
	attributes = OBJECT(object)->attributes;
	attributes_2 = CLOWN_POSE(clown_pose)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | attributes_2;
	OBJECT(object)->parameter = 0u;
	OBJECT(object)->entrance_pending = 0xFFu;
	OBJECT(object)->enemy_class = -1;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Poses until it comes left of x 00E0, then fights. */
void clown_on_ball_pose(uint16_t object)
{
	uint8_t state = 0;
	uint16_t clown_x = 0;

	clown_x = OBJECT(object)->x;
	if (clown_x < 0xE0u)
	{
		OBJECT(object)->enemy_class = 0;
		OBJECT(object)->entrance_pending = 0u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Starts its strike. */
void clown_on_ball_strike_swing(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->animation = 0x90u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Puts out the strike's hit box at its mark and goes back to the fight when the animation ends. */
void clown_on_ball_strike(uint16_t object)
{
	uint8_t animation_flags = 0, animation_flags_2 = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
	{
		animation_flags_2 = OBJECT(object)->animation_flags;
		if ((animation_flags_2 & 2u) == 0u)
		{
			leftover_y = clown_on_ball_body_box_ADDRESS;
			vector_set_hit_box(object);
			return;
		}
		leftover_y = clown_on_ball_strike_box_ADDRESS;
		vector_set_hit_box(object);
		return;
	}
	leftover_y = clown_on_ball_body_box_ADDRESS;
	vector_set_hit_box(object);
	OBJECT(object)->state = 2u;
	OBJECT(object)->timer = 0u;
}

/* Jumps: straight up when near its target, towards it when far. */
void clown_on_ball_jump(uint16_t object)
{
	uint8_t target_direction = 0, action_step = 0;
	uint16_t target_dx = 0, x_speed = 0;

	OBJECT(object)->animation = 0x90u;
	OBJECT(object)->z_speed = 0x600;
	target_dx = OBJECT(object)->target_dx;
	if (target_dx >= 0x20u)
	{
		OBJECT(object)->z_speed = 0x400;
		OBJECT(object)->x_speed = 0x180;
		target_direction = OBJECT(object)->target_direction;
		if ((int8_t)(target_direction - 0x40u) >= 0)
		{
			x_speed = OBJECT(object)->x_speed;
			OBJECT(object)->x_speed = 0u - x_speed;
		}
	}
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Falls with its hit box and goes back to the fight on landing. */
void clown_on_ball_jump_fall(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t animation_flags = 0;
	uint16_t z_speed = 0, next_z_speed = 0;

	z_speed = OBJECT(object)->z_speed;
	next_z_speed = z_speed - 0x20u;
	OBJECT(object)->z_speed = next_z_speed;
	carry = vector_check_landing(object);
	if (carry == 0u)
	{
		animation_flags = OBJECT(object)->animation_flags;
		if ((animation_flags & 2u) == 0u)
		{
			leftover_y = clown_on_ball_body_box_ADDRESS;
			vector_set_hit_box(object);
			return;
		}
		leftover_y = clown_on_ball_strike_box_ADDRESS;
		vector_set_hit_box(object);
		return;
	}
	leftover_y = clown_on_ball_body_box_ADDRESS;
	vector_set_hit_box(object);
	OBJECT(object)->state = 2u;
	OBJECT(object)->timer = 0u;
}

/* Winds up for 32 frames. */
void clown_on_ball_charge_wind_up(uint16_t object)
{
	uint8_t action_step = 0, animation_flags = 0;

	OBJECT(object)->animation = 0x90u;
	OBJECT(object)->timer = 0x20u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) == 0u)
	{
		leftover_y = clown_on_ball_body_box_ADDRESS;
		vector_set_hit_box(object);
		return;
	}
	leftover_y = clown_on_ball_strike_box_ADDRESS;
	vector_set_hit_box(object);
}

/* Rolls at its target for 32 frames. */
void clown_on_ball_charge(uint16_t object)
{
	uint8_t timer = 0, animation_flags = 0, target_direction = 0, action_step = 0;
	uint16_t x_speed = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
	{
		animation_flags = OBJECT(object)->animation_flags;
		if ((animation_flags & 2u) == 0u)
		{
			leftover_y = clown_on_ball_body_box_ADDRESS;
			vector_set_hit_box(object);
			return;
		}
		leftover_y = clown_on_ball_strike_box_ADDRESS;
		vector_set_hit_box(object);
		return;
	}
	OBJECT(object)->timer = 0x20u;
	OBJECT(object)->x_speed = 0x200;
	target_direction = OBJECT(object)->target_direction;
	if ((int8_t)(target_direction - 0x40u) >= 0)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) == 0u)
	{
		leftover_y = clown_on_ball_body_box_ADDRESS;
		vector_set_hit_box(object);
		return;
	}
	leftover_y = clown_on_ball_strike_box_ADDRESS;
	vector_set_hit_box(object);
}

/* Turns round half the time and rolls on for 40 frames. */
void clown_on_ball_charge_turn(uint16_t object)
{
	uint8_t timer = 0, animation_flags = 0, action_step = 0;
	uint16_t x_speed = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
	{
		animation_flags = OBJECT(object)->animation_flags;
		if ((animation_flags & 2u) == 0u)
		{
			leftover_y = clown_on_ball_body_box_ADDRESS;
			vector_set_hit_box(object);
			return;
		}
		leftover_y = clown_on_ball_strike_box_ADDRESS;
		vector_set_hit_box(object);
		return;
	}
	if (random_number & 1u)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	OBJECT(object)->timer = 0x28u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) == 0u)
	{
		leftover_y = clown_on_ball_body_box_ADDRESS;
		vector_set_hit_box(object);
		return;
	}
	leftover_y = clown_on_ball_strike_box_ADDRESS;
	vector_set_hit_box(object);
}

/* Stops and goes back to the fight. */
void clown_on_ball_charge_end(uint16_t object)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->x_speed = 0;
	leftover_y = clown_on_ball_body_box_ADDRESS;
	vector_set_hit_box(object);
	OBJECT(object)->state = 2u;
	OBJECT(object)->timer = 0u;
}

/* Pauses (one of two animations) for a time by the game's rank. */
uint16_t clown_on_ball_pause(uint16_t object)
{
	uint16_t waits = 0;
	uint8_t animation = 0, action_step = 0;

	OBJECT(object)->animation = 0x86u;
	if (random_number & 1u)
	{
		animation = OBJECT(object)->animation;
		OBJECT(object)->animation = (animation + 1u) | 0x80u;
	}
	waits = clown_on_ball_pause_waits_by_rank_ADDRESS;
	OBJECT(object)->timer = clown_on_ball_pause_waits_by_rank[((rank >> 1) >> 1) >> 1];
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	return waits;
}

/* Goes back to the fight. */
void clown_on_ball_pause_end(uint16_t object)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->state = 2u;
		OBJECT(object)->timer = 0u;
		return;
	}
}

/* Starts hopping away from its target, four hops. */
void clown_on_ball_hop_away(uint16_t object)
{
	uint8_t target_direction = 0, action_step = 0;
	uint16_t x_speed = 0;

	OBJECT(object)->animation = 0x90u;
	OBJECT(object)->clown_on_ball.hops_left = 4u;
	OBJECT(object)->z_speed = 0x600;
	OBJECT(object)->x_speed = -0x80;
	target_direction = OBJECT(object)->target_direction;
	if ((int8_t)(target_direction - 0x40u) >= 0)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Hops on until the fourth landing, staying within the screen, then goes back to the fight. */
void clown_on_ball_hop(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;
	uint8_t hops_left = 0;
	uint16_t clown_x = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	if (carry == 0u)
	{
		clown_x = OBJECT(object)->x;
		if (clown_x < 0x40 || clown_x > 0x17F)
			OBJECT(object)->x_speed = 0;
		return;
	}
	hops_left = OBJECT(object)->clown_on_ball.hops_left;
	OBJECT(object)->clown_on_ball.hops_left = hops_left - 1u;
	if (hops_left == 1u)
	{
		OBJECT(object)->state = 2u;
		OBJECT(object)->timer = 0u;
		return;
	}
	OBJECT(object)->z_speed = 0x400;
	clown_x = OBJECT(object)->x;
	if (clown_x < 0x40 || clown_x > 0x17F)
		OBJECT(object)->x_speed = 0;
}

/* Works out the x and y offsets (48E8-48E9, 48EA-48EB) of a point at angle A and radius B round a
   centre. */
void orbit_offset(uint16_t angle_and_radius)
{
	uint8_t angle = 0, quarter = 0, radius = 0, swap = 0;
	uint8_t quadrant_bits = 0;

	angle = (uint8_t)(angle_and_radius >> 8);
	radius = (uint8_t)angle_and_radius;
	orbit_angle_and_radius = ((uint32_t)angle << 8) | radius;
	angle &= 0x3Fu;
	orbit_quarter_angle = angle;
	orbit_x_offset_low = (uint16_t)((uint32_t)orbit_cosines[angle] * radius) >> 8;
	orbit_y_offset_low = (uint16_t)((uint32_t)orbit_cosines[(int8_t)((uint8_t)(0x3Fu - orbit_quarter_angle))] * orbit_radius) >> 8;
	orbit_x_offset_high = 0u;
	orbit_y_offset_high = 0u;
	if ((orbit_angle & 0x40u) != 0u)
	{
		swap = orbit_y_offset_low;
		orbit_y_offset_low = orbit_x_offset_low;
		orbit_x_offset_low = swap;
	}
	if ((int8_t)orbit_angle < 0)
		orbit_y_offset = 0u - orbit_y_offset;
	quadrant_bits = orbit_angle & 0xC0u;
	quarter = quadrant_bits;
	if (quadrant_bits != 0u && quarter != 0xC0u)
		orbit_x_offset = 0u - orbit_x_offset;
}
