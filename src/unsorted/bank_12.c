/**
 *    Name:        unsorted/bank_12.c
 *    Description: bank 12's code
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

void sub_024000(uint16_t u)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, x = 0;
	uint8_t t1 = 0;

	x = loaded_table_025700_ADDRESS;
	t1 = io_read8(VIDEO_18E0);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_02402E();
		return;
	case 2:
		sub_02403A(u);
		return;
	case 4:
		sub_0240E3(x);
		return;
	case 6:
		sub_024113();
		return;
	case 8:
		sub_024125(x);
		return;
	case 10:
	case 38:
		sub_024155(&ignored16, &ignored16_2, &u);
		return;
	case 12:
		sub_024188(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 14:
	case 42:
		sub_0241E2(&ignored16, &ignored16_2, &u);
		return;
	case 16:
		sub_024333(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 18:
		sub_024363(x, 0u);
		return;
	case 20:
	case 22:
		sub_02439E(&ignored16, &ignored16_2, &u);
		return;
	case 24:
		sub_024409(&ignored16, &ignored16_3);
		return;
	case 26:
		sub_0241EC(&x, &ignored16_2);
		return;
	case 28:
		sub_02424B(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 30:
		sub_02427E(x, u);
		return;
	case 32:
		sub_0242D0(x);
		return;
	case 34:
		sub_0242AC(x);
		return;
	case 36:
		sub_024329(x);
		return;
	case 40:
		sub_02441C(&ignored16, &ignored16_2, &u);
		return;
	case 44:
		sub_02448F(&ignored16, &ignored16_2, &u);
		return;
	case 46:
		sub_024532(&ignored16_2, &u);
		return;
	case 48:
		sub_024557(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 50:
		sub_024571();
		return;
	case 52:
		sub_02457C(&ignored16_2, &u);
		return;
	case 54:
		sub_0245A3(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 56:
		sub_0245D1(&ignored16, &ignored16_2, &u);
		return;
	case 58:
		sub_0245E1(&ignored16, &ignored16_2, &u);
		return;
	case 60:
		sub_0245E8();
		return;
	case 62:
		sub_0245F4(&ignored16, &ignored16_3);
		return;
	case 64:
		sub_024616(&ignored16, &ignored16_2, &u);
		return;
	case 66:
		sub_024648(&x, &ignored16_2, &ignored16_3);
		return;
	case 68:
		sub_0246C3();
		return;
	case 70:
		sub_0246DF();
		return;
	case 72:
		sub_024723();
		return;
	case 74:
		sub_024741(&ignored16, &ignored16_2);
		return;
	case 76:
		sub_024779();
		return;
	case 78:
		sub_024799();
		return;
	case 80:
		sub_0247AA(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 82:
		sub_02482F();
		return;
	case 84:
		sub_024839(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 86:
		sub_02488C(&ignored16, &ignored16_3);
		return;
	case 88:
		sub_0248F4();
		return;
	case 90:
		sub_024939(&ignored16, &ignored16_2, &u);
		return;
	case 92:
		sub_02496D(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 94:
		sub_0249B6(x);
		return;
	case 96:
		sub_024A0B(&ignored16, &ignored16_2);
		return;
	case 98:
		sub_024AB0(&ignored16, &ignored16_3);
		return;
	case 100:
		sub_024AD3(&ignored16, &ignored16_3);
		return;
	case 102:
		sub_024B3F(&ignored16, &ignored16_2, &u);
		return;
	case 104:
		sub_024B7E(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 106:
		sub_024C30(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 108:
		sub_024CA6(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 110:
		sub_024CC2();
		return;
	case 112:
		sub_024CED(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 114:
		sub_024D08(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 116:
		sub_024D43(x);
		return;
	case 118:
		sub_024D61(x);
		return;
	case 120:
		sub_024D83(x);
		return;
	case 122:
		sub_024D98(x);
		return;
	case 124:
		sub_024DA6(x);
		return;
	case 126:
		sub_024DBF(x);
		return;
	}
}

void sub_024003(uint16_t u)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, x = 0;
	uint8_t t1 = 0;

	unk_486A = 0u;
	x = loaded_table_02570A_ADDRESS;
	t1 = io_read8(VIDEO_18E0);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
	case 28:
		sub_024155(&ignored16, &ignored16_2, &u);
		return;
	case 2:
		sub_024188(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 4:
	case 32:
		sub_0241E2(&ignored16, &ignored16_2, &u);
		return;
	case 6:
		sub_024333(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 8:
		sub_024363(x, 0u);
		return;
	case 10:
	case 12:
		sub_02439E(&ignored16, &ignored16_2, &u);
		return;
	case 14:
		sub_024409(&ignored16, &ignored16_3);
		return;
	case 16:
		sub_0241EC(&x, &ignored16_2);
		return;
	case 18:
		sub_02424B(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 20:
		sub_02427E(x, u);
		return;
	case 22:
		sub_0242D0(x);
		return;
	case 24:
		sub_0242AC(x);
		return;
	case 26:
		sub_024329(x);
		return;
	case 30:
		sub_02441C(&ignored16, &ignored16_2, &u);
		return;
	case 34:
		sub_02448F(&ignored16, &ignored16_2, &u);
		return;
	case 36:
		sub_024532(&ignored16_2, &u);
		return;
	case 38:
		sub_024557(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 40:
		sub_024571();
		return;
	case 42:
		sub_02457C(&ignored16_2, &u);
		return;
	case 44:
		sub_0245A3(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 46:
		sub_0245D1(&ignored16, &ignored16_2, &u);
		return;
	case 48:
		sub_0245E1(&ignored16, &ignored16_2, &u);
		return;
	case 50:
		sub_0245E8();
		return;
	case 52:
		sub_0245F4(&ignored16, &ignored16_3);
		return;
	case 54:
		sub_024616(&ignored16, &ignored16_2, &u);
		return;
	case 56:
		sub_024648(&x, &ignored16_2, &ignored16_3);
		return;
	case 58:
		sub_0246C3();
		return;
	case 60:
		sub_0246DF();
		return;
	case 62:
		sub_024723();
		return;
	case 64:
		sub_024741(&ignored16, &ignored16_2);
		return;
	case 66:
		sub_024779();
		return;
	case 68:
		sub_024799();
		return;
	case 70:
		sub_0247AA(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 72:
		sub_02482F();
		return;
	case 74:
		sub_024839(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 76:
		sub_02488C(&ignored16, &ignored16_3);
		return;
	case 78:
		sub_0248F4();
		return;
	case 80:
		sub_024939(&ignored16, &ignored16_2, &u);
		return;
	case 82:
		sub_02496D(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 84:
		sub_0249B6(x);
		return;
	case 86:
		sub_024A0B(&ignored16, &ignored16_2);
		return;
	case 88:
		sub_024AB0(&ignored16, &ignored16_3);
		return;
	case 90:
		sub_024AD3(&ignored16, &ignored16_3);
		return;
	case 92:
		sub_024B3F(&ignored16, &ignored16_2, &u);
		return;
	case 94:
		sub_024B7E(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 96:
		sub_024C30(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 98:
		sub_024CA6(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 100:
		sub_024CC2();
		return;
	case 102:
		sub_024CED(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 104:
		sub_024D08(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 106:
		sub_024D43(x);
		return;
	case 108:
		sub_024D61(x);
		return;
	case 110:
		sub_024D83(x);
		return;
	case 112:
		sub_024D98(x);
		return;
	case 114:
		sub_024DA6(x);
		return;
	case 116:
		sub_024DBF(x);
		return;
	case 118:
		sub_024DD7(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 120:
		sub_024E10(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 122:
		sub_024E6B();
		return;
	case 124:
		sub_024E87(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 126:
		sub_024EBD(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case -10:
		sub_02402E();
		return;
	case -8:
		sub_02403A(u);
		return;
	case -6:
		sub_0240E3(x);
		return;
	case -4:
		sub_024113();
		return;
	case -2:
		sub_024125(x);
		return;
	}
}

void sub_024006(uint16_t u)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, x = 0;
	uint8_t t1 = 0;

	unk_486A = 0u;
	x = loaded_table_025726_ADDRESS;
	t1 = io_read8(VIDEO_18E0);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case -28:
	case 0:
		sub_024155(&ignored16, &ignored16_2, &u);
		return;
	case 2:
		sub_02441C(&ignored16, &ignored16_2, &u);
		return;
	case -24:
	case 4:
		sub_0241E2(&ignored16, &ignored16_2, &u);
		return;
	case 6:
		sub_02448F(&ignored16, &ignored16_2, &u);
		return;
	case 8:
		sub_024532(&ignored16_2, &u);
		return;
	case 10:
		sub_024557(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 12:
		sub_024571();
		return;
	case 14:
		sub_02457C(&ignored16_2, &u);
		return;
	case 16:
		sub_0245A3(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 18:
		sub_0245D1(&ignored16, &ignored16_2, &u);
		return;
	case 20:
		sub_0245E1(&ignored16, &ignored16_2, &u);
		return;
	case 22:
		sub_0245E8();
		return;
	case 24:
		sub_0245F4(&ignored16, &ignored16_3);
		return;
	case 26:
		sub_024616(&ignored16, &ignored16_2, &u);
		return;
	case 28:
		sub_024648(&x, &ignored16_2, &ignored16_3);
		return;
	case 30:
		sub_0246C3();
		return;
	case 32:
		sub_0246DF();
		return;
	case 34:
		sub_024723();
		return;
	case 36:
		sub_024741(&ignored16, &ignored16_2);
		return;
	case 38:
		sub_024779();
		return;
	case 40:
		sub_024799();
		return;
	case 42:
		sub_0247AA(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 44:
		sub_02482F();
		return;
	case 46:
		sub_024839(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 48:
		sub_02488C(&ignored16, &ignored16_3);
		return;
	case 50:
		sub_0248F4();
		return;
	case 52:
		sub_024939(&ignored16, &ignored16_2, &u);
		return;
	case 54:
		sub_02496D(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 56:
		sub_0249B6(x);
		return;
	case 58:
		sub_024A0B(&ignored16, &ignored16_2);
		return;
	case 60:
		sub_024AB0(&ignored16, &ignored16_3);
		return;
	case 62:
		sub_024AD3(&ignored16, &ignored16_3);
		return;
	case 64:
		sub_024B3F(&ignored16, &ignored16_2, &u);
		return;
	case 66:
		sub_024B7E(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 68:
		sub_024C30(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 70:
		sub_024CA6(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 72:
		sub_024CC2();
		return;
	case 74:
		sub_024CED(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 76:
		sub_024D08(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 78:
		sub_024D43(x);
		return;
	case 80:
		sub_024D61(x);
		return;
	case 82:
		sub_024D83(x);
		return;
	case 84:
		sub_024D98(x);
		return;
	case 86:
		sub_024DA6(x);
		return;
	case 88:
		sub_024DBF(x);
		return;
	case 90:
		sub_024DD7(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 92:
		sub_024E10(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 94:
		sub_024E6B();
		return;
	case 96:
		sub_024E87(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 98:
		sub_024EBD(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 100:
		sub_024F15(&ignored16, &ignored16_2, &u);
		return;
	case 102:
		sub_0251C9(&ignored16, &ignored16_2, &u);
		return;
	case 104:
		sub_025349(&ignored16, &ignored16_3);
		return;
	case 106:
		sub_0251F5();
		return;
	case 108:
		sub_0251F6(&x, &ignored16_2, &ignored16_3);
		return;
	case 110:
		sub_025297(&x, &ignored16_2, &ignored16_3);
		return;
	case 112:
		sub_025245(&x, &ignored16_2, &ignored16_3);
		return;
	case 114:
		sub_02527F(&x, &ignored16_2, &ignored16_3);
		return;
	case 116:
	case 124:
		sub_0251FF(x);
		return;
	case 118:
		sub_025208(x);
		return;
	case 120:
		sub_02521C(x);
		return;
	case 122:
		sub_025244();
		return;
	case 126:
		sub_02524E(x);
		return;
	case -38:
		sub_02402E();
		return;
	case -36:
		sub_02403A(u);
		return;
	case -34:
		sub_0240E3(x);
		return;
	case -32:
		sub_024113();
		return;
	case -30:
		sub_024125(x);
		return;
	case -26:
		sub_024188(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case -22:
		sub_024333(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case -20:
		sub_024363(x, 0u);
		return;
	case -18:
	case -16:
		sub_02439E(&ignored16, &ignored16_2, &u);
		return;
	case -14:
		sub_024409(&ignored16, &ignored16_3);
		return;
	case -12:
		sub_0241EC(&x, &ignored16_2);
		return;
	case -10:
		sub_02424B(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case -8:
		sub_02427E(x, u);
		return;
	case -6:
		sub_0242D0(x);
		return;
	case -4:
		sub_0242AC(x);
		return;
	case -2:
		sub_024329(x);
		return;
	}
}

void sub_024009(uint16_t u)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, x = 0;
	uint8_t t1 = 0;

	unk_486A = 0u;
	x = loaded_table_025740_ADDRESS;
	t1 = io_read8(VIDEO_18E0);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_024616(&ignored16, &ignored16_2, &u);
		return;
	case 2:
		sub_024648(&x, &ignored16_2, &ignored16_3);
		return;
	case 4:
		sub_0246C3();
		return;
	case 6:
		sub_0246DF();
		return;
	case 8:
		sub_024723();
		return;
	case 10:
		sub_024741(&ignored16, &ignored16_2);
		return;
	case 12:
		sub_024779();
		return;
	case 14:
		sub_024799();
		return;
	case 16:
		sub_0247AA(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 18:
		sub_02482F();
		return;
	case 20:
		sub_024839(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 22:
		sub_02488C(&ignored16, &ignored16_3);
		return;
	case 24:
		sub_0248F4();
		return;
	case 26:
		sub_024939(&ignored16, &ignored16_2, &u);
		return;
	case 28:
		sub_02496D(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 30:
		sub_0249B6(x);
		return;
	case 32:
		sub_024A0B(&ignored16, &ignored16_2);
		return;
	case 34:
		sub_024AB0(&ignored16, &ignored16_3);
		return;
	case 36:
		sub_024AD3(&ignored16, &ignored16_3);
		return;
	case 38:
		sub_024B3F(&ignored16, &ignored16_2, &u);
		return;
	case 40:
		sub_024B7E(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 42:
		sub_024C30(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 44:
		sub_024CA6(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 46:
		sub_024CC2();
		return;
	case 48:
		sub_024CED(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 50:
		sub_024D08(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 52:
		sub_024D43(x);
		return;
	case 54:
		sub_024D61(x);
		return;
	case 56:
		sub_024D83(x);
		return;
	case 58:
		sub_024D98(x);
		return;
	case 60:
		sub_024DA6(x);
		return;
	case 62:
		sub_024DBF(x);
		return;
	case 64:
		sub_024DD7(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 66:
		sub_024E10(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 68:
		sub_024E6B();
		return;
	case 70:
		sub_024E87(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 72:
		sub_024EBD(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 74:
		sub_024F15(&ignored16, &ignored16_2, &u);
		return;
	case 76:
		sub_0251C9(&ignored16, &ignored16_2, &u);
		return;
	case 78:
		sub_025349(&ignored16, &ignored16_3);
		return;
	case 80:
		sub_0251F5();
		return;
	case 82:
		sub_0251F6(&x, &ignored16_2, &ignored16_3);
		return;
	case 84:
		sub_025297(&x, &ignored16_2, &ignored16_3);
		return;
	case 86:
		sub_025245(&x, &ignored16_2, &ignored16_3);
		return;
	case 88:
		sub_02527F(&x, &ignored16_2, &ignored16_3);
		return;
	case 90:
	case 98:
	case 106:
		sub_0251FF(x);
		return;
	case 92:
		sub_025208(x);
		return;
	case 94:
		sub_02521C(x);
		return;
	case 96:
	case 104:
	case 112:
		sub_025244();
		return;
	case 100:
		sub_02524E(x);
		return;
	case 102:
	case 110:
		sub_02525D(x);
		return;
	case 108:
		sub_025288(x);
		return;
	case 114:
		sub_0252A0(x);
		return;
	case 116:
		sub_0252A9(x);
		return;
	case 118:
		sub_0252B9(x);
		return;
	case 120:
		sub_0252DB();
		return;
	case -64:
		sub_02402E();
		return;
	case -62:
		sub_02403A(u);
		return;
	case -60:
		sub_0240E3(x);
		return;
	case -58:
		sub_024113();
		return;
	case -56:
		sub_024125(x);
		return;
	case -54:
	case -26:
		sub_024155(&ignored16, &ignored16_2, &u);
		return;
	case -52:
		sub_024188(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case -50:
	case -22:
		sub_0241E2(&ignored16, &ignored16_2, &u);
		return;
	case -48:
		sub_024333(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case -46:
		sub_024363(x, 0u);
		return;
	case -44:
	case -42:
		sub_02439E(&ignored16, &ignored16_2, &u);
		return;
	case -40:
		sub_024409(&ignored16, &ignored16_3);
		return;
	case -38:
		sub_0241EC(&x, &ignored16_2);
		return;
	case -36:
		sub_02424B(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case -34:
		sub_02427E(x, u);
		return;
	case -32:
		sub_0242D0(x);
		return;
	case -30:
		sub_0242AC(x);
		return;
	case -28:
		sub_024329(x);
		return;
	case -24:
		sub_02441C(&ignored16, &ignored16_2, &u);
		return;
	case -20:
		sub_02448F(&ignored16, &ignored16_2, &u);
		return;
	case -18:
		sub_024532(&ignored16_2, &u);
		return;
	case -16:
		sub_024557(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case -14:
		sub_024571();
		return;
	case -12:
		sub_02457C(&ignored16_2, &u);
		return;
	case -10:
		sub_0245A3(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case -8:
		sub_0245D1(&ignored16, &ignored16_2, &u);
		return;
	case -6:
		sub_0245E1(&ignored16, &ignored16_2, &u);
		return;
	case -4:
		sub_0245E8();
		return;
	case -2:
		sub_0245F4(&ignored16, &ignored16_3);
		return;
	}
}

void sub_02400C(uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t ignored16 = 0, x = 0;
	uint8_t t1 = 0, t2 = 0;

	x = loaded_table_02574A_ADDRESS;
	t1 = io_read8(VIDEO_18E0);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_024741(&x, &y);
		break;
	case 2:
		sub_024779();
		break;
	case 4:
		sub_024799();
		break;
	case 6:
		sub_0247AA(&x, &y, &u);
		break;
	case 8:
		sub_02482F();
		break;
	case 10:
		sub_024839(&x, &y, &u);
		break;
	case 12:
		sub_02488C(&x, &u);
		break;
	case 14:
		sub_0248F4();
		break;
	case 16:
		sub_024939(&x, &y, &u);
		break;
	case 18:
		sub_02496D(&x, &y, &u);
		break;
	case 20:
		y = sub_0249B6(x);
		break;
	case 22:
		sub_024A0B(&x, &y);
		break;
	case 24:
		sub_024AB0(&x, &u);
		break;
	case 26:
		sub_024AD3(&x, &u);
		break;
	case 28:
		sub_024B3F(&x, &y, &u);
		break;
	case 30:
		sub_024B7E(&x, &y, &u);
		break;
	case 32:
		sub_024C30(&x, &y, &u);
		break;
	case 34:
		sub_024CA6(&x, &y, &u);
		break;
	case 36:
		sub_024CC2();
		break;
	case 38:
		sub_024CED(&x, &y, &u);
		break;
	case 40:
		sub_024D08(&x, &y, &u);
		break;
	case 42:
		sub_024D43(x);
		break;
	case 44:
		sub_024D61(x);
		break;
	case 46:
		sub_024D83(x);
		break;
	case 48:
		sub_024D98(x);
		break;
	case 50:
		sub_024DA6(x);
		break;
	case 52:
		sub_024DBF(x);
		break;
	case 54:
		sub_024DD7(&x, &y, &u);
		break;
	case 56:
		sub_024E10(&x, &y, &u);
		break;
	case 58:
		sub_024E6B();
		break;
	case 60:
		sub_024E87(&x, &y, &u);
		break;
	case 62:
		sub_024EBD(&x, &y, &u);
		break;
	case 64:
		sub_024F15(&x, &y, &u);
		break;
	case 66:
		sub_0251C9(&x, &y, &u);
		break;
	case 68:
		sub_025349(&x, &u);
		break;
	case 70:
		sub_0251F5();
		break;
	case 72:
		sub_0251F6(&x, &y, &u);
		break;
	case 74:
		sub_025297(&x, &y, &u);
		break;
	case 76:
		sub_025245(&x, &y, &u);
		break;
	case 78:
		sub_02527F(&x, &y, &u);
		break;
	case 80:
	case 88:
	case 96:
		sub_0251FF(x);
		break;
	case 82:
		sub_025208(x);
		break;
	case 84:
		sub_02521C(x);
		break;
	case 86:
	case 94:
	case 102:
		sub_025244();
		break;
	case 90:
		sub_02524E(x);
		break;
	case 92:
	case 100:
		sub_02525D(x);
		break;
	case 98:
		sub_025288(x);
		break;
	case 104:
		sub_0252A0(x);
		break;
	case 106:
		sub_0252A9(x);
		break;
	case 108:
		sub_0252B9(x);
		break;
	case 110:
		sub_0252DB();
		break;
	case -74:
		sub_02402E();
		break;
	case -72:
		u = sub_02403A(u);
		break;
	case -70:
		sub_0240E3(x);
		break;
	case -68:
		sub_024113();
		break;
	case -66:
		sub_024125(x);
		break;
	case -64:
	case -36:
		sub_024155(&x, &y, &u);
		break;
	case -62:
		sub_024188(&x, &y, &u);
		break;
	case -60:
	case -32:
		sub_0241E2(&x, &y, &u);
		break;
	case -58:
		sub_024333(&x, &y, &u);
		break;
	case -56:
		y = sub_024363(x, y);
		break;
	case -54:
	case -52:
		sub_02439E(&x, &y, &u);
		break;
	case -50:
		sub_024409(&x, &u);
		break;
	case -48:
		sub_0241EC(&x, &y);
		break;
	case -46:
		sub_02424B(&x, &y, &u);
		break;
	case -44:
		u = sub_02427E(x, u);
		break;
	case -42:
		sub_0242D0(x);
		break;
	case -40:
		sub_0242AC(x);
		break;
	case -38:
		sub_024329(x);
		break;
	case -34:
		sub_02441C(&x, &y, &u);
		break;
	case -30:
		sub_02448F(&x, &y, &u);
		break;
	case -28:
		sub_024532(&y, &u);
		break;
	case -26:
		sub_024557(&x, &y, &u);
		break;
	case -24:
		sub_024571();
		break;
	case -22:
		sub_02457C(&y, &u);
		break;
	case -20:
		sub_0245A3(&x, &y, &u);
		break;
	case -18:
		sub_0245D1(&x, &y, &u);
		break;
	case -16:
		sub_0245E1(&x, &y, &u);
		break;
	case -14:
		sub_0245E8();
		break;
	case -12:
		sub_0245F4(&x, &u);
		break;
	case -10:
		sub_024616(&x, &y, &u);
		break;
	case -8:
		sub_024648(&x, &y, &u);
		break;
	case -6:
		sub_0246C3();
		break;
	case -4:
		sub_0246DF();
		break;
	case -2:
		sub_024723();
		break;
	}
	x = loaded_table_025752_ADDRESS;
	t2 = io_read8(VIDEO_18E1);
	switch ((int8_t)(uint8_t)((uint32_t)t2 << 1))
	{
	case 0:
		sub_02482F();
		break;
	case 2:
		sub_024839(&ignored16, &y, &u);
		break;
	case 4:
		sub_02488C(&ignored16, &u);
		break;
	case 6:
		sub_0248F4();
		break;
	case 8:
		sub_024939(&ignored16, &y, &u);
		break;
	case 10:
		sub_02496D(&ignored16, &y, &u);
		break;
	case 12:
		y = sub_0249B6(x);
		break;
	case 14:
		sub_024A0B(&ignored16, &y);
		break;
	case 16:
		sub_024AB0(&ignored16, &u);
		break;
	case 18:
		sub_024AD3(&ignored16, &u);
		break;
	case 20:
		sub_024B3F(&ignored16, &y, &u);
		break;
	case 22:
		sub_024B7E(&ignored16, &y, &u);
		break;
	case 24:
		sub_024C30(&ignored16, &y, &u);
		break;
	case 26:
		sub_024CA6(&ignored16, &y, &u);
		break;
	case 28:
		sub_024CC2();
		break;
	case 30:
		sub_024CED(&ignored16, &y, &u);
		break;
	case 32:
		sub_024D08(&ignored16, &y, &u);
		break;
	case 34:
		sub_024D43(x);
		break;
	case 36:
		sub_024D61(x);
		break;
	case 38:
		sub_024D83(x);
		break;
	case 40:
		sub_024D98(x);
		break;
	case 42:
		sub_024DA6(x);
		break;
	case 44:
		sub_024DBF(x);
		break;
	case 46:
		sub_024DD7(&ignored16, &y, &u);
		break;
	case 48:
		sub_024E10(&ignored16, &y, &u);
		break;
	case 50:
		sub_024E6B();
		break;
	case 52:
		sub_024E87(&ignored16, &y, &u);
		break;
	case 54:
		sub_024EBD(&ignored16, &y, &u);
		break;
	case 56:
		sub_024F15(&ignored16, &y, &u);
		break;
	case 58:
		sub_0251C9(&ignored16, &y, &u);
		break;
	case 60:
		sub_025349(&ignored16, &u);
		break;
	case 62:
		sub_0251F5();
		break;
	case 64:
		sub_0251F6(&x, &y, &u);
		break;
	case 66:
		sub_025297(&x, &y, &u);
		break;
	case 68:
		sub_025245(&x, &y, &u);
		break;
	case 70:
		sub_02527F(&x, &y, &u);
		break;
	case 72:
	case 80:
	case 88:
		sub_0251FF(x);
		break;
	case 74:
		sub_025208(x);
		break;
	case 76:
		sub_02521C(x);
		break;
	case 78:
	case 86:
	case 94:
		sub_025244();
		break;
	case 82:
		sub_02524E(x);
		break;
	case 84:
	case 92:
		sub_02525D(x);
		break;
	case 90:
		sub_025288(x);
		break;
	case 96:
		sub_0252A0(x);
		break;
	case 98:
		sub_0252A9(x);
		break;
	case 100:
		sub_0252B9(x);
		break;
	case 102:
		sub_0252DB();
		break;
	case -82:
		sub_02402E();
		break;
	case -80:
		u = sub_02403A(u);
		break;
	case -78:
		sub_0240E3(x);
		break;
	case -76:
		sub_024113();
		break;
	case -74:
		sub_024125(x);
		break;
	case -72:
	case -44:
		sub_024155(&ignored16, &y, &u);
		break;
	case -70:
		sub_024188(&ignored16, &y, &u);
		break;
	case -68:
	case -40:
		sub_0241E2(&ignored16, &y, &u);
		break;
	case -66:
		sub_024333(&ignored16, &y, &u);
		break;
	case -64:
		y = sub_024363(x, y);
		break;
	case -62:
	case -60:
		sub_02439E(&ignored16, &y, &u);
		break;
	case -58:
		sub_024409(&ignored16, &u);
		break;
	case -56:
		sub_0241EC(&x, &y);
		break;
	case -54:
		sub_02424B(&ignored16, &y, &u);
		break;
	case -52:
		u = sub_02427E(x, u);
		break;
	case -50:
		sub_0242D0(x);
		break;
	case -48:
		sub_0242AC(x);
		break;
	case -46:
		sub_024329(x);
		break;
	case -42:
		sub_02441C(&ignored16, &y, &u);
		break;
	case -38:
		sub_02448F(&ignored16, &y, &u);
		break;
	case -36:
		sub_024532(&y, &u);
		break;
	case -34:
		sub_024557(&ignored16, &y, &u);
		break;
	case -32:
		sub_024571();
		break;
	case -30:
		sub_02457C(&y, &u);
		break;
	case -28:
		sub_0245A3(&ignored16, &y, &u);
		break;
	case -26:
		sub_0245D1(&ignored16, &y, &u);
		break;
	case -24:
		sub_0245E1(&ignored16, &y, &u);
		break;
	case -22:
		sub_0245E8();
		break;
	case -20:
		sub_0245F4(&ignored16, &u);
		break;
	case -18:
		sub_024616(&ignored16, &y, &u);
		break;
	case -16:
		sub_024648(&x, &y, &u);
		break;
	case -14:
		sub_0246C3();
		break;
	case -12:
		sub_0246DF();
		break;
	case -10:
		sub_024723();
		break;
	case -8:
		sub_024741(&ignored16, &y);
		break;
	case -6:
		sub_024779();
		break;
	case -4:
		sub_024799();
		break;
	case -2:
		sub_0247AA(&ignored16, &y, &u);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_02400F(uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, x = 0;
	uint8_t t1 = 0;

	d = loaded_table_078000_ADDRESS;
	sub_078653(d, &ignored16, &carry);
	if (carry)
	{
		sub_07868C(&ignored16, &u);
		unk_4872 = 0u;
	}
	else
	{
		unk_486A = 0u;
		x = loaded_table_02575A_ADDRESS;
		t1 = io_read8(VIDEO_18E0);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			sub_024939(&ignored16, &y, &u);
			break;
		case 2:
			sub_02496D(&ignored16, &y, &u);
			break;
		case 4:
			y = sub_0249B6(x);
			break;
		case 6:
			sub_024A0B(&ignored16, &y);
			break;
		case 8:
			sub_024AB0(&ignored16, &u);
			break;
		case 10:
			sub_024AD3(&ignored16, &u);
			break;
		case 12:
			sub_024B3F(&ignored16, &y, &u);
			break;
		case 14:
			sub_024B7E(&ignored16, &y, &u);
			break;
		case 16:
			sub_024C30(&ignored16, &y, &u);
			break;
		case 18:
			sub_024CA6(&ignored16, &y, &u);
			break;
		case 20:
			sub_024CC2();
			break;
		case 22:
			sub_024CED(&ignored16, &y, &u);
			break;
		case 24:
			sub_024D08(&ignored16, &y, &u);
			break;
		case 26:
			sub_024D43(x);
			break;
		case 28:
			sub_024D61(x);
			break;
		case 30:
			sub_024D83(x);
			break;
		case 32:
			sub_024D98(x);
			break;
		case 34:
			sub_024DA6(x);
			break;
		case 36:
			sub_024DBF(x);
			break;
		case 38:
			sub_024DD7(&ignored16, &y, &u);
			break;
		case 40:
			sub_024E10(&ignored16, &y, &u);
			break;
		case 42:
			sub_024E6B();
			break;
		case 44:
			sub_024E87(&ignored16, &y, &u);
			break;
		case 46:
			sub_024EBD(&ignored16, &y, &u);
			break;
		case 48:
			sub_024F15(&ignored16, &y, &u);
			break;
		case 50:
			sub_0251C9(&ignored16, &y, &u);
			break;
		case 52:
			sub_025349(&ignored16, &u);
			break;
		case 54:
			sub_0251F5();
			break;
		case 56:
			sub_0251F6(&x, &y, &u);
			break;
		case 58:
			sub_025297(&x, &y, &u);
			break;
		case 60:
			sub_025245(&x, &y, &u);
			break;
		case 62:
			sub_02527F(&x, &y, &u);
			break;
		case 64:
		case 72:
		case 80:
			sub_0251FF(x);
			break;
		case 66:
			sub_025208(x);
			break;
		case 68:
			sub_02521C(x);
			break;
		case 70:
		case 78:
		case 86:
			sub_025244();
			break;
		case 74:
			sub_02524E(x);
			break;
		case 76:
		case 84:
			sub_02525D(x);
			break;
		case 82:
			sub_025288(x);
			break;
		case 88:
			sub_0252A0(x);
			break;
		case 90:
			sub_0252A9(x);
			break;
		case 92:
			sub_0252B9(x);
			break;
		case 94:
			sub_0252DB();
			break;
		case -90:
			sub_02402E();
			break;
		case -88:
			u = sub_02403A(u);
			break;
		case -86:
			sub_0240E3(x);
			break;
		case -84:
			sub_024113();
			break;
		case -82:
			sub_024125(x);
			break;
		case -80:
		case -52:
			sub_024155(&ignored16, &y, &u);
			break;
		case -78:
			sub_024188(&ignored16, &y, &u);
			break;
		case -76:
		case -48:
			sub_0241E2(&ignored16, &y, &u);
			break;
		case -74:
			sub_024333(&ignored16, &y, &u);
			break;
		case -72:
			y = sub_024363(x, y);
			break;
		case -70:
		case -68:
			sub_02439E(&ignored16, &y, &u);
			break;
		case -66:
			sub_024409(&ignored16, &u);
			break;
		case -64:
			sub_0241EC(&x, &y);
			break;
		case -62:
			sub_02424B(&ignored16, &y, &u);
			break;
		case -60:
			u = sub_02427E(x, u);
			break;
		case -58:
			sub_0242D0(x);
			break;
		case -56:
			sub_0242AC(x);
			break;
		case -54:
			sub_024329(x);
			break;
		case -50:
			sub_02441C(&ignored16, &y, &u);
			break;
		case -46:
			sub_02448F(&ignored16, &y, &u);
			break;
		case -44:
			sub_024532(&y, &u);
			break;
		case -42:
			sub_024557(&ignored16, &y, &u);
			break;
		case -40:
			sub_024571();
			break;
		case -38:
			sub_02457C(&y, &u);
			break;
		case -36:
			sub_0245A3(&ignored16, &y, &u);
			break;
		case -34:
			sub_0245D1(&ignored16, &y, &u);
			break;
		case -32:
			sub_0245E1(&ignored16, &y, &u);
			break;
		case -30:
			sub_0245E8();
			break;
		case -28:
			sub_0245F4(&ignored16, &u);
			break;
		case -26:
			sub_024616(&ignored16, &y, &u);
			break;
		case -24:
			sub_024648(&x, &y, &u);
			break;
		case -22:
			sub_0246C3();
			break;
		case -20:
			sub_0246DF();
			break;
		case -18:
			sub_024723();
			break;
		case -16:
			sub_024741(&ignored16, &y);
			break;
		case -14:
			sub_024779();
			break;
		case -12:
			sub_024799();
			break;
		case -10:
			sub_0247AA(&ignored16, &y, &u);
			break;
		case -8:
			sub_02482F();
			break;
		case -6:
			sub_024839(&ignored16, &y, &u);
			break;
		case -4:
			sub_02488C(&ignored16, &u);
			break;
		case -2:
			sub_0248F4();
			break;
		}
	}
	*p_y = y;
	*p_u = u;
}

void sub_024012(uint16_t u)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, x = 0;
	uint8_t t1 = 0;

	unk_486A = 0u;
	x = loaded_table_025780_ADDRESS;
	t1 = io_read8(VIDEO_18E0);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_024DD7(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 2:
		sub_024E10(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 4:
		sub_024E6B();
		return;
	case 6:
		sub_024E87(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 8:
		sub_024EBD(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 10:
		sub_024F15(&ignored16, &ignored16_2, &u);
		return;
	case 12:
		sub_0251C9(&ignored16, &ignored16_2, &u);
		return;
	case 14:
		sub_025349(&ignored16, &ignored16_3);
		return;
	case 16:
		sub_0251F5();
		return;
	case 18:
		sub_0251F6(&x, &ignored16_2, &ignored16_3);
		return;
	case 20:
		sub_025297(&x, &ignored16_2, &ignored16_3);
		return;
	case 22:
		sub_025245(&x, &ignored16_2, &ignored16_3);
		return;
	case 24:
		sub_02527F(&x, &ignored16_2, &ignored16_3);
		return;
	case 26:
	case 34:
	case 42:
		sub_0251FF(x);
		return;
	case 28:
		sub_025208(x);
		return;
	case 30:
		sub_02521C(x);
		return;
	case 32:
	case 40:
	case 48:
		sub_025244();
		return;
	case 36:
		sub_02524E(x);
		return;
	case 38:
	case 46:
		sub_02525D(x);
		return;
	case 44:
		sub_025288(x);
		return;
	case 50:
		sub_0252A0(x);
		return;
	case 52:
		sub_0252A9(x);
		return;
	case 54:
		sub_0252B9(x);
		return;
	case 56:
		sub_0252DB();
		return;
	case -128:
		sub_02402E();
		return;
	case -126:
		sub_02403A(u);
		return;
	case -124:
		sub_0240E3(x);
		return;
	case -122:
		sub_024113();
		return;
	case -120:
		sub_024125(x);
		return;
	case -118:
	case -90:
		sub_024155(&ignored16, &ignored16_2, &u);
		return;
	case -116:
		sub_024188(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case -114:
	case -86:
		sub_0241E2(&ignored16, &ignored16_2, &u);
		return;
	case -112:
		sub_024333(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case -110:
		sub_024363(x, 0u);
		return;
	case -108:
	case -106:
		sub_02439E(&ignored16, &ignored16_2, &u);
		return;
	case -104:
		sub_024409(&ignored16, &ignored16_3);
		return;
	case -102:
		sub_0241EC(&x, &ignored16_2);
		return;
	case -100:
		sub_02424B(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case -98:
		sub_02427E(x, u);
		return;
	case -96:
		sub_0242D0(x);
		return;
	case -94:
		sub_0242AC(x);
		return;
	case -92:
		sub_024329(x);
		return;
	case -88:
		sub_02441C(&ignored16, &ignored16_2, &u);
		return;
	case -84:
		sub_02448F(&ignored16, &ignored16_2, &u);
		return;
	case -82:
		sub_024532(&ignored16_2, &u);
		return;
	case -80:
		sub_024557(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case -78:
		sub_024571();
		return;
	case -76:
		sub_02457C(&ignored16_2, &u);
		return;
	case -74:
		sub_0245A3(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case -72:
		sub_0245D1(&ignored16, &ignored16_2, &u);
		return;
	case -70:
		sub_0245E1(&ignored16, &ignored16_2, &u);
		return;
	case -68:
		sub_0245E8();
		return;
	case -66:
		sub_0245F4(&ignored16, &ignored16_3);
		return;
	case -64:
		sub_024616(&ignored16, &ignored16_2, &u);
		return;
	case -62:
		sub_024648(&x, &ignored16_2, &ignored16_3);
		return;
	case -60:
		sub_0246C3();
		return;
	case -58:
		sub_0246DF();
		return;
	case -56:
		sub_024723();
		return;
	case -54:
		sub_024741(&ignored16, &ignored16_2);
		return;
	case -52:
		sub_024779();
		return;
	case -50:
		sub_024799();
		return;
	case -48:
		sub_0247AA(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case -46:
		sub_02482F();
		return;
	case -44:
		sub_024839(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case -42:
		sub_02488C(&ignored16, &ignored16_3);
		return;
	case -40:
		sub_0248F4();
		return;
	case -38:
		sub_024939(&ignored16, &ignored16_2, &u);
		return;
	case -36:
		sub_02496D(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case -34:
		sub_0249B6(x);
		return;
	case -32:
		sub_024A0B(&ignored16, &ignored16_2);
		return;
	case -30:
		sub_024AB0(&ignored16, &ignored16_3);
		return;
	case -28:
		sub_024AD3(&ignored16, &ignored16_3);
		return;
	case -26:
		sub_024B3F(&ignored16, &ignored16_2, &u);
		return;
	case -24:
		sub_024B7E(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case -22:
		sub_024C30(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case -20:
		sub_024CA6(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case -18:
		sub_024CC2();
		return;
	case -16:
		sub_024CED(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case -14:
		sub_024D08(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case -12:
		sub_024D43(x);
		return;
	case -10:
		sub_024D61(x);
		return;
	case -8:
		sub_024D83(x);
		return;
	case -6:
		sub_024D98(x);
		return;
	case -4:
		sub_024DA6(x);
		return;
	case -2:
		sub_024DBF(x);
		return;
	}
}

void sub_024015(void)
{
	uint8_t a = 0, b = 0;
	uint16_t d = 0, x = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t7 = 0;
	uint16_t t4 = 0, t5 = 0, t6 = 0;

	t1 = io_read8(VIDEO_18EA);
	io_write8(VIDEO_18EA, 0u);
	x = VIDEO_1A00;
	do
	{
		t2 = io_read8(VIDEO_18EA);
		t3 = io_read8(VIDEO_18EB);
		d = ((uint32_t)(uint8_t)((uint32_t)(t2 + t3) << 1) << 8) | 0x40u;
		d = sub_0254F4(d);
		a = (uint8_t)(d >> 8);
		b = (uint8_t)d;
		t4 = (((uint32_t)a << 8) | b) + 0x196u;
		a = (t4 >> 8) & 1u;
		t5 = a | 0x1000u;
		t6 = x;
		x = t6 + 2u;
		mem_write16(t6, ((uint32_t)(uint8_t)t4 << 8) | (uint8_t)t5);
		t7 = io_read8(VIDEO_18EA);
		io_write8(VIDEO_18EA, t7 - 1u);
	} while (t7 != 1u);
}

void sub_024018(uint16_t u)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, x = 0;
	uint8_t t1 = 0;

	d = loaded_table_078000_ADDRESS;
	sub_078653(d, &ignored16, &carry);
	if (carry)
	{
		sub_024D0E(&ignored16, &ignored16_2, &ignored16_3);
		return;
	}
	unk_486A = 0u;
	x = loaded_table_025766_ADDRESS;
	t1 = io_read8(VIDEO_18E0);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_024B3F(&ignored16, &ignored16_2, &u);
		return;
	case 2:
		sub_024B7E(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 4:
		sub_024C30(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 6:
		sub_024CA6(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 8:
		sub_024CC2();
		return;
	case 10:
		sub_024CED(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 12:
		sub_024D08(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 14:
		sub_024D43(x);
		return;
	case 16:
		sub_024D61(x);
		return;
	case 18:
		sub_024D83(x);
		return;
	case 20:
		sub_024D98(x);
		return;
	case 22:
		sub_024DA6(x);
		return;
	case 24:
		sub_024DBF(x);
		return;
	case 26:
		sub_024DD7(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 28:
		sub_024E10(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 30:
		sub_024E6B();
		return;
	case 32:
		sub_024E87(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 34:
		sub_024EBD(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 36:
		sub_024F15(&ignored16, &ignored16_2, &u);
		return;
	case 38:
		sub_0251C9(&ignored16, &ignored16_2, &u);
		return;
	case 40:
		sub_025349(&ignored16, &ignored16_3);
		return;
	case 42:
		sub_0251F5();
		return;
	case 44:
		sub_0251F6(&x, &ignored16_2, &ignored16_3);
		return;
	case 46:
		sub_025297(&x, &ignored16_2, &ignored16_3);
		return;
	case 48:
		sub_025245(&x, &ignored16_2, &ignored16_3);
		return;
	case 50:
		sub_02527F(&x, &ignored16_2, &ignored16_3);
		return;
	case 52:
	case 60:
	case 68:
		sub_0251FF(x);
		return;
	case 54:
		sub_025208(x);
		return;
	case 56:
		sub_02521C(x);
		return;
	case 58:
	case 66:
	case 74:
		sub_025244();
		return;
	case 62:
		sub_02524E(x);
		return;
	case 64:
	case 72:
		sub_02525D(x);
		return;
	case 70:
		sub_025288(x);
		return;
	case 76:
		sub_0252A0(x);
		return;
	case 78:
		sub_0252A9(x);
		return;
	case 80:
		sub_0252B9(x);
		return;
	case 82:
		sub_0252DB();
		return;
	case -102:
		sub_02402E();
		return;
	case -100:
		sub_02403A(u);
		return;
	case -98:
		sub_0240E3(x);
		return;
	case -96:
		sub_024113();
		return;
	case -94:
		sub_024125(x);
		return;
	case -92:
	case -64:
		sub_024155(&ignored16, &ignored16_2, &u);
		return;
	case -90:
		sub_024188(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case -88:
	case -60:
		sub_0241E2(&ignored16, &ignored16_2, &u);
		return;
	case -86:
		sub_024333(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case -84:
		sub_024363(x, 0u);
		return;
	case -82:
	case -80:
		sub_02439E(&ignored16, &ignored16_2, &u);
		return;
	case -78:
		sub_024409(&ignored16, &ignored16_3);
		return;
	case -76:
		sub_0241EC(&x, &ignored16_2);
		return;
	case -74:
		sub_02424B(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case -72:
		sub_02427E(x, u);
		return;
	case -70:
		sub_0242D0(x);
		return;
	case -68:
		sub_0242AC(x);
		return;
	case -66:
		sub_024329(x);
		return;
	case -62:
		sub_02441C(&ignored16, &ignored16_2, &u);
		return;
	case -58:
		sub_02448F(&ignored16, &ignored16_2, &u);
		return;
	case -56:
		sub_024532(&ignored16_2, &u);
		return;
	case -54:
		sub_024557(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case -52:
		sub_024571();
		return;
	case -50:
		sub_02457C(&ignored16_2, &u);
		return;
	case -48:
		sub_0245A3(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case -46:
		sub_0245D1(&ignored16, &ignored16_2, &u);
		return;
	case -44:
		sub_0245E1(&ignored16, &ignored16_2, &u);
		return;
	case -42:
		sub_0245E8();
		return;
	case -40:
		sub_0245F4(&ignored16, &ignored16_3);
		return;
	case -38:
		sub_024616(&ignored16, &ignored16_2, &u);
		return;
	case -36:
		sub_024648(&x, &ignored16_2, &ignored16_3);
		return;
	case -34:
		sub_0246C3();
		return;
	case -32:
		sub_0246DF();
		return;
	case -30:
		sub_024723();
		return;
	case -28:
		sub_024741(&ignored16, &ignored16_2);
		return;
	case -26:
		sub_024779();
		return;
	case -24:
		sub_024799();
		return;
	case -22:
		sub_0247AA(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case -20:
		sub_02482F();
		return;
	case -18:
		sub_024839(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case -16:
		sub_02488C(&ignored16, &ignored16_3);
		return;
	case -14:
		sub_0248F4();
		return;
	case -12:
		sub_024939(&ignored16, &ignored16_2, &u);
		return;
	case -10:
		sub_02496D(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case -8:
		sub_0249B6(x);
		return;
	case -6:
		sub_024A0B(&ignored16, &ignored16_2);
		return;
	case -4:
		sub_024AB0(&ignored16, &ignored16_3);
		return;
	case -2:
		sub_024AD3(&ignored16, &ignored16_3);
		return;
	}
}

void sub_02401B(uint16_t u)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, x = 0;
	uint8_t t1 = 0;

	x = loaded_table_025732_ADDRESS;
	t1 = io_read8(VIDEO_18E0);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_024571();
		return;
	case 2:
		sub_02457C(&ignored16_2, &u);
		return;
	case 4:
		sub_0245A3(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 6:
		sub_0245D1(&ignored16, &ignored16_2, &u);
		return;
	case 8:
		sub_0245E1(&ignored16, &ignored16_2, &u);
		return;
	case 10:
		sub_0245E8();
		return;
	case 12:
		sub_0245F4(&ignored16, &ignored16_3);
		return;
	case 14:
		sub_024616(&ignored16, &ignored16_2, &u);
		return;
	case 16:
		sub_024648(&x, &ignored16_2, &ignored16_3);
		return;
	case 18:
		sub_0246C3();
		return;
	case 20:
		sub_0246DF();
		return;
	case 22:
		sub_024723();
		return;
	case 24:
		sub_024741(&ignored16, &ignored16_2);
		return;
	case 26:
		sub_024779();
		return;
	case 28:
		sub_024799();
		return;
	case 30:
		sub_0247AA(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 32:
		sub_02482F();
		return;
	case 34:
		sub_024839(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 36:
		sub_02488C(&ignored16, &ignored16_3);
		return;
	case 38:
		sub_0248F4();
		return;
	case 40:
		sub_024939(&ignored16, &ignored16_2, &u);
		return;
	case 42:
		sub_02496D(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 44:
		sub_0249B6(x);
		return;
	case 46:
		sub_024A0B(&ignored16, &ignored16_2);
		return;
	case 48:
		sub_024AB0(&ignored16, &ignored16_3);
		return;
	case 50:
		sub_024AD3(&ignored16, &ignored16_3);
		return;
	case 52:
		sub_024B3F(&ignored16, &ignored16_2, &u);
		return;
	case 54:
		sub_024B7E(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 56:
		sub_024C30(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 58:
		sub_024CA6(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 60:
		sub_024CC2();
		return;
	case 62:
		sub_024CED(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 64:
		sub_024D08(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 66:
		sub_024D43(x);
		return;
	case 68:
		sub_024D61(x);
		return;
	case 70:
		sub_024D83(x);
		return;
	case 72:
		sub_024D98(x);
		return;
	case 74:
		sub_024DA6(x);
		return;
	case 76:
		sub_024DBF(x);
		return;
	case 78:
		sub_024DD7(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 80:
		sub_024E10(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 82:
		sub_024E6B();
		return;
	case 84:
		sub_024E87(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 86:
		sub_024EBD(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 88:
		sub_024F15(&ignored16, &ignored16_2, &u);
		return;
	case 90:
		sub_0251C9(&ignored16, &ignored16_2, &u);
		return;
	case 92:
		sub_025349(&ignored16, &ignored16_3);
		return;
	case 94:
		sub_0251F5();
		return;
	case 96:
		sub_0251F6(&x, &ignored16_2, &ignored16_3);
		return;
	case 98:
		sub_025297(&x, &ignored16_2, &ignored16_3);
		return;
	case 100:
		sub_025245(&x, &ignored16_2, &ignored16_3);
		return;
	case 102:
		sub_02527F(&x, &ignored16_2, &ignored16_3);
		return;
	case 104:
	case 112:
	case 120:
		sub_0251FF(x);
		return;
	case 106:
		sub_025208(x);
		return;
	case 108:
		sub_02521C(x);
		return;
	case 110:
	case 118:
	case 126:
		sub_025244();
		return;
	case 114:
		sub_02524E(x);
		return;
	case 116:
	case 124:
		sub_02525D(x);
		return;
	case 122:
		sub_025288(x);
		return;
	case -50:
		sub_02402E();
		return;
	case -48:
		sub_02403A(u);
		return;
	case -46:
		sub_0240E3(x);
		return;
	case -44:
		sub_024113();
		return;
	case -42:
		sub_024125(x);
		return;
	case -40:
	case -12:
		sub_024155(&ignored16, &ignored16_2, &u);
		return;
	case -38:
		sub_024188(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case -36:
	case -8:
		sub_0241E2(&ignored16, &ignored16_2, &u);
		return;
	case -34:
		sub_024333(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case -32:
		sub_024363(x, 0u);
		return;
	case -30:
	case -28:
		sub_02439E(&ignored16, &ignored16_2, &u);
		return;
	case -26:
		sub_024409(&ignored16, &ignored16_3);
		return;
	case -24:
		sub_0241EC(&x, &ignored16_2);
		return;
	case -22:
		sub_02424B(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case -20:
		sub_02427E(x, u);
		return;
	case -18:
		sub_0242D0(x);
		return;
	case -16:
		sub_0242AC(x);
		return;
	case -14:
		sub_024329(x);
		return;
	case -10:
		sub_02441C(&ignored16, &ignored16_2, &u);
		return;
	case -6:
		sub_02448F(&ignored16, &ignored16_2, &u);
		return;
	case -4:
		sub_024532(&ignored16_2, &u);
		return;
	case -2:
		sub_024557(&ignored16, &ignored16_2, &ignored16_3);
		return;
	}
}

void sub_02401E(uint16_t u)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, x = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	d = 0x6000u;
	sub_078653(d, &ignored16, &carry);
	if (carry)
	{
		unk_4872 = 0u;
		x = VIDEO_2000;
		do
		{
			t1 = x - 1u;
			x = t1;
		} while (t1 != 0u);
		return;
	}
	unk_486A = 0u;
	x = loaded_table_025738_ADDRESS;
	t2 = io_read8(VIDEO_18E0);
	switch ((int8_t)(uint8_t)((uint32_t)t2 << 1))
	{
	case 0:
		sub_0245D1(&ignored16, &ignored16_2, &u);
		return;
	case 2:
		sub_0245E1(&ignored16, &ignored16_2, &u);
		return;
	case 4:
		sub_0245E8();
		return;
	case 6:
		sub_0245F4(&ignored16, &ignored16_3);
		return;
	case 8:
		sub_024616(&ignored16, &ignored16_2, &u);
		return;
	case 10:
		sub_024648(&x, &ignored16_2, &ignored16_3);
		return;
	case 12:
		sub_0246C3();
		return;
	case 14:
		sub_0246DF();
		return;
	case 16:
		sub_024723();
		return;
	case 18:
		sub_024741(&ignored16, &ignored16_2);
		return;
	case 20:
		sub_024779();
		return;
	case 22:
		sub_024799();
		return;
	case 24:
		sub_0247AA(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 26:
		sub_02482F();
		return;
	case 28:
		sub_024839(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 30:
		sub_02488C(&ignored16, &ignored16_3);
		return;
	case 32:
		sub_0248F4();
		return;
	case 34:
		sub_024939(&ignored16, &ignored16_2, &u);
		return;
	case 36:
		sub_02496D(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 38:
		sub_0249B6(x);
		return;
	case 40:
		sub_024A0B(&ignored16, &ignored16_2);
		return;
	case 42:
		sub_024AB0(&ignored16, &ignored16_3);
		return;
	case 44:
		sub_024AD3(&ignored16, &ignored16_3);
		return;
	case 46:
		sub_024B3F(&ignored16, &ignored16_2, &u);
		return;
	case 48:
		sub_024B7E(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 50:
		sub_024C30(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 52:
		sub_024CA6(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 54:
		sub_024CC2();
		return;
	case 56:
		sub_024CED(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 58:
		sub_024D08(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 60:
		sub_024D43(x);
		return;
	case 62:
		sub_024D61(x);
		return;
	case 64:
		sub_024D83(x);
		return;
	case 66:
		sub_024D98(x);
		return;
	case 68:
		sub_024DA6(x);
		return;
	case 70:
		sub_024DBF(x);
		return;
	case 72:
		sub_024DD7(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 74:
		sub_024E10(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 76:
		sub_024E6B();
		return;
	case 78:
		sub_024E87(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 80:
		sub_024EBD(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case 82:
		sub_024F15(&ignored16, &ignored16_2, &u);
		return;
	case 84:
		sub_0251C9(&ignored16, &ignored16_2, &u);
		return;
	case 86:
		sub_025349(&ignored16, &ignored16_3);
		return;
	case 88:
		sub_0251F5();
		return;
	case 90:
		sub_0251F6(&x, &ignored16_2, &ignored16_3);
		return;
	case 92:
		sub_025297(&x, &ignored16_2, &ignored16_3);
		return;
	case 94:
		sub_025245(&x, &ignored16_2, &ignored16_3);
		return;
	case 96:
		sub_02527F(&x, &ignored16_2, &ignored16_3);
		return;
	case 98:
	case 106:
	case 114:
		sub_0251FF(x);
		return;
	case 100:
		sub_025208(x);
		return;
	case 102:
		sub_02521C(x);
		return;
	case 104:
	case 112:
	case 120:
		sub_025244();
		return;
	case 108:
		sub_02524E(x);
		return;
	case 110:
	case 118:
		sub_02525D(x);
		return;
	case 116:
		sub_025288(x);
		return;
	case 122:
		sub_0252A0(x);
		return;
	case 124:
		sub_0252A9(x);
		return;
	case 126:
		sub_0252B9(x);
		return;
	case -56:
		sub_02402E();
		return;
	case -54:
		sub_02403A(u);
		return;
	case -52:
		sub_0240E3(x);
		return;
	case -50:
		sub_024113();
		return;
	case -48:
		sub_024125(x);
		return;
	case -46:
	case -18:
		sub_024155(&ignored16, &ignored16_2, &u);
		return;
	case -44:
		sub_024188(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case -42:
	case -14:
		sub_0241E2(&ignored16, &ignored16_2, &u);
		return;
	case -40:
		sub_024333(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case -38:
		sub_024363(x, 0u);
		return;
	case -36:
	case -34:
		sub_02439E(&ignored16, &ignored16_2, &u);
		return;
	case -32:
		sub_024409(&ignored16, &ignored16_3);
		return;
	case -30:
		sub_0241EC(&x, &ignored16_2);
		return;
	case -28:
		sub_02424B(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case -26:
		sub_02427E(x, u);
		return;
	case -24:
		sub_0242D0(x);
		return;
	case -22:
		sub_0242AC(x);
		return;
	case -20:
		sub_024329(x);
		return;
	case -16:
		sub_02441C(&ignored16, &ignored16_2, &u);
		return;
	case -12:
		sub_02448F(&ignored16, &ignored16_2, &u);
		return;
	case -10:
		sub_024532(&ignored16_2, &u);
		return;
	case -8:
		sub_024557(&ignored16, &ignored16_2, &ignored16_3);
		return;
	case -6:
		sub_024571();
		return;
	case -4:
		sub_02457C(&ignored16_2, &u);
		return;
	case -2:
		sub_0245A3(&ignored16, &ignored16_2, &ignored16_3);
		return;
	}
}

void sub_02402E(void)
{
	uint8_t t1 = 0;

	io_write16(VIDEO_18E7, 0x80u);
	t1 = io_read8(VIDEO_18E0);
	io_write8(VIDEO_18E0, t1 + 1u);
}

uint16_t sub_02403A(uint16_t u)
{
	uint32_t carry = 0;
	uint8_t d_2 = 0;
	uint16_t d = 0, u_2 = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = io_read16(VIDEO_18E7);
	io_write16(VIDEO_18E7, t1 - 1u);
	if (t1 != 1u)
		return u;
	d = 0x9600u;
	carry = sub_078689(d);
	d_2 = 2u;
	sub_07867D(d_2, &u_2, &carry);
	io_write16(VIDEO_18E1, u_2);
	mem_write8(u_2, 0x80u);
	mem_write8(u_2 + 1u, 0u);
	mem_write16(u_2 + 4u, 0xF93u);
	mem_write8(u_2 + 9u, 0x20u);
	mem_write16(u_2 + 0xCu, 0xE0u);
	mem_write16(u_2 + 0x11u, 0x100u);
	mem_write16(u_2 + 0x16u, 0xFF10u);
	d_2 = 2u;
	sub_07867D(d_2, &u_2, &carry);
	io_write16(0x18E3u, u_2);
	mem_write8(u_2, 0x80u);
	mem_write8(u_2 + 1u, 0u);
	mem_write16(u_2 + 4u, 0xF92u);
	mem_write8(u_2 + 9u, 0x20u);
	mem_write16(u_2 + 0xCu, 0xE0u);
	mem_write16(u_2 + 0x11u, 0x100u);
	mem_write16(u_2 + 0x16u, 0xFF70u);
	d_2 = 2u;
	sub_07867D(d_2, &u, &carry);
	io_write16(0x18E5u, u);
	mem_write8(u, 0x80u);
	mem_write8(u + 1u, 0u);
	mem_write16(u + 4u, 0xFA1u);
	mem_write8(u + 9u, 0x20u);
	mem_write16(u + 0xCu, 0xE0u);
	mem_write16(u + 0x11u, 0xFEu);
	mem_write16(u + 0x16u, 0xFF10u);
	io_write16(VIDEO_18E7, 0xE0u);
	t2 = io_read8(VIDEO_18E0);
	io_write8(VIDEO_18E0, t2 + 1u);
	return u;
}

uint16_t sub_0240E3(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t5 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = io_read16(VIDEO_18E7);
	io_write16(VIDEO_18E7, t1 - 1u);
	if (t1 != 1u)
		return x;
	d = 0x9500u;
	carry = sub_078689(d);
	t2 = io_read16(VIDEO_18E1);
	mem_write16(t2 + 0x19u, 0x100u);
	t3 = io_read16(0x18E3u);
	mem_write16(t3 + 0x19u, 0x100u);
	t4 = io_read16(0x18E5u);
	x = t4;
	mem_write16(x + 0x19u, 0x100u);
	io_write16(VIDEO_18E7, 0x100u);
	t5 = io_read8(VIDEO_18E0);
	io_write8(VIDEO_18E0, t5 + 1u);
	return x;
}

void sub_024113(void)
{
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = io_read16(VIDEO_18E7);
	io_write16(VIDEO_18E7, t1 - 1u);
	if (t1 == 1u)
	{
		io_write16(VIDEO_18E7, VIDEO_00C0);
		t2 = io_read8(VIDEO_18E0);
		io_write8(VIDEO_18E0, t2 + 1u);
	}
}

uint16_t sub_024125(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	if ((unk_4815 & 0xFu) == 0u)
	{
		t1 = io_read16(VIDEO_18E1);
		x = t1;
		t2 = mem_read16(x + 0x16u);
		if ((int16_t)t2 <= 0xB0)
		{
			d = 0x4A00u;
			carry = sub_078680(d);
		}
	}
	t3 = io_read16(VIDEO_18E7);
	io_write16(VIDEO_18E7, t3 - 1u);
	if (t3 == 1u)
		unk_4872 = 0u;
	return x;
}

void sub_024155(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, u_2 = 0, x = 0, y = 0;
	uint8_t t1 = 0;

	unk_487E = 1u;
	d = 0x880u;
	sub_078677(d, &ignored16, &u);
	unk_487E = 1u;
	d = 0xE89u;
	sub_078677(d, &ignored16, &u);
	d = 0u;
	sub_078656(d);
	d = 0xFFF0u;
	sub_0786C2(d);
	d = 0u;
	sub_0786C5(d);
	sub_07868C(&ignored16_2, &u_2);
	sub_07868F(&x, &y);
	t1 = io_read8(VIDEO_18E0);
	io_write8(VIDEO_18E0, t1 + 1u);
	*p_x = x;
	*p_y = y;
	*p_u = u_2;
}

void sub_024188(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, u_2 = 0, x_2 = 0, y_2 = 0;
	uint8_t t1 = 0;

	if (unk_485D != 0u)
		return;
	d = 0x9E00u;
	carry = sub_078689(d);
	io_write8(IO_1FB9, 0x3Fu);
	io_write8(IO_1FBA, 0x36u);
	unk_4875 = 0x84u;
	unk_4876 = 2u;
	d = 0x26u;
	sub_0786AD(d, &x_2, &ignored16, &u_2);
	io_write8(IO_1FB9, 0x13u);
	io_write8(IO_1FBA, 0x2Cu);
	d = 0xD26u;
	y_2 = sub_025388(x_2, d);
	mem_write8(y_2 + 0xAu, 0x30u);
	mem_write8(y_2 + 0xBu, 0x30u);
	mem_write8(y_2 + 0x30u, 4u);
	mem_write8(y_2 + 0x32u, 4u);
	mem_write8(y_2 + VIDEO_0031, 1u);
	t1 = io_read8(VIDEO_18E0);
	io_write8(VIDEO_18E0, t1 + 1u);
	*p_x = x_2;
	*p_y = y_2;
	*p_u = u_2;
}

void sub_0241E2(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t x = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		x = loaded_table_02571A_ADDRESS;
		t1 = io_read8(VIDEO_18E1);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			sub_0241EC(&x, &y);
			break;
		case 2:
			sub_02424B(&x, &y, &u);
			break;
		case 4:
			u = sub_02427E(x, u);
			break;
		case 6:
			sub_0242D0(x);
			break;
		case 8:
			sub_0242AC(x);
			break;
		case 10:
			sub_024329(x);
			break;
		case -16:
		case 12:
			sub_024155(&x, &y, &u);
			break;
		case 14:
			sub_02441C(&x, &y, &u);
			break;
		case -12:
		case 16:
			continue;
		case 18:
			sub_02448F(&x, &y, &u);
			break;
		case 20:
			sub_024532(&y, &u);
			break;
		case 22:
			sub_024557(&x, &y, &u);
			break;
		case 24:
			sub_024571();
			break;
		case 26:
			sub_02457C(&y, &u);
			break;
		case 28:
			sub_0245A3(&x, &y, &u);
			break;
		case 30:
			sub_0245D1(&x, &y, &u);
			break;
		case 32:
			sub_0245E1(&x, &y, &u);
			break;
		case 34:
			sub_0245E8();
			break;
		case 36:
			sub_0245F4(&x, &u);
			break;
		case 38:
			sub_024616(&x, &y, &u);
			break;
		case 40:
			sub_024648(&x, &y, &u);
			break;
		case 42:
			sub_0246C3();
			break;
		case 44:
			sub_0246DF();
			break;
		case 46:
			sub_024723();
			break;
		case 48:
			sub_024741(&x, &y);
			break;
		case 50:
			sub_024779();
			break;
		case 52:
			sub_024799();
			break;
		case 54:
			sub_0247AA(&x, &y, &u);
			break;
		case 56:
			sub_02482F();
			break;
		case 58:
			sub_024839(&x, &y, &u);
			break;
		case 60:
			sub_02488C(&x, &u);
			break;
		case 62:
			sub_0248F4();
			break;
		case 64:
			sub_024939(&x, &y, &u);
			break;
		case 66:
			sub_02496D(&x, &y, &u);
			break;
		case 68:
			y = sub_0249B6(x);
			break;
		case 70:
			sub_024A0B(&x, &y);
			break;
		case 72:
			sub_024AB0(&x, &u);
			break;
		case 74:
			sub_024AD3(&x, &u);
			break;
		case 76:
			sub_024B3F(&x, &y, &u);
			break;
		case 78:
			sub_024B7E(&x, &y, &u);
			break;
		case 80:
			sub_024C30(&x, &y, &u);
			break;
		case 82:
			sub_024CA6(&x, &y, &u);
			break;
		case 84:
			x = sub_024CC2();
			break;
		case 86:
			sub_024CED(&x, &y, &u);
			break;
		case 88:
			sub_024D08(&x, &y, &u);
			break;
		case 90:
			sub_024D43(x);
			break;
		case 92:
			sub_024D61(x);
			break;
		case 94:
			sub_024D83(x);
			break;
		case 96:
			sub_024D98(x);
			break;
		case 98:
			sub_024DA6(x);
			break;
		case 100:
			sub_024DBF(x);
			break;
		case 102:
			sub_024DD7(&x, &y, &u);
			break;
		case 104:
			sub_024E10(&x, &y, &u);
			break;
		case 106:
			sub_024E6B();
			break;
		case 108:
			sub_024E87(&x, &y, &u);
			break;
		case 110:
			sub_024EBD(&x, &y, &u);
			break;
		case 112:
			sub_024F15(&x, &y, &u);
			break;
		case 114:
			sub_0251C9(&x, &y, &u);
			break;
		case 116:
			sub_025349(&x, &u);
			break;
		case 118:
			sub_0251F5();
			break;
		case 120:
			sub_0251F6(&x, &y, &u);
			break;
		case 122:
			sub_025297(&x, &y, &u);
			break;
		case 124:
			sub_025245(&x, &y, &u);
			break;
		case 126:
			sub_02527F(&x, &y, &u);
			break;
		case -26:
			sub_02402E();
			break;
		case -24:
			u = sub_02403A(u);
			break;
		case -22:
			x = sub_0240E3(x);
			break;
		case -20:
			sub_024113();
			break;
		case -18:
			x = sub_024125(x);
			break;
		case -14:
			sub_024188(&x, &y, &u);
			break;
		case -10:
			sub_024333(&x, &y, &u);
			break;
		case -8:
			y = sub_024363(x, y);
			break;
		case -6:
		case -4:
			sub_02439E(&x, &y, &u);
			break;
		case -2:
			sub_024409(&x, &u);
			break;
		}
		break;
	}
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

void sub_0241EC(uint16_t *p_x, uint16_t *p_y)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint8_t a = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	unk_48F0 = 1u;
	unk_48F1 = 0u;
	unk_48F2 = 0u;
	do
	{
		if ((unk_4885 & unk_48F0) != 0u)
		{
			d = (uint32_t)unk_48F1 << 8;
			y = sub_025388(x, d);
			mem_write8(y + 0x32u, unk_48F1);
			mem_write8(y + 0xAu, 0x30u);
			mem_write8(y + 0xBu, 0x30u);
			x = stage_end_exit_waits_ADDRESS;
			a = unk_48F2;
			mem_write8(y + 0x30u, a);
			mem_write8(y + VIDEO_0031, (uint8_t)(EXIT_SPEED(stage_end_exit_speeds_ADDRESS + (int8_t)a - 0x4u)->x_speed >> 8u));
			unk_48F2++;
		}
		unk_48F0 = (uint32_t)unk_48F0 << 1;
		unk_48F1++;
	} while (unk_48F1 != 4u);
	io_write16(VIDEO_18E2, 0xB0u);
	if (unk_4867 == 6u)
		io_write16(VIDEO_18E2, 0x140u);
	t1 = io_read8(VIDEO_18E1);
	io_write8(VIDEO_18E1, t1 + 1u);
	*p_x = x;
	*p_y = y;
}

void sub_02424B(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0, x = 0;
	uint8_t stack = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0, t5 = 0;
	uint16_t t1 = 0;

	t1 = io_read16(VIDEO_18E2);
	io_write16(VIDEO_18E2, t1 - 1u);
	if (t1 == 1u)
	{
		y = sub_078698();
		sub_07868C(&x, &u);
		t2 = io_read8(VIDEO_18E0);
		io_write8(VIDEO_18E0, t2 + 1u);
		t3 = io_read8(VIDEO_18E1);
		io_write8(VIDEO_18E1, 0u);
	}
	else
	{
		x = unk_4D40_ADDRESS;
		stack = 5u;
		do
		{
			u = loaded_table_02571E_ADDRESS;
			if (mem_read8(x) != 0u)
			{
				t4 = mem_read8(x + 1u);
				switch ((uint16_t)(u + (int8_t)((uint32_t)t4 << 1)))
				{
				case loaded_table_025700_ADDRESS:
					sub_02402E();
					break;
				case 0x7702u:
					u = sub_02403A(u);
					break;
				case 0x7704u:
					x = sub_0240E3(x);
					break;
				case 0x7706u:
					sub_024113();
					break;
				case 0x7708u:
					x = sub_024125(x);
					break;
				case loaded_table_02570A_ADDRESS:
				case loaded_table_025726_ADDRESS:
					sub_024155(&x, &y, &u);
					break;
				case 0x770Cu:
					sub_024188(&x, &y, &u);
					break;
				case 0x770Eu:
				case 0x772Au:
					sub_0241E2(&x, &y, &u);
					break;
				case 0x7710u:
					sub_024333(&x, &y, &u);
					break;
				case 0x7712u:
					y = sub_024363(x, y);
					break;
				case 0x7714u:
				case 0x7716u:
					sub_02439E(&x, &y, &u);
					break;
				case 0x7718u:
					sub_024409(&x, &u);
					break;
				case loaded_table_02571A_ADDRESS:
					sub_0241EC(&x, &y);
					break;
				case 0x771Cu:
					sub_02424B(&x, &y, &u);
					break;
				case loaded_table_02571E_ADDRESS:
					u = sub_02427E(x, u);
					break;
				case 0x7720u:
					sub_0242D0(x);
					break;
				case 0x7722u:
					sub_0242AC(x);
					break;
				case 0x7724u:
					sub_024329(x);
					break;
				case 0x7728u:
					sub_02441C(&x, &y, &u);
					break;
				case 0x772Cu:
					sub_02448F(&x, &y, &u);
					break;
				case 0x772Eu:
					sub_024532(&y, &u);
					break;
				case 0x7730u:
					sub_024557(&x, &y, &u);
					break;
				case loaded_table_025732_ADDRESS:
					sub_024571();
					break;
				case 0x7734u:
					sub_02457C(&y, &u);
					break;
				case 0x7736u:
					sub_0245A3(&x, &y, &u);
					break;
				case loaded_table_025738_ADDRESS:
					sub_0245D1(&x, &y, &u);
					break;
				case 0x773Au:
					sub_0245E1(&x, &y, &u);
					break;
				case 0x773Cu:
					sub_0245E8();
					break;
				case 0x773Eu:
					sub_0245F4(&x, &u);
					break;
				case loaded_table_025740_ADDRESS:
					sub_024616(&x, &y, &u);
					break;
				case 0x7742u:
					sub_024648(&x, &y, &u);
					break;
				case 0x7744u:
					sub_0246C3();
					break;
				case 0x7746u:
					sub_0246DF();
					break;
				case 0x7748u:
					sub_024723();
					break;
				case loaded_table_02574A_ADDRESS:
					sub_024741(&x, &y);
					break;
				case 0x774Cu:
					sub_024779();
					break;
				case 0x774Eu:
					sub_024799();
					break;
				case 0x7750u:
					sub_0247AA(&x, &y, &u);
					break;
				case loaded_table_025752_ADDRESS:
					sub_02482F();
					break;
				case 0x7754u:
					sub_024839(&x, &y, &u);
					break;
				case 0x7756u:
					sub_02488C(&x, &u);
					break;
				case 0x7758u:
					sub_0248F4();
					break;
				case loaded_table_02575A_ADDRESS:
					sub_024939(&x, &y, &u);
					break;
				case 0x775Cu:
					sub_02496D(&x, &y, &u);
					break;
				case 0x775Eu:
					y = sub_0249B6(x);
					break;
				case 0x7760u:
					sub_024A0B(&x, &y);
					break;
				case 0x7762u:
					sub_024AB0(&x, &u);
					break;
				case 0x7764u:
					sub_024AD3(&x, &u);
					break;
				case loaded_table_025766_ADDRESS:
					sub_024B3F(&x, &y, &u);
					break;
				case 0x7768u:
					sub_024B7E(&x, &y, &u);
					break;
				case 0x776Au:
					sub_024C30(&x, &y, &u);
					break;
				case 0x776Cu:
					sub_024CA6(&x, &y, &u);
					break;
				case 0x776Eu:
					x = sub_024CC2();
					break;
				case 0x7770u:
					sub_024CED(&x, &y, &u);
					break;
				case 0x7772u:
					sub_024D08(&x, &y, &u);
					break;
				case loaded_table_025774_ADDRESS:
					sub_024D43(x);
					break;
				case 0x7776u:
					sub_024D61(x);
					break;
				case 0x7778u:
					sub_024D83(x);
					break;
				case 0x777Au:
					sub_024D98(x);
					break;
				case 0x777Cu:
					sub_024DA6(x);
					break;
				case 0x777Eu:
					sub_024DBF(x);
					break;
				case loaded_table_025780_ADDRESS:
					sub_024DD7(&x, &y, &u);
					break;
				case 0x7782u:
					sub_024E10(&x, &y, &u);
					break;
				case 0x7784u:
					sub_024E6B();
					break;
				case 0x7786u:
					sub_024E87(&x, &y, &u);
					break;
				case 0x7788u:
					sub_024EBD(&x, &y, &u);
					break;
				case 0x778Au:
					sub_024F15(&x, &y, &u);
					break;
				case 0x778Cu:
					sub_0251C9(&x, &y, &u);
					break;
				case 0x778Eu:
					sub_025349(&x, &u);
					break;
				case loaded_table_025790_ADDRESS:
					sub_0251F5();
					break;
				case 0x7792u:
					sub_0251F6(&x, &y, &u);
					break;
				case 0x7794u:
					sub_025297(&x, &y, &u);
					break;
				case 0x7796u:
					sub_025245(&x, &y, &u);
					break;
				case 0x7798u:
					sub_02527F(&x, &y, &u);
					break;
				case loaded_table_02579A_ADDRESS:
					sub_0251FF(x);
					break;
				case 0x779Cu:
					sub_025208(x);
					break;
				}
			}
			x += 0x60u;
			t5 = stack;
			stack = t5 - 1u;
		} while (t5 != 1u);
	}
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

uint16_t sub_02427E(uint16_t x, uint16_t u)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, exit_speed = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t5 = 0, t7 = 0;
	uint16_t t4 = 0, t6 = 0, x_speed = 0, y_speed = 0;

	t1 = mem_read8(x + VIDEO_0031);
	a = t1;
	if (t1 != 0u)
	{
		t2 = mem_read8(x + VIDEO_0031);
		mem_write8(x + VIDEO_0031, t2 - 1u);
		return u;
	}
	t3 = mem_read8(x + 0x32u);
	b = t3;
	if (b != 4u)
	{
		t4 = (((uint32_t)a << 8) | b) + 0x3F28u;
		d = t4;
		carry = sub_078680(d);
	}
	t5 = mem_read8(x + 0x30u);
	t6 = stage_end_exit_speeds_ADDRESS + (int8_t)(((uint32_t)t5 << 1) << 1);
	exit_speed = t6 + 2u;
	x_speed = EXIT_SPEED(t6)->x_speed;
	mem_write16(x + 0xFu, x_speed);
	y_speed = EXIT_SPEED(exit_speed - 0x2u)->y_speed;
	mem_write16(x + 0x19u, y_speed);
	t7 = mem_read8(x + 1u);
	mem_write8(x + 1u, t7 + 1u);
	return exit_speed;
}

void sub_0242AC(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x33u);
	if (t1 == 0u)
	{
		sub_0242D0(x);
		return;
	}
	t2 = mem_read8(x + 0xAu);
	if (t2 < 0x80u)
	{
		sub_0242D0(x);
		return;
	}
	d = unk_4E00_ADDRESS;
	carry = sub_078680(d);
	mem_write8(x + 5u, 0x9Cu);
	mem_write8(x + 0xAu, 0x40u);
	mem_write8(x + 0xBu, 0x40u);
	t3 = mem_read8(x + 1u);
	mem_write8(x + 1u, t3 + 1u);
}

void sub_0242D0(uint16_t x)
{
	uint8_t a = 0, b = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;
	uint16_t t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0;

	t1 = mem_read8(x + 0xAu);
	t2 = t1;
	a = t2 + 2u;
	mem_write8(x + 0xAu, a);
	mem_write8(x + 0xBu, a);
	if ((uint8_t)(t2 + 2u) < t2)
	{
		t3 = mem_read8(x + 0x32u);
		a = 0x98u + t3;
		t4 = mem_read8(x + 0x32u);
		if (t4 == 4u)
			a = 0x8Eu;
		mem_write8(x + 5u, a);
		mem_write8(x + 0xAu, 0x40u);
		mem_write8(x + 0xBu, 0x40u);
		t5 = mem_read8(x + 0x33u);
		mem_write8(x + 0x33u, t5 + 1u);
		if (unk_4867 == 6u)
		{
			t6 = mem_read8(x + 1u);
			mem_write8(x + 1u, t6 + 1u);
		}
	}
	mem_write8(x, mem_read8(x) | 0x10u);
	t7 = mem_read16(x + 0xFu);
	t8 = t7;
	t9 = t8 - 8u;
	a = (uint8_t)(t9 >> 8);
	b = (uint8_t)t9;
	if (t8 < 8u)
	{
		a = 0u;
		b = 0u;
	}
	mem_write16(x + 0xFu, ((uint32_t)a << 8) | b);
	t10 = mem_read16(x + 0x19u);
	t11 = t10 + 0x16u;
	a = (uint8_t)(t11 >> 8);
	b = (uint8_t)t11;
	if ((int16_t)(((uint32_t)a << 8) | b) >= -0x10)
	{
		a = 0xFFu;
		b = 0xF0u;
	}
	mem_write16(x + 0x19u, ((uint32_t)a << 8) | b);
}

void sub_024329(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) != 0u)
		mem_write8(x, 0u);
}

void sub_024333(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t d = 0, u = 0, x = 0, y = 0;
	uint8_t t1 = 0;

	unk_4876 = 3u;
	io_write8(IO_1FB9, 0x3Fu);
	io_write8(IO_1FBA, 0x36u);
	d = 0x26u;
	sub_0786AD(d, &x, &y, &u);
	io_write8(IO_1FB9, 0x13u);
	io_write8(IO_1FBA, 0x2Cu);
	t1 = io_read8(VIDEO_18E0);
	io_write8(VIDEO_18E0, t1 + 1u);
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

uint16_t sub_024363(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	unk_48F0 = 1u;
	unk_48F1 = 0u;
	do
	{
		if ((unk_4885 & unk_48F0) != 0u)
		{
			d = (d & 0xFFu) | ((uint32_t)(uint8_t)(unk_48F1 + 4u) << 8);
			y = sub_025388(x, d);
			t1 = unk_48F1 + 0x3F28u;
			d = t1;
			carry = sub_078680(d);
		}
		unk_48F0 = (uint32_t)unk_48F0 << 1;
		unk_48F1++;
	} while (unk_48F1 != 4u);
	io_write16(VIDEO_18E2, 0x80u);
	t2 = io_read8(VIDEO_18E0);
	io_write8(VIDEO_18E0, t2 + 1u);
	return y;
}

void sub_02439E(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t d = 0;
	uint16_t stack = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0, t3 = 0, t4 = 0;

	t1 = io_read16(VIDEO_18E2);
	io_write16(VIDEO_18E2, t1 - 1u);
	if (t1 == 1u)
	{
		t2 = io_read8(VIDEO_18E0);
		io_write8(VIDEO_18E0, t2 + 1u);
		if (unk_4803 == 9u)
			sub_07868C(&x, &u);
		else
		{
			unk_487E = 4u;
			d = 0x1EE0u;
			sub_078677(d, &y, &u);
			io_write16(VIDEO_18E2, 0x100u);
		}
	}
	else
	{
		t3 = unk_48C5;
		t4 = t3 + 0x10u;
		unk_48C5 = t4;
		x = 0x4E60u;
		unk_48F0 = 1u;
		unk_48F1 = 0u;
		do
		{
			if ((unk_4885 & unk_48F0) != 0u)
			{
				stack = x;
				if (((stack + (uint8_t)unk_4815) & 0x40u) == 0u)
					mem_write16(x + 0xFu, 0xFF80u);
				else
					mem_write16(x + 0xFu, 0x80u);
			}
			x -= 0x60u;
			unk_48F0 = (uint32_t)unk_48F0 << 1;
			unk_48F1++;
		} while (unk_48F1 != 4u);
	}
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

void sub_024409(uint16_t *p_x, uint16_t *p_u)
{
	uint16_t u = 0, x = 0;

	unk_4872 = 0u;
	*p_x = x;
	*p_u = u;
	sub_07868C(p_x, p_u);
}

void sub_02441C(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, u_2 = 0, x_2 = 0, y_2 = 0;
	uint8_t t1 = 0;

	if (unk_485D != 0u)
		return;
	d = 0x7E00u;
	carry = sub_078680(d);
	d = 0x9A00u;
	carry = sub_078689(d);
	unk_487E = 2u;
	d = 0x10u;
	sub_078677(d, &ignored16, &u);
	io_write16(VIDEO_18E4, u);
	unk_487E = 2u;
	d = 0x11u;
	sub_078677(d, &ignored16, &u);
	io_write16(VIDEO_18E6, u);
	io_write8(IO_1FB9, 0x3Fu);
	io_write8(IO_1FBA, 0x36u);
	unk_4875 = 0x89u;
	unk_4876 = 1u;
	sub_0786B0();
	d = 0x26u;
	sub_0786AD(d, &ignored16_2, &ignored16, &ignored16_3);
	d = 0x126u;
	sub_0786AD(d, &x_2, &ignored16, &u_2);
	io_write8(IO_1FB9, 0x13u);
	io_write8(IO_1FBA, 0x2Cu);
	d = 0x826u;
	y_2 = sub_025388(x_2, d);
	t1 = io_read8(VIDEO_18E0);
	io_write8(VIDEO_18E0, t1 + 1u);
	*p_x = x_2;
	*p_y = y_2;
	*p_u = u_2;
}

void sub_02448F(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t x = 0, y = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = io_read16(VIDEO_18E4);
	mem_write8(t1, 0u);
	t2 = io_read16(VIDEO_18E6);
	mem_write8(t2, 0u);
	*p_x = x;
	*p_y = y;
	*p_u = u;
	sub_024497(p_x, p_y, p_u);
}

void sub_024497(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, u_2 = 0, x = 0, y = 0;
	uint8_t t1 = 0;

	unk_487E = 2u;
	d = 0x12u;
	sub_078677(d, &ignored16, &u);
	io_write16(VIDEO_18E4, u);
	unk_487E = 2u;
	d = 0x13u;
	sub_078677(d, &ignored16, &u);
	io_write16(VIDEO_18E6, u);
	unk_4876 = 3u;
	d = 0xFFF0u;
	sub_0786C2(d);
	d = 0u;
	sub_0786C5(d);
	io_write8(IO_1FB9, 0x3Fu);
	io_write8(IO_1FBA, 0x36u);
	d = 0x40u;
	sub_0786AD(d, &ignored16_2, &ignored16, &ignored16_3);
	d = 0x126u;
	sub_0786AD(d, &x, &y, &u_2);
	unk_48F0 = 0u;
	unk_48F1 = 1u;
	do
	{
		if ((unk_4885 & unk_48F1) != 0u)
		{
			d = (d & 0xFFu) | ((uint32_t)(uint8_t)(unk_48F0 + 9u) << 8);
			y = sub_025388(x, d);
			mem_write8(y + 9u, 0x20u);
		}
		else
		{
			d = (uint32_t)unk_48F0 << 8;
			sub_0253C9(d);
		}
		unk_48F1 = (uint32_t)unk_48F1 << 1;
		unk_48F0++;
	} while (unk_48F0 != 4u);
	io_write8(IO_1FB9, 0x13u);
	io_write8(IO_1FBA, 0x2Cu);
	io_write16(VIDEO_18E2, 0x40u);
	t1 = io_read8(VIDEO_18E0);
	io_write8(VIDEO_18E0, t1 + 1u);
	*p_x = x;
	*p_y = y;
	*p_u = u_2;
}

void sub_024532(uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t d = 0;
	uint8_t t4 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	t1 = io_read16(VIDEO_18E2);
	io_write16(VIDEO_18E2, t1 - 1u);
	if (t1 != 1u)
		return;
	t2 = io_read16(VIDEO_18E4);
	mem_write8(t2, 0u);
	t3 = io_read16(VIDEO_18E6);
	mem_write8(t3, 0u);
	unk_487E = 4u;
	d = 0x1EE0u;
	sub_078677(d, &y, &u);
	io_write16(VIDEO_18E2, 0xE0u);
	t4 = io_read8(VIDEO_18E0);
	io_write8(VIDEO_18E0, t4 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_024557(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t ignored16 = 0, u = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = io_read16(VIDEO_18E2);
	io_write16(VIDEO_18E2, t1 - 1u);
	if (t1 != 1u)
	{
		u = loaded_table_025996_ADDRESS;
		t2 = io_read8(VIDEO_18EC);
		switch ((int8_t)(uint8_t)((uint32_t)t2 << 1))
		{
		case 0:
			sub_025428(&x, &u);
			break;
		case 2:
			x = sub_025446();
			break;
		case 4:
			x = sub_025464();
			break;
		case 6:
			sub_025476();
			break;
		case 8:
			x = sub_025491();
			break;
		case 10:
			x = sub_0254A3();
			break;
		case 12:
			sub_0254BE();
			break;
		}
	}
	else
	{
		unk_4872 = 0u;
		sub_07868C(&ignored16, &u);
		sub_07868F(&x, &y);
	}
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

void sub_024571(void)
{
	uint8_t t1 = 0;

	io_write8(VIDEO_18E2, 0x80u);
	t1 = io_read8(VIDEO_18E0);
	io_write8(VIDEO_18E0, t1 + 1u);
}

void sub_02457C(uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = io_read8(VIDEO_18E2);
	io_write8(VIDEO_18E2, t1 - 1u);
	if (t1 != 1u)
		return;
	unk_487E = 5u;
	d = 0xEFFu;
	sub_078677(d, &y, &u);
	io_write16(VIDEO_18E4, u);
	d = 0xAB00u;
	carry = sub_078680(d);
	io_write16(VIDEO_18E2, 0x200u);
	t2 = io_read8(VIDEO_18E0);
	io_write8(VIDEO_18E0, t2 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_0245A3(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t u_2 = 0, x_2 = 0, y_2 = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = io_read16(VIDEO_18E2);
	io_write16(VIDEO_18E2, t1 - 1u);
	if (t1 != 1u)
		return;
	t2 = io_read16(VIDEO_18E4);
	mem_write8(t2, 0u);
	y_2 = VIDEO_18E0;
	x_2 = VIDEO_18E1;
	io_write8(VIDEO_18E0, 0u);
	u_2 = 0x1Fu;
	while (u_2 != 0u)
	{
		mem_write8(x_2, mem_read8(y_2));
		y_2++;
		x_2++;
		u_2--;
	}
	unk_4872 = 0u;
	*p_x = x_2;
	*p_y = y_2;
	*p_u = u_2;
}

void sub_0245D1(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t x = 0, y = 0;

	unk_4875 = 0x89u;
	unk_4876 = 1u;
	sub_0786B0();
	*p_x = x;
	*p_y = y;
	*p_u = u;
	sub_024155(p_x, p_y, p_u);
}

void sub_0245E1(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;

	if (unk_485D == 0u)
		sub_024497(&x, &y, &u);
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

void sub_0245E8(void)
{
	uint8_t t1 = 0;

	io_write16(VIDEO_18E2, VIDEO_00C0);
	t1 = io_read8(VIDEO_18E0);
	io_write8(VIDEO_18E0, t1 + 1u);
}

void sub_0245F4(uint16_t *p_x, uint16_t *p_u)
{
	uint16_t u = 0, x = 0;
	uint16_t t1 = 0, t2 = 0;

	u = sub_02546C();
	t1 = io_read16(VIDEO_18E2);
	io_write16(VIDEO_18E2, t1 - 1u);
	if (t1 == 1u)
		unk_4872 = 0u;
	x = VIDEO_2000;
	do
	{
		t2 = x - 1u;
		x = t2;
	} while (t2 != 0u);
	*p_x = x;
	*p_u = u;
}

void sub_024616(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, u_2 = 0, x = 0, y = 0;
	uint8_t t1 = 0;

	unk_487E = 1u;
	d = 0xE8Cu;
	sub_078677(d, &ignored16, &u);
	d = 0u;
	sub_078656(d);
	unk_48BE = 0x10u;
	unk_48CE = 0xFFF0u;
	unk_48C5 = 0x120u;
	unk_48D5 = 0u;
	sub_07868C(&ignored16_2, &u_2);
	sub_07868F(&x, &y);
	t1 = io_read8(VIDEO_18E0);
	io_write8(VIDEO_18E0, t1 + 1u);
	*p_x = x;
	*p_y = y;
	*p_u = u_2;
}

void sub_024648(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, u_2 = 0, x_2 = 0, y_2 = 0;
	uint8_t t1 = 0;

	if (unk_485D != 0u)
		return;
	d = 0xA000u;
	carry = sub_078689(d);
	d = 0x1300u;
	sub_025388(x, d);
	io_write8(IO_1FB9, 0x3Fu);
	io_write8(IO_1FBA, 0x36u);
	unk_4875 = 0x8Bu;
	unk_4876 = 2u;
	sub_0786B0();
	d = 0x26u;
	sub_0786AD(d, &ignored16_2, &ignored16, &ignored16_3);
	d = 0x126u;
	sub_0786AD(d, &x_2, &y_2, &u_2);
	unk_48F0 = 0u;
	unk_48F1 = 1u;
	do
	{
		if ((unk_4885 & unk_48F1) == 0u)
		{
			d = ((uint32_t)unk_48F0 << 8) | 1u;
			sub_0253C9(d);
		}
		unk_48F1 = (uint32_t)unk_48F1 << 1;
		unk_48F0++;
	} while (unk_48F0 != 4u);
	io_write8(IO_1FB9, 0x13u);
	io_write8(IO_1FBA, 0x2Cu);
	io_write16(VIDEO_18E2, 0x80u);
	t1 = io_read8(VIDEO_18E0);
	io_write8(VIDEO_18E0, t1 + 1u);
	*p_x = x_2;
	*p_y = y_2;
	*p_u = u_2;
}

void sub_0246C3(void)
{
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = io_read16(VIDEO_18E2);
	io_write16(VIDEO_18E2, t1 - 1u);
	if (t1 == 1u)
	{
		unk_48CA = 0u;
		unk_489D = 1u;
		unk_48A9 = 1u;
		unk_4899 = 1u;
		t2 = io_read8(VIDEO_18E0);
		io_write8(VIDEO_18E0, t2 + 1u);
	}
}

void sub_0246DF(void)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;
	uint32_t unk_48D5_halfword = 0;

	d = AT16(unk_48C5, -1);
	carry = (uint16_t)(d - 0x80u) < d;
	AT16(unk_48C5, -1) = d - 0x80u;
	unk_48C5 = (unk_48C5 & 0xFFu) | (((uint16_t)((uint32_t)(uint8_t)(((uint16_t)(int8_t)0xFFu >> 8) + (uint8_t)(unk_48C5 >> 8u) + carry) << 8) >> 8 & 0xFFu) << 8u);
	d = (((uint32_t)(unk_48D5 & 0xFFu) << 8u) | unk_48D7);
	carry = (uint16_t)(d + 0x40u) < d;
	unk_48D5_halfword = d + 0x40u;
	unk_48D5 = (unk_48D5 & 0xFF00u) | ((unk_48D5_halfword >> 8u) & 0xFFu);
	unk_48D7 = (uint8_t)unk_48D5_halfword;
	unk_48D5 = (unk_48D5 & 0xFFu) | (((uint16_t)((uint32_t)(uint8_t)(0u + (uint8_t)(unk_48D5 >> 8u) + carry) << 8) >> 8 & 0xFFu) << 8u);
	unk_4D54 = 0xFF80u;
	if ((int16_t)unk_48D5 >= 0x20)
	{
		unk_4D54 = 0u;
		io_write16(VIDEO_18E2, 0x60u);
		t1 = io_read8(VIDEO_18E0);
		io_write8(VIDEO_18E0, t1 + 1u);
	}
}

void sub_024723(void)
{
	uint16_t t1 = 0;

	t1 = io_read16(VIDEO_18E2);
	io_write16(VIDEO_18E2, t1 - 1u);
	if (t1 == 1u)
		unk_4872 = 0u;
}

void sub_024741(uint16_t *p_x, uint16_t *p_y)
{
	uint16_t d = 0, x = 0, y = 0;
	uint16_t stack = 0;
	uint8_t t3 = 0, t4 = 0;
	uint16_t t1 = 0, t2 = 0;
	uint32_t unk_48F0_halfword = 0;

	x = sub_0785FF();
	unk_48F0_halfword = 0x8CFu - unk_48AC;
	unk_48F0 = (uint8_t)(unk_48F0_halfword >> 8u);
	unk_48F1 = (uint8_t)unk_48F0_halfword;
	d = 0x1404u;
	do
	{
		stack = d;
		y = sub_025388(x, d);
		t1 = mem_read16(y + 0xCu);
		mem_write16(y + 0xCu, t1 + (((uint32_t)unk_48F0 << 8u) | unk_48F1));
		t2 = mem_read16(y + 0x16u);
		mem_write16(y + 0x16u, t2 + unk_48B2);
		mem_write16(y + 0x11u, 0xD8u);
		d = (stack & 0xFFu) | ((uint32_t)(uint8_t)((stack >> 8) + 1u) << 8);
		t3 = (uint8_t)d;
		d = (d & ~0xFFu) | (uint8_t)(t3 - 1u);
	} while (t3 != 1u);
	t4 = io_read8(VIDEO_18E0);
	io_write8(VIDEO_18E0, t4 + 1u);
	*p_x = x;
	*p_y = y;
}

void sub_024779(void)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	if ((int16_t)unk_48AC < 0x9B0)
		return;
	d = 0x7A00u;
	carry = sub_078680(d);
	t1 = io_read8(VIDEO_18E0);
	io_write8(VIDEO_18E0, t1 + 1u);
}

void unused_02478C(void)
{
	uint8_t t1 = 0;

	if ((int16_t)unk_48AC >= 0xA4F)
	{
		t1 = io_read8(VIDEO_18E0);
		io_write8(VIDEO_18E0, t1 + 1u);
	}
}

void sub_024799(void)
{
	uint8_t t1 = 0;

	if (unk_4881 != 0u)
	{
		io_write16(VIDEO_18E2, 0xFFFFu);
		t1 = io_read8(VIDEO_18E0);
		io_write8(VIDEO_18E0, t1 + 1u);
	}
}

void sub_0247AA(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t u_2 = 0, x = 0;
	uint8_t t8 = 0, t10 = 0, t14 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t9 = 0, t11 = 0, t12 = 0, t13 = 0;

	t1 = io_read16(VIDEO_18E2);
	io_write16(VIDEO_18E2, t1 - 1u);
	if (t1 == 1u)
	{
		y = VIDEO_18E0;
		x = VIDEO_18E1;
		io_write8(VIDEO_18E0, 0u);
		u_2 = 0x1Fu;
		while (u_2 != 0u)
		{
			mem_write8(x, mem_read8(y));
			y++;
			x++;
			u_2--;
		}
		sub_07868C(&x, &u);
		unk_4872 = 0u;
	}
	else
	{
		t2 = io_read16(VIDEO_18EB);
		t3 = t2 + 2u;
		io_write16(VIDEO_18EB, t3);
		t4 = (((uint32_t)(unk_48D5 & 0xFFu) << 8u) | unk_48D7);
		t5 = io_read16(VIDEO_18EB);
		t6 = t4;
		t7 = t6 + t5;
		carry = (uint16_t)(t6 + t5) < t6;
		unk_48D5 = (unk_48D5 & 0xFF00u) | ((t7 >> 8u) & 0xFFu);
		unk_48D7 = (uint8_t)t7;
		t8 = io_read8(VIDEO_18EB);
		unk_48D5 = (unk_48D5 & 0xFFu) | ((((uint16_t)(int8_t)t8 >> 8) + (uint8_t)(unk_48D5 >> 8u) + carry & 0xFFu) << 8u);
		x = unk_4D40_ADDRESS;
		unk_48F0 = 4u;
		do
		{
			t9 = io_read16(VIDEO_18EB);
			mem_write16(x + 0x19u, t9);
			x += 0x60u;
			t10 = unk_48F0;
			unk_48F0 = t10 - 1u;
		} while (t10 != 1u);
		t11 = unk_4E16;
		if ((int16_t)t11 >= 0x8F)
			unk_4E5B = 1u;
		t12 = ((((((uint8_t)unk_48D5 >> 1) >> 1) >> 1) + 0x1Cu) & 0x1Fu) * 0x40u;
		x = 0x3000u + t12;
		unk_48F0 = 0x40u;
		a = 0x10u;
		b = 0u;
		do
		{
			mem_write8(x - 0x2000u, b);
			t13 = x;
			x = t13 + 1u;
			mem_write8(t13, a);
			t14 = unk_48F0;
			unk_48F0 = t14 - 1u;
		} while (t14 != 1u);
	}
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

void sub_02482F(void)
{
	uint8_t t1 = 0;

	if (unk_4882 != 0u)
	{
		t1 = io_read8(VIDEO_18E1);
		io_write8(VIDEO_18E1, t1 + 1u);
	}
}

void sub_024839(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint32_t carry = 0;
	uint16_t d = 0, u = 0, x = 0, y = 0;
	uint16_t stack = 0;
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	io_write16(VIDEO_18EE, 0x808u);
	u = sub_024918();
	io_write16(0x18F0u, u);
	io_write16(VIDEO_18F2, u);
	unk_48FA = u;
	unk_48F0 = 6u;
	do
	{
		d = 0x2800u;
		y = sub_0248F8(u, d);
		stack = y;
		io_write16(unk_48FA + 0x2Au, y);
		unk_48FA = y;
		u = sub_024918();
		d = 0x2900u;
		y = sub_0248F8(u, d);
		mem_write16(stack + 0x28u, y);
		u = sub_024918();
		x = stack;
		t1 = unk_48F0;
		unk_48F0 = t1 - 1u;
	} while (t1 != 1u);
	t2 = io_read16(0x18F0u);
	mem_write16(x + 0x2Au, t2);
	d = 0x8300u;
	carry = sub_078680(d);
	t3 = io_read8(VIDEO_18E1);
	io_write8(VIDEO_18E1, t3 + 1u);
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

void sub_02488C(uint16_t *p_x, uint16_t *p_u)
{
	uint16_t d = 0, u = 0, x = 0;
	uint8_t t6 = 0, t7 = 0, t12 = 0, t13 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t14 = 0;

	t1 = io_read16(VIDEO_18F2);
	t2 = mem_read16(t1 + 0xCu);
	if ((uint16_t)(t2 - 0x40u + unk_48AC) == 0x9E8u)
	{
		t3 = io_read16(0x18F0u);
		x = t3;
		unk_48F0 = 6u;
		d = 0u;
		do
		{
			mem_write16(x + 0xFu, d);
			t4 = mem_read16(x + 0x28u);
			u = t4;
			mem_write16(u + 0xFu, d);
			t5 = mem_read16(x + 0x2Au);
			x = t5;
			t6 = unk_48F0;
			unk_48F0 = t6 - 1u;
		} while (t6 != 1u);
		t7 = io_read8(VIDEO_18E1);
		io_write8(VIDEO_18E1, t7 + 1u);
	}
	else
	{
		t8 = io_read16(0x18F0u);
		x = t8;
		t9 = mem_read16(x + 0xCu);
		t10 = io_read16(VIDEO_18EE);
		if ((uint16_t)(t9 - 0x40u + unk_48AC - t10) != 0x60u)
		{
			mem_write16(x + 0xFu, 0x200u);
			t11 = mem_read16(x + 0x28u);
			u = t11;
			mem_write16(u + 0xFu, 0x200u);
		}
		else
		{
			t12 = io_read8(VIDEO_18ED);
			io_write8(VIDEO_18ED, t12 + 1u);
			t13 = io_read8(VIDEO_18ED);
			if ((uint16_t)((uint32_t)t13 << 8) >> 8 == 6u)
			{
				t3 = io_read16(0x18F0u);
				x = t3;
				unk_48F0 = 6u;
				d = 0u;
				do
				{
					mem_write16(x + 0xFu, d);
					t4 = mem_read16(x + 0x28u);
					u = t4;
					mem_write16(u + 0xFu, d);
					t5 = mem_read16(x + 0x2Au);
					x = t5;
					t6 = unk_48F0;
					unk_48F0 = t6 - 1u;
				} while (t6 != 1u);
				t7 = io_read8(VIDEO_18E1);
				io_write8(VIDEO_18E1, t7 + 1u);
			}
			else
			{
				t14 = mem_read16(x + 0x2Au);
				x = t14;
				io_write16(0x18F0u, x);
				mem_write16(x + 0xFu, 0x200u);
				t11 = mem_read16(x + 0x28u);
				u = t11;
				mem_write16(u + 0xFu, 0x200u);
			}
		}
	}
	*p_x = x;
	*p_u = u;
}

void sub_0248F4(void)
{
	unk_4882 = 0u;
}

uint16_t sub_0248F8(uint16_t u, uint16_t d)
{
	uint16_t x = 0, y = 0;

	x = u;
	y = sub_025388(x, d);
	mem_write8(y + 1u, 0xF4u);
	mem_write16(y + 0xCu, 0x808u - unk_48AC + 0x40u);
	mem_write16(y + 0x11u, 0x90u + unk_48B2);
	return y;
}

uint16_t sub_024918(void)
{
	uint32_t carry = 0;
	uint8_t d = 0;
	uint16_t u = 0;

	d = 0u;
	sub_07867D(d, &u, &carry);
	if (carry == 0u)
	{
		d = 1u;
		sub_07867D(d, &u, &carry);
	}
	return u;
}

void sub_024939(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, u_2 = 0, x = 0, y = 0;
	uint8_t t1 = 0;

	d = 0u;
	sub_078656(d);
	d = 0u;
	sub_07869E(d);
	d = 0x7A00u;
	sub_07869E(d);
	unk_487E = 1u;
	d = 0xC8Cu;
	sub_078677(d, &ignored16, &u);
	d = 0xFFF0u;
	sub_0786C2(d);
	d = 0u;
	sub_0786C5(d);
	sub_07868C(&ignored16_2, &u_2);
	sub_07868F(&x, &y);
	t1 = io_read8(VIDEO_18E0);
	io_write8(VIDEO_18E0, t1 + 1u);
	*p_x = x;
	*p_y = y;
	*p_u = u_2;
}

void sub_02496D(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t d = 0, u_2 = 0, x_2 = 0, y_2 = 0;
	uint8_t t1 = 0;

	if (unk_485D != 0u)
		return;
	io_write8(IO_1FB9, 0x3Fu);
	io_write8(IO_1FBA, 0x36u);
	unk_4875 = 0x8Cu;
	unk_4876 = 1u;
	sub_0786B0();
	d = 0x126u;
	sub_0786AD(d, &x_2, &y_2, &u_2);
	io_write8(IO_1FB9, 0x13u);
	io_write8(IO_1FBA, 0x2Cu);
	unk_487E = 3u;
	d = 0x7A53u;
	sub_078677(d, &y_2, &u_2);
	t1 = io_read8(VIDEO_18E0);
	io_write8(VIDEO_18E0, t1 + 1u);
	*p_x = x_2;
	*p_y = y_2;
	*p_u = u_2;
}

uint16_t sub_0249B6(uint16_t x)
{
	uint8_t a = 0;
	uint16_t d = 0, y = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0, t2 = 0;

	d = 0x1800u;
	y = sub_025388(x, d);
	mem_write16(y + 0xFu, 0x200u);
	mem_write8(y + 0xAu, 0x40u);
	mem_write8(y + 0xBu, 0x40u);
	mem_write8(y + 9u, 0x40u);
	unk_48F0 = 4u;
	unk_48F1 = unk_4885;
	a = 0x19u;
	do
	{
		if ((unk_48F1 & 1u) != 0u)
		{
			stack = a;
			d = (uint32_t)a << 8;
			y = sub_025388(x, d);
			mem_write8(y + 0xAu, 0x40u);
			mem_write8(y + 0xBu, 0x40u);
			mem_write8(y + 9u, 0x40u);
			a = stack;
		}
		a++;
		unk_48F1 = unk_48F1 >> 1;
		t1 = unk_48F0;
		unk_48F0 = t1 - 1u;
	} while (t1 != 1u);
	io_write16(VIDEO_18E2, 0xF0u);
	t2 = io_read8(VIDEO_18E0);
	io_write8(VIDEO_18E0, t2 + 1u);
	return y;
}

void sub_024A0B(uint16_t *p_x, uint16_t *p_y)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t a = 0;
	uint16_t d = 0, x = 0;
	uint8_t stack = 0;
	uint8_t t4 = 0, t5 = 0, t7 = 0, t8 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t6 = 0;

	x = unk_4D40_ADDRESS;
	t1 = unk_4D4C;
	if ((int16_t)t1 >= 0xE0)
	{
		t2 = unk_4D59;
		t3 = t2 + 4u;
		unk_4D59 = t3;
		if ((unk_4815 & 3u) == 0u)
		{
			t4 = unk_4D4A;
			unk_4D4A = t4 + 1u;
			t5 = mem_read8(x + 0xBu);
			mem_write8(x + 0xBu, t5 + 1u);
		}
	}
	x = sub_024AEB();
	t6 = io_read16(VIDEO_18E2);
	io_write16(VIDEO_18E2, t6 - 1u);
	if (t6 != 1u)
		x = sub_024B01();
	else
	{
		d = VIDEO_1D00;
		y = sub_025388(x, d);
		mem_write16(y + 0xFu, 0xFF80u);
		mem_write16(y + 0xFu, 0xFF80u);
		mem_write16(y + 0x19u, 0x80u);
		mem_write8(y, mem_read8(y) | 0x10u);
		mem_write8(y + 9u, 0u);
		mem_write8(y + 0xAu, 0xC0u);
		mem_write8(y + 0xBu, 0xC0u);
		unk_48F0 = 4u;
		unk_48F1 = unk_4885;
		a = 0x1Eu;
		do
		{
			if ((unk_48F1 & 1u) != 0u)
			{
				stack = a;
				d = (uint32_t)a << 8;
				y = sub_025388(x, d);
				mem_write8(y, mem_read8(y) | 0x10u);
				mem_write8(y + 9u, 0u);
				mem_write8(y + 0xAu, 0xC0u);
				mem_write8(y + 0xBu, 0xC0u);
				a = stack;
			}
			a++;
			unk_48F1 = unk_48F1 >> 1;
			t7 = unk_48F0;
			unk_48F0 = t7 - 1u;
		} while (t7 != 1u);
		unk_4D49 = 0x20u;
		unk_4DA9 = 0x20u;
		unk_4E09 = 0x20u;
		unk_4E69 = 0x20u;
		unk_4EC9 = 0x20u;
		t8 = io_read8(VIDEO_18E0);
		io_write8(VIDEO_18E0, t8 + 1u);
		x = sub_024AEB();
	}
	*p_x = x;
	*p_y = y;
}

void sub_024AB0(uint16_t *p_x, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t d = 0, x = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = unk_4D59;
	d = t1 - 1u;
	if (t1 == 0u)
		d = 0u;
	unk_4D59 = d;
	if ((int16_t)unk_4D4C > 0x130)
		x = sub_024AEB();
	else
	{
		io_write16(VIDEO_18E2, 0x100u);
		t2 = io_read8(VIDEO_18E0);
		io_write8(VIDEO_18E0, t2 + 1u);
		sub_024AD3(&x, &u);
	}
	*p_x = x;
	*p_u = u;
}

void sub_024AD3(uint16_t *p_x, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t x = 0;
	uint16_t t1 = 0;

	unk_4D59--;
	t1 = io_read16(VIDEO_18E2);
	io_write16(VIDEO_18E2, t1 - 1u);
	if (t1 != 1u)
		x = sub_024AEB();
	else
	{
		sub_07868C(&x, &u);
		unk_4872 = 0u;
	}
	*p_x = x;
	*p_u = u;
}

uint16_t sub_024AEB(void)
{
	uint16_t x = 0;
	uint8_t t1 = 0;

	x = unk_4D40_ADDRESS;
	unk_48F0 = 5u;
	do
	{
		mem_write8(x, mem_read8(x) | 0x10u);
		x += 0x60u;
		t1 = unk_48F0;
		unk_48F0 = t1 - 1u;
	} while (t1 != 1u);
	return sub_024B01();
}

uint16_t sub_024B01(void)
{
	uint8_t a = 0;
	uint16_t x = 0;
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0;

	x = unk_4DA0_ADDRESS;
	unk_48F0 = 4u;
	do
	{
		t1 = unk_4D4F;
		mem_write16(x + 0xFu, t1);
		t2 = unk_4D59;
		mem_write16(x + 0x19u, t2);
		a = unk_4D4A;
		mem_write8(x + 0xAu, a);
		mem_write8(x + 0xBu, a);
		x += 0x60u;
		t3 = unk_48F0;
		unk_48F0 = t3 - 1u;
	} while (t3 != 1u);
	return x;
}

void sub_024B3F(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, u_2 = 0, x = 0, y = 0;
	uint8_t t1 = 0;

	d = 0u;
	sub_078656(d);
	d = 0u;
	sub_07869E(d);
	unk_487E = 1u;
	d = 0xE91u;
	sub_078677(d, &ignored16, &u);
	d = 0xFFF0u;
	sub_0786C2(d);
	d = 0u;
	unk_48CE = 0u;
	sub_0786C5(d);
	unk_48D5 = 0x100u;
	unk_48AA = 1u;
	unk_489D = 1u;
	sub_07868C(&ignored16_2, &u_2);
	sub_07868F(&x, &y);
	t1 = io_read8(VIDEO_18E0);
	io_write8(VIDEO_18E0, t1 + 1u);
	*p_x = x;
	*p_y = y;
	*p_u = u_2;
}

void sub_024B7E(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, u_2 = 0, x_2 = 0, y_2 = 0;
	uint8_t t1 = 0, t2 = 0;

	if (unk_485D != 0u)
		return;
	io_write8(IO_1FB9, 0x3Fu);
	io_write8(IO_1FBA, 0x36u);
	unk_4875 = 0x8Du;
	unk_4876 = 0u;
	sub_0786B0();
	d = 0x26u;
	sub_0786AD(d, &ignored16, &ignored16_2, &ignored16_3);
	d = 0x126u;
	sub_0786AD(d, &x_2, &ignored16_2, &u_2);
	io_write8(IO_1FB9, 0x13u);
	io_write8(IO_1FBA, 0x2Cu);
	d = 0x2E26u;
	sub_025388(x_2, d);
	d = 0x2F26u;
	sub_025388(x_2, d);
	d = 0x3026u;
	y_2 = sub_025388(x_2, d);
	mem_write8(y_2, mem_read8(y_2) | 8u);
	mem_write8(y_2 + 0x5Bu, 1u);
	d = 0x3126u;
	sub_025388(x_2, d);
	d = 0x3226u;
	y_2 = sub_025388(x_2, d);
	mem_write8(y_2 + 9u, 0x10u);
	unk_48F0 = 4u;
	unk_48F1 = unk_4885;
	unk_48F2 = 0x2Au;
	do
	{
		if ((unk_48F1 & 1u) != 0u)
		{
			d = (d & 0xFFu) | ((uint32_t)unk_48F2 << 8);
			y_2 = sub_025388(x_2, d);
			mem_write8(y_2, mem_read8(y_2) | 8u);
			mem_write8(y_2 + 0x28u, unk_48F0 * 0x10u + 0x10u);
		}
		unk_48F1 = unk_48F1 >> 1;
		unk_48F2++;
		t1 = unk_48F0;
		unk_48F0 = t1 - 1u;
	} while (t1 != 1u);
	d = 0x9600u;
	carry = sub_078680(d);
	io_write16(VIDEO_18EB, 0x400u);
	t2 = io_read8(VIDEO_18E0);
	io_write8(VIDEO_18E0, t2 + 1u);
	*p_x = x_2;
	*p_y = y_2;
	*p_u = u_2;
}

void sub_024C30(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, x = 0;
	uint8_t t3 = 0, t5 = 0;
	uint16_t t1 = 0, t2 = 0, t4 = 0;
	uint32_t unk_48D5_halfword = 0;

	sub_024D26(&ignored16, &y, &u);
	t1 = io_read16(VIDEO_18EB);
	d = t1 - 9u;
	if ((int16_t)d <= 9)
		d = 9u;
	io_write16(VIDEO_18EB, d);
	d = (((uint32_t)(unk_48D5 & 0xFFu) << 8u) | unk_48D7);
	t2 = io_read16(VIDEO_18EB);
	carry = d < t2;
	unk_48D5_halfword = d - t2;
	unk_48D5 = (unk_48D5 & 0xFF00u) | ((unk_48D5_halfword >> 8u) & 0xFFu);
	unk_48D7 = (uint8_t)unk_48D5_halfword;
	unk_48D5 = (unk_48D5 & 0xFFu) | (((uint16_t)((uint32_t)(uint8_t)(((uint16_t)((uint32_t)(uint8_t)(unk_48D5 >> 8u) << 8) >> 8) - carry) << 8) >> 8 & 0xFFu) << 8u);
	if ((int16_t)unk_48D5 <= 0x20)
	{
		unk_5404 = 0x9Cu;
		unk_5405 = 0x83u;
		unk_540F = 0x300u;
		unk_5419 = 0x200u;
		io_write16(VIDEO_18E2, 0x80u);
		unk_48D5 = 0x20u;
		unk_48D7 = 0u;
		t3 = io_read8(VIDEO_18E0);
		io_write8(VIDEO_18E0, t3 + 1u);
	}
	x = 0x5400u;
	unk_48F0 = 4u;
	do
	{
		t4 = io_read16(VIDEO_18EB);
		mem_write16(x + 0x19u, 0u - t4);
		x += 0x60u;
		t5 = unk_48F0;
		unk_48F0 = t5 - 1u;
	} while (t5 != 1u);
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

void sub_024CA6(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint8_t a = 0, d = 0;
	uint16_t x = 0;
	uint8_t t1 = 0, t2 = 0;

	x = 0x5460u;
	unk_48F0 = 3u;
	d = 0u;
	a = 0u;
	do
	{
		mem_write16(x + 0x19u, (uint32_t)a << 8);
		x += 0x60u;
		t1 = unk_48F0;
		unk_48F0 = t1 - 1u;
	} while (t1 != 1u);
	sub_024D26(&x, &y, &u);
	t2 = io_read8(VIDEO_18E0);
	io_write8(VIDEO_18E0, t2 + 1u);
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

uint16_t sub_024CC2(void)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, x = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	x = 0x5400u;
	sub_0785B1(x, &ignored16, &carry);
	t1 = mem_read16(x + 0x16u);
	if ((int16_t)t1 > 0x38)
		return x;
	unk_5405 = 0x81u;
	unk_5419 = 0u;
	d = 0x6000u;
	carry = sub_078680(d);
	unk_5580 = 0u;
	unk_5405 = 0x81u;
	t2 = io_read8(VIDEO_18E0);
	io_write8(VIDEO_18E0, t2 + 1u);
	return x;
}

void sub_024CED(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t ignored16 = 0, x = 0;
	uint8_t t1 = 0;

	sub_024D26(&ignored16, &y, &u);
	x = 0x5400u;
	if ((int16_t)unk_540C >= 0x150)
	{
		io_write16(VIDEO_18E2, 0x80u);
		mem_write8(x, 0u);
		t1 = io_read8(VIDEO_18E0);
		io_write8(VIDEO_18E0, t1 + 1u);
	}
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

void sub_024D08(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t x = 0;
	uint16_t t1 = 0;

	t1 = io_read16(VIDEO_18E2);
	io_write16(VIDEO_18E2, t1 - 1u);
	if (t1 != 1u)
		sub_024D26(&x, &y, &u);
	else
		sub_024D0E(&x, &y, &u);
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

void sub_024D0E(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint32_t carry = 0;
	uint16_t d = 0, u = 0, x = 0, y = 0;

	y = VIDEO_18E0;
	x = VIDEO_18E1;
	io_write8(VIDEO_18E0, 0u);
	u = 0x1Fu;
	while (u != 0u)
	{
		mem_write8(x, mem_read8(y));
		y++;
		x++;
		u--;
	}
	d = 0u;
	carry = sub_078680(d);
	sub_07868C(&x, &u);
	unk_4872 = 0u;
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

void sub_024D26(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t x = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0, t2 = 0;

	stack = 4u;
	x = 0x5280u;
	do
	{
		if ((int8_t)mem_read8(x) < 0)
		{
			u = loaded_table_025774_ADDRESS;
			t1 = mem_read8(x + 2u);
			switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
			{
			case 0:
				sub_024D43(x);
				break;
			case 2:
				sub_024D61(x);
				break;
			case 4:
				sub_024D83(x);
				break;
			case 6:
				sub_024D98(x);
				break;
			case 8:
				sub_024DA6(x);
				break;
			case 10:
				sub_024DBF(x);
				break;
			case 12:
				sub_024DD7(&x, &y, &u);
				break;
			case 14:
				sub_024E10(&x, &y, &u);
				break;
			case 16:
				sub_024E6B();
				break;
			case 18:
				sub_024E87(&x, &y, &u);
				break;
			case 20:
				sub_024EBD(&x, &y, &u);
				break;
			case 22:
				sub_024F15(&x, &y, &u);
				break;
			case 24:
				sub_0251C9(&x, &y, &u);
				break;
			case 26:
				sub_025349(&x, &u);
				break;
			case 28:
				sub_0251F5();
				break;
			case 30:
				sub_0251F6(&x, &y, &u);
				break;
			case 32:
				sub_025297(&x, &y, &u);
				break;
			case 34:
				sub_025245(&x, &y, &u);
				break;
			case 36:
				sub_02527F(&x, &y, &u);
				break;
			case 38:
			case 46:
			case 54:
				sub_0251FF(x);
				break;
			case 40:
				sub_025208(x);
				break;
			case 42:
				sub_02521C(x);
				break;
			case 44:
			case 52:
			case 60:
				sub_025244();
				break;
			case 48:
				sub_02524E(x);
				break;
			case 50:
			case 58:
				sub_02525D(x);
				break;
			case 56:
				sub_025288(x);
				break;
			case 62:
				sub_0252A0(x);
				break;
			case 64:
				sub_0252A9(x);
				break;
			case 66:
				sub_0252B9(x);
				break;
			case 68:
				sub_0252DB();
				break;
			case -116:
				sub_02402E();
				break;
			case -114:
				u = sub_02403A(u);
				break;
			case -112:
				x = sub_0240E3(x);
				break;
			case -110:
				sub_024113();
				break;
			case -108:
				x = sub_024125(x);
				break;
			case -106:
			case -78:
				sub_024155(&x, &y, &u);
				break;
			case -104:
				sub_024188(&x, &y, &u);
				break;
			case -102:
			case -74:
				sub_0241E2(&x, &y, &u);
				break;
			case -100:
				sub_024333(&x, &y, &u);
				break;
			case -98:
				y = sub_024363(x, y);
				break;
			case -96:
			case -94:
				sub_02439E(&x, &y, &u);
				break;
			case -92:
				sub_024409(&x, &u);
				break;
			case -90:
				sub_0241EC(&x, &y);
				break;
			case -88:
				sub_02424B(&x, &y, &u);
				break;
			case -86:
				u = sub_02427E(x, u);
				break;
			case -84:
				sub_0242D0(x);
				break;
			case -82:
				sub_0242AC(x);
				break;
			case -80:
				sub_024329(x);
				break;
			case -76:
				sub_02441C(&x, &y, &u);
				break;
			case -72:
				sub_02448F(&x, &y, &u);
				break;
			case -70:
				sub_024532(&y, &u);
				break;
			case -68:
				sub_024557(&x, &y, &u);
				break;
			case -66:
				sub_024571();
				break;
			case -64:
				sub_02457C(&y, &u);
				break;
			case -62:
				sub_0245A3(&x, &y, &u);
				break;
			case -60:
				sub_0245D1(&x, &y, &u);
				break;
			case -58:
				sub_0245E1(&x, &y, &u);
				break;
			case -56:
				sub_0245E8();
				break;
			case -54:
				sub_0245F4(&x, &u);
				break;
			case -52:
				sub_024616(&x, &y, &u);
				break;
			case -50:
				sub_024648(&x, &y, &u);
				break;
			case -48:
				sub_0246C3();
				break;
			case -46:
				sub_0246DF();
				break;
			case -44:
				sub_024723();
				break;
			case -42:
				sub_024741(&x, &y);
				break;
			case -40:
				sub_024779();
				break;
			case -38:
				sub_024799();
				break;
			case -36:
				sub_0247AA(&x, &y, &u);
				break;
			case -34:
				sub_02482F();
				break;
			case -32:
				sub_024839(&x, &y, &u);
				break;
			case -30:
				sub_02488C(&x, &u);
				break;
			case -28:
				sub_0248F4();
				break;
			case -26:
				sub_024939(&x, &y, &u);
				break;
			case -24:
				sub_02496D(&x, &y, &u);
				break;
			case -22:
				y = sub_0249B6(x);
				break;
			case -20:
				sub_024A0B(&x, &y);
				break;
			case -18:
				sub_024AB0(&x, &u);
				break;
			case -16:
				sub_024AD3(&x, &u);
				break;
			case -14:
				sub_024B3F(&x, &y, &u);
				break;
			case -12:
				sub_024B7E(&x, &y, &u);
				break;
			case -10:
				sub_024C30(&x, &y, &u);
				break;
			case -8:
				sub_024CA6(&x, &y, &u);
				break;
			case -6:
				x = sub_024CC2();
				break;
			case -4:
				sub_024CED(&x, &y, &u);
				break;
			case -2:
				sub_024D08(&x, &y, &u);
				break;
			}
		}
		x += 0x60u;
		t2 = stack;
		stack = t2 - 1u;
	} while (t2 != 1u);
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

void sub_024D43(uint16_t x)
{
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = mem_read16(x + 0x16u);
	if ((int16_t)t1 > 0xBF)
	{
		t2 = io_read16(VIDEO_18EB);
		mem_write16(x + 0x19u, 0u - t2);
		return;
	}
	mem_write8(x + 5u, 0x97u);
	mem_write16(x + 0x19u, 0u);
	t3 = mem_read8(x + 2u);
	mem_write8(x + 2u, t3 + 1u);
}

void sub_024D61(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0;
	uint8_t t2 = 0, t4 = 0;
	uint16_t t1 = 0, t3 = 0;

	sub_0785B1(x, &ignored16, &carry);
	t1 = mem_read16(x + 0x16u);
	if ((int16_t)t1 > 0x38)
		return;
	mem_write8(x + 5u, 0xD4u);
	mem_write16(x + 0x19u, 0u);
	t2 = mem_read8(x + 4u);
	t3 = t2 + 0x3F24u;
	d = t3;
	carry = sub_078680(d);
	t4 = mem_read8(x + 2u);
	mem_write8(x + 2u, t4 + 1u);
}

void sub_024D83(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 7u);
	if (t1 == 3u)
	{
		mem_write8(x + 5u, 0xDFu);
		mem_write8(x + 0x29u, 0x60u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_024D98(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 5u, 0xDCu);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_024DA6(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) != 0u)
	{
		mem_write8(x + 5u, 0x81u);
		mem_write16(x + 0xFu, 0x300u);
		mem_write8(x + 9u, 0u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_024DBF(uint16_t x)
{
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0xCu);
	if ((int16_t)t1 >= 0x150)
		mem_write8(x, 0u);
}

void sub_024DD7(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, u = 0, x = 0, y = 0;
	uint8_t t1 = 0;

	d = 0u;
	sub_078656(d);
	d = 0u;
	sub_07869E(d);
	y = VIDEO_3C00;
	x = 0x3C01u;
	io_write8(VIDEO_3C00, 0u);
	u = 0x1FFu;
	while (u != 0u)
	{
		mem_write8(x, mem_read8(y));
		y++;
		x++;
		u--;
	}
	unk_487E = 1u;
	d = 0xE8Fu;
	sub_078677(d, &ignored16, &u);
	d = 0xFFF0u;
	sub_0786C2(d);
	d = 0u;
	sub_0786C5(d);
	sub_07868C(&ignored16_2, &u);
	sub_07868F(&x, &y);
	t1 = io_read8(VIDEO_18E0);
	io_write8(VIDEO_18E0, t1 + 1u);
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

void sub_024E10(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, u_2 = 0, x_2 = 0, y_2 = 0;
	uint8_t t1 = 0;

	if (unk_485D != 0u)
		return;
	io_write8(IO_1FB9, 0x3Fu);
	io_write8(IO_1FBA, 0x36u);
	unk_4875 = 0x8Du;
	unk_4876 = 2u;
	sub_0786B0();
	d = 0x26u;
	sub_0786AD(d, &ignored16, &ignored16_2, &ignored16_3);
	d = 0x126u;
	sub_0786AD(d, &x_2, &ignored16_2, &u_2);
	d = 0x2326u;
	y_2 = sub_025388(x_2, d);
	mem_write8(y_2 + 9u, 0x10u);
	io_write8(IO_1FB9, 0x13u);
	io_write8(IO_1FBA, 0x2Cu);
	d = 0x9600u;
	carry = sub_078680(d);
	io_write16(VIDEO_18E2, 0x30u);
	t1 = io_read8(VIDEO_18E0);
	io_write8(VIDEO_18E0, t1 + 1u);
	*p_x = x_2;
	*p_y = y_2;
	*p_u = u_2;
}

void sub_024E6B(void)
{
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	unk_4D46 |= 0x40u;
	t1 = io_read16(VIDEO_18E2);
	io_write16(VIDEO_18E2, t1 - 1u);
	if (t1 == 1u)
	{
		io_write16(VIDEO_18E2, 0x60u);
		t2 = io_read8(VIDEO_18E0);
		io_write8(VIDEO_18E0, t2 + 1u);
	}
}

void sub_024E87(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, u = 0, x = 0, y = 0;
	uint8_t t1 = 0;

	io_write8(IO_1FB9, 0x3Fu);
	io_write8(IO_1FBA, 0x36u);
	unk_48CE = 0x120u;
	unk_48D1 = 0x120u;
	unk_48D3 = 0u;
	d = 0x126u;
	sub_0786AD(d, &ignored16, &y, &ignored16_2);
	sub_07868C(&ignored16, &u);
	io_write16(VIDEO_18E2, 0x60u);
	x = sub_0785FF();
	t1 = io_read8(VIDEO_18E0);
	io_write8(VIDEO_18E0, t1 + 1u);
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

void sub_024EBD(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, u_2 = 0, x_2 = 0, y_2 = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	io_write8(IO_1FB9, 0x13u);
	io_write8(IO_1FBA, 0x2Cu);
	t1 = io_read16(VIDEO_18E2);
	io_write16(VIDEO_18E2, t1 - 1u);
	if (t1 != 1u)
		return;
	io_write8(IO_1FB9, 0x3Fu);
	io_write8(IO_1FBA, 0x36u);
	unk_48CE = 0xFFF0u;
	unk_48D1 = 0xFFF0u;
	unk_48D3 = 0u;
	d = 0x126u;
	sub_0786AD(d, &ignored16, &ignored16_2, &ignored16_3);
	sub_07868C(&x_2, &u_2);
	d = 0x2426u;
	sub_025388(x_2, d);
	d = 0x2526u;
	sub_025388(x_2, d);
	d = 0x2626u;
	y_2 = sub_025388(x_2, d);
	io_write16(VIDEO_18E2, 0x100u);
	t2 = io_read8(VIDEO_18E0);
	io_write8(VIDEO_18E0, t2 + 1u);
	*p_x = x_2;
	*p_y = y_2;
	*p_u = u_2;
}

void sub_024F15(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, u_2 = 0, x_2 = 0, y_2 = 0;
	uint8_t t4 = 0, t5 = 0, t6 = 0, t15 = 0, t16 = 0, t27 = 0, t36 = 0, t49 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0, t17 = 0, t18 = 0, t19 = 0, t20 = 0, t21 = 0, t22 = 0, t23 = 0, t24 = 0, t25 = 0, t26 = 0, t28 = 0, t29 = 0, t30 = 0, t31 = 0, t32 = 0, t33 = 0, t34 = 0, t35 = 0, t37 = 0, t38 = 0, t39 = 0, t40 = 0, t41 = 0, t42 = 0, t43 = 0, t44 = 0, t45 = 0, t46 = 0, t47 = 0, t48 = 0;

	io_write8(IO_1FB9, 0x13u);
	io_write8(IO_1FBA, 0x2Cu);
	t1 = io_read16(VIDEO_18E2);
	io_write16(VIDEO_18E2, t1 - 1u);
	if (t1 != 1u)
	{
		b = 0u;
		if ((unk_4815 & 0x20u) != 0u)
			b = 0x80u;
		unk_4DA0 = b;
		unk_4DA6 = b;
		if ((unk_4815 & 0x1Fu) != 0u)
			return;
		d = 0x4500u;
		carry = sub_078680(d);
		return;
	}
	sub_0785FF();
	t2 = io_read16(VIDEO_18F8);
	a = (uint8_t)(t2 >> 8);
	b = (uint8_t)t2;
	unk_48BE = ((uint32_t)a << 8) | b;
	unk_48CE = ((uint32_t)a << 8) | b;
	t3 = io_read16(VIDEO_18FA);
	a = (uint8_t)(t3 >> 8);
	b = (uint8_t)t3;
	unk_48C5 = ((uint32_t)a << 8) | b;
	unk_48D5 = ((uint32_t)a << 8) | b;
	unk_487E = 1u;
	d = 0x880u;
	sub_078677(d, &ignored16_2, &u);
	unk_487E = 1u;
	d = 0xF8Eu;
	sub_078677(d, &ignored16_2, &u);
	io_write8(IO_1FB9, 0x3Fu);
	io_write8(IO_1FBA, 0x36u);
	unk_4875 = 0x8Du;
	unk_4876 = 1u;
	sub_0786B0();
	d = 0x2Cu;
	sub_0786AD(d, &ignored16, &ignored16_2, &u_2);
	y_2 = sub_078698();
	io_write8(IO_1FB9, 0x13u);
	io_write8(IO_1FBA, 0x2Cu);
	t4 = io_read8(VIDEO_18FC);
	t5 = (((t4 >> 1) >> 1) >> 1) >> 1;
	a = t5;
	if (t5 != 0u)
	{
		b = 1u;
		while (a != 0u)
		{
			b = (uint32_t)b << 1;
			a--;
		}
		io_write8(VIDEO_18FC, b);
	}
	else
	{
		a = unk_4885;
		unk_48F0 = 1u;
		b = 4u;
		do
		{
			if ((a & unk_48F0) != 0u)
				break;
			unk_48F0 = (uint32_t)unk_48F0 << 1;
			t6 = b;
			b = t6 - 1u;
		} while (t6 != 1u);
		io_write8(VIDEO_18FC, a & unk_48F0);
	}
	unk_48F0 = 0u;
	unk_48F1 = unk_4885;
	unk_48F8 = 0x60u;
	unk_48FA = 0xFE80u;
	unk_48FC = 0xFFE0u;
	x_2 = 0x5280u;
	do
	{
		if ((unk_48F1 & 1u) == 0u)
		{
			mem_write8(x_2, 0x80u);
			mem_write16(x_2 + 4u, ((uint32_t)unk_48F0 << 8) | 0x80u);
			t7 = io_read16(VIDEO_18F4);
			t8 = t7 + unk_48FA;
			mem_write16(x_2 + 0xCu, t8);
			t9 = io_read16(VIDEO_18F6);
			t10 = t9 - 0x10u;
			mem_write16(x_2 + 0x11u, t10);
			t11 = unk_48FA;
			t12 = t11 - 0x20u;
			unk_48FA = t12;
			t13 = unk_48FC;
			t14 = t13 + 0x20u;
			a = (uint8_t)(t14 >> 8);
			b = (uint8_t)t14;
			unk_48FC = ((uint32_t)a << 8) | b;
			mem_write16(x_2 + 0x2Bu, ((uint32_t)a << 8) | b);
			mem_write8(x_2 + 1u, 0xF4u);
			mem_write8(x_2 + 2u, 1u);
		}
		else
		{
			t15 = io_read8(VIDEO_18FC);
			if ((t15 & 1u) != 0u)
			{
				t16 = io_read8(VIDEO_18FC);
				io_write8(VIDEO_18FC, 0u);
				mem_write8(x_2, 0x80u);
				mem_write16(x_2 + 4u, ((uint32_t)unk_48F0 << 8) | 0x80u);
				t17 = io_read16(VIDEO_18F4);
				t18 = t17 + 0x70u;
				mem_write16(x_2 + 0xCu, t18);
				t19 = io_read16(VIDEO_18F6);
				t20 = t19 - 0xEu;
				mem_write16(x_2 + 0x11u, t20);
				mem_write8(x_2 + 9u, 0x40u);
				mem_write8(x_2 + 1u, 0xF4u);
				mem_write8(x_2 + 2u, 2u);
			}
			else
			{
				mem_write8(x_2, 0x80u);
				mem_write16(x_2 + 4u, ((uint32_t)unk_48F0 << 8) | 0x9Eu);
				t21 = io_read16(VIDEO_18F4);
				t22 = t21 + unk_48F8;
				mem_write16(x_2 + 0xCu, t22);
				t23 = io_read16(VIDEO_18F6);
				t24 = t23 + 0x10u;
				mem_write16(x_2 + 0x11u, t24);
				t25 = unk_48F8;
				t26 = t25 - 0x20u;
				unk_48F8 = t26;
				mem_write8(x_2 + 9u, 0x40u);
				mem_write8(x_2 + 1u, 0xF4u);
				mem_write8(x_2 + 2u, 0u);
			}
		}
		mem_write8(x_2 + 0x2Du, unk_48F0);
		x_2 += 0x60u;
		t27 = io_read8(VIDEO_18FC);
		io_write8(VIDEO_18FC, t27 >> 1);
		unk_48F1 = unk_48F1 >> 1;
		unk_48F0++;
	} while (unk_48F0 != 4u);
	if ((unk_4885 & 0xFu) == 0xFu)
	{
		unk_48F0 = 0x81u;
		unk_48F1 = 2u;
		unk_48FC = 0u;
		unk_48FA = 0xFE80u;
		do
		{
			mem_write8(x_2, 0x80u);
			mem_write16(x_2 + 4u, 0xC900u | unk_48F0);
			unk_48F0++;
			unk_48F0++;
			t28 = io_read16(VIDEO_18F4);
			t29 = t28 + unk_48FA;
			mem_write16(x_2 + 0xCu, t29);
			t30 = io_read16(VIDEO_18F6);
			t31 = t30 + 0x10u;
			mem_write16(x_2 + 0x11u, t31);
			t32 = unk_48FA;
			t33 = t32 - 0x20u;
			unk_48FA = t33;
			t34 = unk_48FC;
			t35 = t34 + 0x20u;
			a = (uint8_t)(t35 >> 8);
			b = (uint8_t)t35;
			unk_48FC = ((uint32_t)a << 8) | b;
			mem_write16(x_2 + 0x2Bu, ((uint32_t)a << 8) | b);
			mem_write8(x_2 + 1u, 0xF4u);
			mem_write8(x_2 + 2u, 3u);
			x_2 += 0x60u;
			t36 = unk_48F1;
			unk_48F1 = t36 - 1u;
		} while (t36 != 1u);
		mem_write8(x_2, 0x80u);
		mem_write16(x_2 + 4u, 0xCA81u);
		t37 = io_read16(VIDEO_18F4);
		t38 = t37 - 0x180u;
		mem_write16(x_2 + 0xCu, t38);
		t39 = io_read16(VIDEO_18F6);
		t40 = t39 + 0x10u;
		mem_write16(x_2 + 0x11u, t40);
		t41 = unk_48FC;
		t42 = t41 + 0x20u;
		mem_write16(x_2 + 0x2Bu, t42);
		mem_write8(x_2 + 1u, 0xF4u);
		mem_write8(x_2 + 2u, 4u);
	}
	unk_5520 = 0x80u;
	unk_5524 = 0x1186u;
	unk_5529 = 0x40u;
	t43 = io_read16(VIDEO_18F4);
	t44 = t43 + 0x60u;
	unk_552C = t44;
	t45 = io_read16(VIDEO_18F6);
	t46 = t45 - 0x10u;
	unk_5531 = t46;
	unk_5521 = 0xF4u;
	x_2 = unk_5580_ADDRESS;
	unk_5580 = 0x80u;
	unk_5584 = 0xD383u;
	unk_5589 = 0x40u;
	t47 = io_read16(VIDEO_18F4);
	unk_558C = t47;
	t48 = io_read16(VIDEO_18F6);
	unk_5591 = t48;
	unk_5581 = 0xF4u;
	io_write16(VIDEO_18E2, 0x1C0u);
	t49 = io_read8(VIDEO_18E0);
	io_write8(VIDEO_18E0, t49 + 1u);
	*p_x = x_2;
	*p_y = y_2;
	*p_u = u_2;
}

void sub_0251C9(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, u_2 = 0, x = 0;
	uint8_t stack = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0;
	uint16_t t1 = 0;

	t1 = io_read16(VIDEO_18E2);
	io_write16(VIDEO_18E2, t1 - 1u);
	if (t1 == 1u)
	{
		io_write16(VIDEO_18E2, VIDEO_00C0);
		sub_0785C3();
		d = 0xFFF0u;
		sub_0786C2(d);
		d = 0u;
		sub_0786C5(d);
		unk_487E = 1u;
		d = 0xE8Fu;
		sub_078677(d, &ignored16, &u);
		unk_4875 = 0x8Du;
		unk_4876 = 3u;
		sub_0786B0();
		io_write8(IO_1FB9, 0x3Fu);
		io_write8(IO_1FBA, 0x36u);
		d = 0x26u;
		sub_0786AD(d, &ignored16_2, &ignored16, &ignored16_3);
		d = 0x126u;
		sub_0786AD(d, &ignored16_2, &ignored16, &ignored16_3);
		sub_07868C(&x, &u_2);
		d = 0x2726u;
		y = sub_025388(x, d);
		io_write16(VIDEO_18E2, 0x140u);
		unk_487E = 2u;
		d = 0x39u;
		sub_078677(d, &y, &u_2);
		d = 0x8B00u;
		carry = sub_078680(d);
		io_write16(VIDEO_18E2, 0x140u);
		t2 = io_read8(VIDEO_18E0);
		io_write8(VIDEO_18E0, t2 + 1u);
	}
	else
	{
		x = 0x5280u;
		stack = 7u;
		do
		{
			u_2 = loaded_table_025790_ADDRESS;
			t3 = mem_read8(x + 2u);
			switch ((int8_t)(uint8_t)((uint32_t)t3 << 1))
			{
			case 0:
				sub_0251F5();
				break;
			case 2:
				sub_0251F6(&x, &y, &u_2);
				break;
			case 4:
				sub_025297(&x, &y, &u_2);
				break;
			case 6:
				sub_025245(&x, &y, &u_2);
				break;
			case 8:
				sub_02527F(&x, &y, &u_2);
				break;
			case 10:
			case 18:
			case 26:
				sub_0251FF(x);
				break;
			case 12:
				sub_025208(x);
				break;
			case 14:
				sub_02521C(x);
				break;
			case 16:
			case 24:
			case 32:
				sub_025244();
				break;
			case 20:
				sub_02524E(x);
				break;
			case 22:
			case 30:
				sub_02525D(x);
				break;
			case 28:
				sub_025288(x);
				break;
			case 34:
				sub_0252A0(x);
				break;
			case 36:
				sub_0252A9(x);
				break;
			case 38:
				sub_0252B9(x);
				break;
			case 40:
				sub_0252DB();
				break;
			case -128:
				sub_024333(&x, &y, &u_2);
				break;
			case -126:
				y = sub_024363(x, y);
				break;
			case -124:
			case -122:
				sub_02439E(&x, &y, &u_2);
				break;
			case -120:
				sub_024409(&x, &u_2);
				break;
			case -118:
				sub_0241EC(&x, &y);
				break;
			case -116:
				sub_02424B(&x, &y, &u_2);
				break;
			case -114:
				u_2 = sub_02427E(x, u_2);
				break;
			case -112:
				sub_0242D0(x);
				break;
			case -110:
				sub_0242AC(x);
				break;
			case -108:
				sub_024329(x);
				break;
			case -106:
				sub_024155(&x, &y, &u_2);
				break;
			case -104:
				sub_02441C(&x, &y, &u_2);
				break;
			case -102:
				sub_0241E2(&x, &y, &u_2);
				break;
			case -100:
				sub_02448F(&x, &y, &u_2);
				break;
			case -98:
				sub_024532(&y, &u_2);
				break;
			case -96:
				sub_024557(&x, &y, &u_2);
				break;
			case -94:
				sub_024571();
				break;
			case -92:
				sub_02457C(&y, &u_2);
				break;
			case -90:
				sub_0245A3(&x, &y, &u_2);
				break;
			case -88:
				sub_0245D1(&x, &y, &u_2);
				break;
			case -86:
				sub_0245E1(&x, &y, &u_2);
				break;
			case -84:
				sub_0245E8();
				break;
			case -82:
				sub_0245F4(&x, &u_2);
				break;
			case -80:
				sub_024616(&x, &y, &u_2);
				break;
			case -78:
				sub_024648(&x, &y, &u_2);
				break;
			case -76:
				sub_0246C3();
				break;
			case -74:
				sub_0246DF();
				break;
			case -72:
				sub_024723();
				break;
			case -70:
				sub_024741(&x, &y);
				break;
			case -68:
				sub_024779();
				break;
			case -66:
				sub_024799();
				break;
			case -64:
				sub_0247AA(&x, &y, &u_2);
				break;
			case -62:
				sub_02482F();
				break;
			case -60:
				sub_024839(&x, &y, &u_2);
				break;
			case -58:
				sub_02488C(&x, &u_2);
				break;
			case -56:
				sub_0248F4();
				break;
			case -54:
				sub_024939(&x, &y, &u_2);
				break;
			case -52:
				sub_02496D(&x, &y, &u_2);
				break;
			case -50:
				y = sub_0249B6(x);
				break;
			case -48:
				sub_024A0B(&x, &y);
				break;
			case -46:
				sub_024AB0(&x, &u_2);
				break;
			case -44:
				sub_024AD3(&x, &u_2);
				break;
			case -42:
				sub_024B3F(&x, &y, &u_2);
				break;
			case -40:
				sub_024B7E(&x, &y, &u_2);
				break;
			case -38:
				sub_024C30(&x, &y, &u_2);
				break;
			case -36:
				sub_024CA6(&x, &y, &u_2);
				break;
			case -34:
				x = sub_024CC2();
				break;
			case -32:
				sub_024CED(&x, &y, &u_2);
				break;
			case -30:
				sub_024D08(&x, &y, &u_2);
				break;
			case -28:
				sub_024D43(x);
				break;
			case -26:
				sub_024D61(x);
				break;
			case -24:
				sub_024D83(x);
				break;
			case -22:
				sub_024D98(x);
				break;
			case -20:
				sub_024DA6(x);
				break;
			case -18:
				sub_024DBF(x);
				break;
			case -16:
				sub_024DD7(&x, &y, &u_2);
				break;
			case -14:
				sub_024E10(&x, &y, &u_2);
				break;
			case -12:
				sub_024E6B();
				break;
			case -10:
				sub_024E87(&x, &y, &u_2);
				break;
			case -8:
				sub_024EBD(&x, &y, &u_2);
				break;
			case -6:
				sub_024F15(&x, &y, &u_2);
				break;
			case -4:
				sub_0251C9(&x, &y, &u_2);
				break;
			case -2:
				sub_025349(&x, &u_2);
				break;
			}
			x += 0x60u;
			t4 = stack;
			stack = t4 - 1u;
		} while (t4 != 1u);
	}
	*p_x = x;
	*p_y = y;
	*p_u = u_2;
}

void sub_0251F5(void)
{
}

void sub_0251F6(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_02579A_ADDRESS;
		t1 = mem_read8(x + 0x28u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
		case 8:
		case 16:
			sub_0251FF(x);
			break;
		case 2:
			sub_025208(x);
			break;
		case 4:
			sub_02521C(x);
			break;
		case 6:
		case 14:
		case 22:
			sub_025244();
			break;
		case 10:
			sub_02524E(x);
			break;
		case 12:
		case 20:
			sub_02525D(x);
			break;
		case 18:
			sub_025288(x);
			break;
		case 24:
			sub_0252A0(x);
			break;
		case 26:
			sub_0252A9(x);
			break;
		case 28:
			sub_0252B9(x);
			break;
		case 30:
			sub_0252DB();
			break;
		case -128:
			sub_0241EC(&x, &y);
			break;
		case -126:
			sub_02424B(&x, &y, &u);
			break;
		case -124:
			u = sub_02427E(x, u);
			break;
		case -122:
			sub_0242D0(x);
			break;
		case -120:
			sub_0242AC(x);
			break;
		case -118:
			sub_024329(x);
			break;
		case -116:
			sub_024155(&x, &y, &u);
			break;
		case -114:
			sub_02441C(&x, &y, &u);
			break;
		case -112:
			sub_0241E2(&x, &y, &u);
			break;
		case -110:
			sub_02448F(&x, &y, &u);
			break;
		case -108:
			sub_024532(&y, &u);
			break;
		case -106:
			sub_024557(&x, &y, &u);
			break;
		case -104:
			sub_024571();
			break;
		case -102:
			sub_02457C(&y, &u);
			break;
		case -100:
			sub_0245A3(&x, &y, &u);
			break;
		case -98:
			sub_0245D1(&x, &y, &u);
			break;
		case -96:
			sub_0245E1(&x, &y, &u);
			break;
		case -94:
			sub_0245E8();
			break;
		case -92:
			sub_0245F4(&x, &u);
			break;
		case -90:
			sub_024616(&x, &y, &u);
			break;
		case -88:
			sub_024648(&x, &y, &u);
			break;
		case -86:
			sub_0246C3();
			break;
		case -84:
			sub_0246DF();
			break;
		case -82:
			sub_024723();
			break;
		case -80:
			sub_024741(&x, &y);
			break;
		case -78:
			sub_024779();
			break;
		case -76:
			sub_024799();
			break;
		case -74:
			sub_0247AA(&x, &y, &u);
			break;
		case -72:
			sub_02482F();
			break;
		case -70:
			sub_024839(&x, &y, &u);
			break;
		case -68:
			sub_02488C(&x, &u);
			break;
		case -66:
			sub_0248F4();
			break;
		case -64:
			sub_024939(&x, &y, &u);
			break;
		case -62:
			sub_02496D(&x, &y, &u);
			break;
		case -60:
			y = sub_0249B6(x);
			break;
		case -58:
			sub_024A0B(&x, &y);
			break;
		case -56:
			sub_024AB0(&x, &u);
			break;
		case -54:
			sub_024AD3(&x, &u);
			break;
		case -52:
			sub_024B3F(&x, &y, &u);
			break;
		case -50:
			sub_024B7E(&x, &y, &u);
			break;
		case -48:
			sub_024C30(&x, &y, &u);
			break;
		case -46:
			sub_024CA6(&x, &y, &u);
			break;
		case -44:
			x = sub_024CC2();
			break;
		case -42:
			sub_024CED(&x, &y, &u);
			break;
		case -40:
			sub_024D08(&x, &y, &u);
			break;
		case -38:
			sub_024D43(x);
			break;
		case -36:
			sub_024D61(x);
			break;
		case -34:
			sub_024D83(x);
			break;
		case -32:
			sub_024D98(x);
			break;
		case -30:
			sub_024DA6(x);
			break;
		case -28:
			sub_024DBF(x);
			break;
		case -26:
			sub_024DD7(&x, &y, &u);
			break;
		case -24:
			sub_024E10(&x, &y, &u);
			break;
		case -22:
			sub_024E6B();
			break;
		case -20:
			sub_024E87(&x, &y, &u);
			break;
		case -18:
			sub_024EBD(&x, &y, &u);
			break;
		case -16:
			sub_024F15(&x, &y, &u);
			break;
		case -14:
			sub_0251C9(&x, &y, &u);
			break;
		case -12:
			sub_025349(&x, &u);
			break;
		case -10:
			sub_0251F5();
			break;
		case -8:
			continue;
		case -6:
			sub_025297(&x, &y, &u);
			break;
		case -4:
			sub_025245(&x, &y, &u);
			break;
		case -2:
			sub_02527F(&x, &y, &u);
			break;
		}
		break;
	}
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

void sub_0251FF(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 0x2Au, 0x20u);
	t1 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t1 + 1u);
}

void sub_025208(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x2Au);
	mem_write8(x + 0x2Au, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(x + 0xFu, 0x300u);
		mem_write8(x + 5u, 0x81u);
		t2 = mem_read8(x + 0x28u);
		mem_write8(x + 0x28u, t2 + 1u);
	}
}

void sub_02521C(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t5 = 0, t6 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = mem_read16(x + 0xCu);
	t2 = mem_read16(x + 0x2Bu);
	t3 = io_read16(VIDEO_18F4);
	t4 = t1 + t2 - t3;
	d = t4;
	if ((int16_t)t4 < 0 || (int16_t)d < 0x20)
		return;
	t5 = mem_read8(x + 0x2Du);
	d = t5 + 0x3F08u;
	carry = sub_078680(d);
	mem_write16(x + 0xFu, 0u);
	mem_write8(x + 5u, 0x9Eu);
	t6 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t6 + 1u);
}

void sub_025244(void)
{
}

void sub_025245(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_0257A2_ADDRESS;
		t1 = mem_read8(x + 0x28u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case -8:
		case 0:
		case 8:
			sub_0251FF(x);
			break;
		case 2:
			sub_02524E(x);
			break;
		case 4:
		case 12:
			sub_02525D(x);
			break;
		case -2:
		case 6:
		case 14:
			sub_025244();
			break;
		case 10:
			sub_025288(x);
			break;
		case 16:
			sub_0252A0(x);
			break;
		case 18:
			sub_0252A9(x);
			break;
		case 20:
			sub_0252B9(x);
			break;
		case 22:
			sub_0252DB();
			break;
		case -128:
			sub_0242AC(x);
			break;
		case -126:
			sub_024329(x);
			break;
		case -124:
			sub_024155(&x, &y, &u);
			break;
		case -122:
			sub_02441C(&x, &y, &u);
			break;
		case -120:
			sub_0241E2(&x, &y, &u);
			break;
		case -118:
			sub_02448F(&x, &y, &u);
			break;
		case -116:
			sub_024532(&y, &u);
			break;
		case -114:
			sub_024557(&x, &y, &u);
			break;
		case -112:
			sub_024571();
			break;
		case -110:
			sub_02457C(&y, &u);
			break;
		case -108:
			sub_0245A3(&x, &y, &u);
			break;
		case -106:
			sub_0245D1(&x, &y, &u);
			break;
		case -104:
			sub_0245E1(&x, &y, &u);
			break;
		case -102:
			sub_0245E8();
			break;
		case -100:
			sub_0245F4(&x, &u);
			break;
		case -98:
			sub_024616(&x, &y, &u);
			break;
		case -96:
			sub_024648(&x, &y, &u);
			break;
		case -94:
			sub_0246C3();
			break;
		case -92:
			sub_0246DF();
			break;
		case -90:
			sub_024723();
			break;
		case -88:
			sub_024741(&x, &y);
			break;
		case -86:
			sub_024779();
			break;
		case -84:
			sub_024799();
			break;
		case -82:
			sub_0247AA(&x, &y, &u);
			break;
		case -80:
			sub_02482F();
			break;
		case -78:
			sub_024839(&x, &y, &u);
			break;
		case -76:
			sub_02488C(&x, &u);
			break;
		case -74:
			sub_0248F4();
			break;
		case -72:
			sub_024939(&x, &y, &u);
			break;
		case -70:
			sub_02496D(&x, &y, &u);
			break;
		case -68:
			y = sub_0249B6(x);
			break;
		case -66:
			sub_024A0B(&x, &y);
			break;
		case -64:
			sub_024AB0(&x, &u);
			break;
		case -62:
			sub_024AD3(&x, &u);
			break;
		case -60:
			sub_024B3F(&x, &y, &u);
			break;
		case -58:
			sub_024B7E(&x, &y, &u);
			break;
		case -56:
			sub_024C30(&x, &y, &u);
			break;
		case -54:
			sub_024CA6(&x, &y, &u);
			break;
		case -52:
			x = sub_024CC2();
			break;
		case -50:
			sub_024CED(&x, &y, &u);
			break;
		case -48:
			sub_024D08(&x, &y, &u);
			break;
		case -46:
			sub_024D43(x);
			break;
		case -44:
			sub_024D61(x);
			break;
		case -42:
			sub_024D83(x);
			break;
		case -40:
			sub_024D98(x);
			break;
		case -38:
			sub_024DA6(x);
			break;
		case -36:
			sub_024DBF(x);
			break;
		case -34:
			sub_024DD7(&x, &y, &u);
			break;
		case -32:
			sub_024E10(&x, &y, &u);
			break;
		case -30:
			sub_024E6B();
			break;
		case -28:
			sub_024E87(&x, &y, &u);
			break;
		case -26:
			sub_024EBD(&x, &y, &u);
			break;
		case -24:
			sub_024F15(&x, &y, &u);
			break;
		case -22:
			sub_0251C9(&x, &y, &u);
			break;
		case -20:
			sub_025349(&x, &u);
			break;
		case -18:
			sub_0251F5();
			break;
		case -16:
			sub_0251F6(&x, &y, &u);
			break;
		case -14:
			sub_025297(&x, &y, &u);
			break;
		case -12:
			continue;
		case -10:
			sub_02527F(&x, &y, &u);
			break;
		case -6:
			sub_025208(x);
			break;
		case -4:
			sub_02521C(x);
			break;
		}
		break;
	}
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

void sub_02524E(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x2Au);
	mem_write8(x + 0x2Au, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(x + 0xFu, 0x200u);
		t2 = mem_read8(x + 0x28u);
		mem_write8(x + 0x28u, t2 + 1u);
	}
}

void sub_02525D(uint16_t x)
{
	uint16_t d = 0;
	uint8_t t5 = 0, t6 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = mem_read16(x + 0xCu);
	t2 = mem_read16(x + 0x2Bu);
	t3 = io_read16(VIDEO_18F4);
	t4 = t1 + t2 - t3;
	d = t4;
	if ((int16_t)t4 >= 0 && (int16_t)d >= 0x20)
	{
		mem_write16(x + 0xFu, 0u);
		t5 = mem_read8(x + 5u);
		mem_write8(x + 5u, (uint16_t)((((uint16_t)((uint32_t)(uint8_t)(((uint16_t)((uint32_t)t5 << 8) >> 8) - 1u) << 8) >> 8) | 0x80u) << 8) >> 8);
		t6 = mem_read8(x + 0x28u);
		mem_write8(x + 0x28u, t6 + 1u);
	}
}

void sub_02527F(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_0257AA_ADDRESS;
		t1 = mem_read8(x + 0x28u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case -16:
		case -8:
		case 0:
			sub_0251FF(x);
			break;
		case 2:
			sub_025288(x);
			break;
		case -4:
		case 4:
			sub_02525D(x);
			break;
		case -10:
		case -2:
		case 6:
			sub_025244();
			break;
		case 8:
			sub_0252A0(x);
			break;
		case 10:
			sub_0252A9(x);
			break;
		case 12:
			sub_0252B9(x);
			break;
		case 14:
			sub_0252DB();
			break;
		case -128:
			sub_0241E2(&x, &y, &u);
			break;
		case -126:
			sub_02448F(&x, &y, &u);
			break;
		case -124:
			sub_024532(&y, &u);
			break;
		case -122:
			sub_024557(&x, &y, &u);
			break;
		case -120:
			sub_024571();
			break;
		case -118:
			sub_02457C(&y, &u);
			break;
		case -116:
			sub_0245A3(&x, &y, &u);
			break;
		case -114:
			sub_0245D1(&x, &y, &u);
			break;
		case -112:
			sub_0245E1(&x, &y, &u);
			break;
		case -110:
			sub_0245E8();
			break;
		case -108:
			sub_0245F4(&x, &u);
			break;
		case -106:
			sub_024616(&x, &y, &u);
			break;
		case -104:
			sub_024648(&x, &y, &u);
			break;
		case -102:
			sub_0246C3();
			break;
		case -100:
			sub_0246DF();
			break;
		case -98:
			sub_024723();
			break;
		case -96:
			sub_024741(&x, &y);
			break;
		case -94:
			sub_024779();
			break;
		case -92:
			sub_024799();
			break;
		case -90:
			sub_0247AA(&x, &y, &u);
			break;
		case -88:
			sub_02482F();
			break;
		case -86:
			sub_024839(&x, &y, &u);
			break;
		case -84:
			sub_02488C(&x, &u);
			break;
		case -82:
			sub_0248F4();
			break;
		case -80:
			sub_024939(&x, &y, &u);
			break;
		case -78:
			sub_02496D(&x, &y, &u);
			break;
		case -76:
			y = sub_0249B6(x);
			break;
		case -74:
			sub_024A0B(&x, &y);
			break;
		case -72:
			sub_024AB0(&x, &u);
			break;
		case -70:
			sub_024AD3(&x, &u);
			break;
		case -68:
			sub_024B3F(&x, &y, &u);
			break;
		case -66:
			sub_024B7E(&x, &y, &u);
			break;
		case -64:
			sub_024C30(&x, &y, &u);
			break;
		case -62:
			sub_024CA6(&x, &y, &u);
			break;
		case -60:
			x = sub_024CC2();
			break;
		case -58:
			sub_024CED(&x, &y, &u);
			break;
		case -56:
			sub_024D08(&x, &y, &u);
			break;
		case -54:
			sub_024D43(x);
			break;
		case -52:
			sub_024D61(x);
			break;
		case -50:
			sub_024D83(x);
			break;
		case -48:
			sub_024D98(x);
			break;
		case -46:
			sub_024DA6(x);
			break;
		case -44:
			sub_024DBF(x);
			break;
		case -42:
			sub_024DD7(&x, &y, &u);
			break;
		case -40:
			sub_024E10(&x, &y, &u);
			break;
		case -38:
			sub_024E6B();
			break;
		case -36:
			sub_024E87(&x, &y, &u);
			break;
		case -34:
			sub_024EBD(&x, &y, &u);
			break;
		case -32:
			sub_024F15(&x, &y, &u);
			break;
		case -30:
			sub_0251C9(&x, &y, &u);
			break;
		case -28:
			sub_025349(&x, &u);
			break;
		case -26:
			sub_0251F5();
			break;
		case -24:
			sub_0251F6(&x, &y, &u);
			break;
		case -22:
			sub_025297(&x, &y, &u);
			break;
		case -20:
			sub_025245(&x, &y, &u);
			break;
		case -18:
			continue;
		case -14:
			sub_025208(x);
			break;
		case -12:
			sub_02521C(x);
			break;
		case -6:
			sub_02524E(x);
			break;
		}
		break;
	}
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

void sub_025288(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x2Au);
	mem_write8(x + 0x2Au, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(x + 0xFu, 0x100u);
		t2 = mem_read8(x + 0x28u);
		mem_write8(x + 0x28u, t2 + 1u);
	}
}

void sub_025297(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_0257B2_ADDRESS;
		t1 = mem_read8(x + 0x28u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			sub_0252A0(x);
			break;
		case 2:
			sub_0252A9(x);
			break;
		case 4:
			sub_0252B9(x);
			break;
		case 6:
			sub_0252DB();
			break;
		case -128:
			sub_024571();
			break;
		case -126:
			sub_02457C(&y, &u);
			break;
		case -124:
			sub_0245A3(&x, &y, &u);
			break;
		case -122:
			sub_0245D1(&x, &y, &u);
			break;
		case -120:
			sub_0245E1(&x, &y, &u);
			break;
		case -118:
			sub_0245E8();
			break;
		case -116:
			sub_0245F4(&x, &u);
			break;
		case -114:
			sub_024616(&x, &y, &u);
			break;
		case -112:
			sub_024648(&x, &y, &u);
			break;
		case -110:
			sub_0246C3();
			break;
		case -108:
			sub_0246DF();
			break;
		case -106:
			sub_024723();
			break;
		case -104:
			sub_024741(&x, &y);
			break;
		case -102:
			sub_024779();
			break;
		case -100:
			sub_024799();
			break;
		case -98:
			sub_0247AA(&x, &y, &u);
			break;
		case -96:
			sub_02482F();
			break;
		case -94:
			sub_024839(&x, &y, &u);
			break;
		case -92:
			sub_02488C(&x, &u);
			break;
		case -90:
			sub_0248F4();
			break;
		case -88:
			sub_024939(&x, &y, &u);
			break;
		case -86:
			sub_02496D(&x, &y, &u);
			break;
		case -84:
			y = sub_0249B6(x);
			break;
		case -82:
			sub_024A0B(&x, &y);
			break;
		case -80:
			sub_024AB0(&x, &u);
			break;
		case -78:
			sub_024AD3(&x, &u);
			break;
		case -76:
			sub_024B3F(&x, &y, &u);
			break;
		case -74:
			sub_024B7E(&x, &y, &u);
			break;
		case -72:
			sub_024C30(&x, &y, &u);
			break;
		case -70:
			sub_024CA6(&x, &y, &u);
			break;
		case -68:
			x = sub_024CC2();
			break;
		case -66:
			sub_024CED(&x, &y, &u);
			break;
		case -64:
			sub_024D08(&x, &y, &u);
			break;
		case -62:
			sub_024D43(x);
			break;
		case -60:
			sub_024D61(x);
			break;
		case -58:
			sub_024D83(x);
			break;
		case -56:
			sub_024D98(x);
			break;
		case -54:
			sub_024DA6(x);
			break;
		case -52:
			sub_024DBF(x);
			break;
		case -50:
			sub_024DD7(&x, &y, &u);
			break;
		case -48:
			sub_024E10(&x, &y, &u);
			break;
		case -46:
			sub_024E6B();
			break;
		case -44:
			sub_024E87(&x, &y, &u);
			break;
		case -42:
			sub_024EBD(&x, &y, &u);
			break;
		case -40:
			sub_024F15(&x, &y, &u);
			break;
		case -38:
			sub_0251C9(&x, &y, &u);
			break;
		case -36:
			sub_025349(&x, &u);
			break;
		case -34:
			sub_0251F5();
			break;
		case -32:
			sub_0251F6(&x, &y, &u);
			break;
		case -30:
			continue;
		case -28:
			sub_025245(&x, &y, &u);
			break;
		case -26:
			sub_02527F(&x, &y, &u);
			break;
		case -24:
		case -16:
		case -8:
			sub_0251FF(x);
			break;
		case -22:
			sub_025208(x);
			break;
		case -20:
			sub_02521C(x);
			break;
		case -18:
		case -10:
		case -2:
			sub_025244();
			break;
		case -14:
			sub_02524E(x);
			break;
		case -12:
		case -4:
			sub_02525D(x);
			break;
		case -6:
			sub_025288(x);
			break;
		}
		break;
	}
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

void sub_0252A0(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 0x2Au, 0x80u);
	t1 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t1 + 1u);
}

void sub_0252A9(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x2Au);
	mem_write8(x + 0x2Au, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 5u, 0xAEu);
		t2 = mem_read8(x + 0x28u);
		mem_write8(x + 0x28u, t2 + 1u);
	}
	if ((unk_4815 & 0x1Fu) == 0u)
	{
		d = 0x4500u;
		carry = sub_078680(d);
	}
}

void sub_0252B9(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) == 0u)
		return;
	if (unk_4885 == 0xFu)
	{
		d = 0x3F09u;
		carry = sub_078680(d);
		d = 0x3F0Au;
		carry = sub_078680(d);
	}
	unk_5520 = 0u;
	t2 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t2 + 1u);
}

void sub_0252DB(void)
{
}

void sub_025349(uint16_t *p_x, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t d = 0;
	uint16_t t1 = 0;

	io_write8(IO_1FB9, 0x13u);
	io_write8(IO_1FBA, 0x2Cu);
	t1 = io_read16(VIDEO_18E2);
	io_write16(VIDEO_18E2, t1 - 1u);
	if (t1 == 1u)
	{
		sub_07868C(&x, &u);
		unk_4872 = 0u;
	}
	else if ((unk_4815 & 0x1Fu) == 0u)
	{
		d = 0x4500u;
		carry = sub_078680(d);
	}
	*p_x = x;
	*p_u = u;
}

void unused_025361(void)
{
	uint32_t carry = 0;
	uint16_t d = 0;

	unk_4DA0 = ((((uint8_t)unk_4815 & 0x10u) << 1) << 1) << 1;
	unk_4DA6 = 0x80u;
	if ((unk_4815 & 0x1Fu) == 0u)
	{
		d = 0x4500u;
		carry = sub_078680(d);
	}
}

uint16_t sub_025388(uint16_t x, uint16_t d)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t placement = 0, u = 0, y = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, kind = 0, t4 = 0, x_2 = 0, z = 0;

	a = (uint8_t)(d >> 8);
	t1 = a | 0x1000u;
	b = (uint8_t)t1;
	carry = (int8_t)b < 0;
	b = (uint32_t)b << 1;
	a = (uint8_t)(((uint32_t)(uint8_t)((uint32_t)a << 8) << 1) | carry);
	carry = (int8_t)b < 0;
	b = (uint32_t)b << 1;
	a = (uint8_t)(((uint32_t)a << 1) | carry);
	carry = (int8_t)b < 0;
	t2 = object_12_placements_ADDRESS + (((((uint32_t)a << 1) | carry) << 8) | (uint8_t)((uint32_t)b << 1));
	u = t2 + 2u;
	y = PLACEMENT(t2)->object;
	if (y == 0xFFFFu)
		y = x;
	mem_write8(y, 0x80u);
	t3 = u;
	kind = PLACEMENT(t3 - 0x2u)->kind;
	mem_write16(y + 4u, ((uint32_t)(kind >> 8) << 8) | (uint8_t)(kind | 0x80u));
	t4 = t3 + 2u;
	placement = t4 + 2u;
	x_2 = PLACEMENT(t4 - 0x4u)->x;
	a = (uint8_t)(x_2 >> 8);
	b = (uint8_t)x_2;
	if ((uint16_t)(((uint32_t)a << 8) | b) != 0xFFFFu)
		mem_write16(y + 0xCu, ((uint32_t)a << 8) | b);
	mem_write16(y + 0x11u, 0x80u);
	z = PLACEMENT(placement - 0x6u)->z;
	a = (uint8_t)(z >> 8);
	b = (uint8_t)z;
	if ((uint16_t)(((uint32_t)a << 8) | b) != 0xFFFFu)
		mem_write16(y + 0x16u, ((uint32_t)a << 8) | b);
	return y;
}

void sub_0253C9(uint16_t d)
{
	uint8_t a = 0, b = 0;
	uint16_t x = 0;
	uint8_t stack = 0;
	uint8_t t6 = 0, t7 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	unk_48EB = d >> 8;
	t1 = absent_player_blanks[d & 0x7Fu];
	unk_48E8 = PLAYER_BLANK(t1)->width;
	t2 = t1 + 1u;
	unk_48EA = PLAYER_BLANK(t2 - 0x1u)->height;
	t3 = t2 + 1u;
	t4 = t3 + 1u;
	b = PLAYER_BLANK(t4 - 0x3u)->colour;
	stack = PLAYER_BLANK(t3 - 0x2u)->tile;
	x = PLAYER_BLANK(t4 + (int8_t)((uint32_t)unk_48EB << 1) - 0x3u)->marge_place;
	a = stack;
	do
	{
		stack = a;
		unk_48E9 = unk_48E8;
		a = stack;
		do
		{
			mem_write8(x - 0x2000u, b);
			t5 = x;
			x = t5 + 1u;
			mem_write8(t5, a);
			t6 = unk_48E9;
			unk_48E9 = t6 - 1u;
		} while (t6 != 1u);
		stack = b;
		x += (int8_t)(0x40u - unk_48E8);
		b = stack;
		t7 = unk_48EA;
		unk_48EA = t7 - 1u;
	} while (t7 != 1u);
}

void sub_02541D(uint16_t *p_x, uint16_t *p_u)
{
	uint16_t d = 0, u = 0, x = 0;

	d = 0x9601u;
	u = 0x100u;
	x = VIDEO_1A00;
	while (u != 0u)
	{
		mem_write16(x, d);
		x += 2u;
		u--;
	}
	*p_x = x;
	*p_u = u;
}

void sub_025428(uint16_t *p_x, uint16_t *p_u)
{
	uint16_t u = 0, x = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	sub_02541D(&x, &u);
	io_write16(VIDEO_18F1, 0u);
	io_write16(VIDEO_18EF, 0u);
	t1 = io_read8(VIDEO_18ED);
	io_write8(VIDEO_18ED, 0u);
	t2 = io_read8(VIDEO_18EB);
	io_write8(VIDEO_18EB, 0u);
	io_write8(VIDEO_1C80, 3u);
	t3 = io_read8(VIDEO_18EC);
	io_write8(VIDEO_18EC, t3 + 1u);
	*p_x = x;
	*p_u = u;
}

uint16_t sub_025446(void)
{
	uint8_t d = 0;
	uint16_t x = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = io_read8(VIDEO_18ED);
	d = t1;
	x = sub_0254BF(d);
	t2 = io_read8(VIDEO_18ED);
	io_write8(VIDEO_18ED, t2 + 8u);
	t3 = io_read8(VIDEO_18ED);
	if (t3 >= 0xC0u)
	{
		t4 = io_read8(VIDEO_18EC);
		io_write8(VIDEO_18EC, t4 + 1u);
	}
	return x;
}

uint16_t sub_025464(void)
{
	uint8_t d = 0;
	uint16_t x = 0;
	uint8_t t1 = 0;

	t1 = io_read8(VIDEO_18ED);
	d = t1;
	x = sub_0254BF(d);
	return x;
}

uint16_t sub_02546C(void)
{
	uint16_t ignored16 = 0, u = 0;
	uint8_t t1 = 0;

	u = loaded_table_02599C_ADDRESS;
	t1 = io_read8(VIDEO_18EC);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_025476();
		return u;
	case 2:
		sub_025491();
		return u;
	case 4:
		sub_0254A3();
		return u;
	case 6:
		sub_0254BE();
		return u;
	case -6:
		sub_025428(&ignored16, &u);
		return u;
	case -4:
		sub_025446();
		return u;
	case -2:
		sub_025464();
		return u;
	}
	unreachable();
}

void sub_025476(void)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = io_read8(VIDEO_18EB);
	io_write8(VIDEO_18EB, 0u);
	io_write8(VIDEO_18ED, 0xC0u);
	io_write8(VIDEO_1C80, 3u);
	io_write8(0x18F3u, 0x40u);
	t2 = io_read8(VIDEO_18EC);
	io_write8(VIDEO_18EC, t2 + 1u);
}

uint16_t sub_025491(void)
{
	uint8_t d = 0;
	uint16_t x = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = io_read8(VIDEO_18ED);
	d = t1;
	x = sub_0254BF(d);
	t2 = io_read8(0x18F3u);
	io_write8(0x18F3u, t2 - 1u);
	if (t2 == 1u)
	{
		t3 = io_read8(VIDEO_18EC);
		io_write8(VIDEO_18EC, t3 + 1u);
	}
	return x;
}

uint16_t sub_0254A3(void)
{
	uint8_t a = 0, d = 0;
	uint16_t x = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = io_read8(VIDEO_18ED);
	d = t1;
	x = sub_0254BF(d);
	t2 = io_read8(VIDEO_18ED);
	a = t2 - 2u;
	io_write8(VIDEO_18ED, a);
	if (a != 0u)
	{
		sub_0254BE();
		return x;
	}
	t3 = io_read8(VIDEO_1C80);
	io_write8(VIDEO_1C80, 0u);
	t4 = io_read8(VIDEO_18EC);
	io_write8(VIDEO_18EC, t4 + 1u);
	sub_0254BE();
	return x;
}

void sub_0254BE(void)
{
}

uint16_t sub_0254BF(uint8_t d)
{
	uint8_t a = 0, b = 0;
	uint16_t d_2 = 0, x = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t8 = 0, t9 = 0;
	uint16_t t5 = 0, t6 = 0, t7 = 0;

	io_write8(VIDEO_18EE, d);
	t1 = io_read8(VIDEO_18EA);
	io_write8(VIDEO_18EA, 0u);
	x = VIDEO_1A00;
	do
	{
		t2 = io_read8(VIDEO_18EA);
		t3 = io_read8(VIDEO_18EB);
		t4 = io_read8(VIDEO_18EE);
		d_2 = ((uint32_t)(uint8_t)((uint32_t)(t2 + t3) << 1) << 8) | t4;
		d_2 = sub_0254F4(d_2);
		a = (uint8_t)(d_2 >> 8);
		b = (uint8_t)d_2;
		t5 = (((uint32_t)a << 8) | b) + 0x196u;
		a = (t5 >> 8) & 1u;
		t6 = a | 0x1000u;
		t7 = x;
		x = t7 + 2u;
		mem_write16(t7, ((uint32_t)(uint8_t)t5 << 8) | (uint8_t)t6);
		t8 = io_read8(VIDEO_18EA);
		io_write8(VIDEO_18EA, t8 - 1u);
	} while (t8 != 1u);
	t9 = io_read8(VIDEO_18EB);
	io_write8(VIDEO_18EB, t9 - 2u);
	return x;
}

uint16_t sub_0254F4(uint16_t d)
{
	uint8_t a = 0, b = 0;
	uint16_t cosines = 0, d_2 = 0;
	uint16_t t1 = 0;
	uint32_t unk_48EC_halfword = 0;

	a = (uint8_t)(d >> 8);
	b = (uint8_t)d;
	unk_48E8 = a;
	unk_48E9 = b;
	unk_48EA = a & 0x3Fu;
	cosines = wave_cosines_ADDRESS;
	if ((unk_48E8 & 0x40u) == 0u)
		a = (uint8_t)((uint16_t)((uint32_t)WAVE_COSINE(cosines + ((int8_t)(0x3Fu - unk_48EA))) * unk_48E9) >> 8);
	else
		a = (uint8_t)((uint16_t)((uint32_t)WAVE_COSINE(cosines + (int8_t)unk_48EA) * b) >> 8);
	unk_48ED = a;
	unk_48EC = 0u;
	if ((unk_48E8 & 0x80u) != 0u)
	{
		unk_48EC_halfword = 0u - (((uint32_t)unk_48EC << 8u) | unk_48ED);
		unk_48EC = (uint8_t)(unk_48EC_halfword >> 8u);
		unk_48ED = (uint8_t)unk_48EC_halfword;
	}
	t1 = (((uint32_t)unk_48EC << 8u) | unk_48ED);
	d_2 = t1;
	return d_2;
}
