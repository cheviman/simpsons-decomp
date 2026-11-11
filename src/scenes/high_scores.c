/**
 *    Name:        scenes/high_scores.c
 *    Description: the bank's jump table, then the name entry and the attract's high score table
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
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
	uint8_t entry_phase = 0;

	control = board_control & ~3u;
	board_control = control;
	io_write8(board_control_register, control);
	entry_phase = io_read8(name_entry_state);
	switch ((int8_t)(uint8_t)((uint32_t)entry_phase << 1))
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

/* The name entry: ranks the players by score, draws each one who made the table a column with its face,
   place and score, starts its initials at the letter A, and sets Maggies walking along the bottom. */
uint32_t name_entry_set_up(void)
{
	uint32_t carry = 0, half_carry = 0;
	uint8_t digit = 0, place = 0, place_number = 0, player_offset = 0, tens = 0;
	uint16_t column_and_picture = 0, entry = 0, entry_2 = 0, high_score_place = 0, initials = 0, letter_and_colour = 0, name_entry_player = 0, object = 0, object_count = 0, place_suffix = 0, ranked = 0, sprite = 0;
	uint8_t place_tens = 0, score_digit = 0, leading_check = 0, score_digit_2 = 0, leading_check_2 = 0, score_digit_3 = 0, leading_check_3 = 0, players_left = 0, maggies_left = 0, old_entry_phase = 0;
	uint16_t ranking_at = 0, score = 0, player_score = 0, no_place_at = 0, no_place_entry = 0, sprites = 0, place_at = 0, place_entry = 0, sprites_2 = 0, score_2 = 0, entry_player_score = 0, place_x = 0, place_y = 0, tens_x = 0, x_after_tens = 0, units_x = 0, x_after_units = 0, suffix = 0, suffix_x = 0, x_after_suffix = 0, score_x = 0, score_y = 0, digit_1_x = 0, x_after_digit = 0, digit_2_x = 0, x_after_digit_2 = 0, digit_3_x = 0, x_after_digit_3 = 0, initial_at = 0, other_initials_at = 0, maggie_x = 0, maggie_offset = 0, next_maggie_offset = 0;

	object = OBJECT_ADDRESS(0);
	object_count = 0x800u;
	reserve_objects_for_sprites(object, object_count);
	name_entry_rank_players();
	players_ranked = 0u;
	ranked = name_entry_ranking;
	do
	{
		ranking_at = ranked;
		ranked = ranking_at + 1u;
		player_offset = (uint32_t)mem_read8(ranking_at) << 1;
		name_entry_player = TABLE16(name_entry_player_records, (int8_t)player_offset);
		entry_2 = name_entry_records + (int8_t)((uint32_t)player_offset << 1);
		score = NAME_ENTRY_PLAYER(name_entry_player)->score;
		player_score = mem_read16(score);
		high_score_place = player_score;
		high_score_place = vector_high_score_rank(high_score_place);
		place = (uint8_t)(high_score_place >> 8);
		place += players_ranked;
		if (place > 9u)
		{
			no_place_at = ranked;
			ranked = no_place_at + 1u;
			mem_write8(no_place_at, 0xFFu);
			no_place_entry = entry_2;
			io_write8(no_place_entry, 0xFFu);
			sprites = NAME_ENTRY_PLAYER(name_entry_player)->sprites;
			mem_write16(no_place_entry + 1u, sprites);
		}
		else
		{
			place_at = ranked;
			ranked = place_at + 1u;
			mem_write8(place_at, place);
			place_entry = entry_2;
			io_write8(place_entry, place);
			sprites_2 = NAME_ENTRY_PLAYER(name_entry_player)->sprites;
			mem_write16(place_entry + 1u, sprites_2);
		}
		players_ranked++;
	} while (players_ranked != 4u);
	entry = name_entry_records;
	entry_player = 0u;
	do
	{
		name_entry_player = name_entry_player_records[(int8_t)((uint8_t)((uint32_t)entry_player << 1)) / 2];
		entry_player_record = name_entry_player;
		sprite = NAME_ENTRY_PLAYER(name_entry_player)->sprites;
		score_2 = NAME_ENTRY_PLAYER(name_entry_player)->score;
		entry_player_score = mem_read16(score_2);
		entry_score = entry_player_score;
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
			place_tens = (((place_number >> 1) >> 1) >> 1) >> 1;
			tens = place_tens;
			if (place_tens != 0u)
			{
				letter_and_colour = ((uint32_t)(uint8_t)(tens + 0x30u) << 8) | (uint8_t)(0xAu + entry_player);
				sprite = print_sprite_letter(sprite, letter_and_colour);
			}
			tens_x = sprite_text_x;
			x_after_tens = tens_x + 0x10u;
			sprite_text_x = x_after_tens;
			letter_and_colour = ((uint32_t)(uint8_t)((entry_digit_state & 0xFu) + 0x30u) << 8) | (uint8_t)(0xAu + entry_player);
			sprite = print_sprite_letter(sprite, letter_and_colour);
			units_x = sprite_text_x;
			x_after_units = units_x + 0x10u;
			sprite_text_x = x_after_units;
			suffix = place_suffixes_ADDRESS + (int8_t)((uint32_t)mem_read8(entry) << 1);
			place_suffix = suffix + 1u;
			letter_and_colour = ((uint32_t)PLACE_SUFFIX(suffix)->first << 8) | (uint8_t)(0xAu + entry_player);
			sprite = print_sprite_letter(sprite, letter_and_colour);
			suffix_x = sprite_text_x;
			x_after_suffix = suffix_x + 0x10u;
			sprite_text_x = x_after_suffix;
			letter_and_colour = ((uint32_t)PLACE_SUFFIX(place_suffix - 0x1u)->second << 8) | (uint8_t)(0xAu + entry_player);
			sprite = print_sprite_letter(sprite, letter_and_colour);
			entry_digit_state = 0u;
			name_entry_player = entry_player_record;
			score_x = NAME_ENTRY_PLAYER(name_entry_player)->score_x;
			sprite_text_x = score_x;
			score_y = NAME_ENTRY_PLAYER(name_entry_player)->score_y;
			sprite_text_y = score_y;
			entry_digit_state++;
			score_digit = ((((uint8_t)(entry_score >> 8u) >> 1) >> 1) >> 1) >> 1;
			digit = score_digit;
			if (score_digit == 0u)
			{
				leading_check = entry_digit_state;
				entry_digit_state = leading_check - 1u;
				if (leading_check == 1u)
					digit = 0x10u;
			}
			letter_and_colour = ((uint32_t)(uint8_t)(digit + 0x30u) << 8) | (uint8_t)(0xAu + entry_player);
			sprite = name_entry_print_tall_letter(sprite, letter_and_colour);
			digit_1_x = sprite_text_x;
			x_after_digit = digit_1_x + 0x10u;
			sprite_text_x = x_after_digit;
			entry_digit_state++;
			score_digit_2 = (uint8_t)(entry_score >> 8u) & 0xFu;
			digit = score_digit_2;
			if (score_digit_2 == 0u)
			{
				leading_check_2 = entry_digit_state;
				entry_digit_state = leading_check_2 - 1u;
				if (leading_check_2 == 1u)
					digit = 0x10u;
			}
			letter_and_colour = ((uint32_t)(uint8_t)(digit + 0x30u) << 8) | (uint8_t)(0xAu + entry_player);
			sprite = name_entry_print_tall_letter(sprite, letter_and_colour);
			digit_2_x = sprite_text_x;
			x_after_digit_2 = digit_2_x + 0x10u;
			sprite_text_x = x_after_digit_2;
			entry_digit_state++;
			score_digit_3 = ((((uint8_t)entry_score >> 1) >> 1) >> 1) >> 1;
			digit = score_digit_3;
			if (score_digit_3 == 0u)
			{
				leading_check_3 = entry_digit_state;
				entry_digit_state = leading_check_3 - 1u;
				if (leading_check_3 == 1u)
					digit = 0x10u;
			}
			letter_and_colour = ((uint32_t)(uint8_t)(digit + 0x30u) << 8) | (uint8_t)(entry_player + 0xAu);
			sprite = name_entry_print_tall_letter(sprite, letter_and_colour);
			digit_3_x = sprite_text_x;
			x_after_digit_3 = digit_3_x + 0x10u;
			sprite_text_x = x_after_digit_3;
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
		initial_at = initials;
		mem_write8(initial_at, 0x41u);
		other_initials_at = initial_at + 1u;
		initials = other_initials_at + 2u;
		mem_write16(other_initials_at, 0x4040u);
		players_left = entry_player;
		entry_player = players_left - 1u;
	} while (players_left != 1u);
	entry_player = 7u;
	maggie_x_offset = 0u;
	object = OBJECT_ADDRESS(8);
	do
	{
		OBJECT(object)->flags = 0x80u;
		OBJECT(object)->attributes = 0x20u;
		OBJECT(object)->kind = 0x11u;
		OBJECT(object)->animation = 1u;
		maggie_x = 0x30u + maggie_x_offset;
		OBJECT(object)->x = maggie_x;
		OBJECT(object)->y = 0xA0u;
		OBJECT(object)->x_speed = 0x100;
		maggie_offset = maggie_x_offset;
		next_maggie_offset = maggie_offset + 0x30u;
		maggie_x_offset = next_maggie_offset;
		object += 0x60u;
		maggies_left = entry_player;
		entry_player = maggies_left - 1u;
	} while (maggies_left != 1u);
	carry = 0u;
	io_write16(name_entry_time, 0u);
	old_entry_phase = io_read8(name_entry_state);
	io_write8(name_entry_state, old_entry_phase + 1u);
	return carry;
}

/* The name entry: the players type their initials until all are done or the time (1792 frames) runs out,
   the sound stopped near the end. */
uint32_t name_entry_type_initials(void)
{
	uint32_t done = 0;
	uint8_t all_done = 0, count = 0, timer_high = 0, timer_low = 0;
	uint16_t command = 0, entry = 0, name_entry_player = 0, object = 0;
	uint8_t kept_word_high = 0, kept_word_low = 0;
	uint8_t maggies_left = 0, entries_left = 0, old_entry_phase = 0;
	uint16_t entry_time = 0, new_entry_time = 0, maggie_x = 0, player_text_x = 0, next_player_text_x = 0;

	entry_time = io_read16(name_entry_time);
	new_entry_time = entry_time + 1u;
	timer_high = (uint8_t)(new_entry_time >> 8);
	timer_low = (uint8_t)new_entry_time;
	io_write16(name_entry_time, ((uint32_t)timer_high << 8) | timer_low);
	if ((uint16_t)(((uint32_t)timer_high << 8) | timer_low) == 0x700u)
		return name_entry_save();
	if ((uint16_t)(((uint32_t)timer_high << 8) | timer_low) == 0x6C0u)
	{
		kept_word_high = timer_high;
		kept_word_low = timer_low;
		command = 0xFD00u;
		vector_queue_sound_always(command);
		timer_high = kept_word_high;
		timer_low = kept_word_low;
	}
	if ((int16_t)(((uint32_t)timer_high << 8) | timer_low) <= 0x580)
	{
		object = OBJECT_ADDRESS(8);
		entry_player = 7u;
		do
		{
			maggie_x = OBJECT(object)->x;
			if ((int16_t)maggie_x >= 0x180)
				OBJECT(object)->x = 0x30u;
			object += 0x60u;
			maggies_left = entry_player;
			entry_player = maggies_left - 1u;
		} while (maggies_left != 1u);
	}
	entry = name_entry_records;
	all_done = 0x80u;
	count = 4u;
	do
	{
		all_done &= mem_read8(entry);
		entry += 4u;
		entries_left = count;
		count = entries_left - 1u;
	} while (entries_left != 1u);
	if ((int8_t)all_done < 0)
	{
		io_write16(name_entry_time, 0u);
		old_entry_phase = io_read8(name_entry_state);
		io_write8(name_entry_state, old_entry_phase + 1u);
		done = 0u;
		return done;
	}
	entry = name_entry_records;
	entry_player = 0u;
	sprite_text_x = 0x60u;
	sprite_text_y = 0xD8u;
	do
	{
		name_entry_player = name_entry_player_records[(int8_t)((uint8_t)((uint32_t)entry_player << 1)) / 2];
		player_text_x = sprite_text_x;
		kept_word_high = player_text_x >> 8;
		kept_word_low = player_text_x;
		if ((int8_t)mem_read8(entry) >= 0)
			entry = name_entry_edit_initials(entry, name_entry_player);
		next_player_text_x = (((uint32_t)kept_word_high << 8) | kept_word_low) + 0x48u;
		sprite_text_x = next_player_text_x;
		entry += 4u;
		entry_player++;
	} while (entry_player != 4u);
	done = 0u;
	return done;
}

/* The name entry: everyone done, waits 256 frames before saving. */
uint32_t name_entry_linger(void)
{
	uint32_t done = 0;
	uint16_t command = 0, timer = 0;
	uint16_t entry_time = 0;

	entry_time = io_read16(name_entry_time);
	timer = entry_time + 1u;
	io_write16(name_entry_time, timer);
	if (timer == 0x100u)
		return name_entry_save();
	if (timer == 0xC0u)
	{
		command = 0xFD00u;
		vector_queue_sound_always(command);
	}
	done = 0u;
	return done;
}

/* The name entry: puts each player who made the table into it with its initials and score (carry: done). */
uint32_t name_entry_save(void)
{
	uint32_t done = 0;
	uint8_t player = 0, score_low = 0, third_initial = 0;
	uint16_t name_entry_player = 0, place = 0, ranked = 0;
	uint8_t entries_to_save = 0;
	uint8_t ranked_place = 0, insert_place = 0, players_left = 0;
	uint16_t initials = 0, initials_at = 0, first_initials = 0, score = 0, player_score = 0;

	ranked = name_entry_ranking;
	entries_to_save = 4u;
	do
	{
		ranked_place = mem_read8(ranked + 1u);
		if ((int8_t)ranked_place >= 0)
		{
			player = mem_read8(ranked);
			new_high_score_player = player;
			name_entry_player = name_entry_player_records[(int8_t)((uint8_t)((uint32_t)player << 1)) / 2];
			initials = NAME_ENTRY_PLAYER(name_entry_player)->initials;
			initials_at = initials;
			first_initials = mem_read16(initials_at);
			new_high_score = first_initials;
			third_initial = mem_read8(initials_at + 2u);
			new_high_score_initial_3 = third_initial;
			score = NAME_ENTRY_PLAYER(name_entry_player)->score;
			player_score = mem_read16(score);
			score_low = (uint8_t)player_score;
			new_high_score_points = ((uint32_t)(player_score >> 8) << 8) | (score_low & 0xFFu);
			insert_place = mem_read8(ranked + 1u);
			place = (score_low & 0xFFu) | ((uint32_t)insert_place << 8);
			vector_insert_high_score(place);
		}
		ranked += 2u;
		players_left = entries_to_save;
		entries_to_save = players_left - 1u;
	} while (players_left != 1u);
	done = 1u;
	return done;
}

/* The name entry: orders the four players by their scores, best first. */
void name_entry_rank_players(void)
{
	uint8_t next_place = 0, player = 0;
	uint16_t other = 0, ranked = 0, score_addresses = 0;
	uint16_t other_score = 0, ranked_player_score = 0;

	ranked = name_entry_ranking;
	io_write8(name_entry_ranking, 0u);
	io_write8(0x3862u, 1u);
	io_write8(0x3864u, 2u);
	io_write8(0x3866u, 3u);
	score_addresses = player_score_addresses_ADDRESS;
	rank_place = 0u;
	do
	{
		other = ranked + 2u;
		next_place = rank_place + 1u;
		if (next_place != 4u)
		{
			rank_other_place = next_place;
			do
			{
				other_score = mem_read16(SCORE_ADDRESS(score_addresses + (int8_t)((uint32_t)mem_read8(other) << 1)));
				rank_other_score = other_score;
				ranked_player_score = mem_read16(SCORE_ADDRESS(score_addresses + (int8_t)((uint32_t)mem_read8(ranked) << 1)));
				if (ranked_player_score <= rank_other_score)
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
	uint8_t kept_pointer_low = 0, kept_pointer_high = 0;
	uint8_t up_initial = 0, down_initial = 0, next_initial = 0, last_initial = 0, player_colour = 0, letters_left = 0;
	uint16_t repeat_wait = 0, repeat_wait_2 = 0, controls_pressed = 0, repeat_wait_3 = 0, controls_held = 0, repeat_wait_4 = 0, initials_2 = 0, letter_up_at = 0, controls_pressed_2 = 0, repeat_wait_5 = 0, controls_held_2 = 0, repeat_wait_6 = 0, initials_3 = 0, letter_down_at = 0, controls_pressed_3 = 0, initials_4 = 0, initials_5 = 0, letter_at = 0, letter_x = 0, next_letter_x = 0;

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
		up_initial = mem_read8(entry + 3u);
		initial = up_initial;
		initials_2 = NAME_ENTRY_PLAYER(name_entry_player)->initials;
		initials = initials_2;
		letter_up_at = initials + (int8_t)initial;
		mem_write8(letter_up_at, mem_read8(letter_up_at) + 1u);
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
		down_initial = mem_read8(entry + 3u);
		initial = down_initial;
		initials_3 = NAME_ENTRY_PLAYER(name_entry_player)->initials;
		initials = initials_3;
		letter_down_at = initials + (int8_t)initial;
		mem_write8(letter_down_at, mem_read8(letter_down_at) - 1u);
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
		next_initial = mem_read8(entry + 3u);
		initial = next_initial;
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
	last_initial = mem_read8(entry + 3u);
	initials_left = last_initial + 1u;
	do
	{
		kept_pointer_high = sprite >> 8;
		kept_pointer_low = (uint8_t)sprite;
		letter_at = initials;
		initials = letter_at + 1u;
		player_colour = io_read8(entry_player_record + 0x18u);
		sprite = ((uint32_t)kept_pointer_high << 8) | kept_pointer_low;
		letter_and_colour = ((uint32_t)mem_read8(letter_at) << 8) | (uint8_t)(player_colour + 0xAu);
		sprite = print_sprite_letter(sprite, letter_and_colour);
		if (mem_read8(entry) != 0xFFu && initials_left == 1u)
		{
			control = board_control | 2u;
			board_control = control;
			io_write8(board_control_register, control);
			kept_pointer_high = entry >> 8;
			kept_pointer_low = (uint8_t)entry;
			mem_write8(sprite - 7u, name_entry_cursor_zooms[((uint8_t)frame_count & 0x1Fu) >> 1]);
			entry = ((uint32_t)kept_pointer_high << 8) | kept_pointer_low;
			control = board_control & ~3u;
			board_control = control;
			io_write8(board_control_register, control);
		}
		letter_x = sprite_text_x;
		next_letter_x = letter_x + 0x10u;
		sprite_text_x = next_letter_x;
		letters_left = initials_left;
		initials_left = letters_left - 1u;
	} while (letters_left != 1u);
	return entry;
}

/* The name entry: prints a letter as a taller sprite (the scores' digits). */
uint16_t name_entry_print_tall_letter(uint16_t sprite, uint16_t letter_and_colour)
{
	uint8_t control = 0;

	sprite = print_sprite_letter(sprite, letter_and_colour);
	control = board_control | 2u;
	board_control = control;
	io_write8(board_control_register, control);
	mem_write16(sprite - 8u, 0x30u);
	control = board_control & ~3u;
	board_control = control;
	io_write8(board_control_register, control);
	return sprite;
}

/* The name entry: draws one of the pictures of tiles (a box or a player's face) in a player's column, or
   blanks it. */
void name_entry_draw_picture(uint16_t column_and_picture)
{
	uint8_t colour = 0, colour_2 = 0, column = 0;
	uint16_t picture = 0, tile = 0;
	uint8_t block_colour = 0, picture_number = 0, column_number = 0, column_tiles = 0, columns_to_draw = 0, column_palette = 0, rows_to_draw = 0, block_width = 0, column_and_blank = 0;
	uint8_t columns_left = 0, rows_left = 0;
	uint16_t column_2 = 0, block = 0, width_at = 0, height_at = 0, colour_at = 0, tile_code_at = 0, tile_place = 0, end_mark_at = 0;

	column = (uint8_t)(column_and_picture >> 8);
	column_and_blank = column;
	column_number = column & 0x7Fu;
	picture_number = (uint8_t)column_and_picture;
	column_2 = (((uint32_t)NAME_ENTRY_COLUMN(name_entry_columns_ADDRESS + (int8_t)((uint32_t)column_number << 1))->column << 8u) | NAME_ENTRY_COLUMN(name_entry_columns_ADDRESS + (int8_t)((uint32_t)column_number << 1))->palette);
	column_tiles = column_2 >> 8;
	column_palette = column_2;
	picture = name_entry_pictures[(int8_t)((uint8_t)((uint32_t)picture_number << 1)) / 2];
	do
	{
		block = picture;
		tile = mem_read16(block) + (int8_t)column_tiles;
		width_at = block + 2u;
		block_width = mem_read8(width_at);
		height_at = width_at + 1u;
		rows_to_draw = mem_read8(height_at);
		colour_at = height_at + 1u;
		picture = colour_at + 1u;
		colour = mem_read8(colour_at) | column_palette;
		if ((int8_t)column_and_blank < 0)
			colour = 0u;
		block_colour = colour;
		do
		{
			columns_to_draw = block_width;
			colour_2 = block_colour;
			do
			{
				mem_write8(tile - 0x2000u, colour_2);
				tile_code_at = picture;
				picture = tile_code_at + 1u;
				tile_place = tile;
				tile = tile_place + 1u;
				mem_write8(tile_place, mem_read8(tile_code_at));
				columns_left = columns_to_draw;
				columns_to_draw = columns_left - 1u;
			} while (columns_left != 1u);
			tile += (int8_t)(0x40u - block_width);
			rows_left = rows_to_draw;
			rows_to_draw = rows_left - 1u;
		} while (rows_left != 1u);
		end_mark_at = picture;
		picture = end_mark_at + 1u;
	} while (mem_read8(end_mark_at) == 0u);
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
	uint16_t command = 0, entry = 0, first_place = 0;
	uint8_t wait_left = 0;

	OBJECT(OBJECT_ADDRESS(14))->animation_flags = 0x40u;
	entry = high_scores_ADDRESS;
	first_place = 0x100u;
	high_scores_print_entries(entry, first_place);
	wait_left = (uint8_t)(scene_timer >> 8u);
	scene_timer = (scene_timer & 0xFFu) | ((wait_left - 1u & 0xFFu) << 8u);
	if (wait_left != 1u)
		return;
	io_write8(tile_chip_scroll_control, 3u);
	scene_timer = (scene_timer & 0xFFu) | 0x8000u;
	command = 0x700u;
	vector_queue_sound(command);
	game_step++;
}

/* The attract's high score table: waves the page line by line and wobbles its sprites' height, then
   clears them. */
void high_scores_wave_out(void)
{
	uint8_t control = 0, height = 0, wave = 0;
	uint16_t command = 0, line_scroll = 0, sprite = 0;
	uint8_t wait_left = 0, discarded_read = 0, rows_left = 0;
	uint16_t wave_product = 0, row_scroll = 0, row_scroll_at = 0;

	wait_left = (uint8_t)(scene_timer >> 8u);
	scene_timer = (scene_timer & 0xFFu) | ((wait_left - 1u & 0xFFu) << 8u);
	if (wait_left == 1u)
	{
		command = 0u;
		vector_queue_sound(command);
		discarded_read = io_read8(tile_chip_scroll_control);
		io_write8(tile_chip_scroll_control, 0u);
		vector_clear_sprites();
		game_step++;
		return;
	}
	line_scroll = tile_chip_layer_a_x;
	wave_lines_left = 0u;
	table_wave_offset = 0xDu * (uint8_t)frame_count;
	do
	{
		wave_product = 0xDu * table_wave_offset;
		row_scroll = wave_product - 0x7001u;
		wave = (uint8_t)row_scroll;
		row_scroll_at = line_scroll;
		line_scroll = row_scroll_at + 2u;
		mem_write16(row_scroll_at, ((uint32_t)(row_scroll >> 8) << 8) | wave);
		table_wave_offset = wave;
		rows_left = wave_lines_left;
		wave_lines_left = rows_left - 1u;
	} while (rows_left != 1u);
	table_wave_offset = 0xDu * (uint8_t)frame_count;
	control = board_control | 2u;
	board_control = control;
	io_write8(board_control_register, control);
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
	io_write8(board_control_register, control);
}

/* The attract's high score table: shows places 6 to 10; when its time is up, starts the wavy exit. */
void high_scores_show_second(void)
{
	uint16_t command = 0, entry = 0, first_place = 0;
	uint8_t wait_left = 0;

	OBJECT(OBJECT_ADDRESS(14))->animation_flags = 0x40u;
	entry = high_scores_ADDRESS + 0x28u;
	first_place = 0x600u;
	high_scores_print_entries(entry, first_place);
	wait_left = (uint8_t)(scene_timer >> 8u);
	scene_timer = (scene_timer & 0xFFu) | ((wait_left - 1u & 0xFFu) << 8u);
	if (wait_left != 1u)
		return;
	io_write8(tile_chip_scroll_control, 3u);
	scene_timer = (scene_timer & 0xFFu) | 0x8000u;
	command = 0x700u;
	vector_queue_sound(command);
	game_step++;
}

/* The attract's high score table: fades the colours out. */
void high_scores_fade_out(uint16_t palette_job)
{
	uint16_t request = 0;

	palette_request_kind = 3u;
	request = 0u;
	vector_palette_request(palette_job, request);
	vector_clear_layer_a();
	scene_timer = (scene_timer & 0xFFu) | 0x4000u;
	game_step++;
}

/* The attract's high score table: after the fade, clears the objects and goes on to the attract's next
   part. */
void high_scores_end(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0;
	uint8_t wait_left = 0;

	OBJECT(OBJECT_ADDRESS(14))->animation_flags = 0x40u;
	wait_left = (uint8_t)(scene_timer >> 8u);
	scene_timer = (scene_timer & 0xFFu) | ((wait_left - 1u & 0xFFu) << 8u);
	if (wait_left != 1u)
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
	uint8_t saved_entry_low = 0, saved_entry_high = 0, digits_low_then_icon = 0, digits_high_then_sprite_low = 0, sprite_high = 0;
	uint8_t place_tens = 0, initials_to_print = 0, digits_left = 0, entries_left = 0;
	uint16_t place_tens_x = 0, x_after_tens = 0, initial_at = 0, initial_x = 0, x_after_initial = 0, score_at = 0, bcd_score = 0, digits = 0, digits_shifted = 0, stored_digits = 0, digit_x = 0, x_after_digit = 0, entry_y = 0, next_entry_y = 0;

	sprite = 0x2000u;
	table_place = first_place >> 8;
	table_entries_left = 5u;
	sprite_text_x = 0x88u;
	sprite_text_y = 0x130u;
	do
	{
		saved_entry_high = entry >> 8;
		saved_entry_low = (uint8_t)entry;
		place_tens = (((table_place >> 1) >> 1) >> 1) >> 1;
		tens = place_tens;
		if (place_tens != 0u)
		{
			letter_and_colour = (uint32_t)(uint8_t)(tens + 0x30u) << 8;
			sprite = print_sprite_letter(sprite, letter_and_colour);
		}
		place_tens_x = sprite_text_x;
		x_after_tens = place_tens_x + 0x10u;
		sprite_text_x = x_after_tens;
		letter_and_colour = (uint32_t)(uint8_t)((table_place & 0xFu) + 0x30u) << 8;
		sprite = print_sprite_letter(sprite, letter_and_colour);
		table_characters_left = 3u;
		sprite_text_x = 0xB8u;
		do
		{
			initial_at = entry;
			entry = initial_at + 1u;
			letter_and_colour = (uint32_t)mem_read8(initial_at) << 8;
			sprite = print_sprite_letter(sprite, letter_and_colour);
			initial_x = sprite_text_x;
			x_after_initial = initial_x + 0x10u;
			sprite_text_x = x_after_initial;
			initials_to_print = table_characters_left;
			table_characters_left = initials_to_print - 1u;
		} while (initials_to_print != 1u);
		sprite_text_x = 0xE0u;
		table_characters_left = 4u;
		score_at = entry;
		entry_icon = score_at + 2u;
		bcd_score = mem_read16(score_at);
		digits_low_then_icon = bcd_score;
		digits_high_then_sprite_low = bcd_score >> 8;
		table_digit_shown = 0u;
		do
		{
			if (table_digit_shown != 0u || table_characters_left == 1u || (digits_high_then_sprite_low & ~0xFu) != 0u)
			{
				letter_and_colour = (uint32_t)(uint8_t)(((((digits_high_then_sprite_low >> 1) >> 1) >> 1) >> 1) + 0x30u) << 8;
				sprite = print_sprite_letter(sprite, letter_and_colour);
				table_digit_shown++;
			}
			digits = ((uint32_t)digits_high_then_sprite_low << 8) | digits_low_then_icon;
			digits_shifted = (uint32_t)digits << 4;
			stored_digits = digits_shifted;
			digits_high_then_sprite_low = stored_digits >> 8;
			digits_low_then_icon = stored_digits;
			digit_x = sprite_text_x;
			x_after_digit = digit_x + 0x10u;
			sprite_text_x = x_after_digit;
			digits_left = table_characters_left;
			table_characters_left = digits_left - 1u;
		} while (digits_left != 1u);
		sprite_text_x = 0x128u;
		digits_low_then_icon = mem_read8(entry_icon);
		icons = high_score_icons_ADDRESS;
		sprite_high = sprite >> 8;
		digits_high_then_sprite_low = (uint8_t)sprite;
		icon_frame = ((((uint8_t)(((uint16_t)(((uint32_t)sprite_high << 8) | digits_high_then_sprite_low) >> 3) + (uint8_t)frame_count) >> 1) >> 1) >> 1) >> 1;
		if ((icon_frame & 4u) == 0u)
			icon_frame = 0u;
		letter_and_colour = (uint32_t)(uint8_t)((icon_frame & 3u) + HIGH_SCORE_ICON(icons + (int8_t)digits_low_then_icon)) << 8;
		sprite = print_sprite_letter(sprite, letter_and_colour);
		sprite_text_x = 0x88u;
		entry_y = sprite_text_y;
		next_entry_y = entry_y - 0x18u;
		sprite_text_y = next_entry_y;
		place = table_place;
		half_carry = ((uint8_t)(place ^ 1u ^ (place + 1u)) >> 4) & 1u;
		carry = (uint8_t)(place + 1u) < place;
		table_place = konami_daa((uint8_t)(place + 1u), half_carry, carry);
		entry = (((uint32_t)saved_entry_high << 8) | saved_entry_low) + 8u;
		entries_left = table_entries_left;
		table_entries_left = entries_left - 1u;
	} while (entries_left != 1u);
}

/* Puts a letter as a sprite of the given colour at the current place, into the next sprite of the sprite
   RAM. */
uint16_t print_sprite_letter(uint16_t sprite, uint16_t letter_and_colour)
{
	uint16_t colour = 0;
	uint8_t saved_colour = 0;

	saved_colour = (uint8_t)letter_and_colour;
	sprite_text_code = ((uint32_t)sprite_font_code_high[0] << 8) | sprite_font_codes[(int8_t)((uint8_t)((letter_and_colour >> 8) - 0x30u))];
	colour = saved_colour;
	sprite = put_sprite(sprite, colour);
	return sprite;
}

/* Unused: would put a sprite code taken from a table, colour 0F, into the next sprite. */
void unused_print_sprite_code(uint16_t sprite_codes, uint16_t sprite)
{
	uint16_t colour = 0;
	uint16_t sprite_code = 0;

	sprite_code = mem_read16(sprite_codes + (int8_t)((uint32_t)sprite_code_index << 1));
	sprite_text_code = sprite_code;
	colour = 0xFu;
	put_sprite(sprite, colour);
}

/* Writes a sprite straight into the sprite RAM: the code, the current place, the given colour, at normal
   size; then moves on to the next sprite. */
uint16_t put_sprite(uint16_t sprite, uint16_t colour)
{
	uint8_t control = 0;
	uint8_t saved_flags = 0;
	uint16_t sprite_code = 0, sprite_x = 0, sprite_y = 0;

	saved_flags = colour >> 8;
	control = board_control | 2u;
	board_control = control;
	io_write8(board_control_register, control);
	io_write8(sprite, saved_flags | 0x80u);
	mem_write16(sprite + 0xCu, colour | 0x20u);
	sprite_code = sprite_text_code;
	mem_write16(sprite + 2u, sprite_code);
	sprite_x = sprite_text_x;
	mem_write16(sprite + 6u, sprite_x);
	sprite_y = sprite_text_y;
	mem_write16(sprite + 4u, sprite_y);
	mem_write16(sprite + 8u, 0x40u);
	mem_write16(sprite + 0xAu, 0x40u);
	sprite += 0x10u;
	control = board_control & ~3u;
	board_control = control;
	io_write8(board_control_register, control);
	return sprite;
}
