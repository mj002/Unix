/* DEC little-endian MIPSes running ULTRIX at Princeton University */

#include <string.h>

char *cpp[] = { "/usr/gnu/lib/gcc-cpp", "-undef", "-DLANGUAGE_C", "-D_LANGUAGE_C",
	"-Dmips", "-Dhost_mips", "-DMIPSEL", "-D_MIPSEL", "$1", "$2", "$3", 0 };
char *com[] =  { "/usr/local/lib/rcc", "$1", "$2", "$3", 0 };
char *include[] = { "-I/usr/local/include/ansi", 0 };
char *as[] =  { "/bin/as", "-o", "$3", "", "$1", "-nocpp", "-EL", "$2", 0 };
char *ld[] =  { "/usr/bin/ld", "-o", "$3", "/usr/lib/crt0.o", "$1", "$2", "", "", "-lm", "-lc", 0 };

int option(arg) char *arg; {
	if (strcmp(arg, "-g") == 0)
		as[3] = "-g";
	else if (strcmp(arg, "-p") == 0) {
		ld[3] = "/usr/lib/mcrt0.o";
		ld[7] = "/usr/lib/libprof1.a";
	} else if (strcmp(arg, "-b") == 0 && access("/usr/local/lib/bbexit.o", 4) == 0)
		ld[6] = "/usr/local/lib/bbexit.o";
	else
		return 0;
	return 1;
}
