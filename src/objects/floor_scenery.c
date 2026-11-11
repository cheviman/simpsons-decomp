/**
 *    Name:        objects/floor_scenery.c
 *    Description: (the unused floor blocker of list 1 type 07)
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Sets up the kind 0F scenery at x 0180 and takes the floor map's row and column under it. */
uint16_t floor_blocker_start(uint16_t object)
{
	uint16_t cell_value = 0, floor_start = 0, setup = 0;
	uint16_t floor_place = 0;
	uint8_t blocked = 0, state = 0;
	uint16_t blocker_y = 0;

	setup = floor_blocker_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->x = 0x180u;
	blocker_y = OBJECT(object)->y;
	OBJECT(object)->y = blocker_y - 2u;
	blocked = OBJECT(object)->blocked;
	OBJECT(object)->blocked = blocked + 1u;
	floor_cell_under(object, &floor_start, &cell_value);
	OBJECT(object)->floor_blocker.floor_cell = cell_value >> 8;
	OBJECT(object)->floor_blocker.floor_start = floor_start;
	floor_place = floor_start;
	OBJECT(object)->floor_blocker.floor_row = floor_place & ~0x3Fu;
	OBJECT(object)->floor_blocker.part = 0u;
	OBJECT(object)->blocked = 0u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	floor_blocker_wait();
	return floor_start;
}

/* Does nothing once all its floor cells are written. */
void floor_blocker_wait(void)
{
}

/* Writes the next part of its floor shape as the scroll brings it in, by field 37. */
uint16_t floor_blocker_steps(uint16_t object)
{
	uint16_t steps = 0;
	uint8_t part = 0;

	steps = floor_blocker_parts_ADDRESS;
	part = OBJECT(object)->floor_blocker.part;
	switch ((int8_t)(uint8_t)((uint32_t)part << 1))
	{
	case 0:
		return floor_blocker_first_part(object, steps);
	case 2:
		return floor_blocker_second_part(object, steps);
	case 4:
		return floor_blocker_last_part(object, steps);
	case 6:
		floor_blocker_part_wait();
		return steps;
	}
	unreachable();
}

/* Writes the first part of its shape into the floor map once the scroll brings it left of 0180. */
uint16_t floor_blocker_first_part(uint16_t object, uint16_t steps)
{
	uint8_t part = 0;
	uint16_t blocker_x = 0;

	blocker_x = OBJECT(object)->x;
	if (blocker_x >= 0x180u)
		return steps;
	leftover_y = floor_blocker_shape_1_ADDRESS;
	steps = floor_blocker_write_cells(object);
	part = OBJECT(object)->floor_blocker.part;
	OBJECT(object)->floor_blocker.part = part + 1u;
	return steps;
}

/* Writes the second part once left of 0160. */
uint16_t floor_blocker_second_part(uint16_t object, uint16_t steps)
{
	uint8_t part = 0;
	uint16_t blocker_x = 0;

	blocker_x = OBJECT(object)->x;
	if (blocker_x >= 0x160u)
		return steps;
	leftover_y = floor_blocker_shape_2_ADDRESS;
	steps = floor_blocker_write_cells(object);
	part = OBJECT(object)->floor_blocker.part;
	OBJECT(object)->floor_blocker.part = part + 1u;
	return steps;
}

/* Writes the last part once left of 0140. */
uint16_t floor_blocker_last_part(uint16_t object, uint16_t steps)
{
	uint16_t u = 0;
	uint8_t state = 0;
	uint16_t blocker_x = 0;

	blocker_x = OBJECT(object)->x;
	if (blocker_x >= 0x140u)
	{
		floor_blocker_part_wait();
		return steps;
	}
	leftover_y = floor_blocker_shape_3_ADDRESS;
	u = floor_blocker_write_cells(object);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	floor_blocker_part_wait();
	return u;
}

/* Does nothing until the scroll brings the next part in. */
void floor_blocker_part_wait(void)
{
}

/* Writes 4 columns of 3 floor cells from the table in Y into the floor map at the object's column. */
uint16_t floor_blocker_write_cells(uint16_t object)
{
	uint8_t control = 0, floor_column = 0;
	uint16_t place = 0;
	uint8_t part_place_low = 0;
	uint8_t part = 0, cell_in_middle = 0, cell_at_bottom = 0, columns_left = 0;
	uint16_t floor_start = 0, floor_row = 0;

	control = board_control | 2u;
	board_control = control;
	io_write8(board_control_register, control);
	floor_start = OBJECT(object)->floor_blocker.floor_start;
	part = OBJECT(object)->floor_blocker.part;
	part_place_low = floor_start + (int8_t)(((uint32_t)part << 1) << 1);
	floor_column = part_place_low;
	OBJECT(object)->floor_blocker.floor_column = floor_column;
	floor_column -= 3u;
	floor_columns_left = 4u;
	do
	{
		floor_row = OBJECT(object)->floor_blocker.floor_row;
		floor_column &= 0x3Fu;
		place = floor_row + floor_column;
		mem_write8(place - 0x40u, mem_read8(leftover_y));
		cell_in_middle = mem_read8(leftover_y + 4u);
		mem_write8(place, cell_in_middle);
		cell_at_bottom = mem_read8(leftover_y + 8u);
		mem_write8(place + 0x40u, cell_at_bottom);
		floor_column++;
		leftover_y = leftover_y + 1u;
		columns_left = floor_columns_left;
		floor_columns_left = columns_left - 1u;
	} while (columns_left != 1u);
	control = board_control & ~3u;
	board_control = control;
	io_write8(board_control_register, control);
	return place;
}

/* Writes the first part of its shape into the floor map. */
uint16_t platform_scenery_first_part(uint16_t object)
{
	uint16_t u = 0;
	uint8_t part = 0;

	leftover_y = platform_scenery_shape_1_ADDRESS;
	u = platform_scenery_write_cells(object);
	part = OBJECT(object)->platform_scenery.part;
	OBJECT(object)->platform_scenery.part = part + 1u;
	return u;
}

/* Writes the second part once the scroll brings it left of 01B0. */
uint16_t platform_scenery_second_part(uint16_t object, uint16_t u)
{
	uint8_t part = 0;
	uint16_t scenery_x = 0;

	scenery_x = OBJECT(object)->x;
	if (scenery_x >= 0x1B0u)
		return u;
	leftover_y = platform_scenery_shape_2_ADDRESS;
	u = platform_scenery_write_cells(object);
	part = OBJECT(object)->platform_scenery.part;
	OBJECT(object)->platform_scenery.part = part + 1u;
	return u;
}

/* Writes the third part once left of 0190. */
uint16_t platform_scenery_third_part(uint16_t object, uint16_t u)
{
	uint8_t part = 0;
	uint16_t scenery_x = 0;

	scenery_x = OBJECT(object)->x;
	if (scenery_x >= 0x190u)
		return u;
	leftover_y = platform_scenery_shape_3_ADDRESS;
	u = platform_scenery_write_cells(object);
	part = OBJECT(object)->platform_scenery.part;
	OBJECT(object)->platform_scenery.part = part + 1u;
	return u;
}

/* Writes the fourth part once left of 0170. */
uint16_t platform_scenery_fourth_part(uint16_t object, uint16_t u)
{
	uint8_t part = 0;
	uint16_t scenery_x = 0;

	scenery_x = OBJECT(object)->x;
	if (scenery_x >= 0x170u)
		return u;
	leftover_y = platform_scenery_shape_4_ADDRESS;
	u = platform_scenery_write_cells(object);
	part = OBJECT(object)->platform_scenery.part;
	OBJECT(object)->platform_scenery.part = part + 1u;
	return u;
}

/* Writes the last part once left of 0150, and settles. */
uint16_t platform_scenery_last_part(uint16_t object, uint16_t u)
{
	uint16_t u_2 = 0;
	uint8_t part = 0;
	uint16_t scenery_x = 0;

	scenery_x = OBJECT(object)->x;
	if (scenery_x >= 0x150u)
	{
		platform_scenery_part_wait();
		return u;
	}
	leftover_y = platform_scenery_shape_5_ADDRESS;
	u_2 = platform_scenery_write_cells(object);
	part = OBJECT(object)->platform_scenery.part;
	OBJECT(object)->platform_scenery.part = part + 1u;
	OBJECT(object)->state = 2u;
	platform_scenery_part_wait();
	return u_2;
}

/* Does nothing until the scroll brings the next part in. */
void platform_scenery_part_wait(void)
{
}

/* Writes 4 columns of 3 floor cells from the table in Y into the floor map at the object's column. */
uint16_t platform_scenery_write_cells(uint16_t object)
{
	uint8_t control = 0, floor_column = 0;
	uint16_t place = 0;
	uint8_t part_place_low = 0;
	uint8_t part = 0, cell_in_middle = 0, cell_at_bottom = 0, columns_left = 0;
	uint16_t floor_start = 0, floor_row = 0;

	control = board_control | 2u;
	board_control = control;
	io_write8(board_control_register, control);
	floor_start = OBJECT(object)->platform_scenery.floor_start;
	part = OBJECT(object)->platform_scenery.part;
	part_place_low = floor_start + (int8_t)(((uint32_t)part << 1) << 1);
	floor_column = part_place_low;
	OBJECT(object)->platform_scenery.floor_column = floor_column;
	floor_column -= 3u;
	floor_columns_left = 4u;
	do
	{
		floor_row = OBJECT(object)->platform_scenery.floor_row;
		floor_column &= 0x3Fu;
		place = floor_row + floor_column;
		mem_write8(place - 0x40u, mem_read8(leftover_y));
		cell_in_middle = mem_read8(leftover_y + 4u);
		mem_write8(place, cell_in_middle);
		cell_at_bottom = mem_read8(leftover_y + 8u);
		mem_write8(place + 0x40u, cell_at_bottom);
		floor_column++;
		leftover_y = leftover_y + 1u;
		columns_left = floor_columns_left;
		floor_columns_left = columns_left - 1u;
	} while (columns_left != 1u);
	control = board_control & ~3u;
	board_control = control;
	io_write8(board_control_register, control);
	return place;
}

/* Sets up the platform scenery at the screen's right edge, taking the floor map's row and column there. */
uint16_t platform_scenery_start(uint16_t object)
{
	uint8_t cell_low = 0, floor_cell = 0;
	uint16_t cell_place = 0, cell_value = 0, floor_start = 0, setup = 0;
	uint8_t floor_start_high = 0, floor_start_low = 0;
	uint16_t floor_place = 0;
	uint8_t state = 0;
	uint16_t scenery_y = 0, raised_y = 0, floor_row = 0;

	setup = platform_scenery_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->shadow_player = 0x40u;
	OBJECT(object)->platform_scenery.held_up = 0x40u;
	OBJECT(object)->x = 0x1BFu;
	scenery_y = OBJECT(object)->y;
	raised_y = scenery_y - 2u;
	OBJECT(object)->y = raised_y;
	floor_cell_under(object, &cell_place, &cell_value);
	floor_cell = (uint8_t)(cell_value >> 8);
	OBJECT(object)->platform_scenery.floor_cell = floor_cell;
	floor_place = cell_place;
	cell_low = (uint8_t)floor_place;
	scenery_floor_column = cell_low;
	OBJECT(object)->platform_scenery.floor_row = ((uint32_t)(floor_place >> 8) << 8) | (cell_low & 0xC0u);
	scenery_floor_column = (scenery_floor_column - 2u) & 0x3Fu;
	floor_row = OBJECT(object)->platform_scenery.floor_row;
	floor_start_high = floor_row >> 8;
	floor_start_low = floor_row | scenery_floor_column;
	floor_start = ((uint32_t)floor_start_high << 8) | floor_start_low;
	OBJECT(object)->platform_scenery.floor_start = floor_start;
	OBJECT(object)->platform_scenery.part = 0xFFu;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return floor_start;
}

/* Gives its 20 columns of floor back to the cell it stood on (or, not held, crashes down). */
uint16_t platform_scenery_clear_floor(uint16_t object, uint16_t piece)
{
	uint8_t floor_column = 0, stood_cell = 0;
	uint16_t place = 0;
	uint16_t floor_place = 0;
	uint8_t held_up = 0, state = 0, floor_cell = 0, columns_left = 0;
	uint16_t floor_start = 0, floor_row = 0;

	held_up = OBJECT(object)->platform_scenery.held_up;
	if (held_up == 0u)
	{
		OBJECT(object)->state = 5u;
		return platform_scenery_crash(object, piece);
	}
	state = OBJECT(object)->state;
	OBJECT(object)->state = state - 1u;
	OBJECT(object)->action = 0u;
	OBJECT(object)->attack = 0u;
	floor_start = OBJECT(object)->platform_scenery.floor_start;
	floor_place = floor_start;
	floor_column = (uint8_t)floor_place;
	OBJECT(object)->platform_scenery.floor_column = floor_column;
	floor_column -= 7u;
	floor_columns_left = 0x14u;
	floor_cell = OBJECT(object)->platform_scenery.floor_cell;
	stood_cell = floor_cell;
	do
	{
		floor_row = OBJECT(object)->platform_scenery.floor_row;
		floor_column &= 0x3Fu;
		place = floor_row + floor_column;
		mem_write8(place - 0x40u, stood_cell);
		mem_write8(place, stood_cell);
		mem_write8(place + 0x40u, stood_cell);
		floor_column++;
		columns_left = floor_columns_left;
		floor_columns_left = columns_left - 1u;
	} while (columns_left != 1u);
	return platform_scenery_react(object);
}

/* Runs the platform's reaction by field 28. */
uint16_t platform_scenery_react(uint16_t object)
{
	uint16_t steps = 0;

	steps = platform_scenery_react_steps(object);
	return steps;
}

/* Settles the platform or presses it down by field 28. */
uint16_t platform_scenery_react_steps(uint16_t object)
{
	uint16_t steps = 0;
	uint8_t action = 0;

	steps = platform_scenery_react_actions_ADDRESS;
	action = OBJECT(object)->action;
	switch ((int8_t)(uint8_t)((uint32_t)action << 1))
	{
	case -92:
	case 0:
		platform_scenery_idle();
		return steps;
	case 2:
		platform_scenery_settle(object);
		return steps;
	case 4:
		platform_scenery_press(object);
		return steps;
	}
	unreachable();
}

/* Puts the platform back on its floor and starts its animation again. */
void platform_scenery_settle(uint16_t object)
{
	uint8_t action = 0;
	uint16_t floor_z = 0;

	floor_z = OBJECT(object)->floor_z;
	OBJECT(object)->z = floor_z;
	OBJECT(object)->animation_flags = 0x80u;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action - 1u;
	platform_scenery_idle();
}

/* Does nothing. */
void platform_scenery_idle(void)
{
}

/* Moves the platform by twice the players present and starts its animation again. */
void platform_scenery_press(uint16_t object)
{
	uint8_t players_counted = 0, action = 0;
	uint16_t z = 0, pressed_z = 0;

	players_counted = io_read8(stage_player_count);
	z = OBJECT(object)->z;
	pressed_z = (uint8_t)((uint32_t)players_counted << 1) + z;
	OBJECT(object)->z = pressed_z;
	OBJECT(object)->animation_flags = 0x80u;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action - 1u;
}

/* Sends the platform flying with its hit box. */
void platform_scenery_launch(uint16_t object)
{
	uint8_t state = 0;

	OBJECT(object)->platform_scenery.held_up = 0u;
	OBJECT(object)->x_speed = 0x400;
	OBJECT(object)->z_speed = 0x400;
	OBJECT(object)->flags = 0x80u;
	leftover_y = platform_scenery_launch_box_ADDRESS;
	vector_set_hit_box(object);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Lands with a crash (sound 6E00), throwing off two pieces, hurting the enemies it touches. */
uint16_t platform_scenery_crash(uint16_t object, uint16_t piece)
{
	uint32_t landed = 0;
	uint16_t child_object = 0, command = 0, ignored16 = 0, ignored16_2 = 0, record = 0;
	uint8_t state = 0;

	vector_apply_gravity(object, &ignored16, &landed);
	if (landed == 0u)
	{
		check_hits_with_enemies(object);
		return piece;
	}
	command = 0x6E00u;
	vector_queue_sound(command);
	OBJECT(object)->animation = 0x81u;
	OBJECT(object)->timer = 4u;
	record = platform_scenery_crash_debris_1_ADDRESS;
	spawn_list_2_child(object, record, &ignored16_2, &landed);
	leftover_y = platform_scenery_crash_debris_2_ADDRESS;
	child_object = platform_scenery_crash_debris_2_ADDRESS;
	spawn_list_2_child(object, child_object, &piece, &landed);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	check_hits_with_enemies(object);
	return piece;
}

/* Waits 4 frames after the crash, then stops. */
void platform_scenery_crash_wait(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->flags = 0x84u;
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->timer = 0x10u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
	check_hits_with_enemies(object);
}

/* Blinks for 16 frames and goes away. */
void platform_scenery_vanish(uint16_t object)
{
	uint8_t timer = 0;

	OBJECT(object)->flags ^= 0x84u;
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
		OBJECT(object)->flags = 0u;
}

/* Sends a piece of the crashed platform flying. */
uint16_t scenery_debris_start(uint16_t object)
{
	uint16_t setup = 0;
	uint8_t state = 0;

	setup = scenery_debris_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->flags = 0x88u;
	OBJECT(object)->x_speed = -0x200;
	OBJECT(object)->z_speed = 0x400;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return setup;
}

/* Bounces the piece once on landing. */
void scenery_debris_bounce(uint16_t object)
{
	uint32_t landed = 0;
	uint16_t ignored16 = 0;
	uint8_t state = 0;

	vector_apply_gravity(object, &ignored16, &landed);
	if (landed)
	{
		OBJECT(object)->z_speed = 0x200;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Lands the piece for good. */
void scenery_debris_land(uint16_t object)
{
	uint32_t landed = 0;
	uint16_t ignored16 = 0;
	uint8_t state = 0;

	vector_apply_gravity(object, &ignored16, &landed);
	if (landed == 0u)
	{
		scenery_debris_idle();
		return;
	}
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	scenery_debris_idle();
}

/* Does nothing once the piece lies. */
void scenery_debris_idle(void)
{
}

/* Writes its three floor parts back to plain floor as it leaves. */
void charging_scenery_clear_floor(uint16_t object)
{
	uint8_t part = 0, part_2 = 0, part_3 = 0;

	OBJECT(object)->charging_scenery.part = 0u;
	leftover_y = plain_floor_shape_ADDRESS;
	platform_scenery_write_cells(object);
	part = OBJECT(object)->charging_scenery.part;
	OBJECT(object)->charging_scenery.part = part + 1u;
	leftover_y = plain_floor_shape_ADDRESS;
	platform_scenery_write_cells(object);
	part_2 = OBJECT(object)->charging_scenery.part;
	OBJECT(object)->charging_scenery.part = part_2 + 1u;
	leftover_y = plain_floor_shape_ADDRESS;
	platform_scenery_write_cells(object);
	part_3 = OBJECT(object)->charging_scenery.part;
	OBJECT(object)->charging_scenery.part = part_3 + 1u;
}

/* Writes the first part of its shape into the floor map. */
uint16_t charging_scenery_first_part(uint16_t object)
{
	uint16_t u = 0;
	uint8_t part = 0;

	leftover_y = charging_scenery_shape_1_ADDRESS;
	u = platform_scenery_write_cells(object);
	part = OBJECT(object)->charging_scenery.part;
	OBJECT(object)->charging_scenery.part = part + 1u;
	return u;
}

/* Writes the second part once the scroll brings it left of 0180. */
uint16_t charging_scenery_second_part(uint16_t object, uint16_t u)
{
	uint8_t part = 0;
	uint16_t scenery_x = 0;

	scenery_x = OBJECT(object)->x;
	if (scenery_x >= 0x180u)
		return u;
	leftover_y = charging_scenery_shape_2_ADDRESS;
	u = platform_scenery_write_cells(object);
	part = OBJECT(object)->charging_scenery.part;
	OBJECT(object)->charging_scenery.part = part + 1u;
	return u;
}

/* Writes the last part once left of 01A0. */
uint16_t charging_scenery_last_part(uint16_t object, uint16_t u)
{
	uint16_t u_2 = 0;
	uint8_t part = 0;
	uint16_t scenery_x = 0;

	scenery_x = OBJECT(object)->x;
	if (scenery_x >= 0x1A0u)
	{
		charging_scenery_part_wait();
		return u;
	}
	leftover_y = charging_scenery_shape_3_ADDRESS;
	u_2 = platform_scenery_write_cells(object);
	part = OBJECT(object)->charging_scenery.part;
	OBJECT(object)->charging_scenery.part = part + 1u;
	charging_scenery_part_wait();
	return u_2;
}

/* Does nothing until the scroll brings the next part in. */
void charging_scenery_part_wait(void)
{
}

/* Sets up the charging scenery behind the players, taking the floor map's row and column under it. */
uint16_t charging_scenery_start(uint16_t object)
{
	uint8_t cell_low = 0, floor_cell = 0;
	uint16_t cell_place = 0, cell_value = 0, floor_start = 0, setup = 0;
	uint8_t floor_start_high = 0, floor_start_low = 0;
	uint16_t floor_place = 0;
	uint8_t attributes = 0, state = 0;
	uint16_t scenery_y = 0, raised_y = 0, floor_row = 0;

	setup = charging_scenery_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->shadow_player = 0x40u;
	scenery_y = OBJECT(object)->y;
	raised_y = scenery_y - 2u;
	OBJECT(object)->y = raised_y;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0x10u;
	floor_cell_under(object, &cell_place, &cell_value);
	floor_cell = (uint8_t)(cell_value >> 8);
	OBJECT(object)->charging_scenery.floor_cell = floor_cell;
	floor_place = cell_place;
	cell_low = (uint8_t)floor_place;
	scenery_floor_column = cell_low;
	OBJECT(object)->charging_scenery.floor_row = ((uint32_t)(floor_place >> 8) << 8) | (cell_low & 0xC0u);
	scenery_floor_column = (scenery_floor_column - 2u) & 0x3Fu;
	floor_row = OBJECT(object)->charging_scenery.floor_row;
	floor_start_high = floor_row >> 8;
	floor_start_low = floor_row | scenery_floor_column;
	floor_start = ((uint32_t)floor_start_high << 8) | floor_start_low;
	OBJECT(object)->charging_scenery.floor_start = floor_start;
	OBJECT(object)->charging_scenery.part = 0u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return floor_start;
}

/* Waits until its three floor parts are written. */
void charging_scenery_wait_shape(uint16_t object)
{
	uint8_t part = 0, state = 0;

	part = OBJECT(object)->charging_scenery.part;
	if (part == 3u)
	{
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Picks a player object in play, starting from a random one (the frame count's low byte). */
uint16_t pick_random_player(void)
{
	uint8_t slot = 0, tries = 0;
	uint16_t player = 0;
	uint8_t flags = 0, tries_before = 0;

	tries = 4u;
	slot = (uint8_t)frame_count;
	do
	{
		player = player_objects[slot & 3u];
		flags = OBJECT(player)->flags;
		slot = flags;
		if (flags != 0u)
			break;
		slot++;
		tries_before = tries;
		tries = tries_before - 1u;
	} while (tries_before != 1u);
	return player;
}

/* Once on screen with a player at the right angle, charges up and left, letting out one or two goons
   with hats. */
uint16_t charging_scenery_wait_target(uint16_t object, uint16_t u)
{
	uint32_t slot_found = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, u_2 = 0;
	uint8_t target_direction = 0, state = 0;
	uint16_t scenery_x = 0;

	scenery_x = OBJECT(object)->x;
	if (scenery_x >= 0x128u)
		return u;
	u = pick_random_player();
	vector_measure_target(object, u);
	target_direction = OBJECT(object)->target_direction;
	if (target_direction != 0xA0u)
		return u;
	OBJECT(object)->flags = 0xC0u;
	OBJECT(object)->x_speed = -0x200;
	OBJECT(object)->y_speed = -0x400;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	charging_scenery_clear_floor(object);
	leftover_y = charging_scenery_goon_left_ADDRESS;
	vector_spawn_child(object, &ignored16, &u_2, &ignored16_2, &slot_found);
	if (player_count <= 2u)
		return u_2;
	leftover_y = charging_scenery_goon_right_ADDRESS;
	vector_spawn_child(object, &ignored16, &u_2, &ignored16_2, &slot_found);
	return u_2;
}

/* Charges, hurting the players and the enemies in turn, until it leaves at the top. */
void charging_scenery_charge(uint16_t object)
{
	uint8_t flags = 0;
	uint16_t scenery_y = 0;

	scenery_y = OBJECT(object)->y;
	if (scenery_y < 0x40u)
	{
		OBJECT(object)->flags = 0u;
		return;
	}
	flags = OBJECT(object)->flags ^ 0x40u;
	OBJECT(object)->flags = flags;
	if ((flags & 0x40u) != 0u)
	{
		OBJECT(object)->attack = 2u;
		return;
	}
	OBJECT(object)->attack = 0x14u;
	check_hits_with_enemies(object);
}

/* Sets up the solid scenery raised off the floor and blocks the floor cells under it. */
uint16_t solid_scenery_start(uint16_t object)
{
	uint16_t setup = 0, u = 0;
	uint8_t attributes = 0, state = 0;
	uint16_t z = 0, raised_z = 0;

	setup = solid_scenery_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->flags = 0x80u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0x10u;
	z = OBJECT(object)->z;
	raised_z = z + 0x4Cu;
	OBJECT(object)->z = raised_z;
	u = scenery_block_floor(object);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	solid_scenery_idle();
	return u;
}

/* Does nothing. */
void solid_scenery_idle(void)
{
}

/* Sets the rising scenery up (kind 10 for the second) and the camera x it waits for. */
uint16_t rising_scenery_start(uint16_t object)
{
	uint16_t camera_xs = 0, setup = 0;
	uint8_t attributes = 0, parameter = 0, old_rise_cue = 0, parameter_2 = 0, state = 0;
	uint16_t scenery_x = 0, moved_x = 0, scenery_y = 0, raised_y = 0, camera_trigger = 0;

	setup = rising_scenery_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->flags = 0x80u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0x20u;
	parameter = OBJECT(object)->parameter;
	if (parameter != 0u)
	{
		old_rise_cue = io_read8(rising_scenery_cue);
		io_write8(rising_scenery_cue, 0u);
		OBJECT(object)->kind = 0x10u;
		OBJECT(object)->animation = 7u;
		scenery_x = OBJECT(object)->x;
		moved_x = scenery_x + 8u;
		OBJECT(object)->x = moved_x;
		scenery_y = OBJECT(object)->y;
		raised_y = scenery_y - 2u;
		OBJECT(object)->y = raised_y;
	}
	camera_xs = rising_scenery_camera_xs_ADDRESS;
	parameter_2 = OBJECT(object)->parameter;
	camera_trigger = rising_scenery_camera_xs[(int8_t)((uint8_t)((uint32_t)parameter_2 << 1)) / 2];
	OBJECT(object)->rising_scenery.trigger_x = camera_trigger;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return camera_xs;
}

/* Waits for the camera, then starts rising (sound 4600 for the first). */
void rising_scenery_wait_camera(uint16_t object)
{
	uint16_t command = 0;
	uint8_t parameter = 0, state = 0;
	uint16_t camera_x_now = 0, trigger_x = 0;

	camera_x_now = camera_x;
	trigger_x = OBJECT(object)->rising_scenery.trigger_x;
	if (camera_x_now < trigger_x)
		return;
	parameter = OBJECT(object)->parameter;
	if (parameter == 0u)
	{
		command = 0x4600u;
		vector_queue_sound(command);
	}
	OBJECT(object)->z_speed = 0x200;
	OBJECT(object)->timer = 0x40u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Rises out of the stage for 64 frames holding the scroll, then goes away. */
void rising_scenery_rise(uint16_t object)
{
	uint8_t timer_left = 0;
	uint8_t timer = 0, timer_2 = 0;

	camera_x_held--;
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
		OBJECT(object)->flags = 0u;
	timer_2 = OBJECT(object)->timer;
	timer_left = timer_2;
	if (timer_left == 0x20u)
		io_write8(rising_scenery_cue, timer_left);
}

/* Sets the scenery up at x 01A0 with the speed, animation and attributes its spawn's state picks. */
uint16_t looping_scenery_start(uint16_t object)
{
	uint16_t looping_scenery_move = 0, setup = 0;
	uint8_t parameter = 0, state = 0;
	uint16_t x_speed = 0, animation = 0;

	setup = looping_scenery_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->x = 0x1A0u;
	parameter = OBJECT(object)->parameter;
	looping_scenery_move = looping_scenery_moves_ADDRESS + (int8_t)(((uint32_t)parameter << 1) << 1);
	x_speed = LOOPING_SCENERY_MOVE(looping_scenery_move)->x_speed;
	OBJECT(object)->x_speed = x_speed;
	animation = (((uint32_t)LOOPING_SCENERY_MOVE(looping_scenery_move)->animation << 8u) | LOOPING_SCENERY_MOVE(looping_scenery_move)->attributes);
	OBJECT(object)->animation = (animation >> 8) | 0x80u;
	OBJECT(object)->attributes = animation;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return looping_scenery_move;
}

/* Keeps the scenery's x within 0000-01FF so it comes round again. */
void looping_scenery_wrap(uint16_t object)
{
	uint8_t x_high = 0;

	x_high = (uint8_t)(OBJECT(object)->x >> 8u);
	OBJECT(object)->x = (OBJECT(object)->x & 0xFFu) | ((x_high & 1u & 0xFFu) << 8u);
}

/* Keeps the scenery coming round until the camera passes 06B0. */
void looping_scenery_wrap_until_camera(uint16_t object)
{
	uint8_t x_high = 0, state = 0;
	uint16_t camera_x_now = 0;

	x_high = (uint8_t)(OBJECT(object)->x >> 8u);
	OBJECT(object)->x = (OBJECT(object)->x & 0xFFu) | ((x_high & 1u & 0xFFu) << 8u);
	camera_x_now = camera_x;
	if (camera_x_now >= 0x6B0u)
	{
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Lets the scenery move off, gone past x 01C0. */
void looping_scenery_leave(uint16_t object)
{
	uint8_t x_high = 0;
	uint16_t scenery_x = 0;

	x_high = (uint8_t)(OBJECT(object)->x >> 8u);
	OBJECT(object)->x = (OBJECT(object)->x & 0xFFu) | ((x_high & 1u & 0xFFu) << 8u);
	scenery_x = OBJECT(object)->x;
	if (scenery_x >= 0x1C0u)
		OBJECT(object)->flags = 0u;
}
