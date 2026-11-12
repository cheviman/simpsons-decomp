/**
 *    Name:        enemies/grabbing_zombie.c
 *    Description: stage 3's zombie that takes hold of the players (type 14, action 31)
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Sets the grabbing zombie up with its behaviour grabbing_zombie_behaviour, turned to its player: state
   0 joins the fight at once, the others stay hidden for their way out. */
void grabbing_zombie_setup(uint16_t object)
{
	uint16_t nearest_player = 0, setup = 0;
	uint8_t parameter = 0, state = 0;

	setup = grabbing_zombie_object_setup_ADDRESS;
	vector_object_setup(object, setup);
	nearest_player = vector_choose_nearest_player(object);
	vector_measure_target(object, nearest_player);
	OBJECT(object)->grabbing_zombie.frame_sound = 0x5100u;
	OBJECT(object)->grabbing_zombie.vanishes = 1u;
	OBJECT(object)->behaviour = 0x7A88u;
	OBJECT(object)->retarget_time = 0x10u;
	parameter = OBJECT(object)->parameter;
	if (parameter == 0u)
	{
		OBJECT(object)->parameter = 0u;
		OBJECT(object)->state = 2u;
		return;
	}
	OBJECT(object)->flags = 4u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* The grabbing zombie's way out of the ground, by field 29. */
void grabbing_zombie_come_out(uint16_t object)
{
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		grabbing_zombie_place(object);
		return;
	case 2:
		grabbing_zombie_rise(object);
		return;
	case 4:
		grabbing_zombie_join_fight(object);
		return;
	}
}

/* Shows the zombie's hand coming out at its place from kind_97_entrances, for its wait. */
void grabbing_zombie_place(uint16_t object)
{
	uint8_t parameter = 0, action_step = 0;
	uint16_t wait = 0, start_x = 0;

	OBJECT(object)->flags = 0x80u;
	parameter = OBJECT(object)->parameter;
	wait = (((uint32_t)kind_97_entrances[(int8_t)((uint32_t)parameter << 1) / 2].wait << 8u) | kind_97_entrances[(int8_t)((uint32_t)parameter << 1) / 2].x);
	OBJECT(object)->timer = wait >> 8;
	start_x = (wait & 0xFFu) << 4;
	OBJECT(object)->x = start_x;
	OBJECT(object)->animation = 0x90u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Counts the wait down, then plays the zombie climbing out, with a sound. */
void grabbing_zombie_rise(uint16_t object)
{
	uint16_t command = 0;
	uint8_t timer = 0, action_step = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->animation = 0x91u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	command = 0x4800u;
	vector_queue_sound(command);
}

/* When the climbing-out animation ends, makes the zombie hittable and lets it join the fight. */
void grabbing_zombie_join_fight(uint16_t object)
{
	uint8_t animation_flags = 0, state = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		OBJECT(object)->flags = 0xC0u;
		OBJECT(object)->parameter = 0u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Starts the grab when its player is free (not hurt, not held): walks at him for 64 frames; otherwise
   ends the action. */
uint16_t zombie_grab_start(uint16_t object)
{
	uint8_t angle = 0;
	uint16_t direction = 0, heading = 0, target_player = 0;
	uint8_t state = 0, hold_presses = 0, action_step = 0;
	uint16_t target = 0;

	target = OBJECT(object)->target;
	target_player = target;
	state = OBJECT(target_player)->state;
	if ((int8_t)state < 0)
	{
		OBJECT(object)->state = 2u;
		OBJECT(object)->timer = 0u;
		return target_player;
	}
	hold_presses = OBJECT(target_player)->player.hold_presses;
	if (hold_presses != 0u)
	{
		OBJECT(object)->state = 2u;
		OBJECT(object)->timer = 0u;
		return target_player;
	}
	face_target(object);
	OBJECT(object)->timer = 0x40u;
	direction = vector_direction_to(object, target_player);
	angle = (uint8_t)(direction >> 8);
	heading = ((uint32_t)angle << 8) | 0x30u;
	vector_set_speed_by_direction(object, heading);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	enemy_restart_walk_animation(object);
	return target_player;
}

/* Walks the zombie at its player; when it touches him on the ground, takes hold of him (the player's
   field 4B points to it), puts itself on his place and plays the hold for his character; gives up after
   its time. */
uint16_t zombie_grab_reach(uint16_t object)
{
	uint8_t angle = 0, floor_high = 0, floor_low = 0;
	uint16_t direction = 0, heading = 0, target_player = 0;
	uint8_t target_player_bits = 0;
	uint8_t state = 0, timer = 0, blink_frames = 0, hold_presses = 0, attributes = 0, attributes_2 = 0, shadow_player = 0, points = 0, shadow_player_2 = 0, action_step = 0;
	uint16_t target = 0, hit_by = 0, target_dx = 0, target_dy = 0, floor_z = 0, z = 0, floor_z_2 = 0, player_x = 0, player_y = 0;

	target = OBJECT(object)->target;
	target_player = target;
	if ((OBJECT(object)->flags & 0x20u) == 0u)
	{
		state = OBJECT(target_player)->state;
		if ((int8_t)state < 0)
		{
			OBJECT(object)->state = 2u;
			OBJECT(object)->timer = 0u;
			return target_player;
		}
		timer = OBJECT(object)->timer;
		OBJECT(object)->timer = timer - 1u;
		if (timer == 1u)
		{
			OBJECT(object)->state = 2u;
			OBJECT(object)->timer = 0u;
			return target_player;
		}
		direction = vector_direction_to(object, target_player);
		angle = (uint8_t)(direction >> 8);
		heading = ((uint32_t)angle << 8) | 0x30u;
		vector_set_speed_by_direction(object, heading);
		vector_choose_walk_animation(object);
		return target_player;
	}
	blink_frames = OBJECT(target_player)->player.blink_frames;
	if (blink_frames != 0u)
	{
		state = OBJECT(target_player)->state;
		if ((int8_t)state < 0)
		{
			OBJECT(object)->state = 2u;
			OBJECT(object)->timer = 0u;
			return target_player;
		}
		timer = OBJECT(object)->timer;
		OBJECT(object)->timer = timer - 1u;
		if (timer == 1u)
		{
			OBJECT(object)->state = 2u;
			OBJECT(object)->timer = 0u;
			return target_player;
		}
		direction = vector_direction_to(object, target_player);
		angle = (uint8_t)(direction >> 8);
		heading = ((uint32_t)angle << 8) | 0x30u;
		vector_set_speed_by_direction(object, heading);
		vector_choose_walk_animation(object);
		return target_player;
	}
	hold_presses = OBJECT(target_player)->player.hold_presses;
	if (hold_presses != 0u)
	{
		state = OBJECT(target_player)->state;
		if ((int8_t)state < 0)
		{
			OBJECT(object)->state = 2u;
			OBJECT(object)->timer = 0u;
			return target_player;
		}
		timer = OBJECT(object)->timer;
		OBJECT(object)->timer = timer - 1u;
		if (timer == 1u)
		{
			OBJECT(object)->state = 2u;
			OBJECT(object)->timer = 0u;
			return target_player;
		}
		direction = vector_direction_to(object, target_player);
		angle = (uint8_t)(direction >> 8);
		heading = ((uint32_t)angle << 8) | 0x30u;
		vector_set_speed_by_direction(object, heading);
		vector_choose_walk_animation(object);
		return target_player;
	}
	hit_by = OBJECT(object)->hit_by;
	if (target_player != hit_by)
	{
		state = OBJECT(target_player)->state;
		if ((int8_t)state < 0)
		{
			OBJECT(object)->state = 2u;
			OBJECT(object)->timer = 0u;
			return target_player;
		}
		timer = OBJECT(object)->timer;
		OBJECT(object)->timer = timer - 1u;
		if (timer == 1u)
		{
			OBJECT(object)->state = 2u;
			OBJECT(object)->timer = 0u;
			return target_player;
		}
		direction = vector_direction_to(object, target_player);
		angle = (uint8_t)(direction >> 8);
		heading = ((uint32_t)angle << 8) | 0x30u;
		vector_set_speed_by_direction(object, heading);
		vector_choose_walk_animation(object);
		return target_player;
	}
	target_dx = OBJECT(object)->target_dx;
	if (target_dx >= 8u)
	{
		state = OBJECT(target_player)->state;
		if ((int8_t)state < 0)
		{
			OBJECT(object)->state = 2u;
			OBJECT(object)->timer = 0u;
			return target_player;
		}
		timer = OBJECT(object)->timer;
		OBJECT(object)->timer = timer - 1u;
		if (timer == 1u)
		{
			OBJECT(object)->state = 2u;
			OBJECT(object)->timer = 0u;
			return target_player;
		}
		direction = vector_direction_to(object, target_player);
		angle = (uint8_t)(direction >> 8);
		heading = ((uint32_t)angle << 8) | 0x30u;
		vector_set_speed_by_direction(object, heading);
		vector_choose_walk_animation(object);
		return target_player;
	}
	target_dy = OBJECT(object)->target_dy;
	if (target_dy >= 4u)
	{
		state = OBJECT(target_player)->state;
		if ((int8_t)state < 0)
		{
			OBJECT(object)->state = 2u;
			OBJECT(object)->timer = 0u;
			return target_player;
		}
		timer = OBJECT(object)->timer;
		OBJECT(object)->timer = timer - 1u;
		if (timer == 1u)
		{
			OBJECT(object)->state = 2u;
			OBJECT(object)->timer = 0u;
			return target_player;
		}
		direction = vector_direction_to(object, target_player);
		angle = (uint8_t)(direction >> 8);
		heading = ((uint32_t)angle << 8) | 0x30u;
		vector_set_speed_by_direction(object, heading);
		vector_choose_walk_animation(object);
		return target_player;
	}
	floor_z = OBJECT(target_player)->floor_z;
	floor_high = (uint8_t)(floor_z >> 8);
	floor_low = (uint8_t)floor_z;
	z = OBJECT(target_player)->z;
	if ((uint16_t)(((uint32_t)floor_high << 8) | floor_low) != z)
	{
		state = OBJECT(target_player)->state;
		if ((int8_t)state < 0)
		{
			OBJECT(object)->state = 2u;
			OBJECT(object)->timer = 0u;
			return target_player;
		}
		timer = OBJECT(object)->timer;
		OBJECT(object)->timer = timer - 1u;
		if (timer == 1u)
		{
			OBJECT(object)->state = 2u;
			OBJECT(object)->timer = 0u;
			return target_player;
		}
		direction = vector_direction_to(object, target_player);
		angle = (uint8_t)(direction >> 8);
		heading = ((uint32_t)angle << 8) | 0x30u;
		vector_set_speed_by_direction(object, heading);
		vector_choose_walk_animation(object);
		return target_player;
	}
	floor_z_2 = OBJECT(object)->floor_z;
	if ((uint16_t)(((uint32_t)floor_high << 8) | floor_low) != floor_z_2)
	{
		state = OBJECT(target_player)->state;
		if ((int8_t)state < 0)
		{
			OBJECT(object)->state = 2u;
			OBJECT(object)->timer = 0u;
			return target_player;
		}
		timer = OBJECT(object)->timer;
		OBJECT(object)->timer = timer - 1u;
		if (timer == 1u)
		{
			OBJECT(object)->state = 2u;
			OBJECT(object)->timer = 0u;
			return target_player;
		}
		direction = vector_direction_to(object, target_player);
		angle = (uint8_t)(direction >> 8);
		heading = ((uint32_t)angle << 8) | 0x30u;
		vector_set_speed_by_direction(object, heading);
		vector_choose_walk_animation(object);
		return target_player;
	}
	vector_enemy_leave_side(object, target_player);
	OBJECT(target_player)->player.holder = object;
	OBJECT(target_player)->player.hold_presses = 0xCu;
	OBJECT(target_player)->flags |= 0x20u;
	OBJECT(target_player)->hit = 3u;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	player_x = OBJECT(target_player)->x;
	OBJECT(object)->x = player_x;
	player_y = OBJECT(target_player)->y;
	OBJECT(object)->y = player_y;
	attributes = OBJECT(target_player)->attributes;
	grab_facing = attributes & 0x40u;
	attributes_2 = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes_2 & 0xBFu) | grab_facing;
	shadow_player = OBJECT(target_player)->shadow_player;
	target_player_bits = shadow_player & 0x70u;
	points = OBJECT(object)->points;
	OBJECT(object)->points = (points & 0x8Fu) | target_player_bits;
	shadow_player_2 = OBJECT(target_player)->shadow_player;
	OBJECT(object)->animation = kind_97_hold_animations[(((shadow_player_2 >> 1) >> 1) >> 1) >> 1] | 0x80u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	leftover_y = kind_97_hold_animations_ADDRESS;
	return target_player;
}

/* Holds the player while he is held; when he breaks free the zombie loses 3 vitality and is thrown off
   into the hit reaction; if the player is beaten, it ends the action. */
uint16_t zombie_grab_hold(uint16_t object)
{
	uint8_t vitality = 0;
	uint16_t held_player = 0;
	uint8_t hold_presses = 0, vitality_2 = 0, vitality_3 = 0, squeeze_step = 0, squeeze_step_2 = 0;
	uint16_t target = 0;

	OBJECT(object)->attack = 0u;
	target = OBJECT(object)->target;
	held_player = target;
	hold_presses = OBJECT(held_player)->player.hold_presses;
	if (hold_presses == 0u)
	{
		vitality_2 = OBJECT(object)->vitality;
		vitality = vitality_2 - 3u;
		OBJECT(object)->vitality = vitality;
		if ((int8_t)vitality < 0)
			OBJECT(object)->vitality = 0u;
		OBJECT(object)->attack = 0u;
		OBJECT(object)->flags = 0x88u;
		OBJECT(object)->state = 4u;
		OBJECT(object)->action = (random_number & 1u) + 2u;
		OBJECT(object)->action_step = 0u;
		return held_player;
	}
	vitality_3 = OBJECT(held_player)->vitality;
	if (vitality_3 == 0u)
	{
		OBJECT(object)->attack = 0u;
		OBJECT(object)->state = 2u;
		OBJECT(object)->timer = 0u;
		return held_player;
	}
	squeeze_step = OBJECT(object)->zombie_grab.squeeze_step;
	if (squeeze_step == 2u)
	{
		squeeze_step_2 = OBJECT(object)->zombie_grab.squeeze_step;
		OBJECT(object)->zombie_grab.squeeze_step = squeeze_step_2 + 1u;
		OBJECT(object)->action_step = 3u;
	}
	return held_player;
}

/* Plays the hold again when it ends, then goes on holding. */
uint16_t zombie_grab_hold_loop(uint16_t object)
{
	uint8_t animation_flags = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		OBJECT(object)->zombie_grab.squeeze_step = 1u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step - 1u;
	}
	return zombie_grab_hold(object);
}
