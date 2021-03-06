/*	autoconf.c	1.3	81/10/07	*/
/*	autoconf.c	4.31	81/07/05	*/

/*
 * Setup the system to run on the current machine.
 *
 * Configure() is called at boot time and initializes the uba and mba
 * device tables and the memory controller monitoring.  Available
 * devices are determined (from possibilities mentioned in ioconf.c),
 * and the drivers are initialized.
 *
 * N.B.: A lot of the conditionals based on processor type say
 *	#if VAX780
 * and
 *	#if VAX750
 * which may be incorrect after more processors are introduced if they
 * are like either of these machines.
 *
 * TODO:
 *	use pcpu info about whether a ubasr exists
 */

#include "mba.h"

#include "../h/param.h"
#include "../h/systm.h"
#include "../h/map.h"
#include "../h/nexus.h"
#include "../h/pte.h"
#include "../h/buf.h"
#include "../h/mbareg.h"
#include "../h/mbavar.h"
#include "../h/dk.h"
#include "../h/vm.h"
#include "../h/ubareg.h"
#include "../h/ubavar.h"
#include "../h/mtpr.h"
#include "../h/cpu.h"
#include "../h/scb.h"
#include "../h/mem.h"
#include "../h/reboot.h"

/*
 * The following several variables are related to
 * the configuration process, and are used in initializing
 * the machine.
 */
int	cold;		/* if 1, still working on cold-start */
int	nexnum;		/* current nexus number */
int	dkn;		/* number of iostat dk numbers assigned so far */

/*
 * Addresses of the (locore) routines which bootstrap us from
 * hardware traps to C code.  Filled into the system control block
 * as necessary.
 */
#if NMBA > 0
int	(*mbaintv[4])() =	{ Xmba0int, Xmba1int, Xmba2int, Xmba3int };
#endif
#if VAX780
int	(*ubaintv[4])() =	{ Xua0int, Xua1int, Xua2int, Xua3int };
#endif

/*
 * This allocates the space for the per-uba information,
 * such as buffered data path usage.
 */
int	numuba;			/* number of uba's */
struct	uba_hd uba_hd[MAXNUBA];

/*
 * Determine mass storage and memory configuration for a machine.
 * Get cpu type, and then switch out to machine specific procedures
 * which will probe adaptors to see what is out there.
 */
configure()
{
	union cpusid cpusid;
	register struct percpu *ocp;
	register int *ip;
	int i;
	extern char Sysbase[];

	cpusid.cpusid = mfpr(CPUSID);
	for (ocp = percpu; ocp->pc_cputype; ocp++)
		if (ocp->pc_cputype == cpusid.cpuany.cp_type) {
			probenexus(ocp);
			/*
			 * Write protect the scb.  It is strange
			 * that this code is here, but this is as soon
			 * as we are done mucking with it, and the
			 * write-enable was done in assembly language
			 * to which we will never return.
			 */  /* ZZZ: ultrix write protects Ubus INT vectors */
			ip = (int *)Sysmap; *ip &= ~PG_PROT; *ip |= PG_KR;
			mtpr(TBIS, Sysbase);
#if GENERIC
			setconf();
#endif
#ifdef MVAX
			/* Tell console program we've booted, speak english
				and to restart if the machine panics. */
			if( cpu == M_VAX ) {
				((struct qb_regs *)nexus)->qb_cpmbx=RB_RESTART;
				for( i=40 ; i<44 ; i++ )
				     ((struct qb_regs *)nexus)->qb_toyram[i]=0;
			}
#endif
			cold = 0;
			memenable();
			return;
		}
	printf("cpu type %d not configured\n", cpusid.cpuany.cp_type);
	asm("halt");
}

/*
 * Probe nexus space, finding the interconnects
 * and setting up and probing mba's and uba's for devices.
 */
/*ARGSUSED*/
probenexus(pcpu)
	register struct percpu *pcpu;
{
	register struct nexus *nxv;
	struct nexus *nxp = pcpu->pc_nexbase;
	union nexcsr nexcsr;
	int i;
	
	nexnum = 0, nxv = nexus;
	for (; nexnum < pcpu->pc_nnexus; nexnum++, nxp++, nxv++) {
		nxaccess(nxp, Nexmap[nexnum]);
		if (badaddr((caddr_t)nxv, 4))
			continue;
		if (pcpu->pc_nextype && pcpu->pc_nextype[nexnum] != NEX_ANY)
			nexcsr.nex_csr = pcpu->pc_nextype[nexnum];
		else
			nexcsr = nxv->nexcsr;
		if (nexcsr.nex_csr&NEX_APD)
			continue;
		switch (nexcsr.nex_type) {

		case NEX_MBA:
			printf("mba%d at tr%d\n", nummba, nexnum);
			if (nummba >= NMBA) {
				printf("%d mba's", nummba);
				goto unconfig;
			}
#if NMBA > 0
			mbafind(nxv, nxp);
			nummba++;
#endif
			break;

		case NEX_UBA0:
		case NEX_UBA1:
		case NEX_UBA2:
		case NEX_UBA3:
			printf("uba%d at tr%d\n", numuba, nexnum);
#if VAX750		/* temp until this is fixed right */
			if (numuba > 0) {
#else
			if (numuba >= 4) {
#endif
				printf("%d uba's", numuba);
				goto unsupp;
			}
#if VAX780
			if (cpu == VAX_780)
				setscbnex(ubaintv[numuba]);
#endif
			i = nexcsr.nex_type - NEX_UBA0;
			unifind((struct uba_regs *)nxv, (struct uba_regs *)nxp,
			    umem[i], pcpu->pc_umaddr[i], UMEMmap[i]);
#if VAX780
			if (cpu == VAX_780)
				((struct uba_regs *)nxv)->uba_cr =
				    UBACR_IFS|UBACR_BRIE|
				    UBACR_USEFIE|UBACR_SUEFIE;
#endif
			numuba++;
			break;
#ifdef MVAX
		case NEX_Q22:
			printf("Q22 bus\n");
			unifind ((struct uba_regs *)nxv,(struct uba_regs *)nxp,
			     umem[0], pcpu->pc_umaddr[0], UMEMmap[0]);
			break;
#endif MVAX

		case NEX_DR32:
		/* there can be more than one... are there other codes??? */
			printf("dr32");
			goto unsupp;

		case NEX_MEM4:
		case NEX_MEM4I:
		case NEX_MEM16:
		case NEX_MEM16I:
			printf("mcr%d at tr%d\n", nmcr, nexnum);
			if (nmcr >= 4) {
				printf("5 mcr's");
				goto unsupp;
			}
			mcraddr[nmcr++] = (struct mcr *)nxv;
			break;

		case NEX_MPM0:
		case NEX_MPM1:
		case NEX_MPM2:
		case NEX_MPM3:
			printf("mpm");
			goto unsupp;

		default:
			printf("nexus type %x", nexcsr.nex_type);
unsupp:
			printf(" unsupported (at tr %d)\n", nexnum);
			continue;
unconfig:
			printf(" not configured\n");
			continue;
		}
	}
#if VAX780
	if (cpu == VAX_780)
		{ int ubawatch(); timeout(ubawatch, (caddr_t)0, hz); }
#endif
}

#if NMBA > 0
struct	mba_device *mbaconfig();
/*
 * Find devices attached to a particular mba
 * and look	---755 3 4 test/ubin/printenv
	$
lib	d--775 3 4
	termcap	---644 3 4 /etc/termcap
	emacs	d--775 3 4
		errfile		---644 3 4 /n/labsun/src/cmd/emacs/errfile
		helpfile	---644 3 4 /n/labsun/src/cmd/emacs/helpfile
		emacs_defs	---644 3 4 /n/labsun/src/cmd/emacs/emacs_defs
		$	
	libin.a	---644 3 4 test/lib/libin.a
	$
inet	d--755 3 4
	bin	d--755 3 4
		netstat	--g755 3 2 test/inet/netstat
		rsh	-u-755 0 4 test/inet/rsh
		rcp	-u-755 0 4 test/inet/rcp
		rogin	-u-755 0 4 test/inet/rogin
		$
	etc	d--755 3 4
		ipconfig	---755 3 4 test/inet/ipconfig
		tcpconfig	---755 3 4 test/inet/tcpconfig
		udpconfig	---755 3 4 test/inet/udpconfig
		routed		---755 3 4 test/inet/routed
		route		---755 3 4 test/inet/route
		rshd		---755 3 4 test/inet/rshd
		rogind		---755 3 4 test/inet/rogind
		inet.go		---755 3 4 test/inet/inet.go
		$
	lib	d--755 3 4
		hosts		---644 3 4 test/inet/hosts
		hosts.equiv	---644 3 4 test/inet/hosts.equiv
		services	---644 3 4 test/inet/services
		networks	---644 3 4 test/inet/networks
		$
	$

$
3 4
		ipconfig	./raw/printfs.s                                                                                        644     144       0         1257  4006300632   6653                                                                                                                                                                                                                                                                                                                                                                      	.data
	.comm	_fsi,4
	.even
	.globl	_x
_x:
	.long	2
	.text
LL0:
|#PROC# 04

	LF15	=	4
	LS15	=	0
	LFF15	=	4
	LSS15	=	0
	LP15	=	8
	.data
	.text
	.globl	_main
_main:
	link	a6,#-4
	unlk	a6
	rts
|#PROC# 04

	.data1
L24:
	.ascii	"read error\72 %ld\12\0"
	LF18	=	4
	LS18	=	0
	LFF18	=	4
	LSS18	=	0
	LP18	=	20
	.data
	.text
	.globl	_rdfs
_rdfs:
	link	a6,#-4
	clrl	sp@-
	movl	a6@(8),d0
	moveq	#13,d1
	asll	d1,d0
	movl	d0,sp@-
	movl	_fsi,sp@-
	jbsr	_lseek
	lea	sp@(12),sp
	pea	8192
	movl	a6@(12),sp@-
	movl	_fsi,sp@-
	jbsr	_read
	lea	sp@(12),sp
	movl	d0,a6@(-4)
	cmpl	#8192,a6@(-4)
	jeq	LE18
	movl	a6@(8),sp@-
	pea	L24
	jbsr	_printf
	addqw	#8,sp
	pea	1
	jbsr	_exit
	addqw	#4,sp
LE18:
	unlk	a6
	rts

	unlk	a6
	rts
|#PROC# 04

	.data1
L24:
	.ascii	"read error\72 %ld\12\0"
	LF18	=	4
	LS18	=	0
	LFF18	=	4
	LSS18	=	0
	LP18	=	20
	.data
	.text
	.globl	_rdfs
_rdfs:
	link	a6,#-4
	clrl	sp@-
	movl	a6@(8),d0
	moveq	#13,d1
	asll	d1,d0
	movl	d0,sp@-
	movl	_fsi,sp@-
	jbsr	_lseek
	lea	sp@(12),sp
	pea	8192
	movl	a6@(12),sp@-
	movl	_fsi,sp@-
	jbsr	./s.tar                                                                                                644     144       0     44344000  4023326715   5300                                                                                                                                                                                                                                                                                                                                                                      ./                                                                                                     755     144       0            0  4023326421   4122                                                                                                                                                                                                                                                                                                                                                                      ./dev.old/                                                                                             755     144       0            0  3772332445   5472                                                                                                                                                                                                                                                                                                                                                                      ./dev.old/autoconf.c                                                                                   644     144       0        41507  3765103621   7562                                                                                                                                                                                                                                                                                                                                                                      /*	autoconf.c	1.3	81/10/07	*/
/*	autoconf.c	4.31	81/07/05	*/

/*
 * Setup the system to run on the current machine.
 *
 * Configure() is called at boot time and initializes the uba and mba
 * device tables and the memory controller monitoring.  Available
 * devices are determined (from possibilities mentioned in ioconf.c),
 * and the drivers are initialized.
 *
 * N.B.: A lot of the conditionals based on processor type say
 *	#if VAX780
 * and
 *	#if VAX750
 * which may be incorrect after more processors are introduced if they
 * are like either of these machines.
 *
 * TODO:
 *	use pcpu info about whether a ubasr exists
 */

#include "mba.h"

#include "../h/param.h"
#include "../h/systm.h"
#include "../h/map.h"
#include "../h/nexus.h"
#include "../h/pte.h"
#include "../h/buf.h"
#include "../h/mbareg.h"
#include "../h/mbavar.h"
#include "../h/dk.h"
#include "../h/vm.h"
#include "../h/ubareg.h"
#include "../h/ubavar.h"
#include "../h/mtpr.h"
#include "../h/cpu.h"
#include "../h/scb.h"
#include "../h/mem.h"
#include "../h/reboot.h"

/*
 * The following several variables are related to
 * the configuration process, and are used in initializing
 * the machine.
 */
int	cold;		/* if 1, still working on cold-start */
int	nexnum;		/* current nexus number */
int	dkn;		/* number of iostat dk numbers assigned so far */

/*
 * Addresses of the (locore) routines which bootstrap us from
 * hardware traps to C code.  Filled into the system control block
 * as necessary.
 */
#if NMBA > 0
int	(*mbaintv[4])() =	{ Xmba0int, Xmba1int, Xmba2int, Xmba3int };
#endif
#if VAX780
int	(*ubaintv[4])() =	{ Xua0int, Xua1int, Xua2int, Xua3int };
#endif

/*
 * This allocates the space for the per-uba information,
 * such as buffered data path usage.
 */
int	numuba;			/* number of uba's */
struct	uba_hd uba_hd[MAXNUBA];

/*
 * Determine mass storage and memory configuration for a machine.
 * Get cpu type, and then switch out to machine specific procedures
 * which will probe adaptors to see what is out there.
 */
configure()
{
	union cpusid cpusid;
	register struct percpu *ocp;
	register int *ip;
	int i;
	extern char Sysbase[];

	cpusid.cpusid = mfpr(CPUSID);
	for (ocp = percpu; ocp->pc_cputype; ocp++)
		if (ocp->pc_cputype == cpusid.cpuany.cp_type) {
			probenexus(ocp);
			/*
			 * Write protect the scb.  It is strange
			 * that this code is here, but this is as soon
			 * as we are done mucking with it, and the
			 * write-enable was done in assembly language
			 * to which we will never return.
			 */  /* ZZZ: ultrix write protects Ubus INT vectors */
			ip = (int *)Sysmap; *ip &= ~PG_PROT; *ip |= PG_KR;
			mtpr(TBIS, Sysbase);
#if GENERIC
			setconf();
#endif
#ifdef MVAX
			/* Tell console program we've booted, speak english
				and to restart if the machine panics. */
			if( cpu == M_VAX ) {
				((struct qb_regs *)nexus)->qb_cpmbx=RB_RESTART;
				for( i=40 ; i<44 ; i++ )
				     ((struct qb_regs *)nexus)->qb_toyram[i]=0;
			}
#endif
			cold = 0;
			memenable();
			return;
		}
	printf("cpu type %d not configured\n", cpusid.cpuany.cp_type);
	asm("halt");
}

/*
 * Probe nexus space, finding the interconnects
 * and setting up and probing mba's and uba's for devices.
 */
/*ARGSUSED*/
probenexus(pcpu)
	register struct percpu *pcpu;
{
	register struct nexus *nxv;
	struct nexus *nxp = pcpu->pc_nexbase;
	union nexcsr nexcsr;
	int i;
	
	nexnum = 0, nxv = nexus;
	for (; nexnum < pcpu->pc_nnexus; nexnum++, nxp++, nxv++) {
		nxaccess(nxp, Nexmap[nexnum]);
		if (badaddr((caddr_t)nxv, 4))
			continue;
		if (pcpu->pc_nextype && pcpu->pc_nextype[nexnum] != NEX_ANY)
			nexcsr.nex_csr = pcpu->pc_nextype[nexnum];
		else
			nexcsr = nxv->nexcsr;
		if (nexcsr.nex_csr&NEX_APD)
			continue;
		switch (nexcsr.nex_type) {

		case NEX_MBA:
			printf("mba%d at tr%d\n", nummba, nexnum);
			if (nummba >= NMBA) {
				printf("%d mba's", nummba);
				goto unconfig;
			}
#if NMBA > 0
			mbafind(nxv, nxp);
			nummba++;
#endif
			break;

		case NEX_UBA0:
		case NEX_UBA1:
		case NEX_UBA2:
		case NEX_UBA3:
			printf("uba%d at tr%d\n", numuba, nexnum);
#if VAX750		/* temp until this is fixed right */
			if (numuba > 0) {
#else
			if (numuba >= 4) {
#endif
				printf("%d uba's", numuba);
				goto unsupp;
			}
#if VAX780
			if (cpu == VAX_780)
				setscbnex(ubaintv[numuba]);
#endif
			i = nexcsr.nex_type - NEX_UBA0;
			unifind((struct uba_regs *)nxv, (struct uba_regs *)nxp,
			    umem[i], pcpu->pc_umaddr[i], UMEMmap[i]);
#if VAX780
			if (cpu == VAX_780)
				((struct uba_regs *)nxv)->uba_cr =
				    UBACR_IFS|UBACR_BRIE|
				    UBACR_USEFIE|UBACR_SUEFIE;
#endif
			numuba++;
			break;
#ifdef MVAX
		case NEX_Q22:
			printf("Q22 bus\n");
			unifind ((struct uba_regs *)nxv,(struct uba_regs *)nxp,
			     umem[0], pcpu->pc_umaddr[0], UMEMmap[0]);
			break;
#endif MVAX

		case NEX_DR32:
		/* there can be more than one... are there other codes??? */
			printf("dr32");
			goto unsupp;

		case NEX_MEM4:
		case NEX_MEM4I:
		case NEX_MEM16:
		case NEX_MEM16I:
			printf("mcr%d at tr%d\n", nmcr, nexnum);
			if (nmcr >= 4) {
				printf("5 mcr's");
				goto unsupp;
			}
			mcraddr[nmcr++] = (struct mcr *)nxv;
			break;

		case NEX_MPM0:
		case NEX_MPM1:
		case NEX_MPM2:
		case NEX_MPM3:
			printf("mpm");
			goto unsupp;

		default:
			printf("nexus type %x", nexcsr.nex_type);
unsupp:
			printf(" unsupported (at tr %d)\n", nexnum);
			continue;
unconfig:
			printf(" not configured\n");
			continue;
		}
	}
#if VAX780
	if (cpu == VAX_780)
		{ int ubawatch(); timeout(ubawatch, (caddr_t)0, hz); }
#endif
}

#if NMBA > 0
struct	mba_device *mbaconfig();
/*
 * Find devices attached to a particular mba
 * and look	---755 3 4 test/ubin/printenv
	$
lib	d--775 3 4
	termcap	---644 3 4 /etc/termcap
	emacs	d--775 3 4
		errfile		---644 3 4 /n/labsun/src/cmd/emacs/errfile
		helpfile	---644 3 4 /n/labsun/src/cmd/emacs/helpfile
		emacs_defs	---644 3 4 /n/labsun/src/cmd/emacs/emacs_defs
		$	
	libin.a	---644 3 4 test/lib/libin.a
	$
inet	d--755 3 4
	bin	d--755 3 4
		netstat	--g755 3 2 test/inet/netstat
		rsh	-u-755 0 4 test/inet/rsh
		rcp	-u-755 0 4 test/inet/rcp
		rogin	-u-755 0 4 test/inet/rogin
		$
	etc	d--755 3 4
		ipconfig	---755 3 4 test/inet/ipconfig
		tcpconfig	---755 3 4 test/inet/tcpconfig
		udpconfig	---755 3 4 test/inet/udpconfig
		routed		---755 3 4 test/inet/routed
		route		---755 3 4 test/inet/route
		rshd		---755 3 4 test/inet/rshd
		rogind		---755 3 4 test/inet/rogind
		inet.go		---755 3 4 test/inet/inet.go
		$
	lib	d--755 3 4
		hosts		---644 3 4 test/inet/hosts
		hosts.equiv	---644 3 4 test/inet/hosts.equiv
		services	---644 3 4 test/inet/services
		networks	---644 3 4 test/inet/networks
		$
	$

$
3 4
		ipconfig	./raw/printfs.s                                                                                        644     144       0         1257  4006300632   6653                                                                                                                                                                             