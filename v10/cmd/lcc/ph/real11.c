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
 **    EGEN -P -R11 -V -A -N5 -Dreal.gen ( @ @ ) @ ( @ @ )                 **
 ****************************************************************************/
#include  "defs.h"


int main()
	{
	extern char *Filename;
	auto float f1;
	auto float * pf1;
	auto float f2;
	auto float * pf2;
	auto float f3;
	auto float * pf3;
	auto float f4;
	auto float * pf4;
	auto double d1;
	auto double * pd1;
	auto double d2;
	auto double * pd2;
	auto double d3;
	auto double * pd3;
	auto double d4;
	auto double * pd4;
	auto double d5;
	auto double * pd5;
	auto double d6;
	auto double * pd6;

	f1 = fvalue(1.000000E+000);
	pf1 = &f1;
	f2 = fvalue(2.000000E+000);
	pf2 = &f2;
	f3 = fvalue(3.000000E+000);
	pf3 = &f3;
	f4 = fvalue(4.000000E+000);
	pf4 = &f4;
	d1 = dvalue(1.000000000000000E+000);
	pd1 = &d1;
	d2 = dvalue(2.000000000000000E+000);
	pd2 = &d2;
	d3 = dvalue(3.000000000000000E+000);
	pd3 = &d3;
	d4 = dvalue(4.000000000000000E+000);
	pd4 = &d4;
	d5 = dvalue(5.000000000000000E+000);
	pd5 = &d5;
	d6 = dvalue(6.000000000000000E+000);
	pd6 = &d6;
	Filename = "real11.c";

	/* neg 4.00000000000000E+000 => -4.00000000000000E+000 */
	/* -4.00000000000000E+000 >= 1.00000E+000 => 0 */
	/* pre++ 4.00000E+000 => 5.00000E+000 */
	/* 5.00000E+000 > 5.00000E+000 => 0 */
	/* 0 >= 0 => 1 */
	iequals(__LINE__, ((( - d4) >= f1) >= (d5 > ( ++ f4))), 1);
	fequals(__LINE__, f4, 5.00000E+000);

	/* 6.00000000000000E+000 <= 5.00000E+000 => 0 */
	/* 0 > 5.00000000000000E+000 => 0 */
	/* 3.00000E+000 * 5.00000000000000E+000 => 1.50000000000000E+001 */
	/* 1.00000000000000E+000 > 1.50000000000000E+001 => 0 */
	/* 0 || 0 => 0 */
	iequals(__LINE__, (((*pd6 <= *pf4) > *pd5) || (*pd1 > (*pf3 * *pd5))), 0);

	/* 1.00000000000000E+000 - 5.00000E+000 => -4.00000000000000E+000 */
	/* 3.00000000000000E+000 == -4.00000000000000E+000 => 0 */
	iequals(__LINE__, ((*pd3 == (*pd1 - f4)) && (d3 == (*pf4 + *pd1))), 0);

	/* 1.00000E+000 / 3.00000000000000E+000 => 3.33333333333333E-001 */
	/* 3.00000E+000 > 3.33333333333333E-001 => 1 */
	/* 5.00000000000000E+000 *= 1.00000E+000 => 5.00000000000000E+000 */
	/* 5.00000E+000 -= 5.00000E+000 => 0.00000E+000 */
	/* 1 < 0.00000E+000 => 0 */
	iequals(__LINE__, ((*pf3 > (f1 / *pd3)) < (f4 -= (*pd5 *= *pf1))), 0);
	fequals(__LINE__, d5, 5.00000E+000);
	fequals(__LINE__, f4, 0.00000E+000);

	/* post++ 4.00000E+000 => 3.00000E+000 */
	/* 3.00000E+000 != 2.00000E+000 => 1 */
	/* 0.00000E+000 - 2.00000E+000 => -2.00000E+000 */
	/* 2.00000E+000 /= -2.00000E+000 => -1.00000E+000 */
	/* 1 > -1.00000E+000 => 1 */
	iequals(__LINE__, ((((*pf3)++ ) != d2) > (f2 /= (f4 - *pd2))), 1);
	fequals(__LINE__, f2, -1.00000E+000);
	fequals(__LINE__, f3, 4.00000E+000);

	return 	report(Filename);
	}
