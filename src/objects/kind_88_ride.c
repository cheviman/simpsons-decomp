/**
 *    Name:        objects/kind_88_ride.c
 *    Description: Krustyland's ride: its hub, its arms, the kind 88 enemies riding it
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Sets up the ride's hub, unseen. */
void kind_88_ride_start(uint16_t object, uint16_t *p_box, uint16_t *p_setup)
{
	uint16_t box = 0, setup = 0;
	uint8_t t1 = 0, attributes = 0, state = 0;
	uint16_t t2 = 0, t3 = 0;

	setup = kind_88_ride_setup_ADDRESS;
	box = vector_object_setup(object, setup);
	OBJECT(object)->flags = 4u;
	t1 = io_read8(0x1881u);
	io_write8(0x1881u, 0u);
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0x20u;
	t2 = OBJECT(object)->x;
	t3 = t2 + 0x40u;
	OBJECT(object)->x = t3;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	*p_box = box;
	*p_setup = setup;
}

/* Holds the scroll until fewer than 2 enemies are left, then puts in its three arms a third of a turn
   apart. */
void kind_88_ride_put_in_arms(uint16_t object, uint16_t *p_arm_record, uint16_t *p_arm)
{
	uint16_t arm_record = (uint16_t)*p_arm_record;
	uint16_t arm = (uint16_t)*p_arm;
	uint32_t carry = 0;
	uint8_t angle = 0;
	uint8_t t1 = 0, state = 0, arms = 0, t2 = 0;

	camera_x_held--;
	t1 = io_read8(0x1876u);
	if (t1 < 2u)
	{
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
		OBJECT(object)->kind_88_ride.arms = 0u;
		ride_parts_left = 3u;
		ride_part_angle = 0x40u;
		do
		{
			arm_record = kind_88_ride_put_in_arms_child_ADDRESS;
			spawn_list_2_child(object, arm_record, &arm, &carry);
			if (carry == 0u)
				break;
			OBJECT(arm)->kind_88_ride_arm.ride_hub = object;
			arms = OBJECT(object)->kind_88_ride.arms;
			OBJECT(object)->kind_88_ride.arms = arms + 1u;
			OBJECT(arm)->kind_88_ride_arm.radius = 0x80u;
			angle = ride_part_angle;
			OBJECT(arm)->kind_88_ride_arm.angle = angle;
			ride_part_angle = angle + 0x55u;
			OBJECT(arm)->kind_88_ride_arm.frame_offset = (((uint32_t)ride_parts_left << 1) << 1) << 1;
			t2 = ride_parts_left;
			ride_parts_left = t2 - 1u;
		} while (t2 != 1u);
	}
	*p_arm_record = arm_record;
	*p_arm = arm;
}

/* Waits until 1884 is set. */
void kind_88_ride_wait_signal(uint16_t object)
{
	uint8_t t1 = 0, state = 0;

	t1 = io_read8(0x1884u);
	if (t1 != 0u)
	{
		OBJECT(object)->timer = 0x40u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Waits 64 frames. */
void kind_88_ride_wait(uint16_t object)
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

/* Waits until fewer than 2 enemies are left. */
void kind_88_ride_wait_enemies(uint16_t object)
{
	uint8_t t1 = 0, state = 0;

	t1 = io_read8(0x1876u);
	if (t1 < 2u)
	{
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Once its arms and riders are gone, goes away, putting in a last goon. */
void kind_88_ride_end(uint16_t object, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t ignored16 = 0, record = 0, u_2 = 0;
	uint8_t arms = 0, riders_out = 0;

	arms = OBJECT(object)->kind_88_ride.arms;
	if (arms != 0u)
		return;
	riders_out = OBJECT(object)->kind_88_ride.riders_out;
	if (riders_out != 0u)
		return;
	OBJECT(object)->flags = 0u;
	record = kind_88_ride_end_child_ADDRESS;
	*p_u = u_2;
	vector_spawn_child(object, record, p_u, &ignored16, &carry);
	*p_y = record;
}

/* Sets up an arm of the ride, unseen, at its place round the hub. */
uint16_t kind_88_ride_arm_start(uint16_t object)
{
	uint16_t hub = 0, setup = 0;
	uint8_t attributes = 0, action = 0, state = 0;

	setup = kind_88_ride_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->flags = 4u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0x10u;
	OBJECT(object)->timer = 1u;
	hub = kind_88_ride_arm_orbit(object);
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return hub;
}

/* Puts in the arm's two kind 88 riders, half a turn apart, counting them in field 3A. */
void kind_88_ride_arm_put_in_riders(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t angle = 0, riders_left = 0;
	uint16_t ignored16 = 0, rider = 0, rider_record = 0;
	uint8_t riders = 0, riders_on = 0, frame_offset = 0, t1 = 0;

	OBJECT(object)->kind_88_ride_arm.riders = 0u;
	OBJECT(object)->kind_88_ride_arm.riders_on = 0u;
	ride_parts_left = 2u;
	ride_part_angle = 0x40u;
	do
	{
		rider_record = kind_88_ride_arm_put_in_riders_child_ADDRESS;
		vector_spawn_child(object, rider_record, &rider, &ignored16, &carry);
		if (carry == 0u)
			break;
		riders = OBJECT(object)->kind_88_ride_arm.riders;
		OBJECT(object)->kind_88_ride_arm.riders = riders + 1u;
		riders_on = OBJECT(object)->kind_88_ride_arm.riders_on;
		OBJECT(object)->kind_88_ride_arm.riders_on = riders_on + 1u;
		OBJECT(rider)->kind_88.radius = 0x40u;
		angle = ride_part_angle;
		OBJECT(rider)->kind_88.angle = angle;
		ride_part_angle = angle - 0x80u;
		riders_left = ride_parts_left;
		OBJECT(rider)->kind_88.leave_turn = riders_left;
		frame_offset = OBJECT(object)->kind_88_ride_arm.frame_offset;
		OBJECT(rider)->kind_88.frame_offset = riders_left + frame_offset;
		OBJECT(rider)->timer = 1u;
		t1 = ride_parts_left;
		ride_parts_left = t1 - 1u;
	} while (t1 != 1u);
}

/* Puts in its riders, then waits until the hub starts the ride. */
uint16_t kind_88_ride_arm_wait_start(uint16_t object)
{
	uint16_t hub = 0;
	uint8_t action = 0, state = 0, state_2 = 0;
	uint16_t ride_hub = 0;

	action = OBJECT(object)->action;
	if (action != 0u)
	{
		OBJECT(object)->action = 0u;
		kind_88_ride_arm_put_in_riders(object);
	}
	ride_hub = OBJECT(object)->kind_88_ride_arm.ride_hub;
	hub = ride_hub;
	state = OBJECT(hub)->state;
	if (state == 2u)
	{
		OBJECT(object)->timer = 1u;
		state_2 = OBJECT(object)->state;
		OBJECT(object)->state = state_2 + 1u;
	}
	return hub;
}

/* Turns round the hub until the hub's next step. */
uint16_t kind_88_ride_arm_turn(uint16_t object)
{
	uint16_t hub = 0;
	uint8_t timer = 0, state = 0, state_2 = 0;
	uint16_t ride_hub = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->timer = 1u;
		kind_88_ride_arm_orbit(object);
	}
	ride_hub = OBJECT(object)->kind_88_ride_arm.ride_hub;
	hub = ride_hub;
	state = OBJECT(hub)->state;
	if (state == 3u)
	{
		OBJECT(object)->timer = 1u;
		OBJECT(object)->kind_88_ride_arm.turn_time = 0x40u;
		state_2 = OBJECT(object)->state;
		OBJECT(object)->state = state_2 + 1u;
	}
	return hub;
}

/* Turns round the hub for 64 frames more. */
uint16_t kind_88_ride_arm_turn_for_time(uint16_t object, uint16_t states)
{
	uint8_t timer = 0, turn_time = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return states;
	OBJECT(object)->timer = 1u;
	states = kind_88_ride_arm_orbit(object);
	turn_time = OBJECT(object)->kind_88_ride_arm.turn_time;
	OBJECT(object)->kind_88_ride_arm.turn_time = turn_time - 1u;
	if (turn_time == 1u)
	{
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
	return states;
}

/* Turns until both its riders are gone, then goes away, counted off the hub's arms. */
uint16_t kind_88_ride_arm_turn_until_empty(uint16_t object, uint16_t hub)
{
	uint8_t timer = 0, riders = 0, arms = 0;
	uint16_t ride_hub = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->timer = 1u;
		hub = kind_88_ride_arm_orbit(object);
	}
	riders = OBJECT(object)->kind_88_ride_arm.riders;
	if (riders == 0u)
	{
		ride_hub = OBJECT(object)->kind_88_ride_arm.ride_hub;
		hub = ride_hub;
		arms = OBJECT(hub)->kind_88_ride.arms;
		OBJECT(hub)->kind_88_ride.arms = arms - 1u;
		OBJECT(object)->flags = 0u;
	}
	return hub;
}

/* Moves the arm one step round the hub (its angle in field 3E, its radius in 3F). */
uint16_t kind_88_ride_arm_orbit(uint16_t object)
{
	uint16_t angle_and_radius = 0, hub = 0;
	uint16_t ride_hub = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	ride_hub = OBJECT(object)->kind_88_ride_arm.ride_hub;
	hub = ride_hub;
	t1 = (((uint32_t)OBJECT(object)->kind_88_ride_arm.angle << 8u) | OBJECT(object)->kind_88_ride_arm.radius);
	angle_and_radius = (t1 & 0xFFu) | ((uint32_t)(uint8_t)((t1 >> 8) - 1u) << 8);
	OBJECT(object)->kind_88_ride_arm.angle = angle_and_radius >> 8;
	orbit_offset(angle_and_radius);
	t2 = OBJECT(hub)->x;
	t3 = OBJECT(object)->x;
	OBJECT(object)->x_speed = (uint32_t)(uint8_t)(t2 + orbit_x_offset - t3) << 8;
	orbit_y_offset = (int16_t)orbit_y_offset >> 1;
	t4 = OBJECT(hub)->y;
	t5 = OBJECT(object)->y;
	OBJECT(object)->y_speed = (uint32_t)(uint8_t)(t4 + orbit_y_offset - t5) << 8;
	return hub;
}

/* Sends the piece flying up and away at a random speed, with one of two looks. */
uint16_t kind_88_piece_start(uint16_t object)
{
	uint8_t random = 0;
	uint16_t rider = 0, setup = 0;
	uint8_t attributes = 0, second_look = 0, state = 0;
	uint16_t parent = 0, t1 = 0, x_speed = 0;

	setup = kind_88_piece_setup_ADDRESS;
	vector_object_setup(object, setup);
	parent = OBJECT(object)->parent;
	rider = parent;
	attributes = OBJECT(rider)->attributes;
	OBJECT(object)->attributes = attributes & 0x30u;
	OBJECT(object)->flags = 0x88u;
	OBJECT(object)->z_speed = 0x400;
	random = random_number;
	OBJECT(object)->x_speed = 0x100u | random;
	if (random & 1u)
	{
		second_look = OBJECT(object)->kind_88_piece.second_look;
		OBJECT(object)->kind_88_piece.second_look = second_look + 1u;
		OBJECT(object)->animation = 0xB9u;
	}
	t1 = OBJECT(object)->x;
	if (t1 >= 0xE0u)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	face_movement(object);
	return rider;
}

/* Falls and lands, lying with its landed look. */
void kind_88_piece_fall(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t second_look = 0, state = 0;
	uint16_t z_speed = 0, t1 = 0;

	z_speed = OBJECT(object)->z_speed;
	t1 = z_speed - 0x18u;
	OBJECT(object)->z_speed = t1;
	carry = vector_check_landing(object);
	if (carry == 0u)
		return;
	second_look = OBJECT(object)->kind_88_piece.second_look;
	if (second_look == 0u)
		OBJECT(object)->animation = 0xBBu;
	else
		OBJECT(object)->animation = 0xBAu;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->timer = 0x20u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Blinks for 32 frames and goes away. */
void kind_88_piece_blink(uint16_t object)
{
	uint8_t timer = 0;

	OBJECT(object)->flags = (OBJECT(object)->flags ^ 0x80u) | 4u;
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
		OBJECT(object)->flags = 0u;
}

/* Beaten: goes away with sound 6C00, counted off the hub, shedding its piece. */
uint16_t kind_88_beaten(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0, hub = 0, ignored16 = 0, piece_record = 0;
	uint8_t riders_out = 0, riders_out_2 = 0, points = 0;
	uint16_t hub_2 = 0;

	command = 0x6C00u;
	carry = vector_queue_sound(command);
	hub_2 = OBJECT(object)->kind_88.hub;
	hub = hub_2;
	riders_out = OBJECT(hub)->kind_88_ride.riders_out;
	OBJECT(hub)->kind_88_ride.riders_out = riders_out - 1u;
	riders_out_2 = OBJECT(hub)->kind_88_ride.riders_out;
	if ((int8_t)riders_out_2 < 0)
		OBJECT(hub)->kind_88_ride.riders_out = 0u;
	OBJECT(object)->flags = 0u;
	points = OBJECT(object)->points;
	OBJECT(object)->points = points | 0x80u;
	piece_record = kind_88_beaten_child_ADDRESS;
	spawn_list_2_child(object, piece_record, &ignored16, &carry);
	return spawn_kind_90_effect(object);
}

/* Runs the enemy's knock-back by its substep, keeping it on screen. */
uint16_t kind_88_hit_steps(uint16_t object, uint16_t box)
{
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		kind_88_knocked(object);
		break;
	case 2:
		kind_88_knocked_fall(object);
		break;
	case 4:
		kind_88_knocked_wait();
		break;
	}
	return kind_88_keep_on_screen(object, box);
}

/* Gives the enemy its weak colour once its life is under 7. */
void kind_88_colour_by_health(uint16_t object)
{
	uint8_t healthy = 0;
	uint16_t attributes = 0;
	uint8_t vitality = 0, attributes_2 = 0;

	attributes = kind_88_attributes_by_health_ADDRESS;
	vitality = OBJECT(object)->vitality;
	if (vitality >= 7u)
		healthy = 1u;
	else
		healthy = 0u;
	attributes_2 = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes_2 & 0x30u) | KIND_88_ATTRIBUTES(attributes + healthy);
}

/* Knocked back: flies up and away with sound 6300. */
void kind_88_knocked(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t attributes = 0, blocked = 0, action_step = 0;
	uint16_t t1 = 0, x_speed = 0, x_speed_2 = 0;

	OBJECT(object)->animation = 0x84u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & ~0xFu) | 9u;
	OBJECT(object)->flags = 0x88u;
	OBJECT(object)->timer = 0x10u;
	OBJECT(object)->x_speed = 0x200;
	blocked = OBJECT(object)->blocked;
	if (blocked != 0u)
	{
		t1 = OBJECT(object)->x;
		if (t1 >= 0xE0u)
		{
			x_speed = OBJECT(object)->x_speed;
			OBJECT(object)->x_speed = 0u - x_speed;
		}
	}
	else if (random_number & 1u)
	{
		x_speed_2 = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed_2;
	}
	OBJECT(object)->z_speed = 0x200;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	command = 0x6300u;
	carry = vector_queue_sound(command);
}

/* Falls back (blinking at the end) and lands with sound 6B00. */
void kind_88_knocked_fall(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t timer = 0, timer_2 = 0, attributes = 0, animation_flags = 0, action_step = 0;
	uint16_t z_speed = 0, t1 = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	timer_2 = OBJECT(object)->timer;
	if (timer_2 > 0x10u)
		kind_88_colour_by_health(object);
	else
	{
		attributes = OBJECT(object)->attributes;
		OBJECT(object)->attributes = attributes ^ 0x80u;
		animation_flags = OBJECT(object)->animation_flags;
		OBJECT(object)->animation_flags = animation_flags | 0x80u;
	}
	z_speed = OBJECT(object)->z_speed;
	t1 = z_speed - 0x20u;
	OBJECT(object)->z_speed = t1;
	carry = vector_check_landing(object);
	if (carry == 0u)
	{
		kind_88_knocked_wait();
		return;
	}
	command = 0x6B00u;
	carry = vector_queue_sound(command);
	OBJECT(object)->animation = 0x83u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	kind_88_colour_by_health(object);
}

/* Does nothing after landing. */
void kind_88_knocked_wait(void)
{
}

/* Sets up a kind 88 rider, hidden, on its arm. */
uint16_t kind_88_start(uint16_t object)
{
	uint16_t arm = 0, box = 0, setup = 0;
	uint8_t entrance_pending = 0, attributes = 0, enemy_class = 0, action = 0, state = 0;
	uint16_t parent = 0, ride_hub = 0;

	setup = kind_88_setup_ADDRESS;
	box = vector_object_setup(object, setup);
	parent = OBJECT(object)->parent;
	arm = parent;
	ride_hub = OBJECT(arm)->kind_88_ride_arm.ride_hub;
	OBJECT(object)->kind_88.hub = ride_hub;
	OBJECT(object)->shadow_player = 1u;
	entrance_pending = OBJECT(object)->entrance_pending;
	OBJECT(object)->entrance_pending = entrance_pending + 1u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0x20u;
	OBJECT(object)->flags = 4u;
	enemy_class = OBJECT(object)->enemy_class;
	OBJECT(object)->enemy_class = enemy_class - 1u;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
	kind_88_follow_arm(object);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return box;
}

/* Waits on its arm until the ride starts. */
void kind_88_wait_ride(uint16_t object)
{
	uint16_t arm = 0;
	uint8_t action = 0, frame_offset = 0, state = 0, state_2 = 0;
	uint16_t parent = 0;

	action = OBJECT(object)->action;
	if (action != 0u)
	{
		frame_offset = OBJECT(object)->kind_88.frame_offset;
		OBJECT(object)->frame_time = frame_offset;
		OBJECT(object)->action = 0u;
	}
	parent = OBJECT(object)->parent;
	arm = parent;
	state = OBJECT(arm)->state;
	if (state != 2u)
		return;
	state_2 = OBJECT(object)->state;
	OBJECT(object)->state = state_2 + 1u;
	kind_88_follow_arm(object);
}

/* Shows the rider and follows its arm until the arm's next step. */
void kind_88_shown_on_ride(uint16_t object)
{
	uint16_t arm = 0;
	uint8_t timer = 0, state = 0, state_2 = 0;
	uint16_t parent = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->flags = 0x80u;
		OBJECT(object)->timer = 1u;
		kind_88_follow_arm(object);
	}
	parent = OBJECT(object)->parent;
	arm = parent;
	state = OBJECT(arm)->state;
	if (state == 3u)
	{
		OBJECT(object)->kind = 0x88u;
		OBJECT(object)->animation = 0x82u;
		state_2 = OBJECT(object)->state;
		OBJECT(object)->state = state_2 + 1u;
	}
}

/* Rides round with its arm until the arm turns for good. */
void kind_88_riding(uint16_t object)
{
	uint16_t arm = 0;
	uint8_t timer = 0, state = 0, state_2 = 0;
	uint16_t parent = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->timer = 1u;
		kind_88_follow_arm(object);
	}
	parent = OBJECT(object)->parent;
	arm = parent;
	state = OBJECT(arm)->state;
	if (state == 4u)
	{
		state_2 = OBJECT(object)->state;
		OBJECT(object)->state = state_2 + 1u;
	}
}

/* Moves the rider one step round its arm. */
void kind_88_follow_arm(uint16_t object)
{
	uint8_t angle = 0;
	uint16_t angle_and_radius = 0, arm = 0;
	uint8_t parameter = 0, angle_2 = 0, angle_3 = 0, radius = 0;
	uint16_t parent = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	parent = OBJECT(object)->parent;
	arm = parent;
	parameter = OBJECT(object)->parameter;
	if (parameter != 1u)
	{
		angle_2 = OBJECT(object)->kind_88.angle;
		angle = angle_2 + 2u;
	}
	else
	{
		angle_3 = OBJECT(object)->kind_88.angle;
		angle = angle_3 + 4u;
	}
	OBJECT(object)->kind_88.angle = angle;
	radius = OBJECT(object)->kind_88.radius;
	OBJECT(object)->kind_88.angle = angle;
	angle_and_radius = ((uint32_t)angle << 8) | radius;
	orbit_offset(angle_and_radius);
	t1 = OBJECT(arm)->x;
	t2 = OBJECT(object)->x;
	angle = (uint8_t)((((uint32_t)angle << 8) | (uint8_t)((((uint32_t)angle << 8) | (uint8_t)t1) + orbit_x_offset)) - t2);
	OBJECT(object)->x_speed = (uint32_t)angle << 8;
	orbit_y_offset = (int16_t)orbit_y_offset >> 1;
	orbit_y_offset = (int16_t)orbit_y_offset >> 1;
	t3 = OBJECT(arm)->y;
	t4 = OBJECT(object)->y;
	OBJECT(object)->y_speed = (uint32_t)(uint8_t)((((uint32_t)angle << 8) | (uint8_t)((((uint32_t)angle << 8) | (uint8_t)t3) + orbit_y_offset)) - t4) << 8;
}

/* Rides round until its turn comes with the arm at the front, then leaps off towards the players. */
uint16_t kind_88_leap_off(uint16_t object, uint16_t hub)
{
	uint16_t arm = 0;
	uint8_t riders = 0, leave_turn = 0, too_many_out = 0, angle = 0, angle_2 = 0, riders_on = 0, riders_out = 0, attributes = 0, state = 0;
	uint16_t parent = 0, hub_2 = 0, t1 = 0, x_speed = 0;

	kind_88_follow_arm(object);
	parent = OBJECT(object)->parent;
	arm = parent;
	riders = OBJECT(arm)->kind_88_ride_arm.riders;
	leave_turn = OBJECT(object)->kind_88.leave_turn;
	if (riders <= leave_turn)
	{
		hub_2 = OBJECT(object)->kind_88.hub;
		hub = hub_2;
		too_many_out = OBJECT(hub)->kind_88_ride.too_many_out;
		if (too_many_out == 0u)
		{
			angle = OBJECT(arm)->kind_88_ride_arm.angle;
			if ((uint8_t)(angle + 0x60u) < 0x40u)
			{
				angle_2 = OBJECT(object)->kind_88.angle;
				if ((angle_2 & 0x7Fu) < 8u)
					return hub;
				riders_on = OBJECT(arm)->kind_88_ride_arm.riders_on;
				OBJECT(arm)->kind_88_ride_arm.riders_on = riders_on - 1u;
				riders_out = OBJECT(hub)->kind_88_ride.riders_out;
				OBJECT(hub)->kind_88_ride.riders_out = riders_out + 1u;
				t1 = (uint32_t)random_number << 1;
				OBJECT(object)->x_speed = t1;
				if (random_number & 1u)
				{
					x_speed = OBJECT(object)->x_speed;
					OBJECT(object)->x_speed = 0u - x_speed;
				}
				OBJECT(object)->y_speed = -0x200;
				OBJECT(object)->z_speed = 0x400;
				OBJECT(object)->flags = 0xCCu;
				OBJECT(object)->entrance_pending = 0u;
				attributes = OBJECT(object)->attributes;
				OBJECT(object)->attributes = (attributes & 0xCFu) | 0x10u;
				state = OBJECT(object)->state;
				OBJECT(object)->state = state + 1u;
				hub = kind_88_leap_off_box_ADDRESS;
				vector_set_hit_box(object, hub);
				OBJECT(object)->box_dz = 0x30u;
			}
		}
	}
	return hub;
}

/* Lands with sound 6B00, counted off its arm, and is in play. */
void kind_88_leap_land(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t arm = 0, command = 0;
	uint8_t riders = 0, state = 0;
	uint16_t z_speed = 0, t1 = 0, parent = 0;

	z_speed = OBJECT(object)->z_speed;
	t1 = z_speed - 0x20u;
	OBJECT(object)->z_speed = t1;
	carry = vector_check_landing(object);
	if (carry == 0u)
		return;
	command = 0x6B00u;
	carry = vector_queue_sound(command);
	parent = OBJECT(object)->parent;
	arm = parent;
	riders = OBJECT(arm)->kind_88_ride_arm.riders;
	OBJECT(arm)->kind_88_ride_arm.riders = riders - 1u;
	OBJECT(object)->animation = 0x80u;
	OBJECT(object)->enemy_class = 0;
	OBJECT(object)->flags = 0xC0u;
	OBJECT(object)->box_dz = 0x10u;
	OBJECT(object)->timer = 0x40u;
	OBJECT(object)->blocked = 0u;
	OBJECT(object)->parameter = 0u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Takes its standing hit box. */
uint16_t kind_88_ready(uint16_t object)
{
	uint16_t box = 0;
	uint8_t state = 0;

	box = kind_88_body_box_ADDRESS;
	vector_set_hit_box(object, box);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return kind_88_ready_wait(object, box);
}

/* After 64 frames faces the nearest player and starts fighting. */
uint16_t kind_88_ready_wait(uint16_t object, uint16_t box)
{
	uint16_t target = 0;
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return kind_88_keep_on_screen(object, box);
	OBJECT(object)->animation = 0x81u;
	target = vector_choose_nearest_player(object);
	vector_measure_target(object, target);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	OBJECT(object)->action_step = 0u;
	return kind_88_keep_on_screen(object, box);
}

/* Turns the enemy back with a hop when it goes off the screen's sides, and off walls up and down. */
uint16_t kind_88_keep_on_screen(uint16_t object, uint16_t box)
{
	uint32_t negative = 0;
	uint8_t floor_value = 0, random = 0;
	uint16_t floor_cell = 0;
	uint8_t blocked = 0;
	uint16_t t1 = 0, t2 = 0, y_speed = 0, x_speed = 0, x_speed_2 = 0, y_speed_2 = 0;

	t1 = OBJECT(object)->x;
	t2 = t1 - 0x40u;
	if (t2 < 0x140u)
		OBJECT(object)->blocked = 0u;
	else
	{
		blocked = OBJECT(object)->blocked;
		if (blocked != 0u)
		{
			vector_floor_ahead_y(object, &floor_cell, &negative);
			floor_value = (uint8_t)(floor_cell >> 8);
			if ((int8_t)floor_value < 0)
			{
				y_speed = OBJECT(object)->y_speed;
				OBJECT(object)->y_speed = 0u - y_speed;
			}
			return box;
		}
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = (int16_t)x_speed >> 1;
		x_speed_2 = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed_2;
		OBJECT(object)->blocked = 1u;
		random = random_number;
		OBJECT(object)->y_speed = 0xFF00u | random;
		if ((int8_t)random >= 0)
		{
			y_speed_2 = OBJECT(object)->y_speed;
			OBJECT(object)->y_speed = 0u - y_speed_2;
		}
		OBJECT(object)->z_speed = 0x200;
		OBJECT(object)->flags = 0x88u;
		OBJECT(object)->state = 9u;
		box = kind_88_body_box_ADDRESS;
		vector_set_hit_box(object, box);
		OBJECT(object)->animation = 0x81u;
	}
	vector_floor_ahead_y(object, &floor_cell, &negative);
	floor_value = (uint8_t)(floor_cell >> 8);
	if ((int8_t)floor_value < 0)
	{
		y_speed = OBJECT(object)->y_speed;
		OBJECT(object)->y_speed = 0u - y_speed;
	}
	return box;
}

/* Runs the kind 88 enemy's fight by its substep, keeping track of the nearest player. */
void kind_88_fight_steps(uint16_t object, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t ignored16 = 0, target = 0;
	uint8_t action_step = 0;
	uint16_t target_2 = 0;

	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		kind_88_switch_side(object);
		break;
	case 2:
		kind_88_approach(object);
		break;
	case 4:
		kind_88_charge(object);
		break;
	case 6:
		y = kind_88_charge_hit(object);
		break;
	case 8:
		vector_goon_start(object, &y, &ignored16);
		break;
	case 12:
	case 24:
	case 86:
		vector_enemy_think(object, &y, &ignored16, p_left_caller);
		break;
	case 14:
	case 26:
	case 88:
		vector_enemy_act(object, &y, &ignored16, p_left_caller);
		break;
	case 16:
	case 28:
	case 90:
		enemy_hurt(object, &y, &ignored16);
		break;
	case 18:
	case 30:
	case 92:
		vector_enemy_climb(object, &y, &ignored16, p_left_caller);
		break;
	case 20:
		kind_98_start(object, &y, &ignored16);
		break;
	case 22:
		kind_98_entrance_steps(object, &y, &ignored16);
		break;
	}
	if ((frame_count & 0xFu) == 0u)
		vector_choose_nearest_player(object);
	target_2 = OBJECT(object)->target;
	target = target_2;
	vector_measure_target(object, target);
	y = kind_88_keep_on_screen(object, y);
	*p_y = y;
}

/* Switches the side it comes at its target from. */
void kind_88_switch_side(uint16_t object)
{
	uint8_t approach_side = 0, action_step = 0;

	approach_side = OBJECT(object)->kind_88.approach_side;
	OBJECT(object)->kind_88.approach_side = approach_side ^ 0x80u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Walks towards its target, first across then up or down, and stops when close. */
void kind_88_approach(uint16_t object)
{
	uint8_t approach_side = 0, target_direction = 0, approach_side_2 = 0, action_step = 0, target_direction_2 = 0;
	uint16_t target_dx = 0, x_speed = 0, target_dy = 0, y_speed = 0;

	target_dx = OBJECT(object)->target_dx;
	if (target_dx < 0x40u)
	{
		OBJECT(object)->y_speed = 0;
		OBJECT(object)->x_speed = 0x100;
		approach_side = OBJECT(object)->kind_88.approach_side;
		if ((int8_t)approach_side < 0)
		{
			x_speed = OBJECT(object)->x_speed;
			OBJECT(object)->x_speed = 0u - x_speed;
		}
	}
	else
	{
		target_direction = OBJECT(object)->target_direction;
		approach_side_2 = OBJECT(object)->kind_88.approach_side;
		if ((int8_t)(target_direction - 0x40u - approach_side_2) < 0)
		{
			OBJECT(object)->y_speed = 0;
			OBJECT(object)->x_speed = 0x100;
			approach_side = OBJECT(object)->kind_88.approach_side;
			if ((int8_t)approach_side < 0)
			{
				x_speed = OBJECT(object)->x_speed;
				OBJECT(object)->x_speed = 0u - x_speed;
			}
			target_dy = OBJECT(object)->target_dy;
			if (target_dy < 3u)
			{
				OBJECT(object)->timer = 0x10u;
				OBJECT(object)->animation = 0x82u;
				OBJECT(object)->x_speed = 0;
				OBJECT(object)->y_speed = 0;
				action_step = OBJECT(object)->action_step;
				OBJECT(object)->action_step = action_step + 1u;
			}
			return;
		}
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0x100;
		target_direction_2 = OBJECT(object)->target_direction;
		if ((int8_t)target_direction_2 < 0)
		{
			y_speed = OBJECT(object)->y_speed;
			OBJECT(object)->y_speed = 0u - y_speed;
		}
	}
	target_dy = OBJECT(object)->target_dy;
	if (target_dy < 3u)
	{
		OBJECT(object)->timer = 0x10u;
		OBJECT(object)->animation = 0x82u;
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* After a moment, charges at its target. */
void kind_88_charge(uint16_t object)
{
	uint8_t timer = 0, blocked = 0, action_step = 0, target_direction = 0, attributes = 0, action_step_2 = 0;
	uint16_t t1 = 0, x_speed = 0, x_speed_2 = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->x_speed = 0x300;
	blocked = OBJECT(object)->blocked;
	if (blocked != 0u)
	{
		t1 = OBJECT(object)->x;
		if (t1 >= 0xE0u)
		{
			x_speed = OBJECT(object)->x_speed;
			OBJECT(object)->x_speed = 0u - x_speed;
		}
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
		return;
	}
	target_direction = OBJECT(object)->target_direction;
	if ((int8_t)(target_direction - 0x40u) >= 0)
	{
		x_speed_2 = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed_2;
	}
	face_movement(object);
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = attributes ^ 0x40u;
	action_step_2 = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step_2 + 1u;
}

/* Puts out the charging hit box one frame in eight. */
uint16_t kind_88_charge_hit(uint16_t object)
{
	uint16_t box = 0;
	uint8_t timer = 0, timer_2 = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	timer_2 = OBJECT(object)->timer;
	if ((timer_2 & 7u) != 0u)
	{
		box = kind_88_body_box_ADDRESS;
		vector_set_hit_box(object, box);
		return box;
	}
	box = kind_88_leap_off_box_ADDRESS;
	vector_set_hit_box(object, box);
	return box;
}

/* Lands from its hop with sound 6B00. */
uint16_t kind_88_hop_land(uint16_t object, uint16_t box)
{
	uint32_t carry = 0;
	uint16_t command = 0, ignored16 = 0;
	uint8_t state = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	if (carry == 0u)
		return kind_88_keep_on_screen(object, box);
	kind_88_colour_by_health(object);
	command = 0x6B00u;
	carry = vector_queue_sound(command);
	OBJECT(object)->timer = 0x40u;
	OBJECT(object)->flags = 0xC0u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return kind_88_keep_on_screen(object, box);
}

/* After 64 frames, gets ready to fight again. */
uint16_t kind_88_hop_wait(uint16_t object, uint16_t box)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->timer = 0x10u;
		OBJECT(object)->state = 7u;
	}
	return kind_88_keep_on_screen(object, box);
}
