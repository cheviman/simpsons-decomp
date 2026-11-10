/**
 *    Name:        objects/krustyland_bear.c
 *    Description: Krustyland's bear and its kind B2 companions
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Sets up the bear. */
void krustyland_bear_start(uint16_t object, uint16_t *p_box, uint16_t *p_setup)
{
	uint16_t box = 0, setup = 0;
	uint8_t state = 0;

	setup = krustyland_bear_setup_ADDRESS;
	box = vector_object_setup(object, setup);
	OBJECT(object)->attributes = 0xADu;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	*p_box = box;
	*p_setup = setup;
}

/* Waits for the camera to reach 0420. */
void krustyland_bear_wait_camera(uint16_t object)
{
	uint8_t state = 0;
	uint16_t t1 = 0;

	t1 = camera_x;
	if (t1 >= 0x420u)
	{
		OBJECT(object)->timer = 0x20u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* After 32 frames wakes with sound 7400. */
void krustyland_bear_wake(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	command = 0x7400u;
	carry = vector_queue_sound(command);
	OBJECT(object)->animation = 0x81u;
	OBJECT(object)->timer = 0x40u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* After 64 frames starts off up the screen with sound 7300 (its kind B2 companion leaps off now). */
void krustyland_bear_start_off(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	command = 0x7300u;
	carry = vector_queue_sound(command);
	OBJECT(object)->y_speed = -0x100;
	OBJECT(object)->timer = 0x20u;
	OBJECT(object)->animation = 0x80u;
	OBJECT(object)->attributes = 0x9Du;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* After 32 frames rides across the stage. */
void krustyland_bear_ride(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->x_speed = 0x200;
		OBJECT(object)->y_speed = 0;
		OBJECT(object)->z = 0u;
		OBJECT(object)->animation = 0x8Du;
		OBJECT(object)->shadow_player = 1u;
		OBJECT(object)->flags = 0xC8u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Does nothing while it rides. */
void krustyland_bear_idle(void)
{
}

/* Sets up the kind B2 object. */
void kind_b2_start(uint16_t object, uint16_t *p_box, uint16_t *p_setup)
{
	uint16_t box = 0, setup = 0;
	uint8_t state = 0;

	setup = kind_b2_setup_ADDRESS;
	box = vector_object_setup(object, setup);
	OBJECT(object)->attributes = 0x10u;
	OBJECT(object)->kind_b2.idle_frames = 0x10u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	*p_box = box;
	*p_setup = setup;
}

/* Calls out (sound 6800) once on screen, switches between its two idle animations, until hit. */
uint16_t kind_b2_idle(uint16_t object, uint16_t states)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t idle_frames = 0, state = 0, idle_frames_2 = 0, timer = 0, timer_2 = 0, idle_number = 0, idle_number_2 = 0;
	uint16_t t1 = 0, t2 = 0;

	idle_frames = OBJECT(object)->kind_b2.idle_frames;
	if (idle_frames != 0u)
	{
		t1 = OBJECT(object)->x;
		if (t1 < 0x130u)
		{
			t2 = OBJECT(object)->y;
			if (t2 < 0x120u)
			{
				OBJECT(object)->kind_b2.idle_frames = 0u;
				command = 0x6800u;
				carry = vector_queue_sound(command);
			}
		}
	}
	if ((OBJECT(object)->flags & 0x20u) != 0u)
	{
		OBJECT(object)->animation = 0x85u;
		OBJECT(object)->kind_b2.idle_frames = 0u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
		return states;
	}
	idle_frames_2 = OBJECT(object)->kind_b2.idle_frames;
	if (idle_frames_2 == 0u)
	{
		timer = OBJECT(object)->timer;
		OBJECT(object)->timer = timer - 1u;
		timer_2 = OBJECT(object)->timer;
		if ((timer_2 & 0x7Fu) == 0u)
		{
			states = kind_b2_idle_animations_ADDRESS;
			idle_number = OBJECT(object)->kind_b2.idle_number;
			OBJECT(object)->kind_b2.idle_number = idle_number + 1u;
			idle_number_2 = OBJECT(object)->kind_b2.idle_number;
			OBJECT(object)->animation = kind_b2_idle_animations[idle_number_2 & 1u];
		}
	}
	return states;
}

/* Hit: takes its hit hit box. */
uint16_t kind_b2_hit(uint16_t object)
{
	uint16_t box = 0;
	uint8_t state = 0;

	box = kind_b2_hit_box_ADDRESS;
	vector_set_hit_box(object, box);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return box;
}

/* Takes its standing hit box back and waits 128 frames. */
uint16_t kind_b2_hit_wait(uint16_t object)
{
	uint16_t box = 0;
	uint8_t state = 0;

	box = kind_b2_body_box_ADDRESS;
	vector_set_hit_box(object, box);
	OBJECT(object)->timer = 0x80u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return box;
}

/* Calls out again (sound 6800) and gets up. */
void kind_b2_recover(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	command = 0x6800u;
	carry = vector_queue_sound(command);
	OBJECT(object)->animation = 0x81u;
	OBJECT(object)->timer = 0x60u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* After 96 frames goes back to idling. */
void kind_b2_recover_end(uint16_t object)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->state = 1u;
		OBJECT(object)->timer = 1u;
		OBJECT(object)->kind_b2.idle_number = 1u;
	}
}
