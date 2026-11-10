/**
 *    Name:        enemies/zombies.c
 *    Description: the zombies of stage 3 and their actions: kinds 91 and 97 (types 10, 14, 23, 5280 18)
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* When a wandering zombie is hit: by field 28 it starts sinking, then goes when that ends. */
uint16_t wandering_zombie_hit(uint16_t object, uint16_t y)
{
	uint8_t action = 0;

	for (;;)
	{
		action = OBJECT(object)->action;
		switch ((int8_t)(uint8_t)((uint32_t)action << 1))
		{
		case 0:
			wandering_zombie_start_sinking(object);
			return y;
		case 2:
			break;
		case -14:
		case -12:
			continue;
		case -10:
			return wandering_zombie_setup(object);
		case -8:
			wandering_zombie_wait(object);
			return y;
		case -6:
			wandering_zombie_set_off(object);
			return y;
		case -4:
			wandering_zombie_walk(object);
			return y;
		case -2:
			wandering_zombie_remove_when_gone(object);
			return y;
		}
		break;
	}
	wandering_zombie_remove_when_sunk(object);
	return y;
}

/* Starts the wandering zombie's sinking animation (its base animation in field 30, plus 2). */
void wandering_zombie_start_sinking(uint16_t object)
{
	uint8_t parameter = 0, action = 0;

	parameter = OBJECT(object)->parameter;
	OBJECT(object)->animation = (parameter + 2u) | 0x80u;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* Frees the wandering zombie's slot when its sinking animation ends. */
void wandering_zombie_remove_when_sunk(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
		OBJECT(object)->flags = 0u;
}

/* Sets the wandering zombie up, hidden, with its wait, how long it walks, its direction and its
   animation from kind_97_timed_moves by its state. */
uint16_t wandering_zombie_setup(uint16_t object)
{
	uint8_t start_animation = 0;
	uint16_t move = 0, setup = 0, y = 0;
	uint8_t parameter = 0, state = 0;
	uint16_t delay = 0, direction = 0;

	setup = wandering_zombie_object_setup_ADDRESS;
	y = vector_object_setup(object, setup);
	OBJECT(object)->flags = 4u;
	parameter = OBJECT(object)->parameter;
	move = kind_97_timed_moves_ADDRESS + (int8_t)(((uint32_t)parameter << 1) << 1);
	delay = (((uint32_t)TIMED_MOVE(move)->delay << 8u) | TIMED_MOVE(move)->travel);
	OBJECT(object)->wandering_zombie.wait = delay >> 8;
	OBJECT(object)->timer = delay;
	direction = (((uint32_t)TIMED_MOVE(move)->direction << 8u) | TIMED_MOVE(move)->animation);
	start_animation = (uint8_t)direction;
	OBJECT(object)->wandering_zombie.direction = direction >> 8;
	OBJECT(object)->parameter = start_animation;
	OBJECT(object)->animation = start_animation;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return y;
}

/* Counts the wandering zombie's wait down, then shows it rising, turned to the nearest player. */
void wandering_zombie_wait(uint16_t object)
{
	uint16_t u = 0;
	uint8_t wait = 0, animation = 0, state = 0;

	wait = OBJECT(object)->wandering_zombie.wait;
	OBJECT(object)->wandering_zombie.wait = wait - 1u;
	if (wait != 1u)
		return;
	u = vector_choose_nearest_player(object);
	vector_measure_target(object, u);
	OBJECT(object)->flags = 0x80u;
	animation = OBJECT(object)->animation;
	OBJECT(object)->animation = animation | 0x80u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	vector_face_direction(object);
}

/* When the rising animation ends, sets the wandering zombie walking in its direction (field 3E), facing
   the way it goes. */
void wandering_zombie_set_off(uint16_t object)
{
	uint16_t direction = 0;
	uint8_t animation_flags = 0, direction_2 = 0, parameter = 0, state = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	OBJECT(object)->flags = 0xC0u;
	direction_2 = OBJECT(object)->wandering_zombie.direction;
	direction = (uint32_t)direction_2 << 8;
	vector_set_walk_speed_by_direction(object, 0u, direction);
	parameter = OBJECT(object)->parameter;
	OBJECT(object)->animation = (parameter + 1u) | 0x80u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	face_movement(object);
}

/* Counts the wandering zombie's walk down, then stops it and starts it sinking. */
void wandering_zombie_walk(uint16_t object)
{
	uint8_t walk_animation = 0;
	uint8_t timer = 0, parameter = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0;
		parameter = OBJECT(object)->parameter;
		walk_animation = (parameter + 2u) | 0x80u;
		OBJECT(object)->animation = walk_animation;
		OBJECT(object)->flags = walk_animation;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Frees the wandering zombie's slot when its sinking animation ends. */
void wandering_zombie_remove_when_gone(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
		OBJECT(object)->flags = 0u;
}

/* Sets a zombie up: with field 30 bit 7 it comes in at once with the behaviour zombie_behaviour, turned
   to its player; otherwise it stays hidden and takes its next state, flags and behaviour from
   object_18_behaviours. */
uint16_t zombie_setup(uint16_t object)
{
	uint16_t choice = 0, setup = 0, u = 0, y = 0;
	uint8_t parameter = 0, parameter_2 = 0, attributes = 0, state_2 = 0;
	uint16_t state = 0, behaviour = 0;

	setup = zombie_object_setup_ADDRESS;
	y = vector_object_setup(object, setup);
	OBJECT(object)->zombie.vanishes = 1u;
	parameter = OBJECT(object)->parameter;
	if ((int8_t)parameter < 0)
	{
		OBJECT(object)->behaviour = 0x78C0u;
		u = vector_choose_nearest_player(object);
		vector_measure_target(object, u);
		OBJECT(object)->parameter = 0u;
		OBJECT(object)->state = 2u;
		return y;
	}
	OBJECT(object)->flags = 4u;
	parameter_2 = OBJECT(object)->parameter;
	choice = object_18_behaviours_ADDRESS + (int8_t)(((uint32_t)parameter_2 << 1) << 1);
	state = (((uint32_t)BEHAVIOUR_CHOICE(choice)->state << 8u) | BEHAVIOUR_CHOICE(choice)->flags);
	OBJECT(object)->parameter = state >> 8;
	attributes = OBJECT(object)->attributes;
	priority_bits = attributes & 0x30u;
	OBJECT(object)->attributes = state | priority_bits;
	behaviour = BEHAVIOUR_CHOICE(choice)->behaviour;
	OBJECT(object)->behaviour = behaviour;
	state_2 = OBJECT(object)->state;
	OBJECT(object)->state = state_2 + 1u;
	return y;
}

/* The zombie's way in, by field 28: rising out of the ground (or walking in as kind 97) until it joins
   the fight. */
uint16_t zombie_come_out(uint16_t object, uint16_t y)
{
	uint16_t ignored16 = 0, y_2 = 0;
	uint8_t action = 0;

	action = OBJECT(object)->action;
	switch ((int8_t)(uint8_t)((uint32_t)action << 1))
	{
	case 0:
		zombie_start_coming_out(object);
		return y;
	case 2:
		zombie_finish_rising(object);
		return y;
	case 4:
		zombie_finish_climbing(object);
		return y;
	case 6:
		zombie_remove_when_sunk(object);
		return y;
	case 8:
		zombie_walk_in(object);
		return y;
	case 10:
		zombie_burrow_start(object);
		return y;
	case 12:
		zombie_burrow_move(object);
		return y;
	case 14:
		zombie_burrow_surface(object);
		return y;
	case 16:
		zombie_burrow_end(object);
		return y;
	case 18:
		zombie_leap_start(object);
		return y;
	case 20:
		zombie_leap_take_off(object);
		return y;
	case 22:
		return zombie_leap_rise(object, y);
	case 24:
		return zombie_leap_fall(object, y);
	case 26:
		zombie_leap_turn(object);
		return y;
	case 28:
		zombie_leap_end(object);
		return y;
	case 30:
		zombie_swipe_start(object);
		return y;
	case 32:
		return zombie_swipe_hit(object, y);
	case 34:
		return zombie_swipe_recover(object);
	case 36:
		zombie_swipe_step_back(object);
		return y;
	case 38:
		zombie_swipe_end(object);
		return y;
	case 40:
		kind_9a_dropper_fall(object, &y, &ignored16);
		return y;
	case 42:
		kind_9a_dropper_hurt(object, &y, &ignored16);
		return y;
	case 44:
		kind_9a_dropper_setup(object, &y_2, &ignored16);
		return y_2;
	case 46:
		kind_9a_dropper_wait_mode(object);
		return y;
	case 48:
		kind_9a_dropper_watch(object, 0u);
		return y;
	case 50:
		kind_9a_dropper_drop(object, &y, &ignored16);
		return y;
	case 52:
		return kind_9a_dropper_hang(object, y);
	case 54:
		kind_9a_dropper_climb(object);
		return y;
	case 56:
		kind_9a_dropper_hurt_start(object);
		return y;
	case 58:
		kind_9a_dropper_hurt_flash(object);
		return y;
	}
	unreachable();
}

/* Starts the zombie's way in: either walking in from the side's edge with kind 97's walk, or rising out
   of the ground with its sound. */
uint16_t zombie_start_coming_out(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t start_parameter = 0;
	uint16_t command = 0, u = 0;
	uint8_t parameter = 0, parameter_2 = 0, action = 0;
	uint16_t t1 = 0, x_speed = 0;

	parameter = OBJECT(object)->parameter;
	if ((parameter & 3u) == 3u)
		OBJECT(object)->vitality = 8u;
	u = vector_choose_nearest_player(object);
	vector_measure_target(object, u);
	parameter_2 = OBJECT(object)->parameter;
	start_parameter = parameter_2;
	if ((int8_t)parameter_2 < 0)
	{
		OBJECT(object)->flags = 0x80u;
		OBJECT(object)->kind = 0x97u;
		OBJECT(object)->animation = 0x90u;
		OBJECT(object)->x_speed = 0x100;
		t1 = OBJECT(object)->x;
		if (t1 >= 0xE0u)
		{
			x_speed = OBJECT(object)->x_speed;
			OBJECT(object)->x_speed = 0u - x_speed;
		}
		OBJECT(object)->timer = 0x80u;
		OBJECT(object)->action = 4u;
		return u;
	}
	OBJECT(object)->parameter = start_parameter & 0x7Fu;
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->animation = 0x92u;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
	command = 0x7B00u;
	carry = vector_queue_sound(command);
	return u;
}

/* Unused: does nothing. */
void unused_zombie_no_op(void)
{
}

/* When the zombie's rising animation ends, makes it hittable and, for states 0-1, plays its climbing-out
   animation; others join the fight at once. */
void zombie_finish_rising(uint16_t object)
{
	uint8_t animation_flags = 0, parameter = 0, state = 0, action = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	OBJECT(object)->flags = 0xC0u;
	parameter = OBJECT(object)->parameter;
	if (parameter >= 2u)
	{
		OBJECT(object)->retarget_time = 0x10u;
		OBJECT(object)->parameter = 0u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
		return;
	}
	OBJECT(object)->animation = 0x87u;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* When the climbing-out animation ends, a zombie of state 1 joins the fight (step 2); one of state 0
   sinks back into the ground (animation 93), out of reach. */
void zombie_finish_climbing(uint16_t object)
{
	uint8_t animation_flags = 0, parameter = 0, action = 0, state = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	parameter = OBJECT(object)->parameter;
	if (parameter == 0u)
	{
		OBJECT(object)->flags = 0x80u;
		OBJECT(object)->animation = 0x93u;
		action = OBJECT(object)->action;
		OBJECT(object)->action = action + 1u;
		return;
	}
	OBJECT(object)->retarget_time = 0x10u;
	OBJECT(object)->parameter = 0u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Frees the zombie's slot when its sinking animation ends. */
void zombie_remove_when_sunk(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
		OBJECT(object)->flags = 0u;
}

/* Walks the zombie in for a while (field 3B), then turns it back into kind 91 rising out of the ground,
   with its sound. */
void zombie_walk_in(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->kind = 0x91u;
	OBJECT(object)->animation = 0x92u;
	OBJECT(object)->action = 1u;
	command = 0x7B00u;
	carry = vector_queue_sound(command);
}

/* Starts the zombie sinking into the ground (animation 93). */
void zombie_burrow_start(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->animation = 0x93u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* When the zombie has sunk, moves it under the ground toward its player: across if it is far, along the
   depth if it is near. */
void zombie_burrow_move(uint16_t object)
{
	uint8_t frame_flags = 0;
	uint8_t animation_flags = 0, target_direction = 0, action_step = 0, target_direction_2 = 0;
	uint16_t target_dx = 0, y_speed = 0, x_speed = 0;

	animation_flags = OBJECT(object)->animation_flags;
	frame_flags = animation_flags;
	if ((frame_flags & 2u) != 0u)
		OBJECT(object)->flags = 0x80u;
	if ((frame_flags & 1u) == 0u)
		return;
	target_dx = OBJECT(object)->target_dx;
	if (target_dx < 0x40u)
	{
		OBJECT(object)->timer = 0x20u;
		OBJECT(object)->y_speed = 0x80;
		target_direction = OBJECT(object)->target_direction;
		if ((int8_t)target_direction < 0)
		{
			y_speed = OBJECT(object)->y_speed;
			OBJECT(object)->y_speed = 0u - y_speed;
		}
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
		return;
	}
	OBJECT(object)->x_speed = 0x180;
	target_direction_2 = OBJECT(object)->target_direction;
	if ((int8_t)(target_direction_2 - 0x40u) >= 0)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	OBJECT(object)->timer = 0x50u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* When the zombie's move under the ground is over, stops it and brings it up again with its sound,
   facing its player. */
void zombie_burrow_surface(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t timer = 0, action_step = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->animation = 0x92u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	command = 0x7B00u;
	carry = vector_queue_sound(command);
	vector_face_direction(object);
}

/* Makes the zombie hittable on the rising animation's marked frame and ends the action when it ends. */
void zombie_burrow_end(uint16_t object)
{
	uint8_t frame_flags = 0;
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	frame_flags = animation_flags;
	if ((frame_flags & 2u) != 0u)
		OBJECT(object)->flags = 0xC0u;
	if (frame_flags & 1u)
	{
		OBJECT(object)->state = 2u;
		OBJECT(object)->timer = 0u;
		return;
	}
}

/* Turns the zombie to its player and starts its crouch before the leap. */
void zombie_leap_start(uint16_t object)
{
	uint8_t action_step = 0;

	face_target(object);
	OBJECT(object)->animation = 0x91u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* On the crouch's marked frame, sends the zombie leaping toward its player with a sound. */
void zombie_leap_take_off(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t animation_flags = 0, target_direction = 0, action_step = 0;
	uint16_t x_speed = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) == 0u)
		return;
	command = 0x301u;
	carry = vector_queue_sound(command);
	OBJECT(object)->x_speed = 0x100;
	OBJECT(object)->z_speed = 0x400;
	target_direction = OBJECT(object)->target_direction;
	if ((int8_t)(target_direction - 0x40u) >= 0)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	OBJECT(object)->flags = 0xC8u;
	OBJECT(object)->animation_flags = 0x80u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Slows the zombie's leap as it rises; once it falls, gives it its attacking hit box. */
uint16_t zombie_leap_rise(uint16_t object, uint16_t box)
{
	uint8_t action_step = 0;
	uint16_t z_speed = 0, z_speed_2 = 0;

	z_speed = OBJECT(object)->z_speed;
	if ((int16_t)z_speed >= 0)
	{
		z_speed_2 = OBJECT(object)->z_speed;
		OBJECT(object)->z_speed = z_speed_2 - 0x10u;
		return zombie_leap_land(object, box);
	}
	box = zombie_leap_rise_box_ADDRESS;
	vector_set_hit_box(object, box);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	return zombie_leap_fall(object, box);
}

/* Pulls the zombie down faster as it falls, then checks its landing. */
uint16_t zombie_leap_fall(uint16_t object, uint16_t box)
{
	uint16_t z_speed = 0;

	z_speed = OBJECT(object)->z_speed;
	OBJECT(object)->z_speed = z_speed - 0x40u;
	return zombie_leap_land(object, box);
}

/* When the leaping zombie lands, gives it back its plain hit box and stops it with the landing sound and
   a wait. */
uint16_t zombie_leap_land(uint16_t object, uint16_t box)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t action_step = 0;

	carry = vector_check_landing(object);
	if (carry == 0u)
		return box;
	box = zombie_body_box_ADDRESS;
	vector_set_hit_box(object, box);
	OBJECT(object)->x_speed = 0;
	command = 0x2000u;
	carry = vector_queue_sound(command);
	OBJECT(object)->timer = 0x20u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	return box;
}

/* Holds the zombie still after landing, then turns it round. */
void zombie_leap_turn(uint16_t object)
{
	uint8_t timer = 0, action_step = 0, attributes = 0;

	OBJECT(object)->animation = 0x90u;
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->timer = 0x20u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
		attributes = OBJECT(object)->attributes;
		OBJECT(object)->attributes = attributes ^ 0x40u;
	}
}

/* Holds the zombie still a moment more and ends the action. */
void zombie_leap_end(uint16_t object)
{
	uint8_t timer = 0;

	OBJECT(object)->animation = 0x90u;
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->state = 2u;
		OBJECT(object)->timer = 0u;
		return;
	}
}

/* Starts the zombie's swipe, turned to its player. */
void zombie_swipe_start(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->animation = 0x90u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	face_target(object);
}

/* On the swipe's marked frame, gives the zombie its attacking hit box. */
uint16_t zombie_swipe_hit(uint16_t object, uint16_t y)
{
	uint16_t box = 0;
	uint8_t animation_flags = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) == 0u)
		return y;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	box = zombie_swipe_hit_box_ADDRESS;
	vector_set_hit_box(object, box);
	return box;
}

/* Gives the zombie back its plain hit box and goes on to its step back. */
uint16_t zombie_swipe_recover(uint16_t object)
{
	uint16_t box = 0;
	uint8_t action_step = 0;

	box = zombie_body_box_ADDRESS;
	vector_set_hit_box(object, box);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	zombie_swipe_step_back(object);
	return box;
}

/* When the swipe ends, walks the zombie backwards for 32 frames. */
void zombie_swipe_step_back(uint16_t object)
{
	uint8_t animation_flags = 0, attributes = 0, action_step = 0;
	uint16_t x_speed = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	OBJECT(object)->animation = 0x81u;
	OBJECT(object)->x_speed = -0x100;
	attributes = OBJECT(object)->attributes;
	if ((attributes & 0x40u) != 0u)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	OBJECT(object)->timer = 0x20u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Stops the zombie's step back when its time is up and ends the action. */
void zombie_swipe_end(uint16_t object)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->state = 2u;
	OBJECT(object)->timer = 0u;
}

/* Unused: when its animation ends, its timer at 1 and back to state 1. */
void unused_zombie_restart_at_animation_end(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		OBJECT(object)->timer = 1u;
		OBJECT(object)->state = 1u;
	}
}
