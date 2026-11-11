/**
 *    Name:        objects/stage_3_boss.c
 *    Description: stage 3's two bosses (type 3E, kinds C4 and C3)
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Runs one of stage 3's two bosses by its state */
void stage_3_boss(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, states = 0;
	uint8_t phase = 0;

	OBJECT(object)->damage = 0u;
	OBJECT(object)->attack = 0u;
	phase = OBJECT(object)->stage_3_boss.phase;
	states = stage_3_boss_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)phase << 1))
	{
	case 0:
		leftover_y = states;
		stage_3_boss_start(object, 0u);
		return;
	case 2:
		leftover_y = states;
		stage_3_boss_enter(object);
		return;
	case 4:
		leftover_y = states;
		stage_3_boss_arrive(object, 0u);
		return;
	case 6:
		leftover_y = states;
		stage_3_boss_wait(object, 0u);
		return;
	case 8:
		stage_3_boss_walk(object, 0u);
		return;
	case 10:
		leftover_y = states;
		stage_3_boss_leap(object, 0u);
		return;
	case 12:
		stage_3_boss_attack(object, 0u);
		return;
	case 14:
	case 28:
		stage_3_boss_strike(object, 0u);
		return;
	case 16:
		stage_3_boss_follow_up(object, 0u);
		return;
	case 18:
		stage_3_boss_reach_partner(object);
		return;
	case 20:
		stage_3_boss_follow_partner(object);
		return;
	case 22:
		leftover_y = states;
		stage_3_boss_join(object, 0u);
		return;
	case 24:
		leftover_y = states;
		stage_3_boss_jump_on(object);
		return;
	case 26:
		stage_3_boss_together(object, 0u);
		return;
	case 30:
		leftover_y = states;
		stage_3_boss_partner_ready(object, &ignored16, &carry);
		return;
	case 32:
		stage_3_boss_pause(object, 0u);
		return;
	case 34:
		leftover_y = states;
		stage_3_boss_flinch(object, 0u);
		return;
	case 36:
		leftover_y = states;
		stage_3_boss_knocked(object, 0u);
		return;
	case 38:
		leftover_y = states;
		stage_3_boss_down(object);
		return;
	case 40:
		leftover_y = states;
		stage_3_boss_defeated(object);
		return;
	case 42:
		stage_3_boss_push(object, 0u);
		return;
	case -16:
	case -14:
	case -12:
		leftover_y = states;
		hurry_up_enter(object);
		return;
	case -10:
	case -8:
		leftover_y = states;
		hurry_up_next_player(object);
		return;
	case -6:
		leftover_y = states;
		hurry_up_go_to_player(object);
		return;
	case -4:
		leftover_y = states;
		hurry_up_hit(object);
		return;
	case -2:
		leftover_y = states;
		hurry_up_vanish(object);
		return;
	}
}

/* Sets a boss up; the first puts in the second and links them */
uint16_t stage_3_boss_start(uint16_t object, uint16_t object_2)
{
	uint32_t carry = 0;
	uint8_t kind = 0, vitality = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0;
	uint8_t second = 0, second_2 = 0, phase = 0;

	second = OBJECT(object)->stage_3_boss.second;
	if (second != 0u)
	{
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
		return object_2;
	}
	leftover_y = stage_3_boss_child_ADDRESS;
	vector_spawn_child(object, &ignored16, &object_2, &ignored16_2, &carry);
	OBJECT(object)->stage_3_boss.partner = object_2;
	OBJECT(object_2)->parent = (OBJECT(object_2)->parent & 0xFF00u) | ((object >> 8u) & 0xFFu);
	OBJECT(object_2)->enemy_class = (uint8_t)object;
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
	return object_2;
}

/* When the stage lets it, comes in from the right and tells the story's object */
void stage_3_boss_enter(uint16_t object)
{
	uint16_t animation_number = 0, command = 0, marker = 0, state_wait = 0, x_speed = 0;
	uint8_t second = 0;
	uint16_t stored_marker = 0;

	if (stage_scrolls_on != 0u)
		return;
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
	stored_marker = io_read16(stage_kept_object);
	marker = stored_marker;
	OBJECT(marker)->behaviour = (OBJECT(marker)->behaviour & 0xFFu) | 0x100u;
	command = 0x6000u;
	vector_queue_sound(command);
	leftover_y = marker;
}

/* Arrives, with its cry, and waits */
uint16_t stage_3_boss_arrive(uint16_t object, uint16_t child)
{
	uint32_t carry = 0;
	uint16_t animation_number = 0, child_object = 0, command = 0, state_wait = 0, y = 0;
	uint8_t wait = 0, wait_2 = 0, second = 0;
	uint16_t stored_marker = 0;

	wait = OBJECT(object)->stage_3_boss.wait;
	OBJECT(object)->stage_3_boss.wait = wait - 1u;
	if (wait != 1u)
	{
		wait_2 = OBJECT(object)->stage_3_boss.wait;
		if (wait_2 != 0x14u)
			return child;
		stored_marker = io_read16(stage_kept_object);
		y = stored_marker;
		mem_write8(y + 0x2Au, 0u);
		command = 0x6000u;
		vector_queue_sound(command);
		leftover_y = y;
		return child;
	}
	leftover_y = 0x3C0u;
	state_wait = 0x3C0u;
	animation_number = 0x8900u;
	stage_boss_set_state(object, state_wait, animation_number);
	second = OBJECT(object)->stage_3_boss.second;
	if (second != 0u)
		return child;
	command = 0x3F35u;
	vector_queue_sound(command);
	leftover_y = stage_3_boss_arrive_child_ADDRESS;
	child_object = stage_3_boss_arrive_child_ADDRESS;
	spawn_list_2_child(object, child_object, &child, &carry);
	return child;
}

/* Waits, then walks */
uint16_t stage_3_boss_wait(uint16_t object, uint16_t u)
{
	uint8_t wait = 0;

	wait = OBJECT(object)->stage_3_boss.wait;
	OBJECT(object)->stage_3_boss.wait = wait - 1u;
	if (wait == 1u)
		return stage_3_boss_start_walk(object);
	return u;
}

/* Takes the carrying state (13) and picks a target */
uint16_t stage_3_boss_start_together(uint16_t object)
{
	uint16_t animation_number = 0, state_wait = 0;

	state_wait = 0xD00u;
	animation_number = 0x8700u;
	stage_boss_set_state(object, state_wait, animation_number);
	return stage_3_boss_pick_target(object);
}

/* Starts walking and picks a target */
uint16_t stage_3_boss_start_walk(uint16_t object)
{
	uint16_t animation_number = 0, state_wait = 0;
	uint8_t attributes = 0;

	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = attributes & 0xCFu;
	state_wait = 0x400u;
	animation_number = 0x8100u;
	stage_boss_set_state(object, state_wait, animation_number);
	return stage_3_boss_pick_target(object);
}

/* Its hit box, then its target: the nearest player for the first, a random one for the second */
uint16_t stage_3_boss_pick_target(uint16_t object)
{
	uint8_t direction_2 = 0;
	uint16_t boxes = 0, chase_target = 0, direction = 0;
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
	return stage_3_boss_taunt(object, chase_target);
}

/* Walks carrying its partner, and attacks a player in reach at random */
uint16_t stage_3_boss_together(uint16_t object, uint16_t other_object)
{
	uint16_t boss = 0, bytes_left = 0, distance = 0, partner_place = 0, target = 0, y = 0;
	uint16_t stack = 0;
	uint8_t second = 0;
	uint16_t partner = 0, chase_target = 0, own_x = 0, target_x = 0, own_y = 0, target_y = 0;

	second = OBJECT(object)->stage_3_boss.second;
	if (second != 0u)
		return stage_3_boss_update(object, other_object);
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
	own_x = OBJECT(boss)->x;
	target_x = OBJECT(target)->x;
	distance = own_x - target_x;
	if ((int16_t)(distance >> 15 ? 0u - distance : distance) < 0x4A)
	{
		own_y = OBJECT(boss)->y;
		target_y = OBJECT(target)->y;
		distance = own_y - target_y;
		if ((int16_t)(distance >> 15 ? 0u - distance : distance) < 0x12 && (((uint16_t)((uint32_t)random_number << 8) >> 8) & 0x30u) != 0u)
			return stage_3_boss_attack_or_wait(boss, target);
	}
	return stage_3_boss_move(boss, target);
}

/* Walks at its target, stopping after a while, and attacks it in reach */
uint16_t stage_3_boss_walk(uint16_t object, uint16_t u)
{
	uint16_t animation_number = 0, distance = 0, state_wait = 0, target = 0;
	uint8_t walk_time = 0, second = 0;
	uint16_t chase_target = 0, own_x = 0, target_x = 0, own_y = 0, target_y = 0;

	walk_time = OBJECT(object)->stage_3_boss.walk_time;
	OBJECT(object)->stage_3_boss.walk_time = walk_time - 1u;
	if (walk_time == 1u)
	{
		state_wait = 0x1500u;
		animation_number = 0x8300u;
		stage_boss_set_state(object, state_wait, animation_number);
		return stage_3_boss_push(object, u);
	}
	chase_target = OBJECT(object)->stage_3_boss.chase_target;
	target = chase_target;
	own_x = OBJECT(object)->x;
	target_x = OBJECT(target)->x;
	distance = own_x - target_x;
	if ((int16_t)(distance >> 15 ? 0u - distance : distance) < 0x3A)
	{
		own_y = OBJECT(object)->y;
		target_y = OBJECT(target)->y;
		distance = own_y - target_y;
		if ((int16_t)(distance >> 15 ? 0u - distance : distance) < 0xA)
		{
			second = OBJECT(object)->stage_3_boss.second;
			if ((((uint16_t)((uint32_t)(uint8_t)(((uint16_t)((uint32_t)random_number << 8) >> 8) + second) << 8) >> 8) & 0x30u) != 0u)
				return stage_3_boss_attack_or_wait(object, target);
		}
	}
	return stage_3_boss_move(object, target);
}

/* Faces its target and attacks now or after a pause */
uint16_t stage_3_boss_attack_or_wait(uint16_t object, uint16_t target)
{
	uint8_t attributes = 0;
	uint16_t boxes = 0;
	uint8_t attributes_2 = 0, second = 0;
	uint16_t own_x = 0, target_x = 0, z = 0;

	boxes = stage_3_boss_attack_box_ADDRESS;
	stage_3_boss_set_hit_box(object, boxes);
	attributes_2 = OBJECT(object)->attributes;
	attributes = attributes_2 | 0x40u;
	own_x = OBJECT(object)->x;
	target_x = OBJECT(target)->x;
	if ((int16_t)own_x < (int16_t)target_x)
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
				return stage_3_boss_update(object, target);
			}
		}
		OBJECT(object)->stage_3_boss.phase = 6u;
		OBJECT(object)->stage_3_boss.wait = 1u;
		return stage_3_boss_update(object, target);
	}
	second = OBJECT(object)->stage_3_boss.second;
	if (stage_3_boss_slow_attack_chances_by_players[(int8_t)player_count - 1] < ((random_number ^ second) & 0xFu))
	{
		OBJECT(object)->stage_3_boss.phase = 6u;
		OBJECT(object)->stage_3_boss.wait = 1u;
		return stage_3_boss_update(object, target);
	}
	OBJECT(object)->stage_3_boss.phase = 6u;
	OBJECT(object)->stage_3_boss.wait = 0xEu;
	return stage_3_boss_update(object, target);
}

/* Turns toward its target and moves on */
uint16_t stage_3_boss_move(uint16_t object, uint16_t target)
{
	uint8_t direction = 0, facing = 0, turn_step = 0;
	uint16_t direction_2 = 0;
	uint8_t attributes = 0, attributes_2 = 0, animation_flags = 0, attributes_3 = 0, animation_flags_2 = 0, direction_3 = 0;
	uint16_t own_x = 0, target_x = 0, x_speed = 0, x_speed_2 = 0, doubled_x_speed = 0;

	attributes = OBJECT(object)->attributes;
	facing = attributes & 0x40u;
	own_x = OBJECT(object)->x;
	target_x = OBJECT(target)->x;
	if ((int16_t)target_x <= (int16_t)own_x)
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
	doubled_x_speed = x_speed + x_speed_2;
	OBJECT(object)->x_speed = doubled_x_speed;
	stage_boss_move_on_screen(object);
	return stage_3_boss_taunt(object, target);
}

/* Picks its attack: a strike, a leap (the second, at a player down) or the carried one's */
uint16_t stage_3_boss_attack(uint16_t object, uint16_t other_object)
{
	uint16_t animation_number = 0, box = 0, state_wait = 0, u = 0;
	uint8_t wait = 0, together = 0, target_state = 0, second = 0, z_low = 0;
	uint16_t partner = 0, chase_target = 0;

	wait = OBJECT(object)->stage_3_boss.wait;
	OBJECT(object)->stage_3_boss.wait = wait - 1u;
	if (wait != 1u)
		return stage_3_boss_update(object, other_object);
	stage_boss_shield(object);
	together = OBJECT(object)->stage_3_boss.together;
	if (together != 0u)
	{
		state_wait = 0xE00u;
		animation_number = 0x8800u;
		stage_boss_set_state(object, state_wait, animation_number);
		partner = OBJECT(object)->stage_3_boss.partner;
		other_object = partner;
		OBJECT(other_object)->x_speed = 0;
		OBJECT(other_object)->y_speed = 0;
		OBJECT(other_object)->z_speed = 0;
		return stage_3_boss_update(object, other_object);
	}
	chase_target = OBJECT(object)->stage_3_boss.chase_target;
	other_object = chase_target;
	target_state = OBJECT(other_object)->state;
	if (target_state != 1u)
	{
		u = stage_boss_face_nearest_player(object);
		state_wait = 0x700u;
		animation_number = 0x8300u;
		stage_boss_set_state(object, state_wait, animation_number);
		return stage_3_boss_strike(object, u);
	}
	second = OBJECT(object)->stage_3_boss.second;
	if (second != 1u)
	{
		box = stage_3_boss_strike_box_ADDRESS;
		stage_boss_set_hit_box(object, box);
		leftover_y = 0x800u;
		state_wait = 0x800u;
		animation_number = 0x8400u;
		stage_boss_set_state(object, state_wait, animation_number);
		return other_object;
	}
	state_wait = 0x500u;
	animation_number = 0x8200u;
	stage_boss_set_state(object, state_wait, animation_number);
	stage_boss_set_airborne(object);
	OBJECT(object)->flags = 0x80u;
	u = 0x580u;
	leftover_y = 0x400u;
	z_low = (uint8_t)OBJECT(object)->z;
	OBJECT(object)->z = (OBJECT(object)->z & 0xFF00u) | (z_low + 1u & 0xFFu);
	u = stage_boss_knock_away(object, u);
	stage_boss_move_on_screen(object);
	return u;
}

/* A strike that pushes without damage */
uint16_t stage_3_boss_push(uint16_t object, uint16_t u)
{
	uint16_t damage = 0;

	damage = 0x11u;
	return stage_3_boss_strike_frames(object, damage, u);
}

/* Its follow-up strike (damage 4) */
uint16_t stage_3_boss_follow_up(uint16_t object, uint16_t u)
{
	uint16_t damage = 0;

	damage = 0x401u;
	return stage_3_boss_strike_frames(object, damage, u);
}

/* Its strike (damage 8) */
uint16_t stage_3_boss_strike(uint16_t object, uint16_t u)
{
	uint16_t damage = 0;

	damage = 0x801u;
	return stage_3_boss_strike_frames(object, damage, u);
}

/* A strike's damage on its attack frames, then walking or a follow-up */
uint16_t stage_3_boss_strike_frames(uint16_t object, uint16_t damage, uint16_t u)
{
	uint32_t carry = 0;
	uint16_t animation_number = 0, box = 0, state_wait = 0;
	uint8_t together = 0, second = 0, phase = 0;

	carry = stage_boss_attack_frame(object, damage);
	if (carry == 0u)
		return stage_3_boss_update(object, u);
	OBJECT(object)->damage = 0u;
	OBJECT(object)->attack = 0u;
	together = OBJECT(object)->stage_3_boss.together;
	if (together != 0u)
		return stage_3_boss_start_together(object);
	second = OBJECT(object)->stage_3_boss.second;
	if (second != 1u)
	{
		phase = OBJECT(object)->stage_3_boss.phase;
		if (phase != 8u && random_number <= stage_3_boss_follow_up_chances_by_players[(int8_t)player_count])
		{
			box = stage_3_boss_strike_box_ADDRESS;
			stage_boss_set_hit_box(object, box);
			leftover_y = 0x800u;
			state_wait = 0x800u;
			animation_number = 0x8400u;
			stage_boss_set_state(object, state_wait, animation_number);
			return u;
		}
	}
	return stage_3_boss_start_walk(object);
}

/* Waits, then walks (or carries) */
uint16_t stage_3_boss_pause(uint16_t object, uint16_t other_object)
{
	uint8_t wait = 0, together = 0;

	wait = OBJECT(object)->stage_3_boss.wait;
	OBJECT(object)->stage_3_boss.wait = wait - 1u;
	if (wait != 1u)
		return stage_3_boss_update(object, other_object);
	together = OBJECT(object)->stage_3_boss.together;
	if (together != 0u)
		return stage_3_boss_start_together(object);
	return stage_3_boss_start_walk(object);
}

/* In the air on its leap; walks on landing */
uint16_t stage_3_boss_leap(uint16_t object, uint16_t u)
{
	uint32_t carry = 0;

	carry = stage_boss_move_on_screen(object);
	if (carry)
		return stage_3_boss_start_walk(object);
	return u;
}

/* Flinches until its animation ends */
uint16_t stage_3_boss_flinch(uint16_t object, uint16_t u)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) != 0u)
		return stage_3_boss_start_walk(object);
	return u;
}

/* Knocked away; walks on landing, or lies beaten */
uint16_t stage_3_boss_knocked(uint16_t object, uint16_t u)
{
	uint32_t carry = 0;
	uint16_t animation_number = 0, command = 0, partner_boss = 0, state_wait = 0;
	uint8_t vitality = 0, partner_phase = 0;
	uint16_t partner = 0;

	carry = stage_boss_move_on_screen(object);
	if (carry == 0u)
		return u;
	vitality = OBJECT(object)->vitality;
	if (vitality != 0u)
		return stage_3_boss_start_walk(object);
	partner = OBJECT(object)->stage_3_boss.partner;
	partner_boss = partner;
	partner_phase = OBJECT(partner_boss)->stage_3_boss.phase;
	if ((int8_t)partner_phase >= 0x13)
	{
		command = 0u;
		vector_queue_sound(command);
		command = 0x9800u;
		vector_queue_sound_unless_attract(command);
	}
	leftover_y = 0x133Cu;
	state_wait = 0x133Cu;
	animation_number = 0x8600u;
	stage_boss_set_state(object, state_wait, animation_number);
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->damage = 0u;
	OBJECT(object)->attack = 0u;
	return u;
}

/* Lies beaten, then blinks out */
void stage_3_boss_down(uint16_t object)
{
	uint8_t wait = 0;

	wait = OBJECT(object)->stage_3_boss.wait;
	OBJECT(object)->stage_3_boss.wait = wait - 1u;
	if (wait == 1u)
	{
		OBJECT(object)->stage_3_boss.phase = 0x14u;
		OBJECT(object)->stage_3_boss.wait = 0x3Cu;
		leftover_y = 0x143Cu;
		return;
	}
}

/* Blinks out; the last of the two marks the bosses beaten and moves the stage on */
void stage_3_boss_defeated(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0, other_object = 0;
	uint16_t partner = 0, stored_marker = 0;

	carry = stage_boss_blink_out(object);
	if (carry == 0u)
		return;
	OBJECT(object)->flags = 0u;
	partner = OBJECT(object)->stage_3_boss.partner;
	other_object = partner;
	if (OBJECT(other_object)->flags != 0u)
	{
		leftover_y = other_object;
		return;
	}
	command = 0x6000u;
	vector_queue_sound(command);
	stored_marker = io_read16(stage_kept_object);
	other_object = stored_marker;
	OBJECT(other_object)->behaviour = (OBJECT(other_object)->behaviour & 0xFFu) | 0x100u;
	boss_beaten = 1u;
	step_phase++;
	step_subphase = 1u;
	step_countdown = 0u;
	leftover_y = other_object;
}

/* Taunts when a player is down */
uint16_t stage_3_boss_taunt(uint16_t object, uint16_t other_object)
{
	uint32_t carry = 0;
	uint16_t animation_number = 0, state_wait = 0;
	uint8_t together = 0;

	carry = stage_boss_any_player_down();
	if (carry == 0u)
		return stage_3_boss_update(object, other_object);
	together = OBJECT(object)->stage_3_boss.together;
	if (together != 0u)
	{
		state_wait = 0x1028u;
		animation_number = 0x8B00u;
		stage_boss_set_state(object, state_wait, animation_number);
		return stage_3_boss_update(object, other_object);
	}
	state_wait = 0x1028u;
	animation_number = 0x8000u;
	stage_boss_set_state(object, state_wait, animation_number);
	return stage_3_boss_update(object, other_object);
}

/* Each frame: its floor, joining its partner again, and its hits */
uint16_t stage_3_boss_update(uint16_t boss, uint16_t other_object)
{
	uint32_t zero = 0, negative = 0, carry = 0;
	uint8_t d = 0, ignored_low_byte = 0;
	uint16_t animation_number = 0, health_limits = 0, hurt_animation = 0, object = 0, partner = 0, state_wait = 0, u = 0;
	uint16_t stack = 0;
	uint8_t join_wait = 0, together = 0, second = 0, apart_time = 0, apart_time_2 = 0, apart_time_3 = 0, still_together = 0, vitality = 0, hit = 0;
	uint16_t partner_2 = 0, partner_z = 0, partner_3 = 0, boss_x = 0, boss_y = 0, partner_address = 0;

	stage_boss_follow_floor(boss);
	ignored_low_byte = (uint8_t)d;
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
				stage_3_boss_partner_ready(boss, &other_object, &carry);
				ignored_low_byte = (uint8_t)d;
				if (carry)
				{
					partner_2 = OBJECT(boss)->stage_3_boss.partner;
					other_object = partner_2;
					partner_z = OBJECT(other_object)->z;
					ignored_low_byte = (uint8_t)partner_z;
					if (partner_z == 0u)
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
							ignored_low_byte = 0x80u;
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
	apart_time_2 = OBJECT(boss)->stage_3_boss.apart_time;
	if (apart_time_2 != 0xFFu)
	{
		apart_time_3 = OBJECT(boss)->stage_3_boss.apart_time;
		OBJECT(boss)->stage_3_boss.apart_time = apart_time_3 + 1u;
	}
	leftover_y = stage_3_boss_beaten_vitality_ADDRESS;
	health_limits = stage_3_boss_beaten_vitality_ADDRESS;
	hurt_animation = ignored_low_byte;
	stage_boss_check_hit(boss, health_limits, &other_object, &zero, &negative);
	if (zero)
		return other_object;
	OBJECT(boss)->stage_3_boss.join_wait = 0x10u;
	still_together = OBJECT(boss)->stage_3_boss.together;
	if (still_together != 0u)
	{
		boss_x = OBJECT(boss)->x;
		boss_y = OBJECT(boss)->y;
		stack = boss;
		partner_address = OBJECT(boss)->stage_3_boss.partner;
		partner = partner_address;
		OBJECT(partner)->x = boss_x;
		OBJECT(partner)->y = boss_y;
		OBJECT(partner)->z = 0x24u;
		OBJECT(partner)->flags = 0x80u;
		state_wait = 0x1200u;
		hurt_animation |= 0x8500u;
		stage_boss_set_state(partner, state_wait, hurt_animation);
		object = 0x700u;
		leftover_y = 0x200u;
		stage_boss_knock_away(partner, object);
		stage_boss_move_on_screen(partner);
		OBJECT(partner)->stage_3_boss.together = 0u;
		boss = stack;
		OBJECT(boss)->stage_3_boss.together = 0u;
		state_wait = 0x1200u;
		animation_number = (hurt_animation & 0xFFu) | 0x8500u;
		stage_boss_set_state(boss, state_wait, animation_number);
		u = 0x500u;
		leftover_y = 0x380u;
		u = stage_boss_knock_away(boss, u);
		OBJECT(boss)->z = (OBJECT(boss)->z & 0xFF00u) | 0x1u;
		stage_boss_move_on_screen(boss);
		return u;
	}
	vitality = OBJECT(boss)->vitality;
	if (vitality == 0u)
	{
		state_wait = 0x1200u;
		animation_number = (hurt_animation & 0xFFu) | 0x8500u;
		stage_boss_set_state(boss, state_wait, animation_number);
		u = 0x500u;
		leftover_y = 0x380u;
		u = stage_boss_knock_away(boss, u);
		OBJECT(boss)->z = (OBJECT(boss)->z & 0xFF00u) | 0x1u;
		stage_boss_move_on_screen(boss);
		return u;
	}
	hit = OBJECT(boss)->hit;
	if (hit >= 0x12u)
	{
		state_wait = 0x1200u;
		animation_number = (hurt_animation & 0xFFu) | 0x8500u;
		stage_boss_set_state(boss, state_wait, animation_number);
		u = 0x500u;
		leftover_y = 0x380u;
		u = stage_boss_knock_away(boss, u);
		OBJECT(boss)->z = (OBJECT(boss)->z & 0xFF00u) | 0x1u;
		stage_boss_move_on_screen(boss);
		return u;
	}
	leftover_y = 0x1100u;
	state_wait = 0x1100u;
	hurt_animation |= 0x8500u;
	stage_boss_set_state(boss, state_wait, hurt_animation);
	return other_object;
}

/* Walks to its partner */
uint16_t stage_3_boss_follow_partner(uint16_t object)
{
	return stage_3_boss_head_to_partner(object);
}

/* Walks to its partner; reaching it, the partner jumps onto it */
uint16_t stage_3_boss_reach_partner(uint16_t object)
{
	uint16_t animation_number = 0, low_x = 0, low_y = 0, partner = 0, partner_2 = 0, state_wait = 0;
	uint16_t partner_3 = 0, own_x = 0, partner_x = 0, partner_x_2 = 0, own_y = 0, partner_y = 0, partner_y_2 = 0, partner_4 = 0;

	stage_3_boss_head_to_partner(object);
	partner_3 = OBJECT(object)->stage_3_boss.partner;
	partner = partner_3;
	own_x = OBJECT(object)->x;
	low_x = own_x - 0xAu;
	partner_x = OBJECT(partner)->x;
	if ((int16_t)partner_x <= (int16_t)low_x)
		return partner;
	partner_x_2 = OBJECT(partner)->x;
	if ((int16_t)(low_x + 0x14u) <= (int16_t)partner_x_2)
		return partner;
	own_y = OBJECT(object)->y;
	low_y = own_y - 0xAu;
	partner_y = OBJECT(partner)->y;
	if ((int16_t)partner_y <= (int16_t)low_y)
		return partner;
	low_y += 0x14u;
	partner_y_2 = OBJECT(partner)->y;
	if ((int16_t)low_y < (int16_t)partner_y_2)
		return partner;
	state_wait = 0xB1Cu;
	animation_number = (low_y & 0xFFu) | 0x8000u;
	stage_boss_set_state(object, state_wait, animation_number);
	partner_4 = OBJECT(object)->stage_3_boss.partner;
	partner_2 = partner_4;
	OBJECT(partner_2)->z_speed = 0x700;
	OBJECT(partner_2)->z = (OBJECT(partner_2)->z & 0xFF00u) | 0x7u;
	OBJECT(partner_2)->z_fraction = 0u;
	leftover_y = 0xC00u;
	animation_number = 0x8200u;
	state_wait = 0xC00u;
	stage_boss_set_state(partner_2, state_wait, animation_number);
	return partner;
}

/* Turns and moves toward its partner */
uint16_t stage_3_boss_head_to_partner(uint16_t object)
{
	uint8_t attributes = 0;
	uint16_t direction = 0, partner = 0;
	uint8_t attributes_2 = 0;
	uint16_t partner_2 = 0, x_speed = 0;

	partner_2 = OBJECT(object)->stage_3_boss.partner;
	partner = partner_2;
	direction = vector_direction_to(object, partner);
	stage_3_boss_walk_speed(object, direction);
	attributes_2 = OBJECT(object)->attributes;
	attributes = attributes_2 & 0xBFu;
	x_speed = OBJECT(object)->x_speed;
	leftover_y = x_speed;
	if ((int16_t)x_speed < 0)
		attributes |= 0x40u;
	OBJECT(object)->attributes = attributes;
	return partner;
}

/* In the air jumping onto its partner */
void stage_3_boss_jump_on(uint16_t object)
{
	stage_boss_move_on_screen(object);
}

/* After its wait the two are one: the partner carried, a shared hit box */
uint16_t stage_3_boss_join(uint16_t object, uint16_t u)
{
	uint16_t boxes = 0, partner = 0;
	uint8_t wait = 0;
	uint16_t partner_2 = 0;

	wait = OBJECT(object)->stage_3_boss.wait;
	OBJECT(object)->stage_3_boss.wait = wait - 1u;
	if (wait != 1u)
		return u;
	partner_2 = OBJECT(object)->stage_3_boss.partner;
	partner = partner_2;
	OBJECT(partner)->stage_3_boss.phase = 0xDu;
	OBJECT(partner)->stage_3_boss.wait = 0u;
	OBJECT(partner)->animation = 0x87u;
	OBJECT(partner)->x_speed = 0;
	OBJECT(partner)->y_speed = 0;
	OBJECT(partner)->z_speed = 0;
	OBJECT(partner)->flags = 0xC0u;
	OBJECT(object)->stage_3_boss.together = 1u;
	OBJECT(partner)->stage_3_boss.together = 1u;
	boxes = stage_3_bosses_joined_box_ADDRESS;
	stage_boss_set_hit_box(object, boxes);
	return stage_3_boss_start_together(object);
}

/* Whether its partner is still a boss standing (carry set) */
void stage_3_boss_partner_ready(uint16_t object, uint16_t *p_partner, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t partner = 0;
	uint8_t type = 0, phase = 0;
	uint16_t partner_2 = 0;

	partner_2 = OBJECT(object)->stage_3_boss.partner;
	partner = partner_2;
	type = OBJECT(partner)->type;
	if (type != 0x3Eu || OBJECT(partner)->flags == 0u)
		carry = 0u;
	else
	{
		phase = OBJECT(partner)->stage_3_boss.phase;
		if ((int8_t)phase >= 0x13)
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
