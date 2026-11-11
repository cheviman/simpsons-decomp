/**
 *    Name:        objects/buzzing_chaser.c
 *    Description: the buzzing thing let out by the object falling off the shaking scenery
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    10-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Sets the chaser rising out with sound 7200, ready to spiral out four times. */
uint16_t buzzing_chaser_start(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0, setup = 0;
	uint8_t attributes = 0, state = 0;

	setup = buzzing_chaser_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->flags = 0x80u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0x10u;
	OBJECT(object)->z_speed = 0x40;
	OBJECT(object)->timer = 0x20u;
	OBJECT(object)->buzzing_chaser.turn = 1u;
	OBJECT(object)->buzzing_chaser.speed = 0x40u;
	OBJECT(object)->buzzing_chaser.chases_left = 4u;
	command = 0x7200u;
	carry = vector_queue_sound(command);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return setup;
}

/* Rises for 32 frames while spiralling, then flies level. */
void buzzing_chaser_rise(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
	{
		buzzing_chaser_spiral(object);
		return;
	}
	OBJECT(object)->z_speed = 0;
	OBJECT(object)->animation = 0x9Eu;
	OBJECT(object)->timer = 0x20u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	buzzing_chaser_spiral(object);
}

/* Moves along a widening spiral: its direction turning faster, its speed falling. */
void buzzing_chaser_spiral(uint16_t object)
{
	uint8_t direction = 0;
	uint16_t heading = 0;
	uint8_t timer = 0, turn = 0, speed = 0, direction_2 = 0, turn_2 = 0, speed_2 = 0;

	timer = OBJECT(object)->timer;
	if ((timer & 1u) == 0u)
		return;
	turn = OBJECT(object)->buzzing_chaser.turn;
	OBJECT(object)->buzzing_chaser.turn = turn + 1u;
	speed = OBJECT(object)->buzzing_chaser.speed;
	OBJECT(object)->buzzing_chaser.speed = speed - 1u;
	direction_2 = OBJECT(object)->buzzing_chaser.direction;
	turn_2 = OBJECT(object)->buzzing_chaser.turn;
	direction = direction_2 + turn_2;
	OBJECT(object)->buzzing_chaser.direction = direction;
	speed_2 = OBJECT(object)->buzzing_chaser.speed;
	heading = ((uint32_t)direction << 8) | speed_2;
	vector_set_speed_by_direction(object, heading);
}

/* After 32 frames more of spiralling, starts hitting and chasing. */
void buzzing_chaser_spiral_end(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
	{
		buzzing_chaser_spiral(object);
		return;
	}
	OBJECT(object)->timer = 1u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	OBJECT(object)->flags = 0xC0u;
}

/* Chases its target (circling while it is down), buzzing and picking the nearest player every 64 frames,
   four times. */
uint16_t buzzing_chaser_chase(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t direction = 0, z_speed_high = 0, z_speed_low = 0;
	uint16_t command = 0, direction_to_target = 0, heading = 0, target = 0;
	uint8_t timer = 0, state = 0, direction_2 = 0, timer_2 = 0, timer_3 = 0, chases_left = 0, state_2 = 0;
	uint16_t target_2 = 0, z = 0, target_height = 0, z_2 = 0;

	target_2 = OBJECT(object)->target;
	target = target_2;
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
	{
		state = OBJECT(target)->state;
		if ((int8_t)state < 0)
		{
			direction_2 = OBJECT(object)->buzzing_chaser.direction;
			direction = direction_2 + 0x10u;
			OBJECT(object)->buzzing_chaser.direction = direction;
			heading = ((uint32_t)direction << 8) | 0x40u;
			vector_set_speed_by_direction(object, heading);
			buzzing_chaser_idle();
			return target;
		}
		timer_2 = OBJECT(object)->timer;
		if ((timer_2 & 0xFu) == 0u)
		{
			z = OBJECT(target)->z;
			target_height = z + 0x30u;
			z_2 = OBJECT(object)->z;
			if (z_2 <= target_height)
			{
				z_speed_high = 0u;
				z_speed_low = 0x40u;
			}
			else
			{
				z_speed_high = 0xFFu;
				z_speed_low = 0xC0u;
			}
			OBJECT(object)->z_speed = ((uint32_t)z_speed_high << 8) | z_speed_low;
		}
		timer_3 = OBJECT(object)->timer;
		if (timer_3 >= 0xFu)
		{
			direction_to_target = vector_direction_to(object, target);
			direction = (uint8_t)(direction_to_target >> 8);
			OBJECT(object)->buzzing_chaser.direction = direction;
			heading = ((uint32_t)direction << 8) | 0x40u;
			vector_set_speed_by_direction(object, heading);
			return target;
		}
		direction_2 = OBJECT(object)->buzzing_chaser.direction;
		direction = direction_2 + 0x10u;
		OBJECT(object)->buzzing_chaser.direction = direction;
		heading = ((uint32_t)direction << 8) | 0x40u;
		vector_set_speed_by_direction(object, heading);
		buzzing_chaser_idle();
		return target;
	}
	command = 0x7200u;
	carry = vector_queue_sound(command);
	OBJECT(object)->timer = 0x40u;
	target = vector_choose_nearest_player(object);
	chases_left = OBJECT(object)->buzzing_chaser.chases_left;
	OBJECT(object)->buzzing_chaser.chases_left = chases_left - 1u;
	if (chases_left != 1u)
	{
		direction_to_target = vector_direction_to(object, target);
		direction = (uint8_t)(direction_to_target >> 8);
		OBJECT(object)->buzzing_chaser.direction = direction;
		heading = ((uint32_t)direction << 8) | 0x40u;
		vector_set_speed_by_direction(object, heading);
		return target;
	}
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->z_speed = 0;
	OBJECT(object)->timer = 0x20u;
	state_2 = OBJECT(object)->state;
	OBJECT(object)->state = state_2 + 1u;
	return target;
}

/* Does nothing. */
void buzzing_chaser_idle(void)
{
}

/* Circles for 32 frames more, then flies off to the left. */
void buzzing_chaser_fly_off(uint16_t object)
{
	uint8_t direction = 0;
	uint16_t heading = 0;
	uint8_t timer = 0, state = 0, direction_2 = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->x_speed = -0x400;
		OBJECT(object)->y_speed = 0;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
		return;
	}
	direction_2 = OBJECT(object)->buzzing_chaser.direction;
	direction = direction_2 + 0x10u;
	OBJECT(object)->buzzing_chaser.direction = direction;
	heading = ((uint32_t)direction << 8) | 0x40u;
	vector_set_speed_by_direction(object, heading);
	buzzing_chaser_idle();
}
