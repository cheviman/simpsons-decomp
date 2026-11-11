/**
 *    Name:        players/gauges.c
 *    Description: the top line: scores, lives, health gauges, credits, CONTINUE?, GAME OVER
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Draws the top line while it is on: each player's score and quarter, and the credits unless free play */
void gauges_draw(void)
{
	uint32_t past_99 = 0;
	uint8_t credits_bcd = 0, credits_shown = 0, player_index = 0;
	uint16_t bcd_value = 0, blank = 0, gauge_player = 0, ignored16 = 0, picture = 0, place = 0, player_number = 0, tiles = 0, value = 0;
	uint8_t player_counter = 0;
	uint16_t credits_count = 0;

	if (gauges_shown == 0u)
		return;
	player_index = 0u;
	do
	{
		player_counter = player_index;
		gauge_player = gauge_player_records[(int8_t)((uint8_t)((uint32_t)player_index << 1)) / 2];
		gauge_print_score(gauge_player);
		player_number = (uint32_t)player_counter << 8;
		gauge_draw_player(player_number);
		player_index = player_counter + 1u;
	} while (player_index != 4u);
	if (separate_coin_slots != 0u)
		return;
	tiles = 0x2766u;
	picture = credit_picture_ADDRESS;
	blank = 0u;
	gauges_put_picture(tiles, picture, blank);
	credits_count = credits;
	credits_shown = (uint8_t)credits_count;
	if ((uint16_t)(((uint32_t)(credits_count >> 8) << 8) | credits_shown) > 0xFFu)
		credits_shown = 0xFFu;
	bcd_value = credits_shown;
	gauges_byte_to_bcd(&ignored16, &bcd_value, &past_99);
	credits_bcd = (uint8_t)(bcd_value >> 8);
	if (past_99)
		credits_bcd = 0x99u;
	place = 0x276Du;
	value = (uint32_t)credits_bcd << 8;
	print_bcd_byte(place, value);
}

/* Draws CONTINUE? and the continue's countdown */
void continue_draw(void)
{
	uint16_t blank = 0, picture = 0, tiles = 0;

	tiles = 0x2213u;
	picture = continue_picture_ADDRESS;
	blank = 0u;
	gauges_put_picture(tiles, picture, blank);
	continue_draw_count();
}

/* Erases CONTINUE? and its countdown, then draws GAME OVER */
void continue_end(void)
{
	uint8_t d = 0;
	uint16_t blank = 0, picture = 0, tiles = 0;
	uint8_t saved_caller_byte = 0;

	saved_caller_byte = d;
	tiles = 0x2213u;
	picture = continue_picture_ADDRESS;
	blank = 0x8000u;
	gauges_put_picture(tiles, picture, blank);
	continue_erase_count();
	tiles = 0x2394u;
	picture = game_over_picture_ADDRESS;
	blank = 0u;
	gauges_put_picture(tiles, picture, blank);
}

/* Draws GAME OVER */
void game_over_draw(void)
{
	uint16_t blank = 0, picture = 0, tiles = 0;

	tiles = 0x2394u;
	picture = game_over_picture_ADDRESS;
	blank = 0u;
	gauges_put_picture(tiles, picture, blank);
}

/* Counts down each player's health gauge's step delay */
void gauges_count_delays(void)
{
	uint8_t delay = 0, player_index = 0;
	uint16_t gauge_counters = 0;
	uint8_t player_counter = 0;
	uint8_t old_delay = 0;
	uint16_t counters = 0;

	player_index = 0u;
	player_counter = 0u;
	do
	{
		counters = GAUGE_PLAYER(gauge_player_records[(int8_t)((uint8_t)((uint32_t)player_index << 1)) / 2])->counters;
		gauge_counters = counters;
		old_delay = PLAYER_COUNTERS(gauge_counters)->gauge_delay;
		delay = old_delay;
		if (old_delay != 0u)
			delay--;
		PLAYER_COUNTERS(gauge_counters)->gauge_delay = delay;
		player_counter = player_counter + 1u;
		player_index = player_counter;
	} while (player_index != 4u);
	leftover_y = gauge_counters;
}

/* Prints a player's score in its quarter */
void gauge_print_score(uint16_t gauge_player)
{
	uint16_t place = 0, value = 0;
	uint16_t score = 0, score_tiles = 0;

	score = GAUGE_PLAYER(gauge_player)->score;
	value = mem_read16(score);
	score_tiles = GAUGE_PLAYER(gauge_player)->score_tiles;
	place = score_tiles;
	print_bcd_word(place, value);
}

/* Draws a player's quarter by its status: playing, continue count, game over or waiting */
void gauge_draw_player(uint16_t player_number)
{
	uint32_t past_99 = 0;
	uint8_t lives_bcd = 0, lives_shown = 0, player_status = 0;
	uint16_t bcd_value = 0, count = 0, gauge_player = 0, quarter_and_picture = 0, tiles = 0;
	uint8_t quarter = 0, number = 0, number_2 = 0, number_3 = 0, number_4 = 0, number_5 = 0, number_6 = 0;
	uint16_t status = 0, lives_tiles = 0, lives = 0, lives_count = 0, status_2 = 0, continue_tiles = 0, counters = 0;

	gauge_player = gauge_player_records[(int8_t)((uint8_t)((uint32_t)(player_number >> 8) << 1)) / 2];
	status = GAUGE_PLAYER(gauge_player)->status;
	if (mem_read8(status) == 2u)
	{
		lives_tiles = GAUGE_PLAYER(gauge_player)->lives_tiles;
		tiles = lives_tiles;
		lives = GAUGE_PLAYER(gauge_player)->lives;
		lives_count = mem_read16(lives);
		lives_shown = (uint8_t)lives_count;
		if ((uint16_t)(((uint32_t)(lives_count >> 8) << 8) | lives_shown) > 0xFFu)
			lives_shown = 0xFFu;
		bcd_value = (uint8_t)(lives_shown - 1u);
		gauges_byte_to_bcd(&tiles, &bcd_value, &past_99);
		lives_bcd = (uint8_t)(bcd_value >> 8);
		if (past_99)
			lives_bcd = 0x99u;
		count = (bcd_value & 0xFFu) | ((uint32_t)lives_bcd << 8);
		gauge_print_count(gauge_player, tiles, count);
		gauge_draw_player_picture(gauge_player);
		gauge_player = gauge_draw_health(gauge_player);
		quarter = GAUGE_PLAYER(gauge_player)->number;
		quarter_and_picture = (uint32_t)quarter << 8;
		gauge_draw_picture(quarter_and_picture);
		return;
	}
	number = GAUGE_PLAYER(gauge_player)->number;
	quarter_and_picture = ((uint32_t)number << 8) | 0xAu;
	gauge_draw_picture(quarter_and_picture);
	number_2 = GAUGE_PLAYER(gauge_player)->number;
	quarter_and_picture = ((uint32_t)number_2 << 8) | 1u;
	gauge_draw_picture(quarter_and_picture);
	status_2 = GAUGE_PLAYER(gauge_player)->status;
	player_status = mem_read8(status_2);
	if (player_status == 3u)
	{
		continue_tiles = GAUGE_PLAYER(gauge_player)->continue_tiles;
		tiles = continue_tiles;
		counters = GAUGE_PLAYER(gauge_player)->counters;
		count = (quarter_and_picture & 0xFFu) | ((uint32_t)PLAYER_COUNTERS(counters)->seconds << 8);
		gauge_print_count(gauge_player, tiles, count);
		number_3 = GAUGE_PLAYER(gauge_player)->number;
		quarter_and_picture = ((uint32_t)number_3 << 8) | 2u;
		gauge_draw_picture(quarter_and_picture);
		return;
	}
	if (player_status == 4u)
	{
		number_4 = GAUGE_PLAYER(gauge_player)->number;
		quarter_and_picture = ((uint32_t)number_4 << 8) | 4u;
		gauge_draw_picture(quarter_and_picture);
		return;
	}
	if (player_status == 1u || player_status == 5u)
	{
		number_5 = GAUGE_PLAYER(gauge_player)->number;
		quarter_and_picture = ((uint32_t)number_5 << 8) | 5u;
		gauge_draw_picture(quarter_and_picture);
		return;
	}
	number_6 = GAUGE_PLAYER(gauge_player)->number;
	quarter_and_picture = ((uint32_t)number_6 << 8) | 3u;
	gauge_draw_picture(quarter_and_picture);
}

/* B in BCD in A (carry set past 99) */
void gauges_byte_to_bcd(uint16_t *p_bcd_powers, uint16_t *p_value, uint32_t *p_past_99)
{
	uint16_t bcd_powers = (uint16_t)*p_bcd_powers;
	uint8_t value = (uint8_t)*p_value;
	uint32_t past_99 = *p_past_99;
	uint32_t half_carry = 0;
	uint8_t bcd = 0, bits = 0;
	uint16_t bcd_word = 0;
	uint8_t saved_tiles_low = 0, saved_tiles_high = 0, bit_count = 0;
	uint8_t bit_value = 0, bcd_sum = 0, adjusted_bcd = 0, bits_before = 0;

	bits = (uint8_t)value;
	saved_tiles_high = bcd_powers >> 8;
	saved_tiles_low = (uint8_t)bcd_powers;
	bcd_powers = bcd_bit_values_ADDRESS;
	bit_count = 8u;
	past_99 = 0u;
	bcd = 0u;
	do
	{
		if ((bits & 1u) != 0u)
		{
			bit_value = mem_read8(bcd_powers);
			bcd_sum = bcd + bit_value;
			half_carry = ((bcd ^ bit_value ^ bcd_sum) >> 4) & 1u;
			past_99 = (uint8_t)(bcd + bit_value) < bcd;
			bcd = bcd_sum;
			adjusted_bcd = konami_daa(bcd, half_carry, past_99);
			past_99 = konami_daa_carry(bcd, half_carry, past_99);
			bcd = adjusted_bcd;
		}
		if (past_99)
			break;
		bcd_powers++;
		bits = bits >> 1;
		past_99 = 0u;
		bits_before = bit_count;
		bit_count = bits_before - 1u;
	} while (bits_before != 1u);
	bcd_powers = ((uint32_t)saved_tiles_high << 8) | saved_tiles_low;
	bcd_word = ((uint32_t)bcd << 8) | bits;
	*p_bcd_powers = bcd_powers;
	*p_value = bcd_word;
	*p_past_99 = past_99;
}

/* Moves the health gauge one step toward the player's health and draws its four tiles */
uint16_t gauge_draw_health(uint16_t gauge_player)
{
	uint32_t gauge_at_health = 0, gauge_above_health = 0;
	uint8_t bottom = 0, gauge_scale = 0, gauge_steps = 0, step_change = 0, target_step = 0;
	uint16_t gauge_counters = 0, gauge_tile = 0;
	uint8_t player_low_or_tiles_left = 0, player_high_or_steps = 0, division_low = 0, division_high = 0;
	uint8_t health_value = 0, shown_step = 0, gauge_step = 0, step_delay = 0, steps_before = 0, tiles_before = 0;
	uint16_t counters = 0, health = 0, scaled_health = 0, first_tile = 0, step_record = 0;

	counters = GAUGE_PLAYER(gauge_player)->counters;
	gauge_counters = counters;
	gauge_scale = 0x1Fu;
	health = GAUGE_PLAYER(gauge_player)->health;
	health_value = mem_read8(health);
	target_step = health_value;
	if (health_value != 0u)
	{
		scaled_health = (uint32_t)gauge_scale * target_step;
		player_high_or_steps = gauge_player >> 8;
		player_low_or_tiles_left = (uint8_t)gauge_player;
		division_low = scaled_health;
		division_high = scaled_health >> 8;
		division_low = konami_divx((uint16_t)(((uint32_t)division_high << 8) | division_low), 0x28u);
		target_step = division_low + 1u;
		gauge_player = ((uint32_t)player_high_or_steps << 8) | player_low_or_tiles_left;
	}
	shown_step = PLAYER_COUNTERS(gauge_counters)->gauge_step;
	gauge_at_health = (uint8_t)(target_step - shown_step) == 0u;
	gauge_above_health = target_step < shown_step;
	if (target_step == shown_step)
		step_change = 2u;
	else if (gauge_above_health | gauge_at_health)
		step_change = 1u;
	else
		step_change = 0u;
	gauge_step = PLAYER_COUNTERS(gauge_counters)->gauge_step;
	gauge_steps = gauge_step;
	step_delay = PLAYER_COUNTERS(gauge_counters)->gauge_delay;
	if (step_delay != 0u)
		return gauge_player;
	if (step_change != 2u)
	{
		if (step_change == 1u)
			gauge_steps--;
		else
			gauge_steps++;
		PLAYER_COUNTERS(gauge_counters)->gauge_step = gauge_steps;
		PLAYER_COUNTERS(gauge_counters)->gauge_delay = 2u;
	}
	first_tile = GAUGE_PLAYER(gauge_player)->gauge_tiles;
	gauge_tile = first_tile;
	player_low_or_tiles_left = 4u;
	do
	{
		if (gauge_steps == 0u)
		{
			player_high_or_steps = gauge_steps;
			mem_write8(gauge_tile, 0x8Du);
			mem_write8(gauge_tile - 0x2000u, 0xC0u);
			mem_write8(gauge_tile + 0x40u, 0x9Du);
			mem_write8(gauge_tile - 0x1FC0u, 0xC0u);
			gauge_steps = player_high_or_steps;
		}
		else
		{
			if (gauge_steps > 8u)
			{
				player_high_or_steps = gauge_steps;
				mem_write8(gauge_tile, 0x85u);
				mem_write8(gauge_tile - 0x2000u, 0xC0u);
				mem_write8(gauge_tile + 0x40u, 0x95u);
				mem_write8(gauge_tile - 0x1FC0u, 0xC0u);
				gauge_steps = player_high_or_steps;
			}
			else
			{
				player_high_or_steps = gauge_steps;
				step_record = gauge_step_tiles_ADDRESS + (int8_t)((uint32_t)gauge_steps << 1);
				mem_write8(gauge_tile, GAUGE_STEP(step_record)->top);
				mem_write8(gauge_tile - 0x2000u, 0xC0u);
				bottom = GAUGE_STEP(step_record)->bottom;
				mem_write8(gauge_tile + 0x40u, bottom);
				mem_write8(gauge_tile - 0x1FC0u, 0xC0u);
				gauge_steps = player_high_or_steps;
			}
			steps_before = gauge_steps;
			gauge_steps = steps_before - 8u;
			if (steps_before < 8u)
				gauge_steps = 0u;
		}
		gauge_tile++;
		tiles_before = player_low_or_tiles_left;
		player_low_or_tiles_left = tiles_before - 1u;
	} while (tiles_before != 1u);
	return gauge_player;
}

/* Prints a BCD count in two big two-row digits in the player's colour (a 0 first is blank) */
void gauge_print_count(uint16_t gauge_player, uint16_t tiles, uint16_t count)
{
	uint8_t bottom = 0, digit_attribute = 0, tens_index = 0;
	uint16_t digits = 0;
	uint8_t player_colour = 0, bcd_count = 0;
	uint8_t number = 0, tens_nibble = 0;
	uint16_t tens_record = 0, tens_cursor = 0, units_record = 0, units_cursor = 0;

	bcd_count = count >> 8;
	number = GAUGE_PLAYER(gauge_player)->number;
	player_colour = GAUGE_COLUMN(gauge_player_columns_ADDRESS + (int8_t)(((uint32_t)number << 1) + 1u))->column;
	digits = big_digits_ADDRESS;
	tens_nibble = bcd_count & ~0xFu;
	tens_index = tens_nibble;
	if (tens_nibble == 0u)
		tens_index = 0xA0u;
	tens_record = digits + ((tens_index >> 1) >> 1);
	digit_attribute = BIG_DIGIT(tens_record)->attribute | player_colour;
	mem_write8(tiles - 0x2000u, digit_attribute);
	mem_write8(tiles - 0x1FC0u, digit_attribute);
	tens_cursor = tens_record + 1u;
	mem_write8(tiles, BIG_DIGIT(tens_cursor - 0x1u)->top);
	bottom = BIG_DIGIT(tens_cursor - 0x1u)->bottom;
	mem_write8(tiles + 0x40u, bottom);
	tiles++;
	units_record = big_digits_ADDRESS + (uint8_t)(((bcd_count & 0xFu) << 1) << 1);
	digit_attribute = BIG_DIGIT(units_record)->attribute | player_colour;
	mem_write8(tiles - 0x2000u, digit_attribute);
	mem_write8(tiles - 0x1FC0u, digit_attribute);
	units_cursor = units_record + 1u;
	mem_write8(tiles, BIG_DIGIT(units_cursor - 0x1u)->top);
	bottom = BIG_DIGIT(units_cursor - 0x1u)->bottom;
	mem_write8(tiles + 0x40u, bottom);
}

/* Draws the player's own picture (6 on) in its quarter */
void gauge_draw_player_picture(uint16_t gauge_player)
{
	uint16_t quarter_and_picture = 0;
	uint8_t number = 0;

	number = GAUGE_PLAYER(gauge_player)->number;
	quarter_and_picture = ((uint32_t)number << 8) | (uint8_t)(number + 6u);
	gauge_draw_picture(quarter_and_picture);
}

/* Draws the continue's countdown in big digits (a 0 first is blank) */
void continue_draw_count(void)
{
	uint8_t seconds = 0, tens_or_blank = 0;
	uint16_t blank = 0, picture = 0, tiles = 0;
	uint8_t seconds_bcd = 0, tens_digit = 0;

	seconds = continue_seconds;
	seconds_bcd = seconds;
	seconds = (((seconds >> 1) >> 1) >> 1) >> 1;
	tens_digit = seconds;
	picture = continue_digit_pictures[seconds & 0x7Fu];
	tiles = 0x2418u;
	tens_or_blank = tens_digit;
	if (tens_or_blank == 0u)
		tens_or_blank = 0x80u;
	blank = (uint32_t)tens_or_blank << 8;
	gauges_put_picture(tiles, picture, blank);
	picture = continue_digit_pictures[seconds_bcd & 0xFu];
	tiles = 0x2420u;
	blank = 0u;
	gauges_put_picture(tiles, picture, blank);
}

/* Blanks the continue's countdown */
void continue_erase_count(void)
{
	uint16_t blank = 0, picture = 0, tiles = 0;

	tiles = 0x2418u;
	picture = continue_count_blank_picture_ADDRESS;
	blank = 0x8000u;
	gauges_put_picture(tiles, picture, blank);
	tiles = 0x2420u;
	picture = continue_count_blank_picture_ADDRESS;
	blank = 0x8000u;
	gauges_put_picture(tiles, picture, blank);
}

/* Draws a picture of tiles at X (blank with A bit 7 set) */
void gauges_put_picture(uint16_t tiles, uint16_t picture, uint16_t blank)
{
	uint8_t blank_tile = 0, colour = 0;
	uint16_t cursor = 0;
	uint8_t blank_flag = 0, rows_left = 0, columns_wide = 0, columns_left = 0, tile_colour = 0;
	uint8_t columns_before = 0, copy_columns_before = 0, rows_before = 0;
	uint16_t header = 0, picture_size = 0, colour_address = 0, blank_place = 0, source = 0, tile_place = 0;

	blank_flag = blank >> 8;
	header = picture;
	picture_size = mem_read16(header);
	rows_left = picture_size;
	columns_wide = picture_size >> 8;
	colour_address = header + 2u;
	cursor = colour_address + 1u;
	tile_colour = mem_read8(colour_address);
	do
	{
		columns_left = columns_wide;
		if ((int8_t)blank_flag < 0)
		{
			blank_tile = 0x10u;
			colour = 0u;
			do
			{
				mem_write8(tiles - 0x2000u, colour);
				blank_place = tiles;
				tiles = blank_place + 1u;
				mem_write8(blank_place, blank_tile);
				columns_before = columns_left;
				columns_left = columns_before - 1u;
			} while (columns_before != 1u);
		}
		else
		{
			colour = tile_colour;
			do
			{
				mem_write8(tiles - 0x2000u, colour);
				source = cursor;
				cursor = source + 1u;
				tile_place = tiles;
				tiles = tile_place + 1u;
				mem_write8(tile_place, mem_read8(source));
				copy_columns_before = columns_left;
				columns_left = copy_columns_before - 1u;
			} while (copy_columns_before != 1u);
		}
		tiles += (int8_t)(0x40u - columns_wide);
		rows_before = rows_left;
		rows_left = rows_before - 1u;
	} while (rows_before != 1u);
}

/* Draws picture B in player A's quarter, in its colour (blank with A bit 7 set) */
void gauge_draw_picture(uint16_t quarter_and_picture)
{
	uint8_t colour = 0, part_colour = 0, quarter_byte = 0;
	uint16_t cursor = 0, tile = 0;
	uint8_t draw_colour = 0, picture_number = 0, quarter_number = 0, quarter_column = 0, columns_left = 0, quarter_colour = 0, rows_left = 0, part_width = 0, quarter_and_blank = 0;
	uint8_t columns_before = 0, rows_before = 0;
	uint16_t column = 0, part = 0, columns_address = 0, rows_address = 0, colour_address = 0, source = 0, tile_place = 0, end_mark = 0;

	quarter_byte = (uint8_t)(quarter_and_picture >> 8);
	quarter_and_blank = quarter_byte;
	quarter_number = quarter_byte & 0x7Fu;
	picture_number = (uint8_t)quarter_and_picture;
	column = (((uint32_t)GAUGE_COLUMN(gauge_player_columns_ADDRESS + (int8_t)((uint32_t)quarter_number << 1))->column << 8u) | GAUGE_COLUMN(gauge_player_columns_ADDRESS + (int8_t)((uint32_t)quarter_number << 1))->colour);
	quarter_column = column >> 8;
	quarter_colour = column;
	cursor = gauge_pictures[(int8_t)((uint8_t)((uint32_t)picture_number << 1)) / 2];
	do
	{
		part = cursor;
		tile = mem_read16(part) + (int8_t)quarter_column;
		columns_address = part + 2u;
		part_width = mem_read8(columns_address);
		rows_address = columns_address + 1u;
		rows_left = mem_read8(rows_address);
		colour_address = rows_address + 1u;
		cursor = colour_address + 1u;
		part_colour = mem_read8(colour_address) | quarter_colour;
		if ((int8_t)quarter_and_blank < 0)
			part_colour = 0u;
		draw_colour = part_colour;
		do
		{
			columns_left = part_width;
			colour = draw_colour;
			do
			{
				mem_write8(tile - 0x2000u, colour);
				source = cursor;
				cursor = source + 1u;
				tile_place = tile;
				tile = tile_place + 1u;
				mem_write8(tile_place, mem_read8(source));
				columns_before = columns_left;
				columns_left = columns_before - 1u;
			} while (columns_before != 1u);
			tile += (int8_t)(0x40u - part_width);
			rows_before = rows_left;
			rows_left = rows_before - 1u;
		} while (rows_before != 1u);
		end_mark = cursor;
		cursor = end_mark + 1u;
	} while (mem_read8(end_mark) == 0u);
}
