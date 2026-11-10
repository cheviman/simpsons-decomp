/**
 *    Name:        main.c
 *    Description: the reset and its self test, the commands from the 053248, the main loop
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the Z80 sound program decompiled into C by
 *    tools/decompile_sound.py, with the names of sound_symbols.txt.
 */
#include "sound.h"

/* The reset: interrupt mode 1, the stack at the top of the RAM, no answer to the 053248 yet; the RAM
   test (55, then AA, written and read back in every byte: bit 0 of self_test_failures when one fails),
   then check_rom. */
uint16_t BOARD_ORIGINAL(sound_reset)(void)
{
	uint16_t address = 0, bytes_left = 0;

	z80_block(28);
	z80_block(61);
	z80_write16(PCM_FC02, 0u);
	self_test_failures = 0u;
	address = held_command_ADDRESS;
	bytes_left = 0x800u;
	do
	{
		z80_block(31);
		z80_write8(address, 0x55u);
		if (0x55u != z80_read8(address))
		{
			z80_block(16);
			self_test_failures = self_test_failures | 1u;
			return check_rom();
		}
		z80_block(30);
		address++;
		bytes_left--;
	} while ((uint8_t)(bytes_left | (bytes_left >> 8)) != 0u);
	z80_block(20);
	address = held_command_ADDRESS;
	bytes_left = 0x800u;
	do
	{
		z80_block(31);
		z80_write8(address, 0xAAu);
		if (0xAAu != z80_read8(address))
		{
			z80_block(16);
			self_test_failures = self_test_failures | 1u;
			return check_rom();
		}
		z80_block(30);
		address++;
		bytes_left--;
	} while ((uint8_t)(bytes_left | (bytes_left >> 8)) != 0u);
	z80_block(10);
	return check_rom();
}

/* The interrupt the 053248 raises: its command and argument from the K053260's ports (unless
   held_command holds one, which nothing sets). F0 answers 30, F1 to F7 hand back self_test_failures and
   the bytes of the three sums, FE adds the two sample ROMs up again, FF resets; while the RAM test has
   failed nothing else runs (self_test_failed); F8 counts in command_f8_count, FD fades the music out. 3F
   starts the PCM effect of effect_handlers_2 the argument picks on a K053260 record, 7F hands the
   argument to the record playing effect 7F; any other command goes to start_sound, and so do as many
   commands after it as the argument says. */
void sound_command(void)
{
	uint8_t command = 0, failure_bits = 0, failures = 0, priority = 0, sound_2 = 0, volume = 0;
	uint16_t bytes_left = 0, channel = 0, count = 0, handler = 0, program_sum = 0, sample_1_sum = 0, sample_2_sum = 0, sound = 0, stride = 0, sum = 0;
	uint8_t saved_sound_2 = 0;
	uint16_t stack = 0, saved_sound = 0;
	uint8_t t20 = 0, t21 = 0, t22 = 0, t23 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0, t15 = 0, t16 = 0, t17 = 0, t18 = 0, t19 = 0;

	z80_block(10);
	z80_block(38);
	sound = held_command;
	if ((uint8_t)((sound >> 8) | sound) == 0u)
	{
		z80_block(20);
		sound = z80_read16(PCM_FC00);
	}
	z80_block(21);
	command = (uint8_t)sound;
	if (command >= 0xF0u)
	{
		z80_block(17);
		if (command == 0xF0u)
		{
			z80_block(57);
			z80_write16(PCM_FC02, IN_PAGE(sound, 0x30u));
			failures = self_test_failures;
			self_test_failures = failures;
			if ((failures & 1u) != 0u)
			{
				self_test_failed();
				return;
			}
			z80_block(10);
			return;
		}
		z80_block(17);
		if (command == 0xF1u)
		{
			z80_block(62);
			failures = self_test_failures;
			z80_write16(PCM_FC02, IN_PAGE(sound, failures));
			self_test_failures = failures;
			if ((failures & 1u) != 0u)
			{
				self_test_failed();
				return;
			}
			z80_block(10);
			return;
		}
		z80_block(17);
		if (command == 0xF2u)
		{
			z80_block(66);
			t1 = sound;
			program_sum = program_rom_sum;
			t2 = program_sum;
			program_rom_sum = t2;
			z80_write16(PCM_FC02, (t1 & ~0xFFu) | (uint8_t)program_sum);
			failures = self_test_failures;
			self_test_failures = failures;
			if ((failures & 1u) != 0u)
			{
				self_test_failed();
				return;
			}
			z80_block(10);
			return;
		}
		z80_block(17);
		if (command == 0xF3u)
		{
			z80_block(66);
			t3 = sound;
			program_sum = program_rom_sum;
			t4 = program_sum;
			program_rom_sum = t4;
			z80_write16(PCM_FC02, (t3 & ~0xFFu) | (program_sum >> 8));
			failures = self_test_failures;
			self_test_failures = failures;
			if ((failures & 1u) != 0u)
			{
				self_test_failed();
				return;
			}
			z80_block(10);
			return;
		}
		z80_block(17);
		if (command == 0xF4u)
		{
			z80_block(66);
			t5 = sound;
			sample_1_sum = sample_rom_1_sum;
			t6 = program_rom_sum;
			program_rom_sum = t6;
			sample_rom_1_sum = sample_1_sum;
			z80_write16(PCM_FC02, (t5 & ~0xFFu) | (uint8_t)sample_1_sum);
			failures = self_test_failures;
			self_test_failures = failures;
			if ((failures & 1u) != 0u)
			{
				self_test_failed();
				return;
			}
			z80_block(10);
			return;
		}
		z80_block(17);
		if (command == 0xF5u)
		{
			z80_block(66);
			t7 = sound;
			sample_1_sum = sample_rom_1_sum;
			t8 = program_rom_sum;
			program_rom_sum = t8;
			sample_rom_1_sum = sample_1_sum;
			z80_write16(PCM_FC02, (t7 & ~0xFFu) | (sample_1_sum >> 8));
			failures = self_test_failures;
			self_test_failures = failures;
			if ((failures & 1u) != 0u)
			{
				self_test_failed();
				return;
			}
			z80_block(10);
			return;
		}
		z80_block(17);
		if (command == 0xF6u)
		{
			z80_block(66);
			t9 = sound;
			sample_2_sum = sample_rom_2_sum;
			t10 = program_rom_sum;
			program_rom_sum = t10;
			sample_rom_2_sum = sample_2_sum;
			z80_write16(PCM_FC02, (t9 & ~0xFFu) | (uint8_t)sample_2_sum);
			failures = self_test_failures;
			self_test_failures = failures;
			if ((failures & 1u) != 0u)
			{
				self_test_failed();
				return;
			}
			z80_block(10);
			return;
		}
		z80_block(17);
		if (command == 0xF7u)
		{
			z80_block(66);
			t11 = sound;
			sample_2_sum = sample_rom_2_sum;
			t12 = program_rom_sum;
			program_rom_sum = t12;
			sample_rom_2_sum = sample_2_sum;
			z80_write16(PCM_FC02, (t11 & ~0xFFu) | (sample_2_sum >> 8));
			failures = self_test_failures;
			self_test_failures = failures;
			if ((failures & 1u) != 0u)
			{
				self_test_failed();
				return;
			}
			z80_block(10);
			return;
		}
		z80_block(17);
		if (command == 0xFEu)
		{
			z80_block(140);
			z80_write8(PCM_FC28, 0u);
			z80_write8(PCM_FC2F, 1u);
			sum = 0u;
			z80_write16(PCM_FC0A, 0u);
			z80_write16(PCM_FC0C, 0u);
			z80_write8(PCM_FC0E, 0u);
			bytes_left = 0u;
			do
			{
				z80_block(59);
				sum += z80_read8(PCM_FC2E);
				bytes_left--;
			} while ((uint8_t)((bytes_left >> 8) | bytes_left) != 0u);
			z80_block(90);
			z80_write16(PCM_FC0A, 0u);
			z80_write16(PCM_FC0C, 0u);
			z80_write8(PCM_FC0E, 1u);
			bytes_left = 0u;
			do
			{
				z80_block(59);
				sum += z80_read8(PCM_FC2E);
				bytes_left--;
			} while ((uint8_t)((bytes_left >> 8) | bytes_left) != 0u);
			z80_block(90);
			z80_write16(PCM_FC0A, 0u);
			z80_write16(PCM_FC0C, 0u);
			z80_write8(PCM_FC0E, 2u);
			bytes_left = 0u;
			do
			{
				z80_block(59);
				sum += z80_read8(PCM_FC2E);
				bytes_left--;
			} while ((uint8_t)((bytes_left >> 8) | bytes_left) != 0u);
			z80_block(90);
			z80_write16(PCM_FC0A, 0u);
			z80_write16(PCM_FC0C, 0u);
			z80_write8(PCM_FC0E, 3u);
			bytes_left = 0u;
			do
			{
				z80_block(59);
				sum += z80_read8(PCM_FC2E);
				bytes_left--;
			} while ((uint8_t)((bytes_left >> 8) | bytes_left) != 0u);
			z80_block(90);
			z80_write16(PCM_FC0A, 0u);
			z80_write16(PCM_FC0C, 0u);
			z80_write8(PCM_FC0E, 4u);
			bytes_left = 0u;
			do
			{
				z80_block(59);
				sum += z80_read8(PCM_FC2E);
				bytes_left--;
			} while ((uint8_t)((bytes_left >> 8) | bytes_left) != 0u);
			z80_block(90);
			z80_write16(PCM_FC0A, 0u);
			z80_write16(PCM_FC0C, 0u);
			z80_write8(PCM_FC0E, 5u);
			bytes_left = 0u;
			do
			{
				z80_block(59);
				sum += z80_read8(PCM_FC2E);
				bytes_left--;
			} while ((uint8_t)((bytes_left >> 8) | bytes_left) != 0u);
			z80_block(90);
			z80_write16(PCM_FC0A, 0u);
			z80_write16(PCM_FC0C, 0u);
			z80_write8(PCM_FC0E, 6u);
			bytes_left = 0u;
			do
			{
				z80_block(59);
				sum += z80_read8(PCM_FC2E);
				bytes_left--;
			} while ((uint8_t)((bytes_left >> 8) | bytes_left) != 0u);
			z80_block(90);
			z80_write16(PCM_FC0A, 0u);
			z80_write16(PCM_FC0C, 0u);
			z80_write8(PCM_FC0E, 7u);
			bytes_left = 0u;
			do
			{
				z80_block(59);
				sum += z80_read8(PCM_FC2E);
				bytes_left--;
			} while ((uint8_t)((bytes_left >> 8) | bytes_left) != 0u);
			z80_block(90);
			z80_write16(PCM_FC0A, 0u);
			z80_write16(PCM_FC0C, 0u);
			z80_write8(PCM_FC0E, 8u);
			bytes_left = 0u;
			do
			{
				z80_block(59);
				sum += z80_read8(PCM_FC2E);
				bytes_left--;
			} while ((uint8_t)((bytes_left >> 8) | bytes_left) != 0u);
			z80_block(90);
			z80_write16(PCM_FC0A, 0u);
			z80_write16(PCM_FC0C, 0u);
			z80_write8(PCM_FC0E, 9u);
			bytes_left = 0u;
			do
			{
				z80_block(59);
				sum += z80_read8(PCM_FC2E);
				bytes_left--;
			} while ((uint8_t)((bytes_left >> 8) | bytes_left) != 0u);
			z80_block(90);
			z80_write16(PCM_FC0A, 0u);
			z80_write16(PCM_FC0C, 0u);
			z80_write8(PCM_FC0E, 0xAu);
			bytes_left = 0u;
			do
			{
				z80_block(59);
				sum += z80_read8(PCM_FC2E);
				bytes_left--;
			} while ((uint8_t)((bytes_left >> 8) | bytes_left) != 0u);
			z80_block(90);
			z80_write16(PCM_FC0A, 0u);
			z80_write16(PCM_FC0C, 0u);
			z80_write8(PCM_FC0E, 0xBu);
			bytes_left = 0u;
			do
			{
				z80_block(59);
				sum += z80_read8(PCM_FC2E);
				bytes_left--;
			} while ((uint8_t)((bytes_left >> 8) | bytes_left) != 0u);
			z80_block(90);
			z80_write16(PCM_FC0A, 0u);
			z80_write16(PCM_FC0C, 0u);
			z80_write8(PCM_FC0E, 0xCu);
			bytes_left = 0u;
			do
			{
				z80_block(59);
				sum += z80_read8(PCM_FC2E);
				bytes_left--;
			} while ((uint8_t)((bytes_left >> 8) | bytes_left) != 0u);
			z80_block(90);
			z80_write16(PCM_FC0A, 0u);
			z80_write16(PCM_FC0C, 0u);
			z80_write8(PCM_FC0E, 0xDu);
			bytes_left = 0u;
			do
			{
				z80_block(59);
				sum += z80_read8(PCM_FC2E);
				bytes_left--;
			} while ((uint8_t)((bytes_left >> 8) | bytes_left) != 0u);
			z80_block(90);
			z80_write16(PCM_FC0A, 0u);
			z80_write16(PCM_FC0C, 0u);
			z80_write8(PCM_FC0E, 0xEu);
			bytes_left = 0u;
			do
			{
				z80_block(59);
				sum += z80_read8(PCM_FC2E);
				bytes_left--;
			} while ((uint8_t)((bytes_left >> 8) | bytes_left) != 0u);
			z80_block(90);
			z80_write16(PCM_FC0A, 0u);
			z80_write16(PCM_FC0C, 0u);
			z80_write8(PCM_FC0E, 0xFu);
			bytes_left = 0u;
			do
			{
				z80_block(59);
				sum += z80_read8(PCM_FC2E);
				bytes_left--;
			} while ((uint8_t)((bytes_left >> 8) | bytes_left) != 0u);
			z80_block(71);
			t13 = sum;
			sample_rom_1_sum = (uint8_t)sum;
			t14 = sample_rom_2_sum;
			sum = t13;
			t15 = sum;
			sample_rom_1_sum = sample_rom_1_sum | ((uint32_t)(sum >> 8) << 8);
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
			sum = 0u;
			z80_write16(PCM_FC0A, 0u);
			z80_write16(PCM_FC0C, 0u);
			z80_write8(PCM_FC0E, 0x10u);
			bytes_left = 0u;
			do
			{
				z80_block(59);
				sum += z80_read8(PCM_FC2E);
				bytes_left--;
			} while ((uint8_t)((bytes_left >> 8) | bytes_left) != 0u);
			z80_block(90);
			z80_write16(PCM_FC0A, 0u);
			z80_write16(PCM_FC0C, 0u);
			z80_write8(PCM_FC0E, 0x11u);
			bytes_left = 0u;
			do
			{
				z80_block(59);
				sum += z80_read8(PCM_FC2E);
				bytes_left--;
			} while ((uint8_t)((bytes_left >> 8) | bytes_left) != 0u);
			z80_block(90);
			z80_write16(PCM_FC0A, 0u);
			z80_write16(PCM_FC0C, 0u);
			z80_write8(PCM_FC0E, 0x12u);
			bytes_left = 0u;
			do
			{
				z80_block(59);
				sum += z80_read8(PCM_FC2E);
				bytes_left--;
			} while ((uint8_t)((bytes_left >> 8) | bytes_left) != 0u);
			z80_block(90);
			z80_write16(PCM_FC0A, 0u);
			z80_write16(PCM_FC0C, 0u);
			z80_write8(PCM_FC0E, 0x13u);
			bytes_left = 0u;
			do
			{
				z80_block(59);
				sum += z80_read8(PCM_FC2E);
				bytes_left--;
			} while ((uint8_t)((bytes_left >> 8) | bytes_left) != 0u);
			z80_block(71);
			t17 = (uint8_t)sum;
			t18 = sum;
			t19 = t17 | ((uint32_t)(sum >> 8) << 8);
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
			failures = self_test_failures;
			self_test_failures = failures;
			if ((failures & 1u) != 0u)
			{
				self_test_failed();
				return;
			}
			z80_block(10);
			return;
		}
		z80_block(17);
		if (command == 0xFFu)
		{
			sound_reset();
			return;
		}
		z80_block(30);
		t20 = command;
		failures = self_test_failures;
		failure_bits = failures;
		t21 = failures;
		failures = t20;
		self_test_failures = t21;
		if ((failure_bits & 1u) != 0u)
		{
			self_test_failed();
			return;
		}
		z80_block(17);
		if (failures == 0xF8u)
		{
			z80_block(31);
			command_f8_count++;
			return;
		}
		z80_block(17);
		if (failures == 0xFDu)
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
	t22 = command;
	failures = self_test_failures;
	failure_bits = failures;
	t23 = failures;
	sound_2 = t22;
	self_test_failures = t23;
	if ((failure_bits & 1u) != 0u)
	{
		self_test_failed();
		return;
	}
	z80_block(17);
	if (sound_2 == 0x3Fu)
	{
		z80_block(16);
		sound_2 = (uint8_t)(sound >> 8);
		if (sound_2 >= 0x3Cu)
		{
			z80_cycles(6);
			return;
		}
		z80_block(35);
		channel = PCM_0;
		stride = 0x50u;
		sound = (sound >> 8) | 0x400u;
		for (;;)
		{
			z80_block(29);
			if (sound_2 == CHANNEL(channel)->sound)
			{
				z80_block(63);
				priority = effect_priorities_2[(uint8_t)sound];
				if (priority < CHANNEL(channel)->priority)
				{
					z80_cycles(6);
					return;
				}
				z80_block(149);
				CHANNEL(channel)->sound = (uint8_t)sound;
				CHANNEL(channel)->priority = priority;
				sound = (uint8_t)((uint32_t)sound << 1);
				handler = effect_handlers_2[sound / 2u];
				CHANNEL(channel)->handler = handler;
				key_off(channel);
				z80_block(14);
				volume = 0u;
				set_volume(channel, volume);
				return;
			}
			z80_block(23);
			channel += stride;
			sound = (sound & 0xFFu) | ((uint32_t)(uint8_t)((sound >> 8) - 1u) << 8);
			if (sound >> 8 == 0u)
				break;
			z80_cycles(5);
		}
		z80_block(38);
		channel = PCM_0;
		stride = 0x50u;
		priority = 0xFFu;
		sound = (sound & 0xFFu) | 0x400u;
		for (;;)
		{
			z80_block(29);
			if (CHANNEL(channel)->priority <= priority)
			{
				z80_block(44);
				priority = CHANNEL(channel)->priority;
				stack = channel;
				sum = stack;
			}
			z80_block(23);
			channel += stride;
			sound = (sound & 0xFFu) | ((uint32_t)(uint8_t)((sound >> 8) - 1u) << 8);
			if (sound >> 8 == 0u)
				break;
			z80_cycles(5);
		}
		z80_block(25);
		stack = sum;
		channel = stack;
		z80_block(63);
		priority = effect_priorities_2[(uint8_t)sound];
		if (priority < CHANNEL(channel)->priority)
		{
			z80_cycles(6);
			return;
		}
		z80_block(149);
		CHANNEL(channel)->sound = (uint8_t)sound;
		CHANNEL(channel)->priority = priority;
		sound = (uint8_t)((uint32_t)sound << 1);
		handler = effect_handlers_2[sound / 2u];
		CHANNEL(channel)->handler = handler;
		key_off(channel);
		z80_block(14);
		volume = 0u;
		set_volume(channel, volume);
		return;
	}
	z80_block(17);
	if (sound_2 == 0x7Fu)
	{
		z80_block(31);
		channel = PCM_0;
		stride = 0x50u;
		count = (sound & 0xFFu) | 0x400u;
		for (;;)
		{
			z80_block(29);
			if (sound_2 == CHANNEL(channel)->sound)
			{
				z80_block(42);
				CHANNEL(channel)->count = z80_read8(0xFC01u);
				return;
			}
			z80_block(23);
			channel += stride;
			count = (count & 0xFFu) | ((uint32_t)(uint8_t)((count >> 8) - 1u) << 8);
			if (count >> 8 == 0u)
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
		channel = PCM_0;
		stride = 0x50u;
		priority = 0xFFu;
		sound = (count & 0xFFu) | 0x400u;
		for (;;)
		{
			z80_block(29);
			if (CHANNEL(channel)->priority <= priority)
			{
				z80_block(44);
				priority = CHANNEL(channel)->priority;
				stack = channel;
				sum = stack;
			}
			z80_block(23);
			channel += stride;
			sound = (sound & 0xFFu) | ((uint32_t)(uint8_t)((sound >> 8) - 1u) << 8);
			if (sound >> 8 == 0u)
				break;
			z80_cycles(5);
		}
		z80_block(88);
		stack = sum;
		channel = stack;
		priority = effect_priorities_40_by_sound[(uint8_t)sound];
		if (priority < CHANNEL(channel)->priority)
		{
			z80_cycles(6);
			return;
		}
		z80_block(149);
		CHANNEL(channel)->sound = (uint8_t)sound;
		CHANNEL(channel)->priority = priority;
		sound = (uint8_t)((uint32_t)sound << 1);
		handler = effect_handlers_40_by_sound[sound / 2u];
		CHANNEL(channel)->handler = handler;
		key_off(channel);
		z80_block(21);
		volume = 0u;
		set_volume(channel, volume);
		z80_block(42);
		CHANNEL(channel)->count = z80_read8(0xFC01u);
		return;
	}
	z80_block(4);
	sound = (uint32_t)(uint8_t)((sound >> 8) + 1u) << 8;
	for (;;)
	{
		z80_block(39);
		saved_sound_2 = sound_2;
		saved_sound = sound;
		start_sound(sound_2);
		z80_block(32);
		sound_2 = saved_sound_2 + 1u;
		sound = (uint32_t)(uint8_t)((saved_sound >> 8) - 1u) << 8;
		if (sound >> 8 == 0u)
			break;
		z80_cycles(5);
	}
	z80_block(10);
}

/* The NMI (the K053260's, armed by a write to the NMI's port): returns at once; it only ends
   pcm_key_on's wait. */
void nmi_return(void)
{
	z80_block(14);
}

/* A command 00 to EF. 00: stop_all_channels. 01-38: an FM effect, on the YM2151 record already playing
   it, else on the one of the lowest priority if the effect's (effect_priorities) is not below it: its
   sound and priority, its handler from effect_handlers, the loudest volume, no LFO, keyed off, released
   at the fastest, no noise. 3C-3F: the unused group on FM_7 (no such command is sent). 40-7E: a PCM
   effect the same way on the K053260's records (effect_priorities_40, effect_handlers_40). 80-AF:
   start_song. C0-EF: the song 40 below, at once when no record plays music, else once the music has
   faded out (fade, fade_next_song). */
void start_sound(uint8_t sound)
{
	uint32_t zero = 0;
	uint8_t count = 0, next_song = 0, priority = 0, sensitivity = 0, song = 0, sound_2 = 0, volume = 0;
	uint16_t channel = 0, handler = 0, lowest = 0, stride = 0;
	uint16_t stack = 0;

	z80_block(17);
	if (sound >= 0xC0u)
	{
		z80_block(42);
		next_song = sound - 0x40u;
		channel = FM_0;
		zero = music_channel_song(channel);
		z80_block(10);
		if (zero)
		{
			z80_block(31);
			channel = FM_1;
			zero = music_channel_song(channel);
			z80_block(10);
			if (zero)
			{
				z80_block(31);
				channel = FM_2;
				zero = music_channel_song(channel);
				z80_block(10);
				if (zero)
				{
					z80_block(31);
					channel = FM_3;
					zero = music_channel_song(channel);
					z80_block(10);
					if (zero)
					{
						z80_block(31);
						channel = FM_4;
						zero = music_channel_song(channel);
						z80_block(10);
						if (zero)
						{
							z80_block(31);
							channel = FM_5;
							zero = music_channel_song(channel);
							z80_block(10);
							if (zero)
							{
								z80_block(31);
								channel = FM_6;
								zero = music_channel_song(channel);
								z80_block(10);
								if (zero)
								{
									z80_block(31);
									channel = FM_7;
									zero = music_channel_song(channel);
									z80_block(10);
									if (zero)
									{
										z80_block(31);
										channel = PCM_0;
										zero = music_channel_song(channel);
										z80_block(10);
										if (zero)
										{
											z80_block(31);
											channel = PCM_1;
											zero = music_channel_song(channel);
											z80_block(10);
											if (zero)
											{
												z80_block(31);
												channel = PCM_2;
												zero = music_channel_song(channel);
												z80_block(10);
												if (zero)
												{
													z80_block(31);
													channel = PCM_3;
													zero = music_channel_song(channel);
													z80_block(10);
													if (zero)
													{
														z80_block(14);
														song = next_song;
														start_song(song);
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
		fade_next_song = next_song;
		fade = 1u;
		fade_period = 8u;
		fade_timer = 8u;
		return;
	}
	z80_block(17);
	if (sound >= 0x80u)
	{
		start_song(sound);
		return;
	}
	z80_block(17);
	if (sound >= 0x40u)
	{
		z80_block(12);
		if (sound >= 0x80u)
		{
			z80_cycles(6);
			return;
		}
		z80_block(35);
		sound_2 = sound;
		channel = PCM_0;
		stride = 0x50u;
		count = 4u;
		for (;;)
		{
			z80_block(29);
			if (sound == CHANNEL(channel)->sound)
			{
				z80_block(111);
				sound_2 = (uint32_t)sound_2 << 1;
				handler = effect_handlers_40_by_sound[sound_2 / 2u];
				CHANNEL(channel)->handler = handler;
				key_off(channel);
				z80_block(14);
				volume = 0u;
				set_volume(channel, volume);
				return;
			}
			z80_block(23);
			channel += stride;
			count--;
			if (count == 0u)
				break;
			z80_cycles(5);
		}
		z80_block(38);
		channel = PCM_0;
		stride = 0x50u;
		priority = 0xFFu;
		count = 4u;
		for (;;)
		{
			z80_block(29);
			if (CHANNEL(channel)->priority <= priority)
			{
				z80_block(44);
				priority = CHANNEL(channel)->priority;
				stack = channel;
				lowest = stack;
			}
			z80_block(23);
			channel += stride;
			count--;
			if (count == 0u)
				break;
			z80_cycles(5);
		}
		z80_block(88);
		stack = lowest;
		channel = stack;
		priority = effect_priorities_40_by_sound[sound_2];
		if (priority < CHANNEL(channel)->priority)
		{
			z80_cycles(6);
			return;
		}
		z80_block(38);
		CHANNEL(channel)->sound = sound_2;
		CHANNEL(channel)->priority = priority;
		z80_block(111);
		sound_2 = (uint32_t)sound_2 << 1;
		handler = effect_handlers_40_by_sound[sound_2 / 2u];
		CHANNEL(channel)->handler = handler;
		key_off(channel);
		z80_block(14);
		volume = 0u;
		set_volume(channel, volume);
		return;
	}
	z80_block(17);
	if (sound >= 0x3Cu)
	{
		z80_block(12);
		if (sound >= 0x40u)
		{
			z80_cycles(6);
			return;
		}
		z80_block(89);
		sound_2 = sound;
		channel = FM_7;
		priority = (uint32_t)unused_effect_priorities_by_sound[sound_2] << 1;
		if (priority < CHANNEL(FM_7)->priority)
		{
			z80_cycles(6);
			return;
		}
		z80_block(172);
		CHANNEL(channel)->sound = sound_2;
		CHANNEL(channel)->priority = priority;
		sound_2 = (uint32_t)sound_2 << 1;
		handler = unused_effect_handlers_by_sound[sound_2 / 2u];
		CHANNEL(channel)->handler = handler;
		CHANNEL(channel)->volume = 0u;
		sensitivity = 0u;
		set_channel_am_sensitivity(channel, sensitivity);
		z80_block(21);
		sensitivity = 0u;
		set_channel_pm_sensitivity(channel, sensitivity);
		z80_block(17);
		key_off(channel);
		z80_block(17);
		fast_release(channel);
		z80_block(14);
		volume = 0u;
		set_volume(channel, volume);
		return;
	}
	z80_block(17);
	if (sound == 0u)
	{
		stop_all_channels();
		return;
	}
	z80_block(12);
	if (sound >= 0x39u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(35);
	sound_2 = sound;
	channel = FM_0;
	stride = 0x50u;
	count = 8u;
	for (;;)
	{
		z80_block(29);
		if (sound == CHANNEL(channel)->sound)
			break;
		z80_block(23);
		channel += stride;
		count--;
		if (count != 0u)
		{
			z80_cycles(5);
			continue;
		}
		z80_block(38);
		channel = FM_0;
		stride = 0x50u;
		priority = 0xFFu;
		count = 8u;
		for (;;)
		{
			z80_block(29);
			if (CHANNEL(channel)->priority <= priority)
			{
				z80_block(44);
				priority = CHANNEL(channel)->priority;
				stack = channel;
				lowest = stack;
			}
			z80_block(23);
			channel += stride;
			count--;
			if (count == 0u)
				break;
			z80_cycles(5);
		}
		z80_block(88);
		stack = lowest;
		channel = stack;
		priority = effect_priorities[(uint16_t)(sound_2 - 1u)];
		if (priority < CHANNEL(channel)->priority)
		{
			z80_cycles(6);
			return;
		}
		z80_block(38);
		CHANNEL(channel)->sound = sound_2;
		CHANNEL(channel)->priority = priority;
		break;
	}
	z80_block(134);
	sound_2 = (uint32_t)sound_2 << 1;
	handler = TABLE16(effect_handlers, (uint16_t)(sound_2 - 2u));
	CHANNEL(channel)->handler = handler;
	CHANNEL(channel)->volume = 0u;
	sensitivity = 0u;
	set_channel_am_sensitivity(channel, sensitivity);
	z80_block(21);
	sensitivity = 0u;
	set_channel_pm_sensitivity(channel, sensitivity);
	z80_block(17);
	key_off(channel);
	z80_block(17);
	fast_release(channel);
	z80_block(17);
	noise_off(channel);
	z80_block(14);
	volume = 0u;
	set_volume(channel, volume);
}

/* Command 00: stops every record but those of priority C0 or more (stop_channel_unless_kept), then the
   music (stop_music). */
uint16_t stop_all_channels(void)
{
	uint8_t ignored8 = 0;
	uint16_t channel = 0, last_channel = 0;

	z80_block(31);
	channel = FM_0;
	stop_channel_unless_kept(channel);
	z80_block(31);
	channel = FM_1;
	stop_channel_unless_kept(channel);
	z80_block(31);
	channel = FM_2;
	stop_channel_unless_kept(channel);
	z80_block(31);
	channel = FM_3;
	stop_channel_unless_kept(channel);
	z80_block(31);
	channel = FM_4;
	stop_channel_unless_kept(channel);
	z80_block(31);
	channel = FM_5;
	stop_channel_unless_kept(channel);
	z80_block(31);
	channel = FM_6;
	stop_channel_unless_kept(channel);
	z80_block(31);
	channel = FM_7;
	stop_channel_unless_kept(channel);
	z80_block(31);
	channel = PCM_0;
	stop_channel_unless_kept(channel);
	z80_block(31);
	channel = PCM_1;
	stop_channel_unless_kept(channel);
	z80_block(31);
	channel = PCM_2;
	stop_channel_unless_kept(channel);
	z80_block(31);
	channel = PCM_3;
	stop_channel_unless_kept(channel);
	stop_music(&last_channel, &ignored8);
	return last_channel;
}

/* The music off on all 12 records (stop_music_channel) and the fade cleared: at the fade's end, and
   after command 00. */
void stop_music(uint16_t *p_last_channel, uint8_t *p_cleared)
{
	uint8_t cleared = 0;
	uint16_t channel = 0, last_channel = 0;

	z80_block(31);
	channel = FM_0;
	stop_music_channel(channel);
	z80_block(31);
	channel = FM_1;
	stop_music_channel(channel);
	z80_block(31);
	channel = FM_2;
	stop_music_channel(channel);
	z80_block(31);
	channel = FM_3;
	stop_music_channel(channel);
	z80_block(31);
	channel = FM_4;
	stop_music_channel(channel);
	z80_block(31);
	channel = FM_5;
	stop_music_channel(channel);
	z80_block(31);
	channel = FM_6;
	stop_music_channel(channel);
	z80_block(31);
	channel = FM_7;
	stop_music_channel(channel);
	z80_block(31);
	channel = PCM_0;
	stop_music_channel(channel);
	z80_block(31);
	channel = PCM_1;
	stop_music_channel(channel);
	z80_block(31);
	channel = PCM_2;
	stop_music_channel(channel);
	z80_block(31);
	last_channel = PCM_3;
	stop_music_channel(last_channel);
	z80_block(79);
	cleared = 0u;
	fade = 0u;
	fade_attenuation = 0u;
	fade_timer = 0u;
	fade_next_song = 0u;
	fade_hold = 0u;
	*p_last_channel = last_channel;
	*p_cleared = cleared;
}

/* stop_channel, unless the record's priority is C0 or more (PCM effects 40 to 42). */
void stop_channel_unless_kept(uint16_t channel)
{
	z80_block(31);
	if (CHANNEL(channel)->priority >= 0xC0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(channel);
}

/* A song, commands 80-AF: its bank (song_banks_by_sound) into the bank register, each record's track
   from the song's header (start_music_channel, FM_0 to PCM_3), the fade cleared. */
void start_song(uint8_t song)
{
	uint8_t command = 0;
	uint16_t channel = 0, header_entry = 0;
	uint8_t saved_song = 0;

	z80_block(12);
	if (song >= 0xB0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(171);
	saved_song = song;
	z80_write8(SOUND_BANK_FE00, song_banks_by_sound[song]);
	command = saved_song;
	header_entry = command * 2u + song_headers_by_sound_ADDRESS;
	header_entry = SONG_HEADER_ADDRESS(header_entry)[0];
	channel = FM_0;
	header_entry = start_music_channel(header_entry, channel, command);
	z80_block(31);
	channel = FM_1;
	header_entry = start_music_channel(header_entry, channel, command);
	z80_block(31);
	channel = FM_2;
	header_entry = start_music_channel(header_entry, channel, command);
	z80_block(31);
	channel = FM_3;
	header_entry = start_music_channel(header_entry, channel, command);
	z80_block(31);
	channel = FM_4;
	header_entry = start_music_channel(header_entry, channel, command);
	z80_block(31);
	channel = FM_5;
	header_entry = start_music_channel(header_entry, channel, command);
	z80_block(31);
	channel = FM_6;
	header_entry = start_music_channel(header_entry, channel, command);
	z80_block(31);
	channel = FM_7;
	header_entry = start_music_channel(header_entry, channel, command);
	z80_block(31);
	channel = PCM_0;
	header_entry = start_music_channel(header_entry, channel, command);
	z80_block(31);
	channel = PCM_1;
	header_entry = start_music_channel(header_entry, channel, command);
	z80_block(31);
	channel = PCM_2;
	header_entry = start_music_channel(header_entry, channel, command);
	z80_block(31);
	channel = PCM_3;
	start_music_channel(header_entry, channel, command);
	z80_block(79);
	fade = 0u;
	fade_attenuation = 0u;
	fade_timer = 0u;
	fade_next_song = 0u;
	fade_hold = 0u;
}

/* The record's track from the song header's next word (start_music_track); hands back the place of the
   word after it. */
uint16_t start_music_channel(uint16_t header_entry, uint16_t channel, uint8_t song)
{
	uint8_t track_high = 0, track_low = 0;
	uint16_t track = 0;

	z80_block(54);
	track_low = z80_read8(header_entry);
	header_entry++;
	track_high = z80_read8(header_entry);
	header_entry++;
	track = ((uint32_t)track_high << 8) | track_low;
	start_music_track(track, channel, song);
	z80_block(20);
	return header_entry;
}

/* The ROM test: adds up the program's 32 KB and the banks 2 to 7 into program_rom_sum; a sum other than
   072E sets bit 1 of self_test_failures; then sound_main. The game's sound board puts its own in its
   place (the game has no ROM to add up: it takes the time good chips take). */
uint16_t BOARD_ORIGINAL(check_rom)(void)
{
	uint16_t address = 0, sum = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	z80_block(20);
	sum = 0u;
	address = 0u;
	do
	{
		z80_block(56);
		sum += z80_read8(address);
		address++;
	} while (address >> 8 != 0x80u);
	z80_block(30);
	z80_write8(SOUND_BANK_FE00, 2u);
	address = 0x8000u;
	do
	{
		z80_block(56);
		sum += z80_read8(address);
		address++;
	} while (address >> 8 != 0xC0u);
	z80_block(30);
	z80_write8(SOUND_BANK_FE00, 3u);
	address = 0x8000u;
	do
	{
		z80_block(56);
		sum += z80_read8(address);
		address++;
	} while (address >> 8 != 0xC0u);
	z80_block(30);
	z80_write8(SOUND_BANK_FE00, 4u);
	address = 0x8000u;
	do
	{
		z80_block(56);
		sum += z80_read8(address);
		address++;
	} while (address >> 8 != 0xC0u);
	z80_block(30);
	z80_write8(SOUND_BANK_FE00, 5u);
	address = 0x8000u;
	do
	{
		z80_block(56);
		sum += z80_read8(address);
		address++;
	} while (address >> 8 != 0xC0u);
	z80_block(30);
	z80_write8(SOUND_BANK_FE00, 6u);
	address = 0x8000u;
	do
	{
		z80_block(56);
		sum += z80_read8(address);
		address++;
	} while (address >> 8 != 0xC0u);
	z80_block(30);
	z80_write8(SOUND_BANK_FE00, 7u);
	address = 0x8000u;
	do
	{
		z80_block(56);
		sum += z80_read8(address);
		address++;
	} while (address >> 8 != 0xC0u);
	z80_block(71);
	t1 = sum;
	program_rom_sum = (uint8_t)sum;
	t2 = sample_rom_2_sum;
	sum = t1;
	t3 = sum;
	program_rom_sum = program_rom_sum | ((uint32_t)(sum >> 8) << 8);
	t4 = t2;
	sample_rom_2_sum = t4;
	if (t3 == 0x72Eu)
		return sound_main();
	z80_block(16);
	self_test_failures = self_test_failures | 2u;
	return sound_main();
}

/* Clears the RAM, sets the K053260 up (its voices' registers cleared, every key off), gives each record
   its chip_channel and the K053260's records their voice's registers and bits; then, unless the RAM test
   failed, stops every channel and starts the YM2151's timer B: the main loop follows. */
uint16_t sound_main(void)
{
	uint8_t channel = 0, failures = 0;
	uint16_t last_channel = 0;

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
	CHANNEL(FM_0)->chip_channel = 0u;
	CHANNEL(FM_1)->chip_channel = 1u;
	CHANNEL(FM_2)->chip_channel = 2u;
	CHANNEL(FM_3)->chip_channel = 3u;
	CHANNEL(FM_4)->chip_channel = 4u;
	CHANNEL(FM_5)->chip_channel = 5u;
	CHANNEL(FM_6)->chip_channel = 6u;
	CHANNEL(FM_7)->chip_channel = 7u;
	CHANNEL(PCM_0)->chip_channel = 8u;
	CHANNEL(PCM_0)->pcm.registers = PCM_FC08;
	CHANNEL(PCM_0)->pcm.key_mask = 0xFEu;
	CHANNEL(PCM_0)->pcm.key_bit = 1u;
	CHANNEL(PCM_0)->pcm.kadpcm_mask = 0xEFu;
	CHANNEL(PCM_0)->pcm.kadpcm_bit = 0x10u;
	CHANNEL(PCM_1)->chip_channel = 9u;
	CHANNEL(PCM_1)->pcm.registers = PCM_FC10;
	CHANNEL(PCM_1)->pcm.key_mask = 0xFDu;
	CHANNEL(PCM_1)->pcm.key_bit = 2u;
	CHANNEL(PCM_1)->pcm.kadpcm_mask = 0xDFu;
	CHANNEL(PCM_1)->pcm.kadpcm_bit = 0x20u;
	CHANNEL(PCM_2)->chip_channel = 0xAu;
	CHANNEL(PCM_2)->pcm.registers = PCM_FC18;
	CHANNEL(PCM_2)->pcm.key_mask = 0xFBu;
	CHANNEL(PCM_2)->pcm.key_bit = 4u;
	CHANNEL(PCM_2)->pcm.kadpcm_mask = 0xBFu;
	CHANNEL(PCM_2)->pcm.kadpcm_bit = 0x40u;
	CHANNEL(PCM_3)->chip_channel = 0xBu;
	CHANNEL(PCM_3)->pcm.registers = PCM_FC20;
	CHANNEL(PCM_3)->pcm.key_mask = 0xF7u;
	CHANNEL(PCM_3)->pcm.key_bit = 8u;
	CHANNEL(PCM_3)->pcm.kadpcm_mask = 0x7Fu;
	CHANNEL(PCM_3)->pcm.kadpcm_bit = 0x80u;
	byte_pointer = 0x100u;
	failures = self_test_failures;
	self_test_failures = failures;
	if ((failures & 1u) != 0u)
	{
		self_test_failed();
		return channel;
	}
	z80_block(17);
	last_channel = stop_all_channels();
	z80_block(17);
	restart_frame_timer();
	z80_block(10);
	return last_channel;
}

/* The RAM test failed: forever a delay and a window with interrupts on, where the 053248's commands come
   in (and end here again). */
void self_test_failed(void)
{
	uint16_t delay = 0;

	for (;;)
	{
		z80_block(20);
		delay = FAILED_DELAY;
		do
		{
			z80_block(24);
			delay--;
		} while ((uint8_t)((delay >> 8) | delay) != 0u);
		z80_block(8);
		interrupts_on();
		z80_block(26);
		interrupts_off();
	}
}

/* A pass of the main loop: waits for the YM2151's timer B and starts it again; runs the 8 YM2151 records
   (run_channel) and the 4 K053260 ones (run_pcm_channel); the fade between songs (every fade_period
   passes fade_attenuation one more: at 30 fade_next_song starts, at 7F the music stops; a fade other
   than 1 only counts fade_hold down); then a window of four instructions with interrupts on, where the
   053248's command comes in, sound_command again if command_held says so (nothing sets it), and
   pass_count. */
void sound_main_loop(void)
{
	uint8_t attenuation = 0, fade_kind = 0, next_song = 0;
	uint16_t channel = 0, ignored16 = 0, timer_address = 0;
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
	channel = FM_0;
	run_channel(channel);
	z80_block(31);
	channel = FM_1;
	run_channel(channel);
	z80_block(31);
	channel = FM_2;
	run_channel(channel);
	z80_block(31);
	channel = FM_3;
	run_channel(channel);
	z80_block(31);
	channel = FM_4;
	run_channel(channel);
	z80_block(31);
	channel = FM_5;
	run_channel(channel);
	z80_block(31);
	channel = FM_6;
	run_channel(channel);
	z80_block(31);
	channel = FM_7;
	run_channel(channel);
	z80_block(31);
	channel = PCM_0;
	run_pcm_channel(channel);
	z80_block(31);
	channel = PCM_1;
	run_pcm_channel(channel);
	z80_block(31);
	channel = PCM_2;
	run_pcm_channel(channel);
	z80_block(31);
	channel = PCM_3;
	run_pcm_channel(channel);
	z80_block(27);
	fade_kind = fade;
	if (fade_kind == 0u)
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
	if (fade_kind == 1u)
	{
		z80_block(31);
		timer_address = fade_timer_ADDRESS;
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
		attenuation = fade_attenuation + 1u;
		fade_attenuation = attenuation;
		if (attenuation == 0x7Fu)
		{
			z80_cycles(7);
			stop_music(&ignored16, &attenuation);
		}
		z80_block(17);
		if (attenuation != 0x30u)
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
		next_song = fade_next_song;
		if (next_song != 0u)
		{
			z80_cycles(7);
			start_song(next_song);
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

/* A K053260 record's pass: on one pass in 16 (its own, by its chip_channel), while its voice is not
   keyed, the decay one decay_step quieter (up to 7F) and update_volume; then run_channel. */
void run_pcm_channel(uint16_t channel)
{
	uint8_t decay = 0;
	uint8_t t1 = 0;

	z80_block(49);
	if ((pass_count & 0xFu) == CHANNEL(channel)->chip_channel)
	{
		z80_block(42);
		if ((pcm_keyed & CHANNEL(channel)->pcm.key_bit) == 0u)
		{
			z80_block(48);
			t1 = CHANNEL(channel)->pcm.decay + CHANNEL(channel)->pcm.decay_step;
			decay = t1;
			if ((int8_t)t1 < 0)
			{
				z80_block(7);
				decay = 0x7Fu;
			}
			z80_block(36);
			CHANNEL(channel)->pcm.decay = decay;
			update_volume(channel);
		}
	}
	run_channel(channel);
}

/* A record's pass: its music (music_tick), then its handler. */
void run_channel(uint16_t channel)
{
	uint32_t jump_target = 0;

	z80_block(17);
	channel = music_tick(channel);
	z80_block(42);
	jump_target = CHANNEL(channel)->handler;
	switch (jump_target)
	{
	case channel_idle_ADDRESS:
		channel_idle();
		return;
	case fm_effect_02_ADDRESS:
		fm_effect_02(channel);
		return;
	case fm_effect_02_delay_ADDRESS:
		fm_effect_02_delay(channel);
		return;
	case fm_effect_01_ADDRESS:
		fm_effect_01(channel);
		return;
	case fm_effect_01_retrigger_ADDRESS:
		fm_effect_01_retrigger(channel);
		return;
	case fm_effect_01_pitch_ADDRESS:
		fm_effect_01_pitch(channel);
		return;
	case fm_effect_04_ADDRESS:
		fm_effect_04(channel);
		return;
	case fm_effect_04_delay_ADDRESS:
		fm_effect_04_delay(channel);
		return;
	case fm_effect_03_ADDRESS:
		fm_effect_03(channel);
		return;
	case fm_effect_03_pitch_ADDRESS:
		fm_effect_03_pitch(channel);
		return;
	case fm_effect_06_ADDRESS:
		fm_effect_06(channel);
		return;
	case fm_effect_06_delay_ADDRESS:
		fm_effect_06_delay(channel);
		return;
	case fm_effect_05_ADDRESS:
		fm_effect_05(channel);
		return;
	case fm_effect_05_slide_ADDRESS:
		fm_effect_05_slide(channel);
		return;
	case fm_effect_07_ADDRESS:
		fm_effect_07(channel);
		return;
	case fm_effect_07_slide_ADDRESS:
		fm_effect_07_slide(channel);
		return;
	case fm_effect_09_ADDRESS:
		fm_effect_09(channel);
		return;
	case fm_effect_09_delay_ADDRESS:
		fm_effect_09_delay(channel);
		return;
	case fm_effect_08_ADDRESS:
		fm_effect_08(channel);
		return;
	case fm_effect_08_retrigger_ADDRESS:
		fm_effect_08_retrigger(channel);
		return;
	case fm_effect_08_hold_ADDRESS:
		fm_effect_08_hold(channel);
		return;
	case fm_effect_0d_ADDRESS:
		fm_effect_0d(channel);
		return;
	case fm_effect_0d_delay_ADDRESS:
		fm_effect_0d_delay(channel);
		return;
	case fm_effect_0c_ADDRESS:
		fm_effect_0c(channel);
		return;
	case fm_effect_0c_retrigger_ADDRESS:
		fm_effect_0c_retrigger(channel);
		return;
	case fm_effect_0c_retrigger_2_ADDRESS:
		fm_effect_0c_retrigger_2(channel);
		return;
	case fm_effect_0c_hold_ADDRESS:
		fm_effect_0c_hold(channel);
		return;
	case fm_effect_0e_ADDRESS:
		fm_effect_0e(channel);
		return;
	case fm_effect_0e_pitch_ADDRESS:
		fm_effect_0e_pitch(channel);
		return;
	case fm_effect_0e_pitch_2_ADDRESS:
		fm_effect_0e_pitch_2(channel);
		return;
	case fm_effect_0e_pitch_3_ADDRESS:
		fm_effect_0e_pitch_3(channel);
		return;
	case fm_effect_0f_ADDRESS:
		fm_effect_0f(channel);
		return;
	case fm_effect_0f_slide_ADDRESS:
		fm_effect_0f_slide(channel);
		return;
	case fm_effect_10_ADDRESS:
		fm_effect_10(channel);
		return;
	case fm_effect_10_slide_ADDRESS:
		fm_effect_10_slide(channel);
		return;
	case fm_effect_11_ADDRESS:
		fm_effect_11(channel);
		return;
	case fm_effect_11_pitch_ADDRESS:
		fm_effect_11_pitch(channel);
		return;
	case fm_effect_12_ADDRESS:
		fm_effect_12(channel);
		return;
	case fm_effect_12_delay_ADDRESS:
		fm_effect_12_delay(channel);
		return;
	case fm_effect_12_slide_ADDRESS:
		fm_effect_12_slide(channel);
		return;
	case fm_effect_13_ADDRESS:
		fm_effect_13(channel);
		return;
	case fm_effect_13_slide_ADDRESS:
		fm_effect_13_slide(channel);
		return;
	case fm_effect_13_hold_ADDRESS:
		fm_effect_13_hold(channel);
		return;
	case fm_effect_13_fall_ADDRESS:
		fm_effect_13_fall(channel);
		return;
	case fm_effect_14_ADDRESS:
		fm_effect_14(channel);
		return;
	case fm_effect_14_slide_ADDRESS:
		fm_effect_14_slide(channel);
		return;
	case fm_effect_14_hold_ADDRESS:
		fm_effect_14_hold(channel);
		return;
	case fm_effect_15_ADDRESS:
		fm_effect_15(channel);
		return;
	case fm_effect_15_note_ADDRESS:
		fm_effect_15_note(channel);
		return;
	case fm_effect_15_slide_ADDRESS:
		fm_effect_15_slide(channel);
		return;
	case fm_effect_17_ADDRESS:
		fm_effect_17(channel);
		return;
	case fm_effect_17_delay_ADDRESS:
		fm_effect_17_delay(channel);
		return;
	case fm_effect_16_ADDRESS:
		fm_effect_16(channel);
		return;
	case fm_effect_16_pitch_ADDRESS:
		fm_effect_16_pitch(channel);
		return;
	case fm_effect_18_ADDRESS:
		fm_effect_18(channel);
		return;
	case fm_effect_18_slide_ADDRESS:
		fm_effect_18_slide(channel);
		return;
	case fm_effect_19_ADDRESS:
		fm_effect_19(channel);
		return;
	case fm_effect_19_slide_ADDRESS:
		fm_effect_19_slide(channel);
		return;
	case fm_effect_1a_ADDRESS:
		fm_effect_1a(channel);
		return;
	case fm_effect_1a_slide_ADDRESS:
		fm_effect_1a_slide(channel);
		return;
	case fm_effect_1b_ADDRESS:
		fm_effect_1b(channel);
		return;
	case fm_effect_1b_pitch_ADDRESS:
		fm_effect_1b_pitch(channel);
		return;
	case fm_effect_1b_pitch_2_ADDRESS:
		fm_effect_1b_pitch_2(channel);
		return;
	case fm_effect_1c_ADDRESS:
		fm_effect_1c(channel);
		return;
	case fm_effect_1c_pitch_ADDRESS:
		fm_effect_1c_pitch(channel);
		return;
	case fm_effect_1c_pitch_2_ADDRESS:
		fm_effect_1c_pitch_2(channel);
		return;
	case fm_effect_1c_pitch_3_ADDRESS:
		fm_effect_1c_pitch_3(channel);
		return;
	case fm_effect_1d_ADDRESS:
		fm_effect_1d(channel);
		return;
	case fm_effect_1d_pitch_ADDRESS:
		fm_effect_1d_pitch(channel);
		return;
	case fm_effect_1d_pitch_3_ADDRESS:
		fm_effect_1d_pitch_3(channel);
		return;
	case fm_effect_1e_ADDRESS:
		fm_effect_1e(channel);
		return;
	case fm_effect_1e_slide_ADDRESS:
		fm_effect_1e_slide(channel);
		return;
	case fm_effect_1f_ADDRESS:
		fm_effect_1f(channel);
		return;
	case fm_effect_1f_retrigger_ADDRESS:
		fm_effect_1f_retrigger(channel);
		return;
	case fm_effect_1f_end_ADDRESS:
		fm_effect_1f_end(channel);
		return;
	case fm_effect_20_ADDRESS:
		fm_effect_20(channel);
		return;
	case fm_effect_20_pitch_ADDRESS:
		fm_effect_20_pitch(channel);
		return;
	case fm_effect_20_pitch_2_ADDRESS:
		fm_effect_20_pitch_2(channel);
		return;
	case fm_effect_21_ADDRESS:
		fm_effect_21(channel);
		return;
	case fm_effect_21_end_ADDRESS:
		fm_effect_21_end(channel);
		return;
	case fm_effect_22_ADDRESS:
		fm_effect_22(channel);
		return;
	case fm_effect_22_slide_ADDRESS:
		fm_effect_22_slide(channel);
		return;
	case fm_effect_23_ADDRESS:
		fm_effect_23(channel);
		return;
	case fm_effect_23_slide_ADDRESS:
		fm_effect_23_slide(channel);
		return;
	case fm_effect_24_ADDRESS:
		fm_effect_24(channel);
		return;
	case fm_effect_24_retrigger_ADDRESS:
		fm_effect_24_retrigger(channel);
		return;
	case fm_effect_24_hold_ADDRESS:
		fm_effect_24_hold(channel);
		return;
	case fm_effect_25_ADDRESS:
		fm_effect_25(channel);
		return;
	case fm_effect_25_note_ADDRESS:
		fm_effect_25_note(channel);
		return;
	case fm_effect_25_retrigger_ADDRESS:
		fm_effect_25_retrigger(channel);
		return;
	case fm_effect_25_hold_ADDRESS:
		fm_effect_25_hold(channel);
		return;
	case fm_effect_26_ADDRESS:
		fm_effect_26(channel);
		return;
	case fm_effect_26_slide_ADDRESS:
		fm_effect_26_slide(channel);
		return;
	case fm_effect_26_pitch_ADDRESS:
		fm_effect_26_pitch(channel);
		return;
	case fm_effect_27_ADDRESS:
		fm_effect_27(channel);
		return;
	case fm_effect_27_retrigger_ADDRESS:
		fm_effect_27_retrigger(channel);
		return;
	case fm_effect_27_hold_ADDRESS:
		fm_effect_27_hold(channel);
		return;
	case fm_effect_28_ADDRESS:
		fm_effect_28(channel);
		return;
	case fm_effect_28_slide_ADDRESS:
		fm_effect_28_slide(channel);
		return;
	case fm_effect_29_ADDRESS:
		fm_effect_29(channel);
		return;
	case fm_effect_29_pitch_ADDRESS:
		fm_effect_29_pitch(channel);
		return;
	case fm_effect_29_slide_ADDRESS:
		fm_effect_29_slide(channel);
		return;
	case fm_effect_2b_ADDRESS:
		fm_effect_2b(channel);
		return;
	case fm_effect_2b_delay_ADDRESS:
		fm_effect_2b_delay(channel);
		return;
	case fm_effect_2a_ADDRESS:
		fm_effect_2a(channel);
		return;
	case fm_effect_2a_retrigger_ADDRESS:
		fm_effect_2a_retrigger(channel);
		return;
	case fm_effect_2a_retrigger_2_ADDRESS:
		fm_effect_2a_retrigger_2(channel);
		return;
	case fm_effect_2a_hold_ADDRESS:
		fm_effect_2a_hold(channel);
		return;
	case fm_effect_2c_ADDRESS:
		fm_effect_2c(channel);
		return;
	case fm_effect_2c_step_up_ADDRESS:
		fm_effect_2c_step_up(channel);
		return;
	case fm_effect_2c_step_down_ADDRESS:
		fm_effect_2c_step_down(channel);
		return;
	case fm_effect_2d_ADDRESS:
		fm_effect_2d(channel);
		return;
	case fm_effect_2d_note_ADDRESS:
		fm_effect_2d_note(channel);
		return;
	case fm_effect_2d_step_up_ADDRESS:
		fm_effect_2d_step_up(channel);
		return;
	case fm_effect_2d_step_down_ADDRESS:
		fm_effect_2d_step_down(channel);
		return;
	case fm_effect_2e_ADDRESS:
		fm_effect_2e(channel);
		return;
	case fm_effect_2e_note_ADDRESS:
		fm_effect_2e_note(channel);
		return;
	case fm_effect_2e_step_up_ADDRESS:
		fm_effect_2e_step_up(channel);
		return;
	case fm_effect_2e_step_down_ADDRESS:
		fm_effect_2e_step_down(channel);
		return;
	case fm_effect_2f_ADDRESS:
		fm_effect_2f(channel);
		return;
	case fm_effect_2f_slide_ADDRESS:
		fm_effect_2f_slide(channel);
		return;
	case fm_effect_32_ADDRESS:
		fm_effect_32(channel);
		return;
	case fm_effect_32_delay_ADDRESS:
		fm_effect_32_delay(channel);
		return;
	case fm_effect_31_ADDRESS:
		fm_effect_31(channel);
		return;
	case fm_effect_31_delay_ADDRESS:
		fm_effect_31_delay(channel);
		return;
	case fm_effect_30_ADDRESS:
		fm_effect_30(channel);
		return;
	case fm_effect_30_retrigger_2_ADDRESS:
		fm_effect_30_retrigger_2(channel);
		return;
	case fm_effect_33_ADDRESS:
		fm_effect_33(channel);
		return;
	case fm_effect_33_retrigger_2_ADDRESS:
		fm_effect_33_retrigger_2(channel);
		return;
	case fm_effect_34_ADDRESS:
		fm_effect_34(channel);
		return;
	case fm_effect_34_slide_ADDRESS:
		fm_effect_34_slide(channel);
		return;
	case fm_effect_35_ADDRESS:
		fm_effect_35(channel);
		return;
	case fm_effect_35_note_ADDRESS:
		fm_effect_35_note(channel);
		return;
	case fm_effect_35_slide_ADDRESS:
		fm_effect_35_slide(channel);
		return;
	case fm_effect_36_ADDRESS:
		fm_effect_36(channel);
		return;
	case fm_effect_36_slide_ADDRESS:
		fm_effect_36_slide(channel);
		return;
	case fm_effect_37_ADDRESS:
		fm_effect_37(channel);
		return;
	case fm_effect_37_slide_ADDRESS:
		fm_effect_37_slide(channel);
		return;
	case fm_effect_38_ADDRESS:
		fm_effect_38(channel);
		return;
	case fm_effect_38_slide_ADDRESS:
		fm_effect_38_slide(channel);
		return;
	case unused_effect_3c_slide_ADDRESS:
		unused_effect_3c_slide(channel);
		return;
	case unused_effect_3d_lower_noise_ADDRESS:
		unused_effect_3d_lower_noise(channel);
		return;
	case unused_effect_3e_end_ADDRESS:
		unused_effect_3e_end(channel);
		return;
	case unused_effect_3f_step_ADDRESS:
		unused_effect_3f_step(channel);
		return;
	case unused_effect_3f_end_ADDRESS:
		unused_effect_3f_end(channel);
		return;
	case pcm_effect_3f_00_ADDRESS:
		pcm_effect_3f_00(channel);
		return;
	case pcm_effect_3f_00_wait_sample_ADDRESS:
		pcm_effect_3f_00_wait_sample(channel);
		return;
	case pcm_effect_3f_01_ADDRESS:
		pcm_effect_3f_01(channel);
		return;
	case pcm_effect_3f_01_wait_sample_ADDRESS:
		pcm_effect_3f_01_wait_sample(channel);
		return;
	case pcm_effect_3f_02_ADDRESS:
		pcm_effect_3f_02(channel);
		return;
	case pcm_effect_3f_02_wait_sample_ADDRESS:
		pcm_effect_3f_02_wait_sample(channel);
		return;
	case pcm_effect_3f_03_ADDRESS:
		pcm_effect_3f_03(channel);
		return;
	case pcm_effect_3f_03_wait_sample_ADDRESS:
		pcm_effect_3f_03_wait_sample(channel);
		return;
	case pcm_effect_3f_04_ADDRESS:
		pcm_effect_3f_04(channel);
		return;
	case pcm_effect_3f_04_wait_sample_ADDRESS:
		pcm_effect_3f_04_wait_sample(channel);
		return;
	case pcm_effect_3f_05_ADDRESS:
		pcm_effect_3f_05(channel);
		return;
	case pcm_effect_3f_05_wait_sample_ADDRESS:
		pcm_effect_3f_05_wait_sample(channel);
		return;
	case pcm_effect_3f_06_ADDRESS:
		pcm_effect_3f_06(channel);
		return;
	case pcm_effect_3f_06_wait_sample_ADDRESS:
		pcm_effect_3f_06_wait_sample(channel);
		return;
	case pcm_effect_3f_07_ADDRESS:
		pcm_effect_3f_07(channel);
		return;
	case pcm_effect_3f_07_wait_sample_ADDRESS:
		pcm_effect_3f_07_wait_sample(channel);
		return;
	case pcm_effect_3f_08_ADDRESS:
		pcm_effect_3f_08(channel);
		return;
	case pcm_effect_3f_08_wait_sample_ADDRESS:
		pcm_effect_3f_08_wait_sample(channel);
		return;
	case pcm_effect_3f_09_ADDRESS:
		pcm_effect_3f_09(channel);
		return;
	case pcm_effect_3f_09_wait_sample_ADDRESS:
		pcm_effect_3f_09_wait_sample(channel);
		return;
	case pcm_effect_3f_0a_ADDRESS:
		pcm_effect_3f_0a(channel);
		return;
	case pcm_effect_3f_0a_wait_sample_ADDRESS:
		pcm_effect_3f_0a_wait_sample(channel);
		return;
	case pcm_effect_3f_0b_ADDRESS:
		pcm_effect_3f_0b(channel);
		return;
	case pcm_effect_3f_0b_wait_sample_ADDRESS:
		pcm_effect_3f_0b_wait_sample(channel);
		return;
	case pcm_effect_3f_0c_ADDRESS:
		pcm_effect_3f_0c(channel);
		return;
	case pcm_effect_3f_0c_wait_sample_ADDRESS:
		pcm_effect_3f_0c_wait_sample(channel);
		return;
	case pcm_effect_3f_0d_ADDRESS:
		pcm_effect_3f_0d(channel);
		return;
	case pcm_effect_3f_0d_wait_sample_ADDRESS:
		pcm_effect_3f_0d_wait_sample(channel);
		return;
	case pcm_effect_3f_0e_ADDRESS:
		pcm_effect_3f_0e(channel);
		return;
	case pcm_effect_3f_0e_wait_sample_ADDRESS:
		pcm_effect_3f_0e_wait_sample(channel);
		return;
	case pcm_effect_3f_0f_ADDRESS:
		pcm_effect_3f_0f(channel);
		return;
	case pcm_effect_3f_0f_wait_sample_ADDRESS:
		pcm_effect_3f_0f_wait_sample(channel);
		return;
	case pcm_effect_3f_10_ADDRESS:
		pcm_effect_3f_10(channel);
		return;
	case pcm_effect_3f_10_wait_sample_ADDRESS:
		pcm_effect_3f_10_wait_sample(channel);
		return;
	case pcm_effect_3f_11_ADDRESS:
		pcm_effect_3f_11(channel);
		return;
	case pcm_effect_3f_11_wait_sample_ADDRESS:
		pcm_effect_3f_11_wait_sample(channel);
		return;
	case pcm_effect_3f_12_ADDRESS:
		pcm_effect_3f_12(channel);
		return;
	case pcm_effect_3f_12_wait_sample_ADDRESS:
		pcm_effect_3f_12_wait_sample(channel);
		return;
	case pcm_effect_3f_13_ADDRESS:
		pcm_effect_3f_13(channel);
		return;
	case pcm_effect_3f_13_wait_sample_ADDRESS:
		pcm_effect_3f_13_wait_sample(channel);
		return;
	case pcm_effect_3f_14_ADDRESS:
		pcm_effect_3f_14(channel);
		return;
	case pcm_effect_3f_14_wait_sample_ADDRESS:
		pcm_effect_3f_14_wait_sample(channel);
		return;
	case pcm_effect_3f_15_ADDRESS:
		pcm_effect_3f_15(channel);
		return;
	case pcm_effect_3f_15_wait_sample_ADDRESS:
		pcm_effect_3f_15_wait_sample(channel);
		return;
	case pcm_effect_3f_16_ADDRESS:
		pcm_effect_3f_16(channel);
		return;
	case pcm_effect_3f_16_wait_sample_ADDRESS:
		pcm_effect_3f_16_wait_sample(channel);
		return;
	case pcm_effect_3f_17_ADDRESS:
		pcm_effect_3f_17(channel);
		return;
	case pcm_effect_3f_17_wait_sample_ADDRESS:
		pcm_effect_3f_17_wait_sample(channel);
		return;
	case pcm_effect_3f_18_ADDRESS:
		pcm_effect_3f_18(channel);
		return;
	case pcm_effect_3f_18_wait_sample_ADDRESS:
		pcm_effect_3f_18_wait_sample(channel);
		return;
	case pcm_effect_3f_19_ADDRESS:
		pcm_effect_3f_19(channel);
		return;
	case pcm_effect_3f_19_wait_sample_ADDRESS:
		pcm_effect_3f_19_wait_sample(channel);
		return;
	case pcm_effect_3f_1a_ADDRESS:
		pcm_effect_3f_1a(channel);
		return;
	case pcm_effect_3f_1a_wait_sample_ADDRESS:
		pcm_effect_3f_1a_wait_sample(channel);
		return;
	case pcm_effect_3f_1b_ADDRESS:
		pcm_effect_3f_1b(channel);
		return;
	case pcm_effect_3f_1b_wait_sample_ADDRESS:
		pcm_effect_3f_1b_wait_sample(channel);
		return;
	case pcm_effect_3f_1c_ADDRESS:
		pcm_effect_3f_1c(channel);
		return;
	case pcm_effect_3f_1c_wait_sample_ADDRESS:
		pcm_effect_3f_1c_wait_sample(channel);
		return;
	case pcm_effect_3f_1d_ADDRESS:
		pcm_effect_3f_1d(channel);
		return;
	case pcm_effect_3f_1d_wait_sample_ADDRESS:
		pcm_effect_3f_1d_wait_sample(channel);
		return;
	case pcm_effect_3f_1e_ADDRESS:
		pcm_effect_3f_1e(channel);
		return;
	case pcm_effect_3f_1e_wait_sample_ADDRESS:
		pcm_effect_3f_1e_wait_sample(channel);
		return;
	case pcm_effect_3f_1f_ADDRESS:
		pcm_effect_3f_1f(channel);
		return;
	case pcm_effect_3f_1f_wait_sample_ADDRESS:
		pcm_effect_3f_1f_wait_sample(channel);
		return;
	case pcm_effect_3f_20_ADDRESS:
		pcm_effect_3f_20(channel);
		return;
	case pcm_effect_3f_20_wait_sample_ADDRESS:
		pcm_effect_3f_20_wait_sample(channel);
		return;
	case pcm_effect_3f_21_ADDRESS:
		pcm_effect_3f_21(channel);
		return;
	case pcm_effect_3f_21_wait_sample_ADDRESS:
		pcm_effect_3f_21_wait_sample(channel);
		return;
	case pcm_effect_3f_22_ADDRESS:
		pcm_effect_3f_22(channel);
		return;
	case pcm_effect_3f_22_wait_sample_ADDRESS:
		pcm_effect_3f_22_wait_sample(channel);
		return;
	case pcm_effect_3f_23_ADDRESS:
		pcm_effect_3f_23(channel);
		return;
	case pcm_effect_3f_23_wait_sample_ADDRESS:
		pcm_effect_3f_23_wait_sample(channel);
		return;
	case pcm_effect_3f_24_ADDRESS:
		pcm_effect_3f_24(channel);
		return;
	case pcm_effect_3f_24_wait_sample_ADDRESS:
		pcm_effect_3f_24_wait_sample(channel);
		return;
	case pcm_effect_3f_25_ADDRESS:
		pcm_effect_3f_25(channel);
		return;
	case pcm_effect_3f_25_wait_sample_ADDRESS:
		pcm_effect_3f_25_wait_sample(channel);
		return;
	case pcm_effect_3f_26_ADDRESS:
		pcm_effect_3f_26(channel);
		return;
	case pcm_effect_3f_26_wait_sample_ADDRESS:
		pcm_effect_3f_26_wait_sample(channel);
		return;
	case pcm_effect_3f_27_ADDRESS:
		pcm_effect_3f_27(channel);
		return;
	case pcm_effect_3f_27_wait_sample_ADDRESS:
		pcm_effect_3f_27_wait_sample(channel);
		return;
	case pcm_effect_3f_28_ADDRESS:
		pcm_effect_3f_28(channel);
		return;
	case pcm_effect_3f_28_wait_sample_ADDRESS:
		pcm_effect_3f_28_wait_sample(channel);
		return;
	case pcm_effect_3f_29_ADDRESS:
		pcm_effect_3f_29(channel);
		return;
	case pcm_effect_3f_29_wait_sample_ADDRESS:
		pcm_effect_3f_29_wait_sample(channel);
		return;
	case pcm_effect_3f_2a_ADDRESS:
		pcm_effect_3f_2a(channel);
		return;
	case pcm_effect_3f_2a_wait_sample_ADDRESS:
		pcm_effect_3f_2a_wait_sample(channel);
		return;
	case pcm_effect_3f_2b_ADDRESS:
		pcm_effect_3f_2b(channel);
		return;
	case pcm_effect_3f_2b_wait_sample_ADDRESS:
		pcm_effect_3f_2b_wait_sample(channel);
		return;
	case pcm_effect_3f_2c_ADDRESS:
		pcm_effect_3f_2c(channel);
		return;
	case pcm_effect_3f_2c_wait_sample_ADDRESS:
		pcm_effect_3f_2c_wait_sample(channel);
		return;
	case pcm_effect_3f_2d_ADDRESS:
		pcm_effect_3f_2d(channel);
		return;
	case pcm_effect_3f_2d_wait_sample_ADDRESS:
		pcm_effect_3f_2d_wait_sample(channel);
		return;
	case pcm_effect_3f_2e_ADDRESS:
		pcm_effect_3f_2e(channel);
		return;
	case pcm_effect_3f_2e_wait_sample_ADDRESS:
		pcm_effect_3f_2e_wait_sample(channel);
		return;
	case pcm_effect_3f_2f_ADDRESS:
		pcm_effect_3f_2f(channel);
		return;
	case pcm_effect_3f_30_ADDRESS:
		pcm_effect_3f_30(channel);
		return;
	case pcm_effect_3f_30_wait_sample_ADDRESS:
		pcm_effect_3f_30_wait_sample(channel);
		return;
	case pcm_effect_3f_31_ADDRESS:
		pcm_effect_3f_31(channel);
		return;
	case pcm_effect_3f_31_wait_sample_ADDRESS:
		pcm_effect_3f_31_wait_sample(channel);
		return;
	case pcm_effect_3f_32_ADDRESS:
		pcm_effect_3f_32(channel);
		return;
	case pcm_effect_3f_32_wait_sample_ADDRESS:
		pcm_effect_3f_32_wait_sample(channel);
		return;
	case pcm_effect_3f_33_ADDRESS:
		pcm_effect_3f_33(channel);
		return;
	case pcm_effect_3f_33_wait_sample_ADDRESS:
		pcm_effect_3f_33_wait_sample(channel);
		return;
	case pcm_effect_3f_34_ADDRESS:
		pcm_effect_3f_34(channel);
		return;
	case pcm_effect_3f_34_wait_sample_ADDRESS:
		pcm_effect_3f_34_wait_sample(channel);
		return;
	case pcm_effect_3f_35_ADDRESS:
		pcm_effect_3f_35(channel);
		return;
	case pcm_effect_3f_35_wait_sample_ADDRESS:
		pcm_effect_3f_35_wait_sample(channel);
		return;
	case pcm_effect_3f_36_ADDRESS:
		pcm_effect_3f_36(channel);
		return;
	case pcm_effect_3f_36_wait_sample_ADDRESS:
		pcm_effect_3f_36_wait_sample(channel);
		return;
	case pcm_effect_3f_37_ADDRESS:
		pcm_effect_3f_37(channel);
		return;
	case pcm_effect_3f_37_wait_sample_ADDRESS:
		pcm_effect_3f_37_wait_sample(channel);
		return;
	case pcm_effect_3f_38_ADDRESS:
		pcm_effect_3f_38(channel);
		return;
	case pcm_effect_3f_38_wait_sample_ADDRESS:
		pcm_effect_3f_38_wait_sample(channel);
		return;
	case pcm_effect_3f_39_ADDRESS:
		pcm_effect_3f_39(channel);
		return;
	case pcm_effect_3f_39_wait_sample_ADDRESS:
		pcm_effect_3f_39_wait_sample(channel);
		return;
	case pcm_effect_3f_3a_ADDRESS:
		pcm_effect_3f_3a(channel);
		return;
	case pcm_effect_3f_3a_wait_sample_ADDRESS:
		pcm_effect_3f_3a_wait_sample(channel);
		return;
	case pcm_effect_3f_3b_ADDRESS:
		pcm_effect_3f_3b(channel);
		return;
	case pcm_effect_3f_3b_wait_sample_ADDRESS:
		pcm_effect_3f_3b_wait_sample(channel);
		return;
	case pcm_effect_42_ADDRESS:
		pcm_effect_42(channel);
		return;
	case pcm_effect_41_ADDRESS:
		pcm_effect_41(channel);
		return;
	case pcm_effect_40_ADDRESS:
		pcm_effect_40(channel);
		return;
	case pcm_effect_42_next_note_ADDRESS:
		pcm_effect_42_next_note(channel);
		return;
	case pcm_effect_42_rest_ADDRESS:
		pcm_effect_42_rest(channel);
		return;
	case pcm_effect_43_ADDRESS:
		pcm_effect_43(channel);
		return;
	case pcm_effect_43_wait_sample_ADDRESS:
		pcm_effect_43_wait_sample(channel);
		return;
	case pcm_effect_44_ADDRESS:
		pcm_effect_44(channel);
		return;
	case pcm_effect_44_wait_sample_ADDRESS:
		pcm_effect_44_wait_sample(channel);
		return;
	case pcm_effect_45_ADDRESS:
		pcm_effect_45(channel);
		return;
	case pcm_effect_45_wait_sample_ADDRESS:
		pcm_effect_45_wait_sample(channel);
		return;
	case pcm_effect_46_ADDRESS:
		pcm_effect_46(channel);
		return;
	case pcm_effect_46_retrigger_ADDRESS:
		pcm_effect_46_retrigger(channel);
		return;
	case pcm_effect_47_ADDRESS:
		pcm_effect_47(channel);
		return;
	case pcm_effect_47_wait_sample_ADDRESS:
		pcm_effect_47_wait_sample(channel);
		return;
	case pcm_effect_48_ADDRESS:
		pcm_effect_48(channel);
		return;
	case pcm_effect_48_wait_sample_ADDRESS:
		pcm_effect_48_wait_sample(channel);
		return;
	case pcm_effect_49_ADDRESS:
		pcm_effect_49(channel);
		return;
	case pcm_effect_49_wait_sample_ADDRESS:
		pcm_effect_49_wait_sample(channel);
		return;
	case pcm_effect_4a_ADDRESS:
		pcm_effect_4a(channel);
		return;
	case pcm_effect_4a_wait_sample_ADDRESS:
		pcm_effect_4a_wait_sample(channel);
		return;
	case pcm_effect_4b_ADDRESS:
		pcm_effect_4b(channel);
		return;
	case pcm_effect_4b_wait_sample_ADDRESS:
		pcm_effect_4b_wait_sample(channel);
		return;
	case pcm_effect_4c_ADDRESS:
		pcm_effect_4c(channel);
		return;
	case pcm_effect_4c_wait_sample_ADDRESS:
		pcm_effect_4c_wait_sample(channel);
		return;
	case pcm_effect_4d_ADDRESS:
		pcm_effect_4d(channel);
		return;
	case pcm_effect_4d_wait_sample_ADDRESS:
		pcm_effect_4d_wait_sample(channel);
		return;
	case pcm_effect_4e_ADDRESS:
		pcm_effect_4e(channel);
		return;
	case pcm_effect_4e_wait_sample_ADDRESS:
		pcm_effect_4e_wait_sample(channel);
		return;
	case pcm_effect_4f_ADDRESS:
		pcm_effect_4f(channel);
		return;
	case pcm_effect_4f_wait_sample_ADDRESS:
		pcm_effect_4f_wait_sample(channel);
		return;
	case pcm_effect_50_ADDRESS:
		pcm_effect_50(channel);
		return;
	case pcm_effect_50_fade_ADDRESS:
		pcm_effect_50_fade(channel);
		return;
	case pcm_effect_50_wait_sample_ADDRESS:
		pcm_effect_50_wait_sample(channel);
		return;
	case pcm_effect_51_ADDRESS:
		pcm_effect_51(channel);
		return;
	case pcm_effect_51_wait_sample_ADDRESS:
		pcm_effect_51_wait_sample(channel);
		return;
	case pcm_effect_52_ADDRESS:
		pcm_effect_52(channel);
		return;
	case pcm_effect_52_delay_ADDRESS:
		pcm_effect_52_delay(channel);
		return;
	case pcm_effect_52_hold_ADDRESS:
		pcm_effect_52_hold(channel);
		return;
	case pcm_effect_53_ADDRESS:
		pcm_effect_53(channel);
		return;
	case pcm_effect_53_wait_sample_ADDRESS:
		pcm_effect_53_wait_sample(channel);
		return;
	case pcm_effect_54_ADDRESS:
		pcm_effect_54(channel);
		return;
	case pcm_effect_54_modulate_ADDRESS:
		pcm_effect_54_modulate(channel);
		return;
	case pcm_effect_54_wait_sample_ADDRESS:
		pcm_effect_54_wait_sample(channel);
		return;
	case pcm_effect_55_ADDRESS:
		pcm_effect_55(channel);
		return;
	case pcm_effect_55_wait_sample_ADDRESS:
		pcm_effect_55_wait_sample(channel);
		return;
	case pcm_effect_56_ADDRESS:
		pcm_effect_56(channel);
		return;
	case pcm_effect_56_retrigger_ADDRESS:
		pcm_effect_56_retrigger(channel);
		return;
	case pcm_effect_56_retrigger_2_ADDRESS:
		pcm_effect_56_retrigger_2(channel);
		return;
	case pcm_effect_56_wait_sample_ADDRESS:
		pcm_effect_56_wait_sample(channel);
		return;
	case pcm_effect_57_ADDRESS:
		pcm_effect_57(channel);
		return;
	case pcm_effect_57_retrigger_ADDRESS:
		pcm_effect_57_retrigger(channel);
		return;
	case pcm_effect_57_note_ADDRESS:
		pcm_effect_57_note(channel);
		return;
	case pcm_effect_57_wait_sample_ADDRESS:
		pcm_effect_57_wait_sample(channel);
		return;
	case pcm_effect_58_ADDRESS:
		pcm_effect_58(channel);
		return;
	case pcm_effect_58_retrigger_ADDRESS:
		pcm_effect_58_retrigger(channel);
		return;
	case pcm_effect_59_ADDRESS:
		pcm_effect_59(channel);
		return;
	case pcm_effect_59_wait_sample_ADDRESS:
		pcm_effect_59_wait_sample(channel);
		return;
	case pcm_effect_5a_ADDRESS:
		pcm_effect_5a(channel);
		return;
	case pcm_effect_5a_wait_sample_ADDRESS:
		pcm_effect_5a_wait_sample(channel);
		return;
	case pcm_effect_5b_ADDRESS:
		pcm_effect_5b(channel);
		return;
	case pcm_effect_5b_wait_sample_ADDRESS:
		pcm_effect_5b_wait_sample(channel);
		return;
	case pcm_effect_5c_ADDRESS:
		pcm_effect_5c(channel);
		return;
	case pcm_effect_5c_delay_ADDRESS:
		pcm_effect_5c_delay(channel);
		return;
	case pcm_effect_5c_hold_ADDRESS:
		pcm_effect_5c_hold(channel);
		return;
	case pcm_effect_5d_ADDRESS:
		pcm_effect_5d(channel);
		return;
	case pcm_effect_5d_delay_ADDRESS:
		pcm_effect_5d_delay(channel);
		return;
	case pcm_effect_5d_hold_ADDRESS:
		pcm_effect_5d_hold(channel);
		return;
	case pcm_effect_5e_ADDRESS:
		pcm_effect_5e(channel);
		return;
	case pcm_effect_5e_wait_sample_ADDRESS:
		pcm_effect_5e_wait_sample(channel);
		return;
	case pcm_effect_5f_ADDRESS:
		pcm_effect_5f(channel);
		return;
	case pcm_effect_5f_wait_sample_ADDRESS:
		pcm_effect_5f_wait_sample(channel);
		return;
	case pcm_effect_60_ADDRESS:
		pcm_effect_60(channel);
		return;
	case pcm_effect_60_wait_sample_ADDRESS:
		pcm_effect_60_wait_sample(channel);
		return;
	case pcm_effect_61_ADDRESS:
		pcm_effect_61(channel);
		return;
	case pcm_effect_61_wait_sample_ADDRESS:
		pcm_effect_61_wait_sample(channel);
		return;
	case pcm_effect_62_ADDRESS:
		pcm_effect_62(channel);
		return;
	case pcm_effect_62_wait_sample_ADDRESS:
		pcm_effect_62_wait_sample(channel);
		return;
	case pcm_effect_63_ADDRESS:
		pcm_effect_63(channel);
		return;
	case pcm_effect_63_wait_sample_ADDRESS:
		pcm_effect_63_wait_sample(channel);
		return;
	case pcm_effect_64_ADDRESS:
		pcm_effect_64(channel);
		return;
	case pcm_effect_64_wait_sample_ADDRESS:
		pcm_effect_64_wait_sample(channel);
		return;
	case pcm_effect_65_ADDRESS:
		pcm_effect_65(channel);
		return;
	case pcm_effect_65_wait_sample_ADDRESS:
		pcm_effect_65_wait_sample(channel);
		return;
	case pcm_effect_66_ADDRESS:
		pcm_effect_66(channel);
		return;
	case pcm_effect_66_wait_sample_ADDRESS:
		pcm_effect_66_wait_sample(channel);
		return;
	case pcm_effect_67_ADDRESS:
		pcm_effect_67(channel);
		return;
	case pcm_effect_67_wait_sample_ADDRESS:
		pcm_effect_67_wait_sample(channel);
		return;
	case pcm_effect_68_ADDRESS:
		pcm_effect_68(channel);
		return;
	case pcm_effect_68_wait_sample_ADDRESS:
		pcm_effect_68_wait_sample(channel);
		return;
	case pcm_effect_69_ADDRESS:
		pcm_effect_69(channel);
		return;
	case pcm_effect_69_wait_sample_ADDRESS:
		pcm_effect_69_wait_sample(channel);
		return;
	case pcm_effect_6a_ADDRESS:
		pcm_effect_6a(channel);
		return;
	case pcm_effect_6a_wait_sample_ADDRESS:
		pcm_effect_6a_wait_sample(channel);
		return;
	case pcm_effect_6b_ADDRESS:
		pcm_effect_6b(channel);
		return;
	case pcm_effect_6b_wait_sample_ADDRESS:
		pcm_effect_6b_wait_sample(channel);
		return;
	case pcm_effect_6c_ADDRESS:
		pcm_effect_6c(channel);
		return;
	case pcm_effect_6c_wait_sample_ADDRESS:
		pcm_effect_6c_wait_sample(channel);
		return;
	case pcm_effect_6d_ADDRESS:
		pcm_effect_6d(channel);
		return;
	case pcm_effect_6d_wait_sample_ADDRESS:
		pcm_effect_6d_wait_sample(channel);
		return;
	case pcm_effect_6e_ADDRESS:
		pcm_effect_6e(channel);
		return;
	case pcm_effect_6e_wait_sample_ADDRESS:
		pcm_effect_6e_wait_sample(channel);
		return;
	case pcm_effect_6f_ADDRESS:
		pcm_effect_6f(channel);
		return;
	case pcm_effect_6f_wait_sample_ADDRESS:
		pcm_effect_6f_wait_sample(channel);
		return;
	case pcm_effect_70_ADDRESS:
		pcm_effect_70(channel);
		return;
	case pcm_effect_70_wait_sample_ADDRESS:
		pcm_effect_70_wait_sample(channel);
		return;
	case pcm_effect_71_ADDRESS:
		pcm_effect_71(channel);
		return;
	case pcm_effect_71_wait_sample_ADDRESS:
		pcm_effect_71_wait_sample(channel);
		return;
	case pcm_effect_72_ADDRESS:
		pcm_effect_72(channel);
		return;
	case pcm_effect_72_wait_sample_ADDRESS:
		pcm_effect_72_wait_sample(channel);
		return;
	case pcm_effect_73_ADDRESS:
		pcm_effect_73(channel);
		return;
	case pcm_effect_73_wait_sample_ADDRESS:
		pcm_effect_73_wait_sample(channel);
		return;
	case pcm_effect_74_ADDRESS:
		pcm_effect_74(channel);
		return;
	case pcm_effect_74_wait_sample_ADDRESS:
		pcm_effect_74_wait_sample(channel);
		return;
	case pcm_effect_75_ADDRESS:
		pcm_effect_75(channel);
		return;
	case pcm_effect_75_wait_sample_ADDRESS:
		pcm_effect_75_wait_sample(channel);
		return;
	case pcm_effect_76_ADDRESS:
		pcm_effect_76(channel);
		return;
	case pcm_effect_76_wait_sample_ADDRESS:
		pcm_effect_76_wait_sample(channel);
		return;
	case pcm_effect_77_ADDRESS:
		pcm_effect_77(channel);
		return;
	case pcm_effect_77_delay_ADDRESS:
		pcm_effect_77_delay(channel);
		return;
	case pcm_effect_77_hold_ADDRESS:
		pcm_effect_77_hold(channel);
		return;
	case pcm_effect_78_ADDRESS:
		pcm_effect_78(channel);
		return;
	case pcm_effect_79_ADDRESS:
		pcm_effect_79(channel);
		return;
	case pcm_effect_79_wait_sample_ADDRESS:
		pcm_effect_79_wait_sample(channel);
		return;
	case pcm_effect_7a_ADDRESS:
		pcm_effect_7a(channel);
		return;
	case pcm_effect_7a_fade_in_ADDRESS:
		pcm_effect_7a_fade_in(channel);
		return;
	case pcm_effect_7a_delay_ADDRESS:
		pcm_effect_7a_delay(channel);
		return;
	case pcm_effect_7a_fade_out_ADDRESS:
		pcm_effect_7a_fade_out(channel);
		return;
	case pcm_effect_7b_ADDRESS:
		pcm_effect_7b(channel);
		return;
	case pcm_effect_7b_wait_sample_ADDRESS:
		pcm_effect_7b_wait_sample(channel);
		return;
	case pcm_effect_7c_ADDRESS:
		pcm_effect_7c(channel);
		return;
	case pcm_effect_7c_fade_in_ADDRESS:
		pcm_effect_7c_fade_in(channel);
		return;
	case pcm_effect_7c_delay_ADDRESS:
		pcm_effect_7c_delay(channel);
		return;
	case pcm_effect_7c_fade_out_ADDRESS:
		pcm_effect_7c_fade_out(channel);
		return;
	case pcm_effect_7d_ADDRESS:
		pcm_effect_7d(channel);
		return;
	case pcm_effect_7d_wait_sample_ADDRESS:
		pcm_effect_7d_wait_sample(channel);
		return;
	case pcm_effect_7e_ADDRESS:
		pcm_effect_7e(channel);
		return;
	case pcm_effect_7e_delay_ADDRESS:
		pcm_effect_7e_delay(channel);
		return;
	case pcm_effect_7e_fade_out_ADDRESS:
		pcm_effect_7e_fade_out(channel);
		return;
	case pcm_effect_7f_ADDRESS:
		pcm_effect_7f(channel);
		return;
	case pcm_effect_7f_retrigger_ADDRESS:
		pcm_effect_7f_retrigger(channel);
		return;
	case music_pitch_envelope_1_ADDRESS:
		music_pitch_envelope_1(channel);
		return;
	case music_pitch_envelope_2_ADDRESS:
		music_pitch_envelope_2(channel);
		return;
	case music_pitch_envelope_3_ADDRESS:
		music_pitch_envelope_3(channel);
		return;
	case music_pitch_envelope_4_ADDRESS:
		music_pitch_envelope_4(channel);
		return;
	case music_note_tick_ADDRESS:
		music_note_tick(channel);
		return;
	case fm_drum_1_1_ADDRESS:
		fm_drum_1_1(channel);
		return;
	case fm_drum_1_1_slide_ADDRESS:
		fm_drum_1_1_slide(channel);
		return;
	case fm_drum_1_2_ADDRESS:
		fm_drum_1_2(channel);
		return;
	case fm_drum_1_2_hold_ADDRESS:
		fm_drum_1_2_hold(channel);
		return;
	case fm_drum_1_3_ADDRESS:
		fm_drum_1_3(channel);
		return;
	case fm_drum_1_3_hold_ADDRESS:
		fm_drum_1_3_hold(channel);
		return;
	case fm_drum_1_4_ADDRESS:
		fm_drum_1_4(channel);
		return;
	case fm_drum_1_4_hold_ADDRESS:
		fm_drum_1_4_hold(channel);
		return;
	case fm_drum_1_5_ADDRESS:
		fm_drum_1_5(channel);
		return;
	case fm_drum_1_5_slide_ADDRESS:
		fm_drum_1_5_slide(channel);
		return;
	case fm_drum_1_6_ADDRESS:
		fm_drum_1_6(channel);
		return;
	case fm_drum_1_6_slide_ADDRESS:
		fm_drum_1_6_slide(channel);
		return;
	case fm_drum_1_7_ADDRESS:
		fm_drum_1_7(channel);
		return;
	case fm_drum_1_7_slide_ADDRESS:
		fm_drum_1_7_slide(channel);
		return;
	case fm_drum_1_8_ADDRESS:
		fm_drum_1_8(channel);
		return;
	case fm_drum_1_8_slide_ADDRESS:
		fm_drum_1_8_slide(channel);
		return;
	case fm_drum_1_9_ADDRESS:
		fm_drum_1_9(channel);
		return;
	case fm_drum_2_1_ADDRESS:
		fm_drum_2_1(channel);
		return;
	case fm_drum_2_1_slide_ADDRESS:
		fm_drum_2_1_slide(channel);
		return;
	case fm_drum_2_2_ADDRESS:
		fm_drum_2_2(channel);
		return;
	case fm_drum_2_2_slide_ADDRESS:
		fm_drum_2_2_slide(channel);
		return;
	case fm_drum_2_3_ADDRESS:
		fm_drum_2_3(channel);
		return;
	case fm_drum_2_3_slide_ADDRESS:
		fm_drum_2_3_slide(channel);
		return;
	case fm_drum_2_4_ADDRESS:
		fm_drum_2_4(channel);
		return;
	case fm_drum_2_4_slide_ADDRESS:
		fm_drum_2_4_slide(channel);
		return;
	case fm_drum_2_5_ADDRESS:
		fm_drum_2_5(channel);
		return;
	case fm_drum_2_5_slide_ADDRESS:
		fm_drum_2_5_slide(channel);
		return;
	case fm_drum_2_6_ADDRESS:
		fm_drum_2_6(channel);
		return;
	case pcm_drum_1_1_ADDRESS:
		pcm_drum_1_1(channel);
		return;
	case pcm_drum_1_2_ADDRESS:
		pcm_drum_1_2(channel);
		return;
	case pcm_drum_1_3_ADDRESS:
		pcm_drum_1_3(channel);
		return;
	case pcm_drum_1_4_ADDRESS:
		pcm_drum_1_4(channel);
		return;
	case pcm_drum_1_5_ADDRESS:
		pcm_drum_1_5(channel);
		return;
	case pcm_drum_1_6_ADDRESS:
		pcm_drum_1_6(channel);
		return;
	case pcm_drum_1_7_ADDRESS:
		pcm_drum_1_7(channel);
		return;
	case pcm_drum_1_8_ADDRESS:
		pcm_drum_1_8(channel);
		return;
	case pcm_drum_1_9_ADDRESS:
		pcm_drum_1_9(channel);
		return;
	case pcm_drum_1_a_ADDRESS:
		pcm_drum_1_a(channel);
		return;
	case pcm_drum_1_b_ADDRESS:
		pcm_drum_1_b(channel);
		return;
	case pcm_drum_1_b_note_ADDRESS:
		pcm_drum_1_b_note(channel);
		return;
	case pcm_drum_1_b_note_2_ADDRESS:
		pcm_drum_1_b_note_2(channel);
		return;
	case pcm_drum_1_c_ADDRESS:
		pcm_drum_1_c(channel);
		return;
	case pcm_drum_1_c_note_ADDRESS:
		pcm_drum_1_c_note(channel);
		return;
	case pcm_drum_1_c_note_2_ADDRESS:
		pcm_drum_1_c_note_2(channel);
		return;
	case pcm_drum_1_c_note_3_ADDRESS:
		pcm_drum_1_c_note_3(channel);
		return;
	case pcm_drum_1_d_ADDRESS:
		pcm_drum_1_d(channel);
		return;
	case pcm_drum_1_f_ADDRESS:
		pcm_drum_1_f(channel);
		return;
	case pcm_drum_2_1_ADDRESS:
		pcm_drum_2_1(channel);
		return;
	case pcm_drum_2_2_ADDRESS:
		pcm_drum_2_2(channel);
		return;
	case pcm_drum_2_3_ADDRESS:
		pcm_drum_2_3(channel);
		return;
	case pcm_drum_2_4_ADDRESS:
		pcm_drum_2_4(channel);
		return;
	case pcm_drum_2_5_ADDRESS:
		pcm_drum_2_5(channel);
		return;
	case pcm_drum_2_6_ADDRESS:
		pcm_drum_2_6(channel);
		return;
	case pcm_drum_2_7_ADDRESS:
		pcm_drum_2_7(channel);
		return;
	case pcm_drum_2_8_ADDRESS:
		pcm_drum_2_8(channel);
		return;
	case pcm_drum_2_9_ADDRESS:
		pcm_drum_2_9(channel);
		return;
	case pcm_drum_2_a_ADDRESS:
		pcm_drum_2_a(channel);
		return;
	case pcm_drum_2_b_ADDRESS:
		pcm_drum_2_b(channel);
		return;
	case pcm_drum_2_c_ADDRESS:
		pcm_drum_2_c(channel);
		return;
	case pcm_drum_2_d_ADDRESS:
		pcm_drum_2_d(channel);
		return;
	case pcm_drum_2_e_ADDRESS:
		pcm_drum_2_e(channel);
		return;
	case pcm_drum_2_f_ADDRESS:
		pcm_drum_2_f(channel);
		return;
	case pcm_drum_3_1_ADDRESS:
		pcm_drum_3_1(channel);
		return;
	case pcm_drum_3_2_ADDRESS:
		pcm_drum_3_2(channel);
		return;
	case pcm_drum_3_3_ADDRESS:
		pcm_drum_3_3(channel);
		return;
	case pcm_drum_3_4_ADDRESS:
		pcm_drum_3_4(channel);
		return;
	case pcm_drum_3_5_ADDRESS:
		pcm_drum_3_5(channel);
		return;
	case pcm_drum_3_6_ADDRESS:
		pcm_drum_3_6(channel);
		return;
	case pcm_drum_3_7_ADDRESS:
		pcm_drum_3_7(channel);
		return;
	case pcm_drum_3_8_ADDRESS:
		pcm_drum_3_8(channel);
		return;
	case pcm_drum_3_9_ADDRESS:
		pcm_drum_3_9(channel);
		return;
	case pcm_drum_3_a_ADDRESS:
		pcm_drum_3_a(channel);
		return;
	case pcm_drum_3_b_ADDRESS:
		pcm_drum_3_b(channel);
		return;
	case pcm_drum_3_c_ADDRESS:
		pcm_drum_3_c(channel);
		return;
	case pcm_drum_3_d_ADDRESS:
		pcm_drum_3_d(channel);
		return;
	case pcm_drum_3_e_ADDRESS:
		pcm_drum_3_e(channel);
		return;
	case pcm_drum_3_f_ADDRESS:
		pcm_drum_3_f(channel);
		return;
	case pcm_drum_4_1_ADDRESS:
		pcm_drum_4_1(channel);
		return;
	case pcm_drum_4_2_ADDRESS:
		pcm_drum_4_2(channel);
		return;
	case pcm_drum_4_3_ADDRESS:
		pcm_drum_4_3(channel);
		return;
	case pcm_drum_4_4_ADDRESS:
		pcm_drum_4_4(channel);
		return;
	case pcm_drum_4_5_ADDRESS:
		pcm_drum_4_5(channel);
		return;
	case pcm_drum_4_6_ADDRESS:
		pcm_drum_4_6(channel);
		return;
	case pcm_drum_4_7_ADDRESS:
		pcm_drum_4_7(channel);
		return;
	case pcm_drum_4_8_ADDRESS:
		pcm_drum_4_8(channel);
		return;
	case pcm_drum_4_9_ADDRESS:
		pcm_drum_4_9(channel);
		return;
	case pcm_drum_4_a_ADDRESS:
		pcm_drum_4_a(channel);
		return;
	case pcm_drum_4_b_ADDRESS:
		pcm_drum_4_b(channel);
		return;
	case pcm_drum_4_c_ADDRESS:
		pcm_drum_4_c(channel);
		return;
	case pcm_drum_4_d_ADDRESS:
		pcm_drum_4_d(channel);
		return;
	case pcm_drum_4_e_ADDRESS:
		pcm_drum_4_e(channel);
		return;
	case pcm_drum_4_f_ADDRESS:
		pcm_drum_4_f(channel);
		return;
	case pcm_drum_5_1_ADDRESS:
		pcm_drum_5_1(channel);
		return;
	case pcm_drum_5_2_ADDRESS:
		pcm_drum_5_2(channel);
		return;
	case pcm_drum_5_3_ADDRESS:
		pcm_drum_5_3(channel);
		return;
	case pcm_drum_5_4_ADDRESS:
		pcm_drum_5_4(channel);
		return;
	case pcm_drum_5_5_ADDRESS:
		pcm_drum_5_5(channel);
		return;
	case pcm_drum_5_6_ADDRESS:
		pcm_drum_5_6(channel);
		return;
	case pcm_drum_5_7_ADDRESS:
		pcm_drum_5_7(channel);
		return;
	case pcm_drum_5_8_ADDRESS:
		pcm_drum_5_8(channel);
		return;
	case pcm_drum_5_9_ADDRESS:
		pcm_drum_5_9(channel);
		return;
	case pcm_drum_5_a_ADDRESS:
		pcm_drum_5_a(channel);
		return;
	case pcm_drum_5_b_ADDRESS:
		pcm_drum_5_b(channel);
		return;
	case pcm_drum_5_c_ADDRESS:
		pcm_drum_5_c(channel);
		return;
	case pcm_drum_5_d_ADDRESS:
		pcm_drum_5_d(channel);
		return;
	case pcm_drum_5_e_ADDRESS:
		pcm_drum_5_e(channel);
		return;
	case pcm_drum_5_f_ADDRESS:
		pcm_drum_5_f(channel);
		return;
	case pcm_drum_6_1_ADDRESS:
		pcm_drum_6_1(channel);
		return;
	case pcm_drum_6_2_ADDRESS:
		pcm_drum_6_2(channel);
		return;
	case pcm_drum_6_3_ADDRESS:
		pcm_drum_6_3(channel);
		return;
	case pcm_drum_6_4_ADDRESS:
		pcm_drum_6_4(channel);
		return;
	case pcm_drum_6_5_ADDRESS:
		pcm_drum_6_5(channel);
		return;
	case pcm_drum_6_6_ADDRESS:
		pcm_drum_6_6(channel);
		return;
	case pcm_drum_6_7_ADDRESS:
		pcm_drum_6_7(channel);
		return;
	case pcm_drum_6_8_ADDRESS:
		pcm_drum_6_8(channel);
		return;
	case pcm_drum_6_9_ADDRESS:
		pcm_drum_6_9(channel);
		return;
	case pcm_drum_6_a_ADDRESS:
		pcm_drum_6_a(channel);
		return;
	case pcm_drum_6_b_ADDRESS:
		pcm_drum_6_b(channel);
		return;
	case pcm_drum_6_c_ADDRESS:
		pcm_drum_6_c(channel);
		return;
	case pcm_drum_6_d_ADDRESS:
		pcm_drum_6_d(channel);
		return;
	case pcm_drum_6_e_ADDRESS:
		pcm_drum_6_e(channel);
		return;
	case pcm_drum_6_f_ADDRESS:
		pcm_drum_6_f(channel);
		return;
	case pcm_drum_7_1_ADDRESS:
		pcm_drum_7_1(channel);
		return;
	case pcm_drum_7_2_ADDRESS:
		pcm_drum_7_2(channel);
		return;
	case pcm_drum_7_3_ADDRESS:
		pcm_drum_7_3(channel);
		return;
	case pcm_drum_7_4_ADDRESS:
		pcm_drum_7_4(channel);
		return;
	case pcm_drum_7_5_ADDRESS:
		pcm_drum_7_5(channel);
		return;
	case pcm_drum_7_6_ADDRESS:
		pcm_drum_7_6(channel);
		return;
	case pcm_drum_7_7_ADDRESS:
		pcm_drum_7_7(channel);
		return;
	case pcm_drum_7_8_ADDRESS:
		pcm_drum_7_8(channel);
		return;
	case pcm_drum_7_9_ADDRESS:
		pcm_drum_7_9(channel);
		return;
	case pcm_drum_7_a_ADDRESS:
		pcm_drum_7_a(channel);
		return;
	case pcm_drum_7_b_ADDRESS:
		pcm_drum_7_b(channel);
		return;
	case pcm_drum_7_c_ADDRESS:
		pcm_drum_7_c(channel);
		return;
	case pcm_drum_7_d_ADDRESS:
		pcm_drum_7_d(channel);
		return;
	case pcm_drum_7_e_ADDRESS:
		pcm_drum_7_e(channel);
		return;
	case pcm_drum_7_f_ADDRESS:
		pcm_drum_7_f(channel);
		return;
	case pcm_drum_8_1_ADDRESS:
		pcm_drum_8_1(channel);
		return;
	case pcm_drum_8_2_ADDRESS:
		pcm_drum_8_2(channel);
		return;
	case pcm_drum_8_3_ADDRESS:
		pcm_drum_8_3(channel);
		return;
	case pcm_drum_8_4_ADDRESS:
		pcm_drum_8_4(channel);
		return;
	case pcm_drum_8_5_ADDRESS:
		pcm_drum_8_5(channel);
		return;
	case pcm_drum_8_6_ADDRESS:
		pcm_drum_8_6(channel);
		return;
	case pcm_drum_8_7_ADDRESS:
		pcm_drum_8_7(channel);
		return;
	case pcm_drum_8_8_ADDRESS:
		pcm_drum_8_8(channel);
		return;
	case pcm_drum_8_9_ADDRESS:
		pcm_drum_8_9(channel);
		return;
	case pcm_drum_8_a_ADDRESS:
		pcm_drum_8_a(channel);
		return;
	case pcm_drum_8_b_ADDRESS:
		pcm_drum_8_b(channel);
		return;
	case pcm_drum_8_c_ADDRESS:
		pcm_drum_8_c(channel);
		return;
	case pcm_drum_8_d_ADDRESS:
		pcm_drum_8_d(channel);
		return;
	case pcm_drum_8_e_ADDRESS:
		pcm_drum_8_e(channel);
		return;
	case pcm_drum_8_f_ADDRESS:
		pcm_drum_8_f(channel);
		return;
	case pcm_drum_9_1_ADDRESS:
		pcm_drum_9_1(channel);
		return;
	case pcm_drum_9_2_ADDRESS:
		pcm_drum_9_2(channel);
		return;
	case pcm_drum_9_3_ADDRESS:
		pcm_drum_9_3(channel);
		return;
	case pcm_drum_9_4_ADDRESS:
		pcm_drum_9_4(channel);
		return;
	case pcm_drum_9_5_ADDRESS:
		pcm_drum_9_5(channel);
		return;
	case pcm_drum_9_6_ADDRESS:
		pcm_drum_9_6(channel);
		return;
	case pcm_drum_9_7_ADDRESS:
		pcm_drum_9_7(channel);
		return;
	case pcm_drum_9_8_ADDRESS:
		pcm_drum_9_8(channel);
		return;
	case pcm_drum_9_9_ADDRESS:
		pcm_drum_9_9(channel);
		return;
	case pcm_drum_9_a_ADDRESS:
		pcm_drum_9_a(channel);
		return;
	case pcm_drum_9_b_ADDRESS:
		pcm_drum_9_b(channel);
		return;
	case pcm_drum_9_c_ADDRESS:
		pcm_drum_9_c(channel);
		return;
	case pcm_drum_9_d_ADDRESS:
		pcm_drum_9_d(channel);
		return;
	case pcm_drum_9_e_ADDRESS:
		pcm_drum_9_e(channel);
		return;
	case pcm_drum_a_1_ADDRESS:
		pcm_drum_a_1(channel);
		return;
	case pcm_drum_a_2_ADDRESS:
		pcm_drum_a_2(channel);
		return;
	case pcm_drum_a_3_ADDRESS:
		pcm_drum_a_3(channel);
		return;
	case pcm_drum_a_4_ADDRESS:
		pcm_drum_a_4(channel);
		return;
	case pcm_drum_a_5_ADDRESS:
		pcm_drum_a_5(channel);
		return;
	case pcm_drum_a_6_ADDRESS:
		pcm_drum_a_6(channel);
		return;
	case pcm_drum_a_7_ADDRESS:
		pcm_drum_a_7(channel);
		return;
	case pcm_drum_a_8_ADDRESS:
		pcm_drum_a_8(channel);
		return;
	case pcm_drum_a_9_ADDRESS:
		pcm_drum_a_9(channel);
		return;
	case pcm_drum_a_a_ADDRESS:
		pcm_drum_a_a(channel);
		return;
	case pcm_drum_a_b_ADDRESS:
		pcm_drum_a_b(channel);
		return;
	case pcm_drum_a_c_ADDRESS:
		pcm_drum_a_c(channel);
		return;
	case pcm_drum_a_d_ADDRESS:
		pcm_drum_a_d(channel);
		return;
	case pcm_drum_a_e_ADDRESS:
		pcm_drum_a_e(channel);
		return;
	case pcm_drum_a_f_ADDRESS:
		pcm_drum_a_f(channel);
		return;
	case pcm_drum_b_1_ADDRESS:
		pcm_drum_b_1(channel);
		return;
	case pcm_drum_b_2_ADDRESS:
		pcm_drum_b_2(channel);
		return;
	case pcm_drum_b_3_ADDRESS:
		pcm_drum_b_3(channel);
		return;
	case pcm_drum_b_4_ADDRESS:
		pcm_drum_b_4(channel);
		return;
	case pcm_drum_b_5_ADDRESS:
		pcm_drum_b_5(channel);
		return;
	case pcm_drum_b_6_ADDRESS:
		pcm_drum_b_6(channel);
		return;
	case pcm_drum_b_7_ADDRESS:
		pcm_drum_b_7(channel);
		return;
	case pcm_drum_b_8_ADDRESS:
		pcm_drum_b_8(channel);
		return;
	case pcm_drum_b_9_ADDRESS:
		pcm_drum_b_9(channel);
		return;
	case pcm_drum_b_a_ADDRESS:
		pcm_drum_b_a(channel);
		return;
	case pcm_drum_b_b_ADDRESS:
		pcm_drum_b_b(channel);
		return;
	case pcm_drum_b_c_ADDRESS:
		pcm_drum_b_c(channel);
		return;
	case pcm_drum_b_d_ADDRESS:
		pcm_drum_b_d(channel);
		return;
	case pcm_drum_b_e_ADDRESS:
		pcm_drum_b_e(channel);
		return;
	case pcm_drum_b_f_ADDRESS:
		pcm_drum_b_f(channel);
		return;
	}
}
