/**
 *    Name:        enemies/cloud_devil.c
 *    Description: stage 6's devil on a cloud (type F2) and its lightning bolt (4D40 type 28)
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Sets the lightning bolt up below the cloud with its sound. */
uint16_t lightning_bolt_setup(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0, setup = 0;
	uint8_t attributes = 0, state = 0;
	uint16_t z = 0, t1 = 0;

	setup = lightning_bolt_object_setup_ADDRESS;
	vector_object_setup(object, setup);
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0x10u;
	z = OBJECT(object)->z;
	t1 = z - 0x30u;
	OBJECT(object)->z = t1;
	command = 0x4C00u;
	carry = vector_queue_sound(command);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return setup;
}

/* Frees the bolt's slot when its animation ends. */
void lightning_bolt_end(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
		OBJECT(object)->flags = 0u;
}

/* Sets the devil up, hidden, at its height, with its x, heading and sweep from the kind_c7 tables by its
   state and 600 frames to stay. */
uint16_t cloud_devil_setup(uint16_t object)
{
	uint8_t variant = 0;
	uint16_t setup = 0, y = 0;
	uint8_t parameter = 0, parameter_2 = 0, state = 0;
	uint16_t t1 = 0;

	setup = cloud_devil_object_setup_ADDRESS;
	y = vector_object_setup(object, setup);
	OBJECT(object)->flags = 4u;
	parameter = OBJECT(object)->parameter;
	variant = parameter;
	OBJECT(object)->cloud_devil.sweep_way = kind_c7_sweep_ways[(int8_t)variant];
	OBJECT(object)->cloud_devil.heading = (OBJECT(object)->cloud_devil.heading & 0xFFu) | ((kind_c7_headings[(int8_t)variant] & 0xFFu) << 8u);
	OBJECT(object)->cloud_devil.sweep_rate = kind_c7_sweep_rates[(int8_t)variant];
	parameter_2 = OBJECT(object)->parameter;
	t1 = kind_c7_start_x[(int8_t)((uint8_t)((uint32_t)parameter_2 << 1)) / 2];
	OBJECT(object)->x = t1;
	OBJECT(object)->z = 0x40u;
	OBJECT(object)->timer = 0x80u;
	OBJECT(object)->cloud_devil.stay_time = 0x258u;
	vector_choose_nearest_player(object);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return y;
}

/* The devil's way in, by field 29. */
void cloud_devil_come_in(uint16_t object)
{
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		cloud_devil_appear(object);
		return;
	case 2:
		cloud_devil_start_flying(object);
		return;
	case 4:
		cloud_devil_wait_to_fly(object);
		return;
	case 6:
		cloud_devil_hurt_start(object);
		return;
	case 8:
		cloud_devil_hurt_shake(object);
		return;
	case 10:
		cloud_devil_die_start(object);
		return;
	case 12:
		cloud_devil_die_fall(object);
		return;
	case 14:
		cloud_devil_die_end(object);
		return;
	}
}

/* Shows the devil appearing, bobbing, with a sound. */
void cloud_devil_appear(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t action_step = 0;

	cloud_devil_bob_in(object);
	OBJECT(object)->flags = 0x88u;
	command = 0x6C00u;
	carry = vector_queue_sound(command);
	OBJECT(object)->animation = 0x84u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* When it has appeared, sets the devil flying at the nearest player with a wait before its first bolt. */
void cloud_devil_start_flying(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t animation_flags = 0, parameter = 0, parameter_2 = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	OBJECT(object)->animation = 0x81u;
	parameter = OBJECT(object)->parameter;
	if (parameter != 3u)
	{
		parameter_2 = OBJECT(object)->parameter;
		if (parameter_2 == 2u)
		{
			command = 0x4B00u;
			carry = vector_queue_sound(command);
		}
		cloud_devil_take_off(object);
		return;
	}
	OBJECT(object)->timer = 8u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Counts a short wait down before the devil flies. */
void cloud_devil_wait_to_fly(uint16_t object)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	cloud_devil_take_off(object);
}

/* Makes the devil hittable and sends it flying at the nearest player, with its first wait before a bolt
   and its speeds. */
void cloud_devil_take_off(uint16_t object)
{
	uint8_t state = 0;

	OBJECT(object)->flags = 0xC8u;
	vector_choose_nearest_player(object);
	cloud_devil_choose_shot_wait(object);
	cloud_devil_set_speeds(object);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	OBJECT(object)->action = 0u;
	OBJECT(object)->action_step = 0u;
}

/* Flies the devil around its player, bobbing, until its next bolt is due, then turns it to face him;
   when its stay (field 2C) is over, it rises off the screen and goes. */
void cloud_devil_fly(uint16_t object)
{
	uint8_t attributes = 0;
	uint8_t timer = 0, state = 0, attributes_2 = 0, attributes_3 = 0;
	uint16_t stay_time = 0, z = 0, stay_time_2 = 0, target = 0, t1 = 0, t2 = 0;

	stay_time = OBJECT(object)->cloud_devil.stay_time;
	if (stay_time == 0u)
	{
		cloud_devil_steer(object);
		OBJECT(object)->z_speed = 0x100;
		z = OBJECT(object)->z;
		if (z >= 0x100u)
			OBJECT(object)->flags = 0u;
		return;
	}
	stay_time_2 = OBJECT(object)->cloud_devil.stay_time;
	OBJECT(object)->cloud_devil.stay_time = stay_time_2 - 1u;
	cloud_devil_bob(object);
	cloud_devil_steer(object);
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->timer = 1u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	if (OBJECT(object)->flags == 0u)
		return;
	target = OBJECT(object)->target;
	t1 = OBJECT(object)->x;
	t2 = OBJECT(target)->x;
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

/* Stops the devil and plays its lightning animation for 64 frames. */
void cloud_devil_stop_to_shoot(uint16_t object)
{
	uint8_t state = 0;

	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->z_speed = 0;
	OBJECT(object)->animation = 0x83u;
	OBJECT(object)->timer = 0x40u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Counts down, then puts in a lightning bolt under the cloud. */
uint16_t cloud_devil_drop_bolt(uint16_t object, uint16_t child_record)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0;
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return child_record;
	child_record = cloud_devil_drop_bolt_child_ADDRESS;
	vector_spawn_child(object, child_record, &ignored16, &ignored16_2, &carry);
	OBJECT(object)->timer = 0x20u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return child_record;
}

/* Counts down, then sends the devil flying again with a new wait before its next bolt. */
void cloud_devil_resume(uint16_t object)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->state = 2u;
		OBJECT(object)->animation = 0x81u;
		cloud_devil_choose_shot_wait(object);
	}
}

/* The devil's hit (step FF), by field 29. */
void cloud_devil_hurt(uint16_t object)
{
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		cloud_devil_hurt_start(object);
		return;
	case 2:
		cloud_devil_hurt_shake(object);
		return;
	case 4:
		cloud_devil_die_start(object);
		return;
	case 6:
		cloud_devil_die_fall(object);
		return;
	case 8:
		cloud_devil_die_end(object);
		return;
	case -6:
		cloud_devil_appear(object);
		return;
	case -4:
		cloud_devil_start_flying(object);
		return;
	case -2:
		cloud_devil_wait_to_fly(object);
		return;
	}
}

/* Stops the hit devil, keeps its height and plays its hurt animation for 30 frames, with the hit sound. */
void cloud_devil_hurt_start(uint16_t object)
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
	OBJECT(object)->cloud_devil.kept_height = z;
	OBJECT(object)->timer = 0x1Eu;
	command = 0x6300u;
	carry = vector_queue_sound(command);
	OBJECT(object)->animation = 0x85u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Shakes and flashes the hit devil, then sends it flying again. */
void cloud_devil_hurt_shake(uint16_t object)
{
	uint8_t attributes = 0;
	uint8_t timer = 0, timer_2 = 0, attributes_2 = 0, attributes_3 = 0, attributes_4 = 0;

	cloud_devil_shake_height(object);
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
	OBJECT(object)->animation = 0x81u;
	OBJECT(object)->state = 2u;
	OBJECT(object)->flags = 0xC8u;
	OBJECT(object)->animation_flags = 0x80u;
	OBJECT(object)->timer = 0x10u;
}

/* The beaten devil (step FE), by field 29. */
void cloud_devil_die(uint16_t object)
{
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		cloud_devil_die_start(object);
		return;
	case 2:
		cloud_devil_die_fall(object);
		return;
	case 4:
		cloud_devil_die_end(object);
		return;
	case -10:
		cloud_devil_appear(object);
		return;
	case -8:
		cloud_devil_start_flying(object);
		return;
	case -6:
		cloud_devil_wait_to_fly(object);
		return;
	case -4:
		cloud_devil_hurt_start(object);
		return;
	case -2:
		cloud_devil_hurt_shake(object);
		return;
	}
}

/* Stops the beaten devil with the hit sound and its falling animation. */
void cloud_devil_die_start(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t action_step = 0;

	OBJECT(object)->flags = 0x88u;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->z_speed = 0;
	command = 0x6300u;
	carry = vector_queue_sound(command);
	OBJECT(object)->animation = 0x86u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Pulls the beaten devil down; when it lands, with a sound, plays its last animation. */
void cloud_devil_die_fall(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0, ignored16 = 0;
	uint8_t points = 0, action_step = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	if (carry == 0u)
		return;
	points = OBJECT(object)->points;
	OBJECT(object)->points = points | 0x80u;
	command = 0x4800u;
	carry = vector_queue_sound(command);
	OBJECT(object)->animation = 0x88u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Frees the devil's slot when its last animation ends. */
void cloud_devil_die_end(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
		OBJECT(object)->flags = 0u;
}

/* Sets the hit devil's height speed toward its kept height plus a shake from kind_c7_hurt_shakes. */
void cloud_devil_shake_height(uint16_t object)
{
	uint8_t a = 0;
	uint8_t timer = 0;
	uint16_t kept_height = 0, z = 0;

	timer = OBJECT(object)->timer;
	kept_height = OBJECT(object)->cloud_devil.kept_height;
	z = OBJECT(object)->z;
	OBJECT(object)->z_speed = (uint32_t)(uint16_t)(((uint32_t)a << 8) | (uint8_t)((((uint32_t)a << 8) | (uint8_t)((((uint32_t)a << 8) | kind_c7_hurt_shakes[timer & 3u]) + kept_height)) - z)) << 8;
}

/* Steers the devil around its player: sweeps its heading back and forth on its side of him, follows his
   depth and keeps it on the screen. */
void cloud_devil_steer(uint16_t object)
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
		sweep_way = OBJECT(object)->cloud_devil.sweep_way;
		if (sweep_way != 0u)
		{
			sweep_rate = OBJECT(object)->cloud_devil.sweep_rate;
			t3 = 0u - sweep_rate;
			heading = OBJECT(object)->cloud_devil.heading;
			t4 = t3 + heading;
			a = (t4 >> 8) & 0xFu;
			OBJECT(object)->cloud_devil.heading = ((uint32_t)a << 8) | (uint8_t)t4;
			if (a == 0xCu)
			{
				sweep_way_2 = OBJECT(object)->cloud_devil.sweep_way;
				OBJECT(object)->cloud_devil.sweep_way = ~sweep_way_2;
			}
		}
		else
		{
			sweep_rate_2 = OBJECT(object)->cloud_devil.sweep_rate;
			heading_2 = OBJECT(object)->cloud_devil.heading;
			t5 = sweep_rate_2 + heading_2;
			a = (t5 >> 8) & 0xFu;
			OBJECT(object)->cloud_devil.heading = ((uint32_t)a << 8) | (uint8_t)t5;
			if (a == 4u)
			{
				sweep_way_3 = OBJECT(object)->cloud_devil.sweep_way;
				OBJECT(object)->cloud_devil.sweep_way = ~sweep_way_3;
			}
		}
	}
	else
	{
		sweep_way_4 = OBJECT(object)->cloud_devil.sweep_way;
		if (sweep_way_4 != 0u)
		{
			sweep_rate_3 = OBJECT(object)->cloud_devil.sweep_rate;
			t6 = 0u - sweep_rate_3;
			heading_3 = OBJECT(object)->cloud_devil.heading;
			t7 = t6 + heading_3;
			a = (t7 >> 8) & 0xFu;
			OBJECT(object)->cloud_devil.heading = ((uint32_t)a << 8) | (uint8_t)t7;
			if (a == 4u)
			{
				sweep_way_5 = OBJECT(object)->cloud_devil.sweep_way;
				OBJECT(object)->cloud_devil.sweep_way = ~sweep_way_5;
			}
		}
		else
		{
			sweep_rate_4 = OBJECT(object)->cloud_devil.sweep_rate;
			heading_4 = OBJECT(object)->cloud_devil.heading;
			t8 = sweep_rate_4 + heading_4;
			a = (t8 >> 8) & 0xFu;
			OBJECT(object)->cloud_devil.heading = ((uint32_t)a << 8) | (uint8_t)t8;
			if (a == 0xCu)
			{
				sweep_way_6 = OBJECT(object)->cloud_devil.sweep_way;
				OBJECT(object)->cloud_devil.sweep_way = ~sweep_way_6;
			}
		}
	}
	cloud_devil_set_speeds(object);
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
	if ((uint16_t)(((uint32_t)a << 8) | b) < 0x60u)
	{
		b = 0x60u;
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
	if ((uint16_t)(((uint32_t)a << 8) | b) >= 0x160u)
	{
		b = 0x5Fu;
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

/* Bobs the appearing devil's height by kind_c7_bob_up. */
void cloud_devil_bob_in(uint16_t object)
{
	uint8_t a = 0;
	uint8_t bob_phase = 0, bob_phase_2 = 0;
	uint16_t z = 0;

	bob_phase = OBJECT(object)->cloud_devil.bob_phase;
	z = OBJECT(object)->z;
	OBJECT(object)->z_speed = (uint32_t)(uint16_t)(((uint32_t)a << 8) | (uint8_t)((((uint32_t)a << 8) | (uint8_t)((((uint32_t)a << 8) | kind_c7_bob_up[(int8_t)bob_phase]) + 0x40u)) - z)) << 8;
	bob_phase_2 = OBJECT(object)->cloud_devil.bob_phase;
	OBJECT(object)->cloud_devil.bob_phase = (bob_phase_2 + 1u) & 0x1Fu;
}

/* Bobs the flying devil's height up and down by kind_c7_bob_down and kind_c7_bob_up. */
void cloud_devil_bob(uint16_t object)
{
	uint8_t a = 0, phase = 0;
	uint16_t heights = 0;
	uint8_t bob_phase = 0, bob_phase_2 = 0;
	uint16_t z = 0;

	bob_phase = OBJECT(object)->cloud_devil.bob_phase;
	phase = bob_phase;
	if ((phase & 0xE0u) != 0u)
		heights = kind_c7_bob_up_ADDRESS;
	else
		heights = kind_c7_bob_down_ADDRESS;
	z = OBJECT(object)->z;
	OBJECT(object)->z_speed = (uint32_t)(uint16_t)(((uint32_t)a << 8) | (uint8_t)((((uint32_t)a << 8) | (uint8_t)((((uint32_t)a << 8) | (uint8_t)BOB_HEIGHT(heights + (phase & 0x1Fu))) + 0x40u)) - z)) << 8;
	bob_phase_2 = OBJECT(object)->cloud_devil.bob_phase;
	OBJECT(object)->cloud_devil.bob_phase = bob_phase_2 + 1u;
}

/* Sets the devil's x and y speeds by its heading, slow while it circles its player, fast otherwise. */
void cloud_devil_set_speeds(uint16_t object)
{
	uint16_t speeds = 0;
	uint8_t state = 0, t1 = 0;
	uint16_t x_speed = 0, y_speed = 0;

	state = OBJECT(object)->state;
	if (state != 2u)
		speeds = kind_c7_fast_velocities_ADDRESS;
	else
		speeds = kind_c7_slow_velocities_ADDRESS;
	t1 = (uint8_t)(OBJECT(object)->cloud_devil.heading >> 8u);
	speeds += (int8_t)(((uint32_t)t1 << 1) << 1);
	x_speed = VELOCITY(speeds)->x_speed;
	OBJECT(object)->x_speed = x_speed;
	y_speed = VELOCITY(speeds)->y_speed;
	OBJECT(object)->y_speed = y_speed;
}

/* Picks the frames before the devil's next bolt at random from kind_c7_shot_waits. */
void cloud_devil_choose_shot_wait(uint16_t object)
{
	uint8_t random_byte = 0;
	uint16_t roll = 0;

	roll = vector_next_random_byte(0u);
	random_byte = (uint8_t)(roll >> 8);
	OBJECT(object)->timer = (uint8_t)(VELOCITY(kind_c7_slow_velocities_ADDRESS + (random_byte & 3u) - 0x4u)->x_speed >> 8u);
}
