/**
 *    Name:        game.h
 *    Description: the game as the ports run it: the board with the assets in place of the ROM, the program on
 *                 it, its frames drawn and its sound made
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    06-11-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    The ports (ports/sdl2, the game's headless) load the assets, reset the game and run it (simpsons/program.h's
 *    program_run); when the program waits for its next frame the board's VBLANK comes (the frame is drawn, the
 *    board's events), and then the port's game_frame_done, where it applies the controls, closes the frame's
 *    sound (game_end_frame), shows the frame and takes its hashes. The program's data is the assets' (game/assets.h):
 *    the game opens no ROM, and a read of the program's code as data stops it.
 */
#ifndef GAME_GAME_H
#define GAME_GAME_H

#include "simpsons/video.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Loads the assets in 'folder' into the board's memories: NULL, or what failed */
const char *game_load(const char *folder);

/* The board after its reset (the factory EEPROM from the assets), its sound board at power on, the program at its
   reset; the test switch on if 'service'. With 'draw', every frame is drawn (game_frame). NULL, or what failed */
const char *game_reset(bool service, bool draw);

/* What the port does when a frame is done (the VBLANK's events are over): its controls, game_end_frame, its
   output */
extern void (*game_frame_done)(void);

/* Closes the frame's sound (the sound board catches up with the frame's end): its samples (game_audio) and hashes */
void game_end_frame(void);

/* The frame drawn when the last VBLANK ended */
const simpsons_frame *game_frame(void);

/* The last frame's sound, stereo (left, right interleaved): 'count' stereo samples, at game_audio_rate() a second */
const int16_t *game_audio(size_t *count);
uint32_t game_audio_rate(void);

/* The last frame's sound hashes (the samples, the sound board's state), as kref --sound-hashes writes them */
uint64_t game_sound_samples_hash(void);
uint64_t game_sound_state_hash(void);

#ifdef __cplusplus
}
#endif

#endif
