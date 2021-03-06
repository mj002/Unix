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
 **    EGEN -P -R13 -V -A -N5 -Dinteger.gen ( @ @ ) @ ( @ @ )              **
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
	Filename = "int13.c";

	/* post-- 9 => 10 */
	/* 97L && 10 => 1 */
	/* ! 5 => 0 */
	/* 0x80e8 ^= 0 => 0x80e8 */
	/* 1 == 0x80e8 => 0 */
	iequals(__LINE__, ((l && ((i)-- )) == (us ^= ( ! rint5))), 0);
	iequals(__LINE__, us, (unsigned)33000);
	iequals(__LINE__, i, 9);

	/* 0x64 & 97L => 96L */
	/* 0x80e8 | 96L => 33000L */
	/* 0x64 * 2 => 0xc8 */
	/* 0xc8 >= 0xfde8L => 0 */
	/* 33000L * 0 => 0L */
	lequals(__LINE__, ((**ppus | (**ppui & l)) * ((*pui * rint2) >= *pul)), 0L);

	/* 2 * 0x64 => 0xc8 */
	/* 20 /= 0xc8 => 0 */
	/* 3 < 5 => 1 */
	/* 13 += 1 => 14 */
	/* 0 <= 14 => 1 */
	iequals(__LINE__, ((**ppc /= (rint2 * **ppui)) <= (s += (rint3 < rint5))), 1);
	iequals(__LINE__, s, 14);
	iequals(__LINE__, c, 0);

	/* ! 9 => 0 */
	/* 0 & 0x64 => 0x0 */
	/* 128 > 128 => 0 */
	/* 0x0 >> 0 => 0x0 */
	iequals(__LINE__, ((( ! i) & **ppui) >> ((uc > *puc) && *pui)), 0x0);

	/* 0x64 |= 5 => 0x65 */
	/* 0 *= 0x65 => 0 */
	/* 0x80 % 14 => 2 */
	/* 2 == 2 => 1 */
	/* 0 >= 1 => 0 */
	iequals(__LINE__, ((**ppc *= (**ppui |= rint5)) >= ((*puc % s) == rint2)), 0);
	iequals(__LINE__, ui, (unsigned)101);
	iequals(__LINE__, c, 0);

	return 	report(Filename);
	}
