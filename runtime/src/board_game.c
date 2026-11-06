/**
 *    Name:        board_game.c
 *    Description: the code the board puts in place of the decompiled game's (runtime/replaced.txt)
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    06-11-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    The boot's RAM ROM CHECK adds up the program's chips, which the game does not have (its data is the assets', its
 *    code is C): the board gives what good chips add up to. The decompiled original stays in the game's C as
 *    original_add_rom_bytes (BOARD_ORIGINAL), which nothing calls. The translation scaffold has its own
 *    (runtime/src/board_code.c), which leaves the 053248's registers as the original does.
 */
#include "game.h"

#define SUM             0x48FAu     /* the word the sum goes to (<$FA) */
#define WINDOW          0x6000u
#define BANK_BYTES      0x2000u
#define WATCHDOG        0x1FCAu

/* The boot's RAM ROM CHECK, chip by chip (078C1E-078D1D): each bank of a chip in turn in the window, added up by
   add_rom_bytes (X 6000, U 2000), the fixed program first for the second chip (X 8000, U 8000, from a sum of 0), and
   the chip's sum compared with the one the program keeps for it (E423...) */
static const struct
{
	uint8_t last_bank;          /* the chip's bank added up last */
	uint16_t good_sum;          /* where the program keeps its sum */
} k_chips[] = {
	{ 0x2F, 0xE423 },           /* banks 20-2F */
	{ 0x3B, 0xE425 },           /* 8000-FFFF and banks 30-3B */
	{ 0x0F, 0xE427 },           /* banks 00-0F */
	{ 0x1F, 0xE429 },           /* banks 10-1F */
};

/* Adds the 'u' bytes from 'x' on to the word at <$FA>, then kicks the watchdog. After the last bank of a chip the
   sum is the chip's good one; along the way it stays as it was: no one reads it before the chip's last bank */
void add_rom_bytes(uint16_t x, uint16_t u)
{
	if (x == WINDOW && u == BANK_BYTES)
		for (size_t chip = 0; chip < sizeof(k_chips) / sizeof(k_chips[0]); chip++)
			if (simpsons_board.bank == k_chips[chip].last_bank)
				RAM16(SUM) = (uint16_t)DATA16(k_chips[chip].good_sum);
	(void)io_read8(WATCHDOG);
}
