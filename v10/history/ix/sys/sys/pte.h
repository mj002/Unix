/*
 * VAX page table entry
 *
 * There are two major kinds of pte's: those which have ever existed (and are
 * thus either now in core or on the swap device), and those which have
 * never existed, but which will be filled on demand at first reference.
 * There is a structure describing each.  There is also an ancillary
 * structure used in page clustering.
 */

struct pte
{
unsigned int	pg_pfnum:21,		/* core page frame number or 0 */
		:3,
		pg_swapm:1,		/* have to write back to swap */
		pg_fod:1,		/* is fill on demand (=0) */
		pg_m:1,			/* hardware maintained modified bit */
		pg_prot:4,		/* access control */
		pg_v:1;			/* valid bit */
};
struct hpte
{
unsigned int	pg_pfnum:21,
		:2,
		pg_high:9;		/* special for clustering */
};
struct fpte
{
unsigned int	pg_blkno:20,		/* file system block number */
		:4,
		pg_source:1,		/* TEXT or ZERO */
		pg_fod:1,		/* is fill on demand (=1) */
		:1,
		pg_prot:4,
		pg_v:1;
};

#define	PG_V		0x80000000
#define	PG_PROT		0x78000000
#define	PG_M		0x04000000
#define	PG_FOD		0x02000000
#define	PG_PFNUM	0x001fffff

#define	PG_FZERO	0
#define	PG_FTEXT	1

#define	PG_NOACC	0
#define	PG_KW		0x10000000
#define	PG_KR		0x18000000
#define	PG_UW		0x20000000
#define	PG_URKW		0x70000000
#define	PG_URKR		0x78000000


#ifdef KERNEL
/*
 * Pte related macros
 */
#define	dirty(pte)	((pte)->pg_fod == 0 && (pte)->pg_pfnum && \
			    ((pte)->pg_m || (pte)->pg_swapm))
#define	physadr(a)	((long)(a)&PGOFSET|(Sysmap[((long)(a)&~KSTART)/NBPG].pg_pfnum*NBPG))

struct	pte *vtopte();
struct	pte *btopte();

/* various pointers into the system page table */
extern struct pte *Sysmap;
extern struct pte *Usrptmap;
extern struct pte *usrpt;
extern struct pte *Swapmap;
extern struct pte *Forkmap;
extern struct pte *Xswapmap;
extern struct pte *Xswap2map;
extern struct pte *Pushmap;
extern struct pte *mmap;
extern struct pte *msgbufmap;
extern struct pte *camap;
extern struct pte *Prusrmap;
#endif
