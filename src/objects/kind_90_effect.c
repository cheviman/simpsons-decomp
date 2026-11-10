/**
 *    Name:        objects/kind_90_effect.c
 *    Description: an object that shows kind 90's animation 11 once
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* The object that shows kind 90's animation 11 once, by its state. */
void kind_90_effect(uint16_t object, uint8_t d, uint16_t *p_y, uint16_t *p_state_handlers)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t state_handlers = 0;

	state_handlers = kind_90_effect_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)d << 1))
	{
	case 0:
		kind_90_effect_start(object, &y, &state_handlers);
		break;
	case 2:
		kind_90_effect_wait(object);
		break;
	}
	*p_y = y;
	*p_state_handlers = state_handlers;
}

/* Sets it up (kind 90, animation 11) and shows it. */
void kind_90_effect_start(uint16_t object, uint16_t *p_box, uint16_t *p_setup)
{
	uint16_t box = 0, setup = 0;
	uint8_t state = 0;

	setup = kind_90_effect_setup_ADDRESS;
	box = start_object_from_setup(object, setup);
	OBJECT(object)->flags = 0x80u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	*p_box = box;
	*p_setup = setup;
}

/* Removes it once its animation has run to its end. */
void kind_90_effect_wait(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
		OBJECT(object)->flags = 0u;
}
