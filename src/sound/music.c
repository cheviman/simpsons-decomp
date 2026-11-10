/**
 *    Name:        music.c
 *    Description: the music: a song's tracks, their notes and commands, the pitch envelope, the gate, the fade's volume
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the Z80 sound program decompiled into C by
 *    tools/decompile_sound.py, with the names of sound_symbols.txt.
 */
#include "sound.h"

/* Starts the record's track: the song's command in song, the music's state cleared (tempo 1, time FFFF
   so that the first pass reads, gate_time 1), the track's place; a music sound playing on the record is
   stopped. */
void start_music_track(uint16_t track, uint16_t channel, uint8_t song)
{
	z80_block(937);
	CHANNEL(channel)->song = song;
	CHANNEL(channel)->music_priority = 0u;
	CHANNEL(channel)->drum_kit = 0u;
	CHANNEL(channel)->tempo = 1u;
	CHANNEL(channel)->gate = 0u;
	CHANNEL(channel)->octave = 0u;
	CHANNEL(channel)->detune = 0u;
	CHANNEL(channel)->music_volume = 0u;
	CHANNEL(channel)->music_pan = 0u;
	CHANNEL(channel)->patch = 0u;
	CHANNEL(channel)->lfo_ramp = 0u;
	CHANNEL(channel)->envelope_count_1 = 0u;
	CHANNEL(channel)->envelope_step_1 = 0;
	CHANNEL(channel)->envelope_count_2 = 0u;
	CHANNEL(channel)->envelope_step_2 = 0;
	CHANNEL(channel)->envelope_count_3 = 0u;
	CHANNEL(channel)->envelope_step_3 = 0;
	CHANNEL(channel)->envelope_count_4 = 0u;
	CHANNEL(channel)->envelope_step_4 = 0;
	CHANNEL(channel)->envelope_period = 0u;
	CHANNEL(channel)->spare = 0u;
	CHANNEL(channel)->transposition = 0;
	CHANNEL(channel)->drum_routines = 0u;
	CHANNEL(channel)->envelope_timer = 0u;
	CHANNEL(channel)->envelope_count = 0u;
	CHANNEL(channel)->note_pitch = 0u;
	CHANNEL(channel)->lfo_ramp_timer = 0u;
	CHANNEL(channel)->lfo_ramp_step = 0u;
	CHANNEL(channel)->jump_count = 0u;
	CHANNEL(channel)->loop_count = 0u;
	CHANNEL(channel)->loop_start = 0u;
	CHANNEL(channel)->loop_2_count = 0u;
	CHANNEL(channel)->loop_2_start = 0u;
	CHANNEL(channel)->part_count = 0u;
	CHANNEL(channel)->part_return = 0u;
	CHANNEL(channel)->time = 0xFFFFu;
	CHANNEL(channel)->gate_time = 1u;
	CHANNEL(channel)->track = track;
	if (CHANNEL(channel)->sound >> 7 == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(39);
	stop_channel(channel);
	z80_block(30);
}

/* No more track on the record (song 0); a music sound playing on it is stopped. */
void stop_music_channel(uint16_t channel)
{
	z80_block(44);
	CHANNEL(channel)->song = 0u;
	if (CHANNEL(channel)->sound >> 7 == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* Whether the record plays a track: its song. */
uint32_t music_channel_song(uint16_t channel)
{
	uint32_t zero = 0;

	z80_block(33);
	zero = CHANNEL(channel)->song == 0u;
	return zero;
}

/* The record's music, on one pass in 8 (by its chip_channel): the tempo added to time, and at its carry
   the track's next steps up to one that takes time: a note (its length; unless a sound of a higher
   priority has the record, the patch, volume and pan when the music did not have it, the gate, the pitch
   of fm_pitches_by_note or pcm_pitches by the note, octave, transposition and detune, key on but for a
   legato note, the pitch envelope and the LFO ramp from their start, the record's sound and priority the
   music's and music_pitch_envelope_1 its handler), a drum (the kit's routine for the note as the
   handler), a rest, an octave, or a command E0-FF (music_commands). */
uint16_t music_tick(uint16_t channel)
{
	bool L_0042C5 = false;
	uint32_t zero = 0, negative = 0, overflow = 0, carry = 0;
	uint8_t byte = 0, detune = 0, drum_kit = 0, envelope_count = 0, envelope_count_2 = 0, envelope_count_3 = 0, envelope_count_4 = 0, envelope_period = 0, envelope_step = 0, envelope_step_2 = 0, envelope_step_3 = 0, envelope_step_4 = 0, gate = 0, index_high = 0, jump_count = 0, lfo_ramp = 0, loop_2_count = 0, loop_count = 0, music_pan = 0, music_volume = 0, part_count = 0, sensitivity = 0, step = 0, step_2 = 0, tempo_2 = 0;
	uint16_t command_entry = 0, drum_routines = 0, element = 0, handler = 0, kit_routines = 0, part_return = 0, patch = 0, patch_entry = 0, pitch = 0, pitch_entry = 0, routine_entry = 0, tempo = 0, time = 0, track = 0, transposition = 0;
	uint8_t stack = 0, saved_step = 0;
	uint8_t t1 = 0, loop_count_2 = 0, loop_2_count_2 = 0, part_count_2 = 0;
	uint32_t jump_target = 0;

	z80_block(28);
	if (CHANNEL(channel)->song == 0u)
	{
		z80_cycles(6);
		return channel;
	}
	z80_block(59);
	if ((CHANNEL(channel)->chip_channel & 7u) != (pass_count & 7u))
	{
		z80_cycles(6);
		return channel;
	}
	z80_block(118);
	time = CHANNEL(channel)->time;
	tempo = CHANNEL(channel)->tempo;
	carry = (uint16_t)(time + tempo) < time;
	time += tempo;
	CHANNEL(channel)->time = time;
	if (carry == 0u)
	{
		z80_cycles(6);
		return channel;
	}
	for (;;)
	{
		z80_block(17);
		byte = next_track_byte(channel);
		z80_block(21);
		step = byte;
		if (byte < 0xE0u)
		{
			z80_block(17);
			if ((byte & 0xFu) == 0u)
			{
				z80_block(17);
				step_2 = step;
				carry = add_note_length(step_2, channel);
				z80_block(10);
				if (carry == 0u)
					break;
				continue;
			}
			z80_block(21);
			if (step < 0x10u)
			{
				z80_block(69);
				step = (((uint32_t)step << 1) << 1) << 1;
				CHANNEL(channel)->octave = step + ((uint32_t)step << 1);
				continue;
			}
			z80_block(17);
			step_2 = step;
			carry = add_note_length(step_2, channel);
			L_0042C5 = true;
		}
		if (!L_0042C5)
		{
			z80_block(71);
			command_entry = step * 2u + music_commands_ADDRESS;
		}
		jump_target = L_0042C5 ? 0x4737u : MUSIC_COMMAND_HANDLER(command_entry)[0];
		switch (jump_target)
		{
		case track_set_drum_kit_ADDRESS:
			z80_block(17);
			drum_kit = next_track_byte(channel);
			z80_block(33);
			CHANNEL(channel)->drum_kit = drum_kit;
			if (drum_kit == 0u)
				continue;
			z80_block(46);
			kit_routines = 0x494Cu;
			if (CHANNEL(channel)->chip_channel >= 8u)
			{
				z80_block(10);
				kit_routines = instrument_routines_ADDRESS;
			}
			z80_block(140);
			drum_routines = CHANNEL(channel)->drum_kit * 2u * 2u * 2u * 2u * 2u + kit_routines;
			CHANNEL(channel)->drum_routines = drum_routines;
			continue;
		case track_set_tempo_ADDRESS:
			z80_block(17);
			tempo_2 = next_track_byte(channel);
			z80_block(29);
			CHANNEL(channel)->tempo = tempo_2;
			continue;
		case track_set_instrument_ADDRESS:
			z80_block(17);
			byte = next_track_byte(channel);
			z80_block(61);
			step = ((uint32_t)byte << 1) | (byte >> 7);
			index_high = 0u;
			patch_entry = music_fm_patches_ADDRESS;
			if (CHANNEL(channel)->chip_channel >= 8u)
			{
				z80_block(89);
				transposition = TABLE16(music_pcm_transpositions, (uint16_t)(((uint32_t)index_high << 8) | step));
				CHANNEL(channel)->transposition = transposition;
				patch_entry = music_pcm_patches_ADDRESS;
			}
			z80_block(99);
			patch_entry += ((uint32_t)index_high << 8) | step;
			element = PATCH_ADDRESS(patch_entry)[0];
			CHANNEL(channel)->patch = element;
			if (CHANNEL(channel)->sound >> 7 == 0u)
				continue;
			z80_block(21);
			patch = element;
			load_patch(patch, channel);
			z80_block(36);
			music_pan = CHANNEL(channel)->music_pan;
			set_pan(channel, music_pan);
			z80_block(17);
			noise_off(channel);
			z80_block(10);
			continue;
		case track_set_volume_ADDRESS:
			z80_block(17);
			music_volume = next_track_byte(channel);
			z80_block(49);
			CHANNEL(channel)->music_volume = music_volume;
			if (CHANNEL(channel)->sound >> 7 != 0u)
			{
				z80_cycles(7);
				set_music_volume(channel, music_volume);
			}
			z80_block(10);
			continue;
		case track_set_gate_ADDRESS:
			z80_block(17);
			gate = next_track_byte(channel);
			z80_block(29);
			CHANNEL(channel)->gate = gate;
			continue;
		case track_held_note_ADDRESS:
			if (!L_0042C5)
			{
				z80_block(17);
				byte = next_track_byte(channel);
				z80_block(21);
				step = byte;
				step_2 = step;
				carry = add_note_length(step_2, channel);
				z80_block(11);
				saved_step = step;
				for (;;)
				{
					z80_block(17);
					byte = next_track_byte(channel);
					z80_block(28);
					step = byte;
					if ((byte & ~0xFu) == 0xF0u)
						break;
					z80_block(17);
					step_2 = step;
					carry = add_note_length(step_2, channel);
					z80_block(28);
					if ((step & 0xFu) == 0xFu)
						break;
					z80_block(49);
					step_2 = (uint8_t)(((((uint32_t)step << 1) << 1) << 1) << 1);
					carry = add_note_length(step_2, channel);
					z80_block(10);
				}
				z80_block(20);
				step = saved_step;
			}
			z80_block(43);
			if (CHANNEL(channel)->music_priority < CHANNEL(channel)->priority)
			{
				z80_cycles(6);
				return channel;
			}
			z80_block(33);
			if (CHANNEL(channel)->drum_kit != 0u)
			{
				z80_block(154);
				CHANNEL(channel)->gate_time = 1u;
				byte = step & 0xFu;
				routine_entry = CHANNEL(channel)->drum_routines + (uint8_t)(((uint32_t)byte << 1) | (byte >> 7));
				handler = z80_read16(routine_entry);
				set_channel_handler(handler, channel);
				z80_block(17);
				key_off(channel);
				z80_block(36);
				music_volume = CHANNEL(channel)->music_volume;
				set_music_volume(channel, music_volume);
				z80_block(17);
				noise_off(channel);
				z80_block(21);
				sensitivity = 0u;
				set_channel_pm_sensitivity(channel, sensitivity);
				z80_block(21);
				sensitivity = 0u;
				set_channel_am_sensitivity(channel, sensitivity);
				z80_block(86);
				CHANNEL(channel)->sound = CHANNEL(channel)->song;
				CHANNEL(channel)->priority = CHANNEL(channel)->music_priority;
				return channel;
			}
			z80_block(30);
			if (CHANNEL(channel)->sound >> 7 == 0u)
			{
				z80_block(66);
				saved_step = step;
				patch = CHANNEL(channel)->patch;
				load_patch(patch, channel);
				z80_block(36);
				music_volume = CHANNEL(channel)->music_volume;
				set_music_volume(channel, music_volume);
				z80_block(36);
				music_pan = CHANNEL(channel)->music_pan;
				set_pan(channel, music_pan);
				z80_block(17);
				noise_off(channel);
				z80_block(10);
				step = saved_step;
			}
			z80_block(66);
			t1 = (uint8_t)CHANNEL(channel)->gate_time | (uint8_t)(CHANNEL(channel)->gate_time >> 8u);
			negative = t1 >> 7;
			zero = t1 == 0u;
			overflow = parity8(t1);
			carry = 0u;
			stack = (negative << 7) | (zero << 6) | (overflow << 2) | (carry << 0);
			set_note_gate(channel);
			z80_block(46);
			pitch_entry = fm_pitches_by_note_ADDRESS;
			if (CHANNEL(channel)->chip_channel >= 8u)
			{
				z80_block(10);
				pitch_entry = pcm_pitches_ADDRESS;
			}
			z80_block(217);
			byte = step & 0xFu;
			pitch_entry = pitch_entry + (uint8_t)((((uint32_t)byte << 1) | (byte >> 7)) + CHANNEL(channel)->octave) + CHANNEL(channel)->transposition;
			pitch = CHANNEL(channel)->detune + PITCH(pitch_entry)[0];
			CHANNEL(channel)->note_pitch = pitch;
			set_pitch(pitch, channel);
			z80_block(20);
			if ((stack >> 6) & 1u)
			{
				z80_block(96);
				CHANNEL(channel)->sound = CHANNEL(channel)->song;
				CHANNEL(channel)->priority = CHANNEL(channel)->music_priority;
				handler = music_pitch_envelope_1_ADDRESS;
				set_channel_handler(handler, channel);
				return channel;
			}
			z80_block(17);
			key_off(channel);
			z80_block(78);
			CHANNEL(channel)->lfo_ramp_timer = CHANNEL(channel)->lfo_ramp;
			CHANNEL(channel)->lfo_ramp_step = 0u;
			sensitivity = 0u;
			set_channel_pm_sensitivity(channel, sensitivity);
			z80_block(21);
			sensitivity = 0u;
			set_channel_am_sensitivity(channel, sensitivity);
			z80_block(17);
			key_on(channel);
			z80_block(76);
			CHANNEL(channel)->envelope_timer = CHANNEL(channel)->envelope_period;
			CHANNEL(channel)->envelope_count = CHANNEL(channel)->envelope_count_1;
			z80_block(96);
			CHANNEL(channel)->sound = CHANNEL(channel)->song;
			CHANNEL(channel)->priority = CHANNEL(channel)->music_priority;
			handler = music_pitch_envelope_1_ADDRESS;
			set_channel_handler(handler, channel);
			return channel;
		case track_set_detune_ADDRESS:
			z80_block(17);
			detune = next_track_byte(channel);
			z80_block(29);
			CHANNEL(channel)->detune = detune;
			continue;
		case track_set_pitch_envelope_ADDRESS:
			z80_block(17);
			envelope_period = next_track_byte(channel);
			z80_block(36);
			CHANNEL(channel)->envelope_period = envelope_period;
			envelope_count = next_track_byte(channel);
			z80_block(36);
			CHANNEL(channel)->envelope_count_1 = envelope_count;
			envelope_step = next_track_byte(channel);
			z80_block(36);
			CHANNEL(channel)->envelope_step_1 = envelope_step;
			envelope_count_2 = next_track_byte(channel);
			z80_block(36);
			CHANNEL(channel)->envelope_count_2 = envelope_count_2;
			envelope_step_2 = next_track_byte(channel);
			z80_block(36);
			CHANNEL(channel)->envelope_step_2 = envelope_step_2;
			envelope_count_3 = next_track_byte(channel);
			z80_block(36);
			CHANNEL(channel)->envelope_count_3 = envelope_count_3;
			envelope_step_3 = next_track_byte(channel);
			z80_block(36);
			CHANNEL(channel)->envelope_step_3 = envelope_step_3;
			envelope_count_4 = next_track_byte(channel);
			z80_block(36);
			CHANNEL(channel)->envelope_count_4 = envelope_count_4;
			envelope_step_4 = next_track_byte(channel);
			z80_block(29);
			CHANNEL(channel)->envelope_step_4 = envelope_step_4;
			continue;
		case track_reset_e8_ADDRESS:
			z80_block(10);
			return sound_reset();
		case track_reset_e9_ADDRESS:
			z80_block(10);
			return sound_reset();
		case track_reset_ea_ADDRESS:
			z80_block(10);
			return sound_reset();
		case track_reset_eb_ADDRESS:
			z80_block(10);
			return sound_reset();
		case track_reset_ec_ADDRESS:
			z80_block(10);
			return sound_reset();
		case track_set_lfo_ADDRESS:
			z80_block(17);
			byte = next_track_byte(channel);
			z80_block(17);
			set_lfo_frequency(byte);
			z80_block(17);
			byte = next_track_byte(channel);
			z80_block(17);
			set_lfo_pm_depth(byte);
			z80_block(17);
			byte = next_track_byte(channel);
			z80_block(17);
			set_lfo_am_depth(byte);
			z80_block(17);
			byte = next_track_byte(channel);
			z80_block(17);
			set_lfo_waveform(byte);
			z80_block(10);
			continue;
		case track_set_lfo_ramp_ADDRESS:
			z80_block(17);
			lfo_ramp = next_track_byte(channel);
			z80_block(29);
			CHANNEL(channel)->lfo_ramp = lfo_ramp;
			continue;
		case track_set_pan_ADDRESS:
			z80_block(17);
			music_pan = next_track_byte(channel);
			z80_block(49);
			CHANNEL(channel)->music_pan = music_pan;
			if (CHANNEL(channel)->sound >> 7 != 0u)
			{
				z80_cycles(7);
				set_pan(channel, music_pan);
			}
			z80_block(10);
			continue;
		case track_jump_ADDRESS:
			z80_block(17);
			byte = next_track_byte(channel);
			z80_block(21);
			step = byte;
			byte = next_track_byte(channel);
			z80_block(48);
			CHANNEL(channel)->track = ((uint32_t)byte << 8) | step;
			continue;
		case track_jump_counted_ADDRESS:
			z80_block(40);
			CHANNEL(channel)->jump_count++;
			jump_count = next_track_byte(channel);
			z80_block(29);
			if (jump_count == CHANNEL(channel)->jump_count)
			{
				z80_block(29);
				CHANNEL(channel)->jump_count = 0u;
				z80_block(17);
				byte = next_track_byte(channel);
				z80_block(21);
				step = byte;
				byte = next_track_byte(channel);
				z80_block(48);
				CHANNEL(channel)->track = ((uint32_t)byte << 8) | step;
				continue;
			}
			z80_block(17);
			next_track_byte(channel);
			z80_block(17);
			next_track_byte(channel);
			z80_block(10);
			continue;
		case track_loop_start_ADDRESS:
			z80_block(17);
			loop_count = next_track_byte(channel);
			z80_block(105);
			CHANNEL(channel)->loop_count = loop_count;
			CHANNEL(channel)->loop_start = CHANNEL(channel)->track;
			continue;
		case track_loop_end_ADDRESS:
			z80_block(33);
			loop_count_2 = CHANNEL(channel)->loop_count;
			CHANNEL(channel)->loop_count = loop_count_2 - 1u;
			if (loop_count_2 == 1u)
				continue;
			z80_block(86);
			CHANNEL(channel)->track = CHANNEL(channel)->loop_start;
			continue;
		case track_loop_2_start_ADDRESS:
			z80_block(17);
			loop_2_count = next_track_byte(channel);
			z80_block(105);
			CHANNEL(channel)->loop_2_count = loop_2_count;
			CHANNEL(channel)->loop_2_start = CHANNEL(channel)->track;
			continue;
		case track_loop_2_end_ADDRESS:
			z80_block(33);
			loop_2_count_2 = CHANNEL(channel)->loop_2_count;
			CHANNEL(channel)->loop_2_count = loop_2_count_2 - 1u;
			if (loop_2_count_2 == 1u)
				continue;
			z80_block(86);
			CHANNEL(channel)->track = CHANNEL(channel)->loop_2_start;
			continue;
		case track_call_part_ADDRESS:
			z80_block(17);
			part_count = next_track_byte(channel);
			z80_block(112);
			CHANNEL(channel)->part_count = part_count;
			track = CHANNEL(channel)->track;
			CHANNEL(channel)->part_return = track;
			byte = next_track_byte(channel);
			z80_block(21);
			step = byte;
			byte = next_track_byte(channel);
			z80_block(48);
			CHANNEL(channel)->track = ((uint32_t)byte << 8) | step;
			continue;
		case track_part_return_ADDRESS:
			z80_block(93);
			part_return = CHANNEL(channel)->part_return;
			CHANNEL(channel)->track = part_return;
			byte = next_track_byte(channel);
			z80_block(21);
			step = byte;
			byte = next_track_byte(channel);
			z80_block(33);
			part_count_2 = CHANNEL(channel)->part_count;
			CHANNEL(channel)->part_count = part_count_2 - 1u;
			if (part_count_2 == 1u)
				continue;
			z80_block(48);
			CHANNEL(channel)->track = ((uint32_t)byte << 8) | step;
			continue;
		case track_reset_f8_ADDRESS:
			z80_block(10);
			return sound_reset();
		case track_reset_fd_ADDRESS:
			z80_block(10);
			return sound_reset();
		case track_set_priority_ADDRESS:
			z80_block(17);
			byte = next_track_byte(channel);
			z80_block(49);
			CHANNEL(channel)->music_priority = byte;
			if (CHANNEL(channel)->sound >> 7 == 0u)
				continue;
			z80_block(29);
			CHANNEL(channel)->priority = byte;
			continue;
		case track_end_ADDRESS:
			z80_block(51);
			CHANNEL(channel)->song = 0u;
			if (CHANNEL(channel)->sound >> 7 == 0u)
			{
				z80_cycles(6);
				return channel;
			}
			z80_block(48);
			CHANNEL(channel)->sound = 0u;
			CHANNEL(channel)->priority = 0u;
			return channel;
		}
	}
	z80_block(63);
	CHANNEL(channel)->gate_time = 1u;
	if (CHANNEL(channel)->sound >> 7 == 0u)
	{
		z80_cycles(6);
		return channel;
	}
	z80_block(10);
	key_off(channel);
	return channel;
}

/* A music note's handler while the pitch envelope's first segment runs: music_note_tick, then every
   envelope_period passes envelope_step added to note_pitch, envelope_count_1 times; then the second
   segment. */
void music_pitch_envelope_1(uint16_t channel)
{
	uint8_t envelope_step = 0, step_high = 0;
	uint16_t handler = 0, pitch = 0;
	uint8_t envelope_timer = 0, envelope_count = 0;

	z80_block(17);
	music_note_tick(channel);
	z80_block(28);
	if (CHANNEL(channel)->envelope_timer == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(28);
	envelope_timer = CHANNEL(channel)->envelope_timer;
	CHANNEL(channel)->envelope_timer = envelope_timer - 1u;
	if (envelope_timer != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(82);
	CHANNEL(channel)->envelope_timer = CHANNEL(channel)->envelope_period;
	envelope_step = CHANNEL(channel)->envelope_step_1;
	step_high = 0u;
	if (envelope_step >> 7)
	{
		z80_block(4);
		step_high--;
	}
	z80_block(104);
	pitch = CHANNEL(channel)->note_pitch + (((uint32_t)step_high << 8) | envelope_step);
	CHANNEL(channel)->note_pitch = pitch;
	set_pitch(pitch, channel);
	z80_block(28);
	envelope_count = CHANNEL(channel)->envelope_count;
	CHANNEL(channel)->envelope_count = envelope_count - 1u;
	if (envelope_count != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(58);
	CHANNEL(channel)->envelope_count = CHANNEL(channel)->envelope_count_2;
	handler = music_pitch_envelope_2_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The second segment: music_note_tick, then every envelope_period passes envelope_step added to
   note_pitch, envelope_count_2 times; then the third. */
void music_pitch_envelope_2(uint16_t channel)
{
	uint8_t envelope_step = 0, step_high = 0;
	uint16_t handler = 0, pitch = 0;
	uint8_t envelope_timer = 0, envelope_count = 0;

	z80_block(17);
	music_note_tick(channel);
	z80_block(28);
	if (CHANNEL(channel)->envelope_timer == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(28);
	envelope_timer = CHANNEL(channel)->envelope_timer;
	CHANNEL(channel)->envelope_timer = envelope_timer - 1u;
	if (envelope_timer != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(82);
	CHANNEL(channel)->envelope_timer = CHANNEL(channel)->envelope_period;
	envelope_step = CHANNEL(channel)->envelope_step_2;
	step_high = 0u;
	if (envelope_step >> 7)
	{
		z80_block(4);
		step_high--;
	}
	z80_block(104);
	pitch = CHANNEL(channel)->note_pitch + (((uint32_t)step_high << 8) | envelope_step);
	CHANNEL(channel)->note_pitch = pitch;
	set_pitch(pitch, channel);
	z80_block(28);
	envelope_count = CHANNEL(channel)->envelope_count;
	CHANNEL(channel)->envelope_count = envelope_count - 1u;
	if (envelope_count != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(58);
	CHANNEL(channel)->envelope_count = CHANNEL(channel)->envelope_count_3;
	handler = music_pitch_envelope_3_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The third segment: music_note_tick, then every envelope_period passes envelope_step added to
   note_pitch, envelope_count_3 times; then the fourth. */
void music_pitch_envelope_3(uint16_t channel)
{
	uint8_t envelope_step = 0, step_high = 0;
	uint16_t handler = 0, pitch = 0;
	uint8_t envelope_timer = 0, envelope_count = 0;

	z80_block(17);
	music_note_tick(channel);
	z80_block(28);
	if (CHANNEL(channel)->envelope_timer == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(28);
	envelope_timer = CHANNEL(channel)->envelope_timer;
	CHANNEL(channel)->envelope_timer = envelope_timer - 1u;
	if (envelope_timer != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(82);
	CHANNEL(channel)->envelope_timer = CHANNEL(channel)->envelope_period;
	envelope_step = CHANNEL(channel)->envelope_step_3;
	step_high = 0u;
	if (envelope_step >> 7)
	{
		z80_block(4);
		step_high--;
	}
	z80_block(104);
	pitch = CHANNEL(channel)->note_pitch + (((uint32_t)step_high << 8) | envelope_step);
	CHANNEL(channel)->note_pitch = pitch;
	set_pitch(pitch, channel);
	z80_block(28);
	envelope_count = CHANNEL(channel)->envelope_count;
	CHANNEL(channel)->envelope_count = envelope_count - 1u;
	if (envelope_count != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(58);
	CHANNEL(channel)->envelope_count = CHANNEL(channel)->envelope_count_4;
	handler = music_pitch_envelope_4_ADDRESS;
	set_channel_handler(handler, channel);
}

/* The fourth segment: music_note_tick, then every envelope_period passes envelope_step added to
   note_pitch, envelope_count_4 times; then music_note_tick alone. */
void music_pitch_envelope_4(uint16_t channel)
{
	uint8_t envelope_step = 0, step_high = 0;
	uint16_t handler = 0, pitch = 0;
	uint8_t envelope_timer = 0, envelope_count = 0;

	z80_block(17);
	music_note_tick(channel);
	z80_block(28);
	if (CHANNEL(channel)->envelope_timer == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(28);
	envelope_timer = CHANNEL(channel)->envelope_timer;
	CHANNEL(channel)->envelope_timer = envelope_timer - 1u;
	if (envelope_timer != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(82);
	CHANNEL(channel)->envelope_timer = CHANNEL(channel)->envelope_period;
	envelope_step = CHANNEL(channel)->envelope_step_4;
	step_high = 0u;
	if (envelope_step >> 7)
	{
		z80_block(4);
		step_high--;
	}
	z80_block(104);
	pitch = CHANNEL(channel)->note_pitch + (((uint32_t)step_high << 8) | envelope_step);
	CHANNEL(channel)->note_pitch = pitch;
	set_pitch(pitch, channel);
	z80_block(28);
	envelope_count = CHANNEL(channel)->envelope_count;
	CHANNEL(channel)->envelope_count = envelope_count - 1u;
	if (envelope_count != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(20);
	handler = music_note_tick_ADDRESS;
	set_channel_handler(handler, channel);
}

/* A music note's handler: the LFO ramp (every lfo_ramp passes the channel's sensitivities a step up, to
   7); on the record's own pass in 16 the fade's volume when a fade runs, and key off once the time left
   is no more than gate_time. */
void music_note_tick(uint16_t channel)
{
	uint32_t carry = 0;
	uint8_t lfo_ramp_step = 0, sensitivity = 0;
	uint16_t time = 0;
	uint8_t lfo_ramp_timer = 0;

	z80_block(33);
	if (CHANNEL(channel)->lfo_ramp_timer != 0u)
	{
		z80_block(33);
		lfo_ramp_timer = CHANNEL(channel)->lfo_ramp_timer;
		CHANNEL(channel)->lfo_ramp_timer = lfo_ramp_timer - 1u;
		if (lfo_ramp_timer == 1u)
		{
			z80_block(59);
			CHANNEL(channel)->lfo_ramp_step++;
			lfo_ramp_step = CHANNEL(channel)->lfo_ramp_step;
			set_channel_pm_sensitivity(channel, lfo_ramp_step);
			z80_block(44);
			sensitivity = CHANNEL(channel)->lfo_ramp_step >> 1;
			set_channel_am_sensitivity(channel, sensitivity);
			z80_block(36);
			if (CHANNEL(channel)->lfo_ramp_step != 7u)
			{
				z80_block(38);
				CHANNEL(channel)->lfo_ramp_timer = CHANNEL(channel)->lfo_ramp;
			}
		}
	}
	z80_block(44);
	if ((pass_count & 0xFu) != CHANNEL(channel)->chip_channel)
	{
		z80_cycles(6);
		return;
	}
	z80_block(27);
	if (fade != 0u)
	{
		z80_cycles(7);
		update_music_volume(channel);
	}
	z80_block(92);
	time = CHANNEL(channel)->time;
	carry = (uint16_t)(time + CHANNEL(channel)->gate_time) < time;
	if (carry == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	key_off(channel);
}

/* Adds a step's length (note_lengths, by its high nibble: negative, so it counts time down) to time;
   hands back the carry, set when the step ends before the time counted so far. */
uint32_t add_note_length(uint8_t step, uint16_t channel)
{
	uint32_t carry = 0;
	uint8_t code = 0;
	uint16_t length = 0, time = 0;

	z80_block(172);
	code = step & 0xF0u;
	code = (code >> 1) | ((uint32_t)code << 7);
	code = (code >> 1) | ((uint32_t)code << 7);
	length = (uint8_t)((code >> 1) | ((uint32_t)code << 7));
	length = TABLE16(note_lengths, length);
	time = CHANNEL(channel)->time;
	carry = (uint16_t)(time + length) < time;
	time += length;
	CHANNEL(channel)->time = time;
	return carry;
}

/* The note's gate_time: gate 256ths of what is left of time, at least 1; 0 when gate is 0 (the next note
   legato). */
void set_note_gate(uint16_t channel)
{
	uint32_t carry = 0;
	uint8_t count = 0, left_high = 0, left_low = 0, ratio = 0;
	uint16_t gate_time = 0;
	uint8_t t1 = 0;

	z80_block(43);
	gate_time = 0u;
	ratio = CHANNEL(channel)->gate;
	if (ratio == 0u)
	{
		z80_block(48);
		CHANNEL(channel)->gate_time = gate_time;
		return;
	}
	z80_block(78);
	gate_time -= CHANNEL(channel)->time;
	left_high = (uint8_t)(gate_time >> 8);
	left_low = (uint8_t)gate_time;
	gate_time = 0u;
	count = 8u;
	for (;;)
	{
		z80_block(30);
		carry = left_high & 1u;
		left_high = left_high >> 1;
		left_low = (left_low >> 1) | (carry << 7);
		t1 = ratio;
		ratio = ((uint32_t)t1 << 1) | (t1 >> 7);
		if (t1 >> 7)
		{
			z80_block(11);
			gate_time += ((uint32_t)left_high << 8) | left_low;
		}
		z80_block(8);
		count--;
		if (count == 0u)
			break;
		z80_cycles(5);
	}
	z80_block(18);
	if ((uint8_t)(gate_time | (gate_time >> 8)) == 0u)
	{
		z80_block(6);
		gate_time++;
	}
	z80_block(48);
	CHANNEL(channel)->gate_time = gate_time;
}

/* set_music_volume with the record's music_volume. */
void update_music_volume(uint16_t channel)
{
	uint8_t music_volume = 0;

	z80_block(19);
	music_volume = CHANNEL(channel)->music_volume;
	set_music_volume(channel, music_volume);
}

/* The music's volume on the record: the volume given plus fade_attenuation (at most 7F), then
   set_volume. */
void set_music_volume(uint16_t channel, uint8_t music_volume)
{
	uint8_t volume = 0;
	uint8_t t1 = 0;

	z80_block(31);
	t1 = fade_attenuation + music_volume;
	volume = t1;
	if ((int8_t)t1 >= 0)
	{
		set_volume(channel, volume);
		return;
	}
	z80_block(17);
	volume = 0x7Fu;
	set_volume(channel, volume);
}

/* The track's next byte; track moves on. */
uint8_t next_track_byte(uint16_t channel)
{
	uint8_t byte = 0;
	uint16_t track = 0;

	z80_block(99);
	track = CHANNEL(channel)->track;
	byte = z80_read8(track);
	track++;
	CHANNEL(channel)->track = track;
	return byte;
}

/* A drum routine's end: the record's handler channel_idle, the note left to ring. */
void drum_done(uint16_t channel)
{
	uint16_t handler = 0;

	z80_block(20);
	handler = channel_idle_ADDRESS;
	set_channel_handler(handler, channel);
}
