/**
 *    Name:        board_code.c
 *    Description: the code the board puts in place of the game's (tools/game_profile.py's REPLACED_CODE)
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    06-11-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    The game's code that adds up the board's program ROM chips, which the game does not have: what it finds is
 *    what a board with good chips gives, and it leaves the registers, the flags and the memory as the game's code
 *    does where anything reads them.
 */
#include "konami/cpu.h"
#include "simpsons/machine.h"

#define SUM             0xFAu       /* the direct page word the sum goes to (<$FA) */
#define WINDOW          0x6000u
#define BANK_BYTES      0x2000u

/* The boot's RAM ROM CHECK, chip by chip (078C1E-078D1D): each bank of a chip in turn in the window, added up by
   078E5B (X 6000, U 2000), the fixed program first for the second chip (078E63: X 8000, U 8000, the sum cleared),
   and the chip's sum compared with the one the program keeps for it (CMPD $E423...) and printed (078DBD) */
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

static uint32_t read16(uint32_t address)
{
	return mem_read8(address) << 8 | mem_read8((address + 1u) & 0xFFFFu);
}

/* 078E68-078E79: adds the U bytes from X to the word <$FA ("LDD <$FA; ADDB ,X+; ADCA #$00; STD <$FA; LEAU -1,U;
   CMPU #$0000; BNE"), and leaves X past them, U 0, D the sum, the flags of CMPU with U 0 (Z), and H the last ADCA's.
   After the last bank of a chip the sum is the chip's good one, and the last byte added (its last byte, which the
   game's data holds) gives H; along the way the sum stays as it was: no one reads it before the chip's last bank
   (the stack bytes the loop's PUSHS leaves of it, the next calls overwrite). */
void sum_rom_bytes(void)
{
	const uint32_t at = (cpu.dp << 8 | SUM) & 0xFFFFu;
	uint32_t sum = read16(at);

	if (cpu.x == WINDOW && cpu.u == BANK_BYTES)
		for (size_t chip = 0; chip < sizeof(k_chips) / sizeof(k_chips[0]); chip++)
			if (simpsons_board.bank == k_chips[chip].last_bank)
			{
				const uint32_t last = mem_read8(WINDOW + BANK_BYTES - 1u);
				const uint32_t before = (read16(k_chips[chip].good_sum) - last) & 0xFFFFu;
				const uint32_t carry = (before & 0xFFu) + last > 0xFFu;

				sum = read16(k_chips[chip].good_sum);
				cpu.h = (uint8_t)(((before >> 8) & 0x0Fu) + carry > 0x0Fu);
			}
	mem_write8(at, (uint8_t)(sum >> 8));
	mem_write8((at + 1u) & 0xFFFFu, (uint8_t)sum);
	cpu.a = sum >> 8;
	cpu.b = sum & 0xFFu;
	cpu.x = (cpu.x + cpu.u) & 0xFFFFu;
	cpu.u = 0;
	cpu.n = 0;
	cpu.z = 1;
	cpu.v = 0;
	cpu.c = 0;
}
