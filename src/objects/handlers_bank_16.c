/**
 *    Name:        objects/handlers_bank_16.c
 *    Description: bank 16's object handlers by type, as the object lists' dispatchers reach them
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Runs a piece of stage 1's scenery that no one can walk into, gone once off screen. */
void solid_scenery_update(uint16_t object, uint8_t state, uint16_t *p_y, uint16_t *p_states)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t states = 0;
	uint16_t t1 = 0;

	state_2 = (uint8_t)state;
	states = solid_scenery_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		solid_scenery_start(object, &y, &states);
		break;
	case 2:
		solid_scenery_idle();
		break;
	case -8:
		states = obstacle_smashed(object, states);
		break;
	case -6:
		obstacle_smashed_end(object);
		break;
	case -4:
		obstacle_knocked(object, &y, &states);
		break;
	case -2:
		obstacle_knocked_fall(object);
		break;
	}
	t1 = OBJECT(object)->x;
	if (t1 >= 0x1F0u)
		OBJECT(object)->flags = 0u;
	*p_y = y;
	*p_states = states;
}

/* Runs a door of the police car, which lets goons out once the car has stopped. */
void police_car_door_update(uint16_t object, uint8_t state, uint16_t *p_y, uint16_t *p_states)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = police_car_door_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		police_car_door_start(object, &y, &states);
		break;
	case 2:
		police_car_door_wait_car(object);
		break;
	case 4:
		police_car_door_open(object, &y, &states);
		break;
	case 6:
		police_car_door_vanish(object);
		break;
	case 8:
		police_car_door_idle();
		break;
	}
	carry = remove_off_screen(object, carry);
	*p_y = y;
	*p_states = states;
}

/* Runs the obstacle a fat goon carries and throws: carried, thrown, bouncing and breaking. */
void carried_obstacle_update(uint16_t object, uint8_t state, uint16_t *p_y, uint16_t *p_states)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t states = 0;
	uint16_t t1 = 0, t2 = 0;

	state_2 = (uint8_t)state;
	states = carried_obstacle_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
	case 18:
		carried_obstacle_start(object, &y, &states);
		break;
	case 2:
		states = carried_obstacle_held(object);
		break;
	case 4:
		carried_obstacle_thrown(object);
		break;
	case 6:
	case 24:
		y = carried_obstacle_fly(object);
		break;
	case 8:
	case 26:
		carried_obstacle_bounce(object);
		break;
	case 10:
	case 28:
		carried_obstacle_land(object);
		break;
	case 12:
	case 30:
		carried_obstacle_slide(object);
		break;
	case -4:
	case 14:
		carried_obstacle_break_steps(object, &y, &states);
		break;
	case -2:
	case 16:
		carried_obstacle_drop_steps(object, &y, &states);
		break;
	case 20:
		states = tossed_obstacle_held(object);
		break;
	case 22:
		tossed_obstacle_toss(object);
		break;
	}
	states = object_take_special_hit(object, states);
	carried_obstacle_check_floor(object);
	if (OBJECT(object)->flags != 0u)
	{
		t1 = OBJECT(object)->x;
		t2 = t1 - 0x10u;
		if (t2 >= 0x1A0u)
			OBJECT(object)->flags = 0u;
	}
	*p_y = y;
	*p_states = states;
}

/* Runs the kind 0F scenery of stage 2 that sets its shape in the floor, then charges with two goons. */
void charging_scenery_update(uint16_t object, uint8_t state, uint16_t *p_y, uint16_t *p_steps)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0, steps = 0;
	uint8_t part = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		charging_scenery_start(object, &y, &ignored16);
		break;
	case 2:
		charging_scenery_wait_shape(object);
		break;
	case 4:
		charging_scenery_wait_target(object, &y, &ignored16);
		break;
	case 6:
		charging_scenery_charge(object);
		break;
	case 8:
		charging_scenery_first_part(object, &y, &ignored16);
		break;
	case 10:
		charging_scenery_second_part(object, &y, &ignored16);
		break;
	case 12:
		charging_scenery_last_part(object, &y, &ignored16);
		break;
	case 14:
		charging_scenery_part_wait();
		break;
	}
	steps = charging_scenery_parts_ADDRESS;
	part = OBJECT(object)->charging_scenery.part;
	switch ((int8_t)(uint8_t)((uint32_t)part << 1))
	{
	case 0:
		charging_scenery_first_part(object, &y, &steps);
		break;
	case 2:
		charging_scenery_second_part(object, &y, &steps);
		break;
	case 4:
		charging_scenery_last_part(object, &y, &steps);
		break;
	case 6:
		charging_scenery_part_wait();
		break;
	case -8:
		charging_scenery_start(object, &y, &steps);
		break;
	case -6:
		charging_scenery_wait_shape(object);
		break;
	case -4:
		charging_scenery_wait_target(object, &y, &steps);
		break;
	case -2:
		charging_scenery_charge(object);
		break;
	}
	*p_y = y;
	*p_steps = steps;
}

/* Runs a piece flying off the platform scenery when it crashes. */
uint16_t scenery_debris_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = scenery_debris_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = scenery_debris_start(object);
		break;
	case 2:
		scenery_debris_bounce(object);
		break;
	case 4:
		scenery_debris_land(object);
		break;
	case 6:
		scenery_debris_idle();
		break;
	}
	carry = remove_off_screen(object, carry);
	return states;
}

/* Runs an obstacle that raises the floor under it and can be picked up, thrown and broken. */
void obstacle_update(uint16_t object, uint32_t carry, uint16_t *p_y, uint16_t *p_states, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t states = (uint16_t)*p_states;
	uint8_t a = 0;
	uint8_t state = 0, state_2 = 0, state_3 = 0, points = 0, shadow_player = 0;

	carry = remove_off_screen(object, carry);
	if (carry)
	{
		states = obstacle_states_ADDRESS;
		state = OBJECT(object)->state;
		switch ((int8_t)(uint8_t)((uint32_t)state << 1))
		{
		case 0:
			obstacle_start(object, &y, &states, p_left_caller);
			break;
		case 2:
			obstacle_settle(object, &y, &states, p_left_caller);
			break;
		case 4:
			obstacle_lie();
			break;
		case 6:
			states = obstacle_pick_up(object);
			break;
		case 8:
			y = obstacle_throw(object, y);
			break;
		case 10:
			obstacle_fly(object);
			break;
		case 12:
			states = obstacle_rebound(object);
			break;
		case 14:
			y = obstacle_rebound_rise(object, y);
			break;
		case 16:
			obstacle_rebound_fall(object);
			break;
		case -4:
			obstacle_smashed_steps(object, &y, &states);
			break;
		case -2:
			obstacle_knocked_steps(object, &y, &states);
			break;
		}
		state_2 = OBJECT(object)->state;
		a = state_2;
		if ((int8_t)state_2 >= 0 && a < 4u)
		{
			states = object_take_special_hit(object, states);
			state_3 = OBJECT(object)->state;
			if ((int8_t)state_3 < 0)
			{
				points = OBJECT(object)->points;
				points_player_bits = points & 0x30u;
				shadow_player = OBJECT(object)->shadow_player;
				OBJECT(object)->shadow_player = (shadow_player & 0xCFu) | points_player_bits;
			}
		}
		states = throwable_follow_floor(object, states);
	}
	*p_y = y;
	*p_states = states;
}

/* Runs a small object lying in the stage that a player can pick up and throw at the enemies. */
void throwable_update(uint16_t object, uint32_t carry, uint16_t *p_y, uint16_t *p_states)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t states = (uint16_t)*p_states;
	uint8_t state = 0, state_2 = 0, state_3 = 0;

	carry = remove_off_screen(object, carry);
	if (carry)
	{
		states = throwable_states_ADDRESS;
		state = OBJECT(object)->state;
		switch ((int8_t)(uint8_t)((uint32_t)state << 1))
		{
		case 0:
			throwable_start(object, &y, &states);
			break;
		case 2:
		case 4:
			throwable_lie();
			break;
		case 6:
			throwable_pick_up(object);
			break;
		case 8:
			y = throwable_throw(object);
			break;
		case 10:
			throwable_hurt_enemies(object);
			break;
		case 12:
			throwable_rebound(object, &y, &states);
			break;
		case 14:
			throwable_fall(object);
			break;
		case 16:
			throwable_stop(object);
			break;
		case 18:
			throwable_stop_end(object);
			break;
		case -14:
		case -8:
			obstacle_break(object);
			break;
		case -12:
		case -6:
			obstacle_break_end(object);
			break;
		case -10:
			obstacle_fall_and_break(object);
			break;
		case -4:
		case -2:
			throwable_stop_steps(object, &y, &states);
			break;
		}
		state_2 = OBJECT(object)->state;
		if ((int8_t)state_2 >= 0)
		{
			state_3 = OBJECT(object)->state;
			if (state_3 > 2u)
			{
				states = object_take_special_hit(object, states);
				throwable_check_hit(object);
			}
		}
		states = throwable_follow_floor(object, states);
	}
	*p_y = y;
	*p_states = states;
}

/* Runs the kind 0F scenery of stage 1 that sets its shape in the floor as it scrolls in. */
void platform_scenery_update(uint16_t object, uint8_t state, uint16_t *p_y, uint16_t *p_steps)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0, steps = 0;
	uint8_t part = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		platform_scenery_start(object, &y, &ignored16);
		break;
	case 2:
	case 94:
		platform_scenery_idle();
		break;
	case 4:
		platform_scenery_react(object);
		break;
	case 6:
		platform_scenery_clear_floor(object, &y, &ignored16);
		break;
	case 8:
		y = platform_scenery_launch(object);
		break;
	case 10:
		platform_scenery_crash(object, &y, &ignored16);
		break;
	case 12:
		platform_scenery_crash_wait(object);
		break;
	case 14:
		platform_scenery_vanish(object);
		break;
	case 16:
		platform_scenery_first_part(object, &y, &ignored16);
		break;
	case 18:
		platform_scenery_second_part(object, &y, &ignored16);
		break;
	case 20:
		platform_scenery_third_part(object, &y, &ignored16);
		break;
	case 22:
		platform_scenery_fourth_part(object, &y, &ignored16);
		break;
	case 24:
		platform_scenery_last_part(object, &y, &ignored16);
		break;
	case 26:
		platform_scenery_part_wait();
		break;
	}
	steps = platform_scenery_parts_ADDRESS;
	part = OBJECT(object)->platform_scenery.part;
	switch ((int8_t)(uint8_t)((uint32_t)part << 1))
	{
	case 0:
		platform_scenery_second_part(object, &y, &steps);
		break;
	case 2:
		platform_scenery_third_part(object, &y, &steps);
		break;
	case 4:
		platform_scenery_fourth_part(object, &y, &steps);
		break;
	case 6:
		platform_scenery_last_part(object, &y, &steps);
		break;
	case 8:
		platform_scenery_part_wait();
		break;
	case -16:
	case 76:
		platform_scenery_idle();
		break;
	case -18:
		platform_scenery_start(object, &y, &steps);
		break;
	case -14:
		steps = platform_scenery_react(object);
		break;
	case -12:
		platform_scenery_clear_floor(object, &y, &steps);
		break;
	case -10:
		y = platform_scenery_launch(object);
		break;
	case -8:
		platform_scenery_crash(object, &y, &steps);
		break;
	case -6:
		platform_scenery_crash_wait(object);
		break;
	case -4:
		platform_scenery_vanish(object);
		break;
	case -2:
		platform_scenery_first_part(object, &y, &steps);
		break;
	}
	*p_y = y;
	*p_steps = steps;
}

/* Runs a small piece that falls off the shaking scenery when it is hit from above. */
void shaken_bit_update(uint16_t object, uint8_t state, uint16_t *p_y, uint16_t *p_states)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = shaken_bit_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		shaken_bit_start(object, &y, &states);
		break;
	case 2:
		shaken_bit_fall(object);
		break;
	}
	*p_y = y;
	*p_states = states;
}

/* Runs the scenery that shakes when a player hits it, dropping food five times. */
void shaking_scenery_update(uint16_t object, uint8_t state, uint16_t *p_y, uint16_t *p_states)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = shaking_scenery_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		shaking_scenery_start(object, &y, &states);
		break;
	case 2:
		shaking_scenery_idle();
		break;
	case -6:
		shaking_scenery_hit_from_above_steps(object, &y, &states);
		break;
	case -4:
		shaking_scenery_shake_steps(object, &y, &states);
		break;
	case -2:
		shaking_scenery_hit_steps(object, &y, &states);
		break;
	}
	states = object_take_special_hit(object, states);
	states = shaking_scenery_check_hit_from_above(object, states);
	carry = remove_off_screen(object, carry);
	*p_y = y;
	*p_states = states;
}

/* Runs an obstacle that raises the floor by 4 steps; nothing puts one in. */
void heavy_obstacle_update(uint16_t object, uint32_t carry, uint16_t *p_y, uint16_t *p_states, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t states = (uint16_t)*p_states;
	uint8_t a = 0;
	uint16_t command = 0;
	uint8_t state = 0, state_2 = 0, points = 0, shadow_player = 0;

	carry = remove_off_screen(object, carry);
	if (carry)
	{
		states = heavy_obstacle_states_ADDRESS;
		state = OBJECT(object)->state;
		switch ((int8_t)(uint8_t)((uint32_t)state << 1))
		{
		case 0:
			heavy_obstacle_start(object, &y, &states, p_left_caller);
			break;
		case 2:
			heavy_obstacle_idle();
			break;
		case 4:
		case 6:
			heavy_obstacle_hit_steps(object, &y, &states, p_left_caller);
			break;
		case 8:
			throwable_start(object, &y, &states);
			break;
		case 10:
			timed_throwable_wait(object);
			break;
		case 12:
			timed_throwable_idle();
			break;
		case 14:
			throwable_pick_up(object);
			break;
		case 16:
			y = timed_throwable_throw(object);
			break;
		case 18:
			throwable_hurt_enemies(object);
			break;
		case 20:
			throwable_rebound(object, &y, &states);
			break;
		case 22:
			y = timed_throwable_fall(object, y);
			break;
		case 24:
			timed_throwable_smash_end(object);
			break;
		case 26:
			y = obstacle_smash(object);
			break;
		case 28:
			obstacle_smash_end(object);
			break;
		case 30:
			kind_10_riser_start(object, &y, &states);
			break;
		case 32:
			kind_10_riser_wait_boss(object);
			break;
		case 34:
			kind_10_riser_rise_slowly(object);
			break;
		case 36:
			kind_10_riser_rise_faster(object);
			break;
		case 38:
			kind_10_riser_stop(object);
			break;
		case 40:
			kind_10_riser_idle();
			break;
		case -4:
			obstacle_smashed_steps(object, &y, &states);
			break;
		case -2:
			obstacle_knocked_steps(object, &y, &states);
			break;
		}
		states = object_take_special_hit(object, states);
		state_2 = OBJECT(object)->state;
		a = state_2;
		if ((int8_t)state_2 < 0)
		{
			if (a == 0xFFu && (frame_count & 0x1Fu) == 0u)
			{
				command = 0x6500u;
				carry = vector_queue_sound(command);
			}
			points = OBJECT(object)->points;
			points_player_bits = points & 0x30u;
			shadow_player = OBJECT(object)->shadow_player;
			OBJECT(object)->shadow_player = (shadow_player & 0xCFu) | points_player_bits;
		}
		states = throwable_follow_floor(object, states);
	}
	*p_y = y;
	*p_states = states;
}

/* Runs the kind 87 character that wanders near its device and runs to it when the device is hit. */
void kind_87_update(uint16_t object, uint8_t state, uint16_t *p_y, uint16_t *p_states)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t home_distance = 0, states = 0;
	uint8_t blocked = 0, blocked_2 = 0;
	uint16_t t1 = 0, t2 = 0, home_x = 0, x_speed = 0;

	states = kind_87_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state << 1))
	{
	case 0:
		kind_87_start(object, &y, &states);
		break;
	case 2:
		kind_87_stop(object);
		break;
	case 4:
		kind_87_wander(object);
		break;
	case 6:
		states = kind_87_run_to_device(object);
		break;
	case 8:
		states = kind_87_reach_device(object);
		break;
	case 10:
		kind_87_behind_device(object);
		break;
	case 12:
		kind_87_come_back(object);
		break;
	case 14:
		kind_87_back(object);
		break;
	}
	t1 = OBJECT(object)->x;
	if (t1 < 0x1C0u)
	{
		t2 = OBJECT(object)->x;
		home_x = OBJECT(object)->kind_87.home_x;
		home_distance = t2 + camera_x - home_x;
		if ((uint16_t)(home_distance >> 15 ? 0u - home_distance : home_distance) < 0x34u)
			OBJECT(object)->blocked = 0u;
		else
		{
			blocked = OBJECT(object)->blocked;
			if (blocked == 0u)
			{
				blocked_2 = OBJECT(object)->blocked;
				OBJECT(object)->blocked = blocked_2 + 1u;
				x_speed = OBJECT(object)->x_speed;
				OBJECT(object)->x_speed = 0u - x_speed;
				face_movement(object);
			}
		}
	}
	else
		OBJECT(object)->flags = 0u;
	*p_y = y;
	*p_states = states;
}

/* Runs the kind 95 character of stage 2 that flinches when hit and runs off when beaten. */
void kind_95_update(uint16_t object, uint8_t state, uint16_t *p_y, uint16_t *p_states)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = kind_95_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		kind_95_start(object, &y, &states);
		break;
	case 2:
		kind_95_stand();
		break;
	case 4:
		kind_95_hit(object);
		break;
	case 6:
		kind_95_hit_end(object);
		break;
	case -6:
		kind_95_wait();
		break;
	case -4:
		kind_95_beaten(object);
		break;
	case -2:
		kind_95_hit_steps(object, &y, &states);
		break;
	}
	states = object_take_special_hit(object, states);
	carry = remove_off_screen(object, carry);
	*p_y = y;
	*p_states = states;
}

/* Runs the kind 87 character's device, which strikes when its keeper works it. */
void kind_87_device_update(uint16_t object, uint8_t state, uint16_t *p_y, uint16_t *p_states)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = kind_87_device_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		kind_87_device_start(object, &y, &states);
		break;
	case 2:
		states = kind_87_device_wait_hit(object, states);
		break;
	case 4:
		kind_87_device_idle();
		break;
	case 6:
		y = kind_87_device_strike(object);
		break;
	case 8:
		y = kind_87_device_strike_end(object, y);
		break;
	case 10:
		kind_87_device_reset(object);
		break;
	case 12:
		kind_87_device_reset_end(object);
		break;
	case 14:
		kind_87_device_rest(object);
		break;
	}
	carry = remove_off_screen(object, carry);
	*p_y = y;
	*p_states = states;
}

/* Runs a throwable that smashes when it lands. */
void timed_throwable_update(uint16_t object, uint8_t state, uint16_t *p_y, uint16_t *p_states, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t states = 0;
	uint8_t state_3 = 0, state_4 = 0;

	state_2 = (uint8_t)state;
	states = timed_throwable_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		throwable_start(object, &y, &states);
		break;
	case 2:
		timed_throwable_wait(object);
		break;
	case 4:
		timed_throwable_idle();
		break;
	case 6:
		throwable_pick_up(object);
		break;
	case 8:
		y = timed_throwable_throw(object);
		break;
	case 10:
		throwable_hurt_enemies(object);
		break;
	case 12:
		throwable_rebound(object, &y, &states);
		break;
	case 14:
		y = timed_throwable_fall(object, y);
		break;
	case 16:
		timed_throwable_smash_end(object);
		break;
	case 18:
		y = obstacle_smash(object);
		break;
	case 20:
		obstacle_smash_end(object);
		break;
	case 22:
		kind_10_riser_start(object, &y, &states);
		break;
	case 24:
		kind_10_riser_wait_boss(object);
		break;
	case 26:
		kind_10_riser_rise_slowly(object);
		break;
	case 28:
		kind_10_riser_rise_faster(object);
		break;
	case 30:
		kind_10_riser_stop(object);
		break;
	case 32:
		kind_10_riser_idle();
		break;
	case -12:
		obstacle_smashed_steps(object, &y, &states);
		break;
	case -10:
		obstacle_knocked_steps(object, &y, &states);
		break;
	case -8:
		heavy_obstacle_start(object, &y, &states, p_left_caller);
		break;
	case -6:
		heavy_obstacle_idle();
		break;
	case -4:
	case -2:
		heavy_obstacle_hit_steps(object, &y, &states, p_left_caller);
		break;
	}
	state_3 = OBJECT(object)->state;
	if ((int8_t)state_3 >= 0)
	{
		state_4 = OBJECT(object)->state;
		if (state_4 > 2u)
		{
			states = object_take_special_hit(object, states);
			throwable_check_hit(object);
		}
	}
	states = throwable_follow_floor(object, states);
	*p_y = y;
	*p_states = states;
}

/* Runs a cemetery obstacle that raises the floor and breaks when hit, some into food. */
void cemetery_obstacle_update(uint16_t object, uint8_t state, uint16_t *p_y, uint16_t *p_states, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = cemetery_obstacle_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		cemetery_obstacle_start(object, &y, &states);
		break;
	case 2:
		cemetery_obstacle_raise_floor(object, &states, p_left_caller);
		break;
	case 4:
		states = cemetery_obstacle_wait_boss(object, states);
		break;
	case 6:
		cemetery_obstacle_idle();
		break;
	case 8:
		cemetery_obstacle_break(object, &y, &states);
		break;
	case 10:
		cemetery_obstacle_vanish(object);
		break;
	case 12:
		cemetery_obstacle_food_fall(object);
		break;
	case -4:
	case -2:
		cemetery_obstacle_broken_steps(object, &y, &states, p_left_caller);
		break;
	}
	states = object_take_special_hit(object, states);
	check_hits_with_enemies(object);
	states = object_take_special_hit(object, states);
	*p_y = y;
	*p_states = states;
}

/* Unused: the handler of list 1's type 13, which does nothing; no object of that type is put in. */
void empty_object_type_13_handler(void)
{
}

/* Unused: the handler of list 1's type 14, which does nothing; no object of that type is put in. */
void empty_object_type_14_handler(void)
{
}

/* Runs the bird that rises, flutters and comes down as an object to pick up. */
void bird_item_update(uint16_t object, uint8_t state, uint16_t *p_y, uint16_t *p_states)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = bird_item_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		bird_item_start(object, &y, &states);
		break;
	case 2:
		bird_item_rise(object);
		break;
	case 4:
		bird_item_flutter(object);
		break;
	case 6:
		bird_item_land(object);
		break;
	}
	carry = remove_off_screen(object, carry);
	*p_y = y;
	*p_states = states;
}

/* Runs the scenery that rises out of the stage once the camera reaches it. */
void rising_scenery_update(uint16_t object, uint8_t state, uint16_t *p_y, uint16_t *p_states)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = rising_scenery_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		rising_scenery_start(object, &y, &states);
		break;
	case 2:
		rising_scenery_wait_camera(object);
		break;
	case 4:
		rising_scenery_rise(object);
		break;
	}
	carry = remove_off_screen(object, carry);
	*p_y = y;
	*p_states = states;
}

/* Runs an obstacle held by another object, dropped when the holder is hit or tossed after a moment. */
void tossed_obstacle_update(uint16_t object, uint8_t state, uint16_t *p_y, uint16_t *p_states)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = tossed_obstacle_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case -18:
	case 0:
		carried_obstacle_start(object, &y, &states);
		break;
	case 2:
		states = tossed_obstacle_held(object);
		break;
	case 4:
		tossed_obstacle_toss(object);
		break;
	case -12:
	case 6:
		y = carried_obstacle_fly(object);
		break;
	case -10:
	case 8:
		carried_obstacle_bounce(object);
		break;
	case -8:
	case 10:
		carried_obstacle_land(object);
		break;
	case -6:
	case 12:
		carried_obstacle_slide(object);
		break;
	case -22:
	case -4:
		carried_obstacle_break_steps(object, &y, &states);
		break;
	case -20:
	case -2:
		carried_obstacle_drop_steps(object, &y, &states);
		break;
	case -16:
		states = carried_obstacle_held(object);
		break;
	case -14:
		carried_obstacle_thrown(object);
		break;
	}
	states = object_take_special_hit(object, states);
	carried_obstacle_check_floor(object);
	carry = remove_off_screen(object, carry);
	*p_y = y;
	*p_states = states;
}

/* Runs the kind 10 scenery of stage 4 that comes down and rewrites the floor under it. */
void kind_10_dropper_update(uint16_t object, uint8_t state, uint16_t *p_y, uint16_t *p_states)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = kind_10_dropper_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		kind_10_dropper_start(object, &y, &states);
		break;
	case 2:
		kind_10_dropper_wait(object);
		break;
	case 4:
		kind_10_dropper_come_down(object);
		break;
	case 6:
		kind_10_dropper_land(object, &y, &states);
		break;
	case 8:
		kind_10_dropper_idle();
		break;
	}
	*p_y = y;
	*p_states = states;
}

/* Runs the kind 10 scenery of stage 4 that rises away once the boss is beaten. */
void kind_10_riser_update(uint16_t object, uint8_t state, uint16_t *p_y, uint16_t *p_states, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = kind_10_riser_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		kind_10_riser_start(object, &y, &states);
		break;
	case 2:
		kind_10_riser_wait_boss(object);
		break;
	case 4:
		kind_10_riser_rise_slowly(object);
		break;
	case 6:
		kind_10_riser_rise_faster(object);
		break;
	case 8:
		kind_10_riser_stop(object);
		break;
	case 10:
		kind_10_riser_idle();
		break;
	case -34:
		obstacle_smashed_steps(object, &y, &states);
		break;
	case -32:
		obstacle_knocked_steps(object, &y, &states);
		break;
	case -30:
		heavy_obstacle_start(object, &y, &states, p_left_caller);
		break;
	case -28:
		heavy_obstacle_idle();
		break;
	case -26:
	case -24:
		heavy_obstacle_hit_steps(object, &y, &states, p_left_caller);
		break;
	case -22:
		throwable_start(object, &y, &states);
		break;
	case -20:
		timed_throwable_wait(object);
		break;
	case -18:
		timed_throwable_idle();
		break;
	case -16:
		throwable_pick_up(object);
		break;
	case -14:
		y = timed_throwable_throw(object);
		break;
	case -12:
		throwable_hurt_enemies(object);
		break;
	case -10:
		throwable_rebound(object, &y, &states);
		break;
	case -8:
		y = timed_throwable_fall(object, y);
		break;
	case -6:
		timed_throwable_smash_end(object);
		break;
	case -4:
		y = obstacle_smash(object);
		break;
	case -2:
		obstacle_smash_end(object);
		break;
	}
	*p_y = y;
	*p_states = states;
}

/* Runs an animal that runs across the stage, which a player can pick up and throw. */
void running_animal_update(uint16_t object, uint8_t state, uint16_t *p_y, uint16_t *p_states)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;
	uint8_t state_3 = 0;

	state_2 = (uint8_t)state;
	states = running_animal_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		running_animal_start(object, &y, &states);
		break;
	case 2:
		running_animal_run(object);
		break;
	case 4:
		running_animal_stop(object);
		break;
	case 6:
		running_animal_picked_up(object);
		break;
	case 8:
		y = running_animal_thrown(object);
		break;
	case 10:
		running_animal_hurt_enemies(object);
		break;
	case 12:
		running_animal_land(object);
		break;
	case 14:
		running_animal_idle();
		break;
	case 16:
		running_animal_knocked(object);
		break;
	case 18:
		running_animal_knocked_away(object);
		break;
	case 20:
		running_animal_knocked_back(object);
		break;
	case 22:
		running_animal_gone();
		break;
	case -4:
	case -2:
		running_animal_hit_steps(object, &y, &states);
		break;
	}
	state_3 = OBJECT(object)->state;
	if ((int8_t)state_3 < 0)
	{
		carry = remove_off_screen(object, carry);
		*p_y = y;
		*p_states = states;
		return;
	}
	face_movement(object);
	states = throwable_follow_floor(object, states);
	carry = remove_off_screen(object, carry);
	*p_y = y;
	*p_states = states;
}

/* Runs a rock of stage 5's gorge that breaks when hit. */
void gorge_rock_update(uint16_t object, uint8_t state, uint16_t *p_y, uint16_t *p_states)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = gorge_rock_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		gorge_rock_start(object, &y, &states);
		break;
	case 2:
		gorge_rock_wait_hit(object);
		break;
	case 4:
		gorge_rock_break_end(object);
		break;
	}
	carry = remove_off_screen(object, carry);
	*p_y = y;
	*p_states = states;
}

/* Runs a boulder of stage 5's gorge that falls and bounces through the stage. */
void boulder_update(uint16_t object, uint8_t state, uint16_t *p_y, uint16_t *p_states)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = boulder_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		boulder_start(object, &y, &states);
		break;
	case 2:
		boulder_wait(object);
		break;
	case 4:
		boulder_fall(object);
		break;
	case 6:
		boulder_bounce(object);
		break;
	case 8:
		boulder_fall_in_front(object);
		break;
	}
	carry = remove_off_screen(object, carry);
	*p_y = y;
	*p_states = states;
}

/* Runs a throwable that bounces once when it lands. */
void bouncing_throwable_update(uint16_t object, uint8_t state, uint16_t *p_y, uint16_t *p_states)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = bouncing_throwable_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		bouncing_throwable_start(object, &y, &states);
		break;
	case 2:
	case 4:
		bouncing_throwable_lie();
		break;
	case 6:
		bouncing_throwable_pick_up(object);
		break;
	case 8:
		y = bouncing_throwable_throw(object);
		break;
	case 10:
		bouncing_throwable_fly(object);
		break;
	case 12:
		throwable_rebound(object, &y, &states);
		break;
	case 14:
		throwable_fall(object);
		break;
	case -4:
	case -2:
		throwable_stop_steps(object, &y, &states);
		break;
	}
	states = throwable_follow_floor(object, states);
	carry = remove_off_screen(object, carry);
	*p_y = y;
	*p_states = states;
}

/* Runs the object on the shaking scenery that falls off it when shaken and lets out a chaser. */
void shaken_object_update(uint16_t object, uint8_t state, uint16_t *p_y, uint16_t *p_states)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = shaken_object_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		shaken_object_start(object, &y, &states);
		break;
	case 2:
		states = shaken_object_wait(object);
		break;
	case 4:
		shaken_object_fall(object);
		break;
	case 6:
		shaken_object_land(object, &y, &states);
		break;
	}
	carry = remove_off_screen(object, carry);
	*p_y = y;
	*p_states = states;
}

/* Runs an obstacle thrown into Dreamland that then lies as an obstacle to pick up. */
void dreamland_obstacle_update(uint16_t object, uint8_t state, uint16_t *p_y, uint16_t *p_states)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t states = 0;
	uint16_t t1 = 0, t2 = 0;

	state_2 = (uint8_t)state;
	states = dreamland_obstacle_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		dreamland_obstacle_start(object, &y, &states);
		break;
	case 2:
		dreamland_obstacle_drop_steps(object, &y, &states);
		break;
	case 4:
		dreamland_obstacle_idle();
		break;
	case 6:
		dreamland_obstacle_pick_up(object);
		break;
	case 8:
		y = obstacle_throw(object, y);
		break;
	case 10:
		obstacle_fly(object);
		break;
	case 12:
		states = obstacle_rebound(object);
		break;
	case 14:
		y = obstacle_rebound_rise(object, y);
		break;
	case 16:
		obstacle_rebound_fall(object);
		break;
	case -4:
		obstacle_smashed_steps(object, &y, &states);
		break;
	case -2:
		obstacle_knocked_steps(object, &y, &states);
		break;
	}
	states = throwable_follow_floor(object, states);
	if (OBJECT(object)->flags != 0u)
	{
		t1 = OBJECT(object)->x;
		t2 = t1 - 0x40u;
		if (t2 >= 0x1C0u)
			OBJECT(object)->flags = 0u;
	}
	*p_y = y;
	*p_states = states;
}
