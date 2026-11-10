/**
 *    Name:        enemies/kind_b8_flyer.c
 *    Description: stage 6's flying kind B8 thrower (type FC) and its shots (5280 type F3)
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Turns the flyer toward its player by which side of him it is. */
void kind_b8_flyer_face_player(uint16_t object)
{
	uint8_t attributes = 0;
	uint16_t target_player = 0;
	uint8_t attributes_2 = 0, attributes_3 = 0;
	uint16_t target = 0, t1 = 0, t2 = 0;

	if (OBJECT(object)->flags == 0u)
		return;
	target = OBJECT(object)->target;
	target_player = target;
	t1 = OBJECT(object)->x;
	t2 = OBJECT(target_player)->x;
	if (t2 <= t1)
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
   the kind_b8 tables and 1200 frames to stay. */
uint16_t kind_b8_flyer_setup(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t variant = 0;
	uint16_t command = 0, setup = 0, y = 0;
	uint8_t parameter = 0, parameter_2 = 0, state = 0;
	uint16_t t1 = 0, t2 = 0;

	setup = kind_b8_flyer_object_setup_ADDRESS;
	y = vector_object_setup(object, setup);
	OBJECT(object)->zoom_x = 0x80u;
	OBJECT(object)->zoom_y = 0x80u;
	OBJECT(object)->flags = 0x98u;
	OBJECT(object)->floor_z = 0u;
	parameter = OBJECT(object)->parameter;
	variant = parameter;
	OBJECT(object)->kind_b8_flyer.sweep_way = kind_b8_sweep_ways[(int8_t)variant];
	OBJECT(object)->kind_b8_flyer.heading = (OBJECT(object)->kind_b8_flyer.heading & 0xFFu) | ((kind_b8_headings[(int8_t)variant] & 0xFFu) << 8u);
	OBJECT(object)->kind_b8_flyer.sweep_rate = kind_b8_sweep_rates[(int8_t)variant];
	t1 = kind_b8_descent_slowdowns[(int8_t)((uint8_t)((uint32_t)variant << 1)) / 2];
	OBJECT(object)->kind_b8_flyer.descent_slowdown = t1;
	parameter_2 = OBJECT(object)->parameter;
	t2 = kind_b8_descent_y_speeds[(int8_t)((uint8_t)((uint32_t)parameter_2 << 1)) / 2];
	OBJECT(object)->kind_b8_flyer.descent_y_speed = t2;
	OBJECT(object)->attributes = 0x20u;
	OBJECT(object)->x = 0xE0u;
	command = 0x301u;
	carry = vector_queue_sound(command);
	OBJECT(object)->x_speed = 0x300;
	OBJECT(object)->y_speed = -0x80;
	OBJECT(object)->z_speed = 0x200;
	OBJECT(object)->kind_b8_flyer.stay_time = 0x4B0u;
	vector_choose_nearest_player(object);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return y;
}

/* The flyer's way in, by field 29. */
void kind_b8_flyer_come_in(uint16_t object)
{
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		kind_b8_flyer_leap_in(object);
		return;
	case 2:
		kind_b8_flyer_descend(object);
		return;
	case 4:
		kind_b8_flyer_hover(object);
		return;
	case 6:
		kind_b8_flyer_rise(object);
		return;
	case 8:
		kind_b8_flyer_take_off(object);
		return;
	}
}

/* Shrinks the leaping flyer and slows it; once it falls, gives it its y speed
   (kind_b8_descent_y_speeds). */
void kind_b8_flyer_leap_in(uint16_t object)
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
		descent_y_speed = OBJECT(object)->kind_b8_flyer.descent_y_speed;
		OBJECT(object)->y_speed = descent_y_speed;
		OBJECT(object)->attributes = 0x10u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* Shrinks the flyer to its plain size and slows it as it comes down to its flying height, then stops it
   for 32 frames. */
void kind_b8_flyer_descend(uint16_t object)
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
		descent_slowdown = OBJECT(object)->kind_b8_flyer.descent_slowdown;
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
void kind_b8_flyer_hover(uint16_t object)
{
	uint8_t timer = 0, action_step = 0;

	kind_b8_flyer_bob_in(object);
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
void kind_b8_flyer_rise(uint16_t object)
{
	uint8_t timer = 0, action_step = 0;
	uint16_t z = 0;

	kind_b8_flyer_set_speeds(object);
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
void kind_b8_flyer_take_off(uint16_t object)
{
	uint8_t state = 0;

	OBJECT(object)->flags = 0xC8u;
	vector_choose_nearest_player(object);
	kind_b8_flyer_choose_throw_wait(object);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	OBJECT(object)->action = 0u;
	OBJECT(object)->action_step = 0u;
}

/* Flies the flyer around its player, bobbing, until its next throw (a volley three times in four, else
   single shots); when its stay is over it rises off the screen and goes. */
void kind_b8_flyer_fly(uint16_t object)
{
	uint8_t timer = 0, hit_box = 0, hit_box_2 = 0;
	uint16_t stay_time = 0, z = 0, stay_time_2 = 0;

	stay_time = OBJECT(object)->kind_b8_flyer.stay_time;
	if (stay_time == 0u)
	{
		kind_b8_flyer_steer(object);
		OBJECT(object)->z_speed = 0x100;
		z = OBJECT(object)->z;
		if (z >= 0x100u)
			OBJECT(object)->flags = 0u;
		return;
	}
	stay_time_2 = OBJECT(object)->kind_b8_flyer.stay_time;
	OBJECT(object)->kind_b8_flyer.stay_time = stay_time_2 - 1u;
	kind_b8_flyer_bob(object);
	kind_b8_flyer_steer(object);
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->kind_b8_flyer.shots_left = 4u;
	OBJECT(object)->timer = 1u;
	hit_box = (uint8_t)(OBJECT(object)->hit_box >> 8u);
	OBJECT(object)->hit_box = (OBJECT(object)->hit_box & 0xFFu) | ((hit_box - 1u & 0xFFu) << 8u);
	hit_box_2 = (uint8_t)(OBJECT(object)->hit_box >> 8u);
	if ((hit_box_2 & 3u) != 0u)
	{
		OBJECT(object)->state = 3u;
		kind_b8_flyer_face_player(object);
		return;
	}
	OBJECT(object)->state = 4u;
	kind_b8_flyer_face_player(object);
}

/* Throws three shots in a row, 7 frames apart, with a sound at the first, still flying. */
uint16_t kind_b8_flyer_volley(uint16_t object, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t child_record = 0, command = 0, ignored16 = 0, ignored16_2 = 0;
	uint8_t timer = 0, shots_left = 0, shots_left_2 = 0, shots_left_3 = 0;

	kind_b8_flyer_bob(object);
	kind_b8_flyer_steer(object);
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
	{
		kind_b8_flyer_face_player(object);
		return y;
	}
	shots_left = OBJECT(object)->kind_b8_flyer.shots_left;
	if (shots_left == 4u)
	{
		command = 0xF00u;
		carry = vector_queue_sound(command);
	}
	shots_left_2 = OBJECT(object)->kind_b8_flyer.shots_left;
	OBJECT(object)->kind_b8_flyer.shots_left = shots_left_2 - 1u;
	if (shots_left_2 == 1u)
	{
		OBJECT(object)->state = 2u;
		OBJECT(object)->animation = 0x80u;
		kind_b8_flyer_choose_throw_wait(object);
		return y;
	}
	OBJECT(object)->animation = 0x95u;
	shots_left_3 = OBJECT(object)->kind_b8_flyer.shots_left;
	child_record = kind_b8_volley_shots[shots_left_3 & 3u];
	vector_spawn_child(object, child_record, &ignored16, &ignored16_2, &carry);
	kind_b8_flyer_next_throw_wait(object);
	return child_record;
}

/* Waits 7 frames before the next shot and turns the flyer to its player. */
void kind_b8_flyer_next_throw_wait(uint16_t object)
{
	OBJECT(object)->timer = 7u;
	kind_b8_flyer_face_player(object);
}

/* Throws its single shots one after the other, still flying, then sends it flying again with a new wait. */
uint16_t kind_b8_flyer_single_throw(uint16_t object, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t child_record = 0, ignored16 = 0, ignored16_2 = 0;
	uint8_t timer = 0, shots_left = 0, shots_left_2 = 0;

	kind_b8_flyer_bob(object);
	kind_b8_flyer_steer(object);
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
	{
		kind_b8_flyer_face_player(object);
		return y;
	}
	shots_left = OBJECT(object)->kind_b8_flyer.shots_left;
	OBJECT(object)->kind_b8_flyer.shots_left = shots_left - 1u;
	if (shots_left == 1u)
	{
		OBJECT(object)->state = 2u;
		OBJECT(object)->animation = 0x80u;
		kind_b8_flyer_choose_throw_wait(object);
		return y;
	}
	OBJECT(object)->animation = 0x90u;
	shots_left_2 = OBJECT(object)->kind_b8_flyer.shots_left;
	child_record = kind_b8_single_shots[shots_left_2 & 1u];
	vector_spawn_child(object, child_record, &ignored16, &ignored16_2, &carry);
	kind_b8_flyer_next_throw_wait(object);
	return child_record;
}

/* The flyer's hit (step FF), by field 29. */
void kind_b8_flyer_hurt(uint16_t object)
{
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		kind_b8_flyer_hurt_start(object);
		return;
	case 2:
		kind_b8_flyer_hurt_shake(object);
		return;
	case 4:
		kind_b8_flyer_die_start(object);
		return;
	case 6:
		kind_b8_flyer_die_fall(object);
		return;
	case 8:
		kind_b8_flyer_die_end(object);
		return;
	}
}

/* Stops the hit flyer, keeps its height and plays its hurt animation for 30 frames with its sound. */
void kind_b8_flyer_hurt_start(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t action_step = 0;
	uint16_t z = 0;

	OBJECT(object)->flags = 0x88u;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->z_speed = 0;
	z = OBJECT(object)->z;
	OBJECT(object)->kind_b8_flyer.kept_height = z;
	OBJECT(object)->timer = 0x1Eu;
	command = 0x5300u;
	carry = vector_queue_sound(command);
	OBJECT(object)->animation = 0x89u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Shakes and flashes the hit flyer, then sends it flying again. */
void kind_b8_flyer_hurt_shake(uint16_t object)
{
	uint8_t attributes = 0;
	uint8_t timer = 0, timer_2 = 0, attributes_2 = 0, attributes_3 = 0, attributes_4 = 0;

	kind_b8_flyer_shake_height(object);
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
void kind_b8_flyer_die(uint16_t object)
{
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		kind_b8_flyer_die_start(object);
		return;
	case 2:
		kind_b8_flyer_die_fall(object);
		return;
	case 4:
		kind_b8_flyer_die_end(object);
		return;
	case -4:
		kind_b8_flyer_hurt_start(object);
		return;
	case -2:
		kind_b8_flyer_hurt_shake(object);
		return;
	}
}

/* Stops the beaten flyer with its sound and its falling animation. */
void kind_b8_flyer_die_start(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t action_step = 0;

	command = 0x5300u;
	carry = vector_queue_sound(command);
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->flags = 0x88u;
	OBJECT(object)->animation = 0x88u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Pulls the beaten flyer down; when it lands, plays a sound. */
void kind_b8_flyer_die_fall(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0, ignored16 = 0;
	uint8_t action_step = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	if (carry == 0u)
	{
		kind_b8_flyer_die_end(object);
		return;
	}
	command = 0x7700u;
	carry = vector_queue_sound(command);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	kind_b8_flyer_die_end(object);
}

/* Frees the flyer's slot when its animation ends. */
void kind_b8_flyer_die_end(uint16_t object)
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

/* Sets the hit flyer's height speed toward its kept height plus a shake from kind_b8_hurt_shakes. */
void kind_b8_flyer_shake_height(uint16_t object)
{
	uint8_t a = 0;
	uint8_t timer = 0;
	uint16_t kept_height = 0, z = 0;

	timer = OBJECT(object)->timer;
	kept_height = OBJECT(object)->kind_b8_flyer.kept_height;
	z = OBJECT(object)->z;
	OBJECT(object)->z_speed = (uint32_t)(uint16_t)(((uint32_t)a << 8) | (uint8_t)((((uint32_t)a << 8) | (uint8_t)((((uint32_t)a << 8) | kind_b8_hurt_shakes[timer & 3u]) + kept_height)) - z)) << 8;
}

/* Steers the flyer around its player: sweeps its heading back and forth on its side of him, follows his
   depth and keeps it on the screen. */
void kind_b8_flyer_steer(uint16_t object)
{
	uint8_t a = 0, b = 0;
	uint16_t target_player = 0;
	uint8_t sweep_way = 0, sweep_rate = 0, sweep_way_2 = 0, sweep_rate_2 = 0, sweep_way_3 = 0, sweep_way_4 = 0, sweep_rate_3 = 0, sweep_way_5 = 0, sweep_rate_4 = 0, sweep_way_6 = 0;
	uint16_t target = 0, t1 = 0, t2 = 0, t3 = 0, heading = 0, t4 = 0, heading_2 = 0, t5 = 0, t6 = 0, heading_3 = 0, t7 = 0, heading_4 = 0, t8 = 0, target_2 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0, y_speed = 0, t14 = 0, t15 = 0, t16 = 0, t17 = 0;

	target = OBJECT(object)->target;
	target_player = target;
	if ((frame_count & 0x7F00u) == 0u)
		target_player = vector_choose_nearest_player(object);
	t1 = OBJECT(object)->x;
	t2 = mem_read16(target_player + 0xCu);
	if (t1 < t2)
	{
		sweep_way = OBJECT(object)->kind_b8_flyer.sweep_way;
		if (sweep_way != 0u)
		{
			sweep_rate = OBJECT(object)->kind_b8_flyer.sweep_rate;
			t3 = 0u - sweep_rate;
			heading = OBJECT(object)->kind_b8_flyer.heading;
			t4 = t3 + heading;
			a = (t4 >> 8) & 0xFu;
			OBJECT(object)->kind_b8_flyer.heading = ((uint32_t)a << 8) | (uint8_t)t4;
			if (a == 0xCu)
			{
				sweep_way_2 = OBJECT(object)->kind_b8_flyer.sweep_way;
				OBJECT(object)->kind_b8_flyer.sweep_way = ~sweep_way_2;
			}
		}
		else
		{
			sweep_rate_2 = OBJECT(object)->kind_b8_flyer.sweep_rate;
			heading_2 = OBJECT(object)->kind_b8_flyer.heading;
			t5 = sweep_rate_2 + heading_2;
			a = (t5 >> 8) & 0xFu;
			OBJECT(object)->kind_b8_flyer.heading = ((uint32_t)a << 8) | (uint8_t)t5;
			if (a == 4u)
			{
				sweep_way_3 = OBJECT(object)->kind_b8_flyer.sweep_way;
				OBJECT(object)->kind_b8_flyer.sweep_way = ~sweep_way_3;
			}
		}
	}
	else
	{
		sweep_way_4 = OBJECT(object)->kind_b8_flyer.sweep_way;
		if (sweep_way_4 != 0u)
		{
			sweep_rate_3 = OBJECT(object)->kind_b8_flyer.sweep_rate;
			t6 = 0u - sweep_rate_3;
			heading_3 = OBJECT(object)->kind_b8_flyer.heading;
			t7 = t6 + heading_3;
			a = (t7 >> 8) & 0xFu;
			OBJECT(object)->kind_b8_flyer.heading = ((uint32_t)a << 8) | (uint8_t)t7;
			if (a == 4u)
			{
				sweep_way_5 = OBJECT(object)->kind_b8_flyer.sweep_way;
				OBJECT(object)->kind_b8_flyer.sweep_way = ~sweep_way_5;
			}
		}
		else
		{
			sweep_rate_4 = OBJECT(object)->kind_b8_flyer.sweep_rate;
			heading_4 = OBJECT(object)->kind_b8_flyer.heading;
			t8 = sweep_rate_4 + heading_4;
			a = (t8 >> 8) & 0xFu;
			OBJECT(object)->kind_b8_flyer.heading = ((uint32_t)a << 8) | (uint8_t)t8;
			if (a == 0xCu)
			{
				sweep_way_6 = OBJECT(object)->kind_b8_flyer.sweep_way;
				OBJECT(object)->kind_b8_flyer.sweep_way = ~sweep_way_6;
			}
		}
	}
	kind_b8_flyer_set_speeds(object);
	target_2 = OBJECT(object)->target;
	target_player = target_2;
	t9 = OBJECT(object)->y;
	t10 = OBJECT(target_player)->y;
	t11 = t9 - t10;
	a = (uint8_t)(t11 >> 8);
	steer_dy_high = a;
	t12 = ((uint32_t)a << 8) | (uint8_t)t11;
	t13 = t12 >> 15 ? 0u - t12 : t12;
	if (t13 >= 4u)
	{
		OBJECT(object)->y_speed = 0x100;
		if (steer_dy_high >= 0)
		{
			y_speed = OBJECT(object)->y_speed;
			OBJECT(object)->y_speed = 0u - y_speed;
		}
	}
	t14 = OBJECT(object)->x;
	a = (uint8_t)(t14 >> 8);
	b = (uint8_t)t14;
	if ((uint16_t)(((uint32_t)a << 8) | b) < 0x40u)
	{
		b = 0x40u;
		t15 = OBJECT(object)->x;
		OBJECT(object)->x_speed = (uint32_t)(uint8_t)((((uint32_t)a << 8) | b) - t15) << 8;
		t16 = OBJECT(object)->y;
		a = (uint8_t)(t16 >> 8);
		b = (uint8_t)t16;
		if ((uint16_t)(((uint32_t)a << 8) | b) < 0x90u)
		{
			b = 0x90u;
			t17 = OBJECT(object)->y;
			OBJECT(object)->y_speed = (uint32_t)(uint8_t)((((uint32_t)a << 8) | b) - t17) << 8;
			return;
		}
		if ((uint16_t)(((uint32_t)a << 8) | b) >= 0x100u)
		{
			b = 0xFFu;
			t17 = OBJECT(object)->y;
			OBJECT(object)->y_speed = (uint32_t)(uint8_t)((((uint32_t)a << 8) | b) - t17) << 8;
		}
		return;
	}
	if ((uint16_t)(((uint32_t)a << 8) | b) >= 0x180u)
	{
		b = 0x7Fu;
		t15 = OBJECT(object)->x;
		OBJECT(object)->x_speed = (uint32_t)(uint8_t)((((uint32_t)a << 8) | b) - t15) << 8;
	}
	t16 = OBJECT(object)->y;
	a = (uint8_t)(t16 >> 8);
	b = (uint8_t)t16;
	if ((uint16_t)(((uint32_t)a << 8) | b) < 0x90u)
	{
		b = 0x90u;
		t17 = OBJECT(object)->y;
		OBJECT(object)->y_speed = (uint32_t)(uint8_t)((((uint32_t)a << 8) | b) - t17) << 8;
		return;
	}
	if ((uint16_t)(((uint32_t)a << 8) | b) >= 0x100u)
	{
		b = 0xFFu;
		t17 = OBJECT(object)->y;
		OBJECT(object)->y_speed = (uint32_t)(uint8_t)((((uint32_t)a << 8) | b) - t17) << 8;
	}
}

/* Bobs the arriving flyer's height by kind_b8_bob_up. */
void kind_b8_flyer_bob_in(uint16_t object)
{
	uint8_t a = 0;
	uint8_t bob_phase = 0, bob_phase_2 = 0;
	uint16_t z = 0;

	bob_phase = OBJECT(object)->kind_b8_flyer.bob_phase;
	z = OBJECT(object)->z;
	OBJECT(object)->z_speed = (uint32_t)(uint16_t)(((uint32_t)a << 8) | (uint8_t)((((uint32_t)a << 8) | (uint8_t)((((uint32_t)a << 8) | kind_b8_bob_up[(int8_t)bob_phase]) + 0x40u)) - z)) << 8;
	bob_phase_2 = OBJECT(object)->kind_b8_flyer.bob_phase;
	OBJECT(object)->kind_b8_flyer.bob_phase = (bob_phase_2 + 1u) & 0x1Fu;
}

/* Bobs the flying flyer's height up and down by kind_b8_bob_down and kind_b8_bob_up. */
void kind_b8_flyer_bob(uint16_t object)
{
	uint8_t a = 0, phase = 0;
	uint16_t heights = 0;
	uint8_t bob_phase = 0, bob_phase_2 = 0;
	uint16_t z = 0;

	bob_phase = OBJECT(object)->kind_b8_flyer.bob_phase;
	phase = bob_phase;
	if ((phase & 0xE0u) != 0u)
		heights = kind_b8_bob_up_ADDRESS;
	else
		heights = kind_b8_bob_down_ADDRESS;
	z = OBJECT(object)->z;
	OBJECT(object)->z_speed = (uint32_t)(uint16_t)(((uint32_t)a << 8) | (uint8_t)((((uint32_t)a << 8) | (uint8_t)((((uint32_t)a << 8) | (uint8_t)BOB_HEIGHT(heights + (phase & 0x1Fu))) + 0x40u)) - z)) << 8;
	bob_phase_2 = OBJECT(object)->kind_b8_flyer.bob_phase;
	OBJECT(object)->kind_b8_flyer.bob_phase = bob_phase_2 + 1u;
}

/* Sets the flyer's x and y speeds by its heading from kind_b8_velocities. */
void kind_b8_flyer_set_speeds(uint16_t object)
{
	uint16_t speeds = 0;
	uint8_t t1 = 0;
	uint16_t x_speed = 0, y_speed = 0;

	t1 = (uint8_t)(OBJECT(object)->kind_b8_flyer.heading >> 8u);
	speeds = kind_b8_velocities_ADDRESS + (int8_t)(((uint32_t)t1 << 1) << 1);
	x_speed = VELOCITY(speeds)->x_speed;
	OBJECT(object)->x_speed = x_speed;
	y_speed = VELOCITY(speeds)->y_speed;
	OBJECT(object)->y_speed = y_speed;
}

/* Picks the frames before the flyer's next throw at random from kind_b8_shot_waits. */
void kind_b8_flyer_choose_throw_wait(uint16_t object)
{
	uint8_t random_byte = 0;
	uint16_t roll = 0;

	roll = vector_next_random_byte(0u);
	random_byte = (uint8_t)(roll >> 8);
	OBJECT(object)->timer = (uint8_t)(VELOCITY(kind_b8_velocities_ADDRESS + (random_byte & 3u) - 0x4u)->x_speed >> 8u);
}

/* Sets the shot up with its animation by its state, thrown up with one of four x speeds at random. */
void kind_b8_shot_setup(uint16_t object, uint16_t *p_y, uint16_t *p_shot_speeds)
{
	uint16_t setup = 0, shot_speeds = 0, y = 0;
	uint8_t parameter = 0, attributes = 0, attributes_2 = 0, state = 0;
	uint16_t t1 = 0, x_speed = 0;

	setup = kind_b8_shot_object_setup_ADDRESS;
	y = vector_object_setup(object, setup);
	OBJECT(object)->flags = 0x80u;
	parameter = OBJECT(object)->parameter;
	OBJECT(object)->animation = kind_b8_shot_animations[(int8_t)parameter];
	OBJECT(object)->z_speed = 0x400;
	shot_speeds = kind_b8_shot_speeds_ADDRESS;
	t1 = kind_b8_shot_speeds[random_number & 3u];
	OBJECT(object)->x_speed = t1;
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
	*p_y = y;
	*p_shot_speeds = shot_speeds;
}

/* Pulls the shot down; where it lands it bursts (hit sparks), able to hurt for 2 frames. */
void kind_b8_shot_fall(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;
	uint8_t state = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	if (carry)
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
void kind_b8_shot_burst(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->flags = 0x80u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	kind_b8_shot_remove(object);
}

/* Frees the shot's slot when its burst ends. */
void kind_b8_shot_remove(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	OBJECT(object)->flags = 0u;
}
