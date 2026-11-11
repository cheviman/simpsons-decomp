/**
 *    Name:        drums.c
 *    Description: the drum routines: a music note's low nibble on a channel with a drum kit (+12) runs one
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the Z80 sound program decompiled into C by
 *    tools/decompile_sound.py, with the names of sound_symbols.txt.
 */
#include "sound.h"

/* FM kit 1's drum 1: its patch at pitch D00, keyed on; fm_drum_1_1_slide then takes the pitch down for
   80 passes. */
void fm_drum_1_1(uint16_t channel)
{
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = fm_drum_1_1_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(65);
	pitch = 0xD00u;
	CHANNEL(channel)->fm_drum_1_1.pitch = 0xD00u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(39);
	CHANNEL(channel)->count = 0x50u;
	handler = fm_drum_1_1_slide_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The pitch 20 lower each pass (half a semitone), 79 times; at the 80th pass, drum_done. */
void fm_drum_1_1_slide(uint16_t channel)
{
	uint16_t pitch = 0;
	uint8_t count = 0;

	z80_block(33);
	count = CHANNEL(channel)->count;
	CHANNEL(channel)->count = count - 1u;
	if (count == 1u)
	{
		drum_done(channel);
		return;
	}
	z80_block(115);
	pitch = CHANNEL(channel)->fm_drum_1_1.pitch - 0x20u;
	CHANNEL(channel)->fm_drum_1_1.pitch = pitch;
	set_pitch(pitch, channel);
}

/* FM kit 1's drum 2: its patch at pitch C70, keyed on; fm_drum_1_2_hold then counts 255 passes. */
void fm_drum_1_2(uint16_t channel)
{
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = fm_drum_1_2_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xC70u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(39);
	CHANNEL(channel)->count = 0xFFu;
	handler = fm_drum_1_2_hold_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Counts the passes down, then drum_done; the note rings on all the while. */
void fm_drum_1_2_hold(uint16_t channel)
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
	drum_done(channel);
}

/* FM kit 1's drum 3: its patch at pitch E00, keyed on; fm_drum_1_3_hold then counts 128 passes. */
void fm_drum_1_3(uint16_t channel)
{
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = fm_drum_1_3_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xE00u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(39);
	CHANNEL(channel)->count = 0x80u;
	handler = fm_drum_1_3_hold_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Counts the passes down, then drum_done; the note rings on all the while. */
void fm_drum_1_3_hold(uint16_t channel)
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
	drum_done(channel);
}

/* FM kit 1's drum 4: drum 3 with another patch (the same connection, other operators) at pitch E00,
   keyed on; fm_drum_1_4_hold then counts 128 passes. */
void fm_drum_1_4(uint16_t channel)
{
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = fm_drum_1_4_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xE00u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(39);
	CHANNEL(channel)->count = 0x80u;
	handler = fm_drum_1_4_hold_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Counts the passes down, then drum_done; the note rings on all the while. */
void fm_drum_1_4_hold(uint16_t channel)
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
	drum_done(channel);
}

/* FM kit 1's drum 5: its patch at pitch E00, keyed on; fm_drum_1_5_slide then takes the pitch down for
   768 passes. */
void fm_drum_1_5(uint16_t channel)
{
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = fm_drum_1_5_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(65);
	pitch = 0xE00u;
	CHANNEL(channel)->pitch = 0xE00u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(68);
	CHANNEL(channel)->fm_drum_1_5.passes = 0x300u;
	handler = fm_drum_1_5_slide_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The pitch 0C lower each pass (3/16 of a semitone), for 768 passes, then drum_done; it runs off the
   bottom of set_pitch's range twice, and the wrap takes it back up each time. */
void fm_drum_1_5_slide(uint16_t channel)
{
	uint16_t passes = 0, pitch = 0;

	z80_block(114);
	pitch = CHANNEL(channel)->pitch - 0xCu;
	CHANNEL(channel)->pitch = pitch;
	set_pitch(pitch, channel);
	z80_block(95);
	passes = CHANNEL(channel)->fm_drum_1_5.passes - 1u;
	CHANNEL(channel)->fm_drum_1_5.passes = passes;
	if ((uint8_t)(passes | (passes >> 8)) != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	drum_done(channel);
}

/* FM kit 1's drum 6: drum 5 a major third lower (pitch D00), its patch drum 5's on both outputs; then
   fm_drum_1_6_slide. */
void fm_drum_1_6(uint16_t channel)
{
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = fm_drum_1_6_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(65);
	pitch = 0xD00u;
	CHANNEL(channel)->pitch = 0xD00u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(68);
	CHANNEL(channel)->fm_drum_1_6.passes = 0x300u;
	handler = fm_drum_1_6_slide_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The pitch 0C lower each pass, for 768 passes, then drum_done; it runs off the bottom of set_pitch's
   range twice, and the wrap takes it back up each time. */
void fm_drum_1_6_slide(uint16_t channel)
{
	uint16_t passes = 0, pitch = 0;

	z80_block(114);
	pitch = CHANNEL(channel)->pitch - 0xCu;
	CHANNEL(channel)->pitch = pitch;
	set_pitch(pitch, channel);
	z80_block(95);
	passes = CHANNEL(channel)->fm_drum_1_6.passes - 1u;
	CHANNEL(channel)->fm_drum_1_6.passes = passes;
	if ((uint8_t)(passes | (passes >> 8)) != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	drum_done(channel);
}

/* FM kit 1's drum 7: drum 5 two major thirds lower (pitch C00), its patch drum 5's on both outputs with
   less feedback; then fm_drum_1_7_slide. */
void fm_drum_1_7(uint16_t channel)
{
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = fm_drum_1_7_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(65);
	pitch = 0xC00u;
	CHANNEL(channel)->pitch = 0xC00u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(68);
	CHANNEL(channel)->fm_drum_1_7.passes = 0x300u;
	handler = fm_drum_1_7_slide_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The pitch 0C lower each pass, for 768 passes, then drum_done; it runs off the bottom of set_pitch's
   range twice, and the wrap takes it back up each time. */
void fm_drum_1_7_slide(uint16_t channel)
{
	uint16_t passes = 0, pitch = 0;

	z80_block(114);
	pitch = CHANNEL(channel)->pitch - 0xCu;
	CHANNEL(channel)->pitch = pitch;
	set_pitch(pitch, channel);
	z80_block(95);
	passes = CHANNEL(channel)->fm_drum_1_7.passes - 1u;
	CHANNEL(channel)->fm_drum_1_7.passes = passes;
	if ((uint8_t)(passes | (passes >> 8)) != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	drum_done(channel);
}

/* FM kit 1's drum 8: its patch at pitch 900, keyed on; fm_drum_1_8_slide then takes the pitch down for
   768 passes. */
void fm_drum_1_8(uint16_t channel)
{
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = fm_drum_1_8_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(65);
	pitch = 0x900u;
	CHANNEL(channel)->pitch = 0x900u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(68);
	CHANNEL(channel)->fm_drum_1_8.passes = 0x300u;
	handler = fm_drum_1_8_slide_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The pitch 2 lower each pass (1/32 of a semitone), for 768 passes (two octaves, down to 300), then
   drum_done. */
void fm_drum_1_8_slide(uint16_t channel)
{
	uint16_t passes = 0, pitch = 0;

	z80_block(114);
	pitch = CHANNEL(channel)->pitch - 2u;
	CHANNEL(channel)->pitch = pitch;
	set_pitch(pitch, channel);
	z80_block(95);
	passes = CHANNEL(channel)->fm_drum_1_8.passes - 1u;
	CHANNEL(channel)->fm_drum_1_8.passes = passes;
	if ((uint8_t)(passes | (passes >> 8)) != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	drum_done(channel);
}

/* FM kit 1's drums 9 to F: nothing played (drum_done at once): the note is a rest. */
void fm_drum_1_9(uint16_t channel)
{
	z80_block(10);
	drum_done(channel);
}

/* FM kit 2's drum 1: its patch (the right output only), then rising sweeps until the track's next note
   (fm_drum_2_1_setup). */
void fm_drum_2_1(uint16_t channel)
{
	uint16_t patch = 0;

	z80_block(27);
	patch = fm_drum_2_1_patch_ADDRESS;
	load_patch(patch, channel);
	fm_drum_2_1_setup(channel);
}

/* Ten sweeps to go (count), then fm_drum_2_1_retrigger. */
void fm_drum_2_1_setup(uint16_t channel)
{
	z80_block(19);
	CHANNEL(channel)->count = 0xAu;
	fm_drum_2_1_retrigger(channel);
}

/* A sweep: the pitch from C00, keyed on, 192 passes (timer) of fm_drum_2_1_slide. */
void fm_drum_2_1_retrigger(uint16_t channel)
{
	uint16_t handler = 0, pitch = 0;

	z80_block(84);
	CHANNEL(channel)->timer = 0xC0u;
	pitch = 0xC00u;
	CHANNEL(channel)->pitch = 0xC00u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = fm_drum_2_1_slide_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The pitch 2 higher each pass (six semitones in a sweep); at the sweep's end the next one
   (fm_drum_2_1_retrigger), and after the tenth, key off and ten more (fm_drum_2_1_setup). */
void fm_drum_2_1_slide(uint16_t channel)
{
	uint16_t pitch = 0;
	uint8_t timer = 0, count = 0;

	z80_block(114);
	pitch = CHANNEL(channel)->pitch + 2u;
	CHANNEL(channel)->pitch = pitch;
	set_pitch(pitch, channel);
	z80_block(28);
	timer = CHANNEL(channel)->timer;
	CHANNEL(channel)->timer = timer - 1u;
	if (timer != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(33);
	count = CHANNEL(channel)->count;
	CHANNEL(channel)->count = count - 1u;
	if (count != 1u)
	{
		fm_drum_2_1_retrigger(channel);
		return;
	}
	z80_block(17);
	key_off(channel);
	z80_block(10);
	fm_drum_2_1_setup(channel);
}

/* FM kit 2's drum 2: drum 1 on the left output (its patch is drum 1's but for that), rising sweeps until
   the track's next note (fm_drum_2_2_setup). */
void fm_drum_2_2(uint16_t channel)
{
	uint16_t patch = 0;

	z80_block(27);
	patch = fm_drum_2_2_patch_ADDRESS;
	load_patch(patch, channel);
	fm_drum_2_2_setup(channel);
}

/* Ten sweeps to go (count), then fm_drum_2_2_retrigger. */
void fm_drum_2_2_setup(uint16_t channel)
{
	z80_block(19);
	CHANNEL(channel)->count = 0xAu;
	fm_drum_2_2_retrigger(channel);
}

/* A sweep: the pitch from C00, keyed on, 192 passes (timer) of fm_drum_2_2_slide. */
void fm_drum_2_2_retrigger(uint16_t channel)
{
	uint16_t handler = 0, pitch = 0;

	z80_block(84);
	CHANNEL(channel)->timer = 0xC0u;
	pitch = 0xC00u;
	CHANNEL(channel)->pitch = 0xC00u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = fm_drum_2_2_slide_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The pitch 2 higher each pass (six semitones in a sweep); at the sweep's end the next one
   (fm_drum_2_2_retrigger), and after the tenth, key off and ten more (fm_drum_2_2_setup). */
void fm_drum_2_2_slide(uint16_t channel)
{
	uint16_t pitch = 0;
	uint8_t timer = 0, count = 0;

	z80_block(114);
	pitch = CHANNEL(channel)->pitch + 2u;
	CHANNEL(channel)->pitch = pitch;
	set_pitch(pitch, channel);
	z80_block(28);
	timer = CHANNEL(channel)->timer;
	CHANNEL(channel)->timer = timer - 1u;
	if (timer != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(33);
	count = CHANNEL(channel)->count;
	CHANNEL(channel)->count = count - 1u;
	if (count != 1u)
	{
		fm_drum_2_2_retrigger(channel);
		return;
	}
	z80_block(17);
	key_off(channel);
	z80_block(10);
	fm_drum_2_2_setup(channel);
}

/* FM kit 2's drum 3: its patch, then rising sweeps until the track's next note (fm_drum_2_3_retrigger). */
void fm_drum_2_3(uint16_t channel)
{
	uint16_t patch = 0;

	z80_block(27);
	patch = fm_drum_2_3_patch_ADDRESS;
	load_patch(patch, channel);
	fm_drum_2_3_retrigger(channel);
}

/* A sweep: the pitch from 600, keyed on, 128 passes (timer) of fm_drum_2_3_slide. */
void fm_drum_2_3_retrigger(uint16_t channel)
{
	uint16_t handler = 0, pitch = 0;

	z80_block(65);
	pitch = 0x600u;
	CHANNEL(channel)->pitch = 0x600u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(39);
	CHANNEL(channel)->timer = 0x80u;
	handler = fm_drum_2_3_slide_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The pitch 2 higher each pass (four semitones in a sweep), then the next sweep (fm_drum_2_3_retrigger). */
void fm_drum_2_3_slide(uint16_t channel)
{
	uint16_t pitch = 0;
	uint8_t timer = 0;

	z80_block(114);
	pitch = CHANNEL(channel)->pitch + 2u;
	CHANNEL(channel)->pitch = pitch;
	set_pitch(pitch, channel);
	z80_block(28);
	timer = CHANNEL(channel)->timer;
	CHANNEL(channel)->timer = timer - 1u;
	if (timer != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	fm_drum_2_3_retrigger(channel);
}

/* FM kit 2's drum 4: a note that wanders up and down at random until the track's next note: the random
   numbers from their start, its patch at pitch 1700, then fm_drum_2_4_retrigger. */
void fm_drum_2_4(uint16_t channel)
{
	uint16_t patch = 0, pitch = 0;

	z80_block(46);
	CHANNEL(channel)->fm_drum_2_4.random_index = 0u;
	patch = fm_drum_2_4_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(65);
	pitch = 0x1700u;
	CHANNEL(channel)->fm_drum_2_4.pitch = 0x1700u;
	set_pitch(pitch, channel);
	fm_drum_2_4_retrigger(channel);
}

/* Keys the note on for 6144 passes, a first random turn (fm_drum_2_4_random_turn), then
   fm_drum_2_4_slide. */
void fm_drum_2_4_retrigger(uint16_t channel)
{
	uint16_t handler = 0;

	z80_block(17);
	key_on(channel);
	z80_block(65);
	CHANNEL(channel)->fm_drum_2_4.passes = 0x1800u;
	fm_drum_2_4_random_turn(channel);
	z80_block(20);
	handler = fm_drum_2_4_slide_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The pitch_step added to the pitch each pass; below 800 a new random step up (fm_drum_2_4_random_step),
   from 1700 up a new one down (fm_drum_2_4_random_step_down), and a random turn when the timer runs out;
   after the 6144 passes, key off and fm_drum_2_4_retrigger again. */
void fm_drum_2_4_slide(uint16_t channel)
{
	uint16_t passes = 0, pitch = 0;
	uint8_t timer = 0;

	z80_block(142);
	pitch = CHANNEL(channel)->fm_drum_2_4.pitch + CHANNEL(channel)->fm_drum_2_4.pitch_step;
	CHANNEL(channel)->fm_drum_2_4.pitch = pitch;
	set_pitch(pitch, channel);
	z80_block(36);
	if ((uint8_t)(CHANNEL(channel)->fm_drum_2_4.pitch >> 8u) < 8u)
	{
		z80_cycles(7);
		fm_drum_2_4_random_step(channel);
	}
	z80_block(36);
	if ((uint8_t)(CHANNEL(channel)->fm_drum_2_4.pitch >> 8u) >= 0x17u)
	{
		z80_cycles(7);
		fm_drum_2_4_random_step_down(channel);
	}
	z80_block(33);
	timer = CHANNEL(channel)->timer;
	CHANNEL(channel)->timer = timer - 1u;
	if (timer == 1u)
	{
		z80_cycles(7);
		fm_drum_2_4_random_turn(channel);
	}
	z80_block(95);
	passes = CHANNEL(channel)->fm_drum_2_4.passes - 1u;
	CHANNEL(channel)->fm_drum_2_4.passes = passes;
	if ((uint8_t)(passes | (passes >> 8)) != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(17);
	key_off(channel);
	z80_block(10);
	fm_drum_2_4_retrigger(channel);
}

/* A new timer and a new pitch_step up, 0 to 1F, from the next two random numbers
   (fm_drum_2_4_next_random). */
void fm_drum_2_4_random_step(uint16_t channel)
{
	uint8_t random = 0, timer = 0;

	z80_block(17);
	timer = fm_drum_2_4_next_random(channel);
	z80_block(36);
	CHANNEL(channel)->timer = timer;
	random = fm_drum_2_4_next_random(channel);
	z80_block(55);
	CHANNEL(channel)->fm_drum_2_4.pitch_step = random & 0x1Fu;
}

/* A new timer and pitch_step (fm_drum_2_4_random_step), turned down (fm_drum_2_4_reverse). */
void fm_drum_2_4_random_step_down(uint16_t channel)
{
	z80_block(17);
	fm_drum_2_4_random_step(channel);
	fm_drum_2_4_reverse(channel);
}

/* The pitch_step negated: the wandering turns the other way. */
void fm_drum_2_4_reverse(uint16_t channel)
{
	uint16_t pitch_step = 0;

	z80_block(115);
	pitch_step = 0u - CHANNEL(channel)->fm_drum_2_4.pitch_step;
	CHANNEL(channel)->fm_drum_2_4.pitch_step = pitch_step;
}

/* A new timer and pitch_step (fm_drum_2_4_random_step), turned down when the next random number is odd
   (fm_drum_2_4_reverse). */
void fm_drum_2_4_random_turn(uint16_t channel)
{
	uint8_t random = 0;

	z80_block(17);
	fm_drum_2_4_random_step(channel);
	z80_block(17);
	random = fm_drum_2_4_next_random(channel);
	z80_block(13);
	if ((random & 1u) == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	fm_drum_2_4_reverse(channel);
}

/* The next random number: the byte of the program's own code at random_index, which moves on by one (the
   same 256 bytes over and over). */
uint8_t fm_drum_2_4_next_random(uint16_t channel)
{
	uint8_t random = 0;

	z80_block(66);
	random = z80_read8(RANDOM_BYTES | CHANNEL(channel)->fm_drum_2_4.random_index);
	CHANNEL(channel)->fm_drum_2_4.random_index++;
	return random;
}

/* FM kit 2's drum 5: its patch, then a note that climbs a semitone at a time, over and over until the
   track's next note (fm_drum_2_5_retrigger). */
void fm_drum_2_5(uint16_t channel)
{
	uint16_t patch = 0;

	z80_block(27);
	patch = fm_drum_2_5_patch_ADDRESS;
	load_patch(patch, channel);
	fm_drum_2_5_retrigger(channel);
}

/* The pitch from 1500, keyed on: twelve steps (count) of 64 passes (timer) in fm_drum_2_5_slide. */
void fm_drum_2_5_retrigger(uint16_t channel)
{
	uint16_t handler = 0, pitch = 0;

	z80_block(65);
	pitch = 0x1500u;
	CHANNEL(channel)->pitch = 0x1500u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(58);
	CHANNEL(channel)->count = 0xCu;
	CHANNEL(channel)->timer = 0x40u;
	handler = fm_drum_2_5_slide_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Every 64 passes the pitch 40 higher (a semitone), 11 times; at the twelfth, fm_drum_2_5_retrigger
   again. */
void fm_drum_2_5_slide(uint16_t channel)
{
	uint16_t pitch = 0;
	uint8_t timer = 0, count = 0;

	z80_block(28);
	timer = CHANNEL(channel)->timer;
	CHANNEL(channel)->timer = timer - 1u;
	if (timer != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(52);
	CHANNEL(channel)->timer = 0x40u;
	count = CHANNEL(channel)->count;
	CHANNEL(channel)->count = count - 1u;
	if (count == 1u)
	{
		fm_drum_2_5_retrigger(channel);
		return;
	}
	z80_block(107);
	pitch = CHANNEL(channel)->pitch + 0x40u;
	CHANNEL(channel)->pitch = pitch;
	set_pitch(pitch, channel);
}

/* FM kit 2's drums 6 to F: nothing played (drum_done at once): the note is a rest. */
void fm_drum_2_6(uint16_t channel)
{
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 1's drum 1: sample 125 at its own pitch, panned 4, keyed on and left ringing (drum_done). */
void pcm_drum_1_1(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_1_1_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 1's drum 2: sample 127 at its own pitch, panned 3, keyed on and left ringing (drum_done). */
void pcm_drum_1_2(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_1_2_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 3u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 1's drum 3: sample 133 at pitch F40, panned 7, keyed on and left ringing (drum_done). */
void pcm_drum_1_3(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_drum_1_3_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xF40u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 7u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 1's drum 4: sample 133 at pitch F20, panned 4, keyed on and left ringing (drum_done). */
void pcm_drum_1_4(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_drum_1_4_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xF20u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 1's drum 5: sample 133 at pitch F00, panned 1, keyed on and left ringing (drum_done). */
void pcm_drum_1_5(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_drum_1_5_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xF00u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 1u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 1's drum 6: sample 133 at pitch EE0, panned 7, keyed on and left ringing (drum_done). */
void pcm_drum_1_6(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_drum_1_6_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xEE0u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 7u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 1's drum 7: sample 132 at its own pitch, panned 6, keyed on and left ringing (drum_done). */
void pcm_drum_1_7(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_1_7_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 6u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 1's drum 8: sample 135 at its own pitch, panned 5, keyed on and left ringing (drum_done). */
void pcm_drum_1_8(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_1_8_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 5u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 1's drum 9: sample 139 at its own pitch, panned 1, keyed on and left ringing (drum_done). */
void pcm_drum_1_9(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_1_9_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 1u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 1's drum A: sample 141 at its own pitch, panned 6, keyed on and left ringing (drum_done). */
void pcm_drum_1_a(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_1_a_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 6u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 1's drum B: sample 160, panned 6, keyed on; then pcm_drum_1_b_note for sample 161 and then
   162, neither of them heard. */
void pcm_drum_1_b(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = pcm_drum_1_b_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 6u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_drum_1_b_note_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When the voice has ended (pcm_voice_playing): sample 161, whose key_on does nothing (pcm_keyed still
   holds the voice), then pcm_drum_1_b_note_2. */
void pcm_drum_1_b_note(uint16_t channel)
{
	uint32_t voice_ended = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(27);
	patch = pcm_drum_1_b_patch_2_ADDRESS;
	load_patch(patch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_drum_1_b_note_2_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When the voice has ended: sample 162, whose key_on does nothing either, then drum_done. */
void pcm_drum_1_b_note_2(uint16_t channel)
{
	uint32_t voice_ended = 0;
	uint16_t patch = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(27);
	patch = pcm_drum_1_b_patch_3_ADDRESS;
	load_patch(patch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 1's drum C: drum B 16 passes later (count) and panned 2, in pcm_drum_1_c_note. */
void pcm_drum_1_c(uint16_t channel)
{
	uint16_t handler = 0;

	z80_block(39);
	CHANNEL(channel)->count = 0x10u;
	handler = pcm_drum_1_c_note_ADDRESS;
	set_channel_handler(handler, channel);
}

/* After the 16 passes, sample 160, panned 2, keyed on; then pcm_drum_1_c_note_2 for sample 161 and then
   162, neither of them heard. */
void pcm_drum_1_c_note(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t handler = 0, patch = 0;
	uint8_t count = 0;

	z80_block(28);
	count = CHANNEL(channel)->count;
	CHANNEL(channel)->count = count - 1u;
	if (count != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(27);
	patch = pcm_drum_1_c_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 2u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_drum_1_c_note_2_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When the voice has ended (pcm_voice_playing): sample 161, whose key_on does nothing (pcm_keyed still
   holds the voice), then pcm_drum_1_c_note_3. */
void pcm_drum_1_c_note_2(uint16_t channel)
{
	uint32_t voice_ended = 0;
	uint16_t handler = 0, patch = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(27);
	patch = pcm_drum_1_c_patch_2_ADDRESS;
	load_patch(patch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = pcm_drum_1_c_note_3_ADDRESS;
	set_channel_handler(handler, channel);
}

/* When the voice has ended: sample 162, whose key_on does nothing either, then drum_done. */
void pcm_drum_1_c_note_3(uint16_t channel)
{
	uint32_t voice_ended = 0;
	uint16_t patch = 0;

	z80_block(17);
	voice_ended = pcm_voice_playing(channel);
	z80_block(5);
	if (voice_ended == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(27);
	patch = pcm_drum_1_c_patch_3_ADDRESS;
	load_patch(patch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 1's drums D and E: nothing played (drum_done at once). */
void pcm_drum_1_d(uint16_t channel)
{
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 1's drum F: sample 98 at its own pitch, panned 4, keyed on and left ringing (drum_done). */
void pcm_drum_1_f(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_1_f_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 2's drum 1: sample 126 at its own pitch, panned 4, keyed on and left ringing (drum_done). */
void pcm_drum_2_1(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_2_1_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 2's drum 2: sample 128 at its own pitch, panned 4, keyed on and left ringing (drum_done). */
void pcm_drum_2_2(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_2_2_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 2's drum 3: sample 134 at pitch F40, panned 7, keyed on and left ringing (drum_done). */
void pcm_drum_2_3(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_drum_2_3_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xF40u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 7u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 2's drum 4: sample 134 at pitch F20, panned 4, keyed on and left ringing (drum_done). */
void pcm_drum_2_4(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_drum_2_4_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xF20u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 2's drum 5: sample 134 at pitch F00, panned 1, keyed on and left ringing (drum_done). */
void pcm_drum_2_5(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_drum_2_5_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xF00u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 1u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 2's drum 6: sample 134 at pitch EE0, panned 7, keyed on and left ringing (drum_done). */
void pcm_drum_2_6(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_drum_2_6_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xEE0u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 7u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 2's drum 7: sample 132 at its own pitch, panned 6, keyed on and left ringing (drum_done). */
void pcm_drum_2_7(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_2_7_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 6u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 2's drum 8: sample 135 at its own pitch, panned 4, keyed on and left ringing (drum_done). */
void pcm_drum_2_8(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_2_8_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 2's drum 9: sample 139 at its own pitch, panned 7, keyed on and left ringing (drum_done). */
void pcm_drum_2_9(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_2_9_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 7u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 2's drum A: sample 131 at its own pitch, panned 1, keyed on and left ringing (drum_done). */
void pcm_drum_2_a(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_2_a_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 1u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 2's drum B: sample 136 at its own pitch, panned 6, keyed on and left ringing (drum_done). */
void pcm_drum_2_b(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_2_b_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 6u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 2's drum C: sample 142 at its own pitch, panned 2, keyed on and left ringing (drum_done). */
void pcm_drum_2_c(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_2_c_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 2u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 2's drum D: sample 143 at its own pitch, panned 3, keyed on and left ringing (drum_done). */
void pcm_drum_2_d(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_2_d_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 3u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 2's drum E: sample 146 at its own pitch, panned 4, keyed on and left ringing (drum_done). */
void pcm_drum_2_e(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_2_e_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 2's drum F: sample 147 at its own pitch, panned 3, keyed on and left ringing (drum_done). */
void pcm_drum_2_f(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_2_f_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 3u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 3's drum 1: sample 125 at its own pitch, panned 4, keyed on and left ringing (drum_done). */
void pcm_drum_3_1(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_3_1_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 3's drum 2: sample 129 at its own pitch, panned 4, keyed on and left ringing (drum_done). */
void pcm_drum_3_2(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_3_2_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 3's drum 3: sample 133 at pitch F40, panned 4, keyed on and left ringing (drum_done). */
void pcm_drum_3_3(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_drum_3_3_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xF40u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 3's drum 4: sample 133 at pitch F20, panned 3, keyed on and left ringing (drum_done). */
void pcm_drum_3_4(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_drum_3_4_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xF20u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 3u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 3's drum 5: sample 133 at pitch F00, panned 6, keyed on and left ringing (drum_done). */
void pcm_drum_3_5(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_drum_3_5_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xF00u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 6u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 3's drum 6: sample 133 at pitch EE0, panned 5, keyed on and left ringing (drum_done). */
void pcm_drum_3_6(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_drum_3_6_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xEE0u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 5u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 3's drum 7: sample 131 at its own pitch, panned 7, keyed on and left ringing (drum_done). */
void pcm_drum_3_7(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_3_7_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 7u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 3's drum 8: sample 135 at its own pitch, panned 5, keyed on and left ringing (drum_done). */
void pcm_drum_3_8(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_3_8_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 5u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 3's drum 9: sample 139 at its own pitch, panned 1, keyed on and left ringing (drum_done). */
void pcm_drum_3_9(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_3_9_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 1u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 3's drum A: sample 128 at its own pitch, panned 5, keyed on and left ringing (drum_done). */
void pcm_drum_3_a(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_3_a_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 5u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 3's drum B: sample 136 at its own pitch, panned 3, keyed on and left ringing (drum_done). */
void pcm_drum_3_b(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_3_b_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 3u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 3's drum C: sample 142 at its own pitch, panned 2, keyed on and left ringing (drum_done). */
void pcm_drum_3_c(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_3_c_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 2u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 3's drum D: sample 143 at its own pitch, panned 6, keyed on and left ringing (drum_done). */
void pcm_drum_3_d(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_3_d_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 6u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 3's drum E: sample 61 at its own pitch, panned 3, keyed on and left ringing (drum_done). */
void pcm_drum_3_e(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_3_e_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 3u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 3's drum F: sample 63 at its own pitch, panned 5, keyed on and left ringing (drum_done). */
void pcm_drum_3_f(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_3_f_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 5u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 4's drum 1: sample 125 at its own pitch, panned 4, keyed on and left ringing (drum_done). */
void pcm_drum_4_1(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_4_1_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 4's drum 2: sample 129 at its own pitch, panned 4, keyed on and left ringing (drum_done). */
void pcm_drum_4_2(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_4_2_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 4's drum 3: sample 68 at its own pitch, panned 6, keyed on and left ringing (drum_done). */
void pcm_drum_4_3(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_4_3_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 6u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 4's drum 4: sample 133 at pitch F20, panned 2, keyed on and left ringing (drum_done). */
void pcm_drum_4_4(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_drum_4_4_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xF20u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 2u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 4's drum 5: sample 133 at pitch F00, panned 6, keyed on and left ringing (drum_done). */
void pcm_drum_4_5(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_drum_4_5_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xF00u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 6u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 4's drum 6: sample 133 at pitch EE0, panned 3, keyed on and left ringing (drum_done). */
void pcm_drum_4_6(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_drum_4_6_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xEE0u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 3u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 4's drum 7: sample 131 at its own pitch, panned 7, keyed on and left ringing (drum_done). */
void pcm_drum_4_7(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_4_7_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 7u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 4's drum 8: sample 135 at its own pitch, panned 5, keyed on and left ringing (drum_done). */
void pcm_drum_4_8(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_4_8_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 5u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 4's drum 9: sample 139 at its own pitch, panned 1, keyed on and left ringing (drum_done). */
void pcm_drum_4_9(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_4_9_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 1u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 4's drum A: sample 140 at its own pitch, panned 5, keyed on and left ringing (drum_done). */
void pcm_drum_4_a(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_4_a_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 5u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 4's drum B: sample 137 at its own pitch, panned 3, keyed on and left ringing (drum_done). */
void pcm_drum_4_b(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_4_b_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 3u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 4's drum C: sample 142 at its own pitch, panned 2, keyed on and left ringing (drum_done). */
void pcm_drum_4_c(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_4_c_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 2u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 4's drum D: sample 143 at its own pitch, panned 6, keyed on and left ringing (drum_done). */
void pcm_drum_4_d(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_4_d_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 6u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 4's drum E: sample 147 at its own pitch, panned 4, keyed on and left ringing (drum_done). */
void pcm_drum_4_e(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_4_e_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 4's drum F: sample 72 at its own pitch, panned 4, keyed on and left ringing (drum_done). */
void pcm_drum_4_f(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_4_f_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 5's drum 1: sample 125 at its own pitch, panned 4, keyed on and left ringing (drum_done). */
void pcm_drum_5_1(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_5_1_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 5's drum 2: sample 127 at its own pitch, panned 4, keyed on and left ringing (drum_done). */
void pcm_drum_5_2(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_5_2_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 5's drum 3: sample 133 at pitch F40, panned 7, keyed on and left ringing (drum_done). */
void pcm_drum_5_3(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_drum_5_3_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xF40u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 7u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 5's drum 4: sample 133 at pitch F20, panned 4, keyed on and left ringing (drum_done). */
void pcm_drum_5_4(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_drum_5_4_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xF20u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 5's drum 5: sample 133 at pitch F00, panned 1, keyed on and left ringing (drum_done). */
void pcm_drum_5_5(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_drum_5_5_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xF00u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 1u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 5's drum 6: sample 133 at pitch EE0, panned 7, keyed on and left ringing (drum_done). */
void pcm_drum_5_6(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_drum_5_6_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xEE0u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 7u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 5's drum 7: sample 131 at its own pitch, panned 1, keyed on and left ringing (drum_done). */
void pcm_drum_5_7(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_5_7_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 1u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 5's drum 8: sample 135 at its own pitch, panned 5, keyed on and left ringing (drum_done). */
void pcm_drum_5_8(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_5_8_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 5u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 5's drum 9: sample 139 at its own pitch, panned 7, keyed on and left ringing (drum_done). */
void pcm_drum_5_9(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_5_9_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 7u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 5's drum A: sample 128 at its own pitch, panned 3, keyed on and left ringing (drum_done). */
void pcm_drum_5_a(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_5_a_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 3u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 5's drum B: sample 136 at its own pitch, panned 6, keyed on and left ringing (drum_done). */
void pcm_drum_5_b(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_5_b_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 6u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 5's drum C: sample 142 at its own pitch, panned 2, keyed on and left ringing (drum_done). */
void pcm_drum_5_c(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_5_c_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 2u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 5's drum D: sample 143 at its own pitch, panned 3, keyed on and left ringing (drum_done). */
void pcm_drum_5_d(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_5_d_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 3u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 5's drum E: sample 146 at its own pitch, panned 5, keyed on and left ringing (drum_done). */
void pcm_drum_5_e(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_5_e_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 5u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 5's drum F: sample 147 at its own pitch, panned 3, keyed on and left ringing (drum_done). */
void pcm_drum_5_f(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_5_f_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 3u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 6's drum 1: sample 126 at its own pitch, panned 4, keyed on and left ringing (drum_done). */
void pcm_drum_6_1(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_6_1_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 6's drum 2: sample 127 at its own pitch, panned 4, keyed on and left ringing (drum_done). */
void pcm_drum_6_2(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_6_2_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 6's drum 3: sample 133 at pitch F40, panned 7, keyed on and left ringing (drum_done). */
void pcm_drum_6_3(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_drum_6_3_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xF40u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 7u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 6's drum 4: sample 133 at pitch F20, panned 4, keyed on and left ringing (drum_done). */
void pcm_drum_6_4(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_drum_6_4_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xF20u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 6's drum 5: sample 133 at pitch F00, panned 1, keyed on and left ringing (drum_done). */
void pcm_drum_6_5(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_drum_6_5_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xF00u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 1u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 6's drum 6: sample 133 at pitch EE0, panned 7, keyed on and left ringing (drum_done). */
void pcm_drum_6_6(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_drum_6_6_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xEE0u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 7u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 6's drum 7: sample 132 at its own pitch, panned 6, keyed on and left ringing (drum_done). */
void pcm_drum_6_7(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_6_7_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 6u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 6's drum 8: sample 135 at its own pitch, panned 5, keyed on and left ringing (drum_done). */
void pcm_drum_6_8(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_6_8_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 5u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 6's drum 9: sample 139 at its own pitch, panned 1, keyed on and left ringing (drum_done). */
void pcm_drum_6_9(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_6_9_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 1u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 6's drum A: sample 130 at its own pitch, panned 4, keyed on and left ringing (drum_done). */
void pcm_drum_6_a(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_6_a_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 6's drum B: sample 142 at its own pitch, panned 2, keyed on and left ringing (drum_done). */
void pcm_drum_6_b(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_6_b_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 2u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 6's drum C: sample 143 at its own pitch, panned 3, keyed on and left ringing (drum_done). */
void pcm_drum_6_c(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_6_c_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 3u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 6's drum D: sample 146 at its own pitch, panned 5, keyed on and left ringing (drum_done). */
void pcm_drum_6_d(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_6_d_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 5u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 6's drum E: sample 53 at its own pitch, panned 5, keyed on and left ringing (drum_done). */
void pcm_drum_6_e(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_6_e_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 5u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 6's drum F: sample 54 at its own pitch, panned 3, keyed on and left ringing (drum_done). */
void pcm_drum_6_f(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_6_f_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 3u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 7's drum 1: sample 126 at its own pitch, panned 4, keyed on and left ringing (drum_done). */
void pcm_drum_7_1(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_7_1_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 7's drum 2: sample 127 at its own pitch, panned 4, keyed on and left ringing (drum_done). */
void pcm_drum_7_2(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_7_2_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 7's drum 3: sample 68 at its own pitch, panned 6, keyed on and left ringing (drum_done). */
void pcm_drum_7_3(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_7_3_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 6u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 7's drum 4: sample 133 at pitch F20, panned 2, keyed on and left ringing (drum_done). */
void pcm_drum_7_4(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_drum_7_4_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xF20u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 2u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 7's drum 5: sample 133 at pitch F00, panned 6, keyed on and left ringing (drum_done). */
void pcm_drum_7_5(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_drum_7_5_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xF00u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 6u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 7's drum 6: sample 133 at pitch EE0, panned 3, keyed on and left ringing (drum_done). */
void pcm_drum_7_6(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_drum_7_6_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xEE0u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 3u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 7's drum 7: sample 131 at its own pitch, panned 7, keyed on and left ringing (drum_done). */
void pcm_drum_7_7(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_7_7_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 7u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 7's drum 8: sample 135 at its own pitch, panned 5, keyed on and left ringing (drum_done). */
void pcm_drum_7_8(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_7_8_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 5u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 7's drum 9: sample 139 at its own pitch, panned 1, keyed on and left ringing (drum_done). */
void pcm_drum_7_9(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_7_9_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 1u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 7's drum A: sample 140 at its own pitch, panned 5, keyed on and left ringing (drum_done). */
void pcm_drum_7_a(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_7_a_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 5u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 7's drum B: sample 137 at its own pitch, panned 3, keyed on and left ringing (drum_done). */
void pcm_drum_7_b(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_7_b_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 3u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 7's drum C: sample 142 at its own pitch, panned 2, keyed on and left ringing (drum_done). */
void pcm_drum_7_c(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_7_c_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 2u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 7's drum D: sample 143 at its own pitch, panned 6, keyed on and left ringing (drum_done). */
void pcm_drum_7_d(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_7_d_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 6u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 7's drum E: sample 147 at its own pitch, panned 4, keyed on and left ringing (drum_done). */
void pcm_drum_7_e(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_7_e_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 7's drum F: sample 72 at its own pitch, panned 4, keyed on and left ringing (drum_done). */
void pcm_drum_7_f(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_7_f_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 8's drum 1: sample 126 at its own pitch, panned 4, keyed on and left ringing (drum_done). */
void pcm_drum_8_1(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_8_1_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 8's drum 2: sample 130 at its own pitch, panned 4, keyed on and left ringing (drum_done). */
void pcm_drum_8_2(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_8_2_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 8's drum 3: sample 134 at pitch F40, panned 7, keyed on and left ringing (drum_done). */
void pcm_drum_8_3(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_drum_8_3_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xF40u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 7u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 8's drum 4: sample 133 at pitch F20, panned 4, keyed on and left ringing (drum_done). */
void pcm_drum_8_4(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_drum_8_4_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xF20u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 8's drum 5: sample 133 at pitch F00, panned 1, keyed on and left ringing (drum_done). */
void pcm_drum_8_5(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_drum_8_5_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xF00u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 1u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 8's drum 6: sample 133 at pitch EE0, panned 7, keyed on and left ringing (drum_done). */
void pcm_drum_8_6(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_drum_8_6_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xEE0u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 7u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 8's drum 7: sample 132 at its own pitch, panned 6, keyed on and left ringing (drum_done). */
void pcm_drum_8_7(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_8_7_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 6u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 8's drum 8: sample 135 at its own pitch, panned 4, keyed on and left ringing (drum_done). */
void pcm_drum_8_8(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_8_8_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 8's drum 9: sample 139 at its own pitch, panned 7, keyed on and left ringing (drum_done). */
void pcm_drum_8_9(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_8_9_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 7u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 8's drum A: sample 131 at its own pitch, panned 1, keyed on and left ringing (drum_done). */
void pcm_drum_8_a(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_8_a_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 1u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 8's drum B: sample 136 at its own pitch, panned 6, keyed on and left ringing (drum_done). */
void pcm_drum_8_b(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_8_b_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 6u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 8's drum C: sample 142 at its own pitch, panned 2, keyed on and left ringing (drum_done). */
void pcm_drum_8_c(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_8_c_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 2u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 8's drum D: sample 143 at its own pitch, panned 3, keyed on and left ringing (drum_done). */
void pcm_drum_8_d(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_8_d_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 3u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 8's drum E: sample 146 at its own pitch, panned 4, keyed on and left ringing (drum_done). */
void pcm_drum_8_e(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_8_e_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 8's drum F: sample 147 at its own pitch, panned 3, keyed on and left ringing (drum_done). */
void pcm_drum_8_f(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_8_f_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 3u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 9's drum 1: sample 148 at its own pitch, panned 3, keyed on and left ringing (drum_done). */
void pcm_drum_9_1(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_9_1_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 3u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 9's drum 2: sample 149 at its own pitch, panned 4, keyed on and left ringing (drum_done). */
void pcm_drum_9_2(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_9_2_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 9's drum 3: sample 150 at its own pitch, panned 2, keyed on and left ringing (drum_done). */
void pcm_drum_9_3(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_9_3_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 2u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 9's drum 4: sample 151 at its own pitch, panned 5, keyed on and left ringing (drum_done). */
void pcm_drum_9_4(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_9_4_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 5u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 9's drum 5: sample 152 at its own pitch, panned 6, keyed on and left ringing (drum_done). */
void pcm_drum_9_5(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_9_5_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 6u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 9's drum 6: sample 153 at its own pitch, panned 5, keyed on and left ringing (drum_done). */
void pcm_drum_9_6(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_9_6_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 5u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 9's drum 7: sample 154 at its own pitch, panned 3, keyed on and left ringing (drum_done). */
void pcm_drum_9_7(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_9_7_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 3u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 9's drum 8: sample 155 at its own pitch, panned 5, keyed on and left ringing (drum_done). */
void pcm_drum_9_8(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_9_8_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 5u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 9's drum 9: sample 156 at its own pitch, panned 2, keyed on and left ringing (drum_done). */
void pcm_drum_9_9(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_9_9_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 2u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 9's drum A: sample 157 at its own pitch, panned 6, keyed on and left ringing (drum_done). */
void pcm_drum_9_a(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_9_a_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 6u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 9's drum B: sample 158 at its own pitch, panned 2, keyed on and left ringing (drum_done). */
void pcm_drum_9_b(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_9_b_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 2u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 9's drum C: sample 159 at its own pitch, panned 7, keyed on and left ringing (drum_done). */
void pcm_drum_9_c(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_9_c_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 7u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 9's drum D: sample 95 at its own pitch, panned 4, keyed on and left ringing (drum_done). */
void pcm_drum_9_d(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_9_d_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit 9's drums E and F: nothing played (drum_done at once). */
void pcm_drum_9_e(uint16_t channel)
{
	z80_block(10);
	drum_done(channel);
}

/* PCM kit A's drum 1: sample 125 at its own pitch, panned 4, keyed on and left ringing (drum_done). */
void pcm_drum_a_1(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_a_1_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit A's drum 2: sample 128 at its own pitch, panned 4, keyed on and left ringing (drum_done). */
void pcm_drum_a_2(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_a_2_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit A's drum 3: sample 134 at pitch F40, panned 7, keyed on and left ringing (drum_done). */
void pcm_drum_a_3(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_drum_a_3_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xF40u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 7u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit A's drum 4: sample 134 at pitch F20, panned 4, keyed on and left ringing (drum_done). */
void pcm_drum_a_4(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_drum_a_4_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xF20u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit A's drum 5: sample 134 at pitch F00, panned 1, keyed on and left ringing (drum_done). */
void pcm_drum_a_5(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_drum_a_5_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xF00u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 1u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit A's drum 6: sample 134 at pitch EE0, panned 7, keyed on and left ringing (drum_done). */
void pcm_drum_a_6(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_drum_a_6_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xEE0u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 7u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit A's drum 7: sample 132 at its own pitch, panned 6, keyed on and left ringing (drum_done). */
void pcm_drum_a_7(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_a_7_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 6u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit A's drum 8: sample 135 at its own pitch, panned 4, keyed on and left ringing (drum_done). */
void pcm_drum_a_8(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_a_8_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit A's drum 9: sample 139 at its own pitch, panned 7, keyed on and left ringing (drum_done). */
void pcm_drum_a_9(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_a_9_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 7u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit A's drum A: sample 131 at its own pitch, panned 1, keyed on and left ringing (drum_done). */
void pcm_drum_a_a(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_a_a_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 1u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit A's drum B: sample 136 at its own pitch, panned 6, keyed on and left ringing (drum_done). */
void pcm_drum_a_b(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_a_b_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 6u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit A's drum C: sample 142 at its own pitch, panned 2, keyed on and left ringing (drum_done). */
void pcm_drum_a_c(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_a_c_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 2u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit A's drum D: sample 143 at its own pitch, panned 3, keyed on and left ringing (drum_done). */
void pcm_drum_a_d(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_a_d_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 3u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit A's drum E: sample 146 at its own pitch, panned 4, keyed on and left ringing (drum_done). */
void pcm_drum_a_e(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_a_e_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit A's drum F: sample 147 at its own pitch, panned 3, keyed on and left ringing (drum_done). */
void pcm_drum_a_f(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_a_f_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 3u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit B's drum 1: sample 125 at its own pitch, panned 4, keyed on and left ringing (drum_done). */
void pcm_drum_b_1(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_b_1_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit B's drum 2: sample 130 at its own pitch, panned 4, keyed on and left ringing (drum_done). */
void pcm_drum_b_2(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_b_2_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit B's drum 3: sample 134 at pitch F40, panned 7, keyed on and left ringing (drum_done). */
void pcm_drum_b_3(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_drum_b_3_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xF40u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 7u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit B's drum 4: sample 133 at pitch F20, panned 4, keyed on and left ringing (drum_done). */
void pcm_drum_b_4(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_drum_b_4_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xF20u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit B's drum 5: sample 133 at pitch F00, panned 1, keyed on and left ringing (drum_done). */
void pcm_drum_b_5(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_drum_b_5_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xF00u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 1u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit B's drum 6: sample 133 at pitch EE0, panned 7, keyed on and left ringing (drum_done). */
void pcm_drum_b_6(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0, pitch = 0;

	z80_block(27);
	patch = pcm_drum_b_6_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xEE0u;
	set_pitch(pitch, channel);
	z80_block(24);
	pan = 7u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit B's drum 7: sample 132 at its own pitch, panned 6, keyed on and left ringing (drum_done). */
void pcm_drum_b_7(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_b_7_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 6u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit B's drum 8: sample 135 at its own pitch, panned 4, keyed on and left ringing (drum_done). */
void pcm_drum_b_8(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_b_8_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit B's drum 9: sample 139 at its own pitch, panned 7, keyed on and left ringing (drum_done). */
void pcm_drum_b_9(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_b_9_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 7u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit B's drum A: sample 131 at its own pitch, panned 1, keyed on and left ringing (drum_done). */
void pcm_drum_b_a(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_b_a_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 1u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit B's drum B: sample 136 at its own pitch, panned 6, keyed on and left ringing (drum_done). */
void pcm_drum_b_b(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_b_b_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 6u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit B's drum C: sample 142 at its own pitch, panned 2, keyed on and left ringing (drum_done). */
void pcm_drum_b_c(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_b_c_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 2u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit B's drum D: sample 143 at its own pitch, panned 3, keyed on and left ringing (drum_done). */
void pcm_drum_b_d(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_b_d_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 3u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit B's drum E: sample 146 at its own pitch, panned 4, keyed on and left ringing (drum_done). */
void pcm_drum_b_e(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_b_e_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 4u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}

/* PCM kit B's drum F: sample 147 at its own pitch, panned 3, keyed on and left ringing (drum_done). */
void pcm_drum_b_f(uint16_t channel)
{
	uint8_t pan = 0;
	uint16_t patch = 0;

	z80_block(27);
	patch = pcm_drum_b_f_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(24);
	pan = 3u;
	set_pan(channel, pan);
	z80_block(17);
	key_on(channel);
	z80_block(10);
	drum_done(channel);
}
