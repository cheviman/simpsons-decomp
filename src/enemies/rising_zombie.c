/**
 *    Name:        enemies/rising_zombie.c
 *    Description: the zombie of the list at 5280 (type 18) that rises and drifts toward an object
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Sets the rising zombie up, hidden, with its wait, flags and the step it starts at from
   kind_91_appearances, and the object at work RAM 1854 to drift toward. */
uint16_t rising_zombie_setup(uint16_t object)
{
	uint16_t setup = 0, start = 0;
	uint8_t parameter = 0;
	uint16_t drift_object = 0, wait = 0, step = 0;

	setup = rising_zombie_object_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->flags = 4u;
	drift_object = io_read16(stage_kept_object_2);
	OBJECT(object)->rising_zombie.drift_target = drift_object;
	parameter = OBJECT(object)->parameter;
	start = kind_91_appearances_ADDRESS + (int8_t)(((uint32_t)parameter << 1) << 1);
	wait = (((uint32_t)APPEARANCE(start)->wait << 8u) | APPEARANCE(start)->flags);
	OBJECT(object)->timer = wait >> 8;
	OBJECT(object)->attributes = wait;
	step = (((uint32_t)APPEARANCE(start)->step << 8u) | APPEARANCE(start)->unused);
	OBJECT(object)->state = step >> 8;
	return start;
}

/* Counts the zombie's wait down, then shows it rising out of the ground with its sound. */
void rising_zombie_wait(uint16_t object)
{
	uint16_t command = 0;
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->animation = 0x92u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	command = 0x7B00u;
	vector_queue_sound(command);
}

/* When the rising animation ends, plays the climbing-out one. */
void rising_zombie_climb_out(uint16_t object)
{
	uint8_t animation_flags = 0, state = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		OBJECT(object)->animation = 0x87u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* When the climbing-out animation ends, takes the direction toward its object (field 40) and waits 64
   frames. */
uint16_t rising_zombie_aim(uint16_t object, uint16_t drift_target)
{
	uint8_t direction = 0;
	uint16_t aim = 0;
	uint8_t animation_flags = 0, state = 0;
	uint16_t drift_target_2 = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return drift_target;
	drift_target_2 = OBJECT(object)->rising_zombie.drift_target;
	drift_target = drift_target_2;
	aim = vector_direction_to(object, drift_target);
	direction = (uint8_t)(aim >> 8);
	OBJECT(object)->rising_zombie.direction = direction;
	OBJECT(object)->timer = 0x40u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return drift_target;
}

/* Counts the wait down, then plays animation 94. */
void rising_zombie_stand(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->timer = 0x80u;
		OBJECT(object)->animation = 0x94u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* When that animation ends, plays animation 99. */
void rising_zombie_rise_up(uint16_t object)
{
	uint8_t animation_flags = 0, state = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		OBJECT(object)->animation = 0x99u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Counts down, then sets it drifting slowly in its direction (animation 9A) for 128 frames. */
void rising_zombie_set_off(uint16_t object)
{
	uint16_t heading = 0;
	uint8_t timer = 0, direction = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	direction = OBJECT(object)->rising_zombie.direction;
	heading = ((uint32_t)direction << 8) | 0xCu;
	vector_set_speed_by_direction(object, heading);
	OBJECT(object)->animation = 0x9Au;
	OBJECT(object)->timer = 0x80u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Counts the drift down, then stops its move in depth. */
void rising_zombie_drift(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->y_speed = 0;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Counts field 3B down, then goes on to the next step. */
void rising_zombie_count_down(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Takes a little off its x speed each frame. */
void rising_zombie_slow_down(uint16_t object)
{
	uint16_t x_speed = 0;

	x_speed = OBJECT(object)->x_speed;
	OBJECT(object)->x_speed = x_speed - 1u;
}

/* The second way in: when the rising animation ends, plays the climbing-out one. */
void rising_zombie_climb_out_again(uint16_t object)
{
	uint8_t animation_flags = 0, state = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		OBJECT(object)->animation = 0x87u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* When the climbing-out animation ends, plays animation 94. */
void rising_zombie_stand_again(uint16_t object)
{
	uint8_t animation_flags = 0, state = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		OBJECT(object)->animation = 0x94u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Counts down, then sets it walking slowly right (animation 9A) and drifting (step 9). */
void rising_zombie_walk_off(uint16_t object)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->x_speed = 0x80;
		OBJECT(object)->animation = 0x9Au;
		OBJECT(object)->state = 9u;
	}
}
