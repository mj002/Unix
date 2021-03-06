/*
 * Copyright (c) 1983 The Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

#ifndef lint
char copyright[] =
"@(#) Copyright (c) 1983 The Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */

#ifndef lint
static char sccsid[] = "@(#)gettable.c	5.4 (Berkeley) 10/11/88";
#endif /* not lint */

#include <sys/types.h>

#include <stdio.h>
#include <ipc.h>


#define	OUTFILE		"hosts.txt"	/* default output file */
#define	VERFILE		"hosts.ver"	/* default version file */
#define	QUERY		"ALL\r\n"	/* query to hostname server */
#define	VERSION		"VERSION\r\n"	/* get version number */

#define	equaln(s1, s2, n)	(!strncmp(s1, s2, n))

char	buf[BUFSIZ];
char	*outfile = OUTFILE;

main(argc, argv)
	int argc;
	char *argv[];
{
	int s;
	register len;
	register FILE *sfi, *sfo, *hf;
	char *host;
	register struct hostent *hp;
	struct servent *sp;
	int version = 0;
	int beginseen = 0;
	int endseen = 0;

	argv++, argc--;
	if (**argv == '-') {
		if (argv[0][1] != 'v')
			fprintf(stderr, "unknown option %s ignored\n", *argv);
		else
			version++, outfile = VERFILE;
		argv++, argc--;
	}
	if (argc < 1 || argc > 2) {
		fprintf(stderr, "usage: gettable [-v] host [ file ]\n");
		exit(1);
	}
	host = *argv;
	argv++, argc--;
	if ((s = ipcopen(ipcpath(host, "tcp", "hostnames")))< 0) {
		fprintf(stderr, "gettable: connect: %s\n", errstr);
		exit(6);
	}
	if (argc > 0)
		outfile = *argv;
	sfi = fdopen(s, "r");
	sfo = fdopen(s, "w");
	if (sfi == NULL || sfo == NULL) {
		perror("gettable: fdopen");
		close(s);
		exit(1);
	}
	hf = fopen(outfile, "w");
	if (hf == NULL) {
		fprintf(stderr, "gettable: "); perror(outfile);
		close(s);
		exit(1);
	}
	fprintf(sfo, version ? VERSION : QUERY);
	fflush(sfo);
	while (fgets(buf, sizeof(buf), sfi) != NULL) {
		len = strlen(buf);
		buf[len-2] = '\0';
		if (!version && equaln(buf, "BEGIN", 5)) {
			if (beginseen || endseen) {
				fprintf(stderr,
				    "gettable: BEGIN sequence error\n");
				exit(90);
			}
			beginseen++;
			continue;
		}
		if (!version && equaln(buf, "END", 3)) {
			if (!beginseen || endseen) {
				fprintf(stderr,
				    "gettable: END sequence error\n");
				exit(91);
			}
			endseen++;
			continue;
		}
		if (equaln(buf, "ERR", 3)) {
			fprintf(stderr,
			    "gettable: hostname service error: %s", buf);
			exit(92);
		}
		fprintf(hf, "%s\n", buf);
	}
	fclose(hf);
	if (!version) {
		if (!beginseen) {
			fprintf(stderr, "gettable: no BEGIN seen\n");
			exit(93);
		}
		if (!endseen) {
			fprintf(stderr, "gettable: no END seen\n");
			exit(94);
		}
	}
	close(s);
	exit(0);
}
