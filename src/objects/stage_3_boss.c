/**
 *    Name:        objects/stage_3_boss.c
 *    Description: stage 3's two bosses (type 3E, kinds C4 and C3)
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Runs one of stage 3's two bosses by its state */
uint16_t stage_3_boss(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, states = 0, y = 0;
	uint8_t phase = 0;

	OBJECT(object)->damage = 0u;
	OBJECT(object)->attack = 0u;
	phase = OBJECT(object)->stage_3_boss.phase;
	states = stage_3_boss_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)phase << 1))
	{
	case 0:
		stage_3_boss_start(object, &states, &ignored16);
		return states;
	case 2:
		return stage_3_boss_enter(object, states);
	case 4:
		stage_3_boss_arrive(object, &states, &ignored16);
		return states;
	case 6:
		stage_3_boss_wait(object, &states, &ignored16);
		return states;
	case 8:
		stage_3_boss_walk(object, &y, &ignored16);
		return y;
	case 10:
		stage_3_boss_leap(object, &states, &ignored16);
		return states;
	case 12:
		stage_3_boss_attack(object, &y, &ignored16);
		return y;
	case 14:
	case 28:
		stage_3_boss_strike(object, &y, &ignored16);
		return y;
	case 16:
		stage_3_boss_follow_up(object, &y, &ignored16);
		return y;
	case 18:
		stage_3_boss_reach_partner(object, &y, &ignored16);
		return y;
	case 20:
		stage_3_boss_follow_partner(object, &y, &ignored16);
		return y;
	case 22:
		stage_3_boss_join(object, &states, &ignored16);
		return states;
	case 24:
		return stage_3_boss_jump_on(object, states);
	case 26:
		stage_3_boss_together(object, &y, &ignored16);
		return y;
	case 30:
		stage_3_boss_partner_ready(object, &ignored16, &carry);
		return states;
	case 32:
		stage_3_boss_pause(object, &y, &ignored16);
		return y;
	case 34:
		stage_3_boss_flinch(object, &states, &ignored16);
		return states;
	case 36:
		stage_3_boss_knocked(object, &states, &ignored16);
		return states;
	case 38:
		return stage_3_boss_down(object, states);
	case 40:
		return stage_3_boss_defeated(object, states);
	case 42:
		stage_3_boss_push(object, &y, &ignored16);
		return y;
	case -16:
	case -14:
	case -12:
		hurry_up_enter(object);
		return states;
	case -10:
	case -8:
		hurry_up_next_player(object);
		return states;
	case -6:
		hurry_up_go_to_player(object);
		return states;
	case -4:
		hurry_up_hit(object);
		return states;
	case -2:
		hurry_up_vanish(object);
		return states;
	}
	unreachable();
}

/* Sets a boss up; the first puts in the second and links them */
void stage_3_boss_start(uint16_t object, uint16_t *p_child_record, uint16_t *p_object_2)
{
	uint16_t child_record = (uint16_t)*p_child_record;
	uint16_t object_2 = (uint16_t)*p_object_2;
	uint32_t carry = 0;
	uint8_t kind = 0, vitality = 0;
	uint16_t ignored16 = 0;
	uint8_t second = 0, second_2 = 0, phase = 0;

	second = OBJECT(object)->stage_3_boss.second;
	if (second == 0u)
	{
		child_record = stage_3_boss_child_ADDRESS;
		vector_spawn_child(object, child_record, &object_2, &ignored16, &carry);
		OBJECT(object)->stage_3_boss.partner = object_2;
		OBJECT(object_2)->parent = (OBJECT(object_2)->parent & 0xFF00u) | ((object >> 8u) & 0xFFu);
		OBJECT(object_2)->enemy_class = (uint8_t)object;
	}
	vitality = 0x80u;
	kind = 0xC4u;
	second_2 = OBJECT(object)->stage_3_boss.second;
	if (second_2 != 0u)
	{
		vitality = 0xC0u;
		kind = 0xC3u;
	}
	OBJECT(object)->kind = kind;
	OBJECT(object)->vitality = vitality;
	OBJECT(object)->attributes = 0x40u;
	phase = OBJECT(object)->stage_3_boss.phase;
	OBJECT(object)->stage_3_boss.phase = phase + 1u;
	OBJECT(object)->entrance_pending = 1u;
	*p_child_record = child_record;
	*p_object_2 = object_2;
}

/* When the stage lets it, comes in from the right and tells the story's object */
uint16_t stage_3_boss_enter(uint16_t object, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t animation_number = 0, command = 0, marker = 0, state_wait = 0, x_speed = 0;
	uint8_t second = 0;
	uint16_t t1 = 0;

	if (stage_scrolls_on != 0u)
		return y;
	OBJECT(object)->entrance_pending = 0u;
	boss_arrived = 1u;
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->attributes = 0x60u;
	OBJECT(object)->x = 0x1A0u;
	OBJECT(object)->y = 0xE8u;
	state_wait = 0x2E0u;
	animation_number = 0x81E8u;
	stage_boss_set_state(object, state_wait, animation_number);
	x_speed = 0xFF40u;
	second = OBJECT(object)->stage_3_boss.second;
	if (second != 0u)
		x_speed = 0xFEE0u;
	OBJECT(object)->x_speed = x_speed;
	OBJECT(object)->y_speed = -0x20;
	t1 = io_read16(0x1852u);
	marker = t1;
	OBJECT(marker)->behaviour = (OBJECT(marker)->behaviour & 0xFFu) | 0x100u;
	command = 0x6000u;
	carry = vector_queue_sound(command);
	return marker;
}

/* Arrives, with its cry, and waits */
void stage_3_boss_arrive(uint16_t object, uint16_t *p_y, uint16_t *p_child)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t child = (uint16_t)*p_child;
	uint32_t carry = 0;
	uint16_t animation_number = 0, command = 0;
	uint8_t wait = 0, second = 0, wait_2 = 0;
	uint16_t t1 = 0;

	wait = OBJECT(object)->stage_3_boss.wait;
	OBJECT(object)->stage_3_boss.wait = wait - 1u;
	if (wait == 1u)
	{
		y = 0x3C0u;
		animation_number = 0x8900u;
		stage_boss_set_state(object, y, animation_number);
		second = OBJECT(object)->stage_3_boss.second;
		if (second == 0u)
		{
			command = 0x3F35u;
			carry = vector_queue_sound(command);
			y = stage_3_boss_arrive_child_ADDRESS;
			spawn_list_2_child(object, y, &child, &carry);
		}
	}
	else
	{
		wait_2 = OBJECT(object)->stage_3_boss.wait;
		if (wait_2 == 0x14u)
		{
			t1 = io_read16(0x1852u);
			y = t1;
			mem_write8(y + 0x2Au, 0u);
			command = 0x6000u;
			carry = vector_queue_sound(command);
		}
	}
	*p_y = y;
	*p_child = child;
}

/* Waits, then walks */
void stage_3_boss_wait(uint16_t object, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint8_t wait = 0;

	wait = OBJECT(object)->stage_3_boss.wait;
	OBJECT(object)->stage_3_boss.wait = wait - 1u;
	if (wait == 1u)
		stage_3_boss_start_walk(object, &y, &u);
	*p_y = y;
	*p_u = u;
}

/* Takes the carrying state (13) and picks a target */
void stage_3_boss_start_together(uint16_t object, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t animation_number = 0, state_wait = 0, u = 0, y = 0;

	state_wait = 0xD00u;
	animation_number = 0x8700u;
	stage_boss_set_state(object, state_wait, animation_number);
	*p_y = y;
	*p_u = u;
	stage_3_boss_pick_target(object, p_y, p_u);
}

/* Starts walking and picks a target */
void stage_3_boss_start_walk(uint16_t object, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t animation_number = 0, state_wait = 0, u = 0, y = 0;
	uint8_t attributes = 0;

	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = attributes & 0xCFu;
	state_wait = 0x400u;
	animation_number = 0x8100u;
	stage_boss_set_state(object, state_wait, animation_number);
	*p_y = y;
	*p_u = u;
	stage_3_boss_pick_target(object, p_y, p_u);
}

/* Its hit box, then its target: the nearest player for the first, a random one for the second */
void stage_3_boss_pick_target(uint16_t object, uint16_t *p_y, uint16_t *p_u)
{
	uint8_t direction_2 = 0;
	uint16_t boxes = 0, chase_target = 0, direction = 0, y = 0;
	uint8_t second = 0;

	boxes = stage_3_boss_box_ADDRESS;
	stage_3_boss_set_hit_box(object, boxes);
	OBJECT(object)->flags = (OBJECT(object)->flags | 0xC0u) & ~4u;
	second = OBJECT(object)->stage_3_boss.second;
	if (second != 0u)
		chase_target = stage_boss_pick_random_player();
	else
		chase_target = vector_choose_nearest_player(object);
	OBJECT(object)->stage_3_boss.chase_target = chase_target;
	direction = vector_direction_to(object, chase_target);
	direction_2 = (uint8_t)(direction >> 8);
	OBJECT(object)->stage_3_boss.direction = direction_2;
	*p_y = y;
	*p_u = chase_target;
	stage_3_boss_taunt(object, p_y, p_u);
}

/* Walks carrying its partner, and attacks a player in reach at random */
void stage_3_boss_together(uint16_t object, uint16_t *p_y, uint16_t *p_target)
{
	uint16_t target = (uint16_t)*p_target;
	uint16_t boss = 0, bytes_left = 0, distance = 0, partner_place = 0, y = 0;
	uint16_t stack = 0;
	uint8_t second = 0;
	uint16_t partner = 0, chase_target = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	second = OBJECT(object)->stage_3_boss.second;
	if (second != 0u)
		stage_3_boss_update(object, &y, &target);
	else
	{
		stack = object;
		y = object + 0xCu;
		partner = OBJECT(object)->stage_3_boss.partner;
		partner_place = partner + 0xCu;
		bytes_left = 0xFu;
		while (bytes_left != 0u)
		{
			mem_write8(partner_place, mem_read8(y));
			y++;
			partner_place++;
			bytes_left--;
		}
		boss = stack;
		chase_target = OBJECT(boss)->stage_3_boss.chase_target;
		target = chase_target;
		t1 = OBJECT(boss)->x;
		t2 = OBJECT(target)->x;
		distance = t1 - t2;
		if ((int16_t)(distance >> 15 ? 0u - distance : distance) >= 0x4A)
			stage_3_boss_move(boss, &y, &target);
		else
		{
			t3 = OBJECT(boss)->y;
			t4 = OBJECT(target)->y;
			distance = t3 - t4;
			if ((int16_t)(distance >> 15 ? 0u - distance : distance) >= 0x12 || (((uint16_t)((uint32_t)random_number << 8) >> 8) & 0x30u) == 0u)
				stage_3_boss_move(boss, &y, &target);
			else
				stage_3_boss_attack_or_wait(boss, &y, &target);
		}
	}
	*p_y = y;
	*p_target = target;
}

/* Walks at its target, stopping after a while, and attacks it in reach */
void stage_3_boss_walk(uint16_t object, uint16_t *p_y, uint16_t *p_target)
{
	uint16_t target = (uint16_t)*p_target;
	uint16_t animation_number = 0, distance = 0, state_wait = 0, y = 0;
	uint8_t walk_time = 0, second = 0;
	uint16_t chase_target = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	walk_time = OBJECT(object)->stage_3_boss.walk_time;
	OBJECT(object)->stage_3_boss.walk_time = walk_time - 1u;
	if (walk_time == 1u)
	{
		state_wait = 0x1500u;
		animation_number = 0x8300u;
		stage_boss_set_state(object, state_wait, animation_number);
		*p_y = y;
		*p_target = target;
		stage_3_boss_push(object, p_y, p_target);
		return;
	}
	chase_target = OBJECT(object)->stage_3_boss.chase_target;
	target = chase_target;
	t1 = OBJECT(object)->x;
	t2 = OBJECT(target)->x;
	distance = t1 - t2;
	if ((int16_t)(distance >> 15 ? 0u - distance : distance) < 0x3A)
	{
		t3 = OBJECT(object)->y;
		t4 = OBJECT(target)->y;
		distance = t3 - t4;
		if ((int16_t)(distance >> 15 ? 0u - distance : distance) < 0xA)
		{
			second = OBJECT(object)->stage_3_boss.second;
			if ((((uint16_t)((uint32_t)(uint8_t)(((uint16_t)((uint32_t)random_number << 8) >> 8) + second) << 8) >> 8) & 0x30u) != 0u)
			{
				*p_y = y;
				*p_target = target;
				stage_3_boss_attack_or_wait(object, p_y, p_target);
				return;
			}
		}
	}
	*p_y = y;
	*p_target = target;
	stage_3_boss_move(object, p_y, p_target);
}

/* Faces its target and attacks now or after a pause */
void stage_3_boss_attack_or_wait(uint16_t object, uint16_t *p_y, uint16_t *p_target)
{
	uint16_t target = (uint16_t)*p_target;
	uint8_t attributes = 0;
	uint16_t boxes = 0, y = 0;
	uint8_t attributes_2 = 0, second = 0;
	uint16_t t1 = 0, t2 = 0, z = 0;

	boxes = stage_3_boss_attack_box_ADDRESS;
	stage_3_boss_set_hit_box(object, boxes);
	attributes_2 = OBJECT(object)->attributes;
	attributes = attributes_2 | 0x40u;
	t1 = OBJECT(object)->x;
	t2 = OBJECT(target)->x;
	if ((int16_t)t1 < (int16_t)t2)
		attributes &= 0xBFu;
	OBJECT(object)->attributes = attributes;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	if (player_count != 1u)
	{
		z = OBJECT(target)->z;
		if (z == 0u)
		{
			second = OBJECT(object)->stage_3_boss.second;
			if (((random_number ^ second) & 0xFu) <= stage_3_boss_slow_attack_chances_by_players[(int8_t)player_count - 1])
			{
				OBJECT(object)->stage_3_boss.phase = 6u;
				OBJECT(object)->stage_3_boss.wait = 0xEu;
				*p_y = y;
				*p_target = target;
				stage_3_boss_update(object, p_y, p_target);
				return;
			}
		}
		OBJECT(object)->stage_3_boss.phase = 6u;
		OBJECT(object)->stage_3_boss.wait = 1u;
		*p_y = y;
		*p_target = target;
		stage_3_boss_update(object, p_y, p_target);
		return;
	}
	second = OBJECT(object)->stage_3_boss.second;
	if (stage_3_boss_slow_attack_chances_by_players[(int8_t)player_count - 1] < ((random_number ^ second) & 0xFu))
	{
		OBJECT(object)->stage_3_boss.phase = 6u;
		OBJECT(object)->stage_3_boss.wait = 1u;
		*p_y = y;
		*p_target = target;
		stage_3_boss_update(object, p_y, p_target);
		return;
	}
	OBJECT(object)->stage_3_boss.phase = 6u;
	OBJECT(object)->stage_3_boss.wait = 0xEu;
	*p_y = y;
	*p_target = target;
	stage_3_boss_update(object, p_y, p_target);
}

/* Turns toward its target and moves on */
void stage_3_boss_move(uint16_t object, uint16_t *p_y, uint16_t *p_target)
{
	uint16_t target = (uint16_t)*p_target;
	uint32_t carry = 0;
	uint8_t direction = 0, facing = 0, turn_step = 0;
	uint16_t direction_2 = 0, ignored16 = 0, y = 0;
	uint8_t attributes = 0, attributes_2 = 0, animation_flags = 0, attributes_3 = 0, animation_flags_2 = 0, direction_3 = 0;
	uint16_t t1 = 0, t2 = 0, x_speed = 0, x_speed_2 = 0, t3 = 0;

	attributes = OBJECT(object)->attributes;
	facing = attributes & 0x40u;
	t1 = OBJECT(object)->x;
	t2 = OBJECT(target)->x;
	if ((int16_t)t2 <= (int16_t)t1)
	{
		if (facing == 0u)
		{
			attributes_2 = OBJECT(object)->attributes;
			OBJECT(object)->attributes = attributes_2 | 0x40u;
			animation_flags = OBJECT(object)->animation_flags;
			OBJECT(object)->animation_flags = animation_flags | 0x80u;
		}
	}
	else if (facing != 0u)
	{
		attributes_3 = OBJECT(object)->attributes;
		OBJECT(object)->attributes = attributes_3 & 0xBFu;
		animation_flags_2 = OBJECT(object)->animation_flags;
		OBJECT(object)->animation_flags = animation_flags_2 | 0x80u;
	}
	direction_3 = OBJECT(object)->stage_3_boss.direction;
	turning_direction = direction_3;
	turn_step = 5u;
	stage_boss_turn_toward(object, target, turn_step);
	direction = turning_direction;
	OBJECT(object)->stage_3_boss.direction = direction;
	direction_2 = 5u | ((uint32_t)direction << 8);
	stage_3_boss_walk_speed(object, direction_2);
	x_speed = OBJECT(object)->x_speed;
	x_speed_2 = OBJECT(object)->x_speed;
	t3 = x_speed + x_speed_2;
	OBJECT(object)->x_speed = t3;
	stage_boss_move_on_screen(object, &ignored16, &carry);
	*p_y = y;
	*p_target = target;
	stage_3_boss_taunt(object, p_y, p_target);
}

/* Picks its attack: a strike, a leap (the second, at a player down) or the carried one's */
void stage_3_boss_attack(uint16_t object, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t animation_number = 0, box = 0, state_wait = 0, y = 0;
	uint8_t wait = 0, together = 0, t1 = 0, second = 0, t2 = 0;
	uint16_t chase_target = 0, partner = 0;

	wait = OBJECT(object)->stage_3_boss.wait;
	OBJECT(object)->stage_3_boss.wait = wait - 1u;
	if (wait != 1u)
		stage_3_boss_update(object, &y, &u);
	else
	{
		stage_boss_shield(object);
		together = OBJECT(object)->stage_3_boss.together;
		if (together == 0u)
		{
			chase_target = OBJECT(object)->stage_3_boss.chase_target;
			u = chase_target;
			t1 = mem_read8(u + 2u);
			if (t1 == 1u)
			{
				second = OBJECT(object)->stage_3_boss.second;
				if (second != 1u)
				{
					box = stage_3_boss_strike_box_ADDRESS;
					stage_boss_set_hit_box(object, box);
					y = 0x800u;
					animation_number = 0x8400u;
					stage_boss_set_state(object, y, animation_number);
				}
				else
				{
					state_wait = 0x500u;
					animation_number = 0x8200u;
					stage_boss_set_state(object, state_wait, animation_number);
					stage_boss_set_airborne(object);
					OBJECT(object)->flags = 0x80u;
					u = 0x580u;
					y = 0x400u;
					t2 = (uint8_t)OBJECT(object)->z;
					OBJECT(object)->z = (OBJECT(object)->z & 0xFF00u) | (t2 + 1u & 0xFFu);
					stage_boss_knock_away(object, &y, &u);
					stage_boss_move_on_screen(object, &y, &carry);
				}
			}
			else
			{
				u = stage_boss_face_nearest_player(object);
				state_wait = 0x700u;
				animation_number = 0x8300u;
				stage_boss_set_state(object, state_wait, animation_number);
				stage_3_boss_strike(object, &y, &u);
			}
		}
		else
		{
			state_wait = 0xE00u;
			animation_number = 0x8800u;
			stage_boss_set_state(object, state_wait, animation_number);
			partner = OBJECT(object)->stage_3_boss.partner;
			u = partner;
			mem_write16(u + 0xFu, 0u);
			mem_write16(u + 0x14u, 0u);
			mem_write16(u + 0x19u, 0u);
			stage_3_boss_update(object, &y, &u);
		}
	}
	*p_y = y;
	*p_u = u;
}

/* A strike that pushes without damage */
void stage_3_boss_push(uint16_t object, uint16_t *p_damage, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t damage = 0;

	damage = 0x11u;
	*p_damage = damage;
	*p_u = u;
	stage_3_boss_strike_frames(object, p_damage, p_u);
}

/* Its follow-up strike (damage 4) */
void stage_3_boss_follow_up(uint16_t object, uint16_t *p_damage, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t damage = 0;

	damage = 0x401u;
	*p_damage = damage;
	*p_u = u;
	stage_3_boss_strike_frames(object, p_damage, p_u);
}

/* Its strike (damage 8) */
void stage_3_boss_strike(uint16_t object, uint16_t *p_damage, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t damage = 0;

	damage = 0x801u;
	*p_damage = damage;
	*p_u = u;
	stage_3_boss_strike_frames(object, p_damage, p_u);
}

/* A strike's damage on its attack frames, then walking or a follow-up */
void stage_3_boss_strike_frames(uint16_t object, uint16_t *p_damage, uint16_t *p_u)
{
	uint16_t damage = (uint16_t)*p_damage;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t animation_number = 0, box = 0, y = 0;
	uint8_t together = 0, second = 0, phase = 0;

	carry = stage_boss_attack_frame(object, damage);
	if (carry == 0u)
		stage_3_boss_update(object, &y, &u);
	else
	{
		OBJECT(object)->damage = 0u;
		OBJECT(object)->attack = 0u;
		together = OBJECT(object)->stage_3_boss.together;
		if (together != 0u)
			stage_3_boss_start_together(object, &y, &u);
		else
		{
			second = OBJECT(object)->stage_3_boss.second;
			if (second == 1u)
				stage_3_boss_start_walk(object, &y, &u);
			else
			{
				phase = OBJECT(object)->stage_3_boss.phase;
				if (phase == 8u || stage_3_boss_follow_up_chances_by_players[(int8_t)player_count] < random_number)
					stage_3_boss_start_walk(object, &y, &u);
				else
				{
					box = stage_3_boss_strike_box_ADDRESS;
					stage_boss_set_hit_box(object, box);
					y = 0x800u;
					animation_number = 0x8400u;
					stage_boss_set_state(object, y, animation_number);
				}
			}
		}
	}
	*p_damage = y;
	*p_u = u;
}

/* Waits, then walks (or carries) */
void stage_3_boss_pause(uint16_t object, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t y = 0;
	uint8_t wait = 0, together = 0;

	wait = OBJECT(object)->stage_3_boss.wait;
	OBJECT(object)->stage_3_boss.wait = wait - 1u;
	if (wait != 1u)
		stage_3_boss_update(object, &y, &u);
	else
	{
		together = OBJECT(object)->stage_3_boss.together;
		if (together != 0u)
			stage_3_boss_start_together(object, &y, &u);
		else
			stage_3_boss_start_walk(object, &y, &u);
	}
	*p_y = y;
	*p_u = u;
}

/* In the air on its leap; walks on landing */
void stage_3_boss_leap(uint16_t object, uint16_t *p_landing_speed, uint16_t *p_u)
{
	uint16_t landing_speed = (uint16_t)*p_landing_speed;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;

	stage_boss_move_on_screen(object, &landing_speed, &carry);
	if (carry)
		stage_3_boss_start_walk(object, &landing_speed, &u);
	*p_landing_speed = landing_speed;
	*p_u = u;
}

/* Flinches until its animation ends */
void stage_3_boss_flinch(uint16_t object, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) != 0u)
		stage_3_boss_start_walk(object, &y, &u);
	*p_y = y;
	*p_u = u;
}

/* Knocked away; walks on landing, or lies beaten */
void stage_3_boss_knocked(uint16_t object, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t animation_number = 0, command = 0;
	uint8_t vitality = 0, t1 = 0;
	uint16_t partner = 0;

	stage_boss_move_on_screen(object, &y, &carry);
	if (carry)
	{
		vitality = OBJECT(object)->vitality;
		if (vitality != 0u)
			stage_3_boss_start_walk(object, &y, &u);
		else
		{
			partner = OBJECT(object)->stage_3_boss.partner;
			t1 = mem_read8(partner + 0x2Eu);
			if ((int8_t)t1 >= 0x13)
			{
				command = 0u;
				carry = vector_queue_sound(command);
				command = 0x9800u;
				carry = vector_queue_sound_unless_attract(command);
			}
			y = 0x133Cu;
			animation_number = 0x8600u;
			stage_boss_set_state(object, y, animation_number);
			OBJECT(object)->flags = 0x80u;
			OBJECT(object)->damage = 0u;
			OBJECT(object)->attack = 0u;
		}
	}
	*p_y = y;
	*p_u = u;
}

/* Lies beaten, then blinks out */
uint16_t stage_3_boss_down(uint16_t object, uint16_t y)
{
	uint16_t state_wait = 0;
	uint8_t wait = 0;

	wait = OBJECT(object)->stage_3_boss.wait;
	OBJECT(object)->stage_3_boss.wait = wait - 1u;
	if (wait == 1u)
	{
		state_wait = 0x143Cu;
		OBJECT(object)->stage_3_boss.phase = 0x14u;
		OBJECT(object)->stage_3_boss.wait = 0x3Cu;
		return state_wait;
	}
	return y;
}

/* Blinks out; the last of the two marks the bosses beaten and moves the stage on */
uint16_t stage_3_boss_defeated(uint16_t object, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t command = 0, y_2 = 0;
	uint16_t partner = 0, t1 = 0;

	carry = stage_boss_blink_out(object);
	if (carry == 0u)
		return y;
	OBJECT(object)->flags = 0u;
	partner = OBJECT(object)->stage_3_boss.partner;
	y_2 = partner;
	if (mem_read8(y_2) != 0u)
		return y_2;
	command = 0x6000u;
	carry = vector_queue_sound(command);
	t1 = io_read16(0x1852u);
	y_2 = t1;
	mem_write8(y_2 + 0x2Au, 1u);
	boss_beaten = 1u;
	step_phase++;
	step_subphase = 1u;
	step_countdown = 0u;
	return y_2;
}

/* Taunts when a player is down */
void stage_3_boss_taunt(uint16_t object, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t animation_number = 0, state_wait = 0, y = 0;
	uint8_t together = 0;

	carry = stage_boss_any_player_down();
	if (carry == 0u)
		stage_3_boss_update(object, &y, &u);
	else
	{
		together = OBJECT(object)->stage_3_boss.together;
		if (together != 0u)
		{
			state_wait = 0x1028u;
			animation_number = 0x8B00u;
			stage_boss_set_state(object, state_wait, animation_number);
			stage_3_boss_update(object, &y, &u);
		}
		else
		{
			state_wait = 0x1028u;
			animation_number = 0x8000u;
			stage_boss_set_state(object, state_wait, animation_number);
			stage_3_boss_update(object, &y, &u);
		}
	}
	*p_y = y;
	*p_u = u;
}

/* Each frame: its floor, joining its partner again, and its hits */
void stage_3_boss_update(uint16_t boss, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t zero = 0, negative = 0, carry = 0;
	uint8_t b = 0, d = 0;
	uint16_t animation_number = 0, d_2 = 0, object = 0, partner = 0, state_wait = 0, y_2 = 0;
	uint16_t stack = 0;
	uint8_t join_wait = 0, together = 0, second = 0, apart_time = 0, retarget_time = 0, retarget_time_2 = 0, t2 = 0, vitality = 0, hit = 0;
	uint16_t partner_2 = 0, t1 = 0, partner_3 = 0, t3 = 0, t4 = 0, t5 = 0;

	stage_boss_follow_floor(boss, &y, &carry);
	b = (uint8_t)d;
	join_wait = OBJECT(boss)->stage_3_boss.join_wait;
	OBJECT(boss)->stage_3_boss.join_wait = join_wait - 1u;
	if (join_wait == 1u)
	{
		together = OBJECT(boss)->stage_3_boss.together;
		if (together == 0u)
		{
			second = OBJECT(boss)->stage_3_boss.second;
			if (second == 0u)
			{
				stage_3_boss_partner_ready(boss, &u, &carry);
				b = (uint8_t)d;
				if (carry)
				{
					partner_2 = OBJECT(boss)->stage_3_boss.partner;
					u = partner_2;
					t1 = mem_read16(u + 0x16u);
					b = (uint8_t)t1;
					if (t1 == 0u)
					{
						apart_time = OBJECT(boss)->stage_3_boss.apart_time;
						if ((uint8_t)(0x64u - rank - rank) <= apart_time)
						{
							OBJECT(boss)->stage_3_boss.apart_time = 0u;
							OBJECT(boss)->flags = 0x80u;
							state_wait = 0x900u;
							animation_number = 0x8100u;
							stage_boss_set_state(boss, state_wait, animation_number);
							stack = boss;
							partner_3 = OBJECT(boss)->stage_3_boss.partner;
							partner = partner_3;
							b = 0x80u;
							OBJECT(partner)->flags = 0x80u;
							OBJECT(partner)->z_speed = 0;
							state_wait = 0xA00u;
							animation_number = 0x8100u;
							stage_boss_set_state(partner, state_wait, animation_number);
							boss = stack;
						}
					}
				}
			}
		}
	}
	retarget_time = OBJECT(boss)->retarget_time;
	if (retarget_time != 0xFFu)
	{
		retarget_time_2 = OBJECT(boss)->retarget_time;
		OBJECT(boss)->retarget_time = retarget_time_2 + 1u;
	}
	y_2 = stage_3_boss_beaten_vitality_ADDRESS;
	d_2 = b;
	stage_boss_check_hit(boss, y_2, &u, &zero, &negative);
	if (zero == 0u)
	{
		OBJECT(boss)->parent = (OBJECT(boss)->parent & 0xFFu) | 0x1000u;
		t2 = OBJECT(boss)->unk_43;
		if (t2 != 0u)
		{
			t3 = OBJECT(boss)->x;
			t4 = OBJECT(boss)->y;
			stack = boss;
			t5 = (((uint32_t)(OBJECT(boss)->parent & 0xFFu) << 8u) | (uint8_t)OBJECT(boss)->enemy_class);
			partner = t5;
			OBJECT(partner)->x = t3;
			OBJECT(partner)->y = t4;
			OBJECT(partner)->z = 0x24u;
			OBJECT(partner)->flags = 0x80u;
			state_wait = 0x1200u;
			d_2 |= 0x8500u;
			stage_boss_set_state(partner, state_wait, d_2);
			object = 0x700u;
			y_2 = 0x200u;
			stage_boss_knock_away(partner, &y_2, &object);
			stage_boss_move_on_screen(partner, &y_2, &carry);
			OBJECT(partner)->unk_43 = 0u;
			boss = stack;
			OBJECT(boss)->stage_3_boss.together = 0u;
			state_wait = 0x1200u;
			animation_number = (d_2 & 0xFFu) | 0x8500u;
			stage_boss_set_state(boss, state_wait, animation_number);
			u = 0x500u;
			y_2 = 0x380u;
			stage_boss_knock_away(boss, &y_2, &u);
			OBJECT(boss)->z = (OBJECT(boss)->z & 0xFF00u) | 0x1u;
			stage_boss_move_on_screen(boss, &y_2, &carry);
		}
		else
		{
			vitality = OBJECT(boss)->vitality;
			if (vitality == 0u)
			{
				state_wait = 0x1200u;
				animation_number = (d_2 & 0xFFu) | 0x8500u;
				stage_boss_set_state(boss, state_wait, animation_number);
				u = 0x500u;
				y_2 = 0x380u;
				stage_boss_knock_away(boss, &y_2, &u);
				OBJECT(boss)->z = (OBJECT(boss)->z & 0xFF00u) | 0x1u;
				stage_boss_move_on_screen(boss, &y_2, &carry);
			}
			else
			{
				hit = OBJECT(boss)->hit;
				if (hit >= 0x12u)
				{
					state_wait = 0x1200u;
					animation_number = (d_2 & 0xFFu) | 0x8500u;
					stage_boss_set_state(boss, state_wait, animation_number);
					u = 0x500u;
					y_2 = 0x380u;
					stage_boss_knock_away(boss, &y_2, &u);
					OBJECT(boss)->z = (OBJECT(boss)->z & 0xFF00u) | 0x1u;
					stage_boss_move_on_screen(boss, &y_2, &carry);
				}
				else
				{
					y_2 = 0x1100u;
					d_2 |= 0x8500u;
					stage_boss_set_state(boss, y_2, d_2);
				}
			}
		}
	}
	*p_y = y_2;
	*p_u = u;
}

/* Walks to its partner */
void stage_3_boss_follow_partner(uint16_t object, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;

	*p_y = y;
	*p_u = u;
	stage_3_boss_head_to_partner(object, p_y, p_u);
}

/* Walks to its partner; reaching it, the partner jumps onto it */
void stage_3_boss_reach_partner(uint16_t object, uint16_t *p_y, uint16_t *p_partner)
{
	uint16_t animation_number = 0, ignored16 = 0, low_x = 0, low_y = 0, partner = 0, partner_2 = 0, state_wait = 0, y = 0;
	uint16_t partner_3 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, partner_4 = 0;

	stage_3_boss_head_to_partner(object, &y, &ignored16);
	partner_3 = OBJECT(object)->stage_3_boss.partner;
	partner = partner_3;
	t1 = OBJECT(object)->x;
	low_x = t1 - 0xAu;
	t2 = OBJECT(partner)->x;
	if ((int16_t)low_x < (int16_t)t2)
	{
		t3 = OBJECT(partner)->x;
		if ((int16_t)t3 < (int16_t)(low_x + 0x14u))
		{
			t4 = OBJECT(object)->y;
			low_y = t4 - 0xAu;
			t5 = OBJECT(partner)->y;
			if ((int16_t)low_y < (int16_t)t5)
			{
				low_y += 0x14u;
				t6 = OBJECT(partner)->y;
				if ((int16_t)t6 <= (int16_t)low_y)
				{
					state_wait = 0xB1Cu;
					animation_number = (low_y & 0xFFu) | 0x8000u;
					stage_boss_set_state(object, state_wait, animation_number);
					partner_4 = OBJECT(object)->stage_3_boss.partner;
					partner_2 = partner_4;
					OBJECT(partner_2)->z_speed = 0x700;
					OBJECT(partner_2)->z = (OBJECT(partner_2)->z & 0xFF00u) | 0x7u;
					OBJECT(partner_2)->z_fraction = 0u;
					y = 0xC00u;
					animation_number = 0x8200u;
					stage_boss_set_state(partner_2, y, animation_number);
				}
			}
		}
	}
	*p_y = y;
	*p_partner = partner;
}

/* Turns and moves toward its partner */
void stage_3_boss_head_to_partner(uint16_t object, uint16_t *p_speed_x, uint16_t *p_partner)
{
	uint8_t attributes = 0;
	uint16_t direction = 0, partner = 0, speed_x = 0;
	uint8_t attributes_2 = 0;
	uint16_t partner_2 = 0, x_speed = 0;

	partner_2 = OBJECT(object)->stage_3_boss.partner;
	partner = partner_2;
	direction = vector_direction_to(object, partner);
	stage_3_boss_walk_speed(object, direction);
	attributes_2 = OBJECT(object)->attributes;
	attributes = attributes_2 & 0xBFu;
	x_speed = OBJECT(object)->x_speed;
	speed_x = x_speed;
	if ((int16_t)x_speed < 0)
		attributes |= 0x40u;
	OBJECT(object)->attributes = attributes;
	*p_speed_x = speed_x;
	*p_partner = partner;
}

/* In the air jumping onto its partner */
uint16_t stage_3_boss_jump_on(uint16_t object, uint16_t landing_speed)
{
	uint32_t carry = 0;

	stage_boss_move_on_screen(object, &landing_speed, &carry);
	return landing_speed;
}

/* After its wait the two are one: the partner carried, a shared hit box */
void stage_3_boss_join(uint16_t object, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t boxes = 0, partner = 0, u_2 = 0, y_2 = 0;
	uint8_t wait = 0;
	uint16_t partner_2 = 0;

	wait = OBJECT(object)->stage_3_boss.wait;
	OBJECT(object)->stage_3_boss.wait = wait - 1u;
	if (wait != 1u)
		return;
	partner_2 = OBJECT(object)->stage_3_boss.partner;
	partner = partner_2;
	OBJECT(partner)->target_dy = 0xD00u;
	OBJECT(partner)->animation = 0x87u;
	OBJECT(partner)->x_speed = 0;
	OBJECT(partner)->y_speed = 0;
	OBJECT(partner)->z_speed = 0;
	OBJECT(partner)->flags = 0xC0u;
	OBJECT(object)->stage_3_boss.together = 1u;
	OBJECT(partner)->unk_43 = 1u;
	boxes = stage_3_bosses_joined_box_ADDRESS;
	stage_boss_set_hit_box(object, boxes);
	*p_y = y_2;
	*p_u = u_2;
	stage_3_boss_start_together(object, p_y, p_u);
}

/* Whether its partner is still a boss standing (carry set) */
void stage_3_boss_partner_ready(uint16_t object, uint16_t *p_partner, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t partner = 0;
	uint8_t type = 0, target_dy = 0;
	uint16_t partner_2 = 0;

	partner_2 = OBJECT(object)->stage_3_boss.partner;
	partner = partner_2;
	type = OBJECT(partner)->type;
	if (type != 0x3Eu || OBJECT(partner)->flags == 0u)
		carry = 0u;
	else
	{
		target_dy = (uint8_t)(OBJECT(partner)->target_dy >> 8u);
		if ((int8_t)target_dy >= 0x13)
			carry = 0u;
		else
			carry = 1u;
	}
	*p_partner = partner;
	*p_carry = carry;
}

/* Its hit box from the record in Y, the next ones for the first and the carrying one */
void stage_3_boss_set_hit_box(uint16_t object, uint16_t boxes)
{
	uint8_t second = 0, together = 0;

	second = OBJECT(object)->stage_3_boss.second;
	if (second == 0u)
	{
		boxes += 4u;
		together = OBJECT(object)->stage_3_boss.together;
		if (together != 0u)
			boxes += 4u;
	}
	stage_boss_set_hit_box(object, boxes);
}

/* Its speed by the rank, one table for each of the two */
void stage_3_boss_walk_speed(uint16_t object, uint16_t direction)
{
	uint16_t speeds_by_rank = 0;
	uint8_t second = 0;

	second = OBJECT(object)->stage_3_boss.second;
	if (second == 0u)
	{
		speeds_by_rank = stage_3_boss_walk_speeds_1_ADDRESS;
		stage_boss_walk_by_rank(object, speeds_by_rank, direction);
		return;
	}
	speeds_by_rank = stage_3_boss_walk_speeds_2_ADDRESS;
	stage_boss_walk_by_rank(object, speeds_by_rank, direction);
}
