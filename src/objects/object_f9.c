/**
 *    Name:        objects/object_f9.c
 *    Description: stage 6's objects of type F9 (kind B9)
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Runs an F9 object by its state, removing it off the screen's left */
void object_f9(uint16_t object)
{
	uint16_t states = 0;
	uint8_t phase = 0;
	uint16_t screen_x = 0;

	screen_x = OBJECT(object)->x;
	if ((int16_t)screen_x < 0x40)
	{
		OBJECT(object)->flags = 0u;
		return;
	}
	phase = OBJECT(object)->object_f9.phase;
	states = bank_1e_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)phase << 1))
	{
	case 0:
		leftover_y = states;
		object_f9_start(object);
		return;
	case 2:
		leftover_y = states;
		object_f9_wait_for_player(object);
		return;
	case 4:
	case 28:
		leftover_y = states;
		object_f9_wander(object);
		return;
	case 6:
		leftover_y = states;
		object_f9_appear(object);
		return;
	case 8:
	case 10:
		object_f9_wait(object);
		return;
	case 12:
		object_f9_look(object);
		return;
	case 14:
		object_f9_windup(object);
		return;
	case 16:
		object_f9_attack(object);
		return;
	case 18:
		object_f9_idle(object);
		return;
	case 20:
		object_f9_act(object);
		return;
	case 22:
		leftover_y = states;
		object_f9_leave(object);
		return;
	case 24:
		leftover_y = states;
		object_f9_flinch(object);
		return;
	case 26:
		leftover_y = states;
		object_f9_vanish(object);
		return;
	}
}

/* Its state B with that state's wait and animation */
void object_f9_set_state(uint16_t object, uint8_t new_phase)
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
	leftover_y = state_start;
}

/* Sets it up: kind, health, where it wanders to */
void object_f9_start(uint16_t object)
{
	uint16_t camera_position = 0, camera_ahead = 0, screen_x = 0, wander_end = 0;

	OBJECT(object)->kind = 0xB9u;
	OBJECT(object)->enemy_class = -1;
	OBJECT(object)->entrance_pending = 0xFFu;
	OBJECT(object)->vitality = 8u;
	camera_position = camera_x;
	camera_ahead = camera_position + 0x60u;
	screen_x = OBJECT(object)->x;
	wander_end = camera_ahead + screen_x;
	OBJECT(object)->object_f9.wander_x = wander_end;
	OBJECT(object)->object_f9.phase = 1u;
}

/* Waits hidden for a player to come near, then shows itself */
void object_f9_wait_for_player(uint16_t object)
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
		object_f9_set_state(object, new_phase);
		return;
	}
}

/* Moves about, then with a sound starts its appearance */
void object_f9_wander(uint16_t object)
{
	uint32_t negative = 0;
	uint8_t floor_value = 0, new_phase = 0;
	uint16_t command = 0, floor_cell = 0;
	uint8_t wait = 0;
	uint16_t camera_position = 0, screen_x = 0, world_x = 0, wander_x = 0;

	camera_position = camera_x;
	screen_x = OBJECT(object)->x;
	world_x = camera_position + screen_x;
	wander_x = OBJECT(object)->object_f9.wander_x;
	if ((int16_t)wander_x < (int16_t)world_x)
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
		return;
	OBJECT(object)->flags = 0x80u;
	command = 0xE00u;
	vector_queue_sound(command);
	OBJECT(object)->object_f9.actions = 0u;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	new_phase = 3u;
	object_f9_set_state(object, new_phase);
}

/* At its animation's end takes its hit box */
void object_f9_appear(uint16_t object)
{
	uint8_t new_phase = 0;
	uint16_t box = 0;
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	OBJECT(object)->flags |= 0x40u;
	new_phase = 4u;
	object_f9_set_state(object, new_phase);
	box = object_f9_box_ADDRESS;
	stage_boss_set_hit_box(object, box);
}

/* Waits for its turn (by its x and the frame count), then acts with a sound */
void object_f9_idle(uint16_t object)
{
	uint8_t new_phase = 0;
	uint16_t command = 0;
	uint8_t stack = 0;
	uint8_t x_low = 0, attributes = 0, actions = 0;

	stack = ((((uint32_t)(uint8_t)frame_count << 1) << 1) << 1) & 0x78u;
	x_low = (uint8_t)OBJECT(object)->x;
	if (((x_low - 0x40u) & 0x78u) != stack)
	{
		object_f9_check_hit(object);
		return;
	}
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = attributes & 0xBFu;
	new_phase = 0xAu;
	object_f9_set_state(object, new_phase);
	command = 0x2A01u;
	vector_queue_sound(command);
	actions = OBJECT(object)->object_f9.actions;
	OBJECT(object)->object_f9.actions = actions + 1u;
	object_f9_check_hit(object);
}

/* Its action's animation, then it looks for a player */
void object_f9_act(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		object_f9_start_look(object);
		return;
	}
	object_f9_check_hit(object);
}

/* Waits, then looks for a player */
void object_f9_wait(uint16_t object)
{
	uint8_t wait = 0;

	wait = OBJECT(object)->object_f9.wait;
	OBJECT(object)->object_f9.wait = wait - 1u;
	if (wait != 1u)
	{
		object_f9_check_hit(object);
		return;
	}
	object_f9_start_look(object);
}

/* Takes the looking state */
void object_f9_start_look(uint16_t object)
{
	uint8_t new_phase = 0;

	new_phase = 6u;
	object_f9_set_state(object, new_phase);
	OBJECT(object)->flags |= 0x40u;
	object_f9_check_leave(object);
}

/* Looks for a player in reach to attack, else idles */
void object_f9_look(uint16_t object)
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
		object_f9_check_leave(object);
		return;
	}
	wait = OBJECT(object)->object_f9.wait;
	OBJECT(object)->object_f9.wait = wait - 1u;
	if (wait != 1u)
	{
		object_f9_check_leave(object);
		return;
	}
	object_f9_start_idle(object);
}

/* Takes the idle state */
void object_f9_start_idle(uint16_t object)
{
	uint8_t new_phase = 0;

	new_phase = 9u;
	object_f9_set_state(object, new_phase);
	object_f9_check_hit(object);
}

/* Winds up its attack at the nearest player */
void object_f9_windup(uint16_t object)
{
	uint8_t new_phase = 0;
	uint16_t box = 0, command = 0;
	uint8_t wait = 0, actions = 0;

	wait = OBJECT(object)->object_f9.wait;
	OBJECT(object)->object_f9.wait = wait - 1u;
	if (wait != 1u)
	{
		object_f9_check_hit(object);
		return;
	}
	command = 0x1C00u;
	vector_queue_sound(command);
	stage_boss_shield(object);
	new_phase = 8u;
	object_f9_set_state(object, new_phase);
	box = object_f9_windup_box_ADDRESS;
	stage_boss_set_hit_box(object, box);
	stage_boss_face_nearest_player(object);
	actions = OBJECT(object)->object_f9.actions;
	OBJECT(object)->object_f9.actions = actions + 1u;
	object_f9_check_hit(object);
}

/* Its attack's damage on the attack frames */
void object_f9_attack(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t new_phase = 0, new_phase_2 = 0;
	uint16_t box = 0, damage = 0;

	damage = 0x401u;
	carry = stage_boss_attack_frame(object, damage);
	if (carry == 0u)
	{
		object_f9_check_hit(object);
		return;
	}
	OBJECT(object)->damage = 0u;
	OBJECT(object)->attack = 0u;
	new_phase = 5u;
	new_phase_2 = new_phase;
	object_f9_set_state(object, new_phase_2);
	box = object_f9_box_ADDRESS;
	stage_boss_set_hit_box(object, box);
}

/* Idles when a player is down; leaves after 3 actions */
void object_f9_check_leave(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t new_phase = 0;
	uint16_t command = 0;
	uint8_t actions = 0;

	carry = stage_boss_any_player_down();
	if (carry)
	{
		object_f9_start_idle(object);
		return;
	}
	actions = OBJECT(object)->object_f9.actions;
	if (actions <= 3u)
	{
		object_f9_check_hit(object);
		return;
	}
	command = 0x1900u;
	vector_queue_sound(command);
	new_phase = 0xBu;
	object_f9_set_state(object, new_phase);
	stage_boss_shield(object);
	object_f9_check_hit(object);
}

/* Its hits: a flinch, or beaten */
void object_f9_check_hit(uint16_t object)
{
	uint32_t zero = 0, negative = 0;
	uint8_t new_phase = 0;
	uint16_t command = 0, health_limits = 0, ignored16 = 0;

	leftover_y = 0x7FA1u;
	health_limits = 0x7FA1u;
	stage_boss_check_hit(object, health_limits, &ignored16, &zero, &negative);
	if (zero)
		return;
	if (negative == 0u)
	{
		new_phase = 0xCu;
		object_f9_set_state(object, new_phase);
		return;
	}
	command = 0x1000u;
	vector_queue_sound(command);
	new_phase = 0xDu;
	object_f9_set_state(object, new_phase);
}

/* Flinches, then looks for a player */
void object_f9_flinch(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		object_f9_start_look(object);
		return;
	}
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
void object_f9_leave(uint16_t object)
{
	uint8_t angle = 0, new_phase = 0;
	uint16_t direction = 0, heading = 0, target_player = 0;
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	target_player = stage_boss_pick_random_player();
	direction = vector_direction_to(object, target_player);
	angle = (uint8_t)(direction >> 8);
	heading = ((uint32_t)angle << 8) | 0x60u;
	vector_set_speed_by_direction(object, heading);
	OBJECT(object)->flags = 4u;
	new_phase = 0xEu;
	object_f9_set_state(object, new_phase);
}
