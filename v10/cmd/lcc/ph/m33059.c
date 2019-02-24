/* The Plum Hall Validation Suite for C
 * Unpublished copyright (c) 1986-1991, Chiron Systems Inc and Plum Hall Inc.
 * VERSION: 4
 * DATE: 1993-01-01
 * The "ANSI" mode of this suite corresponds to official ANSI C, X3.159-1989.
 * As per your license agreement, your distribution is not to be moved or copied outside the Designated Site
 * without specific permission from Plum Hall Inc.
 */

/* 3.3.16	ConP1 (and 3.2.2.1 P1S3)	CONSTRAINT-MANDATORY */
/* 	non-const expr, cast to const, isn't modifiable, and ass't needs modifiable lvalue */
int main() {
	{ int i = 1; *(const int *)&i = 2; }
	return 0; }
