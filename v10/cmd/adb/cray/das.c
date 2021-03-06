/*
 * cray disassembler
 */

#include "defs.h"
#include "space.h"

#define	FBIG	1
#define	FPAR	2
#define	FWRD	4

static struct optab {
	int op;
	int mask;
	int mbnz;
	int flag;
	char *name;
} optab[] = {
	0000000, 0177777, 0, 0, "err",
	0001000, 0177707, 0, 0, "%ca,%a$j\t1",
	0001100, 0177707, 0, 0, "%cl,%a$j\t1",
	0001000, 0177700, 0, 0, "%ca,%a$j\t%a$k",
	0001100, 0177700, 0, 0, "%cl,%a$j\t%a$k",
	0001200, 0177707, 0, 0, "%ci,%a$j",
	0001201, 0177707, 0, 0, "%mc,%a$j",
	0001300, 0177777, 0, 0, "%xa\t0",
	0001300, 0177707, 0, 0, "%xa\t%a$j",
	0001400, 0177777, 0, 0, "%rt\t0",
	0001400, 0177707, 0, 0, "%rt\t%s$j",
	0001401, 0177777, 0, 0, "%ip\t1",
	0001402, 0177777, 0, 0, "%ip\t0",
	0001403, 0177777, 0, 0, "%cln\t0",
	0001413, 0177777, 0, 0, "%cln\t1",
	0001423, 0177777, 0, 0, "%cln\t2",
	0001433, 0177777, 0, 0, "%cln\t3",
	0001404, 0177777, 0, 0, "%pci\t0",
	0001404, 0177707, 0, 0, "%pci\t%s$j",
	0001405, 0177777, 0, 0, "cci",
	0001406, 0177777, 0, 0, "eci",
	0001407, 0177777, 0, 0, "dci",
	0002000, 0177777, 0, 0, "%vl\t1",
	0002000, 0177770, 0, 0, "%vl\t%a$k",
	0002100, 0177777, 0, 0, "efi",
	0002200, 0177777, 0, 0, "dfi",
	0002300, 0177777, 0, 0, "eri",
	0002400, 0177777, 0, 0, "dri",
	0002500, 0177777, 0, 0, "dbm",
	0002600, 0177777, 0, 0, "ebm",
	0002700, 0177777, 0, 0, "cmr",
	0003000, 0177777, 0, 0, "%vm\t0",
	0003000, 0177707, 0, 0, "%vm\t%s$j",
	0003400, 0177700, 0, 0, "%sm$j$k\t1,ts",
	0003600, 0177700, 0, 0, "%sm$j$k\t0",
	0003700, 0177700, 0, 0, "%sm$j$k\t1",
	0004000, 0177777, 0, 0, "ex",
	0005000, 0177700, 0, 0, "j\t%b$j$k",
	0006000, 0177000, 0, FBIG|FPAR, "j\t$X",
	0007000, 0177000, 0, FBIG|FPAR, "r\t$X",
	0010000, 0177000, 0, FBIG|FPAR, "jaz\t$X",
	0011000, 0177000, 0, FBIG|FPAR, "jan\t$X",
	0012000, 0177000, 0, FBIG|FPAR, "jap\t$X",
	0013000, 0177000, 0, FBIG|FPAR, "jam\t$X",
	0014000, 0177000, 0, FBIG|FPAR, "jsz\t$X",
	0015000, 0177000, 0, FBIG|FPAR, "jsn\t$X",
	0016000, 0177000, 0, FBIG|FPAR, "jsp\t$X",
	0017000, 0177000, 0, FBIG|FPAR, "jsm\t$X",
	0020000, 0177000, 0, FBIG|FWRD, "%a$i\t$x",
	0021000, 0177000, 0, FBIG|FWRD, "%a$i\t~$x",
	0022000, 0177000, 0, FWRD, "%a$i\t$y",
	0023000, 0177077, 0, 0, "%a$i\t0",
	0023000, 0177007, 0, 0, "%a$i\t%s$j",
	0023001, 0177077, 0, 0, "%a$i\tvl",
	0024000, 0177000, 0, 0, "%a$i\t%b$j$k",
	0025000, 0177000, 0, 0, "%b$j$k\t%a$i",
	0026000, 0177007, 0, 0, "%a$i\t%ps$j",
	0026001, 0177007, 0, 0, "%a$i\t%qs$j",
	0026007, 0177007, 0, 0, "%a$i\t%sb$j",
	0027000, 0177007, 0, 0, "%a$i\t%zs$j",
	0027007, 0177007, 0, 0, "%zs$j\t%a$i",
	0030000, 0177070, 07, 0, "%a$i\t%a$k",
	0030000, 0177007, 070, 0, "%a$i\t%a$j+1",
	0030000, 0177000, 0, 0, "%a$i\t%a$j+%a$k",
	0031000, 0177077, 0, 0, "%a$i\t-1",
	0031000, 0177070, 07, 0, "%a$i\t-%a$k",
	0031000, 0177007, 070, 0, "%a$i\t%a$j-1",
	0031000, 0177000, 0, 0, "%a$i\t%a$j-%a$k",
	0032000, 0177070, 07, 0, "%a$i\t0*%a$k",
	0032000, 0177007, 070, 0, "%a$i\t%a$j*1",
	0032000, 0177000, 0, 0, "%a$i\t%a$j*%a$k",
	0033000, 0177077, 0, 0, "%a$i\t%ci",
	0033000, 0177007, 0, 0, "%a$i\t%ca,%a$j",
	0033001, 0177007, 0, 0, "%a$i\t%ce,%a$j",
	0034000, 0177000, 0, 0, "%b$j$k,%a$i\t,%a0",
	0035000, 0177000, 0, 0, ",%a0\t%b$j$k,%a$i",
	0036000, 0177000, 0, 0, "%t$j$k,%a$i\t,%a0",
	0037000, 0177000, 0, 0, ",%a0\t%t$j$k,%a$i",
	0040000, 0177000, 0, FBIG, "%s$i\t$x",
	0041000, 0177000, 0, FBIG, "%s$i\t~$x",
	0042000, 0177077, 0, 0, "%s$i\t-1",
	0042077, 0177077, 0, 0, "%s$i\t1",
	0042000, 0177000, 0, 0, "%s$i\t<$x",
	0043000, 0177077, 0, 0, "%s$i\t0",
	0043000, 0177000, 0, 0, "%s$i\t>$x",
	0044000, 0177007, 0, 0, "%s$i\t%s$j&%sb",
	0044000, 0177000, 0, 0, "%s$i\t%s$j&%s$k",
	0045000, 0177007, 0, 0, "%s$i\t%s$j&~%sb",
	0045000, 0177000, 0, 0, "%s$i\t%s$j&~%s$k",
	0046000, 0177007, 0, 0, "%s$i\t%s$j^%sb",
	0046000, 0177000, 0, 0, "%s$i\t%s$j^%s$k",
	0047000, 0177007, 0, 0, "%s$i\t%s$j^~%sb",
	0047000, 0177000, 0, 0, "%s$i\t%s$j^~%s$k",
	0050000, 0177007, 0, 0, "%s$i\t%s$j!%s$i&%sb",
	0050000, 0177000, 0, 0, "%s$i\t%s$j!%s$i&%s$k",
	0051000, 0177077, 0, 0, "%s$i\t%sb",
	0051000, 0177007, 070, 0, "%s$i\t%s$j|%sb",
	0051000, 0177070, 07, 0, "%s$i\t%s$k|0",
	0051000, 0177000, 0, 0, "%s$i\t%s$j|%s$k",
	0052000, 0177000, 0, 0, "%s0\t%s$i<<$y",
	0053000, 0177000, 0, 0, "%s0\t%s$i>>$z",
	0054000, 0177000, 0, 0, "%s$i\t%s$i<<$y",
	0055000, 0177000, 0, 0, "%s$i\t%s$i>>$z",
	0056000, 0177007, 070, 0, "%s$i\t%s$i,$s$j<<1",
	0056000, 0177070, 07, 0, "%s$i\t%s$i<<%a$k",
	0056000, 0177000, 0, 0, "%s$i\t%s$i,%s$j<<%a$k",
	0057000, 0177007, 070, 0, "%s$i\t%s$i,$s$j>>1",
	0057000, 0177070, 07, 0, "%s$i\t%s$i>>%a$k",
	0057000, 0177000, 0, 0, "%s$i\t%s$i,%s$j>>%a$k",
	0060000, 0177070, 07, 0, "%s$i\t0+%s$k",
	0060000, 0177007, 070, 0, "%s$i\t%s$j^%sb",
	0060000, 0177000, 0, 0, "%s$i\t%s$j+%s$k",
	0061000, 0177070, 0, 0, "%s$i\t-%s$k",
	0061000, 0177000, 0, 0, "%s$i\t%s$j-%s$k",
	0062000, 0177070, 0, 0, "%s$i\t+%fs$k",
	0062000, 0177000, 0, 0, "%s$i\t%s$j+%fs$k",
	0063000, 0177070, 0, 0, "%s$i\t-%fs$k",
	0063000, 0177000, 0, 0, "%s$i\t%s$j-%fs$k",
	0064000, 0177000, 0, 0, "%s$i\t%s$j*%fs$k",
	0065000, 0177000, 0, 0, "%s$i\t%s$j*%hs$k",
	0066000, 0177000, 0, 0, "%s$i\t%s$j*%rs$k",
	0067000, 0177000, 0, 0, "%s$i\t%s$j*%is$k",
	0070000, 0177007, 0, 0, "%s$i\t/%hs$j",
	0071000, 0177070, 0, 0, "%s$i\t%a$k",
	0071010, 0177070, 0, 0, "%s$i\t+%a$k",
	0071020, 0177070, 0, 0, "%s$i\t+%fa%k",
	0071030, 0177077, 0, 0, "%s$i\t0.75*2**48",
	0071040, 0177077, 0, 0, "%s$i\t0.5",
	0071050, 0177077, 0, 0, "%s$i\t1.0",
	0071060, 0177077, 0, 0, "%s$i\t2.0",
	0071070, 0177077, 0, 0, "%s$i\t4.0",
	0072000, 0177077, 0, 0, "%s$i\t%rt",
	0072002, 0177077, 0, 0, "%s$i\t%sm",
	0072003, 0177007, 0, 0, "%s$i\t%st$j",
	0073000, 0177077, 0, 0, "%s$i\t%vm",
	0073001, 0177007, 0, 0, "%s$i\t%sr$j",
	0073002, 0177077, 0, 0, "%sm\t%s$i",
	0073003, 0177007, 0, 0, "%st$j\t%s$i",
	0074000, 0177000, 0, 0, "%s$i\t%t$j$k",
	0075000, 0177000, 0, 0, "%t$j$k\t%s$i",
	0076000, 0177000, 0, 0, "%s$i\t%v$j,%a$k",
	0077000, 0177077, 0, 0, "%v$i,1\t0",
	0077000, 0177070, 07, 0, "%v$i,%a$k\t0",
	0077000, 0177007, 070, 0, "%v$i,1\t%s$j",
	0077000, 0177000, 0, 0, "%v$i,%a$k\t%s$j",
	0100000, 0177000, 0, FBIG|FWRD, "%a$i\t$x,0",
	0100000, 0170000, 0, FBIG|FWRD, "%a$i\t$x,%a$h",
	0110000, 0177000, 0, FBIG|FWRD, "$x,0\t%a$i",
	0110000, 0170000, 0, FBIG|FWRD, "$x,%a$h\t%a$i",
	0120000, 0177000, 0, FBIG|FWRD, "%s$i\t$x,0",
	0120000, 0170000, 0, FBIG|FWRD, "%s$i\t$x,%a$h",
	0130000, 0177000, 0, FBIG|FWRD, "$x,0\t%s$i",
	0130000, 0170000, 0, FBIG|FWRD, "$x,%a$h\t%s$i",
	0140000, 0177000, 0, 0, "%v$i\t%s$j&%v$k",
	0141000, 0177000, 0, 0, "%v$i\t%v$j&%v$k",
	0142000, 0177070, 0, 0, "%v$i\t%v$k",
	0142000, 0177000, 0, 0, "%v$i\t%s$j|%v$k",
	0143000, 0177000, 0, 0, "%v$i\t%v$j|%v$k",
	0144000, 0177000, 0, 0, "%v$i\t%s$j^%v$k",
	0145000, 0177000, 0, 0, "%v$i\t%v$j^%v$k",
	0146000, 0177070, 0, 0, "%v$i\t#%vm&%v$k",
	0146000, 0177000, 0, 0, "%v$i\t%s$j!%v$k&%vm",
	0147000, 0177000, 0, 0, "%v$i\t%v$j!%v$k&%vm",
	0150000, 0177007, 0, 0, "%v$i\t%v$j<<1",
	0150000, 0177000, 0, 0, "%v$i\t%v$j<<%a$k",
	0151000, 0177007, 0, 0, "%v$i\t%v$j>>1",
	0151000, 0177000, 0, 0, "%v$i\t%v$j>>%a$k",
	0152000, 0177007, 0, 0, "%v$i\t%v$j,%v$j<<1",
	0152000, 0177000, 0, 0, "%v$i\t%v$j,%v$j<<%a$k",
	0153000, 0177007, 0, 0, "%v$i\t%v$j,%v$j>>1",
	0153000, 0177000, 0, 0, "%v$i\t%v$j,%v$j>>%a$k",
	0154000, 0177000, 0, 0, "%v$i\t%s$j+%v$k",
	0155000, 0177000, 0, 0, "%v$i\t%v$j+%v$k",
	0156000, 0177070, 0, 0, "%v$i\t-%v$k",
	0156000, 0177000, 0, 0, "%v$i\t%s$j-%v$k",
	0157000, 0177000, 0, 0, "%v$i\t%v$j-%v$k",
	0160000, 0177000, 0, 0, "%v$i\t%s$j*%fv$k",
	0161000, 0177000, 0, 0, "%v$i\t%v$j*%fv$k",
	0162000, 0177000, 0, 0, "%v$i\t%s$j*%hv$k",
	0163000, 0177000, 0, 0, "%v$i\t%v$j*%hv$k",
	0164000, 0177000, 0, 0, "%v$i\t%s$j*%rv$k",
	0165000, 0177000, 0, 0, "%v$i\t%v$j*%rv$k",
	0166000, 0177000, 0, 0, "%v$i\t%s$j*%iv$k",
	0167000, 0177000, 0, 0, "%v$i\t%v$j*%iv$k",
	0170000, 0177070, 0, 0, "%v$i\t+%fv$k",
	0170000, 0177000, 0, 0, "%v$i\t%s$j+%fv$k",
	0171000, 0177000, 0, 0, "%v$i\t%v$j+%fv$k",
	0172000, 0177070, 0, 0, "%v$i\t-%fv$k",
	0172000, 0177000, 0, 0, "%v$i\t%s$j-%fv$k",
	0173000, 0177000, 0, 0, "%v$i\t%v$j-%fv$k",
	0174000, 0177007, 0, 0, "%v$i\t/%hv$j",
	0174001, 0177007, 0, 0, "%v$i\t/%pv$j",
	0174002, 0177007, 0, 0, "%v$i\t/%qv$j",
	0175000, 0177707, 0, 0, "%vm\t%v$j,z",
	0175001, 0177707, 0, 0, "%vm\t%v$j,n",
	0175002, 0177707, 0, 0, "%vm\t%v$j,p",
	0175003, 0177707, 0, 0, "%vm\t%v$j,m",
	0176000, 0177077, 0, 0, "%v$i\t,%a0,1",
	0176000, 0177070, 0, 0, "%v$i\t,%a0,%a$k",
	0177000, 0177707, 0, 0, ",%a0,1\t%v$j",
	0177000, 0177700, 0, 0, ",%a0,%a$k\t%v$j",
	0, 0, 0, 0, 0, 0, NULL
};

printins(isp)
int isp;
{
	register WORD ins;
	register struct optab *op;
	register char *p;
	int oh, oi, oj, ok, om;
	WORD val, xval;
	static char oct[] = "01234567";

	ins = stow(sget(dot, isp));
	ins &= 0177777;		/* hack */
	for (op = optab; op->name; op++) {
		if ((ins & op->mask) != op->op)
			continue;
		if (op->mbnz == 0
		||  (ins & op->mbnz) != 0)
			break;
	}
	dotinc = 2;
	if (op->name == NULL) {
		printf("gok\t%R", ins);
		return;
	}
	om = 0;
	if (op->flag & FBIG) {
		dotinc += 2;
		om = stow(sget(dot+2, isp)) & 0177777;
	}
	oh = (ins >> 9) & 07;
	oi = (ins >> 6) & 07;
	oj = (ins >> 3) & 07;
	ok = ins & 07;
	for (p = op->name; *p; p++) {
		if (*p != '$') {
			printc(*p);
			continue;
		}
		switch (*++p) {
		case 0:
			--p;
			break;

		case 'h':
			printc(oct[oh]);
			break;

		case 'i':
			printc(oct[oi]);
			break;

		case 'j':
			printc(oct[oj]);
			break;

		case 'k':
			printc(oct[ok]);
			break;

		case 'y':	/* jk */
			val = ok|(oj<<3);
			if (op->flag & FPAR) {
				printf("p.");
				val *= 2;
			}
			if (op->flag & FWRD) {
				printf("w.");
				val *= 8;
			}
			psymoff(val, (op->flag & FPAR) ? INSTSP : DATASP, "");
			break;

		case 'z':	/* jk, special case for >> */
			val = 0100 - (ok|(oj<<3));
			psymoff(val, DATASP, "");
			break;

		case 'x':	/* jkm */
			val = om|(ok<<16)|(oj<<19);
			if (op->flag & FPAR) {
				printf("p.");
				val *= 2;
			}
			if (op->flag & FWRD) {
				printf("w.");
				val *= 8;
			}
			psymoff(val, (op->flag & FPAR) ? INSTSP : DATASP, "");
			break;

		case 'X':	/* ijkm */
			val = om|(ok<<16)|(oj<<19)|(oi<<22);
			if (op->flag & FPAR) {
				printf("p.");
				val *= 2;
			}
			if (op->flag & FWRD) {
				printf("w.");
				val *= 8;
			}
			psymoff(val, (op->flag & FPAR) ? INSTSP : DATASP, "");
			break;
		}
	}
}
