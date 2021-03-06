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
 **    EGEN -P -R11 -V -A -N5 -Dinteger.gen ( @ @ ) @ ( @ @ )              **
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
	Filename = "int11.c";

	/* pre-- 20 => 19 */
	/* 10 + 19 => 29 */
	/* 0x80 ^ 0x80 => 0 */
	/* 0xfde8L &= 0 => 0x0L */
	/* 29 <= 0x0L => 0 */
	iequals(__LINE__, ((*pi + ( -- **ppc)) <= (*pul &= (**ppuc ^ uc))), 0);
	lequals(__LINE__, ul, 0L);
	iequals(__LINE__, c, 19);

	/* 0x80 >> 2 => 32 */
	/* 32 > 13 => 1 */
	/* ! 0x80e8 => 0 */
	/* 0 > 0x80e8 => 0 */
	/* 1 << 0 => 1 */
	iequals(__LINE__, (((*puc >> rint2) > *ps) << (( ! **ppus) > **ppus)), 1);

	/* 0x80e8 <= 3 => 0 */
	/* 1 | 0 => 1 */
	/* post++ 14 => 13 */
	/* 4 <= 13 => 1 */
	/* 1 % 1 => 0 */
	iequals(__LINE__, ((rint1 | (us <= rint3)) % (rint4 <= ((s)++ ))), 0);
	iequals(__LINE__, s, 14);

	/* neg 10 => -10 */
	/* -10 >= 14 => 0 */
	/* pre++ 0x80 => 0x81 */
	/* 4 > 129 => 0 */
	/* 0 >= 0 => 1 */
	iequals(__LINE__, ((( - *pi) >= *ps) >= (rint4 > ( ++ *puc))), 1);
	iequals(__LINE__, uc, (unsigned)129);

	/* 1 &= 19 => 1 */
	/* 97L <<= 1 => 194L */
	/* post++ 0x82 => 0x81 */
	/* 14 &= 0x81 => 0 */
	/* 194L + 0 => 194L */
	lequals(__LINE__, ((**ppl <<= (rint1 &= c)) + (s &= ((uc)++ ))), 194L);
	iequals(__LINE__, uc, (unsigned)130);
	iequals(__LINE__, s, 0);
	iequals(__LINE__, rint1, 1);
	lequals(__LINE__, l, 194L);

	return 	report(Filename);
	}
