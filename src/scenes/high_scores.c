/**
 *    Name:        scenes/high_scores.c
 *    Description: the bank's jump table, then the name entry and the attract's high score table
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Runs the name entry of the high scores by its state (3840): set up, the players typing their initials,
   a last wait, then the scores saved (carry when done). */
uint32_t name_entry(void)
{
	uint8_t control = 0;
	uint8_t t1 = 0;

	control = board_control & ~3u;
	board_control = control;
	io_write8(0x1FC2u, control);
	t1 = io_read8(0x3840u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		return name_entry_set_up();
	case 2:
		return name_entry_type_initials();
	case 4:
		return name_entry_linger();
	}
	unreachable();
}

/* Runs the ending by the scene's state: the family, the staff roll and the last fade; after 192 frames a
   player's button skips it. */
void ending(uint16_t u)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, wait = 0;
	uint8_t t1 = 0;

	wait = 0xC000u;
	vector_check_skip(wait, &ignored16, &carry);
	if (carry)
	{
		vector_clear_objects(&ignored16, &ignored16_2);
		scene_running = 0u;
		return;
	}
	gauges_shown = 0u;
	t1 = io_read8(scene_state);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		ending_set_up(u);
		return;
	case 2:
		ending_show_family();
		return;
	case 4:
		ending_roll_credits();
		return;
	case 6:
		ending_toss();
		return;
	case 8:
		ending_catch();
		return;
	case 10:
		ending_fade_start(u);
		return;
	case 12:
		ending_fade(u);
		return;
	}
}

/* Runs stage 7's boss each frame: reacts to a hit, runs its state, keeps it inside its area, sends its
   helpers and draws its health gauge. */
uint16_t stage_7_boss_update(uint16_t object, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t state = 0;
	uint16_t step_and_row = 0, u = 0;
	uint8_t state_2 = 0;

	y = stage_7_boss_check_hit(object, y);
	u = stage_7_boss_states_ADDRESS;
	state_2 = OBJECT(object)->state;
	state = state_2;
	carry = (int8_t)state < 0;
	switch ((int8_t)(uint8_t)((uint32_t)state << 1))
	{
	case 0:
		y = stage_7_boss_entrance(object, y);
		break;
	case 2:
		y = stage_7_boss_walk(object, y);
		break;
	case 4:
		y = stage_7_boss_attack(object, y);
		break;
	case 6:
		y = stage_7_boss_charge(object, y);
		break;
	case 8:
		y = stage_7_boss_jump_away(object, y);
		break;
	case 10:
		y = stage_7_boss_idle(object, y, u);
		break;
	case 12:
		y = stage_7_boss_wait_target_up(object, y);
		break;
	case 14:
		stage_7_boss_beaten_wait(object);
		break;
	case 16:
		stage_7_boss_blink_out(object, carry);
		break;
	case 18:
		stage_7_boss_fall(object);
		break;
	case 20:
		stage_7_boss_lie(object);
		break;
	case 22:
		y = stage_7_boss_get_up(object, y);
		break;
	case 24:
		stage_7_boss_flinch_wait(object);
		break;
	case 26:
		y = stage_7_boss_flinch_land(object, y);
		break;
	case 28:
		y = stage_7_boss_put_in(object);
		break;
	case 30:
		stage_7_boss_start_entrance(object);
		break;
	case 32:
		stage_7_boss_move_helpers(object);
		break;
	case 34:
		stage_7_boss_step_forward(object);
		break;
	case 36:
		stage_7_boss_arrive(object);
		break;
	case 38:
		stage_7_boss_entrance_pose(object);
		break;
	case 40:
		stage_7_boss_entrance_end(object);
		break;
	case 42:
		stage_7_boss_wind_up(object);
		break;
	case 44:
		stage_7_boss_strike(object);
		break;
	case 46:
		y = stage_7_boss_recover(object, y);
		break;
	case 48:
		stage_7_boss_charging(object);
		break;
	case 50:
		y = stage_7_boss_charge_end(object, y);
		break;
	case 52:
		stage_7_boss_jump_rise(object);
		break;
	case 54:
		stage_7_boss_jump_land(object);
		break;
	case 56:
		stage_7_boss_jump_end(object);
		break;
	case -6:
		y = stage_7_boss_beaten(object, y);
		break;
	case -4:
		y = stage_7_boss_knocked_down(object, y);
		break;
	case -2:
		y = stage_7_boss_flinch(object, y);
		break;
	}
	stage_7_boss_keep_in_x(object);
	stage_7_boss_keep_in_y(object);
	y = stage_7_boss_order_throws(object, y);
	step_and_row = ((uint32_t)stage_7_boss_gauge_piece_health_by_players[(int8_t)((uint8_t)(player_count - 1u))] << 8) | 4u;
	y = boss_shade_by_vitality(object, y, step_and_row);
	return y;
}

/* Runs one of stage 7's boss' four helpers by its state: waits, moves as the boss says, or throws. */
void stage_7_boss_helper_update(uint16_t object, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t state = 0;

	u = stage_7_boss_helper_states_ADDRESS;
	state = OBJECT(object)->state;
	switch ((int8_t)(uint8_t)((uint32_t)state << 1))
	{
	case 0:
		stage_7_boss_helper_idle();
		break;
	case 2:
	case 4:
	case 6:
	case 8:
	case 10:
	case 12:
		stage_7_boss_helper_move(object, &y, &u);
		break;
	case 14:
		stage_7_boss_helper_attack(object, &y, &u);
		break;
	case 16:
		u = stage_7_boss_helper_start_move(object);
		break;
	case 18:
		y = stage_7_boss_helper_moving(object);
		break;
	case 20:
		stage_7_boss_helper_throw_start(object);
		break;
	case 22:
		stage_7_boss_helper_throw_end(object);
		break;
	}
	*p_y = y;
	*p_u = u;
}

/* The name entry: ranks the players by score, draws each one who made the table a column with its face,
   place and score, starts its initials at the letter A, and sets Maggies walking along the bottom. */
uint32_t name_entry_set_up(void)
{
	uint32_t carry = 0, half_carry = 0;
	uint8_t digit = 0, place = 0, place_number = 0, player_offset = 0, tens = 0;
	uint16_t column_and_picture = 0, d = 0, entry = 0, entry_2 = 0, initials = 0, letter_and_colour = 0, name_entry_player = 0, object = 0, object_count = 0, place_suffix = 0, ranked = 0, sprite = 0;
	uint8_t t8 = 0, t16 = 0, t17 = 0, t20 = 0, t21 = 0, t24 = 0, t25 = 0, t30 = 0, t34 = 0, t35 = 0;
	uint16_t t1 = 0, score = 0, t2 = 0, t3 = 0, t4 = 0, sprites = 0, t5 = 0, t6 = 0, sprites_2 = 0, score_2 = 0, t7 = 0, place_x = 0, place_y = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0, t15 = 0, score_x = 0, score_y = 0, t18 = 0, t19 = 0, t22 = 0, t23 = 0, t26 = 0, t27 = 0, t28 = 0, t29 = 0, t31 = 0, t32 = 0, t33 = 0;

	object = OBJECT_ADDRESS(0);
	object_count = 0x800u;
	reserve_objects_for_sprites(object, object_count);
	name_entry_rank_players();
	players_ranked = 0u;
	ranked = 0x3860u;
	do
	{
		t1 = ranked;
		ranked = t1 + 1u;
		player_offset = (uint32_t)mem_read8(t1) << 1;
		name_entry_player = TABLE16(name_entry_player_records, (int8_t)player_offset);
		entry_2 = 0x3842u + (int8_t)((uint32_t)player_offset << 1);
		score = NAME_ENTRY_PLAYER(name_entry_player)->score;
		t2 = mem_read16(score);
		d = t2;
		d = vector_high_score_rank(d);
		place = (uint8_t)(d >> 8);
		place += players_ranked;
		if (place > 9u)
		{
			t3 = ranked;
			ranked = t3 + 1u;
			mem_write8(t3, 0xFFu);
			t4 = entry_2;
			io_write8(t4, 0xFFu);
			sprites = NAME_ENTRY_PLAYER(name_entry_player)->sprites;
			mem_write16(t4 + 1u, sprites);
		}
		else
		{
			t5 = ranked;
			ranked = t5 + 1u;
			mem_write8(t5, place);
			t6 = entry_2;
			io_write8(t6, place);
			sprites_2 = NAME_ENTRY_PLAYER(name_entry_player)->sprites;
			mem_write16(t6 + 1u, sprites_2);
		}
		players_ranked++;
	} while (players_ranked != 4u);
	entry = 0x3842u;
	entry_player = 0u;
	do
	{
		name_entry_player = name_entry_player_records[(int8_t)((uint8_t)((uint32_t)entry_player << 1)) / 2];
		entry_player_record = name_entry_player;
		sprite = NAME_ENTRY_PLAYER(name_entry_player)->sprites;
		score_2 = NAME_ENTRY_PLAYER(name_entry_player)->score;
		t7 = mem_read16(score_2);
		entry_score = t7;
		if ((int8_t)mem_read8(entry) >= 0)
		{
			column_and_picture = entry_player;
			name_entry_draw_picture(column_and_picture);
			column_and_picture = ((uint32_t)entry_player << 8) | (uint8_t)(4u + entry_player);
			name_entry_draw_picture(column_and_picture);
			place_x = NAME_ENTRY_PLAYER(name_entry_player)->place_x;
			sprite_text_x = place_x;
			place_y = NAME_ENTRY_PLAYER(name_entry_player)->place_y;
			sprite_text_y = place_y;
			place_number = mem_read8(entry);
			half_carry = ((uint8_t)(place_number ^ 1u ^ (place_number + 1u)) >> 4) & 1u;
			carry = (uint8_t)(place_number + 1u) < place_number;
			place_number = konami_daa((uint8_t)(place_number + 1u), half_carry, carry);
			entry_digit_state = place_number;
			t8 = (((place_number >> 1) >> 1) >> 1) >> 1;
			tens = t8;
			if (t8 != 0u)
			{
				letter_and_colour = ((uint32_t)(uint8_t)(tens + 0x30u) << 8) | (uint8_t)(0xAu + entry_player);
				sprite = print_sprite_letter(sprite, letter_and_colour);
			}
			t9 = sprite_text_x;
			t10 = t9 + 0x10u;
			sprite_text_x = t10;
			letter_and_colour = ((uint32_t)(uint8_t)((entry_digit_state & 0xFu) + 0x30u) << 8) | (uint8_t)(0xAu + entry_player);
			sprite = print_sprite_letter(sprite, letter_and_colour);
			t11 = sprite_text_x;
			t12 = t11 + 0x10u;
			sprite_text_x = t12;
			t13 = place_suffixes_ADDRESS + (int8_t)((uint32_t)mem_read8(entry) << 1);
			place_suffix = t13 + 1u;
			letter_and_colour = ((uint32_t)PLACE_SUFFIX(t13)->first << 8) | (uint8_t)(0xAu + entry_player);
			sprite = print_sprite_letter(sprite, letter_and_colour);
			t14 = sprite_text_x;
			t15 = t14 + 0x10u;
			sprite_text_x = t15;
			letter_and_colour = ((uint32_t)PLACE_SUFFIX(place_suffix - 0x1u)->second << 8) | (uint8_t)(0xAu + entry_player);
			sprite = print_sprite_letter(sprite, letter_and_colour);
			entry_digit_state = 0u;
			name_entry_player = entry_player_record;
			score_x = NAME_ENTRY_PLAYER(name_entry_player)->score_x;
			sprite_text_x = score_x;
			score_y = NAME_ENTRY_PLAYER(name_entry_player)->score_y;
			sprite_text_y = score_y;
			entry_digit_state++;
			t16 = ((((uint8_t)(entry_score >> 8u) >> 1) >> 1) >> 1) >> 1;
			digit = t16;
			if (t16 == 0u)
			{
				t17 = entry_digit_state;
				entry_digit_state = t17 - 1u;
				if (t17 == 1u)
					digit = 0x10u;
			}
			letter_and_colour = ((uint32_t)(uint8_t)(digit + 0x30u) << 8) | (uint8_t)(0xAu + entry_player);
			sprite = name_entry_print_tall_letter(sprite, letter_and_colour);
			t18 = sprite_text_x;
			t19 = t18 + 0x10u;
			sprite_text_x = t19;
			entry_digit_state++;
			t20 = (uint8_t)(entry_score >> 8u) & 0xFu;
			digit = t20;
			if (t20 == 0u)
			{
				t21 = entry_digit_state;
				entry_digit_state = t21 - 1u;
				if (t21 == 1u)
					digit = 0x10u;
			}
			letter_and_colour = ((uint32_t)(uint8_t)(digit + 0x30u) << 8) | (uint8_t)(0xAu + entry_player);
			sprite = name_entry_print_tall_letter(sprite, letter_and_colour);
			t22 = sprite_text_x;
			t23 = t22 + 0x10u;
			sprite_text_x = t23;
			entry_digit_state++;
			t24 = ((((uint8_t)entry_score >> 1) >> 1) >> 1) >> 1;
			digit = t24;
			if (t24 == 0u)
			{
				t25 = entry_digit_state;
				entry_digit_state = t25 - 1u;
				if (t25 == 1u)
					digit = 0x10u;
			}
			letter_and_colour = ((uint32_t)(uint8_t)(digit + 0x30u) << 8) | (uint8_t)(entry_player + 0xAu);
			sprite = name_entry_print_tall_letter(sprite, letter_and_colour);
			t26 = sprite_text_x;
			t27 = t26 + 0x10u;
			sprite_text_x = t27;
			letter_and_colour = ((uint32_t)(uint8_t)(((uint8_t)entry_score & 0xFu) + 0x30u) << 8) | (uint8_t)(entry_player + 0xAu);
			name_entry_print_tall_letter(sprite, letter_and_colour);
		}
		entry += 4u;
		entry_player++;
	} while (entry_player != 4u);
	initials = 0x3852u;
	entry_player = 4u;
	do
	{
		t28 = initials;
		mem_write8(t28, 0x41u);
		t29 = t28 + 1u;
		initials = t29 + 2u;
		mem_write16(t29, 0x4040u);
		t30 = entry_player;
		entry_player = t30 - 1u;
	} while (t30 != 1u);
	entry_player = 7u;
	maggie_x_offset = 0u;
	object = OBJECT_ADDRESS(8);
	do
	{
		OBJECT(object)->flags = 0x80u;
		OBJECT(object)->attributes = 0x20u;
		OBJECT(object)->kind = 0x11u;
		OBJECT(object)->animation = 1u;
		t31 = 0x30u + maggie_x_offset;
		OBJECT(object)->x = t31;
		OBJECT(object)->y = 0xA0u;
		OBJECT(object)->x_speed = 0x100;
		t32 = maggie_x_offset;
		t33 = t32 + 0x30u;
		maggie_x_offset = t33;
		object += 0x60u;
		t34 = entry_player;
		entry_player = t34 - 1u;
	} while (t34 != 1u);
	carry = 0u;
	io_write16(0x385Eu, 0u);
	t35 = io_read8(0x3840u);
	io_write8(0x3840u, t35 + 1u);
	return carry;
}

/* The name entry: the players type their initials until all are done or the time (1792 frames) runs out,
   the sound stopped near the end. */
uint32_t name_entry_type_initials(void)
{
	uint32_t carry = 0;
	uint8_t all_done = 0, count = 0, timer_high = 0, timer_low = 0;
	uint16_t command = 0, entry = 0, name_entry_player = 0, object = 0;
	uint8_t stack = 0, stack_10002 = 0;
	uint8_t t4 = 0, t5 = 0, t6 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t7 = 0, t8 = 0;

	t1 = io_read16(0x385Eu);
	t2 = t1 + 1u;
	timer_high = (uint8_t)(t2 >> 8);
	timer_low = (uint8_t)t2;
	io_write16(0x385Eu, ((uint32_t)timer_high << 8) | timer_low);
	if ((uint16_t)(((uint32_t)timer_high << 8) | timer_low) == 0x700u)
		return name_entry_save();
	if ((uint16_t)(((uint32_t)timer_high << 8) | timer_low) == 0x6C0u)
	{
		stack = timer_high;
		stack_10002 = timer_low;
		command = 0xFD00u;
		vector_queue_sound_always(command);
		timer_high = stack;
		timer_low = stack_10002;
	}
	if ((int16_t)(((uint32_t)timer_high << 8) | timer_low) <= 0x580)
	{
		object = OBJECT_ADDRESS(8);
		entry_player = 7u;
		do
		{
			t3 = OBJECT(object)->x;
			if ((int16_t)t3 >= 0x180)
				OBJECT(object)->x = 0x30u;
			object += 0x60u;
			t4 = entry_player;
			entry_player = t4 - 1u;
		} while (t4 != 1u);
	}
	entry = 0x3842u;
	all_done = 0x80u;
	count = 4u;
	do
	{
		all_done &= mem_read8(entry);
		entry += 4u;
		t5 = count;
		count = t5 - 1u;
	} while (t5 != 1u);
	if ((int8_t)all_done < 0)
	{
		io_write16(0x385Eu, 0u);
		t6 = io_read8(0x3840u);
		io_write8(0x3840u, t6 + 1u);
		carry = 0u;
		return carry;
	}
	entry = 0x3842u;
	entry_player = 0u;
	sprite_text_x = 0x60u;
	sprite_text_y = 0xD8u;
	do
	{
		name_entry_player = name_entry_player_records[(int8_t)((uint8_t)((uint32_t)entry_player << 1)) / 2];
		t7 = sprite_text_x;
		stack = t7 >> 8;
		stack_10002 = t7;
		if ((int8_t)mem_read8(entry) >= 0)
			entry = name_entry_edit_initials(entry, name_entry_player);
		t8 = (((uint32_t)stack << 8) | stack_10002) + 0x48u;
		sprite_text_x = t8;
		entry += 4u;
		entry_player++;
	} while (entry_player != 4u);
	carry = 0u;
	return carry;
}

/* The name entry: everyone done, waits 256 frames before saving. */
uint32_t name_entry_linger(void)
{
	uint32_t carry = 0;
	uint16_t command = 0, timer = 0;
	uint16_t t1 = 0;

	t1 = io_read16(0x385Eu);
	timer = t1 + 1u;
	io_write16(0x385Eu, timer);
	if (timer == 0x100u)
		return name_entry_save();
	if (timer == 0xC0u)
	{
		command = 0xFD00u;
		vector_queue_sound_always(command);
	}
	carry = 0u;
	return carry;
}

/* The name entry: puts each player who made the table into it with its initials and score (carry: done). */
uint32_t name_entry_save(void)
{
	uint32_t carry = 0;
	uint8_t a = 0, d = 0, player = 0;
	uint16_t name_entry_player = 0, place = 0, ranked = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0, t5 = 0, t6 = 0;
	uint16_t initials = 0, t2 = 0, t3 = 0, score = 0, t4 = 0;

	ranked = 0x3860u;
	stack = 4u;
	do
	{
		t1 = mem_read8(ranked + 1u);
		if ((int8_t)t1 >= 0)
		{
			player = mem_read8(ranked);
			new_high_score_player = player;
			name_entry_player = name_entry_player_records[(int8_t)((uint8_t)((uint32_t)player << 1)) / 2];
			initials = NAME_ENTRY_PLAYER(name_entry_player)->initials;
			t2 = initials;
			t3 = mem_read16(t2);
			new_high_score = t3;
			a = mem_read8(t2 + 2u);
			new_high_score_initial_3 = a;
			score = NAME_ENTRY_PLAYER(name_entry_player)->score;
			t4 = mem_read16(score);
			d = (uint8_t)t4;
			new_high_score_points = ((uint32_t)(t4 >> 8) << 8) | (d & 0xFFu);
			t5 = mem_read8(ranked + 1u);
			place = (d & 0xFFu) | ((uint32_t)t5 << 8);
			vector_insert_high_score(place);
		}
		ranked += 2u;
		t6 = stack;
		stack = t6 - 1u;
	} while (t6 != 1u);
	carry = 1u;
	return carry;
}

/* The name entry: orders the four players by their scores, best first. */
void name_entry_rank_players(void)
{
	uint8_t a = 0, player = 0;
	uint16_t other = 0, ranked = 0, score_addresses = 0;
	uint16_t t1 = 0, t2 = 0;

	ranked = 0x3860u;
	io_write8(0x3860u, 0u);
	io_write8(0x3862u, 1u);
	io_write8(0x3864u, 2u);
	io_write8(0x3866u, 3u);
	score_addresses = player_score_addresses_ADDRESS;
	rank_place = 0u;
	do
	{
		other = ranked + 2u;
		a = rank_place + 1u;
		if (a != 4u)
		{
			rank_other_place = a;
			do
			{
				t1 = mem_read16(SCORE_ADDRESS(score_addresses + (int8_t)((uint32_t)mem_read8(other) << 1)));
				rank_other_score = t1;
				t2 = mem_read16(SCORE_ADDRESS(score_addresses + (int8_t)((uint32_t)mem_read8(ranked) << 1)));
				if (t2 <= rank_other_score)
				{
					player = mem_read8(ranked);
					mem_write8(ranked, mem_read8(other));
					mem_write8(other, player);
				}
				other += 2u;
				rank_other_place++;
			} while (rank_other_place != 4u);
		}
		ranked += 2u;
		rank_place++;
	} while (rank_place != 4u);
}

/* The name entry: one player's initials: right and left change the letter (held, they repeat), a button
   takes it and moves on; draws them with the current letter pulsing. */
uint16_t name_entry_edit_initials(uint16_t entry, uint16_t name_entry_player)
{
	bool L_022382 = false, L_0223B2 = false;
	uint8_t control = 0, initial = 0, letter = 0;
	uint16_t command = 0, initials = 0, letter_and_colour = 0, sprite = 0;
	uint8_t stack = 0, stack_2 = 0;
	uint8_t t1 = 0, t3 = 0, t5 = 0, t6 = 0, t8 = 0, t11 = 0;
	uint16_t repeat_wait = 0, repeat_wait_2 = 0, controls_pressed = 0, repeat_wait_3 = 0, controls_held = 0, repeat_wait_4 = 0, initials_2 = 0, t2 = 0, controls_pressed_2 = 0, repeat_wait_5 = 0, controls_held_2 = 0, repeat_wait_6 = 0, initials_3 = 0, t4 = 0, controls_pressed_3 = 0, initials_4 = 0, initials_5 = 0, t7 = 0, t9 = 0, t10 = 0;

	repeat_wait = NAME_ENTRY_PLAYER(name_entry_player)->repeat_wait;
	if (mem_read8(repeat_wait) != 0u)
	{
		repeat_wait_2 = NAME_ENTRY_PLAYER(name_entry_player)->repeat_wait;
		mem_write8(repeat_wait_2, mem_read8(repeat_wait_2) - 1u);
	}
	controls_pressed = NAME_ENTRY_PLAYER(name_entry_player)->controls_pressed;
	if ((mem_read8(controls_pressed) & 2u) != 0u)
		L_022382 = true;
	else
	{
		repeat_wait_3 = NAME_ENTRY_PLAYER(name_entry_player)->repeat_wait;
		if (mem_read8(repeat_wait_3) == 0u)
		{
			controls_held = NAME_ENTRY_PLAYER(name_entry_player)->controls_held;
			L_022382 = (mem_read8(controls_held) & 2u) != 0u;
		}
	}
	if (L_022382)
	{
		repeat_wait_4 = NAME_ENTRY_PLAYER(name_entry_player)->repeat_wait;
		mem_write8(repeat_wait_4, 0xFu);
		command = 0x4500u;
		vector_queue_sound_always(command);
		t1 = mem_read8(entry + 3u);
		initial = t1;
		initials_2 = NAME_ENTRY_PLAYER(name_entry_player)->initials;
		initials = initials_2;
		t2 = initials + (int8_t)initial;
		mem_write8(t2, mem_read8(t2) + 1u);
		letter = mem_read8(initials + (int8_t)initial);
		if (letter > 0x62u)
			letter = 0x40u;
		mem_write8(initials + (int8_t)initial, letter);
	}
	controls_pressed_2 = NAME_ENTRY_PLAYER(name_entry_player)->controls_pressed;
	if ((mem_read8(controls_pressed_2) & 1u) != 0u)
		L_0223B2 = true;
	else
	{
		repeat_wait_5 = NAME_ENTRY_PLAYER(name_entry_player)->repeat_wait;
		if (mem_read8(repeat_wait_5) == 0u)
		{
			controls_held_2 = NAME_ENTRY_PLAYER(name_entry_player)->controls_held;
			L_0223B2 = (mem_read8(controls_held_2) & 1u) != 0u;
		}
	}
	if (L_0223B2)
	{
		repeat_wait_6 = NAME_ENTRY_PLAYER(name_entry_player)->repeat_wait;
		mem_write8(repeat_wait_6, 0xFu);
		command = 0x4500u;
		vector_queue_sound_always(command);
		t3 = mem_read8(entry + 3u);
		initial = t3;
		initials_3 = NAME_ENTRY_PLAYER(name_entry_player)->initials;
		initials = initials_3;
		t4 = initials + (int8_t)initial;
		mem_write8(t4, mem_read8(t4) - 1u);
		letter = mem_read8(initials + (int8_t)initial);
		if (letter < 0x40u)
			letter = 0x62u;
		mem_write8(initials + (int8_t)initial, letter);
	}
	controls_pressed_3 = NAME_ENTRY_PLAYER(name_entry_player)->controls_pressed;
	if ((mem_read8(controls_pressed_3) & 0x30u) != 0u)
	{
		command = 0x4400u;
		vector_queue_sound_always(command);
		t5 = mem_read8(entry + 3u);
		initial = t5;
		if (initial == 2u)
			io_write8(entry, 0xFFu);
		else
		{
			initial++;
			initials_4 = NAME_ENTRY_PLAYER(name_entry_player)->initials;
			mem_write8(initials_4 + (int8_t)initial, 0x41u);
			mem_write8(entry + 3u, initial);
		}
	}
	entry_player_record = name_entry_player;
	initials_5 = NAME_ENTRY_PLAYER(name_entry_player)->initials;
	initials = initials_5;
	sprite = NAME_ENTRY_PLAYER(name_entry_player)->sprites + 0x80u;
	t6 = mem_read8(entry + 3u);
	initials_left = t6 + 1u;
	do
	{
		stack_2 = sprite >> 8;
		stack = (uint8_t)sprite;
		t7 = initials;
		initials = t7 + 1u;
		t8 = io_read8(entry_player_record + 0x18u);
		sprite = ((uint32_t)stack_2 << 8) | stack;
		letter_and_colour = ((uint32_t)mem_read8(t7) << 8) | (uint8_t)(t8 + 0xAu);
		sprite = print_sprite_letter(sprite, letter_and_colour);
		if (mem_read8(entry) != 0xFFu && initials_left == 1u)
		{
			control = board_control | 2u;
			board_control = control;
			io_write8(0x1FC2u, control);
			stack_2 = entry >> 8;
			stack = (uint8_t)entry;
			mem_write8(sprite - 7u, name_entry_cursor_zooms[((uint8_t)frame_count & 0x1Fu) >> 1]);
			entry = ((uint32_t)stack_2 << 8) | stack;
			control = board_control & ~3u;
			board_control = control;
			io_write8(0x1FC2u, control);
		}
		t9 = sprite_text_x;
		t10 = t9 + 0x10u;
		sprite_text_x = t10;
		t11 = initials_left;
		initials_left = t11 - 1u;
	} while (t11 != 1u);
	return entry;
}

/* The name entry: prints a letter as a taller sprite (the scores' digits). */
uint16_t name_entry_print_tall_letter(uint16_t sprite, uint16_t letter_and_colour)
{
	uint8_t control = 0;

	sprite = print_sprite_letter(sprite, letter_and_colour);
	control = board_control | 2u;
	board_control = control;
	io_write8(0x1FC2u, control);
	mem_write16(sprite - 8u, 0x30u);
	control = board_control & ~3u;
	board_control = control;
	io_write8(0x1FC2u, control);
	return sprite;
}

/* The name entry: draws one of the pictures of tiles (a box or a player's face) in a player's column, or
   blanks it. */
void name_entry_draw_picture(uint16_t column_and_picture)
{
	uint8_t colour = 0, colour_2 = 0, column = 0;
	uint16_t picture = 0, tile = 0;
	uint8_t stack_E = 0, stack_F = 0, stack = 0, stack_11 = 0, stack_12 = 0, stack_13 = 0, stack_14 = 0, stack_15 = 0, stack_16 = 0;
	uint8_t t7 = 0, t8 = 0;
	uint16_t column_2 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t9 = 0;

	column = (uint8_t)(column_and_picture >> 8);
	stack_16 = column;
	stack = column & 0x7Fu;
	stack_F = (uint8_t)column_and_picture;
	column_2 = (((uint32_t)NAME_ENTRY_COLUMN(name_entry_columns_ADDRESS + (int8_t)((uint32_t)stack << 1))->column << 8u) | NAME_ENTRY_COLUMN(name_entry_columns_ADDRESS + (int8_t)((uint32_t)stack << 1))->palette);
	stack_11 = column_2 >> 8;
	stack_13 = column_2;
	picture = name_entry_pictures[(int8_t)((uint8_t)((uint32_t)stack_F << 1)) / 2];
	do
	{
		t1 = picture;
		tile = mem_read16(t1) + (int8_t)stack_11;
		t2 = t1 + 2u;
		stack_15 = mem_read8(t2);
		t3 = t2 + 1u;
		stack_14 = mem_read8(t3);
		t4 = t3 + 1u;
		picture = t4 + 1u;
		colour = mem_read8(t4) | stack_13;
		if ((int8_t)stack_16 < 0)
			colour = 0u;
		stack_E = colour;
		do
		{
			stack_12 = stack_15;
			colour_2 = stack_E;
			do
			{
				mem_write8(tile - 0x2000u, colour_2);
				t5 = picture;
				picture = t5 + 1u;
				t6 = tile;
				tile = t6 + 1u;
				mem_write8(t6, mem_read8(t5));
				t7 = stack_12;
				stack_12 = t7 - 1u;
			} while (t7 != 1u);
			tile += (int8_t)(0x40u - stack_15);
			t8 = stack_14;
			stack_14 = t8 - 1u;
		} while (t8 != 1u);
		t9 = picture;
		picture = t9 + 1u;
	} while (mem_read8(t9) == 0u);
}

/* The attract's high score table: puts its heading, then clears the objects' sprites and sets the page's
   time (192 frames). */
void high_scores_set_up(void)
{
	OBJECT(OBJECT_ADDRESS(14))->flags = 0x80u;
	OBJECT(OBJECT_ADDRESS(14))->animation_flags = 0x40u;
	OBJECT(OBJECT_ADDRESS(14))->kind = 0xFu;
	OBJECT(OBJECT_ADDRESS(14))->animation = 0x9Fu;
	OBJECT(OBJECT_ADDRESS(14))->x = 0x138u;
	OBJECT(OBJECT_ADDRESS(14))->y = 0x98u;
	high_scores_clear_sprites();
}

/* The attract's high score table: clears the objects' sprites and sets the page's time (192 frames). */
void high_scores_clear_sprites(void)
{
	uint16_t object = 0, object_count = 0;

	object = OBJECT_ADDRESS(0);
	object_count = 0x800u;
	reserve_objects_for_sprites(object, object_count);
	scene_timer = (scene_timer & 0xFFu) | 0xC000u;
	game_step++;
}

/* The attract's high score table: shows places 1 to 5; when its time is up, starts the wavy exit with
   its sound (0700). */
void high_scores_show_first(void)
{
	uint32_t carry = 0;
	uint16_t command = 0, entry = 0, first_place = 0;
	uint8_t t1 = 0;

	OBJECT(OBJECT_ADDRESS(14))->animation_flags = 0x40u;
	entry = high_scores_ADDRESS;
	first_place = 0x100u;
	high_scores_print_entries(entry, first_place);
	t1 = (uint8_t)(scene_timer >> 8u);
	scene_timer = (scene_timer & 0xFFu) | ((t1 - 1u & 0xFFu) << 8u);
	if (t1 != 1u)
		return;
	io_write8(0x1C80u, 3u);
	scene_timer = (scene_timer & 0xFFu) | 0x8000u;
	command = 0x700u;
	carry = vector_queue_sound(command);
	game_step++;
}

/* The attract's high score table: waves the page line by line and wobbles its sprites' height, then
   clears them. */
void high_scores_wave_out(void)
{
	uint32_t carry = 0;
	uint8_t control = 0, height = 0, wave = 0;
	uint16_t command = 0, ignored16 = 0, ignored16_2 = 0, line_scroll = 0, sprite = 0;
	uint8_t t1 = 0, t2 = 0, t6 = 0;
	uint16_t t3 = 0, t4 = 0, t5 = 0;

	t1 = (uint8_t)(scene_timer >> 8u);
	scene_timer = (scene_timer & 0xFFu) | ((t1 - 1u & 0xFFu) << 8u);
	if (t1 == 1u)
	{
		command = 0u;
		carry = vector_queue_sound(command);
		t2 = io_read8(0x1C80u);
		io_write8(0x1C80u, 0u);
		vector_clear_sprites(&ignored16, &ignored16_2);
		game_step++;
		return;
	}
	line_scroll = 0x1A00u;
	wave_lines_left = 0u;
	table_wave_offset = 0xDu * (uint8_t)frame_count;
	do
	{
		t3 = 0xDu * table_wave_offset;
		t4 = t3 - 0x7001u;
		wave = (uint8_t)t4;
		t5 = line_scroll;
		line_scroll = t5 + 2u;
		mem_write16(t5, ((uint32_t)(t4 >> 8) << 8) | wave);
		table_wave_offset = wave;
		t6 = wave_lines_left;
		wave_lines_left = t6 - 1u;
	} while (t6 != 1u);
	table_wave_offset = 0xDu * (uint8_t)frame_count;
	control = board_control | 2u;
	board_control = control;
	io_write8(0x1FC2u, control);
	sprite = 0x2000u;
	while (mem_read8(sprite) != 0u)
	{
		height = 0xDu * table_wave_offset;
		if (height < 0x30u)
			height = 0x30u;
		mem_write8(sprite + 0xBu, height);
		sprite += 0x10u;
	}
	control = board_control & ~3u;
	board_control = control;
	io_write8(0x1FC2u, control);
}

/* The attract's high score table: shows places 6 to 10; when its time is up, starts the wavy exit. */
void high_scores_show_second(void)
{
	uint32_t carry = 0;
	uint16_t command = 0, entry = 0, first_place = 0;
	uint8_t t1 = 0;

	OBJECT(OBJECT_ADDRESS(14))->animation_flags = 0x40u;
	entry = high_scores_ADDRESS + 0x28u;
	first_place = 0x600u;
	high_scores_print_entries(entry, first_place);
	t1 = (uint8_t)(scene_timer >> 8u);
	scene_timer = (scene_timer & 0xFFu) | ((t1 - 1u & 0xFFu) << 8u);
	if (t1 != 1u)
		return;
	io_write8(0x1C80u, 3u);
	scene_timer = (scene_timer & 0xFFu) | 0x8000u;
	command = 0x700u;
	carry = vector_queue_sound(command);
	game_step++;
}

/* The attract's high score table: fades the colours out. */
void high_scores_fade_out(uint16_t palette_job)
{
	uint16_t ignored16 = 0, request = 0;

	palette_request_kind = 3u;
	request = 0u;
	vector_palette_request(request, &ignored16, &palette_job);
	vector_clear_layer_a();
	scene_timer = (scene_timer & 0xFFu) | 0x4000u;
	game_step++;
}

/* The attract's high score table: after the fade, clears the objects and goes on to the attract's next
   part. */
void high_scores_end(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0;
	uint8_t t1 = 0;

	OBJECT(OBJECT_ADDRESS(14))->animation_flags = 0x40u;
	t1 = (uint8_t)(scene_timer >> 8u);
	scene_timer = (scene_timer & 0xFFu) | ((t1 - 1u & 0xFFu) << 8u);
	if (t1 != 1u)
		return;
	vector_clear_objects(&ignored16, &ignored16_2);
	mode_phase++;
	game_step = 0u;
	step_phase = 0u;
	step_subphase = 0u;
	step_countdown = 0u;
}

/* The high score table: prints five entries, numbered from the given place: place, initials, score and
   the player's little animated face. */
void high_scores_print_entries(uint16_t entry, uint16_t first_place)
{
	uint32_t carry = 0, half_carry = 0;
	uint8_t icon_frame = 0, place = 0, tens = 0;
	uint16_t entry_icon = 0, icons = 0, letter_and_colour = 0, sprite = 0;
	uint8_t stack = 0, stack_2 = 0, stack_3 = 0, stack_4 = 0, stack_5 = 0;
	uint8_t t1 = 0, t7 = 0, t15 = 0, t18 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0, t16 = 0, t17 = 0;

	sprite = 0x2000u;
	table_place = first_place >> 8;
	table_entries_left = 5u;
	sprite_text_x = 0x88u;
	sprite_text_y = 0x130u;
	do
	{
		stack_2 = entry >> 8;
		stack = (uint8_t)entry;
		t1 = (((table_place >> 1) >> 1) >> 1) >> 1;
		tens = t1;
		if (t1 != 0u)
		{
			letter_and_colour = (uint32_t)(uint8_t)(tens + 0x30u) << 8;
			sprite = print_sprite_letter(sprite, letter_and_colour);
		}
		t2 = sprite_text_x;
		t3 = t2 + 0x10u;
		sprite_text_x = t3;
		letter_and_colour = (uint32_t)(uint8_t)((table_place & 0xFu) + 0x30u) << 8;
		sprite = print_sprite_letter(sprite, letter_and_colour);
		table_characters_left = 3u;
		sprite_text_x = 0xB8u;
		do
		{
			t4 = entry;
			entry = t4 + 1u;
			letter_and_colour = (uint32_t)mem_read8(t4) << 8;
			sprite = print_sprite_letter(sprite, letter_and_colour);
			t5 = sprite_text_x;
			t6 = t5 + 0x10u;
			sprite_text_x = t6;
			t7 = table_characters_left;
			table_characters_left = t7 - 1u;
		} while (t7 != 1u);
		sprite_text_x = 0xE0u;
		table_characters_left = 4u;
		t8 = entry;
		entry_icon = t8 + 2u;
		t9 = mem_read16(t8);
		stack_3 = t9;
		stack_4 = t9 >> 8;
		table_digit_shown = 0u;
		do
		{
			if (table_digit_shown != 0u || table_characters_left == 1u || (stack_4 & ~0xFu) != 0u)
			{
				letter_and_colour = (uint32_t)(uint8_t)(((((stack_4 >> 1) >> 1) >> 1) >> 1) + 0x30u) << 8;
				sprite = print_sprite_letter(sprite, letter_and_colour);
				table_digit_shown++;
			}
			t10 = ((uint32_t)stack_4 << 8) | stack_3;
			t11 = (uint32_t)t10 << 4;
			t12 = t11;
			stack_4 = t12 >> 8;
			stack_3 = t12;
			t13 = sprite_text_x;
			t14 = t13 + 0x10u;
			sprite_text_x = t14;
			t15 = table_characters_left;
			table_characters_left = t15 - 1u;
		} while (t15 != 1u);
		sprite_text_x = 0x128u;
		stack_3 = mem_read8(entry_icon);
		icons = high_score_icons_ADDRESS;
		stack_5 = sprite >> 8;
		stack_4 = (uint8_t)sprite;
		icon_frame = ((((uint8_t)(((uint16_t)(((uint32_t)stack_5 << 8) | stack_4) >> 3) + (uint8_t)frame_count) >> 1) >> 1) >> 1) >> 1;
		if ((icon_frame & 4u) == 0u)
			icon_frame = 0u;
		letter_and_colour = (uint32_t)(uint8_t)((icon_frame & 3u) + HIGH_SCORE_ICON(icons + (int8_t)stack_3)) << 8;
		sprite = print_sprite_letter(sprite, letter_and_colour);
		sprite_text_x = 0x88u;
		t16 = sprite_text_y;
		t17 = t16 - 0x18u;
		sprite_text_y = t17;
		place = table_place;
		half_carry = ((uint8_t)(place ^ 1u ^ (place + 1u)) >> 4) & 1u;
		carry = (uint8_t)(place + 1u) < place;
		table_place = konami_daa((uint8_t)(place + 1u), half_carry, carry);
		entry = (((uint32_t)stack_2 << 8) | stack) + 8u;
		t18 = table_entries_left;
		table_entries_left = t18 - 1u;
	} while (t18 != 1u);
}

/* Puts a letter as a sprite of the given colour at the current place, into the next sprite of the sprite
   RAM. */
uint16_t print_sprite_letter(uint16_t sprite, uint16_t letter_and_colour)
{
	uint16_t colour = 0;
	uint8_t stack = 0;

	stack = (uint8_t)letter_and_colour;
	sprite_text_code = ((uint32_t)sprite_font_code_high[0] << 8) | sprite_font_codes[(int8_t)((uint8_t)((letter_and_colour >> 8) - 0x30u))];
	colour = stack;
	sprite = put_sprite(sprite, colour);
	return sprite;
}

/* Unused: would put a sprite code taken from a table, colour 0F, into the next sprite. */
void unused_print_sprite_code(uint16_t x, uint16_t sprite)
{
	uint16_t colour = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + (int8_t)((uint32_t)sprite_code_index << 1));
	sprite_text_code = t1;
	colour = 0xFu;
	put_sprite(sprite, colour);
}

/* Writes a sprite straight into the sprite RAM: the code, the current place, the given colour, at normal
   size; then moves on to the next sprite. */
uint16_t put_sprite(uint16_t sprite, uint16_t colour)
{
	uint8_t control = 0;
	uint8_t stack = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	stack = colour >> 8;
	control = board_control | 2u;
	board_control = control;
	io_write8(0x1FC2u, control);
	io_write8(sprite, stack | 0x80u);
	mem_write16(sprite + 0xCu, colour | 0x20u);
	t1 = sprite_text_code;
	mem_write16(sprite + 2u, t1);
	t2 = sprite_text_x;
	mem_write16(sprite + 6u, t2);
	t3 = sprite_text_y;
	mem_write16(sprite + 4u, t3);
	mem_write16(sprite + 8u, 0x40u);
	mem_write16(sprite + 0xAu, 0x40u);
	sprite += 0x10u;
	control = board_control & ~3u;
	board_control = control;
	io_write8(0x1FC2u, control);
	return sprite;
}
