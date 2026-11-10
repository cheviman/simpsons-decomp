/**
 *    Name:        objects/kind_10_scenery.c
 *    Description: stage 4's kind 10 scenery: what rises at the end and what comes down
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Sets up the kind 10 scenery that will rise, behind the players. */
void kind_10_riser_start(uint16_t object, uint16_t *p_box, uint16_t *p_setup)
{
	uint16_t box = 0, setup = 0;
	uint8_t animation_flags = 0, parameter = 0, animation = 0, attributes = 0, state = 0;
	uint16_t t1 = 0, t2 = 0;

	setup = kind_10_riser_setup_ADDRESS;
	box = vector_object_setup(object, setup);
	t1 = OBJECT(object)->x;
	t2 = t1 + 0x10u;
	OBJECT(object)->x = t2;
	animation_flags = OBJECT(object)->animation_flags;
	OBJECT(object)->animation_flags = animation_flags | 0x80u;
	parameter = OBJECT(object)->parameter;
	if (parameter != 0u)
	{
		animation = OBJECT(object)->animation;
		OBJECT(object)->animation = (animation + 1u) | 0x80u;
	}
	OBJECT(object)->flags = 0x80u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0x20u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	*p_box = box;
	*p_setup = setup;
}

/* Waits until the stage's boss is beaten, then starts rising (sound 1500 for the second one). */
void kind_10_riser_wait_boss(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t parameter = 0, state = 0;

	if (boss_beaten == 0u)
		return;
	parameter = OBJECT(object)->parameter;
	if (parameter != 0u)
	{
		command = 0x1500u;
		carry = vector_queue_sound(command);
	}
	OBJECT(object)->z_speed = 0x40;
	OBJECT(object)->timer = 4u;
	OBJECT(object)->kind_10_riser.rise_steps = 8u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Rises slowly for 32 frames. */
void kind_10_riser_rise_slowly(uint16_t object)
{
	uint8_t timer = 0, rise_steps = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->timer = 4u;
		rise_steps = OBJECT(object)->kind_10_riser.rise_steps;
		OBJECT(object)->kind_10_riser.rise_steps = rise_steps - 1u;
		if (rise_steps == 1u)
		{
			OBJECT(object)->timer = 0x40u;
			OBJECT(object)->z_speed = 0x40;
			state = OBJECT(object)->state;
			OBJECT(object)->state = state + 1u;
		}
	}
}

/* Rises faster and faster for 64 frames. */
void kind_10_riser_rise_faster(uint16_t object)
{
	uint8_t timer = 0, state = 0;
	uint16_t z_speed = 0;

	z_speed = OBJECT(object)->z_speed;
	OBJECT(object)->z_speed = z_speed + 4u;
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Stops rising once high enough. */
void kind_10_riser_stop(uint16_t object)
{
	uint8_t state = 0;
	uint16_t z = 0;

	z = OBJECT(object)->z;
	if (z < 0x80u)
	{
		kind_10_riser_idle();
		return;
	}
	OBJECT(object)->z_speed = 0;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	kind_10_riser_idle();
}

/* Does nothing once it has risen. */
void kind_10_riser_idle(void)
{
}

/* Sets up the kind 10 scenery that comes down, taking the floor map's row and column under it. */
void kind_10_dropper_start(uint16_t object, uint16_t *p_box, uint16_t *p_u)
{
	uint8_t floor_cell_2 = 0, floor_place_low = 0;
	uint16_t box = 0, floor_cell = 0, floor_start = 0;
	uint16_t stack = 0;
	uint8_t animation_flags = 0, parameter = 0, animation = 0, attributes = 0, state = 0;
	uint16_t t1 = 0, t2 = 0;

	floor_start = kind_10_dropper_setup_ADDRESS;
	box = vector_object_setup(object, floor_start);
	OBJECT(object)->flags = 0x80u;
	t1 = OBJECT(object)->x;
	t2 = t1 + 0x10u;
	OBJECT(object)->x = t2;
	animation_flags = OBJECT(object)->animation_flags;
	OBJECT(object)->animation_flags = animation_flags | 0x80u;
	parameter = OBJECT(object)->parameter;
	if (parameter == 0u)
	{
		animation = OBJECT(object)->animation;
		OBJECT(object)->animation = (animation - 1u) | 0x80u;
		floor_cell_under(object, &floor_start, &floor_cell);
		floor_cell_2 = (uint8_t)(floor_cell >> 8);
		OBJECT(object)->kind_10_dropper.floor_start = floor_start;
		OBJECT(object)->kind_10_dropper.floor_cell = floor_cell_2;
		stack = floor_start;
		floor_place_low = (uint8_t)stack;
		scenery_floor_column = floor_place_low;
		OBJECT(object)->kind_10_dropper.floor_row = ((uint32_t)(stack >> 8) << 8) | (floor_place_low & 0xC0u);
	}
	OBJECT(object)->floor_z = 0u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0x20u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	*p_box = box;
	*p_u = floor_start;
}

/* Waits until direct page 92 is clear, then 32 frames more. */
void kind_10_dropper_wait(uint16_t object)
{
	uint8_t state = 0;

	if (stage_scrolls_on == 0u)
	{
		OBJECT(object)->timer = 0x20u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Starts coming down for 64 frames (sound 1300 for the first). */
void kind_10_dropper_come_down(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t timer = 0, parameter = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	parameter = OBJECT(object)->parameter;
	if (parameter == 0u)
	{
		command = 0x1300u;
		carry = vector_queue_sound(command);
	}
	OBJECT(object)->timer = 0x40u;
	OBJECT(object)->z_speed = -0x80;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Stops when down; the first counts itself in 184A and rewrites the floor. */
void kind_10_dropper_land(uint16_t object, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint8_t timer = 0, parameter = 0, animation_flags = 0, t1 = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		kind_10_dropper_idle();
	else
	{
		OBJECT(object)->z_speed = 0;
		parameter = OBJECT(object)->parameter;
		if (parameter == 0u)
		{
			animation_flags = OBJECT(object)->animation_flags;
			OBJECT(object)->animation_flags = animation_flags | 0x80u;
			t1 = io_read8(0x184Au);
			io_write8(0x184Au, t1 + 1u);
			kind_10_dropper_write_floor(object, &y, &u);
		}
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
		kind_10_dropper_idle();
	}
	*p_y = y;
	*p_u = u;
}

/* Does nothing once down. */
void kind_10_dropper_idle(void)
{
}

/* Rewrites 32 columns of the floor map from its place, six cells each, the last columns as edges. */
void kind_10_dropper_write_floor(uint16_t object, uint16_t *p_column, uint16_t *p_floor_place)
{
	uint8_t control = 0, floor_column = 0;
	uint16_t column = 0, floor_place = 0;
	uint8_t stack = 0;
	uint8_t row = 0, row_2 = 0, row_3 = 0, row_4 = 0, row_5 = 0, t1 = 0;
	uint16_t floor_start = 0, floor_row = 0;

	control = board_control | 2u;
	board_control = control;
	io_write8(0x1FC2u, control);
	floor_columns_left = 0x20u;
	floor_start = OBJECT(object)->kind_10_dropper.floor_start;
	stack = floor_start;
	floor_column = stack;
	OBJECT(object)->kind_10_dropper.floor_column = floor_column;
	floor_column -= 5u;
	do
	{
		if (kind_10_floor_edge_flags[(int8_t)floor_columns_left] != 0u)
			column = kind_10_edge_floor_cells_ADDRESS;
		else
			column = kind_10_floor_cells_ADDRESS;
		floor_row = OBJECT(object)->kind_10_dropper.floor_row;
		floor_column &= 0x3Fu;
		floor_place = floor_row + floor_column;
		mem_write8(floor_place, FLOOR_COLUMN(column)->row_0);
		row = FLOOR_COLUMN(column)->row_1;
		mem_write8(floor_place + 0x40u, row);
		row_2 = FLOOR_COLUMN(column)->row_2;
		mem_write8(floor_place + 0x80u, row_2);
		row_3 = FLOOR_COLUMN(column)->row_3;
		mem_write8(floor_place + 0xC0u, row_3);
		row_4 = FLOOR_COLUMN(column)->row_4;
		mem_write8(floor_place + 0x100u, row_4);
		row_5 = FLOOR_COLUMN(column)->row_5;
		mem_write8(floor_place + 0x140u, row_5);
		floor_column++;
		t1 = floor_columns_left;
		floor_columns_left = t1 - 1u;
	} while (t1 != 1u);
	control = board_control & ~3u;
	board_control = control;
	io_write8(0x1FC2u, control);
	*p_column = column;
	*p_floor_place = floor_place;
}
