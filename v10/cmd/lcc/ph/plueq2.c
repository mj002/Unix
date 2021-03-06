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
#include "n.h"
int main()
	{
	extern char *Filename;
	auto CHAR Cc = 7;
	auto CHAR *pCc = &Cc;
	auto CHAR **ppCc = &pCc;
#if ANSI
	auto SCHAR Csc = 8;
	auto SCHAR *pCsc = &Csc;
	auto SCHAR **ppCsc = &pCsc;
#endif
	auto SHORT Cs = 9;
	auto SHORT *pCs = &Cs;
	auto SHORT **ppCs = &pCs;
	auto INT Ci = 10;
	auto INT *pCi = &Ci;
	auto INT **ppCi = &pCi;
	auto UCHAR Cuc = 11;
	auto UCHAR *pCuc = &Cuc;
	auto UCHAR **ppCuc = &pCuc;
	auto USHORT Cus = 12;
	auto USHORT *pCus = &Cus;
	auto USHORT **ppCus = &pCus;
	auto UINT Cui = 13;
	auto UINT *pCui = &Cui;
	auto UINT **ppCui = &pCui;
	auto LONG Cl = 14;
	auto LONG *pCl = &Cl;
	auto LONG **ppCl = &pCl;
	auto ULONG Cul = 15;
	auto ULONG *pCul = &Cul;
	auto ULONG **ppCul = &pCul;
	auto FLOAT Cf = 16;
	auto FLOAT *pCf = &Cf;
	auto FLOAT **ppCf = &pCf;
	auto DOUBLE Cd = 17;
	auto DOUBLE *pCd = &Cd;
	auto DOUBLE **ppCd = &pCd;
#if ANSI
	auto LDOUBLE Cld = 18;
	auto LDOUBLE *pCld = &Cld;
	auto LDOUBLE **ppCld = &pCld;
#endif
	{
	CHAR *Nc();
#if ANSI
	SCHAR *Nsc();
#endif
	SHORT *Ns();
	INT *Ni();
	UCHAR *Nuc();
	USHORT *Nus();
	UINT *Nui();
	LONG *Nl();
	ULONG *Nul();
	FLOAT *Nf();
	DOUBLE *Nd();
#if ANSI
	LDOUBLE *Nld();
#endif
	{
	int true = 1, false = 0;
	Filename =  " auto pscalar2 auto funcrp plueq2 ";
	*Nui() = 13; **ppCs = 9;
	*Nui() += **ppCs;
	iequals(__LINE__, *Nui(), (UINT)22);
	*Nui() = 13;
	iequals(__LINE__, *Nui() += **ppCs, (UINT)22);
	**ppCs = 9; *Nl() = 14;
	**ppCs += *Nl();
	iequals(__LINE__, **ppCs, (SHORT)23);
	**ppCs = 9;
	iequals(__LINE__, **ppCs += *Nl(), (SHORT)23);
	*Nl() = 14; **ppCs = 9;
	*Nl() += **ppCs;
	lequals(__LINE__, *Nl(), (LONG)23L);
	*Nl() = 14;
	lequals(__LINE__, *Nl() += **ppCs, (LONG)23L);
	**ppCs = 9; *Nul() = 15;
	**ppCs += *Nul();
	iequals(__LINE__, **ppCs, (SHORT)24);
	**ppCs = 9;
	iequals(__LINE__, **ppCs += *Nul(), (SHORT)24);
	*Nul() = 15; **ppCs = 9;
	*Nul() += **ppCs;
	lequals(__LINE__, *Nul(), (ULONG)24L);
	*Nul() = 15;
	lequals(__LINE__, *Nul() += **ppCs, (ULONG)24L);
	**ppCs = 9; *Nf() = 16;
	**ppCs += *Nf();
	iequals(__LINE__, **ppCs, (SHORT)25);
	**ppCs = 9;
	iequals(__LINE__, **ppCs += *Nf(), (SHORT)25);
	*Nf() = 16; **ppCs = 9;
	*Nf() += **ppCs;
	dequals(__LINE__, *Nf(), (FLOAT)25.);
	*Nf() = 16;
	dequals(__LINE__, *Nf() += **ppCs, (FLOAT)25.);
	**ppCs = 9; *Nd() = 17;
	**ppCs += *Nd();
	iequals(__LINE__, **ppCs, (SHORT)26);
	**ppCs = 9;
	iequals(__LINE__, **ppCs += *Nd(), (SHORT)26);
	*Nd() = 17; **ppCs = 9;
	*Nd() += **ppCs;
	dequals(__LINE__, *Nd(), (DOUBLE)26.);
	*Nd() = 17;
	dequals(__LINE__, *Nd() += **ppCs, (DOUBLE)26.);
#if ANSI
	**ppCs = 9; *Nld() = 18;
	**ppCs += *Nld();
	iequals(__LINE__, **ppCs, (SHORT)27);
	**ppCs = 9;
	iequals(__LINE__, **ppCs += *Nld(), (SHORT)27);
	*Nld() = 18; **ppCs = 9;
	*Nld() += **ppCs;
	ldequals(__LINE__, *Nld(), (LDOUBLE)27.L);
	*Nld() = 18;
	ldequals(__LINE__, *Nld() += **ppCs, (LDOUBLE)27.L);
#endif
	**ppCi = 10; *Nc() = 7;
	**ppCi += *Nc();
	iequals(__LINE__, **ppCi, (INT)17);
	**ppCi = 10;
	iequals(__LINE__, **ppCi += *Nc(), (INT)17);
	*Nc() = 7; **ppCi = 10;
	*Nc() += **ppCi;
	iequals(__LINE__, *Nc(), (CHAR)17);
	*Nc() = 7;
	iequals(__LINE__, *Nc() += **ppCi, (CHAR)17);
#if ANSI
	**ppCi = 10; *Nsc() = 8;
	**ppCi += *Nsc();
	iequals(__LINE__, **ppCi, (INT)18);
	**ppCi = 10;
	iequals(__LINE__, **ppCi += *Nsc(), (INT)18);
	*Nsc() = 8; **ppCi = 10;
	*Nsc() += **ppCi;
	iequals(__LINE__, *Nsc(), (SCHAR)18);
	*Nsc() = 8;
	iequals(__LINE__, *Nsc() += **ppCi, (SCHAR)18);
#endif
	**ppCi = 10; *Ns() = 9;
	**ppCi += *Ns();
	iequals(__LINE__, **ppCi, (INT)19);
	**ppCi = 10;
	iequals(__LINE__, **ppCi += *Ns(), (INT)19);
	*Ns() = 9; **ppCi = 10;
	*Ns() += **ppCi;
	iequals(__LINE__, *Ns(), (SHORT)19);
	*Ns() = 9;
	iequals(__LINE__, *Ns() += **ppCi, (SHORT)19);
	**ppCi = 10; *Ni() = 10;
	**ppCi += *Ni();
	iequals(__LINE__, **ppCi, (INT)20);
	**ppCi = 10;
	iequals(__LINE__, **ppCi += *Ni(), (INT)20);
	*Ni() = 10; **ppCi = 10;
	*Ni() += **ppCi;
	iequals(__LINE__, *Ni(), (INT)20);
	*Ni() = 10;
	iequals(__LINE__, *Ni() += **ppCi, (INT)20);
	**ppCi = 10; *Nuc() = 11;
	**ppCi += *Nuc();
	iequals(__LINE__, **ppCi, (INT)21);
	**ppCi = 10;
	iequals(__LINE__, **ppCi += *Nuc(), (INT)21);
	*Nuc() = 11; **ppCi = 10;
	*Nuc() += **ppCi;
	iequals(__LINE__, *Nuc(), (UCHAR)21);
	*Nuc() = 11;
	iequals(__LINE__, *Nuc() += **ppCi, (UCHAR)21);
	**ppCi = 10; *Nus() = 12;
	**ppCi += *Nus();
	iequals(__LINE__, **ppCi, (INT)22);
	**ppCi = 10;
	iequals(__LINE__, **ppCi += *Nus(), (INT)22);
	*Nus() = 12; **ppCi = 10;
	*Nus() += **ppCi;
	iequals(__LINE__, *Nus(), (USHORT)22);
	*Nus() = 12;
	iequals(__LINE__, *Nus() += **ppCi, (USHORT)22);
	**ppCi = 10; *Nui() = 13;
	**ppCi += *Nui();
	iequals(__LINE__, **ppCi, (INT)23);
	**ppCi = 10;
	iequals(__LINE__, **ppCi += *Nui(), (INT)23);
	*Nui() = 13; **ppCi = 10;
	*Nui() += **ppCi;
	iequals(__LINE__, *Nui(), (UINT)23);
	*Nui() = 13;
	iequals(__LINE__, *Nui() += **ppCi, (UINT)23);
	**ppCi = 10; *Nl() = 14;
	**ppCi += *Nl();
	iequals(__LINE__, **ppCi, (INT)24);
	**ppCi = 10;
	iequals(__LINE__, **ppCi += *Nl(), (INT)24);
	*Nl() = 14; **ppCi = 10;
	*Nl() += **ppCi;
	lequals(__LINE__, *Nl(), (LONG)24L);
	*Nl() = 14;
	lequals(__LINE__, *Nl() += **ppCi, (LONG)24L);
	**ppCi = 10; *Nul() = 15;
	**ppCi += *Nul();
	iequals(__LINE__, **ppCi, (INT)25);
	**ppCi = 10;
	iequals(__LINE__, **ppCi += *Nul(), (INT)25);
	*Nul() = 15; **ppCi = 10;
	*Nul() += **ppCi;
	lequals(__LINE__, *Nul(), (ULONG)25L);
	*Nul() = 15;
	lequals(__LINE__, *Nul() += **ppCi, (ULONG)25L);
	**ppCi = 10; *Nf() = 16;
	**ppCi += *Nf();
	iequals(__LINE__, **ppCi, (INT)26);
	**ppCi = 10;
	iequals(__LINE__, **ppCi += *Nf(), (INT)26);
	*Nf() = 16; **ppCi = 10;
	*Nf() += **ppCi;
	dequals(__LINE__, *Nf(), (FLOAT)26.);
	*Nf() = 16;
	dequals(__LINE__, *Nf() += **ppCi, (FLOAT)26.);
	**ppCi = 10; *Nd() = 17;
	**ppCi += *Nd();
	iequals(__LINE__, **ppCi, (INT)27);
	**ppCi = 10;
	iequals(__LINE__, **ppCi += *Nd(), (INT)27);
	*Nd() = 17; **ppCi = 10;
	*Nd() += **ppCi;
	dequals(__LINE__, *Nd(), (DOUBLE)27.);
	*Nd() = 17;
	dequals(__LINE__, *Nd() += **ppCi, (DOUBLE)27.);
#if ANSI
	**ppCi = 10; *Nld() = 18;
	**ppCi += *Nld();
	iequals(__LINE__, **ppCi, (INT)28);
	**ppCi = 10;
	iequals(__LINE__, **ppCi += *Nld(), (INT)28);
	*Nld() = 18; **ppCi = 10;
	*Nld() += **ppCi;
	ldequals(__LINE__, *Nld(), (LDOUBLE)28.L);
	*Nld() = 18;
	ldequals(__LINE__, *Nld() += **ppCi, (LDOUBLE)28.L);
#endif
	**ppCuc = 11; *Nc() = 7;
	**ppCuc += *Nc();
	iequals(__LINE__, **ppCuc, (UCHAR)18);
	**ppCuc = 11;
	iequals(__LINE__, **ppCuc += *Nc(), (UCHAR)18);
	*Nc() = 7; **ppCuc = 11;
	*Nc() += **ppCuc;
	iequals(__LINE__, *Nc(), (CHAR)18);
	*Nc() = 7;
	iequals(__LINE__, *Nc() += **ppCuc, (CHAR)18);
#if ANSI
	**ppCuc = 11; *Nsc() = 8;
	**ppCuc += *Nsc();
	iequals(__LINE__, **ppCuc, (UCHAR)19);
	**ppCuc = 11;
	iequals(__LINE__, **ppCuc += *Nsc(), (UCHAR)19);
	*Nsc() = 8; **ppCuc = 11;
	*Nsc() += **ppCuc;
	iequals(__LINE__, *Nsc(), (SCHAR)19);
	*Nsc() = 8;
	iequals(__LINE__, *Nsc() += **ppCuc, (SCHAR)19);
#endif
	**ppCuc = 11; *Ns() = 9;
	**ppCuc += *Ns();
	iequals(__LINE__, **ppCuc, (UCHAR)20);
	**ppCuc = 11;
	iequals(__LINE__, **ppCuc += *Ns(), (UCHAR)20);
	*Ns() = 9; **ppCuc = 11;
	*Ns() += **ppCuc;
	iequals(__LINE__, *Ns(), (SHORT)20);
	*Ns() = 9;
	iequals(__LINE__, *Ns() += **ppCuc, (SHORT)20);
	**ppCuc = 11; *Ni() = 10;
	**ppCuc += *Ni();
	iequals(__LINE__, **ppCuc, (UCHAR)21);
	**ppCuc = 11;
	iequals(__LINE__, **ppCuc += *Ni(), (UCHAR)21);
	*Ni() = 10; **ppCuc = 11;
	*Ni() += **ppCuc;
	iequals(__LINE__, *Ni(), (INT)21);
	*Ni() = 10;
	iequals(__LINE__, *Ni() += **ppCuc, (INT)21);
	**ppCuc = 11; *Nuc() = 11;
	**ppCuc += *Nuc();
	iequals(__LINE__, **ppCuc, (UCHAR)22);
	**ppCuc = 11;
	iequals(__LINE__, **ppCuc += *Nuc(), (UCHAR)22);
	*Nuc() = 11; **ppCuc = 11;
	*Nuc() += **ppCuc;
	iequals(__LINE__, *Nuc(), (UCHAR)22);
	*Nuc() = 11;
	iequals(__LINE__, *Nuc() += **ppCuc, (UCHAR)22);
	**ppCuc = 11; *Nus() = 12;
	**ppCuc += *Nus();
	iequals(__LINE__, **ppCuc, (UCHAR)23);
	**ppCuc = 11;
	iequals(__LINE__, **ppCuc += *Nus(), (UCHAR)23);
	*Nus() = 12; **ppCuc = 11;
	*Nus() += **ppCuc;
	iequals(__LINE__, *Nus(), (USHORT)23);
	*Nus() = 12;
	iequals(__LINE__, *Nus() += **ppCuc, (USHORT)23);
	**ppCuc = 11; *Nui() = 13;
	**ppCuc += *Nui();
	iequals(__LINE__, **ppCuc, (UCHAR)24);
	**ppCuc = 11;
	iequals(__LINE__, **ppCuc += *Nui(), (UCHAR)24);
	*Nui() = 13; **ppCuc = 11;
	*Nui() += **ppCuc;
	iequals(__LINE__, *Nui(), (UINT)24);
	*Nui() = 13;
	iequals(__LINE__, *Nui() += **ppCuc, (UINT)24);
	**ppCuc = 11; *Nl() = 14;
	**ppCuc += *Nl();
	iequals(__LINE__, **ppCuc, (UCHAR)25);
	**ppCuc = 11;
	iequals(__LINE__, **ppCuc += *Nl(), (UCHAR)25);
	*Nl() = 14; **ppCuc = 11;
	*Nl() += **ppCuc;
	lequals(__LINE__, *Nl(), (LONG)25L);
	*Nl() = 14;
	lequals(__LINE__, *Nl() += **ppCuc, (LONG)25L);
	**ppCuc = 11; *Nul() = 15;
	**ppCuc += *Nul();
	iequals(__LINE__, **ppCuc, (UCHAR)26);
	**ppCuc = 11;
	iequals(__LINE__, **ppCuc += *Nul(), (UCHAR)26);
	*Nul() = 15; **ppCuc = 11;
	*Nul() += **ppCuc;
	lequals(__LINE__, *Nul(), (ULONG)26L);
	*Nul() = 15;
	lequals(__LINE__, *Nul() += **ppCuc, (ULONG)26L);
	**ppCuc = 11; *Nf() = 16;
	**ppCuc += *Nf();
	iequals(__LINE__, **ppCuc, (UCHAR)27);
	**ppCuc = 11;
	iequals(__LINE__, **ppCuc += *Nf(), (UCHAR)27);
	*Nf() = 16; **ppCuc = 11;
	*Nf() += **ppCuc;
	dequals(__LINE__, *Nf(), (FLOAT)27.);
	*Nf() = 16;
	dequals(__LINE__, *Nf() += **ppCuc, (FLOAT)27.);
	**ppCuc = 11; *Nd() = 17;
	**ppCuc += *Nd();
	iequals(__LINE__, **ppCuc, (UCHAR)28);
	**ppCuc = 11;
	iequals(__LINE__, **ppCuc += *Nd(), (UCHAR)28);
	*Nd() = 17; **ppCuc = 11;
	*Nd() += **ppCuc;
	dequals(__LINE__, *Nd(), (DOUBLE)28.);
	*Nd() = 17;
	dequals(__LINE__, *Nd() += **ppCuc, (DOUBLE)28.);
#if ANSI
	**ppCuc = 11; *Nld() = 18;
	**ppCuc += *Nld();
	iequals(__LINE__, **ppCuc, (UCHAR)29);
	**ppCuc = 11;
	iequals(__LINE__, **ppCuc += *Nld(), (UCHAR)29);
	*Nld() = 18; **ppCuc = 11;
	*Nld() += **ppCuc;
	ldequals(__LINE__, *Nld(), (LDOUBLE)29.L);
	*Nld() = 18;
	ldequals(__LINE__, *Nld() += **ppCuc, (LDOUBLE)29.L);
#endif
	**ppCus = 12; *Nc() = 7;
	**ppCus += *Nc();
	iequals(__LINE__, **ppCus, (USHORT)19);
	**ppCus = 12;
	iequals(__LINE__, **ppCus += *Nc(), (USHORT)19);
	*Nc() = 7; **ppCus = 12;
	*Nc() += **ppCus;
	iequals(__LINE__, *Nc(), (CHAR)19);
	*Nc() = 7;
	iequals(__LINE__, *Nc() += **ppCus, (CHAR)19);
#if ANSI
	**ppCus = 12; *Nsc() = 8;
	**ppCus += *Nsc();
	iequals(__LINE__, **ppCus, (USHORT)20);
	**ppCus = 12;
	iequals(__LINE__, **ppCus += *Nsc(), (USHORT)20);
	*Nsc() = 8; **ppCus = 12;
	*Nsc() += **ppCus;
	iequals(__LINE__, *Nsc(), (SCHAR)20);
	*Nsc() = 8;
	iequals(__LINE__, *Nsc() += **ppCus, (SCHAR)20);
#endif
	**ppCus = 12; *Ns() = 9;
	**ppCus += *Ns();
	iequals(__LINE__, **ppCus, (USHORT)21);
	**ppCus = 12;
	iequals(__LINE__, **ppCus += *Ns(), (USHORT)21);
	*Ns() = 9; **ppCus = 12;
	*Ns() += **ppCus;
	iequals(__LINE__, *Ns(), (SHORT)21);
	*Ns() = 9;
	iequals(__LINE__, *Ns() += **ppCus, (SHORT)21);
	**ppCus = 12; *Ni() = 10;
	**ppCus += *Ni();
	iequals(__LINE__, **ppCus, (USHORT)22);
	**ppCus = 12;
	iequals(__LINE__, **ppCus += *Ni(), (USHORT)22);
	*Ni() = 10; **ppCus = 12;
	*Ni() += **ppCus;
	iequals(__LINE__, *Ni(), (INT)22);
	*Ni() = 10;
	iequals(__LINE__, *Ni() += **ppCus, (INT)22);
	**ppCus = 12; *Nuc() = 11;
	**ppCus += *Nuc();
	iequals(__LINE__, **ppCus, (USHORT)23);
	**ppCus = 12;
	iequals(__LINE__, **ppCus += *Nuc(), (USHORT)23);
	*Nuc() = 11; **ppCus = 12;
	*Nuc() += **ppCus;
	iequals(__LINE__, *Nuc(), (UCHAR)23);
	*Nuc() = 11;
	iequals(__LINE__, *Nuc() += **ppCus, (UCHAR)23);
	**ppCus = 12; *Nus() = 12;
	**ppCus += *Nus();
	iequals(__LINE__, **ppCus, (USHORT)24);
	**ppCus = 12;
	iequals(__LINE__, **ppCus += *Nus(), (USHORT)24);
	*Nus() = 12; **ppCus = 12;
	*Nus() += **ppCus;
	iequals(__LINE__, *Nus(), (USHORT)24);
	*Nus() = 12;
	iequals(__LINE__, *Nus() += **ppCus, (USHORT)24);
	**ppCus = 12; *Nui() = 13;
	**ppCus += *Nui();
	iequals(__LINE__, **ppCus, (USHORT)25);
	**ppCus = 12;
	iequals(__LINE__, **ppCus += *Nui(), (USHORT)25);
	*Nui() = 13; **ppCus = 12;
	*Nui() += **ppCus;
	iequals(__LINE__, *Nui(), (UINT)25);
	*Nui() = 13;
	iequals(__LINE__, *Nui() += **ppCus, (UINT)25);
	**ppCus = 12; *Nl() = 14;
	**ppCus += *Nl();
	iequals(__LINE__, **ppCus, (USHORT)26);
	**ppCus = 12;
	iequals(__LINE__, **ppCus += *Nl(), (USHORT)26);
	*Nl() = 14; **ppCus = 12;
	*Nl() += **ppCus;
	lequals(__LINE__, *Nl(), (LONG)26L);
	*Nl() = 14;
	lequals(__LINE__, *Nl() += **ppCus, (LONG)26L);
	**ppCus = 12; *Nul() = 15;
	**ppCus += *Nul();
	iequals(__LINE__, **ppCus, (USHORT)27);
	**ppCus = 12;
	iequals(__LINE__, **ppCus += *Nul(), (USHORT)27);
	*Nul() = 15; **ppCus = 12;
	*Nul() += **ppCus;
	lequals(__LINE__, *Nul(), (ULONG)27L);
	*Nul() = 15;
	lequals(__LINE__, *Nul() += **ppCus, (ULONG)27L);
	**ppCus = 12; *Nf() = 16;
	**ppCus += *Nf();
	iequals(__LINE__, **ppCus, (USHORT)28);
	**ppCus = 12;
	iequals(__LINE__, **ppCus += *Nf(), (USHORT)28);
	}}
	return 	report(Filename);
	}
