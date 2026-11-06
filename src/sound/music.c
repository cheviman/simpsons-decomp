/**
 *    Name:        music.c
 *    Description: the music: a song's tracks, their notes and commands, the pitch envelope, the gate, the fade's volume
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    06-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the Z80 sound program decompiled into C by
 *    tools/decompile_sound.py, with the names of sound_symbols.txt.
 */
#include "sound.h"

/* the record's music from its start: the song A (+10), its state (+11-+3D) cleared, the track at DE
   (+3E); a music sound on the record is stopped */
void start_music_track(uint16_t de, uint16_t ix, uint8_t a)
{
	z80_block(937);
	z80_write8((uint16_t)(ix + 0x10u), a);
	z80_write8((uint16_t)(ix + 0x11u), 0u);
	z80_write8((uint16_t)(ix + 0x12u), 0u);
	z80_write8((uint16_t)(ix + 0x13u), 1u);
	z80_write8((uint16_t)(ix + 0x14u), 0u);
	z80_write8((uint16_t)(ix + 0x15u), 0u);
	z80_write8((uint16_t)(ix + 0x16u), 0u);
	z80_write8((uint16_t)(ix + 0x17u), 0u);
	z80_write8((uint16_t)(ix + 0x18u), 0u);
	z80_write8((uint16_t)(ix + 0x19u), 0u);
	z80_write8((uint16_t)(ix + 0x1Au), 0u);
	z80_write8((uint16_t)(ix + 0x1Bu), 0u);
	z80_write8((uint16_t)(ix + 0x1Cu), 0u);
	z80_write8((uint16_t)(ix + 0x1Du), 0u);
	z80_write8((uint16_t)(ix + 0x1Eu), 0u);
	z80_write8((uint16_t)(ix + 0x1Fu), 0u);
	z80_write8((uint16_t)(ix + 0x20u), 0u);
	z80_write8((uint16_t)(ix + 0x21u), 0u);
	z80_write8((uint16_t)(ix + 0x22u), 0u);
	z80_write8((uint16_t)(ix + 0x23u), 0u);
	z80_write8((uint16_t)(ix + 0x24u), 0u);
	z80_write8((uint16_t)(ix + 0x25u), 0u);
	z80_write8((uint16_t)(ix + 0x26u), 0u);
	z80_write8((uint16_t)(ix + 0x27u), 0u);
	z80_write8((uint16_t)(ix + 0x28u), 0u);
	z80_write8((uint16_t)(ix + 0x29u), 0u);
	z80_write8((uint16_t)(ix + 0x2Au), 0u);
	z80_write8((uint16_t)(ix + 0x2Bu), 0u);
	z80_write8((uint16_t)(ix + 0x2Cu), 0u);
	z80_write8((uint16_t)(ix + 0x2Du), 0u);
	z80_write8((uint16_t)(ix + 0x2Eu), 0u);
	z80_write8((uint16_t)(ix + 0x2Fu), 0u);
	z80_write8((uint16_t)(ix + 0x30u), 0u);
	z80_write8((uint16_t)(ix + 0x31u), 0u);
	z80_write8((uint16_t)(ix + 0x32u), 0u);
	z80_write8((uint16_t)(ix + 0x33u), 0u);
	z80_write8((uint16_t)(ix + 0x34u), 0u);
	z80_write8((uint16_t)(ix + 0x35u), 0u);
	z80_write8((uint16_t)(ix + 0x36u), 0u);
	z80_write8((uint16_t)(ix + 0x37u), 0u);
	z80_write8((uint16_t)(ix + 0x38u), 0u);
	z80_write8((uint16_t)(ix + 0x39u), 0u);
	z80_write8((uint16_t)(ix + 0x3Au), 0xFFu);
	z80_write8((uint16_t)(ix + 0x3Bu), 0xFFu);
	z80_write8((uint16_t)(ix + 0x3Cu), 1u);
	z80_write8((uint16_t)(ix + 0x3Du), 0u);
	z80_write16((uint16_t)(ix + 0x3Eu), de);
	if (z80_read8((uint16_t)(ix + 0x41u)) >> 7 == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(39);
	stop_channel(ix);
	z80_block(30);
}

/* no song on the record (+10); a music sound on it stopped */
void stop_music_channel(uint16_t ix)
{
	z80_block(44);
	z80_write8((uint16_t)(ix + 0x10u), 0u);
	if (z80_read8((uint16_t)(ix + 0x41u)) >> 7 == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

/* the record's song (+10), its flags */
uint32_t music_channel_song(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(33);
	zero = z80_read8((uint16_t)(ix + 0x10u)) == 0u;
	return zero;
}

/* a record's music, one pass in 8 (its own): the tempo (+13) added to +3A, at each carry the track's
   next step: a note (its length, a drum routine, the patch, volume and pan, the pitch, key on, the pitch
   envelope), a rest, an octave, or a command E0-FF (music_commands) */
uint16_t music_tick(uint16_t ix)
{
	bool L_0042C5 = false;
	uint32_t zero = 0, negative = 0, overflow = 0, carry = 0;
	uint8_t a = 0, b = 0, bc = 0, c = 0, d = 0, e = 0;
	uint16_t hl = 0;
	uint8_t stack = 0, saved_c = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;
	uint32_t jump_target = 0;

	z80_block(28);
	if (z80_read8((uint16_t)(ix + 0x10u)) == 0u)
	{
		z80_cycles(6);
		return ix;
	}
	z80_block(59);
	if ((z80_read8((uint16_t)(ix + 0x40u)) & 7u) != (pass_count & 7u))
	{
		z80_cycles(6);
		return ix;
	}
	z80_block(118);
	hl = z80_read16((uint16_t)(ix + 0x3Au));
	e = z80_read8((uint16_t)(ix + 0x13u));
	carry = (uint16_t)(hl + e) < hl;
	hl += e;
	z80_write16((uint16_t)(ix + 0x3Au), hl);
	if (carry == 0u)
	{
		z80_cycles(6);
		return ix;
	}
	for (;;)
	{
		z80_block(17);
		a = next_track_byte(ix);
		z80_block(21);
		c = a;
		if (a < 0xE0u)
		{
			z80_block(17);
			if ((a & 0xFu) == 0u)
			{
				z80_block(17);
				bc = c;
				carry = add_note_length(bc, ix);
				z80_block(10);
				if (carry == 0u)
					break;
				continue;
			}
			z80_block(21);
			if (c < 0x10u)
			{
				z80_block(69);
				c = (((uint32_t)c << 1) << 1) << 1;
				z80_write8((uint16_t)(ix + 0x15u), c + ((uint32_t)c << 1));
				continue;
			}
			z80_block(17);
			bc = c;
			carry = add_note_length(bc, ix);
			L_0042C5 = true;
		}
		if (!L_0042C5)
		{
			z80_block(71);
			hl = c * 2u + music_commands_ADDRESS;
		}
		jump_target = L_0042C5 ? 0x4737u : SOUND_ROM16(hl);
		switch (jump_target)
		{
		case 0x0046A6u:
			z80_block(17);
			a = next_track_byte(ix);
			z80_block(33);
			z80_write8((uint16_t)(ix + 0x12u), a);
			if (a == 0u)
				continue;
			z80_block(46);
			d = 0x49u;
			e = 0x4Cu;
			if (z80_read8((uint16_t)(ix + 0x40u)) >= 8u)
			{
				z80_block(10);
				d = 0x4Eu;
				e = 0x4Eu;
			}
			z80_block(140);
			hl = z80_read8((uint16_t)(ix + 0x12u)) * 2u * 2u * 2u * 2u * 2u + (((uint32_t)d << 8) | e);
			z80_write16((uint16_t)(ix + 0x28u), hl);
			continue;
		case 0x0046D2u:
			z80_block(17);
			a = next_track_byte(ix);
			z80_block(29);
			z80_write8((uint16_t)(ix + 0x13u), a);
			continue;
		case 0x0046DBu:
			z80_block(17);
			a = next_track_byte(ix);
			z80_block(61);
			c = ((uint32_t)a << 1) | (a >> 7);
			b = 0u;
			hl = music_fm_patches_ADDRESS;
			if (z80_read8((uint16_t)(ix + 0x40u)) >= 8u)
			{
				z80_block(89);
				hl = music_pcm_transpositions_ADDRESS + (((uint32_t)b << 8) | c);
				d = SOUND_ROM8(hl + 1u);
				z80_write8((uint16_t)(ix + 0x26u), SOUND_ROM8(hl));
				z80_write8((uint16_t)(ix + 0x27u), d);
				hl = music_pcm_patches_ADDRESS;
			}
			z80_block(99);
			hl += ((uint32_t)b << 8) | c;
			e = SOUND_ROM8(hl);
			d = SOUND_ROM8(hl + 1u);
			z80_write8((uint16_t)(ix + 0x19u), e);
			z80_write8((uint16_t)(ix + 0x1Au), d);
			if (z80_read8((uint16_t)(ix + 0x41u)) >> 7 == 0u)
				continue;
			z80_block(21);
			hl = ((uint32_t)d << 8) | e;
			load_patch(hl, ix);
			z80_block(36);
			a = z80_read8((uint16_t)(ix + 0x18u));
			set_pan(ix, a);
			z80_block(17);
			noise_off(ix);
			z80_block(10);
			continue;
		case 0x00471Eu:
			z80_block(17);
			a = next_track_byte(ix);
			z80_block(49);
			z80_write8((uint16_t)(ix + 0x17u), a);
			if (z80_read8((uint16_t)(ix + 0x41u)) >> 7 != 0u)
			{
				z80_cycles(7);
				set_music_volume(ix, a);
			}
			z80_block(10);
			continue;
		case 0x00472Eu:
			z80_block(17);
			a = next_track_byte(ix);
			z80_block(29);
			z80_write8((uint16_t)(ix + 0x14u), a);
			continue;
		case 0x004737u:
			if (!L_0042C5)
			{
				z80_block(17);
				a = next_track_byte(ix);
				z80_block(21);
				c = a;
				bc = c;
				carry = add_note_length(bc, ix);
				z80_block(11);
				saved_c = c;
				for (;;)
				{
					z80_block(17);
					a = next_track_byte(ix);
					z80_block(28);
					c = a;
					if ((a & ~0xFu) == 0xF0u)
						break;
					z80_block(17);
					bc = c;
					carry = add_note_length(bc, ix);
					z80_block(28);
					if ((c & 0xFu) == 0xFu)
						break;
					z80_block(49);
					bc = (uint8_t)(((((uint32_t)c << 1) << 1) << 1) << 1);
					carry = add_note_length(bc, ix);
					z80_block(10);
				}
				z80_block(20);
				c = saved_c;
			}
			z80_block(43);
			if (z80_read8((uint16_t)(ix + 0x11u)) < z80_read8((uint16_t)(ix + 0x42u)))
			{
				z80_cycles(6);
				return ix;
			}
			z80_block(33);
			if (z80_read8((uint16_t)(ix + 0x12u)) != 0u)
			{
				z80_block(154);
				z80_write8((uint16_t)(ix + 0x3Cu), 1u);
				z80_write8((uint16_t)(ix + 0x3Du), 0u);
				a = c & 0xFu;
				hl = z80_read16((uint16_t)(ix + 0x28u)) + (uint8_t)(((uint32_t)a << 1) | (a >> 7));
				hl = z80_read16(hl);
				set_channel_handler(hl, ix);
				z80_block(17);
				key_off(ix);
				z80_block(36);
				a = z80_read8((uint16_t)(ix + 0x17u));
				set_music_volume(ix, a);
				z80_block(17);
				noise_off(ix);
				z80_block(21);
				a = 0u;
				set_channel_pm_sensitivity(ix, a);
				z80_block(21);
				a = 0u;
				set_channel_am_sensitivity(ix, a);
				z80_block(86);
				z80_write8((uint16_t)(ix + 0x41u), z80_read8((uint16_t)(ix + 0x10u)));
				z80_write8((uint16_t)(ix + 0x42u), z80_read8((uint16_t)(ix + 0x11u)));
				return ix;
			}
			z80_block(30);
			if (z80_read8((uint16_t)(ix + 0x41u)) >> 7 == 0u)
			{
				z80_block(66);
				saved_c = c;
				hl = z80_read16((uint16_t)(ix + 0x19u));
				load_patch(hl, ix);
				z80_block(36);
				a = z80_read8((uint16_t)(ix + 0x17u));
				set_music_volume(ix, a);
				z80_block(36);
				a = z80_read8((uint16_t)(ix + 0x18u));
				set_pan(ix, a);
				z80_block(17);
				noise_off(ix);
				z80_block(10);
				c = saved_c;
			}
			z80_block(66);
			t1 = z80_read8((uint16_t)(ix + 0x3Cu)) | z80_read8((uint16_t)(ix + 0x3Du));
			negative = t1 >> 7;
			zero = t1 == 0u;
			overflow = parity8(t1);
			carry = 0u;
			stack = (negative << 7) | (zero << 6) | (overflow << 2) | (carry << 0);
			set_note_gate(ix);
			z80_block(46);
			hl = 0x448Bu;
			if (z80_read8((uint16_t)(ix + 0x40u)) >= 8u)
			{
				z80_block(10);
				hl = pcm_pitches_ADDRESS;
			}
			z80_block(217);
			a = c & 0xFu;
			hl = hl + (uint8_t)((((uint32_t)a << 1) | (a >> 7)) + z80_read8((uint16_t)(ix + 0x15u))) + z80_read16((uint16_t)(ix + 0x26u));
			hl = z80_read8((uint16_t)(ix + 0x16u)) + SOUND_ROM16(hl);
			z80_write16((uint16_t)(ix + 0x2Cu), hl);
			set_pitch(hl, ix);
			z80_block(20);
			if ((stack >> 6) & 1u)
			{
				z80_block(96);
				z80_write8((uint16_t)(ix + 0x41u), z80_read8((uint16_t)(ix + 0x10u)));
				z80_write8((uint16_t)(ix + 0x42u), z80_read8((uint16_t)(ix + 0x11u)));
				hl = music_pitch_envelope_1_ADDRESS;
				set_channel_handler(hl, ix);
				return ix;
			}
			z80_block(17);
			key_off(ix);
			z80_block(78);
			z80_write8((uint16_t)(ix + 0x2Eu), z80_read8((uint16_t)(ix + 0x1Bu)));
			z80_write8((uint16_t)(ix + 0x2Fu), 0u);
			a = 0u;
			set_channel_pm_sensitivity(ix, a);
			z80_block(21);
			a = 0u;
			set_channel_am_sensitivity(ix, a);
			z80_block(17);
			key_on(ix);
			z80_block(76);
			z80_write8((uint16_t)(ix + 0x2Au), z80_read8((uint16_t)(ix + 0x24u)));
			z80_write8((uint16_t)(ix + 0x2Bu), z80_read8((uint16_t)(ix + 0x1Cu)));
			z80_block(96);
			z80_write8((uint16_t)(ix + 0x41u), z80_read8((uint16_t)(ix + 0x10u)));
			z80_write8((uint16_t)(ix + 0x42u), z80_read8((uint16_t)(ix + 0x11u)));
			hl = music_pitch_envelope_1_ADDRESS;
			set_channel_handler(hl, ix);
			return ix;
		case 0x004767u:
			z80_block(17);
			a = next_track_byte(ix);
			z80_block(29);
			z80_write8((uint16_t)(ix + 0x16u), a);
			continue;
		case 0x004770u:
			z80_block(17);
			a = next_track_byte(ix);
			z80_block(36);
			z80_write8((uint16_t)(ix + 0x24u), a);
			a = next_track_byte(ix);
			z80_block(36);
			z80_write8((uint16_t)(ix + 0x1Cu), a);
			a = next_track_byte(ix);
			z80_block(36);
			z80_write8((uint16_t)(ix + 0x1Du), a);
			a = next_track_byte(ix);
			z80_block(36);
			z80_write8((uint16_t)(ix + 0x1Eu), a);
			a = next_track_byte(ix);
			z80_block(36);
			z80_write8((uint16_t)(ix + 0x1Fu), a);
			a = next_track_byte(ix);
			z80_block(36);
			z80_write8((uint16_t)(ix + 0x20u), a);
			a = next_track_byte(ix);
			z80_block(36);
			z80_write8((uint16_t)(ix + 0x21u), a);
			a = next_track_byte(ix);
			z80_block(36);
			z80_write8((uint16_t)(ix + 0x22u), a);
			a = next_track_byte(ix);
			z80_block(29);
			z80_write8((uint16_t)(ix + 0x23u), a);
			continue;
		case 0x0047A9u:
			z80_block(10);
			return sound_reset();
		case 0x0047ACu:
			z80_block(10);
			return sound_reset();
		case 0x0047AFu:
			z80_block(10);
			return sound_reset();
		case 0x0047B2u:
			z80_block(10);
			return sound_reset();
		case 0x0047B5u:
			z80_block(10);
			return sound_reset();
		case 0x0047B8u:
			z80_block(17);
			a = next_track_byte(ix);
			z80_block(17);
			set_lfo_frequency(a);
			z80_block(17);
			a = next_track_byte(ix);
			z80_block(17);
			set_lfo_pm_depth(a);
			z80_block(17);
			a = next_track_byte(ix);
			z80_block(17);
			set_lfo_am_depth(a);
			z80_block(17);
			a = next_track_byte(ix);
			z80_block(17);
			set_lfo_waveform(a);
			z80_block(10);
			continue;
		case 0x0047D3u:
			z80_block(17);
			a = next_track_byte(ix);
			z80_block(29);
			z80_write8((uint16_t)(ix + 0x1Bu), a);
			continue;
		case 0x0047DCu:
			z80_block(17);
			a = next_track_byte(ix);
			z80_block(49);
			z80_write8((uint16_t)(ix + 0x18u), a);
			if (z80_read8((uint16_t)(ix + 0x41u)) >> 7 != 0u)
			{
				z80_cycles(7);
				set_pan(ix, a);
			}
			z80_block(10);
			continue;
		case 0x0047ECu:
			z80_block(17);
			a = next_track_byte(ix);
			z80_block(21);
			c = a;
			a = next_track_byte(ix);
			z80_block(48);
			z80_write8((uint16_t)(ix + 0x3Eu), c);
			z80_write8((uint16_t)(ix + 0x3Fu), a);
			continue;
		case 0x0047FCu:
			z80_block(40);
			z80_write8((uint16_t)(ix + 0x30u), z80_read8((uint16_t)(ix + 0x30u)) + 1u);
			a = next_track_byte(ix);
			z80_block(29);
			if (a == z80_read8((uint16_t)(ix + 0x30u)))
			{
				z80_block(29);
				z80_write8((uint16_t)(ix + 0x30u), 0u);
				z80_block(17);
				a = next_track_byte(ix);
				z80_block(21);
				c = a;
				a = next_track_byte(ix);
				z80_block(48);
				z80_write8((uint16_t)(ix + 0x3Eu), c);
				z80_write8((uint16_t)(ix + 0x3Fu), a);
				continue;
			}
			z80_block(17);
			next_track_byte(ix);
			z80_block(17);
			next_track_byte(ix);
			z80_block(10);
			continue;
		case 0x004818u:
			z80_block(17);
			a = next_track_byte(ix);
			z80_block(105);
			z80_write8((uint16_t)(ix + 0x31u), a);
			z80_write8((uint16_t)(ix + 0x32u), z80_read8((uint16_t)(ix + 0x3Eu)));
			z80_write8((uint16_t)(ix + 0x33u), z80_read8((uint16_t)(ix + 0x3Fu)));
			continue;
		case 0x00482Du:
			z80_block(33);
			t2 = z80_read8((uint16_t)(ix + 0x31u));
			z80_write8((uint16_t)(ix + 0x31u), t2 - 1u);
			if (t2 == 1u)
				continue;
			z80_block(86);
			z80_write8((uint16_t)(ix + 0x3Eu), z80_read8((uint16_t)(ix + 0x32u)));
			z80_write8((uint16_t)(ix + 0x3Fu), z80_read8((uint16_t)(ix + 0x33u)));
			continue;
		case 0x004842u:
			z80_block(17);
			a = next_track_byte(ix);
			z80_block(105);
			z80_write8((uint16_t)(ix + 0x34u), a);
			z80_write8((uint16_t)(ix + 0x35u), z80_read8((uint16_t)(ix + 0x3Eu)));
			z80_write8((uint16_t)(ix + 0x36u), z80_read8((uint16_t)(ix + 0x3Fu)));
			continue;
		case 0x004857u:
			z80_block(33);
			t3 = z80_read8((uint16_t)(ix + 0x34u));
			z80_write8((uint16_t)(ix + 0x34u), t3 - 1u);
			if (t3 == 1u)
				continue;
			z80_block(86);
			z80_write8((uint16_t)(ix + 0x3Eu), z80_read8((uint16_t)(ix + 0x35u)));
			z80_write8((uint16_t)(ix + 0x3Fu), z80_read8((uint16_t)(ix + 0x36u)));
			continue;
		case 0x00486Cu:
			z80_block(17);
			a = next_track_byte(ix);
			z80_block(112);
			z80_write8((uint16_t)(ix + 0x37u), a);
			hl = z80_read16((uint16_t)(ix + 0x3Eu));
			z80_write16((uint16_t)(ix + 0x38u), hl);
			a = next_track_byte(ix);
			z80_block(21);
			c = a;
			a = next_track_byte(ix);
			z80_block(48);
			z80_write8((uint16_t)(ix + 0x3Eu), c);
			z80_write8((uint16_t)(ix + 0x3Fu), a);
			continue;
		case 0x00488Eu:
			z80_block(93);
			hl = z80_read16((uint16_t)(ix + 0x38u));
			z80_write16((uint16_t)(ix + 0x3Eu), hl);
			a = next_track_byte(ix);
			z80_block(21);
			c = a;
			a = next_track_byte(ix);
			z80_block(33);
			t4 = z80_read8((uint16_t)(ix + 0x37u));
			z80_write8((uint16_t)(ix + 0x37u), t4 - 1u);
			if (t4 == 1u)
				continue;
			z80_block(48);
			z80_write8((uint16_t)(ix + 0x3Eu), c);
			z80_write8((uint16_t)(ix + 0x3Fu), a);
			continue;
		case 0x0048B0u:
			z80_block(10);
			return sound_reset();
		case 0x0048B3u:
			z80_block(10);
			return sound_reset();
		case 0x0048B6u:
			z80_block(17);
			a = next_track_byte(ix);
			z80_block(49);
			z80_write8((uint16_t)(ix + 0x11u), a);
			if (z80_read8((uint16_t)(ix + 0x41u)) >> 7 == 0u)
				continue;
			z80_block(29);
			z80_write8((uint16_t)(ix + 0x42u), a);
			continue;
		case 0x0048C9u:
			z80_block(51);
			z80_write8((uint16_t)(ix + 0x10u), 0u);
			if (z80_read8((uint16_t)(ix + 0x41u)) >> 7 == 0u)
			{
				z80_cycles(6);
				return ix;
			}
			z80_block(48);
			z80_write8((uint16_t)(ix + 0x41u), 0u);
			z80_write8((uint16_t)(ix + 0x42u), 0u);
			return ix;
		}
	}
	z80_block(63);
	z80_write8((uint16_t)(ix + 0x3Cu), 1u);
	z80_write8((uint16_t)(ix + 0x3Du), 0u);
	if (z80_read8((uint16_t)(ix + 0x41u)) >> 7 == 0u)
	{
		z80_cycles(6);
		return ix;
	}
	z80_block(10);
	key_off(ix);
	return ix;
}

/* a note's pitch envelope, segment 1: every +24 passes the pitch by +1D, +1E times */
void music_pitch_envelope_1(uint16_t ix)
{
	uint8_t d = 0, e = 0, h = 0, l = 0;
	uint16_t hl = 0;
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	z80_block(17);
	music_note_tick(ix);
	z80_block(28);
	if (z80_read8((uint16_t)(ix + 0x2Au)) == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(28);
	t1 = z80_read8((uint16_t)(ix + 0x2Au));
	z80_write8((uint16_t)(ix + 0x2Au), t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(82);
	z80_write8((uint16_t)(ix + 0x2Au), z80_read8((uint16_t)(ix + 0x24u)));
	e = z80_read8((uint16_t)(ix + 0x1Du));
	d = 0u;
	if (e >> 7)
	{
		z80_block(4);
		d--;
	}
	z80_block(104);
	t2 = z80_read16((uint16_t)(ix + 0x2Cu)) + (((uint32_t)d << 8) | e);
	h = (uint8_t)(t2 >> 8);
	l = (uint8_t)t2;
	z80_write8((uint16_t)(ix + 0x2Cu), l);
	z80_write8((uint16_t)(ix + 0x2Du), h);
	hl = ((uint32_t)h << 8) | l;
	set_pitch(hl, ix);
	z80_block(28);
	t3 = z80_read8((uint16_t)(ix + 0x2Bu));
	z80_write8((uint16_t)(ix + 0x2Bu), t3 - 1u);
	if (t3 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(58);
	z80_write8((uint16_t)(ix + 0x2Bu), z80_read8((uint16_t)(ix + 0x1Eu)));
	hl = music_pitch_envelope_2_ADDRESS;
	set_channel_handler(hl, ix);
}

/* segment 2: by +1F, +20 times */
void music_pitch_envelope_2(uint16_t ix)
{
	uint8_t d = 0, e = 0, h = 0, l = 0;
	uint16_t hl = 0;
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	z80_block(17);
	music_note_tick(ix);
	z80_block(28);
	if (z80_read8((uint16_t)(ix + 0x2Au)) == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(28);
	t1 = z80_read8((uint16_t)(ix + 0x2Au));
	z80_write8((uint16_t)(ix + 0x2Au), t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(82);
	z80_write8((uint16_t)(ix + 0x2Au), z80_read8((uint16_t)(ix + 0x24u)));
	e = z80_read8((uint16_t)(ix + 0x1Fu));
	d = 0u;
	if (e >> 7)
	{
		z80_block(4);
		d--;
	}
	z80_block(104);
	t2 = z80_read16((uint16_t)(ix + 0x2Cu)) + (((uint32_t)d << 8) | e);
	h = (uint8_t)(t2 >> 8);
	l = (uint8_t)t2;
	z80_write8((uint16_t)(ix + 0x2Cu), l);
	z80_write8((uint16_t)(ix + 0x2Du), h);
	hl = ((uint32_t)h << 8) | l;
	set_pitch(hl, ix);
	z80_block(28);
	t3 = z80_read8((uint16_t)(ix + 0x2Bu));
	z80_write8((uint16_t)(ix + 0x2Bu), t3 - 1u);
	if (t3 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(58);
	z80_write8((uint16_t)(ix + 0x2Bu), z80_read8((uint16_t)(ix + 0x20u)));
	hl = music_pitch_envelope_3_ADDRESS;
	set_channel_handler(hl, ix);
}

/* segment 3: by +21, +22 times */
void music_pitch_envelope_3(uint16_t ix)
{
	uint8_t d = 0, e = 0, h = 0, l = 0;
	uint16_t hl = 0;
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	z80_block(17);
	music_note_tick(ix);
	z80_block(28);
	if (z80_read8((uint16_t)(ix + 0x2Au)) == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(28);
	t1 = z80_read8((uint16_t)(ix + 0x2Au));
	z80_write8((uint16_t)(ix + 0x2Au), t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(82);
	z80_write8((uint16_t)(ix + 0x2Au), z80_read8((uint16_t)(ix + 0x24u)));
	e = z80_read8((uint16_t)(ix + 0x21u));
	d = 0u;
	if (e >> 7)
	{
		z80_block(4);
		d--;
	}
	z80_block(104);
	t2 = z80_read16((uint16_t)(ix + 0x2Cu)) + (((uint32_t)d << 8) | e);
	h = (uint8_t)(t2 >> 8);
	l = (uint8_t)t2;
	z80_write8((uint16_t)(ix + 0x2Cu), l);
	z80_write8((uint16_t)(ix + 0x2Du), h);
	hl = ((uint32_t)h << 8) | l;
	set_pitch(hl, ix);
	z80_block(28);
	t3 = z80_read8((uint16_t)(ix + 0x2Bu));
	z80_write8((uint16_t)(ix + 0x2Bu), t3 - 1u);
	if (t3 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(58);
	z80_write8((uint16_t)(ix + 0x2Bu), z80_read8((uint16_t)(ix + 0x22u)));
	hl = music_pitch_envelope_4_ADDRESS;
	set_channel_handler(hl, ix);
}

/* segment 4: by +23, then music_note_tick */
void music_pitch_envelope_4(uint16_t ix)
{
	uint8_t d = 0, e = 0, h = 0, l = 0;
	uint16_t hl = 0;
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	z80_block(17);
	music_note_tick(ix);
	z80_block(28);
	if (z80_read8((uint16_t)(ix + 0x2Au)) == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(28);
	t1 = z80_read8((uint16_t)(ix + 0x2Au));
	z80_write8((uint16_t)(ix + 0x2Au), t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(82);
	z80_write8((uint16_t)(ix + 0x2Au), z80_read8((uint16_t)(ix + 0x24u)));
	e = z80_read8((uint16_t)(ix + 0x23u));
	d = 0u;
	if (e >> 7)
	{
		z80_block(4);
		d--;
	}
	z80_block(104);
	t2 = z80_read16((uint16_t)(ix + 0x2Cu)) + (((uint32_t)d << 8) | e);
	h = (uint8_t)(t2 >> 8);
	l = (uint8_t)t2;
	z80_write8((uint16_t)(ix + 0x2Cu), l);
	z80_write8((uint16_t)(ix + 0x2Du), h);
	hl = ((uint32_t)h << 8) | l;
	set_pitch(hl, ix);
	z80_block(28);
	t3 = z80_read8((uint16_t)(ix + 0x2Bu));
	z80_write8((uint16_t)(ix + 0x2Bu), t3 - 1u);
	if (t3 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(20);
	hl = music_note_tick_ADDRESS;
	set_channel_handler(hl, ix);
}

/* a music note's handler: the LFO's ramp (+2E, +2F into the PMS and AMS), the fade's volume, and key off
   when the note's gate time (+3C) runs out */
void music_note_tick(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl = 0;
	uint8_t t1 = 0;

	z80_block(33);
	if (z80_read8((uint16_t)(ix + 0x2Eu)) != 0u)
	{
		z80_block(33);
		t1 = z80_read8((uint16_t)(ix + 0x2Eu));
		z80_write8((uint16_t)(ix + 0x2Eu), t1 - 1u);
		if (t1 == 1u)
		{
			z80_block(59);
			z80_write8((uint16_t)(ix + 0x2Fu), z80_read8((uint16_t)(ix + 0x2Fu)) + 1u);
			a = z80_read8((uint16_t)(ix + 0x2Fu));
			set_channel_pm_sensitivity(ix, a);
			z80_block(44);
			a = z80_read8((uint16_t)(ix + 0x2Fu)) >> 1;
			set_channel_am_sensitivity(ix, a);
			z80_block(36);
			if (z80_read8((uint16_t)(ix + 0x2Fu)) != 7u)
			{
				z80_block(38);
				z80_write8((uint16_t)(ix + 0x2Eu), z80_read8((uint16_t)(ix + 0x1Bu)));
			}
		}
	}
	z80_block(44);
	if ((pass_count & 0xFu) != z80_read8((uint16_t)(ix + 0x40u)))
	{
		z80_cycles(6);
		return;
	}
	z80_block(27);
	if (fade != 0u)
	{
		z80_cycles(7);
		update_music_volume(ix);
	}
	z80_block(92);
	hl = z80_read16((uint16_t)(ix + 0x3Au));
	carry = (uint16_t)(hl + z80_read16((uint16_t)(ix + 0x3Cu))) < hl;
	if (carry == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	key_off(ix);
}

/* the length of the note's high nibble (note_lengths) into the track's time (+3A) */
uint32_t add_note_length(uint8_t bc, uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t de = 0, hl = 0;

	z80_block(172);
	a = bc & 0xF0u;
	a = (a >> 1) | ((uint32_t)a << 7);
	a = (a >> 1) | ((uint32_t)a << 7);
	hl = note_lengths_ADDRESS + (uint8_t)((a >> 1) | ((uint32_t)a << 7));
	de = SOUND_ROM16(hl);
	hl = z80_read16((uint16_t)(ix + 0x3Au));
	carry = (uint16_t)(hl + de) < hl;
	hl += de;
	z80_write16((uint16_t)(ix + 0x3Au), hl);
	return carry;
}

/* the note's gate time (+3C): the gate ratio (+14) of the time left */
void set_note_gate(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0, d = 0, e = 0;
	uint16_t hl = 0;
	uint8_t t1 = 0;

	z80_block(43);
	hl = 0u;
	a = z80_read8((uint16_t)(ix + 0x14u));
	if (a == 0u)
	{
		z80_block(48);
		z80_write16((uint16_t)(ix + 0x3Cu), hl);
		return;
	}
	z80_block(78);
	hl -= z80_read16((uint16_t)(ix + 0x3Au));
	d = (uint8_t)(hl >> 8);
	e = (uint8_t)hl;
	hl = 0u;
	b = 8u;
	for (;;)
	{
		z80_block(30);
		carry = d & 1u;
		d = d >> 1;
		e = (e >> 1) | (carry << 7);
		t1 = a;
		a = ((uint32_t)t1 << 1) | (t1 >> 7);
		if (t1 >> 7)
		{
			z80_block(11);
			hl += ((uint32_t)d << 8) | e;
		}
		z80_block(8);
		b--;
		if (b == 0u)
			break;
		z80_cycles(5);
	}
	z80_block(18);
	if ((uint8_t)(hl | (hl >> 8)) == 0u)
	{
		z80_block(6);
		hl++;
	}
	z80_block(48);
	z80_write16((uint16_t)(ix + 0x3Cu), hl);
}

/* set_music_volume with the record's music volume (+17) */
void update_music_volume(uint16_t ix)
{
	uint8_t a = 0;

	z80_block(19);
	a = z80_read8((uint16_t)(ix + 0x17u));
	set_music_volume(ix, a);
}

/* A plus the fade (F3CB) as the record's volume (at most 7F) */
void set_music_volume(uint16_t ix, uint8_t a)
{
	uint8_t a_2 = 0;
	uint8_t t1 = 0;

	z80_block(31);
	t1 = fade_attenuation + a;
	a_2 = t1;
	if ((int8_t)t1 >= 0)
	{
		set_volume(ix, a_2);
		return;
	}
	z80_block(17);
	a_2 = 0x7Fu;
	set_volume(ix, a_2);
}

/* the track's next byte (+3E) */
uint8_t next_track_byte(uint16_t ix)
{
	uint8_t a = 0, h = 0, l = 0;
	uint16_t t1 = 0;

	z80_block(99);
	l = z80_read8((uint16_t)(ix + 0x3Eu));
	h = z80_read8((uint16_t)(ix + 0x3Fu));
	a = z80_read8((uint16_t)(((uint32_t)h << 8) | l));
	t1 = (((uint32_t)h << 8) | l) + 1u;
	z80_write16((uint16_t)(ix + 0x3Eu), t1);
	return a;
}

/* the record's handler channel_idle, the note left ringing: a drum routine's end */
void drum_done(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(20);
	hl = channel_idle_ADDRESS;
	set_channel_handler(hl, ix);
}
