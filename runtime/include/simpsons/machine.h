/**
 *    Name:        machine.h
 *    Description: The Simpsons' board (Konami GX072) as the 053248 program sees it: memory map, banks, inputs,
 *                 interrupts, the EEPROM, the video chips' memories and registers
 *    Version:     0.1.0
 *    Created:     05-11-2026
 *    Modified:    05-11-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    Behavior follows MAME 0.289: konami/simpsons.cpp (Ernesto Corvi), konami/k052109.cpp,
 *    konami/k053246_k053247_k055673.cpp, konami/k053251.cpp, sound/k053260.cpp (its ports) and
 *    machine/eepromser.cpp and eeprom.cpp (the ER5911). MAME's terms are in tools/core/konami/reference/mame/LICENSE.
 *
 *    The 053248 reaches the board through simpsons_read / simpsons_write: 64 KB, 8 bits wide. As in MAME, the
 *    handlers are per direction: an address with a port to read and nothing to write (the inputs, 1F80-1F93)
 *    writes the K052109 under it, and one with a register to write and nothing to read (1FA0-1FC2) reads the
 *    K052109. Its bank lines (the SETLN instruction) choose the program bank seen at 6000-7FFF
 *    (simpsons_set_lines). What no device answers reads 0, MAME's default.
 *
 *    Time: the caller advances simpsons_board.cycles as the CPU runs (the 053248's cycles, 12 MHz / 4), gives
 *    the present within a run through simpsons_board.now (the EEPROM's timing needs it), and calls the frame's
 *    events itself (tools/core/konami/reference/kref, to follow the real CPU's pace). With frame timing
 *    (simpsons/frame.h: kref --timing frames, the translated program) instructions take no time: the board moves
 *    on to its next VBLANK where the program waits for one (simpsons_frame_vblank), and a read of a port the
 *    program polls in a loop (1F81: the EEPROM's READY) or a write of the EEPROM's lines (1FC2: its start bit
 *    must come after CS goes up) costs it SIMPSONS_POLL_CYCLES, and a read of the Z80's answers (1FC6-1FC7)
 *    SIMPSONS_SOUND_POLL_CYCLES: the time the EEPROM and the Z80 go on in while the program waits for them.
 */
#ifndef SIMPSONS_MACHINE_H
#define SIMPSONS_MACHINE_H

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SIMPSONS_CPU_CLOCK        3000000u     /* the 053248: 12 MHz in, an internal divider of 4 */
#define SIMPSONS_LINE_CYCLES      192u         /* 384 pixels at 6 MHz: 64 us */
#define SIMPSONS_LINES            264
#define SIMPSONS_VBLANK_START     240          /* the visible lines are 16-239 */
#define SIMPSONS_VBLANK_END       16
#define SIMPSONS_FRAME_CYCLES     (SIMPSONS_LINE_CYCLES * SIMPSONS_LINES)
/* The sprite DMA's FIRQ, after VBLANK starts: from 256 to 256 + 2048 ticks of 6 MHz (MAME's periodic_irq) */
#define SIMPSONS_DMA_START_CYCLES 128u
#define SIMPSONS_DMA_END_CYCLES   1152u
/* Frame timing: what a read of a port the program polls costs, or a write of the EEPROM's lines (1F81, 1FC2), and
   a read of the Z80's answers (1FC6, 1FC7): the boot asks the Z80 for its ROM's sum and waits 2000 reads at most
   (078EB0), which the Z80 takes the time of the 053248's RAM test to work out on the real board */
#define SIMPSONS_POLL_CYCLES      16u
#define SIMPSONS_SOUND_POLL_CYCLES 1024u
/* The ER5911 is busy 1750 us after a write (MAME's default write time) */
#define SIMPSONS_EEPROM_WRITE_CYCLES 5250u

#define SIMPSONS_WORK_RAM         0x4000u
#define SIMPSONS_WORK_RAM_SIZE    0x2000       /* 4000-5FFF */
/* The 053248's stack: the boot sets S to 5E00 (07870B) and nothing sets it again; the scenarios take it no lower
   than SIMPSONS_STACK_LOW (kref --stack). Only the original's stack discipline writes there (the return addresses,
   the registers it pushes, the interrupts' frames), which the decompiled program keeps in its own variables: the
   state hash leaves it out */
#define SIMPSONS_STACK_LOW        0x5D80u
#define SIMPSONS_STACK_TOP        0x5E00u
#define SIMPSONS_EXTRA_RAM_SIZE   0x1000       /* 3000-3FFF while the sprite RAM is in view */
#define SIMPSONS_PALETTE_SIZE     0x1000       /* 0000-0FFF while in view: 2048 colors, xBGR 555, big endian */
#define SIMPSONS_TILE_RAM_SIZE    0x6000       /* the K052109's (the board reaches 0000-3FFF of it) */
#define SIMPSONS_SPRITE_RAM_SIZE  0x1000       /* 2000-2FFF while in view: 256 sprites of 8 big-endian words */
#define SIMPSONS_EEPROM_SIZE      0x80         /* the ER5911: 128 cells of 8 bits */

/* The sound board: a Z80, a YM2151 and a K053260 on 3.579545 MHz */
#define SIMPSONS_SOUND_CLOCK      3579545u
#define SIMPSONS_SOUND_RAM_SIZE   0x800        /* the Z80's RAM, F000-F7FF */

/* The sound board's chips as the Z80 reaches them (simpsons_z80_read / simpsons_z80_write) */
enum
{
	SIMPSONS_CHIP_FM,          /* YM2151, F800-F801 */
	SIMPSONS_CHIP_PCM          /* K053260, FC00-FC2F (its ports to the 053248 are the board's: sound_ports) */
};

/* The inputs, as MAME's ports have them: every bit active low but the EEPROM's */
enum
{
	SIMPSONS_COIN1 = 0x01, SIMPSONS_COIN2 = 0x02, SIMPSONS_COIN3 = 0x04, SIMPSONS_COIN4 = 0x08
};
enum
{
	SIMPSONS_LEFT = 0x01, SIMPSONS_RIGHT = 0x02, SIMPSONS_UP = 0x04, SIMPSONS_DOWN = 0x08,
	SIMPSONS_ATTACK = 0x10, SIMPSONS_JUMP = 0x20, SIMPSONS_START = 0x80    /* (the test mode: SHOOT1, SHOOT2) */
};
#define SIMPSONS_TEST_SERVICE     0x01          /* 1F81: the test mode's switch, active low */
#define SIMPSONS_TEST_IDLE        0xCF          /* its other bits (MAME's unknown ones read 1), the EEPROM's apart */
#define SIMPSONS_TEST_EEPROM_DO   0x10
#define SIMPSONS_TEST_EEPROM_READY 0x20

/* The ER5911's serial interface (MAME's eeprom_serial_base_device) */
typedef struct
{
	uint8_t data[SIMPSONS_EEPROM_SIZE];
	uint8_t state;                 /* in reset, waiting for the start bit, the command, reading, writing, done */
	bool cs, clk, di;
	bool locked;
	uint8_t command;
	uint32_t bits;                 /* bits clocked in the present state */
	uint32_t command_address;      /* the start bit's 2 command bits and 9 address bits */
	uint32_t address;
	uint32_t shift;                /* the shift register: the data read (from bit 31) or written */
	uint64_t cs_rose_at;           /* the cycle CS last went up (a clock at the same cycle is ignored) */
	uint64_t busy_until;           /* the cycle a write completes */
} simpsons_eeprom;

typedef struct
{
	uint8_t work_ram[SIMPSONS_WORK_RAM_SIZE];    /* the other way round: simpsons_work_ram_at */
	uint8_t extra_ram[SIMPSONS_EXTRA_RAM_SIZE];
	uint8_t palette[SIMPSONS_PALETTE_SIZE];

	/* K052109: three tile layers (codes, colors), their scroll and its registers, all in one RAM */
	uint8_t tile_ram[SIMPSONS_TILE_RAM_SIZE];
	uint8_t char_rom_bank[4];      /* 1D80, 1F00 */
	uint8_t char_rom_bank_2[4];    /* 3D80, 3F00 */
	uint8_t rom_subbank;           /* 1E00 */
	uint8_t irq_control;           /* 1D00: bit 2 the IRQ at VBLANK */
	uint8_t scroll_control;        /* 1C80 */
	uint8_t address_map;           /* 1C00 */
	uint8_t tile_flip;             /* 1E80 */
	bool read_char_rom;            /* RMRD (1FC0 bit 3): the tile RAM's window reads the tile ROM */

	/* K053246 / K053247: the sprite list the CPU writes, the copy the DMA makes for the chip, its registers */
	uint8_t sprite_ram[SIMPSONS_SPRITE_RAM_SIZE];
	uint8_t object_ram[SIMPSONS_SPRITE_RAM_SIZE];
	uint8_t sprite_registers[8];   /* 1FA0-1FA7: 4, 6, 7 the sprite ROM's address; 5 bit 4 the DMA */
	bool read_sprite_rom;          /* OBJCHA (1FC0 bit 5 low): 1FC8-1FC9 read the sprite ROM */

	/* K053251: the layers' priorities and color bases */
	uint8_t priority[16];

	uint8_t bank;                  /* the 053248's lines: the program bank at 6000-7FFF */
	uint8_t video_bank;            /* 1FC2 bits 0-1: the palette at 0000, the sprite RAM at 2000 */
	bool firq_enabled;             /* 1FC2 bit 2 */
	bool irq;                      /* the 053248's IRQ, from the K052109 at VBLANK */
	bool firq;                     /* its FIRQ, from the sprite DMA */
	uint8_t control;               /* the last byte written to 1FC0 */
	uint8_t eeprom_out;            /* the last byte written to 1FC2 */
	uint64_t dma_start_at, dma_end_at;    /* the DMA's FIRQ, in cycles (0: none) */
	bool frame_timing;             /* simpsons/frame.h: the board moves on where the program waits */
	bool firq_due;                 /* frame timing: the DMA's FIRQ, held for the IRQ handler's FIRQ point */

	/* K053260: the ports between the two CPUs (0-1 the 053248 writes, 2-3 the Z80) */
	uint8_t sound_ports[4];
	uint32_t sound_irqs;           /* the Z80's IRQs: reads of 1FC4 */

	/* the sound board */
	uint8_t sound_ram[SIMPSONS_SOUND_RAM_SIZE];
	uint8_t sound_bank;            /* FE00: the bank at 8000-BFFF (0-7) */
	/* What the sound board's model (the reference's) does: brings the sound board up to the 053248's present
	   before the 053248 sees or changes what the Z80 shares; raises the Z80's IRQ (held until the Z80 takes
	   it); reads and writes the sound chips; arms the Z80's NMI (FA00: the line down, and up again at the
	   K053260's next SH1 pulse). Unset, the sound board stands still */
	void (*sound_sync)(void);
	void (*sound_irq)(void);
	uint8_t (*sound_chip_read)(int chip, int offset);
	void (*sound_chip_write)(int chip, int offset, uint8_t data);
	void (*sound_nmi_arm)(void);

	simpsons_eeprom eeprom;

	/* the present within the CPU's run (the EEPROM's timing): unset, simpsons_board.cycles */
	uint64_t (*now)(void);
	/* A development aid: called with every write the 053248 makes on the bus */
	void (*write_watch)(uint16_t address, uint8_t data);
	/* Where the program's byte at a place (its region's offset) is: the game's assets' pieces (game/assets.h's
	   game_assets_program_at); unset, game/data.h's game_program, the ROM set's (the tools that run the original). A
	   place the assets give nothing at, which only the original's code holds, is a mistake of the game's, and stops it */
	const uint8_t *(*program_at)(uint32_t place);
	uint32_t coin_counters[2];
	uint32_t watchdog_resets;
	uint32_t unmapped_writes;      /* to the program's ROM (the reset writes 7C00) */

	/* the inputs, active low */
	uint8_t coins;
	uint8_t test;
	uint8_t players[4];

	uint64_t cycles;               /* the 053248's, since reset */
	uint64_t frame;                /* VBLANKs since reset */
} simpsons_machine;

extern simpsons_machine simpsons_board;

/* The work RAM's 'size' bytes from 'address' as the host has them: the board keeps the work RAM the other way round
   (the byte at its last address first), so that a big-endian value of the 053248's of any width at any address is a
   little-endian value of the host's there, which the decompiled program reads and writes as plain C variables
   (game/support.h); the bus and the state hash see the bytes at their addresses */
static inline void *simpsons_work_ram_at(uint16_t address, uint32_t size)
{
	return &simpsons_board.work_ram[SIMPSONS_WORK_RAM_SIZE - size - ((address - SIMPSONS_WORK_RAM)
		& (SIMPSONS_WORK_RAM_SIZE - 1u))];
}

/* The work RAM's byte at 'address' */
static inline uint8_t *simpsons_work_ram_byte(uint16_t address)
{
	return (uint8_t *)simpsons_work_ram_at(address, 1u);
}

/* The board after its reset, the inputs idle and the EEPROM as it leaves the factory (game/data.h's
   game_eeprom: MAME's default, without which the game boots upside down with an error) */
void simpsons_reset(void);

uint8_t simpsons_read(uint16_t address);
void simpsons_write(uint16_t address, uint8_t data);

/* The 053248's output lines (its SETLN instruction): bits 0-5 the program bank at 6000-7FFF */
void simpsons_set_lines(uint8_t data);

/* The program ROM's place of a CPU address: the bank's at 6000-7FFF, the fixed four's at 8000-FFFF; -1 for
   the RAM and the devices below 6000 */
int32_t simpsons_program_offset(uint16_t address);

/* The screen's VBLANK begins (line 240): the K052109's IRQ if the program enables it, and the sprite DMA with
   its FIRQ (simpsons_dma_start / simpsons_dma_end at dma_start_at / dma_end_at) if the K053246's DMA is on */
void simpsons_vblank_start(void);
void simpsons_dma_start(void);
void simpsons_dma_end(void);

/* Frame timing (simpsons/frame.h), at the program's wait: the time up to the next VBLANK, the VBLANK's events
   (simpsons_vblank_start), the last frame's FIRQ dropped, and the sprite DMA's FIRQ at once, or, when the CPU
   will take the IRQ ('irq_masked' false: its CC's I clear), held for the IRQ handler's FIRQ point
   (simpsons_firq_point), where MAME's pace has it come: 128 cycles in, after the handler saved what the FIRQ
   changes */
void simpsons_frame_vblank(bool irq_masked);
void simpsons_firq_point(void);

/* A hash of the state the program keeps: work RAM (but its stack, SIMPSONS_STACK_LOW to SIMPSONS_STACK_TOP), the
   RAM at 3000, palette, the video chips' memories and registers, the bank, the EEPROM */
uint64_t simpsons_state_hash(void);

/* The Z80's memory map (MAME's z80_map): its program, the bank at 8000-BFFF, its RAM, the chips, FA00 (the
   NMI's arming), FE00 (the bank). What no device answers reads 0 */
uint8_t simpsons_z80_read(uint16_t address);
void simpsons_z80_write(uint16_t address, uint8_t data);

/* The sound program ROM's place of a Z80 address (its region's offset: 0000-7FFF fixed, the bank's at
   8000-BFFF); -1 for the RAM and the chips */
int32_t simpsons_sound_offset(uint16_t address);

#ifdef __cplusplus
}
#endif

#endif
