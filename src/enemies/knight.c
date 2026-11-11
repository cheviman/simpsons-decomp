/**
 *    Name:        enemies/knight.c
 *    Description: stage 6's knight (type F5) and its action 3C
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* The knight beaten in its first form, by field 29: it falls and comes back as its fighting kind. */
uint32_t knight_lose_first_form(uint16_t object, uint32_t left_caller)
{
	uint16_t ignored16 = 0;
	uint8_t action_step = 0;

	for (;;)
	{
		action_step = OBJECT(object)->action_step;
		switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
		{
		case 0:
			knight_fall(object);
			return left_caller;
		case 2:
			break;
		case -14:
			continue;
		case -12:
			knight_setup(object);
			return left_caller;
		case -10:
			knight_come_in(object);
			return left_caller;
		case -8:
			vector_enemy_think(object, &ignored16, &left_caller);
			return left_caller;
		case -6:
			vector_enemy_act(object, &ignored16, &left_caller);
			return left_caller;
		case -4:
			enemy_hurt(object);
			return left_caller;
		case -2:
			vector_enemy_climb(object, &ignored16, &left_caller);
			return left_caller;
		}
		break;
	}
	knight_get_up(object);
	return left_caller;
}

/* Pulls the beaten knight down; when it lands, puts in what it leaves behind (4D40 type 09) and plays
   animation 88. */
void knight_fall(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, target_player = 0;
	uint8_t action_step = 0;
	uint16_t target = 0;

	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	vector_apply_gravity(object, &ignored16, &carry);
	if (carry == 0u)
		return;
	leftover_y = knight_fall_child_ADDRESS;
	vector_spawn_child(object, &ignored16_2, &ignored16_3, &ignored16, &carry);
	OBJECT(object)->animation = 0x88u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	target = OBJECT(object)->target;
	target_player = target;
	vector_enemy_leave_side(object, target_player);
}

/* When that animation ends, the knight takes its fighting kind (field 50) with one vitality point and
   fights again. */
void knight_get_up(uint16_t object)
{
	uint8_t animation_flags = 0, fighting_kind = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		fighting_kind = OBJECT(object)->knight.fighting_kind;
		OBJECT(object)->kind = fighting_kind;
		OBJECT(object)->animation = 0x80u;
		OBJECT(object)->flags = 0xC0u;
		OBJECT(object)->state = 2u;
		OBJECT(object)->vitality = 1u;
		OBJECT(object)->action = 0u;
		OBJECT(object)->action_step = 0u;
		OBJECT(object)->parameter = 0u;
		OBJECT(object)->knight.first_form = 0u;
	}
}

/* Sets the knight up with its behaviour knight_behaviour in its first form: with state bit 7 hidden,
   with the entrance kind, wait, fighting kind and x from knight_entrances; otherwise fighting at once. */
void knight_setup(uint16_t object)
{
	uint8_t variant = 0;
	uint16_t entrance = 0, setup = 0;
	uint8_t first_form = 0, parameter = 0, kind = 0, parameter_2 = 0, state = 0;
	uint16_t wait = 0, kind_2 = 0, start_x = 0;

	setup = knight_object_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->knight.vanishes = 1u;
	first_form = OBJECT(object)->knight.first_form;
	OBJECT(object)->knight.first_form = first_form + 1u;
	OBJECT(object)->behaviour = 0x7C7Fu;
	OBJECT(object)->retarget_time = 0x10u;
	OBJECT(object)->floor_z = 0u;
	entrance = knight_entrances_ADDRESS;
	parameter = OBJECT(object)->parameter;
	variant = parameter;
	if ((int8_t)parameter >= 0)
	{
		entrance += (int8_t)(((uint32_t)variant << 1) << 1);
		kind = KNIGHT_ENTRANCE(entrance)->kind;
		OBJECT(object)->knight.fighting_kind = kind;
		OBJECT(object)->parameter = 0u;
		OBJECT(object)->state = 2u;
		return;
	}
	OBJECT(object)->flags = 4u;
	parameter_2 = OBJECT(object)->parameter;
	entrance += (int8_t)(((uint32_t)parameter_2 << 1) << 1);
	wait = (((uint32_t)KNIGHT_ENTRANCE(entrance)->wait << 8u) | KNIGHT_ENTRANCE(entrance)->entrance_kind);
	OBJECT(object)->timer = wait >> 8;
	OBJECT(object)->kind = wait;
	kind_2 = (((uint32_t)KNIGHT_ENTRANCE(entrance)->kind << 8u) | KNIGHT_ENTRANCE(entrance)->x);
	OBJECT(object)->knight.fighting_kind = kind_2 >> 8;
	start_x = (kind_2 & 0xFFu) << 4;
	OBJECT(object)->x = start_x;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* The knight's way in, by field 29 (knight_entrance_styles gives where it starts). */
void knight_come_in(uint16_t object)
{
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		knight_choose_entrance(object);
		return;
	case 2:
		knight_jump_in(object);
		return;
	case 4:
	case 16:
		knight_jump_rise(object);
		return;
	case 6:
	case 18:
		knight_jump_land(object);
		return;
	case 8:
		knight_walk_in_start(object);
		return;
	case 10:
		knight_walk_in(object);
		return;
	case 12:
		knight_walk_in_end(object);
		return;
	case 14:
		knight_jump_in_straight(object);
		return;
	case 20:
		knight_leap_in(object);
		return;
	case 22:
		knight_leap_rise(object);
		return;
	case 24:
		knight_leap_land(object);
		return;
	}
}

/* Takes the step the knight's way in starts at and its slowdown from knight_entrance_styles. */
void knight_choose_entrance(uint16_t object)
{
	uint8_t parameter = 0;
	uint16_t step = 0;

	parameter = OBJECT(object)->parameter;
	step = (((uint32_t)KNIGHT_ENTRANCE_STYLE(knight_entrance_styles_ADDRESS + (int8_t)((uint32_t)parameter << 1))->step << 8u) | KNIGHT_ENTRANCE_STYLE(knight_entrance_styles_ADDRESS + (int8_t)((uint32_t)parameter << 1))->slowdown);
	OBJECT(object)->action_step = step >> 8;
	OBJECT(object)->knight.entrance_slowdown = step & 0xFFu;
	OBJECT(object)->parameter = 0u;
}

/* After its wait, the knight jumps in from the front, big (zoom 8080), with a sound. */
void knight_jump_in(uint16_t object)
{
	uint16_t command = 0;
	uint8_t timer = 0, action_step = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	command = 0x301u;
	vector_queue_sound(command);
	OBJECT(object)->flags = 0x98u;
	OBJECT(object)->zoom_x = 0x80u;
	OBJECT(object)->zoom_y = 0x80u;
	OBJECT(object)->attributes = 0x20u;
	OBJECT(object)->x_speed = 0x80;
	OBJECT(object)->z_speed = 0x300;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Shrinks the jumping knight and slows its rise; once it falls, moves it toward the front. */
void knight_jump_rise(uint16_t object)
{
	uint16_t z_speed = 0;
	uint8_t action_step = 0;
	uint16_t z_speed_2 = 0;

	knight_shrink(object);
	z_speed_2 = OBJECT(object)->z_speed;
	z_speed = z_speed_2 - 0x10u;
	OBJECT(object)->z_speed = z_speed;
	if ((int16_t)z_speed < 0)
	{
		OBJECT(object)->y_speed = -0x80;
		OBJECT(object)->attributes = 0x10u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* Shrinks the knight and pulls it down until it lands with a sound, then makes it hittable and lets it
   fight. */
void knight_jump_land(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t state = 0;
	uint16_t z_speed = 0;

	knight_shrink(object);
	z_speed = OBJECT(object)->z_speed;
	OBJECT(object)->z_speed = z_speed - 0x20u;
	carry = vector_check_landing(object);
	if (carry == 0u)
		return;
	command = 0x2000u;
	vector_queue_sound(command);
	OBJECT(object)->flags = 0xC0u;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->z_speed = 0;
	OBJECT(object)->action = 0u;
	OBJECT(object)->action_step = 0u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Shrinks the jumping knight a step until its zoom is back to 4040. */
void knight_shrink(uint16_t object)
{
	uint16_t new_flags = 0, zoom_x = 0;
	uint16_t zoom_x_2 = 0;

	zoom_x_2 = (((uint32_t)OBJECT(object)->zoom_x << 8u) | OBJECT(object)->zoom_y);
	zoom_x = zoom_x_2 - 0x101u;
	if (zoom_x < 0x4040u)
		new_flags = 0x8800u;
	else
	{
		OBJECT(object)->zoom_x = (uint8_t)(zoom_x >> 8u);
		OBJECT(object)->zoom_y = (uint8_t)zoom_x;
		new_flags = 0x9800u;
	}
	OBJECT(object)->flags = new_flags >> 8;
}

/* Shows the knight that walks in from the right. */
void knight_walk_in_start(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->attributes = 0x50u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* When the scroll brings the knight on, walks it in from the right toward the front for 32 frames. */
void knight_walk_in(uint16_t object)
{
	uint8_t action_step = 0;
	uint16_t knight_x = 0;

	knight_x = OBJECT(object)->x;
	if (knight_x < 0x160u)
	{
		OBJECT(object)->x_speed = -0x40;
		OBJECT(object)->y_speed = -0x80;
		OBJECT(object)->animation = 0x81u;
		OBJECT(object)->timer = 0x20u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* Counts the walk down, then makes the knight hittable and lets it fight. */
void knight_walk_in_end(uint16_t object)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->flags = 0xC0u;
		OBJECT(object)->state = 2u;
	}
}

/* After its wait, the knight jumps in from the front straight up, big, with a sound. */
void knight_jump_in_straight(uint16_t object)
{
	uint16_t command = 0;
	uint8_t timer = 0, action_step = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	command = 0x301u;
	vector_queue_sound(command);
	OBJECT(object)->flags = 0x98u;
	OBJECT(object)->zoom_x = 0x80u;
	OBJECT(object)->zoom_y = 0x80u;
	OBJECT(object)->attributes = 0x20u;
	OBJECT(object)->z_speed = 0x300;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* After its wait, the knight leaps in from the front fast across, big, with a sound. */
void knight_leap_in(uint16_t object)
{
	uint16_t command = 0;
	uint8_t timer = 0, action_step = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	command = 0x301u;
	vector_queue_sound(command);
	OBJECT(object)->flags = 0x98u;
	OBJECT(object)->zoom_x = 0x80u;
	OBJECT(object)->zoom_y = 0x80u;
	OBJECT(object)->attributes = 0x20u;
	OBJECT(object)->x_speed = 0x400;
	OBJECT(object)->z_speed = 0x200;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Shrinks the leaping knight and slows it; once it falls, moves it toward the front with a sound. */
void knight_leap_rise(uint16_t object)
{
	uint16_t command = 0, z_speed = 0;
	uint8_t action_step = 0;
	uint16_t x_speed = 0, z_speed_2 = 0;

	knight_shrink(object);
	x_speed = OBJECT(object)->x_speed;
	OBJECT(object)->x_speed = x_speed - 0x10u;
	z_speed_2 = OBJECT(object)->z_speed;
	z_speed = z_speed_2 - 0x10u;
	OBJECT(object)->z_speed = z_speed;
	if ((int16_t)z_speed >= 0)
		return;
	command = 0x2000u;
	vector_queue_sound(command);
	OBJECT(object)->y_speed = -0x80;
	OBJECT(object)->attributes = 0x10u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Shrinks the knight, slows it by its slowdown (field 3E) and pulls it down until it lands with a sound,
   then lets it fight. */
void knight_leap_land(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t state = 0;
	uint16_t x_speed = 0, entrance_slowdown = 0, z_speed = 0;

	knight_shrink(object);
	x_speed = OBJECT(object)->x_speed;
	entrance_slowdown = OBJECT(object)->knight.entrance_slowdown;
	OBJECT(object)->x_speed = x_speed - entrance_slowdown;
	z_speed = OBJECT(object)->z_speed;
	OBJECT(object)->z_speed = z_speed - 0x20u;
	carry = vector_check_landing(object);
	if (carry == 0u)
		return;
	command = 0x2000u;
	vector_queue_sound(command);
	OBJECT(object)->flags = 0xC0u;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->z_speed = 0;
	OBJECT(object)->action = 0u;
	OBJECT(object)->action_step = 0u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Starts the knight's blow, turned to its player. */
void knight_strike_start(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->animation = 0x90u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	face_target(object);
}

/* On the blow's marked frame, gives the knight its attacking hit box. */
void knight_strike_hit(uint16_t object)
{
	uint8_t animation_flags = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) == 0u)
		return;
	leftover_y = knight_strike_hit_box_ADDRESS;
	vector_set_hit_box(object);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	knight_strike_end(object);
}

/* When the blow ends, gives the knight back its plain hit box and ends the action. */
void knight_strike_end(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	leftover_y = knight_body_box_ADDRESS;
	vector_set_hit_box(object);
	OBJECT(object)->state = 2u;
	OBJECT(object)->timer = 0u;
}
