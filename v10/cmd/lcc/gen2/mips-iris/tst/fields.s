.set reorder
.globl x
.data; .align 2; x:.word 0x1
.byte 2
.space 3
.byte 0
.byte 52
.space 2
.byte 10
.byte 6
.space 2
.globl i
.sdata; .align 2; i:.word 0x10
.globl y
.sdata; .align 2; y:.byte 224
.space 3
.byte 0
.byte 0
.byte 0
.byte 9
.text
.globl main
.text
.align 2; .ent main
main:
$fp1=32
.frame $sp,32,$31
addu $sp,$sp,-32
.mask 0x80000000,-4
sw $31,28($sp)
la $4,L.4
lw $5,x
lb $6,x+4
lw $25,x+8
sra $7,$25,20
lw $25,x+8
sll $25,$25,12
sra $25,$25,28
sw $25,16($sp)
lw $25,x+12
sll $25,$25,4
sra $25,$25,29
sw $25,20($sp)
lb $25,x+13
sw $25,24($sp)
jal printf  # int
la $4,L.10
lw $25,y
srl $5,$25,30
sll $25,$25,2
srl $6,$25,28
lw $7,y+4
jal printf  # int
lw $25,x+8
and $25,$25,0xfff0ffff
lw $24,i
sll $24,$24,28
sra $24,$24,28
sll $24,$24,16
and $24,$24,0xf0000
or $25,$25,$24
sw $25,x+8
lw $25,x+12
and $25,$25,0xf1ffffff
sw $25,x+12
la $4,L.4
lw $5,x
lb $6,x+4
lw $25,x+8
sra $7,$25,20
lw $25,x+8
sll $25,$25,12
sra $25,$25,28
sw $25,16($sp)
lw $25,x+12
sll $25,$25,4
sra $25,$25,29
sw $25,20($sp)
lb $25,x+13
sw $25,24($sp)
jal printf  # int
lw $25,y
and $25,$25,0x3fffffff
or $25,$25,0x80000000
sw $25,y
lw $25,i
sw $25,y+4
la $4,L.10
lw $25,y
srl $5,$25,30
sll $25,$25,2
srl $6,$25,28
lw $7,y+4
jal printf  # int
la $4,x
jal f2  # int
L.3:
lw $31,28($sp)
addu $sp,$sp,32
j $31
.end main
.globl f1
.text
.align 2; .ent f1
f1:
$fp2=24
.frame $sp,24,$31
addu $sp,$sp,-24
.mask 0xc0000000,-4
sw $30,16($sp)
sw $31,20($sp)
move $30,$4
lw $25,($30)
and $25,$25,0xc3ffffff
sw $25,($30)
lw $25,($30)
and $25,$25,0x3fffffff
and $24,$0,3
sll $24,$24,30
and $24,$24,0xc0000000
or $25,$25,$24
sw $25,($30)
lw $25,($30)
and $25,$25,0x3c000000
beq $25,$0,L.22
la $4,L.24
jal printf  # int
L.22:
lw $25,($30)
or $25,$25,0xc0000000
sw $25,($30)
lw $25,($30)
or $25,$25,0x3c000000
sw $25,($30)
la $4,L.25
lw $25,($30)
srl $5,$25,30
sll $25,$25,2
srl $6,$25,28
jal printf  # int
L.21:
lw $30,16($sp)
lw $31,20($sp)
addu $sp,$sp,24
j $31
.end f1
.globl f2
.text
.align 2; .ent f2
f2:
$fp3=32
.frame $sp,32,$31
addu $sp,$sp,-32
.mask 0xc0800000,-8
sw $23,16($sp)
sw $30,20($sp)
sw $31,24($sp)
move $30,$4
lw $25,i
bne $25,$0,L.28
li $23,1
b L.29
L.28:
move $23,$0
L.29:
lw $25,($30)
and $25,$25,0x3fffffff
and $24,$23,3
sll $24,$24,30
and $24,$24,0xc0000000
or $25,$25,$24
sw $25,($30)
move $4,$30
jal f1  # int
lw $25,($30)
and $25,$25,0xc3ffffff
and $24,$0,15
sll $24,$24,26
and $24,$24,0x3c000000
or $25,$25,$24
sw $25,($30)
L.26:
lw $23,16($sp)
lw $30,20($sp)
lw $31,24($sp)
addu $sp,$sp,32
j $31
.end f2
.rdata
L.25:.ascii "p->a = 0x%x, p->b = 0x%x\012\000"
L.24:.ascii "p->b != 0!\012\000"
L.10:.ascii "y = %d %d %d\012\000"
L.4:.ascii "x = %d %d %d %d %d %d\012\000"
