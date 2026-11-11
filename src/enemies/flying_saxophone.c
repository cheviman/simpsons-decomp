/**
 *    Name:        enemies/flying_saxophone.c
 *    Description: stage 6's flying kind B8 thrower (type FC) and its shots (5280 type F3)
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Turns the flyer toward its player by which side of him it is. */
void flying_saxophone_face_player(uint16_t object)
{
	uint8_t attributes = 0;
	uint16_t target_player = 0;
	uint8_t attributes_2 = 0, attributes_3 = 0;
	uint16_t target = 0, flyer_x = 0, player_x = 0;

	if (OBJECT(object)->flags == 0u)
		return;
	target = OBJECT(object)->target;
	target_player = target;
	flyer_x = OBJECT(object)->x;
	player_x = OBJECT(target_player)->x;
	if (player_x <= flyer_x)
	{
		attributes_2 = OBJECT(object)->attributes;
		attributes = attributes_2 | 0x40u;
	}
	else
	{
		attributes_3 = OBJECT(object)->attributes;
		attributes = attributes_3 & 0xBFu;
	}
	OBJECT(object)->attributes = attributes;
}

/* Sets the flyer up leaping in big from the front with a sound, with its heading, sweep and descent from
   the flying_saxophone tables and 1200 frames to stay. */
void flying_saxophone_setup(uint16_t object)
{
	uint8_t variant = 0;
	uint16_t command = 0, setup = 0;
	uint8_t parameter = 0, parameter_2 = 0, state = 0;
	uint16_t descent_slowdown_value = 0, descent_speed = 0;

	setup = flying_saxophone_object_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->zoom_x = 0x80u;
	OBJECT(object)->zoom_y = 0x80u;
	OBJECT(object)->flags = 0x98u;
	OBJECT(object)->floor_z = 0u;
	parameter = OBJECT(object)->parameter;
	variant = parameter;
	OBJECT(object)->flying_saxophone.sweep_way = flying_saxophone_sweep_ways[(int8_t)variant];
	OBJECT(object)->flying_saxophone.heading = (OBJECT(object)->flying_saxophone.heading & 0xFFu) | ((flying_saxophone_headings[(int8_t)variant] & 0xFFu) << 8u);
	OBJECT(object)->flying_saxophone.sweep_rate = flying_saxophone_sweep_rates[(int8_t)variant];
	descent_slowdown_value = flying_saxophone_descent_slowdowns[(int8_t)((uint8_t)((uint32_t)variant << 1)) / 2];
	OBJECT(object)->flying_saxophone.descent_slowdown = descent_slowdown_value;
	parameter_2 = OBJECT(object)->parameter;
	descent_speed = flying_saxophone_descent_y_speeds[(int8_t)((uint8_t)((uint32_t)parameter_2 << 1)) / 2];
	OBJECT(object)->flying_saxophone.descent_y_speed = descent_speed;
	OBJECT(object)->attributes = 0x20u;
	OBJECT(object)->x = 0xE0u;
	command = 0x301u;
	vector_queue_sound(command);
	OBJECT(object)->x_speed = 0x300;
	OBJECT(object)->y_speed = -0x80;
	OBJECT(object)->z_speed = 0x200;
	OBJECT(object)->flying_saxophone.stay_time = 0x4B0u;
	vector_choose_nearest_player(object);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* The flyer's way in, by field 29. */
void flying_saxophone_come_in(uint16_t object)
{
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		flying_saxophone_leap_in(object);
		return;
	case 2:
		flying_saxophone_descend(object);
		return;
	case 4:
		flying_saxophone_hover(object);
		return;
	case 6:
		flying_saxophone_rise(object);
		return;
	case 8:
		flying_saxophone_take_off(object);
		return;
	}
}

/* Shrinks the leaping flyer and slows it; once it falls, gives it its y speed
   (flying_saxophone_descent_y_speeds). */
void flying_saxophone_leap_in(uint16_t object)
{
	uint16_t z_speed = 0;
	uint8_t action_step = 0;
	uint16_t zoom_x = 0, x_speed = 0, z_speed_2 = 0, descent_y_speed = 0;
	uint32_t zoom_x_halfword = 0;

	OBJECT(object)->flags = 0x98u;
	zoom_x = (((uint32_t)OBJECT(object)->zoom_x << 8u) | OBJECT(object)->zoom_y);
	zoom_x_halfword = zoom_x - 0x101u;
	OBJECT(object)->zoom_x = (uint8_t)(zoom_x_halfword >> 8u);
	OBJECT(object)->zoom_y = (uint8_t)zoom_x_halfword;
	x_speed = OBJECT(object)->x_speed;
	OBJECT(object)->x_speed = x_speed - 0x10u;
	z_speed_2 = OBJECT(object)->z_speed;
	z_speed = z_speed_2 - 0x10u;
	OBJECT(object)->z_speed = z_speed;
	if ((int16_t)z_speed < 0)
	{
		descent_y_speed = OBJECT(object)->flying_saxophone.descent_y_speed;
		OBJECT(object)->y_speed = descent_y_speed;
		OBJECT(object)->attributes = 0x10u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* Shrinks the flyer to its plain size and slows it as it comes down to its flying height, then stops it
   for 32 frames. */
void flying_saxophone_descend(uint16_t object)
{
	uint16_t new_flags = 0, zoom_x = 0;
	uint8_t action_step = 0;
	uint16_t zoom_x_2 = 0, z = 0, x_speed = 0, descent_slowdown = 0, z_speed = 0;

	zoom_x_2 = (((uint32_t)OBJECT(object)->zoom_x << 8u) | OBJECT(object)->zoom_y);
	zoom_x = zoom_x_2 - 0x202u;
	if (zoom_x < 0x4040u)
		new_flags = 0x8800u;
	else
	{
		OBJECT(object)->zoom_x = (uint8_t)(zoom_x >> 8u);
		OBJECT(object)->zoom_y = (uint8_t)zoom_x;
		new_flags = 0x9800u;
	}
	OBJECT(object)->flags = new_flags >> 8;
	z = OBJECT(object)->z;
	if (z > 0x40u)
	{
		x_speed = OBJECT(object)->x_speed;
		descent_slowdown = OBJECT(object)->flying_saxophone.descent_slowdown;
		OBJECT(object)->x_speed = x_speed - descent_slowdown;
		z_speed = OBJECT(object)->z_speed;
		OBJECT(object)->z_speed = z_speed - 0x20u;
		return;
	}
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->z_speed = 0;
	OBJECT(object)->timer = 0x20u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Bobs the flyer for its wait, then lifts it a little. */
void flying_saxophone_hover(uint16_t object)
{
	uint8_t timer = 0, action_step = 0;

	flying_saxophone_bob_in(object);
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->flags = 0x88u;
		OBJECT(object)->timer = 0x12u;
		OBJECT(object)->z_speed = 0x100;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* Moves the flyer by its heading while it rises to its flying height. */
void flying_saxophone_rise(uint16_t object)
{
	uint8_t timer = 0, action_step = 0;
	uint16_t z = 0;

	flying_saxophone_set_speeds(object);
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->z_speed = 0;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
		return;
	}
	z = OBJECT(object)->z;
	if (z >= 0x40u)
		OBJECT(object)->z_speed = 0;
}

/* Makes the flyer hittable and sends it flying at the nearest player with a wait before its first throw. */
void flying_saxophone_take_off(uint16_t object)
{
	uint8_t state = 0;

	OBJECT(object)->flags = 0xC8u;
	vector_choose_nearest_player(object);
	flying_saxophone_choose_throw_wait(object);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	OBJECT(object)->action = 0u;
	OBJECT(object)->action_step = 0u;
}

/* Flies the flyer around its player, bobbing, until its next throw (a volley three times in four, else
   single shots); when its stay is over it rises off the screen and goes. */
void flying_saxophone_fly(uint16_t object)
{
	uint8_t timer = 0, hit_box = 0, hit_box_2 = 0;
	uint16_t stay_time = 0, z = 0, stay_time_2 = 0;

	stay_time = OBJECT(object)->flying_saxophone.stay_time;
	if (stay_time == 0u)
	{
		flying_saxophone_steer(object);
		OBJECT(object)->z_speed = 0x100;
		z = OBJECT(object)->z;
		if (z >= 0x100u)
			OBJECT(object)->flags = 0u;
		return;
	}
	stay_time_2 = OBJECT(object)->flying_saxophone.stay_time;
	OBJECT(object)->flying_saxophone.stay_time = stay_time_2 - 1u;
	flying_saxophone_bob(object);
	flying_saxophone_steer(object);
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->flying_saxophone.shots_left = 4u;
	OBJECT(object)->timer = 1u;
	hit_box = (uint8_t)(OBJECT(object)->hit_box >> 8u);
	OBJECT(object)->hit_box = (OBJECT(object)->hit_box & 0xFFu) | ((hit_box - 1u & 0xFFu) << 8u);
	hit_box_2 = (uint8_t)(OBJECT(object)->hit_box >> 8u);
	if ((hit_box_2 & 3u) != 0u)
	{
		OBJECT(object)->state = 3u;
		flying_saxophone_face_player(object);
		return;
	}
	OBJECT(object)->state = 4u;
	flying_saxophone_face_player(object);
}

/* Throws three shots in a row, 7 frames apart, with a sound at the first, still flying. */
void flying_saxophone_volley(uint16_t object)
{
	uint32_t slot_found = 0;
	uint16_t command = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0;
	uint8_t timer = 0, shots_left = 0, shots_left_2 = 0, shots_left_3 = 0;

	flying_saxophone_bob(object);
	flying_saxophone_steer(object);
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
	{
		flying_saxophone_face_player(object);
		return;
	}
	shots_left = OBJECT(object)->flying_saxophone.shots_left;
	if (shots_left == 4u)
	{
		command = 0xF00u;
		vector_queue_sound(command);
	}
	shots_left_2 = OBJECT(object)->flying_saxophone.shots_left;
	OBJECT(object)->flying_saxophone.shots_left = shots_left_2 - 1u;
	if (shots_left_2 == 1u)
	{
		OBJECT(object)->state = 2u;
		OBJECT(object)->animation = 0x80u;
		flying_saxophone_choose_throw_wait(object);
		return;
	}
	OBJECT(object)->animation = 0x95u;
	shots_left_3 = OBJECT(object)->flying_saxophone.shots_left;
	leftover_y = flying_saxophone_volley_shots[shots_left_3 & 3u];
	vector_spawn_child(object, &ignored16, &ignored16_2, &ignored16_3, &slot_found);
	flying_saxophone_next_throw_wait(object);
}

/* Waits 7 frames before the next shot and turns the flyer to its player. */
void flying_saxophone_next_throw_wait(uint16_t object)
{
	OBJECT(object)->timer = 7u;
	flying_saxophone_face_player(object);
}

/* Throws its single shots one after the other, still flying, then sends it flying again with a new wait. */
void flying_saxophone_single_throw(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0;
	uint8_t timer = 0, shots_left = 0, shots_left_2 = 0;

	flying_saxophone_bob(object);
	flying_saxophone_steer(object);
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
	{
		flying_saxophone_face_player(object);
		return;
	}
	shots_left = OBJECT(object)->flying_saxophone.shots_left;
	OBJECT(object)->flying_saxophone.shots_left = shots_left - 1u;
	if (shots_left == 1u)
	{
		OBJECT(object)->state = 2u;
		OBJECT(object)->animation = 0x80u;
		flying_saxophone_choose_throw_wait(object);
		return;
	}
	OBJECT(object)->animation = 0x90u;
	shots_left_2 = OBJECT(object)->flying_saxophone.shots_left;
	leftover_y = flying_saxophone_single_shots[shots_left_2 & 1u];
	vector_spawn_child(object, &ignored16, &ignored16_2, &ignored16_3, &carry);
	flying_saxophone_next_throw_wait(object);
}

/* The flyer's hit (step FF), by field 29. */
void flying_saxophone_hurt(uint16_t object)
{
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		flying_saxophone_hurt_start(object);
		return;
	case 2:
		flying_saxophone_hurt_shake(object);
		return;
	case 4:
		flying_saxophone_die_start(object);
		return;
	case 6:
		flying_saxophone_die_fall(object);
		return;
	case 8:
		flying_saxophone_die_end(object);
		return;
	}
}

/* Stops the hit flyer, keeps its height and plays its hurt animation for 30 frames with its sound. */
void flying_saxophone_hurt_start(uint16_t object)
{
	uint16_t command = 0;
	uint8_t action_step = 0;
	uint16_t z = 0;

	OBJECT(object)->flags = 0x88u;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->z_speed = 0;
	z = OBJECT(object)->z;
	OBJECT(object)->flying_saxophone.kept_height = z;
	OBJECT(object)->timer = 0x1Eu;
	command = 0x5300u;
	vector_queue_sound(command);
	OBJECT(object)->animation = 0x89u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Shakes and flashes the hit flyer, then sends it flying again. */
void flying_saxophone_hurt_shake(uint16_t object)
{
	uint8_t attributes = 0;
	uint8_t timer = 0, timer_2 = 0, attributes_2 = 0, attributes_3 = 0, attributes_4 = 0;

	flying_saxophone_shake_height(object);
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
	{
		timer_2 = OBJECT(object)->timer;
		if (timer_2 & 1u)
		{
			attributes_2 = OBJECT(object)->attributes;
			attributes = (attributes_2 & 0x30u) | 0x8Fu;
		}
		else
		{
			attributes_3 = OBJECT(object)->attributes;
			attributes = attributes_3 & 0x7Fu;
		}
		OBJECT(object)->attributes = attributes;
		OBJECT(object)->animation_flags = 0x80u;
		return;
	}
	attributes_4 = OBJECT(object)->attributes;
	OBJECT(object)->attributes = attributes_4 & 0x7Fu;
	OBJECT(object)->animation = 0x80u;
	OBJECT(object)->state = 2u;
	OBJECT(object)->flags = 0xC8u;
	OBJECT(object)->animation_flags = 0x80u;
	OBJECT(object)->timer = 0x10u;
}

/* The beaten flyer (step FE), by field 29. */
void flying_saxophone_die(uint16_t object)
{
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		flying_saxophone_die_start(object);
		return;
	case 2:
		flying_saxophone_die_fall(object);
		return;
	case 4:
		flying_saxophone_die_end(object);
		return;
	case -4:
		flying_saxophone_hurt_start(object);
		return;
	case -2:
		flying_saxophone_hurt_shake(object);
		return;
	}
}

/* Stops the beaten flyer with its sound and its falling animation. */
void flying_saxophone_die_start(uint16_t object)
{
	uint16_t command = 0;
	uint8_t action_step = 0;

	command = 0x5300u;
	vector_queue_sound(command);
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->flags = 0x88u;
	OBJECT(object)->animation = 0x88u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Pulls the beaten flyer down; when it lands, plays a sound. */
void flying_saxophone_die_fall(uint16_t object)
{
	uint32_t landed = 0;
	uint16_t command = 0, ignored16 = 0;
	uint8_t action_step = 0;

	vector_apply_gravity(object, &ignored16, &landed);
	if (landed == 0u)
	{
		flying_saxophone_die_end(object);
		return;
	}
	command = 0x7700u;
	vector_queue_sound(command);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	flying_saxophone_die_end(object);
}

/* Frees the flyer's slot when its animation ends. */
void flying_saxophone_die_end(uint16_t object)
{
	uint8_t animation_flags = 0, points = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		points = OBJECT(object)->points;
		OBJECT(object)->points = points | 0x80u;
		OBJECT(object)->flags = 0u;
	}
}

/* Sets the hit flyer's height speed toward its kept height plus a shake from
   flying_saxophone_hurt_shakes. */
void flying_saxophone_shake_height(uint16_t object)
{
	uint8_t a = 0;
	uint8_t timer = 0;
	uint16_t kept_height = 0, z = 0;

	timer = OBJECT(object)->timer;
	kept_height = OBJECT(object)->flying_saxophone.kept_height;
	z = OBJECT(object)->z;
	OBJECT(object)->z_speed = (uint32_t)(uint16_t)(((uint32_t)a << 8) | (uint8_t)((((uint32_t)a << 8) | (uint8_t)((((uint32_t)a << 8) | flying_saxophone_hurt_shakes[timer & 3u]) + kept_height)) - z)) << 8;
}

/* Steers the flyer around its player: sweeps its heading back and forth on its side of him, follows his
   depth and keeps it on the screen. */
void flying_saxophone_steer(uint16_t object)
{
	uint8_t dy_high = 0, goal_x_high = 0, goal_x_low = 0, goal_y_high = 0, goal_y_low = 0, heading_whole = 0;
	uint16_t target_player = 0;
	uint8_t sweep_way = 0, sweep_rate = 0, sweep_way_2 = 0, sweep_rate_2 = 0, sweep_way_3 = 0, sweep_way_4 = 0, sweep_rate_3 = 0, sweep_way_5 = 0, sweep_rate_4 = 0, sweep_way_6 = 0;
	uint16_t target = 0, flyer_x = 0, player_x = 0, turn = 0, heading = 0, new_heading = 0, heading_2 = 0, right_heading_up = 0, left_minus_rate = 0, heading_3 = 0, left_heading_down = 0, heading_4 = 0, left_heading_up = 0, target_2 = 0, flyer_y = 0, player_y = 0, dy = 0, depth_difference = 0, depth_distance = 0, y_speed = 0, checked_x = 0, old_x = 0, checked_y = 0, old_y = 0;

	target = OBJECT(object)->target;
	target_player = target;
	if ((frame_count & 0x7F00u) == 0u)
		target_player = vector_choose_nearest_player(object);
	flyer_x = OBJECT(object)->x;
	player_x = OBJECT(target_player)->x;
	if (flyer_x < player_x)
	{
		sweep_way = OBJECT(object)->flying_saxophone.sweep_way;
		if (sweep_way != 0u)
		{
			sweep_rate = OBJECT(object)->flying_saxophone.sweep_rate;
			turn = 0u - sweep_rate;
			heading = OBJECT(object)->flying_saxophone.heading;
			new_heading = turn + heading;
			heading_whole = (new_heading >> 8) & 0xFu;
			OBJECT(object)->flying_saxophone.heading = ((uint32_t)heading_whole << 8) | (uint8_t)new_heading;
			if (heading_whole == 0xCu)
			{
				sweep_way_2 = OBJECT(object)->flying_saxophone.sweep_way;
				OBJECT(object)->flying_saxophone.sweep_way = ~sweep_way_2;
			}
		}
		else
		{
			sweep_rate_2 = OBJECT(object)->flying_saxophone.sweep_rate;
			heading_2 = OBJECT(object)->flying_saxophone.heading;
			right_heading_up = sweep_rate_2 + heading_2;
			heading_whole = (right_heading_up >> 8) & 0xFu;
			OBJECT(object)->flying_saxophone.heading = ((uint32_t)heading_whole << 8) | (uint8_t)right_heading_up;
			if (heading_whole == 4u)
			{
				sweep_way_3 = OBJECT(object)->flying_saxophone.sweep_way;
				OBJECT(object)->flying_saxophone.sweep_way = ~sweep_way_3;
			}
		}
	}
	else
	{
		sweep_way_4 = OBJECT(object)->flying_saxophone.sweep_way;
		if (sweep_way_4 != 0u)
		{
			sweep_rate_3 = OBJECT(object)->flying_saxophone.sweep_rate;
			left_minus_rate = 0u - sweep_rate_3;
			heading_3 = OBJECT(object)->flying_saxophone.heading;
			left_heading_down = left_minus_rate + heading_3;
			heading_whole = (left_heading_down >> 8) & 0xFu;
			OBJECT(object)->flying_saxophone.heading = ((uint32_t)heading_whole << 8) | (uint8_t)left_heading_down;
			if (heading_whole == 4u)
			{
				sweep_way_5 = OBJECT(object)->flying_saxophone.sweep_way;
				OBJECT(object)->flying_saxophone.sweep_way = ~sweep_way_5;
			}
		}
		else
		{
			sweep_rate_4 = OBJECT(object)->flying_saxophone.sweep_rate;
			heading_4 = OBJECT(object)->flying_saxophone.heading;
			left_heading_up = sweep_rate_4 + heading_4;
			heading_whole = (left_heading_up >> 8) & 0xFu;
			OBJECT(object)->flying_saxophone.heading = ((uint32_t)heading_whole << 8) | (uint8_t)left_heading_up;
			if (heading_whole == 0xCu)
			{
				sweep_way_6 = OBJECT(object)->flying_saxophone.sweep_way;
				OBJECT(object)->flying_saxophone.sweep_way = ~sweep_way_6;
			}
		}
	}
	flying_saxophone_set_speeds(object);
	target_2 = OBJECT(object)->target;
	target_player = target_2;
	flyer_y = OBJECT(object)->y;
	player_y = OBJECT(target_player)->y;
	dy = flyer_y - player_y;
	dy_high = (uint8_t)(dy >> 8);
	steer_dy_high = dy_high;
	depth_difference = ((uint32_t)dy_high << 8) | (uint8_t)dy;
	depth_distance = depth_difference >> 15 ? 0u - depth_difference : depth_difference;
	if (depth_distance >= 4u)
	{
		OBJECT(object)->y_speed = 0x100;
		if (steer_dy_high >= 0)
		{
			y_speed = OBJECT(object)->y_speed;
			OBJECT(object)->y_speed = 0u - y_speed;
		}
	}
	checked_x = OBJECT(object)->x;
	goal_x_high = (uint8_t)(checked_x >> 8);
	goal_x_low = (uint8_t)checked_x;
	if ((uint16_t)(((uint32_t)goal_x_high << 8) | goal_x_low) < 0x40u)
	{
		goal_x_low = 0x40u;
		old_x = OBJECT(object)->x;
		OBJECT(object)->x_speed = (uint32_t)(uint8_t)((((uint32_t)goal_x_high << 8) | goal_x_low) - old_x) << 8;
		checked_y = OBJECT(object)->y;
		goal_y_high = (uint8_t)(checked_y >> 8);
		goal_y_low = (uint8_t)checked_y;
		if ((uint16_t)(((uint32_t)goal_y_high << 8) | goal_y_low) < 0x90u)
		{
			goal_y_low = 0x90u;
			old_y = OBJECT(object)->y;
			OBJECT(object)->y_speed = (uint32_t)(uint8_t)((((uint32_t)goal_y_high << 8) | goal_y_low) - old_y) << 8;
			return;
		}
		if ((uint16_t)(((uint32_t)goal_y_high << 8) | goal_y_low) >= 0x100u)
		{
			goal_y_low = 0xFFu;
			old_y = OBJECT(object)->y;
			OBJECT(object)->y_speed = (uint32_t)(uint8_t)((((uint32_t)goal_y_high << 8) | goal_y_low) - old_y) << 8;
		}
		return;
	}
	if ((uint16_t)(((uint32_t)goal_x_high << 8) | goal_x_low) >= 0x180u)
	{
		goal_x_low = 0x7Fu;
		old_x = OBJECT(object)->x;
		OBJECT(object)->x_speed = (uint32_t)(uint8_t)((((uint32_t)goal_x_high << 8) | goal_x_low) - old_x) << 8;
	}
	checked_y = OBJECT(object)->y;
	goal_y_high = (uint8_t)(checked_y >> 8);
	goal_y_low = (uint8_t)checked_y;
	if ((uint16_t)(((uint32_t)goal_y_high << 8) | goal_y_low) < 0x90u)
	{
		goal_y_low = 0x90u;
		old_y = OBJECT(object)->y;
		OBJECT(object)->y_speed = (uint32_t)(uint8_t)((((uint32_t)goal_y_high << 8) | goal_y_low) - old_y) << 8;
		return;
	}
	if ((uint16_t)(((uint32_t)goal_y_high << 8) | goal_y_low) >= 0x100u)
	{
		goal_y_low = 0xFFu;
		old_y = OBJECT(object)->y;
		OBJECT(object)->y_speed = (uint32_t)(uint8_t)((((uint32_t)goal_y_high << 8) | goal_y_low) - old_y) << 8;
	}
}

/* Bobs the arriving flyer's height by flying_saxophone_bob_up. */
void flying_saxophone_bob_in(uint16_t object)
{
	uint8_t a = 0;
	uint8_t bob_phase = 0, bob_phase_2 = 0;
	uint16_t z = 0;

	bob_phase = OBJECT(object)->flying_saxophone.bob_phase;
	z = OBJECT(object)->z;
	OBJECT(object)->z_speed = (uint32_t)(uint16_t)(((uint32_t)a << 8) | (uint8_t)((((uint32_t)a << 8) | (uint8_t)((((uint32_t)a << 8) | flying_saxophone_bob_up[(int8_t)bob_phase]) + 0x40u)) - z)) << 8;
	bob_phase_2 = OBJECT(object)->flying_saxophone.bob_phase;
	OBJECT(object)->flying_saxophone.bob_phase = (bob_phase_2 + 1u) & 0x1Fu;
}

/* Bobs the flying flyer's height up and down by flying_saxophone_bob_down and flying_saxophone_bob_up. */
void flying_saxophone_bob(uint16_t object)
{
	uint8_t a = 0, phase = 0;
	uint16_t heights = 0;
	uint8_t bob_phase = 0, bob_phase_2 = 0;
	uint16_t z = 0;

	bob_phase = OBJECT(object)->flying_saxophone.bob_phase;
	phase = bob_phase;
	if ((phase & 0xE0u) != 0u)
		heights = flying_saxophone_bob_up_ADDRESS;
	else
		heights = flying_saxophone_bob_down_ADDRESS;
	z = OBJECT(object)->z;
	OBJECT(object)->z_speed = (uint32_t)(uint16_t)(((uint32_t)a << 8) | (uint8_t)((((uint32_t)a << 8) | (uint8_t)((((uint32_t)a << 8) | (uint8_t)BOB_HEIGHT(heights + (phase & 0x1Fu))) + 0x40u)) - z)) << 8;
	bob_phase_2 = OBJECT(object)->flying_saxophone.bob_phase;
	OBJECT(object)->flying_saxophone.bob_phase = bob_phase_2 + 1u;
}

/* Sets the flyer's x and y speeds by its heading from flying_saxophone_velocities. */
void flying_saxophone_set_speeds(uint16_t object)
{
	uint16_t speeds = 0;
	uint8_t heading_whole = 0;
	uint16_t x_speed = 0, y_speed = 0;

	heading_whole = (uint8_t)(OBJECT(object)->flying_saxophone.heading >> 8u);
	speeds = flying_saxophone_velocities_ADDRESS + (int8_t)(((uint32_t)heading_whole << 1) << 1);
	x_speed = VELOCITY(speeds)->x_speed;
	OBJECT(object)->x_speed = x_speed;
	y_speed = VELOCITY(speeds)->y_speed;
	OBJECT(object)->y_speed = y_speed;
}

/* Picks the frames before the flyer's next throw at random from flying_saxophone_shot_waits. */
void flying_saxophone_choose_throw_wait(uint16_t object)
{
	uint8_t random_byte = 0;
	uint16_t roll = 0;

	roll = vector_next_random_byte(0u);
	random_byte = (uint8_t)(roll >> 8);
	OBJECT(object)->timer = (uint8_t)(VELOCITY(flying_saxophone_velocities_ADDRESS + (random_byte & 3u) - 0x4u)->x_speed >> 8u);
}

/* Sets the shot up with its animation by its state, thrown up with one of four x speeds at random. */
uint16_t flying_saxophone_shot_setup(uint16_t object)
{
	uint16_t setup = 0, shot_speeds = 0;
	uint8_t parameter = 0, attributes = 0, attributes_2 = 0, state = 0;
	uint16_t shot_x_speed = 0, x_speed = 0;

	setup = flying_saxophone_shot_object_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->flags = 0x80u;
	parameter = OBJECT(object)->parameter;
	OBJECT(object)->animation = flying_saxophone_shot_animations[(int8_t)parameter];
	OBJECT(object)->z_speed = 0x400;
	shot_speeds = flying_saxophone_shot_speeds_ADDRESS;
	shot_x_speed = flying_saxophone_shot_speeds[random_number & 3u];
	OBJECT(object)->x_speed = shot_x_speed;
	attributes = OBJECT(object)->attributes;
	if ((attributes & 0x40u) != 0u)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	attributes_2 = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes_2 & 0x8Fu) | 0x50u;
	OBJECT(object)->floor_z = 0u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return shot_speeds;
}

/* Pulls the shot down; where it lands it bursts (hit sparks), able to hurt for 2 frames. */
void flying_saxophone_shot_fall(uint16_t object)
{
	uint32_t landed = 0;
	uint16_t ignored16 = 0;
	uint8_t state = 0;

	vector_apply_gravity(object, &ignored16, &landed);
	if (landed)
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->z_speed = 0x100;
		OBJECT(object)->flags = 0xC0u;
		OBJECT(object)->kind = 4u;
		OBJECT(object)->animation = 0x80u;
		OBJECT(object)->timer = 2u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Counts the 2 frames down and makes the burst harmless. */
void flying_saxophone_shot_burst(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->flags = 0x80u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	flying_saxophone_shot_remove(object);
}

/* Frees the shot's slot when its burst ends. */
void flying_saxophone_shot_remove(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	OBJECT(object)->flags = 0u;
}
