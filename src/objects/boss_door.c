/**
 *    Name:        objects/boss_door.c
 *    Description: the door stage 3's boss comes out of
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    10-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* The door stage 3's boss comes out of in the cemetery (list 1 type ED): runs its state (field 02: 0 set
   up, 1 closed, 2 open). */
uint16_t boss_door(uint16_t object)
{
	uint16_t states = 0;
	uint8_t state = 0;

	states = boss_door_states_ADDRESS;
	state = OBJECT(object)->state;
	switch ((int8_t)(uint8_t)((uint32_t)state << 1))
	{
	case 0:
		return boss_door_set_up(object);
	case 2:
	case 8:
		return boss_door_closed(object, states);
	case 4:
	case 10:
		return boss_door_open(object, states);
	case 6:
		return boss_door_stage_8_set_up(object);
	}
	unreachable();
}

/* The same door at the start of stage 8 (list 2 type 1F, scene 0B's spawn list): runs its state and goes
   once the camera's x reaches 0320. */
uint16_t boss_door_stage_8(uint16_t object)
{
	uint16_t states = 0;
	uint8_t state = 0;
	uint16_t camera_x_now = 0;

	states = boss_door_stage_8_states_ADDRESS;
	state = OBJECT(object)->state;
	switch ((int8_t)(uint8_t)((uint32_t)state << 1))
	{
	case 0:
		states = boss_door_stage_8_set_up(object);
		break;
	case -4:
	case 2:
		states = boss_door_closed(object, states);
		break;
	case -2:
	case 4:
		states = boss_door_open(object, states);
		break;
	case -6:
		states = boss_door_set_up(object);
		break;
	}
	camera_x_now = camera_x;
	if ((int16_t)camera_x_now >= 0x320)
		OBJECT(object)->flags = 0u;
	return states;
}

/* Keeps itself in 1852 and puts in its other half (list 1 type F4, which has no handler) in front of it,
   both kind 13, closed (animation 85). */
uint16_t boss_door_set_up(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t list = 0;
	uint16_t other_half = 0;
	uint8_t state = 0;
	uint16_t door_x = 0, other_half_x = 0, door_y = 0, other_half_y = 0;

	io_write16(0x1852u, object);
	list = 1u;
	vector_find_free_slot(list, &other_half, &carry);
	if (carry)
	{
		OBJECT(other_half)->type = -0xC;
		OBJECT(object)->boss_door.other_half = other_half;
		OBJECT(object)->flags = 0x80u;
		door_x = 0x2E0u - camera_x;
		OBJECT(object)->x = door_x;
		other_half_x = 0x2E8u - camera_x;
		OBJECT(other_half)->x = other_half_x;
		door_y = 0x108u + camera_y;
		OBJECT(object)->y = door_y;
		other_half_y = 0xC8u + camera_y;
		OBJECT(other_half)->y = other_half_y;
		OBJECT(object)->z = 0xFFE0u;
		OBJECT(other_half)->z = 0x20u;
		OBJECT(object)->kind = 0x13u;
		OBJECT(other_half)->kind = 0x13u;
		OBJECT(object)->animation = 0x85u;
		OBJECT(object)->attributes = 0x60u;
		OBJECT(other_half)->attributes = 0x60u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
	return other_half;
}

/* Closed (state 1): once its field 2A is set opens: animation 86 and its other half shown with animation
   87. */
uint16_t boss_door_closed(uint16_t object, uint16_t half)
{
	uint8_t open = 0, state = 0;
	uint16_t other_half = 0;

	open = OBJECT(object)->boss_door.open;
	if (open != 0u)
	{
		OBJECT(object)->animation = 0x86u;
		other_half = OBJECT(object)->boss_door.other_half;
		half = other_half;
		OBJECT(half)->flags = 0x80u;
		OBJECT(half)->animation = 0x87u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
	return half;
}

/* Open (state 2): once its field 2A is clear closes: animation 85 and its other half hidden. */
uint16_t boss_door_open(uint16_t object, uint16_t half)
{
	uint8_t open = 0, state = 0;
	uint16_t other_half = 0;

	open = OBJECT(object)->boss_door.open;
	if (open == 0u)
	{
		OBJECT(object)->animation = 0x85u;
		other_half = OBJECT(object)->boss_door.other_half;
		half = other_half;
		OBJECT(half)->flags = 4u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state - 1u;
	}
	return half;
}

/* Stage 8's door: keeps itself in 1852 and puts in its other half in list 2, both kind 13, closed. */
uint16_t boss_door_stage_8_set_up(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t list = 0;
	uint16_t other_half = 0;
	uint8_t state = 0;
	uint16_t door_x = 0, other_half_x = 0, door_y = 0, other_half_y = 0;

	io_write16(0x1852u, object);
	list = 2u;
	vector_find_free_slot(list, &other_half, &carry);
	if (carry)
	{
		OBJECT(object)->boss_door.other_half = other_half;
		OBJECT(object)->flags = 0x80u;
		door_x = 0x330u - camera_x;
		OBJECT(object)->x = door_x;
		other_half_x = 0x328u - camera_x;
		OBJECT(other_half)->x = other_half_x;
		door_y = 0xD0u + camera_y;
		OBJECT(object)->y = door_y;
		other_half_y = 0x90u + camera_y;
		OBJECT(other_half)->y = other_half_y;
		OBJECT(object)->z = 0xFFE0u;
		OBJECT(other_half)->z = 0x20u;
		OBJECT(object)->kind = 0x13u;
		OBJECT(other_half)->kind = 0x13u;
		OBJECT(object)->animation = 0x85u;
		OBJECT(object)->attributes = 0x20u;
		OBJECT(other_half)->attributes = 0x20u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
	return other_half;
}
