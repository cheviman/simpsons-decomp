/**
 *    Name:        data.h
 *    Description: the ROM set's regions as the board has them, for the tools that run the original code
 *    Version:     0.1.0
 *    Created:     05-11-2026
 *    Modified:    05-11-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    The reference (tools/core/konami/reference) runs the original code, so it fills these regions from the
 *    player's ROM set when it starts (game/extract.h). The regions are laid out as MAME's ROM_START( simpsons )
 *    leaves them, as tools/simpsons_rom.py builds them: the board's chips keep their bytes as they are (the
 *    driver's init does nothing to them), and the video chips read the tile and sprite ROMs as these bytes.
 */
#ifndef GAME_DATA_H
#define GAME_DATA_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define GAME_PROGRAM_SIZE   0x80000      /* the 053248's program: 64 banks of 8 KB, the last four fixed at 8000 */
#define GAME_SOUND_SIZE     0x28000      /* the Z80's: 0000-7FFF fixed, 10000-27FFF its banks (8000-FFFF unused) */
#define GAME_TILES_SIZE     0x100000     /* the K052109's tile ROM */
#define GAME_SPRITES_SIZE   0x400000     /* the K053246's sprite ROM */
#define GAME_SAMPLES_SIZE   0x140000     /* the K053260's samples */
#define GAME_EEPROM_SIZE    0x80         /* the ER5911's contents as the board leaves the factory */

extern uint8_t game_program[GAME_PROGRAM_SIZE];
extern uint8_t game_sound[GAME_SOUND_SIZE];
extern uint8_t game_tiles[GAME_TILES_SIZE];
extern uint8_t game_sprites[GAME_SPRITES_SIZE];
extern uint8_t game_samples[GAME_SAMPLES_SIZE];
extern uint8_t game_eeprom[GAME_EEPROM_SIZE];

#ifdef __cplusplus
}
#endif

#endif
