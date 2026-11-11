/**
 *    Name:        objects/kind_95.c
 *    Description: the kind 95 character of stage 2
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Beaten: cries out (sound 6300) and runs off to the left. */
void kind_95_beaten(uint16_t object)
{
	uint16_t command = 0;

	command = 0x6300u;
	vector_queue_sound(command);
	OBJECT(object)->x_speed = -0x200;
	OBJECT(object)->animation = 0x81u;
	OBJECT(object)->state = 0xFDu;
	face_movement(object);
}

/* Runs its reaction to a hit by its substep. */
uint16_t kind_95_hit_steps(uint16_t object)
{
	uint16_t step_handlers = 0;
	uint8_t action_step = 0;

	for (;;)
	{
		step_handlers = kind_95_hit_step_handlers_ADDRESS;
		action_step = OBJECT(object)->action_step;
		switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
		{
		case 0:
			kind_95_hit(object);
			return step_handlers;
		case 2:
			break;
		case -10:
			kind_95_wait();
			return step_handlers;
		case -8:
			kind_95_beaten(object);
			return step_handlers;
		case -6:
			continue;
		case -4:
			return kind_95_start(object);
		case -2:
			kind_95_stand();
			return step_handlers;
		}
		break;
	}
	kind_95_hit_end(object);
	return step_handlers;
}

/* Shows its hit animation for 64 frames. */
void kind_95_hit(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->animation = 0x82u;
	OBJECT(object)->timer = 0x40u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	kind_95_wait();
}

/* Does nothing. */
void kind_95_wait(void)
{
}

/* After its hit animation, stands again. */
void kind_95_hit_end(uint16_t object)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->flags = 0xC0u;
		OBJECT(object)->state = 1u;
		OBJECT(object)->animation = 0x80u;
	}
}

/* Sets up the kind 95 character. */
uint16_t kind_95_start(uint16_t object)
{
	uint16_t setup = 0;
	uint8_t state = 0;

	setup = kind_95_setup_ADDRESS;
	vector_object_setup(object, setup);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	kind_95_stand();
	return setup;
}

/* Does nothing while it stands. */
void kind_95_stand(void)
{
}
