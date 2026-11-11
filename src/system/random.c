/**
 *    Name:        system/random.c
 *    Description: the random number
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Steps the random number on: five times it plus 3711. */
void next_random(void)
{
	uint16_t old_random = 0;
	uint16_t stack = 0;

	old_random = AT16(random_number, -1);
	stack = old_random;
	old_random += AT16(random_number, -1);
	AT16(random_number, -1) = old_random;
	AT16(random_number, -1) = old_random + AT16(random_number, -1) + stack + 0x3711u;
}
