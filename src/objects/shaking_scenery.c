/**
 *    Name:        objects/shaking_scenery.c
 *    Description: the scenery that shakes when hit, and what falls off it
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Sets up a small piece falling off the shaking scenery. */
void shaken_bit_start(uint16_t object, uint16_t *p_box, uint16_t *p_setup)
{
	uint16_t box = 0, setup = 0;
	uint8_t attributes = 0, parameter = 0, state = 0;

	setup = shaken_bit_setup_ADDRESS;
	box = vector_object_setup(object, setup);
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0x10u;
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->timer = 0x20u;
	OBJECT(object)->x_speed = 0x20;
	OBJECT(object)->z_speed = -0x100;
	parameter = OBJECT(object)->parameter;
	if (parameter != 0u)
		OBJECT(object)->animation = 0x90u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	*p_box = box;
	*p_setup = setup;
}

/* Falls for 32 frames or until near the floor, then goes away. */
void shaken_bit_fall(uint16_t object)
{
	uint8_t timer = 0;
	uint16_t z = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
	{
		z = OBJECT(object)->z;
		if (z < 0x10u)
			OBJECT(object)->flags = 0u;
		return;
	}
	OBJECT(object)->flags = 0u;
}

/* Sets up the object sitting on the shaking scenery. */
void shaken_object_start(uint16_t object, uint16_t *p_box, uint16_t *p_setup)
{
	uint16_t box = 0, setup = 0;
	uint8_t attributes = 0, state = 0;

	setup = shaken_object_setup_ADDRESS;
	box = vector_object_setup(object, setup);
	OBJECT(object)->flags = 0x80u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0x10u;
	OBJECT(object)->parameter = 0x1Cu;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	*p_box = box;
	*p_setup = setup;
}

/* Waits until the scenery under it shakes, then starts falling. */
uint16_t shaken_object_wait(uint16_t object)
{
	uint16_t scenery = 0;
	uint8_t state = 0;
	uint16_t parent = 0;

	parent = OBJECT(object)->parent;
	scenery = parent;
	if ((OBJECT(scenery)->flags & 0x40u) == 0u)
	{
		OBJECT(object)->flags = 0x88u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
	return scenery;
}

/* Falls and bounces off the floor. */
void shaken_object_fall(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;
	uint8_t state = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	if (carry)
	{
		OBJECT(object)->flags = 0x88u;
		OBJECT(object)->x_speed = 0x200;
		OBJECT(object)->z_speed = 0x200;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Lands for good: becomes a throwable (list 1 type 01) and lets out a buzzing chaser. */
void shaken_object_land(uint16_t object, uint16_t *p_child_record, uint16_t *p_u)
{
	uint16_t child_record = (uint16_t)*p_child_record;
	uint16_t u = (uint16_t)*p_u;
	uint32_t negative = 0, carry = 0;
	uint16_t floor_cell = 0, ignored16 = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	if (carry)
	{
		OBJECT(object)->x_speed = 0;
		floor_cell = 0u;
		vector_floor_at_offset(object, &floor_cell, &negative);
		if ((int8_t)(floor_cell >> 8) < 0)
			OBJECT(object)->flags = 0u;
		else
		{
			OBJECT(object)->type = 1;
			OBJECT(object)->state = 0u;
			child_record = shaken_object_land_child_ADDRESS;
			spawn_list_2_child(object, child_record, &u, &carry);
		}
	}
	*p_child_record = child_record;
	*p_u = u;
}

/* When hit by something 0050 or more over its floor, starts the reaction to a hit from above. */
uint16_t shaking_scenery_check_hit_from_above(uint16_t object, uint16_t hitter)
{
	uint8_t state = 0;
	uint16_t hit_by = 0, z = 0, floor_z = 0, t1 = 0;

	state = OBJECT(object)->state;
	if ((int8_t)state >= 0 && (OBJECT(object)->flags & 0x20u) != 0u)
	{
		hit_by = OBJECT(object)->hit_by;
		hitter = hit_by;
		z = OBJECT(hitter)->z;
		floor_z = OBJECT(object)->floor_z;
		t1 = z - floor_z;
		if (t1 >= 0x50u)
		{
			OBJECT(object)->flags = 0x80u;
			OBJECT(object)->state = 0xFDu;
			OBJECT(object)->action = 0u;
			shaking_scenery_idle();
			return hitter;
		}
	}
	shaking_scenery_idle();
	return hitter;
}

/* Does nothing between hits. */
void shaking_scenery_idle(void)
{
}

/* Sets the scenery up by its spawn's state: its kind, food pattern and shake animations, and what sits
   in it. */
void shaking_scenery_start(uint16_t object, uint16_t *p_record, uint16_t *p_setup)
{
	uint32_t carry = 0;
	uint8_t parameter = 0, start_animation = 0, variant = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, object_16_animation_run = 0, pattern_start = 0, record = 0, setup = 0, u = 0;
	uint8_t parameter_2 = 0, t1 = 0, attributes = 0, parameter_3 = 0, state = 0;
	uint16_t pattern = 0, kind = 0, first = 0, third = 0, t2 = 0, t3 = 0;

	setup = shaking_scenery_setup_ADDRESS;
	record = vector_object_setup(object, setup);
	parameter_2 = OBJECT(object)->parameter;
	variant = parameter_2;
	if ((int8_t)parameter_2 < 0)
	{
		t1 = variant & 0x7Fu;
		parameter = t1;
		if (t1 == 0u)
		{
			attributes = OBJECT(object)->attributes;
			OBJECT(object)->attributes = (attributes & 0xCFu) | 0x20u;
			OBJECT(object)->flags = 0x80u;
			*p_record = record;
			*p_setup = setup;
			return;
		}
		OBJECT(object)->parameter = parameter;
		if (parameter != 1u)
		{
			record = shaking_scenery_child_4_ADDRESS;
			vector_spawn_child(object, record, &ignored16, &ignored16_2, &carry);
			variant = 2u;
		}
		else
		{
			record = shaking_scenery_child_1_ADDRESS;
			vector_spawn_child(object, record, &ignored16, &ignored16_2, &carry);
			record = shaking_scenery_child_2_ADDRESS;
			vector_spawn_child(object, record, &ignored16, &ignored16_2, &carry);
			record = shaking_scenery_child_3_ADDRESS;
			vector_spawn_child(object, record, &ignored16, &ignored16_2, &carry);
			variant = 0u;
		}
	}
	OBJECT(object)->shaking_scenery.food_flags = object_16_flags[(int8_t)variant];
	pattern_start = object_16_kinds_ADDRESS + (int8_t)(((uint32_t)variant << 1) << 1);
	pattern = PATTERN_START(pattern_start)->pattern;
	OBJECT(object)->shaking_scenery.pattern = pattern;
	kind = (((uint32_t)PATTERN_START(pattern_start)->kind << 8u) | PATTERN_START(pattern_start)->animation);
	start_animation = (uint8_t)kind;
	OBJECT(object)->kind = kind >> 8;
	OBJECT(object)->animation = start_animation;
	OBJECT(object)->shaking_scenery.kept_animation = start_animation;
	OBJECT(object)->shaking_scenery.standing_animation = start_animation;
	parameter_3 = OBJECT(object)->parameter;
	object_16_animation_run = object_16_animation_runs_ADDRESS + (int8_t)(((uint32_t)parameter_3 << 1) << 1);
	first = (((uint32_t)OBJECT_16_ANIMATION_RUN(object_16_animation_run)->first << 8u) | OBJECT_16_ANIMATION_RUN(object_16_animation_run)->second);
	OBJECT(object)->shaking_scenery.shake_animation_1 = (uint8_t)(first >> 8u);
	OBJECT(object)->shaking_scenery.shake_animation_2 = (uint8_t)first;
	third = (((uint32_t)OBJECT_16_ANIMATION_RUN(object_16_animation_run)->third << 8u) | OBJECT_16_ANIMATION_RUN(object_16_animation_run)->fourth);
	OBJECT(object)->shaking_scenery.shake_animation_3 = (uint8_t)(third >> 8u);
	OBJECT(object)->shaking_scenery.shake_animation_4 = (uint8_t)third;
	OBJECT(object)->shaking_scenery.food_left = 5u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	t2 = OBJECT(object)->y;
	t3 = t2 - 2u;
	OBJECT(object)->y = t3;
	u = scenery_block_floor(object);
	*p_record = record;
	*p_setup = u;
}

/* Marks the 3 floor cells under the object as no floor, keeping the cell's old value and place. */
uint16_t scenery_block_floor(uint16_t object)
{
	uint8_t column = 0, control = 0, floor_column = 0, no_floor = 0, old_cell = 0;
	uint16_t floor_cell = 0, floor_place = 0, floor_start = 0;
	uint8_t stack = 0, stack_2 = 0;
	uint8_t blocked = 0, floor_column_2 = 0, t1 = 0;
	uint16_t floor_row = 0;

	blocked = OBJECT(object)->blocked;
	OBJECT(object)->blocked = blocked + 1u;
	floor_cell_under(object, &floor_start, &floor_cell);
	old_cell = (uint8_t)(floor_cell >> 8);
	stack = old_cell;
	control = board_control | 2u;
	board_control = control;
	io_write8(0x1FC2u, control);
	OBJECT(object)->scenery.floor_cell = stack;
	OBJECT(object)->scenery.floor_start = floor_start;
	stack_2 = floor_start >> 8;
	stack = (uint8_t)floor_start;
	floor_column = stack;
	OBJECT(object)->scenery.floor_column = floor_column;
	OBJECT(object)->scenery.floor_row = ((uint32_t)stack_2 << 8) | (floor_column & 0xC0u);
	floor_columns_left = 3u;
	floor_column_2 = OBJECT(object)->scenery.floor_column;
	column = floor_column_2 - 2u;
	no_floor = 0xFFu;
	do
	{
		floor_row = OBJECT(object)->scenery.floor_row;
		column &= 0x3Fu;
		floor_place = floor_row + column;
		mem_write8(floor_place, no_floor);
		column++;
		t1 = floor_columns_left;
		floor_columns_left = t1 - 1u;
	} while (t1 != 1u);
	control = board_control & ~3u;
	board_control = control;
	io_write8(0x1FC2u, control);
	return floor_place;
}

/* Runs the scenery's shake by its substep. */
void shaking_scenery_shake_steps(uint16_t object, uint16_t *p_y, uint16_t *p_step_handlers)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t step_handlers = 0;
	uint8_t action_step = 0;

	step_handlers = shaking_scenery_shake_step_handlers_ADDRESS;
	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		shaking_scenery_shake(object);
		break;
	case 2:
		shaking_scenery_shake_second(object);
		break;
	case 4:
		shaking_scenery_shake_third(object);
		break;
	case 6:
		shaking_scenery_shake_fourth(object);
		break;
	case 8:
		shaking_scenery_shake_end(object);
		break;
	case 10:
		shaking_scenery_drop_bit(object, &y, &step_handlers);
		break;
	case 12:
	case 32:
		shaking_scenery_recover(object);
		break;
	}
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* Plays sound 4800 and the shake's first animation. */
void shaking_scenery_shake(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t shake_animation = 0, action_step = 0;

	command = 0x4800u;
	carry = vector_queue_sound(command);
	shake_animation = OBJECT(object)->shaking_scenery.shake_animation_1;
	OBJECT(object)->animation = shake_animation;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* After the first animation, the second; at its mark, sound 0C01. */
void shaking_scenery_shake_second(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t animation_flags = 0, shake_animation = 0, action_step = 0, animation_flags_2 = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		shake_animation = OBJECT(object)->shaking_scenery.shake_animation_2;
		OBJECT(object)->animation = shake_animation;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
		return;
	}
	animation_flags_2 = OBJECT(object)->animation_flags;
	if ((animation_flags_2 & 2u) == 0u)
		return;
	command = 0xC01u;
	carry = vector_queue_sound(command);
}

/* After the second animation, the third. */
void shaking_scenery_shake_third(uint16_t object)
{
	uint8_t animation_flags = 0, shake_animation = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		shake_animation = OBJECT(object)->shaking_scenery.shake_animation_3;
		OBJECT(object)->animation = shake_animation;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* After the third animation, the fourth. */
void shaking_scenery_shake_fourth(uint16_t object)
{
	uint8_t animation_flags = 0, shake_animation = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		shake_animation = OBJECT(object)->shaking_scenery.shake_animation_4;
		OBJECT(object)->animation = shake_animation;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* After the fourth animation, goes back to standing. */
void shaking_scenery_shake_end(uint16_t object)
{
	uint8_t animation_flags = 0, kept_animation = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		OBJECT(object)->flags = 0xC0u;
		kept_animation = OBJECT(object)->shaking_scenery.kept_animation;
		OBJECT(object)->animation = kept_animation;
		OBJECT(object)->state = 1u;
	}
}

/* Runs the reaction to a hit from above by field 28. */
void shaking_scenery_hit_from_above_steps(uint16_t object, uint16_t *p_y, uint16_t *p_action_handlers)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t action_handlers = 0;
	uint8_t action = 0;

	action_handlers = shaking_scenery_hit_from_above_actions_ADDRESS;
	action = OBJECT(object)->action;
	switch ((int8_t)(uint8_t)((uint32_t)action << 1))
	{
	case 0:
		shaking_scenery_drop_bit(object, &y, &action_handlers);
		break;
	case 2:
	case 22:
		shaking_scenery_recover(object);
		break;
	case -10:
		shaking_scenery_shake(object);
		break;
	case -8:
		shaking_scenery_shake_second(object);
		break;
	case -6:
		shaking_scenery_shake_third(object);
		break;
	case -4:
		shaking_scenery_shake_fourth(object);
		break;
	case -2:
		shaking_scenery_shake_end(object);
		break;
	}
	*p_y = y;
	*p_action_handlers = action_handlers;
}

/* Shows its hit animation and drops a small piece. */
void shaking_scenery_drop_bit(uint16_t object, uint16_t *p_child_record, uint16_t *p_u)
{
	uint32_t carry = 0;
	uint16_t child_record = 0, dropped_bit = 0, ignored16 = 0;
	uint8_t standing_animation = 0, action = 0, kind = 0;

	standing_animation = OBJECT(object)->shaking_scenery.standing_animation;
	OBJECT(object)->animation = standing_animation + 1u;
	OBJECT(object)->timer = 0x20u;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
	kind = OBJECT(object)->kind;
	if (kind != 0xFu)
	{
		child_record = shaking_scenery_bit_2_ADDRESS;
		vector_spawn_child(object, child_record, &dropped_bit, &ignored16, &carry);
	}
	else
	{
		child_record = shaking_scenery_bit_1_ADDRESS;
		vector_spawn_child(object, child_record, &dropped_bit, &ignored16, &carry);
	}
	*p_child_record = child_record;
	*p_u = dropped_bit;
}

/* Runs the reaction to a hit by field 28. */
void shaking_scenery_hit_steps(uint16_t object, uint16_t *p_y, uint16_t *p_action_handlers)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t action_handlers = 0;
	uint8_t action = 0;

	action_handlers = shaking_scenery_hit_actions_ADDRESS;
	action = OBJECT(object)->action;
	switch ((int8_t)(uint8_t)((uint32_t)action << 1))
	{
	case 0:
		shaking_scenery_drop_food(object, &y, &action_handlers);
		break;
	case -18:
	case 2:
		shaking_scenery_recover(object);
		break;
	}
	*p_y = y;
	*p_action_handlers = action_handlers;
}

/* Lets out the next food of its pattern (sound 1C00); after the fifth it can take no more. */
void shaking_scenery_drop_food(uint16_t object, uint16_t *p_y, uint16_t *p_food)
{
	uint32_t carry = 0;
	uint8_t food_parameter = 0, pattern_byte = 0;
	uint16_t command = 0, food = 0, ignored16 = 0, y = 0;
	uint8_t food_left = 0, food_left_2 = 0, food_flags = 0, standing_animation = 0, action = 0;
	uint16_t pattern = 0, hit_by = 0;

	y = shaking_scenery_drop_food_child_ADDRESS;
	vector_spawn_child(object, y, &food, &ignored16, &carry);
	if (carry)
	{
		pattern = OBJECT(object)->shaking_scenery.pattern;
		y = pattern;
		food_left = OBJECT(object)->shaking_scenery.food_left;
		OBJECT(object)->shaking_scenery.food_left = food_left - 1u;
		if (food_left == 1u)
			OBJECT(object)->vitality = 0u;
		food_left_2 = OBJECT(object)->shaking_scenery.food_left;
		pattern_byte = mem_read8(y + (food_left_2 & 0xFu));
		food_state = pattern_byte;
		if (player_count <= (pattern_byte >> 1) >> 1)
		{
			food_flags = OBJECT(object)->shaking_scenery.food_flags;
			food_parameter = food_flags;
		}
		else
			food_parameter = food_state;
		OBJECT(food)->parameter = food_parameter;
		hit_by = OBJECT(object)->hit_by;
		OBJECT(food)->behaviour = hit_by;
	}
	command = 0x1C00u;
	carry = vector_queue_sound(command);
	standing_animation = OBJECT(object)->shaking_scenery.standing_animation;
	OBJECT(object)->animation = standing_animation + 1u;
	OBJECT(object)->timer = 0x20u;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
	*p_y = y;
	*p_food = food;
}

/* After 32 frames, goes back to standing. */
void shaking_scenery_recover(uint16_t object)
{
	uint8_t timer = 0, standing_animation = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		standing_animation = OBJECT(object)->shaking_scenery.standing_animation;
		OBJECT(object)->animation = standing_animation;
		OBJECT(object)->state = 1u;
		OBJECT(object)->flags = 0xC0u;
		OBJECT(object)->action = 0u;
	}
}
