/**
 *    Name:        pcm_effects.c
 *    Description: the PCM effects (commands 40-7E, and 3F by its argument): samples of the K053260
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    07-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the Z80 sound program decompiled into C by
 *    tools/decompile_sound.py, with the names of sound_symbols.txt.
 */
#include "sound.h"

void pcm_effect_3f_00(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x2EB5u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_00_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_00_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_01(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x2ED3u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_01_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_01_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_02(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x2EF1u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_02_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_02_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_03(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x2F0Fu;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_03_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_03_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_04(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x2F2Du;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_04_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_04_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_05(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x2F4Bu;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_05_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_05_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_06(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x2F69u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_06_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_06_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_07(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x2F87u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_07_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_07_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_08(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x2FA5u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_08_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_08_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_09(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x2FC3u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_09_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_09_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_0a(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x2FE1u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_0a_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_0a_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_0b(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x2FFFu;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_0b_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_0b_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_0c(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x301Du;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_0c_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_0c_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_0d(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x303Bu;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_0d_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_0d_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_0e(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3059u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_0e_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_0e_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_0f(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3077u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_0f_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_0f_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_10(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3095u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_10_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_10_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_11(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x30B3u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_11_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_11_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_12(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x30D1u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_12_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_12_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_13(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x30EFu;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_13_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_13_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_14(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x310Du;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_14_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_14_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_15(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x312Bu;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_15_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_15_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_16(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3149u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_16_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_16_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_17(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3167u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_17_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_17_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_18(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3185u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_18_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_18_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_19(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x31A3u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_19_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_19_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_1a(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x31C1u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_1a_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_1a_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_1b(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x31DFu;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_1b_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_1b_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_1c(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x31FDu;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_1c_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_1c_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_1d(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x321Bu;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_1d_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_1d_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_1e(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3239u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_1e_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_1e_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_1f(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3257u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_1f_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_1f_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_20(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3275u;
	load_patch(hl, ix);
	z80_block(24);
	a = 2u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_20_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_20_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_21(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3293u;
	load_patch(hl, ix);
	z80_block(24);
	a = 3u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_21_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_21_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_22(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x32B1u;
	load_patch(hl, ix);
	z80_block(24);
	a = 5u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_22_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_22_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_23(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x32CFu;
	load_patch(hl, ix);
	z80_block(24);
	a = 6u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_23_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_23_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_24(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x32EDu;
	load_patch(hl, ix);
	z80_block(24);
	a = 2u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_24_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_24_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_25(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x330Bu;
	load_patch(hl, ix);
	z80_block(24);
	a = 3u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_25_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_25_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_26(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3329u;
	load_patch(hl, ix);
	z80_block(24);
	a = 5u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_26_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_26_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_27(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3347u;
	load_patch(hl, ix);
	z80_block(24);
	a = 6u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_27_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_27_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_28(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3365u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_28_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_28_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_29(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3383u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_29_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_29_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_2a(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x33A1u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_2a_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_2a_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_2b(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x33BFu;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_2b_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_2b_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_2c(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x33DDu;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xEA0u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_2c_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_2c_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_2d(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3401u;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xE40u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_2d_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_2d_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_2e(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3425u;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xEE0u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_2e_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_2e_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_2f(uint16_t ix)
{
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_30(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x344Cu;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xEE0u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_30_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_30_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_31(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3470u;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xEE0u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_31_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_31_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_32(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3494u;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xEE0u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_32_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_32_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_33(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x34B8u;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xEE0u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_33_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_33_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_34(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x34DCu;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xEF0u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_34_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_34_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_35(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3500u;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xEF0u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_35_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_35_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_36(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3524u;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xEF0u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_36_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_36_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_37(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3548u;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xEF0u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_37_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_37_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_38(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x356Cu;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_38_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_38_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void unused_358A(uint16_t ix, uint8_t a)
{
	z80_block(17);
	set_volume(ix, a);
	z80_block(31);
	if (z80_read8(ix) != 0x7Fu)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_39(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3596u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_39_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_39_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_3a(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(27);
	hl = 0x35B4u;
	load_patch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_3a_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_3a_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_3f_3b(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(27);
	hl = 0x35D2u;
	load_patch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_3f_3b_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_3f_3b_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_42(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x36B6u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(20);
	hl = 0x36F9u;
	pcm_effect_42_setup(hl, ix);
}

void pcm_effect_41(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x36B3u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(20);
	hl = 0x36D9u;
	pcm_effect_42_setup(hl, ix);
}

void pcm_effect_40(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x36B0u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(10);
	hl = effect_steps_36b9_ADDRESS;
	pcm_effect_42_setup(hl, ix);
}

void pcm_effect_42_setup(uint16_t hl, uint16_t ix)
{
	uint16_t hl_2 = 0;

	z80_block(96);
	z80_write16(ix, hl);
	z80_write8((uint16_t)(ix + 2u), 1u);
	z80_write8((uint16_t)(ix + 3u), 0u);
	hl_2 = pcm_effect_42_retrigger_ADDRESS;
	set_channel_handler(hl_2, ix);
}

void pcm_effect_42_retrigger(uint16_t ix)
{
	uint32_t zero = 0;
	uint8_t d = 0, e = 0;
	uint16_t hl = 0;
	uint16_t saved_hl = 0;

	z80_block(17);
	zero = pcm_effect_42_update(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(82);
	hl = z80_read16(ix);
	e = z80_read8(hl);
	hl++;
	d = z80_read8(hl);
	hl++;
	if ((e | d) == 0u)
	{
		stop_channel(ix);
		return;
	}
	z80_block(32);
	saved_hl = hl;
	hl = ((uint32_t)d << 8) | e;
	set_pitch(hl, ix);
	z80_block(129);
	hl = saved_hl;
	e = z80_read8(hl);
	hl++;
	d = z80_read8(hl);
	hl++;
	z80_write8((uint16_t)(ix + 2u), e);
	z80_write8((uint16_t)(ix + 3u), d);
	z80_write16(ix, hl);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_42_setup_2_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_42_setup_2(uint16_t ix)
{
	uint32_t zero = 0;
	uint8_t d = 0, e = 0;
	uint16_t hl = 0;

	z80_block(17);
	zero = pcm_effect_42_update(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(157);
	hl = z80_read16(ix);
	e = z80_read8(hl);
	hl++;
	d = z80_read8(hl);
	hl++;
	z80_write8((uint16_t)(ix + 2u), e);
	z80_write8((uint16_t)(ix + 3u), d);
	z80_write16(ix, hl);
	key_off(ix);
	z80_block(20);
	hl = pcm_effect_42_retrigger_ADDRESS;
	set_channel_handler(hl, ix);
}

uint32_t pcm_effect_42_update(uint16_t ix)
{
	uint32_t zero = 0;
	uint8_t d = 0, e = 0;
	uint16_t t1 = 0;

	z80_block(100);
	t1 = z80_read16((uint16_t)(ix + 2u)) - 1u;
	d = (uint8_t)(t1 >> 8);
	e = (uint8_t)t1;
	z80_write8((uint16_t)(ix + 2u), e);
	z80_write8((uint16_t)(ix + 3u), d);
	zero = (e | d) == 0u;
	return zero;
}

void pcm_effect_43(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x37C2u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_43_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_43_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_44(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x37E0u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_44_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_44_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_45(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x37FEu;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_45_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_45_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_46(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x381Cu;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(39);
	z80_write8(ix, 4u);
	hl = pcm_effect_46_retrigger_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_46_retrigger(uint16_t ix)
{
	uint32_t zero = 0;
	uint8_t t1 = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(33);
	t1 = z80_read8(ix);
	z80_write8(ix, t1 - 1u);
	if (t1 == 1u)
	{
		stop_channel(ix);
		return;
	}
	z80_block(17);
	key_off(ix);
	z80_block(10);
	key_on(ix);
}

void pcm_effect_47(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3847u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_47_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_47_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_48(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3865u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_48_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_48_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_49(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3883u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_49_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_49_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_4a(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x38A1u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_4a_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_4a_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_4b(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x38BFu;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_4b_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_4b_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_4c(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x38DDu;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_4c_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_4c_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_4d(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x38FBu;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_4d_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_4d_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_4e(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3919u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_4e_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_4e_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_4f(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3937u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_4f_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_4f_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_50(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3955u;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xF00u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(43);
	a = 0x7Fu;
	z80_write8(ix, 0x7Fu);
	set_volume(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(39);
	z80_write8((uint16_t)(ix + 1u), 1u);
	hl = pcm_effect_50_fade_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_50_fade(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;
	uint8_t t1 = 0;

	z80_block(28);
	t1 = z80_read8((uint16_t)(ix + 1u));
	z80_write8((uint16_t)(ix + 1u), t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(78);
	z80_write8((uint16_t)(ix + 1u), 1u);
	z80_write8(ix, z80_read8(ix) - 1u);
	a = z80_read8(ix);
	set_volume(ix, a);
	z80_block(28);
	if (z80_read8(ix) != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(20);
	hl = pcm_effect_50_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_50_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_51(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x39A1u;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xF00u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_51_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_51_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_52(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x39C5u;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xF00u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(39);
	z80_write8(ix, 0x70u);
	hl = pcm_effect_52_delay_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_52_delay(uint16_t ix)
{
	uint16_t hl = 0;
	uint8_t t1 = 0;

	z80_block(28);
	t1 = z80_read8(ix);
	z80_write8(ix, t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(17);
	key_off(ix);
	z80_block(39);
	z80_write8(ix, 0u);
	hl = pcm_effect_52_hold_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_52_hold(uint16_t ix)
{
	uint8_t t1 = 0;

	z80_block(28);
	t1 = z80_read8(ix);
	z80_write8(ix, t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_53(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x39FEu;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_53_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_53_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_54(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3A1Cu;
	load_patch(hl, ix);
	z80_block(43);
	a = 6u;
	z80_write8((uint16_t)(ix + 1u), 6u);
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(39);
	z80_write8(ix, 0x90u);
	hl = pcm_effect_54_modulate_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_54_modulate(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;
	uint8_t t1 = 0;

	z80_block(28);
	t1 = z80_read8(ix);
	z80_write8(ix, t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(78);
	z80_write8(ix, 0x90u);
	z80_write8((uint16_t)(ix + 1u), z80_read8((uint16_t)(ix + 1u)) - 1u);
	a = z80_read8((uint16_t)(ix + 1u));
	set_pan(ix, a);
	z80_block(31);
	if (z80_read8((uint16_t)(ix + 1u)) != 2u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(20);
	hl = pcm_effect_54_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_54_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_55(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3A5Eu;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xE40u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_55_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_55_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_56(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3A82u;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xE00u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 0u;
	set_volume(ix, a);
	z80_block(24);
	a = 6u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_56_retrigger_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_56_retrigger(uint16_t ix)
{
	uint32_t zero = 0;
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(17);
	key_off(ix);
	z80_block(24);
	a = 0x60u;
	set_volume(ix, a);
	z80_block(24);
	a = 3u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_56_retrigger_2_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_56_retrigger_2(uint16_t ix)
{
	uint32_t zero = 0;
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(17);
	key_off(ix);
	z80_block(24);
	a = 0x70u;
	set_volume(ix, a);
	z80_block(24);
	a = 2u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_56_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_56_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_57(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3ADFu;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xF00u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(68);
	z80_write8(ix, 0u);
	z80_write8((uint16_t)(ix + 1u), 2u);
	hl = pcm_effect_57_retrigger_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_57_retrigger(uint16_t ix)
{
	uint32_t zero = 0;
	uint16_t hl = 0;

	z80_block(17);
	zero = pcm_effect_57_update(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(17);
	key_off(ix);
	z80_block(27);
	hl = 0xEC0u;
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(17);
	key_off(ix);
	z80_block(68);
	z80_write8(ix, 0x80u);
	z80_write8((uint16_t)(ix + 1u), 2u);
	hl = pcm_effect_57_note_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_57_note(uint16_t ix)
{
	uint32_t zero = 0;
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(17);
	zero = pcm_effect_57_update(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(27);
	hl = 0x3AE2u;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xF60u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_57_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_57_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

uint32_t pcm_effect_57_update(uint16_t ix)
{
	uint32_t zero = 0;
	uint8_t h = 0, l = 0;
	uint16_t t1 = 0;

	z80_block(100);
	t1 = z80_read16(ix) - 1u;
	h = (uint8_t)(t1 >> 8);
	l = (uint8_t)t1;
	z80_write8(ix, l);
	z80_write8((uint16_t)(ix + 1u), h);
	zero = (h | l) == 0u;
	return zero;
}

void pcm_effect_58(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3B5Fu;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xFA0u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(39);
	z80_write8(ix, 5u);
	hl = pcm_effect_58_retrigger_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_58_retrigger(uint16_t ix)
{
	uint32_t zero = 0;
	uint8_t t1 = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(33);
	t1 = z80_read8(ix);
	z80_write8(ix, t1 - 1u);
	if (t1 == 1u)
	{
		stop_channel(ix);
		return;
	}
	z80_block(17);
	key_off(ix);
	z80_block(10);
	key_on(ix);
}

void pcm_effect_59(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3B90u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_59_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_59_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_5a(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3BAEu;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_5a_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_5a_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_5b(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3BCCu;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(17);
	key_off(ix);
	z80_block(20);
	hl = pcm_effect_5b_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_5b_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_5c(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3BEDu;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xF40u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(39);
	z80_write8(ix, 0x40u);
	hl = pcm_effect_5c_delay_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_5c_delay(uint16_t ix)
{
	uint16_t hl = 0;
	uint8_t t1 = 0;

	z80_block(28);
	t1 = z80_read8(ix);
	z80_write8(ix, t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(17);
	key_off(ix);
	z80_block(39);
	z80_write8(ix, 0u);
	hl = pcm_effect_5c_hold_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_5c_hold(uint16_t ix)
{
	uint8_t t1 = 0;

	z80_block(28);
	t1 = z80_read8(ix);
	z80_write8(ix, t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_5d(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3C26u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(39);
	z80_write8(ix, 0x80u);
	hl = pcm_effect_5d_delay_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_5d_delay(uint16_t ix)
{
	uint16_t hl = 0;
	uint8_t t1 = 0;

	z80_block(28);
	t1 = z80_read8(ix);
	z80_write8(ix, t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(17);
	key_off(ix);
	z80_block(39);
	z80_write8(ix, 0u);
	hl = pcm_effect_5d_hold_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_5d_hold(uint16_t ix)
{
	uint8_t t1 = 0;

	z80_block(28);
	t1 = z80_read8(ix);
	z80_write8(ix, t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_5e(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3C59u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_5e_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_5e_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_5f(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3C77u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_5f_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_5f_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_60(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3C95u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_60_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_60_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_61(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3CB3u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_61_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_61_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_62(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3CD1u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_62_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_62_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_63(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3CEFu;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_63_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_63_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_64(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3D0Du;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_64_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_64_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_65(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3D2Bu;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_65_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_65_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_66(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3D49u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_66_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_66_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_67(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3D67u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_67_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_67_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_68(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3D85u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_68_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_68_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_69(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3DA3u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_69_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_69_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_6a(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3DC1u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_6a_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_6a_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_6b(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3DDFu;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_6b_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_6b_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_6c(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3DFDu;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_6c_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_6c_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_6d(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3E1Bu;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_6d_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_6d_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_6e(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3E39u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_6e_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_6e_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_6f(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3E57u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_6f_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_6f_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_70(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3E75u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_70_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_70_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_71(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3E93u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_71_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_71_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_72(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(27);
	hl = 0x3EB1u;
	load_patch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_72_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_72_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_73(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(27);
	hl = 0x3ECFu;
	load_patch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_73_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_73_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_74(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(27);
	hl = 0x3EEDu;
	load_patch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_74_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_74_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_75(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(27);
	hl = 0x3F0Bu;
	load_patch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_75_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_75_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_76(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(27);
	hl = 0x3F29u;
	load_patch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_76_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_76_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_77(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3F47u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(39);
	z80_write8(ix, 0x80u);
	hl = pcm_effect_77_delay_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_77_delay(uint16_t ix)
{
	uint16_t hl = 0;
	uint8_t t1 = 0;

	z80_block(28);
	t1 = z80_read8(ix);
	z80_write8(ix, t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(17);
	key_off(ix);
	z80_block(39);
	z80_write8(ix, 0u);
	hl = pcm_effect_77_hold_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_77_hold(uint16_t ix)
{
	uint8_t t1 = 0;

	z80_block(28);
	t1 = z80_read8(ix);
	z80_write8(ix, t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_78(uint16_t ix)
{
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_79(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3F7Du;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_79_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_79_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_7a(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x3F9Bu;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(43);
	a = 0x60u;
	z80_write8(ix, 0x60u);
	set_volume(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(39);
	z80_write8((uint16_t)(ix + 1u), 1u);
	hl = pcm_effect_7a_retrigger_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_7a_retrigger(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;
	uint8_t t1 = 0;

	z80_block(17);
	pcm_effect_7a_retrigger_4(ix);
	z80_block(28);
	t1 = z80_read8((uint16_t)(ix + 1u));
	z80_write8((uint16_t)(ix + 1u), t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(78);
	z80_write8((uint16_t)(ix + 1u), 1u);
	z80_write8(ix, z80_read8(ix) - 1u);
	a = z80_read8(ix);
	set_volume(ix, a);
	z80_block(28);
	if (z80_read8(ix) != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(68);
	z80_write8(ix, 0u);
	z80_write8((uint16_t)(ix + 1u), 0xAu);
	hl = pcm_effect_7a_retrigger_2_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_7a_retrigger_2(uint16_t ix)
{
	uint8_t h = 0, l = 0;
	uint16_t hl = 0;
	uint16_t t1 = 0;

	z80_block(17);
	pcm_effect_7a_retrigger_4(ix);
	z80_block(95);
	t1 = z80_read16(ix) - 1u;
	h = (uint8_t)(t1 >> 8);
	l = (uint8_t)t1;
	z80_write8(ix, l);
	z80_write8((uint16_t)(ix + 1u), h);
	if ((l | h) != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(58);
	z80_write8(ix, 0u);
	z80_write8((uint16_t)(ix + 1u), 1u);
	hl = pcm_effect_7a_retrigger_3_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_7a_retrigger_3(uint16_t ix)
{
	uint8_t a = 0;
	uint8_t t1 = 0;

	z80_block(17);
	pcm_effect_7a_retrigger_4(ix);
	z80_block(28);
	t1 = z80_read8((uint16_t)(ix + 1u));
	z80_write8((uint16_t)(ix + 1u), t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(78);
	z80_write8((uint16_t)(ix + 1u), 8u);
	z80_write8(ix, z80_read8(ix) + 1u);
	a = z80_read8(ix);
	set_volume(ix, a);
	z80_block(31);
	if (z80_read8(ix) != 0x7Fu)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_7a_retrigger_4(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(17);
	key_off(ix);
	z80_block(10);
	key_on(ix);
}

void pcm_effect_7b(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x402Eu;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_7b_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_7b_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_7c(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x404Cu;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(43);
	a = 0x40u;
	z80_write8(ix, 0x40u);
	set_volume(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(39);
	z80_write8((uint16_t)(ix + 1u), 1u);
	hl = pcm_effect_7c_retrigger_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_7c_retrigger(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;
	uint8_t t1 = 0;

	z80_block(17);
	pcm_effect_7c_retrigger_4(ix);
	z80_block(28);
	t1 = z80_read8((uint16_t)(ix + 1u));
	z80_write8((uint16_t)(ix + 1u), t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(78);
	z80_write8((uint16_t)(ix + 1u), 4u);
	z80_write8(ix, z80_read8(ix) - 1u);
	a = z80_read8(ix);
	set_volume(ix, a);
	z80_block(28);
	if (z80_read8(ix) != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(68);
	z80_write8(ix, 0u);
	z80_write8((uint16_t)(ix + 1u), 0x11u);
	hl = pcm_effect_7c_retrigger_2_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_7c_retrigger_2(uint16_t ix)
{
	uint8_t h = 0, l = 0;
	uint16_t hl = 0;
	uint16_t t1 = 0;

	z80_block(17);
	pcm_effect_7c_retrigger_4(ix);
	z80_block(95);
	t1 = z80_read16(ix) - 1u;
	h = (uint8_t)(t1 >> 8);
	l = (uint8_t)t1;
	z80_write8(ix, l);
	z80_write8((uint16_t)(ix + 1u), h);
	if ((l | h) != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(58);
	z80_write8(ix, 0u);
	z80_write8((uint16_t)(ix + 1u), 1u);
	hl = pcm_effect_7c_retrigger_3_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_7c_retrigger_3(uint16_t ix)
{
	uint8_t a = 0;
	uint8_t t1 = 0;

	z80_block(17);
	pcm_effect_7c_retrigger_4(ix);
	z80_block(28);
	t1 = z80_read8((uint16_t)(ix + 1u));
	z80_write8((uint16_t)(ix + 1u), t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(78);
	z80_write8((uint16_t)(ix + 1u), 8u);
	z80_write8(ix, z80_read8(ix) + 1u);
	a = z80_read8(ix);
	set_volume(ix, a);
	z80_block(31);
	if (z80_read8(ix) != 0x7Fu)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_7c_retrigger_4(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(17);
	key_off(ix);
	z80_block(10);
	key_on(ix);
}

void pcm_effect_7d(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x40DFu;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_7d_wait_sample_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_7d_wait_sample(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_7e(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x40FDu;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(68);
	z80_write8(ix, 0u);
	z80_write8((uint16_t)(ix + 1u), 6u);
	hl = pcm_effect_7e_retrigger_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_7e_retrigger(uint16_t ix)
{
	uint8_t h = 0, l = 0;
	uint16_t hl = 0;
	uint16_t t1 = 0;

	z80_block(17);
	pcm_effect_7e_retrigger_3(ix);
	z80_block(95);
	t1 = z80_read16(ix) - 1u;
	h = (uint8_t)(t1 >> 8);
	l = (uint8_t)t1;
	z80_write8(ix, l);
	z80_write8((uint16_t)(ix + 1u), h);
	if ((l | h) != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(58);
	z80_write8(ix, 0u);
	z80_write8((uint16_t)(ix + 1u), 1u);
	hl = pcm_effect_7e_retrigger_2_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_7e_retrigger_2(uint16_t ix)
{
	uint8_t a = 0;
	uint8_t t1 = 0;

	z80_block(17);
	pcm_effect_7e_retrigger_3(ix);
	z80_block(28);
	t1 = z80_read8((uint16_t)(ix + 1u));
	z80_write8((uint16_t)(ix + 1u), t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(78);
	z80_write8((uint16_t)(ix + 1u), 8u);
	z80_write8(ix, z80_read8(ix) + 1u);
	a = z80_read8(ix);
	set_volume(ix, a);
	z80_block(31);
	if (z80_read8(ix) != 0x7Fu)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void pcm_effect_7e_retrigger_3(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(17);
	key_off(ix);
	z80_block(10);
	key_on(ix);
}

void pcm_effect_7f(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x4165u;
	load_patch(hl, ix);
	z80_block(17);
	pcm_effect_7f_set_volume(ix);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_effect_7f_retrigger_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_effect_7f_retrigger(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(10);
	if (zero == 0u)
	{
		pcm_effect_7f_set_volume(ix);
		return;
	}
	z80_block(17);
	key_off(ix);
	z80_block(17);
	key_on(ix);
	pcm_effect_7f_set_volume(ix);
}

void pcm_effect_7f_set_volume(uint16_t ix)
{
	uint8_t a = 0, pan = 0, volume = 0;
	uint16_t level = 0;

	z80_block(40);
	a = z80_read8(ix) & 7u;
	if (a == 0u)
	{
		stop_channel(ix);
		return;
	}
	z80_block(73);
	level = a * 2u + (effect_levels_ADDRESS - 0x2u);
	pan = EFFECT_LEVEL(level)->pan;
	level++;
	set_pan(ix, pan);
	z80_block(17);
	volume = EFFECT_LEVEL(level - 0x1u)->volume;
	set_volume(ix, volume);
}
