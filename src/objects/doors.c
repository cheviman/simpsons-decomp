/**
 *    Name:        objects/doors.c
 *    Description: the doors that open when the stage reaches them and let out enemies (kinds 0F, 10, 12), the car whose doors let enemies out, the kind-93 passer-by
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* The kind-0F door (5280 type 0C, stage 1 and stage 4): runs its step and leaves the screen with it. */
uint16_t door_kind_0f_run(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = door_kind_0f_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = door_kind_0f_start(object);
		break;
	case 2:
		door_wait_for_place(object);
		break;
	case 4:
		door_kind_0f_open(object);
		break;
	case 6:
		states = door_kind_0f_let_out_enemies(object);
		break;
	case 8:
		door_wait_for_animation(object);
		break;
	case 10:
		door_kind_0f_close(object);
		break;
	case 12:
		door_idle();
		break;
	}
	remove_off_screen(object, carry);
	return states;
}

/* The kind-10 door (5280 type 0B, stage 4's shop fronts): runs its step and leaves the screen with it. */
uint16_t door_kind_10_run(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = door_kind_10_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = door_kind_10_start(object);
		break;
	case -118:
	case 2:
		door_wait_for_place(object);
		break;
	case 4:
		door_kind_10_open(object);
		break;
	case 6:
		states = door_kind_10_let_out_enemies(object);
		break;
	case 8:
		door_kind_10_finish(object);
		break;
	case -108:
	case 10:
		door_idle();
		break;
	}
	remove_off_screen(object, carry);
	return states;
}

/* The kind-12 door (5280 type 38, stage 7's glass doors): runs its step and is gone once its x leaves
   30-1C0. */
uint16_t door_kind_12_run(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;
	uint16_t door_x = 0, screen_offset = 0;

	state_2 = (uint8_t)state;
	states = door_kind_12_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = door_kind_12_start(object);
		break;
	case 2:
	case 122:
		door_wait_for_place(object);
		break;
	case 4:
		door_kind_12_open(object);
		break;
	case 6:
		states = door_kind_12_let_out_enemies(object);
		break;
	case 8:
		door_wait_for_animation(object);
		break;
	case 10:
		door_kind_12_close(object);
		break;
	case 12:
		door_idle();
		break;
	}
	if (OBJECT(object)->flags != 0u)
	{
		door_x = OBJECT(object)->x;
		screen_offset = door_x - 0x30u;
		if (screen_offset >= 0x190u)
			OBJECT(object)->flags = 0u;
	}
	return states;
}

/* The kind-93 passer-by of stage 1 (5280 type 2A): runs its step and leaves the screen with it. */
uint16_t kid_in_sunglasses_run(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = kid_in_sunglasses_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = kid_in_sunglasses_start(object);
		break;
	case 2:
		kid_in_sunglasses_wait_for_scroll(object);
		break;
	case 4:
		kid_in_sunglasses_run_in(object);
		break;
	case 6:
		kid_in_sunglasses_turn_away(object);
		break;
	case 8:
		kid_in_sunglasses_wait_for_floor(object);
		break;
	case 10:
		kid_in_sunglasses_walk_down(object);
		break;
	case 12:
		kid_in_sunglasses_stop(object);
		break;
	case 14:
	case 20:
		kid_in_sunglasses_walk_left(object);
		break;
	case 16:
		kid_in_sunglasses_dash_left(object);
		break;
	case 18:
		kid_in_sunglasses_stand(object);
		break;
	case 22:
		kid_in_sunglasses_idle();
		break;
	}
	remove_off_screen(object, carry);
	return states;
}

/* The car whose doors open and let enemies out (5280 type 12, kind 0F police_car_and_doors, stage 1):
   runs its step and is gone once its x is below 30. */
uint16_t car_doors_run(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;
	uint16_t door_x = 0;

	state_2 = (uint8_t)state;
	states = car_doors_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = car_doors_start(object);
		break;
	case 2:
		car_doors_wait_for_scroll(object);
		break;
	case 4:
		car_doors_wait(object);
		break;
	case 6:
		car_doors_open(object);
		break;
	case 8:
		car_doors_hold_open(object);
		break;
	case 10:
	case 18:
		car_doors_wait_for_animation(object);
		break;
	case 12:
		states = car_doors_shake_and_unload(object, states);
		break;
	case 14:
		car_doors_close(object);
		break;
	case 16:
		car_doors_closed(object);
		break;
	case 20:
		car_doors_shake(object);
		break;
	case 22:
		car_doors_idle();
		break;
	}
	door_x = OBJECT(object)->x;
	if (door_x < 0x30u)
		OBJECT(object)->flags = 0u;
	return states;
}

/* Sets kind 93 up from its setup record, shown, at its first priority, and goes on to wait for the
   scroll. */
uint16_t kid_in_sunglasses_start(uint16_t object)
{
	uint16_t setup = 0;
	uint8_t attributes = 0, state = 0;

	setup = kid_in_sunglasses_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->flags = 0x80u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0x20u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return setup;
}

/* Waits until the stage has scrolled to 120. */
void kid_in_sunglasses_wait_for_scroll(uint16_t object)
{
	uint8_t state = 0;

	if (camera_x >= 0x120u)
	{
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Runs right (x speed 0200, animation 82) for 44 frames. */
void kid_in_sunglasses_run_in(uint16_t object)
{
	uint8_t state = 0;

	OBJECT(object)->x_speed = 0x200;
	OBJECT(object)->animation = 0x82u;
	OBJECT(object)->timer = 0x2Cu;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	face_movement(object);
}

/* When its frames run out, heads off at speed 30 in direction E8 with animation 81. */
void kid_in_sunglasses_turn_away(uint16_t object)
{
	uint16_t heading = 0;
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	heading = 0xE830u;
	vector_set_speed_by_direction(object, heading);
	OBJECT(object)->animation = 0x81u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Waits until it stands on a floor of height 0, then takes the second priority. */
void kid_in_sunglasses_wait_for_floor(uint16_t object)
{
	uint32_t negative = 0;
	uint8_t cell = 0;
	uint16_t floor_cell = 0;
	uint8_t attributes = 0, state = 0;

	floor_cell = 0u;
	vector_floor_at_offset(object, &floor_cell, &negative);
	cell = (uint8_t)(floor_cell >> 8);
	if ((int8_t)cell < 0 || (cell & 0xFu) != 0u)
		return;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0x10u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Walks right and down (x speed 0140, y speed 0080, animation 82) for 12 frames. */
void kid_in_sunglasses_walk_down(uint16_t object)
{
	uint8_t state = 0;

	OBJECT(object)->y_speed = 0x80;
	OBJECT(object)->x_speed = 0x140;
	OBJECT(object)->animation = 0x82u;
	OBJECT(object)->timer = 0xCu;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	face_movement(object);
}

/* When its frames run out, stops facing left (animation 83) for 64 frames. */
void kid_in_sunglasses_stop(uint16_t object)
{
	uint8_t timer = 0, attributes = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0;
		OBJECT(object)->animation = 0x83u;
		attributes = OBJECT(object)->attributes;
		OBJECT(object)->attributes = attributes | 0x40u;
		OBJECT(object)->timer = 0x40u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* When its frames run out, stops (animation 83) for 64 frames, after its dash. */
void kid_in_sunglasses_stand(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->animation = 0x83u;
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->timer = 0x40u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* When its frames run out, walks left (x speed FE00, animation 82) for 16 frames (after each stop). */
void kid_in_sunglasses_walk_left(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
	{
		kid_in_sunglasses_idle();
		return;
	}
	OBJECT(object)->animation = 0x82u;
	OBJECT(object)->x_speed = -0x200;
	OBJECT(object)->timer = 0x10u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	face_movement(object);
}

/* Its last step: nothing (it walks on at its speed until it leaves the screen). */
void kid_in_sunglasses_idle(void)
{
}

/* When its frames run out, dashes left (x speed FB00, animation 84) for 24 frames. */
void kid_in_sunglasses_dash_left(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->animation = 0x84u;
		OBJECT(object)->timer = 0x18u;
		OBJECT(object)->x_speed = -0x500;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Sets the car up from its setup record and shows it. */
uint16_t car_doors_start(uint16_t object)
{
	uint16_t setup = 0;
	uint8_t state = 0;

	setup = car_doors_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->flags = 0x80u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return setup;
}

/* Waits until the stage has scrolled to 120, then 44 frames more. */
void car_doors_wait_for_scroll(uint16_t object)
{
	uint8_t state = 0;
	uint16_t camera_x_now = 0;

	camera_x_now = camera_x;
	if (camera_x_now >= 0x120u)
	{
		OBJECT(object)->timer = 0x2Cu;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Counts its frames down. */
void car_doors_wait(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Opens its doors (animation 8A, sound 60) and can be hit while they open, for 16 frames. */
void car_doors_open(uint16_t object)
{
	uint16_t command = 0;
	uint8_t state = 0;

	OBJECT(object)->flags = 0xC0u;
	command = 0x6000u;
	vector_queue_sound(command);
	OBJECT(object)->animation = 0x8Au;
	OBJECT(object)->timer = 0x10u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* When its frames run out, holds its doors open (animation 8B). */
void car_doors_hold_open(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->flags = 0x80u;
		OBJECT(object)->animation = 0x8Bu;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* When its animation ends, waits 32 frames more. */
void car_doors_wait_for_animation(uint16_t object)
{
	uint8_t animation_flags = 0, state = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		OBJECT(object)->timer = 0x20u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Shakes up and down for 8 frames, then lets its enemies out and waits 54 frames. */
uint16_t car_doors_shake_and_unload(uint16_t object, uint16_t states)
{
	uint8_t timer_now = 0;
	uint8_t timer = 0, z_low = 0, timer_2 = 0, state = 0;

	timer = OBJECT(object)->timer;
	timer_now = timer;
	if (timer_now >= 0x18u)
	{
		z_low = (uint8_t)OBJECT(object)->z;
		OBJECT(object)->z = (OBJECT(object)->z & 0xFF00u) | ((timer_now & 1u) ^ z_low & 0xFFu);
	}
	timer_2 = OBJECT(object)->timer;
	OBJECT(object)->timer = timer_2 - 1u;
	if (timer_2 != 1u)
		return states;
	states = car_doors_let_out_enemies(object);
	OBJECT(object)->timer = 0x36u;
	OBJECT(object)->z &= 0xFF00u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return states;
}

/* Puts in the enemies of its door_spawns list (by spawn_list) that the players in the game call for,
   counting them in spawned (then 16 frames each). */
uint16_t car_doors_let_out_enemies(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t players = 0;
	uint16_t ignored16 = 0, lists = 0, spawn = 0;
	uint8_t spawn_list = 0, players_counted = 0, spawned = 0, spawned_2 = 0;
	uint16_t spawn_record = 0;

	OBJECT(object)->car_doors.spawned = 0u;
	lists = door_spawn_lists_ADDRESS;
	spawn_list = OBJECT(object)->car_doors.spawn_list;
	spawn = door_spawn_lists[(int8_t)((uint8_t)((uint32_t)spawn_list << 1)) / 2];
	for (;;)
	{
		spawn_record = spawn;
		spawn = spawn_record + 1u;
		players = DOOR_SPAWN(spawn_record)->players;
		if (players == 0x7Fu)
			break;
		players_counted = io_read8(stage_player_count);
		if (players < players_counted)
		{
			spawned = OBJECT(object)->car_doors.spawned;
			OBJECT(object)->car_doors.spawned = spawned + 1u;
			leftover_y = spawn;
			vector_spawn_child(object, &spawn, &lists, &ignored16, &carry);
		}
		spawn += 8u;
	}
	spawned_2 = OBJECT(object)->car_doors.spawned;
	OBJECT(object)->car_doors.spawned = ((((uint32_t)spawned_2 << 1) << 1) << 1) << 1;
	leftover_y = spawn;
	return lists;
}

/* When its frames run out, waits 16 frames for each enemy it let out while it closes its doors
   (animation 8C, sound 60). */
void car_doors_close(uint16_t object)
{
	uint16_t command = 0;
	uint8_t timer = 0, spawned = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->flags = 0xC0u;
	spawned = OBJECT(object)->car_doors.spawned;
	OBJECT(object)->timer = spawned;
	command = 0x6000u;
	vector_queue_sound(command);
	OBJECT(object)->animation = 0x8Cu;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* When its frames run out, shows its doors closed (animation 8D); it can not be hit. */
void car_doors_closed(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->animation = 0x8Du;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
	OBJECT(object)->flags = 0x80u;
}

/* Shakes up and down for 8 frames. */
void car_doors_shake(uint16_t object)
{
	uint8_t timer_now = 0;
	uint8_t timer = 0, z_low = 0, timer_2 = 0, state = 0;

	timer = OBJECT(object)->timer;
	timer_now = timer;
	if (timer_now >= 0x18u)
	{
		z_low = (uint8_t)OBJECT(object)->z;
		OBJECT(object)->z = (OBJECT(object)->z & 0xFF00u) | ((timer_now & 1u) ^ z_low & 0xFFu);
	}
	timer_2 = OBJECT(object)->timer;
	OBJECT(object)->timer = timer_2 - 1u;
	if (timer_2 != 1u)
	{
		car_doors_idle();
		return;
	}
	OBJECT(object)->z &= 0xFF00u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	car_doors_idle();
}

/* Its last step: nothing. */
void car_doors_idle(void)
{
}

/* Sets the kind-12 door up from its setup record and its channel_6_scenery_door_openings record (by its
   spawn state): where it opens and which list it lets out. */
uint16_t door_kind_12_start(uint16_t object)
{
	uint16_t opening = 0, setup = 0;
	uint8_t spawn_list = 0, state = 0;
	uint16_t opening_x = 0, wait = 0;

	setup = door_kind_12_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->flags = 0x80u;
	spawn_list = OBJECT(object)->door.spawn_list;
	opening = channel_6_scenery_door_openings_ADDRESS + (int8_t)(((uint32_t)spawn_list << 1) << 1);
	opening_x = DOOR_OPENING(opening)->x;
	OBJECT(object)->door.open_x = opening_x;
	wait = (((uint32_t)DOOR_OPENING(opening)->wait << 8u) | DOOR_OPENING(opening)->list);
	OBJECT(object)->door.spawn_list = wait;
	OBJECT(object)->attributes = 0u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return opening;
}

/* Opens (animation 8A, sound 60), hitting what it touches with strength 08 (a player is knocked down). */
void door_kind_12_open(uint16_t object)
{
	uint16_t command = 0;
	uint8_t state = 0;

	OBJECT(object)->flags = 0xC0u;
	OBJECT(object)->attack = 8u;
	command = 0x6000u;
	vector_queue_sound(command);
	OBJECT(object)->animation = 0x8Au;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Lets out its list of enemies (the kind-12 doors' lists). */
uint16_t door_kind_12_let_out_enemies(uint16_t object)
{
	uint16_t lists = 0;

	OBJECT(object)->door.spawned = 0u;
	lists = door_kind_12_enemy_lists_ADDRESS;
	return door_let_out_list(object, lists);
}

/* When its frames run out, closes (animation 8B). */
void door_kind_12_close(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->animation = 0x8Bu;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Sets the kind-10 door up from its setup record and its moes_street_scenery_door_openings record: where
   it opens, how long it waits and which list it lets out. */
uint16_t door_kind_10_start(uint16_t object)
{
	uint16_t opening = 0, setup = 0;
	uint8_t spawn_list = 0, state = 0;
	uint16_t opening_x = 0, wait = 0;

	setup = door_kind_10_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->flags = 0x80u;
	spawn_list = OBJECT(object)->door.spawn_list;
	opening = moes_street_scenery_door_openings_ADDRESS + (int8_t)(((uint32_t)spawn_list << 1) << 1);
	opening_x = DOOR_OPENING(opening)->x;
	OBJECT(object)->door.open_x = opening_x;
	wait = (((uint32_t)DOOR_OPENING(opening)->wait << 8u) | DOOR_OPENING(opening)->list);
	OBJECT(object)->timer = wait >> 8;
	OBJECT(object)->door.spawn_list = wait;
	OBJECT(object)->attributes = 0u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return opening;
}

/* When its wait runs out, opens (kind 0F, animation 95, sound 60), hitting what it touches with strength
   08. */
void door_kind_10_open(uint16_t object)
{
	uint16_t command = 0;
	uint8_t timer = 0, attributes = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->flags = 0xC0u;
	OBJECT(object)->attack = 8u;
	command = 0x6000u;
	vector_queue_sound(command);
	OBJECT(object)->kind = 0xFu;
	OBJECT(object)->animation = 0x95u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0x30u) | 0x83u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* When its animation ends, it is gone. */
void door_kind_10_finish(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
		OBJECT(object)->flags = 0u;
}

/* Lets out its list of enemies (the kind-10 doors' lists). */
uint16_t door_kind_10_let_out_enemies(uint16_t object)
{
	uint16_t lists = 0;

	OBJECT(object)->door.spawned = 0u;
	lists = door_kind_10_enemy_lists_ADDRESS;
	return door_let_out_list(object, lists);
}

/* Sets the kind-0F door up from its setup record and its kind_0f_door_openings record: where it opens
   and which list it lets out. */
uint16_t door_kind_0f_start(uint16_t object)
{
	uint16_t opening = 0, setup = 0;
	uint8_t spawn_list = 0, state = 0;
	uint16_t opening_x = 0, wait = 0;

	setup = door_kind_0f_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->flags = 0x80u;
	spawn_list = OBJECT(object)->door.spawn_list;
	opening = kind_0f_door_openings_ADDRESS + (int8_t)(((uint32_t)spawn_list << 1) << 1);
	opening_x = DOOR_OPENING(opening)->x;
	OBJECT(object)->door.open_x = opening_x;
	wait = (((uint32_t)DOOR_OPENING(opening)->wait << 8u) | DOOR_OPENING(opening)->list);
	OBJECT(object)->door.spawn_list = wait;
	OBJECT(object)->attributes = 0u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return opening;
}

/* Waits until the door's x on the screen comes below the place it opens at. */
void door_wait_for_place(uint16_t object)
{
	uint8_t state = 0;
	uint16_t door_x = 0, open_x = 0;

	door_x = OBJECT(object)->x;
	open_x = OBJECT(object)->door.open_x;
	if (door_x < open_x)
	{
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Opens (animation 8F, sound 60), hitting what it touches with strength 08. */
void door_kind_0f_open(uint16_t object)
{
	uint16_t command = 0;
	uint8_t state = 0;

	OBJECT(object)->flags = 0xC0u;
	OBJECT(object)->attack = 8u;
	command = 0x6000u;
	vector_queue_sound(command);
	OBJECT(object)->animation = 0x8Fu;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Goes on when its animation ends; it can not be hit any more. */
void door_wait_for_animation(uint16_t object)
{
	uint8_t animation_flags = 0, state = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
	OBJECT(object)->flags = 0x80u;
}

/* Lets out its list of enemies (the kind-0F doors' lists). */
uint16_t door_kind_0f_let_out_enemies(uint16_t object)
{
	uint16_t lists = 0;

	OBJECT(object)->door.spawned = 0u;
	lists = door_kind_0f_enemy_lists_ADDRESS;
	return door_let_out_list(object, lists);
}

/* Puts in the enemies of the door's list (U, by spawn_list) that the players in the game call for, and
   waits 16 frames for each (24 if none). */
uint16_t door_let_out_list(uint16_t object, uint16_t lists)
{
	uint32_t carry = 0;
	uint8_t fewest_players = 0;
	uint16_t ignored16 = 0, spawn = 0;
	uint8_t spawn_list = 0, state = 0, players_counted = 0, spawned = 0, spawned_2 = 0, state_2 = 0;
	uint16_t first_spawn_record = 0, spawn_record = 0;

	spawn_list = OBJECT(object)->door.spawn_list;
	first_spawn_record = mem_read16(lists + (int8_t)((uint32_t)spawn_list << 1));
	spawn = first_spawn_record + 1u;
	fewest_players = mem_read8(first_spawn_record);
	if (fewest_players == 0x7Fu)
	{
		OBJECT(object)->timer = 0x18u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
		leftover_y = spawn;
		return lists;
	}
	do
	{
		players_counted = io_read8(stage_player_count);
		if (fewest_players < players_counted)
		{
			spawned = OBJECT(object)->door.spawned;
			OBJECT(object)->door.spawned = spawned + 1u;
			leftover_y = spawn;
			vector_spawn_child(object, &spawn, &lists, &ignored16, &carry);
		}
		spawn += 8u;
		spawn_record = spawn;
		spawn = spawn_record + 1u;
		fewest_players = DOOR_SPAWN(spawn_record)->players;
	} while (fewest_players != 0x7Fu);
	spawned_2 = OBJECT(object)->door.spawned;
	OBJECT(object)->timer = ((((uint32_t)spawned_2 << 1) << 1) << 1) << 1;
	state_2 = OBJECT(object)->state;
	OBJECT(object)->state = state_2 + 1u;
	leftover_y = spawn;
	return lists;
}

/* When its frames run out, closes (animation 90). */
void door_kind_0f_close(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
	{
		door_idle();
		return;
	}
	OBJECT(object)->animation = 0x90u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	door_idle();
}

/* A door's last step: nothing. */
void door_idle(void)
{
}
