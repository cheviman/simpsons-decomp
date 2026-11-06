/**
 *    Name:        video.h
 *    Description: The Simpsons' video: the K052109's three tile layers, the K053246/K053247's sprites and the
 *                 K053251's priorities and colour bases, drawn from the board's memories as the board shows them
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    06-11-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 */
#ifndef SIMPSONS_VIDEO_H
#define SIMPSONS_VIDEO_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SIMPSONS_VIDEO_WIDTH    320
#define SIMPSONS_VIDEO_HEIGHT   224     /* the screen's lines 16-239 */

typedef struct simpsons_frame
{
	uint32_t pixels[SIMPSONS_VIDEO_WIDTH * SIMPSONS_VIDEO_HEIGHT];  /* 0x00RRGGBB */
} simpsons_frame;

/* the chips as the board's reset leaves them */
void simpsons_video_reset(void);

/* VBLANK ends (line 16): the chips take the board's memories, the K052109 its scroll, and the frame is drawn into
   'frame' (none when NULL): The Simpsons shows a frame from the end of its VBLANK */
void simpsons_video_vblank_end(simpsons_frame *frame);

/* VBLANK begins (line 240): the chips take the board's memories */
void simpsons_video_vblank_start(void);

/* FNV-1a over the frame's pixels, red, green and blue (kref's video hashes) */
uint64_t simpsons_video_hash(const simpsons_frame *frame);

#ifdef __cplusplus
}
#endif

#endif
