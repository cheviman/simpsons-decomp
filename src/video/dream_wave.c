/**
 *    Name:        video/dream_wave.c
 *    Description: the dream's wave over layer A's line scroll (stage 6's start and end)
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
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
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	dream_wave_straighten(&line_scroll, &count);
	io_write16(0x18F1u, 0u);
	io_write16(0x18EFu, 0u);
	t1 = io_read8(0x18EDu);
	io_write8(0x18EDu, 0u);
	t2 = io_read8(0x18EBu);
	io_write8(0x18EBu, 0u);
	io_write8(0x1C80u, 3u);
	t3 = io_read8(0x18ECu);
	io_write8(0x18ECu, t3 + 1u);
	*p_line_scroll = line_scroll;
	*p_count = count;
}

/* The dream's wave: draws it growing 8 a frame up to C0 (no scenario reaches it). */
uint16_t dream_wave_grow(void)
{
	uint8_t size = 0;
	uint16_t x = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = io_read8(0x18EDu);
	size = t1;
	x = dream_wave_draw_lines(size);
	t2 = io_read8(0x18EDu);
	io_write8(0x18EDu, t2 + 8u);
	t3 = io_read8(0x18EDu);
	if (t3 >= 0xC0u)
	{
		t4 = io_read8(0x18ECu);
		io_write8(0x18ECu, t4 + 1u);
	}
	return x;
}

/* The dream's wave: draws it at its size (no scenario reaches it). */
uint16_t dream_wave_keep(void)
{
	uint8_t size = 0;
	uint16_t x = 0;
	uint8_t t1 = 0;

	t1 = io_read8(0x18EDu);
	size = t1;
	x = dream_wave_draw_lines(size);
	return x;
}

/* The dream's wave going away, by its step: full, held, shrinking, done. */
uint16_t dream_wave_fade_out(void)
{
	uint16_t ignored16 = 0, u = 0;
	uint8_t t1 = 0;

	u = dream_wave_fade_out_steps_ADDRESS;
	t1 = io_read8(0x18ECu);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		dream_wave_start_full();
		return u;
	case 2:
		dream_wave_hold();
		return u;
	case 4:
		dream_wave_shrink();
		return u;
	case 6:
		dream_wave_done();
		return u;
	case -6:
		dream_wave_start(&ignored16, &u);
		return u;
	case -4:
		dream_wave_grow();
		return u;
	case -2:
		dream_wave_keep();
		return u;
	}
	unreachable();
}

/* The dream's wave: starts it at full size, line scroll on. */
void dream_wave_start_full(void)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = io_read8(0x18EBu);
	io_write8(0x18EBu, 0u);
	io_write8(0x18EDu, 0xC0u);
	io_write8(0x1C80u, 3u);
	io_write8(0x18F3u, 0x40u);
	t2 = io_read8(0x18ECu);
	io_write8(0x18ECu, t2 + 1u);
}

/* The dream's wave: draws it at full size for 64 frames. */
uint16_t dream_wave_hold(void)
{
	uint8_t size = 0;
	uint16_t x = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = io_read8(0x18EDu);
	size = t1;
	x = dream_wave_draw_lines(size);
	t2 = io_read8(0x18F3u);
	io_write8(0x18F3u, t2 - 1u);
	if (t2 == 1u)
	{
		t3 = io_read8(0x18ECu);
		io_write8(0x18ECu, t3 + 1u);
	}
	return x;
}

/* The dream's wave: draws it 2 smaller each frame; at nothing, line scroll off. */
uint16_t dream_wave_shrink(void)
{
	uint8_t size = 0, size_2 = 0;
	uint16_t x = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = io_read8(0x18EDu);
	size = t1;
	x = dream_wave_draw_lines(size);
	t2 = io_read8(0x18EDu);
	size_2 = t2 - 2u;
	io_write8(0x18EDu, size_2);
	if (size_2 != 0u)
	{
		dream_wave_done();
		return x;
	}
	t3 = io_read8(0x1C80u);
	io_write8(0x1C80u, 0u);
	t4 = io_read8(0x18ECu);
	io_write8(0x18ECu, t4 + 1u);
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
	uint8_t a = 0, b = 0, scroll_high = 0;
	uint16_t d = 0, line_scroll = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t8 = 0, t9 = 0;
	uint16_t t5 = 0, t6 = 0, t7 = 0;

	io_write8(0x18EEu, size);
	t1 = io_read8(0x18EAu);
	io_write8(0x18EAu, 0u);
	line_scroll = 0x1A00u;
	do
	{
		t2 = io_read8(0x18EAu);
		t3 = io_read8(0x18EBu);
		t4 = io_read8(0x18EEu);
		d = ((uint32_t)(uint8_t)((uint32_t)(t2 + t3) << 1) << 8) | t4;
		d = wave_sine(d);
		a = (uint8_t)(d >> 8);
		b = (uint8_t)d;
		t5 = (((uint32_t)a << 8) | b) + 0x196u;
		scroll_high = (t5 >> 8) & 1u;
		t6 = scroll_high | 0x1000u;
		t7 = line_scroll;
		line_scroll = t7 + 2u;
		mem_write16(t7, ((uint32_t)(uint8_t)t5 << 8) | (uint8_t)t6);
		t8 = io_read8(0x18EAu);
		io_write8(0x18EAu, t8 - 1u);
	} while (t8 != 1u);
	t9 = io_read8(0x18EBu);
	io_write8(0x18EBu, t9 - 2u);
	return line_scroll;
}

/* The sine of an angle (256 to a turn) times a size (wave_cosines). */
uint16_t wave_sine(uint16_t angle_and_size)
{
	uint8_t angle = 0, offset = 0, wave_size = 0;
	uint16_t cosines = 0, wave_offset = 0;
	uint16_t t1 = 0;

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
	t1 = wave_sine_value;
	wave_offset = t1;
	return wave_offset;
}
