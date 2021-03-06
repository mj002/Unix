/* The Plum Hall Validation Suite for C
 * Unpublished copyright (c) 1986-1991, Chiron Systems Inc and Plum Hall Inc.
 * VERSION: 4
 * DATE: 1993-01-01
 * The "ANSI" mode of the Suite corresponds to the official ANSI C, X3.159-1989.
 * As per your license agreement, your distribution is not to be moved or copied outside the Designated Site
 * without specific permission from Plum Hall Inc.
 */

/****************************************************************************
 ** Self-checking C source code generated by EGEN component of             **
 **    The Plum Hall Validation Suite for C.                               **
 **    (C) 1986-1988 Chiron Systems Inc and Plum Hall Inc                  **
 **    EGEN Version 1.09.000  88/08/21                                     **
 **                                                                        **
 **    EGEN -P -R5 -V -A -N5 -Dinteger.gen ( @ @ ) @ ( @ @ )               **
 ****************************************************************************/
#include "defs.h"


int main()
	{
	extern char *Filename;
	auto unsigned int ui;
	static unsigned int * pui;
	auto unsigned int ** ppui;
	auto int i;
	static int * pi;
	auto int ** ppi;
	auto unsigned short us;
	static unsigned short * pus;
	auto unsigned short ** ppus;
	auto short s;
	static short * ps;
	auto short ** pps;
	auto unsigned char uc;
	static unsigned char * puc;
	auto unsigned char ** ppuc;
	auto char c;
	static char * pc;
	auto char ** ppc;
	auto unsigned long ul;
	static unsigned long * pul;
	auto unsigned long ** ppul;
	auto long l;
	static long * pl;
	auto long ** ppl;
	register int rint1;
	register int rint2;
	register int rint3;
	register int rint4;
	register int rint5;

	ui = ivalue(100);
	pui = &ui;
	ppui = &pui;
	i = ivalue(10);
	pi = &i;
	ppi = &pi;
	us = lvalue(33000);
	pus = &us;
	ppus = &pus;
	s = ivalue(13);
	ps = &s;
	pps = &ps;
	uc = ivalue(128);
	puc = &uc;
	ppuc = &puc;
	c = ivalue(20);
	pc = &c;
	ppc = &pc;
	ul = lvalue(65000L);
	pul = &ul;
	ppul = &pul;
	l = lvalue(97L);
	pl = &l;
	ppl = &pl;
	rint1 = ivalue(1);
	rint2 = ivalue(2);
	rint3 = ivalue(3);
	rint4 = ivalue(4);
	rint5 = ivalue(5);
	Filename = "int5.c";

	/* 0x80 -= 20 => 0x6c */
	/* 13 &= 0x6c => 12 */
	/* 2 > 20 => 0 */
	/* 1 | 0 => 1 */
	/* 12 * 1 => 12 */
	iequals(__LINE__, ((*ps &= (uc -= c)) * (rint1 | (rint2 > c))), 12);
	iequals(__LINE__, uc, (unsigned)108);
	iequals(__LINE__, s, 12);

	/* neg 0x6c => -108 */
	/* -108 >= 12 => 0 */
	/* 97L + 5 => 102L */
	/* 102L - 4 => 98L */
	/* 0 == 98L => 0 */
	iequals(__LINE__, ((( - **ppuc) >= s) == ((l + rint5) - rint4)), 0);

	/* pre++ 0x6c => 0x6d */
	/* 1 ^= 0x6d => 108 */
	/* 20 >= 0x64 => 0 */
	/* 0 >= 97L => 0 */
	/* 108 ^ 0 => 108 */
	iequals(__LINE__, ((rint1 ^= ( ++ uc)) ^ ((c >= ui) >= l)), 108);
	iequals(__LINE__, uc, (unsigned)109);
	iequals(__LINE__, rint1, 108);

	/* 0x6d / 0x6d => 1 */
	/* 1 <= 0x64 => 1 */
	/* 0x64 ^ 0x80e8 => 0x808c */
	/* 97L -= 0x808c => -32811L */
	/* 1 & -32811L => 1L */
	ulequals(__LINE__, (((*puc / **ppuc) <= **ppui) & (ULONG)(**ppl -= (long)(ui ^ **ppus))), 1L);
	lequals(__LINE__, l, -32811L);

	/* 0x6d &= 20 => 0x4 */
	/* 0xfde8L >>= 0x4 => 0xfdeL */
	/* 0x64 != -32811L => 1 */
	/* 12 <<= 1 => 24 */
	/* 0xfdeL * 24 => 0x17cd0L */
	ulequals(__LINE__, ((*pul >>= (*puc &= c)) * (s <<= (**ppui != l))), 0x17cd0L);
	iequals(__LINE__, s, 24);
	iequals(__LINE__, uc, (unsigned)4);
	lequals(__LINE__, ul, 4062L);

	return 	report(Filename);
	}
