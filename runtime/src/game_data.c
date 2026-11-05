/**
 *    Name:        game_data.c
 *    Description: the ROM set's regions (game/data.h), which the reference fills when it starts
 *    Version:     0.1.0
 *    Created:     05-11-2026
 *    Modified:    05-11-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 */
#include "game/data.h"

uint8_t game_program[GAME_PROGRAM_SIZE];
uint8_t game_sound[GAME_SOUND_SIZE];
uint8_t game_tiles[GAME_TILES_SIZE];
uint8_t game_sprites[GAME_SPRITES_SIZE];
uint8_t game_samples[GAME_SAMPLES_SIZE];
uint8_t game_eeprom[GAME_EEPROM_SIZE];
