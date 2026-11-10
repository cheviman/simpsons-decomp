/**
 *    Name:        objects/football_player.c
 *    Description: stage 4's boss (type 19, kind 92), its football and its charge's line
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Runs the football player, stage 4's boss: shows its gauge and runs its state */
uint16_t football_player(uint16_t object, uint16_t enemy_handlers)
{
	uint8_t gauge_number = 0;
	uint16_t piece_health_by_players = 0, states = 0;
	uint8_t phase = 0;

	piece_health_by_players = football_player_gauge_healths_ADDRESS;
	gauge_number = 2u;
	stage_boss_set_gauge(object, piece_health_by_players, gauge_number);
	phase = OBJECT(object)->football_player.phase;
	states = football_player_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)phase << 1))
	{
	case 0:
		return football_player_start(object);
	case 2:
		return football_player_wait_cue(object, states);
	case 4:
	case 38:
		return football_player_stand(object, enemy_handlers);
	case 6:
		return football_player_run_at_target(object, enemy_handlers);
	case 8:
		return football_player_wander(object, enemy_handlers);
	case 10:
		return football_player_appear(object, states);
	case 12:
		return football_player_ready(object, states);
	case 14:
		return football_player_tackle(object, enemy_handlers);
	case 16:
		return football_player_rest(object, enemy_handlers);
	case 18:
		return football_player_throw(object, enemy_handlers);
	case 20:
		return football_player_throwing(object, enemy_handlers);
	case 22:
		return football_player_charge_windup(object, enemy_handlers);
	case 24:
		return football_player_charge(object, enemy_handlers);
	case 26:
		return football_player_hurt_pose(object, enemy_handlers);
	case 28:
		return football_player_hurt_pose_wait(object, enemy_handlers);
	case 30:
		return football_player_flinch(object, states);
	case 32:
		return football_player_knocked_back(object, states);
	case 34:
		return football_player_knocked_out(object, states);
	case 36:
		football_player_defeated(object);
		return states;
	case 40:
		return football_player_start_tackle(object, enemy_handlers);
	}
	unreachable();
}

/* The football it throws: a hit box with damage for 15 frames */
void football_thrown(uint16_t object)
{
	uint16_t box = 0;
	uint8_t flight_frames = 0;

	if ((OBJECT(object)->flags & 4u) == 0u)
	{
		flight_frames = OBJECT(object)->football_thrown.flight_frames;
		OBJECT(object)->football_thrown.flight_frames = flight_frames - 1u;
		if (flight_frames == 1u)
			OBJECT(object)->flags = 0u;
		return;
	}
	stage_boss_activate(object);
	OBJECT(object)->kind = 0x92u;
	OBJECT(object)->animation = 0x88u;
	box = football_box_ADDRESS;
	stage_boss_set_hit_box(object, box);
	OBJECT(object)->box_dz = 0u;
	OBJECT(object)->damage = 8u;
	OBJECT(object)->attack = 0xAu;
	OBJECT(object)->football_thrown.flight_frames = 0x15u;
}

/* One of the 8 pieces of the line its charge puts in, each from the one before; the 1st, 4th and 7th
   hurt */
uint16_t football_line_piece(uint16_t object, uint16_t child)
{
	uint32_t carry = 0;
	uint8_t dx = 0, flags = 0, piece_number = 0, step = 0;
	uint16_t box = 0, child_object = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, life_frames = 0, t6 = 0, t7 = 0, attributes = 0;
	uint16_t t8 = 0, t9 = 0, t10 = 0, t11 = 0;
	uint32_t kind_halfword = 0, kind_halfword_2 = 0;

	if ((OBJECT(object)->flags & 4u) == 0u)
	{
		t1 = (uint8_t)OBJECT(object)->target_dy;
		step = t1;
		if (step == 4u)
		{
			t2 = (uint8_t)OBJECT(object)->target_dy;
			OBJECT(object)->target_dy = (OBJECT(object)->target_dy & 0xFF00u) | (t2 + 1u & 0xFFu);
			t3 = io_read8(0x184Au);
			if ((int8_t)t3 < 7)
			{
				t4 = io_read8(0x184Au);
				io_write8(0x184Au, t4 + 1u);
				child_object = football_line_piece_child_ADDRESS;
				spawn_list_2_child(object, child_object, &child, &carry);
			}
		}
		else if ((int8_t)step <= 4)
		{
			t5 = (uint8_t)OBJECT(object)->target_dy;
			OBJECT(object)->target_dy = (OBJECT(object)->target_dy & 0xFF00u) | (t5 + 1u & 0xFFu);
		}
		life_frames = OBJECT(object)->football_line_piece.life_frames;
		OBJECT(object)->football_line_piece.life_frames = life_frames - 1u;
		if (life_frames == 1u)
			OBJECT(object)->flags = 0u;
		return child;
	}
	flags = 0x80u;
	t6 = io_read8(0x184Au);
	piece_number = t6;
	if (t6 != 0u && piece_number != 3u && piece_number != 6u)
	{
		OBJECT(object)->flags = flags;
		t7 = io_read8(0x184Au);
		t8 = football_player_line_pieces_ADDRESS + (int8_t)((uint32_t)t7 << 1);
		kind_halfword = 0x9200u | LINE_PIECE(t8)->animation;
		OBJECT(object)->kind = (uint8_t)(kind_halfword >> 8u);
		OBJECT(object)->animation = (uint8_t)kind_halfword;
		dx = LINE_PIECE(t8)->dx;
		attributes = OBJECT(object)->attributes;
		if ((attributes & 0x40u) != 0u)
			dx = 0u - dx;
		t9 = (int8_t)dx;
		t10 = OBJECT(object)->x;
		t11 = t9 + t10;
		OBJECT(object)->x = t11;
		OBJECT(object)->football_line_piece.life_frames = 0x13u;
		return child;
	}
	box = football_line_piece_box_ADDRESS;
	stage_boss_set_hit_box(object, box);
	OBJECT(object)->box_dz = 1u;
	OBJECT(object)->damage = 0xCu;
	OBJECT(object)->attack = 5u;
	flags = 0xC0u;
	OBJECT(object)->flags = flags;
	t7 = io_read8(0x184Au);
	t8 = football_player_line_pieces_ADDRESS + (int8_t)((uint32_t)t7 << 1);
	kind_halfword_2 = 0x9200u | LINE_PIECE(t8)->animation;
	OBJECT(object)->kind = (uint8_t)(kind_halfword_2 >> 8u);
	OBJECT(object)->animation = (uint8_t)kind_halfword_2;
	dx = LINE_PIECE(t8)->dx;
	attributes = OBJECT(object)->attributes;
	if ((attributes & 0x40u) != 0u)
		dx = 0u - dx;
	t9 = (int8_t)dx;
	t10 = OBJECT(object)->x;
	t11 = t9 + t10;
	OBJECT(object)->x = t11;
	OBJECT(object)->football_line_piece.life_frames = 0x13u;
	return child;
}

/* Sets the football player up: kind, health, its first state, and the marker the story uses */
uint16_t football_player_start(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t animation_number = 0, ignored16 = 0, marker = 0, record = 0, state_wait = 0;
	uint8_t t4 = 0;
	uint16_t t1 = 0, t2 = 0, z = 0, t3 = 0;

	stage_boss_activate(object);
	OBJECT(object)->kind = 0x92u;
	OBJECT(object)->vitality = 0xA0u;
	OBJECT(object)->football_player.flinch_health = 0xA0u;
	OBJECT(object)->football_player.attack_health = 0xA0u;
	OBJECT(object)->attributes = 0x20u;
	state_wait = 0x100u;
	animation_number = 0x8200u;
	stage_boss_set_state(object, state_wait, animation_number);
	t1 = OBJECT(object)->y;
	t2 = t1 + 0x30u;
	OBJECT(object)->y = t2;
	z = OBJECT(object)->z;
	t3 = z - 0x30u;
	OBJECT(object)->z = t3;
	OBJECT(object)->football_player.hurt_pose = 0x14u;
	OBJECT(object)->entrance_pending = 0x14u;
	t4 = io_read8(0x184Au);
	io_write8(0x184Au, 0u);
	record = football_player_child_ADDRESS;
	vector_spawn_child(object, record, &marker, &ignored16, &carry);
	io_write16(0x1852u, marker);
	return record;
}

/* Waits for the story to set the cue in 184A, then drops to the floor */
uint16_t football_player_wait_cue(uint16_t object, uint16_t states)
{
	uint16_t state_wait = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	t1 = io_read8(0x184Au);
	if (t1 == 0u)
		return states;
	state_wait = 0x514u;
	OBJECT(object)->football_player.phase = 5u;
	OBJECT(object)->football_player.wait = 0x14u;
	t2 = OBJECT(object)->y;
	OBJECT(object)->y = t2 - 0x30u;
	OBJECT(object)->z = 0u;
	OBJECT(object)->attributes = 0u;
	OBJECT(object)->entrance_pending = 0u;
	return state_wait;
}

/* After its wait, marks the boss entering and starts its entrance animation */
uint16_t football_player_appear(uint16_t object, uint16_t states)
{
	uint16_t animation_number = 0, state_wait = 0;
	uint8_t wait = 0;

	wait = OBJECT(object)->football_player.wait;
	OBJECT(object)->football_player.wait = wait - 1u;
	if (wait != 1u)
		return states;
	boss_arrived = 1u;
	OBJECT(object)->football_player.charge_wait = 0x86u - rank - rank;
	state_wait = 0x600u;
	animation_number = 0x8300u;
	stage_boss_set_state(object, state_wait, animation_number);
	return state_wait;
}

/* At its entrance's end takes its stance, hit box and flags and looks for a player to tackle */
uint16_t football_player_ready(uint16_t object, uint16_t states)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0, next_state = 0, next_wait = 0;
	uint16_t animation_number = 0, box = 0, ignored16 = 0, player = 0, state_wait = 0;
	uint8_t animation_flags = 0, attack_health = 0, vitality = 0, vitality_2 = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return states;
	boss_arrived = 0u;
	state_wait = 0x214u;
	animation_number = 0x8000u;
	stage_boss_set_state(object, state_wait, animation_number);
	box = football_player_box_ADDRESS;
	stage_boss_set_hit_box(object, box);
	OBJECT(object)->flags = (OBJECT(object)->flags & ~4u) | 0xC0u;
	a = 0u;
	b = 0x3Cu;
	reach_x = ((uint32_t)a << 8) | b;
	reach_y = 0xC;
	stage_boss_find_near_player(object, &player, &ignored16, &carry);
	if (carry == 0u)
		return football_player_check_hit(object, player);
	attack_health = OBJECT(object)->football_player.attack_health;
	vitality = OBJECT(object)->vitality;
	if ((uint8_t)(attack_health - vitality) < 0xCu)
	{
		player = 0x7DA5u;
		next_wait = football_player_attack_delays_by_players[(int8_t)player_count - 1];
		next_state = 0x14u;
	}
	else
	{
		vitality_2 = OBJECT(object)->vitality;
		OBJECT(object)->football_player.attack_health = vitality_2;
		next_state = 0x14u;
		next_wait = 1u;
	}
	OBJECT(object)->target_dy = ((uint32_t)next_state << 8) | next_wait;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	return football_player_start_tackle(object, player);
}

/* Waits, then rests, charges or runs at the nearest player */
uint16_t football_player_stand(uint16_t object, uint16_t enemy_handlers)
{
	uint8_t wait = 0, runs_to_rest = 0, charge_wait = 0;

	wait = OBJECT(object)->football_player.wait;
	OBJECT(object)->football_player.wait = wait - 1u;
	if (wait != 1u)
		return football_player_check_hit(object, enemy_handlers);
	runs_to_rest = OBJECT(object)->football_player.runs_to_rest;
	OBJECT(object)->football_player.runs_to_rest = runs_to_rest - 1u;
	if (runs_to_rest == 1u)
		return football_player_start_rest(object, enemy_handlers);
	charge_wait = OBJECT(object)->football_player.charge_wait;
	OBJECT(object)->football_player.charge_wait = charge_wait - 1u;
	if (charge_wait == 1u)
		return football_player_start_charge(object, enemy_handlers);
	return football_player_start_run(object);
}

/* Runs at the nearest player */
uint16_t football_player_start_run(uint16_t object)
{
	uint8_t direction = 0;
	uint16_t animation_number = 0, chase_target = 0, d = 0, state_wait = 0;

	state_wait = 0x300u;
	animation_number = 0x8100u;
	stage_boss_set_state(object, state_wait, animation_number);
	chase_target = vector_choose_nearest_player(object);
	OBJECT(object)->football_player.chase_target = chase_target;
	d = stage_boss_offset_ahead_of(chase_target);
	d = vector_direction_to_offset(object, chase_target, d);
	direction = (uint8_t)(d >> 8);
	OBJECT(object)->football_player.direction = direction;
	OBJECT(object)->football_player.speed = 0x10u;
	return football_player_check_hit(object, chase_target);
}

/* Starts a rest (animation 85); its count of 1E goes to 003C instead of its own field 3C */
uint16_t football_player_start_rest(uint16_t object, uint16_t u)
{
	uint16_t animation_number = 0, state_wait = 0;

	io_write8(0x3Cu, 0x1Eu);
	state_wait = 0x800u;
	animation_number = 0x8500u;
	stage_boss_set_state(object, state_wait, animation_number);
	return football_player_check_hit(object, u);
}

/* Runs turning toward its target until its charge is due, now and then wandering */
uint16_t football_player_run_at_target(uint16_t object, uint16_t enemy_handlers)
{
	uint32_t negative = 0, overflow = 0;
	uint8_t direction = 0, turn = 0;
	uint16_t d = 0, heading = 0, target = 0;
	uint8_t charge_wait = 0, runs_to_rest = 0, direction_2 = 0, direction_3 = 0, speed = 0;
	uint16_t chase_target = 0;

	charge_wait = OBJECT(object)->football_player.charge_wait;
	OBJECT(object)->football_player.charge_wait = charge_wait - 1u;
	if (charge_wait == 1u)
		return football_player_start_charge(object, enemy_handlers);
	runs_to_rest = OBJECT(object)->football_player.runs_to_rest;
	OBJECT(object)->football_player.runs_to_rest = runs_to_rest - 1u;
	if (runs_to_rest == 1u)
		return football_player_start_rest(object, enemy_handlers);
	chase_target = OBJECT(object)->football_player.chase_target;
	target = chase_target;
	d = stage_boss_offset_ahead_of(target);
	d = vector_direction_to_offset(object, target, d);
	direction = (uint8_t)(d >> 8);
	direction_2 = OBJECT(object)->football_player.direction;
	negative = (uint8_t)(direction - direction_2) >> 7;
	overflow = (uint32_t)(int8_t)direction - (int8_t)direction_2 != (uint32_t)(int8_t)(direction - direction_2);
	if (direction == direction_2)
		turn = 0x1Cu;
	else
	{
		if ((negative ^ overflow) == 0u)
		{
			if (overflow)
			{
				turn = 0xF9u;
				OBJECT(object)->football_player.turn = turn;
				direction_3 = OBJECT(object)->football_player.direction;
				turn += direction_3;
				OBJECT(object)->football_player.direction = turn;
				speed = OBJECT(object)->football_player.speed;
				heading = ((uint32_t)turn << 8) | speed;
				vector_set_speed_by_direction(object, heading);
				if ((random_number & 0x7Fu) != 0u)
					return football_player_run(object, target);
				OBJECT(object)->football_player.phase = 4u;
				OBJECT(object)->football_player.wait = 0x78u;
				OBJECT(object)->football_player.turn = 5;
				return football_player_run(object, target);
			}
			turn = 7u;
			OBJECT(object)->football_player.turn = turn;
			direction_3 = OBJECT(object)->football_player.direction;
			turn += direction_3;
			OBJECT(object)->football_player.direction = turn;
			speed = OBJECT(object)->football_player.speed;
			heading = ((uint32_t)turn << 8) | speed;
			vector_set_speed_by_direction(object, heading);
			if ((random_number & 0x7Fu) != 0u)
				return football_player_run(object, target);
			OBJECT(object)->football_player.phase = 4u;
			OBJECT(object)->football_player.wait = 0x78u;
			OBJECT(object)->football_player.turn = 5;
			return football_player_run(object, target);
		}
		if (overflow)
			turn = 7u;
		else
			turn = 0xF9u;
	}
	OBJECT(object)->football_player.turn = turn;
	direction_3 = OBJECT(object)->football_player.direction;
	turn += direction_3;
	OBJECT(object)->football_player.direction = turn;
	speed = OBJECT(object)->football_player.speed;
	heading = ((uint32_t)turn << 8) | speed;
	vector_set_speed_by_direction(object, heading);
	if ((random_number & 0x7Fu) != 0u)
		return football_player_run(object, target);
	OBJECT(object)->football_player.phase = 4u;
	OBJECT(object)->football_player.wait = 0x78u;
	OBJECT(object)->football_player.turn = 5;
	return football_player_run(object, target);
}

/* Winds up its charge (unhurtable with three or more players) */
uint16_t football_player_start_charge(uint16_t object, uint16_t enemy_handlers)
{
	uint16_t animation_number = 0, state_wait = 0;
	uint8_t stack = 0, stack_10002 = 0;

	if ((int8_t)player_count > 2)
		stage_boss_shield(object);
	players_share = player_count >> 1;
	OBJECT(object)->football_player.charge_wait = 0x86u - players_share - players_share;
	stack = 0xBu;
	stack_10002 = 0x12u;
	state_wait = ((uint32_t)stack << 8) | stack_10002;
	animation_number = 0x8900u;
	stage_boss_set_state(object, state_wait, animation_number);
	return football_player_check_hit(object, enemy_handlers);
}

/* Runs turning at random for its wait, then at its target again */
uint16_t football_player_wander(uint16_t object, uint16_t chase_target)
{
	uint8_t direction = 0, turn = 0;
	uint16_t heading = 0;
	uint8_t wait = 0, runs_to_rest = 0, turn_2 = 0, turn_3 = 0, direction_2 = 0, speed = 0;

	wait = OBJECT(object)->football_player.wait;
	OBJECT(object)->football_player.wait = wait - 1u;
	if (wait == 1u)
	{
		OBJECT(object)->football_player.phase = 3u;
		chase_target = vector_choose_nearest_player(object);
		OBJECT(object)->football_player.chase_target = chase_target;
	}
	runs_to_rest = OBJECT(object)->football_player.runs_to_rest;
	OBJECT(object)->football_player.runs_to_rest = runs_to_rest - 1u;
	if (runs_to_rest == 1u)
		return football_player_start_rest(object, chase_target);
	turn_2 = OBJECT(object)->football_player.turn;
	turn = turn_2;
	if ((random_number & ~0xFu) == 0u)
		OBJECT(object)->football_player.turn = 0u - turn;
	turn_3 = OBJECT(object)->football_player.turn;
	direction_2 = OBJECT(object)->football_player.direction;
	direction = turn_3 + direction_2;
	OBJECT(object)->football_player.direction = direction;
	speed = OBJECT(object)->football_player.speed;
	heading = ((uint32_t)direction << 8) | speed;
	vector_set_speed_by_direction(object, heading);
	return football_player_run(object, chase_target);
}

/* Moves it on its run, bounces off the screen's sides and decides to pose, throw, taunt or tackle */
uint16_t football_player_run(uint16_t object, uint16_t u)
{
	uint32_t negative = 0, carry = 0;
	uint8_t a = 0, attributes = 0, b = 0, cell = 0, next_state = 0, next_wait = 0;
	uint16_t animation_number = 0, floor_cell = 0, ignored16 = 0, limit = 0, player = 0, state_wait = 0;
	uint8_t stack = 0, stack_10002 = 0;
	uint8_t attributes_2 = 0, wrong_way = 0, wrong_way_2 = 0, x_fraction = 0, y_fraction = 0, vitality = 0, direction = 0, x_speed_2 = 0, t3 = 0, y_speed = 0, t6 = 0, vitality_2 = 0, hurt_pose = 0, direction_2 = 0, throw_wait = 0, attack_health = 0, vitality_3 = 0, vitality_4 = 0;
	uint16_t x_speed = 0, t1 = 0, x_speed_3 = 0, t2 = 0, t4 = 0, y_speed_2 = 0, t5 = 0;

	attributes = 0u;
	x_speed = OBJECT(object)->x_speed;
	if ((int16_t)x_speed < 0)
		attributes = 0x40u;
	attributes_2 = OBJECT(object)->attributes;
	if (((attributes ^ attributes_2) & 0x40u) == 0u)
		OBJECT(object)->football_player.wrong_way = 0u;
	else
	{
		wrong_way = OBJECT(object)->football_player.wrong_way;
		OBJECT(object)->football_player.wrong_way = wrong_way + 1u;
		wrong_way_2 = OBJECT(object)->football_player.wrong_way;
		if (wrong_way_2 >= 0x10u)
		{
			OBJECT(object)->attributes = attributes;
			OBJECT(object)->football_player.wrong_way = 0u;
		}
	}
	x_fraction = OBJECT(object)->x_fraction;
	y_fraction = OBJECT(object)->y_fraction;
	if (((x_fraction + y_fraction) & 0x3Cu) == 0u)
	{
		vitality = OBJECT(object)->vitality;
		OBJECT(object)->football_player.speed = ((uint16_t)((uint32_t)(uint8_t)(((uint8_t)(0xFFu - vitality) >> 1) + football_player_speed_ranges_by_rank[rank >> 1]) * random_number) >> 8) + 0x10u;
	}
	vector_floor_ahead(object, &floor_cell, &negative);
	cell = (uint8_t)(floor_cell >> 8);
	if ((cell & 0xFu) != 0u)
	{
		direction = OBJECT(object)->football_player.direction;
		OBJECT(object)->football_player.direction = direction - 0x80u;
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0;
	}
	else
	{
		x_speed_2 = (uint8_t)(OBJECT(object)->x_speed >> 8u);
		players_share = (uint16_t)(int8_t)x_speed_2 >> 8;
		t1 = (((uint32_t)(OBJECT(object)->x & 0xFFu) << 8u) | OBJECT(object)->x_fraction);
		x_speed_3 = OBJECT(object)->x_speed;
		t2 = t1;
		carry = (uint16_t)(t2 + x_speed_3) < t2;
		b = (uint8_t)((uint16_t)(t2 + x_speed_3) >> 8);
		t3 = (uint8_t)(OBJECT(object)->x >> 8u);
		a = t3 + players_share + carry;
		limit = 0x30u;
		if ((int16_t)(((uint32_t)a << 8) | b) < 0x30)
		{
			OBJECT(object)->x = limit;
			direction = OBJECT(object)->football_player.direction;
			OBJECT(object)->football_player.direction = direction - 0x80u;
			OBJECT(object)->x_speed = 0;
			OBJECT(object)->y_speed = 0;
		}
		else
		{
			limit = 0x180u;
			if ((int16_t)(((uint32_t)a << 8) | b) <= 0x180)
			{
				y_speed = (uint8_t)(OBJECT(object)->y_speed >> 8u);
				players_share = (uint16_t)(int8_t)y_speed >> 8;
				t4 = (((uint32_t)(OBJECT(object)->y & 0xFFu) << 8u) | OBJECT(object)->y_fraction);
				y_speed_2 = OBJECT(object)->y_speed;
				t5 = t4;
				carry = (uint16_t)(t5 + y_speed_2) < t5;
				b = (uint8_t)((uint16_t)(t5 + y_speed_2) >> 8);
				t6 = (uint8_t)(OBJECT(object)->y >> 8u);
				a = t6 + players_share + carry;
				limit = 0x58u;
				if ((int16_t)(((uint32_t)a << 8) | b) < 0x58)
				{
					OBJECT(object)->y = limit;
					direction = OBJECT(object)->football_player.direction;
					OBJECT(object)->football_player.direction = direction - 0x80u;
					OBJECT(object)->x_speed = 0;
					OBJECT(object)->y_speed = 0;
				}
				else
				{
					limit = 0x170u;
					if ((int16_t)(((uint32_t)a << 8) | b) > 0x170)
					{
						OBJECT(object)->y = limit;
						direction = OBJECT(object)->football_player.direction;
						OBJECT(object)->football_player.direction = direction - 0x80u;
						OBJECT(object)->x_speed = 0;
						OBJECT(object)->y_speed = 0;
					}
				}
			}
			else
			{
				OBJECT(object)->x = limit;
				direction = OBJECT(object)->football_player.direction;
				OBJECT(object)->football_player.direction = direction - 0x80u;
				OBJECT(object)->x_speed = 0;
				OBJECT(object)->y_speed = 0;
			}
		}
	}
	vitality_2 = OBJECT(object)->vitality;
	if (vitality_2 < 0x60u)
	{
		hurt_pose = OBJECT(object)->football_player.hurt_pose;
		if (hurt_pose != 0u)
		{
			OBJECT(object)->football_player.hurt_pose = 0u;
			direction_2 = OBJECT(object)->football_player.direction;
			if ((direction_2 & 0xE0u) == 0u)
			{
				state_wait = 0xD00u;
				animation_number = (floor_cell & 0xFFu) | 0x8C00u;
				stage_boss_set_state(object, state_wait, animation_number);
				return football_player_check_hit(object, u);
			}
		}
	}
	throw_wait = OBJECT(object)->football_player.throw_wait;
	OBJECT(object)->football_player.throw_wait = throw_wait - 1u;
	if (throw_wait == 1u)
	{
		players_share = (uint32_t)player_count << 1;
		OBJECT(object)->football_player.throw_wait = 0xC6u - players_share - players_share - players_share;
		stack = 9u;
		stack_10002 = 0x18u;
		state_wait = ((uint32_t)stack << 8) | stack_10002;
		animation_number = (floor_cell & 0xFFu) | 0x8600u;
		stage_boss_set_state(object, state_wait, animation_number);
		return football_player_check_hit(object, u);
	}
	carry = stage_boss_any_player_down();
	if (carry == 0u)
	{
		a = 0u;
		b = 0x3Cu;
		reach_x = ((uint32_t)a << 8) | b;
		reach_y = 0xC;
		stage_boss_find_near_player(object, &player, &ignored16, &carry);
		if (carry == 0u)
			return football_player_check_hit(object, player);
		attack_health = OBJECT(object)->football_player.attack_health;
		vitality_3 = OBJECT(object)->vitality;
		if ((uint8_t)(attack_health - vitality_3) < 0xCu)
		{
			player = 0x7DA5u;
			next_wait = football_player_attack_delays_by_players[(int8_t)player_count - 1];
			next_state = 0x14u;
		}
		else
		{
			vitality_4 = OBJECT(object)->vitality;
			OBJECT(object)->football_player.attack_health = vitality_4;
			next_state = 0x14u;
			next_wait = 1u;
		}
		OBJECT(object)->target_dy = ((uint32_t)next_state << 8) | next_wait;
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0;
		return football_player_start_tackle(object, player);
	}
	if (player_count == 1u)
		state_wait = 0x13FEu;
	else
	{
		state_wait = 0x1350u;
		if ((random_number & 3u) == 0u)
			state_wait = 0x1364u;
	}
	animation_number = (floor_cell & 0xFFu) | 0x9000u;
	stage_boss_set_state(object, state_wait, animation_number);
	return football_player_check_hit(object, u);
}

/* After its wait, tackles: attack animation, hit box, unhurtable */
uint16_t football_player_start_tackle(uint16_t object, uint16_t u)
{
	uint16_t animation_number = 0, state_wait = 0;
	uint8_t wait = 0;

	wait = OBJECT(object)->football_player.wait;
	OBJECT(object)->football_player.wait = wait - 1u;
	if (wait != 1u)
		return football_player_check_hit(object, u);
	state_wait = 0x728u;
	animation_number = 0x8400u;
	stage_boss_set_state(object, state_wait, animation_number);
	OBJECT(object)->box_width = 0x1Cu;
	OBJECT(object)->box_dx = 0x1C;
	stage_boss_shield(object);
	u = stage_boss_face_nearest_player(object);
	OBJECT(object)->football_player.wrong_way = 0u;
	if (1u == 0u)
		return football_player_check_hit(object, u);
	return football_player_tackle(object, u);
}

/* Its tackle's damage on the attack frames, back to standing when done */
uint16_t football_player_tackle(uint16_t object, uint16_t u)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0, next_state = 0, next_wait = 0, throw_wait = 0;
	uint16_t animation_number = 0, box = 0, damage = 0, ignored16 = 0, state_wait = 0;
	uint8_t charge_wait = 0, charge_wait_2 = 0, throw_wait_2 = 0, throw_wait_3 = 0, wait = 0, attack_health = 0, vitality = 0, vitality_2 = 0;

	damage = 0xC0Au;
	carry = stage_boss_attack_frame(object, damage);
	throw_wait = 1u;
	charge_wait = OBJECT(object)->football_player.charge_wait;
	if (1u != charge_wait)
	{
		charge_wait_2 = OBJECT(object)->football_player.charge_wait;
		OBJECT(object)->football_player.charge_wait = charge_wait_2 - 1u;
	}
	throw_wait_2 = OBJECT(object)->football_player.throw_wait;
	if (throw_wait != throw_wait_2)
	{
		throw_wait_3 = OBJECT(object)->football_player.throw_wait;
		OBJECT(object)->football_player.throw_wait = throw_wait_3 - 1u;
	}
	wait = OBJECT(object)->football_player.wait;
	OBJECT(object)->football_player.wait = wait - 1u;
	if (wait != 1u)
		return football_player_check_hit(object, u);
	state_wait = 0x214u;
	animation_number = 0x8000u;
	stage_boss_set_state(object, state_wait, animation_number);
	box = football_player_box_ADDRESS;
	stage_boss_set_hit_box(object, box);
	OBJECT(object)->flags = (OBJECT(object)->flags & ~4u) | 0xC0u;
	a = 0u;
	b = 0x3Cu;
	reach_x = ((uint32_t)a << 8) | b;
	reach_y = 0xC;
	stage_boss_find_near_player(object, &u, &ignored16, &carry);
	if (carry == 0u)
		return football_player_check_hit(object, u);
	attack_health = OBJECT(object)->football_player.attack_health;
	vitality = OBJECT(object)->vitality;
	if ((uint8_t)(attack_health - vitality) < 0xCu)
	{
		u = 0x7DA5u;
		next_wait = football_player_attack_delays_by_players[(int8_t)player_count - 1];
		next_state = 0x14u;
	}
	else
	{
		vitality_2 = OBJECT(object)->vitality;
		OBJECT(object)->football_player.attack_health = vitality_2;
		next_state = 0x14u;
		next_wait = 1u;
	}
	OBJECT(object)->target_dy = ((uint32_t)next_state << 8) | next_wait;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	return football_player_start_tackle(object, u);
}

/* Rests until its animation ends, then runs again */
uint16_t football_player_rest(uint16_t object, uint16_t enemy_handlers)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return football_player_check_hit(object, enemy_handlers);
	return football_player_start_run(object);
}

/* After its wait, throws a football */
uint16_t football_player_throw(uint16_t object, uint16_t enemy_handlers)
{
	uint32_t carry = 0;
	uint16_t animation_number = 0, ball = 0, command = 0, record = 0, state_wait = 0;
	uint8_t wait = 0;

	wait = OBJECT(object)->football_player.wait;
	OBJECT(object)->football_player.wait = wait - 1u;
	if (wait != 1u)
		return football_player_shield_if_crowded(object, enemy_handlers);
	state_wait = 0xA00u;
	animation_number = 0x8700u;
	stage_boss_set_state(object, state_wait, animation_number);
	record = football_player_throw_child_ADDRESS;
	spawn_list_2_child(object, record, &ball, &carry);
	command = 0x6D00u;
	carry = vector_queue_sound(command);
	return football_player_check_hit(object, ball);
}

/* Makes it unhurtable when three or four play */
uint16_t football_player_shield_if_crowded(uint16_t object, uint16_t enemy_handlers)
{
	if ((int8_t)player_count <= 2)
		return football_player_check_hit(object, enemy_handlers);
	stage_boss_shield(object);
	return football_player_check_hit(object, enemy_handlers);
}

/* Its throw's animation, hurting on the attack frames */
uint16_t football_player_throwing(uint16_t object, uint16_t enemy_handlers)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0, next_state = 0, next_wait = 0;
	uint16_t animation_number = 0, box = 0, ignored16 = 0, player = 0, state_wait = 0;
	uint8_t animation_flags = 0, attack_health = 0, vitality = 0, vitality_2 = 0;

	OBJECT(object)->flags |= 0xC0u;
	animation_flags = OBJECT(object)->animation_flags;
	a = animation_flags;
	if ((a & 1u) == 0u)
	{
		if ((a & 2u) == 0u)
		{
			OBJECT(object)->damage = 0u;
			OBJECT(object)->attack = 0u;
			return football_player_check_hit(object, enemy_handlers);
		}
		OBJECT(object)->damage = 4u;
		OBJECT(object)->attack = 0xAu;
		return football_player_check_hit(object, enemy_handlers);
	}
	state_wait = 0x214u;
	animation_number = 0x8000u;
	stage_boss_set_state(object, state_wait, animation_number);
	box = football_player_box_ADDRESS;
	stage_boss_set_hit_box(object, box);
	OBJECT(object)->flags = (OBJECT(object)->flags & ~4u) | 0xC0u;
	a = 0u;
	b = 0x3Cu;
	reach_x = ((uint32_t)a << 8) | b;
	reach_y = 0xC;
	stage_boss_find_near_player(object, &player, &ignored16, &carry);
	if (carry == 0u)
		return football_player_check_hit(object, player);
	attack_health = OBJECT(object)->football_player.attack_health;
	vitality = OBJECT(object)->vitality;
	if ((uint8_t)(attack_health - vitality) < 0xCu)
	{
		player = 0x7DA5u;
		next_wait = football_player_attack_delays_by_players[(int8_t)player_count - 1];
		next_state = 0x14u;
	}
	else
	{
		vitality_2 = OBJECT(object)->vitality;
		OBJECT(object)->football_player.attack_health = vitality_2;
		next_state = 0x14u;
		next_wait = 1u;
	}
	OBJECT(object)->target_dy = ((uint32_t)next_state << 8) | next_wait;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	return football_player_start_tackle(object, player);
}

/* Waits out the charge's wind-up, then charges */
uint16_t football_player_charge_windup(uint16_t object, uint16_t enemy_handlers)
{
	uint16_t animation_number = 0, state_wait = 0;
	uint8_t wait = 0, animation_flags = 0;

	wait = OBJECT(object)->football_player.wait;
	OBJECT(object)->football_player.wait = wait - 1u;
	if (wait != 1u)
	{
		animation_flags = OBJECT(object)->animation_flags;
		if ((animation_flags & 1u) == 0u)
			return football_player_shield_if_crowded(object, enemy_handlers);
	}
	state_wait = 0xC00u;
	animation_number = 0x8A00u;
	stage_boss_set_state(object, state_wait, animation_number);
	OBJECT(object)->flags = 0xC0u;
	return football_player_check_hit(object, enemy_handlers);
}

/* Charges, leaving its line of pictures behind */
uint16_t football_player_charge(uint16_t object, uint16_t enemy_handlers)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0, next_state = 0, next_wait = 0;
	uint16_t animation_number = 0, box = 0, command = 0, ignored16 = 0, piece = 0, record = 0, state_wait = 0;
	uint8_t animation_flags = 0, attack_health = 0, vitality = 0, vitality_2 = 0, t1 = 0;

	OBJECT(object)->flags |= 0xC0u;
	animation_flags = OBJECT(object)->animation_flags;
	a = animation_flags;
	if ((a & 1u) != 0u)
	{
		state_wait = 0x214u;
		animation_number = 0x8000u;
		stage_boss_set_state(object, state_wait, animation_number);
		box = football_player_box_ADDRESS;
		stage_boss_set_hit_box(object, box);
		OBJECT(object)->flags = (OBJECT(object)->flags & ~4u) | 0xC0u;
		a = 0u;
		b = 0x3Cu;
		reach_x = ((uint32_t)a << 8) | b;
		reach_y = 0xC;
		stage_boss_find_near_player(object, &enemy_handlers, &ignored16, &carry);
		if (carry == 0u)
			return football_player_check_hit(object, enemy_handlers);
		attack_health = OBJECT(object)->football_player.attack_health;
		vitality = OBJECT(object)->vitality;
		if ((uint8_t)(attack_health - vitality) < 0xCu)
		{
			enemy_handlers = 0x7DA5u;
			next_wait = football_player_attack_delays_by_players[(int8_t)player_count - 1];
			next_state = 0x14u;
		}
		else
		{
			vitality_2 = OBJECT(object)->vitality;
			OBJECT(object)->football_player.attack_health = vitality_2;
			next_state = 0x14u;
			next_wait = 1u;
		}
		OBJECT(object)->target_dy = ((uint32_t)next_state << 8) | next_wait;
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0;
		return football_player_start_tackle(object, enemy_handlers);
	}
	if ((a & 2u) == 0u)
		return football_player_check_hit(object, enemy_handlers);
	record = football_player_charge_child_ADDRESS;
	spawn_list_2_child(object, record, &piece, &carry);
	t1 = io_read8(0x184Au);
	io_write8(0x184Au, 0u);
	command = 0x6200u;
	carry = vector_queue_sound(command);
	return football_player_check_hit(object, piece);
}

/* The pose it strikes once when its health falls under 60 */
uint16_t football_player_hurt_pose(uint16_t object, uint16_t enemy_handlers)
{
	uint16_t animation_number = 0, state_wait = 0;
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return football_player_check_hit(object, enemy_handlers);
	state_wait = 0xE78u;
	animation_number = 0x8200u;
	stage_boss_set_state(object, state_wait, animation_number);
	return football_player_check_hit(object, enemy_handlers);
}

/* Waits after the pose, then takes its stance again */
uint16_t football_player_hurt_pose_wait(uint16_t object, uint16_t enemy_handlers)
{
	uint16_t animation_number = 0, state_wait = 0;
	uint8_t wait = 0;

	wait = OBJECT(object)->football_player.wait;
	OBJECT(object)->football_player.wait = wait - 1u;
	if (wait == 1u)
	{
		OBJECT(object)->football_player.charge_wait = 0x86u - rank - rank;
		state_wait = 0x600u;
		animation_number = 0x8300u;
		stage_boss_set_state(object, state_wait, animation_number);
		return state_wait;
	}
	return football_player_check_hit(object, enemy_handlers);
}

/* Flinches until its animation ends */
uint16_t football_player_flinch(uint16_t object, uint16_t states)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0, next_state = 0, next_wait = 0;
	uint16_t animation_number = 0, box = 0, ignored16 = 0, player = 0, state_wait = 0;
	uint8_t animation_flags = 0, attack_health = 0, vitality = 0, vitality_2 = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return states;
	state_wait = 0x206u;
	animation_number = 0x8000u;
	stage_boss_set_state(object, state_wait, animation_number);
	box = football_player_box_ADDRESS;
	stage_boss_set_hit_box(object, box);
	OBJECT(object)->flags = (OBJECT(object)->flags & ~4u) | 0xC0u;
	a = 0u;
	b = 0x3Cu;
	reach_x = ((uint32_t)a << 8) | b;
	reach_y = 0xC;
	stage_boss_find_near_player(object, &player, &ignored16, &carry);
	if (carry == 0u)
		return football_player_check_hit(object, player);
	attack_health = OBJECT(object)->football_player.attack_health;
	vitality = OBJECT(object)->vitality;
	if ((uint8_t)(attack_health - vitality) < 0xCu)
	{
		player = 0x7DA5u;
		next_wait = football_player_attack_delays_by_players[(int8_t)player_count - 1];
		next_state = 0x14u;
	}
	else
	{
		vitality_2 = OBJECT(object)->vitality;
		OBJECT(object)->football_player.attack_health = vitality_2;
		next_state = 0x14u;
		next_wait = 1u;
	}
	OBJECT(object)->target_dy = ((uint32_t)next_state << 8) | next_wait;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	return football_player_start_tackle(object, player);
}

/* Knocked back; stands up when it lands */
uint16_t football_player_knocked_back(uint16_t object, uint16_t landing_speed)
{
	uint32_t carry = 0;
	uint16_t animation_number = 0, state_wait = 0;

	stage_boss_move_on_screen(object, &landing_speed, &carry);
	if (carry == 0u)
		return landing_speed;
	state_wait = 0x600u;
	animation_number = 0x8300u;
	stage_boss_set_state(object, state_wait, animation_number);
	return state_wait;
}

/* Beaten and thrown; after landing goes to its last state with a cry */
uint16_t football_player_knocked_out(uint16_t object, uint16_t landing_speed)
{
	uint32_t carry = 0;
	uint16_t command = 0, state_wait = 0;
	uint8_t wait = 0;

	stage_boss_move_on_screen(object, &landing_speed, &carry);
	if (carry)
	{
		wait = OBJECT(object)->football_player.wait;
		OBJECT(object)->football_player.wait = wait - 1u;
		if (wait == 1u)
		{
			state_wait = 0x1278u;
			OBJECT(object)->football_player.phase = 0x12u;
			OBJECT(object)->football_player.wait = 0x78u;
			command = 0x3F3Au;
			carry = vector_queue_sound(command);
			return state_wait;
		}
	}
	return landing_speed;
}

/* Blinks out; then plays area_clear, marks the boss beaten and moves the stage on */
void football_player_defeated(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t t1 = 0;

	carry = stage_boss_blink_out(object);
	if (carry == 0u)
		return;
	t1 = io_read8(0x1850u);
	io_write8(0x1850u, 0u);
	command = 0x9600u;
	carry = vector_queue_sound_unless_attract(command);
	boss_beaten = 1u;
	step_phase++;
	step_subphase = 1u;
	step_countdown = 0u;
}

/* Its hits: a flinch, a knock back, or beaten (boss_defeated) and thrown */
uint16_t football_player_check_hit(uint16_t object, uint16_t u)
{
	uint32_t zero = 0, negative = 0, carry = 0;
	uint16_t animation_number = 0, command = 0, ignored16 = 0, object_2 = 0, request = 0, state_wait = 0, y = 0;
	uint8_t flinch_health = 0, vitality = 0, vitality_2 = 0, t1 = 0;

	y = football_player_beaten_vitality_ADDRESS;
	stage_boss_check_hit(object, y, &u, &zero, &negative);
	if (zero)
		return y;
	if (negative)
	{
		command = 0u;
		carry = vector_queue_sound(command);
		command = 0x9800u;
		carry = vector_queue_sound_unless_attract(command);
		state_wait = 0x1178u;
		animation_number = 0x8F00u;
		stage_boss_set_state(object, state_wait, animation_number);
		object_2 = 0x600u;
		y = 0x400u;
		stage_boss_knock_away(object, &y, &object_2);
		return y;
	}
	palette_request_kind = 2u;
	request = 0xEu;
	vector_palette_request(request, &ignored16, &u);
	flinch_health = OBJECT(object)->football_player.flinch_health;
	vitality = OBJECT(object)->vitality;
	if ((uint8_t)(flinch_health - vitality) <= 8u)
	{
		state_wait = 0xF06u;
		animation_number = 0x8D0Eu;
		stage_boss_set_state(object, state_wait, animation_number);
		return state_wait;
	}
	vitality_2 = OBJECT(object)->vitality;
	OBJECT(object)->football_player.flinch_health = vitality_2;
	state_wait = 0x1006u;
	animation_number = 0x8E0Eu;
	stage_boss_set_state(object, state_wait, animation_number);
	object_2 = 0x600u;
	y = 0x400u;
	stage_boss_knock_away(object, &y, &object_2);
	t1 = (uint8_t)OBJECT(object)->z;
	OBJECT(object)->z = (OBJECT(object)->z & 0xFF00u) | (t1 + 1u & 0xFFu);
	return football_player_knocked_back(object, y);
}
