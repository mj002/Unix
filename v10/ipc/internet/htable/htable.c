/*
 * htable - convert NIC host table into a UNIX format.
 * NIC format is described in RFC 810, 1 March 1982.
 */
#include <stdio.h>
#include <ctype.h>
#include <errno.h>
#include <sys/types.h>

#include "htable.h"


#define	DATELINES	3	/* these lines usually contain the date */
#define	MAXNETS		30	/* array size for local, connected nets */

FILE	*hf;			/* hosts file */
FILE	*gf;			/* gateways file */
FILE	*nf;			/* networks file */
struct gateway *savegateway(), *gatewayto();

int connected_nets[MAXNETS];
int nconnected;
int local_nets[MAXNETS];
int nlocal;
char *myname;

main(argc, argv)
	int argc;
	char *argv[];
{
	int errs;

	infile = "(stdin)";
	myname = argv[0];
	argc--;
	argv++;
	while (argc--) {
		if (*argv[0] == '-') {
			switch (argv[0][1]) {
			case 'c':
				nconnected = addlocal(argv[1], connected_nets);
				argv++;
				argc--;
				break;
			case 'l':
				nlocal = addlocal(argv[1], local_nets);
				argv++;
				argc--;
				break;
			default:
				usage();
				/*NOTREACHED*/
			}
		} else {
			infile = argv[0];
			if (freopen(infile, "r", stdin) == NULL) {
				perror(infile);
				exit(1);
			}
		}
		argv++;
	}
	hf = fopen("hosts", "w");
	if (hf == NULL) {
		perror("hosts");
		exit(1);
	}
	copylocal(hf, "localhosts");
	gf = fopen("gateways", "w");
	if (gf == NULL) {
		perror("gateways");
		exit(1);
	}
	nf = fopen("networks", "w");
	if (nf == NULL) {
		perror("networks");
		exit(1);
	}
	copylocal(nf, "localnetworks");
	copycomments(stdin, hf, DATELINES);
	errs = yyparse();
	exit(errs);
}

usage()
{
	fprintf(stderr,
	"usage: %s [ -c connected-nets ] [-l local-nets ] [ input-file ]\n",
		myname);
	exit(1);
}

/*
 *  Turn a comma-separated list of network names or numbers in dot notation
 *  (e.g.  "arpanet, 128.32") into an array of net numbers.
 */
addlocal(arg, nets)
	char *arg;
	int *nets;
{
	register char *p, c;
	register int nfound = 0;

	do {
		p = arg;
		while (*p && *p != ',' && !isspace(*p))
			p++;
		c = *p;
		*p = 0;
		while (*arg && isspace(*arg))
			arg++;
		if (*arg == 0)
			continue;
		if (nfound == MAXNETS) {
			fprintf(stderr, "%s: Too many networks in list\n",
				myname);
			return (nfound);
		}
		if (getnetaddr(arg, &nets[nfound]))
			nfound++;
		else {
			fprintf(stderr, "%s: %s: unknown network\n",
				myname, arg);
			exit(1);
		}
		arg = p + 1;
	} while (c);
	return (nfound);
}

struct name *
newname(str)
	char *str;
{
	char *p;
	struct name *nm;

	p = malloc(strlen(str) + 1);
	strcpy(p, str);
	nm = (struct name *)malloc(sizeof (struct name));
	nm->name_val = p;
	nm->name_link = NONAME;
	return (nm);
}

char *
lower(str)
	char *str;
{
	register char *cp = str;

	while (*cp) {
		if (isupper(*cp))
			*cp = tolower(*cp);
		cp++;
	}
	return (str);
}

do_entry(keyword, addrlist, namelist, cputype, opsys, protos)
	int keyword;
	struct addr *addrlist;
	struct name *namelist, *cputype, *opsys, *protos;
{
	register struct addr *al, *al2;
	register struct name *nl;
	struct addr *connect_addr;
	char *cp;

	switch (keyword) {

	case KW_NET:
		nl = namelist;
		if (nl == NONAME) {
			fprintf(stderr, "htable: net");
			putnet(stderr, inet_netof(addrlist->addr_val));
			fprintf(stderr, " missing names.\n");
			break;
		}
		fprintf(nf, "%-16.16s", lower(nl->name_val));
		al2 = addrlist;
		while (al = al2) {
			char *cp;

			putnet(nf, inet_netof(al->addr_val));
			cp = "\t%s";
			while (nl = nl->name_link) {
				fprintf(nf, cp, lower(nl->name_val));
				cp = " %s";
			}
			putc('\n', nf);
			al2 = al->addr_link;
			free((char *)al);
		}
		break;

	case KW_GATEWAY:
		/* locate locally connected address, if one */
		for (al = addrlist; al; al = al->addr_link)
			if (connectedto(inet_netof(al->addr_val)))
				break;
		if (al == NULL) {
			/*
			 * Not connected to known networks.  Save for later.
			 */
			struct gateway *gw, *firstgw = (struct gateway *) NULL;

			for (al = addrlist; al; al = al->addr_link) {
				register int net;

				net = inet_netof(al->addr_val);
				gw = savegateway(namelist, net,
				    al->addr_val, 0);
				if (firstgw == (struct gateway *) NULL)
					firstgw = gw;
				gw->g_firstent = firstgw;
			}
			freeaddrs(addrlist);
			goto dontfree;
		}
		/*
		 * Connected to a known network.
		 * Mark this as the gateway to all other networks
		 * that are on the addrlist (unless we already have
		 * gateways to them).
		 */
		connect_addr = al;
		for (al = addrlist; al; al = al->addr_link) {
			register int net;

			/* suppress duplicates -- not optimal */
			net = inet_netof(al->addr_val);
			if (connectedto(net) || gatewayto(net))
				continue;
			printgateway(net, namelist->name_val, 1);
			(void) savegateway(namelist, net, al->addr_val, 1);
		}
		/*
		 * Put the gateway in the hosts file.
		 */
		putaddr(hf, connect_addr->addr_val);
		cp = "%s";
		for (nl = namelist; nl; nl = nl->name_link) {
			fprintf(hf, cp, lower(nl->name_val));
			cp = " %s";
		}
		fprintf(hf, "\t# gateway\n");
		freeaddrs(addrlist);
		goto dontfree;

	case KW_HOST:
		al2 = addrlist;
		while (al = al2) {
			if (!local(inet_netof(al->addr_val))) {
				char *cp;

				putaddr(hf, al->addr_val);
				cp = "%s";
				for (nl = namelist; nl; nl = nl->name_link) {
					fprintf(hf, cp, lower(nl->name_val));
					cp = " %s";
				}
				putc('\n', hf);
			}
			al2 = al->addr_link;
			free((char *)al);
		}
		break;

	default:
		fprintf(stderr, "Unknown keyword: %d.\n", keyword);
	}
	freenames(namelist);
dontfree:
	freenames(protos);
}

copylocal(f, filename)
	FILE *f;
	char *filename;
{
	register FILE *lhf;
	register cc;
	char buf[BUFSIZ];
	extern int errno;

	lhf = fopen(filename, "r");
	if (lhf == NULL) {
		if (errno != ENOENT) {
			perror(filename);
			exit(1);
		}
		fprintf(stderr, "Warning, no %s file.\n", filename);
		return;
	}
	while (cc = fread(buf, 1, sizeof(buf), lhf))
		fwrite(buf, 1, cc, f);
	fclose(lhf);
}

copycomments(in, out, ccount)
	FILE *in, *out;
	int ccount;
{
	int count;
	char buf[BUFSIZ], *fgets();

	for (count=0; count < ccount; count++) {
		if ((fgets(buf, sizeof(buf), in) == NULL) || (buf[0] != ';'))
			return;
		buf[0] = '#';
		fputs(buf, out);
	}
	return;
}
#define	UC(b)	(((int)(b))&0xff)

/*
 * Print network number in internet-standard dot notation;
 * v is in host byte order.
 */
putnet(f, v)
	FILE *f;
	register int v;
{
	if (v < 128)
		fprintf(f, "%d", v);
	else if (v < 65536)
		fprintf(f, "%d.%d", UC(v >> 8), UC(v));
	else
		fprintf(f, "%d.%d.%d", UC(v >> 16), UC(v >> 8), UC(v));
}

putaddr(f, v)
	FILE *f;
	in_addr v;
{
	fprintf(f, "%-16.16s", inet_ntoa(v));
}

freenames(list)
	struct name *list;
{
	register struct name *nl, *nl2;

	nl2 = list;
	while (nl = nl2) {
		nl2 = nl->name_link;
		free(nl->name_val);
		free((char *)nl);
	}
}

freeaddrs(list)
	struct addr *list;
{
	register struct addr *al, *al2;

	al2 = list;
	while (al = al2)
		al2 = al->addr_link, free((char *)al);
}

struct gateway *gateways = 0;
struct gateway *lastgateway = 0;

struct gateway *
gatewayto(net)
	register int net;
{
	register struct gateway *gp;

	for (gp = gateways; gp; gp = gp->g_link)
		if ((gp->g_net == net) && (gp->g_metric > 0))
			return (gp);
	return ((struct gateway *) NULL);
}

struct gateway *
savegateway(namelist, net, addr, metric)
	struct name *namelist;
	in_addr addr;
	int net, metric;
{
	register struct gateway *gp;

	gp = (struct gateway *)malloc(sizeof (struct gateway));
	if (gp == 0) {
		fprintf(stderr, "htable: out of memory\n");
		exit(1);
	}
	gp->g_link = (struct gateway *) NULL;
	if (lastgateway)
		lastgateway->g_link = gp;
	else
		gateways = gp;
	lastgateway = gp;
	gp->g_name = namelist;
	gp->g_net = net;
	gp->g_addr = addr;
	gp->g_metric = metric;
	if (metric == 1)
		gp->g_dst = gp;
	return (gp);
}

connectedto(net)
	u_long net;
{
	register i;

	for (i = 0; i < nconnected; i++)
		if (connected_nets[i] == net)
			return(1);
	return(0);
}

local(net)
	u_long net;
{
	register i;

	for (i = 0; i < nlocal; i++)
		if (local_nets[i] == net)
			return(1);
	return(0);
}
