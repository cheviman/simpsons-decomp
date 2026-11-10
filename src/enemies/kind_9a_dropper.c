/**
 *    Name:        enemies/kind_9a_dropper.c
 *    Description: stage 3's kind 9A object that hangs above and drops on the players
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* The kind 9A object's hit (step FF) by field 29: it shakes, then falls. */
void kind_9a_dropper_hurt(uint16_t object, uint16_t *p_y, uint16_t *p_step_handlers)
{
	uint16_t y = (uint16_t)*p_y;
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
			break;
		case 2:
			kind_9a_dropper_hurt_flash(object);
			break;
		case -56:
			step_handlers = zombie_start_coming_out(object);
			break;
		case -54:
			zombie_finish_rising(object);
			break;
		case -52:
			zombie_finish_climbing(object);
			break;
		case -50:
			zombie_remove_when_sunk(object);
			break;
		case -48:
			zombie_walk_in(object);
			break;
		case -46:
			zombie_burrow_start(object);
			break;
		case -44:
			zombie_burrow_move(object);
			break;
		case -42:
			zombie_burrow_surface(object);
			break;
		case -40:
			zombie_burrow_end(object);
			break;
		case -38:
			zombie_leap_start(object);
			break;
		case -36:
			zombie_leap_take_off(object);
			break;
		case -34:
			y = zombie_leap_rise(object, y);
			break;
		case -32:
			y = zombie_leap_fall(object, y);
			break;
		case -30:
			zombie_leap_turn(object);
			break;
		case -28:
			zombie_leap_end(object);
			break;
		case -26:
			zombie_swipe_start(object);
			break;
		case -24:
			y = zombie_swipe_hit(object, y);
			break;
		case -22:
			y = zombie_swipe_recover(object);
			break;
		case -20:
			zombie_swipe_step_back(object);
			break;
		case -18:
			zombie_swipe_end(object);
			break;
		case -16:
			kind_9a_dropper_fall(object, &y, &step_handlers);
			break;
		case -14:
			continue;
		case -12:
			kind_9a_dropper_setup(object, &y, &step_handlers);
			break;
		case -10:
			kind_9a_dropper_wait_mode(object);
			break;
		case -8:
			step_handlers = kind_9a_dropper_watch(object, step_handlers);
			break;
		case -6:
			kind_9a_dropper_drop(object, &y, &step_handlers);
			break;
		case -4:
			y = kind_9a_dropper_hang(object, y);
			break;
		case -2:
			kind_9a_dropper_climb(object);
			break;
		}
		break;
	}
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* Stops the hit object with the hit sound and a short wait. */
void kind_9a_dropper_hurt_start(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t action_step = 0;

	OBJECT(object)->z_speed = 0;
	OBJECT(object)->flags = 0x88u;
	OBJECT(object)->timer = 8u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	command = 0x6300u;
	carry = vector_queue_sound(command);
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
void kind_9a_dropper_fall(uint16_t object, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t command = 0, ignored16 = 0, u_2 = 0, y_2 = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	if (carry == 0u)
		return;
	OBJECT(object)->entrance_pending = 0u;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->z_speed = 0;
	OBJECT(object)->shadow_player = 0u;
	OBJECT(object)->enemy_class = 0;
	u_2 = vector_choose_nearest_player(object);
	command = 0x6C00u;
	carry = vector_queue_sound(command);
	vector_measure_target(object, u_2);
	spawn_kind_90_effect(object);
	vector_enemy_hurt_become_goon(object, &y_2, &u_2);
	OBJECT(object)->vitality = 1u;
	*p_y = y_2;
	*p_u = u_2;
}

/* Sets the kind 9A object up out of the enemy count, with its x offset and its mode from
   kind_9a_drop_starts, keeping its place along the stage in field 2A. */
void kind_9a_dropper_setup(uint16_t object, uint16_t *p_y, uint16_t *p_start)
{
	uint16_t setup = 0, start = 0, y = 0;
	uint8_t enemy_class = 0, parameter = 0, state = 0;
	uint16_t x_offset = 0, unused = 0, t1 = 0, t2 = 0;

	setup = kind_9a_dropper_object_setup_ADDRESS;
	y = vector_object_setup(object, setup);
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
	t1 = OBJECT(object)->x;
	t2 = t1 + camera_x;
	OBJECT(object)->kind_9a_dropper.stage_x = t2;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	*p_y = y;
	*p_start = start;
}

/* In mode 0 starts watching for players; in mode 1 lets it fall (step FE) once it comes onto the
   screen's left part. */
void kind_9a_dropper_wait_mode(uint16_t object)
{
	uint8_t parameter = 0, state = 0;
	uint16_t t1 = 0;

	parameter = OBJECT(object)->parameter;
	if (parameter == 0u)
	{
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
		return;
	}
	t1 = OBJECT(object)->x;
	if (t1 < 0x100u)
		OBJECT(object)->state = 0xFEu;
}

/* Every 4 frames looks for the nearest player; within 64 pixels across and in depth, drops toward him
   from its place, with a sound. */
uint16_t kind_9a_dropper_watch(uint16_t object, uint16_t u)
{
	uint32_t carry = 0;
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
			carry = vector_queue_sound(command);
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
void kind_9a_dropper_drop(uint16_t object, uint16_t *p_box, uint16_t *p_nearest_player)
{
	uint16_t box = (uint16_t)*p_box;
	uint16_t nearest_player = (uint16_t)*p_nearest_player;
	uint8_t state = 0;
	uint16_t z = 0;

	z = OBJECT(object)->z;
	if (z >= 0x10u)
		return;
	OBJECT(object)->timer = (random_number & 0x1Fu) + 8u;
	OBJECT(object)->z_speed = 0;
	OBJECT(object)->animation = 0x80u;
	box = kind_9a_dropper_drop_box_ADDRESS;
	vector_set_hit_box(object, box);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	nearest_player = vector_choose_nearest_player(object);
	vector_measure_target(object, nearest_player);
	vector_face_direction(object);
	*p_box = box;
	*p_nearest_player = nearest_player;
}

/* Counts its time down at the bottom, then sends it climbing back up with its plain hit box. */
uint16_t kind_9a_dropper_hang(uint16_t object, uint16_t box)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return box;
	box = kind_9a_dropper_body_box_ADDRESS;
	vector_set_hit_box(object, box);
	OBJECT(object)->animation = 0x81u;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->z_speed = 0x200;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return box;
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
