/**
 *    Name:        machine.c
 *    Description: The Simpsons' board (Konami GX072) as the 053248 program sees it: memory map, banks, inputs,
 *                 interrupts, the EEPROM, the video chips' memories and registers
 *    Version:     0.1.0
 *    Created:     05-11-2026
 *    Modified:    05-11-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    Behavior follows MAME 0.289: konami/simpsons.cpp (main_map, eeprom_w, coin_counter_w, sound_interrupt_r,
 *    k052109_r/w, k053247_r/w, video_bank_select, object_dma, periodic_irq, dma_start, dma_end, banking_callback,
 *    tile_callback, machine_reset), konami/k052109.cpp (read, write, vblank_callback, device_reset),
 *    konami/k053246_k053247_k055673.cpp (k053246_r/w, k053246_set_objcha_line, k053246_is_irq_enabled,
 *    device_reset), konami/k053251.cpp (write), sound/k053260.cpp (main_read, main_write) and
 *    machine/eepromser.cpp and eeprom.cpp (the ER5911's serial interface and its timing). MAME's terms are in
 *    tools/core/konami/reference/mame/LICENSE.
 */
#include "simpsons/machine.h"

#include "game/data.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

simpsons_machine simpsons_board;

static uint64_t now(void)
{
	return simpsons_board.now ? simpsons_board.now() : simpsons_board.cycles;
}

/* ---------------------------------------------------------------------------------------------------------
   The ER5911, 128 cells of 8 bits: after CS goes up, a start bit, 2 bits of command and 9 of address on DI,
   each taken as CLK goes up; a read gives the cell's bits on DO, a write takes 8 bits more. A write keeps it
   busy (READY low) for 1750 us
   --------------------------------------------------------------------------------------------------------- */

enum
{
	EEPROM_IN_RESET, EEPROM_WAIT_FOR_START_BIT, EEPROM_WAIT_FOR_COMMAND, EEPROM_READING_DATA,
	EEPROM_WAIT_FOR_DATA, EEPROM_WAIT_FOR_COMPLETION
};
enum
{
	EEPROM_INVALID, EEPROM_READ, EEPROM_WRITE, EEPROM_LOCK, EEPROM_UNLOCK, EEPROM_ERASE_ALL
};
enum { CS_RISING, CS_FALLING, CLK_RISING, CLK_FALLING };

#define EEPROM_COMMAND_ADDRESS_BITS  9
#define EEPROM_DATA_BITS             8
/* MAME's times, 1750 us for a write and 8000 us to erase it all, end at the first cycle at or past them: a
   cycle of the 053248 is 333333333332 attoseconds there, so 5250 cycles fall short of 1750 us */
#define EEPROM_WRITE_BUSY            (SIMPSONS_EEPROM_WRITE_CYCLES + 1u)
#define EEPROM_ERASE_ALL_BUSY        24001u

static bool eeprom_ready(void)
{
	return now() >= simpsons_board.eeprom.busy_until;
}

static void eeprom_execute_command(simpsons_eeprom *eeprom)
{
	/* the ER5911's commands: 01 and 11 write (it has no erase), 10 reads, 00 takes two more bits */
	eeprom->command = EEPROM_INVALID;
	eeprom->address = eeprom->command_address & ((1u << EEPROM_COMMAND_ADDRESS_BITS) - 1u);
	switch (eeprom->command_address >> EEPROM_COMMAND_ADDRESS_BITS)
	{
	case 0:
		switch (eeprom->address >> (EEPROM_COMMAND_ADDRESS_BITS - 2))
		{
		case 0: eeprom->command = EEPROM_LOCK; break;
		case 2: eeprom->command = EEPROM_ERASE_ALL; break;
		case 3: eeprom->command = EEPROM_UNLOCK; break;
		default: break;
		}
		eeprom->address = 0;
		break;
	case 2:
		eeprom->command = EEPROM_READ;
		break;
	default:
		eeprom->command = EEPROM_WRITE;
		break;
	}
	eeprom->bits = 0;
	switch (eeprom->command)
	{
	case EEPROM_READ:
		/* the dummy 0 before the first clock */
		eeprom->shift = 0;
		eeprom->state = EEPROM_READING_DATA;
		break;
	case EEPROM_WRITE:
		eeprom->shift = 0;
		eeprom->state = EEPROM_WAIT_FOR_DATA;
		break;
	case EEPROM_LOCK:
		eeprom->locked = true;
		eeprom->state = EEPROM_IN_RESET;
		break;
	case EEPROM_UNLOCK:
		eeprom->locked = false;
		eeprom->state = EEPROM_IN_RESET;
		break;
	case EEPROM_ERASE_ALL:
		if (eeprom->locked)
		{
			eeprom->state = EEPROM_IN_RESET;
			break;
		}
		memset(eeprom->data, 0xFF, sizeof(eeprom->data));
		eeprom->busy_until = now() + EEPROM_ERASE_ALL_BUSY;
		eeprom->state = EEPROM_WAIT_FOR_COMPLETION;
		break;
	default:
		/* (MAME stops the machine here: the ER5911 has no such command) */
		eeprom->state = EEPROM_IN_RESET;
		break;
	}
}

static void eeprom_event(int event)
{
	simpsons_eeprom *eeprom = &simpsons_board.eeprom;

	switch (eeprom->state)
	{
	case EEPROM_IN_RESET:
		if (event == CS_RISING)
			eeprom->state = EEPROM_WAIT_FOR_START_BIT;
		break;
	case EEPROM_WAIT_FOR_START_BIT:
		/* (a clock at the very moment CS goes up is not one) */
		if (event == CLK_RISING && eeprom->di && eeprom_ready() && now() > eeprom->cs_rose_at)
		{
			eeprom->command_address = eeprom->bits = 0;
			eeprom->state = EEPROM_WAIT_FOR_COMMAND;
		}
		else if (event == CS_FALLING)
			eeprom->state = EEPROM_IN_RESET;
		break;
	case EEPROM_WAIT_FOR_COMMAND:
		if (event == CLK_RISING)
		{
			eeprom->command_address = (eeprom->command_address << 1) | eeprom->di;
			if (++eeprom->bits == 2u + EEPROM_COMMAND_ADDRESS_BITS)
				eeprom_execute_command(eeprom);
		}
		else if (event == CS_FALLING)
			eeprom->state = EEPROM_IN_RESET;
		break;
	case EEPROM_READING_DATA:
		if (event == CLK_RISING)
		{
			/* the cell's bits from bit 31, then ones (one cell a command: no streaming) */
			if (eeprom->bits++ == 0)
				eeprom->shift = (uint32_t)eeprom->data[eeprom->address & (SIMPSONS_EEPROM_SIZE - 1u)] << 24;
			else
				eeprom->shift = (eeprom->shift << 1) | 1u;
		}
		else if (event == CS_FALLING)
			eeprom->state = EEPROM_IN_RESET;
		break;
	case EEPROM_WAIT_FOR_DATA:
		if (event == CLK_RISING)
		{
			eeprom->shift = (eeprom->shift << 1) | eeprom->di;
			if (++eeprom->bits == EEPROM_DATA_BITS)
			{
				if (eeprom->locked)
					eeprom->state = EEPROM_IN_RESET;
				else
				{
					/* (an address past the 128 cells wraps: MAME writes past its array there) */
					eeprom->data[eeprom->address & (SIMPSONS_EEPROM_SIZE - 1u)] = (uint8_t)eeprom->shift;
					eeprom->busy_until = now() + EEPROM_WRITE_BUSY;
					eeprom->state = EEPROM_WAIT_FOR_COMPLETION;
				}
			}
		}
		else if (event == CS_FALLING)
			eeprom->state = EEPROM_IN_RESET;
		break;
	case EEPROM_WAIT_FOR_COMPLETION:
		if (event == CS_FALLING)
			eeprom->state = EEPROM_IN_RESET;
		break;
	default:
		break;
	}
}

/* 1FC2's EEPROM lines, as MAME's EEPROMOUT port gives them: CS (bit 3), then CLK (bit 4), then DI (bit 7); a
   line that does not change does nothing */
static void eeprom_lines(uint8_t data)
{
	simpsons_eeprom *eeprom = &simpsons_board.eeprom;
	const bool cs = (data & 0x08) != 0, clk = (data & 0x10) != 0;

	if (cs != eeprom->cs)
	{
		eeprom->cs = cs;
		if (cs)
			eeprom->cs_rose_at = now();
		eeprom_event(cs ? CS_RISING : CS_FALLING);
	}
	if (clk != eeprom->clk)
	{
		eeprom->clk = clk;
		eeprom_event(clk ? CLK_RISING : CLK_FALLING);
	}
	eeprom->di = (data & 0x80) != 0;
}

/* 1F81: the test switch, DO (high but while a read shifts a 0 out) and READY, the other bits high */
static uint8_t test_port(void)
{
	const simpsons_eeprom *eeprom = &simpsons_board.eeprom;
	const bool data_out = eeprom->state != EEPROM_READING_DATA || (eeprom->shift & 0x80000000u) != 0;

	return (uint8_t)((simpsons_board.test & (uint8_t)~(SIMPSONS_TEST_EEPROM_DO | SIMPSONS_TEST_EEPROM_READY))
		| (data_out ? SIMPSONS_TEST_EEPROM_DO : 0) | (eeprom_ready() ? SIMPSONS_TEST_EEPROM_READY : 0));
}

/* ---------------------------------------------------------------------------------------------------------
   K052109
   --------------------------------------------------------------------------------------------------------- */

static uint8_t k052109_read(uint32_t offset)
{
	if (!simpsons_board.read_char_rom)
		return simpsons_board.tile_ram[offset];
	{
		/* the tile ROM through the RAM's window: 32 bytes a tile, the tile from the offset and the ROM subbank
		   register as the layers' tile callback takes them (code, color bits 0-5, bank) */
		const uint32_t color = simpsons_board.rom_subbank;
		const uint32_t bank = (uint32_t)(simpsons_board.char_rom_bank[(color & 0x0Cu) >> 2] >> 2)
			| (uint32_t)(simpsons_board.char_rom_bank_2[(color & 0x0Cu) >> 2] >> 2);
		const uint32_t code = ((offset & 0x1FFFu) >> 5) | ((color & 0x3Fu) << 8) | (bank << 14);

		return game_tiles[((code << 5) + (offset & 0x1Fu)) & (GAME_TILES_SIZE - 1u)];
	}
}

static void k052109_write(uint32_t offset, uint8_t data)
{
	simpsons_board.tile_ram[offset] = data;
	if ((offset & 0x1FFFu) < 0x1800u)
		return;
	/* the registers that latch (the scroll and the others stay in the RAM, where the video reads them) */
	switch (offset)
	{
	case 0x1C00u:
		simpsons_board.address_map = data;
		break;
	case 0x1C80u:
		simpsons_board.scroll_control = data;
		break;
	case 0x1D00u:
		/* bit 2 enables the IRQ at VBLANK; clearing it takes the IRQ back */
		if (~data & simpsons_board.irq_control & 0x04u)
			simpsons_board.irq = false;
		simpsons_board.irq_control = data;
		break;
	case 0x1D80u:
		simpsons_board.char_rom_bank[0] = data & 0x0F;
		simpsons_board.char_rom_bank[1] = (data >> 4) & 0x0F;
		break;
	case 0x1E00u:
	case 0x3E00u:
		simpsons_board.rom_subbank = data;
		break;
	case 0x1E80u:
		simpsons_board.tile_flip = data & 0x07;
		break;
	case 0x1F00u:
		simpsons_board.char_rom_bank[2] = data & 0x0F;
		simpsons_board.char_rom_bank[3] = (data >> 4) & 0x0F;
		break;
	case 0x3D80u:
		simpsons_board.char_rom_bank_2[0] = data & 0x0F;
		simpsons_board.char_rom_bank_2[1] = (data >> 4) & 0x0F;
		break;
	case 0x3F00u:
		simpsons_board.char_rom_bank_2[2] = data & 0x0F;
		simpsons_board.char_rom_bank_2[3] = (data >> 4) & 0x0F;
		break;
	default:
		break;
	}
}

/* ---------------------------------------------------------------------------------------------------------
   The board
   --------------------------------------------------------------------------------------------------------- */

void simpsons_reset(void)
{
	uint32_t offset;
	int player;

	memset(&simpsons_board, 0, sizeof(simpsons_board));
	/* the K052109's reset writes 0 to its registers 1C00-1F00 (all zero already) */
	for (offset = 0x1C00u; offset <= 0x1F00u; offset += 0x80u)
		k052109_write(offset, 0);
	memcpy(simpsons_board.eeprom.data, game_eeprom, SIMPSONS_EEPROM_SIZE);
	simpsons_board.eeprom.locked = true;
	simpsons_board.coins = 0xFF;
	simpsons_board.test = SIMPSONS_TEST_IDLE;
	for (player = 0; player < 4; player++)
		simpsons_board.players[player] = 0xFF;
}

void simpsons_set_lines(uint8_t data)
{
	simpsons_board.bank = data & 0x3F;
}

int32_t simpsons_program_offset(uint16_t address)
{
	if (address >= 0x8000u)
		return (int32_t)(GAME_PROGRAM_SIZE - 0x8000u + (address - 0x8000u));
	if (address >= 0x6000u)
		return (int32_t)((uint32_t)simpsons_board.bank * 0x2000u + (address - 0x6000u));
	return -1;
}

/* 1FC8-1FC9: the sprite ROM, at the address registers 6, 7 and 4 give, while OBJCHA is on */
static uint8_t sprite_rom_read(uint16_t address)
{
	const uint8_t *registers = simpsons_board.sprite_registers;

	if (!simpsons_board.read_sprite_rom)
		return 0;
	return game_sprites[(((uint32_t)registers[6] << 17) | ((uint32_t)registers[7] << 9) | ((uint32_t)registers[4] << 1)
		| ((address & 1u) ^ 1u)) & (GAME_SPRITES_SIZE - 1u)];
}

/* A read of the program that the assets do not give (code): the game stops, saying where */
static void program_not_given(int32_t place, uint16_t address)
{
	fprintf(stderr, "The game read %06X (%04X, bank %02X) in frame %llu: code, which its assets do not give\n",
		(unsigned)place, address, simpsons_board.bank, (unsigned long long)simpsons_board.frame);
	exit(4);
}

uint8_t simpsons_read(uint16_t address)
{
	if (address >= 0x6000u)
	{
		const int32_t place = simpsons_program_offset(address);

		if (simpsons_board.program_given && !simpsons_board.program_given[place])
			program_not_given(place, address);
		return game_program[place];
	}
	if (address >= 0x4000u)
		return *simpsons_work_ram_byte(address);
	if (address >= 0x2000u)
	{
		if (simpsons_board.video_bank & 0x02u)
			return address < 0x3000u ? simpsons_board.sprite_ram[address - 0x2000u]
				: simpsons_board.extra_ram[address - 0x3000u];
		return k052109_read(address);
	}
	if (address < 0x1000u && (simpsons_board.video_bank & 0x01u))
		return simpsons_board.palette[address];
	switch (address)
	{
	case 0x1F80u: return simpsons_board.coins;
	case 0x1F81u:
		if (simpsons_board.frame_timing)
			simpsons_board.cycles += SIMPSONS_POLL_CYCLES;
		return test_port();
	case 0x1F90u: case 0x1F91u: case 0x1F92u: case 0x1F93u: return simpsons_board.players[address - 0x1F90u];
	case 0x1FC4u:
		/* the Z80's IRQ, held until it takes it */
		simpsons_board.sound_irqs++;
		if (simpsons_board.sound_sync)
			simpsons_board.sound_sync();
		if (simpsons_board.sound_irq)
			simpsons_board.sound_irq();
		return 0;
	case 0x1FC6u: case 0x1FC7u:
		if (simpsons_board.frame_timing)
			simpsons_board.cycles += SIMPSONS_SOUND_POLL_CYCLES;
		if (simpsons_board.sound_sync)
			simpsons_board.sound_sync();
		return simpsons_board.sound_ports[2u + (address & 1u)];
	case 0x1FC8u: case 0x1FC9u: return sprite_rom_read(address);
	case 0x1FCAu:
		simpsons_board.watchdog_resets++;
		return 0;
	default:
		return k052109_read(address);
	}
}

/* 1FC0: the coin counters, the tile ROM's window (bit 3), the sprite ROM's (bit 5 low) */
static void control_write(uint8_t data)
{
	int counter;

	for (counter = 0; counter < 2; counter++)
		if ((data >> counter) & 1u && !((simpsons_board.control >> counter) & 1u))
			simpsons_board.coin_counters[counter]++;
	simpsons_board.read_char_rom = (data & 0x08u) != 0;
	simpsons_board.read_sprite_rom = (data & 0x20u) == 0;
	simpsons_board.control = data;
}

/* 1FC2: the EEPROM's lines, the palette's and the sprite RAM's views (bits 0-1), the FIRQ's enable (bit 2);
   FF does nothing */
static void eeprom_write(uint8_t data)
{
	if (data == 0xFFu)
		return;
	simpsons_board.eeprom_out = data;
	eeprom_lines(data);
	simpsons_board.video_bank = data & 0x03u;
	simpsons_board.firq_enabled = (data & 0x04u) != 0;
	if (!simpsons_board.firq_enabled)
		simpsons_board.firq = false;
}

void simpsons_write(uint16_t address, uint8_t data)
{
	if (simpsons_board.write_watch)
		simpsons_board.write_watch(address, data);
	if (address >= 0x6000u)
	{
		simpsons_board.unmapped_writes++;
		return;
	}
	if (address >= 0x4000u)
	{
		*simpsons_work_ram_byte(address) = data;
		return;
	}
	if (address >= 0x2000u)
	{
		if (!(simpsons_board.video_bank & 0x02u))
			k052109_write(address, data);
		else if (address < 0x3000u)
			simpsons_board.sprite_ram[address - 0x2000u] = data;
		else
			simpsons_board.extra_ram[address - 0x3000u] = data;
		return;
	}
	if (address < 0x1000u && (simpsons_board.video_bank & 0x01u))
	{
		simpsons_board.palette[address] = data;
		return;
	}
	if (address >= 0x1FA0u && address <= 0x1FA7u)
	{
		simpsons_board.sprite_registers[address - 0x1FA0u] = data;
		return;
	}
	if (address >= 0x1FB0u && address <= 0x1FBFu)
	{
		simpsons_board.priority[address & 0x0Fu] = data & 0x3Fu;
		return;
	}
	switch (address)
	{
	case 0x1FC0u:
		control_write(data);
		return;
	case 0x1FC2u:
		/* (frame timing: the EEPROM's lines take time, which the ER5911's start bit needs after CS goes up) */
		if (simpsons_board.frame_timing)
			simpsons_board.cycles += SIMPSONS_POLL_CYCLES;
		eeprom_write(data);
		return;
	case 0x1FC6u: case 0x1FC7u:
		if (simpsons_board.sound_sync)
			simpsons_board.sound_sync();
		simpsons_board.sound_ports[address & 1u] = data;
		return;
	default:
		k052109_write(address, data);
		return;
	}
}

/* The sprite DMA: each of the 256 sprites the program shows (the first word's bit 15, a priority other than 0)
   to the K053247's RAM, one after another; then the first word of the rest cleared */
static void object_dma(void)
{
	const uint8_t *source = simpsons_board.sprite_ram;
	uint8_t *target = simpsons_board.object_ram;
	int sprite, inactive = 256;

	for (sprite = 0; sprite < 256; sprite++, source += 16)
		if ((source[0] & 0x80u) && source[1])
		{
			memcpy(target, source, 16);
			target += 16;
			inactive--;
		}
	for (; inactive; inactive--, target += 16)
		target[0] = target[1] = 0;
}

void simpsons_vblank_start(void)
{
	simpsons_board.frame++;
	if (simpsons_board.irq_control & 0x04u)
		simpsons_board.irq = true;
	if (simpsons_board.sprite_registers[5] & 0x10u)
	{
		object_dma();
		simpsons_board.dma_start_at = simpsons_board.cycles + SIMPSONS_DMA_START_CYCLES;
		simpsons_board.dma_end_at = simpsons_board.cycles + SIMPSONS_DMA_END_CYCLES;
	}
}

void simpsons_dma_start(void)
{
	simpsons_board.dma_start_at = 0;
	if (simpsons_board.firq_enabled)
		simpsons_board.firq = true;
}

void simpsons_dma_end(void)
{
	simpsons_board.dma_end_at = 0;
	simpsons_board.firq = false;
}

void simpsons_frame_vblank(bool irq_masked)
{
	const uint64_t vblank = simpsons_board.frame * SIMPSONS_FRAME_CYCLES
		+ (uint64_t)SIMPSONS_VBLANK_START * SIMPSONS_LINE_CYCLES;

	if (simpsons_board.cycles < vblank)
		simpsons_board.cycles = vblank;
	simpsons_board.firq = simpsons_board.firq_due = false;
	simpsons_vblank_start();
	if (simpsons_board.dma_start_at)
	{
		simpsons_board.dma_start_at = simpsons_board.dma_end_at = 0;
		if (simpsons_board.irq && !irq_masked)
			simpsons_board.firq_due = true;
		else
			simpsons_board.firq = simpsons_board.firq_enabled;
	}
}

void simpsons_firq_point(void)
{
	if (!simpsons_board.firq_due)
		return;
	simpsons_board.firq_due = false;
	simpsons_board.firq = simpsons_board.firq_enabled;
}

static uint64_t hash_bytes(const void *data, size_t size, uint64_t hash)
{
	const uint8_t *bytes = (const uint8_t *)data;
	size_t index;

	for (index = 0; index < size; index++)
		hash = (hash ^ bytes[index]) * 0x100000001b3ull;
	return hash;
}

uint64_t simpsons_state_hash(void)
{
	const simpsons_machine *board = &simpsons_board;
	const uint8_t registers[] = {
		board->char_rom_bank[0], board->char_rom_bank[1], board->char_rom_bank[2], board->char_rom_bank[3],
		board->char_rom_bank_2[0], board->char_rom_bank_2[1], board->char_rom_bank_2[2], board->char_rom_bank_2[3],
		board->rom_subbank, board->irq_control, board->scroll_control, board->address_map, board->tile_flip,
		board->read_char_rom, board->read_sprite_rom, board->bank, board->video_bank, board->firq_enabled,
		board->control, board->eeprom_out, board->sound_ports[0], board->sound_ports[1], board->sound_ports[2],
		board->sound_ports[3]
	};
	uint64_t hash = 0xcbf29ce484222325ull;
	uint32_t address;

	/* (the work RAM in the order of its addresses, its stack left out) */
	for (address = SIMPSONS_WORK_RAM; address < SIMPSONS_WORK_RAM + SIMPSONS_WORK_RAM_SIZE; address++)
		if (address < SIMPSONS_STACK_LOW || address >= SIMPSONS_STACK_TOP)
			hash = (hash ^ *simpsons_work_ram_byte((uint16_t)address)) * 0x100000001b3ull;
	hash = hash_bytes(board->extra_ram, sizeof(board->extra_ram), hash);
	hash = hash_bytes(board->palette, sizeof(board->palette), hash);
	hash = hash_bytes(board->tile_ram, sizeof(board->tile_ram), hash);
	hash = hash_bytes(board->sprite_ram, sizeof(board->sprite_ram), hash);
	hash = hash_bytes(board->object_ram, sizeof(board->object_ram), hash);
	hash = hash_bytes(board->sprite_registers, sizeof(board->sprite_registers), hash);
	hash = hash_bytes(board->priority, sizeof(board->priority), hash);
	hash = hash_bytes(board->eeprom.data, sizeof(board->eeprom.data), hash);
	return hash_bytes(registers, sizeof(registers), hash);
}
