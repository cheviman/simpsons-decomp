/**
 *    Name:        main.c
 *    Description: the reset and its self test, the commands from the 053248, the main loop
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    06-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the Z80 sound program decompiled into C by
 *    tools/decompile_sound.py, with the names of sound_symbols.txt.
 */
#include "sound.h"

/* the reset: IM 1, SP F800, the RAM test (55 then AA over F000-F7FF; bit 0 of self_test_failures), then
   check_rom */
uint16_t BOARD_ORIGINAL(sound_reset)(void)
{
	uint16_t bc = 0, hl = 0;

	z80_block(28);
	z80_block(61);
	z80_write16(PCM_FC02, 0u);
	self_test_failures = 0u;
	hl = held_command_ADDRESS;
	bc = 0x800u;
	do
	{
		z80_block(31);
		z80_write8(hl, 0x55u);
		if (0x55u != z80_read8(hl))
		{
			z80_block(16);
			self_test_failures = self_test_failures | 1u;
			return check_rom();
		}
		z80_block(30);
		hl++;
		bc--;
	} while ((uint8_t)(bc | (bc >> 8)) != 0u);
	z80_block(20);
	hl = held_command_ADDRESS;
	bc = 0x800u;
	do
	{
		z80_block(31);
		z80_write8(hl, 0xAAu);
		if (0xAAu != z80_read8(hl))
		{
			z80_block(16);
			self_test_failures = self_test_failures | 1u;
			return check_rom();
		}
		z80_block(30);
		hl++;
		bc--;
	} while ((uint8_t)(bc | (bc >> 8)) != 0u);
	z80_block(10);
	return check_rom();
}

/* IM 1: the 053248's command (FC00, unless F000-F001 holds one: nothing sets it) and its argument
   (FC01): F0-FF the self test's answers and the reset, 3F a PCM effect of the third group by the
   argument, 7F the argument to a playing effect 7F, the rest start_sound for the command and the
   argument's count after it */
void sound_command(void)
{
	uint8_t a = 0, de = 0;
	uint16_t bc = 0, de_2 = 0, hl = 0, ix = 0;
	uint8_t saved_a = 0;
	uint16_t stack = 0, saved_bc = 0;
	uint8_t t20 = 0, t21 = 0, t22 = 0, t23 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0, t15 = 0, t16 = 0, t17 = 0, t18 = 0, t19 = 0;

	z80_block(10);
	z80_block(38);
	bc = held_command;
	if ((uint8_t)((bc >> 8) | bc) == 0u)
	{
		z80_block(20);
		bc = z80_read16(PCM_FC00);
	}
	z80_block(21);
	a = (uint8_t)bc;
	if (a >= 0xF0u)
	{
		z80_block(17);
		if (a == 0xF0u)
		{
			z80_block(57);
			z80_write16(PCM_FC02, IN_PAGE(bc, 0x30u));
			a = self_test_failures;
			self_test_failures = a;
			if ((a & 1u) != 0u)
			{
				self_test_failed();
				return;
			}
			z80_block(10);
			return;
		}
		z80_block(17);
		if (a == 0xF1u)
		{
			z80_block(62);
			a = self_test_failures;
			z80_write16(PCM_FC02, IN_PAGE(bc, a));
			self_test_failures = a;
			if ((a & 1u) != 0u)
			{
				self_test_failed();
				return;
			}
			z80_block(10);
			return;
		}
		z80_block(17);
		if (a == 0xF2u)
		{
			z80_block(66);
			t1 = bc;
			bc = program_rom_sum;
			t2 = bc;
			program_rom_sum = t2;
			z80_write16(PCM_FC02, (t1 & ~0xFFu) | (uint8_t)bc);
			a = self_test_failures;
			self_test_failures = a;
			if ((a & 1u) != 0u)
			{
				self_test_failed();
				return;
			}
			z80_block(10);
			return;
		}
		z80_block(17);
		if (a == 0xF3u)
		{
			z80_block(66);
			t3 = bc;
			bc = program_rom_sum;
			t4 = bc;
			program_rom_sum = t4;
			z80_write16(PCM_FC02, (t3 & ~0xFFu) | (bc >> 8));
			a = self_test_failures;
			self_test_failures = a;
			if ((a & 1u) != 0u)
			{
				self_test_failed();
				return;
			}
			z80_block(10);
			return;
		}
		z80_block(17);
		if (a == 0xF4u)
		{
			z80_block(66);
			t5 = bc;
			de_2 = sample_rom_1_sum;
			t6 = program_rom_sum;
			program_rom_sum = t6;
			sample_rom_1_sum = de_2;
			z80_write16(PCM_FC02, (t5 & ~0xFFu) | (uint8_t)de_2);
			a = self_test_failures;
			self_test_failures = a;
			if ((a & 1u) != 0u)
			{
				self_test_failed();
				return;
			}
			z80_block(10);
			return;
		}
		z80_block(17);
		if (a == 0xF5u)
		{
			z80_block(66);
			t7 = bc;
			de_2 = sample_rom_1_sum;
			t8 = program_rom_sum;
			program_rom_sum = t8;
			sample_rom_1_sum = de_2;
			z80_write16(PCM_FC02, (t7 & ~0xFFu) | (de_2 >> 8));
			a = self_test_failures;
			self_test_failures = a;
			if ((a & 1u) != 0u)
			{
				self_test_failed();
				return;
			}
			z80_block(10);
			return;
		}
		z80_block(17);
		if (a == 0xF6u)
		{
			z80_block(66);
			t9 = bc;
			hl = sample_rom_2_sum;
			t10 = program_rom_sum;
			program_rom_sum = t10;
			sample_rom_2_sum = hl;
			z80_write16(PCM_FC02, (t9 & ~0xFFu) | (uint8_t)hl);
			a = self_test_failures;
			self_test_failures = a;
			if ((a & 1u) != 0u)
			{
				self_test_failed();
				return;
			}
			z80_block(10);
			return;
		}
		z80_block(17);
		if (a == 0xF7u)
		{
			z80_block(66);
			t11 = bc;
			hl = sample_rom_2_sum;
			t12 = program_rom_sum;
			program_rom_sum = t12;
			sample_rom_2_sum = hl;
			z80_write16(PCM_FC02, (t11 & ~0xFFu) | (hl >> 8));
			a = self_test_failures;
			self_test_failures = a;
			if ((a & 1u) != 0u)
			{
				self_test_failed();
				return;
			}
			z80_block(10);
			return;
		}
		z80_block(17);
		if (a == 0xFEu)
		{
			z80_block(140);
			z80_write8(PCM_FC28, 0u);
			z80_write8(PCM_FC2F, 1u);
			hl = 0u;
			z80_write16(PCM_FC0A, 0u);
			z80_write16(PCM_FC0C, 0u);
			z80_write8(PCM_FC0E, 0u);
			bc = 0u;
			do
			{
				z80_block(59);
				hl += z80_read8(PCM_FC2E);
				bc--;
			} while ((uint8_t)((bc >> 8) | bc) != 0u);
			z80_block(90);
			z80_write16(PCM_FC0A, 0u);
			z80_write16(PCM_FC0C, 0u);
			z80_write8(PCM_FC0E, 1u);
			bc = 0u;
			do
			{
				z80_block(59);
				hl += z80_read8(PCM_FC2E);
				bc--;
			} while ((uint8_t)((bc >> 8) | bc) != 0u);
			z80_block(90);
			z80_write16(PCM_FC0A, 0u);
			z80_write16(PCM_FC0C, 0u);
			z80_write8(PCM_FC0E, 2u);
			bc = 0u;
			do
			{
				z80_block(59);
				hl += z80_read8(PCM_FC2E);
				bc--;
			} while ((uint8_t)((bc >> 8) | bc) != 0u);
			z80_block(90);
			z80_write16(PCM_FC0A, 0u);
			z80_write16(PCM_FC0C, 0u);
			z80_write8(PCM_FC0E, 3u);
			bc = 0u;
			do
			{
				z80_block(59);
				hl += z80_read8(PCM_FC2E);
				bc--;
			} while ((uint8_t)((bc >> 8) | bc) != 0u);
			z80_block(90);
			z80_write16(PCM_FC0A, 0u);
			z80_write16(PCM_FC0C, 0u);
			z80_write8(PCM_FC0E, 4u);
			bc = 0u;
			do
			{
				z80_block(59);
				hl += z80_read8(PCM_FC2E);
				bc--;
			} while ((uint8_t)((bc >> 8) | bc) != 0u);
			z80_block(90);
			z80_write16(PCM_FC0A, 0u);
			z80_write16(PCM_FC0C, 0u);
			z80_write8(PCM_FC0E, 5u);
			bc = 0u;
			do
			{
				z80_block(59);
				hl += z80_read8(PCM_FC2E);
				bc--;
			} while ((uint8_t)((bc >> 8) | bc) != 0u);
			z80_block(90);
			z80_write16(PCM_FC0A, 0u);
			z80_write16(PCM_FC0C, 0u);
			z80_write8(PCM_FC0E, 6u);
			bc = 0u;
			do
			{
				z80_block(59);
				hl += z80_read8(PCM_FC2E);
				bc--;
			} while ((uint8_t)((bc >> 8) | bc) != 0u);
			z80_block(90);
			z80_write16(PCM_FC0A, 0u);
			z80_write16(PCM_FC0C, 0u);
			z80_write8(PCM_FC0E, 7u);
			bc = 0u;
			do
			{
				z80_block(59);
				hl += z80_read8(PCM_FC2E);
				bc--;
			} while ((uint8_t)((bc >> 8) | bc) != 0u);
			z80_block(90);
			z80_write16(PCM_FC0A, 0u);
			z80_write16(PCM_FC0C, 0u);
			z80_write8(PCM_FC0E, 8u);
			bc = 0u;
			do
			{
				z80_block(59);
				hl += z80_read8(PCM_FC2E);
				bc--;
			} while ((uint8_t)((bc >> 8) | bc) != 0u);
			z80_block(90);
			z80_write16(PCM_FC0A, 0u);
			z80_write16(PCM_FC0C, 0u);
			z80_write8(PCM_FC0E, 9u);
			bc = 0u;
			do
			{
				z80_block(59);
				hl += z80_read8(PCM_FC2E);
				bc--;
			} while ((uint8_t)((bc >> 8) | bc) != 0u);
			z80_block(90);
			z80_write16(PCM_FC0A, 0u);
			z80_write16(PCM_FC0C, 0u);
			z80_write8(PCM_FC0E, 0xAu);
			bc = 0u;
			do
			{
				z80_block(59);
				hl += z80_read8(PCM_FC2E);
				bc--;
			} while ((uint8_t)((bc >> 8) | bc) != 0u);
			z80_block(90);
			z80_write16(PCM_FC0A, 0u);
			z80_write16(PCM_FC0C, 0u);
			z80_write8(PCM_FC0E, 0xBu);
			bc = 0u;
			do
			{
				z80_block(59);
				hl += z80_read8(PCM_FC2E);
				bc--;
			} while ((uint8_t)((bc >> 8) | bc) != 0u);
			z80_block(90);
			z80_write16(PCM_FC0A, 0u);
			z80_write16(PCM_FC0C, 0u);
			z80_write8(PCM_FC0E, 0xCu);
			bc = 0u;
			do
			{
				z80_block(59);
				hl += z80_read8(PCM_FC2E);
				bc--;
			} while ((uint8_t)((bc >> 8) | bc) != 0u);
			z80_block(90);
			z80_write16(PCM_FC0A, 0u);
			z80_write16(PCM_FC0C, 0u);
			z80_write8(PCM_FC0E, 0xDu);
			bc = 0u;
			do
			{
				z80_block(59);
				hl += z80_read8(PCM_FC2E);
				bc--;
			} while ((uint8_t)((bc >> 8) | bc) != 0u);
			z80_block(90);
			z80_write16(PCM_FC0A, 0u);
			z80_write16(PCM_FC0C, 0u);
			z80_write8(PCM_FC0E, 0xEu);
			bc = 0u;
			do
			{
				z80_block(59);
				hl += z80_read8(PCM_FC2E);
				bc--;
			} while ((uint8_t)((bc >> 8) | bc) != 0u);
			z80_block(90);
			z80_write16(PCM_FC0A, 0u);
			z80_write16(PCM_FC0C, 0u);
			z80_write8(PCM_FC0E, 0xFu);
			bc = 0u;
			do
			{
				z80_block(59);
				hl += z80_read8(PCM_FC2E);
				bc--;
			} while ((uint8_t)((bc >> 8) | bc) != 0u);
			z80_block(71);
			t13 = hl;
			sample_rom_1_sum = (uint8_t)hl;
			t14 = sample_rom_2_sum;
			hl = t13;
			t15 = hl;
			sample_rom_1_sum = sample_rom_1_sum | ((uint32_t)(hl >> 8) << 8);
			t16 = t14;
			sample_rom_2_sum = t16;
			if (t15 != 0x93ABu)
			{
				z80_block(16);
				self_test_failures = self_test_failures | 4u;
			}
			z80_block(140);
			z80_write8(PCM_FC28, 0u);
			z80_write8(PCM_FC2F, 1u);
			hl = 0u;
			z80_write16(PCM_FC0A, 0u);
			z80_write16(PCM_FC0C, 0u);
			z80_write8(PCM_FC0E, 0x10u);
			bc = 0u;
			do
			{
				z80_block(59);
				hl += z80_read8(PCM_FC2E);
				bc--;
			} while ((uint8_t)((bc >> 8) | bc) != 0u);
			z80_block(90);
			z80_write16(PCM_FC0A, 0u);
			z80_write16(PCM_FC0C, 0u);
			z80_write8(PCM_FC0E, 0x11u);
			bc = 0u;
			do
			{
				z80_block(59);
				hl += z80_read8(PCM_FC2E);
				bc--;
			} while ((uint8_t)((bc >> 8) | bc) != 0u);
			z80_block(90);
			z80_write16(PCM_FC0A, 0u);
			z80_write16(PCM_FC0C, 0u);
			z80_write8(PCM_FC0E, 0x12u);
			bc = 0u;
			do
			{
				z80_block(59);
				hl += z80_read8(PCM_FC2E);
				bc--;
			} while ((uint8_t)((bc >> 8) | bc) != 0u);
			z80_block(90);
			z80_write16(PCM_FC0A, 0u);
			z80_write16(PCM_FC0C, 0u);
			z80_write8(PCM_FC0E, 0x13u);
			bc = 0u;
			do
			{
				z80_block(59);
				hl += z80_read8(PCM_FC2E);
				bc--;
			} while ((uint8_t)((bc >> 8) | bc) != 0u);
			z80_block(71);
			t17 = (uint8_t)hl;
			t18 = hl;
			t19 = t17 | ((uint32_t)(hl >> 8) << 8);
			sample_rom_2_sum = t19;
			if (t18 != 0xA5A5u)
			{
				z80_block(16);
				self_test_failures = self_test_failures | 8u;
			}
			z80_block(406);
			z80_write8(PCM_FC2F, 0u);
			z80_write16(PCM_FC08, 0xFFFu);
			z80_write16(PCM_FC10, 0xFFFu);
			z80_write16(PCM_FC18, 0xFFFu);
			z80_write16(PCM_FC20, 0xFFFu);
			z80_write16(PCM_FC0A, 0u);
			z80_write16(PCM_FC0C, 0u);
			z80_write16(PCM_FC0E, 0u);
			z80_write16(PCM_FC12, 0u);
			z80_write16(PCM_FC14, 0u);
			z80_write16(PCM_FC16, 0u);
			z80_write16(PCM_FC1A, 0u);
			z80_write16(PCM_FC1C, 0u);
			z80_write16(PCM_FC1E, 0u);
			z80_write16(PCM_FC22, 0u);
			z80_write16(PCM_FC24, 0u);
			z80_write16(PCM_FC26, 0u);
			z80_write8(PCM_FC28, 0xFu);
			z80_write8(PCM_FC2F, 6u);
			z80_write16(PCM_FC02, z80_read16(PCM_FC00));
			a = self_test_failures;
			self_test_failures = a;
			if ((a & 1u) != 0u)
			{
				self_test_failed();
				return;
			}
			z80_block(10);
			return;
		}
		z80_block(17);
		if (a == 0xFFu)
		{
			sound_reset();
			return;
		}
		z80_block(30);
		t20 = a;
		a = self_test_failures;
		de = a;
		t21 = a;
		a = t20;
		self_test_failures = t21;
		if ((de & 1u) != 0u)
		{
			self_test_failed();
			return;
		}
		z80_block(17);
		if (a == 0xF8u)
		{
			z80_block(31);
			command_f8_count++;
			return;
		}
		z80_block(17);
		if (a == 0xFDu)
		{
			z80_block(63);
			fade = 1u;
			fade_period = 0x20u;
			fade_timer = 0x20u;
			return;
		}
		z80_block(10);
		return;
	}
	z80_block(30);
	t22 = a;
	a = self_test_failures;
	de = a;
	t23 = a;
	a = t22;
	self_test_failures = t23;
	if ((de & 1u) != 0u)
	{
		self_test_failed();
		return;
	}
	z80_block(17);
	if (a == 0x3Fu)
	{
		z80_block(16);
		a = (uint8_t)(bc >> 8);
		if (a >= 0x3Cu)
		{
			z80_cycles(6);
			return;
		}
		z80_block(35);
		ix = 0xF283u;
		de_2 = 0x50u;
		bc = (bc >> 8) | 0x400u;
		for (;;)
		{
			z80_block(29);
			if (a == z80_read8((uint16_t)(ix + 0x41u)))
			{
				z80_block(63);
				a = effect_priorities_2[(uint8_t)bc];
				if (a < z80_read8((uint16_t)(ix + 0x42u)))
				{
					z80_cycles(6);
					return;
				}
				z80_block(149);
				z80_write8((uint16_t)(ix + 0x41u), (uint8_t)bc);
				z80_write8((uint16_t)(ix + 0x42u), a);
				hl = effect_handlers_2_ADDRESS + (uint8_t)((uint32_t)bc << 1);
				de_2 = SOUND_ROM16(hl);
				z80_write16((uint16_t)(ix + 0x43u), de_2);
				key_off(ix);
				z80_block(14);
				a = 0u;
				set_volume(ix, a);
				return;
			}
			z80_block(23);
			ix += de_2;
			bc = (bc & 0xFFu) | ((uint32_t)(uint8_t)((bc >> 8) - 1u) << 8);
			if (bc >> 8 == 0u)
				break;
			z80_cycles(5);
		}
		z80_block(38);
		ix = 0xF283u;
		de_2 = 0x50u;
		a = 0xFFu;
		bc = (bc & 0xFFu) | 0x400u;
		for (;;)
		{
			z80_block(29);
			if (z80_read8((uint16_t)(ix + 0x42u)) <= a)
			{
				z80_block(44);
				a = z80_read8((uint16_t)(ix + 0x42u));
				stack = ix;
				hl = stack;
			}
			z80_block(23);
			ix += de_2;
			bc = (bc & 0xFFu) | ((uint32_t)(uint8_t)((bc >> 8) - 1u) << 8);
			if (bc >> 8 == 0u)
				break;
			z80_cycles(5);
		}
		z80_block(25);
		stack = hl;
		ix = stack;
		z80_block(63);
		a = effect_priorities_2[(uint8_t)bc];
		if (a < z80_read8((uint16_t)(ix + 0x42u)))
		{
			z80_cycles(6);
			return;
		}
		z80_block(149);
		z80_write8((uint16_t)(ix + 0x41u), (uint8_t)bc);
		z80_write8((uint16_t)(ix + 0x42u), a);
		hl = effect_handlers_2_ADDRESS + (uint8_t)((uint32_t)bc << 1);
		de_2 = SOUND_ROM16(hl);
		z80_write16((uint16_t)(ix + 0x43u), de_2);
		key_off(ix);
		z80_block(14);
		a = 0u;
		set_volume(ix, a);
		return;
	}
	z80_block(17);
	if (a == 0x7Fu)
	{
		z80_block(31);
		ix = 0xF283u;
		de_2 = 0x50u;
		bc = (bc & 0xFFu) | 0x400u;
		for (;;)
		{
			z80_block(29);
			if (a == z80_read8((uint16_t)(ix + 0x41u)))
			{
				z80_block(42);
				z80_write8(ix, z80_read8(0xFC01u));
				return;
			}
			z80_block(23);
			ix += de_2;
			bc = (bc & 0xFFu) | ((uint32_t)(uint8_t)((bc >> 8) - 1u) << 8);
			if (bc >> 8 == 0u)
				break;
			z80_cycles(5);
		}
		z80_block(22);
		if (z80_read8(0xFC01u) == 0u)
		{
			z80_cycles(6);
			return;
		}
		z80_block(38);
		ix = 0xF283u;
		de_2 = 0x50u;
		a = 0xFFu;
		bc = (bc & 0xFFu) | 0x400u;
		for (;;)
		{
			z80_block(29);
			if (z80_read8((uint16_t)(ix + 0x42u)) <= a)
			{
				z80_block(44);
				a = z80_read8((uint16_t)(ix + 0x42u));
				stack = ix;
				hl = stack;
			}
			z80_block(23);
			ix += de_2;
			bc = (bc & 0xFFu) | ((uint32_t)(uint8_t)((bc >> 8) - 1u) << 8);
			if (bc >> 8 == 0u)
				break;
			z80_cycles(5);
		}
		z80_block(88);
		stack = hl;
		ix = stack;
		a = effect_priorities_40_by_sound[(uint8_t)bc];
		if (a < z80_read8((uint16_t)(ix + 0x42u)))
		{
			z80_cycles(6);
			return;
		}
		z80_block(149);
		z80_write8((uint16_t)(ix + 0x41u), (uint8_t)bc);
		z80_write8((uint16_t)(ix + 0x42u), a);
		hl = 0x3570u + (uint8_t)((uint32_t)bc << 1);
		de_2 = SOUND_ROM16(hl);
		z80_write16((uint16_t)(ix + 0x43u), de_2);
		key_off(ix);
		z80_block(21);
		a = 0u;
		set_volume(ix, a);
		z80_block(42);
		z80_write8(ix, z80_read8(0xFC01u));
		return;
	}
	z80_block(4);
	bc = (uint32_t)(uint8_t)((bc >> 8) + 1u) << 8;
	for (;;)
	{
		z80_block(39);
		saved_a = a;
		saved_bc = bc;
		start_sound(a);
		z80_block(32);
		a = saved_a + 1u;
		bc = (uint32_t)(uint8_t)((saved_bc >> 8) - 1u) << 8;
		if (bc >> 8 == 0u)
			break;
		z80_cycles(5);
	}
	z80_block(10);
}

/* the NMI's handler (the K053260's SH1, armed by FA00): RETN, which only ends key_on's HALT */
void nmi_return(void)
{
	z80_block(14);
}

/* a command 00-EF: 00 stops all, 01-38 an FM effect, 3C-3F the group of no table, 40-7E a PCM effect,
   80-AF a song, C0-EF a song after the playing one fades out */
void start_sound(uint8_t a)
{
	uint32_t zero = 0;
	uint8_t a_2 = 0, b = 0, c = 0, d = 0, e = 0;
	uint16_t hl = 0, ix = 0;
	uint16_t stack = 0;

	z80_block(17);
	if (a >= 0xC0u)
	{
		z80_block(42);
		c = a - 0x40u;
		ix = 0xF003u;
		zero = music_channel_song(ix);
		z80_block(10);
		if (zero)
		{
			z80_block(31);
			ix = 0xF053u;
			zero = music_channel_song(ix);
			z80_block(10);
			if (zero)
			{
				z80_block(31);
				ix = 0xF0A3u;
				zero = music_channel_song(ix);
				z80_block(10);
				if (zero)
				{
					z80_block(31);
					ix = 0xF0F3u;
					zero = music_channel_song(ix);
					z80_block(10);
					if (zero)
					{
						z80_block(31);
						ix = 0xF143u;
						zero = music_channel_song(ix);
						z80_block(10);
						if (zero)
						{
							z80_block(31);
							ix = 0xF193u;
							zero = music_channel_song(ix);
							z80_block(10);
							if (zero)
							{
								z80_block(31);
								ix = 0xF1E3u;
								zero = music_channel_song(ix);
								z80_block(10);
								if (zero)
								{
									z80_block(31);
									ix = 0xF233u;
									zero = music_channel_song(ix);
									z80_block(10);
									if (zero)
									{
										z80_block(31);
										ix = 0xF283u;
										zero = music_channel_song(ix);
										z80_block(10);
										if (zero)
										{
											z80_block(31);
											ix = 0xF2D3u;
											zero = music_channel_song(ix);
											z80_block(10);
											if (zero)
											{
												z80_block(31);
												ix = 0xF323u;
												zero = music_channel_song(ix);
												z80_block(10);
												if (zero)
												{
													z80_block(31);
													ix = 0xF373u;
													zero = music_channel_song(ix);
													z80_block(10);
													if (zero)
													{
														z80_block(14);
														a_2 = c;
														start_song(a_2);
														return;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		z80_block(80);
		fade_next_song = c;
		fade = 1u;
		fade_period = 8u;
		fade_timer = 8u;
		return;
	}
	z80_block(17);
	if (a >= 0x80u)
	{
		start_song(a);
		return;
	}
	z80_block(17);
	if (a >= 0x40u)
	{
		z80_block(12);
		if (a >= 0x80u)
		{
			z80_cycles(6);
			return;
		}
		z80_block(35);
		c = a;
		ix = 0xF283u;
		d = 0u;
		e = 0x50u;
		b = 4u;
		for (;;)
		{
			z80_block(29);
			if (a == z80_read8((uint16_t)(ix + 0x41u)))
			{
				z80_block(111);
				hl = 0x3570u + (uint8_t)((uint32_t)c << 1);
				d = SOUND_ROM8(hl + 1u);
				z80_write8((uint16_t)(ix + 0x43u), SOUND_ROM8(hl));
				z80_write8((uint16_t)(ix + 0x44u), d);
				key_off(ix);
				z80_block(14);
				a_2 = 0u;
				set_volume(ix, a_2);
				return;
			}
			z80_block(23);
			ix += ((uint32_t)d << 8) | e;
			b--;
			if (b == 0u)
				break;
			z80_cycles(5);
		}
		z80_block(38);
		ix = 0xF283u;
		d = 0u;
		e = 0x50u;
		a_2 = 0xFFu;
		b = 4u;
		for (;;)
		{
			z80_block(29);
			if (z80_read8((uint16_t)(ix + 0x42u)) <= a_2)
			{
				z80_block(44);
				a_2 = z80_read8((uint16_t)(ix + 0x42u));
				stack = ix;
				hl = stack;
			}
			z80_block(23);
			ix += ((uint32_t)d << 8) | e;
			b--;
			if (b == 0u)
				break;
			z80_cycles(5);
		}
		z80_block(88);
		stack = hl;
		ix = stack;
		a_2 = effect_priorities_40_by_sound[c];
		if (a_2 < z80_read8((uint16_t)(ix + 0x42u)))
		{
			z80_cycles(6);
			return;
		}
		z80_block(38);
		z80_write8((uint16_t)(ix + 0x41u), c);
		z80_write8((uint16_t)(ix + 0x42u), a_2);
		z80_block(111);
		hl = 0x3570u + (uint8_t)((uint32_t)c << 1);
		d = SOUND_ROM8(hl + 1u);
		z80_write8((uint16_t)(ix + 0x43u), SOUND_ROM8(hl));
		z80_write8((uint16_t)(ix + 0x44u), d);
		key_off(ix);
		z80_block(14);
		a_2 = 0u;
		set_volume(ix, a_2);
		return;
	}
	z80_block(17);
	if (a >= 0x3Cu)
	{
		z80_block(12);
		if (a >= 0x40u)
		{
			z80_cycles(6);
			return;
		}
		z80_block(89);
		c = a;
		ix = 0xF233u;
		a_2 = (uint32_t)unused_effect_priorities_by_sound[c] << 1;
		if (a_2 < unk_F275)
		{
			z80_cycles(6);
			return;
		}
		z80_block(172);
		unk_F274 = c;
		unk_F275 = a_2;
		hl = unused_effect_handlers_ADDRESS + (uint8_t)((uint32_t)c << 1);
		d = SOUND_ROM8(hl + 1u);
		unk_F276 = SOUND_ROM8(hl);
		unk_F277 = d;
		unk_F278 = 0u;
		a_2 = 0u;
		set_channel_am_sensitivity(ix, a_2);
		z80_block(21);
		a_2 = 0u;
		set_channel_pm_sensitivity(ix, a_2);
		z80_block(17);
		key_off(ix);
		z80_block(17);
		fast_release(ix);
		z80_block(14);
		a_2 = 0u;
		set_volume(ix, a_2);
		return;
	}
	z80_block(17);
	if (a == 0u)
	{
		stop_all_channels();
		return;
	}
	z80_block(12);
	if (a >= 0x39u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(35);
	c = a;
	ix = 0xF003u;
	d = 0u;
	e = 0x50u;
	b = 8u;
	for (;;)
	{
		z80_block(29);
		if (a == z80_read8((uint16_t)(ix + 0x41u)))
			break;
		z80_block(23);
		ix += ((uint32_t)d << 8) | e;
		b--;
		if (b != 0u)
		{
			z80_cycles(5);
			continue;
		}
		z80_block(38);
		ix = 0xF003u;
		d = 0u;
		e = 0x50u;
		a_2 = 0xFFu;
		b = 8u;
		for (;;)
		{
			z80_block(29);
			if (z80_read8((uint16_t)(ix + 0x42u)) <= a_2)
			{
				z80_block(44);
				a_2 = z80_read8((uint16_t)(ix + 0x42u));
				stack = ix;
				hl = stack;
			}
			z80_block(23);
			ix += ((uint32_t)d << 8) | e;
			b--;
			if (b == 0u)
				break;
			z80_cycles(5);
		}
		z80_block(88);
		stack = hl;
		ix = stack;
		a_2 = effect_priorities[(uint16_t)(c - 1u)];
		if (a_2 < z80_read8((uint16_t)(ix + 0x42u)))
		{
			z80_cycles(6);
			return;
		}
		z80_block(38);
		z80_write8((uint16_t)(ix + 0x41u), c);
		z80_write8((uint16_t)(ix + 0x42u), a_2);
		break;
	}
	z80_block(134);
	hl = effect_handlers_ADDRESS - 0x2u + (uint8_t)((uint32_t)c << 1);
	d = SOUND_ROM8(hl + 1u);
	z80_write8((uint16_t)(ix + 0x43u), SOUND_ROM8(hl));
	z80_write8((uint16_t)(ix + 0x44u), d);
	z80_write8((uint16_t)(ix + 0x45u), 0u);
	a_2 = 0u;
	set_channel_am_sensitivity(ix, a_2);
	z80_block(21);
	a_2 = 0u;
	set_channel_pm_sensitivity(ix, a_2);
	z80_block(17);
	key_off(ix);
	z80_block(17);
	fast_release(ix);
	z80_block(17);
	noise_off(ix);
	z80_block(14);
	a_2 = 0u;
	set_volume(ix, a_2);
}

/* command 00: stop_channel_unless_kept on all 12 records */
uint16_t stop_all_channels(void)
{
	uint8_t ignored8 = 0;
	uint16_t ix = 0;

	z80_block(31);
	ix = 0xF003u;
	stop_channel_unless_kept(ix);
	z80_block(31);
	ix = 0xF053u;
	stop_channel_unless_kept(ix);
	z80_block(31);
	ix = 0xF0A3u;
	stop_channel_unless_kept(ix);
	z80_block(31);
	ix = 0xF0F3u;
	stop_channel_unless_kept(ix);
	z80_block(31);
	ix = 0xF143u;
	stop_channel_unless_kept(ix);
	z80_block(31);
	ix = 0xF193u;
	stop_channel_unless_kept(ix);
	z80_block(31);
	ix = 0xF1E3u;
	stop_channel_unless_kept(ix);
	z80_block(31);
	ix = 0xF233u;
	stop_channel_unless_kept(ix);
	z80_block(31);
	ix = 0xF283u;
	stop_channel_unless_kept(ix);
	z80_block(31);
	ix = 0xF2D3u;
	stop_channel_unless_kept(ix);
	z80_block(31);
	ix = 0xF323u;
	stop_channel_unless_kept(ix);
	z80_block(31);
	ix = 0xF373u;
	stop_channel_unless_kept(ix);
	stop_music(&ix, &ignored8);
	return ix;
}

/* the music off on all 12 records (stop_music_channel), the fade cleared: at the fade's end */
void stop_music(uint16_t *p_ix, uint8_t *p_a)
{
	uint8_t a = 0;
	uint16_t ix = 0;

	z80_block(31);
	ix = 0xF003u;
	stop_music_channel(ix);
	z80_block(31);
	ix = 0xF053u;
	stop_music_channel(ix);
	z80_block(31);
	ix = 0xF0A3u;
	stop_music_channel(ix);
	z80_block(31);
	ix = 0xF0F3u;
	stop_music_channel(ix);
	z80_block(31);
	ix = 0xF143u;
	stop_music_channel(ix);
	z80_block(31);
	ix = 0xF193u;
	stop_music_channel(ix);
	z80_block(31);
	ix = 0xF1E3u;
	stop_music_channel(ix);
	z80_block(31);
	ix = 0xF233u;
	stop_music_channel(ix);
	z80_block(31);
	ix = 0xF283u;
	stop_music_channel(ix);
	z80_block(31);
	ix = 0xF2D3u;
	stop_music_channel(ix);
	z80_block(31);
	ix = 0xF323u;
	stop_music_channel(ix);
	z80_block(31);
	ix = 0xF373u;
	stop_music_channel(ix);
	z80_block(79);
	a = 0u;
	fade = 0u;
	fade_attenuation = 0u;
	fade_timer = 0u;
	fade_next_song = 0u;
	fade_hold = 0u;
	*p_ix = ix;
	*p_a = a;
}

/* stop_channel unless the record's priority is C0 or more */
void stop_channel_unless_kept(uint16_t ix)
{
	z80_block(31);
	if (z80_read8((uint16_t)(ix + 0x42u)) >= 0xC0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

/* a song 80-AF: its bank (song_banks) to FE00, its header (song_headers), every record's track from it
   (start_music_channel), the fade cleared */
void start_song(uint8_t a)
{
	uint8_t a_2 = 0;
	uint16_t hl = 0, ix = 0;
	uint8_t saved_a = 0;

	z80_block(12);
	if (a >= 0xB0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(171);
	saved_a = a;
	z80_write8(SOUND_BANK_FE00, song_banks_by_sound[a]);
	a_2 = saved_a;
	hl = a_2 * 2u + 0x5CB2u;
	hl = SOUND_ROM16(hl);
	ix = 0xF003u;
	hl = start_music_channel(hl, ix, a_2);
	z80_block(31);
	ix = 0xF053u;
	hl = start_music_channel(hl, ix, a_2);
	z80_block(31);
	ix = 0xF0A3u;
	hl = start_music_channel(hl, ix, a_2);
	z80_block(31);
	ix = 0xF0F3u;
	hl = start_music_channel(hl, ix, a_2);
	z80_block(31);
	ix = 0xF143u;
	hl = start_music_channel(hl, ix, a_2);
	z80_block(31);
	ix = 0xF193u;
	hl = start_music_channel(hl, ix, a_2);
	z80_block(31);
	ix = 0xF1E3u;
	hl = start_music_channel(hl, ix, a_2);
	z80_block(31);
	ix = 0xF233u;
	hl = start_music_channel(hl, ix, a_2);
	z80_block(31);
	ix = 0xF283u;
	hl = start_music_channel(hl, ix, a_2);
	z80_block(31);
	ix = 0xF2D3u;
	hl = start_music_channel(hl, ix, a_2);
	z80_block(31);
	ix = 0xF323u;
	hl = start_music_channel(hl, ix, a_2);
	z80_block(31);
	ix = 0xF373u;
	start_music_channel(hl, ix, a_2);
	z80_block(79);
	fade = 0u;
	fade_attenuation = 0u;
	fade_timer = 0u;
	fade_next_song = 0u;
	fade_hold = 0u;
}

/* the record's track from the song header at HL (start_music_track), HL past it */
uint16_t start_music_channel(uint16_t hl, uint16_t ix, uint8_t a)
{
	uint8_t d = 0, e = 0;
	uint16_t de = 0;

	z80_block(54);
	e = z80_read8(hl);
	hl++;
	d = z80_read8(hl);
	hl++;
	de = ((uint32_t)d << 8) | e;
	start_music_track(de, ix, a);
	z80_block(20);
	return hl;
}

/* the ROM test: adds up 0000-7FFF and the banks 2-7 into program_rom_sum and compares it with 072E (bit
   1 of self_test_failures), then sound_main (the game has no ROM to add up: runtime/sound_replaced.txt) */
uint16_t BOARD_ORIGINAL(check_rom)(void)
{
	uint16_t bc = 0, hl = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	z80_block(20);
	hl = 0u;
	bc = 0u;
	do
	{
		z80_block(56);
		hl += z80_read8(bc);
		bc++;
	} while (bc >> 8 != 0x80u);
	z80_block(30);
	z80_write8(SOUND_BANK_FE00, 2u);
	bc = 0x8000u;
	do
	{
		z80_block(56);
		hl += z80_read8(bc);
		bc++;
	} while (bc >> 8 != 0xC0u);
	z80_block(30);
	z80_write8(SOUND_BANK_FE00, 3u);
	bc = 0x8000u;
	do
	{
		z80_block(56);
		hl += z80_read8(bc);
		bc++;
	} while (bc >> 8 != 0xC0u);
	z80_block(30);
	z80_write8(SOUND_BANK_FE00, 4u);
	bc = 0x8000u;
	do
	{
		z80_block(56);
		hl += z80_read8(bc);
		bc++;
	} while (bc >> 8 != 0xC0u);
	z80_block(30);
	z80_write8(SOUND_BANK_FE00, 5u);
	bc = 0x8000u;
	do
	{
		z80_block(56);
		hl += z80_read8(bc);
		bc++;
	} while (bc >> 8 != 0xC0u);
	z80_block(30);
	z80_write8(SOUND_BANK_FE00, 6u);
	bc = 0x8000u;
	do
	{
		z80_block(56);
		hl += z80_read8(bc);
		bc++;
	} while (bc >> 8 != 0xC0u);
	z80_block(30);
	z80_write8(SOUND_BANK_FE00, 7u);
	bc = 0x8000u;
	do
	{
		z80_block(56);
		hl += z80_read8(bc);
		bc++;
	} while (bc >> 8 != 0xC0u);
	z80_block(71);
	t1 = hl;
	program_rom_sum = (uint8_t)hl;
	t2 = sample_rom_2_sum;
	hl = t1;
	t3 = hl;
	program_rom_sum = program_rom_sum | ((uint32_t)(hl >> 8) << 8);
	t4 = t2;
	sample_rom_2_sum = t4;
	if (t3 == 0x72Eu)
		return sound_main();
	z80_block(16);
	self_test_failures = self_test_failures | 2u;
	return sound_main();
}

/* RAM cleared, the K053260 set up (its voices' registers, keys, mode), every record's chip channel and
   the PCM voices' registers and key bits, then the YM2151's timer and the main loop */
uint16_t sound_main(void)
{
	uint8_t a = 0, ix = 0;
	uint16_t ix_2 = 0;

	z80_block(1340);
	AS8(held_command) = 0u;
	move_block(held_command_ADDRESS, 0xF001u, 0x7FFu, 1u);
	z80_write8(PCM_FC2F, 0u);
	z80_write16(PCM_FC08, 0xFFFu);
	z80_write16(PCM_FC10, 0xFFFu);
	z80_write16(PCM_FC18, 0xFFFu);
	z80_write16(PCM_FC20, 0xFFFu);
	z80_write16(PCM_FC0A, 0u);
	z80_write16(PCM_FC0C, 0u);
	z80_write16(PCM_FC0E, 0u);
	z80_write16(PCM_FC12, 0u);
	z80_write16(PCM_FC14, 0u);
	z80_write16(PCM_FC16, 0u);
	z80_write16(PCM_FC1A, 0u);
	z80_write16(PCM_FC1C, 0u);
	z80_write16(PCM_FC1E, 0u);
	z80_write16(PCM_FC22, 0u);
	z80_write16(PCM_FC24, 0u);
	z80_write16(PCM_FC26, 0u);
	z80_write8(PCM_FC28, 0xFu);
	z80_write8(PCM_FC2F, 6u);
	unk_F043 = 0u;
	unk_F093 = 1u;
	unk_F0E3 = 2u;
	unk_F133 = 3u;
	unk_F183 = 4u;
	unk_F1D3 = 5u;
	unk_F223 = 6u;
	unk_F273 = 7u;
	unk_F2C3 = 8u;
	unk_F2CD = 8u;
	unk_F2CE = 0xFCu;
	unk_F2CF = 0xFEu;
	unk_F2D0 = 1u;
	unk_F2D1 = 0xEFu;
	unk_F2D2 = 0x10u;
	unk_F313 = 9u;
	unk_F31D = 0x10u;
	unk_F31E = 0xFCu;
	unk_F31F = 0xFDu;
	unk_F320 = 2u;
	unk_F321 = 0xDFu;
	unk_F322 = 0x20u;
	unk_F363 = 0xAu;
	unk_F36D = 0x18u;
	unk_F36E = 0xFCu;
	unk_F36F = 0xFBu;
	unk_F370 = 4u;
	unk_F371 = 0xBFu;
	unk_F372 = 0x40u;
	unk_F3B3 = 0xBu;
	unk_F3BD = 0x20u;
	unk_F3BE = 0xFCu;
	unk_F3BF = 0xF7u;
	unk_F3C0 = 8u;
	unk_F3C1 = 0x7Fu;
	unk_F3C2 = 0x80u;
	byte_pointer = 0x100u;
	a = self_test_failures;
	self_test_failures = a;
	if ((a & 1u) != 0u)
	{
		self_test_failed();
		return ix;
	}
	z80_block(17);
	ix_2 = stop_all_channels();
	z80_block(17);
	restart_frame_timer();
	z80_block(10);
	return ix_2;
}

/* the RAM test failed: forever a delay and four NOPs with interrupts on (commands come in, and fail
   again) */
void self_test_failed(void)
{
	uint16_t bc = 0;

	for (;;)
	{
		z80_block(20);
		bc = pcm_voice_playing_ADDRESS;
		do
		{
			z80_block(24);
			bc--;
		} while ((uint8_t)((bc >> 8) | bc) != 0u);
		z80_block(8);
		interrupts_on();
		z80_block(26);
		interrupts_off();
	}
}

/* waits for the YM2151's timer B; restarts it; runs the 8 FM records and the 4 PCM ones; the fade
   between songs; then four NOPs with interrupts on (the command comes in), the command again if F002
   says so (nothing sets it), the pass count */
void sound_main_loop(void)
{
	uint8_t a = 0;
	uint16_t hl = 0, ignored16 = 0, ix = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(27);
	if ((z80_read8(FM_F801) & 2u) == 0u)
	{
		z80_cycles(5);
		return;
	}
	z80_block(17);
	restart_frame_timer();
	z80_block(31);
	ix = 0xF003u;
	run_channel(ix);
	z80_block(31);
	ix = 0xF053u;
	run_channel(ix);
	z80_block(31);
	ix = 0xF0A3u;
	run_channel(ix);
	z80_block(31);
	ix = 0xF0F3u;
	run_channel(ix);
	z80_block(31);
	ix = 0xF143u;
	run_channel(ix);
	z80_block(31);
	ix = 0xF193u;
	run_channel(ix);
	z80_block(31);
	ix = 0xF1E3u;
	run_channel(ix);
	z80_block(31);
	ix = 0xF233u;
	run_channel(ix);
	z80_block(31);
	ix = 0xF283u;
	run_pcm_channel(ix);
	z80_block(31);
	ix = 0xF2D3u;
	run_pcm_channel(ix);
	z80_block(31);
	ix = 0xF323u;
	run_pcm_channel(ix);
	z80_block(31);
	ix = 0xF373u;
	run_pcm_channel(ix);
	z80_block(27);
	a = fade;
	if (a == 0u)
	{
		z80_block(8);
		interrupts_on();
		z80_block(43);
		interrupts_off();
		if (command_held != 0u)
		{
			z80_block(34);
			command_held = 0u;
			sound_command();
		}
		z80_block(31);
		pass_count++;
		return;
	}
	z80_block(17);
	if (a == 1u)
	{
		z80_block(31);
		hl = fade_timer_ADDRESS;
		t1 = fade_timer;
		fade_timer = t1 - 1u;
		if (t1 != 1u)
		{
			z80_block(8);
			interrupts_on();
			z80_block(43);
			interrupts_off();
			if (command_held != 0u)
			{
				z80_block(34);
				command_held = 0u;
				sound_command();
			}
			z80_block(31);
			pass_count++;
			return;
		}
		z80_block(67);
		fade_timer = fade_period;
		a = fade_attenuation + 1u;
		fade_attenuation = a;
		if (a == 0x7Fu)
		{
			z80_cycles(7);
			stop_music(&ignored16, &a);
		}
		z80_block(17);
		if (a != 0x30u)
		{
			z80_block(8);
			interrupts_on();
			z80_block(43);
			interrupts_off();
			if (command_held != 0u)
			{
				z80_block(34);
				command_held = 0u;
				sound_command();
			}
			z80_block(31);
			pass_count++;
			return;
		}
		z80_block(27);
		a = fade_next_song;
		if (a != 0u)
		{
			z80_cycles(7);
			start_song(a);
			z80_block(8);
			interrupts_on();
			z80_block(43);
			interrupts_off();
			if (command_held != 0u)
			{
				z80_block(34);
				command_held = 0u;
				sound_command();
			}
			z80_block(31);
			pass_count++;
			return;
		}
		z80_block(8);
		interrupts_on();
		z80_block(43);
		interrupts_off();
		if (command_held != 0u)
		{
			z80_block(34);
			command_held = 0u;
			sound_command();
		}
		z80_block(31);
		pass_count++;
		return;
	}
	z80_block(31);
	t2 = fade_hold;
	fade_hold = t2 - 1u;
	if (t2 != 1u)
	{
		z80_block(8);
		interrupts_on();
		z80_block(43);
		interrupts_off();
		if (command_held != 0u)
		{
			z80_block(34);
			command_held = 0u;
			sound_command();
		}
		z80_block(31);
		pass_count++;
		return;
	}
	z80_block(27);
	fade = 0u;
	z80_block(8);
	interrupts_on();
	z80_block(43);
	interrupts_off();
	if (command_held != 0u)
	{
		z80_block(34);
		command_held = 0u;
		sound_command();
	}
	z80_block(31);
	pass_count++;
}

/* a PCM record's: one pass in 16 (its own, by its chip channel), unless its voice plays, the volume
   moves (+48 by +47) before run_channel */
void run_pcm_channel(uint16_t ix)
{
	uint8_t a = 0;
	uint8_t t1 = 0;

	z80_block(49);
	if ((pass_count & 0xFu) == z80_read8((uint16_t)(ix + 0x40u)))
	{
		z80_block(42);
		if ((pcm_keyed & z80_read8((uint16_t)(ix + 0x4Du))) == 0u)
		{
			z80_block(48);
			t1 = z80_read8((uint16_t)(ix + 0x48u)) + z80_read8((uint16_t)(ix + 0x47u));
			a = t1;
			if ((int8_t)t1 < 0)
			{
				z80_block(7);
				a = 0x7Fu;
			}
			z80_block(36);
			z80_write8((uint16_t)(ix + 0x48u), a);
			update_volume(ix);
		}
	}
	run_channel(ix);
}

/* the music's tick on the record, then the handler it keeps at +43 */
void run_channel(uint16_t ix)
{
	uint32_t jump_target = 0;

	z80_block(17);
	ix = music_tick(ix);
	z80_block(42);
	jump_target = z80_read16((uint16_t)(ix + 0x43u));
	switch (jump_target)
	{
	case channel_idle_ADDRESS:
		channel_idle();
		return;
	case fm_effect_02_ADDRESS:
		fm_effect_02(ix);
		return;
	case fm_effect_02_delay_ADDRESS:
		fm_effect_02_delay(ix);
		return;
	case fm_effect_01_ADDRESS:
		fm_effect_01(ix);
		return;
	case fm_effect_01_retrigger_ADDRESS:
		fm_effect_01_retrigger(ix);
		return;
	case fm_effect_01_pitch_ADDRESS:
		fm_effect_01_pitch(ix);
		return;
	case fm_effect_04_ADDRESS:
		fm_effect_04(ix);
		return;
	case fm_effect_04_delay_ADDRESS:
		fm_effect_04_delay(ix);
		return;
	case fm_effect_03_ADDRESS:
		fm_effect_03(ix);
		return;
	case fm_effect_03_pitch_ADDRESS:
		fm_effect_03_pitch(ix);
		return;
	case fm_effect_06_ADDRESS:
		fm_effect_06(ix);
		return;
	case fm_effect_06_delay_ADDRESS:
		fm_effect_06_delay(ix);
		return;
	case fm_effect_05_ADDRESS:
		fm_effect_05(ix);
		return;
	case fm_effect_05_slide_ADDRESS:
		fm_effect_05_slide(ix);
		return;
	case fm_effect_07_ADDRESS:
		fm_effect_07(ix);
		return;
	case fm_effect_07_slide_ADDRESS:
		fm_effect_07_slide(ix);
		return;
	case fm_effect_09_ADDRESS:
		fm_effect_09(ix);
		return;
	case fm_effect_09_delay_ADDRESS:
		fm_effect_09_delay(ix);
		return;
	case fm_effect_08_ADDRESS:
		fm_effect_08(ix);
		return;
	case fm_effect_08_retrigger_ADDRESS:
		fm_effect_08_retrigger(ix);
		return;
	case fm_effect_08_hold_ADDRESS:
		fm_effect_08_hold(ix);
		return;
	case fm_effect_0d_ADDRESS:
		fm_effect_0d(ix);
		return;
	case fm_effect_0d_delay_ADDRESS:
		fm_effect_0d_delay(ix);
		return;
	case fm_effect_0c_ADDRESS:
		fm_effect_0c(ix);
		return;
	case fm_effect_0c_retrigger_ADDRESS:
		fm_effect_0c_retrigger(ix);
		return;
	case fm_effect_0c_retrigger_2_ADDRESS:
		fm_effect_0c_retrigger_2(ix);
		return;
	case fm_effect_0c_hold_ADDRESS:
		fm_effect_0c_hold(ix);
		return;
	case fm_effect_0e_ADDRESS:
		fm_effect_0e(ix);
		return;
	case fm_effect_0e_pitch_ADDRESS:
		fm_effect_0e_pitch(ix);
		return;
	case fm_effect_0e_pitch_2_ADDRESS:
		fm_effect_0e_pitch_2(ix);
		return;
	case fm_effect_0e_pitch_3_ADDRESS:
		fm_effect_0e_pitch_3(ix);
		return;
	case fm_effect_0f_ADDRESS:
		fm_effect_0f(ix);
		return;
	case fm_effect_0f_slide_ADDRESS:
		fm_effect_0f_slide(ix);
		return;
	case fm_effect_10_ADDRESS:
		fm_effect_10(ix);
		return;
	case fm_effect_10_slide_ADDRESS:
		fm_effect_10_slide(ix);
		return;
	case fm_effect_11_ADDRESS:
		fm_effect_11(ix);
		return;
	case fm_effect_11_pitch_ADDRESS:
		fm_effect_11_pitch(ix);
		return;
	case fm_effect_12_ADDRESS:
		fm_effect_12(ix);
		return;
	case fm_effect_12_delay_ADDRESS:
		fm_effect_12_delay(ix);
		return;
	case fm_effect_12_slide_ADDRESS:
		fm_effect_12_slide(ix);
		return;
	case fm_effect_13_ADDRESS:
		fm_effect_13(ix);
		return;
	case fm_effect_13_slide_ADDRESS:
		fm_effect_13_slide(ix);
		return;
	case fm_effect_13_slide_2_ADDRESS:
		fm_effect_13_slide_2(ix);
		return;
	case fm_effect_13_slide_3_ADDRESS:
		fm_effect_13_slide_3(ix);
		return;
	case fm_effect_14_ADDRESS:
		fm_effect_14(ix);
		return;
	case fm_effect_14_slide_ADDRESS:
		fm_effect_14_slide(ix);
		return;
	case fm_effect_14_slide_2_ADDRESS:
		fm_effect_14_slide_2(ix);
		return;
	case fm_effect_15_ADDRESS:
		fm_effect_15(ix);
		return;
	case fm_effect_15_note_ADDRESS:
		fm_effect_15_note(ix);
		return;
	case fm_effect_15_slide_ADDRESS:
		fm_effect_15_slide(ix);
		return;
	case fm_effect_17_ADDRESS:
		fm_effect_17(ix);
		return;
	case fm_effect_17_delay_ADDRESS:
		fm_effect_17_delay(ix);
		return;
	case fm_effect_16_ADDRESS:
		fm_effect_16(ix);
		return;
	case fm_effect_16_pitch_ADDRESS:
		fm_effect_16_pitch(ix);
		return;
	case fm_effect_18_ADDRESS:
		fm_effect_18(ix);
		return;
	case fm_effect_18_slide_ADDRESS:
		fm_effect_18_slide(ix);
		return;
	case fm_effect_19_ADDRESS:
		fm_effect_19(ix);
		return;
	case fm_effect_19_slide_ADDRESS:
		fm_effect_19_slide(ix);
		return;
	case fm_effect_1a_ADDRESS:
		fm_effect_1a(ix);
		return;
	case fm_effect_1a_slide_ADDRESS:
		fm_effect_1a_slide(ix);
		return;
	case fm_effect_1b_ADDRESS:
		fm_effect_1b(ix);
		return;
	case fm_effect_1b_pitch_ADDRESS:
		fm_effect_1b_pitch(ix);
		return;
	case fm_effect_1b_pitch_2_ADDRESS:
		fm_effect_1b_pitch_2(ix);
		return;
	case fm_effect_1c_ADDRESS:
		fm_effect_1c(ix);
		return;
	case fm_effect_1c_pitch_ADDRESS:
		fm_effect_1c_pitch(ix);
		return;
	case fm_effect_1c_pitch_2_ADDRESS:
		fm_effect_1c_pitch_2(ix);
		return;
	case fm_effect_1c_pitch_3_ADDRESS:
		fm_effect_1c_pitch_3(ix);
		return;
	case fm_effect_1d_ADDRESS:
		fm_effect_1d(ix);
		return;
	case fm_effect_1d_pitch_ADDRESS:
		fm_effect_1d_pitch(ix);
		return;
	case fm_effect_1d_pitch_3_ADDRESS:
		fm_effect_1d_pitch_3(ix);
		return;
	case fm_effect_1e_ADDRESS:
		fm_effect_1e(ix);
		return;
	case fm_effect_1e_slide_ADDRESS:
		fm_effect_1e_slide(ix);
		return;
	case fm_effect_1f_ADDRESS:
		fm_effect_1f(ix);
		return;
	case fm_effect_1f_retrigger_ADDRESS:
		fm_effect_1f_retrigger(ix);
		return;
	case fm_effect_1f_end_ADDRESS:
		fm_effect_1f_end(ix);
		return;
	case fm_effect_20_ADDRESS:
		fm_effect_20(ix);
		return;
	case fm_effect_20_pitch_ADDRESS:
		fm_effect_20_pitch(ix);
		return;
	case fm_effect_20_pitch_2_ADDRESS:
		fm_effect_20_pitch_2(ix);
		return;
	case fm_effect_21_ADDRESS:
		fm_effect_21(ix);
		return;
	case fm_effect_21_end_ADDRESS:
		fm_effect_21_end(ix);
		return;
	case fm_effect_22_ADDRESS:
		fm_effect_22(ix);
		return;
	case fm_effect_22_slide_ADDRESS:
		fm_effect_22_slide(ix);
		return;
	case fm_effect_23_ADDRESS:
		fm_effect_23(ix);
		return;
	case fm_effect_23_slide_ADDRESS:
		fm_effect_23_slide(ix);
		return;
	case fm_effect_24_ADDRESS:
		fm_effect_24(ix);
		return;
	case fm_effect_24_retrigger_ADDRESS:
		fm_effect_24_retrigger(ix);
		return;
	case fm_effect_24_hold_ADDRESS:
		fm_effect_24_hold(ix);
		return;
	case fm_effect_25_ADDRESS:
		fm_effect_25(ix);
		return;
	case fm_effect_25_note_ADDRESS:
		fm_effect_25_note(ix);
		return;
	case fm_effect_25_retrigger_ADDRESS:
		fm_effect_25_retrigger(ix);
		return;
	case fm_effect_25_hold_ADDRESS:
		fm_effect_25_hold(ix);
		return;
	case fm_effect_26_ADDRESS:
		fm_effect_26(ix);
		return;
	case fm_effect_26_slide_ADDRESS:
		fm_effect_26_slide(ix);
		return;
	case fm_effect_26_pitch_ADDRESS:
		fm_effect_26_pitch(ix);
		return;
	case fm_effect_27_ADDRESS:
		fm_effect_27(ix);
		return;
	case fm_effect_27_retrigger_ADDRESS:
		fm_effect_27_retrigger(ix);
		return;
	case fm_effect_27_hold_ADDRESS:
		fm_effect_27_hold(ix);
		return;
	case fm_effect_28_ADDRESS:
		fm_effect_28(ix);
		return;
	case fm_effect_28_slide_ADDRESS:
		fm_effect_28_slide(ix);
		return;
	case fm_effect_29_ADDRESS:
		fm_effect_29(ix);
		return;
	case fm_effect_29_pitch_ADDRESS:
		fm_effect_29_pitch(ix);
		return;
	case fm_effect_29_slide_ADDRESS:
		fm_effect_29_slide(ix);
		return;
	case fm_effect_2b_ADDRESS:
		fm_effect_2b(ix);
		return;
	case fm_effect_2b_delay_ADDRESS:
		fm_effect_2b_delay(ix);
		return;
	case fm_effect_2a_ADDRESS:
		fm_effect_2a(ix);
		return;
	case fm_effect_2a_retrigger_ADDRESS:
		fm_effect_2a_retrigger(ix);
		return;
	case fm_effect_2a_retrigger_2_ADDRESS:
		fm_effect_2a_retrigger_2(ix);
		return;
	case fm_effect_2a_hold_ADDRESS:
		fm_effect_2a_hold(ix);
		return;
	case fm_effect_2c_ADDRESS:
		fm_effect_2c(ix);
		return;
	case fm_effect_2c_delay_ADDRESS:
		fm_effect_2c_delay(ix);
		return;
	case fm_effect_2c_hold_ADDRESS:
		fm_effect_2c_hold(ix);
		return;
	case fm_effect_2d_ADDRESS:
		fm_effect_2d(ix);
		return;
	case fm_effect_2d_note_ADDRESS:
		fm_effect_2d_note(ix);
		return;
	case fm_effect_2d_delay_ADDRESS:
		fm_effect_2d_delay(ix);
		return;
	case fm_effect_2d_hold_ADDRESS:
		fm_effect_2d_hold(ix);
		return;
	case fm_effect_2e_ADDRESS:
		fm_effect_2e(ix);
		return;
	case fm_effect_2e_note_ADDRESS:
		fm_effect_2e_note(ix);
		return;
	case fm_effect_2e_delay_ADDRESS:
		fm_effect_2e_delay(ix);
		return;
	case fm_effect_2e_hold_ADDRESS:
		fm_effect_2e_hold(ix);
		return;
	case fm_effect_2f_ADDRESS:
		fm_effect_2f(ix);
		return;
	case fm_effect_2f_slide_ADDRESS:
		fm_effect_2f_slide(ix);
		return;
	case fm_effect_32_ADDRESS:
		fm_effect_32(ix);
		return;
	case fm_effect_32_delay_ADDRESS:
		fm_effect_32_delay(ix);
		return;
	case fm_effect_31_ADDRESS:
		fm_effect_31(ix);
		return;
	case fm_effect_31_delay_ADDRESS:
		fm_effect_31_delay(ix);
		return;
	case fm_effect_30_ADDRESS:
		fm_effect_30(ix);
		return;
	case fm_effect_30_retrigger_2_ADDRESS:
		fm_effect_30_retrigger_2(ix);
		return;
	case fm_effect_33_ADDRESS:
		fm_effect_33(ix);
		return;
	case fm_effect_33_retrigger_2_ADDRESS:
		fm_effect_33_retrigger_2(ix);
		return;
	case fm_effect_34_ADDRESS:
		fm_effect_34(ix);
		return;
	case fm_effect_34_slide_ADDRESS:
		fm_effect_34_slide(ix);
		return;
	case fm_effect_35_ADDRESS:
		fm_effect_35(ix);
		return;
	case fm_effect_35_note_ADDRESS:
		fm_effect_35_note(ix);
		return;
	case fm_effect_35_slide_ADDRESS:
		fm_effect_35_slide(ix);
		return;
	case fm_effect_36_ADDRESS:
		fm_effect_36(ix);
		return;
	case fm_effect_36_slide_ADDRESS:
		fm_effect_36_slide(ix);
		return;
	case fm_effect_37_ADDRESS:
		fm_effect_37(ix);
		return;
	case fm_effect_37_slide_ADDRESS:
		fm_effect_37_slide(ix);
		return;
	case fm_effect_38_ADDRESS:
		fm_effect_38(ix);
		return;
	case fm_effect_38_slide_ADDRESS:
		fm_effect_38_slide(ix);
		return;
	case unused_effect_2799_slide_ADDRESS:
		unused_effect_2799_slide(ix);
		return;
	case unused_effect_280E_hold_ADDRESS:
		unused_effect_280E_hold(ix);
		return;
	case unused_effect_2856_end_ADDRESS:
		unused_effect_2856_end(ix);
		return;
	case unused_effect_289F_step_ADDRESS:
		unused_effect_289F_step(ix);
		return;
	case unused_effect_289F_end_ADDRESS:
		unused_effect_289F_end(ix);
		return;
	case pcm_effect_3f_00_ADDRESS:
		pcm_effect_3f_00(ix);
		return;
	case pcm_effect_3f_00_wait_sample_ADDRESS:
		pcm_effect_3f_00_wait_sample(ix);
		return;
	case pcm_effect_3f_01_ADDRESS:
		pcm_effect_3f_01(ix);
		return;
	case pcm_effect_3f_01_wait_sample_ADDRESS:
		pcm_effect_3f_01_wait_sample(ix);
		return;
	case pcm_effect_3f_02_ADDRESS:
		pcm_effect_3f_02(ix);
		return;
	case pcm_effect_3f_02_wait_sample_ADDRESS:
		pcm_effect_3f_02_wait_sample(ix);
		return;
	case pcm_effect_3f_03_ADDRESS:
		pcm_effect_3f_03(ix);
		return;
	case pcm_effect_3f_03_wait_sample_ADDRESS:
		pcm_effect_3f_03_wait_sample(ix);
		return;
	case pcm_effect_3f_04_ADDRESS:
		pcm_effect_3f_04(ix);
		return;
	case pcm_effect_3f_04_wait_sample_ADDRESS:
		pcm_effect_3f_04_wait_sample(ix);
		return;
	case pcm_effect_3f_05_ADDRESS:
		pcm_effect_3f_05(ix);
		return;
	case pcm_effect_3f_05_wait_sample_ADDRESS:
		pcm_effect_3f_05_wait_sample(ix);
		return;
	case pcm_effect_3f_06_ADDRESS:
		pcm_effect_3f_06(ix);
		return;
	case pcm_effect_3f_06_wait_sample_ADDRESS:
		pcm_effect_3f_06_wait_sample(ix);
		return;
	case pcm_effect_3f_07_ADDRESS:
		pcm_effect_3f_07(ix);
		return;
	case pcm_effect_3f_07_wait_sample_ADDRESS:
		pcm_effect_3f_07_wait_sample(ix);
		return;
	case pcm_effect_3f_08_ADDRESS:
		pcm_effect_3f_08(ix);
		return;
	case pcm_effect_3f_08_wait_sample_ADDRESS:
		pcm_effect_3f_08_wait_sample(ix);
		return;
	case pcm_effect_3f_09_ADDRESS:
		pcm_effect_3f_09(ix);
		return;
	case pcm_effect_3f_09_wait_sample_ADDRESS:
		pcm_effect_3f_09_wait_sample(ix);
		return;
	case pcm_effect_3f_0a_ADDRESS:
		pcm_effect_3f_0a(ix);
		return;
	case pcm_effect_3f_0a_wait_sample_ADDRESS:
		pcm_effect_3f_0a_wait_sample(ix);
		return;
	case pcm_effect_3f_0b_ADDRESS:
		pcm_effect_3f_0b(ix);
		return;
	case pcm_effect_3f_0b_wait_sample_ADDRESS:
		pcm_effect_3f_0b_wait_sample(ix);
		return;
	case pcm_effect_3f_0c_ADDRESS:
		pcm_effect_3f_0c(ix);
		return;
	case pcm_effect_3f_0c_wait_sample_ADDRESS:
		pcm_effect_3f_0c_wait_sample(ix);
		return;
	case pcm_effect_3f_0d_ADDRESS:
		pcm_effect_3f_0d(ix);
		return;
	case pcm_effect_3f_0d_wait_sample_ADDRESS:
		pcm_effect_3f_0d_wait_sample(ix);
		return;
	case pcm_effect_3f_0e_ADDRESS:
		pcm_effect_3f_0e(ix);
		return;
	case pcm_effect_3f_0e_wait_sample_ADDRESS:
		pcm_effect_3f_0e_wait_sample(ix);
		return;
	case pcm_effect_3f_0f_ADDRESS:
		pcm_effect_3f_0f(ix);
		return;
	case pcm_effect_3f_0f_wait_sample_ADDRESS:
		pcm_effect_3f_0f_wait_sample(ix);
		return;
	case pcm_effect_3f_10_ADDRESS:
		pcm_effect_3f_10(ix);
		return;
	case pcm_effect_3f_10_wait_sample_ADDRESS:
		pcm_effect_3f_10_wait_sample(ix);
		return;
	case pcm_effect_3f_11_ADDRESS:
		pcm_effect_3f_11(ix);
		return;
	case pcm_effect_3f_11_wait_sample_ADDRESS:
		pcm_effect_3f_11_wait_sample(ix);
		return;
	case pcm_effect_3f_12_ADDRESS:
		pcm_effect_3f_12(ix);
		return;
	case pcm_effect_3f_12_wait_sample_ADDRESS:
		pcm_effect_3f_12_wait_sample(ix);
		return;
	case pcm_effect_3f_13_ADDRESS:
		pcm_effect_3f_13(ix);
		return;
	case pcm_effect_3f_13_wait_sample_ADDRESS:
		pcm_effect_3f_13_wait_sample(ix);
		return;
	case pcm_effect_3f_14_ADDRESS:
		pcm_effect_3f_14(ix);
		return;
	case pcm_effect_3f_14_wait_sample_ADDRESS:
		pcm_effect_3f_14_wait_sample(ix);
		return;
	case pcm_effect_3f_15_ADDRESS:
		pcm_effect_3f_15(ix);
		return;
	case pcm_effect_3f_15_wait_sample_ADDRESS:
		pcm_effect_3f_15_wait_sample(ix);
		return;
	case pcm_effect_3f_16_ADDRESS:
		pcm_effect_3f_16(ix);
		return;
	case pcm_effect_3f_16_wait_sample_ADDRESS:
		pcm_effect_3f_16_wait_sample(ix);
		return;
	case pcm_effect_3f_17_ADDRESS:
		pcm_effect_3f_17(ix);
		return;
	case pcm_effect_3f_17_wait_sample_ADDRESS:
		pcm_effect_3f_17_wait_sample(ix);
		return;
	case pcm_effect_3f_18_ADDRESS:
		pcm_effect_3f_18(ix);
		return;
	case pcm_effect_3f_18_wait_sample_ADDRESS:
		pcm_effect_3f_18_wait_sample(ix);
		return;
	case pcm_effect_3f_19_ADDRESS:
		pcm_effect_3f_19(ix);
		return;
	case pcm_effect_3f_19_wait_sample_ADDRESS:
		pcm_effect_3f_19_wait_sample(ix);
		return;
	case pcm_effect_3f_1a_ADDRESS:
		pcm_effect_3f_1a(ix);
		return;
	case pcm_effect_3f_1a_wait_sample_ADDRESS:
		pcm_effect_3f_1a_wait_sample(ix);
		return;
	case pcm_effect_3f_1b_ADDRESS:
		pcm_effect_3f_1b(ix);
		return;
	case pcm_effect_3f_1b_wait_sample_ADDRESS:
		pcm_effect_3f_1b_wait_sample(ix);
		return;
	case pcm_effect_3f_1c_ADDRESS:
		pcm_effect_3f_1c(ix);
		return;
	case pcm_effect_3f_1c_wait_sample_ADDRESS:
		pcm_effect_3f_1c_wait_sample(ix);
		return;
	case pcm_effect_3f_1d_ADDRESS:
		pcm_effect_3f_1d(ix);
		return;
	case pcm_effect_3f_1d_wait_sample_ADDRESS:
		pcm_effect_3f_1d_wait_sample(ix);
		return;
	case pcm_effect_3f_1e_ADDRESS:
		pcm_effect_3f_1e(ix);
		return;
	case pcm_effect_3f_1e_wait_sample_ADDRESS:
		pcm_effect_3f_1e_wait_sample(ix);
		return;
	case pcm_effect_3f_1f_ADDRESS:
		pcm_effect_3f_1f(ix);
		return;
	case pcm_effect_3f_1f_wait_sample_ADDRESS:
		pcm_effect_3f_1f_wait_sample(ix);
		return;
	case pcm_effect_3f_20_ADDRESS:
		pcm_effect_3f_20(ix);
		return;
	case pcm_effect_3f_20_wait_sample_ADDRESS:
		pcm_effect_3f_20_wait_sample(ix);
		return;
	case pcm_effect_3f_21_ADDRESS:
		pcm_effect_3f_21(ix);
		return;
	case pcm_effect_3f_21_wait_sample_ADDRESS:
		pcm_effect_3f_21_wait_sample(ix);
		return;
	case pcm_effect_3f_22_ADDRESS:
		pcm_effect_3f_22(ix);
		return;
	case pcm_effect_3f_22_wait_sample_ADDRESS:
		pcm_effect_3f_22_wait_sample(ix);
		return;
	case pcm_effect_3f_23_ADDRESS:
		pcm_effect_3f_23(ix);
		return;
	case pcm_effect_3f_23_wait_sample_ADDRESS:
		pcm_effect_3f_23_wait_sample(ix);
		return;
	case pcm_effect_3f_24_ADDRESS:
		pcm_effect_3f_24(ix);
		return;
	case pcm_effect_3f_24_wait_sample_ADDRESS:
		pcm_effect_3f_24_wait_sample(ix);
		return;
	case pcm_effect_3f_25_ADDRESS:
		pcm_effect_3f_25(ix);
		return;
	case pcm_effect_3f_25_wait_sample_ADDRESS:
		pcm_effect_3f_25_wait_sample(ix);
		return;
	case pcm_effect_3f_26_ADDRESS:
		pcm_effect_3f_26(ix);
		return;
	case pcm_effect_3f_26_wait_sample_ADDRESS:
		pcm_effect_3f_26_wait_sample(ix);
		return;
	case pcm_effect_3f_27_ADDRESS:
		pcm_effect_3f_27(ix);
		return;
	case pcm_effect_3f_27_wait_sample_ADDRESS:
		pcm_effect_3f_27_wait_sample(ix);
		return;
	case pcm_effect_3f_28_ADDRESS:
		pcm_effect_3f_28(ix);
		return;
	case pcm_effect_3f_28_wait_sample_ADDRESS:
		pcm_effect_3f_28_wait_sample(ix);
		return;
	case pcm_effect_3f_29_ADDRESS:
		pcm_effect_3f_29(ix);
		return;
	case pcm_effect_3f_29_wait_sample_ADDRESS:
		pcm_effect_3f_29_wait_sample(ix);
		return;
	case pcm_effect_3f_2a_ADDRESS:
		pcm_effect_3f_2a(ix);
		return;
	case pcm_effect_3f_2a_wait_sample_ADDRESS:
		pcm_effect_3f_2a_wait_sample(ix);
		return;
	case pcm_effect_3f_2b_ADDRESS:
		pcm_effect_3f_2b(ix);
		return;
	case pcm_effect_3f_2b_wait_sample_ADDRESS:
		pcm_effect_3f_2b_wait_sample(ix);
		return;
	case pcm_effect_3f_2c_ADDRESS:
		pcm_effect_3f_2c(ix);
		return;
	case pcm_effect_3f_2c_wait_sample_ADDRESS:
		pcm_effect_3f_2c_wait_sample(ix);
		return;
	case pcm_effect_3f_2d_ADDRESS:
		pcm_effect_3f_2d(ix);
		return;
	case pcm_effect_3f_2d_wait_sample_ADDRESS:
		pcm_effect_3f_2d_wait_sample(ix);
		return;
	case pcm_effect_3f_2e_ADDRESS:
		pcm_effect_3f_2e(ix);
		return;
	case pcm_effect_3f_2e_wait_sample_ADDRESS:
		pcm_effect_3f_2e_wait_sample(ix);
		return;
	case pcm_effect_3f_2f_ADDRESS:
		pcm_effect_3f_2f(ix);
		return;
	case pcm_effect_3f_30_ADDRESS:
		pcm_effect_3f_30(ix);
		return;
	case pcm_effect_3f_30_wait_sample_ADDRESS:
		pcm_effect_3f_30_wait_sample(ix);
		return;
	case pcm_effect_3f_31_ADDRESS:
		pcm_effect_3f_31(ix);
		return;
	case pcm_effect_3f_31_wait_sample_ADDRESS:
		pcm_effect_3f_31_wait_sample(ix);
		return;
	case pcm_effect_3f_32_ADDRESS:
		pcm_effect_3f_32(ix);
		return;
	case pcm_effect_3f_32_wait_sample_ADDRESS:
		pcm_effect_3f_32_wait_sample(ix);
		return;
	case pcm_effect_3f_33_ADDRESS:
		pcm_effect_3f_33(ix);
		return;
	case pcm_effect_3f_33_wait_sample_ADDRESS:
		pcm_effect_3f_33_wait_sample(ix);
		return;
	case pcm_effect_3f_34_ADDRESS:
		pcm_effect_3f_34(ix);
		return;
	case pcm_effect_3f_34_wait_sample_ADDRESS:
		pcm_effect_3f_34_wait_sample(ix);
		return;
	case pcm_effect_3f_35_ADDRESS:
		pcm_effect_3f_35(ix);
		return;
	case pcm_effect_3f_35_wait_sample_ADDRESS:
		pcm_effect_3f_35_wait_sample(ix);
		return;
	case pcm_effect_3f_36_ADDRESS:
		pcm_effect_3f_36(ix);
		return;
	case pcm_effect_3f_36_wait_sample_ADDRESS:
		pcm_effect_3f_36_wait_sample(ix);
		return;
	case pcm_effect_3f_37_ADDRESS:
		pcm_effect_3f_37(ix);
		return;
	case pcm_effect_3f_37_wait_sample_ADDRESS:
		pcm_effect_3f_37_wait_sample(ix);
		return;
	case pcm_effect_3f_38_ADDRESS:
		pcm_effect_3f_38(ix);
		return;
	case pcm_effect_3f_38_wait_sample_ADDRESS:
		pcm_effect_3f_38_wait_sample(ix);
		return;
	case pcm_effect_3f_39_ADDRESS:
		pcm_effect_3f_39(ix);
		return;
	case pcm_effect_3f_39_wait_sample_ADDRESS:
		pcm_effect_3f_39_wait_sample(ix);
		return;
	case pcm_effect_3f_3a_ADDRESS:
		pcm_effect_3f_3a(ix);
		return;
	case pcm_effect_3f_3a_wait_sample_ADDRESS:
		pcm_effect_3f_3a_wait_sample(ix);
		return;
	case pcm_effect_3f_3b_ADDRESS:
		pcm_effect_3f_3b(ix);
		return;
	case pcm_effect_3f_3b_wait_sample_ADDRESS:
		pcm_effect_3f_3b_wait_sample(ix);
		return;
	case pcm_effect_42_ADDRESS:
		pcm_effect_42(ix);
		return;
	case pcm_effect_41_ADDRESS:
		pcm_effect_41(ix);
		return;
	case pcm_effect_40_ADDRESS:
		pcm_effect_40(ix);
		return;
	case pcm_effect_42_retrigger_ADDRESS:
		pcm_effect_42_retrigger(ix);
		return;
	case pcm_effect_42_setup_2_ADDRESS:
		pcm_effect_42_setup_2(ix);
		return;
	case pcm_effect_43_ADDRESS:
		pcm_effect_43(ix);
		return;
	case pcm_effect_43_wait_sample_ADDRESS:
		pcm_effect_43_wait_sample(ix);
		return;
	case pcm_effect_44_ADDRESS:
		pcm_effect_44(ix);
		return;
	case pcm_effect_44_wait_sample_ADDRESS:
		pcm_effect_44_wait_sample(ix);
		return;
	case pcm_effect_45_ADDRESS:
		pcm_effect_45(ix);
		return;
	case pcm_effect_45_wait_sample_ADDRESS:
		pcm_effect_45_wait_sample(ix);
		return;
	case pcm_effect_46_ADDRESS:
		pcm_effect_46(ix);
		return;
	case pcm_effect_46_retrigger_ADDRESS:
		pcm_effect_46_retrigger(ix);
		return;
	case pcm_effect_47_ADDRESS:
		pcm_effect_47(ix);
		return;
	case pcm_effect_47_wait_sample_ADDRESS:
		pcm_effect_47_wait_sample(ix);
		return;
	case pcm_effect_48_ADDRESS:
		pcm_effect_48(ix);
		return;
	case pcm_effect_48_wait_sample_ADDRESS:
		pcm_effect_48_wait_sample(ix);
		return;
	case pcm_effect_49_ADDRESS:
		pcm_effect_49(ix);
		return;
	case pcm_effect_49_wait_sample_ADDRESS:
		pcm_effect_49_wait_sample(ix);
		return;
	case pcm_effect_4a_ADDRESS:
		pcm_effect_4a(ix);
		return;
	case pcm_effect_4a_wait_sample_ADDRESS:
		pcm_effect_4a_wait_sample(ix);
		return;
	case pcm_effect_4b_ADDRESS:
		pcm_effect_4b(ix);
		return;
	case pcm_effect_4b_wait_sample_ADDRESS:
		pcm_effect_4b_wait_sample(ix);
		return;
	case pcm_effect_4c_ADDRESS:
		pcm_effect_4c(ix);
		return;
	case pcm_effect_4c_wait_sample_ADDRESS:
		pcm_effect_4c_wait_sample(ix);
		return;
	case pcm_effect_4d_ADDRESS:
		pcm_effect_4d(ix);
		return;
	case pcm_effect_4d_wait_sample_ADDRESS:
		pcm_effect_4d_wait_sample(ix);
		return;
	case pcm_effect_4e_ADDRESS:
		pcm_effect_4e(ix);
		return;
	case pcm_effect_4e_wait_sample_ADDRESS:
		pcm_effect_4e_wait_sample(ix);
		return;
	case pcm_effect_4f_ADDRESS:
		pcm_effect_4f(ix);
		return;
	case pcm_effect_4f_wait_sample_ADDRESS:
		pcm_effect_4f_wait_sample(ix);
		return;
	case pcm_effect_50_ADDRESS:
		pcm_effect_50(ix);
		return;
	case pcm_effect_50_fade_ADDRESS:
		pcm_effect_50_fade(ix);
		return;
	case pcm_effect_50_wait_sample_ADDRESS:
		pcm_effect_50_wait_sample(ix);
		return;
	case pcm_effect_51_ADDRESS:
		pcm_effect_51(ix);
		return;
	case pcm_effect_51_wait_sample_ADDRESS:
		pcm_effect_51_wait_sample(ix);
		return;
	case pcm_effect_52_ADDRESS:
		pcm_effect_52(ix);
		return;
	case pcm_effect_52_delay_ADDRESS:
		pcm_effect_52_delay(ix);
		return;
	case pcm_effect_52_hold_ADDRESS:
		pcm_effect_52_hold(ix);
		return;
	case pcm_effect_53_ADDRESS:
		pcm_effect_53(ix);
		return;
	case pcm_effect_53_wait_sample_ADDRESS:
		pcm_effect_53_wait_sample(ix);
		return;
	case pcm_effect_54_ADDRESS:
		pcm_effect_54(ix);
		return;
	case pcm_effect_54_modulate_ADDRESS:
		pcm_effect_54_modulate(ix);
		return;
	case pcm_effect_54_wait_sample_ADDRESS:
		pcm_effect_54_wait_sample(ix);
		return;
	case pcm_effect_55_ADDRESS:
		pcm_effect_55(ix);
		return;
	case pcm_effect_55_wait_sample_ADDRESS:
		pcm_effect_55_wait_sample(ix);
		return;
	case pcm_effect_56_ADDRESS:
		pcm_effect_56(ix);
		return;
	case pcm_effect_56_retrigger_ADDRESS:
		pcm_effect_56_retrigger(ix);
		return;
	case pcm_effect_56_retrigger_2_ADDRESS:
		pcm_effect_56_retrigger_2(ix);
		return;
	case pcm_effect_56_wait_sample_ADDRESS:
		pcm_effect_56_wait_sample(ix);
		return;
	case pcm_effect_57_ADDRESS:
		pcm_effect_57(ix);
		return;
	case pcm_effect_57_retrigger_ADDRESS:
		pcm_effect_57_retrigger(ix);
		return;
	case pcm_effect_57_note_ADDRESS:
		pcm_effect_57_note(ix);
		return;
	case pcm_effect_57_wait_sample_ADDRESS:
		pcm_effect_57_wait_sample(ix);
		return;
	case pcm_effect_58_ADDRESS:
		pcm_effect_58(ix);
		return;
	case pcm_effect_58_retrigger_ADDRESS:
		pcm_effect_58_retrigger(ix);
		return;
	case pcm_effect_59_ADDRESS:
		pcm_effect_59(ix);
		return;
	case pcm_effect_59_wait_sample_ADDRESS:
		pcm_effect_59_wait_sample(ix);
		return;
	case pcm_effect_5a_ADDRESS:
		pcm_effect_5a(ix);
		return;
	case pcm_effect_5a_wait_sample_ADDRESS:
		pcm_effect_5a_wait_sample(ix);
		return;
	case pcm_effect_5b_ADDRESS:
		pcm_effect_5b(ix);
		return;
	case pcm_effect_5b_wait_sample_ADDRESS:
		pcm_effect_5b_wait_sample(ix);
		return;
	case pcm_effect_5c_ADDRESS:
		pcm_effect_5c(ix);
		return;
	case pcm_effect_5c_delay_ADDRESS:
		pcm_effect_5c_delay(ix);
		return;
	case pcm_effect_5c_hold_ADDRESS:
		pcm_effect_5c_hold(ix);
		return;
	case pcm_effect_5d_ADDRESS:
		pcm_effect_5d(ix);
		return;
	case pcm_effect_5d_delay_ADDRESS:
		pcm_effect_5d_delay(ix);
		return;
	case pcm_effect_5d_hold_ADDRESS:
		pcm_effect_5d_hold(ix);
		return;
	case pcm_effect_5e_ADDRESS:
		pcm_effect_5e(ix);
		return;
	case pcm_effect_5e_wait_sample_ADDRESS:
		pcm_effect_5e_wait_sample(ix);
		return;
	case pcm_effect_5f_ADDRESS:
		pcm_effect_5f(ix);
		return;
	case pcm_effect_5f_wait_sample_ADDRESS:
		pcm_effect_5f_wait_sample(ix);
		return;
	case pcm_effect_60_ADDRESS:
		pcm_effect_60(ix);
		return;
	case pcm_effect_60_wait_sample_ADDRESS:
		pcm_effect_60_wait_sample(ix);
		return;
	case pcm_effect_61_ADDRESS:
		pcm_effect_61(ix);
		return;
	case pcm_effect_61_wait_sample_ADDRESS:
		pcm_effect_61_wait_sample(ix);
		return;
	case pcm_effect_62_ADDRESS:
		pcm_effect_62(ix);
		return;
	case pcm_effect_62_wait_sample_ADDRESS:
		pcm_effect_62_wait_sample(ix);
		return;
	case pcm_effect_63_ADDRESS:
		pcm_effect_63(ix);
		return;
	case pcm_effect_63_wait_sample_ADDRESS:
		pcm_effect_63_wait_sample(ix);
		return;
	case pcm_effect_64_ADDRESS:
		pcm_effect_64(ix);
		return;
	case pcm_effect_64_wait_sample_ADDRESS:
		pcm_effect_64_wait_sample(ix);
		return;
	case pcm_effect_65_ADDRESS:
		pcm_effect_65(ix);
		return;
	case pcm_effect_65_wait_sample_ADDRESS:
		pcm_effect_65_wait_sample(ix);
		return;
	case pcm_effect_66_ADDRESS:
		pcm_effect_66(ix);
		return;
	case pcm_effect_66_wait_sample_ADDRESS:
		pcm_effect_66_wait_sample(ix);
		return;
	case pcm_effect_67_ADDRESS:
		pcm_effect_67(ix);
		return;
	case pcm_effect_67_wait_sample_ADDRESS:
		pcm_effect_67_wait_sample(ix);
		return;
	case pcm_effect_68_ADDRESS:
		pcm_effect_68(ix);
		return;
	case pcm_effect_68_wait_sample_ADDRESS:
		pcm_effect_68_wait_sample(ix);
		return;
	case pcm_effect_69_ADDRESS:
		pcm_effect_69(ix);
		return;
	case pcm_effect_69_wait_sample_ADDRESS:
		pcm_effect_69_wait_sample(ix);
		return;
	case pcm_effect_6a_ADDRESS:
		pcm_effect_6a(ix);
		return;
	case pcm_effect_6a_wait_sample_ADDRESS:
		pcm_effect_6a_wait_sample(ix);
		return;
	case pcm_effect_6b_ADDRESS:
		pcm_effect_6b(ix);
		return;
	case pcm_effect_6b_wait_sample_ADDRESS:
		pcm_effect_6b_wait_sample(ix);
		return;
	case pcm_effect_6c_ADDRESS:
		pcm_effect_6c(ix);
		return;
	case pcm_effect_6c_wait_sample_ADDRESS:
		pcm_effect_6c_wait_sample(ix);
		return;
	case pcm_effect_6d_ADDRESS:
		pcm_effect_6d(ix);
		return;
	case pcm_effect_6d_wait_sample_ADDRESS:
		pcm_effect_6d_wait_sample(ix);
		return;
	case pcm_effect_6e_ADDRESS:
		pcm_effect_6e(ix);
		return;
	case pcm_effect_6e_wait_sample_ADDRESS:
		pcm_effect_6e_wait_sample(ix);
		return;
	case pcm_effect_6f_ADDRESS:
		pcm_effect_6f(ix);
		return;
	case pcm_effect_6f_wait_sample_ADDRESS:
		pcm_effect_6f_wait_sample(ix);
		return;
	case pcm_effect_70_ADDRESS:
		pcm_effect_70(ix);
		return;
	case pcm_effect_70_wait_sample_ADDRESS:
		pcm_effect_70_wait_sample(ix);
		return;
	case pcm_effect_71_ADDRESS:
		pcm_effect_71(ix);
		return;
	case pcm_effect_71_wait_sample_ADDRESS:
		pcm_effect_71_wait_sample(ix);
		return;
	case pcm_effect_72_ADDRESS:
		pcm_effect_72(ix);
		return;
	case pcm_effect_72_wait_sample_ADDRESS:
		pcm_effect_72_wait_sample(ix);
		return;
	case pcm_effect_73_ADDRESS:
		pcm_effect_73(ix);
		return;
	case pcm_effect_73_wait_sample_ADDRESS:
		pcm_effect_73_wait_sample(ix);
		return;
	case pcm_effect_74_ADDRESS:
		pcm_effect_74(ix);
		return;
	case pcm_effect_74_wait_sample_ADDRESS:
		pcm_effect_74_wait_sample(ix);
		return;
	case pcm_effect_75_ADDRESS:
		pcm_effect_75(ix);
		return;
	case pcm_effect_75_wait_sample_ADDRESS:
		pcm_effect_75_wait_sample(ix);
		return;
	case pcm_effect_76_ADDRESS:
		pcm_effect_76(ix);
		return;
	case pcm_effect_76_wait_sample_ADDRESS:
		pcm_effect_76_wait_sample(ix);
		return;
	case pcm_effect_77_ADDRESS:
		pcm_effect_77(ix);
		return;
	case pcm_effect_77_delay_ADDRESS:
		pcm_effect_77_delay(ix);
		return;
	case pcm_effect_77_hold_ADDRESS:
		pcm_effect_77_hold(ix);
		return;
	case pcm_effect_78_ADDRESS:
		pcm_effect_78(ix);
		return;
	case pcm_effect_79_ADDRESS:
		pcm_effect_79(ix);
		return;
	case pcm_effect_79_wait_sample_ADDRESS:
		pcm_effect_79_wait_sample(ix);
		return;
	case pcm_effect_7a_ADDRESS:
		pcm_effect_7a(ix);
		return;
	case pcm_effect_7a_retrigger_ADDRESS:
		pcm_effect_7a_retrigger(ix);
		return;
	case pcm_effect_7a_retrigger_2_ADDRESS:
		pcm_effect_7a_retrigger_2(ix);
		return;
	case pcm_effect_7a_retrigger_3_ADDRESS:
		pcm_effect_7a_retrigger_3(ix);
		return;
	case pcm_effect_7b_ADDRESS:
		pcm_effect_7b(ix);
		return;
	case pcm_effect_7b_wait_sample_ADDRESS:
		pcm_effect_7b_wait_sample(ix);
		return;
	case pcm_effect_7c_ADDRESS:
		pcm_effect_7c(ix);
		return;
	case pcm_effect_7c_retrigger_ADDRESS:
		pcm_effect_7c_retrigger(ix);
		return;
	case pcm_effect_7c_retrigger_2_ADDRESS:
		pcm_effect_7c_retrigger_2(ix);
		return;
	case pcm_effect_7c_retrigger_3_ADDRESS:
		pcm_effect_7c_retrigger_3(ix);
		return;
	case pcm_effect_7d_ADDRESS:
		pcm_effect_7d(ix);
		return;
	case pcm_effect_7d_wait_sample_ADDRESS:
		pcm_effect_7d_wait_sample(ix);
		return;
	case pcm_effect_7e_ADDRESS:
		pcm_effect_7e(ix);
		return;
	case pcm_effect_7e_retrigger_ADDRESS:
		pcm_effect_7e_retrigger(ix);
		return;
	case pcm_effect_7e_retrigger_2_ADDRESS:
		pcm_effect_7e_retrigger_2(ix);
		return;
	case pcm_effect_7f_ADDRESS:
		pcm_effect_7f(ix);
		return;
	case pcm_effect_7f_retrigger_ADDRESS:
		pcm_effect_7f_retrigger(ix);
		return;
	case music_pitch_envelope_1_ADDRESS:
		music_pitch_envelope_1(ix);
		return;
	case music_pitch_envelope_2_ADDRESS:
		music_pitch_envelope_2(ix);
		return;
	case music_pitch_envelope_3_ADDRESS:
		music_pitch_envelope_3(ix);
		return;
	case music_pitch_envelope_4_ADDRESS:
		music_pitch_envelope_4(ix);
		return;
	case music_note_tick_ADDRESS:
		music_note_tick(ix);
		return;
	case fm_drum_1_1_ADDRESS:
		fm_drum_1_1(ix);
		return;
	case fm_drum_1_1_slide_ADDRESS:
		fm_drum_1_1_slide(ix);
		return;
	case fm_drum_1_2_ADDRESS:
		fm_drum_1_2(ix);
		return;
	case fm_drum_1_2_hold_ADDRESS:
		fm_drum_1_2_hold(ix);
		return;
	case fm_drum_1_3_ADDRESS:
		fm_drum_1_3(ix);
		return;
	case fm_drum_1_3_hold_ADDRESS:
		fm_drum_1_3_hold(ix);
		return;
	case fm_drum_1_4_ADDRESS:
		fm_drum_1_4(ix);
		return;
	case fm_drum_1_4_hold_ADDRESS:
		fm_drum_1_4_hold(ix);
		return;
	case fm_drum_1_5_ADDRESS:
		fm_drum_1_5(ix);
		return;
	case fm_drum_1_5_slide_ADDRESS:
		fm_drum_1_5_slide(ix);
		return;
	case fm_drum_1_6_ADDRESS:
		fm_drum_1_6(ix);
		return;
	case fm_drum_1_6_slide_ADDRESS:
		fm_drum_1_6_slide(ix);
		return;
	case fm_drum_1_7_ADDRESS:
		fm_drum_1_7(ix);
		return;
	case fm_drum_1_7_slide_ADDRESS:
		fm_drum_1_7_slide(ix);
		return;
	case fm_drum_1_8_ADDRESS:
		fm_drum_1_8(ix);
		return;
	case fm_drum_1_8_slide_ADDRESS:
		fm_drum_1_8_slide(ix);
		return;
	case fm_drum_1_9_ADDRESS:
		fm_drum_1_9(ix);
		return;
	case fm_drum_2_1_ADDRESS:
		fm_drum_2_1(ix);
		return;
	case fm_drum_2_1_slide_ADDRESS:
		fm_drum_2_1_slide(ix);
		return;
	case fm_drum_2_2_ADDRESS:
		fm_drum_2_2(ix);
		return;
	case fm_drum_2_2_slide_ADDRESS:
		fm_drum_2_2_slide(ix);
		return;
	case fm_drum_2_3_ADDRESS:
		fm_drum_2_3(ix);
		return;
	case fm_drum_2_3_slide_ADDRESS:
		fm_drum_2_3_slide(ix);
		return;
	case fm_drum_2_4_ADDRESS:
		fm_drum_2_4(ix);
		return;
	case fm_drum_2_4_slide_ADDRESS:
		fm_drum_2_4_slide(ix);
		return;
	case fm_drum_2_5_ADDRESS:
		fm_drum_2_5(ix);
		return;
	case fm_drum_2_5_slide_ADDRESS:
		fm_drum_2_5_slide(ix);
		return;
	case fm_drum_2_6_ADDRESS:
		fm_drum_2_6(ix);
		return;
	case pcm_drum_1_1_ADDRESS:
		pcm_drum_1_1(ix);
		return;
	case pcm_drum_1_2_ADDRESS:
		pcm_drum_1_2(ix);
		return;
	case pcm_drum_1_3_ADDRESS:
		pcm_drum_1_3(ix);
		return;
	case pcm_drum_1_4_ADDRESS:
		pcm_drum_1_4(ix);
		return;
	case pcm_drum_1_5_ADDRESS:
		pcm_drum_1_5(ix);
		return;
	case pcm_drum_1_6_ADDRESS:
		pcm_drum_1_6(ix);
		return;
	case pcm_drum_1_7_ADDRESS:
		pcm_drum_1_7(ix);
		return;
	case pcm_drum_1_8_ADDRESS:
		pcm_drum_1_8(ix);
		return;
	case pcm_drum_1_9_ADDRESS:
		pcm_drum_1_9(ix);
		return;
	case pcm_drum_1_a_ADDRESS:
		pcm_drum_1_a(ix);
		return;
	case pcm_drum_1_b_ADDRESS:
		pcm_drum_1_b(ix);
		return;
	case pcm_drum_1_b_note_ADDRESS:
		pcm_drum_1_b_note(ix);
		return;
	case pcm_drum_1_b_note_2_ADDRESS:
		pcm_drum_1_b_note_2(ix);
		return;
	case pcm_drum_1_c_ADDRESS:
		pcm_drum_1_c(ix);
		return;
	case pcm_drum_1_c_note_ADDRESS:
		pcm_drum_1_c_note(ix);
		return;
	case pcm_drum_1_c_note_2_ADDRESS:
		pcm_drum_1_c_note_2(ix);
		return;
	case pcm_drum_1_c_note_3_ADDRESS:
		pcm_drum_1_c_note_3(ix);
		return;
	case pcm_drum_1_d_ADDRESS:
		pcm_drum_1_d(ix);
		return;
	case pcm_drum_1_f_ADDRESS:
		pcm_drum_1_f(ix);
		return;
	case pcm_drum_2_1_ADDRESS:
		pcm_drum_2_1(ix);
		return;
	case pcm_drum_2_2_ADDRESS:
		pcm_drum_2_2(ix);
		return;
	case pcm_drum_2_3_ADDRESS:
		pcm_drum_2_3(ix);
		return;
	case pcm_drum_2_4_ADDRESS:
		pcm_drum_2_4(ix);
		return;
	case pcm_drum_2_5_ADDRESS:
		pcm_drum_2_5(ix);
		return;
	case pcm_drum_2_6_ADDRESS:
		pcm_drum_2_6(ix);
		return;
	case pcm_drum_2_7_ADDRESS:
		pcm_drum_2_7(ix);
		return;
	case pcm_drum_2_8_ADDRESS:
		pcm_drum_2_8(ix);
		return;
	case pcm_drum_2_9_ADDRESS:
		pcm_drum_2_9(ix);
		return;
	case pcm_drum_2_a_ADDRESS:
		pcm_drum_2_a(ix);
		return;
	case pcm_drum_2_b_ADDRESS:
		pcm_drum_2_b(ix);
		return;
	case pcm_drum_2_c_ADDRESS:
		pcm_drum_2_c(ix);
		return;
	case pcm_drum_2_d_ADDRESS:
		pcm_drum_2_d(ix);
		return;
	case pcm_drum_2_e_ADDRESS:
		pcm_drum_2_e(ix);
		return;
	case pcm_drum_2_f_ADDRESS:
		pcm_drum_2_f(ix);
		return;
	case pcm_drum_3_1_ADDRESS:
		pcm_drum_3_1(ix);
		return;
	case pcm_drum_3_2_ADDRESS:
		pcm_drum_3_2(ix);
		return;
	case pcm_drum_3_3_ADDRESS:
		pcm_drum_3_3(ix);
		return;
	case pcm_drum_3_4_ADDRESS:
		pcm_drum_3_4(ix);
		return;
	case pcm_drum_3_5_ADDRESS:
		pcm_drum_3_5(ix);
		return;
	case pcm_drum_3_6_ADDRESS:
		pcm_drum_3_6(ix);
		return;
	case pcm_drum_3_7_ADDRESS:
		pcm_drum_3_7(ix);
		return;
	case pcm_drum_3_8_ADDRESS:
		pcm_drum_3_8(ix);
		return;
	case pcm_drum_3_9_ADDRESS:
		pcm_drum_3_9(ix);
		return;
	case pcm_drum_3_a_ADDRESS:
		pcm_drum_3_a(ix);
		return;
	case pcm_drum_3_b_ADDRESS:
		pcm_drum_3_b(ix);
		return;
	case pcm_drum_3_c_ADDRESS:
		pcm_drum_3_c(ix);
		return;
	case pcm_drum_3_d_ADDRESS:
		pcm_drum_3_d(ix);
		return;
	case pcm_drum_3_e_ADDRESS:
		pcm_drum_3_e(ix);
		return;
	case pcm_drum_3_f_ADDRESS:
		pcm_drum_3_f(ix);
		return;
	case pcm_drum_4_1_ADDRESS:
		pcm_drum_4_1(ix);
		return;
	case pcm_drum_4_2_ADDRESS:
		pcm_drum_4_2(ix);
		return;
	case pcm_drum_4_3_ADDRESS:
		pcm_drum_4_3(ix);
		return;
	case pcm_drum_4_4_ADDRESS:
		pcm_drum_4_4(ix);
		return;
	case pcm_drum_4_5_ADDRESS:
		pcm_drum_4_5(ix);
		return;
	case pcm_drum_4_6_ADDRESS:
		pcm_drum_4_6(ix);
		return;
	case pcm_drum_4_7_ADDRESS:
		pcm_drum_4_7(ix);
		return;
	case pcm_drum_4_8_ADDRESS:
		pcm_drum_4_8(ix);
		return;
	case pcm_drum_4_9_ADDRESS:
		pcm_drum_4_9(ix);
		return;
	case pcm_drum_4_a_ADDRESS:
		pcm_drum_4_a(ix);
		return;
	case pcm_drum_4_b_ADDRESS:
		pcm_drum_4_b(ix);
		return;
	case pcm_drum_4_c_ADDRESS:
		pcm_drum_4_c(ix);
		return;
	case pcm_drum_4_d_ADDRESS:
		pcm_drum_4_d(ix);
		return;
	case pcm_drum_4_e_ADDRESS:
		pcm_drum_4_e(ix);
		return;
	case pcm_drum_4_f_ADDRESS:
		pcm_drum_4_f(ix);
		return;
	case pcm_drum_5_1_ADDRESS:
		pcm_drum_5_1(ix);
		return;
	case pcm_drum_5_2_ADDRESS:
		pcm_drum_5_2(ix);
		return;
	case pcm_drum_5_3_ADDRESS:
		pcm_drum_5_3(ix);
		return;
	case pcm_drum_5_4_ADDRESS:
		pcm_drum_5_4(ix);
		return;
	case pcm_drum_5_5_ADDRESS:
		pcm_drum_5_5(ix);
		return;
	case pcm_drum_5_6_ADDRESS:
		pcm_drum_5_6(ix);
		return;
	case pcm_drum_5_7_ADDRESS:
		pcm_drum_5_7(ix);
		return;
	case pcm_drum_5_8_ADDRESS:
		pcm_drum_5_8(ix);
		return;
	case pcm_drum_5_9_ADDRESS:
		pcm_drum_5_9(ix);
		return;
	case pcm_drum_5_a_ADDRESS:
		pcm_drum_5_a(ix);
		return;
	case pcm_drum_5_b_ADDRESS:
		pcm_drum_5_b(ix);
		return;
	case pcm_drum_5_c_ADDRESS:
		pcm_drum_5_c(ix);
		return;
	case pcm_drum_5_d_ADDRESS:
		pcm_drum_5_d(ix);
		return;
	case pcm_drum_5_e_ADDRESS:
		pcm_drum_5_e(ix);
		return;
	case pcm_drum_5_f_ADDRESS:
		pcm_drum_5_f(ix);
		return;
	case pcm_drum_6_1_ADDRESS:
		pcm_drum_6_1(ix);
		return;
	case pcm_drum_6_2_ADDRESS:
		pcm_drum_6_2(ix);
		return;
	case pcm_drum_6_3_ADDRESS:
		pcm_drum_6_3(ix);
		return;
	case pcm_drum_6_4_ADDRESS:
		pcm_drum_6_4(ix);
		return;
	case pcm_drum_6_5_ADDRESS:
		pcm_drum_6_5(ix);
		return;
	case pcm_drum_6_6_ADDRESS:
		pcm_drum_6_6(ix);
		return;
	case pcm_drum_6_7_ADDRESS:
		pcm_drum_6_7(ix);
		return;
	case pcm_drum_6_8_ADDRESS:
		pcm_drum_6_8(ix);
		return;
	case pcm_drum_6_9_ADDRESS:
		pcm_drum_6_9(ix);
		return;
	case pcm_drum_6_a_ADDRESS:
		pcm_drum_6_a(ix);
		return;
	case pcm_drum_6_b_ADDRESS:
		pcm_drum_6_b(ix);
		return;
	case pcm_drum_6_c_ADDRESS:
		pcm_drum_6_c(ix);
		return;
	case pcm_drum_6_d_ADDRESS:
		pcm_drum_6_d(ix);
		return;
	case pcm_drum_6_e_ADDRESS:
		pcm_drum_6_e(ix);
		return;
	case pcm_drum_6_f_ADDRESS:
		pcm_drum_6_f(ix);
		return;
	case pcm_drum_7_1_ADDRESS:
		pcm_drum_7_1(ix);
		return;
	case pcm_drum_7_2_ADDRESS:
		pcm_drum_7_2(ix);
		return;
	case pcm_drum_7_3_ADDRESS:
		pcm_drum_7_3(ix);
		return;
	case pcm_drum_7_4_ADDRESS:
		pcm_drum_7_4(ix);
		return;
	case pcm_drum_7_5_ADDRESS:
		pcm_drum_7_5(ix);
		return;
	case pcm_drum_7_6_ADDRESS:
		pcm_drum_7_6(ix);
		return;
	case pcm_drum_7_7_ADDRESS:
		pcm_drum_7_7(ix);
		return;
	case pcm_drum_7_8_ADDRESS:
		pcm_drum_7_8(ix);
		return;
	case pcm_drum_7_9_ADDRESS:
		pcm_drum_7_9(ix);
		return;
	case pcm_drum_7_a_ADDRESS:
		pcm_drum_7_a(ix);
		return;
	case pcm_drum_7_b_ADDRESS:
		pcm_drum_7_b(ix);
		return;
	case pcm_drum_7_c_ADDRESS:
		pcm_drum_7_c(ix);
		return;
	case pcm_drum_7_d_ADDRESS:
		pcm_drum_7_d(ix);
		return;
	case pcm_drum_7_e_ADDRESS:
		pcm_drum_7_e(ix);
		return;
	case pcm_drum_7_f_ADDRESS:
		pcm_drum_7_f(ix);
		return;
	case pcm_drum_8_1_ADDRESS:
		pcm_drum_8_1(ix);
		return;
	case pcm_drum_8_2_ADDRESS:
		pcm_drum_8_2(ix);
		return;
	case pcm_drum_8_3_ADDRESS:
		pcm_drum_8_3(ix);
		return;
	case pcm_drum_8_4_ADDRESS:
		pcm_drum_8_4(ix);
		return;
	case pcm_drum_8_5_ADDRESS:
		pcm_drum_8_5(ix);
		return;
	case pcm_drum_8_6_ADDRESS:
		pcm_drum_8_6(ix);
		return;
	case pcm_drum_8_7_ADDRESS:
		pcm_drum_8_7(ix);
		return;
	case pcm_drum_8_8_ADDRESS:
		pcm_drum_8_8(ix);
		return;
	case pcm_drum_8_9_ADDRESS:
		pcm_drum_8_9(ix);
		return;
	case pcm_drum_8_a_ADDRESS:
		pcm_drum_8_a(ix);
		return;
	case pcm_drum_8_b_ADDRESS:
		pcm_drum_8_b(ix);
		return;
	case pcm_drum_8_c_ADDRESS:
		pcm_drum_8_c(ix);
		return;
	case pcm_drum_8_d_ADDRESS:
		pcm_drum_8_d(ix);
		return;
	case pcm_drum_8_e_ADDRESS:
		pcm_drum_8_e(ix);
		return;
	case pcm_drum_8_f_ADDRESS:
		pcm_drum_8_f(ix);
		return;
	case pcm_drum_9_1_ADDRESS:
		pcm_drum_9_1(ix);
		return;
	case pcm_drum_9_2_ADDRESS:
		pcm_drum_9_2(ix);
		return;
	case pcm_drum_9_3_ADDRESS:
		pcm_drum_9_3(ix);
		return;
	case pcm_drum_9_4_ADDRESS:
		pcm_drum_9_4(ix);
		return;
	case pcm_drum_9_5_ADDRESS:
		pcm_drum_9_5(ix);
		return;
	case pcm_drum_9_6_ADDRESS:
		pcm_drum_9_6(ix);
		return;
	case pcm_drum_9_7_ADDRESS:
		pcm_drum_9_7(ix);
		return;
	case pcm_drum_9_8_ADDRESS:
		pcm_drum_9_8(ix);
		return;
	case pcm_drum_9_9_ADDRESS:
		pcm_drum_9_9(ix);
		return;
	case pcm_drum_9_a_ADDRESS:
		pcm_drum_9_a(ix);
		return;
	case pcm_drum_9_b_ADDRESS:
		pcm_drum_9_b(ix);
		return;
	case pcm_drum_9_c_ADDRESS:
		pcm_drum_9_c(ix);
		return;
	case pcm_drum_9_d_ADDRESS:
		pcm_drum_9_d(ix);
		return;
	case pcm_drum_9_e_ADDRESS:
		pcm_drum_9_e(ix);
		return;
	case pcm_drum_a_1_ADDRESS:
		pcm_drum_a_1(ix);
		return;
	case pcm_drum_a_2_ADDRESS:
		pcm_drum_a_2(ix);
		return;
	case pcm_drum_a_3_ADDRESS:
		pcm_drum_a_3(ix);
		return;
	case pcm_drum_a_4_ADDRESS:
		pcm_drum_a_4(ix);
		return;
	case pcm_drum_a_5_ADDRESS:
		pcm_drum_a_5(ix);
		return;
	case pcm_drum_a_6_ADDRESS:
		pcm_drum_a_6(ix);
		return;
	case pcm_drum_a_7_ADDRESS:
		pcm_drum_a_7(ix);
		return;
	case pcm_drum_a_8_ADDRESS:
		pcm_drum_a_8(ix);
		return;
	case pcm_drum_a_9_ADDRESS:
		pcm_drum_a_9(ix);
		return;
	case pcm_drum_a_a_ADDRESS:
		pcm_drum_a_a(ix);
		return;
	case pcm_drum_a_b_ADDRESS:
		pcm_drum_a_b(ix);
		return;
	case pcm_drum_a_c_ADDRESS:
		pcm_drum_a_c(ix);
		return;
	case pcm_drum_a_d_ADDRESS:
		pcm_drum_a_d(ix);
		return;
	case pcm_drum_a_e_ADDRESS:
		pcm_drum_a_e(ix);
		return;
	case pcm_drum_a_f_ADDRESS:
		pcm_drum_a_f(ix);
		return;
	case pcm_drum_b_1_ADDRESS:
		pcm_drum_b_1(ix);
		return;
	case pcm_drum_b_2_ADDRESS:
		pcm_drum_b_2(ix);
		return;
	case pcm_drum_b_3_ADDRESS:
		pcm_drum_b_3(ix);
		return;
	case pcm_drum_b_4_ADDRESS:
		pcm_drum_b_4(ix);
		return;
	case pcm_drum_b_5_ADDRESS:
		pcm_drum_b_5(ix);
		return;
	case pcm_drum_b_6_ADDRESS:
		pcm_drum_b_6(ix);
		return;
	case pcm_drum_b_7_ADDRESS:
		pcm_drum_b_7(ix);
		return;
	case pcm_drum_b_8_ADDRESS:
		pcm_drum_b_8(ix);
		return;
	case pcm_drum_b_9_ADDRESS:
		pcm_drum_b_9(ix);
		return;
	case pcm_drum_b_a_ADDRESS:
		pcm_drum_b_a(ix);
		return;
	case pcm_drum_b_b_ADDRESS:
		pcm_drum_b_b(ix);
		return;
	case pcm_drum_b_c_ADDRESS:
		pcm_drum_b_c(ix);
		return;
	case pcm_drum_b_d_ADDRESS:
		pcm_drum_b_d(ix);
		return;
	case pcm_drum_b_e_ADDRESS:
		pcm_drum_b_e(ix);
		return;
	case pcm_drum_b_f_ADDRESS:
		pcm_drum_b_f(ix);
		return;
	}
}
