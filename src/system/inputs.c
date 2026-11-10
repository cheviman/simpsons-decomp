/**
 *    Name:        system/inputs.c
 *    Description: the coin slots, the credits and the players' controls, read at each IRQ
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Whether a coin went through the coin slot whose bit is in A (released after being held): queues the
   coin's sound and counts it in coins_inserted; carry when it did. */
void coin_inserted(uint16_t *p_coin_bit, uint32_t *p_carry)
{
	uint16_t coin_bit = (uint16_t)*p_coin_bit;
	uint32_t carry = *p_carry;
	uint8_t b = 0, inserted = 0;
	uint16_t command = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0;

	stack = coin_bit >> 8;
	t1 = ~(coin_inputs | coin_inputs_last) & coin_inputs_before & stack;
	inserted = t1;
	if (t1 == 0u)
	{
		carry = 0u;
		coin_bit = ((uint32_t)stack << 8) | inserted;
	}
	else
	{
		b = 2u;
		command = 0x4002u;
		carry = queue_sound_always(command);
		coins_inserted++;
		carry = 1u;
		coin_bit = ((uint32_t)stack << 8) | b;
	}
	*p_coin_bit = coin_bit;
	*p_carry = carry;
}

/* Counts a coin in the coin slot's record at U and gives the credits it is worth when enough coins are
   in: into the shared credits, or into the slot's own when each slot has its credits (the first credit
   of a slot may take more coins). */
uint16_t add_coin(uint16_t slot, uint8_t d)
{
	uint8_t b = 0, coins = 0, coins_needed = 0, first_credit_given = 0;
	uint16_t d_2 = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t8 = 0, t9 = 0, t10 = 0;
	uint16_t t7 = 0, t11 = 0;

	b = (uint8_t)d;
	t1 = mem_read8(slot + 2u);
	mem_write8(slot + 2u, t1 + 1u);
	if (separate_coin_slots == 0u)
	{
		t2 = mem_read8(slot + 3u);
		mem_write8(slot + 3u, t2 + 1u);
		t3 = mem_read8(slot + 2u);
		coins = t3;
		t4 = mem_read8(slot + 5u);
		if (t4 <= coins)
		{
			t5 = mem_read8(slot + 5u);
			mem_write8(slot + 2u, coins - t5);
			t6 = mem_read8(slot + 6u);
			t7 = t6 + credits;
			coins = (uint8_t)(t7 >> 8);
			b = (uint8_t)t7;
			credits = ((uint32_t)coins << 8) | b;
		}
		d_2 = ((uint32_t)coins << 8) | b;
		return d_2;
	}
	slot_1_counter_pulses++;
	coins_needed = slot_1_coins_per_credit;
	t8 = mem_read8(slot + 7u);
	first_credit_given = t8;
	if (t8 == 0u)
		coins_needed += first_credit_extra_coins;
	t9 = mem_read8(slot + 2u);
	if (coins_needed <= t9)
	{
		stack = coins_needed;
		t10 = mem_read8(slot + 2u);
		mem_write8(slot + 2u, t10 - stack);
		t11 = slot_1_credits_per_coins + mem_read16(slot);
		first_credit_given = (uint8_t)t11;
		mem_write16(slot, ((uint32_t)(t11 >> 8) << 8) | first_credit_given);
		coins_needed = 1u;
		mem_write8(slot + 7u, 1u);
	}
	d_2 = ((uint32_t)coins_needed << 8) | first_credit_given;
	return d_2;
}

/* Reads a player's controls from the port at U into its block at X, unless the attract runs. */
void read_controls(uint16_t controls, uint16_t port)
{
	if (in_attract != 0u)
		return;
	update_controls(controls, port);
}

/* Updates a player's controls block at X from the port at U: this frame's, last frame's, the ones newly
   pressed and the ones held. */
void update_controls(uint16_t controls, uint16_t port)
{
	uint8_t t1 = 0, t2 = 0;

	mem_write8(controls + 1u, mem_read8(controls));
	mem_write8(controls, ~mem_read8(port));
	t1 = mem_read8(controls + 1u);
	mem_write8(controls + 3u, t1 & mem_read8(controls));
	t2 = mem_read8(controls + 1u);
	mem_write8(controls + 2u, ~t2 & mem_read8(controls));
}
