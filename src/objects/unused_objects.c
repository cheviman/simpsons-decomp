/**
 *    Name:        objects/unused_objects.c
 *    Description: objects nothing puts in
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    10-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Unused: sets the kind B7 object moving left; state 0 only slides. */
void unused_kind_b7_start(uint16_t object)
{
	uint16_t setup = 0;
	uint8_t parameter = 0, state = 0;

	setup = unused_kind_b7_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->flags = 0xC8u;
	OBJECT(object)->floor_z = 0u;
	OBJECT(object)->x_speed = -0x200;
	parameter = OBJECT(object)->parameter;
	if (parameter != 0u)
	{
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
		return;
	}
	OBJECT(object)->state = 3u;
}

/* Unused: falls and bounces high with sound 2000. */
void unused_kind_b7_bounce(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t state = 0;
	uint16_t z_speed = 0;

	z_speed = OBJECT(object)->z_speed;
	OBJECT(object)->z_speed = z_speed - 0x40u;
	carry = vector_check_landing(object);
	if (carry == 0u)
		return;
	OBJECT(object)->flags = 0xC8u;
	OBJECT(object)->z_speed = 0x600;
	command = 0x2000u;
	carry = vector_queue_sound(command);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Unused: falls and lands with sound 2000. */
void unused_kind_b7_land(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t state = 0;
	uint16_t z_speed = 0;

	z_speed = OBJECT(object)->z_speed;
	OBJECT(object)->z_speed = z_speed - 0x40u;
	carry = vector_check_landing(object);
	if (carry == 0u)
		return;
	command = 0x2000u;
	carry = vector_queue_sound(command);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	unused_kind_b7_speed_up(object);
}

/* Unused: speeds the object up to the left. */
void unused_kind_b7_speed_up(uint16_t object)
{
	uint16_t x_speed = 0;

	x_speed = OBJECT(object)->x_speed;
	OBJECT(object)->x_speed = x_speed - 0x10u;
}

/* Unused: runs the unused obstacle by its state, then takes a special hit. */
void unused_obstacle_update(uint16_t object, uint8_t state)
{
	switch ((int8_t)(uint8_t)((uint32_t)state << 1))
	{
	case 0:
		unused_obstacle_start(object);
		break;
	case 2:
		unused_obstacle_idle();
		break;
	case 4:
		unused_obstacle_break(object);
		break;
	case 6:
		unused_obstacle_break_end(object);
		break;
	case -4:
	case -2:
		unused_obstacle_break_steps(object);
		break;
	}
	object_take_special_hit(object, 0u);
}

/* Unused: runs the obstacle's breaking by its substep. */
void unused_obstacle_break_steps(uint16_t object)
{
	uint8_t action_step = 0;

	for (;;)
	{
		action_step = OBJECT(object)->action_step;
		switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
		{
		case 0:
			unused_obstacle_break(object);
			return;
		case 2:
			break;
		case -8:
		case -6:
			continue;
		case -4:
			unused_obstacle_start(object);
			return;
		case -2:
			unused_obstacle_idle();
			return;
		}
		break;
	}
	unused_obstacle_break_end(object);
}

/* Unused: breaks the obstacle with sound 6C00. */
void unused_obstacle_break(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t action_step = 0;

	OBJECT(object)->animation = 0x80u;
	command = 0x6C00u;
	carry = vector_queue_sound(command);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Unused: takes the obstacle away when its breaking animation ends. */
void unused_obstacle_break_end(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
		OBJECT(object)->flags = 0u;
}

/* Unused: sets up an obstacle at x 0200 with sound 6700. */
void unused_obstacle_start(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0, setup = 0;
	uint8_t state = 0;

	setup = unused_obstacle_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->x = 0x200u;
	OBJECT(object)->attributes = 0x10u;
	command = 0x6700u;
	carry = vector_queue_sound(command);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Unused: does nothing. */
void unused_obstacle_idle(void)
{
}
