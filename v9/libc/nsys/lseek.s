# C library -- lseek

# error = lseek(file, offset, ptr);

	lseek = 19
.globl	_lseek
.globl  cerror

_lseek:
	linkw	a6,#0
	pea	lseek
	trap	#0
	bcc 	noerror
	jmp 	cerror
noerror:
	unlk	a6
	rts
