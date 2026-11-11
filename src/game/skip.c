/**
 *    Name:        game/skip.c
 *    Description: whether a player's button skips what is on (a story)
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* After waiting A frames, whether a player in the game newly presses attack or jump (carry), which skips
   a story. */
void check_skip(uint16_t wait, uint16_t *p_presses_addresses, uint32_t *p_carry)
{
	uint16_t presses_addresses = (uint16_t)*p_presses_addresses;
	uint32_t carry = *p_carry;
	uint8_t player_bits = 0;

	if (skip_wait <= wait >> 8)
	{
		skip_wait++;
		carry = 0u;
	}
	else
	{
		skip_player = 0u;
		player_bits = players_playing;
		for (;;)
		{
			if (skip_player == 4u)
			{
				carry = 0u;
				break;
			}
			if ((player_bits & 1u) != 0u)
			{
				presses_addresses = player_presses_ADDRESS;
				if ((mem_read8(player_presses[(int8_t)((uint8_t)((uint32_t)skip_player << 1)) / 2]) & 0x30u) != 0u)
				{
					skip_wait = 0u;
					carry = 1u;
					break;
				}
			}
			player_bits = player_bits >> 1;
			skip_player++;
		}
	}
	*p_presses_addresses = presses_addresses;
	*p_carry = carry;
}
