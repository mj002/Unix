/*
 * Structures and definitions for mag tape io control commands
 */

/* mag tape io control commands */
#define MTIOCTOP	(('m'<<8)|1)	/* do a mag tape op */
#define MTIOCGET	(('m'<<8)|2)	/* get mag tape status */
#define MTIOCIEOT	(('m'<<8)|3)	/* ignore EOT error */
#define MTIOCEEOT	(('m'<<8)|4)	/* enable EOT error */

/* structure for MTIOCTOP - mag tape op command */
struct	mtop	{
	short	mt_op;		/* operations defined below */
	daddr_t	mt_count;	/* how many of them */
};

/* operations */
#define MTWEOF	0	/* write an end-of-file record */
#define MTFSF	1	/* forward space file */
#define MTBSF	2	/* backward space file */
#define MTFSR	3	/* forward space record */
#define MTBSR	4	/* backward space record */
#define MTREW	5	/* rewind */
#define MTOFFL	6	/* rewind and put the drive offline */
#define MTNOP	7	/* no operation, sets status only */
#define	MTRST	8	/* reset broken dec tape controller */

/* structure for MTIOCGET - mag tape get status command */

struct	mtget	{
	short	mt_type;	/* type of magtape device */
/* the following two registers are grossly device dependent */
	short	mt_dsreg;	/* ``drive status'' register */
	short	mt_erreg;	/* ``error'' register */
/* end device-dependent registers */
	short	mt_resid;	/* residual count */
/* the following two are not yet implemented */
	daddr_t	mt_fileno;	/* file number of current position */
	daddr_t	mt_blkno;	/* block number of current position */
/* end not yet implemented */
};

/*
 * Constants for mt_type byte
 */
#define MT_ISTS		01
#define MT_ISHT		02
#define MT_ISTM		03
#define	MT_ISMT		04
#define	MT_ISUT		05
#define MT_ISTMSCP	06
