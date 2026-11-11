/**
 *    Name:        enemies/goon.c
 *    Description: the plain goon (enemy type 0, kind 80) of the fixed program
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* The plain goon's handler (enemy type 0): runs its state (starting, thinking, attacking, its hit
   reactions, climbing), then takes any hit and leaves when it walks off the screen. */
uint32_t enemy_goon_run(uint16_t object, uint8_t state)
{
	uint16_t ignored16 = 0;
	uint32_t ignored = 0, left_caller = 0;

	switch ((int8_t)(uint8_t)((uint32_t)state << 1))
	{
	case 0:
		enemy_goon_enter(object);
		break;
	case 4:
		enemy_think(object, &ignored16, &ignored);
		break;
	case 6:
		enemy_attack(object, &ignored16, &ignored);
		break;
	case 8:
		enemy_hit_reaction(object, &ignored16, &ignored);
		break;
	case 10:
		enemy_climb(object, &ignored16, &ignored);
		break;
	}
	enemy_check_hit(object, &ignored16, &left_caller);
	enemy_remove_off_screen(object, ignored16);
	return left_caller;
}

/* Sets the object up as a goon: its setup, facing left, with walk animations by direction, the nearest
   player as its target, the goon's behaviour, and a new target looked for every 16 frames. */
uint16_t enemy_goon_set_up(uint16_t object)
{
	uint16_t behaviour_address = 0, nearest_player = 0, setup = 0;
	uint8_t attributes = 0;

	setup = goon_setup_ADDRESS;
	start_object_from_setup(object, setup);
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = attributes | 0x40u;
	OBJECT(object)->enemy_class = 1;
	nearest_player = enemy_target_nearest_player(object);
	enemy_look_at_target(object, nearest_player);
	behaviour_address = 0xF144u;
	OBJECT(object)->behaviour = 0xF144u;
	OBJECT(object)->retarget_time = 0x10u;
	return behaviour_address;
}

/* A goon's first frame: sets it up (with 1 life when its spawn gave it a starting state) and starts it
   thinking. */
uint16_t enemy_goon_enter(uint16_t object)
{
	uint16_t behaviour_address = 0;
	uint8_t parameter = 0;

	behaviour_address = enemy_goon_set_up(object);
	parameter = OBJECT(object)->parameter;
	if (parameter != 0u)
		OBJECT(object)->vitality = 1u;
	OBJECT(object)->parameter = 0u;
	OBJECT(object)->state = 2u;
	return behaviour_address;
}

/* Turns the object into a plain goon: the goon's setup and behaviour, its old target's side given back,
   run from now on as enemy type 0, thinking. */
uint16_t enemy_become_goon(uint16_t object)
{
	uint16_t behaviour = 0, setup = 0, target = 0;
	uint8_t enemy_class = 0;
	uint16_t target_2 = 0;

	setup = goon_setup_ADDRESS;
	start_object_from_setup(object, setup);
	enemy_class = OBJECT(object)->enemy_class;
	if ((int8_t)enemy_class >= 0)
	{
		target_2 = OBJECT(object)->target;
		target = target_2;
		enemy_leave_side_if_holding(object, target);
	}
	OBJECT(object)->enemy_class = 1;
	behaviour = 0xF144u;
	OBJECT(object)->behaviour = 0xF144u;
	OBJECT(object)->retarget_time = 0x10u;
	OBJECT(object)->parameter = 0u;
	OBJECT(object)->timer = 0u;
	OBJECT(object)->type = 0;
	OBJECT(object)->state = 2u;
	return behaviour;
}
