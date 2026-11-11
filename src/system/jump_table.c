/**
 *    Name:        system/jump_table.c
 *    Description: the fixed program's entry points for the banks (an LBRA each, 078593-0786CB) and the routines the decompiler folded into them
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* When the object was hit this frame by an attack of kind 11 to 15 and is not reacting already: counts
   the hit for the player who hit an enemy, gives the hitter's player its points, and sends it to its
   state FF, or FE when its vitality is gone, with its action cleared and its flags 80 (shown, not hit
   again). */
uint16_t object_take_special_hit(uint16_t object, uint16_t hitter)
{
	uint8_t state = 0;
	uint8_t stack = 0;
	uint8_t hit = 0, state_2 = 0, kind = 0, kind_2 = 0, behaviour = 0, shadow_player = 0, points = 0, vitality = 0;
	uint16_t hit_by = 0;

	if ((OBJECT(object)->flags & 0x20u) == 0u)
		return hitter;
	hit = OBJECT(object)->hit;
	if (hit < 0x11 || hit > 0x15)
		return hitter;
	state_2 = OBJECT(object)->state;
	if ((int8_t)state_2 < 0)
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
	shadow_player = OBJECT(hitter)->shadow_player;
	stack = shadow_player & 0x70u;
	points = OBJECT(object)->points;
	OBJECT(object)->points = (points & 0x8Fu) | stack;
	OBJECT(object)->flags = 0x80u;
	vitality = OBJECT(object)->vitality;
	if (vitality != 0u)
		state = 0xFFu;
	else
		state = 0xFEu;
	OBJECT(object)->state = state;
	OBJECT(object)->action = 0u;
	OBJECT(object)->action_step = 0u;
	return hitter;
}

/* Jumps to the enemies' hit check: an attack of kind 11 to 14 starts the reaction it calls for (a
   flinch, a knock-down, a spin or a knock-back). */
void vector_enemy_take_special_hit(uint16_t object, uint16_t *p_reaction_handlers, uint32_t *p_left_caller)
{
	uint16_t reaction_handlers = (uint16_t)*p_reaction_handlers;

	*p_reaction_handlers = reaction_handlers;
	enemy_check_hit(object, p_reaction_handlers, p_left_caller);
}

/* Jumps to the routine that marks a gone enemy's points to be scored and frees its place by the player
   it went after. */
uint16_t vector_enemy_score_and_release(uint16_t object, uint16_t target)
{
	return enemy_mark_defeated(object, target);
}

/* Turns the object to face the way field target_direction points (left when it is 40 to BF). */
void face_target(uint16_t object)
{
	uint8_t attributes = 0;
	uint8_t attributes_2 = 0, target_direction = 0;

	attributes_2 = OBJECT(object)->attributes;
	attributes = attributes_2 & 0xBFu;
	target_direction = OBJECT(object)->target_direction;
	if ((int8_t)(target_direction - 0x40u) >= 0)
		attributes |= 0x40u;
	OBJECT(object)->attributes = attributes;
}

/* Jumps to the routine that frees the enemy's place at its player's side when it holds one (parameter
   1). */
void vector_enemy_leave_side(uint16_t object, uint16_t target)
{
	enemy_leave_side_if_holding(object, target);
}

/* Unused: jumps to enemy_leave_side. */
void unused_vector_enemy_leave_side(uint16_t object, uint16_t target)
{
	enemy_leave_side(object, target);
}

/* Jumps to print_text. */
void vector_print_text(uint16_t colour, uint16_t *p_x, uint16_t *p_text)
{
	uint16_t text = (uint16_t)*p_text;
	uint16_t x = 0;

	*p_x = x;
	*p_text = text;
	print_text(colour, p_x, p_text);
}

/* Unused: jumps to print_hex_byte (only an unused debug display calls it). */
void unused_vector_print_hex_byte(uint16_t place, uint16_t value)
{
	print_hex_byte(place, value);
}

/* Jumps to the object setup: kind and animation, hit box, vitality and points from the record at U, and
   its priority from the floor under it. */
void vector_object_setup(uint16_t object, uint16_t setup)
{
	start_object_from_setup(object, setup);
}

/* Unused: does nothing. */
void unused_vector_no_op_1(void)
{
}

/* Jumps to the routine that takes gravity off the object's z speed and lands it on the floor (carry when
   it lands). */
void vector_apply_gravity(uint16_t object, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d = 0;

	*p_d = d;
	apply_gravity(object, p_d, &carry);
	*p_carry = carry;
}

/* Jumps to the routine that copies the hit box record at Y into the object's attack and box fields. */
void vector_set_hit_box(uint16_t object)
{
	uint16_t box = 0;

	box = (uint16_t)leftover_y;
	set_hit_box(object, box);
}

/* Jumps to the routine that removes the object once its x is past 01C0, scoring or releasing an enemy. */
uint16_t vector_remove_past_right_edge(uint16_t object, uint16_t target)
{
	return enemy_remove_off_screen(object, target);
}

/* Jumps to the routine that stops the object's x speed when its x is outside 0010-01AF. */
void vector_stop_at_screen_edges(uint16_t object)
{
	stop_beyond_screen_edge(object);
}

/* Unused: jumps to enemy_on_screen. */
void unused_vector_enemy_on_screen(void)
{
	enemy_on_screen(0u);
}

/* Jumps to print_game_text. */
void vector_print_game_text(uint16_t text_number)
{
	print_game_text(text_number);
}

/* Jumps to clear_list_1_objects. */
void vector_clear_list_1_objects(void)
{
	clear_list_1_objects();
}

/* Turns the object to face the way it moves across, when it moves. */
void face_movement(uint16_t object)
{
	uint8_t attributes = 0;
	uint8_t attributes_2 = 0, x_speed_2 = 0;
	uint16_t x_speed = 0;

	x_speed = OBJECT(object)->x_speed;
	if (x_speed == 0u)
		return;
	attributes_2 = OBJECT(object)->attributes;
	attributes = attributes_2;
	x_speed_2 = (uint8_t)(OBJECT(object)->x_speed >> 8u);
	if ((int8_t)x_speed_2 >= 0)
		attributes &= 0xBFu;
	else
		attributes |= 0x40u;
	OBJECT(object)->attributes = attributes;
}

/* Jumps to the routine that turns the object to face the way field target_direction points. */
void vector_face_direction(uint16_t object)
{
	enemy_face_target(object);
}

/* Jumps to the routine that picks the enemy's walk animation by the way to its player. */
void vector_choose_walk_animation(uint16_t object)
{
	enemy_pick_walk_animation(object);
}

/* Unused: jumps to enemy_pick_walk_animation_noting_direction. */
void unused_vector_enemy_pick_walk_animation(uint16_t object)
{
	enemy_pick_walk_animation_noting_direction(object);
}

/* Jumps to the plain goon's start: its setup, its vitality 1 when its parameter is set, then its state
   2. */
uint16_t vector_goon_start(uint16_t object)
{
	return enemy_goon_enter(object);
}

/* Jumps to the enemies' state 2: they go after a player, take a place by it and pick an action by their
   behaviour. */
void vector_enemy_think(uint16_t object, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t u = 0;

	*p_u = u;
	enemy_think(object, p_u, p_left_caller);
}

/* Jumps to the enemies' state 3: they run the action in field action. */
void vector_enemy_act(uint16_t object, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t u = 0;

	*p_u = u;
	enemy_attack(object, p_u, p_left_caller);
}

/* Jumps to the enemies' state 4: they run the shared hit reaction in field action. */
void vector_enemy_react(uint16_t object, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t u = 0;

	*p_u = u;
	enemy_hit_reaction(object, p_u, p_left_caller);
}

/* Jumps to the enemies' state 5: they climb or jump to the floor field blocked found. */
void vector_enemy_climb(uint16_t object, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t u = 0;

	*p_u = u;
	enemy_climb(object, p_u, p_left_caller);
}

/* Unused: jumps to enemy_become_goon. */
void unused_vector_enemy_become_goon(uint16_t object)
{
	enemy_become_goon(object);
}

/* Prints the BCD byte in A as two digits at the tile RAM's X in colour B, a blank for a leading 0. */
void print_bcd_byte(uint16_t place, uint16_t value)
{
	uint8_t bcd_byte = 0, high_digit = 0;
	uint8_t stack = 0;
	uint8_t high_nibble = 0;
	uint16_t tile_place = 0;

	bcd_byte = (uint8_t)(value >> 8);
	stack = bcd_byte;
	high_nibble = (((bcd_byte >> 1) >> 1) >> 1) >> 1;
	high_digit = high_nibble;
	if (high_nibble == 0u)
		high_digit = 0x10u;
	io_write8(place - 0x2000u, (uint8_t)value);
	tile_place = place;
	place = tile_place + 1u;
	io_write8(tile_place, high_digit);
	mem_write8(place - 0x2000u, (uint8_t)value);
	mem_write8(place, stack & 0xFu);
}

/* Unused: jumps to kind_90_effect. */
void unused_vector_kind_90_effect(uint16_t object, uint8_t d)
{
	kind_90_effect(object, d);
}

/* Puts in a kind_90_effect object at the object's place. */
void spawn_kind_90_effect(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, record = 0;

	leftover_y = kind_90_effect_child_ADDRESS;
	record = kind_90_effect_child_ADDRESS;
	spawn_child_object(object, record, &ignored16, &ignored16_2, &carry);
}

/* Jumps to enemy_hurt_become_goon. */
uint16_t vector_enemy_hurt_become_goon(uint16_t object)
{
	return enemy_hurt_become_goon(object);
}

/* Jumps to the plain goon's setup (object_setup_07F1A8, kind 80): facing left, after the nearest player,
   the goon's behaviour and its retarget time. */
uint16_t vector_goon_setup(uint16_t object)
{
	return enemy_goon_set_up(object);
}

/* Runs the enemy's shared hit reaction by field action; then, while work RAM 48B8 is under 0500, sends
   it into the pit reaction when there is no floor under it, else stops it at the walls. */
void enemy_react_with_pits(uint16_t object)
{
	uint32_t negative = 0;
	uint8_t action_step = 0, floor_cell = 0;
	uint16_t floor_probe = 0, ignored16 = 0;
	uint32_t left_caller = 0;
	uint8_t action_2 = 0;
	uint16_t action = 0, cemetery_position = 0;

	action = (((uint32_t)OBJECT(object)->action << 8u) | OBJECT(object)->action_step);
	action_step = (uint8_t)action;
	switch ((int8_t)(uint8_t)((uint32_t)(action >> 8) << 1))
	{
	case 0:
		enemy_flinch_from_behind(object, action_step, &ignored16, &left_caller);
		break;
	case 2:
		enemy_flinch_kind_12(object, action_step, &ignored16, &left_caller);
		break;
	case 4:
		enemy_knocked_forward(object, action_step, &ignored16, &left_caller);
		break;
	case 6:
		enemy_knocked_back(object, action_step, &ignored16, &left_caller);
		break;
	case 8:
		enemy_get_up(object, action_step, &ignored16, &left_caller);
		break;
	case 10:
		enemy_die(object, action_step, &ignored16, &left_caller);
		break;
	case 12:
		enemy_drop(object, action_step, &ignored16, &left_caller);
		break;
	case 14:
		enemy_sent_flying(object, action_step, &ignored16, &left_caller);
		break;
	case 16:
		enemy_spin_backward(object, action_step, &ignored16, &left_caller);
		break;
	case 18:
		enemy_flinch_kind_11(object, action_step, &ignored16, &left_caller);
		break;
	case 20:
		enemy_defeated_forward(object, action_step, &ignored16, &left_caller);
		break;
	case 22:
		enemy_defeated_backward(object, action_step, &ignored16, &left_caller);
		break;
	case 24:
		enemy_pit(object, action_step, &ignored16, &left_caller);
		break;
	}
	if (left_caller != 0u)
		return;
	cemetery_position = cemetery_scroll;
	if (cemetery_position >= 0x500u)
	{
		check_floor(object, ignored16);
		return;
	}
	action_2 = OBJECT(object)->action;
	if (action_2 == 0xCu)
		return;
	floor_probe = 0u;
	floor_at_offset(object, &floor_probe, &negative);
	floor_cell = (uint8_t)(floor_probe >> 8);
	if ((int8_t)floor_cell < 0)
	{
		OBJECT(object)->action = 0xCu;
		OBJECT(object)->action_step = 0u;
	}
}

/* Clears the 6 objects of list 2 (4D40), all but the ones lending their sprites (flags 1), keeping their
   sprite slots. */
uint16_t clear_child_objects(void)
{
	uint8_t clear_value = 0, clear_value_high = 0;
	uint16_t object_place = 0;
	uint8_t stack = 0, stack_10002 = 0;
	uint8_t object_words_left_was = 0, objects_left_was = 0;
	uint16_t kept_sprites = 0, cleared_word_place = 0;

	object_place = OBJECT_ADDRESS(8);
	cleared_objects_left = 6u;
	do
	{
		if (mem_read8(object_place) != 1u)
		{
			cleared_object_words_left = 0x30u;
			kept_sprites = mem_read16(object_place + 0x59u);
			stack = kept_sprites >> 8;
			stack_10002 = kept_sprites;
			clear_value = 0u;
			clear_value_high = 0u;
			do
			{
				cleared_word_place = object_place;
				object_place = cleared_word_place + 2u;
				mem_write16(cleared_word_place, (uint32_t)clear_value_high << 8);
				object_words_left_was = cleared_object_words_left;
				cleared_object_words_left = object_words_left_was - 1u;
			} while (object_words_left_was != 1u);
			mem_write16(object_place - 7u, ((uint32_t)stack << 8) | stack_10002);
		}
		else
			object_place += 0x60u;
		objects_left_was = cleared_objects_left;
		cleared_objects_left = objects_left_was - 1u;
	} while (objects_left_was != 1u);
	return object_place;
}

/* Runs the enemy's shared hit reaction by field action; then, for the actions under 0A, stops it at the
   walls. */
void enemy_react_with_walls(uint16_t object)
{
	uint8_t action_step = 0;
	uint16_t ignored16 = 0;
	uint32_t left_caller = 0;
	uint8_t action_2 = 0;
	uint16_t action = 0;

	action = (((uint32_t)OBJECT(object)->action << 8u) | OBJECT(object)->action_step);
	action_step = (uint8_t)action;
	switch ((int8_t)(uint8_t)((uint32_t)(action >> 8) << 1))
	{
	case 0:
		enemy_flinch_from_behind(object, action_step, &ignored16, &left_caller);
		break;
	case 2:
		enemy_flinch_kind_12(object, action_step, &ignored16, &left_caller);
		break;
	case 4:
		enemy_knocked_forward(object, action_step, &ignored16, &left_caller);
		break;
	case 6:
		enemy_knocked_back(object, action_step, &ignored16, &left_caller);
		break;
	case 8:
		enemy_get_up(object, action_step, &ignored16, &left_caller);
		break;
	case 10:
		enemy_die(object, action_step, &ignored16, &left_caller);
		break;
	case 12:
		enemy_drop(object, action_step, &ignored16, &left_caller);
		break;
	case 14:
		enemy_sent_flying(object, action_step, &ignored16, &left_caller);
		break;
	case 16:
		enemy_spin_backward(object, action_step, &ignored16, &left_caller);
		break;
	case 18:
		enemy_flinch_kind_11(object, action_step, &ignored16, &left_caller);
		break;
	case 20:
		enemy_defeated_forward(object, action_step, &ignored16, &left_caller);
		break;
	case 22:
		enemy_defeated_backward(object, action_step, &ignored16, &left_caller);
		break;
	case 24:
		enemy_pit(object, action_step, &ignored16, &left_caller);
		break;
	}
	if (left_caller != 0u)
		return;
	action_2 = OBJECT(object)->action;
	if (action_2 < 0xAu)
	{
		check_floor(object, ignored16);
		return;
	}
}

/* Jumps to ask_sound_cpu_check. */
void vector_ask_sound_cpu_check(uint16_t *p_x, uint16_t *p_d)
{
	uint16_t d = 0, x = 0;

	*p_x = x;
	*p_d = d;
	ask_sound_cpu_check(p_x, p_d);
}

/* Asks the Z80 to check the K053260's sample ROMs (command FE88), without waiting. */
uint16_t start_sample_rom_check(void)
{
	uint16_t command = 0;
	uint8_t t1 = 0;

	command = 0xFE88u;
	io_write16(sound_command_port, 0xFE88u);
	t1 = io_read8(sound_irq_port);
	return command;
}

/* Asks the Z80 for the check of the sample ROM 1F (commands F585 and F484), waiting for each answer. */
void check_sample_rom_1f(void)
{
	uint16_t command = 0;

	command = 0xF585u;
	send_sound_command_and_wait(command);
	command = 0xF484u;
	send_sound_command_and_wait(command);
}

/* Asks the Z80 for the check of the sample ROM 1D (commands F787 and F686), waiting for each answer. */
void check_sample_rom_1d(void)
{
	uint16_t command = 0;

	command = 0xF787u;
	send_sound_command_and_wait(command);
	command = 0xF686u;
	send_sound_command_and_wait(command);
}

/* Sets Z when the Z80 has answered start_sample_rom_check (88 in 1FC7). */
void sample_rom_check_answered(uint16_t *p_sample_check_command, uint32_t *p_zero)
{
	uint32_t zero = *p_zero;
	uint16_t sample_check_command = 0;
	uint8_t sound_echo = 0;

	sound_echo = io_read8(sound_echo_port);
	zero = (uint8_t)(0x88u - sound_echo) == 0u;
	sample_check_command = 0x88u;
	*p_sample_check_command = (*p_sample_check_command & 0xFF00u) | sample_check_command;
	*p_zero = zero;
}

/* Unused: does nothing. */
void unused_vector_no_op_2(void)
{
}

/* Jumps to the routine that sets the object's x and y speeds from a direction (A) and a speed (B). */
void vector_set_speed_by_direction(uint16_t object, uint16_t heading)
{
	set_speeds_from_direction(object, heading);
}

/* Unused: jumps to scaled_sine. */
void unused_vector_scaled_sine(uint16_t heading)
{
	uint16_t ignored16 = 0;

	scaled_sine(&ignored16, &heading);
}

/* Jumps to the routine that gives the direction, in 256ths of a turn, from the object at X to the one at
   U. */
uint16_t vector_direction_to(uint16_t object, uint16_t other)
{
	return direction_to(object, other);
}

/* Jumps to the routine that makes the nearest player the enemy's target. */
uint16_t vector_choose_nearest_player(uint16_t object)
{
	return enemy_target_nearest_player(object);
}

/* Jumps to the routine that adds the random number to work RAM 189E and returns it in A. */
uint16_t vector_next_random_byte(uint16_t roll)
{
	return enemy_random((uint8_t)roll);
}

/* Jumps to the routine that measures the distance and the way to the object at U into target_dx,
   target_dy and target_direction. */
void vector_measure_target(uint16_t object, uint16_t target)
{
	enemy_look_at_target(object, target);
}

/* Unused: jumps to enemy_find_attack_range. */
void unused_vector_enemy_find_attack_range(uint16_t object, uint16_t range)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;

	enemy_find_attack_range(object, &range, &ignored16, &carry);
}

/* Jumps to the routine that puts in a child object by the record at Y, at an offset from the object at
   X. */
void vector_spawn_child(uint16_t object, uint16_t *p_y, uint16_t *p_u, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d = 0, record = 0, u = 0;

	record = (uint16_t)leftover_y;
	*p_u = u;
	*p_d = d;
	spawn_child_object(object, record, p_u, p_d, &carry);
	*p_y = record;
	*p_carry = carry;
}

/* Puts in an object of list 2 (4D40) with the type of the record at Y (its byte 5), at the record's
   offset from the object at X; carry when there was a free slot. */
void spawn_list_2_child(uint16_t object, uint16_t child_object, uint16_t *p_child, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t child = 0, ignored16 = 0, list_number = 0;
	uint8_t list = 0;

	list_number = 2u;
	take_free_object(&child, &list_number, &carry);
	if (carry)
	{
		list = CHILD_OBJECT(child_object)->list;
		OBJECT(child)->type = list;
		place_child_object(object, child_object, child, &ignored16, &carry);
	}
	*p_child = child;
	*p_carry = carry;
}

/* The floor map's cell at the object's place moved by the 8.8 offsets in work RAM 48F8 (across) and 48FA
   (on the floor). */
uint16_t floor_at_scratch_offset(uint16_t object)
{
	uint32_t negative = 0;
	uint16_t cell = 0, ignored16 = 0;

	floor_offset_x = floor_probe_dx;
	floor_offset_y = floor_probe_dy;
	floor_cell_at(object, &ignored16, &cell, &negative);
	return cell;
}

/* Jumps to floor_at_offset. */
void vector_floor_at_offset(uint16_t object, uint16_t *p_offsets, uint32_t *p_negative)
{
	uint16_t offsets = (uint16_t)*p_offsets;
	uint32_t negative = *p_negative;

	*p_offsets = offsets;
	floor_at_offset(object, p_offsets, &negative);
	*p_negative = negative;
}

/* Jumps to floor_ahead. */
void vector_floor_ahead(uint16_t object, uint16_t *p_d, uint32_t *p_negative)
{
	uint32_t negative = *p_negative;
	uint16_t d = 0;

	*p_d = d;
	floor_ahead(object, p_d, &negative);
	*p_negative = negative;
}

/* Unused: jumps to enemy_start_climbing. */
void unused_vector_enemy_start_climbing(uint16_t object)
{
	enemy_start_climbing(object);
}

/* Jumps to floor_ahead_x. */
void vector_floor_ahead_x(uint16_t object, uint16_t *p_d, uint32_t *p_negative)
{
	uint32_t negative = *p_negative;
	uint16_t d = 0;

	*p_d = d;
	floor_ahead_x(object, p_d, &negative);
	*p_negative = negative;
}

/* Jumps to floor_ahead_y. */
void vector_floor_ahead_y(uint16_t object, uint16_t *p_d, uint32_t *p_negative)
{
	uint32_t negative = *p_negative;
	uint16_t d = 0;

	*p_d = d;
	floor_ahead_y(object, p_d, &negative);
	*p_negative = negative;
}

/* Turns the object's flags 80 (shown) and 04 over: called each frame, it blinks. */
void blink(uint16_t object)
{
	OBJECT(object)->flags ^= 0x84u;
}

/* Unused: on a floor, takes the floor cell's height and sprite priority under the object. */
void unused_take_floor_height_and_priority(uint16_t object)
{
	uint32_t negative = 0;
	uint8_t floor_cell = 0;
	uint16_t floor_probe = 0;
	uint8_t attributes = 0;

	floor_probe = 0u;
	floor_at_offset(object, &floor_probe, &negative);
	floor_cell = (uint8_t)(floor_probe >> 8);
	if ((int8_t)floor_cell >= 0)
	{
		floor_priority_bits = floor_cell;
		OBJECT(object)->floor_z = (OBJECT(object)->floor_z & 0xFF00u) | ((((floor_cell & 0xFu) << 1) << 1) << 1 & 0xFFu);
		floor_priority_bits &= 0x30u;
		attributes = OBJECT(object)->attributes;
		OBJECT(object)->attributes = (attributes & 0xCFu) | floor_priority_bits;
	}
}

/* The floor map's cell under the object: its address in U and its value in A. */
void floor_cell_under(uint16_t object, uint16_t *p_u, uint16_t *p_d)
{
	uint32_t negative = 0;
	uint16_t d = 0, u = 0;

	floor_offset_x = 0;
	floor_offset_y = 0;
	*p_u = u;
	*p_d = d;
	floor_cell_at(object, p_u, p_d, &negative);
}

/* Jumps to check_skip. */
void vector_check_skip(uint16_t wait, uint16_t *p_presses_addresses, uint32_t *p_carry)
{
	uint16_t presses_addresses = (uint16_t)*p_presses_addresses;
	uint32_t carry = *p_carry;

	*p_presses_addresses = presses_addresses;
	check_skip(wait, p_presses_addresses, &carry);
	*p_carry = carry;
}

/* Jumps to queue_job. */
void vector_queue_job(uint16_t job)
{
	queue_job(job);
}

/* Jumps to reset_sound. */
void vector_reset_sound(void)
{
	reset_sound();
}

/* The hit reaction of the enemies with their own hit animations, by its step: a flinch or a knock-down
   by field action and getting up, or when defeated lying down and then becoming a plain goon or blinking
   out; it keeps them inside the screen and stops them at the walls. */
uint16_t enemy_hurt(uint16_t object)
{
	uint16_t hurt_step_table = 0;
	uint8_t action_step = 0;

	hurt_step_table = enemy_hurt_steps_ADDRESS;
	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		hurt_step_table = enemy_hurt_start(object, hurt_step_table);
		break;
	case 2:
		enemy_hurt_recover(object);
		break;
	case 4:
		enemy_hurt_fall_defeated(object);
		break;
	case 6:
		hurt_step_table = enemy_hurt_lie_defeated(object, hurt_step_table);
		break;
	case 8:
		hurt_step_table = enemy_hurt_vanish(object, hurt_step_table);
		break;
	case 10:
		enemy_hurt_fall(object);
		break;
	case 12:
		enemy_hurt_get_up(object);
		break;
	}
	if (OBJECT(object)->flags == 0u)
		return hurt_step_table;
	stop_beyond_screen_edge(object);
	return check_floor(object, hurt_step_table);
}

/* Jumps to the routine that, while the object falls, lands it on the floor under it (carry when it
   lands). */
uint32_t vector_check_landing(uint16_t object)
{
	return land_if_falling(object);
}

/* Unused: jumps to unused_take_floor_priority. */
void unused_vector_take_floor_priority(uint16_t object)
{
	unused_take_floor_priority(object);
}

/* Jumps to the routine that sets the object's x and y speeds from a direction (A) at the walk's speed
   (sines_20). */
uint16_t vector_set_walk_speed_by_direction(uint16_t object, uint16_t u, uint16_t heading)
{
	return set_walk_speeds_from_direction(object, u, heading);
}

/* Unused: does nothing. */
void unused_vector_no_op_3(void)
{
}

/* Jumps to the routine that gives the direction from the object at X to the place B pixels across from
   the object at U. */
uint16_t vector_direction_to_offset(uint16_t object, uint16_t other, uint16_t x_offset)
{
	return direction_to_beside(object, other, (uint8_t)x_offset);
}

/* Checks the object's hit box against the 8 enemies' (list 0) that can be hit; each pair that touches
   takes the other's damage and attack. */
void check_hits_with_enemies(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, object_2 = 0;
	uint8_t enemies_left_was = 0;

	OBJECT(object)->flags &= 0xDFu;
	OBJECT(object)->hit = 0u;
	object_2 = OBJECT_ADDRESS(14);
	hit_check_enemies_left = 8u;
	do
	{
		if ((OBJECT(object_2)->flags & 0x40u) != 0u)
		{
			boxes_overlap(object, object_2, &ignored16, &carry);
			if (carry)
				trade_hits(object, object_2);
		}
		object_2 += 0x60u;
		enemies_left_was = hit_check_enemies_left;
		hit_check_enemies_left = enemies_left_was - 1u;
	} while (enemies_left_was != 1u);
}

/* Jumps to the routine that starts the palette job work RAM 487E asks for, with D. */
uint16_t vector_palette_request(uint16_t palette_job, uint16_t request)
{
	return palette_request(palette_job, request);
}

/* Unused: jumps to unused_collide_with_list_1_objects. */
void unused_vector_collide_with_list_1_objects(uint16_t object)
{
	unused_collide_with_list_1_objects(object);
}

/* Jumps to the routine that finds and clears a free object of the list in B (carry and U when found). */
void vector_find_free_slot(uint16_t list_number, uint16_t *p_u, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t u = 0;

	*p_u = u;
	take_free_object(p_u, &list_number, &carry);
	*p_carry = carry;
}

/* Jumps to queue_sound. */
uint32_t vector_queue_sound(uint16_t command)
{
	return queue_sound(command);
}

/* Removes the object when its x is outside 0040-01BF; carry while it is inside. */
uint32_t remove_off_screen(uint16_t object, uint32_t carry)
{
	uint16_t window_x = 0;
	uint16_t object_x = 0;

	if (OBJECT(object)->flags != 0u)
	{
		object_x = OBJECT(object)->x;
		window_x = object_x - 0x40u;
		carry = window_x < 0x180u;
		if (window_x >= 0x180u)
		{
			carry = 0u;
			OBJECT(object)->flags = 0u;
		}
	}
	return carry;
}

/* Finds the nearest player in play to the object (U, and A the distance's high byte; carry when one was
   found). */
void find_nearest_player(uint16_t object, uint16_t *p_nearest, uint16_t *p_nearest_result, uint32_t *p_carry)
{
	uint16_t nearest = (uint16_t)*p_nearest;
	uint16_t nearest_result = (uint16_t)*p_nearest_result;
	uint32_t carry = *p_carry;
	uint16_t distance = 0, object_2 = 0, x_distance = 0;
	uint8_t stack = 0;
	uint16_t stack_3 = 0;
	uint8_t present_count = 0, state = 0, players_left_was = 0;
	uint16_t own_x = 0, player_x = 0, x_difference = 0, own_y = 0, player_y = 0, y_difference = 0, nearest_found = 0;

	present_count = io_read8(stage_player_count);
	if (present_count != 0u)
	{
		stack = 4u;
		object_2 = OBJECT_ADDRESS(0);
		distance = 0x7FFFu;
		nearest_player_distance = 0x7FFFu;
		do
		{
			if (OBJECT(object_2)->flags != 0u)
			{
				state = OBJECT(object_2)->state;
				if ((int8_t)state >= 0)
				{
					own_x = OBJECT(object)->x;
					player_x = OBJECT(object_2)->x;
					x_difference = own_x - player_x;
					x_distance = x_difference;
					if ((int16_t)x_difference < 0)
						x_distance = 0u - x_distance;
					stack_3 = x_distance;
					own_y = OBJECT(object)->y;
					player_y = OBJECT(object_2)->y;
					y_difference = own_y - player_y;
					distance = y_difference;
					if ((int16_t)y_difference < 0)
						distance = 0u - distance;
					distance += stack_3;
					if (distance < nearest_player_distance)
					{
						nearest_player_distance = distance;
						io_write16(nearest_player_found, object_2);
					}
				}
			}
			object_2 += 0xC0u;
			players_left_was = stack;
			stack = players_left_was - 1u;
		} while (players_left_was != 1u);
		nearest_found = io_read16(nearest_player_found);
		nearest = nearest_found;
		nearest_result = (distance & 0xFFu) | ((uint32_t)nearest_player_distance_high << 8);
		carry = nearest_result >> 8 < 0x7Fu;
	}
	else
	{
		carry = 0u;
		nearest_result &= 0xFFu;
	}
	*p_nearest = nearest;
	*p_nearest_result = nearest_result;
	*p_carry = carry;
}

/* Jumps to queue_sound_unless_attract. */
uint32_t vector_queue_sound_unless_attract(uint16_t command)
{
	return queue_sound_unless_attract(command);
}

/* Jumps to clear_objects. */
void vector_clear_objects(uint16_t *p_x, uint16_t *p_u)
{
	uint16_t u = 0, x = 0;

	*p_x = x;
	*p_u = u;
	clear_objects(p_x, p_u);
}

/* Jumps to clear_sprites. */
uint16_t vector_clear_sprites(void)
{
	return clear_sprites();
}

/* Jumps to print_hex_word. */
uint16_t vector_print_hex_word(uint16_t place, uint16_t value)
{
	return print_hex_word(place, value);
}

/* Jumps to clear_layer_a. */
void vector_clear_layer_a(void)
{
	clear_layer_a();
}

/* Jumps to clear_layer_b. */
void vector_clear_layer_b(void)
{
	clear_layer_b();
}

/* Jumps to clear_text_layer. */
void vector_clear_text_layer(uint16_t *p_x, uint16_t *p_d)
{
	uint16_t d = 0, x = 0;

	*p_x = x;
	*p_d = d;
	clear_text_layer(p_x, p_d);
}

/* Jumps to queue_sound_always. */
void vector_queue_sound_always(uint16_t command)
{
	queue_sound_always(command);
}

/* Jumps to insert_high_score. */
void vector_insert_high_score(uint16_t place)
{
	insert_high_score(place);
}

/* Jumps to high_score_rank. */
uint16_t vector_high_score_rank(uint16_t score)
{
	uint32_t carry = 0;

	high_score_rank(&score, &carry);
	return score;
}

/* Prints the BCD word in D as four digits at the tile RAM's X, blanks for the leading zeros. */
void print_bcd_word(uint16_t place, uint16_t value)
{
	uint8_t digit = 0, digit_2 = 0, digit_3 = 0, high_byte = 0, low_byte = 0;
	uint8_t stack = 0, stack_2 = 0;
	uint8_t nibble = 0, nibble_2 = 0, nibble_3 = 0;
	uint16_t tile_place = 0, tile_place_2 = 0, tile_place_3 = 0;

	high_byte = (uint8_t)(value >> 8);
	stack = high_byte;
	nibble = (((high_byte >> 1) >> 1) >> 1) >> 1;
	digit = nibble;
	if (nibble == 0u)
		digit = 0x10u;
	mem_write8(place - 0x2000u, 0u);
	tile_place = place;
	place = tile_place + 1u;
	mem_write8(tile_place, digit);
	nibble_2 = stack & 0xFu;
	digit_2 = nibble_2;
	if (nibble_2 == 0u)
		digit_2 = 0x10u;
	mem_write8(place - 0x2000u, 0u);
	tile_place_2 = place;
	place = tile_place_2 + 1u;
	mem_write8(tile_place_2, digit_2);
	low_byte = (uint8_t)value;
	stack_2 = low_byte;
	nibble_3 = (((low_byte >> 1) >> 1) >> 1) >> 1;
	digit_3 = nibble_3;
	if (nibble_3 == 0u && stack == 0u)
		digit_3 = 0x10u;
	mem_write8(place - 0x2000u, 0u);
	tile_place_3 = place;
	place = tile_place_3 + 1u;
	mem_write8(tile_place_3, digit_3);
	mem_write8(place - 0x2000u, 0u);
	mem_write8(place, stack_2 & 0xFu);
}

/* Jumps to the routine that finds a free object in the list bits 2-3 of B name (a spawn record's flags). */
void vector_find_free_slot_by_flags(uint8_t spawn_flags, uint16_t *p_u, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t u = 0;

	*p_u = u;
	take_free_object_for_spawn(spawn_flags, p_u, &carry);
	*p_carry = carry;
}

/* Jumps to the routine that draws B strips of 8 pixels of the layer A names, from its scroll on. */
void vector_draw_layer_strips(uint16_t layer_and_columns, uint16_t *p_x, uint16_t *p_u)
{
	uint16_t u = 0, x = 0;

	*p_x = x;
	*p_u = u;
	draw_layer_columns(layer_and_columns, p_x, p_u);
}

/* Jumps to the routine that sets the K052109's tile banks (1D80, 1F00) by the map's scene and area. */
void vector_set_layer_modes(void)
{
	set_area_tile_banks();
}

/* Takes A objects from X out of the game (flags 1) and gives their sprites fixed orders from FF down, so
   a screen can draw with them. */
void reserve_objects_for_sprites(uint16_t object, uint16_t object_count)
{
	uint8_t control = 0, order = 0, reserve_count = 0;
	uint16_t sprite_place = 0;
	uint8_t stack = 0, stack_2 = 0;
	uint8_t sprites_left_was = 0, objects_left_was = 0;
	uint16_t sprites = 0;

	reserve_count = (uint8_t)(object_count >> 8);
	stack = reserve_count;
	control = board_control | 2u;
	board_control = control;
	io_write8(board_control_register, control);
	order = 0xFFu;
	do
	{
		sprites = OBJECT(object)->sprites;
		sprite_place = sprites;
		stack_2 = 8u;
		do
		{
			OBJECT(object)->flags = 1u;
			SPRITE_ENTRY(sprite_place)->depth = order;
			sprite_place += 0x10u;
			order--;
			sprites_left_was = stack_2;
			stack_2 = sprites_left_was - 1u;
		} while (sprites_left_was != 1u);
		object += 0x60u;
		objects_left_was = stack;
		stack = objects_left_was - 1u;
	} while (objects_left_was != 1u);
	control = board_control & ~3u;
	board_control = control;
	io_write8(board_control_register, control);
}

/* Jumps to erase_text. */
void vector_erase_text(uint16_t text)
{
	erase_text(text);
}

/* The enemies' hit check: an attack of kind 11 to 14 starts the reaction it calls for, or the defeat
   when the enemy's vitality is gone. */
uint32_t enemy_take_special_hit_or_fall(uint16_t object)
{
	uint8_t action = 0;
	uint16_t ignored16 = 0;
	uint32_t left_caller = 0;
	uint8_t vitality = 0, hit_from_behind = 0, hit = 0;

	enemy_take_hit(object, &ignored16, &left_caller);
	if (left_caller != 0u)
	{
		left_caller = 0u;
		return left_caller;
	}
	vitality = OBJECT(object)->vitality;
	if (vitality == 0u)
	{
		hit_from_behind = OBJECT(object)->hit_from_behind;
		if (hit_from_behind == 0u)
			action = 0xBu;
		else
			action = 0xAu;
		OBJECT(object)->action = action;
		OBJECT(object)->action_step = 0u;
		return left_caller;
	}
	hit = OBJECT(object)->hit;
	switch ((int8_t)(uint8_t)((hit - 0x11u) << 1))
	{
	case 0:
	case 2:
		enemy_react_to_hit(object);
		return left_caller;
	case 4:
		enemy_react_sent_flying(object);
		return left_caller;
	case 6:
		enemy_react_knocked_down(object);
		return left_caller;
	}
	unreachable();
}

/* Jumps to the routine that queues the scene's music. */
void vector_play_scene_music(void)
{
	play_stage_music();
}

/* Turns the boss's colours by how much of its vitality is left, in 5 steps of A, with the palette
   effects of row B of hurt_effect_rows; the first call starts the row's normal effect and keeps its job. */
void boss_shade_by_vitality(uint16_t object, uint16_t step_and_row)
{
	uint8_t effect_row = 0, shade_level = 0, threshold = 0, vitality_step = 0;
	uint16_t palette_job = 0, request = 0, shade_job = 0, y = 0;
	uint8_t vitality = 0, shade_level_2 = 0, vitality_2 = 0, full_vitality = 0, vitality_3 = 0;
	uint16_t shade_job_2 = 0, normal = 0, shade_job_3 = 0, normal_2 = 0;

	vitality_step = (uint8_t)(step_and_row >> 8);
	effect_row = (uint8_t)step_and_row;
	shade_arguments = ((uint32_t)vitality_step << 8) | effect_row;
	shade_new_level = 0u;
	vitality = OBJECT(object)->vitality;
	if (vitality == 0u)
	{
		shade_job_2 = OBJECT(object)->boss_shade.shade_job;
		palette_job = shade_job_2;
		if (shade_job_2 != 0u)
		{
			shade_level = shade_new_level;
			shade_level_2 = OBJECT(object)->boss_shade.shade_level;
			if (shade_level < shade_level_2)
			{
				OBJECT(object)->boss_shade.shade_level = shade_level;
				palette_request_kind = 8u;
				y = hurt_effect_rows[(int8_t)((uint8_t)((uint32_t)shade_effect_row << 1)) / 2];
				leftover_y = y;
				normal = HURT_EFFECT_ROW(y + (int8_t)((uint32_t)shade_new_level << 1))->normal;
				request = normal;
				palette_request(palette_job, request);
			}
		}
		return;
	}
	shade_job_3 = OBJECT(object)->boss_shade.shade_job;
	palette_job = shade_job_3;
	if (shade_job_3 == 0u)
	{
		OBJECT(object)->boss_shade.shade_level = 5u;
		vitality_2 = OBJECT(object)->vitality;
		OBJECT(object)->boss_shade.full_vitality = vitality_2;
		palette_request_kind = 2u;
		shade_job = hurt_effect_rows_ADDRESS;
		normal_2 = HURT_EFFECT_ROW(hurt_effect_rows[(int8_t)((uint8_t)((uint32_t)shade_effect_row << 1)) / 2])->normal;
		request = normal_2;
		shade_job = palette_request(shade_job, request);
		OBJECT(object)->boss_shade.shade_job = shade_job;
		return;
	}
	shade_vitality_over = vitality_step * 5u;
	full_vitality = OBJECT(object)->boss_shade.full_vitality;
	shade_vitality_over = full_vitality - shade_vitality_over;
	vitality_3 = OBJECT(object)->vitality;
	shade_vitality_over = vitality_3 - shade_vitality_over;
	threshold = shade_vitality_step;
	shade_new_level++;
	while (threshold < shade_vitality_over)
	{
		threshold += shade_vitality_step;
		shade_new_level++;
		if (shade_new_level == 5u)
			return;
	}
	shade_level = shade_new_level;
	shade_level_2 = OBJECT(object)->boss_shade.shade_level;
	if (shade_level < shade_level_2)
	{
		OBJECT(object)->boss_shade.shade_level = shade_level;
		palette_request_kind = 8u;
		y = hurt_effect_rows[(int8_t)((uint8_t)((uint32_t)shade_effect_row << 1)) / 2];
		leftover_y = y;
		normal = HURT_EFFECT_ROW(y + (int8_t)((uint32_t)shade_new_level << 1))->normal;
		request = normal;
		palette_request(palette_job, request);
	}
}

/* Jumps to the routine that puts the camera and both layers at x D. */
void vector_set_scroll_x(uint16_t scroll_x)
{
	set_scroll_x(scroll_x);
}

/* Jumps to the routine that puts the camera and both layers at y D. */
void vector_set_scroll_y(uint16_t scroll_y)
{
	set_scroll_y(scroll_y);
}

/* Prints the text at U (an address, its characters, '/' a new address, ' */
void print_big_text(uint16_t text, uint16_t colour)
{
	uint8_t attribute = 0, character = 0;
	uint16_t place = 0;
	uint16_t place_source = 0, character_source = 0;

	attribute = (uint8_t)(colour >> 8);
	attribute += 2u;
	for (;;)
	{
		place_source = text;
		text = place_source + 2u;
		place = mem_read16(place_source);
		for (;;)
		{
			character_source = text;
			text = character_source + 1u;
			character = mem_read8(character_source);
			if (character == 0x23u)
				return;
			if (character == 0x2Fu)
				break;
			character = ((character - 0x30u) << 1) << 1;
			mem_write8(place - 0x2000u, attribute);
			mem_write8(place, character);
			character++;
			mem_write8(place - 0x1FFFu, attribute);
			mem_write8(place + 1u, character);
			character++;
			mem_write8(place - 0x1FC0u, attribute);
			mem_write8(place + 0x40u, character);
			mem_write8(place - 0x1FBFu, attribute);
			mem_write8(place + 0x41u, character + 1u);
			place += 2u;
		}
	}
}

/* Blanks a text that print_big_text printed, 2 x 2 tiles a character. */
void erase_big_text(uint16_t text)
{
	uint8_t character = 0;
	uint16_t place = 0;
	uint16_t place_source = 0, character_source = 0;

	for (;;)
	{
		place_source = text;
		text = place_source + 2u;
		place = mem_read16(place_source);
		for (;;)
		{
			character_source = text;
			text = character_source + 1u;
			character = mem_read8(character_source);
			if (character == 0x23u)
				return;
			if (character == 0x2Fu)
				break;
			mem_write8(place - 0x2000u, 0u);
			mem_write8(place, 0x10u);
			mem_write8(place - 0x1FFFu, 0u);
			mem_write8(place + 1u, 0x10u);
			mem_write8(place - 0x1FC0u, 0u);
			mem_write8(place + 0x40u, 0x10u);
			mem_write8(place - 0x1FBFu, 0u);
			mem_write8(place + 0x41u, 0x10u);
			place += 2u;
		}
	}
}
