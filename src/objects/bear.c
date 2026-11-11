/**
 *    Name:        objects/bear.c
 *    Description: stage 5's boss (type 20, kind A2) and its cage's parts
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    10-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Runs the bear, stage 5's boss: shows its gauge and runs its state */
uint16_t bear(uint16_t object, uint16_t enemy_handlers)
{
	uint8_t gauge_number = 0;
	uint16_t piece_health_by_players = 0, states = 0;
	uint8_t phase = 0;

	piece_health_by_players = bear_gauge_healths_ADDRESS;
	gauge_number = 3u;
	stage_boss_set_gauge(object, piece_health_by_players, gauge_number);
	phase = OBJECT(object)->bear.phase;
	states = bear_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)phase << 1))
	{
	case 0:
		bear_start(object);
		return object;
	case 2:
		leftover_y = states;
		bear_wait_entrance(object);
		return object;
	case 4:
		leftover_y = states;
		bear_stir(object);
		return object;
	case 6:
		leftover_y = states;
		return bear_break_out(object);
	case 8:
		leftover_y = states;
		bear_step_out(object);
		return object;
	case 10:
		bear_roar(object, enemy_handlers);
		return object;
	case 12:
		bear_choose_target(object, enemy_handlers);
		return object;
	case 14:
		bear_walk(object);
		return object;
	case 16:
		bear_swipe(object, enemy_handlers);
		return object;
	case 18:
		bear_start_charge(object, enemy_handlers);
		return object;
	case 20:
		bear_charge(object);
		return object;
	case 22:
	case 36:
		bear_recover(object);
		return object;
	case 24:
		leftover_y = states;
		bear_knocked_down(object);
		return object;
	case 26:
		leftover_y = states;
		bear_change(object);
		return object;
	case 28:
		leftover_y = states;
		bear_changed(object);
		return object;
	case 30:
		leftover_y = states;
		bear_long_get_up(object);
		return object;
	case 32:
		bear_get_up(object, enemy_handlers);
		return object;
	case 34:
		bear_attack_wait(object, enemy_handlers);
		return object;
	case 38:
		leftover_y = states;
		bear_defeated(object);
		return object;
	}
	unreachable();
}

/* A part of the bear's cage: shakes while the bear stirs, flies off as it breaks out */
void bear_part(uint16_t object)
{
	uint8_t phase = 0, z_speed_high = 0, z_speed_low = 0;
	uint16_t part_flight = 0, z = 0;
	uint8_t phase_2 = 0, z_2 = 0, parts_phase = 0, number = 0, number_2 = 0;
	uint16_t z_speed = 0, rebound_speed = 0, halved_rebound = 0, next_z_speed = 0, part_y = 0, flight_record = 0, speed_x = 0, flight_rest = 0, rest_height = 0;

	if (OBJECT(object)->flags == 4u)
	{
		OBJECT(object)->flags = 0x80u;
		OBJECT(object)->kind = 0x10u;
		OBJECT(object)->animation = 0x91u;
		return;
	}
	phase_2 = OBJECT(object)->bear_part.phase;
	if (phase_2 != 0u)
	{
		z_speed = OBJECT(object)->z_speed;
		z_speed_low = (uint8_t)z_speed;
		z_speed_high = (uint8_t)(z_speed >> 8);
		z_2 = (uint8_t)(OBJECT(object)->z >> 8u);
		if ((int8_t)z_2 < 0)
		{
			OBJECT(object)->z = 0u;
			rebound_speed = 0u - (((uint32_t)z_speed_high << 8) | (z_speed_low & 0xFFu));
			halved_rebound = (int16_t)rebound_speed >> 1;
			z_speed_low = (uint8_t)halved_rebound;
			z_speed_high = (uint8_t)(halved_rebound >> 8);
		}
		next_z_speed = (((uint32_t)z_speed_high << 8) | (z_speed_low & 0xFFu)) - 0x60u;
		OBJECT(object)->z_speed = next_z_speed;
		part_y = OBJECT(object)->y;
		if ((int16_t)part_y <= 0x76)
			OBJECT(object)->flags = 0u;
		return;
	}
	parts_phase = io_read8(0x184Au);
	phase = parts_phase;
	if (parts_phase == 0u)
		return;
	if (phase != 1u)
	{
		OBJECT(object)->bear_part.phase = phase;
		number = OBJECT(object)->bear_part.number;
		flight_record = bear_part_flights_ADDRESS + (int8_t)(((uint32_t)number << 1) << 1);
		speed_x = PART_FLIGHT(flight_record)->speed_x;
		OBJECT(object)->x_speed = speed_x;
		flight_rest = flight_record + 2u;
		part_flight = flight_rest + 1u;
		leftover_y = part_flight;
		OBJECT(object)->y_speed = (OBJECT(object)->y_speed & 0xFFu) | ((PART_FLIGHT(flight_rest - 0x2u)->speed_y & 0xFFu) << 8u);
		OBJECT(object)->z_speed = (OBJECT(object)->z_speed & 0xFFu) | ((PART_FLIGHT(part_flight - 0x3u)->speed_z & 0xFFu) << 8u);
		OBJECT(object)->flags = 0x88u;
		return;
	}
	number_2 = OBJECT(object)->bear_part.number;
	rest_height = OBJECT(object)->bear_part.rest_height;
	z = rest_height;
	if ((((uint8_t)frame_count + number_2) & 4u) != 0u)
		z += 2u;
	OBJECT(object)->z = z;
	OBJECT(object)->animation_flags = 0x80u;
	leftover_y = z;
}

/* A boulder the bear's stomp brings down: falls, bounces and hurts while the bear stands */
uint16_t bear_boulder(uint16_t object, uint16_t damage)
{
	uint32_t carry = 0;
	uint8_t flags = 0, word_high = 0, word_low = 0;
	uint16_t command = 0, object_2 = 0;
	uint8_t stack = 0, stack_10002 = 0;
	uint8_t landed = 0, animation_flags = 0, z = 0, landed_2 = 0, vitality = 0, vitality_2 = 0, parameter = 0;
	uint16_t z_speed = 0, rebound_speed = 0, rebound_twice = 0, rebound_thrice = 0, bounce_back_speed = 0, floor_y = 0, boulder_y = 0, landing_y = 0, next_z_speed = 0, parent = 0, parent_2 = 0, first_x = 0, first_y = 0;
	uint32_t box_width_halfword = 0;

	if (OBJECT(object)->flags != 4u)
	{
		landed = OBJECT(object)->bear_boulder.landed;
		if (landed != 0u)
		{
			animation_flags = OBJECT(object)->animation_flags;
			if ((animation_flags & 1u) != 0u)
				OBJECT(object)->flags = 0u;
			return damage;
		}
		z_speed = OBJECT(object)->z_speed;
		word_high = (uint8_t)(z_speed >> 8);
		word_low = (uint8_t)z_speed;
		z = (uint8_t)(OBJECT(object)->z >> 8u);
		if ((int8_t)z < 0)
		{
			if ((int16_t)(((uint32_t)word_high << 8) | word_low) < -0x110)
			{
				stack = word_high;
				stack_10002 = word_low;
				command = 0x6500u;
				carry = vector_queue_sound(command);
				word_high = stack;
				word_low = stack_10002;
				leftover_y = 0xFE80u;
				OBJECT(object)->y_speed = -0x180;
			}
			OBJECT(object)->z = 0u;
			rebound_speed = 0u - (((uint32_t)word_high << 8) | word_low);
			word_high = (uint8_t)(rebound_speed >> 8);
			word_low = (uint8_t)rebound_speed;
			boulder_bounce_speed = ((uint32_t)word_high << 8) | word_low;
			rebound_twice = (((uint32_t)word_high << 8) | word_low) + boulder_bounce_speed;
			rebound_thrice = rebound_twice + boulder_bounce_speed;
			bounce_back_speed = (int16_t)rebound_thrice >> 2;
			stack = bounce_back_speed >> 8;
			stack_10002 = bounce_back_speed;
			floor_y = 0x98u + camera_y;
			boulder_y = OBJECT(object)->y;
			landing_y = floor_y;
			word_high = stack;
			word_low = stack_10002;
			if ((int16_t)boulder_y <= (int16_t)landing_y)
			{
				OBJECT(object)->z_speed = 0;
				OBJECT(object)->y_speed = 0;
				OBJECT(object)->kind = 5u;
				OBJECT(object)->animation = 0x80u;
				landed_2 = OBJECT(object)->bear_boulder.landed;
				OBJECT(object)->bear_boulder.landed = landed_2 + 1u;
				return damage;
			}
		}
		next_z_speed = (((uint32_t)word_high << 8) | word_low) - 0x60u;
		OBJECT(object)->z_speed = next_z_speed;
		if ((frame_count & 1u) == 0u)
		{
			parent = OBJECT(object)->parent;
			object_2 = parent;
			flags = 0xC8u;
			damage = 0x401u;
			vitality = OBJECT(object_2)->vitality;
			if (vitality == 0u)
			{
				flags = 0x88u;
				damage = 0u;
			}
			OBJECT(object)->flags = flags;
			OBJECT(object)->damage = (uint8_t)(damage >> 8u);
			OBJECT(object)->attack = (uint8_t)damage;
		}
		else
		{
			OBJECT(object)->flags = 0x88u;
			parent_2 = OBJECT(object)->parent;
			vitality_2 = OBJECT(parent_2)->vitality;
			if (vitality_2 <= 0x48u)
			{
				parent = OBJECT(object)->parent;
				object_2 = parent;
				flags = 0xC8u;
				damage = 0x401u;
				vitality = OBJECT(object_2)->vitality;
				if (vitality == 0u)
				{
					flags = 0x88u;
					damage = 0u;
				}
				OBJECT(object)->flags = flags;
				OBJECT(object)->damage = (uint8_t)(damage >> 8u);
				OBJECT(object)->attack = (uint8_t)damage;
				leftover_y = object_2;
				return damage;
			}
			object_2 = 0x111u;
			OBJECT(object)->damage = 1u;
			OBJECT(object)->attack = 0x11u;
			check_hits_with_enemies(object);
		}
		leftover_y = object_2;
		return damage;
	}
	OBJECT(object)->flags = 0xC8u;
	OBJECT(object)->shadow_player = 0x40u;
	parameter = OBJECT(object)->parameter;
	if (parameter != 0u)
	{
		OBJECT(object)->kind = 0xAFu;
		OBJECT(object)->animation = 0x83u;
		word_high = 0x10u;
		word_low = 4u;
	}
	else
	{
		OBJECT(object)->kind = 0xAFu;
		OBJECT(object)->animation = 0x83u;
		word_high = 0x10u;
		word_low = 4u;
	}
	box_width_halfword = ((uint32_t)word_high << 8) | word_low;
	OBJECT(object)->box_width = (uint8_t)(box_width_halfword >> 8u);
	OBJECT(object)->box_depth = (uint8_t)box_width_halfword;
	OBJECT(object)->box_height = word_high;
	OBJECT(object)->box_dz = word_high;
	first_x = (uint8_t)((((random_number & 0x1Fu) << 1) << 1) << 1) + 0x60u;
	OBJECT(object)->x = first_x;
	first_y = 0xF0u + camera_y;
	OBJECT(object)->y = first_y;
	OBJECT(object)->z = 0x80u;
	return damage;
}

/* The effect shown as the beaten bear changes */
void bear_change_effect(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t animation_flags = 0;

	if (OBJECT(object)->flags == 4u)
	{
		OBJECT(object)->flags = 0x80u;
		OBJECT(object)->kind = 0x90u;
		OBJECT(object)->animation = 0x91u;
		command = 0x6C00u;
		carry = vector_queue_sound(command);
		return;
	}
	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
		OBJECT(object)->flags = 0u;
}

/* Sets the bear up and puts in the parts of its cage */
void bear_start(uint16_t object)
{
	uint8_t old_parts_phase = 0, phase = 0;
	uint16_t cage_x = 0, bear_x = 0;

	OBJECT(object)->kind = 0xA2u;
	OBJECT(object)->vitality = 0xE0u;
	OBJECT(object)->bear.flinch_health = 0xE0u;
	OBJECT(object)->bear.attack_health = 0xE0u;
	cage_x = OBJECT(object)->x;
	bear_x = cage_x + 0x40u;
	OBJECT(object)->x = bear_x;
	OBJECT(object)->enemy_class = -1;
	OBJECT(object)->entrance_pending = 0xFFu;
	OBJECT(object)->attributes = 0x40u;
	OBJECT(object)->hit_from_behind = 0x40u;
	cage_part_offsets = object_1e_part_offsets_ADDRESS;
	cage_part_number = 0u;
	cage_parts_left = 8u;
	leftover_y = bear_start_child_2_ADDRESS;
	bear_put_parts(object);
	cage_parts_left = 0xAu;
	leftover_y = bear_start_child_3_ADDRESS;
	bear_put_parts(object);
	cage_parts_left = 6u;
	leftover_y = bear_start_child_1_ADDRESS;
	bear_put_parts(object);
	old_parts_phase = io_read8(0x184Au);
	io_write8(0x184Au, 0u);
	phase = OBJECT(object)->bear.phase;
	OBJECT(object)->bear.phase = phase + 1u;
}

/* Puts in up to 11 cage parts from a child record, each at its offset */
void bear_put_parts(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t place_high = 0, place_low = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, part = 0;
	uint16_t saved_leftover_y = 0;
	uint8_t parts_left = 0;
	uint16_t offset_record = 0, offset_dx = 0, part_x = 0, placed_x = 0, dy_at = 0, offset_dy = 0, part_y = 0, placed_y = 0, dz_at = 0, offset_dz = 0, z = 0, placed_z = 0;
	uint32_t unk_50_halfword = 0, unk_52_halfword = 0;

	do
	{
		if ((int8_t)cage_part_number >= 0xB)
			break;
		saved_leftover_y = leftover_y;
		vector_spawn_child(object, &ignored16, &part, &ignored16_2, &carry);
		if (carry)
		{
			offset_record = cage_part_offsets;
			offset_dx = (int8_t)mem_read8(offset_record);
			part_x = OBJECT(part)->x;
			placed_x = offset_dx + part_x;
			place_high = (uint8_t)(placed_x >> 8);
			place_low = (uint8_t)placed_x;
			OBJECT(part)->x = ((uint32_t)place_high << 8) | place_low;
			unk_50_halfword = ((uint32_t)place_high << 8) | place_low;
			OBJECT(part)->unk_50 = (uint8_t)(unk_50_halfword >> 8u);
			OBJECT(part)->unk_51 = (uint8_t)unk_50_halfword;
			dy_at = offset_record + 1u;
			offset_dy = (int8_t)mem_read8(dy_at);
			part_y = OBJECT(part)->y;
			placed_y = offset_dy + part_y;
			place_high = (uint8_t)(placed_y >> 8);
			place_low = (uint8_t)placed_y;
			OBJECT(part)->y = ((uint32_t)place_high << 8) | place_low;
			unk_52_halfword = ((uint32_t)place_high << 8) | place_low;
			OBJECT(part)->unk_52 = (uint8_t)(unk_52_halfword >> 8u);
			OBJECT(part)->unk_53 = (uint8_t)unk_52_halfword;
			dz_at = dy_at + 1u;
			offset_dz = (int8_t)mem_read8(dz_at);
			z = OBJECT(part)->z;
			placed_z = offset_dz + z;
			place_high = (uint8_t)(placed_z >> 8);
			place_low = (uint8_t)placed_z;
			OBJECT(part)->z = ((uint32_t)place_high << 8) | place_low;
			OBJECT(part)->bear_part.rest_height = ((uint32_t)place_high << 8) | place_low;
			cage_part_offsets = dz_at + 1u;
			OBJECT(part)->enemy_class = -1;
			OBJECT(part)->entrance_pending = 0xFFu;
			OBJECT(part)->bear_part.number = cage_part_number;
			cage_part_number++;
		}
		leftover_y = saved_leftover_y;
		parts_left = cage_parts_left;
		cage_parts_left = parts_left - 1u;
	} while (parts_left != 1u);
}

/* Waits for the stage to let it in, then stirs */
void bear_wait_entrance(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t animation_number = 0, command = 0, state_wait = 0;

	if (stage_scrolls_on != 0u)
		return;
	command = 0xFD00u;
	carry = vector_queue_sound(command);
	OBJECT(object)->enemy_class = 0;
	OBJECT(object)->entrance_pending = 0u;
	leftover_y = 0x23Cu;
	state_wait = 0x23Cu;
	animation_number = 0x8A00u;
	stage_boss_set_state(object, state_wait, animation_number);
}

/* Shakes its cage, then starts breaking out */
void bear_stir(uint16_t object)
{
	uint16_t animation_number = 0, state_wait = 0;
	uint8_t wait = 0;

	wait = OBJECT(object)->bear.wait;
	OBJECT(object)->bear.wait = wait - 1u;
	if (wait == 1u)
	{
		io_write8(0x184Au, 1u);
		leftover_y = 0x3FAu;
		state_wait = 0x3FAu;
		animation_number = 0x8A00u;
		stage_boss_set_state(object, state_wait, animation_number);
		return;
	}
}

/* Breaks out of its cage: the parts shake, then fly; its tiles are cleared */
uint16_t bear_break_out(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t control = 0, fill = 0, parts_phase = 0, row_start_low = 0, wait_then_row_high = 0;
	uint16_t animation_number = 0, cell_place = 0, command = 0, count = 0, floor_row = 0, ignored16 = 0, state_wait = 0;
	uint8_t stack = 0, stack_2 = 0, stack_3 = 0, stack_4 = 0;
	uint8_t wait = 0, wait_2 = 0, row_mask = 0;
	uint16_t bear_y = 0, lowered_y = 0;

	wait = OBJECT(object)->bear.wait;
	OBJECT(object)->bear.wait = wait - 1u;
	if (wait == 1u)
	{
		state_wait = 0x428u;
		animation_number = 0x8000u;
		stage_boss_set_state(object, state_wait, animation_number);
		OBJECT(object)->x_speed = -0x100;
		OBJECT(object)->y_speed = -0x100;
		leftover_y = 0xFF00u;
		return object;
	}
	wait_2 = OBJECT(object)->bear.wait;
	wait_then_row_high = wait_2;
	if (wait_then_row_high == 0xDCu)
		boss_arrived = 1u;
	if ((int8_t)wait_then_row_high > 0x4B)
	{
		parts_phase = 0u;
		if ((wait_then_row_high & 0x10u) == 0u)
			parts_phase++;
		io_write8(0x184Au, parts_phase);
		return object;
	}
	if ((int8_t)wait_then_row_high < 0x4B)
		return object;
	floor_cell_under(object, &cell_place, &ignored16);
	control = board_control | 2u;
	board_control = control;
	io_write8(0x1FC2u, control);
	stack_2 = cell_place >> 8;
	stack = (uint8_t)cell_place;
	wait_then_row_high = stack_2;
	row_mask = io_read8(0xC0u);
	row_start_low = stack & row_mask;
	stack_2 = object >> 8;
	stack = (uint8_t)object;
	stack_3 = row_start_low;
	stack_4 = wait_then_row_high;
	floor_row = ((uint32_t)stack_4 << 8) | stack_3;
	count = 0x100u;
	fill = 0u;
	while (count != 0u)
	{
		mem_write8(floor_row, fill);
		floor_row++;
		count--;
	}
	object = ((uint32_t)stack_2 << 8) | stack;
	control = board_control & ~3u;
	board_control = control;
	io_write8(0x1FC2u, control);
	OBJECT(object)->flags = 0x80u;
	bear_y = OBJECT(object)->y;
	lowered_y = bear_y + 0x10u;
	OBJECT(object)->y = lowered_y;
	command = 0x7000u;
	carry = vector_queue_sound(command);
	parts_phase = 2u;
	io_write8(0x184Au, parts_phase);
	return object;
}

/* Steps out with a roar and takes its hit box */
void bear_step_out(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t animation_number = 0, box = 0, command = 0, state_wait = 0;
	uint8_t wait = 0, wait_2 = 0;

	boss_arrived = 0u;
	wait = OBJECT(object)->bear.wait;
	if (wait == 0x26u)
	{
		command = 0x3F37u;
		carry = vector_queue_sound(command);
	}
	wait_2 = OBJECT(object)->bear.wait;
	OBJECT(object)->bear.wait = wait_2 - 1u;
	if (wait_2 != 1u)
		return;
	box = bear_box_ADDRESS;
	stage_boss_set_hit_box(object, box);
	command = 0x7400u;
	carry = vector_queue_sound(command);
	leftover_y = 0x53Cu;
	state_wait = 0x53Cu;
	animation_number = 0x8900u;
	stage_boss_set_state(object, state_wait, animation_number);
}

/* Waits out its roar, then turns to a player */
void bear_roar(uint16_t object, uint16_t object_2)
{
	uint8_t wait = 0;

	wait = OBJECT(object)->bear.wait;
	OBJECT(object)->bear.wait = wait - 1u;
	if (wait != 1u)
	{
		bear_move(object, object_2);
		return;
	}
	bear_turn_to_player(object);
}

/* Takes state 6 facing the nearest player */
void bear_turn_to_player(uint16_t object)
{
	uint16_t state_wait = 0;

	state_wait = 0x610u;
	bear_face_player(object, state_wait);
}

/* Takes the state in Y facing the nearest player, hurtable */
void bear_face_player(uint16_t object, uint16_t state_wait)
{
	uint32_t carry = 0;
	uint16_t animation_number = 0, box = 0, chase_target = 0, command = 0;
	uint16_t stack = 0;
	uint8_t charged = 0, charged_2 = 0;

	stack = state_wait;
	box = bear_box_ADDRESS;
	stage_boss_set_hit_box(object, box);
	state_wait = stack;
	animation_number = 0x8900u;
	stage_boss_set_state(object, state_wait, animation_number);
	chase_target = vector_choose_nearest_player(object);
	OBJECT(object)->bear.chase_target = chase_target;
	stage_boss_unshield(object);
	charged = OBJECT(object)->bear.charged;
	if (charged != 0u)
	{
		bear_think(object, chase_target);
		return;
	}
	carry = stage_boss_any_player_down();
	if (carry == 0u)
	{
		bear_move(object, chase_target);
		return;
	}
	charged_2 = OBJECT(object)->bear.charged;
	OBJECT(object)->bear.charged = charged_2 + 1u;
	command = 0x7400u;
	carry = vector_queue_sound(command);
	state_wait = 0x53Cu;
	animation_number = 0x8A00u;
	stage_boss_set_state(object, state_wait, animation_number);
	bear_check_hit(object, chase_target);
}

/* Picks its target, at random or the nearest player, and walks */
void bear_choose_target(uint16_t object, uint16_t object_2)
{
	uint8_t roll = 0, target_low = 0;
	uint16_t animation_number = 0, chosen_target = 0, state_wait = 0;
	uint8_t stack = 0, stack_10002 = 0;
	uint8_t wait = 0;
	uint16_t player_offset = 0, player_object = 0;

	wait = OBJECT(object)->bear.wait;
	OBJECT(object)->bear.wait = wait - 1u;
	if (wait != 1u)
	{
		bear_move(object, object_2);
		return;
	}
	roll = random_number;
	if ((roll & 8u) == 0u)
	{
		player_offset = (roll & 3u) * 0xC0u;
		player_object = player_offset + OBJECT_ADDRESS(0);
		target_low = (uint8_t)player_object;
		stack = player_object >> 8;
		stack_10002 = target_low;
		chosen_target = ((uint32_t)stack << 8) | stack_10002;
		if (OBJECT(chosen_target)->flags == 0u)
		{
			animation_number = target_low;
			chosen_target = vector_choose_nearest_player(object);
		}
		OBJECT(object)->bear.chase_target = chosen_target;
		state_wait = 0x700u;
		animation_number |= 0x8000u;
		stage_boss_set_state(object, state_wait, animation_number);
		bear_move(object, chosen_target);
		return;
	}
	animation_number = target_low;
	chosen_target = vector_choose_nearest_player(object);
	OBJECT(object)->bear.chase_target = chosen_target;
	state_wait = 0x700u;
	animation_number |= 0x8000u;
	stage_boss_set_state(object, state_wait, animation_number);
	bear_move(object, chosen_target);
}

/* Walks at its target, shaking the screen and dropping boulders, and swipes at a player in reach */
void bear_walk(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t facing = 0, offset = 0;
	uint16_t animation_number = 0, command = 0, direction_word = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, object_2 = 0, player = 0, playing_bits = 0, speeds_by_rank = 0, state_wait = 0, target = 0;
	uint8_t stack = 0, stack_10002 = 0;
	uint8_t animation_flags = 0, vitality = 0, attributes = 0, attributes_2 = 0, animation_flags_2 = 0, attributes_3 = 0, animation_flags_3 = 0, attack_health = 0, vitality_2 = 0, vitality_3 = 0;
	uint16_t boulder_roll = 0, chase_target = 0, bear_x = 0, target_x = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) != 0u)
	{
		screen_shake_on = 1u;
		screen_shake_kind = 2u;
		command = 0x7500u;
		carry = vector_queue_sound(command);
		boulder_roll = (uint32_t)(uint8_t)((((uint32_t)rank << 1) << 1) << 1) * random_number;
		if (boulder_roll >= 0x3000u)
		{
			leftover_y = bear_boulder_child_1_ADDRESS;
			vitality = OBJECT(object)->vitality;
			if ((int8_t)vitality < 0x20 && (random_number & 3u) == 0u)
				leftover_y = bear_boulder_child_2_ADDRESS;
			vector_spawn_child(object, &ignored16, &ignored16_2, &ignored16_3, &carry);
		}
	}
	reach_x = 0x30;
	reach_y = 8;
	stage_boss_find_near_player(object, &ignored16_2, &playing_bits, &carry);
	offset = (uint8_t)playing_bits;
	if (carry == 0u)
	{
		chase_target = OBJECT(object)->bear.chase_target;
		target = chase_target;
		if ((frame_count & 7u) != 0u)
		{
			direction_word = offset;
			direction_word = vector_direction_to_offset(object, target, direction_word);
			speeds_by_rank = bear_walk_speeds_ADDRESS;
			stage_boss_walk_by_rank(object, speeds_by_rank, direction_word);
			bear_move(object, target);
			return;
		}
		attributes = OBJECT(object)->attributes;
		facing = attributes & 0x40u;
		bear_x = OBJECT(object)->x;
		target_x = OBJECT(target)->x;
		if ((int16_t)target_x <= (int16_t)bear_x)
		{
			offset = 0xDAu;
			if (facing != 0u)
			{
				direction_word = offset;
				direction_word = vector_direction_to_offset(object, target, direction_word);
				speeds_by_rank = bear_walk_speeds_ADDRESS;
				stage_boss_walk_by_rank(object, speeds_by_rank, direction_word);
				bear_move(object, target);
				return;
			}
			attributes_2 = OBJECT(object)->attributes;
			OBJECT(object)->attributes = attributes_2 | 0x40u;
			animation_flags_2 = OBJECT(object)->animation_flags;
			OBJECT(object)->animation_flags = animation_flags_2 | 0x80u;
			direction_word = offset;
			direction_word = vector_direction_to_offset(object, target, direction_word);
			speeds_by_rank = bear_walk_speeds_ADDRESS;
			stage_boss_walk_by_rank(object, speeds_by_rank, direction_word);
			bear_move(object, target);
			return;
		}
		offset = 0x26u;
		if (facing == 0u)
		{
			direction_word = offset;
			direction_word = vector_direction_to_offset(object, target, direction_word);
			speeds_by_rank = bear_walk_speeds_ADDRESS;
			stage_boss_walk_by_rank(object, speeds_by_rank, direction_word);
			bear_move(object, target);
			return;
		}
		attributes_3 = OBJECT(object)->attributes;
		OBJECT(object)->attributes = attributes_3 & 0xBFu;
		animation_flags_3 = OBJECT(object)->animation_flags;
		OBJECT(object)->animation_flags = animation_flags_3 | 0x80u;
		direction_word = offset;
		direction_word = vector_direction_to_offset(object, target, direction_word);
		speeds_by_rank = bear_walk_speeds_ADDRESS;
		stage_boss_walk_by_rank(object, speeds_by_rank, direction_word);
		bear_move(object, target);
		return;
	}
	command = 0x6A00u;
	carry = vector_queue_sound(command);
	OBJECT(object)->box_width = 0x28u;
	OBJECT(object)->box_dx = -6;
	player = stage_boss_face_nearest_player(object);
	if (player_count != 1u)
	{
		stage_boss_any_player_off_floor(&player, &carry);
		if (carry)
		{
			state_wait = 0x800u;
			animation_number = 0x81FAu;
			stage_boss_set_state(object, state_wait, animation_number);
			stage_boss_shield(object);
			bear_swipe(object, player);
			return;
		}
	}
	attack_health = OBJECT(object)->bear.attack_health;
	vitality_2 = OBJECT(object)->vitality;
	if ((uint8_t)(attack_health - vitality_2) > 0x10u)
	{
		vitality_3 = OBJECT(object)->vitality;
		OBJECT(object)->bear.attack_health = vitality_3;
		state_wait = 0x1101u;
		animation_number = 0x8AFAu;
		stage_boss_set_state(object, state_wait, animation_number);
		bear_move(object, player);
		return;
	}
	object_2 = 0x7E63u;
	stack = 0x11u;
	stack_10002 = bear_attack_delays_by_players[(int8_t)player_count - 1];
	state_wait = ((uint32_t)stack << 8) | stack_10002;
	animation_number = 0x8AFAu;
	stage_boss_set_state(object, state_wait, animation_number);
	bear_move(object, object_2);
}

/* After its wind-up, charges across the screen */
void bear_start_charge(uint16_t object, uint16_t enemy_handlers)
{
	uint8_t speed_high = 0, speed_low = 0;
	uint16_t animation_number = 0, box = 0, state_wait = 0;
	uint8_t stack = 0;
	uint8_t animation_flags = 0, attributes = 0, facing = 0;
	uint16_t charge_speed = 0, reversed_speed = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
	{
		bear_charge_check_hit(object, enemy_handlers);
		return;
	}
	OBJECT(object)->flags = 0xC0u;
	state_wait = 0xA00u;
	animation_number = 0x8C00u;
	stage_boss_set_state(object, state_wait, animation_number);
	charge_speed = bear_charge_speeds_by_rank[((rank >> 1) & ~1u) / 2u];
	speed_low = (uint8_t)charge_speed;
	stack = charge_speed >> 8;
	attributes = OBJECT(object)->attributes;
	facing = attributes & 0x40u;
	speed_high = stack;
	if (facing != 0u)
	{
		reversed_speed = 0u - (((uint32_t)speed_high << 8) | (speed_low & 0xFFu));
		speed_low = (uint8_t)reversed_speed;
		speed_high = (uint8_t)(reversed_speed >> 8);
	}
	OBJECT(object)->x_speed = ((uint32_t)speed_high << 8) | (speed_low & 0xFFu);
	box = bear_charge_box_ADDRESS;
	stage_boss_set_hit_box(object, box);
	bear_charge_check_hit(object, enemy_handlers);
}

/* Its hits while charging: flashes, or beaten */
void bear_charge_check_hit(uint16_t object, uint16_t u)
{
	uint32_t zero = 0, negative = 0, carry = 0;
	uint16_t health_limits = 0, request = 0;

	leftover_y = bear_beaten_vitality_ADDRESS;
	health_limits = bear_beaten_vitality_ADDRESS;
	stage_boss_check_hit(object, health_limits, &u, &zero, &negative);
	if (zero)
	{
		carry = stage_boss_move_on_screen(object);
		return;
	}
	if (negative)
	{
		bear_beaten(object);
		return;
	}
	palette_request_kind = 2u;
	request = 0x27u;
	vector_palette_request(u, request);
	OBJECT(object)->flags = 0xC4u;
	carry = stage_boss_move_on_screen(object);
}

/* Hurts while it charges; stops into a pose, then gets up */
void bear_charge(uint16_t object)
{
	uint8_t speed_low = 0;
	uint16_t animation_number = 0, charge_x = 0, state_wait = 0;
	uint16_t bear_x = 0, x_speed = 0;

	OBJECT(object)->damage = 8u;
	OBJECT(object)->attack = 9u;
	bear_x = OBJECT(object)->x;
	charge_x = bear_x;
	x_speed = OBJECT(object)->x_speed;
	speed_low = (uint8_t)x_speed;
	if (x_speed != 0u)
	{
		bear_charge_check_hit(object, charge_x);
		return;
	}
	OBJECT(object)->damage = 0u;
	OBJECT(object)->attack = 0u;
	OBJECT(object)->flags = 0xC0u;
	state_wait = 0x1000u;
	animation_number = (speed_low & 0xFFu) | 0x8800u;
	stage_boss_set_state(object, state_wait, animation_number);
	bear_charge_check_hit(object, charge_x);
}

/* Gets up unhurtable, then turns to a player */
void bear_get_up(uint16_t object, uint16_t object_2)
{
	uint16_t state_wait = 0;
	uint8_t animation_flags = 0;

	stage_boss_shield(object);
	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
	{
		bear_move(object, object_2);
		return;
	}
	state_wait = 0x603u;
	bear_face_player(object, state_wait);
}

/* Waits before its swipe, then swipes */
void bear_attack_wait(uint16_t object, uint16_t object_2)
{
	uint16_t animation_number = 0, state_wait = 0;
	uint8_t wait = 0;

	wait = OBJECT(object)->bear.wait;
	OBJECT(object)->bear.wait = wait - 1u;
	if (wait != 1u)
	{
		bear_move(object, object_2);
		return;
	}
	state_wait = 0x800u;
	animation_number = 0x8100u;
	stage_boss_set_state(object, state_wait, animation_number);
	stage_boss_shield(object);
	bear_swipe(object, object_2);
}

/* Its swipe's damage on the attack frames */
void bear_swipe(uint16_t object, uint16_t object_2)
{
	uint32_t carry = 0;
	uint16_t damage = 0;

	damage = 0x80Au;
	carry = stage_boss_attack_frame(object, damage);
	if (carry)
	{
		bear_turn_to_player(object);
		return;
	}
	bear_check_hit(object, object_2);
}

/* Moves until its animation ends, then turns to a player */
void bear_recover(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t state_wait = 0;
	uint8_t animation_flags = 0;

	carry = stage_boss_move_on_screen(object);
	leftover_y = 0x601u;
	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) != 0u)
	{
		state_wait = (uint16_t)leftover_y;
		bear_face_player(object, state_wait);
		return;
	}
}

/* Knocked down: lands shaking the screen, maybe bringing boulders down */
void bear_knocked_down(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, object_2 = 0;
	uint8_t wait = 0, wait_2 = 0;

	carry = stage_boss_move_on_screen(object);
	if (carry == 0u)
		return;
	wait = OBJECT(object)->bear.wait;
	if (wait == 0u)
	{
		bear_land(object);
		return;
	}
	wait_2 = OBJECT(object)->bear.wait;
	OBJECT(object)->bear.wait = wait_2 - 1u;
	if (wait_2 != 1u)
	{
		screen_shake_on = 1u;
		screen_shake_kind = 1u;
		if ((int8_t)rank <= 0xC)
		{
			if ((int8_t)random_number >= 0)
			{
				bear_land(object);
				return;
			}
			leftover_y = 0x280u;
			object_2 = 0x400u;
			stage_boss_knock_away(object, object_2);
			return;
		}
		leftover_y = bear_boulder_child_1_ADDRESS;
		vector_spawn_child(object, &ignored16, &ignored16_2, &ignored16_3, &carry);
		if ((int8_t)rank <= 0x14)
		{
			if ((int8_t)random_number >= 0)
			{
				bear_land(object);
				return;
			}
			leftover_y = 0x280u;
			object_2 = 0x400u;
			stage_boss_knock_away(object, object_2);
			return;
		}
		leftover_y = bear_boulder_child_1_ADDRESS;
		vector_spawn_child(object, &ignored16, &ignored16_2, &ignored16_3, &carry);
		if ((int8_t)random_number >= 0)
		{
			bear_land(object);
			return;
		}
		leftover_y = 0x280u;
		object_2 = 0x400u;
		stage_boss_knock_away(object, object_2);
		return;
	}
	screen_shake_on = 1u;
	screen_shake_kind = 1u;
	if ((int8_t)rank <= 8)
		return;
	leftover_y = bear_boulder_child_1_ADDRESS;
	vector_spawn_child(object, &ignored16, &ignored16_2, &ignored16_3, &carry);
	if ((int8_t)rank > 0xF)
	{
		leftover_y = bear_boulder_child_1_ADDRESS;
		vector_spawn_child(object, &ignored16, &ignored16_2, &ignored16_3, &carry);
	}
}

/* Unused: lands the bear, stopping its x speed when it is outside the area it keeps to. */
void unused_bear_land_in_area(uint16_t object)
{
	uint16_t place_x = 0;
	uint16_t current_x = 0;

	current_x = OBJECT(object)->x;
	place_x = current_x;
	if ((int16_t)place_x >= 0x70 || (int16_t)place_x <= 0x140)
	{
		bear_land(object);
		return;
	}
	OBJECT(object)->x_speed = 0;
	bear_land(object);
}

/* Its landing after a knock-down: recovers (a longer animation every fourth time), or, beaten, starts
   its change */
void bear_land(uint16_t object)
{
	uint16_t animation_number = 0, state_wait = 0;
	uint8_t vitality = 0, bounces = 0, bounces_2 = 0, animation_flags = 0;

	vitality = OBJECT(object)->vitality;
	if (vitality == 0u)
	{
		leftover_y = 0xDC8u;
		state_wait = 0xDC8u;
		animation_number = 0x8600u;
		stage_boss_set_state(object, state_wait, animation_number);
		OBJECT(object)->flags = 0x80u;
		OBJECT(object)->zoom_x = 0x40u;
		OBJECT(object)->zoom_y = 0x40u;
		OBJECT(object)->damage = 0u;
		OBJECT(object)->attack = 0u;
		return;
	}
	bounces = OBJECT(object)->bear.bounces;
	OBJECT(object)->bear.bounces = bounces + 1u;
	bounces_2 = OBJECT(object)->bear.bounces;
	if (bounces_2 > 3u)
	{
		OBJECT(object)->bear.bounces = 0u;
		leftover_y = 0xF00u;
		state_wait = 0xF00u;
		animation_number = 0x8400u;
		stage_boss_set_state(object, state_wait, animation_number);
		return;
	}
	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	leftover_y = 0x1200u;
	state_wait = 0x1200u;
	animation_number = 0x8800u;
	stage_boss_set_state(object, state_wait, animation_number);
}

/* Every fourth knock-down's longer animation, then it recovers */
void bear_long_get_up(uint16_t object)
{
	uint16_t animation_number = 0, state_wait = 0;
	uint8_t animation_flags = 0, animation_flags_2 = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) != 0u)
	{
		animation_flags_2 = OBJECT(object)->animation_flags;
		if ((animation_flags_2 & 1u) != 0u)
		{
			leftover_y = 0x1200u;
			state_wait = 0x1200u;
			animation_number = 0x8800u;
			stage_boss_set_state(object, state_wait, animation_number);
			return;
		}
	}
}

/* Beaten, swells and changes into kind 81 (the fat goon's set) */
void bear_change(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t wait = 0, zoom = 0;
	uint16_t child_z = 0, ignored16 = 0, ignored16_2 = 0;
	uint8_t wait_before = 0, wait_left = 0, zoom_x = 0;

	wait_before = io_read8(0x2Fu);
	io_write8(0x2Fu, wait_before - 1u);
	if (wait_before == 1u)
	{
		OBJECT(object)->bear.phase = 0xEu;
		OBJECT(object)->bear.wait = 0x78u;
		OBJECT(object)->kind = 0x81u;
		OBJECT(object)->animation = 0xBBu;
		bear_changed(object);
		return;
	}
	wait_left = io_read8(0x2Fu);
	wait = wait_left;
	if (wait == 0x11u)
	{
		leftover_y = bear_change_child_ADDRESS;
		vector_spawn_child(object, &ignored16, &ignored16_2, &child_z, &carry);
		wait = (uint8_t)(child_z >> 8);
	}
	if (wait <= 0x28u)
	{
		OBJECT(object)->flags = 0x90u;
		zoom_x = OBJECT(object)->zoom_x;
		zoom = zoom_x + 1u;
		OBJECT(object)->zoom_x = zoom;
		OBJECT(object)->zoom_y = zoom;
	}
}

/* Waits as its new self, then blinks out */
void bear_changed(uint16_t object)
{
	uint8_t wait = 0;

	wait = OBJECT(object)->bear.wait;
	OBJECT(object)->bear.wait = wait - 1u;
	if (wait == 1u)
	{
		OBJECT(object)->bear.phase = 0x13u;
		OBJECT(object)->bear.wait = 0x5Au;
		return;
	}
}

/* Blinks out; then plays area_clear, marks the boss beaten and moves the stage on */
void bear_defeated(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;

	carry = stage_boss_blink_out(object);
	if (carry == 0u)
		return;
	command = 0x9600u;
	carry = vector_queue_sound_unless_attract(command);
	boss_beaten = 1u;
	step_phase++;
	step_subphase = 1u;
	step_countdown = 0u;
}

/* Moves it on the screen, then decides whether to charge */
void bear_move(uint16_t object, uint16_t object_2)
{
	uint32_t carry = 0;

	carry = stage_boss_move_on_screen(object);
	OBJECT(object)->bear.charged = 0u;
	bear_think(object, object_2);
}

/* Charges now and then (more often with more players), unless a lone player is down */
void bear_think(uint16_t object, uint16_t object_2)
{
	uint32_t carry = 0;
	uint16_t animation_number = 0, bear_x = 0, command = 0, state_wait = 0;
	uint8_t stack = 0;
	uint8_t charge_timer = 0;
	uint16_t x_now = 0;

	OBJECT(object)->flags |= 0xC0u;
	stack = ((((uint32_t)player_count << 1) << 1) << 1) << 1;
	charge_timer = OBJECT(object)->bear.charge_timer;
	if (charge_timer < (uint8_t)(0x96u - stack))
	{
		bear_check_hit(object, object_2);
		return;
	}
	OBJECT(object)->bear.charge_timer = 0u;
	if (player_count == 1u)
	{
		carry = stage_boss_any_player_down();
		if (carry)
		{
			bear_check_hit(object, object_2);
			return;
		}
	}
	command = 0x7400u;
	carry = vector_queue_sound(command);
	x_now = OBJECT(object)->x;
	bear_x = x_now;
	if ((int16_t)bear_x >= 0x58)
	{
		if ((int16_t)bear_x > 0x162)
			OBJECT(object)->attributes = 0x40u;
	}
	else
		OBJECT(object)->attributes = 0u;
	state_wait = 0x900u;
	animation_number = 0x8B00u;
	stage_boss_set_state(object, state_wait, animation_number);
	bear_check_hit(object, object_2);
}

/* Its hits: flinches with a flash, is knocked down or beaten */
void bear_check_hit(uint16_t object, uint16_t object_2)
{
	uint32_t zero = 0, negative = 0, carry = 0;
	uint8_t flinch_animation = 0;
	uint16_t animation_number = 0, health_limits = 0, request = 0, state_wait = 0;
	uint8_t charge_timer = 0, charge_timer_2 = 0, attributes = 0, attributes_2 = 0, vitality = 0, flinch_health = 0, vitality_2 = 0;

	carry = stage_boss_move_on_screen(object);
	charge_timer = OBJECT(object)->bear.charge_timer;
	if (charge_timer != 0xFFu)
	{
		charge_timer_2 = OBJECT(object)->bear.charge_timer;
		OBJECT(object)->bear.charge_timer = charge_timer_2 + 1u;
	}
	leftover_y = bear_beaten_vitality_ADDRESS;
	health_limits = bear_beaten_vitality_ADDRESS;
	stage_boss_check_hit(object, health_limits, &object_2, &zero, &negative);
	if (zero)
		return;
	attributes = OBJECT(object)->attributes;
	attributes_2 = OBJECT(object_2)->attributes;
	if ((attributes ^ attributes_2) == 0u)
	{
		leftover_y = 0xB00u;
		flinch_animation = 0x83u;
	}
	else
	{
		leftover_y = 0xB00u;
		flinch_animation = 0x82u;
	}
	state_wait = (uint16_t)leftover_y;
	animation_number = (uint32_t)flinch_animation << 8;
	stage_boss_set_state(object, state_wait, animation_number);
	palette_request_kind = 2u;
	request = 0x27u;
	vector_palette_request(object_2, request);
	vitality = OBJECT(object)->vitality;
	if (vitality == 0u)
	{
		bear_beaten(object);
		return;
	}
	flinch_health = OBJECT(object)->bear.flinch_health;
	vitality_2 = OBJECT(object)->vitality;
	if ((uint8_t)(flinch_health - vitality_2) > 0xCu)
	{
		bear_knocked_away(object);
		return;
	}
}

/* Stops the sounds, plays boss_defeated and knocks it away */
void bear_beaten(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;

	command = 0u;
	carry = vector_queue_sound(command);
	command = 0x9800u;
	carry = vector_queue_sound_unless_attract(command);
	bear_knocked_away(object);
}

/* Knocked away, shaking the screen */
void bear_knocked_away(uint16_t object)
{
	uint16_t animation_number = 0, object_2 = 0, state_wait = 0;
	uint8_t vitality = 0;

	vitality = OBJECT(object)->vitality;
	OBJECT(object)->bear.flinch_health = vitality;
	state_wait = 0xC02u;
	animation_number = 0x8500u;
	stage_boss_set_state(object, state_wait, animation_number);
	screen_shake_on = 1u;
	screen_shake_kind = 1u;
	object_2 = 0x500u;
	leftover_y = 0x380u;
	stage_boss_knock_away(object, object_2);
}
