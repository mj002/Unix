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
	auto CHAR Bc = 7;
	auto CHAR *pBc = &Bc;
#if ANSI
	auto SCHAR Bsc = 8;
	auto SCHAR *pBsc = &Bsc;
#endif
	auto SHORT Bs = 9;
	auto SHORT *pBs = &Bs;
	auto INT Bi = 10;
	auto INT *pBi = &Bi;
	auto UCHAR Buc = 11;
	auto UCHAR *pBuc = &Buc;
	auto USHORT Bus = 12;
	auto USHORT *pBus = &Bus;
	auto UINT Bui = 13;
	auto UINT *pBui = &Bui;
	auto LONG Bl = 14;
	auto LONG *pBl = &Bl;
	auto ULONG Bul = 15;
	auto ULONG *pBul = &Bul;
	auto FLOAT Bf = 16;
	auto FLOAT *pBf = &Bf;
	auto DOUBLE Bd = 17;
	auto DOUBLE *pBd = &Bd;
#if ANSI
	auto LDOUBLE Bld = 18;
	auto LDOUBLE *pBld = &Bld;
#endif
	{
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
		} G, *pG = &G;
	pG->c = 7;
#if ANSI
	pG->sc = 8;
#endif
	pG->s = 9;
	pG->i = 10;
	pG->uc = 11;
	pG->us = 12;
	pG->ui = 13;
	pG->l = 14;
	pG->ul = 15;
	pG->f = 16;
	pG->d = 17;
#if ANSI
	pG->ld = 18;
#endif
	{
	int true = 1, false = 0;
	Filename =  " auto pscalar1 auto pstruct1 remeq ";
	*pBc = 7; pG->c = 7;
	*pBc %= pG->c;
	iequals(__LINE__, *pBc, (CHAR)0);
	*pBc = 7;
	iequals(__LINE__, *pBc %= pG->c, (CHAR)0);
	pG->c = 7; *pBc = 7;
	pG->c %= *pBc;
	iequals(__LINE__, pG->c, (CHAR)0);
	pG->c = 7;
	iequals(__LINE__, pG->c %= *pBc, (CHAR)0);
#if ANSI
	*pBc = 7; pG->sc = 8;
	*pBc %= pG->sc;
	iequals(__LINE__, *pBc, (CHAR)7);
	*pBc = 7;
	iequals(__LINE__, *pBc %= pG->sc, (CHAR)7);
	pG->sc = 8; *pBc = 7;
	pG->sc %= *pBc;
	iequals(__LINE__, pG->sc, (SCHAR)1);
	pG->sc = 8;
	iequals(__LINE__, pG->sc %= *pBc, (SCHAR)1);
#endif
	*pBc = 7; pG->s = 9;
	*pBc %= pG->s;
	iequals(__LINE__, *pBc, (CHAR)7);
	*pBc = 7;
	iequals(__LINE__, *pBc %= pG->s, (CHAR)7);
	pG->s = 9; *pBc = 7;
	pG->s %= *pBc;
	iequals(__LINE__, pG->s, (SHORT)2);
	pG->s = 9;
	iequals(__LINE__, pG->s %= *pBc, (SHORT)2);
	*pBc = 7; pG->i = 10;
	*pBc %= pG->i;
	iequals(__LINE__, *pBc, (CHAR)7);
	*pBc = 7;
	iequals(__LINE__, *pBc %= pG->i, (CHAR)7);
	pG->i = 10; *pBc = 7;
	pG->i %= *pBc;
	iequals(__LINE__, pG->i, (INT)3);
	pG->i = 10;
	iequals(__LINE__, pG->i %= *pBc, (INT)3);
	*pBc = 7; pG->uc = 11;
	*pBc %= pG->uc;
	iequals(__LINE__, *pBc, (CHAR)7);
	*pBc = 7;
	iequals(__LINE__, *pBc %= pG->uc, (CHAR)7);
	pG->uc = 11; *pBc = 7;
	pG->uc %= *pBc;
	iequals(__LINE__, pG->uc, (UCHAR)4);
	pG->uc = 11;
	iequals(__LINE__, pG->uc %= *pBc, (UCHAR)4);
	*pBc = 7; pG->us = 12;
	*pBc %= pG->us;
	iequals(__LINE__, *pBc, (CHAR)7);
	*pBc = 7;
	iequals(__LINE__, *pBc %= pG->us, (CHAR)7);
	pG->us = 12; *pBc = 7;
	pG->us %= *pBc;
	iequals(__LINE__, pG->us, (USHORT)5);
	pG->us = 12;
	iequals(__LINE__, pG->us %= *pBc, (USHORT)5);
	*pBc = 7; pG->ui = 13;
	*pBc %= pG->ui;
	iequals(__LINE__, *pBc, (CHAR)7);
	*pBc = 7;
	iequals(__LINE__, *pBc %= pG->ui, (CHAR)7);
	pG->ui = 13; *pBc = 7;
	pG->ui %= *pBc;
	iequals(__LINE__, pG->ui, (UINT)6);
	pG->ui = 13;
	iequals(__LINE__, pG->ui %= *pBc, (UINT)6);
	*pBc = 7; pG->l = 14;
	*pBc %= pG->l;
	iequals(__LINE__, *pBc, (CHAR)7);
	*pBc = 7;
	iequals(__LINE__, *pBc %= pG->l, (CHAR)7);
	pG->l = 14; *pBc = 7;
	pG->l %= *pBc;
	lequals(__LINE__, pG->l, (LONG)0L);
	pG->l = 14;
	lequals(__LINE__, pG->l %= *pBc, (LONG)0L);
	*pBc = 7; pG->ul = 15;
	*pBc %= pG->ul;
	iequals(__LINE__, *pBc, (CHAR)7);
	*pBc = 7;
	iequals(__LINE__, *pBc %= pG->ul, (CHAR)7);
	pG->ul = 15; *pBc = 7;
	pG->ul %= *pBc;
	lequals(__LINE__, pG->ul, (ULONG)1L);
	pG->ul = 15;
	lequals(__LINE__, pG->ul %= *pBc, (ULONG)1L);
#if ANSI
	*pBsc = 8; pG->c = 7;
	*pBsc %= pG->c;
	iequals(__LINE__, *pBsc, (SCHAR)1);
	*pBsc = 8;
	iequals(__LINE__, *pBsc %= pG->c, (SCHAR)1);
	pG->c = 7; *pBsc = 8;
	pG->c %= *pBsc;
	iequals(__LINE__, pG->c, (CHAR)7);
	pG->c = 7;
	iequals(__LINE__, pG->c %= *pBsc, (CHAR)7);
#endif
#if ANSI
	*pBsc = 8; pG->sc = 8;
	*pBsc %= pG->sc;
	iequals(__LINE__, *pBsc, (SCHAR)0);
	*pBsc = 8;
	iequals(__LINE__, *pBsc %= pG->sc, (SCHAR)0);
	pG->sc = 8; *pBsc = 8;
	pG->sc %= *pBsc;
	iequals(__LINE__, pG->sc, (SCHAR)0);
	pG->sc = 8;
	iequals(__LINE__, pG->sc %= *pBsc, (SCHAR)0);
#endif
#if ANSI
	*pBsc = 8; pG->s = 9;
	*pBsc %= pG->s;
	iequals(__LINE__, *pBsc, (SCHAR)8);
	*pBsc = 8;
	iequals(__LINE__, *pBsc %= pG->s, (SCHAR)8);
	pG->s = 9; *pBsc = 8;
	pG->s %= *pBsc;
	iequals(__LINE__, pG->s, (SHORT)1);
	pG->s = 9;
	iequals(__LINE__, pG->s %= *pBsc, (SHORT)1);
#endif
#if ANSI
	*pBsc = 8; pG->i = 10;
	*pBsc %= pG->i;
	iequals(__LINE__, *pBsc, (SCHAR)8);
	*pBsc = 8;
	iequals(__LINE__, *pBsc %= pG->i, (SCHAR)8);
	pG->i = 10; *pBsc = 8;
	pG->i %= *pBsc;
	iequals(__LINE__, pG->i, (INT)2);
	pG->i = 10;
	iequals(__LINE__, pG->i %= *pBsc, (INT)2);
#endif
#if ANSI
	*pBsc = 8; pG->uc = 11;
	*pBsc %= pG->uc;
	iequals(__LINE__, *pBsc, (SCHAR)8);
	*pBsc = 8;
	iequals(__LINE__, *pBsc %= pG->uc, (SCHAR)8);
	pG->uc = 11; *pBsc = 8;
	pG->uc %= *pBsc;
	iequals(__LINE__, pG->uc, (UCHAR)3);
	pG->uc = 11;
	iequals(__LINE__, pG->uc %= *pBsc, (UCHAR)3);
#endif
#if ANSI
	*pBsc = 8; pG->us = 12;
	*pBsc %= pG->us;
	iequals(__LINE__, *pBsc, (SCHAR)8);
	*pBsc = 8;
	iequals(__LINE__, *pBsc %= pG->us, (SCHAR)8);
	pG->us = 12; *pBsc = 8;
	pG->us %= *pBsc;
	iequals(__LINE__, pG->us, (USHORT)4);
	pG->us = 12;
	iequals(__LINE__, pG->us %= *pBsc, (USHORT)4);
#endif
#if ANSI
	*pBsc = 8; pG->ui = 13;
	*pBsc %= pG->ui;
	iequals(__LINE__, *pBsc, (SCHAR)8);
	*pBsc = 8;
	iequals(__LINE__, *pBsc %= pG->ui, (SCHAR)8);
	pG->ui = 13; *pBsc = 8;
	pG->ui %= *pBsc;
	iequals(__LINE__, pG->ui, (UINT)5);
	pG->ui = 13;
	iequals(__LINE__, pG->ui %= *pBsc, (UINT)5);
#endif
#if ANSI
	*pBsc = 8; pG->l = 14;
	*pBsc %= pG->l;
	iequals(__LINE__, *pBsc, (SCHAR)8);
	*pBsc = 8;
	iequals(__LINE__, *pBsc %= pG->l, (SCHAR)8);
	pG->l = 14; *pBsc = 8;
	pG->l %= *pBsc;
	lequals(__LINE__, pG->l, (LONG)6L);
	pG->l = 14;
	lequals(__LINE__, pG->l %= *pBsc, (LONG)6L);
#endif
#if ANSI
	*pBsc = 8; pG->ul = 15;
	*pBsc %= pG->ul;
	iequals(__LINE__, *pBsc, (SCHAR)8);
	*pBsc = 8;
	iequals(__LINE__, *pBsc %= pG->ul, (SCHAR)8);
	pG->ul = 15; *pBsc = 8;
	pG->ul %= *pBsc;
	lequals(__LINE__, pG->ul, (ULONG)7L);
	pG->ul = 15;
	lequals(__LINE__, pG->ul %= *pBsc, (ULONG)7L);
#endif
	*pBs = 9; pG->c = 7;
	*pBs %= pG->c;
	iequals(__LINE__, *pBs, (SHORT)2);
	*pBs = 9;
	iequals(__LINE__, *pBs %= pG->c, (SHORT)2);
	pG->c = 7; *pBs = 9;
	pG->c %= *pBs;
	iequals(__LINE__, pG->c, (CHAR)7);
	pG->c = 7;
	iequals(__LINE__, pG->c %= *pBs, (CHAR)7);
#if ANSI
	*pBs = 9; pG->sc = 8;
	*pBs %= pG->sc;
	iequals(__LINE__, *pBs, (SHORT)1);
	*pBs = 9;
	iequals(__LINE__, *pBs %= pG->sc, (SHORT)1);
	pG->sc = 8; *pBs = 9;
	pG->sc %= *pBs;
	iequals(__LINE__, pG->sc, (SCHAR)8);
	pG->sc = 8;
	iequals(__LINE__, pG->sc %= *pBs, (SCHAR)8);
#endif
	*pBs = 9; pG->s = 9;
	*pBs %= pG->s;
	iequals(__LINE__, *pBs, (SHORT)0);
	*pBs = 9;
	iequals(__LINE__, *pBs %= pG->s, (SHORT)0);
	pG->s = 9; *pBs = 9;
	pG->s %= *pBs;
	iequals(__LINE__, pG->s, (SHORT)0);
	pG->s = 9;
	iequals(__LINE__, pG->s %= *pBs, (SHORT)0);
	*pBs = 9; pG->i = 10;
	*pBs %= pG->i;
	iequals(__LINE__, *pBs, (SHORT)9);
	*pBs = 9;
	iequals(__LINE__, *pBs %= pG->i, (SHORT)9);
	pG->i = 10; *pBs = 9;
	pG->i %= *pBs;
	iequals(__LINE__, pG->i, (INT)1);
	pG->i = 10;
	iequals(__LINE__, pG->i %= *pBs, (INT)1);
	*pBs = 9; pG->uc = 11;
	*pBs %= pG->uc;
	iequals(__LINE__, *pBs, (SHORT)9);
	*pBs = 9;
	iequals(__LINE__, *pBs %= pG->uc, (SHORT)9);
	pG->uc = 11; *pBs = 9;
	pG->uc %= *pBs;
	iequals(__LINE__, pG->uc, (UCHAR)2);
	pG->uc = 11;
	iequals(__LINE__, pG->uc %= *pBs, (UCHAR)2);
	*pBs = 9; pG->us = 12;
	*pBs %= pG->us;
	iequals(__LINE__, *pBs, (SHORT)9);
	*pBs = 9;
	iequals(__LINE__, *pBs %= pG->us, (SHORT)9);
	pG->us = 12; *pBs = 9;
	pG->us %= *pBs;
	iequals(__LINE__, pG->us, (USHORT)3);
	pG->us = 12;
	iequals(__LINE__, pG->us %= *pBs, (USHORT)3);
	*pBs = 9; pG->ui = 13;
	*pBs %= pG->ui;
	iequals(__LINE__, *pBs, (SHORT)9);
	*pBs = 9;
	iequals(__LINE__, *pBs %= pG->ui, (SHORT)9);
	pG->ui = 13; *pBs = 9;
	pG->ui %= *pBs;
	iequals(__LINE__, pG->ui, (UINT)4);
	pG->ui = 13;
	iequals(__LINE__, pG->ui %= *pBs, (UINT)4);
	*pBs = 9; pG->l = 14;
	*pBs %= pG->l;
	iequals(__LINE__, *pBs, (SHORT)9);
	*pBs = 9;
	iequals(__LINE__, *pBs %= pG->l, (SHORT)9);
	pG->l = 14; *pBs = 9;
	pG->l %= *pBs;
	lequals(__LINE__, pG->l, (LONG)5L);
	pG->l = 14;
	lequals(__LINE__, pG->l %= *pBs, (LONG)5L);
	*pBs = 9; pG->ul = 15;
	*pBs %= pG->ul;
	iequals(__LINE__, *pBs, (SHORT)9);
	*pBs = 9;
	iequals(__LINE__, *pBs %= pG->ul, (SHORT)9);
	pG->ul = 15; *pBs = 9;
	pG->ul %= *pBs;
	lequals(__LINE__, pG->ul, (ULONG)6L);
	pG->ul = 15;
	lequals(__LINE__, pG->ul %= *pBs, (ULONG)6L);
	*pBi = 10; pG->c = 7;
	*pBi %= pG->c;
	iequals(__LINE__, *pBi, (INT)3);
	*pBi = 10;
	iequals(__LINE__, *pBi %= pG->c, (INT)3);
	pG->c = 7; *pBi = 10;
	pG->c %= *pBi;
	iequals(__LINE__, pG->c, (CHAR)7);
	pG->c = 7;
	iequals(__LINE__, pG->c %= *pBi, (CHAR)7);
#if ANSI
	*pBi = 10; pG->sc = 8;
	*pBi %= pG->sc;
	iequals(__LINE__, *pBi, (INT)2);
	*pBi = 10;
	iequals(__LINE__, *pBi %= pG->sc, (INT)2);
	pG->sc = 8; *pBi = 10;
	pG->sc %= *pBi;
	iequals(__LINE__, pG->sc, (SCHAR)8);
	pG->sc = 8;
	iequals(__LINE__, pG->sc %= *pBi, (SCHAR)8);
#endif
	*pBi = 10; pG->s = 9;
	*pBi %= pG->s;
	iequals(__LINE__, *pBi, (INT)1);
	*pBi = 10;
	iequals(__LINE__, *pBi %= pG->s, (INT)1);
	pG->s = 9; *pBi = 10;
	pG->s %= *pBi;
	iequals(__LINE__, pG->s, (SHORT)9);
	pG->s = 9;
	iequals(__LINE__, pG->s %= *pBi, (SHORT)9);
	*pBi = 10; pG->i = 10;
	*pBi %= pG->i;
	iequals(__LINE__, *pBi, (INT)0);
	*pBi = 10;
	iequals(__LINE__, *pBi %= pG->i, (INT)0);
	pG->i = 10; *pBi = 10;
	pG->i %= *pBi;
	iequals(__LINE__, pG->i, (INT)0);
	pG->i = 10;
	iequals(__LINE__, pG->i %= *pBi, (INT)0);
	*pBi = 10; pG->uc = 11;
	*pBi %= pG->uc;
	iequals(__LINE__, *pBi, (INT)10);
	*pBi = 10;
	iequals(__LINE__, *pBi %= pG->uc, (INT)10);
	pG->uc = 11; *pBi = 10;
	pG->uc %= *pBi;
	iequals(__LINE__, pG->uc, (UCHAR)1);
	pG->uc = 11;
	iequals(__LINE__, pG->uc %= *pBi, (UCHAR)1);
	*pBi = 10; pG->us = 12;
	*pBi %= pG->us;
	iequals(__LINE__, *pBi, (INT)10);
	*pBi = 10;
	iequals(__LINE__, *pBi %= pG->us, (INT)10);
	pG->us = 12; *pBi = 10;
	pG->us %= *pBi;
	iequals(__LINE__, pG->us, (USHORT)2);
	pG->us = 12;
	iequals(__LINE__, pG->us %= *pBi, (USHORT)2);
	*pBi = 10; pG->ui = 13;
	*pBi %= pG->ui;
	iequals(__LINE__, *pBi, (INT)10);
	*pBi = 10;
	iequals(__LINE__, *pBi %= pG->ui, (INT)10);
	pG->ui = 13; *pBi = 10;
	pG->ui %= *pBi;
	iequals(__LINE__, pG->ui, (UINT)3);
	pG->ui = 13;
	iequals(__LINE__, pG->ui %= *pBi, (UINT)3);
	*pBi = 10; pG->l = 14;
	*pBi %= pG->l;
	iequals(__LINE__, *pBi, (INT)10);
	*pBi = 10;
	iequals(__LINE__, *pBi %= pG->l, (INT)10);
	pG->l = 14; *pBi = 10;
	pG->l %= *pBi;
	lequals(__LINE__, pG->l, (LONG)4L);
	pG->l = 14;
	lequals(__LINE__, pG->l %= *pBi, (LONG)4L);
	*pBi = 10; pG->ul = 15;
	*pBi %= pG->ul;
	iequals(__LINE__, *pBi, (INT)10);
	*pBi = 10;
	iequals(__LINE__, *pBi %= pG->ul, (INT)10);
	pG->ul = 15; *pBi = 10;
	pG->ul %= *pBi;
	lequals(__LINE__, pG->ul, (ULONG)5L);
	pG->ul = 15;
	lequals(__LINE__, pG->ul %= *pBi, (ULONG)5L);
	*pBuc = 11; pG->c = 7;
	*pBuc %= pG->c;
	iequals(__LINE__, *pBuc, (UCHAR)4);
	*pBuc = 11;
	iequals(__LINE__, *pBuc %= pG->c, (UCHAR)4);
	pG->c = 7; *pBuc = 11;
	pG->c %= *pBuc;
	iequals(__LINE__, pG->c, (CHAR)7);
	pG->c = 7;
	iequals(__LINE__, pG->c %= *pBuc, (CHAR)7);
#if ANSI
	*pBuc = 11; pG->sc = 8;
	*pBuc %= pG->sc;
	iequals(__LINE__, *pBuc, (UCHAR)3);
	*pBuc = 11;
	iequals(__LINE__, *pBuc %= pG->sc, (UCHAR)3);
	pG->sc = 8; *pBuc = 11;
	pG->sc %= *pBuc;
	iequals(__LINE__, pG->sc, (SCHAR)8);
	pG->sc = 8;
	iequals(__LINE__, pG->sc %= *pBuc, (SCHAR)8);
#endif
	*pBuc = 11; pG->s = 9;
	*pBuc %= pG->s;
	iequals(__LINE__, *pBuc, (UCHAR)2);
	*pBuc = 11;
	iequals(__LINE__, *pBuc %= pG->s, (UCHAR)2);
	pG->s = 9; *pBuc = 11;
	pG->s %= *pBuc;
	iequals(__LINE__, pG->s, (SHORT)9);
	pG->s = 9;
	iequals(__LINE__, pG->s %= *pBuc, (SHORT)9);
	*pBuc = 11; pG->i = 10;
	*pBuc %= pG->i;
	iequals(__LINE__, *pBuc, (UCHAR)1);
	*pBuc = 11;
	iequals(__LINE__, *pBuc %= pG->i, (UCHAR)1);
	pG->i = 10; *pBuc = 11;
	pG->i %= *pBuc;
	iequals(__LINE__, pG->i, (INT)10);
	pG->i = 10;
	iequals(__LINE__, pG->i %= *pBuc, (INT)10);
	*pBuc = 11; pG->uc = 11;
	*pBuc %= pG->uc;
	iequals(__LINE__, *pBuc, (UCHAR)0);
	*pBuc = 11;
	iequals(__LINE__, *pBuc %= pG->uc, (UCHAR)0);
	pG->uc = 11; *pBuc = 11;
	pG->uc %= *pBuc;
	iequals(__LINE__, pG->uc, (UCHAR)0);
	pG->uc = 11;
	iequals(__LINE__, pG->uc %= *pBuc, (UCHAR)0);
	*pBuc = 11; pG->us = 12;
	*pBuc %= pG->us;
	iequals(__LINE__, *pBuc, (UCHAR)11);
	*pBuc = 11;
	iequals(__LINE__, *pBuc %= pG->us, (UCHAR)11);
	pG->us = 12; *pBuc = 11;
	pG->us %= *pBuc;
	iequals(__LINE__, pG->us, (USHORT)1);
	pG->us = 12;
	iequals(__LINE__, pG->us %= *pBuc, (USHORT)1);
	*pBuc = 11; pG->ui = 13;
	*pBuc %= pG->ui;
	iequals(__LINE__, *pBuc, (UCHAR)11);
	*pBuc = 11;
	iequals(__LINE__, *pBuc %= pG->ui, (UCHAR)11);
	pG->ui = 13; *pBuc = 11;
	pG->ui %= *pBuc;
	iequals(__LINE__, pG->ui, (UINT)2);
	pG->ui = 13;
	iequals(__LINE__, pG->ui %= *pBuc, (UINT)2);
	*pBuc = 11; pG->l = 14;
	*pBuc %= pG->l;
	iequals(__LINE__, *pBuc, (UCHAR)11);
	*pBuc = 11;
	iequals(__LINE__, *pBuc %= pG->l, (UCHAR)11);
	pG->l = 14; *pBuc = 11;
	pG->l %= *pBuc;
	lequals(__LINE__, pG->l, (LONG)3L);
	pG->l = 14;
	lequals(__LINE__, pG->l %= *pBuc, (LONG)3L);
	*pBuc = 11; pG->ul = 15;
	*pBuc %= pG->ul;
	iequals(__LINE__, *pBuc, (UCHAR)11);
	*pBuc = 11;
	iequals(__LINE__, *pBuc %= pG->ul, (UCHAR)11);
	pG->ul = 15; *pBuc = 11;
	pG->ul %= *pBuc;
	lequals(__LINE__, pG->ul, (ULONG)4L);
	pG->ul = 15;
	lequals(__LINE__, pG->ul %= *pBuc, (ULONG)4L);
	*pBus = 12; pG->c = 7;
	*pBus %= pG->c;
	iequals(__LINE__, *pBus, (USHORT)5);
	*pBus = 12;
	iequals(__LINE__, *pBus %= pG->c, (USHORT)5);
	pG->c = 7; *pBus = 12;
	pG->c %= *pBus;
	iequals(__LINE__, pG->c, (CHAR)7);
	pG->c = 7;
	iequals(__LINE__, pG->c %= *pBus, (CHAR)7);
#if ANSI
	*pBus = 12; pG->sc = 8;
	*pBus %= pG->sc;
	iequals(__LINE__, *pBus, (USHORT)4);
	*pBus = 12;
	iequals(__LINE__, *pBus %= pG->sc, (USHORT)4);
	pG->sc = 8; *pBus = 12;
	pG->sc %= *pBus;
	iequals(__LINE__, pG->sc, (SCHAR)8);
	pG->sc = 8;
	iequals(__LINE__, pG->sc %= *pBus, (SCHAR)8);
#endif
	*pBus = 12; pG->s = 9;
	*pBus %= pG->s;
	iequals(__LINE__, *pBus, (USHORT)3);
	*pBus = 12;
	iequals(__LINE__, *pBus %= pG->s, (USHORT)3);
	pG->s = 9; *pBus = 12;
	pG->s %= *pBus;
	iequals(__LINE__, pG->s, (SHORT)9);
	pG->s = 9;
	iequals(__LINE__, pG->s %= *pBus, (SHORT)9);
	*pBus = 12; pG->i = 10;
	*pBus %= pG->i;
	iequals(__LINE__, *pBus, (USHORT)2);
	*pBus = 12;
	iequals(__LINE__, *pBus %= pG->i, (USHORT)2);
	pG->i = 10; *pBus = 12;
	pG->i %= *pBus;
	iequals(__LINE__, pG->i, (INT)10);
	pG->i = 10;
	iequals(__LINE__, pG->i %= *pBus, (INT)10);
	*pBus = 12; pG->uc = 11;
	*pBus %= pG->uc;
	iequals(__LINE__, *pBus, (USHORT)1);
	*pBus = 12;
	iequals(__LINE__, *pBus %= pG->uc, (USHORT)1);
	pG->uc = 11; *pBus = 12;
	pG->uc %= *pBus;
	iequals(__LINE__, pG->uc, (UCHAR)11);
	pG->uc = 11;
	iequals(__LINE__, pG->uc %= *pBus, (UCHAR)11);
	*pBus = 12; pG->us = 12;
	*pBus %= pG->us;
	iequals(__LINE__, *pBus, (USHORT)0);
	*pBus = 12;
	iequals(__LINE__, *pBus %= pG->us, (USHORT)0);
	pG->us = 12; *pBus = 12;
	pG->us %= *pBus;
	iequals(__LINE__, pG->us, (USHORT)0);
	pG->us = 12;
	iequals(__LINE__, pG->us %= *pBus, (USHORT)0);
	*pBus = 12; pG->ui = 13;
	*pBus %= pG->ui;
	iequals(__LINE__, *pBus, (USHORT)12);
	*pBus = 12;
	iequals(__LINE__, *pBus %= pG->ui, (USHORT)12);
	pG->ui = 13; *pBus = 12;
	pG->ui %= *pBus;
	iequals(__LINE__, pG->ui, (UINT)1);
	pG->ui = 13;
	iequals(__LINE__, pG->ui %= *pBus, (UINT)1);
	*pBus = 12; pG->l = 14;
	*pBus %= pG->l;
	iequals(__LINE__, *pBus, (USHORT)12);
	*pBus = 12;
	iequals(__LINE__, *pBus %= pG->l, (USHORT)12);
	pG->l = 14; *pBus = 12;
	pG->l %= *pBus;
	lequals(__LINE__, pG->l, (LONG)2L);
	pG->l = 14;
	lequals(__LINE__, pG->l %= *pBus, (LONG)2L);
	*pBus = 12; pG->ul = 15;
	*pBus %= pG->ul;
	iequals(__LINE__, *pBus, (USHORT)12);
	*pBus = 12;
	iequals(__LINE__, *pBus %= pG->ul, (USHORT)12);
	pG->ul = 15; *pBus = 12;
	pG->ul %= *pBus;
	lequals(__LINE__, pG->ul, (ULONG)3L);
	pG->ul = 15;
	lequals(__LINE__, pG->ul %= *pBus, (ULONG)3L);
	*pBui = 13; pG->c = 7;
	*pBui %= pG->c;
	iequals(__LINE__, *pBui, (UINT)6);
	*pBui = 13;
	iequals(__LINE__, *pBui %= pG->c, (UINT)6);
	pG->c = 7; *pBui = 13;
	pG->c %= *pBui;
	iequals(__LINE__, pG->c, (CHAR)7);
	pG->c = 7;
	iequals(__LINE__, pG->c %= *pBui, (CHAR)7);
#if ANSI
	*pBui = 13; pG->sc = 8;
	*pBui %= pG->sc;
	iequals(__LINE__, *pBui, (UINT)5);
	*pBui = 13;
	iequals(__LINE__, *pBui %= pG->sc, (UINT)5);
	pG->sc = 8; *pBui = 13;
	pG->sc %= *pBui;
	iequals(__LINE__, pG->sc, (SCHAR)8);
	pG->sc = 8;
	iequals(__LINE__, pG->sc %= *pBui, (SCHAR)8);
#endif
	*pBui = 13; pG->s = 9;
	*pBui %= pG->s;
	iequals(__LINE__, *pBui, (UINT)4);
	*pBui = 13;
	iequals(__LINE__, *pBui %= pG->s, (UINT)4);
	pG->s = 9; *pBui = 13;
	pG->s %= *pBui;
	iequals(__LINE__, pG->s, (SHORT)9);
	pG->s = 9;
	iequals(__LINE__, pG->s %= *pBui, (SHORT)9);
	*pBui = 13; pG->i = 10;
	*pBui %= pG->i;
	iequals(__LINE__, *pBui, (UINT)3);
	*pBui = 13;
	iequals(__LINE__, *pBui %= pG->i, (UINT)3);
	pG->i = 10; *pBui = 13;
	pG->i %= *pBui;
	iequals(__LINE__, pG->i, (INT)10);
	pG->i = 10;
	iequals(__LINE__, pG->i %= *pBui, (INT)10);
	*pBui = 13; pG->uc = 11;
	*pBui %= pG->uc;
	iequals(__LINE__, *pBui, (UINT)2);
	*pBui = 13;
	iequals(__LINE__, *pBui %= pG->uc, (UINT)2);
	pG->uc = 11; *pBui = 13;
	pG->uc %= *pBui;
	iequals(__LINE__, pG->uc, (UCHAR)11);
	pG->uc = 11;
	iequals(__LINE__, pG->uc %= *pBui, (UCHAR)11);
	*pBui = 13; pG->us = 12;
	*pBui %= pG->us;
	iequals(__LINE__, *pBui, (UINT)1);
	*pBui = 13;
	iequals(__LINE__, *pBui %= pG->us, (UINT)1);
	pG->us = 12; *pBui = 13;
	pG->us %= *pBui;
	iequals(__LINE__, pG->us, (USHORT)12);
	pG->us = 12;
	iequals(__LINE__, pG->us %= *pBui, (USHORT)12);
	*pBui = 13; pG->ui = 13;
	*pBui %= pG->ui;
	iequals(__LINE__, *pBui, (UINT)0);
	*pBui = 13;
	iequals(__LINE__, *pBui %= pG->ui, (UINT)0);
	pG->ui = 13; *pBui = 13;
	pG->ui %= *pBui;
	iequals(__LINE__, pG->ui, (UINT)0);
	pG->ui = 13;
	iequals(__LINE__, pG->ui %= *pBui, (UINT)0);
	*pBui = 13; pG->l = 14;
	*pBui %= pG->l;
	iequals(__LINE__, *pBui, (UINT)13);
	*pBui = 13;
	iequals(__LINE__, *pBui %= pG->l, (UINT)13);
	pG->l = 14; *pBui = 13;
	pG->l %= *pBui;
	lequals(__LINE__, pG->l, (LONG)1L);
	pG->l = 14;
	lequals(__LINE__, pG->l %= *pBui, (LONG)1L);
	*pBui = 13; pG->ul = 15;
	*pBui %= pG->ul;
	iequals(__LINE__, *pBui, (UINT)13);
	*pBui = 13;
	iequals(__LINE__, *pBui %= pG->ul, (UINT)13);
	pG->ul = 15; *pBui = 13;
	pG->ul %= *pBui;
	lequals(__LINE__, pG->ul, (ULONG)2L);
	pG->ul = 15;
	lequals(__LINE__, pG->ul %= *pBui, (ULONG)2L);
	*pBl = 14; pG->c = 7;
	*pBl %= pG->c;
	lequals(__LINE__, *pBl, (LONG)0L);
	*pBl = 14;
	lequals(__LINE__, *pBl %= pG->c, (LONG)0L);
	pG->c = 7; *pBl = 14;
	pG->c %= *pBl;
	iequals(__LINE__, pG->c, (CHAR)7);
	pG->c = 7;
	iequals(__LINE__, pG->c %= *pBl, (CHAR)7);
#if ANSI
	*pBl = 14; pG->sc = 8;
	*pBl %= pG->sc;
	lequals(__LINE__, *pBl, (LONG)6L);
	*pBl = 14;
	lequals(__LINE__, *pBl %= pG->sc, (LONG)6L);
	pG->sc = 8; *pBl = 14;
	pG->sc %= *pBl;
	iequals(__LINE__, pG->sc, (SCHAR)8);
	pG->sc = 8;
	iequals(__LINE__, pG->sc %= *pBl, (SCHAR)8);
#endif
	*pBl = 14; pG->s = 9;
	*pBl %= pG->s;
	lequals(__LINE__, *pBl, (LONG)5L);
	*pBl = 14;
	lequals(__LINE__, *pBl %= pG->s, (LONG)5L);
	pG->s = 9; *pBl = 14;
	pG->s %= *pBl;
	iequals(__LINE__, pG->s, (SHORT)9);
	pG->s = 9;
	iequals(__LINE__, pG->s %= *pBl, (SHORT)9);
	*pBl = 14; pG->i = 10;
	*pBl %= pG->i;
	lequals(__LINE__, *pBl, (LONG)4L);
	*pBl = 14;
	lequals(__LINE__, *pBl %= pG->i, (LONG)4L);
	pG->i = 10; *pBl = 14;
	pG->i %= *pBl;
	iequals(__LINE__, pG->i, (INT)10);
	pG->i = 10;
	iequals(__LINE__, pG->i %= *pBl, (INT)10);
	*pBl = 14; pG->uc = 11;
	*pBl %= pG->uc;
	lequals(__LINE__, *pBl, (LONG)3L);
	*pBl = 14;
	lequals(__LINE__, *pBl %= pG->uc, (LONG)3L);
	pG->uc = 11; *pBl = 14;
	pG->uc %= *pBl;
	iequals(__LINE__, pG->uc, (UCHAR)11);
	pG->uc = 11;
	iequals(__LINE__, pG->uc %= *pBl, (UCHAR)11);
	*pBl = 14; pG->us = 12;
	*pBl %= pG->us;
	lequals(__LINE__, *pBl, (LONG)2L);
	*pBl = 14;
	lequals(__LINE__, *pBl %= pG->us, (LONG)2L);
	pG->us = 12; *pBl = 14;
	pG->us %= *pBl;
	iequals(__LINE__, pG->us, (USHORT)12);
	pG->us = 12;
	iequals(__LINE__, pG->us %= *pBl, (USHORT)12);
	*pBl = 14; pG->ui = 13;
	*pBl %= pG->ui;
	lequals(__LINE__, *pBl, (LONG)1L);
	*pBl = 14;
	lequals(__LINE__, *pBl %= pG->ui, (LONG)1L);
	pG->ui = 13; *pBl = 14;
	pG->ui %= *pBl;
	iequals(__LINE__, pG->ui, (UINT)13);
	pG->ui = 13;
	iequals(__LINE__, pG->ui %= *pBl, (UINT)13);
	*pBl = 14; pG->l = 14;
	*pBl %= pG->l;
	lequals(__LINE__, *pBl, (LONG)0L);
	*pBl = 14;
	lequals(__LINE__, *pBl %= pG->l, (LONG)0L);
	pG->l = 14; *pBl = 14;
	pG->l %= *pBl;
	lequals(__LINE__, pG->l, (LONG)0L);
	pG->l = 14;
	lequals(__LINE__, pG->l %= *pBl, (LONG)0L);
	*pBl = 14; pG->ul = 15;
	*pBl %= pG->ul;
	lequals(__LINE__, *pBl, (LONG)14L);
	*pBl = 14;
	lequals(__LINE__, *pBl %= pG->ul, (LONG)14L);
	pG->ul = 15; *pBl = 14;
	pG->ul %= *pBl;
	lequals(__LINE__, pG->ul, (ULONG)1L);
	pG->ul = 15;
	lequals(__LINE__, pG->ul %= *pBl, (ULONG)1L);
	*pBul = 15; pG->c = 7;
	*pBul %= pG->c;
	lequals(__LINE__, *pBul, (ULONG)1L);
	*pBul = 15;
	lequals(__LINE__, *pBul %= pG->c, (ULONG)1L);
	pG->c = 7; *pBul = 15;
	pG->c %= *pBul;
	iequals(__LINE__, pG->c, (CHAR)7);
	pG->c = 7;
	iequals(__LINE__, pG->c %= *pBul, (CHAR)7);
#if ANSI
	*pBul = 15; pG->sc = 8;
	*pBul %= pG->sc;
	lequals(__LINE__, *pBul, (ULONG)7L);
	*pBul = 15;
	lequals(__LINE__, *pBul %= pG->sc, (ULONG)7L);
	pG->sc = 8; *pBul = 15;
	pG->sc %= *pBul;
	iequals(__LINE__, pG->sc, (SCHAR)8);
	pG->sc = 8;
	iequals(__LINE__, pG->sc %= *pBul, (SCHAR)8);
#endif
	*pBul = 15; pG->s = 9;
	*pBul %= pG->s;
	lequals(__LINE__, *pBul, (ULONG)6L);
	*pBul = 15;
	lequals(__LINE__, *pBul %= pG->s, (ULONG)6L);
	pG->s = 9; *pBul = 15;
	pG->s %= *pBul;
	iequals(__LINE__, pG->s, (SHORT)9);
	pG->s = 9;
	iequals(__LINE__, pG->s %= *pBul, (SHORT)9);
	*pBul = 15; pG->i = 10;
	*pBul %= pG->i;
	lequals(__LINE__, *pBul, (ULONG)5L);
	*pBul = 15;
	lequals(__LINE__, *pBul %= pG->i, (ULONG)5L);
	pG->i = 10; *pBul = 15;
	pG->i %= *pBul;
	iequals(__LINE__, pG->i, (INT)10);
	pG->i = 10;
	iequals(__LINE__, pG->i %= *pBul, (INT)10);
	*pBul = 15; pG->uc = 11;
	*pBul %= pG->uc;
	lequals(__LINE__, *pBul, (ULONG)4L);
	*pBul = 15;
	lequals(__LINE__, *pBul %= pG->uc, (ULONG)4L);
	pG->uc = 11; *pBul = 15;
	pG->uc %= *pBul;
	iequals(__LINE__, pG->uc, (UCHAR)11);
	pG->uc = 11;
	iequals(__LINE__, pG->uc %= *pBul, (UCHAR)11);
	*pBul = 15; pG->us = 12;
	*pBul %= pG->us;
	lequals(__LINE__, *pBul, (ULONG)3L);
	*pBul = 15;
	lequals(__LINE__, *pBul %= pG->us, (ULONG)3L);
	pG->us = 12; *pBul = 15;
	pG->us %= *pBul;
	iequals(__LINE__, pG->us, (USHORT)12);
	pG->us = 12;
	iequals(__LINE__, pG->us %= *pBul, (USHORT)12);
	*pBul = 15; pG->ui = 13;
	*pBul %= pG->ui;
	lequals(__LINE__, *pBul, (ULONG)2L);
	*pBul = 15;
	lequals(__LINE__, *pBul %= pG->ui, (ULONG)2L);
	pG->ui = 13; *pBul = 15;
	pG->ui %= *pBul;
	iequals(__LINE__, pG->ui, (UINT)13);
	pG->ui = 13;
	iequals(__LINE__, pG->ui %= *pBul, (UINT)13);
	*pBul = 15; pG->l = 14;
	*pBul %= pG->l;
	lequals(__LINE__, *pBul, (ULONG)1L);
	*pBul = 15;
	lequals(__LINE__, *pBul %= pG->l, (ULONG)1L);
	pG->l = 14; *pBul = 15;
	pG->l %= *pBul;
	lequals(__LINE__, pG->l, (LONG)14L);
	pG->l = 14;
	lequals(__LINE__, pG->l %= *pBul, (LONG)14L);
	*pBul = 15; pG->ul = 15;
	*pBul %= pG->ul;
	lequals(__LINE__, *pBul, (ULONG)0L);
	*pBul = 15;
	lequals(__LINE__, *pBul %= pG->ul, (ULONG)0L);
	pG->ul = 15; *pBul = 15;
	pG->ul %= *pBul;
	lequals(__LINE__, pG->ul, (ULONG)0L);
	pG->ul = 15;
	lequals(__LINE__, pG->ul %= *pBul, (ULONG)0L);
	}}
	return 	report(Filename);
	}
