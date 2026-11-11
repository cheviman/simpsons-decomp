/**
 *    Name:        system/inputs.c
 *    Description: the coin slots, the credits and the players' controls, read at each IRQ
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
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
	uint8_t released_coin_bits = 0;

	stack = coin_bit >> 8;
	released_coin_bits = ~(coin_inputs | coin_inputs_last) & coin_inputs_before & stack;
	inserted = released_coin_bits;
	if (released_coin_bits == 0u)
	{
		carry = 0u;
		coin_bit = ((uint32_t)stack << 8) | inserted;
	}
	else
	{
		b = 2u;
		command = 0x4002u;
		queue_sound_always(command);
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
uint16_t add_coin(uint16_t slot, uint8_t coin_bit)
{
	uint8_t b = 0, coins = 0, coins_needed = 0, first_credit_given = 0;
	uint16_t d = 0, d_2 = 0;
	uint8_t stack = 0;
	uint8_t coins_before = 0, pulses_before = 0, slot_coins = 0, credit_price = 0, credit_price_2 = 0, credit_gain = 0, given_already = 0, slot_coins_2 = 0, slot_coins_3 = 0;
	uint16_t new_credits = 0, new_slot_credits = 0;

	b = (uint8_t)coin_bit;
	coins_before = COIN_SLOT(slot)->coins;
	COIN_SLOT(slot)->coins = coins_before + 1u;
	if (separate_coin_slots == 0u)
	{
		pulses_before = COIN_SLOT(slot)->counter_pulses;
		COIN_SLOT(slot)->counter_pulses = pulses_before + 1u;
		slot_coins = COIN_SLOT(slot)->coins;
		coins = slot_coins;
		credit_price = COIN_SLOT(slot)->coins_per_credit;
		if (credit_price <= coins)
		{
			credit_price_2 = COIN_SLOT(slot)->coins_per_credit;
			COIN_SLOT(slot)->coins = coins - credit_price_2;
			credit_gain = COIN_SLOT(slot)->credits_per_coins;
			new_credits = credit_gain + credits;
			coins = (uint8_t)(new_credits >> 8);
			b = (uint8_t)new_credits;
			credits = ((uint32_t)coins << 8) | b;
		}
		d = ((uint32_t)coins << 8) | b;
		return d;
	}
	slot_1_counter_pulses++;
	coins_needed = slot_1_coins_per_credit;
	given_already = COIN_SLOT(slot)->credit_given;
	first_credit_given = given_already;
	if (given_already == 0u)
		coins_needed += first_credit_extra_coins;
	slot_coins_2 = COIN_SLOT(slot)->coins;
	if (coins_needed <= slot_coins_2)
	{
		stack = coins_needed;
		slot_coins_3 = COIN_SLOT(slot)->coins;
		COIN_SLOT(slot)->coins = slot_coins_3 - stack;
		new_slot_credits = slot_1_credits_per_coins + COIN_SLOT(slot)->own_credits;
		first_credit_given = (uint8_t)new_slot_credits;
		COIN_SLOT(slot)->own_credits = ((uint32_t)(new_slot_credits >> 8) << 8) | first_credit_given;
		coins_needed = 1u;
		COIN_SLOT(slot)->credit_given = 1u;
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
	uint8_t last_controls = 0, last_controls_2 = 0;

	PLAYER_INPUT(controls)->last = PLAYER_INPUT(controls)->now;
	PLAYER_INPUT(controls)->now = ~mem_read8(port);
	last_controls = PLAYER_INPUT(controls)->last;
	PLAYER_INPUT(controls)->held = last_controls & PLAYER_INPUT(controls)->now;
	last_controls_2 = PLAYER_INPUT(controls)->last;
	PLAYER_INPUT(controls)->pressed = ~last_controls_2 & PLAYER_INPUT(controls)->now;
}
