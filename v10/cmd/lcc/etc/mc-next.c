/* NeXTs running NeXT MACH 4.3 at Princeton University */

#include <string.h>

char *cpp[] = { "/lib/cpp", "-undef", "-DNeXT", "-Dmc68030", "-DMACH", "$1", "$2", "$3", 0 };
char *include[] = { "-I/usr/local/include/ansi", 0 };
char *com[] = { "/usr/local/lib/rcc", "$1", "$2", "$3", 0 };
char *as[] = { "/bin/as", "-o", "$3", "$1", "$2", 0 };
char *ld[] = { "/bin/ld", "-o", "$3", "-lcrt0.o", "$1", "$2", "-lm", "-lc", 0 };

int option(arg) char *arg; {
	if (strcmp(arg, "-g") == 0)
		;
	else if (strcmp(arg, "-p") == 0) {
		ld[3] = "-lmcrt0.o";
		ld[7] = "-lc_p";
	} else if (strcmp(arg, "-pg") == 0) {
		ld[3] = "-lgcrt0.o";
		ld[7] = "-lc_p";
	} else if (strcmp(arg, "-f68881") == 0)
		;
	else
		return 0;
	return 1;
}
