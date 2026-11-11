/**
 *    Name:        video/dream_wave.c
 *    Description: the dream's wave over layer A's line scroll (stage 6's start and end)
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    10-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* The dream's wave: sets every line's x scroll back to straight. */
void dream_wave_straighten(uint16_t *p_line_scroll, uint16_t *p_count)
{
	uint16_t count = 0, line_scroll = 0, straight = 0;

	straight = 0x9601u;
	count = 0x100u;
	line_scroll = 0x1A00u;
	while (count != 0u)
	{
		mem_write16(line_scroll, straight);
		line_scroll += 2u;
		count--;
	}
	*p_line_scroll = line_scroll;
	*p_count = count;
}

/* The dream's wave: straight lines, line scroll on, the wave's size 0 (no scenario reaches it). */
void dream_wave_start(uint16_t *p_line_scroll, uint16_t *p_count)
{
	uint16_t count = 0, line_scroll = 0;
	uint8_t previous_wave_size = 0, previous_wave_phase = 0, wave_step = 0;

	dream_wave_straighten(&line_scroll, &count);
	io_write16(0x18F1u, 0u);
	io_write16(0x18EFu, 0u);
	previous_wave_size = io_read8(0x18EDu);
	io_write8(0x18EDu, 0u);
	previous_wave_phase = io_read8(0x18EBu);
	io_write8(0x18EBu, 0u);
	io_write8(0x1C80u, 3u);
	wave_step = io_read8(0x18ECu);
	io_write8(0x18ECu, wave_step + 1u);
	*p_line_scroll = line_scroll;
	*p_count = count;
}

/* The dream's wave: draws it growing 8 a frame up to C0 (no scenario reaches it). */
uint16_t dream_wave_grow(void)
{
	uint8_t size = 0;
	uint16_t x = 0;
	uint8_t wave_size = 0, wave_size_before = 0, grown_size = 0, wave_step = 0;

	wave_size = io_read8(0x18EDu);
	size = wave_size;
	x = dream_wave_draw_lines(size);
	wave_size_before = io_read8(0x18EDu);
	io_write8(0x18EDu, wave_size_before + 8u);
	grown_size = io_read8(0x18EDu);
	if (grown_size >= 0xC0u)
	{
		wave_step = io_read8(0x18ECu);
		io_write8(0x18ECu, wave_step + 1u);
	}
	return x;
}

/* The dream's wave: draws it at its size (no scenario reaches it). */
uint16_t dream_wave_keep(void)
{
	uint8_t size = 0;
	uint16_t x = 0;
	uint8_t wave_size = 0;

	wave_size = io_read8(0x18EDu);
	size = wave_size;
	x = dream_wave_draw_lines(size);
	return x;
}

/* The dream's wave going away, by its step: full, held, shrinking, done. */
uint16_t dream_wave_fade_out(void)
{
	uint16_t fade_out_step_table = 0, ignored16 = 0;
	uint8_t wave_step = 0;

	fade_out_step_table = dream_wave_fade_out_steps_ADDRESS;
	wave_step = io_read8(0x18ECu);
	switch ((int8_t)(uint8_t)((uint32_t)wave_step << 1))
	{
	case 0:
		dream_wave_start_full();
		return fade_out_step_table;
	case 2:
		dream_wave_hold();
		return fade_out_step_table;
	case 4:
		dream_wave_shrink();
		return fade_out_step_table;
	case 6:
		dream_wave_done();
		return fade_out_step_table;
	case -6:
		dream_wave_start(&ignored16, &fade_out_step_table);
		return fade_out_step_table;
	case -4:
		dream_wave_grow();
		return fade_out_step_table;
	case -2:
		dream_wave_keep();
		return fade_out_step_table;
	}
	unreachable();
}

/* The dream's wave: starts it at full size, line scroll on. */
void dream_wave_start_full(void)
{
	uint8_t previous_wave_phase = 0, wave_step = 0;

	previous_wave_phase = io_read8(0x18EBu);
	io_write8(0x18EBu, 0u);
	io_write8(0x18EDu, 0xC0u);
	io_write8(0x1C80u, 3u);
	io_write8(0x18F3u, 0x40u);
	wave_step = io_read8(0x18ECu);
	io_write8(0x18ECu, wave_step + 1u);
}

/* The dream's wave: draws it at full size for 64 frames. */
uint16_t dream_wave_hold(void)
{
	uint8_t size = 0;
	uint16_t x = 0;
	uint8_t wave_size = 0, hold_frames_left = 0, wave_step = 0;

	wave_size = io_read8(0x18EDu);
	size = wave_size;
	x = dream_wave_draw_lines(size);
	hold_frames_left = io_read8(0x18F3u);
	io_write8(0x18F3u, hold_frames_left - 1u);
	if (hold_frames_left == 1u)
	{
		wave_step = io_read8(0x18ECu);
		io_write8(0x18ECu, wave_step + 1u);
	}
	return x;
}

/* The dream's wave: draws it 2 smaller each frame; at nothing, line scroll off. */
uint16_t dream_wave_shrink(void)
{
	uint8_t size = 0, size_2 = 0;
	uint16_t x = 0;
	uint8_t wave_size = 0, wave_size_before = 0, previous_line_scroll_mode = 0, wave_step = 0;

	wave_size = io_read8(0x18EDu);
	size = wave_size;
	x = dream_wave_draw_lines(size);
	wave_size_before = io_read8(0x18EDu);
	size_2 = wave_size_before - 2u;
	io_write8(0x18EDu, size_2);
	if (size_2 != 0u)
	{
		dream_wave_done();
		return x;
	}
	previous_line_scroll_mode = io_read8(0x1C80u);
	io_write8(0x1C80u, 0u);
	wave_step = io_read8(0x18ECu);
	io_write8(0x18ECu, wave_step + 1u);
	dream_wave_done();
	return x;
}

/* The dream's wave: gone (nothing more to do). */
void dream_wave_done(void)
{
}

/* The dream's wave: sets each line's x scroll to straight plus the sine of its line and the phase, of
   the given size; the wave moves 2 a frame. */
uint16_t dream_wave_draw_lines(uint8_t size)
{
	uint8_t line_offset_high = 0, line_offset_low = 0, scroll_high = 0;
	uint16_t line_scroll = 0, line_wave_offset = 0;
	uint8_t previous_line_count = 0, wave_line = 0, wave_phase = 0, line_wave_size = 0, lines_left_before = 0, wave_phase_before = 0;
	uint16_t line_x_scroll = 0, swapped_scroll = 0, written_place = 0;

	io_write8(0x18EEu, size);
	previous_line_count = io_read8(0x18EAu);
	io_write8(0x18EAu, 0u);
	line_scroll = 0x1A00u;
	do
	{
		wave_line = io_read8(0x18EAu);
		wave_phase = io_read8(0x18EBu);
		line_wave_size = io_read8(0x18EEu);
		line_wave_offset = ((uint32_t)(uint8_t)((uint32_t)(wave_line + wave_phase) << 1) << 8) | line_wave_size;
		line_wave_offset = wave_sine(line_wave_offset);
		line_offset_high = (uint8_t)(line_wave_offset >> 8);
		line_offset_low = (uint8_t)line_wave_offset;
		line_x_scroll = (((uint32_t)line_offset_high << 8) | line_offset_low) + 0x196u;
		scroll_high = (line_x_scroll >> 8) & 1u;
		swapped_scroll = scroll_high | 0x1000u;
		written_place = line_scroll;
		line_scroll = written_place + 2u;
		mem_write16(written_place, ((uint32_t)(uint8_t)line_x_scroll << 8) | (uint8_t)swapped_scroll);
		lines_left_before = io_read8(0x18EAu);
		io_write8(0x18EAu, lines_left_before - 1u);
	} while (lines_left_before != 1u);
	wave_phase_before = io_read8(0x18EBu);
	io_write8(0x18EBu, wave_phase_before - 2u);
	return line_scroll;
}

/* The sine of an angle (256 to a turn) times a size (wave_cosines). */
uint16_t wave_sine(uint16_t angle_and_size)
{
	uint8_t angle = 0, offset = 0, wave_size = 0;
	uint16_t cosines = 0, wave_offset = 0;
	uint16_t signed_offset = 0;

	angle = (uint8_t)(angle_and_size >> 8);
	wave_size = (uint8_t)angle_and_size;
	wave_sine_angle = angle;
	wave_sine_size = wave_size;
	wave_sine_quarter = angle & 0x3Fu;
	cosines = wave_cosines_ADDRESS;
	if ((wave_sine_angle & 0x40u) == 0u)
		offset = (uint8_t)((uint16_t)((uint32_t)WAVE_COSINE(cosines + ((int8_t)(0x3Fu - wave_sine_quarter))) * wave_sine_size) >> 8);
	else
		offset = (uint8_t)((uint16_t)((uint32_t)WAVE_COSINE(cosines + (int8_t)wave_sine_quarter) * wave_size) >> 8);
	wave_sine_low = offset;
	wave_sine_high = 0u;
	if ((wave_sine_angle & 0x80u) != 0u)
		wave_sine_value = 0u - wave_sine_value;
	signed_offset = wave_sine_value;
	wave_offset = signed_offset;
	return wave_offset;
}
