/**
 *    Name:        objects/kind_90_effect.c
 *    Description: an object that shows kind 90's animation 11 once
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* The object that shows kind 90's animation 11 once, by its state. */
uint16_t kind_90_effect(uint16_t object, uint8_t state)
{
	uint16_t state_handlers = 0;

	state_handlers = kind_90_effect_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state << 1))
	{
	case 0:
		return kind_90_effect_start(object);
	case 2:
		kind_90_effect_wait(object);
		return state_handlers;
	}
	unreachable();
}

/* Sets it up (kind 90, animation 11) and shows it. */
uint16_t kind_90_effect_start(uint16_t object)
{
	uint16_t setup = 0;
	uint8_t state = 0;

	setup = kind_90_effect_setup_ADDRESS;
	start_object_from_setup(object, setup);
	OBJECT(object)->flags = 0x80u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return setup;
}

/* Removes it once its animation has run to its end. */
void kind_90_effect_wait(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
		OBJECT(object)->flags = 0u;
}
