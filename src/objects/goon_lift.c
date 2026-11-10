/**
 *    Name:        objects/goon_lift.c
 *    Description: stage 7's lift that brings goons down (5280 types 39 and 3A)
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Sets the lift up hidden and puts in its two parts (type 3A). */
void goon_lift_setup(uint16_t object, uint16_t *p_y, uint16_t *p_u)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_3 = 0, part = 0, record = 0, setup = 0;
	uint8_t state = 0;

	setup = goon_lift_object_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->flags = 4u;
	OBJECT(object)->attributes = 0x20u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	record = goon_lift_part_child_1_ADDRESS;
	vector_spawn_child(object, record, &ignored16, &ignored16_3, &carry);
	record = goon_lift_part_child_2_ADDRESS;
	*p_u = part;
	vector_spawn_child(object, record, p_u, &ignored16_3, &carry);
	*p_y = record;
}

/* When the scroll brings it on, shows the lift coming down with its two goons (4F80 type 13). */
void goon_lift_arrive(uint16_t object, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t goon = 0, ignored16 = 0, ignored16_2 = 0, record = 0;
	uint8_t state = 0;
	uint16_t t1 = 0;

	t1 = OBJECT(object)->x;
	if (t1 >= 0x140u)
		return;
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->z_speed = -0x100;
	OBJECT(object)->timer = 0x60u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	record = goon_lift_goon_1_ADDRESS;
	vector_spawn_child(object, record, &ignored16, &ignored16_2, &carry);
	record = goon_lift_goon_2_ADDRESS;
	*p_u = goon;
	vector_spawn_child(object, record, p_u, &ignored16_2, &carry);
	*p_y = record;
}

/* Counts the descent down, then stops the lift for 128 frames. */
void goon_lift_stop(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->z_speed = 0;
		OBJECT(object)->timer = 0x80u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Counts down, then moves the lift down again for 96 frames. */
void goon_lift_descend(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->z_speed = -0x100;
		OBJECT(object)->timer = 0x60u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Counts down, then stops the lift for 32 frames. */
void goon_lift_settle(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->z_speed = 0;
	OBJECT(object)->timer = 0x20u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Counts down, then makes the lift hittable for 96 frames. */
void goon_lift_open(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->flags = 0xC0u;
		OBJECT(object)->timer = 0x60u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Counts down, then sends the lift back up, unhittable. */
void goon_lift_rise(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->flags = 0x80u;
		OBJECT(object)->z_speed = 0x100;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Counts the rise down and frees the lift's slot. */
void goon_lift_remove(uint16_t object)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
		OBJECT(object)->flags = 0u;
}

/* Sets the lift's part up with the lift's step it changes at, its wait and its height from
   kind_12_parts. */
void goon_lift_part_setup(uint16_t object, uint16_t *p_box, uint16_t *p_part)
{
	uint16_t box = 0, part = 0, setup = 0;
	uint8_t parameter = 0, height = 0, state = 0;
	uint16_t parent_step = 0;

	setup = goon_lift_part_object_setup_ADDRESS;
	box = vector_object_setup(object, setup);
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->attributes = 0x20u;
	parameter = OBJECT(object)->parameter;
	part = kind_12_parts_ADDRESS + (int8_t)(((uint32_t)parameter << 1) << 1);
	parent_step = (((uint32_t)KIND_12_PART(part)->parent_step << 8u) | KIND_12_PART(part)->wait);
	OBJECT(object)->goon_lift_part.lift_step = parent_step >> 8;
	OBJECT(object)->goon_lift_part.wait = parent_step;
	height = KIND_12_PART(part)->height;
	OBJECT(object)->z = height;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	*p_box = box;
	*p_part = part;
}

/* Waits for the lift (field 40) to reach its step, then plays animation 82. */
uint16_t goon_lift_part_wait_for_lift(uint16_t object)
{
	uint16_t lift = 0;
	uint8_t state = 0, lift_step = 0, state_2 = 0;
	uint16_t parent = 0;

	parent = OBJECT(object)->parent;
	lift = parent;
	state = OBJECT(lift)->state;
	lift_step = OBJECT(object)->goon_lift_part.lift_step;
	if (state == lift_step)
	{
		OBJECT(object)->animation = 0x82u;
		state_2 = OBJECT(object)->state;
		OBJECT(object)->state = state_2 + 1u;
	}
	return lift;
}

/* Counts its wait down, then plays animation 8F. */
void goon_lift_part_change(uint16_t object)
{
	uint8_t wait = 0, state = 0;

	wait = OBJECT(object)->goon_lift_part.wait;
	OBJECT(object)->goon_lift_part.wait = wait - 1u;
	if (wait != 1u)
	{
		goon_lift_part_idle();
		return;
	}
	OBJECT(object)->animation = 0x8Fu;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	goon_lift_part_idle();
}

/* The part after its change: nothing to do. */
void goon_lift_part_idle(void)
{
}
