/**
 *    Name:        enemies/reactions.c
 *    Description: the enemies' shared reactions: spun away, defeated and knocked into the distance, fallen into a pit
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Lets the spinning enemy fall; once it lands it stops and lies down (it gets up, or dies with no
   vitality left). */
void enemy_spin_land(uint16_t object)
{
	uint32_t landed = 0;
	uint16_t z_speed = 0;

	z_speed = OBJECT(object)->z_speed;
	OBJECT(object)->z_speed = z_speed - 0x20u;
	landed = vector_check_landing(object);
	if (landed == 0u)
		return;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	enemy_die_or_get_up(object);
}

/* Action 8: the enemy hit from the front by an attack of kind 13 spins away backwards, by its step. */
void enemy_spin_backward(uint16_t object, uint8_t step, uint16_t *p_step_handlers, uint32_t *p_left_caller)
{
	uint16_t step_handlers = 0;
	uint32_t left_caller = 0;

	step_handlers = enemy_spin_backward_steps_ADDRESS;
	left_caller = 0u;
	switch ((int8_t)(uint8_t)((uint32_t)step << 1))
	{
	case 0:
		enemy_spin_backward_start(object);
		break;
	case -4:
	case 2:
		enemy_sent_flying_step(object);
		break;
	case -2:
	case 4:
		enemy_spin_land(object);
		break;
	case 6:
		enemy_defeated_forward_start(object);
		break;
	case 8:
	case 14:
		enemy_defeated_fly(object);
		break;
	case 10:
	case 16:
		enemy_defeated_shrink(object, &step_handlers, &left_caller);
		break;
	case 12:
		enemy_defeated_backward_start(object);
		break;
	case 18:
		enemy_pit_start(object);
		break;
	case 20:
		enemy_pit_fall(object, &step_handlers, &left_caller);
		break;
	case -38:
		enemy_flinch_from_behind_start(object);
		break;
	case -36:
	case -32:
	case -28:
	case -14:
		enemy_back_to_thinking_after_animation(object);
		break;
	case -34:
		enemy_flinch_kind_12_start(object);
		break;
	case -30:
		enemy_flinch_kind_11_start(object);
		break;
	case -26:
		enemy_knocked_forward_start(object);
		break;
	case -24:
		enemy_knocked_fall(object);
		break;
	case -22:
		enemy_knocked_back_start(object);
		break;
	case -20:
		enemy_knocked_back_fall(object);
		break;
	case -18:
		enemy_lie_then_get_up(object);
		break;
	case -16:
		enemy_get_up_start(object);
		break;
	case -12:
		enemy_die_start(object);
		break;
	case -10:
		enemy_die_blink(object, &step_handlers, &left_caller);
		break;
	case -8:
		enemy_drop_fall(object);
		break;
	case -6:
		enemy_sent_flying_start(object);
		break;
	}
	if (left_caller != 0u)
		left_caller = 0u;
	else
		vector_stop_at_screen_edges(object);
	*p_step_handlers = step_handlers;
	*p_left_caller = left_caller;
}

/* Starts the backward spin: the hit's sound, the spin animation (97), x speed 2 backwards (kept to start
   it again after a wall) and a time of 20 frames. */
void enemy_spin_backward_start(uint16_t object)
{
	uint16_t command = 0;
	uint8_t attributes = 0, action_step = 0;
	uint16_t x_speed = 0, x_speed_2 = 0;

	OBJECT(object)->timer = 0x20u;
	command = 0x6300u;
	vector_queue_sound(command);
	OBJECT(object)->animation = 0x97u;
	OBJECT(object)->x_speed = -0x200;
	OBJECT(object)->y_speed = 0;
	attributes = OBJECT(object)->attributes;
	if ((attributes & 0x40u) != 0u)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	x_speed_2 = OBJECT(object)->x_speed;
	OBJECT(object)->enemy_spin.spin_x_speed = x_speed_2;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Action 0A: the enemy defeated from behind is knocked forwards and away, by its step. */
void enemy_defeated_forward(uint16_t object, uint8_t step, uint16_t *p_step_handlers, uint32_t *p_left_caller)
{
	uint16_t step_handlers = 0;
	uint32_t left_caller = 0;

	step_handlers = enemy_defeated_forward_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step << 1))
	{
	case 0:
		left_caller = 0u;
		enemy_defeated_forward_start(object);
		break;
	case 2:
	case 8:
		left_caller = 0u;
		enemy_defeated_fly(object);
		break;
	case 4:
	case 10:
		enemy_defeated_shrink(object, &step_handlers, &left_caller);
		break;
	case 6:
		left_caller = 0u;
		enemy_defeated_backward_start(object);
		break;
	case 12:
		left_caller = 0u;
		enemy_pit_start(object);
		break;
	case 14:
		enemy_pit_fall(object, &step_handlers, &left_caller);
		break;
	case -44:
		left_caller = 0u;
		enemy_flinch_from_behind_start(object);
		break;
	case -42:
	case -38:
	case -34:
	case -20:
		left_caller = 0u;
		enemy_back_to_thinking_after_animation(object);
		break;
	case -40:
		left_caller = 0u;
		enemy_flinch_kind_12_start(object);
		break;
	case -36:
		left_caller = 0u;
		enemy_flinch_kind_11_start(object);
		break;
	case -32:
		left_caller = 0u;
		enemy_knocked_forward_start(object);
		break;
	case -30:
		left_caller = 0u;
		enemy_knocked_fall(object);
		break;
	case -28:
		left_caller = 0u;
		enemy_knocked_back_start(object);
		break;
	case -26:
		left_caller = 0u;
		enemy_knocked_back_fall(object);
		break;
	case -24:
		left_caller = 0u;
		enemy_lie_then_get_up(object);
		break;
	case -22:
		left_caller = 0u;
		enemy_get_up_start(object);
		break;
	case -18:
		left_caller = 0u;
		enemy_die_start(object);
		break;
	case -16:
		enemy_die_blink(object, &step_handlers, &left_caller);
		break;
	case -14:
		left_caller = 0u;
		enemy_drop_fall(object);
		break;
	case -12:
		left_caller = 0u;
		enemy_sent_flying_start(object);
		break;
	case -10:
	case -4:
		left_caller = 0u;
		enemy_sent_flying_step(object);
		break;
	case -8:
	case -2:
		left_caller = 0u;
		enemy_spin_land(object);
		break;
	case -6:
		left_caller = 0u;
		enemy_spin_backward_start(object);
		break;
	}
	*p_step_handlers = step_handlers;
	*p_left_caller = left_caller;
}

/* Starts the forward knock: animation 8E and x speed 0080 forwards. */
void enemy_defeated_forward_start(uint16_t object)
{
	OBJECT(object)->animation = 0x8Eu;
	OBJECT(object)->x_speed = 0x80;
	enemy_defeated_launch(object);
}

/* Launches the defeated enemy: shown with its shadow and not hit any more, the hit's sound, up at z
   speed 0200, along the floor at y speed 0100 (the other way, and for less time, when its y is less than
   00A0 from the camera's), across the way it was knocked. */
void enemy_defeated_launch(uint16_t object)
{
	uint16_t command = 0;
	uint8_t attributes = 0, action_step = 0;
	uint16_t enemy_y = 0, screen_y = 0, y_speed = 0, x_speed = 0;

	OBJECT(object)->flags = 0x88u;
	command = 0x6300u;
	vector_queue_sound(command);
	OBJECT(object)->z_speed = 0x200;
	OBJECT(object)->y_speed = 0x100;
	OBJECT(object)->timer = 0x68u;
	enemy_y = OBJECT(object)->y;
	screen_y = enemy_y - camera_y;
	if (screen_y < 0xA0u)
	{
		OBJECT(object)->timer = 0x48u;
		y_speed = OBJECT(object)->y_speed;
		OBJECT(object)->y_speed = 0u - y_speed;
	}
	attributes = OBJECT(object)->attributes;
	if ((attributes & 0x40u) != 0u)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Flies the defeated enemy: when it lands it blinks out; when it is over a place with no floor it starts
   going into the distance, without its shadow, at the sprites' priority 20 when its y speed is not
   negative. */
void enemy_defeated_fly(uint16_t object)
{
	uint32_t negative = 0, landed = 0;
	uint8_t floor_value = 0;
	uint16_t floor_cell = 0;
	uint8_t y_speed = 0, attributes = 0, action_step = 0;
	uint16_t z_speed = 0, falling_z_speed = 0;

	z_speed = OBJECT(object)->z_speed;
	falling_z_speed = z_speed - 0x20u;
	OBJECT(object)->z_speed = falling_z_speed;
	landed = vector_check_landing(object);
	if (landed)
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0;
		OBJECT(object)->action = 5u;
		OBJECT(object)->action_step = 0u;
		return;
	}
	floor_cell = 0u;
	vector_floor_at_offset(object, &floor_cell, &negative);
	floor_value = (uint8_t)(floor_cell >> 8);
	if ((int8_t)floor_value >= 0)
		return;
	y_speed = (uint8_t)(OBJECT(object)->y_speed >> 8u);
	if ((int8_t)y_speed >= 0)
	{
		attributes = OBJECT(object)->attributes;
		OBJECT(object)->attributes = (attributes & 0xCFu) | 0x20u;
	}
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->zoom_x = 0x40u;
	OBJECT(object)->zoom_y = 0x40u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Lets the defeated enemy fall into the distance, smaller each frame for its last 18 frames, with the
   falling sound at 40; at the end it is gone and its points scored. */
void enemy_defeated_shrink(uint16_t object, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t command = 0, z_speed = 0;
	uint32_t left_caller = 0;
	uint8_t timer = 0, timer_2 = 0, timer_3 = 0;
	uint16_t z_speed_2 = 0, falling_z_speed = 0, zoom_x = 0;
	uint32_t zoom_x_halfword = 0;

	z_speed_2 = OBJECT(object)->z_speed;
	falling_z_speed = z_speed_2 - 0x20u;
	z_speed = falling_z_speed;
	if ((int16_t)falling_z_speed >= 0 || z_speed >= 0xFC00u)
		OBJECT(object)->z_speed = z_speed;
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
	{
		timer_2 = OBJECT(object)->timer;
		if ((uint16_t)((uint32_t)timer_2 << 8) >> 8 < 0x18u)
		{
			OBJECT(object)->y_speed = 0;
			OBJECT(object)->flags = 0x90u;
			zoom_x = (((uint32_t)OBJECT(object)->zoom_x << 8u) | OBJECT(object)->zoom_y);
			zoom_x_halfword = zoom_x + 0x101u;
			OBJECT(object)->zoom_x = (uint8_t)(zoom_x_halfword >> 8u);
			OBJECT(object)->zoom_y = (uint8_t)zoom_x_halfword;
		}
		timer_3 = OBJECT(object)->timer;
		if ((uint16_t)((uint32_t)timer_3 << 8) >> 8 != 0x40u)
			left_caller = 0u;
		else
		{
			command = 0x301u;
			left_caller = 0u;
			vector_queue_sound(command);
		}
	}
	else
	{
		OBJECT(object)->flags = 0u;
		u = vector_enemy_score_and_release(object, u);
		left_caller = 1u;
	}
	*p_u = u;
	*p_left_caller = left_caller;
}

/* Action 0B: the enemy defeated from the front is knocked backwards and away, by its step. */
void enemy_defeated_backward(uint16_t object, uint8_t step, uint16_t *p_step_handlers, uint32_t *p_left_caller)
{
	uint16_t step_handlers = 0;
	uint32_t left_caller = 0;

	step_handlers = enemy_defeated_backward_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step << 1))
	{
	case 0:
		left_caller = 0u;
		enemy_defeated_backward_start(object);
		break;
	case -4:
	case 2:
		left_caller = 0u;
		enemy_defeated_fly(object);
		break;
	case -2:
	case 4:
		enemy_defeated_shrink(object, &step_handlers, &left_caller);
		break;
	case 6:
		left_caller = 0u;
		enemy_pit_start(object);
		break;
	case 8:
		enemy_pit_fall(object, &step_handlers, &left_caller);
		break;
	case -50:
		left_caller = 0u;
		enemy_flinch_from_behind_start(object);
		break;
	case -48:
	case -44:
	case -40:
	case -26:
		left_caller = 0u;
		enemy_back_to_thinking_after_animation(object);
		break;
	case -46:
		left_caller = 0u;
		enemy_flinch_kind_12_start(object);
		break;
	case -42:
		left_caller = 0u;
		enemy_flinch_kind_11_start(object);
		break;
	case -38:
		left_caller = 0u;
		enemy_knocked_forward_start(object);
		break;
	case -36:
		left_caller = 0u;
		enemy_knocked_fall(object);
		break;
	case -34:
		left_caller = 0u;
		enemy_knocked_back_start(object);
		break;
	case -32:
		left_caller = 0u;
		enemy_knocked_back_fall(object);
		break;
	case -30:
		left_caller = 0u;
		enemy_lie_then_get_up(object);
		break;
	case -28:
		left_caller = 0u;
		enemy_get_up_start(object);
		break;
	case -24:
		left_caller = 0u;
		enemy_die_start(object);
		break;
	case -22:
		enemy_die_blink(object, &step_handlers, &left_caller);
		break;
	case -20:
		left_caller = 0u;
		enemy_drop_fall(object);
		break;
	case -18:
		left_caller = 0u;
		enemy_sent_flying_start(object);
		break;
	case -16:
	case -10:
		left_caller = 0u;
		enemy_sent_flying_step(object);
		break;
	case -14:
	case -8:
		left_caller = 0u;
		enemy_spin_land(object);
		break;
	case -12:
		left_caller = 0u;
		enemy_spin_backward_start(object);
		break;
	case -6:
		left_caller = 0u;
		enemy_defeated_forward_start(object);
		break;
	}
	*p_step_handlers = step_handlers;
	*p_left_caller = left_caller;
}

/* Starts the backward knock: animation 8C and x speed 0080 backwards. */
void enemy_defeated_backward_start(uint16_t object)
{
	OBJECT(object)->animation = 0x8Cu;
	OBJECT(object)->x_speed = -0x80;
	enemy_defeated_launch(object);
}

/* Action 0C: the enemy over a place with no floor falls into the pit, by its step. */
void enemy_pit(uint16_t object, uint8_t step, uint16_t *p_step_handlers, uint32_t *p_left_caller)
{
	uint16_t step_handlers = 0;
	uint32_t left_caller = 0;

	step_handlers = enemy_pit_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step << 1))
	{
	case 0:
		left_caller = 0u;
		enemy_pit_start(object);
		break;
	case 2:
		enemy_pit_fall(object, &step_handlers, &left_caller);
		break;
	case -56:
		left_caller = 0u;
		enemy_flinch_from_behind_start(object);
		break;
	case -54:
	case -50:
	case -46:
	case -32:
		left_caller = 0u;
		enemy_back_to_thinking_after_animation(object);
		break;
	case -52:
		left_caller = 0u;
		enemy_flinch_kind_12_start(object);
		break;
	case -48:
		left_caller = 0u;
		enemy_flinch_kind_11_start(object);
		break;
	case -44:
		left_caller = 0u;
		enemy_knocked_forward_start(object);
		break;
	case -42:
		left_caller = 0u;
		enemy_knocked_fall(object);
		break;
	case -40:
		left_caller = 0u;
		enemy_knocked_back_start(object);
		break;
	case -38:
		left_caller = 0u;
		enemy_knocked_back_fall(object);
		break;
	case -36:
		left_caller = 0u;
		enemy_lie_then_get_up(object);
		break;
	case -34:
		left_caller = 0u;
		enemy_get_up_start(object);
		break;
	case -30:
		left_caller = 0u;
		enemy_die_start(object);
		break;
	case -28:
		enemy_die_blink(object, &step_handlers, &left_caller);
		break;
	case -26:
		left_caller = 0u;
		enemy_drop_fall(object);
		break;
	case -24:
		left_caller = 0u;
		enemy_sent_flying_start(object);
		break;
	case -22:
	case -16:
		left_caller = 0u;
		enemy_sent_flying_step(object);
		break;
	case -20:
	case -14:
		left_caller = 0u;
		enemy_spin_land(object);
		break;
	case -18:
		left_caller = 0u;
		enemy_spin_backward_start(object);
		break;
	case -12:
		left_caller = 0u;
		enemy_defeated_forward_start(object);
		break;
	case -10:
	case -4:
		left_caller = 0u;
		enemy_defeated_fly(object);
		break;
	case -8:
	case -2:
		enemy_defeated_shrink(object, &step_handlers, &left_caller);
		break;
	case -6:
		left_caller = 0u;
		enemy_defeated_backward_start(object);
		break;
	}
	*p_step_handlers = step_handlers;
	*p_left_caller = left_caller;
}

/* Starts the fall into the pit: no vitality left, a time of 40 frames. */
void enemy_pit_start(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->timer = 0x40u;
	OBJECT(object)->vitality = 0u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Drops the enemy into the pit, with the falling sound, at the sprites' priority 20 once below the
   floor; at the end it is gone and its points scored. */
void enemy_pit_fall(uint16_t object, uint16_t *p_target, uint32_t *p_left_caller)
{
	uint16_t target = (uint16_t)*p_target;
	uint8_t z_speed_high = 0, z_speed_low = 0;
	uint16_t command = 0;
	uint8_t timer = 0, timer_2 = 0, attributes = 0;
	uint16_t z_speed = 0, falling_z_speed = 0, z = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
	{
		timer_2 = OBJECT(object)->timer;
		if (timer_2 == 0x38u)
		{
			command = 0x301u;
			vector_queue_sound(command);
		}
		z_speed = OBJECT(object)->z_speed;
		falling_z_speed = z_speed - 0x40u;
		z_speed_low = (uint8_t)falling_z_speed;
		z_speed_high = (uint8_t)(falling_z_speed >> 8);
		if ((int16_t)falling_z_speed >= 0 || (uint16_t)(((uint32_t)z_speed_high << 8) | (z_speed_low & 0xFFu)) >= 0xFC00u)
			OBJECT(object)->z_speed = ((uint32_t)z_speed_high << 8) | (z_speed_low & 0xFFu);
		z = OBJECT(object)->z;
		if ((int16_t)z < 0)
		{
			attributes = OBJECT(object)->attributes;
			OBJECT(object)->attributes = (attributes & 0xCFu) | 0x20u;
		}
		*p_left_caller = 0u;
	}
	else
	{
		OBJECT(object)->flags = 0u;
		target = vector_enemy_score_and_release(object, target);
		*p_left_caller = 1u;
	}
	*p_target = target;
}
