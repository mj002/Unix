/* usage: connect hostname (answer|send|notice) (in|out) program [ args ... ] */

#include <ipc.h>
#include <string.h>
#include "../paths.h"

int
main(int argc, char *argv[])
{
	int fd;
	char ignore;

	if (argc < 5)
		return 1;

	chdir(SDIR);

	fd = ipcopen(ipcpath(argv[1], "dk", "dist"), "heavy bsdauth");

	/* when connecting to a TCP host, soak up the initial NUL byte that
	   the bsdauth option ought to have eaten for us.  (lynch presotto)  */
	if (strncmp(ipcpath(argv[1], "dk", "dist"), "/cs/tcp!", 8) == 0)
		read(fd, &ignore, 1);

	if (fd < 0) {
		perror(argv[1]);
		return 1;
	}

	write(fd, argv[2], strlen(argv[2]) + 1);

	if (strchr(argv[3], 'i'))
		dup2(fd, 0);
	if (strchr(argv[3], 'o'))
		dup2(fd, 1);
	close(fd);
	execv(argv[4], &argv[4]);
}
