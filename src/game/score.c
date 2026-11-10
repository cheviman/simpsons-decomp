/**
 *    Name:        game/score.c
 *    Description: the players' scores and the high score table
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Adds score_additions' entry B (BCD) to the score at X. */
void add_score(uint16_t score, uint8_t addition)
{
	uint32_t carry = 0, half_carry = 0;
	uint8_t addition_low = 0, high = 0, low_sum = 0;
	uint16_t score_addition = 0;
	uint8_t low = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	score_addition = score_additions_ADDRESS + (int8_t)((uint32_t)addition << 1);
	low = SCORE_ADDITION(score_addition)->low;
	addition_low = low;
	t1 = mem_read8(score + 1u);
	t2 = addition_low + t1;
	half_carry = ((addition_low ^ t1 ^ t2) >> 4) & 1u;
	carry = (uint8_t)(addition_low + t1) < addition_low;
	low_sum = t2;
	t3 = konami_daa(low_sum, half_carry, carry);
	carry = konami_daa_carry(low_sum, half_carry, carry);
	mem_write8(score + 1u, t3);
	high = SCORE_ADDITION(score_addition)->high;
	t4 = mem_read8(score);
	t5 = high + t4 + carry;
	half_carry = ((high ^ t4 ^ t5) >> 4) & 1u;
	carry = konami_carry_add8(high, t4, carry);
	mem_write8(score, konami_daa(t5, half_carry, carry));
}

/* Finds the place of the score D in the high score table (A, 0-9; carry when it gets in). */
void high_score_rank(uint16_t *p_score, uint32_t *p_carry)
{
	uint16_t score = (uint16_t)*p_score;
	uint32_t carry = *p_carry;
	uint8_t d = 0;
	uint16_t high_score_address = 0;
	uint16_t t1 = 0;

	ranked_score = score;
	high_score_address = high_scores_ADDRESS + 0x3u;
	high_score_place_found = 0u;
	for (;;)
	{
		t1 = ranked_score;
		d = (uint8_t)t1;
		if (mem_read16(high_score_address) <= (uint16_t)(((uint32_t)(t1 >> 8) << 8) | (d & 0xFFu)))
		{
			carry = 1u;
			score = (d & 0xFFu) | ((uint32_t)high_score_place_found << 8);
			break;
		}
		high_score_address += 8u;
		high_score_place_found++;
		if (high_score_place_found == 0xAu)
		{
			carry = 0u;
			score = (d & 0xFFu) | ((uint32_t)high_score_place_found << 8);
			break;
		}
	}
	*p_score = score;
	*p_carry = carry;
}

/* Puts the initials and score at 48F0 into the high score table at place A, moving the lower ones down. */
uint16_t insert_high_score(uint16_t place)
{
	uint8_t insert_place = 0;
	uint16_t new_entry = 0, record_place = 0;
	uint8_t t1 = 0, t4 = 0, t8 = 0;
	uint16_t t2 = 0, t3 = 0, t5 = 0, t6 = 0, t7 = 0;

	new_high_score_place = place >> 8;
	high_score_moved_place = 9u;
	record_place = high_scores_ADDRESS + 0x48u;
	for (;;)
	{
		insert_place = new_high_score_place;
		if (insert_place == high_score_moved_place)
			break;
		t1 = high_score_moved_place - 1u;
		high_score_moved_place = t1;
		if ((int8_t)t1 < 0)
		{
			place = (place & 0xFFu) | ((uint32_t)insert_place << 8);
			return place;
		}
		high_score_words_left = 4u;
		do
		{
			t2 = mem_read16(record_place - 8u);
			place = t2;
			t3 = record_place;
			record_place = t3 + 2u;
			mem_write16(t3, ((uint32_t)(t2 >> 8) << 8) | (place & 0xFFu));
			t4 = high_score_words_left;
			high_score_words_left = t4 - 1u;
		} while (t4 != 1u);
		record_place -= 0x10u;
	}
	high_score_words_left = 3u;
	new_entry = new_high_score_ADDRESS;
	do
	{
		t5 = new_entry;
		new_entry = t5 + 2u;
		t6 = mem_read16(t5);
		place = t6;
		insert_place = (uint8_t)(t6 >> 8);
		t7 = record_place;
		record_place = t7 + 2u;
		mem_write16(t7, ((uint32_t)insert_place << 8) | (place & 0xFFu));
		t8 = high_score_words_left;
		high_score_words_left = t8 - 1u;
	} while (t8 != 1u);
	place = (place & 0xFFu) | ((uint32_t)insert_place << 8);
	return place;
}
