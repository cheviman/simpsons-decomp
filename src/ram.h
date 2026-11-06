/**
 *    Name:        ram.h
 *    Description: the game's variables, tables, board registers and structures
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    06-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#ifndef SIMPSONS_RAM_H
#define SIMPSONS_RAM_H

/* the game's variables in work RAM (4000-5FFF), which the board keeps the other way round */
#define unk_4000_ADDRESS 0x4000u
#define unk_4000 RAM8(unk_4000_ADDRESS)
#define unk_4800_ADDRESS 0x4800u
#define unk_4800 RAM8(unk_4800_ADDRESS)
#define unk_4801_ADDRESS 0x4801u
#define unk_4801 RAM8(unk_4801_ADDRESS)
#define unk_4802_ADDRESS 0x4802u
#define unk_4802 RAM8(unk_4802_ADDRESS)
#define unk_4803_ADDRESS 0x4803u
#define unk_4803 RAM8(unk_4803_ADDRESS)
#define unk_4804_ADDRESS 0x4804u
#define unk_4804 RAM8(unk_4804_ADDRESS)
#define unk_4805_ADDRESS 0x4805u
#define unk_4805 RAM16(unk_4805_ADDRESS)
#define unk_4807_ADDRESS 0x4807u
#define unk_4807 RAM16(unk_4807_ADDRESS)
#define unk_4809_ADDRESS 0x4809u
#define unk_4809 RAM8(unk_4809_ADDRESS)
#define unk_480A_ADDRESS 0x480Au
#define unk_480A RAM8(unk_480A_ADDRESS)
#define unk_480B_ADDRESS 0x480Bu
#define unk_480B RAM8(unk_480B_ADDRESS)
#define unk_480D_ADDRESS 0x480Du
#define unk_480D RAM8(unk_480D_ADDRESS)
#define unk_480E_ADDRESS 0x480Eu
#define unk_480E RAM8(unk_480E_ADDRESS)
#define unk_480F_ADDRESS 0x480Fu
#define unk_480F RAM8(unk_480F_ADDRESS)
#define unk_4810_ADDRESS 0x4810u
#define unk_4810 RAM8(unk_4810_ADDRESS)
#define unk_4811_ADDRESS 0x4811u
#define unk_4811 RAM8(unk_4811_ADDRESS)
#define unk_4812_ADDRESS 0x4812u
#define unk_4812 RAM8(unk_4812_ADDRESS)
#define unk_4813_ADDRESS 0x4813u
#define unk_4813 RAM8(unk_4813_ADDRESS)
#define unk_4814_ADDRESS 0x4814u
#define unk_4814 RAM8(unk_4814_ADDRESS)
#define unk_4815_ADDRESS 0x4815u
#define unk_4815 RAM16(unk_4815_ADDRESS)
#define unk_4817_ADDRESS 0x4817u
#define unk_4817 RAM16(unk_4817_ADDRESS)
#define unk_481A_ADDRESS 0x481Au
#define unk_481A RAM8(unk_481A_ADDRESS)
#define unk_481B_ADDRESS 0x481Bu
#define unk_481B RAM8(unk_481B_ADDRESS)
#define unk_481C_ADDRESS 0x481Cu
#define unk_481C RAM8(unk_481C_ADDRESS)
#define unk_481D_ADDRESS 0x481Du
#define unk_481D RAM8(unk_481D_ADDRESS)
#define unk_481F_ADDRESS 0x481Fu
#define unk_481F RAM16(unk_481F_ADDRESS)
#define unk_4822_ADDRESS 0x4822u
#define unk_4822 RAM8(unk_4822_ADDRESS)
#define unk_4823_ADDRESS 0x4823u
#define unk_4823 RAM8(unk_4823_ADDRESS)
#define unk_4824_ADDRESS 0x4824u
#define unk_4824 RAM8(unk_4824_ADDRESS)
#define unk_4825_ADDRESS 0x4825u
#define unk_4825 RAM8(unk_4825_ADDRESS)
#define unk_4827_ADDRESS 0x4827u
#define unk_4827 RAM16(unk_4827_ADDRESS)
#define unk_482F_ADDRESS 0x482Fu
#define unk_482F RAM16(unk_482F_ADDRESS)
#define unk_4837_ADDRESS 0x4837u
#define unk_4837 RAM16(unk_4837_ADDRESS)
#define unk_4839_ADDRESS 0x4839u
#define unk_4839 RAM8(unk_4839_ADDRESS)
#define unk_483A_ADDRESS 0x483Au
#define unk_483A RAM8(unk_483A_ADDRESS)
#define unk_483B_ADDRESS 0x483Bu
#define unk_483B RAM8(unk_483B_ADDRESS)
#define unk_483D_ADDRESS 0x483Du
#define unk_483D RAM8(unk_483D_ADDRESS)
#define unk_483E_ADDRESS 0x483Eu
#define unk_483E RAM8(unk_483E_ADDRESS)
#define unk_483F_ADDRESS 0x483Fu
#define unk_483F RAM8(unk_483F_ADDRESS)
#define unk_4840_ADDRESS 0x4840u
#define unk_4840 RAM8(unk_4840_ADDRESS)
#define unk_4842_ADDRESS 0x4842u
#define unk_4842 RAM8(unk_4842_ADDRESS)
#define unk_4844_ADDRESS 0x4844u
#define unk_4844 RAM8(unk_4844_ADDRESS)
#define unk_4846_ADDRESS 0x4846u
#define unk_4846 RAM8(unk_4846_ADDRESS)
#define unk_4848_ADDRESS 0x4848u
#define unk_4848 RAM8(unk_4848_ADDRESS)
#define unk_484A_ADDRESS 0x484Au
#define unk_484A RAM8(unk_484A_ADDRESS)
#define unk_484C_ADDRESS 0x484Cu
#define unk_484C RAM8(unk_484C_ADDRESS)
#define unk_484E_ADDRESS 0x484Eu
#define unk_484E RAM8(unk_484E_ADDRESS)
#define unk_4850_ADDRESS 0x4850u
#define unk_4850 RAM8(unk_4850_ADDRESS)
#define unk_4851_ADDRESS 0x4851u
#define unk_4851 RAM8(unk_4851_ADDRESS)
#define unk_4855_ADDRESS 0x4855u
#define unk_4855 RAM8(unk_4855_ADDRESS)
#define unk_4856_ADDRESS 0x4856u
#define unk_4856 RAM8(unk_4856_ADDRESS)
#define unk_4857_ADDRESS 0x4857u
#define unk_4857 RAM8(unk_4857_ADDRESS)
#define unk_4858_ADDRESS 0x4858u
#define unk_4858 RAM8(unk_4858_ADDRESS)
#define unk_485A_ADDRESS 0x485Au
#define unk_485A RAM8(unk_485A_ADDRESS)
#define unk_485B_ADDRESS 0x485Bu
#define unk_485B RAM8(unk_485B_ADDRESS)
#define unk_485D_ADDRESS 0x485Du
#define unk_485D RAM8(unk_485D_ADDRESS)
#define unk_485E_ADDRESS 0x485Eu
#define unk_485E RAM8(unk_485E_ADDRESS)
#define unk_485F_ADDRESS 0x485Fu
#define unk_485F RAM8(unk_485F_ADDRESS)
#define unk_4860_ADDRESS 0x4860u
#define unk_4860 RAM8(unk_4860_ADDRESS)
#define unk_4861_ADDRESS 0x4861u
#define unk_4861 RAM8(unk_4861_ADDRESS)
#define unk_4862_ADDRESS 0x4862u
#define unk_4862 RAM8(unk_4862_ADDRESS)
#define unk_4863_ADDRESS 0x4863u
#define unk_4863 RAM16(unk_4863_ADDRESS)
#define unk_4865_ADDRESS 0x4865u
#define unk_4865 RAM16(unk_4865_ADDRESS)
#define unk_4867_ADDRESS 0x4867u
#define unk_4867 RAM8(unk_4867_ADDRESS)
#define unk_486A_ADDRESS 0x486Au
#define unk_486A RAM8(unk_486A_ADDRESS)
#define unk_486B_ADDRESS 0x486Bu
#define unk_486B RAM8(unk_486B_ADDRESS)
#define unk_4870_ADDRESS 0x4870u
#define unk_4870 RAM8(unk_4870_ADDRESS)
#define unk_4871_ADDRESS 0x4871u
#define unk_4871 RAM8(unk_4871_ADDRESS)
#define unk_4872_ADDRESS 0x4872u
#define unk_4872 RAM8(unk_4872_ADDRESS)
#define unk_4873_ADDRESS 0x4873u
#define unk_4873 RAM16(unk_4873_ADDRESS)
#define unk_4875_ADDRESS 0x4875u
#define unk_4875 RAM8(unk_4875_ADDRESS)
#define unk_4876_ADDRESS 0x4876u
#define unk_4876 RAM8(unk_4876_ADDRESS)
#define unk_4877_ADDRESS 0x4877u
#define unk_4877 RAM8(unk_4877_ADDRESS)
#define unk_4878_ADDRESS 0x4878u
#define unk_4878 RAM8(unk_4878_ADDRESS)
#define unk_4879_ADDRESS 0x4879u
#define unk_4879 RAM8(unk_4879_ADDRESS)
#define unk_487A_ADDRESS 0x487Au
#define unk_487A RAM8(unk_487A_ADDRESS)
#define unk_487B_ADDRESS 0x487Bu
#define unk_487B RAM8(unk_487B_ADDRESS)
#define unk_487C_ADDRESS 0x487Cu
#define unk_487C RAM8(unk_487C_ADDRESS)
#define unk_487D_ADDRESS 0x487Du
#define unk_487D RAM8(unk_487D_ADDRESS)
#define unk_487E_ADDRESS 0x487Eu
#define unk_487E RAM8(unk_487E_ADDRESS)
#define unk_487F_ADDRESS 0x487Fu
#define unk_487F RAM8(unk_487F_ADDRESS)
#define unk_4880_ADDRESS 0x4880u
#define unk_4880 RAM8(unk_4880_ADDRESS)
#define unk_4881_ADDRESS 0x4881u
#define unk_4881 RAM8(unk_4881_ADDRESS)
#define unk_4882_ADDRESS 0x4882u
#define unk_4882 RAM8(unk_4882_ADDRESS)
#define unk_4883_ADDRESS 0x4883u
#define unk_4883 RAM8(unk_4883_ADDRESS)
#define unk_4884_ADDRESS 0x4884u
#define unk_4884 RAM8(unk_4884_ADDRESS)
#define unk_4885_ADDRESS 0x4885u
#define unk_4885 RAM8(unk_4885_ADDRESS)
#define unk_4886_ADDRESS 0x4886u
#define unk_4886 RAM16(unk_4886_ADDRESS)
#define unk_4888_ADDRESS 0x4888u
#define unk_4888 RAM8(unk_4888_ADDRESS)
#define unk_4889_ADDRESS 0x4889u
#define unk_4889 RAM16(unk_4889_ADDRESS)
#define unk_488B_ADDRESS 0x488Bu
#define unk_488B RAM8(unk_488B_ADDRESS)
#define unk_488D_ADDRESS 0x488Du
#define unk_488D RAM8(unk_488D_ADDRESS)
#define unk_488E_ADDRESS 0x488Eu
#define unk_488E RAM8(unk_488E_ADDRESS)
#define unk_488F_ADDRESS 0x488Fu
#define unk_488F RAM8(unk_488F_ADDRESS)
#define unk_4890_ADDRESS 0x4890u
#define unk_4890 RAM16(unk_4890_ADDRESS)
#define unk_4892_ADDRESS 0x4892u
#define unk_4892 RAM8(unk_4892_ADDRESS)
#define unk_4893_ADDRESS 0x4893u
#define unk_4893 RAM16(unk_4893_ADDRESS)
#define unk_4895_ADDRESS 0x4895u
#define unk_4895 RAM8(unk_4895_ADDRESS)
#define unk_4896_ADDRESS 0x4896u
#define unk_4896 RAM8(unk_4896_ADDRESS)
#define unk_4897_ADDRESS 0x4897u
#define unk_4897 RAM8(unk_4897_ADDRESS)
#define unk_4898_ADDRESS 0x4898u
#define unk_4898 RAM8(unk_4898_ADDRESS)
#define unk_4899_ADDRESS 0x4899u
#define unk_4899 RAM8(unk_4899_ADDRESS)
#define unk_489A_ADDRESS 0x489Au
#define unk_489A RAM8(unk_489A_ADDRESS)
#define unk_489B_ADDRESS 0x489Bu
#define unk_489B RAM8(unk_489B_ADDRESS)
#define unk_489C_ADDRESS 0x489Cu
#define unk_489C RAM8(unk_489C_ADDRESS)
#define unk_489D_ADDRESS 0x489Du
#define unk_489D RAM8(unk_489D_ADDRESS)
#define unk_489E_ADDRESS 0x489Eu
#define unk_489E RAM8(unk_489E_ADDRESS)
#define unk_489F_ADDRESS 0x489Fu
#define unk_489F RAM16(unk_489F_ADDRESS)
#define unk_48A1_ADDRESS 0x48A1u
#define unk_48A1 RAM8(unk_48A1_ADDRESS)
#define unk_48A2_ADDRESS 0x48A2u
#define unk_48A2 RAM8(unk_48A2_ADDRESS)
#define unk_48A3_ADDRESS 0x48A3u
#define unk_48A3 RAM8(unk_48A3_ADDRESS)
#define unk_48A4_ADDRESS 0x48A4u
#define unk_48A4 RAM16(unk_48A4_ADDRESS)
#define unk_48A6_ADDRESS 0x48A6u
#define unk_48A6 RAM8(unk_48A6_ADDRESS)
#define unk_48A7_ADDRESS 0x48A7u
#define unk_48A7 RAM8(unk_48A7_ADDRESS)
#define unk_48A8_ADDRESS 0x48A8u
#define unk_48A8 RAM8(unk_48A8_ADDRESS)
#define unk_48A9_ADDRESS 0x48A9u
#define unk_48A9 RAM8(unk_48A9_ADDRESS)
#define unk_48AA_ADDRESS 0x48AAu
#define unk_48AA RAM8(unk_48AA_ADDRESS)
#define unk_48AB_ADDRESS 0x48ABu
#define unk_48AB RAM8(unk_48AB_ADDRESS)
#define unk_48AC_ADDRESS 0x48ACu
#define unk_48AC RAM16(unk_48AC_ADDRESS)
#define unk_48AF_ADDRESS 0x48AFu
#define unk_48AF RAM8(unk_48AF_ADDRESS)
#define unk_48B0_ADDRESS 0x48B0u
#define unk_48B0 RAM8(unk_48B0_ADDRESS)
#define unk_48B2_ADDRESS 0x48B2u
#define unk_48B2 RAM16(unk_48B2_ADDRESS)
#define unk_48B5_ADDRESS 0x48B5u
#define unk_48B5 RAM8(unk_48B5_ADDRESS)
#define unk_48B6_ADDRESS 0x48B6u
#define unk_48B6 RAM8(unk_48B6_ADDRESS)
#define unk_48B8_ADDRESS 0x48B8u
#define unk_48B8 RAM16(unk_48B8_ADDRESS)
#define unk_48BB_ADDRESS 0x48BBu
#define unk_48BB RAM8(unk_48BB_ADDRESS)
#define unk_48BC_ADDRESS 0x48BCu
#define unk_48BC RAM16(unk_48BC_ADDRESS)
#define unk_48BE_ADDRESS 0x48BEu
#define unk_48BE RAM16(unk_48BE_ADDRESS)
#define unk_48C1_ADDRESS 0x48C1u
#define unk_48C1 RAM16(unk_48C1_ADDRESS)
#define unk_48C3_ADDRESS 0x48C3u
#define unk_48C3 RAM16(unk_48C3_ADDRESS)
#define unk_48C5_ADDRESS 0x48C5u
#define unk_48C5 RAM16(unk_48C5_ADDRESS)
#define unk_48C8_ADDRESS 0x48C8u
#define unk_48C8 RAM16(unk_48C8_ADDRESS)
#define unk_48CA_ADDRESS 0x48CAu
#define unk_48CA RAM16(unk_48CA_ADDRESS)
#define unk_48CC_ADDRESS 0x48CCu
#define unk_48CC RAM16(unk_48CC_ADDRESS)
#define unk_48CE_ADDRESS 0x48CEu
#define unk_48CE RAM16(unk_48CE_ADDRESS)
#define unk_48D1_ADDRESS 0x48D1u
#define unk_48D1 RAM16(unk_48D1_ADDRESS)
#define unk_48D3_ADDRESS 0x48D3u
#define unk_48D3 RAM16(unk_48D3_ADDRESS)
#define unk_48D5_ADDRESS 0x48D5u
#define unk_48D5 RAM16(unk_48D5_ADDRESS)
#define unk_48D7_ADDRESS 0x48D7u
#define unk_48D7 RAM8(unk_48D7_ADDRESS)
#define unk_48D8_ADDRESS 0x48D8u
#define unk_48D8 RAM16(unk_48D8_ADDRESS)
#define unk_48DA_ADDRESS 0x48DAu
#define unk_48DA RAM16(unk_48DA_ADDRESS)
#define unk_48DE_ADDRESS 0x48DEu
#define unk_48DE RAM16(unk_48DE_ADDRESS)
#define unk_48E0_ADDRESS 0x48E0u
#define unk_48E0 RAM16(unk_48E0_ADDRESS)
#define unk_48E2_ADDRESS 0x48E2u
#define unk_48E2 RAM16(unk_48E2_ADDRESS)
#define unk_48E4_ADDRESS 0x48E4u
#define unk_48E4 RAM16(unk_48E4_ADDRESS)
#define unk_48E6_ADDRESS 0x48E6u
#define unk_48E6 RAM16(unk_48E6_ADDRESS)
#define unk_48E8_ADDRESS 0x48E8u
#define unk_48E8 RAM8(unk_48E8_ADDRESS)
#define unk_48E9_ADDRESS 0x48E9u
#define unk_48E9 RAM8(unk_48E9_ADDRESS)
#define unk_48EA_ADDRESS 0x48EAu
#define unk_48EA RAM8(unk_48EA_ADDRESS)
#define unk_48EB_ADDRESS 0x48EBu
#define unk_48EB RAM8(unk_48EB_ADDRESS)
#define unk_48EC_ADDRESS 0x48ECu
#define unk_48EC RAM8(unk_48EC_ADDRESS)
#define unk_48ED_ADDRESS 0x48EDu
#define unk_48ED RAM8(unk_48ED_ADDRESS)
#define unk_48EE_ADDRESS 0x48EEu
#define unk_48EE RAM8(unk_48EE_ADDRESS)
#define unk_48EF_ADDRESS 0x48EFu
#define unk_48EF RAM8(unk_48EF_ADDRESS)
#define unk_48F0_ADDRESS 0x48F0u
#define unk_48F0 RAM8(unk_48F0_ADDRESS)
#define unk_48F1_ADDRESS 0x48F1u
#define unk_48F1 RAM8(unk_48F1_ADDRESS)
#define unk_48F2_ADDRESS 0x48F2u
#define unk_48F2 RAM8(unk_48F2_ADDRESS)
#define unk_48F3_ADDRESS 0x48F3u
#define unk_48F3 RAM8(unk_48F3_ADDRESS)
#define unk_48F4_ADDRESS 0x48F4u
#define unk_48F4 RAM8(unk_48F4_ADDRESS)
#define unk_48F5_ADDRESS 0x48F5u
#define unk_48F5 RAM8(unk_48F5_ADDRESS)
#define unk_48F6_ADDRESS 0x48F6u
#define unk_48F6 RAM16(unk_48F6_ADDRESS)
#define unk_48F8_ADDRESS 0x48F8u
#define unk_48F8 RAM16(unk_48F8_ADDRESS)
#define unk_48FA_ADDRESS 0x48FAu
#define unk_48FA RAM16(unk_48FA_ADDRESS)
#define unk_48FC_ADDRESS 0x48FCu
#define unk_48FC RAM16(unk_48FC_ADDRESS)
#define unk_48FE_ADDRESS 0x48FEu
#define unk_48FE RAM16(unk_48FE_ADDRESS)
#define unk_4900_ADDRESS 0x4900u
#define unk_4900 RAM16(unk_4900_ADDRESS)
#define unk_4902_ADDRESS 0x4902u
#define unk_4902 RAM16(unk_4902_ADDRESS)
#define unk_4940_ADDRESS 0x4940u
#define unk_4940 RAM16(unk_4940_ADDRESS)
#define unk_4942_ADDRESS 0x4942u
#define unk_4942 RAM16(unk_4942_ADDRESS)
#define unk_49D0_ADDRESS 0x49D0u
#define unk_49D0 RAM16(unk_49D0_ADDRESS)
#define unk_49D3_ADDRESS 0x49D3u
#define unk_49D3 RAM8(unk_49D3_ADDRESS)
#define unk_49D4_ADDRESS 0x49D4u
#define unk_49D4 RAM16(unk_49D4_ADDRESS)
#define unk_49D6_ADDRESS 0x49D6u
#define unk_49D6 RAM8(unk_49D6_ADDRESS)
#define unk_49D7_ADDRESS 0x49D7u
#define unk_49D7 RAM8(unk_49D7_ADDRESS)
#define unk_49D8_ADDRESS 0x49D8u
#define unk_49D8 RAM16(unk_49D8_ADDRESS)
#define unk_49DB_ADDRESS 0x49DBu
#define unk_49DB RAM8(unk_49DB_ADDRESS)
#define unk_49DC_ADDRESS 0x49DCu
#define unk_49DC RAM16(unk_49DC_ADDRESS)
#define unk_49DE_ADDRESS 0x49DEu
#define unk_49DE RAM8(unk_49DE_ADDRESS)
#define unk_49DF_ADDRESS 0x49DFu
#define unk_49DF RAM8(unk_49DF_ADDRESS)
#define unk_49E0_ADDRESS 0x49E0u
#define unk_49E0 RAM16(unk_49E0_ADDRESS)
#define unk_49E3_ADDRESS 0x49E3u
#define unk_49E3 RAM8(unk_49E3_ADDRESS)
#define unk_49E4_ADDRESS 0x49E4u
#define unk_49E4 RAM16(unk_49E4_ADDRESS)
#define unk_49E6_ADDRESS 0x49E6u
#define unk_49E6 RAM8(unk_49E6_ADDRESS)
#define unk_49E7_ADDRESS 0x49E7u
#define unk_49E7 RAM8(unk_49E7_ADDRESS)
#define unk_49E8_ADDRESS 0x49E8u
#define unk_49E8 RAM16(unk_49E8_ADDRESS)
#define unk_49EB_ADDRESS 0x49EBu
#define unk_49EB RAM8(unk_49EB_ADDRESS)
#define unk_49EC_ADDRESS 0x49ECu
#define unk_49EC RAM16(unk_49EC_ADDRESS)
#define unk_49EE_ADDRESS 0x49EEu
#define unk_49EE RAM8(unk_49EE_ADDRESS)
#define unk_49EF_ADDRESS 0x49EFu
#define unk_49EF RAM8(unk_49EF_ADDRESS)
#define unk_49F0_ADDRESS 0x49F0u
#define unk_49F0 RAM8(unk_49F0_ADDRESS)
#define unk_49F1_ADDRESS 0x49F1u
#define unk_49F1 RAM8(unk_49F1_ADDRESS)
#define unk_49F2_ADDRESS 0x49F2u
#define unk_49F2 RAM8(unk_49F2_ADDRESS)
#define unk_49F3_ADDRESS 0x49F3u
#define unk_49F3 RAM8(unk_49F3_ADDRESS)
#define unk_4A02_ADDRESS 0x4A02u
#define unk_4A02 RAM16(unk_4A02_ADDRESS)
#define unk_4A04_ADDRESS 0x4A04u
#define unk_4A04 RAM16(unk_4A04_ADDRESS)
#define unk_4A06_ADDRESS 0x4A06u
#define unk_4A06 RAM8(unk_4A06_ADDRESS)
#define unk_4A09_ADDRESS 0x4A09u
#define unk_4A09 RAM16(unk_4A09_ADDRESS)
#define unk_4A0B_ADDRESS 0x4A0Bu
#define unk_4A0B RAM16(unk_4A0B_ADDRESS)
#define unk_4A0D_ADDRESS 0x4A0Du
#define unk_4A0D RAM8(unk_4A0D_ADDRESS)
#define unk_4A10_ADDRESS 0x4A10u
#define unk_4A10 RAM16(unk_4A10_ADDRESS)
#define unk_4A12_ADDRESS 0x4A12u
#define unk_4A12 RAM16(unk_4A12_ADDRESS)
#define unk_4A14_ADDRESS 0x4A14u
#define unk_4A14 RAM8(unk_4A14_ADDRESS)
#define unk_4A17_ADDRESS 0x4A17u
#define unk_4A17 RAM16(unk_4A17_ADDRESS)
#define unk_4A19_ADDRESS 0x4A19u
#define unk_4A19 RAM16(unk_4A19_ADDRESS)
#define unk_4A1B_ADDRESS 0x4A1Bu
#define unk_4A1B RAM8(unk_4A1B_ADDRESS)
#define unk_4A1C_ADDRESS 0x4A1Cu
#define unk_4A1C RAM8(unk_4A1C_ADDRESS)
#define unk_4A1D_ADDRESS 0x4A1Du
#define unk_4A1D RAM8(unk_4A1D_ADDRESS)
#define unk_4A21_ADDRESS 0x4A21u
#define unk_4A21 RAM8(unk_4A21_ADDRESS)
#define unk_4A22_ADDRESS 0x4A22u
#define unk_4A22 RAM8(unk_4A22_ADDRESS)
#define unk_4A40_ADDRESS 0x4A40u
#define unk_4A40 RAM8(unk_4A40_ADDRESS)
#define unk_4A42_ADDRESS 0x4A42u
#define unk_4A42 RAM8(unk_4A42_ADDRESS)
#define unk_4A4C_ADDRESS 0x4A4Cu
#define unk_4A4C RAM16(unk_4A4C_ADDRESS)
#define unk_4A51_ADDRESS 0x4A51u
#define unk_4A51 RAM16(unk_4A51_ADDRESS)
#define unk_4A70_ADDRESS 0x4A70u
#define unk_4A70 RAM8(unk_4A70_ADDRESS)
#define unk_4A7F_ADDRESS 0x4A7Fu
#define unk_4A7F RAM16(unk_4A7F_ADDRESS)
#define unk_4A84_ADDRESS 0x4A84u
#define unk_4A84 RAM8(unk_4A84_ADDRESS)
#define unk_4B00_ADDRESS 0x4B00u
#define unk_4B00 RAM8(unk_4B00_ADDRESS)
#define unk_4B02_ADDRESS 0x4B02u
#define unk_4B02 RAM8(unk_4B02_ADDRESS)
#define unk_4B0C_ADDRESS 0x4B0Cu
#define unk_4B0C RAM16(unk_4B0C_ADDRESS)
#define unk_4B11_ADDRESS 0x4B11u
#define unk_4B11 RAM16(unk_4B11_ADDRESS)
#define unk_4B30_ADDRESS 0x4B30u
#define unk_4B30 RAM8(unk_4B30_ADDRESS)
#define unk_4B3F_ADDRESS 0x4B3Fu
#define unk_4B3F RAM16(unk_4B3F_ADDRESS)
#define unk_4B44_ADDRESS 0x4B44u
#define unk_4B44 RAM8(unk_4B44_ADDRESS)
#define unk_4BC0_ADDRESS 0x4BC0u
#define unk_4BC0 RAM8(unk_4BC0_ADDRESS)
#define unk_4BC2_ADDRESS 0x4BC2u
#define unk_4BC2 RAM8(unk_4BC2_ADDRESS)
#define unk_4BCC_ADDRESS 0x4BCCu
#define unk_4BCC RAM16(unk_4BCC_ADDRESS)
#define unk_4BD1_ADDRESS 0x4BD1u
#define unk_4BD1 RAM16(unk_4BD1_ADDRESS)
#define unk_4BF0_ADDRESS 0x4BF0u
#define unk_4BF0 RAM8(unk_4BF0_ADDRESS)
#define unk_4BFF_ADDRESS 0x4BFFu
#define unk_4BFF RAM16(unk_4BFF_ADDRESS)
#define unk_4C04_ADDRESS 0x4C04u
#define unk_4C04 RAM8(unk_4C04_ADDRESS)
#define unk_4C80_ADDRESS 0x4C80u
#define unk_4C80 RAM8(unk_4C80_ADDRESS)
#define unk_4C82_ADDRESS 0x4C82u
#define unk_4C82 RAM8(unk_4C82_ADDRESS)
#define unk_4C8C_ADDRESS 0x4C8Cu
#define unk_4C8C RAM16(unk_4C8C_ADDRESS)
#define unk_4C91_ADDRESS 0x4C91u
#define unk_4C91 RAM16(unk_4C91_ADDRESS)
#define unk_4CB0_ADDRESS 0x4CB0u
#define unk_4CB0 RAM8(unk_4CB0_ADDRESS)
#define unk_4CBF_ADDRESS 0x4CBFu
#define unk_4CBF RAM16(unk_4CBF_ADDRESS)
#define unk_4CC4_ADDRESS 0x4CC4u
#define unk_4CC4 RAM8(unk_4CC4_ADDRESS)
#define unk_4D40_ADDRESS 0x4D40u
#define unk_4D40 RAM8(unk_4D40_ADDRESS)
#define unk_4D44_ADDRESS 0x4D44u
#define unk_4D44 RAM8(unk_4D44_ADDRESS)
#define unk_4D45_ADDRESS 0x4D45u
#define unk_4D45 RAM8(unk_4D45_ADDRESS)
#define unk_4D46_ADDRESS 0x4D46u
#define unk_4D46 RAM8(unk_4D46_ADDRESS)
#define unk_4D49_ADDRESS 0x4D49u
#define unk_4D49 RAM8(unk_4D49_ADDRESS)
#define unk_4D4A_ADDRESS 0x4D4Au
#define unk_4D4A RAM8(unk_4D4A_ADDRESS)
#define unk_4D4C_ADDRESS 0x4D4Cu
#define unk_4D4C RAM16(unk_4D4C_ADDRESS)
#define unk_4D4F_ADDRESS 0x4D4Fu
#define unk_4D4F RAM16(unk_4D4F_ADDRESS)
#define unk_4D51_ADDRESS 0x4D51u
#define unk_4D51 RAM16(unk_4D51_ADDRESS)
#define unk_4D54_ADDRESS 0x4D54u
#define unk_4D54 RAM16(unk_4D54_ADDRESS)
#define unk_4D56_ADDRESS 0x4D56u
#define unk_4D56 RAM16(unk_4D56_ADDRESS)
#define unk_4D59_ADDRESS 0x4D59u
#define unk_4D59 RAM16(unk_4D59_ADDRESS)
#define unk_4DA0_ADDRESS 0x4DA0u
#define unk_4DA0 RAM8(unk_4DA0_ADDRESS)
#define unk_4DA6_ADDRESS 0x4DA6u
#define unk_4DA6 RAM8(unk_4DA6_ADDRESS)
#define unk_4DA9_ADDRESS 0x4DA9u
#define unk_4DA9 RAM8(unk_4DA9_ADDRESS)
#define unk_4DC8_ADDRESS 0x4DC8u
#define unk_4DC8 RAM8(unk_4DC8_ADDRESS)
#define unk_4E00_ADDRESS 0x4E00u
#define unk_4E00 RAM8(unk_4E00_ADDRESS)
#define unk_4E09_ADDRESS 0x4E09u
#define unk_4E09 RAM8(unk_4E09_ADDRESS)
#define unk_4E16_ADDRESS 0x4E16u
#define unk_4E16 RAM16(unk_4E16_ADDRESS)
#define unk_4E19_ADDRESS 0x4E19u
#define unk_4E19 RAM16(unk_4E19_ADDRESS)
#define unk_4E28_ADDRESS 0x4E28u
#define unk_4E28 RAM8(unk_4E28_ADDRESS)
#define unk_4E5B_ADDRESS 0x4E5Bu
#define unk_4E5B RAM8(unk_4E5B_ADDRESS)
#define unk_4E69_ADDRESS 0x4E69u
#define unk_4E69 RAM8(unk_4E69_ADDRESS)
#define unk_4EC9_ADDRESS 0x4EC9u
#define unk_4EC9 RAM8(unk_4EC9_ADDRESS)
#define unk_4F80_ADDRESS 0x4F80u
#define unk_4F80 RAM8(unk_4F80_ADDRESS)
#define unk_4F81_ADDRESS 0x4F81u
#define unk_4F81 RAM8(unk_4F81_ADDRESS)
#define unk_4F84_ADDRESS 0x4F84u
#define unk_4F84 RAM16(unk_4F84_ADDRESS)
#define unk_4F86_ADDRESS 0x4F86u
#define unk_4F86 RAM8(unk_4F86_ADDRESS)
#define unk_4F89_ADDRESS 0x4F89u
#define unk_4F89 RAM8(unk_4F89_ADDRESS)
#define unk_4F8A_ADDRESS 0x4F8Au
#define unk_4F8A RAM8(unk_4F8A_ADDRESS)
#define unk_4F8B_ADDRESS 0x4F8Bu
#define unk_4F8B RAM8(unk_4F8B_ADDRESS)
#define unk_4F8C_ADDRESS 0x4F8Cu
#define unk_4F8C RAM16(unk_4F8C_ADDRESS)
#define unk_4F8F_ADDRESS 0x4F8Fu
#define unk_4F8F RAM16(unk_4F8F_ADDRESS)
#define unk_4F91_ADDRESS 0x4F91u
#define unk_4F91 RAM16(unk_4F91_ADDRESS)
#define unk_4F99_ADDRESS 0x4F99u
#define unk_4F99 RAM16(unk_4F99_ADDRESS)
#define unk_4F9B_ADDRESS 0x4F9Bu
#define unk_4F9B RAM8(unk_4F9B_ADDRESS)
#define unk_4FA8_ADDRESS 0x4FA8u
#define unk_4FA8 RAM16(unk_4FA8_ADDRESS)
#define unk_4FC5_ADDRESS 0x4FC5u
#define unk_4FC5 RAM8(unk_4FC5_ADDRESS)
#define unk_4FE5_ADDRESS 0x4FE5u
#define unk_4FE5 RAM8(unk_4FE5_ADDRESS)
#define unk_4FE6_ADDRESS 0x4FE6u
#define unk_4FE6 RAM8(unk_4FE6_ADDRESS)
#define unk_5040_ADDRESS 0x5040u
#define unk_5040 RAM8(unk_5040_ADDRESS)
#define unk_5085_ADDRESS 0x5085u
#define unk_5085 RAM8(unk_5085_ADDRESS)
#define unk_5109_ADDRESS 0x5109u
#define unk_5109 RAM8(unk_5109_ADDRESS)
#define unk_510C_ADDRESS 0x510Cu
#define unk_510C RAM16(unk_510C_ADDRESS)
#define unk_510F_ADDRESS 0x510Fu
#define unk_510F RAM16(unk_510F_ADDRESS)
#define unk_5114_ADDRESS 0x5114u
#define unk_5114 RAM16(unk_5114_ADDRESS)
#define unk_5145_ADDRESS 0x5145u
#define unk_5145 RAM8(unk_5145_ADDRESS)
#define unk_5205_ADDRESS 0x5205u
#define unk_5205 RAM8(unk_5205_ADDRESS)
#define unk_5404_ADDRESS 0x5404u
#define unk_5404 RAM8(unk_5404_ADDRESS)
#define unk_5405_ADDRESS 0x5405u
#define unk_5405 RAM8(unk_5405_ADDRESS)
#define unk_540C_ADDRESS 0x540Cu
#define unk_540C RAM16(unk_540C_ADDRESS)
#define unk_540F_ADDRESS 0x540Fu
#define unk_540F RAM16(unk_540F_ADDRESS)
#define unk_5419_ADDRESS 0x5419u
#define unk_5419 RAM16(unk_5419_ADDRESS)
#define unk_5520_ADDRESS 0x5520u
#define unk_5520 RAM8(unk_5520_ADDRESS)
#define unk_5521_ADDRESS 0x5521u
#define unk_5521 RAM8(unk_5521_ADDRESS)
#define unk_5524_ADDRESS 0x5524u
#define unk_5524 RAM16(unk_5524_ADDRESS)
#define unk_5529_ADDRESS 0x5529u
#define unk_5529 RAM8(unk_5529_ADDRESS)
#define unk_552C_ADDRESS 0x552Cu
#define unk_552C RAM16(unk_552C_ADDRESS)
#define unk_5531_ADDRESS 0x5531u
#define unk_5531 RAM16(unk_5531_ADDRESS)
#define unk_5580_ADDRESS 0x5580u
#define unk_5580 RAM8(unk_5580_ADDRESS)
#define unk_5581_ADDRESS 0x5581u
#define unk_5581 RAM8(unk_5581_ADDRESS)
#define unk_5584_ADDRESS 0x5584u
#define unk_5584 RAM16(unk_5584_ADDRESS)
#define unk_5589_ADDRESS 0x5589u
#define unk_5589 RAM8(unk_5589_ADDRESS)
#define unk_558C_ADDRESS 0x558Cu
#define unk_558C RAM16(unk_558C_ADDRESS)
#define unk_5591_ADDRESS 0x5591u
#define unk_5591 RAM16(unk_5591_ADDRESS)
#define unk_55E0_ADDRESS 0x55E0u
#define unk_55E0 RAM8(unk_55E0_ADDRESS)
#define unk_55E4_ADDRESS 0x55E4u
#define unk_55E4 RAM16(unk_55E4_ADDRESS)
#define unk_55EC_ADDRESS 0x55ECu
#define unk_55EC RAM16(unk_55EC_ADDRESS)
#define unk_55F1_ADDRESS 0x55F1u
#define unk_55F1 RAM16(unk_55F1_ADDRESS)
#define unk_55F6_ADDRESS 0x55F6u
#define unk_55F6 RAM16(unk_55F6_ADDRESS)
#define unk_5670_ADDRESS 0x5670u
#define unk_5670 RAM8(unk_5670_ADDRESS)
#define unk_5671_ADDRESS 0x5671u
#define unk_5671 RAM16(unk_5671_ADDRESS)
#define unk_5685_ADDRESS 0x5685u
#define unk_5685 RAM16(unk_5685_ADDRESS)
#define unk_5800_ADDRESS 0x5800u
#define unk_5800 RAM16(unk_5800_ADDRESS)
#define unk_5813_ADDRESS 0x5813u
#define unk_5813 RAM8(unk_5813_ADDRESS)
#define unk_5823_ADDRESS 0x5823u
#define unk_5823 RAM8(unk_5823_ADDRESS)
#define unk_5833_ADDRESS 0x5833u
#define unk_5833 RAM8(unk_5833_ADDRESS)
#define unk_5843_ADDRESS 0x5843u
#define unk_5843 RAM8(unk_5843_ADDRESS)
#define unk_5900_ADDRESS 0x5900u
#define unk_5900 RAM8(unk_5900_ADDRESS)
#define unk_5908_ADDRESS 0x5908u
#define unk_5908 RAM8(unk_5908_ADDRESS)
#define unk_5909_ADDRESS 0x5909u
#define unk_5909 RAM8(unk_5909_ADDRESS)
#define unk_590A_ADDRESS 0x590Au
#define unk_590A RAM8(unk_590A_ADDRESS)
#define unk_590B_ADDRESS 0x590Bu
#define unk_590B RAM16(unk_590B_ADDRESS)
#define unk_590D_ADDRESS 0x590Du
#define unk_590D RAM16(unk_590D_ADDRESS)
#define unk_5912_ADDRESS 0x5912u
#define unk_5912 RAM8(unk_5912_ADDRESS)
#define unk_5913_ADDRESS 0x5913u
#define unk_5913 RAM8(unk_5913_ADDRESS)
#define unk_5914_ADDRESS 0x5914u
#define unk_5914 RAM8(unk_5914_ADDRESS)
#define unk_5915_ADDRESS 0x5915u
#define unk_5915 RAM8(unk_5915_ADDRESS)
#define unk_5916_ADDRESS 0x5916u
#define unk_5916 RAM8(unk_5916_ADDRESS)
#define unk_5917_ADDRESS 0x5917u
#define unk_5917 RAM8(unk_5917_ADDRESS)
#define unk_591A_ADDRESS 0x591Au
#define unk_591A RAM8(unk_591A_ADDRESS)
#define unk_591B_ADDRESS 0x591Bu
#define unk_591B RAM8(unk_591B_ADDRESS)
#define unk_591C_ADDRESS 0x591Cu
#define unk_591C RAM8(unk_591C_ADDRESS)
#define unk_59F1_ADDRESS 0x59F1u
#define unk_59F1 RAM8(unk_59F1_ADDRESS)
#define unk_59F8_ADDRESS 0x59F8u
#define unk_59F8 RAM8(unk_59F8_ADDRESS)
#define unk_5A00_ADDRESS 0x5A00u
#define unk_5A00 RAM8(unk_5A00_ADDRESS)
#define unk_5A01_ADDRESS 0x5A01u
#define unk_5A01 RAM8(unk_5A01_ADDRESS)
#define unk_5A02_ADDRESS 0x5A02u
#define unk_5A02 RAM8(unk_5A02_ADDRESS)
#define unk_5A10_ADDRESS 0x5A10u
#define unk_5A10 RAM8(unk_5A10_ADDRESS)
#define unk_5A11_ADDRESS 0x5A11u
#define unk_5A11 RAM8(unk_5A11_ADDRESS)
#define unk_5A12_ADDRESS 0x5A12u
#define unk_5A12 RAM16(unk_5A12_ADDRESS)
#define unk_5A14_ADDRESS 0x5A14u
#define unk_5A14 RAM16(unk_5A14_ADDRESS)
#define unk_5A16_ADDRESS 0x5A16u
#define unk_5A16 RAM16(unk_5A16_ADDRESS)
#define unk_5A18_ADDRESS 0x5A18u
#define unk_5A18 RAM16(unk_5A18_ADDRESS)
#define unk_5A1A_ADDRESS 0x5A1Au
#define unk_5A1A RAM8(unk_5A1A_ADDRESS)
#define unk_5A1B_ADDRESS 0x5A1Bu
#define unk_5A1B RAM8(unk_5A1B_ADDRESS)
#define unk_5D00_ADDRESS 0x5D00u
#define unk_5D00 RAM16(unk_5D00_ADDRESS)
#define unk_5D02_ADDRESS 0x5D02u
#define unk_5D02 RAM8(unk_5D02_ADDRESS)
#define unk_5D03_ADDRESS 0x5D03u
#define unk_5D03 RAM8(unk_5D03_ADDRESS)
#define unk_5D04_ADDRESS 0x5D04u
#define unk_5D04 RAM8(unk_5D04_ADDRESS)
#define unk_5D05_ADDRESS 0x5D05u
#define unk_5D05 RAM8(unk_5D05_ADDRESS)
#define unk_5D06_ADDRESS 0x5D06u
#define unk_5D06 RAM8(unk_5D06_ADDRESS)
#define unk_5D07_ADDRESS 0x5D07u
#define unk_5D07 RAM8(unk_5D07_ADDRESS)
#define unk_5D08_ADDRESS 0x5D08u
#define unk_5D08 RAM8(unk_5D08_ADDRESS)
#define unk_5D09_ADDRESS 0x5D09u
#define unk_5D09 RAM8(unk_5D09_ADDRESS)

/* the program's data the code reads by name, which the game loads from its assets (src/table.c) */
#define indexed_table_021BC4_ADDRESS 0x7BC4u    /* 021BC4: bank 10 */
extern const void *indexed_table_021BC4_data;
#define indexed_table_021BC4 ((const uint16_t *)indexed_table_021BC4_data)
#define indexed_table_021BC8_ADDRESS 0x7BC8u    /* 021BC8: bank 10 */
extern const void *indexed_table_021BC8_data;
#define indexed_table_021BC8 ((const uint16_t *)indexed_table_021BC8_data)
#define unused_sound_commands_021BEC_ADDRESS 0x7BECu    /* 021BEC: bank 10 */
extern const void *unused_sound_commands_021BEC_data;
#define unused_sound_commands_021BEC ((const uint16_t *)unused_sound_commands_021BEC_data)
#define indexed_table_021C00_ADDRESS 0x7C00u    /* 021C00: bank 10 */
extern const void *indexed_table_021C00_data;
#define indexed_table_021C00 ((const uint16_t *)indexed_table_021C00_data)
#define rom_021C32_ADDRESS 0x7C32u    /* 021C32: bank 10 */
extern const void *rom_021C32_data;
#define rom_021C32 (*(const uint16_t *)rom_021C32_data)
#define indexed_table_021D28_ADDRESS 0x7D28u    /* 021D28: bank 10 */
extern const void *indexed_table_021D28_data;
#define indexed_table_021D28 ((const uint8_t *)indexed_table_021D28_data)
#define indexed_table_021D44_ADDRESS 0x7D44u    /* 021D44: bank 10 */
extern const void *indexed_table_021D44_data;
#define indexed_table_021D44 ((const uint8_t *)indexed_table_021D44_data)
#define indexed_table_021D4D_ADDRESS 0x7D4Du    /* 021D4D: bank 10 */
extern const void *indexed_table_021D4D_data;
#define indexed_table_021D4D ((const uint8_t *)indexed_table_021D4D_data)
#define indexed_table_021D55_ADDRESS 0x7D55u    /* 021D55: bank 10 */
extern const void *indexed_table_021D55_data;
#define indexed_table_021D55 ((const uint8_t *)indexed_table_021D55_data)
#define loaded_table_021D5D_ADDRESS 0x7D5Du    /* 021D5D: bank 10 */
extern const void *loaded_table_021D5D_data;
#define loaded_table_021D5D ((const uint8_t *)loaded_table_021D5D_data)
#define indexed_table_021D71_ADDRESS 0x7D71u    /* 021D71: bank 10 */
extern const void *indexed_table_021D71_data;
#define indexed_table_021D71 ((const uint16_t *)indexed_table_021D71_data)
#define indexed_table_021D7D_ADDRESS 0x7D7Du    /* 021D7D: bank 10 */
extern const void *indexed_table_021D7D_data;
#define indexed_table_021D7D ((const uint16_t *)indexed_table_021D7D_data)
#define indexed_table_021D9C_ADDRESS 0x7D9Cu    /* 021D9C: bank 10 */
extern const void *indexed_table_021D9C_data;
#define indexed_table_021D9C ((const uint8_t *)indexed_table_021D9C_data)
#define indexed_table_021E71_ADDRESS 0x7E71u    /* 021E71: bank 10 */
extern const void *indexed_table_021E71_data;
#define indexed_table_021E71 ((const uint8_t *)indexed_table_021E71_data)
#define indexed_table_021E75_ADDRESS 0x7E75u    /* 021E75: bank 10 */
extern const void *indexed_table_021E75_data;
#define indexed_table_021E75 ((const uint8_t *)indexed_table_021E75_data)
#define constant_table_021E79_ADDRESS 0x7E79u    /* 021E79: bank 10 */
extern const void *constant_table_021E79_data;
#define constant_table_021E79 ((const uint16_t *)constant_table_021E79_data)
#define indexed_table_021EB9_ADDRESS 0x7EB9u    /* 021EB9: bank 10 */
extern const void *indexed_table_021EB9_data;
#define indexed_table_021EB9 ((const uint8_t *)indexed_table_021EB9_data)
#define indexed_table_021EC9_ADDRESS 0x7EC9u    /* 021EC9: bank 10 */
extern const void *indexed_table_021EC9_data;
#define indexed_table_021EC9 ((const uint8_t *)indexed_table_021EC9_data)
#define indexed_table_021ECD_ADDRESS 0x7ECDu    /* 021ECD: bank 10 */
extern const void *indexed_table_021ECD_data;
#define indexed_table_021ECD ((const uint8_t *)indexed_table_021ECD_data)
#define indexed_table_021ED1_ADDRESS 0x7ED1u    /* 021ED1: bank 10 */
extern const void *indexed_table_021ED1_data;
#define indexed_table_021ED1 ((const uint8_t *)indexed_table_021ED1_data)
#define indexed_table_023532_ADDRESS 0x7532u    /* 023532: bank 11 */
extern const void *indexed_table_023532_data;
#define indexed_table_023532 ((const uint16_t *)indexed_table_023532_data)
#define indexed_table_02359E_ADDRESS 0x759Eu    /* 02359E: bank 11 */
extern const void *indexed_table_02359E_data;
#define indexed_table_02359E ((const uint8_t *)indexed_table_02359E_data)
#define indexed_table_0235AE_ADDRESS 0x75AEu    /* 0235AE: bank 11 */
extern const void *indexed_table_0235AE_data;
#define indexed_table_0235AE ((const uint16_t *)indexed_table_0235AE_data)
#define indexed_table_02367B_ADDRESS 0x767Bu    /* 02367B: bank 11 */
extern const void *indexed_table_02367B_data;
#define indexed_table_02367B ((const uint16_t *)indexed_table_02367B_data)
#define rom_023694_ADDRESS 0x7694u    /* 023694: bank 11 */
extern const void *rom_023694_data;
#define rom_023694 (*(const uint8_t *)rom_023694_data)
#define indexed_table_023695_ADDRESS 0x7695u    /* 023695: bank 11 */
extern const void *indexed_table_023695_data;
#define indexed_table_023695 ((const uint8_t *)indexed_table_023695_data)
#define indexed_table_0236F8_ADDRESS 0x76F8u    /* 0236F8: bank 11 */
extern const void *indexed_table_0236F8_data;
#define indexed_table_0236F8 ((const uint16_t *)indexed_table_0236F8_data)
#define indexed_table_023736_ADDRESS 0x7736u    /* 023736: bank 11 */
extern const void *indexed_table_023736_data;
#define indexed_table_023736 ((const uint16_t *)indexed_table_023736_data)
#define indexed_table_0238B2_ADDRESS 0x78B2u    /* 0238B2: bank 11 */
extern const void *indexed_table_0238B2_data;
#define indexed_table_0238B2 ((const uint16_t *)indexed_table_0238B2_data)
#define indexed_table_023A4D_ADDRESS 0x7A4Du    /* 023A4D: bank 11 */
extern const void *indexed_table_023A4D_data;
#define indexed_table_023A4D ((const uint8_t *)indexed_table_023A4D_data)
#define indexed_table_023A51_ADDRESS 0x7A51u    /* 023A51: bank 11 */
extern const void *indexed_table_023A51_data;
#define indexed_table_023A51 ((const uint8_t *)indexed_table_023A51_data)
#define constant_table_023A55_ADDRESS 0x7A55u    /* 023A55: bank 11 */
extern const void *constant_table_023A55_data;
#define constant_table_023A55 ((const uint16_t *)constant_table_023A55_data)
#define indexed_table_023AA1_ADDRESS 0x7AA1u    /* 023AA1: bank 11 */
extern const void *indexed_table_023AA1_data;
#define indexed_table_023AA1 ((const uint8_t *)indexed_table_023AA1_data)
#define indexed_table_023AA5_ADDRESS 0x7AA5u    /* 023AA5: bank 11 */
extern const void *indexed_table_023AA5_data;
#define indexed_table_023AA5 ((const uint8_t *)indexed_table_023AA5_data)
#define indexed_table_023AA9_ADDRESS 0x7AA9u    /* 023AA9: bank 11 */
extern const void *indexed_table_023AA9_data;
#define indexed_table_023AA9 ((const uint8_t *)indexed_table_023AA9_data)
#define indexed_table_023AB9_ADDRESS 0x7AB9u    /* 023AB9: bank 11 */
extern const void *indexed_table_023AB9_data;
#define indexed_table_023AB9 ((const uint16_t *)indexed_table_023AB9_data)
#define indexed_table_023B09_ADDRESS 0x7B09u    /* 023B09: bank 11 */
extern const void *indexed_table_023B09_data;
#define indexed_table_023B09 ((const uint16_t *)indexed_table_023B09_data)
#define game_texts_address_ADDRESS 0x6021u    /* 024021: bank 12 */
extern const void *game_texts_address_data;
#define game_texts_address ((const uint16_t *)game_texts_address_data)
#define indexed_table_025962_ADDRESS 0x7962u    /* 025962: bank 12 */
extern const void *indexed_table_025962_data;
#define indexed_table_025962 ((const uint8_t *)indexed_table_025962_data)
#define constant_table_02597A_ADDRESS 0x797Au    /* 02597A: bank 12 */
extern const void *constant_table_02597A_data;
#define constant_table_02597A ((const uint16_t *)constant_table_02597A_data)
#define game_texts_ADDRESS 0x79E4u    /* 0259E4: bank 12 */
extern const void *game_texts_data;
#define game_texts ((const uint16_t *)game_texts_data)
#define indexed_table_027A10_ADDRESS 0x7A10u    /* 027A10: bank 13 */
extern const void *indexed_table_027A10_data;
#define indexed_table_027A10 ((const uint8_t *)indexed_table_027A10_data)
#define indexed_table_027A37_ADDRESS 0x7A37u    /* 027A37: bank 13 */
extern const void *indexed_table_027A37_data;
#define indexed_table_027A37 ((const uint16_t *)indexed_table_027A37_data)
#define indexed_table_027CAE_ADDRESS 0x7CAEu    /* 027CAE: bank 13 */
extern const void *indexed_table_027CAE_data;
#define indexed_table_027CAE ((const uint8_t *)indexed_table_027CAE_data)
#define indexed_table_027CB2_ADDRESS 0x7CB2u    /* 027CB2: bank 13 */
extern const void *indexed_table_027CB2_data;
#define indexed_table_027CB2 ((const uint8_t *)indexed_table_027CB2_data)
#define indexed_table_027CB6_ADDRESS 0x7CB6u    /* 027CB6: bank 13 */
extern const void *indexed_table_027CB6_data;
#define indexed_table_027CB6 ((const uint16_t *)indexed_table_027CB6_data)
#define indexed_table_027D00_ADDRESS 0x7D00u    /* 027D00: bank 13 */
extern const void *indexed_table_027D00_data;
#define indexed_table_027D00 ((const uint8_t *)indexed_table_027D00_data)
#define indexed_table_027D04_ADDRESS 0x7D04u    /* 027D04: bank 13 */
extern const void *indexed_table_027D04_data;
#define indexed_table_027D04 ((const uint8_t *)indexed_table_027D04_data)
#define indexed_table_027D08_ADDRESS 0x7D08u    /* 027D08: bank 13 */
extern const void *indexed_table_027D08_data;
#define indexed_table_027D08 ((const uint8_t *)indexed_table_027D08_data)
#define indexed_table_027D18_ADDRESS 0x7D18u    /* 027D18: bank 13 */
extern const void *indexed_table_027D18_data;
#define indexed_table_027D18 ((const uint8_t *)indexed_table_027D18_data)
#define indexed_table_027D28_ADDRESS 0x7D28u    /* 027D28: bank 13 */
extern const void *indexed_table_027D28_data;
#define indexed_table_027D28 ((const uint16_t *)indexed_table_027D28_data)
#define indexed_table_029A72_ADDRESS 0x7A72u    /* 029A72: bank 14 */
extern const void *indexed_table_029A72_data;
#define indexed_table_029A72 ((const uint16_t *)indexed_table_029A72_data)
#define indexed_table_029B16_ADDRESS 0x7B16u    /* 029B16: bank 14 */
extern const void *indexed_table_029B16_data;
#define indexed_table_029B16 ((const uint16_t *)indexed_table_029B16_data)
#define indexed_table_029BC8_ADDRESS 0x7BC8u    /* 029BC8: bank 14 */
extern const void *indexed_table_029BC8_data;
#define indexed_table_029BC8 ((const uint16_t *)indexed_table_029BC8_data)
#define indexed_table_029BE0_ADDRESS 0x7BE0u    /* 029BE0: bank 14 */
extern const void *indexed_table_029BE0_data;
#define indexed_table_029BE0 ((const uint16_t *)indexed_table_029BE0_data)
#define indexed_table_029C2E_ADDRESS 0x7C2Eu    /* 029C2E: bank 14 */
extern const void *indexed_table_029C2E_data;
#define indexed_table_029C2E ((const uint8_t *)indexed_table_029C2E_data)
#define indexed_table_029C7A_ADDRESS 0x7C7Au    /* 029C7A: bank 14 */
extern const void *indexed_table_029C7A_data;
#define indexed_table_029C7A ((const uint8_t *)indexed_table_029C7A_data)
#define indexed_table_029CA3_ADDRESS 0x7CA3u    /* 029CA3: bank 14 */
extern const void *indexed_table_029CA3_data;
#define indexed_table_029CA3 ((const uint8_t *)indexed_table_029CA3_data)
#define indexed_table_029CD3_ADDRESS 0x7CD3u    /* 029CD3: bank 14 */
extern const void *indexed_table_029CD3_data;
#define indexed_table_029CD3 ((const uint8_t *)indexed_table_029CD3_data)
#define indexed_table_029EE5_ADDRESS 0x7EE5u    /* 029EE5: bank 14 */
extern const void *indexed_table_029EE5_data;
#define indexed_table_029EE5 ((const uint8_t *)indexed_table_029EE5_data)
#define indexed_table_029EF4_ADDRESS 0x7EF4u    /* 029EF4: bank 14 */
extern const void *indexed_table_029EF4_data;
#define indexed_table_029EF4 ((const uint8_t *)indexed_table_029EF4_data)
#define indexed_table_029F9B_ADDRESS 0x7F9Bu    /* 029F9B: bank 14 */
extern const void *indexed_table_029F9B_data;
#define indexed_table_029F9B ((const uint16_t *)indexed_table_029F9B_data)
#define indexed_table_029FAF_ADDRESS 0x7FAFu    /* 029FAF: bank 14 */
extern const void *indexed_table_029FAF_data;
#define indexed_table_029FAF ((const uint16_t *)indexed_table_029FAF_data)
#define indexed_table_029FC3_ADDRESS 0x7FC3u    /* 029FC3: bank 14 */
extern const void *indexed_table_029FC3_data;
#define indexed_table_029FC3 ((const uint16_t *)indexed_table_029FC3_data)
#define indexed_table_02B84A_ADDRESS 0x784Au    /* 02B84A: bank 15 */
extern const void *indexed_table_02B84A_data;
#define indexed_table_02B84A ((const uint16_t *)indexed_table_02B84A_data)
#define indexed_table_02B890_ADDRESS 0x7890u    /* 02B890: bank 15 */
extern const void *indexed_table_02B890_data;
#define indexed_table_02B890 ((const uint16_t *)indexed_table_02B890_data)
#define indexed_table_02B974_ADDRESS 0x7974u    /* 02B974: bank 15 */
extern const void *indexed_table_02B974_data;
#define indexed_table_02B974 ((const uint8_t *)indexed_table_02B974_data)
#define indexed_table_02B995_ADDRESS 0x7995u    /* 02B995: bank 15 */
extern const void *indexed_table_02B995_data;
#define indexed_table_02B995 ((const uint8_t *)indexed_table_02B995_data)
#define indexed_table_02B9A5_ADDRESS 0x79A5u    /* 02B9A5: bank 15 */
extern const void *indexed_table_02B9A5_data;
#define indexed_table_02B9A5 ((const uint16_t *)indexed_table_02B9A5_data)
#define indexed_table_02B9B9_ADDRESS 0x79B9u    /* 02B9B9: bank 15 */
extern const void *indexed_table_02B9B9_data;
#define indexed_table_02B9B9 ((const uint16_t *)indexed_table_02B9B9_data)
#define object_15_times_ADDRESS 0x79F1u    /* 02B9F1: bank 15 */
extern const void *object_15_times_data;
#define object_15_times ((const uint8_t *)object_15_times_data)
#define object_15_spawn_lists_ADDRESS 0x79FEu    /* 02B9FE: bank 15 */
extern const void *object_15_spawn_lists_data;
#define object_15_spawn_lists ((const uint16_t *)object_15_spawn_lists_data)
#define object_15_next_kinds_ADDRESS 0x7A18u    /* 02BA18: bank 15 */
extern const void *object_15_next_kinds_data;
#define object_15_next_kinds ((const uint8_t *)object_15_next_kinds_data)
#define indexed_table_02DB58_ADDRESS 0x7B58u    /* 02DB58: bank 16 */
extern const void *indexed_table_02DB58_data;
#define indexed_table_02DB58 ((const uint16_t *)indexed_table_02DB58_data)
#define loaded_table_02DB68_ADDRESS 0x7B68u    /* 02DB68: bank 16 */
extern const void *loaded_table_02DB68_data;
#define loaded_table_02DB68 ((const uint8_t *)loaded_table_02DB68_data)
#define indexed_table_02DBF2_ADDRESS 0x7BF2u    /* 02DBF2: bank 16 */
extern const void *indexed_table_02DBF2_data;
#define indexed_table_02DBF2 ((const uint8_t *)indexed_table_02DBF2_data)
#define indexed_table_02DC3E_ADDRESS 0x7C3Eu    /* 02DC3E: bank 16 */
extern const void *indexed_table_02DC3E_data;
#define indexed_table_02DC3E ((const uint16_t *)indexed_table_02DC3E_data)
#define indexed_table_02DD83_ADDRESS 0x7D83u    /* 02DD83: bank 16 */
extern const void *indexed_table_02DD83_data;
#define indexed_table_02DD83 ((const uint16_t *)indexed_table_02DD83_data)
#define indexed_table_02DDB1_ADDRESS 0x7DB1u    /* 02DDB1: bank 16 */
extern const void *indexed_table_02DDB1_data;
#define indexed_table_02DDB1 ((const uint8_t *)indexed_table_02DDB1_data)
#define object_16_flags_ADDRESS 0x7E39u    /* 02DE39: bank 16 */
extern const void *object_16_flags_data;
#define object_16_flags ((const uint8_t *)object_16_flags_data)
#define object_16_patterns_ADDRESS 0x7E57u    /* 02DE57: bank 16 */
extern const void *object_16_patterns_data;
#define object_16_patterns ((const uint8_t *)object_16_patterns_data)
#define indexed_table_02DF05_ADDRESS 0x7F05u    /* 02DF05: bank 16 */
extern const void *indexed_table_02DF05_data;
#define indexed_table_02DF05 ((const uint16_t *)indexed_table_02DF05_data)
#define rom_02DFA1_ADDRESS 0x7FA1u    /* 02DFA1: bank 16 */
extern const void *rom_02DFA1_data;
#define rom_02DFA1 ((const uint16_t *)rom_02DFA1_data)
#define indexed_table_02FA70_ADDRESS 0x7A70u    /* 02FA70: bank 17 */
extern const void *indexed_table_02FA70_data;
#define indexed_table_02FA70 ((const uint16_t *)indexed_table_02FA70_data)
#define indexed_table_02FA9C_ADDRESS 0x7A9Cu    /* 02FA9C: bank 17 */
extern const void *indexed_table_02FA9C_data;
#define indexed_table_02FA9C ((const uint16_t *)indexed_table_02FA9C_data)
#define indexed_table_02FACE_ADDRESS 0x7ACEu    /* 02FACE: bank 17 */
extern const void *indexed_table_02FACE_data;
#define indexed_table_02FACE ((const uint8_t *)indexed_table_02FACE_data)
#define indexed_table_02FB00_ADDRESS 0x7B00u    /* 02FB00: bank 17 */
extern const void *indexed_table_02FB00_data;
#define indexed_table_02FB00 ((const uint16_t *)indexed_table_02FB00_data)
#define indexed_table_02FB28_ADDRESS 0x7B28u    /* 02FB28: bank 17 */
extern const void *indexed_table_02FB28_data;
#define indexed_table_02FB28 ((const uint16_t *)indexed_table_02FB28_data)
#define indexed_table_02FB7A_ADDRESS 0x7B7Au    /* 02FB7A: bank 17 */
extern const void *indexed_table_02FB7A_data;
#define indexed_table_02FB7A ((const uint16_t *)indexed_table_02FB7A_data)
#define indexed_table_02FB92_ADDRESS 0x7B92u    /* 02FB92: bank 17 */
extern const void *indexed_table_02FB92_data;
#define indexed_table_02FB92 ((const uint16_t *)indexed_table_02FB92_data)
#define indexed_table_02FBB8_ADDRESS 0x7BB8u    /* 02FBB8: bank 17 */
extern const void *indexed_table_02FBB8_data;
#define indexed_table_02FBB8 ((const uint8_t *)indexed_table_02FBB8_data)
#define indexed_table_02FC9F_ADDRESS 0x7C9Fu    /* 02FC9F: bank 17 */
extern const void *indexed_table_02FC9F_data;
#define indexed_table_02FC9F ((const uint8_t *)indexed_table_02FC9F_data)
#define indexed_table_02FDA2_ADDRESS 0x7DA2u    /* 02FDA2: bank 17 */
extern const void *indexed_table_02FDA2_data;
#define indexed_table_02FDA2 ((const uint8_t *)indexed_table_02FDA2_data)
#define indexed_table_02FE87_ADDRESS 0x7E87u    /* 02FE87: bank 17 */
extern const void *indexed_table_02FE87_data;
#define indexed_table_02FE87 ((const uint8_t *)indexed_table_02FE87_data)
#define indexed_table_02FE8F_ADDRESS 0x7E8Fu    /* 02FE8F: bank 17 */
extern const void *indexed_table_02FE8F_data;
#define indexed_table_02FE8F ((const uint8_t *)indexed_table_02FE8F_data)
#define indexed_table_02FF3B_ADDRESS 0x7F3Bu    /* 02FF3B: bank 17 */
extern const void *indexed_table_02FF3B_data;
#define indexed_table_02FF3B ((const uint8_t *)indexed_table_02FF3B_data)
#define indexed_table_031AF8_ADDRESS 0x7AF8u    /* 031AF8: bank 18 */
extern const void *indexed_table_031AF8_data;
#define indexed_table_031AF8 ((const uint16_t *)indexed_table_031AF8_data)
#define indexed_table_031B0A_ADDRESS 0x7B0Au    /* 031B0A: bank 18 */
extern const void *indexed_table_031B0A_data;
#define indexed_table_031B0A ((const uint8_t *)indexed_table_031B0A_data)
#define indexed_table_031C0C_ADDRESS 0x7C0Cu    /* 031C0C: bank 18 */
extern const void *indexed_table_031C0C_data;
#define indexed_table_031C0C ((const uint8_t *)indexed_table_031C0C_data)
#define indexed_table_031C5D_ADDRESS 0x7C5Du    /* 031C5D: bank 18 */
extern const void *indexed_table_031C5D_data;
#define indexed_table_031C5D ((const uint16_t *)indexed_table_031C5D_data)
#define loaded_table_031D51_ADDRESS 0x7D51u    /* 031D51: bank 18 */
extern const void *loaded_table_031D51_data;
#define loaded_table_031D51 ((const uint16_t *)loaded_table_031D51_data)
#define indexed_table_031DA1_ADDRESS 0x7DA1u    /* 031DA1: bank 18 */
extern const void *indexed_table_031DA1_data;
#define indexed_table_031DA1 ((const uint8_t *)indexed_table_031DA1_data)
#define indexed_table_031DA8_ADDRESS 0x7DA8u    /* 031DA8: bank 18 */
extern const void *indexed_table_031DA8_data;
#define indexed_table_031DA8 ((const uint8_t *)indexed_table_031DA8_data)
#define indexed_table_031DAF_ADDRESS 0x7DAFu    /* 031DAF: bank 18 */
extern const void *indexed_table_031DAF_data;
#define indexed_table_031DAF ((const uint8_t *)indexed_table_031DAF_data)
#define indexed_table_031DB6_ADDRESS 0x7DB6u    /* 031DB6: bank 18 */
extern const void *indexed_table_031DB6_data;
#define indexed_table_031DB6 ((const uint16_t *)indexed_table_031DB6_data)
#define indexed_table_031DD8_ADDRESS 0x7DD8u    /* 031DD8: bank 18 */
extern const void *indexed_table_031DD8_data;
#define indexed_table_031DD8 ((const uint8_t *)indexed_table_031DD8_data)
#define indexed_table_031DDC_ADDRESS 0x7DDCu    /* 031DDC: bank 18 */
extern const void *indexed_table_031DDC_data;
#define indexed_table_031DDC ((const uint8_t *)indexed_table_031DDC_data)
#define indexed_table_031E1C_ADDRESS 0x7E1Cu    /* 031E1C: bank 18 */
extern const void *indexed_table_031E1C_data;
#define indexed_table_031E1C ((const uint8_t *)indexed_table_031E1C_data)
#define indexed_table_031F7A_ADDRESS 0x7F7Au    /* 031F7A: bank 18 */
extern const void *indexed_table_031F7A_data;
#define indexed_table_031F7A ((const uint8_t *)indexed_table_031F7A_data)
#define indexed_table_033A72_ADDRESS 0x7A72u    /* 033A72: bank 19 */
extern const void *indexed_table_033A72_data;
#define indexed_table_033A72 ((const uint8_t *)indexed_table_033A72_data)
#define indexed_table_033AB5_ADDRESS 0x7AB5u    /* 033AB5: bank 19 */
extern const void *indexed_table_033AB5_data;
#define indexed_table_033AB5 ((const uint8_t *)indexed_table_033AB5_data)
#define indexed_table_033BCC_ADDRESS 0x7BCCu    /* 033BCC: bank 19 */
extern const void *indexed_table_033BCC_data;
#define indexed_table_033BCC ((const uint8_t *)indexed_table_033BCC_data)
#define indexed_table_033C16_ADDRESS 0x7C16u    /* 033C16: bank 19 */
extern const void *indexed_table_033C16_data;
#define indexed_table_033C16 ((const uint16_t *)indexed_table_033C16_data)
#define indexed_table_033C3C_ADDRESS 0x7C3Cu    /* 033C3C: bank 19 */
extern const void *indexed_table_033C3C_data;
#define indexed_table_033C3C ((const uint16_t *)indexed_table_033C3C_data)
#define indexed_table_033C76_ADDRESS 0x7C76u    /* 033C76: bank 19 */
extern const void *indexed_table_033C76_data;
#define indexed_table_033C76 ((const uint16_t *)indexed_table_033C76_data)
#define indexed_table_033CB8_ADDRESS 0x7CB8u    /* 033CB8: bank 19 */
extern const void *indexed_table_033CB8_data;
#define indexed_table_033CB8 ((const uint8_t *)indexed_table_033CB8_data)
#define indexed_table_033CC0_ADDRESS 0x7CC0u    /* 033CC0: bank 19 */
extern const void *indexed_table_033CC0_data;
#define indexed_table_033CC0 ((const uint8_t *)indexed_table_033CC0_data)
#define indexed_table_033D22_ADDRESS 0x7D22u    /* 033D22: bank 19 */
extern const void *indexed_table_033D22_data;
#define indexed_table_033D22 ((const uint8_t *)indexed_table_033D22_data)
#define indexed_table_033E32_ADDRESS 0x7E32u    /* 033E32: bank 19 */
extern const void *indexed_table_033E32_data;
#define indexed_table_033E32 ((const uint16_t *)indexed_table_033E32_data)
#define indexed_table_033E86_ADDRESS 0x7E86u    /* 033E86: bank 19 */
extern const void *indexed_table_033E86_data;
#define indexed_table_033E86 ((const uint8_t *)indexed_table_033E86_data)
#define indexed_table_033E8D_ADDRESS 0x7E8Du    /* 033E8D: bank 19 */
extern const void *indexed_table_033E8D_data;
#define indexed_table_033E8D ((const uint8_t *)indexed_table_033E8D_data)
#define indexed_table_033E94_ADDRESS 0x7E94u    /* 033E94: bank 19 */
extern const void *indexed_table_033E94_data;
#define indexed_table_033E94 ((const uint8_t *)indexed_table_033E94_data)
#define indexed_table_033E9B_ADDRESS 0x7E9Bu    /* 033E9B: bank 19 */
extern const void *indexed_table_033E9B_data;
#define indexed_table_033E9B ((const uint16_t *)indexed_table_033E9B_data)
#define indexed_table_033EA9_ADDRESS 0x7EA9u    /* 033EA9: bank 19 */
extern const void *indexed_table_033EA9_data;
#define indexed_table_033EA9 ((const uint16_t *)indexed_table_033EA9_data)
#define indexed_table_033EC7_ADDRESS 0x7EC7u    /* 033EC7: bank 19 */
extern const void *indexed_table_033EC7_data;
#define indexed_table_033EC7 ((const uint16_t *)indexed_table_033EC7_data)
#define indexed_table_033EEF_ADDRESS 0x7EEFu    /* 033EEF: bank 19 */
extern const void *indexed_table_033EEF_data;
#define indexed_table_033EEF ((const uint16_t *)indexed_table_033EEF_data)
#define indexed_table_033F0D_ADDRESS 0x7F0Du    /* 033F0D: bank 19 */
extern const void *indexed_table_033F0D_data;
#define indexed_table_033F0D ((const uint8_t *)indexed_table_033F0D_data)
#define indexed_table_033F11_ADDRESS 0x7F11u    /* 033F11: bank 19 */
extern const void *indexed_table_033F11_data;
#define indexed_table_033F11 ((const uint8_t *)indexed_table_033F11_data)
#define indexed_table_033F51_ADDRESS 0x7F51u    /* 033F51: bank 19 */
extern const void *indexed_table_033F51_data;
#define indexed_table_033F51 ((const uint8_t *)indexed_table_033F51_data)
#define indexed_table_033FE3_ADDRESS 0x7FE3u    /* 033FE3: bank 19 */
extern const void *indexed_table_033FE3_data;
#define indexed_table_033FE3 ((const uint8_t *)indexed_table_033FE3_data)
#define indexed_table_033FE9_ADDRESS 0x7FE9u    /* 033FE9: bank 19 */
extern const void *indexed_table_033FE9_data;
#define indexed_table_033FE9 ((const uint16_t *)indexed_table_033FE9_data)
#define unused_tile_places_ADDRESS 0x76E5u    /* 0356E5: bank 1A */
extern const void *unused_tile_places_data;
#define unused_tile_places ((const uint8_t *)unused_tile_places_data)
#define unused_text_0356FE_ADDRESS 0x76FEu    /* 0356FE: bank 1A */
extern const void *unused_text_0356FE_data;
#define unused_text_0356FE ((const uint8_t *)unused_text_0356FE_data)
#define unused_text_035744_ADDRESS 0x7744u    /* 035744: bank 1A */
extern const void *unused_text_035744_data;
#define unused_text_035744 ((const uint8_t *)unused_text_035744_data)
#define object_1a_levels_ADDRESS 0x7754u    /* 035754: bank 1A */
extern const void *object_1a_levels_data;
#define object_1a_levels ((const uint8_t *)object_1a_levels_data)
#define object_1a_next_states_ADDRESS 0x77BCu    /* 0357BC: bank 1A */
extern const void *object_1a_next_states_data;
#define object_1a_next_states ((const uint8_t *)object_1a_next_states_data)
#define object_1a_states_after_ADDRESS 0x77C1u    /* 0357C1: bank 1A */
extern const void *object_1a_states_after_data;
#define object_1a_states_after ((const uint8_t *)object_1a_states_after_data)
#define object_1a_level_rows_ADDRESS 0x77C6u    /* 0357C6: bank 1A */
extern const void *object_1a_level_rows_data;
#define object_1a_level_rows ((const uint16_t *)object_1a_level_rows_data)
#define indexed_table_0357FE_ADDRESS 0x77FEu    /* 0357FE: bank 1A */
extern const void *indexed_table_0357FE_data;
#define indexed_table_0357FE ((const uint8_t *)indexed_table_0357FE_data)
#define indexed_table_03582A_ADDRESS 0x782Au    /* 03582A: bank 1A */
extern const void *indexed_table_03582A_data;
#define indexed_table_03582A ((const uint8_t *)indexed_table_03582A_data)
#define indexed_table_035832_ADDRESS 0x7832u    /* 035832: bank 1A */
extern const void *indexed_table_035832_data;
#define indexed_table_035832 ((const uint8_t *)indexed_table_035832_data)
#define indexed_table_03583A_ADDRESS 0x783Au    /* 03583A: bank 1A */
extern const void *indexed_table_03583A_data;
#define indexed_table_03583A ((const uint8_t *)indexed_table_03583A_data)
#define indexed_table_03584E_ADDRESS 0x784Eu    /* 03584E: bank 1A */
extern const void *indexed_table_03584E_data;
#define indexed_table_03584E ((const uint8_t *)indexed_table_03584E_data)
#define indexed_table_03585E_ADDRESS 0x785Eu    /* 03585E: bank 1A */
extern const void *indexed_table_03585E_data;
#define indexed_table_03585E ((const uint8_t *)indexed_table_03585E_data)
#define indexed_table_0358A0_ADDRESS 0x78A0u    /* 0358A0: bank 1A */
extern const void *indexed_table_0358A0_data;
#define indexed_table_0358A0 ((const uint8_t *)indexed_table_0358A0_data)
#define indexed_table_0358C8_ADDRESS 0x78C8u    /* 0358C8: bank 1A */
extern const void *indexed_table_0358C8_data;
#define indexed_table_0358C8 ((const uint8_t *)indexed_table_0358C8_data)
#define indexed_table_0358EC_ADDRESS 0x78ECu    /* 0358EC: bank 1A */
extern const void *indexed_table_0358EC_data;
#define indexed_table_0358EC ((const uint16_t *)indexed_table_0358EC_data)
#define unused_words_035934_ADDRESS 0x7934u    /* 035934: bank 1A */
extern const void *unused_words_035934_data;
#define unused_words_035934 ((const uint16_t *)unused_words_035934_data)
#define loaded_table_0359A6_ADDRESS 0x79A6u    /* 0359A6: bank 1A */
extern const void *loaded_table_0359A6_data;
#define loaded_table_0359A6 ((const uint16_t *)loaded_table_0359A6_data)
#define object_1a_path_choices_ADDRESS 0x79DCu    /* 0359DC: bank 1A */
extern const void *object_1a_path_choices_data;
#define object_1a_path_choices ((const uint8_t *)object_1a_path_choices_data)
#define object_1a_path_times_ADDRESS 0x79F0u    /* 0359F0: bank 1A */
extern const void *object_1a_path_times_data;
#define object_1a_path_times ((const uint8_t *)object_1a_path_times_data)
#define indexed_table_035FA3_ADDRESS 0x7FA3u    /* 035FA3: bank 1A */
extern const void *indexed_table_035FA3_data;
#define indexed_table_035FA3 ((const uint8_t *)indexed_table_035FA3_data)
#define spawn_lists_ADDRESS 0x6000u    /* 036000: bank 1B */
extern const void *spawn_lists_data;
#define spawn_lists ((const uint16_t *)spawn_lists_data)
#define indexed_table_036454_ADDRESS 0x6454u    /* 036454: bank 1B */
extern const void *indexed_table_036454_data;
#define indexed_table_036454 ((const uint16_t *)indexed_table_036454_data)
#define indexed_table_039DD5_ADDRESS 0x7DD5u    /* 039DD5: bank 1C */
extern const void *indexed_table_039DD5_data;
#define indexed_table_039DD5 ((const uint8_t *)indexed_table_039DD5_data)
#define object_1c_move_steps_ADDRESS 0x7DEBu    /* 039DEB: bank 1C */
extern const void *object_1c_move_steps_data;
#define object_1c_move_steps ((const uint8_t *)object_1c_move_steps_data)
#define object_1c_moves_ADDRESS 0x7DF7u    /* 039DF7: bank 1C */
extern const void *object_1c_moves_data;
#define object_1c_moves ((const uint16_t *)object_1c_moves_data)
#define indexed_table_039E3D_ADDRESS 0x7E3Du    /* 039E3D: bank 1C */
extern const void *indexed_table_039E3D_data;
#define indexed_table_039E3D ((const uint8_t *)indexed_table_039E3D_data)
#define indexed_table_039EAD_ADDRESS 0x7EADu    /* 039EAD: bank 1C */
extern const void *indexed_table_039EAD_data;
#define indexed_table_039EAD ((const uint8_t *)indexed_table_039EAD_data)
#define indexed_table_039F21_ADDRESS 0x7F21u    /* 039F21: bank 1C */
extern const void *indexed_table_039F21_data;
#define indexed_table_039F21 ((const uint16_t *)indexed_table_039F21_data)
#define indexed_table_039F99_ADDRESS 0x7F99u    /* 039F99: bank 1C */
extern const void *indexed_table_039F99_data;
#define indexed_table_039F99 ((const uint16_t *)indexed_table_039F99_data)
#define indexed_table_039FD1_ADDRESS 0x7FD1u    /* 039FD1: bank 1C */
extern const void *indexed_table_039FD1_data;
#define indexed_table_039FD1 ((const uint8_t *)indexed_table_039FD1_data)
#define zoom_steps_address_ADDRESS 0x602Au    /* 03A02A: bank 1D */
extern const void *zoom_steps_address_data;
#define zoom_steps_address ((const uint16_t *)zoom_steps_address_data)
#define indexed_table_03BAA5_ADDRESS 0x7AA5u    /* 03BAA5: bank 1D */
extern const void *indexed_table_03BAA5_data;
#define indexed_table_03BAA5 ((const uint8_t *)indexed_table_03BAA5_data)
#define indexed_table_03BAA9_ADDRESS 0x7AA9u    /* 03BAA9: bank 1D */
extern const void *indexed_table_03BAA9_data;
#define indexed_table_03BAA9 ((const uint8_t *)indexed_table_03BAA9_data)
#define indexed_table_03BAAD_ADDRESS 0x7AADu    /* 03BAAD: bank 1D */
extern const void *indexed_table_03BAAD_data;
#define indexed_table_03BAAD ((const uint8_t *)indexed_table_03BAAD_data)
#define value_03BAB1_ADDRESS 0x7AB1u    /* 03BAB1: bank 1D */
extern const void *value_03BAB1_data;
#define value_03BAB1 (*(const uint16_t *)value_03BAB1_data)
#define indexed_table_03BAB5_ADDRESS 0x7AB5u    /* 03BAB5: bank 1D */
extern const void *indexed_table_03BAB5_data;
#define indexed_table_03BAB5 ((const uint8_t *)indexed_table_03BAB5_data)
#define indexed_table_03BAB9_ADDRESS 0x7AB9u    /* 03BAB9: bank 1D */
extern const void *indexed_table_03BAB9_data;
#define indexed_table_03BAB9 ((const uint8_t *)indexed_table_03BAB9_data)
#define indexed_table_03BAC1_ADDRESS 0x7AC1u    /* 03BAC1: bank 1D */
extern const void *indexed_table_03BAC1_data;
#define indexed_table_03BAC1 ((const uint8_t *)indexed_table_03BAC1_data)
#define indexed_table_03BAC5_ADDRESS 0x7AC5u    /* 03BAC5: bank 1D */
extern const void *indexed_table_03BAC5_data;
#define indexed_table_03BAC5 ((const uint8_t *)indexed_table_03BAC5_data)
#define indexed_table_03BAC9_ADDRESS 0x7AC9u    /* 03BAC9: bank 1D */
extern const void *indexed_table_03BAC9_data;
#define indexed_table_03BAC9 ((const uint8_t *)indexed_table_03BAC9_data)
#define indexed_table_03BACD_ADDRESS 0x7ACDu    /* 03BACD: bank 1D */
extern const void *indexed_table_03BACD_data;
#define indexed_table_03BACD ((const uint8_t *)indexed_table_03BACD_data)
#define indexed_table_03BAD1_ADDRESS 0x7AD1u    /* 03BAD1: bank 1D */
extern const void *indexed_table_03BAD1_data;
#define indexed_table_03BAD1 ((const uint8_t *)indexed_table_03BAD1_data)
#define indexed_table_03BB5A_ADDRESS 0x7B5Au    /* 03BB5A: bank 1D */
extern const void *indexed_table_03BB5A_data;
#define indexed_table_03BB5A ((const uint8_t *)indexed_table_03BB5A_data)
#define indexed_table_03BB76_ADDRESS 0x7B76u    /* 03BB76: bank 1D */
extern const void *indexed_table_03BB76_data;
#define indexed_table_03BB76 ((const uint16_t *)indexed_table_03BB76_data)
#define indexed_table_03BB80_ADDRESS 0x7B80u    /* 03BB80: bank 1D */
extern const void *indexed_table_03BB80_data;
#define indexed_table_03BB80 ((const uint8_t *)indexed_table_03BB80_data)
#define indexed_table_03BB85_ADDRESS 0x7B85u    /* 03BB85: bank 1D */
extern const void *indexed_table_03BB85_data;
#define indexed_table_03BB85 ((const uint16_t *)indexed_table_03BB85_data)
#define indexed_table_03BBA3_ADDRESS 0x7BA3u    /* 03BBA3: bank 1D */
extern const void *indexed_table_03BBA3_data;
#define indexed_table_03BBA3 ((const uint8_t *)indexed_table_03BBA3_data)
#define indexed_table_03BBA7_ADDRESS 0x7BA7u    /* 03BBA7: bank 1D */
extern const void *indexed_table_03BBA7_data;
#define indexed_table_03BBA7 ((const uint16_t *)indexed_table_03BBA7_data)
#define indexed_table_03BBC7_ADDRESS 0x7BC7u    /* 03BBC7: bank 1D */
extern const void *indexed_table_03BBC7_data;
#define indexed_table_03BBC7 ((const uint16_t *)indexed_table_03BBC7_data)
#define indexed_table_03BBE7_ADDRESS 0x7BE7u    /* 03BBE7: bank 1D */
extern const void *indexed_table_03BBE7_data;
#define indexed_table_03BBE7 ((const uint16_t *)indexed_table_03BBE7_data)
#define indexed_table_03BBF9_ADDRESS 0x7BF9u    /* 03BBF9: bank 1D */
extern const void *indexed_table_03BBF9_data;
#define indexed_table_03BBF9 ((const uint16_t *)indexed_table_03BBF9_data)
#define indexed_table_03BC65_ADDRESS 0x7C65u    /* 03BC65: bank 1D */
extern const void *indexed_table_03BC65_data;
#define indexed_table_03BC65 ((const uint16_t *)indexed_table_03BC65_data)
#define indexed_table_03BCD7_ADDRESS 0x7CD7u    /* 03BCD7: bank 1D */
extern const void *indexed_table_03BCD7_data;
#define indexed_table_03BCD7 ((const uint16_t *)indexed_table_03BCD7_data)
#define zoom_steps_ADDRESS 0x7DE7u    /* 03BDE7: bank 1D */
extern const void *zoom_steps_data;
#define zoom_steps ((const uint16_t *)zoom_steps_data)
#define indexed_table_03D8B5_ADDRESS 0x78B5u    /* 03D8B5: bank 1E */
extern const void *indexed_table_03D8B5_data;
#define indexed_table_03D8B5 ((const uint16_t *)indexed_table_03D8B5_data)
#define rom_03DDA5_ADDRESS 0x7DA5u    /* 03DDA5: bank 1E */
extern const void *rom_03DDA5_data;
#define rom_03DDA5 ((const uint8_t *)rom_03DDA5_data)
#define indexed_table_03DDAA_ADDRESS 0x7DAAu    /* 03DDAA: bank 1E */
extern const void *indexed_table_03DDAA_data;
#define indexed_table_03DDAA ((const uint8_t *)indexed_table_03DDAA_data)
#define rom_03DE63_ADDRESS 0x7E63u    /* 03DE63: bank 1E */
extern const void *rom_03DE63_data;
#define rom_03DE63 ((const uint8_t *)rom_03DE63_data)
#define indexed_table_03DE80_ADDRESS 0x7E80u    /* 03DE80: bank 1E */
extern const void *indexed_table_03DE80_data;
#define indexed_table_03DE80 ((const uint16_t *)indexed_table_03DE80_data)
#define rom_03DF35_ADDRESS 0x7F35u    /* 03DF35: bank 1E */
extern const void *rom_03DF35_data;
#define rom_03DF35 ((const uint8_t *)rom_03DF35_data)
#define indexed_table_03DF39_ADDRESS 0x7F39u    /* 03DF39: bank 1E */
extern const void *indexed_table_03DF39_data;
#define indexed_table_03DF39 ((const uint8_t *)indexed_table_03DF39_data)
#define story_scripts_ADDRESS 0x7078u    /* 03F078: bank 1F */
extern const void *story_scripts_data;
#define story_scripts ((const uint16_t *)story_scripts_data)
#define indexed_table_03FE77_ADDRESS 0x7E77u    /* 03FE77: bank 1F */
extern const void *indexed_table_03FE77_data;
#define indexed_table_03FE77 ((const uint8_t *)indexed_table_03FE77_data)
#define indexed_table_03FE7B_ADDRESS 0x7E7Bu    /* 03FE7B: bank 1F */
extern const void *indexed_table_03FE7B_data;
#define indexed_table_03FE7B ((const uint8_t *)indexed_table_03FE7B_data)
#define indexed_table_03FE7F_ADDRESS 0x7E7Fu    /* 03FE7F: bank 1F */
extern const void *indexed_table_03FE7F_data;
#define indexed_table_03FE7F ((const uint8_t *)indexed_table_03FE7F_data)
#define indexed_table_03FE84_ADDRESS 0x7E84u    /* 03FE84: bank 1F */
extern const void *indexed_table_03FE84_data;
#define indexed_table_03FE84 ((const uint8_t *)indexed_table_03FE84_data)
#define indexed_table_03FE94_ADDRESS 0x7E94u    /* 03FE94: bank 1F */
extern const void *indexed_table_03FE94_data;
#define indexed_table_03FE94 ((const uint8_t *)indexed_table_03FE94_data)
#define indexed_table_0410E3_ADDRESS 0x70E3u    /* 0410E3: bank 20 */
extern const void *indexed_table_0410E3_data;
#define indexed_table_0410E3 ((const uint16_t *)indexed_table_0410E3_data)
#define profile_texts_ADDRESS 0x7106u    /* 041106: bank 20 */
extern const void *profile_texts_data;
#define profile_texts ((const uint16_t *)profile_texts_data)
#define gauge_player_records_ADDRESS 0x7294u    /* 041294: bank 20 */
extern const void *gauge_player_records_data;
#define gauge_player_records ((const uint16_t *)gauge_player_records_data)
#define gauge_step_tiles_ADDRESS 0x72FCu    /* 0412FC: bank 20 */
extern const void *gauge_step_tiles_data;
#define gauge_step_tiles ((const uint8_t *)gauge_step_tiles_data)
#define indexed_table_04130E_ADDRESS 0x730Eu    /* 04130E: bank 20 */
extern const void *indexed_table_04130E_data;
#define indexed_table_04130E ((const uint8_t *)indexed_table_04130E_data)
#define indexed_table_041316_ADDRESS 0x7316u    /* 041316: bank 20 */
extern const void *indexed_table_041316_data;
#define indexed_table_041316 ((const uint16_t *)indexed_table_041316_data)
#define indexed_table_0413F1_ADDRESS 0x73F1u    /* 0413F1: bank 20 */
extern const void *indexed_table_0413F1_data;
#define indexed_table_0413F1 ((const uint16_t *)indexed_table_0413F1_data)
#define rank_base_ADDRESS 0x7782u    /* 041782: bank 20 */
extern const void *rank_base_data;
#define rank_base ((const uint8_t *)rank_base_data)
#define rank_by_players_ADDRESS 0x7786u    /* 041786: bank 20 */
extern const void *rank_by_players_data;
#define rank_by_players ((const uint8_t *)rank_by_players_data)
#define rank_by_scene_ADDRESS 0x778Au    /* 04178A: bank 20 */
extern const void *rank_by_scene_data;
#define rank_by_scene ((const uint8_t *)rank_by_scene_data)
#define rank_step_times_ADDRESS 0x7796u    /* 041796: bank 20 */
extern const void *rank_step_times_data;
#define rank_step_times ((const uint16_t *)rank_step_times_data)
#define rank_frame_limits_ADDRESS 0x77ACu    /* 0417AC: bank 20 */
extern const void *rank_frame_limits_data;
#define rank_frame_limits ((const uint16_t *)rank_frame_limits_data)
#define indexed_table_05E502_ADDRESS 0x6502u    /* 05E502: bank 2F */
extern const void *indexed_table_05E502_data;
#define indexed_table_05E502 ((const uint8_t *)indexed_table_05E502_data)
#define sound_test_effects_ADDRESS 0x6739u    /* 05E739: bank 2F */
extern const void *sound_test_effects_data;
#define sound_test_effects ((const uint16_t *)sound_test_effects_data)
#define sound_test_music_ADDRESS 0x688Fu    /* 05E88F: bank 2F */
extern const void *sound_test_music_data;
#define sound_test_music ((const uint16_t *)sound_test_music_data)
#define indexed_table_05F5AE_ADDRESS 0x75AEu    /* 05F5AE: bank 2F */
extern const void *indexed_table_05F5AE_data;
#define indexed_table_05F5AE ((const uint8_t *)indexed_table_05F5AE_data)
#define test_mode_texts_ADDRESS 0x75BEu    /* 05F5BE: bank 2F */
extern const void *test_mode_texts_data;
#define test_mode_texts ((const uint16_t *)test_mode_texts_data)
#define test_mode_words_ADDRESS 0x78F7u    /* 05F8F7: bank 2F */
extern const void *test_mode_words_data;
#define test_mode_words ((const uint16_t *)test_mode_words_data)
#define rom_05FA5D_ADDRESS 0x7A5Du    /* 05FA5D: bank 2F */
extern const void *rom_05FA5D_data;
#define rom_05FA5D ((const uint8_t *)rom_05FA5D_data)
#define rom_05FA6F_ADDRESS 0x7A6Fu    /* 05FA6F: bank 2F */
extern const void *rom_05FA6F_data;
#define rom_05FA6F ((const uint8_t *)rom_05FA6F_data)
#define indexed_table_05FCA7_ADDRESS 0x7CA7u    /* 05FCA7: bank 2F */
extern const void *indexed_table_05FCA7_data;
#define indexed_table_05FCA7 (*(const uint8_t *)indexed_table_05FCA7_data)
#define indexed_table_05FCB6_ADDRESS 0x7CB6u    /* 05FCB6: bank 2F */
extern const void *indexed_table_05FCB6_data;
#define indexed_table_05FCB6 (*(const uint8_t *)indexed_table_05FCB6_data)
#define indexed_table_05FCCB_ADDRESS 0x7CCBu    /* 05FCCB: bank 2F */
extern const void *indexed_table_05FCCB_data;
#define indexed_table_05FCCB (*(const uint8_t *)indexed_table_05FCCB_data)
#define indexed_table_05FD5C_ADDRESS 0x7D5Cu    /* 05FD5C: bank 2F */
extern const void *indexed_table_05FD5C_data;
#define indexed_table_05FD5C ((const uint16_t *)indexed_table_05FD5C_data)
#define indexed_table_05FD68_ADDRESS 0x7D68u    /* 05FD68: bank 2F */
extern const void *indexed_table_05FD68_data;
#define indexed_table_05FD68 ((const uint16_t *)indexed_table_05FD68_data)
#define indexed_table_05FD74_ADDRESS 0x7D74u    /* 05FD74: bank 2F */
extern const void *indexed_table_05FD74_data;
#define indexed_table_05FD74 ((const uint8_t *)indexed_table_05FD74_data)
#define test_player_records_ADDRESS 0x7D88u    /* 05FD88: bank 2F */
extern const void *test_player_records_data;
#define test_player_records ((const uint16_t *)test_player_records_data)
#define indexed_table_07BADA_ADDRESS 0xBADAu    /* 07BADA: the fixed program */
extern const void *indexed_table_07BADA_data;
#define indexed_table_07BADA ((const uint16_t *)indexed_table_07BADA_data)
#define rom_07E000_ADDRESS 0xE000u    /* 07E000: the fixed program */
extern const void *rom_07E000_data;
#define rom_07E000 ((const uint8_t *)rom_07E000_data)
#define rom_07E001_ADDRESS 0xE001u    /* 07E001: the fixed program */
extern const void *rom_07E001_data;
#define rom_07E001 ((const uint8_t *)rom_07E001_data)
#define rom_07E026_ADDRESS 0xE026u    /* 07E026: the fixed program */
extern const void *rom_07E026_data;
#define rom_07E026 ((const uint16_t *)rom_07E026_data)
#define rom_07E040_ADDRESS 0xE040u    /* 07E040: the fixed program */
extern const void *rom_07E040_data;
#define rom_07E040 ((const uint8_t *)rom_07E040_data)
#define rom_07E041_ADDRESS 0xE041u    /* 07E041: the fixed program */
extern const void *rom_07E041_data;
#define rom_07E041 ((const uint8_t *)rom_07E041_data)
#define indexed_table_07E3EB_ADDRESS 0xE3EBu    /* 07E3EB: the fixed program */
extern const void *indexed_table_07E3EB_data;
#define indexed_table_07E3EB ((const uint8_t *)indexed_table_07E3EB_data)
#define value_07E423_ADDRESS 0xE423u    /* 07E423: the fixed program */
extern const void *value_07E423_data;
#define value_07E423 (*(const uint16_t *)value_07E423_data)
#define value_07E425_ADDRESS 0xE425u    /* 07E425: the fixed program */
extern const void *value_07E425_data;
#define value_07E425 (*(const uint16_t *)value_07E425_data)
#define value_07E427_ADDRESS 0xE427u    /* 07E427: the fixed program */
extern const void *value_07E427_data;
#define value_07E427 (*(const uint16_t *)value_07E427_data)
#define value_07E429_ADDRESS 0xE429u    /* 07E429: the fixed program */
extern const void *value_07E429_data;
#define value_07E429 (*(const uint16_t *)value_07E429_data)
#define indexed_table_07E435_ADDRESS 0xE435u    /* 07E435: the fixed program */
extern const void *indexed_table_07E435_data;
#define indexed_table_07E435 ((const uint8_t *)indexed_table_07E435_data)
#define indexed_table_07E449_ADDRESS 0xE449u    /* 07E449: the fixed program */
extern const void *indexed_table_07E449_data;
#define indexed_table_07E449 ((const uint16_t *)indexed_table_07E449_data)
#define indexed_table_07E526_ADDRESS 0xE526u    /* 07E526: the fixed program */
extern const void *indexed_table_07E526_data;
#define indexed_table_07E526 ((const uint16_t *)indexed_table_07E526_data)
#define indexed_table_07E574_ADDRESS 0xE574u    /* 07E574: the fixed program */
extern const void *indexed_table_07E574_data;
#define indexed_table_07E574 ((const uint8_t *)indexed_table_07E574_data)
#define demos_ADDRESS 0xE6A1u    /* 07E6A1: the fixed program */
extern const void *demos_data;
#define demos ((const uint16_t *)demos_data)
#define player_records_ADDRESS 0xE819u    /* 07E819: the fixed program */
extern const void *player_records_data;
#define player_records ((const uint16_t *)player_records_data)
#define indexed_table_07E88D_ADDRESS 0xE88Du    /* 07E88D: the fixed program */
extern const void *indexed_table_07E88D_data;
#define indexed_table_07E88D ((const uint8_t *)indexed_table_07E88D_data)
#define palette_sets_ADDRESS 0xE9CBu    /* 07E9CB: the fixed program */
extern const void *palette_sets_data;
#define palette_sets ((const uint16_t *)palette_sets_data)
#define palette_sets_high_ADDRESS 0xEAEBu    /* 07EAEB: the fixed program */
extern const void *palette_sets_high_data;
#define palette_sets_high ((const uint16_t *)palette_sets_high_data)
#define layer_maps_ADDRESS 0xEC9Du    /* 07EC9D: the fixed program */
extern const void *layer_maps_data;
#define layer_maps ((const uint16_t *)layer_maps_data)
#define block_scenes_a_ADDRESS 0xECC9u    /* 07ECC9: the fixed program */
extern const void *block_scenes_a_data;
#define block_scenes_a ((const uint16_t *)block_scenes_a_data)
#define block_scenes_b_ADDRESS 0xECE9u    /* 07ECE9: the fixed program */
extern const void *block_scenes_b_data;
#define block_scenes_b ((const uint16_t *)block_scenes_b_data)
#define map_scenes_a_ADDRESS 0xECF9u    /* 07ECF9: the fixed program */
extern const void *map_scenes_a_data;
#define map_scenes_a ((const uint16_t *)map_scenes_a_data)
#define map_scenes_b_ADDRESS 0xED19u    /* 07ED19: the fixed program */
extern const void *map_scenes_b_data;
#define map_scenes_b ((const uint16_t *)map_scenes_b_data)
#define block_scenes_a_high_ADDRESS 0xED29u    /* 07ED29: the fixed program */
extern const void *block_scenes_a_high_data;
#define block_scenes_a_high ((const uint16_t *)block_scenes_a_high_data)
#define block_scenes_b_high_ADDRESS 0xEDBBu    /* 07EDBB: the fixed program */
extern const void *block_scenes_b_high_data;
#define block_scenes_b_high ((const uint16_t *)block_scenes_b_high_data)
#define map_scenes_a_high_ADDRESS 0xEE41u    /* 07EE41: the fixed program */
extern const void *map_scenes_a_high_data;
#define map_scenes_a_high ((const uint16_t *)map_scenes_a_high_data)
#define map_scenes_b_high_ADDRESS 0xEED3u    /* 07EED3: the fixed program */
extern const void *map_scenes_b_high_data;
#define map_scenes_b_high ((const uint16_t *)map_scenes_b_high_data)
#define layer_modes_ADDRESS 0xEF55u    /* 07EF55: the fixed program */
extern const void *layer_modes_data;
#define layer_modes ((const uint16_t *)layer_modes_data)
#define layer_modes_high_ADDRESS 0xEF63u    /* 07EF63: the fixed program */
extern const void *layer_modes_high_data;
#define layer_modes_high ((const uint16_t *)layer_modes_high_data)
#define tile_pictures_ADDRESS 0xEFB5u    /* 07EFB5: the fixed program */
extern const void *tile_pictures_data;
#define tile_pictures ((const uint16_t *)tile_pictures_data)
#define spawn_list_places_ADDRESS 0xEFBCu    /* 07EFBC: the fixed program */
extern const void *spawn_list_places_data;
#define spawn_list_places ((const uint16_t *)spawn_list_places_data)
#define spawn_ranges_ADDRESS 0xEFD4u    /* 07EFD4: the fixed program */
extern const void *spawn_ranges_data;
#define spawn_ranges ((const uint8_t *)spawn_ranges_data)
#define object_list_sizes_ADDRESS 0xEFF4u    /* 07EFF4: the fixed program */
extern const void *object_list_sizes_data;
#define object_list_sizes ((const uint8_t *)object_list_sizes_data)
#define object_lists_ADDRESS 0xEFF8u    /* 07EFF8: the fixed program */
extern const void *object_lists_data;
#define object_lists ((const uint16_t *)object_lists_data)
#define indexed_table_07F000_ADDRESS 0xF000u    /* 07F000: the fixed program */
extern const void *indexed_table_07F000_data;
#define indexed_table_07F000 ((const uint8_t *)indexed_table_07F000_data)
#define indexed_table_07F008_ADDRESS 0xF008u    /* 07F008: the fixed program */
extern const void *indexed_table_07F008_data;
#define indexed_table_07F008 ((const uint8_t *)indexed_table_07F008_data)
#define indexed_table_07F014_ADDRESS 0xF014u    /* 07F014: the fixed program */
extern const void *indexed_table_07F014_data;
#define indexed_table_07F014 ((const uint8_t *)indexed_table_07F014_data)
#define loaded_table_07F031_ADDRESS 0xF031u    /* 07F031: the fixed program */
extern const void *loaded_table_07F031_data;
#define loaded_table_07F031 ((const uint8_t *)loaded_table_07F031_data)
#define rom_07F0E3_ADDRESS 0xF0E3u    /* 07F0E3: the fixed program */
extern const void *rom_07F0E3_data;
#define rom_07F0E3 ((const uint8_t *)rom_07F0E3_data)
#define indexed_table_07F124_ADDRESS 0xF124u    /* 07F124: the fixed program */
extern const void *indexed_table_07F124_data;
#define indexed_table_07F124 ((const uint8_t *)indexed_table_07F124_data)
#define indexed_table_07F387_ADDRESS 0xF387u    /* 07F387: the fixed program */
extern const void *indexed_table_07F387_data;
#define indexed_table_07F387 ((const uint8_t *)indexed_table_07F387_data)
#define indexed_table_07F4B0_ADDRESS 0xF4B0u    /* 07F4B0: the fixed program */
extern const void *indexed_table_07F4B0_data;
#define indexed_table_07F4B0 ((const uint8_t *)indexed_table_07F4B0_data)
#define indexed_table_07F54C_ADDRESS 0xF54Cu    /* 07F54C: the fixed program */
extern const void *indexed_table_07F54C_data;
#define indexed_table_07F54C ((const uint8_t *)indexed_table_07F54C_data)
#define indexed_table_07F581_ADDRESS 0xF581u    /* 07F581: the fixed program */
extern const void *indexed_table_07F581_data;
#define indexed_table_07F581 ((const uint8_t *)indexed_table_07F581_data)
#define indexed_table_07F620_ADDRESS 0xF620u    /* 07F620: the fixed program */
extern const void *indexed_table_07F620_data;
#define indexed_table_07F620 ((const uint8_t *)indexed_table_07F620_data)
#define indexed_table_07F661_ADDRESS 0xF661u    /* 07F661: the fixed program */
extern const void *indexed_table_07F661_data;
#define indexed_table_07F661 ((const uint8_t *)indexed_table_07F661_data)
#define block_tile_flags_ADDRESS 0xF67Cu    /* 07F67C: the fixed program */
extern const void *block_tile_flags_data;
#define block_tile_flags ((const uint8_t *)block_tile_flags_data)
#define rom_07FAC1_ADDRESS 0xFAC1u    /* 07FAC1: the fixed program */
extern const void *rom_07FAC1_data;
#define rom_07FAC1 ((const uint8_t *)rom_07FAC1_data)
#define rom_07FFA0_ADDRESS 0xFFA0u    /* 07FFA0: the fixed program */
extern const void *rom_07FFA0_data;
#define rom_07FFA0 ((const uint8_t *)rom_07FFA0_data)
#define rom_07FFA4_ADDRESS 0xFFA4u    /* 07FFA4: the fixed program */
extern const void *rom_07FFA4_data;
#define rom_07FFA4 ((const uint8_t *)rom_07FFA4_data)
#define rom_07FFC0_ADDRESS 0xFFC0u    /* 07FFC0: the fixed program */
extern const void *rom_07FFC0_data;
#define rom_07FFC0 ((const uint8_t *)rom_07FFC0_data)
#define rom_07FFF8_ADDRESS 0xFFF8u    /* 07FFF8: the fixed program */
extern const void *rom_07FFF8_data;
#define rom_07FFF8 ((const uint16_t *)rom_07FFF8_data)
#define rom_07FFFD_ADDRESS 0xFFFDu    /* 07FFFD: the fixed program */
extern const void *rom_07FFFD_data;
#define rom_07FFFD ((const uint8_t *)rom_07FFFD_data)
#define rom_07FFFE_ADDRESS 0xFFFEu    /* 07FFFE: the fixed program */
extern const void *rom_07FFFE_data;
#define rom_07FFFE ((const uint16_t *)rom_07FFFE_data)

/* the board's registers (read and written through the bus) */
#define VIDEO_0000 0x0000u
#define VIDEO_002F 0x002Fu
#define VIDEO_0031 0x0031u
#define VIDEO_003C 0x003Cu
#define VIDEO_00A0 0x00A0u
#define VIDEO_00C0 0x00C0u
#define VIDEO_0C00 0x0C00u
#define VIDEO_180C 0x180Cu
#define VIDEO_1840 0x1840u
#define VIDEO_1841 0x1841u
#define VIDEO_1842 0x1842u
#define VIDEO_1844 0x1844u
#define VIDEO_1845 0x1845u
#define VIDEO_1846 0x1846u
#define VIDEO_1848 0x1848u
#define VIDEO_184A 0x184Au
#define VIDEO_184B 0x184Bu
#define VIDEO_184C 0x184Cu
#define VIDEO_184D 0x184Du
#define VIDEO_184E 0x184Eu
#define VIDEO_1850 0x1850u
#define VIDEO_1852 0x1852u
#define VIDEO_1854 0x1854u
#define VIDEO_1856 0x1856u
#define VIDEO_1858 0x1858u
#define VIDEO_185A 0x185Au
#define VIDEO_1860 0x1860u
#define VIDEO_1870 0x1870u
#define VIDEO_1872 0x1872u
#define VIDEO_1874 0x1874u
#define VIDEO_1876 0x1876u
#define VIDEO_1877 0x1877u
#define VIDEO_1878 0x1878u
#define VIDEO_1879 0x1879u
#define VIDEO_187A 0x187Au
#define VIDEO_187B 0x187Bu
#define VIDEO_187C 0x187Cu
#define VIDEO_187D 0x187Du
#define VIDEO_187E 0x187Eu
#define VIDEO_187F 0x187Fu
#define VIDEO_1880 0x1880u
#define VIDEO_1881 0x1881u
#define VIDEO_1883 0x1883u
#define VIDEO_1884 0x1884u
#define VIDEO_1885 0x1885u
#define VIDEO_1886 0x1886u
#define VIDEO_1888 0x1888u
#define VIDEO_188B 0x188Bu
#define VIDEO_188C 0x188Cu
#define VIDEO_189C 0x189Cu
#define VIDEO_189E 0x189Eu
#define VIDEO_18E0 0x18E0u
#define VIDEO_18E1 0x18E1u
#define VIDEO_18E2 0x18E2u
#define VIDEO_18E4 0x18E4u
#define VIDEO_18E6 0x18E6u
#define VIDEO_18E7 0x18E7u
#define VIDEO_18E9 0x18E9u
#define VIDEO_18EA 0x18EAu
#define VIDEO_18EB 0x18EBu
#define VIDEO_18EC 0x18ECu
#define VIDEO_18ED 0x18EDu
#define VIDEO_18EE 0x18EEu
#define VIDEO_18EF 0x18EFu
#define VIDEO_18F1 0x18F1u
#define VIDEO_18F2 0x18F2u
#define VIDEO_18F4 0x18F4u
#define VIDEO_18F6 0x18F6u
#define VIDEO_18F8 0x18F8u
#define VIDEO_18FA 0x18FAu
#define VIDEO_18FC 0x18FCu
#define VIDEO_1A00 0x1A00u
#define VIDEO_1C80 0x1C80u
#define VIDEO_1D00 0x1D00u
#define VIDEO_1D80 0x1D80u
#define VIDEO_1E00 0x1E00u
#define VIDEO_1E80 0x1E80u
#define VIDEO_1F00 0x1F00u
#define IO_1F80 0x1F80u
#define IO_1F81 0x1F81u
#define IO_1F90 0x1F90u
#define IO_1FA0 0x1FA0u
#define IO_1FA2 0x1FA2u
#define IO_1FA4 0x1FA4u
#define IO_1FA5 0x1FA5u
#define IO_1FA6 0x1FA6u
#define IO_1FA7 0x1FA7u
#define IO_1FB0 0x1FB0u
#define IO_1FB2 0x1FB2u
#define IO_1FB3 0x1FB3u
#define IO_1FB4 0x1FB4u
#define IO_1FB6 0x1FB6u
#define IO_1FB7 0x1FB7u
#define IO_1FB8 0x1FB8u
#define IO_1FB9 0x1FB9u
#define IO_1FBA 0x1FBAu
#define IO_1FBB 0x1FBBu
#define IO_1FBC 0x1FBCu
#define IO_1FC0 0x1FC0u
#define IO_1FC2 0x1FC2u
#define IO_1FC4 0x1FC4u
#define IO_1FC6 0x1FC6u
#define IO_1FC8 0x1FC8u
#define IO_1FC9 0x1FC9u
#define IO_1FCA 0x1FCAu
#define VIDEO_2000 0x2000u
#define VIDEO_24E2 0x24E2u
#define VIDEO_26DD 0x26DDu
#define VIDEO_380C 0x380Cu
#define VIDEO_3840 0x3840u
#define VIDEO_385E 0x385Eu
#define VIDEO_3860 0x3860u
#define VIDEO_3862 0x3862u
#define VIDEO_3864 0x3864u
#define VIDEO_3866 0x3866u
#define VIDEO_3A00 0x3A00u
#define VIDEO_3C00 0x3C00u

/* data of the program symbols.txt and the assets label (their CPU addresses) */
#define map_000000_ADDRESS 0x6000u    /* 000000 */
#define map_strip_000004_ADDRESS 0x6004u    /* 000004 */
#define map_strip_000084_ADDRESS 0x6084u    /* 000084 */
#define map_000104_ADDRESS 0x6104u    /* 000104 */
#define map_strip_000108_ADDRESS 0x6108u    /* 000108 */
#define map_strip_000188_ADDRESS 0x6188u    /* 000188 */
#define unreached_map_000208_ADDRESS 0x6208u    /* 000208 */
#define map_strip_00020C_ADDRESS 0x620Cu    /* 00020C */
#define map_00030C_ADDRESS 0x630Cu    /* 00030C */
#define map_strip_00031C_ADDRESS 0x631Cu    /* 00031C */
#define map_strip_00039C_ADDRESS 0x639Cu    /* 00039C */
#define map_strip_00041C_ADDRESS 0x641Cu    /* 00041C */
#define map_strip_00049C_ADDRESS 0x649Cu    /* 00049C */
#define map_strip_00051C_ADDRESS 0x651Cu    /* 00051C */
#define map_strip_00059C_ADDRESS 0x659Cu    /* 00059C */
#define map_strip_00061C_ADDRESS 0x661Cu    /* 00061C */
#define map_strip_00069C_ADDRESS 0x669Cu    /* 00069C */
#define map_00071C_ADDRESS 0x671Cu    /* 00071C */
#define map_strip_00072C_ADDRESS 0x672Cu    /* 00072C */
#define map_strip_0007AC_ADDRESS 0x67ACu    /* 0007AC */
#define map_strip_00082C_ADDRESS 0x682Cu    /* 00082C */
#define map_strip_0008AC_ADDRESS 0x68ACu    /* 0008AC */
#define map_strip_00092C_ADDRESS 0x692Cu    /* 00092C */
#define map_strip_0009AC_ADDRESS 0x69ACu    /* 0009AC */
#define map_strip_000A2C_ADDRESS 0x6A2Cu    /* 000A2C */
#define map_strip_000AAC_ADDRESS 0x6AACu    /* 000AAC */
#define map_000B2C_ADDRESS 0x6B2Cu    /* 000B2C */
#define map_strip_000B3C_ADDRESS 0x6B3Cu    /* 000B3C */
#define map_strip_000BBC_ADDRESS 0x6BBCu    /* 000BBC */
#define map_strip_000C3C_ADDRESS 0x6C3Cu    /* 000C3C */
#define map_strip_000CBC_ADDRESS 0x6CBCu    /* 000CBC */
#define map_strip_000D3C_ADDRESS 0x6D3Cu    /* 000D3C */
#define map_strip_000DBC_ADDRESS 0x6DBCu    /* 000DBC */
#define map_strip_000E3C_ADDRESS 0x6E3Cu    /* 000E3C */
#define map_strip_000EBC_ADDRESS 0x6EBCu    /* 000EBC */
#define map_000F3C_ADDRESS 0x6F3Cu    /* 000F3C */
#define map_strip_000F48_ADDRESS 0x6F48u    /* 000F48 */
#define map_strip_000FC8_ADDRESS 0x6FC8u    /* 000FC8 */
#define map_strip_001048_ADDRESS 0x7048u    /* 001048 */
#define map_strip_0010C8_ADDRESS 0x70C8u    /* 0010C8 */
#define map_strip_001148_ADDRESS 0x7148u    /* 001148 */
#define map_strip_0011C8_ADDRESS 0x71C8u    /* 0011C8 */
#define map_001248_ADDRESS 0x7248u    /* 001248 */
#define map_strip_00124E_ADDRESS 0x724Eu    /* 00124E */
#define map_strip_0012CE_ADDRESS 0x72CEu    /* 0012CE */
#define map_strip_00134E_ADDRESS 0x734Eu    /* 00134E */
#define map_0013CE_ADDRESS 0x73CEu    /* 0013CE */
#define map_strip_0013D2_ADDRESS 0x73D2u    /* 0013D2 */
#define map_strip_001552_ADDRESS 0x7552u    /* 001552 */
#define map_0016D2_ADDRESS 0x76D2u    /* 0016D2 */
#define map_strip_0016D8_ADDRESS 0x76D8u    /* 0016D8 */
#define map_strip_001758_ADDRESS 0x7758u    /* 001758 */
#define map_strip_0017D8_ADDRESS 0x77D8u    /* 0017D8 */
#define map_001858_ADDRESS 0x7858u    /* 001858 */
#define map_strip_00185C_ADDRESS 0x785Cu    /* 00185C */
#define map_strip_0018DC_ADDRESS 0x78DCu    /* 0018DC */
#define map_00195C_ADDRESS 0x795Cu    /* 00195C */
#define map_strip_001960_ADDRESS 0x7960u    /* 001960 */
#define map_strip_0019E0_ADDRESS 0x79E0u    /* 0019E0 */
#define map_001A60_ADDRESS 0x7A60u    /* 001A60 */
#define map_strip_001A64_ADDRESS 0x7A64u    /* 001A64 */
#define map_strip_001AE4_ADDRESS 0x7AE4u    /* 001AE4 */
#define map_001B64_ADDRESS 0x7B64u    /* 001B64 */
#define map_strip_001B68_ADDRESS 0x7B68u    /* 001B68 */
#define map_strip_001BE8_ADDRESS 0x7BE8u    /* 001BE8 */
#define map_001C68_ADDRESS 0x7C68u    /* 001C68 */
#define map_strip_001C6C_ADDRESS 0x7C6Cu    /* 001C6C */
#define map_strip_001CEC_ADDRESS 0x7CECu    /* 001CEC */
#define map_001D6C_ADDRESS 0x7D6Cu    /* 001D6C */
#define map_strip_001D7E_ADDRESS 0x7D7Eu    /* 001D7E */
#define map_strip_001DFE_ADDRESS 0x7DFEu    /* 001DFE */
#define map_001E7E_ADDRESS 0x7E7Eu    /* 001E7E */
#define map_strip_001E82_ADDRESS 0x7E82u    /* 001E82 */
#define map_strip_001F02_ADDRESS 0x7F02u    /* 001F02 */
#define map_edge_row_001F82_ADDRESS 0x7F82u    /* 001F82 */
#define fill_001F92_ADDRESS 0x7F92u    /* 001F92 */
#define map_002000_ADDRESS 0x6000u    /* 002000 */
#define map_strip_00200E_ADDRESS 0x600Eu    /* 00200E */
#define map_strip_00208E_ADDRESS 0x608Eu    /* 00208E */
#define map_strip_00210E_ADDRESS 0x610Eu    /* 00210E */
#define map_strip_00218E_ADDRESS 0x618Eu    /* 00218E */
#define map_strip_00220E_ADDRESS 0x620Eu    /* 00220E */
#define map_strip_00228E_ADDRESS 0x628Eu    /* 00228E */
#define map_strip_00230E_ADDRESS 0x630Eu    /* 00230E */
#define map_00238E_ADDRESS 0x638Eu    /* 00238E */
#define map_strip_00239C_ADDRESS 0x639Cu    /* 00239C */
#define map_strip_00241C_ADDRESS 0x641Cu    /* 00241C */
#define map_strip_00249C_ADDRESS 0x649Cu    /* 00249C */
#define map_strip_00251C_ADDRESS 0x651Cu    /* 00251C */
#define map_strip_00259C_ADDRESS 0x659Cu    /* 00259C */
#define map_strip_00261C_ADDRESS 0x661Cu    /* 00261C */
#define map_strip_00269C_ADDRESS 0x669Cu    /* 00269C */
#define map_00271C_ADDRESS 0x671Cu    /* 00271C */
#define map_strip_00272E_ADDRESS 0x672Eu    /* 00272E */
#define map_strip_0027AE_ADDRESS 0x67AEu    /* 0027AE */
#define map_strip_00282E_ADDRESS 0x682Eu    /* 00282E */
#define map_strip_0028AE_ADDRESS 0x68AEu    /* 0028AE */
#define map_strip_00292E_ADDRESS 0x692Eu    /* 00292E */
#define map_strip_0029AE_ADDRESS 0x69AEu    /* 0029AE */
#define map_strip_002A2E_ADDRESS 0x6A2Eu    /* 002A2E */
#define map_strip_002AAE_ADDRESS 0x6AAEu    /* 002AAE */
#define map_strip_002B2E_ADDRESS 0x6B2Eu    /* 002B2E */
#define map_002BAE_ADDRESS 0x6BAEu    /* 002BAE */
#define map_strip_002BC0_ADDRESS 0x6BC0u    /* 002BC0 */
#define map_strip_002C40_ADDRESS 0x6C40u    /* 002C40 */
#define map_strip_002CC0_ADDRESS 0x6CC0u    /* 002CC0 */
#define map_strip_002D40_ADDRESS 0x6D40u    /* 002D40 */
#define map_strip_002DC0_ADDRESS 0x6DC0u    /* 002DC0 */
#define map_strip_002E40_ADDRESS 0x6E40u    /* 002E40 */
#define map_strip_002EC0_ADDRESS 0x6EC0u    /* 002EC0 */
#define map_strip_002F40_ADDRESS 0x6F40u    /* 002F40 */
#define map_strip_002FC0_ADDRESS 0x6FC0u    /* 002FC0 */
#define map_003040_ADDRESS 0x7040u    /* 003040 */
#define map_strip_003044_ADDRESS 0x7044u    /* 003044 */
#define map_strip_0030C4_ADDRESS 0x70C4u    /* 0030C4 */
#define map_003144_ADDRESS 0x7144u    /* 003144 */
#define map_strip_003156_ADDRESS 0x7156u    /* 003156 */
#define map_strip_0031D6_ADDRESS 0x71D6u    /* 0031D6 */
#define map_strip_003256_ADDRESS 0x7256u    /* 003256 */
#define map_strip_0032D6_ADDRESS 0x72D6u    /* 0032D6 */
#define map_strip_003356_ADDRESS 0x7356u    /* 003356 */
#define map_strip_0033D6_ADDRESS 0x73D6u    /* 0033D6 */
#define map_strip_003456_ADDRESS 0x7456u    /* 003456 */
#define map_strip_0034D6_ADDRESS 0x74D6u    /* 0034D6 */
#define map_strip_003556_ADDRESS 0x7556u    /* 003556 */
#define map_0035D6_ADDRESS 0x75D6u    /* 0035D6 */
#define map_strip_0035E8_ADDRESS 0x75E8u    /* 0035E8 */
#define map_strip_003668_ADDRESS 0x7668u    /* 003668 */
#define map_strip_0036E8_ADDRESS 0x76E8u    /* 0036E8 */
#define map_strip_003768_ADDRESS 0x7768u    /* 003768 */
#define map_strip_0037E8_ADDRESS 0x77E8u    /* 0037E8 */
#define map_strip_003868_ADDRESS 0x7868u    /* 003868 */
#define map_strip_0038E8_ADDRESS 0x78E8u    /* 0038E8 */
#define map_strip_003968_ADDRESS 0x7968u    /* 003968 */
#define map_strip_0039E8_ADDRESS 0x79E8u    /* 0039E8 */
#define map_003A68_ADDRESS 0x7A68u    /* 003A68 */
#define map_strip_003A6C_ADDRESS 0x7A6Cu    /* 003A6C */
#define map_strip_003AEC_ADDRESS 0x7AECu    /* 003AEC */
#define map_003B6C_ADDRESS 0x7B6Cu    /* 003B6C */
#define map_strip_003B70_ADDRESS 0x7B70u    /* 003B70 */
#define map_strip_003BF0_ADDRESS 0x7BF0u    /* 003BF0 */
#define map_003C70_ADDRESS 0x7C70u    /* 003C70 */
#define map_strip_003C74_ADDRESS 0x7C74u    /* 003C74 */
#define map_strip_003CF4_ADDRESS 0x7CF4u    /* 003CF4 */
#define map_003D74_ADDRESS 0x7D74u    /* 003D74 */
#define map_strip_003D78_ADDRESS 0x7D78u    /* 003D78 */
#define map_strip_003DF8_ADDRESS 0x7DF8u    /* 003DF8 */
#define map_003E78_ADDRESS 0x7E78u    /* 003E78 */
#define map_strip_003E7C_ADDRESS 0x7E7Cu    /* 003E7C */
#define map_strip_003EFC_ADDRESS 0x7EFCu    /* 003EFC */
#define map_edge_row_003F7C_ADDRESS 0x7F7Cu    /* 003F7C */
#define fill_003F8C_ADDRESS 0x7F8Cu    /* 003F8C */
#define map_004000_ADDRESS 0x6000u    /* 004000 */
#define map_strip_004014_ADDRESS 0x6014u    /* 004014 */
#define map_strip_004094_ADDRESS 0x6094u    /* 004094 */
#define map_strip_004114_ADDRESS 0x6114u    /* 004114 */
#define map_strip_004194_ADDRESS 0x6194u    /* 004194 */
#define map_strip_004214_ADDRESS 0x6214u    /* 004214 */
#define map_strip_004294_ADDRESS 0x6294u    /* 004294 */
#define map_strip_004314_ADDRESS 0x6314u    /* 004314 */
#define map_strip_004394_ADDRESS 0x6394u    /* 004394 */
#define map_strip_004414_ADDRESS 0x6414u    /* 004414 */
#define map_strip_004494_ADDRESS 0x6494u    /* 004494 */
#define map_004514_ADDRESS 0x6514u    /* 004514 */
#define map_strip_004528_ADDRESS 0x6528u    /* 004528 */
#define map_strip_0045A8_ADDRESS 0x65A8u    /* 0045A8 */
#define map_strip_004628_ADDRESS 0x6628u    /* 004628 */
#define map_strip_0046A8_ADDRESS 0x66A8u    /* 0046A8 */
#define map_strip_004728_ADDRESS 0x6728u    /* 004728 */
#define map_strip_0047A8_ADDRESS 0x67A8u    /* 0047A8 */
#define map_strip_004828_ADDRESS 0x6828u    /* 004828 */
#define map_strip_0048A8_ADDRESS 0x68A8u    /* 0048A8 */
#define map_strip_004928_ADDRESS 0x6928u    /* 004928 */
#define map_strip_0049A8_ADDRESS 0x69A8u    /* 0049A8 */
#define map_004A28_ADDRESS 0x6A28u    /* 004A28 */
#define map_strip_004A40_ADDRESS 0x6A40u    /* 004A40 */
#define map_strip_004AC0_ADDRESS 0x6AC0u    /* 004AC0 */
#define map_strip_004B40_ADDRESS 0x6B40u    /* 004B40 */
#define map_strip_004BC0_ADDRESS 0x6BC0u    /* 004BC0 */
#define map_strip_004C40_ADDRESS 0x6C40u    /* 004C40 */
#define map_strip_004CC0_ADDRESS 0x6CC0u    /* 004CC0 */
#define map_strip_004D40_ADDRESS 0x6D40u    /* 004D40 */
#define map_strip_004DC0_ADDRESS 0x6DC0u    /* 004DC0 */
#define map_strip_004E40_ADDRESS 0x6E40u    /* 004E40 */
#define map_strip_004EC0_ADDRESS 0x6EC0u    /* 004EC0 */
#define map_strip_004F40_ADDRESS 0x6F40u    /* 004F40 */
#define map_strip_004FC0_ADDRESS 0x6FC0u    /* 004FC0 */
#define map_005040_ADDRESS 0x7040u    /* 005040 */
#define map_strip_005058_ADDRESS 0x7058u    /* 005058 */
#define map_strip_0050D8_ADDRESS 0x70D8u    /* 0050D8 */
#define map_strip_005158_ADDRESS 0x7158u    /* 005158 */
#define map_strip_0051D8_ADDRESS 0x71D8u    /* 0051D8 */
#define map_strip_005258_ADDRESS 0x7258u    /* 005258 */
#define map_strip_0052D8_ADDRESS 0x72D8u    /* 0052D8 */
#define map_strip_005358_ADDRESS 0x7358u    /* 005358 */
#define map_strip_0053D8_ADDRESS 0x73D8u    /* 0053D8 */
#define map_strip_005458_ADDRESS 0x7458u    /* 005458 */
#define map_strip_0054D8_ADDRESS 0x74D8u    /* 0054D8 */
#define map_strip_005558_ADDRESS 0x7558u    /* 005558 */
#define map_strip_0055D8_ADDRESS 0x75D8u    /* 0055D8 */
#define map_005658_ADDRESS 0x7658u    /* 005658 */
#define map_strip_005670_ADDRESS 0x7670u    /* 005670 */
#define map_strip_0056F0_ADDRESS 0x76F0u    /* 0056F0 */
#define map_strip_005770_ADDRESS 0x7770u    /* 005770 */
#define map_strip_0057F0_ADDRESS 0x77F0u    /* 0057F0 */
#define map_strip_005870_ADDRESS 0x7870u    /* 005870 */
#define map_strip_0058F0_ADDRESS 0x78F0u    /* 0058F0 */
#define map_strip_005970_ADDRESS 0x7970u    /* 005970 */
#define map_strip_0059F0_ADDRESS 0x79F0u    /* 0059F0 */
#define map_strip_005A70_ADDRESS 0x7A70u    /* 005A70 */
#define map_strip_005AF0_ADDRESS 0x7AF0u    /* 005AF0 */
#define map_strip_005B70_ADDRESS 0x7B70u    /* 005B70 */
#define map_strip_005BF0_ADDRESS 0x7BF0u    /* 005BF0 */
#define map_005C70_ADDRESS 0x7C70u    /* 005C70 */
#define map_strip_005C76_ADDRESS 0x7C76u    /* 005C76 */
#define map_strip_005CF6_ADDRESS 0x7CF6u    /* 005CF6 */
#define map_strip_005D76_ADDRESS 0x7D76u    /* 005D76 */
#define map_005DF6_ADDRESS 0x7DF6u    /* 005DF6 */
#define map_strip_005DFA_ADDRESS 0x7DFAu    /* 005DFA */
#define map_strip_005EFA_ADDRESS 0x7EFAu    /* 005EFA */
#define map_edge_row_005FFA_ADDRESS 0x7FFAu    /* 005FFA */
#define map_006000_ADDRESS 0x6000u    /* 006000 */
#define map_strip_006018_ADDRESS 0x6018u    /* 006018 */
#define map_strip_006098_ADDRESS 0x6098u    /* 006098 */
#define map_strip_006118_ADDRESS 0x6118u    /* 006118 */
#define map_strip_006198_ADDRESS 0x6198u    /* 006198 */
#define map_strip_006218_ADDRESS 0x6218u    /* 006218 */
#define map_strip_006298_ADDRESS 0x6298u    /* 006298 */
#define map_strip_006318_ADDRESS 0x6318u    /* 006318 */
#define map_strip_006398_ADDRESS 0x6398u    /* 006398 */
#define map_strip_006418_ADDRESS 0x6418u    /* 006418 */
#define map_strip_006498_ADDRESS 0x6498u    /* 006498 */
#define map_strip_006518_ADDRESS 0x6518u    /* 006518 */
#define map_strip_006598_ADDRESS 0x6598u    /* 006598 */
#define map_006618_ADDRESS 0x6618u    /* 006618 */
#define map_strip_00661E_ADDRESS 0x661Eu    /* 00661E */
#define map_strip_006A1E_ADDRESS 0x6A1Eu    /* 006A1E */
#define map_strip_006E1E_ADDRESS 0x6E1Eu    /* 006E1E */
#define map_00721E_ADDRESS 0x721Eu    /* 00721E */
#define map_strip_007224_ADDRESS 0x7224u    /* 007224 */
#define map_strip_0072A4_ADDRESS 0x72A4u    /* 0072A4 */
#define map_strip_007324_ADDRESS 0x7324u    /* 007324 */
#define map_0073A4_ADDRESS 0x73A4u    /* 0073A4 */
#define map_strip_0073B6_ADDRESS 0x73B6u    /* 0073B6 */
#define map_strip_007436_ADDRESS 0x7436u    /* 007436 */
#define map_strip_0074B6_ADDRESS 0x74B6u    /* 0074B6 */
#define map_strip_007536_ADDRESS 0x7536u    /* 007536 */
#define map_strip_0075B6_ADDRESS 0x75B6u    /* 0075B6 */
#define map_strip_007636_ADDRESS 0x7636u    /* 007636 */
#define map_strip_0076B6_ADDRESS 0x76B6u    /* 0076B6 */
#define map_strip_007736_ADDRESS 0x7736u    /* 007736 */
#define map_strip_0077B6_ADDRESS 0x77B6u    /* 0077B6 */
#define map_007836_ADDRESS 0x7836u    /* 007836 */
#define map_strip_00783A_ADDRESS 0x783Au    /* 00783A */
#define map_strip_0078BA_ADDRESS 0x78BAu    /* 0078BA */
#define map_00793A_ADDRESS 0x793Au    /* 00793A */
#define map_strip_00793E_ADDRESS 0x793Eu    /* 00793E */
#define map_strip_0079BE_ADDRESS 0x79BEu    /* 0079BE */
#define map_007A3E_ADDRESS 0x7A3Eu    /* 007A3E */
#define map_strip_007A4E_ADDRESS 0x7A4Eu    /* 007A4E */
#define map_strip_007ACE_ADDRESS 0x7ACEu    /* 007ACE */
#define map_strip_007B4E_ADDRESS 0x7B4Eu    /* 007B4E */
#define map_strip_007BCE_ADDRESS 0x7BCEu    /* 007BCE */
#define map_strip_007C4E_ADDRESS 0x7C4Eu    /* 007C4E */
#define map_strip_007CCE_ADDRESS 0x7CCEu    /* 007CCE */
#define map_strip_007D4E_ADDRESS 0x7D4Eu    /* 007D4E */
#define map_strip_007DCE_ADDRESS 0x7DCEu    /* 007DCE */
#define map_007E4E_ADDRESS 0x7E4Eu    /* 007E4E */
#define map_strip_007E52_ADDRESS 0x7E52u    /* 007E52 */
#define map_strip_007ED2_ADDRESS 0x7ED2u    /* 007ED2 */
#define map_edge_row_007F52_ADDRESS 0x7F52u    /* 007F52 */
#define fill_007F62_ADDRESS 0x7F62u    /* 007F62 */
#define map_008000_ADDRESS 0x6000u    /* 008000 */
#define map_strip_008004_ADDRESS 0x6004u    /* 008004 */
#define map_strip_008084_ADDRESS 0x6084u    /* 008084 */
#define tile_blocks_008104_ADDRESS 0x6104u    /* 008104 */
#define unused_blocks_00842E_ADDRESS 0x642Eu    /* 00842E */
#define tile_blocks_008464_ADDRESS 0x6464u    /* 008464 */
#define unused_blocks_009298_ADDRESS 0x7298u    /* 009298 */
#define map_0092BC_ADDRESS 0x72BCu    /* 0092BC */
#define map_strip_0092C0_ADDRESS 0x72C0u    /* 0092C0 */
#define map_strip_009340_ADDRESS 0x7340u    /* 009340 */
#define map_0093C0_ADDRESS 0x73C0u    /* 0093C0 */
#define map_strip_0093C4_ADDRESS 0x73C4u    /* 0093C4 */
#define map_strip_0094C4_ADDRESS 0x74C4u    /* 0094C4 */
#define tile_blocks_0095C4_ADDRESS 0x75C4u    /* 0095C4 */
#define map_0099A2_ADDRESS 0x79A2u    /* 0099A2 */
#define map_strip_0099A6_ADDRESS 0x79A6u    /* 0099A6 */
#define map_strip_009A26_ADDRESS 0x7A26u    /* 009A26 */
#define tile_blocks_009AA6_ADDRESS 0x7AA6u    /* 009AA6 */
#define unused_blocks_009C20_ADDRESS 0x7C20u    /* 009C20 */
#define map_009C32_ADDRESS 0x7C32u    /* 009C32 */
#define map_strip_009C36_ADDRESS 0x7C36u    /* 009C36 */
#define map_strip_009CB6_ADDRESS 0x7CB6u    /* 009CB6 */
#define tile_blocks_009D36_ADDRESS 0x7D36u    /* 009D36 */
#define map_009E44_ADDRESS 0x7E44u    /* 009E44 */
#define map_strip_009E48_ADDRESS 0x7E48u    /* 009E48 */
#define map_strip_009EC8_ADDRESS 0x7EC8u    /* 009EC8 */
#define map_edge_row_009F48_ADDRESS 0x7F48u    /* 009F48 */
#define fill_009F58_ADDRESS 0x7F58u    /* 009F58 */
#define edge_block_009FA4_ADDRESS 0x7FA4u    /* 009FA4 */
#define fill_009FB6_ADDRESS 0x7FB6u    /* 009FB6 */
#define edge_block_009FD0_ADDRESS 0x7FD0u    /* 009FD0 */
#define fill_009FE2_ADDRESS 0x7FE2u    /* 009FE2 */
#define tile_blocks_00A000_ADDRESS 0x6000u    /* 00A000 */
#define unused_blocks_00A4B6_ADDRESS 0x64B6u    /* 00A4B6 */
#define tile_blocks_00A4C8_ADDRESS 0x64C8u    /* 00A4C8 */
#define tile_blocks_00B7A0_ADDRESS 0x77A0u    /* 00B7A0 */
#define map_00B998_ADDRESS 0x7998u    /* 00B998 */
#define map_strip_00B99C_ADDRESS 0x799Cu    /* 00B99C */
#define map_strip_00BA1C_ADDRESS 0x7A1Cu    /* 00BA1C */
#define tile_blocks_00BA9C_ADDRESS 0x7A9Cu    /* 00BA9C */
#define tile_blocks_00BC04_ADDRESS 0x7C04u    /* 00BC04 */
#define fill_00BF64_ADDRESS 0x7F64u    /* 00BF64 */
#define tile_blocks_00C000_ADDRESS 0x6000u    /* 00C000 */
#define tile_blocks_00CDDA_ADDRESS 0x6DDAu    /* 00CDDA */
#define tile_blocks_00D2C6_ADDRESS 0x72C6u    /* 00D2C6 */
#define tile_blocks_00D5CC_ADDRESS 0x75CCu    /* 00D5CC */
#define tile_blocks_00DA3A_ADDRESS 0x7A3Au    /* 00DA3A */
#define map_00DB00_ADDRESS 0x7B00u    /* 00DB00 */
#define map_strip_00DB10_ADDRESS 0x7B10u    /* 00DB10 */
#define map_strip_00DB90_ADDRESS 0x7B90u    /* 00DB90 */
#define map_strip_00DC10_ADDRESS 0x7C10u    /* 00DC10 */
#define map_strip_00DC90_ADDRESS 0x7C90u    /* 00DC90 */
#define map_strip_00DD10_ADDRESS 0x7D10u    /* 00DD10 */
#define map_strip_00DD90_ADDRESS 0x7D90u    /* 00DD90 */
#define map_strip_00DE10_ADDRESS 0x7E10u    /* 00DE10 */
#define map_strip_00DE90_ADDRESS 0x7E90u    /* 00DE90 */
#define map_edge_row_00DF10_ADDRESS 0x7F10u    /* 00DF10 */
#define fill_00DF20_ADDRESS 0x7F20u    /* 00DF20 */
#define unreached_map_00DF5C_ADDRESS 0x7F5Cu    /* 00DF5C */
#define map_strip_00DF5E_ADDRESS 0x7F5Eu    /* 00DF5E */
#define fill_00DFDE_ADDRESS 0x7FDEu    /* 00DFDE */
#define tile_blocks_00E000_ADDRESS 0x6000u    /* 00E000 */
#define tile_blocks_00F2EA_ADDRESS 0x72EAu    /* 00F2EA */
#define tile_blocks_00F6C8_ADDRESS 0x76C8u    /* 00F6C8 */
#define tile_blocks_00F9CE_ADDRESS 0x79CEu    /* 00F9CE */
#define tile_blocks_00FD88_ADDRESS 0x7D88u    /* 00FD88 */
#define map_00FF5C_ADDRESS 0x7F5Cu    /* 00FF5C */
#define map_strip_00FF5E_ADDRESS 0x7F5Eu    /* 00FF5E */
#define map_edge_row_00FFDE_ADDRESS 0x7FDEu    /* 00FFDE */
#define fill_00FFEE_ADDRESS 0x7FEEu    /* 00FFEE */
#define tile_blocks_010000_ADDRESS 0x6000u    /* 010000 */
#define tile_blocks_011476_ADDRESS 0x7476u    /* 011476 */
#define unused_blocks_0116C8_ADDRESS 0x76C8u    /* 0116C8 */
#define tile_blocks_01178E_ADDRESS 0x778Eu    /* 01178E */
#define tile_blocks_011A94_ADDRESS 0x7A94u    /* 011A94 */
#define map_011F14_ADDRESS 0x7F14u    /* 011F14 */
#define map_strip_011F16_ADDRESS 0x7F16u    /* 011F16 */
#define map_edge_row_011F96_ADDRESS 0x7F96u    /* 011F96 */
#define fill_011FA6_ADDRESS 0x7FA6u    /* 011FA6 */
#define tile_blocks_012000_ADDRESS 0x6000u    /* 012000 */
#define tile_blocks_013D40_ADDRESS 0x7D40u    /* 013D40 */
#define tile_blocks_013DF4_ADDRESS 0x7DF4u    /* 013DF4 */
#define tile_blocks_013EF0_ADDRESS 0x7EF0u    /* 013EF0 */
#define unused_blocks_013FEC_ADDRESS 0x7FECu    /* 013FEC */
#define fill_013FFE_ADDRESS 0x7FFEu    /* 013FFE */
#define tile_blocks_014000_ADDRESS 0x6000u    /* 014000 */
#define unused_blocks_014C06_ADDRESS 0x6C06u    /* 014C06 */
#define tile_blocks_014C18_ADDRESS 0x6C18u    /* 014C18 */
#define tile_picture_015A94_ADDRESS 0x7A94u    /* 015A94 */
#define tile_blocks_015C8B_ADDRESS 0x7C8Bu    /* 015C8B */
#define unused_blocks_015FEB_ADDRESS 0x7FEBu    /* 015FEB */
#define fill_015FFD_ADDRESS 0x7FFDu    /* 015FFD */
#define tile_blocks_016000_ADDRESS 0x6000u    /* 016000 */
#define tile_blocks_016A32_ADDRESS 0x6A32u    /* 016A32 */
#define tile_blocks_017626_ADDRESS 0x7626u    /* 017626 */
#define fill_017F5C_ADDRESS 0x7F5Cu    /* 017F5C */
#define tile_blocks_018000_ADDRESS 0x6000u    /* 018000 */
#define tile_blocks_018AC2_ADDRESS 0x6AC2u    /* 018AC2 */
#define tile_blocks_019596_ADDRESS 0x7596u    /* 019596 */
#define tile_blocks_019BD8_ADDRESS 0x7BD8u    /* 019BD8 */
#define map_019ECC_ADDRESS 0x7ECCu    /* 019ECC */
#define map_strip_019ED0_ADDRESS 0x7ED0u    /* 019ED0 */
#define map_strip_019F50_ADDRESS 0x7F50u    /* 019F50 */
#define map_edge_row_019FD0_ADDRESS 0x7FD0u    /* 019FD0 */
#define fill_019FE0_ADDRESS 0x7FE0u    /* 019FE0 */
#define tile_blocks_01A000_ADDRESS 0x6000u    /* 01A000 */
#define tile_blocks_01A9B4_ADDRESS 0x69B4u    /* 01A9B4 */
#define tile_blocks_01AD5C_ADDRESS 0x6D5Cu    /* 01AD5C */
#define tile_blocks_01B452_ADDRESS 0x7452u    /* 01B452 */
#define unused_blocks_01BC7A_ADDRESS 0x7C7Au    /* 01BC7A */
#define tile_blocks_01BC8C_ADDRESS 0x7C8Cu    /* 01BC8C */
#define fill_01BF26_ADDRESS 0x7F26u    /* 01BF26 */
#define tile_blocks_01C000_ADDRESS 0x6000u    /* 01C000 */
#define tile_blocks_01D53C_ADDRESS 0x753Cu    /* 01D53C */
#define tile_blocks_01E000_ADDRESS 0x6000u    /* 01E000 */
#define tile_blocks_01F1B8_ADDRESS 0x71B8u    /* 01F1B8 */
#define tile_blocks_01FC0E_ADDRESS 0x7C0Eu    /* 01FC0E */
#define unused_blocks_01FFC8_ADDRESS 0x7FC8u    /* 01FFC8 */
#define fill_01FFFE_ADDRESS 0x7FFEu    /* 01FFFE */
#define fill_021A34_ADDRESS 0x7A34u    /* 021A34 */
#define loaded_table_021B80_ADDRESS 0x7B80u    /* 021B80 */
#define loaded_table_021B86_ADDRESS 0x7B86u    /* 021B86 */
#define loaded_table_021B8C_ADDRESS 0x7B8Cu    /* 021B8C */
#define loaded_table_021B90_ADDRESS 0x7B90u    /* 021B90 */
#define loaded_table_021B94_ADDRESS 0x7B94u    /* 021B94 */
#define loaded_table_021B9E_ADDRESS 0x7B9Eu    /* 021B9E */
#define loaded_table_021BA2_ADDRESS 0x7BA2u    /* 021BA2 */
#define loaded_table_021BAA_ADDRESS 0x7BAAu    /* 021BAA */
#define loaded_table_021BB2_ADDRESS 0x7BB2u    /* 021BB2 */
#define loaded_table_021BB6_ADDRESS 0x7BB6u    /* 021BB6 */
#define loaded_table_021BBE_ADDRESS 0x7BBEu    /* 021BBE */
#define record_021BD0_ADDRESS 0x7BD0u    /* 021BD0 */
#define record_021BD7_ADDRESS 0x7BD7u    /* 021BD7 */
#define record_021BDE_ADDRESS 0x7BDEu    /* 021BDE */
#define record_021BE5_ADDRESS 0x7BE5u    /* 021BE5 */
#define indexed_table_021C38_ADDRESS 0x7C38u    /* 021C38 */
#define indexed_table_021C40_ADDRESS 0x7C40u    /* 021C40 */
#define indexed_table_021C48_ADDRESS 0x7C48u    /* 021C48 */
#define indexed_table_021C50_ADDRESS 0x7C50u    /* 021C50 */
#define indexed_table_021C58_ADDRESS 0x7C58u    /* 021C58 */
#define indexed_table_021C60_ADDRESS 0x7C60u    /* 021C60 */
#define indexed_table_021C68_ADDRESS 0x7C68u    /* 021C68 */
#define indexed_table_021C70_ADDRESS 0x7C70u    /* 021C70 */
#define indexed_table_021C78_ADDRESS 0x7C78u    /* 021C78 */
#define indexed_table_021C80_ADDRESS 0x7C80u    /* 021C80 */
#define indexed_table_021C88_ADDRESS 0x7C88u    /* 021C88 */
#define indexed_table_021C90_ADDRESS 0x7C90u    /* 021C90 */
#define indexed_table_021C98_ADDRESS 0x7C98u    /* 021C98 */
#define indexed_table_021CA0_ADDRESS 0x7CA0u    /* 021CA0 */
#define indexed_table_021CA8_ADDRESS 0x7CA8u    /* 021CA8 */
#define indexed_table_021CB0_ADDRESS 0x7CB0u    /* 021CB0 */
#define indexed_table_021CB8_ADDRESS 0x7CB8u    /* 021CB8 */
#define indexed_table_021CC0_ADDRESS 0x7CC0u    /* 021CC0 */
#define indexed_table_021CC8_ADDRESS 0x7CC8u    /* 021CC8 */
#define indexed_table_021CD0_ADDRESS 0x7CD0u    /* 021CD0 */
#define indexed_table_021CD8_ADDRESS 0x7CD8u    /* 021CD8 */
#define indexed_table_021CE0_ADDRESS 0x7CE0u    /* 021CE0 */
#define indexed_table_021CE8_ADDRESS 0x7CE8u    /* 021CE8 */
#define indexed_table_021CF0_ADDRESS 0x7CF0u    /* 021CF0 */
#define indexed_table_021CF8_ADDRESS 0x7CF8u    /* 021CF8 */
#define indexed_table_021D00_ADDRESS 0x7D00u    /* 021D00 */
#define indexed_table_021D08_ADDRESS 0x7D08u    /* 021D08 */
#define indexed_table_021D10_ADDRESS 0x7D10u    /* 021D10 */
#define loaded_table_021D18_ADDRESS 0x7D18u    /* 021D18 */
#define loaded_table_021D2C_ADDRESS 0x7D2Cu    /* 021D2C */
#define loaded_table_021D8D_ADDRESS 0x7D8Du    /* 021D8D */
#define loaded_table_021DBC_ADDRESS 0x7DBCu    /* 021DBC */
#define loaded_table_021DCF_ADDRESS 0x7DCFu    /* 021DCF */
#define loaded_table_021DE3_ADDRESS 0x7DE3u    /* 021DE3 */
#define indexed_table_021DF1_ADDRESS 0x7DF1u    /* 021DF1 */
#define loaded_table_021E2F_ADDRESS 0x7E2Fu    /* 021E2F */
#define loaded_table_021E3F_ADDRESS 0x7E3Fu    /* 021E3F */
#define loaded_table_021E43_ADDRESS 0x7E43u    /* 021E43 */
#define loaded_table_021E49_ADDRESS 0x7E49u    /* 021E49 */
#define loaded_table_021E4D_ADDRESS 0x7E4Du    /* 021E4D */
#define loaded_table_021E5D_ADDRESS 0x7E5Du    /* 021E5D */
#define loaded_table_021E63_ADDRESS 0x7E63u    /* 021E63 */
#define loaded_table_021E65_ADDRESS 0x7E65u    /* 021E65 */
#define loaded_table_021E6D_ADDRESS 0x7E6Du    /* 021E6D */
#define indexed_table_021E99_ADDRESS 0x7E99u    /* 021E99 */
#define indexed_table_021E9B_ADDRESS 0x7E9Bu    /* 021E9B */
#define indexed_table_021E9D_ADDRESS 0x7E9Du    /* 021E9D */
#define indexed_table_021E9F_ADDRESS 0x7E9Fu    /* 021E9F */
#define indexed_table_021EA1_ADDRESS 0x7EA1u    /* 021EA1 */
#define indexed_table_021EA3_ADDRESS 0x7EA3u    /* 021EA3 */
#define indexed_table_021EA5_ADDRESS 0x7EA5u    /* 021EA5 */
#define indexed_table_021EA7_ADDRESS 0x7EA7u    /* 021EA7 */
#define indexed_table_021EA9_ADDRESS 0x7EA9u    /* 021EA9 */
#define indexed_table_021EAB_ADDRESS 0x7EABu    /* 021EAB */
#define indexed_table_021EAD_ADDRESS 0x7EADu    /* 021EAD */
#define indexed_table_021EAF_ADDRESS 0x7EAFu    /* 021EAF */
#define indexed_table_021EB1_ADDRESS 0x7EB1u    /* 021EB1 */
#define indexed_table_021EB3_ADDRESS 0x7EB3u    /* 021EB3 */
#define indexed_table_021EB5_ADDRESS 0x7EB5u    /* 021EB5 */
#define indexed_table_021EB7_ADDRESS 0x7EB7u    /* 021EB7 */
#define loaded_table_021EE1_ADDRESS 0x7EE1u    /* 021EE1 */
#define fill_021EE5_ADDRESS 0x7EE5u    /* 021EE5 */
#define fill_0231FF_ADDRESS 0x71FFu    /* 0231FF */
#define loaded_table_023510_ADDRESS 0x7510u    /* 023510 */
#define indexed_table_023516_ADDRESS 0x7516u    /* 023516 */
#define loaded_table_02351E_ADDRESS 0x751Eu    /* 02351E */
#define record_02353A_ADDRESS 0x753Au    /* 02353A */
#define record_023553_ADDRESS 0x7553u    /* 023553 */
#define record_02356C_ADDRESS 0x756Cu    /* 02356C */
#define record_023585_ADDRESS 0x7585u    /* 023585 */
#define fill_02367A_ADDRESS 0x767Au    /* 02367A */
#define loaded_table_023683_ADDRESS 0x7683u    /* 023683 */
#define indexed_table_0236E6_ADDRESS 0x76E6u    /* 0236E6 */
#define loaded_table_0236EA_ADDRESS 0x76EAu    /* 0236EA */
#define loaded_table_023706_ADDRESS 0x7706u    /* 023706 */
#define text_023766_ADDRESS 0x7766u    /* 023766 */
#define text_023769_ADDRESS 0x7769u    /* 023769 */
#define text_023779_ADDRESS 0x7779u    /* 023779 */
#define text_02378B_ADDRESS 0x778Bu    /* 02378B */
#define text_02379C_ADDRESS 0x779Cu    /* 02379C */
#define text_0237B4_ADDRESS 0x77B4u    /* 0237B4 */
#define text_0237C7_ADDRESS 0x77C7u    /* 0237C7 */
#define text_0237E0_ADDRESS 0x77E0u    /* 0237E0 */
#define text_0237EB_ADDRESS 0x77EBu    /* 0237EB */
#define text_0237FD_ADDRESS 0x77FDu    /* 0237FD */
#define text_02380E_ADDRESS 0x780Eu    /* 02380E */
#define text_02381E_ADDRESS 0x781Eu    /* 02381E */
#define text_02382F_ADDRESS 0x782Fu    /* 02382F */
#define text_023840_ADDRESS 0x7840u    /* 023840 */
#define text_023851_ADDRESS 0x7851u    /* 023851 */
#define text_023862_ADDRESS 0x7862u    /* 023862 */
#define text_02386F_ADDRESS 0x786Fu    /* 02386F */
#define text_02387C_ADDRESS 0x787Cu    /* 02387C */
#define text_023889_ADDRESS 0x7889u    /* 023889 */
#define text_02388C_ADDRESS 0x788Cu    /* 02388C */
#define text_0238E2_ADDRESS 0x78E2u    /* 0238E2 */
#define text_0238E5_ADDRESS 0x78E5u    /* 0238E5 */
#define text_0238FC_ADDRESS 0x78FCu    /* 0238FC */
#define text_023907_ADDRESS 0x7907u    /* 023907 */
#define text_02391A_ADDRESS 0x791Au    /* 02391A */
#define text_023927_ADDRESS 0x7927u    /* 023927 */
#define text_023932_ADDRESS 0x7932u    /* 023932 */
#define text_02394A_ADDRESS 0x794Au    /* 02394A */
#define text_023956_ADDRESS 0x7956u    /* 023956 */
#define text_023962_ADDRESS 0x7962u    /* 023962 */
#define text_02396F_ADDRESS 0x796Fu    /* 02396F */
#define text_023984_ADDRESS 0x7984u    /* 023984 */
#define text_02399D_ADDRESS 0x799Du    /* 02399D */
#define text_0239A7_ADDRESS 0x79A7u    /* 0239A7 */
#define text_0239B2_ADDRESS 0x79B2u    /* 0239B2 */
#define text_0239BF_ADDRESS 0x79BFu    /* 0239BF */
#define text_0239C8_ADDRESS 0x79C8u    /* 0239C8 */
#define text_0239D1_ADDRESS 0x79D1u    /* 0239D1 */
#define text_0239DE_ADDRESS 0x79DEu    /* 0239DE */
#define text_0239EE_ADDRESS 0x79EEu    /* 0239EE */
#define text_023A0A_ADDRESS 0x7A0Au    /* 023A0A */
#define described_023A0D_ADDRESS 0x7A0Du    /* 023A0D */
#define loaded_table_023A13_ADDRESS 0x7A13u    /* 023A13 */
#define loaded_table_023A21_ADDRESS 0x7A21u    /* 023A21 */
#define loaded_table_023A25_ADDRESS 0x7A25u    /* 023A25 */
#define loaded_table_023A2B_ADDRESS 0x7A2Bu    /* 023A2B */
#define loaded_table_023A2F_ADDRESS 0x7A2Fu    /* 023A2F */
#define loaded_table_023A3D_ADDRESS 0x7A3Du    /* 023A3D */
#define loaded_table_023A43_ADDRESS 0x7A43u    /* 023A43 */
#define loaded_table_023A47_ADDRESS 0x7A47u    /* 023A47 */
#define indexed_table_023A71_ADDRESS 0x7A71u    /* 023A71 */
#define indexed_table_023A73_ADDRESS 0x7A73u    /* 023A73 */
#define indexed_table_023A75_ADDRESS 0x7A75u    /* 023A75 */
#define indexed_table_023A77_ADDRESS 0x7A77u    /* 023A77 */
#define indexed_table_023A79_ADDRESS 0x7A79u    /* 023A79 */
#define indexed_table_023A7B_ADDRESS 0x7A7Bu    /* 023A7B */
#define indexed_table_023A7D_ADDRESS 0x7A7Du    /* 023A7D */
#define indexed_table_023A7F_ADDRESS 0x7A7Fu    /* 023A7F */
#define indexed_table_023A81_ADDRESS 0x7A81u    /* 023A81 */
#define indexed_table_023A83_ADDRESS 0x7A83u    /* 023A83 */
#define indexed_table_023A85_ADDRESS 0x7A85u    /* 023A85 */
#define indexed_table_023A87_ADDRESS 0x7A87u    /* 023A87 */
#define loaded_table_023A99_ADDRESS 0x7A99u    /* 023A99 */
#define loaded_table_023AD9_ADDRESS 0x7AD9u    /* 023AD9 */
#define child_object_023AE9_ADDRESS 0x7AE9u    /* 023AE9 */
#define loaded_table_023AF1_ADDRESS 0x7AF1u    /* 023AF1 */
#define loaded_table_023B01_ADDRESS 0x7B01u    /* 023B01 */
#define loaded_table_023B05_ADDRESS 0x7B05u    /* 023B05 */
#define loaded_table_023B15_ADDRESS 0x7B15u    /* 023B15 */
#define fill_023B21_ADDRESS 0x7B21u    /* 023B21 */
#define fill_024023_ADDRESS 0x6023u    /* 024023 */
#define fill_025558_ADDRESS 0x7558u    /* 025558 */
#define loaded_table_025700_ADDRESS 0x7700u    /* 025700 */
#define loaded_table_02570A_ADDRESS 0x770Au    /* 02570A */
#define loaded_table_02571A_ADDRESS 0x771Au    /* 02571A */
#define loaded_table_02571E_ADDRESS 0x771Eu    /* 02571E */
#define loaded_table_025726_ADDRESS 0x7726u    /* 025726 */
#define loaded_table_025732_ADDRESS 0x7732u    /* 025732 */
#define loaded_table_025738_ADDRESS 0x7738u    /* 025738 */
#define loaded_table_025740_ADDRESS 0x7740u    /* 025740 */
#define loaded_table_02574A_ADDRESS 0x774Au    /* 02574A */
#define loaded_table_025752_ADDRESS 0x7752u    /* 025752 */
#define loaded_table_02575A_ADDRESS 0x775Au    /* 02575A */
#define loaded_table_025766_ADDRESS 0x7766u    /* 025766 */
#define loaded_table_025774_ADDRESS 0x7774u    /* 025774 */
#define loaded_table_025780_ADDRESS 0x7780u    /* 025780 */
#define loaded_table_025790_ADDRESS 0x7790u    /* 025790 */
#define loaded_table_02579A_ADDRESS 0x779Au    /* 02579A */
#define loaded_table_0257A2_ADDRESS 0x77A2u    /* 0257A2 */
#define loaded_table_0257AA_ADDRESS 0x77AAu    /* 0257AA */
#define loaded_table_0257B2_ADDRESS 0x77B2u    /* 0257B2 */
#define loaded_table_025966_ADDRESS 0x7966u    /* 025966 */
#define indexed_table_02597E_ADDRESS 0x797Eu    /* 02597E */
#define indexed_table_02597F_ADDRESS 0x797Fu    /* 02597F */
#define indexed_table_025980_ADDRESS 0x7980u    /* 025980 */
#define indexed_table_025981_ADDRESS 0x7981u    /* 025981 */
#define indexed_table_025982_ADDRESS 0x7982u    /* 025982 */
#define indexed_table_02598A_ADDRESS 0x798Au    /* 02598A */
#define indexed_table_02598B_ADDRESS 0x798Bu    /* 02598B */
#define indexed_table_02598C_ADDRESS 0x798Cu    /* 02598C */
#define indexed_table_02598D_ADDRESS 0x798Du    /* 02598D */
#define indexed_table_02598E_ADDRESS 0x798Eu    /* 02598E */
#define loaded_table_025996_ADDRESS 0x7996u    /* 025996 */
#define loaded_table_02599C_ADDRESS 0x799Cu    /* 02599C */
#define indexed_table_0259A4_ADDRESS 0x79A4u    /* 0259A4 */
#define text_025A0A_ADDRESS 0x7A0Au    /* 025A0A */
#define text_025A30_ADDRESS 0x7A30u    /* 025A30 */
#define text_025B05_ADDRESS 0x7B05u    /* 025B05 */
#define text_025B0F_ADDRESS 0x7B0Fu    /* 025B0F */
#define text_025B14_ADDRESS 0x7B14u    /* 025B14 */
#define text_025B24_ADDRESS 0x7B24u    /* 025B24 */
#define text_025B33_ADDRESS 0x7B33u    /* 025B33 */
#define text_025B38_ADDRESS 0x7B38u    /* 025B38 */
#define text_025B3E_ADDRESS 0x7B3Eu    /* 025B3E */
#define text_025B4E_ADDRESS 0x7B4Eu    /* 025B4E */
#define text_025B59_ADDRESS 0x7B59u    /* 025B59 */
#define text_025BB2_ADDRESS 0x7BB2u    /* 025BB2 */
#define text_025BDE_ADDRESS 0x7BDEu    /* 025BDE */
#define text_025BE8_ADDRESS 0x7BE8u    /* 025BE8 */
#define text_025CB7_ADDRESS 0x7CB7u    /* 025CB7 */
#define text_025D7D_ADDRESS 0x7D7Du    /* 025D7D */
#define text_025DD9_ADDRESS 0x7DD9u    /* 025DD9 */
#define text_025E35_ADDRESS 0x7E35u    /* 025E35 */
#define fill_025E43_ADDRESS 0x7E43u    /* 025E43 */
#define fill_0263C5_ADDRESS 0x63C5u    /* 0263C5 */
#define fill_026F1D_ADDRESS 0x6F1Du    /* 026F1D */
#define fill_027903_ADDRESS 0x7903u    /* 027903 */
#define loaded_table_027908_ADDRESS 0x7908u    /* 027908 */
#define loaded_table_02792A_ADDRESS 0x792Au    /* 02792A */
#define loaded_table_027936_ADDRESS 0x7936u    /* 027936 */
#define loaded_table_027948_ADDRESS 0x7948u    /* 027948 */
#define loaded_table_0279F2_ADDRESS 0x79F2u    /* 0279F2 */
#define loaded_table_0279F6_ADDRESS 0x79F6u    /* 0279F6 */
#define loaded_table_0279FA_ADDRESS 0x79FAu    /* 0279FA */
#define loaded_table_027A00_ADDRESS 0x7A00u    /* 027A00 */
#define loaded_table_027A13_ADDRESS 0x7A13u    /* 027A13 */
#define loaded_table_027A1D_ADDRESS 0x7A1Du    /* 027A1D */
#define loaded_table_027A27_ADDRESS 0x7A27u    /* 027A27 */
#define loaded_table_027A2F_ADDRESS 0x7A2Fu    /* 027A2F */
#define record_027A3B_ADDRESS 0x7A3Bu    /* 027A3B */
#define record_027A3F_ADDRESS 0x7A3Fu    /* 027A3F */
#define loaded_table_027A43_ADDRESS 0x7A43u    /* 027A43 */
#define loaded_table_027A53_ADDRESS 0x7A53u    /* 027A53 */
#define loaded_table_027A5B_ADDRESS 0x7A5Bu    /* 027A5B */
#define loaded_table_027C64_ADDRESS 0x7C64u    /* 027C64 */
#define loaded_table_027C70_ADDRESS 0x7C70u    /* 027C70 */
#define loaded_table_027C78_ADDRESS 0x7C78u    /* 027C78 */
#define loaded_table_027C7C_ADDRESS 0x7C7Cu    /* 027C7C */
#define loaded_table_027C88_ADDRESS 0x7C88u    /* 027C88 */
#define loaded_table_027C8E_ADDRESS 0x7C8Eu    /* 027C8E */
#define loaded_table_027C98_ADDRESS 0x7C98u    /* 027C98 */
#define loaded_table_027C9C_ADDRESS 0x7C9Cu    /* 027C9C */
#define loaded_table_027CA2_ADDRESS 0x7CA2u    /* 027CA2 */
#define loaded_table_027CAA_ADDRESS 0x7CAAu    /* 027CAA */
#define indexed_table_027CD0_ADDRESS 0x7CD0u    /* 027CD0 */
#define indexed_table_027CD2_ADDRESS 0x7CD2u    /* 027CD2 */
#define indexed_table_027CD4_ADDRESS 0x7CD4u    /* 027CD4 */
#define indexed_table_027CD6_ADDRESS 0x7CD6u    /* 027CD6 */
#define indexed_table_027CD8_ADDRESS 0x7CD8u    /* 027CD8 */
#define indexed_table_027CDA_ADDRESS 0x7CDAu    /* 027CDA */
#define indexed_table_027CDC_ADDRESS 0x7CDCu    /* 027CDC */
#define indexed_table_027CDE_ADDRESS 0x7CDEu    /* 027CDE */
#define indexed_table_027CE0_ADDRESS 0x7CE0u    /* 027CE0 */
#define indexed_table_027CE2_ADDRESS 0x7CE2u    /* 027CE2 */
#define indexed_table_027CE4_ADDRESS 0x7CE4u    /* 027CE4 */
#define indexed_table_027CE6_ADDRESS 0x7CE6u    /* 027CE6 */
#define indexed_table_027CE8_ADDRESS 0x7CE8u    /* 027CE8 */
#define indexed_table_027CEA_ADDRESS 0x7CEAu    /* 027CEA */
#define indexed_table_027CEC_ADDRESS 0x7CECu    /* 027CEC */
#define indexed_table_027CEE_ADDRESS 0x7CEEu    /* 027CEE */
#define indexed_table_027CF0_ADDRESS 0x7CF0u    /* 027CF0 */
#define indexed_table_027CF2_ADDRESS 0x7CF2u    /* 027CF2 */
#define indexed_table_027CF4_ADDRESS 0x7CF4u    /* 027CF4 */
#define indexed_table_027CF6_ADDRESS 0x7CF6u    /* 027CF6 */
#define indexed_table_027CF8_ADDRESS 0x7CF8u    /* 027CF8 */
#define indexed_table_027CFA_ADDRESS 0x7CFAu    /* 027CFA */
#define indexed_table_027CFC_ADDRESS 0x7CFCu    /* 027CFC */
#define indexed_table_027CFE_ADDRESS 0x7CFEu    /* 027CFE */
#define loaded_table_027D3A_ADDRESS 0x7D3Au    /* 027D3A */
#define loaded_table_027D42_ADDRESS 0x7D42u    /* 027D42 */
#define loaded_table_027D5A_ADDRESS 0x7D5Au    /* 027D5A */
#define loaded_table_027D60_ADDRESS 0x7D60u    /* 027D60 */
#define loaded_table_027D66_ADDRESS 0x7D66u    /* 027D66 */
#define loaded_table_027D6C_ADDRESS 0x7D6Cu    /* 027D6C */
#define loaded_table_027D72_ADDRESS 0x7D72u    /* 027D72 */
#define loaded_table_027D78_ADDRESS 0x7D78u    /* 027D78 */
#define loaded_table_027D7E_ADDRESS 0x7D7Eu    /* 027D7E */
#define loaded_table_027D86_ADDRESS 0x7D86u    /* 027D86 */
#define text_027D8C_ADDRESS 0x7D8Cu    /* 027D8C */
#define text_027DAD_ADDRESS 0x7DADu    /* 027DAD */
#define text_027DC4_ADDRESS 0x7DC4u    /* 027DC4 */
#define text_027DF0_ADDRESS 0x7DF0u    /* 027DF0 */
#define text_027E09_ADDRESS 0x7E09u    /* 027E09 */
#define text_027E27_ADDRESS 0x7E27u    /* 027E27 */
#define text_027E3D_ADDRESS 0x7E3Du    /* 027E3D */
#define text_027E53_ADDRESS 0x7E53u    /* 027E53 */
#define loaded_table_027E81_ADDRESS 0x7E81u    /* 027E81 */
#define loaded_table_027ED1_ADDRESS 0x7ED1u    /* 027ED1 */
#define loaded_table_027EDD_ADDRESS 0x7EDDu    /* 027EDD */
#define loaded_table_027EE3_ADDRESS 0x7EE3u    /* 027EE3 */
#define loaded_table_027EE7_ADDRESS 0x7EE7u    /* 027EE7 */
#define loaded_table_027EFD_ADDRESS 0x7EFDu    /* 027EFD */
#define loaded_table_027F05_ADDRESS 0x7F05u    /* 027F05 */
#define loaded_table_027F09_ADDRESS 0x7F09u    /* 027F09 */
#define loaded_table_027F0F_ADDRESS 0x7F0Fu    /* 027F0F */
#define indexed_table_027F11_ADDRESS 0x7F11u    /* 027F11 */
#define indexed_table_027F12_ADDRESS 0x7F12u    /* 027F12 */
#define indexed_table_027F13_ADDRESS 0x7F13u    /* 027F13 */
#define indexed_table_027F14_ADDRESS 0x7F14u    /* 027F14 */
#define indexed_table_027F17_ADDRESS 0x7F17u    /* 027F17 */
#define indexed_table_027F18_ADDRESS 0x7F18u    /* 027F18 */
#define indexed_table_027F19_ADDRESS 0x7F19u    /* 027F19 */
#define indexed_table_027F1A_ADDRESS 0x7F1Au    /* 027F1A */
#define indexed_table_027F1D_ADDRESS 0x7F1Du    /* 027F1D */
#define indexed_table_027F1E_ADDRESS 0x7F1Eu    /* 027F1E */
#define indexed_table_027F1F_ADDRESS 0x7F1Fu    /* 027F1F */
#define indexed_table_027F20_ADDRESS 0x7F20u    /* 027F20 */
#define indexed_table_027F23_ADDRESS 0x7F23u    /* 027F23 */
#define indexed_table_027F24_ADDRESS 0x7F24u    /* 027F24 */
#define indexed_table_027F25_ADDRESS 0x7F25u    /* 027F25 */
#define indexed_table_027F26_ADDRESS 0x7F26u    /* 027F26 */
#define loaded_table_027F27_ADDRESS 0x7F27u    /* 027F27 */
#define indexed_table_027F29_ADDRESS 0x7F29u    /* 027F29 */
#define indexed_table_027F2A_ADDRESS 0x7F2Au    /* 027F2A */
#define indexed_table_027F2B_ADDRESS 0x7F2Bu    /* 027F2B */
#define indexed_table_027F2C_ADDRESS 0x7F2Cu    /* 027F2C */
#define indexed_table_027F2F_ADDRESS 0x7F2Fu    /* 027F2F */
#define indexed_table_027F30_ADDRESS 0x7F30u    /* 027F30 */
#define indexed_table_027F31_ADDRESS 0x7F31u    /* 027F31 */
#define indexed_table_027F32_ADDRESS 0x7F32u    /* 027F32 */
#define indexed_table_027F35_ADDRESS 0x7F35u    /* 027F35 */
#define indexed_table_027F36_ADDRESS 0x7F36u    /* 027F36 */
#define indexed_table_027F37_ADDRESS 0x7F37u    /* 027F37 */
#define indexed_table_027F38_ADDRESS 0x7F38u    /* 027F38 */
#define indexed_table_027F3B_ADDRESS 0x7F3Bu    /* 027F3B */
#define indexed_table_027F3C_ADDRESS 0x7F3Cu    /* 027F3C */
#define indexed_table_027F3D_ADDRESS 0x7F3Du    /* 027F3D */
#define indexed_table_027F3E_ADDRESS 0x7F3Eu    /* 027F3E */
#define loaded_table_027F3F_ADDRESS 0x7F3Fu    /* 027F3F */
#define indexed_table_027F41_ADDRESS 0x7F41u    /* 027F41 */
#define indexed_table_027F42_ADDRESS 0x7F42u    /* 027F42 */
#define object_start_027F43_ADDRESS 0x7F43u    /* 027F43 */
#define object_start_027F4D_ADDRESS 0x7F4Du    /* 027F4D */
#define object_start_027F57_ADDRESS 0x7F57u    /* 027F57 */
#define object_start_027F61_ADDRESS 0x7F61u    /* 027F61 */
#define object_start_027F6B_ADDRESS 0x7F6Bu    /* 027F6B */
#define object_start_027F75_ADDRESS 0x7F75u    /* 027F75 */
#define object_start_027F7F_ADDRESS 0x7F7Fu    /* 027F7F */
#define object_start_027F89_ADDRESS 0x7F89u    /* 027F89 */
#define object_start_027F93_ADDRESS 0x7F93u    /* 027F93 */
#define object_start_027F9D_ADDRESS 0x7F9Du    /* 027F9D */
#define object_start_027FA7_ADDRESS 0x7FA7u    /* 027FA7 */
#define object_start_027FB1_ADDRESS 0x7FB1u    /* 027FB1 */
#define object_start_027FBB_ADDRESS 0x7FBBu    /* 027FBB */
#define object_start_027FC5_ADDRESS 0x7FC5u    /* 027FC5 */
#define object_start_027FCF_ADDRESS 0x7FCFu    /* 027FCF */
#define object_start_027FD9_ADDRESS 0x7FD9u    /* 027FD9 */
#define object_start_027FE3_ADDRESS 0x7FE3u    /* 027FE3 */
#define loaded_table_027FED_ADDRESS 0x7FEDu    /* 027FED */
#define loaded_table_027FF3_ADDRESS 0x7FF3u    /* 027FF3 */
#define fill_0295C1_ADDRESS 0x75C1u    /* 0295C1 */
#define hit_box_029800_ADDRESS 0x7800u    /* 029800 */
#define enemy_behaviour_029808_ADDRESS 0x7808u    /* 029808 */
#define enemy_behaviour_029860_ADDRESS 0x7860u    /* 029860 */
#define enemy_behaviour_0298B8_ADDRESS 0x78B8u    /* 0298B8 */
#define enemy_behaviour_029910_ADDRESS 0x7910u    /* 029910 */
#define loaded_table_029974_ADDRESS 0x7974u    /* 029974 */
#define loaded_table_029980_ADDRESS 0x7980u    /* 029980 */
#define loaded_table_02998C_ADDRESS 0x798Cu    /* 02998C */
#define loaded_table_029998_ADDRESS 0x7998u    /* 029998 */
#define loaded_table_0299A4_ADDRESS 0x79A4u    /* 0299A4 */
#define object_setup_0299B0_ADDRESS 0x79B0u    /* 0299B0 */
#define hit_box_0299B6_ADDRESS 0x79B6u    /* 0299B6 */
#define hit_box_0299BE_ADDRESS 0x79BEu    /* 0299BE */
#define hit_box_0299C6_ADDRESS 0x79C6u    /* 0299C6 */
#define hit_box_0299CE_ADDRESS 0x79CEu    /* 0299CE */
#define object_setup_0299D6_ADDRESS 0x79D6u    /* 0299D6 */
#define loaded_table_0299DC_ADDRESS 0x79DCu    /* 0299DC */
#define loaded_table_0299E8_ADDRESS 0x79E8u    /* 0299E8 */
#define child_object_0299EC_ADDRESS 0x79ECu    /* 0299EC */
#define loaded_table_0299F4_ADDRESS 0x79F4u    /* 0299F4 */
#define loaded_table_029A14_ADDRESS 0x7A14u    /* 029A14 */
#define loaded_table_029A20_ADDRESS 0x7A20u    /* 029A20 */
#define loaded_table_029A28_ADDRESS 0x7A28u    /* 029A28 */
#define loaded_table_029A34_ADDRESS 0x7A34u    /* 029A34 */
#define loaded_table_029A40_ADDRESS 0x7A40u    /* 029A40 */
#define loaded_table_029A44_ADDRESS 0x7A44u    /* 029A44 */
#define loaded_table_029A50_ADDRESS 0x7A50u    /* 029A50 */
#define loaded_table_029A5C_ADDRESS 0x7A5Cu    /* 029A5C */
#define loaded_table_029A60_ADDRESS 0x7A60u    /* 029A60 */
#define loaded_table_029A6C_ADDRESS 0x7A6Cu    /* 029A6C */
#define loaded_table_029A7A_ADDRESS 0x7A7Au    /* 029A7A */
#define loaded_table_029A86_ADDRESS 0x7A86u    /* 029A86 */
#define loaded_table_029A92_ADDRESS 0x7A92u    /* 029A92 */
#define loaded_table_029A9C_ADDRESS 0x7A9Cu    /* 029A9C */
#define object_setup_029AA8_ADDRESS 0x7AA8u    /* 029AA8 */
#define loaded_table_029AAE_ADDRESS 0x7AAEu    /* 029AAE */
#define loaded_table_029ABE_ADDRESS 0x7ABEu    /* 029ABE */
#define loaded_table_029AC6_ADDRESS 0x7AC6u    /* 029AC6 */
#define loaded_table_029AD2_ADDRESS 0x7AD2u    /* 029AD2 */
#define loaded_table_029AE2_ADDRESS 0x7AE2u    /* 029AE2 */
#define loaded_table_029AE8_ADDRESS 0x7AE8u    /* 029AE8 */
#define loaded_table_029AF4_ADDRESS 0x7AF4u    /* 029AF4 */
#define loaded_table_029AFE_ADDRESS 0x7AFEu    /* 029AFE */
#define loaded_table_029B0A_ADDRESS 0x7B0Au    /* 029B0A */
#define loaded_table_029B30_ADDRESS 0x7B30u    /* 029B30 */
#define loaded_table_029B3C_ADDRESS 0x7B3Cu    /* 029B3C */
#define loaded_table_029B48_ADDRESS 0x7B48u    /* 029B48 */
#define loaded_table_029B50_ADDRESS 0x7B50u    /* 029B50 */
#define loaded_table_029B5C_ADDRESS 0x7B5Cu    /* 029B5C */
#define loaded_table_029B68_ADDRESS 0x7B68u    /* 029B68 */
#define loaded_table_029B6C_ADDRESS 0x7B6Cu    /* 029B6C */
#define loaded_table_029B72_ADDRESS 0x7B72u    /* 029B72 */
#define loaded_table_029B7E_ADDRESS 0x7B7Eu    /* 029B7E */
#define loaded_table_029B86_ADDRESS 0x7B86u    /* 029B86 */
#define loaded_table_029B8C_ADDRESS 0x7B8Cu    /* 029B8C */
#define loaded_table_029B98_ADDRESS 0x7B98u    /* 029B98 */
#define loaded_table_029BB0_ADDRESS 0x7BB0u    /* 029BB0 */
#define loaded_table_029BBC_ADDRESS 0x7BBCu    /* 029BBC */
#define loaded_table_029BCC_ADDRESS 0x7BCCu    /* 029BCC */
#define loaded_table_029BD4_ADDRESS 0x7BD4u    /* 029BD4 */
#define loaded_table_029BE8_ADDRESS 0x7BE8u    /* 029BE8 */
#define hit_box_029BEE_ADDRESS 0x7BEEu    /* 029BEE */
#define hit_box_029BF6_ADDRESS 0x7BF6u    /* 029BF6 */
#define hit_box_029BFE_ADDRESS 0x7BFEu    /* 029BFE */
#define hit_box_029C06_ADDRESS 0x7C06u    /* 029C06 */
#define hit_box_029C0E_ADDRESS 0x7C0Eu    /* 029C0E */
#define hit_box_029C16_ADDRESS 0x7C16u    /* 029C16 */
#define hit_box_029C1E_ADDRESS 0x7C1Eu    /* 029C1E */
#define hit_box_029C26_ADDRESS 0x7C26u    /* 029C26 */
#define loaded_table_029C4E_ADDRESS 0x7C4Eu    /* 029C4E */
#define loaded_table_029C5A_ADDRESS 0x7C5Au    /* 029C5A */
#define loaded_table_029C5E_ADDRESS 0x7C5Eu    /* 029C5E */
#define loaded_table_029C68_ADDRESS 0x7C68u    /* 029C68 */
#define loaded_table_029C70_ADDRESS 0x7C70u    /* 029C70 */
#define loaded_table_029C7F_ADDRESS 0x7C7Fu    /* 029C7F */
#define loaded_table_029C89_ADDRESS 0x7C89u    /* 029C89 */
#define loaded_table_029C91_ADDRESS 0x7C91u    /* 029C91 */
#define loaded_table_029C99_ADDRESS 0x7C99u    /* 029C99 */
#define loaded_table_029CC3_ADDRESS 0x7CC3u    /* 029CC3 */
#define loaded_table_029CCB_ADDRESS 0x7CCBu    /* 029CCB */
#define hit_box_029CD7_ADDRESS 0x7CD7u    /* 029CD7 */
#define enemy_behaviour_029CDF_ADDRESS 0x7CDFu    /* 029CDF */
#define enemy_behaviour_029D37_ADDRESS 0x7D37u    /* 029D37 */
#define enemy_behaviour_029D8F_ADDRESS 0x7D8Fu    /* 029D8F */
#define enemy_behaviour_029DE7_ADDRESS 0x7DE7u    /* 029DE7 */
#define loaded_table_029E3F_ADDRESS 0x7E3Fu    /* 029E3F */
#define object_setup_029E4B_ADDRESS 0x7E4Bu    /* 029E4B */
#define loaded_table_029E51_ADDRESS 0x7E51u    /* 029E51 */
#define object_setup_029E5D_ADDRESS 0x7E5Du    /* 029E5D */
#define loaded_table_029E63_ADDRESS 0x7E63u    /* 029E63 */
#define object_setup_029E6F_ADDRESS 0x7E6Fu    /* 029E6F */
#define loaded_table_029E75_ADDRESS 0x7E75u    /* 029E75 */
#define object_setup_029E81_ADDRESS 0x7E81u    /* 029E81 */
#define hit_box_029E87_ADDRESS 0x7E87u    /* 029E87 */
#define hit_box_029E8F_ADDRESS 0x7E8Fu    /* 029E8F */
#define hit_box_029E97_ADDRESS 0x7E97u    /* 029E97 */
#define hit_box_029E9F_ADDRESS 0x7E9Fu    /* 029E9F */
#define hit_box_029EA7_ADDRESS 0x7EA7u    /* 029EA7 */
#define hit_box_029EAF_ADDRESS 0x7EAFu    /* 029EAF */
#define hit_box_029EB7_ADDRESS 0x7EB7u    /* 029EB7 */
#define hit_box_029EBF_ADDRESS 0x7EBFu    /* 029EBF */
#define hit_box_029EC7_ADDRESS 0x7EC7u    /* 029EC7 */
#define loaded_table_029ECF_ADDRESS 0x7ECFu    /* 029ECF */
#define child_object_029ED5_ADDRESS 0x7ED5u    /* 029ED5 */
#define loaded_table_029EDB_ADDRESS 0x7EDBu    /* 029EDB */
#define loaded_table_029EEA_ADDRESS 0x7EEAu    /* 029EEA */
#define loaded_table_029EF9_ADDRESS 0x7EF9u    /* 029EF9 */
#define loaded_table_029F03_ADDRESS 0x7F03u    /* 029F03 */
#define loaded_table_029F0B_ADDRESS 0x7F0Bu    /* 029F0B */
#define loaded_table_029F13_ADDRESS 0x7F13u    /* 029F13 */
#define loaded_table_029F1B_ADDRESS 0x7F1Bu    /* 029F1B */
#define loaded_table_029F21_ADDRESS 0x7F21u    /* 029F21 */
#define loaded_table_029F27_ADDRESS 0x7F27u    /* 029F27 */
#define child_object_029F2F_ADDRESS 0x7F2Fu    /* 029F2F */
#define hit_box_029F35_ADDRESS 0x7F35u    /* 029F35 */
#define hit_box_029F3D_ADDRESS 0x7F3Du    /* 029F3D */
#define hit_box_029F45_ADDRESS 0x7F45u    /* 029F45 */
#define object_setup_029F55_ADDRESS 0x7F55u    /* 029F55 */
#define loaded_table_029F5B_ADDRESS 0x7F5Bu    /* 029F5B */
#define loaded_table_029F67_ADDRESS 0x7F67u    /* 029F67 */
#define child_object_029F6D_ADDRESS 0x7F6Du    /* 029F6D */
#define hit_box_029F73_ADDRESS 0x7F73u    /* 029F73 */
#define hit_box_029F7B_ADDRESS 0x7F7Bu    /* 029F7B */
#define hit_box_029F83_ADDRESS 0x7F83u    /* 029F83 */
#define loaded_table_029F9F_ADDRESS 0x7F9Fu    /* 029F9F */
#define loaded_table_029FA3_ADDRESS 0x7FA3u    /* 029FA3 */
#define loaded_table_029FB3_ADDRESS 0x7FB3u    /* 029FB3 */
#define loaded_table_029FB7_ADDRESS 0x7FB7u    /* 029FB7 */
#define fill_029FFF_ADDRESS 0x7FFFu    /* 029FFF */
#define fill_02A224_ADDRESS 0x6224u    /* 02A224 */
#define fill_02B518_ADDRESS 0x7518u    /* 02B518 */
#define hit_box_02B5E0_ADDRESS 0x75E0u    /* 02B5E0 */
#define enemy_behaviour_02B5E8_ADDRESS 0x75E8u    /* 02B5E8 */
#define loaded_table_02B640_ADDRESS 0x7640u    /* 02B640 */
#define object_setup_02B64C_ADDRESS 0x764Cu    /* 02B64C */
#define hit_box_02B652_ADDRESS 0x7652u    /* 02B652 */
#define enemy_behaviour_02B65A_ADDRESS 0x765Au    /* 02B65A */
#define enemy_behaviour_02B6B2_ADDRESS 0x76B2u    /* 02B6B2 */
#define enemy_behaviour_02B70A_ADDRESS 0x770Au    /* 02B70A */
#define enemy_behaviour_02B762_ADDRESS 0x7762u    /* 02B762 */
#define loaded_table_02B7BA_ADDRESS 0x77BAu    /* 02B7BA */
#define object_setup_02B7C6_ADDRESS 0x77C6u    /* 02B7C6 */
#define loaded_table_02B7CC_ADDRESS 0x77CCu    /* 02B7CC */
#define loaded_table_02B7D8_ADDRESS 0x77D8u    /* 02B7D8 */
#define loaded_table_02B7E4_ADDRESS 0x77E4u    /* 02B7E4 */
#define hit_box_02B7F0_ADDRESS 0x77F0u    /* 02B7F0 */
#define loaded_table_02B7F8_ADDRESS 0x77F8u    /* 02B7F8 */
#define loaded_table_02B804_ADDRESS 0x7804u    /* 02B804 */
#define loaded_table_02B810_ADDRESS 0x7810u    /* 02B810 */
#define loaded_table_02B822_ADDRESS 0x7822u    /* 02B822 */
#define loaded_table_02B82A_ADDRESS 0x782Au    /* 02B82A */
#define loaded_table_02B836_ADDRESS 0x7836u    /* 02B836 */
#define loaded_table_02B83E_ADDRESS 0x783Eu    /* 02B83E */
#define loaded_table_02B862_ADDRESS 0x7862u    /* 02B862 */
#define loaded_table_02B86E_ADDRESS 0x786Eu    /* 02B86E */
#define loaded_table_02B87A_ADDRESS 0x787Au    /* 02B87A */
#define loaded_table_02B87E_ADDRESS 0x787Eu    /* 02B87E */
#define loaded_table_02B88A_ADDRESS 0x788Au    /* 02B88A */
#define loaded_table_02B898_ADDRESS 0x7898u    /* 02B898 */
#define loaded_table_02B8A4_ADDRESS 0x78A4u    /* 02B8A4 */
#define child_object_02B8AC_ADDRESS 0x78ACu    /* 02B8AC */
#define loaded_table_02B8B4_ADDRESS 0x78B4u    /* 02B8B4 */
#define loaded_table_02B8C0_ADDRESS 0x78C0u    /* 02B8C0 */
#define loaded_table_02B8D0_ADDRESS 0x78D0u    /* 02B8D0 */
#define loaded_table_02B8D6_ADDRESS 0x78D6u    /* 02B8D6 */
#define loaded_table_02B8E2_ADDRESS 0x78E2u    /* 02B8E2 */
#define child_object_02B8E6_ADDRESS 0x78E6u    /* 02B8E6 */
#define loaded_table_02B8EE_ADDRESS 0x78EEu    /* 02B8EE */
#define loaded_table_02B8F6_ADDRESS 0x78F6u    /* 02B8F6 */
#define object_setup_02B8FE_ADDRESS 0x78FEu    /* 02B8FE */
#define hit_box_02B904_ADDRESS 0x7904u    /* 02B904 */
#define hit_box_02B90C_ADDRESS 0x790Cu    /* 02B90C */
#define hit_box_02B914_ADDRESS 0x7914u    /* 02B914 */
#define hit_box_02B91C_ADDRESS 0x791Cu    /* 02B91C */
#define hit_box_02B924_ADDRESS 0x7924u    /* 02B924 */
#define hit_box_02B92C_ADDRESS 0x792Cu    /* 02B92C */
#define hit_box_02B934_ADDRESS 0x7934u    /* 02B934 */
#define hit_box_02B93C_ADDRESS 0x793Cu    /* 02B93C */
#define loaded_table_02B979_ADDRESS 0x7979u    /* 02B979 */
#define loaded_table_02B983_ADDRESS 0x7983u    /* 02B983 */
#define loaded_table_02B985_ADDRESS 0x7985u    /* 02B985 */
#define loaded_table_02B98D_ADDRESS 0x798Du    /* 02B98D */
#define loaded_table_02B999_ADDRESS 0x7999u    /* 02B999 */
#define loaded_table_02B9A9_ADDRESS 0x79A9u    /* 02B9A9 */
#define loaded_table_02B9AD_ADDRESS 0x79ADu    /* 02B9AD */
#define loaded_table_02B9BD_ADDRESS 0x79BDu    /* 02B9BD */
#define loaded_table_02B9C1_ADDRESS 0x79C1u    /* 02B9C1 */
#define child_object_02B9C5_ADDRESS 0x79C5u    /* 02B9C5 */
#define child_object_02B9CD_ADDRESS 0x79CDu    /* 02B9CD */
#define child_object_02B9D5_ADDRESS 0x79D5u    /* 02B9D5 */
#define child_object_02B9DD_ADDRESS 0x79DDu    /* 02B9DD */
#define loaded_table_02B9E5_ADDRESS 0x79E5u    /* 02B9E5 */
#define loaded_table_02B9E9_ADDRESS 0x79E9u    /* 02B9E9 */
#define spawn_list_02BA4C_ADDRESS 0x7A4Cu    /* 02BA4C */
#define spawn_list_02BA84_ADDRESS 0x7A84u    /* 02BA84 */
#define spawn_list_02BA9C_ADDRESS 0x7A9Cu    /* 02BA9C */
#define spawn_list_02BAD4_ADDRESS 0x7AD4u    /* 02BAD4 */
#define spawn_list_02BAF4_ADDRESS 0x7AF4u    /* 02BAF4 */
#define spawn_list_02BB34_ADDRESS 0x7B34u    /* 02BB34 */
#define spawn_list_02BB6C_ADDRESS 0x7B6Cu    /* 02BB6C */
#define spawn_list_02BB9C_ADDRESS 0x7B9Cu    /* 02BB9C */
#define spawn_list_02BBDC_ADDRESS 0x7BDCu    /* 02BBDC */
#define spawn_list_02BC64_ADDRESS 0x7C64u    /* 02BC64 */
#define spawn_list_02BCCC_ADDRESS 0x7CCCu    /* 02BCCC */
#define spawn_list_02BCF4_ADDRESS 0x7CF4u    /* 02BCF4 */
#define spawn_list_02BD2C_ADDRESS 0x7D2Cu    /* 02BD2C */
#define hit_box_02BD4C_ADDRESS 0x7D4Cu    /* 02BD4C */
#define hit_box_02BD54_ADDRESS 0x7D54u    /* 02BD54 */
#define hit_box_02BD5C_ADDRESS 0x7D5Cu    /* 02BD5C */
#define hit_box_02BD64_ADDRESS 0x7D64u    /* 02BD64 */
#define loaded_table_02BD6C_ADDRESS 0x7D6Cu    /* 02BD6C */
#define object_setup_02BD72_ADDRESS 0x7D72u    /* 02BD72 */
#define child_object_02BD78_ADDRESS 0x7D78u    /* 02BD78 */
#define loaded_table_02BD80_ADDRESS 0x7D80u    /* 02BD80 */
#define object_setup_02BD88_ADDRESS 0x7D88u    /* 02BD88 */
#define child_object_02BD8E_ADDRESS 0x7D8Eu    /* 02BD8E */
#define loaded_table_02BD96_ADDRESS 0x7D96u    /* 02BD96 */
#define object_setup_02BDA2_ADDRESS 0x7DA2u    /* 02BDA2 */
#define child_object_02BDA8_ADDRESS 0x7DA8u    /* 02BDA8 */
#define loaded_table_02BDB0_ADDRESS 0x7DB0u    /* 02BDB0 */
#define object_setup_02BDBC_ADDRESS 0x7DBCu    /* 02BDBC */
#define loaded_table_02BDC2_ADDRESS 0x7DC2u    /* 02BDC2 */
#define loaded_table_02BDFD_ADDRESS 0x7DFDu    /* 02BDFD */
#define child_object_02BE0B_ADDRESS 0x7E0Bu    /* 02BE0B */
#define object_setup_02BE13_ADDRESS 0x7E13u    /* 02BE13 */
#define loaded_table_02BE19_ADDRESS 0x7E19u    /* 02BE19 */
#define object_setup_02BE1D_ADDRESS 0x7E1Du    /* 02BE1D */
#define loaded_table_02BE23_ADDRESS 0x7E23u    /* 02BE23 */
#define loaded_table_02BE53_ADDRESS 0x7E53u    /* 02BE53 */
#define object_setup_02BE57_ADDRESS 0x7E57u    /* 02BE57 */
#define loaded_table_02BE5D_ADDRESS 0x7E5Du    /* 02BE5D */
#define object_setup_02BE61_ADDRESS 0x7E61u    /* 02BE61 */
#define child_object_02BE67_ADDRESS 0x7E67u    /* 02BE67 */
#define loaded_table_02BE6F_ADDRESS 0x7E6Fu    /* 02BE6F */
#define object_setup_02BE79_ADDRESS 0x7E79u    /* 02BE79 */
#define loaded_table_02BE7F_ADDRESS 0x7E7Fu    /* 02BE7F */
#define object_setup_02BE83_ADDRESS 0x7E83u    /* 02BE83 */
#define loaded_table_02BE89_ADDRESS 0x7E89u    /* 02BE89 */
#define hit_box_02BE99_ADDRESS 0x7E99u    /* 02BE99 */
#define hit_box_02BEA1_ADDRESS 0x7EA1u    /* 02BEA1 */
#define object_setup_02BED1_ADDRESS 0x7ED1u    /* 02BED1 */
#define hit_box_02BED7_ADDRESS 0x7ED7u    /* 02BED7 */
#define loaded_table_02BEDF_ADDRESS 0x7EDFu    /* 02BEDF */
#define object_setup_02BEE5_ADDRESS 0x7EE5u    /* 02BEE5 */
#define loaded_table_02BEEB_ADDRESS 0x7EEBu    /* 02BEEB */
#define loaded_table_02BEF3_ADDRESS 0x7EF3u    /* 02BEF3 */
#define loaded_table_02BEFF_ADDRESS 0x7EFFu    /* 02BEFF */
#define loaded_table_02BF0B_ADDRESS 0x7F0Bu    /* 02BF0B */
#define hit_box_02BF17_ADDRESS 0x7F17u    /* 02BF17 */
#define hit_box_02BF1F_ADDRESS 0x7F1Fu    /* 02BF1F */
#define object_setup_02BF3F_ADDRESS 0x7F3Fu    /* 02BF3F */
#define hit_box_02BF45_ADDRESS 0x7F45u    /* 02BF45 */
#define described_02BF4D_ADDRESS 0x7F4Du    /* 02BF4D */
#define loaded_table_02BF51_ADDRESS 0x7F51u    /* 02BF51 */
#define loaded_table_02BF5D_ADDRESS 0x7F5Du    /* 02BF5D */
#define object_setup_02BF63_ADDRESS 0x7F63u    /* 02BF63 */
#define loaded_table_02BF69_ADDRESS 0x7F69u    /* 02BF69 */
#define fill_02BF71_ADDRESS 0x7F71u    /* 02BF71 */
#define fill_02DA14_ADDRESS 0x7A14u    /* 02DA14 */
#define hit_box_02DA98_ADDRESS 0x7A98u    /* 02DA98 */
#define hit_box_02DAA0_ADDRESS 0x7AA0u    /* 02DAA0 */
#define hit_box_02DAA8_ADDRESS 0x7AA8u    /* 02DAA8 */
#define hit_box_02DAB0_ADDRESS 0x7AB0u    /* 02DAB0 */
#define hit_box_02DAB8_ADDRESS 0x7AB8u    /* 02DAB8 */
#define hit_box_02DAC0_ADDRESS 0x7AC0u    /* 02DAC0 */
#define hit_box_02DAC8_ADDRESS 0x7AC8u    /* 02DAC8 */
#define hit_box_02DAD0_ADDRESS 0x7AD0u    /* 02DAD0 */
#define hit_box_02DAD8_ADDRESS 0x7AD8u    /* 02DAD8 */
#define hit_box_02DAE0_ADDRESS 0x7AE0u    /* 02DAE0 */
#define hit_box_02DAE8_ADDRESS 0x7AE8u    /* 02DAE8 */
#define hit_box_02DAF0_ADDRESS 0x7AF0u    /* 02DAF0 */
#define hit_box_02DAF8_ADDRESS 0x7AF8u    /* 02DAF8 */
#define hit_box_02DB00_ADDRESS 0x7B00u    /* 02DB00 */
#define hit_box_02DB08_ADDRESS 0x7B08u    /* 02DB08 */
#define hit_box_02DB10_ADDRESS 0x7B10u    /* 02DB10 */
#define hit_box_02DB18_ADDRESS 0x7B18u    /* 02DB18 */
#define hit_box_02DB20_ADDRESS 0x7B20u    /* 02DB20 */
#define hit_box_02DB28_ADDRESS 0x7B28u    /* 02DB28 */
#define hit_box_02DB30_ADDRESS 0x7B30u    /* 02DB30 */
#define hit_box_02DB38_ADDRESS 0x7B38u    /* 02DB38 */
#define described_02DB40_ADDRESS 0x7B40u    /* 02DB40 */
#define loaded_table_02DB44_ADDRESS 0x7B44u    /* 02DB44 */
#define loaded_table_02DB4C_ADDRESS 0x7B4Cu    /* 02DB4C */
#define child_object_02DB52_ADDRESS 0x7B52u    /* 02DB52 */
#define object_setup_02DBA8_ADDRESS 0x7BA8u    /* 02DBA8 */
#define described_02DBAE_ADDRESS 0x7BAEu    /* 02DBAE */
#define loaded_table_02DBB2_ADDRESS 0x7BB2u    /* 02DBB2 */
#define loaded_table_02DBBA_ADDRESS 0x7BBAu    /* 02DBBA */
#define loaded_table_02DBCC_ADDRESS 0x7BCCu    /* 02DBCC */
#define loaded_table_02DBD0_ADDRESS 0x7BD0u    /* 02DBD0 */
#define object_setup_02DBDC_ADDRESS 0x7BDCu    /* 02DBDC */
#define loaded_table_02DBE2_ADDRESS 0x7BE2u    /* 02DBE2 */
#define object_setup_02DBEC_ADDRESS 0x7BECu    /* 02DBEC */
#define record_02DC12_ADDRESS 0x7C12u    /* 02DC12 */
#define record_02DC18_ADDRESS 0x7C18u    /* 02DC18 */
#define loaded_table_02DC1E_ADDRESS 0x7C1Eu    /* 02DC1E */
#define object_setup_02DC28_ADDRESS 0x7C28u    /* 02DC28 */
#define loaded_table_02DC2E_ADDRESS 0x7C2Eu    /* 02DC2E */
#define described_02DC70_ADDRESS 0x7C70u    /* 02DC70 */
#define loaded_table_02DC71_ADDRESS 0x7C71u    /* 02DC71 */
#define loaded_table_02DC83_ADDRESS 0x7C83u    /* 02DC83 */
#define object_setup_02DC91_ADDRESS 0x7C91u    /* 02DC91 */
#define loaded_table_02DC97_ADDRESS 0x7C97u    /* 02DC97 */
#define loaded_table_02DC9B_ADDRESS 0x7C9Bu    /* 02DC9B */
#define loaded_table_02DCA5_ADDRESS 0x7CA5u    /* 02DCA5 */
#define loaded_table_02DCB5_ADDRESS 0x7CB5u    /* 02DCB5 */
#define object_setup_02DCB9_ADDRESS 0x7CB9u    /* 02DCB9 */
#define loaded_table_02DCBF_ADDRESS 0x7CBFu    /* 02DCBF */
#define loaded_table_02DCD1_ADDRESS 0x7CD1u    /* 02DCD1 */
#define object_setup_02DCDB_ADDRESS 0x7CDBu    /* 02DCDB */
#define loaded_table_02DCE1_ADDRESS 0x7CE1u    /* 02DCE1 */
#define loaded_table_02DCED_ADDRESS 0x7CEDu    /* 02DCED */
#define loaded_table_02DCF9_ADDRESS 0x7CF9u    /* 02DCF9 */
#define loaded_table_02DD05_ADDRESS 0x7D05u    /* 02DD05 */
#define loaded_table_02DD11_ADDRESS 0x7D11u    /* 02DD11 */
#define loaded_table_02DD1D_ADDRESS 0x7D1Du    /* 02DD1D */
#define child_object_02DD23_ADDRESS 0x7D23u    /* 02DD23 */
#define child_object_02DD29_ADDRESS 0x7D29u    /* 02DD29 */
#define loaded_table_02DD2F_ADDRESS 0x7D2Fu    /* 02DD2F */
#define object_setup_02DD37_ADDRESS 0x7D37u    /* 02DD37 */
#define loaded_table_02DD3D_ADDRESS 0x7D3Du    /* 02DD3D */
#define loaded_table_02DD45_ADDRESS 0x7D45u    /* 02DD45 */
#define loaded_table_02DD4D_ADDRESS 0x7D4Du    /* 02DD4D */
#define loaded_table_02DD59_ADDRESS 0x7D59u    /* 02DD59 */
#define loaded_table_02DD65_ADDRESS 0x7D65u    /* 02DD65 */
#define loaded_table_02DD71_ADDRESS 0x7D71u    /* 02DD71 */
#define object_setup_02DD7D_ADDRESS 0x7D7Du    /* 02DD7D */
#define child_object_02DD8B_ADDRESS 0x7D8Bu    /* 02DD8B */
#define child_object_02DD93_ADDRESS 0x7D93u    /* 02DD93 */
#define described_02DD9B_ADDRESS 0x7D9Bu    /* 02DD9B */
#define loaded_table_02DD9F_ADDRESS 0x7D9Fu    /* 02DD9F */
#define object_setup_02DDCD_ADDRESS 0x7DCDu    /* 02DDCD */
#define loaded_table_02DDD3_ADDRESS 0x7DD3u    /* 02DDD3 */
#define loaded_table_02DDD7_ADDRESS 0x7DD7u    /* 02DDD7 */
#define loaded_table_02DDDB_ADDRESS 0x7DDBu    /* 02DDDB */
#define object_setup_02DDDF_ADDRESS 0x7DDFu    /* 02DDDF */
#define loaded_table_02DDE5_ADDRESS 0x7DE5u    /* 02DDE5 */
#define object_setup_02DDEF_ADDRESS 0x7DEFu    /* 02DDEF */
#define loaded_table_02DDF5_ADDRESS 0x7DF5u    /* 02DDF5 */
#define loaded_table_02DE05_ADDRESS 0x7E05u    /* 02DE05 */
#define object_setup_02DE0B_ADDRESS 0x7E0Bu    /* 02DE0B */
#define loaded_table_02DE11_ADDRESS 0x7E11u    /* 02DE11 */
#define object_setup_02DE15_ADDRESS 0x7E15u    /* 02DE15 */
#define loaded_table_02DE1B_ADDRESS 0x7E1Bu    /* 02DE1B */
#define object_setup_02DE23_ADDRESS 0x7E23u    /* 02DE23 */
#define child_object_02DE29_ADDRESS 0x7E29u    /* 02DE29 */
#define described_02DE2F_ADDRESS 0x7E2Fu    /* 02DE2F */
#define loaded_table_02DE35_ADDRESS 0x7E35u    /* 02DE35 */
#define child_object_02DE75_ADDRESS 0x7E75u    /* 02DE75 */
#define child_object_02DE7D_ADDRESS 0x7E7Du    /* 02DE7D */
#define child_object_02DE85_ADDRESS 0x7E85u    /* 02DE85 */
#define child_object_02DE8D_ADDRESS 0x7E8Du    /* 02DE8D */
#define loaded_table_02DE95_ADDRESS 0x7E95u    /* 02DE95 */
#define object_setup_02DEAD_ADDRESS 0x7EADu    /* 02DEAD */
#define loaded_table_02DEB3_ADDRESS 0x7EB3u    /* 02DEB3 */
#define loaded_table_02DEBD_ADDRESS 0x7EBDu    /* 02DEBD */
#define child_object_02DEC1_ADDRESS 0x7EC1u    /* 02DEC1 */
#define child_object_02DEC9_ADDRESS 0x7EC9u    /* 02DEC9 */
#define loaded_table_02DED1_ADDRESS 0x7ED1u    /* 02DED1 */
#define child_object_02DED5_ADDRESS 0x7ED5u    /* 02DED5 */
#define described_02DEDD_ADDRESS 0x7EDDu    /* 02DEDD */
#define loaded_table_02DEE1_ADDRESS 0x7EE1u    /* 02DEE1 */
#define loaded_table_02DEF1_ADDRESS 0x7EF1u    /* 02DEF1 */
#define loaded_table_02DEF9_ADDRESS 0x7EF9u    /* 02DEF9 */
#define object_setup_02DF0B_ADDRESS 0x7F0Bu    /* 02DF0B */
#define described_02DF11_ADDRESS 0x7F11u    /* 02DF11 */
#define loaded_table_02DF15_ADDRESS 0x7F15u    /* 02DF15 */
#define object_setup_02DF25_ADDRESS 0x7F25u    /* 02DF25 */
#define described_02DF2B_ADDRESS 0x7F2Bu    /* 02DF2B */
#define loaded_table_02DF2F_ADDRESS 0x7F2Fu    /* 02DF2F */
#define object_setup_02DF41_ADDRESS 0x7F41u    /* 02DF41 */
#define loaded_table_02DF47_ADDRESS 0x7F47u    /* 02DF47 */
#define loaded_table_02DF67_ADDRESS 0x7F67u    /* 02DF67 */
#define hit_box_02DF6D_ADDRESS 0x7F6Du    /* 02DF6D */
#define hit_box_02DF75_ADDRESS 0x7F75u    /* 02DF75 */
#define object_setup_02DF7D_ADDRESS 0x7F7Du    /* 02DF7D */
#define hit_box_02DF83_ADDRESS 0x7F83u    /* 02DF83 */
#define hit_box_02DF8B_ADDRESS 0x7F8Bu    /* 02DF8B */
#define hit_box_02DF93_ADDRESS 0x7F93u    /* 02DF93 */
#define hit_box_02DF9B_ADDRESS 0x7F9Bu    /* 02DF9B */
#define indexed_table_02DFA3_ADDRESS 0x7FA3u    /* 02DFA3 */
#define object_setup_02DFA5_ADDRESS 0x7FA5u    /* 02DFA5 */
#define loaded_table_02DFAB_ADDRESS 0x7FABu    /* 02DFAB */
#define object_setup_02DFBB_ADDRESS 0x7FBBu    /* 02DFBB */
#define loaded_table_02DFC1_ADDRESS 0x7FC1u    /* 02DFC1 */
#define described_02DFCD_ADDRESS 0x7FCDu    /* 02DFCD */
#define child_object_02DFD1_ADDRESS 0x7FD1u    /* 02DFD1 */
#define object_setup_02DFD9_ADDRESS 0x7FD9u    /* 02DFD9 */
#define described_02DFDF_ADDRESS 0x7FDFu    /* 02DFDF */
#define loaded_table_02DFE5_ADDRESS 0x7FE5u    /* 02DFE5 */
#define loaded_table_02DFE9_ADDRESS 0x7FE9u    /* 02DFE9 */
#define object_setup_02DFED_ADDRESS 0x7FEDu    /* 02DFED */
#define fill_02DFF3_ADDRESS 0x7FF3u    /* 02DFF3 */
#define hit_box_02E151_ADDRESS 0x6151u    /* 02E151 */
#define hit_box_02E159_ADDRESS 0x6159u    /* 02E159 */
#define hit_box_02E161_ADDRESS 0x6161u    /* 02E161 */
#define hit_box_02E169_ADDRESS 0x6169u    /* 02E169 */
#define hit_box_02E171_ADDRESS 0x6171u    /* 02E171 */
#define hit_box_02E179_ADDRESS 0x6179u    /* 02E179 */
#define hit_box_02E181_ADDRESS 0x6181u    /* 02E181 */
#define hit_box_02E189_ADDRESS 0x6189u    /* 02E189 */
#define hit_box_02E191_ADDRESS 0x6191u    /* 02E191 */
#define hit_box_02E199_ADDRESS 0x6199u    /* 02E199 */
#define hit_box_02E1A1_ADDRESS 0x61A1u    /* 02E1A1 */
#define fill_02F85F_ADDRESS 0x785Fu    /* 02F85F */
#define hit_box_02FA00_ADDRESS 0x7A00u    /* 02FA00 */
#define loaded_table_02FA08_ADDRESS 0x7A08u    /* 02FA08 */
#define object_setup_02FA0C_ADDRESS 0x7A0Cu    /* 02FA0C */
#define loaded_table_02FA12_ADDRESS 0x7A12u    /* 02FA12 */
#define loaded_table_02FA3A_ADDRESS 0x7A3Au    /* 02FA3A */
#define hit_box_02FA40_ADDRESS 0x7A40u    /* 02FA40 */
#define hit_box_02FA48_ADDRESS 0x7A48u    /* 02FA48 */
#define object_setup_02FA50_ADDRESS 0x7A50u    /* 02FA50 */
#define described_02FA56_ADDRESS 0x7A56u    /* 02FA56 */
#define loaded_table_02FA5A_ADDRESS 0x7A5Au    /* 02FA5A */
#define loaded_table_02FA5E_ADDRESS 0x7A5Eu    /* 02FA5E */
#define object_setup_02FA62_ADDRESS 0x7A62u    /* 02FA62 */
#define loaded_table_02FA68_ADDRESS 0x7A68u    /* 02FA68 */
#define object_setup_02FA76_ADDRESS 0x7A76u    /* 02FA76 */
#define object_setup_02FA7C_ADDRESS 0x7A7Cu    /* 02FA7C */
#define object_setup_02FA82_ADDRESS 0x7A82u    /* 02FA82 */
#define loaded_table_02FA88_ADDRESS 0x7A88u    /* 02FA88 */
#define object_setup_02FA96_ADDRESS 0x7A96u    /* 02FA96 */
#define record_02FAA4_ADDRESS 0x7AA4u    /* 02FAA4 */
#define record_02FAAC_ADDRESS 0x7AACu    /* 02FAAC */
#define record_02FAB4_ADDRESS 0x7AB4u    /* 02FAB4 */
#define record_02FABC_ADDRESS 0x7ABCu    /* 02FABC */
#define loaded_table_02FAC4_ADDRESS 0x7AC4u    /* 02FAC4 */
#define object_setup_02FADE_ADDRESS 0x7ADEu    /* 02FADE */
#define loaded_table_02FAE4_ADDRESS 0x7AE4u    /* 02FAE4 */
#define loaded_table_02FAEC_ADDRESS 0x7AECu    /* 02FAEC */
#define object_setup_02FAFA_ADDRESS 0x7AFAu    /* 02FAFA */
#define child_object_02FB08_ADDRESS 0x7B08u    /* 02FB08 */
#define child_object_02FB10_ADDRESS 0x7B10u    /* 02FB10 */
#define child_object_02FB18_ADDRESS 0x7B18u    /* 02FB18 */
#define child_object_02FB20_ADDRESS 0x7B20u    /* 02FB20 */
#define child_object_02FB30_ADDRESS 0x7B30u    /* 02FB30 */
#define child_object_02FB38_ADDRESS 0x7B38u    /* 02FB38 */
#define child_object_02FB40_ADDRESS 0x7B40u    /* 02FB40 */
#define child_object_02FB48_ADDRESS 0x7B48u    /* 02FB48 */
#define loaded_table_02FB50_ADDRESS 0x7B50u    /* 02FB50 */
#define object_setup_02FB5E_ADDRESS 0x7B5Eu    /* 02FB5E */
#define child_object_02FB64_ADDRESS 0x7B64u    /* 02FB64 */
#define loaded_table_02FB6C_ADDRESS 0x7B6Cu    /* 02FB6C */
#define object_setup_02FB80_ADDRESS 0x7B80u    /* 02FB80 */
#define object_setup_02FB86_ADDRESS 0x7B86u    /* 02FB86 */
#define object_setup_02FB8C_ADDRESS 0x7B8Cu    /* 02FB8C */
#define child_object_02FB98_ADDRESS 0x7B98u    /* 02FB98 */
#define child_object_02FBA0_ADDRESS 0x7BA0u    /* 02FBA0 */
#define child_object_02FBA8_ADDRESS 0x7BA8u    /* 02FBA8 */
#define loaded_table_02FBB0_ADDRESS 0x7BB0u    /* 02FBB0 */
#define hit_box_02FBBB_ADDRESS 0x7BBBu    /* 02FBBB */
#define hit_box_02FBC3_ADDRESS 0x7BC3u    /* 02FBC3 */
#define record_02FBD3_ADDRESS 0x7BD3u    /* 02FBD3 */
#define record_02FBD6_ADDRESS 0x7BD6u    /* 02FBD6 */
#define object_setup_02FBD9_ADDRESS 0x7BD9u    /* 02FBD9 */
#define hit_box_02FBDF_ADDRESS 0x7BDFu    /* 02FBDF */
#define hit_box_02FBE7_ADDRESS 0x7BE7u    /* 02FBE7 */
#define enemy_behaviour_02FBEF_ADDRESS 0x7BEFu    /* 02FBEF */
#define loaded_table_02FC47_ADDRESS 0x7C47u    /* 02FC47 */
#define object_setup_02FC53_ADDRESS 0x7C53u    /* 02FC53 */
#define loaded_table_02FC59_ADDRESS 0x7C59u    /* 02FC59 */
#define loaded_table_02FC65_ADDRESS 0x7C65u    /* 02FC65 */
#define loaded_table_02FC6D_ADDRESS 0x7C6Du    /* 02FC6D */
#define child_object_02FC73_ADDRESS 0x7C73u    /* 02FC73 */
#define loaded_table_02FC79_ADDRESS 0x7C79u    /* 02FC79 */
#define object_setup_02FC81_ADDRESS 0x7C81u    /* 02FC81 */
#define hit_box_02FC87_ADDRESS 0x7C87u    /* 02FC87 */
#define loaded_table_02FC8F_ADDRESS 0x7C8Fu    /* 02FC8F */
#define object_setup_02FC99_ADDRESS 0x7C99u    /* 02FC99 */
#define hit_box_02FCA6_ADDRESS 0x7CA6u    /* 02FCA6 */
#define hit_box_02FCAE_ADDRESS 0x7CAEu    /* 02FCAE */
#define hit_box_02FCB6_ADDRESS 0x7CB6u    /* 02FCB6 */
#define hit_box_02FCBE_ADDRESS 0x7CBEu    /* 02FCBE */
#define hit_box_02FCC6_ADDRESS 0x7CC6u    /* 02FCC6 */
#define hit_box_02FCCE_ADDRESS 0x7CCEu    /* 02FCCE */
#define hit_box_02FCD6_ADDRESS 0x7CD6u    /* 02FCD6 */
#define hit_box_02FCDE_ADDRESS 0x7CDEu    /* 02FCDE */
#define enemy_behaviour_02FCE6_ADDRESS 0x7CE6u    /* 02FCE6 */
#define enemy_behaviour_02FD3E_ADDRESS 0x7D3Eu    /* 02FD3E */
#define loaded_table_02FD96_ADDRESS 0x7D96u    /* 02FD96 */
#define child_object_02FDA7_ADDRESS 0x7DA7u    /* 02FDA7 */
#define child_object_02FDAD_ADDRESS 0x7DADu    /* 02FDAD */
#define loaded_table_02FDB5_ADDRESS 0x7DB5u    /* 02FDB5 */
#define object_setup_02FDBF_ADDRESS 0x7DBFu    /* 02FDBF */
#define child_object_02FDC5_ADDRESS 0x7DC5u    /* 02FDC5 */
#define loaded_table_02FDCD_ADDRESS 0x7DCDu    /* 02FDCD */
#define object_setup_02FDD3_ADDRESS 0x7DD3u    /* 02FDD3 */
#define described_02FDD9_ADDRESS 0x7DD9u    /* 02FDD9 */
#define loaded_table_02FDDD_ADDRESS 0x7DDDu    /* 02FDDD */
#define child_object_02FDF3_ADDRESS 0x7DF3u    /* 02FDF3 */
#define loaded_table_02FDF9_ADDRESS 0x7DF9u    /* 02FDF9 */
#define constant_table_02FDFF_ADDRESS 0x7DFFu    /* 02FDFF */
#define object_setup_02FE01_ADDRESS 0x7E01u    /* 02FE01 */
#define loaded_table_02FE07_ADDRESS 0x7E07u    /* 02FE07 */
#define loaded_table_02FE0F_ADDRESS 0x7E0Fu    /* 02FE0F */
#define loaded_table_02FE1B_ADDRESS 0x7E1Bu    /* 02FE1B */
#define object_setup_02FE27_ADDRESS 0x7E27u    /* 02FE27 */
#define loaded_table_02FE2D_ADDRESS 0x7E2Du    /* 02FE2D */
#define loaded_table_02FE37_ADDRESS 0x7E37u    /* 02FE37 */
#define loaded_table_02FE3B_ADDRESS 0x7E3Bu    /* 02FE3B */
#define loaded_table_02FE47_ADDRESS 0x7E47u    /* 02FE47 */
#define loaded_table_02FE4F_ADDRESS 0x7E4Fu    /* 02FE4F */
#define object_setup_02FE53_ADDRESS 0x7E53u    /* 02FE53 */
#define loaded_table_02FE59_ADDRESS 0x7E59u    /* 02FE59 */
#define object_setup_02FE65_ADDRESS 0x7E65u    /* 02FE65 */
#define loaded_table_02FE6B_ADDRESS 0x7E6Bu    /* 02FE6B */
#define loaded_table_02FE73_ADDRESS 0x7E73u    /* 02FE73 */
#define loaded_table_02FE77_ADDRESS 0x7E77u    /* 02FE77 */
#define loaded_table_02FE7B_ADDRESS 0x7E7Bu    /* 02FE7B */
#define loaded_table_02FE83_ADDRESS 0x7E83u    /* 02FE83 */
#define loaded_table_02FE8B_ADDRESS 0x7E8Bu    /* 02FE8B */
#define hit_box_02FECF_ADDRESS 0x7ECFu    /* 02FECF */
#define hit_box_02FED7_ADDRESS 0x7ED7u    /* 02FED7 */
#define hit_box_02FEDF_ADDRESS 0x7EDFu    /* 02FEDF */
#define hit_box_02FEE7_ADDRESS 0x7EE7u    /* 02FEE7 */
#define hit_box_02FEEF_ADDRESS 0x7EEFu    /* 02FEEF */
#define hit_box_02FEF7_ADDRESS 0x7EF7u    /* 02FEF7 */
#define hit_box_02FEFF_ADDRESS 0x7EFFu    /* 02FEFF */
#define hit_box_02FF0F_ADDRESS 0x7F0Fu    /* 02FF0F */
#define loaded_table_02FF17_ADDRESS 0x7F17u    /* 02FF17 */
#define object_setup_02FF23_ADDRESS 0x7F23u    /* 02FF23 */
#define loaded_table_02FF29_ADDRESS 0x7F29u    /* 02FF29 */
#define object_setup_02FF35_ADDRESS 0x7F35u    /* 02FF35 */
#define loaded_table_02FF3D_ADDRESS 0x7F3Du    /* 02FF3D */
#define object_setup_02FF49_ADDRESS 0x7F49u    /* 02FF49 */
#define loaded_table_02FF4F_ADDRESS 0x7F4Fu    /* 02FF4F */
#define object_setup_02FF65_ADDRESS 0x7F65u    /* 02FF65 */
#define loaded_table_02FF6B_ADDRESS 0x7F6Bu    /* 02FF6B */
#define loaded_table_02FF8B_ADDRESS 0x7F8Bu    /* 02FF8B */
#define loaded_table_02FFA3_ADDRESS 0x7FA3u    /* 02FFA3 */
#define object_setup_02FFA7_ADDRESS 0x7FA7u    /* 02FFA7 */
#define loaded_table_02FFAD_ADDRESS 0x7FADu    /* 02FFAD */
#define loaded_table_02FFC9_ADDRESS 0x7FC9u    /* 02FFC9 */
#define object_setup_02FFD5_ADDRESS 0x7FD5u    /* 02FFD5 */
#define fill_02FFDB_ADDRESS 0x7FDBu    /* 02FFDB */
#define child_object_030FAE_ADDRESS 0x6FAEu    /* 030FAE */
#define fill_0316C3_ADDRESS 0x76C3u    /* 0316C3 */
#define hit_box_031880_ADDRESS 0x7880u    /* 031880 */
#define hit_box_031888_ADDRESS 0x7888u    /* 031888 */
#define hit_box_031890_ADDRESS 0x7890u    /* 031890 */
#define hit_box_031898_ADDRESS 0x7898u    /* 031898 */
#define hit_box_0318A0_ADDRESS 0x78A0u    /* 0318A0 */
#define hit_box_0318A8_ADDRESS 0x78A8u    /* 0318A8 */
#define hit_box_0318B0_ADDRESS 0x78B0u    /* 0318B0 */
#define hit_box_0318B8_ADDRESS 0x78B8u    /* 0318B8 */
#define enemy_behaviour_0318C0_ADDRESS 0x78C0u    /* 0318C0 */
#define enemy_behaviour_031918_ADDRESS 0x7918u    /* 031918 */
#define described_031970_ADDRESS 0x7970u    /* 031970 */
#define loaded_table_031974_ADDRESS 0x7974u    /* 031974 */
#define loaded_table_03197E_ADDRESS 0x797Eu    /* 03197E */
#define object_setup_031982_ADDRESS 0x7982u    /* 031982 */
#define loaded_table_031988_ADDRESS 0x7988u    /* 031988 */
#define loaded_table_0319C8_ADDRESS 0x79C8u    /* 0319C8 */
#define object_setup_0319D4_ADDRESS 0x79D4u    /* 0319D4 */
#define loaded_table_0319EE_ADDRESS 0x79EEu    /* 0319EE */
#define loaded_table_0319F8_ADDRESS 0x79F8u    /* 0319F8 */
#define loaded_table_031A00_ADDRESS 0x7A00u    /* 031A00 */
#define loaded_table_031A0C_ADDRESS 0x7A0Cu    /* 031A0C */
#define loaded_table_031A1A_ADDRESS 0x7A1Au    /* 031A1A */
#define loaded_table_031A26_ADDRESS 0x7A26u    /* 031A26 */
#define object_setup_031A2A_ADDRESS 0x7A2Au    /* 031A2A */
#define loaded_table_031A30_ADDRESS 0x7A30u    /* 031A30 */
#define loaded_table_031A38_ADDRESS 0x7A38u    /* 031A38 */
#define loaded_table_031A56_ADDRESS 0x7A56u    /* 031A56 */
#define object_setup_031A72_ADDRESS 0x7A72u    /* 031A72 */
#define hit_box_031A78_ADDRESS 0x7A78u    /* 031A78 */
#define hit_box_031A80_ADDRESS 0x7A80u    /* 031A80 */
#define enemy_behaviour_031A88_ADDRESS 0x7A88u    /* 031A88 */
#define loaded_table_031AE0_ADDRESS 0x7AE0u    /* 031AE0 */
#define object_setup_031AEC_ADDRESS 0x7AECu    /* 031AEC */
#define loaded_table_031AF2_ADDRESS 0x7AF2u    /* 031AF2 */
#define loaded_table_031B02_ADDRESS 0x7B02u    /* 031B02 */
#define hit_box_031B0E_ADDRESS 0x7B0Eu    /* 031B0E */
#define hit_box_031B16_ADDRESS 0x7B16u    /* 031B16 */
#define hit_box_031B1E_ADDRESS 0x7B1Eu    /* 031B1E */
#define hit_box_031B26_ADDRESS 0x7B26u    /* 031B26 */
#define hit_box_031B2E_ADDRESS 0x7B2Eu    /* 031B2E */
#define enemy_behaviour_031B36_ADDRESS 0x7B36u    /* 031B36 */
#define enemy_behaviour_031B8E_ADDRESS 0x7B8Eu    /* 031B8E */
#define loaded_table_031BE6_ADDRESS 0x7BE6u    /* 031BE6 */
#define object_setup_031BF2_ADDRESS 0x7BF2u    /* 031BF2 */
#define loaded_table_031BF8_ADDRESS 0x7BF8u    /* 031BF8 */
#define loaded_table_031BFE_ADDRESS 0x7BFEu    /* 031BFE */
#define loaded_table_031C11_ADDRESS 0x7C11u    /* 031C11 */
#define object_setup_031C1D_ADDRESS 0x7C1Du    /* 031C1D */
#define loaded_table_031C23_ADDRESS 0x7C23u    /* 031C23 */
#define loaded_table_031C3B_ADDRESS 0x7C3Bu    /* 031C3B */
#define loaded_table_031C4F_ADDRESS 0x7C4Fu    /* 031C4F */
#define loaded_table_031C57_ADDRESS 0x7C57u    /* 031C57 */
#define loaded_table_031C6B_ADDRESS 0x7C6Bu    /* 031C6B */
#define hit_box_031C6F_ADDRESS 0x7C6Fu    /* 031C6F */
#define hit_box_031C77_ADDRESS 0x7C77u    /* 031C77 */
#define enemy_behaviour_031C7F_ADDRESS 0x7C7Fu    /* 031C7F */
#define described_031CD7_ADDRESS 0x7CD7u    /* 031CD7 */
#define loaded_table_031CD9_ADDRESS 0x7CD9u    /* 031CD9 */
#define loaded_table_031CE5_ADDRESS 0x7CE5u    /* 031CE5 */
#define child_object_031CE9_ADDRESS 0x7CE9u    /* 031CE9 */
#define object_setup_031CF1_ADDRESS 0x7CF1u    /* 031CF1 */
#define loaded_table_031CF7_ADDRESS 0x7CF7u    /* 031CF7 */
#define loaded_table_031D37_ADDRESS 0x7D37u    /* 031D37 */
#define loaded_table_031D71_ADDRESS 0x7D71u    /* 031D71 */
#define hit_box_031D77_ADDRESS 0x7D77u    /* 031D77 */
#define hit_box_031D7F_ADDRESS 0x7D7Fu    /* 031D7F */
#define loaded_table_031D87_ADDRESS 0x7D87u    /* 031D87 */
#define object_setup_031D8B_ADDRESS 0x7D8Bu    /* 031D8B */
#define described_031D91_ADDRESS 0x7D91u    /* 031D91 */
#define loaded_table_031D95_ADDRESS 0x7D95u    /* 031D95 */
#define object_setup_031DC2_ADDRESS 0x7DC2u    /* 031DC2 */
#define loaded_table_031DC8_ADDRESS 0x7DC8u    /* 031DC8 */
#define loaded_table_031DCE_ADDRESS 0x7DCEu    /* 031DCE */
#define loaded_table_031DD2_ADDRESS 0x7DD2u    /* 031DD2 */
#define indexed_table_031DFC_ADDRESS 0x7DFCu    /* 031DFC */
#define loaded_table_031E20_ADDRESS 0x7E20u    /* 031E20 */
#define loaded_table_031E60_ADDRESS 0x7E60u    /* 031E60 */
#define hit_box_031EA0_ADDRESS 0x7EA0u    /* 031EA0 */
#define hit_box_031EA8_ADDRESS 0x7EA8u    /* 031EA8 */
#define hit_box_031EB0_ADDRESS 0x7EB0u    /* 031EB0 */
#define hit_box_031EB8_ADDRESS 0x7EB8u    /* 031EB8 */
#define hit_box_031EC0_ADDRESS 0x7EC0u    /* 031EC0 */
#define hit_box_031EC8_ADDRESS 0x7EC8u    /* 031EC8 */
#define hit_box_031ED0_ADDRESS 0x7ED0u    /* 031ED0 */
#define fill_031EE0_ADDRESS 0x7EE0u    /* 031EE0 */
#define described_031EE8_ADDRESS 0x7EE8u    /* 031EE8 */
#define loaded_table_031EEC_ADDRESS 0x7EECu    /* 031EEC */
#define loaded_table_031EF0_ADDRESS 0x7EF0u    /* 031EF0 */
#define object_setup_031EF4_ADDRESS 0x7EF4u    /* 031EF4 */
#define described_031EFA_ADDRESS 0x7EFAu    /* 031EFA */
#define loaded_table_031EFC_ADDRESS 0x7EFCu    /* 031EFC */
#define loaded_table_031F08_ADDRESS 0x7F08u    /* 031F08 */
#define loaded_table_031F0C_ADDRESS 0x7F0Cu    /* 031F0C */
#define object_setup_031F10_ADDRESS 0x7F10u    /* 031F10 */
#define child_object_031F16_ADDRESS 0x7F16u    /* 031F16 */
#define loaded_table_031F1C_ADDRESS 0x7F1Cu    /* 031F1C */
#define object_setup_031F2A_ADDRESS 0x7F2Au    /* 031F2A */
#define loaded_table_031F30_ADDRESS 0x7F30u    /* 031F30 */
#define object_setup_031F44_ADDRESS 0x7F44u    /* 031F44 */
#define loaded_table_031F4A_ADDRESS 0x7F4Au    /* 031F4A */
#define loaded_table_031F52_ADDRESS 0x7F52u    /* 031F52 */
#define object_setup_031F58_ADDRESS 0x7F58u    /* 031F58 */
#define described_031F5E_ADDRESS 0x7F5Eu    /* 031F5E */
#define loaded_table_031F64_ADDRESS 0x7F64u    /* 031F64 */
#define loaded_table_031F68_ADDRESS 0x7F68u    /* 031F68 */
#define loaded_table_031F6E_ADDRESS 0x7F6Eu    /* 031F6E */
#define object_setup_031F74_ADDRESS 0x7F74u    /* 031F74 */
#define loaded_table_031F82_ADDRESS 0x7F82u    /* 031F82 */
#define loaded_table_031F8E_ADDRESS 0x7F8Eu    /* 031F8E */
#define object_setup_031F92_ADDRESS 0x7F92u    /* 031F92 */
#define child_object_031F98_ADDRESS 0x7F98u    /* 031F98 */
#define fill_031FA0_ADDRESS 0x7FA0u    /* 031FA0 */
#define fill_0336B2_ADDRESS 0x76B2u    /* 0336B2 */
#define hit_box_0338A4_ADDRESS 0x78A4u    /* 0338A4 */
#define hit_box_0338AC_ADDRESS 0x78ACu    /* 0338AC */
#define described_0338B4_ADDRESS 0x78B4u    /* 0338B4 */
#define loaded_table_0338B8_ADDRESS 0x78B8u    /* 0338B8 */
#define loaded_table_0338C6_ADDRESS 0x78C6u    /* 0338C6 */
#define object_setup_0338CE_ADDRESS 0x78CEu    /* 0338CE */
#define loaded_table_0338D4_ADDRESS 0x78D4u    /* 0338D4 */
#define hit_box_0338D8_ADDRESS 0x78D8u    /* 0338D8 */
#define hit_box_0338E0_ADDRESS 0x78E0u    /* 0338E0 */
#define hit_box_0338E8_ADDRESS 0x78E8u    /* 0338E8 */
#define hit_box_0338F0_ADDRESS 0x78F0u    /* 0338F0 */
#define hit_box_0338F8_ADDRESS 0x78F8u    /* 0338F8 */
#define enemy_behaviour_033900_ADDRESS 0x7900u    /* 033900 */
#define enemy_behaviour_033958_ADDRESS 0x7958u    /* 033958 */
#define enemy_behaviour_0339B0_ADDRESS 0x79B0u    /* 0339B0 */
#define loaded_table_033A08_ADDRESS 0x7A08u    /* 033A08 */
#define loaded_table_033A14_ADDRESS 0x7A14u    /* 033A14 */
#define loaded_table_033A20_ADDRESS 0x7A20u    /* 033A20 */
#define loaded_table_033A2E_ADDRESS 0x7A2Eu    /* 033A2E */
#define object_setup_033A32_ADDRESS 0x7A32u    /* 033A32 */
#define loaded_table_033A38_ADDRESS 0x7A38u    /* 033A38 */
#define child_object_033A7D_ADDRESS 0x7A7Du    /* 033A7D */
#define loaded_table_033A85_ADDRESS 0x7A85u    /* 033A85 */
#define loaded_table_033A8D_ADDRESS 0x7A8Du    /* 033A8D */
#define child_object_033A93_ADDRESS 0x7A93u    /* 033A93 */
#define loaded_table_033A99_ADDRESS 0x7A99u    /* 033A99 */
#define object_setup_033A9D_ADDRESS 0x7A9Du    /* 033A9D */
#define loaded_table_033AA3_ADDRESS 0x7AA3u    /* 033AA3 */
#define loaded_table_033AAB_ADDRESS 0x7AABu    /* 033AAB */
#define loaded_table_033ABA_ADDRESS 0x7ABAu    /* 033ABA */
#define loaded_table_033AC4_ADDRESS 0x7AC4u    /* 033AC4 */
#define loaded_table_033ACC_ADDRESS 0x7ACCu    /* 033ACC */
#define hit_box_033AD8_ADDRESS 0x7AD8u    /* 033AD8 */
#define hit_box_033AE0_ADDRESS 0x7AE0u    /* 033AE0 */
#define hit_box_033AE8_ADDRESS 0x7AE8u    /* 033AE8 */
#define object_setup_033B00_ADDRESS 0x7B00u    /* 033B00 */
#define loaded_table_033B06_ADDRESS 0x7B06u    /* 033B06 */
#define loaded_table_033B10_ADDRESS 0x7B10u    /* 033B10 */
#define hit_box_033B30_ADDRESS 0x7B30u    /* 033B30 */
#define hit_box_033B38_ADDRESS 0x7B38u    /* 033B38 */
#define hit_box_033B40_ADDRESS 0x7B40u    /* 033B40 */
#define hit_box_033B48_ADDRESS 0x7B48u    /* 033B48 */
#define hit_box_033B50_ADDRESS 0x7B50u    /* 033B50 */
#define hit_box_033B60_ADDRESS 0x7B60u    /* 033B60 */
#define hit_box_033B68_ADDRESS 0x7B68u    /* 033B68 */
#define enemy_behaviour_033B70_ADDRESS 0x7B70u    /* 033B70 */
#define loaded_table_033BC8_ADDRESS 0x7BC8u    /* 033BC8 */
#define object_setup_033BD0_ADDRESS 0x7BD0u    /* 033BD0 */
#define loaded_table_033BD6_ADDRESS 0x7BD6u    /* 033BD6 */
#define object_setup_033BE2_ADDRESS 0x7BE2u    /* 033BE2 */
#define loaded_table_033BE8_ADDRESS 0x7BE8u    /* 033BE8 */
#define loaded_table_033C04_ADDRESS 0x7C04u    /* 033C04 */
#define loaded_table_033C10_ADDRESS 0x7C10u    /* 033C10 */
#define loaded_table_033C36_ADDRESS 0x7C36u    /* 033C36 */
#define child_object_033C50_ADDRESS 0x7C50u    /* 033C50 */
#define child_object_033C58_ADDRESS 0x7C58u    /* 033C58 */
#define child_object_033C60_ADDRESS 0x7C60u    /* 033C60 */
#define child_object_033C68_ADDRESS 0x7C68u    /* 033C68 */
#define loaded_table_033C70_ADDRESS 0x7C70u    /* 033C70 */
#define child_object_033C8A_ADDRESS 0x7C8Au    /* 033C8A */
#define child_object_033C92_ADDRESS 0x7C92u    /* 033C92 */
#define child_object_033C9A_ADDRESS 0x7C9Au    /* 033C9A */
#define child_object_033CA2_ADDRESS 0x7CA2u    /* 033CA2 */
#define loaded_table_033CAA_ADDRESS 0x7CAAu    /* 033CAA */
#define loaded_table_033CC8_ADDRESS 0x7CC8u    /* 033CC8 */
#define loaded_table_033D08_ADDRESS 0x7D08u    /* 033D08 */
#define child_object_033D10_ADDRESS 0x7D10u    /* 033D10 */
#define loaded_table_033D16_ADDRESS 0x7D16u    /* 033D16 */
#define object_setup_033D1C_ADDRESS 0x7D1Cu    /* 033D1C */
#define loaded_table_033D52_ADDRESS 0x7D52u    /* 033D52 */
#define object_setup_033D62_ADDRESS 0x7D62u    /* 033D62 */
#define child_object_033D68_ADDRESS 0x7D68u    /* 033D68 */
#define child_object_033D70_ADDRESS 0x7D70u    /* 033D70 */
#define child_object_033D78_ADDRESS 0x7D78u    /* 033D78 */
#define child_object_033D80_ADDRESS 0x7D80u    /* 033D80 */
#define loaded_table_033D88_ADDRESS 0x7D88u    /* 033D88 */
#define object_setup_033D90_ADDRESS 0x7D90u    /* 033D90 */
#define loaded_table_033D96_ADDRESS 0x7D96u    /* 033D96 */
#define hit_box_033D9E_ADDRESS 0x7D9Eu    /* 033D9E */
#define hit_box_033DA6_ADDRESS 0x7DA6u    /* 033DA6 */
#define hit_box_033DAE_ADDRESS 0x7DAEu    /* 033DAE */
#define enemy_behaviour_033DB6_ADDRESS 0x7DB6u    /* 033DB6 */
#define loaded_table_033E0E_ADDRESS 0x7E0Eu    /* 033E0E */
#define object_setup_033E1A_ADDRESS 0x7E1Au    /* 033E1A */
#define loaded_table_033E20_ADDRESS 0x7E20u    /* 033E20 */
#define loaded_table_033E4A_ADDRESS 0x7E4Au    /* 033E4A */
#define loaded_table_033E50_ADDRESS 0x7E50u    /* 033E50 */
#define child_object_033E56_ADDRESS 0x7E56u    /* 033E56 */
#define loaded_table_033E5E_ADDRESS 0x7E5Eu    /* 033E5E */
#define object_setup_033E62_ADDRESS 0x7E62u    /* 033E62 */
#define hit_box_033E68_ADDRESS 0x7E68u    /* 033E68 */
#define hit_box_033E70_ADDRESS 0x7E70u    /* 033E70 */
#define described_033E78_ADDRESS 0x7E78u    /* 033E78 */
#define loaded_table_033E7C_ADDRESS 0x7E7Cu    /* 033E7C */
#define object_setup_033EB7_ADDRESS 0x7EB7u    /* 033EB7 */
#define loaded_table_033EBD_ADDRESS 0x7EBDu    /* 033EBD */
#define child_object_033ECF_ADDRESS 0x7ECFu    /* 033ECF */
#define child_object_033ED7_ADDRESS 0x7ED7u    /* 033ED7 */
#define child_object_033EDF_ADDRESS 0x7EDFu    /* 033EDF */
#define child_object_033EE7_ADDRESS 0x7EE7u    /* 033EE7 */
#define child_object_033EF3_ADDRESS 0x7EF3u    /* 033EF3 */
#define child_object_033EFB_ADDRESS 0x7EFBu    /* 033EFB */
#define loaded_table_033F03_ADDRESS 0x7F03u    /* 033F03 */
#define loaded_table_033F07_ADDRESS 0x7F07u    /* 033F07 */
#define indexed_table_033F31_ADDRESS 0x7F31u    /* 033F31 */
#define loaded_table_033F55_ADDRESS 0x7F55u    /* 033F55 */
#define loaded_table_033FD5_ADDRESS 0x7FD5u    /* 033FD5 */
#define object_setup_033FDD_ADDRESS 0x7FDDu    /* 033FDD */
#define fill_033FFF_ADDRESS 0x7FFFu    /* 033FFF */
#define fill_034C82_ADDRESS 0x6C82u    /* 034C82 */
#define described_0352FC_ADDRESS 0x72FCu    /* 0352FC */
#define loaded_table_035300_ADDRESS 0x7300u    /* 035300 */
#define hit_box_035768_ADDRESS 0x7768u    /* 035768 */
#define hit_box_035770_ADDRESS 0x7770u    /* 035770 */
#define hit_box_035778_ADDRESS 0x7778u    /* 035778 */
#define hit_box_035780_ADDRESS 0x7780u    /* 035780 */
#define hit_box_035788_ADDRESS 0x7788u    /* 035788 */
#define described_035790_ADDRESS 0x7790u    /* 035790 */
#define loaded_table_035794_ADDRESS 0x7794u    /* 035794 */
#define object_setup_0357D0_ADDRESS 0x77D0u    /* 0357D0 */
#define loaded_table_0357D6_ADDRESS 0x77D6u    /* 0357D6 */
#define loaded_table_0357E6_ADDRESS 0x77E6u    /* 0357E6 */
#define loaded_table_0357EA_ADDRESS 0x77EAu    /* 0357EA */
#define loaded_table_035806_ADDRESS 0x7806u    /* 035806 */
#define loaded_table_03580C_ADDRESS 0x780Cu    /* 03580C */
#define child_object_035812_ADDRESS 0x7812u    /* 035812 */
#define described_03581A_ADDRESS 0x781Au    /* 03581A */
#define loaded_table_03581E_ADDRESS 0x781Eu    /* 03581E */
#define loaded_table_03582E_ADDRESS 0x782Eu    /* 03582E */
#define loaded_table_035842_ADDRESS 0x7842u    /* 035842 */
#define loaded_table_035870_ADDRESS 0x7870u    /* 035870 */
#define loaded_table_035876_ADDRESS 0x7876u    /* 035876 */
#define loaded_table_035880_ADDRESS 0x7880u    /* 035880 */
#define loaded_table_035886_ADDRESS 0x7886u    /* 035886 */
#define child_object_03588C_ADDRESS 0x788Cu    /* 03588C */
#define described_035892_ADDRESS 0x7892u    /* 035892 */
#define loaded_table_035896_ADDRESS 0x7896u    /* 035896 */
#define loaded_table_0358A4_ADDRESS 0x78A4u    /* 0358A4 */
#define loaded_table_0358AC_ADDRESS 0x78ACu    /* 0358AC */
#define child_object_0358BC_ADDRESS 0x78BCu    /* 0358BC */
#define loaded_table_0358C4_ADDRESS 0x78C4u    /* 0358C4 */
#define loaded_table_0358D8_ADDRESS 0x78D8u    /* 0358D8 */
#define loaded_table_0358DC_ADDRESS 0x78DCu    /* 0358DC */
#define child_object_0358F4_ADDRESS 0x78F4u    /* 0358F4 */
#define child_object_0358FC_ADDRESS 0x78FCu    /* 0358FC */
#define child_object_035904_ADDRESS 0x7904u    /* 035904 */
#define child_object_03590C_ADDRESS 0x790Cu    /* 03590C */
#define loaded_table_035914_ADDRESS 0x7914u    /* 035914 */
#define loaded_table_035926_ADDRESS 0x7926u    /* 035926 */
#define object_setup_03592E_ADDRESS 0x792Eu    /* 03592E */
#define child_object_03593C_ADDRESS 0x793Cu    /* 03593C */
#define loaded_table_035944_ADDRESS 0x7944u    /* 035944 */
#define object_setup_035948_ADDRESS 0x7948u    /* 035948 */
#define loaded_table_03594E_ADDRESS 0x794Eu    /* 03594E */
#define object_setup_035952_ADDRESS 0x7952u    /* 035952 */
#define hit_box_035958_ADDRESS 0x7958u    /* 035958 */
#define loaded_table_035960_ADDRESS 0x7960u    /* 035960 */
#define child_object_035966_ADDRESS 0x7966u    /* 035966 */
#define object_setup_03596E_ADDRESS 0x796Eu    /* 03596E */
#define described_035974_ADDRESS 0x7974u    /* 035974 */
#define loaded_table_035978_ADDRESS 0x7978u    /* 035978 */
#define loaded_table_035982_ADDRESS 0x7982u    /* 035982 */
#define object_setup_035988_ADDRESS 0x7988u    /* 035988 */
#define loaded_table_03598E_ADDRESS 0x798Eu    /* 03598E */
#define object_setup_0359D6_ADDRESS 0x79D6u    /* 0359D6 */
#define object_1a_path_ADDRESS 0x79F3u    /* 0359F3 */
#define object_path_035A5A_ADDRESS 0x7A5Au    /* 035A5A */
#define object_path_035A81_ADDRESS 0x7A81u    /* 035A81 */
#define object_path_035B08_ADDRESS 0x7B08u    /* 035B08 */
#define object_path_035C0F_ADDRESS 0x7C0Fu    /* 035C0F */
#define object_path_035C66_ADDRESS 0x7C66u    /* 035C66 */
#define object_path_035C9D_ADDRESS 0x7C9Du    /* 035C9D */
#define object_path_035CE4_ADDRESS 0x7CE4u    /* 035CE4 */
#define object_path_035D2B_ADDRESS 0x7D2Bu    /* 035D2B */
#define object_1a_dive_path_ADDRESS 0x7D72u    /* 035D72 */
#define object_path_035DD9_ADDRESS 0x7DD9u    /* 035DD9 */
#define object_path_035E80_ADDRESS 0x7E80u    /* 035E80 */
#define object_path_035E97_ADDRESS 0x7E97u    /* 035E97 */
#define object_path_035EAE_ADDRESS 0x7EAEu    /* 035EAE */
#define object_path_035F35_ADDRESS 0x7F35u    /* 035F35 */
#define object_path_035F5C_ADDRESS 0x7F5Cu    /* 035F5C */
#define fill_0360B4_ADDRESS 0x60B4u    /* 0360B4 */
#define fill_0363C6_ADDRESS 0x63C6u    /* 0363C6 */
#define hit_box_036400_ADDRESS 0x6400u    /* 036400 */
#define hit_box_036408_ADDRESS 0x6408u    /* 036408 */
#define hit_box_036410_ADDRESS 0x6410u    /* 036410 */
#define hit_box_036418_ADDRESS 0x6418u    /* 036418 */
#define object_setup_036430_ADDRESS 0x6430u    /* 036430 */
#define loaded_table_036436_ADDRESS 0x6436u    /* 036436 */
#define object_setup_03644E_ADDRESS 0x644Eu    /* 03644E */
#define loaded_table_036474_ADDRESS 0x6474u    /* 036474 */
#define object_setup_036482_ADDRESS 0x6482u    /* 036482 */
#define loaded_table_036488_ADDRESS 0x6488u    /* 036488 */
#define indexed_table_036498_ADDRESS 0x6498u    /* 036498 */
#define indexed_table_0364A0_ADDRESS 0x64A0u    /* 0364A0 */
#define indexed_table_0364B3_ADDRESS 0x64B3u    /* 0364B3 */
#define indexed_table_0364C6_ADDRESS 0x64C6u    /* 0364C6 */
#define indexed_table_0364D9_ADDRESS 0x64D9u    /* 0364D9 */
#define loaded_table_0364EC_ADDRESS 0x64ECu    /* 0364EC */
#define object_setup_0364F8_ADDRESS 0x64F8u    /* 0364F8 */
#define loaded_table_0364FE_ADDRESS 0x64FEu    /* 0364FE */
#define indexed_table_03650A_ADDRESS 0x650Au    /* 03650A */
#define indexed_table_036512_ADDRESS 0x6512u    /* 036512 */
#define indexed_table_03651C_ADDRESS 0x651Cu    /* 03651C */
#define indexed_table_036526_ADDRESS 0x6526u    /* 036526 */
#define loaded_table_036539_ADDRESS 0x6539u    /* 036539 */
#define object_setup_036547_ADDRESS 0x6547u    /* 036547 */
#define loaded_table_03654D_ADDRESS 0x654Du    /* 03654D */
#define indexed_table_03655D_ADDRESS 0x655Du    /* 03655D */
#define indexed_table_036565_ADDRESS 0x6565u    /* 036565 */
#define indexed_table_036577_ADDRESS 0x6577u    /* 036577 */
#define indexed_table_036578_ADDRESS 0x6578u    /* 036578 */
#define spawn_list_03659D_ADDRESS 0x659Du    /* 03659D */
#define spawn_list_03685D_ADDRESS 0x685Du    /* 03685D */
#define spawn_list_036B8D_ADDRESS 0x6B8Du    /* 036B8D */
#define spawn_list_036B95_ADDRESS 0x6B95u    /* 036B95 */
#define spawn_list_036F15_ADDRESS 0x6F15u    /* 036F15 */
#define spawn_list_0370C5_ADDRESS 0x70C5u    /* 0370C5 */
#define spawn_list_0374B5_ADDRESS 0x74B5u    /* 0374B5 */
#define spawn_list_0377ED_ADDRESS 0x77EDu    /* 0377ED */
#define spawn_list_0377F5_ADDRESS 0x77F5u    /* 0377F5 */
#define spawn_list_037A1D_ADDRESS 0x7A1Du    /* 037A1D */
#define spawn_list_037E95_ADDRESS 0x7E95u    /* 037E95 */
#define spawn_list_037E9D_ADDRESS 0x7E9Du    /* 037E9D */
#define fill_037ECD_ADDRESS 0x7ECDu    /* 037ECD */
#define fill_039C5C_ADDRESS 0x7C5Cu    /* 039C5C */
#define loaded_table_039D51_ADDRESS 0x7D51u    /* 039D51 */
#define loaded_table_039DD9_ADDRESS 0x7DD9u    /* 039DD9 */
#define loaded_table_039DE1_ADDRESS 0x7DE1u    /* 039DE1 */
#define indexed_table_039E07_ADDRESS 0x7E07u    /* 039E07 */
#define indexed_table_039E09_ADDRESS 0x7E09u    /* 039E09 */
#define indexed_table_039E0B_ADDRESS 0x7E0Bu    /* 039E0B */
#define record_039E0D_ADDRESS 0x7E0Du    /* 039E0D */
#define record_039E0F_ADDRESS 0x7E0Fu    /* 039E0F */
#define indexed_table_039E11_ADDRESS 0x7E11u    /* 039E11 */
#define indexed_table_039E13_ADDRESS 0x7E13u    /* 039E13 */
#define indexed_table_039E15_ADDRESS 0x7E15u    /* 039E15 */
#define record_039E17_ADDRESS 0x7E17u    /* 039E17 */
#define record_039E19_ADDRESS 0x7E19u    /* 039E19 */
#define loaded_table_039E1B_ADDRESS 0x7E1Bu    /* 039E1B */
#define loaded_table_039E23_ADDRESS 0x7E23u    /* 039E23 */
#define loaded_table_039E3B_ADDRESS 0x7E3Bu    /* 039E3B */
#define loaded_table_039E3C_ADDRESS 0x7E3Cu    /* 039E3C */
#define loaded_table_039E45_ADDRESS 0x7E45u    /* 039E45 */
#define loaded_table_039E55_ADDRESS 0x7E55u    /* 039E55 */
#define loaded_table_039E8D_ADDRESS 0x7E8Du    /* 039E8D */
#define loaded_table_039EA9_ADDRESS 0x7EA9u    /* 039EA9 */
#define loaded_table_039F5D_ADDRESS 0x7F5Du    /* 039F5D */
#define fill_03A00C_ADDRESS 0x600Cu    /* 03A00C */
#define fill_03A02C_ADDRESS 0x602Cu    /* 03A02C */
#define fill_03A924_ADDRESS 0x6924u    /* 03A924 */
#define fill_03B9E3_ADDRESS 0x79E3u    /* 03B9E3 */
#define bank_1d_states_ADDRESS 0x7A00u    /* 03BA00 */
#define indexed_table_03BA3A_ADDRESS 0x7A3Au    /* 03BA3A */
#define child_object_03BA78_ADDRESS 0x7A78u    /* 03BA78 */
#define child_object_03BA7E_ADDRESS 0x7A7Eu    /* 03BA7E */
#define child_object_03BA84_ADDRESS 0x7A84u    /* 03BA84 */
#define child_object_03BA8C_ADDRESS 0x7A8Cu    /* 03BA8C */
#define indexed_table_03BA94_ADDRESS 0x7A94u    /* 03BA94 */
#define record_03BA96_ADDRESS 0x7A96u    /* 03BA96 */
#define indexed_table_03BA98_ADDRESS 0x7A98u    /* 03BA98 */
#define record_03BA9A_ADDRESS 0x7A9Au    /* 03BA9A */
#define loaded_table_03BA9C_ADDRESS 0x7A9Cu    /* 03BA9C */
#define fill_03BAB3_ADDRESS 0x7AB3u    /* 03BAB3 */
#define indexed_table_03BABD_ADDRESS 0x7ABDu    /* 03BABD */
#define loaded_table_03BAD6_ADDRESS 0x7AD6u    /* 03BAD6 */
#define indexed_table_03BADE_ADDRESS 0x7ADEu    /* 03BADE */
#define record_03BAE0_ADDRESS 0x7AE0u    /* 03BAE0 */
#define described_03BAE2_ADDRESS 0x7AE2u    /* 03BAE2 */
#define loaded_table_03BAEE_ADDRESS 0x7AEEu    /* 03BAEE */
#define loaded_table_03BB0A_ADDRESS 0x7B0Au    /* 03BB0A */
#define loaded_table_03BB14_ADDRESS 0x7B14u    /* 03BB14 */
#define loaded_table_03BB18_ADDRESS 0x7B18u    /* 03BB18 */
#define loaded_table_03BB1C_ADDRESS 0x7B1Cu    /* 03BB1C */
#define loaded_table_03BB2A_ADDRESS 0x7B2Au    /* 03BB2A */
#define loaded_table_03BB38_ADDRESS 0x7B38u    /* 03BB38 */
#define loaded_table_03BB3C_ADDRESS 0x7B3Cu    /* 03BB3C */
#define loaded_table_03BB4C_ADDRESS 0x7B4Cu    /* 03BB4C */
#define loaded_table_03BB52_ADDRESS 0x7B52u    /* 03BB52 */
#define loaded_table_03BB5E_ADDRESS 0x7B5Eu    /* 03BB5E */
#define loaded_table_03BB66_ADDRESS 0x7B66u    /* 03BB66 */
#define loaded_table_03BB6E_ADDRESS 0x7B6Eu    /* 03BB6E */
#define loaded_table_03BB7C_ADDRESS 0x7B7Cu    /* 03BB7C */
#define indexed_table_03BB8F_ADDRESS 0x7B8Fu    /* 03BB8F */
#define indexed_table_03BB93_ADDRESS 0x7B93u    /* 03BB93 */
#define indexed_table_03BB97_ADDRESS 0x7B97u    /* 03BB97 */
#define indexed_table_03BB9B_ADDRESS 0x7B9Bu    /* 03BB9B */
#define indexed_table_03BB9F_ADDRESS 0x7B9Fu    /* 03BB9F */
#define indexed_table_03BBF1_ADDRESS 0x7BF1u    /* 03BBF1 */
#define indexed_table_03BBF5_ADDRESS 0x7BF5u    /* 03BBF5 */
#define indexed_table_03BC87_ADDRESS 0x7C87u    /* 03BC87 */
#define indexed_table_03BC8F_ADDRESS 0x7C8Fu    /* 03BC8F */
#define indexed_table_03BC97_ADDRESS 0x7C97u    /* 03BC97 */
#define indexed_table_03BC9F_ADDRESS 0x7C9Fu    /* 03BC9F */
#define indexed_table_03BCA7_ADDRESS 0x7CA7u    /* 03BCA7 */
#define indexed_table_03BCAF_ADDRESS 0x7CAFu    /* 03BCAF */
#define indexed_table_03BCB7_ADDRESS 0x7CB7u    /* 03BCB7 */
#define indexed_table_03BCBF_ADDRESS 0x7CBFu    /* 03BCBF */
#define indexed_table_03BCC7_ADDRESS 0x7CC7u    /* 03BCC7 */
#define indexed_table_03BCCF_ADDRESS 0x7CCFu    /* 03BCCF */
#define indexed_table_03BCE1_ADDRESS 0x7CE1u    /* 03BCE1 */
#define indexed_table_03BCF1_ADDRESS 0x7CF1u    /* 03BCF1 */
#define indexed_table_03BD01_ADDRESS 0x7D01u    /* 03BD01 */
#define indexed_table_03BD11_ADDRESS 0x7D11u    /* 03BD11 */
#define loaded_table_03BD99_ADDRESS 0x7D99u    /* 03BD99 */
#define loaded_table_03BDA1_ADDRESS 0x7DA1u    /* 03BDA1 */
#define loaded_table_03BDA5_ADDRESS 0x7DA5u    /* 03BDA5 */
#define loaded_table_03BDAD_ADDRESS 0x7DADu    /* 03BDAD */
#define loaded_table_03BDCF_ADDRESS 0x7DCFu    /* 03BDCF */
#define loaded_table_03BDD7_ADDRESS 0x7DD7u    /* 03BDD7 */
#define loaded_table_03BDDB_ADDRESS 0x7DDBu    /* 03BDDB */
#define fill_03BFC7_ADDRESS 0x7FC7u    /* 03BFC7 */
#define fill_03C61A_ADDRESS 0x661Au    /* 03C61A */
#define fill_03DCE7_ADDRESS 0x7CE7u    /* 03DCE7 */
#define loaded_table_03DD70_ADDRESS 0x7D70u    /* 03DD70 */
#define child_object_03DD9A_ADDRESS 0x7D9Au    /* 03DD9A */
#define indexed_table_03DDA2_ADDRESS 0x7DA2u    /* 03DDA2 */
#define record_03DDA4_ADDRESS 0x7DA4u    /* 03DDA4 */
#define indexed_table_03DDA6_ADDRESS 0x7DA6u    /* 03DDA6 */
#define indexed_table_03DDB9_ADDRESS 0x7DB9u    /* 03DDB9 */
#define indexed_table_03DDBD_ADDRESS 0x7DBDu    /* 03DDBD */
#define child_object_03DDC2_ADDRESS 0x7DC2u    /* 03DDC2 */
#define child_object_03DDC8_ADDRESS 0x7DC8u    /* 03DDC8 */
#define indexed_table_03DDCE_ADDRESS 0x7DCEu    /* 03DDCE */
#define record_03DDD0_ADDRESS 0x7DD0u    /* 03DDD0 */
#define indexed_table_03DDD2_ADDRESS 0x7DD2u    /* 03DDD2 */
#define record_03DDD4_ADDRESS 0x7DD4u    /* 03DDD4 */
#define loaded_table_03DDD6_ADDRESS 0x7DD6u    /* 03DDD6 */
#define child_object_03DDE6_ADDRESS 0x7DE6u    /* 03DDE6 */
#define loaded_table_03DDEC_ADDRESS 0x7DECu    /* 03DDEC */
#define child_object_03DE14_ADDRESS 0x7E14u    /* 03DE14 */
#define child_object_03DE1C_ADDRESS 0x7E1Cu    /* 03DE1C */
#define child_object_03DE24_ADDRESS 0x7E24u    /* 03DE24 */
#define indexed_table_03DE50_ADDRESS 0x7E50u    /* 03DE50 */
#define record_03DE52_ADDRESS 0x7E52u    /* 03DE52 */
#define child_object_03DE54_ADDRESS 0x7E54u    /* 03DE54 */
#define child_object_03DE5C_ADDRESS 0x7E5Cu    /* 03DE5C */
#define indexed_table_03DE64_ADDRESS 0x7E64u    /* 03DE64 */
#define indexed_table_03DE67_ADDRESS 0x7E67u    /* 03DE67 */
#define indexed_table_03DE6B_ADDRESS 0x7E6Bu    /* 03DE6B */
#define indexed_table_03DE70_ADDRESS 0x7E70u    /* 03DE70 */
#define indexed_table_03DE90_ADDRESS 0x7E90u    /* 03DE90 */
#define record_03DE92_ADDRESS 0x7E92u    /* 03DE92 */
#define child_object_03DE94_ADDRESS 0x7E94u    /* 03DE94 */
#define loaded_table_03DE9C_ADDRESS 0x7E9Cu    /* 03DE9C */
#define loaded_table_03DECC_ADDRESS 0x7ECCu    /* 03DECC */
#define loaded_table_03DEDC_ADDRESS 0x7EDCu    /* 03DEDC */
#define child_object_03DF08_ADDRESS 0x7F08u    /* 03DF08 */
#define child_object_03DF10_ADDRESS 0x7F10u    /* 03DF10 */
#define indexed_table_03DF16_ADDRESS 0x7F16u    /* 03DF16 */
#define record_03DF18_ADDRESS 0x7F18u    /* 03DF18 */
#define indexed_table_03DF1A_ADDRESS 0x7F1Au    /* 03DF1A */
#define record_03DF1C_ADDRESS 0x7F1Cu    /* 03DF1C */
#define indexed_table_03DF1E_ADDRESS 0x7F1Eu    /* 03DF1E */
#define record_03DF20_ADDRESS 0x7F20u    /* 03DF20 */
#define indexed_table_03DF22_ADDRESS 0x7F22u    /* 03DF22 */
#define record_03DF24_ADDRESS 0x7F24u    /* 03DF24 */
#define indexed_table_03DF26_ADDRESS 0x7F26u    /* 03DF26 */
#define record_03DF28_ADDRESS 0x7F28u    /* 03DF28 */
#define indexed_table_03DF2A_ADDRESS 0x7F2Au    /* 03DF2A */
#define record_03DF2C_ADDRESS 0x7F2Cu    /* 03DF2C */
#define indexed_table_03DF2E_ADDRESS 0x7F2Eu    /* 03DF2E */
#define record_03DF30_ADDRESS 0x7F30u    /* 03DF30 */
#define indexed_table_03DF32_ADDRESS 0x7F32u    /* 03DF32 */
#define record_03DF34_ADDRESS 0x7F34u    /* 03DF34 */
#define indexed_table_03DF36_ADDRESS 0x7F36u    /* 03DF36 */
#define indexed_table_03DF3D_ADDRESS 0x7F3Du    /* 03DF3D */
#define indexed_table_03DF42_ADDRESS 0x7F42u    /* 03DF42 */
#define indexed_table_03DF52_ADDRESS 0x7F52u    /* 03DF52 */
#define bank_1e_states_ADDRESS 0x7F62u    /* 03DF62 */
#define loaded_table_03DF7C_ADDRESS 0x7F7Cu    /* 03DF7C */
#define constant_table_03DF80_ADDRESS 0x7F80u    /* 03DF80 */
#define indexed_table_03DF9A_ADDRESS 0x7F9Au    /* 03DF9A */
#define record_03DF9C_ADDRESS 0x7F9Cu    /* 03DF9C */
#define indexed_table_03DF9E_ADDRESS 0x7F9Eu    /* 03DF9E */
#define record_03DFA0_ADDRESS 0x7FA0u    /* 03DFA0 */
#define indexed_table_03DFA2_ADDRESS 0x7FA2u    /* 03DFA2 */
#define loaded_table_03DFAA_ADDRESS 0x7FAAu    /* 03DFAA */
#define story_script_03E62E_ADDRESS 0x662Eu    /* 03E62E */
#define story_script_03E8A7_ADDRESS 0x68A7u    /* 03E8A7 */
#define story_script_03E8C0_ADDRESS 0x68C0u    /* 03E8C0 */
#define story_script_03E8E4_ADDRESS 0x68E4u    /* 03E8E4 */
#define story_script_03E90D_ADDRESS 0x690Du    /* 03E90D */
#define story_script_03E978_ADDRESS 0x6978u    /* 03E978 */
#define story_script_03E993_ADDRESS 0x6993u    /* 03E993 */
#define fill_03E9BA_ADDRESS 0x69BAu    /* 03E9BA */
#define fill_03ED54_ADDRESS 0x6D54u    /* 03ED54 */
#define loaded_table_03F000_ADDRESS 0x7000u    /* 03F000 */
#define loaded_table_03F04C_ADDRESS 0x704Cu    /* 03F04C */
#define loaded_table_03F05C_ADDRESS 0x705Cu    /* 03F05C */
#define story_script_03F06C_ADDRESS 0x706Cu    /* 03F06C */
#define story_script_03F150_ADDRESS 0x7150u    /* 03F150 */
#define story_script_03F1BD_ADDRESS 0x71BDu    /* 03F1BD */
#define story_script_03F25F_ADDRESS 0x725Fu    /* 03F25F */
#define story_script_03F2D7_ADDRESS 0x72D7u    /* 03F2D7 */
#define story_script_03F2F6_ADDRESS 0x72F6u    /* 03F2F6 */
#define story_script_03F31A_ADDRESS 0x731Au    /* 03F31A */
#define story_script_03F376_ADDRESS 0x7376u    /* 03F376 */
#define story_script_03F403_ADDRESS 0x7403u    /* 03F403 */
#define story_script_03F489_ADDRESS 0x7489u    /* 03F489 */
#define story_script_03F5E2_ADDRESS 0x75E2u    /* 03F5E2 */
#define story_script_03F647_ADDRESS 0x7647u    /* 03F647 */
#define story_script_03F6F6_ADDRESS 0x76F6u    /* 03F6F6 */
#define story_script_03F82D_ADDRESS 0x782Du    /* 03F82D */
#define story_script_03F846_ADDRESS 0x7846u    /* 03F846 */
#define story_script_03F8F5_ADDRESS 0x78F5u    /* 03F8F5 */
#define story_script_03F997_ADDRESS 0x7997u    /* 03F997 */
#define story_script_03FA56_ADDRESS 0x7A56u    /* 03FA56 */
#define story_script_03FB84_ADDRESS 0x7B84u    /* 03FB84 */
#define story_script_03FBA1_ADDRESS 0x7BA1u    /* 03FBA1 */
#define story_script_03FBC1_ADDRESS 0x7BC1u    /* 03FBC1 */
#define story_script_03FBDA_ADDRESS 0x7BDAu    /* 03FBDA */
#define story_script_03FCCC_ADDRESS 0x7CCCu    /* 03FCCC */
#define story_script_03FD67_ADDRESS 0x7D67u    /* 03FD67 */
#define story_script_03FDAA_ADDRESS 0x7DAAu    /* 03FDAA */
#define story_script_03FE24_ADDRESS 0x7E24u    /* 03FE24 */
#define story_script_03FE31_ADDRESS 0x7E31u    /* 03FE31 */
#define story_script_03FE4D_ADDRESS 0x7E4Du    /* 03FE4D */
#define loaded_table_03FE5B_ADDRESS 0x7E5Bu    /* 03FE5B */
#define loaded_table_03FEDC_ADDRESS 0x7EDCu    /* 03FEDC */
#define fill_040D4C_ADDRESS 0x6D4Cu    /* 040D4C */
#define loaded_table_041000_ADDRESS 0x7000u    /* 041000 */
#define loaded_table_041010_ADDRESS 0x7010u    /* 041010 */
#define loaded_table_041014_ADDRESS 0x7014u    /* 041014 */
#define loaded_table_04101A_ADDRESS 0x701Au    /* 04101A */
#define loaded_table_041026_ADDRESS 0x7026u    /* 041026 */
#define loaded_table_041032_ADDRESS 0x7032u    /* 041032 */
#define loaded_table_04103E_ADDRESS 0x703Eu    /* 04103E */
#define loaded_table_04104C_ADDRESS 0x704Cu    /* 04104C */
#define loaded_table_041056_ADDRESS 0x7056u    /* 041056 */
#define loaded_table_04105A_ADDRESS 0x705Au    /* 04105A */
#define loaded_table_041066_ADDRESS 0x7066u    /* 041066 */
#define loaded_table_04106B_ADDRESS 0x706Bu    /* 04106B */
#define loaded_table_041070_ADDRESS 0x7070u    /* 041070 */
#define loaded_table_041075_ADDRESS 0x7075u    /* 041075 */
#define loaded_table_04107A_ADDRESS 0x707Au    /* 04107A */
#define loaded_table_041089_ADDRESS 0x7089u    /* 041089 */
#define loaded_table_04108E_ADDRESS 0x708Eu    /* 04108E */
#define loaded_table_041093_ADDRESS 0x7093u    /* 041093 */
#define loaded_table_041098_ADDRESS 0x7098u    /* 041098 */
#define loaded_table_04109D_ADDRESS 0x709Du    /* 04109D */
#define loaded_table_0410A2_ADDRESS 0x70A2u    /* 0410A2 */
#define loaded_table_0410A7_ADDRESS 0x70A7u    /* 0410A7 */
#define loaded_table_0410AC_ADDRESS 0x70ACu    /* 0410AC */
#define loaded_table_0410B1_ADDRESS 0x70B1u    /* 0410B1 */
#define loaded_table_0410BB_ADDRESS 0x70BBu    /* 0410BB */
#define loaded_table_0410C5_ADDRESS 0x70C5u    /* 0410C5 */
#define loaded_table_0410CF_ADDRESS 0x70CFu    /* 0410CF */
#define loaded_table_0410D9_ADDRESS 0x70D9u    /* 0410D9 */
#define indexed_table_0410ED_ADDRESS 0x70EDu    /* 0410ED */
#define indexed_table_0410F2_ADDRESS 0x70F2u    /* 0410F2 */
#define indexed_table_0410F7_ADDRESS 0x70F7u    /* 0410F7 */
#define indexed_table_0410FC_ADDRESS 0x70FCu    /* 0410FC */
#define indexed_table_041101_ADDRESS 0x7101u    /* 041101 */
#define profile_text_041118_ADDRESS 0x7118u    /* 041118 */
#define profile_text_04114A_ADDRESS 0x714Au    /* 04114A */
#define profile_text_041170_ADDRESS 0x7170u    /* 041170 */
#define profile_text_041199_ADDRESS 0x7199u    /* 041199 */
#define profile_text_0411BD_ADDRESS 0x71BDu    /* 0411BD */
#define profile_text_0411EE_ADDRESS 0x71EEu    /* 0411EE */
#define profile_text_041209_ADDRESS 0x7209u    /* 041209 */
#define profile_text_04124C_ADDRESS 0x724Cu    /* 04124C */
#define profile_text_04126B_ADDRESS 0x726Bu    /* 04126B */
#define indexed_table_04132C_ADDRESS 0x732Cu    /* 04132C */
#define indexed_table_04133B_ADDRESS 0x733Bu    /* 04133B */
#define indexed_table_041344_ADDRESS 0x7344u    /* 041344 */
#define indexed_table_041358_ADDRESS 0x7358u    /* 041358 */
#define indexed_table_041370_ADDRESS 0x7370u    /* 041370 */
#define indexed_table_041388_ADDRESS 0x7388u    /* 041388 */
#define indexed_table_0413A6_ADDRESS 0x73A6u    /* 0413A6 */
#define indexed_table_0413B5_ADDRESS 0x73B5u    /* 0413B5 */
#define indexed_table_0413C4_ADDRESS 0x73C4u    /* 0413C4 */
#define indexed_table_0413D3_ADDRESS 0x73D3u    /* 0413D3 */
#define indexed_table_0413E2_ADDRESS 0x73E2u    /* 0413E2 */
#define indexed_table_041405_ADDRESS 0x7405u    /* 041405 */
#define indexed_table_041448_ADDRESS 0x7448u    /* 041448 */
#define indexed_table_04148B_ADDRESS 0x748Bu    /* 04148B */
#define indexed_table_0414CE_ADDRESS 0x74CEu    /* 0414CE */
#define indexed_table_041511_ADDRESS 0x7511u    /* 041511 */
#define indexed_table_041554_ADDRESS 0x7554u    /* 041554 */
#define indexed_table_041597_ADDRESS 0x7597u    /* 041597 */
#define indexed_table_0415DA_ADDRESS 0x75DAu    /* 0415DA */
#define indexed_table_04161D_ADDRESS 0x761Du    /* 04161D */
#define indexed_table_041660_ADDRESS 0x7660u    /* 041660 */
#define indexed_table_0416A3_ADDRESS 0x76A3u    /* 0416A3 */
#define indexed_table_0416F4_ADDRESS 0x76F4u    /* 0416F4 */
#define indexed_table_041745_ADDRESS 0x7745u    /* 041745 */
#define loaded_table_04174E_ADDRESS 0x774Eu    /* 04174E */
#define loaded_table_04177A_ADDRESS 0x777Au    /* 04177A */
#define fill_0417C4_ADDRESS 0x77C4u    /* 0417C4 */
#define set_index_042000_ADDRESS 0x6000u    /* 042000 */
#define animation_table_042016_ADDRESS 0x6016u    /* 042016 */
#define animation_042020_ADDRESS 0x6020u    /* 042020 */
#define sprite_list_042028_ADDRESS 0x6028u    /* 042028 */
#define animation_04204C_ADDRESS 0x604Cu    /* 04204C */
#define sprite_list_042054_ADDRESS 0x6054u    /* 042054 */
#define animation_042078_ADDRESS 0x6078u    /* 042078 */
#define sprite_list_042080_ADDRESS 0x6080u    /* 042080 */
#define animation_0420B0_ADDRESS 0x60B0u    /* 0420B0 */
#define sprite_list_0420B8_ADDRESS 0x60B8u    /* 0420B8 */
#define animation_0420E8_ADDRESS 0x60E8u    /* 0420E8 */
#define sprite_list_0420F0_ADDRESS 0x60F0u    /* 0420F0 */
#define animation_table_042120_ADDRESS 0x6120u    /* 042120 */
#define animation_042150_ADDRESS 0x6150u    /* 042150 */
#define sprite_list_042158_ADDRESS 0x6158u    /* 042158 */
#define animation_042164_ADDRESS 0x6164u    /* 042164 */
#define sprite_list_04216C_ADDRESS 0x616Cu    /* 04216C */
#define animation_042196_ADDRESS 0x6196u    /* 042196 */
#define sprite_list_04219E_ADDRESS 0x619Eu    /* 04219E */
#define animation_0421C8_ADDRESS 0x61C8u    /* 0421C8 */
#define sprite_list_0421D0_ADDRESS 0x61D0u    /* 0421D0 */
#define animation_0421EE_ADDRESS 0x61EEu    /* 0421EE */
#define sprite_list_0421F6_ADDRESS 0x61F6u    /* 0421F6 */
#define animation_04221A_ADDRESS 0x621Au    /* 04221A */
#define sprite_list_042222_ADDRESS 0x6222u    /* 042222 */
#define animation_04224C_ADDRESS 0x624Cu    /* 04224C */
#define sprite_list_042254_ADDRESS 0x6254u    /* 042254 */
#define animation_04227E_ADDRESS 0x627Eu    /* 04227E */
#define sprite_list_042286_ADDRESS 0x6286u    /* 042286 */
#define animation_0422AA_ADDRESS 0x62AAu    /* 0422AA */
#define sprite_list_0422B2_ADDRESS 0x62B2u    /* 0422B2 */
#define animation_0422E2_ADDRESS 0x62E2u    /* 0422E2 */
#define sprite_list_0422EA_ADDRESS 0x62EAu    /* 0422EA */
#define animation_042314_ADDRESS 0x6314u    /* 042314 */
#define sprite_list_04231C_ADDRESS 0x631Cu    /* 04231C */
#define animation_04233A_ADDRESS 0x633Au    /* 04233A */
#define sprite_list_042342_ADDRESS 0x6342u    /* 042342 */
#define animation_04236C_ADDRESS 0x636Cu    /* 04236C */
#define sprite_list_042374_ADDRESS 0x6374u    /* 042374 */
#define animation_0423A4_ADDRESS 0x63A4u    /* 0423A4 */
#define sprite_list_0423AC_ADDRESS 0x63ACu    /* 0423AC */
#define animation_0423D0_ADDRESS 0x63D0u    /* 0423D0 */
#define sprite_list_0423D8_ADDRESS 0x63D8u    /* 0423D8 */
#define animation_042402_ADDRESS 0x6402u    /* 042402 */
#define sprite_list_04240A_ADDRESS 0x640Au    /* 04240A */
#define animation_04242E_ADDRESS 0x642Eu    /* 04242E */
#define sprite_list_042436_ADDRESS 0x6436u    /* 042436 */
#define animation_042454_ADDRESS 0x6454u    /* 042454 */
#define sprite_list_04245C_ADDRESS 0x645Cu    /* 04245C */
#define animation_042474_ADDRESS 0x6474u    /* 042474 */
#define sprite_list_04247C_ADDRESS 0x647Cu    /* 04247C */
#define animation_0424A6_ADDRESS 0x64A6u    /* 0424A6 */
#define sprite_list_0424AE_ADDRESS 0x64AEu    /* 0424AE */
#define animation_0424C6_ADDRESS 0x64C6u    /* 0424C6 */
#define sprite_list_0424CE_ADDRESS 0x64CEu    /* 0424CE */
#define animation_0424FE_ADDRESS 0x64FEu    /* 0424FE */
#define sprite_list_042506_ADDRESS 0x6506u    /* 042506 */
#define animation_04252A_ADDRESS 0x652Au    /* 04252A */
#define sprite_list_042532_ADDRESS 0x6532u    /* 042532 */
#define animation_042562_ADDRESS 0x6562u    /* 042562 */
#define sprite_list_04256A_ADDRESS 0x656Au    /* 04256A */
#define animation_table_0425CA_ADDRESS 0x65CAu    /* 0425CA */
#define animation_0425D6_ADDRESS 0x65D6u    /* 0425D6 */
#define sprite_list_0425E2_ADDRESS 0x65E2u    /* 0425E2 */
#define sprite_list_0425F4_ADDRESS 0x65F4u    /* 0425F4 */
#define animation_042606_ADDRESS 0x6606u    /* 042606 */
#define sprite_list_042612_ADDRESS 0x6612u    /* 042612 */
#define sprite_list_042630_ADDRESS 0x6630u    /* 042630 */
#define animation_04264E_ADDRESS 0x664Eu    /* 04264E */
#define sprite_list_042656_ADDRESS 0x6656u    /* 042656 */
#define animation_042674_ADDRESS 0x6674u    /* 042674 */
#define sprite_list_04267C_ADDRESS 0x667Cu    /* 04267C */
#define animation_0426A0_ADDRESS 0x66A0u    /* 0426A0 */
#define sprite_list_0426A8_ADDRESS 0x66A8u    /* 0426A8 */
#define animation_0426CC_ADDRESS 0x66CCu    /* 0426CC */
#define animation_table_0426D8_ADDRESS 0x66D8u    /* 0426D8 */
#define animation_0426E0_ADDRESS 0x66E0u    /* 0426E0 */
#define sprite_list_0426F4_ADDRESS 0x66F4u    /* 0426F4 */
#define sprite_list_042700_ADDRESS 0x6700u    /* 042700 */
#define sprite_list_04270C_ADDRESS 0x670Cu    /* 04270C */
#define animation_042718_ADDRESS 0x6718u    /* 042718 */
#define sprite_list_042720_ADDRESS 0x6720u    /* 042720 */
#define animation_04272C_ADDRESS 0x672Cu    /* 04272C */
#define sprite_list_042738_ADDRESS 0x6738u    /* 042738 */
#define sprite_list_04274A_ADDRESS 0x674Au    /* 04274A */
#define animation_04275C_ADDRESS 0x675Cu    /* 04275C */
#define sprite_list_042764_ADDRESS 0x6764u    /* 042764 */
#define animation_table_04277C_ADDRESS 0x677Cu    /* 04277C */
#define animation_042784_ADDRESS 0x6784u    /* 042784 */
#define sprite_list_042790_ADDRESS 0x6790u    /* 042790 */
#define sprite_list_042796_ADDRESS 0x6796u    /* 042796 */
#define animation_04279C_ADDRESS 0x679Cu    /* 04279C */
#define sprite_list_0427AC_ADDRESS 0x67ACu    /* 0427AC */
#define sprite_list_0427B8_ADDRESS 0x67B8u    /* 0427B8 */
#define sprite_list_0427C4_ADDRESS 0x67C4u    /* 0427C4 */
#define animation_0427D0_ADDRESS 0x67D0u    /* 0427D0 */
#define sprite_list_0427E4_ADDRESS 0x67E4u    /* 0427E4 */
#define sprite_list_0427EA_ADDRESS 0x67EAu    /* 0427EA */
#define sprite_list_0427F0_ADDRESS 0x67F0u    /* 0427F0 */
#define animation_042802_ADDRESS 0x6802u    /* 042802 */
#define sprite_list_042816_ADDRESS 0x6816u    /* 042816 */
#define sprite_list_042822_ADDRESS 0x6822u    /* 042822 */
#define sprite_list_04282E_ADDRESS 0x682Eu    /* 04282E */
#define animation_table_042846_ADDRESS 0x6846u    /* 042846 */
#define animation_04284A_ADDRESS 0x684Au    /* 04284A */
#define sprite_list_04286A_ADDRESS 0x686Au    /* 04286A */
#define sprite_list_042876_ADDRESS 0x6876u    /* 042876 */
#define sprite_list_042882_ADDRESS 0x6882u    /* 042882 */
#define animation_04288E_ADDRESS 0x688Eu    /* 04288E */
#define sprite_list_0428B2_ADDRESS 0x68B2u    /* 0428B2 */
#define sprite_list_0428C4_ADDRESS 0x68C4u    /* 0428C4 */
#define sprite_list_0428D6_ADDRESS 0x68D6u    /* 0428D6 */
#define sprite_list_0428E8_ADDRESS 0x68E8u    /* 0428E8 */
#define sprite_list_0428FA_ADDRESS 0x68FAu    /* 0428FA */
#define animation_table_04290C_ADDRESS 0x690Cu    /* 04290C */
#define animation_042916_ADDRESS 0x6916u    /* 042916 */
#define sprite_list_04291E_ADDRESS 0x691Eu    /* 04291E */
#define animation_042924_ADDRESS 0x6924u    /* 042924 */
#define sprite_list_042930_ADDRESS 0x6930u    /* 042930 */
#define animation_042936_ADDRESS 0x6936u    /* 042936 */
#define sprite_list_042942_ADDRESS 0x6942u    /* 042942 */
#define sprite_list_042948_ADDRESS 0x6948u    /* 042948 */
#define animation_04294E_ADDRESS 0x694Eu    /* 04294E */
#define sprite_list_04295A_ADDRESS 0x695Au    /* 04295A */
#define sprite_list_042960_ADDRESS 0x6960u    /* 042960 */
#define animation_042966_ADDRESS 0x6966u    /* 042966 */
#define sprite_list_042972_ADDRESS 0x6972u    /* 042972 */
#define sprite_list_042978_ADDRESS 0x6978u    /* 042978 */
#define animation_table_04297E_ADDRESS 0x697Eu    /* 04297E */
#define unreached_animation_0429CE_ADDRESS 0x69CEu    /* 0429CE */
#define sprite_list_0429D6_ADDRESS 0x69D6u    /* 0429D6 */
#define animation_0429E2_ADDRESS 0x69E2u    /* 0429E2 */
#define sprite_list_042A06_ADDRESS 0x6A06u    /* 042A06 */
#define sprite_list_042A12_ADDRESS 0x6A12u    /* 042A12 */
#define sprite_list_042A1E_ADDRESS 0x6A1Eu    /* 042A1E */
#define animation_042A2A_ADDRESS 0x6A2Au    /* 042A2A */
#define sprite_list_042A4E_ADDRESS 0x6A4Eu    /* 042A4E */
#define sprite_list_042A5A_ADDRESS 0x6A5Au    /* 042A5A */
#define sprite_list_042A66_ADDRESS 0x6A66u    /* 042A66 */
#define animation_042A72_ADDRESS 0x6A72u    /* 042A72 */
#define sprite_list_042A96_ADDRESS 0x6A96u    /* 042A96 */
#define sprite_list_042AA2_ADDRESS 0x6AA2u    /* 042AA2 */
#define sprite_list_042AB4_ADDRESS 0x6AB4u    /* 042AB4 */
#define animation_042AC0_ADDRESS 0x6AC0u    /* 042AC0 */
#define sprite_list_042AE4_ADDRESS 0x6AE4u    /* 042AE4 */
#define sprite_list_042AF0_ADDRESS 0x6AF0u    /* 042AF0 */
#define sprite_list_042AFC_ADDRESS 0x6AFCu    /* 042AFC */
#define sprite_list_042B0E_ADDRESS 0x6B0Eu    /* 042B0E */
#define sprite_list_042B20_ADDRESS 0x6B20u    /* 042B20 */
#define sprite_list_042B38_ADDRESS 0x6B38u    /* 042B38 */
#define animation_042B50_ADDRESS 0x6B50u    /* 042B50 */
#define sprite_list_042B74_ADDRESS 0x6B74u    /* 042B74 */
#define sprite_list_042B80_ADDRESS 0x6B80u    /* 042B80 */
#define sprite_list_042B86_ADDRESS 0x6B86u    /* 042B86 */
#define sprite_list_042B8C_ADDRESS 0x6B8Cu    /* 042B8C */
#define sprite_list_042B98_ADDRESS 0x6B98u    /* 042B98 */
#define sprite_list_042BA4_ADDRESS 0x6BA4u    /* 042BA4 */
#define animation_042BB0_ADDRESS 0x6BB0u    /* 042BB0 */
#define sprite_list_042BDC_ADDRESS 0x6BDCu    /* 042BDC */
#define sprite_list_042BE8_ADDRESS 0x6BE8u    /* 042BE8 */
#define sprite_list_042BF4_ADDRESS 0x6BF4u    /* 042BF4 */
#define sprite_list_042C06_ADDRESS 0x6C06u    /* 042C06 */
#define sprite_list_042C12_ADDRESS 0x6C12u    /* 042C12 */
#define sprite_list_042C24_ADDRESS 0x6C24u    /* 042C24 */
#define animation_042C30_ADDRESS 0x6C30u    /* 042C30 */
#define sprite_list_042C44_ADDRESS 0x6C44u    /* 042C44 */
#define sprite_list_042C4A_ADDRESS 0x6C4Au    /* 042C4A */
#define sprite_list_042C50_ADDRESS 0x6C50u    /* 042C50 */
#define sprite_list_042C56_ADDRESS 0x6C56u    /* 042C56 */
#define animation_042C5C_ADDRESS 0x6C5Cu    /* 042C5C */
#define sprite_list_042C74_ADDRESS 0x6C74u    /* 042C74 */
#define sprite_list_042C7A_ADDRESS 0x6C7Au    /* 042C7A */
#define sprite_list_042C80_ADDRESS 0x6C80u    /* 042C80 */
#define animation_042C86_ADDRESS 0x6C86u    /* 042C86 */
#define sprite_list_042CBA_ADDRESS 0x6CBAu    /* 042CBA */
#define sprite_list_042CC0_ADDRESS 0x6CC0u    /* 042CC0 */
#define sprite_list_042CC6_ADDRESS 0x6CC6u    /* 042CC6 */
#define sprite_list_042CCC_ADDRESS 0x6CCCu    /* 042CCC */
#define sprite_list_042CD2_ADDRESS 0x6CD2u    /* 042CD2 */
#define sprite_list_042CD8_ADDRESS 0x6CD8u    /* 042CD8 */
#define sprite_list_042CDE_ADDRESS 0x6CDEu    /* 042CDE */
#define sprite_list_042CE4_ADDRESS 0x6CE4u    /* 042CE4 */
#define sprite_list_042CEA_ADDRESS 0x6CEAu    /* 042CEA */
#define sprite_list_042CF0_ADDRESS 0x6CF0u    /* 042CF0 */
#define sprite_list_042CFC_ADDRESS 0x6CFCu    /* 042CFC */
#define animation_042D02_ADDRESS 0x6D02u    /* 042D02 */
#define animation_042D2A_ADDRESS 0x6D2Au    /* 042D2A */
#define animation_042D32_ADDRESS 0x6D32u    /* 042D32 */
#define sprite_list_042D46_ADDRESS 0x6D46u    /* 042D46 */
#define sprite_list_042D52_ADDRESS 0x6D52u    /* 042D52 */
#define sprite_list_042D5E_ADDRESS 0x6D5Eu    /* 042D5E */
#define sprite_list_042D6A_ADDRESS 0x6D6Au    /* 042D6A */
#define animation_042D76_ADDRESS 0x6D76u    /* 042D76 */
#define sprite_list_042DA2_ADDRESS 0x6DA2u    /* 042DA2 */
#define sprite_list_042DBA_ADDRESS 0x6DBAu    /* 042DBA */
#define sprite_list_042DC6_ADDRESS 0x6DC6u    /* 042DC6 */
#define sprite_list_042DD2_ADDRESS 0x6DD2u    /* 042DD2 */
#define sprite_list_042DE4_ADDRESS 0x6DE4u    /* 042DE4 */
#define sprite_list_042DF0_ADDRESS 0x6DF0u    /* 042DF0 */
#define sprite_list_042E02_ADDRESS 0x6E02u    /* 042E02 */
#define sprite_list_042E0E_ADDRESS 0x6E0Eu    /* 042E0E */
#define sprite_list_042E1A_ADDRESS 0x6E1Au    /* 042E1A */
#define animation_042E2C_ADDRESS 0x6E2Cu    /* 042E2C */
#define sprite_list_042E38_ADDRESS 0x6E38u    /* 042E38 */
#define animation_042E44_ADDRESS 0x6E44u    /* 042E44 */
#define sprite_list_042E58_ADDRESS 0x6E58u    /* 042E58 */
#define sprite_list_042E64_ADDRESS 0x6E64u    /* 042E64 */
#define sprite_list_042E6A_ADDRESS 0x6E6Au    /* 042E6A */
#define animation_042E70_ADDRESS 0x6E70u    /* 042E70 */
#define sprite_list_042E80_ADDRESS 0x6E80u    /* 042E80 */
#define sprite_list_042E8C_ADDRESS 0x6E8Cu    /* 042E8C */
#define animation_042E92_ADDRESS 0x6E92u    /* 042E92 */
#define sprite_list_042E9E_ADDRESS 0x6E9Eu    /* 042E9E */
#define sprite_list_042EA4_ADDRESS 0x6EA4u    /* 042EA4 */
#define animation_042EB0_ADDRESS 0x6EB0u    /* 042EB0 */
#define sprite_list_042EB8_ADDRESS 0x6EB8u    /* 042EB8 */
#define animation_042ED0_ADDRESS 0x6ED0u    /* 042ED0 */
#define animation_042ED8_ADDRESS 0x6ED8u    /* 042ED8 */
#define sprite_list_042EF4_ADDRESS 0x6EF4u    /* 042EF4 */
#define sprite_list_042F00_ADDRESS 0x6F00u    /* 042F00 */
#define sprite_list_042F12_ADDRESS 0x6F12u    /* 042F12 */
#define sprite_list_042F1E_ADDRESS 0x6F1Eu    /* 042F1E */
#define animation_042F2A_ADDRESS 0x6F2Au    /* 042F2A */
#define animation_042F3E_ADDRESS 0x6F3Eu    /* 042F3E */
#define sprite_list_042F6A_ADDRESS 0x6F6Au    /* 042F6A */
#define sprite_list_042F82_ADDRESS 0x6F82u    /* 042F82 */
#define sprite_list_042F8E_ADDRESS 0x6F8Eu    /* 042F8E */
#define sprite_list_042F9A_ADDRESS 0x6F9Au    /* 042F9A */
#define sprite_list_042FAC_ADDRESS 0x6FACu    /* 042FAC */
#define sprite_list_042FB8_ADDRESS 0x6FB8u    /* 042FB8 */
#define sprite_list_042FCA_ADDRESS 0x6FCAu    /* 042FCA */
#define sprite_list_042FD6_ADDRESS 0x6FD6u    /* 042FD6 */
#define sprite_list_042FE2_ADDRESS 0x6FE2u    /* 042FE2 */
#define animation_042FF4_ADDRESS 0x6FF4u    /* 042FF4 */
#define sprite_list_043024_ADDRESS 0x7024u    /* 043024 */
#define sprite_list_043030_ADDRESS 0x7030u    /* 043030 */
#define sprite_list_043042_ADDRESS 0x7042u    /* 043042 */
#define sprite_list_043054_ADDRESS 0x7054u    /* 043054 */
#define sprite_list_043066_ADDRESS 0x7066u    /* 043066 */
#define sprite_list_04307E_ADDRESS 0x707Eu    /* 04307E */
#define sprite_list_043090_ADDRESS 0x7090u    /* 043090 */
#define sprite_list_0430A8_ADDRESS 0x70A8u    /* 0430A8 */
#define animation_0430BA_ADDRESS 0x70BAu    /* 0430BA */
#define sprite_list_0430DA_ADDRESS 0x70DAu    /* 0430DA */
#define sprite_list_0430E6_ADDRESS 0x70E6u    /* 0430E6 */
#define sprite_list_0430F2_ADDRESS 0x70F2u    /* 0430F2 */
#define sprite_list_043104_ADDRESS 0x7104u    /* 043104 */
#define sprite_list_04311C_ADDRESS 0x711Cu    /* 04311C */
#define animation_04313A_ADDRESS 0x713Au    /* 04313A */
#define sprite_list_043166_ADDRESS 0x7166u    /* 043166 */
#define animation_043178_ADDRESS 0x7178u    /* 043178 */
#define sprite_list_0431A4_ADDRESS 0x71A4u    /* 0431A4 */
#define sprite_list_0431C2_ADDRESS 0x71C2u    /* 0431C2 */
#define sprite_list_0431DA_ADDRESS 0x71DAu    /* 0431DA */
#define sprite_list_0431EC_ADDRESS 0x71ECu    /* 0431EC */
#define sprite_list_0431FE_ADDRESS 0x71FEu    /* 0431FE */
#define sprite_list_043210_ADDRESS 0x7210u    /* 043210 */
#define sprite_list_043222_ADDRESS 0x7222u    /* 043222 */
#define animation_043234_ADDRESS 0x7234u    /* 043234 */
#define animation_table_04323C_ADDRESS 0x723Cu    /* 04323C */
#define animation_043254_ADDRESS 0x7254u    /* 043254 */
#define sprite_list_04326C_ADDRESS 0x726Cu    /* 04326C */
#define sprite_list_04328A_ADDRESS 0x728Au    /* 04328A */
#define sprite_list_0432A8_ADDRESS 0x72A8u    /* 0432A8 */
#define sprite_list_0432C6_ADDRESS 0x72C6u    /* 0432C6 */
#define sprite_list_0432E4_ADDRESS 0x72E4u    /* 0432E4 */
#define animation_043302_ADDRESS 0x7302u    /* 043302 */
#define sprite_list_043316_ADDRESS 0x7316u    /* 043316 */
#define sprite_list_043334_ADDRESS 0x7334u    /* 043334 */
#define sprite_list_043364_ADDRESS 0x7364u    /* 043364 */
#define sprite_list_043394_ADDRESS 0x7394u    /* 043394 */
#define animation_0433C4_ADDRESS 0x73C4u    /* 0433C4 */
#define sprite_list_0433E0_ADDRESS 0x73E0u    /* 0433E0 */
#define sprite_list_04340A_ADDRESS 0x740Au    /* 04340A */
#define sprite_list_04342E_ADDRESS 0x742Eu    /* 04342E */
#define sprite_list_043458_ADDRESS 0x7458u    /* 043458 */
#define sprite_list_043482_ADDRESS 0x7482u    /* 043482 */
#define sprite_list_0434A6_ADDRESS 0x74A6u    /* 0434A6 */
#define animation_0434D0_ADDRESS 0x74D0u    /* 0434D0 */
#define sprite_list_0434E4_ADDRESS 0x74E4u    /* 0434E4 */
#define sprite_list_043514_ADDRESS 0x7514u    /* 043514 */
#define sprite_list_04353E_ADDRESS 0x753Eu    /* 04353E */
#define animation_04356E_ADDRESS 0x756Eu    /* 04356E */
#define sprite_list_043576_ADDRESS 0x7576u    /* 043576 */
#define animation_0435A6_ADDRESS 0x75A6u    /* 0435A6 */
#define sprite_list_0435B2_ADDRESS 0x75B2u    /* 0435B2 */
#define sprite_list_0435D6_ADDRESS 0x75D6u    /* 0435D6 */
#define animation_0435F4_ADDRESS 0x75F4u    /* 0435F4 */
#define sprite_list_043600_ADDRESS 0x7600u    /* 043600 */
#define sprite_list_04361E_ADDRESS 0x761Eu    /* 04361E */
#define animation_043642_ADDRESS 0x7642u    /* 043642 */
#define sprite_list_043656_ADDRESS 0x7656u    /* 043656 */
#define sprite_list_04367A_ADDRESS 0x767Au    /* 04367A */
#define sprite_list_0436A4_ADDRESS 0x76A4u    /* 0436A4 */
#define sprite_list_0436CE_ADDRESS 0x76CEu    /* 0436CE */
#define animation_0436FE_ADDRESS 0x76FEu    /* 0436FE */
#define sprite_list_04370E_ADDRESS 0x770Eu    /* 04370E */
#define sprite_list_043732_ADDRESS 0x7732u    /* 043732 */
#define sprite_list_043756_ADDRESS 0x7756u    /* 043756 */
#define animation_043780_ADDRESS 0x7780u    /* 043780 */
#define animation_043788_ADDRESS 0x7788u    /* 043788 */
#define sprite_list_04379C_ADDRESS 0x779Cu    /* 04379C */
#define sprite_list_0437C6_ADDRESS 0x77C6u    /* 0437C6 */
#define animation_0437F0_ADDRESS 0x77F0u    /* 0437F0 */
#define animation_table_043810_ADDRESS 0x7810u    /* 043810 */
#define animation_043814_ADDRESS 0x7814u    /* 043814 */
#define sprite_list_043858_ADDRESS 0x7858u    /* 043858 */
#define sprite_list_04386A_ADDRESS 0x786Au    /* 04386A */
#define sprite_list_04387C_ADDRESS 0x787Cu    /* 04387C */
#define sprite_list_043894_ADDRESS 0x7894u    /* 043894 */
#define sprite_list_0438AC_ADDRESS 0x78ACu    /* 0438AC */
#define sprite_list_0438C4_ADDRESS 0x78C4u    /* 0438C4 */
#define sprite_list_0438DC_ADDRESS 0x78DCu    /* 0438DC */
#define sprite_list_0438FA_ADDRESS 0x78FAu    /* 0438FA */
#define sprite_list_043918_ADDRESS 0x7918u    /* 043918 */
#define sprite_list_043930_ADDRESS 0x7930u    /* 043930 */
#define sprite_list_04394E_ADDRESS 0x794Eu    /* 04394E */
#define animation_04396C_ADDRESS 0x796Cu    /* 04396C */
#define sprite_list_043980_ADDRESS 0x7980u    /* 043980 */
#define sprite_list_04399E_ADDRESS 0x799Eu    /* 04399E */
#define sprite_list_0439B6_ADDRESS 0x79B6u    /* 0439B6 */
#define sprite_list_0439D4_ADDRESS 0x79D4u    /* 0439D4 */
#define animation_table_0439EC_ADDRESS 0x79ECu    /* 0439EC */
#define animation_043A14_ADDRESS 0x7A14u    /* 043A14 */
#define sprite_list_043A1C_ADDRESS 0x7A1Cu    /* 043A1C */
#define animation_043A2E_ADDRESS 0x7A2Eu    /* 043A2E */
#define sprite_list_043A36_ADDRESS 0x7A36u    /* 043A36 */
#define animation_043A48_ADDRESS 0x7A48u    /* 043A48 */
#define sprite_list_043A50_ADDRESS 0x7A50u    /* 043A50 */
#define animation_043A62_ADDRESS 0x7A62u    /* 043A62 */
#define sprite_list_043A6A_ADDRESS 0x7A6Au    /* 043A6A */
#define animation_043A7C_ADDRESS 0x7A7Cu    /* 043A7C */
#define sprite_list_043A84_ADDRESS 0x7A84u    /* 043A84 */
#define animation_043A96_ADDRESS 0x7A96u    /* 043A96 */
#define sprite_list_043A9E_ADDRESS 0x7A9Eu    /* 043A9E */
#define animation_043AB0_ADDRESS 0x7AB0u    /* 043AB0 */
#define sprite_list_043AB8_ADDRESS 0x7AB8u    /* 043AB8 */
#define animation_043ACA_ADDRESS 0x7ACAu    /* 043ACA */
#define sprite_list_043AD2_ADDRESS 0x7AD2u    /* 043AD2 */
#define animation_043AE4_ADDRESS 0x7AE4u    /* 043AE4 */
#define sprite_list_043AEC_ADDRESS 0x7AECu    /* 043AEC */
#define animation_043AFE_ADDRESS 0x7AFEu    /* 043AFE */
#define sprite_list_043B06_ADDRESS 0x7B06u    /* 043B06 */
#define animation_043B18_ADDRESS 0x7B18u    /* 043B18 */
#define sprite_list_043B20_ADDRESS 0x7B20u    /* 043B20 */
#define animation_043B32_ADDRESS 0x7B32u    /* 043B32 */
#define sprite_list_043B3A_ADDRESS 0x7B3Au    /* 043B3A */
#define animation_043B4C_ADDRESS 0x7B4Cu    /* 043B4C */
#define sprite_list_043B54_ADDRESS 0x7B54u    /* 043B54 */
#define animation_043B66_ADDRESS 0x7B66u    /* 043B66 */
#define sprite_list_043B6E_ADDRESS 0x7B6Eu    /* 043B6E */
#define animation_043B80_ADDRESS 0x7B80u    /* 043B80 */
#define sprite_list_043B88_ADDRESS 0x7B88u    /* 043B88 */
#define animation_043B9A_ADDRESS 0x7B9Au    /* 043B9A */
#define sprite_list_043BA2_ADDRESS 0x7BA2u    /* 043BA2 */
#define animation_043BB4_ADDRESS 0x7BB4u    /* 043BB4 */
#define sprite_list_043BBC_ADDRESS 0x7BBCu    /* 043BBC */
#define animation_043BCE_ADDRESS 0x7BCEu    /* 043BCE */
#define sprite_list_043BD6_ADDRESS 0x7BD6u    /* 043BD6 */
#define animation_043BE8_ADDRESS 0x7BE8u    /* 043BE8 */
#define sprite_list_043BF0_ADDRESS 0x7BF0u    /* 043BF0 */
#define animation_043C08_ADDRESS 0x7C08u    /* 043C08 */
#define sprite_list_043C10_ADDRESS 0x7C10u    /* 043C10 */
#define fill_043C28_ADDRESS 0x7C28u    /* 043C28 */
#define unreached_animation_043D48_ADDRESS 0x7D48u    /* 043D48 */
#define sprite_list_043D64_ADDRESS 0x7D64u    /* 043D64 */
#define sprite_list_043D8E_ADDRESS 0x7D8Eu    /* 043D8E */
#define sprite_list_043DBE_ADDRESS 0x7DBEu    /* 043DBE */
#define sprite_list_043DF4_ADDRESS 0x7DF4u    /* 043DF4 */
#define sprite_list_043E30_ADDRESS 0x7E30u    /* 043E30 */
#define sprite_list_043E78_ADDRESS 0x7E78u    /* 043E78 */
#define fill_043ECC_ADDRESS 0x7ECCu    /* 043ECC */
#define set_index_044000_ADDRESS 0x6000u    /* 044000 */
#define animation_table_04400A_ADDRESS 0x600Au    /* 04400A */
#define animation_04401E_ADDRESS 0x601Eu    /* 04401E */
#define sprite_list_04404A_ADDRESS 0x604Au    /* 04404A */
#define sprite_list_044056_ADDRESS 0x6056u    /* 044056 */
#define sprite_list_044062_ADDRESS 0x6062u    /* 044062 */
#define sprite_list_04406E_ADDRESS 0x606Eu    /* 04406E */
#define animation_044074_ADDRESS 0x6074u    /* 044074 */
#define sprite_list_044084_ADDRESS 0x6084u    /* 044084 */
#define sprite_list_04409C_ADDRESS 0x609Cu    /* 04409C */
#define sprite_list_0440AE_ADDRESS 0x60AEu    /* 0440AE */
#define animation_0440BA_ADDRESS 0x60BAu    /* 0440BA */
#define sprite_list_0440C2_ADDRESS 0x60C2u    /* 0440C2 */
#define animation_0440D4_ADDRESS 0x60D4u    /* 0440D4 */
#define sprite_list_0440DC_ADDRESS 0x60DCu    /* 0440DC */
#define animation_0440E2_ADDRESS 0x60E2u    /* 0440E2 */
#define sprite_list_0440EA_ADDRESS 0x60EAu    /* 0440EA */
#define animation_0440F6_ADDRESS 0x60F6u    /* 0440F6 */
#define sprite_list_0440FE_ADDRESS 0x60FEu    /* 0440FE */
#define animation_04411C_ADDRESS 0x611Cu    /* 04411C */
#define sprite_list_04413C_ADDRESS 0x613Cu    /* 04413C */
#define sprite_list_044142_ADDRESS 0x6142u    /* 044142 */
#define sprite_list_044148_ADDRESS 0x6148u    /* 044148 */
#define sprite_list_04414E_ADDRESS 0x614Eu    /* 04414E */
#define sprite_list_044178_ADDRESS 0x6178u    /* 044178 */
#define sprite_list_0441B4_ADDRESS 0x61B4u    /* 0441B4 */
#define sprite_list_0441F0_ADDRESS 0x61F0u    /* 0441F0 */
#define animation_044226_ADDRESS 0x6226u    /* 044226 */
#define sprite_list_04422E_ADDRESS 0x622Eu    /* 04422E */
#define animation_04424C_ADDRESS 0x624Cu    /* 04424C */
#define sprite_list_044254_ADDRESS 0x6254u    /* 044254 */
#define animation_04426C_ADDRESS 0x626Cu    /* 04426C */
#define sprite_list_044274_ADDRESS 0x6274u    /* 044274 */
#define animation_table_044280_ADDRESS 0x6280u    /* 044280 */
#define animation_044290_ADDRESS 0x6290u    /* 044290 */
#define sprite_list_0442B4_ADDRESS 0x62B4u    /* 0442B4 */
#define sprite_list_0442D8_ADDRESS 0x62D8u    /* 0442D8 */
#define sprite_list_0442F6_ADDRESS 0x62F6u    /* 0442F6 */
#define sprite_list_044314_ADDRESS 0x6314u    /* 044314 */
#define sprite_list_044332_ADDRESS 0x6332u    /* 044332 */
#define sprite_list_044350_ADDRESS 0x6350u    /* 044350 */
#define sprite_list_04436E_ADDRESS 0x636Eu    /* 04436E */
#define sprite_list_04438C_ADDRESS 0x638Cu    /* 04438C */
#define animation_0443AA_ADDRESS 0x63AAu    /* 0443AA */
#define sprite_list_0443CE_ADDRESS 0x63CEu    /* 0443CE */
#define sprite_list_0443E6_ADDRESS 0x63E6u    /* 0443E6 */
#define sprite_list_0443FE_ADDRESS 0x63FEu    /* 0443FE */
#define sprite_list_044416_ADDRESS 0x6416u    /* 044416 */
#define sprite_list_04442E_ADDRESS 0x642Eu    /* 04442E */
#define sprite_list_044452_ADDRESS 0x6452u    /* 044452 */
#define sprite_list_044476_ADDRESS 0x6476u    /* 044476 */
#define sprite_list_04449A_ADDRESS 0x649Au    /* 04449A */
#define animation_0444A6_ADDRESS 0x64A6u    /* 0444A6 */
#define sprite_list_04450E_ADDRESS 0x650Eu    /* 04450E */
#define sprite_list_044532_ADDRESS 0x6532u    /* 044532 */
#define sprite_list_044550_ADDRESS 0x6550u    /* 044550 */
#define sprite_list_04456E_ADDRESS 0x656Eu    /* 04456E */
#define sprite_list_04458C_ADDRESS 0x658Cu    /* 04458C */
#define sprite_list_0445AA_ADDRESS 0x65AAu    /* 0445AA */
#define sprite_list_0445C8_ADDRESS 0x65C8u    /* 0445C8 */
#define sprite_list_0445E6_ADDRESS 0x65E6u    /* 0445E6 */
#define sprite_list_044604_ADDRESS 0x6604u    /* 044604 */
#define sprite_list_044628_ADDRESS 0x6628u    /* 044628 */
#define sprite_list_044646_ADDRESS 0x6646u    /* 044646 */
#define sprite_list_044664_ADDRESS 0x6664u    /* 044664 */
#define sprite_list_044682_ADDRESS 0x6682u    /* 044682 */
#define sprite_list_0446A0_ADDRESS 0x66A0u    /* 0446A0 */
#define sprite_list_0446BE_ADDRESS 0x66BEu    /* 0446BE */
#define sprite_list_0446DC_ADDRESS 0x66DCu    /* 0446DC */
#define sprite_list_0446FA_ADDRESS 0x66FAu    /* 0446FA */
#define sprite_list_04471E_ADDRESS 0x671Eu    /* 04471E */
#define sprite_list_04473C_ADDRESS 0x673Cu    /* 04473C */
#define sprite_list_04475A_ADDRESS 0x675Au    /* 04475A */
#define sprite_list_044778_ADDRESS 0x6778u    /* 044778 */
#define sprite_list_044796_ADDRESS 0x6796u    /* 044796 */
#define sprite_list_0447B4_ADDRESS 0x67B4u    /* 0447B4 */
#define sprite_list_0447D2_ADDRESS 0x67D2u    /* 0447D2 */
#define sprite_list_0447F0_ADDRESS 0x67F0u    /* 0447F0 */
#define animation_044814_ADDRESS 0x6814u    /* 044814 */
#define sprite_list_044838_ADDRESS 0x6838u    /* 044838 */
#define sprite_list_044856_ADDRESS 0x6856u    /* 044856 */
#define animation_044874_ADDRESS 0x6874u    /* 044874 */
#define sprite_list_0448AC_ADDRESS 0x68ACu    /* 0448AC */
#define sprite_list_0448CA_ADDRESS 0x68CAu    /* 0448CA */
#define sprite_list_0448E8_ADDRESS 0x68E8u    /* 0448E8 */
#define sprite_list_044906_ADDRESS 0x6906u    /* 044906 */
#define sprite_list_04492A_ADDRESS 0x692Au    /* 04492A */
#define sprite_list_044954_ADDRESS 0x6954u    /* 044954 */
#define sprite_list_044984_ADDRESS 0x6984u    /* 044984 */
#define animation_0449B4_ADDRESS 0x69B4u    /* 0449B4 */
#define sprite_list_0449C8_ADDRESS 0x69C8u    /* 0449C8 */
#define sprite_list_0449CE_ADDRESS 0x69CEu    /* 0449CE */
#define sprite_list_0449D4_ADDRESS 0x69D4u    /* 0449D4 */
#define sprite_list_0449DA_ADDRESS 0x69DAu    /* 0449DA */
#define animation_0449E0_ADDRESS 0x69E0u    /* 0449E0 */
#define sprite_list_0449F4_ADDRESS 0x69F4u    /* 0449F4 */
#define sprite_list_0449FA_ADDRESS 0x69FAu    /* 0449FA */
#define sprite_list_044A00_ADDRESS 0x6A00u    /* 044A00 */
#define sprite_list_044A06_ADDRESS 0x6A06u    /* 044A06 */
#define animation_044A0C_ADDRESS 0x6A0Cu    /* 044A0C */
#define sprite_list_044A20_ADDRESS 0x6A20u    /* 044A20 */
#define sprite_list_044A2C_ADDRESS 0x6A2Cu    /* 044A2C */
#define sprite_list_044A38_ADDRESS 0x6A38u    /* 044A38 */
#define sprite_list_044A44_ADDRESS 0x6A44u    /* 044A44 */
#define animation_table_044A50_ADDRESS 0x6A50u    /* 044A50 */
#define animation_044A80_ADDRESS 0x6A80u    /* 044A80 */
#define sprite_list_044A88_ADDRESS 0x6A88u    /* 044A88 */
#define animation_044AA0_ADDRESS 0x6AA0u    /* 044AA0 */
#define sprite_list_044AC4_ADDRESS 0x6AC4u    /* 044AC4 */
#define sprite_list_044AD6_ADDRESS 0x6AD6u    /* 044AD6 */
#define sprite_list_044AE8_ADDRESS 0x6AE8u    /* 044AE8 */
#define sprite_list_044AFA_ADDRESS 0x6AFAu    /* 044AFA */
#define sprite_list_044B0C_ADDRESS 0x6B0Cu    /* 044B0C */
#define sprite_list_044B24_ADDRESS 0x6B24u    /* 044B24 */
#define animation_044B3C_ADDRESS 0x6B3Cu    /* 044B3C */
#define sprite_list_044B5C_ADDRESS 0x6B5Cu    /* 044B5C */
#define sprite_list_044B74_ADDRESS 0x6B74u    /* 044B74 */
#define sprite_list_044B86_ADDRESS 0x6B86u    /* 044B86 */
#define sprite_list_044B98_ADDRESS 0x6B98u    /* 044B98 */
#define sprite_list_044BB0_ADDRESS 0x6BB0u    /* 044BB0 */
#define sprite_list_044BC8_ADDRESS 0x6BC8u    /* 044BC8 */
#define sprite_list_044BE0_ADDRESS 0x6BE0u    /* 044BE0 */
#define animation_044BF2_ADDRESS 0x6BF2u    /* 044BF2 */
#define sprite_list_044C06_ADDRESS 0x6C06u    /* 044C06 */
#define sprite_list_044C18_ADDRESS 0x6C18u    /* 044C18 */
#define sprite_list_044C36_ADDRESS 0x6C36u    /* 044C36 */
#define animation_044C54_ADDRESS 0x6C54u    /* 044C54 */
#define sprite_list_044C6C_ADDRESS 0x6C6Cu    /* 044C6C */
#define sprite_list_044C84_ADDRESS 0x6C84u    /* 044C84 */
#define sprite_list_044C9C_ADDRESS 0x6C9Cu    /* 044C9C */
#define sprite_list_044CB4_ADDRESS 0x6CB4u    /* 044CB4 */
#define sprite_list_044CCC_ADDRESS 0x6CCCu    /* 044CCC */
#define animation_044CEA_ADDRESS 0x6CEAu    /* 044CEA */
#define sprite_list_044D06_ADDRESS 0x6D06u    /* 044D06 */
#define animation_044D1E_ADDRESS 0x6D1Eu    /* 044D1E */
#define animation_044D2A_ADDRESS 0x6D2Au    /* 044D2A */
#define sprite_list_044D3E_ADDRESS 0x6D3Eu    /* 044D3E */
#define sprite_list_044D5C_ADDRESS 0x6D5Cu    /* 044D5C */
#define animation_044D74_ADDRESS 0x6D74u    /* 044D74 */
#define sprite_list_044DA0_ADDRESS 0x6DA0u    /* 044DA0 */
#define sprite_list_044DB2_ADDRESS 0x6DB2u    /* 044DB2 */
#define sprite_list_044DCA_ADDRESS 0x6DCAu    /* 044DCA */
#define sprite_list_044DDC_ADDRESS 0x6DDCu    /* 044DDC */
#define sprite_list_044DE8_ADDRESS 0x6DE8u    /* 044DE8 */
#define sprite_list_044DF4_ADDRESS 0x6DF4u    /* 044DF4 */
#define sprite_list_044E06_ADDRESS 0x6E06u    /* 044E06 */
#define sprite_list_044E18_ADDRESS 0x6E18u    /* 044E18 */
#define sprite_list_044E24_ADDRESS 0x6E24u    /* 044E24 */
#define sprite_list_044E2A_ADDRESS 0x6E2Au    /* 044E2A */
#define animation_044E30_ADDRESS 0x6E30u    /* 044E30 */
#define sprite_list_044E38_ADDRESS 0x6E38u    /* 044E38 */
#define animation_044E3E_ADDRESS 0x6E3Eu    /* 044E3E */
#define sprite_list_044E4E_ADDRESS 0x6E4Eu    /* 044E4E */
#define sprite_list_044E60_ADDRESS 0x6E60u    /* 044E60 */
#define sprite_list_044E6C_ADDRESS 0x6E6Cu    /* 044E6C */
#define animation_044E84_ADDRESS 0x6E84u    /* 044E84 */
#define sprite_list_044E94_ADDRESS 0x6E94u    /* 044E94 */
#define sprite_list_044EAC_ADDRESS 0x6EACu    /* 044EAC */
#define animation_044EC4_ADDRESS 0x6EC4u    /* 044EC4 */
#define sprite_list_044EE4_ADDRESS 0x6EE4u    /* 044EE4 */
#define sprite_list_044EFC_ADDRESS 0x6EFCu    /* 044EFC */
#define sprite_list_044F0E_ADDRESS 0x6F0Eu    /* 044F0E */
#define animation_044F26_ADDRESS 0x6F26u    /* 044F26 */
#define sprite_list_044F46_ADDRESS 0x6F46u    /* 044F46 */
#define sprite_list_044F4C_ADDRESS 0x6F4Cu    /* 044F4C */
#define sprite_list_044F52_ADDRESS 0x6F52u    /* 044F52 */
#define sprite_list_044F58_ADDRESS 0x6F58u    /* 044F58 */
#define sprite_list_044F64_ADDRESS 0x6F64u    /* 044F64 */
#define sprite_list_044F6A_ADDRESS 0x6F6Au    /* 044F6A */
#define sprite_list_044F94_ADDRESS 0x6F94u    /* 044F94 */
#define animation_044FB8_ADDRESS 0x6FB8u    /* 044FB8 */
#define animation_044FD8_ADDRESS 0x6FD8u    /* 044FD8 */
#define animation_table_044FF0_ADDRESS 0x6FF0u    /* 044FF0 */
#define animation_045024_ADDRESS 0x7024u    /* 045024 */
#define sprite_list_04502C_ADDRESS 0x702Cu    /* 04502C */
#define animation_045044_ADDRESS 0x7044u    /* 045044 */
#define sprite_list_045060_ADDRESS 0x7060u    /* 045060 */
#define sprite_list_045084_ADDRESS 0x7084u    /* 045084 */
#define sprite_list_0450A2_ADDRESS 0x70A2u    /* 0450A2 */
#define sprite_list_0450C0_ADDRESS 0x70C0u    /* 0450C0 */
#define animation_0450DE_ADDRESS 0x70DEu    /* 0450DE */
#define sprite_list_045122_ADDRESS 0x7122u    /* 045122 */
#define sprite_list_045146_ADDRESS 0x7146u    /* 045146 */
#define sprite_list_04516A_ADDRESS 0x716Au    /* 04516A */
#define sprite_list_04518E_ADDRESS 0x718Eu    /* 04518E */
#define sprite_list_0451B2_ADDRESS 0x71B2u    /* 0451B2 */
#define sprite_list_0451DC_ADDRESS 0x71DCu    /* 0451DC */
#define sprite_list_045206_ADDRESS 0x7206u    /* 045206 */
#define sprite_list_045224_ADDRESS 0x7224u    /* 045224 */
#define sprite_list_045248_ADDRESS 0x7248u    /* 045248 */
#define sprite_list_04526C_ADDRESS 0x726Cu    /* 04526C */
#define animation_045290_ADDRESS 0x7290u    /* 045290 */
#define sprite_list_0452B0_ADDRESS 0x72B0u    /* 0452B0 */
#define sprite_list_0452CE_ADDRESS 0x72CEu    /* 0452CE */
#define sprite_list_0452EC_ADDRESS 0x72ECu    /* 0452EC */
#define animation_04530A_ADDRESS 0x730Au    /* 04530A */
#define sprite_list_04531E_ADDRESS 0x731Eu    /* 04531E */
#define sprite_list_045330_ADDRESS 0x7330u    /* 045330 */
#define sprite_list_045354_ADDRESS 0x7354u    /* 045354 */
#define animation_045372_ADDRESS 0x7372u    /* 045372 */
#define sprite_list_04538E_ADDRESS 0x738Eu    /* 04538E */
#define sprite_list_0453AC_ADDRESS 0x73ACu    /* 0453AC */
#define sprite_list_0453CA_ADDRESS 0x73CAu    /* 0453CA */
#define sprite_list_0453E8_ADDRESS 0x73E8u    /* 0453E8 */
#define animation_045406_ADDRESS 0x7406u    /* 045406 */
#define sprite_list_045442_ADDRESS 0x7442u    /* 045442 */
#define sprite_list_045460_ADDRESS 0x7460u    /* 045460 */
#define sprite_list_045478_ADDRESS 0x7478u    /* 045478 */
#define sprite_list_045490_ADDRESS 0x7490u    /* 045490 */
#define sprite_list_0454A2_ADDRESS 0x74A2u    /* 0454A2 */
#define sprite_list_0454C0_ADDRESS 0x74C0u    /* 0454C0 */
#define sprite_list_0454DE_ADDRESS 0x74DEu    /* 0454DE */
#define sprite_list_0454FC_ADDRESS 0x74FCu    /* 0454FC */
#define sprite_list_045514_ADDRESS 0x7514u    /* 045514 */
#define sprite_list_045532_ADDRESS 0x7532u    /* 045532 */
#define animation_045544_ADDRESS 0x7544u    /* 045544 */
#define sprite_list_04554C_ADDRESS 0x754Cu    /* 04554C */
#define animation_045552_ADDRESS 0x7552u    /* 045552 */
#define sprite_list_04555A_ADDRESS 0x755Au    /* 04555A */
#define animation_045560_ADDRESS 0x7560u    /* 045560 */
#define sprite_list_045568_ADDRESS 0x7568u    /* 045568 */
#define animation_04556E_ADDRESS 0x756Eu    /* 04556E */
#define sprite_list_045576_ADDRESS 0x7576u    /* 045576 */
#define animation_04557C_ADDRESS 0x757Cu    /* 04557C */
#define sprite_list_0455AC_ADDRESS 0x75ACu    /* 0455AC */
#define sprite_list_0455D0_ADDRESS 0x75D0u    /* 0455D0 */
#define sprite_list_0455E8_ADDRESS 0x75E8u    /* 0455E8 */
#define sprite_list_04560C_ADDRESS 0x760Cu    /* 04560C */
#define sprite_list_045630_ADDRESS 0x7630u    /* 045630 */
#define sprite_list_04564E_ADDRESS 0x764Eu    /* 04564E */
#define animation_04566C_ADDRESS 0x766Cu    /* 04566C */
#define sprite_list_045680_ADDRESS 0x7680u    /* 045680 */
#define sprite_list_045698_ADDRESS 0x7698u    /* 045698 */
#define sprite_list_0456B0_ADDRESS 0x76B0u    /* 0456B0 */
#define animation_0456C8_ADDRESS 0x76C8u    /* 0456C8 */
#define sprite_list_0456E8_ADDRESS 0x76E8u    /* 0456E8 */
#define sprite_list_0456EE_ADDRESS 0x76EEu    /* 0456EE */
#define sprite_list_0456F4_ADDRESS 0x76F4u    /* 0456F4 */
#define sprite_list_0456FA_ADDRESS 0x76FAu    /* 0456FA */
#define sprite_list_045706_ADDRESS 0x7706u    /* 045706 */
#define sprite_list_04570C_ADDRESS 0x770Cu    /* 04570C */
#define sprite_list_045730_ADDRESS 0x7730u    /* 045730 */
#define animation_045754_ADDRESS 0x7754u    /* 045754 */
#define sprite_list_04575C_ADDRESS 0x775Cu    /* 04575C */
#define animation_045762_ADDRESS 0x7762u    /* 045762 */
#define sprite_list_04576A_ADDRESS 0x776Au    /* 04576A */
#define animation_table_045770_ADDRESS 0x7770u    /* 045770 */
#define animation_045780_ADDRESS 0x7780u    /* 045780 */
#define sprite_list_045794_ADDRESS 0x7794u    /* 045794 */
#define sprite_list_04579A_ADDRESS 0x779Au    /* 04579A */
#define sprite_list_0457A0_ADDRESS 0x77A0u    /* 0457A0 */
#define animation_0457A6_ADDRESS 0x77A6u    /* 0457A6 */
#define sprite_list_0457CA_ADDRESS 0x77CAu    /* 0457CA */
#define sprite_list_0457D0_ADDRESS 0x77D0u    /* 0457D0 */
#define sprite_list_0457DC_ADDRESS 0x77DCu    /* 0457DC */
#define sprite_list_0457E8_ADDRESS 0x77E8u    /* 0457E8 */
#define sprite_list_0457FA_ADDRESS 0x77FAu    /* 0457FA */
#define animation_045806_ADDRESS 0x7806u    /* 045806 */
#define sprite_list_04581A_ADDRESS 0x781Au    /* 04581A */
#define sprite_list_04582C_ADDRESS 0x782Cu    /* 04582C */
#define animation_04583E_ADDRESS 0x783Eu    /* 04583E */
#define sprite_list_045872_ADDRESS 0x7872u    /* 045872 */
#define sprite_list_045884_ADDRESS 0x7884u    /* 045884 */
#define sprite_list_045896_ADDRESS 0x7896u    /* 045896 */
#define sprite_list_0458A2_ADDRESS 0x78A2u    /* 0458A2 */
#define animation_0458AE_ADDRESS 0x78AEu    /* 0458AE */
#define sprite_list_0458D6_ADDRESS 0x78D6u    /* 0458D6 */
#define sprite_list_0458E2_ADDRESS 0x78E2u    /* 0458E2 */
#define sprite_list_0458F4_ADDRESS 0x78F4u    /* 0458F4 */
#define sprite_list_045906_ADDRESS 0x7906u    /* 045906 */
#define sprite_list_045912_ADDRESS 0x7912u    /* 045912 */
#define sprite_list_045924_ADDRESS 0x7924u    /* 045924 */
#define sprite_list_045936_ADDRESS 0x7936u    /* 045936 */
#define animation_04594E_ADDRESS 0x794Eu    /* 04594E */
#define sprite_list_04595E_ADDRESS 0x795Eu    /* 04595E */
#define sprite_list_04596A_ADDRESS 0x796Au    /* 04596A */
#define animation_045976_ADDRESS 0x7976u    /* 045976 */
#define sprite_list_045992_ADDRESS 0x7992u    /* 045992 */
#define sprite_list_045998_ADDRESS 0x7998u    /* 045998 */
#define sprite_list_04599E_ADDRESS 0x799Eu    /* 04599E */
#define animation_0459B6_ADDRESS 0x79B6u    /* 0459B6 */
#define fill_0459D6_ADDRESS 0x79D6u    /* 0459D6 */
#define unreached_animation_045A4C_ADDRESS 0x7A4Cu    /* 045A4C */
#define sprite_list_045A54_ADDRESS 0x7A54u    /* 045A54 */
#define fill_045A5A_ADDRESS 0x7A5Au    /* 045A5A */
#define unreached_animation_045A9A_ADDRESS 0x7A9Au    /* 045A9A */
#define sprite_list_045AA2_ADDRESS 0x7AA2u    /* 045AA2 */
#define fill_045AA8_ADDRESS 0x7AA8u    /* 045AA8 */
#define unreached_animation_045AC0_ADDRESS 0x7AC0u    /* 045AC0 */
#define sprite_list_045AC8_ADDRESS 0x7AC8u    /* 045AC8 */
#define fill_045ACE_ADDRESS 0x7ACEu    /* 045ACE */
#define unreached_animation_045ADA_ADDRESS 0x7ADAu    /* 045ADA */
#define sprite_list_045AE2_ADDRESS 0x7AE2u    /* 045AE2 */
#define unreached_animation_045AEE_ADDRESS 0x7AEEu    /* 045AEE */
#define sprite_list_045AF6_ADDRESS 0x7AF6u    /* 045AF6 */
#define unreached_animation_045B02_ADDRESS 0x7B02u    /* 045B02 */
#define sprite_list_045B0A_ADDRESS 0x7B0Au    /* 045B0A */
#define unreached_animation_045B16_ADDRESS 0x7B16u    /* 045B16 */
#define sprite_list_045B36_ADDRESS 0x7B36u    /* 045B36 */
#define sprite_list_045B42_ADDRESS 0x7B42u    /* 045B42 */
#define sprite_list_045B54_ADDRESS 0x7B54u    /* 045B54 */
#define sprite_list_045B7E_ADDRESS 0x7B7Eu    /* 045B7E */
#define sprite_list_045BA8_ADDRESS 0x7BA8u    /* 045BA8 */
#define sprite_list_045BC6_ADDRESS 0x7BC6u    /* 045BC6 */
#define sprite_list_045BE4_ADDRESS 0x7BE4u    /* 045BE4 */
#define fill_045BF0_ADDRESS 0x7BF0u    /* 045BF0 */
#define unreached_animation_045BF2_ADDRESS 0x7BF2u    /* 045BF2 */
#define sprite_list_045C02_ADDRESS 0x7C02u    /* 045C02 */
#define sprite_list_045C08_ADDRESS 0x7C08u    /* 045C08 */
#define sprite_list_045C0E_ADDRESS 0x7C0Eu    /* 045C0E */
#define fill_045C1A_ADDRESS 0x7C1Au    /* 045C1A */
#define unreached_animation_045D48_ADDRESS 0x7D48u    /* 045D48 */
#define sprite_list_045D64_ADDRESS 0x7D64u    /* 045D64 */
#define sprite_list_045D8E_ADDRESS 0x7D8Eu    /* 045D8E */
#define sprite_list_045DBE_ADDRESS 0x7DBEu    /* 045DBE */
#define sprite_list_045DF4_ADDRESS 0x7DF4u    /* 045DF4 */
#define sprite_list_045E30_ADDRESS 0x7E30u    /* 045E30 */
#define sprite_list_045E78_ADDRESS 0x7E78u    /* 045E78 */
#define fill_045ECC_ADDRESS 0x7ECCu    /* 045ECC */
#define set_index_046000_ADDRESS 0x6000u    /* 046000 */
#define animation_table_046008_ADDRESS 0x6008u    /* 046008 */
#define animation_046080_ADDRESS 0x6080u    /* 046080 */
#define sprite_list_046088_ADDRESS 0x6088u    /* 046088 */
#define animation_04608E_ADDRESS 0x608Eu    /* 04608E */
#define sprite_list_0460B2_ADDRESS 0x60B2u    /* 0460B2 */
#define sprite_list_0460CA_ADDRESS 0x60CAu    /* 0460CA */
#define sprite_list_0460DC_ADDRESS 0x60DCu    /* 0460DC */
#define sprite_list_0460EE_ADDRESS 0x60EEu    /* 0460EE */
#define sprite_list_046100_ADDRESS 0x6100u    /* 046100 */
#define sprite_list_046112_ADDRESS 0x6112u    /* 046112 */
#define sprite_list_046124_ADDRESS 0x6124u    /* 046124 */
#define sprite_list_046136_ADDRESS 0x6136u    /* 046136 */
#define animation_046148_ADDRESS 0x6148u    /* 046148 */
#define sprite_list_04616C_ADDRESS 0x616Cu    /* 04616C */
#define sprite_list_04617E_ADDRESS 0x617Eu    /* 04617E */
#define sprite_list_04618A_ADDRESS 0x618Au    /* 04618A */
#define sprite_list_04619C_ADDRESS 0x619Cu    /* 04619C */
#define sprite_list_0461A8_ADDRESS 0x61A8u    /* 0461A8 */
#define sprite_list_0461BA_ADDRESS 0x61BAu    /* 0461BA */
#define sprite_list_0461CC_ADDRESS 0x61CCu    /* 0461CC */
#define sprite_list_0461E4_ADDRESS 0x61E4u    /* 0461E4 */
#define animation_0461F6_ADDRESS 0x61F6u    /* 0461F6 */
#define sprite_list_04621A_ADDRESS 0x621Au    /* 04621A */
#define sprite_list_04622C_ADDRESS 0x622Cu    /* 04622C */
#define sprite_list_04623E_ADDRESS 0x623Eu    /* 04623E */
#define sprite_list_046250_ADDRESS 0x6250u    /* 046250 */
#define sprite_list_046262_ADDRESS 0x6262u    /* 046262 */
#define sprite_list_046274_ADDRESS 0x6274u    /* 046274 */
#define sprite_list_046286_ADDRESS 0x6286u    /* 046286 */
#define sprite_list_046298_ADDRESS 0x6298u    /* 046298 */
#define animation_0462AA_ADDRESS 0x62AAu    /* 0462AA */
#define sprite_list_0462B6_ADDRESS 0x62B6u    /* 0462B6 */
#define sprite_list_0462BC_ADDRESS 0x62BCu    /* 0462BC */
#define animation_0462C2_ADDRESS 0x62C2u    /* 0462C2 */
#define sprite_list_0462CE_ADDRESS 0x62CEu    /* 0462CE */
#define sprite_list_0462D4_ADDRESS 0x62D4u    /* 0462D4 */
#define animation_0462DA_ADDRESS 0x62DAu    /* 0462DA */
#define sprite_list_0462E6_ADDRESS 0x62E6u    /* 0462E6 */
#define sprite_list_0462F8_ADDRESS 0x62F8u    /* 0462F8 */
#define animation_04630A_ADDRESS 0x630Au    /* 04630A */
#define sprite_list_046316_ADDRESS 0x6316u    /* 046316 */
#define sprite_list_046328_ADDRESS 0x6328u    /* 046328 */
#define animation_046340_ADDRESS 0x6340u    /* 046340 */
#define sprite_list_046358_ADDRESS 0x6358u    /* 046358 */
#define sprite_list_04636A_ADDRESS 0x636Au    /* 04636A */
#define sprite_list_04637C_ADDRESS 0x637Cu    /* 04637C */
#define sprite_list_04638E_ADDRESS 0x638Eu    /* 04638E */
#define sprite_list_04639A_ADDRESS 0x639Au    /* 04639A */
#define animation_0463A6_ADDRESS 0x63A6u    /* 0463A6 */
#define sprite_list_0463BA_ADDRESS 0x63BAu    /* 0463BA */
#define sprite_list_0463C0_ADDRESS 0x63C0u    /* 0463C0 */
#define sprite_list_0463C6_ADDRESS 0x63C6u    /* 0463C6 */
#define animation_0463CC_ADDRESS 0x63CCu    /* 0463CC */
#define sprite_list_0463E4_ADDRESS 0x63E4u    /* 0463E4 */
#define sprite_list_0463F0_ADDRESS 0x63F0u    /* 0463F0 */
#define sprite_list_046402_ADDRESS 0x6402u    /* 046402 */
#define animation_04641A_ADDRESS 0x641Au    /* 04641A */
#define sprite_list_04642E_ADDRESS 0x642Eu    /* 04642E */
#define sprite_list_046434_ADDRESS 0x6434u    /* 046434 */
#define sprite_list_04643A_ADDRESS 0x643Au    /* 04643A */
#define sprite_list_046440_ADDRESS 0x6440u    /* 046440 */
#define animation_046446_ADDRESS 0x6446u    /* 046446 */
#define sprite_list_046462_ADDRESS 0x6462u    /* 046462 */
#define sprite_list_046474_ADDRESS 0x6474u    /* 046474 */
#define sprite_list_04647A_ADDRESS 0x647Au    /* 04647A */
#define sprite_list_046480_ADDRESS 0x6480u    /* 046480 */
#define sprite_list_046486_ADDRESS 0x6486u    /* 046486 */
#define sprite_list_046498_ADDRESS 0x6498u    /* 046498 */
#define animation_0464B0_ADDRESS 0x64B0u    /* 0464B0 */
#define sprite_list_0464BC_ADDRESS 0x64BCu    /* 0464BC */
#define sprite_list_0464C2_ADDRESS 0x64C2u    /* 0464C2 */
#define animation_0464CE_ADDRESS 0x64CEu    /* 0464CE */
#define sprite_list_0464EE_ADDRESS 0x64EEu    /* 0464EE */
#define sprite_list_0464F4_ADDRESS 0x64F4u    /* 0464F4 */
#define sprite_list_0464FA_ADDRESS 0x64FAu    /* 0464FA */
#define sprite_list_046506_ADDRESS 0x6506u    /* 046506 */
#define sprite_list_04650C_ADDRESS 0x650Cu    /* 04650C */
#define animation_046512_ADDRESS 0x6512u    /* 046512 */
#define sprite_list_046526_ADDRESS 0x6526u    /* 046526 */
#define sprite_list_04653E_ADDRESS 0x653Eu    /* 04653E */
#define sprite_list_046556_ADDRESS 0x6556u    /* 046556 */
#define sprite_list_046568_ADDRESS 0x6568u    /* 046568 */
#define animation_04657A_ADDRESS 0x657Au    /* 04657A */
#define sprite_list_04659E_ADDRESS 0x659Eu    /* 04659E */
#define sprite_list_0465B0_ADDRESS 0x65B0u    /* 0465B0 */
#define sprite_list_0465C2_ADDRESS 0x65C2u    /* 0465C2 */
#define sprite_list_0465D4_ADDRESS 0x65D4u    /* 0465D4 */
#define sprite_list_0465E0_ADDRESS 0x65E0u    /* 0465E0 */
#define sprite_list_0465F2_ADDRESS 0x65F2u    /* 0465F2 */
#define sprite_list_046604_ADDRESS 0x6604u    /* 046604 */
#define sprite_list_04661C_ADDRESS 0x661Cu    /* 04661C */
#define animation_046634_ADDRESS 0x6634u    /* 046634 */
#define sprite_list_046658_ADDRESS 0x6658u    /* 046658 */
#define sprite_list_04665E_ADDRESS 0x665Eu    /* 04665E */
#define sprite_list_046664_ADDRESS 0x6664u    /* 046664 */
#define sprite_list_04666A_ADDRESS 0x666Au    /* 04666A */
#define sprite_list_046670_ADDRESS 0x6670u    /* 046670 */
#define sprite_list_046676_ADDRESS 0x6676u    /* 046676 */
#define sprite_list_04667C_ADDRESS 0x667Cu    /* 04667C */
#define sprite_list_046682_ADDRESS 0x6682u    /* 046682 */
#define animation_046688_ADDRESS 0x6688u    /* 046688 */
#define sprite_list_0466A0_ADDRESS 0x66A0u    /* 0466A0 */
#define sprite_list_0466B2_ADDRESS 0x66B2u    /* 0466B2 */
#define sprite_list_0466CA_ADDRESS 0x66CAu    /* 0466CA */
#define animation_0466DC_ADDRESS 0x66DCu    /* 0466DC */
#define sprite_list_0466F4_ADDRESS 0x66F4u    /* 0466F4 */
#define sprite_list_046706_ADDRESS 0x6706u    /* 046706 */
#define sprite_list_046718_ADDRESS 0x6718u    /* 046718 */
#define animation_04672A_ADDRESS 0x672Au    /* 04672A */
#define sprite_list_04673E_ADDRESS 0x673Eu    /* 04673E */
#define animation_046750_ADDRESS 0x6750u    /* 046750 */
#define sprite_list_046760_ADDRESS 0x6760u    /* 046760 */
#define sprite_list_046766_ADDRESS 0x6766u    /* 046766 */
#define animation_04676C_ADDRESS 0x676Cu    /* 04676C */
#define sprite_list_04677C_ADDRESS 0x677Cu    /* 04677C */
#define sprite_list_046782_ADDRESS 0x6782u    /* 046782 */
#define sprite_list_046788_ADDRESS 0x6788u    /* 046788 */
#define animation_04678E_ADDRESS 0x678Eu    /* 04678E */
#define sprite_list_0467AA_ADDRESS 0x67AAu    /* 0467AA */
#define sprite_list_0467C2_ADDRESS 0x67C2u    /* 0467C2 */
#define sprite_list_0467D4_ADDRESS 0x67D4u    /* 0467D4 */
#define sprite_list_0467E0_ADDRESS 0x67E0u    /* 0467E0 */
#define sprite_list_0467F2_ADDRESS 0x67F2u    /* 0467F2 */
#define animation_046804_ADDRESS 0x6804u    /* 046804 */
#define sprite_list_046818_ADDRESS 0x6818u    /* 046818 */
#define sprite_list_04681E_ADDRESS 0x681Eu    /* 04681E */
#define sprite_list_046830_ADDRESS 0x6830u    /* 046830 */
#define animation_04683C_ADDRESS 0x683Cu    /* 04683C */
#define sprite_list_046848_ADDRESS 0x6848u    /* 046848 */
#define sprite_list_046860_ADDRESS 0x6860u    /* 046860 */
#define animation_046872_ADDRESS 0x6872u    /* 046872 */
#define sprite_list_046896_ADDRESS 0x6896u    /* 046896 */
#define sprite_list_0468A8_ADDRESS 0x68A8u    /* 0468A8 */
#define sprite_list_0468BA_ADDRESS 0x68BAu    /* 0468BA */
#define sprite_list_0468D2_ADDRESS 0x68D2u    /* 0468D2 */
#define sprite_list_0468F0_ADDRESS 0x68F0u    /* 0468F0 */
#define sprite_list_046908_ADDRESS 0x6908u    /* 046908 */
#define sprite_list_046920_ADDRESS 0x6920u    /* 046920 */
#define sprite_list_046938_ADDRESS 0x6938u    /* 046938 */
#define animation_046950_ADDRESS 0x6950u    /* 046950 */
#define sprite_list_046960_ADDRESS 0x6960u    /* 046960 */
#define sprite_list_046978_ADDRESS 0x6978u    /* 046978 */
#define sprite_list_04698A_ADDRESS 0x698Au    /* 04698A */
#define animation_04699C_ADDRESS 0x699Cu    /* 04699C */
#define sprite_list_0469B0_ADDRESS 0x69B0u    /* 0469B0 */
#define sprite_list_0469C2_ADDRESS 0x69C2u    /* 0469C2 */
#define sprite_list_0469C8_ADDRESS 0x69C8u    /* 0469C8 */
#define animation_0469D4_ADDRESS 0x69D4u    /* 0469D4 */
#define sprite_list_0469DC_ADDRESS 0x69DCu    /* 0469DC */
#define animation_0469E2_ADDRESS 0x69E2u    /* 0469E2 */
#define sprite_list_0469F2_ADDRESS 0x69F2u    /* 0469F2 */
#define sprite_list_0469F8_ADDRESS 0x69F8u    /* 0469F8 */
#define animation_0469FE_ADDRESS 0x69FEu    /* 0469FE */
#define sprite_list_046A1E_ADDRESS 0x6A1Eu    /* 046A1E */
#define sprite_list_046A24_ADDRESS 0x6A24u    /* 046A24 */
#define sprite_list_046A3C_ADDRESS 0x6A3Cu    /* 046A3C */
#define sprite_list_046A4E_ADDRESS 0x6A4Eu    /* 046A4E */
#define sprite_list_046A60_ADDRESS 0x6A60u    /* 046A60 */
#define sprite_list_046A66_ADDRESS 0x6A66u    /* 046A66 */
#define animation_046A6C_ADDRESS 0x6A6Cu    /* 046A6C */
#define sprite_list_046A80_ADDRESS 0x6A80u    /* 046A80 */
#define sprite_list_046AA4_ADDRESS 0x6AA4u    /* 046AA4 */
#define sprite_list_046AC8_ADDRESS 0x6AC8u    /* 046AC8 */
#define animation_046AF8_ADDRESS 0x6AF8u    /* 046AF8 */
#define sprite_list_046B08_ADDRESS 0x6B08u    /* 046B08 */
#define sprite_list_046B14_ADDRESS 0x6B14u    /* 046B14 */
#define sprite_list_046B20_ADDRESS 0x6B20u    /* 046B20 */
#define animation_046B32_ADDRESS 0x6B32u    /* 046B32 */
#define sprite_list_046B42_ADDRESS 0x6B42u    /* 046B42 */
#define sprite_list_046B54_ADDRESS 0x6B54u    /* 046B54 */
#define animation_046B66_ADDRESS 0x6B66u    /* 046B66 */
#define sprite_list_046B7A_ADDRESS 0x6B7Au    /* 046B7A */
#define sprite_list_046B86_ADDRESS 0x6B86u    /* 046B86 */
#define sprite_list_046B92_ADDRESS 0x6B92u    /* 046B92 */
#define animation_046BA4_ADDRESS 0x6BA4u    /* 046BA4 */
#define sprite_list_046BB4_ADDRESS 0x6BB4u    /* 046BB4 */
#define sprite_list_046BBA_ADDRESS 0x6BBAu    /* 046BBA */
#define sprite_list_046BC0_ADDRESS 0x6BC0u    /* 046BC0 */
#define animation_046BC6_ADDRESS 0x6BC6u    /* 046BC6 */
#define sprite_list_046BCE_ADDRESS 0x6BCEu    /* 046BCE */
#define animation_046BD4_ADDRESS 0x6BD4u    /* 046BD4 */
#define sprite_list_046BFC_ADDRESS 0x6BFCu    /* 046BFC */
#define sprite_list_046C0E_ADDRESS 0x6C0Eu    /* 046C0E */
#define sprite_list_046C14_ADDRESS 0x6C14u    /* 046C14 */
#define sprite_list_046C20_ADDRESS 0x6C20u    /* 046C20 */
#define sprite_list_046C32_ADDRESS 0x6C32u    /* 046C32 */
#define sprite_list_046C44_ADDRESS 0x6C44u    /* 046C44 */
#define sprite_list_046C5C_ADDRESS 0x6C5Cu    /* 046C5C */
#define sprite_list_046C68_ADDRESS 0x6C68u    /* 046C68 */
#define animation_046C7A_ADDRESS 0x6C7Au    /* 046C7A */
#define sprite_list_046C9A_ADDRESS 0x6C9Au    /* 046C9A */
#define sprite_list_046CA0_ADDRESS 0x6CA0u    /* 046CA0 */
#define sprite_list_046CAC_ADDRESS 0x6CACu    /* 046CAC */
#define animation_046CB8_ADDRESS 0x6CB8u    /* 046CB8 */
#define sprite_list_046CC8_ADDRESS 0x6CC8u    /* 046CC8 */
#define sprite_list_046CDA_ADDRESS 0x6CDAu    /* 046CDA */
#define sprite_list_046CF2_ADDRESS 0x6CF2u    /* 046CF2 */
#define animation_046D0A_ADDRESS 0x6D0Au    /* 046D0A */
#define sprite_list_046D1E_ADDRESS 0x6D1Eu    /* 046D1E */
#define sprite_list_046D36_ADDRESS 0x6D36u    /* 046D36 */
#define sprite_list_046D4E_ADDRESS 0x6D4Eu    /* 046D4E */
#define animation_046D72_ADDRESS 0x6D72u    /* 046D72 */
#define sprite_list_046D82_ADDRESS 0x6D82u    /* 046D82 */
#define sprite_list_046D9A_ADDRESS 0x6D9Au    /* 046D9A */
#define sprite_list_046DBE_ADDRESS 0x6DBEu    /* 046DBE */
#define animation_046DE8_ADDRESS 0x6DE8u    /* 046DE8 */
#define sprite_list_046DF8_ADDRESS 0x6DF8u    /* 046DF8 */
#define sprite_list_046E04_ADDRESS 0x6E04u    /* 046E04 */
#define sprite_list_046E10_ADDRESS 0x6E10u    /* 046E10 */
#define animation_046E1C_ADDRESS 0x6E1Cu    /* 046E1C */
#define sprite_list_046E2C_ADDRESS 0x6E2Cu    /* 046E2C */
#define sprite_list_046E38_ADDRESS 0x6E38u    /* 046E38 */
#define sprite_list_046E44_ADDRESS 0x6E44u    /* 046E44 */
#define animation_046E56_ADDRESS 0x6E56u    /* 046E56 */
#define sprite_list_046E6A_ADDRESS 0x6E6Au    /* 046E6A */
#define sprite_list_046E88_ADDRESS 0x6E88u    /* 046E88 */
#define sprite_list_046EB2_ADDRESS 0x6EB2u    /* 046EB2 */
#define animation_046EE2_ADDRESS 0x6EE2u    /* 046EE2 */
#define sprite_list_046EFA_ADDRESS 0x6EFAu    /* 046EFA */
#define sprite_list_046F0C_ADDRESS 0x6F0Cu    /* 046F0C */
#define sprite_list_046F12_ADDRESS 0x6F12u    /* 046F12 */
#define sprite_list_046F18_ADDRESS 0x6F18u    /* 046F18 */
#define sprite_list_046F1E_ADDRESS 0x6F1Eu    /* 046F1E */
#define animation_046F2A_ADDRESS 0x6F2Au    /* 046F2A */
#define animation_046F36_ADDRESS 0x6F36u    /* 046F36 */
#define animation_table_046F42_ADDRESS 0x6F42u    /* 046F42 */
#define animation_046F8C_ADDRESS 0x6F8Cu    /* 046F8C */
#define sprite_list_046F94_ADDRESS 0x6F94u    /* 046F94 */
#define animation_046FAC_ADDRESS 0x6FACu    /* 046FAC */
#define sprite_list_046FD0_ADDRESS 0x6FD0u    /* 046FD0 */
#define sprite_list_046FE8_ADDRESS 0x6FE8u    /* 046FE8 */
#define sprite_list_047000_ADDRESS 0x7000u    /* 047000 */
#define sprite_list_047018_ADDRESS 0x7018u    /* 047018 */
#define sprite_list_047030_ADDRESS 0x7030u    /* 047030 */
#define sprite_list_04704E_ADDRESS 0x704Eu    /* 04704E */
#define sprite_list_04706C_ADDRESS 0x706Cu    /* 04706C */
#define sprite_list_04708A_ADDRESS 0x708Au    /* 04708A */
#define animation_0470A8_ADDRESS 0x70A8u    /* 0470A8 */
#define sprite_list_0470CC_ADDRESS 0x70CCu    /* 0470CC */
#define sprite_list_0470E4_ADDRESS 0x70E4u    /* 0470E4 */
#define sprite_list_0470FC_ADDRESS 0x70FCu    /* 0470FC */
#define sprite_list_047114_ADDRESS 0x7114u    /* 047114 */
#define sprite_list_04712C_ADDRESS 0x712Cu    /* 04712C */
#define sprite_list_04714A_ADDRESS 0x714Au    /* 04714A */
#define sprite_list_047168_ADDRESS 0x7168u    /* 047168 */
#define sprite_list_047186_ADDRESS 0x7186u    /* 047186 */
#define animation_0471A4_ADDRESS 0x71A4u    /* 0471A4 */
#define sprite_list_0471C8_ADDRESS 0x71C8u    /* 0471C8 */
#define sprite_list_0471DA_ADDRESS 0x71DAu    /* 0471DA */
#define sprite_list_0471EC_ADDRESS 0x71ECu    /* 0471EC */
#define sprite_list_0471FE_ADDRESS 0x71FEu    /* 0471FE */
#define sprite_list_047210_ADDRESS 0x7210u    /* 047210 */
#define sprite_list_047222_ADDRESS 0x7222u    /* 047222 */
#define sprite_list_047234_ADDRESS 0x7234u    /* 047234 */
#define sprite_list_047246_ADDRESS 0x7246u    /* 047246 */
#define animation_047258_ADDRESS 0x7258u    /* 047258 */
#define sprite_list_047268_ADDRESS 0x7268u    /* 047268 */
#define sprite_list_047274_ADDRESS 0x7274u    /* 047274 */
#define sprite_list_047280_ADDRESS 0x7280u    /* 047280 */
#define animation_047292_ADDRESS 0x7292u    /* 047292 */
#define sprite_list_0472A2_ADDRESS 0x72A2u    /* 0472A2 */
#define sprite_list_0472B4_ADDRESS 0x72B4u    /* 0472B4 */
#define sprite_list_0472C6_ADDRESS 0x72C6u    /* 0472C6 */
#define animation_0472DE_ADDRESS 0x72DEu    /* 0472DE */
#define sprite_list_0472EA_ADDRESS 0x72EAu    /* 0472EA */
#define sprite_list_047308_ADDRESS 0x7308u    /* 047308 */
#define animation_047326_ADDRESS 0x7326u    /* 047326 */
#define sprite_list_047332_ADDRESS 0x7332u    /* 047332 */
#define sprite_list_047350_ADDRESS 0x7350u    /* 047350 */
#define animation_047374_ADDRESS 0x7374u    /* 047374 */
#define sprite_list_047388_ADDRESS 0x7388u    /* 047388 */
#define sprite_list_04739A_ADDRESS 0x739Au    /* 04739A */
#define sprite_list_0473AC_ADDRESS 0x73ACu    /* 0473AC */
#define animation_0473BE_ADDRESS 0x73BEu    /* 0473BE */
#define sprite_list_0473D6_ADDRESS 0x73D6u    /* 0473D6 */
#define sprite_list_0473EE_ADDRESS 0x73EEu    /* 0473EE */
#define sprite_list_04740C_ADDRESS 0x740Cu    /* 04740C */
#define animation_04742A_ADDRESS 0x742Au    /* 04742A */
#define sprite_list_04743E_ADDRESS 0x743Eu    /* 04743E */
#define sprite_list_047450_ADDRESS 0x7450u    /* 047450 */
#define sprite_list_04745C_ADDRESS 0x745Cu    /* 04745C */
#define sprite_list_047468_ADDRESS 0x7468u    /* 047468 */
#define animation_04747A_ADDRESS 0x747Au    /* 04747A */
#define sprite_list_04749A_ADDRESS 0x749Au    /* 04749A */
#define sprite_list_0474B2_ADDRESS 0x74B2u    /* 0474B2 */
#define sprite_list_0474BE_ADDRESS 0x74BEu    /* 0474BE */
#define sprite_list_0474CA_ADDRESS 0x74CAu    /* 0474CA */
#define sprite_list_0474DC_ADDRESS 0x74DCu    /* 0474DC */
#define sprite_list_0474E8_ADDRESS 0x74E8u    /* 0474E8 */
#define animation_0474F4_ADDRESS 0x74F4u    /* 0474F4 */
#define sprite_list_047500_ADDRESS 0x7500u    /* 047500 */
#define sprite_list_04750C_ADDRESS 0x750Cu    /* 04750C */
#define animation_04751E_ADDRESS 0x751Eu    /* 04751E */
#define sprite_list_047536_ADDRESS 0x7536u    /* 047536 */
#define sprite_list_047542_ADDRESS 0x7542u    /* 047542 */
#define sprite_list_04754E_ADDRESS 0x754Eu    /* 04754E */
#define sprite_list_04755A_ADDRESS 0x755Au    /* 04755A */
#define sprite_list_047572_ADDRESS 0x7572u    /* 047572 */
#define animation_047590_ADDRESS 0x7590u    /* 047590 */
#define sprite_list_0475A4_ADDRESS 0x75A4u    /* 0475A4 */
#define sprite_list_0475C2_ADDRESS 0x75C2u    /* 0475C2 */
#define sprite_list_0475E0_ADDRESS 0x75E0u    /* 0475E0 */
#define sprite_list_0475F8_ADDRESS 0x75F8u    /* 0475F8 */
#define animation_047610_ADDRESS 0x7610u    /* 047610 */
#define sprite_list_047634_ADDRESS 0x7634u    /* 047634 */
#define sprite_list_047646_ADDRESS 0x7646u    /* 047646 */
#define sprite_list_047658_ADDRESS 0x7658u    /* 047658 */
#define sprite_list_04766A_ADDRESS 0x766Au    /* 04766A */
#define sprite_list_04767C_ADDRESS 0x767Cu    /* 04767C */
#define sprite_list_047694_ADDRESS 0x7694u    /* 047694 */
#define sprite_list_0476AC_ADDRESS 0x76ACu    /* 0476AC */
#define sprite_list_0476C4_ADDRESS 0x76C4u    /* 0476C4 */
#define animation_0476DC_ADDRESS 0x76DCu    /* 0476DC */
#define sprite_list_0476EC_ADDRESS 0x76ECu    /* 0476EC */
#define sprite_list_04770A_ADDRESS 0x770Au    /* 04770A */
#define sprite_list_047728_ADDRESS 0x7728u    /* 047728 */
#define animation_047746_ADDRESS 0x7746u    /* 047746 */
#define sprite_list_04775A_ADDRESS 0x775Au    /* 04775A */
#define sprite_list_047778_ADDRESS 0x7778u    /* 047778 */
#define sprite_list_047796_ADDRESS 0x7796u    /* 047796 */
#define animation_0477B4_ADDRESS 0x77B4u    /* 0477B4 */
#define sprite_list_0477E0_ADDRESS 0x77E0u    /* 0477E0 */
#define sprite_list_0477EC_ADDRESS 0x77ECu    /* 0477EC */
#define sprite_list_0477FE_ADDRESS 0x77FEu    /* 0477FE */
#define sprite_list_047816_ADDRESS 0x7816u    /* 047816 */
#define sprite_list_04782E_ADDRESS 0x782Eu    /* 04782E */
#define sprite_list_047840_ADDRESS 0x7840u    /* 047840 */
#define sprite_list_04784C_ADDRESS 0x784Cu    /* 04784C */
#define sprite_list_047864_ADDRESS 0x7864u    /* 047864 */
#define animation_047870_ADDRESS 0x7870u    /* 047870 */
#define sprite_list_047878_ADDRESS 0x7878u    /* 047878 */
#define animation_table_04788A_ADDRESS 0x788Au    /* 04788A */
#define animation_047890_ADDRESS 0x7890u    /* 047890 */
#define sprite_list_04789C_ADDRESS 0x789Cu    /* 04789C */
#define sprite_list_0478A8_ADDRESS 0x78A8u    /* 0478A8 */
#define animation_0478B4_ADDRESS 0x78B4u    /* 0478B4 */
#define sprite_list_0478C8_ADDRESS 0x78C8u    /* 0478C8 */
#define sprite_list_0478D4_ADDRESS 0x78D4u    /* 0478D4 */
#define animation_0478E0_ADDRESS 0x78E0u    /* 0478E0 */
#define sprite_list_0478E8_ADDRESS 0x78E8u    /* 0478E8 */
#define animation_table_0478FA_ADDRESS 0x78FAu    /* 0478FA */
#define animation_047900_ADDRESS 0x7900u    /* 047900 */
#define sprite_list_047908_ADDRESS 0x7908u    /* 047908 */
#define animation_04793E_ADDRESS 0x793Eu    /* 04793E */
#define sprite_list_047946_ADDRESS 0x7946u    /* 047946 */
#define animation_04794C_ADDRESS 0x794Cu    /* 04794C */
#define sprite_list_047954_ADDRESS 0x7954u    /* 047954 */
#define fill_04795A_ADDRESS 0x795Au    /* 04795A */
#define unreached_animation_04796C_ADDRESS 0x796Cu    /* 04796C */
#define sprite_list_047980_ADDRESS 0x7980u    /* 047980 */
#define sprite_list_04799E_ADDRESS 0x799Eu    /* 04799E */
#define sprite_list_0479B6_ADDRESS 0x79B6u    /* 0479B6 */
#define sprite_list_0479D4_ADDRESS 0x79D4u    /* 0479D4 */
#define fill_0479EC_ADDRESS 0x79ECu    /* 0479EC */
#define unreached_animation_047A14_ADDRESS 0x7A14u    /* 047A14 */
#define sprite_list_047A1C_ADDRESS 0x7A1Cu    /* 047A1C */
#define unreached_animation_047A2E_ADDRESS 0x7A2Eu    /* 047A2E */
#define sprite_list_047A36_ADDRESS 0x7A36u    /* 047A36 */
#define unreached_animation_047A48_ADDRESS 0x7A48u    /* 047A48 */
#define sprite_list_047A50_ADDRESS 0x7A50u    /* 047A50 */
#define unreached_animation_047A62_ADDRESS 0x7A62u    /* 047A62 */
#define sprite_list_047A6A_ADDRESS 0x7A6Au    /* 047A6A */
#define unreached_animation_047A7C_ADDRESS 0x7A7Cu    /* 047A7C */
#define sprite_list_047A84_ADDRESS 0x7A84u    /* 047A84 */
#define unreached_animation_047A96_ADDRESS 0x7A96u    /* 047A96 */
#define sprite_list_047A9E_ADDRESS 0x7A9Eu    /* 047A9E */
#define unreached_animation_047AB0_ADDRESS 0x7AB0u    /* 047AB0 */
#define sprite_list_047AB8_ADDRESS 0x7AB8u    /* 047AB8 */
#define unreached_animation_047ACA_ADDRESS 0x7ACAu    /* 047ACA */
#define sprite_list_047AD2_ADDRESS 0x7AD2u    /* 047AD2 */
#define unreached_animation_047AE4_ADDRESS 0x7AE4u    /* 047AE4 */
#define sprite_list_047AEC_ADDRESS 0x7AECu    /* 047AEC */
#define unreached_animation_047AFE_ADDRESS 0x7AFEu    /* 047AFE */
#define sprite_list_047B06_ADDRESS 0x7B06u    /* 047B06 */
#define unreached_animation_047B18_ADDRESS 0x7B18u    /* 047B18 */
#define sprite_list_047B20_ADDRESS 0x7B20u    /* 047B20 */
#define unreached_animation_047B32_ADDRESS 0x7B32u    /* 047B32 */
#define sprite_list_047B3A_ADDRESS 0x7B3Au    /* 047B3A */
#define unreached_animation_047B4C_ADDRESS 0x7B4Cu    /* 047B4C */
#define sprite_list_047B54_ADDRESS 0x7B54u    /* 047B54 */
#define unreached_animation_047B66_ADDRESS 0x7B66u    /* 047B66 */
#define sprite_list_047B6E_ADDRESS 0x7B6Eu    /* 047B6E */
#define unreached_animation_047B80_ADDRESS 0x7B80u    /* 047B80 */
#define sprite_list_047B88_ADDRESS 0x7B88u    /* 047B88 */
#define unreached_animation_047B9A_ADDRESS 0x7B9Au    /* 047B9A */
#define sprite_list_047BA2_ADDRESS 0x7BA2u    /* 047BA2 */
#define unreached_animation_047BB4_ADDRESS 0x7BB4u    /* 047BB4 */
#define sprite_list_047BBC_ADDRESS 0x7BBCu    /* 047BBC */
#define unreached_animation_047BCE_ADDRESS 0x7BCEu    /* 047BCE */
#define sprite_list_047BD6_ADDRESS 0x7BD6u    /* 047BD6 */
#define unreached_animation_047BE8_ADDRESS 0x7BE8u    /* 047BE8 */
#define sprite_list_047BF0_ADDRESS 0x7BF0u    /* 047BF0 */
#define unreached_animation_047C08_ADDRESS 0x7C08u    /* 047C08 */
#define sprite_list_047C10_ADDRESS 0x7C10u    /* 047C10 */
#define fill_047C28_ADDRESS 0x7C28u    /* 047C28 */
#define unreached_animation_047D48_ADDRESS 0x7D48u    /* 047D48 */
#define sprite_list_047D64_ADDRESS 0x7D64u    /* 047D64 */
#define sprite_list_047D8E_ADDRESS 0x7D8Eu    /* 047D8E */
#define sprite_list_047DBE_ADDRESS 0x7DBEu    /* 047DBE */
#define sprite_list_047DF4_ADDRESS 0x7DF4u    /* 047DF4 */
#define sprite_list_047E30_ADDRESS 0x7E30u    /* 047E30 */
#define sprite_list_047E78_ADDRESS 0x7E78u    /* 047E78 */
#define fill_047ECC_ADDRESS 0x7ECCu    /* 047ECC */
#define set_index_048000_ADDRESS 0x6000u    /* 048000 */
#define animation_table_048008_ADDRESS 0x6008u    /* 048008 */
#define animation_048024_ADDRESS 0x6024u    /* 048024 */
#define sprite_list_04802C_ADDRESS 0x602Cu    /* 04802C */
#define animation_048056_ADDRESS 0x6056u    /* 048056 */
#define sprite_list_048082_ADDRESS 0x6082u    /* 048082 */
#define sprite_list_0480AC_ADDRESS 0x60ACu    /* 0480AC */
#define sprite_list_0480D6_ADDRESS 0x60D6u    /* 0480D6 */
#define animation_048100_ADDRESS 0x6100u    /* 048100 */
#define sprite_list_04811C_ADDRESS 0x611Cu    /* 04811C */
#define sprite_list_048146_ADDRESS 0x6146u    /* 048146 */
#define sprite_list_048170_ADDRESS 0x6170u    /* 048170 */
#define sprite_list_04819A_ADDRESS 0x619Au    /* 04819A */
#define animation_0481C4_ADDRESS 0x61C4u    /* 0481C4 */
#define sprite_list_0481D4_ADDRESS 0x61D4u    /* 0481D4 */
#define sprite_list_0481FE_ADDRESS 0x61FEu    /* 0481FE */
#define animation_048228_ADDRESS 0x6228u    /* 048228 */
#define sprite_list_048238_ADDRESS 0x6238u    /* 048238 */
#define animation_048262_ADDRESS 0x6262u    /* 048262 */
#define sprite_list_048286_ADDRESS 0x6286u    /* 048286 */
#define sprite_list_0482B0_ADDRESS 0x62B0u    /* 0482B0 */
#define sprite_list_0482DA_ADDRESS 0x62DAu    /* 0482DA */
#define sprite_list_048304_ADDRESS 0x6304u    /* 048304 */
#define sprite_list_04832E_ADDRESS 0x632Eu    /* 04832E */
#define animation_048358_ADDRESS 0x6358u    /* 048358 */
#define sprite_list_04836C_ADDRESS 0x636Cu    /* 04836C */
#define sprite_list_048396_ADDRESS 0x6396u    /* 048396 */
#define sprite_list_0483C0_ADDRESS 0x63C0u    /* 0483C0 */
#define animation_0483EA_ADDRESS 0x63EAu    /* 0483EA */
#define sprite_list_048406_ADDRESS 0x6406u    /* 048406 */
#define sprite_list_048430_ADDRESS 0x6430u    /* 048430 */
#define sprite_list_048460_ADDRESS 0x6460u    /* 048460 */
#define sprite_list_048490_ADDRESS 0x6490u    /* 048490 */
#define animation_0484C0_ADDRESS 0x64C0u    /* 0484C0 */
#define sprite_list_0484E4_ADDRESS 0x64E4u    /* 0484E4 */
#define sprite_list_04850E_ADDRESS 0x650Eu    /* 04850E */
#define sprite_list_048538_ADDRESS 0x6538u    /* 048538 */
#define sprite_list_048568_ADDRESS 0x6568u    /* 048568 */
#define sprite_list_048598_ADDRESS 0x6598u    /* 048598 */
#define animation_0485CE_ADDRESS 0x65CEu    /* 0485CE */
#define sprite_list_0485FE_ADDRESS 0x65FEu    /* 0485FE */
#define sprite_list_048628_ADDRESS 0x6628u    /* 048628 */
#define sprite_list_048652_ADDRESS 0x6652u    /* 048652 */
#define sprite_list_04867C_ADDRESS 0x667Cu    /* 04867C */
#define sprite_list_0486A6_ADDRESS 0x66A6u    /* 0486A6 */
#define animation_0486D0_ADDRESS 0x66D0u    /* 0486D0 */
#define sprite_list_0486E8_ADDRESS 0x66E8u    /* 0486E8 */
#define sprite_list_048712_ADDRESS 0x6712u    /* 048712 */
#define animation_04873C_ADDRESS 0x673Cu    /* 04873C */
#define sprite_list_048768_ADDRESS 0x6768u    /* 048768 */
#define sprite_list_048792_ADDRESS 0x6792u    /* 048792 */
#define sprite_list_0487BC_ADDRESS 0x67BCu    /* 0487BC */
#define sprite_list_0487E0_ADDRESS 0x67E0u    /* 0487E0 */
#define sprite_list_048804_ADDRESS 0x6804u    /* 048804 */
#define sprite_list_04883A_ADDRESS 0x683Au    /* 04883A */
#define animation_048864_ADDRESS 0x6864u    /* 048864 */
#define sprite_list_048874_ADDRESS 0x6874u    /* 048874 */
#define sprite_list_04889E_ADDRESS 0x689Eu    /* 04889E */
#define sprite_list_0488C8_ADDRESS 0x68C8u    /* 0488C8 */
#define animation_0488F2_ADDRESS 0x68F2u    /* 0488F2 */
#define sprite_list_048906_ADDRESS 0x6906u    /* 048906 */
#define sprite_list_048930_ADDRESS 0x6930u    /* 048930 */
#define sprite_list_04895A_ADDRESS 0x695Au    /* 04895A */
#define sprite_list_048984_ADDRESS 0x6984u    /* 048984 */
#define animation_table_04899C_ADDRESS 0x699Cu    /* 04899C */
#define animation_0489B2_ADDRESS 0x69B2u    /* 0489B2 */
#define sprite_list_0489DA_ADDRESS 0x69DAu    /* 0489DA */
#define sprite_list_048A2E_ADDRESS 0x6A2Eu    /* 048A2E */
#define sprite_list_048A82_ADDRESS 0x6A82u    /* 048A82 */
#define animation_048ADC_ADDRESS 0x6ADCu    /* 048ADC */
#define sprite_list_048AF8_ADDRESS 0x6AF8u    /* 048AF8 */
#define sprite_list_048B46_ADDRESS 0x6B46u    /* 048B46 */
#define animation_048B94_ADDRESS 0x6B94u    /* 048B94 */
#define sprite_list_048BBC_ADDRESS 0x6BBCu    /* 048BBC */
#define sprite_list_048C0A_ADDRESS 0x6C0Au    /* 048C0A */
#define sprite_list_048C58_ADDRESS 0x6C58u    /* 048C58 */
#define animation_048CA6_ADDRESS 0x6CA6u    /* 048CA6 */
#define sprite_list_048CB6_ADDRESS 0x6CB6u    /* 048CB6 */
#define sprite_list_048CFE_ADDRESS 0x6CFEu    /* 048CFE */
#define sprite_list_048D4C_ADDRESS 0x6D4Cu    /* 048D4C */
#define animation_048D9A_ADDRESS 0x6D9Au    /* 048D9A */
#define sprite_list_048DC2_ADDRESS 0x6DC2u    /* 048DC2 */
#define sprite_list_048E0A_ADDRESS 0x6E0Au    /* 048E0A */
#define sprite_list_048E52_ADDRESS 0x6E52u    /* 048E52 */
#define animation_048EAC_ADDRESS 0x6EACu    /* 048EAC */
#define sprite_list_048EC4_ADDRESS 0x6EC4u    /* 048EC4 */
#define sprite_list_048EFA_ADDRESS 0x6EFAu    /* 048EFA */
#define sprite_list_048F30_ADDRESS 0x6F30u    /* 048F30 */
#define sprite_list_048F66_ADDRESS 0x6F66u    /* 048F66 */
#define sprite_list_048FA8_ADDRESS 0x6FA8u    /* 048FA8 */
#define animation_048FF6_ADDRESS 0x6FF6u    /* 048FF6 */
#define sprite_list_04901A_ADDRESS 0x701Au    /* 04901A */
#define sprite_list_049068_ADDRESS 0x7068u    /* 049068 */
#define sprite_list_0490B6_ADDRESS 0x70B6u    /* 0490B6 */
#define sprite_list_049104_ADDRESS 0x7104u    /* 049104 */
#define sprite_list_049152_ADDRESS 0x7152u    /* 049152 */
#define sprite_list_0491A0_ADDRESS 0x71A0u    /* 0491A0 */
#define sprite_list_0491EE_ADDRESS 0x71EEu    /* 0491EE */
#define sprite_list_04923C_ADDRESS 0x723Cu    /* 04923C */
#define animation_04928A_ADDRESS 0x728Au    /* 04928A */
#define sprite_list_0492BA_ADDRESS 0x72BAu    /* 0492BA */
#define sprite_list_049308_ADDRESS 0x7308u    /* 049308 */
#define sprite_list_049356_ADDRESS 0x7356u    /* 049356 */
#define sprite_list_0493A4_ADDRESS 0x73A4u    /* 0493A4 */
#define sprite_list_0493F2_ADDRESS 0x73F2u    /* 0493F2 */
#define sprite_list_049446_ADDRESS 0x7446u    /* 049446 */
#define sprite_list_04949A_ADDRESS 0x749Au    /* 04949A */
#define animation_0494EE_ADDRESS 0x74EEu    /* 0494EE */
#define animation_0494F6_ADDRESS 0x74F6u    /* 0494F6 */
#define sprite_list_049512_ADDRESS 0x7512u    /* 049512 */
#define animation_04953C_ADDRESS 0x753Cu    /* 04953C */
#define sprite_list_049554_ADDRESS 0x7554u    /* 049554 */
#define sprite_list_0495A2_ADDRESS 0x75A2u    /* 0495A2 */
#define sprite_list_0495E4_ADDRESS 0x75E4u    /* 0495E4 */
#define sprite_list_049626_ADDRESS 0x7626u    /* 049626 */
#define sprite_list_049656_ADDRESS 0x7656u    /* 049656 */
#define animation_table_049680_ADDRESS 0x7680u    /* 049680 */
#define animation_0496A6_ADDRESS 0x76A6u    /* 0496A6 */
#define sprite_list_0496AE_ADDRESS 0x76AEu    /* 0496AE */
#define animation_0496B4_ADDRESS 0x76B4u    /* 0496B4 */
#define sprite_list_0496BC_ADDRESS 0x76BCu    /* 0496BC */
#define animation_0496C2_ADDRESS 0x76C2u    /* 0496C2 */
#define sprite_list_0496CA_ADDRESS 0x76CAu    /* 0496CA */
#define animation_0496E2_ADDRESS 0x76E2u    /* 0496E2 */
#define sprite_list_0496EE_ADDRESS 0x76EEu    /* 0496EE */
#define sprite_list_0496FA_ADDRESS 0x76FAu    /* 0496FA */
#define animation_049706_ADDRESS 0x7706u    /* 049706 */
#define sprite_list_049716_ADDRESS 0x7716u    /* 049716 */
#define sprite_list_049728_ADDRESS 0x7728u    /* 049728 */
#define sprite_list_04972E_ADDRESS 0x772Eu    /* 04972E */
#define sprite_list_04973A_ADDRESS 0x773Au    /* 04973A */
#define animation_049746_ADDRESS 0x7746u    /* 049746 */
#define sprite_list_04975A_ADDRESS 0x775Au    /* 04975A */
#define sprite_list_049760_ADDRESS 0x7760u    /* 049760 */
#define sprite_list_049766_ADDRESS 0x7766u    /* 049766 */
#define sprite_list_049784_ADDRESS 0x7784u    /* 049784 */
#define animation_0497A2_ADDRESS 0x77A2u    /* 0497A2 */
#define sprite_list_0497AA_ADDRESS 0x77AAu    /* 0497AA */
#define animation_0497B6_ADDRESS 0x77B6u    /* 0497B6 */
#define sprite_list_0497C2_ADDRESS 0x77C2u    /* 0497C2 */
#define sprite_list_0497C8_ADDRESS 0x77C8u    /* 0497C8 */
#define animation_0497CE_ADDRESS 0x77CEu    /* 0497CE */
#define sprite_list_0497FA_ADDRESS 0x77FAu    /* 0497FA */
#define sprite_list_04981E_ADDRESS 0x781Eu    /* 04981E */
#define sprite_list_04984E_ADDRESS 0x784Eu    /* 04984E */
#define sprite_list_049890_ADDRESS 0x7890u    /* 049890 */
#define sprite_list_0498D8_ADDRESS 0x78D8u    /* 0498D8 */
#define sprite_list_049938_ADDRESS 0x7938u    /* 049938 */
#define sprite_list_04998C_ADDRESS 0x798Cu    /* 04998C */
#define sprite_list_0499DA_ADDRESS 0x79DAu    /* 0499DA */
#define sprite_list_049A1C_ADDRESS 0x7A1Cu    /* 049A1C */
#define sprite_list_049A3A_ADDRESS 0x7A3Au    /* 049A3A */
#define animation_049A4C_ADDRESS 0x7A4Cu    /* 049A4C */
#define sprite_list_049A54_ADDRESS 0x7A54u    /* 049A54 */
#define animation_049A5A_ADDRESS 0x7A5Au    /* 049A5A */
#define sprite_list_049A76_ADDRESS 0x7A76u    /* 049A76 */
#define sprite_list_049A7C_ADDRESS 0x7A7Cu    /* 049A7C */
#define sprite_list_049A82_ADDRESS 0x7A82u    /* 049A82 */
#define sprite_list_049A88_ADDRESS 0x7A88u    /* 049A88 */
#define sprite_list_049A8E_ADDRESS 0x7A8Eu    /* 049A8E */
#define sprite_list_049A94_ADDRESS 0x7A94u    /* 049A94 */
#define animation_049A9A_ADDRESS 0x7A9Au    /* 049A9A */
#define sprite_list_049AA2_ADDRESS 0x7AA2u    /* 049AA2 */
#define animation_049AA8_ADDRESS 0x7AA8u    /* 049AA8 */
#define sprite_list_049AB4_ADDRESS 0x7AB4u    /* 049AB4 */
#define sprite_list_049ABA_ADDRESS 0x7ABAu    /* 049ABA */
#define animation_049AC0_ADDRESS 0x7AC0u    /* 049AC0 */
#define sprite_list_049AC8_ADDRESS 0x7AC8u    /* 049AC8 */
#define animation_049ACE_ADDRESS 0x7ACEu    /* 049ACE */
#define animation_049ADA_ADDRESS 0x7ADAu    /* 049ADA */
#define sprite_list_049AE2_ADDRESS 0x7AE2u    /* 049AE2 */
#define animation_049AEE_ADDRESS 0x7AEEu    /* 049AEE */
#define sprite_list_049AF6_ADDRESS 0x7AF6u    /* 049AF6 */
#define animation_049B02_ADDRESS 0x7B02u    /* 049B02 */
#define sprite_list_049B0A_ADDRESS 0x7B0Au    /* 049B0A */
#define animation_049B16_ADDRESS 0x7B16u    /* 049B16 */
#define sprite_list_049B36_ADDRESS 0x7B36u    /* 049B36 */
#define sprite_list_049B42_ADDRESS 0x7B42u    /* 049B42 */
#define sprite_list_049B54_ADDRESS 0x7B54u    /* 049B54 */
#define sprite_list_049B7E_ADDRESS 0x7B7Eu    /* 049B7E */
#define sprite_list_049BA8_ADDRESS 0x7BA8u    /* 049BA8 */
#define sprite_list_049BC6_ADDRESS 0x7BC6u    /* 049BC6 */
#define sprite_list_049BE4_ADDRESS 0x7BE4u    /* 049BE4 */
#define animation_table_049BF0_ADDRESS 0x7BF0u    /* 049BF0 */
#define animation_049BF2_ADDRESS 0x7BF2u    /* 049BF2 */
#define sprite_list_049C02_ADDRESS 0x7C02u    /* 049C02 */
#define sprite_list_049C08_ADDRESS 0x7C08u    /* 049C08 */
#define sprite_list_049C0E_ADDRESS 0x7C0Eu    /* 049C0E */
#define fill_049C1A_ADDRESS 0x7C1Au    /* 049C1A */
#define unreached_animation_049D48_ADDRESS 0x7D48u    /* 049D48 */
#define sprite_list_049D64_ADDRESS 0x7D64u    /* 049D64 */
#define sprite_list_049D8E_ADDRESS 0x7D8Eu    /* 049D8E */
#define sprite_list_049DBE_ADDRESS 0x7DBEu    /* 049DBE */
#define sprite_list_049DF4_ADDRESS 0x7DF4u    /* 049DF4 */
#define sprite_list_049E30_ADDRESS 0x7E30u    /* 049E30 */
#define sprite_list_049E78_ADDRESS 0x7E78u    /* 049E78 */
#define fill_049ECC_ADDRESS 0x7ECCu    /* 049ECC */
#define set_index_04A000_ADDRESS 0x6000u    /* 04A000 */
#define animation_table_04A002_ADDRESS 0x6002u    /* 04A002 */
#define sprite_list_04A020_ADDRESS 0x6020u    /* 04A020 */
#define animation_04A04A_ADDRESS 0x604Au    /* 04A04A */
#define sprite_list_04A0A2_ADDRESS 0x60A2u    /* 04A0A2 */
#define sprite_list_04A0D2_ADDRESS 0x60D2u    /* 04A0D2 */
#define sprite_list_04A108_ADDRESS 0x6108u    /* 04A108 */
#define sprite_list_04A144_ADDRESS 0x6144u    /* 04A144 */
#define sprite_list_04A186_ADDRESS 0x6186u    /* 04A186 */
#define sprite_list_04A1C8_ADDRESS 0x61C8u    /* 04A1C8 */
#define sprite_list_04A20A_ADDRESS 0x620Au    /* 04A20A */
#define sprite_list_04A258_ADDRESS 0x6258u    /* 04A258 */
#define sprite_list_04A2AC_ADDRESS 0x62ACu    /* 04A2AC */
#define sprite_list_04A306_ADDRESS 0x6306u    /* 04A306 */
#define sprite_list_04A366_ADDRESS 0x6366u    /* 04A366 */
#define sprite_list_04A3C6_ADDRESS 0x63C6u    /* 04A3C6 */
#define sprite_list_04A420_ADDRESS 0x6420u    /* 04A420 */
#define sprite_list_04A474_ADDRESS 0x6474u    /* 04A474 */
#define sprite_list_04A4C2_ADDRESS 0x64C2u    /* 04A4C2 */
#define sprite_list_04A50A_ADDRESS 0x650Au    /* 04A50A */
#define sprite_list_04A54C_ADDRESS 0x654Cu    /* 04A54C */
#define sprite_list_04A588_ADDRESS 0x6588u    /* 04A588 */
#define sprite_list_04A5BE_ADDRESS 0x65BEu    /* 04A5BE */
#define sprite_list_04A5EE_ADDRESS 0x65EEu    /* 04A5EE */
#define sprite_list_04A618_ADDRESS 0x6618u    /* 04A618 */
#define animation_04A63C_ADDRESS 0x663Cu    /* 04A63C */
#define sprite_list_04A68C_ADDRESS 0x668Cu    /* 04A68C */
#define sprite_list_04A6B6_ADDRESS 0x66B6u    /* 04A6B6 */
#define sprite_list_04A6E6_ADDRESS 0x66E6u    /* 04A6E6 */
#define sprite_list_04A71C_ADDRESS 0x671Cu    /* 04A71C */
#define sprite_list_04A758_ADDRESS 0x6758u    /* 04A758 */
#define sprite_list_04A794_ADDRESS 0x6794u    /* 04A794 */
#define sprite_list_04A7D6_ADDRESS 0x67D6u    /* 04A7D6 */
#define sprite_list_04A81E_ADDRESS 0x681Eu    /* 04A81E */
#define sprite_list_04A86C_ADDRESS 0x686Cu    /* 04A86C */
#define sprite_list_04A8B4_ADDRESS 0x68B4u    /* 04A8B4 */
#define sprite_list_04A8F6_ADDRESS 0x68F6u    /* 04A8F6 */
#define sprite_list_04A932_ADDRESS 0x6932u    /* 04A932 */
#define sprite_list_04A968_ADDRESS 0x6968u    /* 04A968 */
#define sprite_list_04A998_ADDRESS 0x6998u    /* 04A998 */
#define sprite_list_04A9C2_ADDRESS 0x69C2u    /* 04A9C2 */
#define sprite_list_04A9E6_ADDRESS 0x69E6u    /* 04A9E6 */
#define sprite_list_04AA04_ADDRESS 0x6A04u    /* 04AA04 */
#define sprite_list_04AA2E_ADDRESS 0x6A2Eu    /* 04AA2E */
#define sprite_list_04AA58_ADDRESS 0x6A58u    /* 04AA58 */
#define animation_04AA82_ADDRESS 0x6A82u    /* 04AA82 */
#define sprite_list_04AAD2_ADDRESS 0x6AD2u    /* 04AAD2 */
#define sprite_list_04AAFC_ADDRESS 0x6AFCu    /* 04AAFC */
#define sprite_list_04AB2C_ADDRESS 0x6B2Cu    /* 04AB2C */
#define sprite_list_04AB5C_ADDRESS 0x6B5Cu    /* 04AB5C */
#define sprite_list_04AB92_ADDRESS 0x6B92u    /* 04AB92 */
#define sprite_list_04ABCE_ADDRESS 0x6BCEu    /* 04ABCE */
#define sprite_list_04AC10_ADDRESS 0x6C10u    /* 04AC10 */
#define sprite_list_04AC58_ADDRESS 0x6C58u    /* 04AC58 */
#define sprite_list_04ACA6_ADDRESS 0x6CA6u    /* 04ACA6 */
#define sprite_list_04AD00_ADDRESS 0x6D00u    /* 04AD00 */
#define sprite_list_04AD60_ADDRESS 0x6D60u    /* 04AD60 */
#define sprite_list_04ADBA_ADDRESS 0x6DBAu    /* 04ADBA */
#define sprite_list_04AE1A_ADDRESS 0x6E1Au    /* 04AE1A */
#define sprite_list_04AE7A_ADDRESS 0x6E7Au    /* 04AE7A */
#define sprite_list_04AEDA_ADDRESS 0x6EDAu    /* 04AEDA */
#define sprite_list_04AF3A_ADDRESS 0x6F3Au    /* 04AF3A */
#define sprite_list_04AF9A_ADDRESS 0x6F9Au    /* 04AF9A */
#define sprite_list_04AFFA_ADDRESS 0x6FFAu    /* 04AFFA */
#define sprite_list_04B05A_ADDRESS 0x705Au    /* 04B05A */
#define animation_04B0BA_ADDRESS 0x70BAu    /* 04B0BA */
#define animation_04B10A_ADDRESS 0x710Au    /* 04B10A */
#define sprite_list_04B12A_ADDRESS 0x712Au    /* 04B12A */
#define sprite_list_04B15A_ADDRESS 0x715Au    /* 04B15A */
#define sprite_list_04B18A_ADDRESS 0x718Au    /* 04B18A */
#define sprite_list_04B1C0_ADDRESS 0x71C0u    /* 04B1C0 */
#define sprite_list_04B202_ADDRESS 0x7202u    /* 04B202 */
#define sprite_list_04B250_ADDRESS 0x7250u    /* 04B250 */
#define sprite_list_04B2AA_ADDRESS 0x72AAu    /* 04B2AA */
#define animation_04B30A_ADDRESS 0x730Au    /* 04B30A */
#define animation_04B32E_ADDRESS 0x732Eu    /* 04B32E */
#define sprite_list_04B35A_ADDRESS 0x735Au    /* 04B35A */
#define sprite_list_04B3BA_ADDRESS 0x73BAu    /* 04B3BA */
#define sprite_list_04B41A_ADDRESS 0x741Au    /* 04B41A */
#define animation_04B47A_ADDRESS 0x747Au    /* 04B47A */
#define sprite_list_04B49E_ADDRESS 0x749Eu    /* 04B49E */
#define sprite_list_04B4FE_ADDRESS 0x74FEu    /* 04B4FE */
#define sprite_list_04B55E_ADDRESS 0x755Eu    /* 04B55E */
#define sprite_list_04B5BE_ADDRESS 0x75BEu    /* 04B5BE */
#define animation_04B61E_ADDRESS 0x761Eu    /* 04B61E */
#define sprite_list_04B642_ADDRESS 0x7642u    /* 04B642 */
#define sprite_list_04B6A2_ADDRESS 0x76A2u    /* 04B6A2 */
#define sprite_list_04B702_ADDRESS 0x7702u    /* 04B702 */
#define animation_04B762_ADDRESS 0x7762u    /* 04B762 */
#define sprite_list_04B786_ADDRESS 0x7786u    /* 04B786 */
#define sprite_list_04B7E6_ADDRESS 0x77E6u    /* 04B7E6 */
#define sprite_list_04B846_ADDRESS 0x7846u    /* 04B846 */
#define animation_04B8A6_ADDRESS 0x78A6u    /* 04B8A6 */
#define sprite_list_04B8C6_ADDRESS 0x78C6u    /* 04B8C6 */
#define sprite_list_04B920_ADDRESS 0x7920u    /* 04B920 */
#define sprite_list_04B97A_ADDRESS 0x797Au    /* 04B97A */
#define animation_04B9D4_ADDRESS 0x79D4u    /* 04B9D4 */
#define sprite_list_04B9F4_ADDRESS 0x79F4u    /* 04B9F4 */
#define sprite_list_04BA24_ADDRESS 0x7A24u    /* 04BA24 */
#define sprite_list_04BA54_ADDRESS 0x7A54u    /* 04BA54 */
#define sprite_list_04BA8A_ADDRESS 0x7A8Au    /* 04BA8A */
#define sprite_list_04BAC6_ADDRESS 0x7AC6u    /* 04BAC6 */
#define sprite_list_04BB08_ADDRESS 0x7B08u    /* 04BB08 */
#define sprite_list_04BB56_ADDRESS 0x7B56u    /* 04BB56 */
#define animation_04BBA4_ADDRESS 0x7BA4u    /* 04BBA4 */
#define animation_04BBC4_ADDRESS 0x7BC4u    /* 04BBC4 */
#define sprite_list_04BBE0_ADDRESS 0x7BE0u    /* 04BBE0 */
#define sprite_list_04BC34_ADDRESS 0x7C34u    /* 04BC34 */
#define sprite_list_04BC7C_ADDRESS 0x7C7Cu    /* 04BC7C */
#define sprite_list_04BCB8_ADDRESS 0x7CB8u    /* 04BCB8 */
#define sprite_list_04BCEE_ADDRESS 0x7CEEu    /* 04BCEE */
#define sprite_list_04BD1E_ADDRESS 0x7D1Eu    /* 04BD1E */
#define animation_04BD48_ADDRESS 0x7D48u    /* 04BD48 */
#define sprite_list_04BD64_ADDRESS 0x7D64u    /* 04BD64 */
#define sprite_list_04BD8E_ADDRESS 0x7D8Eu    /* 04BD8E */
#define sprite_list_04BDBE_ADDRESS 0x7DBEu    /* 04BDBE */
#define sprite_list_04BDF4_ADDRESS 0x7DF4u    /* 04BDF4 */
#define sprite_list_04BE30_ADDRESS 0x7E30u    /* 04BE30 */
#define sprite_list_04BE78_ADDRESS 0x7E78u    /* 04BE78 */
#define fill_04BECC_ADDRESS 0x7ECCu    /* 04BECC */
#define set_index_04C000_ADDRESS 0x6000u    /* 04C000 */
#define animation_table_04C00A_ADDRESS 0x600Au    /* 04C00A */
#define animation_04C02C_ADDRESS 0x602Cu    /* 04C02C */
#define sprite_list_04C058_ADDRESS 0x6058u    /* 04C058 */
#define sprite_list_04C06A_ADDRESS 0x606Au    /* 04C06A */
#define sprite_list_04C082_ADDRESS 0x6082u    /* 04C082 */
#define sprite_list_04C09A_ADDRESS 0x609Au    /* 04C09A */
#define sprite_list_04C0AC_ADDRESS 0x60ACu    /* 04C0AC */
#define sprite_list_04C0C4_ADDRESS 0x60C4u    /* 04C0C4 */
#define animation_04C0DC_ADDRESS 0x60DCu    /* 04C0DC */
#define sprite_list_04C118_ADDRESS 0x6118u    /* 04C118 */
#define sprite_list_04C13C_ADDRESS 0x613Cu    /* 04C13C */
#define sprite_list_04C160_ADDRESS 0x6160u    /* 04C160 */
#define sprite_list_04C17E_ADDRESS 0x617Eu    /* 04C17E */
#define sprite_list_04C19C_ADDRESS 0x619Cu    /* 04C19C */
#define sprite_list_04C1BA_ADDRESS 0x61BAu    /* 04C1BA */
#define sprite_list_04C1D8_ADDRESS 0x61D8u    /* 04C1D8 */
#define sprite_list_04C1FC_ADDRESS 0x61FCu    /* 04C1FC */
#define animation_04C21A_ADDRESS 0x621Au    /* 04C21A */
#define sprite_list_04C236_ADDRESS 0x6236u    /* 04C236 */
#define sprite_list_04C248_ADDRESS 0x6248u    /* 04C248 */
#define sprite_list_04C260_ADDRESS 0x6260u    /* 04C260 */
#define sprite_list_04C27E_ADDRESS 0x627Eu    /* 04C27E */
#define animation_04C29C_ADDRESS 0x629Cu    /* 04C29C */
#define sprite_list_04C2C0_ADDRESS 0x62C0u    /* 04C2C0 */
#define sprite_list_04C2D8_ADDRESS 0x62D8u    /* 04C2D8 */
#define sprite_list_04C2F6_ADDRESS 0x62F6u    /* 04C2F6 */
#define sprite_list_04C30E_ADDRESS 0x630Eu    /* 04C30E */
#define sprite_list_04C32C_ADDRESS 0x632Cu    /* 04C32C */
#define sprite_list_04C344_ADDRESS 0x6344u    /* 04C344 */
#define animation_04C362_ADDRESS 0x6362u    /* 04C362 */
#define sprite_list_04C38E_ADDRESS 0x638Eu    /* 04C38E */
#define sprite_list_04C3B2_ADDRESS 0x63B2u    /* 04C3B2 */
#define sprite_list_04C3D6_ADDRESS 0x63D6u    /* 04C3D6 */
#define sprite_list_04C3FA_ADDRESS 0x63FAu    /* 04C3FA */
#define sprite_list_04C418_ADDRESS 0x6418u    /* 04C418 */
#define sprite_list_04C436_ADDRESS 0x6436u    /* 04C436 */
#define animation_04C454_ADDRESS 0x6454u    /* 04C454 */
#define sprite_list_04C478_ADDRESS 0x6478u    /* 04C478 */
#define sprite_list_04C496_ADDRESS 0x6496u    /* 04C496 */
#define sprite_list_04C4B4_ADDRESS 0x64B4u    /* 04C4B4 */
#define sprite_list_04C4DE_ADDRESS 0x64DEu    /* 04C4DE */
#define animation_04C508_ADDRESS 0x6508u    /* 04C508 */
#define sprite_list_04C534_ADDRESS 0x6534u    /* 04C534 */
#define sprite_list_04C552_ADDRESS 0x6552u    /* 04C552 */
#define sprite_list_04C570_ADDRESS 0x6570u    /* 04C570 */
#define animation_table_04C58E_ADDRESS 0x658Eu    /* 04C58E */
#define animation_04C5B0_ADDRESS 0x65B0u    /* 04C5B0 */
#define sprite_list_04C5BC_ADDRESS 0x65BCu    /* 04C5BC */
#define sprite_list_04C5D4_ADDRESS 0x65D4u    /* 04C5D4 */
#define animation_04C5EC_ADDRESS 0x65ECu    /* 04C5EC */
#define sprite_list_04C628_ADDRESS 0x6628u    /* 04C628 */
#define sprite_list_04C646_ADDRESS 0x6646u    /* 04C646 */
#define sprite_list_04C664_ADDRESS 0x6664u    /* 04C664 */
#define sprite_list_04C67C_ADDRESS 0x667Cu    /* 04C67C */
#define sprite_list_04C694_ADDRESS 0x6694u    /* 04C694 */
#define sprite_list_04C6AC_ADDRESS 0x66ACu    /* 04C6AC */
#define sprite_list_04C6C4_ADDRESS 0x66C4u    /* 04C6C4 */
#define sprite_list_04C6E2_ADDRESS 0x66E2u    /* 04C6E2 */
#define animation_04C6FA_ADDRESS 0x66FAu    /* 04C6FA */
#define sprite_list_04C716_ADDRESS 0x6716u    /* 04C716 */
#define sprite_list_04C728_ADDRESS 0x6728u    /* 04C728 */
#define sprite_list_04C740_ADDRESS 0x6740u    /* 04C740 */
#define sprite_list_04C758_ADDRESS 0x6758u    /* 04C758 */
#define animation_04C770_ADDRESS 0x6770u    /* 04C770 */
#define sprite_list_04C794_ADDRESS 0x6794u    /* 04C794 */
#define sprite_list_04C7AC_ADDRESS 0x67ACu    /* 04C7AC */
#define sprite_list_04C7C4_ADDRESS 0x67C4u    /* 04C7C4 */
#define sprite_list_04C7DC_ADDRESS 0x67DCu    /* 04C7DC */
#define sprite_list_04C7F4_ADDRESS 0x67F4u    /* 04C7F4 */
#define sprite_list_04C80C_ADDRESS 0x680Cu    /* 04C80C */
#define animation_04C824_ADDRESS 0x6824u    /* 04C824 */
#define sprite_list_04C850_ADDRESS 0x6850u    /* 04C850 */
#define sprite_list_04C86E_ADDRESS 0x686Eu    /* 04C86E */
#define sprite_list_04C88C_ADDRESS 0x688Cu    /* 04C88C */
#define sprite_list_04C8AA_ADDRESS 0x68AAu    /* 04C8AA */
#define sprite_list_04C8C2_ADDRESS 0x68C2u    /* 04C8C2 */
#define sprite_list_04C8DA_ADDRESS 0x68DAu    /* 04C8DA */
#define animation_04C8F2_ADDRESS 0x68F2u    /* 04C8F2 */
#define sprite_list_04C91E_ADDRESS 0x691Eu    /* 04C91E */
#define sprite_list_04C936_ADDRESS 0x6936u    /* 04C936 */
#define sprite_list_04C954_ADDRESS 0x6954u    /* 04C954 */
#define sprite_list_04C972_ADDRESS 0x6972u    /* 04C972 */
#define sprite_list_04C990_ADDRESS 0x6990u    /* 04C990 */
#define sprite_list_04C9B4_ADDRESS 0x69B4u    /* 04C9B4 */
#define sprite_list_04C9D8_ADDRESS 0x69D8u    /* 04C9D8 */
#define sprite_list_04C9F6_ADDRESS 0x69F6u    /* 04C9F6 */
#define sprite_list_04CA14_ADDRESS 0x6A14u    /* 04CA14 */
#define sprite_list_04CA32_ADDRESS 0x6A32u    /* 04CA32 */
#define animation_04CA50_ADDRESS 0x6A50u    /* 04CA50 */
#define sprite_list_04CA78_ADDRESS 0x6A78u    /* 04CA78 */
#define sprite_list_04CA96_ADDRESS 0x6A96u    /* 04CA96 */
#define sprite_list_04CAAE_ADDRESS 0x6AAEu    /* 04CAAE */
#define sprite_list_04CAD2_ADDRESS 0x6AD2u    /* 04CAD2 */
#define sprite_list_04CAF6_ADDRESS 0x6AF6u    /* 04CAF6 */
#define sprite_list_04CB1A_ADDRESS 0x6B1Au    /* 04CB1A */
#define animation_04CB3E_ADDRESS 0x6B3Eu    /* 04CB3E */
#define sprite_list_04CB6A_ADDRESS 0x6B6Au    /* 04CB6A */
#define sprite_list_04CB82_ADDRESS 0x6B82u    /* 04CB82 */
#define sprite_list_04CB9A_ADDRESS 0x6B9Au    /* 04CB9A */
#define animation_table_04CBB2_ADDRESS 0x6BB2u    /* 04CBB2 */
#define animation_04CBD4_ADDRESS 0x6BD4u    /* 04CBD4 */
#define sprite_list_04CC00_ADDRESS 0x6C00u    /* 04CC00 */
#define sprite_list_04CC12_ADDRESS 0x6C12u    /* 04CC12 */
#define sprite_list_04CC2A_ADDRESS 0x6C2Au    /* 04CC2A */
#define sprite_list_04CC42_ADDRESS 0x6C42u    /* 04CC42 */
#define sprite_list_04CC5A_ADDRESS 0x6C5Au    /* 04CC5A */
#define sprite_list_04CC78_ADDRESS 0x6C78u    /* 04CC78 */
#define animation_04CC96_ADDRESS 0x6C96u    /* 04CC96 */
#define sprite_list_04CCD2_ADDRESS 0x6CD2u    /* 04CCD2 */
#define sprite_list_04CCF6_ADDRESS 0x6CF6u    /* 04CCF6 */
#define sprite_list_04CD1A_ADDRESS 0x6D1Au    /* 04CD1A */
#define sprite_list_04CD38_ADDRESS 0x6D38u    /* 04CD38 */
#define sprite_list_04CD56_ADDRESS 0x6D56u    /* 04CD56 */
#define sprite_list_04CD74_ADDRESS 0x6D74u    /* 04CD74 */
#define sprite_list_04CD92_ADDRESS 0x6D92u    /* 04CD92 */
#define sprite_list_04CDB6_ADDRESS 0x6DB6u    /* 04CDB6 */
#define animation_04CDD4_ADDRESS 0x6DD4u    /* 04CDD4 */
#define sprite_list_04CDF0_ADDRESS 0x6DF0u    /* 04CDF0 */
#define sprite_list_04CE08_ADDRESS 0x6E08u    /* 04CE08 */
#define sprite_list_04CE20_ADDRESS 0x6E20u    /* 04CE20 */
#define sprite_list_04CE44_ADDRESS 0x6E44u    /* 04CE44 */
#define animation_04CE68_ADDRESS 0x6E68u    /* 04CE68 */
#define sprite_list_04CE8C_ADDRESS 0x6E8Cu    /* 04CE8C */
#define sprite_list_04CEAA_ADDRESS 0x6EAAu    /* 04CEAA */
#define sprite_list_04CECE_ADDRESS 0x6ECEu    /* 04CECE */
#define sprite_list_04CEEC_ADDRESS 0x6EECu    /* 04CEEC */
#define sprite_list_04CF10_ADDRESS 0x6F10u    /* 04CF10 */
#define sprite_list_04CF2E_ADDRESS 0x6F2Eu    /* 04CF2E */
#define animation_04CF52_ADDRESS 0x6F52u    /* 04CF52 */
#define sprite_list_04CF76_ADDRESS 0x6F76u    /* 04CF76 */
#define sprite_list_04CF9A_ADDRESS 0x6F9Au    /* 04CF9A */
#define sprite_list_04CFBE_ADDRESS 0x6FBEu    /* 04CFBE */
#define sprite_list_04CFEE_ADDRESS 0x6FEEu    /* 04CFEE */
#define animation_04D01E_ADDRESS 0x701Eu    /* 04D01E */
#define sprite_list_04D04A_ADDRESS 0x704Au    /* 04D04A */
#define sprite_list_04D06E_ADDRESS 0x706Eu    /* 04D06E */
#define sprite_list_04D092_ADDRESS 0x7092u    /* 04D092 */
#define sprite_list_04D0B6_ADDRESS 0x70B6u    /* 04D0B6 */
#define sprite_list_04D0DA_ADDRESS 0x70DAu    /* 04D0DA */
#define sprite_list_04D0FE_ADDRESS 0x70FEu    /* 04D0FE */
#define animation_04D122_ADDRESS 0x7122u    /* 04D122 */
#define sprite_list_04D14E_ADDRESS 0x714Eu    /* 04D14E */
#define sprite_list_04D172_ADDRESS 0x7172u    /* 04D172 */
#define sprite_list_04D196_ADDRESS 0x7196u    /* 04D196 */
#define animation_table_04D1BA_ADDRESS 0x71BAu    /* 04D1BA */
#define animation_04D1DC_ADDRESS 0x71DCu    /* 04D1DC */
#define sprite_list_04D208_ADDRESS 0x7208u    /* 04D208 */
#define sprite_list_04D220_ADDRESS 0x7220u    /* 04D220 */
#define sprite_list_04D238_ADDRESS 0x7238u    /* 04D238 */
#define sprite_list_04D250_ADDRESS 0x7250u    /* 04D250 */
#define sprite_list_04D26E_ADDRESS 0x726Eu    /* 04D26E */
#define sprite_list_04D28C_ADDRESS 0x728Cu    /* 04D28C */
#define animation_04D2AA_ADDRESS 0x72AAu    /* 04D2AA */
#define sprite_list_04D2E6_ADDRESS 0x72E6u    /* 04D2E6 */
#define sprite_list_04D304_ADDRESS 0x7304u    /* 04D304 */
#define sprite_list_04D322_ADDRESS 0x7322u    /* 04D322 */
#define sprite_list_04D33A_ADDRESS 0x733Au    /* 04D33A */
#define sprite_list_04D352_ADDRESS 0x7352u    /* 04D352 */
#define sprite_list_04D36A_ADDRESS 0x736Au    /* 04D36A */
#define sprite_list_04D382_ADDRESS 0x7382u    /* 04D382 */
#define sprite_list_04D3A0_ADDRESS 0x73A0u    /* 04D3A0 */
#define animation_04D3B8_ADDRESS 0x73B8u    /* 04D3B8 */
#define sprite_list_04D3D4_ADDRESS 0x73D4u    /* 04D3D4 */
#define sprite_list_04D3EC_ADDRESS 0x73ECu    /* 04D3EC */
#define sprite_list_04D404_ADDRESS 0x7404u    /* 04D404 */
#define sprite_list_04D422_ADDRESS 0x7422u    /* 04D422 */
#define animation_04D440_ADDRESS 0x7440u    /* 04D440 */
#define sprite_list_04D464_ADDRESS 0x7464u    /* 04D464 */
#define sprite_list_04D482_ADDRESS 0x7482u    /* 04D482 */
#define sprite_list_04D4A0_ADDRESS 0x74A0u    /* 04D4A0 */
#define sprite_list_04D4BE_ADDRESS 0x74BEu    /* 04D4BE */
#define sprite_list_04D4DC_ADDRESS 0x74DCu    /* 04D4DC */
#define sprite_list_04D4FA_ADDRESS 0x74FAu    /* 04D4FA */
#define animation_04D518_ADDRESS 0x7518u    /* 04D518 */
#define sprite_list_04D540_ADDRESS 0x7540u    /* 04D540 */
#define sprite_list_04D564_ADDRESS 0x7564u    /* 04D564 */
#define sprite_list_04D582_ADDRESS 0x7582u    /* 04D582 */
#define sprite_list_04D5AC_ADDRESS 0x75ACu    /* 04D5AC */
#define sprite_list_04D5D6_ADDRESS 0x75D6u    /* 04D5D6 */
#define animation_04D600_ADDRESS 0x7600u    /* 04D600 */
#define sprite_list_04D62C_ADDRESS 0x762Cu    /* 04D62C */
#define sprite_list_04D64A_ADDRESS 0x764Au    /* 04D64A */
#define sprite_list_04D668_ADDRESS 0x7668u    /* 04D668 */
#define sprite_list_04D686_ADDRESS 0x7686u    /* 04D686 */
#define sprite_list_04D6A4_ADDRESS 0x76A4u    /* 04D6A4 */
#define sprite_list_04D6C2_ADDRESS 0x76C2u    /* 04D6C2 */
#define animation_04D6E0_ADDRESS 0x76E0u    /* 04D6E0 */
#define sprite_list_04D70C_ADDRESS 0x770Cu    /* 04D70C */
#define sprite_list_04D72A_ADDRESS 0x772Au    /* 04D72A */
#define sprite_list_04D748_ADDRESS 0x7748u    /* 04D748 */
#define animation_table_04D766_ADDRESS 0x7766u    /* 04D766 */
#define animation_04D78A_ADDRESS 0x778Au    /* 04D78A */
#define sprite_list_04D796_ADDRESS 0x7796u    /* 04D796 */
#define sprite_list_04D7A8_ADDRESS 0x77A8u    /* 04D7A8 */
#define animation_04D7BA_ADDRESS 0x77BAu    /* 04D7BA */
#define sprite_list_04D7E6_ADDRESS 0x77E6u    /* 04D7E6 */
#define sprite_list_04D7FE_ADDRESS 0x77FEu    /* 04D7FE */
#define sprite_list_04D81C_ADDRESS 0x781Cu    /* 04D81C */
#define sprite_list_04D83A_ADDRESS 0x783Au    /* 04D83A */
#define sprite_list_04D852_ADDRESS 0x7852u    /* 04D852 */
#define sprite_list_04D870_ADDRESS 0x7870u    /* 04D870 */
#define animation_04D88E_ADDRESS 0x788Eu    /* 04D88E */
#define sprite_list_04D8CA_ADDRESS 0x78CAu    /* 04D8CA */
#define sprite_list_04D8EE_ADDRESS 0x78EEu    /* 04D8EE */
#define sprite_list_04D912_ADDRESS 0x7912u    /* 04D912 */
#define sprite_list_04D92A_ADDRESS 0x792Au    /* 04D92A */
#define sprite_list_04D942_ADDRESS 0x7942u    /* 04D942 */
#define sprite_list_04D95A_ADDRESS 0x795Au    /* 04D95A */
#define sprite_list_04D972_ADDRESS 0x7972u    /* 04D972 */
#define sprite_list_04D990_ADDRESS 0x7990u    /* 04D990 */
#define animation_04D9A8_ADDRESS 0x79A8u    /* 04D9A8 */
#define sprite_list_04D9C4_ADDRESS 0x79C4u    /* 04D9C4 */
#define sprite_list_04D9DC_ADDRESS 0x79DCu    /* 04D9DC */
#define sprite_list_04D9EE_ADDRESS 0x79EEu    /* 04D9EE */
#define sprite_list_04DA06_ADDRESS 0x7A06u    /* 04DA06 */
#define animation_04DA1E_ADDRESS 0x7A1Eu    /* 04DA1E */
#define sprite_list_04DA3A_ADDRESS 0x7A3Au    /* 04DA3A */
#define sprite_list_04DA52_ADDRESS 0x7A52u    /* 04DA52 */
#define sprite_list_04DA6A_ADDRESS 0x7A6Au    /* 04DA6A */
#define sprite_list_04DA82_ADDRESS 0x7A82u    /* 04DA82 */
#define sprite_list_04DA9A_ADDRESS 0x7A9Au    /* 04DA9A */
#define sprite_list_04DAB8_ADDRESS 0x7AB8u    /* 04DAB8 */
#define animation_04DAD0_ADDRESS 0x7AD0u    /* 04DAD0 */
#define sprite_list_04DB24_ADDRESS 0x7B24u    /* 04DB24 */
#define sprite_list_04DB3C_ADDRESS 0x7B3Cu    /* 04DB3C */
#define sprite_list_04DB54_ADDRESS 0x7B54u    /* 04DB54 */
#define sprite_list_04DB6C_ADDRESS 0x7B6Cu    /* 04DB6C */
#define sprite_list_04DB84_ADDRESS 0x7B84u    /* 04DB84 */
#define sprite_list_04DB9C_ADDRESS 0x7B9Cu    /* 04DB9C */
#define sprite_list_04DBB4_ADDRESS 0x7BB4u    /* 04DBB4 */
#define sprite_list_04DBCC_ADDRESS 0x7BCCu    /* 04DBCC */
#define sprite_list_04DBE4_ADDRESS 0x7BE4u    /* 04DBE4 */
#define animation_04DBFC_ADDRESS 0x7BFCu    /* 04DBFC */
#define sprite_list_04DC20_ADDRESS 0x7C20u    /* 04DC20 */
#define sprite_list_04DC38_ADDRESS 0x7C38u    /* 04DC38 */
#define sprite_list_04DC50_ADDRESS 0x7C50u    /* 04DC50 */
#define sprite_list_04DC74_ADDRESS 0x7C74u    /* 04DC74 */
#define animation_04DC98_ADDRESS 0x7C98u    /* 04DC98 */
#define sprite_list_04DCA4_ADDRESS 0x7CA4u    /* 04DCA4 */
#define sprite_list_04DCAA_ADDRESS 0x7CAAu    /* 04DCAA */
#define fill_04DCB0_ADDRESS 0x7CB0u    /* 04DCB0 */
#define unreached_animation_04DCCC_ADDRESS 0x7CCCu    /* 04DCCC */
#define sprite_list_04DCD8_ADDRESS 0x7CD8u    /* 04DCD8 */
#define sprite_list_04DCEA_ADDRESS 0x7CEAu    /* 04DCEA */
#define unreached_animation_04DCFC_ADDRESS 0x7CFCu    /* 04DCFC */
#define sprite_list_04DD08_ADDRESS 0x7D08u    /* 04DD08 */
#define sprite_list_04DD14_ADDRESS 0x7D14u    /* 04DD14 */
#define fill_04DD20_ADDRESS 0x7D20u    /* 04DD20 */
#define unreached_animation_04DD2A_ADDRESS 0x7D2Au    /* 04DD2A */
#define sprite_list_04DD46_ADDRESS 0x7D46u    /* 04DD46 */
#define sprite_list_04DD52_ADDRESS 0x7D52u    /* 04DD52 */
#define sprite_list_04DD5E_ADDRESS 0x7D5Eu    /* 04DD5E */
#define sprite_list_04DD6A_ADDRESS 0x7D6Au    /* 04DD6A */
#define unreached_animation_04DD76_ADDRESS 0x7D76u    /* 04DD76 */
#define sprite_list_04DD92_ADDRESS 0x7D92u    /* 04DD92 */
#define sprite_list_04DDAA_ADDRESS 0x7DAAu    /* 04DDAA */
#define sprite_list_04DDC2_ADDRESS 0x7DC2u    /* 04DDC2 */
#define sprite_list_04DDDA_ADDRESS 0x7DDAu    /* 04DDDA */
#define unreached_animation_04DDF2_ADDRESS 0x7DF2u    /* 04DDF2 */
#define sprite_list_04DDFE_ADDRESS 0x7DFEu    /* 04DDFE */
#define sprite_list_04DE16_ADDRESS 0x7E16u    /* 04DE16 */
#define unreached_animation_04DE2E_ADDRESS 0x7E2Eu    /* 04DE2E */
#define sprite_list_04DE3A_ADDRESS 0x7E3Au    /* 04DE3A */
#define sprite_list_04DE46_ADDRESS 0x7E46u    /* 04DE46 */
#define unreached_animation_04DE52_ADDRESS 0x7E52u    /* 04DE52 */
#define sprite_list_04DE5E_ADDRESS 0x7E5Eu    /* 04DE5E */
#define sprite_list_04DE6A_ADDRESS 0x7E6Au    /* 04DE6A */
#define fill_04DE76_ADDRESS 0x7E76u    /* 04DE76 */
#define set_index_04E000_ADDRESS 0x6000u    /* 04E000 */
#define animation_table_04E00C_ADDRESS 0x600Cu    /* 04E00C */
#define animation_04E01E_ADDRESS 0x601Eu    /* 04E01E */
#define sprite_list_04E052_ADDRESS 0x6052u    /* 04E052 */
#define sprite_list_04E07C_ADDRESS 0x607Cu    /* 04E07C */
#define sprite_list_04E0B8_ADDRESS 0x60B8u    /* 04E0B8 */
#define sprite_list_04E0EE_ADDRESS 0x60EEu    /* 04E0EE */
#define sprite_list_04E124_ADDRESS 0x6124u    /* 04E124 */
#define sprite_list_04E14E_ADDRESS 0x614Eu    /* 04E14E */
#define sprite_list_04E184_ADDRESS 0x6184u    /* 04E184 */
#define sprite_list_04E1BA_ADDRESS 0x61BAu    /* 04E1BA */
#define sprite_list_04E1F0_ADDRESS 0x61F0u    /* 04E1F0 */
#define sprite_list_04E226_ADDRESS 0x6226u    /* 04E226 */
#define sprite_list_04E25C_ADDRESS 0x625Cu    /* 04E25C */
#define sprite_list_04E28C_ADDRESS 0x628Cu    /* 04E28C */
#define animation_04E2C8_ADDRESS 0x62C8u    /* 04E2C8 */
#define sprite_list_04E2E0_ADDRESS 0x62E0u    /* 04E2E0 */
#define sprite_list_04E316_ADDRESS 0x6316u    /* 04E316 */
#define sprite_list_04E34C_ADDRESS 0x634Cu    /* 04E34C */
#define sprite_list_04E388_ADDRESS 0x6388u    /* 04E388 */
#define sprite_list_04E3C4_ADDRESS 0x63C4u    /* 04E3C4 */
#define animation_04E3F4_ADDRESS 0x63F4u    /* 04E3F4 */
#define sprite_list_04E444_ADDRESS 0x6444u    /* 04E444 */
#define sprite_list_04E456_ADDRESS 0x6456u    /* 04E456 */
#define sprite_list_04E46E_ADDRESS 0x646Eu    /* 04E46E */
#define sprite_list_04E486_ADDRESS 0x6486u    /* 04E486 */
#define sprite_list_04E49E_ADDRESS 0x649Eu    /* 04E49E */
#define sprite_list_04E4B6_ADDRESS 0x64B6u    /* 04E4B6 */
#define animation_04E4D4_ADDRESS 0x64D4u    /* 04E4D4 */
#define sprite_list_04E4F4_ADDRESS 0x64F4u    /* 04E4F4 */
#define sprite_list_04E506_ADDRESS 0x6506u    /* 04E506 */
#define sprite_list_04E524_ADDRESS 0x6524u    /* 04E524 */
#define sprite_list_04E542_ADDRESS 0x6542u    /* 04E542 */
#define sprite_list_04E560_ADDRESS 0x6560u    /* 04E560 */
#define sprite_list_04E58A_ADDRESS 0x658Au    /* 04E58A */
#define sprite_list_04E5B4_ADDRESS 0x65B4u    /* 04E5B4 */
#define animation_04E5DE_ADDRESS 0x65DEu    /* 04E5DE */
#define sprite_list_04E606_ADDRESS 0x6606u    /* 04E606 */
#define sprite_list_04E618_ADDRESS 0x6618u    /* 04E618 */
#define sprite_list_04E636_ADDRESS 0x6636u    /* 04E636 */
#define sprite_list_04E660_ADDRESS 0x6660u    /* 04E660 */
#define sprite_list_04E67E_ADDRESS 0x667Eu    /* 04E67E */
#define sprite_list_04E69C_ADDRESS 0x669Cu    /* 04E69C */
#define sprite_list_04E6C0_ADDRESS 0x66C0u    /* 04E6C0 */
#define animation_04E6E4_ADDRESS 0x66E4u    /* 04E6E4 */
#define sprite_list_04E700_ADDRESS 0x6700u    /* 04E700 */
#define sprite_list_04E72A_ADDRESS 0x672Au    /* 04E72A */
#define sprite_list_04E754_ADDRESS 0x6754u    /* 04E754 */
#define sprite_list_04E784_ADDRESS 0x6784u    /* 04E784 */
#define sprite_list_04E7A8_ADDRESS 0x67A8u    /* 04E7A8 */
#define sprite_list_04E7D2_ADDRESS 0x67D2u    /* 04E7D2 */
#define animation_04E7FC_ADDRESS 0x67FCu    /* 04E7FC */
#define sprite_list_04E804_ADDRESS 0x6804u    /* 04E804 */
#define animation_04E83A_ADDRESS 0x683Au    /* 04E83A */
#define sprite_list_04E84A_ADDRESS 0x684Au    /* 04E84A */
#define sprite_list_04E89E_ADDRESS 0x689Eu    /* 04E89E */
#define animation_04E8EC_ADDRESS 0x68ECu    /* 04E8EC */
#define sprite_list_04E900_ADDRESS 0x6900u    /* 04E900 */
#define sprite_list_04E936_ADDRESS 0x6936u    /* 04E936 */
#define sprite_list_04E94E_ADDRESS 0x694Eu    /* 04E94E */
#define sprite_list_04E966_ADDRESS 0x6966u    /* 04E966 */
#define animation_table_04E99C_ADDRESS 0x699Cu    /* 04E99C */
#define animation_04E9F4_ADDRESS 0x69F4u    /* 04E9F4 */
#define sprite_list_04EA08_ADDRESS 0x6A08u    /* 04EA08 */
#define sprite_list_04EA0E_ADDRESS 0x6A0Eu    /* 04EA0E */
#define sprite_list_04EA14_ADDRESS 0x6A14u    /* 04EA14 */
#define sprite_list_04EA1A_ADDRESS 0x6A1Au    /* 04EA1A */
#define animation_04EA20_ADDRESS 0x6A20u    /* 04EA20 */
#define sprite_list_04EA28_ADDRESS 0x6A28u    /* 04EA28 */
#define animation_04EA2E_ADDRESS 0x6A2Eu    /* 04EA2E */
#define sprite_list_04EA42_ADDRESS 0x6A42u    /* 04EA42 */
#define sprite_list_04EA48_ADDRESS 0x6A48u    /* 04EA48 */
#define sprite_list_04EA4E_ADDRESS 0x6A4Eu    /* 04EA4E */
#define sprite_list_04EA54_ADDRESS 0x6A54u    /* 04EA54 */
#define animation_04EA5A_ADDRESS 0x6A5Au    /* 04EA5A */
#define sprite_list_04EA62_ADDRESS 0x6A62u    /* 04EA62 */
#define animation_04EA68_ADDRESS 0x6A68u    /* 04EA68 */
#define sprite_list_04EA7C_ADDRESS 0x6A7Cu    /* 04EA7C */
#define sprite_list_04EA82_ADDRESS 0x6A82u    /* 04EA82 */
#define sprite_list_04EA88_ADDRESS 0x6A88u    /* 04EA88 */
#define sprite_list_04EA8E_ADDRESS 0x6A8Eu    /* 04EA8E */
#define animation_04EA94_ADDRESS 0x6A94u    /* 04EA94 */
#define sprite_list_04EA9C_ADDRESS 0x6A9Cu    /* 04EA9C */
#define animation_04EAA2_ADDRESS 0x6AA2u    /* 04EAA2 */
#define sprite_list_04EAAE_ADDRESS 0x6AAEu    /* 04EAAE */
#define sprite_list_04EAB4_ADDRESS 0x6AB4u    /* 04EAB4 */
#define animation_04EABA_ADDRESS 0x6ABAu    /* 04EABA */
#define sprite_list_04EAC2_ADDRESS 0x6AC2u    /* 04EAC2 */
#define animation_04EAC8_ADDRESS 0x6AC8u    /* 04EAC8 */
#define sprite_list_04EADC_ADDRESS 0x6ADCu    /* 04EADC */
#define sprite_list_04EAE2_ADDRESS 0x6AE2u    /* 04EAE2 */
#define sprite_list_04EAE8_ADDRESS 0x6AE8u    /* 04EAE8 */
#define sprite_list_04EAEE_ADDRESS 0x6AEEu    /* 04EAEE */
#define animation_04EAF4_ADDRESS 0x6AF4u    /* 04EAF4 */
#define sprite_list_04EAFC_ADDRESS 0x6AFCu    /* 04EAFC */
#define animation_04EB02_ADDRESS 0x6B02u    /* 04EB02 */
#define sprite_list_04EB0A_ADDRESS 0x6B0Au    /* 04EB0A */
#define animation_04EB10_ADDRESS 0x6B10u    /* 04EB10 */
#define sprite_list_04EB18_ADDRESS 0x6B18u    /* 04EB18 */
#define animation_04EB1E_ADDRESS 0x6B1Eu    /* 04EB1E */
#define sprite_list_04EB26_ADDRESS 0x6B26u    /* 04EB26 */
#define animation_04EB2C_ADDRESS 0x6B2Cu    /* 04EB2C */
#define sprite_list_04EB34_ADDRESS 0x6B34u    /* 04EB34 */
#define animation_04EB3A_ADDRESS 0x6B3Au    /* 04EB3A */
#define sprite_list_04EB42_ADDRESS 0x6B42u    /* 04EB42 */
#define animation_04EB48_ADDRESS 0x6B48u    /* 04EB48 */
#define sprite_list_04EB50_ADDRESS 0x6B50u    /* 04EB50 */
#define animation_04EB56_ADDRESS 0x6B56u    /* 04EB56 */
#define sprite_list_04EB66_ADDRESS 0x6B66u    /* 04EB66 */
#define sprite_list_04EB7E_ADDRESS 0x6B7Eu    /* 04EB7E */
#define sprite_list_04EB96_ADDRESS 0x6B96u    /* 04EB96 */
#define animation_04EBAE_ADDRESS 0x6BAEu    /* 04EBAE */
#define sprite_list_04EBC2_ADDRESS 0x6BC2u    /* 04EBC2 */
#define sprite_list_04EBCE_ADDRESS 0x6BCEu    /* 04EBCE */
#define sprite_list_04EBDA_ADDRESS 0x6BDAu    /* 04EBDA */
#define sprite_list_04EBE6_ADDRESS 0x6BE6u    /* 04EBE6 */
#define animation_04EBF2_ADDRESS 0x6BF2u    /* 04EBF2 */
#define sprite_list_04EBFA_ADDRESS 0x6BFAu    /* 04EBFA */
#define animation_04EC00_ADDRESS 0x6C00u    /* 04EC00 */
#define sprite_list_04EC0C_ADDRESS 0x6C0Cu    /* 04EC0C */
#define sprite_list_04EC12_ADDRESS 0x6C12u    /* 04EC12 */
#define animation_04EC18_ADDRESS 0x6C18u    /* 04EC18 */
#define sprite_list_04EC20_ADDRESS 0x6C20u    /* 04EC20 */
#define animation_04EC26_ADDRESS 0x6C26u    /* 04EC26 */
#define animation_04EC2E_ADDRESS 0x6C2Eu    /* 04EC2E */
#define sprite_list_04EC36_ADDRESS 0x6C36u    /* 04EC36 */
#define animation_04EC3C_ADDRESS 0x6C3Cu    /* 04EC3C */
#define sprite_list_04EC44_ADDRESS 0x6C44u    /* 04EC44 */
#define animation_04EC4A_ADDRESS 0x6C4Au    /* 04EC4A */
#define sprite_list_04EC56_ADDRESS 0x6C56u    /* 04EC56 */
#define sprite_list_04EC5C_ADDRESS 0x6C5Cu    /* 04EC5C */
#define animation_04EC62_ADDRESS 0x6C62u    /* 04EC62 */
#define sprite_list_04EC86_ADDRESS 0x6C86u    /* 04EC86 */
#define sprite_list_04EC9E_ADDRESS 0x6C9Eu    /* 04EC9E */
#define sprite_list_04ECBC_ADDRESS 0x6CBCu    /* 04ECBC */
#define sprite_list_04ECDA_ADDRESS 0x6CDAu    /* 04ECDA */
#define sprite_list_04ECF8_ADDRESS 0x6CF8u    /* 04ECF8 */
#define animation_04ED16_ADDRESS 0x6D16u    /* 04ED16 */
#define sprite_list_04ED2A_ADDRESS 0x6D2Au    /* 04ED2A */
#define sprite_list_04ED36_ADDRESS 0x6D36u    /* 04ED36 */
#define sprite_list_04ED42_ADDRESS 0x6D42u    /* 04ED42 */
#define sprite_list_04ED4E_ADDRESS 0x6D4Eu    /* 04ED4E */
#define animation_04ED5A_ADDRESS 0x6D5Au    /* 04ED5A */
#define sprite_list_04ED6E_ADDRESS 0x6D6Eu    /* 04ED6E */
#define sprite_list_04ED86_ADDRESS 0x6D86u    /* 04ED86 */
#define sprite_list_04EDA4_ADDRESS 0x6DA4u    /* 04EDA4 */
#define animation_04EDC2_ADDRESS 0x6DC2u    /* 04EDC2 */
#define sprite_list_04EDD2_ADDRESS 0x6DD2u    /* 04EDD2 */
#define sprite_list_04EDEA_ADDRESS 0x6DEAu    /* 04EDEA */
#define sprite_list_04EE02_ADDRESS 0x6E02u    /* 04EE02 */
#define animation_04EE20_ADDRESS 0x6E20u    /* 04EE20 */
#define animation_04EE28_ADDRESS 0x6E28u    /* 04EE28 */
#define sprite_list_04EE4C_ADDRESS 0x6E4Cu    /* 04EE4C */
#define sprite_list_04EE52_ADDRESS 0x6E52u    /* 04EE52 */
#define sprite_list_04EE58_ADDRESS 0x6E58u    /* 04EE58 */
#define sprite_list_04EE5E_ADDRESS 0x6E5Eu    /* 04EE5E */
#define sprite_list_04EE64_ADDRESS 0x6E64u    /* 04EE64 */
#define sprite_list_04EE6A_ADDRESS 0x6E6Au    /* 04EE6A */
#define sprite_list_04EE70_ADDRESS 0x6E70u    /* 04EE70 */
#define sprite_list_04EE76_ADDRESS 0x6E76u    /* 04EE76 */
#define animation_04EE7C_ADDRESS 0x6E7Cu    /* 04EE7C */
#define animation_04EE84_ADDRESS 0x6E84u    /* 04EE84 */
#define sprite_list_04EE98_ADDRESS 0x6E98u    /* 04EE98 */
#define sprite_list_04EE9E_ADDRESS 0x6E9Eu    /* 04EE9E */
#define sprite_list_04EEA4_ADDRESS 0x6EA4u    /* 04EEA4 */
#define sprite_list_04EEAA_ADDRESS 0x6EAAu    /* 04EEAA */
#define animation_04EEB0_ADDRESS 0x6EB0u    /* 04EEB0 */
#define sprite_list_04EEB8_ADDRESS 0x6EB8u    /* 04EEB8 */
#define animation_table_04EEBE_ADDRESS 0x6EBEu    /* 04EEBE */
#define animation_04EF2E_ADDRESS 0x6F2Eu    /* 04EF2E */
#define sprite_list_04EF4A_ADDRESS 0x6F4Au    /* 04EF4A */
#define sprite_list_04EF50_ADDRESS 0x6F50u    /* 04EF50 */
#define sprite_list_04EF56_ADDRESS 0x6F56u    /* 04EF56 */
#define animation_04EF5C_ADDRESS 0x6F5Cu    /* 04EF5C */
#define sprite_list_04EF64_ADDRESS 0x6F64u    /* 04EF64 */
#define animation_04EF70_ADDRESS 0x6F70u    /* 04EF70 */
#define sprite_list_04EF78_ADDRESS 0x6F78u    /* 04EF78 */
#define animation_04EF84_ADDRESS 0x6F84u    /* 04EF84 */
#define sprite_list_04EF8C_ADDRESS 0x6F8Cu    /* 04EF8C */
#define animation_04EF98_ADDRESS 0x6F98u    /* 04EF98 */
#define sprite_list_04EFA0_ADDRESS 0x6FA0u    /* 04EFA0 */
#define animation_04EFAC_ADDRESS 0x6FACu    /* 04EFAC */
#define sprite_list_04EFB4_ADDRESS 0x6FB4u    /* 04EFB4 */
#define animation_04EFBA_ADDRESS 0x6FBAu    /* 04EFBA */
#define sprite_list_04EFCE_ADDRESS 0x6FCEu    /* 04EFCE */
#define sprite_list_04EFD4_ADDRESS 0x6FD4u    /* 04EFD4 */
#define sprite_list_04EFDA_ADDRESS 0x6FDAu    /* 04EFDA */
#define sprite_list_04EFE0_ADDRESS 0x6FE0u    /* 04EFE0 */
#define animation_04EFE6_ADDRESS 0x6FE6u    /* 04EFE6 */
#define sprite_list_04EFEE_ADDRESS 0x6FEEu    /* 04EFEE */
#define animation_04EFFA_ADDRESS 0x6FFAu    /* 04EFFA */
#define sprite_list_04F002_ADDRESS 0x7002u    /* 04F002 */
#define animation_04F00E_ADDRESS 0x700Eu    /* 04F00E */
#define sprite_list_04F016_ADDRESS 0x7016u    /* 04F016 */
#define animation_04F01C_ADDRESS 0x701Cu    /* 04F01C */
#define animation_04F024_ADDRESS 0x7024u    /* 04F024 */
#define sprite_list_04F038_ADDRESS 0x7038u    /* 04F038 */
#define sprite_list_04F03E_ADDRESS 0x703Eu    /* 04F03E */
#define sprite_list_04F044_ADDRESS 0x7044u    /* 04F044 */
#define animation_04F04A_ADDRESS 0x704Au    /* 04F04A */
#define animation_04F05E_ADDRESS 0x705Eu    /* 04F05E */
#define sprite_list_04F066_ADDRESS 0x7066u    /* 04F066 */
#define animation_04F06C_ADDRESS 0x706Cu    /* 04F06C */
#define sprite_list_04F074_ADDRESS 0x7074u    /* 04F074 */
#define animation_04F07A_ADDRESS 0x707Au    /* 04F07A */
#define sprite_list_04F082_ADDRESS 0x7082u    /* 04F082 */
#define animation_04F088_ADDRESS 0x7088u    /* 04F088 */
#define sprite_list_04F090_ADDRESS 0x7090u    /* 04F090 */
#define animation_04F096_ADDRESS 0x7096u    /* 04F096 */
#define sprite_list_04F0A2_ADDRESS 0x70A2u    /* 04F0A2 */
#define sprite_list_04F0A8_ADDRESS 0x70A8u    /* 04F0A8 */
#define animation_04F0AE_ADDRESS 0x70AEu    /* 04F0AE */
#define sprite_list_04F0BE_ADDRESS 0x70BEu    /* 04F0BE */
#define sprite_list_04F0CA_ADDRESS 0x70CAu    /* 04F0CA */
#define sprite_list_04F0D6_ADDRESS 0x70D6u    /* 04F0D6 */
#define animation_04F0E2_ADDRESS 0x70E2u    /* 04F0E2 */
#define sprite_list_04F0F6_ADDRESS 0x70F6u    /* 04F0F6 */
#define sprite_list_04F0FC_ADDRESS 0x70FCu    /* 04F0FC */
#define sprite_list_04F102_ADDRESS 0x7102u    /* 04F102 */
#define animation_04F114_ADDRESS 0x7114u    /* 04F114 */
#define sprite_list_04F128_ADDRESS 0x7128u    /* 04F128 */
#define sprite_list_04F134_ADDRESS 0x7134u    /* 04F134 */
#define sprite_list_04F140_ADDRESS 0x7140u    /* 04F140 */
#define animation_04F158_ADDRESS 0x7158u    /* 04F158 */
#define sprite_list_04F160_ADDRESS 0x7160u    /* 04F160 */
#define animation_04F166_ADDRESS 0x7166u    /* 04F166 */
#define sprite_list_04F17E_ADDRESS 0x717Eu    /* 04F17E */
#define sprite_list_04F18A_ADDRESS 0x718Au    /* 04F18A */
#define sprite_list_04F196_ADDRESS 0x7196u    /* 04F196 */
#define sprite_list_04F1A2_ADDRESS 0x71A2u    /* 04F1A2 */
#define sprite_list_04F1AE_ADDRESS 0x71AEu    /* 04F1AE */
#define animation_04F1C0_ADDRESS 0x71C0u    /* 04F1C0 */
#define animation_04F1C8_ADDRESS 0x71C8u    /* 04F1C8 */
#define animation_04F1D0_ADDRESS 0x71D0u    /* 04F1D0 */
#define sprite_list_04F1D8_ADDRESS 0x71D8u    /* 04F1D8 */
#define animation_04F1DE_ADDRESS 0x71DEu    /* 04F1DE */
#define sprite_list_04F1F6_ADDRESS 0x71F6u    /* 04F1F6 */
#define sprite_list_04F202_ADDRESS 0x7202u    /* 04F202 */
#define sprite_list_04F20E_ADDRESS 0x720Eu    /* 04F20E */
#define sprite_list_04F21A_ADDRESS 0x721Au    /* 04F21A */
#define sprite_list_04F226_ADDRESS 0x7226u    /* 04F226 */
#define animation_04F238_ADDRESS 0x7238u    /* 04F238 */
#define animation_04F240_ADDRESS 0x7240u    /* 04F240 */
#define animation_04F248_ADDRESS 0x7248u    /* 04F248 */
#define sprite_list_04F250_ADDRESS 0x7250u    /* 04F250 */
#define animation_04F256_ADDRESS 0x7256u    /* 04F256 */
#define sprite_list_04F26E_ADDRESS 0x726Eu    /* 04F26E */
#define sprite_list_04F27A_ADDRESS 0x727Au    /* 04F27A */
#define sprite_list_04F286_ADDRESS 0x7286u    /* 04F286 */
#define sprite_list_04F292_ADDRESS 0x7292u    /* 04F292 */
#define sprite_list_04F29E_ADDRESS 0x729Eu    /* 04F29E */
#define animation_04F2B0_ADDRESS 0x72B0u    /* 04F2B0 */
#define animation_04F2B8_ADDRESS 0x72B8u    /* 04F2B8 */
#define animation_04F2C0_ADDRESS 0x72C0u    /* 04F2C0 */
#define sprite_list_04F2C8_ADDRESS 0x72C8u    /* 04F2C8 */
#define animation_04F2CE_ADDRESS 0x72CEu    /* 04F2CE */
#define sprite_list_04F2E6_ADDRESS 0x72E6u    /* 04F2E6 */
#define sprite_list_04F2F2_ADDRESS 0x72F2u    /* 04F2F2 */
#define sprite_list_04F2FE_ADDRESS 0x72FEu    /* 04F2FE */
#define sprite_list_04F30A_ADDRESS 0x730Au    /* 04F30A */
#define sprite_list_04F316_ADDRESS 0x7316u    /* 04F316 */
#define animation_04F328_ADDRESS 0x7328u    /* 04F328 */
#define animation_04F330_ADDRESS 0x7330u    /* 04F330 */
#define animation_04F338_ADDRESS 0x7338u    /* 04F338 */
#define sprite_list_04F340_ADDRESS 0x7340u    /* 04F340 */
#define animation_04F346_ADDRESS 0x7346u    /* 04F346 */
#define sprite_list_04F35E_ADDRESS 0x735Eu    /* 04F35E */
#define sprite_list_04F36A_ADDRESS 0x736Au    /* 04F36A */
#define sprite_list_04F376_ADDRESS 0x7376u    /* 04F376 */
#define sprite_list_04F382_ADDRESS 0x7382u    /* 04F382 */
#define sprite_list_04F38E_ADDRESS 0x738Eu    /* 04F38E */
#define animation_04F3A0_ADDRESS 0x73A0u    /* 04F3A0 */
#define animation_04F3A8_ADDRESS 0x73A8u    /* 04F3A8 */
#define animation_04F3B0_ADDRESS 0x73B0u    /* 04F3B0 */
#define sprite_list_04F3B8_ADDRESS 0x73B8u    /* 04F3B8 */
#define animation_04F3BE_ADDRESS 0x73BEu    /* 04F3BE */
#define sprite_list_04F3D6_ADDRESS 0x73D6u    /* 04F3D6 */
#define sprite_list_04F3E2_ADDRESS 0x73E2u    /* 04F3E2 */
#define sprite_list_04F3EE_ADDRESS 0x73EEu    /* 04F3EE */
#define sprite_list_04F3FA_ADDRESS 0x73FAu    /* 04F3FA */
#define sprite_list_04F406_ADDRESS 0x7406u    /* 04F406 */
#define animation_04F418_ADDRESS 0x7418u    /* 04F418 */
#define animation_04F420_ADDRESS 0x7420u    /* 04F420 */
#define animation_04F428_ADDRESS 0x7428u    /* 04F428 */
#define sprite_list_04F430_ADDRESS 0x7430u    /* 04F430 */
#define animation_04F436_ADDRESS 0x7436u    /* 04F436 */
#define sprite_list_04F44E_ADDRESS 0x744Eu    /* 04F44E */
#define sprite_list_04F45A_ADDRESS 0x745Au    /* 04F45A */
#define sprite_list_04F466_ADDRESS 0x7466u    /* 04F466 */
#define sprite_list_04F472_ADDRESS 0x7472u    /* 04F472 */
#define sprite_list_04F47E_ADDRESS 0x747Eu    /* 04F47E */
#define animation_04F490_ADDRESS 0x7490u    /* 04F490 */
#define animation_04F498_ADDRESS 0x7498u    /* 04F498 */
#define animation_04F4A0_ADDRESS 0x74A0u    /* 04F4A0 */
#define sprite_list_04F4A8_ADDRESS 0x74A8u    /* 04F4A8 */
#define animation_04F4AE_ADDRESS 0x74AEu    /* 04F4AE */
#define sprite_list_04F4B6_ADDRESS 0x74B6u    /* 04F4B6 */
#define animation_04F4BC_ADDRESS 0x74BCu    /* 04F4BC */
#define sprite_list_04F4D0_ADDRESS 0x74D0u    /* 04F4D0 */
#define sprite_list_04F4D6_ADDRESS 0x74D6u    /* 04F4D6 */
#define sprite_list_04F4DC_ADDRESS 0x74DCu    /* 04F4DC */
#define sprite_list_04F4E2_ADDRESS 0x74E2u    /* 04F4E2 */
#define animation_04F4E8_ADDRESS 0x74E8u    /* 04F4E8 */
#define animation_04F4F0_ADDRESS 0x74F0u    /* 04F4F0 */
#define sprite_list_04F504_ADDRESS 0x7504u    /* 04F504 */
#define sprite_list_04F516_ADDRESS 0x7516u    /* 04F516 */
#define sprite_list_04F528_ADDRESS 0x7528u    /* 04F528 */
#define sprite_list_04F53A_ADDRESS 0x753Au    /* 04F53A */
#define animation_table_04F54C_ADDRESS 0x754Cu    /* 04F54C */
#define animation_04F550_ADDRESS 0x7550u    /* 04F550 */
#define sprite_list_04F558_ADDRESS 0x7558u    /* 04F558 */
#define animation_04F564_ADDRESS 0x7564u    /* 04F564 */
#define sprite_list_04F56C_ADDRESS 0x756Cu    /* 04F56C */
#define animation_table_04F58A_ADDRESS 0x758Au    /* 04F58A */
#define animation_04F59E_ADDRESS 0x759Eu    /* 04F59E */
#define sprite_list_04F5B2_ADDRESS 0x75B2u    /* 04F5B2 */
#define sprite_list_04F5CA_ADDRESS 0x75CAu    /* 04F5CA */
#define sprite_list_04F5E2_ADDRESS 0x75E2u    /* 04F5E2 */
#define sprite_list_04F5FA_ADDRESS 0x75FAu    /* 04F5FA */
#define animation_04F612_ADDRESS 0x7612u    /* 04F612 */
#define animation_04F626_ADDRESS 0x7626u    /* 04F626 */
#define sprite_list_04F63A_ADDRESS 0x763Au    /* 04F63A */
#define sprite_list_04F64C_ADDRESS 0x764Cu    /* 04F64C */
#define sprite_list_04F664_ADDRESS 0x7664u    /* 04F664 */
#define animation_04F67C_ADDRESS 0x767Cu    /* 04F67C */
#define sprite_list_04F6D0_ADDRESS 0x76D0u    /* 04F6D0 */
#define sprite_list_04F6E8_ADDRESS 0x76E8u    /* 04F6E8 */
#define sprite_list_04F700_ADDRESS 0x7700u    /* 04F700 */
#define sprite_list_04F718_ADDRESS 0x7718u    /* 04F718 */
#define sprite_list_04F730_ADDRESS 0x7730u    /* 04F730 */
#define sprite_list_04F760_ADDRESS 0x7760u    /* 04F760 */
#define sprite_list_04F796_ADDRESS 0x7796u    /* 04F796 */
#define sprite_list_04F7BA_ADDRESS 0x77BAu    /* 04F7BA */
#define sprite_list_04F7D8_ADDRESS 0x77D8u    /* 04F7D8 */
#define sprite_list_04F7F6_ADDRESS 0x77F6u    /* 04F7F6 */
#define sprite_list_04F814_ADDRESS 0x7814u    /* 04F814 */
#define sprite_list_04F832_ADDRESS 0x7832u    /* 04F832 */
#define sprite_list_04F850_ADDRESS 0x7850u    /* 04F850 */
#define sprite_list_04F86E_ADDRESS 0x786Eu    /* 04F86E */
#define sprite_list_04F88C_ADDRESS 0x788Cu    /* 04F88C */
#define sprite_list_04F8AA_ADDRESS 0x78AAu    /* 04F8AA */
#define sprite_list_04F8C8_ADDRESS 0x78C8u    /* 04F8C8 */
#define animation_04F8E6_ADDRESS 0x78E6u    /* 04F8E6 */
#define sprite_list_04F906_ADDRESS 0x7906u    /* 04F906 */
#define sprite_list_04F90C_ADDRESS 0x790Cu    /* 04F90C */
#define sprite_list_04F912_ADDRESS 0x7912u    /* 04F912 */
#define sprite_list_04F918_ADDRESS 0x7918u    /* 04F918 */
#define sprite_list_04F924_ADDRESS 0x7924u    /* 04F924 */
#define sprite_list_04F92A_ADDRESS 0x792Au    /* 04F92A */
#define sprite_list_04F954_ADDRESS 0x7954u    /* 04F954 */
#define animation_04F97E_ADDRESS 0x797Eu    /* 04F97E */
#define sprite_list_04F99E_ADDRESS 0x799Eu    /* 04F99E */
#define sprite_list_04F9C2_ADDRESS 0x79C2u    /* 04F9C2 */
#define sprite_list_04F9E0_ADDRESS 0x79E0u    /* 04F9E0 */
#define sprite_list_04F9FE_ADDRESS 0x79FEu    /* 04F9FE */
#define sprite_list_04FA1C_ADDRESS 0x7A1Cu    /* 04FA1C */
#define sprite_list_04FA3A_ADDRESS 0x7A3Au    /* 04FA3A */
#define animation_04FA58_ADDRESS 0x7A58u    /* 04FA58 */
#define sprite_list_04FA7C_ADDRESS 0x7A7Cu    /* 04FA7C */
#define sprite_list_04FA8E_ADDRESS 0x7A8Eu    /* 04FA8E */
#define sprite_list_04FAA6_ADDRESS 0x7AA6u    /* 04FAA6 */
#define sprite_list_04FABE_ADDRESS 0x7ABEu    /* 04FABE */
#define sprite_list_04FAD0_ADDRESS 0x7AD0u    /* 04FAD0 */
#define sprite_list_04FAE2_ADDRESS 0x7AE2u    /* 04FAE2 */
#define sprite_list_04FAFA_ADDRESS 0x7AFAu    /* 04FAFA */
#define animation_04FB12_ADDRESS 0x7B12u    /* 04FB12 */
#define sprite_list_04FB26_ADDRESS 0x7B26u    /* 04FB26 */
#define sprite_list_04FB38_ADDRESS 0x7B38u    /* 04FB38 */
#define sprite_list_04FB4A_ADDRESS 0x7B4Au    /* 04FB4A */
#define animation_04FB62_ADDRESS 0x7B62u    /* 04FB62 */
#define sprite_list_04FB7E_ADDRESS 0x7B7Eu    /* 04FB7E */
#define sprite_list_04FB9C_ADDRESS 0x7B9Cu    /* 04FB9C */
#define sprite_list_04FBBA_ADDRESS 0x7BBAu    /* 04FBBA */
#define sprite_list_04FBC6_ADDRESS 0x7BC6u    /* 04FBC6 */
#define sprite_list_04FBD2_ADDRESS 0x7BD2u    /* 04FBD2 */
#define sprite_list_04FBDE_ADDRESS 0x7BDEu    /* 04FBDE */
#define animation_04FBF0_ADDRESS 0x7BF0u    /* 04FBF0 */
#define sprite_list_04FC28_ADDRESS 0x7C28u    /* 04FC28 */
#define sprite_list_04FC2E_ADDRESS 0x7C2Eu    /* 04FC2E */
#define sprite_list_04FC34_ADDRESS 0x7C34u    /* 04FC34 */
#define sprite_list_04FC40_ADDRESS 0x7C40u    /* 04FC40 */
#define sprite_list_04FC46_ADDRESS 0x7C46u    /* 04FC46 */
#define sprite_list_04FC52_ADDRESS 0x7C52u    /* 04FC52 */
#define animation_table_04FC5E_ADDRESS 0x7C5Eu    /* 04FC5E */
#define animation_04FC66_ADDRESS 0x7C66u    /* 04FC66 */
#define sprite_list_04FC6E_ADDRESS 0x7C6Eu    /* 04FC6E */
#define animation_04FC7A_ADDRESS 0x7C7Au    /* 04FC7A */
#define sprite_list_04FC82_ADDRESS 0x7C82u    /* 04FC82 */
#define animation_04FC8E_ADDRESS 0x7C8Eu    /* 04FC8E */
#define sprite_list_04FC96_ADDRESS 0x7C96u    /* 04FC96 */
#define animation_04FCA2_ADDRESS 0x7CA2u    /* 04FCA2 */
#define sprite_list_04FCAA_ADDRESS 0x7CAAu    /* 04FCAA */
#define fill_04FCB6_ADDRESS 0x7CB6u    /* 04FCB6 */
#define unreached_animation_04FCCC_ADDRESS 0x7CCCu    /* 04FCCC */
#define sprite_list_04FCD8_ADDRESS 0x7CD8u    /* 04FCD8 */
#define sprite_list_04FCEA_ADDRESS 0x7CEAu    /* 04FCEA */
#define unreached_animation_04FCFC_ADDRESS 0x7CFCu    /* 04FCFC */
#define sprite_list_04FD08_ADDRESS 0x7D08u    /* 04FD08 */
#define sprite_list_04FD14_ADDRESS 0x7D14u    /* 04FD14 */
#define fill_04FD20_ADDRESS 0x7D20u    /* 04FD20 */
#define unreached_animation_04FD2A_ADDRESS 0x7D2Au    /* 04FD2A */
#define sprite_list_04FD46_ADDRESS 0x7D46u    /* 04FD46 */
#define sprite_list_04FD52_ADDRESS 0x7D52u    /* 04FD52 */
#define sprite_list_04FD5E_ADDRESS 0x7D5Eu    /* 04FD5E */
#define sprite_list_04FD6A_ADDRESS 0x7D6Au    /* 04FD6A */
#define unreached_animation_04FD76_ADDRESS 0x7D76u    /* 04FD76 */
#define sprite_list_04FD92_ADDRESS 0x7D92u    /* 04FD92 */
#define sprite_list_04FDAA_ADDRESS 0x7DAAu    /* 04FDAA */
#define sprite_list_04FDC2_ADDRESS 0x7DC2u    /* 04FDC2 */
#define sprite_list_04FDDA_ADDRESS 0x7DDAu    /* 04FDDA */
#define unreached_animation_04FDF2_ADDRESS 0x7DF2u    /* 04FDF2 */
#define sprite_list_04FDFE_ADDRESS 0x7DFEu    /* 04FDFE */
#define sprite_list_04FE16_ADDRESS 0x7E16u    /* 04FE16 */
#define unreached_animation_04FE2E_ADDRESS 0x7E2Eu    /* 04FE2E */
#define sprite_list_04FE3A_ADDRESS 0x7E3Au    /* 04FE3A */
#define sprite_list_04FE46_ADDRESS 0x7E46u    /* 04FE46 */
#define unreached_animation_04FE52_ADDRESS 0x7E52u    /* 04FE52 */
#define sprite_list_04FE5E_ADDRESS 0x7E5Eu    /* 04FE5E */
#define sprite_list_04FE6A_ADDRESS 0x7E6Au    /* 04FE6A */
#define fill_04FE76_ADDRESS 0x7E76u    /* 04FE76 */
#define set_index_050000_ADDRESS 0x6000u    /* 050000 */
#define animation_table_05000C_ADDRESS 0x600Cu    /* 05000C */
#define animation_05002E_ADDRESS 0x602Eu    /* 05002E */
#define sprite_list_05005A_ADDRESS 0x605Au    /* 05005A */
#define sprite_list_050072_ADDRESS 0x6072u    /* 050072 */
#define sprite_list_050090_ADDRESS 0x6090u    /* 050090 */
#define sprite_list_0500AE_ADDRESS 0x60AEu    /* 0500AE */
#define sprite_list_0500CC_ADDRESS 0x60CCu    /* 0500CC */
#define sprite_list_0500F0_ADDRESS 0x60F0u    /* 0500F0 */
#define sprite_list_050114_ADDRESS 0x6114u    /* 050114 */
#define sprite_list_050132_ADDRESS 0x6132u    /* 050132 */
#define sprite_list_050150_ADDRESS 0x6150u    /* 050150 */
#define sprite_list_05016E_ADDRESS 0x616Eu    /* 05016E */
#define animation_05018C_ADDRESS 0x618Cu    /* 05018C */
#define sprite_list_050198_ADDRESS 0x6198u    /* 050198 */
#define sprite_list_0501AA_ADDRESS 0x61AAu    /* 0501AA */
#define animation_0501BC_ADDRESS 0x61BCu    /* 0501BC */
#define sprite_list_0501F8_ADDRESS 0x61F8u    /* 0501F8 */
#define sprite_list_050216_ADDRESS 0x6216u    /* 050216 */
#define sprite_list_050234_ADDRESS 0x6234u    /* 050234 */
#define sprite_list_05024C_ADDRESS 0x624Cu    /* 05024C */
#define sprite_list_050264_ADDRESS 0x6264u    /* 050264 */
#define sprite_list_05027C_ADDRESS 0x627Cu    /* 05027C */
#define sprite_list_05028E_ADDRESS 0x628Eu    /* 05028E */
#define sprite_list_0502A6_ADDRESS 0x62A6u    /* 0502A6 */
#define animation_0502B8_ADDRESS 0x62B8u    /* 0502B8 */
#define sprite_list_0502D4_ADDRESS 0x62D4u    /* 0502D4 */
#define sprite_list_0502E6_ADDRESS 0x62E6u    /* 0502E6 */
#define sprite_list_0502F8_ADDRESS 0x62F8u    /* 0502F8 */
#define sprite_list_050310_ADDRESS 0x6310u    /* 050310 */
#define animation_050328_ADDRESS 0x6328u    /* 050328 */
#define sprite_list_050344_ADDRESS 0x6344u    /* 050344 */
#define sprite_list_050356_ADDRESS 0x6356u    /* 050356 */
#define sprite_list_050368_ADDRESS 0x6368u    /* 050368 */
#define sprite_list_05037A_ADDRESS 0x637Au    /* 05037A */
#define sprite_list_05038C_ADDRESS 0x638Cu    /* 05038C */
#define sprite_list_05039E_ADDRESS 0x639Eu    /* 05039E */
#define animation_0503B0_ADDRESS 0x63B0u    /* 0503B0 */
#define sprite_list_0503D8_ADDRESS 0x63D8u    /* 0503D8 */
#define sprite_list_0503F0_ADDRESS 0x63F0u    /* 0503F0 */
#define sprite_list_050402_ADDRESS 0x6402u    /* 050402 */
#define sprite_list_050420_ADDRESS 0x6420u    /* 050420 */
#define sprite_list_05043E_ADDRESS 0x643Eu    /* 05043E */
#define sprite_list_05045C_ADDRESS 0x645Cu    /* 05045C */
#define animation_05047A_ADDRESS 0x647Au    /* 05047A */
#define sprite_list_0504CE_ADDRESS 0x64CEu    /* 0504CE */
#define sprite_list_0504E0_ADDRESS 0x64E0u    /* 0504E0 */
#define sprite_list_0504F2_ADDRESS 0x64F2u    /* 0504F2 */
#define sprite_list_050504_ADDRESS 0x6504u    /* 050504 */
#define sprite_list_050516_ADDRESS 0x6516u    /* 050516 */
#define sprite_list_050528_ADDRESS 0x6528u    /* 050528 */
#define sprite_list_05053A_ADDRESS 0x653Au    /* 05053A */
#define sprite_list_05054C_ADDRESS 0x654Cu    /* 05054C */
#define animation_table_05055E_ADDRESS 0x655Eu    /* 05055E */
#define animation_050566_ADDRESS 0x6566u    /* 050566 */
#define sprite_list_050572_ADDRESS 0x6572u    /* 050572 */
#define sprite_list_050584_ADDRESS 0x6584u    /* 050584 */
#define animation_050596_ADDRESS 0x6596u    /* 050596 */
#define sprite_list_0505BA_ADDRESS 0x65BAu    /* 0505BA */
#define sprite_list_0505CC_ADDRESS 0x65CCu    /* 0505CC */
#define sprite_list_0505DE_ADDRESS 0x65DEu    /* 0505DE */
#define sprite_list_0505F0_ADDRESS 0x65F0u    /* 0505F0 */
#define sprite_list_050602_ADDRESS 0x6602u    /* 050602 */
#define animation_050614_ADDRESS 0x6614u    /* 050614 */
#define sprite_list_050620_ADDRESS 0x6620u    /* 050620 */
#define sprite_list_050632_ADDRESS 0x6632u    /* 050632 */
#define animation_050644_ADDRESS 0x6644u    /* 050644 */
#define sprite_list_050668_ADDRESS 0x6668u    /* 050668 */
#define sprite_list_05067A_ADDRESS 0x667Au    /* 05067A */
#define sprite_list_05068C_ADDRESS 0x668Cu    /* 05068C */
#define sprite_list_05069E_ADDRESS 0x669Eu    /* 05069E */
#define sprite_list_0506B0_ADDRESS 0x66B0u    /* 0506B0 */
#define animation_table_0506C2_ADDRESS 0x66C2u    /* 0506C2 */
#define animation_0506C6_ADDRESS 0x66C6u    /* 0506C6 */
#define sprite_list_0506D2_ADDRESS 0x66D2u    /* 0506D2 */
#define sprite_list_0506EA_ADDRESS 0x66EAu    /* 0506EA */
#define animation_050702_ADDRESS 0x6702u    /* 050702 */
#define sprite_list_050726_ADDRESS 0x6726u    /* 050726 */
#define sprite_list_05073E_ADDRESS 0x673Eu    /* 05073E */
#define sprite_list_050756_ADDRESS 0x6756u    /* 050756 */
#define sprite_list_05076E_ADDRESS 0x676Eu    /* 05076E */
#define sprite_list_050786_ADDRESS 0x6786u    /* 050786 */
#define animation_table_0507AA_ADDRESS 0x67AAu    /* 0507AA */
#define animation_0507AE_ADDRESS 0x67AEu    /* 0507AE */
#define sprite_list_0507C2_ADDRESS 0x67C2u    /* 0507C2 */
#define sprite_list_0507D4_ADDRESS 0x67D4u    /* 0507D4 */
#define sprite_list_0507E6_ADDRESS 0x67E6u    /* 0507E6 */
#define animation_050804_ADDRESS 0x6804u    /* 050804 */
#define sprite_list_050810_ADDRESS 0x6810u    /* 050810 */
#define animation_table_05083A_ADDRESS 0x683Au    /* 05083A */
#define animation_05085E_ADDRESS 0x685Eu    /* 05085E */
#define sprite_list_050872_ADDRESS 0x6872u    /* 050872 */
#define sprite_list_0508B4_ADDRESS 0x68B4u    /* 0508B4 */
#define sprite_list_0508F6_ADDRESS 0x68F6u    /* 0508F6 */
#define sprite_list_050938_ADDRESS 0x6938u    /* 050938 */
#define animation_05097A_ADDRESS 0x697Au    /* 05097A */
#define animation_050986_ADDRESS 0x6986u    /* 050986 */
#define sprite_list_0509A6_ADDRESS 0x69A6u    /* 0509A6 */
#define sprite_list_0509EE_ADDRESS 0x69EEu    /* 0509EE */
#define sprite_list_050A30_ADDRESS 0x6A30u    /* 050A30 */
#define sprite_list_050A78_ADDRESS 0x6A78u    /* 050A78 */
#define sprite_list_050AC6_ADDRESS 0x6AC6u    /* 050AC6 */
#define sprite_list_050B1A_ADDRESS 0x6B1Au    /* 050B1A */
#define sprite_list_050B68_ADDRESS 0x6B68u    /* 050B68 */
#define animation_050BB6_ADDRESS 0x6BB6u    /* 050BB6 */
#define sprite_list_050BCA_ADDRESS 0x6BCAu    /* 050BCA */
#define sprite_list_050C18_ADDRESS 0x6C18u    /* 050C18 */
#define sprite_list_050C66_ADDRESS 0x6C66u    /* 050C66 */
#define animation_050CBA_ADDRESS 0x6CBAu    /* 050CBA */
#define sprite_list_050CC6_ADDRESS 0x6CC6u    /* 050CC6 */
#define sprite_list_050D0E_ADDRESS 0x6D0Eu    /* 050D0E */
#define animation_050D56_ADDRESS 0x6D56u    /* 050D56 */
#define sprite_list_050D7A_ADDRESS 0x6D7Au    /* 050D7A */
#define sprite_list_050DC2_ADDRESS 0x6DC2u    /* 050DC2 */
#define sprite_list_050E04_ADDRESS 0x6E04u    /* 050E04 */
#define sprite_list_050E5E_ADDRESS 0x6E5Eu    /* 050E5E */
#define sprite_list_050E8E_ADDRESS 0x6E8Eu    /* 050E8E */
#define sprite_list_050ECA_ADDRESS 0x6ECAu    /* 050ECA */
#define sprite_list_050F06_ADDRESS 0x6F06u    /* 050F06 */
#define animation_050F42_ADDRESS 0x6F42u    /* 050F42 */
#define sprite_list_050F5E_ADDRESS 0x6F5Eu    /* 050F5E */
#define sprite_list_050FB2_ADDRESS 0x6FB2u    /* 050FB2 */
#define sprite_list_051006_ADDRESS 0x7006u    /* 051006 */
#define sprite_list_051060_ADDRESS 0x7060u    /* 051060 */
#define sprite_list_0510BA_ADDRESS 0x70BAu    /* 0510BA */
#define animation_051114_ADDRESS 0x7114u    /* 051114 */
#define sprite_list_051150_ADDRESS 0x7150u    /* 051150 */
#define sprite_list_051192_ADDRESS 0x7192u    /* 051192 */
#define sprite_list_0511DA_ADDRESS 0x71DAu    /* 0511DA */
#define sprite_list_051222_ADDRESS 0x7222u    /* 051222 */
#define sprite_list_051276_ADDRESS 0x7276u    /* 051276 */
#define sprite_list_0512CA_ADDRESS 0x72CAu    /* 0512CA */
#define sprite_list_05132A_ADDRESS 0x732Au    /* 05132A */
#define sprite_list_05138A_ADDRESS 0x738Au    /* 05138A */
#define animation_0513EA_ADDRESS 0x73EAu    /* 0513EA */
#define sprite_list_0513FA_ADDRESS 0x73FAu    /* 0513FA */
#define sprite_list_051400_ADDRESS 0x7400u    /* 051400 */
#define sprite_list_051406_ADDRESS 0x7406u    /* 051406 */
#define animation_05140C_ADDRESS 0x740Cu    /* 05140C */
#define sprite_list_051418_ADDRESS 0x7418u    /* 051418 */
#define sprite_list_05145A_ADDRESS 0x745Au    /* 05145A */
#define animation_05149C_ADDRESS 0x749Cu    /* 05149C */
#define sprite_list_0514AC_ADDRESS 0x74ACu    /* 0514AC */
#define sprite_list_0514F4_ADDRESS 0x74F4u    /* 0514F4 */
#define animation_051536_ADDRESS 0x7536u    /* 051536 */
#define sprite_list_051572_ADDRESS 0x7572u    /* 051572 */
#define sprite_list_0515BA_ADDRESS 0x75BAu    /* 0515BA */
#define sprite_list_0515FC_ADDRESS 0x75FCu    /* 0515FC */
#define sprite_list_05164A_ADDRESS 0x764Au    /* 05164A */
#define sprite_list_051698_ADDRESS 0x7698u    /* 051698 */
#define sprite_list_0516E6_ADDRESS 0x76E6u    /* 0516E6 */
#define sprite_list_051734_ADDRESS 0x7734u    /* 051734 */
#define animation_051782_ADDRESS 0x7782u    /* 051782 */
#define sprite_list_051796_ADDRESS 0x7796u    /* 051796 */
#define sprite_list_05179C_ADDRESS 0x779Cu    /* 05179C */
#define sprite_list_0517A2_ADDRESS 0x77A2u    /* 0517A2 */
#define animation_0517A8_ADDRESS 0x77A8u    /* 0517A8 */
#define sprite_list_0517DC_ADDRESS 0x77DCu    /* 0517DC */
#define sprite_list_05180C_ADDRESS 0x780Cu    /* 05180C */
#define sprite_list_051848_ADDRESS 0x7848u    /* 051848 */
#define sprite_list_051884_ADDRESS 0x7884u    /* 051884 */
#define sprite_list_0518C0_ADDRESS 0x78C0u    /* 0518C0 */
#define sprite_list_0518FC_ADDRESS 0x78FCu    /* 0518FC */
#define sprite_list_051938_ADDRESS 0x7938u    /* 051938 */
#define sprite_list_051974_ADDRESS 0x7974u    /* 051974 */
#define sprite_list_0519B0_ADDRESS 0x79B0u    /* 0519B0 */
#define animation_0519EC_ADDRESS 0x79ECu    /* 0519EC */
#define sprite_list_051A08_ADDRESS 0x7A08u    /* 051A08 */
#define sprite_list_051A56_ADDRESS 0x7A56u    /* 051A56 */
#define sprite_list_051AAA_ADDRESS 0x7AAAu    /* 051AAA */
#define sprite_list_051B0A_ADDRESS 0x7B0Au    /* 051B0A */
#define animation_051B5E_ADDRESS 0x7B5Eu    /* 051B5E */
#define sprite_list_051B6E_ADDRESS 0x7B6Eu    /* 051B6E */
#define sprite_list_051B80_ADDRESS 0x7B80u    /* 051B80 */
#define sprite_list_051B92_ADDRESS 0x7B92u    /* 051B92 */
#define animation_051BA4_ADDRESS 0x7BA4u    /* 051BA4 */
#define sprite_list_051BB8_ADDRESS 0x7BB8u    /* 051BB8 */
#define sprite_list_051BBE_ADDRESS 0x7BBEu    /* 051BBE */
#define sprite_list_051BC4_ADDRESS 0x7BC4u    /* 051BC4 */
#define sprite_list_051BCA_ADDRESS 0x7BCAu    /* 051BCA */
#define animation_051BD0_ADDRESS 0x7BD0u    /* 051BD0 */
#define sprite_list_051BD8_ADDRESS 0x7BD8u    /* 051BD8 */
#define animation_table_051BDE_ADDRESS 0x7BDEu    /* 051BDE */
#define animation_051BE6_ADDRESS 0x7BE6u    /* 051BE6 */
#define sprite_list_051BFA_ADDRESS 0x7BFAu    /* 051BFA */
#define sprite_list_051C00_ADDRESS 0x7C00u    /* 051C00 */
#define sprite_list_051C0C_ADDRESS 0x7C0Cu    /* 051C0C */
#define animation_051C18_ADDRESS 0x7C18u    /* 051C18 */
#define sprite_list_051C38_ADDRESS 0x7C38u    /* 051C38 */
#define sprite_list_051C3E_ADDRESS 0x7C3Eu    /* 051C3E */
#define sprite_list_051C4A_ADDRESS 0x7C4Au    /* 051C4A */
#define animation_051C50_ADDRESS 0x7C50u    /* 051C50 */
#define animation_051C5C_ADDRESS 0x7C5Cu    /* 051C5C */
#define sprite_list_051C64_ADDRESS 0x7C64u    /* 051C64 */
#define fill_051C6A_ADDRESS 0x7C6Au    /* 051C6A */
#define unreached_animation_051C6C_ADDRESS 0x7C6Cu    /* 051C6C */
#define sprite_list_051C78_ADDRESS 0x7C78u    /* 051C78 */
#define sprite_list_051C8A_ADDRESS 0x7C8Au    /* 051C8A */
#define unreached_animation_051C9C_ADDRESS 0x7C9Cu    /* 051C9C */
#define sprite_list_051CA8_ADDRESS 0x7CA8u    /* 051CA8 */
#define sprite_list_051CBA_ADDRESS 0x7CBAu    /* 051CBA */
#define unreached_animation_051CCC_ADDRESS 0x7CCCu    /* 051CCC */
#define sprite_list_051CD8_ADDRESS 0x7CD8u    /* 051CD8 */
#define sprite_list_051CEA_ADDRESS 0x7CEAu    /* 051CEA */
#define unreached_animation_051CFC_ADDRESS 0x7CFCu    /* 051CFC */
#define sprite_list_051D08_ADDRESS 0x7D08u    /* 051D08 */
#define sprite_list_051D14_ADDRESS 0x7D14u    /* 051D14 */
#define fill_051D20_ADDRESS 0x7D20u    /* 051D20 */
#define unreached_animation_051D2A_ADDRESS 0x7D2Au    /* 051D2A */
#define sprite_list_051D46_ADDRESS 0x7D46u    /* 051D46 */
#define sprite_list_051D52_ADDRESS 0x7D52u    /* 051D52 */
#define sprite_list_051D5E_ADDRESS 0x7D5Eu    /* 051D5E */
#define sprite_list_051D6A_ADDRESS 0x7D6Au    /* 051D6A */
#define unreached_animation_051D76_ADDRESS 0x7D76u    /* 051D76 */
#define sprite_list_051D92_ADDRESS 0x7D92u    /* 051D92 */
#define sprite_list_051DAA_ADDRESS 0x7DAAu    /* 051DAA */
#define sprite_list_051DC2_ADDRESS 0x7DC2u    /* 051DC2 */
#define sprite_list_051DDA_ADDRESS 0x7DDAu    /* 051DDA */
#define unreached_animation_051DF2_ADDRESS 0x7DF2u    /* 051DF2 */
#define sprite_list_051DFE_ADDRESS 0x7DFEu    /* 051DFE */
#define sprite_list_051E16_ADDRESS 0x7E16u    /* 051E16 */
#define unreached_animation_051E2E_ADDRESS 0x7E2Eu    /* 051E2E */
#define sprite_list_051E3A_ADDRESS 0x7E3Au    /* 051E3A */
#define sprite_list_051E46_ADDRESS 0x7E46u    /* 051E46 */
#define unreached_animation_051E52_ADDRESS 0x7E52u    /* 051E52 */
#define sprite_list_051E5E_ADDRESS 0x7E5Eu    /* 051E5E */
#define sprite_list_051E6A_ADDRESS 0x7E6Au    /* 051E6A */
#define fill_051E76_ADDRESS 0x7E76u    /* 051E76 */
#define set_index_052000_ADDRESS 0x6000u    /* 052000 */
#define animation_table_05200A_ADDRESS 0x600Au    /* 05200A */
#define animation_052032_ADDRESS 0x6032u    /* 052032 */
#define sprite_list_05204A_ADDRESS 0x604Au    /* 05204A */
#define sprite_list_052092_ADDRESS 0x6092u    /* 052092 */
#define sprite_list_0520EC_ADDRESS 0x60ECu    /* 0520EC */
#define animation_052146_ADDRESS 0x6146u    /* 052146 */
#define sprite_list_05216E_ADDRESS 0x616Eu    /* 05216E */
#define sprite_list_0521B6_ADDRESS 0x61B6u    /* 0521B6 */
#define sprite_list_0521FE_ADDRESS 0x61FEu    /* 0521FE */
#define animation_052246_ADDRESS 0x6246u    /* 052246 */
#define sprite_list_05225A_ADDRESS 0x625Au    /* 05225A */
#define sprite_list_052260_ADDRESS 0x6260u    /* 052260 */
#define sprite_list_052266_ADDRESS 0x6266u    /* 052266 */
#define sprite_list_05226C_ADDRESS 0x626Cu    /* 05226C */
#define animation_052272_ADDRESS 0x6272u    /* 052272 */
#define sprite_list_052282_ADDRESS 0x6282u    /* 052282 */
#define sprite_list_0522BE_ADDRESS 0x62BEu    /* 0522BE */
#define sprite_list_052300_ADDRESS 0x6300u    /* 052300 */
#define animation_052342_ADDRESS 0x6342u    /* 052342 */
#define sprite_list_052366_ADDRESS 0x6366u    /* 052366 */
#define sprite_list_0523AE_ADDRESS 0x63AEu    /* 0523AE */
#define sprite_list_0523F6_ADDRESS 0x63F6u    /* 0523F6 */
#define sprite_list_05243E_ADDRESS 0x643Eu    /* 05243E */
#define sprite_list_05248C_ADDRESS 0x648Cu    /* 05248C */
#define sprite_list_0524DA_ADDRESS 0x64DAu    /* 0524DA */
#define sprite_list_05251C_ADDRESS 0x651Cu    /* 05251C */
#define sprite_list_052564_ADDRESS 0x6564u    /* 052564 */
#define animation_0525A6_ADDRESS 0x65A6u    /* 0525A6 */
#define sprite_list_0525C6_ADDRESS 0x65C6u    /* 0525C6 */
#define sprite_list_05260E_ADDRESS 0x660Eu    /* 05260E */
#define sprite_list_052650_ADDRESS 0x6650u    /* 052650 */
#define sprite_list_0526AA_ADDRESS 0x66AAu    /* 0526AA */
#define sprite_list_0526FE_ADDRESS 0x66FEu    /* 0526FE */
#define animation_05274C_ADDRESS 0x674Cu    /* 05274C */
#define sprite_list_052770_ADDRESS 0x6770u    /* 052770 */
#define sprite_list_0527BE_ADDRESS 0x67BEu    /* 0527BE */
#define sprite_list_05280C_ADDRESS 0x680Cu    /* 05280C */
#define sprite_list_05285A_ADDRESS 0x685Au    /* 05285A */
#define sprite_list_0528AE_ADDRESS 0x68AEu    /* 0528AE */
#define animation_0528F6_ADDRESS 0x68F6u    /* 0528F6 */
#define sprite_list_05290A_ADDRESS 0x690Au    /* 05290A */
#define sprite_list_052910_ADDRESS 0x6910u    /* 052910 */
#define sprite_list_052916_ADDRESS 0x6916u    /* 052916 */
#define sprite_list_05291C_ADDRESS 0x691Cu    /* 05291C */
#define animation_052922_ADDRESS 0x6922u    /* 052922 */
#define animation_05292A_ADDRESS 0x692Au    /* 05292A */
#define sprite_list_05294E_ADDRESS 0x694Eu    /* 05294E */
#define sprite_list_05295A_ADDRESS 0x695Au    /* 05295A */
#define sprite_list_052972_ADDRESS 0x6972u    /* 052972 */
#define sprite_list_052984_ADDRESS 0x6984u    /* 052984 */
#define sprite_list_0529A2_ADDRESS 0x69A2u    /* 0529A2 */
#define sprite_list_0529CC_ADDRESS 0x69CCu    /* 0529CC */
#define sprite_list_052A08_ADDRESS 0x6A08u    /* 052A08 */
#define sprite_list_052A3E_ADDRESS 0x6A3Eu    /* 052A3E */
#define animation_052A8C_ADDRESS 0x6A8Cu    /* 052A8C */
#define sprite_list_052AB8_ADDRESS 0x6AB8u    /* 052AB8 */
#define sprite_list_052B00_ADDRESS 0x6B00u    /* 052B00 */
#define sprite_list_052B48_ADDRESS 0x6B48u    /* 052B48 */
#define sprite_list_052B90_ADDRESS 0x6B90u    /* 052B90 */
#define sprite_list_052BCC_ADDRESS 0x6BCCu    /* 052BCC */
#define sprite_list_052C14_ADDRESS 0x6C14u    /* 052C14 */
#define sprite_list_052C5C_ADDRESS 0x6C5Cu    /* 052C5C */
#define sprite_list_052C98_ADDRESS 0x6C98u    /* 052C98 */
#define sprite_list_052CD4_ADDRESS 0x6CD4u    /* 052CD4 */
#define animation_052D10_ADDRESS 0x6D10u    /* 052D10 */
#define sprite_list_052D1C_ADDRESS 0x6D1Cu    /* 052D1C */
#define sprite_list_052D6A_ADDRESS 0x6D6Au    /* 052D6A */
#define animation_052DB8_ADDRESS 0x6DB8u    /* 052DB8 */
#define sprite_list_052DD4_ADDRESS 0x6DD4u    /* 052DD4 */
#define sprite_list_052E1C_ADDRESS 0x6E1Cu    /* 052E1C */
#define sprite_list_052E64_ADDRESS 0x6E64u    /* 052E64 */
#define sprite_list_052EAC_ADDRESS 0x6EACu    /* 052EAC */
#define sprite_list_052EF4_ADDRESS 0x6EF4u    /* 052EF4 */
#define sprite_list_052F3C_ADDRESS 0x6F3Cu    /* 052F3C */
#define animation_052F84_ADDRESS 0x6F84u    /* 052F84 */
#define sprite_list_052FB0_ADDRESS 0x6FB0u    /* 052FB0 */
#define sprite_list_052FF8_ADDRESS 0x6FF8u    /* 052FF8 */
#define sprite_list_053040_ADDRESS 0x7040u    /* 053040 */
#define sprite_list_053088_ADDRESS 0x7088u    /* 053088 */
#define sprite_list_0530D0_ADDRESS 0x70D0u    /* 0530D0 */
#define sprite_list_053118_ADDRESS 0x7118u    /* 053118 */
#define sprite_list_053154_ADDRESS 0x7154u    /* 053154 */
#define sprite_list_05319C_ADDRESS 0x719Cu    /* 05319C */
#define sprite_list_0531E4_ADDRESS 0x71E4u    /* 0531E4 */
#define sprite_list_053220_ADDRESS 0x7220u    /* 053220 */
#define animation_05325C_ADDRESS 0x725Cu    /* 05325C */
#define sprite_list_053280_ADDRESS 0x7280u    /* 053280 */
#define sprite_list_0532CE_ADDRESS 0x72CEu    /* 0532CE */
#define sprite_list_053316_ADDRESS 0x7316u    /* 053316 */
#define sprite_list_053370_ADDRESS 0x7370u    /* 053370 */
#define animation_0533CA_ADDRESS 0x73CAu    /* 0533CA */
#define animation_0533D6_ADDRESS 0x73D6u    /* 0533D6 */
#define sprite_list_0533EA_ADDRESS 0x73EAu    /* 0533EA */
#define sprite_list_0533F0_ADDRESS 0x73F0u    /* 0533F0 */
#define sprite_list_0533F6_ADDRESS 0x73F6u    /* 0533F6 */
#define sprite_list_0533FC_ADDRESS 0x73FCu    /* 0533FC */
#define animation_053402_ADDRESS 0x7402u    /* 053402 */
#define sprite_list_05340A_ADDRESS 0x740Au    /* 05340A */
#define animation_053410_ADDRESS 0x7410u    /* 053410 */
#define sprite_list_05341C_ADDRESS 0x741Cu    /* 05341C */
#define sprite_list_05346A_ADDRESS 0x746Au    /* 05346A */
#define animation_0534B2_ADDRESS 0x74B2u    /* 0534B2 */
#define sprite_list_0534BE_ADDRESS 0x74BEu    /* 0534BE */
#define animation_table_0534CA_ADDRESS 0x74CAu    /* 0534CA */
#define animation_0534D2_ADDRESS 0x74D2u    /* 0534D2 */
#define sprite_list_0534F6_ADDRESS 0x74F6u    /* 0534F6 */
#define sprite_list_05350E_ADDRESS 0x750Eu    /* 05350E */
#define sprite_list_053526_ADDRESS 0x7526u    /* 053526 */
#define sprite_list_05353E_ADDRESS 0x753Eu    /* 05353E */
#define animation_053556_ADDRESS 0x7556u    /* 053556 */
#define sprite_list_053566_ADDRESS 0x7566u    /* 053566 */
#define sprite_list_05357E_ADDRESS 0x757Eu    /* 05357E */
#define sprite_list_05359C_ADDRESS 0x759Cu    /* 05359C */
#define animation_0535AE_ADDRESS 0x75AEu    /* 0535AE */
#define sprite_list_0535BA_ADDRESS 0x75BAu    /* 0535BA */
#define animation_0535CC_ADDRESS 0x75CCu    /* 0535CC */
#define sprite_list_0535D4_ADDRESS 0x75D4u    /* 0535D4 */
#define animation_table_0535E6_ADDRESS 0x75E6u    /* 0535E6 */
#define animation_053614_ADDRESS 0x7614u    /* 053614 */
#define sprite_list_053620_ADDRESS 0x7620u    /* 053620 */
#define sprite_list_053626_ADDRESS 0x7626u    /* 053626 */
#define animation_05362C_ADDRESS 0x762Cu    /* 05362C */
#define sprite_list_053634_ADDRESS 0x7634u    /* 053634 */
#define animation_053640_ADDRESS 0x7640u    /* 053640 */
#define sprite_list_053654_ADDRESS 0x7654u    /* 053654 */
#define sprite_list_053660_ADDRESS 0x7660u    /* 053660 */
#define sprite_list_05366C_ADDRESS 0x766Cu    /* 05366C */
#define sprite_list_053678_ADDRESS 0x7678u    /* 053678 */
#define animation_053684_ADDRESS 0x7684u    /* 053684 */
#define sprite_list_053698_ADDRESS 0x7698u    /* 053698 */
#define sprite_list_0536AA_ADDRESS 0x76AAu    /* 0536AA */
#define sprite_list_0536C8_ADDRESS 0x76C8u    /* 0536C8 */
#define sprite_list_0536E6_ADDRESS 0x76E6u    /* 0536E6 */
#define animation_0536F8_ADDRESS 0x76F8u    /* 0536F8 */
#define sprite_list_053708_ADDRESS 0x7708u    /* 053708 */
#define sprite_list_053726_ADDRESS 0x7726u    /* 053726 */
#define animation_053750_ADDRESS 0x7750u    /* 053750 */
#define sprite_list_053764_ADDRESS 0x7764u    /* 053764 */
#define sprite_list_053776_ADDRESS 0x7776u    /* 053776 */
#define animation_053794_ADDRESS 0x7794u    /* 053794 */
#define sprite_list_0537A4_ADDRESS 0x77A4u    /* 0537A4 */
#define animation_0537CE_ADDRESS 0x77CEu    /* 0537CE */
#define animation_0537D6_ADDRESS 0x77D6u    /* 0537D6 */
#define animation_0537DE_ADDRESS 0x77DEu    /* 0537DE */
#define sprite_list_0537E6_ADDRESS 0x77E6u    /* 0537E6 */
#define animation_0537F2_ADDRESS 0x77F2u    /* 0537F2 */
#define sprite_list_0537FE_ADDRESS 0x77FEu    /* 0537FE */
#define sprite_list_053810_ADDRESS 0x7810u    /* 053810 */
#define animation_053822_ADDRESS 0x7822u    /* 053822 */
#define animation_05382E_ADDRESS 0x782Eu    /* 05382E */
#define sprite_list_053836_ADDRESS 0x7836u    /* 053836 */
#define animation_053842_ADDRESS 0x7842u    /* 053842 */
#define sprite_list_05384A_ADDRESS 0x784Au    /* 05384A */
#define animation_053862_ADDRESS 0x7862u    /* 053862 */
#define sprite_list_05386A_ADDRESS 0x786Au    /* 05386A */
#define animation_053882_ADDRESS 0x7882u    /* 053882 */
#define animation_05389A_ADDRESS 0x789Au    /* 05389A */
#define sprite_list_0538A2_ADDRESS 0x78A2u    /* 0538A2 */
#define animation_0538B4_ADDRESS 0x78B4u    /* 0538B4 */
#define sprite_list_0538C0_ADDRESS 0x78C0u    /* 0538C0 */
#define animation_0538D2_ADDRESS 0x78D2u    /* 0538D2 */
#define sprite_list_0538E2_ADDRESS 0x78E2u    /* 0538E2 */
#define sprite_list_0538E8_ADDRESS 0x78E8u    /* 0538E8 */
#define sprite_list_0538EE_ADDRESS 0x78EEu    /* 0538EE */
#define animation_0538F4_ADDRESS 0x78F4u    /* 0538F4 */
#define sprite_list_053908_ADDRESS 0x7908u    /* 053908 */
#define sprite_list_053920_ADDRESS 0x7920u    /* 053920 */
#define sprite_list_053938_ADDRESS 0x7938u    /* 053938 */
#define sprite_list_053950_ADDRESS 0x7950u    /* 053950 */
#define animation_05397A_ADDRESS 0x797Au    /* 05397A */
#define sprite_list_053986_ADDRESS 0x7986u    /* 053986 */
#define animation_0539B0_ADDRESS 0x79B0u    /* 0539B0 */
#define sprite_list_0539BC_ADDRESS 0x79BCu    /* 0539BC */
#define sprite_list_0539E6_ADDRESS 0x79E6u    /* 0539E6 */
#define animation_053A16_ADDRESS 0x7A16u    /* 053A16 */
#define animation_table_053A26_ADDRESS 0x7A26u    /* 053A26 */
#define animation_053A3C_ADDRESS 0x7A3Cu    /* 053A3C */
#define sprite_list_053A58_ADDRESS 0x7A58u    /* 053A58 */
#define sprite_list_053A64_ADDRESS 0x7A64u    /* 053A64 */
#define sprite_list_053A70_ADDRESS 0x7A70u    /* 053A70 */
#define sprite_list_053A7C_ADDRESS 0x7A7Cu    /* 053A7C */
#define animation_053A88_ADDRESS 0x7A88u    /* 053A88 */
#define sprite_list_053AA4_ADDRESS 0x7AA4u    /* 053AA4 */
#define sprite_list_053AB6_ADDRESS 0x7AB6u    /* 053AB6 */
#define sprite_list_053AC8_ADDRESS 0x7AC8u    /* 053AC8 */
#define sprite_list_053ADA_ADDRESS 0x7ADAu    /* 053ADA */
#define animation_053AEC_ADDRESS 0x7AECu    /* 053AEC */
#define sprite_list_053B08_ADDRESS 0x7B08u    /* 053B08 */
#define sprite_list_053B1A_ADDRESS 0x7B1Au    /* 053B1A */
#define sprite_list_053B2C_ADDRESS 0x7B2Cu    /* 053B2C */
#define sprite_list_053B3E_ADDRESS 0x7B3Eu    /* 053B3E */
#define animation_053B50_ADDRESS 0x7B50u    /* 053B50 */
#define sprite_list_053B6C_ADDRESS 0x7B6Cu    /* 053B6C */
#define sprite_list_053B7E_ADDRESS 0x7B7Eu    /* 053B7E */
#define sprite_list_053B90_ADDRESS 0x7B90u    /* 053B90 */
#define sprite_list_053BA2_ADDRESS 0x7BA2u    /* 053BA2 */
#define animation_053BB4_ADDRESS 0x7BB4u    /* 053BB4 */
#define sprite_list_053BD0_ADDRESS 0x7BD0u    /* 053BD0 */
#define sprite_list_053BE2_ADDRESS 0x7BE2u    /* 053BE2 */
#define sprite_list_053BF4_ADDRESS 0x7BF4u    /* 053BF4 */
#define sprite_list_053C06_ADDRESS 0x7C06u    /* 053C06 */
#define animation_053C18_ADDRESS 0x7C18u    /* 053C18 */
#define sprite_list_053C24_ADDRESS 0x7C24u    /* 053C24 */
#define sprite_list_053C30_ADDRESS 0x7C30u    /* 053C30 */
#define animation_053C3C_ADDRESS 0x7C3Cu    /* 053C3C */
#define sprite_list_053C48_ADDRESS 0x7C48u    /* 053C48 */
#define sprite_list_053C5A_ADDRESS 0x7C5Au    /* 053C5A */
#define animation_053C6C_ADDRESS 0x7C6Cu    /* 053C6C */
#define sprite_list_053C78_ADDRESS 0x7C78u    /* 053C78 */
#define sprite_list_053C8A_ADDRESS 0x7C8Au    /* 053C8A */
#define animation_053C9C_ADDRESS 0x7C9Cu    /* 053C9C */
#define sprite_list_053CA8_ADDRESS 0x7CA8u    /* 053CA8 */
#define sprite_list_053CBA_ADDRESS 0x7CBAu    /* 053CBA */
#define animation_053CCC_ADDRESS 0x7CCCu    /* 053CCC */
#define sprite_list_053CD8_ADDRESS 0x7CD8u    /* 053CD8 */
#define sprite_list_053CEA_ADDRESS 0x7CEAu    /* 053CEA */
#define animation_053CFC_ADDRESS 0x7CFCu    /* 053CFC */
#define sprite_list_053D08_ADDRESS 0x7D08u    /* 053D08 */
#define sprite_list_053D14_ADDRESS 0x7D14u    /* 053D14 */
#define animation_table_053D20_ADDRESS 0x7D20u    /* 053D20 */
#define animation_053D2A_ADDRESS 0x7D2Au    /* 053D2A */
#define sprite_list_053D46_ADDRESS 0x7D46u    /* 053D46 */
#define sprite_list_053D52_ADDRESS 0x7D52u    /* 053D52 */
#define sprite_list_053D5E_ADDRESS 0x7D5Eu    /* 053D5E */
#define sprite_list_053D6A_ADDRESS 0x7D6Au    /* 053D6A */
#define animation_053D76_ADDRESS 0x7D76u    /* 053D76 */
#define sprite_list_053D92_ADDRESS 0x7D92u    /* 053D92 */
#define sprite_list_053DAA_ADDRESS 0x7DAAu    /* 053DAA */
#define sprite_list_053DC2_ADDRESS 0x7DC2u    /* 053DC2 */
#define sprite_list_053DDA_ADDRESS 0x7DDAu    /* 053DDA */
#define animation_053DF2_ADDRESS 0x7DF2u    /* 053DF2 */
#define sprite_list_053DFE_ADDRESS 0x7DFEu    /* 053DFE */
#define sprite_list_053E16_ADDRESS 0x7E16u    /* 053E16 */
#define animation_053E2E_ADDRESS 0x7E2Eu    /* 053E2E */
#define sprite_list_053E3A_ADDRESS 0x7E3Au    /* 053E3A */
#define sprite_list_053E46_ADDRESS 0x7E46u    /* 053E46 */
#define animation_053E52_ADDRESS 0x7E52u    /* 053E52 */
#define sprite_list_053E5E_ADDRESS 0x7E5Eu    /* 053E5E */
#define sprite_list_053E6A_ADDRESS 0x7E6Au    /* 053E6A */
#define fill_053E76_ADDRESS 0x7E76u    /* 053E76 */
#define set_index_054000_ADDRESS 0x6000u    /* 054000 */
#define animation_table_054004_ADDRESS 0x6004u    /* 054004 */
#define animation_054024_ADDRESS 0x6024u    /* 054024 */
#define sprite_list_054034_ADDRESS 0x6034u    /* 054034 */
#define sprite_list_054076_ADDRESS 0x6076u    /* 054076 */
#define sprite_list_0540B8_ADDRESS 0x60B8u    /* 0540B8 */
#define animation_0540FA_ADDRESS 0x60FAu    /* 0540FA */
#define sprite_list_054106_ADDRESS 0x6106u    /* 054106 */
#define sprite_list_05414E_ADDRESS 0x614Eu    /* 05414E */
#define animation_054196_ADDRESS 0x6196u    /* 054196 */
#define sprite_list_0541B2_ADDRESS 0x61B2u    /* 0541B2 */
#define sprite_list_0541EE_ADDRESS 0x61EEu    /* 0541EE */
#define sprite_list_054230_ADDRESS 0x6230u    /* 054230 */
#define sprite_list_054272_ADDRESS 0x6272u    /* 054272 */
#define sprite_list_0542B4_ADDRESS 0x62B4u    /* 0542B4 */
#define sprite_list_0542F6_ADDRESS 0x62F6u    /* 0542F6 */
#define animation_054338_ADDRESS 0x6338u    /* 054338 */
#define sprite_list_05435C_ADDRESS 0x635Cu    /* 05435C */
#define sprite_list_0543B6_ADDRESS 0x63B6u    /* 0543B6 */
#define sprite_list_05440A_ADDRESS 0x640Au    /* 05440A */
#define sprite_list_054464_ADDRESS 0x6464u    /* 054464 */
#define sprite_list_0544B8_ADDRESS 0x64B8u    /* 0544B8 */
#define sprite_list_054512_ADDRESS 0x6512u    /* 054512 */
#define sprite_list_054566_ADDRESS 0x6566u    /* 054566 */
#define animation_0545BA_ADDRESS 0x65BAu    /* 0545BA */
#define sprite_list_0545CE_ADDRESS 0x65CEu    /* 0545CE */
#define sprite_list_0545D4_ADDRESS 0x65D4u    /* 0545D4 */
#define sprite_list_0545DA_ADDRESS 0x65DAu    /* 0545DA */
#define sprite_list_0545E0_ADDRESS 0x65E0u    /* 0545E0 */
#define animation_0545E6_ADDRESS 0x65E6u    /* 0545E6 */
#define sprite_list_0545F2_ADDRESS 0x65F2u    /* 0545F2 */
#define sprite_list_05463A_ADDRESS 0x663Au    /* 05463A */
#define animation_05467C_ADDRESS 0x667Cu    /* 05467C */
#define sprite_list_0546A0_ADDRESS 0x66A0u    /* 0546A0 */
#define sprite_list_0546F4_ADDRESS 0x66F4u    /* 0546F4 */
#define animation_054754_ADDRESS 0x6754u    /* 054754 */
#define sprite_list_054768_ADDRESS 0x6768u    /* 054768 */
#define sprite_list_054780_ADDRESS 0x6780u    /* 054780 */
#define sprite_list_054798_ADDRESS 0x6798u    /* 054798 */
#define sprite_list_0547B0_ADDRESS 0x67B0u    /* 0547B0 */
#define animation_0547C8_ADDRESS 0x67C8u    /* 0547C8 */
#define sprite_list_0547E8_ADDRESS 0x67E8u    /* 0547E8 */
#define sprite_list_05482A_ADDRESS 0x682Au    /* 05482A */
#define sprite_list_054866_ADDRESS 0x6866u    /* 054866 */
#define sprite_list_0548BA_ADDRESS 0x68BAu    /* 0548BA */
#define sprite_list_054908_ADDRESS 0x6908u    /* 054908 */
#define animation_054950_ADDRESS 0x6950u    /* 054950 */
#define sprite_list_054974_ADDRESS 0x6974u    /* 054974 */
#define sprite_list_0549BC_ADDRESS 0x69BCu    /* 0549BC */
#define sprite_list_054A04_ADDRESS 0x6A04u    /* 054A04 */
#define sprite_list_054A4C_ADDRESS 0x6A4Cu    /* 054A4C */
#define sprite_list_054A9A_ADDRESS 0x6A9Au    /* 054A9A */
#define animation_054AD6_ADDRESS 0x6AD6u    /* 054AD6 */
#define sprite_list_054AF6_ADDRESS 0x6AF6u    /* 054AF6 */
#define sprite_list_054B38_ADDRESS 0x6B38u    /* 054B38 */
#define sprite_list_054B86_ADDRESS 0x6B86u    /* 054B86 */
#define sprite_list_054BD4_ADDRESS 0x6BD4u    /* 054BD4 */
#define sprite_list_054C22_ADDRESS 0x6C22u    /* 054C22 */
#define animation_054C70_ADDRESS 0x6C70u    /* 054C70 */
#define sprite_list_054C80_ADDRESS 0x6C80u    /* 054C80 */
#define sprite_list_054CCE_ADDRESS 0x6CCEu    /* 054CCE */
#define sprite_list_054D1C_ADDRESS 0x6D1Cu    /* 054D1C */
#define animation_054D64_ADDRESS 0x6D64u    /* 054D64 */
#define animation_054D74_ADDRESS 0x6D74u    /* 054D74 */
#define sprite_list_054D80_ADDRESS 0x6D80u    /* 054D80 */
#define sprite_list_054DC2_ADDRESS 0x6DC2u    /* 054DC2 */
#define animation_054E04_ADDRESS 0x6E04u    /* 054E04 */
#define sprite_list_054E20_ADDRESS 0x6E20u    /* 054E20 */
#define sprite_list_054E74_ADDRESS 0x6E74u    /* 054E74 */
#define sprite_list_054ECE_ADDRESS 0x6ECEu    /* 054ECE */
#define sprite_list_054F22_ADDRESS 0x6F22u    /* 054F22 */
#define sprite_list_054F7C_ADDRESS 0x6F7Cu    /* 054F7C */
#define sprite_list_054FD0_ADDRESS 0x6FD0u    /* 054FD0 */
#define animation_055024_ADDRESS 0x7024u    /* 055024 */
#define sprite_list_055030_ADDRESS 0x7030u    /* 055030 */
#define sprite_list_05506C_ADDRESS 0x706Cu    /* 05506C */
#define animation_table_0550A8_ADDRESS 0x70A8u    /* 0550A8 */
#define animation_0550BC_ADDRESS 0x70BCu    /* 0550BC */
#define sprite_list_0550D0_ADDRESS 0x70D0u    /* 0550D0 */
#define sprite_list_05510C_ADDRESS 0x710Cu    /* 05510C */
#define sprite_list_055148_ADDRESS 0x7148u    /* 055148 */
#define sprite_list_055184_ADDRESS 0x7184u    /* 055184 */
#define animation_0551C0_ADDRESS 0x71C0u    /* 0551C0 */
#define sprite_list_0551D4_ADDRESS 0x71D4u    /* 0551D4 */
#define sprite_list_055210_ADDRESS 0x7210u    /* 055210 */
#define sprite_list_05524C_ADDRESS 0x724Cu    /* 05524C */
#define sprite_list_055288_ADDRESS 0x7288u    /* 055288 */
#define animation_0552C4_ADDRESS 0x72C4u    /* 0552C4 */
#define sprite_list_0552D0_ADDRESS 0x72D0u    /* 0552D0 */
#define sprite_list_05530C_ADDRESS 0x730Cu    /* 05530C */
#define animation_055348_ADDRESS 0x7348u    /* 055348 */
#define sprite_list_055354_ADDRESS 0x7354u    /* 055354 */
#define sprite_list_055390_ADDRESS 0x7390u    /* 055390 */
#define animation_0553CC_ADDRESS 0x73CCu    /* 0553CC */
#define sprite_list_0553E0_ADDRESS 0x73E0u    /* 0553E0 */
#define sprite_list_05541C_ADDRESS 0x741Cu    /* 05541C */
#define sprite_list_055458_ADDRESS 0x7458u    /* 055458 */
#define sprite_list_055494_ADDRESS 0x7494u    /* 055494 */
#define animation_0554D0_ADDRESS 0x74D0u    /* 0554D0 */
#define sprite_list_0554EC_ADDRESS 0x74ECu    /* 0554EC */
#define sprite_list_055528_ADDRESS 0x7528u    /* 055528 */
#define sprite_list_055564_ADDRESS 0x7564u    /* 055564 */
#define sprite_list_0555A0_ADDRESS 0x75A0u    /* 0555A0 */
#define sprite_list_0555DC_ADDRESS 0x75DCu    /* 0555DC */
#define sprite_list_055618_ADDRESS 0x7618u    /* 055618 */
#define animation_05564E_ADDRESS 0x764Eu    /* 05564E */
#define sprite_list_055662_ADDRESS 0x7662u    /* 055662 */
#define sprite_list_05569E_ADDRESS 0x769Eu    /* 05569E */
#define sprite_list_0556DA_ADDRESS 0x76DAu    /* 0556DA */
#define animation_055716_ADDRESS 0x7716u    /* 055716 */
#define sprite_list_05573E_ADDRESS 0x773Eu    /* 05573E */
#define sprite_list_05577A_ADDRESS 0x777Au    /* 05577A */
#define sprite_list_0557BC_ADDRESS 0x77BCu    /* 0557BC */
#define sprite_list_05580A_ADDRESS 0x780Au    /* 05580A */
#define sprite_list_055858_ADDRESS 0x7858u    /* 055858 */
#define animation_0558A6_ADDRESS 0x78A6u    /* 0558A6 */
#define sprite_list_0558D6_ADDRESS 0x78D6u    /* 0558D6 */
#define sprite_list_055918_ADDRESS 0x7918u    /* 055918 */
#define sprite_list_055960_ADDRESS 0x7960u    /* 055960 */
#define sprite_list_0559AE_ADDRESS 0x79AEu    /* 0559AE */
#define sprite_list_055A02_ADDRESS 0x7A02u    /* 055A02 */
#define sprite_list_055A56_ADDRESS 0x7A56u    /* 055A56 */
#define sprite_list_055AA4_ADDRESS 0x7AA4u    /* 055AA4 */
#define sprite_list_055AFE_ADDRESS 0x7AFEu    /* 055AFE */
#define sprite_list_055B4C_ADDRESS 0x7B4Cu    /* 055B4C */
#define animation_055BA0_ADDRESS 0x7BA0u    /* 055BA0 */
#define sprite_list_055BAC_ADDRESS 0x7BACu    /* 055BAC */
#define sprite_list_055BE2_ADDRESS 0x7BE2u    /* 055BE2 */
#define fill_055C30_ADDRESS 0x7C30u    /* 055C30 */
#define unreached_animation_055C36_ADDRESS 0x7C36u    /* 055C36 */
#define unreached_animation_055C4A_ADDRESS 0x7C4Au    /* 055C4A */
#define sprite_list_055C52_ADDRESS 0x7C52u    /* 055C52 */
#define sprite_list_055C64_ADDRESS 0x7C64u    /* 055C64 */
#define sprite_list_055C6A_ADDRESS 0x7C6Au    /* 055C6A */
#define unreached_animation_055C70_ADDRESS 0x7C70u    /* 055C70 */
#define sprite_list_055C84_ADDRESS 0x7C84u    /* 055C84 */
#define sprite_list_055C8A_ADDRESS 0x7C8Au    /* 055C8A */
#define sprite_list_055C9C_ADDRESS 0x7C9Cu    /* 055C9C */
#define sprite_list_055CB4_ADDRESS 0x7CB4u    /* 055CB4 */
#define fill_055CCC_ADDRESS 0x7CCCu    /* 055CCC */
#define unreached_animation_055CDA_ADDRESS 0x7CDAu    /* 055CDA */
#define sprite_list_055CE2_ADDRESS 0x7CE2u    /* 055CE2 */
#define unreached_animation_055CFA_ADDRESS 0x7CFAu    /* 055CFA */
#define sprite_list_055D16_ADDRESS 0x7D16u    /* 055D16 */
#define sprite_list_055D1C_ADDRESS 0x7D1Cu    /* 055D1C */
#define sprite_list_055D28_ADDRESS 0x7D28u    /* 055D28 */
#define sprite_list_055D40_ADDRESS 0x7D40u    /* 055D40 */
#define sprite_list_055D58_ADDRESS 0x7D58u    /* 055D58 */
#define sprite_list_055D6A_ADDRESS 0x7D6Au    /* 055D6A */
#define unreached_animation_055D70_ADDRESS 0x7D70u    /* 055D70 */
#define unreached_animation_055D78_ADDRESS 0x7D78u    /* 055D78 */
#define sprite_list_055D8C_ADDRESS 0x7D8Cu    /* 055D8C */
#define sprite_list_055D92_ADDRESS 0x7D92u    /* 055D92 */
#define sprite_list_055D98_ADDRESS 0x7D98u    /* 055D98 */
#define sprite_list_055D9E_ADDRESS 0x7D9Eu    /* 055D9E */
#define unreached_animation_055DA4_ADDRESS 0x7DA4u    /* 055DA4 */
#define sprite_list_055DB8_ADDRESS 0x7DB8u    /* 055DB8 */
#define sprite_list_055DCA_ADDRESS 0x7DCAu    /* 055DCA */
#define sprite_list_055DDC_ADDRESS 0x7DDCu    /* 055DDC */
#define sprite_list_055DEE_ADDRESS 0x7DEEu    /* 055DEE */
#define unreached_animation_055E00_ADDRESS 0x7E00u    /* 055E00 */
#define sprite_list_055E08_ADDRESS 0x7E08u    /* 055E08 */
#define unreached_animation_055E0E_ADDRESS 0x7E0Eu    /* 055E0E */
#define fill_055E16_ADDRESS 0x7E16u    /* 055E16 */
#define set_index_056000_ADDRESS 0x6000u    /* 056000 */
#define animation_table_056008_ADDRESS 0x6008u    /* 056008 */
#define animation_05602A_ADDRESS 0x602Au    /* 05602A */
#define sprite_list_05603E_ADDRESS 0x603Eu    /* 05603E */
#define sprite_list_056086_ADDRESS 0x6086u    /* 056086 */
#define sprite_list_0560D4_ADDRESS 0x60D4u    /* 0560D4 */
#define animation_05611C_ADDRESS 0x611Cu    /* 05611C */
#define sprite_list_056130_ADDRESS 0x6130u    /* 056130 */
#define sprite_list_056178_ADDRESS 0x6178u    /* 056178 */
#define sprite_list_0561C6_ADDRESS 0x61C6u    /* 0561C6 */
#define animation_05620E_ADDRESS 0x620Eu    /* 05620E */
#define sprite_list_056242_ADDRESS 0x6242u    /* 056242 */
#define sprite_list_05628A_ADDRESS 0x628Au    /* 05628A */
#define sprite_list_0562D8_ADDRESS 0x62D8u    /* 0562D8 */
#define sprite_list_056320_ADDRESS 0x6320u    /* 056320 */
#define sprite_list_056362_ADDRESS 0x6362u    /* 056362 */
#define sprite_list_05639E_ADDRESS 0x639Eu    /* 05639E */
#define sprite_list_0563DA_ADDRESS 0x63DAu    /* 0563DA */
#define animation_056416_ADDRESS 0x6416u    /* 056416 */
#define sprite_list_056422_ADDRESS 0x6422u    /* 056422 */
#define sprite_list_05646A_ADDRESS 0x646Au    /* 05646A */
#define animation_0564B2_ADDRESS 0x64B2u    /* 0564B2 */
#define sprite_list_0564D6_ADDRESS 0x64D6u    /* 0564D6 */
#define sprite_list_05651E_ADDRESS 0x651Eu    /* 05651E */
#define sprite_list_056566_ADDRESS 0x6566u    /* 056566 */
#define sprite_list_0565B4_ADDRESS 0x65B4u    /* 0565B4 */
#define sprite_list_056602_ADDRESS 0x6602u    /* 056602 */
#define sprite_list_056656_ADDRESS 0x6656u    /* 056656 */
#define sprite_list_0566B0_ADDRESS 0x66B0u    /* 0566B0 */
#define sprite_list_05670A_ADDRESS 0x670Au    /* 05670A */
#define animation_05675E_ADDRESS 0x675Eu    /* 05675E */
#define sprite_list_056776_ADDRESS 0x6776u    /* 056776 */
#define sprite_list_0567C4_ADDRESS 0x67C4u    /* 0567C4 */
#define sprite_list_056818_ADDRESS 0x6818u    /* 056818 */
#define sprite_list_05686C_ADDRESS 0x686Cu    /* 05686C */
#define animation_0568C6_ADDRESS 0x68C6u    /* 0568C6 */
#define sprite_list_056902_ADDRESS 0x6902u    /* 056902 */
#define sprite_list_056944_ADDRESS 0x6944u    /* 056944 */
#define sprite_list_056986_ADDRESS 0x6986u    /* 056986 */
#define sprite_list_0569CE_ADDRESS 0x69CEu    /* 0569CE */
#define sprite_list_056A22_ADDRESS 0x6A22u    /* 056A22 */
#define sprite_list_056A76_ADDRESS 0x6A76u    /* 056A76 */
#define sprite_list_056AD6_ADDRESS 0x6AD6u    /* 056AD6 */
#define sprite_list_056B36_ADDRESS 0x6B36u    /* 056B36 */
#define sprite_list_056B90_ADDRESS 0x6B90u    /* 056B90 */
#define sprite_list_056BD2_ADDRESS 0x6BD2u    /* 056BD2 */
#define animation_056C20_ADDRESS 0x6C20u    /* 056C20 */
#define sprite_list_056C44_ADDRESS 0x6C44u    /* 056C44 */
#define sprite_list_056C86_ADDRESS 0x6C86u    /* 056C86 */
#define sprite_list_056CC8_ADDRESS 0x6CC8u    /* 056CC8 */
#define sprite_list_056D1C_ADDRESS 0x6D1Cu    /* 056D1C */
#define sprite_list_056D52_ADDRESS 0x6D52u    /* 056D52 */
#define sprite_list_056D8E_ADDRESS 0x6D8Eu    /* 056D8E */
#define sprite_list_056DD0_ADDRESS 0x6DD0u    /* 056DD0 */
#define animation_056E0C_ADDRESS 0x6E0Cu    /* 056E0C */
#define sprite_list_056E2C_ADDRESS 0x6E2Cu    /* 056E2C */
#define sprite_list_056E86_ADDRESS 0x6E86u    /* 056E86 */
#define sprite_list_056EDA_ADDRESS 0x6EDAu    /* 056EDA */
#define sprite_list_056F3A_ADDRESS 0x6F3Au    /* 056F3A */
#define sprite_list_056F94_ADDRESS 0x6F94u    /* 056F94 */
#define animation_056FF4_ADDRESS 0x6FF4u    /* 056FF4 */
#define sprite_list_057028_ADDRESS 0x7028u    /* 057028 */
#define sprite_list_05705E_ADDRESS 0x705Eu    /* 05705E */
#define sprite_list_05709A_ADDRESS 0x709Au    /* 05709A */
#define sprite_list_0570DC_ADDRESS 0x70DCu    /* 0570DC */
#define sprite_list_057118_ADDRESS 0x7118u    /* 057118 */
#define sprite_list_05715A_ADDRESS 0x715Au    /* 05715A */
#define sprite_list_057196_ADDRESS 0x7196u    /* 057196 */
#define sprite_list_0571D8_ADDRESS 0x71D8u    /* 0571D8 */
#define sprite_list_057214_ADDRESS 0x7214u    /* 057214 */
#define animation_057256_ADDRESS 0x7256u    /* 057256 */
#define sprite_list_05726A_ADDRESS 0x726Au    /* 05726A */
#define sprite_list_0572B2_ADDRESS 0x72B2u    /* 0572B2 */
#define sprite_list_057300_ADDRESS 0x7300u    /* 057300 */
#define animation_057348_ADDRESS 0x7348u    /* 057348 */
#define sprite_list_057378_ADDRESS 0x7378u    /* 057378 */
#define sprite_list_0573C6_ADDRESS 0x73C6u    /* 0573C6 */
#define sprite_list_057414_ADDRESS 0x7414u    /* 057414 */
#define sprite_list_057468_ADDRESS 0x7468u    /* 057468 */
#define sprite_list_0574C8_ADDRESS 0x74C8u    /* 0574C8 */
#define sprite_list_057528_ADDRESS 0x7528u    /* 057528 */
#define sprite_list_057588_ADDRESS 0x7588u    /* 057588 */
#define sprite_list_0575E2_ADDRESS 0x75E2u    /* 0575E2 */
#define animation_05761E_ADDRESS 0x761Eu    /* 05761E */
#define sprite_list_057642_ADDRESS 0x7642u    /* 057642 */
#define sprite_list_057648_ADDRESS 0x7648u    /* 057648 */
#define sprite_list_05764E_ADDRESS 0x764Eu    /* 05764E */
#define sprite_list_057654_ADDRESS 0x7654u    /* 057654 */
#define sprite_list_05765A_ADDRESS 0x765Au    /* 05765A */
#define sprite_list_057660_ADDRESS 0x7660u    /* 057660 */
#define sprite_list_057666_ADDRESS 0x7666u    /* 057666 */
#define sprite_list_05766C_ADDRESS 0x766Cu    /* 05766C */
#define animation_057672_ADDRESS 0x7672u    /* 057672 */
#define sprite_list_057696_ADDRESS 0x7696u    /* 057696 */
#define sprite_list_05769C_ADDRESS 0x769Cu    /* 05769C */
#define sprite_list_0576A2_ADDRESS 0x76A2u    /* 0576A2 */
#define sprite_list_0576A8_ADDRESS 0x76A8u    /* 0576A8 */
#define sprite_list_0576AE_ADDRESS 0x76AEu    /* 0576AE */
#define sprite_list_0576B4_ADDRESS 0x76B4u    /* 0576B4 */
#define sprite_list_0576BA_ADDRESS 0x76BAu    /* 0576BA */
#define sprite_list_0576C0_ADDRESS 0x76C0u    /* 0576C0 */
#define animation_0576C6_ADDRESS 0x76C6u    /* 0576C6 */
#define sprite_list_0576EA_ADDRESS 0x76EAu    /* 0576EA */
#define sprite_list_0576F6_ADDRESS 0x76F6u    /* 0576F6 */
#define sprite_list_057702_ADDRESS 0x7702u    /* 057702 */
#define sprite_list_05770E_ADDRESS 0x770Eu    /* 05770E */
#define sprite_list_05771A_ADDRESS 0x771Au    /* 05771A */
#define sprite_list_057726_ADDRESS 0x7726u    /* 057726 */
#define sprite_list_057732_ADDRESS 0x7732u    /* 057732 */
#define sprite_list_05773E_ADDRESS 0x773Eu    /* 05773E */
#define animation_05774A_ADDRESS 0x774Au    /* 05774A */
#define sprite_list_05776E_ADDRESS 0x776Eu    /* 05776E */
#define sprite_list_05777A_ADDRESS 0x777Au    /* 05777A */
#define sprite_list_057786_ADDRESS 0x7786u    /* 057786 */
#define sprite_list_057792_ADDRESS 0x7792u    /* 057792 */
#define sprite_list_05779E_ADDRESS 0x779Eu    /* 05779E */
#define sprite_list_0577AA_ADDRESS 0x77AAu    /* 0577AA */
#define sprite_list_0577B6_ADDRESS 0x77B6u    /* 0577B6 */
#define sprite_list_0577C2_ADDRESS 0x77C2u    /* 0577C2 */
#define animation_table_0577CE_ADDRESS 0x77CEu    /* 0577CE */
#define animation_0577DC_ADDRESS 0x77DCu    /* 0577DC */
#define sprite_list_0577E4_ADDRESS 0x77E4u    /* 0577E4 */
#define animation_0577FC_ADDRESS 0x77FCu    /* 0577FC */
#define sprite_list_05781C_ADDRESS 0x781Cu    /* 05781C */
#define sprite_list_057846_ADDRESS 0x7846u    /* 057846 */
#define sprite_list_057870_ADDRESS 0x7870u    /* 057870 */
#define sprite_list_057894_ADDRESS 0x7894u    /* 057894 */
#define sprite_list_0578BE_ADDRESS 0x78BEu    /* 0578BE */
#define sprite_list_0578E8_ADDRESS 0x78E8u    /* 0578E8 */
#define animation_05790C_ADDRESS 0x790Cu    /* 05790C */
#define sprite_list_057928_ADDRESS 0x7928u    /* 057928 */
#define sprite_list_057958_ADDRESS 0x7958u    /* 057958 */
#define sprite_list_057988_ADDRESS 0x7988u    /* 057988 */
#define sprite_list_0579B8_ADDRESS 0x79B8u    /* 0579B8 */
#define sprite_list_0579E8_ADDRESS 0x79E8u    /* 0579E8 */
#define sprite_list_057A18_ADDRESS 0x7A18u    /* 057A18 */
#define animation_057A48_ADDRESS 0x7A48u    /* 057A48 */
#define sprite_list_057A78_ADDRESS 0x7A78u    /* 057A78 */
#define sprite_list_057A9C_ADDRESS 0x7A9Cu    /* 057A9C */
#define sprite_list_057AC0_ADDRESS 0x7AC0u    /* 057AC0 */
#define sprite_list_057AE4_ADDRESS 0x7AE4u    /* 057AE4 */
#define sprite_list_057B08_ADDRESS 0x7B08u    /* 057B08 */
#define sprite_list_057B26_ADDRESS 0x7B26u    /* 057B26 */
#define sprite_list_057B3E_ADDRESS 0x7B3Eu    /* 057B3E */
#define sprite_list_057B56_ADDRESS 0x7B56u    /* 057B56 */
#define sprite_list_057B6E_ADDRESS 0x7B6Eu    /* 057B6E */
#define sprite_list_057B86_ADDRESS 0x7B86u    /* 057B86 */
#define sprite_list_057B92_ADDRESS 0x7B92u    /* 057B92 */
#define animation_057B98_ADDRESS 0x7B98u    /* 057B98 */
#define sprite_list_057BA4_ADDRESS 0x7BA4u    /* 057BA4 */
#define animation_057BBC_ADDRESS 0x7BBCu    /* 057BBC */
#define sprite_list_057BC8_ADDRESS 0x7BC8u    /* 057BC8 */
#define sprite_list_057BCE_ADDRESS 0x7BCEu    /* 057BCE */
#define animation_057BD4_ADDRESS 0x7BD4u    /* 057BD4 */
#define sprite_list_057BE8_ADDRESS 0x7BE8u    /* 057BE8 */
#define sprite_list_057BEE_ADDRESS 0x7BEEu    /* 057BEE */
#define sprite_list_057BF4_ADDRESS 0x7BF4u    /* 057BF4 */
#define sprite_list_057BFA_ADDRESS 0x7BFAu    /* 057BFA */
#define animation_table_057C00_ADDRESS 0x7C00u    /* 057C00 */
#define animation_057C0A_ADDRESS 0x7C0Au    /* 057C0A */
#define animation_057C22_ADDRESS 0x7C22u    /* 057C22 */
#define animation_057C36_ADDRESS 0x7C36u    /* 057C36 */
#define animation_057C4A_ADDRESS 0x7C4Au    /* 057C4A */
#define sprite_list_057C52_ADDRESS 0x7C52u    /* 057C52 */
#define sprite_list_057C64_ADDRESS 0x7C64u    /* 057C64 */
#define sprite_list_057C6A_ADDRESS 0x7C6Au    /* 057C6A */
#define animation_057C70_ADDRESS 0x7C70u    /* 057C70 */
#define sprite_list_057C84_ADDRESS 0x7C84u    /* 057C84 */
#define sprite_list_057C8A_ADDRESS 0x7C8Au    /* 057C8A */
#define sprite_list_057C9C_ADDRESS 0x7C9Cu    /* 057C9C */
#define sprite_list_057CB4_ADDRESS 0x7CB4u    /* 057CB4 */
#define animation_table_057CCC_ADDRESS 0x7CCCu    /* 057CCC */
#define animation_057CDA_ADDRESS 0x7CDAu    /* 057CDA */
#define sprite_list_057CE2_ADDRESS 0x7CE2u    /* 057CE2 */
#define animation_057CFA_ADDRESS 0x7CFAu    /* 057CFA */
#define sprite_list_057D16_ADDRESS 0x7D16u    /* 057D16 */
#define sprite_list_057D1C_ADDRESS 0x7D1Cu    /* 057D1C */
#define sprite_list_057D28_ADDRESS 0x7D28u    /* 057D28 */
#define sprite_list_057D40_ADDRESS 0x7D40u    /* 057D40 */
#define sprite_list_057D58_ADDRESS 0x7D58u    /* 057D58 */
#define sprite_list_057D6A_ADDRESS 0x7D6Au    /* 057D6A */
#define animation_057D70_ADDRESS 0x7D70u    /* 057D70 */
#define animation_057D78_ADDRESS 0x7D78u    /* 057D78 */
#define sprite_list_057D8C_ADDRESS 0x7D8Cu    /* 057D8C */
#define sprite_list_057D92_ADDRESS 0x7D92u    /* 057D92 */
#define sprite_list_057D98_ADDRESS 0x7D98u    /* 057D98 */
#define sprite_list_057D9E_ADDRESS 0x7D9Eu    /* 057D9E */
#define animation_057DA4_ADDRESS 0x7DA4u    /* 057DA4 */
#define sprite_list_057DB8_ADDRESS 0x7DB8u    /* 057DB8 */
#define sprite_list_057DCA_ADDRESS 0x7DCAu    /* 057DCA */
#define sprite_list_057DDC_ADDRESS 0x7DDCu    /* 057DDC */
#define sprite_list_057DEE_ADDRESS 0x7DEEu    /* 057DEE */
#define animation_057E00_ADDRESS 0x7E00u    /* 057E00 */
#define sprite_list_057E08_ADDRESS 0x7E08u    /* 057E08 */
#define animation_057E0E_ADDRESS 0x7E0Eu    /* 057E0E */
#define fill_057E16_ADDRESS 0x7E16u    /* 057E16 */
#define tile_blocks_058000_ADDRESS 0x6000u    /* 058000 */
#define map_058870_ADDRESS 0x6870u    /* 058870 */
#define map_strip_058874_ADDRESS 0x6874u    /* 058874 */
#define map_strip_0588F4_ADDRESS 0x68F4u    /* 0588F4 */
#define tile_blocks_058974_ADDRESS 0x6974u    /* 058974 */
#define unused_blocks_058B6C_ADDRESS 0x6B6Cu    /* 058B6C */
#define demo_inputs_058B7E_ADDRESS 0x6B7Eu    /* 058B7E */
#define demo_inputs_058D5E_ADDRESS 0x6D5Eu    /* 058D5E */
#define demo_inputs_058F76_ADDRESS 0x6F76u    /* 058F76 */
#define demo_inputs_059166_ADDRESS 0x7166u    /* 059166 */
#define demo_inputs_05938E_ADDRESS 0x738Eu    /* 05938E */
#define demo_inputs_05952E_ADDRESS 0x752Eu    /* 05952E */
#define fill_059760_ADDRESS 0x7760u    /* 059760 */
#define edge_block_059B1A_ADDRESS 0x7B1Au    /* 059B1A */
#define fill_059B2C_ADDRESS 0x7B2Cu    /* 059B2C */
#define edge_block_059B86_ADDRESS 0x7B86u    /* 059B86 */
#define fill_059B98_ADDRESS 0x7B98u    /* 059B98 */
#define edge_block_059C3A_ADDRESS 0x7C3Au    /* 059C3A */
#define fill_059C4C_ADDRESS 0x7C4Cu    /* 059C4C */
#define unreached_map_059EE8_ADDRESS 0x7EE8u    /* 059EE8 */
#define map_strip_059EEA_ADDRESS 0x7EEAu    /* 059EEA */
#define fill_059F6A_ADDRESS 0x7F6Au    /* 059F6A */
#define palettes_05A000_ADDRESS 0x6000u    /* 05A000 */
#define palettes_05A020_ADDRESS 0x6020u    /* 05A020 */
#define palettes_05A040_ADDRESS 0x6040u    /* 05A040 */
#define palettes_05A060_ADDRESS 0x6060u    /* 05A060 */
#define palettes_05A080_ADDRESS 0x6080u    /* 05A080 */
#define palettes_05A0A0_ADDRESS 0x60A0u    /* 05A0A0 */
#define palettes_05A0C0_ADDRESS 0x60C0u    /* 05A0C0 */
#define palettes_05A0E0_ADDRESS 0x60E0u    /* 05A0E0 */
#define palettes_05A100_ADDRESS 0x6100u    /* 05A100 */
#define palettes_05A120_ADDRESS 0x6120u    /* 05A120 */
#define palettes_05A140_ADDRESS 0x6140u    /* 05A140 */
#define palettes_05A160_ADDRESS 0x6160u    /* 05A160 */
#define palettes_05A180_ADDRESS 0x6180u    /* 05A180 */
#define palettes_05A1A0_ADDRESS 0x61A0u    /* 05A1A0 */
#define palettes_05A1C0_ADDRESS 0x61C0u    /* 05A1C0 */
#define palettes_05A1E0_ADDRESS 0x61E0u    /* 05A1E0 */
#define palettes_05A200_ADDRESS 0x6200u    /* 05A200 */
#define palettes_05A220_ADDRESS 0x6220u    /* 05A220 */
#define palettes_05A240_ADDRESS 0x6240u    /* 05A240 */
#define palettes_05A260_ADDRESS 0x6260u    /* 05A260 */
#define palettes_05A280_ADDRESS 0x6280u    /* 05A280 */
#define palettes_05A2A0_ADDRESS 0x62A0u    /* 05A2A0 */
#define palettes_05A2C0_ADDRESS 0x62C0u    /* 05A2C0 */
#define palettes_05A2E0_ADDRESS 0x62E0u    /* 05A2E0 */
#define palettes_05A300_ADDRESS 0x6300u    /* 05A300 */
#define palettes_05A320_ADDRESS 0x6320u    /* 05A320 */
#define palettes_05A340_ADDRESS 0x6340u    /* 05A340 */
#define palettes_05A360_ADDRESS 0x6360u    /* 05A360 */
#define palettes_05A380_ADDRESS 0x6380u    /* 05A380 */
#define palettes_05A3A0_ADDRESS 0x63A0u    /* 05A3A0 */
#define palettes_05A3C0_ADDRESS 0x63C0u    /* 05A3C0 */
#define palettes_05A3E0_ADDRESS 0x63E0u    /* 05A3E0 */
#define palettes_05A400_ADDRESS 0x6400u    /* 05A400 */
#define palettes_05A420_ADDRESS 0x6420u    /* 05A420 */
#define palettes_05A440_ADDRESS 0x6440u    /* 05A440 */
#define palettes_05A460_ADDRESS 0x6460u    /* 05A460 */
#define palettes_05A480_ADDRESS 0x6480u    /* 05A480 */
#define palettes_05A4A0_ADDRESS 0x64A0u    /* 05A4A0 */
#define palettes_05A4C0_ADDRESS 0x64C0u    /* 05A4C0 */
#define palettes_05A4E0_ADDRESS 0x64E0u    /* 05A4E0 */
#define palettes_05A500_ADDRESS 0x6500u    /* 05A500 */
#define palettes_05A520_ADDRESS 0x6520u    /* 05A520 */
#define palettes_05A540_ADDRESS 0x6540u    /* 05A540 */
#define palettes_05A560_ADDRESS 0x6560u    /* 05A560 */
#define palettes_05A580_ADDRESS 0x6580u    /* 05A580 */
#define palettes_05A5A0_ADDRESS 0x65A0u    /* 05A5A0 */
#define palettes_05A5C0_ADDRESS 0x65C0u    /* 05A5C0 */
#define palettes_05A5E0_ADDRESS 0x65E0u    /* 05A5E0 */
#define palettes_05A600_ADDRESS 0x6600u    /* 05A600 */
#define palettes_05A620_ADDRESS 0x6620u    /* 05A620 */
#define palettes_05A640_ADDRESS 0x6640u    /* 05A640 */
#define palettes_05A660_ADDRESS 0x6660u    /* 05A660 */
#define palettes_05A680_ADDRESS 0x6680u    /* 05A680 */
#define palettes_05A6A0_ADDRESS 0x66A0u    /* 05A6A0 */
#define palettes_05A6C0_ADDRESS 0x66C0u    /* 05A6C0 */
#define palettes_05A6E0_ADDRESS 0x66E0u    /* 05A6E0 */
#define palettes_05A700_ADDRESS 0x6700u    /* 05A700 */
#define palettes_05A720_ADDRESS 0x6720u    /* 05A720 */
#define palettes_05A740_ADDRESS 0x6740u    /* 05A740 */
#define palettes_05A760_ADDRESS 0x6760u    /* 05A760 */
#define palettes_05A780_ADDRESS 0x6780u    /* 05A780 */
#define palettes_05A7A0_ADDRESS 0x67A0u    /* 05A7A0 */
#define palettes_05A7C0_ADDRESS 0x67C0u    /* 05A7C0 */
#define palettes_05A7E0_ADDRESS 0x67E0u    /* 05A7E0 */
#define palettes_05A800_ADDRESS 0x6800u    /* 05A800 */
#define palettes_05A820_ADDRESS 0x6820u    /* 05A820 */
#define palettes_05A840_ADDRESS 0x6840u    /* 05A840 */
#define palettes_05A860_ADDRESS 0x6860u    /* 05A860 */
#define palettes_05A880_ADDRESS 0x6880u    /* 05A880 */
#define palettes_05A8A0_ADDRESS 0x68A0u    /* 05A8A0 */
#define palettes_05A8C0_ADDRESS 0x68C0u    /* 05A8C0 */
#define palettes_05A8E0_ADDRESS 0x68E0u    /* 05A8E0 */
#define palettes_05A900_ADDRESS 0x6900u    /* 05A900 */
#define palettes_05A920_ADDRESS 0x6920u    /* 05A920 */
#define palettes_05A940_ADDRESS 0x6940u    /* 05A940 */
#define palettes_05A960_ADDRESS 0x6960u    /* 05A960 */
#define palettes_05A980_ADDRESS 0x6980u    /* 05A980 */
#define palettes_05A9A0_ADDRESS 0x69A0u    /* 05A9A0 */
#define palettes_05A9C0_ADDRESS 0x69C0u    /* 05A9C0 */
#define palettes_05A9E0_ADDRESS 0x69E0u    /* 05A9E0 */
#define palettes_05AA00_ADDRESS 0x6A00u    /* 05AA00 */
#define palettes_05AA20_ADDRESS 0x6A20u    /* 05AA20 */
#define palettes_05AA40_ADDRESS 0x6A40u    /* 05AA40 */
#define palettes_05AA60_ADDRESS 0x6A60u    /* 05AA60 */
#define palettes_05AA80_ADDRESS 0x6A80u    /* 05AA80 */
#define palettes_05AAA0_ADDRESS 0x6AA0u    /* 05AAA0 */
#define palettes_05AAC0_ADDRESS 0x6AC0u    /* 05AAC0 */
#define palettes_05AAE0_ADDRESS 0x6AE0u    /* 05AAE0 */
#define palettes_05AB00_ADDRESS 0x6B00u    /* 05AB00 */
#define palettes_05AB20_ADDRESS 0x6B20u    /* 05AB20 */
#define palettes_05AB40_ADDRESS 0x6B40u    /* 05AB40 */
#define palettes_05AB60_ADDRESS 0x6B60u    /* 05AB60 */
#define palettes_05AB80_ADDRESS 0x6B80u    /* 05AB80 */
#define palettes_05ABA0_ADDRESS 0x6BA0u    /* 05ABA0 */
#define palettes_05ABC0_ADDRESS 0x6BC0u    /* 05ABC0 */
#define palettes_05ABE0_ADDRESS 0x6BE0u    /* 05ABE0 */
#define palettes_05AC00_ADDRESS 0x6C00u    /* 05AC00 */
#define palettes_05AC20_ADDRESS 0x6C20u    /* 05AC20 */
#define palettes_05AC40_ADDRESS 0x6C40u    /* 05AC40 */
#define palettes_05AC60_ADDRESS 0x6C60u    /* 05AC60 */
#define palettes_05AC80_ADDRESS 0x6C80u    /* 05AC80 */
#define palettes_05ACA0_ADDRESS 0x6CA0u    /* 05ACA0 */
#define palettes_05ACC0_ADDRESS 0x6CC0u    /* 05ACC0 */
#define palettes_05ACE0_ADDRESS 0x6CE0u    /* 05ACE0 */
#define palettes_05AD00_ADDRESS 0x6D00u    /* 05AD00 */
#define palettes_05AD20_ADDRESS 0x6D20u    /* 05AD20 */
#define palettes_05AD40_ADDRESS 0x6D40u    /* 05AD40 */
#define palettes_05AD60_ADDRESS 0x6D60u    /* 05AD60 */
#define palettes_05AD80_ADDRESS 0x6D80u    /* 05AD80 */
#define palettes_05ADA0_ADDRESS 0x6DA0u    /* 05ADA0 */
#define palettes_05ADC0_ADDRESS 0x6DC0u    /* 05ADC0 */
#define palettes_05ADE0_ADDRESS 0x6DE0u    /* 05ADE0 */
#define palettes_05AE00_ADDRESS 0x6E00u    /* 05AE00 */
#define palettes_05AE20_ADDRESS 0x6E20u    /* 05AE20 */
#define palettes_05AE40_ADDRESS 0x6E40u    /* 05AE40 */
#define palettes_05AE60_ADDRESS 0x6E60u    /* 05AE60 */
#define palettes_05AE80_ADDRESS 0x6E80u    /* 05AE80 */
#define palettes_05AEA0_ADDRESS 0x6EA0u    /* 05AEA0 */
#define palettes_05AEC0_ADDRESS 0x6EC0u    /* 05AEC0 */
#define palettes_05AEE0_ADDRESS 0x6EE0u    /* 05AEE0 */
#define palettes_05AF00_ADDRESS 0x6F00u    /* 05AF00 */
#define palettes_05AF20_ADDRESS 0x6F20u    /* 05AF20 */
#define palettes_05AF40_ADDRESS 0x6F40u    /* 05AF40 */
#define palettes_05AF60_ADDRESS 0x6F60u    /* 05AF60 */
#define palettes_05AF80_ADDRESS 0x6F80u    /* 05AF80 */
#define palettes_05AFA0_ADDRESS 0x6FA0u    /* 05AFA0 */
#define palettes_05AFC0_ADDRESS 0x6FC0u    /* 05AFC0 */
#define palettes_05AFE0_ADDRESS 0x6FE0u    /* 05AFE0 */
#define palettes_05B000_ADDRESS 0x7000u    /* 05B000 */
#define palettes_05B020_ADDRESS 0x7020u    /* 05B020 */
#define palettes_05B040_ADDRESS 0x7040u    /* 05B040 */
#define palettes_05B060_ADDRESS 0x7060u    /* 05B060 */
#define palettes_05B080_ADDRESS 0x7080u    /* 05B080 */
#define palettes_05B0A0_ADDRESS 0x70A0u    /* 05B0A0 */
#define unused_palettes_05B0C0_ADDRESS 0x70C0u    /* 05B0C0 */
#define palettes_05B180_ADDRESS 0x7180u    /* 05B180 */
#define palettes_05B1A0_ADDRESS 0x71A0u    /* 05B1A0 */
#define palettes_05B1C0_ADDRESS 0x71C0u    /* 05B1C0 */
#define palettes_05B1E0_ADDRESS 0x71E0u    /* 05B1E0 */
#define palettes_05B200_ADDRESS 0x7200u    /* 05B200 */
#define palettes_05B220_ADDRESS 0x7220u    /* 05B220 */
#define palettes_05B240_ADDRESS 0x7240u    /* 05B240 */
#define palettes_05B260_ADDRESS 0x7260u    /* 05B260 */
#define palettes_05B280_ADDRESS 0x7280u    /* 05B280 */
#define palettes_05B2A0_ADDRESS 0x72A0u    /* 05B2A0 */
#define palettes_05B2C0_ADDRESS 0x72C0u    /* 05B2C0 */
#define palettes_05B2E0_ADDRESS 0x72E0u    /* 05B2E0 */
#define palettes_05B300_ADDRESS 0x7300u    /* 05B300 */
#define palettes_05B320_ADDRESS 0x7320u    /* 05B320 */
#define palettes_05B340_ADDRESS 0x7340u    /* 05B340 */
#define palettes_05B360_ADDRESS 0x7360u    /* 05B360 */
#define palettes_05B380_ADDRESS 0x7380u    /* 05B380 */
#define palettes_05B3A0_ADDRESS 0x73A0u    /* 05B3A0 */
#define palettes_05B3C0_ADDRESS 0x73C0u    /* 05B3C0 */
#define palettes_05B3E0_ADDRESS 0x73E0u    /* 05B3E0 */
#define palettes_05B400_ADDRESS 0x7400u    /* 05B400 */
#define palettes_05B420_ADDRESS 0x7420u    /* 05B420 */
#define palettes_05B440_ADDRESS 0x7440u    /* 05B440 */
#define palettes_05B460_ADDRESS 0x7460u    /* 05B460 */
#define palettes_05B480_ADDRESS 0x7480u    /* 05B480 */
#define palettes_05B4A0_ADDRESS 0x74A0u    /* 05B4A0 */
#define palettes_05B4C0_ADDRESS 0x74C0u    /* 05B4C0 */
#define palettes_05B4E0_ADDRESS 0x74E0u    /* 05B4E0 */
#define palettes_05B500_ADDRESS 0x7500u    /* 05B500 */
#define palettes_05B520_ADDRESS 0x7520u    /* 05B520 */
#define palettes_05B540_ADDRESS 0x7540u    /* 05B540 */
#define palettes_05B560_ADDRESS 0x7560u    /* 05B560 */
#define palettes_05B580_ADDRESS 0x7580u    /* 05B580 */
#define palettes_05B5A0_ADDRESS 0x75A0u    /* 05B5A0 */
#define palettes_05B5C0_ADDRESS 0x75C0u    /* 05B5C0 */
#define palettes_05B5E0_ADDRESS 0x75E0u    /* 05B5E0 */
#define palettes_05B600_ADDRESS 0x7600u    /* 05B600 */
#define palettes_05B620_ADDRESS 0x7620u    /* 05B620 */
#define palettes_05B640_ADDRESS 0x7640u    /* 05B640 */
#define palettes_05B660_ADDRESS 0x7660u    /* 05B660 */
#define palettes_05B680_ADDRESS 0x7680u    /* 05B680 */
#define palettes_05B6A0_ADDRESS 0x76A0u    /* 05B6A0 */
#define palettes_05B6C0_ADDRESS 0x76C0u    /* 05B6C0 */
#define palettes_05B6E0_ADDRESS 0x76E0u    /* 05B6E0 */
#define palettes_05B700_ADDRESS 0x7700u    /* 05B700 */
#define palettes_05B720_ADDRESS 0x7720u    /* 05B720 */
#define palettes_05B740_ADDRESS 0x7740u    /* 05B740 */
#define palettes_05B760_ADDRESS 0x7760u    /* 05B760 */
#define palettes_05B780_ADDRESS 0x7780u    /* 05B780 */
#define palettes_05B7A0_ADDRESS 0x77A0u    /* 05B7A0 */
#define palettes_05B7C0_ADDRESS 0x77C0u    /* 05B7C0 */
#define palettes_05B7E0_ADDRESS 0x77E0u    /* 05B7E0 */
#define palettes_05B800_ADDRESS 0x7800u    /* 05B800 */
#define palettes_05B820_ADDRESS 0x7820u    /* 05B820 */
#define palettes_05B840_ADDRESS 0x7840u    /* 05B840 */
#define palettes_05B860_ADDRESS 0x7860u    /* 05B860 */
#define palettes_05B880_ADDRESS 0x7880u    /* 05B880 */
#define palettes_05B8A0_ADDRESS 0x78A0u    /* 05B8A0 */
#define palettes_05B8C0_ADDRESS 0x78C0u    /* 05B8C0 */
#define palettes_05B8E0_ADDRESS 0x78E0u    /* 05B8E0 */
#define palettes_05B900_ADDRESS 0x7900u    /* 05B900 */
#define palettes_05B920_ADDRESS 0x7920u    /* 05B920 */
#define palettes_05B940_ADDRESS 0x7940u    /* 05B940 */
#define palettes_05B960_ADDRESS 0x7960u    /* 05B960 */
#define palettes_05B980_ADDRESS 0x7980u    /* 05B980 */
#define palettes_05B9A0_ADDRESS 0x79A0u    /* 05B9A0 */
#define palettes_05B9C0_ADDRESS 0x79C0u    /* 05B9C0 */
#define palettes_05B9E0_ADDRESS 0x79E0u    /* 05B9E0 */
#define palettes_05BA00_ADDRESS 0x7A00u    /* 05BA00 */
#define palettes_05BA20_ADDRESS 0x7A20u    /* 05BA20 */
#define palettes_05BA40_ADDRESS 0x7A40u    /* 05BA40 */
#define palettes_05BA60_ADDRESS 0x7A60u    /* 05BA60 */
#define palettes_05BA80_ADDRESS 0x7A80u    /* 05BA80 */
#define palettes_05BAA0_ADDRESS 0x7AA0u    /* 05BAA0 */
#define palettes_05BAC0_ADDRESS 0x7AC0u    /* 05BAC0 */
#define palettes_05BAE0_ADDRESS 0x7AE0u    /* 05BAE0 */
#define palettes_05BB00_ADDRESS 0x7B00u    /* 05BB00 */
#define palettes_05BB20_ADDRESS 0x7B20u    /* 05BB20 */
#define palettes_05BB40_ADDRESS 0x7B40u    /* 05BB40 */
#define palettes_05BB60_ADDRESS 0x7B60u    /* 05BB60 */
#define palettes_05BB80_ADDRESS 0x7B80u    /* 05BB80 */
#define palettes_05BBA0_ADDRESS 0x7BA0u    /* 05BBA0 */
#define palettes_05BBC0_ADDRESS 0x7BC0u    /* 05BBC0 */
#define palettes_05BBE0_ADDRESS 0x7BE0u    /* 05BBE0 */
#define palettes_05BC00_ADDRESS 0x7C00u    /* 05BC00 */
#define palettes_05BC20_ADDRESS 0x7C20u    /* 05BC20 */
#define palettes_05BC40_ADDRESS 0x7C40u    /* 05BC40 */
#define palettes_05BC60_ADDRESS 0x7C60u    /* 05BC60 */
#define palettes_05BC80_ADDRESS 0x7C80u    /* 05BC80 */
#define palettes_05BCA0_ADDRESS 0x7CA0u    /* 05BCA0 */
#define palettes_05BCC0_ADDRESS 0x7CC0u    /* 05BCC0 */
#define palettes_05BCE0_ADDRESS 0x7CE0u    /* 05BCE0 */
#define palettes_05BD00_ADDRESS 0x7D00u    /* 05BD00 */
#define palettes_05BD20_ADDRESS 0x7D20u    /* 05BD20 */
#define palettes_05BD40_ADDRESS 0x7D40u    /* 05BD40 */
#define palettes_05BD60_ADDRESS 0x7D60u    /* 05BD60 */
#define palettes_05BD80_ADDRESS 0x7D80u    /* 05BD80 */
#define palettes_05BDA0_ADDRESS 0x7DA0u    /* 05BDA0 */
#define palettes_05BDC0_ADDRESS 0x7DC0u    /* 05BDC0 */
#define palettes_05BDE0_ADDRESS 0x7DE0u    /* 05BDE0 */
#define palettes_05BE00_ADDRESS 0x7E00u    /* 05BE00 */
#define palettes_05BE20_ADDRESS 0x7E20u    /* 05BE20 */
#define palettes_05BE40_ADDRESS 0x7E40u    /* 05BE40 */
#define palettes_05BE60_ADDRESS 0x7E60u    /* 05BE60 */
#define palettes_05BE80_ADDRESS 0x7E80u    /* 05BE80 */
#define palettes_05BEA0_ADDRESS 0x7EA0u    /* 05BEA0 */
#define palettes_05BEC0_ADDRESS 0x7EC0u    /* 05BEC0 */
#define palettes_05BEE0_ADDRESS 0x7EE0u    /* 05BEE0 */
#define palettes_05BF00_ADDRESS 0x7F00u    /* 05BF00 */
#define palettes_05BF20_ADDRESS 0x7F20u    /* 05BF20 */
#define palettes_05BF40_ADDRESS 0x7F40u    /* 05BF40 */
#define palettes_05BF60_ADDRESS 0x7F60u    /* 05BF60 */
#define palettes_05BF80_ADDRESS 0x7F80u    /* 05BF80 */
#define palettes_05BFA0_ADDRESS 0x7FA0u    /* 05BFA0 */
#define palettes_05BFC0_ADDRESS 0x7FC0u    /* 05BFC0 */
#define fill_05BFE0_ADDRESS 0x7FE0u    /* 05BFE0 */
#define palette_effects_05C000_ADDRESS 0x6000u    /* 05C000 */
#define palette_effect_05C092_ADDRESS 0x6092u    /* 05C092 */
#define palette_effect_05C0D7_ADDRESS 0x60D7u    /* 05C0D7 */
#define palette_effect_05C11B_ADDRESS 0x611Bu    /* 05C11B */
#define palette_effect_05C174_ADDRESS 0x6174u    /* 05C174 */
#define palette_effect_05C18C_ADDRESS 0x618Cu    /* 05C18C */
#define palette_effect_05C1F1_ADDRESS 0x61F1u    /* 05C1F1 */
#define palette_effect_05C21A_ADDRESS 0x621Au    /* 05C21A */
#define palette_effect_05C233_ADDRESS 0x6233u    /* 05C233 */
#define palette_effect_05C248_ADDRESS 0x6248u    /* 05C248 */
#define palette_effect_05C25D_ADDRESS 0x625Du    /* 05C25D */
#define palette_effect_05C272_ADDRESS 0x6272u    /* 05C272 */
#define palette_effect_05C287_ADDRESS 0x6287u    /* 05C287 */
#define palette_effect_05C2CC_ADDRESS 0x62CCu    /* 05C2CC */
#define palette_effect_05C2E1_ADDRESS 0x62E1u    /* 05C2E1 */
#define palette_effect_05C36A_ADDRESS 0x636Au    /* 05C36A */
#define palette_effect_05C3D3_ADDRESS 0x63D3u    /* 05C3D3 */
#define palette_effect_05C4CB_ADDRESS 0x64CBu    /* 05C4CB */
#define palette_effect_05C563_ADDRESS 0x6563u    /* 05C563 */
#define palette_effect_05C58F_ADDRESS 0x658Fu    /* 05C58F */
#define palette_effect_05C5D7_ADDRESS 0x65D7u    /* 05C5D7 */
#define palette_effect_05C61F_ADDRESS 0x661Fu    /* 05C61F */
#define palette_effect_05C64B_ADDRESS 0x664Bu    /* 05C64B */
#define palette_effect_05C66B_ADDRESS 0x666Bu    /* 05C66B */
#define palette_effect_05C718_ADDRESS 0x6718u    /* 05C718 */
#define palette_effect_05C77D_ADDRESS 0x677Du    /* 05C77D */
#define palette_effect_05C862_ADDRESS 0x6862u    /* 05C862 */
#define palette_effect_05C8F3_ADDRESS 0x68F3u    /* 05C8F3 */
#define palette_effect_05C968_ADDRESS 0x6968u    /* 05C968 */
#define palette_effect_05C97D_ADDRESS 0x697Du    /* 05C97D */
#define palette_effect_05CAC9_ADDRESS 0x6AC9u    /* 05CAC9 */
#define palette_effect_05CC15_ADDRESS 0x6C15u    /* 05CC15 */
#define palette_effect_05CD61_ADDRESS 0x6D61u    /* 05CD61 */
#define palette_effect_05CEAD_ADDRESS 0x6EADu    /* 05CEAD */
#define palette_effect_05CF5A_ADDRESS 0x6F5Au    /* 05CF5A */
#define palette_effect_05CFBF_ADDRESS 0x6FBFu    /* 05CFBF */
#define palette_effect_05CFD8_ADDRESS 0x6FD8u    /* 05CFD8 */
#define palette_effect_05CFF1_ADDRESS 0x6FF1u    /* 05CFF1 */
#define palette_effect_05D00A_ADDRESS 0x700Au    /* 05D00A */
#define palette_effect_05D023_ADDRESS 0x7023u    /* 05D023 */
#define palette_effect_05D06B_ADDRESS 0x706Bu    /* 05D06B */
#define palette_effect_05D094_ADDRESS 0x7094u    /* 05D094 */
#define palette_effect_05D0FD_ADDRESS 0x70FDu    /* 05D0FD */
#define palette_effect_05D141_ADDRESS 0x7141u    /* 05D141 */
#define palette_effect_05D19D_ADDRESS 0x719Du    /* 05D19D */
#define palette_effect_05D1B9_ADDRESS 0x71B9u    /* 05D1B9 */
#define palette_effect_05D23D_ADDRESS 0x723Du    /* 05D23D */
#define palette_effect_05D2A9_ADDRESS 0x72A9u    /* 05D2A9 */
#define palette_effect_05D2C9_ADDRESS 0x72C9u    /* 05D2C9 */
#define palette_effect_05D365_ADDRESS 0x7365u    /* 05D365 */
#define palette_effect_05D401_ADDRESS 0x7401u    /* 05D401 */
#define palette_effect_05D421_ADDRESS 0x7421u    /* 05D421 */
#define palette_effect_05D48D_ADDRESS 0x748Du    /* 05D48D */
#define palette_effect_05D4C9_ADDRESS 0x74C9u    /* 05D4C9 */
#define palette_effect_05D4D9_ADDRESS 0x74D9u    /* 05D4D9 */
#define palette_effect_05D50D_ADDRESS 0x750Du    /* 05D50D */
#define palette_effect_05D5C1_ADDRESS 0x75C1u    /* 05D5C1 */
#define palette_effect_05D5E5_ADDRESS 0x75E5u    /* 05D5E5 */
#define palette_effect_05D661_ADDRESS 0x7661u    /* 05D661 */
#define palette_effect_05D9ED_ADDRESS 0x79EDu    /* 05D9ED */
#define palette_effect_05DABD_ADDRESS 0x7ABDu    /* 05DABD */
#define palette_effect_05DAD5_ADDRESS 0x7AD5u    /* 05DAD5 */
#define palette_effect_05DAF5_ADDRESS 0x7AF5u    /* 05DAF5 */
#define palette_effect_05DB15_ADDRESS 0x7B15u    /* 05DB15 */
#define palette_effect_05DB4D_ADDRESS 0x7B4Du    /* 05DB4D */
#define palette_effect_05DBF2_ADDRESS 0x7BF2u    /* 05DBF2 */
#define palette_effect_05DC73_ADDRESS 0x7C73u    /* 05DC73 */
#define palette_effect_05DCF4_ADDRESS 0x7CF4u    /* 05DCF4 */
#define palette_effect_05DD10_ADDRESS 0x7D10u    /* 05DD10 */
#define palette_effect_05DD40_ADDRESS 0x7D40u    /* 05DD40 */
#define palette_effect_05DD90_ADDRESS 0x7D90u    /* 05DD90 */
#define palette_effect_05DDE0_ADDRESS 0x7DE0u    /* 05DDE0 */
#define palette_effect_05DE00_ADDRESS 0x7E00u    /* 05DE00 */
#define palette_effect_05DE40_ADDRESS 0x7E40u    /* 05DE40 */
#define fill_05DE6D_ADDRESS 0x7E6Du    /* 05DE6D */
#define loaded_table_05E047_ADDRESS 0x6047u    /* 05E047 */
#define loaded_table_05E0A1_ADDRESS 0x60A1u    /* 05E0A1 */
#define loaded_table_05E0C9_ADDRESS 0x60C9u    /* 05E0C9 */
#define loaded_table_05E0F2_ADDRESS 0x60F2u    /* 05E0F2 */
#define loaded_table_05E17D_ADDRESS 0x617Du    /* 05E17D */
#define loaded_table_05E21B_ADDRESS 0x621Bu    /* 05E21B */
#define loaded_table_05E277_ADDRESS 0x6277u    /* 05E277 */
#define loaded_table_05E2C9_ADDRESS 0x62C9u    /* 05E2C9 */
#define loaded_table_05E42B_ADDRESS 0x642Bu    /* 05E42B */
#define loaded_table_05E46D_ADDRESS 0x646Du    /* 05E46D */
#define loaded_table_05E691_ADDRESS 0x6691u    /* 05E691 */
#define fill_05EFA8_ADDRESS 0x6FA8u    /* 05EFA8 */
#define loaded_table_05F1E0_ADDRESS 0x71E0u    /* 05F1E0 */
#define loaded_table_05F580_ADDRESS 0x7580u    /* 05F580 */
#define test_mode_page_05F5EE_ADDRESS 0x75EEu    /* 05F5EE */
#define test_mode_page_05F634_ADDRESS 0x7634u    /* 05F634 */
#define test_mode_page_05F640_ADDRESS 0x7640u    /* 05F640 */
#define test_mode_page_05F64C_ADDRESS 0x764Cu    /* 05F64C */
#define test_mode_page_05F658_ADDRESS 0x7658u    /* 05F658 */
#define test_mode_page_05F68C_ADDRESS 0x768Cu    /* 05F68C */
#define test_mode_page_05F6AE_ADDRESS 0x76AEu    /* 05F6AE */
#define test_mode_page_05F6D0_ADDRESS 0x76D0u    /* 05F6D0 */
#define test_mode_page_05F6E8_ADDRESS 0x76E8u    /* 05F6E8 */
#define test_mode_page_05F71D_ADDRESS 0x771Du    /* 05F71D */
#define test_mode_page_05F75C_ADDRESS 0x775Cu    /* 05F75C */
#define test_mode_page_05F76D_ADDRESS 0x776Du    /* 05F76D */
#define test_mode_page_05F7AA_ADDRESS 0x77AAu    /* 05F7AA */
#define test_mode_page_05F7CE_ADDRESS 0x77CEu    /* 05F7CE */
#define test_mode_page_05F7DF_ADDRESS 0x77DFu    /* 05F7DF */
#define test_mode_page_05F7F7_ADDRESS 0x77F7u    /* 05F7F7 */
#define test_mode_page_05F80F_ADDRESS 0x780Fu    /* 05F80F */
#define test_mode_page_05F823_ADDRESS 0x7823u    /* 05F823 */
#define test_mode_page_05F845_ADDRESS 0x7845u    /* 05F845 */
#define test_mode_page_05F881_ADDRESS 0x7881u    /* 05F881 */
#define test_mode_page_05F8BD_ADDRESS 0x78BDu    /* 05F8BD */
#define test_mode_text_05F965_ADDRESS 0x7965u    /* 05F965 */
#define test_mode_text_05F96B_ADDRESS 0x796Bu    /* 05F96B */
#define test_mode_text_05F977_ADDRESS 0x7977u    /* 05F977 */
#define test_mode_text_05F97F_ADDRESS 0x797Fu    /* 05F97F */
#define test_mode_text_05F984_ADDRESS 0x7984u    /* 05F984 */
#define test_mode_text_05F98C_ADDRESS 0x798Cu    /* 05F98C */
#define test_mode_text_05F9BA_ADDRESS 0x79BAu    /* 05F9BA */
#define test_mode_text_05F9C2_ADDRESS 0x79C2u    /* 05F9C2 */
#define test_mode_text_05F9CD_ADDRESS 0x79CDu    /* 05F9CD */
#define test_mode_text_05F9D7_ADDRESS 0x79D7u    /* 05F9D7 */
#define test_mode_text_05F9DE_ADDRESS 0x79DEu    /* 05F9DE */
#define test_mode_text_05F9E4_ADDRESS 0x79E4u    /* 05F9E4 */
#define test_mode_text_05F9EA_ADDRESS 0x79EAu    /* 05F9EA */
#define test_mode_text_05F9FC_ADDRESS 0x79FCu    /* 05F9FC */
#define test_mode_text_05FA04_ADDRESS 0x7A04u    /* 05FA04 */
#define test_mode_text_05FA0C_ADDRESS 0x7A0Cu    /* 05FA0C */
#define test_mode_text_05FA14_ADDRESS 0x7A14u    /* 05FA14 */
#define test_mode_text_05FA2B_ADDRESS 0x7A2Bu    /* 05FA2B */
#define test_mode_text_05FA42_ADDRESS 0x7A42u    /* 05FA42 */
#define test_mode_text_05FA4F_ADDRESS 0x7A4Fu    /* 05FA4F */
#define test_mode_text_05FA5C_ADDRESS 0x7A5Cu    /* 05FA5C */
#define test_mode_text_05FA6E_ADDRESS 0x7A6Eu    /* 05FA6E */
#define test_mode_text_05FA80_ADDRESS 0x7A80u    /* 05FA80 */
#define test_mode_text_05FA8A_ADDRESS 0x7A8Au    /* 05FA8A */
#define test_mode_text_05FA8F_ADDRESS 0x7A8Fu    /* 05FA8F */
#define test_mode_text_05FA95_ADDRESS 0x7A95u    /* 05FA95 */
#define test_mode_text_05FA9B_ADDRESS 0x7A9Bu    /* 05FA9B */
#define test_mode_text_05FAA0_ADDRESS 0x7AA0u    /* 05FAA0 */
#define test_mode_text_05FAA8_ADDRESS 0x7AA8u    /* 05FAA8 */
#define test_mode_text_05FAB2_ADDRESS 0x7AB2u    /* 05FAB2 */
#define test_mode_text_05FAB5_ADDRESS 0x7AB5u    /* 05FAB5 */
#define test_mode_text_05FABA_ADDRESS 0x7ABAu    /* 05FABA */
#define test_mode_text_05FAC1_ADDRESS 0x7AC1u    /* 05FAC1 */
#define test_mode_text_05FAC8_ADDRESS 0x7AC8u    /* 05FAC8 */
#define test_mode_text_05FACE_ADDRESS 0x7ACEu    /* 05FACE */
#define test_mode_text_05FAD5_ADDRESS 0x7AD5u    /* 05FAD5 */
#define test_mode_text_05FADE_ADDRESS 0x7ADEu    /* 05FADE */
#define test_mode_text_05FAE7_ADDRESS 0x7AE7u    /* 05FAE7 */
#define test_mode_text_05FAEE_ADDRESS 0x7AEEu    /* 05FAEE */
#define test_mode_text_05FAF2_ADDRESS 0x7AF2u    /* 05FAF2 */
#define test_mode_text_05FAF7_ADDRESS 0x7AF7u    /* 05FAF7 */
#define test_mode_text_05FAFA_ADDRESS 0x7AFAu    /* 05FAFA */
#define test_mode_text_05FB03_ADDRESS 0x7B03u    /* 05FB03 */
#define test_mode_text_05FB15_ADDRESS 0x7B15u    /* 05FB15 */
#define test_mode_text_05FB1D_ADDRESS 0x7B1Du    /* 05FB1D */
#define test_mode_text_05FB25_ADDRESS 0x7B25u    /* 05FB25 */
#define test_mode_text_05FB2F_ADDRESS 0x7B2Fu    /* 05FB2F */
#define test_mode_text_05FB35_ADDRESS 0x7B35u    /* 05FB35 */
#define test_mode_text_05FB39_ADDRESS 0x7B39u    /* 05FB39 */
#define test_mode_text_05FB3D_ADDRESS 0x7B3Du    /* 05FB3D */
#define test_mode_text_05FB49_ADDRESS 0x7B49u    /* 05FB49 */
#define test_mode_text_05FB52_ADDRESS 0x7B52u    /* 05FB52 */
#define test_mode_text_05FB5A_ADDRESS 0x7B5Au    /* 05FB5A */
#define loaded_table_05FB65_ADDRESS 0x7B65u    /* 05FB65 */
#define loaded_table_05FB68_ADDRESS 0x7B68u    /* 05FB68 */
#define indexed_table_05FC7C_ADDRESS 0x7C7Cu    /* 05FC7C */
#define indexed_table_05FC9A_ADDRESS 0x7C9Au    /* 05FC9A */
#define indexed_table_05FCC7_ADDRESS 0x7CC7u    /* 05FCC7 */
#define indexed_table_05FCCC_ADDRESS 0x7CCCu    /* 05FCCC */
#define indexed_table_05FCF7_ADDRESS 0x7CF7u    /* 05FCF7 */
#define indexed_table_05FD08_ADDRESS 0x7D08u    /* 05FD08 */
#define loaded_table_05FD23_ADDRESS 0x7D23u    /* 05FD23 */
#define loaded_table_05FD36_ADDRESS 0x7D36u    /* 05FD36 */
#define loaded_table_05FD42_ADDRESS 0x7D42u    /* 05FD42 */
#define loaded_table_05FD78_ADDRESS 0x7D78u    /* 05FD78 */
#define loaded_table_05FD7C_ADDRESS 0x7D7Cu    /* 05FD7C */
#define loaded_table_05FDD8_ADDRESS 0x7DD8u    /* 05FDD8 */
#define set_index_060000_ADDRESS 0x6000u    /* 060000 */
#define animation_table_060008_ADDRESS 0x6008u    /* 060008 */
#define animation_060108_ADDRESS 0x6108u    /* 060108 */
#define sprite_list_060110_ADDRESS 0x6110u    /* 060110 */
#define animation_06011C_ADDRESS 0x611Cu    /* 06011C */
#define sprite_list_060124_ADDRESS 0x6124u    /* 060124 */
#define animation_06012A_ADDRESS 0x612Au    /* 06012A */
#define sprite_list_060132_ADDRESS 0x6132u    /* 060132 */
#define animation_06013E_ADDRESS 0x613Eu    /* 06013E */
#define sprite_list_060146_ADDRESS 0x6146u    /* 060146 */
#define animation_06015E_ADDRESS 0x615Eu    /* 06015E */
#define sprite_list_060182_ADDRESS 0x6182u    /* 060182 */
#define sprite_list_06019A_ADDRESS 0x619Au    /* 06019A */
#define sprite_list_0601B2_ADDRESS 0x61B2u    /* 0601B2 */
#define sprite_list_0601CA_ADDRESS 0x61CAu    /* 0601CA */
#define sprite_list_0601E2_ADDRESS 0x61E2u    /* 0601E2 */
#define sprite_list_0601FA_ADDRESS 0x61FAu    /* 0601FA */
#define sprite_list_060212_ADDRESS 0x6212u    /* 060212 */
#define sprite_list_06022A_ADDRESS 0x622Au    /* 06022A */
#define animation_060242_ADDRESS 0x6242u    /* 060242 */
#define sprite_list_060266_ADDRESS 0x6266u    /* 060266 */
#define sprite_list_060272_ADDRESS 0x6272u    /* 060272 */
#define sprite_list_06027E_ADDRESS 0x627Eu    /* 06027E */
#define sprite_list_06028A_ADDRESS 0x628Au    /* 06028A */
#define sprite_list_060296_ADDRESS 0x6296u    /* 060296 */
#define sprite_list_0602A2_ADDRESS 0x62A2u    /* 0602A2 */
#define sprite_list_0602AE_ADDRESS 0x62AEu    /* 0602AE */
#define sprite_list_0602BA_ADDRESS 0x62BAu    /* 0602BA */
#define animation_0602C6_ADDRESS 0x62C6u    /* 0602C6 */
#define sprite_list_0602CE_ADDRESS 0x62CEu    /* 0602CE */
#define animation_0602E6_ADDRESS 0x62E6u    /* 0602E6 */
#define sprite_list_0602EE_ADDRESS 0x62EEu    /* 0602EE */
#define animation_060300_ADDRESS 0x6300u    /* 060300 */
#define sprite_list_06030C_ADDRESS 0x630Cu    /* 06030C */
#define sprite_list_06031E_ADDRESS 0x631Eu    /* 06031E */
#define animation_06032A_ADDRESS 0x632Au    /* 06032A */
#define sprite_list_060332_ADDRESS 0x6332u    /* 060332 */
#define animation_06034A_ADDRESS 0x634Au    /* 06034A */
#define sprite_list_06036E_ADDRESS 0x636Eu    /* 06036E */
#define sprite_list_060386_ADDRESS 0x6386u    /* 060386 */
#define sprite_list_06039E_ADDRESS 0x639Eu    /* 06039E */
#define sprite_list_0603B6_ADDRESS 0x63B6u    /* 0603B6 */
#define sprite_list_0603CE_ADDRESS 0x63CEu    /* 0603CE */
#define sprite_list_0603E6_ADDRESS 0x63E6u    /* 0603E6 */
#define sprite_list_0603FE_ADDRESS 0x63FEu    /* 0603FE */
#define sprite_list_060416_ADDRESS 0x6416u    /* 060416 */
#define animation_06042E_ADDRESS 0x642Eu    /* 06042E */
#define sprite_list_060436_ADDRESS 0x6436u    /* 060436 */
#define animation_060448_ADDRESS 0x6448u    /* 060448 */
#define sprite_list_060450_ADDRESS 0x6450u    /* 060450 */
#define animation_06045C_ADDRESS 0x645Cu    /* 06045C */
#define animation_060464_ADDRESS 0x6464u    /* 060464 */
#define sprite_list_06046C_ADDRESS 0x646Cu    /* 06046C */
#define animation_060478_ADDRESS 0x6478u    /* 060478 */
#define sprite_list_06049C_ADDRESS 0x649Cu    /* 06049C */
#define sprite_list_0604A8_ADDRESS 0x64A8u    /* 0604A8 */
#define sprite_list_0604B4_ADDRESS 0x64B4u    /* 0604B4 */
#define sprite_list_0604C0_ADDRESS 0x64C0u    /* 0604C0 */
#define sprite_list_0604CC_ADDRESS 0x64CCu    /* 0604CC */
#define sprite_list_0604D8_ADDRESS 0x64D8u    /* 0604D8 */
#define sprite_list_0604E4_ADDRESS 0x64E4u    /* 0604E4 */
#define sprite_list_0604F0_ADDRESS 0x64F0u    /* 0604F0 */
#define animation_0604FC_ADDRESS 0x64FCu    /* 0604FC */
#define sprite_list_060504_ADDRESS 0x6504u    /* 060504 */
#define animation_060510_ADDRESS 0x6510u    /* 060510 */
#define sprite_list_060518_ADDRESS 0x6518u    /* 060518 */
#define animation_060524_ADDRESS 0x6524u    /* 060524 */
#define sprite_list_06052C_ADDRESS 0x652Cu    /* 06052C */
#define animation_060538_ADDRESS 0x6538u    /* 060538 */
#define sprite_list_060540_ADDRESS 0x6540u    /* 060540 */
#define animation_060558_ADDRESS 0x6558u    /* 060558 */
#define sprite_list_06056C_ADDRESS 0x656Cu    /* 06056C */
#define sprite_list_060584_ADDRESS 0x6584u    /* 060584 */
#define sprite_list_06059C_ADDRESS 0x659Cu    /* 06059C */
#define sprite_list_0605B4_ADDRESS 0x65B4u    /* 0605B4 */
#define animation_0605CC_ADDRESS 0x65CCu    /* 0605CC */
#define sprite_list_0605F8_ADDRESS 0x65F8u    /* 0605F8 */
#define sprite_list_060610_ADDRESS 0x6610u    /* 060610 */
#define sprite_list_060628_ADDRESS 0x6628u    /* 060628 */
#define sprite_list_060640_ADDRESS 0x6640u    /* 060640 */
#define sprite_list_060652_ADDRESS 0x6652u    /* 060652 */
#define sprite_list_06066A_ADDRESS 0x666Au    /* 06066A */
#define sprite_list_060682_ADDRESS 0x6682u    /* 060682 */
#define animation_06069A_ADDRESS 0x669Au    /* 06069A */
#define sprite_list_0606AE_ADDRESS 0x66AEu    /* 0606AE */
#define sprite_list_0606BA_ADDRESS 0x66BAu    /* 0606BA */
#define sprite_list_0606C6_ADDRESS 0x66C6u    /* 0606C6 */
#define sprite_list_0606CC_ADDRESS 0x66CCu    /* 0606CC */
#define animation_0606D2_ADDRESS 0x66D2u    /* 0606D2 */
#define sprite_list_0606DE_ADDRESS 0x66DEu    /* 0606DE */
#define sprite_list_0606EA_ADDRESS 0x66EAu    /* 0606EA */
#define animation_0606FC_ADDRESS 0x66FCu    /* 0606FC */
#define sprite_list_06070C_ADDRESS 0x670Cu    /* 06070C */
#define sprite_list_060718_ADDRESS 0x6718u    /* 060718 */
#define sprite_list_060730_ADDRESS 0x6730u    /* 060730 */
#define animation_06073C_ADDRESS 0x673Cu    /* 06073C */
#define sprite_list_060748_ADDRESS 0x6748u    /* 060748 */
#define sprite_list_060754_ADDRESS 0x6754u    /* 060754 */
#define animation_060766_ADDRESS 0x6766u    /* 060766 */
#define sprite_list_060772_ADDRESS 0x6772u    /* 060772 */
#define sprite_list_060784_ADDRESS 0x6784u    /* 060784 */
#define animation_060790_ADDRESS 0x6790u    /* 060790 */
#define sprite_list_060798_ADDRESS 0x6798u    /* 060798 */
#define animation_0607A4_ADDRESS 0x67A4u    /* 0607A4 */
#define sprite_list_0607B0_ADDRESS 0x67B0u    /* 0607B0 */
#define sprite_list_0607B6_ADDRESS 0x67B6u    /* 0607B6 */
#define animation_0607C2_ADDRESS 0x67C2u    /* 0607C2 */
#define sprite_list_0607CA_ADDRESS 0x67CAu    /* 0607CA */
#define animation_0607E2_ADDRESS 0x67E2u    /* 0607E2 */
#define sprite_list_0607EE_ADDRESS 0x67EEu    /* 0607EE */
#define animation_060806_ADDRESS 0x6806u    /* 060806 */
#define sprite_list_060812_ADDRESS 0x6812u    /* 060812 */
#define sprite_list_06082A_ADDRESS 0x682Au    /* 06082A */
#define animation_060842_ADDRESS 0x6842u    /* 060842 */
#define sprite_list_06084E_ADDRESS 0x684Eu    /* 06084E */
#define sprite_list_06085A_ADDRESS 0x685Au    /* 06085A */
#define animation_06086C_ADDRESS 0x686Cu    /* 06086C */
#define sprite_list_060884_ADDRESS 0x6884u    /* 060884 */
#define sprite_list_060896_ADDRESS 0x6896u    /* 060896 */
#define sprite_list_0608A8_ADDRESS 0x68A8u    /* 0608A8 */
#define sprite_list_0608BA_ADDRESS 0x68BAu    /* 0608BA */
#define sprite_list_0608CC_ADDRESS 0x68CCu    /* 0608CC */
#define animation_0608DE_ADDRESS 0x68DEu    /* 0608DE */
#define sprite_list_0608F2_ADDRESS 0x68F2u    /* 0608F2 */
#define sprite_list_060904_ADDRESS 0x6904u    /* 060904 */
#define sprite_list_060916_ADDRESS 0x6916u    /* 060916 */
#define animation_060928_ADDRESS 0x6928u    /* 060928 */
#define sprite_list_060934_ADDRESS 0x6934u    /* 060934 */
#define sprite_list_06093A_ADDRESS 0x693Au    /* 06093A */
#define animation_060940_ADDRESS 0x6940u    /* 060940 */
#define sprite_list_06094C_ADDRESS 0x694Cu    /* 06094C */
#define sprite_list_060964_ADDRESS 0x6964u    /* 060964 */
#define animation_06097C_ADDRESS 0x697Cu    /* 06097C */
#define sprite_list_060984_ADDRESS 0x6984u    /* 060984 */
#define animation_060990_ADDRESS 0x6990u    /* 060990 */
#define sprite_list_06099C_ADDRESS 0x699Cu    /* 06099C */
#define sprite_list_0609A8_ADDRESS 0x69A8u    /* 0609A8 */
#define animation_0609BA_ADDRESS 0x69BAu    /* 0609BA */
#define sprite_list_0609C6_ADDRESS 0x69C6u    /* 0609C6 */
#define sprite_list_0609D8_ADDRESS 0x69D8u    /* 0609D8 */
#define animation_0609F0_ADDRESS 0x69F0u    /* 0609F0 */
#define sprite_list_0609FC_ADDRESS 0x69FCu    /* 0609FC */
#define sprite_list_060A08_ADDRESS 0x6A08u    /* 060A08 */
#define animation_060A1A_ADDRESS 0x6A1Au    /* 060A1A */
#define sprite_list_060A32_ADDRESS 0x6A32u    /* 060A32 */
#define sprite_list_060A44_ADDRESS 0x6A44u    /* 060A44 */
#define sprite_list_060A56_ADDRESS 0x6A56u    /* 060A56 */
#define sprite_list_060A68_ADDRESS 0x6A68u    /* 060A68 */
#define sprite_list_060A7A_ADDRESS 0x6A7Au    /* 060A7A */
#define animation_060A8C_ADDRESS 0x6A8Cu    /* 060A8C */
#define sprite_list_060A98_ADDRESS 0x6A98u    /* 060A98 */
#define sprite_list_060AB0_ADDRESS 0x6AB0u    /* 060AB0 */
#define animation_060AC2_ADDRESS 0x6AC2u    /* 060AC2 */
#define sprite_list_060AD6_ADDRESS 0x6AD6u    /* 060AD6 */
#define sprite_list_060AE2_ADDRESS 0x6AE2u    /* 060AE2 */
#define sprite_list_060AF4_ADDRESS 0x6AF4u    /* 060AF4 */
#define sprite_list_060B06_ADDRESS 0x6B06u    /* 060B06 */
#define animation_060B12_ADDRESS 0x6B12u    /* 060B12 */
#define sprite_list_060B1E_ADDRESS 0x6B1Eu    /* 060B1E */
#define sprite_list_060B30_ADDRESS 0x6B30u    /* 060B30 */
#define animation_060B42_ADDRESS 0x6B42u    /* 060B42 */
#define sprite_list_060B4E_ADDRESS 0x6B4Eu    /* 060B4E */
#define sprite_list_060B5A_ADDRESS 0x6B5Au    /* 060B5A */
#define animation_060B6C_ADDRESS 0x6B6Cu    /* 060B6C */
#define sprite_list_060B80_ADDRESS 0x6B80u    /* 060B80 */
#define sprite_list_060B8C_ADDRESS 0x6B8Cu    /* 060B8C */
#define sprite_list_060B98_ADDRESS 0x6B98u    /* 060B98 */
#define sprite_list_060BA4_ADDRESS 0x6BA4u    /* 060BA4 */
#define animation_060BB0_ADDRESS 0x6BB0u    /* 060BB0 */
#define sprite_list_060BC4_ADDRESS 0x6BC4u    /* 060BC4 */
#define sprite_list_060BD6_ADDRESS 0x6BD6u    /* 060BD6 */
#define sprite_list_060BE2_ADDRESS 0x6BE2u    /* 060BE2 */
#define sprite_list_060BF4_ADDRESS 0x6BF4u    /* 060BF4 */
#define animation_060C0C_ADDRESS 0x6C0Cu    /* 060C0C */
#define sprite_list_060C1C_ADDRESS 0x6C1Cu    /* 060C1C */
#define sprite_list_060C28_ADDRESS 0x6C28u    /* 060C28 */
#define sprite_list_060C3A_ADDRESS 0x6C3Au    /* 060C3A */
#define animation_060C40_ADDRESS 0x6C40u    /* 060C40 */
#define sprite_list_060C54_ADDRESS 0x6C54u    /* 060C54 */
#define sprite_list_060C60_ADDRESS 0x6C60u    /* 060C60 */
#define sprite_list_060C6C_ADDRESS 0x6C6Cu    /* 060C6C */
#define sprite_list_060C78_ADDRESS 0x6C78u    /* 060C78 */
#define animation_060C84_ADDRESS 0x6C84u    /* 060C84 */
#define sprite_list_060C94_ADDRESS 0x6C94u    /* 060C94 */
#define sprite_list_060CA0_ADDRESS 0x6CA0u    /* 060CA0 */
#define animation_060CAC_ADDRESS 0x6CACu    /* 060CAC */
#define sprite_list_060CB8_ADDRESS 0x6CB8u    /* 060CB8 */
#define sprite_list_060CC4_ADDRESS 0x6CC4u    /* 060CC4 */
#define animation_060CD0_ADDRESS 0x6CD0u    /* 060CD0 */
#define sprite_list_060CD8_ADDRESS 0x6CD8u    /* 060CD8 */
#define animation_060CEA_ADDRESS 0x6CEAu    /* 060CEA */
#define sprite_list_060D0E_ADDRESS 0x6D0Eu    /* 060D0E */
#define sprite_list_060D20_ADDRESS 0x6D20u    /* 060D20 */
#define sprite_list_060D2C_ADDRESS 0x6D2Cu    /* 060D2C */
#define sprite_list_060D3E_ADDRESS 0x6D3Eu    /* 060D3E */
#define sprite_list_060D4A_ADDRESS 0x6D4Au    /* 060D4A */
#define sprite_list_060D62_ADDRESS 0x6D62u    /* 060D62 */
#define sprite_list_060D7A_ADDRESS 0x6D7Au    /* 060D7A */
#define sprite_list_060D92_ADDRESS 0x6D92u    /* 060D92 */
#define animation_060DAA_ADDRESS 0x6DAAu    /* 060DAA */
#define sprite_list_060DB6_ADDRESS 0x6DB6u    /* 060DB6 */
#define sprite_list_060DC2_ADDRESS 0x6DC2u    /* 060DC2 */
#define animation_060DCE_ADDRESS 0x6DCEu    /* 060DCE */
#define sprite_list_060DDE_ADDRESS 0x6DDEu    /* 060DDE */
#define sprite_list_060DF0_ADDRESS 0x6DF0u    /* 060DF0 */
#define sprite_list_060E02_ADDRESS 0x6E02u    /* 060E02 */
#define animation_060E14_ADDRESS 0x6E14u    /* 060E14 */
#define sprite_list_060E38_ADDRESS 0x6E38u    /* 060E38 */
#define sprite_list_060E44_ADDRESS 0x6E44u    /* 060E44 */
#define sprite_list_060E50_ADDRESS 0x6E50u    /* 060E50 */
#define sprite_list_060E5C_ADDRESS 0x6E5Cu    /* 060E5C */
#define sprite_list_060E68_ADDRESS 0x6E68u    /* 060E68 */
#define sprite_list_060E74_ADDRESS 0x6E74u    /* 060E74 */
#define sprite_list_060E80_ADDRESS 0x6E80u    /* 060E80 */
#define sprite_list_060E8C_ADDRESS 0x6E8Cu    /* 060E8C */
#define animation_060E98_ADDRESS 0x6E98u    /* 060E98 */
#define animation_060EB8_ADDRESS 0x6EB8u    /* 060EB8 */
#define animation_060EDC_ADDRESS 0x6EDCu    /* 060EDC */
#define sprite_list_060F00_ADDRESS 0x6F00u    /* 060F00 */
#define sprite_list_060F06_ADDRESS 0x6F06u    /* 060F06 */
#define sprite_list_060F0C_ADDRESS 0x6F0Cu    /* 060F0C */
#define sprite_list_060F12_ADDRESS 0x6F12u    /* 060F12 */
#define sprite_list_060F18_ADDRESS 0x6F18u    /* 060F18 */
#define sprite_list_060F1E_ADDRESS 0x6F1Eu    /* 060F1E */
#define sprite_list_060F24_ADDRESS 0x6F24u    /* 060F24 */
#define sprite_list_060F2A_ADDRESS 0x6F2Au    /* 060F2A */
#define animation_060F30_ADDRESS 0x6F30u    /* 060F30 */
#define animation_060F54_ADDRESS 0x6F54u    /* 060F54 */
#define sprite_list_060F5C_ADDRESS 0x6F5Cu    /* 060F5C */
#define animation_060F6E_ADDRESS 0x6F6Eu    /* 060F6E */
#define sprite_list_060F76_ADDRESS 0x6F76u    /* 060F76 */
#define animation_060F88_ADDRESS 0x6F88u    /* 060F88 */
#define sprite_list_060F90_ADDRESS 0x6F90u    /* 060F90 */
#define animation_060FA8_ADDRESS 0x6FA8u    /* 060FA8 */
#define sprite_list_060FCC_ADDRESS 0x6FCCu    /* 060FCC */
#define sprite_list_060FE4_ADDRESS 0x6FE4u    /* 060FE4 */
#define sprite_list_060FFC_ADDRESS 0x6FFCu    /* 060FFC */
#define sprite_list_061014_ADDRESS 0x7014u    /* 061014 */
#define sprite_list_06102C_ADDRESS 0x702Cu    /* 06102C */
#define sprite_list_061044_ADDRESS 0x7044u    /* 061044 */
#define sprite_list_06105C_ADDRESS 0x705Cu    /* 06105C */
#define sprite_list_061074_ADDRESS 0x7074u    /* 061074 */
#define animation_06108C_ADDRESS 0x708Cu    /* 06108C */
#define sprite_list_061094_ADDRESS 0x7094u    /* 061094 */
#define animation_0610AC_ADDRESS 0x70ACu    /* 0610AC */
#define sprite_list_0610B4_ADDRESS 0x70B4u    /* 0610B4 */
#define animation_0610CC_ADDRESS 0x70CCu    /* 0610CC */
#define animation_0610D4_ADDRESS 0x70D4u    /* 0610D4 */
#define sprite_list_0610E4_ADDRESS 0x70E4u    /* 0610E4 */
#define sprite_list_0610FC_ADDRESS 0x70FCu    /* 0610FC */
#define sprite_list_06110E_ADDRESS 0x710Eu    /* 06110E */
#define animation_061126_ADDRESS 0x7126u    /* 061126 */
#define sprite_list_061136_ADDRESS 0x7136u    /* 061136 */
#define sprite_list_06114E_ADDRESS 0x714Eu    /* 06114E */
#define sprite_list_061160_ADDRESS 0x7160u    /* 061160 */
#define animation_061178_ADDRESS 0x7178u    /* 061178 */
#define sprite_list_061184_ADDRESS 0x7184u    /* 061184 */
#define sprite_list_06119C_ADDRESS 0x719Cu    /* 06119C */
#define animation_0611B4_ADDRESS 0x71B4u    /* 0611B4 */
#define sprite_list_0611BC_ADDRESS 0x71BCu    /* 0611BC */
#define animation_0611CE_ADDRESS 0x71CEu    /* 0611CE */
#define sprite_list_0611F2_ADDRESS 0x71F2u    /* 0611F2 */
#define sprite_list_061204_ADDRESS 0x7204u    /* 061204 */
#define sprite_list_061216_ADDRESS 0x7216u    /* 061216 */
#define sprite_list_061228_ADDRESS 0x7228u    /* 061228 */
#define sprite_list_06123A_ADDRESS 0x723Au    /* 06123A */
#define sprite_list_06124C_ADDRESS 0x724Cu    /* 06124C */
#define sprite_list_06125E_ADDRESS 0x725Eu    /* 06125E */
#define sprite_list_061270_ADDRESS 0x7270u    /* 061270 */
#define animation_061282_ADDRESS 0x7282u    /* 061282 */
#define sprite_list_06128A_ADDRESS 0x728Au    /* 06128A */
#define animation_0612A2_ADDRESS 0x72A2u    /* 0612A2 */
#define sprite_list_0612AA_ADDRESS 0x72AAu    /* 0612AA */
#define animation_0612C2_ADDRESS 0x72C2u    /* 0612C2 */
#define sprite_list_0612CE_ADDRESS 0x72CEu    /* 0612CE */
#define animation_0612E6_ADDRESS 0x72E6u    /* 0612E6 */
#define sprite_list_0612FA_ADDRESS 0x72FAu    /* 0612FA */
#define sprite_list_061312_ADDRESS 0x7312u    /* 061312 */
#define sprite_list_06132A_ADDRESS 0x732Au    /* 06132A */
#define sprite_list_061342_ADDRESS 0x7342u    /* 061342 */
#define animation_061360_ADDRESS 0x7360u    /* 061360 */
#define sprite_list_061374_ADDRESS 0x7374u    /* 061374 */
#define sprite_list_06138C_ADDRESS 0x738Cu    /* 06138C */
#define sprite_list_0613A4_ADDRESS 0x73A4u    /* 0613A4 */
#define sprite_list_0613BC_ADDRESS 0x73BCu    /* 0613BC */
#define animation_0613DA_ADDRESS 0x73DAu    /* 0613DA */
#define sprite_list_0613E2_ADDRESS 0x73E2u    /* 0613E2 */
#define animation_0613EE_ADDRESS 0x73EEu    /* 0613EE */
#define sprite_list_061412_ADDRESS 0x7412u    /* 061412 */
#define sprite_list_06141E_ADDRESS 0x741Eu    /* 06141E */
#define sprite_list_06142A_ADDRESS 0x742Au    /* 06142A */
#define sprite_list_061436_ADDRESS 0x7436u    /* 061436 */
#define sprite_list_061442_ADDRESS 0x7442u    /* 061442 */
#define sprite_list_06144E_ADDRESS 0x744Eu    /* 06144E */
#define sprite_list_06145A_ADDRESS 0x745Au    /* 06145A */
#define sprite_list_061466_ADDRESS 0x7466u    /* 061466 */
#define animation_061472_ADDRESS 0x7472u    /* 061472 */
#define sprite_list_06147A_ADDRESS 0x747Au    /* 06147A */
#define animation_061486_ADDRESS 0x7486u    /* 061486 */
#define sprite_list_06148E_ADDRESS 0x748Eu    /* 06148E */
#define animation_06149A_ADDRESS 0x749Au    /* 06149A */
#define animation_0614A2_ADDRESS 0x74A2u    /* 0614A2 */
#define sprite_list_0614B2_ADDRESS 0x74B2u    /* 0614B2 */
#define sprite_list_0614CA_ADDRESS 0x74CAu    /* 0614CA */
#define animation_0614E2_ADDRESS 0x74E2u    /* 0614E2 */
#define sprite_list_0614F2_ADDRESS 0x74F2u    /* 0614F2 */
#define sprite_list_0614FE_ADDRESS 0x74FEu    /* 0614FE */
#define sprite_list_061516_ADDRESS 0x7516u    /* 061516 */
#define animation_06152E_ADDRESS 0x752Eu    /* 06152E */
#define sprite_list_06154A_ADDRESS 0x754Au    /* 06154A */
#define sprite_list_06155C_ADDRESS 0x755Cu    /* 06155C */
#define sprite_list_061568_ADDRESS 0x7568u    /* 061568 */
#define sprite_list_061574_ADDRESS 0x7574u    /* 061574 */
#define sprite_list_061580_ADDRESS 0x7580u    /* 061580 */
#define sprite_list_06158C_ADDRESS 0x758Cu    /* 06158C */
#define animation_06159E_ADDRESS 0x759Eu    /* 06159E */
#define sprite_list_0615CA_ADDRESS 0x75CAu    /* 0615CA */
#define sprite_list_0615DC_ADDRESS 0x75DCu    /* 0615DC */
#define sprite_list_0615EE_ADDRESS 0x75EEu    /* 0615EE */
#define sprite_list_0615FA_ADDRESS 0x75FAu    /* 0615FA */
#define sprite_list_061606_ADDRESS 0x7606u    /* 061606 */
#define sprite_list_061618_ADDRESS 0x7618u    /* 061618 */
#define sprite_list_061624_ADDRESS 0x7624u    /* 061624 */
#define sprite_list_061630_ADDRESS 0x7630u    /* 061630 */
#define sprite_list_06163C_ADDRESS 0x763Cu    /* 06163C */
#define sprite_list_061648_ADDRESS 0x7648u    /* 061648 */
#define animation_06165A_ADDRESS 0x765Au    /* 06165A */
#define sprite_list_06166A_ADDRESS 0x766Au    /* 06166A */
#define sprite_list_06167C_ADDRESS 0x767Cu    /* 06167C */
#define sprite_list_061688_ADDRESS 0x7688u    /* 061688 */
#define animation_061694_ADDRESS 0x7694u    /* 061694 */
#define sprite_list_0616CC_ADDRESS 0x76CCu    /* 0616CC */
#define sprite_list_0616DE_ADDRESS 0x76DEu    /* 0616DE */
#define sprite_list_0616F6_ADDRESS 0x76F6u    /* 0616F6 */
#define sprite_list_06170E_ADDRESS 0x770Eu    /* 06170E */
#define sprite_list_061726_ADDRESS 0x7726u    /* 061726 */
#define sprite_list_06173E_ADDRESS 0x773Eu    /* 06173E */
#define sprite_list_061750_ADDRESS 0x7750u    /* 061750 */
#define sprite_list_061762_ADDRESS 0x7762u    /* 061762 */
#define sprite_list_06177A_ADDRESS 0x777Au    /* 06177A */
#define sprite_list_061792_ADDRESS 0x7792u    /* 061792 */
#define sprite_list_0617AA_ADDRESS 0x77AAu    /* 0617AA */
#define animation_0617C8_ADDRESS 0x77C8u    /* 0617C8 */
#define sprite_list_061800_ADDRESS 0x7800u    /* 061800 */
#define sprite_list_061818_ADDRESS 0x7818u    /* 061818 */
#define sprite_list_06182A_ADDRESS 0x782Au    /* 06182A */
#define animation_061842_ADDRESS 0x7842u    /* 061842 */
#define sprite_list_06184E_ADDRESS 0x784Eu    /* 06184E */
#define sprite_list_061866_ADDRESS 0x7866u    /* 061866 */
#define animation_06187E_ADDRESS 0x787Eu    /* 06187E */
#define sprite_list_06188A_ADDRESS 0x788Au    /* 06188A */
#define sprite_list_061896_ADDRESS 0x7896u    /* 061896 */
#define animation_table_0618A8_ADDRESS 0x78A8u    /* 0618A8 */
#define animation_0618B2_ADDRESS 0x78B2u    /* 0618B2 */
#define sprite_list_0618CE_ADDRESS 0x78CEu    /* 0618CE */
#define sprite_list_0618DA_ADDRESS 0x78DAu    /* 0618DA */
#define sprite_list_0618E6_ADDRESS 0x78E6u    /* 0618E6 */
#define sprite_list_0618F2_ADDRESS 0x78F2u    /* 0618F2 */
#define animation_0618FE_ADDRESS 0x78FEu    /* 0618FE */
#define sprite_list_06191A_ADDRESS 0x791Au    /* 06191A */
#define sprite_list_061932_ADDRESS 0x7932u    /* 061932 */
#define sprite_list_06194A_ADDRESS 0x794Au    /* 06194A */
#define sprite_list_061962_ADDRESS 0x7962u    /* 061962 */
#define animation_06197A_ADDRESS 0x797Au    /* 06197A */
#define sprite_list_061986_ADDRESS 0x7986u    /* 061986 */
#define sprite_list_06199E_ADDRESS 0x799Eu    /* 06199E */
#define animation_0619B6_ADDRESS 0x79B6u    /* 0619B6 */
#define sprite_list_0619C2_ADDRESS 0x79C2u    /* 0619C2 */
#define sprite_list_0619CE_ADDRESS 0x79CEu    /* 0619CE */
#define animation_0619DA_ADDRESS 0x79DAu    /* 0619DA */
#define sprite_list_0619E6_ADDRESS 0x79E6u    /* 0619E6 */
#define sprite_list_0619F2_ADDRESS 0x79F2u    /* 0619F2 */
#define animation_table_0619FE_ADDRESS 0x79FEu    /* 0619FE */
#define animation_061A0C_ADDRESS 0x7A0Cu    /* 061A0C */
#define sprite_list_061A28_ADDRESS 0x7A28u    /* 061A28 */
#define sprite_list_061A3A_ADDRESS 0x7A3Au    /* 061A3A */
#define sprite_list_061A4C_ADDRESS 0x7A4Cu    /* 061A4C */
#define sprite_list_061A5E_ADDRESS 0x7A5Eu    /* 061A5E */
#define animation_061A70_ADDRESS 0x7A70u    /* 061A70 */
#define sprite_list_061A8C_ADDRESS 0x7A8Cu    /* 061A8C */
#define sprite_list_061AAA_ADDRESS 0x7AAAu    /* 061AAA */
#define sprite_list_061AC8_ADDRESS 0x7AC8u    /* 061AC8 */
#define sprite_list_061AE6_ADDRESS 0x7AE6u    /* 061AE6 */
#define animation_061B04_ADDRESS 0x7B04u    /* 061B04 */
#define sprite_list_061B10_ADDRESS 0x7B10u    /* 061B10 */
#define sprite_list_061B28_ADDRESS 0x7B28u    /* 061B28 */
#define animation_061B40_ADDRESS 0x7B40u    /* 061B40 */
#define sprite_list_061B4C_ADDRESS 0x7B4Cu    /* 061B4C */
#define sprite_list_061B6A_ADDRESS 0x7B6Au    /* 061B6A */
#define animation_061B82_ADDRESS 0x7B82u    /* 061B82 */
#define sprite_list_061B8E_ADDRESS 0x7B8Eu    /* 061B8E */
#define sprite_list_061B94_ADDRESS 0x7B94u    /* 061B94 */
#define animation_061BA0_ADDRESS 0x7BA0u    /* 061BA0 */
#define sprite_list_061BC0_ADDRESS 0x7BC0u    /* 061BC0 */
#define sprite_list_061BCC_ADDRESS 0x7BCCu    /* 061BCC */
#define sprite_list_061BD8_ADDRESS 0x7BD8u    /* 061BD8 */
#define animation_061BE4_ADDRESS 0x7BE4u    /* 061BE4 */
#define sprite_list_061C08_ADDRESS 0x7C08u    /* 061C08 */
#define sprite_list_061C26_ADDRESS 0x7C26u    /* 061C26 */
#define sprite_list_061C3E_ADDRESS 0x7C3Eu    /* 061C3E */
#define sprite_list_061C4A_ADDRESS 0x7C4Au    /* 061C4A */
#define sprite_list_061C62_ADDRESS 0x7C62u    /* 061C62 */
#define animation_table_061C86_ADDRESS 0x7C86u    /* 061C86 */
#define animation_061C8E_ADDRESS 0x7C8Eu    /* 061C8E */
#define sprite_list_061CB2_ADDRESS 0x7CB2u    /* 061CB2 */
#define sprite_list_061CCA_ADDRESS 0x7CCAu    /* 061CCA */
#define sprite_list_061CE2_ADDRESS 0x7CE2u    /* 061CE2 */
#define sprite_list_061CFA_ADDRESS 0x7CFAu    /* 061CFA */
#define sprite_list_061D12_ADDRESS 0x7D12u    /* 061D12 */
#define animation_061D2A_ADDRESS 0x7D2Au    /* 061D2A */
#define sprite_list_061D4E_ADDRESS 0x7D4Eu    /* 061D4E */
#define sprite_list_061D6C_ADDRESS 0x7D6Cu    /* 061D6C */
#define sprite_list_061D8A_ADDRESS 0x7D8Au    /* 061D8A */
#define sprite_list_061DA8_ADDRESS 0x7DA8u    /* 061DA8 */
#define sprite_list_061DC6_ADDRESS 0x7DC6u    /* 061DC6 */
#define animation_061DE4_ADDRESS 0x7DE4u    /* 061DE4 */
#define sprite_list_061DFC_ADDRESS 0x7DFCu    /* 061DFC */
#define sprite_list_061E14_ADDRESS 0x7E14u    /* 061E14 */
#define animation_061E2C_ADDRESS 0x7E2Cu    /* 061E2C */
#define sprite_list_061E44_ADDRESS 0x7E44u    /* 061E44 */
#define sprite_list_061E62_ADDRESS 0x7E62u    /* 061E62 */
#define fill_061E80_ADDRESS 0x7E80u    /* 061E80 */
#define unreached_animation_061EA4_ADDRESS 0x7EA4u    /* 061EA4 */
#define sprite_list_061EB0_ADDRESS 0x7EB0u    /* 061EB0 */
#define sprite_list_061EDA_ADDRESS 0x7EDAu    /* 061EDA */
#define unreached_animation_061F04_ADDRESS 0x7F04u    /* 061F04 */
#define sprite_list_061F0C_ADDRESS 0x7F0Cu    /* 061F0C */
#define unreached_animation_061F12_ADDRESS 0x7F12u    /* 061F12 */
#define sprite_list_061F1A_ADDRESS 0x7F1Au    /* 061F1A */
#define unreached_animation_061F38_ADDRESS 0x7F38u    /* 061F38 */
#define sprite_list_061F40_ADDRESS 0x7F40u    /* 061F40 */
#define unreached_animation_061F58_ADDRESS 0x7F58u    /* 061F58 */
#define sprite_list_061F60_ADDRESS 0x7F60u    /* 061F60 */
#define fill_061F6C_ADDRESS 0x7F6Cu    /* 061F6C */
#define unreached_animation_061F6E_ADDRESS 0x7F6Eu    /* 061F6E */
#define sprite_list_061F76_ADDRESS 0x7F76u    /* 061F76 */
#define unreached_animation_061F7C_ADDRESS 0x7F7Cu    /* 061F7C */
#define sprite_list_061F84_ADDRESS 0x7F84u    /* 061F84 */
#define unreached_animation_061F8A_ADDRESS 0x7F8Au    /* 061F8A */
#define sprite_list_061F92_ADDRESS 0x7F92u    /* 061F92 */
#define unreached_animation_061F9E_ADDRESS 0x7F9Eu    /* 061F9E */
#define sprite_list_061FAA_ADDRESS 0x7FAAu    /* 061FAA */
#define sprite_list_061FB0_ADDRESS 0x7FB0u    /* 061FB0 */
#define unreached_animation_061FB6_ADDRESS 0x7FB6u    /* 061FB6 */
#define sprite_list_061FBE_ADDRESS 0x7FBEu    /* 061FBE */
#define unreached_animation_061FC4_ADDRESS 0x7FC4u    /* 061FC4 */
#define sprite_list_061FCC_ADDRESS 0x7FCCu    /* 061FCC */
#define unreached_animation_061FD2_ADDRESS 0x7FD2u    /* 061FD2 */
#define sprite_list_061FDA_ADDRESS 0x7FDAu    /* 061FDA */
#define unreached_animation_061FE0_ADDRESS 0x7FE0u    /* 061FE0 */
#define sprite_list_061FE8_ADDRESS 0x7FE8u    /* 061FE8 */
#define fill_061FEE_ADDRESS 0x7FEEu    /* 061FEE */
#define set_index_062000_ADDRESS 0x6000u    /* 062000 */
#define animation_table_06200A_ADDRESS 0x600Au    /* 06200A */
#define animation_0620EC_ADDRESS 0x60ECu    /* 0620EC */
#define sprite_list_0620F4_ADDRESS 0x60F4u    /* 0620F4 */
#define animation_062100_ADDRESS 0x6100u    /* 062100 */
#define sprite_list_062108_ADDRESS 0x6108u    /* 062108 */
#define animation_06210E_ADDRESS 0x610Eu    /* 06210E */
#define sprite_list_062116_ADDRESS 0x6116u    /* 062116 */
#define animation_06211C_ADDRESS 0x611Cu    /* 06211C */
#define sprite_list_062124_ADDRESS 0x6124u    /* 062124 */
#define animation_062136_ADDRESS 0x6136u    /* 062136 */
#define sprite_list_06215A_ADDRESS 0x615Au    /* 06215A */
#define sprite_list_06216C_ADDRESS 0x616Cu    /* 06216C */
#define sprite_list_06217E_ADDRESS 0x617Eu    /* 06217E */
#define sprite_list_062190_ADDRESS 0x6190u    /* 062190 */
#define sprite_list_0621A2_ADDRESS 0x61A2u    /* 0621A2 */
#define sprite_list_0621B4_ADDRESS 0x61B4u    /* 0621B4 */
#define sprite_list_0621C6_ADDRESS 0x61C6u    /* 0621C6 */
#define sprite_list_0621D8_ADDRESS 0x61D8u    /* 0621D8 */
#define animation_0621EA_ADDRESS 0x61EAu    /* 0621EA */
#define sprite_list_06220E_ADDRESS 0x620Eu    /* 06220E */
#define sprite_list_06221A_ADDRESS 0x621Au    /* 06221A */
#define sprite_list_062220_ADDRESS 0x6220u    /* 062220 */
#define sprite_list_062226_ADDRESS 0x6226u    /* 062226 */
#define sprite_list_06222C_ADDRESS 0x622Cu    /* 06222C */
#define sprite_list_062238_ADDRESS 0x6238u    /* 062238 */
#define sprite_list_06223E_ADDRESS 0x623Eu    /* 06223E */
#define sprite_list_062244_ADDRESS 0x6244u    /* 062244 */
#define animation_06224A_ADDRESS 0x624Au    /* 06224A */
#define sprite_list_062252_ADDRESS 0x6252u    /* 062252 */
#define animation_06226A_ADDRESS 0x626Au    /* 06226A */
#define sprite_list_062272_ADDRESS 0x6272u    /* 062272 */
#define animation_06228A_ADDRESS 0x628Au    /* 06228A */
#define sprite_list_062292_ADDRESS 0x6292u    /* 062292 */
#define animation_0622AA_ADDRESS 0x62AAu    /* 0622AA */
#define sprite_list_0622B2_ADDRESS 0x62B2u    /* 0622B2 */
#define animation_0622C4_ADDRESS 0x62C4u    /* 0622C4 */
#define sprite_list_0622E8_ADDRESS 0x62E8u    /* 0622E8 */
#define sprite_list_0622FA_ADDRESS 0x62FAu    /* 0622FA */
#define sprite_list_06230C_ADDRESS 0x630Cu    /* 06230C */
#define sprite_list_06231E_ADDRESS 0x631Eu    /* 06231E */
#define sprite_list_062330_ADDRESS 0x6330u    /* 062330 */
#define sprite_list_062342_ADDRESS 0x6342u    /* 062342 */
#define sprite_list_062354_ADDRESS 0x6354u    /* 062354 */
#define sprite_list_062366_ADDRESS 0x6366u    /* 062366 */
#define animation_062378_ADDRESS 0x6378u    /* 062378 */
#define sprite_list_062380_ADDRESS 0x6380u    /* 062380 */
#define animation_062392_ADDRESS 0x6392u    /* 062392 */
#define sprite_list_06239A_ADDRESS 0x639Au    /* 06239A */
#define animation_0623AC_ADDRESS 0x63ACu    /* 0623AC */
#define animation_0623B4_ADDRESS 0x63B4u    /* 0623B4 */
#define sprite_list_0623BC_ADDRESS 0x63BCu    /* 0623BC */
#define animation_0623C8_ADDRESS 0x63C8u    /* 0623C8 */
#define sprite_list_0623EC_ADDRESS 0x63ECu    /* 0623EC */
#define sprite_list_0623F8_ADDRESS 0x63F8u    /* 0623F8 */
#define sprite_list_062404_ADDRESS 0x6404u    /* 062404 */
#define sprite_list_062410_ADDRESS 0x6410u    /* 062410 */
#define sprite_list_06241C_ADDRESS 0x641Cu    /* 06241C */
#define sprite_list_062428_ADDRESS 0x6428u    /* 062428 */
#define sprite_list_062434_ADDRESS 0x6434u    /* 062434 */
#define sprite_list_062440_ADDRESS 0x6440u    /* 062440 */
#define animation_06244C_ADDRESS 0x644Cu    /* 06244C */
#define sprite_list_062454_ADDRESS 0x6454u    /* 062454 */
#define animation_062460_ADDRESS 0x6460u    /* 062460 */
#define sprite_list_062468_ADDRESS 0x6468u    /* 062468 */
#define animation_062474_ADDRESS 0x6474u    /* 062474 */
#define animation_06247C_ADDRESS 0x647Cu    /* 06247C */
#define sprite_list_062498_ADDRESS 0x6498u    /* 062498 */
#define sprite_list_0624AA_ADDRESS 0x64AAu    /* 0624AA */
#define sprite_list_0624BC_ADDRESS 0x64BCu    /* 0624BC */
#define animation_0624CE_ADDRESS 0x64CEu    /* 0624CE */
#define sprite_list_0624DA_ADDRESS 0x64DAu    /* 0624DA */
#define sprite_list_0624EC_ADDRESS 0x64ECu    /* 0624EC */
#define sprite_list_062504_ADDRESS 0x6504u    /* 062504 */
#define sprite_list_062516_ADDRESS 0x6516u    /* 062516 */
#define animation_06252E_ADDRESS 0x652Eu    /* 06252E */
#define sprite_list_06253A_ADDRESS 0x653Au    /* 06253A */
#define animation_062546_ADDRESS 0x6546u    /* 062546 */
#define sprite_list_06256A_ADDRESS 0x656Au    /* 06256A */
#define sprite_list_06257C_ADDRESS 0x657Cu    /* 06257C */
#define sprite_list_06258E_ADDRESS 0x658Eu    /* 06258E */
#define sprite_list_0625A0_ADDRESS 0x65A0u    /* 0625A0 */
#define sprite_list_0625B2_ADDRESS 0x65B2u    /* 0625B2 */
#define sprite_list_0625C4_ADDRESS 0x65C4u    /* 0625C4 */
#define sprite_list_0625D6_ADDRESS 0x65D6u    /* 0625D6 */
#define sprite_list_0625E8_ADDRESS 0x65E8u    /* 0625E8 */
#define animation_0625FA_ADDRESS 0x65FAu    /* 0625FA */
#define sprite_list_06260E_ADDRESS 0x660Eu    /* 06260E */
#define sprite_list_062620_ADDRESS 0x6620u    /* 062620 */
#define sprite_list_062632_ADDRESS 0x6632u    /* 062632 */
#define sprite_list_062644_ADDRESS 0x6644u    /* 062644 */
#define animation_062656_ADDRESS 0x6656u    /* 062656 */
#define sprite_list_06267A_ADDRESS 0x667Au    /* 06267A */
#define sprite_list_06268C_ADDRESS 0x668Cu    /* 06268C */
#define sprite_list_06269E_ADDRESS 0x669Eu    /* 06269E */
#define sprite_list_0626B0_ADDRESS 0x66B0u    /* 0626B0 */
#define animation_0626C2_ADDRESS 0x66C2u    /* 0626C2 */
#define sprite_list_0626EA_ADDRESS 0x66EAu    /* 0626EA */
#define sprite_list_0626FC_ADDRESS 0x66FCu    /* 0626FC */
#define sprite_list_06270E_ADDRESS 0x670Eu    /* 06270E */
#define animation_062726_ADDRESS 0x6726u    /* 062726 */
#define sprite_list_062756_ADDRESS 0x6756u    /* 062756 */
#define sprite_list_06275C_ADDRESS 0x675Cu    /* 06275C */
#define sprite_list_062762_ADDRESS 0x6762u    /* 062762 */
#define sprite_list_062768_ADDRESS 0x6768u    /* 062768 */
#define sprite_list_06276E_ADDRESS 0x676Eu    /* 06276E */
#define sprite_list_062774_ADDRESS 0x6774u    /* 062774 */
#define sprite_list_06277A_ADDRESS 0x677Au    /* 06277A */
#define animation_062780_ADDRESS 0x6780u    /* 062780 */
#define sprite_list_0627A4_ADDRESS 0x67A4u    /* 0627A4 */
#define sprite_list_0627BC_ADDRESS 0x67BCu    /* 0627BC */
#define sprite_list_0627DA_ADDRESS 0x67DAu    /* 0627DA */
#define sprite_list_0627F2_ADDRESS 0x67F2u    /* 0627F2 */
#define sprite_list_06280A_ADDRESS 0x680Au    /* 06280A */
#define sprite_list_06281C_ADDRESS 0x681Cu    /* 06281C */
#define animation_062834_ADDRESS 0x6834u    /* 062834 */
#define sprite_list_06283C_ADDRESS 0x683Cu    /* 06283C */
#define animation_06284E_ADDRESS 0x684Eu    /* 06284E */
#define sprite_list_062872_ADDRESS 0x6872u    /* 062872 */
#define sprite_list_062884_ADDRESS 0x6884u    /* 062884 */
#define sprite_list_062896_ADDRESS 0x6896u    /* 062896 */
#define sprite_list_0628A8_ADDRESS 0x68A8u    /* 0628A8 */
#define sprite_list_0628BA_ADDRESS 0x68BAu    /* 0628BA */
#define sprite_list_0628CC_ADDRESS 0x68CCu    /* 0628CC */
#define sprite_list_0628DE_ADDRESS 0x68DEu    /* 0628DE */
#define sprite_list_0628F0_ADDRESS 0x68F0u    /* 0628F0 */
#define animation_062902_ADDRESS 0x6902u    /* 062902 */
#define sprite_list_06290A_ADDRESS 0x690Au    /* 06290A */
#define animation_06291C_ADDRESS 0x691Cu    /* 06291C */
#define sprite_list_062924_ADDRESS 0x6924u    /* 062924 */
#define animation_062936_ADDRESS 0x6936u    /* 062936 */
#define sprite_list_06293E_ADDRESS 0x693Eu    /* 06293E */
#define animation_062950_ADDRESS 0x6950u    /* 062950 */
#define sprite_list_062964_ADDRESS 0x6964u    /* 062964 */
#define sprite_list_06297C_ADDRESS 0x697Cu    /* 06297C */
#define sprite_list_062994_ADDRESS 0x6994u    /* 062994 */
#define sprite_list_0629A6_ADDRESS 0x69A6u    /* 0629A6 */
#define animation_0629B8_ADDRESS 0x69B8u    /* 0629B8 */
#define sprite_list_0629C4_ADDRESS 0x69C4u    /* 0629C4 */
#define sprite_list_0629CA_ADDRESS 0x69CAu    /* 0629CA */
#define animation_0629D0_ADDRESS 0x69D0u    /* 0629D0 */
#define sprite_list_0629DC_ADDRESS 0x69DCu    /* 0629DC */
#define sprite_list_0629E8_ADDRESS 0x69E8u    /* 0629E8 */
#define animation_0629F4_ADDRESS 0x69F4u    /* 0629F4 */
#define sprite_list_0629FC_ADDRESS 0x69FCu    /* 0629FC */
#define animation_062A08_ADDRESS 0x6A08u    /* 062A08 */
#define sprite_list_062A14_ADDRESS 0x6A14u    /* 062A14 */
#define sprite_list_062A20_ADDRESS 0x6A20u    /* 062A20 */
#define animation_062A38_ADDRESS 0x6A38u    /* 062A38 */
#define sprite_list_062A44_ADDRESS 0x6A44u    /* 062A44 */
#define sprite_list_062A50_ADDRESS 0x6A50u    /* 062A50 */
#define animation_062A5C_ADDRESS 0x6A5Cu    /* 062A5C */
#define sprite_list_062A68_ADDRESS 0x6A68u    /* 062A68 */
#define sprite_list_062A7A_ADDRESS 0x6A7Au    /* 062A7A */
#define animation_062A8C_ADDRESS 0x6A8Cu    /* 062A8C */
#define sprite_list_062A98_ADDRESS 0x6A98u    /* 062A98 */
#define sprite_list_062AA4_ADDRESS 0x6AA4u    /* 062AA4 */
#define animation_062AB6_ADDRESS 0x6AB6u    /* 062AB6 */
#define sprite_list_062AC2_ADDRESS 0x6AC2u    /* 062AC2 */
#define sprite_list_062ACE_ADDRESS 0x6ACEu    /* 062ACE */
#define animation_062ADA_ADDRESS 0x6ADAu    /* 062ADA */
#define sprite_list_062AE6_ADDRESS 0x6AE6u    /* 062AE6 */
#define sprite_list_062AF2_ADDRESS 0x6AF2u    /* 062AF2 */
#define animation_062AF8_ADDRESS 0x6AF8u    /* 062AF8 */
#define sprite_list_062B04_ADDRESS 0x6B04u    /* 062B04 */
#define sprite_list_062B0A_ADDRESS 0x6B0Au    /* 062B0A */
#define animation_062B16_ADDRESS 0x6B16u    /* 062B16 */
#define sprite_list_062B2A_ADDRESS 0x6B2Au    /* 062B2A */
#define sprite_list_062B36_ADDRESS 0x6B36u    /* 062B36 */
#define sprite_list_062B42_ADDRESS 0x6B42u    /* 062B42 */
#define sprite_list_062B4E_ADDRESS 0x6B4Eu    /* 062B4E */
#define animation_062B5A_ADDRESS 0x6B5Au    /* 062B5A */
#define sprite_list_062B6E_ADDRESS 0x6B6Eu    /* 062B6E */
#define sprite_list_062B7A_ADDRESS 0x6B7Au    /* 062B7A */
#define sprite_list_062B86_ADDRESS 0x6B86u    /* 062B86 */
#define sprite_list_062B92_ADDRESS 0x6B92u    /* 062B92 */
#define animation_062B9E_ADDRESS 0x6B9Eu    /* 062B9E */
#define sprite_list_062BB2_ADDRESS 0x6BB2u    /* 062BB2 */
#define sprite_list_062BBE_ADDRESS 0x6BBEu    /* 062BBE */
#define sprite_list_062BC4_ADDRESS 0x6BC4u    /* 062BC4 */
#define sprite_list_062BCA_ADDRESS 0x6BCAu    /* 062BCA */
#define animation_062BD0_ADDRESS 0x6BD0u    /* 062BD0 */
#define sprite_list_062BDC_ADDRESS 0x6BDCu    /* 062BDC */
#define sprite_list_062BE8_ADDRESS 0x6BE8u    /* 062BE8 */
#define animation_062BFA_ADDRESS 0x6BFAu    /* 062BFA */
#define sprite_list_062C02_ADDRESS 0x6C02u    /* 062C02 */
#define animation_062C08_ADDRESS 0x6C08u    /* 062C08 */
#define sprite_list_062C28_ADDRESS 0x6C28u    /* 062C28 */
#define sprite_list_062C34_ADDRESS 0x6C34u    /* 062C34 */
#define sprite_list_062C40_ADDRESS 0x6C40u    /* 062C40 */
#define sprite_list_062C46_ADDRESS 0x6C46u    /* 062C46 */
#define sprite_list_062C64_ADDRESS 0x6C64u    /* 062C64 */
#define sprite_list_062C7C_ADDRESS 0x6C7Cu    /* 062C7C */
#define sprite_list_062C8E_ADDRESS 0x6C8Eu    /* 062C8E */
#define animation_062C9A_ADDRESS 0x6C9Au    /* 062C9A */
#define sprite_list_062CAE_ADDRESS 0x6CAEu    /* 062CAE */
#define sprite_list_062CBA_ADDRESS 0x6CBAu    /* 062CBA */
#define sprite_list_062CC6_ADDRESS 0x6CC6u    /* 062CC6 */
#define sprite_list_062CD8_ADDRESS 0x6CD8u    /* 062CD8 */
#define animation_062CEA_ADDRESS 0x6CEAu    /* 062CEA */
#define sprite_list_062CF6_ADDRESS 0x6CF6u    /* 062CF6 */
#define animation_062D08_ADDRESS 0x6D08u    /* 062D08 */
#define sprite_list_062D18_ADDRESS 0x6D18u    /* 062D18 */
#define sprite_list_062D24_ADDRESS 0x6D24u    /* 062D24 */
#define sprite_list_062D30_ADDRESS 0x6D30u    /* 062D30 */
#define animation_062D36_ADDRESS 0x6D36u    /* 062D36 */
#define sprite_list_062D46_ADDRESS 0x6D46u    /* 062D46 */
#define sprite_list_062D52_ADDRESS 0x6D52u    /* 062D52 */
#define animation_062D5E_ADDRESS 0x6D5Eu    /* 062D5E */
#define sprite_list_062D72_ADDRESS 0x6D72u    /* 062D72 */
#define sprite_list_062D7E_ADDRESS 0x6D7Eu    /* 062D7E */
#define sprite_list_062D8A_ADDRESS 0x6D8Au    /* 062D8A */
#define sprite_list_062D96_ADDRESS 0x6D96u    /* 062D96 */
#define animation_062DA2_ADDRESS 0x6DA2u    /* 062DA2 */
#define sprite_list_062DAE_ADDRESS 0x6DAEu    /* 062DAE */
#define sprite_list_062DC6_ADDRESS 0x6DC6u    /* 062DC6 */
#define animation_062DD2_ADDRESS 0x6DD2u    /* 062DD2 */
#define sprite_list_062DDE_ADDRESS 0x6DDEu    /* 062DDE */
#define sprite_list_062DF0_ADDRESS 0x6DF0u    /* 062DF0 */
#define animation_062E02_ADDRESS 0x6E02u    /* 062E02 */
#define sprite_list_062E26_ADDRESS 0x6E26u    /* 062E26 */
#define sprite_list_062E32_ADDRESS 0x6E32u    /* 062E32 */
#define sprite_list_062E3E_ADDRESS 0x6E3Eu    /* 062E3E */
#define sprite_list_062E4A_ADDRESS 0x6E4Au    /* 062E4A */
#define animation_062E56_ADDRESS 0x6E56u    /* 062E56 */
#define sprite_list_062E5E_ADDRESS 0x6E5Eu    /* 062E5E */
#define animation_062E6A_ADDRESS 0x6E6Au    /* 062E6A */
#define sprite_list_062E76_ADDRESS 0x6E76u    /* 062E76 */
#define sprite_list_062E88_ADDRESS 0x6E88u    /* 062E88 */
#define animation_062E9A_ADDRESS 0x6E9Au    /* 062E9A */
#define sprite_list_062EA6_ADDRESS 0x6EA6u    /* 062EA6 */
#define sprite_list_062EB2_ADDRESS 0x6EB2u    /* 062EB2 */
#define animation_062EC4_ADDRESS 0x6EC4u    /* 062EC4 */
#define sprite_list_062ECC_ADDRESS 0x6ECCu    /* 062ECC */
#define animation_062EEA_ADDRESS 0x6EEAu    /* 062EEA */
#define sprite_list_062F0E_ADDRESS 0x6F0Eu    /* 062F0E */
#define sprite_list_062F2C_ADDRESS 0x6F2Cu    /* 062F2C */
#define sprite_list_062F4A_ADDRESS 0x6F4Au    /* 062F4A */
#define sprite_list_062F68_ADDRESS 0x6F68u    /* 062F68 */
#define sprite_list_062F86_ADDRESS 0x6F86u    /* 062F86 */
#define sprite_list_062FA4_ADDRESS 0x6FA4u    /* 062FA4 */
#define sprite_list_062FC2_ADDRESS 0x6FC2u    /* 062FC2 */
#define sprite_list_062FE0_ADDRESS 0x6FE0u    /* 062FE0 */
#define animation_062FFE_ADDRESS 0x6FFEu    /* 062FFE */
#define sprite_list_063006_ADDRESS 0x7006u    /* 063006 */
#define animation_063024_ADDRESS 0x7024u    /* 063024 */
#define sprite_list_06302C_ADDRESS 0x702Cu    /* 06302C */
#define animation_06304A_ADDRESS 0x704Au    /* 06304A */
#define animation_063052_ADDRESS 0x7052u    /* 063052 */
#define sprite_list_063062_ADDRESS 0x7062u    /* 063062 */
#define sprite_list_063074_ADDRESS 0x7074u    /* 063074 */
#define sprite_list_063086_ADDRESS 0x7086u    /* 063086 */
#define animation_06309E_ADDRESS 0x709Eu    /* 06309E */
#define sprite_list_0630AE_ADDRESS 0x70AEu    /* 0630AE */
#define sprite_list_0630C0_ADDRESS 0x70C0u    /* 0630C0 */
#define sprite_list_0630D8_ADDRESS 0x70D8u    /* 0630D8 */
#define animation_0630F0_ADDRESS 0x70F0u    /* 0630F0 */
#define sprite_list_0630F8_ADDRESS 0x70F8u    /* 0630F8 */
#define animation_063110_ADDRESS 0x7110u    /* 063110 */
#define sprite_list_063134_ADDRESS 0x7134u    /* 063134 */
#define sprite_list_06314C_ADDRESS 0x714Cu    /* 06314C */
#define sprite_list_063164_ADDRESS 0x7164u    /* 063164 */
#define sprite_list_06317C_ADDRESS 0x717Cu    /* 06317C */
#define sprite_list_063194_ADDRESS 0x7194u    /* 063194 */
#define sprite_list_0631AC_ADDRESS 0x71ACu    /* 0631AC */
#define sprite_list_0631C4_ADDRESS 0x71C4u    /* 0631C4 */
#define sprite_list_0631DC_ADDRESS 0x71DCu    /* 0631DC */
#define animation_0631F4_ADDRESS 0x71F4u    /* 0631F4 */
#define sprite_list_0631FC_ADDRESS 0x71FCu    /* 0631FC */
#define animation_06321A_ADDRESS 0x721Au    /* 06321A */
#define sprite_list_063222_ADDRESS 0x7222u    /* 063222 */
#define animation_063240_ADDRESS 0x7240u    /* 063240 */
#define sprite_list_06324C_ADDRESS 0x724Cu    /* 06324C */
#define sprite_list_06326A_ADDRESS 0x726Au    /* 06326A */
#define animation_063288_ADDRESS 0x7288u    /* 063288 */
#define sprite_list_06329C_ADDRESS 0x729Cu    /* 06329C */
#define sprite_list_0632B4_ADDRESS 0x72B4u    /* 0632B4 */
#define sprite_list_0632CC_ADDRESS 0x72CCu    /* 0632CC */
#define sprite_list_0632DE_ADDRESS 0x72DEu    /* 0632DE */
#define animation_0632F6_ADDRESS 0x72F6u    /* 0632F6 */
#define sprite_list_06330A_ADDRESS 0x730Au    /* 06330A */
#define sprite_list_063322_ADDRESS 0x7322u    /* 063322 */
#define sprite_list_06333A_ADDRESS 0x733Au    /* 06333A */
#define sprite_list_06334C_ADDRESS 0x734Cu    /* 06334C */
#define animation_063364_ADDRESS 0x7364u    /* 063364 */
#define sprite_list_06336C_ADDRESS 0x736Cu    /* 06336C */
#define animation_06337E_ADDRESS 0x737Eu    /* 06337E */
#define sprite_list_0633A2_ADDRESS 0x73A2u    /* 0633A2 */
#define sprite_list_0633B4_ADDRESS 0x73B4u    /* 0633B4 */
#define sprite_list_0633C6_ADDRESS 0x73C6u    /* 0633C6 */
#define sprite_list_0633D8_ADDRESS 0x73D8u    /* 0633D8 */
#define sprite_list_0633EA_ADDRESS 0x73EAu    /* 0633EA */
#define sprite_list_0633FC_ADDRESS 0x73FCu    /* 0633FC */
#define sprite_list_06340E_ADDRESS 0x740Eu    /* 06340E */
#define sprite_list_063420_ADDRESS 0x7420u    /* 063420 */
#define animation_063432_ADDRESS 0x7432u    /* 063432 */
#define sprite_list_06343A_ADDRESS 0x743Au    /* 06343A */
#define animation_06344C_ADDRESS 0x744Cu    /* 06344C */
#define sprite_list_063454_ADDRESS 0x7454u    /* 063454 */
#define animation_063466_ADDRESS 0x7466u    /* 063466 */
#define animation_06346E_ADDRESS 0x746Eu    /* 06346E */
#define sprite_list_06347E_ADDRESS 0x747Eu    /* 06347E */
#define sprite_list_063490_ADDRESS 0x7490u    /* 063490 */
#define sprite_list_0634A2_ADDRESS 0x74A2u    /* 0634A2 */
#define animation_0634B4_ADDRESS 0x74B4u    /* 0634B4 */
#define sprite_list_0634C4_ADDRESS 0x74C4u    /* 0634C4 */
#define sprite_list_0634D6_ADDRESS 0x74D6u    /* 0634D6 */
#define sprite_list_0634E8_ADDRESS 0x74E8u    /* 0634E8 */
#define animation_0634FA_ADDRESS 0x74FAu    /* 0634FA */
#define sprite_list_063506_ADDRESS 0x7506u    /* 063506 */
#define sprite_list_063512_ADDRESS 0x7512u    /* 063512 */
#define animation_06351E_ADDRESS 0x751Eu    /* 06351E */
#define sprite_list_063526_ADDRESS 0x7526u    /* 063526 */
#define animation_06352C_ADDRESS 0x752Cu    /* 06352C */
#define sprite_list_063538_ADDRESS 0x7538u    /* 063538 */
#define animation_06354A_ADDRESS 0x754Au    /* 06354A */
#define sprite_list_063552_ADDRESS 0x7552u    /* 063552 */
#define animation_063558_ADDRESS 0x7558u    /* 063558 */
#define sprite_list_06356C_ADDRESS 0x756Cu    /* 06356C */
#define sprite_list_06357E_ADDRESS 0x757Eu    /* 06357E */
#define sprite_list_063590_ADDRESS 0x7590u    /* 063590 */
#define sprite_list_0635A2_ADDRESS 0x75A2u    /* 0635A2 */
#define animation_0635B4_ADDRESS 0x75B4u    /* 0635B4 */
#define sprite_list_0635C8_ADDRESS 0x75C8u    /* 0635C8 */
#define sprite_list_0635D4_ADDRESS 0x75D4u    /* 0635D4 */
#define sprite_list_0635E6_ADDRESS 0x75E6u    /* 0635E6 */
#define sprite_list_0635F8_ADDRESS 0x75F8u    /* 0635F8 */
#define animation_06360A_ADDRESS 0x760Au    /* 06360A */
#define sprite_list_06362A_ADDRESS 0x762Au    /* 06362A */
#define sprite_list_063636_ADDRESS 0x7636u    /* 063636 */
#define sprite_list_06364E_ADDRESS 0x764Eu    /* 06364E */
#define sprite_list_063666_ADDRESS 0x7666u    /* 063666 */
#define sprite_list_063672_ADDRESS 0x7672u    /* 063672 */
#define sprite_list_063684_ADDRESS 0x7684u    /* 063684 */
#define sprite_list_063696_ADDRESS 0x7696u    /* 063696 */
#define animation_0636A8_ADDRESS 0x76A8u    /* 0636A8 */
#define sprite_list_0636B4_ADDRESS 0x76B4u    /* 0636B4 */
#define sprite_list_0636C6_ADDRESS 0x76C6u    /* 0636C6 */
#define animation_0636D8_ADDRESS 0x76D8u    /* 0636D8 */
#define sprite_list_0636E4_ADDRESS 0x76E4u    /* 0636E4 */
#define sprite_list_0636F0_ADDRESS 0x76F0u    /* 0636F0 */
#define animation_0636FC_ADDRESS 0x76FCu    /* 0636FC */
#define sprite_list_063708_ADDRESS 0x7708u    /* 063708 */
#define sprite_list_063714_ADDRESS 0x7714u    /* 063714 */
#define animation_table_06371A_ADDRESS 0x771Au    /* 06371A */
#define animation_06371E_ADDRESS 0x771Eu    /* 06371E */
#define sprite_list_063726_ADDRESS 0x7726u    /* 063726 */
#define animation_06372C_ADDRESS 0x772Cu    /* 06372C */
#define sprite_list_063734_ADDRESS 0x7734u    /* 063734 */
#define animation_table_063752_ADDRESS 0x7752u    /* 063752 */
#define animation_063758_ADDRESS 0x7758u    /* 063758 */
#define sprite_list_063760_ADDRESS 0x7760u    /* 063760 */
#define animation_063766_ADDRESS 0x7766u    /* 063766 */
#define sprite_list_06376E_ADDRESS 0x776Eu    /* 06376E */
#define animation_06378C_ADDRESS 0x778Cu    /* 06378C */
#define sprite_list_063794_ADDRESS 0x7794u    /* 063794 */
#define animation_table_06379A_ADDRESS 0x779Au    /* 06379A */
#define animation_0637C2_ADDRESS 0x77C2u    /* 0637C2 */
#define sprite_list_0637D6_ADDRESS 0x77D6u    /* 0637D6 */
#define sprite_list_0637DC_ADDRESS 0x77DCu    /* 0637DC */
#define sprite_list_0637E2_ADDRESS 0x77E2u    /* 0637E2 */
#define animation_0637E8_ADDRESS 0x77E8u    /* 0637E8 */
#define sprite_list_0637FC_ADDRESS 0x77FCu    /* 0637FC */
#define sprite_list_063802_ADDRESS 0x7802u    /* 063802 */
#define sprite_list_063808_ADDRESS 0x7808u    /* 063808 */
#define animation_06380E_ADDRESS 0x780Eu    /* 06380E */
#define sprite_list_063816_ADDRESS 0x7816u    /* 063816 */
#define animation_06381C_ADDRESS 0x781Cu    /* 06381C */
#define sprite_list_063824_ADDRESS 0x7824u    /* 063824 */
#define animation_063842_ADDRESS 0x7842u    /* 063842 */
#define sprite_list_06384A_ADDRESS 0x784Au    /* 06384A */
#define animation_063850_ADDRESS 0x7850u    /* 063850 */
#define sprite_list_063858_ADDRESS 0x7858u    /* 063858 */
#define animation_063876_ADDRESS 0x7876u    /* 063876 */
#define sprite_list_06387E_ADDRESS 0x787Eu    /* 06387E */
#define animation_063884_ADDRESS 0x7884u    /* 063884 */
#define sprite_list_06388C_ADDRESS 0x788Cu    /* 06388C */
#define animation_0638AA_ADDRESS 0x78AAu    /* 0638AA */
#define sprite_list_0638B2_ADDRESS 0x78B2u    /* 0638B2 */
#define animation_0638B8_ADDRESS 0x78B8u    /* 0638B8 */
#define sprite_list_0638C0_ADDRESS 0x78C0u    /* 0638C0 */
#define animation_0638DE_ADDRESS 0x78DEu    /* 0638DE */
#define sprite_list_0638E6_ADDRESS 0x78E6u    /* 0638E6 */
#define animation_0638EC_ADDRESS 0x78ECu    /* 0638EC */
#define sprite_list_0638F4_ADDRESS 0x78F4u    /* 0638F4 */
#define animation_063912_ADDRESS 0x7912u    /* 063912 */
#define sprite_list_06391A_ADDRESS 0x791Au    /* 06391A */
#define animation_063920_ADDRESS 0x7920u    /* 063920 */
#define sprite_list_063928_ADDRESS 0x7928u    /* 063928 */
#define animation_063946_ADDRESS 0x7946u    /* 063946 */
#define sprite_list_06394E_ADDRESS 0x794Eu    /* 06394E */
#define animation_063954_ADDRESS 0x7954u    /* 063954 */
#define sprite_list_06395C_ADDRESS 0x795Cu    /* 06395C */
#define animation_06397A_ADDRESS 0x797Au    /* 06397A */
#define sprite_list_063982_ADDRESS 0x7982u    /* 063982 */
#define animation_063988_ADDRESS 0x7988u    /* 063988 */
#define sprite_list_063990_ADDRESS 0x7990u    /* 063990 */
#define animation_table_0639AE_ADDRESS 0x79AEu    /* 0639AE */
#define animation_0639C8_ADDRESS 0x79C8u    /* 0639C8 */
#define sprite_list_0639D4_ADDRESS 0x79D4u    /* 0639D4 */
#define sprite_list_0639DA_ADDRESS 0x79DAu    /* 0639DA */
#define animation_0639E0_ADDRESS 0x79E0u    /* 0639E0 */
#define sprite_list_0639FC_ADDRESS 0x79FCu    /* 0639FC */
#define sprite_list_063A08_ADDRESS 0x7A08u    /* 063A08 */
#define sprite_list_063A14_ADDRESS 0x7A14u    /* 063A14 */
#define sprite_list_063A20_ADDRESS 0x7A20u    /* 063A20 */
#define sprite_list_063A2C_ADDRESS 0x7A2Cu    /* 063A2C */
#define sprite_list_063A38_ADDRESS 0x7A38u    /* 063A38 */
#define animation_063A44_ADDRESS 0x7A44u    /* 063A44 */
#define sprite_list_063A68_ADDRESS 0x7A68u    /* 063A68 */
#define sprite_list_063A7A_ADDRESS 0x7A7Au    /* 063A7A */
#define sprite_list_063A8C_ADDRESS 0x7A8Cu    /* 063A8C */
#define sprite_list_063A9E_ADDRESS 0x7A9Eu    /* 063A9E */
#define sprite_list_063AB0_ADDRESS 0x7AB0u    /* 063AB0 */
#define sprite_list_063AC2_ADDRESS 0x7AC2u    /* 063AC2 */
#define sprite_list_063AD4_ADDRESS 0x7AD4u    /* 063AD4 */
#define sprite_list_063AE6_ADDRESS 0x7AE6u    /* 063AE6 */
#define animation_063AF8_ADDRESS 0x7AF8u    /* 063AF8 */
#define sprite_list_063B0C_ADDRESS 0x7B0Cu    /* 063B0C */
#define sprite_list_063B12_ADDRESS 0x7B12u    /* 063B12 */
#define sprite_list_063B18_ADDRESS 0x7B18u    /* 063B18 */
#define sprite_list_063B1E_ADDRESS 0x7B1Eu    /* 063B1E */
#define animation_063B30_ADDRESS 0x7B30u    /* 063B30 */
#define sprite_list_063B38_ADDRESS 0x7B38u    /* 063B38 */
#define animation_063B44_ADDRESS 0x7B44u    /* 063B44 */
#define sprite_list_063B50_ADDRESS 0x7B50u    /* 063B50 */
#define sprite_list_063B5C_ADDRESS 0x7B5Cu    /* 063B5C */
#define animation_063B6E_ADDRESS 0x7B6Eu    /* 063B6E */
#define sprite_list_063B82_ADDRESS 0x7B82u    /* 063B82 */
#define sprite_list_063B8E_ADDRESS 0x7B8Eu    /* 063B8E */
#define sprite_list_063B9A_ADDRESS 0x7B9Au    /* 063B9A */
#define animation_063BA6_ADDRESS 0x7BA6u    /* 063BA6 */
#define sprite_list_063BBA_ADDRESS 0x7BBAu    /* 063BBA */
#define sprite_list_063BC6_ADDRESS 0x7BC6u    /* 063BC6 */
#define sprite_list_063BD2_ADDRESS 0x7BD2u    /* 063BD2 */
#define animation_063BDE_ADDRESS 0x7BDEu    /* 063BDE */
#define sprite_list_063BF6_ADDRESS 0x7BF6u    /* 063BF6 */
#define sprite_list_063C02_ADDRESS 0x7C02u    /* 063C02 */
#define sprite_list_063C0E_ADDRESS 0x7C0Eu    /* 063C0E */
#define sprite_list_063C1A_ADDRESS 0x7C1Au    /* 063C1A */
#define sprite_list_063C26_ADDRESS 0x7C26u    /* 063C26 */
#define animation_063C32_ADDRESS 0x7C32u    /* 063C32 */
#define sprite_list_063C42_ADDRESS 0x7C42u    /* 063C42 */
#define sprite_list_063C4E_ADDRESS 0x7C4Eu    /* 063C4E */
#define animation_063C5A_ADDRESS 0x7C5Au    /* 063C5A */
#define sprite_list_063C72_ADDRESS 0x7C72u    /* 063C72 */
#define sprite_list_063C84_ADDRESS 0x7C84u    /* 063C84 */
#define sprite_list_063C96_ADDRESS 0x7C96u    /* 063C96 */
#define sprite_list_063CA8_ADDRESS 0x7CA8u    /* 063CA8 */
#define sprite_list_063CC0_ADDRESS 0x7CC0u    /* 063CC0 */
#define animation_063CE4_ADDRESS 0x7CE4u    /* 063CE4 */
#define sprite_list_063CF4_ADDRESS 0x7CF4u    /* 063CF4 */
#define sprite_list_063D12_ADDRESS 0x7D12u    /* 063D12 */
#define sprite_list_063D30_ADDRESS 0x7D30u    /* 063D30 */
#define animation_063D48_ADDRESS 0x7D48u    /* 063D48 */
#define sprite_list_063D50_ADDRESS 0x7D50u    /* 063D50 */
#define fill_063D62_ADDRESS 0x7D62u    /* 063D62 */
#define unreached_animation_063D8E_ADDRESS 0x7D8Eu    /* 063D8E */
#define sprite_list_063D96_ADDRESS 0x7D96u    /* 063D96 */
#define unreached_animation_063DA8_ADDRESS 0x7DA8u    /* 063DA8 */
#define sprite_list_063DB0_ADDRESS 0x7DB0u    /* 063DB0 */
#define unreached_animation_063DB6_ADDRESS 0x7DB6u    /* 063DB6 */
#define sprite_list_063DBE_ADDRESS 0x7DBEu    /* 063DBE */
#define fill_063DCA_ADDRESS 0x7DCAu    /* 063DCA */
#define unreached_animation_063DDA_ADDRESS 0x7DDAu    /* 063DDA */
#define sprite_list_063DE2_ADDRESS 0x7DE2u    /* 063DE2 */
#define unreached_animation_063DE8_ADDRESS 0x7DE8u    /* 063DE8 */
#define sprite_list_063DF0_ADDRESS 0x7DF0u    /* 063DF0 */
#define unreached_animation_063DF6_ADDRESS 0x7DF6u    /* 063DF6 */
#define sprite_list_063DFE_ADDRESS 0x7DFEu    /* 063DFE */
#define unreached_animation_063E04_ADDRESS 0x7E04u    /* 063E04 */
#define sprite_list_063E0C_ADDRESS 0x7E0Cu    /* 063E0C */
#define unreached_animation_063E12_ADDRESS 0x7E12u    /* 063E12 */
#define sprite_list_063E2A_ADDRESS 0x7E2Au    /* 063E2A */
#define sprite_list_063E30_ADDRESS 0x7E30u    /* 063E30 */
#define sprite_list_063E36_ADDRESS 0x7E36u    /* 063E36 */
#define sprite_list_063E3C_ADDRESS 0x7E3Cu    /* 063E3C */
#define sprite_list_063E42_ADDRESS 0x7E42u    /* 063E42 */
#define unreached_animation_063E48_ADDRESS 0x7E48u    /* 063E48 */
#define sprite_list_063E5C_ADDRESS 0x7E5Cu    /* 063E5C */
#define sprite_list_063E62_ADDRESS 0x7E62u    /* 063E62 */
#define sprite_list_063E74_ADDRESS 0x7E74u    /* 063E74 */
#define sprite_list_063E8C_ADDRESS 0x7E8Cu    /* 063E8C */
#define unreached_animation_063EA4_ADDRESS 0x7EA4u    /* 063EA4 */
#define sprite_list_063EB0_ADDRESS 0x7EB0u    /* 063EB0 */
#define sprite_list_063EDA_ADDRESS 0x7EDAu    /* 063EDA */
#define unreached_animation_063F04_ADDRESS 0x7F04u    /* 063F04 */
#define sprite_list_063F0C_ADDRESS 0x7F0Cu    /* 063F0C */
#define unreached_animation_063F12_ADDRESS 0x7F12u    /* 063F12 */
#define sprite_list_063F1A_ADDRESS 0x7F1Au    /* 063F1A */
#define unreached_animation_063F38_ADDRESS 0x7F38u    /* 063F38 */
#define sprite_list_063F40_ADDRESS 0x7F40u    /* 063F40 */
#define unreached_animation_063F58_ADDRESS 0x7F58u    /* 063F58 */
#define sprite_list_063F60_ADDRESS 0x7F60u    /* 063F60 */
#define fill_063F6C_ADDRESS 0x7F6Cu    /* 063F6C */
#define unreached_animation_063F6E_ADDRESS 0x7F6Eu    /* 063F6E */
#define sprite_list_063F76_ADDRESS 0x7F76u    /* 063F76 */
#define unreached_animation_063F7C_ADDRESS 0x7F7Cu    /* 063F7C */
#define sprite_list_063F84_ADDRESS 0x7F84u    /* 063F84 */
#define unreached_animation_063F8A_ADDRESS 0x7F8Au    /* 063F8A */
#define sprite_list_063F92_ADDRESS 0x7F92u    /* 063F92 */
#define unreached_animation_063F9E_ADDRESS 0x7F9Eu    /* 063F9E */
#define sprite_list_063FAA_ADDRESS 0x7FAAu    /* 063FAA */
#define sprite_list_063FB0_ADDRESS 0x7FB0u    /* 063FB0 */
#define unreached_animation_063FB6_ADDRESS 0x7FB6u    /* 063FB6 */
#define sprite_list_063FBE_ADDRESS 0x7FBEu    /* 063FBE */
#define unreached_animation_063FC4_ADDRESS 0x7FC4u    /* 063FC4 */
#define sprite_list_063FCC_ADDRESS 0x7FCCu    /* 063FCC */
#define unreached_animation_063FD2_ADDRESS 0x7FD2u    /* 063FD2 */
#define sprite_list_063FDA_ADDRESS 0x7FDAu    /* 063FDA */
#define unreached_animation_063FE0_ADDRESS 0x7FE0u    /* 063FE0 */
#define sprite_list_063FE8_ADDRESS 0x7FE8u    /* 063FE8 */
#define fill_063FEE_ADDRESS 0x7FEEu    /* 063FEE */
#define set_index_064000_ADDRESS 0x6000u    /* 064000 */
#define animation_table_064006_ADDRESS 0x6006u    /* 064006 */
#define animation_064106_ADDRESS 0x6106u    /* 064106 */
#define sprite_list_06410E_ADDRESS 0x610Eu    /* 06410E */
#define animation_06411A_ADDRESS 0x611Au    /* 06411A */
#define sprite_list_064122_ADDRESS 0x6122u    /* 064122 */
#define animation_064128_ADDRESS 0x6128u    /* 064128 */
#define sprite_list_064130_ADDRESS 0x6130u    /* 064130 */
#define animation_064136_ADDRESS 0x6136u    /* 064136 */
#define sprite_list_06414E_ADDRESS 0x614Eu    /* 06414E */
#define sprite_list_06415A_ADDRESS 0x615Au    /* 06415A */
#define sprite_list_064166_ADDRESS 0x6166u    /* 064166 */
#define sprite_list_06417E_ADDRESS 0x617Eu    /* 06417E */
#define sprite_list_064190_ADDRESS 0x6190u    /* 064190 */
#define animation_0641A8_ADDRESS 0x61A8u    /* 0641A8 */
#define animation_0641B0_ADDRESS 0x61B0u    /* 0641B0 */
#define animation_0641B8_ADDRESS 0x61B8u    /* 0641B8 */
#define sprite_list_0641DC_ADDRESS 0x61DCu    /* 0641DC */
#define sprite_list_0641F4_ADDRESS 0x61F4u    /* 0641F4 */
#define sprite_list_06420C_ADDRESS 0x620Cu    /* 06420C */
#define sprite_list_06421E_ADDRESS 0x621Eu    /* 06421E */
#define sprite_list_064236_ADDRESS 0x6236u    /* 064236 */
#define sprite_list_06424E_ADDRESS 0x624Eu    /* 06424E */
#define sprite_list_064266_ADDRESS 0x6266u    /* 064266 */
#define sprite_list_064278_ADDRESS 0x6278u    /* 064278 */
#define animation_064290_ADDRESS 0x6290u    /* 064290 */
#define sprite_list_064298_ADDRESS 0x6298u    /* 064298 */
#define animation_0642B0_ADDRESS 0x62B0u    /* 0642B0 */
#define sprite_list_0642B8_ADDRESS 0x62B8u    /* 0642B8 */
#define animation_0642D0_ADDRESS 0x62D0u    /* 0642D0 */
#define sprite_list_0642DC_ADDRESS 0x62DCu    /* 0642DC */
#define sprite_list_0642E8_ADDRESS 0x62E8u    /* 0642E8 */
#define animation_0642F4_ADDRESS 0x62F4u    /* 0642F4 */
#define sprite_list_064300_ADDRESS 0x6300u    /* 064300 */
#define sprite_list_064318_ADDRESS 0x6318u    /* 064318 */
#define animation_064336_ADDRESS 0x6336u    /* 064336 */
#define animation_064342_ADDRESS 0x6342u    /* 064342 */
#define animation_06434A_ADDRESS 0x634Au    /* 06434A */
#define sprite_list_064362_ADDRESS 0x6362u    /* 064362 */
#define sprite_list_064374_ADDRESS 0x6374u    /* 064374 */
#define sprite_list_064386_ADDRESS 0x6386u    /* 064386 */
#define sprite_list_064398_ADDRESS 0x6398u    /* 064398 */
#define sprite_list_0643AA_ADDRESS 0x63AAu    /* 0643AA */
#define animation_0643C2_ADDRESS 0x63C2u    /* 0643C2 */
#define sprite_list_0643E6_ADDRESS 0x63E6u    /* 0643E6 */
#define sprite_list_0643FE_ADDRESS 0x63FEu    /* 0643FE */
#define sprite_list_064416_ADDRESS 0x6416u    /* 064416 */
#define sprite_list_06442E_ADDRESS 0x642Eu    /* 06442E */
#define sprite_list_064446_ADDRESS 0x6446u    /* 064446 */
#define sprite_list_06445E_ADDRESS 0x645Eu    /* 06445E */
#define sprite_list_064476_ADDRESS 0x6476u    /* 064476 */
#define sprite_list_06448E_ADDRESS 0x648Eu    /* 06448E */
#define animation_0644A6_ADDRESS 0x64A6u    /* 0644A6 */
#define animation_0644AE_ADDRESS 0x64AEu    /* 0644AE */
#define animation_0644D2_ADDRESS 0x64D2u    /* 0644D2 */
#define sprite_list_0644DA_ADDRESS 0x64DAu    /* 0644DA */
#define animation_0644F2_ADDRESS 0x64F2u    /* 0644F2 */
#define sprite_list_0644FA_ADDRESS 0x64FAu    /* 0644FA */
#define animation_064512_ADDRESS 0x6512u    /* 064512 */
#define sprite_list_064526_ADDRESS 0x6526u    /* 064526 */
#define sprite_list_064538_ADDRESS 0x6538u    /* 064538 */
#define sprite_list_064550_ADDRESS 0x6550u    /* 064550 */
#define sprite_list_064568_ADDRESS 0x6568u    /* 064568 */
#define animation_064580_ADDRESS 0x6580u    /* 064580 */
#define sprite_list_06458C_ADDRESS 0x658Cu    /* 06458C */
#define sprite_list_0645AA_ADDRESS 0x65AAu    /* 0645AA */
#define animation_0645C2_ADDRESS 0x65C2u    /* 0645C2 */
#define sprite_list_0645CA_ADDRESS 0x65CAu    /* 0645CA */
#define animation_0645D6_ADDRESS 0x65D6u    /* 0645D6 */
#define sprite_list_064606_ADDRESS 0x6606u    /* 064606 */
#define sprite_list_064612_ADDRESS 0x6612u    /* 064612 */
#define sprite_list_06461E_ADDRESS 0x661Eu    /* 06461E */
#define sprite_list_06462A_ADDRESS 0x662Au    /* 06462A */
#define sprite_list_064636_ADDRESS 0x6636u    /* 064636 */
#define sprite_list_064642_ADDRESS 0x6642u    /* 064642 */
#define sprite_list_06464E_ADDRESS 0x664Eu    /* 06464E */
#define sprite_list_06465A_ADDRESS 0x665Au    /* 06465A */
#define sprite_list_064666_ADDRESS 0x6666u    /* 064666 */
#define sprite_list_064672_ADDRESS 0x6672u    /* 064672 */
#define sprite_list_06467E_ADDRESS 0x667Eu    /* 06467E */
#define animation_06468A_ADDRESS 0x668Au    /* 06468A */
#define sprite_list_06469A_ADDRESS 0x669Au    /* 06469A */
#define sprite_list_0646A6_ADDRESS 0x66A6u    /* 0646A6 */
#define sprite_list_0646B8_ADDRESS 0x66B8u    /* 0646B8 */
#define animation_0646C4_ADDRESS 0x66C4u    /* 0646C4 */
#define sprite_list_0646D4_ADDRESS 0x66D4u    /* 0646D4 */
#define sprite_list_0646E0_ADDRESS 0x66E0u    /* 0646E0 */
#define sprite_list_0646EC_ADDRESS 0x66ECu    /* 0646EC */
#define animation_0646F8_ADDRESS 0x66F8u    /* 0646F8 */
#define sprite_list_064708_ADDRESS 0x6708u    /* 064708 */
#define sprite_list_064714_ADDRESS 0x6714u    /* 064714 */
#define sprite_list_064720_ADDRESS 0x6720u    /* 064720 */
#define animation_06472C_ADDRESS 0x672Cu    /* 06472C */
#define sprite_list_064740_ADDRESS 0x6740u    /* 064740 */
#define sprite_list_06474C_ADDRESS 0x674Cu    /* 06474C */
#define sprite_list_064758_ADDRESS 0x6758u    /* 064758 */
#define sprite_list_064764_ADDRESS 0x6764u    /* 064764 */
#define animation_064770_ADDRESS 0x6770u    /* 064770 */
#define sprite_list_064784_ADDRESS 0x6784u    /* 064784 */
#define sprite_list_064790_ADDRESS 0x6790u    /* 064790 */
#define sprite_list_064796_ADDRESS 0x6796u    /* 064796 */
#define sprite_list_0647A2_ADDRESS 0x67A2u    /* 0647A2 */
#define animation_0647A8_ADDRESS 0x67A8u    /* 0647A8 */
#define sprite_list_0647BC_ADDRESS 0x67BCu    /* 0647BC */
#define sprite_list_0647C8_ADDRESS 0x67C8u    /* 0647C8 */
#define sprite_list_0647CE_ADDRESS 0x67CEu    /* 0647CE */
#define sprite_list_0647DA_ADDRESS 0x67DAu    /* 0647DA */
#define animation_0647E0_ADDRESS 0x67E0u    /* 0647E0 */
#define sprite_list_0647F0_ADDRESS 0x67F0u    /* 0647F0 */
#define sprite_list_0647FC_ADDRESS 0x67FCu    /* 0647FC */
#define sprite_list_064808_ADDRESS 0x6808u    /* 064808 */
#define animation_06480E_ADDRESS 0x680Eu    /* 06480E */
#define sprite_list_064816_ADDRESS 0x6816u    /* 064816 */
#define animation_064822_ADDRESS 0x6822u    /* 064822 */
#define sprite_list_064832_ADDRESS 0x6832u    /* 064832 */
#define sprite_list_064838_ADDRESS 0x6838u    /* 064838 */
#define sprite_list_064844_ADDRESS 0x6844u    /* 064844 */
#define animation_064850_ADDRESS 0x6850u    /* 064850 */
#define sprite_list_064864_ADDRESS 0x6864u    /* 064864 */
#define sprite_list_064870_ADDRESS 0x6870u    /* 064870 */
#define sprite_list_06487C_ADDRESS 0x687Cu    /* 06487C */
#define sprite_list_064888_ADDRESS 0x6888u    /* 064888 */
#define animation_064894_ADDRESS 0x6894u    /* 064894 */
#define sprite_list_0648A8_ADDRESS 0x68A8u    /* 0648A8 */
#define sprite_list_0648B4_ADDRESS 0x68B4u    /* 0648B4 */
#define sprite_list_0648C0_ADDRESS 0x68C0u    /* 0648C0 */
#define animation_0648CC_ADDRESS 0x68CCu    /* 0648CC */
#define sprite_list_0648D4_ADDRESS 0x68D4u    /* 0648D4 */
#define animation_0648E0_ADDRESS 0x68E0u    /* 0648E0 */
#define sprite_list_0648F0_ADDRESS 0x68F0u    /* 0648F0 */
#define sprite_list_0648F6_ADDRESS 0x68F6u    /* 0648F6 */
#define sprite_list_064902_ADDRESS 0x6902u    /* 064902 */
#define animation_06490E_ADDRESS 0x690Eu    /* 06490E */
#define sprite_list_06491A_ADDRESS 0x691Au    /* 06491A */
#define sprite_list_064926_ADDRESS 0x6926u    /* 064926 */
#define animation_064932_ADDRESS 0x6932u    /* 064932 */
#define sprite_list_06493E_ADDRESS 0x693Eu    /* 06493E */
#define sprite_list_06494A_ADDRESS 0x694Au    /* 06494A */
#define animation_064956_ADDRESS 0x6956u    /* 064956 */
#define sprite_list_064966_ADDRESS 0x6966u    /* 064966 */
#define sprite_list_064972_ADDRESS 0x6972u    /* 064972 */
#define sprite_list_06497E_ADDRESS 0x697Eu    /* 06497E */
#define animation_06498A_ADDRESS 0x698Au    /* 06498A */
#define sprite_list_06499E_ADDRESS 0x699Eu    /* 06499E */
#define sprite_list_0649AA_ADDRESS 0x69AAu    /* 0649AA */
#define sprite_list_0649BC_ADDRESS 0x69BCu    /* 0649BC */
#define sprite_list_0649CE_ADDRESS 0x69CEu    /* 0649CE */
#define animation_0649E0_ADDRESS 0x69E0u    /* 0649E0 */
#define sprite_list_064A00_ADDRESS 0x6A00u    /* 064A00 */
#define sprite_list_064A06_ADDRESS 0x6A06u    /* 064A06 */
#define sprite_list_064A12_ADDRESS 0x6A12u    /* 064A12 */
#define sprite_list_064A24_ADDRESS 0x6A24u    /* 064A24 */
#define sprite_list_064A30_ADDRESS 0x6A30u    /* 064A30 */
#define sprite_list_064A3C_ADDRESS 0x6A3Cu    /* 064A3C */
#define sprite_list_064A48_ADDRESS 0x6A48u    /* 064A48 */
#define animation_064A54_ADDRESS 0x6A54u    /* 064A54 */
#define sprite_list_064A60_ADDRESS 0x6A60u    /* 064A60 */
#define sprite_list_064A66_ADDRESS 0x6A66u    /* 064A66 */
#define animation_064A6C_ADDRESS 0x6A6Cu    /* 064A6C */
#define sprite_list_064A78_ADDRESS 0x6A78u    /* 064A78 */
#define sprite_list_064A84_ADDRESS 0x6A84u    /* 064A84 */
#define animation_064A90_ADDRESS 0x6A90u    /* 064A90 */
#define sprite_list_064A9C_ADDRESS 0x6A9Cu    /* 064A9C */
#define sprite_list_064AA8_ADDRESS 0x6AA8u    /* 064AA8 */
#define animation_064AC0_ADDRESS 0x6AC0u    /* 064AC0 */
#define sprite_list_064AF8_ADDRESS 0x6AF8u    /* 064AF8 */
#define sprite_list_064B04_ADDRESS 0x6B04u    /* 064B04 */
#define sprite_list_064B10_ADDRESS 0x6B10u    /* 064B10 */
#define sprite_list_064B1C_ADDRESS 0x6B1Cu    /* 064B1C */
#define sprite_list_064B28_ADDRESS 0x6B28u    /* 064B28 */
#define sprite_list_064B34_ADDRESS 0x6B34u    /* 064B34 */
#define animation_064B40_ADDRESS 0x6B40u    /* 064B40 */
#define sprite_list_064B5C_ADDRESS 0x6B5Cu    /* 064B5C */
#define sprite_list_064B6E_ADDRESS 0x6B6Eu    /* 064B6E */
#define sprite_list_064B80_ADDRESS 0x6B80u    /* 064B80 */
#define sprite_list_064B92_ADDRESS 0x6B92u    /* 064B92 */
#define sprite_list_064BA4_ADDRESS 0x6BA4u    /* 064BA4 */
#define sprite_list_064BB0_ADDRESS 0x6BB0u    /* 064BB0 */
#define animation_064BBC_ADDRESS 0x6BBCu    /* 064BBC */
#define sprite_list_064BD8_ADDRESS 0x6BD8u    /* 064BD8 */
#define sprite_list_064BE4_ADDRESS 0x6BE4u    /* 064BE4 */
#define sprite_list_064BF0_ADDRESS 0x6BF0u    /* 064BF0 */
#define sprite_list_064BFC_ADDRESS 0x6BFCu    /* 064BFC */
#define sprite_list_064C08_ADDRESS 0x6C08u    /* 064C08 */
#define sprite_list_064C14_ADDRESS 0x6C14u    /* 064C14 */
#define animation_064C20_ADDRESS 0x6C20u    /* 064C20 */
#define sprite_list_064C28_ADDRESS 0x6C28u    /* 064C28 */
#define animation_064C3A_ADDRESS 0x6C3Au    /* 064C3A */
#define sprite_list_064C42_ADDRESS 0x6C42u    /* 064C42 */
#define animation_064C4E_ADDRESS 0x6C4Eu    /* 064C4E */
#define sprite_list_064C56_ADDRESS 0x6C56u    /* 064C56 */
#define animation_064C62_ADDRESS 0x6C62u    /* 064C62 */
#define sprite_list_064C6A_ADDRESS 0x6C6Au    /* 064C6A */
#define animation_064C7C_ADDRESS 0x6C7Cu    /* 064C7C */
#define sprite_list_064C98_ADDRESS 0x6C98u    /* 064C98 */
#define sprite_list_064CAA_ADDRESS 0x6CAAu    /* 064CAA */
#define sprite_list_064CBC_ADDRESS 0x6CBCu    /* 064CBC */
#define sprite_list_064CCE_ADDRESS 0x6CCEu    /* 064CCE */
#define sprite_list_064CE0_ADDRESS 0x6CE0u    /* 064CE0 */
#define sprite_list_064CF2_ADDRESS 0x6CF2u    /* 064CF2 */
#define animation_064D04_ADDRESS 0x6D04u    /* 064D04 */
#define sprite_list_064D0C_ADDRESS 0x6D0Cu    /* 064D0C */
#define animation_064D18_ADDRESS 0x6D18u    /* 064D18 */
#define sprite_list_064D34_ADDRESS 0x6D34u    /* 064D34 */
#define sprite_list_064D46_ADDRESS 0x6D46u    /* 064D46 */
#define sprite_list_064D58_ADDRESS 0x6D58u    /* 064D58 */
#define sprite_list_064D6A_ADDRESS 0x6D6Au    /* 064D6A */
#define sprite_list_064D7C_ADDRESS 0x6D7Cu    /* 064D7C */
#define sprite_list_064D8E_ADDRESS 0x6D8Eu    /* 064D8E */
#define animation_064DA0_ADDRESS 0x6DA0u    /* 064DA0 */
#define sprite_list_064DAC_ADDRESS 0x6DACu    /* 064DAC */
#define animation_064DBE_ADDRESS 0x6DBEu    /* 064DBE */
#define sprite_list_064DCA_ADDRESS 0x6DCAu    /* 064DCA */
#define animation_064DD6_ADDRESS 0x6DD6u    /* 064DD6 */
#define sprite_list_064DF2_ADDRESS 0x6DF2u    /* 064DF2 */
#define sprite_list_064DFE_ADDRESS 0x6DFEu    /* 064DFE */
#define sprite_list_064E0A_ADDRESS 0x6E0Au    /* 064E0A */
#define sprite_list_064E16_ADDRESS 0x6E16u    /* 064E16 */
#define sprite_list_064E22_ADDRESS 0x6E22u    /* 064E22 */
#define sprite_list_064E2E_ADDRESS 0x6E2Eu    /* 064E2E */
#define animation_064E3A_ADDRESS 0x6E3Au    /* 064E3A */
#define sprite_list_064E46_ADDRESS 0x6E46u    /* 064E46 */
#define sprite_list_064E4C_ADDRESS 0x6E4Cu    /* 064E4C */
#define animation_064E58_ADDRESS 0x6E58u    /* 064E58 */
#define sprite_list_064E6C_ADDRESS 0x6E6Cu    /* 064E6C */
#define sprite_list_064E78_ADDRESS 0x6E78u    /* 064E78 */
#define sprite_list_064E84_ADDRESS 0x6E84u    /* 064E84 */
#define animation_064E90_ADDRESS 0x6E90u    /* 064E90 */
#define sprite_list_064EA8_ADDRESS 0x6EA8u    /* 064EA8 */
#define sprite_list_064EB4_ADDRESS 0x6EB4u    /* 064EB4 */
#define sprite_list_064EC0_ADDRESS 0x6EC0u    /* 064EC0 */
#define sprite_list_064ECC_ADDRESS 0x6ECCu    /* 064ECC */
#define sprite_list_064ED8_ADDRESS 0x6ED8u    /* 064ED8 */
#define animation_064EE4_ADDRESS 0x6EE4u    /* 064EE4 */
#define sprite_list_064EF0_ADDRESS 0x6EF0u    /* 064EF0 */
#define sprite_list_064EFC_ADDRESS 0x6EFCu    /* 064EFC */
#define animation_064F08_ADDRESS 0x6F08u    /* 064F08 */
#define sprite_list_064F14_ADDRESS 0x6F14u    /* 064F14 */
#define sprite_list_064F20_ADDRESS 0x6F20u    /* 064F20 */
#define animation_064F2C_ADDRESS 0x6F2Cu    /* 064F2C */
#define sprite_list_064F34_ADDRESS 0x6F34u    /* 064F34 */
#define animation_064F3A_ADDRESS 0x6F3Au    /* 064F3A */
#define sprite_list_064F42_ADDRESS 0x6F42u    /* 064F42 */
#define animation_064F48_ADDRESS 0x6F48u    /* 064F48 */
#define sprite_list_064F64_ADDRESS 0x6F64u    /* 064F64 */
#define sprite_list_064F70_ADDRESS 0x6F70u    /* 064F70 */
#define sprite_list_064F7C_ADDRESS 0x6F7Cu    /* 064F7C */
#define sprite_list_064F88_ADDRESS 0x6F88u    /* 064F88 */
#define sprite_list_064F94_ADDRESS 0x6F94u    /* 064F94 */
#define sprite_list_064FA0_ADDRESS 0x6FA0u    /* 064FA0 */
#define animation_064FAC_ADDRESS 0x6FACu    /* 064FAC */
#define sprite_list_064FB4_ADDRESS 0x6FB4u    /* 064FB4 */
#define animation_064FBA_ADDRESS 0x6FBAu    /* 064FBA */
#define sprite_list_064FC2_ADDRESS 0x6FC2u    /* 064FC2 */
#define animation_064FC8_ADDRESS 0x6FC8u    /* 064FC8 */
#define sprite_list_064FD4_ADDRESS 0x6FD4u    /* 064FD4 */
#define sprite_list_064FDA_ADDRESS 0x6FDAu    /* 064FDA */
#define animation_064FE0_ADDRESS 0x6FE0u    /* 064FE0 */
#define sprite_list_064FF4_ADDRESS 0x6FF4u    /* 064FF4 */
#define sprite_list_064FFA_ADDRESS 0x6FFAu    /* 064FFA */
#define sprite_list_065000_ADDRESS 0x7000u    /* 065000 */
#define sprite_list_06501E_ADDRESS 0x701Eu    /* 06501E */
#define animation_06503C_ADDRESS 0x703Cu    /* 06503C */
#define sprite_list_065050_ADDRESS 0x7050u    /* 065050 */
#define sprite_list_065062_ADDRESS 0x7062u    /* 065062 */
#define sprite_list_065074_ADDRESS 0x7074u    /* 065074 */
#define sprite_list_065086_ADDRESS 0x7086u    /* 065086 */
#define animation_065098_ADDRESS 0x7098u    /* 065098 */
#define sprite_list_0650A4_ADDRESS 0x70A4u    /* 0650A4 */
#define sprite_list_0650B6_ADDRESS 0x70B6u    /* 0650B6 */
#define animation_0650C2_ADDRESS 0x70C2u    /* 0650C2 */
#define sprite_list_0650CE_ADDRESS 0x70CEu    /* 0650CE */
#define sprite_list_0650DA_ADDRESS 0x70DAu    /* 0650DA */
#define animation_0650E6_ADDRESS 0x70E6u    /* 0650E6 */
#define sprite_list_0650F2_ADDRESS 0x70F2u    /* 0650F2 */
#define sprite_list_0650FE_ADDRESS 0x70FEu    /* 0650FE */
#define animation_065110_ADDRESS 0x7110u    /* 065110 */
#define sprite_list_06511C_ADDRESS 0x711Cu    /* 06511C */
#define sprite_list_065128_ADDRESS 0x7128u    /* 065128 */
#define animation_065134_ADDRESS 0x7134u    /* 065134 */
#define sprite_list_06513C_ADDRESS 0x713Cu    /* 06513C */
#define animation_065142_ADDRESS 0x7142u    /* 065142 */
#define sprite_list_06514A_ADDRESS 0x714Au    /* 06514A */
#define animation_06515C_ADDRESS 0x715Cu    /* 06515C */
#define sprite_list_065178_ADDRESS 0x7178u    /* 065178 */
#define sprite_list_06518A_ADDRESS 0x718Au    /* 06518A */
#define sprite_list_06519C_ADDRESS 0x719Cu    /* 06519C */
#define sprite_list_0651AE_ADDRESS 0x71AEu    /* 0651AE */
#define sprite_list_0651C0_ADDRESS 0x71C0u    /* 0651C0 */
#define sprite_list_0651D2_ADDRESS 0x71D2u    /* 0651D2 */
#define animation_0651E4_ADDRESS 0x71E4u    /* 0651E4 */
#define sprite_list_0651EC_ADDRESS 0x71ECu    /* 0651EC */
#define animation_0651FE_ADDRESS 0x71FEu    /* 0651FE */
#define sprite_list_065206_ADDRESS 0x7206u    /* 065206 */
#define animation_065218_ADDRESS 0x7218u    /* 065218 */
#define sprite_list_065220_ADDRESS 0x7220u    /* 065220 */
#define animation_065232_ADDRESS 0x7232u    /* 065232 */
#define sprite_list_065242_ADDRESS 0x7242u    /* 065242 */
#define sprite_list_065254_ADDRESS 0x7254u    /* 065254 */
#define sprite_list_065266_ADDRESS 0x7266u    /* 065266 */
#define animation_06527E_ADDRESS 0x727Eu    /* 06527E */
#define sprite_list_06528E_ADDRESS 0x728Eu    /* 06528E */
#define sprite_list_0652A0_ADDRESS 0x72A0u    /* 0652A0 */
#define animation_0652B8_ADDRESS 0x72B8u    /* 0652B8 */
#define sprite_list_0652C4_ADDRESS 0x72C4u    /* 0652C4 */
#define sprite_list_0652CA_ADDRESS 0x72CAu    /* 0652CA */
#define animation_0652D6_ADDRESS 0x72D6u    /* 0652D6 */
#define sprite_list_0652DE_ADDRESS 0x72DEu    /* 0652DE */
#define animation_0652E4_ADDRESS 0x72E4u    /* 0652E4 */
#define sprite_list_0652F0_ADDRESS 0x72F0u    /* 0652F0 */
#define animation_0652FC_ADDRESS 0x72FCu    /* 0652FC */
#define sprite_list_065308_ADDRESS 0x7308u    /* 065308 */
#define sprite_list_06531A_ADDRESS 0x731Au    /* 06531A */
#define animation_06532C_ADDRESS 0x732Cu    /* 06532C */
#define sprite_list_065340_ADDRESS 0x7340u    /* 065340 */
#define sprite_list_06534C_ADDRESS 0x734Cu    /* 06534C */
#define sprite_list_065358_ADDRESS 0x7358u    /* 065358 */
#define sprite_list_065364_ADDRESS 0x7364u    /* 065364 */
#define animation_06536A_ADDRESS 0x736Au    /* 06536A */
#define sprite_list_06538E_ADDRESS 0x738Eu    /* 06538E */
#define sprite_list_0653A0_ADDRESS 0x73A0u    /* 0653A0 */
#define sprite_list_0653AC_ADDRESS 0x73ACu    /* 0653AC */
#define sprite_list_0653BE_ADDRESS 0x73BEu    /* 0653BE */
#define sprite_list_0653D0_ADDRESS 0x73D0u    /* 0653D0 */
#define sprite_list_0653DC_ADDRESS 0x73DCu    /* 0653DC */
#define sprite_list_0653E8_ADDRESS 0x73E8u    /* 0653E8 */
#define sprite_list_0653F4_ADDRESS 0x73F4u    /* 0653F4 */
#define animation_0653FA_ADDRESS 0x73FAu    /* 0653FA */
#define sprite_list_065402_ADDRESS 0x7402u    /* 065402 */
#define animation_06541A_ADDRESS 0x741Au    /* 06541A */
#define sprite_list_065436_ADDRESS 0x7436u    /* 065436 */
#define sprite_list_06544E_ADDRESS 0x744Eu    /* 06544E */
#define sprite_list_065466_ADDRESS 0x7466u    /* 065466 */
#define sprite_list_06547E_ADDRESS 0x747Eu    /* 06547E */
#define sprite_list_065496_ADDRESS 0x7496u    /* 065496 */
#define sprite_list_0654AE_ADDRESS 0x74AEu    /* 0654AE */
#define animation_0654C6_ADDRESS 0x74C6u    /* 0654C6 */
#define sprite_list_0654CE_ADDRESS 0x74CEu    /* 0654CE */
#define animation_0654E6_ADDRESS 0x74E6u    /* 0654E6 */
#define sprite_list_0654EE_ADDRESS 0x74EEu    /* 0654EE */
#define animation_065506_ADDRESS 0x7506u    /* 065506 */
#define sprite_list_06550E_ADDRESS 0x750Eu    /* 06550E */
#define animation_065526_ADDRESS 0x7526u    /* 065526 */
#define sprite_list_065536_ADDRESS 0x7536u    /* 065536 */
#define sprite_list_065548_ADDRESS 0x7548u    /* 065548 */
#define sprite_list_065560_ADDRESS 0x7560u    /* 065560 */
#define animation_065578_ADDRESS 0x7578u    /* 065578 */
#define sprite_list_065588_ADDRESS 0x7588u    /* 065588 */
#define sprite_list_06559A_ADDRESS 0x759Au    /* 06559A */
#define sprite_list_0655B2_ADDRESS 0x75B2u    /* 0655B2 */
#define animation_0655CA_ADDRESS 0x75CAu    /* 0655CA */
#define sprite_list_0655D2_ADDRESS 0x75D2u    /* 0655D2 */
#define animation_0655EA_ADDRESS 0x75EAu    /* 0655EA */
#define sprite_list_065606_ADDRESS 0x7606u    /* 065606 */
#define sprite_list_06561E_ADDRESS 0x761Eu    /* 06561E */
#define sprite_list_065636_ADDRESS 0x7636u    /* 065636 */
#define sprite_list_06564E_ADDRESS 0x764Eu    /* 06564E */
#define sprite_list_065666_ADDRESS 0x7666u    /* 065666 */
#define sprite_list_06567E_ADDRESS 0x767Eu    /* 06567E */
#define animation_065696_ADDRESS 0x7696u    /* 065696 */
#define sprite_list_06569E_ADDRESS 0x769Eu    /* 06569E */
#define animation_0656B6_ADDRESS 0x76B6u    /* 0656B6 */
#define sprite_list_0656BE_ADDRESS 0x76BEu    /* 0656BE */
#define animation_0656D6_ADDRESS 0x76D6u    /* 0656D6 */
#define sprite_list_0656E2_ADDRESS 0x76E2u    /* 0656E2 */
#define sprite_list_065700_ADDRESS 0x7700u    /* 065700 */
#define animation_06571E_ADDRESS 0x771Eu    /* 06571E */
#define sprite_list_065732_ADDRESS 0x7732u    /* 065732 */
#define sprite_list_06574A_ADDRESS 0x774Au    /* 06574A */
#define sprite_list_065762_ADDRESS 0x7762u    /* 065762 */
#define sprite_list_065774_ADDRESS 0x7774u    /* 065774 */
#define animation_065786_ADDRESS 0x7786u    /* 065786 */
#define sprite_list_06579A_ADDRESS 0x779Au    /* 06579A */
#define sprite_list_0657B2_ADDRESS 0x77B2u    /* 0657B2 */
#define sprite_list_0657C4_ADDRESS 0x77C4u    /* 0657C4 */
#define sprite_list_0657D6_ADDRESS 0x77D6u    /* 0657D6 */
#define animation_0657E8_ADDRESS 0x77E8u    /* 0657E8 */
#define sprite_list_0657F0_ADDRESS 0x77F0u    /* 0657F0 */
#define animation_0657FC_ADDRESS 0x77FCu    /* 0657FC */
#define sprite_list_065804_ADDRESS 0x7804u    /* 065804 */
#define animation_065810_ADDRESS 0x7810u    /* 065810 */
#define sprite_list_065818_ADDRESS 0x7818u    /* 065818 */
#define animation_065824_ADDRESS 0x7824u    /* 065824 */
#define sprite_list_06582C_ADDRESS 0x782Cu    /* 06582C */
#define animation_065838_ADDRESS 0x7838u    /* 065838 */
#define sprite_list_065840_ADDRESS 0x7840u    /* 065840 */
#define animation_06584C_ADDRESS 0x784Cu    /* 06584C */
#define sprite_list_065854_ADDRESS 0x7854u    /* 065854 */
#define animation_065860_ADDRESS 0x7860u    /* 065860 */
#define sprite_list_06586C_ADDRESS 0x786Cu    /* 06586C */
#define sprite_list_065878_ADDRESS 0x7878u    /* 065878 */
#define animation_065884_ADDRESS 0x7884u    /* 065884 */
#define sprite_list_065890_ADDRESS 0x7890u    /* 065890 */
#define sprite_list_06589C_ADDRESS 0x789Cu    /* 06589C */
#define animation_table_0658A2_ADDRESS 0x78A2u    /* 0658A2 */
#define animation_0658D2_ADDRESS 0x78D2u    /* 0658D2 */
#define sprite_list_0658DE_ADDRESS 0x78DEu    /* 0658DE */
#define sprite_list_0658F6_ADDRESS 0x78F6u    /* 0658F6 */
#define animation_06590E_ADDRESS 0x790Eu    /* 06590E */
#define sprite_list_065916_ADDRESS 0x7916u    /* 065916 */
#define animation_065928_ADDRESS 0x7928u    /* 065928 */
#define sprite_list_065938_ADDRESS 0x7938u    /* 065938 */
#define sprite_list_06594A_ADDRESS 0x794Au    /* 06594A */
#define sprite_list_06595C_ADDRESS 0x795Cu    /* 06595C */
#define animation_06596E_ADDRESS 0x796Eu    /* 06596E */
#define animation_065976_ADDRESS 0x7976u    /* 065976 */
#define sprite_list_06598A_ADDRESS 0x798Au    /* 06598A */
#define sprite_list_06599C_ADDRESS 0x799Cu    /* 06599C */
#define sprite_list_0659AE_ADDRESS 0x79AEu    /* 0659AE */
#define sprite_list_0659C0_ADDRESS 0x79C0u    /* 0659C0 */
#define sprite_list_0659D2_ADDRESS 0x79D2u    /* 0659D2 */
#define animation_0659E4_ADDRESS 0x79E4u    /* 0659E4 */
#define sprite_list_0659EC_ADDRESS 0x79ECu    /* 0659EC */
#define animation_0659F2_ADDRESS 0x79F2u    /* 0659F2 */
#define sprite_list_0659FA_ADDRESS 0x79FAu    /* 0659FA */
#define animation_065A06_ADDRESS 0x7A06u    /* 065A06 */
#define sprite_list_065A0E_ADDRESS 0x7A0Eu    /* 065A0E */
#define animation_065A1A_ADDRESS 0x7A1Au    /* 065A1A */
#define sprite_list_065A22_ADDRESS 0x7A22u    /* 065A22 */
#define animation_065A2E_ADDRESS 0x7A2Eu    /* 065A2E */
#define sprite_list_065A36_ADDRESS 0x7A36u    /* 065A36 */
#define animation_065A60_ADDRESS 0x7A60u    /* 065A60 */
#define sprite_list_065A68_ADDRESS 0x7A68u    /* 065A68 */
#define animation_065A92_ADDRESS 0x7A92u    /* 065A92 */
#define sprite_list_065A9A_ADDRESS 0x7A9Au    /* 065A9A */
#define animation_065AB8_ADDRESS 0x7AB8u    /* 065AB8 */
#define sprite_list_065AD0_ADDRESS 0x7AD0u    /* 065AD0 */
#define sprite_list_065AD6_ADDRESS 0x7AD6u    /* 065AD6 */
#define sprite_list_065ADC_ADDRESS 0x7ADCu    /* 065ADC */
#define sprite_list_065AE2_ADDRESS 0x7AE2u    /* 065AE2 */
#define sprite_list_065AE8_ADDRESS 0x7AE8u    /* 065AE8 */
#define animation_065AEE_ADDRESS 0x7AEEu    /* 065AEE */
#define sprite_list_065AF6_ADDRESS 0x7AF6u    /* 065AF6 */
#define animation_065AFC_ADDRESS 0x7AFCu    /* 065AFC */
#define sprite_list_065B04_ADDRESS 0x7B04u    /* 065B04 */
#define animation_065B10_ADDRESS 0x7B10u    /* 065B10 */
#define sprite_list_065B18_ADDRESS 0x7B18u    /* 065B18 */
#define animation_065B1E_ADDRESS 0x7B1Eu    /* 065B1E */
#define sprite_list_065B26_ADDRESS 0x7B26u    /* 065B26 */
#define animation_065B2C_ADDRESS 0x7B2Cu    /* 065B2C */
#define sprite_list_065B34_ADDRESS 0x7B34u    /* 065B34 */
#define animation_065B3A_ADDRESS 0x7B3Au    /* 065B3A */
#define sprite_list_065B42_ADDRESS 0x7B42u    /* 065B42 */
#define animation_065B48_ADDRESS 0x7B48u    /* 065B48 */
#define sprite_list_065B50_ADDRESS 0x7B50u    /* 065B50 */
#define animation_065B56_ADDRESS 0x7B56u    /* 065B56 */
#define sprite_list_065B5E_ADDRESS 0x7B5Eu    /* 065B5E */
#define animation_table_065B64_ADDRESS 0x7B64u    /* 065B64 */
#define animation_065B94_ADDRESS 0x7B94u    /* 065B94 */
#define sprite_list_065BA0_ADDRESS 0x7BA0u    /* 065BA0 */
#define sprite_list_065BB2_ADDRESS 0x7BB2u    /* 065BB2 */
#define animation_065BC4_ADDRESS 0x7BC4u    /* 065BC4 */
#define sprite_list_065BCC_ADDRESS 0x7BCCu    /* 065BCC */
#define animation_065BD8_ADDRESS 0x7BD8u    /* 065BD8 */
#define sprite_list_065BE8_ADDRESS 0x7BE8u    /* 065BE8 */
#define sprite_list_065BF4_ADDRESS 0x7BF4u    /* 065BF4 */
#define sprite_list_065C00_ADDRESS 0x7C00u    /* 065C00 */
#define animation_065C0C_ADDRESS 0x7C0Cu    /* 065C0C */
#define animation_065C14_ADDRESS 0x7C14u    /* 065C14 */
#define sprite_list_065C2C_ADDRESS 0x7C2Cu    /* 065C2C */
#define sprite_list_065C44_ADDRESS 0x7C44u    /* 065C44 */
#define sprite_list_065C5C_ADDRESS 0x7C5Cu    /* 065C5C */
#define sprite_list_065C74_ADDRESS 0x7C74u    /* 065C74 */
#define sprite_list_065C8C_ADDRESS 0x7C8Cu    /* 065C8C */
#define animation_065CA4_ADDRESS 0x7CA4u    /* 065CA4 */
#define sprite_list_065CAC_ADDRESS 0x7CACu    /* 065CAC */
#define animation_065CB2_ADDRESS 0x7CB2u    /* 065CB2 */
#define sprite_list_065CBA_ADDRESS 0x7CBAu    /* 065CBA */
#define animation_065CC0_ADDRESS 0x7CC0u    /* 065CC0 */
#define sprite_list_065CC8_ADDRESS 0x7CC8u    /* 065CC8 */
#define animation_065CE6_ADDRESS 0x7CE6u    /* 065CE6 */
#define sprite_list_065CEE_ADDRESS 0x7CEEu    /* 065CEE */
#define animation_065CFA_ADDRESS 0x7CFAu    /* 065CFA */
#define sprite_list_065D02_ADDRESS 0x7D02u    /* 065D02 */
#define animation_065D1A_ADDRESS 0x7D1Au    /* 065D1A */
#define sprite_list_065D2E_ADDRESS 0x7D2Eu    /* 065D2E */
#define sprite_list_065D46_ADDRESS 0x7D46u    /* 065D46 */
#define sprite_list_065D5E_ADDRESS 0x7D5Eu    /* 065D5E */
#define sprite_list_065D76_ADDRESS 0x7D76u    /* 065D76 */
#define animation_065D8E_ADDRESS 0x7D8Eu    /* 065D8E */
#define sprite_list_065D96_ADDRESS 0x7D96u    /* 065D96 */
#define animation_065DA8_ADDRESS 0x7DA8u    /* 065DA8 */
#define sprite_list_065DB0_ADDRESS 0x7DB0u    /* 065DB0 */
#define animation_065DB6_ADDRESS 0x7DB6u    /* 065DB6 */
#define sprite_list_065DBE_ADDRESS 0x7DBEu    /* 065DBE */
#define fill_065DCA_ADDRESS 0x7DCAu    /* 065DCA */
#define unreached_animation_065DDA_ADDRESS 0x7DDAu    /* 065DDA */
#define sprite_list_065DE2_ADDRESS 0x7DE2u    /* 065DE2 */
#define unreached_animation_065DE8_ADDRESS 0x7DE8u    /* 065DE8 */
#define sprite_list_065DF0_ADDRESS 0x7DF0u    /* 065DF0 */
#define unreached_animation_065DF6_ADDRESS 0x7DF6u    /* 065DF6 */
#define sprite_list_065DFE_ADDRESS 0x7DFEu    /* 065DFE */
#define unreached_animation_065E04_ADDRESS 0x7E04u    /* 065E04 */
#define sprite_list_065E0C_ADDRESS 0x7E0Cu    /* 065E0C */
#define unreached_animation_065E12_ADDRESS 0x7E12u    /* 065E12 */
#define sprite_list_065E2A_ADDRESS 0x7E2Au    /* 065E2A */
#define sprite_list_065E30_ADDRESS 0x7E30u    /* 065E30 */
#define sprite_list_065E36_ADDRESS 0x7E36u    /* 065E36 */
#define sprite_list_065E3C_ADDRESS 0x7E3Cu    /* 065E3C */
#define sprite_list_065E42_ADDRESS 0x7E42u    /* 065E42 */
#define unreached_animation_065E48_ADDRESS 0x7E48u    /* 065E48 */
#define sprite_list_065E5C_ADDRESS 0x7E5Cu    /* 065E5C */
#define sprite_list_065E62_ADDRESS 0x7E62u    /* 065E62 */
#define sprite_list_065E74_ADDRESS 0x7E74u    /* 065E74 */
#define sprite_list_065E8C_ADDRESS 0x7E8Cu    /* 065E8C */
#define unreached_animation_065EA4_ADDRESS 0x7EA4u    /* 065EA4 */
#define sprite_list_065EB0_ADDRESS 0x7EB0u    /* 065EB0 */
#define sprite_list_065EDA_ADDRESS 0x7EDAu    /* 065EDA */
#define unreached_animation_065F04_ADDRESS 0x7F04u    /* 065F04 */
#define sprite_list_065F0C_ADDRESS 0x7F0Cu    /* 065F0C */
#define unreached_animation_065F12_ADDRESS 0x7F12u    /* 065F12 */
#define sprite_list_065F1A_ADDRESS 0x7F1Au    /* 065F1A */
#define unreached_animation_065F38_ADDRESS 0x7F38u    /* 065F38 */
#define sprite_list_065F40_ADDRESS 0x7F40u    /* 065F40 */
#define unreached_animation_065F58_ADDRESS 0x7F58u    /* 065F58 */
#define sprite_list_065F60_ADDRESS 0x7F60u    /* 065F60 */
#define fill_065F6C_ADDRESS 0x7F6Cu    /* 065F6C */
#define unreached_animation_065F6E_ADDRESS 0x7F6Eu    /* 065F6E */
#define sprite_list_065F76_ADDRESS 0x7F76u    /* 065F76 */
#define unreached_animation_065F7C_ADDRESS 0x7F7Cu    /* 065F7C */
#define sprite_list_065F84_ADDRESS 0x7F84u    /* 065F84 */
#define unreached_animation_065F8A_ADDRESS 0x7F8Au    /* 065F8A */
#define sprite_list_065F92_ADDRESS 0x7F92u    /* 065F92 */
#define unreached_animation_065F9E_ADDRESS 0x7F9Eu    /* 065F9E */
#define sprite_list_065FAA_ADDRESS 0x7FAAu    /* 065FAA */
#define sprite_list_065FB0_ADDRESS 0x7FB0u    /* 065FB0 */
#define unreached_animation_065FB6_ADDRESS 0x7FB6u    /* 065FB6 */
#define sprite_list_065FBE_ADDRESS 0x7FBEu    /* 065FBE */
#define unreached_animation_065FC4_ADDRESS 0x7FC4u    /* 065FC4 */
#define sprite_list_065FCC_ADDRESS 0x7FCCu    /* 065FCC */
#define unreached_animation_065FD2_ADDRESS 0x7FD2u    /* 065FD2 */
#define sprite_list_065FDA_ADDRESS 0x7FDAu    /* 065FDA */
#define unreached_animation_065FE0_ADDRESS 0x7FE0u    /* 065FE0 */
#define sprite_list_065FE8_ADDRESS 0x7FE8u    /* 065FE8 */
#define fill_065FEE_ADDRESS 0x7FEEu    /* 065FEE */
#define set_index_066000_ADDRESS 0x6000u    /* 066000 */
#define animation_table_066006_ADDRESS 0x6006u    /* 066006 */
#define animation_066106_ADDRESS 0x6106u    /* 066106 */
#define sprite_list_06610E_ADDRESS 0x610Eu    /* 06610E */
#define animation_06611A_ADDRESS 0x611Au    /* 06611A */
#define sprite_list_066122_ADDRESS 0x6122u    /* 066122 */
#define animation_066128_ADDRESS 0x6128u    /* 066128 */
#define sprite_list_066130_ADDRESS 0x6130u    /* 066130 */
#define animation_066136_ADDRESS 0x6136u    /* 066136 */
#define sprite_list_06614E_ADDRESS 0x614Eu    /* 06614E */
#define sprite_list_066160_ADDRESS 0x6160u    /* 066160 */
#define sprite_list_06616C_ADDRESS 0x616Cu    /* 06616C */
#define sprite_list_06617E_ADDRESS 0x617Eu    /* 06617E */
#define sprite_list_066190_ADDRESS 0x6190u    /* 066190 */
#define animation_0661A8_ADDRESS 0x61A8u    /* 0661A8 */
#define sprite_list_0661CC_ADDRESS 0x61CCu    /* 0661CC */
#define sprite_list_0661E4_ADDRESS 0x61E4u    /* 0661E4 */
#define sprite_list_0661FC_ADDRESS 0x61FCu    /* 0661FC */
#define sprite_list_066214_ADDRESS 0x6214u    /* 066214 */
#define sprite_list_06622C_ADDRESS 0x622Cu    /* 06622C */
#define sprite_list_066244_ADDRESS 0x6244u    /* 066244 */
#define sprite_list_06625C_ADDRESS 0x625Cu    /* 06625C */
#define sprite_list_066274_ADDRESS 0x6274u    /* 066274 */
#define animation_06628C_ADDRESS 0x628Cu    /* 06628C */
#define animation_066294_ADDRESS 0x6294u    /* 066294 */
#define animation_0662B8_ADDRESS 0x62B8u    /* 0662B8 */
#define sprite_list_0662C0_ADDRESS 0x62C0u    /* 0662C0 */
#define animation_0662D8_ADDRESS 0x62D8u    /* 0662D8 */
#define sprite_list_0662E0_ADDRESS 0x62E0u    /* 0662E0 */
#define animation_0662F8_ADDRESS 0x62F8u    /* 0662F8 */
#define sprite_list_06630C_ADDRESS 0x630Cu    /* 06630C */
#define sprite_list_06631E_ADDRESS 0x631Eu    /* 06631E */
#define sprite_list_066330_ADDRESS 0x6330u    /* 066330 */
#define sprite_list_066348_ADDRESS 0x6348u    /* 066348 */
#define animation_066360_ADDRESS 0x6360u    /* 066360 */
#define sprite_list_066374_ADDRESS 0x6374u    /* 066374 */
#define sprite_list_066386_ADDRESS 0x6386u    /* 066386 */
#define sprite_list_066398_ADDRESS 0x6398u    /* 066398 */
#define sprite_list_0663B0_ADDRESS 0x63B0u    /* 0663B0 */
#define animation_0663C8_ADDRESS 0x63C8u    /* 0663C8 */
#define sprite_list_0663E0_ADDRESS 0x63E0u    /* 0663E0 */
#define sprite_list_0663F2_ADDRESS 0x63F2u    /* 0663F2 */
#define sprite_list_066404_ADDRESS 0x6404u    /* 066404 */
#define sprite_list_06641C_ADDRESS 0x641Cu    /* 06641C */
#define sprite_list_06642E_ADDRESS 0x642Eu    /* 06642E */
#define animation_066446_ADDRESS 0x6446u    /* 066446 */
#define animation_06644E_ADDRESS 0x644Eu    /* 06644E */
#define animation_066456_ADDRESS 0x6456u    /* 066456 */
#define sprite_list_06647A_ADDRESS 0x647Au    /* 06647A */
#define sprite_list_066492_ADDRESS 0x6492u    /* 066492 */
#define sprite_list_0664AA_ADDRESS 0x64AAu    /* 0664AA */
#define sprite_list_0664C2_ADDRESS 0x64C2u    /* 0664C2 */
#define sprite_list_0664DA_ADDRESS 0x64DAu    /* 0664DA */
#define sprite_list_0664F2_ADDRESS 0x64F2u    /* 0664F2 */
#define sprite_list_06650A_ADDRESS 0x650Au    /* 06650A */
#define sprite_list_066522_ADDRESS 0x6522u    /* 066522 */
#define animation_06653A_ADDRESS 0x653Au    /* 06653A */
#define sprite_list_066542_ADDRESS 0x6542u    /* 066542 */
#define animation_06655A_ADDRESS 0x655Au    /* 06655A */
#define sprite_list_066562_ADDRESS 0x6562u    /* 066562 */
#define animation_06657A_ADDRESS 0x657Au    /* 06657A */
#define sprite_list_066586_ADDRESS 0x6586u    /* 066586 */
#define sprite_list_06659E_ADDRESS 0x659Eu    /* 06659E */
#define animation_0665BC_ADDRESS 0x65BCu    /* 0665BC */
#define sprite_list_0665C8_ADDRESS 0x65C8u    /* 0665C8 */
#define sprite_list_0665DA_ADDRESS 0x65DAu    /* 0665DA */
#define animation_0665EC_ADDRESS 0x65ECu    /* 0665EC */
#define sprite_list_0665F8_ADDRESS 0x65F8u    /* 0665F8 */
#define animation_066610_ADDRESS 0x6610u    /* 066610 */
#define animation_06661C_ADDRESS 0x661Cu    /* 06661C */
#define sprite_list_066624_ADDRESS 0x6624u    /* 066624 */
#define animation_066636_ADDRESS 0x6636u    /* 066636 */
#define sprite_list_06665A_ADDRESS 0x665Au    /* 06665A */
#define sprite_list_06666C_ADDRESS 0x666Cu    /* 06666C */
#define sprite_list_06667E_ADDRESS 0x667Eu    /* 06667E */
#define sprite_list_066690_ADDRESS 0x6690u    /* 066690 */
#define sprite_list_0666A2_ADDRESS 0x66A2u    /* 0666A2 */
#define sprite_list_0666B4_ADDRESS 0x66B4u    /* 0666B4 */
#define sprite_list_0666C6_ADDRESS 0x66C6u    /* 0666C6 */
#define sprite_list_0666D8_ADDRESS 0x66D8u    /* 0666D8 */
#define animation_0666EA_ADDRESS 0x66EAu    /* 0666EA */
#define sprite_list_06670E_ADDRESS 0x670Eu    /* 06670E */
#define sprite_list_066714_ADDRESS 0x6714u    /* 066714 */
#define sprite_list_06671A_ADDRESS 0x671Au    /* 06671A */
#define sprite_list_066720_ADDRESS 0x6720u    /* 066720 */
#define sprite_list_066726_ADDRESS 0x6726u    /* 066726 */
#define sprite_list_06672C_ADDRESS 0x672Cu    /* 06672C */
#define sprite_list_066732_ADDRESS 0x6732u    /* 066732 */
#define sprite_list_066738_ADDRESS 0x6738u    /* 066738 */
#define animation_06673E_ADDRESS 0x673Eu    /* 06673E */
#define sprite_list_066746_ADDRESS 0x6746u    /* 066746 */
#define animation_06674C_ADDRESS 0x674Cu    /* 06674C */
#define sprite_list_066754_ADDRESS 0x6754u    /* 066754 */
#define animation_066766_ADDRESS 0x6766u    /* 066766 */
#define sprite_list_06676E_ADDRESS 0x676Eu    /* 06676E */
#define animation_066780_ADDRESS 0x6780u    /* 066780 */
#define sprite_list_0667A4_ADDRESS 0x67A4u    /* 0667A4 */
#define sprite_list_0667B6_ADDRESS 0x67B6u    /* 0667B6 */
#define sprite_list_0667C8_ADDRESS 0x67C8u    /* 0667C8 */
#define sprite_list_0667DA_ADDRESS 0x67DAu    /* 0667DA */
#define sprite_list_0667EC_ADDRESS 0x67ECu    /* 0667EC */
#define sprite_list_0667FE_ADDRESS 0x67FEu    /* 0667FE */
#define sprite_list_066810_ADDRESS 0x6810u    /* 066810 */
#define sprite_list_066822_ADDRESS 0x6822u    /* 066822 */
#define animation_066834_ADDRESS 0x6834u    /* 066834 */
#define sprite_list_06683C_ADDRESS 0x683Cu    /* 06683C */
#define animation_06684E_ADDRESS 0x684Eu    /* 06684E */
#define sprite_list_066856_ADDRESS 0x6856u    /* 066856 */
#define animation_066868_ADDRESS 0x6868u    /* 066868 */
#define sprite_list_066870_ADDRESS 0x6870u    /* 066870 */
#define animation_066882_ADDRESS 0x6882u    /* 066882 */
#define sprite_list_06688A_ADDRESS 0x688Au    /* 06688A */
#define animation_06689C_ADDRESS 0x689Cu    /* 06689C */
#define sprite_list_0668C0_ADDRESS 0x68C0u    /* 0668C0 */
#define sprite_list_0668D2_ADDRESS 0x68D2u    /* 0668D2 */
#define sprite_list_0668E4_ADDRESS 0x68E4u    /* 0668E4 */
#define sprite_list_0668F6_ADDRESS 0x68F6u    /* 0668F6 */
#define sprite_list_066908_ADDRESS 0x6908u    /* 066908 */
#define sprite_list_06691A_ADDRESS 0x691Au    /* 06691A */
#define sprite_list_06692C_ADDRESS 0x692Cu    /* 06692C */
#define sprite_list_06693E_ADDRESS 0x693Eu    /* 06693E */
#define animation_066950_ADDRESS 0x6950u    /* 066950 */
#define sprite_list_066958_ADDRESS 0x6958u    /* 066958 */
#define animation_06696A_ADDRESS 0x696Au    /* 06696A */
#define sprite_list_066972_ADDRESS 0x6972u    /* 066972 */
#define animation_066984_ADDRESS 0x6984u    /* 066984 */
#define sprite_list_06698C_ADDRESS 0x698Cu    /* 06698C */
#define animation_06699E_ADDRESS 0x699Eu    /* 06699E */
#define sprite_list_0669AA_ADDRESS 0x69AAu    /* 0669AA */
#define sprite_list_0669BC_ADDRESS 0x69BCu    /* 0669BC */
#define animation_0669CE_ADDRESS 0x69CEu    /* 0669CE */
#define sprite_list_0669DA_ADDRESS 0x69DAu    /* 0669DA */
#define animation_0669EC_ADDRESS 0x69ECu    /* 0669EC */
#define sprite_list_0669F8_ADDRESS 0x69F8u    /* 0669F8 */
#define animation_066A0A_ADDRESS 0x6A0Au    /* 066A0A */
#define sprite_list_066A26_ADDRESS 0x6A26u    /* 066A26 */
#define sprite_list_066A38_ADDRESS 0x6A38u    /* 066A38 */
#define sprite_list_066A4A_ADDRESS 0x6A4Au    /* 066A4A */
#define sprite_list_066A56_ADDRESS 0x6A56u    /* 066A56 */
#define animation_066A62_ADDRESS 0x6A62u    /* 066A62 */
#define sprite_list_066A6E_ADDRESS 0x6A6Eu    /* 066A6E */
#define sprite_list_066A80_ADDRESS 0x6A80u    /* 066A80 */
#define animation_066A92_ADDRESS 0x6A92u    /* 066A92 */
#define sprite_list_066A9E_ADDRESS 0x6A9Eu    /* 066A9E */
#define sprite_list_066AB0_ADDRESS 0x6AB0u    /* 066AB0 */
#define animation_066AC2_ADDRESS 0x6AC2u    /* 066AC2 */
#define sprite_list_066AD6_ADDRESS 0x6AD6u    /* 066AD6 */
#define sprite_list_066AE8_ADDRESS 0x6AE8u    /* 066AE8 */
#define sprite_list_066AFA_ADDRESS 0x6AFAu    /* 066AFA */
#define sprite_list_066B12_ADDRESS 0x6B12u    /* 066B12 */
#define animation_066B24_ADDRESS 0x6B24u    /* 066B24 */
#define sprite_list_066B34_ADDRESS 0x6B34u    /* 066B34 */
#define sprite_list_066B46_ADDRESS 0x6B46u    /* 066B46 */
#define sprite_list_066B58_ADDRESS 0x6B58u    /* 066B58 */
#define animation_066B6A_ADDRESS 0x6B6Au    /* 066B6A */
#define sprite_list_066B72_ADDRESS 0x6B72u    /* 066B72 */
#define animation_066B84_ADDRESS 0x6B84u    /* 066B84 */
#define sprite_list_066BA4_ADDRESS 0x6BA4u    /* 066BA4 */
#define sprite_list_066BB0_ADDRESS 0x6BB0u    /* 066BB0 */
#define sprite_list_066BBC_ADDRESS 0x6BBCu    /* 066BBC */
#define sprite_list_066BC8_ADDRESS 0x6BC8u    /* 066BC8 */
#define sprite_list_066BD4_ADDRESS 0x6BD4u    /* 066BD4 */
#define sprite_list_066BE0_ADDRESS 0x6BE0u    /* 066BE0 */
#define sprite_list_066BEC_ADDRESS 0x6BECu    /* 066BEC */
#define animation_066BF8_ADDRESS 0x6BF8u    /* 066BF8 */
#define sprite_list_066C28_ADDRESS 0x6C28u    /* 066C28 */
#define sprite_list_066C3A_ADDRESS 0x6C3Au    /* 066C3A */
#define sprite_list_066C4C_ADDRESS 0x6C4Cu    /* 066C4C */
#define sprite_list_066C5E_ADDRESS 0x6C5Eu    /* 066C5E */
#define animation_066C70_ADDRESS 0x6C70u    /* 066C70 */
#define sprite_list_066CAC_ADDRESS 0x6CACu    /* 066CAC */
#define sprite_list_066CBE_ADDRESS 0x6CBEu    /* 066CBE */
#define sprite_list_066CCA_ADDRESS 0x6CCAu    /* 066CCA */
#define sprite_list_066CD6_ADDRESS 0x6CD6u    /* 066CD6 */
#define sprite_list_066CE8_ADDRESS 0x6CE8u    /* 066CE8 */
#define sprite_list_066CFA_ADDRESS 0x6CFAu    /* 066CFA */
#define sprite_list_066D06_ADDRESS 0x6D06u    /* 066D06 */
#define sprite_list_066D12_ADDRESS 0x6D12u    /* 066D12 */
#define sprite_list_066D1E_ADDRESS 0x6D1Eu    /* 066D1E */
#define sprite_list_066D2A_ADDRESS 0x6D2Au    /* 066D2A */
#define sprite_list_066D36_ADDRESS 0x6D36u    /* 066D36 */
#define sprite_list_066D42_ADDRESS 0x6D42u    /* 066D42 */
#define animation_066D4E_ADDRESS 0x6D4Eu    /* 066D4E */
#define sprite_list_066D5A_ADDRESS 0x6D5Au    /* 066D5A */
#define sprite_list_066D66_ADDRESS 0x6D66u    /* 066D66 */
#define animation_066D72_ADDRESS 0x6D72u    /* 066D72 */
#define sprite_list_066D7E_ADDRESS 0x6D7Eu    /* 066D7E */
#define sprite_list_066D84_ADDRESS 0x6D84u    /* 066D84 */
#define animation_066D8A_ADDRESS 0x6D8Au    /* 066D8A */
#define sprite_list_066DA6_ADDRESS 0x6DA6u    /* 066DA6 */
#define sprite_list_066DAC_ADDRESS 0x6DACu    /* 066DAC */
#define sprite_list_066DB8_ADDRESS 0x6DB8u    /* 066DB8 */
#define sprite_list_066DC4_ADDRESS 0x6DC4u    /* 066DC4 */
#define sprite_list_066DCA_ADDRESS 0x6DCAu    /* 066DCA */
#define sprite_list_066DD6_ADDRESS 0x6DD6u    /* 066DD6 */
#define animation_066DE2_ADDRESS 0x6DE2u    /* 066DE2 */
#define sprite_list_066DF2_ADDRESS 0x6DF2u    /* 066DF2 */
#define sprite_list_066E04_ADDRESS 0x6E04u    /* 066E04 */
#define sprite_list_066E16_ADDRESS 0x6E16u    /* 066E16 */
#define animation_066E2E_ADDRESS 0x6E2Eu    /* 066E2E */
#define sprite_list_066E3A_ADDRESS 0x6E3Au    /* 066E3A */
#define sprite_list_066E4C_ADDRESS 0x6E4Cu    /* 066E4C */
#define animation_066E5E_ADDRESS 0x6E5Eu    /* 066E5E */
#define sprite_list_066E6A_ADDRESS 0x6E6Au    /* 066E6A */
#define sprite_list_066E7C_ADDRESS 0x6E7Cu    /* 066E7C */
#define animation_066E8E_ADDRESS 0x6E8Eu    /* 066E8E */
#define sprite_list_066E9A_ADDRESS 0x6E9Au    /* 066E9A */
#define sprite_list_066EAC_ADDRESS 0x6EACu    /* 066EAC */
#define animation_066EB8_ADDRESS 0x6EB8u    /* 066EB8 */
#define sprite_list_066ECC_ADDRESS 0x6ECCu    /* 066ECC */
#define sprite_list_066EDE_ADDRESS 0x6EDEu    /* 066EDE */
#define sprite_list_066EF0_ADDRESS 0x6EF0u    /* 066EF0 */
#define sprite_list_066F02_ADDRESS 0x6F02u    /* 066F02 */
#define animation_066F14_ADDRESS 0x6F14u    /* 066F14 */
#define sprite_list_066F28_ADDRESS 0x6F28u    /* 066F28 */
#define sprite_list_066F3A_ADDRESS 0x6F3Au    /* 066F3A */
#define sprite_list_066F46_ADDRESS 0x6F46u    /* 066F46 */
#define sprite_list_066F52_ADDRESS 0x6F52u    /* 066F52 */
#define animation_066F5E_ADDRESS 0x6F5Eu    /* 066F5E */
#define sprite_list_066F72_ADDRESS 0x6F72u    /* 066F72 */
#define sprite_list_066F8A_ADDRESS 0x6F8Au    /* 066F8A */
#define sprite_list_066F9C_ADDRESS 0x6F9Cu    /* 066F9C */
#define sprite_list_066FA8_ADDRESS 0x6FA8u    /* 066FA8 */
#define animation_066FB4_ADDRESS 0x6FB4u    /* 066FB4 */
#define sprite_list_066FC4_ADDRESS 0x6FC4u    /* 066FC4 */
#define sprite_list_066FD6_ADDRESS 0x6FD6u    /* 066FD6 */
#define sprite_list_066FE8_ADDRESS 0x6FE8u    /* 066FE8 */
#define animation_066FF4_ADDRESS 0x6FF4u    /* 066FF4 */
#define animation_066FFC_ADDRESS 0x6FFCu    /* 066FFC */
#define sprite_list_06700C_ADDRESS 0x700Cu    /* 06700C */
#define sprite_list_067018_ADDRESS 0x7018u    /* 067018 */
#define sprite_list_06702A_ADDRESS 0x702Au    /* 06702A */
#define animation_06703C_ADDRESS 0x703Cu    /* 06703C */
#define sprite_list_06704C_ADDRESS 0x704Cu    /* 06704C */
#define sprite_list_067058_ADDRESS 0x7058u    /* 067058 */
#define sprite_list_067064_ADDRESS 0x7064u    /* 067064 */
#define animation_067076_ADDRESS 0x7076u    /* 067076 */
#define sprite_list_06707E_ADDRESS 0x707Eu    /* 06707E */
#define animation_06708A_ADDRESS 0x708Au    /* 06708A */
#define sprite_list_0670AA_ADDRESS 0x70AAu    /* 0670AA */
#define sprite_list_0670BC_ADDRESS 0x70BCu    /* 0670BC */
#define sprite_list_0670C8_ADDRESS 0x70C8u    /* 0670C8 */
#define sprite_list_0670DA_ADDRESS 0x70DAu    /* 0670DA */
#define sprite_list_0670EC_ADDRESS 0x70ECu    /* 0670EC */
#define sprite_list_0670F8_ADDRESS 0x70F8u    /* 0670F8 */
#define sprite_list_067104_ADDRESS 0x7104u    /* 067104 */
#define animation_06711C_ADDRESS 0x711Cu    /* 06711C */
#define sprite_list_067130_ADDRESS 0x7130u    /* 067130 */
#define sprite_list_06713C_ADDRESS 0x713Cu    /* 06713C */
#define sprite_list_067148_ADDRESS 0x7148u    /* 067148 */
#define sprite_list_06714E_ADDRESS 0x714Eu    /* 06714E */
#define animation_067154_ADDRESS 0x7154u    /* 067154 */
#define sprite_list_067160_ADDRESS 0x7160u    /* 067160 */
#define animation_06716C_ADDRESS 0x716Cu    /* 06716C */
#define sprite_list_067180_ADDRESS 0x7180u    /* 067180 */
#define sprite_list_067192_ADDRESS 0x7192u    /* 067192 */
#define sprite_list_0671A4_ADDRESS 0x71A4u    /* 0671A4 */
#define sprite_list_0671B6_ADDRESS 0x71B6u    /* 0671B6 */
#define animation_0671C8_ADDRESS 0x71C8u    /* 0671C8 */
#define sprite_list_0671D4_ADDRESS 0x71D4u    /* 0671D4 */
#define sprite_list_0671DA_ADDRESS 0x71DAu    /* 0671DA */
#define animation_0671E0_ADDRESS 0x71E0u    /* 0671E0 */
#define sprite_list_0671F0_ADDRESS 0x71F0u    /* 0671F0 */
#define sprite_list_0671FC_ADDRESS 0x71FCu    /* 0671FC */
#define sprite_list_06720E_ADDRESS 0x720Eu    /* 06720E */
#define animation_06721A_ADDRESS 0x721Au    /* 06721A */
#define sprite_list_067226_ADDRESS 0x7226u    /* 067226 */
#define sprite_list_067238_ADDRESS 0x7238u    /* 067238 */
#define animation_06724A_ADDRESS 0x724Au    /* 06724A */
#define sprite_list_067256_ADDRESS 0x7256u    /* 067256 */
#define sprite_list_067268_ADDRESS 0x7268u    /* 067268 */
#define animation_067274_ADDRESS 0x7274u    /* 067274 */
#define sprite_list_067280_ADDRESS 0x7280u    /* 067280 */
#define sprite_list_067292_ADDRESS 0x7292u    /* 067292 */
#define animation_0672AA_ADDRESS 0x72AAu    /* 0672AA */
#define sprite_list_0672B6_ADDRESS 0x72B6u    /* 0672B6 */
#define sprite_list_0672C8_ADDRESS 0x72C8u    /* 0672C8 */
#define animation_0672DA_ADDRESS 0x72DAu    /* 0672DA */
#define sprite_list_0672FE_ADDRESS 0x72FEu    /* 0672FE */
#define sprite_list_067310_ADDRESS 0x7310u    /* 067310 */
#define sprite_list_067322_ADDRESS 0x7322u    /* 067322 */
#define sprite_list_067334_ADDRESS 0x7334u    /* 067334 */
#define sprite_list_067346_ADDRESS 0x7346u    /* 067346 */
#define sprite_list_067358_ADDRESS 0x7358u    /* 067358 */
#define sprite_list_06736A_ADDRESS 0x736Au    /* 06736A */
#define sprite_list_06737C_ADDRESS 0x737Cu    /* 06737C */
#define animation_06738E_ADDRESS 0x738Eu    /* 06738E */
#define sprite_list_067396_ADDRESS 0x7396u    /* 067396 */
#define animation_0673A8_ADDRESS 0x73A8u    /* 0673A8 */
#define sprite_list_0673B0_ADDRESS 0x73B0u    /* 0673B0 */
#define animation_0673C2_ADDRESS 0x73C2u    /* 0673C2 */
#define animation_0673CA_ADDRESS 0x73CAu    /* 0673CA */
#define sprite_list_0673DA_ADDRESS 0x73DAu    /* 0673DA */
#define sprite_list_0673EC_ADDRESS 0x73ECu    /* 0673EC */
#define sprite_list_0673FE_ADDRESS 0x73FEu    /* 0673FE */
#define animation_067410_ADDRESS 0x7410u    /* 067410 */
#define sprite_list_067420_ADDRESS 0x7420u    /* 067420 */
#define sprite_list_067432_ADDRESS 0x7432u    /* 067432 */
#define animation_067444_ADDRESS 0x7444u    /* 067444 */
#define sprite_list_06744C_ADDRESS 0x744Cu    /* 06744C */
#define animation_06745E_ADDRESS 0x745Eu    /* 06745E */
#define sprite_list_067482_ADDRESS 0x7482u    /* 067482 */
#define sprite_list_067494_ADDRESS 0x7494u    /* 067494 */
#define sprite_list_0674AC_ADDRESS 0x74ACu    /* 0674AC */
#define sprite_list_0674C4_ADDRESS 0x74C4u    /* 0674C4 */
#define sprite_list_0674D6_ADDRESS 0x74D6u    /* 0674D6 */
#define sprite_list_0674E8_ADDRESS 0x74E8u    /* 0674E8 */
#define sprite_list_067500_ADDRESS 0x7500u    /* 067500 */
#define sprite_list_067518_ADDRESS 0x7518u    /* 067518 */
#define animation_06752A_ADDRESS 0x752Au    /* 06752A */
#define sprite_list_067532_ADDRESS 0x7532u    /* 067532 */
#define animation_067544_ADDRESS 0x7544u    /* 067544 */
#define sprite_list_06754C_ADDRESS 0x754Cu    /* 06754C */
#define animation_067564_ADDRESS 0x7564u    /* 067564 */
#define sprite_list_067570_ADDRESS 0x7570u    /* 067570 */
#define animation_06758E_ADDRESS 0x758Eu    /* 06758E */
#define sprite_list_0675A2_ADDRESS 0x75A2u    /* 0675A2 */
#define sprite_list_0675BA_ADDRESS 0x75BAu    /* 0675BA */
#define sprite_list_0675CC_ADDRESS 0x75CCu    /* 0675CC */
#define sprite_list_0675DE_ADDRESS 0x75DEu    /* 0675DE */
#define animation_0675F0_ADDRESS 0x75F0u    /* 0675F0 */
#define sprite_list_067604_ADDRESS 0x7604u    /* 067604 */
#define sprite_list_06761C_ADDRESS 0x761Cu    /* 06761C */
#define sprite_list_06762E_ADDRESS 0x762Eu    /* 06762E */
#define sprite_list_067640_ADDRESS 0x7640u    /* 067640 */
#define animation_067652_ADDRESS 0x7652u    /* 067652 */
#define sprite_list_06765A_ADDRESS 0x765Au    /* 06765A */
#define animation_067660_ADDRESS 0x7660u    /* 067660 */
#define sprite_list_067668_ADDRESS 0x7668u    /* 067668 */
#define animation_067680_ADDRESS 0x7680u    /* 067680 */
#define sprite_list_0676A4_ADDRESS 0x76A4u    /* 0676A4 */
#define sprite_list_0676BC_ADDRESS 0x76BCu    /* 0676BC */
#define sprite_list_0676D4_ADDRESS 0x76D4u    /* 0676D4 */
#define sprite_list_0676EC_ADDRESS 0x76ECu    /* 0676EC */
#define sprite_list_067704_ADDRESS 0x7704u    /* 067704 */
#define sprite_list_06771C_ADDRESS 0x771Cu    /* 06771C */
#define sprite_list_067734_ADDRESS 0x7734u    /* 067734 */
#define sprite_list_06774C_ADDRESS 0x774Cu    /* 06774C */
#define animation_067764_ADDRESS 0x7764u    /* 067764 */
#define sprite_list_06776C_ADDRESS 0x776Cu    /* 06776C */
#define animation_067784_ADDRESS 0x7784u    /* 067784 */
#define sprite_list_06778C_ADDRESS 0x778Cu    /* 06778C */
#define animation_0677A4_ADDRESS 0x77A4u    /* 0677A4 */
#define animation_0677AC_ADDRESS 0x77ACu    /* 0677AC */
#define sprite_list_0677BC_ADDRESS 0x77BCu    /* 0677BC */
#define sprite_list_0677D4_ADDRESS 0x77D4u    /* 0677D4 */
#define sprite_list_0677E6_ADDRESS 0x77E6u    /* 0677E6 */
#define animation_0677F8_ADDRESS 0x77F8u    /* 0677F8 */
#define sprite_list_067808_ADDRESS 0x7808u    /* 067808 */
#define sprite_list_067820_ADDRESS 0x7820u    /* 067820 */
#define sprite_list_067832_ADDRESS 0x7832u    /* 067832 */
#define animation_067844_ADDRESS 0x7844u    /* 067844 */
#define sprite_list_067850_ADDRESS 0x7850u    /* 067850 */
#define sprite_list_06785C_ADDRESS 0x785Cu    /* 06785C */
#define animation_06786E_ADDRESS 0x786Eu    /* 06786E */
#define sprite_list_067876_ADDRESS 0x7876u    /* 067876 */
#define animation_06787C_ADDRESS 0x787Cu    /* 06787C */
#define sprite_list_067888_ADDRESS 0x7888u    /* 067888 */
#define animation_06788E_ADDRESS 0x788Eu    /* 06788E */
#define sprite_list_06789A_ADDRESS 0x789Au    /* 06789A */
#define sprite_list_0678AC_ADDRESS 0x78ACu    /* 0678AC */
#define animation_0678BE_ADDRESS 0x78BEu    /* 0678BE */
#define sprite_list_0678D2_ADDRESS 0x78D2u    /* 0678D2 */
#define sprite_list_0678EA_ADDRESS 0x78EAu    /* 0678EA */
#define sprite_list_0678FC_ADDRESS 0x78FCu    /* 0678FC */
#define sprite_list_067914_ADDRESS 0x7914u    /* 067914 */
#define animation_067932_ADDRESS 0x7932u    /* 067932 */
#define sprite_list_067956_ADDRESS 0x7956u    /* 067956 */
#define sprite_list_06796E_ADDRESS 0x796Eu    /* 06796E */
#define sprite_list_067986_ADDRESS 0x7986u    /* 067986 */
#define sprite_list_067992_ADDRESS 0x7992u    /* 067992 */
#define sprite_list_06799E_ADDRESS 0x799Eu    /* 06799E */
#define sprite_list_0679B6_ADDRESS 0x79B6u    /* 0679B6 */
#define sprite_list_0679C8_ADDRESS 0x79C8u    /* 0679C8 */
#define sprite_list_0679E0_ADDRESS 0x79E0u    /* 0679E0 */
#define animation_0679F8_ADDRESS 0x79F8u    /* 0679F8 */
#define sprite_list_067A04_ADDRESS 0x7A04u    /* 067A04 */
#define sprite_list_067A10_ADDRESS 0x7A10u    /* 067A10 */
#define animation_067A1C_ADDRESS 0x7A1Cu    /* 067A1C */
#define sprite_list_067A28_ADDRESS 0x7A28u    /* 067A28 */
#define sprite_list_067A34_ADDRESS 0x7A34u    /* 067A34 */
#define animation_table_067A3A_ADDRESS 0x7A3Au    /* 067A3A */
#define animation_067A6A_ADDRESS 0x7A6Au    /* 067A6A */
#define sprite_list_067A76_ADDRESS 0x7A76u    /* 067A76 */
#define sprite_list_067A88_ADDRESS 0x7A88u    /* 067A88 */
#define animation_067A9A_ADDRESS 0x7A9Au    /* 067A9A */
#define sprite_list_067AA2_ADDRESS 0x7AA2u    /* 067AA2 */
#define animation_067AAE_ADDRESS 0x7AAEu    /* 067AAE */
#define sprite_list_067ABE_ADDRESS 0x7ABEu    /* 067ABE */
#define sprite_list_067ACA_ADDRESS 0x7ACAu    /* 067ACA */
#define sprite_list_067AD6_ADDRESS 0x7AD6u    /* 067AD6 */
#define animation_067AE2_ADDRESS 0x7AE2u    /* 067AE2 */
#define animation_067AEA_ADDRESS 0x7AEAu    /* 067AEA */
#define sprite_list_067AFE_ADDRESS 0x7AFEu    /* 067AFE */
#define sprite_list_067B0A_ADDRESS 0x7B0Au    /* 067B0A */
#define sprite_list_067B16_ADDRESS 0x7B16u    /* 067B16 */
#define sprite_list_067B22_ADDRESS 0x7B22u    /* 067B22 */
#define animation_067B2E_ADDRESS 0x7B2Eu    /* 067B2E */
#define sprite_list_067B36_ADDRESS 0x7B36u    /* 067B36 */
#define animation_067B3C_ADDRESS 0x7B3Cu    /* 067B3C */
#define sprite_list_067B44_ADDRESS 0x7B44u    /* 067B44 */
#define animation_067B4A_ADDRESS 0x7B4Au    /* 067B4A */
#define sprite_list_067B52_ADDRESS 0x7B52u    /* 067B52 */
#define animation_067B5E_ADDRESS 0x7B5Eu    /* 067B5E */
#define sprite_list_067B66_ADDRESS 0x7B66u    /* 067B66 */
#define animation_067B72_ADDRESS 0x7B72u    /* 067B72 */
#define sprite_list_067B7A_ADDRESS 0x7B7Au    /* 067B7A */
#define animation_067B86_ADDRESS 0x7B86u    /* 067B86 */
#define sprite_list_067BA2_ADDRESS 0x7BA2u    /* 067BA2 */
#define sprite_list_067BC6_ADDRESS 0x7BC6u    /* 067BC6 */
#define sprite_list_067BEA_ADDRESS 0x7BEAu    /* 067BEA */
#define sprite_list_067C0E_ADDRESS 0x7C0Eu    /* 067C0E */
#define sprite_list_067C32_ADDRESS 0x7C32u    /* 067C32 */
#define sprite_list_067C56_ADDRESS 0x7C56u    /* 067C56 */
#define animation_067C7A_ADDRESS 0x7C7Au    /* 067C7A */
#define sprite_list_067C82_ADDRESS 0x7C82u    /* 067C82 */
#define animation_067C8E_ADDRESS 0x7C8Eu    /* 067C8E */
#define sprite_list_067CA6_ADDRESS 0x7CA6u    /* 067CA6 */
#define sprite_list_067CB2_ADDRESS 0x7CB2u    /* 067CB2 */
#define sprite_list_067CBE_ADDRESS 0x7CBEu    /* 067CBE */
#define sprite_list_067CCA_ADDRESS 0x7CCAu    /* 067CCA */
#define sprite_list_067CD6_ADDRESS 0x7CD6u    /* 067CD6 */
#define animation_067CE2_ADDRESS 0x7CE2u    /* 067CE2 */
#define sprite_list_067CEA_ADDRESS 0x7CEAu    /* 067CEA */
#define animation_067CF0_ADDRESS 0x7CF0u    /* 067CF0 */
#define sprite_list_067CF8_ADDRESS 0x7CF8u    /* 067CF8 */
#define animation_067D04_ADDRESS 0x7D04u    /* 067D04 */
#define sprite_list_067D0C_ADDRESS 0x7D0Cu    /* 067D0C */
#define animation_067D18_ADDRESS 0x7D18u    /* 067D18 */
#define sprite_list_067D20_ADDRESS 0x7D20u    /* 067D20 */
#define animation_067D2C_ADDRESS 0x7D2Cu    /* 067D2C */
#define sprite_list_067D34_ADDRESS 0x7D34u    /* 067D34 */
#define animation_067D40_ADDRESS 0x7D40u    /* 067D40 */
#define sprite_list_067D48_ADDRESS 0x7D48u    /* 067D48 */
#define animation_067D54_ADDRESS 0x7D54u    /* 067D54 */
#define sprite_list_067D5C_ADDRESS 0x7D5Cu    /* 067D5C */
#define animation_067D68_ADDRESS 0x7D68u    /* 067D68 */
#define sprite_list_067D70_ADDRESS 0x7D70u    /* 067D70 */
#define animation_table_067D7C_ADDRESS 0x7D7Cu    /* 067D7C */
#define animation_067DAC_ADDRESS 0x7DACu    /* 067DAC */
#define sprite_list_067DB8_ADDRESS 0x7DB8u    /* 067DB8 */
#define sprite_list_067DD0_ADDRESS 0x7DD0u    /* 067DD0 */
#define animation_067DE8_ADDRESS 0x7DE8u    /* 067DE8 */
#define sprite_list_067DF0_ADDRESS 0x7DF0u    /* 067DF0 */
#define animation_067DFC_ADDRESS 0x7DFCu    /* 067DFC */
#define sprite_list_067E0C_ADDRESS 0x7E0Cu    /* 067E0C */
#define sprite_list_067E18_ADDRESS 0x7E18u    /* 067E18 */
#define sprite_list_067E24_ADDRESS 0x7E24u    /* 067E24 */
#define animation_067E30_ADDRESS 0x7E30u    /* 067E30 */
#define animation_067E38_ADDRESS 0x7E38u    /* 067E38 */
#define sprite_list_067E4C_ADDRESS 0x7E4Cu    /* 067E4C */
#define sprite_list_067E64_ADDRESS 0x7E64u    /* 067E64 */
#define sprite_list_067E7C_ADDRESS 0x7E7Cu    /* 067E7C */
#define sprite_list_067E94_ADDRESS 0x7E94u    /* 067E94 */
#define animation_067EAC_ADDRESS 0x7EACu    /* 067EAC */
#define sprite_list_067EB4_ADDRESS 0x7EB4u    /* 067EB4 */
#define animation_067EBA_ADDRESS 0x7EBAu    /* 067EBA */
#define sprite_list_067EC2_ADDRESS 0x7EC2u    /* 067EC2 */
#define animation_067EC8_ADDRESS 0x7EC8u    /* 067EC8 */
#define sprite_list_067ED0_ADDRESS 0x7ED0u    /* 067ED0 */
#define animation_067EDC_ADDRESS 0x7EDCu    /* 067EDC */
#define sprite_list_067EE4_ADDRESS 0x7EE4u    /* 067EE4 */
#define animation_067EF0_ADDRESS 0x7EF0u    /* 067EF0 */
#define sprite_list_067EF8_ADDRESS 0x7EF8u    /* 067EF8 */
#define animation_067F04_ADDRESS 0x7F04u    /* 067F04 */
#define sprite_list_067F14_ADDRESS 0x7F14u    /* 067F14 */
#define sprite_list_067F20_ADDRESS 0x7F20u    /* 067F20 */
#define sprite_list_067F2C_ADDRESS 0x7F2Cu    /* 067F2C */
#define animation_067F38_ADDRESS 0x7F38u    /* 067F38 */
#define sprite_list_067F40_ADDRESS 0x7F40u    /* 067F40 */
#define animation_067F4C_ADDRESS 0x7F4Cu    /* 067F4C */
#define sprite_list_067F54_ADDRESS 0x7F54u    /* 067F54 */
#define animation_067F5A_ADDRESS 0x7F5Au    /* 067F5A */
#define sprite_list_067F62_ADDRESS 0x7F62u    /* 067F62 */
#define unreached_animation_067F6E_ADDRESS 0x7F6Eu    /* 067F6E */
#define sprite_list_067F76_ADDRESS 0x7F76u    /* 067F76 */
#define unreached_animation_067F7C_ADDRESS 0x7F7Cu    /* 067F7C */
#define sprite_list_067F84_ADDRESS 0x7F84u    /* 067F84 */
#define unreached_animation_067F8A_ADDRESS 0x7F8Au    /* 067F8A */
#define sprite_list_067F92_ADDRESS 0x7F92u    /* 067F92 */
#define unreached_animation_067F9E_ADDRESS 0x7F9Eu    /* 067F9E */
#define sprite_list_067FAA_ADDRESS 0x7FAAu    /* 067FAA */
#define sprite_list_067FB0_ADDRESS 0x7FB0u    /* 067FB0 */
#define unreached_animation_067FB6_ADDRESS 0x7FB6u    /* 067FB6 */
#define sprite_list_067FBE_ADDRESS 0x7FBEu    /* 067FBE */
#define unreached_animation_067FC4_ADDRESS 0x7FC4u    /* 067FC4 */
#define sprite_list_067FCC_ADDRESS 0x7FCCu    /* 067FCC */
#define unreached_animation_067FD2_ADDRESS 0x7FD2u    /* 067FD2 */
#define sprite_list_067FDA_ADDRESS 0x7FDAu    /* 067FDA */
#define unreached_animation_067FE0_ADDRESS 0x7FE0u    /* 067FE0 */
#define sprite_list_067FE8_ADDRESS 0x7FE8u    /* 067FE8 */
#define fill_067FEE_ADDRESS 0x7FEEu    /* 067FEE */
#define set_index_068000_ADDRESS 0x6000u    /* 068000 */
#define animation_table_068006_ADDRESS 0x6006u    /* 068006 */
#define animation_06809C_ADDRESS 0x609Cu    /* 06809C */
#define sprite_list_0680A4_ADDRESS 0x60A4u    /* 0680A4 */
#define animation_0680AA_ADDRESS 0x60AAu    /* 0680AA */
#define sprite_list_0680B2_ADDRESS 0x60B2u    /* 0680B2 */
#define animation_0680C4_ADDRESS 0x60C4u    /* 0680C4 */
#define sprite_list_0680D4_ADDRESS 0x60D4u    /* 0680D4 */
#define sprite_list_0680E6_ADDRESS 0x60E6u    /* 0680E6 */
#define sprite_list_0680F8_ADDRESS 0x60F8u    /* 0680F8 */
#define animation_06810A_ADDRESS 0x610Au    /* 06810A */
#define sprite_list_068112_ADDRESS 0x6112u    /* 068112 */
#define animation_068124_ADDRESS 0x6124u    /* 068124 */
#define sprite_list_06812C_ADDRESS 0x612Cu    /* 06812C */
#define animation_068132_ADDRESS 0x6132u    /* 068132 */
#define sprite_list_06813A_ADDRESS 0x613Au    /* 06813A */
#define animation_068146_ADDRESS 0x6146u    /* 068146 */
#define sprite_list_06814E_ADDRESS 0x614Eu    /* 06814E */
#define animation_068160_ADDRESS 0x6160u    /* 068160 */
#define sprite_list_068168_ADDRESS 0x6168u    /* 068168 */
#define animation_06816E_ADDRESS 0x616Eu    /* 06816E */
#define sprite_list_068176_ADDRESS 0x6176u    /* 068176 */
#define animation_06817C_ADDRESS 0x617Cu    /* 06817C */
#define sprite_list_06819C_ADDRESS 0x619Cu    /* 06819C */
#define sprite_list_0681A2_ADDRESS 0x61A2u    /* 0681A2 */
#define sprite_list_0681A8_ADDRESS 0x61A8u    /* 0681A8 */
#define sprite_list_0681AE_ADDRESS 0x61AEu    /* 0681AE */
#define sprite_list_0681BA_ADDRESS 0x61BAu    /* 0681BA */
#define sprite_list_0681C6_ADDRESS 0x61C6u    /* 0681C6 */
#define sprite_list_0681D2_ADDRESS 0x61D2u    /* 0681D2 */
#define animation_0681D8_ADDRESS 0x61D8u    /* 0681D8 */
#define sprite_list_0681E0_ADDRESS 0x61E0u    /* 0681E0 */
#define animation_0681E6_ADDRESS 0x61E6u    /* 0681E6 */
#define sprite_list_0681EE_ADDRESS 0x61EEu    /* 0681EE */
#define animation_0681FA_ADDRESS 0x61FAu    /* 0681FA */
#define sprite_list_068202_ADDRESS 0x6202u    /* 068202 */
#define animation_06820E_ADDRESS 0x620Eu    /* 06820E */
#define sprite_list_068216_ADDRESS 0x6216u    /* 068216 */
#define animation_068222_ADDRESS 0x6222u    /* 068222 */
#define sprite_list_06822A_ADDRESS 0x622Au    /* 06822A */
#define animation_068236_ADDRESS 0x6236u    /* 068236 */
#define sprite_list_06823E_ADDRESS 0x623Eu    /* 06823E */
#define animation_06824A_ADDRESS 0x624Au    /* 06824A */
#define sprite_list_068252_ADDRESS 0x6252u    /* 068252 */
#define animation_068282_ADDRESS 0x6282u    /* 068282 */
#define sprite_list_06828A_ADDRESS 0x628Au    /* 06828A */
#define animation_068290_ADDRESS 0x6290u    /* 068290 */
#define sprite_list_06829C_ADDRESS 0x629Cu    /* 06829C */
#define sprite_list_0682A8_ADDRESS 0x62A8u    /* 0682A8 */
#define animation_0682B4_ADDRESS 0x62B4u    /* 0682B4 */
#define sprite_list_0682C8_ADDRESS 0x62C8u    /* 0682C8 */
#define sprite_list_0682E6_ADDRESS 0x62E6u    /* 0682E6 */
#define sprite_list_0682FE_ADDRESS 0x62FEu    /* 0682FE */
#define sprite_list_068316_ADDRESS 0x6316u    /* 068316 */
#define animation_068346_ADDRESS 0x6346u    /* 068346 */
#define sprite_list_06835A_ADDRESS 0x635Au    /* 06835A */
#define sprite_list_068390_ADDRESS 0x6390u    /* 068390 */
#define sprite_list_0683C0_ADDRESS 0x63C0u    /* 0683C0 */
#define sprite_list_068408_ADDRESS 0x6408u    /* 068408 */
#define animation_068450_ADDRESS 0x6450u    /* 068450 */
#define sprite_list_068460_ADDRESS 0x6460u    /* 068460 */
#define sprite_list_068490_ADDRESS 0x6490u    /* 068490 */
#define animation_0684C0_ADDRESS 0x64C0u    /* 0684C0 */
#define animation_0684C8_ADDRESS 0x64C8u    /* 0684C8 */
#define animation_0684D0_ADDRESS 0x64D0u    /* 0684D0 */
#define animation_0684D8_ADDRESS 0x64D8u    /* 0684D8 */
#define sprite_list_0684E0_ADDRESS 0x64E0u    /* 0684E0 */
#define sprite_list_06852E_ADDRESS 0x652Eu    /* 06852E */
#define sprite_list_06854C_ADDRESS 0x654Cu    /* 06854C */
#define sprite_list_06858E_ADDRESS 0x658Eu    /* 06858E */
#define animation_0685B2_ADDRESS 0x65B2u    /* 0685B2 */
#define sprite_list_0685BA_ADDRESS 0x65BAu    /* 0685BA */
#define animation_0685C0_ADDRESS 0x65C0u    /* 0685C0 */
#define sprite_list_0685C8_ADDRESS 0x65C8u    /* 0685C8 */
#define animation_0685CE_ADDRESS 0x65CEu    /* 0685CE */
#define sprite_list_0685D6_ADDRESS 0x65D6u    /* 0685D6 */
#define animation_0685DC_ADDRESS 0x65DCu    /* 0685DC */
#define sprite_list_0685E4_ADDRESS 0x65E4u    /* 0685E4 */
#define animation_068614_ADDRESS 0x6614u    /* 068614 */
#define sprite_list_068624_ADDRESS 0x6624u    /* 068624 */
#define sprite_list_06863C_ADDRESS 0x663Cu    /* 06863C */
#define sprite_list_068678_ADDRESS 0x6678u    /* 068678 */
#define animation_068696_ADDRESS 0x6696u    /* 068696 */
#define sprite_list_06869E_ADDRESS 0x669Eu    /* 06869E */
#define animation_0686C2_ADDRESS 0x66C2u    /* 0686C2 */
#define sprite_list_0686CA_ADDRESS 0x66CAu    /* 0686CA */
#define animation_0686D0_ADDRESS 0x66D0u    /* 0686D0 */
#define sprite_list_0686D8_ADDRESS 0x66D8u    /* 0686D8 */
#define animation_06871A_ADDRESS 0x671Au    /* 06871A */
#define sprite_list_06873E_ADDRESS 0x673Eu    /* 06873E */
#define sprite_list_068744_ADDRESS 0x6744u    /* 068744 */
#define sprite_list_06874A_ADDRESS 0x674Au    /* 06874A */
#define sprite_list_068750_ADDRESS 0x6750u    /* 068750 */
#define sprite_list_068756_ADDRESS 0x6756u    /* 068756 */
#define sprite_list_068762_ADDRESS 0x6762u    /* 068762 */
#define sprite_list_068768_ADDRESS 0x6768u    /* 068768 */
#define sprite_list_06876E_ADDRESS 0x676Eu    /* 06876E */
#define animation_068774_ADDRESS 0x6774u    /* 068774 */
#define sprite_list_06877C_ADDRESS 0x677Cu    /* 06877C */
#define animation_068788_ADDRESS 0x6788u    /* 068788 */
#define sprite_list_068790_ADDRESS 0x6790u    /* 068790 */
#define animation_0687A8_ADDRESS 0x67A8u    /* 0687A8 */
#define sprite_list_0687D8_ADDRESS 0x67D8u    /* 0687D8 */
#define sprite_list_068814_ADDRESS 0x6814u    /* 068814 */
#define sprite_list_06884A_ADDRESS 0x684Au    /* 06884A */
#define sprite_list_06889E_ADDRESS 0x689Eu    /* 06889E */
#define sprite_list_0688F8_ADDRESS 0x68F8u    /* 0688F8 */
#define sprite_list_068952_ADDRESS 0x6952u    /* 068952 */
#define sprite_list_0689AC_ADDRESS 0x69ACu    /* 0689AC */
#define sprite_list_068A06_ADDRESS 0x6A06u    /* 068A06 */
#define sprite_list_068A60_ADDRESS 0x6A60u    /* 068A60 */
#define animation_068A7E_ADDRESS 0x6A7Eu    /* 068A7E */
#define sprite_list_068A86_ADDRESS 0x6A86u    /* 068A86 */
#define animation_068A92_ADDRESS 0x6A92u    /* 068A92 */
#define sprite_list_068AA2_ADDRESS 0x6AA2u    /* 068AA2 */
#define sprite_list_068AAE_ADDRESS 0x6AAEu    /* 068AAE */
#define sprite_list_068ABA_ADDRESS 0x6ABAu    /* 068ABA */
#define animation_068ACC_ADDRESS 0x6ACCu    /* 068ACC */
#define sprite_list_068AD8_ADDRESS 0x6AD8u    /* 068AD8 */
#define sprite_list_068AF0_ADDRESS 0x6AF0u    /* 068AF0 */
#define animation_068B02_ADDRESS 0x6B02u    /* 068B02 */
#define sprite_list_068B0A_ADDRESS 0x6B0Au    /* 068B0A */
#define animation_068B2E_ADDRESS 0x6B2Eu    /* 068B2E */
#define sprite_list_068B36_ADDRESS 0x6B36u    /* 068B36 */
#define animation_068B48_ADDRESS 0x6B48u    /* 068B48 */
#define sprite_list_068B50_ADDRESS 0x6B50u    /* 068B50 */
#define animation_068B5C_ADDRESS 0x6B5Cu    /* 068B5C */
#define sprite_list_068B64_ADDRESS 0x6B64u    /* 068B64 */
#define animation_068B7C_ADDRESS 0x6B7Cu    /* 068B7C */
#define sprite_list_068B84_ADDRESS 0x6B84u    /* 068B84 */
#define animation_068BA2_ADDRESS 0x6BA2u    /* 068BA2 */
#define sprite_list_068BAA_ADDRESS 0x6BAAu    /* 068BAA */
#define animation_068BFE_ADDRESS 0x6BFEu    /* 068BFE */
#define sprite_list_068C06_ADDRESS 0x6C06u    /* 068C06 */
#define animation_068C1E_ADDRESS 0x6C1Eu    /* 068C1E */
#define sprite_list_068C26_ADDRESS 0x6C26u    /* 068C26 */
#define animation_068C7A_ADDRESS 0x6C7Au    /* 068C7A */
#define sprite_list_068C82_ADDRESS 0x6C82u    /* 068C82 */
#define animation_068C88_ADDRESS 0x6C88u    /* 068C88 */
#define sprite_list_068C90_ADDRESS 0x6C90u    /* 068C90 */
#define animation_068C96_ADDRESS 0x6C96u    /* 068C96 */
#define sprite_list_068C9E_ADDRESS 0x6C9Eu    /* 068C9E */
#define animation_068CA4_ADDRESS 0x6CA4u    /* 068CA4 */
#define sprite_list_068CAC_ADDRESS 0x6CACu    /* 068CAC */
#define animation_068CB2_ADDRESS 0x6CB2u    /* 068CB2 */
#define sprite_list_068CBA_ADDRESS 0x6CBAu    /* 068CBA */
#define animation_068CC0_ADDRESS 0x6CC0u    /* 068CC0 */
#define sprite_list_068CC8_ADDRESS 0x6CC8u    /* 068CC8 */
#define animation_068CCE_ADDRESS 0x6CCEu    /* 068CCE */
#define sprite_list_068CD6_ADDRESS 0x6CD6u    /* 068CD6 */
#define animation_068CDC_ADDRESS 0x6CDCu    /* 068CDC */
#define sprite_list_068CE4_ADDRESS 0x6CE4u    /* 068CE4 */
#define animation_068CEA_ADDRESS 0x6CEAu    /* 068CEA */
#define sprite_list_068CF2_ADDRESS 0x6CF2u    /* 068CF2 */
#define animation_068CF8_ADDRESS 0x6CF8u    /* 068CF8 */
#define sprite_list_068D00_ADDRESS 0x6D00u    /* 068D00 */
#define animation_068D06_ADDRESS 0x6D06u    /* 068D06 */
#define sprite_list_068D12_ADDRESS 0x6D12u    /* 068D12 */
#define sprite_list_068D18_ADDRESS 0x6D18u    /* 068D18 */
#define animation_068D1E_ADDRESS 0x6D1Eu    /* 068D1E */
#define sprite_list_068D26_ADDRESS 0x6D26u    /* 068D26 */
#define animation_068D2C_ADDRESS 0x6D2Cu    /* 068D2C */
#define sprite_list_068D34_ADDRESS 0x6D34u    /* 068D34 */
#define animation_068D46_ADDRESS 0x6D46u    /* 068D46 */
#define sprite_list_068D4E_ADDRESS 0x6D4Eu    /* 068D4E */
#define animation_068D54_ADDRESS 0x6D54u    /* 068D54 */
#define sprite_list_068D78_ADDRESS 0x6D78u    /* 068D78 */
#define sprite_list_068D7E_ADDRESS 0x6D7Eu    /* 068D7E */
#define sprite_list_068D84_ADDRESS 0x6D84u    /* 068D84 */
#define sprite_list_068D8A_ADDRESS 0x6D8Au    /* 068D8A */
#define sprite_list_068D96_ADDRESS 0x6D96u    /* 068D96 */
#define sprite_list_068DA2_ADDRESS 0x6DA2u    /* 068DA2 */
#define sprite_list_068DAE_ADDRESS 0x6DAEu    /* 068DAE */
#define sprite_list_068DB4_ADDRESS 0x6DB4u    /* 068DB4 */
#define animation_068DBA_ADDRESS 0x6DBAu    /* 068DBA */
#define sprite_list_068DC2_ADDRESS 0x6DC2u    /* 068DC2 */
#define animation_068DC8_ADDRESS 0x6DC8u    /* 068DC8 */
#define sprite_list_068E0C_ADDRESS 0x6E0Cu    /* 068E0C */
#define sprite_list_068E1E_ADDRESS 0x6E1Eu    /* 068E1E */
#define sprite_list_068E36_ADDRESS 0x6E36u    /* 068E36 */
#define sprite_list_068E48_ADDRESS 0x6E48u    /* 068E48 */
#define sprite_list_068E60_ADDRESS 0x6E60u    /* 068E60 */
#define sprite_list_068E78_ADDRESS 0x6E78u    /* 068E78 */
#define sprite_list_068E8A_ADDRESS 0x6E8Au    /* 068E8A */
#define sprite_list_068EA2_ADDRESS 0x6EA2u    /* 068EA2 */
#define sprite_list_068EBA_ADDRESS 0x6EBAu    /* 068EBA */
#define sprite_list_068ECC_ADDRESS 0x6ECCu    /* 068ECC */
#define animation_068EE4_ADDRESS 0x6EE4u    /* 068EE4 */
#define sprite_list_068EEC_ADDRESS 0x6EECu    /* 068EEC */
#define animation_068EF8_ADDRESS 0x6EF8u    /* 068EF8 */
#define sprite_list_068F00_ADDRESS 0x6F00u    /* 068F00 */
#define animation_068F12_ADDRESS 0x6F12u    /* 068F12 */
#define sprite_list_068F1A_ADDRESS 0x6F1Au    /* 068F1A */
#define animation_table_068F2C_ADDRESS 0x6F2Cu    /* 068F2C */
#define animation_068F82_ADDRESS 0x6F82u    /* 068F82 */
#define sprite_list_068F8A_ADDRESS 0x6F8Au    /* 068F8A */
#define animation_068FA8_ADDRESS 0x6FA8u    /* 068FA8 */
#define sprite_list_068FB0_ADDRESS 0x6FB0u    /* 068FB0 */
#define animation_068FC2_ADDRESS 0x6FC2u    /* 068FC2 */
#define sprite_list_068FCA_ADDRESS 0x6FCAu    /* 068FCA */
#define animation_068FD0_ADDRESS 0x6FD0u    /* 068FD0 */
#define sprite_list_068FD8_ADDRESS 0x6FD8u    /* 068FD8 */
#define animation_068FE4_ADDRESS 0x6FE4u    /* 068FE4 */
#define sprite_list_068FEC_ADDRESS 0x6FECu    /* 068FEC */
#define animation_068FFE_ADDRESS 0x6FFEu    /* 068FFE */
#define sprite_list_06900A_ADDRESS 0x700Au    /* 06900A */
#define sprite_list_06901C_ADDRESS 0x701Cu    /* 06901C */
#define animation_06902E_ADDRESS 0x702Eu    /* 06902E */
#define sprite_list_069036_ADDRESS 0x7036u    /* 069036 */
#define animation_069042_ADDRESS 0x7042u    /* 069042 */
#define sprite_list_06904E_ADDRESS 0x704Eu    /* 06904E */
#define sprite_list_069066_ADDRESS 0x7066u    /* 069066 */
#define animation_06907E_ADDRESS 0x707Eu    /* 06907E */
#define sprite_list_06908A_ADDRESS 0x708Au    /* 06908A */
#define sprite_list_0690A2_ADDRESS 0x70A2u    /* 0690A2 */
#define animation_0690BA_ADDRESS 0x70BAu    /* 0690BA */
#define sprite_list_0690C2_ADDRESS 0x70C2u    /* 0690C2 */
#define animation_0690CE_ADDRESS 0x70CEu    /* 0690CE */
#define sprite_list_0690DA_ADDRESS 0x70DAu    /* 0690DA */
#define sprite_list_0690EC_ADDRESS 0x70ECu    /* 0690EC */
#define animation_0690FE_ADDRESS 0x70FEu    /* 0690FE */
#define sprite_list_06910A_ADDRESS 0x710Au    /* 06910A */
#define sprite_list_06911C_ADDRESS 0x711Cu    /* 06911C */
#define animation_06912E_ADDRESS 0x712Eu    /* 06912E */
#define sprite_list_06913A_ADDRESS 0x713Au    /* 06913A */
#define sprite_list_069152_ADDRESS 0x7152u    /* 069152 */
#define animation_06916A_ADDRESS 0x716Au    /* 06916A */
#define sprite_list_069176_ADDRESS 0x7176u    /* 069176 */
#define sprite_list_06918E_ADDRESS 0x718Eu    /* 06918E */
#define animation_0691A6_ADDRESS 0x71A6u    /* 0691A6 */
#define sprite_list_0691AE_ADDRESS 0x71AEu    /* 0691AE */
#define animation_0691BA_ADDRESS 0x71BAu    /* 0691BA */
#define sprite_list_0691C6_ADDRESS 0x71C6u    /* 0691C6 */
#define sprite_list_0691D2_ADDRESS 0x71D2u    /* 0691D2 */
#define animation_0691DE_ADDRESS 0x71DEu    /* 0691DE */
#define sprite_list_0691EA_ADDRESS 0x71EAu    /* 0691EA */
#define sprite_list_0691F6_ADDRESS 0x71F6u    /* 0691F6 */
#define animation_069202_ADDRESS 0x7202u    /* 069202 */
#define sprite_list_06920A_ADDRESS 0x720Au    /* 06920A */
#define animation_069252_ADDRESS 0x7252u    /* 069252 */
#define sprite_list_06925A_ADDRESS 0x725Au    /* 06925A */
#define animation_0692A8_ADDRESS 0x72A8u    /* 0692A8 */
#define sprite_list_0692B0_ADDRESS 0x72B0u    /* 0692B0 */
#define animation_0692E0_ADDRESS 0x72E0u    /* 0692E0 */
#define sprite_list_0692E8_ADDRESS 0x72E8u    /* 0692E8 */
#define animation_0692F4_ADDRESS 0x72F4u    /* 0692F4 */
#define sprite_list_069308_ADDRESS 0x7308u    /* 069308 */
#define sprite_list_069338_ADDRESS 0x7338u    /* 069338 */
#define sprite_list_069368_ADDRESS 0x7368u    /* 069368 */
#define sprite_list_069398_ADDRESS 0x7398u    /* 069398 */
#define animation_0693BC_ADDRESS 0x73BCu    /* 0693BC */
#define sprite_list_0693C4_ADDRESS 0x73C4u    /* 0693C4 */
#define animation_0693DC_ADDRESS 0x73DCu    /* 0693DC */
#define sprite_list_0693E4_ADDRESS 0x73E4u    /* 0693E4 */
#define animation_06942C_ADDRESS 0x742Cu    /* 06942C */
#define sprite_list_069434_ADDRESS 0x7434u    /* 069434 */
#define animation_06943A_ADDRESS 0x743Au    /* 06943A */
#define sprite_list_069442_ADDRESS 0x7442u    /* 069442 */
#define animation_06944E_ADDRESS 0x744Eu    /* 06944E */
#define sprite_list_069456_ADDRESS 0x7456u    /* 069456 */
#define animation_069462_ADDRESS 0x7462u    /* 069462 */
#define sprite_list_06946A_ADDRESS 0x746Au    /* 06946A */
#define animation_069476_ADDRESS 0x7476u    /* 069476 */
#define sprite_list_06947E_ADDRESS 0x747Eu    /* 06947E */
#define animation_069490_ADDRESS 0x7490u    /* 069490 */
#define sprite_list_069498_ADDRESS 0x7498u    /* 069498 */
#define animation_0694B0_ADDRESS 0x74B0u    /* 0694B0 */
#define sprite_list_0694B8_ADDRESS 0x74B8u    /* 0694B8 */
#define animation_0694D6_ADDRESS 0x74D6u    /* 0694D6 */
#define sprite_list_0694E2_ADDRESS 0x74E2u    /* 0694E2 */
#define sprite_list_0694E8_ADDRESS 0x74E8u    /* 0694E8 */
#define animation_0694EE_ADDRESS 0x74EEu    /* 0694EE */
#define sprite_list_0694FE_ADDRESS 0x74FEu    /* 0694FE */
#define sprite_list_06950A_ADDRESS 0x750Au    /* 06950A */
#define sprite_list_06951C_ADDRESS 0x751Cu    /* 06951C */
#define animation_069534_ADDRESS 0x7534u    /* 069534 */
#define sprite_list_069540_ADDRESS 0x7540u    /* 069540 */
#define animation_069558_ADDRESS 0x7558u    /* 069558 */
#define sprite_list_069560_ADDRESS 0x7560u    /* 069560 */
#define animation_0695A2_ADDRESS 0x75A2u    /* 0695A2 */
#define sprite_list_0695C6_ADDRESS 0x75C6u    /* 0695C6 */
#define sprite_list_0695D2_ADDRESS 0x75D2u    /* 0695D2 */
#define sprite_list_0695DE_ADDRESS 0x75DEu    /* 0695DE */
#define sprite_list_0695EA_ADDRESS 0x75EAu    /* 0695EA */
#define sprite_list_0695F6_ADDRESS 0x75F6u    /* 0695F6 */
#define sprite_list_069602_ADDRESS 0x7602u    /* 069602 */
#define sprite_list_06961A_ADDRESS 0x761Au    /* 06961A */
#define sprite_list_069626_ADDRESS 0x7626u    /* 069626 */
#define animation_069632_ADDRESS 0x7632u    /* 069632 */
#define animation_069656_ADDRESS 0x7656u    /* 069656 */
#define animation_06965E_ADDRESS 0x765Eu    /* 06965E */
#define sprite_list_069672_ADDRESS 0x7672u    /* 069672 */
#define sprite_list_069678_ADDRESS 0x7678u    /* 069678 */
#define animation_06967E_ADDRESS 0x767Eu    /* 06967E */
#define sprite_list_069692_ADDRESS 0x7692u    /* 069692 */
#define sprite_list_0696AA_ADDRESS 0x76AAu    /* 0696AA */
#define sprite_list_0696C2_ADDRESS 0x76C2u    /* 0696C2 */
#define sprite_list_0696DA_ADDRESS 0x76DAu    /* 0696DA */
#define animation_069704_ADDRESS 0x7704u    /* 069704 */
#define sprite_list_069710_ADDRESS 0x7710u    /* 069710 */
#define animation_06973A_ADDRESS 0x773Au    /* 06973A */
#define sprite_list_069746_ADDRESS 0x7746u    /* 069746 */
#define sprite_list_069770_ADDRESS 0x7770u    /* 069770 */
#define animation_0697A0_ADDRESS 0x77A0u    /* 0697A0 */
#define animation_table_0697B0_ADDRESS 0x77B0u    /* 0697B0 */
#define animation_0697F6_ADDRESS 0x77F6u    /* 0697F6 */
#define sprite_list_0697FE_ADDRESS 0x77FEu    /* 0697FE */
#define animation_069828_ADDRESS 0x7828u    /* 069828 */
#define sprite_list_069830_ADDRESS 0x7830u    /* 069830 */
#define animation_06985A_ADDRESS 0x785Au    /* 06985A */
#define sprite_list_069862_ADDRESS 0x7862u    /* 069862 */
#define animation_069892_ADDRESS 0x7892u    /* 069892 */
#define sprite_list_06989A_ADDRESS 0x789Au    /* 06989A */
#define animation_0698CA_ADDRESS 0x78CAu    /* 0698CA */
#define sprite_list_0698F2_ADDRESS 0x78F2u    /* 0698F2 */
#define sprite_list_069928_ADDRESS 0x7928u    /* 069928 */
#define sprite_list_069952_ADDRESS 0x7952u    /* 069952 */
#define sprite_list_06998E_ADDRESS 0x798Eu    /* 06998E */
#define sprite_list_0699CA_ADDRESS 0x79CAu    /* 0699CA */
#define sprite_list_0699E8_ADDRESS 0x79E8u    /* 0699E8 */
#define sprite_list_0699FA_ADDRESS 0x79FAu    /* 0699FA */
#define sprite_list_069A0C_ADDRESS 0x7A0Cu    /* 069A0C */
#define sprite_list_069A1E_ADDRESS 0x7A1Eu    /* 069A1E */
#define animation_069A30_ADDRESS 0x7A30u    /* 069A30 */
#define sprite_list_069A44_ADDRESS 0x7A44u    /* 069A44 */
#define sprite_list_069A68_ADDRESS 0x7A68u    /* 069A68 */
#define sprite_list_069A8C_ADDRESS 0x7A8Cu    /* 069A8C */
#define sprite_list_069AB0_ADDRESS 0x7AB0u    /* 069AB0 */
#define animation_069AD4_ADDRESS 0x7AD4u    /* 069AD4 */
#define sprite_list_069ADC_ADDRESS 0x7ADCu    /* 069ADC */
#define animation_069AE2_ADDRESS 0x7AE2u    /* 069AE2 */
#define sprite_list_069AEA_ADDRESS 0x7AEAu    /* 069AEA */
#define animation_069B32_ADDRESS 0x7B32u    /* 069B32 */
#define sprite_list_069B3A_ADDRESS 0x7B3Au    /* 069B3A */
#define animation_069B64_ADDRESS 0x7B64u    /* 069B64 */
#define sprite_list_069B6C_ADDRESS 0x7B6Cu    /* 069B6C */
#define animation_069B72_ADDRESS 0x7B72u    /* 069B72 */
#define sprite_list_069B7A_ADDRESS 0x7B7Au    /* 069B7A */
#define animation_069B92_ADDRESS 0x7B92u    /* 069B92 */
#define sprite_list_069B9A_ADDRESS 0x7B9Au    /* 069B9A */
#define animation_069BEE_ADDRESS 0x7BEEu    /* 069BEE */
#define sprite_list_069BF6_ADDRESS 0x7BF6u    /* 069BF6 */
#define animation_069C32_ADDRESS 0x7C32u    /* 069C32 */
#define sprite_list_069C3A_ADDRESS 0x7C3Au    /* 069C3A */
#define animation_069C6A_ADDRESS 0x7C6Au    /* 069C6A */
#define sprite_list_069C72_ADDRESS 0x7C72u    /* 069C72 */
#define animation_069C96_ADDRESS 0x7C96u    /* 069C96 */
#define sprite_list_069C9E_ADDRESS 0x7C9Eu    /* 069C9E */
#define animation_069CBC_ADDRESS 0x7CBCu    /* 069CBC */
#define sprite_list_069CC4_ADDRESS 0x7CC4u    /* 069CC4 */
#define animation_069CEE_ADDRESS 0x7CEEu    /* 069CEE */
#define sprite_list_069CF6_ADDRESS 0x7CF6u    /* 069CF6 */
#define animation_069CFC_ADDRESS 0x7CFCu    /* 069CFC */
#define sprite_list_069D08_ADDRESS 0x7D08u    /* 069D08 */
#define sprite_list_069D1A_ADDRESS 0x7D1Au    /* 069D1A */
#define animation_069D2C_ADDRESS 0x7D2Cu    /* 069D2C */
#define sprite_list_069D34_ADDRESS 0x7D34u    /* 069D34 */
#define animation_069D40_ADDRESS 0x7D40u    /* 069D40 */
#define sprite_list_069D48_ADDRESS 0x7D48u    /* 069D48 */
#define animation_069D4E_ADDRESS 0x7D4Eu    /* 069D4E */
#define sprite_list_069D6E_ADDRESS 0x7D6Eu    /* 069D6E */
#define sprite_list_069D7A_ADDRESS 0x7D7Au    /* 069D7A */
#define sprite_list_069D8C_ADDRESS 0x7D8Cu    /* 069D8C */
#define sprite_list_069D98_ADDRESS 0x7D98u    /* 069D98 */
#define sprite_list_069DB6_ADDRESS 0x7DB6u    /* 069DB6 */
#define sprite_list_069DC8_ADDRESS 0x7DC8u    /* 069DC8 */
#define sprite_list_069DCE_ADDRESS 0x7DCEu    /* 069DCE */
#define animation_069DDA_ADDRESS 0x7DDAu    /* 069DDA */
#define sprite_list_069DE2_ADDRESS 0x7DE2u    /* 069DE2 */
#define animation_069DE8_ADDRESS 0x7DE8u    /* 069DE8 */
#define sprite_list_069DF0_ADDRESS 0x7DF0u    /* 069DF0 */
#define animation_069DF6_ADDRESS 0x7DF6u    /* 069DF6 */
#define sprite_list_069DFE_ADDRESS 0x7DFEu    /* 069DFE */
#define animation_069E04_ADDRESS 0x7E04u    /* 069E04 */
#define sprite_list_069E0C_ADDRESS 0x7E0Cu    /* 069E0C */
#define animation_069E12_ADDRESS 0x7E12u    /* 069E12 */
#define sprite_list_069E2A_ADDRESS 0x7E2Au    /* 069E2A */
#define sprite_list_069E30_ADDRESS 0x7E30u    /* 069E30 */
#define sprite_list_069E36_ADDRESS 0x7E36u    /* 069E36 */
#define sprite_list_069E3C_ADDRESS 0x7E3Cu    /* 069E3C */
#define sprite_list_069E42_ADDRESS 0x7E42u    /* 069E42 */
#define animation_069E48_ADDRESS 0x7E48u    /* 069E48 */
#define sprite_list_069E5C_ADDRESS 0x7E5Cu    /* 069E5C */
#define sprite_list_069E62_ADDRESS 0x7E62u    /* 069E62 */
#define sprite_list_069E74_ADDRESS 0x7E74u    /* 069E74 */
#define sprite_list_069E8C_ADDRESS 0x7E8Cu    /* 069E8C */
#define animation_069EA4_ADDRESS 0x7EA4u    /* 069EA4 */
#define sprite_list_069EB0_ADDRESS 0x7EB0u    /* 069EB0 */
#define sprite_list_069EDA_ADDRESS 0x7EDAu    /* 069EDA */
#define animation_069F04_ADDRESS 0x7F04u    /* 069F04 */
#define sprite_list_069F0C_ADDRESS 0x7F0Cu    /* 069F0C */
#define animation_069F12_ADDRESS 0x7F12u    /* 069F12 */
#define sprite_list_069F1A_ADDRESS 0x7F1Au    /* 069F1A */
#define animation_069F38_ADDRESS 0x7F38u    /* 069F38 */
#define sprite_list_069F40_ADDRESS 0x7F40u    /* 069F40 */
#define animation_069F58_ADDRESS 0x7F58u    /* 069F58 */
#define sprite_list_069F60_ADDRESS 0x7F60u    /* 069F60 */
#define fill_069F6C_ADDRESS 0x7F6Cu    /* 069F6C */
#define unreached_animation_069F6E_ADDRESS 0x7F6Eu    /* 069F6E */
#define sprite_list_069F76_ADDRESS 0x7F76u    /* 069F76 */
#define unreached_animation_069F7C_ADDRESS 0x7F7Cu    /* 069F7C */
#define sprite_list_069F84_ADDRESS 0x7F84u    /* 069F84 */
#define unreached_animation_069F8A_ADDRESS 0x7F8Au    /* 069F8A */
#define sprite_list_069F92_ADDRESS 0x7F92u    /* 069F92 */
#define unreached_animation_069F9E_ADDRESS 0x7F9Eu    /* 069F9E */
#define sprite_list_069FAA_ADDRESS 0x7FAAu    /* 069FAA */
#define sprite_list_069FB0_ADDRESS 0x7FB0u    /* 069FB0 */
#define unreached_animation_069FB6_ADDRESS 0x7FB6u    /* 069FB6 */
#define sprite_list_069FBE_ADDRESS 0x7FBEu    /* 069FBE */
#define unreached_animation_069FC4_ADDRESS 0x7FC4u    /* 069FC4 */
#define sprite_list_069FCC_ADDRESS 0x7FCCu    /* 069FCC */
#define unreached_animation_069FD2_ADDRESS 0x7FD2u    /* 069FD2 */
#define sprite_list_069FDA_ADDRESS 0x7FDAu    /* 069FDA */
#define unreached_animation_069FE0_ADDRESS 0x7FE0u    /* 069FE0 */
#define sprite_list_069FE8_ADDRESS 0x7FE8u    /* 069FE8 */
#define fill_069FEE_ADDRESS 0x7FEEu    /* 069FEE */
#define set_index_06A000_ADDRESS 0x6000u    /* 06A000 */
#define animation_table_06A004_ADDRESS 0x6004u    /* 06A004 */
#define animation_06A04E_ADDRESS 0x604Eu    /* 06A04E */
#define sprite_list_06A056_ADDRESS 0x6056u    /* 06A056 */
#define animation_06A068_ADDRESS 0x6068u    /* 06A068 */
#define sprite_list_06A08C_ADDRESS 0x608Cu    /* 06A08C */
#define sprite_list_06A0AA_ADDRESS 0x60AAu    /* 06A0AA */
#define sprite_list_06A0C8_ADDRESS 0x60C8u    /* 06A0C8 */
#define sprite_list_06A0E6_ADDRESS 0x60E6u    /* 06A0E6 */
#define sprite_list_06A10A_ADDRESS 0x610Au    /* 06A10A */
#define sprite_list_06A11C_ADDRESS 0x611Cu    /* 06A11C */
#define sprite_list_06A146_ADDRESS 0x6146u    /* 06A146 */
#define sprite_list_06A16A_ADDRESS 0x616Au    /* 06A16A */
#define animation_06A188_ADDRESS 0x6188u    /* 06A188 */
#define sprite_list_06A1AC_ADDRESS 0x61ACu    /* 06A1AC */
#define sprite_list_06A1CA_ADDRESS 0x61CAu    /* 06A1CA */
#define sprite_list_06A1E8_ADDRESS 0x61E8u    /* 06A1E8 */
#define sprite_list_06A206_ADDRESS 0x6206u    /* 06A206 */
#define sprite_list_06A22A_ADDRESS 0x622Au    /* 06A22A */
#define sprite_list_06A23C_ADDRESS 0x623Cu    /* 06A23C */
#define sprite_list_06A266_ADDRESS 0x6266u    /* 06A266 */
#define sprite_list_06A28A_ADDRESS 0x628Au    /* 06A28A */
#define animation_06A2A8_ADDRESS 0x62A8u    /* 06A2A8 */
#define sprite_list_06A2CC_ADDRESS 0x62CCu    /* 06A2CC */
#define sprite_list_06A2EA_ADDRESS 0x62EAu    /* 06A2EA */
#define sprite_list_06A308_ADDRESS 0x6308u    /* 06A308 */
#define sprite_list_06A320_ADDRESS 0x6320u    /* 06A320 */
#define sprite_list_06A338_ADDRESS 0x6338u    /* 06A338 */
#define animation_06A350_ADDRESS 0x6350u    /* 06A350 */
#define sprite_list_06A358_ADDRESS 0x6358u    /* 06A358 */
#define animation_06A370_ADDRESS 0x6370u    /* 06A370 */
#define sprite_list_06A37C_ADDRESS 0x637Cu    /* 06A37C */
#define sprite_list_06A39A_ADDRESS 0x639Au    /* 06A39A */
#define animation_06A3AC_ADDRESS 0x63ACu    /* 06A3AC */
#define animation_06A3B4_ADDRESS 0x63B4u    /* 06A3B4 */
#define sprite_list_06A3C0_ADDRESS 0x63C0u    /* 06A3C0 */
#define sprite_list_06A3FC_ADDRESS 0x63FCu    /* 06A3FC */
#define animation_06A432_ADDRESS 0x6432u    /* 06A432 */
#define sprite_list_06A442_ADDRESS 0x6442u    /* 06A442 */
#define sprite_list_06A454_ADDRESS 0x6454u    /* 06A454 */
#define sprite_list_06A466_ADDRESS 0x6466u    /* 06A466 */
#define animation_06A47E_ADDRESS 0x647Eu    /* 06A47E */
#define sprite_list_06A4A6_ADDRESS 0x64A6u    /* 06A4A6 */
#define sprite_list_06A4C4_ADDRESS 0x64C4u    /* 06A4C4 */
#define sprite_list_06A4E8_ADDRESS 0x64E8u    /* 06A4E8 */
#define sprite_list_06A50C_ADDRESS 0x650Cu    /* 06A50C */
#define sprite_list_06A536_ADDRESS 0x6536u    /* 06A536 */
#define sprite_list_06A560_ADDRESS 0x6560u    /* 06A560 */
#define sprite_list_06A58A_ADDRESS 0x658Au    /* 06A58A */
#define animation_06A5A8_ADDRESS 0x65A8u    /* 06A5A8 */
#define sprite_list_06A5CC_ADDRESS 0x65CCu    /* 06A5CC */
#define sprite_list_06A5D2_ADDRESS 0x65D2u    /* 06A5D2 */
#define sprite_list_06A5D8_ADDRESS 0x65D8u    /* 06A5D8 */
#define sprite_list_06A5DE_ADDRESS 0x65DEu    /* 06A5DE */
#define sprite_list_06A5E4_ADDRESS 0x65E4u    /* 06A5E4 */
#define sprite_list_06A5EA_ADDRESS 0x65EAu    /* 06A5EA */
#define sprite_list_06A5F0_ADDRESS 0x65F0u    /* 06A5F0 */
#define sprite_list_06A5F6_ADDRESS 0x65F6u    /* 06A5F6 */
#define animation_06A5FC_ADDRESS 0x65FCu    /* 06A5FC */
#define sprite_list_06A620_ADDRESS 0x6620u    /* 06A620 */
#define sprite_list_06A626_ADDRESS 0x6626u    /* 06A626 */
#define sprite_list_06A632_ADDRESS 0x6632u    /* 06A632 */
#define sprite_list_06A638_ADDRESS 0x6638u    /* 06A638 */
#define sprite_list_06A63E_ADDRESS 0x663Eu    /* 06A63E */
#define sprite_list_06A650_ADDRESS 0x6650u    /* 06A650 */
#define sprite_list_06A656_ADDRESS 0x6656u    /* 06A656 */
#define sprite_list_06A65C_ADDRESS 0x665Cu    /* 06A65C */
#define animation_06A662_ADDRESS 0x6662u    /* 06A662 */
#define sprite_list_06A686_ADDRESS 0x6686u    /* 06A686 */
#define sprite_list_06A6A4_ADDRESS 0x66A4u    /* 06A6A4 */
#define sprite_list_06A6C8_ADDRESS 0x66C8u    /* 06A6C8 */
#define sprite_list_06A6EC_ADDRESS 0x66ECu    /* 06A6EC */
#define sprite_list_06A710_ADDRESS 0x6710u    /* 06A710 */
#define sprite_list_06A734_ADDRESS 0x6734u    /* 06A734 */
#define sprite_list_06A746_ADDRESS 0x6746u    /* 06A746 */
#define sprite_list_06A770_ADDRESS 0x6770u    /* 06A770 */
#define animation_06A794_ADDRESS 0x6794u    /* 06A794 */
#define sprite_list_06A7A8_ADDRESS 0x67A8u    /* 06A7A8 */
#define sprite_list_06A7BA_ADDRESS 0x67BAu    /* 06A7BA */
#define sprite_list_06A7D8_ADDRESS 0x67D8u    /* 06A7D8 */
#define sprite_list_06A802_ADDRESS 0x6802u    /* 06A802 */
#define animation_06A820_ADDRESS 0x6820u    /* 06A820 */
#define sprite_list_06A848_ADDRESS 0x6848u    /* 06A848 */
#define sprite_list_06A860_ADDRESS 0x6860u    /* 06A860 */
#define sprite_list_06A87E_ADDRESS 0x687Eu    /* 06A87E */
#define sprite_list_06A8A2_ADDRESS 0x68A2u    /* 06A8A2 */
#define sprite_list_06A8C6_ADDRESS 0x68C6u    /* 06A8C6 */
#define sprite_list_06A8F0_ADDRESS 0x68F0u    /* 06A8F0 */
#define sprite_list_06A91A_ADDRESS 0x691Au    /* 06A91A */
#define animation_06A93E_ADDRESS 0x693Eu    /* 06A93E */
#define sprite_list_06A962_ADDRESS 0x6962u    /* 06A962 */
#define sprite_list_06A980_ADDRESS 0x6980u    /* 06A980 */
#define sprite_list_06A9A4_ADDRESS 0x69A4u    /* 06A9A4 */
#define sprite_list_06A9C8_ADDRESS 0x69C8u    /* 06A9C8 */
#define sprite_list_06A9EC_ADDRESS 0x69ECu    /* 06A9EC */
#define sprite_list_06AA04_ADDRESS 0x6A04u    /* 06AA04 */
#define sprite_list_06AA2E_ADDRESS 0x6A2Eu    /* 06AA2E */
#define sprite_list_06AA58_ADDRESS 0x6A58u    /* 06AA58 */
#define animation_06AA7C_ADDRESS 0x6A7Cu    /* 06AA7C */
#define sprite_list_06AAA0_ADDRESS 0x6AA0u    /* 06AAA0 */
#define sprite_list_06AAC4_ADDRESS 0x6AC4u    /* 06AAC4 */
#define sprite_list_06AAEE_ADDRESS 0x6AEEu    /* 06AAEE */
#define sprite_list_06AB0C_ADDRESS 0x6B0Cu    /* 06AB0C */
#define sprite_list_06AB36_ADDRESS 0x6B36u    /* 06AB36 */
#define animation_06AB5A_ADDRESS 0x6B5Au    /* 06AB5A */
#define sprite_list_06AB7E_ADDRESS 0x6B7Eu    /* 06AB7E */
#define sprite_list_06AB96_ADDRESS 0x6B96u    /* 06AB96 */
#define sprite_list_06ABB4_ADDRESS 0x6BB4u    /* 06ABB4 */
#define sprite_list_06ABD8_ADDRESS 0x6BD8u    /* 06ABD8 */
#define sprite_list_06ABF6_ADDRESS 0x6BF6u    /* 06ABF6 */
#define sprite_list_06AC20_ADDRESS 0x6C20u    /* 06AC20 */
#define sprite_list_06AC50_ADDRESS 0x6C50u    /* 06AC50 */
#define sprite_list_06AC7A_ADDRESS 0x6C7Au    /* 06AC7A */
#define animation_06AC9E_ADDRESS 0x6C9Eu    /* 06AC9E */
#define sprite_list_06ACC2_ADDRESS 0x6CC2u    /* 06ACC2 */
#define sprite_list_06ACE6_ADDRESS 0x6CE6u    /* 06ACE6 */
#define sprite_list_06AD0A_ADDRESS 0x6D0Au    /* 06AD0A */
#define sprite_list_06AD2E_ADDRESS 0x6D2Eu    /* 06AD2E */
#define sprite_list_06AD58_ADDRESS 0x6D58u    /* 06AD58 */
#define sprite_list_06AD8E_ADDRESS 0x6D8Eu    /* 06AD8E */
#define sprite_list_06ADB8_ADDRESS 0x6DB8u    /* 06ADB8 */
#define sprite_list_06ADE8_ADDRESS 0x6DE8u    /* 06ADE8 */
#define animation_06AE00_ADDRESS 0x6E00u    /* 06AE00 */
#define sprite_list_06AE80_ADDRESS 0x6E80u    /* 06AE80 */
#define sprite_list_06AE98_ADDRESS 0x6E98u    /* 06AE98 */
#define sprite_list_06AEB6_ADDRESS 0x6EB6u    /* 06AEB6 */
#define sprite_list_06AED4_ADDRESS 0x6ED4u    /* 06AED4 */
#define sprite_list_06AEF2_ADDRESS 0x6EF2u    /* 06AEF2 */
#define sprite_list_06AF10_ADDRESS 0x6F10u    /* 06AF10 */
#define sprite_list_06AF28_ADDRESS 0x6F28u    /* 06AF28 */
#define animation_06AF46_ADDRESS 0x6F46u    /* 06AF46 */
#define sprite_list_06AF4E_ADDRESS 0x6F4Eu    /* 06AF4E */
#define animation_06AF5A_ADDRESS 0x6F5Au    /* 06AF5A */
#define sprite_list_06AF72_ADDRESS 0x6F72u    /* 06AF72 */
#define sprite_list_06AF8A_ADDRESS 0x6F8Au    /* 06AF8A */
#define sprite_list_06AFA2_ADDRESS 0x6FA2u    /* 06AFA2 */
#define sprite_list_06AFB4_ADDRESS 0x6FB4u    /* 06AFB4 */
#define sprite_list_06AFC0_ADDRESS 0x6FC0u    /* 06AFC0 */
#define animation_06AFCC_ADDRESS 0x6FCCu    /* 06AFCC */
#define sprite_list_06AFF0_ADDRESS 0x6FF0u    /* 06AFF0 */
#define sprite_list_06B020_ADDRESS 0x7020u    /* 06B020 */
#define sprite_list_06B038_ADDRESS 0x7038u    /* 06B038 */
#define sprite_list_06B056_ADDRESS 0x7056u    /* 06B056 */
#define sprite_list_06B07A_ADDRESS 0x707Au    /* 06B07A */
#define animation_06B098_ADDRESS 0x7098u    /* 06B098 */
#define sprite_list_06B0A8_ADDRESS 0x70A8u    /* 06B0A8 */
#define sprite_list_06B0B4_ADDRESS 0x70B4u    /* 06B0B4 */
#define sprite_list_06B0C6_ADDRESS 0x70C6u    /* 06B0C6 */
#define animation_06B0D8_ADDRESS 0x70D8u    /* 06B0D8 */
#define sprite_list_06B0F4_ADDRESS 0x70F4u    /* 06B0F4 */
#define sprite_list_06B112_ADDRESS 0x7112u    /* 06B112 */
#define sprite_list_06B12A_ADDRESS 0x712Au    /* 06B12A */
#define sprite_list_06B13C_ADDRESS 0x713Cu    /* 06B13C */
#define animation_06B154_ADDRESS 0x7154u    /* 06B154 */
#define sprite_list_06B164_ADDRESS 0x7164u    /* 06B164 */
#define sprite_list_06B17C_ADDRESS 0x717Cu    /* 06B17C */
#define sprite_list_06B1A0_ADDRESS 0x71A0u    /* 06B1A0 */
#define animation_06B1BE_ADDRESS 0x71BEu    /* 06B1BE */
#define sprite_list_06B1CA_ADDRESS 0x71CAu    /* 06B1CA */
#define sprite_list_06B1EE_ADDRESS 0x71EEu    /* 06B1EE */
#define animation_06B20C_ADDRESS 0x720Cu    /* 06B20C */
#define animation_06B278_ADDRESS 0x7278u    /* 06B278 */
#define sprite_list_06B2B4_ADDRESS 0x72B4u    /* 06B2B4 */
#define sprite_list_06B2DE_ADDRESS 0x72DEu    /* 06B2DE */
#define sprite_list_06B308_ADDRESS 0x7308u    /* 06B308 */
#define sprite_list_06B33E_ADDRESS 0x733Eu    /* 06B33E */
#define sprite_list_06B374_ADDRESS 0x7374u    /* 06B374 */
#define sprite_list_06B3B0_ADDRESS 0x73B0u    /* 06B3B0 */
#define sprite_list_06B3E0_ADDRESS 0x73E0u    /* 06B3E0 */
#define sprite_list_06B422_ADDRESS 0x7422u    /* 06B422 */
#define sprite_list_06B46A_ADDRESS 0x746Au    /* 06B46A */
#define sprite_list_06B4A6_ADDRESS 0x74A6u    /* 06B4A6 */
#define sprite_list_06B4DC_ADDRESS 0x74DCu    /* 06B4DC */
#define sprite_list_06B512_ADDRESS 0x7512u    /* 06B512 */
#define sprite_list_06B536_ADDRESS 0x7536u    /* 06B536 */
#define sprite_list_06B560_ADDRESS 0x7560u    /* 06B560 */
#define sprite_list_06B58A_ADDRESS 0x758Au    /* 06B58A */
#define sprite_list_06B5C0_ADDRESS 0x75C0u    /* 06B5C0 */
#define sprite_list_06B608_ADDRESS 0x7608u    /* 06B608 */
#define sprite_list_06B668_ADDRESS 0x7668u    /* 06B668 */
#define sprite_list_06B6C8_ADDRESS 0x76C8u    /* 06B6C8 */
#define sprite_list_06B728_ADDRESS 0x7728u    /* 06B728 */
#define sprite_list_06B788_ADDRESS 0x7788u    /* 06B788 */
#define sprite_list_06B7D0_ADDRESS 0x77D0u    /* 06B7D0 */
#define sprite_list_06B80C_ADDRESS 0x780Cu    /* 06B80C */
#define sprite_list_06B83C_ADDRESS 0x783Cu    /* 06B83C */
#define sprite_list_06B86C_ADDRESS 0x786Cu    /* 06B86C */
#define sprite_list_06B890_ADDRESS 0x7890u    /* 06B890 */
#define animation_06B8AE_ADDRESS 0x78AEu    /* 06B8AE */
#define sprite_list_06B8CA_ADDRESS 0x78CAu    /* 06B8CA */
#define animation_06B8E8_ADDRESS 0x78E8u    /* 06B8E8 */
#define sprite_list_06B908_ADDRESS 0x7908u    /* 06B908 */
#define sprite_list_06B926_ADDRESS 0x7926u    /* 06B926 */
#define sprite_list_06B938_ADDRESS 0x7938u    /* 06B938 */
#define sprite_list_06B950_ADDRESS 0x7950u    /* 06B950 */
#define animation_06B968_ADDRESS 0x7968u    /* 06B968 */
#define sprite_list_06B978_ADDRESS 0x7978u    /* 06B978 */
#define sprite_list_06B996_ADDRESS 0x7996u    /* 06B996 */
#define sprite_list_06B9AE_ADDRESS 0x79AEu    /* 06B9AE */
#define animation_06B9C0_ADDRESS 0x79C0u    /* 06B9C0 */
#define animation_06B9C8_ADDRESS 0x79C8u    /* 06B9C8 */
#define sprite_list_06B9EC_ADDRESS 0x79ECu    /* 06B9EC */
#define sprite_list_06B9F2_ADDRESS 0x79F2u    /* 06B9F2 */
#define sprite_list_06B9F8_ADDRESS 0x79F8u    /* 06B9F8 */
#define sprite_list_06B9FE_ADDRESS 0x79FEu    /* 06B9FE */
#define sprite_list_06BA04_ADDRESS 0x7A04u    /* 06BA04 */
#define sprite_list_06BA0A_ADDRESS 0x7A0Au    /* 06BA0A */
#define sprite_list_06BA10_ADDRESS 0x7A10u    /* 06BA10 */
#define sprite_list_06BA16_ADDRESS 0x7A16u    /* 06BA16 */
#define animation_06BA1C_ADDRESS 0x7A1Cu    /* 06BA1C */
#define sprite_list_06BA44_ADDRESS 0x7A44u    /* 06BA44 */
#define sprite_list_06BA4A_ADDRESS 0x7A4Au    /* 06BA4A */
#define sprite_list_06BA50_ADDRESS 0x7A50u    /* 06BA50 */
#define sprite_list_06BA56_ADDRESS 0x7A56u    /* 06BA56 */
#define sprite_list_06BA5C_ADDRESS 0x7A5Cu    /* 06BA5C */
#define sprite_list_06BA62_ADDRESS 0x7A62u    /* 06BA62 */
#define sprite_list_06BA68_ADDRESS 0x7A68u    /* 06BA68 */
#define sprite_list_06BA6E_ADDRESS 0x7A6Eu    /* 06BA6E */
#define sprite_list_06BA74_ADDRESS 0x7A74u    /* 06BA74 */
#define animation_06BA7A_ADDRESS 0x7A7Au    /* 06BA7A */
#define sprite_list_06BAAE_ADDRESS 0x7AAEu    /* 06BAAE */
#define sprite_list_06BAB4_ADDRESS 0x7AB4u    /* 06BAB4 */
#define sprite_list_06BAC0_ADDRESS 0x7AC0u    /* 06BAC0 */
#define sprite_list_06BAD2_ADDRESS 0x7AD2u    /* 06BAD2 */
#define sprite_list_06BAF6_ADDRESS 0x7AF6u    /* 06BAF6 */
#define sprite_list_06BB26_ADDRESS 0x7B26u    /* 06BB26 */
#define sprite_list_06BB5C_ADDRESS 0x7B5Cu    /* 06BB5C */
#define sprite_list_06BB98_ADDRESS 0x7B98u    /* 06BB98 */
#define animation_table_06BB9E_ADDRESS 0x7B9Eu    /* 06BB9E */
#define animation_06BBC2_ADDRESS 0x7BC2u    /* 06BBC2 */
#define sprite_list_06BBCE_ADDRESS 0x7BCEu    /* 06BBCE */
#define sprite_list_06BBDA_ADDRESS 0x7BDAu    /* 06BBDA */
#define animation_06BBE6_ADDRESS 0x7BE6u    /* 06BBE6 */
#define sprite_list_06BBF2_ADDRESS 0x7BF2u    /* 06BBF2 */
#define sprite_list_06BC46_ADDRESS 0x7C46u    /* 06BC46 */
#define animation_06BCA0_ADDRESS 0x7CA0u    /* 06BCA0 */
#define sprite_list_06BCB8_ADDRESS 0x7CB8u    /* 06BCB8 */
#define sprite_list_06BD0C_ADDRESS 0x7D0Cu    /* 06BD0C */
#define sprite_list_06BD66_ADDRESS 0x7D66u    /* 06BD66 */
#define sprite_list_06BDBA_ADDRESS 0x7DBAu    /* 06BDBA */
#define sprite_list_06BE14_ADDRESS 0x7E14u    /* 06BE14 */
#define animation_06BE6E_ADDRESS 0x7E6Eu    /* 06BE6E */
#define animation_06BE7A_ADDRESS 0x7E7Au    /* 06BE7A */
#define sprite_list_06BE86_ADDRESS 0x7E86u    /* 06BE86 */
#define sprite_list_06BE92_ADDRESS 0x7E92u    /* 06BE92 */
#define animation_06BE9E_ADDRESS 0x7E9Eu    /* 06BE9E */
#define sprite_list_06BEAA_ADDRESS 0x7EAAu    /* 06BEAA */
#define sprite_list_06BEBC_ADDRESS 0x7EBCu    /* 06BEBC */
#define animation_06BECE_ADDRESS 0x7ECEu    /* 06BECE */
#define sprite_list_06BEDA_ADDRESS 0x7EDAu    /* 06BEDA */
#define sprite_list_06BEEC_ADDRESS 0x7EECu    /* 06BEEC */
#define animation_06BEFE_ADDRESS 0x7EFEu    /* 06BEFE */
#define sprite_list_06BF06_ADDRESS 0x7F06u    /* 06BF06 */
#define animation_06BF24_ADDRESS 0x7F24u    /* 06BF24 */
#define sprite_list_06BF30_ADDRESS 0x7F30u    /* 06BF30 */
#define sprite_list_06BF48_ADDRESS 0x7F48u    /* 06BF48 */
#define animation_06BF60_ADDRESS 0x7F60u    /* 06BF60 */
#define sprite_list_06BF68_ADDRESS 0x7F68u    /* 06BF68 */
#define animation_06BF6E_ADDRESS 0x7F6Eu    /* 06BF6E */
#define sprite_list_06BF76_ADDRESS 0x7F76u    /* 06BF76 */
#define animation_06BF7C_ADDRESS 0x7F7Cu    /* 06BF7C */
#define sprite_list_06BF84_ADDRESS 0x7F84u    /* 06BF84 */
#define animation_06BF8A_ADDRESS 0x7F8Au    /* 06BF8A */
#define sprite_list_06BF92_ADDRESS 0x7F92u    /* 06BF92 */
#define animation_06BF9E_ADDRESS 0x7F9Eu    /* 06BF9E */
#define sprite_list_06BFAA_ADDRESS 0x7FAAu    /* 06BFAA */
#define sprite_list_06BFB0_ADDRESS 0x7FB0u    /* 06BFB0 */
#define animation_06BFB6_ADDRESS 0x7FB6u    /* 06BFB6 */
#define sprite_list_06BFBE_ADDRESS 0x7FBEu    /* 06BFBE */
#define animation_06BFC4_ADDRESS 0x7FC4u    /* 06BFC4 */
#define sprite_list_06BFCC_ADDRESS 0x7FCCu    /* 06BFCC */
#define animation_06BFD2_ADDRESS 0x7FD2u    /* 06BFD2 */
#define sprite_list_06BFDA_ADDRESS 0x7FDAu    /* 06BFDA */
#define animation_06BFE0_ADDRESS 0x7FE0u    /* 06BFE0 */
#define sprite_list_06BFE8_ADDRESS 0x7FE8u    /* 06BFE8 */
#define fill_06BFEE_ADDRESS 0x7FEEu    /* 06BFEE */
#define set_index_06C000_ADDRESS 0x6000u    /* 06C000 */
#define animation_table_06C00C_ADDRESS 0x600Cu    /* 06C00C */
#define animation_06C082_ADDRESS 0x6082u    /* 06C082 */
#define sprite_list_06C08A_ADDRESS 0x608Au    /* 06C08A */
#define animation_06C096_ADDRESS 0x6096u    /* 06C096 */
#define sprite_list_06C0BA_ADDRESS 0x60BAu    /* 06C0BA */
#define sprite_list_06C0D2_ADDRESS 0x60D2u    /* 06C0D2 */
#define sprite_list_06C0EA_ADDRESS 0x60EAu    /* 06C0EA */
#define sprite_list_06C102_ADDRESS 0x6102u    /* 06C102 */
#define sprite_list_06C11A_ADDRESS 0x611Au    /* 06C11A */
#define sprite_list_06C132_ADDRESS 0x6132u    /* 06C132 */
#define sprite_list_06C14A_ADDRESS 0x614Au    /* 06C14A */
#define sprite_list_06C162_ADDRESS 0x6162u    /* 06C162 */
#define animation_06C17A_ADDRESS 0x617Au    /* 06C17A */
#define sprite_list_06C19E_ADDRESS 0x619Eu    /* 06C19E */
#define sprite_list_06C1BC_ADDRESS 0x61BCu    /* 06C1BC */
#define sprite_list_06C1D4_ADDRESS 0x61D4u    /* 06C1D4 */
#define sprite_list_06C1EC_ADDRESS 0x61ECu    /* 06C1EC */
#define sprite_list_06C204_ADDRESS 0x6204u    /* 06C204 */
#define sprite_list_06C21C_ADDRESS 0x621Cu    /* 06C21C */
#define sprite_list_06C234_ADDRESS 0x6234u    /* 06C234 */
#define sprite_list_06C24C_ADDRESS 0x624Cu    /* 06C24C */
#define animation_06C264_ADDRESS 0x6264u    /* 06C264 */
#define sprite_list_06C288_ADDRESS 0x6288u    /* 06C288 */
#define sprite_list_06C2A0_ADDRESS 0x62A0u    /* 06C2A0 */
#define sprite_list_06C2B8_ADDRESS 0x62B8u    /* 06C2B8 */
#define sprite_list_06C2D0_ADDRESS 0x62D0u    /* 06C2D0 */
#define sprite_list_06C2E8_ADDRESS 0x62E8u    /* 06C2E8 */
#define sprite_list_06C300_ADDRESS 0x6300u    /* 06C300 */
#define sprite_list_06C318_ADDRESS 0x6318u    /* 06C318 */
#define sprite_list_06C330_ADDRESS 0x6330u    /* 06C330 */
#define animation_06C348_ADDRESS 0x6348u    /* 06C348 */
#define sprite_list_06C354_ADDRESS 0x6354u    /* 06C354 */
#define sprite_list_06C360_ADDRESS 0x6360u    /* 06C360 */
#define animation_06C36C_ADDRESS 0x636Cu    /* 06C36C */
#define sprite_list_06C378_ADDRESS 0x6378u    /* 06C378 */
#define sprite_list_06C384_ADDRESS 0x6384u    /* 06C384 */
#define animation_06C390_ADDRESS 0x6390u    /* 06C390 */
#define sprite_list_06C39C_ADDRESS 0x639Cu    /* 06C39C */
#define sprite_list_06C3A8_ADDRESS 0x63A8u    /* 06C3A8 */
#define animation_06C3B4_ADDRESS 0x63B4u    /* 06C3B4 */
#define sprite_list_06C3C0_ADDRESS 0x63C0u    /* 06C3C0 */
#define sprite_list_06C3CC_ADDRESS 0x63CCu    /* 06C3CC */
#define animation_06C3DE_ADDRESS 0x63DEu    /* 06C3DE */
#define sprite_list_06C3F6_ADDRESS 0x63F6u    /* 06C3F6 */
#define sprite_list_06C408_ADDRESS 0x6408u    /* 06C408 */
#define sprite_list_06C41A_ADDRESS 0x641Au    /* 06C41A */
#define sprite_list_06C42C_ADDRESS 0x642Cu    /* 06C42C */
#define sprite_list_06C444_ADDRESS 0x6444u    /* 06C444 */
#define animation_06C450_ADDRESS 0x6450u    /* 06C450 */
#define sprite_list_06C46C_ADDRESS 0x646Cu    /* 06C46C */
#define sprite_list_06C47E_ADDRESS 0x647Eu    /* 06C47E */
#define sprite_list_06C48A_ADDRESS 0x648Au    /* 06C48A */
#define sprite_list_06C49C_ADDRESS 0x649Cu    /* 06C49C */
#define animation_06C4AE_ADDRESS 0x64AEu    /* 06C4AE */
#define sprite_list_06C4C2_ADDRESS 0x64C2u    /* 06C4C2 */
#define sprite_list_06C4CE_ADDRESS 0x64CEu    /* 06C4CE */
#define sprite_list_06C4E0_ADDRESS 0x64E0u    /* 06C4E0 */
#define sprite_list_06C4F2_ADDRESS 0x64F2u    /* 06C4F2 */
#define animation_06C4FE_ADDRESS 0x64FEu    /* 06C4FE */
#define sprite_list_06C516_ADDRESS 0x6516u    /* 06C516 */
#define sprite_list_06C52E_ADDRESS 0x652Eu    /* 06C52E */
#define sprite_list_06C546_ADDRESS 0x6546u    /* 06C546 */
#define sprite_list_06C558_ADDRESS 0x6558u    /* 06C558 */
#define sprite_list_06C570_ADDRESS 0x6570u    /* 06C570 */
#define animation_06C588_ADDRESS 0x6588u    /* 06C588 */
#define sprite_list_06C5A8_ADDRESS 0x65A8u    /* 06C5A8 */
#define sprite_list_06C5BA_ADDRESS 0x65BAu    /* 06C5BA */
#define sprite_list_06C5D2_ADDRESS 0x65D2u    /* 06C5D2 */
#define sprite_list_06C5EA_ADDRESS 0x65EAu    /* 06C5EA */
#define sprite_list_06C602_ADDRESS 0x6602u    /* 06C602 */
#define sprite_list_06C614_ADDRESS 0x6614u    /* 06C614 */
#define animation_06C626_ADDRESS 0x6626u    /* 06C626 */
#define sprite_list_06C632_ADDRESS 0x6632u    /* 06C632 */
#define sprite_list_06C644_ADDRESS 0x6644u    /* 06C644 */
#define animation_06C656_ADDRESS 0x6656u    /* 06C656 */
#define sprite_list_06C67A_ADDRESS 0x667Au    /* 06C67A */
#define sprite_list_06C692_ADDRESS 0x6692u    /* 06C692 */
#define sprite_list_06C6A4_ADDRESS 0x66A4u    /* 06C6A4 */
#define sprite_list_06C6BC_ADDRESS 0x66BCu    /* 06C6BC */
#define sprite_list_06C6C8_ADDRESS 0x66C8u    /* 06C6C8 */
#define animation_06C6D4_ADDRESS 0x66D4u    /* 06C6D4 */
#define sprite_list_06C6F0_ADDRESS 0x66F0u    /* 06C6F0 */
#define sprite_list_06C702_ADDRESS 0x6702u    /* 06C702 */
#define sprite_list_06C714_ADDRESS 0x6714u    /* 06C714 */
#define sprite_list_06C732_ADDRESS 0x6732u    /* 06C732 */
#define animation_06C750_ADDRESS 0x6750u    /* 06C750 */
#define sprite_list_06C774_ADDRESS 0x6774u    /* 06C774 */
#define sprite_list_06C78C_ADDRESS 0x678Cu    /* 06C78C */
#define sprite_list_06C79E_ADDRESS 0x679Eu    /* 06C79E */
#define sprite_list_06C7B0_ADDRESS 0x67B0u    /* 06C7B0 */
#define sprite_list_06C7C2_ADDRESS 0x67C2u    /* 06C7C2 */
#define sprite_list_06C7D4_ADDRESS 0x67D4u    /* 06C7D4 */
#define sprite_list_06C7E6_ADDRESS 0x67E6u    /* 06C7E6 */
#define sprite_list_06C7F8_ADDRESS 0x67F8u    /* 06C7F8 */
#define animation_06C810_ADDRESS 0x6810u    /* 06C810 */
#define sprite_list_06C834_ADDRESS 0x6834u    /* 06C834 */
#define sprite_list_06C840_ADDRESS 0x6840u    /* 06C840 */
#define sprite_list_06C84C_ADDRESS 0x684Cu    /* 06C84C */
#define sprite_list_06C858_ADDRESS 0x6858u    /* 06C858 */
#define sprite_list_06C864_ADDRESS 0x6864u    /* 06C864 */
#define sprite_list_06C870_ADDRESS 0x6870u    /* 06C870 */
#define sprite_list_06C87C_ADDRESS 0x687Cu    /* 06C87C */
#define sprite_list_06C888_ADDRESS 0x6888u    /* 06C888 */
#define animation_06C894_ADDRESS 0x6894u    /* 06C894 */
#define sprite_list_06C8AC_ADDRESS 0x68ACu    /* 06C8AC */
#define sprite_list_06C8BE_ADDRESS 0x68BEu    /* 06C8BE */
#define sprite_list_06C8D0_ADDRESS 0x68D0u    /* 06C8D0 */
#define sprite_list_06C8DC_ADDRESS 0x68DCu    /* 06C8DC */
#define animation_06C8E8_ADDRESS 0x68E8u    /* 06C8E8 */
#define sprite_list_06C8FC_ADDRESS 0x68FCu    /* 06C8FC */
#define sprite_list_06C908_ADDRESS 0x6908u    /* 06C908 */
#define sprite_list_06C920_ADDRESS 0x6920u    /* 06C920 */
#define animation_06C938_ADDRESS 0x6938u    /* 06C938 */
#define sprite_list_06C950_ADDRESS 0x6950u    /* 06C950 */
#define sprite_list_06C95C_ADDRESS 0x695Cu    /* 06C95C */
#define sprite_list_06C96E_ADDRESS 0x696Eu    /* 06C96E */
#define animation_06C980_ADDRESS 0x6980u    /* 06C980 */
#define sprite_list_06C98C_ADDRESS 0x698Cu    /* 06C98C */
#define sprite_list_06C998_ADDRESS 0x6998u    /* 06C998 */
#define animation_06C9A4_ADDRESS 0x69A4u    /* 06C9A4 */
#define sprite_list_06C9B8_ADDRESS 0x69B8u    /* 06C9B8 */
#define sprite_list_06C9BE_ADDRESS 0x69BEu    /* 06C9BE */
#define sprite_list_06C9CA_ADDRESS 0x69CAu    /* 06C9CA */
#define sprite_list_06C9D6_ADDRESS 0x69D6u    /* 06C9D6 */
#define animation_06C9DC_ADDRESS 0x69DCu    /* 06C9DC */
#define sprite_list_06C9F4_ADDRESS 0x69F4u    /* 06C9F4 */
#define sprite_list_06CA00_ADDRESS 0x6A00u    /* 06CA00 */
#define sprite_list_06CA18_ADDRESS 0x6A18u    /* 06CA18 */
#define sprite_list_06CA30_ADDRESS 0x6A30u    /* 06CA30 */
#define animation_06CA42_ADDRESS 0x6A42u    /* 06CA42 */
#define sprite_list_06CA66_ADDRESS 0x6A66u    /* 06CA66 */
#define sprite_list_06CA72_ADDRESS 0x6A72u    /* 06CA72 */
#define sprite_list_06CA84_ADDRESS 0x6A84u    /* 06CA84 */
#define animation_06CA96_ADDRESS 0x6A96u    /* 06CA96 */
#define sprite_list_06CABA_ADDRESS 0x6ABAu    /* 06CABA */
#define sprite_list_06CAC6_ADDRESS 0x6AC6u    /* 06CAC6 */
#define sprite_list_06CAD8_ADDRESS 0x6AD8u    /* 06CAD8 */
#define sprite_list_06CAF0_ADDRESS 0x6AF0u    /* 06CAF0 */
#define sprite_list_06CB08_ADDRESS 0x6B08u    /* 06CB08 */
#define sprite_list_06CB26_ADDRESS 0x6B26u    /* 06CB26 */
#define sprite_list_06CB3E_ADDRESS 0x6B3Eu    /* 06CB3E */
#define sprite_list_06CB56_ADDRESS 0x6B56u    /* 06CB56 */
#define animation_06CB68_ADDRESS 0x6B68u    /* 06CB68 */
#define sprite_list_06CB74_ADDRESS 0x6B74u    /* 06CB74 */
#define animation_06CB86_ADDRESS 0x6B86u    /* 06CB86 */
#define sprite_list_06CB9A_ADDRESS 0x6B9Au    /* 06CB9A */
#define sprite_list_06CBA6_ADDRESS 0x6BA6u    /* 06CBA6 */
#define sprite_list_06CBB8_ADDRESS 0x6BB8u    /* 06CBB8 */
#define sprite_list_06CBCA_ADDRESS 0x6BCAu    /* 06CBCA */
#define animation_06CBE8_ADDRESS 0x6BE8u    /* 06CBE8 */
#define sprite_list_06CBF0_ADDRESS 0x6BF0u    /* 06CBF0 */
#define animation_06CBFC_ADDRESS 0x6BFCu    /* 06CBFC */
#define sprite_list_06CC18_ADDRESS 0x6C18u    /* 06CC18 */
#define sprite_list_06CC24_ADDRESS 0x6C24u    /* 06CC24 */
#define sprite_list_06CC3C_ADDRESS 0x6C3Cu    /* 06CC3C */
#define sprite_list_06CC54_ADDRESS 0x6C54u    /* 06CC54 */
#define sprite_list_06CC66_ADDRESS 0x6C66u    /* 06CC66 */
#define animation_06CC7E_ADDRESS 0x6C7Eu    /* 06CC7E */
#define sprite_list_06CC92_ADDRESS 0x6C92u    /* 06CC92 */
#define sprite_list_06CC98_ADDRESS 0x6C98u    /* 06CC98 */
#define sprite_list_06CC9E_ADDRESS 0x6C9Eu    /* 06CC9E */
#define animation_06CCA4_ADDRESS 0x6CA4u    /* 06CCA4 */
#define sprite_list_06CCD4_ADDRESS 0x6CD4u    /* 06CCD4 */
#define sprite_list_06CCDA_ADDRESS 0x6CDAu    /* 06CCDA */
#define sprite_list_06CCEC_ADDRESS 0x6CECu    /* 06CCEC */
#define sprite_list_06CCF8_ADDRESS 0x6CF8u    /* 06CCF8 */
#define sprite_list_06CD04_ADDRESS 0x6D04u    /* 06CD04 */
#define sprite_list_06CD10_ADDRESS 0x6D10u    /* 06CD10 */
#define sprite_list_06CD1C_ADDRESS 0x6D1Cu    /* 06CD1C */
#define sprite_list_06CD28_ADDRESS 0x6D28u    /* 06CD28 */
#define sprite_list_06CD34_ADDRESS 0x6D34u    /* 06CD34 */
#define sprite_list_06CD52_ADDRESS 0x6D52u    /* 06CD52 */
#define animation_06CD6A_ADDRESS 0x6D6Au    /* 06CD6A */
#define sprite_list_06CD86_ADDRESS 0x6D86u    /* 06CD86 */
#define sprite_list_06CD98_ADDRESS 0x6D98u    /* 06CD98 */
#define sprite_list_06CDAA_ADDRESS 0x6DAAu    /* 06CDAA */
#define animation_06CDBC_ADDRESS 0x6DBCu    /* 06CDBC */
#define sprite_list_06CDC4_ADDRESS 0x6DC4u    /* 06CDC4 */
#define animation_06CDCA_ADDRESS 0x6DCAu    /* 06CDCA */
#define sprite_list_06CDDE_ADDRESS 0x6DDEu    /* 06CDDE */
#define sprite_list_06CDEA_ADDRESS 0x6DEAu    /* 06CDEA */
#define sprite_list_06CDF6_ADDRESS 0x6DF6u    /* 06CDF6 */
#define sprite_list_06CE02_ADDRESS 0x6E02u    /* 06CE02 */
#define animation_06CE0E_ADDRESS 0x6E0Eu    /* 06CE0E */
#define sprite_list_06CE26_ADDRESS 0x6E26u    /* 06CE26 */
#define sprite_list_06CE32_ADDRESS 0x6E32u    /* 06CE32 */
#define sprite_list_06CE3E_ADDRESS 0x6E3Eu    /* 06CE3E */
#define sprite_list_06CE4A_ADDRESS 0x6E4Au    /* 06CE4A */
#define animation_06CE5C_ADDRESS 0x6E5Cu    /* 06CE5C */
#define sprite_list_06CE64_ADDRESS 0x6E64u    /* 06CE64 */
#define animation_06CE70_ADDRESS 0x6E70u    /* 06CE70 */
#define sprite_list_06CE94_ADDRESS 0x6E94u    /* 06CE94 */
#define sprite_list_06CEB2_ADDRESS 0x6EB2u    /* 06CEB2 */
#define sprite_list_06CED0_ADDRESS 0x6ED0u    /* 06CED0 */
#define sprite_list_06CEEE_ADDRESS 0x6EEEu    /* 06CEEE */
#define sprite_list_06CF0C_ADDRESS 0x6F0Cu    /* 06CF0C */
#define sprite_list_06CF2A_ADDRESS 0x6F2Au    /* 06CF2A */
#define sprite_list_06CF48_ADDRESS 0x6F48u    /* 06CF48 */
#define sprite_list_06CF66_ADDRESS 0x6F66u    /* 06CF66 */
#define animation_06CF84_ADDRESS 0x6F84u    /* 06CF84 */
#define sprite_list_06CF98_ADDRESS 0x6F98u    /* 06CF98 */
#define sprite_list_06CF9E_ADDRESS 0x6F9Eu    /* 06CF9E */
#define sprite_list_06CFA4_ADDRESS 0x6FA4u    /* 06CFA4 */
#define sprite_list_06CFAA_ADDRESS 0x6FAAu    /* 06CFAA */
#define animation_06CFB0_ADDRESS 0x6FB0u    /* 06CFB0 */
#define sprite_list_06CFC0_ADDRESS 0x6FC0u    /* 06CFC0 */
#define sprite_list_06CFCC_ADDRESS 0x6FCCu    /* 06CFCC */
#define sprite_list_06CFD8_ADDRESS 0x6FD8u    /* 06CFD8 */
#define animation_06CFE4_ADDRESS 0x6FE4u    /* 06CFE4 */
#define sprite_list_06CFF4_ADDRESS 0x6FF4u    /* 06CFF4 */
#define sprite_list_06D000_ADDRESS 0x7000u    /* 06D000 */
#define sprite_list_06D00C_ADDRESS 0x700Cu    /* 06D00C */
#define animation_06D018_ADDRESS 0x7018u    /* 06D018 */
#define sprite_list_06D03C_ADDRESS 0x703Cu    /* 06D03C */
#define sprite_list_06D05A_ADDRESS 0x705Au    /* 06D05A */
#define sprite_list_06D078_ADDRESS 0x7078u    /* 06D078 */
#define sprite_list_06D096_ADDRESS 0x7096u    /* 06D096 */
#define sprite_list_06D0B4_ADDRESS 0x70B4u    /* 06D0B4 */
#define sprite_list_06D0D2_ADDRESS 0x70D2u    /* 06D0D2 */
#define sprite_list_06D0F0_ADDRESS 0x70F0u    /* 06D0F0 */
#define sprite_list_06D10E_ADDRESS 0x710Eu    /* 06D10E */
#define animation_06D12C_ADDRESS 0x712Cu    /* 06D12C */
#define sprite_list_06D138_ADDRESS 0x7138u    /* 06D138 */
#define sprite_list_06D13E_ADDRESS 0x713Eu    /* 06D13E */
#define animation_06D144_ADDRESS 0x7144u    /* 06D144 */
#define sprite_list_06D158_ADDRESS 0x7158u    /* 06D158 */
#define sprite_list_06D176_ADDRESS 0x7176u    /* 06D176 */
#define sprite_list_06D194_ADDRESS 0x7194u    /* 06D194 */
#define sprite_list_06D1B2_ADDRESS 0x71B2u    /* 06D1B2 */
#define animation_06D1D0_ADDRESS 0x71D0u    /* 06D1D0 */
#define animation_06D1E4_ADDRESS 0x71E4u    /* 06D1E4 */
#define sprite_list_06D1FC_ADDRESS 0x71FCu    /* 06D1FC */
#define sprite_list_06D20E_ADDRESS 0x720Eu    /* 06D20E */
#define sprite_list_06D21A_ADDRESS 0x721Au    /* 06D21A */
#define sprite_list_06D22C_ADDRESS 0x722Cu    /* 06D22C */
#define sprite_list_06D244_ADDRESS 0x7244u    /* 06D244 */
#define animation_06D256_ADDRESS 0x7256u    /* 06D256 */
#define sprite_list_06D266_ADDRESS 0x7266u    /* 06D266 */
#define sprite_list_06D278_ADDRESS 0x7278u    /* 06D278 */
#define animation_table_06D28A_ADDRESS 0x728Au    /* 06D28A */
#define animation_06D2AA_ADDRESS 0x72AAu    /* 06D2AA */
#define sprite_list_06D2C2_ADDRESS 0x72C2u    /* 06D2C2 */
#define sprite_list_06D2E0_ADDRESS 0x72E0u    /* 06D2E0 */
#define sprite_list_06D304_ADDRESS 0x7304u    /* 06D304 */
#define sprite_list_06D328_ADDRESS 0x7328u    /* 06D328 */
#define sprite_list_06D34C_ADDRESS 0x734Cu    /* 06D34C */
#define animation_06D36A_ADDRESS 0x736Au    /* 06D36A */
#define sprite_list_06D37E_ADDRESS 0x737Eu    /* 06D37E */
#define sprite_list_06D3A8_ADDRESS 0x73A8u    /* 06D3A8 */
#define sprite_list_06D3CC_ADDRESS 0x73CCu    /* 06D3CC */
#define sprite_list_06D3F6_ADDRESS 0x73F6u    /* 06D3F6 */
#define animation_06D40E_ADDRESS 0x740Eu    /* 06D40E */
#define sprite_list_06D41A_ADDRESS 0x741Au    /* 06D41A */
#define sprite_list_06D432_ADDRESS 0x7432u    /* 06D432 */
#define animation_06D462_ADDRESS 0x7462u    /* 06D462 */
#define sprite_list_06D46E_ADDRESS 0x746Eu    /* 06D46E */
#define sprite_list_06D48C_ADDRESS 0x748Cu    /* 06D48C */
#define animation_06D4AA_ADDRESS 0x74AAu    /* 06D4AA */
#define sprite_list_06D4BE_ADDRESS 0x74BEu    /* 06D4BE */
#define sprite_list_06D4DC_ADDRESS 0x74DCu    /* 06D4DC */
#define sprite_list_06D4FA_ADDRESS 0x74FAu    /* 06D4FA */
#define animation_06D51E_ADDRESS 0x751Eu    /* 06D51E */
#define sprite_list_06D526_ADDRESS 0x7526u    /* 06D526 */
#define animation_06D556_ADDRESS 0x7556u    /* 06D556 */
#define sprite_list_06D562_ADDRESS 0x7562u    /* 06D562 */
#define sprite_list_06D580_ADDRESS 0x7580u    /* 06D580 */
#define animation_06D59E_ADDRESS 0x759Eu    /* 06D59E */
#define sprite_list_06D5BE_ADDRESS 0x75BEu    /* 06D5BE */
#define sprite_list_06D5D6_ADDRESS 0x75D6u    /* 06D5D6 */
#define sprite_list_06D5EE_ADDRESS 0x75EEu    /* 06D5EE */
#define sprite_list_06D606_ADDRESS 0x7606u    /* 06D606 */
#define animation_06D61E_ADDRESS 0x761Eu    /* 06D61E */
#define sprite_list_06D62A_ADDRESS 0x762Au    /* 06D62A */
#define sprite_list_06D642_ADDRESS 0x7642u    /* 06D642 */
#define animation_06D666_ADDRESS 0x7666u    /* 06D666 */
#define sprite_list_06D686_ADDRESS 0x7686u    /* 06D686 */
#define sprite_list_06D6AA_ADDRESS 0x76AAu    /* 06D6AA */
#define sprite_list_06D6C8_ADDRESS 0x76C8u    /* 06D6C8 */
#define animation_06D6E6_ADDRESS 0x76E6u    /* 06D6E6 */
#define sprite_list_06D716_ADDRESS 0x7716u    /* 06D716 */
#define sprite_list_06D734_ADDRESS 0x7734u    /* 06D734 */
#define sprite_list_06D752_ADDRESS 0x7752u    /* 06D752 */
#define sprite_list_06D770_ADDRESS 0x7770u    /* 06D770 */
#define animation_06D78E_ADDRESS 0x778Eu    /* 06D78E */
#define sprite_list_06D7AA_ADDRESS 0x77AAu    /* 06D7AA */
#define sprite_list_06D7C8_ADDRESS 0x77C8u    /* 06D7C8 */
#define animation_06D7E0_ADDRESS 0x77E0u    /* 06D7E0 */
#define sprite_list_06D7F4_ADDRESS 0x77F4u    /* 06D7F4 */
#define sprite_list_06D806_ADDRESS 0x7806u    /* 06D806 */
#define sprite_list_06D812_ADDRESS 0x7812u    /* 06D812 */
#define sprite_list_06D81E_ADDRESS 0x781Eu    /* 06D81E */
#define animation_06D830_ADDRESS 0x7830u    /* 06D830 */
#define sprite_list_06D844_ADDRESS 0x7844u    /* 06D844 */
#define sprite_list_06D862_ADDRESS 0x7862u    /* 06D862 */
#define sprite_list_06D88C_ADDRESS 0x788Cu    /* 06D88C */
#define sprite_list_06D8B0_ADDRESS 0x78B0u    /* 06D8B0 */
#define animation_06D8DA_ADDRESS 0x78DAu    /* 06D8DA */
#define sprite_list_06D8E2_ADDRESS 0x78E2u    /* 06D8E2 */
#define animation_06D900_ADDRESS 0x7900u    /* 06D900 */
#define sprite_list_06D910_ADDRESS 0x7910u    /* 06D910 */
#define sprite_list_06D91C_ADDRESS 0x791Cu    /* 06D91C */
#define sprite_list_06D928_ADDRESS 0x7928u    /* 06D928 */
#define animation_table_06D934_ADDRESS 0x7934u    /* 06D934 */
#define animation_table_06D9AA_ADDRESS 0x79AAu    /* 06D9AA */
#define animation_06D9B6_ADDRESS 0x79B6u    /* 06D9B6 */
#define sprite_list_06D9FA_ADDRESS 0x79FAu    /* 06D9FA */
#define sprite_list_06DA00_ADDRESS 0x7A00u    /* 06DA00 */
#define sprite_list_06DA06_ADDRESS 0x7A06u    /* 06DA06 */
#define sprite_list_06DA0C_ADDRESS 0x7A0Cu    /* 06DA0C */
#define sprite_list_06DA12_ADDRESS 0x7A12u    /* 06DA12 */
#define sprite_list_06DA18_ADDRESS 0x7A18u    /* 06DA18 */
#define sprite_list_06DA1E_ADDRESS 0x7A1Eu    /* 06DA1E */
#define sprite_list_06DA24_ADDRESS 0x7A24u    /* 06DA24 */
#define animation_06DA2A_ADDRESS 0x7A2Au    /* 06DA2A */
#define sprite_list_06DA6E_ADDRESS 0x7A6Eu    /* 06DA6E */
#define sprite_list_06DA74_ADDRESS 0x7A74u    /* 06DA74 */
#define sprite_list_06DA7A_ADDRESS 0x7A7Au    /* 06DA7A */
#define sprite_list_06DA80_ADDRESS 0x7A80u    /* 06DA80 */
#define sprite_list_06DA86_ADDRESS 0x7A86u    /* 06DA86 */
#define sprite_list_06DA8C_ADDRESS 0x7A8Cu    /* 06DA8C */
#define sprite_list_06DA92_ADDRESS 0x7A92u    /* 06DA92 */
#define sprite_list_06DA98_ADDRESS 0x7A98u    /* 06DA98 */
#define sprite_list_06DA9E_ADDRESS 0x7A9Eu    /* 06DA9E */
#define sprite_list_06DAA4_ADDRESS 0x7AA4u    /* 06DAA4 */
#define sprite_list_06DAAA_ADDRESS 0x7AAAu    /* 06DAAA */
#define animation_06DAB0_ADDRESS 0x7AB0u    /* 06DAB0 */
#define sprite_list_06DAD0_ADDRESS 0x7AD0u    /* 06DAD0 */
#define sprite_list_06DAD6_ADDRESS 0x7AD6u    /* 06DAD6 */
#define sprite_list_06DADC_ADDRESS 0x7ADCu    /* 06DADC */
#define sprite_list_06DAE2_ADDRESS 0x7AE2u    /* 06DAE2 */
#define sprite_list_06DAE8_ADDRESS 0x7AE8u    /* 06DAE8 */
#define sprite_list_06DAEE_ADDRESS 0x7AEEu    /* 06DAEE */
#define sprite_list_06DAFA_ADDRESS 0x7AFAu    /* 06DAFA */
#define animation_06DB00_ADDRESS 0x7B00u    /* 06DB00 */
#define sprite_list_06DB24_ADDRESS 0x7B24u    /* 06DB24 */
#define sprite_list_06DB36_ADDRESS 0x7B36u    /* 06DB36 */
#define animation_06DB48_ADDRESS 0x7B48u    /* 06DB48 */
#define sprite_list_06DB60_ADDRESS 0x7B60u    /* 06DB60 */
#define sprite_list_06DB72_ADDRESS 0x7B72u    /* 06DB72 */
#define sprite_list_06DB84_ADDRESS 0x7B84u    /* 06DB84 */
#define sprite_list_06DB96_ADDRESS 0x7B96u    /* 06DB96 */
#define sprite_list_06DBA8_ADDRESS 0x7BA8u    /* 06DBA8 */
#define animation_06DBBA_ADDRESS 0x7BBAu    /* 06DBBA */
#define sprite_list_06DBDE_ADDRESS 0x7BDEu    /* 06DBDE */
#define sprite_list_06DBEA_ADDRESS 0x7BEAu    /* 06DBEA */
#define sprite_list_06DBF6_ADDRESS 0x7BF6u    /* 06DBF6 */
#define animation_table_06DC1A_ADDRESS 0x7C1Au    /* 06DC1A */
#define animation_06DC20_ADDRESS 0x7C20u    /* 06DC20 */
#define sprite_list_06DC30_ADDRESS 0x7C30u    /* 06DC30 */
#define sprite_list_06DC48_ADDRESS 0x7C48u    /* 06DC48 */
#define sprite_list_06DC60_ADDRESS 0x7C60u    /* 06DC60 */
#define animation_06DC78_ADDRESS 0x7C78u    /* 06DC78 */
#define sprite_list_06DC8C_ADDRESS 0x7C8Cu    /* 06DC8C */
#define sprite_list_06DCAA_ADDRESS 0x7CAAu    /* 06DCAA */
#define animation_06DCC8_ADDRESS 0x7CC8u    /* 06DCC8 */
#define sprite_list_06DCDC_ADDRESS 0x7CDCu    /* 06DCDC */
#define sprite_list_06DCEE_ADDRESS 0x7CEEu    /* 06DCEE */
#define sprite_list_06DD00_ADDRESS 0x7D00u    /* 06DD00 */
#define sprite_list_06DD18_ADDRESS 0x7D18u    /* 06DD18 */
#define animation_table_06DD2A_ADDRESS 0x7D2Au    /* 06DD2A */
#define animation_06DD30_ADDRESS 0x7D30u    /* 06DD30 */
#define sprite_list_06DD80_ADDRESS 0x7D80u    /* 06DD80 */
#define sprite_list_06DD98_ADDRESS 0x7D98u    /* 06DD98 */
#define sprite_list_06DDAA_ADDRESS 0x7DAAu    /* 06DDAA */
#define sprite_list_06DDBC_ADDRESS 0x7DBCu    /* 06DDBC */
#define sprite_list_06DDD4_ADDRESS 0x7DD4u    /* 06DDD4 */
#define sprite_list_06DDF2_ADDRESS 0x7DF2u    /* 06DDF2 */
#define sprite_list_06DE10_ADDRESS 0x7E10u    /* 06DE10 */
#define animation_06DE28_ADDRESS 0x7E28u    /* 06DE28 */
#define sprite_list_06DE30_ADDRESS 0x7E30u    /* 06DE30 */
#define animation_06DE36_ADDRESS 0x7E36u    /* 06DE36 */
#define sprite_list_06DE46_ADDRESS 0x7E46u    /* 06DE46 */
#define sprite_list_06DE58_ADDRESS 0x7E58u    /* 06DE58 */
#define sprite_list_06DE70_ADDRESS 0x7E70u    /* 06DE70 */
#define fill_06DE88_ADDRESS 0x7E88u    /* 06DE88 */
#define set_index_06E000_ADDRESS 0x6000u    /* 06E000 */
#define animation_table_06E008_ADDRESS 0x6008u    /* 06E008 */
#define animation_06E01E_ADDRESS 0x601Eu    /* 06E01E */
#define sprite_list_06E02E_ADDRESS 0x602Eu    /* 06E02E */
#define sprite_list_06E064_ADDRESS 0x6064u    /* 06E064 */
#define sprite_list_06E09A_ADDRESS 0x609Au    /* 06E09A */
#define animation_06E0D0_ADDRESS 0x60D0u    /* 06E0D0 */
#define sprite_list_06E0E4_ADDRESS 0x60E4u    /* 06E0E4 */
#define sprite_list_06E132_ADDRESS 0x6132u    /* 06E132 */
#define sprite_list_06E180_ADDRESS 0x6180u    /* 06E180 */
#define animation_06E1CE_ADDRESS 0x61CEu    /* 06E1CE */
#define sprite_list_06E1D6_ADDRESS 0x61D6u    /* 06E1D6 */
#define animation_06E230_ADDRESS 0x6230u    /* 06E230 */
#define sprite_list_06E238_ADDRESS 0x6238u    /* 06E238 */
#define animation_06E292_ADDRESS 0x6292u    /* 06E292 */
#define sprite_list_06E2C6_ADDRESS 0x62C6u    /* 06E2C6 */
#define sprite_list_06E2FC_ADDRESS 0x62FCu    /* 06E2FC */
#define sprite_list_06E332_ADDRESS 0x6332u    /* 06E332 */
#define sprite_list_06E368_ADDRESS 0x6368u    /* 06E368 */
#define sprite_list_06E39E_ADDRESS 0x639Eu    /* 06E39E */
#define sprite_list_06E3D4_ADDRESS 0x63D4u    /* 06E3D4 */
#define sprite_list_06E40A_ADDRESS 0x640Au    /* 06E40A */
#define animation_06E446_ADDRESS 0x6446u    /* 06E446 */
#define sprite_list_06E456_ADDRESS 0x6456u    /* 06E456 */
#define sprite_list_06E4A4_ADDRESS 0x64A4u    /* 06E4A4 */
#define animation_06E4F2_ADDRESS 0x64F2u    /* 06E4F2 */
#define sprite_list_06E502_ADDRESS 0x6502u    /* 06E502 */
#define sprite_list_06E508_ADDRESS 0x6508u    /* 06E508 */
#define sprite_list_06E50E_ADDRESS 0x650Eu    /* 06E50E */
#define animation_06E514_ADDRESS 0x6514u    /* 06E514 */
#define sprite_list_06E528_ADDRESS 0x6528u    /* 06E528 */
#define animation_06E52E_ADDRESS 0x652Eu    /* 06E52E */
#define sprite_list_06E536_ADDRESS 0x6536u    /* 06E536 */
#define animation_06E590_ADDRESS 0x6590u    /* 06E590 */
#define sprite_list_06E5C4_ADDRESS 0x65C4u    /* 06E5C4 */
#define sprite_list_06E5FA_ADDRESS 0x65FAu    /* 06E5FA */
#define sprite_list_06E630_ADDRESS 0x6630u    /* 06E630 */
#define sprite_list_06E666_ADDRESS 0x6666u    /* 06E666 */
#define sprite_list_06E69C_ADDRESS 0x669Cu    /* 06E69C */
#define sprite_list_06E6D2_ADDRESS 0x66D2u    /* 06E6D2 */
#define sprite_list_06E708_ADDRESS 0x6708u    /* 06E708 */
#define animation_06E744_ADDRESS 0x6744u    /* 06E744 */
#define sprite_list_06E76C_ADDRESS 0x676Cu    /* 06E76C */
#define sprite_list_06E7BA_ADDRESS 0x67BAu    /* 06E7BA */
#define sprite_list_06E808_ADDRESS 0x6808u    /* 06E808 */
#define sprite_list_06E856_ADDRESS 0x6856u    /* 06E856 */
#define sprite_list_06E8A4_ADDRESS 0x68A4u    /* 06E8A4 */
#define animation_table_06E8FE_ADDRESS 0x68FEu    /* 06E8FE */
#define animation_06E90C_ADDRESS 0x690Cu    /* 06E90C */
#define sprite_list_06E91C_ADDRESS 0x691Cu    /* 06E91C */
#define sprite_list_06E92E_ADDRESS 0x692Eu    /* 06E92E */
#define sprite_list_06E946_ADDRESS 0x6946u    /* 06E946 */
#define animation_06E95E_ADDRESS 0x695Eu    /* 06E95E */
#define sprite_list_06E96A_ADDRESS 0x696Au    /* 06E96A */
#define sprite_list_06E97C_ADDRESS 0x697Cu    /* 06E97C */
#define animation_06E988_ADDRESS 0x6988u    /* 06E988 */
#define sprite_list_06E998_ADDRESS 0x6998u    /* 06E998 */
#define sprite_list_06E9B6_ADDRESS 0x69B6u    /* 06E9B6 */
#define sprite_list_06E9C8_ADDRESS 0x69C8u    /* 06E9C8 */
#define animation_06E9DA_ADDRESS 0x69DAu    /* 06E9DA */
#define sprite_list_06E9EE_ADDRESS 0x69EEu    /* 06E9EE */
#define animation_06E9FA_ADDRESS 0x69FAu    /* 06E9FA */
#define animation_06EA06_ADDRESS 0x6A06u    /* 06EA06 */
#define sprite_list_06EA1A_ADDRESS 0x6A1Au    /* 06EA1A */
#define sprite_list_06EA4A_ADDRESS 0x6A4Au    /* 06EA4A */
#define animation_06EA80_ADDRESS 0x6A80u    /* 06EA80 */
#define sprite_list_06EA88_ADDRESS 0x6A88u    /* 06EA88 */
#define animation_table_06EA8E_ADDRESS 0x6A8Eu    /* 06EA8E */
#define animation_06EACC_ADDRESS 0x6ACCu    /* 06EACC */
#define sprite_list_06EB00_ADDRESS 0x6B00u    /* 06EB00 */
#define sprite_list_06EB24_ADDRESS 0x6B24u    /* 06EB24 */
#define sprite_list_06EB48_ADDRESS 0x6B48u    /* 06EB48 */
#define sprite_list_06EB6C_ADDRESS 0x6B6Cu    /* 06EB6C */
#define sprite_list_06EB90_ADDRESS 0x6B90u    /* 06EB90 */
#define sprite_list_06EBB4_ADDRESS 0x6BB4u    /* 06EBB4 */
#define sprite_list_06EBD8_ADDRESS 0x6BD8u    /* 06EBD8 */
#define sprite_list_06EBFC_ADDRESS 0x6BFCu    /* 06EBFC */
#define sprite_list_06EC20_ADDRESS 0x6C20u    /* 06EC20 */
#define sprite_list_06EC44_ADDRESS 0x6C44u    /* 06EC44 */
#define sprite_list_06EC68_ADDRESS 0x6C68u    /* 06EC68 */
#define sprite_list_06EC8C_ADDRESS 0x6C8Cu    /* 06EC8C */
#define animation_06ECB0_ADDRESS 0x6CB0u    /* 06ECB0 */
#define sprite_list_06ECD4_ADDRESS 0x6CD4u    /* 06ECD4 */
#define sprite_list_06ECF2_ADDRESS 0x6CF2u    /* 06ECF2 */
#define sprite_list_06ED16_ADDRESS 0x6D16u    /* 06ED16 */
#define sprite_list_06ED3A_ADDRESS 0x6D3Au    /* 06ED3A */
#define sprite_list_06ED5E_ADDRESS 0x6D5Eu    /* 06ED5E */
#define sprite_list_06ED82_ADDRESS 0x6D82u    /* 06ED82 */
#define sprite_list_06EDA6_ADDRESS 0x6DA6u    /* 06EDA6 */
#define sprite_list_06EDCA_ADDRESS 0x6DCAu    /* 06EDCA */
#define animation_06EDEE_ADDRESS 0x6DEEu    /* 06EDEE */
#define sprite_list_06EE1A_ADDRESS 0x6E1Au    /* 06EE1A */
#define sprite_list_06EE3E_ADDRESS 0x6E3Eu    /* 06EE3E */
#define sprite_list_06EE62_ADDRESS 0x6E62u    /* 06EE62 */
#define sprite_list_06EE86_ADDRESS 0x6E86u    /* 06EE86 */
#define sprite_list_06EEAA_ADDRESS 0x6EAAu    /* 06EEAA */
#define sprite_list_06EECE_ADDRESS 0x6ECEu    /* 06EECE */
#define sprite_list_06EEF2_ADDRESS 0x6EF2u    /* 06EEF2 */
#define sprite_list_06EF16_ADDRESS 0x6F16u    /* 06EF16 */
#define sprite_list_06EF3A_ADDRESS 0x6F3Au    /* 06EF3A */
#define sprite_list_06EF5E_ADDRESS 0x6F5Eu    /* 06EF5E */
#define animation_06EF82_ADDRESS 0x6F82u    /* 06EF82 */
#define sprite_list_06EFAE_ADDRESS 0x6FAEu    /* 06EFAE */
#define sprite_list_06EFD8_ADDRESS 0x6FD8u    /* 06EFD8 */
#define sprite_list_06F002_ADDRESS 0x7002u    /* 06F002 */
#define sprite_list_06F02C_ADDRESS 0x702Cu    /* 06F02C */
#define sprite_list_06F056_ADDRESS 0x7056u    /* 06F056 */
#define sprite_list_06F080_ADDRESS 0x7080u    /* 06F080 */
#define sprite_list_06F0B0_ADDRESS 0x70B0u    /* 06F0B0 */
#define animation_06F0E6_ADDRESS 0x70E6u    /* 06F0E6 */
#define sprite_list_06F112_ADDRESS 0x7112u    /* 06F112 */
#define sprite_list_06F13C_ADDRESS 0x713Cu    /* 06F13C */
#define sprite_list_06F166_ADDRESS 0x7166u    /* 06F166 */
#define sprite_list_06F190_ADDRESS 0x7190u    /* 06F190 */
#define sprite_list_06F1BA_ADDRESS 0x71BAu    /* 06F1BA */
#define sprite_list_06F1E4_ADDRESS 0x71E4u    /* 06F1E4 */
#define sprite_list_06F214_ADDRESS 0x7214u    /* 06F214 */
#define animation_06F24A_ADDRESS 0x724Au    /* 06F24A */
#define sprite_list_06F252_ADDRESS 0x7252u    /* 06F252 */
#define animation_06F258_ADDRESS 0x7258u    /* 06F258 */
#define sprite_list_06F260_ADDRESS 0x7260u    /* 06F260 */
#define animation_06F266_ADDRESS 0x7266u    /* 06F266 */
#define sprite_list_06F26E_ADDRESS 0x726Eu    /* 06F26E */
#define animation_06F274_ADDRESS 0x7274u    /* 06F274 */
#define sprite_list_06F27C_ADDRESS 0x727Cu    /* 06F27C */
#define animation_06F2A0_ADDRESS 0x72A0u    /* 06F2A0 */
#define animation_06F2D4_ADDRESS 0x72D4u    /* 06F2D4 */
#define sprite_list_06F2E0_ADDRESS 0x72E0u    /* 06F2E0 */
#define sprite_list_06F2EC_ADDRESS 0x72ECu    /* 06F2EC */
#define animation_06F2F8_ADDRESS 0x72F8u    /* 06F2F8 */
#define sprite_list_06F314_ADDRESS 0x7314u    /* 06F314 */
#define sprite_list_06F320_ADDRESS 0x7320u    /* 06F320 */
#define sprite_list_06F32C_ADDRESS 0x732Cu    /* 06F32C */
#define sprite_list_06F338_ADDRESS 0x7338u    /* 06F338 */
#define animation_06F344_ADDRESS 0x7344u    /* 06F344 */
#define sprite_list_06F350_ADDRESS 0x7350u    /* 06F350 */
#define sprite_list_06F356_ADDRESS 0x7356u    /* 06F356 */
#define animation_06F35C_ADDRESS 0x735Cu    /* 06F35C */
#define sprite_list_06F364_ADDRESS 0x7364u    /* 06F364 */
#define animation_06F36A_ADDRESS 0x736Au    /* 06F36A */
#define sprite_list_06F372_ADDRESS 0x7372u    /* 06F372 */
#define animation_06F378_ADDRESS 0x7378u    /* 06F378 */
#define sprite_list_06F3A8_ADDRESS 0x73A8u    /* 06F3A8 */
#define sprite_list_06F3CC_ADDRESS 0x73CCu    /* 06F3CC */
#define sprite_list_06F3F0_ADDRESS 0x73F0u    /* 06F3F0 */
#define sprite_list_06F41A_ADDRESS 0x741Au    /* 06F41A */
#define sprite_list_06F444_ADDRESS 0x7444u    /* 06F444 */
#define sprite_list_06F46E_ADDRESS 0x746Eu    /* 06F46E */
#define sprite_list_06F49E_ADDRESS 0x749Eu    /* 06F49E */
#define sprite_list_06F4D4_ADDRESS 0x74D4u    /* 06F4D4 */
#define sprite_list_06F504_ADDRESS 0x7504u    /* 06F504 */
#define sprite_list_06F52E_ADDRESS 0x752Eu    /* 06F52E */
#define sprite_list_06F558_ADDRESS 0x7558u    /* 06F558 */
#define animation_06F57C_ADDRESS 0x757Cu    /* 06F57C */
#define sprite_list_06F5AC_ADDRESS 0x75ACu    /* 06F5AC */
#define sprite_list_06F5D6_ADDRESS 0x75D6u    /* 06F5D6 */
#define sprite_list_06F600_ADDRESS 0x7600u    /* 06F600 */
#define sprite_list_06F62A_ADDRESS 0x762Au    /* 06F62A */
#define sprite_list_06F654_ADDRESS 0x7654u    /* 06F654 */
#define sprite_list_06F67E_ADDRESS 0x767Eu    /* 06F67E */
#define sprite_list_06F6AE_ADDRESS 0x76AEu    /* 06F6AE */
#define sprite_list_06F6E4_ADDRESS 0x76E4u    /* 06F6E4 */
#define sprite_list_06F714_ADDRESS 0x7714u    /* 06F714 */
#define sprite_list_06F73E_ADDRESS 0x773Eu    /* 06F73E */
#define sprite_list_06F768_ADDRESS 0x7768u    /* 06F768 */
#define animation_table_06F78C_ADDRESS 0x778Cu    /* 06F78C */
#define animation_06F7B4_ADDRESS 0x77B4u    /* 06F7B4 */
#define sprite_list_06F7D8_ADDRESS 0x77D8u    /* 06F7D8 */
#define sprite_list_06F7E4_ADDRESS 0x77E4u    /* 06F7E4 */
#define sprite_list_06F7F6_ADDRESS 0x77F6u    /* 06F7F6 */
#define sprite_list_06F80E_ADDRESS 0x780Eu    /* 06F80E */
#define sprite_list_06F820_ADDRESS 0x7820u    /* 06F820 */
#define sprite_list_06F82C_ADDRESS 0x782Cu    /* 06F82C */
#define sprite_list_06F83E_ADDRESS 0x783Eu    /* 06F83E */
#define sprite_list_06F84A_ADDRESS 0x784Au    /* 06F84A */
#define animation_06F856_ADDRESS 0x7856u    /* 06F856 */
#define sprite_list_06F876_ADDRESS 0x7876u    /* 06F876 */
#define sprite_list_06F88E_ADDRESS 0x788Eu    /* 06F88E */
#define sprite_list_06F8A0_ADDRESS 0x78A0u    /* 06F8A0 */
#define sprite_list_06F8B8_ADDRESS 0x78B8u    /* 06F8B8 */
#define sprite_list_06F8D6_ADDRESS 0x78D6u    /* 06F8D6 */
#define sprite_list_06F8EE_ADDRESS 0x78EEu    /* 06F8EE */
#define sprite_list_06F906_ADDRESS 0x7906u    /* 06F906 */
#define animation_06F918_ADDRESS 0x7918u    /* 06F918 */
#define sprite_list_06F93C_ADDRESS 0x793Cu    /* 06F93C */
#define sprite_list_06F942_ADDRESS 0x7942u    /* 06F942 */
#define sprite_list_06F94E_ADDRESS 0x794Eu    /* 06F94E */
#define sprite_list_06F960_ADDRESS 0x7960u    /* 06F960 */
#define animation_06F972_ADDRESS 0x7972u    /* 06F972 */
#define sprite_list_06F982_ADDRESS 0x7982u    /* 06F982 */
#define sprite_list_06F994_ADDRESS 0x7994u    /* 06F994 */
#define sprite_list_06F9A0_ADDRESS 0x79A0u    /* 06F9A0 */
#define animation_06F9AC_ADDRESS 0x79ACu    /* 06F9AC */
#define sprite_list_06F9CC_ADDRESS 0x79CCu    /* 06F9CC */
#define sprite_list_06F9D8_ADDRESS 0x79D8u    /* 06F9D8 */
#define sprite_list_06F9E4_ADDRESS 0x79E4u    /* 06F9E4 */
#define sprite_list_06F9F0_ADDRESS 0x79F0u    /* 06F9F0 */
#define animation_06F9FC_ADDRESS 0x79FCu    /* 06F9FC */
#define sprite_list_06FA30_ADDRESS 0x7A30u    /* 06FA30 */
#define sprite_list_06FA48_ADDRESS 0x7A48u    /* 06FA48 */
#define sprite_list_06FA60_ADDRESS 0x7A60u    /* 06FA60 */
#define sprite_list_06FA78_ADDRESS 0x7A78u    /* 06FA78 */
#define sprite_list_06FA90_ADDRESS 0x7A90u    /* 06FA90 */
#define sprite_list_06FAA8_ADDRESS 0x7AA8u    /* 06FAA8 */
#define sprite_list_06FABA_ADDRESS 0x7ABAu    /* 06FABA */
#define animation_06FACC_ADDRESS 0x7ACCu    /* 06FACC */
#define sprite_list_06FADC_ADDRESS 0x7ADCu    /* 06FADC */
#define sprite_list_06FAF4_ADDRESS 0x7AF4u    /* 06FAF4 */
#define sprite_list_06FB0C_ADDRESS 0x7B0Cu    /* 06FB0C */
#define animation_06FB24_ADDRESS 0x7B24u    /* 06FB24 */
#define sprite_list_06FB30_ADDRESS 0x7B30u    /* 06FB30 */
#define fill_06FB48_ADDRESS 0x7B48u    /* 06FB48 */
#define unreached_animation_06FC3E_ADDRESS 0x7C3Eu    /* 06FC3E */
#define sprite_list_06FC5A_ADDRESS 0x7C5Au    /* 06FC5A */
#define sprite_list_06FC78_ADDRESS 0x7C78u    /* 06FC78 */
#define sprite_list_06FC96_ADDRESS 0x7C96u    /* 06FC96 */
#define sprite_list_06FCB4_ADDRESS 0x7CB4u    /* 06FCB4 */
#define sprite_list_06FCD2_ADDRESS 0x7CD2u    /* 06FCD2 */
#define sprite_list_06FCF0_ADDRESS 0x7CF0u    /* 06FCF0 */
#define unreached_animation_06FD0E_ADDRESS 0x7D0Eu    /* 06FD0E */
#define sprite_list_06FD16_ADDRESS 0x7D16u    /* 06FD16 */
#define fill_06FD34_ADDRESS 0x7D34u    /* 06FD34 */
#define unreached_animation_06FD38_ADDRESS 0x7D38u    /* 06FD38 */
#define sprite_list_06FD4C_ADDRESS 0x7D4Cu    /* 06FD4C */
#define sprite_list_06FD5E_ADDRESS 0x7D5Eu    /* 06FD5E */
#define sprite_list_06FD76_ADDRESS 0x7D76u    /* 06FD76 */
#define sprite_list_06FD8E_ADDRESS 0x7D8Eu    /* 06FD8E */
#define unreached_animation_06FDAC_ADDRESS 0x7DACu    /* 06FDAC */
#define sprite_list_06FDC0_ADDRESS 0x7DC0u    /* 06FDC0 */
#define sprite_list_06FDD2_ADDRESS 0x7DD2u    /* 06FDD2 */
#define sprite_list_06FDE4_ADDRESS 0x7DE4u    /* 06FDE4 */
#define sprite_list_06FDF6_ADDRESS 0x7DF6u    /* 06FDF6 */
#define fill_06FE08_ADDRESS 0x7E08u    /* 06FE08 */
#define unreached_animation_06FE74_ADDRESS 0x7E74u    /* 06FE74 */
#define sprite_list_06FE84_ADDRESS 0x7E84u    /* 06FE84 */
#define sprite_list_06FE96_ADDRESS 0x7E96u    /* 06FE96 */
#define sprite_list_06FEBA_ADDRESS 0x7EBAu    /* 06FEBA */
#define fill_06FEE4_ADDRESS 0x7EE4u    /* 06FEE4 */
#define set_index_070000_ADDRESS 0x6000u    /* 070000 */
#define animation_table_070012_ADDRESS 0x6012u    /* 070012 */
#define animation_07001C_ADDRESS 0x601Cu    /* 07001C */
#define animation_070024_ADDRESS 0x6024u    /* 070024 */
#define sprite_list_070038_ADDRESS 0x6038u    /* 070038 */
#define sprite_list_070044_ADDRESS 0x6044u    /* 070044 */
#define sprite_list_070050_ADDRESS 0x6050u    /* 070050 */
#define sprite_list_07005C_ADDRESS 0x605Cu    /* 07005C */
#define animation_070068_ADDRESS 0x6068u    /* 070068 */
#define sprite_list_07007C_ADDRESS 0x607Cu    /* 07007C */
#define sprite_list_070088_ADDRESS 0x6088u    /* 070088 */
#define sprite_list_070094_ADDRESS 0x6094u    /* 070094 */
#define sprite_list_0700A0_ADDRESS 0x60A0u    /* 0700A0 */
#define animation_0700AC_ADDRESS 0x60ACu    /* 0700AC */
#define sprite_list_0700B8_ADDRESS 0x60B8u    /* 0700B8 */
#define sprite_list_0700CA_ADDRESS 0x60CAu    /* 0700CA */
#define animation_0700DC_ADDRESS 0x60DCu    /* 0700DC */
#define sprite_list_0700E4_ADDRESS 0x60E4u    /* 0700E4 */
#define animation_table_0700F6_ADDRESS 0x60F6u    /* 0700F6 */
#define animation_070116_ADDRESS 0x6116u    /* 070116 */
#define sprite_list_070142_ADDRESS 0x6142u    /* 070142 */
#define sprite_list_07015A_ADDRESS 0x615Au    /* 07015A */
#define sprite_list_07017E_ADDRESS 0x617Eu    /* 07017E */
#define sprite_list_0701B4_ADDRESS 0x61B4u    /* 0701B4 */
#define sprite_list_0701D8_ADDRESS 0x61D8u    /* 0701D8 */
#define sprite_list_070202_ADDRESS 0x6202u    /* 070202 */
#define sprite_list_070226_ADDRESS 0x6226u    /* 070226 */
#define sprite_list_070256_ADDRESS 0x6256u    /* 070256 */
#define sprite_list_070286_ADDRESS 0x6286u    /* 070286 */
#define sprite_list_0702AA_ADDRESS 0x62AAu    /* 0702AA */
#define animation_0702CE_ADDRESS 0x62CEu    /* 0702CE */
#define sprite_list_0702DE_ADDRESS 0x62DEu    /* 0702DE */
#define sprite_list_07032C_ADDRESS 0x632Cu    /* 07032C */
#define animation_07035C_ADDRESS 0x635Cu    /* 07035C */
#define sprite_list_070378_ADDRESS 0x6378u    /* 070378 */
#define sprite_list_07039C_ADDRESS 0x639Cu    /* 07039C */
#define sprite_list_0703BA_ADDRESS 0x63BAu    /* 0703BA */
#define sprite_list_0703DE_ADDRESS 0x63DEu    /* 0703DE */
#define sprite_list_070402_ADDRESS 0x6402u    /* 070402 */
#define sprite_list_070420_ADDRESS 0x6420u    /* 070420 */
#define animation_070438_ADDRESS 0x6438u    /* 070438 */
#define sprite_list_070448_ADDRESS 0x6448u    /* 070448 */
#define sprite_list_070472_ADDRESS 0x6472u    /* 070472 */
#define sprite_list_070496_ADDRESS 0x6496u    /* 070496 */
#define animation_0704AE_ADDRESS 0x64AEu    /* 0704AE */
#define sprite_list_0704BA_ADDRESS 0x64BAu    /* 0704BA */
#define sprite_list_0704D8_ADDRESS 0x64D8u    /* 0704D8 */
#define animation_0704F6_ADDRESS 0x64F6u    /* 0704F6 */
#define sprite_list_070502_ADDRESS 0x6502u    /* 070502 */
#define sprite_list_070526_ADDRESS 0x6526u    /* 070526 */
#define animation_070544_ADDRESS 0x6544u    /* 070544 */
#define sprite_list_070550_ADDRESS 0x6550u    /* 070550 */
#define sprite_list_070574_ADDRESS 0x6574u    /* 070574 */
#define animation_070598_ADDRESS 0x6598u    /* 070598 */
#define sprite_list_0705AC_ADDRESS 0x65ACu    /* 0705AC */
#define sprite_list_0705C4_ADDRESS 0x65C4u    /* 0705C4 */
#define sprite_list_0705D6_ADDRESS 0x65D6u    /* 0705D6 */
#define animation_0705EE_ADDRESS 0x65EEu    /* 0705EE */
#define sprite_list_0705FA_ADDRESS 0x65FAu    /* 0705FA */
#define sprite_list_070618_ADDRESS 0x6618u    /* 070618 */
#define animation_07063C_ADDRESS 0x663Cu    /* 07063C */
#define sprite_list_070644_ADDRESS 0x6644u    /* 070644 */
#define animation_070680_ADDRESS 0x6680u    /* 070680 */
#define sprite_list_070694_ADDRESS 0x6694u    /* 070694 */
#define sprite_list_0706DC_ADDRESS 0x66DCu    /* 0706DC */
#define sprite_list_07071E_ADDRESS 0x671Eu    /* 07071E */
#define animation_070760_ADDRESS 0x6760u    /* 070760 */
#define sprite_list_07076C_ADDRESS 0x676Cu    /* 07076C */
#define sprite_list_07078A_ADDRESS 0x678Au    /* 07078A */
#define animation_0707AE_ADDRESS 0x67AEu    /* 0707AE */
#define sprite_list_0707BA_ADDRESS 0x67BAu    /* 0707BA */
#define animation_0707D8_ADDRESS 0x67D8u    /* 0707D8 */
#define sprite_list_0707E4_ADDRESS 0x67E4u    /* 0707E4 */
#define sprite_list_070826_ADDRESS 0x6826u    /* 070826 */
#define animation_070868_ADDRESS 0x6868u    /* 070868 */
#define sprite_list_070874_ADDRESS 0x6874u    /* 070874 */
#define animation_0708B6_ADDRESS 0x68B6u    /* 0708B6 */
#define sprite_list_0708C2_ADDRESS 0x68C2u    /* 0708C2 */
#define sprite_list_070904_ADDRESS 0x6904u    /* 070904 */
#define animation_table_070952_ADDRESS 0x6952u    /* 070952 */
#define animation_070958_ADDRESS 0x6958u    /* 070958 */
#define sprite_list_070964_ADDRESS 0x6964u    /* 070964 */
#define sprite_list_070976_ADDRESS 0x6976u    /* 070976 */
#define animation_07098E_ADDRESS 0x698Eu    /* 07098E */
#define sprite_list_0709A2_ADDRESS 0x69A2u    /* 0709A2 */
#define sprite_list_0709B4_ADDRESS 0x69B4u    /* 0709B4 */
#define sprite_list_0709D2_ADDRESS 0x69D2u    /* 0709D2 */
#define animation_0709F0_ADDRESS 0x69F0u    /* 0709F0 */
#define sprite_list_0709FC_ADDRESS 0x69FCu    /* 0709FC */
#define animation_table_070A0E_ADDRESS 0x6A0Eu    /* 070A0E */
#define animation_070A3A_ADDRESS 0x6A3Au    /* 070A3A */
#define sprite_list_070A42_ADDRESS 0x6A42u    /* 070A42 */
#define animation_070A54_ADDRESS 0x6A54u    /* 070A54 */
#define sprite_list_070A78_ADDRESS 0x6A78u    /* 070A78 */
#define sprite_list_070A8A_ADDRESS 0x6A8Au    /* 070A8A */
#define sprite_list_070A96_ADDRESS 0x6A96u    /* 070A96 */
#define sprite_list_070AA2_ADDRESS 0x6AA2u    /* 070AA2 */
#define sprite_list_070ABA_ADDRESS 0x6ABAu    /* 070ABA */
#define sprite_list_070ACC_ADDRESS 0x6ACCu    /* 070ACC */
#define sprite_list_070AD8_ADDRESS 0x6AD8u    /* 070AD8 */
#define sprite_list_070AF0_ADDRESS 0x6AF0u    /* 070AF0 */
#define animation_070B08_ADDRESS 0x6B08u    /* 070B08 */
#define sprite_list_070B14_ADDRESS 0x6B14u    /* 070B14 */
#define sprite_list_070B26_ADDRESS 0x6B26u    /* 070B26 */
#define animation_070B38_ADDRESS 0x6B38u    /* 070B38 */
#define sprite_list_070B58_ADDRESS 0x6B58u    /* 070B58 */
#define sprite_list_070B70_ADDRESS 0x6B70u    /* 070B70 */
#define sprite_list_070B82_ADDRESS 0x6B82u    /* 070B82 */
#define sprite_list_070B9A_ADDRESS 0x6B9Au    /* 070B9A */
#define animation_070BA6_ADDRESS 0x6BA6u    /* 070BA6 */
#define sprite_list_070BC6_ADDRESS 0x6BC6u    /* 070BC6 */
#define sprite_list_070BDE_ADDRESS 0x6BDEu    /* 070BDE */
#define animation_070BF0_ADDRESS 0x6BF0u    /* 070BF0 */
#define sprite_list_070C28_ADDRESS 0x6C28u    /* 070C28 */
#define sprite_list_070C40_ADDRESS 0x6C40u    /* 070C40 */
#define sprite_list_070C52_ADDRESS 0x6C52u    /* 070C52 */
#define sprite_list_070C64_ADDRESS 0x6C64u    /* 070C64 */
#define sprite_list_070C76_ADDRESS 0x6C76u    /* 070C76 */
#define sprite_list_070C8E_ADDRESS 0x6C8Eu    /* 070C8E */
#define sprite_list_070CA6_ADDRESS 0x6CA6u    /* 070CA6 */
#define sprite_list_070CB8_ADDRESS 0x6CB8u    /* 070CB8 */
#define sprite_list_070CD0_ADDRESS 0x6CD0u    /* 070CD0 */
#define sprite_list_070CE8_ADDRESS 0x6CE8u    /* 070CE8 */
#define sprite_list_070D00_ADDRESS 0x6D00u    /* 070D00 */
#define sprite_list_070D12_ADDRESS 0x6D12u    /* 070D12 */
#define sprite_list_070D2A_ADDRESS 0x6D2Au    /* 070D2A */
#define animation_070D42_ADDRESS 0x6D42u    /* 070D42 */
#define sprite_list_070D4A_ADDRESS 0x6D4Au    /* 070D4A */
#define animation_070D50_ADDRESS 0x6D50u    /* 070D50 */
#define animation_070D68_ADDRESS 0x6D68u    /* 070D68 */
#define sprite_list_070DB0_ADDRESS 0x6DB0u    /* 070DB0 */
#define animation_070DCE_ADDRESS 0x6DCEu    /* 070DCE */
#define sprite_list_070DFE_ADDRESS 0x6DFEu    /* 070DFE */
#define sprite_list_070E10_ADDRESS 0x6E10u    /* 070E10 */
#define sprite_list_070E28_ADDRESS 0x6E28u    /* 070E28 */
#define sprite_list_070E40_ADDRESS 0x6E40u    /* 070E40 */
#define sprite_list_070E58_ADDRESS 0x6E58u    /* 070E58 */
#define sprite_list_070E6A_ADDRESS 0x6E6Au    /* 070E6A */
#define sprite_list_070E82_ADDRESS 0x6E82u    /* 070E82 */
#define sprite_list_070E9A_ADDRESS 0x6E9Au    /* 070E9A */
#define animation_070EB2_ADDRESS 0x6EB2u    /* 070EB2 */
#define sprite_list_070EE2_ADDRESS 0x6EE2u    /* 070EE2 */
#define sprite_list_070EFA_ADDRESS 0x6EFAu    /* 070EFA */
#define sprite_list_070F0C_ADDRESS 0x6F0Cu    /* 070F0C */
#define sprite_list_070F1E_ADDRESS 0x6F1Eu    /* 070F1E */
#define animation_070F30_ADDRESS 0x6F30u    /* 070F30 */
#define sprite_list_070F38_ADDRESS 0x6F38u    /* 070F38 */
#define animation_table_070F44_ADDRESS 0x6F44u    /* 070F44 */
#define animation_070F70_ADDRESS 0x6F70u    /* 070F70 */
#define sprite_list_070F7C_ADDRESS 0x6F7Cu    /* 070F7C */
#define sprite_list_070F88_ADDRESS 0x6F88u    /* 070F88 */
#define animation_070F8E_ADDRESS 0x6F8Eu    /* 070F8E */
#define sprite_list_070FAA_ADDRESS 0x6FAAu    /* 070FAA */
#define sprite_list_070FB0_ADDRESS 0x6FB0u    /* 070FB0 */
#define sprite_list_070FC2_ADDRESS 0x6FC2u    /* 070FC2 */
#define sprite_list_070FC8_ADDRESS 0x6FC8u    /* 070FC8 */
#define sprite_list_070FCE_ADDRESS 0x6FCEu    /* 070FCE */
#define sprite_list_070FD4_ADDRESS 0x6FD4u    /* 070FD4 */
#define animation_070FE6_ADDRESS 0x6FE6u    /* 070FE6 */
#define sprite_list_07100A_ADDRESS 0x700Au    /* 07100A */
#define sprite_list_07101C_ADDRESS 0x701Cu    /* 07101C */
#define sprite_list_07102E_ADDRESS 0x702Eu    /* 07102E */
#define sprite_list_071046_ADDRESS 0x7046u    /* 071046 */
#define sprite_list_071064_ADDRESS 0x7064u    /* 071064 */
#define sprite_list_071076_ADDRESS 0x7076u    /* 071076 */
#define sprite_list_071088_ADDRESS 0x7088u    /* 071088 */
#define sprite_list_0710A0_ADDRESS 0x70A0u    /* 0710A0 */
#define animation_0710BE_ADDRESS 0x70BEu    /* 0710BE */
#define sprite_list_0710DA_ADDRESS 0x70DAu    /* 0710DA */
#define sprite_list_0710FE_ADDRESS 0x70FEu    /* 0710FE */
#define sprite_list_07111C_ADDRESS 0x711Cu    /* 07111C */
#define sprite_list_071134_ADDRESS 0x7134u    /* 071134 */
#define sprite_list_071152_ADDRESS 0x7152u    /* 071152 */
#define sprite_list_071170_ADDRESS 0x7170u    /* 071170 */
#define animation_07118E_ADDRESS 0x718Eu    /* 07118E */
#define sprite_list_0711AA_ADDRESS 0x71AAu    /* 0711AA */
#define sprite_list_0711C8_ADDRESS 0x71C8u    /* 0711C8 */
#define sprite_list_0711E6_ADDRESS 0x71E6u    /* 0711E6 */
#define sprite_list_07120A_ADDRESS 0x720Au    /* 07120A */
#define sprite_list_071234_ADDRESS 0x7234u    /* 071234 */
#define sprite_list_071258_ADDRESS 0x7258u    /* 071258 */
#define animation_071282_ADDRESS 0x7282u    /* 071282 */
#define sprite_list_07129E_ADDRESS 0x729Eu    /* 07129E */
#define sprite_list_0712C2_ADDRESS 0x72C2u    /* 0712C2 */
#define sprite_list_0712E0_ADDRESS 0x72E0u    /* 0712E0 */
#define sprite_list_071304_ADDRESS 0x7304u    /* 071304 */
#define sprite_list_071328_ADDRESS 0x7328u    /* 071328 */
#define sprite_list_07134C_ADDRESS 0x734Cu    /* 07134C */
#define animation_071370_ADDRESS 0x7370u    /* 071370 */
#define sprite_list_07138C_ADDRESS 0x738Cu    /* 07138C */
#define sprite_list_0713B0_ADDRESS 0x73B0u    /* 0713B0 */
#define sprite_list_0713D4_ADDRESS 0x73D4u    /* 0713D4 */
#define sprite_list_0713FE_ADDRESS 0x73FEu    /* 0713FE */
#define sprite_list_07142E_ADDRESS 0x742Eu    /* 07142E */
#define sprite_list_07145E_ADDRESS 0x745Eu    /* 07145E */
#define animation_071488_ADDRESS 0x7488u    /* 071488 */
#define sprite_list_071494_ADDRESS 0x7494u    /* 071494 */
#define sprite_list_0714A6_ADDRESS 0x74A6u    /* 0714A6 */
#define animation_0714B8_ADDRESS 0x74B8u    /* 0714B8 */
#define sprite_list_0714E8_ADDRESS 0x74E8u    /* 0714E8 */
#define sprite_list_071500_ADDRESS 0x7500u    /* 071500 */
#define sprite_list_07151E_ADDRESS 0x751Eu    /* 07151E */
#define sprite_list_07152A_ADDRESS 0x752Au    /* 07152A */
#define sprite_list_07153C_ADDRESS 0x753Cu    /* 07153C */
#define sprite_list_071554_ADDRESS 0x7554u    /* 071554 */
#define sprite_list_071560_ADDRESS 0x7560u    /* 071560 */
#define sprite_list_07156C_ADDRESS 0x756Cu    /* 07156C */
#define sprite_list_071578_ADDRESS 0x7578u    /* 071578 */
#define sprite_list_071584_ADDRESS 0x7584u    /* 071584 */
#define sprite_list_071590_ADDRESS 0x7590u    /* 071590 */
#define animation_table_07159C_ADDRESS 0x759Cu    /* 07159C */
#define animation_0715C0_ADDRESS 0x75C0u    /* 0715C0 */
#define sprite_list_0715CC_ADDRESS 0x75CCu    /* 0715CC */
#define sprite_list_0715DE_ADDRESS 0x75DEu    /* 0715DE */
#define animation_0715F6_ADDRESS 0x75F6u    /* 0715F6 */
#define sprite_list_07160A_ADDRESS 0x760Au    /* 07160A */
#define sprite_list_071622_ADDRESS 0x7622u    /* 071622 */
#define sprite_list_07163A_ADDRESS 0x763Au    /* 07163A */
#define animation_071652_ADDRESS 0x7652u    /* 071652 */
#define sprite_list_07165E_ADDRESS 0x765Eu    /* 07165E */
#define sprite_list_07167C_ADDRESS 0x767Cu    /* 07167C */
#define animation_07169A_ADDRESS 0x769Au    /* 07169A */
#define sprite_list_0716B2_ADDRESS 0x76B2u    /* 0716B2 */
#define sprite_list_0716C4_ADDRESS 0x76C4u    /* 0716C4 */
#define sprite_list_0716DC_ADDRESS 0x76DCu    /* 0716DC */
#define sprite_list_0716E8_ADDRESS 0x76E8u    /* 0716E8 */
#define animation_071700_ADDRESS 0x7700u    /* 071700 */
#define sprite_list_071718_ADDRESS 0x7718u    /* 071718 */
#define sprite_list_071736_ADDRESS 0x7736u    /* 071736 */
#define sprite_list_071754_ADDRESS 0x7754u    /* 071754 */
#define sprite_list_071772_ADDRESS 0x7772u    /* 071772 */
#define sprite_list_07178A_ADDRESS 0x778Au    /* 07178A */
#define animation_0717A2_ADDRESS 0x77A2u    /* 0717A2 */
#define sprite_list_0717B2_ADDRESS 0x77B2u    /* 0717B2 */
#define animation_0717D0_ADDRESS 0x77D0u    /* 0717D0 */
#define sprite_list_0717EC_ADDRESS 0x77ECu    /* 0717EC */
#define sprite_list_0717FE_ADDRESS 0x77FEu    /* 0717FE */
#define sprite_list_071810_ADDRESS 0x7810u    /* 071810 */
#define sprite_list_071828_ADDRESS 0x7828u    /* 071828 */
#define animation_table_071840_ADDRESS 0x7840u    /* 071840 */
#define animation_071866_ADDRESS 0x7866u    /* 071866 */
#define sprite_list_07186E_ADDRESS 0x786Eu    /* 07186E */
#define animation_071880_ADDRESS 0x7880u    /* 071880 */
#define sprite_list_0718A4_ADDRESS 0x78A4u    /* 0718A4 */
#define sprite_list_0718B6_ADDRESS 0x78B6u    /* 0718B6 */
#define sprite_list_0718C2_ADDRESS 0x78C2u    /* 0718C2 */
#define sprite_list_0718D4_ADDRESS 0x78D4u    /* 0718D4 */
#define sprite_list_0718EC_ADDRESS 0x78ECu    /* 0718EC */
#define sprite_list_0718FE_ADDRESS 0x78FEu    /* 0718FE */
#define sprite_list_07190A_ADDRESS 0x790Au    /* 07190A */
#define sprite_list_071922_ADDRESS 0x7922u    /* 071922 */
#define animation_07193A_ADDRESS 0x793Au    /* 07193A */
#define sprite_list_071946_ADDRESS 0x7946u    /* 071946 */
#define sprite_list_071958_ADDRESS 0x7958u    /* 071958 */
#define animation_07196A_ADDRESS 0x796Au    /* 07196A */
#define sprite_list_07198A_ADDRESS 0x798Au    /* 07198A */
#define sprite_list_0719A2_ADDRESS 0x79A2u    /* 0719A2 */
#define sprite_list_0719BA_ADDRESS 0x79BAu    /* 0719BA */
#define sprite_list_0719D2_ADDRESS 0x79D2u    /* 0719D2 */
#define animation_0719DE_ADDRESS 0x79DEu    /* 0719DE */
#define sprite_list_071A16_ADDRESS 0x7A16u    /* 071A16 */
#define sprite_list_071A2E_ADDRESS 0x7A2Eu    /* 071A2E */
#define sprite_list_071A40_ADDRESS 0x7A40u    /* 071A40 */
#define sprite_list_071A52_ADDRESS 0x7A52u    /* 071A52 */
#define animation_071A64_ADDRESS 0x7A64u    /* 071A64 */
#define sprite_list_071A9C_ADDRESS 0x7A9Cu    /* 071A9C */
#define sprite_list_071AB4_ADDRESS 0x7AB4u    /* 071AB4 */
#define sprite_list_071AC6_ADDRESS 0x7AC6u    /* 071AC6 */
#define sprite_list_071AD8_ADDRESS 0x7AD8u    /* 071AD8 */
#define sprite_list_071AEA_ADDRESS 0x7AEAu    /* 071AEA */
#define sprite_list_071AFC_ADDRESS 0x7AFCu    /* 071AFC */
#define sprite_list_071B0E_ADDRESS 0x7B0Eu    /* 071B0E */
#define sprite_list_071B26_ADDRESS 0x7B26u    /* 071B26 */
#define sprite_list_071B38_ADDRESS 0x7B38u    /* 071B38 */
#define sprite_list_071B50_ADDRESS 0x7B50u    /* 071B50 */
#define sprite_list_071B6E_ADDRESS 0x7B6Eu    /* 071B6E */
#define sprite_list_071B86_ADDRESS 0x7B86u    /* 071B86 */
#define sprite_list_071BA4_ADDRESS 0x7BA4u    /* 071BA4 */
#define animation_071BBC_ADDRESS 0x7BBCu    /* 071BBC */
#define animation_071BD4_ADDRESS 0x7BD4u    /* 071BD4 */
#define sprite_list_071C1C_ADDRESS 0x7C1Cu    /* 071C1C */
#define animation_table_071C3A_ADDRESS 0x7C3Au    /* 071C3A */
#define animation_071C3E_ADDRESS 0x7C3Eu    /* 071C3E */
#define sprite_list_071C5A_ADDRESS 0x7C5Au    /* 071C5A */
#define sprite_list_071C78_ADDRESS 0x7C78u    /* 071C78 */
#define sprite_list_071C96_ADDRESS 0x7C96u    /* 071C96 */
#define sprite_list_071CB4_ADDRESS 0x7CB4u    /* 071CB4 */
#define sprite_list_071CD2_ADDRESS 0x7CD2u    /* 071CD2 */
#define sprite_list_071CF0_ADDRESS 0x7CF0u    /* 071CF0 */
#define animation_071D0E_ADDRESS 0x7D0Eu    /* 071D0E */
#define sprite_list_071D16_ADDRESS 0x7D16u    /* 071D16 */
#define animation_table_071D34_ADDRESS 0x7D34u    /* 071D34 */
#define animation_071D38_ADDRESS 0x7D38u    /* 071D38 */
#define sprite_list_071D4C_ADDRESS 0x7D4Cu    /* 071D4C */
#define sprite_list_071D5E_ADDRESS 0x7D5Eu    /* 071D5E */
#define sprite_list_071D76_ADDRESS 0x7D76u    /* 071D76 */
#define sprite_list_071D8E_ADDRESS 0x7D8Eu    /* 071D8E */
#define animation_071DAC_ADDRESS 0x7DACu    /* 071DAC */
#define sprite_list_071DC0_ADDRESS 0x7DC0u    /* 071DC0 */
#define sprite_list_071DD2_ADDRESS 0x7DD2u    /* 071DD2 */
#define sprite_list_071DE4_ADDRESS 0x7DE4u    /* 071DE4 */
#define sprite_list_071DF6_ADDRESS 0x7DF6u    /* 071DF6 */
#define fill_071E08_ADDRESS 0x7E08u    /* 071E08 */
#define unreached_animation_071E74_ADDRESS 0x7E74u    /* 071E74 */
#define sprite_list_071E84_ADDRESS 0x7E84u    /* 071E84 */
#define sprite_list_071E96_ADDRESS 0x7E96u    /* 071E96 */
#define sprite_list_071EBA_ADDRESS 0x7EBAu    /* 071EBA */
#define fill_071EE4_ADDRESS 0x7EE4u    /* 071EE4 */
#define set_index_072000_ADDRESS 0x6000u    /* 072000 */
#define animation_table_072010_ADDRESS 0x6010u    /* 072010 */
#define animation_07201A_ADDRESS 0x601Au    /* 07201A */
#define sprite_list_072022_ADDRESS 0x6022u    /* 072022 */
#define animation_072034_ADDRESS 0x6034u    /* 072034 */
#define sprite_list_072048_ADDRESS 0x6048u    /* 072048 */
#define sprite_list_072060_ADDRESS 0x6060u    /* 072060 */
#define sprite_list_072072_ADDRESS 0x6072u    /* 072072 */
#define sprite_list_07208A_ADDRESS 0x608Au    /* 07208A */
#define animation_07209C_ADDRESS 0x609Cu    /* 07209C */
#define sprite_list_0720B0_ADDRESS 0x60B0u    /* 0720B0 */
#define sprite_list_0720C2_ADDRESS 0x60C2u    /* 0720C2 */
#define sprite_list_0720D4_ADDRESS 0x60D4u    /* 0720D4 */
#define animation_0720E6_ADDRESS 0x60E6u    /* 0720E6 */
#define sprite_list_0720FA_ADDRESS 0x60FAu    /* 0720FA */
#define sprite_list_07210C_ADDRESS 0x610Cu    /* 07210C */
#define sprite_list_072124_ADDRESS 0x6124u    /* 072124 */
#define sprite_list_07213C_ADDRESS 0x613Cu    /* 07213C */
#define animation_072154_ADDRESS 0x6154u    /* 072154 */
#define sprite_list_072164_ADDRESS 0x6164u    /* 072164 */
#define sprite_list_07217C_ADDRESS 0x617Cu    /* 07217C */
#define animation_table_07218E_ADDRESS 0x618Eu    /* 07218E */
#define animation_072192_ADDRESS 0x6192u    /* 072192 */
#define sprite_list_0721A6_ADDRESS 0x61A6u    /* 0721A6 */
#define sprite_list_0721AC_ADDRESS 0x61ACu    /* 0721AC */
#define sprite_list_0721B2_ADDRESS 0x61B2u    /* 0721B2 */
#define animation_0721B8_ADDRESS 0x61B8u    /* 0721B8 */
#define sprite_list_0721CC_ADDRESS 0x61CCu    /* 0721CC */
#define sprite_list_0721D2_ADDRESS 0x61D2u    /* 0721D2 */
#define sprite_list_0721D8_ADDRESS 0x61D8u    /* 0721D8 */
#define animation_table_0721DE_ADDRESS 0x61DEu    /* 0721DE */
#define animation_072204_ADDRESS 0x6204u    /* 072204 */
#define sprite_list_07220C_ADDRESS 0x620Cu    /* 07220C */
#define animation_07221E_ADDRESS 0x621Eu    /* 07221E */
#define sprite_list_072242_ADDRESS 0x6242u    /* 072242 */
#define sprite_list_072254_ADDRESS 0x6254u    /* 072254 */
#define sprite_list_072266_ADDRESS 0x6266u    /* 072266 */
#define sprite_list_072278_ADDRESS 0x6278u    /* 072278 */
#define sprite_list_07228A_ADDRESS 0x628Au    /* 07228A */
#define sprite_list_07229C_ADDRESS 0x629Cu    /* 07229C */
#define sprite_list_0722AE_ADDRESS 0x62AEu    /* 0722AE */
#define sprite_list_0722C0_ADDRESS 0x62C0u    /* 0722C0 */
#define animation_0722D2_ADDRESS 0x62D2u    /* 0722D2 */
#define sprite_list_0722DE_ADDRESS 0x62DEu    /* 0722DE */
#define animation_0722F0_ADDRESS 0x62F0u    /* 0722F0 */
#define sprite_list_072304_ADDRESS 0x6304u    /* 072304 */
#define sprite_list_072316_ADDRESS 0x6316u    /* 072316 */
#define sprite_list_07232E_ADDRESS 0x632Eu    /* 07232E */
#define sprite_list_072346_ADDRESS 0x6346u    /* 072346 */
#define animation_07235E_ADDRESS 0x635Eu    /* 07235E */
#define sprite_list_07236E_ADDRESS 0x636Eu    /* 07236E */
#define sprite_list_072386_ADDRESS 0x6386u    /* 072386 */
#define sprite_list_07239E_ADDRESS 0x639Eu    /* 07239E */
#define animation_0723B6_ADDRESS 0x63B6u    /* 0723B6 */
#define sprite_list_0723CA_ADDRESS 0x63CAu    /* 0723CA */
#define sprite_list_0723E2_ADDRESS 0x63E2u    /* 0723E2 */
#define sprite_list_0723FA_ADDRESS 0x63FAu    /* 0723FA */
#define sprite_list_072412_ADDRESS 0x6412u    /* 072412 */
#define animation_072424_ADDRESS 0x6424u    /* 072424 */
#define sprite_list_072438_ADDRESS 0x6438u    /* 072438 */
#define sprite_list_07245C_ADDRESS 0x645Cu    /* 07245C */
#define animation_table_072474_ADDRESS 0x6474u    /* 072474 */
#define animation_072496_ADDRESS 0x6496u    /* 072496 */
#define sprite_list_0724BA_ADDRESS 0x64BAu    /* 0724BA */
#define sprite_list_0724D2_ADDRESS 0x64D2u    /* 0724D2 */
#define sprite_list_0724EA_ADDRESS 0x64EAu    /* 0724EA */
#define sprite_list_072502_ADDRESS 0x6502u    /* 072502 */
#define sprite_list_07251A_ADDRESS 0x651Au    /* 07251A */
#define sprite_list_072532_ADDRESS 0x6532u    /* 072532 */
#define sprite_list_07254A_ADDRESS 0x654Au    /* 07254A */
#define sprite_list_072562_ADDRESS 0x6562u    /* 072562 */
#define animation_07257A_ADDRESS 0x657Au    /* 07257A */
#define sprite_list_07259E_ADDRESS 0x659Eu    /* 07259E */
#define sprite_list_0725B6_ADDRESS 0x65B6u    /* 0725B6 */
#define sprite_list_0725CE_ADDRESS 0x65CEu    /* 0725CE */
#define sprite_list_0725E6_ADDRESS 0x65E6u    /* 0725E6 */
#define sprite_list_0725FE_ADDRESS 0x65FEu    /* 0725FE */
#define sprite_list_072616_ADDRESS 0x6616u    /* 072616 */
#define animation_072628_ADDRESS 0x6628u    /* 072628 */
#define sprite_list_07263C_ADDRESS 0x663Cu    /* 07263C */
#define sprite_list_072654_ADDRESS 0x6654u    /* 072654 */
#define sprite_list_07266C_ADDRESS 0x666Cu    /* 07266C */
#define sprite_list_072684_ADDRESS 0x6684u    /* 072684 */
#define animation_07269C_ADDRESS 0x669Cu    /* 07269C */
#define sprite_list_0726A8_ADDRESS 0x66A8u    /* 0726A8 */
#define sprite_list_0726B4_ADDRESS 0x66B4u    /* 0726B4 */
#define animation_0726C6_ADDRESS 0x66C6u    /* 0726C6 */
#define sprite_list_0726E6_ADDRESS 0x66E6u    /* 0726E6 */
#define sprite_list_0726F8_ADDRESS 0x66F8u    /* 0726F8 */
#define sprite_list_0726FE_ADDRESS 0x66FEu    /* 0726FE */
#define sprite_list_072704_ADDRESS 0x6704u    /* 072704 */
#define sprite_list_07271C_ADDRESS 0x671Cu    /* 07271C */
#define sprite_list_07272E_ADDRESS 0x672Eu    /* 07272E */
#define sprite_list_072740_ADDRESS 0x6740u    /* 072740 */
#define animation_table_072758_ADDRESS 0x6758u    /* 072758 */
#define animation_072762_ADDRESS 0x6762u    /* 072762 */
#define sprite_list_07276A_ADDRESS 0x676Au    /* 07276A */
#define animation_072782_ADDRESS 0x6782u    /* 072782 */
#define sprite_list_0727AE_ADDRESS 0x67AEu    /* 0727AE */
#define sprite_list_0727C6_ADDRESS 0x67C6u    /* 0727C6 */
#define sprite_list_0727DE_ADDRESS 0x67DEu    /* 0727DE */
#define sprite_list_0727F6_ADDRESS 0x67F6u    /* 0727F6 */
#define animation_07280E_ADDRESS 0x680Eu    /* 07280E */
#define sprite_list_072832_ADDRESS 0x6832u    /* 072832 */
#define sprite_list_07284A_ADDRESS 0x684Au    /* 07284A */
#define sprite_list_072862_ADDRESS 0x6862u    /* 072862 */
#define sprite_list_072874_ADDRESS 0x6874u    /* 072874 */
#define sprite_list_072886_ADDRESS 0x6886u    /* 072886 */
#define sprite_list_07289E_ADDRESS 0x689Eu    /* 07289E */
#define sprite_list_0728B0_ADDRESS 0x68B0u    /* 0728B0 */
#define sprite_list_0728C2_ADDRESS 0x68C2u    /* 0728C2 */
#define animation_0728DA_ADDRESS 0x68DAu    /* 0728DA */
#define sprite_list_0728F6_ADDRESS 0x68F6u    /* 0728F6 */
#define sprite_list_072902_ADDRESS 0x6902u    /* 072902 */
#define sprite_list_07290E_ADDRESS 0x690Eu    /* 07290E */
#define sprite_list_072920_ADDRESS 0x6920u    /* 072920 */
#define sprite_list_072932_ADDRESS 0x6932u    /* 072932 */
#define sprite_list_07294A_ADDRESS 0x694Au    /* 07294A */
#define animation_072962_ADDRESS 0x6962u    /* 072962 */
#define sprite_list_07296E_ADDRESS 0x696Eu    /* 07296E */
#define sprite_list_072980_ADDRESS 0x6980u    /* 072980 */
#define animation_table_072998_ADDRESS 0x6998u    /* 072998 */
#define animation_0729C0_ADDRESS 0x69C0u    /* 0729C0 */
#define sprite_list_0729C8_ADDRESS 0x69C8u    /* 0729C8 */
#define animation_0729D4_ADDRESS 0x69D4u    /* 0729D4 */
#define sprite_list_0729F8_ADDRESS 0x69F8u    /* 0729F8 */
#define sprite_list_072A04_ADDRESS 0x6A04u    /* 072A04 */
#define sprite_list_072A10_ADDRESS 0x6A10u    /* 072A10 */
#define sprite_list_072A1C_ADDRESS 0x6A1Cu    /* 072A1C */
#define sprite_list_072A34_ADDRESS 0x6A34u    /* 072A34 */
#define sprite_list_072A52_ADDRESS 0x6A52u    /* 072A52 */
#define sprite_list_072A6A_ADDRESS 0x6A6Au    /* 072A6A */
#define sprite_list_072A82_ADDRESS 0x6A82u    /* 072A82 */
#define animation_072A9A_ADDRESS 0x6A9Au    /* 072A9A */
#define sprite_list_072AA6_ADDRESS 0x6AA6u    /* 072AA6 */
#define sprite_list_072AB8_ADDRESS 0x6AB8u    /* 072AB8 */
#define animation_072ACA_ADDRESS 0x6ACAu    /* 072ACA */
#define sprite_list_072AD6_ADDRESS 0x6AD6u    /* 072AD6 */
#define sprite_list_072AE8_ADDRESS 0x6AE8u    /* 072AE8 */
#define animation_072B00_ADDRESS 0x6B00u    /* 072B00 */
#define sprite_list_072B14_ADDRESS 0x6B14u    /* 072B14 */
#define sprite_list_072B26_ADDRESS 0x6B26u    /* 072B26 */
#define animation_072B38_ADDRESS 0x6B38u    /* 072B38 */
#define sprite_list_072B48_ADDRESS 0x6B48u    /* 072B48 */
#define sprite_list_072B66_ADDRESS 0x6B66u    /* 072B66 */
#define sprite_list_072B8A_ADDRESS 0x6B8Au    /* 072B8A */
#define animation_072BA2_ADDRESS 0x6BA2u    /* 072BA2 */
#define sprite_list_072BD2_ADDRESS 0x6BD2u    /* 072BD2 */
#define sprite_list_072BD8_ADDRESS 0x6BD8u    /* 072BD8 */
#define sprite_list_072BEA_ADDRESS 0x6BEAu    /* 072BEA */
#define sprite_list_072C02_ADDRESS 0x6C02u    /* 072C02 */
#define sprite_list_072C26_ADDRESS 0x6C26u    /* 072C26 */
#define sprite_list_072C4A_ADDRESS 0x6C4Au    /* 072C4A */
#define sprite_list_072C6E_ADDRESS 0x6C6Eu    /* 072C6E */
#define sprite_list_072C92_ADDRESS 0x6C92u    /* 072C92 */
#define sprite_list_072CB6_ADDRESS 0x6CB6u    /* 072CB6 */
#define sprite_list_072CD4_ADDRESS 0x6CD4u    /* 072CD4 */
#define sprite_list_072CE6_ADDRESS 0x6CE6u    /* 072CE6 */
#define animation_072CF2_ADDRESS 0x6CF2u    /* 072CF2 */
#define sprite_list_072D22_ADDRESS 0x6D22u    /* 072D22 */
#define sprite_list_072D28_ADDRESS 0x6D28u    /* 072D28 */
#define sprite_list_072D3A_ADDRESS 0x6D3Au    /* 072D3A */
#define sprite_list_072D64_ADDRESS 0x6D64u    /* 072D64 */
#define sprite_list_072DA0_ADDRESS 0x6DA0u    /* 072DA0 */
#define sprite_list_072DDC_ADDRESS 0x6DDCu    /* 072DDC */
#define sprite_list_072E18_ADDRESS 0x6E18u    /* 072E18 */
#define sprite_list_072E54_ADDRESS 0x6E54u    /* 072E54 */
#define sprite_list_072E90_ADDRESS 0x6E90u    /* 072E90 */
#define sprite_list_072ECC_ADDRESS 0x6ECCu    /* 072ECC */
#define sprite_list_072EF0_ADDRESS 0x6EF0u    /* 072EF0 */
#define animation_072EFC_ADDRESS 0x6EFCu    /* 072EFC */
#define sprite_list_072F20_ADDRESS 0x6F20u    /* 072F20 */
#define sprite_list_072F32_ADDRESS 0x6F32u    /* 072F32 */
#define sprite_list_072F44_ADDRESS 0x6F44u    /* 072F44 */
#define sprite_list_072F5C_ADDRESS 0x6F5Cu    /* 072F5C */
#define sprite_list_072F74_ADDRESS 0x6F74u    /* 072F74 */
#define sprite_list_072F92_ADDRESS 0x6F92u    /* 072F92 */
#define sprite_list_072FAA_ADDRESS 0x6FAAu    /* 072FAA */
#define sprite_list_072FC2_ADDRESS 0x6FC2u    /* 072FC2 */
#define animation_072FDA_ADDRESS 0x6FDAu    /* 072FDA */
#define sprite_list_07300A_ADDRESS 0x700Au    /* 07300A */
#define sprite_list_073010_ADDRESS 0x7010u    /* 073010 */
#define sprite_list_073022_ADDRESS 0x7022u    /* 073022 */
#define sprite_list_073034_ADDRESS 0x7034u    /* 073034 */
#define sprite_list_073046_ADDRESS 0x7046u    /* 073046 */
#define sprite_list_07305E_ADDRESS 0x705Eu    /* 07305E */
#define sprite_list_073076_ADDRESS 0x7076u    /* 073076 */
#define sprite_list_07308E_ADDRESS 0x708Eu    /* 07308E */
#define sprite_list_0730A6_ADDRESS 0x70A6u    /* 0730A6 */
#define sprite_list_0730B8_ADDRESS 0x70B8u    /* 0730B8 */
#define sprite_list_0730BE_ADDRESS 0x70BEu    /* 0730BE */
#define animation_table_0730CA_ADDRESS 0x70CAu    /* 0730CA */
#define animation_073100_ADDRESS 0x7100u    /* 073100 */
#define sprite_list_073108_ADDRESS 0x7108u    /* 073108 */
#define animation_073120_ADDRESS 0x7120u    /* 073120 */
#define animation_07313C_ADDRESS 0x713Cu    /* 07313C */
#define sprite_list_073158_ADDRESS 0x7158u    /* 073158 */
#define sprite_list_07315E_ADDRESS 0x715Eu    /* 07315E */
#define sprite_list_07316A_ADDRESS 0x716Au    /* 07316A */
#define sprite_list_073170_ADDRESS 0x7170u    /* 073170 */
#define sprite_list_073176_ADDRESS 0x7176u    /* 073176 */
#define sprite_list_07317C_ADDRESS 0x717Cu    /* 07317C */
#define animation_07318E_ADDRESS 0x718Eu    /* 07318E */
#define sprite_list_0731A2_ADDRESS 0x71A2u    /* 0731A2 */
#define sprite_list_0731B4_ADDRESS 0x71B4u    /* 0731B4 */
#define sprite_list_0731C6_ADDRESS 0x71C6u    /* 0731C6 */
#define sprite_list_0731E4_ADDRESS 0x71E4u    /* 0731E4 */
#define animation_0731FC_ADDRESS 0x71FCu    /* 0731FC */
#define sprite_list_073220_ADDRESS 0x7220u    /* 073220 */
#define sprite_list_073232_ADDRESS 0x7232u    /* 073232 */
#define sprite_list_07324A_ADDRESS 0x724Au    /* 07324A */
#define sprite_list_07325C_ADDRESS 0x725Cu    /* 07325C */
#define sprite_list_073274_ADDRESS 0x7274u    /* 073274 */
#define sprite_list_07328C_ADDRESS 0x728Cu    /* 07328C */
#define sprite_list_0732A4_ADDRESS 0x72A4u    /* 0732A4 */
#define sprite_list_0732B6_ADDRESS 0x72B6u    /* 0732B6 */
#define animation_0732CE_ADDRESS 0x72CEu    /* 0732CE */
#define sprite_list_0732F2_ADDRESS 0x72F2u    /* 0732F2 */
#define sprite_list_07330A_ADDRESS 0x730Au    /* 07330A */
#define sprite_list_073322_ADDRESS 0x7322u    /* 073322 */
#define sprite_list_07333A_ADDRESS 0x733Au    /* 07333A */
#define animation_073346_ADDRESS 0x7346u    /* 073346 */
#define sprite_list_07336A_ADDRESS 0x736Au    /* 07336A */
#define sprite_list_073382_ADDRESS 0x7382u    /* 073382 */
#define animation_073394_ADDRESS 0x7394u    /* 073394 */
#define sprite_list_0733B4_ADDRESS 0x73B4u    /* 0733B4 */
#define sprite_list_0733C6_ADDRESS 0x73C6u    /* 0733C6 */
#define sprite_list_0733D8_ADDRESS 0x73D8u    /* 0733D8 */
#define sprite_list_0733EA_ADDRESS 0x73EAu    /* 0733EA */
#define sprite_list_073402_ADDRESS 0x7402u    /* 073402 */
#define sprite_list_073414_ADDRESS 0x7414u    /* 073414 */
#define sprite_list_073426_ADDRESS 0x7426u    /* 073426 */
#define animation_073438_ADDRESS 0x7438u    /* 073438 */
#define sprite_list_07347C_ADDRESS 0x747Cu    /* 07347C */
#define sprite_list_073494_ADDRESS 0x7494u    /* 073494 */
#define sprite_list_0734AC_ADDRESS 0x74ACu    /* 0734AC */
#define sprite_list_0734C4_ADDRESS 0x74C4u    /* 0734C4 */
#define sprite_list_0734D6_ADDRESS 0x74D6u    /* 0734D6 */
#define sprite_list_0734EE_ADDRESS 0x74EEu    /* 0734EE */
#define sprite_list_073500_ADDRESS 0x7500u    /* 073500 */
#define sprite_list_073512_ADDRESS 0x7512u    /* 073512 */
#define sprite_list_07352A_ADDRESS 0x752Au    /* 07352A */
#define sprite_list_07353C_ADDRESS 0x753Cu    /* 07353C */
#define animation_07354E_ADDRESS 0x754Eu    /* 07354E */
#define sprite_list_073572_ADDRESS 0x7572u    /* 073572 */
#define sprite_list_07358A_ADDRESS 0x758Au    /* 07358A */
#define sprite_list_07359C_ADDRESS 0x759Cu    /* 07359C */
#define sprite_list_0735B4_ADDRESS 0x75B4u    /* 0735B4 */
#define animation_0735C6_ADDRESS 0x75C6u    /* 0735C6 */
#define sprite_list_0735F2_ADDRESS 0x75F2u    /* 0735F2 */
#define sprite_list_0735FE_ADDRESS 0x75FEu    /* 0735FE */
#define sprite_list_073610_ADDRESS 0x7610u    /* 073610 */
#define sprite_list_073622_ADDRESS 0x7622u    /* 073622 */
#define sprite_list_07363A_ADDRESS 0x763Au    /* 07363A */
#define animation_073652_ADDRESS 0x7652u    /* 073652 */
#define sprite_list_073676_ADDRESS 0x7676u    /* 073676 */
#define sprite_list_073682_ADDRESS 0x7682u    /* 073682 */
#define sprite_list_073694_ADDRESS 0x7694u    /* 073694 */
#define sprite_list_0736A0_ADDRESS 0x76A0u    /* 0736A0 */
#define sprite_list_0736B2_ADDRESS 0x76B2u    /* 0736B2 */
#define sprite_list_0736C4_ADDRESS 0x76C4u    /* 0736C4 */
#define sprite_list_0736D6_ADDRESS 0x76D6u    /* 0736D6 */
#define sprite_list_0736E2_ADDRESS 0x76E2u    /* 0736E2 */
#define animation_0736F4_ADDRESS 0x76F4u    /* 0736F4 */
#define sprite_list_073700_ADDRESS 0x7700u    /* 073700 */
#define animation_073718_ADDRESS 0x7718u    /* 073718 */
#define sprite_list_07373C_ADDRESS 0x773Cu    /* 07373C */
#define sprite_list_07374E_ADDRESS 0x774Eu    /* 07374E */
#define sprite_list_073766_ADDRESS 0x7766u    /* 073766 */
#define sprite_list_073778_ADDRESS 0x7778u    /* 073778 */
#define sprite_list_073790_ADDRESS 0x7790u    /* 073790 */
#define sprite_list_0737A8_ADDRESS 0x77A8u    /* 0737A8 */
#define sprite_list_0737C0_ADDRESS 0x77C0u    /* 0737C0 */
#define sprite_list_0737D2_ADDRESS 0x77D2u    /* 0737D2 */
#define animation_table_0737EA_ADDRESS 0x77EAu    /* 0737EA */
#define animation_073810_ADDRESS 0x7810u    /* 073810 */
#define sprite_list_073824_ADDRESS 0x7824u    /* 073824 */
#define sprite_list_073836_ADDRESS 0x7836u    /* 073836 */
#define sprite_list_073848_ADDRESS 0x7848u    /* 073848 */
#define sprite_list_07385A_ADDRESS 0x785Au    /* 07385A */
#define animation_07386C_ADDRESS 0x786Cu    /* 07386C */
#define sprite_list_073884_ADDRESS 0x7884u    /* 073884 */
#define sprite_list_07389C_ADDRESS 0x789Cu    /* 07389C */
#define sprite_list_0738B4_ADDRESS 0x78B4u    /* 0738B4 */
#define sprite_list_0738CC_ADDRESS 0x78CCu    /* 0738CC */
#define sprite_list_0738F0_ADDRESS 0x78F0u    /* 0738F0 */
#define animation_07391A_ADDRESS 0x791Au    /* 07391A */
#define sprite_list_073926_ADDRESS 0x7926u    /* 073926 */
#define sprite_list_073950_ADDRESS 0x7950u    /* 073950 */
#define animation_07397A_ADDRESS 0x797Au    /* 07397A */
#define sprite_list_07399E_ADDRESS 0x799Eu    /* 07399E */
#define sprite_list_0739C8_ADDRESS 0x79C8u    /* 0739C8 */
#define sprite_list_0739F2_ADDRESS 0x79F2u    /* 0739F2 */
#define sprite_list_073A1C_ADDRESS 0x7A1Cu    /* 073A1C */
#define animation_073A46_ADDRESS 0x7A46u    /* 073A46 */
#define sprite_list_073A5A_ADDRESS 0x7A5Au    /* 073A5A */
#define sprite_list_073AA2_ADDRESS 0x7AA2u    /* 073AA2 */
#define sprite_list_073AC6_ADDRESS 0x7AC6u    /* 073AC6 */
#define animation_073AF6_ADDRESS 0x7AF6u    /* 073AF6 */
#define sprite_list_073B06_ADDRESS 0x7B06u    /* 073B06 */
#define sprite_list_073B18_ADDRESS 0x7B18u    /* 073B18 */
#define sprite_list_073B36_ADDRESS 0x7B36u    /* 073B36 */
#define animation_073B48_ADDRESS 0x7B48u    /* 073B48 */
#define sprite_list_073B54_ADDRESS 0x7B54u    /* 073B54 */
#define sprite_list_073B8A_ADDRESS 0x7B8Au    /* 073B8A */
#define animation_073BC0_ADDRESS 0x7BC0u    /* 073BC0 */
#define sprite_list_073BC8_ADDRESS 0x7BC8u    /* 073BC8 */
#define animation_073BEC_ADDRESS 0x7BECu    /* 073BEC */
#define sprite_list_073C00_ADDRESS 0x7C00u    /* 073C00 */
#define sprite_list_073C06_ADDRESS 0x7C06u    /* 073C06 */
#define sprite_list_073C1E_ADDRESS 0x7C1Eu    /* 073C1E */
#define sprite_list_073C2A_ADDRESS 0x7C2Au    /* 073C2A */
#define animation_073C36_ADDRESS 0x7C36u    /* 073C36 */
#define animation_073C3E_ADDRESS 0x7C3Eu    /* 073C3E */
#define sprite_list_073C4A_ADDRESS 0x7C4Au    /* 073C4A */
#define sprite_list_073C74_ADDRESS 0x7C74u    /* 073C74 */
#define animation_073C92_ADDRESS 0x7C92u    /* 073C92 */
#define sprite_list_073C9A_ADDRESS 0x7C9Au    /* 073C9A */
#define animation_073CA0_ADDRESS 0x7CA0u    /* 073CA0 */
#define sprite_list_073CA8_ADDRESS 0x7CA8u    /* 073CA8 */
#define animation_073CAE_ADDRESS 0x7CAEu    /* 073CAE */
#define sprite_list_073CB6_ADDRESS 0x7CB6u    /* 073CB6 */
#define animation_073CBC_ADDRESS 0x7CBCu    /* 073CBC */
#define sprite_list_073CC8_ADDRESS 0x7CC8u    /* 073CC8 */
#define sprite_list_073CF2_ADDRESS 0x7CF2u    /* 073CF2 */
#define animation_073D1C_ADDRESS 0x7D1Cu    /* 073D1C */
#define sprite_list_073D30_ADDRESS 0x7D30u    /* 073D30 */
#define sprite_list_073D4E_ADDRESS 0x7D4Eu    /* 073D4E */
#define sprite_list_073D6C_ADDRESS 0x7D6Cu    /* 073D6C */
#define animation_073D9C_ADDRESS 0x7D9Cu    /* 073D9C */
#define sprite_list_073DA4_ADDRESS 0x7DA4u    /* 073DA4 */
#define animation_073DD4_ADDRESS 0x7DD4u    /* 073DD4 */
#define sprite_list_073DE4_ADDRESS 0x7DE4u    /* 073DE4 */
#define sprite_list_073E08_ADDRESS 0x7E08u    /* 073E08 */
#define sprite_list_073E38_ADDRESS 0x7E38u    /* 073E38 */
#define animation_073E74_ADDRESS 0x7E74u    /* 073E74 */
#define sprite_list_073E84_ADDRESS 0x7E84u    /* 073E84 */
#define sprite_list_073E96_ADDRESS 0x7E96u    /* 073E96 */
#define sprite_list_073EBA_ADDRESS 0x7EBAu    /* 073EBA */
#define fill_073EE4_ADDRESS 0x7EE4u    /* 073EE4 */
#define set_index_074000_ADDRESS 0x6000u    /* 074000 */
#define animation_table_07400E_ADDRESS 0x600Eu    /* 07400E */
#define animation_074058_ADDRESS 0x6058u    /* 074058 */
#define sprite_list_074070_ADDRESS 0x6070u    /* 074070 */
#define sprite_list_07407C_ADDRESS 0x607Cu    /* 07407C */
#define sprite_list_074088_ADDRESS 0x6088u    /* 074088 */
#define sprite_list_074094_ADDRESS 0x6094u    /* 074094 */
#define sprite_list_0740A6_ADDRESS 0x60A6u    /* 0740A6 */
#define animation_0740AC_ADDRESS 0x60ACu    /* 0740AC */
#define sprite_list_0740BC_ADDRESS 0x60BCu    /* 0740BC */
#define sprite_list_0740C2_ADDRESS 0x60C2u    /* 0740C2 */
#define sprite_list_0740C8_ADDRESS 0x60C8u    /* 0740C8 */
#define animation_0740CE_ADDRESS 0x60CEu    /* 0740CE */
#define sprite_list_0740DE_ADDRESS 0x60DEu    /* 0740DE */
#define sprite_list_0740E4_ADDRESS 0x60E4u    /* 0740E4 */
#define sprite_list_0740EA_ADDRESS 0x60EAu    /* 0740EA */
#define animation_0740F0_ADDRESS 0x60F0u    /* 0740F0 */
#define sprite_list_074104_ADDRESS 0x6104u    /* 074104 */
#define sprite_list_07411C_ADDRESS 0x611Cu    /* 07411C */
#define sprite_list_074134_ADDRESS 0x6134u    /* 074134 */
#define sprite_list_07414C_ADDRESS 0x614Cu    /* 07414C */
#define animation_074164_ADDRESS 0x6164u    /* 074164 */
#define animation_074178_ADDRESS 0x6178u    /* 074178 */
#define sprite_list_074180_ADDRESS 0x6180u    /* 074180 */
#define animation_074192_ADDRESS 0x6192u    /* 074192 */
#define sprite_list_0741B6_ADDRESS 0x61B6u    /* 0741B6 */
#define sprite_list_0741CE_ADDRESS 0x61CEu    /* 0741CE */
#define sprite_list_0741E6_ADDRESS 0x61E6u    /* 0741E6 */
#define sprite_list_0741FE_ADDRESS 0x61FEu    /* 0741FE */
#define sprite_list_074216_ADDRESS 0x6216u    /* 074216 */
#define sprite_list_07422E_ADDRESS 0x622Eu    /* 07422E */
#define sprite_list_074246_ADDRESS 0x6246u    /* 074246 */
#define sprite_list_074258_ADDRESS 0x6258u    /* 074258 */
#define animation_074270_ADDRESS 0x6270u    /* 074270 */
#define sprite_list_074294_ADDRESS 0x6294u    /* 074294 */
#define sprite_list_0742AC_ADDRESS 0x62ACu    /* 0742AC */
#define sprite_list_0742C4_ADDRESS 0x62C4u    /* 0742C4 */
#define sprite_list_0742DC_ADDRESS 0x62DCu    /* 0742DC */
#define sprite_list_0742F4_ADDRESS 0x62F4u    /* 0742F4 */
#define sprite_list_07430C_ADDRESS 0x630Cu    /* 07430C */
#define sprite_list_074324_ADDRESS 0x6324u    /* 074324 */
#define sprite_list_07433C_ADDRESS 0x633Cu    /* 07433C */
#define animation_074354_ADDRESS 0x6354u    /* 074354 */
#define sprite_list_074378_ADDRESS 0x6378u    /* 074378 */
#define sprite_list_07438A_ADDRESS 0x638Au    /* 07438A */
#define sprite_list_07439C_ADDRESS 0x639Cu    /* 07439C */
#define sprite_list_0743B4_ADDRESS 0x63B4u    /* 0743B4 */
#define sprite_list_0743CC_ADDRESS 0x63CCu    /* 0743CC */
#define sprite_list_0743DE_ADDRESS 0x63DEu    /* 0743DE */
#define sprite_list_0743F0_ADDRESS 0x63F0u    /* 0743F0 */
#define sprite_list_074408_ADDRESS 0x6408u    /* 074408 */
#define animation_074420_ADDRESS 0x6420u    /* 074420 */
#define sprite_list_07442C_ADDRESS 0x642Cu    /* 07442C */
#define sprite_list_074444_ADDRESS 0x6444u    /* 074444 */
#define animation_07445C_ADDRESS 0x645Cu    /* 07445C */
#define sprite_list_074468_ADDRESS 0x6468u    /* 074468 */
#define sprite_list_074480_ADDRESS 0x6480u    /* 074480 */
#define animation_074498_ADDRESS 0x6498u    /* 074498 */
#define sprite_list_0744A4_ADDRESS 0x64A4u    /* 0744A4 */
#define sprite_list_0744B6_ADDRESS 0x64B6u    /* 0744B6 */
#define animation_0744CE_ADDRESS 0x64CEu    /* 0744CE */
#define sprite_list_0744DA_ADDRESS 0x64DAu    /* 0744DA */
#define sprite_list_0744E6_ADDRESS 0x64E6u    /* 0744E6 */
#define animation_0744F2_ADDRESS 0x64F2u    /* 0744F2 */
#define sprite_list_07450E_ADDRESS 0x650Eu    /* 07450E */
#define sprite_list_074526_ADDRESS 0x6526u    /* 074526 */
#define sprite_list_074538_ADDRESS 0x6538u    /* 074538 */
#define sprite_list_074550_ADDRESS 0x6550u    /* 074550 */
#define animation_074568_ADDRESS 0x6568u    /* 074568 */
#define sprite_list_07457C_ADDRESS 0x657Cu    /* 07457C */
#define sprite_list_07458E_ADDRESS 0x658Eu    /* 07458E */
#define sprite_list_0745A6_ADDRESS 0x65A6u    /* 0745A6 */
#define sprite_list_0745BE_ADDRESS 0x65BEu    /* 0745BE */
#define animation_0745D0_ADDRESS 0x65D0u    /* 0745D0 */
#define sprite_list_0745E8_ADDRESS 0x65E8u    /* 0745E8 */
#define sprite_list_074606_ADDRESS 0x6606u    /* 074606 */
#define sprite_list_074624_ADDRESS 0x6624u    /* 074624 */
#define sprite_list_07463C_ADDRESS 0x663Cu    /* 07463C */
#define sprite_list_07465A_ADDRESS 0x665Au    /* 07465A */
#define animation_074678_ADDRESS 0x6678u    /* 074678 */
#define sprite_list_074698_ADDRESS 0x6698u    /* 074698 */
#define sprite_list_0746B0_ADDRESS 0x66B0u    /* 0746B0 */
#define sprite_list_0746CE_ADDRESS 0x66CEu    /* 0746CE */
#define sprite_list_0746EC_ADDRESS 0x66ECu    /* 0746EC */
#define sprite_list_07470A_ADDRESS 0x670Au    /* 07470A */
#define sprite_list_074722_ADDRESS 0x6722u    /* 074722 */
#define animation_07473A_ADDRESS 0x673Au    /* 07473A */
#define sprite_list_074746_ADDRESS 0x6746u    /* 074746 */
#define sprite_list_07475E_ADDRESS 0x675Eu    /* 07475E */
#define animation_074776_ADDRESS 0x6776u    /* 074776 */
#define sprite_list_07479A_ADDRESS 0x679Au    /* 07479A */
#define sprite_list_0747B2_ADDRESS 0x67B2u    /* 0747B2 */
#define sprite_list_0747D0_ADDRESS 0x67D0u    /* 0747D0 */
#define sprite_list_0747E8_ADDRESS 0x67E8u    /* 0747E8 */
#define sprite_list_074806_ADDRESS 0x6806u    /* 074806 */
#define sprite_list_074818_ADDRESS 0x6818u    /* 074818 */
#define animation_07482A_ADDRESS 0x682Au    /* 07482A */
#define sprite_list_074846_ADDRESS 0x6846u    /* 074846 */
#define sprite_list_07485E_ADDRESS 0x685Eu    /* 07485E */
#define sprite_list_074876_ADDRESS 0x6876u    /* 074876 */
#define sprite_list_07489A_ADDRESS 0x689Au    /* 07489A */
#define animation_0748BE_ADDRESS 0x68BEu    /* 0748BE */
#define sprite_list_0748E2_ADDRESS 0x68E2u    /* 0748E2 */
#define sprite_list_0748F4_ADDRESS 0x68F4u    /* 0748F4 */
#define sprite_list_074906_ADDRESS 0x6906u    /* 074906 */
#define sprite_list_074918_ADDRESS 0x6918u    /* 074918 */
#define sprite_list_07492A_ADDRESS 0x692Au    /* 07492A */
#define sprite_list_07493C_ADDRESS 0x693Cu    /* 07493C */
#define sprite_list_07494E_ADDRESS 0x694Eu    /* 07494E */
#define sprite_list_074960_ADDRESS 0x6960u    /* 074960 */
#define animation_074978_ADDRESS 0x6978u    /* 074978 */
#define sprite_list_074990_ADDRESS 0x6990u    /* 074990 */
#define sprite_list_0749A8_ADDRESS 0x69A8u    /* 0749A8 */
#define sprite_list_0749BA_ADDRESS 0x69BAu    /* 0749BA */
#define sprite_list_0749D2_ADDRESS 0x69D2u    /* 0749D2 */
#define animation_0749EA_ADDRESS 0x69EAu    /* 0749EA */
#define sprite_list_0749FE_ADDRESS 0x69FEu    /* 0749FE */
#define sprite_list_074A16_ADDRESS 0x6A16u    /* 074A16 */
#define animation_074A28_ADDRESS 0x6A28u    /* 074A28 */
#define sprite_list_074A38_ADDRESS 0x6A38u    /* 074A38 */
#define sprite_list_074A44_ADDRESS 0x6A44u    /* 074A44 */
#define animation_074A56_ADDRESS 0x6A56u    /* 074A56 */
#define sprite_list_074A72_ADDRESS 0x6A72u    /* 074A72 */
#define sprite_list_074A7E_ADDRESS 0x6A7Eu    /* 074A7E */
#define sprite_list_074A90_ADDRESS 0x6A90u    /* 074A90 */
#define sprite_list_074A9C_ADDRESS 0x6A9Cu    /* 074A9C */
#define sprite_list_074AAE_ADDRESS 0x6AAEu    /* 074AAE */
#define animation_074AC0_ADDRESS 0x6AC0u    /* 074AC0 */
#define sprite_list_074AD0_ADDRESS 0x6AD0u    /* 074AD0 */
#define animation_074AD6_ADDRESS 0x6AD6u    /* 074AD6 */
#define sprite_list_074ADE_ADDRESS 0x6ADEu    /* 074ADE */
#define animation_074AEA_ADDRESS 0x6AEAu    /* 074AEA */
#define sprite_list_074B0E_ADDRESS 0x6B0Eu    /* 074B0E */
#define sprite_list_074B26_ADDRESS 0x6B26u    /* 074B26 */
#define sprite_list_074B3E_ADDRESS 0x6B3Eu    /* 074B3E */
#define sprite_list_074B56_ADDRESS 0x6B56u    /* 074B56 */
#define sprite_list_074B6E_ADDRESS 0x6B6Eu    /* 074B6E */
#define sprite_list_074B86_ADDRESS 0x6B86u    /* 074B86 */
#define sprite_list_074B9E_ADDRESS 0x6B9Eu    /* 074B9E */
#define sprite_list_074BB6_ADDRESS 0x6BB6u    /* 074BB6 */
#define animation_table_074BD4_ADDRESS 0x6BD4u    /* 074BD4 */
#define animation_074BD8_ADDRESS 0x6BD8u    /* 074BD8 */
#define sprite_list_074BEC_ADDRESS 0x6BECu    /* 074BEC */
#define sprite_list_074BF8_ADDRESS 0x6BF8u    /* 074BF8 */
#define sprite_list_074C04_ADDRESS 0x6C04u    /* 074C04 */
#define sprite_list_074C10_ADDRESS 0x6C10u    /* 074C10 */
#define animation_074C1C_ADDRESS 0x6C1Cu    /* 074C1C */
#define sprite_list_074C2C_ADDRESS 0x6C2Cu    /* 074C2C */
#define sprite_list_074C38_ADDRESS 0x6C38u    /* 074C38 */
#define animation_table_074C44_ADDRESS 0x6C44u    /* 074C44 */
#define unreached_animation_074C4A_ADDRESS 0x6C4Au    /* 074C4A */
#define sprite_list_074C52_ADDRESS 0x6C52u    /* 074C52 */
#define animation_074C64_ADDRESS 0x6C64u    /* 074C64 */
#define sprite_list_074C80_ADDRESS 0x6C80u    /* 074C80 */
#define sprite_list_074C92_ADDRESS 0x6C92u    /* 074C92 */
#define sprite_list_074CA4_ADDRESS 0x6CA4u    /* 074CA4 */
#define sprite_list_074CB6_ADDRESS 0x6CB6u    /* 074CB6 */
#define sprite_list_074CC8_ADDRESS 0x6CC8u    /* 074CC8 */
#define sprite_list_074CDA_ADDRESS 0x6CDAu    /* 074CDA */
#define animation_074CEC_ADDRESS 0x6CECu    /* 074CEC */
#define sprite_list_074D20_ADDRESS 0x6D20u    /* 074D20 */
#define sprite_list_074D32_ADDRESS 0x6D32u    /* 074D32 */
#define sprite_list_074D44_ADDRESS 0x6D44u    /* 074D44 */
#define sprite_list_074D56_ADDRESS 0x6D56u    /* 074D56 */
#define sprite_list_074D6E_ADDRESS 0x6D6Eu    /* 074D6E */
#define sprite_list_074D8C_ADDRESS 0x6D8Cu    /* 074D8C */
#define sprite_list_074DA4_ADDRESS 0x6DA4u    /* 074DA4 */
#define animation_074DC2_ADDRESS 0x6DC2u    /* 074DC2 */
#define sprite_list_074DDA_ADDRESS 0x6DDAu    /* 074DDA */
#define sprite_list_074DF2_ADDRESS 0x6DF2u    /* 074DF2 */
#define animation_table_074E0A_ADDRESS 0x6E0Au    /* 074E0A */
#define animation_074E14_ADDRESS 0x6E14u    /* 074E14 */
#define sprite_list_074E1C_ADDRESS 0x6E1Cu    /* 074E1C */
#define animation_074E22_ADDRESS 0x6E22u    /* 074E22 */
#define sprite_list_074E46_ADDRESS 0x6E46u    /* 074E46 */
#define sprite_list_074E58_ADDRESS 0x6E58u    /* 074E58 */
#define sprite_list_074E6A_ADDRESS 0x6E6Au    /* 074E6A */
#define sprite_list_074E82_ADDRESS 0x6E82u    /* 074E82 */
#define sprite_list_074E9A_ADDRESS 0x6E9Au    /* 074E9A */
#define sprite_list_074EB2_ADDRESS 0x6EB2u    /* 074EB2 */
#define sprite_list_074ECA_ADDRESS 0x6ECAu    /* 074ECA */
#define sprite_list_074EE2_ADDRESS 0x6EE2u    /* 074EE2 */
#define animation_074EFA_ADDRESS 0x6EFAu    /* 074EFA */
#define sprite_list_074F1E_ADDRESS 0x6F1Eu    /* 074F1E */
#define sprite_list_074F36_ADDRESS 0x6F36u    /* 074F36 */
#define sprite_list_074F4E_ADDRESS 0x6F4Eu    /* 074F4E */
#define sprite_list_074F66_ADDRESS 0x6F66u    /* 074F66 */
#define sprite_list_074F7E_ADDRESS 0x6F7Eu    /* 074F7E */
#define sprite_list_074F96_ADDRESS 0x6F96u    /* 074F96 */
#define sprite_list_074FAE_ADDRESS 0x6FAEu    /* 074FAE */
#define animation_074FC6_ADDRESS 0x6FC6u    /* 074FC6 */
#define sprite_list_074FEA_ADDRESS 0x6FEAu    /* 074FEA */
#define sprite_list_074FFC_ADDRESS 0x6FFCu    /* 074FFC */
#define sprite_list_075014_ADDRESS 0x7014u    /* 075014 */
#define sprite_list_075032_ADDRESS 0x7032u    /* 075032 */
#define sprite_list_07504A_ADDRESS 0x704Au    /* 07504A */
#define sprite_list_075062_ADDRESS 0x7062u    /* 075062 */
#define sprite_list_075080_ADDRESS 0x7080u    /* 075080 */
#define sprite_list_07509E_ADDRESS 0x709Eu    /* 07509E */
#define animation_0750B6_ADDRESS 0x70B6u    /* 0750B6 */
#define sprite_list_0750C2_ADDRESS 0x70C2u    /* 0750C2 */
#define animation_table_0750D4_ADDRESS 0x70D4u    /* 0750D4 */
#define animation_0750D8_ADDRESS 0x70D8u    /* 0750D8 */
#define sprite_list_075114_ADDRESS 0x7114u    /* 075114 */
#define sprite_list_075120_ADDRESS 0x7120u    /* 075120 */
#define sprite_list_075132_ADDRESS 0x7132u    /* 075132 */
#define sprite_list_075144_ADDRESS 0x7144u    /* 075144 */
#define sprite_list_075156_ADDRESS 0x7156u    /* 075156 */
#define animation_075168_ADDRESS 0x7168u    /* 075168 */
#define sprite_list_07517C_ADDRESS 0x717Cu    /* 07517C */
#define sprite_list_075182_ADDRESS 0x7182u    /* 075182 */
#define sprite_list_075194_ADDRESS 0x7194u    /* 075194 */
#define sprite_list_0751A6_ADDRESS 0x71A6u    /* 0751A6 */
#define animation_table_0751AC_ADDRESS 0x71ACu    /* 0751AC */
#define animation_0751C2_ADDRESS 0x71C2u    /* 0751C2 */
#define sprite_list_0751CA_ADDRESS 0x71CAu    /* 0751CA */
#define animation_0751D0_ADDRESS 0x71D0u    /* 0751D0 */
#define sprite_list_0751E4_ADDRESS 0x71E4u    /* 0751E4 */
#define sprite_list_0751FC_ADDRESS 0x71FCu    /* 0751FC */
#define sprite_list_07521A_ADDRESS 0x721Au    /* 07521A */
#define animation_075238_ADDRESS 0x7238u    /* 075238 */
#define sprite_list_07524C_ADDRESS 0x724Cu    /* 07524C */
#define sprite_list_075264_ADDRESS 0x7264u    /* 075264 */
#define sprite_list_075282_ADDRESS 0x7282u    /* 075282 */
#define animation_0752A0_ADDRESS 0x72A0u    /* 0752A0 */
#define sprite_list_0752AC_ADDRESS 0x72ACu    /* 0752AC */
#define sprite_list_0752C4_ADDRESS 0x72C4u    /* 0752C4 */
#define animation_0752DC_ADDRESS 0x72DCu    /* 0752DC */
#define sprite_list_075300_ADDRESS 0x7300u    /* 075300 */
#define sprite_list_075312_ADDRESS 0x7312u    /* 075312 */
#define sprite_list_07532A_ADDRESS 0x732Au    /* 07532A */
#define sprite_list_075342_ADDRESS 0x7342u    /* 075342 */
#define sprite_list_07535A_ADDRESS 0x735Au    /* 07535A */
#define sprite_list_075372_ADDRESS 0x7372u    /* 075372 */
#define sprite_list_07538A_ADDRESS 0x738Au    /* 07538A */
#define sprite_list_07539C_ADDRESS 0x739Cu    /* 07539C */
#define animation_0753B4_ADDRESS 0x73B4u    /* 0753B4 */
#define sprite_list_0753C4_ADDRESS 0x73C4u    /* 0753C4 */
#define sprite_list_0753E2_ADDRESS 0x73E2u    /* 0753E2 */
#define sprite_list_075400_ADDRESS 0x7400u    /* 075400 */
#define animation_07541E_ADDRESS 0x741Eu    /* 07541E */
#define sprite_list_075436_ADDRESS 0x7436u    /* 075436 */
#define sprite_list_07544E_ADDRESS 0x744Eu    /* 07544E */
#define sprite_list_075466_ADDRESS 0x7466u    /* 075466 */
#define sprite_list_075484_ADDRESS 0x7484u    /* 075484 */
#define sprite_list_0754A2_ADDRESS 0x74A2u    /* 0754A2 */
#define animation_0754BA_ADDRESS 0x74BAu    /* 0754BA */
#define sprite_list_0754C6_ADDRESS 0x74C6u    /* 0754C6 */
#define sprite_list_0754DE_ADDRESS 0x74DEu    /* 0754DE */
#define animation_0754F6_ADDRESS 0x74F6u    /* 0754F6 */
#define animation_075506_ADDRESS 0x7506u    /* 075506 */
#define animation_table_07551A_ADDRESS 0x751Au    /* 07551A */
#define animation_075532_ADDRESS 0x7532u    /* 075532 */
#define sprite_list_07555A_ADDRESS 0x755Au    /* 07555A */
#define sprite_list_075584_ADDRESS 0x7584u    /* 075584 */
#define sprite_list_0755B4_ADDRESS 0x75B4u    /* 0755B4 */
#define sprite_list_0755DE_ADDRESS 0x75DEu    /* 0755DE */
#define sprite_list_075614_ADDRESS 0x7614u    /* 075614 */
#define sprite_list_07563E_ADDRESS 0x763Eu    /* 07563E */
#define sprite_list_075668_ADDRESS 0x7668u    /* 075668 */
#define animation_075692_ADDRESS 0x7692u    /* 075692 */
#define sprite_list_0756A6_ADDRESS 0x76A6u    /* 0756A6 */
#define animation_0756D0_ADDRESS 0x76D0u    /* 0756D0 */
#define animation_0756E4_ADDRESS 0x76E4u    /* 0756E4 */
#define sprite_list_075708_ADDRESS 0x7708u    /* 075708 */
#define sprite_list_07571A_ADDRESS 0x771Au    /* 07571A */
#define sprite_list_075726_ADDRESS 0x7726u    /* 075726 */
#define sprite_list_075732_ADDRESS 0x7732u    /* 075732 */
#define sprite_list_07573E_ADDRESS 0x773Eu    /* 07573E */
#define sprite_list_075750_ADDRESS 0x7750u    /* 075750 */
#define sprite_list_07575C_ADDRESS 0x775Cu    /* 07575C */
#define sprite_list_075768_ADDRESS 0x7768u    /* 075768 */
#define animation_07577A_ADDRESS 0x777Au    /* 07577A */
#define sprite_list_07579E_ADDRESS 0x779Eu    /* 07579E */
#define sprite_list_0757B0_ADDRESS 0x77B0u    /* 0757B0 */
#define sprite_list_0757C2_ADDRESS 0x77C2u    /* 0757C2 */
#define sprite_list_0757D4_ADDRESS 0x77D4u    /* 0757D4 */
#define sprite_list_0757E6_ADDRESS 0x77E6u    /* 0757E6 */
#define sprite_list_0757F8_ADDRESS 0x77F8u    /* 0757F8 */
#define sprite_list_07580A_ADDRESS 0x780Au    /* 07580A */
#define sprite_list_07581C_ADDRESS 0x781Cu    /* 07581C */
#define animation_07582E_ADDRESS 0x782Eu    /* 07582E */
#define sprite_list_075842_ADDRESS 0x7842u    /* 075842 */
#define sprite_list_07586C_ADDRESS 0x786Cu    /* 07586C */
#define sprite_list_075896_ADDRESS 0x7896u    /* 075896 */
#define sprite_list_0758B4_ADDRESS 0x78B4u    /* 0758B4 */
#define animation_0758F0_ADDRESS 0x78F0u    /* 0758F0 */
#define sprite_list_0758FC_ADDRESS 0x78FCu    /* 0758FC */
#define sprite_list_075926_ADDRESS 0x7926u    /* 075926 */
#define animation_075950_ADDRESS 0x7950u    /* 075950 */
#define sprite_list_07596C_ADDRESS 0x796Cu    /* 07596C */
#define sprite_list_075984_ADDRESS 0x7984u    /* 075984 */
#define sprite_list_0759A8_ADDRESS 0x79A8u    /* 0759A8 */
#define sprite_list_0759D2_ADDRESS 0x79D2u    /* 0759D2 */
#define sprite_list_0759FC_ADDRESS 0x79FCu    /* 0759FC */
#define animation_075A20_ADDRESS 0x7A20u    /* 075A20 */
#define sprite_list_075A2C_ADDRESS 0x7A2Cu    /* 075A2C */
#define sprite_list_075A50_ADDRESS 0x7A50u    /* 075A50 */
#define animation_075A7A_ADDRESS 0x7A7Au    /* 075A7A */
#define sprite_list_075AAE_ADDRESS 0x7AAEu    /* 075AAE */
#define sprite_list_075AE4_ADDRESS 0x7AE4u    /* 075AE4 */
#define sprite_list_075B26_ADDRESS 0x7B26u    /* 075B26 */
#define sprite_list_075B62_ADDRESS 0x7B62u    /* 075B62 */
#define sprite_list_075BBC_ADDRESS 0x7BBCu    /* 075BBC */
#define sprite_list_075C16_ADDRESS 0x7C16u    /* 075C16 */
#define sprite_list_075C6A_ADDRESS 0x7C6Au    /* 075C6A */
#define sprite_list_075CCA_ADDRESS 0x7CCAu    /* 075CCA */
#define sprite_list_075D24_ADDRESS 0x7D24u    /* 075D24 */
#define sprite_list_075D84_ADDRESS 0x7D84u    /* 075D84 */
#define sprite_list_075DD8_ADDRESS 0x7DD8u    /* 075DD8 */
#define sprite_list_075E32_ADDRESS 0x7E32u    /* 075E32 */
#define animation_075E74_ADDRESS 0x7E74u    /* 075E74 */
#define animation_075E7C_ADDRESS 0x7E7Cu    /* 075E7C */
#define sprite_list_075E84_ADDRESS 0x7E84u    /* 075E84 */
#define fill_075EB4_ADDRESS 0x7EB4u    /* 075EB4 */
#define set_index_076000_ADDRESS 0x6000u    /* 076000 */
#define animation_table_076004_ADDRESS 0x6004u    /* 076004 */
#define animation_076094_ADDRESS 0x6094u    /* 076094 */
#define sprite_list_07609C_ADDRESS 0x609Cu    /* 07609C */
#define animation_0760A2_ADDRESS 0x60A2u    /* 0760A2 */
#define sprite_list_0760C6_ADDRESS 0x60C6u    /* 0760C6 */
#define sprite_list_0760D8_ADDRESS 0x60D8u    /* 0760D8 */
#define sprite_list_0760EA_ADDRESS 0x60EAu    /* 0760EA */
#define sprite_list_0760FC_ADDRESS 0x60FCu    /* 0760FC */
#define sprite_list_07610E_ADDRESS 0x610Eu    /* 07610E */
#define sprite_list_076120_ADDRESS 0x6120u    /* 076120 */
#define sprite_list_076132_ADDRESS 0x6132u    /* 076132 */
#define sprite_list_076144_ADDRESS 0x6144u    /* 076144 */
#define animation_076156_ADDRESS 0x6156u    /* 076156 */
#define sprite_list_07617A_ADDRESS 0x617Au    /* 07617A */
#define sprite_list_076192_ADDRESS 0x6192u    /* 076192 */
#define sprite_list_0761A4_ADDRESS 0x61A4u    /* 0761A4 */
#define sprite_list_0761B6_ADDRESS 0x61B6u    /* 0761B6 */
#define sprite_list_0761C8_ADDRESS 0x61C8u    /* 0761C8 */
#define sprite_list_0761DA_ADDRESS 0x61DAu    /* 0761DA */
#define sprite_list_0761EC_ADDRESS 0x61ECu    /* 0761EC */
#define sprite_list_0761FE_ADDRESS 0x61FEu    /* 0761FE */
#define animation_076210_ADDRESS 0x6210u    /* 076210 */
#define sprite_list_076234_ADDRESS 0x6234u    /* 076234 */
#define sprite_list_076246_ADDRESS 0x6246u    /* 076246 */
#define sprite_list_076258_ADDRESS 0x6258u    /* 076258 */
#define sprite_list_07626A_ADDRESS 0x626Au    /* 07626A */
#define sprite_list_07627C_ADDRESS 0x627Cu    /* 07627C */
#define sprite_list_07628E_ADDRESS 0x628Eu    /* 07628E */
#define sprite_list_0762A0_ADDRESS 0x62A0u    /* 0762A0 */
#define sprite_list_0762B2_ADDRESS 0x62B2u    /* 0762B2 */
#define animation_0762C4_ADDRESS 0x62C4u    /* 0762C4 */
#define sprite_list_0762D0_ADDRESS 0x62D0u    /* 0762D0 */
#define sprite_list_0762D6_ADDRESS 0x62D6u    /* 0762D6 */
#define animation_0762DC_ADDRESS 0x62DCu    /* 0762DC */
#define sprite_list_0762E8_ADDRESS 0x62E8u    /* 0762E8 */
#define sprite_list_0762EE_ADDRESS 0x62EEu    /* 0762EE */
#define animation_0762F4_ADDRESS 0x62F4u    /* 0762F4 */
#define sprite_list_076300_ADDRESS 0x6300u    /* 076300 */
#define sprite_list_076306_ADDRESS 0x6306u    /* 076306 */
#define animation_07630C_ADDRESS 0x630Cu    /* 07630C */
#define sprite_list_076318_ADDRESS 0x6318u    /* 076318 */
#define sprite_list_07631E_ADDRESS 0x631Eu    /* 07631E */
#define animation_07632A_ADDRESS 0x632Au    /* 07632A */
#define sprite_list_076342_ADDRESS 0x6342u    /* 076342 */
#define sprite_list_07634E_ADDRESS 0x634Eu    /* 07634E */
#define sprite_list_07635A_ADDRESS 0x635Au    /* 07635A */
#define sprite_list_076366_ADDRESS 0x6366u    /* 076366 */
#define sprite_list_076378_ADDRESS 0x6378u    /* 076378 */
#define animation_07637E_ADDRESS 0x637Eu    /* 07637E */
#define sprite_list_07639A_ADDRESS 0x639Au    /* 07639A */
#define sprite_list_0763A6_ADDRESS 0x63A6u    /* 0763A6 */
#define sprite_list_0763AC_ADDRESS 0x63ACu    /* 0763AC */
#define sprite_list_0763B8_ADDRESS 0x63B8u    /* 0763B8 */
#define animation_0763C4_ADDRESS 0x63C4u    /* 0763C4 */
#define sprite_list_0763D8_ADDRESS 0x63D8u    /* 0763D8 */
#define sprite_list_0763DE_ADDRESS 0x63DEu    /* 0763DE */
#define sprite_list_0763EA_ADDRESS 0x63EAu    /* 0763EA */
#define sprite_list_0763F6_ADDRESS 0x63F6u    /* 0763F6 */
#define animation_0763FC_ADDRESS 0x63FCu    /* 0763FC */
#define sprite_list_076414_ADDRESS 0x6414u    /* 076414 */
#define sprite_list_076426_ADDRESS 0x6426u    /* 076426 */
#define sprite_list_076438_ADDRESS 0x6438u    /* 076438 */
#define sprite_list_076444_ADDRESS 0x6444u    /* 076444 */
#define sprite_list_076456_ADDRESS 0x6456u    /* 076456 */
#define animation_076468_ADDRESS 0x6468u    /* 076468 */
#define sprite_list_076488_ADDRESS 0x6488u    /* 076488 */
#define sprite_list_076494_ADDRESS 0x6494u    /* 076494 */
#define sprite_list_0764A6_ADDRESS 0x64A6u    /* 0764A6 */
#define sprite_list_0764B8_ADDRESS 0x64B8u    /* 0764B8 */
#define sprite_list_0764CA_ADDRESS 0x64CAu    /* 0764CA */
#define sprite_list_0764D6_ADDRESS 0x64D6u    /* 0764D6 */
#define animation_0764E2_ADDRESS 0x64E2u    /* 0764E2 */
#define sprite_list_0764EE_ADDRESS 0x64EEu    /* 0764EE */
#define sprite_list_0764FA_ADDRESS 0x64FAu    /* 0764FA */
#define animation_076506_ADDRESS 0x6506u    /* 076506 */
#define sprite_list_07652A_ADDRESS 0x652Au    /* 07652A */
#define sprite_list_07653C_ADDRESS 0x653Cu    /* 07653C */
#define sprite_list_076548_ADDRESS 0x6548u    /* 076548 */
#define sprite_list_07655A_ADDRESS 0x655Au    /* 07655A */
#define sprite_list_076560_ADDRESS 0x6560u    /* 076560 */
#define animation_076566_ADDRESS 0x6566u    /* 076566 */
#define sprite_list_076582_ADDRESS 0x6582u    /* 076582 */
#define sprite_list_07658E_ADDRESS 0x658Eu    /* 07658E */
#define sprite_list_07659A_ADDRESS 0x659Au    /* 07659A */
#define sprite_list_0765B2_ADDRESS 0x65B2u    /* 0765B2 */
#define animation_0765CA_ADDRESS 0x65CAu    /* 0765CA */
#define sprite_list_0765EE_ADDRESS 0x65EEu    /* 0765EE */
#define sprite_list_076600_ADDRESS 0x6600u    /* 076600 */
#define sprite_list_07660C_ADDRESS 0x660Cu    /* 07660C */
#define sprite_list_076618_ADDRESS 0x6618u    /* 076618 */
#define sprite_list_076624_ADDRESS 0x6624u    /* 076624 */
#define sprite_list_076630_ADDRESS 0x6630u    /* 076630 */
#define sprite_list_07663C_ADDRESS 0x663Cu    /* 07663C */
#define sprite_list_076648_ADDRESS 0x6648u    /* 076648 */
#define animation_07665A_ADDRESS 0x665Au    /* 07665A */
#define sprite_list_07667E_ADDRESS 0x667Eu    /* 07667E */
#define sprite_list_076684_ADDRESS 0x6684u    /* 076684 */
#define sprite_list_07668A_ADDRESS 0x668Au    /* 07668A */
#define sprite_list_076690_ADDRESS 0x6690u    /* 076690 */
#define sprite_list_076696_ADDRESS 0x6696u    /* 076696 */
#define sprite_list_07669C_ADDRESS 0x669Cu    /* 07669C */
#define sprite_list_0766A2_ADDRESS 0x66A2u    /* 0766A2 */
#define sprite_list_0766A8_ADDRESS 0x66A8u    /* 0766A8 */
#define animation_0766AE_ADDRESS 0x66AEu    /* 0766AE */
#define sprite_list_0766C6_ADDRESS 0x66C6u    /* 0766C6 */
#define sprite_list_0766D2_ADDRESS 0x66D2u    /* 0766D2 */
#define sprite_list_0766DE_ADDRESS 0x66DEu    /* 0766DE */
#define sprite_list_0766E4_ADDRESS 0x66E4u    /* 0766E4 */
#define animation_0766EA_ADDRESS 0x66EAu    /* 0766EA */
#define sprite_list_0766FE_ADDRESS 0x66FEu    /* 0766FE */
#define sprite_list_076704_ADDRESS 0x6704u    /* 076704 */
#define sprite_list_076716_ADDRESS 0x6716u    /* 076716 */
#define animation_076728_ADDRESS 0x6728u    /* 076728 */
#define sprite_list_07673C_ADDRESS 0x673Cu    /* 07673C */
#define sprite_list_076742_ADDRESS 0x6742u    /* 076742 */
#define sprite_list_07674E_ADDRESS 0x674Eu    /* 07674E */
#define animation_07675A_ADDRESS 0x675Au    /* 07675A */
#define sprite_list_076766_ADDRESS 0x6766u    /* 076766 */
#define sprite_list_07676C_ADDRESS 0x676Cu    /* 07676C */
#define animation_076772_ADDRESS 0x6772u    /* 076772 */
#define sprite_list_076786_ADDRESS 0x6786u    /* 076786 */
#define sprite_list_07678C_ADDRESS 0x678Cu    /* 07678C */
#define sprite_list_076798_ADDRESS 0x6798u    /* 076798 */
#define sprite_list_0767A4_ADDRESS 0x67A4u    /* 0767A4 */
#define animation_0767AA_ADDRESS 0x67AAu    /* 0767AA */
#define sprite_list_0767C2_ADDRESS 0x67C2u    /* 0767C2 */
#define sprite_list_0767C8_ADDRESS 0x67C8u    /* 0767C8 */
#define sprite_list_0767DA_ADDRESS 0x67DAu    /* 0767DA */
#define sprite_list_0767EC_ADDRESS 0x67ECu    /* 0767EC */
#define animation_0767F8_ADDRESS 0x67F8u    /* 0767F8 */
#define sprite_list_07681C_ADDRESS 0x681Cu    /* 07681C */
#define sprite_list_076822_ADDRESS 0x6822u    /* 076822 */
#define sprite_list_07682E_ADDRESS 0x682Eu    /* 07682E */
#define animation_07683A_ADDRESS 0x683Au    /* 07683A */
#define sprite_list_07685E_ADDRESS 0x685Eu    /* 07685E */
#define sprite_list_076864_ADDRESS 0x6864u    /* 076864 */
#define sprite_list_076870_ADDRESS 0x6870u    /* 076870 */
#define sprite_list_076882_ADDRESS 0x6882u    /* 076882 */
#define sprite_list_076894_ADDRESS 0x6894u    /* 076894 */
#define sprite_list_0768AC_ADDRESS 0x68ACu    /* 0768AC */
#define sprite_list_0768BE_ADDRESS 0x68BEu    /* 0768BE */
#define sprite_list_0768D0_ADDRESS 0x68D0u    /* 0768D0 */
#define animation_0768DC_ADDRESS 0x68DCu    /* 0768DC */
#define sprite_list_0768E8_ADDRESS 0x68E8u    /* 0768E8 */
#define animation_0768F4_ADDRESS 0x68F4u    /* 0768F4 */
#define sprite_list_076908_ADDRESS 0x6908u    /* 076908 */
#define sprite_list_07690E_ADDRESS 0x690Eu    /* 07690E */
#define sprite_list_07691A_ADDRESS 0x691Au    /* 07691A */
#define sprite_list_076926_ADDRESS 0x6926u    /* 076926 */
#define animation_07693E_ADDRESS 0x693Eu    /* 07693E */
#define sprite_list_076946_ADDRESS 0x6946u    /* 076946 */
#define animation_07694C_ADDRESS 0x694Cu    /* 07694C */
#define sprite_list_076968_ADDRESS 0x6968u    /* 076968 */
#define sprite_list_07696E_ADDRESS 0x696Eu    /* 07696E */
#define sprite_list_076980_ADDRESS 0x6980u    /* 076980 */
#define sprite_list_076992_ADDRESS 0x6992u    /* 076992 */
#define sprite_list_07699E_ADDRESS 0x699Eu    /* 07699E */
#define animation_0769B0_ADDRESS 0x69B0u    /* 0769B0 */
#define sprite_list_0769DC_ADDRESS 0x69DCu    /* 0769DC */
#define sprite_list_0769E2_ADDRESS 0x69E2u    /* 0769E2 */
#define sprite_list_0769F4_ADDRESS 0x69F4u    /* 0769F4 */
#define sprite_list_076A00_ADDRESS 0x6A00u    /* 076A00 */
#define sprite_list_076A0C_ADDRESS 0x6A0Cu    /* 076A0C */
#define sprite_list_076A18_ADDRESS 0x6A18u    /* 076A18 */
#define sprite_list_076A24_ADDRESS 0x6A24u    /* 076A24 */
#define sprite_list_076A30_ADDRESS 0x6A30u    /* 076A30 */
#define sprite_list_076A3C_ADDRESS 0x6A3Cu    /* 076A3C */
#define animation_076A42_ADDRESS 0x6A42u    /* 076A42 */
#define sprite_list_076A5E_ADDRESS 0x6A5Eu    /* 076A5E */
#define sprite_list_076A70_ADDRESS 0x6A70u    /* 076A70 */
#define sprite_list_076A7C_ADDRESS 0x6A7Cu    /* 076A7C */
#define animation_076A8E_ADDRESS 0x6A8Eu    /* 076A8E */
#define sprite_list_076A96_ADDRESS 0x6A96u    /* 076A96 */
#define animation_076A9C_ADDRESS 0x6A9Cu    /* 076A9C */
#define sprite_list_076AB8_ADDRESS 0x6AB8u    /* 076AB8 */
#define sprite_list_076ACA_ADDRESS 0x6ACAu    /* 076ACA */
#define sprite_list_076ADC_ADDRESS 0x6ADCu    /* 076ADC */
#define animation_076AE8_ADDRESS 0x6AE8u    /* 076AE8 */
#define sprite_list_076B00_ADDRESS 0x6B00u    /* 076B00 */
#define animation_076B0C_ADDRESS 0x6B0Cu    /* 076B0C */
#define sprite_list_076B28_ADDRESS 0x6B28u    /* 076B28 */
#define sprite_list_076B34_ADDRESS 0x6B34u    /* 076B34 */
#define sprite_list_076B3A_ADDRESS 0x6B3Au    /* 076B3A */
#define sprite_list_076B46_ADDRESS 0x6B46u    /* 076B46 */
#define animation_076B4C_ADDRESS 0x6B4Cu    /* 076B4C */
#define sprite_list_076B60_ADDRESS 0x6B60u    /* 076B60 */
#define sprite_list_076B66_ADDRESS 0x6B66u    /* 076B66 */
#define sprite_list_076B6C_ADDRESS 0x6B6Cu    /* 076B6C */
#define sprite_list_076B72_ADDRESS 0x6B72u    /* 076B72 */
#define animation_076B78_ADDRESS 0x6B78u    /* 076B78 */
#define sprite_list_076B90_ADDRESS 0x6B90u    /* 076B90 */
#define sprite_list_076B96_ADDRESS 0x6B96u    /* 076B96 */
#define sprite_list_076B9C_ADDRESS 0x6B9Cu    /* 076B9C */
#define sprite_list_076BA2_ADDRESS 0x6BA2u    /* 076BA2 */
#define animation_076BAE_ADDRESS 0x6BAEu    /* 076BAE */
#define sprite_list_076BB6_ADDRESS 0x6BB6u    /* 076BB6 */
#define animation_076BBC_ADDRESS 0x6BBCu    /* 076BBC */
#define sprite_list_076BE0_ADDRESS 0x6BE0u    /* 076BE0 */
#define sprite_list_076BF8_ADDRESS 0x6BF8u    /* 076BF8 */
#define sprite_list_076C10_ADDRESS 0x6C10u    /* 076C10 */
#define sprite_list_076C28_ADDRESS 0x6C28u    /* 076C28 */
#define sprite_list_076C40_ADDRESS 0x6C40u    /* 076C40 */
#define sprite_list_076C58_ADDRESS 0x6C58u    /* 076C58 */
#define sprite_list_076C70_ADDRESS 0x6C70u    /* 076C70 */
#define sprite_list_076C88_ADDRESS 0x6C88u    /* 076C88 */
#define animation_076CA0_ADDRESS 0x6CA0u    /* 076CA0 */
#define sprite_list_076CB4_ADDRESS 0x6CB4u    /* 076CB4 */
#define sprite_list_076CBA_ADDRESS 0x6CBAu    /* 076CBA */
#define sprite_list_076CC0_ADDRESS 0x6CC0u    /* 076CC0 */
#define sprite_list_076CC6_ADDRESS 0x6CC6u    /* 076CC6 */
#define animation_076CCC_ADDRESS 0x6CCCu    /* 076CCC */
#define sprite_list_076CDC_ADDRESS 0x6CDCu    /* 076CDC */
#define sprite_list_076CE2_ADDRESS 0x6CE2u    /* 076CE2 */
#define sprite_list_076CE8_ADDRESS 0x6CE8u    /* 076CE8 */
#define animation_076CEE_ADDRESS 0x6CEEu    /* 076CEE */
#define sprite_list_076CFE_ADDRESS 0x6CFEu    /* 076CFE */
#define sprite_list_076D04_ADDRESS 0x6D04u    /* 076D04 */
#define sprite_list_076D0A_ADDRESS 0x6D0Au    /* 076D0A */
#define animation_076D10_ADDRESS 0x6D10u    /* 076D10 */
#define sprite_list_076D34_ADDRESS 0x6D34u    /* 076D34 */
#define sprite_list_076D4C_ADDRESS 0x6D4Cu    /* 076D4C */
#define sprite_list_076D64_ADDRESS 0x6D64u    /* 076D64 */
#define sprite_list_076D7C_ADDRESS 0x6D7Cu    /* 076D7C */
#define sprite_list_076D94_ADDRESS 0x6D94u    /* 076D94 */
#define sprite_list_076DAC_ADDRESS 0x6DACu    /* 076DAC */
#define sprite_list_076DC4_ADDRESS 0x6DC4u    /* 076DC4 */
#define sprite_list_076DDC_ADDRESS 0x6DDCu    /* 076DDC */
#define animation_076DF4_ADDRESS 0x6DF4u    /* 076DF4 */
#define sprite_list_076DFC_ADDRESS 0x6DFCu    /* 076DFC */
#define animation_076E0E_ADDRESS 0x6E0Eu    /* 076E0E */
#define sprite_list_076E1A_ADDRESS 0x6E1Au    /* 076E1A */
#define sprite_list_076E20_ADDRESS 0x6E20u    /* 076E20 */
#define animation_076E26_ADDRESS 0x6E26u    /* 076E26 */
#define sprite_list_076E3A_ADDRESS 0x6E3Au    /* 076E3A */
#define sprite_list_076E52_ADDRESS 0x6E52u    /* 076E52 */
#define sprite_list_076E6A_ADDRESS 0x6E6Au    /* 076E6A */
#define sprite_list_076E82_ADDRESS 0x6E82u    /* 076E82 */
#define animation_076E9A_ADDRESS 0x6E9Au    /* 076E9A */
#define animation_076EAE_ADDRESS 0x6EAEu    /* 076EAE */
#define sprite_list_076ECA_ADDRESS 0x6ECAu    /* 076ECA */
#define sprite_list_076EE2_ADDRESS 0x6EE2u    /* 076EE2 */
#define sprite_list_076EFA_ADDRESS 0x6EFAu    /* 076EFA */
#define sprite_list_076F12_ADDRESS 0x6F12u    /* 076F12 */
#define sprite_list_076F2A_ADDRESS 0x6F2Au    /* 076F2A */
#define animation_076F42_ADDRESS 0x6F42u    /* 076F42 */
#define sprite_list_076F5A_ADDRESS 0x6F5Au    /* 076F5A */
#define animation_076F78_ADDRESS 0x6F78u    /* 076F78 */
#define sprite_list_076F94_ADDRESS 0x6F94u    /* 076F94 */
#define sprite_list_076FB2_ADDRESS 0x6FB2u    /* 076FB2 */
#define sprite_list_076FCA_ADDRESS 0x6FCAu    /* 076FCA */
#define sprite_list_076FE2_ADDRESS 0x6FE2u    /* 076FE2 */
#define sprite_list_076FFA_ADDRESS 0x6FFAu    /* 076FFA */
#define animation_077012_ADDRESS 0x7012u    /* 077012 */
#define sprite_list_07702A_ADDRESS 0x702Au    /* 07702A */
#define animation_077042_ADDRESS 0x7042u    /* 077042 */
#define sprite_list_07705E_ADDRESS 0x705Eu    /* 07705E */
#define sprite_list_07707C_ADDRESS 0x707Cu    /* 07707C */
#define sprite_list_077094_ADDRESS 0x7094u    /* 077094 */
#define sprite_list_0770B2_ADDRESS 0x70B2u    /* 0770B2 */
#define sprite_list_0770D0_ADDRESS 0x70D0u    /* 0770D0 */
#define animation_0770EE_ADDRESS 0x70EEu    /* 0770EE */
#define sprite_list_077106_ADDRESS 0x7106u    /* 077106 */
#define animation_07711E_ADDRESS 0x711Eu    /* 07711E */
#define sprite_list_07713A_ADDRESS 0x713Au    /* 07713A */
#define sprite_list_077158_ADDRESS 0x7158u    /* 077158 */
#define sprite_list_077170_ADDRESS 0x7170u    /* 077170 */
#define sprite_list_07718E_ADDRESS 0x718Eu    /* 07718E */
#define sprite_list_0771AC_ADDRESS 0x71ACu    /* 0771AC */
#define animation_0771CA_ADDRESS 0x71CAu    /* 0771CA */
#define sprite_list_0771E2_ADDRESS 0x71E2u    /* 0771E2 */
#define animation_0771FA_ADDRESS 0x71FAu    /* 0771FA */
#define sprite_list_077212_ADDRESS 0x7212u    /* 077212 */
#define sprite_list_07721E_ADDRESS 0x721Eu    /* 07721E */
#define sprite_list_077224_ADDRESS 0x7224u    /* 077224 */
#define sprite_list_077230_ADDRESS 0x7230u    /* 077230 */
#define sprite_list_077242_ADDRESS 0x7242u    /* 077242 */
#define animation_07724E_ADDRESS 0x724Eu    /* 07724E */
#define sprite_list_07725E_ADDRESS 0x725Eu    /* 07725E */
#define sprite_list_07726A_ADDRESS 0x726Au    /* 07726A */
#define animation_077276_ADDRESS 0x7276u    /* 077276 */
#define sprite_list_0772A2_ADDRESS 0x72A2u    /* 0772A2 */
#define sprite_list_0772A8_ADDRESS 0x72A8u    /* 0772A8 */
#define sprite_list_0772AE_ADDRESS 0x72AEu    /* 0772AE */
#define sprite_list_0772BA_ADDRESS 0x72BAu    /* 0772BA */
#define sprite_list_0772C6_ADDRESS 0x72C6u    /* 0772C6 */
#define sprite_list_0772CC_ADDRESS 0x72CCu    /* 0772CC */
#define sprite_list_0772D2_ADDRESS 0x72D2u    /* 0772D2 */
#define sprite_list_0772D8_ADDRESS 0x72D8u    /* 0772D8 */
#define sprite_list_0772DE_ADDRESS 0x72DEu    /* 0772DE */
#define sprite_list_0772E4_ADDRESS 0x72E4u    /* 0772E4 */
#define animation_table_0772EA_ADDRESS 0x72EAu    /* 0772EA */
#define animation_07733A_ADDRESS 0x733Au    /* 07733A */
#define sprite_list_077342_ADDRESS 0x7342u    /* 077342 */
#define animation_077354_ADDRESS 0x7354u    /* 077354 */
#define sprite_list_077378_ADDRESS 0x7378u    /* 077378 */
#define sprite_list_07738A_ADDRESS 0x738Au    /* 07738A */
#define sprite_list_07739C_ADDRESS 0x739Cu    /* 07739C */
#define sprite_list_0773AE_ADDRESS 0x73AEu    /* 0773AE */
#define sprite_list_0773C0_ADDRESS 0x73C0u    /* 0773C0 */
#define sprite_list_0773D2_ADDRESS 0x73D2u    /* 0773D2 */
#define sprite_list_0773E4_ADDRESS 0x73E4u    /* 0773E4 */
#define sprite_list_0773F6_ADDRESS 0x73F6u    /* 0773F6 */
#define animation_077408_ADDRESS 0x7408u    /* 077408 */
#define sprite_list_07742C_ADDRESS 0x742Cu    /* 07742C */
#define sprite_list_07743E_ADDRESS 0x743Eu    /* 07743E */
#define sprite_list_077450_ADDRESS 0x7450u    /* 077450 */
#define sprite_list_077462_ADDRESS 0x7462u    /* 077462 */
#define sprite_list_077474_ADDRESS 0x7474u    /* 077474 */
#define sprite_list_077486_ADDRESS 0x7486u    /* 077486 */
#define sprite_list_077498_ADDRESS 0x7498u    /* 077498 */
#define sprite_list_0774AA_ADDRESS 0x74AAu    /* 0774AA */
#define animation_0774BC_ADDRESS 0x74BCu    /* 0774BC */
#define sprite_list_0774E0_ADDRESS 0x74E0u    /* 0774E0 */
#define sprite_list_0774F2_ADDRESS 0x74F2u    /* 0774F2 */
#define sprite_list_077504_ADDRESS 0x7504u    /* 077504 */
#define sprite_list_077516_ADDRESS 0x7516u    /* 077516 */
#define sprite_list_077528_ADDRESS 0x7528u    /* 077528 */
#define sprite_list_07753A_ADDRESS 0x753Au    /* 07753A */
#define sprite_list_07754C_ADDRESS 0x754Cu    /* 07754C */
#define sprite_list_07755E_ADDRESS 0x755Eu    /* 07755E */
#define animation_077570_ADDRESS 0x7570u    /* 077570 */
#define sprite_list_07757C_ADDRESS 0x757Cu    /* 07757C */
#define sprite_list_07758E_ADDRESS 0x758Eu    /* 07758E */
#define animation_0775A0_ADDRESS 0x75A0u    /* 0775A0 */
#define sprite_list_0775AC_ADDRESS 0x75ACu    /* 0775AC */
#define sprite_list_0775BE_ADDRESS 0x75BEu    /* 0775BE */
#define animation_0775D0_ADDRESS 0x75D0u    /* 0775D0 */
#define sprite_list_0775DC_ADDRESS 0x75DCu    /* 0775DC */
#define sprite_list_0775EE_ADDRESS 0x75EEu    /* 0775EE */
#define animation_077600_ADDRESS 0x7600u    /* 077600 */
#define sprite_list_07760C_ADDRESS 0x760Cu    /* 07760C */
#define sprite_list_077624_ADDRESS 0x7624u    /* 077624 */
#define animation_07763C_ADDRESS 0x763Cu    /* 07763C */
#define sprite_list_077658_ADDRESS 0x7658u    /* 077658 */
#define sprite_list_077670_ADDRESS 0x7670u    /* 077670 */
#define sprite_list_077682_ADDRESS 0x7682u    /* 077682 */
#define sprite_list_07769A_ADDRESS 0x769Au    /* 07769A */
#define animation_0776B2_ADDRESS 0x76B2u    /* 0776B2 */
#define sprite_list_0776C6_ADDRESS 0x76C6u    /* 0776C6 */
#define sprite_list_0776D8_ADDRESS 0x76D8u    /* 0776D8 */
#define sprite_list_0776F0_ADDRESS 0x76F0u    /* 0776F0 */
#define sprite_list_077708_ADDRESS 0x7708u    /* 077708 */
#define animation_07771A_ADDRESS 0x771Au    /* 07771A */
#define sprite_list_077732_ADDRESS 0x7732u    /* 077732 */
#define sprite_list_077750_ADDRESS 0x7750u    /* 077750 */
#define sprite_list_07776E_ADDRESS 0x776Eu    /* 07776E */
#define sprite_list_077786_ADDRESS 0x7786u    /* 077786 */
#define sprite_list_0777A4_ADDRESS 0x77A4u    /* 0777A4 */
#define animation_0777C2_ADDRESS 0x77C2u    /* 0777C2 */
#define sprite_list_0777E2_ADDRESS 0x77E2u    /* 0777E2 */
#define sprite_list_077800_ADDRESS 0x7800u    /* 077800 */
#define sprite_list_07781E_ADDRESS 0x781Eu    /* 07781E */
#define sprite_list_077836_ADDRESS 0x7836u    /* 077836 */
#define animation_07784E_ADDRESS 0x784Eu    /* 07784E */
#define sprite_list_07785A_ADDRESS 0x785Au    /* 07785A */
#define sprite_list_077872_ADDRESS 0x7872u    /* 077872 */
#define animation_07788A_ADDRESS 0x788Au    /* 07788A */
#define sprite_list_0778AE_ADDRESS 0x78AEu    /* 0778AE */
#define sprite_list_0778CC_ADDRESS 0x78CCu    /* 0778CC */
#define sprite_list_0778E4_ADDRESS 0x78E4u    /* 0778E4 */
#define sprite_list_077902_ADDRESS 0x7902u    /* 077902 */
#define sprite_list_077914_ADDRESS 0x7914u    /* 077914 */
#define animation_077926_ADDRESS 0x7926u    /* 077926 */
#define sprite_list_077942_ADDRESS 0x7942u    /* 077942 */
#define sprite_list_07795A_ADDRESS 0x795Au    /* 07795A */
#define sprite_list_077972_ADDRESS 0x7972u    /* 077972 */
#define sprite_list_077996_ADDRESS 0x7996u    /* 077996 */
#define animation_0779BA_ADDRESS 0x79BAu    /* 0779BA */
#define sprite_list_0779DE_ADDRESS 0x79DEu    /* 0779DE */
#define sprite_list_0779EA_ADDRESS 0x79EAu    /* 0779EA */
#define sprite_list_0779F6_ADDRESS 0x79F6u    /* 0779F6 */
#define sprite_list_077A02_ADDRESS 0x7A02u    /* 077A02 */
#define sprite_list_077A0E_ADDRESS 0x7A0Eu    /* 077A0E */
#define sprite_list_077A1A_ADDRESS 0x7A1Au    /* 077A1A */
#define sprite_list_077A26_ADDRESS 0x7A26u    /* 077A26 */
#define sprite_list_077A32_ADDRESS 0x7A32u    /* 077A32 */
#define animation_077A44_ADDRESS 0x7A44u    /* 077A44 */
#define sprite_list_077A5C_ADDRESS 0x7A5Cu    /* 077A5C */
#define sprite_list_077A74_ADDRESS 0x7A74u    /* 077A74 */
#define sprite_list_077A80_ADDRESS 0x7A80u    /* 077A80 */
#define animation_077A8C_ADDRESS 0x7A8Cu    /* 077A8C */
#define sprite_list_077AAC_ADDRESS 0x7AACu    /* 077AAC */
#define sprite_list_077AC4_ADDRESS 0x7AC4u    /* 077AC4 */
#define sprite_list_077AD0_ADDRESS 0x7AD0u    /* 077AD0 */
#define sprite_list_077AE2_ADDRESS 0x7AE2u    /* 077AE2 */
#define sprite_list_077AF4_ADDRESS 0x7AF4u    /* 077AF4 */
#define sprite_list_077B06_ADDRESS 0x7B06u    /* 077B06 */
#define animation_077B18_ADDRESS 0x7B18u    /* 077B18 */
#define sprite_list_077B30_ADDRESS 0x7B30u    /* 077B30 */
#define sprite_list_077B42_ADDRESS 0x7B42u    /* 077B42 */
#define sprite_list_077B66_ADDRESS 0x7B66u    /* 077B66 */
#define sprite_list_077B7E_ADDRESS 0x7B7Eu    /* 077B7E */
#define animation_077B8A_ADDRESS 0x7B8Au    /* 077B8A */
#define sprite_list_077B9E_ADDRESS 0x7B9Eu    /* 077B9E */
#define sprite_list_077BB0_ADDRESS 0x7BB0u    /* 077BB0 */
#define animation_077BC2_ADDRESS 0x7BC2u    /* 077BC2 */
#define sprite_list_077BDE_ADDRESS 0x7BDEu    /* 077BDE */
#define sprite_list_077BF6_ADDRESS 0x7BF6u    /* 077BF6 */
#define sprite_list_077C08_ADDRESS 0x7C08u    /* 077C08 */
#define sprite_list_077C20_ADDRESS 0x7C20u    /* 077C20 */
#define animation_077C32_ADDRESS 0x7C32u    /* 077C32 */
#define sprite_list_077C3A_ADDRESS 0x7C3Au    /* 077C3A */
#define animation_077C46_ADDRESS 0x7C46u    /* 077C46 */
#define animation_077C5A_ADDRESS 0x7C5Au    /* 077C5A */
#define animation_077C62_ADDRESS 0x7C62u    /* 077C62 */
#define animation_077C6A_ADDRESS 0x7C6Au    /* 077C6A */
#define sprite_list_077C72_ADDRESS 0x7C72u    /* 077C72 */
#define animation_077C7E_ADDRESS 0x7C7Eu    /* 077C7E */
#define sprite_list_077C86_ADDRESS 0x7C86u    /* 077C86 */
#define animation_077C92_ADDRESS 0x7C92u    /* 077C92 */
#define sprite_list_077C9A_ADDRESS 0x7C9Au    /* 077C9A */
#define fill_077CA6_ADDRESS 0x7CA6u    /* 077CA6 */
#define loaded_table_078000_ADDRESS 0x8000u    /* 078000 */
#define code_read_as_tiles_078593_ADDRESS 0x8593u    /* 078593 */
#define code_read_as_tiles_0785DB_ADDRESS 0x85DBu    /* 0785DB */
#define code_read_as_tiles_0785F9_ADDRESS 0x85F9u    /* 0785F9 */
#define code_read_as_tiles_078662_ADDRESS 0x8662u    /* 078662 */
#define code_read_as_a_map_078668_ADDRESS 0x8668u    /* 078668 */
#define code_read_as_tiles_07BAEC_ADDRESS 0xBAECu    /* 07BAEC */
#define loaded_table_07BCAA_ADDRESS 0xBCAAu    /* 07BCAA */
#define code_read_as_tiles_07BCBA_ADDRESS 0xBCBAu    /* 07BCBA */
#define fill_07D8B9_ADDRESS 0xD8B9u    /* 07D8B9 */
#define code_read_as_a_map_07DA7B_ADDRESS 0xDA7Bu    /* 07DA7B */
#define fill_07E2DB_ADDRESS 0xE2DBu    /* 07E2DB */
#define loaded_table_07E380_ADDRESS 0xE380u    /* 07E380 */
#define loaded_table_07E3D0_ADDRESS 0xE3D0u    /* 07E3D0 */
#define loaded_table_07E3FB_ADDRESS 0xE3FBu    /* 07E3FB */
#define loaded_table_07E41B_ADDRESS 0xE41Bu    /* 07E41B */
#define loaded_table_07E42B_ADDRESS 0xE42Bu    /* 07E42B */
#define loaded_table_07E431_ADDRESS 0xE431u    /* 07E431 */
#define loaded_table_07E445_ADDRESS 0xE445u    /* 07E445 */
#define indexed_table_07E530_ADDRESS 0xE530u    /* 07E530 */
#define indexed_table_07E53C_ADDRESS 0xE53Cu    /* 07E53C */
#define indexed_table_07E548_ADDRESS 0xE548u    /* 07E548 */
#define indexed_table_07E554_ADDRESS 0xE554u    /* 07E554 */
#define indexed_table_07E560_ADDRESS 0xE560u    /* 07E560 */
#define loaded_table_07E56C_ADDRESS 0xE56Cu    /* 07E56C */
#define loaded_table_07E66B_ADDRESS 0xE66Bu    /* 07E66B */
#define loaded_table_07E677_ADDRESS 0xE677u    /* 07E677 */
#define loaded_table_07E67F_ADDRESS 0xE67Fu    /* 07E67F */
#define loaded_table_07E687_ADDRESS 0xE687u    /* 07E687 */
#define loaded_table_07E68B_ADDRESS 0xE68Bu    /* 07E68B */
#define loaded_table_07E693_ADDRESS 0xE693u    /* 07E693 */
#define loaded_table_07E69B_ADDRESS 0xE69Bu    /* 07E69B */
#define demo_07E6A7_ADDRESS 0xE6A7u    /* 07E6A7 */
#define demo_07E6B3_ADDRESS 0xE6B3u    /* 07E6B3 */
#define demo_07E6BF_ADDRESS 0xE6BFu    /* 07E6BF */
#define loaded_table_07E6CB_ADDRESS 0xE6CBu    /* 07E6CB */
#define loaded_table_07E6D5_ADDRESS 0xE6D5u    /* 07E6D5 */
#define loaded_table_07E6D9_ADDRESS 0xE6D9u    /* 07E6D9 */
#define loaded_table_07E6FB_ADDRESS 0xE6FBu    /* 07E6FB */
#define loaded_table_07E701_ADDRESS 0xE701u    /* 07E701 */
#define loaded_table_07E707_ADDRESS 0xE707u    /* 07E707 */
#define loaded_table_07E717_ADDRESS 0xE717u    /* 07E717 */
#define loaded_table_07E721_ADDRESS 0xE721u    /* 07E721 */
#define loaded_table_07E731_ADDRESS 0xE731u    /* 07E731 */
#define loaded_table_07E743_ADDRESS 0xE743u    /* 07E743 */
#define loaded_table_07E751_ADDRESS 0xE751u    /* 07E751 */
#define loaded_table_07E761_ADDRESS 0xE761u    /* 07E761 */
#define loaded_table_07E773_ADDRESS 0xE773u    /* 07E773 */
#define loaded_table_07E785_ADDRESS 0xE785u    /* 07E785 */
#define loaded_table_07E791_ADDRESS 0xE791u    /* 07E791 */
#define loaded_table_07E7A3_ADDRESS 0xE7A3u    /* 07E7A3 */
#define loaded_table_07E7C1_ADDRESS 0xE7C1u    /* 07E7C1 */
#define loaded_table_07E7C7_ADDRESS 0xE7C7u    /* 07E7C7 */
#define loaded_table_07E7CD_ADDRESS 0xE7CDu    /* 07E7CD */
#define loaded_table_07E7D3_ADDRESS 0xE7D3u    /* 07E7D3 */
#define loaded_table_07E803_ADDRESS 0xE803u    /* 07E803 */
#define loaded_table_07E80F_ADDRESS 0xE80Fu    /* 07E80F */
#define indexed_table_07E89D_ADDRESS 0xE89Du    /* 07E89D */
#define indexed_table_07E8B5_ADDRESS 0xE8B5u    /* 07E8B5 */
#define loaded_table_07E971_ADDRESS 0xE971u    /* 07E971 */
#define loaded_table_07E975_ADDRESS 0xE975u    /* 07E975 */
#define loaded_table_07E97B_ADDRESS 0xE97Bu    /* 07E97B */
#define loaded_table_07E97F_ADDRESS 0xE97Fu    /* 07E97F */
#define loaded_table_07E9BB_ADDRESS 0xE9BBu    /* 07E9BB */
#define palette_sets_07E9E7_ADDRESS 0xE9E7u    /* 07E9E7 */
#define palette_sets_07E9FB_ADDRESS 0xE9FBu    /* 07E9FB */
#define palette_sets_07EA0F_ADDRESS 0xEA0Fu    /* 07EA0F */
#define palette_sets_07EA23_ADDRESS 0xEA23u    /* 07EA23 */
#define palette_sets_07EA37_ADDRESS 0xEA37u    /* 07EA37 */
#define palette_sets_07EA4B_ADDRESS 0xEA4Bu    /* 07EA4B */
#define palette_sets_07EA5F_ADDRESS 0xEA5Fu    /* 07EA5F */
#define palette_sets_07EA73_ADDRESS 0xEA73u    /* 07EA73 */
#define palette_sets_07EA87_ADDRESS 0xEA87u    /* 07EA87 */
#define palette_sets_07EA9B_ADDRESS 0xEA9Bu    /* 07EA9B */
#define palette_sets_07EAAF_ADDRESS 0xEAAFu    /* 07EAAF */
#define palette_sets_07EAC3_ADDRESS 0xEAC3u    /* 07EAC3 */
#define palette_sets_07EAD7_ADDRESS 0xEAD7u    /* 07EAD7 */
#define palette_sets_07EB11_ADDRESS 0xEB11u    /* 07EB11 */
#define palette_sets_07EB25_ADDRESS 0xEB25u    /* 07EB25 */
#define palette_sets_07EB39_ADDRESS 0xEB39u    /* 07EB39 */
#define palette_sets_07EB4D_ADDRESS 0xEB4Du    /* 07EB4D */
#define palette_sets_07EB61_ADDRESS 0xEB61u    /* 07EB61 */
#define palette_sets_07EB75_ADDRESS 0xEB75u    /* 07EB75 */
#define palette_sets_07EB89_ADDRESS 0xEB89u    /* 07EB89 */
#define palette_sets_07EB9D_ADDRESS 0xEB9Du    /* 07EB9D */
#define palette_sets_07EBB1_ADDRESS 0xEBB1u    /* 07EBB1 */
#define palette_sets_07EBC5_ADDRESS 0xEBC5u    /* 07EBC5 */
#define palette_sets_07EBD9_ADDRESS 0xEBD9u    /* 07EBD9 */
#define palette_sets_07EBED_ADDRESS 0xEBEDu    /* 07EBED */
#define palette_sets_07EC01_ADDRESS 0xEC01u    /* 07EC01 */
#define palette_sets_07EC15_ADDRESS 0xEC15u    /* 07EC15 */
#define palette_sets_07EC29_ADDRESS 0xEC29u    /* 07EC29 */
#define palette_sets_07EC3D_ADDRESS 0xEC3Du    /* 07EC3D */
#define palette_sets_07EC51_ADDRESS 0xEC51u    /* 07EC51 */
#define palette_sets_07EC65_ADDRESS 0xEC65u    /* 07EC65 */
#define palette_sets_07EC79_ADDRESS 0xEC79u    /* 07EC79 */
#define loaded_table_07EC8D_ADDRESS 0xEC8Du    /* 07EC8D */
#define loaded_table_07EC95_ADDRESS 0xEC95u    /* 07EC95 */
#define loaded_table_07ECC5_ADDRESS 0xECC5u    /* 07ECC5 */
#define scene_list_07ECD1_ADDRESS 0xECD1u    /* 07ECD1 */
#define scene_list_07ECE1_ADDRESS 0xECE1u    /* 07ECE1 */
#define scene_list_07ECE5_ADDRESS 0xECE5u    /* 07ECE5 */
#define scene_list_07ECF1_ADDRESS 0xECF1u    /* 07ECF1 */
#define scene_list_07ECF5_ADDRESS 0xECF5u    /* 07ECF5 */
#define scene_list_07ED01_ADDRESS 0xED01u    /* 07ED01 */
#define scene_list_07ED11_ADDRESS 0xED11u    /* 07ED11 */
#define scene_list_07ED15_ADDRESS 0xED15u    /* 07ED15 */
#define scene_list_07ED21_ADDRESS 0xED21u    /* 07ED21 */
#define scene_list_07ED25_ADDRESS 0xED25u    /* 07ED25 */
#define scene_list_07ED47_ADDRESS 0xED47u    /* 07ED47 */
#define scene_list_07ED4B_ADDRESS 0xED4Bu    /* 07ED4B */
#define scene_list_07ED53_ADDRESS 0xED53u    /* 07ED53 */
#define scene_list_07ED57_ADDRESS 0xED57u    /* 07ED57 */
#define scene_list_07ED5F_ADDRESS 0xED5Fu    /* 07ED5F */
#define scene_list_07ED6F_ADDRESS 0xED6Fu    /* 07ED6F */
#define scene_list_07ED77_ADDRESS 0xED77u    /* 07ED77 */
#define scene_list_07ED7B_ADDRESS 0xED7Bu    /* 07ED7B */
#define scene_list_07ED7F_ADDRESS 0xED7Fu    /* 07ED7F */
#define scene_list_07ED93_ADDRESS 0xED93u    /* 07ED93 */
#define scene_list_07ED97_ADDRESS 0xED97u    /* 07ED97 */
#define scene_list_07EDA3_ADDRESS 0xEDA3u    /* 07EDA3 */
#define scene_list_07EDA7_ADDRESS 0xEDA7u    /* 07EDA7 */
#define scene_list_07EDB7_ADDRESS 0xEDB7u    /* 07EDB7 */
#define scene_list_07EDD9_ADDRESS 0xEDD9u    /* 07EDD9 */
#define scene_list_07EDDD_ADDRESS 0xEDDDu    /* 07EDDD */
#define scene_list_07EDE1_ADDRESS 0xEDE1u    /* 07EDE1 */
#define scene_list_07EDE5_ADDRESS 0xEDE5u    /* 07EDE5 */
#define scene_list_07EDE9_ADDRESS 0xEDE9u    /* 07EDE9 */
#define scene_list_07EDF9_ADDRESS 0xEDF9u    /* 07EDF9 */
#define scene_list_07EDFD_ADDRESS 0xEDFDu    /* 07EDFD */
#define scene_list_07EE01_ADDRESS 0xEE01u    /* 07EE01 */
#define scene_list_07EE05_ADDRESS 0xEE05u    /* 07EE05 */
#define scene_list_07EE15_ADDRESS 0xEE15u    /* 07EE15 */
#define scene_list_07EE19_ADDRESS 0xEE19u    /* 07EE19 */
#define scene_list_07EE25_ADDRESS 0xEE25u    /* 07EE25 */
#define scene_list_07EE2D_ADDRESS 0xEE2Du    /* 07EE2D */
#define scene_list_07EE3D_ADDRESS 0xEE3Du    /* 07EE3D */
#define scene_list_07EE5F_ADDRESS 0xEE5Fu    /* 07EE5F */
#define scene_list_07EE63_ADDRESS 0xEE63u    /* 07EE63 */
#define scene_list_07EE6B_ADDRESS 0xEE6Bu    /* 07EE6B */
#define scene_list_07EE6F_ADDRESS 0xEE6Fu    /* 07EE6F */
#define scene_list_07EE77_ADDRESS 0xEE77u    /* 07EE77 */
#define scene_list_07EE87_ADDRESS 0xEE87u    /* 07EE87 */
#define scene_list_07EE8F_ADDRESS 0xEE8Fu    /* 07EE8F */
#define scene_list_07EE93_ADDRESS 0xEE93u    /* 07EE93 */
#define scene_list_07EE97_ADDRESS 0xEE97u    /* 07EE97 */
#define scene_list_07EEAB_ADDRESS 0xEEABu    /* 07EEAB */
#define scene_list_07EEAF_ADDRESS 0xEEAFu    /* 07EEAF */
#define scene_list_07EEBB_ADDRESS 0xEEBBu    /* 07EEBB */
#define scene_list_07EEBF_ADDRESS 0xEEBFu    /* 07EEBF */
#define scene_list_07EECF_ADDRESS 0xEECFu    /* 07EECF */
#define scene_list_07EEF1_ADDRESS 0xEEF1u    /* 07EEF1 */
#define scene_list_07EEF5_ADDRESS 0xEEF5u    /* 07EEF5 */
#define scene_list_07EEF9_ADDRESS 0xEEF9u    /* 07EEF9 */
#define scene_list_07EEFD_ADDRESS 0xEEFDu    /* 07EEFD */
#define scene_list_07EF01_ADDRESS 0xEF01u    /* 07EF01 */
#define scene_list_07EF0D_ADDRESS 0xEF0Du    /* 07EF0D */
#define scene_list_07EF11_ADDRESS 0xEF11u    /* 07EF11 */
#define scene_list_07EF15_ADDRESS 0xEF15u    /* 07EF15 */
#define scene_list_07EF19_ADDRESS 0xEF19u    /* 07EF19 */
#define scene_list_07EF29_ADDRESS 0xEF29u    /* 07EF29 */
#define scene_list_07EF2D_ADDRESS 0xEF2Du    /* 07EF2D */
#define scene_list_07EF39_ADDRESS 0xEF39u    /* 07EF39 */
#define scene_list_07EF41_ADDRESS 0xEF41u    /* 07EF41 */
#define scene_list_07EF51_ADDRESS 0xEF51u    /* 07EF51 */
#define layer_mode_list_07EF5D_ADDRESS 0xEF5Du    /* 07EF5D */
#define layer_mode_list_07EF5F_ADDRESS 0xEF5Fu    /* 07EF5F */
#define layer_mode_list_07EF61_ADDRESS 0xEF61u    /* 07EF61 */
#define layer_mode_list_07EF81_ADDRESS 0xEF81u    /* 07EF81 */
#define layer_mode_list_07EF83_ADDRESS 0xEF83u    /* 07EF83 */
#define layer_mode_list_07EF85_ADDRESS 0xEF85u    /* 07EF85 */
#define layer_mode_list_07EF87_ADDRESS 0xEF87u    /* 07EF87 */
#define layer_mode_list_07EF8B_ADDRESS 0xEF8Bu    /* 07EF8B */
#define layer_mode_list_07EF8D_ADDRESS 0xEF8Du    /* 07EF8D */
#define layer_mode_list_07EF8F_ADDRESS 0xEF8Fu    /* 07EF8F */
#define layer_mode_list_07EF93_ADDRESS 0xEF93u    /* 07EF93 */
#define layer_mode_list_07EF95_ADDRESS 0xEF95u    /* 07EF95 */
#define layer_mode_list_07EF97_ADDRESS 0xEF97u    /* 07EF97 */
#define layer_mode_list_07EF9D_ADDRESS 0xEF9Du    /* 07EF9D */
#define layer_mode_list_07EF9F_ADDRESS 0xEF9Fu    /* 07EF9F */
#define layer_mode_list_07EFA7_ADDRESS 0xEFA7u    /* 07EFA7 */
#define layer_mode_list_07EFAB_ADDRESS 0xEFABu    /* 07EFAB */
#define layer_mode_list_07EFB3_ADDRESS 0xEFB3u    /* 07EFB3 */
#define tile_picture_place_07EFB7_ADDRESS 0xEFB7u    /* 07EFB7 */
#define loaded_table_07F019_ADDRESS 0xF019u    /* 07F019 */
#define indexed_table_07F061_ADDRESS 0xF061u    /* 07F061 */
#define indexed_table_07F0A2_ADDRESS 0xF0A2u    /* 07F0A2 */
#define loaded_table_07F134_ADDRESS 0xF134u    /* 07F134 */
#define hit_box_07F13C_ADDRESS 0xF13Cu    /* 07F13C */
#define enemy_behaviour_07F144_ADDRESS 0xF144u    /* 07F144 */
#define loaded_table_07F19C_ADDRESS 0xF19Cu    /* 07F19C */
#define object_setup_07F1A8_ADDRESS 0xF1A8u    /* 07F1A8 */
#define loaded_table_07F1AE_ADDRESS 0xF1AEu    /* 07F1AE */
#define loaded_table_07F1BE_ADDRESS 0xF1BEu    /* 07F1BE */
#define loaded_table_07F1C4_ADDRESS 0xF1C4u    /* 07F1C4 */
#define loaded_table_07F1CA_ADDRESS 0xF1CAu    /* 07F1CA */
#define loaded_table_07F1D0_ADDRESS 0xF1D0u    /* 07F1D0 */
#define loaded_table_07F1D6_ADDRESS 0xF1D6u    /* 07F1D6 */
#define loaded_table_07F1DC_ADDRESS 0xF1DCu    /* 07F1DC */
#define loaded_table_07F1E2_ADDRESS 0xF1E2u    /* 07F1E2 */
#define loaded_table_07F1E8_ADDRESS 0xF1E8u    /* 07F1E8 */
#define loaded_table_07F1EE_ADDRESS 0xF1EEu    /* 07F1EE */
#define loaded_table_07F1F4_ADDRESS 0xF1F4u    /* 07F1F4 */
#define loaded_table_07F1F8_ADDRESS 0xF1F8u    /* 07F1F8 */
#define loaded_table_07F1FE_ADDRESS 0xF1FEu    /* 07F1FE */
#define loaded_table_07F202_ADDRESS 0xF202u    /* 07F202 */
#define loaded_table_07F208_ADDRESS 0xF208u    /* 07F208 */
#define loaded_table_07F210_ADDRESS 0xF210u    /* 07F210 */
#define loaded_table_07F214_ADDRESS 0xF214u    /* 07F214 */
#define loaded_table_07F21A_ADDRESS 0xF21Au    /* 07F21A */
#define loaded_table_07F21E_ADDRESS 0xF21Eu    /* 07F21E */
#define loaded_table_07F222_ADDRESS 0xF222u    /* 07F222 */
#define loaded_table_07F228_ADDRESS 0xF228u    /* 07F228 */
#define loaded_table_07F22E_ADDRESS 0xF22Eu    /* 07F22E */
#define loaded_table_07F248_ADDRESS 0xF248u    /* 07F248 */
#define loaded_table_07F24C_ADDRESS 0xF24Cu    /* 07F24C */
#define loaded_table_07F250_ADDRESS 0xF250u    /* 07F250 */
#define loaded_table_07F254_ADDRESS 0xF254u    /* 07F254 */
#define loaded_table_07F258_ADDRESS 0xF258u    /* 07F258 */
#define loaded_table_07F25E_ADDRESS 0xF25Eu    /* 07F25E */
#define loaded_table_07F262_ADDRESS 0xF262u    /* 07F262 */
#define loaded_table_07F266_ADDRESS 0xF266u    /* 07F266 */
#define loaded_table_07F268_ADDRESS 0xF268u    /* 07F268 */
#define loaded_table_07F26E_ADDRESS 0xF26Eu    /* 07F26E */
#define loaded_table_07F274_ADDRESS 0xF274u    /* 07F274 */
#define loaded_table_07F27A_ADDRESS 0xF27Au    /* 07F27A */
#define loaded_table_07F280_ADDRESS 0xF280u    /* 07F280 */
#define hit_box_07F284_ADDRESS 0xF284u    /* 07F284 */
#define loaded_table_07F28C_ADDRESS 0xF28Cu    /* 07F28C */
#define object_setup_07F290_ADDRESS 0xF290u    /* 07F290 */
#define loaded_table_07F296_ADDRESS 0xF296u    /* 07F296 */
#define loaded_table_07F29E_ADDRESS 0xF29Eu    /* 07F29E */
#define indexed_table_07F2AC_ADDRESS 0xF2ACu    /* 07F2AC */
#define loaded_table_07F2EC_ADDRESS 0xF2ECu    /* 07F2EC */
#define loaded_table_07F40D_ADDRESS 0xF40Du    /* 07F40D */
#define loaded_table_07F4F4_ADDRESS 0xF4F4u    /* 07F4F4 */
#define loaded_table_07F577_ADDRESS 0xF577u    /* 07F577 */
#define loaded_table_07F586_ADDRESS 0xF586u    /* 07F586 */
#define loaded_table_07F5A2_ADDRESS 0xF5A2u    /* 07F5A2 */
#define unused_object_handlers_ADDRESS 0xF65Fu    /* 07F65F */
#define loaded_table_07F662_ADDRESS 0xF662u    /* 07F662 */

/* numbers the code uses, by name (symbols.txt constant lines) */


/* the game's structures */
#pragma pack(push, 1)
struct animation_set
{
	uint8_t index;
	uint8_t bank;
};

struct shadow_sprite
{
	uint8_t pad_00[0x1];
	uint16_t code;
	uint8_t attributes;
};

struct layer_map
{
	uint16_t maps_high;
	uint16_t offset_y2;
	uint16_t offset_y;
	uint16_t offset_x;
	uint16_t unk_08;
	uint16_t maps;
	uint16_t scroll_y;
	uint16_t scroll_x;
	uint16_t tiles;
};

struct palette_load
{
	uint8_t palettes;
	uint16_t destination;
	uint16_t source;
};

struct spawn
{
	uint8_t kind;
	uint8_t level;
	uint8_t unk_05;
	uint8_t flags;
	uint8_t depth;
	int8_t y;
	uint16_t x;
};

struct tile_picture_place
{
	uint16_t picture;
	uint16_t tiles;
	uint8_t bank;
};

struct test_menu_line
{
	uint8_t action;
	uint16_t cursor;
};

struct path_step
{
	uint8_t speed;
	int8_t direction;
};

struct path_start
{
	uint8_t count_3a;
	uint8_t count_3b;
	uint16_t path;
};

struct demo
{
	uint8_t pad_00[0x6];
	uint16_t inputs;
	uint8_t step;
	uint16_t frames;
	uint8_t players;
};

struct demo_input
{
	uint8_t frames;
	uint8_t controls;
};

struct test_palette
{
	uint8_t pad_00[0x1E];
	uint16_t colours;
	uint16_t destination;
};

struct vector
{
	int16_t offset;
	uint8_t opcode;
};

struct enemy_behaviour
{
	uint8_t pad_00[0x2F];
	uint8_t ranges;
	uint8_t pad_30[0x27];
	uint8_t states;
};

struct behaviour_choice
{
	uint16_t behaviour;
	uint8_t flags;
	uint8_t state;
};

struct player
{
	uint8_t pad_00[0xA];
	uint16_t variables_0f;
	uint8_t number;
	uint8_t pad_0D[0x2];
	uint8_t initials;
	uint16_t variables_09;
	uint16_t variables_07;
	uint8_t bit;
	uint16_t lives;
	uint16_t variables_02;
	uint16_t variables_00;
};

struct gauge_player
{
	uint8_t unk_17;
	uint8_t pad_01[0x14];
	uint16_t variables;
	uint8_t unk_00;
};

struct test_player
{
	uint8_t button;
	uint8_t pad_01[0x4];
	uint8_t unk_0c;
	uint16_t shadow_x;
	uint16_t shadow_kind;
	uint16_t z;
	uint16_t x;
	uint8_t animation;
	uint8_t kind;
	uint16_t lives;
};

struct placement
{
	uint16_t z;
	uint16_t x;
	uint16_t kind;
	uint16_t object;
};

struct player_kind
{
	uint8_t unk_03;
	uint16_t kind;
	uint8_t bit;
};

struct stage_slot
{
	uint8_t unk_02;
	uint16_t record;
};

struct hit_box
{
	uint16_t field_23;
	uint16_t field_21;
	uint16_t field_1f;
	uint16_t field_1c;
};

struct part
{
	uint16_t unk_06;
	uint16_t animation;
	uint8_t kind;
	int8_t dz;
	int8_t dy;
	uint8_t speed;
};

struct pattern_start
{
	uint8_t animation;
	uint8_t kind;
	uint16_t pattern;
};

struct part_offset
{
	int8_t dz;
	int8_t dy;
	int8_t dx;
};

#pragma pack(pop)

_Static_assert(sizeof(struct animation_set) == 0x2, "struct animation_set has the size of the program ROM's records");
_Static_assert(sizeof(struct shadow_sprite) == 0x4, "struct shadow_sprite has the size of the program ROM's records");
_Static_assert(sizeof(struct layer_map) == 0x12, "struct layer_map has the size of the program ROM's records");
_Static_assert(sizeof(struct palette_load) == 0x5, "struct palette_load has the size of the program ROM's records");
_Static_assert(sizeof(struct spawn) == 0x8, "struct spawn has the size of the program ROM's records");
_Static_assert(sizeof(struct tile_picture_place) == 0x5, "struct tile_picture_place has the size of the program ROM's records");
_Static_assert(sizeof(struct test_menu_line) == 0x3, "struct test_menu_line has the size of the program ROM's records");
_Static_assert(sizeof(struct path_step) == 0x2, "struct path_step has the size of the program ROM's records");
_Static_assert(sizeof(struct path_start) == 0x4, "struct path_start has the size of the program ROM's records");
_Static_assert(sizeof(struct demo) == 0xC, "struct demo has the size of the program ROM's records");
_Static_assert(sizeof(struct demo_input) == 0x2, "struct demo_input has the size of the program ROM's records");
_Static_assert(sizeof(struct test_palette) == 0x22, "struct test_palette has the size of the program ROM's records");
_Static_assert(sizeof(struct vector) == 0x3, "struct vector has the size of the program ROM's records");
_Static_assert(sizeof(struct enemy_behaviour) == 0x58, "struct enemy_behaviour has the size of the program ROM's records");
_Static_assert(sizeof(struct behaviour_choice) == 0x4, "struct behaviour_choice has the size of the program ROM's records");
_Static_assert(sizeof(struct player) == 0x1B, "struct player has the size of the program ROM's records");
_Static_assert(sizeof(struct gauge_player) == 0x18, "struct gauge_player has the size of the program ROM's records");
_Static_assert(sizeof(struct test_player) == 0x12, "struct test_player has the size of the program ROM's records");
_Static_assert(sizeof(struct placement) == 0x8, "struct placement has the size of the program ROM's records");
_Static_assert(sizeof(struct player_kind) == 0x4, "struct player_kind has the size of the program ROM's records");
_Static_assert(sizeof(struct stage_slot) == 0x3, "struct stage_slot has the size of the program ROM's records");
_Static_assert(sizeof(struct hit_box) == 0x8, "struct hit_box has the size of the program ROM's records");
_Static_assert(sizeof(struct part) == 0x8, "struct part has the size of the program ROM's records");
_Static_assert(sizeof(struct pattern_start) == 0x4, "struct pattern_start has the size of the program ROM's records");
_Static_assert(sizeof(struct part_offset) == 0x3, "struct part_offset has the size of the program ROM's records");

#define ANIMATION_SET(address) ((const struct animation_set *)data_record((address), sizeof(struct animation_set)))
#define SHADOW_SPRITE(address) ((const struct shadow_sprite *)data_record((address), sizeof(struct shadow_sprite)))
#define LAYER_MAP(address) ((const struct layer_map *)data_record((address), sizeof(struct layer_map)))
#define PALETTE_LOAD(address) ((const struct palette_load *)data_record((address), sizeof(struct palette_load)))
#define SPAWN(address) ((const struct spawn *)data_record((address), sizeof(struct spawn)))
#define TILE_PICTURE_PLACE(address) ((const struct tile_picture_place *)data_record((address), sizeof(struct tile_picture_place)))
#define TEST_MENU_LINE(address) ((const struct test_menu_line *)data_record((address), sizeof(struct test_menu_line)))
#define PATH_STEP(address) ((const struct path_step *)data_record((address), sizeof(struct path_step)))
#define PATH_START(address) ((const struct path_start *)data_record((address), sizeof(struct path_start)))
#define DEMO(address) ((const struct demo *)data_record((address), sizeof(struct demo)))
#define DEMO_INPUT(address) ((const struct demo_input *)data_record((address), sizeof(struct demo_input)))
#define TEST_PALETTE(address) ((const struct test_palette *)data_record((address), sizeof(struct test_palette)))
#define VECTOR(address) ((const struct vector *)data_record((address), sizeof(struct vector)))
#define ENEMY_BEHAVIOUR(address) ((const struct enemy_behaviour *)data_record((address), sizeof(struct enemy_behaviour)))
#define BEHAVIOUR_CHOICE(address) ((const struct behaviour_choice *)data_record((address), sizeof(struct behaviour_choice)))
#define PLAYER(address) ((const struct player *)data_record((address), sizeof(struct player)))
#define GAUGE_PLAYER(address) ((const struct gauge_player *)data_record((address), sizeof(struct gauge_player)))
#define TEST_PLAYER(address) ((const struct test_player *)data_record((address), sizeof(struct test_player)))
#define PLACEMENT(address) ((const struct placement *)data_record((address), sizeof(struct placement)))
#define PLAYER_KIND(address) ((const struct player_kind *)data_record((address), sizeof(struct player_kind)))
#define STAGE_SLOT(address) ((const struct stage_slot *)data_record((address), sizeof(struct stage_slot)))
#define HIT_BOX(address) ((const struct hit_box *)data_record((address), sizeof(struct hit_box)))
#define PART(address) ((const struct part *)data_record((address), sizeof(struct part)))
#define PATTERN_START(address) ((const struct pattern_start *)data_record((address), sizeof(struct pattern_start)))
#define PART_OFFSET(address) ((const struct part_offset *)data_record((address), sizeof(struct part_offset)))

/* the program ROM's tables of records, by name: name[i].field */
#define object_12_placements_ADDRESS 0x77BAu    /* 0257BA */
extern const void *object_12_placements_data;
#define object_12_placements ((const struct placement *)(object_12_placements_data))
#define unused_player_kinds_025952_ADDRESS 0x7952u    /* 025952 */
extern const void *unused_player_kinds_025952_data;
#define unused_player_kinds_025952 ((const struct player_kind *)(unused_player_kinds_025952_data))
#define stage_slots_ADDRESS 0x600Cu    /* 02600C */
extern const void *stage_slots_data;
#define stage_slots ((const struct stage_slot *)(stage_slots_data))
#define empty_vectors_02807E_ADDRESS 0x607Eu    /* 02807E */
extern const void *empty_vectors_02807E_data;
#define empty_vectors_02807E ((const struct vector *)(empty_vectors_02807E_data))
#define empty_vector_0280B1_ADDRESS 0x60B1u    /* 0280B1 */
extern const void *empty_vector_0280B1_data;
#define empty_vector_0280B1 ((const struct vector *)(empty_vector_0280B1_data))
#define empty_vector_0280BD_ADDRESS 0x60BDu    /* 0280BD */
extern const void *empty_vector_0280BD_data;
#define empty_vector_0280BD ((const struct vector *)(empty_vector_0280BD_data))
#define empty_vectors_02C030_ADDRESS 0x6030u    /* 02C030 */
extern const void *empty_vectors_02C030_data;
#define empty_vectors_02C030 ((const struct vector *)(empty_vectors_02C030_data))
#define empty_vector_02C057_ADDRESS 0x6057u    /* 02C057 */
extern const void *empty_vector_02C057_data;
#define empty_vector_02C057 ((const struct vector *)(empty_vector_02C057_data))
#define object_16_kinds_ADDRESS 0x7E3Fu    /* 02DE3F */
extern const void *object_16_kinds_data;
#define object_16_kinds ((const struct pattern_start *)(object_16_kinds_data))
#define object_18_behaviours_ADDRESS 0x79DAu    /* 0319DA */
extern const void *object_18_behaviours_data;
#define object_18_behaviours ((const struct behaviour_choice *)(object_18_behaviours_data))
#define unused_hit_box_031ED8_ADDRESS 0x7ED8u    /* 031ED8 */
extern const void *unused_hit_box_031ED8_data;
#define unused_hit_box_031ED8 ((const struct hit_box *)(unused_hit_box_031ED8_data))
#define empty_vector_032024_ADDRESS 0x6024u    /* 032024 */
extern const void *empty_vector_032024_data;
#define empty_vector_032024 ((const struct vector *)(empty_vector_032024_data))
#define empty_vectors_034000_ADDRESS 0x6000u    /* 034000 */
extern const void *empty_vectors_034000_data;
#define empty_vectors_034000 ((const struct vector *)(empty_vectors_034000_data))
#define unused_spawn_list_0354C5_ADDRESS 0x74C5u    /* 0354C5 */
extern const void *unused_spawn_list_0354C5_data;
#define unused_spawn_list_0354C5 ((const struct spawn *)(unused_spawn_list_0354C5_data))
#define unused_spawn_0356DD_ADDRESS 0x76DDu    /* 0356DD */
extern const void *unused_spawn_0356DD_data;
#define unused_spawn_0356DD ((const struct spawn *)(unused_spawn_0356DD_data))
#define object_1a_path_starts_ADDRESS 0x79E4u    /* 0359E4 */
extern const void *object_1a_path_starts_data;
#define object_1a_path_starts ((const struct path_start *)(object_1a_path_starts_data))
#define object_1d_parts_ADDRESS 0x7D21u    /* 03BD21 */
extern const void *object_1d_parts_data;
#define object_1d_parts ((const struct part *)(object_1d_parts_data))
#define object_1e_part_offsets_ADDRESS 0x7E2Cu    /* 03DE2C */
extern const void *object_1e_part_offsets_data;
#define object_1e_part_offsets ((const struct part_offset *)(object_1e_part_offsets_data))
#define gauge_players_ADDRESS 0x729Cu    /* 04129C */
extern const void *gauge_players_data;
#define gauge_players ((const struct gauge_player *)(gauge_players_data))
#define test_mode_palettes_ADDRESS 0x7B6Cu    /* 05FB6C */
extern const void *test_mode_palettes_data;
#define test_mode_palettes ((const struct test_palette *)(test_mode_palettes_data))
#define test_players_ADDRESS 0x7D90u    /* 05FD90 */
extern const void *test_players_data;
#define test_players ((const struct test_player *)(test_players_data))
#define unused_vector_0785D8_ADDRESS 0x85D8u    /* 0785D8 */
extern const void *unused_vector_0785D8_data;
#define unused_vector_0785D8 ((const struct vector *)(unused_vector_0785D8_data))
#define empty_vector_0785F6_ADDRESS 0x85F6u    /* 0785F6 */
extern const void *empty_vector_0785F6_data;
#define empty_vector_0785F6 ((const struct vector *)(empty_vector_0785F6_data))
#define empty_vector_07865F_ADDRESS 0x865Fu    /* 07865F */
extern const void *empty_vector_07865F_data;
#define empty_vector_07865F ((const struct vector *)(empty_vector_07865F_data))
#define empty_vector_078665_ADDRESS 0x8665u    /* 078665 */
extern const void *empty_vector_078665_data;
#define empty_vector_078665 ((const struct vector *)(empty_vector_078665_data))
#define shadow_sprites_ADDRESS 0xE585u    /* 07E585 */
extern const void *shadow_sprites_data;
#define shadow_sprites ((const struct shadow_sprite *)(shadow_sprites_data))
#define animation_sets_ADDRESS 0xE591u    /* 07E591 */
extern const void *animation_sets_data;
#define animation_sets ((const struct animation_set *)(animation_sets_data))
#define animation_sets_high_ADDRESS 0xE5BBu    /* 07E5BB */
extern const void *animation_sets_high_data;
#define animation_sets_high ((const struct animation_set *)(animation_sets_high_data))
#define players_ADDRESS 0xE821u    /* 07E821 */
extern const void *players_data;
#define players ((const struct player *)(players_data))
#define layers_ADDRESS 0xECA1u    /* 07ECA1 */
extern const void *layers_data;
#define layers ((const struct layer_map *)(layers_data))

#endif
