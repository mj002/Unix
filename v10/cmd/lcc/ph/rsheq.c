/* The Plum Hall Validation Suite for C
 * Unpublished copyright (c) 1986-1991, Chiron Systems Inc and Plum Hall Inc.
 * VERSION: 4
 * DATE: 1993-01-01
 * The "ANSI" mode of the Suite corresponds to the official ANSI C, X3.159-1989.
 * As per your license agreement, your distribution is not to be moved or copied outside the Designated Site
 * without specific permission from Plum Hall Inc.
 */

#define ANSI 1  /* This file follows ANSI arithmetic rules, which may not work in non-ANSI modes */
#include "types.h"
int main()
	{
	extern char *Filename;
	auto struct {
		CHAR c;
		SHORT s;
		INT i;
		UCHAR uc;
		USHORT us;
		UINT ui;
		LONG l;
		ULONG ul;
		FLOAT f;
		DOUBLE d;
#if ANSI
		SCHAR sc;
		LDOUBLE ld;
#endif
		} F;
	F.c = 7;
#if ANSI
	F.sc = 8;
#endif
	F.s = 9;
	F.i = 10;
	F.uc = 11;
	F.us = 12;
	F.ui = 13;
	F.l = 14;
	F.ul = 15;
	F.f = 16;
	F.d = 17;
#if ANSI
	F.ld = 18;
#endif
	{
	auto CHAR Ic[12];
	int x_0 = 0;
#if ANSI
	auto SCHAR Isc[12];
	int x_1 = 1;
#endif
	auto SHORT Is[12];
	int x_2 = 2;
	auto INT Ii[12];
	int x_3 = 3;
	auto UCHAR Iuc[12];
	int x_4 = 4;
	auto USHORT Ius[12];
	int x_5 = 5;
	auto UINT Iui[12];
	int x_6 = 6;
	auto LONG Il[12];
	int x_7 = 7;
	auto ULONG Iul[12];
	int x_8 = 8;
	auto FLOAT If[12];
	int x_9 = 9;
	auto DOUBLE Id[12];
	int x_10 = 10;
#if ANSI
	auto LDOUBLE Ild[12];
	int x_11 = 11;
#endif
	Ic[x_0] = 7;
#if ANSI
	Isc[x_1] = 8;
#endif
	Is[x_2] = 9;
	Ii[x_3] = 10;
	Iuc[x_4] = 11;
	Ius[x_5] = 12;
	Iui[x_6] = 13;
	Il[x_7] = 14;
	Iul[x_8] = 15;
	If[x_9] = 16;
	Id[x_10] = 17;
#if ANSI
	Ild[x_11] = 18;
#endif
	{
	int true = 1, false = 0;
	Filename =  " auto struct auto array1 rsheq ";
	F.c = 7; Ic[x_0] = 1;
	F.c >>= Ic[x_0];
	iequals(__LINE__, F.c, (CHAR)3);
	F.c = 7; Ic[x_0] = 1;
	iequals(__LINE__, F.c >>= Ic[x_0], (CHAR)3);
	Ic[x_0] = 7; F.c = 1;
	Ic[x_0] >>= F.c;
	iequals(__LINE__, Ic[x_0], (CHAR)3);
	Ic[x_0] = 7; F.c = 1;
	iequals(__LINE__, Ic[x_0] >>= F.c, (CHAR)3);
#if ANSI
	F.c = 7; Isc[x_1] = 1;
	F.c >>= Isc[x_1];
	iequals(__LINE__, F.c, (CHAR)3);
	F.c = 7; Isc[x_1] = 1;
	iequals(__LINE__, F.c >>= Isc[x_1], (CHAR)3);
	Isc[x_1] = 8; F.c = 1;
	Isc[x_1] >>= F.c;
	iequals(__LINE__, Isc[x_1], (SCHAR)4);
	Isc[x_1] = 8; F.c = 1;
	iequals(__LINE__, Isc[x_1] >>= F.c, (SCHAR)4);
#endif
	F.c = 7; Is[x_2] = 1;
	F.c >>= Is[x_2];
	iequals(__LINE__, F.c, (CHAR)3);
	F.c = 7; Is[x_2] = 1;
	iequals(__LINE__, F.c >>= Is[x_2], (CHAR)3);
	Is[x_2] = 9; F.c = 1;
	Is[x_2] >>= F.c;
	iequals(__LINE__, Is[x_2], (SHORT)4);
	Is[x_2] = 9; F.c = 1;
	iequals(__LINE__, Is[x_2] >>= F.c, (SHORT)4);
	F.c = 7; Ii[x_3] = 1;
	F.c >>= Ii[x_3];
	iequals(__LINE__, F.c, (CHAR)3);
	F.c = 7; Ii[x_3] = 1;
	iequals(__LINE__, F.c >>= Ii[x_3], (CHAR)3);
	Ii[x_3] = 10; F.c = 1;
	Ii[x_3] >>= F.c;
	iequals(__LINE__, Ii[x_3], (INT)5);
	Ii[x_3] = 10; F.c = 1;
	iequals(__LINE__, Ii[x_3] >>= F.c, (INT)5);
	F.c = 7; Iuc[x_4] = 1;
	F.c >>= Iuc[x_4];
	iequals(__LINE__, F.c, (CHAR)3);
	F.c = 7; Iuc[x_4] = 1;
	iequals(__LINE__, F.c >>= Iuc[x_4], (CHAR)3);
	Iuc[x_4] = 11; F.c = 1;
	Iuc[x_4] >>= F.c;
	iequals(__LINE__, Iuc[x_4], (UCHAR)5);
	Iuc[x_4] = 11; F.c = 1;
	iequals(__LINE__, Iuc[x_4] >>= F.c, (UCHAR)5);
	F.c = 7; Ius[x_5] = 1;
	F.c >>= Ius[x_5];
	iequals(__LINE__, F.c, (CHAR)3);
	F.c = 7; Ius[x_5] = 1;
	iequals(__LINE__, F.c >>= Ius[x_5], (CHAR)3);
	Ius[x_5] = 12; F.c = 1;
	Ius[x_5] >>= F.c;
	iequals(__LINE__, Ius[x_5], (USHORT)6);
	Ius[x_5] = 12; F.c = 1;
	iequals(__LINE__, Ius[x_5] >>= F.c, (USHORT)6);
	F.c = 7; Iui[x_6] = 1;
	F.c >>= Iui[x_6];
	iequals(__LINE__, F.c, (CHAR)3);
	F.c = 7; Iui[x_6] = 1;
	iequals(__LINE__, F.c >>= Iui[x_6], (CHAR)3);
	Iui[x_6] = 13; F.c = 1;
	Iui[x_6] >>= F.c;
	iequals(__LINE__, Iui[x_6], (UINT)6);
	Iui[x_6] = 13; F.c = 1;
	iequals(__LINE__, Iui[x_6] >>= F.c, (UINT)6);
	F.c = 7; Il[x_7] = 1;
	F.c >>= Il[x_7];
	iequals(__LINE__, F.c, (CHAR)3);
	F.c = 7; Il[x_7] = 1;
	iequals(__LINE__, F.c >>= Il[x_7], (CHAR)3);
	Il[x_7] = 14; F.c = 1;
	Il[x_7] >>= F.c;
	lequals(__LINE__, Il[x_7], (LONG)7L);
	Il[x_7] = 14; F.c = 1;
	lequals(__LINE__, Il[x_7] >>= F.c, (LONG)7L);
	F.c = 7; Iul[x_8] = 1;
	F.c >>= Iul[x_8];
	iequals(__LINE__, F.c, (CHAR)3);
	F.c = 7; Iul[x_8] = 1;
	iequals(__LINE__, F.c >>= Iul[x_8], (CHAR)3);
	Iul[x_8] = 15; F.c = 1;
	Iul[x_8] >>= F.c;
	lequals(__LINE__, Iul[x_8], (ULONG)7L);
	Iul[x_8] = 15; F.c = 1;
	lequals(__LINE__, Iul[x_8] >>= F.c, (ULONG)7L);
#if ANSI
	F.sc = 8; Ic[x_0] = 1;
	F.sc >>= Ic[x_0];
	iequals(__LINE__, F.sc, (SCHAR)4);
	F.sc = 8; Ic[x_0] = 1;
	iequals(__LINE__, F.sc >>= Ic[x_0], (SCHAR)4);
	Ic[x_0] = 7; F.sc = 1;
	Ic[x_0] >>= F.sc;
	iequals(__LINE__, Ic[x_0], (CHAR)3);
	Ic[x_0] = 7; F.sc = 1;
	iequals(__LINE__, Ic[x_0] >>= F.sc, (CHAR)3);
#endif
#if ANSI
	F.sc = 8; Isc[x_1] = 1;
	F.sc >>= Isc[x_1];
	iequals(__LINE__, F.sc, (SCHAR)4);
	F.sc = 8; Isc[x_1] = 1;
	iequals(__LINE__, F.sc >>= Isc[x_1], (SCHAR)4);
	Isc[x_1] = 8; F.sc = 1;
	Isc[x_1] >>= F.sc;
	iequals(__LINE__, Isc[x_1], (SCHAR)4);
	Isc[x_1] = 8; F.sc = 1;
	iequals(__LINE__, Isc[x_1] >>= F.sc, (SCHAR)4);
#endif
#if ANSI
	F.sc = 8; Is[x_2] = 1;
	F.sc >>= Is[x_2];
	iequals(__LINE__, F.sc, (SCHAR)4);
	F.sc = 8; Is[x_2] = 1;
	iequals(__LINE__, F.sc >>= Is[x_2], (SCHAR)4);
	Is[x_2] = 9; F.sc = 1;
	Is[x_2] >>= F.sc;
	iequals(__LINE__, Is[x_2], (SHORT)4);
	Is[x_2] = 9; F.sc = 1;
	iequals(__LINE__, Is[x_2] >>= F.sc, (SHORT)4);
#endif
#if ANSI
	F.sc = 8; Ii[x_3] = 1;
	F.sc >>= Ii[x_3];
	iequals(__LINE__, F.sc, (SCHAR)4);
	F.sc = 8; Ii[x_3] = 1;
	iequals(__LINE__, F.sc >>= Ii[x_3], (SCHAR)4);
	Ii[x_3] = 10; F.sc = 1;
	Ii[x_3] >>= F.sc;
	iequals(__LINE__, Ii[x_3], (INT)5);
	Ii[x_3] = 10; F.sc = 1;
	iequals(__LINE__, Ii[x_3] >>= F.sc, (INT)5);
#endif
#if ANSI
	F.sc = 8; Iuc[x_4] = 1;
	F.sc >>= Iuc[x_4];
	iequals(__LINE__, F.sc, (SCHAR)4);
	F.sc = 8; Iuc[x_4] = 1;
	iequals(__LINE__, F.sc >>= Iuc[x_4], (SCHAR)4);
	Iuc[x_4] = 11; F.sc = 1;
	Iuc[x_4] >>= F.sc;
	iequals(__LINE__, Iuc[x_4], (UCHAR)5);
	Iuc[x_4] = 11; F.sc = 1;
	iequals(__LINE__, Iuc[x_4] >>= F.sc, (UCHAR)5);
#endif
#if ANSI
	F.sc = 8; Ius[x_5] = 1;
	F.sc >>= Ius[x_5];
	iequals(__LINE__, F.sc, (SCHAR)4);
	F.sc = 8; Ius[x_5] = 1;
	iequals(__LINE__, F.sc >>= Ius[x_5], (SCHAR)4);
	Ius[x_5] = 12; F.sc = 1;
	Ius[x_5] >>= F.sc;
	iequals(__LINE__, Ius[x_5], (USHORT)6);
	Ius[x_5] = 12; F.sc = 1;
	iequals(__LINE__, Ius[x_5] >>= F.sc, (USHORT)6);
#endif
#if ANSI
	F.sc = 8; Iui[x_6] = 1;
	F.sc >>= Iui[x_6];
	iequals(__LINE__, F.sc, (SCHAR)4);
	F.sc = 8; Iui[x_6] = 1;
	iequals(__LINE__, F.sc >>= Iui[x_6], (SCHAR)4);
	Iui[x_6] = 13; F.sc = 1;
	Iui[x_6] >>= F.sc;
	iequals(__LINE__, Iui[x_6], (UINT)6);
	Iui[x_6] = 13; F.sc = 1;
	iequals(__LINE__, Iui[x_6] >>= F.sc, (UINT)6);
#endif
#if ANSI
	F.sc = 8; Il[x_7] = 1;
	F.sc >>= Il[x_7];
	iequals(__LINE__, F.sc, (SCHAR)4);
	F.sc = 8; Il[x_7] = 1;
	iequals(__LINE__, F.sc >>= Il[x_7], (SCHAR)4);
	Il[x_7] = 14; F.sc = 1;
	Il[x_7] >>= F.sc;
	lequals(__LINE__, Il[x_7], (LONG)7L);
	Il[x_7] = 14; F.sc = 1;
	lequals(__LINE__, Il[x_7] >>= F.sc, (LONG)7L);
#endif
#if ANSI
	F.sc = 8; Iul[x_8] = 1;
	F.sc >>= Iul[x_8];
	iequals(__LINE__, F.sc, (SCHAR)4);
	F.sc = 8; Iul[x_8] = 1;
	iequals(__LINE__, F.sc >>= Iul[x_8], (SCHAR)4);
	Iul[x_8] = 15; F.sc = 1;
	Iul[x_8] >>= F.sc;
	lequals(__LINE__, Iul[x_8], (ULONG)7L);
	Iul[x_8] = 15; F.sc = 1;
	lequals(__LINE__, Iul[x_8] >>= F.sc, (ULONG)7L);
#endif
	F.s = 9; Ic[x_0] = 1;
	F.s >>= Ic[x_0];
	iequals(__LINE__, F.s, (SHORT)4);
	F.s = 9; Ic[x_0] = 1;
	iequals(__LINE__, F.s >>= Ic[x_0], (SHORT)4);
	Ic[x_0] = 7; F.s = 1;
	Ic[x_0] >>= F.s;
	iequals(__LINE__, Ic[x_0], (CHAR)3);
	Ic[x_0] = 7; F.s = 1;
	iequals(__LINE__, Ic[x_0] >>= F.s, (CHAR)3);
#if ANSI
	F.s = 9; Isc[x_1] = 1;
	F.s >>= Isc[x_1];
	iequals(__LINE__, F.s, (SHORT)4);
	F.s = 9; Isc[x_1] = 1;
	iequals(__LINE__, F.s >>= Isc[x_1], (SHORT)4);
	Isc[x_1] = 8; F.s = 1;
	Isc[x_1] >>= F.s;
	iequals(__LINE__, Isc[x_1], (SCHAR)4);
	Isc[x_1] = 8; F.s = 1;
	iequals(__LINE__, Isc[x_1] >>= F.s, (SCHAR)4);
#endif
	F.s = 9; Is[x_2] = 1;
	F.s >>= Is[x_2];
	iequals(__LINE__, F.s, (SHORT)4);
	F.s = 9; Is[x_2] = 1;
	iequals(__LINE__, F.s >>= Is[x_2], (SHORT)4);
	Is[x_2] = 9; F.s = 1;
	Is[x_2] >>= F.s;
	iequals(__LINE__, Is[x_2], (SHORT)4);
	Is[x_2] = 9; F.s = 1;
	iequals(__LINE__, Is[x_2] >>= F.s, (SHORT)4);
	F.s = 9; Ii[x_3] = 1;
	F.s >>= Ii[x_3];
	iequals(__LINE__, F.s, (SHORT)4);
	F.s = 9; Ii[x_3] = 1;
	iequals(__LINE__, F.s >>= Ii[x_3], (SHORT)4);
	Ii[x_3] = 10; F.s = 1;
	Ii[x_3] >>= F.s;
	iequals(__LINE__, Ii[x_3], (INT)5);
	Ii[x_3] = 10; F.s = 1;
	iequals(__LINE__, Ii[x_3] >>= F.s, (INT)5);
	F.s = 9; Iuc[x_4] = 1;
	F.s >>= Iuc[x_4];
	iequals(__LINE__, F.s, (SHORT)4);
	F.s = 9; Iuc[x_4] = 1;
	iequals(__LINE__, F.s >>= Iuc[x_4], (SHORT)4);
	Iuc[x_4] = 11; F.s = 1;
	Iuc[x_4] >>= F.s;
	iequals(__LINE__, Iuc[x_4], (UCHAR)5);
	Iuc[x_4] = 11; F.s = 1;
	iequals(__LINE__, Iuc[x_4] >>= F.s, (UCHAR)5);
	F.s = 9; Ius[x_5] = 1;
	F.s >>= Ius[x_5];
	iequals(__LINE__, F.s, (SHORT)4);
	F.s = 9; Ius[x_5] = 1;
	iequals(__LINE__, F.s >>= Ius[x_5], (SHORT)4);
	Ius[x_5] = 12; F.s = 1;
	Ius[x_5] >>= F.s;
	iequals(__LINE__, Ius[x_5], (USHORT)6);
	Ius[x_5] = 12; F.s = 1;
	iequals(__LINE__, Ius[x_5] >>= F.s, (USHORT)6);
	F.s = 9; Iui[x_6] = 1;
	F.s >>= Iui[x_6];
	iequals(__LINE__, F.s, (SHORT)4);
	F.s = 9; Iui[x_6] = 1;
	iequals(__LINE__, F.s >>= Iui[x_6], (SHORT)4);
	Iui[x_6] = 13; F.s = 1;
	Iui[x_6] >>= F.s;
	iequals(__LINE__, Iui[x_6], (UINT)6);
	Iui[x_6] = 13; F.s = 1;
	iequals(__LINE__, Iui[x_6] >>= F.s, (UINT)6);
	F.s = 9; Il[x_7] = 1;
	F.s >>= Il[x_7];
	iequals(__LINE__, F.s, (SHORT)4);
	F.s = 9; Il[x_7] = 1;
	iequals(__LINE__, F.s >>= Il[x_7], (SHORT)4);
	Il[x_7] = 14; F.s = 1;
	Il[x_7] >>= F.s;
	lequals(__LINE__, Il[x_7], (LONG)7L);
	Il[x_7] = 14; F.s = 1;
	lequals(__LINE__, Il[x_7] >>= F.s, (LONG)7L);
	F.s = 9; Iul[x_8] = 1;
	F.s >>= Iul[x_8];
	iequals(__LINE__, F.s, (SHORT)4);
	F.s = 9; Iul[x_8] = 1;
	iequals(__LINE__, F.s >>= Iul[x_8], (SHORT)4);
	Iul[x_8] = 15; F.s = 1;
	Iul[x_8] >>= F.s;
	lequals(__LINE__, Iul[x_8], (ULONG)7L);
	Iul[x_8] = 15; F.s = 1;
	lequals(__LINE__, Iul[x_8] >>= F.s, (ULONG)7L);
	F.i = 10; Ic[x_0] = 1;
	F.i >>= Ic[x_0];
	iequals(__LINE__, F.i, (INT)5);
	F.i = 10; Ic[x_0] = 1;
	iequals(__LINE__, F.i >>= Ic[x_0], (INT)5);
	Ic[x_0] = 7; F.i = 1;
	Ic[x_0] >>= F.i;
	iequals(__LINE__, Ic[x_0], (CHAR)3);
	Ic[x_0] = 7; F.i = 1;
	iequals(__LINE__, Ic[x_0] >>= F.i, (CHAR)3);
#if ANSI
	F.i = 10; Isc[x_1] = 1;
	F.i >>= Isc[x_1];
	iequals(__LINE__, F.i, (INT)5);
	F.i = 10; Isc[x_1] = 1;
	iequals(__LINE__, F.i >>= Isc[x_1], (INT)5);
	Isc[x_1] = 8; F.i = 1;
	Isc[x_1] >>= F.i;
	iequals(__LINE__, Isc[x_1], (SCHAR)4);
	Isc[x_1] = 8; F.i = 1;
	iequals(__LINE__, Isc[x_1] >>= F.i, (SCHAR)4);
#endif
	F.i = 10; Is[x_2] = 1;
	F.i >>= Is[x_2];
	iequals(__LINE__, F.i, (INT)5);
	F.i = 10; Is[x_2] = 1;
	iequals(__LINE__, F.i >>= Is[x_2], (INT)5);
	Is[x_2] = 9; F.i = 1;
	Is[x_2] >>= F.i;
	iequals(__LINE__, Is[x_2], (SHORT)4);
	Is[x_2] = 9; F.i = 1;
	iequals(__LINE__, Is[x_2] >>= F.i, (SHORT)4);
	F.i = 10; Ii[x_3] = 1;
	F.i >>= Ii[x_3];
	iequals(__LINE__, F.i, (INT)5);
	F.i = 10; Ii[x_3] = 1;
	iequals(__LINE__, F.i >>= Ii[x_3], (INT)5);
	Ii[x_3] = 10; F.i = 1;
	Ii[x_3] >>= F.i;
	iequals(__LINE__, Ii[x_3], (INT)5);
	Ii[x_3] = 10; F.i = 1;
	iequals(__LINE__, Ii[x_3] >>= F.i, (INT)5);
	F.i = 10; Iuc[x_4] = 1;
	F.i >>= Iuc[x_4];
	iequals(__LINE__, F.i, (INT)5);
	F.i = 10; Iuc[x_4] = 1;
	iequals(__LINE__, F.i >>= Iuc[x_4], (INT)5);
	Iuc[x_4] = 11; F.i = 1;
	Iuc[x_4] >>= F.i;
	iequals(__LINE__, Iuc[x_4], (UCHAR)5);
	Iuc[x_4] = 11; F.i = 1;
	iequals(__LINE__, Iuc[x_4] >>= F.i, (UCHAR)5);
	F.i = 10; Ius[x_5] = 1;
	F.i >>= Ius[x_5];
	iequals(__LINE__, F.i, (INT)5);
	F.i = 10; Ius[x_5] = 1;
	iequals(__LINE__, F.i >>= Ius[x_5], (INT)5);
	Ius[x_5] = 12; F.i = 1;
	Ius[x_5] >>= F.i;
	iequals(__LINE__, Ius[x_5], (USHORT)6);
	Ius[x_5] = 12; F.i = 1;
	iequals(__LINE__, Ius[x_5] >>= F.i, (USHORT)6);
	F.i = 10; Iui[x_6] = 1;
	F.i >>= Iui[x_6];
	iequals(__LINE__, F.i, (INT)5);
	F.i = 10; Iui[x_6] = 1;
	iequals(__LINE__, F.i >>= Iui[x_6], (INT)5);
	Iui[x_6] = 13; F.i = 1;
	Iui[x_6] >>= F.i;
	iequals(__LINE__, Iui[x_6], (UINT)6);
	Iui[x_6] = 13; F.i = 1;
	iequals(__LINE__, Iui[x_6] >>= F.i, (UINT)6);
	F.i = 10; Il[x_7] = 1;
	F.i >>= Il[x_7];
	iequals(__LINE__, F.i, (INT)5);
	F.i = 10; Il[x_7] = 1;
	iequals(__LINE__, F.i >>= Il[x_7], (INT)5);
	Il[x_7] = 14; F.i = 1;
	Il[x_7] >>= F.i;
	lequals(__LINE__, Il[x_7], (LONG)7L);
	Il[x_7] = 14; F.i = 1;
	lequals(__LINE__, Il[x_7] >>= F.i, (LONG)7L);
	F.i = 10; Iul[x_8] = 1;
	F.i >>= Iul[x_8];
	iequals(__LINE__, F.i, (INT)5);
	F.i = 10; Iul[x_8] = 1;
	iequals(__LINE__, F.i >>= Iul[x_8], (INT)5);
	Iul[x_8] = 15; F.i = 1;
	Iul[x_8] >>= F.i;
	lequals(__LINE__, Iul[x_8], (ULONG)7L);
	Iul[x_8] = 15; F.i = 1;
	lequals(__LINE__, Iul[x_8] >>= F.i, (ULONG)7L);
	F.uc = 11; Ic[x_0] = 1;
	F.uc >>= Ic[x_0];
	iequals(__LINE__, F.uc, (UCHAR)5);
	F.uc = 11; Ic[x_0] = 1;
	iequals(__LINE__, F.uc >>= Ic[x_0], (UCHAR)5);
	Ic[x_0] = 7; F.uc = 1;
	Ic[x_0] >>= F.uc;
	iequals(__LINE__, Ic[x_0], (CHAR)3);
	Ic[x_0] = 7; F.uc = 1;
	iequals(__LINE__, Ic[x_0] >>= F.uc, (CHAR)3);
#if ANSI
	F.uc = 11; Isc[x_1] = 1;
	F.uc >>= Isc[x_1];
	iequals(__LINE__, F.uc, (UCHAR)5);
	F.uc = 11; Isc[x_1] = 1;
	iequals(__LINE__, F.uc >>= Isc[x_1], (UCHAR)5);
	Isc[x_1] = 8; F.uc = 1;
	Isc[x_1] >>= F.uc;
	iequals(__LINE__, Isc[x_1], (SCHAR)4);
	Isc[x_1] = 8; F.uc = 1;
	iequals(__LINE__, Isc[x_1] >>= F.uc, (SCHAR)4);
#endif
	F.uc = 11; Is[x_2] = 1;
	F.uc >>= Is[x_2];
	iequals(__LINE__, F.uc, (UCHAR)5);
	F.uc = 11; Is[x_2] = 1;
	iequals(__LINE__, F.uc >>= Is[x_2], (UCHAR)5);
	Is[x_2] = 9; F.uc = 1;
	Is[x_2] >>= F.uc;
	iequals(__LINE__, Is[x_2], (SHORT)4);
	Is[x_2] = 9; F.uc = 1;
	iequals(__LINE__, Is[x_2] >>= F.uc, (SHORT)4);
	F.uc = 11; Ii[x_3] = 1;
	F.uc >>= Ii[x_3];
	iequals(__LINE__, F.uc, (UCHAR)5);
	F.uc = 11; Ii[x_3] = 1;
	iequals(__LINE__, F.uc >>= Ii[x_3], (UCHAR)5);
	Ii[x_3] = 10; F.uc = 1;
	Ii[x_3] >>= F.uc;
	iequals(__LINE__, Ii[x_3], (INT)5);
	Ii[x_3] = 10; F.uc = 1;
	iequals(__LINE__, Ii[x_3] >>= F.uc, (INT)5);
	F.uc = 11; Iuc[x_4] = 1;
	F.uc >>= Iuc[x_4];
	iequals(__LINE__, F.uc, (UCHAR)5);
	F.uc = 11; Iuc[x_4] = 1;
	iequals(__LINE__, F.uc >>= Iuc[x_4], (UCHAR)5);
	Iuc[x_4] = 11; F.uc = 1;
	Iuc[x_4] >>= F.uc;
	iequals(__LINE__, Iuc[x_4], (UCHAR)5);
	Iuc[x_4] = 11; F.uc = 1;
	iequals(__LINE__, Iuc[x_4] >>= F.uc, (UCHAR)5);
	F.uc = 11; Ius[x_5] = 1;
	F.uc >>= Ius[x_5];
	iequals(__LINE__, F.uc, (UCHAR)5);
	F.uc = 11; Ius[x_5] = 1;
	iequals(__LINE__, F.uc >>= Ius[x_5], (UCHAR)5);
	Ius[x_5] = 12; F.uc = 1;
	Ius[x_5] >>= F.uc;
	iequals(__LINE__, Ius[x_5], (USHORT)6);
	Ius[x_5] = 12; F.uc = 1;
	iequals(__LINE__, Ius[x_5] >>= F.uc, (USHORT)6);
	F.uc = 11; Iui[x_6] = 1;
	F.uc >>= Iui[x_6];
	iequals(__LINE__, F.uc, (UCHAR)5);
	F.uc = 11; Iui[x_6] = 1;
	iequals(__LINE__, F.uc >>= Iui[x_6], (UCHAR)5);
	Iui[x_6] = 13; F.uc = 1;
	Iui[x_6] >>= F.uc;
	iequals(__LINE__, Iui[x_6], (UINT)6);
	Iui[x_6] = 13; F.uc = 1;
	iequals(__LINE__, Iui[x_6] >>= F.uc, (UINT)6);
	F.uc = 11; Il[x_7] = 1;
	F.uc >>= Il[x_7];
	iequals(__LINE__, F.uc, (UCHAR)5);
	F.uc = 11; Il[x_7] = 1;
	iequals(__LINE__, F.uc >>= Il[x_7], (UCHAR)5);
	Il[x_7] = 14; F.uc = 1;
	Il[x_7] >>= F.uc;
	lequals(__LINE__, Il[x_7], (LONG)7L);
	Il[x_7] = 14; F.uc = 1;
	lequals(__LINE__, Il[x_7] >>= F.uc, (LONG)7L);
	F.uc = 11; Iul[x_8] = 1;
	F.uc >>= Iul[x_8];
	iequals(__LINE__, F.uc, (UCHAR)5);
	F.uc = 11; Iul[x_8] = 1;
	iequals(__LINE__, F.uc >>= Iul[x_8], (UCHAR)5);
	Iul[x_8] = 15; F.uc = 1;
	Iul[x_8] >>= F.uc;
	lequals(__LINE__, Iul[x_8], (ULONG)7L);
	Iul[x_8] = 15; F.uc = 1;
	lequals(__LINE__, Iul[x_8] >>= F.uc, (ULONG)7L);
	F.us = 12; Ic[x_0] = 1;
	F.us >>= Ic[x_0];
	iequals(__LINE__, F.us, (USHORT)6);
	F.us = 12; Ic[x_0] = 1;
	iequals(__LINE__, F.us >>= Ic[x_0], (USHORT)6);
	Ic[x_0] = 7; F.us = 1;
	Ic[x_0] >>= F.us;
	iequals(__LINE__, Ic[x_0], (CHAR)3);
	Ic[x_0] = 7; F.us = 1;
	iequals(__LINE__, Ic[x_0] >>= F.us, (CHAR)3);
#if ANSI
	F.us = 12; Isc[x_1] = 1;
	F.us >>= Isc[x_1];
	iequals(__LINE__, F.us, (USHORT)6);
	F.us = 12; Isc[x_1] = 1;
	iequals(__LINE__, F.us >>= Isc[x_1], (USHORT)6);
	Isc[x_1] = 8; F.us = 1;
	Isc[x_1] >>= F.us;
	iequals(__LINE__, Isc[x_1], (SCHAR)4);
	Isc[x_1] = 8; F.us = 1;
	iequals(__LINE__, Isc[x_1] >>= F.us, (SCHAR)4);
#endif
	F.us = 12; Is[x_2] = 1;
	F.us >>= Is[x_2];
	iequals(__LINE__, F.us, (USHORT)6);
	F.us = 12; Is[x_2] = 1;
	iequals(__LINE__, F.us >>= Is[x_2], (USHORT)6);
	Is[x_2] = 9; F.us = 1;
	Is[x_2] >>= F.us;
	iequals(__LINE__, Is[x_2], (SHORT)4);
	Is[x_2] = 9; F.us = 1;
	iequals(__LINE__, Is[x_2] >>= F.us, (SHORT)4);
	F.us = 12; Ii[x_3] = 1;
	F.us >>= Ii[x_3];
	iequals(__LINE__, F.us, (USHORT)6);
	F.us = 12; Ii[x_3] = 1;
	iequals(__LINE__, F.us >>= Ii[x_3], (USHORT)6);
	Ii[x_3] = 10; F.us = 1;
	Ii[x_3] >>= F.us;
	iequals(__LINE__, Ii[x_3], (INT)5);
	Ii[x_3] = 10; F.us = 1;
	iequals(__LINE__, Ii[x_3] >>= F.us, (INT)5);
	F.us = 12; Iuc[x_4] = 1;
	F.us >>= Iuc[x_4];
	iequals(__LINE__, F.us, (USHORT)6);
	F.us = 12; Iuc[x_4] = 1;
	iequals(__LINE__, F.us >>= Iuc[x_4], (USHORT)6);
	Iuc[x_4] = 11; F.us = 1;
	Iuc[x_4] >>= F.us;
	iequals(__LINE__, Iuc[x_4], (UCHAR)5);
	Iuc[x_4] = 11; F.us = 1;
	iequals(__LINE__, Iuc[x_4] >>= F.us, (UCHAR)5);
	F.us = 12; Ius[x_5] = 1;
	F.us >>= Ius[x_5];
	iequals(__LINE__, F.us, (USHORT)6);
	F.us = 12; Ius[x_5] = 1;
	iequals(__LINE__, F.us >>= Ius[x_5], (USHORT)6);
	Ius[x_5] = 12; F.us = 1;
	Ius[x_5] >>= F.us;
	iequals(__LINE__, Ius[x_5], (USHORT)6);
	Ius[x_5] = 12; F.us = 1;
	iequals(__LINE__, Ius[x_5] >>= F.us, (USHORT)6);
	F.us = 12; Iui[x_6] = 1;
	F.us >>= Iui[x_6];
	iequals(__LINE__, F.us, (USHORT)6);
	F.us = 12; Iui[x_6] = 1;
	iequals(__LINE__, F.us >>= Iui[x_6], (USHORT)6);
	Iui[x_6] = 13; F.us = 1;
	Iui[x_6] >>= F.us;
	iequals(__LINE__, Iui[x_6], (UINT)6);
	Iui[x_6] = 13; F.us = 1;
	iequals(__LINE__, Iui[x_6] >>= F.us, (UINT)6);
	F.us = 12; Il[x_7] = 1;
	F.us >>= Il[x_7];
	iequals(__LINE__, F.us, (USHORT)6);
	F.us = 12; Il[x_7] = 1;
	iequals(__LINE__, F.us >>= Il[x_7], (USHORT)6);
	Il[x_7] = 14; F.us = 1;
	Il[x_7] >>= F.us;
	lequals(__LINE__, Il[x_7], (LONG)7L);
	Il[x_7] = 14; F.us = 1;
	lequals(__LINE__, Il[x_7] >>= F.us, (LONG)7L);
	F.us = 12; Iul[x_8] = 1;
	F.us >>= Iul[x_8];
	iequals(__LINE__, F.us, (USHORT)6);
	F.us = 12; Iul[x_8] = 1;
	iequals(__LINE__, F.us >>= Iul[x_8], (USHORT)6);
	Iul[x_8] = 15; F.us = 1;
	Iul[x_8] >>= F.us;
	lequals(__LINE__, Iul[x_8], (ULONG)7L);
	Iul[x_8] = 15; F.us = 1;
	lequals(__LINE__, Iul[x_8] >>= F.us, (ULONG)7L);
	F.ui = 13; Ic[x_0] = 1;
	F.ui >>= Ic[x_0];
	iequals(__LINE__, F.ui, (UINT)6);
	F.ui = 13; Ic[x_0] = 1;
	iequals(__LINE__, F.ui >>= Ic[x_0], (UINT)6);
	Ic[x_0] = 7; F.ui = 1;
	Ic[x_0] >>= F.ui;
	iequals(__LINE__, Ic[x_0], (CHAR)3);
	Ic[x_0] = 7; F.ui = 1;
	iequals(__LINE__, Ic[x_0] >>= F.ui, (CHAR)3);
#if ANSI
	F.ui = 13; Isc[x_1] = 1;
	F.ui >>= Isc[x_1];
	iequals(__LINE__, F.ui, (UINT)6);
	F.ui = 13; Isc[x_1] = 1;
	iequals(__LINE__, F.ui >>= Isc[x_1], (UINT)6);
	Isc[x_1] = 8; F.ui = 1;
	Isc[x_1] >>= F.ui;
	iequals(__LINE__, Isc[x_1], (SCHAR)4);
	Isc[x_1] = 8; F.ui = 1;
	iequals(__LINE__, Isc[x_1] >>= F.ui, (SCHAR)4);
#endif
	F.ui = 13; Is[x_2] = 1;
	F.ui >>= Is[x_2];
	iequals(__LINE__, F.ui, (UINT)6);
	F.ui = 13; Is[x_2] = 1;
	iequals(__LINE__, F.ui >>= Is[x_2], (UINT)6);
	Is[x_2] = 9; F.ui = 1;
	Is[x_2] >>= F.ui;
	iequals(__LINE__, Is[x_2], (SHORT)4);
	Is[x_2] = 9; F.ui = 1;
	iequals(__LINE__, Is[x_2] >>= F.ui, (SHORT)4);
	F.ui = 13; Ii[x_3] = 1;
	F.ui >>= Ii[x_3];
	iequals(__LINE__, F.ui, (UINT)6);
	F.ui = 13; Ii[x_3] = 1;
	iequals(__LINE__, F.ui >>= Ii[x_3], (UINT)6);
	Ii[x_3] = 10; F.ui = 1;
	Ii[x_3] >>= F.ui;
	iequals(__LINE__, Ii[x_3], (INT)5);
	Ii[x_3] = 10; F.ui = 1;
	iequals(__LINE__, Ii[x_3] >>= F.ui, (INT)5);
	F.ui = 13; Iuc[x_4] = 1;
	F.ui >>= Iuc[x_4];
	iequals(__LINE__, F.ui, (UINT)6);
	F.ui = 13; Iuc[x_4] = 1;
	iequals(__LINE__, F.ui >>= Iuc[x_4], (UINT)6);
	Iuc[x_4] = 11; F.ui = 1;
	Iuc[x_4] >>= F.ui;
	iequals(__LINE__, Iuc[x_4], (UCHAR)5);
	Iuc[x_4] = 11; F.ui = 1;
	iequals(__LINE__, Iuc[x_4] >>= F.ui, (UCHAR)5);
	F.ui = 13; Ius[x_5] = 1;
	F.ui >>= Ius[x_5];
	iequals(__LINE__, F.ui, (UINT)6);
	F.ui = 13; Ius[x_5] = 1;
	iequals(__LINE__, F.ui >>= Ius[x_5], (UINT)6);
	Ius[x_5] = 12; F.ui = 1;
	Ius[x_5] >>= F.ui;
	iequals(__LINE__, Ius[x_5], (USHORT)6);
	Ius[x_5] = 12; F.ui = 1;
	iequals(__LINE__, Ius[x_5] >>= F.ui, (USHORT)6);
	F.ui = 13; Iui[x_6] = 1;
	F.ui >>= Iui[x_6];
	iequals(__LINE__, F.ui, (UINT)6);
	F.ui = 13; Iui[x_6] = 1;
	iequals(__LINE__, F.ui >>= Iui[x_6], (UINT)6);
	Iui[x_6] = 13; F.ui = 1;
	Iui[x_6] >>= F.ui;
	iequals(__LINE__, Iui[x_6], (UINT)6);
	Iui[x_6] = 13; F.ui = 1;
	iequals(__LINE__, Iui[x_6] >>= F.ui, (UINT)6);
	F.ui = 13; Il[x_7] = 1;
	F.ui >>= Il[x_7];
	iequals(__LINE__, F.ui, (UINT)6);
	F.ui = 13; Il[x_7] = 1;
	iequals(__LINE__, F.ui >>= Il[x_7], (UINT)6);
	Il[x_7] = 14; F.ui = 1;
	Il[x_7] >>= F.ui;
	lequals(__LINE__, Il[x_7], (LONG)7L);
	Il[x_7] = 14; F.ui = 1;
	lequals(__LINE__, Il[x_7] >>= F.ui, (LONG)7L);
	F.ui = 13; Iul[x_8] = 1;
	F.ui >>= Iul[x_8];
	iequals(__LINE__, F.ui, (UINT)6);
	F.ui = 13; Iul[x_8] = 1;
	iequals(__LINE__, F.ui >>= Iul[x_8], (UINT)6);
	Iul[x_8] = 15; F.ui = 1;
	Iul[x_8] >>= F.ui;
	lequals(__LINE__, Iul[x_8], (ULONG)7L);
	Iul[x_8] = 15; F.ui = 1;
	lequals(__LINE__, Iul[x_8] >>= F.ui, (ULONG)7L);
	F.l = 14; Ic[x_0] = 1;
	F.l >>= Ic[x_0];
	lequals(__LINE__, F.l, (LONG)7L);
	F.l = 14; Ic[x_0] = 1;
	lequals(__LINE__, F.l >>= Ic[x_0], (LONG)7L);
	Ic[x_0] = 7; F.l = 1;
	Ic[x_0] >>= F.l;
	iequals(__LINE__, Ic[x_0], (CHAR)3);
	Ic[x_0] = 7; F.l = 1;
	iequals(__LINE__, Ic[x_0] >>= F.l, (CHAR)3);
#if ANSI
	F.l = 14; Isc[x_1] = 1;
	F.l >>= Isc[x_1];
	lequals(__LINE__, F.l, (LONG)7L);
	F.l = 14; Isc[x_1] = 1;
	lequals(__LINE__, F.l >>= Isc[x_1], (LONG)7L);
	Isc[x_1] = 8; F.l = 1;
	Isc[x_1] >>= F.l;
	iequals(__LINE__, Isc[x_1], (SCHAR)4);
	Isc[x_1] = 8; F.l = 1;
	iequals(__LINE__, Isc[x_1] >>= F.l, (SCHAR)4);
#endif
	F.l = 14; Is[x_2] = 1;
	F.l >>= Is[x_2];
	lequals(__LINE__, F.l, (LONG)7L);
	F.l = 14; Is[x_2] = 1;
	lequals(__LINE__, F.l >>= Is[x_2], (LONG)7L);
	Is[x_2] = 9; F.l = 1;
	Is[x_2] >>= F.l;
	iequals(__LINE__, Is[x_2], (SHORT)4);
	Is[x_2] = 9; F.l = 1;
	iequals(__LINE__, Is[x_2] >>= F.l, (SHORT)4);
	F.l = 14; Ii[x_3] = 1;
	F.l >>= Ii[x_3];
	lequals(__LINE__, F.l, (LONG)7L);
	F.l = 14; Ii[x_3] = 1;
	lequals(__LINE__, F.l >>= Ii[x_3], (LONG)7L);
	Ii[x_3] = 10; F.l = 1;
	Ii[x_3] >>= F.l;
	iequals(__LINE__, Ii[x_3], (INT)5);
	Ii[x_3] = 10; F.l = 1;
	iequals(__LINE__, Ii[x_3] >>= F.l, (INT)5);
	F.l = 14; Iuc[x_4] = 1;
	F.l >>= Iuc[x_4];
	lequals(__LINE__, F.l, (LONG)7L);
	F.l = 14; Iuc[x_4] = 1;
	lequals(__LINE__, F.l >>= Iuc[x_4], (LONG)7L);
	Iuc[x_4] = 11; F.l = 1;
	Iuc[x_4] >>= F.l;
	iequals(__LINE__, Iuc[x_4], (UCHAR)5);
	Iuc[x_4] = 11; F.l = 1;
	iequals(__LINE__, Iuc[x_4] >>= F.l, (UCHAR)5);
	F.l = 14; Ius[x_5] = 1;
	F.l >>= Ius[x_5];
	lequals(__LINE__, F.l, (LONG)7L);
	F.l = 14; Ius[x_5] = 1;
	lequals(__LINE__, F.l >>= Ius[x_5], (LONG)7L);
	Ius[x_5] = 12; F.l = 1;
	Ius[x_5] >>= F.l;
	iequals(__LINE__, Ius[x_5], (USHORT)6);
	Ius[x_5] = 12; F.l = 1;
	iequals(__LINE__, Ius[x_5] >>= F.l, (USHORT)6);
	F.l = 14; Iui[x_6] = 1;
	F.l >>= Iui[x_6];
	lequals(__LINE__, F.l, (LONG)7L);
	F.l = 14; Iui[x_6] = 1;
	lequals(__LINE__, F.l >>= Iui[x_6], (LONG)7L);
	Iui[x_6] = 13; F.l = 1;
	Iui[x_6] >>= F.l;
	iequals(__LINE__, Iui[x_6], (UINT)6);
	Iui[x_6] = 13; F.l = 1;
	iequals(__LINE__, Iui[x_6] >>= F.l, (UINT)6);
	F.l = 14; Il[x_7] = 1;
	F.l >>= Il[x_7];
	lequals(__LINE__, F.l, (LONG)7L);
	F.l = 14; Il[x_7] = 1;
	lequals(__LINE__, F.l >>= Il[x_7], (LONG)7L);
	Il[x_7] = 14; F.l = 1;
	Il[x_7] >>= F.l;
	lequals(__LINE__, Il[x_7], (LONG)7L);
	Il[x_7] = 14; F.l = 1;
	lequals(__LINE__, Il[x_7] >>= F.l, (LONG)7L);
	F.l = 14; Iul[x_8] = 1;
	F.l >>= Iul[x_8];
	lequals(__LINE__, F.l, (LONG)7L);
	F.l = 14; Iul[x_8] = 1;
	lequals(__LINE__, F.l >>= Iul[x_8], (LONG)7L);
	Iul[x_8] = 15; F.l = 1;
	Iul[x_8] >>= F.l;
	lequals(__LINE__, Iul[x_8], (ULONG)7L);
	Iul[x_8] = 15; F.l = 1;
	lequals(__LINE__, Iul[x_8] >>= F.l, (ULONG)7L);
	F.ul = 15; Ic[x_0] = 1;
	F.ul >>= Ic[x_0];
	lequals(__LINE__, F.ul, (ULONG)7L);
	F.ul = 15; Ic[x_0] = 1;
	lequals(__LINE__, F.ul >>= Ic[x_0], (ULONG)7L);
	Ic[x_0] = 7; F.ul = 1;
	Ic[x_0] >>= F.ul;
	iequals(__LINE__, Ic[x_0], (CHAR)3);
	Ic[x_0] = 7; F.ul = 1;
	iequals(__LINE__, Ic[x_0] >>= F.ul, (CHAR)3);
#if ANSI
	F.ul = 15; Isc[x_1] = 1;
	F.ul >>= Isc[x_1];
	lequals(__LINE__, F.ul, (ULONG)7L);
	F.ul = 15; Isc[x_1] = 1;
	lequals(__LINE__, F.ul >>= Isc[x_1], (ULONG)7L);
	Isc[x_1] = 8; F.ul = 1;
	Isc[x_1] >>= F.ul;
	iequals(__LINE__, Isc[x_1], (SCHAR)4);
	Isc[x_1] = 8; F.ul = 1;
	iequals(__LINE__, Isc[x_1] >>= F.ul, (SCHAR)4);
#endif
	F.ul = 15; Is[x_2] = 1;
	F.ul >>= Is[x_2];
	lequals(__LINE__, F.ul, (ULONG)7L);
	F.ul = 15; Is[x_2] = 1;
	lequals(__LINE__, F.ul >>= Is[x_2], (ULONG)7L);
	Is[x_2] = 9; F.ul = 1;
	Is[x_2] >>= F.ul;
	iequals(__LINE__, Is[x_2], (SHORT)4);
	Is[x_2] = 9; F.ul = 1;
	iequals(__LINE__, Is[x_2] >>= F.ul, (SHORT)4);
	F.ul = 15; Ii[x_3] = 1;
	F.ul >>= Ii[x_3];
	lequals(__LINE__, F.ul, (ULONG)7L);
	F.ul = 15; Ii[x_3] = 1;
	lequals(__LINE__, F.ul >>= Ii[x_3], (ULONG)7L);
	Ii[x_3] = 10; F.ul = 1;
	Ii[x_3] >>= F.ul;
	iequals(__LINE__, Ii[x_3], (INT)5);
	Ii[x_3] = 10; F.ul = 1;
	iequals(__LINE__, Ii[x_3] >>= F.ul, (INT)5);
	F.ul = 15; Iuc[x_4] = 1;
	F.ul >>= Iuc[x_4];
	lequals(__LINE__, F.ul, (ULONG)7L);
	F.ul = 15; Iuc[x_4] = 1;
	lequals(__LINE__, F.ul >>= Iuc[x_4], (ULONG)7L);
	Iuc[x_4] = 11; F.ul = 1;
	Iuc[x_4] >>= F.ul;
	iequals(__LINE__, Iuc[x_4], (UCHAR)5);
	Iuc[x_4] = 11; F.ul = 1;
	iequals(__LINE__, Iuc[x_4] >>= F.ul, (UCHAR)5);
	F.ul = 15; Ius[x_5] = 1;
	F.ul >>= Ius[x_5];
	lequals(__LINE__, F.ul, (ULONG)7L);
	F.ul = 15; Ius[x_5] = 1;
	lequals(__LINE__, F.ul >>= Ius[x_5], (ULONG)7L);
	Ius[x_5] = 12; F.ul = 1;
	Ius[x_5] >>= F.ul;
	iequals(__LINE__, Ius[x_5], (USHORT)6);
	Ius[x_5] = 12; F.ul = 1;
	iequals(__LINE__, Ius[x_5] >>= F.ul, (USHORT)6);
	F.ul = 15; Iui[x_6] = 1;
	F.ul >>= Iui[x_6];
	lequals(__LINE__, F.ul, (ULONG)7L);
	F.ul = 15; Iui[x_6] = 1;
	lequals(__LINE__, F.ul >>= Iui[x_6], (ULONG)7L);
	Iui[x_6] = 13; F.ul = 1;
	Iui[x_6] >>= F.ul;
	iequals(__LINE__, Iui[x_6], (UINT)6);
	Iui[x_6] = 13; F.ul = 1;
	iequals(__LINE__, Iui[x_6] >>= F.ul, (UINT)6);
	F.ul = 15; Il[x_7] = 1;
	F.ul >>= Il[x_7];
	lequals(__LINE__, F.ul, (ULONG)7L);
	F.ul = 15; Il[x_7] = 1;
	lequals(__LINE__, F.ul >>= Il[x_7], (ULONG)7L);
	Il[x_7] = 14; F.ul = 1;
	Il[x_7] >>= F.ul;
	lequals(__LINE__, Il[x_7], (LONG)7L);
	Il[x_7] = 14; F.ul = 1;
	lequals(__LINE__, Il[x_7] >>= F.ul, (LONG)7L);
	F.ul = 15; Iul[x_8] = 1;
	F.ul >>= Iul[x_8];
	lequals(__LINE__, F.ul, (ULONG)7L);
	F.ul = 15; Iul[x_8] = 1;
	lequals(__LINE__, F.ul >>= Iul[x_8], (ULONG)7L);
	Iul[x_8] = 15; F.ul = 1;
	Iul[x_8] >>= F.ul;
	lequals(__LINE__, Iul[x_8], (ULONG)7L);
	Iul[x_8] = 15; F.ul = 1;
	lequals(__LINE__, Iul[x_8] >>= F.ul, (ULONG)7L);
	}}
	return 	report(Filename);
	}
