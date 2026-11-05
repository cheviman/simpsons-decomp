/**
 *    Name:        sound.c
 *    Description: The Simpsons' sound board as the Z80 program sees it: its memory map, the bank, the chips
 *    Version:     0.1.0
 *    Created:     05-11-2026
 *    Modified:    05-11-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    Behavior follows MAME 0.289: konami/simpsons.cpp (z80_map, z80_bankswitch_w, z80_arm_nmi_w, the audio
 *    bank's entries) and sound/k053260.cpp (read and write of its ports). MAME's terms are in
 *    tools/core/konami/reference/mame/LICENSE.
 */
#include "simpsons/machine.h"

#include "game/data.h"

int32_t simpsons_sound_offset(uint16_t address)
{
	if (address < 0x8000u)
		return address;
	if (address < 0xC000u)
	{
		/* entries 0-2 are the region's 10000, then 4000 more each */
		const uint32_t entry = simpsons_board.sound_bank;
		const uint32_t base = 0x10000u + (entry < 2u ? 0u : (entry - 2u) * 0x4000u);

		return (int32_t)(base + (address - 0x8000u));
	}
	return -1;
}

uint8_t simpsons_z80_read(uint16_t address)
{
	if (address < 0xC000u)
		return game_sound[simpsons_sound_offset(address)];
	if (address >= 0xF000u && address < 0xF800u)
		return simpsons_board.sound_ram[address - 0xF000u];
	if (address == 0xF800u || address == 0xF801u)
		return simpsons_board.sound_chip_read ? simpsons_board.sound_chip_read(SIMPSONS_CHIP_FM, address & 1) : 0;
	if (address >= 0xFC00u && address < 0xFC30u)
	{
		/* the K053260's ports from the 053248 (its registers 0-1); the rest is the chip's */
		if (address < 0xFC02u)
			return simpsons_board.sound_ports[address - 0xFC00u];
		return simpsons_board.sound_chip_read ? simpsons_board.sound_chip_read(SIMPSONS_CHIP_PCM, address - 0xFC00u) : 0;
	}
	return 0;
}

void simpsons_z80_write(uint16_t address, uint8_t data)
{
	if (address >= 0xF000u && address < 0xF800u)
	{
		simpsons_board.sound_ram[address - 0xF000u] = data;
		return;
	}
	if (address == 0xF800u || address == 0xF801u)
	{
		if (simpsons_board.sound_chip_write)
			simpsons_board.sound_chip_write(SIMPSONS_CHIP_FM, address & 1, data);
		return;
	}
	if (address == 0xFA00u)
	{
		if (simpsons_board.sound_nmi_arm)
			simpsons_board.sound_nmi_arm();
		return;
	}
	if (address >= 0xFC00u && address < 0xFC30u)
	{
		/* the K053260's ports to the 053248 (its registers 2-3); the rest is the chip's */
		if (address == 0xFC02u || address == 0xFC03u)
			simpsons_board.sound_ports[address - 0xFC00u] = data;
		else if (simpsons_board.sound_chip_write)
			simpsons_board.sound_chip_write(SIMPSONS_CHIP_PCM, address - 0xFC00u, data);
		return;
	}
	if (address == 0xFE00u)
		simpsons_board.sound_bank = data & 7u;
}
