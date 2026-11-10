/**
 *    Name:        objects/bear.c
 *    Description: stage 5's boss (type 20, kind A2) and its cage's parts
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Runs the bear, stage 5's boss: shows its gauge and runs its state */
void bear(uint16_t enemy_handlers, uint16_t *p_object, uint16_t *p_states)
{
	uint16_t object = (uint16_t)*p_object;
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
		states = bear_start(object);
		break;
	case 2:
		states = bear_wait_entrance(object, states);
		break;
	case 4:
		states = bear_stir(object, states);
		break;
	case 6:
		bear_break_out(&object, &states);
		break;
	case 8:
		states = bear_step_out(object, states);
		break;
	case 10:
		states = bear_roar(object, enemy_handlers);
		break;
	case 12:
		states = bear_choose_target(object, enemy_handlers);
		break;
	case 14:
		states = bear_walk(object);
		break;
	case 16:
		states = bear_swipe(object, enemy_handlers);
		break;
	case 18:
		states = bear_start_charge(object, enemy_handlers);
		break;
	case 20:
		states = bear_charge(object);
		break;
	case 22:
	case 36:
		states = bear_recover(object);
		break;
	case 24:
		states = bear_knocked_down(object, states);
		break;
	case 26:
		states = bear_change(object, states);
		break;
	case 28:
		bear_changed(object);
		break;
	case 30:
		states = bear_long_get_up(object, states);
		break;
	case 32:
		states = bear_get_up(object, enemy_handlers);
		break;
	case 34:
		states = bear_attack_wait(object, enemy_handlers);
		break;
	case 38:
		bear_defeated(object);
		break;
	}
	*p_object = object;
	*p_states = states;
}

/* A part of the bear's cage: shakes while the bear stirs, flies off as it breaks out */
uint16_t bear_part(uint16_t object, uint16_t part_flight)
{
	uint8_t a = 0, d = 0, phase = 0;
	uint8_t phase_2 = 0, z = 0, t5 = 0, number = 0, number_2 = 0;
	uint16_t z_speed = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t6 = 0, speed_x = 0, t7 = 0, rest_height = 0;

	if (OBJECT(object)->flags == 4u)
	{
		OBJECT(object)->flags = 0x80u;
		OBJECT(object)->kind = 0x10u;
		OBJECT(object)->animation = 0x91u;
		return part_flight;
	}
	phase_2 = OBJECT(object)->bear_part.phase;
	if (phase_2 != 0u)
	{
		z_speed = OBJECT(object)->z_speed;
		d = (uint8_t)z_speed;
		a = (uint8_t)(z_speed >> 8);
		z = (uint8_t)(OBJECT(object)->z >> 8u);
		if ((int8_t)z < 0)
		{
			OBJECT(object)->z = 0u;
			t1 = 0u - (((uint32_t)a << 8) | (d & 0xFFu));
			t2 = (int16_t)t1 >> 1;
			d = (uint8_t)t2;
			a = (uint8_t)(t2 >> 8);
		}
		t3 = (((uint32_t)a << 8) | (d & 0xFFu)) - 0x60u;
		OBJECT(object)->z_speed = t3;
		t4 = OBJECT(object)->y;
		if ((int16_t)t4 <= 0x76)
			OBJECT(object)->flags = 0u;
		return part_flight;
	}
	t5 = io_read8(0x184Au);
	phase = t5;
	if (t5 == 0u)
		return part_flight;
	if (phase != 1u)
	{
		OBJECT(object)->bear_part.phase = phase;
		number = OBJECT(object)->bear_part.number;
		t6 = bear_part_flights_ADDRESS + (int8_t)(((uint32_t)number << 1) << 1);
		speed_x = PART_FLIGHT(t6)->speed_x;
		OBJECT(object)->x_speed = speed_x;
		t7 = t6 + 2u;
		part_flight = t7 + 1u;
		OBJECT(object)->y_speed = (OBJECT(object)->y_speed & 0xFFu) | ((PART_FLIGHT(t7 - 0x2u)->speed_y & 0xFFu) << 8u);
		OBJECT(object)->z_speed = (OBJECT(object)->z_speed & 0xFFu) | ((PART_FLIGHT(part_flight - 0x3u)->speed_z & 0xFFu) << 8u);
		OBJECT(object)->flags = 0x88u;
		return part_flight;
	}
	number_2 = OBJECT(object)->bear_part.number;
	rest_height = OBJECT(object)->bear_part.rest_height;
	part_flight = rest_height;
	if ((((uint8_t)frame_count + number_2) & 4u) != 0u)
		part_flight += 2u;
	OBJECT(object)->z = part_flight;
	OBJECT(object)->animation_flags = 0x80u;
	return part_flight;
}

/* A boulder the bear's stomp brings down: falls, bounces and hurts while the bear stands */
void bear_boulder(uint16_t object, uint16_t *p_object_2, uint16_t *p_damage)
{
	uint16_t object_2 = (uint16_t)*p_object_2;
	uint16_t damage = (uint16_t)*p_damage;
	uint32_t carry = 0;
	uint8_t a = 0, b = 0, flags = 0;
	uint16_t command = 0;
	uint8_t stack = 0, stack_10002 = 0;
	uint8_t landed = 0, animation_flags = 0, z = 0, vitality = 0, vitality_2 = 0, landed_2 = 0, parameter = 0;
	uint16_t z_speed = 0, t1 = 0, parent = 0, parent_2 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0;
	uint32_t box_width_halfword = 0;

	if (OBJECT(object)->flags != 4u)
	{
		landed = OBJECT(object)->bear_boulder.landed;
		if (landed != 0u)
		{
			animation_flags = OBJECT(object)->animation_flags;
			if ((animation_flags & 1u) != 0u)
				OBJECT(object)->flags = 0u;
		}
		else
		{
			z_speed = OBJECT(object)->z_speed;
			a = (uint8_t)(z_speed >> 8);
			b = (uint8_t)z_speed;
			z = (uint8_t)(OBJECT(object)->z >> 8u);
			if ((int8_t)z >= 0)
			{
				t1 = (((uint32_t)a << 8) | b) - 0x60u;
				OBJECT(object)->z_speed = t1;
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
					}
					else
					{
						object_2 = 0x111u;
						OBJECT(object)->damage = 1u;
						OBJECT(object)->attack = 0x11u;
						check_hits_with_enemies(object);
					}
				}
			}
			else
			{
				if ((int16_t)(((uint32_t)a << 8) | b) < -0x110)
				{
					stack = a;
					stack_10002 = b;
					command = 0x6500u;
					carry = vector_queue_sound(command);
					a = stack;
					b = stack_10002;
					object_2 = 0xFE80u;
					OBJECT(object)->y_speed = -0x180;
				}
				OBJECT(object)->z = 0u;
				t2 = 0u - (((uint32_t)a << 8) | b);
				a = (uint8_t)(t2 >> 8);
				b = (uint8_t)t2;
				boulder_bounce_speed = ((uint32_t)a << 8) | b;
				t3 = (((uint32_t)a << 8) | b) + boulder_bounce_speed;
				t4 = t3 + boulder_bounce_speed;
				t5 = (int16_t)t4 >> 2;
				stack = t5 >> 8;
				stack_10002 = t5;
				t6 = 0x98u + camera_y;
				t7 = OBJECT(object)->y;
				t8 = t6;
				a = stack;
				b = stack_10002;
				if ((int16_t)t7 <= (int16_t)t8)
				{
					OBJECT(object)->z_speed = 0;
					OBJECT(object)->y_speed = 0;
					OBJECT(object)->kind = 5u;
					OBJECT(object)->animation = 0x80u;
					landed_2 = OBJECT(object)->bear_boulder.landed;
					OBJECT(object)->bear_boulder.landed = landed_2 + 1u;
				}
				else
				{
					t1 = (((uint32_t)a << 8) | b) - 0x60u;
					OBJECT(object)->z_speed = t1;
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
						}
						else
						{
							object_2 = 0x111u;
							OBJECT(object)->damage = 1u;
							OBJECT(object)->attack = 0x11u;
							check_hits_with_enemies(object);
						}
					}
				}
			}
		}
	}
	else
	{
		OBJECT(object)->flags = 0xC8u;
		OBJECT(object)->shadow_player = 0x40u;
		parameter = OBJECT(object)->parameter;
		if (parameter != 0u)
		{
			OBJECT(object)->kind = 0xAFu;
			OBJECT(object)->animation = 0x83u;
			a = 0x10u;
			b = 4u;
		}
		else
		{
			OBJECT(object)->kind = 0xAFu;
			OBJECT(object)->animation = 0x83u;
			a = 0x10u;
			b = 4u;
		}
		box_width_halfword = ((uint32_t)a << 8) | b;
		OBJECT(object)->box_width = (uint8_t)(box_width_halfword >> 8u);
		OBJECT(object)->box_depth = (uint8_t)box_width_halfword;
		OBJECT(object)->box_height = a;
		OBJECT(object)->box_dz = a;
		t9 = (uint8_t)((((random_number & 0x1Fu) << 1) << 1) << 1) + 0x60u;
		OBJECT(object)->x = t9;
		t10 = 0xF0u + camera_y;
		OBJECT(object)->y = t10;
		OBJECT(object)->z = 0x80u;
	}
	*p_object_2 = object_2;
	*p_damage = damage;
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
uint16_t bear_start(uint16_t object)
{
	uint16_t record = 0;
	uint8_t t3 = 0, phase = 0;
	uint16_t t1 = 0, t2 = 0;

	OBJECT(object)->kind = 0xA2u;
	OBJECT(object)->vitality = 0xE0u;
	OBJECT(object)->bear.flinch_health = 0xE0u;
	OBJECT(object)->bear.attack_health = 0xE0u;
	t1 = OBJECT(object)->x;
	t2 = t1 + 0x40u;
	OBJECT(object)->x = t2;
	OBJECT(object)->enemy_class = -1;
	OBJECT(object)->entrance_pending = 0xFFu;
	OBJECT(object)->attributes = 0x40u;
	OBJECT(object)->hit_from_behind = 0x40u;
	cage_part_offsets = object_1e_part_offsets_ADDRESS;
	cage_part_number = 0u;
	cage_parts_left = 8u;
	record = bear_start_child_2_ADDRESS;
	bear_put_parts(object, record);
	cage_parts_left = 0xAu;
	record = bear_start_child_3_ADDRESS;
	bear_put_parts(object, record);
	cage_parts_left = 6u;
	record = bear_start_child_1_ADDRESS;
	bear_put_parts(object, record);
	t3 = io_read8(0x184Au);
	io_write8(0x184Au, 0u);
	phase = OBJECT(object)->bear.phase;
	OBJECT(object)->bear.phase = phase + 1u;
	return record;
}

/* Puts in up to 11 cage parts from a child record, each at its offset */
void bear_put_parts(uint16_t object, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t ignored16 = 0, part = 0;
	uint16_t stack = 0;
	uint8_t t12 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, z = 0, t11 = 0;
	uint32_t unk_50_halfword = 0, unk_52_halfword = 0;

	do
	{
		if ((int8_t)cage_part_number >= 0xB)
			break;
		stack = y;
		vector_spawn_child(object, y, &part, &ignored16, &carry);
		if (carry)
		{
			t1 = cage_part_offsets;
			t2 = (int8_t)mem_read8(t1);
			t3 = OBJECT(part)->x;
			t4 = t2 + t3;
			a = (uint8_t)(t4 >> 8);
			b = (uint8_t)t4;
			OBJECT(part)->x = ((uint32_t)a << 8) | b;
			unk_50_halfword = ((uint32_t)a << 8) | b;
			OBJECT(part)->unk_50 = (uint8_t)(unk_50_halfword >> 8u);
			OBJECT(part)->unk_51 = (uint8_t)unk_50_halfword;
			t5 = t1 + 1u;
			t6 = (int8_t)mem_read8(t5);
			t7 = OBJECT(part)->y;
			t8 = t6 + t7;
			a = (uint8_t)(t8 >> 8);
			b = (uint8_t)t8;
			OBJECT(part)->y = ((uint32_t)a << 8) | b;
			unk_52_halfword = ((uint32_t)a << 8) | b;
			OBJECT(part)->unk_52 = (uint8_t)(unk_52_halfword >> 8u);
			OBJECT(part)->unk_53 = (uint8_t)unk_52_halfword;
			t9 = t5 + 1u;
			t10 = (int8_t)mem_read8(t9);
			z = OBJECT(part)->z;
			t11 = t10 + z;
			a = (uint8_t)(t11 >> 8);
			b = (uint8_t)t11;
			OBJECT(part)->z = ((uint32_t)a << 8) | b;
			OBJECT(part)->bear_part.rest_height = ((uint32_t)a << 8) | b;
			cage_part_offsets = t9 + 1u;
			OBJECT(part)->enemy_class = -1;
			OBJECT(part)->entrance_pending = 0xFFu;
			OBJECT(part)->bear_part.number = cage_part_number;
			cage_part_number++;
		}
		y = stack;
		t12 = cage_parts_left;
		cage_parts_left = t12 - 1u;
	} while (t12 != 1u);
}

/* Waits for the stage to let it in, then stirs */
uint16_t bear_wait_entrance(uint16_t object, uint16_t states)
{
	uint32_t carry = 0;
	uint16_t animation_number = 0, command = 0, state_wait = 0;

	if (stage_scrolls_on != 0u)
		return states;
	command = 0xFD00u;
	carry = vector_queue_sound(command);
	OBJECT(object)->enemy_class = 0;
	OBJECT(object)->entrance_pending = 0u;
	state_wait = 0x23Cu;
	animation_number = 0x8A00u;
	stage_boss_set_state(object, state_wait, animation_number);
	return state_wait;
}

/* Shakes its cage, then starts breaking out */
uint16_t bear_stir(uint16_t object, uint16_t states)
{
	uint16_t animation_number = 0, state_wait = 0;
	uint8_t wait = 0;

	wait = OBJECT(object)->bear.wait;
	OBJECT(object)->bear.wait = wait - 1u;
	if (wait == 1u)
	{
		io_write8(0x184Au, 1u);
		state_wait = 0x3FAu;
		animation_number = 0x8A00u;
		stage_boss_set_state(object, state_wait, animation_number);
		return state_wait;
	}
	return states;
}

/* Breaks out of its cage: the parts shake, then fly; its tiles are cleared */
void bear_break_out(uint16_t *p_object, uint16_t *p_y)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t a = 0, b = 0, control = 0, fill = 0, parts_phase = 0;
	uint16_t animation_number = 0, cell_place = 0, command = 0, count = 0, floor_row = 0, ignored16 = 0, state_wait = 0;
	uint8_t stack = 0, stack_2 = 0, stack_3 = 0, stack_4 = 0;
	uint8_t wait = 0, wait_2 = 0, t1 = 0;
	uint16_t t2 = 0, t3 = 0;

	wait = OBJECT(object)->bear.wait;
	OBJECT(object)->bear.wait = wait - 1u;
	if (wait == 1u)
	{
		state_wait = 0x428u;
		animation_number = 0x8000u;
		stage_boss_set_state(object, state_wait, animation_number);
		OBJECT(object)->x_speed = -0x100;
		y = 0xFF00u;
		OBJECT(object)->y_speed = -0x100;
	}
	else
	{
		wait_2 = OBJECT(object)->bear.wait;
		a = wait_2;
		if (a == 0xDCu)
			boss_arrived = 1u;
		if ((int8_t)a > 0x4B)
		{
			parts_phase = 0u;
			if ((a & 0x10u) == 0u)
				parts_phase++;
			io_write8(0x184Au, parts_phase);
		}
		else if ((int8_t)a >= 0x4B)
		{
			floor_cell_under(object, &cell_place, &ignored16);
			control = board_control | 2u;
			board_control = control;
			io_write8(0x1FC2u, control);
			stack_2 = cell_place >> 8;
			stack = (uint8_t)cell_place;
			a = stack_2;
			t1 = io_read8(0xC0u);
			b = stack & t1;
			stack_2 = object >> 8;
			stack = (uint8_t)object;
			stack_3 = b;
			stack_4 = a;
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
			mem_write8(object, 0x80u);
			t2 = io_read16(object + 0x11u);
			t3 = t2 + 0x10u;
			io_write16(object + 0x11u, t3);
			command = 0x7000u;
			carry = vector_queue_sound(command);
			parts_phase = 2u;
			io_write8(0x184Au, parts_phase);
		}
	}
	*p_object = object;
	*p_y = y;
}

/* Steps out with a roar and takes its hit box */
uint16_t bear_step_out(uint16_t object, uint16_t states)
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
		return states;
	box = bear_box_ADDRESS;
	stage_boss_set_hit_box(object, box);
	command = 0x7400u;
	carry = vector_queue_sound(command);
	state_wait = 0x53Cu;
	animation_number = 0x8900u;
	stage_boss_set_state(object, state_wait, animation_number);
	return state_wait;
}

/* Waits out its roar, then turns to a player */
uint16_t bear_roar(uint16_t object, uint16_t object_2)
{
	uint8_t wait = 0;

	wait = OBJECT(object)->bear.wait;
	OBJECT(object)->bear.wait = wait - 1u;
	if (wait != 1u)
		return bear_move(object, object_2);
	return bear_turn_to_player(object);
}

/* Takes state 6 facing the nearest player */
uint16_t bear_turn_to_player(uint16_t object)
{
	uint16_t state_wait = 0;

	state_wait = 0x610u;
	return bear_face_player(object, state_wait);
}

/* Takes the state in Y facing the nearest player, hurtable */
uint16_t bear_face_player(uint16_t object, uint16_t state_wait)
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
		return bear_think(object, chase_target);
	carry = stage_boss_any_player_down();
	if (carry == 0u)
		return bear_move(object, chase_target);
	charged_2 = OBJECT(object)->bear.charged;
	OBJECT(object)->bear.charged = charged_2 + 1u;
	command = 0x7400u;
	carry = vector_queue_sound(command);
	state_wait = 0x53Cu;
	animation_number = 0x8A00u;
	stage_boss_set_state(object, state_wait, animation_number);
	return bear_check_hit(object, chase_target);
}

/* Picks its target, at random or the nearest player, and walks */
uint16_t bear_choose_target(uint16_t object, uint16_t object_2)
{
	uint8_t b = 0, roll = 0;
	uint16_t chase_target = 0, d = 0, state_wait = 0;
	uint8_t stack = 0, stack_10002 = 0;
	uint8_t wait = 0;
	uint16_t t1 = 0, t2 = 0;

	wait = OBJECT(object)->bear.wait;
	OBJECT(object)->bear.wait = wait - 1u;
	if (wait != 1u)
		return bear_move(object, object_2);
	roll = random_number;
	if ((roll & 8u) == 0u)
	{
		t1 = (roll & 3u) * 0xC0u;
		t2 = t1 + OBJECT_ADDRESS(0);
		b = (uint8_t)t2;
		stack = t2 >> 8;
		stack_10002 = b;
		chase_target = ((uint32_t)stack << 8) | stack_10002;
		if (mem_read8(chase_target) == 0u)
		{
			d = b;
			chase_target = vector_choose_nearest_player(object);
		}
		OBJECT(object)->bear.chase_target = chase_target;
		state_wait = 0x700u;
		d |= 0x8000u;
		stage_boss_set_state(object, state_wait, d);
		return bear_move(object, chase_target);
	}
	d = b;
	chase_target = vector_choose_nearest_player(object);
	OBJECT(object)->bear.chase_target = chase_target;
	state_wait = 0x700u;
	d |= 0x8000u;
	stage_boss_set_state(object, state_wait, d);
	return bear_move(object, chase_target);
}

/* Walks at its target, shaking the screen and dropping boulders, and swipes at a player in reach */
uint16_t bear_walk(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t facing = 0, offset = 0;
	uint16_t animation_number = 0, command = 0, d = 0, ignored16 = 0, ignored16_2 = 0, object_2 = 0, player = 0, playing_bits = 0, record = 0, speeds_by_rank = 0, state_wait = 0, target = 0;
	uint8_t stack = 0, stack_10002 = 0;
	uint8_t animation_flags = 0, vitality = 0, attributes = 0, attributes_2 = 0, animation_flags_2 = 0, attributes_3 = 0, animation_flags_3 = 0, attack_health = 0, vitality_2 = 0, vitality_3 = 0;
	uint16_t t1 = 0, chase_target = 0, t2 = 0, t3 = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) != 0u)
	{
		screen_shake_on = 1u;
		screen_shake_kind = 2u;
		command = 0x7500u;
		carry = vector_queue_sound(command);
		t1 = (uint32_t)(uint8_t)((((uint32_t)rank << 1) << 1) << 1) * random_number;
		if (t1 >= 0x3000u)
		{
			record = bear_boulder_child_1_ADDRESS;
			vitality = OBJECT(object)->vitality;
			if ((int8_t)vitality < 0x20 && (random_number & 3u) == 0u)
				record = bear_boulder_child_2_ADDRESS;
			vector_spawn_child(object, record, &ignored16, &ignored16_2, &carry);
		}
	}
	reach_x = 0x30;
	reach_y = 8;
	stage_boss_find_near_player(object, &ignored16, &playing_bits, &carry);
	offset = (uint8_t)playing_bits;
	if (carry == 0u)
	{
		chase_target = OBJECT(object)->bear.chase_target;
		target = chase_target;
		if ((frame_count & 7u) != 0u)
		{
			d = offset;
			d = vector_direction_to_offset(object, target, d);
			speeds_by_rank = bear_walk_speeds_ADDRESS;
			stage_boss_walk_by_rank(object, speeds_by_rank, d);
			return bear_move(object, target);
		}
		attributes = OBJECT(object)->attributes;
		facing = attributes & 0x40u;
		t2 = OBJECT(object)->x;
		t3 = OBJECT(target)->x;
		if ((int16_t)t3 <= (int16_t)t2)
		{
			offset = 0xDAu;
			if (facing != 0u)
			{
				d = offset;
				d = vector_direction_to_offset(object, target, d);
				speeds_by_rank = bear_walk_speeds_ADDRESS;
				stage_boss_walk_by_rank(object, speeds_by_rank, d);
				return bear_move(object, target);
			}
			attributes_2 = OBJECT(object)->attributes;
			OBJECT(object)->attributes = attributes_2 | 0x40u;
			animation_flags_2 = OBJECT(object)->animation_flags;
			OBJECT(object)->animation_flags = animation_flags_2 | 0x80u;
			d = offset;
			d = vector_direction_to_offset(object, target, d);
			speeds_by_rank = bear_walk_speeds_ADDRESS;
			stage_boss_walk_by_rank(object, speeds_by_rank, d);
			return bear_move(object, target);
		}
		offset = 0x26u;
		if (facing == 0u)
		{
			d = offset;
			d = vector_direction_to_offset(object, target, d);
			speeds_by_rank = bear_walk_speeds_ADDRESS;
			stage_boss_walk_by_rank(object, speeds_by_rank, d);
			return bear_move(object, target);
		}
		attributes_3 = OBJECT(object)->attributes;
		OBJECT(object)->attributes = attributes_3 & 0xBFu;
		animation_flags_3 = OBJECT(object)->animation_flags;
		OBJECT(object)->animation_flags = animation_flags_3 | 0x80u;
		d = offset;
		d = vector_direction_to_offset(object, target, d);
		speeds_by_rank = bear_walk_speeds_ADDRESS;
		stage_boss_walk_by_rank(object, speeds_by_rank, d);
		return bear_move(object, target);
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
			return bear_swipe(object, player);
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
		return bear_move(object, player);
	}
	object_2 = 0x7E63u;
	stack = 0x11u;
	stack_10002 = bear_attack_delays_by_players[(int8_t)player_count - 1];
	state_wait = ((uint32_t)stack << 8) | stack_10002;
	animation_number = 0x8AFAu;
	stage_boss_set_state(object, state_wait, animation_number);
	return bear_move(object, object_2);
}

/* After its wind-up, charges across the screen */
uint16_t bear_start_charge(uint16_t object, uint16_t enemy_handlers)
{
	uint8_t a = 0, d = 0;
	uint16_t animation_number = 0, box = 0, state_wait = 0;
	uint8_t stack = 0;
	uint8_t animation_flags = 0, attributes = 0, t2 = 0;
	uint16_t t1 = 0, t3 = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return bear_charge_check_hit(object, enemy_handlers);
	OBJECT(object)->flags = 0xC0u;
	state_wait = 0xA00u;
	animation_number = 0x8C00u;
	stage_boss_set_state(object, state_wait, animation_number);
	t1 = bear_charge_speeds_by_rank[((rank >> 1) & ~1u) / 2u];
	d = (uint8_t)t1;
	stack = t1 >> 8;
	attributes = OBJECT(object)->attributes;
	t2 = attributes & 0x40u;
	a = stack;
	if (t2 != 0u)
	{
		t3 = 0u - (((uint32_t)a << 8) | (d & 0xFFu));
		d = (uint8_t)t3;
		a = (uint8_t)(t3 >> 8);
	}
	OBJECT(object)->x_speed = ((uint32_t)a << 8) | (d & 0xFFu);
	box = bear_charge_box_ADDRESS;
	stage_boss_set_hit_box(object, box);
	return bear_charge_check_hit(object, enemy_handlers);
}

/* Its hits while charging: flashes, or beaten */
uint16_t bear_charge_check_hit(uint16_t object, uint16_t u)
{
	uint32_t zero = 0, negative = 0, carry = 0;
	uint16_t request = 0, y = 0;

	y = bear_beaten_vitality_ADDRESS;
	stage_boss_check_hit(object, y, &u, &zero, &negative);
	if (zero)
	{
		stage_boss_move_on_screen(object, &y, &carry);
		return y;
	}
	if (negative)
		return bear_beaten(object);
	palette_request_kind = 2u;
	request = 0x27u;
	vector_palette_request(request, &y, &u);
	OBJECT(object)->flags = 0xC4u;
	stage_boss_move_on_screen(object, &y, &carry);
	return y;
}

/* Hurts while it charges; stops into a pose, then gets up */
uint16_t bear_charge(uint16_t object)
{
	uint8_t d = 0;
	uint16_t animation_number = 0, state_wait = 0, u = 0;
	uint16_t t1 = 0, x_speed = 0;

	OBJECT(object)->damage = 8u;
	OBJECT(object)->attack = 9u;
	t1 = OBJECT(object)->x;
	u = t1;
	x_speed = OBJECT(object)->x_speed;
	d = (uint8_t)x_speed;
	if (x_speed != 0u)
		return bear_charge_check_hit(object, u);
	OBJECT(object)->damage = 0u;
	OBJECT(object)->attack = 0u;
	OBJECT(object)->flags = 0xC0u;
	state_wait = 0x1000u;
	animation_number = (d & 0xFFu) | 0x8800u;
	stage_boss_set_state(object, state_wait, animation_number);
	return bear_charge_check_hit(object, u);
}

/* Gets up unhurtable, then turns to a player */
uint16_t bear_get_up(uint16_t object, uint16_t object_2)
{
	uint16_t state_wait = 0;
	uint8_t animation_flags = 0;

	stage_boss_shield(object);
	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return bear_move(object, object_2);
	state_wait = 0x603u;
	return bear_face_player(object, state_wait);
}

/* Waits before its swipe, then swipes */
uint16_t bear_attack_wait(uint16_t object, uint16_t object_2)
{
	uint16_t animation_number = 0, state_wait = 0;
	uint8_t wait = 0;

	wait = OBJECT(object)->bear.wait;
	OBJECT(object)->bear.wait = wait - 1u;
	if (wait != 1u)
		return bear_move(object, object_2);
	state_wait = 0x800u;
	animation_number = 0x8100u;
	stage_boss_set_state(object, state_wait, animation_number);
	stage_boss_shield(object);
	return bear_swipe(object, object_2);
}

/* Its swipe's damage on the attack frames */
uint16_t bear_swipe(uint16_t object, uint16_t object_2)
{
	uint32_t carry = 0;
	uint16_t damage = 0;

	damage = 0x80Au;
	carry = stage_boss_attack_frame(object, damage);
	if (carry)
		return bear_turn_to_player(object);
	return bear_check_hit(object, object_2);
}

/* Moves until its animation ends, then turns to a player */
uint16_t bear_recover(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, y = 0;
	uint8_t animation_flags = 0;

	stage_boss_move_on_screen(object, &ignored16, &carry);
	y = 0x601u;
	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) != 0u)
		return bear_face_player(object, y);
	return y;
}

/* Knocked down: lands shaking the screen, maybe bringing boulders down */
uint16_t bear_knocked_down(uint16_t object, uint16_t states)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, object_2 = 0, x_speed = 0;
	uint8_t wait = 0, wait_2 = 0;

	stage_boss_move_on_screen(object, &states, &carry);
	if (carry == 0u)
		return states;
	wait = OBJECT(object)->bear.wait;
	if (wait == 0u)
		return bear_land(object, states);
	wait_2 = OBJECT(object)->bear.wait;
	OBJECT(object)->bear.wait = wait_2 - 1u;
	if (wait_2 != 1u)
	{
		screen_shake_on = 1u;
		screen_shake_kind = 1u;
		if ((int8_t)rank <= 0xC)
		{
			if ((int8_t)random_number >= 0)
				return bear_land(object, states);
			x_speed = 0x280u;
			object_2 = 0x400u;
			stage_boss_knock_away(object, &x_speed, &object_2);
			return x_speed;
		}
		states = bear_boulder_child_1_ADDRESS;
		vector_spawn_child(object, states, &ignored16, &ignored16_2, &carry);
		if ((int8_t)rank <= 0x14)
		{
			if ((int8_t)random_number >= 0)
				return bear_land(object, states);
			x_speed = 0x280u;
			object_2 = 0x400u;
			stage_boss_knock_away(object, &x_speed, &object_2);
			return x_speed;
		}
		states = bear_boulder_child_1_ADDRESS;
		vector_spawn_child(object, states, &ignored16, &ignored16_2, &carry);
		if ((int8_t)random_number >= 0)
			return bear_land(object, states);
		x_speed = 0x280u;
		object_2 = 0x400u;
		stage_boss_knock_away(object, &x_speed, &object_2);
		return x_speed;
	}
	screen_shake_on = 1u;
	screen_shake_kind = 1u;
	if ((int8_t)rank <= 8)
		return states;
	states = bear_boulder_child_1_ADDRESS;
	vector_spawn_child(object, states, &ignored16, &ignored16_2, &carry);
	if ((int8_t)rank > 0xF)
	{
		states = bear_boulder_child_1_ADDRESS;
		vector_spawn_child(object, states, &ignored16, &ignored16_2, &carry);
	}
	return states;
}

/* Unused: lands the bear, stopping its x speed when it is outside the area it keeps to. */
void unused_bear_land_in_area(uint16_t x)
{
	uint16_t place_x = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0xCu);
	place_x = t1;
	if ((int16_t)place_x >= 0x70 || (int16_t)place_x <= 0x140)
	{
		bear_land(x, place_x);
		return;
	}
	mem_write16(x + 0xFu, 0u);
	bear_land(x, place_x);
}

/* Its landing after a knock-down: recovers (a longer animation every fourth time), or, beaten, starts
   its change */
uint16_t bear_land(uint16_t object, uint16_t y)
{
	uint16_t animation_number = 0, state_wait = 0, y_2 = 0;
	uint8_t vitality = 0, bounces = 0, bounces_2 = 0, animation_flags = 0;

	vitality = OBJECT(object)->vitality;
	if (vitality == 0u)
	{
		y_2 = 0xDC8u;
		animation_number = 0x8600u;
		stage_boss_set_state(object, y_2, animation_number);
		OBJECT(object)->flags = 0x80u;
		OBJECT(object)->zoom_x = 0x40u;
		OBJECT(object)->zoom_y = 0x40u;
		OBJECT(object)->damage = 0u;
		OBJECT(object)->attack = 0u;
		return y_2;
	}
	bounces = OBJECT(object)->bear.bounces;
	OBJECT(object)->bear.bounces = bounces + 1u;
	bounces_2 = OBJECT(object)->bear.bounces;
	if (bounces_2 > 3u)
	{
		OBJECT(object)->bear.bounces = 0u;
		state_wait = 0xF00u;
		animation_number = 0x8400u;
		stage_boss_set_state(object, state_wait, animation_number);
		return state_wait;
	}
	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return y;
	state_wait = 0x1200u;
	animation_number = 0x8800u;
	stage_boss_set_state(object, state_wait, animation_number);
	return state_wait;
}

/* Every fourth knock-down's longer animation, then it recovers */
uint16_t bear_long_get_up(uint16_t object, uint16_t states)
{
	uint16_t animation_number = 0, state_wait = 0;
	uint8_t animation_flags = 0, animation_flags_2 = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) != 0u)
	{
		animation_flags_2 = OBJECT(object)->animation_flags;
		if ((animation_flags_2 & 1u) != 0u)
		{
			state_wait = 0x1200u;
			animation_number = 0x8800u;
			stage_boss_set_state(object, state_wait, animation_number);
			return state_wait;
		}
	}
	return states;
}

/* Beaten, swells and changes into kind 81 (the fat goon's set) */
uint16_t bear_change(uint16_t object, uint16_t states)
{
	uint32_t carry = 0;
	uint8_t wait = 0, zoom = 0;
	uint16_t d = 0, ignored16 = 0;
	uint8_t t1 = 0, t2 = 0, zoom_x = 0;

	t1 = io_read8(0x2Fu);
	io_write8(0x2Fu, t1 - 1u);
	if (t1 == 1u)
	{
		OBJECT(object)->bear.phase = 0xEu;
		OBJECT(object)->bear.wait = 0x78u;
		OBJECT(object)->kind = 0x81u;
		OBJECT(object)->animation = 0xBBu;
		bear_changed(object);
		return states;
	}
	t2 = io_read8(0x2Fu);
	wait = t2;
	if (wait == 0x11u)
	{
		states = bear_change_child_ADDRESS;
		vector_spawn_child(object, states, &ignored16, &d, &carry);
		wait = (uint8_t)(d >> 8);
	}
	if (wait <= 0x28u)
	{
		OBJECT(object)->flags = 0x90u;
		zoom_x = OBJECT(object)->zoom_x;
		zoom = zoom_x + 1u;
		OBJECT(object)->zoom_x = zoom;
		OBJECT(object)->zoom_y = zoom;
	}
	return states;
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
uint16_t bear_move(uint16_t object, uint16_t object_2)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;

	stage_boss_move_on_screen(object, &ignored16, &carry);
	OBJECT(object)->bear.charged = 0u;
	return bear_think(object, object_2);
}

/* Charges now and then (more often with more players), unless a lone player is down */
uint16_t bear_think(uint16_t object, uint16_t object_2)
{
	uint32_t carry = 0;
	uint16_t animation_number = 0, bear_x = 0, command = 0, state_wait = 0;
	uint8_t stack = 0;
	uint8_t charge_timer = 0;
	uint16_t t1 = 0;

	OBJECT(object)->flags |= 0xC0u;
	stack = ((((uint32_t)player_count << 1) << 1) << 1) << 1;
	charge_timer = OBJECT(object)->bear.charge_timer;
	if (charge_timer < (uint8_t)(0x96u - stack))
		return bear_check_hit(object, object_2);
	OBJECT(object)->bear.charge_timer = 0u;
	if (player_count == 1u)
	{
		carry = stage_boss_any_player_down();
		if (carry)
			return bear_check_hit(object, object_2);
	}
	command = 0x7400u;
	carry = vector_queue_sound(command);
	t1 = OBJECT(object)->x;
	bear_x = t1;
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
	return bear_check_hit(object, object_2);
}

/* Its hits: flinches with a flash, is knocked down or beaten */
uint16_t bear_check_hit(uint16_t object, uint16_t object_2)
{
	uint32_t zero = 0, negative = 0, carry = 0;
	uint8_t flinch_animation = 0;
	uint16_t animation_number = 0, ignored16 = 0, request = 0, y = 0;
	uint8_t charge_timer = 0, charge_timer_2 = 0, attributes = 0, attributes_2 = 0, vitality = 0, flinch_health = 0, vitality_2 = 0;

	stage_boss_move_on_screen(object, &ignored16, &carry);
	charge_timer = OBJECT(object)->bear.charge_timer;
	if (charge_timer != 0xFFu)
	{
		charge_timer_2 = OBJECT(object)->bear.charge_timer;
		OBJECT(object)->bear.charge_timer = charge_timer_2 + 1u;
	}
	y = bear_beaten_vitality_ADDRESS;
	stage_boss_check_hit(object, y, &object_2, &zero, &negative);
	if (zero)
		return y;
	attributes = OBJECT(object)->attributes;
	attributes_2 = OBJECT(object_2)->attributes;
	if ((attributes ^ attributes_2) == 0u)
	{
		y = 0xB00u;
		flinch_animation = 0x83u;
	}
	else
	{
		y = 0xB00u;
		flinch_animation = 0x82u;
	}
	animation_number = (uint32_t)flinch_animation << 8;
	stage_boss_set_state(object, y, animation_number);
	palette_request_kind = 2u;
	request = 0x27u;
	vector_palette_request(request, &y, &object_2);
	vitality = OBJECT(object)->vitality;
	if (vitality == 0u)
		return bear_beaten(object);
	flinch_health = OBJECT(object)->bear.flinch_health;
	vitality_2 = OBJECT(object)->vitality;
	if ((uint8_t)(flinch_health - vitality_2) > 0xCu)
		return bear_knocked_away(object);
	return y;
}

/* Stops the sounds, plays boss_defeated and knocks it away */
uint16_t bear_beaten(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;

	command = 0u;
	carry = vector_queue_sound(command);
	command = 0x9800u;
	carry = vector_queue_sound_unless_attract(command);
	return bear_knocked_away(object);
}

/* Knocked away, shaking the screen */
uint16_t bear_knocked_away(uint16_t object)
{
	uint16_t animation_number = 0, object_2 = 0, state_wait = 0, x_speed = 0;
	uint8_t vitality = 0;

	vitality = OBJECT(object)->vitality;
	OBJECT(object)->bear.flinch_health = vitality;
	state_wait = 0xC02u;
	animation_number = 0x8500u;
	stage_boss_set_state(object, state_wait, animation_number);
	screen_shake_on = 1u;
	screen_shake_kind = 1u;
	object_2 = 0x500u;
	x_speed = 0x380u;
	stage_boss_knock_away(object, &x_speed, &object_2);
	return x_speed;
}
