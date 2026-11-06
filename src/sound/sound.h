/**
 *    Name:        sound.h
 *    Description: the sound program's ports, variables, tables, structures and functions
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    06-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the Z80 sound program decompiled into C by
 *    tools/decompile_sound.py, with the names of sound_symbols.txt.
 */
#ifndef SIMPSONS_SOUND_H
#define SIMPSONS_SOUND_H

#include "sound/support.h"

/* registers the whole program keeps (sound_symbols.txt's register lines; defined in tables.c) */
extern uint16_t program_rom_sum;
extern uint16_t sample_rom_1_sum;
extern uint16_t sample_rom_2_sum;
extern uint8_t self_test_failures;

/* the sound program's variables and channel records, in the Z80's RAM (F000-F7FF) */
#define held_command_ADDRESS 0xF000u
#define held_command SOUND_RAM16(held_command_ADDRESS)
#define command_held_ADDRESS 0xF002u
#define command_held SOUND_RAM8(command_held_ADDRESS)
#define unk_F043_ADDRESS 0xF043u
#define unk_F043 SOUND_RAM8(unk_F043_ADDRESS)
#define unk_F093_ADDRESS 0xF093u
#define unk_F093 SOUND_RAM8(unk_F093_ADDRESS)
#define unk_F0E3_ADDRESS 0xF0E3u
#define unk_F0E3 SOUND_RAM8(unk_F0E3_ADDRESS)
#define unk_F133_ADDRESS 0xF133u
#define unk_F133 SOUND_RAM8(unk_F133_ADDRESS)
#define unk_F183_ADDRESS 0xF183u
#define unk_F183 SOUND_RAM8(unk_F183_ADDRESS)
#define unk_F1D3_ADDRESS 0xF1D3u
#define unk_F1D3 SOUND_RAM8(unk_F1D3_ADDRESS)
#define unk_F223_ADDRESS 0xF223u
#define unk_F223 SOUND_RAM8(unk_F223_ADDRESS)
#define unk_F273_ADDRESS 0xF273u
#define unk_F273 SOUND_RAM8(unk_F273_ADDRESS)
#define unk_F274_ADDRESS 0xF274u
#define unk_F274 SOUND_RAM8(unk_F274_ADDRESS)
#define unk_F275_ADDRESS 0xF275u
#define unk_F275 SOUND_RAM8(unk_F275_ADDRESS)
#define unk_F276_ADDRESS 0xF276u
#define unk_F276 SOUND_RAM8(unk_F276_ADDRESS)
#define unk_F277_ADDRESS 0xF277u
#define unk_F277 SOUND_RAM8(unk_F277_ADDRESS)
#define unk_F278_ADDRESS 0xF278u
#define unk_F278 SOUND_RAM8(unk_F278_ADDRESS)
#define unk_F2C3_ADDRESS 0xF2C3u
#define unk_F2C3 SOUND_RAM8(unk_F2C3_ADDRESS)
#define unk_F2CD_ADDRESS 0xF2CDu
#define unk_F2CD SOUND_RAM8(unk_F2CD_ADDRESS)
#define unk_F2CE_ADDRESS 0xF2CEu
#define unk_F2CE SOUND_RAM8(unk_F2CE_ADDRESS)
#define unk_F2CF_ADDRESS 0xF2CFu
#define unk_F2CF SOUND_RAM8(unk_F2CF_ADDRESS)
#define unk_F2D0_ADDRESS 0xF2D0u
#define unk_F2D0 SOUND_RAM8(unk_F2D0_ADDRESS)
#define unk_F2D1_ADDRESS 0xF2D1u
#define unk_F2D1 SOUND_RAM8(unk_F2D1_ADDRESS)
#define unk_F2D2_ADDRESS 0xF2D2u
#define unk_F2D2 SOUND_RAM8(unk_F2D2_ADDRESS)
#define unk_F313_ADDRESS 0xF313u
#define unk_F313 SOUND_RAM8(unk_F313_ADDRESS)
#define unk_F31D_ADDRESS 0xF31Du
#define unk_F31D SOUND_RAM8(unk_F31D_ADDRESS)
#define unk_F31E_ADDRESS 0xF31Eu
#define unk_F31E SOUND_RAM8(unk_F31E_ADDRESS)
#define unk_F31F_ADDRESS 0xF31Fu
#define unk_F31F SOUND_RAM8(unk_F31F_ADDRESS)
#define unk_F320_ADDRESS 0xF320u
#define unk_F320 SOUND_RAM8(unk_F320_ADDRESS)
#define unk_F321_ADDRESS 0xF321u
#define unk_F321 SOUND_RAM8(unk_F321_ADDRESS)
#define unk_F322_ADDRESS 0xF322u
#define unk_F322 SOUND_RAM8(unk_F322_ADDRESS)
#define unk_F363_ADDRESS 0xF363u
#define unk_F363 SOUND_RAM8(unk_F363_ADDRESS)
#define unk_F36D_ADDRESS 0xF36Du
#define unk_F36D SOUND_RAM8(unk_F36D_ADDRESS)
#define unk_F36E_ADDRESS 0xF36Eu
#define unk_F36E SOUND_RAM8(unk_F36E_ADDRESS)
#define unk_F36F_ADDRESS 0xF36Fu
#define unk_F36F SOUND_RAM8(unk_F36F_ADDRESS)
#define unk_F370_ADDRESS 0xF370u
#define unk_F370 SOUND_RAM8(unk_F370_ADDRESS)
#define unk_F371_ADDRESS 0xF371u
#define unk_F371 SOUND_RAM8(unk_F371_ADDRESS)
#define unk_F372_ADDRESS 0xF372u
#define unk_F372 SOUND_RAM8(unk_F372_ADDRESS)
#define unk_F3B3_ADDRESS 0xF3B3u
#define unk_F3B3 SOUND_RAM8(unk_F3B3_ADDRESS)
#define unk_F3BD_ADDRESS 0xF3BDu
#define unk_F3BD SOUND_RAM8(unk_F3BD_ADDRESS)
#define unk_F3BE_ADDRESS 0xF3BEu
#define unk_F3BE SOUND_RAM8(unk_F3BE_ADDRESS)
#define unk_F3BF_ADDRESS 0xF3BFu
#define unk_F3BF SOUND_RAM8(unk_F3BF_ADDRESS)
#define unk_F3C0_ADDRESS 0xF3C0u
#define unk_F3C0 SOUND_RAM8(unk_F3C0_ADDRESS)
#define unk_F3C1_ADDRESS 0xF3C1u
#define unk_F3C1 SOUND_RAM8(unk_F3C1_ADDRESS)
#define unk_F3C2_ADDRESS 0xF3C2u
#define unk_F3C2 SOUND_RAM8(unk_F3C2_ADDRESS)
#define pcm_keys_ADDRESS 0xF3C3u
#define pcm_keys SOUND_RAM8(pcm_keys_ADDRESS)
#define pcm_loops_ADDRESS 0xF3C4u
#define pcm_loops SOUND_RAM8(pcm_loops_ADDRESS)
#define pcm_pans_1_ADDRESS 0xF3C5u
#define pcm_pans_1 SOUND_RAM8(pcm_pans_1_ADDRESS)
#define pcm_pans_2_ADDRESS 0xF3C6u
#define pcm_pans_2 SOUND_RAM8(pcm_pans_2_ADDRESS)
#define pcm_keyed_ADDRESS 0xF3C7u
#define pcm_keyed SOUND_RAM8(pcm_keyed_ADDRESS)
#define byte_pointer_ADDRESS 0xF3C8u
#define byte_pointer SOUND_RAM16(byte_pointer_ADDRESS)
#define fade_ADDRESS 0xF3CAu
#define fade SOUND_RAM8(fade_ADDRESS)
#define fade_attenuation_ADDRESS 0xF3CBu
#define fade_attenuation SOUND_RAM8(fade_attenuation_ADDRESS)
#define fade_period_ADDRESS 0xF3CCu
#define fade_period SOUND_RAM8(fade_period_ADDRESS)
#define fade_timer_ADDRESS 0xF3CDu
#define fade_timer SOUND_RAM8(fade_timer_ADDRESS)
#define fade_next_song_ADDRESS 0xF3CEu
#define fade_next_song SOUND_RAM8(fade_next_song_ADDRESS)
#define fade_hold_ADDRESS 0xF3CFu
#define fade_hold SOUND_RAM8(fade_hold_ADDRESS)
#define pass_count_ADDRESS 0xF3D0u
#define pass_count SOUND_RAM8(pass_count_ADDRESS)
#define command_f8_count_ADDRESS 0xF3D1u
#define command_f8_count SOUND_RAM8(command_f8_count_ADDRESS)

/* data in the program ROM the code reads, which the game loads from its assets */
#define rom_0007_ADDRESS 0x0007u
extern const void *rom_0007_data;
#define rom_0007 ((const uint8_t *)rom_0007_data)
#define carrier_masks_ADDRESS 0x0DB8u
extern const void *carrier_masks_data;
#define carrier_masks ((const uint8_t *)carrier_masks_data)
#define note_codes_ADDRESS 0x0E10u
extern const void *note_codes_data;
#define note_codes ((const uint8_t *)note_codes_data)
#define effect_handlers_ADDRESS 0x1016u
extern const void *effect_handlers_data;
#define effect_handlers (*(const uint16_t *)effect_handlers_data)
#define effect_priorities_ADDRESS 0x1086u
extern const void *effect_priorities_data;
#define effect_priorities ((const uint8_t *)effect_priorities_data)
#define unused_effect_priorities_by_sound_ADDRESS 0x2740u
extern const void *unused_effect_priorities_by_sound_data;
#define unused_effect_priorities_by_sound ((const uint8_t *)unused_effect_priorities_by_sound_data)
#define unused_effect_group_ADDRESS 0x2774u
extern const void *unused_effect_group_data;
#define unused_effect_group (*(const uint16_t *)unused_effect_group_data)
#define unused_effect_priorities_ADDRESS 0x277Cu
extern const void *unused_effect_priorities_data;
#define unused_effect_priorities (*(const uint8_t *)unused_effect_priorities_data)
#define samples_ADDRESS 0x28E9u
extern const void *samples_data;
#define samples (*(const uint8_t *)samples_data)
#define effect_handlers_2_ADDRESS 0x2E01u
extern const void *effect_handlers_2_data;
#define effect_handlers_2 (*(const uint16_t *)effect_handlers_2_data)
#define effect_priorities_2_ADDRESS 0x2E79u
extern const void *effect_priorities_2_data;
#define effect_priorities_2 ((const uint8_t *)effect_priorities_2_data)
#define effect_handlers_40_ADDRESS 0x35F0u
extern const void *effect_handlers_40_data;
#define effect_handlers_40 (*(const uint16_t *)effect_handlers_40_data)
#define effect_priorities_40_by_sound_ADDRESS 0x3630u
extern const void *effect_priorities_40_by_sound_data;
#define effect_priorities_40_by_sound ((const uint8_t *)effect_priorities_40_by_sound_data)
#define effect_priorities_40_ADDRESS 0x3670u
extern const void *effect_priorities_40_data;
#define effect_priorities_40 (*(const uint8_t *)effect_priorities_40_data)
#define effect_levels_ADDRESS 0x4168u
extern const void *effect_levels_data;
#define effect_levels (*(const uint16_t *)effect_levels_data)
#define fm_pitches_ADDRESS 0x44A5u
extern const void *fm_pitches_data;
#define fm_pitches (*(const uint16_t *)fm_pitches_data)
#define pcm_pitches_ADDRESS 0x4533u
extern const void *pcm_pitches_data;
#define pcm_pitches (*(const uint16_t *)pcm_pitches_data)
#define note_lengths_ADDRESS 0x48FAu
extern const void *note_lengths_data;
#define note_lengths (*(const uint16_t *)note_lengths_data)
#define song_banks_by_sound_ADDRESS 0x5D92u
extern const void *song_banks_by_sound_data;
#define song_banks_by_sound ((const uint8_t *)song_banks_by_sound_data)
#define song_headers_ADDRESS 0x5DB2u
extern const void *song_headers_data;
#define song_headers (*(const uint16_t *)song_headers_data)
#define song_banks_ADDRESS 0x5E12u
extern const void *song_banks_data;
#define song_banks (*(const uint8_t *)song_banks_data)
#define music_fm_patches_ADDRESS 0x5E42u
extern const void *music_fm_patches_data;
#define music_fm_patches (*(const uint16_t *)music_fm_patches_data)
#define music_pcm_patches_ADDRESS 0x63F4u
extern const void *music_pcm_patches_data;
#define music_pcm_patches (*(const uint16_t *)music_pcm_patches_data)
#define music_pcm_transpositions_ADDRESS 0x642Cu
extern const void *music_pcm_transpositions_data;
#define music_pcm_transpositions (*(const int16_t *)music_pcm_transpositions_data)

/* the board's registers on the Z80's bus: the YM2151, FA00 (the NMI's arming), the K053260 with
   the ports between the two CPUs, and the bank of 8000-BFFF (read and written through the bus) */
#define FM_F800 0xF800u
#define FM_F801 0xF801u
#define NMI_ARM_FA00 0xFA00u
#define PCM_FC00 0xFC00u
#define PCM_FC02 0xFC02u
#define PCM_FC08 0xFC08u
#define PCM_FC0A 0xFC0Au
#define PCM_FC0C 0xFC0Cu
#define PCM_FC0E 0xFC0Eu
#define PCM_FC10 0xFC10u
#define PCM_FC12 0xFC12u
#define PCM_FC14 0xFC14u
#define PCM_FC16 0xFC16u
#define PCM_FC18 0xFC18u
#define PCM_FC1A 0xFC1Au
#define PCM_FC1C 0xFC1Cu
#define PCM_FC1E 0xFC1Eu
#define PCM_FC20 0xFC20u
#define PCM_FC22 0xFC22u
#define PCM_FC24 0xFC24u
#define PCM_FC26 0xFC26u
#define PCM_FC28 0xFC28u
#define PCM_FC29 0xFC29u
#define PCM_FC2A 0xFC2Au
#define PCM_FC2C 0xFC2Cu
#define PCM_FC2D 0xFC2Du
#define PCM_FC2E 0xFC2Eu
#define PCM_FC2F 0xFC2Fu
#define SOUND_BANK_FE00 0xFE00u

/* data in the program ROM sound_symbols.txt labels */
#define effect_steps_12e1_ADDRESS 0x12E1u
#define unused_effect_handlers_ADDRESS 0x26FCu
#define effect_steps_36b9_ADDRESS 0x36B9u
#define music_commands_ADDRESS 0x44A6u
#define instrument_routines_low_ADDRESS 0x496Cu
#define instrument_routines_ADDRESS 0x4E4Eu

/* where the code the program holds as values is (the handlers it stores and switches on) */
#define channel_idle_ADDRESS 0x0C39u
#define pcm_voice_playing_ADDRESS 0x1000u
#define fm_effect_02_ADDRESS 0x10D7u
#define fm_effect_02_delay_ADDRESS 0x10E1u
#define fm_effect_01_ADDRESS 0x10E5u
#define fm_effect_01_retrigger_ADDRESS 0x1108u
#define fm_effect_01_pitch_ADDRESS 0x1131u
#define fm_effect_04_ADDRESS 0x1176u
#define fm_effect_04_delay_ADDRESS 0x1180u
#define fm_effect_03_ADDRESS 0x1184u
#define fm_effect_03_pitch_ADDRESS 0x11ABu
#define fm_effect_06_ADDRESS 0x11EFu
#define fm_effect_06_delay_ADDRESS 0x1201u
#define fm_effect_05_ADDRESS 0x1208u
#define fm_effect_05_slide_ADDRESS 0x122Fu
#define fm_effect_07_ADDRESS 0x127Eu
#define fm_effect_07_slide_ADDRESS 0x12A2u
#define fm_effect_09_ADDRESS 0x12F1u
#define fm_effect_09_delay_ADDRESS 0x12FBu
#define fm_effect_08_ADDRESS 0x12FFu
#define fm_effect_08_retrigger_ADDRESS 0x1318u
#define fm_effect_08_hold_ADDRESS 0x134Au
#define fm_effect_0d_ADDRESS 0x136Au
#define fm_effect_0d_delay_ADDRESS 0x1374u
#define fm_effect_0c_ADDRESS 0x1378u
#define fm_effect_0c_retrigger_ADDRESS 0x139Bu
#define fm_effect_0c_retrigger_2_ADDRESS 0x13ABu
#define fm_effect_0c_hold_ADDRESS 0x13CBu
#define fm_effect_0e_ADDRESS 0x1405u
#define fm_effect_0e_pitch_ADDRESS 0x1428u
#define fm_effect_0e_pitch_2_ADDRESS 0x1439u
#define fm_effect_0e_pitch_3_ADDRESS 0x145Du
#define fm_effect_0f_ADDRESS 0x14A5u
#define fm_effect_0f_slide_ADDRESS 0x14C8u
#define fm_effect_10_ADDRESS 0x1522u
#define fm_effect_10_slide_ADDRESS 0x1545u
#define fm_effect_11_ADDRESS 0x159Fu
#define fm_effect_11_pitch_ADDRESS 0x15C3u
#define fm_effect_12_ADDRESS 0x1610u
#define fm_effect_12_delay_ADDRESS 0x1633u
#define fm_effect_12_slide_ADDRESS 0x1651u
#define fm_effect_13_ADDRESS 0x1698u
#define fm_effect_13_slide_ADDRESS 0x16BFu
#define fm_effect_13_slide_2_ADDRESS 0x1705u
#define fm_effect_13_slide_3_ADDRESS 0x173Cu
#define fm_effect_14_ADDRESS 0x1787u
#define fm_effect_14_slide_ADDRESS 0x17ADu
#define fm_effect_14_slide_2_ADDRESS 0x17F4u
#define fm_effect_15_ADDRESS 0x184Cu
#define fm_effect_15_note_ADDRESS 0x1869u
#define fm_effect_15_slide_ADDRESS 0x189Bu
#define fm_effect_17_ADDRESS 0x18D8u
#define fm_effect_17_delay_ADDRESS 0x18E7u
#define fm_effect_16_ADDRESS 0x18EBu
#define fm_effect_16_pitch_ADDRESS 0x1912u
#define fm_effect_18_ADDRESS 0x1956u
#define fm_effect_18_slide_ADDRESS 0x1975u
#define fm_effect_19_ADDRESS 0x19B2u
#define fm_effect_19_slide_ADDRESS 0x19D9u
#define fm_effect_1a_ADDRESS 0x1A28u
#define fm_effect_1a_slide_ADDRESS 0x1A4Bu
#define fm_effect_1b_ADDRESS 0x1A8Fu
#define fm_effect_1b_pitch_ADDRESS 0x1AAEu
#define fm_effect_1b_pitch_2_ADDRESS 0x1ABFu
#define fm_effect_1c_ADDRESS 0x1B01u
#define fm_effect_1c_pitch_ADDRESS 0x1B24u
#define fm_effect_1c_pitch_2_ADDRESS 0x1B35u
#define fm_effect_1c_pitch_3_ADDRESS 0x1B59u
#define fm_effect_1d_ADDRESS 0x1BA1u
#define fm_effect_1d_pitch_ADDRESS 0x1BC0u
#define fm_effect_1d_pitch_3_ADDRESS 0x1BE1u
#define fm_effect_1e_ADDRESS 0x1C29u
#define fm_effect_1e_slide_ADDRESS 0x1C48u
#define fm_effect_1f_ADDRESS 0x1C85u
#define fm_effect_1f_retrigger_ADDRESS 0x1C9Eu
#define fm_effect_1f_end_ADDRESS 0x1CBDu
#define fm_effect_20_ADDRESS 0x1CE9u
#define fm_effect_20_pitch_ADDRESS 0x1D08u
#define fm_effect_20_pitch_2_ADDRESS 0x1D19u
#define fm_effect_21_ADDRESS 0x1D5Bu
#define fm_effect_21_end_ADDRESS 0x1D79u
#define fm_effect_22_ADDRESS 0x1DA5u
#define fm_effect_22_slide_ADDRESS 0x1DC8u
#define fm_effect_23_ADDRESS 0x1E0Cu
#define fm_effect_23_slide_ADDRESS 0x1E2Fu
#define fm_effect_24_ADDRESS 0x1E73u
#define fm_effect_24_retrigger_ADDRESS 0x1E96u
#define fm_effect_24_hold_ADDRESS 0x1EC7u
#define fm_effect_25_ADDRESS 0x1EE7u
#define fm_effect_25_note_ADDRESS 0x1EF1u
#define fm_effect_25_retrigger_ADDRESS 0x1F18u
#define fm_effect_25_hold_ADDRESS 0x1F49u
#define fm_effect_26_ADDRESS 0x1F69u
#define fm_effect_26_slide_ADDRESS 0x1F9Cu
#define fm_effect_26_pitch_ADDRESS 0x1FBAu
#define fm_effect_27_ADDRESS 0x1FF7u
#define fm_effect_27_retrigger_ADDRESS 0x201Au
#define fm_effect_27_hold_ADDRESS 0x204Bu
#define fm_effect_28_ADDRESS 0x206Bu
#define fm_effect_28_slide_ADDRESS 0x208Eu
#define fm_effect_29_ADDRESS 0x20E4u
#define fm_effect_29_pitch_ADDRESS 0x2103u
#define fm_effect_29_slide_ADDRESS 0x2118u
#define fm_effect_2b_ADDRESS 0x2165u
#define fm_effect_2b_delay_ADDRESS 0x216Fu
#define fm_effect_2a_ADDRESS 0x2173u
#define fm_effect_2a_retrigger_ADDRESS 0x2196u
#define fm_effect_2a_retrigger_2_ADDRESS 0x21A6u
#define fm_effect_2a_hold_ADDRESS 0x21C6u
#define fm_effect_2c_ADDRESS 0x2200u
#define fm_effect_2c_delay_ADDRESS 0x2227u
#define fm_effect_2c_hold_ADDRESS 0x2248u
#define fm_effect_2d_ADDRESS 0x22A1u
#define fm_effect_2d_note_ADDRESS 0x22ABu
#define fm_effect_2d_delay_ADDRESS 0x22D6u
#define fm_effect_2d_hold_ADDRESS 0x22F7u
#define fm_effect_2e_ADDRESS 0x2350u
#define fm_effect_2e_note_ADDRESS 0x235Au
#define fm_effect_2e_delay_ADDRESS 0x2385u
#define fm_effect_2e_hold_ADDRESS 0x23A6u
#define fm_effect_2f_ADDRESS 0x23FFu
#define fm_effect_2f_slide_ADDRESS 0x2426u
#define fm_effect_32_ADDRESS 0x2475u
#define fm_effect_32_delay_ADDRESS 0x247Fu
#define fm_effect_31_ADDRESS 0x2483u
#define fm_effect_31_delay_ADDRESS 0x248Du
#define fm_effect_30_ADDRESS 0x2491u
#define fm_effect_30_retrigger_2_ADDRESS 0x24B8u
#define fm_effect_33_ADDRESS 0x2501u
#define fm_effect_33_retrigger_2_ADDRESS 0x2528u
#define fm_effect_34_ADDRESS 0x2571u
#define fm_effect_34_slide_ADDRESS 0x2598u
#define fm_effect_35_ADDRESS 0x25DAu
#define fm_effect_35_note_ADDRESS 0x25E4u
#define fm_effect_35_slide_ADDRESS 0x260Fu
#define fm_effect_36_ADDRESS 0x2651u
#define fm_effect_36_slide_ADDRESS 0x2674u
#define fm_effect_37_ADDRESS 0x26ADu
#define fm_effect_37_slide_ADDRESS 0x26D4u
#define fm_effect_38_ADDRESS 0x2717u
#define fm_effect_38_slide_ADDRESS 0x273Eu
#define unused_effect_2799_slide_ADDRESS 0x27C0u
#define unused_effect_280E_hold_ADDRESS 0x2829u
#define unused_effect_2856_end_ADDRESS 0x2873u
#define unused_effect_289F_step_ADDRESS 0x28BCu
#define unused_effect_289F_end_ADDRESS 0x28D2u
#define pcm_effect_3f_00_ADDRESS 0x2EB8u
#define pcm_effect_3f_00_wait_sample_ADDRESS 0x2ECCu
#define pcm_effect_3f_01_ADDRESS 0x2ED6u
#define pcm_effect_3f_01_wait_sample_ADDRESS 0x2EEAu
#define pcm_effect_3f_02_ADDRESS 0x2EF4u
#define pcm_effect_3f_02_wait_sample_ADDRESS 0x2F08u
#define pcm_effect_3f_03_ADDRESS 0x2F12u
#define pcm_effect_3f_03_wait_sample_ADDRESS 0x2F26u
#define pcm_effect_3f_04_ADDRESS 0x2F30u
#define pcm_effect_3f_04_wait_sample_ADDRESS 0x2F44u
#define pcm_effect_3f_05_ADDRESS 0x2F4Eu
#define pcm_effect_3f_05_wait_sample_ADDRESS 0x2F62u
#define pcm_effect_3f_06_ADDRESS 0x2F6Cu
#define pcm_effect_3f_06_wait_sample_ADDRESS 0x2F80u
#define pcm_effect_3f_07_ADDRESS 0x2F8Au
#define pcm_effect_3f_07_wait_sample_ADDRESS 0x2F9Eu
#define pcm_effect_3f_08_ADDRESS 0x2FA8u
#define pcm_effect_3f_08_wait_sample_ADDRESS 0x2FBCu
#define pcm_effect_3f_09_ADDRESS 0x2FC6u
#define pcm_effect_3f_09_wait_sample_ADDRESS 0x2FDAu
#define pcm_effect_3f_0a_ADDRESS 0x2FE4u
#define pcm_effect_3f_0a_wait_sample_ADDRESS 0x2FF8u
#define pcm_effect_3f_0b_ADDRESS 0x3002u
#define pcm_effect_3f_0b_wait_sample_ADDRESS 0x3016u
#define pcm_effect_3f_0c_ADDRESS 0x3020u
#define pcm_effect_3f_0c_wait_sample_ADDRESS 0x3034u
#define pcm_effect_3f_0d_ADDRESS 0x303Eu
#define pcm_effect_3f_0d_wait_sample_ADDRESS 0x3052u
#define pcm_effect_3f_0e_ADDRESS 0x305Cu
#define pcm_effect_3f_0e_wait_sample_ADDRESS 0x3070u
#define pcm_effect_3f_0f_ADDRESS 0x307Au
#define pcm_effect_3f_0f_wait_sample_ADDRESS 0x308Eu
#define pcm_effect_3f_10_ADDRESS 0x3098u
#define pcm_effect_3f_10_wait_sample_ADDRESS 0x30ACu
#define pcm_effect_3f_11_ADDRESS 0x30B6u
#define pcm_effect_3f_11_wait_sample_ADDRESS 0x30CAu
#define pcm_effect_3f_12_ADDRESS 0x30D4u
#define pcm_effect_3f_12_wait_sample_ADDRESS 0x30E8u
#define pcm_effect_3f_13_ADDRESS 0x30F2u
#define pcm_effect_3f_13_wait_sample_ADDRESS 0x3106u
#define pcm_effect_3f_14_ADDRESS 0x3110u
#define pcm_effect_3f_14_wait_sample_ADDRESS 0x3124u
#define pcm_effect_3f_15_ADDRESS 0x312Eu
#define pcm_effect_3f_15_wait_sample_ADDRESS 0x3142u
#define pcm_effect_3f_16_ADDRESS 0x314Cu
#define pcm_effect_3f_16_wait_sample_ADDRESS 0x3160u
#define pcm_effect_3f_17_ADDRESS 0x316Au
#define pcm_effect_3f_17_wait_sample_ADDRESS 0x317Eu
#define pcm_effect_3f_18_ADDRESS 0x3188u
#define pcm_effect_3f_18_wait_sample_ADDRESS 0x319Cu
#define pcm_effect_3f_19_ADDRESS 0x31A6u
#define pcm_effect_3f_19_wait_sample_ADDRESS 0x31BAu
#define pcm_effect_3f_1a_ADDRESS 0x31C4u
#define pcm_effect_3f_1a_wait_sample_ADDRESS 0x31D8u
#define pcm_effect_3f_1b_ADDRESS 0x31E2u
#define pcm_effect_3f_1b_wait_sample_ADDRESS 0x31F6u
#define pcm_effect_3f_1c_ADDRESS 0x3200u
#define pcm_effect_3f_1c_wait_sample_ADDRESS 0x3214u
#define pcm_effect_3f_1d_ADDRESS 0x321Eu
#define pcm_effect_3f_1d_wait_sample_ADDRESS 0x3232u
#define pcm_effect_3f_1e_ADDRESS 0x323Cu
#define pcm_effect_3f_1e_wait_sample_ADDRESS 0x3250u
#define pcm_effect_3f_1f_ADDRESS 0x325Au
#define pcm_effect_3f_1f_wait_sample_ADDRESS 0x326Eu
#define pcm_effect_3f_20_ADDRESS 0x3278u
#define pcm_effect_3f_20_wait_sample_ADDRESS 0x328Cu
#define pcm_effect_3f_21_ADDRESS 0x3296u
#define pcm_effect_3f_21_wait_sample_ADDRESS 0x32AAu
#define pcm_effect_3f_22_ADDRESS 0x32B4u
#define pcm_effect_3f_22_wait_sample_ADDRESS 0x32C8u
#define pcm_effect_3f_23_ADDRESS 0x32D2u
#define pcm_effect_3f_23_wait_sample_ADDRESS 0x32E6u
#define pcm_effect_3f_24_ADDRESS 0x32F0u
#define pcm_effect_3f_24_wait_sample_ADDRESS 0x3304u
#define pcm_effect_3f_25_ADDRESS 0x330Eu
#define pcm_effect_3f_25_wait_sample_ADDRESS 0x3322u
#define pcm_effect_3f_26_ADDRESS 0x332Cu
#define pcm_effect_3f_26_wait_sample_ADDRESS 0x3340u
#define pcm_effect_3f_27_ADDRESS 0x334Au
#define pcm_effect_3f_27_wait_sample_ADDRESS 0x335Eu
#define pcm_effect_3f_28_ADDRESS 0x3368u
#define pcm_effect_3f_28_wait_sample_ADDRESS 0x337Cu
#define pcm_effect_3f_29_ADDRESS 0x3386u
#define pcm_effect_3f_29_wait_sample_ADDRESS 0x339Au
#define pcm_effect_3f_2a_ADDRESS 0x33A4u
#define pcm_effect_3f_2a_wait_sample_ADDRESS 0x33B8u
#define pcm_effect_3f_2b_ADDRESS 0x33C2u
#define pcm_effect_3f_2b_wait_sample_ADDRESS 0x33D6u
#define pcm_effect_3f_2c_ADDRESS 0x33E0u
#define pcm_effect_3f_2c_wait_sample_ADDRESS 0x33FAu
#define pcm_effect_3f_2d_ADDRESS 0x3404u
#define pcm_effect_3f_2d_wait_sample_ADDRESS 0x341Eu
#define pcm_effect_3f_2e_ADDRESS 0x3428u
#define pcm_effect_3f_2e_wait_sample_ADDRESS 0x3442u
#define pcm_effect_3f_2f_ADDRESS 0x3449u
#define pcm_effect_3f_30_ADDRESS 0x344Fu
#define pcm_effect_3f_30_wait_sample_ADDRESS 0x3469u
#define pcm_effect_3f_31_ADDRESS 0x3473u
#define pcm_effect_3f_31_wait_sample_ADDRESS 0x348Du
#define pcm_effect_3f_32_ADDRESS 0x3497u
#define pcm_effect_3f_32_wait_sample_ADDRESS 0x34B1u
#define pcm_effect_3f_33_ADDRESS 0x34BBu
#define pcm_effect_3f_33_wait_sample_ADDRESS 0x34D5u
#define pcm_effect_3f_34_ADDRESS 0x34DFu
#define pcm_effect_3f_34_wait_sample_ADDRESS 0x34F9u
#define pcm_effect_3f_35_ADDRESS 0x3503u
#define pcm_effect_3f_35_wait_sample_ADDRESS 0x351Du
#define pcm_effect_3f_36_ADDRESS 0x3527u
#define pcm_effect_3f_36_wait_sample_ADDRESS 0x3541u
#define pcm_effect_3f_37_ADDRESS 0x354Bu
#define pcm_effect_3f_37_wait_sample_ADDRESS 0x3565u
#define pcm_effect_3f_38_ADDRESS 0x356Fu
#define pcm_effect_3f_38_wait_sample_ADDRESS 0x3583u
#define pcm_effect_3f_39_ADDRESS 0x3599u
#define pcm_effect_3f_39_wait_sample_ADDRESS 0x35ADu
#define pcm_effect_3f_3a_ADDRESS 0x35B7u
#define pcm_effect_3f_3a_wait_sample_ADDRESS 0x35CBu
#define pcm_effect_3f_3b_ADDRESS 0x35D5u
#define pcm_effect_3f_3b_wait_sample_ADDRESS 0x35E9u
#define pcm_effect_42_ADDRESS 0x3719u
#define pcm_effect_41_ADDRESS 0x372Au
#define pcm_effect_40_ADDRESS 0x373Bu
#define pcm_effect_42_retrigger_ADDRESS 0x375Du
#define pcm_effect_42_setup_2_ADDRESS 0x378Fu
#define pcm_effect_43_ADDRESS 0x37C5u
#define pcm_effect_43_wait_sample_ADDRESS 0x37D9u
#define pcm_effect_44_ADDRESS 0x37E3u
#define pcm_effect_44_wait_sample_ADDRESS 0x37F7u
#define pcm_effect_45_ADDRESS 0x3801u
#define pcm_effect_45_wait_sample_ADDRESS 0x3815u
#define pcm_effect_46_ADDRESS 0x381Fu
#define pcm_effect_46_retrigger_ADDRESS 0x3837u
#define pcm_effect_47_ADDRESS 0x384Au
#define pcm_effect_47_wait_sample_ADDRESS 0x385Eu
#define pcm_effect_48_ADDRESS 0x3868u
#define pcm_effect_48_wait_sample_ADDRESS 0x387Cu
#define pcm_effect_49_ADDRESS 0x3886u
#define pcm_effect_49_wait_sample_ADDRESS 0x389Au
#define pcm_effect_4a_ADDRESS 0x38A4u
#define pcm_effect_4a_wait_sample_ADDRESS 0x38B8u
#define pcm_effect_4b_ADDRESS 0x38C2u
#define pcm_effect_4b_wait_sample_ADDRESS 0x38D6u
#define pcm_effect_4c_ADDRESS 0x38E0u
#define pcm_effect_4c_wait_sample_ADDRESS 0x38F4u
#define pcm_effect_4d_ADDRESS 0x38FEu
#define pcm_effect_4d_wait_sample_ADDRESS 0x3912u
#define pcm_effect_4e_ADDRESS 0x391Cu
#define pcm_effect_4e_wait_sample_ADDRESS 0x3930u
#define pcm_effect_4f_ADDRESS 0x393Au
#define pcm_effect_4f_wait_sample_ADDRESS 0x394Eu
#define pcm_effect_50_ADDRESS 0x3958u
#define pcm_effect_50_fade_ADDRESS 0x397Eu
#define pcm_effect_50_wait_sample_ADDRESS 0x399Au
#define pcm_effect_51_ADDRESS 0x39A4u
#define pcm_effect_51_wait_sample_ADDRESS 0x39BEu
#define pcm_effect_52_ADDRESS 0x39C8u
#define pcm_effect_52_delay_ADDRESS 0x39E6u
#define pcm_effect_52_hold_ADDRESS 0x39F7u
#define pcm_effect_53_ADDRESS 0x3A01u
#define pcm_effect_53_wait_sample_ADDRESS 0x3A15u
#define pcm_effect_54_ADDRESS 0x3A1Fu
#define pcm_effect_54_modulate_ADDRESS 0x3A3Au
#define pcm_effect_54_wait_sample_ADDRESS 0x3A57u
#define pcm_effect_55_ADDRESS 0x3A61u
#define pcm_effect_55_wait_sample_ADDRESS 0x3A7Bu
#define pcm_effect_56_ADDRESS 0x3A85u
#define pcm_effect_56_retrigger_ADDRESS 0x3AA4u
#define pcm_effect_56_retrigger_2_ADDRESS 0x3ABEu
#define pcm_effect_56_wait_sample_ADDRESS 0x3AD8u
#define pcm_effect_57_ADDRESS 0x3AE5u
#define pcm_effect_57_retrigger_ADDRESS 0x3B08u
#define pcm_effect_57_note_ADDRESS 0x3B2Au
#define pcm_effect_57_wait_sample_ADDRESS 0x3B48u
#define pcm_effect_58_ADDRESS 0x3B62u
#define pcm_effect_58_retrigger_ADDRESS 0x3B80u
#define pcm_effect_59_ADDRESS 0x3B93u
#define pcm_effect_59_wait_sample_ADDRESS 0x3BA7u
#define pcm_effect_5a_ADDRESS 0x3BB1u
#define pcm_effect_5a_wait_sample_ADDRESS 0x3BC5u
#define pcm_effect_5b_ADDRESS 0x3BCFu
#define pcm_effect_5b_wait_sample_ADDRESS 0x3BE6u
#define pcm_effect_5c_ADDRESS 0x3BF0u
#define pcm_effect_5c_delay_ADDRESS 0x3C0Eu
#define pcm_effect_5c_hold_ADDRESS 0x3C1Fu
#define pcm_effect_5d_ADDRESS 0x3C29u
#define pcm_effect_5d_delay_ADDRESS 0x3C41u
#define pcm_effect_5d_hold_ADDRESS 0x3C52u
#define pcm_effect_5e_ADDRESS 0x3C5Cu
#define pcm_effect_5e_wait_sample_ADDRESS 0x3C70u
#define pcm_effect_5f_ADDRESS 0x3C7Au
#define pcm_effect_5f_wait_sample_ADDRESS 0x3C8Eu
#define pcm_effect_60_ADDRESS 0x3C98u
#define pcm_effect_60_wait_sample_ADDRESS 0x3CACu
#define pcm_effect_61_ADDRESS 0x3CB6u
#define pcm_effect_61_wait_sample_ADDRESS 0x3CCAu
#define pcm_effect_62_ADDRESS 0x3CD4u
#define pcm_effect_62_wait_sample_ADDRESS 0x3CE8u
#define pcm_effect_63_ADDRESS 0x3CF2u
#define pcm_effect_63_wait_sample_ADDRESS 0x3D06u
#define pcm_effect_64_ADDRESS 0x3D10u
#define pcm_effect_64_wait_sample_ADDRESS 0x3D24u
#define pcm_effect_65_ADDRESS 0x3D2Eu
#define pcm_effect_65_wait_sample_ADDRESS 0x3D42u
#define pcm_effect_66_ADDRESS 0x3D4Cu
#define pcm_effect_66_wait_sample_ADDRESS 0x3D60u
#define pcm_effect_67_ADDRESS 0x3D6Au
#define pcm_effect_67_wait_sample_ADDRESS 0x3D7Eu
#define pcm_effect_68_ADDRESS 0x3D88u
#define pcm_effect_68_wait_sample_ADDRESS 0x3D9Cu
#define pcm_effect_69_ADDRESS 0x3DA6u
#define pcm_effect_69_wait_sample_ADDRESS 0x3DBAu
#define pcm_effect_6a_ADDRESS 0x3DC4u
#define pcm_effect_6a_wait_sample_ADDRESS 0x3DD8u
#define pcm_effect_6b_ADDRESS 0x3DE2u
#define pcm_effect_6b_wait_sample_ADDRESS 0x3DF6u
#define pcm_effect_6c_ADDRESS 0x3E00u
#define pcm_effect_6c_wait_sample_ADDRESS 0x3E14u
#define pcm_effect_6d_ADDRESS 0x3E1Eu
#define pcm_effect_6d_wait_sample_ADDRESS 0x3E32u
#define pcm_effect_6e_ADDRESS 0x3E3Cu
#define pcm_effect_6e_wait_sample_ADDRESS 0x3E50u
#define pcm_effect_6f_ADDRESS 0x3E5Au
#define pcm_effect_6f_wait_sample_ADDRESS 0x3E6Eu
#define pcm_effect_70_ADDRESS 0x3E78u
#define pcm_effect_70_wait_sample_ADDRESS 0x3E8Cu
#define pcm_effect_71_ADDRESS 0x3E96u
#define pcm_effect_71_wait_sample_ADDRESS 0x3EAAu
#define pcm_effect_72_ADDRESS 0x3EB4u
#define pcm_effect_72_wait_sample_ADDRESS 0x3EC8u
#define pcm_effect_73_ADDRESS 0x3ED2u
#define pcm_effect_73_wait_sample_ADDRESS 0x3EE6u
#define pcm_effect_74_ADDRESS 0x3EF0u
#define pcm_effect_74_wait_sample_ADDRESS 0x3F04u
#define pcm_effect_75_ADDRESS 0x3F0Eu
#define pcm_effect_75_wait_sample_ADDRESS 0x3F22u
#define pcm_effect_76_ADDRESS 0x3F2Cu
#define pcm_effect_76_wait_sample_ADDRESS 0x3F40u
#define pcm_effect_77_ADDRESS 0x3F4Au
#define pcm_effect_77_delay_ADDRESS 0x3F62u
#define pcm_effect_77_hold_ADDRESS 0x3F73u
#define pcm_effect_78_ADDRESS 0x3F7Au
#define pcm_effect_79_ADDRESS 0x3F80u
#define pcm_effect_79_wait_sample_ADDRESS 0x3F94u
#define pcm_effect_7a_ADDRESS 0x3F9Eu
#define pcm_effect_7a_retrigger_ADDRESS 0x3FBEu
#define pcm_effect_7a_retrigger_2_ADDRESS 0x3FE6u
#define pcm_effect_7a_retrigger_3_ADDRESS 0x4007u
#define pcm_effect_7b_ADDRESS 0x4031u
#define pcm_effect_7b_wait_sample_ADDRESS 0x4045u
#define pcm_effect_7c_ADDRESS 0x404Fu
#define pcm_effect_7c_retrigger_ADDRESS 0x406Fu
#define pcm_effect_7c_retrigger_2_ADDRESS 0x4097u
#define pcm_effect_7c_retrigger_3_ADDRESS 0x40B8u
#define pcm_effect_7d_ADDRESS 0x40E2u
#define pcm_effect_7d_wait_sample_ADDRESS 0x40F6u
#define pcm_effect_7e_ADDRESS 0x4100u
#define pcm_effect_7e_retrigger_ADDRESS 0x411Du
#define pcm_effect_7e_retrigger_2_ADDRESS 0x413Eu
#define pcm_effect_7f_ADDRESS 0x4176u
#define pcm_effect_7f_retrigger_ADDRESS 0x4188u
#define music_pitch_envelope_1_ADDRESS 0x436Au
#define music_pitch_envelope_2_ADDRESS 0x43A7u
#define music_pitch_envelope_3_ADDRESS 0x43E4u
#define music_pitch_envelope_4_ADDRESS 0x4421u
#define music_note_tick_ADDRESS 0x4458u
#define fm_drum_1_1_ADDRESS 0x49C5u
#define fm_drum_1_1_slide_ADDRESS 0x49E4u
#define fm_drum_1_2_ADDRESS 0x4A18u
#define fm_drum_1_2_hold_ADDRESS 0x4A31u
#define fm_drum_1_3_ADDRESS 0x4A51u
#define fm_drum_1_3_hold_ADDRESS 0x4A6Au
#define fm_drum_1_4_ADDRESS 0x4A8Au
#define fm_drum_1_4_hold_ADDRESS 0x4AA3u
#define fm_drum_1_5_ADDRESS 0x4AC3u
#define fm_drum_1_5_slide_ADDRESS 0x4AE7u
#define fm_drum_1_6_ADDRESS 0x4B26u
#define fm_drum_1_6_slide_ADDRESS 0x4B4Au
#define fm_drum_1_7_ADDRESS 0x4B89u
#define fm_drum_1_7_slide_ADDRESS 0x4BADu
#define fm_drum_1_8_ADDRESS 0x4BECu
#define fm_drum_1_8_slide_ADDRESS 0x4C10u
#define fm_drum_1_9_ADDRESS 0x4C36u
#define fm_drum_2_1_ADDRESS 0x4C52u
#define fm_drum_2_1_slide_ADDRESS 0x4C75u
#define fm_drum_2_2_ADDRESS 0x4CB1u
#define fm_drum_2_2_slide_ADDRESS 0x4CD4u
#define fm_drum_2_3_ADDRESS 0x4D10u
#define fm_drum_2_3_slide_ADDRESS 0x4D2Fu
#define fm_drum_2_4_ADDRESS 0x4D62u
#define fm_drum_2_4_slide_ADDRESS 0x4D8Du
#define fm_drum_2_5_ADDRESS 0x4E27u
#define fm_drum_2_5_slide_ADDRESS 0x4E4Au
#define fm_drum_2_6_ADDRESS 0x4E6Bu
#define pcm_drum_1_1_ADDRESS 0x4FD1u
#define pcm_drum_1_2_ADDRESS 0x4FE5u
#define pcm_drum_1_3_ADDRESS 0x4FF9u
#define pcm_drum_1_4_ADDRESS 0x5013u
#define pcm_drum_1_5_ADDRESS 0x502Du
#define pcm_drum_1_6_ADDRESS 0x5047u
#define pcm_drum_1_7_ADDRESS 0x5061u
#define pcm_drum_1_8_ADDRESS 0x5075u
#define pcm_drum_1_9_ADDRESS 0x5089u
#define pcm_drum_1_a_ADDRESS 0x509Du
#define pcm_drum_1_b_ADDRESS 0x50B7u
#define pcm_drum_1_b_note_ADDRESS 0x50CBu
#define pcm_drum_1_b_note_2_ADDRESS 0x50DEu
#define pcm_drum_1_c_ADDRESS 0x50F7u
#define pcm_drum_1_c_note_ADDRESS 0x5101u
#define pcm_drum_1_c_note_2_ADDRESS 0x5119u
#define pcm_drum_1_c_note_3_ADDRESS 0x512Cu
#define pcm_drum_1_d_ADDRESS 0x513Cu
#define pcm_drum_1_f_ADDRESS 0x5142u
#define pcm_drum_2_1_ADDRESS 0x5156u
#define pcm_drum_2_2_ADDRESS 0x516Au
#define pcm_drum_2_3_ADDRESS 0x517Eu
#define pcm_drum_2_4_ADDRESS 0x5198u
#define pcm_drum_2_5_ADDRESS 0x51B2u
#define pcm_drum_2_6_ADDRESS 0x51CCu
#define pcm_drum_2_7_ADDRESS 0x51E6u
#define pcm_drum_2_8_ADDRESS 0x51FAu
#define pcm_drum_2_9_ADDRESS 0x520Eu
#define pcm_drum_2_a_ADDRESS 0x5222u
#define pcm_drum_2_b_ADDRESS 0x5236u
#define pcm_drum_2_c_ADDRESS 0x524Au
#define pcm_drum_2_d_ADDRESS 0x525Eu
#define pcm_drum_2_e_ADDRESS 0x5272u
#define pcm_drum_2_f_ADDRESS 0x5286u
#define pcm_drum_3_1_ADDRESS 0x529Au
#define pcm_drum_3_2_ADDRESS 0x52AEu
#define pcm_drum_3_3_ADDRESS 0x52C2u
#define pcm_drum_3_4_ADDRESS 0x52DCu
#define pcm_drum_3_5_ADDRESS 0x52F6u
#define pcm_drum_3_6_ADDRESS 0x5310u
#define pcm_drum_3_7_ADDRESS 0x532Au
#define pcm_drum_3_8_ADDRESS 0x533Eu
#define pcm_drum_3_9_ADDRESS 0x5352u
#define pcm_drum_3_a_ADDRESS 0x5366u
#define pcm_drum_3_b_ADDRESS 0x537Au
#define pcm_drum_3_c_ADDRESS 0x538Eu
#define pcm_drum_3_d_ADDRESS 0x53A2u
#define pcm_drum_3_e_ADDRESS 0x53B6u
#define pcm_drum_3_f_ADDRESS 0x53CAu
#define pcm_drum_4_1_ADDRESS 0x53DEu
#define pcm_drum_4_2_ADDRESS 0x53F2u
#define pcm_drum_4_3_ADDRESS 0x5406u
#define pcm_drum_4_4_ADDRESS 0x541Au
#define pcm_drum_4_5_ADDRESS 0x5434u
#define pcm_drum_4_6_ADDRESS 0x544Eu
#define pcm_drum_4_7_ADDRESS 0x5468u
#define pcm_drum_4_8_ADDRESS 0x547Cu
#define pcm_drum_4_9_ADDRESS 0x5490u
#define pcm_drum_4_a_ADDRESS 0x54A4u
#define pcm_drum_4_b_ADDRESS 0x54B8u
#define pcm_drum_4_c_ADDRESS 0x54CCu
#define pcm_drum_4_d_ADDRESS 0x54E0u
#define pcm_drum_4_e_ADDRESS 0x54F4u
#define pcm_drum_4_f_ADDRESS 0x5508u
#define pcm_drum_5_1_ADDRESS 0x551Cu
#define pcm_drum_5_2_ADDRESS 0x5530u
#define pcm_drum_5_3_ADDRESS 0x5544u
#define pcm_drum_5_4_ADDRESS 0x555Eu
#define pcm_drum_5_5_ADDRESS 0x5578u
#define pcm_drum_5_6_ADDRESS 0x5592u
#define pcm_drum_5_7_ADDRESS 0x55ACu
#define pcm_drum_5_8_ADDRESS 0x55C0u
#define pcm_drum_5_9_ADDRESS 0x55D4u
#define pcm_drum_5_a_ADDRESS 0x55E8u
#define pcm_drum_5_b_ADDRESS 0x55FCu
#define pcm_drum_5_c_ADDRESS 0x5610u
#define pcm_drum_5_d_ADDRESS 0x5624u
#define pcm_drum_5_e_ADDRESS 0x5638u
#define pcm_drum_5_f_ADDRESS 0x564Cu
#define pcm_drum_6_1_ADDRESS 0x5660u
#define pcm_drum_6_2_ADDRESS 0x5674u
#define pcm_drum_6_3_ADDRESS 0x5688u
#define pcm_drum_6_4_ADDRESS 0x56A2u
#define pcm_drum_6_5_ADDRESS 0x56BCu
#define pcm_drum_6_6_ADDRESS 0x56D6u
#define pcm_drum_6_7_ADDRESS 0x56F0u
#define pcm_drum_6_8_ADDRESS 0x5704u
#define pcm_drum_6_9_ADDRESS 0x5718u
#define pcm_drum_6_a_ADDRESS 0x572Cu
#define pcm_drum_6_b_ADDRESS 0x5740u
#define pcm_drum_6_c_ADDRESS 0x5754u
#define pcm_drum_6_d_ADDRESS 0x5768u
#define pcm_drum_6_e_ADDRESS 0x577Cu
#define pcm_drum_6_f_ADDRESS 0x5790u
#define pcm_drum_7_1_ADDRESS 0x57A4u
#define pcm_drum_7_2_ADDRESS 0x57B8u
#define pcm_drum_7_3_ADDRESS 0x57CCu
#define pcm_drum_7_4_ADDRESS 0x57E0u
#define pcm_drum_7_5_ADDRESS 0x57FAu
#define pcm_drum_7_6_ADDRESS 0x5814u
#define pcm_drum_7_7_ADDRESS 0x582Eu
#define pcm_drum_7_8_ADDRESS 0x5842u
#define pcm_drum_7_9_ADDRESS 0x5856u
#define pcm_drum_7_a_ADDRESS 0x586Au
#define pcm_drum_7_b_ADDRESS 0x587Eu
#define pcm_drum_7_c_ADDRESS 0x5892u
#define pcm_drum_7_d_ADDRESS 0x58A6u
#define pcm_drum_7_e_ADDRESS 0x58BAu
#define pcm_drum_7_f_ADDRESS 0x58CEu
#define pcm_drum_8_1_ADDRESS 0x58E2u
#define pcm_drum_8_2_ADDRESS 0x58F6u
#define pcm_drum_8_3_ADDRESS 0x590Au
#define pcm_drum_8_4_ADDRESS 0x5924u
#define pcm_drum_8_5_ADDRESS 0x593Eu
#define pcm_drum_8_6_ADDRESS 0x5958u
#define pcm_drum_8_7_ADDRESS 0x5972u
#define pcm_drum_8_8_ADDRESS 0x5986u
#define pcm_drum_8_9_ADDRESS 0x599Au
#define pcm_drum_8_a_ADDRESS 0x59AEu
#define pcm_drum_8_b_ADDRESS 0x59C2u
#define pcm_drum_8_c_ADDRESS 0x59D6u
#define pcm_drum_8_d_ADDRESS 0x59EAu
#define pcm_drum_8_e_ADDRESS 0x59FEu
#define pcm_drum_8_f_ADDRESS 0x5A12u
#define pcm_drum_9_1_ADDRESS 0x5A26u
#define pcm_drum_9_2_ADDRESS 0x5A3Au
#define pcm_drum_9_3_ADDRESS 0x5A4Eu
#define pcm_drum_9_4_ADDRESS 0x5A62u
#define pcm_drum_9_5_ADDRESS 0x5A76u
#define pcm_drum_9_6_ADDRESS 0x5A8Au
#define pcm_drum_9_7_ADDRESS 0x5A9Eu
#define pcm_drum_9_8_ADDRESS 0x5AB2u
#define pcm_drum_9_9_ADDRESS 0x5AC6u
#define pcm_drum_9_a_ADDRESS 0x5ADAu
#define pcm_drum_9_b_ADDRESS 0x5AEEu
#define pcm_drum_9_c_ADDRESS 0x5B02u
#define pcm_drum_9_d_ADDRESS 0x5B16u
#define pcm_drum_9_e_ADDRESS 0x5B27u
#define pcm_drum_a_1_ADDRESS 0x5B2Du
#define pcm_drum_a_2_ADDRESS 0x5B41u
#define pcm_drum_a_3_ADDRESS 0x5B55u
#define pcm_drum_a_4_ADDRESS 0x5B6Fu
#define pcm_drum_a_5_ADDRESS 0x5B89u
#define pcm_drum_a_6_ADDRESS 0x5BA3u
#define pcm_drum_a_7_ADDRESS 0x5BBDu
#define pcm_drum_a_8_ADDRESS 0x5BD1u
#define pcm_drum_a_9_ADDRESS 0x5BE5u
#define pcm_drum_a_a_ADDRESS 0x5BF9u
#define pcm_drum_a_b_ADDRESS 0x5C0Du
#define pcm_drum_a_c_ADDRESS 0x5C21u
#define pcm_drum_a_d_ADDRESS 0x5C35u
#define pcm_drum_a_e_ADDRESS 0x5C49u
#define pcm_drum_a_f_ADDRESS 0x5C5Du
#define pcm_drum_b_1_ADDRESS 0x5C71u
#define pcm_drum_b_2_ADDRESS 0x5C85u
#define pcm_drum_b_3_ADDRESS 0x5C99u
#define pcm_drum_b_4_ADDRESS 0x5CB3u
#define pcm_drum_b_5_ADDRESS 0x5CCDu
#define pcm_drum_b_6_ADDRESS 0x5CE7u
#define pcm_drum_b_7_ADDRESS 0x5D01u
#define pcm_drum_b_8_ADDRESS 0x5D15u
#define pcm_drum_b_9_ADDRESS 0x5D29u
#define pcm_drum_b_a_ADDRESS 0x5D3Du
#define pcm_drum_b_b_ADDRESS 0x5D51u
#define pcm_drum_b_c_ADDRESS 0x5D65u
#define pcm_drum_b_d_ADDRESS 0x5D79u
#define pcm_drum_b_e_ADDRESS 0x5D8Du
#define pcm_drum_b_f_ADDRESS 0x5DA1u

/* the sound program's structures in the shared RAM */
#pragma pack(push, 1)
struct fm_patch
{
	uint8_t algorithm;
	uint8_t pad_01[0x18];
};

struct pcm_patch
{
	uint8_t sample;
	uint8_t unk_01;
	uint8_t unk_02;
};

struct sample
{
	uint8_t registers[0x7];
	uint8_t flags;
};

#pragma pack(pop)

_Static_assert(sizeof(struct fm_patch) == 0x19, "struct fm_patch has the size of the program ROM's records");
_Static_assert(sizeof(struct pcm_patch) == 0x3, "struct pcm_patch has the size of the program ROM's records");
_Static_assert(sizeof(struct sample) == 0x8, "struct sample has the size of the program ROM's records");

#define FM_PATCH(address) ((const struct fm_patch *)sound_rom_at(address))
#define PCM_PATCH(address) ((const struct pcm_patch *)sound_rom_at(address))
#define SAMPLE(address) ((const struct sample *)sound_rom_at(address))

/* chips.c: the records' handlers and the chips: the YM2151's registers, patches, volumes, pitches, keys, LFO and pan; the K053260's voices */
void stop_channel(uint16_t ix);
void set_channel_handler(uint16_t hl, uint16_t ix);
void channel_idle(void);
void write_fm_channel_register(uint16_t bc, uint16_t ix);
void write_fm_register(uint16_t bc);
void restart_frame_timer(void);
void load_patch(uint16_t hl, uint16_t ix);
void set_volume(uint16_t ix, uint8_t a);
void update_volume(uint16_t ix);
uint16_t write_operator_level(uint16_t bc, uint16_t hl, uint16_t ix, uint8_t a);
void set_pitch(uint16_t hl, uint16_t ix);
void key_on(uint16_t ix);
void key_off(uint16_t ix);
void fast_release(uint16_t ix);
void unused_0F06(uint16_t ix);
void set_lfo_pm_depth(uint8_t a);
void set_lfo_am_depth(uint8_t a);
void set_channel_pm_sensitivity(uint16_t ix, uint8_t a);
void set_channel_am_sensitivity(uint16_t ix, uint8_t a);
void set_lfo_frequency(uint8_t a);
void set_lfo_waveform(uint8_t a);
void set_pan(uint16_t ix, uint8_t a);
void noise_off(uint16_t ix);
void unused_0FF2(uint16_t ix, uint8_t a);
uint32_t pcm_voice_playing(uint16_t ix);
void unused_100D(void);

/* drums.c: the drum routines: a music note's low nibble on a channel with a drum kit (+12) runs one */
void fm_drum_1_1(uint16_t ix);
void fm_drum_1_1_slide(uint16_t ix);
void fm_drum_1_2(uint16_t ix);
void fm_drum_1_2_hold(uint16_t ix);
void fm_drum_1_3(uint16_t ix);
void fm_drum_1_3_hold(uint16_t ix);
void fm_drum_1_4(uint16_t ix);
void fm_drum_1_4_hold(uint16_t ix);
void fm_drum_1_5(uint16_t ix);
void fm_drum_1_5_slide(uint16_t ix);
void fm_drum_1_6(uint16_t ix);
void fm_drum_1_6_slide(uint16_t ix);
void fm_drum_1_7(uint16_t ix);
void fm_drum_1_7_slide(uint16_t ix);
void fm_drum_1_8(uint16_t ix);
void fm_drum_1_8_slide(uint16_t ix);
void fm_drum_1_9(uint16_t ix);
void fm_drum_2_1(uint16_t ix);
void fm_drum_2_1_setup(uint16_t ix);
void fm_drum_2_1_retrigger(uint16_t ix);
void fm_drum_2_1_slide(uint16_t ix);
void fm_drum_2_2(uint16_t ix);
void fm_drum_2_2_setup(uint16_t ix);
void fm_drum_2_2_retrigger(uint16_t ix);
void fm_drum_2_2_slide(uint16_t ix);
void fm_drum_2_3(uint16_t ix);
void fm_drum_2_3_retrigger(uint16_t ix);
void fm_drum_2_3_slide(uint16_t ix);
void fm_drum_2_4(uint16_t ix);
void fm_drum_2_4_retrigger(uint16_t ix);
void fm_drum_2_4_slide(uint16_t ix);
void fm_drum_2_4_update(uint16_t ix);
void fm_drum_2_4_update_2(uint16_t ix);
void fm_drum_2_4_transpose(uint16_t ix);
void fm_drum_2_4_update_3(uint16_t ix);
uint8_t fm_drum_2_4_update_4(uint16_t ix);
void fm_drum_2_5(uint16_t ix);
void fm_drum_2_5_retrigger(uint16_t ix);
void fm_drum_2_5_slide(uint16_t ix);
void fm_drum_2_6(uint16_t ix);
void pcm_drum_1_1(uint16_t ix);
void pcm_drum_1_2(uint16_t ix);
void pcm_drum_1_3(uint16_t ix);
void pcm_drum_1_4(uint16_t ix);
void pcm_drum_1_5(uint16_t ix);
void pcm_drum_1_6(uint16_t ix);
void pcm_drum_1_7(uint16_t ix);
void pcm_drum_1_8(uint16_t ix);
void pcm_drum_1_9(uint16_t ix);
void pcm_drum_1_a(uint16_t ix);
void pcm_drum_1_b(uint16_t ix);
void pcm_drum_1_b_note(uint16_t ix);
void pcm_drum_1_b_note_2(uint16_t ix);
void pcm_drum_1_c(uint16_t ix);
void pcm_drum_1_c_note(uint16_t ix);
void pcm_drum_1_c_note_2(uint16_t ix);
void pcm_drum_1_c_note_3(uint16_t ix);
void pcm_drum_1_d(uint16_t ix);
void pcm_drum_1_f(uint16_t ix);
void pcm_drum_2_1(uint16_t ix);
void pcm_drum_2_2(uint16_t ix);
void pcm_drum_2_3(uint16_t ix);
void pcm_drum_2_4(uint16_t ix);
void pcm_drum_2_5(uint16_t ix);
void pcm_drum_2_6(uint16_t ix);
void pcm_drum_2_7(uint16_t ix);
void pcm_drum_2_8(uint16_t ix);
void pcm_drum_2_9(uint16_t ix);
void pcm_drum_2_a(uint16_t ix);
void pcm_drum_2_b(uint16_t ix);
void pcm_drum_2_c(uint16_t ix);
void pcm_drum_2_d(uint16_t ix);
void pcm_drum_2_e(uint16_t ix);
void pcm_drum_2_f(uint16_t ix);
void pcm_drum_3_1(uint16_t ix);
void pcm_drum_3_2(uint16_t ix);
void pcm_drum_3_3(uint16_t ix);
void pcm_drum_3_4(uint16_t ix);
void pcm_drum_3_5(uint16_t ix);
void pcm_drum_3_6(uint16_t ix);
void pcm_drum_3_7(uint16_t ix);
void pcm_drum_3_8(uint16_t ix);
void pcm_drum_3_9(uint16_t ix);
void pcm_drum_3_a(uint16_t ix);
void pcm_drum_3_b(uint16_t ix);
void pcm_drum_3_c(uint16_t ix);
void pcm_drum_3_d(uint16_t ix);
void pcm_drum_3_e(uint16_t ix);
void pcm_drum_3_f(uint16_t ix);
void pcm_drum_4_1(uint16_t ix);
void pcm_drum_4_2(uint16_t ix);
void pcm_drum_4_3(uint16_t ix);
void pcm_drum_4_4(uint16_t ix);
void pcm_drum_4_5(uint16_t ix);
void pcm_drum_4_6(uint16_t ix);
void pcm_drum_4_7(uint16_t ix);
void pcm_drum_4_8(uint16_t ix);
void pcm_drum_4_9(uint16_t ix);
void pcm_drum_4_a(uint16_t ix);
void pcm_drum_4_b(uint16_t ix);
void pcm_drum_4_c(uint16_t ix);
void pcm_drum_4_d(uint16_t ix);
void pcm_drum_4_e(uint16_t ix);
void pcm_drum_4_f(uint16_t ix);
void pcm_drum_5_1(uint16_t ix);
void pcm_drum_5_2(uint16_t ix);
void pcm_drum_5_3(uint16_t ix);
void pcm_drum_5_4(uint16_t ix);
void pcm_drum_5_5(uint16_t ix);
void pcm_drum_5_6(uint16_t ix);
void pcm_drum_5_7(uint16_t ix);
void pcm_drum_5_8(uint16_t ix);
void pcm_drum_5_9(uint16_t ix);
void pcm_drum_5_a(uint16_t ix);
void pcm_drum_5_b(uint16_t ix);
void pcm_drum_5_c(uint16_t ix);
void pcm_drum_5_d(uint16_t ix);
void pcm_drum_5_e(uint16_t ix);
void pcm_drum_5_f(uint16_t ix);
void pcm_drum_6_1(uint16_t ix);
void pcm_drum_6_2(uint16_t ix);
void pcm_drum_6_3(uint16_t ix);
void pcm_drum_6_4(uint16_t ix);
void pcm_drum_6_5(uint16_t ix);
void pcm_drum_6_6(uint16_t ix);
void pcm_drum_6_7(uint16_t ix);
void pcm_drum_6_8(uint16_t ix);
void pcm_drum_6_9(uint16_t ix);
void pcm_drum_6_a(uint16_t ix);
void pcm_drum_6_b(uint16_t ix);
void pcm_drum_6_c(uint16_t ix);
void pcm_drum_6_d(uint16_t ix);
void pcm_drum_6_e(uint16_t ix);
void pcm_drum_6_f(uint16_t ix);
void pcm_drum_7_1(uint16_t ix);
void pcm_drum_7_2(uint16_t ix);
void pcm_drum_7_3(uint16_t ix);
void pcm_drum_7_4(uint16_t ix);
void pcm_drum_7_5(uint16_t ix);
void pcm_drum_7_6(uint16_t ix);
void pcm_drum_7_7(uint16_t ix);
void pcm_drum_7_8(uint16_t ix);
void pcm_drum_7_9(uint16_t ix);
void pcm_drum_7_a(uint16_t ix);
void pcm_drum_7_b(uint16_t ix);
void pcm_drum_7_c(uint16_t ix);
void pcm_drum_7_d(uint16_t ix);
void pcm_drum_7_e(uint16_t ix);
void pcm_drum_7_f(uint16_t ix);
void pcm_drum_8_1(uint16_t ix);
void pcm_drum_8_2(uint16_t ix);
void pcm_drum_8_3(uint16_t ix);
void pcm_drum_8_4(uint16_t ix);
void pcm_drum_8_5(uint16_t ix);
void pcm_drum_8_6(uint16_t ix);
void pcm_drum_8_7(uint16_t ix);
void pcm_drum_8_8(uint16_t ix);
void pcm_drum_8_9(uint16_t ix);
void pcm_drum_8_a(uint16_t ix);
void pcm_drum_8_b(uint16_t ix);
void pcm_drum_8_c(uint16_t ix);
void pcm_drum_8_d(uint16_t ix);
void pcm_drum_8_e(uint16_t ix);
void pcm_drum_8_f(uint16_t ix);
void pcm_drum_9_1(uint16_t ix);
void pcm_drum_9_2(uint16_t ix);
void pcm_drum_9_3(uint16_t ix);
void pcm_drum_9_4(uint16_t ix);
void pcm_drum_9_5(uint16_t ix);
void pcm_drum_9_6(uint16_t ix);
void pcm_drum_9_7(uint16_t ix);
void pcm_drum_9_8(uint16_t ix);
void pcm_drum_9_9(uint16_t ix);
void pcm_drum_9_a(uint16_t ix);
void pcm_drum_9_b(uint16_t ix);
void pcm_drum_9_c(uint16_t ix);
void pcm_drum_9_d(uint16_t ix);
void pcm_drum_9_e(uint16_t ix);
void pcm_drum_a_1(uint16_t ix);
void pcm_drum_a_2(uint16_t ix);
void pcm_drum_a_3(uint16_t ix);
void pcm_drum_a_4(uint16_t ix);
void pcm_drum_a_5(uint16_t ix);
void pcm_drum_a_6(uint16_t ix);
void pcm_drum_a_7(uint16_t ix);
void pcm_drum_a_8(uint16_t ix);
void pcm_drum_a_9(uint16_t ix);
void pcm_drum_a_a(uint16_t ix);
void pcm_drum_a_b(uint16_t ix);
void pcm_drum_a_c(uint16_t ix);
void pcm_drum_a_d(uint16_t ix);
void pcm_drum_a_e(uint16_t ix);
void pcm_drum_a_f(uint16_t ix);
void pcm_drum_b_1(uint16_t ix);
void pcm_drum_b_2(uint16_t ix);
void pcm_drum_b_3(uint16_t ix);
void pcm_drum_b_4(uint16_t ix);
void pcm_drum_b_5(uint16_t ix);
void pcm_drum_b_6(uint16_t ix);
void pcm_drum_b_7(uint16_t ix);
void pcm_drum_b_8(uint16_t ix);
void pcm_drum_b_9(uint16_t ix);
void pcm_drum_b_a(uint16_t ix);
void pcm_drum_b_b(uint16_t ix);
void pcm_drum_b_c(uint16_t ix);
void pcm_drum_b_d(uint16_t ix);
void pcm_drum_b_e(uint16_t ix);
void pcm_drum_b_f(uint16_t ix);

/* fm_effects.c: the FM effects (commands 01-38), each a chain of handlers its record runs one pass at a time */
void fm_effect_02(uint16_t ix);
void fm_effect_02_delay(uint16_t ix);
void fm_effect_01(uint16_t ix);
void fm_effect_01_retrigger(uint16_t ix);
void fm_effect_01_pitch(uint16_t ix);
uint32_t fm_effect_01_move_pitch(uint16_t de, uint16_t ix);
void fm_effect_04(uint16_t ix);
void fm_effect_04_delay(uint16_t ix);
void fm_effect_03(uint16_t ix);
void fm_effect_03_pitch(uint16_t ix);
void fm_effect_03_move_pitch(uint16_t de, uint16_t ix);
void fm_effect_06(uint16_t ix);
void fm_effect_06_delay(uint16_t ix);
void fm_effect_05(uint16_t ix);
void fm_effect_05_note(uint16_t ix);
void fm_effect_05_retrigger(uint16_t ix);
void fm_effect_05_slide(uint16_t ix);
void fm_effect_07(uint16_t ix);
void fm_effect_07_slide(uint16_t ix);
void fm_effect_09(uint16_t ix);
void fm_effect_09_delay(uint16_t ix);
void fm_effect_08(uint16_t ix);
void fm_effect_08_retrigger(uint16_t ix);
void fm_effect_08_hold(uint16_t ix);
void fm_effect_0d(uint16_t ix);
void fm_effect_0d_delay(uint16_t ix);
void fm_effect_0c(uint16_t ix);
void fm_effect_0c_retrigger(uint16_t ix);
void fm_effect_0c_retrigger_2(uint16_t ix);
void fm_effect_0c_hold(uint16_t ix);
void fm_effect_0c_move_pitch(uint16_t de, uint16_t ix);
void fm_effect_0e(uint16_t ix);
void fm_effect_0e_pitch(uint16_t ix);
void fm_effect_0e_pitch_2(uint16_t ix);
void fm_effect_0e_slide(uint16_t ix);
void fm_effect_0e_pitch_3(uint16_t ix);
uint32_t fm_effect_0e_move_pitch(uint16_t de, uint16_t ix);
void fm_effect_0f(uint16_t ix);
void fm_effect_0f_slide(uint16_t ix);
void fm_effect_10(uint16_t ix);
void fm_effect_10_slide(uint16_t ix);
void fm_effect_11(uint16_t ix);
void fm_effect_11_pitch(uint16_t ix);
void fm_effect_11_move_pitch(uint16_t de, uint16_t ix);
void fm_effect_12(uint16_t ix);
void fm_effect_12_delay(uint16_t ix);
void fm_effect_12_slide(uint16_t ix);
void fm_effect_13(uint16_t ix);
void fm_effect_13_slide(uint16_t ix);
void fm_effect_13_slide_2(uint16_t ix);
void fm_effect_13_slide_3(uint16_t ix);
void fm_effect_14(uint16_t ix);
void fm_effect_14_slide(uint16_t ix);
void fm_effect_14_slide_2(uint16_t ix);
void fm_effect_15(uint16_t ix);
void fm_effect_15_note(uint16_t ix);
void fm_effect_15_slide(uint16_t ix);
void fm_effect_17(uint16_t ix);
void fm_effect_17_delay(uint16_t ix);
void fm_effect_16(uint16_t ix);
void fm_effect_16_pitch(uint16_t ix);
void fm_effect_16_move_pitch(uint16_t de, uint16_t ix);
void fm_effect_18(uint16_t ix);
void fm_effect_18_slide(uint16_t ix);
void fm_effect_19(uint16_t ix);
void fm_effect_19_retrigger(uint16_t ix);
void fm_effect_19_slide(uint16_t ix);
void fm_effect_1a(uint16_t ix);
void fm_effect_1a_retrigger(uint16_t ix);
void fm_effect_1a_slide(uint16_t ix);
void fm_effect_1b(uint16_t ix);
void fm_effect_1b_pitch(uint16_t ix);
void fm_effect_1b_pitch_2(uint16_t ix);
uint32_t fm_effect_1b_move_pitch(uint16_t de, uint16_t ix);
void fm_effect_1c(uint16_t ix);
void fm_effect_1c_pitch(uint16_t ix);
void fm_effect_1c_pitch_2(uint16_t ix);
void fm_effect_1c_slide(uint16_t ix);
void fm_effect_1c_pitch_3(uint16_t ix);
uint32_t fm_effect_1c_move_pitch(uint16_t de, uint16_t ix);
void fm_effect_1d(uint16_t ix);
void fm_effect_1d_pitch(uint16_t ix);
void fm_effect_1d_pitch_2(uint16_t ix);
void fm_effect_1d_pitch_3(uint16_t ix);
uint32_t fm_effect_1d_move_pitch(uint16_t de, uint16_t ix);
void fm_effect_1e(uint16_t ix);
void fm_effect_1e_slide(uint16_t ix);
void fm_effect_1f(uint16_t ix);
void fm_effect_1f_retrigger(uint16_t ix);
void fm_effect_1f_end(uint16_t ix);
void fm_effect_20(uint16_t ix);
void fm_effect_20_pitch(uint16_t ix);
void fm_effect_20_pitch_2(uint16_t ix);
uint32_t fm_effect_20_move_pitch(uint16_t de, uint16_t ix);
void fm_effect_21(uint16_t ix);
void fm_effect_21_end(uint16_t ix);
void fm_effect_22(uint16_t ix);
void fm_effect_22_slide(uint16_t ix);
void fm_effect_23(uint16_t ix);
void fm_effect_23_retrigger(uint16_t ix);
void fm_effect_23_slide(uint16_t ix);
void fm_effect_24(uint16_t ix);
void fm_effect_24_retrigger(uint16_t ix);
void fm_effect_24_hold(uint16_t ix);
void fm_effect_25(uint16_t ix);
void fm_effect_25_note(uint16_t ix);
void fm_effect_25_retrigger(uint16_t ix);
void fm_effect_25_hold(uint16_t ix);
void fm_effect_26(uint16_t ix);
void fm_effect_26_transpose(uint16_t ix);
void fm_effect_26_slide(uint16_t ix);
void fm_effect_26_pitch(uint16_t ix);
uint32_t fm_effect_26_move_pitch(uint16_t ix);
void fm_effect_27(uint16_t ix);
void fm_effect_27_retrigger(uint16_t ix);
void fm_effect_27_hold(uint16_t ix);
void fm_effect_28(uint16_t ix);
void fm_effect_28_slide(uint16_t ix);
void fm_effect_29(uint16_t ix);
void fm_effect_29_pitch(uint16_t ix);
void fm_effect_29_setup(uint16_t ix);
void fm_effect_29_slide(uint16_t ix);
uint32_t fm_effect_29_move_pitch(uint16_t de, uint16_t ix);
void fm_effect_2b(uint16_t ix);
void fm_effect_2b_delay(uint16_t ix);
void fm_effect_2a(uint16_t ix);
void fm_effect_2a_retrigger(uint16_t ix);
void fm_effect_2a_retrigger_2(uint16_t ix);
void fm_effect_2a_hold(uint16_t ix);
void fm_effect_2a_move_pitch(uint16_t de, uint16_t ix);
void fm_effect_2c(uint16_t ix);
void fm_effect_2c_retrigger(uint16_t ix);
void fm_effect_2c_delay(uint16_t ix);
void fm_effect_2c_hold(uint16_t ix);
void fm_effect_2c_transpose(uint16_t de, uint16_t ix);
void fm_effect_2c_setup(uint16_t ix);
void fm_effect_2c_slide(uint16_t hl, uint16_t ix);
void fm_effect_2d(uint16_t ix);
void fm_effect_2d_note(uint16_t ix);
void fm_effect_2d_retrigger(uint16_t ix);
void fm_effect_2d_delay(uint16_t ix);
void fm_effect_2d_hold(uint16_t ix);
void fm_effect_2d_transpose(uint16_t de, uint16_t ix);
void fm_effect_2d_setup(uint16_t ix);
void fm_effect_2d_slide(uint16_t hl, uint16_t ix);
void fm_effect_2e(uint16_t ix);
void fm_effect_2e_note(uint16_t ix);
void fm_effect_2e_retrigger(uint16_t ix);
void fm_effect_2e_delay(uint16_t ix);
void fm_effect_2e_hold(uint16_t ix);
void fm_effect_2e_transpose(uint16_t de, uint16_t ix);
void fm_effect_2e_setup(uint16_t ix);
void fm_effect_2e_slide(uint16_t hl, uint16_t ix);
void fm_effect_2f(uint16_t ix);
void fm_effect_2f_retrigger(uint16_t ix);
void fm_effect_2f_slide(uint16_t ix);
void fm_effect_32(uint16_t ix);
void fm_effect_32_delay(uint16_t ix);
void fm_effect_31(uint16_t ix);
void fm_effect_31_delay(uint16_t ix);
void fm_effect_30(uint16_t ix);
void fm_effect_30_retrigger(uint16_t ix);
void fm_effect_30_retrigger_2(uint16_t ix);
void fm_effect_33(uint16_t ix);
void fm_effect_33_retrigger(uint16_t ix);
void fm_effect_33_retrigger_2(uint16_t ix);
void fm_effect_34(uint16_t ix);
void fm_effect_34_setup(uint16_t ix);
void fm_effect_34_retrigger(uint16_t ix);
void fm_effect_34_slide(uint16_t ix);
void fm_effect_35(uint16_t ix);
void fm_effect_35_note(uint16_t ix);
void fm_effect_35_setup(uint16_t ix);
void fm_effect_35_retrigger(uint16_t ix);
void fm_effect_35_slide(uint16_t ix);
void fm_effect_36(uint16_t ix);
void fm_effect_36_retrigger(uint16_t ix);
void fm_effect_36_slide(uint16_t ix);
void fm_effect_37(uint16_t ix);
void fm_effect_37_retrigger(uint16_t ix);
void fm_effect_37_slide(uint16_t ix);
void fm_effect_38(uint16_t ix);
void fm_effect_38_retrigger(uint16_t ix);
void fm_effect_38_slide(uint16_t ix);

/* main.c: the reset and its self test, the commands from the 053248, the main loop */
uint16_t sound_reset(void);
uint16_t BOARD_ORIGINAL(sound_reset)(void);
void sound_command(void);
void nmi_return(void);
void start_sound(uint8_t a);
uint16_t stop_all_channels(void);
void stop_music(uint16_t *p_ix, uint8_t *p_a);
void stop_channel_unless_kept(uint16_t ix);
void start_song(uint8_t a);
uint16_t start_music_channel(uint16_t hl, uint16_t ix, uint8_t a);
uint16_t check_rom(void);
uint16_t BOARD_ORIGINAL(check_rom)(void);
uint16_t sound_main(void);
void self_test_failed(void);
void sound_main_loop(void);
void run_pcm_channel(uint16_t ix);
void run_channel(uint16_t ix);

/* music.c: the music: a song's tracks, their notes and commands, the pitch envelope, the gate, the fade's volume */
void start_music_track(uint16_t de, uint16_t ix, uint8_t a);
void stop_music_channel(uint16_t ix);
uint32_t music_channel_song(uint16_t ix);
uint16_t music_tick(uint16_t ix);
void music_pitch_envelope_1(uint16_t ix);
void music_pitch_envelope_2(uint16_t ix);
void music_pitch_envelope_3(uint16_t ix);
void music_pitch_envelope_4(uint16_t ix);
void music_note_tick(uint16_t ix);
uint32_t add_note_length(uint8_t bc, uint16_t ix);
void set_note_gate(uint16_t ix);
void update_music_volume(uint16_t ix);
void set_music_volume(uint16_t ix, uint8_t a);
uint8_t next_track_byte(uint16_t ix);
void drum_done(uint16_t ix);

/* pcm_effects.c: the PCM effects (commands 40-7E, and 3F by its argument): samples of the K053260 */
void pcm_effect_3f_00(uint16_t ix);
void pcm_effect_3f_00_wait_sample(uint16_t ix);
void pcm_effect_3f_01(uint16_t ix);
void pcm_effect_3f_01_wait_sample(uint16_t ix);
void pcm_effect_3f_02(uint16_t ix);
void pcm_effect_3f_02_wait_sample(uint16_t ix);
void pcm_effect_3f_03(uint16_t ix);
void pcm_effect_3f_03_wait_sample(uint16_t ix);
void pcm_effect_3f_04(uint16_t ix);
void pcm_effect_3f_04_wait_sample(uint16_t ix);
void pcm_effect_3f_05(uint16_t ix);
void pcm_effect_3f_05_wait_sample(uint16_t ix);
void pcm_effect_3f_06(uint16_t ix);
void pcm_effect_3f_06_wait_sample(uint16_t ix);
void pcm_effect_3f_07(uint16_t ix);
void pcm_effect_3f_07_wait_sample(uint16_t ix);
void pcm_effect_3f_08(uint16_t ix);
void pcm_effect_3f_08_wait_sample(uint16_t ix);
void pcm_effect_3f_09(uint16_t ix);
void pcm_effect_3f_09_wait_sample(uint16_t ix);
void pcm_effect_3f_0a(uint16_t ix);
void pcm_effect_3f_0a_wait_sample(uint16_t ix);
void pcm_effect_3f_0b(uint16_t ix);
void pcm_effect_3f_0b_wait_sample(uint16_t ix);
void pcm_effect_3f_0c(uint16_t ix);
void pcm_effect_3f_0c_wait_sample(uint16_t ix);
void pcm_effect_3f_0d(uint16_t ix);
void pcm_effect_3f_0d_wait_sample(uint16_t ix);
void pcm_effect_3f_0e(uint16_t ix);
void pcm_effect_3f_0e_wait_sample(uint16_t ix);
void pcm_effect_3f_0f(uint16_t ix);
void pcm_effect_3f_0f_wait_sample(uint16_t ix);
void pcm_effect_3f_10(uint16_t ix);
void pcm_effect_3f_10_wait_sample(uint16_t ix);
void pcm_effect_3f_11(uint16_t ix);
void pcm_effect_3f_11_wait_sample(uint16_t ix);
void pcm_effect_3f_12(uint16_t ix);
void pcm_effect_3f_12_wait_sample(uint16_t ix);
void pcm_effect_3f_13(uint16_t ix);
void pcm_effect_3f_13_wait_sample(uint16_t ix);
void pcm_effect_3f_14(uint16_t ix);
void pcm_effect_3f_14_wait_sample(uint16_t ix);
void pcm_effect_3f_15(uint16_t ix);
void pcm_effect_3f_15_wait_sample(uint16_t ix);
void pcm_effect_3f_16(uint16_t ix);
void pcm_effect_3f_16_wait_sample(uint16_t ix);
void pcm_effect_3f_17(uint16_t ix);
void pcm_effect_3f_17_wait_sample(uint16_t ix);
void pcm_effect_3f_18(uint16_t ix);
void pcm_effect_3f_18_wait_sample(uint16_t ix);
void pcm_effect_3f_19(uint16_t ix);
void pcm_effect_3f_19_wait_sample(uint16_t ix);
void pcm_effect_3f_1a(uint16_t ix);
void pcm_effect_3f_1a_wait_sample(uint16_t ix);
void pcm_effect_3f_1b(uint16_t ix);
void pcm_effect_3f_1b_wait_sample(uint16_t ix);
void pcm_effect_3f_1c(uint16_t ix);
void pcm_effect_3f_1c_wait_sample(uint16_t ix);
void pcm_effect_3f_1d(uint16_t ix);
void pcm_effect_3f_1d_wait_sample(uint16_t ix);
void pcm_effect_3f_1e(uint16_t ix);
void pcm_effect_3f_1e_wait_sample(uint16_t ix);
void pcm_effect_3f_1f(uint16_t ix);
void pcm_effect_3f_1f_wait_sample(uint16_t ix);
void pcm_effect_3f_20(uint16_t ix);
void pcm_effect_3f_20_wait_sample(uint16_t ix);
void pcm_effect_3f_21(uint16_t ix);
void pcm_effect_3f_21_wait_sample(uint16_t ix);
void pcm_effect_3f_22(uint16_t ix);
void pcm_effect_3f_22_wait_sample(uint16_t ix);
void pcm_effect_3f_23(uint16_t ix);
void pcm_effect_3f_23_wait_sample(uint16_t ix);
void pcm_effect_3f_24(uint16_t ix);
void pcm_effect_3f_24_wait_sample(uint16_t ix);
void pcm_effect_3f_25(uint16_t ix);
void pcm_effect_3f_25_wait_sample(uint16_t ix);
void pcm_effect_3f_26(uint16_t ix);
void pcm_effect_3f_26_wait_sample(uint16_t ix);
void pcm_effect_3f_27(uint16_t ix);
void pcm_effect_3f_27_wait_sample(uint16_t ix);
void pcm_effect_3f_28(uint16_t ix);
void pcm_effect_3f_28_wait_sample(uint16_t ix);
void pcm_effect_3f_29(uint16_t ix);
void pcm_effect_3f_29_wait_sample(uint16_t ix);
void pcm_effect_3f_2a(uint16_t ix);
void pcm_effect_3f_2a_wait_sample(uint16_t ix);
void pcm_effect_3f_2b(uint16_t ix);
void pcm_effect_3f_2b_wait_sample(uint16_t ix);
void pcm_effect_3f_2c(uint16_t ix);
void pcm_effect_3f_2c_wait_sample(uint16_t ix);
void pcm_effect_3f_2d(uint16_t ix);
void pcm_effect_3f_2d_wait_sample(uint16_t ix);
void pcm_effect_3f_2e(uint16_t ix);
void pcm_effect_3f_2e_wait_sample(uint16_t ix);
void pcm_effect_3f_2f(uint16_t ix);
void pcm_effect_3f_30(uint16_t ix);
void pcm_effect_3f_30_wait_sample(uint16_t ix);
void pcm_effect_3f_31(uint16_t ix);
void pcm_effect_3f_31_wait_sample(uint16_t ix);
void pcm_effect_3f_32(uint16_t ix);
void pcm_effect_3f_32_wait_sample(uint16_t ix);
void pcm_effect_3f_33(uint16_t ix);
void pcm_effect_3f_33_wait_sample(uint16_t ix);
void pcm_effect_3f_34(uint16_t ix);
void pcm_effect_3f_34_wait_sample(uint16_t ix);
void pcm_effect_3f_35(uint16_t ix);
void pcm_effect_3f_35_wait_sample(uint16_t ix);
void pcm_effect_3f_36(uint16_t ix);
void pcm_effect_3f_36_wait_sample(uint16_t ix);
void pcm_effect_3f_37(uint16_t ix);
void pcm_effect_3f_37_wait_sample(uint16_t ix);
void pcm_effect_3f_38(uint16_t ix);
void pcm_effect_3f_38_wait_sample(uint16_t ix);
void unused_358A(uint16_t ix, uint8_t a);
void pcm_effect_3f_39(uint16_t ix);
void pcm_effect_3f_39_wait_sample(uint16_t ix);
void pcm_effect_3f_3a(uint16_t ix);
void pcm_effect_3f_3a_wait_sample(uint16_t ix);
void pcm_effect_3f_3b(uint16_t ix);
void pcm_effect_3f_3b_wait_sample(uint16_t ix);
void pcm_effect_42(uint16_t ix);
void pcm_effect_41(uint16_t ix);
void pcm_effect_40(uint16_t ix);
void pcm_effect_42_setup(uint16_t hl, uint16_t ix);
void pcm_effect_42_retrigger(uint16_t ix);
void pcm_effect_42_setup_2(uint16_t ix);
uint32_t pcm_effect_42_update(uint16_t ix);
void pcm_effect_43(uint16_t ix);
void pcm_effect_43_wait_sample(uint16_t ix);
void pcm_effect_44(uint16_t ix);
void pcm_effect_44_wait_sample(uint16_t ix);
void pcm_effect_45(uint16_t ix);
void pcm_effect_45_wait_sample(uint16_t ix);
void pcm_effect_46(uint16_t ix);
void pcm_effect_46_retrigger(uint16_t ix);
void pcm_effect_47(uint16_t ix);
void pcm_effect_47_wait_sample(uint16_t ix);
void pcm_effect_48(uint16_t ix);
void pcm_effect_48_wait_sample(uint16_t ix);
void pcm_effect_49(uint16_t ix);
void pcm_effect_49_wait_sample(uint16_t ix);
void pcm_effect_4a(uint16_t ix);
void pcm_effect_4a_wait_sample(uint16_t ix);
void pcm_effect_4b(uint16_t ix);
void pcm_effect_4b_wait_sample(uint16_t ix);
void pcm_effect_4c(uint16_t ix);
void pcm_effect_4c_wait_sample(uint16_t ix);
void pcm_effect_4d(uint16_t ix);
void pcm_effect_4d_wait_sample(uint16_t ix);
void pcm_effect_4e(uint16_t ix);
void pcm_effect_4e_wait_sample(uint16_t ix);
void pcm_effect_4f(uint16_t ix);
void pcm_effect_4f_wait_sample(uint16_t ix);
void pcm_effect_50(uint16_t ix);
void pcm_effect_50_fade(uint16_t ix);
void pcm_effect_50_wait_sample(uint16_t ix);
void pcm_effect_51(uint16_t ix);
void pcm_effect_51_wait_sample(uint16_t ix);
void pcm_effect_52(uint16_t ix);
void pcm_effect_52_delay(uint16_t ix);
void pcm_effect_52_hold(uint16_t ix);
void pcm_effect_53(uint16_t ix);
void pcm_effect_53_wait_sample(uint16_t ix);
void pcm_effect_54(uint16_t ix);
void pcm_effect_54_modulate(uint16_t ix);
void pcm_effect_54_wait_sample(uint16_t ix);
void pcm_effect_55(uint16_t ix);
void pcm_effect_55_wait_sample(uint16_t ix);
void pcm_effect_56(uint16_t ix);
void pcm_effect_56_retrigger(uint16_t ix);
void pcm_effect_56_retrigger_2(uint16_t ix);
void pcm_effect_56_wait_sample(uint16_t ix);
void pcm_effect_57(uint16_t ix);
void pcm_effect_57_retrigger(uint16_t ix);
void pcm_effect_57_note(uint16_t ix);
void pcm_effect_57_wait_sample(uint16_t ix);
uint32_t pcm_effect_57_update(uint16_t ix);
void pcm_effect_58(uint16_t ix);
void pcm_effect_58_retrigger(uint16_t ix);
void pcm_effect_59(uint16_t ix);
void pcm_effect_59_wait_sample(uint16_t ix);
void pcm_effect_5a(uint16_t ix);
void pcm_effect_5a_wait_sample(uint16_t ix);
void pcm_effect_5b(uint16_t ix);
void pcm_effect_5b_wait_sample(uint16_t ix);
void pcm_effect_5c(uint16_t ix);
void pcm_effect_5c_delay(uint16_t ix);
void pcm_effect_5c_hold(uint16_t ix);
void pcm_effect_5d(uint16_t ix);
void pcm_effect_5d_delay(uint16_t ix);
void pcm_effect_5d_hold(uint16_t ix);
void pcm_effect_5e(uint16_t ix);
void pcm_effect_5e_wait_sample(uint16_t ix);
void pcm_effect_5f(uint16_t ix);
void pcm_effect_5f_wait_sample(uint16_t ix);
void pcm_effect_60(uint16_t ix);
void pcm_effect_60_wait_sample(uint16_t ix);
void pcm_effect_61(uint16_t ix);
void pcm_effect_61_wait_sample(uint16_t ix);
void pcm_effect_62(uint16_t ix);
void pcm_effect_62_wait_sample(uint16_t ix);
void pcm_effect_63(uint16_t ix);
void pcm_effect_63_wait_sample(uint16_t ix);
void pcm_effect_64(uint16_t ix);
void pcm_effect_64_wait_sample(uint16_t ix);
void pcm_effect_65(uint16_t ix);
void pcm_effect_65_wait_sample(uint16_t ix);
void pcm_effect_66(uint16_t ix);
void pcm_effect_66_wait_sample(uint16_t ix);
void pcm_effect_67(uint16_t ix);
void pcm_effect_67_wait_sample(uint16_t ix);
void pcm_effect_68(uint16_t ix);
void pcm_effect_68_wait_sample(uint16_t ix);
void pcm_effect_69(uint16_t ix);
void pcm_effect_69_wait_sample(uint16_t ix);
void pcm_effect_6a(uint16_t ix);
void pcm_effect_6a_wait_sample(uint16_t ix);
void pcm_effect_6b(uint16_t ix);
void pcm_effect_6b_wait_sample(uint16_t ix);
void pcm_effect_6c(uint16_t ix);
void pcm_effect_6c_wait_sample(uint16_t ix);
void pcm_effect_6d(uint16_t ix);
void pcm_effect_6d_wait_sample(uint16_t ix);
void pcm_effect_6e(uint16_t ix);
void pcm_effect_6e_wait_sample(uint16_t ix);
void pcm_effect_6f(uint16_t ix);
void pcm_effect_6f_wait_sample(uint16_t ix);
void pcm_effect_70(uint16_t ix);
void pcm_effect_70_wait_sample(uint16_t ix);
void pcm_effect_71(uint16_t ix);
void pcm_effect_71_wait_sample(uint16_t ix);
void pcm_effect_72(uint16_t ix);
void pcm_effect_72_wait_sample(uint16_t ix);
void pcm_effect_73(uint16_t ix);
void pcm_effect_73_wait_sample(uint16_t ix);
void pcm_effect_74(uint16_t ix);
void pcm_effect_74_wait_sample(uint16_t ix);
void pcm_effect_75(uint16_t ix);
void pcm_effect_75_wait_sample(uint16_t ix);
void pcm_effect_76(uint16_t ix);
void pcm_effect_76_wait_sample(uint16_t ix);
void pcm_effect_77(uint16_t ix);
void pcm_effect_77_delay(uint16_t ix);
void pcm_effect_77_hold(uint16_t ix);
void pcm_effect_78(uint16_t ix);
void pcm_effect_79(uint16_t ix);
void pcm_effect_79_wait_sample(uint16_t ix);
void pcm_effect_7a(uint16_t ix);
void pcm_effect_7a_retrigger(uint16_t ix);
void pcm_effect_7a_retrigger_2(uint16_t ix);
void pcm_effect_7a_retrigger_3(uint16_t ix);
void pcm_effect_7a_retrigger_4(uint16_t ix);
void pcm_effect_7b(uint16_t ix);
void pcm_effect_7b_wait_sample(uint16_t ix);
void pcm_effect_7c(uint16_t ix);
void pcm_effect_7c_retrigger(uint16_t ix);
void pcm_effect_7c_retrigger_2(uint16_t ix);
void pcm_effect_7c_retrigger_3(uint16_t ix);
void pcm_effect_7c_retrigger_4(uint16_t ix);
void pcm_effect_7d(uint16_t ix);
void pcm_effect_7d_wait_sample(uint16_t ix);
void pcm_effect_7e(uint16_t ix);
void pcm_effect_7e_retrigger(uint16_t ix);
void pcm_effect_7e_retrigger_2(uint16_t ix);
void pcm_effect_7e_retrigger_3(uint16_t ix);
void pcm_effect_7f(uint16_t ix);
void pcm_effect_7f_retrigger(uint16_t ix);
void pcm_effect_7f_set_volume(uint16_t ix);

/* unused_effects.c: a group of four FM effects no command reaches (unused_effect_group) */
void unused_effect_2799(uint16_t ix);
void unused_effect_2799_slide(uint16_t ix);
void unused_effect_280E(uint16_t ix);
void unused_effect_280E_hold(uint16_t ix);
void unused_effect_2856(uint16_t ix);
void unused_effect_2856_end(uint16_t ix);
void unused_effect_289F(uint16_t ix);
void unused_effect_289F_step(uint16_t ix);
void unused_effect_289F_end(uint16_t ix);
uint32_t unused_effect_289F_update(uint16_t ix);

#endif
