/**
 *    Name:        chips.c
 *    Description: the records' handlers and the chips: the YM2151's registers, patches, volumes, pitches, keys, LFO and pan; the K053260's voices
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    06-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the Z80 sound program decompiled into C by
 *    tools/decompile_sound.py, with the names of sound_symbols.txt.
 */
#include "sound.h"

/* key off, the fastest release, the record's sound and priority 0, its handler channel_idle */
void stop_channel(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(17);
	key_off(ix);
	z80_block(17);
	fast_release(ix);
	z80_block(48);
	z80_write8((uint16_t)(ix + 0x41u), 0u);
	z80_write8((uint16_t)(ix + 0x42u), 0u);
	hl = channel_idle_ADDRESS;
	set_channel_handler(hl, ix);
}

/* HL into the record's handler (+43) */
void set_channel_handler(uint16_t hl, uint16_t ix)
{
	z80_block(38);
	z80_write16((uint16_t)(ix + 0x43u), hl);
	channel_idle();
}

/* a free record's handler: RET */
void channel_idle(void)
{
	z80_block(10);
}

/* YM2151 register B plus the record's chip channel (+40) = C */
void write_fm_channel_register(uint16_t bc, uint16_t ix)
{
	z80_block(27);
	bc = (bc & 0xFFu) | ((uint32_t)(uint8_t)(z80_read8((uint16_t)(ix + 0x40u)) + (bc >> 8)) << 8);
	write_fm_register(bc);
}

/* YM2151 register B = C, each write after the busy flag (F801 bit 7) clears */
void write_fm_register(uint16_t bc)
{
	for (;;)
	{
		z80_block(27);
		if ((z80_read8(FM_F801) & 0x80u) == 0u)
			break;
		z80_cycles(5);
	}
	z80_block(17);
	z80_write8(FM_F800, bc >> 8);
	for (;;)
	{
		z80_block(27);
		if ((z80_read8(FM_F801) & 0x80u) == 0u)
			break;
		z80_cycles(5);
	}
	z80_block(27);
	z80_write8(FM_F801, (uint8_t)bc);
}

/* YM2151 timer B (register 12 = F9) restarted and its flag cleared (register 14): the main loop's tick */
void restart_frame_timer(void)
{
	uint16_t bc = 0;

	z80_block(27);
	bc = 0x1420u;
	write_fm_register(bc);
	z80_block(27);
	bc = 0x12F9u;
	write_fm_register(bc);
	z80_block(20);
	bc = 0x140Au;
	write_fm_register(bc);
}

/* the patch at HL into the record's chip channel: an FM one's 25 bytes (algorithm, the operators'
   registers), or a PCM one's sample and two bytes */
void load_patch(uint16_t hl, uint16_t ix)
{
	uint8_t a = 0, c = 0;
	uint16_t bc = 0, hl_2 = 0;
	uint16_t saved_hl = 0;

	z80_block(36);
	if (z80_read8((uint16_t)(ix + 0x40u)) >= 8u)
	{
		z80_block(255);
		a = pcm_keys & z80_read8((uint16_t)(ix + 0x4Cu));
		pcm_keys = a;
		z80_write8(PCM_FC28, a);
		saved_hl = hl;
		hl_2 = z80_read8(hl) * 2u * 2u * 2u + samples_ADDRESS;
		move_block(hl_2, z80_read16((uint16_t)(ix + 0x4Au)), 7u, 1u);
		a = pcm_loops & z80_read8((uint16_t)(ix + 0x4Eu));
		if (SOUND_ROM8(hl_2 + 7u) & 1u)
		{
			z80_block(19);
			a |= z80_read8((uint16_t)(ix + 0x4Fu));
		}
		z80_block(110);
		pcm_loops = a;
		z80_write8(PCM_FC2A, a);
		hl_2 = saved_hl + 1u;
		z80_write8((uint16_t)(ix + 0x46u), z80_read8(hl_2));
		z80_write8((uint16_t)(ix + 0x47u), z80_read8((uint16_t)(hl_2 + 1u)));
		update_volume(ix);
		return;
	}
	z80_block(17);
	key_off(ix);
	z80_block(17);
	fast_release(ix);
	z80_block(50);
	c = z80_read8(hl);
	z80_write8((uint16_t)(ix + 0x46u), c);
	bc = 0x2000u | c;
	write_fm_channel_register(bc, ix);
	z80_block(37);
	hl++;
	bc = 0x4000u | z80_read8(hl);
	write_fm_channel_register(bc, ix);
	z80_block(69);
	hl++;
	z80_write8((uint16_t)(ix + 0x47u), z80_read8(hl));
	hl++;
	bc = 0x8000u | z80_read8(hl);
	write_fm_channel_register(bc, ix);
	z80_block(37);
	hl++;
	bc = 0xA000u | z80_read8(hl);
	write_fm_channel_register(bc, ix);
	z80_block(37);
	hl++;
	bc = 0xC000u | z80_read8(hl);
	write_fm_channel_register(bc, ix);
	z80_block(56);
	hl++;
	c = z80_read8(hl);
	z80_write8((uint16_t)(ix + 0x4Bu), c);
	bc = 0xE000u | c;
	write_fm_channel_register(bc, ix);
	z80_block(37);
	hl++;
	bc = 0x5000u | z80_read8(hl);
	write_fm_channel_register(bc, ix);
	z80_block(69);
	hl++;
	z80_write8((uint16_t)(ix + 0x48u), z80_read8(hl));
	hl++;
	bc = 0x9000u | z80_read8(hl);
	write_fm_channel_register(bc, ix);
	z80_block(37);
	hl++;
	bc = 0xB000u | z80_read8(hl);
	write_fm_channel_register(bc, ix);
	z80_block(37);
	hl++;
	bc = 0xD000u | z80_read8(hl);
	write_fm_channel_register(bc, ix);
	z80_block(56);
	hl++;
	c = z80_read8(hl);
	z80_write8((uint16_t)(ix + 0x4Cu), c);
	bc = 0xF000u | c;
	write_fm_channel_register(bc, ix);
	z80_block(37);
	hl++;
	bc = 0x4800u | z80_read8(hl);
	write_fm_channel_register(bc, ix);
	z80_block(69);
	hl++;
	z80_write8((uint16_t)(ix + 0x49u), z80_read8(hl));
	hl++;
	bc = 0x8800u | z80_read8(hl);
	write_fm_channel_register(bc, ix);
	z80_block(37);
	hl++;
	bc = 0xA800u | z80_read8(hl);
	write_fm_channel_register(bc, ix);
	z80_block(37);
	hl++;
	bc = 0xC800u | z80_read8(hl);
	write_fm_channel_register(bc, ix);
	z80_block(56);
	hl++;
	c = z80_read8(hl);
	z80_write8((uint16_t)(ix + 0x4Du), c);
	bc = 0xE800u | c;
	write_fm_channel_register(bc, ix);
	z80_block(37);
	hl++;
	bc = 0x5800u | z80_read8(hl);
	write_fm_channel_register(bc, ix);
	z80_block(69);
	hl++;
	z80_write8((uint16_t)(ix + 0x4Au), z80_read8(hl));
	hl++;
	bc = 0x9800u | z80_read8(hl);
	write_fm_channel_register(bc, ix);
	z80_block(37);
	hl++;
	bc = 0xB800u | z80_read8(hl);
	write_fm_channel_register(bc, ix);
	z80_block(37);
	hl++;
	bc = 0xD800u | z80_read8(hl);
	write_fm_channel_register(bc, ix);
	z80_block(56);
	c = z80_read8((uint16_t)(hl + 1u));
	z80_write8((uint16_t)(ix + 0x4Eu), c);
	bc = 0xF800u | c;
	write_fm_channel_register(bc, ix);
	z80_block(10);
	update_volume(ix);
}

/* A into the record's volume (+45), then update_volume */
void set_volume(uint16_t ix, uint8_t a)
{
	z80_block(19);
	z80_write8((uint16_t)(ix + 0x45u), a);
	update_volume(ix);
}

/* the volume to the chip: an FM channel's carriers' total levels (carrier_masks by the algorithm), a PCM
   voice's volume register */
void update_volume(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t bc = 0, hl = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(36);
	if (z80_read8((uint16_t)(ix + 0x40u)) < 8u)
	{
		z80_block(108);
		hl = carrier_masks[z80_read8((uint16_t)(ix + 0x46u)) & 7u];
		a = z80_read8((uint16_t)(ix + 0x47u));
		bc = 0x6000u;
		hl = write_operator_level(bc, hl, ix, a);
		z80_block(43);
		a = z80_read8((uint16_t)(ix + 0x49u));
		bc = 0x6800u;
		hl = write_operator_level(bc, hl, ix, a);
		z80_block(43);
		a = z80_read8((uint16_t)(ix + 0x48u));
		bc = 0x7000u;
		hl = write_operator_level(bc, hl, ix, a);
		z80_block(26);
		a = z80_read8((uint16_t)(ix + 0x4Au));
		bc = 0x7800u;
		write_operator_level(bc, hl, ix, a);
		return;
	}
	z80_block(48);
	t1 = z80_read8((uint16_t)(ix + 0x45u)) + z80_read8((uint16_t)(ix + 0x46u));
	a = t1;
	if ((int8_t)t1 < 0)
	{
		z80_block(7);
		a = 0x7Fu;
	}
	z80_block(29);
	t2 = a + z80_read8((uint16_t)(ix + 0x48u));
	a = t2;
	if ((int8_t)t2 < 0)
	{
		z80_block(7);
		a = 0x7Fu;
	}
	z80_block(28);
	a = ~a & 0x7Fu;
	if (a < 4u)
	{
		z80_block(4);
		a = 0u;
	}
	z80_block(76);
	z80_write8((uint16_t)(z80_read16((uint16_t)(ix + 0x4Au)) + 7u), a);
}

/* an FM operator's total level, with the record's volume added when it is a carrier */
uint16_t write_operator_level(uint16_t bc, uint16_t hl, uint16_t ix, uint8_t a)
{
	uint32_t carry = 0;
	uint8_t l = 0;
	uint16_t bc_2 = 0, hl_2 = 0;
	uint8_t t1 = 0;

	l = (uint8_t)hl;
	z80_block(18);
	carry = l >> 7;
	l = (uint32_t)l << 1;
	if (carry)
	{
		z80_block(29);
		t1 = a + z80_read8((uint16_t)(ix + 0x45u));
		a = t1;
		if ((int8_t)t1 < 0)
		{
			z80_block(7);
			a = 0x7Fu;
		}
	}
	z80_block(14);
	bc_2 = (bc & ~0xFFu) | a;
	hl_2 = (hl & ~0xFFu) | l;
	write_fm_channel_register(bc_2, ix);
	return hl_2;
}

/* HL to the record's channel: an FM one's key fraction and key code (note_codes), a PCM voice's pitch
   registers */
void set_pitch(uint16_t hl, uint16_t ix)
{
	uint8_t a = 0;
	uint16_t bc = 0, de = 0, hl_2 = 0;
	uint8_t t1 = 0;

	z80_block(36);
	if (z80_read8((uint16_t)(ix + 0x40u)) >= 8u)
	{
		z80_block(72);
		de = hl;
		hl_2 = z80_read16((uint16_t)(ix + 0x4Au));
		z80_write16(hl_2, de);
		return;
	}
	z80_block(11);
	a = (hl >> 8) & 0x1Fu;
	do
	{
		z80_block(17);
		t1 = a;
		a = t1 - 0x18u;
	} while (t1 >= 0x18u);
	z80_block(61);
	hl = ((hl & 0xFFu) | ((uint32_t)(uint8_t)(a + 0x18u) << 8)) * 2u * 2u;
	bc = 0x3000u | (uint8_t)hl;
	write_fm_channel_register(bc, ix);
	z80_block(56);
	bc = 0x2800u | note_codes[hl >> 8];
	write_fm_channel_register(bc, ix);
}

/* an FM channel's operators on (register 08); a PCM voice keyed off, FA00 armed, HALT until the
   K053260's NMI, then keyed on, its volume back to full */
void key_on(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t bc = 0;

	z80_block(36);
	a = z80_read8((uint16_t)(ix + 0x40u));
	if (a < 8u)
	{
		z80_block(28);
		bc = 0x800u | a | 0x78u;
		write_fm_register(bc);
		return;
	}
	z80_block(37);
	if ((pcm_keyed & z80_read8((uint16_t)(ix + 0x4Du))) != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(165);
	a = pcm_keys & z80_read8((uint16_t)(ix + 0x4Cu));
	pcm_keys = a;
	z80_write8(PCM_FC28, a);
	pcm_keyed |= z80_read8((uint16_t)(ix + 0x4Du));
	a = pcm_keys | z80_read8((uint16_t)(ix + 0x4Du));
	pcm_keys = a;
	z80_write8(NMI_ARM_FA00, a);
	z80_halt();
	z80_block(42);
	z80_write8(PCM_FC28, a);
	z80_write8((uint16_t)(ix + 0x48u), 0u);
	update_volume(ix);
}

/* an FM channel's operators off (register 08); a PCM voice's key bit cleared */
void key_off(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t bc = 0;

	z80_block(36);
	a = z80_read8((uint16_t)(ix + 0x40u));
	if (a < 8u)
	{
		z80_block(21);
		bc = 0x800u | a;
		write_fm_register(bc);
		return;
	}
	z80_block(37);
	if ((pcm_keyed & z80_read8((uint16_t)(ix + 0x4Du))) == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(55);
	pcm_keyed &= z80_read8((uint16_t)(ix + 0x4Cu));
}

/* an FM channel's operators' release at their fastest (E0-F8 = FF); a PCM record's volume down to 7F */
void fast_release(uint16_t ix)
{
	uint16_t bc = 0;

	z80_block(36);
	if (z80_read8((uint16_t)(ix + 0x40u)) >= 8u)
	{
		z80_block(29);
		z80_write8((uint16_t)(ix + 0x48u), 0x7Fu);
		return;
	}
	z80_block(31);
	bc = 0xE0FFu;
	write_fm_channel_register(bc, ix);
	z80_block(31);
	bc = 0xF0FFu;
	write_fm_channel_register(bc, ix);
	z80_block(31);
	bc = 0xE8FFu;
	write_fm_channel_register(bc, ix);
	z80_block(24);
	bc = 0xF8FFu;
	write_fm_channel_register(bc, ix);
}

/* Unused: the FM channel's release rates back from +4B-+4E */
void unused_0F06(uint16_t ix)
{
	uint16_t bc = 0;

	z80_block(31);
	if (z80_read8((uint16_t)(ix + 0x40u)) >= 8u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(43);
	bc = 0xE000u | z80_read8((uint16_t)(ix + 0x4Bu));
	write_fm_channel_register(bc, ix);
	z80_block(43);
	bc = 0xF000u | z80_read8((uint16_t)(ix + 0x4Cu));
	write_fm_channel_register(bc, ix);
	z80_block(43);
	bc = 0xE800u | z80_read8((uint16_t)(ix + 0x4Du));
	write_fm_channel_register(bc, ix);
	z80_block(36);
	bc = 0xF800u | z80_read8((uint16_t)(ix + 0x4Eu));
	write_fm_channel_register(bc, ix);
}

/* YM2151 register 19 with bit 7: the LFO's phase modulation depth */
void set_lfo_pm_depth(uint8_t a)
{
	uint16_t bc = 0;

	z80_block(28);
	bc = 0x1900u | a | 0x80u;
	write_fm_register(bc);
}

/* YM2151 register 19 without bit 7: the LFO's amplitude modulation depth */
void set_lfo_am_depth(uint8_t a)
{
	uint16_t bc = 0;

	z80_block(28);
	bc = 0x1900u | (a & 0x7Fu);
	write_fm_register(bc);
}

/* an FM channel's PMS (register 38 bits 4-6), kept in +4F */
void set_channel_pm_sensitivity(uint16_t ix, uint8_t a)
{
	uint8_t a_2 = 0, c = 0;
	uint16_t bc = 0;

	z80_block(58);
	a &= 7u;
	a = ((uint32_t)a << 1) | (a >> 7);
	a = ((uint32_t)a << 1) | (a >> 7);
	a = ((uint32_t)a << 1) | (a >> 7);
	c = ((uint32_t)a << 1) | (a >> 7);
	if (z80_read8((uint16_t)(ix + 0x40u)) >= 8u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(70);
	a_2 = (z80_read8((uint16_t)(ix + 0x4Fu)) & 3u) | c;
	z80_write8((uint16_t)(ix + 0x4Fu), a_2);
	bc = 0x3800u | a_2;
	write_fm_channel_register(bc, ix);
}

/* an FM channel's AMS (register 38 bits 0-1), kept in +4F */
void set_channel_am_sensitivity(uint16_t ix, uint8_t a)
{
	uint8_t a_2 = 0, c = 0;
	uint16_t bc = 0;

	z80_block(42);
	c = a & 3u;
	if (z80_read8((uint16_t)(ix + 0x40u)) >= 8u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(70);
	a_2 = (z80_read8((uint16_t)(ix + 0x4Fu)) & 0x70u) | c;
	z80_write8((uint16_t)(ix + 0x4Fu), a_2);
	bc = 0x3800u | a_2;
	write_fm_channel_register(bc, ix);
}

/* YM2151 register 18: the LFO's frequency */
void set_lfo_frequency(uint8_t a)
{
	uint16_t bc = 0;

	z80_block(21);
	bc = 0x1800u | a;
	write_fm_register(bc);
}

/* YM2151 register 1B: the LFO's waveform */
void set_lfo_waveform(uint8_t a)
{
	uint16_t bc = 0;

	z80_block(21);
	bc = 0x1B00u | a;
	write_fm_register(bc);
}

/* an FM channel's left and right (register 20 bits 6-7, kept in +46); a PCM voice's pan (FC2C-FC2D, kept
   in F3C5-F3C6) */
void set_pan(uint16_t ix, uint8_t a)
{
	uint8_t a_2 = 0, c = 0;
	uint16_t bc = 0;

	z80_block(40);
	c = a;
	a_2 = z80_read8((uint16_t)(ix + 0x40u));
	if (a_2 >= 8u)
	{
		z80_block(10);
		if (a_2 == 8u)
		{
			z80_block(60);
			a_2 = (pcm_pans_1 & 0x38u) | c;
			pcm_pans_1 = a_2;
			z80_write8(PCM_FC2C, a_2);
			return;
		}
		z80_block(17);
		if (a_2 == 9u)
		{
			z80_block(84);
			a_2 = (pcm_pans_1 & 7u) | ((((uint32_t)c << 1) << 1) << 1);
			pcm_pans_1 = a_2;
			z80_write8(PCM_FC2C, a_2);
			return;
		}
		z80_block(17);
		if (a_2 == 0xAu)
		{
			z80_block(60);
			a_2 = (pcm_pans_2 & 0x38u) | c;
			pcm_pans_2 = a_2;
			z80_write8(PCM_FC2D, a_2);
			return;
		}
		z80_block(84);
		a_2 = (pcm_pans_2 & 7u) | ((((uint32_t)c << 1) << 1) << 1);
		pcm_pans_2 = a_2;
		z80_write8(PCM_FC2D, a_2);
		return;
	}
	z80_block(86);
	c = (c >> 1) | ((uint32_t)c << 7);
	a_2 = (z80_read8((uint16_t)(ix + 0x46u)) & 0x3Fu) | (c >> 1) | ((uint32_t)c << 7);
	z80_write8((uint16_t)(ix + 0x46u), a_2);
	bc = 0x2000u | a_2;
	write_fm_channel_register(bc, ix);
}

/* on FM channel 7: the noise off (register 0F = 0) */
void noise_off(uint16_t ix)
{
	uint16_t bc = 0;

	z80_block(31);
	if (z80_read8((uint16_t)(ix + 0x40u)) != 7u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(24);
	bc = 0xF00u;
	write_fm_register(bc);
}

/* Unused: on FM channel 7, the noise on at frequency A (register 0F) */
void unused_0FF2(uint16_t ix, uint8_t a)
{
	uint8_t c = 0;
	uint16_t bc = 0;

	z80_block(42);
	c = a | 0x80u;
	if (z80_read8((uint16_t)(ix + 0x40u)) != 7u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(17);
	bc = 0xF00u | c;
	write_fm_register(bc);
}

/* a PCM record's voice's bit of the K053260's status (FC29); nothing for an FM record */
uint32_t pcm_voice_playing(uint16_t ix)
{
	uint32_t zero = 0;
	uint8_t a = 0;

	z80_block(31);
	a = z80_read8((uint16_t)(ix + 0x40u));
	zero = (uint8_t)(a - 8u) == 0u;
	if (a < 8u)
	{
		z80_cycles(6);
		return zero;
	}
	z80_block(42);
	zero = (z80_read8(PCM_FC29) & z80_read8((uint16_t)(ix + 0x4Du))) == 0u;
	return zero;
}

/* Unused: the next byte at the pointer F3C8 (0100 on: the program's own bytes) */
void unused_100D(void)
{
	uint16_t hl = 0;

	z80_block(53);
	hl = byte_pointer;
	byte_pointer = (hl & ~0xFFu) | (uint8_t)(hl + 1u);
}
