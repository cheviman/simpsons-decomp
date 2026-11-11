/**
 *    Name:        enemies/kind_9a_dropper.c
 *    Description: stage 3's kind 9A object that hangs above and drops on the players
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* The kind 9A object's hit (step FF) by field 29: it shakes, then falls. */
uint16_t kind_9a_dropper_hurt(uint16_t object)
{
	uint16_t step_handlers = 0;
	uint8_t action_step = 0;

	for (;;)
	{
		step_handlers = kind_9a_dropper_hurt_steps_ADDRESS;
		action_step = OBJECT(object)->action_step;
		switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
		{
		case 0:
			kind_9a_dropper_hurt_start(object);
			return step_handlers;
		case 2:
			break;
		case -56:
			return zombie_start_coming_out(object);
		case -54:
			zombie_finish_rising(object);
			return step_handlers;
		case -52:
			zombie_finish_climbing(object);
			return step_handlers;
		case -50:
			zombie_remove_when_sunk(object);
			return step_handlers;
		case -48:
			zombie_walk_in(object);
			return step_handlers;
		case -46:
			zombie_burrow_start(object);
			return step_handlers;
		case -44:
			zombie_burrow_move(object);
			return step_handlers;
		case -42:
			zombie_burrow_surface(object);
			return step_handlers;
		case -40:
			zombie_burrow_end(object);
			return step_handlers;
		case -38:
			zombie_leap_start(object);
			return step_handlers;
		case -36:
			zombie_leap_take_off(object);
			return step_handlers;
		case -34:
			zombie_leap_rise(object);
			return step_handlers;
		case -32:
			zombie_leap_fall(object);
			return step_handlers;
		case -30:
			zombie_leap_turn(object);
			return step_handlers;
		case -28:
			zombie_leap_end(object);
			return step_handlers;
		case -26:
			zombie_swipe_start(object);
			return step_handlers;
		case -24:
			zombie_swipe_hit(object);
			return step_handlers;
		case -22:
			zombie_swipe_recover(object);
			return step_handlers;
		case -20:
			zombie_swipe_step_back(object);
			return step_handlers;
		case -18:
			zombie_swipe_end(object);
			return step_handlers;
		case -16:
			return kind_9a_dropper_fall(object, step_handlers);
		case -14:
			continue;
		case -12:
			return kind_9a_dropper_setup(object);
		case -10:
			kind_9a_dropper_wait_mode(object);
			return step_handlers;
		case -8:
			return kind_9a_dropper_watch(object, step_handlers);
		case -6:
			return kind_9a_dropper_drop(object, step_handlers);
		case -4:
			kind_9a_dropper_hang(object);
			return step_handlers;
		case -2:
			kind_9a_dropper_climb(object);
			return step_handlers;
		}
		break;
	}
	kind_9a_dropper_hurt_flash(object);
	return step_handlers;
}

/* Stops the hit object with the hit sound and a short wait. */
void kind_9a_dropper_hurt_start(uint16_t object)
{
	uint16_t command = 0;
	uint8_t action_step = 0;

	OBJECT(object)->z_speed = 0;
	OBJECT(object)->flags = 0x88u;
	OBJECT(object)->timer = 8u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	command = 0x6300u;
	vector_queue_sound(command);
}

/* Flashes the hit object for 8 frames, then lets it fall (step FE). */
void kind_9a_dropper_hurt_flash(uint16_t object)
{
	uint8_t timer = 0, attributes = 0, attributes_2 = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
	{
		attributes = OBJECT(object)->attributes;
		OBJECT(object)->attributes = attributes ^ 0x80u;
		OBJECT(object)->animation_flags = 0x80u;
		return;
	}
	OBJECT(object)->state = 0xFEu;
	OBJECT(object)->timer = 1u;
	attributes_2 = OBJECT(object)->attributes;
	OBJECT(object)->attributes = attributes_2 & 0x7Fu;
	OBJECT(object)->animation_flags = 0x80u;
}

/* Pulls the beaten object down; when it lands, with a thud, it is knocked out like a beaten enemy (stars
   and the knocked-down animation), left one vitality point. */
uint16_t kind_9a_dropper_fall(uint16_t object, uint16_t behaviour_address)
{
	uint32_t carry = 0;
	uint16_t command = 0, ignored16 = 0, nearest_player = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	if (carry == 0u)
		return behaviour_address;
	OBJECT(object)->entrance_pending = 0u;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->z_speed = 0;
	OBJECT(object)->shadow_player = 0u;
	OBJECT(object)->enemy_class = 0;
	nearest_player = vector_choose_nearest_player(object);
	command = 0x6C00u;
	vector_queue_sound(command);
	vector_measure_target(object, nearest_player);
	spawn_kind_90_effect(object);
	behaviour_address = vector_enemy_hurt_become_goon(object);
	OBJECT(object)->vitality = 1u;
	return behaviour_address;
}

/* Sets the kind 9A object up out of the enemy count, with its x offset and its mode from
   kind_9a_drop_starts, keeping its place along the stage in field 2A. */
uint16_t kind_9a_dropper_setup(uint16_t object)
{
	uint16_t setup = 0, start = 0;
	uint8_t enemy_class = 0, parameter = 0, state = 0;
	uint16_t x_offset = 0, unused = 0, dropper_x = 0, place_in_stage = 0;

	setup = kind_9a_dropper_object_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->flags = 0xC8u;
	OBJECT(object)->box_depth = 0x10u;
	OBJECT(object)->shadow_player = 1u;
	OBJECT(object)->floor_z = 0u;
	OBJECT(object)->entrance_pending = 1u;
	enemy_class = OBJECT(object)->enemy_class;
	OBJECT(object)->enemy_class = enemy_class - 1u;
	parameter = OBJECT(object)->parameter;
	start = kind_9a_drop_starts_ADDRESS + (int8_t)(((uint32_t)parameter << 1) << 1);
	x_offset = DROP_START(start)->x_offset;
	OBJECT(object)->kind_9a_dropper.drop_x_offset = x_offset;
	unused = (((uint32_t)DROP_START(start)->unused << 8u) | DROP_START(start)->mode);
	OBJECT(object)->kind_9a_dropper.drop_unused = unused >> 8;
	OBJECT(object)->parameter = unused;
	dropper_x = OBJECT(object)->x;
	place_in_stage = dropper_x + camera_x;
	OBJECT(object)->kind_9a_dropper.stage_x = place_in_stage;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return start;
}

/* In mode 0 starts watching for players; in mode 1 lets it fall (step FE) once it comes onto the
   screen's left part. */
void kind_9a_dropper_wait_mode(uint16_t object)
{
	uint8_t parameter = 0, state = 0;
	uint16_t dropper_x = 0;

	parameter = OBJECT(object)->parameter;
	if (parameter == 0u)
	{
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
		return;
	}
	dropper_x = OBJECT(object)->x;
	if (dropper_x < 0x100u)
		OBJECT(object)->state = 0xFEu;
}

/* Every 4 frames looks for the nearest player; within 64 pixels across and in depth, drops toward him
   from its place, with a sound. */
uint16_t kind_9a_dropper_watch(uint16_t object, uint16_t u)
{
	uint16_t command = 0;
	uint8_t state = 0;
	uint16_t target_dx = 0, target_dy = 0, stage_x = 0, drop_x_offset = 0, drop_x_offset_2 = 0;

	if ((((uint16_t)((uint32_t)(uint8_t)frame_count << 8) >> 8) & 3u) != 0u)
		return u;
	u = vector_choose_nearest_player(object);
	vector_measure_target(object, u);
	target_dx = OBJECT(object)->target_dx;
	if (target_dx < 0x40u)
	{
		target_dy = OBJECT(object)->target_dy;
		if (target_dy < 0x40u)
		{
			OBJECT(object)->animation_flags = 0x80u;
			OBJECT(object)->flags = 0xC8u;
			stage_x = OBJECT(object)->kind_9a_dropper.stage_x;
			drop_x_offset = OBJECT(object)->kind_9a_dropper.drop_x_offset;
			OBJECT(object)->x = stage_x - camera_x + drop_x_offset;
			drop_x_offset_2 = OBJECT(object)->kind_9a_dropper.drop_x_offset;
			OBJECT(object)->kind_9a_dropper.drop_x_offset = 0u - drop_x_offset_2;
			OBJECT(object)->z_speed = -0x200;
			command = 0x5000u;
			vector_queue_sound(command);
			state = OBJECT(object)->state;
			OBJECT(object)->state = state + 1u;
			vector_face_direction(object);
			return u;
		}
	}
	return u;
}

/* When it has dropped near the ground, stops it there for a random 8 to 39 frames with its attacking hit
   box, facing the player. */
uint16_t kind_9a_dropper_drop(uint16_t object, uint16_t u)
{
	uint16_t nearest_player = 0;
	uint8_t state = 0;
	uint16_t z = 0;

	z = OBJECT(object)->z;
	if (z >= 0x10u)
		return u;
	OBJECT(object)->timer = (random_number & 0x1Fu) + 8u;
	OBJECT(object)->z_speed = 0;
	OBJECT(object)->animation = 0x80u;
	leftover_y = kind_9a_dropper_drop_box_ADDRESS;
	vector_set_hit_box(object);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	nearest_player = vector_choose_nearest_player(object);
	vector_measure_target(object, nearest_player);
	vector_face_direction(object);
	return nearest_player;
}

/* Counts its time down at the bottom, then sends it climbing back up with its plain hit box. */
void kind_9a_dropper_hang(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	leftover_y = kind_9a_dropper_body_box_ADDRESS;
	vector_set_hit_box(object);
	OBJECT(object)->animation = 0x81u;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->z_speed = 0x200;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Stops it at the top and makes it watch for players again. */
void kind_9a_dropper_climb(uint16_t object)
{
	uint16_t z = 0;

	z = OBJECT(object)->z;
	if (z >= 0x80u)
	{
		OBJECT(object)->z_speed = 0;
		OBJECT(object)->state = 2u;
	}
}
