/**
 *    Name:        objects/fat_goon.c
 *    Description: the fat goons (kind 81): their setups, entrances and starts
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    10-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Sets a fat goon up: its sprite, hit box and life, facing the nearest player, the plain fat goon's
   behaviour. */
uint16_t fat_goon_setup(uint16_t object)
{
	uint16_t behaviour = 0, player = 0, setup = 0;
	uint8_t attributes = 0;

	setup = fat_goon_object_setup_ADDRESS;
	vector_object_setup(object, setup);
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = attributes | 0x40u;
	OBJECT(object)->enemy_class = 2;
	player = vector_choose_nearest_player(object);
	vector_measure_target(object, player);
	behaviour = 0x75E8u;
	OBJECT(object)->behaviour = 0x75E8u;
	OBJECT(object)->retarget_time = 0x10u;
	return behaviour;
}

/* Sets up the plain fat goon (with less life when its spawn's state is set) and lets it fight at once. */
void fat_goon_start(uint16_t object)
{
	uint8_t parameter = 0;

	fat_goon_setup(object);
	parameter = OBJECT(object)->parameter;
	if (parameter != 0u)
		OBJECT(object)->vitality = 8u;
	OBJECT(object)->parameter = 0u;
	OBJECT(object)->state = 2u;
}

/* Unused: turns the object into a fat goon: its setup and behaviour, its old target's side given back,
   thinking as enemy type 0E. */
void unused_become_fat_goon(uint16_t enemy)
{
	uint16_t setup = 0, target = 0;
	uint8_t old_class = 0;
	uint16_t old_target = 0;

	setup = fat_goon_object_setup_ADDRESS;
	vector_object_setup(enemy, setup);
	old_class = OBJECT(enemy)->enemy_class;
	if ((int8_t)old_class >= 0)
	{
		old_target = OBJECT(enemy)->target;
		target = old_target;
		vector_enemy_leave_side(enemy, target);
	}
	OBJECT(enemy)->enemy_class = 2;
	OBJECT(enemy)->behaviour = 0x75E8u;
	OBJECT(enemy)->retarget_time = 0x10u;
	OBJECT(enemy)->parameter = 0u;
	OBJECT(enemy)->timer = 0u;
	OBJECT(enemy)->type = 0xE;
	OBJECT(enemy)->state = 2u;
}

/* Sets a fat goon up with the grabbing behaviour. */
void fat_goon_grabber_setup(uint16_t object)
{
	fat_goon_base_setup(object);
	OBJECT(object)->behaviour = 0x765Au;
}

/* Sets up the grabbing fat goon and lets it fight at once. */
void fat_goon_grabber_start(uint16_t object)
{
	uint8_t parameter = 0;

	fat_goon_grabber_setup(object);
	fat_goon_weaken(object);
	parameter = OBJECT(object)->parameter;
	if (parameter != 0u)
		OBJECT(object)->vitality = 8u;
	OBJECT(object)->parameter = 0u;
	OBJECT(object)->state = 2u;
}

/* Sets a fat goon up with the striking behaviour. */
void fat_goon_puncher_setup(uint16_t object)
{
	fat_goon_base_setup(object);
	OBJECT(object)->behaviour = 0x76B2u;
}

/* Sets up the striking fat goon and lets it fight at once. */
void fat_goon_puncher_start(uint16_t object)
{
	fat_goon_puncher_setup(object);
	fat_goon_weaken(object);
	OBJECT(object)->parameter = 0u;
	OBJECT(object)->state = 2u;
}

/* Sets a fat goon up without a behaviour: its sprite, hit box and life, facing the nearest player. */
void fat_goon_base_setup(uint16_t object)
{
	uint16_t player = 0, setup = 0;
	uint8_t attributes = 0;

	setup = fat_goon_base_object_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->retarget_time = 0x10u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = attributes | 0x40u;
	OBJECT(object)->enemy_class = 2;
	player = vector_choose_nearest_player(object);
	vector_measure_target(object, player);
}

/* Gives the fat goon less life when its spawn's state is set. */
void fat_goon_weaken(uint16_t object)
{
	uint8_t parameter = 0;

	parameter = OBJECT(object)->parameter;
	if (parameter != 0u)
		OBJECT(object)->vitality = 8u;
}

/* Sets a fat goon up with the grabbing and body-slamming behaviour. */
void fat_goon_jumper_setup(uint16_t object)
{
	fat_goon_base_setup(object);
	OBJECT(object)->behaviour = 0x770Au;
}

/* Sets up the grabbing and body-slamming fat goon and lets it fight at once. */
void fat_goon_jumper_start(uint16_t object)
{
	fat_goon_jumper_setup(object);
	fat_goon_weaken(object);
	OBJECT(object)->parameter = 0u;
	OBJECT(object)->state = 2u;
}

/* Sets the kind 85 fighter up on a fat goon's setup: its own sprites and a behaviour of heavy strikes
   only. */
void kind_85_setup(uint16_t object)
{
	fat_goon_base_setup(object);
	fat_goon_weaken(object);
	OBJECT(object)->kind = 0x85u;
	OBJECT(object)->behaviour = 0x7762u;
}

/* Sets up the kind 85 fighter and lets it fight at once. */
void kind_85_start(uint16_t object)
{
	kind_85_setup(object);
	fat_goon_weaken(object);
	OBJECT(object)->parameter = 0u;
	OBJECT(object)->state = 2u;
}

/* Sets up the fat goon that stands still (animation B3) out of play. */
void fat_goon_waiting_start(uint16_t object)
{
	uint8_t state = 0;

	fat_goon_setup(object);
	OBJECT(object)->animation = 0xB3u;
	OBJECT(object)->entrance_pending = 1u;
	OBJECT(object)->parameter = 0u;
	OBJECT(object)->retarget_time = 0x10u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Keeps the standing fat goon out of play until it is hit or comes past x 0100, then lets it fight. */
void fat_goon_waiting(uint16_t object)
{
	uint8_t state = 0;
	uint16_t goon_x = 0;

	if ((OBJECT(object)->flags & 0x20u) == 0u)
	{
		goon_x = OBJECT(object)->x;
		if (goon_x < 0x100u)
		{
			OBJECT(object)->entrance_pending = 0u;
			state = OBJECT(object)->state;
			OBJECT(object)->state = state + 1u;
		}
		return;
	}
	OBJECT(object)->entrance_pending = 0u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Sets up the dropping fat goon, shown at once. */
void fat_goon_drop_start(uint16_t object)
{
	uint8_t state = 0;

	fat_goon_setup(object);
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->attributes = 0x20u;
	OBJECT(object)->animation = 0xB3u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Runs the dropping fat goon's route by its substep. */
void fat_goon_drop_route_update(uint16_t object)
{
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;
	uint8_t action_step = 0;

	for (;;)
	{
		action_step = OBJECT(object)->action_step;
		switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
		{
		case 0:
			fat_goon_drop_fall(object);
			return;
		case 2:
			fat_goon_drop_take_route(object);
			return;
		case 4:
			fat_goon_drop_walk_up_left(object);
			return;
		case 6:
		case 16:
			fat_goon_drop_walk_to_floor(object);
			return;
		case 8:
			fat_goon_drop_walk_right(object);
			return;
		case 10:
			fat_goon_drop_stop(object);
			return;
		case 12:
			fat_goon_drop_fall_again(object);
			return;
		case 14:
			break;
		case -82:
		case -64:
		case -52:
		case -40:
		case -20:
		case -8:
		case 30:
		case 50:
		case 98:
		case 114:
			vector_enemy_think(object, &ignored16, &ignored);
			return;
		case -80:
		case -62:
		case -50:
		case -38:
		case -18:
		case -6:
		case 32:
		case 52:
		case 100:
		case 116:
			vector_enemy_act(object, &ignored16, &ignored);
			return;
		case -78:
		case -60:
		case -48:
		case -36:
		case -16:
		case -4:
		case 34:
		case 54:
		case 102:
		case 118:
			vector_enemy_react(object, &ignored16, &ignored);
			return;
		case -76:
		case -58:
		case -46:
		case -34:
		case -14:
		case -2:
		case 36:
		case 56:
		case 104:
		case 120:
			vector_enemy_climb(object, &ignored16, &ignored);
			return;
		case -24:
			fat_goon_waiting_start(object);
			return;
		case -22:
			fat_goon_waiting(object);
			return;
		case -12:
			fat_goon_drop_start(object);
			return;
		case -10:
			continue;
		}
		break;
	}
	fat_goon_drop_walk_up(object);
}

/* Starts the fat goon falling for 96 frames. */
void fat_goon_drop_fall(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->z_speed = -0x100;
	OBJECT(object)->timer = 0x60u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* When the fall ends, takes its route by its spawn's state: the substep to go on with, the floor to walk
   to, the wait. */
void fat_goon_drop_take_route(uint16_t object)
{
	uint8_t floor = 0;
	uint16_t fat_goon_drop_route = 0;
	uint8_t timer = 0, parameter = 0, wait = 0;
	uint16_t next_step = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->z_speed = 0;
		parameter = OBJECT(object)->parameter;
		fat_goon_drop_route = fat_goon_drop_routes_ADDRESS + (int8_t)(((uint32_t)parameter << 1) << 1);
		next_step = (((uint32_t)FAT_GOON_DROP_ROUTE(fat_goon_drop_route)->next_step << 8u) | FAT_GOON_DROP_ROUTE(fat_goon_drop_route)->floor);
		floor = (uint8_t)next_step;
		OBJECT(object)->action_step = next_step >> 8;
		OBJECT(object)->fat_goon_drop.route_floor = floor;
		OBJECT(object)->floor_z = (OBJECT(object)->floor_z & 0xFF00u) | (floor & 0xFFu);
		wait = FAT_GOON_DROP_ROUTE(fat_goon_drop_route)->wait;
		OBJECT(object)->fat_goon_drop.route_wait = wait;
	}
}

/* Starts the fat goon walking up and to the left. */
void fat_goon_drop_walk_up_left(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->x_speed = -0x80;
	OBJECT(object)->y_speed = -0x80;
	OBJECT(object)->animation = 0x91u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Walks until the floor under it is the route's floor, then lets the fat goon fight. */
void fat_goon_drop_walk_to_floor(uint16_t object)
{
	uint32_t negative = 0;
	uint8_t cell = 0;
	uint16_t floor_cell = 0;
	uint8_t route_floor = 0, route_wait = 0;

	floor_cell = 0u;
	vector_floor_at_offset(object, &floor_cell, &negative);
	cell = (uint8_t)(floor_cell >> 8);
	route_floor = OBJECT(object)->fat_goon_drop.route_floor;
	if ((uint8_t)((((cell & 0xFu) << 1) << 1) << 1) != route_floor)
	{
		route_wait = OBJECT(object)->fat_goon_drop.route_wait;
		OBJECT(object)->fat_goon_drop.route_wait = route_wait - 1u;
		if (route_wait == 1u)
			OBJECT(object)->attributes = 0x10u;
		return;
	}
	OBJECT(object)->parameter = 0u;
	OBJECT(object)->flags = 0xC0u;
	OBJECT(object)->state = 2u;
	OBJECT(object)->timer = 0u;
}

/* Starts the fat goon walking right for 32 frames. */
void fat_goon_drop_walk_right(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->x_speed = 0x80;
	OBJECT(object)->timer = 0x20u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Stops the fat goon after its walk and waits 96 frames. */
void fat_goon_drop_stop(uint16_t object)
{
	uint8_t timer = 0, action_step = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->timer = 0x60u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* After the wait, starts the fat goon falling again. */
void fat_goon_drop_fall_again(uint16_t object)
{
	uint8_t timer = 0, action_step = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->z_speed = -0x100;
		OBJECT(object)->timer = 0x60u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* After the second fall, starts the fat goon walking up. */
void fat_goon_drop_walk_up(uint16_t object)
{
	uint8_t timer = 0, action_step = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->y_speed = -0x80;
		OBJECT(object)->z_speed = 0;
		OBJECT(object)->animation = 0x91u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* Runs the steps of the fat goon that walks up onto any floor, by its substep. */
void fat_goon_entrance_to_floor_steps(uint16_t object)
{
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;
	uint8_t action_step = 0;

	for (;;)
	{
		action_step = OBJECT(object)->action_step;
		switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
		{
		case 0:
			fat_goon_entrance_show(object);
			return;
		case 2:
		case 50:
			fat_goon_entrance_walk_out(object);
			return;
		case 4:
			fat_goon_reach_any_floor(object);
			return;
		case 6:
		case 54:
			fat_goon_entrance_end(object);
			return;
		case -12:
		case 8:
			fat_goon_entrance_start(object);
			return;
		case 10:
			break;
		case -120:
		case -102:
		case -90:
		case -78:
		case -58:
		case -46:
		case -8:
		case 12:
		case 60:
		case 76:
		case 102:
			vector_enemy_think(object, &ignored16, &ignored);
			return;
		case -118:
		case -100:
		case -88:
		case -76:
		case -56:
		case -44:
		case -6:
		case 14:
		case 62:
		case 78:
		case 104:
			vector_enemy_act(object, &ignored16, &ignored);
			return;
		case -116:
		case -98:
		case -86:
		case -74:
		case -54:
		case -42:
		case -4:
		case 16:
		case 64:
		case 80:
		case 106:
			vector_enemy_react(object, &ignored16, &ignored);
			return;
		case -114:
		case -96:
		case -84:
		case -72:
		case -52:
		case -40:
		case -2:
		case 18:
		case 66:
		case 82:
		case 108:
			vector_enemy_climb(object, &ignored16, &ignored);
			return;
		case -10:
			continue;
		}
		break;
	}
	fat_goon_entrance_steps(object);
}

/* Shows the fat goon with sprite priority 1 (field 09 bits 4-5). */
void fat_goon_entrance_show(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->attributes = 0x10u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Waits until there is floor under the fat goon, then takes that floor's height and priority. */
void fat_goon_reach_any_floor(uint16_t object)
{
	uint32_t negative = 0;
	uint8_t cell = 0;
	uint16_t floor_cell = 0;
	uint8_t attributes = 0, action_step = 0;

	floor_cell = 0u;
	vector_floor_at_offset(object, &floor_cell, &negative);
	cell = (uint8_t)(floor_cell >> 8);
	if ((int8_t)cell >= 0)
	{
		cell_seen = cell;
		OBJECT(object)->next_floor_cell = cell;
		priority_bits = cell & 0x30u;
		attributes = OBJECT(object)->attributes;
		OBJECT(object)->attributes = (attributes & 0xCFu) | priority_bits;
		OBJECT(object)->floor_z = (OBJECT(object)->floor_z & 0xFF00u) | ((((cell_seen & 0xFu) << 1) << 1) << 1 & 0xFFu);
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* Sets up the entering fat goon: its wait and attributes by its spawn's state. */
void fat_goon_entrance_start(uint16_t object)
{
	uint8_t parameter = 0, state = 0;
	uint16_t wait = 0;

	fat_goon_setup(object);
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->animation = 0x91u;
	parameter = OBJECT(object)->parameter;
	wait = (((uint32_t)GOON_ENTRANCE(fat_goon_entrances_ADDRESS + (int8_t)((uint32_t)parameter << 1))->wait << 8u) | GOON_ENTRANCE(fat_goon_entrances_ADDRESS + (int8_t)((uint32_t)parameter << 1))->attributes);
	OBJECT(object)->fat_goon_entrance.entrance_wait = wait >> 8;
	OBJECT(object)->attributes = wait;
	OBJECT(object)->timer = 8u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Runs the steps of the fat goon stepping out onto the ground, by its substep. */
void fat_goon_entrance_steps(uint16_t object)
{
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		fat_goon_entrance_appear(object);
		return;
	case 2:
		fat_goon_entrance_pose(object);
		return;
	case 4:
		fat_goon_entrance_pose_end(object);
		return;
	case -42:
	case 6:
		fat_goon_entrance_walk_out(object);
		return;
	case 8:
	case 112:
		fat_goon_reach_ground(object);
		return;
	case -38:
	case 10:
	case 114:
		fat_goon_entrance_end(object);
		return;
	case 12:
		fat_goon_walk_in_start(object);
		return;
	case 14:
		fat_goon_walk_in_steps(object);
		return;
	case -122:
	case -102:
	case -90:
	case -52:
	case -32:
	case 16:
	case 32:
	case 58:
	case 86:
	case 120:
		vector_enemy_think(object, &ignored16, &ignored);
		return;
	case -120:
	case -100:
	case -88:
	case -50:
	case -30:
	case 18:
	case 34:
	case 60:
	case 88:
	case 122:
		vector_enemy_act(object, &ignored16, &ignored);
		return;
	case -118:
	case -98:
	case -86:
	case -48:
	case -28:
	case 20:
	case 36:
	case 62:
	case 90:
	case 124:
		vector_enemy_react(object, &ignored16, &ignored);
		return;
	case -128:
	case -116:
	case -96:
	case -84:
	case -46:
	case -26:
	case 22:
	case 38:
	case 64:
	case 92:
	case 126:
		vector_enemy_climb(object, &ignored16, &ignored);
		return;
	case 24:
		fat_goon_walk_in_go(object);
		return;
	case 26:
		fat_goon_walk_in_end(object, 0u);
		return;
	case 28:
		fat_goon_from_back_start(object);
		return;
	case 30:
		fat_goon_from_back_steps(object);
		return;
	case 40:
		fat_goon_from_back_place(object);
		return;
	case 42:
		fat_goon_from_back_walk(object, 0u);
		return;
	case 44:
		fat_goon_from_back_wait(object, 0u);
		return;
	}
}

/* Shows the fat goon; without a pose in its spawn's state it goes straight to walking out. */
void fat_goon_entrance_appear(uint16_t object)
{
	uint8_t parameter = 0, action_step = 0;

	OBJECT(object)->flags = 0x80u;
	parameter = OBJECT(object)->parameter;
	if ((int8_t)parameter >= 0)
	{
		OBJECT(object)->action_step = 3u;
		return;
	}
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* After its wait, starts the fat goon's pose (animation B1). */
void fat_goon_entrance_pose(uint16_t object)
{
	uint8_t entrance_wait = 0, action_step = 0;

	entrance_wait = OBJECT(object)->fat_goon_entrance.entrance_wait;
	OBJECT(object)->fat_goon_entrance.entrance_wait = entrance_wait - 1u;
	if (entrance_wait == 1u)
	{
		OBJECT(object)->animation = 0xB1u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* When the pose ends, starts the walking animation. */
void fat_goon_entrance_pose_end(uint16_t object)
{
	uint8_t animation_flags = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		OBJECT(object)->fat_goon_entrance.entrance_wait = 1u;
		OBJECT(object)->animation = 0x91u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* After its wait, starts the fat goon walking up the screen. */
void fat_goon_entrance_walk_out(uint16_t object)
{
	uint8_t entrance_wait = 0, action_step = 0;

	entrance_wait = OBJECT(object)->fat_goon_entrance.entrance_wait;
	OBJECT(object)->fat_goon_entrance.entrance_wait = entrance_wait - 1u;
	if (entrance_wait == 1u)
	{
		OBJECT(object)->y_speed = -0x100;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* Sets up the fat goon that walks in for as many frames as its spawn's state says. */
uint16_t fat_goon_walk_in_start(uint16_t object)
{
	uint16_t behaviour = 0;
	uint8_t parameter = 0, state = 0;

	behaviour = fat_goon_setup(object);
	parameter = OBJECT(object)->parameter;
	OBJECT(object)->timer = parameter;
	OBJECT(object)->parameter = 0u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return behaviour;
}

/* Runs the steps of the walking-in fat goon by its substep, keeping its priority by the floor. */
uint16_t fat_goon_walk_in_steps(uint16_t object)
{
	uint32_t negative = 0;
	uint8_t cell = 0;
	uint16_t floor_cell = 0, steps = 0;
	uint32_t ignored = 0;
	uint8_t action_step = 0, attributes = 0;

	steps = fat_goon_walk_in_step_handlers_ADDRESS;
	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		fat_goon_walk_in_go(object);
		break;
	case 2:
		steps = fat_goon_walk_in_end(object, steps);
		break;
	case 4:
		steps = fat_goon_from_back_start(object);
		break;
	case 6:
		steps = fat_goon_from_back_steps(object);
		break;
	case -126:
	case -114:
	case -76:
	case -56:
	case -8:
	case 8:
	case 34:
	case 62:
	case 96:
		vector_enemy_think(object, &steps, &ignored);
		break;
	case -124:
	case -112:
	case -74:
	case -54:
	case -6:
	case 10:
	case 36:
	case 64:
	case 98:
		vector_enemy_act(object, &steps, &ignored);
		break;
	case -122:
	case -110:
	case -72:
	case -52:
	case -4:
	case 12:
	case 38:
	case 66:
	case 100:
		vector_enemy_react(object, &steps, &ignored);
		break;
	case -120:
	case -108:
	case -70:
	case -50:
	case -2:
	case 14:
	case 40:
	case 68:
	case 102:
		vector_enemy_climb(object, &steps, &ignored);
		break;
	case 16:
		steps = fat_goon_from_back_place(object);
		break;
	case 18:
		steps = fat_goon_from_back_walk(object, steps);
		break;
	case 20:
		steps = fat_goon_from_back_wait(object, steps);
		break;
	case -16:
	case 88:
		fat_goon_reach_ground(object);
		break;
	case -62:
	case -14:
	case 90:
		fat_goon_entrance_end(object);
		break;
	case -66:
	case -18:
		fat_goon_entrance_walk_out(object);
		break;
	case -24:
		fat_goon_entrance_appear(object);
		break;
	case -22:
		fat_goon_entrance_pose(object);
		break;
	case -20:
		fat_goon_entrance_pose_end(object);
		break;
	case -12:
		steps = fat_goon_walk_in_start(object);
		break;
	case -10:
		steps = fat_goon_walk_in_steps(object);
		break;
	}
	floor_cell = 0u;
	vector_floor_at_offset(object, &floor_cell, &negative);
	cell = (uint8_t)(floor_cell >> 8);
	if ((int8_t)cell >= 0)
	{
		cell_seen = cell;
		priority_bits = cell & 0x30u;
		attributes = OBJECT(object)->attributes;
		OBJECT(object)->attributes = (attributes & 0xCFu) | priority_bits;
		OBJECT(object)->floor_z = (OBJECT(object)->floor_z & 0xFF00u) | ((((cell_seen & 0xFu) << 1) << 1) << 1 & 0xFFu);
	}
	return steps;
}

/* Starts the fat goon walking towards its target. */
void fat_goon_walk_in_go(uint16_t object)
{
	uint8_t target_direction = 0, action_step = 0;
	uint16_t x_speed = 0;

	OBJECT(object)->animation = 0x90u;
	OBJECT(object)->x_speed = 0x200;
	target_direction = OBJECT(object)->target_direction;
	if ((int8_t)(target_direction - 0x40u) >= 0)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	vector_face_direction(object);
}

/* When the walk's frames run out, faces the nearest player and lets the fat goon fight. */
uint16_t fat_goon_walk_in_end(uint16_t object, uint16_t u)
{
	uint16_t heading = 0, player = 0;
	uint8_t timer = 0, target_direction = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return u;
	player = vector_choose_nearest_player(object);
	vector_measure_target(object, player);
	target_direction = OBJECT(object)->target_direction;
	heading = (uint32_t)target_direction << 8;
	player = vector_set_walk_speed_by_direction(object, player, heading);
	vector_face_direction(object);
	OBJECT(object)->state = 2u;
	OBJECT(object)->timer = 0u;
	return player;
}

/* Sets up the fat goon coming from the back of the stage, facing the nearest player. */
uint16_t fat_goon_from_back_start(uint16_t object)
{
	uint16_t player = 0;
	uint8_t state = 0, attributes = 0;

	fat_goon_setup(object);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	OBJECT(object)->animation = 0x83u;
	OBJECT(object)->flags = 0x80u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0x10u;
	player = vector_choose_nearest_player(object);
	vector_measure_target(object, player);
	vector_face_direction(object);
	return player;
}

/* Runs the steps of the fat goon coming from the back, by its substep. */
uint16_t fat_goon_from_back_steps(uint16_t object)
{
	uint16_t steps = 0, u = 0;
	uint32_t ignored = 0;
	uint8_t action_step = 0;

	for (;;)
	{
		steps = fat_goon_from_back_step_handlers_ADDRESS;
		action_step = OBJECT(object)->action_step;
		switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
		{
		case 0:
			return fat_goon_from_back_place(object);
		case 2:
			return fat_goon_from_back_walk(object, steps);
		case 4:
			break;
		case -92:
		case -72:
		case -24:
		case -8:
		case 18:
		case 46:
		case 80:
			vector_enemy_think(object, &u, &ignored);
			return u;
		case -128:
		case -90:
		case -70:
		case -22:
		case -6:
		case 20:
		case 48:
		case 82:
			vector_enemy_act(object, &u, &ignored);
			return u;
		case -126:
		case -88:
		case -68:
		case -20:
		case -4:
		case 22:
		case 50:
		case 84:
			vector_enemy_react(object, &u, &ignored);
			return u;
		case -124:
		case -86:
		case -66:
		case -18:
		case -2:
		case 24:
		case 52:
		case 86:
			vector_enemy_climb(object, &u, &ignored);
			return u;
		case -32:
		case 72:
			fat_goon_reach_ground(object);
			return steps;
		case -78:
		case -30:
		case 74:
			fat_goon_entrance_end(object);
			return steps;
		case -82:
		case -34:
			fat_goon_entrance_walk_out(object);
			return steps;
		case -40:
			fat_goon_entrance_appear(object);
			return steps;
		case -38:
			fat_goon_entrance_pose(object);
			return steps;
		case -36:
			fat_goon_entrance_pose_end(object);
			return steps;
		case -28:
			return fat_goon_walk_in_start(object);
		case -26:
			return fat_goon_walk_in_steps(object);
		case -16:
			fat_goon_walk_in_go(object);
			return steps;
		case -14:
			return fat_goon_walk_in_end(object, steps);
		case -12:
			return fat_goon_from_back_start(object);
		case -10:
			continue;
		}
		break;
	}
	return fat_goon_from_back_wait(object, steps);
}

/* Puts the fat goon at the back of the stage, at the x its spawn's state picks, walking down. */
uint16_t fat_goon_from_back_place(uint16_t object)
{
	uint16_t xs = 0;
	uint8_t parameter = 0, action_step = 0;
	uint16_t first_x = 0;

	OBJECT(object)->flags = 0x80u;
	xs = fat_goon_from_back_xs_ADDRESS;
	parameter = OBJECT(object)->parameter;
	first_x = fat_goon_from_back_xs[(int8_t)((uint8_t)((uint32_t)parameter << 1)) / 2];
	OBJECT(object)->x = first_x;
	OBJECT(object)->y = 0x40u;
	OBJECT(object)->y_speed = 0x100;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	return xs;
}

/* Walks down until there is floor under it, facing its target every 8 frames. */
uint16_t fat_goon_from_back_walk(uint16_t object, uint16_t u)
{
	uint32_t negative = 0;
	uint8_t cell = 0;
	uint16_t floor_cell = 0, target = 0;
	uint8_t action_step = 0;
	uint16_t target_2 = 0;

	floor_cell = 0u;
	vector_floor_at_offset(object, &floor_cell, &negative);
	cell = (uint8_t)(floor_cell >> 8);
	if ((int8_t)cell >= 0)
	{
		OBJECT(object)->next_floor_cell = cell;
		OBJECT(object)->floor_z = (OBJECT(object)->floor_z & 0xFF00u) | ((((cell & 0xFu) << 1) << 1) << 1 & 0xFFu);
		OBJECT(object)->parameter = 0u;
		OBJECT(object)->flags = 0xC0u;
		OBJECT(object)->timer = 0x20u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
	if ((frame_count & 7u) != 0u)
		return u;
	target_2 = OBJECT(object)->target;
	target = target_2;
	vector_measure_target(object, target);
	vector_face_direction(object);
	return target;
}

/* Waits 32 frames on the floor facing its target, then lets the fat goon fight. */
uint16_t fat_goon_from_back_wait(uint16_t object, uint16_t u)
{
	uint16_t target = 0;
	uint8_t timer = 0, state = 0;
	uint16_t target_2 = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
	{
		if ((frame_count & 7u) != 0u)
			return u;
		target_2 = OBJECT(object)->target;
		target = target_2;
		vector_measure_target(object, target);
		vector_face_direction(object);
		return target;
	}
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return u;
}

/* Sets up the fat goon that carries an obstacle, walking for as many steps as its spawn's state says. */
uint16_t fat_goon_thrower_start(uint16_t object)
{
	uint32_t negative = 0;
	uint8_t cell = 0;
	uint16_t behaviour = 0, floor_cell = 0;
	uint8_t parameter = 0, state = 0;

	parameter = OBJECT(object)->parameter;
	OBJECT(object)->fat_goon_thrower.carry_time = parameter;
	behaviour = fat_goon_setup(object);
	OBJECT(object)->animation = 0xA6u;
	floor_cell = 0u;
	vector_floor_at_offset(object, &floor_cell, &negative);
	cell = (uint8_t)(floor_cell >> 8);
	OBJECT(object)->fat_goon_thrower.start_cell = cell;
	OBJECT(object)->parameter = 0u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return behaviour;
}

/* Runs the thrower's steps by its substep, stopping where the floor ahead changes. */
uint16_t fat_goon_thrower_steps(uint16_t object)
{
	uint32_t negative = 0;
	uint8_t cell = 0;
	uint16_t floor_cell = 0, steps = 0;
	uint32_t ignored = 0;
	uint8_t action_step = 0, start_cell = 0;

	steps = fat_goon_thrower_step_handlers_ADDRESS;
	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		steps = fat_goon_thrower_pick_up(object);
		break;
	case 2:
		steps = fat_goon_thrower_carry(object);
		break;
	case 4:
		steps = fat_goon_thrower_throw(object, steps);
		break;
	case 6:
		fat_goon_thrower_end(object);
		break;
	case -118:
	case -98:
	case -50:
	case -34:
	case -8:
	case 20:
	case 54:
		vector_enemy_think(object, &steps, &ignored);
		break;
	case -116:
	case -96:
	case -48:
	case -32:
	case -6:
	case 22:
	case 56:
		vector_enemy_act(object, &steps, &ignored);
		break;
	case -114:
	case -94:
	case -46:
	case -30:
	case -4:
	case 24:
	case 58:
		vector_enemy_react(object, &steps, &ignored);
		break;
	case -112:
	case -92:
	case -44:
	case -28:
	case -2:
	case 26:
	case 60:
		vector_enemy_climb(object, &steps, &ignored);
		break;
	case -12:
		steps = fat_goon_thrower_start(object);
		break;
	case -10:
		steps = fat_goon_thrower_steps(object);
		break;
	}
	vector_floor_ahead(object, &floor_cell, &negative);
	cell = (uint8_t)(floor_cell >> 8);
	start_cell = OBJECT(object)->fat_goon_thrower.start_cell;
	if (cell != start_cell)
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0;
	}
	return steps;
}

/* Puts in the obstacle the fat goon carries on its head and starts it walking; without a free slot it
   fights at once. */
uint16_t fat_goon_thrower_pick_up(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t x_speed_high = 0, x_speed_low = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, object_2 = 0;
	uint8_t target_direction = 0, carry_time = 0, action_step = 0;

	OBJECT(object)->timer = 0x40u;
	target_direction = OBJECT(object)->target_direction;
	if ((int8_t)(target_direction - 0x40u) < 0)
	{
		x_speed_low = 0u;
		x_speed_high = 2u;
	}
	else
	{
		x_speed_low = 0u;
		x_speed_high = 0xFFu;
	}
	OBJECT(object)->x_speed = (uint32_t)x_speed_high << 8;
	leftover_y = fat_goon_thrower_pick_up_child_ADDRESS;
	vector_spawn_child(object, &ignored16, &object_2, &ignored16_2, &carry);
	if (carry == 0u)
	{
		OBJECT(object)->state = 2u;
		OBJECT(object)->timer = 0u;
		return object_2;
	}
	OBJECT(object)->fat_goon_thrower.carried_object = object_2;
	carry_time = OBJECT(object)->fat_goon_thrower.carry_time;
	OBJECT(object_2)->parameter = carry_time;
	OBJECT(object_2)->unk_3D = 1u;
	OBJECT(object)->fat_goon_thrower.carry_time = 8u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	return object_2;
}

/* Walks with the obstacle on its head, and starts the throw when its steps run out or the target is
   near. */
uint16_t fat_goon_thrower_carry(uint16_t object)
{
	uint16_t carried = 0;
	uint8_t state = 0, timer = 0, carry_time = 0, action_step = 0, target_direction = 0, animation_flags = 0;
	uint16_t carried_object = 0, y_speed = 0, carried_object_2 = 0, thrower_x = 0, thrower_y = 0, z = 0, carried_z = 0, target_dy = 0, target_dx = 0, thrower_x_now = 0, screen_offset = 0;

	carried_object = OBJECT(object)->fat_goon_thrower.carried_object;
	carried = carried_object;
	OBJECT(carried)->carried_obstacle.carried = 1u;
	state = OBJECT(carried)->state;
	if ((int8_t)state < 0)
	{
		OBJECT(object)->state = 4u;
		OBJECT(object)->action = 0u;
		OBJECT(object)->action_step = 0u;
		return carried;
	}
	carried = vector_choose_nearest_player(object);
	vector_measure_target(object, carried);
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->timer = 0x10u;
		carry_time = OBJECT(object)->fat_goon_thrower.carry_time;
		OBJECT(object)->fat_goon_thrower.carry_time = carry_time - 1u;
		if (carry_time == 1u)
		{
			OBJECT(object)->animation = 0xA7u;
			OBJECT(object)->timer = 0x10u;
			OBJECT(object)->x_speed = 0;
			OBJECT(object)->y_speed = 0;
			action_step = OBJECT(object)->action_step;
			OBJECT(object)->action_step = action_step + 1u;
			vector_face_direction(object);
			return carried;
		}
		OBJECT(object)->x_speed = 4;
		OBJECT(object)->y_speed = 0x40;
		target_direction = OBJECT(object)->target_direction;
		if ((int8_t)target_direction < 0)
		{
			y_speed = OBJECT(object)->y_speed;
			OBJECT(object)->y_speed = 0u - y_speed;
		}
	}
	carried_object_2 = OBJECT(object)->fat_goon_thrower.carried_object;
	carried = carried_object_2;
	animation_flags = OBJECT(carried)->animation_flags;
	OBJECT(carried)->animation_flags = animation_flags | 0x80u;
	thrower_x = OBJECT(object)->x;
	OBJECT(carried)->x = thrower_x;
	thrower_y = OBJECT(object)->y;
	OBJECT(carried)->y = thrower_y;
	z = OBJECT(object)->z;
	carried_z = z + 0x44u;
	OBJECT(carried)->z = carried_z;
	target_dy = OBJECT(object)->target_dy;
	if (target_dy >= 0x10u)
	{
		vector_face_direction(object);
		return carried;
	}
	target_dx = OBJECT(object)->target_dx;
	if (target_dx >= 0x60u)
	{
		vector_face_direction(object);
		return carried;
	}
	thrower_x_now = OBJECT(object)->x;
	screen_offset = thrower_x_now - 0x60u;
	if (screen_offset >= 0x100u)
	{
		vector_face_direction(object);
		return carried;
	}
	OBJECT(object)->animation = 0xA7u;
	OBJECT(object)->timer = 0x10u;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	vector_face_direction(object);
	return carried;
}

/* At the throw's frame, sends the carried obstacle flying the way the fat goon faces. */
uint16_t fat_goon_thrower_throw(uint16_t object, uint16_t carried)
{
	uint8_t animation_flags = 0, attributes = 0, action_step = 0;
	uint16_t carried_object = 0, x_speed = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) == 0u)
		return carried;
	carried_object = OBJECT(object)->fat_goon_thrower.carried_object;
	carried = carried_object;
	OBJECT(carried)->state = 2u;
	OBJECT(carried)->x_speed = 0x380;
	OBJECT(carried)->z_speed = 0x100;
	attributes = OBJECT(object)->attributes;
	if ((attributes & 0x40u) != 0u)
	{
		x_speed = OBJECT(carried)->x_speed;
		OBJECT(carried)->x_speed = 0u - x_speed;
	}
	OBJECT(object)->timer = 0x20u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	return carried;
}

/* After the throw, waits 32 frames and lets the fat goon fight. */
void fat_goon_thrower_end(uint16_t object)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->state = 2u;
	OBJECT(object)->timer = 0u;
}

/* Waits until the fat goon is over the ground floor, then takes its priority and height. */
void fat_goon_reach_ground(uint16_t object)
{
	uint32_t negative = 0;
	uint8_t cell = 0;
	uint16_t floor_cell = 0;
	uint8_t attributes = 0, action_step = 0;

	floor_cell = 0u;
	vector_floor_at_offset(object, &floor_cell, &negative);
	cell = (uint8_t)(floor_cell >> 8);
	if ((int8_t)cell >= 0 && (cell & 0xFu) == 0u)
	{
		cell_seen = cell;
		OBJECT(object)->next_floor_cell = cell;
		priority_bits = cell & 0x30u;
		attributes = OBJECT(object)->attributes;
		OBJECT(object)->attributes = (attributes & 0xCFu) | priority_bits;
		OBJECT(object)->floor_z = (OBJECT(object)->floor_z & 0xFF00u) | ((((cell_seen & 0xFu) << 1) << 1) << 1 & 0xFFu);
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* After its last wait, stops the fat goon and lets it fight. */
void fat_goon_entrance_end(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->parameter = 0u;
		OBJECT(object)->flags = 0xC0u;
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Sets up the hidden fat goon: its wait, its floor wait and the direction and speed it comes in by. */
void fat_goon_delayed_start(uint16_t object)
{
	uint16_t delayed_start = 0;
	uint8_t state = 0, attributes = 0, parameter = 0;
	uint16_t wait = 0, direction = 0;

	fat_goon_puncher_setup(object);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	OBJECT(object)->animation = 0x82u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0x20u;
	OBJECT(object)->flags = 8u;
	parameter = OBJECT(object)->parameter;
	delayed_start = delayed_fat_goon_starts_ADDRESS + (int8_t)(((uint32_t)parameter << 1) << 1);
	wait = (((uint32_t)DELAYED_START(delayed_start)->wait << 8u) | DELAYED_START(delayed_start)->floor_wait);
	OBJECT(object)->fat_goon_delayed.appear_wait = wait >> 8;
	OBJECT(object)->timer = wait;
	direction = (((uint32_t)DELAYED_START(delayed_start)->direction << 8u) | DELAYED_START(delayed_start)->speed);
	OBJECT(object)->fat_goon_delayed.direction = (uint8_t)(direction >> 8u);
	OBJECT(object)->fat_goon_delayed.speed = (uint8_t)direction;
	OBJECT(object)->parameter = 0u;
}

/* Runs the delayed fat goon's steps by its substep. */
void fat_goon_delayed_steps(uint16_t object)
{
	uint32_t zero = 0, negative = 0;
	uint16_t ignored16 = 0, steps = 0;
	uint32_t ignored = 0;
	uint8_t action_step = 0, step_offset = 0;

	steps = fat_goon_delayed_step_handlers_ADDRESS;
	action_step = OBJECT(object)->action_step;
	step_offset = (uint32_t)action_step << 1;
	negative = step_offset >> 7;
	zero = step_offset == 0u;
	switch ((int8_t)step_offset)
	{
	case 0:
		fat_goon_delayed_appear(object);
		return;
	case -102:
	case 2:
		fat_goon_reach_ground(object);
		return;
	case -100:
	case 4:
		fat_goon_entrance_end(object);
		return;
	case 6:
		fat_goon_descent_start(object);
		return;
	case 8:
		fat_goon_descent_steps(object);
		return;
	case -94:
	case -78:
	case -52:
	case -24:
	case 10:
		vector_enemy_think(object, &ignored16, &ignored);
		return;
	case -92:
	case -76:
	case -50:
	case -22:
	case 12:
		vector_enemy_act(object, &ignored16, &ignored);
		return;
	case -90:
	case -74:
	case -48:
	case -20:
	case 14:
		vector_enemy_react(object, &ignored16, &ignored);
		return;
	case -88:
	case -72:
	case -46:
	case -18:
	case 16:
		vector_enemy_climb(object, &ignored16, &ignored);
		return;
	case 18:
		fat_goon_descent_fall(object, steps);
		return;
	case 20:
		fat_goon_descent_land(object, steps);
		return;
	case -14:
	case -10:
	case -6:
	case -2:
		enemy_set_knock_direction(object, steps, zero, negative);
		return;
	}
}

/* When its wait runs out, shows the fat goon and starts it moving by its direction and speed. */
void fat_goon_delayed_appear(uint16_t object)
{
	uint16_t heading = 0;
	uint8_t appear_wait = 0, action_step = 0;
	uint16_t direction_and_speed = 0;

	appear_wait = OBJECT(object)->fat_goon_delayed.appear_wait;
	OBJECT(object)->fat_goon_delayed.appear_wait = appear_wait - 1u;
	if (appear_wait != 1u)
		return;
	OBJECT(object)->flags = 0x80u;
	direction_and_speed = (((uint32_t)OBJECT(object)->fat_goon_delayed.direction << 8u) | OBJECT(object)->fat_goon_delayed.speed);
	heading = direction_and_speed;
	vector_set_speed_by_direction(object, heading);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Sets up the fat goon coming down from far away, small and high, with the balloon it will let go of. */
uint16_t fat_goon_descent_start(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t carried_object = 0, descent_start = 0, ignored16 = 0, ignored16_3 = 0;
	uint8_t parameter = 0, state = 0;
	uint16_t first_x = 0, x_speed = 0;

	fat_goon_setup(object);
	leftover_y = fat_goon_descent_child_ADDRESS;
	vector_spawn_child(object, &ignored16, &carried_object, &ignored16_3, &carry);
	if (carry == 0u)
	{
		OBJECT(object)->timer = 0u;
		OBJECT(object)->parameter = 0u;
		OBJECT(object)->state = 2u;
		return carried_object;
	}
	OBJECT(object)->fat_goon.carried_object = carried_object;
	OBJECT(object)->animation = 0xAFu;
	OBJECT(object)->timer = 0x68u;
	parameter = OBJECT(object)->parameter;
	descent_start = fat_goon_descent_starts_ADDRESS + (int8_t)(((uint32_t)parameter << 1) << 1);
	first_x = DESCENT_START(descent_start)->x;
	OBJECT(object)->x = first_x;
	OBJECT(object)->y = 0x60u;
	OBJECT(object)->z = 0xE0u;
	x_speed = DESCENT_START(descent_start)->x_speed;
	OBJECT(object)->x_speed = x_speed;
	OBJECT(object)->y_speed = 0x100;
	OBJECT(object)->z_speed = -0x200;
	OBJECT(object)->floor_z = 0u;
	OBJECT(object)->zoom_x = 0x10u;
	OBJECT(object)->zoom_y = 0x10u;
	OBJECT(object)->parameter = 0u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return descent_start;
}

/* Runs the descending fat goon's steps by its substep, facing its target. */
uint16_t fat_goon_descent_steps(uint16_t object)
{
	uint32_t zero = 0, negative = 0;
	uint16_t steps = 0;
	uint32_t ignored = 0;
	uint8_t action_step = 0, step_offset = 0;

	steps = fat_goon_descent_step_handlers_ADDRESS;
	action_step = OBJECT(object)->action_step;
	step_offset = (uint32_t)action_step << 1;
	negative = step_offset >> 7;
	zero = step_offset == 0u;
	switch ((int8_t)step_offset)
	{
	case 0:
		steps = fat_goon_descent_fall(object, steps);
		break;
	case 2:
		steps = fat_goon_descent_land(object, steps);
		break;
	case -120:
	case -16:
		fat_goon_reach_ground(object);
		break;
	case -118:
	case -14:
		fat_goon_entrance_end(object);
		break;
	case -112:
	case -96:
	case -70:
	case -42:
	case -8:
		vector_enemy_think(object, &steps, &ignored);
		break;
	case -110:
	case -94:
	case -68:
	case -40:
	case -6:
		vector_enemy_act(object, &steps, &ignored);
		break;
	case -108:
	case -92:
	case -66:
	case -38:
	case -4:
		vector_enemy_react(object, &steps, &ignored);
		break;
	case -106:
	case -90:
	case -64:
	case -36:
	case -2:
		vector_enemy_climb(object, &steps, &ignored);
		break;
	case -32:
	case -28:
	case -24:
	case -20:
		enemy_set_knock_direction(object, steps, zero, negative);
		break;
	case -18:
		fat_goon_delayed_appear(object);
		break;
	case -12:
		steps = fat_goon_descent_start(object);
		break;
	case -10:
		steps = fat_goon_descent_steps(object);
		break;
	}
	vector_face_direction(object);
	return steps;
}

/* Grows the fat goon as it comes nearer, and after its time lets the balloon go. */
uint16_t fat_goon_descent_fall(uint16_t object, uint16_t balloon)
{
	uint32_t negative = 0, carry = 0;
	uint8_t cell = 0, new_zoom_x = 0, new_zoom_y = 0;
	uint16_t floor_cell = 0;
	uint8_t timer = 0, action_step = 0;
	uint16_t zoom_x = 0, bigger_zoom = 0, carried_object = 0;
	uint32_t zoom_x_halfword = 0;

	floor_cell = 0u;
	vector_floor_at_offset(object, &floor_cell, &negative);
	cell = (uint8_t)(floor_cell >> 8);
	if ((int8_t)cell >= 0)
		OBJECT(object)->floor_z = (OBJECT(object)->floor_z & 0xFF00u) | ((((cell & 0xFu) << 1) << 1) << 1 & 0xFFu);
	zoom_x = (((uint32_t)OBJECT(object)->zoom_x << 8u) | OBJECT(object)->zoom_y);
	bigger_zoom = zoom_x + 0x101u;
	new_zoom_y = (uint8_t)bigger_zoom;
	new_zoom_x = (uint8_t)(bigger_zoom >> 8);
	if ((uint16_t)(((uint32_t)new_zoom_x << 8) | (new_zoom_y & 0xFFu)) <= 0x4040u)
	{
		zoom_x_halfword = ((uint32_t)new_zoom_x << 8) | (new_zoom_y & 0xFFu);
		OBJECT(object)->zoom_x = (uint8_t)(zoom_x_halfword >> 8u);
		OBJECT(object)->zoom_y = (uint8_t)zoom_x_halfword;
		OBJECT(object)->flags = 0x98u;
	}
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->y_speed = 0;
		carried_object = OBJECT(object)->fat_goon.carried_object;
		balloon = carried_object;
		OBJECT(balloon)->state = 2u;
		OBJECT(object)->flags = 0xC8u;
		OBJECT(object)->animation = 0xA8u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
	carry = vector_check_landing(object);
	return balloon;
}

/* Falls to the floor, then faces the nearest player and lets the fat goon fight. */
uint16_t fat_goon_descent_land(uint16_t object, uint16_t u)
{
	uint32_t carry = 0;
	uint16_t d = 0, heading = 0, player = 0;
	uint8_t target_direction = 0;

	vector_apply_gravity(object, &d, &carry);
	if (carry == 0u)
		return u;
	player = vector_choose_nearest_player(object);
	vector_measure_target(object, player);
	target_direction = OBJECT(object)->target_direction;
	heading = (d & 0xFFu) | ((uint32_t)target_direction << 8);
	player = vector_set_walk_speed_by_direction(object, player, heading);
	vector_face_direction(object);
	OBJECT(object)->state = 2u;
	OBJECT(object)->timer = 0u;
	return player;
}

/* Sets up the fat goon coming in from a side of the cemetery, walking in. */
void fat_goon_jump_in_start(uint16_t object)
{
	uint8_t parameter = 0, parameter_2 = 0, state = 0;
	uint16_t first_x = 0, goon_x = 0, x_speed = 0, scroll_z_speed = 0;

	parameter = OBJECT(object)->parameter;
	first_x = fat_goon_jump_in_xs[(int8_t)((uint8_t)((uint32_t)parameter << 1)) / 2];
	OBJECT(object)->x = first_x;
	parameter_2 = OBJECT(object)->parameter;
	if ((int8_t)parameter_2 < 0)
		OBJECT(object)->vitality = 1u;
	OBJECT(object)->parameter = 0u;
	fat_goon_puncher_setup(object);
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->attributes = 0x20u;
	OBJECT(object)->animation = 0x90u;
	OBJECT(object)->x_speed = 0x200;
	goon_x = OBJECT(object)->x;
	if (goon_x >= 0xE0u)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	face_movement(object);
	scroll_z_speed = cemetery_scroll_speed;
	OBJECT(object)->z_speed = scroll_z_speed;
}

/* Runs the steps of the fat goon jumping in, by its substep. */
void fat_goon_jump_in_steps(uint16_t object)
{
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		fat_goon_jump_in_jump(object);
		return;
	case 2:
		fat_goon_jump_in_land(object);
		return;
	case 4:
		fat_goon_from_below_start(object);
		return;
	case 6:
		fat_goon_from_below_steps(object);
		return;
	case -12:
	case 8:
		vector_enemy_think(object, &ignored16, &ignored);
		return;
	case -10:
	case 10:
		vector_enemy_act(object, &ignored16, &ignored);
		return;
	case -8:
	case 12:
		enemy_react_with_pits(object);
		return;
	case -6:
	case 14:
		vector_enemy_climb(object, &ignored16, &ignored);
		return;
	}
}

/* Walks in until there is floor ahead, then jumps onto it. */
void fat_goon_jump_in_jump(uint16_t object)
{
	uint32_t negative = 0;
	uint8_t cell = 0;
	uint16_t floor_cell = 0;
	uint8_t attributes = 0, action_step = 0;
	uint16_t scroll_z_speed = 0;

	vector_floor_ahead_x(object, &floor_cell, &negative);
	cell = (uint8_t)(floor_cell >> 8);
	priority_bits = cell;
	OBJECT(object)->floor_cell = cell;
	if ((int8_t)cell < 0)
	{
		scroll_z_speed = cemetery_scroll_speed;
		OBJECT(object)->z_speed = scroll_z_speed;
		return;
	}
	OBJECT(object)->floor_z = (OBJECT(object)->floor_z & 0xFF00u) | ((((cell & 0xFu) << 1) << 1) << 1 & 0xFFu);
	priority_bits &= 0x30u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = attributes & 0xC0u;
	OBJECT(object)->z_speed = 0x400;
	OBJECT(object)->flags = 0x88u;
	OBJECT(object)->animation = 0x84u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Lands, then finds the nearest player and fights. */
void fat_goon_jump_in_land(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	if (carry == 0u)
		return;
	OBJECT(object)->flags = 0xC0u;
	vector_choose_nearest_player(object);
	OBJECT(object)->state = 2u;
}

/* Sets up the fat goon under the cemetery's floor, at the x its spawn's state picks. */
void fat_goon_from_below_start(uint16_t object)
{
	uint8_t parameter = 0, attributes = 0, state = 0;
	uint16_t first_x = 0, goon_x = 0, scroll_z_speed = 0;

	parameter = OBJECT(object)->parameter;
	first_x = fat_goon_from_below_xs[(int8_t)((uint8_t)((uint32_t)parameter << 1)) / 2];
	OBJECT(object)->x = first_x;
	OBJECT(object)->parameter = 0u;
	OBJECT(object)->z = 0xFF80u;
	fat_goon_grabber_setup(object);
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->attributes = 0x20u;
	OBJECT(object)->animation = 0x86u;
	OBJECT(object)->floor_z = 0u;
	goon_x = OBJECT(object)->x;
	if (goon_x >= 0xE0u)
	{
		attributes = OBJECT(object)->attributes;
		OBJECT(object)->attributes = attributes | 0x40u;
	}
	scroll_z_speed = cemetery_scroll_speed;
	OBJECT(object)->z_speed = scroll_z_speed;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Runs the steps of the fat goon coming up from below, by its substep. */
void fat_goon_from_below_steps(uint16_t object)
{
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		fat_goon_from_below_rise(object);
		return;
	case 2:
		fat_goon_from_below_land(object);
		return;
	case 4:
		cleared_wave_start(object);
		return;
	case 6:
		cleared_wave_wait(object);
		return;
	}
}

/* Rises until out of the floor, then jumps out forward. */
void fat_goon_from_below_rise(uint16_t object)
{
	uint8_t z_high = 0, z_low = 0;
	uint8_t attributes = 0, attributes_2 = 0, action_step = 0;
	uint16_t z = 0, scroll_z_speed = 0, x_speed = 0;

	z = OBJECT(object)->z;
	z_low = (uint8_t)z;
	z_high = (uint8_t)(z >> 8);
	if ((int16_t)z < 0 || (uint16_t)(((uint32_t)z_high << 8) | (z_low & 0xFFu)) < 0u)
	{
		scroll_z_speed = cemetery_scroll_speed;
		OBJECT(object)->z_speed = scroll_z_speed;
		return;
	}
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0x10u;
	OBJECT(object)->z_speed = 0x400;
	OBJECT(object)->x_speed = 0x200;
	attributes_2 = OBJECT(object)->attributes;
	if ((attributes_2 & 0x40u) != 0u)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	OBJECT(object)->flags = 0x88u;
	OBJECT(object)->animation = 0x84u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Lands, then finds the nearest player and fights. */
void fat_goon_from_below_land(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	if (carry == 0u)
		return;
	OBJECT(object)->flags = 0xC0u;
	vector_choose_nearest_player(object);
	OBJECT(object)->state = 2u;
}
