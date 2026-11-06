/**
 *    Name:        program.h
 *    Description: the 053248 program as a port runs it: its reset, its run, the frames it makes
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    06-11-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    The program runs with frame timing (simpsons/frame.h): it takes no time, and where it waits for its next frame
 *    with nothing to do, program_frame runs: the port moves the board on to its next VBLANK (simpsons_frame_vblank,
 *    the video, the sound board), applies its controls and takes the frame's hashes; it ends the run itself when it
 *    has had enough (the program never returns).
 */
#ifndef SIMPSONS_PROGRAM_H
#define SIMPSONS_PROGRAM_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* The CPU as its reset leaves it: the PC from the reset vector */
void program_reset(void);

/* Runs the program; it never comes back (program_frame ends the run) */
void program_run(void);

/* The port's: the board's next frame, where the program waits for it */
extern void (*program_frame)(void);

/* The interrupts the program took */
uint32_t program_interrupts(void);

#ifdef __cplusplus
}
#endif

#endif
