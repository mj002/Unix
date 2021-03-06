/*
    plumber.c - check malloc arena for coreleaks

	author: WJHansen, CMU/ITC
	(c) Copyright IBM Corporation, 1986

Uses the IDENTIFY version of malloc, which stores the return address in the 
header of each block.  

Produces a table showing a description of the set of blocks produced from each calling address.


	WARNING:  if an application does sbrk's of its own, the arena
	will be in multiple segments.  The code here only processes the last of these.

*/
#define IDENTIFY

#include <stdio.h>
#include "malloc.h"

#ifndef IDENTIFY

plumber () {
}

#else

static struct callerdata {
	struct callerdata *left, *right;
	char *caller;
	int nblks;
	long totsize;
	int loseq, hiseq, losize, hisize;
} *data;

plumber (outf) 
    FILE *outf;
{
	register struct arenastate *A = GetMallocArena();
	register int nextseq = A->SeqNo;
	register struct freehdr *t, *f;
	/* scan free list to find segment trailers and scan each segment */
	CheckAllocs("plumber start");

	data = NULL;
	t = A->arenaend;
	f = ((struct freetrlr *)(t+1))->Front;
	/* scan the last arena segment for active blocks */
	for (; f<t; f = (struct freehdr *)((char *)f 
			+ clearbits(f->Size))) 
		if (testbit(f->Size, ACTIVE)
				&& f->seqno<nextseq) 
			storedata(f, &data);
	/* output data from tree */
	fprintf(outf, "%10s%10s%10s%20s%20s\n\n", 
		"caller", "#blocks", "tot size", "size range    ", "seq# range     ");
	printandfreedata(data, outf);
}

    static
storedata (p, d)
    register struct hdr *p;
    struct callerdata **d;
{
    register struct callerdata *td = *d;
	if (td==NULL) {
		*d = td = (struct callerdata *)malloc(sizeof(struct callerdata));
		td->caller = p->caller;
		td->nblks = 1;
		td->loseq = td->hiseq = p->seqno;
		td->losize = td->hisize = td->totsize = clearbits(p->Size);
	}
	else if (p->caller < td->caller)
		storedata (p, &(td->left));
	else if (p->caller > td->caller)
		storedata (p, &(td->right)); 
	else {    /* == */
		int size = clearbits(p->Size);
		td->nblks++;
		if (p->seqno<td->loseq)  td->loseq = p->seqno;
		else if (p->seqno>td->hiseq)  td->hiseq = p->seqno;
		if (size<td->losize)  td->losize = size;
		else if (size>td->hisize)  td->hisize = size;
		td->totsize += size;
	}
}

    static
printandfreedata(d, outf)
    register struct callerdata *d;
    FILE *outf;
{
	if (d) {
		printandfreedata(d->left, outf);
		fprintf (outf, "0x%-8lx%10d%10d%9d-%-10d%9d-%-10d\n",
			d->caller, d->nblks, d->totsize, 
			d->losize, d->hisize, d->loseq, d->hiseq);
		printandfreedata(d->right, outf);
		free(d);
	}
}

/*
 * calloc - allocate and clear memory block
 */

#define CHARPERINT (sizeof(int)/sizeof(char))
#define NULL 0

char *
calloc(num, size)
	unsigned num, size;
{
#define FIRSTARG	num
	register char *mp;
	register int *q;
	register m;

	num *= size;
	mp = malloc(num);
	if (mp == NULL)
		return(NULL);

	/* Stamp pc of caller of calloc in malloc header */
	(((struct hdr *)mp)-1)->caller = *(((char **)&FIRSTARG)-RETADDROFF);

	q = (int *) mp;
	m = (num+CHARPERINT-1)/CHARPERINT;
	while (--m>=0)
		*q++ = 0;
	return (mp);
}

cfree(p, num, size)
	char *p;
	unsigned num, size;
{

	free(p);
}
#endif
