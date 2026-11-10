/**
 *    Name:        objects/object_f9.c
 *    Description: stage 6's objects of type F9 (kind B9)
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Runs an F9 object by its state, removing it off the screen's left */
uint16_t object_f9(uint16_t object, uint16_t y)
{
	uint16_t states = 0;
	uint8_t phase = 0;
	uint16_t t1 = 0;

	t1 = OBJECT(object)->x;
	if ((int16_t)t1 < 0x40)
	{
		OBJECT(object)->flags = 0u;
		return y;
	}
	phase = OBJECT(object)->object_f9.phase;
	states = bank_1e_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)phase << 1))
	{
	case 0:
		object_f9_start(object);
		return states;
	case 2:
		return object_f9_wait_for_player(object, states);
	case 4:
	case 28:
		return object_f9_wander(object, states);
	case 6:
		return object_f9_appear(object, states);
	case 8:
	case 10:
		return object_f9_wait(object);
	case 12:
		return object_f9_look(object);
	case 14:
		return object_f9_windup(object);
	case 16:
		return object_f9_attack(object);
	case 18:
		return object_f9_idle(object);
	case 20:
		return object_f9_act(object);
	case 22:
		return object_f9_leave(object, states);
	case 24:
		return object_f9_flinch(object, states);
	case 26:
		object_f9_vanish(object);
		return states;
	}
	unreachable();
}

/* Its state B with that state's wait and animation */
uint16_t object_f9_set_state(uint16_t object, uint8_t new_phase)
{
	uint8_t animation = 0, phase = 0;
	uint16_t state_start = 0;
	uint16_t wait = 0;

	phase = (uint8_t)new_phase;
	state_start = object_f9_state_starts_ADDRESS;
	OBJECT(object)->object_f9.phase = phase;
	wait = (((uint32_t)STATE_START(state_start + (phase & 0x7Fu) * 0x2u)->wait << 8u) | STATE_START(state_start + (phase & 0x7Fu) * 0x2u)->animation);
	animation = (uint8_t)wait;
	OBJECT(object)->object_f9.wait = ((wait & ~0xFFu) | animation) >> 8;
	OBJECT(object)->animation = animation;
	return state_start;
}

/* Sets it up: kind, health, where it wanders to */
void object_f9_start(uint16_t object)
{
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	OBJECT(object)->kind = 0xB9u;
	OBJECT(object)->enemy_class = -1;
	OBJECT(object)->entrance_pending = 0xFFu;
	OBJECT(object)->vitality = 8u;
	t1 = camera_x;
	t2 = t1 + 0x60u;
	t3 = OBJECT(object)->x;
	t4 = t2 + t3;
	OBJECT(object)->object_f9.wander_x = t4;
	OBJECT(object)->object_f9.phase = 1u;
}

/* Waits hidden for a player to come near, then shows itself */
uint16_t object_f9_wait_for_player(uint16_t object, uint16_t states)
{
	uint32_t carry = 0;
	uint8_t new_phase = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0;

	reach_x = 0x30;
	reach_y = 0x10;
	stage_boss_find_near_player(object, &ignored16, &ignored16_2, &carry);
	if (carry)
	{
		OBJECT(object)->flags = 0x80u;
		new_phase = 2u;
		return object_f9_set_state(object, new_phase);
	}
	return states;
}

/* Moves about, then with a sound starts its appearance */
uint16_t object_f9_wander(uint16_t object, uint16_t states)
{
	uint32_t negative = 0, carry = 0;
	uint8_t floor_value = 0, new_phase = 0;
	uint16_t command = 0, floor_cell = 0;
	uint8_t wait = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, wander_x = 0;

	t1 = camera_x;
	t2 = OBJECT(object)->x;
	t3 = t1 + t2;
	wander_x = OBJECT(object)->object_f9.wander_x;
	if ((int16_t)wander_x < (int16_t)t3)
		OBJECT(object)->x_speed = 0;
	vector_floor_ahead(object, &floor_cell, &negative);
	floor_value = (uint8_t)(floor_cell >> 8);
	if ((uint8_t)(floor_value + 1u) == 0u)
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0;
	}
	wait = OBJECT(object)->object_f9.wait;
	OBJECT(object)->object_f9.wait = wait - 1u;
	if (wait != 1u)
		return states;
	OBJECT(object)->flags = 0x80u;
	command = 0xE00u;
	carry = vector_queue_sound(command);
	OBJECT(object)->object_f9.actions = 0u;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	new_phase = 3u;
	return object_f9_set_state(object, new_phase);
}

/* At its animation's end takes its hit box */
uint16_t object_f9_appear(uint16_t object, uint16_t states)
{
	uint8_t new_phase = 0;
	uint16_t box = 0;
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return states;
	OBJECT(object)->flags |= 0x40u;
	new_phase = 4u;
	object_f9_set_state(object, new_phase);
	box = object_f9_box_ADDRESS;
	return stage_boss_set_hit_box(object, box);
}

/* Waits for its turn (by its x and the frame count), then acts with a sound */
uint16_t object_f9_idle(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t new_phase = 0;
	uint16_t command = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0, attributes = 0, actions = 0;

	stack = ((((uint32_t)(uint8_t)frame_count << 1) << 1) << 1) & 0x78u;
	t1 = (uint8_t)OBJECT(object)->x;
	if (((t1 - 0x40u) & 0x78u) != stack)
		return object_f9_check_hit(object);
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = attributes & 0xBFu;
	new_phase = 0xAu;
	object_f9_set_state(object, new_phase);
	command = 0x2A01u;
	carry = vector_queue_sound(command);
	actions = OBJECT(object)->object_f9.actions;
	OBJECT(object)->object_f9.actions = actions + 1u;
	return object_f9_check_hit(object);
}

/* Its action's animation, then it looks for a player */
uint16_t object_f9_act(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
		return object_f9_start_look(object);
	return object_f9_check_hit(object);
}

/* Waits, then looks for a player */
uint16_t object_f9_wait(uint16_t object)
{
	uint8_t wait = 0;

	wait = OBJECT(object)->object_f9.wait;
	OBJECT(object)->object_f9.wait = wait - 1u;
	if (wait != 1u)
		return object_f9_check_hit(object);
	return object_f9_start_look(object);
}

/* Takes the looking state */
uint16_t object_f9_start_look(uint16_t object)
{
	uint8_t new_phase = 0;

	new_phase = 6u;
	object_f9_set_state(object, new_phase);
	OBJECT(object)->flags |= 0x40u;
	return object_f9_check_leave(object);
}

/* Looks for a player in reach to attack, else idles */
uint16_t object_f9_look(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t new_phase = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0;
	uint8_t wait = 0;

	reach_x = 0x40;
	reach_y = 0x10;
	stage_boss_find_near_player(object, &ignored16, &ignored16_2, &carry);
	if (carry)
	{
		new_phase = 7u;
		object_f9_set_state(object, new_phase);
		if ((random_number & 3u) == 0u)
			OBJECT(object)->object_f9.wait = 1u;
		return object_f9_check_leave(object);
	}
	wait = OBJECT(object)->object_f9.wait;
	OBJECT(object)->object_f9.wait = wait - 1u;
	if (wait != 1u)
		return object_f9_check_leave(object);
	return object_f9_start_idle(object);
}

/* Takes the idle state */
uint16_t object_f9_start_idle(uint16_t object)
{
	uint8_t new_phase = 0;

	new_phase = 9u;
	object_f9_set_state(object, new_phase);
	return object_f9_check_hit(object);
}

/* Winds up its attack at the nearest player */
uint16_t object_f9_windup(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t new_phase = 0;
	uint16_t box = 0, command = 0;
	uint8_t wait = 0, actions = 0;

	wait = OBJECT(object)->object_f9.wait;
	OBJECT(object)->object_f9.wait = wait - 1u;
	if (wait != 1u)
		return object_f9_check_hit(object);
	command = 0x1C00u;
	carry = vector_queue_sound(command);
	stage_boss_shield(object);
	new_phase = 8u;
	object_f9_set_state(object, new_phase);
	box = object_f9_windup_box_ADDRESS;
	stage_boss_set_hit_box(object, box);
	stage_boss_face_nearest_player(object);
	actions = OBJECT(object)->object_f9.actions;
	OBJECT(object)->object_f9.actions = actions + 1u;
	return object_f9_check_hit(object);
}

/* Its attack's damage on the attack frames */
uint16_t object_f9_attack(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t new_phase = 0, new_phase_2 = 0;
	uint16_t box = 0, damage = 0;

	damage = 0x401u;
	carry = stage_boss_attack_frame(object, damage);
	if (carry == 0u)
		return object_f9_check_hit(object);
	OBJECT(object)->damage = 0u;
	OBJECT(object)->attack = 0u;
	new_phase = 5u;
	new_phase_2 = new_phase;
	object_f9_set_state(object, new_phase_2);
	box = object_f9_box_ADDRESS;
	return stage_boss_set_hit_box(object, box);
}

/* Idles when a player is down; leaves after 3 actions */
uint16_t object_f9_check_leave(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t new_phase = 0;
	uint16_t command = 0;
	uint8_t actions = 0;

	carry = stage_boss_any_player_down();
	if (carry)
		return object_f9_start_idle(object);
	actions = OBJECT(object)->object_f9.actions;
	if (actions <= 3u)
		return object_f9_check_hit(object);
	command = 0x1900u;
	carry = vector_queue_sound(command);
	new_phase = 0xBu;
	object_f9_set_state(object, new_phase);
	stage_boss_shield(object);
	return object_f9_check_hit(object);
}

/* Its hits: a flinch, or beaten */
uint16_t object_f9_check_hit(uint16_t object)
{
	uint32_t zero = 0, negative = 0, carry = 0;
	uint8_t new_phase = 0;
	uint16_t command = 0, health_limits = 0, ignored16 = 0;

	health_limits = 0x7FA1u;
	stage_boss_check_hit(object, health_limits, &ignored16, &zero, &negative);
	if (zero)
		return health_limits;
	if (negative == 0u)
	{
		new_phase = 0xCu;
		return object_f9_set_state(object, new_phase);
	}
	command = 0x1000u;
	carry = vector_queue_sound(command);
	new_phase = 0xDu;
	return object_f9_set_state(object, new_phase);
}

/* Flinches, then looks for a player */
uint16_t object_f9_flinch(uint16_t object, uint16_t states)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
		return object_f9_start_look(object);
	return states;
}

/* Beaten: gone at its animation's end, its score awarded */
void object_f9_vanish(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	OBJECT(object)->flags = 0u;
	stage_boss_award_score(object);
}

/* Leaves toward a random player, unhurtable */
uint16_t object_f9_leave(uint16_t object, uint16_t states)
{
	uint8_t angle = 0, new_phase = 0;
	uint16_t direction = 0, heading = 0, target_player = 0;
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return states;
	target_player = stage_boss_pick_random_player();
	direction = vector_direction_to(object, target_player);
	angle = (uint8_t)(direction >> 8);
	heading = ((uint32_t)angle << 8) | 0x60u;
	vector_set_speed_by_direction(object, heading);
	OBJECT(object)->flags = 4u;
	new_phase = 0xEu;
	return object_f9_set_state(object, new_phase);
}
