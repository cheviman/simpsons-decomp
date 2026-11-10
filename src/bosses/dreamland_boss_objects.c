/**
 *    Name:        bosses/dreamland_boss_objects.c
 *    Description: the Dreamland boss's balls, their trail, its shadow, its chain and the kind BB chain holder
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Stops the ball that has hit something and bursts it with a sound. */
void boss_ball_burst(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t state = 0;

	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->z_speed = 0;
	command = 0x6C00u;
	carry = vector_queue_sound(command);
	OBJECT(object)->kind = 4u;
	OBJECT(object)->animation = 0x80u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Sets the spat ball up with its speed and time from object_1a_launches, the way the boss faces, with a
   sound, aimed at the nearest player. */
uint16_t boss_ball_setup(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0, setup = 0, start = 0, u = 0;
	uint8_t attributes = 0, time = 0, attributes_2 = 0, state = 0;
	uint16_t x_speed = 0;

	setup = boss_ball_object_setup_ADDRESS;
	vector_object_setup(object, setup);
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0x10u;
	OBJECT(object)->flags = 0xC8u;
	OBJECT(object)->zoom_x = 0x40u;
	OBJECT(object)->zoom_y = 0x40u;
	start = object_1a_launches_ADDRESS + (uint8_t)((random_number & 3u) << 1);
	OBJECT(object)->x_speed = (uint32_t)LAUNCH(start)->speed << 8;
	time = LAUNCH(start)->time;
	OBJECT(object)->timer = time;
	OBJECT(object)->boss_ball.heading = 0u;
	attributes_2 = OBJECT(object)->attributes;
	if ((attributes_2 & 0x40u) != 0u)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
		OBJECT(object)->boss_ball.heading = 0x80u;
	}
	command = 0x1D00u;
	carry = vector_queue_sound(command);
	u = vector_choose_nearest_player(object);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return u;
}

/* Flies the ball out, leaving a trail and rising unless near its player; then takes the turn toward him. */
uint16_t boss_ball_fly_out(uint16_t object, uint16_t target_player)
{
	uint32_t carry = 0;
	uint8_t angle = 0, timer = 0;
	uint16_t child_record = 0, direction = 0, ignored16 = 0, ignored16_2 = 0;
	uint8_t timer_2 = 0, heading = 0, state = 0, timer_3 = 0;
	uint16_t target = 0, target_2 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, z_speed = 0, t6 = 0;

	timer_2 = OBJECT(object)->timer;
	OBJECT(object)->timer = timer_2 - 1u;
	if (timer_2 == 1u)
	{
		target = OBJECT(object)->target;
		target_player = target;
		direction = vector_direction_to(object, target_player);
		angle = (uint8_t)(direction >> 8);
		OBJECT(object)->target_direction = angle;
		heading = OBJECT(object)->boss_ball.heading;
		angle = (int8_t)((int8_t)((int8_t)(angle - heading) >> 1) >> 1) >> 1;
		OBJECT(object)->boss_ball.turn = angle;
		if (angle >= 2u)
			timer = 0xAu;
		else
			timer = 1u;
		OBJECT(object)->timer = timer;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
	timer_3 = OBJECT(object)->timer;
	if ((timer_3 & 1u) != 0u)
		return target_player;
	child_record = boss_ball_fly_out_child_ADDRESS;
	vector_spawn_child(object, child_record, &ignored16, &ignored16_2, &carry);
	target_2 = OBJECT(object)->target;
	target_player = target_2;
	t1 = OBJECT(target_player)->x;
	t2 = OBJECT(object)->x;
	t3 = t1 - t2;
	t4 = t3;
	t5 = t4 >> 15 ? 0u - t4 : t4;
	if (t5 >= 0x20u)
	{
		z_speed = OBJECT(object)->z_speed;
		t6 = z_speed + 0x40u;
		OBJECT(object)->z_speed = t6;
	}
	return target_player;
}

/* Turns the ball toward its player a little each frame and brings it down, leaving a trail, until it
   lands. */
uint16_t boss_ball_home_in(uint16_t object, uint16_t states)
{
	uint32_t carry = 0;
	uint8_t heading_2 = 0;
	uint16_t child_record = 0, heading = 0, ignored16 = 0, target_player = 0;
	uint8_t timer = 0, target_direction = 0, state = 0, timer_2 = 0, state_2 = 0, heading_3 = 0, turn = 0;
	uint16_t target = 0, z_speed = 0, t1 = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->timer = 0x40u;
		target = OBJECT(object)->target;
		target_player = target;
		target_direction = OBJECT(object)->target_direction;
		heading = ((uint32_t)target_direction << 8) | 0x80u;
		vector_set_speed_by_direction(object, heading);
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
		return boss_ball_land(object, target_player);
	}
	timer_2 = OBJECT(object)->timer;
	if ((timer_2 & 1u) == 0u)
	{
		child_record = boss_ball_fly_out_child_ADDRESS;
		vector_spawn_child(object, child_record, &states, &ignored16, &carry);
	}
	z_speed = OBJECT(object)->z_speed;
	t1 = z_speed - 0x80u;
	OBJECT(object)->z_speed = t1;
	carry = vector_check_landing(object);
	if (carry)
	{
		OBJECT(object)->timer = 0x20u;
		state_2 = OBJECT(object)->state;
		OBJECT(object)->state = state_2 + 1u;
	}
	heading_3 = OBJECT(object)->boss_ball.heading;
	turn = OBJECT(object)->boss_ball.turn;
	heading_2 = heading_3 + turn;
	OBJECT(object)->boss_ball.heading = heading_2;
	heading = ((uint32_t)heading_2 << 8) | 0x40u;
	vector_set_speed_by_direction(object, heading);
	return states;
}

/* Pulls the ball down; where it lands, or when its time is up, it bursts with its hit box and a sound. */
uint16_t boss_ball_land(uint16_t object, uint16_t u)
{
	uint32_t negative = 0, carry = 0;
	uint16_t command = 0, floor_cell = 0, ignored16 = 0, record = 0;
	uint8_t state = 0, timer = 0, timer_2 = 0;
	uint16_t z_speed = 0;

	z_speed = OBJECT(object)->z_speed;
	OBJECT(object)->z_speed = z_speed - 0x20u;
	carry = vector_check_landing(object);
	if (carry)
	{
		floor_cell = 0u;
		vector_floor_at_offset(object, &floor_cell, &negative);
		if ((int8_t)(floor_cell >> 8) < 0)
		{
			OBJECT(object)->x_speed = 0;
			OBJECT(object)->y_speed = 0;
			OBJECT(object)->z_speed = 0;
			command = 0x6C00u;
			carry = vector_queue_sound(command);
			OBJECT(object)->kind = 4u;
			OBJECT(object)->animation = 0x80u;
			state = OBJECT(object)->state;
			OBJECT(object)->state = state + 1u;
			return u;
		}
	}
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
	{
		timer_2 = OBJECT(object)->timer;
		if ((((uint16_t)((uint32_t)timer_2 << 8) >> 8) & 1u) == 0u)
		{
			record = boss_ball_fly_out_child_ADDRESS;
			vector_spawn_child(object, record, &u, &ignored16, &carry);
		}
		return u;
	}
	record = boss_ball_land_box_ADDRESS;
	vector_set_hit_box(object, record);
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->z_speed = 0;
	command = 0x6C00u;
	carry = vector_queue_sound(command);
	OBJECT(object)->kind = 4u;
	OBJECT(object)->animation = 0x80u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return u;
}

/* Makes the ball's burst harmless. */
void boss_ball_burst_out(uint16_t object)
{
	uint8_t state = 0;

	OBJECT(object)->flags = 0x80u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	boss_ball_remove(object);
}

/* Frees the ball's slot when its burst ends. */
void boss_ball_remove(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
		OBJECT(object)->flags = 0u;
}

/* Sets the trail's puff up. */
void boss_ball_trail_setup(uint16_t object, uint16_t *p_y, uint16_t *p_setup)
{
	uint16_t setup = 0, y = 0;
	uint8_t state = 0;

	setup = boss_ball_trail_object_setup_ADDRESS;
	y = vector_object_setup(object, setup);
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->attributes = 0x10u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	*p_y = y;
	*p_setup = setup;
}

/* Frees the puff's slot when its animation ends. */
void boss_ball_trail_fade(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
		OBJECT(object)->flags = 0u;
}

/* Sets the boss's shadow up. */
void dreamland_boss_shadow_setup(uint16_t object, uint16_t *p_y, uint16_t *p_setup)
{
	uint16_t setup = 0, y = 0;
	uint8_t state = 0;

	setup = dreamland_boss_shadow_object_setup_ADDRESS;
	y = vector_object_setup(object, setup);
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->attributes = 0x10u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	*p_y = y;
	*p_setup = setup;
}

/* Keeps the shadow under the boss (field 40); it goes when the boss's second form ends (its step 0A). */
uint16_t dreamland_boss_shadow_follow(uint16_t object)
{
	uint16_t boss = 0;
	uint8_t state = 0;
	uint16_t chain = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	chain = OBJECT(object)->dreamland_boss.chain;
	boss = chain;
	state = OBJECT(boss)->state;
	if ((uint16_t)((uint32_t)state << 8) >> 8 == 0xAu)
	{
		OBJECT(object)->flags = 0u;
		return boss;
	}
	t1 = OBJECT(boss)->x;
	t2 = OBJECT(object)->x;
	OBJECT(object)->x_speed = (uint32_t)(uint8_t)(t1 - t2) << 8;
	t3 = OBJECT(boss)->y;
	t4 = OBJECT(object)->y;
	OBJECT(object)->y_speed = (uint32_t)(uint8_t)(t3 - t4) << 8;
	return boss;
}

/* Sets the kind BB chain holder up with a 128 frames' wait. */
uint16_t chain_holder_setup(uint16_t object)
{
	uint16_t setup = 0, y = 0;
	uint8_t state = 0;

	setup = chain_holder_object_setup_ADDRESS;
	y = vector_object_setup(object, setup);
	OBJECT(object)->timer = 0x80u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return y;
}

/* Counts the wait down, then sets direct page 7C and puts out its chain of balls (4F80 type FF), held by
   it. */
uint16_t chain_holder_put_out_chain(uint16_t object, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t chain = 0, child_record = 0, ignored16 = 0;
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return y;
	boss_arrived = 1u;
	child_record = chain_holder_put_out_chain_child_ADDRESS;
	vector_spawn_child(object, child_record, &chain, &ignored16, &carry);
	if (carry)
		OBJECT(chain)->target = object;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return child_record;
}

/* Every 256 frames starts its animation again and faces the nearest player. */
void chain_holder_watch(uint16_t object)
{
	uint8_t attributes = 0;
	uint16_t nearest_player = 0;
	uint8_t animation = 0;
	uint16_t t1 = 0, t2 = 0;

	if ((uint8_t)frame_count != 0u)
		return;
	animation = OBJECT(object)->animation;
	OBJECT(object)->animation = animation | 0x80u;
	nearest_player = vector_choose_nearest_player(object);
	t1 = OBJECT(object)->x;
	t2 = OBJECT(nearest_player)->x;
	if (t2 <= t1)
		attributes = 0x40u;
	else
		attributes = 0u;
	OBJECT(object)->attributes = attributes;
}

/* Turns the chain's piece over when its holder (field 38) turns. */
uint16_t dreamland_boss_chain_follow_facing(uint16_t object)
{
	uint8_t attributes = 0, leap_distance = 0;
	uint16_t holder = 0;
	uint8_t attributes_2 = 0, leap_distance_2 = 0, attributes_3 = 0;
	uint16_t target = 0;

	target = OBJECT(object)->target;
	holder = target;
	attributes_2 = OBJECT(holder)->attributes;
	leap_distance = attributes_2;
	leap_distance_2 = OBJECT(object)->dreamland_boss_chain.leap_distance;
	if (leap_distance == leap_distance_2)
		return holder;
	OBJECT(object)->dreamland_boss_chain.leap_distance = leap_distance;
	attributes_3 = OBJECT(object)->attributes;
	attributes = attributes_3;
	if ((int8_t)leap_distance >= 0)
		attributes &= 0x7Fu;
	else
		attributes |= 0x83u;
	OBJECT(object)->attributes = attributes;
	OBJECT(object)->animation_flags = 0x80u;
	return holder;
}

/* The chain's piece bursting, by field 29. */
uint16_t dreamland_boss_chain_pop(uint16_t object, uint16_t y)
{
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		dreamland_boss_chain_pop_start(object);
		break;
	case 2:
		y = dreamland_boss_chain_pop_next(object, y);
		break;
	case 4:
		dreamland_boss_chain_pop_end(object);
		break;
	}
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->z_speed = 0;
	return y;
}

/* Bursts the piece with a sound. */
void dreamland_boss_chain_pop_start(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t action_step = 0;

	command = 0x6C00u;
	carry = vector_queue_sound(command);
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->kind = 0xD1u;
	OBJECT(object)->animation = 0x85u;
	OBJECT(object)->timer = 4u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Four frames later bursts the piece next to it (field 2E). */
uint16_t dreamland_boss_chain_pop_next(uint16_t object, uint16_t link)
{
	uint8_t timer = 0, action_step = 0;
	uint16_t previous_link = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		previous_link = OBJECT(object)->dreamland_boss_chain.previous_link;
		link = previous_link;
		OBJECT(link)->state = 0xFEu;
		OBJECT(object)->timer = 4u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
	return link;
}

/* Frees the piece's slot four frames later. */
void dreamland_boss_chain_pop_end(uint16_t object)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
		OBJECT(object)->flags = 0u;
}

/* Sets the chain's base up and builds the chain: its links (type FF, step 2) and its head (type FE),
   each tied to the next and the one before, held by the base's holder; with no room for the head the
   chain is not made. */
uint16_t dreamland_boss_chain_setup(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t list = 0, piece_state = 0, piece_type = 0;
	uint16_t holder = 0, piece = 0, previous_piece = 0, setup = 0;
	uint8_t attributes = 0, state = 0, t3 = 0;
	uint16_t target = 0, t1 = 0, t2 = 0, z = 0, target_2 = 0, t4 = 0, t5 = 0, target_dx = 0, t6 = 0;
	uint32_t type_halfword = 0, type_halfword_2 = 0;

	setup = dreamland_boss_chain_object_setup_ADDRESS;
	vector_object_setup(object, setup);
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0x10u;
	OBJECT(object)->flags = 4u;
	OBJECT(object)->enemy_class = -1;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	chain_pieces_left = 0x16u;
	OBJECT(object)->dreamland_boss_chain.next_direction = 0u;
	OBJECT(object)->dreamland_boss_chain.next_distance = 2u;
	OBJECT(object)->dreamland_boss_chain.queued_direction = 0u;
	OBJECT(object)->target_direction = 2u;
	OBJECT(object)->dreamland_boss_chain.lead_attributes = 2u;
	OBJECT(object)->dreamland_boss_chain.direction = 2u;
	OBJECT(object)->dreamland_boss_chain.legs_left = 0x10u;
	target = OBJECT(object)->target;
	holder = target;
	OBJECT(object)->dreamland_boss_chain.previous_link = holder;
	OBJECT(object)->dreamland_boss_chain.chain_base = object;
	list = 2u;
	vector_find_free_slot(list, &piece, &carry);
	if (carry == 0u)
	{
		OBJECT(object)->flags = 0u;
		return holder;
	}
	chain_head_link = piece;
	previous_piece = object;
	do
	{
		if (chain_pieces_left == 1u)
		{
			piece = chain_head_link;
			piece_type = 0xFEu;
			piece_state = 0u;
			type_halfword = ((uint32_t)piece_type << 8) | piece_state;
			OBJECT(piece)->type = (uint8_t)(type_halfword >> 8u);
			OBJECT(piece)->state = (uint8_t)type_halfword;
			OBJECT(object)->dreamland_boss_chain.lead_attributes = 0u;
			t1 = OBJECT(previous_piece)->x;
			OBJECT(piece)->x = t1;
			t2 = OBJECT(previous_piece)->y;
			OBJECT(piece)->y = t2;
			z = OBJECT(previous_piece)->z;
			OBJECT(piece)->z = z;
			OBJECT(piece)->unk_3E = 0u;
			OBJECT(piece)->unk_3F = 2u;
			OBJECT(piece)->unk_35 = 0u;
			OBJECT(piece)->target_direction = 2u;
			OBJECT(piece)->unk_37 = 0u;
			OBJECT(piece)->unk_3C = 0x10u;
			target_2 = OBJECT(object)->target;
			OBJECT(piece)->target = target_2;
			OBJECT(piece)->behaviour = object;
			OBJECT(piece)->target_dy = previous_piece;
			OBJECT(previous_piece)->target_dx = piece;
			OBJECT(piece)->unk_50 = 0u;
			OBJECT(piece)->unk_51 = 0u;
			OBJECT(piece)->unk_52 = 0u;
			OBJECT(piece)->unk_53 = 0u;
			OBJECT(piece)->unk_32 = chain_pieces_left;
			previous_piece = piece;
		}
		else
		{
			find_free_object_from_4d40(&piece, &carry);
			if (carry)
			{
				piece_type = 0xFFu;
				piece_state = 2u;
				type_halfword_2 = ((uint32_t)piece_type << 8) | piece_state;
				OBJECT(piece)->type = (uint8_t)(type_halfword_2 >> 8u);
				OBJECT(piece)->state = (uint8_t)type_halfword_2;
				OBJECT(object)->dreamland_boss_chain.lead_attributes = 0u;
				t1 = OBJECT(previous_piece)->x;
				OBJECT(piece)->x = t1;
				t2 = OBJECT(previous_piece)->y;
				OBJECT(piece)->y = t2;
				z = OBJECT(previous_piece)->z;
				OBJECT(piece)->z = z;
				OBJECT(piece)->unk_3E = 0u;
				OBJECT(piece)->unk_3F = 2u;
				OBJECT(piece)->unk_35 = 0u;
				OBJECT(piece)->target_direction = 2u;
				OBJECT(piece)->unk_37 = 0u;
				OBJECT(piece)->unk_3C = 0x10u;
				target_2 = OBJECT(object)->target;
				OBJECT(piece)->target = target_2;
				OBJECT(piece)->behaviour = object;
				OBJECT(piece)->target_dy = previous_piece;
				OBJECT(previous_piece)->target_dx = piece;
				OBJECT(piece)->unk_50 = 0u;
				OBJECT(piece)->unk_51 = 0u;
				OBJECT(piece)->unk_52 = 0u;
				OBJECT(piece)->unk_53 = 0u;
				OBJECT(piece)->unk_32 = chain_pieces_left;
				previous_piece = piece;
			}
		}
		t3 = chain_pieces_left;
		chain_pieces_left = t3 - 1u;
	} while (t3 != 1u);
	piece = dreamland_boss_chain_link_parameters_ADDRESS;
	previous_piece = object;
	do
	{
		t4 = chain_head_link;
		OBJECT(previous_piece)->parent = t4;
		t5 = piece;
		piece = t5 + 1u;
		OBJECT(previous_piece)->parameter = OBJECT(t5)->flags;
		target_dx = OBJECT(previous_piece)->target_dx;
		previous_piece = target_dx;
	} while (previous_piece != chain_head_link);
	t6 = chain_head_link;
	OBJECT(previous_piece)->parent = t6;
	OBJECT(previous_piece)->parameter = OBJECT(piece)->flags;
	return previous_piece;
}

/* Unused: does nothing. */
void unused_dreamland_boss_chain_no_op(void)
{
}

/* Keeps the chain's base at its holder and draws the next piece after it, at the offset its direction
   and distance give. */
uint16_t dreamland_boss_chain_lead(uint16_t object)
{
	uint16_t direction_and_distance = 0, next_link = 0;
	uint8_t attributes = 0, direction = 0, next_direction = 0, queued_direction = 0;
	uint16_t next_link_2 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, z = 0, z_2 = 0;

	attributes = OBJECT(object)->attributes;
	OBJECT(object)->dreamland_boss_chain.lead_attributes = (uint16_t)((uint32_t)attributes << 8) >> 8;
	next_link_2 = OBJECT(object)->dreamland_boss_chain.next_link;
	next_link = next_link_2;
	t1 = (((uint32_t)OBJECT(object)->dreamland_boss_chain.next_direction << 8u) | OBJECT(object)->dreamland_boss_chain.next_distance);
	direction_and_distance = t1;
	OBJECT(next_link)->dreamland_boss_chain.queued_direction = direction_and_distance >> 8;
	direction = OBJECT(object)->dreamland_boss_chain.direction;
	direction_and_distance = (direction_and_distance & 0xFFu) | ((uint32_t)direction << 8);
	chain_link_offset(direction_and_distance);
	OBJECT(object)->dreamland_boss_chain.next_dx = chain_link_dx;
	OBJECT(object)->dreamland_boss_chain.next_dz = chain_link_dz;
	t2 = OBJECT(object)->x;
	t3 = OBJECT(next_link)->x;
	OBJECT(next_link)->x_speed = (uint32_t)(uint8_t)(t2 + chain_link_dx - t3) << 8;
	t4 = OBJECT(object)->y;
	t5 = OBJECT(next_link)->y;
	OBJECT(next_link)->y_speed = (uint32_t)(uint8_t)(t4 - 2u - t5) << 8;
	z = OBJECT(object)->z;
	z_2 = OBJECT(next_link)->z;
	OBJECT(next_link)->z_speed = (uint32_t)(uint8_t)(z + chain_link_dz - z_2) << 8;
	next_direction = OBJECT(object)->dreamland_boss_chain.next_direction;
	OBJECT(object)->dreamland_boss_chain.direction = (uint16_t)((uint32_t)next_direction << 8) >> 8;
	queued_direction = OBJECT(object)->dreamland_boss_chain.queued_direction;
	OBJECT(object)->dreamland_boss_chain.next_direction = (uint16_t)((uint32_t)queued_direction << 8) >> 8;
	dreamland_boss_chain_stay_at_holder(object);
	return next_link;
}

/* Moves the chain's x offset from its holder (work RAM 1888, from -16 to 15) a step toward the side the
   holder faces. */
void dreamland_boss_chain_shift_offset(uint16_t object)
{
	uint16_t offset = 0;
	uint8_t attributes = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = io_read16(0x1888u);
	chain_offset_biased = t1 + 0x10u;
	attributes = OBJECT(object)->attributes;
	if ((((uint16_t)((uint32_t)attributes << 8) >> 8) & 0x40u) != 0u)
	{
		offset = chain_offset_biased + 1u;
		if (offset >= 0x20u)
			return;
		io_write16(0x1888u, offset - 0x10u);
		return;
	}
	t2 = chain_offset_biased - 1u;
	offset = t2;
	if ((int16_t)t2 < 0)
		return;
	io_write16(0x1888u, offset - 0x10u);
}

/* Sets the base's speeds to bring it to its holder's mouth: the holder's place plus the x offset, 48 up. */
void dreamland_boss_chain_stay_at_holder(uint16_t object)
{
	uint16_t holder = 0;
	uint16_t target = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, z = 0, z_2 = 0;

	target = OBJECT(object)->target;
	holder = target;
	dreamland_boss_chain_shift_offset(holder);
	t1 = OBJECT(holder)->x;
	t2 = io_read16(0x1888u);
	t3 = OBJECT(object)->x;
	OBJECT(object)->x_speed = (uint32_t)(uint8_t)(t1 + t2 - t3) << 8;
	t4 = OBJECT(holder)->y;
	t5 = OBJECT(object)->y;
	OBJECT(object)->y_speed = (uint32_t)(uint8_t)(t4 - 2u - t5) << 8;
	z = OBJECT(holder)->z;
	z_2 = OBJECT(object)->z;
	OBJECT(object)->z_speed = (uint32_t)(uint8_t)(z + 0x30u - z_2) << 8;
}

/* Sets a link of the chain up with its animation and its hit box's height from object_1a_chain_links. */
uint16_t dreamland_boss_chain_link_setup(uint16_t object)
{
	uint16_t setup = 0;
	uint8_t attributes = 0, parameter = 0, state = 0;
	uint16_t animation = 0;

	setup = dreamland_boss_chain_object_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->enemy_class = -1;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0x10u;
	parameter = OBJECT(object)->parameter;
	animation = (((uint32_t)CHAIN_LINK(object_1a_chain_links_ADDRESS + (int8_t)((uint32_t)parameter << 1))->animation << 8u) | (uint8_t)CHAIN_LINK(object_1a_chain_links_ADDRESS + (int8_t)((uint32_t)parameter << 1))->box_y_offset);
	OBJECT(object)->animation = animation >> 8;
	OBJECT(object)->box_dy = animation;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return dreamland_boss_chain_link_follow(object);
}

/* Sets the link's drawing order (field 08) from its place in the chain (field 32). */
uint16_t dreamland_boss_chain_link_order(uint16_t object)
{
	uint8_t link_index = 0, state = 0;

	link_index = OBJECT(object)->dreamland_boss_chain.link_index;
	OBJECT(object)->frame_time = link_index;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return dreamland_boss_chain_link_follow(object);
}

/* Draws the next piece after this link at its offsets, passes the offsets and direction down the chain
   and takes the head's state. */
uint16_t dreamland_boss_chain_link_follow(uint16_t object)
{
	uint8_t a = 0, direction = 0, flags = 0;
	uint16_t chain_head = 0, next_link = 0, previous_link = 0;
	uint8_t next_direction = 0, attributes = 0, attributes_2 = 0, lead_attributes = 0, queued_direction = 0, parameter = 0, flags_2 = 0;
	uint16_t previous_link_2 = 0, next_link_2 = 0, t1 = 0, next_dx = 0, t2 = 0, next_dx_2 = 0, t3 = 0, t4 = 0, z = 0, next_dz = 0, z_2 = 0, next_dz_2 = 0, previous_link_3 = 0, chain_head_2 = 0;

	previous_link_2 = OBJECT(object)->dreamland_boss_chain.previous_link;
	previous_link = previous_link_2;
	next_link_2 = OBJECT(object)->dreamland_boss_chain.next_link;
	next_link = next_link_2;
	t1 = OBJECT(object)->x;
	next_dx = OBJECT(object)->dreamland_boss_chain.next_dx;
	t2 = OBJECT(next_link)->x;
	OBJECT(next_link)->x_speed = (uint32_t)(uint16_t)(((uint32_t)a << 8) | (uint8_t)((((uint32_t)a << 8) | (uint8_t)((((uint32_t)a << 8) | (uint8_t)t1) + next_dx)) - t2)) << 8;
	next_dx_2 = OBJECT(previous_link)->dreamland_boss_chain.next_dx;
	a = (uint8_t)(next_dx_2 >> 8);
	OBJECT(object)->dreamland_boss_chain.next_dx = ((uint32_t)a << 8) | (uint8_t)next_dx_2;
	t3 = OBJECT(object)->y;
	t4 = OBJECT(next_link)->y;
	a = (uint8_t)((((uint32_t)a << 8) | (uint8_t)((((uint32_t)a << 8) | (uint8_t)t3) - 2u)) - t4);
	OBJECT(next_link)->y_speed = (uint32_t)a << 8;
	z = OBJECT(object)->z;
	next_dz = OBJECT(object)->dreamland_boss_chain.next_dz;
	z_2 = OBJECT(next_link)->z;
	OBJECT(next_link)->z_speed = (uint32_t)(uint8_t)((((uint32_t)a << 8) | (uint8_t)((((uint32_t)a << 8) | (uint8_t)z) + next_dz)) - z_2) << 8;
	next_dz_2 = OBJECT(previous_link)->dreamland_boss_chain.next_dz;
	OBJECT(object)->dreamland_boss_chain.next_dz = next_dz_2;
	previous_link_3 = OBJECT(object)->dreamland_boss_chain.previous_link;
	previous_link = previous_link_3;
	next_direction = OBJECT(object)->dreamland_boss_chain.next_direction;
	direction = next_direction;
	attributes = OBJECT(previous_link)->attributes;
	attributes_2 = OBJECT(object)->attributes;
	if ((attributes & attributes_2) == 0u)
		direction = 0u - direction;
	OBJECT(object)->dreamland_boss_chain.direction = direction;
	lead_attributes = OBJECT(previous_link)->dreamland_boss_chain.lead_attributes;
	OBJECT(object)->attributes = lead_attributes;
	queued_direction = OBJECT(object)->dreamland_boss_chain.queued_direction;
	OBJECT(object)->dreamland_boss_chain.next_direction = queued_direction;
	parameter = OBJECT(object)->parameter;
	if ((int8_t)parameter >= 0)
	{
		chain_head_2 = OBJECT(object)->dreamland_boss_chain.chain_head;
		chain_head = chain_head_2;
		flags_2 = OBJECT(chain_head)->flags;
		flags = flags_2;
		if ((int8_t)flags_2 < 0)
			OBJECT(object)->flags = flags;
	}
	return next_link;
}

/* Sets the chain's head up on its idle path (object_1a_path), out of the enemy count. */
uint16_t dreamland_boss_chain_head_setup(uint16_t object)
{
	uint16_t holder = 0, path = 0, setup = 0;
	uint8_t attributes = 0, parameter = 0, box_y_offset = 0, attributes_2 = 0, state = 0;
	uint16_t target = 0;

	setup = dreamland_boss_chain_head_object_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->flags = 0x80u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0x10u;
	OBJECT(object)->enemy_class = -1;
	OBJECT(object)->dreamland_boss_chain_head.path_loops = 2u;
	path = 0x79F3u;
	OBJECT(object)->dreamland_boss_chain_head.path = 0x79F3u;
	parameter = OBJECT(object)->parameter;
	box_y_offset = CHAIN_LINK(object_1a_chain_links_ADDRESS + (int8_t)((uint32_t)parameter << 1))->box_y_offset;
	OBJECT(object)->box_dy = box_y_offset;
	OBJECT(object)->dreamland_boss_chain_head.legs_left = 4u;
	target = OBJECT(object)->target;
	holder = target;
	attributes_2 = OBJECT(holder)->attributes;
	OBJECT(object)->dreamland_boss_chain_head.holder_attributes = attributes_2;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return path;
}

/* Moves the head along its path: each record a direction and a distance (mirrored as its holder faces)
   given to the chain's base; FFFF goes back to the path's loop as many times as it says. */
uint16_t dreamland_boss_chain_head_follow_path(uint16_t object, uint16_t path)
{
	uint8_t direction = 0, distance = 0;
	uint16_t chain_base = 0, holder = 0, loop_path = 0;
	uint8_t target_direction = 0, legs_left = 0, attributes = 0, path_loops = 0, t3 = 0;
	uint16_t target = 0, path_2 = 0, t1 = 0, t2 = 0, target_2 = 0, chain_base_2 = 0, t4 = 0, t5 = 0, t6 = 0;
	uint32_t next_direction_halfword = 0, next_direction_halfword_2 = 0;

	target = OBJECT(object)->target;
	holder = target;
	target_direction = OBJECT(holder)->target_direction;
	if (target_direction == 0u)
	{
		legs_left = OBJECT(object)->dreamland_boss_chain_head.legs_left;
		OBJECT(object)->dreamland_boss_chain_head.legs_left = legs_left - 1u;
		if (legs_left != 1u)
			return path;
		OBJECT(object)->dreamland_boss_chain_head.legs_left = 1u;
	}
	path_2 = OBJECT(object)->dreamland_boss_chain_head.path;
	t1 = path_2;
	path = t1 + 2u;
	t2 = mem_read16(t1);
	direction = (uint8_t)(t2 >> 8);
	distance = (uint8_t)t2;
	if ((uint16_t)(((uint32_t)direction << 8) | distance) != 0xFFFFu)
	{
		path_distance = distance;
		target_2 = OBJECT(object)->target;
		holder = target_2;
		attributes = OBJECT(holder)->attributes;
		if ((attributes & 0x40u) == 0u)
			direction = 0u - direction;
		direction += 0x40u;
		chain_base_2 = OBJECT(object)->dreamland_boss_chain_head.chain_base;
		chain_base = chain_base_2;
		next_direction_halfword = ((uint32_t)direction << 8) | path_distance;
		OBJECT(chain_base)->dreamland_boss_chain.next_direction = (uint8_t)(next_direction_halfword >> 8u);
		OBJECT(chain_base)->dreamland_boss_chain.next_distance = (uint8_t)next_direction_halfword;
		OBJECT(chain_base)->dreamland_boss_chain.queued_direction = direction;
		OBJECT(object)->dreamland_boss_chain_head.path = path;
		return path;
	}
	path_loops = OBJECT(object)->dreamland_boss_chain_head.path_loops;
	OBJECT(object)->dreamland_boss_chain_head.path_loops = path_loops - 1u;
	if (path_loops != 1u)
		loop_path = mem_read16(path);
	else
	{
		t3 = mem_read8(path + 4u);
		OBJECT(object)->dreamland_boss_chain_head.path_loops = t3;
		t4 = mem_read16(path + 2u);
		loop_path = t4;
	}
	t5 = loop_path;
	path = t5 + 2u;
	t6 = mem_read16(t5);
	direction = (uint8_t)(t6 >> 8);
	distance = (uint8_t)t6;
	path_distance = distance;
	target_2 = OBJECT(object)->target;
	holder = target_2;
	attributes = OBJECT(holder)->attributes;
	if ((attributes & 0x40u) == 0u)
		direction = 0u - direction;
	direction += 0x40u;
	chain_base_2 = OBJECT(object)->dreamland_boss_chain_head.chain_base;
	chain_base = chain_base_2;
	next_direction_halfword_2 = ((uint32_t)direction << 8) | path_distance;
	OBJECT(chain_base)->dreamland_boss_chain.next_direction = (uint8_t)(next_direction_halfword_2 >> 8u);
	OBJECT(chain_base)->dreamland_boss_chain.next_distance = (uint8_t)next_direction_halfword_2;
	OBJECT(chain_base)->dreamland_boss_chain.queued_direction = direction;
	OBJECT(object)->dreamland_boss_chain_head.path = path;
	return path;
}

/* Picks the head's next lash from object_1a_path_starts: its path, its wait, its time and when it
   sounds. */
uint16_t dreamland_boss_chain_head_choose_lash(uint16_t object, uint16_t path)
{
	uint8_t path_choice = 0;
	uint16_t start = 0;
	uint8_t lash_index = 0, lash_index_2 = 0, state = 0;
	uint16_t path_2 = 0, count_3b = 0;

	OBJECT(object)->dreamland_boss_chain_head.path_loops = 1u;
	lash_index = OBJECT(object)->dreamland_boss_chain_head.lash_index;
	OBJECT(object)->dreamland_boss_chain_head.lash_index = lash_index - 1u;
	lash_index_2 = OBJECT(object)->dreamland_boss_chain_head.lash_index;
	path_choice = object_1a_path_choices[lash_index_2 & 7u];
	lash_number = path_choice;
	start = object_1a_path_starts_ADDRESS + (int8_t)(((uint32_t)path_choice << 1) << 1);
	path_2 = PATH_START(start)->path;
	OBJECT(object)->dreamland_boss_chain_head.path = path_2;
	count_3b = (((uint32_t)PATH_START(start)->count_3b << 8u) | PATH_START(start)->count_3a);
	OBJECT(object)->timer = count_3b >> 8;
	OBJECT(object)->dreamland_boss_chain_head.lash_time = count_3b;
	OBJECT(object)->dreamland_boss_chain_head.sound_time = object_1a_path_times[(int8_t)lash_number];
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return dreamland_boss_chain_head_follow_path(object, path);
}

/* Counts the wait down, then makes the head able to hit and hurt, with a sound. */
uint16_t dreamland_boss_chain_head_lash(uint16_t object, uint16_t path)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t timer = 0, attributes = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return dreamland_boss_chain_head_follow_path(object, path);
	OBJECT(object)->flags = 0xC0u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = attributes | 0x83u;
	OBJECT(object)->animation_flags = 0x80u;
	command = 0x6700u;
	carry = vector_queue_sound(command);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return dreamland_boss_chain_head_follow_path(object, path);
}

/* Sounds at its moment and, when the lash's time is up, makes the head harmless and puts it back on its
   path. */
uint16_t dreamland_boss_chain_head_withdraw(uint16_t object, uint16_t path)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t lash_time = 0, sound_time = 0, lash_time_2 = 0, attributes = 0;

	lash_time = OBJECT(object)->dreamland_boss_chain_head.lash_time;
	sound_time = OBJECT(object)->dreamland_boss_chain_head.sound_time;
	if (lash_time == sound_time)
	{
		command = 0x6A00u;
		carry = vector_queue_sound(command);
	}
	lash_time_2 = OBJECT(object)->dreamland_boss_chain_head.lash_time;
	OBJECT(object)->dreamland_boss_chain_head.lash_time = lash_time_2 - 1u;
	if (lash_time_2 != 1u)
		return dreamland_boss_chain_head_follow_path(object, path);
	OBJECT(object)->flags = 0x80u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = attributes & 0x7Fu;
	OBJECT(object)->animation_flags = 0x80u;
	OBJECT(object)->state = 1u;
	return dreamland_boss_chain_head_follow_path(object, path);
}

/* Puts the head on the path that pulls it back in (object_1a_dive_path). */
uint16_t dreamland_boss_chain_head_retract(uint16_t object, uint16_t path)
{
	OBJECT(object)->dreamland_boss_chain_head.path_loops = 0xFFu;
	OBJECT(object)->dreamland_boss_chain_head.path = 0x7D72u;
	OBJECT(object)->state = 1u;
	return dreamland_boss_chain_head_follow_path(object, path);
}

/* Finds a free object among the 24 from 4D40 (the lists at 4D40, 4F80 and 5280), clears it but for field
   59 and marks it hidden; returns true with it in U. */
void find_free_object_from_4d40(uint16_t *p_object, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t a = 0, b = 0;
	uint16_t cursor = 0, object = 0, words_left = 0;
	uint16_t stack = 0;
	uint8_t t1 = 0;
	uint16_t sprites = 0, t2 = 0;

	object = OBJECT_ADDRESS(8);
	a = 0x18u;
	for (;;)
	{
		if (OBJECT(object)->flags != 0u)
		{
			object += 0x60u;
			t1 = a;
			a = t1 - 1u;
			if (t1 != 1u)
				continue;
			carry = 0u;
			break;
		}
		sprites = OBJECT(object)->sprites;
		free_slot_sprites = sprites;
		stack = object;
		a = 0u;
		b = 0u;
		cursor = object;
		words_left = 0x30u;
		while (words_left != 0u)
		{
			mem_write8(cursor, a);
			mem_write8(cursor + 1u, b);
			cursor += 2u;
			words_left--;
		}
		object = stack;
		t2 = free_slot_sprites;
		OBJECT(object)->sprites = t2;
		OBJECT(object)->flags = 4u;
		carry = 1u;
		break;
	}
	*p_object = object;
	*p_carry = carry;
}

/* Gives the x and height offsets of a chain's link at a direction (A) and a distance (B), by
   object_1a_sines. */
void chain_link_offset(uint16_t direction_and_distance)
{
	uint8_t direction = 0, distance = 0;
	uint8_t t1 = 0;

	direction = (uint8_t)(direction_and_distance >> 8);
	distance = (uint8_t)direction_and_distance;
	chain_direction_and_distance = ((uint32_t)direction << 8) | distance;
	direction &= 0x3Fu;
	chain_quarter_direction = direction;
	chain_link_dx_low = (uint16_t)((uint32_t)object_1a_sines[direction] * distance) >> 8;
	chain_link_dz_low = (uint16_t)((uint32_t)object_1a_sines[(int8_t)((uint8_t)(0x3Fu - chain_quarter_direction))] * chain_distance) >> 8;
	chain_link_dx_high = 0u;
	chain_link_dz_high = 0u;
	if ((chain_direction & 0x40u) != 0u)
	{
		distance = chain_link_dz_low;
		chain_link_dz_low = chain_link_dx_low;
		chain_link_dx_low = distance;
	}
	if ((int8_t)chain_direction < 0)
		chain_link_dz = 0u - chain_link_dz;
	t1 = chain_direction & 0xC0u;
	direction = t1;
	if (t1 != 0u && direction != 0xC0u)
		chain_link_dx = 0u - chain_link_dx;
}
