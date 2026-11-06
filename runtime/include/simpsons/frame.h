/**
 *    Name:        frame.h
 *    Description: where The Simpsons' 053248 program waits for its next frame, and where its IRQ handler takes the
 *                 sprite DMA's FIRQ, for the tools that run it with frame timing
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    06-11-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    The program does a frame's work in its IRQ handler (078F43, the K052109's VBLANK) and in the jobs the frames
 *    leave in a queue, which its main loop (0789BC-0789EA) runs: the pointer at 4942 is the next one, and a
 *    negative word there means there is none. At 0789D1 the loop branches back on that word: when it is negative
 *    the program has nothing to do until the next VBLANK. Before the loop, the boot waits at 078814-078817 for the
 *    sprite DMA's FIRQ to clear 4856, and, once it has reset the EEPROM (the test switch held at power on), at
 *    07887C-078882 for the switch to be let go, which the controls do only at a VBLANK. With frame timing (kref
 *    --timing frames, and the translated program) instructions take no time, and the board moves on to its next
 *    VBLANK only at those waits (machine.h: simpsons_frame_vblank): the frames come where the program has finished
 *    its work, as on a board fast enough never to lag; the interrupt the VBLANK raises is taken after the waiting
 *    instruction.
 *    The FIRQ, which MAME's pace has come 128 cycles into the VBLANK, lands in the IRQ handler's first steps
 *    (kref --interrupts: after 078F7A-078F9E, or 079054-079058 down LBEQ's other way), always after the handler
 *    saved the 1FC2 copy (direct page 0F) the FIRQ handler changes, and before anything there the FIRQ handler
 *    touches: with frame timing it is taken after 078F7A (LBEQ $9054), whichever way the branch goes.
 */
#ifndef SIMPSONS_FRAME_H
#define SIMPSONS_FRAME_H

#include "simpsons/machine.h"

#include <stdbool.h>
#include <stdint.h>

#define SIMPSONS_FRAME_WAIT    0x89D1u    /* BMI $89BC: the main loop finds no job */
#define SIMPSONS_JOB_QUEUE     0x4942u    /* the pointer to the next job (4944-497F) */
#define SIMPSONS_BOOT_WAIT     0x8817u    /* BNE $8814: the boot waits for the FIRQ */
#define SIMPSONS_BOOT_FLAG     0x4856u    /* direct page 56, which the FIRQ handler clears */
#define SIMPSONS_SWITCH_WAIT   0x8882u    /* BEQ $887C: the boot waits for the test switch to be let go */
#define SIMPSONS_FIRQ_POINT    0x8F7Au    /* LBEQ $9054: the IRQ handler takes the DMA's FIRQ after it */

/* True when the instruction at 'pc' (the fixed program's) is a wait for the next frame that finds nothing to do */
static inline bool simpsons_frame_idle(uint16_t pc)
{
	if (pc == SIMPSONS_FRAME_WAIT)
	{
		const uint16_t queue = (uint16_t)(*simpsons_work_ram_byte(SIMPSONS_JOB_QUEUE) << 8
			| *simpsons_work_ram_byte(SIMPSONS_JOB_QUEUE + 1u));
		return queue >= SIMPSONS_WORK_RAM && queue < SIMPSONS_WORK_RAM + SIMPSONS_WORK_RAM_SIZE
			&& (*simpsons_work_ram_byte(queue) & 0x80u) != 0;
	}
	if (pc == SIMPSONS_BOOT_WAIT)
		return *simpsons_work_ram_byte(SIMPSONS_BOOT_FLAG) != 0;
	if (pc == SIMPSONS_SWITCH_WAIT)
		return (simpsons_board.test & SIMPSONS_TEST_SERVICE) == 0;
	return false;
}

#endif
