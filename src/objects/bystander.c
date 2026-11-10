/**
 *    Name:        objects/bystander.c
 *    Description: stage 1's bystanders
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Sets a bystander up by its spawn's state: its kind, facing, place and animations, waiting. */
void bystander_start(uint16_t object, uint16_t *p_bystander_animation_set, uint16_t *p_bystander)
{
	uint8_t place = 0;
	uint16_t bystander = 0, bystander_animation_set = 0, setup = 0;
	uint8_t parameter = 0, state = 0;
	uint16_t kind = 0, t1 = 0, animations = 0;

	setup = bystander_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->flags = 0x80u;
	parameter = OBJECT(object)->parameter;
	bystander = bystanders_ADDRESS + (int8_t)(((uint32_t)parameter << 1) << 1);
	kind = (((uint32_t)BYSTANDER(bystander)->kind << 8u) | BYSTANDER(bystander)->place);
	place = (uint8_t)kind;
	OBJECT(object)->kind = kind >> 8;
	if ((int8_t)place < 0)
	{
		OBJECT(object)->attributes = 0x40u;
		place &= 0x7Fu;
	}
	t1 = (uint32_t)place << 4;
	OBJECT(object)->bystander.trigger_x = t1;
	animations = BYSTANDER(bystander)->animations;
	bystander_animation_set = animations;
	OBJECT(object)->bystander.animations = bystander_animation_set;
	OBJECT(object)->animation = BYSTANDER_ANIMATION_SET(bystander_animation_set)->waiting;
	OBJECT(object)->timer = 0x40u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	*p_bystander_animation_set = bystander_animation_set;
	*p_bystander = bystander;
}

/* Waits until the police car stops, then is startled. */
uint16_t bystander_wait_car(uint16_t object, uint16_t animations)
{
	uint8_t t1 = 0, startled = 0, state = 0;
	uint16_t animations_2 = 0;

	t1 = io_read8(0x1884u);
	if (t1 != 0u)
	{
		animations_2 = OBJECT(object)->bystander.animations;
		animations = animations_2;
		startled = BYSTANDER_ANIMATION_SET(animations)->startled;
		OBJECT(object)->animation = startled;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
	return animations;
}

/* When the startled animation ends, runs off to the left. */
uint16_t bystander_flee(uint16_t object, uint16_t states)
{
	uint16_t animations = 0;
	uint8_t animation_flags = 0, fleeing = 0, state = 0;
	uint16_t animations_2 = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
	{
		bystander_gone();
		return states;
	}
	OBJECT(object)->x_speed = -0x200;
	animations_2 = OBJECT(object)->bystander.animations;
	animations = animations_2;
	fleeing = BYSTANDER_ANIMATION_SET(animations)->fleeing;
	OBJECT(object)->animation = fleeing;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	face_movement(object);
	return animations;
}

/* Does nothing while it runs off. */
void bystander_gone(void)
{
}
