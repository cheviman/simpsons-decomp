/**
 *    Name:        players/gauges.c
 *    Description: the top line: scores, lives, health gauges, credits, CONTINUE?, GAME OVER
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Draws the top line while it is on: each player's score and quarter, and the credits unless free play */
void gauges_draw(void)
{
	uint32_t carry = 0;
	uint8_t a = 0, credits_shown = 0;
	uint16_t blank = 0, d = 0, gauge_player = 0, ignored16 = 0, picture = 0, place = 0, player_number = 0, tiles = 0, value = 0;
	uint8_t stack = 0;
	uint16_t t1 = 0;

	if (gauges_shown == 0u)
		return;
	a = 0u;
	do
	{
		stack = a;
		gauge_player = gauge_player_records[(int8_t)((uint8_t)((uint32_t)a << 1)) / 2];
		gauge_print_score(gauge_player);
		player_number = (uint32_t)stack << 8;
		gauge_draw_player(player_number);
		a = stack + 1u;
	} while (a != 4u);
	if (separate_coin_slots != 0u)
		return;
	tiles = 0x2766u;
	picture = credit_picture_ADDRESS;
	blank = 0u;
	gauges_put_picture(tiles, picture, blank);
	t1 = credits;
	credits_shown = (uint8_t)t1;
	if ((uint16_t)(((uint32_t)(t1 >> 8) << 8) | credits_shown) > 0xFFu)
		credits_shown = 0xFFu;
	d = credits_shown;
	gauges_byte_to_bcd(&ignored16, &d, &carry);
	a = (uint8_t)(d >> 8);
	if (carry)
		a = 0x99u;
	place = 0x276Du;
	value = (uint32_t)a << 8;
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
	uint8_t stack = 0;

	stack = d;
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
uint16_t gauges_count_delays(void)
{
	uint8_t a = 0;
	uint16_t gauge_counters = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0;
	uint16_t counters = 0;

	a = 0u;
	stack = 0u;
	do
	{
		counters = GAUGE_PLAYER(gauge_player_records[(int8_t)((uint8_t)((uint32_t)a << 1)) / 2])->counters;
		gauge_counters = counters;
		t1 = mem_read8(gauge_counters + 3u);
		a = t1;
		if (t1 != 0u)
			a--;
		mem_write8(gauge_counters + 3u, a);
		stack = stack + 1u;
		a = stack;
	} while (a != 4u);
	return gauge_counters;
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
	uint32_t carry = 0;
	uint8_t a = 0, lives_shown = 0;
	uint16_t count = 0, d = 0, gauge_player = 0, quarter_and_picture = 0, tiles = 0;
	uint8_t t2 = 0, number = 0, number_2 = 0, number_3 = 0, number_4 = 0, number_5 = 0, number_6 = 0;
	uint16_t status = 0, lives_tiles = 0, lives = 0, t1 = 0, status_2 = 0, continue_tiles = 0, counters = 0;

	gauge_player = gauge_player_records[(int8_t)((uint8_t)((uint32_t)(player_number >> 8) << 1)) / 2];
	status = GAUGE_PLAYER(gauge_player)->status;
	if (mem_read8(status) == 2u)
	{
		lives_tiles = GAUGE_PLAYER(gauge_player)->lives_tiles;
		tiles = lives_tiles;
		lives = GAUGE_PLAYER(gauge_player)->lives;
		t1 = mem_read16(lives);
		lives_shown = (uint8_t)t1;
		if ((uint16_t)(((uint32_t)(t1 >> 8) << 8) | lives_shown) > 0xFFu)
			lives_shown = 0xFFu;
		d = (uint8_t)(lives_shown - 1u);
		gauges_byte_to_bcd(&tiles, &d, &carry);
		a = (uint8_t)(d >> 8);
		if (carry)
			a = 0x99u;
		count = (d & 0xFFu) | ((uint32_t)a << 8);
		gauge_print_count(gauge_player, tiles, count);
		gauge_draw_player_picture(gauge_player);
		gauge_player = gauge_draw_health(gauge_player);
		t2 = mem_read8(gauge_player + 1u);
		quarter_and_picture = (uint32_t)t2 << 8;
		gauge_draw_picture(quarter_and_picture);
		return;
	}
	number = GAUGE_PLAYER(gauge_player)->number;
	quarter_and_picture = ((uint32_t)number << 8) | 0xAu;
	gauge_draw_picture(quarter_and_picture);
	number_2 = GAUGE_PLAYER(gauge_player)->number;
	d = ((uint32_t)number_2 << 8) | 1u;
	gauge_draw_picture(d);
	status_2 = GAUGE_PLAYER(gauge_player)->status;
	a = mem_read8(status_2);
	if (a == 3u)
	{
		continue_tiles = GAUGE_PLAYER(gauge_player)->continue_tiles;
		tiles = continue_tiles;
		counters = GAUGE_PLAYER(gauge_player)->counters;
		count = (d & 0xFFu) | ((uint32_t)mem_read8(counters) << 8);
		gauge_print_count(gauge_player, tiles, count);
		number_3 = GAUGE_PLAYER(gauge_player)->number;
		quarter_and_picture = ((uint32_t)number_3 << 8) | 2u;
		gauge_draw_picture(quarter_and_picture);
		return;
	}
	if (a == 4u)
	{
		number_4 = GAUGE_PLAYER(gauge_player)->number;
		quarter_and_picture = ((uint32_t)number_4 << 8) | 4u;
		gauge_draw_picture(quarter_and_picture);
		return;
	}
	if (a == 1u || a == 5u)
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
void gauges_byte_to_bcd(uint16_t *p_bcd_powers, uint16_t *p_value, uint32_t *p_carry)
{
	uint16_t bcd_powers = (uint16_t)*p_bcd_powers;
	uint8_t value = (uint8_t)*p_value;
	uint32_t carry = *p_carry;
	uint32_t half_carry = 0;
	uint8_t bcd = 0, bits = 0;
	uint16_t bcd_word = 0;
	uint8_t stack = 0, stack_2 = 0, stack_4 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	bits = (uint8_t)value;
	stack_2 = bcd_powers >> 8;
	stack = (uint8_t)bcd_powers;
	bcd_powers = bcd_bit_values_ADDRESS;
	stack_4 = 8u;
	carry = 0u;
	bcd = 0u;
	do
	{
		if ((bits & 1u) != 0u)
		{
			t1 = mem_read8(bcd_powers);
			t2 = bcd + t1;
			half_carry = ((bcd ^ t1 ^ t2) >> 4) & 1u;
			carry = (uint8_t)(bcd + t1) < bcd;
			bcd = t2;
			t3 = konami_daa(bcd, half_carry, carry);
			carry = konami_daa_carry(bcd, half_carry, carry);
			bcd = t3;
		}
		if (carry)
			break;
		bcd_powers++;
		bits = bits >> 1;
		carry = 0u;
		t4 = stack_4;
		stack_4 = t4 - 1u;
	} while (t4 != 1u);
	bcd_powers = ((uint32_t)stack_2 << 8) | stack;
	bcd_word = ((uint32_t)bcd << 8) | bits;
	*p_bcd_powers = bcd_powers;
	*p_value = bcd_word;
	*p_carry = carry;
}

/* Moves the health gauge one step toward the player's health and draws its four tiles */
uint16_t gauge_draw_health(uint16_t gauge_player)
{
	uint32_t zero = 0, carry = 0;
	uint8_t a = 0, b = 0, bottom = 0;
	uint16_t u = 0;
	uint8_t stack = 0, stack_2 = 0, stack_3 = 0, stack_4 = 0;
	uint8_t t1 = 0, t3 = 0, t4 = 0, t5 = 0, t8 = 0, t9 = 0;
	uint16_t counters = 0, health = 0, t2 = 0, t6 = 0, t7 = 0;

	counters = GAUGE_PLAYER(gauge_player)->counters;
	u = counters;
	a = 0x1Fu;
	health = GAUGE_PLAYER(gauge_player)->health;
	t1 = mem_read8(health);
	b = t1;
	if (t1 != 0u)
	{
		t2 = (uint32_t)a * b;
		stack_2 = gauge_player >> 8;
		stack = (uint8_t)gauge_player;
		stack_3 = t2;
		stack_4 = t2 >> 8;
		stack_3 = konami_divx((uint16_t)(((uint32_t)stack_4 << 8) | stack_3), 0x28u);
		b = stack_3 + 1u;
		gauge_player = ((uint32_t)stack_2 << 8) | stack;
	}
	t3 = mem_read8(u + 2u);
	zero = (uint8_t)(b - t3) == 0u;
	carry = b < t3;
	if (b == t3)
		b = 2u;
	else if (carry | zero)
		b = 1u;
	else
		b = 0u;
	t4 = mem_read8(u + 2u);
	a = t4;
	t5 = mem_read8(u + 3u);
	if (t5 != 0u)
		return gauge_player;
	if (b != 2u)
	{
		if (b == 1u)
			a--;
		else
			a++;
		mem_write8(u + 2u, a);
		mem_write8(u + 3u, 2u);
	}
	t6 = mem_read16(gauge_player + 0xEu);
	u = t6;
	stack = 4u;
	do
	{
		if (a == 0u)
		{
			stack_2 = a;
			mem_write8(u, 0x8Du);
			mem_write8(u - 0x2000u, 0xC0u);
			mem_write8(u + 0x40u, 0x9Du);
			mem_write8(u - 0x1FC0u, 0xC0u);
			a = stack_2;
		}
		else
		{
			if (a > 8u)
			{
				stack_2 = a;
				mem_write8(u, 0x85u);
				mem_write8(u - 0x2000u, 0xC0u);
				mem_write8(u + 0x40u, 0x95u);
				mem_write8(u - 0x1FC0u, 0xC0u);
				a = stack_2;
			}
			else
			{
				stack_2 = a;
				t7 = gauge_step_tiles_ADDRESS + (int8_t)((uint32_t)a << 1);
				mem_write8(u, GAUGE_STEP(t7)->top);
				mem_write8(u - 0x2000u, 0xC0u);
				bottom = GAUGE_STEP(t7)->bottom;
				mem_write8(u + 0x40u, bottom);
				mem_write8(u - 0x1FC0u, 0xC0u);
				a = stack_2;
			}
			t8 = a;
			a = t8 - 8u;
			if (t8 < 8u)
				a = 0u;
		}
		u++;
		t9 = stack;
		stack = t9 - 1u;
	} while (t9 != 1u);
	return gauge_player;
}

/* Prints a BCD count in two big two-row digits in the player's colour (a 0 first is blank) */
void gauge_print_count(uint16_t gauge_player, uint16_t tiles, uint16_t count)
{
	uint8_t a = 0, bottom = 0;
	uint16_t digits = 0;
	uint8_t stack_F = 0, stack = 0;
	uint8_t number = 0, t1 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	stack = count >> 8;
	number = GAUGE_PLAYER(gauge_player)->number;
	stack_F = GAUGE_COLUMN(gauge_player_columns_ADDRESS + (int8_t)(((uint32_t)number << 1) + 1u))->column;
	digits = big_digits_ADDRESS;
	t1 = stack & ~0xFu;
	a = t1;
	if (t1 == 0u)
		a = 0xA0u;
	t2 = digits + ((a >> 1) >> 1);
	a = BIG_DIGIT(t2)->attribute | stack_F;
	mem_write8(tiles - 0x2000u, a);
	mem_write8(tiles - 0x1FC0u, a);
	t3 = t2 + 1u;
	mem_write8(tiles, BIG_DIGIT(t3 - 0x1u)->top);
	bottom = BIG_DIGIT(t3 - 0x1u)->bottom;
	mem_write8(tiles + 0x40u, bottom);
	tiles++;
	t4 = big_digits_ADDRESS + (uint8_t)(((stack & 0xFu) << 1) << 1);
	a = BIG_DIGIT(t4)->attribute | stack_F;
	mem_write8(tiles - 0x2000u, a);
	mem_write8(tiles - 0x1FC0u, a);
	t5 = t4 + 1u;
	mem_write8(tiles, BIG_DIGIT(t5 - 0x1u)->top);
	bottom = BIG_DIGIT(t5 - 0x1u)->bottom;
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
	uint8_t a = 0;
	uint16_t blank = 0, picture = 0, tiles = 0;
	uint8_t stack = 0, stack_2 = 0;

	a = continue_seconds;
	stack = a;
	a = (((a >> 1) >> 1) >> 1) >> 1;
	stack_2 = a;
	picture = continue_digit_pictures[a & 0x7Fu];
	tiles = 0x2418u;
	a = stack_2;
	if (a == 0u)
		a = 0x80u;
	blank = (uint32_t)a << 8;
	gauges_put_picture(tiles, picture, blank);
	picture = continue_digit_pictures[stack & 0xFu];
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
	uint8_t stack = 0, stack_2 = 0, stack_3 = 0, stack_4 = 0, stack_5 = 0;
	uint8_t t5 = 0, t8 = 0, t9 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t6 = 0, t7 = 0;

	stack = blank >> 8;
	t1 = picture;
	t2 = mem_read16(t1);
	stack_2 = t2;
	stack_3 = t2 >> 8;
	t3 = t1 + 2u;
	cursor = t3 + 1u;
	stack_5 = mem_read8(t3);
	do
	{
		stack_4 = stack_3;
		if ((int8_t)stack < 0)
		{
			blank_tile = 0x10u;
			colour = 0u;
			do
			{
				mem_write8(tiles - 0x2000u, colour);
				t4 = tiles;
				tiles = t4 + 1u;
				mem_write8(t4, blank_tile);
				t5 = stack_4;
				stack_4 = t5 - 1u;
			} while (t5 != 1u);
		}
		else
		{
			colour = stack_5;
			do
			{
				mem_write8(tiles - 0x2000u, colour);
				t6 = cursor;
				cursor = t6 + 1u;
				t7 = tiles;
				tiles = t7 + 1u;
				mem_write8(t7, mem_read8(t6));
				t8 = stack_4;
				stack_4 = t8 - 1u;
			} while (t8 != 1u);
		}
		tiles += (int8_t)(0x40u - stack_3);
		t9 = stack_2;
		stack_2 = t9 - 1u;
	} while (t9 != 1u);
}

/* Draws picture B in player A's quarter, in its colour (blank with A bit 7 set) */
void gauge_draw_picture(uint16_t quarter_and_picture)
{
	uint8_t a = 0, colour = 0;
	uint16_t cursor = 0, tile = 0;
	uint8_t stack_E = 0, stack_F = 0, stack = 0, stack_11 = 0, stack_12 = 0, stack_13 = 0, stack_14 = 0, stack_15 = 0, stack_16 = 0;
	uint8_t t7 = 0, t8 = 0;
	uint16_t column = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t9 = 0;

	a = (uint8_t)(quarter_and_picture >> 8);
	stack_16 = a;
	stack = a & 0x7Fu;
	stack_F = (uint8_t)quarter_and_picture;
	column = (((uint32_t)GAUGE_COLUMN(gauge_player_columns_ADDRESS + (int8_t)((uint32_t)stack << 1))->column << 8u) | GAUGE_COLUMN(gauge_player_columns_ADDRESS + (int8_t)((uint32_t)stack << 1))->colour);
	stack_11 = column >> 8;
	stack_13 = column;
	cursor = gauge_pictures[(int8_t)((uint8_t)((uint32_t)stack_F << 1)) / 2];
	do
	{
		t1 = cursor;
		tile = mem_read16(t1) + (int8_t)stack_11;
		t2 = t1 + 2u;
		stack_15 = mem_read8(t2);
		t3 = t2 + 1u;
		stack_14 = mem_read8(t3);
		t4 = t3 + 1u;
		cursor = t4 + 1u;
		a = mem_read8(t4) | stack_13;
		if ((int8_t)stack_16 < 0)
			a = 0u;
		stack_E = a;
		do
		{
			stack_12 = stack_15;
			colour = stack_E;
			do
			{
				mem_write8(tile - 0x2000u, colour);
				t5 = cursor;
				cursor = t5 + 1u;
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
		t9 = cursor;
		cursor = t9 + 1u;
	} while (mem_read8(t9) == 0u);
}
