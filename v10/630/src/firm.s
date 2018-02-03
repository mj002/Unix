#
#	This file contains the stand-alone jump
# 	table. 
#
#	It loads at 0x200 (absolute)
#

	.file	"vector.s"
	.data
	.align	4
	.globl	Firm
Firm:	.word	abs		# Firm[0]
	.word	aciapaws		# Firm[1]
	.word	aciainit		# Firm[2]
	.word	aciatrint		# Firm[3]
	.word	add		# Firm[4]
	.word	addr		# Firm[5]
	.word	alloc		# Firm[6]
	.word	allocinit		# Firm[7]
	.word	auto1		# Firm[8]
	.word	auto2		# Firm[9]
	.word	auto4		# Firm[10]
	.word	balloc		# Firm[11]
	.word	bfree		# Firm[12]
	.word	binit		# Firm[13]
	.word	bitblt		# Firm[14]
	.word	bramgetstr		# Firm[15]
	.word	bramputstr		# Firm[16]
	.word	ceil		# Firm[17]
	.word	checkbram		# Firm[18]
	.word	cursallow		# Firm[19]
	.word	cursblt		# Firm[20]
	.word	cursinhibit		# Firm[21]
	.word	cursinit		# Firm[22]
	.word	cursset		# Firm[23]
	.word	cursswitch		# Firm[24]
	.word	dellayer		# Firm[25]
	.word	disconnect		# Firm[26]
	.word	div		# Firm[27]
	.word	eqpt		# Firm[28]
	.word	eqrect		# Firm[29]
	.word	excep_int		# Firm[30]
	.word	excep_norm		# Firm[31]
	.word	excep_proc		# Firm[32]
	.word	excep_stack		# Firm[33]
	.word	excep_msg		# Firm[34]
	.word	floor		# Firm[35]
	.word	free		# Firm[36]
	.word	freeall		# Firm[37]
	.word	gcalloc		# Firm[38]
	.word	gcfree		# Firm[39]
	.word	gcfreeall		# Firm[40]
	.word	gcinit		# Firm[41]
	.word	getnum		# Firm[42]
	.word	inset		# Firm[43]
	.word	jline		# Firm[44]
	.word	jlineto		# Firm[45]
	.word	jmove		# Firm[46]
	.word	jmoveto		# Firm[47]
	.word	jpoint		# Firm[48]
	.word	jrectf		# Firm[49]
	.word	jsegment		# Firm[50]
	.word	jstring		# Firm[51]
	.word	jstrwidth		# Firm[52]
	.word	jtexture		# Firm[53]
	.word	kbdchar		# Firm[54]
	.word	kbdinit		# Firm[55]
	.word	kgetc		# Firm[56]
	.word	layerop		# Firm[57]
	.word	lbitblt		# Firm[58]
	.word	lblt		# Firm[59]
	.word	Lbox		# Firm[60]
	.word	Lgrey		# Firm[61]
	.word	load		# Firm[62]
	.word	lpoint		# Firm[63]
	.word	lrectf		# Firm[64]
	.word	lsegment		# Firm[65]
	.word	ltexture		# Firm[66]
	.word	main		# Firm[67]
	.word	menuhit		# Firm[68]
	.word	mul		# Firm[69]
	.word	nap		# Firm[70]
	.word	newlayer		# Firm[71]
	.word	own		# Firm[72]
	.word	pfkey		# Firm[73]
	.word	point		# Firm[74]
	.word	Pt		# Firm[75]
	.word	ptinrect	# Firm[76]
	.word	qclear		# Firm[77]
	.word	qgetc		# Firm[78]
	.word	qinit		# Firm[79]
	.word	qputc		# Firm[80]
	.word	qputstr		# Firm[81]
	.word	raddp		# Firm[82]
	.word	rcvchar		# Firm[83]
	.word	realalloc		# Firm[84]
	.word	realballoc		# Firm[85]
	.word	realgcalloc		# Firm[86]
	.word	reboot		# Firm[87]
	.word	Rect		# Firm[88]
	.word	rectclip	# Firm[89]
	.word	rectf		# Firm[90]
	.word	rectXrect	# Firm[91]
	.word	ringbell		# Firm[92]
	.word	Rpt		# Firm[93]
	.word	rsubp		# Firm[94]
	.word	screenswap		# Firm[95]
	.word	scroll		# Firm[96]
	.word	segment		# Firm[97]
	.word	sendbreak		# Firm[98]
	.word	sendchar		# Firm[99]
	.word	0		# Firm[100]
	.word	setbram		# Firm[101]
	.word	setupdisplay		# Firm[102]
	.word	spl0		# Firm[103]
	.word	spl1		# Firm[104]
	.word	spl4		# Firm[105]
	.word	spl5		# Firm[106]
	.word	spl6		# Firm[107]
	.word	spl7		# Firm[108]
	.word	splx		# Firm[109]
	.word	string		# Firm[110]
	.word	strlen		# Firm[111]
	.word	strwidth		# Firm[112]
	.word	sub		# Firm[113]
	.word	test32		# Firm[114]
	.word	texture		# Firm[115]
	.word	trdisable		# Firm[116]
	.word	trenable		# Firm[117]
	.word	tstdcd		# Firm[118]
	.word	upfront		# Firm[119]
	.word	version		# Firm[120]
	.word	wait		# Firm[121]
	.word	allocb		# Firm[122]
	.word	allocendp		# Firm[123]
	.word	allocstartp		# Firm[124]
	.word	blocked		# Firm[125]
	.word	cbufs		# Firm[126]
	.word	cur		# Firm[127]
	.word	cursor		# Firm[128]
	.word	curtabp		# Firm[129]
	.word	defont		# Firm[130]
	.word	display		# Firm[131]
	.word	dtr		# Firm[132]
	.word	ENDAREA		# Firm[133]
	.word	freelist		# Firm[134]
	.word	interrupt		# Firm[135]
	.word	kbdrepeat		# Firm[136]
	.word	kbdstatus		# Firm[137]
	.word	lback		# Firm[138]
	.word	lfront		# Firm[139]
	.word	maxaddr		# Firm[140]
	.word	mouse		# Firm[141]
	.word	NAVAIL		# Firm[142]
	.word	nextlong		# Firm[143]
	.word	NLONGS		# Firm[144]
	.word	PtCurrent		# Firm[145]
	.word	queues		# Firm[146]
	.word	remote		# Firm[147]
	.word	savecur		# Firm[148]
	.word	stdcurtab		# Firm[149]
	.word	ublocked		# Firm[150]
	.word	usercurtab		# Firm[151]

#
# New entries go here
#
	.word	botbits 	# Firm[152]
	.word	baud_speeds	# Firm[153]
	.word	topbits		# Firm[154]
	.word	ver_str		# Firm[155]
	.word	psendchar	# Firm[156]
	.word	kbdrpt		# Firm[157]

Copies to: ihnp4!research!presotto
