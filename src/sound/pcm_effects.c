/**
 *    Name:        pcm_effects.c
 *    Description: the PCM effects (commands 40-7E, and 3F by its argument): samples of the K053260
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the Z80 sound program decompiled into C by
 *    tools/decompile_sound.py, with the names of sound_symbols.txt.
 */
#include "sound.h"

/* Command 3F 00: sample 16 (pcm_effect_3f_00_patch, level 0) at its own pitch, pan 4 (centred), keyed
   on; then pcm_effect_3f_00_wait_sample. */
void pcm_effect_3f_00(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_00_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_00_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 16 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_00_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 01: sample 17 (pcm_effect_3f_01_patch, level 0) at its own pitch, pan 4 (centred), keyed
   on; then pcm_effect_3f_01_wait_sample. */
void pcm_effect_3f_01(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_01_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_01_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 17 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_01_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 02: sample 18 (pcm_effect_3f_02_patch, level 0) at its own pitch, pan 4 (centred), keyed
   on; then pcm_effect_3f_02_wait_sample. */
void pcm_effect_3f_02(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_02_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_02_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 18 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_02_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 03: sample 19 (pcm_effect_3f_03_patch, level 0) at its own pitch, pan 4 (centred), keyed
   on; then pcm_effect_3f_03_wait_sample. */
void pcm_effect_3f_03(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_03_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_03_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 19 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_03_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 04: sample 20 (pcm_effect_3f_04_patch, level 0) at its own pitch, pan 4 (centred), keyed
   on; then pcm_effect_3f_04_wait_sample. */
void pcm_effect_3f_04(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_04_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_04_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 20 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_04_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 05: sample 21 (pcm_effect_3f_05_patch, level 0) at its own pitch, pan 4 (centred), keyed
   on; then pcm_effect_3f_05_wait_sample. */
void pcm_effect_3f_05(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_05_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_05_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 21 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_05_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 06: sample 22 (pcm_effect_3f_06_patch, level 0) at its own pitch, pan 4 (centred), keyed
   on; then pcm_effect_3f_06_wait_sample. */
void pcm_effect_3f_06(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_06_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_06_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 22 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_06_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 07: sample 23 (pcm_effect_3f_07_patch, level 0) at its own pitch, pan 4 (centred), keyed
   on; then pcm_effect_3f_07_wait_sample. */
void pcm_effect_3f_07(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_07_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_07_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 23 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_07_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 08: sample 24 (pcm_effect_3f_08_patch, level 0) at its own pitch, pan 4 (centred), keyed
   on; then pcm_effect_3f_08_wait_sample. */
void pcm_effect_3f_08(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_08_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_08_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 24 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_08_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 09: sample 25 (pcm_effect_3f_09_patch, level 0) at its own pitch, pan 4 (centred), keyed
   on; then pcm_effect_3f_09_wait_sample. */
void pcm_effect_3f_09(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_09_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_09_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 25 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_09_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 0A: sample 26 (pcm_effect_3f_0a_patch, level 0) at its own pitch, pan 4 (centred), keyed
   on; then pcm_effect_3f_0a_wait_sample. */
void pcm_effect_3f_0a(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_0a_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_0a_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 26 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_0a_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 0B: sample 27 (pcm_effect_3f_0b_patch, level 0) at its own pitch, pan 4 (centred), keyed
   on; then pcm_effect_3f_0b_wait_sample. */
void pcm_effect_3f_0b(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_0b_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_0b_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 27 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_0b_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 0C: sample 28 (pcm_effect_3f_0c_patch, level 0) at its own pitch, pan 4 (centred), keyed
   on; then pcm_effect_3f_0c_wait_sample. */
void pcm_effect_3f_0c(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_0c_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_0c_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 28 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_0c_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 0D: sample 29 (pcm_effect_3f_0d_patch, level 0) at its own pitch, pan 4 (centred), keyed
   on; then pcm_effect_3f_0d_wait_sample. */
void pcm_effect_3f_0d(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_0d_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_0d_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 29 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_0d_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 0E: sample 30 (pcm_effect_3f_0e_patch, level 0) at its own pitch, pan 4 (centred), keyed
   on; then pcm_effect_3f_0e_wait_sample. */
void pcm_effect_3f_0e(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_0e_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_0e_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 30 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_0e_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 0F: sample 31 (pcm_effect_3f_0f_patch, level 0) at its own pitch, pan 4 (centred), keyed
   on; then pcm_effect_3f_0f_wait_sample. */
void pcm_effect_3f_0f(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_0f_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_0f_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 31 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_0f_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 10: sample 32 (pcm_effect_3f_10_patch, level 0) at its own pitch, pan 4 (centred), keyed
   on; then pcm_effect_3f_10_wait_sample. */
void pcm_effect_3f_10(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_10_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_10_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 32 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_10_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 11: sample 33 (pcm_effect_3f_11_patch, level 0) at its own pitch, pan 4 (centred), keyed
   on; then pcm_effect_3f_11_wait_sample. */
void pcm_effect_3f_11(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_11_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_11_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 33 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_11_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 12: sample 34 (pcm_effect_3f_12_patch, level 0) at its own pitch, pan 4 (centred), keyed
   on; then pcm_effect_3f_12_wait_sample. */
void pcm_effect_3f_12(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_12_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_12_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 34 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_12_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 13: sample 35 (pcm_effect_3f_13_patch, level 0) at its own pitch, pan 4 (centred), keyed
   on; then pcm_effect_3f_13_wait_sample. */
void pcm_effect_3f_13(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_13_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_13_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 35 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_13_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 14: sample 36 (pcm_effect_3f_14_patch, level 0) at its own pitch, pan 4 (centred), keyed
   on; then pcm_effect_3f_14_wait_sample. */
void pcm_effect_3f_14(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_14_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_14_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 36 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_14_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 15: sample 37 (pcm_effect_3f_15_patch, level 0) at its own pitch, pan 4 (centred), keyed
   on; then pcm_effect_3f_15_wait_sample. */
void pcm_effect_3f_15(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_15_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_15_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 37 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_15_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 16: sample 38 (pcm_effect_3f_16_patch, level 0) at its own pitch, pan 4 (centred), keyed
   on; then pcm_effect_3f_16_wait_sample. */
void pcm_effect_3f_16(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_16_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_16_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 38 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_16_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 17: sample 39 (pcm_effect_3f_17_patch, level 0) at its own pitch, pan 4 (centred), keyed
   on; then pcm_effect_3f_17_wait_sample. */
void pcm_effect_3f_17(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_17_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_17_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 39 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_17_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 18: sample 0 (pcm_effect_3f_18_patch, level 0) at its own pitch, pan 4 (centred), keyed on;
   then pcm_effect_3f_18_wait_sample. */
void pcm_effect_3f_18(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_18_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_18_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 0 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_18_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 19: sample 1 (pcm_effect_3f_19_patch, level 0) at its own pitch, pan 4 (centred), keyed on;
   then pcm_effect_3f_19_wait_sample. */
void pcm_effect_3f_19(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_19_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_19_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 1 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_19_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 1A: sample 2 (pcm_effect_3f_1a_patch, level 0) at its own pitch, pan 4 (centred), keyed on;
   then pcm_effect_3f_1a_wait_sample. */
void pcm_effect_3f_1a(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_1a_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_1a_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 2 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_1a_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 1B: sample 3 (pcm_effect_3f_1b_patch, level 0) at its own pitch, pan 4 (centred), keyed on;
   then pcm_effect_3f_1b_wait_sample. */
void pcm_effect_3f_1b(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_1b_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_1b_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 3 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_1b_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 1C: sample 40 (pcm_effect_3f_1c_patch, level 0) at its own pitch, pan 4 (centred), keyed
   on; then pcm_effect_3f_1c_wait_sample. */
void pcm_effect_3f_1c(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_1c_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_1c_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 40 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_1c_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 1D: sample 41 (pcm_effect_3f_1d_patch, level 0) at its own pitch, pan 4 (centred), keyed
   on; then pcm_effect_3f_1d_wait_sample. */
void pcm_effect_3f_1d(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_1d_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_1d_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 41 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_1d_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 1E: sample 42 (pcm_effect_3f_1e_patch, level 0) at its own pitch, pan 4 (centred), keyed
   on; then pcm_effect_3f_1e_wait_sample. */
void pcm_effect_3f_1e(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_1e_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_1e_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 42 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_1e_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 1F: sample 43 (pcm_effect_3f_1f_patch, level 0) at its own pitch, pan 4 (centred), keyed
   on; then pcm_effect_3f_1f_wait_sample. */
void pcm_effect_3f_1f(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_1f_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_1f_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 43 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_1f_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 20: sample 4 (pcm_effect_3f_20_patch, level 50) at its own pitch, pan 2 (to the left),
   keyed on; then pcm_effect_3f_20_wait_sample. */
void pcm_effect_3f_20(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_20_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 2u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_20_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 4 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_20_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 21: sample 5 (pcm_effect_3f_21_patch, level 38) at its own pitch, pan 3 (a little to the
   left), keyed on; then pcm_effect_3f_21_wait_sample. */
void pcm_effect_3f_21(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_21_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 3u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_21_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 5 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_21_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 22: sample 6 (pcm_effect_3f_22_patch, level 50) at its own pitch, pan 5 (a little to the
   right), keyed on; then pcm_effect_3f_22_wait_sample. */
void pcm_effect_3f_22(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_22_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 5u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_22_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 6 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_22_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 23: sample 7 (pcm_effect_3f_23_patch, level 58) at its own pitch, pan 6 (to the right),
   keyed on; then pcm_effect_3f_23_wait_sample. */
void pcm_effect_3f_23(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_23_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 6u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_23_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 7 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_23_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 24: sample 8 (pcm_effect_3f_24_patch, level 0) at its own pitch, pan 2 (to the left), keyed
   on; then pcm_effect_3f_24_wait_sample. */
void pcm_effect_3f_24(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_24_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 2u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_24_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 8 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_24_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 25: sample 9 (pcm_effect_3f_25_patch, level 30) at its own pitch, pan 3 (a little to the
   left), keyed on; then pcm_effect_3f_25_wait_sample. */
void pcm_effect_3f_25(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_25_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 3u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_25_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 9 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_25_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 26: sample 10 (pcm_effect_3f_26_patch, level 10) at its own pitch, pan 5 (a little to the
   right), keyed on; then pcm_effect_3f_26_wait_sample. */
void pcm_effect_3f_26(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_26_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 5u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_26_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 10 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_26_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 27: sample 11 (pcm_effect_3f_27_patch, level 10) at its own pitch, pan 6 (to the right),
   keyed on; then pcm_effect_3f_27_wait_sample. */
void pcm_effect_3f_27(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_27_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 6u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_27_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 11 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_27_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 28: sample 12 (pcm_effect_3f_28_patch, level 0) at its own pitch, pan 4 (centred), keyed
   on; then pcm_effect_3f_28_wait_sample. */
void pcm_effect_3f_28(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_28_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_28_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 12 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_28_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 29: sample 13 (pcm_effect_3f_29_patch, level 20) at its own pitch, pan 4 (centred), keyed
   on; then pcm_effect_3f_29_wait_sample. */
void pcm_effect_3f_29(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_29_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_29_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 13 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_29_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 2A: sample 14 (pcm_effect_3f_2a_patch, level 20) at its own pitch, pan 4 (centred), keyed
   on; then pcm_effect_3f_2a_wait_sample. */
void pcm_effect_3f_2a(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_2a_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_2a_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 14 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_2a_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 2B: sample 15 (pcm_effect_3f_2b_patch, level 20) at its own pitch, pan 4 (centred), keyed
   on; then pcm_effect_3f_2b_wait_sample. */
void pcm_effect_3f_2b(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_2b_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_2b_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 15 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_2b_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 2C: sample 100 (pcm_effect_3f_2c_patch, level 0) at pitch EA0, pan 4 (centred), keyed on;
   then pcm_effect_3f_2c_wait_sample. */
void pcm_effect_3f_2c(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_effect_3f_2c_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xEA0u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_2c_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 100 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_2c_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 2D: sample 101 (pcm_effect_3f_2d_patch, level 0) at pitch E40, pan 4 (centred), keyed on;
   then pcm_effect_3f_2d_wait_sample. */
void pcm_effect_3f_2d(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_effect_3f_2d_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xE40u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_2d_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 101 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_2d_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 2E: sample 101 (pcm_effect_3f_2e_patch, level 0) at pitch EE0, pan 4 (centred), keyed on;
   then pcm_effect_3f_2e_wait_sample. */
void pcm_effect_3f_2e(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_effect_3f_2e_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xEE0u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_2e_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 101 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_2e_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 2F: stop_channel at once. Its priority is 0 (effect_priorities_2), so it only takes a free
   record: an empty slot, which the sound test leaves out (sound_test_effects). */
void pcm_effect_3f_2f(uint16_t channel)
{
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 30: sample 45 (pcm_effect_3f_30_patch, level 0) at pitch EE0, pan 4 (centred), keyed on;
   then pcm_effect_3f_30_wait_sample. */
void pcm_effect_3f_30(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_effect_3f_30_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xEE0u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_30_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 45 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_30_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 31: sample 46 (pcm_effect_3f_31_patch, level 0) at pitch EE0, pan 4 (centred), keyed on;
   then pcm_effect_3f_31_wait_sample. */
void pcm_effect_3f_31(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_effect_3f_31_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xEE0u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_31_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 46 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_31_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 32: sample 47 (pcm_effect_3f_32_patch, level 0) at pitch EE0, pan 4 (centred), keyed on;
   then pcm_effect_3f_32_wait_sample. */
void pcm_effect_3f_32(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_effect_3f_32_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xEE0u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_32_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 47 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_32_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 33: sample 48 (pcm_effect_3f_33_patch, level 0) at pitch EE0, pan 4 (centred), keyed on;
   then pcm_effect_3f_33_wait_sample. */
void pcm_effect_3f_33(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_effect_3f_33_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xEE0u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_33_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 48 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_33_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 34: sample 50 (pcm_effect_3f_34_patch, level 0) at pitch EF0, pan 4 (centred), keyed on;
   then pcm_effect_3f_34_wait_sample. */
void pcm_effect_3f_34(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_effect_3f_34_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xEF0u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_34_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 50 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_34_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 35: sample 51 (pcm_effect_3f_35_patch, level 0) at pitch EF0, pan 4 (centred), keyed on;
   then pcm_effect_3f_35_wait_sample. */
void pcm_effect_3f_35(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_effect_3f_35_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xEF0u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_35_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 51 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_35_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 36: sample 52 (pcm_effect_3f_36_patch, level 0) at pitch EF0, pan 4 (centred), keyed on;
   then pcm_effect_3f_36_wait_sample. */
void pcm_effect_3f_36(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_effect_3f_36_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xEF0u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_36_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 52 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_36_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 37: sample 49 (pcm_effect_3f_37_patch, level 40) at pitch EF0, pan 4 (centred), keyed on;
   then pcm_effect_3f_37_wait_sample. */
void pcm_effect_3f_37(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_effect_3f_37_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xEF0u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_37_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 49 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_37_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 38: sample 98 (pcm_effect_3f_38_patch, level 0) at its own pitch, pan 4 (centred), keyed
   on; then pcm_effect_3f_38_wait_sample. */
void pcm_effect_3f_38(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_38_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_38_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 98 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_38_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Unused: set_volume with the volume it is given, then stop_channel once the record's attenuation is 7F:
   the end of a fade out, which pcm_effect_7a_fade_out, pcm_effect_7c_fade_out and pcm_effect_7e_fade_out
   do on their own. */
void set_volume_stop_at_7f(uint16_t channel, uint8_t volume)
{
	z80_block(17);
	set_volume(channel, volume);
	z80_block(31);
	if (CHANNEL(channel)->pcm_effect_7a.attenuation != 0x7Fu)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 39: sample 97 (pcm_effect_3f_39_patch, level 0) at its own pitch, pan 4 (centred), keyed
   on; then pcm_effect_3f_39_wait_sample. */
void pcm_effect_3f_39(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_3f_39_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_39_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 97 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_39_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 3A: sample 78 (pcm_effect_3f_3a_patch, level 10) at its own pitch, pan 4 (centred), keyed
   on; then pcm_effect_3f_3a_wait_sample. */
void pcm_effect_3f_3a(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(27);
	patch = pcm_effect_3f_3a_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_3a_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 78 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_3a_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 3F 3B: sample 95 (pcm_effect_3f_3b_patch, level 10) at its own pitch, pan 4 (centred), keyed
   on; then pcm_effect_3f_3b_wait_sample. */
void pcm_effect_3f_3b(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(27);
	patch = pcm_effect_3f_3b_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_3f_3b_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 95 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_3f_3b_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 42: sample 114 (pcm_effect_42_patch, level 10, decay step 6), pan 4 (centred), then
   pcm_effect_42_setup with pcm_effect_42_notes: the third part of the jingle of effects 40, 41 and 42,
   whose notes fade in their rests. */
void pcm_effect_42(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t notes = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_42_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(20);
	notes = pcm_effect_42_notes_ADDRESS;
	pcm_effect_42_setup(notes, channel);
}

/* Command 41: sample 105 (pcm_effect_41_patch, level 10), pan 4 (centred), then pcm_effect_42_setup with
   pcm_effect_41_notes: the second part of the jingle of effects 40, 41 and 42. */
void pcm_effect_41(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t notes = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_41_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(20);
	notes = pcm_effect_41_notes_ADDRESS;
	pcm_effect_42_setup(notes, channel);
}

/* Command 40: sample 115 (pcm_effect_40_patch, level 30), pan 4 (centred), then pcm_effect_42_setup with
   pcm_effect_40_notes: the first part of a jingle of five notes in the same rhythm on three voices
   (command 40 with argument 2 starts 40, 41 and 42; their priority C0 outlasts command 00). */
void pcm_effect_40(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t notes = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_40_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(10);
	notes = pcm_effect_40_notes_ADDRESS;
	pcm_effect_42_setup(notes, channel);
}

/* The list of notes of effect 40, 41 or 42 into notes, 1 pass to wait, then pcm_effect_42_next_note. */
void pcm_effect_42_setup(uint16_t notes, uint16_t channel)
{
	uint16_t handler = 0;

	z80_block(96);
	CHANNEL(channel)->pcm_effect_42.notes = notes;
	CHANNEL(channel)->pcm_effect_42.passes = 1u;
	handler = pcm_effect_42_next_note_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When the passes have run out (pcm_effect_42_update), the list's next note: its pitch (0 ends the
   effect: stop_channel) and its length into passes, keyed on (the sample from its start); then
   pcm_effect_42_rest. */
void pcm_effect_42_next_note(uint16_t channel)
{
	uint32_t passes_ran_out = 0;
	uint8_t word_high = 0, word_low = 0;
	uint16_t handler = 0, note = 0, notes = 0, pitch = 0;
	uint16_t saved_note = 0;

	z80_block(17);
	passes_ran_out = pcm_effect_42_update(channel);
	z80_block(5);
	if (passes_ran_out == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(82);
	note = CHANNEL(channel)->pcm_effect_42.notes;
	word_low = z80_read8(note);
	note++;
	word_high = z80_read8(note);
	note++;
	if ((word_low | word_high) == 0u)
	{
		stop_channel(channel);
		return;
	}
	z80_block(32);
	saved_note = note;
	pitch = ((uint32_t)word_high << 8) | word_low;
	set_pitch(pitch, channel);
	z80_block(129);
	notes = saved_note;
	word_low = z80_read8(notes);
	notes++;
	word_high = z80_read8(notes);
	notes++;
	CHANNEL(channel)->pcm_effect_42.passes = ((uint32_t)word_high << 8) | word_low;
	CHANNEL(channel)->pcm_effect_42.notes = notes;
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_42_rest_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When the note's passes have run out, the rest's length from the list into passes and key off (the
   voice decays by its patch's decay step every 16 passes); then pcm_effect_42_next_note. */
void pcm_effect_42_rest(uint16_t channel)
{
	uint32_t passes_ran_out = 0;
	uint8_t word_high = 0, word_low = 0;
	uint16_t handler = 0, notes = 0;

	z80_block(17);
	passes_ran_out = pcm_effect_42_update(channel);
	z80_block(5);
	if (passes_ran_out == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(157);
	notes = CHANNEL(channel)->pcm_effect_42.notes;
	word_low = z80_read8(notes);
	notes++;
	word_high = z80_read8(notes);
	notes++;
	CHANNEL(channel)->pcm_effect_42.passes = ((uint32_t)word_high << 8) | word_low;
	CHANNEL(channel)->pcm_effect_42.notes = notes;
	key_off(channel);
	z80_block(20);
	handler = pcm_effect_42_next_note_ADDRESS;
	set_channel_handler(handler, channel);
}

/* One pass less of the note or the rest (passes); true when none is left. */
uint32_t pcm_effect_42_update(uint16_t channel)
{
	uint32_t passes_ran_out = 0;
	uint8_t passes_high = 0, passes_low = 0;
	uint16_t passes_left = 0;

	z80_block(100);
	passes_left = CHANNEL(channel)->pcm_effect_42.passes - 1u;
	passes_high = (uint8_t)(passes_left >> 8);
	passes_low = (uint8_t)passes_left;
	CHANNEL(channel)->pcm_effect_42.passes = ((uint32_t)passes_high << 8) | passes_low;
	passes_ran_out = (passes_low | passes_high) == 0u;
	return passes_ran_out;
}

/* Command 43: sample 145 (pcm_effect_43_patch, level 40) at its own pitch, pan 4 (centred), keyed on;
   then pcm_effect_43_wait_sample. */
void pcm_effect_43(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_43_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_43_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 145 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_43_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 44: sample 53 (pcm_effect_44_patch, level 0) at its own pitch, pan 4 (centred), keyed on; then
   pcm_effect_44_wait_sample. */
void pcm_effect_44(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_44_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_44_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 53 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_44_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 45: sample 54 (pcm_effect_45_patch, level 0) at its own pitch, pan 4 (centred), keyed on; then
   pcm_effect_45_wait_sample. */
void pcm_effect_45(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_45_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_45_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 54 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_45_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 46: sample 59 (pcm_effect_46_patch, level 38) at its own pitch, pan 4 (centred), keyed on, to
   play 4 times (count); then pcm_effect_46_retrigger. */
void pcm_effect_46(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_46_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(39);
	CHANNEL(channel)->count = 4u;
	handler = pcm_effect_46_retrigger_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Each time the sample ends (pcm_voice_playing), one play less: after the last, stop_channel; before,
   key off and on (the sample again from its start). */
void pcm_effect_46_retrigger(uint16_t channel)
{
	uint32_t voice_ended = 0;
	uint8_t count = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(33);
	count = CHANNEL(channel)->count;
	CHANNEL(channel)->count = count - 1u;
	if (count == 1u)
	{
		stop_channel(channel);
		return;
	}
	z80_block(17);
	key_off(channel);
	z80_block(10);
	key_on(channel);
}

/* Command 47: sample 81 (pcm_effect_47_patch, level 10) at its own pitch, pan 4 (centred), keyed on;
   then pcm_effect_47_wait_sample. */
void pcm_effect_47(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_47_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_47_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 81 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_47_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 48: sample 70 (pcm_effect_48_patch, level 10) at its own pitch, pan 4 (centred), keyed on;
   then pcm_effect_48_wait_sample. */
void pcm_effect_48(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_48_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_48_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 70 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_48_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 49: sample 91 (pcm_effect_49_patch, level 0) at its own pitch, pan 4 (centred), keyed on; then
   pcm_effect_49_wait_sample. */
void pcm_effect_49(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_49_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_49_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 91 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_49_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 4A: sample 54 (pcm_effect_4a_patch, level 40) at its own pitch, pan 4 (centred), keyed on;
   then pcm_effect_4a_wait_sample. */
void pcm_effect_4a(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_4a_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_4a_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 54 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_4a_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 4B: sample 44 (pcm_effect_4b_patch, level 0) at its own pitch, pan 4 (centred), keyed on; then
   pcm_effect_4b_wait_sample. */
void pcm_effect_4b(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_4b_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_4b_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 44 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_4b_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 4C: sample 72 (pcm_effect_4c_patch, level 0) at its own pitch, pan 4 (centred), keyed on; then
   pcm_effect_4c_wait_sample. */
void pcm_effect_4c(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_4c_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_4c_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 72 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_4c_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 4D: sample 73 (pcm_effect_4d_patch, level 20) at its own pitch, pan 4 (centred), keyed on;
   then pcm_effect_4d_wait_sample. */
void pcm_effect_4d(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_4d_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_4d_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 73 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_4d_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 4E: sample 90 (pcm_effect_4e_patch, level 20) at its own pitch, pan 4 (centred), keyed on;
   then pcm_effect_4e_wait_sample. */
void pcm_effect_4e(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_4e_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_4e_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 90 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_4e_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 4F: sample 69 (pcm_effect_4f_patch, level 0) at its own pitch, pan 4 (centred), keyed on; then
   pcm_effect_4f_wait_sample. */
void pcm_effect_4f(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_4f_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_4f_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 69 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_4f_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 50: sample 147 (pcm_effect_50_patch, level 0) at pitch F00, pan 4 (centred), keyed on silent
   (attenuation 7F, set_volume), timer 1; then pcm_effect_50_fade. */
void pcm_effect_50(uint16_t channel)
{
	uint8_t pan = 0, volume = 0;
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_effect_50_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xF00u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(43);
	volume = 0x7Fu;
	CHANNEL(channel)->pcm_effect_50.attenuation = 0x7Fu;
	set_volume(channel, volume);
	z80_block(17);
	key_on(channel);
	z80_block(39);
	CHANNEL(channel)->timer = 1u;
	handler = pcm_effect_50_fade_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Fades the sample in: every pass the attenuation one less (set_volume), down to 0 (127 passes); then
   pcm_effect_50_wait_sample. */
void pcm_effect_50_fade(uint16_t channel)
{
	uint8_t attenuation = 0;
	uint16_t handler = 0;
	uint8_t timer = 0;

	z80_block(28);
	timer = CHANNEL(channel)->timer;
	CHANNEL(channel)->timer = timer - 1u;
	if (timer != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(78);
	CHANNEL(channel)->timer = 1u;
	CHANNEL(channel)->pcm_effect_50.attenuation--;
	attenuation = CHANNEL(channel)->pcm_effect_50.attenuation;
	set_volume(channel, attenuation);
	z80_block(28);
	if (CHANNEL(channel)->pcm_effect_50.attenuation != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(20);
	handler = pcm_effect_50_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 147 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_50_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 51: sample 146 (pcm_effect_51_patch, level 0) at pitch F00, pan 4 (centred), keyed on; then
   pcm_effect_51_wait_sample. */
void pcm_effect_51(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_effect_51_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xF00u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_51_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 146 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_51_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 52: sample 94 (pcm_effect_52_patch, level 20, decay step 8) at pitch F00, pan 4 (centred),
   keyed on for 112 passes (count); then pcm_effect_52_delay. */
void pcm_effect_52(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_effect_52_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xF00u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(39);
	CHANNEL(channel)->count = 0x70u;
	handler = pcm_effect_52_delay_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When the count runs out, key off (the sample fades, 8 more attenuation every 16 passes) and a count of
   256 passes; then pcm_effect_52_hold. */
void pcm_effect_52_delay(uint16_t channel)
{
	uint16_t handler = 0;
	uint8_t count = 0;

	z80_block(28);
	count = CHANNEL(channel)->count;
	CHANNEL(channel)->count = count - 1u;
	if (count != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(17);
	key_off(channel);
	z80_block(39);
	CHANNEL(channel)->count = 0u;
	handler = pcm_effect_52_hold_ADDRESS;
	set_channel_handler(handler, channel);
}

/* After 256 passes, stop_channel, whether the sample has ended or not. */
void pcm_effect_52_hold(uint16_t channel)
{
	uint8_t count = 0;

	z80_block(28);
	count = CHANNEL(channel)->count;
	CHANNEL(channel)->count = count - 1u;
	if (count != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 53: sample 92 (pcm_effect_53_patch, level 0) at its own pitch, pan 4 (centred), keyed on; then
   pcm_effect_53_wait_sample. */
void pcm_effect_53(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_53_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_53_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 92 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_53_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 54: sample 55 (pcm_effect_54_patch, level 0) at its own pitch, pan 6 (to the right), keyed on,
   timer 144; then pcm_effect_54_modulate. */
void pcm_effect_54(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_54_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(43);
	pan = 6u;
	CHANNEL(channel)->pcm_effect_54.pan = 6u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(39);
	CHANNEL(channel)->pcm_effect_54.timer = 0x90u;
	handler = pcm_effect_54_modulate_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Every 144 passes the pan one step to the left, from 6 down to 2 (the sound crosses from right to left
   in 576 passes); then pcm_effect_54_wait_sample. */
void pcm_effect_54_modulate(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0;
	uint8_t timer = 0;

	z80_block(28);
	timer = CHANNEL(channel)->pcm_effect_54.timer;
	CHANNEL(channel)->pcm_effect_54.timer = timer - 1u;
	if (timer != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(78);
	CHANNEL(channel)->pcm_effect_54.timer = 0x90u;
	CHANNEL(channel)->pcm_effect_54.pan--;
	pan = CHANNEL(channel)->pcm_effect_54.pan;
	set_pan(channel, pan);
	z80_block(31);
	if (CHANNEL(channel)->pcm_effect_54.pan != 2u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(20);
	handler = pcm_effect_54_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 55 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_54_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 55: sample 68 (pcm_effect_55_patch, level 0) at pitch E40, pan 4 (centred), keyed on; then
   pcm_effect_55_wait_sample. */
void pcm_effect_55(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_effect_55_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xE40u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_55_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 68 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_55_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 56: sample 79 (pcm_effect_56_patch, level 0) at pitch E00, volume 0 (set_volume), pan 6 (to
   the right), keyed on; then pcm_effect_56_retrigger. */
void pcm_effect_56(uint16_t channel)
{
	uint8_t pan = 0, volume = 0;
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_effect_56_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xE00u;
	set_pitch(pitch, channel);
	z80_block(24);
	volume = 0u;
	set_volume(channel, volume);
	z80_block(24);
	pan = 6u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_56_retrigger_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When the sample ends (pcm_voice_playing), key off and on again at volume 60, pan 3 (a little to the
   left): an echo; then pcm_effect_56_retrigger_2. */
void pcm_effect_56_retrigger(uint16_t channel)
{
	uint32_t voice_ended = 0;
	uint8_t pan = 0, volume = 0;
	uint16_t handler = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(17);
	key_off(channel);
	z80_block(24);
	volume = 0x60u;
	set_volume(channel, volume);
	z80_block(24);
	pan = 3u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_56_retrigger_2_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When it ends, a third time at volume 70, pan 2 (to the left); then pcm_effect_56_wait_sample. */
void pcm_effect_56_retrigger_2(uint16_t channel)
{
	uint32_t voice_ended = 0;
	uint8_t pan = 0, volume = 0;
	uint16_t handler = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(17);
	key_off(channel);
	z80_block(24);
	volume = 0x70u;
	set_volume(channel, volume);
	z80_block(24);
	pan = 2u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_56_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 79 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_56_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 57: sample 74 (pcm_effect_57_patch, level 0, decay step 9) at pitch F00, pan 4 (centred),
   keyed on for 512 passes; then pcm_effect_57_retrigger. */
void pcm_effect_57(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_effect_57_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xF00u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(68);
	CHANNEL(channel)->pcm_effect_57.passes = 0x200u;
	handler = pcm_effect_57_retrigger_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When the passes run out (pcm_effect_57_update), sample 74 again from its start at pitch EC0 (lower),
   keyed off at once so that it fades (9 more attenuation every 16 passes), for 640 passes; then
   pcm_effect_57_note. */
void pcm_effect_57_retrigger(uint16_t channel)
{
	uint32_t passes_ran_out = 0;
	uint16_t handler = 0, pitch = 0;

	z80_block(17);
	passes_ran_out = pcm_effect_57_update(channel);
	z80_block(5);
	if (passes_ran_out == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(17);
	key_off(channel);
	z80_block(27);
	pitch = 0xEC0u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(17);
	key_off(channel);
	z80_block(68);
	CHANNEL(channel)->pcm_effect_57.passes = 0x280u;
	handler = pcm_effect_57_note_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When the passes run out, sample 17 (pcm_effect_57_patch_2, level 10) at pitch F60, pan 4 (centred),
   keyed on; then pcm_effect_57_wait_sample. */
void pcm_effect_57_note(uint16_t channel)
{
	uint32_t passes_ran_out = 0;
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(17);
	passes_ran_out = pcm_effect_57_update(channel);
	z80_block(5);
	if (passes_ran_out == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(27);
	patch = pcm_effect_57_patch_2_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xF60u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_57_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 17 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_57_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* One pass less (passes); true when none is left. */
uint32_t pcm_effect_57_update(uint16_t channel)
{
	uint32_t passes_ran_out = 0;
	uint8_t passes_high = 0, passes_low = 0;
	uint16_t passes_left = 0;

	z80_block(100);
	passes_left = CHANNEL(channel)->pcm_effect_57.passes - 1u;
	passes_high = (uint8_t)(passes_left >> 8);
	passes_low = (uint8_t)passes_left;
	CHANNEL(channel)->pcm_effect_57.passes = ((uint32_t)passes_high << 8) | passes_low;
	passes_ran_out = (passes_high | passes_low) == 0u;
	return passes_ran_out;
}

/* Command 58: sample 77 (pcm_effect_58_patch, level 0) at pitch FA0, pan 4 (centred), keyed on, to play
   5 times (count); then pcm_effect_58_retrigger. */
void pcm_effect_58(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_effect_58_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xFA0u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(39);
	CHANNEL(channel)->count = 5u;
	handler = pcm_effect_58_retrigger_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Each time the sample ends (pcm_voice_playing), one play less: after the last, stop_channel; before,
   key off and on (the sample again from its start). */
void pcm_effect_58_retrigger(uint16_t channel)
{
	uint32_t voice_ended = 0;
	uint8_t count = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(33);
	count = CHANNEL(channel)->count;
	CHANNEL(channel)->count = count - 1u;
	if (count == 1u)
	{
		stop_channel(channel);
		return;
	}
	z80_block(17);
	key_off(channel);
	z80_block(10);
	key_on(channel);
}

/* Command 59: sample 144 (pcm_effect_59_patch, level 0) at its own pitch, pan 4 (centred), keyed on;
   then pcm_effect_59_wait_sample. */
void pcm_effect_59(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_59_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_59_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 144 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_59_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 5A: sample 74 (pcm_effect_5a_patch, level 0) at its own pitch, pan 4 (centred), keyed on; then
   pcm_effect_5a_wait_sample. */
void pcm_effect_5a(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_5a_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_5a_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 74 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_5a_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 5B: sample 74 (pcm_effect_5b_patch, level 0, decay step 8) at its own pitch, pan 4 (centred),
   keyed on and off at once, so that it fades from its start (8 more attenuation every 16 passes); then
   pcm_effect_5b_wait_sample. */
void pcm_effect_5b(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_5b_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(17);
	key_off(channel);
	z80_block(20);
	handler = pcm_effect_5b_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 74 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_5b_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 5C: sample 94 (pcm_effect_5c_patch, level 0, decay step 10) at pitch F40, pan 4 (centred),
   keyed on for 64 passes (count); then pcm_effect_5c_delay. */
void pcm_effect_5c(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_effect_5c_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xF40u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(39);
	CHANNEL(channel)->count = 0x40u;
	handler = pcm_effect_5c_delay_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When the count runs out, key off (the sample fades, 10 more attenuation every 16 passes) and a count
   of 256 passes; then pcm_effect_5c_hold. */
void pcm_effect_5c_delay(uint16_t channel)
{
	uint16_t handler = 0;
	uint8_t count = 0;

	z80_block(28);
	count = CHANNEL(channel)->count;
	CHANNEL(channel)->count = count - 1u;
	if (count != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(17);
	key_off(channel);
	z80_block(39);
	CHANNEL(channel)->count = 0u;
	handler = pcm_effect_5c_hold_ADDRESS;
	set_channel_handler(handler, channel);
}

/* After 256 passes, stop_channel, whether the sample has ended or not. */
void pcm_effect_5c_hold(uint16_t channel)
{
	uint8_t count = 0;

	z80_block(28);
	count = CHANNEL(channel)->count;
	CHANNEL(channel)->count = count - 1u;
	if (count != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 5D: sample 94 (pcm_effect_5d_patch, level 0, decay step 8) at its own pitch, pan 4 (centred),
   keyed on for 128 passes (count); then pcm_effect_5d_delay. */
void pcm_effect_5d(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_5d_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(39);
	CHANNEL(channel)->count = 0x80u;
	handler = pcm_effect_5d_delay_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When the count runs out, key off (the sample fades, 8 more attenuation every 16 passes) and a count of
   256 passes; then pcm_effect_5d_hold. */
void pcm_effect_5d_delay(uint16_t channel)
{
	uint16_t handler = 0;
	uint8_t count = 0;

	z80_block(28);
	count = CHANNEL(channel)->count;
	CHANNEL(channel)->count = count - 1u;
	if (count != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(17);
	key_off(channel);
	z80_block(39);
	CHANNEL(channel)->count = 0u;
	handler = pcm_effect_5d_hold_ADDRESS;
	set_channel_handler(handler, channel);
}

/* After 256 passes, stop_channel, whether the sample has ended or not. */
void pcm_effect_5d_hold(uint16_t channel)
{
	uint8_t count = 0;

	z80_block(28);
	count = CHANNEL(channel)->count;
	CHANNEL(channel)->count = count - 1u;
	if (count != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 5E: sample 77 (pcm_effect_5e_patch, level 0) at its own pitch, pan 4 (centred), keyed on; then
   pcm_effect_5e_wait_sample. */
void pcm_effect_5e(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_5e_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_5e_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 77 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_5e_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 5F: sample 58 (pcm_effect_5f_patch, level 0) at its own pitch, pan 4 (centred), keyed on; then
   pcm_effect_5f_wait_sample. */
void pcm_effect_5f(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_5f_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_5f_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 58 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_5f_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 60: sample 57 (pcm_effect_60_patch, level 0) at its own pitch, pan 4 (centred), keyed on; then
   pcm_effect_60_wait_sample. */
void pcm_effect_60(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_60_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_60_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 57 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_60_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 61: sample 60 (pcm_effect_61_patch, level 10) at its own pitch, pan 4 (centred), keyed on;
   then pcm_effect_61_wait_sample. */
void pcm_effect_61(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_61_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_61_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 60 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_61_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 62: sample 76 (pcm_effect_62_patch, level 0) at its own pitch, pan 4 (centred), keyed on; then
   pcm_effect_62_wait_sample. */
void pcm_effect_62(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_62_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_62_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 76 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_62_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 63: sample 56 (pcm_effect_63_patch, level 30) at its own pitch, pan 4 (centred), keyed on;
   then pcm_effect_63_wait_sample. */
void pcm_effect_63(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_63_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_63_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 56 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_63_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 64: sample 64 (pcm_effect_64_patch, level 10) at its own pitch, pan 4 (centred), keyed on;
   then pcm_effect_64_wait_sample. */
void pcm_effect_64(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_64_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_64_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 64 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_64_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 65: sample 122 (pcm_effect_65_patch, level 30) at its own pitch, pan 4 (centred), keyed on;
   then pcm_effect_65_wait_sample. */
void pcm_effect_65(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_65_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_65_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 122 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_65_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 66: sample 102 (pcm_effect_66_patch, level 10) at its own pitch, pan 4 (centred), keyed on;
   then pcm_effect_66_wait_sample. */
void pcm_effect_66(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_66_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_66_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 102 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_66_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 67: sample 61 (pcm_effect_67_patch, level 10) at its own pitch, pan 4 (centred), keyed on;
   then pcm_effect_67_wait_sample. */
void pcm_effect_67(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_67_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_67_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 61 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_67_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 68: sample 62 (pcm_effect_68_patch, level 10) at its own pitch, pan 4 (centred), keyed on;
   then pcm_effect_68_wait_sample. */
void pcm_effect_68(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_68_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_68_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 62 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_68_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 69: sample 63 (pcm_effect_69_patch, level 20) at its own pitch, pan 4 (centred), keyed on;
   then pcm_effect_69_wait_sample. */
void pcm_effect_69(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_69_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_69_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 63 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_69_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 6A: sample 83 (pcm_effect_6a_patch, level 10) at its own pitch, pan 4 (centred), keyed on;
   then pcm_effect_6a_wait_sample. */
void pcm_effect_6a(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_6a_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_6a_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 83 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_6a_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 6B: sample 66 (pcm_effect_6b_patch, level 30) at its own pitch, pan 4 (centred), keyed on;
   then pcm_effect_6b_wait_sample. */
void pcm_effect_6b(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_6b_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_6b_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 66 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_6b_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 6C: sample 67 (pcm_effect_6c_patch, level 40) at its own pitch, pan 4 (centred), keyed on;
   then pcm_effect_6c_wait_sample. */
void pcm_effect_6c(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_6c_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_6c_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 67 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_6c_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 6D: sample 75 (pcm_effect_6d_patch, level 0) at its own pitch, pan 4 (centred), keyed on; then
   pcm_effect_6d_wait_sample. */
void pcm_effect_6d(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_6d_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_6d_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 75 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_6d_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 6E: sample 94 (pcm_effect_6e_patch, level 0) at its own pitch, pan 4 (centred), keyed on; then
   pcm_effect_6e_wait_sample. */
void pcm_effect_6e(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_6e_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_6e_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 94 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_6e_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 6F: sample 65 (pcm_effect_6f_patch, level 0) at its own pitch, pan 4 (centred), keyed on; then
   pcm_effect_6f_wait_sample. */
void pcm_effect_6f(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_6f_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_6f_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 65 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_6f_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 70: sample 84 (pcm_effect_70_patch, level 0) at its own pitch, pan 4 (centred), keyed on; then
   pcm_effect_70_wait_sample. */
void pcm_effect_70(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_70_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_70_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 84 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_70_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 71: sample 93 (pcm_effect_71_patch, level 0) at its own pitch, pan 4 (centred), keyed on; then
   pcm_effect_71_wait_sample. */
void pcm_effect_71(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_71_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_71_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 93 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_71_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 72: sample 80 (pcm_effect_72_patch, level 20) at its own pitch, pan 4 (centred), keyed on;
   then pcm_effect_72_wait_sample. */
void pcm_effect_72(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(27);
	patch = pcm_effect_72_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_72_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 80 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_72_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 73: sample 85 (pcm_effect_73_patch, level 30) at its own pitch, pan 4 (centred), keyed on;
   then pcm_effect_73_wait_sample. */
void pcm_effect_73(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(27);
	patch = pcm_effect_73_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_73_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 85 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_73_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 74: sample 86 (pcm_effect_74_patch, level 30) at its own pitch, pan 4 (centred), keyed on;
   then pcm_effect_74_wait_sample. */
void pcm_effect_74(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(27);
	patch = pcm_effect_74_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_74_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 86 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_74_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 75: sample 87 (pcm_effect_75_patch, level 10) at its own pitch, pan 4 (centred), keyed on;
   then pcm_effect_75_wait_sample. */
void pcm_effect_75(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(27);
	patch = pcm_effect_75_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_75_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 87 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_75_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 76: sample 96 (pcm_effect_76_patch, level 20) at its own pitch, pan 4 (centred), keyed on;
   then pcm_effect_76_wait_sample. */
void pcm_effect_76(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(27);
	patch = pcm_effect_76_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_76_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 96 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_76_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 77: sample 94 (pcm_effect_77_patch, level 0, decay step 4) at its own pitch, pan 4 (centred),
   keyed on for 128 passes (count); then pcm_effect_77_delay. */
void pcm_effect_77(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_77_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(39);
	CHANNEL(channel)->count = 0x80u;
	handler = pcm_effect_77_delay_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When the count runs out, key off (the sample fades, 4 more attenuation every 16 passes) and a count of
   256 passes; then pcm_effect_77_hold. */
void pcm_effect_77_delay(uint16_t channel)
{
	uint16_t handler = 0;
	uint8_t count = 0;

	z80_block(28);
	count = CHANNEL(channel)->count;
	CHANNEL(channel)->count = count - 1u;
	if (count != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(17);
	key_off(channel);
	z80_block(39);
	CHANNEL(channel)->count = 0u;
	handler = pcm_effect_77_hold_ADDRESS;
	set_channel_handler(handler, channel);
}

/* After 256 passes, stop_channel, whether the sample has ended or not. */
void pcm_effect_77_hold(uint16_t channel)
{
	uint8_t count = 0;

	z80_block(28);
	count = CHANNEL(channel)->count;
	CHANNEL(channel)->count = count - 1u;
	if (count != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 78: stop_channel at once. Its priority is 0 (effect_priorities_40), so it only takes a free
   record: an empty slot, which the sound test leaves out (sound_test_effects). */
void pcm_effect_78(uint16_t channel)
{
	z80_block(10);
	stop_channel(channel);
}

/* Command 79: sample 68 (pcm_effect_79_patch, level 0) at its own pitch, pan 4 (centred), keyed on; then
   pcm_effect_79_wait_sample. */
void pcm_effect_79(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_79_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_79_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 68 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_79_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 7A: sample 88 (pcm_effect_7a_patch, level 20) at its own pitch, pan 4 (centred), keyed on at
   attenuation 60 (set_volume), timer 1; then pcm_effect_7a_fade_in. */
void pcm_effect_7a(uint16_t channel)
{
	uint8_t pan = 0, volume = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_7a_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(43);
	volume = 0x60u;
	CHANNEL(channel)->pcm_effect_7a.attenuation = 0x60u;
	set_volume(channel, volume);
	z80_block(17);
	key_on(channel);
	z80_block(39);
	CHANNEL(channel)->timer = 1u;
	handler = pcm_effect_7a_fade_in_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Fades in: every pass the attenuation one less (set_volume), down to 0 (96 passes), the sample played
   again whenever it ends (pcm_effect_7a_replay); then passes 2560 (the word over the attenuation and the
   timer) and pcm_effect_7a_delay. */
void pcm_effect_7a_fade_in(uint16_t channel)
{
	uint8_t attenuation = 0;
	uint16_t handler = 0;
	uint8_t timer = 0;

	z80_block(17);
	pcm_effect_7a_replay(channel);
	z80_block(28);
	timer = CHANNEL(channel)->timer;
	CHANNEL(channel)->timer = timer - 1u;
	if (timer != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(78);
	CHANNEL(channel)->timer = 1u;
	CHANNEL(channel)->pcm_effect_7a.attenuation--;
	attenuation = CHANNEL(channel)->pcm_effect_7a.attenuation;
	set_volume(channel, attenuation);
	z80_block(28);
	if (CHANNEL(channel)->pcm_effect_7a.attenuation != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(68);
	CHANNEL(channel)->pcm_effect_7a.passes = 0xA00u;
	handler = pcm_effect_7a_delay_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Holds the sound until passes runs out, played again whenever it ends; then attenuation 0, timer 1 and
   pcm_effect_7a_fade_out. */
void pcm_effect_7a_delay(uint16_t channel)
{
	uint8_t passes_high = 0, passes_low = 0;
	uint16_t handler = 0;
	uint16_t passes_left = 0;

	z80_block(17);
	pcm_effect_7a_replay(channel);
	z80_block(95);
	passes_left = CHANNEL(channel)->pcm_effect_7a.passes - 1u;
	passes_high = (uint8_t)(passes_left >> 8);
	passes_low = (uint8_t)passes_left;
	CHANNEL(channel)->pcm_effect_7a.passes = ((uint32_t)passes_high << 8) | passes_low;
	if ((passes_low | passes_high) != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(58);
	CHANNEL(channel)->pcm_effect_7a.passes = 0x100u;
	handler = pcm_effect_7a_fade_out_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Fades out: every 8 passes the attenuation one more (set_volume), the sample played again whenever it
   ends; at 7F, stop_channel. */
void pcm_effect_7a_fade_out(uint16_t channel)
{
	uint8_t attenuation = 0;
	uint8_t timer = 0;

	z80_block(17);
	pcm_effect_7a_replay(channel);
	z80_block(28);
	timer = CHANNEL(channel)->timer;
	CHANNEL(channel)->timer = timer - 1u;
	if (timer != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(78);
	CHANNEL(channel)->timer = 8u;
	CHANNEL(channel)->pcm_effect_7a.attenuation++;
	attenuation = CHANNEL(channel)->pcm_effect_7a.attenuation;
	set_volume(channel, attenuation);
	z80_block(31);
	if (CHANNEL(channel)->pcm_effect_7a.attenuation != 0x7Fu)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* When the sample has ended (pcm_voice_playing), key off and on: the sample again from its start. */
void pcm_effect_7a_replay(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(17);
	key_off(channel);
	z80_block(10);
	key_on(channel);
}

/* Command 7B: sample 71 (pcm_effect_7b_patch, level 0) at its own pitch, pan 4 (centred), keyed on; then
   pcm_effect_7b_wait_sample. */
void pcm_effect_7b(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_7b_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_7b_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 71 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_7b_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 7C: sample 82 (pcm_effect_7c_patch, level 40) at its own pitch, pan 4 (centred), keyed on at
   attenuation 40 (set_volume), timer 1; then pcm_effect_7c_fade_in. */
void pcm_effect_7c(uint16_t channel)
{
	uint8_t pan = 0, volume = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_7c_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(43);
	volume = 0x40u;
	CHANNEL(channel)->pcm_effect_7c.attenuation = 0x40u;
	set_volume(channel, volume);
	z80_block(17);
	key_on(channel);
	z80_block(39);
	CHANNEL(channel)->timer = 1u;
	handler = pcm_effect_7c_fade_in_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Fades in: every 4 passes the attenuation one less (set_volume), down to 0 (256 passes), the sample
   played again whenever it ends (pcm_effect_7c_replay); then passes 4352 (the word over the attenuation
   and the timer) and pcm_effect_7c_delay. */
void pcm_effect_7c_fade_in(uint16_t channel)
{
	uint8_t attenuation = 0;
	uint16_t handler = 0;
	uint8_t timer = 0;

	z80_block(17);
	pcm_effect_7c_replay(channel);
	z80_block(28);
	timer = CHANNEL(channel)->timer;
	CHANNEL(channel)->timer = timer - 1u;
	if (timer != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(78);
	CHANNEL(channel)->timer = 4u;
	CHANNEL(channel)->pcm_effect_7c.attenuation--;
	attenuation = CHANNEL(channel)->pcm_effect_7c.attenuation;
	set_volume(channel, attenuation);
	z80_block(28);
	if (CHANNEL(channel)->pcm_effect_7c.attenuation != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(68);
	CHANNEL(channel)->pcm_effect_7c.passes = 0x1100u;
	handler = pcm_effect_7c_delay_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Holds the sound until passes runs out, played again whenever it ends; then attenuation 0, timer 1 and
   pcm_effect_7c_fade_out. */
void pcm_effect_7c_delay(uint16_t channel)
{
	uint8_t passes_high = 0, passes_low = 0;
	uint16_t handler = 0;
	uint16_t passes_left = 0;

	z80_block(17);
	pcm_effect_7c_replay(channel);
	z80_block(95);
	passes_left = CHANNEL(channel)->pcm_effect_7c.passes - 1u;
	passes_high = (uint8_t)(passes_left >> 8);
	passes_low = (uint8_t)passes_left;
	CHANNEL(channel)->pcm_effect_7c.passes = ((uint32_t)passes_high << 8) | passes_low;
	if ((passes_low | passes_high) != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(58);
	CHANNEL(channel)->pcm_effect_7c.passes = 0x100u;
	handler = pcm_effect_7c_fade_out_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Fades out: every 8 passes the attenuation one more (set_volume), the sample played again whenever it
   ends; at 7F, stop_channel. */
void pcm_effect_7c_fade_out(uint16_t channel)
{
	uint8_t attenuation = 0;
	uint8_t timer = 0;

	z80_block(17);
	pcm_effect_7c_replay(channel);
	z80_block(28);
	timer = CHANNEL(channel)->timer;
	CHANNEL(channel)->timer = timer - 1u;
	if (timer != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(78);
	CHANNEL(channel)->timer = 8u;
	CHANNEL(channel)->pcm_effect_7c.attenuation++;
	attenuation = CHANNEL(channel)->pcm_effect_7c.attenuation;
	set_volume(channel, attenuation);
	z80_block(31);
	if (CHANNEL(channel)->pcm_effect_7c.attenuation != 0x7Fu)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* When the sample has ended (pcm_voice_playing), key off and on: the sample again from its start. */
void pcm_effect_7c_replay(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(17);
	key_off(channel);
	z80_block(10);
	key_on(channel);
}

/* Command 7D: sample 99 (pcm_effect_7d_patch, level 0) at its own pitch, pan 4 (centred), keyed on; then
   pcm_effect_7d_wait_sample. */
void pcm_effect_7d(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_7d_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_7d_wait_sample_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When sample 99 has ended (pcm_voice_playing), stop_channel. */
void pcm_effect_7d_wait_sample(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Command 7E: sample 89 (pcm_effect_7e_patch, level 50) at its own pitch, pan 4 (centred), keyed on,
   passes 1536 (the word over the attenuation and the timer); then pcm_effect_7e_delay. */
void pcm_effect_7e(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_7e_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(68);
	CHANNEL(channel)->pcm_effect_7e.passes = 0x600u;
	handler = pcm_effect_7e_delay_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Holds the sound until passes runs out, the sample played again whenever it ends
   (pcm_effect_7e_replay); then attenuation 0, timer 1 and pcm_effect_7e_fade_out. */
void pcm_effect_7e_delay(uint16_t channel)
{
	uint8_t passes_high = 0, passes_low = 0;
	uint16_t handler = 0;
	uint16_t passes_left = 0;

	z80_block(17);
	pcm_effect_7e_replay(channel);
	z80_block(95);
	passes_left = CHANNEL(channel)->pcm_effect_7e.passes - 1u;
	passes_high = (uint8_t)(passes_left >> 8);
	passes_low = (uint8_t)passes_left;
	CHANNEL(channel)->pcm_effect_7e.passes = ((uint32_t)passes_high << 8) | passes_low;
	if ((passes_low | passes_high) != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(58);
	CHANNEL(channel)->pcm_effect_7e.passes = 0x100u;
	handler = pcm_effect_7e_fade_out_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Fades out: every 8 passes the attenuation one more (set_volume), the sample played again whenever it
   ends; at 7F, stop_channel. */
void pcm_effect_7e_fade_out(uint16_t channel)
{
	uint8_t attenuation = 0;
	uint8_t timer = 0;

	z80_block(17);
	pcm_effect_7e_replay(channel);
	z80_block(28);
	timer = CHANNEL(channel)->timer;
	CHANNEL(channel)->timer = timer - 1u;
	if (timer != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(78);
	CHANNEL(channel)->timer = 8u;
	CHANNEL(channel)->pcm_effect_7e.attenuation++;
	attenuation = CHANNEL(channel)->pcm_effect_7e.attenuation;
	set_volume(channel, attenuation);
	z80_block(31);
	if (CHANNEL(channel)->pcm_effect_7e.attenuation != 0x7Fu)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* When the sample has ended (pcm_voice_playing), key off and on: the sample again from its start. */
void pcm_effect_7e_replay(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(17);
	key_off(channel);
	z80_block(10);
	key_on(channel);
}

/* Command 7F: sample 89 (pcm_effect_7f_patch, level 30) at its own pitch, its pan and volume by the
   position the command hands (pcm_effect_7f_set_volume), keyed on; then pcm_effect_7f_retrigger. */
void pcm_effect_7f(uint16_t channel)
{
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_effect_7f_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(17);
	pcm_effect_7f_set_volume(channel);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_effect_7f_retrigger_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Every pass: when the sample has ended (pcm_voice_playing), key off and on (the sample again: it plays
   until position 0); then pcm_effect_7f_set_volume. */
void pcm_effect_7f_retrigger(uint16_t channel)
{
	uint32_t voice_ended = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(10);
	if (voice_ended == 0u)
	{
		pcm_effect_7f_set_volume(channel);
		return;
	}
	z80_block(17);
	key_off(channel);
	z80_block(17);
	key_on(channel);
	pcm_effect_7f_set_volume(channel);
}

/* The record's position (its low 3 bits; a command 7F while the effect plays changes it): 0 stops the
   channel, 1-7 set the pan and the volume of effect_levels (from the right, pan 7, to the left, pan 1,
   loudest at 4 in the centre). */
void pcm_effect_7f_set_volume(uint16_t channel)
{
	uint8_t pan = 0, position = 0, volume = 0;
	uint16_t level = 0;

	z80_block(40);
	position = CHANNEL(channel)->pcm_effect_7f.position & 7u;
	if (position == 0u)
	{
		stop_channel(channel);
		return;
	}
	z80_block(73);
	level = position * 2u + effect_levels_by_position_ADDRESS;
	pan = EFFECT_LEVEL(level)->pan;
	level++;
	set_pan(channel, pan);
	z80_block(17);
	volume = EFFECT_LEVEL(level - 0x1u)->volume;
	set_volume(channel, volume);
}
