/**
 *    Name:        fm_effects.c
 *    Description: the FM effects (commands 01-38), each a chain of handlers its record runs one pass at a time
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the Z80 sound program decompiled into C by
 *    tools/decompile_sound.py, with the names of sound_symbols.txt.
 */
#include "sound.h"

/* Effect 01's sound after 48 passes. */
void fm_effect_02(uint16_t channel)
{
	uint16_t handler = 0;

	z80_block(39);
	CHANNEL(channel)->count = 0x30u;
	handler = fm_effect_02_delay_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Counts down the 48 passes, then starts effect 01 (fm_effect_01). */
void fm_effect_02_delay(uint16_t channel)
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
	fm_effect_01(channel);
}

/* Loads fm_effect_01_patch and keys on pitch 600, for 42 rounds of 32 passes that climb
   (fm_effect_01_retrigger) and then 42 that fall (fm_effect_01_pitch). */
void fm_effect_01(uint16_t channel)
{
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = fm_effect_01_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(65);
	pitch = 0x600u;
	CHANNEL(channel)->pitch = 0x600u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(58);
	CHANNEL(channel)->count = 0x2Au;
	CHANNEL(channel)->timer = 0x20u;
	handler = fm_effect_01_retrigger_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The climbing half: the pitch an eighth of a semitone higher each pass; after each 32 passes it drops 3
   1/4 semitones, so that each round starts 3/4 of a semitone above the last. After 42 rounds the note is
   keyed off and on again for the falling half (fm_effect_01_pitch). */
void fm_effect_01_retrigger(uint16_t channel)
{
	uint32_t zero = 0;
	uint16_t handler = 0, step = 0;
	uint8_t count = 0;

	z80_block(27);
	step = 8u;
	zero = fm_effect_01_move_pitch(step, channel);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(27);
	step = 0xFF30u;
	zero = fm_effect_01_move_pitch(step, channel);
	z80_block(47);
	CHANNEL(channel)->timer = 0x20u;
	count = CHANNEL(channel)->count;
	CHANNEL(channel)->count = count - 1u;
	if (count != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(17);
	key_off(channel);
	z80_block(17);
	key_on(channel);
	z80_block(58);
	CHANNEL(channel)->count = 0x2Au;
	CHANNEL(channel)->timer = 0x20u;
	handler = fm_effect_01_pitch_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The falling half, the mirror of the climbing one: an eighth of a semitone lower each pass and 3 1/4
   semitones up after each 32, for 42 rounds; then stop_channel. */
void fm_effect_01_pitch(uint16_t channel)
{
	uint32_t zero = 0;
	uint16_t step = 0;
	uint8_t count = 0;

	z80_block(27);
	step = 0xFFF8u;
	zero = fm_effect_01_move_pitch(step, channel);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(27);
	step = 0xD0u;
	zero = fm_effect_01_move_pitch(step, channel);
	z80_block(47);
	CHANNEL(channel)->timer = 0x20u;
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

/* Adds the step to the pitch and sets it; counts the timer down and tells whether it ran out. */
uint32_t fm_effect_01_move_pitch(uint16_t step, uint16_t channel)
{
	uint32_t zero = 0;
	uint16_t pitch = 0;
	uint8_t t1 = 0;

	z80_block(104);
	pitch = CHANNEL(channel)->pitch + step;
	CHANNEL(channel)->pitch = pitch;
	set_pitch(pitch, channel);
	z80_block(33);
	t1 = CHANNEL(channel)->timer - 1u;
	zero = t1 == 0u;
	CHANNEL(channel)->timer = t1;
	return zero;
}

/* Effect 03's sound after 16 passes. */
void fm_effect_04(uint16_t channel)
{
	uint16_t handler = 0;

	z80_block(39);
	CHANNEL(channel)->count = 0x10u;
	handler = fm_effect_04_delay_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Counts down the 16 passes, then starts effect 03 (fm_effect_03). */
void fm_effect_04_delay(uint16_t channel)
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
	fm_effect_03(channel);
}

/* Loads fm_effect_03_patch and keys on pitch F00, for 16 rounds of 32 passes (fm_effect_03_pitch). */
void fm_effect_03(uint16_t channel)
{
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = fm_effect_03_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(65);
	pitch = 0xF00u;
	CHANNEL(channel)->pitch = 0xF00u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(77);
	CHANNEL(channel)->count = 0x10u;
	CHANNEL(channel)->timer = 0x20u;
	CHANNEL(channel)->rounds = 0u;
	handler = fm_effect_03_pitch_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Each pass the pitch an eighth of a semitone lower; after each 32 passes it jumps 2 3/4 semitones up,
   so that each round starts 1 1/4 semitones below the last; after 16 rounds stop_channel. */
void fm_effect_03_pitch(uint16_t channel)
{
	uint16_t step = 0;
	uint8_t timer = 0, count = 0;

	z80_block(27);
	step = 0xFFF8u;
	fm_effect_03_move_pitch(step, channel);
	z80_block(28);
	timer = CHANNEL(channel)->timer;
	CHANNEL(channel)->timer = timer - 1u;
	if (timer != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(46);
	CHANNEL(channel)->timer = 0x20u;
	step = 0xB0u;
	fm_effect_03_move_pitch(step, channel);
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

/* Adds the step to the pitch and sets it. */
void fm_effect_03_move_pitch(uint16_t step, uint16_t channel)
{
	uint16_t pitch = 0;

	z80_block(97);
	pitch = CHANNEL(channel)->pitch + step;
	CHANNEL(channel)->pitch = pitch;
	set_pitch(pitch, channel);
}

/* Effect 05's notes after 112 passes, from attenuation 20 (then 38, 50 and 68). */
void fm_effect_06(uint16_t channel)
{
	uint8_t volume = 0;
	uint16_t handler = 0;

	z80_block(43);
	volume = 0x20u;
	CHANNEL(channel)->fm_effect_06.attenuation = 0x20u;
	set_volume(channel, volume);
	z80_block(39);
	CHANNEL(channel)->count = 0x70u;
	handler = fm_effect_06_delay_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Counts down the 112 passes, then effect 05's notes (fm_effect_05_note). */
void fm_effect_06_delay(uint16_t channel)
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
	fm_effect_05_note(channel);
}

/* Four notes, at the volume start_sound leaves (0) and then at attenuations 30, 48 and 60
   (fm_effect_05_note, the attenuation set at 18). */
void fm_effect_05(uint16_t channel)
{
	z80_block(19);
	CHANNEL(channel)->fm_effect_05.attenuation = 0x18u;
	fm_effect_05_note(channel);
}

/* Loads fm_effect_05_patch, then the note four times (fm_effect_05_retrigger). */
void fm_effect_05_note(uint16_t channel)
{
	uint16_t patch = 0;

	z80_block(27);
	patch = fm_effect_05_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(19);
	CHANNEL(channel)->count = 4u;
	fm_effect_05_retrigger(channel);
}

/* Sets pitch 800 and keys on, for 128 passes of fm_effect_05_slide. */
void fm_effect_05_retrigger(uint16_t channel)
{
	uint16_t handler = 0, pitch = 0;

	z80_block(65);
	pitch = 0x800u;
	CHANNEL(channel)->pitch = 0x800u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(39);
	CHANNEL(channel)->timer = 0x80u;
	handler = fm_effect_05_slide_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The pitch a quarter semitone higher each pass, played 28 semitones higher in turn every 32 passes;
   after the 128 passes 24 quieter (set_volume) and the next time (fm_effect_05_retrigger), and
   stop_channel after the fourth. */
void fm_effect_05_slide(uint16_t channel)
{
	uint8_t volume = 0;
	uint16_t pitch = 0;
	uint8_t timer = 0, count = 0;

	z80_block(127);
	pitch = CHANNEL(channel)->pitch + 0x10u;
	CHANNEL(channel)->pitch = pitch;
	if ((CHANNEL(channel)->timer >> 5) & 1u)
	{
		z80_block(21);
		pitch += 0x700u;
	}
	z80_block(17);
	set_pitch(pitch, channel);
	z80_block(28);
	timer = CHANNEL(channel)->timer;
	CHANNEL(channel)->timer = timer - 1u;
	if (timer != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(62);
	volume = CHANNEL(channel)->fm_effect_05.attenuation + 0x18u;
	CHANNEL(channel)->fm_effect_05.attenuation = volume;
	set_volume(channel, volume);
	z80_block(33);
	count = CHANNEL(channel)->count;
	CHANNEL(channel)->count = count - 1u;
	if (count != 1u)
	{
		fm_effect_05_retrigger(channel);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Loads fm_effect_07_patch and keys on pitch 1800, for 1024 passes of fm_effect_07_slide. */
void fm_effect_07(uint16_t channel)
{
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = fm_effect_07_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(65);
	pitch = 0x1800u;
	CHANNEL(channel)->pitch = 0x1800u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(68);
	CHANNEL(channel)->fm_effect_07.passes = 0x400u;
	handler = fm_effect_07_slide_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The pitch a 64th of a semitone lower each pass (16 semitones in the 1024 passes); then stop_channel. */
void fm_effect_07_slide(uint16_t channel)
{
	uint16_t passes = 0, pitch = 0;

	z80_block(114);
	pitch = CHANNEL(channel)->pitch - 1u;
	CHANNEL(channel)->pitch = pitch;
	set_pitch(pitch, channel);
	z80_block(95);
	passes = CHANNEL(channel)->fm_effect_07.passes - 1u;
	CHANNEL(channel)->fm_effect_07.passes = passes;
	if ((uint8_t)(passes | (passes >> 8)) != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Effect 08's notes after 12 passes. */
void fm_effect_09(uint16_t channel)
{
	uint16_t handler = 0;

	z80_block(39);
	CHANNEL(channel)->fm_effect_09.timer = 0xCu;
	handler = fm_effect_09_delay_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Counts down the 12 passes (in the timer effect 08 then uses), then starts effect 08 (fm_effect_08). */
void fm_effect_09_delay(uint16_t channel)
{
	uint8_t timer = 0;

	z80_block(28);
	timer = CHANNEL(channel)->fm_effect_09.timer;
	CHANNEL(channel)->fm_effect_09.timer = timer - 1u;
	if (timer != 1u)
	{
		z80_cycles(6);
		return;
	}
	fm_effect_08(channel);
}

/* Loads fm_effect_08_patch and plays the 7 notes of fm_effect_08_pitches from the next pass
   (fm_effect_08_retrigger). */
void fm_effect_08(uint16_t channel)
{
	uint16_t handler = 0, patch = 0;

	z80_block(27);
	patch = fm_effect_08_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(87);
	CHANNEL(channel)->fm_effect_08.next_pitch = fm_effect_08_pitches_ADDRESS;
	CHANNEL(channel)->fm_effect_08.timer = 1u;
	handler = fm_effect_08_retrigger_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Every 24 passes, key off and the next pitch of fm_effect_08_pitches keyed on; at the list's end (a
   word FFxx) the last note's release for 256 passes (fm_effect_08_hold). */
void fm_effect_08_retrigger(uint16_t channel)
{
	uint8_t pitch_high = 0, pitch_low = 0;
	uint16_t handler = 0, next_pitch = 0, pitch = 0;
	uint8_t timer = 0;

	z80_block(28);
	timer = CHANNEL(channel)->fm_effect_08.timer;
	CHANNEL(channel)->fm_effect_08.timer = timer - 1u;
	if (timer != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(17);
	key_off(channel);
	z80_block(142);
	CHANNEL(channel)->fm_effect_08.timer = 0x18u;
	next_pitch = CHANNEL(channel)->fm_effect_08.next_pitch;
	pitch_low = z80_read8(next_pitch);
	next_pitch++;
	pitch_high = z80_read8(next_pitch);
	next_pitch++;
	CHANNEL(channel)->fm_effect_08.next_pitch = next_pitch;
	if (pitch_high == 0xFFu)
	{
		z80_block(39);
		CHANNEL(channel)->fm_effect_08.timer = 0u;
		handler = fm_effect_08_hold_ADDRESS;
		set_channel_handler(handler, channel);
		return;
	}
	z80_block(21);
	pitch = ((uint32_t)pitch_high << 8) | pitch_low;
	set_pitch(pitch, channel);
	z80_block(10);
	key_on(channel);
}

/* Counts down the 256 passes, then stop_channel. */
void fm_effect_08_hold(uint16_t channel)
{
	uint8_t timer = 0;

	z80_block(28);
	timer = CHANNEL(channel)->fm_effect_08.timer;
	CHANNEL(channel)->fm_effect_08.timer = timer - 1u;
	if (timer != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Effect 0C's notes after 16 passes. */
void fm_effect_0d(uint16_t channel)
{
	uint16_t handler = 0;

	z80_block(39);
	CHANNEL(channel)->count = 0x10u;
	handler = fm_effect_0d_delay_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Counts down the 16 passes, then starts effect 0C (fm_effect_0c). */
void fm_effect_0d_delay(uint16_t channel)
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
	fm_effect_0c(channel);
}

/* Loads fm_effect_0c_patch and keys on pitch 1300: six notes of 24 passes, 8 semitones down and 2 up in
   turn (fm_effect_0c_retrigger), the last one held. */
void fm_effect_0c(uint16_t channel)
{
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = fm_effect_0c_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(65);
	pitch = 0x1300u;
	CHANNEL(channel)->pitch = 0x1300u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(58);
	CHANNEL(channel)->count = 3u;
	CHANNEL(channel)->timer = 0x18u;
	handler = fm_effect_0c_retrigger_ADDRESS;
	set_channel_handler(handler, channel);
}

/* After the 24 passes, the note 8 semitones lower (fm_effect_0c_move_pitch); then
   fm_effect_0c_retrigger_2. */
void fm_effect_0c_retrigger(uint16_t channel)
{
	uint16_t handler = 0, step = 0;
	uint8_t timer = 0;

	z80_block(28);
	timer = CHANNEL(channel)->timer;
	CHANNEL(channel)->timer = timer - 1u;
	if (timer != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(27);
	step = SOUND_BANK_FE00;
	fm_effect_0c_move_pitch(step, channel);
	z80_block(20);
	handler = fm_effect_0c_retrigger_2_ADDRESS;
	set_channel_handler(handler, channel);
}

/* After the 24 passes, the note 2 semitones higher and fm_effect_0c_retrigger again; the third time the
   note instead goes on 256 passes more (fm_effect_0c_hold). */
void fm_effect_0c_retrigger_2(uint16_t channel)
{
	uint16_t handler = 0, step = 0;
	uint8_t timer = 0, count = 0;

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
	if (count == 1u)
	{
		z80_block(39);
		CHANNEL(channel)->timer = 0u;
		handler = fm_effect_0c_hold_ADDRESS;
		set_channel_handler(handler, channel);
		return;
	}
	z80_block(27);
	step = 0x80u;
	fm_effect_0c_move_pitch(step, channel);
	z80_block(20);
	handler = fm_effect_0c_retrigger_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Counts down the 256 passes, then stop_channel. */
void fm_effect_0c_hold(uint16_t channel)
{
	uint8_t timer = 0;

	z80_block(28);
	timer = CHANNEL(channel)->timer;
	CHANNEL(channel)->timer = timer - 1u;
	if (timer != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Keys off, moves the pitch by the step, sets it and keys on again, for 24 passes. */
void fm_effect_0c_move_pitch(uint16_t step, uint16_t channel)
{
	uint16_t pitch = 0;

	z80_block(17);
	key_off(channel);
	z80_block(104);
	pitch = CHANNEL(channel)->pitch + step;
	CHANNEL(channel)->pitch = pitch;
	set_pitch(pitch, channel);
	z80_block(29);
	CHANNEL(channel)->timer = 0x18u;
	key_on(channel);
}

/* Loads fm_effect_0e_patch and keys on pitch 1400: a dive of 4 octaves, a climb, then 8 rising sweeps of
   2 octaves (fm_effect_0e_pitch). */
void fm_effect_0e(uint16_t channel)
{
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = fm_effect_0e_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(65);
	pitch = 0x1400u;
	CHANNEL(channel)->pitch = fm_effect_0e_patch_ADDRESS + 0x14u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(58);
	CHANNEL(channel)->count = 8u;
	CHANNEL(channel)->timer = 0x30u;
	handler = fm_effect_0e_pitch_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The dive: a semitone lower each pass for 48 passes; then 96 passes of fm_effect_0e_pitch_2. */
void fm_effect_0e_pitch(uint16_t channel)
{
	uint32_t zero = 0;
	uint16_t handler = 0, step = 0;

	z80_block(27);
	step = 0xFFC0u;
	zero = fm_effect_0e_move_pitch(step, channel);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(39);
	CHANNEL(channel)->timer = 0x60u;
	handler = fm_effect_0e_pitch_2_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The climb: 3/8 of a semitone higher each pass for the 96 passes, the first 33 played 28 semitones
   higher; then the first sweep (fm_effect_0e_round). */
void fm_effect_0e_pitch_2(uint16_t channel)
{
	uint32_t zero = 0;
	uint16_t step = 0;

	z80_block(27);
	step = 0x18u;
	zero = fm_effect_0e_move_pitch(step, channel);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	fm_effect_0e_round(channel);
}

/* Starts a sweep: the pitch 24 semitones lower, for 64 passes of fm_effect_0e_pitch_3. */
void fm_effect_0e_round(uint16_t channel)
{
	uint16_t handler = 0, pitch = 0;

	z80_block(114);
	pitch = CHANNEL(channel)->pitch - 0x600u;
	CHANNEL(channel)->pitch = pitch;
	set_pitch(pitch, channel);
	z80_block(39);
	CHANNEL(channel)->timer = 0x40u;
	handler = fm_effect_0e_pitch_3_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The sweep: 3/8 of a semitone higher each pass for the 64 passes (back where it started), the first
   pass 28 semitones higher; after 8 sweeps (fm_effect_0e_round) stop_channel. */
void fm_effect_0e_pitch_3(uint16_t channel)
{
	uint32_t zero = 0;
	uint16_t step = 0;
	uint8_t count = 0;

	z80_block(27);
	step = 0x18u;
	zero = fm_effect_0e_move_pitch(step, channel);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(33);
	count = CHANNEL(channel)->count;
	CHANNEL(channel)->count = count - 1u;
	if (count != 1u)
	{
		fm_effect_0e_round(channel);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Adds the step to the pitch and sets it, 28 semitones higher while the timer is 64 or more; counts the
   timer down and tells whether it ran out. */
uint32_t fm_effect_0e_move_pitch(uint16_t step, uint16_t channel)
{
	uint32_t zero = 0;
	uint16_t pitch = 0;
	uint8_t t1 = 0;

	z80_block(117);
	pitch = CHANNEL(channel)->pitch + step;
	CHANNEL(channel)->pitch = pitch;
	if ((CHANNEL(channel)->timer >> 6) & 1u)
	{
		z80_block(21);
		pitch += 0x700u;
	}
	z80_block(17);
	set_pitch(pitch, channel);
	z80_block(33);
	t1 = CHANNEL(channel)->timer - 1u;
	zero = t1 == 0u;
	CHANNEL(channel)->timer = t1;
	return zero;
}

/* Loads fm_effect_0f_patch (fm_effect_0e_patch's bytes) and keys on pitch C00, for 8 rounds of 64 passes
   (fm_effect_0f_slide). */
void fm_effect_0f(uint16_t channel)
{
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = fm_effect_0f_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(65);
	pitch = 0xC00u;
	CHANNEL(channel)->pitch = 0xC00u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(58);
	CHANNEL(channel)->count = 8u;
	CHANNEL(channel)->timer = 0x40u;
	handler = fm_effect_0f_slide_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The pitch 3/8 of a semitone higher each pass, played 16 semitones higher in turn every 16 passes;
   after each 64 passes it drops 16 semitones, so that each round starts 7 5/8 semitones above the last;
   after 8 rounds stop_channel. */
void fm_effect_0f_slide(uint16_t channel)
{
	uint16_t pitch = 0;
	uint8_t timer = 0, count = 0;

	z80_block(33);
	timer = CHANNEL(channel)->timer;
	CHANNEL(channel)->timer = timer - 1u;
	if (timer == 1u)
	{
		z80_block(52);
		CHANNEL(channel)->timer = 0x40u;
		count = CHANNEL(channel)->count;
		CHANNEL(channel)->count = count - 1u;
		if (count == 1u)
		{
			stop_channel(channel);
			return;
		}
		z80_block(107);
		pitch = CHANNEL(channel)->pitch - 0x400u;
		CHANNEL(channel)->pitch = pitch;
		set_pitch(pitch, channel);
		return;
	}
	z80_block(127);
	pitch = CHANNEL(channel)->pitch + 0x18u;
	CHANNEL(channel)->pitch = pitch;
	if (((CHANNEL(channel)->timer >> 4) & 1u) == 0u)
	{
		set_pitch(pitch, channel);
		return;
	}
	z80_block(31);
	pitch += 0x400u;
	set_pitch(pitch, channel);
}

/* Loads fm_effect_10_patch and keys on pitch 1000, for 8 rounds of 64 passes (fm_effect_10_slide). */
void fm_effect_10(uint16_t channel)
{
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = fm_effect_10_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(65);
	pitch = 0x1000u;
	CHANNEL(channel)->pitch = 0x1000u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(58);
	CHANNEL(channel)->count = 8u;
	CHANNEL(channel)->timer = 0x40u;
	handler = fm_effect_10_slide_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The pitch a semitone higher each pass, played 4 semitones higher in turn every 8 passes; after each 64
   passes it drops 16 semitones; after 8 rounds stop_channel. It climbs past the top of the 8 octaves,
   where set_pitch starts again from the bottom. */
void fm_effect_10_slide(uint16_t channel)
{
	uint16_t pitch = 0;
	uint8_t timer = 0, count = 0;

	z80_block(33);
	timer = CHANNEL(channel)->timer;
	CHANNEL(channel)->timer = timer - 1u;
	if (timer == 1u)
	{
		z80_block(52);
		CHANNEL(channel)->timer = 0x40u;
		count = CHANNEL(channel)->count;
		CHANNEL(channel)->count = count - 1u;
		if (count == 1u)
		{
			stop_channel(channel);
			return;
		}
		z80_block(107);
		pitch = CHANNEL(channel)->pitch - 0x400u;
		CHANNEL(channel)->pitch = pitch;
		set_pitch(pitch, channel);
		return;
	}
	z80_block(127);
	pitch = CHANNEL(channel)->pitch + 0x40u;
	CHANNEL(channel)->pitch = pitch;
	if (((CHANNEL(channel)->timer >> 3) & 1u) == 0u)
	{
		set_pitch(pitch, channel);
		return;
	}
	z80_block(31);
	pitch += 0x100u;
	set_pitch(pitch, channel);
}

/* Loads fm_effect_11_patch and keys on pitch 1700, for 512 passes of fm_effect_11_pitch. */
void fm_effect_11(uint16_t channel)
{
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = fm_effect_11_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(65);
	pitch = 0x1700u;
	CHANNEL(channel)->pitch = 0x1700u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(68);
	CHANNEL(channel)->fm_effect_11.passes = 0x200u;
	handler = fm_effect_11_pitch_ADDRESS;
	set_channel_handler(handler, channel);
}

/* A trill sliding down: the pitch an eighth of a semitone lower each pass (64 semitones in the 512
   passes, fm_effect_11_move_pitch); then stop_channel. */
void fm_effect_11_pitch(uint16_t channel)
{
	uint8_t passes_high = 0, passes_low = 0;
	uint16_t step = 0;
	uint16_t t1 = 0;

	z80_block(27);
	step = 0xFFF8u;
	fm_effect_11_move_pitch(step, channel);
	z80_block(95);
	t1 = CHANNEL(channel)->fm_effect_11.passes - 1u;
	passes_high = (uint8_t)(t1 >> 8);
	passes_low = (uint8_t)t1;
	CHANNEL(channel)->fm_effect_11.passes = ((uint32_t)passes_high << 8) | passes_low;
	if ((passes_high | passes_low) != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Adds the step to the pitch and sets it, 4 semitones higher in turn every 2 passes (by the passes
   left). */
void fm_effect_11_move_pitch(uint16_t step, uint16_t channel)
{
	uint16_t pitch = 0;

	z80_block(117);
	pitch = CHANNEL(channel)->pitch + step;
	CHANNEL(channel)->pitch = pitch;
	if ((CHANNEL(channel)->fm_effect_11.passes_low >> 1) & 1u)
	{
		z80_block(21);
		pitch += 0x100u;
	}
	z80_block(10);
	set_pitch(pitch, channel);
}

/* Loads fm_effect_12_patch and keys on pitch 400, held 768 passes (fm_effect_12_delay). */
void fm_effect_12(uint16_t channel)
{
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = fm_effect_12_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(65);
	pitch = 0x400u;
	CHANNEL(channel)->fm_effect_12.pitch = 0x400u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(58);
	CHANNEL(channel)->fm_effect_12.passes = 0x300u;
	handler = fm_effect_12_delay_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Counts down the 768 passes, then 416 passes of fm_effect_12_slide. */
void fm_effect_12_delay(uint16_t channel)
{
	uint8_t passes_high = 0, passes_low = 0;
	uint16_t handler = 0;
	uint16_t t1 = 0;

	z80_block(95);
	t1 = CHANNEL(channel)->fm_effect_12.passes - 1u;
	passes_high = (uint8_t)(t1 >> 8);
	passes_low = (uint8_t)t1;
	CHANNEL(channel)->fm_effect_12.passes = ((uint32_t)passes_high << 8) | passes_low;
	if ((passes_low | passes_high) != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(58);
	CHANNEL(channel)->fm_effect_12.passes = 0x1A0u;
	handler = fm_effect_12_slide_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The pitch a 32nd of a semitone lower each pass (13 semitones in the 416 passes), played 3 semitones
   lower every other pass; then stop_channel. */
void fm_effect_12_slide(uint16_t channel)
{
	uint16_t passes = 0, pitch = 0;

	z80_block(115);
	pitch = CHANNEL(channel)->fm_effect_12.pitch - 1u - 1u;
	CHANNEL(channel)->fm_effect_12.pitch = pitch;
	if ((CHANNEL(channel)->fm_effect_12.passes_low & 1u) == 0u)
		z80_cycles(5);
	else
	{
		z80_block(21);
		pitch -= 0xC0u;
	}
	z80_block(17);
	set_pitch(pitch, channel);
	z80_block(95);
	passes = CHANNEL(channel)->fm_effect_12.passes - 1u;
	CHANNEL(channel)->fm_effect_12.passes = passes;
	if ((uint8_t)(passes | (passes >> 8)) != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Loads fm_effect_13_patch and keys on pitch 700, for 256 passes of fm_effect_13_slide. */
void fm_effect_13(uint16_t channel)
{
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = fm_effect_13_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(84);
	pitch = 0x700u;
	CHANNEL(channel)->fm_effect_13.pitch_fraction = 0u;
	CHANNEL(channel)->fm_effect_13.pitch = 0x700u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(58);
	CHANNEL(channel)->fm_effect_13.passes = 0x100u;
	handler = fm_effect_13_slide_ADDRESS;
	set_channel_handler(handler, channel);
}

/* A rising trill: the pitch with its fraction up 1E0 each pass (7 1/2 semitones in the 256 passes),
   played 8 semitones higher every other pass; then 320 passes of fm_effect_13_hold. */
void fm_effect_13_slide(uint16_t channel)
{
	uint32_t carry = 0;
	uint16_t fraction_word = 0, handler = 0, passes = 0, pitch = 0;

	z80_block(104);
	fraction_word = (CHANNEL(channel)->fm_effect_13.pitch_fraction | ((uint32_t)(CHANNEL(channel)->fm_effect_13.pitch & 0xFFu) << 8u));
	carry = (uint16_t)(fraction_word + 0x1E0u) < fraction_word;
	fraction_word += 0x1E0u;
	AS16(CHANNEL(channel)->fm_effect_13.pitch_fraction) = fraction_word;
	if (carry == 0u)
		z80_cycles(5);
	else
	{
		z80_block(23);
		AT8(CHANNEL(channel)->fm_effect_13.pitch, 1)++;
	}
	z80_block(65);
	pitch = CHANNEL(channel)->fm_effect_13.pitch;
	if ((CHANNEL(channel)->fm_effect_13.passes_low & 1u) == 0u)
		z80_cycles(5);
	else
	{
		z80_block(21);
		pitch += 0x200u;
	}
	z80_block(17);
	set_pitch(pitch, channel);
	z80_block(95);
	passes = CHANNEL(channel)->fm_effect_13.passes - 1u;
	CHANNEL(channel)->fm_effect_13.passes = passes;
	if ((uint8_t)(passes | (passes >> 8)) != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(58);
	CHANNEL(channel)->fm_effect_13.passes = 0x140u;
	handler = fm_effect_13_hold_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The trill held for the 320 passes; then key off, and 192 passes of fm_effect_13_fall while the note
   dies away. */
void fm_effect_13_hold(uint16_t channel)
{
	uint16_t handler = 0, passes = 0, pitch = 0;

	z80_block(62);
	passes = CHANNEL(channel)->fm_effect_13.passes - 1u;
	if ((uint8_t)(passes | (passes >> 8)) == 0u)
	{
		z80_block(55);
		CHANNEL(channel)->fm_effect_13.passes = 0xC0u;
		key_off(channel);
		z80_block(20);
		handler = fm_effect_13_fall_ADDRESS;
		set_channel_handler(handler, channel);
		return;
	}
	z80_block(103);
	CHANNEL(channel)->fm_effect_13.passes = passes;
	pitch = CHANNEL(channel)->fm_effect_13.pitch;
	if ((CHANNEL(channel)->fm_effect_13.passes_low & 1u) == 0u)
		z80_cycles(5);
	else
	{
		z80_block(21);
		pitch += 0x200u;
	}
	z80_block(17);
	set_pitch(pitch, channel);
	z80_block(10);
}

/* The trill falls: the pitch 6 lower each pass (18 semitones in the 192 passes), 8 semitones higher
   every other pass; then stop_channel. */
void fm_effect_13_fall(uint16_t channel)
{
	uint16_t passes = 0, pitch = 0;

	z80_block(132);
	pitch = CHANNEL(channel)->fm_effect_13.pitch - 6u;
	CHANNEL(channel)->fm_effect_13.pitch = pitch;
	if ((CHANNEL(channel)->fm_effect_13.passes_low & 1u) == 0u)
		z80_cycles(5);
	else
	{
		z80_block(21);
		pitch += 0x200u;
	}
	z80_block(17);
	set_pitch(pitch, channel);
	z80_block(95);
	passes = CHANNEL(channel)->fm_effect_13.passes - 1u;
	CHANNEL(channel)->fm_effect_13.passes = passes;
	if ((uint8_t)(passes | (passes >> 8)) != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Loads fm_effect_14_patch and keys on pitch 200, for 512 passes of fm_effect_14_slide. */
void fm_effect_14(uint16_t channel)
{
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = fm_effect_14_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(84);
	pitch = 0x200u;
	CHANNEL(channel)->fm_effect_14.pitch_fraction = 0u;
	CHANNEL(channel)->fm_effect_14.pitch = 0x200u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(58);
	CHANNEL(channel)->fm_effect_14.passes = 0x200u;
	handler = fm_effect_14_slide_ADDRESS;
	set_channel_handler(handler, channel);
}

/* A rising trill: the pitch with its fraction up C0 each pass (6 semitones in the 512 passes), played 2
   semitones higher every other pass; then key off and 2560 passes of fm_effect_14_hold. */
void fm_effect_14_slide(uint16_t channel)
{
	uint32_t carry = 0;
	uint16_t handler = 0, passes = 0, pitch = 0;

	z80_block(66);
	pitch = (CHANNEL(channel)->fm_effect_14.pitch_fraction | ((uint32_t)(CHANNEL(channel)->fm_effect_14.pitch & 0xFFu) << 8u));
	carry = (uint16_t)(pitch + 0xC0u) < pitch;
	pitch += 0xC0u;
	if (carry == 0u)
		z80_cycles(5);
	else
	{
		z80_block(23);
		AT8(CHANNEL(channel)->fm_effect_14.pitch, 1)++;
	}
	z80_block(88);
	AS16(CHANNEL(channel)->fm_effect_14.pitch_fraction) = pitch;
	pitch = (pitch >> 8) | ((uint32_t)(uint8_t)(CHANNEL(channel)->fm_effect_14.pitch >> 8u) << 8);
	if ((CHANNEL(channel)->fm_effect_14.passes_low & 1u) == 0u)
		z80_cycles(5);
	else
	{
		z80_block(21);
		pitch += 0x80u;
	}
	z80_block(17);
	set_pitch(pitch, channel);
	z80_block(95);
	passes = CHANNEL(channel)->fm_effect_14.passes - 1u;
	CHANNEL(channel)->fm_effect_14.passes = passes;
	if ((uint8_t)(passes | (passes >> 8)) != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(17);
	key_off(channel);
	z80_block(58);
	CHANNEL(channel)->fm_effect_14.passes = 0xA00u;
	handler = fm_effect_14_hold_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The trill goes on without moving while the note dies away, for the 2560 passes; then stop_channel. */
void fm_effect_14_hold(uint16_t channel)
{
	uint16_t passes = 0, pitch = 0;

	z80_block(65);
	pitch = CHANNEL(channel)->fm_effect_14.pitch;
	if ((CHANNEL(channel)->fm_effect_14.passes_low & 1u) == 0u)
		z80_cycles(5);
	else
	{
		z80_block(21);
		pitch += 0x80u;
	}
	z80_block(17);
	set_pitch(pitch, channel);
	z80_block(95);
	passes = CHANNEL(channel)->fm_effect_14.passes - 1u;
	CHANNEL(channel)->fm_effect_14.passes = passes;
	if ((uint8_t)(passes | (passes >> 8)) != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Loads fm_effect_15_patch and keys on pitch 400 for 768 passes (fm_effect_15_note). */
void fm_effect_15(uint16_t channel)
{
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = fm_effect_15_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0x400u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(58);
	CHANNEL(channel)->fm_effect_15.passes = 0x300u;
	handler = fm_effect_15_note_ADDRESS;
	set_channel_handler(handler, channel);
}

/* After the 768 passes, key off and a second note: fm_effect_15_patch_2 at pitch 300 (kept in the word
   that counted the passes), for 176 passes of fm_effect_15_slide. */
void fm_effect_15_note(uint16_t channel)
{
	uint16_t handler = 0, passes = 0, patch = 0, pitch = 0;

	z80_block(95);
	passes = CHANNEL(channel)->fm_effect_15.passes - 1u;
	CHANNEL(channel)->fm_effect_15.passes = passes;
	if ((uint8_t)(passes | (passes >> 8)) != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(17);
	key_off(channel);
	z80_block(27);
	patch = fm_effect_15_patch_2_ADDRESS;
	load_patch(patch, channel);
	z80_block(65);
	pitch = 0x300u;
	CHANNEL(channel)->fm_effect_15.passes = 0x300u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(39);
	CHANNEL(channel)->fm_effect_15.timer = 0xB0u;
	handler = fm_effect_15_slide_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The pitch a 16th of a semitone lower each pass, played 10 semitones higher every other pass; after the
   176 passes stop_channel. */
void fm_effect_15_slide(uint16_t channel)
{
	uint16_t pitch = 0;
	uint8_t timer = 0;

	z80_block(124);
	pitch = CHANNEL(channel)->fm_effect_15_slide.pitch - 4u;
	CHANNEL(channel)->fm_effect_15_slide.pitch = pitch;
	if ((CHANNEL(channel)->fm_effect_15_slide.timer & 1u) == 0u)
		z80_cycles(5);
	else
	{
		z80_block(21);
		pitch += 0x280u;
	}
	z80_block(17);
	set_pitch(pitch, channel);
	z80_block(33);
	timer = CHANNEL(channel)->fm_effect_15_slide.timer;
	CHANNEL(channel)->fm_effect_15_slide.timer = timer - 1u;
	if (timer == 1u)
	{
		stop_channel(channel);
		return;
	}
	z80_block(10);
}

/* Effect 16's sound after 44 passes, at attenuation 0A. */
void fm_effect_17(uint16_t channel)
{
	uint8_t volume = 0;
	uint16_t handler = 0;

	z80_block(24);
	volume = 0xAu;
	set_volume(channel, volume);
	z80_block(39);
	CHANNEL(channel)->count = 0x2Cu;
	handler = fm_effect_17_delay_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Counts down the 44 passes, then starts effect 16 (fm_effect_16). */
void fm_effect_17_delay(uint16_t channel)
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
	fm_effect_16(channel);
}

/* Loads fm_effect_16_patch and keys on pitch 600, for 11 rounds of 48 passes (fm_effect_16_pitch). */
void fm_effect_16(uint16_t channel)
{
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = fm_effect_16_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(65);
	pitch = 0x600u;
	CHANNEL(channel)->pitch = 0x600u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(77);
	CHANNEL(channel)->count = 0xBu;
	CHANNEL(channel)->timer = 0x30u;
	CHANNEL(channel)->rounds = 0u;
	handler = fm_effect_16_pitch_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The pitch a quarter semitone higher each pass; after each 48 passes (an octave) it drops 8 semitones,
   so that each round starts 4 semitones above the last; after 11 rounds stop_channel. */
void fm_effect_16_pitch(uint16_t channel)
{
	uint16_t step = 0;
	uint8_t timer = 0, count = 0;

	z80_block(27);
	step = 0x10u;
	fm_effect_16_move_pitch(step, channel);
	z80_block(28);
	timer = CHANNEL(channel)->timer;
	CHANNEL(channel)->timer = timer - 1u;
	if (timer != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(46);
	CHANNEL(channel)->timer = 0x30u;
	step = SOUND_BANK_FE00;
	fm_effect_16_move_pitch(step, channel);
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

/* Adds the step to the pitch and sets it. */
void fm_effect_16_move_pitch(uint16_t step, uint16_t channel)
{
	uint16_t pitch = 0;

	z80_block(97);
	pitch = CHANNEL(channel)->pitch + step;
	CHANNEL(channel)->pitch = pitch;
	set_pitch(pitch, channel);
}

/* Loads fm_effect_18_patch and keys on pitch 800, for 112 passes of fm_effect_18_slide. */
void fm_effect_18(uint16_t channel)
{
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = fm_effect_18_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(65);
	pitch = 0x800u;
	CHANNEL(channel)->fm_effect_18.pitch = 0x800u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(39);
	CHANNEL(channel)->count = 0x70u;
	handler = fm_effect_18_slide_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The pitch half a semitone higher each pass, played an octave higher in turn every 16 passes; after the
   112 passes stop_channel. */
void fm_effect_18_slide(uint16_t channel)
{
	uint16_t pitch = 0;
	uint8_t count = 0;

	z80_block(33);
	count = CHANNEL(channel)->count;
	CHANNEL(channel)->count = count - 1u;
	if (count == 1u)
	{
		stop_channel(channel);
		return;
	}
	z80_block(127);
	pitch = CHANNEL(channel)->fm_effect_18.pitch + 0x20u;
	CHANNEL(channel)->fm_effect_18.pitch = pitch;
	if ((CHANNEL(channel)->count >> 4) & 1u)
	{
		z80_block(21);
		pitch += 0x300u;
	}
	z80_block(10);
	set_pitch(pitch, channel);
}

/* Loads fm_effect_19_patch: a falling note four times (fm_effect_19_retrigger), at the volume
   start_sound leaves (0) and then at attenuations 16, 21 and 2C. */
void fm_effect_19(uint16_t channel)
{
	uint16_t patch = 0;

	z80_block(27);
	patch = fm_effect_19_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(38);
	CHANNEL(channel)->count = 4u;
	CHANNEL(channel)->fm_effect_19.attenuation = 0xBu;
	fm_effect_19_retrigger(channel);
}

/* Sets pitch 1300 and keys on, for 64 passes of fm_effect_19_slide. */
void fm_effect_19_retrigger(uint16_t channel)
{
	uint16_t handler = 0, pitch = 0;

	z80_block(65);
	pitch = 0x1300u;
	CHANNEL(channel)->pitch = 0x1300u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(39);
	CHANNEL(channel)->timer = 0x40u;
	handler = fm_effect_19_slide_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The pitch a quarter semitone lower each pass, played an octave higher in turn every 16 passes; after
   the 64 passes 11 quieter (set_volume) and the next time (fm_effect_19_retrigger), and stop_channel
   after the fourth. */
void fm_effect_19_slide(uint16_t channel)
{
	uint8_t volume = 0;
	uint16_t pitch = 0;
	uint8_t timer = 0, count = 0;

	z80_block(127);
	pitch = CHANNEL(channel)->pitch - 0x10u;
	CHANNEL(channel)->pitch = pitch;
	if ((CHANNEL(channel)->timer >> 4) & 1u)
	{
		z80_block(21);
		pitch += 0x300u;
	}
	z80_block(17);
	set_pitch(pitch, channel);
	z80_block(28);
	timer = CHANNEL(channel)->timer;
	CHANNEL(channel)->timer = timer - 1u;
	if (timer != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(62);
	volume = CHANNEL(channel)->fm_effect_19.attenuation + 0xBu;
	CHANNEL(channel)->fm_effect_19.attenuation = volume;
	set_volume(channel, volume);
	z80_block(33);
	count = CHANNEL(channel)->count;
	CHANNEL(channel)->count = count - 1u;
	if (count != 1u)
	{
		fm_effect_19_retrigger(channel);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Loads fm_effect_1a_patch: a falling note three times (fm_effect_1a_retrigger). */
void fm_effect_1a(uint16_t channel)
{
	uint16_t patch = 0;

	z80_block(27);
	patch = fm_effect_1a_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(19);
	CHANNEL(channel)->count = 3u;
	fm_effect_1a_retrigger(channel);
}

/* Sets pitch 1400 and keys on, for 256 passes of fm_effect_1a_slide. */
void fm_effect_1a_retrigger(uint16_t channel)
{
	uint16_t handler = 0, pitch = 0;

	z80_block(65);
	pitch = 0x1400u;
	CHANNEL(channel)->pitch = fm_effect_0e_patch_ADDRESS + 0x14u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(39);
	CHANNEL(channel)->timer = 0u;
	handler = fm_effect_1a_slide_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The pitch an eighth of a semitone lower each pass (32 semitones in the 256 passes), played an octave
   higher in turn every 32 passes; then the next time (fm_effect_1a_retrigger), and stop_channel after
   the third. */
void fm_effect_1a_slide(uint16_t channel)
{
	uint16_t pitch = 0;
	uint8_t timer = 0, count = 0;

	z80_block(127);
	pitch = CHANNEL(channel)->pitch - 8u;
	CHANNEL(channel)->pitch = pitch;
	if ((CHANNEL(channel)->timer >> 5) & 1u)
	{
		z80_block(21);
		pitch += 0x300u;
	}
	z80_block(17);
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
		fm_effect_1a_retrigger(channel);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Loads fm_effect_1b_patch and keys on pitch 1400, for 64 passes of fm_effect_1b_pitch. */
void fm_effect_1b(uint16_t channel)
{
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = fm_effect_1b_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(65);
	pitch = 0x1400u;
	CHANNEL(channel)->pitch = fm_effect_0e_patch_ADDRESS + 0x14u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(39);
	CHANNEL(channel)->timer = 0x40u;
	handler = fm_effect_1b_pitch_ADDRESS;
	set_channel_handler(handler, channel);
}

/* A fast fall: the pitch 7/8 of a semitone lower each pass (56 semitones in the 64 passes); then 224
   passes of fm_effect_1b_pitch_2. */
void fm_effect_1b_pitch(uint16_t channel)
{
	uint32_t zero = 0;
	uint16_t handler = 0, step = 0;

	z80_block(27);
	step = 0xFFC8u;
	zero = fm_effect_1b_move_pitch(step, channel);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(39);
	CHANNEL(channel)->timer = 0xE0u;
	handler = fm_effect_1b_pitch_2_ADDRESS;
	set_channel_handler(handler, channel);
}

/* A slow climb back to where it started: a quarter semitone higher each pass for the 224 passes; then
   stop_channel. */
void fm_effect_1b_pitch_2(uint16_t channel)
{
	uint32_t zero = 0;
	uint16_t step = 0;

	z80_block(27);
	step = 0x10u;
	zero = fm_effect_1b_move_pitch(step, channel);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Adds the step to the pitch and sets it, an octave higher in turn every 32 passes (while bit 5 of the
   timer is clear); counts the timer down and tells whether it ran out. */
uint32_t fm_effect_1b_move_pitch(uint16_t step, uint16_t channel)
{
	uint32_t zero = 0;
	uint16_t pitch = 0;
	uint8_t t1 = 0;

	z80_block(117);
	pitch = CHANNEL(channel)->pitch + step;
	CHANNEL(channel)->pitch = pitch;
	if (((CHANNEL(channel)->timer >> 5) & 1u) == 0u)
	{
		z80_block(21);
		pitch += 0x300u;
	}
	z80_block(17);
	set_pitch(pitch, channel);
	z80_block(33);
	t1 = CHANNEL(channel)->timer - 1u;
	zero = t1 == 0u;
	CHANNEL(channel)->timer = t1;
	return zero;
}

/* Loads fm_effect_1c_patch and keys on pitch 1500: a fall, a climb and 4 short rises
   (fm_effect_1c_pitch). */
void fm_effect_1c(uint16_t channel)
{
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = fm_effect_1c_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(65);
	pitch = 0x1500u;
	CHANNEL(channel)->pitch = 0x1500u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(58);
	CHANNEL(channel)->count = 4u;
	CHANNEL(channel)->timer = 0x30u;
	handler = fm_effect_1c_pitch_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The fall: 1 1/4 semitones lower each pass for 48 passes; then 64 passes of fm_effect_1c_pitch_2. */
void fm_effect_1c_pitch(uint16_t channel)
{
	uint32_t zero = 0;
	uint16_t handler = 0, step = 0;

	z80_block(27);
	step = 0xFFB0u;
	zero = fm_effect_1c_move_pitch(step, channel);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(39);
	CHANNEL(channel)->timer = 0x40u;
	handler = fm_effect_1c_pitch_2_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The climb: half a semitone higher each pass for the 64 passes; then the first short rise
   (fm_effect_1c_round). */
void fm_effect_1c_pitch_2(uint16_t channel)
{
	uint32_t zero = 0;
	uint16_t step = 0;

	z80_block(27);
	step = 0x20u;
	zero = fm_effect_1c_move_pitch(step, channel);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	fm_effect_1c_round(channel);
}

/* Starts a short rise: the pitch 8 semitones lower, for 64 passes of fm_effect_1c_pitch_3. */
void fm_effect_1c_round(uint16_t channel)
{
	uint16_t handler = 0, pitch = 0;

	z80_block(114);
	pitch = CHANNEL(channel)->pitch - 0x200u;
	CHANNEL(channel)->pitch = pitch;
	set_pitch(pitch, channel);
	z80_block(39);
	CHANNEL(channel)->timer = 0x40u;
	handler = fm_effect_1c_pitch_3_ADDRESS;
	set_channel_handler(handler, channel);
}

/* An eighth of a semitone higher each pass for the 64 passes (back where it started); after 4 rises
   (fm_effect_1c_round) stop_channel. */
void fm_effect_1c_pitch_3(uint16_t channel)
{
	uint32_t zero = 0;
	uint16_t step = 0;
	uint8_t count = 0;

	z80_block(27);
	step = 8u;
	zero = fm_effect_1c_move_pitch(step, channel);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(33);
	count = CHANNEL(channel)->count;
	CHANNEL(channel)->count = count - 1u;
	if (count != 1u)
	{
		fm_effect_1c_round(channel);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Adds the step to the pitch and sets it, 28 semitones higher in turn every 16 passes (while bit 4 of
   the timer is set); counts the timer down and tells whether it ran out. */
uint32_t fm_effect_1c_move_pitch(uint16_t step, uint16_t channel)
{
	uint32_t zero = 0;
	uint16_t pitch = 0;
	uint8_t t1 = 0;

	z80_block(117);
	pitch = CHANNEL(channel)->pitch + step;
	CHANNEL(channel)->pitch = pitch;
	if ((CHANNEL(channel)->timer >> 4) & 1u)
	{
		z80_block(21);
		pitch += 0x700u;
	}
	z80_block(17);
	set_pitch(pitch, channel);
	z80_block(33);
	t1 = CHANNEL(channel)->timer - 1u;
	zero = t1 == 0u;
	CHANNEL(channel)->timer = t1;
	return zero;
}

/* Loads fm_effect_1d_patch and keys on pitch 1500: a fall, then 10 short falls from pitch C00
   (fm_effect_1d_pitch). */
void fm_effect_1d(uint16_t channel)
{
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = fm_effect_1d_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(65);
	pitch = 0x1500u;
	CHANNEL(channel)->pitch = 0x1500u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(39);
	CHANNEL(channel)->timer = 0x30u;
	handler = fm_effect_1d_pitch_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The fall: 1 1/4 semitones lower each pass for 48 passes; then the first of 10 short falls
   (fm_effect_1d_pitch_2). */
void fm_effect_1d_pitch(uint16_t channel)
{
	uint32_t zero = 0;
	uint16_t step = 0;

	z80_block(27);
	step = 0xFFB0u;
	zero = fm_effect_1d_move_pitch(step, channel);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(19);
	CHANNEL(channel)->count = 0xAu;
	fm_effect_1d_pitch_2(channel);
}

/* Starts a short fall: pitch C00, for 32 passes of fm_effect_1d_pitch_3. */
void fm_effect_1d_pitch_2(uint16_t channel)
{
	uint16_t handler = 0, pitch = 0;

	z80_block(65);
	pitch = 0xC00u;
	CHANNEL(channel)->pitch = 0xC00u;
	set_pitch(pitch, channel);
	z80_block(39);
	CHANNEL(channel)->timer = 0x20u;
	handler = fm_effect_1d_pitch_3_ADDRESS;
	set_channel_handler(handler, channel);
}

/* A quarter semitone lower each pass for the 32 passes; after 10 falls (fm_effect_1d_pitch_2)
   stop_channel. */
void fm_effect_1d_pitch_3(uint16_t channel)
{
	uint32_t zero = 0;
	uint16_t step = 0;
	uint8_t count = 0;

	z80_block(27);
	step = 0xFFF0u;
	zero = fm_effect_1d_move_pitch(step, channel);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(33);
	count = CHANNEL(channel)->count;
	CHANNEL(channel)->count = count - 1u;
	if (count != 1u)
	{
		fm_effect_1d_pitch_2(channel);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Adds the step to the pitch and sets it, 4 semitones higher while bit 5 of the timer is set; counts the
   timer down and tells whether it ran out. */
uint32_t fm_effect_1d_move_pitch(uint16_t step, uint16_t channel)
{
	uint32_t zero = 0;
	uint16_t pitch = 0;
	uint8_t t1 = 0;

	z80_block(117);
	pitch = CHANNEL(channel)->pitch + step;
	CHANNEL(channel)->pitch = pitch;
	if ((CHANNEL(channel)->timer >> 5) & 1u)
	{
		z80_block(21);
		pitch += 0x100u;
	}
	z80_block(17);
	set_pitch(pitch, channel);
	z80_block(33);
	t1 = CHANNEL(channel)->timer - 1u;
	zero = t1 == 0u;
	CHANNEL(channel)->timer = t1;
	return zero;
}

/* Loads fm_effect_1e_patch (fm_effect_18_patch's bytes) and keys on pitch 1500, for 128 passes of
   fm_effect_1e_slide: effect 18's sound falling instead of rising. */
void fm_effect_1e(uint16_t channel)
{
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = fm_effect_1e_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(65);
	pitch = 0x1500u;
	CHANNEL(channel)->fm_effect_1e.pitch = 0x1500u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(39);
	CHANNEL(channel)->count = 0x80u;
	handler = fm_effect_1e_slide_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The pitch 5/8 of a semitone lower each pass, played an octave higher in turn every 16 passes; after
   the 128 passes stop_channel. */
void fm_effect_1e_slide(uint16_t channel)
{
	uint16_t pitch = 0;
	uint8_t count = 0;

	z80_block(33);
	count = CHANNEL(channel)->count;
	CHANNEL(channel)->count = count - 1u;
	if (count == 1u)
	{
		stop_channel(channel);
		return;
	}
	z80_block(127);
	pitch = CHANNEL(channel)->fm_effect_1e.pitch - 0x28u;
	CHANNEL(channel)->fm_effect_1e.pitch = pitch;
	if ((CHANNEL(channel)->count >> 4) & 1u)
	{
		z80_block(21);
		pitch += 0x300u;
	}
	z80_block(10);
	set_pitch(pitch, channel);
}

/* Loads fm_effect_1f_patch and keys on pitch D00 for 64 passes (fm_effect_1f_retrigger). */
void fm_effect_1f(uint16_t channel)
{
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = fm_effect_1f_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0xD00u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(39);
	CHANNEL(channel)->fm_effect_1f.passes_low = 0x40u;
	handler = fm_effect_1f_retrigger_ADDRESS;
	set_channel_handler(handler, channel);
}

/* After the 64 passes, key off and pitch 1000 keyed on, for 512 passes of fm_effect_1f_end. */
void fm_effect_1f_retrigger(uint16_t channel)
{
	uint16_t handler = 0, pitch = 0;
	uint8_t passes_low = 0;

	z80_block(28);
	passes_low = CHANNEL(channel)->fm_effect_1f.passes_low;
	CHANNEL(channel)->fm_effect_1f.passes_low = passes_low - 1u;
	if (passes_low != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(17);
	key_off(channel);
	z80_block(27);
	pitch = 0x1000u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(68);
	CHANNEL(channel)->fm_effect_1f.passes = 0x200u;
	handler = fm_effect_1f_end_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Counts down the 512 passes, then stop_channel. */
void fm_effect_1f_end(uint16_t channel)
{
	uint8_t passes_high = 0, passes_low = 0;
	uint16_t t1 = 0;

	z80_block(95);
	t1 = CHANNEL(channel)->fm_effect_1f.passes - 1u;
	passes_high = (uint8_t)(t1 >> 8);
	passes_low = (uint8_t)t1;
	CHANNEL(channel)->fm_effect_1f.passes = ((uint32_t)passes_high << 8) | passes_low;
	if ((passes_low | passes_high) != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Loads fm_effect_20_patch and keys on pitch 1700, for 48 passes of fm_effect_20_pitch. */
void fm_effect_20(uint16_t channel)
{
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = fm_effect_20_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(65);
	pitch = 0x1700u;
	CHANNEL(channel)->fm_effect_20.pitch = 0x1700u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(39);
	CHANNEL(channel)->count = 0x30u;
	handler = fm_effect_20_pitch_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The fall: 1 1/2 semitones lower each pass for the 48 passes; then 64 passes of fm_effect_20_pitch_2. */
void fm_effect_20_pitch(uint16_t channel)
{
	uint32_t zero = 0;
	uint16_t handler = 0, step = 0;

	z80_block(27);
	step = 0xFFA0u;
	zero = fm_effect_20_move_pitch(step, channel);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(39);
	CHANNEL(channel)->count = 0x40u;
	handler = fm_effect_20_pitch_2_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The climb: a semitone higher each pass for the 64 passes; then stop_channel. */
void fm_effect_20_pitch_2(uint16_t channel)
{
	uint32_t zero = 0;
	uint16_t step = 0;

	z80_block(27);
	step = 0x40u;
	zero = fm_effect_20_move_pitch(step, channel);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Adds the step to the pitch and sets it, 8 semitones higher in turn every 8 passes; counts the count
   down and tells whether it ran out. */
uint32_t fm_effect_20_move_pitch(uint16_t step, uint16_t channel)
{
	uint32_t zero = 0;
	uint16_t pitch = 0;
	uint8_t t1 = 0;

	z80_block(117);
	pitch = CHANNEL(channel)->fm_effect_20.pitch + step;
	CHANNEL(channel)->fm_effect_20.pitch = pitch;
	if ((CHANNEL(channel)->count >> 3) & 1u)
	{
		z80_block(21);
		pitch += 0x200u;
	}
	z80_block(17);
	set_pitch(pitch, channel);
	z80_block(33);
	t1 = CHANNEL(channel)->count - 1u;
	zero = t1 == 0u;
	CHANNEL(channel)->count = t1;
	return zero;
}

/* Loads fm_effect_21_patch and keys on pitch 600 for 384 passes (fm_effect_21_end). */
void fm_effect_21(uint16_t channel)
{
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = fm_effect_21_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(27);
	pitch = 0x600u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(68);
	CHANNEL(channel)->fm_effect_21.passes = 0x180u;
	handler = fm_effect_21_end_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Counts down the 384 passes, then stop_channel. */
void fm_effect_21_end(uint16_t channel)
{
	uint8_t passes_high = 0, passes_low = 0;
	uint16_t t1 = 0;

	z80_block(95);
	t1 = CHANNEL(channel)->fm_effect_21.passes - 1u;
	passes_high = (uint8_t)(t1 >> 8);
	passes_low = (uint8_t)t1;
	AT8(CHANNEL(channel)->fm_effect_21.passes, 1) = passes_high;
	AS8(CHANNEL(channel)->fm_effect_21.passes) = passes_low;
	if ((passes_low | passes_high) != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Loads fm_effect_22_patch and keys on pitch 1500: 10 falls of 24 passes (fm_effect_22_slide). */
void fm_effect_22(uint16_t channel)
{
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = fm_effect_22_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(65);
	pitch = 0x1500u;
	CHANNEL(channel)->pitch = 0x1500u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(58);
	CHANNEL(channel)->fm_effect_22.timer = 0x18u;
	CHANNEL(channel)->fm_effect_22.count = 0xAu;
	handler = fm_effect_22_slide_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The pitch 4 3/4 semitones lower each pass; every 24 passes back to pitch 1500, 10 times; then
   stop_channel. */
void fm_effect_22_slide(uint16_t channel)
{
	uint16_t pitch = 0;
	uint8_t timer = 0, count = 0;

	z80_block(33);
	timer = CHANNEL(channel)->fm_effect_22.timer;
	CHANNEL(channel)->fm_effect_22.timer = timer - 1u;
	if (timer != 1u)
	{
		z80_block(67);
		pitch = CHANNEL(channel)->pitch - 0x130u;
		z80_block(48);
		CHANNEL(channel)->pitch = pitch;
		set_pitch(pitch, channel);
		return;
	}
	z80_block(52);
	CHANNEL(channel)->fm_effect_22.timer = 0x18u;
	count = CHANNEL(channel)->fm_effect_22.count;
	CHANNEL(channel)->fm_effect_22.count = count - 1u;
	if (count == 1u)
	{
		stop_channel(channel);
		return;
	}
	z80_block(20);
	pitch = 0x1500u;
	z80_block(48);
	CHANNEL(channel)->pitch = pitch;
	set_pitch(pitch, channel);
}

/* Loads fm_effect_23_patch: a falling trill three times (fm_effect_23_retrigger). */
void fm_effect_23(uint16_t channel)
{
	uint16_t patch = 0;

	z80_block(27);
	patch = fm_effect_23_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(19);
	CHANNEL(channel)->count = 3u;
	fm_effect_23_retrigger(channel);
}

/* Sets pitch 1400 and keys on, for 128 passes of fm_effect_23_slide. */
void fm_effect_23_retrigger(uint16_t channel)
{
	uint16_t handler = 0, pitch = 0;

	z80_block(65);
	pitch = 0x1400u;
	CHANNEL(channel)->pitch = fm_effect_0e_patch_ADDRESS + 0x14u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(39);
	CHANNEL(channel)->timer = 0x80u;
	handler = fm_effect_23_slide_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The pitch 5/16 of a semitone lower each pass (40 semitones in the 128 passes), played 4 semitones
   higher in turn every 2 passes; then the next time (fm_effect_23_retrigger), and stop_channel after the
   third. */
void fm_effect_23_slide(uint16_t channel)
{
	uint16_t pitch = 0;
	uint8_t timer = 0, count = 0;

	z80_block(127);
	pitch = CHANNEL(channel)->pitch - 0x14u;
	CHANNEL(channel)->pitch = pitch;
	if ((CHANNEL(channel)->timer >> 1) & 1u)
	{
		z80_block(21);
		pitch += 0x100u;
	}
	z80_block(17);
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
		fm_effect_23_retrigger(channel);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Loads fm_effect_24_patch and keys on pitch B00: 8 notes of 32 passes, each 5 semitones higher
   (fm_effect_24_retrigger). */
void fm_effect_24(uint16_t channel)
{
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = fm_effect_24_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(65);
	pitch = 0xB00u;
	CHANNEL(channel)->pitch = 0xB00u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(58);
	CHANNEL(channel)->fm_effect_24.timer = 0x20u;
	CHANNEL(channel)->fm_effect_24.count = 8u;
	handler = fm_effect_24_retrigger_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Every 32 passes, key off and the next note 5 semitones higher, keyed on; after the eighth, its release
   for 256 passes (fm_effect_24_hold). */
void fm_effect_24_retrigger(uint16_t channel)
{
	uint16_t handler = 0, pitch = 0;
	uint8_t timer = 0, count = 0;

	z80_block(28);
	timer = CHANNEL(channel)->fm_effect_24.timer;
	CHANNEL(channel)->fm_effect_24.timer = timer - 1u;
	if (timer != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(17);
	key_off(channel);
	z80_block(33);
	count = CHANNEL(channel)->fm_effect_24.count;
	CHANNEL(channel)->fm_effect_24.count = count - 1u;
	if (count == 1u)
	{
		z80_block(39);
		CHANNEL(channel)->fm_effect_24.timer = 0u;
		handler = fm_effect_24_hold_ADDRESS;
		set_channel_handler(handler, channel);
		return;
	}
	z80_block(133);
	CHANNEL(channel)->fm_effect_24.timer = 0x20u;
	pitch = CHANNEL(channel)->pitch + 0x140u;
	CHANNEL(channel)->pitch = pitch;
	set_pitch(pitch, channel);
	z80_block(10);
	key_on(channel);
}

/* Counts down the 256 passes, then stop_channel. */
void fm_effect_24_hold(uint16_t channel)
{
	uint8_t timer = 0;

	z80_block(28);
	timer = CHANNEL(channel)->fm_effect_24.timer;
	CHANNEL(channel)->fm_effect_24.timer = timer - 1u;
	if (timer != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Effect 24's notes 8 passes later and an eighth of a semitone higher (its own copy of the chain, and of
   the patch). */
void fm_effect_25(uint16_t channel)
{
	uint16_t handler = 0;

	z80_block(39);
	CHANNEL(channel)->fm_effect_25.timer = 8u;
	handler = fm_effect_25_note_ADDRESS;
	set_channel_handler(handler, channel);
}

/* After the 8 passes, loads fm_effect_25_patch and keys on pitch B08: 8 notes of 32 passes, each 5
   semitones higher (fm_effect_25_retrigger). */
void fm_effect_25_note(uint16_t channel)
{
	uint16_t handler = 0, patch = 0, pitch = 0;
	uint8_t timer = 0;

	z80_block(28);
	timer = CHANNEL(channel)->fm_effect_25.timer;
	CHANNEL(channel)->fm_effect_25.timer = timer - 1u;
	if (timer != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(27);
	patch = fm_effect_25_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(65);
	pitch = 0xB08u;
	CHANNEL(channel)->pitch = 0xB08u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(58);
	CHANNEL(channel)->fm_effect_25.timer = 0x20u;
	CHANNEL(channel)->fm_effect_25.count = 8u;
	handler = fm_effect_25_retrigger_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Every 32 passes, key off and the next note 5 semitones higher, keyed on; after the eighth, its release
   for 256 passes (fm_effect_25_hold). */
void fm_effect_25_retrigger(uint16_t channel)
{
	uint16_t handler = 0, pitch = 0;
	uint8_t timer = 0, count = 0;

	z80_block(28);
	timer = CHANNEL(channel)->fm_effect_25.timer;
	CHANNEL(channel)->fm_effect_25.timer = timer - 1u;
	if (timer != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(17);
	key_off(channel);
	z80_block(33);
	count = CHANNEL(channel)->fm_effect_25.count;
	CHANNEL(channel)->fm_effect_25.count = count - 1u;
	if (count == 1u)
	{
		z80_block(39);
		CHANNEL(channel)->fm_effect_25.timer = 0u;
		handler = fm_effect_25_hold_ADDRESS;
		set_channel_handler(handler, channel);
		return;
	}
	z80_block(133);
	CHANNEL(channel)->fm_effect_25.timer = 0x20u;
	pitch = CHANNEL(channel)->pitch + 0x140u;
	CHANNEL(channel)->pitch = pitch;
	set_pitch(pitch, channel);
	z80_block(10);
	key_on(channel);
}

/* Counts down the 256 passes, then stop_channel. */
void fm_effect_25_hold(uint16_t channel)
{
	uint8_t timer = 0;

	z80_block(28);
	timer = CHANNEL(channel)->fm_effect_25.timer;
	CHANNEL(channel)->fm_effect_25.timer = timer - 1u;
	if (timer != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Loads fm_effect_26_patch and keys on pitch 1200: 3 rounds of two rises (fm_effect_26_transpose). */
void fm_effect_26(uint16_t channel)
{
	uint16_t patch = 0, pitch = 0;

	z80_block(27);
	patch = fm_effect_26_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(65);
	pitch = 0x1200u;
	CHANNEL(channel)->pitch = 0x1200u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(19);
	CHANNEL(channel)->count = 3u;
	fm_effect_26_transpose(channel);
}

/* Starts a round: the pitch 44 semitones lower, for 48 passes of fm_effect_26_slide. */
void fm_effect_26_transpose(uint16_t channel)
{
	uint16_t handler = 0, pitch = 0;

	z80_block(136);
	CHANNEL(channel)->timer = 0x30u;
	pitch = CHANNEL(channel)->pitch - 0xB00u;
	CHANNEL(channel)->pitch = pitch;
	handler = fm_effect_26_slide_ADDRESS;
	set_channel_handler(handler, channel);
}

/* A rise of 7/16 of a semitone a pass (fm_effect_26_move_pitch) for the 48 passes; then 4 semitones up
   and the second rise (fm_effect_26_pitch). */
void fm_effect_26_slide(uint16_t channel)
{
	uint32_t zero = 0;
	uint16_t handler = 0, pitch = 0;

	z80_block(17);
	zero = fm_effect_26_move_pitch(channel);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(136);
	CHANNEL(channel)->timer = 0x30u;
	pitch = CHANNEL(channel)->pitch + 0x100u;
	CHANNEL(channel)->pitch = pitch;
	handler = fm_effect_26_pitch_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The second rise, 48 passes more; after 3 rounds, each 2 semitones above the last, stop_channel. */
void fm_effect_26_pitch(uint16_t channel)
{
	uint32_t zero = 0;
	uint8_t count = 0;

	z80_block(17);
	zero = fm_effect_26_move_pitch(channel);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(33);
	count = CHANNEL(channel)->count;
	CHANNEL(channel)->count = count - 1u;
	if (count != 1u)
	{
		fm_effect_26_transpose(channel);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* The pitch 7/16 of a semitone higher, set; counts the timer down and tells whether it ran out. */
uint32_t fm_effect_26_move_pitch(uint16_t channel)
{
	uint32_t zero = 0;
	uint16_t pitch = 0;
	uint8_t t1 = 0;

	z80_block(114);
	pitch = CHANNEL(channel)->pitch + 0x1Cu;
	CHANNEL(channel)->pitch = pitch;
	set_pitch(pitch, channel);
	z80_block(33);
	t1 = CHANNEL(channel)->timer - 1u;
	zero = t1 == 0u;
	CHANNEL(channel)->timer = t1;
	return zero;
}

/* Loads fm_effect_27_patch and keys on pitch 17D8: 6 notes of 48 passes, each a semitone lower
   (fm_effect_27_retrigger). */
void fm_effect_27(uint16_t channel)
{
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = fm_effect_27_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(103);
	CHANNEL(channel)->count = 6u;
	CHANNEL(channel)->timer = 0x30u;
	pitch = 0x17D8u;
	CHANNEL(channel)->pitch = 0x17D8u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(20);
	handler = fm_effect_27_retrigger_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Every 48 passes, key off and the next note a semitone lower, keyed on; after the sixth, its release
   for 128 passes (fm_effect_27_hold). */
void fm_effect_27_retrigger(uint16_t channel)
{
	uint16_t handler = 0, pitch = 0;
	uint8_t timer = 0, count = 0;

	z80_block(28);
	timer = CHANNEL(channel)->timer;
	CHANNEL(channel)->timer = timer - 1u;
	if (timer != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(36);
	CHANNEL(channel)->timer = 0x30u;
	key_off(channel);
	z80_block(33);
	count = CHANNEL(channel)->count;
	CHANNEL(channel)->count = count - 1u;
	if (count == 1u)
	{
		z80_block(39);
		CHANNEL(channel)->count = 0x80u;
		handler = fm_effect_27_hold_ADDRESS;
		set_channel_handler(handler, channel);
		return;
	}
	z80_block(114);
	pitch = CHANNEL(channel)->pitch - 0x40u;
	CHANNEL(channel)->pitch = pitch;
	set_pitch(pitch, channel);
	z80_block(10);
	key_on(channel);
}

/* Counts down the 128 passes, then stop_channel. */
void fm_effect_27_hold(uint16_t channel)
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

/* Loads fm_effect_28_patch and keys on pitch 600, for 16 rounds of 32 passes (fm_effect_28_slide). */
void fm_effect_28(uint16_t channel)
{
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = fm_effect_28_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(65);
	pitch = 0x600u;
	CHANNEL(channel)->pitch = 0x600u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(58);
	CHANNEL(channel)->count = 0x10u;
	CHANNEL(channel)->timer = 0x20u;
	handler = fm_effect_28_slide_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The pitch half a semitone higher each pass, played 8 semitones higher in turn every 16 passes; after
   each 32 passes it drops 15 5/8 semitones, so that each round starts 3/8 of a semitone above the last;
   after 16 rounds stop_channel. */
void fm_effect_28_slide(uint16_t channel)
{
	uint16_t pitch = 0;
	uint8_t timer = 0, count = 0;

	z80_block(127);
	pitch = CHANNEL(channel)->pitch + 0x20u;
	CHANNEL(channel)->pitch = pitch;
	if ((CHANNEL(channel)->timer >> 4) & 1u)
	{
		z80_block(21);
		pitch += 0x200u;
	}
	z80_block(17);
	set_pitch(pitch, channel);
	z80_block(28);
	timer = CHANNEL(channel)->timer;
	CHANNEL(channel)->timer = timer - 1u;
	if (timer != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(144);
	CHANNEL(channel)->timer = 0x20u;
	pitch = CHANNEL(channel)->pitch - 0x3E8u;
	CHANNEL(channel)->pitch = pitch;
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

/* Loads fm_effect_29_patch and keys on pitch 1400: a fall, then 3 rises (fm_effect_29_pitch). */
void fm_effect_29(uint16_t channel)
{
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = fm_effect_29_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(65);
	pitch = 0x1400u;
	CHANNEL(channel)->pitch = fm_effect_0e_patch_ADDRESS + 0x14u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(39);
	CHANNEL(channel)->timer = 0x30u;
	handler = fm_effect_29_pitch_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The fall: 1 1/8 semitones lower each pass for 48 passes; then the 3 rises (fm_effect_29_setup). */
void fm_effect_29_pitch(uint16_t channel)
{
	uint32_t zero = 0;
	uint16_t step = 0;

	z80_block(27);
	step = 0xFFB8u;
	zero = fm_effect_29_move_pitch(step, channel);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(19);
	CHANNEL(channel)->count = 3u;
	fm_effect_29_setup(channel);
}

/* Starts a rise of 64 passes (fm_effect_29_slide). */
void fm_effect_29_setup(uint16_t channel)
{
	uint16_t handler = 0;

	z80_block(39);
	CHANNEL(channel)->timer = 0x40u;
	handler = fm_effect_29_slide_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Half a semitone higher each pass for the 64 passes; then 24 semitones lower and the next rise
   (fm_effect_29_setup), each 8 semitones above the last; after the third stop_channel. */
void fm_effect_29_slide(uint16_t channel)
{
	uint32_t zero = 0;
	uint16_t pitch = 0, step = 0;
	uint8_t count = 0;

	z80_block(27);
	step = 0x20u;
	zero = fm_effect_29_move_pitch(step, channel);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(130);
	pitch = CHANNEL(channel)->pitch - 0x600u;
	CHANNEL(channel)->pitch = pitch;
	count = CHANNEL(channel)->count;
	CHANNEL(channel)->count = count - 1u;
	if (count != 1u)
	{
		fm_effect_29_setup(channel);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Adds the step to the pitch and sets it; counts the timer down and tells whether it ran out. */
uint32_t fm_effect_29_move_pitch(uint16_t step, uint16_t channel)
{
	uint32_t zero = 0;
	uint16_t pitch = 0;
	uint8_t t1 = 0;

	z80_block(104);
	pitch = CHANNEL(channel)->pitch + step;
	CHANNEL(channel)->pitch = pitch;
	set_pitch(pitch, channel);
	z80_block(33);
	t1 = CHANNEL(channel)->timer - 1u;
	zero = t1 == 0u;
	CHANNEL(channel)->timer = t1;
	return zero;
}

/* Effect 2A's notes after 48 passes. */
void fm_effect_2b(uint16_t channel)
{
	uint16_t handler = 0;

	z80_block(39);
	CHANNEL(channel)->count = 0x30u;
	handler = fm_effect_2b_delay_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Counts down the 48 passes, then starts effect 2A (fm_effect_2a). */
void fm_effect_2b_delay(uint16_t channel)
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
	fm_effect_2a(channel);
}

/* Loads fm_effect_2a_patch and keys on pitch 1000: six notes of 24 passes, 6 semitones up and 2 down in
   turn (fm_effect_2a_retrigger), the last one held; effect 0C's figure, climbing. */
void fm_effect_2a(uint16_t channel)
{
	uint16_t handler = 0, patch = 0, pitch = 0;

	z80_block(27);
	patch = fm_effect_2a_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(65);
	pitch = 0x1000u;
	CHANNEL(channel)->pitch = 0x1000u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(58);
	CHANNEL(channel)->count = 3u;
	CHANNEL(channel)->timer = 0x18u;
	handler = fm_effect_2a_retrigger_ADDRESS;
	set_channel_handler(handler, channel);
}

/* After the 24 passes, the note 6 semitones higher (fm_effect_2a_move_pitch); then
   fm_effect_2a_retrigger_2. */
void fm_effect_2a_retrigger(uint16_t channel)
{
	uint16_t handler = 0, step = 0;
	uint8_t timer = 0;

	z80_block(28);
	timer = CHANNEL(channel)->timer;
	CHANNEL(channel)->timer = timer - 1u;
	if (timer != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(27);
	step = 0x180u;
	fm_effect_2a_move_pitch(step, channel);
	z80_block(20);
	handler = fm_effect_2a_retrigger_2_ADDRESS;
	set_channel_handler(handler, channel);
}

/* After the 24 passes, the note 2 semitones lower and fm_effect_2a_retrigger again; the third time the
   note instead goes on 256 passes more (fm_effect_2a_hold). */
void fm_effect_2a_retrigger_2(uint16_t channel)
{
	uint16_t handler = 0, step = 0;
	uint8_t timer = 0, count = 0;

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
	if (count == 1u)
	{
		z80_block(39);
		CHANNEL(channel)->timer = 0u;
		handler = fm_effect_2a_hold_ADDRESS;
		set_channel_handler(handler, channel);
		return;
	}
	z80_block(27);
	step = 0xFF80u;
	fm_effect_2a_move_pitch(step, channel);
	z80_block(20);
	handler = fm_effect_2a_retrigger_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Counts down the 256 passes, then stop_channel. */
void fm_effect_2a_hold(uint16_t channel)
{
	uint8_t timer = 0;

	z80_block(28);
	timer = CHANNEL(channel)->timer;
	CHANNEL(channel)->timer = timer - 1u;
	if (timer != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Keys off, moves the pitch by the step, sets it and keys on again, for 24 passes. */
void fm_effect_2a_move_pitch(uint16_t step, uint16_t channel)
{
	uint16_t pitch = 0;

	z80_block(17);
	key_off(channel);
	z80_block(104);
	pitch = CHANNEL(channel)->pitch + step;
	CHANNEL(channel)->pitch = pitch;
	set_pitch(pitch, channel);
	z80_block(29);
	CHANNEL(channel)->timer = 0x18u;
	key_on(channel);
}

/* Loads fm_effect_2c_patch: 5 rounds of a five-note figure (fm_effect_2c_retrigger). */
void fm_effect_2c(uint16_t channel)
{
	uint16_t patch = 0;

	z80_block(27);
	patch = fm_effect_2c_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(19);
	CHANNEL(channel)->rounds = 5u;
	fm_effect_2c_retrigger(channel);
}

/* Starts a round: pitch C00 keyed on, 48 passes a note (fm_effect_2c_step_up). */
void fm_effect_2c_retrigger(uint16_t channel)
{
	uint16_t handler = 0, pitch = 0;

	z80_block(65);
	pitch = 0xC00u;
	CHANNEL(channel)->pitch = 0xC00u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(58);
	CHANNEL(channel)->count = 4u;
	CHANNEL(channel)->timer = 0x30u;
	handler = fm_effect_2c_step_up_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Plays the note (fm_effect_2c_play); every 48 passes the next, 3 semitones higher
   (fm_effect_2c_transpose), three times; then the round's last note (fm_effect_2c_step_down). */
void fm_effect_2c_step_up(uint16_t channel)
{
	uint16_t handler = 0, step = 0;
	uint8_t timer = 0, count = 0;

	z80_block(33);
	timer = CHANNEL(channel)->timer;
	CHANNEL(channel)->timer = timer - 1u;
	if (timer != 1u)
	{
		fm_effect_2c_play(channel);
		return;
	}
	z80_block(62);
	CHANNEL(channel)->timer = 0x30u;
	count = CHANNEL(channel)->count;
	CHANNEL(channel)->count = count - 1u;
	step = 0xC0u;
	if (count != 1u)
	{
		fm_effect_2c_transpose(step, channel);
		return;
	}
	z80_block(58);
	CHANNEL(channel)->count = 2u;
	CHANNEL(channel)->timer = 1u;
	handler = fm_effect_2c_step_down_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The round's last note, 4 semitones lower, for 48 passes; then the next round (fm_effect_2c_retrigger),
   and stop_channel after the fifth. */
void fm_effect_2c_step_down(uint16_t channel)
{
	uint16_t step = 0;
	uint8_t timer = 0, count = 0, rounds = 0;

	z80_block(33);
	timer = CHANNEL(channel)->timer;
	CHANNEL(channel)->timer = timer - 1u;
	if (timer != 1u)
	{
		fm_effect_2c_play(channel);
		return;
	}
	z80_block(62);
	CHANNEL(channel)->timer = 0x30u;
	count = CHANNEL(channel)->count;
	CHANNEL(channel)->count = count - 1u;
	step = 0xFF00u;
	if (count != 1u)
	{
		fm_effect_2c_transpose(step, channel);
		return;
	}
	z80_block(33);
	rounds = CHANNEL(channel)->rounds;
	CHANNEL(channel)->rounds = rounds - 1u;
	if (rounds != 1u)
	{
		fm_effect_2c_retrigger(channel);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Moves the pitch by the step and sets it (fm_effect_2c_set_pitch). */
void fm_effect_2c_transpose(uint16_t step, uint16_t channel)
{
	uint16_t pitch = 0;

	z80_block(97);
	pitch = CHANNEL(channel)->pitch + step;
	CHANNEL(channel)->pitch = pitch;
	fm_effect_2c_set_pitch(pitch, channel);
}

/* Sets the pitch (fm_effect_2c_set_pitch). */
void fm_effect_2c_play(uint16_t channel)
{
	uint16_t pitch = 0;

	z80_block(38);
	pitch = CHANNEL(channel)->pitch;
	fm_effect_2c_set_pitch(pitch, channel);
}

/* Sets the pitch it is given, 28 semitones higher while bit 5 of the timer is set: a high blip over the
   first 17 passes of each note. */
void fm_effect_2c_set_pitch(uint16_t pitch, uint16_t channel)
{
	z80_block(30);
	if ((CHANNEL(channel)->timer >> 5) & 1u)
	{
		z80_block(21);
		pitch += 0x700u;
	}
	z80_block(10);
	set_pitch(pitch, channel);
}

/* Effect 2C's figure 32 passes later, a 16th of a semitone higher, quieter and on the left output only
   (fm_effect_2d_patch): its own copy of the chain. */
void fm_effect_2d(uint16_t channel)
{
	uint16_t handler = 0;

	z80_block(39);
	CHANNEL(channel)->count = 0x20u;
	handler = fm_effect_2d_note_ADDRESS;
	set_channel_handler(handler, channel);
}

/* After the 32 passes, loads fm_effect_2d_patch: 5 rounds of the figure (fm_effect_2d_retrigger). */
void fm_effect_2d_note(uint16_t channel)
{
	uint16_t patch = 0;
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
	patch = fm_effect_2d_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(19);
	CHANNEL(channel)->rounds = 5u;
	fm_effect_2d_retrigger(channel);
}

/* Starts a round: pitch C04 keyed on, 48 passes a note (fm_effect_2d_step_up). */
void fm_effect_2d_retrigger(uint16_t channel)
{
	uint16_t handler = 0, pitch = 0;

	z80_block(65);
	pitch = 0xC04u;
	CHANNEL(channel)->pitch = 0xC04u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(58);
	CHANNEL(channel)->count = 4u;
	CHANNEL(channel)->timer = 0x30u;
	handler = fm_effect_2d_step_up_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Plays the note (fm_effect_2d_play); every 48 passes the next, 3 semitones higher
   (fm_effect_2d_transpose), three times; then the round's last note (fm_effect_2d_step_down). */
void fm_effect_2d_step_up(uint16_t channel)
{
	uint16_t handler = 0, step = 0;
	uint8_t timer = 0, count = 0;

	z80_block(33);
	timer = CHANNEL(channel)->timer;
	CHANNEL(channel)->timer = timer - 1u;
	if (timer != 1u)
	{
		fm_effect_2d_play(channel);
		return;
	}
	z80_block(62);
	CHANNEL(channel)->timer = 0x30u;
	count = CHANNEL(channel)->count;
	CHANNEL(channel)->count = count - 1u;
	step = 0xC0u;
	if (count != 1u)
	{
		fm_effect_2d_transpose(step, channel);
		return;
	}
	z80_block(58);
	CHANNEL(channel)->count = 2u;
	CHANNEL(channel)->timer = 1u;
	handler = fm_effect_2d_step_down_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The round's last note, 4 semitones lower, for 48 passes; then the next round (fm_effect_2d_retrigger),
   and stop_channel after the fifth. */
void fm_effect_2d_step_down(uint16_t channel)
{
	uint16_t step = 0;
	uint8_t timer = 0, count = 0, rounds = 0;

	z80_block(33);
	timer = CHANNEL(channel)->timer;
	CHANNEL(channel)->timer = timer - 1u;
	if (timer != 1u)
	{
		fm_effect_2d_play(channel);
		return;
	}
	z80_block(62);
	CHANNEL(channel)->timer = 0x30u;
	count = CHANNEL(channel)->count;
	CHANNEL(channel)->count = count - 1u;
	step = 0xFF00u;
	if (count != 1u)
	{
		fm_effect_2d_transpose(step, channel);
		return;
	}
	z80_block(33);
	rounds = CHANNEL(channel)->rounds;
	CHANNEL(channel)->rounds = rounds - 1u;
	if (rounds != 1u)
	{
		fm_effect_2d_retrigger(channel);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Moves the pitch by the step and sets it (fm_effect_2d_set_pitch). */
void fm_effect_2d_transpose(uint16_t step, uint16_t channel)
{
	uint16_t pitch = 0;

	z80_block(97);
	pitch = CHANNEL(channel)->pitch + step;
	CHANNEL(channel)->pitch = pitch;
	fm_effect_2d_set_pitch(pitch, channel);
}

/* Sets the pitch (fm_effect_2d_set_pitch). */
void fm_effect_2d_play(uint16_t channel)
{
	uint16_t pitch = 0;

	z80_block(38);
	pitch = CHANNEL(channel)->pitch;
	fm_effect_2d_set_pitch(pitch, channel);
}

/* Sets the pitch it is given, 28 semitones higher while bit 5 of the timer is set: a high blip over the
   first 17 passes of each note. */
void fm_effect_2d_set_pitch(uint16_t pitch, uint16_t channel)
{
	z80_block(30);
	if ((CHANNEL(channel)->timer >> 5) & 1u)
	{
		z80_block(21);
		pitch += 0x700u;
	}
	z80_block(10);
	set_pitch(pitch, channel);
}

/* Effect 2C's figure 64 passes later, an eighth of a semitone higher, quieter and on the right output
   only (fm_effect_2e_patch): its own copy of the chain. */
void fm_effect_2e(uint16_t channel)
{
	uint16_t handler = 0;

	z80_block(39);
	CHANNEL(channel)->count = 0x40u;
	handler = fm_effect_2e_note_ADDRESS;
	set_channel_handler(handler, channel);
}

/* After the 64 passes, loads fm_effect_2e_patch: 5 rounds of the figure (fm_effect_2e_retrigger). */
void fm_effect_2e_note(uint16_t channel)
{
	uint16_t patch = 0;
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
	patch = fm_effect_2e_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(19);
	CHANNEL(channel)->rounds = 5u;
	fm_effect_2e_retrigger(channel);
}

/* Starts a round: pitch C08 keyed on, 48 passes a note (fm_effect_2e_step_up). */
void fm_effect_2e_retrigger(uint16_t channel)
{
	uint16_t handler = 0, pitch = 0;

	z80_block(65);
	pitch = 0xC08u;
	CHANNEL(channel)->pitch = 0xC08u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(58);
	CHANNEL(channel)->count = 4u;
	CHANNEL(channel)->timer = 0x30u;
	handler = fm_effect_2e_step_up_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Plays the note (fm_effect_2e_play); every 48 passes the next, 3 semitones higher
   (fm_effect_2e_transpose), three times; then the round's last note (fm_effect_2e_step_down). */
void fm_effect_2e_step_up(uint16_t channel)
{
	uint16_t handler = 0, step = 0;
	uint8_t timer = 0, count = 0;

	z80_block(33);
	timer = CHANNEL(channel)->timer;
	CHANNEL(channel)->timer = timer - 1u;
	if (timer != 1u)
	{
		fm_effect_2e_play(channel);
		return;
	}
	z80_block(62);
	CHANNEL(channel)->timer = 0x30u;
	count = CHANNEL(channel)->count;
	CHANNEL(channel)->count = count - 1u;
	step = 0xC0u;
	if (count != 1u)
	{
		fm_effect_2e_transpose(step, channel);
		return;
	}
	z80_block(58);
	CHANNEL(channel)->count = 2u;
	CHANNEL(channel)->timer = 1u;
	handler = fm_effect_2e_step_down_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The round's last note, 4 semitones lower, for 48 passes; then the next round (fm_effect_2e_retrigger),
   and stop_channel after the fifth. */
void fm_effect_2e_step_down(uint16_t channel)
{
	uint16_t step = 0;
	uint8_t timer = 0, count = 0, rounds = 0;

	z80_block(33);
	timer = CHANNEL(channel)->timer;
	CHANNEL(channel)->timer = timer - 1u;
	if (timer != 1u)
	{
		fm_effect_2e_play(channel);
		return;
	}
	z80_block(62);
	CHANNEL(channel)->timer = 0x30u;
	count = CHANNEL(channel)->count;
	CHANNEL(channel)->count = count - 1u;
	step = 0xFF00u;
	if (count != 1u)
	{
		fm_effect_2e_transpose(step, channel);
		return;
	}
	z80_block(33);
	rounds = CHANNEL(channel)->rounds;
	CHANNEL(channel)->rounds = rounds - 1u;
	if (rounds != 1u)
	{
		fm_effect_2e_retrigger(channel);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Moves the pitch by the step and sets it (fm_effect_2e_set_pitch). */
void fm_effect_2e_transpose(uint16_t step, uint16_t channel)
{
	uint16_t pitch = 0;

	z80_block(97);
	pitch = CHANNEL(channel)->pitch + step;
	CHANNEL(channel)->pitch = pitch;
	fm_effect_2e_set_pitch(pitch, channel);
}

/* Sets the pitch (fm_effect_2e_set_pitch). */
void fm_effect_2e_play(uint16_t channel)
{
	uint16_t pitch = 0;

	z80_block(38);
	pitch = CHANNEL(channel)->pitch;
	fm_effect_2e_set_pitch(pitch, channel);
}

/* Sets the pitch it is given, 28 semitones higher while bit 5 of the timer is set: a high blip over the
   first 17 passes of each note. */
void fm_effect_2e_set_pitch(uint16_t pitch, uint16_t channel)
{
	z80_block(30);
	if ((CHANNEL(channel)->timer >> 5) & 1u)
	{
		z80_block(21);
		pitch += 0x700u;
	}
	z80_block(10);
	set_pitch(pitch, channel);
}

/* Loads fm_effect_2f_patch: a falling note four times (fm_effect_2f_retrigger), at the volume
   start_sound leaves (0) and then at attenuations 16, 21 and 2C; effect 19's figure from pitch 1400,
   falling slower. */
void fm_effect_2f(uint16_t channel)
{
	uint16_t patch = 0;

	z80_block(27);
	patch = fm_effect_2f_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(38);
	CHANNEL(channel)->count = 4u;
	CHANNEL(channel)->fm_effect_2f.attenuation = 0xBu;
	fm_effect_2f_retrigger(channel);
}

/* Sets pitch 1400 and keys on, for 64 passes of fm_effect_2f_slide. */
void fm_effect_2f_retrigger(uint16_t channel)
{
	uint16_t handler = 0, pitch = 0;

	z80_block(65);
	pitch = 0x1400u;
	CHANNEL(channel)->pitch = fm_effect_0e_patch_ADDRESS + 0x14u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(39);
	CHANNEL(channel)->timer = 0x40u;
	handler = fm_effect_2f_slide_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The pitch 3/16 of a semitone lower each pass (an octave in the 64 passes), played an octave higher in
   turn every 16 passes; then 11 quieter (set_volume) and the next time (fm_effect_2f_retrigger), and
   stop_channel after the fourth. */
void fm_effect_2f_slide(uint16_t channel)
{
	uint8_t volume = 0;
	uint16_t pitch = 0;
	uint8_t timer = 0, count = 0;

	z80_block(127);
	pitch = CHANNEL(channel)->pitch - 0xCu;
	CHANNEL(channel)->pitch = pitch;
	if ((CHANNEL(channel)->timer >> 4) & 1u)
	{
		z80_block(21);
		pitch += 0x300u;
	}
	z80_block(17);
	set_pitch(pitch, channel);
	z80_block(28);
	timer = CHANNEL(channel)->timer;
	CHANNEL(channel)->timer = timer - 1u;
	if (timer != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(62);
	volume = CHANNEL(channel)->fm_effect_2f.attenuation + 0xBu;
	CHANNEL(channel)->fm_effect_2f.attenuation = volume;
	set_volume(channel, volume);
	z80_block(33);
	count = CHANNEL(channel)->count;
	CHANNEL(channel)->count = count - 1u;
	if (count != 1u)
	{
		fm_effect_2f_retrigger(channel);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Effect 30's notes after 112 passes: 32 passes, then effect 31's 80. */
void fm_effect_32(uint16_t channel)
{
	uint16_t handler = 0;

	z80_block(39);
	CHANNEL(channel)->count = 0x20u;
	handler = fm_effect_32_delay_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Counts down the 32 passes, then starts effect 31 (fm_effect_31). */
void fm_effect_32_delay(uint16_t channel)
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
	fm_effect_31(channel);
}

/* Effect 30's notes after 80 passes. */
void fm_effect_31(uint16_t channel)
{
	uint16_t handler = 0;

	z80_block(39);
	CHANNEL(channel)->count = 0x50u;
	handler = fm_effect_31_delay_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Counts down the 80 passes, then starts effect 30 (fm_effect_30). */
void fm_effect_31_delay(uint16_t channel)
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
	fm_effect_30(channel);
}

/* Loads fm_effect_30_patch: 4 rounds of 8 notes, each a whole tone lower (fm_effect_30_retrigger). */
void fm_effect_30(uint16_t channel)
{
	uint16_t patch = 0;

	z80_block(27);
	patch = fm_effect_30_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(19);
	CHANNEL(channel)->rounds = 4u;
	fm_effect_30_retrigger(channel);
}

/* Starts a round: pitch 1200 keyed on, 8 notes of 48 passes (fm_effect_30_retrigger_2). */
void fm_effect_30_retrigger(uint16_t channel)
{
	uint16_t handler = 0, pitch = 0;

	z80_block(65);
	pitch = 0x1200u;
	CHANNEL(channel)->pitch = 0x1200u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(58);
	CHANNEL(channel)->count = 8u;
	CHANNEL(channel)->timer = 0x30u;
	handler = fm_effect_30_retrigger_2_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Every 48 passes, key off and the next note 2 semitones lower, keyed on; after the eighth the next
   round (fm_effect_30_retrigger), and stop_channel after the fourth. */
void fm_effect_30_retrigger_2(uint16_t channel)
{
	uint16_t pitch = 0;
	uint8_t timer = 0, count = 0, rounds = 0;

	z80_block(28);
	timer = CHANNEL(channel)->timer;
	CHANNEL(channel)->timer = timer - 1u;
	if (timer != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(52);
	CHANNEL(channel)->timer = 0x30u;
	count = CHANNEL(channel)->count;
	CHANNEL(channel)->count = count - 1u;
	if (count == 1u)
	{
		z80_block(33);
		rounds = CHANNEL(channel)->rounds;
		CHANNEL(channel)->rounds = rounds - 1u;
		if (rounds != 1u)
		{
			fm_effect_30_retrigger(channel);
			return;
		}
		z80_block(10);
		stop_channel(channel);
		return;
	}
	z80_block(17);
	key_off(channel);
	z80_block(114);
	pitch = CHANNEL(channel)->pitch - 0x80u;
	CHANNEL(channel)->pitch = pitch;
	set_pitch(pitch, channel);
	z80_block(10);
	key_on(channel);
}

/* Effect 30's notes an eighth of a semitone higher (its own copy of the chain, and of the patch). */
void fm_effect_33(uint16_t channel)
{
	uint16_t patch = 0;

	z80_block(27);
	patch = fm_effect_33_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(19);
	CHANNEL(channel)->rounds = 4u;
	fm_effect_33_retrigger(channel);
}

/* Starts a round: pitch 1208 keyed on, 8 notes of 48 passes (fm_effect_33_retrigger_2). */
void fm_effect_33_retrigger(uint16_t channel)
{
	uint16_t handler = 0, pitch = 0;

	z80_block(65);
	pitch = 0x1208u;
	CHANNEL(channel)->pitch = 0x1208u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(58);
	CHANNEL(channel)->count = 8u;
	CHANNEL(channel)->timer = 0x30u;
	handler = fm_effect_33_retrigger_2_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Every 48 passes, key off and the next note 2 semitones lower, keyed on; after the eighth the next
   round (fm_effect_33_retrigger), and stop_channel after the fourth. */
void fm_effect_33_retrigger_2(uint16_t channel)
{
	uint16_t pitch = 0;
	uint8_t timer = 0, count = 0, rounds = 0;

	z80_block(28);
	timer = CHANNEL(channel)->timer;
	CHANNEL(channel)->timer = timer - 1u;
	if (timer != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(52);
	CHANNEL(channel)->timer = 0x30u;
	count = CHANNEL(channel)->count;
	CHANNEL(channel)->count = count - 1u;
	if (count == 1u)
	{
		z80_block(33);
		rounds = CHANNEL(channel)->rounds;
		CHANNEL(channel)->rounds = rounds - 1u;
		if (rounds != 1u)
		{
			fm_effect_33_retrigger(channel);
			return;
		}
		z80_block(10);
		stop_channel(channel);
		return;
	}
	z80_block(17);
	key_off(channel);
	z80_block(114);
	pitch = CHANNEL(channel)->pitch - 0x80u;
	CHANNEL(channel)->pitch = pitch;
	set_pitch(pitch, channel);
	z80_block(10);
	key_on(channel);
}

/* Loads fm_effect_34_patch (the right output only): 2 rounds of 8 slow rises (fm_effect_34_setup). */
void fm_effect_34(uint16_t channel)
{
	uint16_t patch = 0;

	z80_block(27);
	patch = fm_effect_34_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(19);
	CHANNEL(channel)->rounds = 2u;
	fm_effect_34_setup(channel);
}

/* Starts a round of 8 rises (fm_effect_34_retrigger). */
void fm_effect_34_setup(uint16_t channel)
{
	z80_block(19);
	CHANNEL(channel)->count = 8u;
	fm_effect_34_retrigger(channel);
}

/* Sets pitch C00 and keys on, for 192 passes of fm_effect_34_slide. */
void fm_effect_34_retrigger(uint16_t channel)
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
	handler = fm_effect_34_slide_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The pitch a 32nd of a semitone higher each pass (6 semitones in the 192 passes); then the next rise
   (fm_effect_34_retrigger); after the eighth, key off and the next round (fm_effect_34_setup), and
   stop_channel after the second. */
void fm_effect_34_slide(uint16_t channel)
{
	uint16_t pitch = 0;
	uint8_t timer = 0, count = 0, rounds = 0;

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
		fm_effect_34_retrigger(channel);
		return;
	}
	z80_block(17);
	key_off(channel);
	z80_block(33);
	rounds = CHANNEL(channel)->rounds;
	CHANNEL(channel)->rounds = rounds - 1u;
	if (rounds != 1u)
	{
		fm_effect_34_setup(channel);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Effect 34's rises 32 passes later, on the left output only (fm_effect_35_patch): its own copy of the
   chain. */
void fm_effect_35(uint16_t channel)
{
	uint16_t handler = 0;

	z80_block(39);
	CHANNEL(channel)->count = 0x20u;
	handler = fm_effect_35_note_ADDRESS;
	set_channel_handler(handler, channel);
}

/* After the 32 passes, loads fm_effect_35_patch: 2 rounds of 8 slow rises (fm_effect_35_setup). */
void fm_effect_35_note(uint16_t channel)
{
	uint16_t patch = 0;
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
	patch = fm_effect_35_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(19);
	CHANNEL(channel)->rounds = 2u;
	fm_effect_35_setup(channel);
}

/* Starts a round of 8 rises (fm_effect_35_retrigger). */
void fm_effect_35_setup(uint16_t channel)
{
	z80_block(19);
	CHANNEL(channel)->count = 8u;
	fm_effect_35_retrigger(channel);
}

/* Sets pitch C00 and keys on, for 192 passes of fm_effect_35_slide. */
void fm_effect_35_retrigger(uint16_t channel)
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
	handler = fm_effect_35_slide_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The pitch a 32nd of a semitone higher each pass (6 semitones in the 192 passes); then the next rise
   (fm_effect_35_retrigger); after the eighth, key off and the next round (fm_effect_35_setup), and
   stop_channel after the second. */
void fm_effect_35_slide(uint16_t channel)
{
	uint16_t pitch = 0;
	uint8_t timer = 0, count = 0, rounds = 0;

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
		fm_effect_35_retrigger(channel);
		return;
	}
	z80_block(17);
	key_off(channel);
	z80_block(33);
	rounds = CHANNEL(channel)->rounds;
	CHANNEL(channel)->rounds = rounds - 1u;
	if (rounds != 1u)
	{
		fm_effect_35_setup(channel);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Loads fm_effect_36_patch: 24 slow rises from pitch 600 (fm_effect_36_retrigger). */
void fm_effect_36(uint16_t channel)
{
	uint16_t patch = 0;

	z80_block(27);
	patch = fm_effect_36_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(19);
	CHANNEL(channel)->rounds = 0x18u;
	fm_effect_36_retrigger(channel);
}

/* Sets pitch 600 and keys on, for 128 passes of fm_effect_36_slide. */
void fm_effect_36_retrigger(uint16_t channel)
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
	handler = fm_effect_36_slide_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The pitch a 32nd of a semitone higher each pass (4 semitones in the 128 passes); then the next rise
   (fm_effect_36_retrigger), and stop_channel after the 24th. */
void fm_effect_36_slide(uint16_t channel)
{
	uint16_t pitch = 0;
	uint8_t timer = 0, rounds = 0;

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
	rounds = CHANNEL(channel)->rounds;
	CHANNEL(channel)->rounds = rounds - 1u;
	if (rounds != 1u)
	{
		fm_effect_36_retrigger(channel);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Loads fm_effect_37_patch: 5 rounds of a rising chromatic scale (fm_effect_37_retrigger). */
void fm_effect_37(uint16_t channel)
{
	uint16_t patch = 0;

	z80_block(27);
	patch = fm_effect_37_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(19);
	CHANNEL(channel)->rounds = 5u;
	fm_effect_37_retrigger(channel);
}

/* Starts a round: pitch 1500 keyed on, 12 notes of 64 passes (fm_effect_37_slide). */
void fm_effect_37_retrigger(uint16_t channel)
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
	handler = fm_effect_37_slide_ADDRESS;
	set_channel_handler(handler, channel);
}

/* Every 64 passes the pitch a semitone higher, not keyed again; after the twelfth note the next round
   (fm_effect_37_retrigger), and stop_channel after the fifth. */
void fm_effect_37_slide(uint16_t channel)
{
	uint16_t pitch = 0;
	uint8_t timer = 0, count = 0, rounds = 0;

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
	if (count != 1u)
	{
		z80_block(107);
		pitch = CHANNEL(channel)->pitch + 0x40u;
		CHANNEL(channel)->pitch = pitch;
		set_pitch(pitch, channel);
		return;
	}
	z80_block(33);
	rounds = CHANNEL(channel)->rounds;
	CHANNEL(channel)->rounds = rounds - 1u;
	if (rounds != 1u)
	{
		fm_effect_37_retrigger(channel);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Loads fm_effect_38_patch (fm_effect_19_patch's bytes): a falling note four times
   (fm_effect_38_retrigger), at the volume start_sound leaves (0) and then at attenuations 10, 18 and 20;
   effect 19's figure from pitch 1000, fading slower. */
void fm_effect_38(uint16_t channel)
{
	uint16_t patch = 0;

	z80_block(27);
	patch = fm_effect_38_patch_ADDRESS;
	load_patch(patch, channel);
	z80_block(38);
	CHANNEL(channel)->count = 4u;
	CHANNEL(channel)->fm_effect_38.attenuation = 8u;
	fm_effect_38_retrigger(channel);
}

/* Sets pitch 1000 and keys on, for 64 passes of fm_effect_38_slide. */
void fm_effect_38_retrigger(uint16_t channel)
{
	uint16_t handler = 0, pitch = 0;

	z80_block(65);
	pitch = 0x1000u;
	CHANNEL(channel)->pitch = 0x1000u;
	set_pitch(pitch, channel);
	z80_block(17);
	key_on(channel);
	z80_block(39);
	CHANNEL(channel)->timer = 0x40u;
	handler = fm_effect_38_slide_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The pitch a quarter semitone lower each pass, played an octave higher in turn every 16 passes; after
   the 64 passes 8 quieter (set_volume) and the next time (fm_effect_38_retrigger), and stop_channel
   after the fourth. */
void fm_effect_38_slide(uint16_t channel)
{
	uint8_t volume = 0;
	uint16_t pitch = 0;
	uint8_t timer = 0, count = 0;

	z80_block(127);
	pitch = CHANNEL(channel)->pitch - 0x10u;
	CHANNEL(channel)->pitch = pitch;
	if ((CHANNEL(channel)->timer >> 4) & 1u)
	{
		z80_block(21);
		pitch += 0x300u;
	}
	z80_block(17);
	set_pitch(pitch, channel);
	z80_block(28);
	timer = CHANNEL(channel)->timer;
	CHANNEL(channel)->timer = timer - 1u;
	if (timer != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(62);
	volume = CHANNEL(channel)->fm_effect_38.attenuation + 8u;
	CHANNEL(channel)->fm_effect_38.attenuation = volume;
	set_volume(channel, volume);
	z80_block(33);
	count = CHANNEL(channel)->count;
	CHANNEL(channel)->count = count - 1u;
	if (count != 1u)
	{
		fm_effect_38_retrigger(channel);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}
