/**
 *    Name:        objects/obstacles.c
 *    Description: the obstacles: raising the floor, picked up, thrown and broken
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Runs the cemetery obstacle's breaking by its substep. */
void cemetery_obstacle_broken_steps(uint16_t object, uint16_t *p_y, uint16_t *p_step_handlers, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t step_handlers = 0;
	uint8_t action_step = 0;

	for (;;)
	{
		step_handlers = cemetery_obstacle_broken_step_handlers_ADDRESS;
		action_step = OBJECT(object)->action_step;
		switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
		{
		case 0:
			cemetery_obstacle_break(object, &y, &step_handlers);
			break;
		case 2:
			cemetery_obstacle_vanish(object);
			break;
		case 4:
			cemetery_obstacle_food_fall(object);
			break;
		case -12:
		case -10:
			continue;
		case -8:
			cemetery_obstacle_start(object, &y, &step_handlers);
			break;
		case -6:
			cemetery_obstacle_raise_floor(object, &step_handlers, p_left_caller);
			break;
		case -4:
			step_handlers = cemetery_obstacle_wait_boss(object, step_handlers);
			break;
		case -2:
			cemetery_obstacle_idle();
			break;
		}
		break;
	}
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* Breaks the obstacle (sound 6C00), gives the floor back, and either jumps out as food or vanishes. */
void cemetery_obstacle_break(uint16_t object, uint16_t *p_child_record, uint16_t *p_u)
{
	uint32_t carry = 0;
	uint8_t parameter = 0;
	uint16_t child_record = 0, command = 0, ignored16 = 0, u = 0;
	uint8_t holds_food = 0, parameter_2 = 0, action_step = 0;

	child_record = cemetery_obstacle_break_child_ADDRESS;
	spawn_list_2_child(object, child_record, &ignored16, &carry);
	command = 0x6C00u;
	carry = vector_queue_sound(command);
	u = obstacle_restore_floor(object);
	holds_food = OBJECT(object)->cemetery_obstacle.holds_food;
	if (holds_food != 0u)
	{
		OBJECT(object)->z_speed = 0x800;
		OBJECT(object)->kind = 9u;
		parameter_2 = OBJECT(object)->parameter;
		parameter = (parameter_2 & 1u) << 1;
		OBJECT(object)->parameter = parameter;
		OBJECT(object)->animation = parameter | 0x80u;
		OBJECT(object)->action_step = 2u;
	}
	else
	{
		OBJECT(object)->timer = 0x10u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
	*p_child_record = child_record;
	*p_u = u;
}

/* Takes the broken obstacle away after 16 frames. */
void cemetery_obstacle_vanish(uint16_t object)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
		OBJECT(object)->flags = 0u;
}

/* Lets the food fall and, on landing, turns the object into food lying on the floor. */
void cemetery_obstacle_food_fall(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	if (carry)
	{
		OBJECT(object)->type = 0x27;
		OBJECT(object)->state = 0u;
	}
}

/* Sets a cemetery obstacle up at the x its spawn's state picks, deciding by the players' scores whether
   it holds food. */
void cemetery_obstacle_start(uint16_t object, uint16_t *p_box, uint16_t *p_x_table)
{
	uint16_t box = 0, setup = 0, x_table = 0;
	uint8_t parameter = 0, parameter_2 = 0, state = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	setup = cemetery_obstacle_setup_ADDRESS;
	box = vector_object_setup(object, setup);
	t1 = OBJECT(object)->y;
	t2 = t1 - 2u;
	OBJECT(object)->y = t2;
	OBJECT(object)->attributes = 0x10u;
	parameter = OBJECT(object)->parameter;
	OBJECT(object)->cemetery_obstacle.holds_food = TABLE8(cemetery_obstacle_food, (uint16_t)((uint8_t)((((((uint8_t)marge_score + (uint8_t)homer_score + (uint8_t)bart_score + (uint8_t)lisa_score) & 7u) << 1) << 1) << 1) + (int8_t)parameter));
	x_table = cemetery_obstacle_xs_ADDRESS;
	parameter_2 = OBJECT(object)->parameter;
	t3 = cemetery_obstacle_xs[(int8_t)((uint8_t)((uint32_t)parameter_2 << 1)) / 2];
	OBJECT(object)->x = t3;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	*p_box = box;
	*p_x_table = x_table;
}

/* Once on screen, raises the floor under it by 2 steps. */
void cemetery_obstacle_raise_floor(uint16_t object, uint16_t *p_floor_place, uint32_t *p_left_caller)
{
	uint16_t floor_place = (uint16_t)*p_floor_place;
	uint16_t raise_steps = 0, screen_x = 0;
	uint8_t state = 0;
	uint16_t t1 = 0;

	t1 = OBJECT(object)->x;
	screen_x = t1;
	if (screen_x < 0x160u)
	{
		raise_steps = (screen_x & 0xFFu) | 0x200u;
		obstacle_raise_floor(object, raise_steps, &floor_place, p_left_caller);
		if (*p_left_caller != 0u)
			*p_left_caller = 0u;
		else
		{
			state = OBJECT(object)->state;
			OBJECT(object)->state = state + 1u;
		}
	}
	*p_floor_place = floor_place;
}

/* Gives the floor back once the stage's boss is beaten. */
uint16_t cemetery_obstacle_wait_boss(uint16_t object, uint16_t u)
{
	uint16_t u_2 = 0;
	uint8_t state = 0;

	if (boss_beaten == 0u)
	{
		cemetery_obstacle_idle();
		return u;
	}
	u_2 = obstacle_restore_floor(object);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	cemetery_obstacle_idle();
	return u_2;
}

/* Does nothing. */
void cemetery_obstacle_idle(void)
{
}

/* Unused: sets up the obstacle (animation by its spawn's state) and raises the floor under it by 4
   steps. */
void heavy_obstacle_start(uint16_t object, uint16_t *p_box, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint8_t animation = 0, new_y = 0;
	uint16_t box = 0, raise_steps = 0, setup = 0, u = 0;
	uint8_t parameter = 0, state = 0;
	uint16_t t1 = 0, t2 = 0;

	setup = heavy_obstacle_setup_ADDRESS;
	box = vector_object_setup(object, setup);
	OBJECT(object)->attack = 0u;
	parameter = OBJECT(object)->parameter;
	animation = parameter | 0x80u;
	OBJECT(object)->animation = animation;
	OBJECT(object)->parameter = animation + 1u;
	t1 = OBJECT(object)->y;
	t2 = t1 - 2u;
	new_y = (uint8_t)t2;
	OBJECT(object)->y = ((uint32_t)(t2 >> 8) << 8) | (new_y & 0xFFu);
	raise_steps = (new_y & 0xFFu) | 0x400u;
	obstacle_raise_floor(object, raise_steps, &u, p_left_caller);
	if (*p_left_caller != 0u)
		*p_left_caller = 0u;
	else
	{
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
		heavy_obstacle_idle();
	}
	*p_box = box;
	*p_u = u;
}

/* Unused: does nothing while the obstacle stands. */
void heavy_obstacle_idle(void)
{
}

/* Unused: runs the obstacle's smashing by field 28. */
void heavy_obstacle_hit_steps(uint16_t object, uint16_t *p_y, uint16_t *p_action_handlers, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t action_handlers = 0;
	uint8_t action = 0;

	for (;;)
	{
		action_handlers = heavy_obstacle_hit_actions_ADDRESS;
		action = OBJECT(object)->action;
		switch ((int8_t)(uint8_t)((uint32_t)action << 1))
		{
		case 0:
			y = obstacle_smash(object);
			break;
		case 2:
			obstacle_smash_end(object);
			break;
		case 4:
			kind_10_riser_start(object, &y, &action_handlers);
			break;
		case 6:
			kind_10_riser_wait_boss(object);
			break;
		case 8:
			kind_10_riser_rise_slowly(object);
			break;
		case 10:
			kind_10_riser_rise_faster(object);
			break;
		case 12:
			kind_10_riser_stop(object);
			break;
		case 14:
			kind_10_riser_idle();
			break;
		case -30:
			obstacle_smashed_steps(object, &y, &action_handlers);
			break;
		case -28:
			obstacle_knocked_steps(object, &y, &action_handlers);
			break;
		case -26:
			heavy_obstacle_start(object, &y, &action_handlers, p_left_caller);
			break;
		case -24:
			heavy_obstacle_idle();
			break;
		case -22:
		case -20:
			continue;
		case -18:
			throwable_start(object, &y, &action_handlers);
			break;
		case -16:
			timed_throwable_wait(object);
			break;
		case -14:
			timed_throwable_idle();
			break;
		case -12:
			throwable_pick_up(object);
			break;
		case -10:
			y = timed_throwable_throw(object);
			break;
		case -8:
			throwable_hurt_enemies(object);
			break;
		case -6:
			throwable_rebound(object, &y, &action_handlers);
			break;
		case -4:
			y = timed_throwable_fall(object, y);
			break;
		case -2:
			timed_throwable_smash_end(object);
			break;
		}
		break;
	}
	*p_y = y;
	*p_action_handlers = action_handlers;
}

/* Turns the object into a smash (kind 9C, animation A2) with sound 6C00, hurting the enemies it touches. */
uint16_t obstacle_smash(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t box = 0, command = 0;
	uint8_t action = 0;

	command = 0x6C00u;
	carry = vector_queue_sound(command);
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->x_speed = 0;
	box = obstacle_smash_box_ADDRESS;
	vector_set_hit_box(object, box);
	OBJECT(object)->kind = 0x9Cu;
	OBJECT(object)->animation = 0xA2u;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
	check_hits_with_enemies(object);
	return box;
}

/* When the smash's animation ends, takes the object away. */
void obstacle_smash_end(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
		OBJECT(object)->flags = 0u;
}

/* Waits out field 3B, then starts falling. */
void timed_throwable_wait(uint16_t object)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
	{
		timed_throwable_idle();
		return;
	}
	OBJECT(object)->state = 7u;
	timed_throwable_idle();
}

/* Does nothing while it lies. */
void timed_throwable_idle(void)
{
}

/* Thrown: shows its flying animation and hurts the enemies it touches. */
uint16_t timed_throwable_throw(uint16_t object)
{
	uint16_t box = 0;
	uint8_t animation = 0, state = 0;

	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->timed_throwable.carried = 0u;
	animation = OBJECT(object)->animation;
	OBJECT(object)->animation = (animation + 1u) | 0x80u;
	box = timed_throwable_throw_box_ADDRESS;
	vector_set_hit_box(object, box);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	check_hits_with_enemies(object);
	return box;
}

/* Falls and, on landing, smashes (kind 9C, animation 8A) with sound 6C00. */
uint16_t timed_throwable_fall(uint16_t object, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t command = 0, ignored16 = 0;
	uint8_t state = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	if (carry == 0u)
		return y;
	command = 0x6C00u;
	carry = vector_queue_sound(command);
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->flags = 0xC0u;
	y = obstacle_smash_box_ADDRESS;
	vector_set_hit_box(object, y);
	OBJECT(object)->kind = 0x9Cu;
	OBJECT(object)->animation = 0x8Au;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return y;
}

/* Takes the smash away when its animation ends. */
void timed_throwable_smash_end(uint16_t object)
{
	uint8_t animation_flags = 0;

	OBJECT(object)->flags = 0x80u;
	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
		OBJECT(object)->flags = 0u;
}

/* While carried, drops when the carrier is knocked down. */
uint16_t carried_obstacle_held(uint16_t object)
{
	uint16_t carrier = 0;
	uint8_t state = 0;
	uint16_t parent = 0;

	parent = OBJECT(object)->parent;
	carrier = parent;
	state = OBJECT(carrier)->state;
	if (state == 4u)
	{
		OBJECT(object)->state = 0xFFu;
		OBJECT(object)->action = 0u;
	}
	return carrier;
}

/* Starts the obstacle's flight when thrown. */
void carried_obstacle_thrown(uint16_t object)
{
	uint8_t state = 0;

	OBJECT(object)->flags = 0xC8u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Breaks the flying obstacle (sound 6500) at a wall or a missing floor, else gives it the floor's
   priority. */
void carried_obstacle_check_floor(uint16_t object)
{
	uint32_t negative = 0, carry = 0;
	uint8_t flags = 0, floor_value = 0, value_ahead = 0;
	uint16_t command = 0, floor_cell = 0;
	uint8_t state = 0, attributes = 0;
	uint16_t z = 0, floor_z = 0, t1 = 0, z_2 = 0;

	if (OBJECT(object)->flags == 0u)
		return;
	state = OBJECT(object)->state;
	if ((int8_t)state < 0)
		return;
	floor_cell = 0u;
	vector_floor_at_offset(object, &floor_cell, &negative);
	floor_value = (uint8_t)(floor_cell >> 8);
	thrown_cell_here = floor_value;
	if ((int8_t)floor_value < 0)
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0;
		OBJECT(object)->state = 0xFEu;
		OBJECT(object)->flags = 0x80u;
		OBJECT(object)->action = 0u;
		command = 0x6500u;
		carry = vector_queue_sound(command);
		return;
	}
	OBJECT(object)->floor_z = (OBJECT(object)->floor_z & 0xFF00u) | ((((floor_value & 0xFu) << 1) << 1) << 1 & 0xFFu);
	z = OBJECT(object)->z;
	floor_z = OBJECT(object)->floor_z;
	if (z != floor_z)
		flags = OBJECT(object)->flags | 8u;
	else
		flags = OBJECT(object)->flags & ~8u;
	OBJECT(object)->flags = flags;
	vector_floor_ahead(object, &floor_cell, &negative);
	value_ahead = (uint8_t)(floor_cell >> 8);
	thrown_cell_ahead = value_ahead;
	if (value_ahead == thrown_cell_here)
		return;
	if ((int8_t)value_ahead < 0)
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0;
		OBJECT(object)->state = 0xFEu;
		OBJECT(object)->flags = 0x80u;
		OBJECT(object)->action = 0u;
		command = 0x6500u;
		carry = vector_queue_sound(command);
		return;
	}
	t1 = (thrown_cell_ahead & 0xFu) << 3;
	z_2 = OBJECT(object)->z;
	if (t1 < z_2)
	{
		thrown_cell_priority = thrown_cell_ahead & 0x30u;
		attributes = OBJECT(object)->attributes;
		OBJECT(object)->attributes = (attributes & 0xCFu) | thrown_cell_priority;
		return;
	}
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->state = 0xFEu;
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->action = 0u;
	command = 0x6500u;
	carry = vector_queue_sound(command);
}

/* Sets up the obstacle with the animation its spawn's state gives, facing as its carrier. */
void carried_obstacle_start(uint16_t object, uint16_t *p_box, uint16_t *p_carrier)
{
	uint8_t animation = 0;
	uint16_t box = 0, carrier = 0, setup = 0;
	uint8_t parameter = 0, attributes = 0, attributes_2 = 0, state = 0;
	uint16_t parent = 0;

	setup = carried_obstacle_setup_ADDRESS;
	box = vector_object_setup(object, setup);
	OBJECT(object)->flags = 0x80u;
	parameter = OBJECT(object)->parameter;
	animation = parameter | 0x80u;
	OBJECT(object)->animation = animation;
	OBJECT(object)->parameter = animation + 1u;
	parent = OBJECT(object)->parent;
	carrier = parent;
	attributes = OBJECT(carrier)->attributes;
	if ((attributes & 0x40u) != 0u)
	{
		attributes_2 = OBJECT(object)->attributes;
		OBJECT(object)->attributes = attributes_2 | 0x40u;
	}
	OBJECT(object)->timer = 8u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	*p_box = box;
	*p_carrier = carrier;
}

/* Runs the obstacle's breaking by field 28. */
void carried_obstacle_break_steps(uint16_t object, uint16_t *p_y, uint16_t *p_action_handlers)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t action_handlers = 0;
	uint8_t action = 0;

	action_handlers = carried_obstacle_break_actions_ADDRESS;
	action = OBJECT(object)->action;
	switch ((int8_t)(uint8_t)((uint32_t)action << 1))
	{
	case 0:
	case 6:
		obstacle_break(object);
		break;
	case 2:
	case 8:
		obstacle_break_end(object);
		break;
	case 4:
		obstacle_fall_and_break(object);
		break;
	case 10:
	case 12:
		throwable_stop_steps(object, &y, &action_handlers);
		break;
	case 14:
		throwable_start(object, &y, &action_handlers);
		break;
	case 16:
	case 18:
		throwable_lie();
		break;
	case 20:
		throwable_pick_up(object);
		break;
	case 22:
		y = throwable_throw(object);
		break;
	case 24:
		throwable_hurt_enemies(object);
		break;
	case 26:
		throwable_rebound(object, &y, &action_handlers);
		break;
	case 28:
		throwable_fall(object);
		break;
	case 30:
		throwable_stop(object);
		break;
	case 32:
		throwable_stop_end(object);
		break;
	}
	*p_y = y;
	*p_action_handlers = action_handlers;
}

/* Stops the object and starts its breaking animation. */
void obstacle_break(uint16_t object)
{
	uint8_t action = 0;

	OBJECT(object)->x_speed = 0;
	OBJECT(object)->z_speed = 0;
	OBJECT(object)->animation = 0x80u;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* Takes the object away when its breaking animation ends. */
void obstacle_break_end(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
		OBJECT(object)->flags = 0u;
}

/* Runs the dropped obstacle's fall and breaking by field 28. */
void carried_obstacle_drop_steps(uint16_t object, uint16_t *p_y, uint16_t *p_action_handlers)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t action_handlers = 0;
	uint8_t action = 0;

	action_handlers = carried_obstacle_drop_actions_ADDRESS;
	action = OBJECT(object)->action;
	switch ((int8_t)(uint8_t)((uint32_t)action << 1))
	{
	case 0:
		obstacle_fall_and_break(object);
		break;
	case -4:
	case 2:
		obstacle_break(object);
		break;
	case -2:
	case 4:
		obstacle_break_end(object);
		break;
	case 6:
	case 8:
		throwable_stop_steps(object, &y, &action_handlers);
		break;
	case 10:
		throwable_start(object, &y, &action_handlers);
		break;
	case 12:
	case 14:
		throwable_lie();
		break;
	case 16:
		throwable_pick_up(object);
		break;
	case 18:
		y = throwable_throw(object);
		break;
	case 20:
		throwable_hurt_enemies(object);
		break;
	case 22:
		throwable_rebound(object, &y, &action_handlers);
		break;
	case 24:
		throwable_fall(object);
		break;
	case 26:
		throwable_stop(object);
		break;
	case 28:
		throwable_stop_end(object);
		break;
	}
	*p_y = y;
	*p_action_handlers = action_handlers;
}

/* Falls and, on landing, plays sound 6500 and goes on to break. */
void obstacle_fall_and_break(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0, ignored16 = 0;
	uint8_t action = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	if (carry == 0u)
		return;
	command = 0x6500u;
	carry = vector_queue_sound(command);
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* While held, drops when the holder is hit. */
uint16_t tossed_obstacle_held(uint16_t object)
{
	uint16_t holder = 0;
	uint8_t state = 0;
	uint16_t parent = 0;

	parent = OBJECT(object)->parent;
	holder = parent;
	state = OBJECT(holder)->state;
	if ((int8_t)state < 0)
	{
		OBJECT(object)->state = 0xFFu;
		OBJECT(object)->action = 0u;
	}
	return holder;
}

/* After 8 frames, is tossed to the left. */
void tossed_obstacle_toss(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->flags = 0xC8u;
		OBJECT(object)->x_speed = -0x300;
		OBJECT(object)->z_speed = 0x300;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Puts out the flying obstacle's hit box (stronger with 3 or more players) and its flying animation. */
uint16_t carried_obstacle_fly(uint16_t object)
{
	uint16_t box = 0;
	uint8_t parameter = 0, state = 0;

	box = carried_obstacle_fly_box_ADDRESS;
	vector_set_hit_box(object, box);
	if (player_count >= 3u)
		OBJECT(object)->damage = 0x10u;
	parameter = OBJECT(object)->parameter;
	OBJECT(object)->animation = parameter | 0x80u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	face_movement(object);
	return box;
}

/* Falls and, on landing, bounces up again with sound 6500. */
void carried_obstacle_bounce(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0, ignored16 = 0;
	uint8_t state = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	if (carry == 0u)
		return;
	OBJECT(object)->z_speed = 0x500;
	OBJECT(object)->flags |= 8u;
	command = 0x6500u;
	carry = vector_queue_sound(command);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Falls and lands again with sound 6500. */
void carried_obstacle_land(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0, ignored16 = 0;
	uint8_t state = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	if (carry == 0u)
		return;
	command = 0x6500u;
	carry = vector_queue_sound(command);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Slides along the floor, falling again off an edge, and breaks once it stops. */
void carried_obstacle_slide(uint16_t object)
{
	uint8_t state = 0;
	uint16_t z = 0, floor_z = 0, x_speed = 0;

	z = OBJECT(object)->z;
	floor_z = OBJECT(object)->floor_z;
	if (z != floor_z)
	{
		state = OBJECT(object)->state;
		OBJECT(object)->state = state - 1u;
		OBJECT(object)->flags |= 8u;
	}
	x_speed = OBJECT(object)->x_speed;
	if (x_speed == 0u)
	{
		OBJECT(object)->state = 0xFEu;
		OBJECT(object)->action = 0u;
		OBJECT(object)->flags = 0x80u;
	}
}

/* Stops a thrown object in flight when something hits it. */
void throwable_check_hit(uint16_t object)
{
	uint8_t state = 0;

	state = OBJECT(object)->state;
	if (state == 5u && (OBJECT(object)->flags & 0x20u) != 0u)
	{
		OBJECT(object)->state = 0xFFu;
		OBJECT(object)->action = 0u;
	}
}

/* Runs a throwable's end by field 28. */
void throwable_stop_steps(uint16_t object, uint16_t *p_y, uint16_t *p_action_handlers)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t action_handlers = 0;
	uint8_t action = 0;

	for (;;)
	{
		action_handlers = throwable_stop_actions_ADDRESS;
		action = OBJECT(object)->action;
		switch ((int8_t)(uint8_t)((uint32_t)action << 1))
		{
		case 0:
			throwable_stop(object);
			break;
		case 2:
			throwable_stop_end(object);
			break;
		case -30:
		case -24:
			obstacle_break(object);
			break;
		case -28:
		case -22:
			obstacle_break_end(object);
			break;
		case -26:
			obstacle_fall_and_break(object);
			break;
		case -20:
		case -18:
			continue;
		case -16:
			throwable_start(object, &y, &action_handlers);
			break;
		case -14:
		case -12:
			throwable_lie();
			break;
		case -10:
			throwable_pick_up(object);
			break;
		case -8:
			y = throwable_throw(object);
			break;
		case -6:
			throwable_hurt_enemies(object);
			break;
		case -4:
			throwable_rebound(object, &y, &action_handlers);
			break;
		case -2:
			throwable_fall(object);
			break;
		}
		break;
	}
	*p_y = y;
	*p_action_handlers = action_handlers;
}

/* Stops the throwable with a little hop and starts its end animation. */
void throwable_stop(uint16_t object)
{
	uint8_t action = 0;

	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->z_speed = 0x80;
	OBJECT(object)->animation = 0x80u;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* Takes the throwable away when its end animation ends. */
void throwable_stop_end(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
		OBJECT(object)->flags = 0u;
}

/* Sets up a throwable with the animation its spawn's state gives. */
void throwable_start(uint16_t object, uint16_t *p_box, uint16_t *p_setup)
{
	uint16_t box = 0, setup = 0;
	uint8_t parameter = 0, blocked = 0, state = 0;

	setup = throwable_setup_ADDRESS;
	box = vector_object_setup(object, setup);
	OBJECT(object)->shadow_player = 2u;
	parameter = OBJECT(object)->parameter;
	OBJECT(object)->animation = parameter | 0x80u;
	blocked = OBJECT(object)->blocked;
	OBJECT(object)->blocked = blocked + 1u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	*p_box = box;
	*p_setup = setup;
}

/* Does nothing while the throwable lies or is carried. */
void throwable_lie(void)
{
}

/* Picked up: marks it carried. */
void throwable_pick_up(uint16_t object)
{
	uint8_t state = 0;

	OBJECT(object)->blocked = 0u;
	OBJECT(object)->throwable.carried = 1u;
	OBJECT(object)->flags = 0x80u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state - 1u;
}

/* Thrown: shows its flying animation with its hit box, facing its way. */
uint16_t throwable_throw(uint16_t object)
{
	uint16_t box = 0;
	uint8_t animation = 0, state = 0;

	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->throwable.carried = 0u;
	animation = OBJECT(object)->animation;
	OBJECT(object)->animation = (animation + 1u) | 0x80u;
	box = throwable_throw_box_ADDRESS;
	vector_set_hit_box(object, box);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	face_movement(object);
	throwable_hurt_enemies(object);
	return box;
}

/* Hurts the enemies the flying throwable touches. */
void throwable_hurt_enemies(uint16_t object)
{
	check_hits_with_enemies(object);
}

/* Bounces the throwable up and back after it hits something. */
void throwable_rebound(uint16_t object, uint16_t *p_box, uint16_t *p_thrower)
{
	uint32_t negative = 0;
	uint8_t floor_value = 0;
	uint16_t box = 0, floor_cell = 0, thrower = 0;
	uint8_t attributes = 0, animation = 0, state = 0;
	uint16_t parent = 0, x_speed = 0;

	OBJECT(object)->flags = 0x88u;
	box = throwable_rebound_box_ADDRESS;
	vector_set_hit_box(object, box);
	OBJECT(object)->z_speed = 0x600;
	OBJECT(object)->x_speed = 0x100;
	parent = OBJECT(object)->parent;
	thrower = parent;
	attributes = OBJECT(thrower)->attributes;
	if ((attributes & 0x40u) == 0u)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	floor_cell = 0u;
	vector_floor_at_offset(object, &floor_cell, &negative);
	floor_value = (uint8_t)(floor_cell >> 8);
	OBJECT(object)->floor_z = (OBJECT(object)->floor_z & 0xFF00u) | ((((floor_value & 0xFu) << 1) << 1) << 1 & 0xFFu);
	animation = OBJECT(object)->animation;
	OBJECT(object)->animation = (animation + 1u) | 0x80u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	*p_box = box;
	*p_thrower = thrower;
}

/* Falls back to the floor, hurting enemies on the way up, then ends. */
void throwable_fall(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;
	uint16_t z_speed = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	if (carry)
	{
		OBJECT(object)->state = 0xFFu;
		OBJECT(object)->action = 0u;
		return;
	}
	z_speed = OBJECT(object)->z_speed;
	if ((int16_t)z_speed < 0)
	{
		check_hits_with_enemies(object);
		return;
	}
}

/* Keeps a throwable on its floor (or its carrier's priority while carried), ending it when it goes off
   an edge. */
uint16_t throwable_follow_floor(uint16_t object, uint16_t states)
{
	uint32_t negative = 0;
	uint8_t flags = 0, floor_value = 0, value_ahead = 0;
	uint16_t carrier = 0, floor_cell = 0;
	uint8_t blocked = 0, carried = 0, attributes = 0, attributes_2 = 0, attributes_3 = 0;
	uint16_t parent = 0, z = 0, floor_z = 0, t1 = 0, z_2 = 0;

	if (OBJECT(object)->flags == 0u)
		return states;
	blocked = OBJECT(object)->blocked;
	if (blocked != 0u)
		return states;
	carried = OBJECT(object)->throwable.carried;
	if (carried != 0u)
	{
		parent = OBJECT(object)->parent;
		carrier = parent;
		attributes = OBJECT(carrier)->attributes;
		thrown_cell_here = attributes & 0x30u;
		attributes_2 = OBJECT(object)->attributes;
		OBJECT(object)->attributes = (attributes_2 & 0xCFu) | thrown_cell_here;
		return carrier;
	}
	floor_cell = 0u;
	vector_floor_at_offset(object, &floor_cell, &negative);
	floor_value = (uint8_t)(floor_cell >> 8);
	thrown_cell_here = floor_value;
	if ((int8_t)floor_value < 0)
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->state = 0xFEu;
		return states;
	}
	OBJECT(object)->floor_z = (OBJECT(object)->floor_z & 0xFF00u) | ((((floor_value & 0xFu) << 1) << 1) << 1 & 0xFFu);
	z = OBJECT(object)->z;
	floor_z = OBJECT(object)->floor_z;
	if (z != floor_z)
		flags = OBJECT(object)->flags | 8u;
	else
		flags = OBJECT(object)->flags & ~8u;
	OBJECT(object)->flags = flags;
	vector_floor_ahead(object, &floor_cell, &negative);
	value_ahead = (uint8_t)(floor_cell >> 8);
	thrown_cell_ahead = value_ahead;
	if (value_ahead == thrown_cell_here)
		return states;
	if ((int8_t)value_ahead >= 0)
	{
		t1 = (thrown_cell_ahead & 0xFu) << 3;
		z_2 = OBJECT(object)->z;
		if (t1 < z_2)
		{
			thrown_cell_priority = thrown_cell_ahead & 0x30u;
			attributes_3 = OBJECT(object)->attributes;
			OBJECT(object)->attributes = (attributes_3 & 0xCFu) | thrown_cell_priority;
			return states;
		}
	}
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->state = 0xFEu;
	return states;
}

/* Sets an obstacle up by its spawn's state and, once on screen, raises the floor under it by its height. */
void obstacle_start(uint16_t object, uint16_t *p_box, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t box = (uint16_t)*p_box;
	uint16_t u = (uint16_t)*p_u;
	uint8_t animation = 0, new_y = 0;
	uint16_t raise_steps = 0, setup = 0;
	uint8_t action = 0, height = 0, state = 0, parameter = 0, parameter_2 = 0, carried = 0, action_2 = 0, floor_raised = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	action = OBJECT(object)->action;
	if (action != 0u)
	{
		t1 = OBJECT(object)->x;
		if (t1 < 0x180u)
		{
			t2 = OBJECT(object)->y;
			t3 = t2 - 2u;
			new_y = (uint8_t)t3;
			OBJECT(object)->y = ((uint32_t)(t3 >> 8) << 8) | (new_y & 0xFFu);
			OBJECT(object)->animation_flags = 0x80u;
			height = OBJECT(object)->obstacle.height;
			raise_steps = (new_y & 0xFFu) | ((uint32_t)height << 8);
			obstacle_raise_floor(object, raise_steps, &u, p_left_caller);
			if (*p_left_caller != 0u)
				*p_left_caller = 0u;
			else
			{
				state = OBJECT(object)->state;
				OBJECT(object)->state = state + 1u;
			}
		}
	}
	else
	{
		setup = heavy_obstacle_setup_ADDRESS;
		box = vector_object_setup(object, setup);
		u = obstacle_heights_ADDRESS;
		parameter = OBJECT(object)->parameter;
		OBJECT(object)->obstacle.height = obstacle_heights[parameter >> 1];
		parameter_2 = OBJECT(object)->parameter;
		animation = parameter_2 | 0x80u;
		OBJECT(object)->animation = animation;
		OBJECT(object)->parameter = animation + 1u;
		carried = OBJECT(object)->obstacle.carried;
		if (carried != 0u)
		{
			state = OBJECT(object)->state;
			OBJECT(object)->state = state + 1u;
		}
		else
		{
			action_2 = OBJECT(object)->action;
			OBJECT(object)->action = action_2 + 1u;
			floor_raised = OBJECT(object)->obstacle.floor_raised;
			OBJECT(object)->obstacle.floor_raised = floor_raised + 1u;
		}
	}
	*p_box = box;
	*p_u = u;
}

/* Runs the obstacle's smashing by its substep. */
void obstacle_smashed_steps(uint16_t object, uint16_t *p_y, uint16_t *p_step_handlers)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t step_handlers = 0;
	uint8_t action_step = 0;

	step_handlers = obstacle_smashed_step_handlers_ADDRESS;
	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		step_handlers = obstacle_smashed(object, step_handlers);
		break;
	case 2:
		obstacle_smashed_end(object);
		break;
	case 4:
		obstacle_knocked(object, &y, &step_handlers);
		break;
	case 6:
		obstacle_knocked_fall(object);
		break;
	case 8:
		solid_scenery_start(object, &y, &step_handlers);
		break;
	case 10:
		solid_scenery_idle();
		break;
	}
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* Smashes the obstacle (sound 6C00), giving the floor back, and starts its breaking animation. */
uint16_t obstacle_smashed(uint16_t object, uint16_t u)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t floor_raised = 0, action_step = 0;

	command = 0x6C00u;
	carry = vector_queue_sound(command);
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->z_speed = 0;
	floor_raised = OBJECT(object)->obstacle.floor_raised;
	if (floor_raised != 0u)
		u = obstacle_restore_floor(object);
	OBJECT(object)->animation = 0x80u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	return u;
}

/* Takes the smashed obstacle away when its animation ends. */
void obstacle_smashed_end(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
		OBJECT(object)->flags = 0u;
}

/* Runs the knocked obstacle by field 28, hurting the enemies it touches. */
void obstacle_knocked_steps(uint16_t object, uint16_t *p_y, uint16_t *p_action_handlers)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t action_handlers = 0;
	uint8_t action = 0;

	action_handlers = obstacle_knocked_actions_ADDRESS;
	action = OBJECT(object)->action;
	switch ((int8_t)(uint8_t)((uint32_t)action << 1))
	{
	case 0:
		obstacle_knocked(object, &y, &action_handlers);
		break;
	case 2:
		obstacle_knocked_fall(object);
		break;
	case 4:
		solid_scenery_start(object, &y, &action_handlers);
		break;
	case 6:
		solid_scenery_idle();
		break;
	case -4:
		action_handlers = obstacle_smashed(object, action_handlers);
		break;
	case -2:
		obstacle_smashed_end(object);
		break;
	}
	check_hits_with_enemies(object);
	*p_y = y;
	*p_action_handlers = action_handlers;
}

/* Sends the obstacle sliding away from what hit it, with its hit box. */
void obstacle_knocked(uint16_t object, uint16_t *p_box, uint16_t *p_hitter)
{
	uint16_t box = 0, hitter = 0;
	uint8_t floor_raised = 0, parameter = 0, action = 0;
	uint16_t hit_by = 0, t1 = 0, t2 = 0, x_speed = 0;

	floor_raised = OBJECT(object)->obstacle.floor_raised;
	if (floor_raised != 0u)
		obstacle_restore_floor(object);
	OBJECT(object)->flags = 0x80u;
	box = obstacle_knocked_box_ADDRESS;
	vector_set_hit_box(object, box);
	parameter = OBJECT(object)->parameter;
	OBJECT(object)->animation = parameter | 0x80u;
	OBJECT(object)->x_speed = 0x400;
	hit_by = OBJECT(object)->hit_by;
	hitter = hit_by;
	t1 = OBJECT(hitter)->x;
	t2 = OBJECT(object)->x;
	if (t2 <= t1)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	OBJECT(object)->action_step = 0u;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
	*p_box = box;
	*p_hitter = hitter;
}

/* Falls while sliding, hurting the enemies it touches. */
void obstacle_knocked_fall(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	check_hits_with_enemies(object);
}

/* Raises the 3 floor cells under the object by A steps; if they differ or would overflow, the object
   breaks instead. */
void obstacle_raise_floor(uint16_t object, uint16_t raise_steps, uint16_t *p_floor_place, uint32_t *p_left_caller)
{
	uint8_t column = 0, control = 0, floor_column = 0, old_cell = 0, raised_cell = 0;
	uint16_t floor_cell = 0, floor_place = 0;
	uint32_t left_caller = 0;
	uint8_t stack = 0, stack_2 = 0;
	uint8_t floor_column_2 = 0, floor_cell_2 = 0, t1 = 0, floor_cell_3 = 0, t2 = 0, floor_cell_4 = 0, t3 = 0, t4 = 0, floor_raised = 0;
	uint16_t floor_row = 0, floor_row_2 = 0;

	io_write8(0x188Bu, raise_steps >> 8);
	floor_cell_under(object, &floor_place, &floor_cell);
	old_cell = (uint8_t)(floor_cell >> 8);
	stack = old_cell;
	control = board_control | 2u;
	board_control = control;
	io_write8(0x1FC2u, control);
	OBJECT(object)->obstacle.floor_cell = stack;
	stack_2 = floor_place >> 8;
	stack = (uint8_t)floor_place;
	floor_column = stack;
	OBJECT(object)->obstacle.floor_column = floor_column;
	OBJECT(object)->obstacle.floor_row = ((uint32_t)stack_2 << 8) | (floor_column & 0xC0u);
	floor_columns_left = 3u;
	floor_column_2 = OBJECT(object)->obstacle.floor_column;
	column = floor_column_2 - 1u;
	floor_raise_steps = column;
	for (;;)
	{
		floor_row = OBJECT(object)->obstacle.floor_row;
		column &= 0x3Fu;
		floor_place = floor_row + column;
		floor_cell_2 = OBJECT(object)->obstacle.floor_cell;
		if (mem_read8(floor_place) != floor_cell_2)
		{
			OBJECT(object)->state = 0xFEu;
			control = board_control & ~3u;
			board_control = control;
			io_write8(0x1FC2u, control);
			left_caller = 1u;
			break;
		}
		t1 = mem_read8(floor_place + 0x40u);
		floor_cell_3 = OBJECT(object)->obstacle.floor_cell;
		if (t1 != floor_cell_3)
		{
			OBJECT(object)->state = 0xFEu;
			control = board_control & ~3u;
			board_control = control;
			io_write8(0x1FC2u, control);
			left_caller = 1u;
			break;
		}
		column++;
		t2 = floor_columns_left;
		floor_columns_left = t2 - 1u;
		if (t2 != 1u)
			continue;
		floor_columns_left = 3u;
		column = floor_raise_steps;
		floor_cell_4 = OBJECT(object)->obstacle.floor_cell;
		t3 = io_read8(0x188Bu);
		raised_cell = (floor_cell_4 & 0xFu) + t3;
		if (raised_cell >= 0x10u)
		{
			OBJECT(object)->state = 0xFEu;
			control = board_control & ~3u;
			board_control = control;
			io_write8(0x1FC2u, control);
			left_caller = 1u;
			break;
		}
		do
		{
			floor_row_2 = OBJECT(object)->obstacle.floor_row;
			column &= 0x3Fu;
			floor_place = floor_row_2 + column;
			mem_write8(floor_place, raised_cell);
			column++;
			t4 = floor_columns_left;
			floor_columns_left = t4 - 1u;
		} while (t4 != 1u);
		control = board_control & ~3u;
		board_control = control;
		io_write8(0x1FC2u, control);
		floor_raised = OBJECT(object)->obstacle.floor_raised;
		OBJECT(object)->obstacle.floor_raised = floor_raised + 1u;
		left_caller = 0u;
		break;
	}
	*p_floor_place = floor_place;
	*p_left_caller = left_caller;
}

/* Gives the 3 floor cells under the object their old value back. */
uint16_t obstacle_restore_floor(uint16_t object)
{
	uint8_t column = 0, control = 0, old_cell = 0;
	uint16_t floor_place = 0;
	uint8_t floor_column = 0, floor_cell = 0, t1 = 0;
	uint16_t floor_row = 0;

	control = board_control | 2u;
	board_control = control;
	io_write8(0x1FC2u, control);
	floor_column = OBJECT(object)->obstacle.floor_column;
	column = floor_column - 1u;
	floor_columns_left = 3u;
	floor_cell = OBJECT(object)->obstacle.floor_cell;
	old_cell = floor_cell;
	do
	{
		floor_row = OBJECT(object)->obstacle.floor_row;
		column &= 0x3Fu;
		floor_place = floor_row + column;
		mem_write8(floor_place, old_cell);
		column++;
		t1 = floor_columns_left;
		floor_columns_left = t1 - 1u;
	} while (t1 != 1u);
	OBJECT(object)->obstacle.floor_raised = 0u;
	control = board_control & ~3u;
	board_control = control;
	io_write8(0x1FC2u, control);
	return floor_place;
}

/* Gives the obstacle its standing hit box, raising the floor first if needed. */
void obstacle_settle(uint16_t object, uint16_t *p_box, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t box = (uint16_t)*p_box;
	uint16_t u = (uint16_t)*p_u;
	uint16_t raise_steps = 0;
	uint8_t carried = 0, state = 0, action = 0;

	carried = OBJECT(object)->obstacle.carried;
	if (carried != 0u)
	{
		box = obstacle_settle_box_ADDRESS;
		vector_set_hit_box(object, box);
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
		obstacle_lie();
	}
	else
	{
		action = OBJECT(object)->action;
		if (action != 0u)
		{
			box = obstacle_settle_box_ADDRESS;
			vector_set_hit_box(object, box);
			state = OBJECT(object)->state;
			OBJECT(object)->state = state + 1u;
			obstacle_lie();
		}
		else
		{
			raise_steps = 0x400u;
			obstacle_raise_floor(object, raise_steps, &u, p_left_caller);
			if (*p_left_caller != 0u)
				*p_left_caller = 0u;
			else
			{
				box = obstacle_settle_box_ADDRESS;
				vector_set_hit_box(object, box);
				state = OBJECT(object)->state;
				OBJECT(object)->state = state + 1u;
				obstacle_lie();
			}
		}
	}
	*p_box = box;
	*p_u = u;
}

/* Does nothing while the obstacle stands. */
void obstacle_lie(void)
{
}

/* Picked up: gives the floor under it back. */
uint16_t obstacle_pick_up(uint16_t object)
{
	uint16_t u = 0;
	uint8_t state = 0;

	OBJECT(object)->flags = 0x80u;
	u = obstacle_restore_floor(object);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state - 1u;
	return u;
}

/* Thrown: puts out its hit box (or, already on the floor, smashes). */
uint16_t obstacle_throw(uint16_t object, uint16_t y)
{
	uint32_t negative = 0;
	uint8_t floor_value = 0;
	uint16_t box = 0, floor_cell = 0;
	uint8_t t1 = 0, state = 0;

	OBJECT(object)->flags = 0x80u;
	floor_cell = 0u;
	vector_floor_at_offset(object, &floor_cell, &negative);
	floor_value = (uint8_t)(floor_cell >> 8);
	t1 = (uint8_t)OBJECT(object)->z;
	if (t1 <= (uint8_t)((((floor_value & 0xFu) << 1) << 1) << 1))
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->state = 0xFEu;
		return y;
	}
	box = obstacle_knocked_box_ADDRESS;
	vector_set_hit_box(object, box);
	OBJECT(object)->obstacle.carried = 0u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	check_hits_with_enemies(object);
	return box;
}

/* Flies until it lands, then bounces once more. */
void obstacle_fly(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;
	uint8_t parameter = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	if (carry)
	{
		OBJECT(object)->z_speed = 0x400;
		parameter = OBJECT(object)->parameter;
		OBJECT(object)->animation = parameter | 0x80u;
		OBJECT(object)->state = 0xFFu;
		OBJECT(object)->action = 1u;
	}
	check_hits_with_enemies(object);
}

/* Bounces the thrown obstacle up and back after it hits something. */
uint16_t obstacle_rebound(uint16_t object)
{
	uint16_t thrower = 0;
	uint8_t attributes = 0, state = 0;
	uint16_t parent = 0, x_speed = 0;

	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->obstacle.carried = 0u;
	OBJECT(object)->z_speed = 0x600;
	OBJECT(object)->x_speed = 0x100;
	parent = OBJECT(object)->parent;
	thrower = parent;
	attributes = OBJECT(thrower)->attributes;
	if ((attributes & 0x40u) == 0u)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return thrower;
}

/* Rises after the rebound; when it starts falling, puts its hit box back out. */
uint16_t obstacle_rebound_rise(uint16_t object, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t box = 0, ignored16 = 0;
	uint8_t state = 0;
	uint16_t z_speed = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	z_speed = OBJECT(object)->z_speed;
	if ((int16_t)z_speed >= 0)
		return y;
	box = obstacle_knocked_box_ADDRESS;
	vector_set_hit_box(object, box);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	check_hits_with_enemies(object);
	return box;
}

/* Falls and, on landing, bounces on the way it was going. */
void obstacle_rebound_fall(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;
	uint8_t x_speed = 0, parameter = 0;
	uint16_t x_speed_2 = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	if (carry == 0u)
	{
		check_hits_with_enemies(object);
		return;
	}
	x_speed = (uint8_t)(OBJECT(object)->x_speed >> 8u);
	rebound_x_speed_high = x_speed;
	OBJECT(object)->x_speed = 0x400;
	if (rebound_x_speed_high < 0)
	{
		x_speed_2 = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed_2;
	}
	OBJECT(object)->z_speed = 0x400;
	parameter = OBJECT(object)->parameter;
	OBJECT(object)->animation = parameter | 0x80u;
	OBJECT(object)->state = 0xFFu;
	OBJECT(object)->action = 1u;
	check_hits_with_enemies(object);
}

/* Unused: clears field 3D and falls; the next state once it lands. */
void unused_obstacle_fall(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;
	uint8_t state = 0;

	OBJECT(object)->unk_3D = 0u;
	vector_apply_gravity(object, &ignored16, &carry);
	if (carry)
	{
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Unused: falls; the next state once it lands. */
void unused_obstacle_keep_falling(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;
	uint8_t state = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	if (carry)
	{
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Unused: takes animation 80 and the next state. */
void unused_obstacle_show_animation_80(uint16_t object)
{
	uint8_t state = 0;

	OBJECT(object)->animation = 0x80u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Unused: removes the object when its animation ends. */
void unused_obstacle_vanish_at_animation_end(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
		OBJECT(object)->flags = 0u;
}

/* Sets up the throwable that bounces once. */
void bouncing_throwable_start(uint16_t object, uint16_t *p_box, uint16_t *p_setup)
{
	uint16_t box = 0, setup = 0;
	uint8_t blocked = 0, state = 0;

	setup = bouncing_throwable_setup_ADDRESS;
	box = vector_object_setup(object, setup);
	OBJECT(object)->bouncing_throwable.flight_count = 1u;
	blocked = OBJECT(object)->blocked;
	OBJECT(object)->blocked = blocked + 1u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	bouncing_throwable_lie();
	*p_box = box;
	*p_setup = setup;
}

/* Does nothing while it lies or is carried. */
void bouncing_throwable_lie(void)
{
}

/* Picked up: marks it carried (hidden for field 58's 2). */
void bouncing_throwable_pick_up(uint16_t object)
{
	uint8_t carrier_kind = 0, state = 0;

	OBJECT(object)->blocked = 0u;
	OBJECT(object)->bouncing_throwable.carried = 1u;
	OBJECT(object)->flags = 0x80u;
	carrier_kind = OBJECT(object)->bouncing_throwable.carrier_kind;
	if (carrier_kind == 2u)
		OBJECT(object)->flags = 4u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state - 1u;
}

/* Thrown: shows its flying animation with its hit box. */
uint16_t bouncing_throwable_throw(uint16_t object)
{
	uint16_t box = 0;
	uint8_t animation = 0, state = 0;

	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->bouncing_throwable.carried = 0u;
	animation = OBJECT(object)->animation;
	OBJECT(object)->animation = (animation + 1u) | 0x80u;
	box = bouncing_throwable_throw_box_ADDRESS;
	vector_set_hit_box(object, box);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	face_movement(object);
	check_hits_with_enemies(object);
	return box;
}

/* Flies, bouncing once on landing, hurting the enemies it touches. */
void bouncing_throwable_fly(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;
	uint8_t flight_count = 0, flight_count_2 = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	if (carry)
	{
		flight_count = OBJECT(object)->bouncing_throwable.flight_count;
		if (flight_count != 0u)
		{
			flight_count_2 = OBJECT(object)->bouncing_throwable.flight_count;
			OBJECT(object)->bouncing_throwable.flight_count = flight_count_2 - 1u;
			OBJECT(object)->z_speed = 0x200;
			OBJECT(object)->flags = 0x88u;
		}
	}
	check_hits_with_enemies(object);
}

/* Sets up a hidden Dreamland obstacle: its animation, its wait and its x. */
void dreamland_obstacle_start(uint16_t object, uint16_t *p_box, uint16_t *p_obstacle_drop)
{
	uint8_t drop_animation = 0;
	uint16_t box = 0, obstacle_drop = 0, setup = 0;
	uint8_t parameter = 0, blocked = 0, state = 0;
	uint16_t animation = 0, t1 = 0;

	setup = dreamland_obstacle_setup_ADDRESS;
	box = vector_object_setup(object, setup);
	OBJECT(object)->flags = 4u;
	OBJECT(object)->floor_z = 0u;
	OBJECT(object)->attributes = 0x10u;
	parameter = OBJECT(object)->parameter;
	obstacle_drop = dreamland_obstacle_drops_ADDRESS + (int8_t)(((uint32_t)parameter << 1) << 1);
	animation = (((uint32_t)OBSTACLE_DROP(obstacle_drop)->animation << 8u) | OBSTACLE_DROP(obstacle_drop)->wait);
	drop_animation = (uint8_t)(animation >> 8);
	OBJECT(object)->animation = drop_animation;
	OBJECT(object)->dreamland_obstacle.drop_animation = drop_animation;
	OBJECT(object)->parameter = drop_animation;
	OBJECT(object)->timer = animation;
	t1 = OBSTACLE_DROP(obstacle_drop)->x;
	OBJECT(object)->x = t1;
	blocked = OBJECT(object)->blocked;
	OBJECT(object)->blocked = blocked + 1u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	dreamland_obstacle_idle();
	*p_box = box;
	*p_obstacle_drop = obstacle_drop;
}

/* Does nothing while it lies. */
void dreamland_obstacle_idle(void)
{
}

/* Runs the obstacle's throw-in by its substep. */
void dreamland_obstacle_drop_steps(uint16_t object, uint16_t *p_y, uint16_t *p_step_handlers)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t step_handlers = 0;
	uint8_t action_step = 0;

	step_handlers = dreamland_obstacle_drop_step_handlers_ADDRESS;
	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		dreamland_obstacle_throw_in(object);
		break;
	case 2:
		dreamland_obstacle_land(object);
		break;
	case 4:
		y = dreamland_obstacle_settle(object, y);
		break;
	}
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* After its wait, is thrown in with sound 0301. */
void dreamland_obstacle_throw_in(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t timer = 0, action_step = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	command = 0x301u;
	carry = vector_queue_sound(command);
	OBJECT(object)->flags = 0xC8u;
	OBJECT(object)->x_speed = 0x300;
	OBJECT(object)->z_speed = -0x100;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Lands with sound 2000 and stops. */
void dreamland_obstacle_land(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0, ignored16 = 0;
	uint8_t drop_animation = 0, action_step = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	if (carry == 0u)
		return;
	drop_animation = OBJECT(object)->dreamland_obstacle.drop_animation;
	OBJECT(object)->animation = drop_animation + 1u;
	command = 0x2000u;
	carry = vector_queue_sound(command);
	OBJECT(object)->x_speed = 0;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* When its landing animation ends, stands as an obstacle to pick up. */
uint16_t dreamland_obstacle_settle(uint16_t object, uint16_t y)
{
	uint8_t animation_flags = 0, drop_animation = 0;

	OBJECT(object)->flags = 0x80u;
	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return y;
	drop_animation = OBJECT(object)->dreamland_obstacle.drop_animation;
	OBJECT(object)->animation = drop_animation + 2u;
	OBJECT(object)->flags = 0xC0u;
	y = obstacle_settle_box_ADDRESS;
	vector_set_hit_box(object, y);
	OBJECT(object)->action = 0u;
	OBJECT(object)->action_step = 0u;
	OBJECT(object)->state = 2u;
	return y;
}

/* Picked up: shows its first animation again. */
void dreamland_obstacle_pick_up(uint16_t object)
{
	uint8_t drop_animation = 0, state = 0;

	OBJECT(object)->flags = 0x80u;
	drop_animation = OBJECT(object)->dreamland_obstacle.drop_animation;
	OBJECT(object)->animation = drop_animation;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state - 1u;
}
