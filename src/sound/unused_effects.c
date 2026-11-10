/**
 *    Name:        unused_effects.c
 *    Description: a group of four FM effects no command reaches (unused_effect_group)
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the Z80 sound program decompiled into C by
 *    tools/decompile_sound.py, with the names of sound_symbols.txt.
 */
#include "sound.h"

/* Unused: command 3C's handler (unused_effect_group). Loads unused_effect_3c_patch on FM channel 7, the
   noise on at frequency 0, and keys on pitch 800: 32 steps of 16 passes (unused_effect_3c_slide). */
void unused_effect_3c(uint16_t channel)
{
	uint8_t noise_frequency = 0;
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = unused_effect_3c_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(43);
	noise_frequency = 0u;
	CHANNEL(channel)->unused_effect_3c.noise_frequency = 0u;
	noise_on(channel, noise_frequency);
	z80_block(65);
	pitch = 0x800u;
	CHANNEL(channel)->pitch = 0x800u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(39);
	CHANNEL(channel)->count = 0x10u;
	handler = unused_effect_3c_slide_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The pitch a 16th of a semitone higher each pass, 2 semitones higher while the noise's frequency is
   odd; every 16 passes the noise's frequency one higher (noise_on), and stop_channel when it reaches 32. */
void unused_effect_3c_slide(uint16_t channel)
{
	uint8_t noise_frequency = 0;
	uint16_t pitch = 0;
	uint8_t count = 0;

	z80_block(127);
	pitch = CHANNEL(channel)->pitch + 4u;
	CHANNEL(channel)->pitch = pitch;
	if (CHANNEL(channel)->unused_effect_3c.noise_frequency & 1u)
	{
		z80_block(21);
		pitch += 0x80u;
	}
	z80_block(17);
	set_pitch(pitch, channel);
	z80_block(28);
	count = CHANNEL(channel)->count;
	CHANNEL(channel)->count = count - 1u;
	if (count != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(59);
	CHANNEL(channel)->count = 0x10u;
	noise_frequency = CHANNEL(channel)->unused_effect_3c.noise_frequency + 1u;
	if (noise_frequency >= 0x20u)
	{
		stop_channel(channel);
		return;
	}
	z80_block(29);
	CHANNEL(channel)->unused_effect_3c.noise_frequency = noise_frequency;
	noise_on(channel, noise_frequency);
}

/* Unused: command 3D's handler (unused_effect_group). Loads unused_effect_3d_patch on FM channel 7, the
   noise on at frequency 0A, and keys on at the pitch the channel has: unused_effect_3d_lower_noise. */
void unused_effect_3d(uint16_t channel)
{
	uint8_t noise_frequency = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = unused_effect_3d_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(43);
	noise_frequency = 0xAu;
	CHANNEL(channel)->unused_effect_3d.noise_frequency = 0xAu;
	noise_on(channel, noise_frequency);
	z80_block(17);
	key_on(channel);
	z80_block(39);
	CHANNEL(channel)->count = 0x10u;
	handler = unused_effect_3d_lower_noise_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Every 16 passes the noise's frequency one lower (noise_on); stop_channel when it reaches 0. */
void unused_effect_3d_lower_noise(uint16_t channel)
{
	uint8_t noise_frequency = 0;
	uint8_t count = 0, noise_frequency_2 = 0;

	z80_block(28);
	count = CHANNEL(channel)->count;
	CHANNEL(channel)->count = count - 1u;
	if (count != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(52);
	CHANNEL(channel)->count = 0x10u;
	noise_frequency_2 = CHANNEL(channel)->unused_effect_3d.noise_frequency;
	CHANNEL(channel)->unused_effect_3d.noise_frequency = noise_frequency_2 - 1u;
	if (noise_frequency_2 == 1u)
	{
		stop_channel(channel);
		return;
	}
	z80_block(29);
	noise_frequency = CHANNEL(channel)->unused_effect_3d.noise_frequency;
	noise_on(channel, noise_frequency);
}

/* Unused: command 3E's handler (unused_effect_group). Loads unused_effect_3e_patch on FM channel 7, the
   noise on at frequency 12, and keys on at the pitch the channel has, for 1024 passes
   (unused_effect_3e_end). */
void unused_effect_3e(uint16_t channel)
{
	uint8_t noise_frequency = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = unused_effect_3e_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	noise_frequency = 0x12u;
	noise_on(channel, noise_frequency);
	z80_block(17);
	key_on(channel);
	z80_block(68);
	CHANNEL(channel)->unused_effect_3e.passes = 0x400u;
	handler = unused_effect_3e_end_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Counts down the 1024 passes, then stop_channel. */
void unused_effect_3e_end(uint16_t channel)
{
	uint8_t passes_high = 0, passes_low = 0;
	uint16_t t1 = 0;

	z80_block(95);
	t1 = CHANNEL(channel)->unused_effect_3e.passes - 1u;
	passes_high = (uint8_t)(t1 >> 8);
	passes_low = (uint8_t)t1;
	CHANNEL(channel)->unused_effect_3e.passes = ((uint32_t)passes_high << 8) | passes_low;
	if ((passes_low | passes_high) != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Unused: command 3F's handler in unused_effect_group, which no command reaches. Loads
   unused_effect_3f_patch on FM channel 7, the noise on at frequency 1F, and keys on at the pitch the
   channel has, for 5632 passes (unused_effect_3f_step). */
void unused_effect_3f(uint16_t channel)
{
	uint8_t noise_frequency = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = unused_effect_3f_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	noise_frequency = 0x1Fu;
	noise_on(channel, noise_frequency);
	z80_block(17);
	key_on(channel);
	z80_block(68);
	CHANNEL(channel)->unused_effect_3f.passes = fm_effect_12_patch_ADDRESS + 0x9u;
	handler = unused_effect_3f_step_ADDRESS;
	set_channel_handler(handler, channel);
}

/* After the 5632 passes (unused_effect_3f_update), key off and 512 passes of unused_effect_3f_end. */
void unused_effect_3f_step(uint16_t channel)
{
	uint32_t zero = 0;
	uint16_t handler = 0;

	z80_block(17);
	zero = unused_effect_3f_update(channel);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(17);
	key_off(channel);
	z80_block(68);
	CHANNEL(channel)->unused_effect_3f.passes = 0x200u;
	handler = unused_effect_3f_end_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Counts down the 512 passes (unused_effect_3f_update), then stop_channel. */
void unused_effect_3f_end(uint16_t channel)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = unused_effect_3f_update(channel);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Counts the passes down and tells whether they ran out. */
uint32_t unused_effect_3f_update(uint16_t channel)
{
	uint32_t zero = 0;
	uint8_t passes_high = 0, passes_low = 0;
	uint16_t t1 = 0;

	z80_block(100);
	t1 = CHANNEL(channel)->unused_effect_3f.passes - 1u;
	passes_high = (uint8_t)(t1 >> 8);
	passes_low = (uint8_t)t1;
	CHANNEL(channel)->unused_effect_3f.passes = ((uint32_t)passes_high << 8) | passes_low;
	zero = (passes_low | passes_high) == 0u;
	return zero;
}
