/**
 *    Name:        script.h
 *    Description: scripted controls for test runs: coins, the test switch, the four players' joysticks,
 *                 buttons and start buttons, and memory pokes, applied when VBLANK starts in the frames a text
 *                 script names
 *    Version:     0.1.0
 *    Created:     05-11-2026
 *    Modified:    05-11-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    A run that applies the same script at the same frame boundaries sees the same inputs, so the game and
 *    tools/core/konami/reference/kref stay comparable frame by frame. The format is OutRunners' (its
 *    runtime/include/s32/script.h), with this board's controls (TMNT's, without its DIP switches: this board keeps
 *    its settings in the EEPROM).
 *
 *    Script format, one event per line, '#' starts a comment:
 *      FRAME ACTION [ARGUMENTS]        FRAME is a frame number (the VBLANKs before it), or +N for N frames
 *                                      after the previous event
 *      press INPUT [FRAMES]            pressed for FRAMES frames (4 by default), then released
 *      hold INPUT / release INPUT      pressed / released until another event changes it
 *      poke ADDRESS VALUE              writes a byte through the bus (hexadecimal address and value)
 *      end                             the run ends with this frame
 *    INPUT: coin1-coin4, service (the test switch), and for players 1-4 leftN rightN upN downN attackN jumpN startN
 *    (attack and jump are MAME's buttons 1 and 2, the test mode's SHOOT1 and SHOOT2; player 1 is Marge, 2 Homer,
 *    3 Bart, 4 Lisa)
 */
#ifndef SIMPSONS_SCRIPT_H
#define SIMPSONS_SCRIPT_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct simpsons_script simpsons_script;

/* NULL if the script cannot be read or parsed; 'error' then says what and where */
simpsons_script *simpsons_script_load(const char *path, char *error, size_t error_size);
void simpsons_script_free(simpsons_script *script);

/* Applies what is due in 'frame': call it when the frame's VBLANK starts, the moment MAME polls the
   controls, with the VBLANKs so far (frame 0 before the program starts) */
void simpsons_script_apply(simpsons_script *script, uint64_t frame);

/* Frames the script asks to run ('end'), or 0 if it does not say */
uint64_t simpsons_script_frames(const simpsons_script *script);

#ifdef __cplusplus
}
#endif

#endif
