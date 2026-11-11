/**
 *    Name:        game/score.c
 *    Description: the players' scores and the high score table
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
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
	uint8_t low = 0, score_low = 0, low_binary_sum = 0, low_digits = 0, score_high = 0, high_binary_sum = 0;

	score_addition = score_additions_ADDRESS + (int8_t)((uint32_t)addition << 1);
	low = SCORE_ADDITION(score_addition)->low;
	addition_low = low;
	score_low = mem_read8(score + 1u);
	low_binary_sum = addition_low + score_low;
	half_carry = ((addition_low ^ score_low ^ low_binary_sum) >> 4) & 1u;
	carry = (uint8_t)(addition_low + score_low) < addition_low;
	low_sum = low_binary_sum;
	low_digits = konami_daa(low_sum, half_carry, carry);
	carry = konami_daa_carry(low_sum, half_carry, carry);
	mem_write8(score + 1u, low_digits);
	high = SCORE_ADDITION(score_addition)->high;
	score_high = mem_read8(score);
	high_binary_sum = high + score_high + carry;
	half_carry = ((high ^ score_high ^ high_binary_sum) >> 4) & 1u;
	carry = konami_carry_add8(high, score_high, carry);
	mem_write8(score, konami_daa(high_binary_sum, half_carry, carry));
}

/* Finds the place of the score D in the high score table (A, 0-9; carry when it gets in). */
void high_score_rank(uint16_t *p_score, uint32_t *p_in_high_scores)
{
	uint16_t score = (uint16_t)*p_score;
	uint32_t in_high_scores = *p_in_high_scores;
	uint8_t score_low_byte = 0;
	uint16_t high_score_address = 0;
	uint16_t score_compared = 0;

	ranked_score = score;
	high_score_address = high_scores_ADDRESS + 0x3u;
	high_score_place_found = 0u;
	for (;;)
	{
		score_compared = ranked_score;
		score_low_byte = (uint8_t)score_compared;
		if (mem_read16(high_score_address) <= (uint16_t)(((uint32_t)(score_compared >> 8) << 8) | (score_low_byte & 0xFFu)))
		{
			in_high_scores = 1u;
			score = (score_low_byte & 0xFFu) | ((uint32_t)high_score_place_found << 8);
			break;
		}
		high_score_address += 8u;
		high_score_place_found++;
		if (high_score_place_found == 0xAu)
		{
			in_high_scores = 0u;
			score = (score_low_byte & 0xFFu) | ((uint32_t)high_score_place_found << 8);
			break;
		}
	}
	*p_score = score;
	*p_in_high_scores = in_high_scores;
}

/* Puts the initials and score at 48F0 into the high score table at place A, moving the lower ones down. */
uint16_t insert_high_score(uint16_t place)
{
	uint8_t insert_place = 0;
	uint16_t new_entry = 0, record_place = 0;
	uint8_t moved_place = 0, words_left = 0, words_left_2 = 0;
	uint16_t moved_word = 0, word_place = 0, entry_word_place = 0, entry_word = 0, word_place_2 = 0;

	new_high_score_place = place >> 8;
	high_score_moved_place = 9u;
	record_place = high_scores_ADDRESS + 0x48u;
	for (;;)
	{
		insert_place = new_high_score_place;
		if (insert_place == high_score_moved_place)
			break;
		moved_place = high_score_moved_place - 1u;
		high_score_moved_place = moved_place;
		if ((int8_t)moved_place < 0)
		{
			place = (place & 0xFFu) | ((uint32_t)insert_place << 8);
			return place;
		}
		high_score_words_left = 4u;
		do
		{
			moved_word = mem_read16(record_place - 8u);
			place = moved_word;
			word_place = record_place;
			record_place = word_place + 2u;
			mem_write16(word_place, ((uint32_t)(moved_word >> 8) << 8) | (place & 0xFFu));
			words_left = high_score_words_left;
			high_score_words_left = words_left - 1u;
		} while (words_left != 1u);
		record_place -= 0x10u;
	}
	high_score_words_left = 3u;
	new_entry = new_high_score_ADDRESS;
	do
	{
		entry_word_place = new_entry;
		new_entry = entry_word_place + 2u;
		entry_word = mem_read16(entry_word_place);
		place = entry_word;
		insert_place = (uint8_t)(entry_word >> 8);
		word_place_2 = record_place;
		record_place = word_place_2 + 2u;
		mem_write16(word_place_2, ((uint32_t)insert_place << 8) | (place & 0xFFu));
		words_left_2 = high_score_words_left;
		high_score_words_left = words_left_2 - 1u;
	} while (words_left_2 != 1u);
	place = (place & 0xFFu) | ((uint32_t)insert_place << 8);
	return place;
}
