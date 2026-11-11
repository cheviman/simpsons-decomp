/**
 *    Name:        enemies/enemy_hit_reactions.c
 *    Description: flinching, knocked down, getting up, dying (they go on in fixed_3F to 07E1CC)
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Unused: queues sound command 6300. */
void unused_enemy_hit_sound(void)
{
	uint16_t command = 0;

	command = 0x6300u;
	vector_queue_sound(command);
}

/* Reaction 0, a hit from behind: a hit sound and its flinch, then back to thinking. */
void enemy_flinch_from_behind(uint16_t object, uint8_t step, uint16_t *p_step_handlers, uint32_t *p_left_caller)
{
	uint16_t step_handlers = 0;
	uint32_t left_caller = 0;

	step_handlers = enemy_flinch_from_behind_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step << 1))
	{
	case 0:
		left_caller = 0u;
		enemy_flinch_from_behind_start(object);
		break;
	case 2:
	case 6:
	case 10:
	case 24:
		left_caller = 0u;
		enemy_back_to_thinking_after_animation(object);
		break;
	case 4:
		left_caller = 0u;
		enemy_flinch_kind_12_start(object);
		break;
	case 8:
		left_caller = 0u;
		enemy_flinch_kind_11_start(object);
		break;
	case 12:
		left_caller = 0u;
		enemy_knocked_forward_start(object);
		break;
	case 14:
		left_caller = 0u;
		enemy_knocked_fall(object);
		break;
	case 16:
		left_caller = 0u;
		enemy_knocked_back_start(object);
		break;
	case 18:
		left_caller = 0u;
		enemy_knocked_back_fall(object);
		break;
	case 20:
		left_caller = 0u;
		enemy_lie_then_get_up(object);
		break;
	case 22:
		left_caller = 0u;
		enemy_get_up_start(object);
		break;
	case 26:
		left_caller = 0u;
		enemy_die_start(object);
		break;
	case 28:
		enemy_die_blink(object, &step_handlers, &left_caller);
		break;
	case 30:
		left_caller = 0u;
		enemy_drop_fall(object);
		break;
	case 32:
		left_caller = 0u;
		enemy_sent_flying_start(object);
		break;
	case 34:
	case 40:
		left_caller = 0u;
		enemy_sent_flying_step(object);
		break;
	case 36:
	case 42:
		left_caller = 0u;
		enemy_spin_land(object);
		break;
	case 38:
		left_caller = 0u;
		enemy_spin_backward_start(object);
		break;
	case 44:
		left_caller = 0u;
		enemy_defeated_forward_start(object);
		break;
	case 46:
	case 52:
		left_caller = 0u;
		enemy_defeated_fly(object);
		break;
	case 48:
	case 54:
		enemy_defeated_shrink(object, &step_handlers, &left_caller);
		break;
	case 50:
		left_caller = 0u;
		enemy_defeated_backward_start(object);
		break;
	case 56:
		left_caller = 0u;
		enemy_pit_start(object);
		break;
	case 58:
		enemy_pit_fall(object, &step_handlers, &left_caller);
		break;
	}
	*p_step_handlers = step_handlers;
	*p_left_caller = left_caller;
}

/* The hit sound, stopped, the flinch animation from behind. */
void enemy_flinch_from_behind_start(uint16_t object)
{
	uint16_t command = 0;
	uint8_t action_step = 0;

	command = 0x6300u;
	vector_queue_sound(command);
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->animation = 0x8Bu;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Once its animation has ended: back in the hit checks with its hit box, thinking. */
void enemy_back_to_thinking_after_animation(uint16_t object)
{
	uint8_t animation_flags = 0;
	uint16_t hit_box = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	OBJECT(object)->flags = 0xC0u;
	hit_box = OBJECT(object)->hit_box;
	leftover_y = hit_box;
	vector_set_hit_box(object);
	OBJECT(object)->state = 2u;
	OBJECT(object)->timer = 0u;
}

/* Reaction 1, a hit of kind 12 from the front: a hit sound and its flinch, then back to thinking. */
void enemy_flinch_kind_12(uint16_t object, uint8_t step, uint16_t *p_step_handlers, uint32_t *p_left_caller)
{
	uint16_t step_handlers = 0;
	uint32_t left_caller = 0;

	step_handlers = enemy_flinch_kind_12_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step << 1))
	{
	case 0:
		left_caller = 0u;
		enemy_flinch_kind_12_start(object);
		break;
	case -2:
	case 2:
	case 6:
	case 20:
		left_caller = 0u;
		enemy_back_to_thinking_after_animation(object);
		break;
	case 4:
		left_caller = 0u;
		enemy_flinch_kind_11_start(object);
		break;
	case 8:
		left_caller = 0u;
		enemy_knocked_forward_start(object);
		break;
	case 10:
		left_caller = 0u;
		enemy_knocked_fall(object);
		break;
	case 12:
		left_caller = 0u;
		enemy_knocked_back_start(object);
		break;
	case 14:
		left_caller = 0u;
		enemy_knocked_back_fall(object);
		break;
	case 16:
		left_caller = 0u;
		enemy_lie_then_get_up(object);
		break;
	case 18:
		left_caller = 0u;
		enemy_get_up_start(object);
		break;
	case 22:
		left_caller = 0u;
		enemy_die_start(object);
		break;
	case 24:
		enemy_die_blink(object, &step_handlers, &left_caller);
		break;
	case 26:
		left_caller = 0u;
		enemy_drop_fall(object);
		break;
	case 28:
		left_caller = 0u;
		enemy_sent_flying_start(object);
		break;
	case 30:
	case 36:
		left_caller = 0u;
		enemy_sent_flying_step(object);
		break;
	case 32:
	case 38:
		left_caller = 0u;
		enemy_spin_land(object);
		break;
	case 34:
		left_caller = 0u;
		enemy_spin_backward_start(object);
		break;
	case 40:
		left_caller = 0u;
		enemy_defeated_forward_start(object);
		break;
	case 42:
	case 48:
		left_caller = 0u;
		enemy_defeated_fly(object);
		break;
	case 44:
	case 50:
		enemy_defeated_shrink(object, &step_handlers, &left_caller);
		break;
	case 46:
		left_caller = 0u;
		enemy_defeated_backward_start(object);
		break;
	case 52:
		left_caller = 0u;
		enemy_pit_start(object);
		break;
	case 54:
		enemy_pit_fall(object, &step_handlers, &left_caller);
		break;
	case -4:
		left_caller = 0u;
		enemy_flinch_from_behind_start(object);
		break;
	}
	*p_step_handlers = step_handlers;
	*p_left_caller = left_caller;
}

/* The hit sound, stopped, the flinch animation of a kind 12 hit. */
void enemy_flinch_kind_12_start(uint16_t object)
{
	uint16_t command = 0;
	uint8_t action_step = 0;

	command = 0x6300u;
	vector_queue_sound(command);
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->animation = 0x8Au;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Reaction 9, a hit of kind 11 from the front: a hit sound and its flinch, then back to thinking. */
void enemy_flinch_kind_11(uint16_t object, uint8_t step, uint16_t *p_step_handlers, uint32_t *p_left_caller)
{
	uint16_t step_handlers = 0;
	uint32_t left_caller = 0;

	step_handlers = enemy_flinch_kind_11_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step << 1))
	{
	case 0:
		left_caller = 0u;
		enemy_flinch_kind_11_start(object);
		break;
	case -6:
	case -2:
	case 2:
	case 16:
		left_caller = 0u;
		enemy_back_to_thinking_after_animation(object);
		break;
	case 4:
		left_caller = 0u;
		enemy_knocked_forward_start(object);
		break;
	case 6:
		left_caller = 0u;
		enemy_knocked_fall(object);
		break;
	case 8:
		left_caller = 0u;
		enemy_knocked_back_start(object);
		break;
	case 10:
		left_caller = 0u;
		enemy_knocked_back_fall(object);
		break;
	case 12:
		left_caller = 0u;
		enemy_lie_then_get_up(object);
		break;
	case 14:
		left_caller = 0u;
		enemy_get_up_start(object);
		break;
	case 18:
		left_caller = 0u;
		enemy_die_start(object);
		break;
	case 20:
		enemy_die_blink(object, &step_handlers, &left_caller);
		break;
	case 22:
		left_caller = 0u;
		enemy_drop_fall(object);
		break;
	case 24:
		left_caller = 0u;
		enemy_sent_flying_start(object);
		break;
	case 26:
	case 32:
		left_caller = 0u;
		enemy_sent_flying_step(object);
		break;
	case 28:
	case 34:
		left_caller = 0u;
		enemy_spin_land(object);
		break;
	case 30:
		left_caller = 0u;
		enemy_spin_backward_start(object);
		break;
	case 36:
		left_caller = 0u;
		enemy_defeated_forward_start(object);
		break;
	case 38:
	case 44:
		left_caller = 0u;
		enemy_defeated_fly(object);
		break;
	case 40:
	case 46:
		enemy_defeated_shrink(object, &step_handlers, &left_caller);
		break;
	case 42:
		left_caller = 0u;
		enemy_defeated_backward_start(object);
		break;
	case 48:
		left_caller = 0u;
		enemy_pit_start(object);
		break;
	case 50:
		enemy_pit_fall(object, &step_handlers, &left_caller);
		break;
	case -8:
		left_caller = 0u;
		enemy_flinch_from_behind_start(object);
		break;
	case -4:
		left_caller = 0u;
		enemy_flinch_kind_12_start(object);
		break;
	}
	*p_step_handlers = step_handlers;
	*p_left_caller = left_caller;
}

/* The hit sound, stopped, the flinch animation of a kind 11 hit. */
void enemy_flinch_kind_11_start(uint16_t object)
{
	uint16_t command = 0;
	uint8_t action_step = 0;

	command = 0x6300u;
	vector_queue_sound(command);
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->animation = 0x89u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Reaction 2: knocked down forward, flying the way it faces; on landing it dies or lies to get up. */
void enemy_knocked_forward(uint16_t object, uint8_t step, uint16_t *p_step_handlers, uint32_t *p_left_caller)
{
	uint16_t step_handlers = 0;
	uint32_t left_caller = 0;

	step_handlers = enemy_knocked_forward_steps_ADDRESS;
	left_caller = 0u;
	switch ((int8_t)(uint8_t)((uint32_t)step << 1))
	{
	case 0:
		enemy_knocked_forward_start(object);
		break;
	case 2:
		enemy_knocked_fall(object);
		break;
	case 4:
		enemy_knocked_back_start(object);
		break;
	case 6:
		enemy_knocked_back_fall(object);
		break;
	case 8:
		enemy_lie_then_get_up(object);
		break;
	case 10:
		enemy_get_up_start(object);
		break;
	case -10:
	case -6:
	case -2:
	case 12:
		enemy_back_to_thinking_after_animation(object);
		break;
	case 14:
		enemy_die_start(object);
		break;
	case 16:
		enemy_die_blink(object, &step_handlers, &left_caller);
		break;
	case 18:
		enemy_drop_fall(object);
		break;
	case 20:
		enemy_sent_flying_start(object);
		break;
	case 22:
	case 28:
		enemy_sent_flying_step(object);
		break;
	case 24:
	case 30:
		enemy_spin_land(object);
		break;
	case 26:
		enemy_spin_backward_start(object);
		break;
	case 32:
		enemy_defeated_forward_start(object);
		break;
	case 34:
	case 40:
		enemy_defeated_fly(object);
		break;
	case 36:
	case 42:
		enemy_defeated_shrink(object, &step_handlers, &left_caller);
		break;
	case 38:
		enemy_defeated_backward_start(object);
		break;
	case 44:
		enemy_pit_start(object);
		break;
	case 46:
		enemy_pit_fall(object, &step_handlers, &left_caller);
		break;
	case -12:
		enemy_flinch_from_behind_start(object);
		break;
	case -8:
		enemy_flinch_kind_12_start(object);
		break;
	case -4:
		enemy_flinch_kind_11_start(object);
		break;
	}
	if (left_caller != 0u)
		left_caller = 0u;
	else
		vector_stop_at_screen_edges(object);
	*p_step_handlers = step_handlers;
	*p_left_caller = left_caller;
}

/* The hit sound, the knocked-down animation, 2 pixels a frame the way it faces, thrown up when near its
   floor. */
void enemy_knocked_forward_start(uint16_t object)
{
	uint16_t command = 0;
	uint8_t attributes = 0, action_step = 0;
	uint16_t z = 0, floor_z = 0, height_above_floor = 0, x_speed = 0;

	command = 0x6300u;
	vector_queue_sound(command);
	OBJECT(object)->animation = 0x8Eu;
	OBJECT(object)->x_speed = 0x200;
	OBJECT(object)->y_speed = 0;
	z = OBJECT(object)->z;
	floor_z = OBJECT(object)->floor_z;
	height_above_floor = z - floor_z;
	if (height_above_floor < 0x20u)
		OBJECT(object)->z_speed = 0x200;
	attributes = OBJECT(object)->attributes;
	if ((attributes & 0x40u) != 0u)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Falls with gravity; landed, it dies or lies to get up; stopped by a wall in the air, it drops. */
void enemy_knocked_fall(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t enemy_class = 0;
	uint16_t z_speed = 0, falling_z_speed = 0, x_speed = 0;

	z_speed = OBJECT(object)->z_speed;
	falling_z_speed = z_speed - 0x20u;
	OBJECT(object)->z_speed = falling_z_speed;
	carry = vector_check_landing(object);
	if (carry)
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0;
		enemy_die_or_get_up(object);
		return;
	}
	x_speed = OBJECT(object)->x_speed;
	if (x_speed != 0u)
		return;
	enemy_class = OBJECT(object)->enemy_class;
	if (enemy_class != 0u)
		OBJECT(object)->animation = 0x95u;
	else
		OBJECT(object)->animation = 0x85u;
	OBJECT(object)->action = 6u;
	OBJECT(object)->action_step = 0u;
}

/* With no life left, dies; otherwise lies 32 frames and gets up. */
void enemy_die_or_get_up(uint16_t object)
{
	uint8_t vitality = 0;

	vitality = OBJECT(object)->vitality;
	if (vitality != 0u)
	{
		OBJECT(object)->action = 4u;
		OBJECT(object)->action_step = 0u;
		OBJECT(object)->timer = 0x20u;
		return;
	}
	OBJECT(object)->action = 5u;
	OBJECT(object)->action_step = 0u;
}

/* Reaction 3: knocked down backward; on landing it lies on its back, then dies or gets up. */
void enemy_knocked_back(uint16_t object, uint8_t step, uint16_t *p_step_handlers, uint32_t *p_left_caller)
{
	uint16_t step_handlers = 0;
	uint32_t left_caller = 0;

	step_handlers = enemy_knocked_back_steps_ADDRESS;
	left_caller = 0u;
	switch ((int8_t)(uint8_t)((uint32_t)step << 1))
	{
	case 0:
		enemy_knocked_back_start(object);
		break;
	case 2:
		enemy_knocked_back_fall(object);
		break;
	case 4:
		enemy_lie_then_get_up(object);
		break;
	case 6:
		enemy_get_up_start(object);
		break;
	case -14:
	case -10:
	case -6:
	case 8:
		enemy_back_to_thinking_after_animation(object);
		break;
	case 10:
		enemy_die_start(object);
		break;
	case 12:
		enemy_die_blink(object, &step_handlers, &left_caller);
		break;
	case 14:
		enemy_drop_fall(object);
		break;
	case 16:
		enemy_sent_flying_start(object);
		break;
	case 18:
	case 24:
		enemy_sent_flying_step(object);
		break;
	case 20:
	case 26:
		enemy_spin_land(object);
		break;
	case 22:
		enemy_spin_backward_start(object);
		break;
	case 28:
		enemy_defeated_forward_start(object);
		break;
	case 30:
	case 36:
		enemy_defeated_fly(object);
		break;
	case 32:
	case 38:
		enemy_defeated_shrink(object, &step_handlers, &left_caller);
		break;
	case 34:
		enemy_defeated_backward_start(object);
		break;
	case 40:
		enemy_pit_start(object);
		break;
	case 42:
		enemy_pit_fall(object, &step_handlers, &left_caller);
		break;
	case -16:
		enemy_flinch_from_behind_start(object);
		break;
	case -12:
		enemy_flinch_kind_12_start(object);
		break;
	case -8:
		enemy_flinch_kind_11_start(object);
		break;
	case -4:
		enemy_knocked_forward_start(object);
		break;
	case -2:
		enemy_knocked_fall(object);
		break;
	}
	if (left_caller != 0u)
		left_caller = 0u;
	else
		vector_stop_at_screen_edges(object);
	*p_step_handlers = step_handlers;
	*p_left_caller = left_caller;
}

/* The hit sound, the knocked-back animation, 2 pixels a frame backward, thrown up when near its floor. */
void enemy_knocked_back_start(uint16_t object)
{
	uint16_t command = 0;
	uint8_t attributes = 0, action_step = 0;
	uint16_t z = 0, floor_z = 0, height_above_floor = 0, x_speed = 0;

	command = 0x6300u;
	vector_queue_sound(command);
	OBJECT(object)->animation = 0x8Cu;
	OBJECT(object)->x_speed = -0x200;
	OBJECT(object)->y_speed = 0;
	z = OBJECT(object)->z;
	floor_z = OBJECT(object)->floor_z;
	height_above_floor = z - floor_z;
	if (height_above_floor < 0x20u)
		OBJECT(object)->z_speed = 0x200;
	attributes = OBJECT(object)->attributes;
	if ((attributes & 0x40u) != 0u)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Falls with gravity; landed on its back, it dies with no life left or lies 4 frames; stopped by a wall
   in the air, it drops. */
void enemy_knocked_back_fall(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t vitality = 0, action_step = 0, enemy_class = 0;
	uint16_t z_speed = 0, falling_z_speed = 0, x_speed = 0;

	z_speed = OBJECT(object)->z_speed;
	falling_z_speed = z_speed - 0x20u;
	OBJECT(object)->z_speed = falling_z_speed;
	carry = vector_check_landing(object);
	if (carry)
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0;
		OBJECT(object)->animation = 0x8Du;
		vitality = OBJECT(object)->vitality;
		if (vitality != 0u)
		{
			OBJECT(object)->timer = 4u;
			action_step = OBJECT(object)->action_step;
			OBJECT(object)->action_step = action_step + 1u;
			return;
		}
		OBJECT(object)->action = 5u;
		OBJECT(object)->action_step = 0u;
		return;
	}
	x_speed = OBJECT(object)->x_speed;
	if (x_speed != 0u)
		return;
	enemy_class = OBJECT(object)->enemy_class;
	if (enemy_class != 0u)
		OBJECT(object)->animation = 0x96u;
	else
		OBJECT(object)->animation = 0x84u;
	OBJECT(object)->action = 6u;
	OBJECT(object)->action_step = 0u;
}

/* Lies until its timer runs out, then gets up after 16 frames more. */
void enemy_lie_then_get_up(uint16_t object)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->timer = 0x10u;
		OBJECT(object)->action = 4u;
		OBJECT(object)->action_step = 0u;
	}
}

/* Reaction 4: lies until its timer runs out, gets up, and thinks again. */
void enemy_get_up(uint16_t object, uint8_t step, uint16_t *p_step_handlers, uint32_t *p_left_caller)
{
	uint16_t step_handlers = 0;
	uint32_t left_caller = 0;

	step_handlers = enemy_get_up_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step << 1))
	{
	case 0:
		left_caller = 0u;
		enemy_get_up_start(object);
		break;
	case -20:
	case -16:
	case -12:
	case 2:
		left_caller = 0u;
		enemy_back_to_thinking_after_animation(object);
		break;
	case 4:
		left_caller = 0u;
		enemy_die_start(object);
		break;
	case 6:
		enemy_die_blink(object, &step_handlers, &left_caller);
		break;
	case 8:
		left_caller = 0u;
		enemy_drop_fall(object);
		break;
	case 10:
		left_caller = 0u;
		enemy_sent_flying_start(object);
		break;
	case 12:
	case 18:
		left_caller = 0u;
		enemy_sent_flying_step(object);
		break;
	case 14:
	case 20:
		left_caller = 0u;
		enemy_spin_land(object);
		break;
	case 16:
		left_caller = 0u;
		enemy_spin_backward_start(object);
		break;
	case 22:
		left_caller = 0u;
		enemy_defeated_forward_start(object);
		break;
	case 24:
	case 30:
		left_caller = 0u;
		enemy_defeated_fly(object);
		break;
	case 26:
	case 32:
		enemy_defeated_shrink(object, &step_handlers, &left_caller);
		break;
	case 28:
		left_caller = 0u;
		enemy_defeated_backward_start(object);
		break;
	case 34:
		left_caller = 0u;
		enemy_pit_start(object);
		break;
	case 36:
		enemy_pit_fall(object, &step_handlers, &left_caller);
		break;
	case -22:
		left_caller = 0u;
		enemy_flinch_from_behind_start(object);
		break;
	case -18:
		left_caller = 0u;
		enemy_flinch_kind_12_start(object);
		break;
	case -14:
		left_caller = 0u;
		enemy_flinch_kind_11_start(object);
		break;
	case -10:
		left_caller = 0u;
		enemy_knocked_forward_start(object);
		break;
	case -8:
		left_caller = 0u;
		enemy_knocked_fall(object);
		break;
	case -6:
		left_caller = 0u;
		enemy_knocked_back_start(object);
		break;
	case -4:
		left_caller = 0u;
		enemy_knocked_back_fall(object);
		break;
	case -2:
		left_caller = 0u;
		enemy_lie_then_get_up(object);
		break;
	}
	*p_step_handlers = step_handlers;
	*p_left_caller = left_caller;
}

/* Lies until its timer runs out, then the getting-up animation. */
void enemy_get_up_start(uint16_t object)
{
	uint8_t timer = 0, action_step = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->animation = 0x8Fu;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* Reaction 5: lies blinking, then is gone, defeated. */
void enemy_die(uint16_t object, uint8_t step, uint16_t *p_step_handlers, uint32_t *p_left_caller)
{
	uint16_t step_handlers = 0;
	uint32_t left_caller = 0;

	step_handlers = enemy_die_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step << 1))
	{
	case 0:
		left_caller = 0u;
		enemy_die_start(object);
		break;
	case 2:
		enemy_die_blink(object, &step_handlers, &left_caller);
		break;
	case 4:
		left_caller = 0u;
		enemy_drop_fall(object);
		break;
	case 6:
		left_caller = 0u;
		enemy_sent_flying_start(object);
		break;
	case 8:
	case 14:
		left_caller = 0u;
		enemy_sent_flying_step(object);
		break;
	case 10:
	case 16:
		left_caller = 0u;
		enemy_spin_land(object);
		break;
	case 12:
		left_caller = 0u;
		enemy_spin_backward_start(object);
		break;
	case 18:
		left_caller = 0u;
		enemy_defeated_forward_start(object);
		break;
	case 20:
	case 26:
		left_caller = 0u;
		enemy_defeated_fly(object);
		break;
	case 22:
	case 28:
		enemy_defeated_shrink(object, &step_handlers, &left_caller);
		break;
	case 24:
		left_caller = 0u;
		enemy_defeated_backward_start(object);
		break;
	case 30:
		left_caller = 0u;
		enemy_pit_start(object);
		break;
	case 32:
		enemy_pit_fall(object, &step_handlers, &left_caller);
		break;
	case -26:
		left_caller = 0u;
		enemy_flinch_from_behind_start(object);
		break;
	case -24:
	case -20:
	case -16:
	case -2:
		left_caller = 0u;
		enemy_back_to_thinking_after_animation(object);
		break;
	case -22:
		left_caller = 0u;
		enemy_flinch_kind_12_start(object);
		break;
	case -18:
		left_caller = 0u;
		enemy_flinch_kind_11_start(object);
		break;
	case -14:
		left_caller = 0u;
		enemy_knocked_forward_start(object);
		break;
	case -12:
		left_caller = 0u;
		enemy_knocked_fall(object);
		break;
	case -10:
		left_caller = 0u;
		enemy_knocked_back_start(object);
		break;
	case -8:
		left_caller = 0u;
		enemy_knocked_back_fall(object);
		break;
	case -6:
		left_caller = 0u;
		enemy_lie_then_get_up(object);
		break;
	case -4:
		left_caller = 0u;
		enemy_get_up_start(object);
		break;
	}
	*p_step_handlers = step_handlers;
	*p_left_caller = left_caller;
}

/* The dying animation (unless it is already on animation 0E), no longer kept from damage, 32 frames to
   go. */
void enemy_die_start(uint16_t object)
{
	uint8_t animation = 0, action_step = 0;

	animation = OBJECT(object)->animation;
	if (animation != 0xEu)
		OBJECT(object)->animation = 0x88u;
	OBJECT(object)->flags &= ~4u;
	OBJECT(object)->timer = 0x20u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Blinks in its last 16 frames, then is removed and marked defeated, and its handler stops there. */
void enemy_die_blink(uint16_t object, uint16_t *p_target, uint32_t *p_left_caller)
{
	uint16_t target = (uint16_t)*p_target;
	uint8_t timer = 0, timer_2 = 0;

	timer = OBJECT(object)->timer;
	if (timer < 0x10u)
		blink(object);
	timer_2 = OBJECT(object)->timer;
	OBJECT(object)->timer = timer_2 - 1u;
	if (timer_2 != 1u)
		*p_left_caller = 0u;
	else
	{
		OBJECT(object)->flags = 0u;
		target = vector_enemy_score_and_release(object, target);
		*p_left_caller = 1u;
	}
	*p_target = target;
}

/* Reaction 6: drops to its floor, then dies or lies to get up. */
void enemy_drop(uint16_t object, uint8_t step, uint16_t *p_step_handlers, uint32_t *p_left_caller)
{
	uint16_t step_handlers = 0;
	uint32_t left_caller = 0;

	step_handlers = enemy_drop_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step << 1))
	{
	case 0:
		left_caller = 0u;
		enemy_drop_fall(object);
		break;
	case 2:
		left_caller = 0u;
		enemy_sent_flying_start(object);
		break;
	case 4:
	case 10:
		left_caller = 0u;
		enemy_sent_flying_step(object);
		break;
	case 6:
	case 12:
		left_caller = 0u;
		enemy_spin_land(object);
		break;
	case 8:
		left_caller = 0u;
		enemy_spin_backward_start(object);
		break;
	case 14:
		left_caller = 0u;
		enemy_defeated_forward_start(object);
		break;
	case 16:
	case 22:
		left_caller = 0u;
		enemy_defeated_fly(object);
		break;
	case 18:
	case 24:
		enemy_defeated_shrink(object, &step_handlers, &left_caller);
		break;
	case 20:
		left_caller = 0u;
		enemy_defeated_backward_start(object);
		break;
	case 26:
		left_caller = 0u;
		enemy_pit_start(object);
		break;
	case 28:
		enemy_pit_fall(object, &step_handlers, &left_caller);
		break;
	case -30:
		left_caller = 0u;
		enemy_flinch_from_behind_start(object);
		break;
	case -28:
	case -24:
	case -20:
	case -6:
		left_caller = 0u;
		enemy_back_to_thinking_after_animation(object);
		break;
	case -26:
		left_caller = 0u;
		enemy_flinch_kind_12_start(object);
		break;
	case -22:
		left_caller = 0u;
		enemy_flinch_kind_11_start(object);
		break;
	case -18:
		left_caller = 0u;
		enemy_knocked_forward_start(object);
		break;
	case -16:
		left_caller = 0u;
		enemy_knocked_fall(object);
		break;
	case -14:
		left_caller = 0u;
		enemy_knocked_back_start(object);
		break;
	case -12:
		left_caller = 0u;
		enemy_knocked_back_fall(object);
		break;
	case -10:
		left_caller = 0u;
		enemy_lie_then_get_up(object);
		break;
	case -8:
		left_caller = 0u;
		enemy_get_up_start(object);
		break;
	case -4:
		left_caller = 0u;
		enemy_die_start(object);
		break;
	case -2:
		enemy_die_blink(object, &step_handlers, &left_caller);
		break;
	}
	*p_step_handlers = step_handlers;
	*p_left_caller = left_caller;
}

/* Falls with a lighter pull than the knock-downs' (16 a frame against 32); landed, it dies or lies to
   get up. */
void enemy_drop_fall(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t z_speed = 0;

	z_speed = OBJECT(object)->z_speed;
	OBJECT(object)->z_speed = z_speed - 0x10u;
	carry = vector_check_landing(object);
	if (carry)
	{
		enemy_die_or_get_up(object);
		return;
	}
}

/* Reaction 7: sent flying the way it faces, nudged up when it hits a wall, then dies or lies to get up. */
void enemy_sent_flying(uint16_t object, uint8_t step, uint16_t *p_step_handlers, uint32_t *p_left_caller)
{
	uint16_t step_handlers = 0;
	uint32_t left_caller = 0;

	step_handlers = enemy_sent_flying_steps_ADDRESS;
	left_caller = 0u;
	switch ((int8_t)(uint8_t)((uint32_t)step << 1))
	{
	case 0:
		enemy_sent_flying_start(object);
		break;
	case 2:
	case 8:
		enemy_sent_flying_step(object);
		break;
	case 4:
	case 10:
		enemy_spin_land(object);
		break;
	case 6:
		enemy_spin_backward_start(object);
		break;
	case 12:
		enemy_defeated_forward_start(object);
		break;
	case 14:
	case 20:
		enemy_defeated_fly(object);
		break;
	case 16:
	case 22:
		enemy_defeated_shrink(object, &step_handlers, &left_caller);
		break;
	case 18:
		enemy_defeated_backward_start(object);
		break;
	case 24:
		enemy_pit_start(object);
		break;
	case 26:
		enemy_pit_fall(object, &step_handlers, &left_caller);
		break;
	case -32:
		enemy_flinch_from_behind_start(object);
		break;
	case -30:
	case -26:
	case -22:
	case -8:
		enemy_back_to_thinking_after_animation(object);
		break;
	case -28:
		enemy_flinch_kind_12_start(object);
		break;
	case -24:
		enemy_flinch_kind_11_start(object);
		break;
	case -20:
		enemy_knocked_forward_start(object);
		break;
	case -18:
		enemy_knocked_fall(object);
		break;
	case -16:
		enemy_knocked_back_start(object);
		break;
	case -14:
		enemy_knocked_back_fall(object);
		break;
	case -12:
		enemy_lie_then_get_up(object);
		break;
	case -10:
		enemy_get_up_start(object);
		break;
	case -6:
		enemy_die_start(object);
		break;
	case -4:
		enemy_die_blink(object, &step_handlers, &left_caller);
		break;
	case -2:
		enemy_drop_fall(object);
		break;
	}
	if (left_caller != 0u)
		left_caller = 0u;
	else
		vector_stop_at_screen_edges(object);
	*p_step_handlers = step_handlers;
	*p_left_caller = left_caller;
}

/* The hit sound, the flying animation, 2 pixels a frame the way it faces for 32 frames, its speed kept. */
void enemy_sent_flying_start(uint16_t object)
{
	uint16_t command = 0;
	uint8_t attributes = 0, action_step = 0;
	uint16_t x_speed = 0, x_speed_2 = 0;

	OBJECT(object)->timer = 0x20u;
	command = 0x6300u;
	vector_queue_sound(command);
	OBJECT(object)->animation = 0x98u;
	OBJECT(object)->x_speed = 0x200;
	OBJECT(object)->y_speed = 0;
	attributes = OBJECT(object)->attributes;
	if ((attributes & 0x40u) != 0u)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	x_speed_2 = OBJECT(object)->x_speed;
	OBJECT(object)->enemy_sent_flying.flight_x_speed = x_speed_2;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Flies with gravity for its 32 frames; when a step stops it, it is lifted a pixel and keeps its speed. */
void enemy_sent_flying_step(uint16_t object)
{
	uint16_t blocked_flags = 0;
	uint8_t timer = 0, action_step = 0, blocked = 0, z_low = 0;
	uint16_t z_speed = 0, flight_x_speed = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
	z_speed = OBJECT(object)->z_speed;
	OBJECT(object)->z_speed = z_speed - 0x20u;
	vector_check_landing(object);
	blocked = OBJECT(object)->blocked;
	blocked_flags = (uint32_t)blocked << 8;
	if (((blocked_flags >> 8) & 0x80u) != 0u && ((blocked_flags >> 8) & 8u) == 0u)
	{
		z_low = (uint8_t)OBJECT(object)->z;
		OBJECT(object)->z = (OBJECT(object)->z & 0xFF00u) | (z_low + 1u & 0xFFu);
		flight_x_speed = OBJECT(object)->enemy_sent_flying.flight_x_speed;
		OBJECT(object)->x_speed = flight_x_speed;
	}
}
