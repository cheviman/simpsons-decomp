/**
 *    Name:        objects/police_car.c
 *    Description: the police car that drives into stage 1 and stage 2
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    10-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Runs the police car's reaction to a hit, by its substep. */
uint16_t police_car_hit_steps(uint16_t object)
{
	uint16_t step_handlers = 0;
	uint8_t action_step = 0;

	for (;;)
	{
		step_handlers = police_car_hit_step_handlers_ADDRESS;
		action_step = OBJECT(object)->action_step;
		switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
		{
		case 0:
			police_car_hit(object);
			return step_handlers;
		case 2:
			police_car_drive_off(object);
			return step_handlers;
		case 4:
			break;
		case -16:
		case -14:
			continue;
		case -12:
			return police_car_start(object);
		case -10:
			police_car_drive_in(object);
			return step_handlers;
		case -8:
			return police_car_stopped(object, step_handlers);
		case -6:
			return police_car_wait(object, step_handlers);
		case -4:
			return police_car_leave(object, step_handlers);
		case -2:
			return police_car_driving_off(object, step_handlers);
		}
		break;
	}
	police_car_hit_wait();
	return step_handlers;
}

/* Plays sound 6300 and the car's hit animation. */
void police_car_hit(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t action_step = 0;

	command = 0x6300u;
	carry = vector_queue_sound(command);
	OBJECT(object)->animation = 0x85u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	police_car_hit_wait();
}

/* Does nothing (the step after the hit). */
void police_car_hit_wait(void)
{
}

/* When the hit animation ends, drives away to the right. */
void police_car_drive_off(uint16_t object)
{
	uint8_t animation_flags = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	OBJECT(object)->animation = 0x81u;
	OBJECT(object)->x_speed = 0x200;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	face_movement(object);
}

/* Sets the police car up by its spawn's state: its speed, the frames it drives and its kind. */
uint16_t police_car_start(uint16_t object)
{
	uint16_t police_car_arrival = 0, setup = 0;
	uint8_t parameter = 0, state = 0;
	uint16_t x_speed = 0, frames = 0;

	setup = police_car_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->flags = 0x80u;
	parameter = OBJECT(object)->parameter;
	police_car_arrival = police_car_arrivals_ADDRESS + (int8_t)(((uint32_t)parameter << 1) << 1);
	x_speed = POLICE_CAR_ARRIVAL(police_car_arrival)->x_speed;
	OBJECT(object)->x_speed = x_speed;
	frames = (((uint32_t)POLICE_CAR_ARRIVAL(police_car_arrival)->frames << 8u) | POLICE_CAR_ARRIVAL(police_car_arrival)->kind);
	OBJECT(object)->timer = frames >> 8;
	OBJECT(object)->kind = frames;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	face_movement(object);
	return police_car_arrival;
}

/* Drives in (holding the scroll in stage 1), then stops and tells the doors and bystanders (1884). */
void police_car_drive_in(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	if (scene == 0u)
		camera_x_held--;
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->flags = 0xC0u;
		io_write8(0x1884u, 0xC0u);
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->animation = 0x89u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* After stopping, waits for the animation's end, taking hits (and hurting enemies outside stage 1). */
uint16_t police_car_stopped(uint16_t object, uint16_t hitter)
{
	uint8_t animation_flags = 0, state = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		OBJECT(object)->animation = 0x80u;
		OBJECT(object)->timer = 0x80u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
	hitter = police_car_check_hit(object, hitter);
	if (scene == 0u)
		return hitter;
	check_hits_with_enemies(object);
	return police_car_check_hit(object, hitter);
}

/* When a player's attack hits the car, counts it for that player and starts the car's hit reaction. */
uint16_t police_car_check_hit(uint16_t object, uint16_t hitter)
{
	uint8_t hit = 0, state = 0, kind = 0, kind_2 = 0, behaviour = 0;
	uint16_t hit_by = 0;

	if ((OBJECT(object)->flags & 0x20u) == 0u)
		return hitter;
	hit = OBJECT(object)->hit;
	if (hit < 1 || hit > 0x15)
		return hitter;
	state = OBJECT(object)->state;
	if ((int8_t)state < 0)
		return hitter;
	hit_by = OBJECT(object)->hit_by;
	hitter = hit_by;
	kind = OBJECT(object)->kind;
	if ((int8_t)kind < 0)
	{
		kind_2 = OBJECT(hitter)->kind;
		if (kind_2 <= 3u)
		{
			behaviour = (uint8_t)(OBJECT(hitter)->behaviour >> 8u);
			OBJECT(hitter)->behaviour = (OBJECT(hitter)->behaviour & 0xFFu) | ((behaviour + 1u & 0xFFu) << 8u);
			AT16(OBJECT(hitter)->hit_box, -1) = object;
		}
	}
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->state = 0xFFu;
	OBJECT(object)->action = 0u;
	OBJECT(object)->action_step = 0u;
	return hitter;
}

/* Waits 128 frames, taking hits. */
uint16_t police_car_wait(uint16_t object, uint16_t hitter)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
	hitter = police_car_check_hit(object, hitter);
	if (scene == 0u)
		return hitter;
	check_hits_with_enemies(object);
	return police_car_check_hit(object, hitter);
}

/* When its animation ends, drives away to the right. */
uint16_t police_car_leave(uint16_t object, uint16_t u)
{
	uint8_t animation_flags = 0, state = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return police_car_driving_off(object, u);
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->animation = 0x81u;
	OBJECT(object)->x_speed = 0x200;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	face_movement(object);
	return u;
}

/* Drives away, taking hits. */
uint16_t police_car_driving_off(uint16_t object, uint16_t hitter)
{
	hitter = police_car_check_hit(object, hitter);
	if (scene == 0u)
		return hitter;
	check_hits_with_enemies(object);
	return police_car_check_hit(object, hitter);
}

/* Sets up a door of the police car: its wait and release list, or nothing if too few players are
   present. */
uint16_t police_car_door_start(uint16_t object)
{
	uint16_t police_car_door = 0, setup = 0;
	uint8_t attributes = 0, parameter = 0, players_now = 0, trigger_x = 0, state = 0;
	uint16_t trigger_at_x = 0, wait = 0;

	setup = police_car_door_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->flags = 0x80u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0x10u;
	parameter = OBJECT(object)->parameter;
	police_car_door = police_car_doors_ADDRESS + (int8_t)(((uint32_t)parameter << 1) << 1);
	players_now = io_read8(0x1874u);
	if (players_now < POLICE_CAR_DOOR(police_car_door)->players)
	{
		OBJECT(object)->state = 4u;
		return police_car_door;
	}
	trigger_x = POLICE_CAR_DOOR(police_car_door)->trigger_x;
	trigger_at_x = (uint32_t)trigger_x << 4;
	OBJECT(object)->police_car_door.trigger_x = trigger_at_x;
	wait = (((uint32_t)POLICE_CAR_DOOR(police_car_door)->wait << 8u) | POLICE_CAR_DOOR(police_car_door)->releases);
	OBJECT(object)->timer = wait >> 8;
	OBJECT(object)->parameter = wait;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	police_car_door_idle();
	return police_car_door;
}

/* Does nothing (a door too few players are present for). */
void police_car_door_idle(void)
{
}

/* Waits until the police car has stopped. */
void police_car_door_wait_car(uint16_t object)
{
	uint8_t car_stopped = 0, state = 0;

	car_stopped = io_read8(0x1884u);
	if (car_stopped != 0u)
	{
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* After its wait, opens and lets out the goons its list holds for the players present. */
uint16_t police_car_door_open(uint16_t object, uint16_t states)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t ignored16 = 0, release = 0, released = 0;
	uint8_t timer = 0, state = 0, parameter = 0, players_now = 0;
	uint16_t release_record = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return states;
	OBJECT(object)->animation = 0x95u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	released = police_car_door_lists_ADDRESS;
	parameter = OBJECT(object)->parameter;
	release = police_car_door_lists[(int8_t)((uint8_t)((uint32_t)parameter << 1)) / 2];
	for (;;)
	{
		release_record = release;
		release = release_record + 1u;
		a = mem_read8(release_record);
		if (a == 0x7Fu)
			break;
		players_now = io_read8(0x1874u);
		if (a < players_now)
		{
			leftover_y = release;
			vector_spawn_child(object, &release, &released, &ignored16, &carry);
		}
		release += 8u;
	}
	leftover_y = release;
	return released;
}

/* When the door's animation ends, takes it away with sound 2200. */
void police_car_door_vanish(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	OBJECT(object)->flags = 0u;
	command = 0x2200u;
	carry = vector_queue_sound(command);
}
