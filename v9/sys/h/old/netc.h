#define NETVERSION	1	/* protocol variant */

#define NSTAT	1
#define NWRT	2
#define NREAD	3
#define NFREE	4
#define NTRUNC	5
#define NUPDAT	6
#define NGET	7
#define NNAMI	8
#define NPUT	9
#define NROOT	10
#define NDEL	11
#define NLINK	12
#define NCREAT	13
#define NOMATCH	14
#define NSTART	15
#define NIOCTL	16
#define NMKDIR	17
#define	NRMDIR	18

struct sendc {	/* not space efficient */
	char version;
	char cmd;
	char flags;	/* now only for nami */
	char rsvd;
	long trannum;
	short uid;
	short gid;
	short dev;	/* server may be using several */
	short pad;
	long tag;
	long mode;
	short newuid;	/* for updat */
	short newgid;
	long ino;
	long count;
	long offset;
	char *buf;
	time_t ta;
	time_t tm;
};

struct rcvc {	/* not space efficient either */
	long trannum;
	char errno;
	char flags;	/* NROOT for nami */
	short dev;
	long size;
	short mode;
	short uid;
	short gid;
	short pad;
	long tag;
	short nlink;
	short rsvd;
	long ino;	/* back from nami */
	long count;	/* count or loc for nami to use */
	time_t tm[3];
};

extern long trannum;
