.set reorder
.text
.globl main
.text
.align 2; .ent main
main:
$fp1=48
.frame $sp,48,$31
addu $sp,$sp,-48
.mask 0x80000000,-32
sw $31,16($sp)
sw $0,$fp1-24($sp)
sw $0,next
b L.3
L.2:
la $4,$fp1-20($sp)
la $5,$fp1-24($sp)
jal lookup  # int
move $25,$2
lw $24,($25)
addu $24,$24,1
sw $24,($25)
L.3:
la $4,$fp1-20($sp)
jal getword  # int
bne $2,$0,L.2
lw $4,$fp1-24($sp)
jal tprint  # int
move $2,$0
L.1:
lw $31,16($sp)
addu $sp,$sp,48
j $31
.end main
.globl err
.text
.align 2; .ent err
err:
$fp2=24
.frame $sp,24,$31
addu $sp,$sp,-24
.mask 0x80000000,-8
sw $31,16($sp)
sw $4,24($sp)
la $4,L.6
lw $5,$fp2+0($sp)
jal printf  # int
li $4,1
jal exit  # int
L.5:
lw $31,16($sp)
addu $sp,$sp,24
j $31
.end err
.globl getword
.text
.align 2; .ent getword
getword:
$fp3=32
.frame $sp,32,$31
addu $sp,$sp,-32
.mask 0xc0800000,-8
sw $23,16($sp)
sw $30,20($sp)
sw $31,24($sp)
sw $4,32($sp)
L.8:
L.9:
jal getchar  # int
move $30,$2
beq $2,-1,L.11
move $4,$30
jal isletter  # int
beq $2,$0,L.8
L.11:
lw $23,$fp3+0($sp)
b L.15
L.12:
move $25,$23
addu $23,$25,1
sb $30,($25)
L.13:
jal getchar  # int
move $30,$2
L.15:
move $4,$30
jal isletter  # int
move $30,$2
bne $2,$0,L.12
sb $0,($23)
lw $25,$fp3+0($sp)
bleu $23,$25,L.16
li $2,1
b L.7
L.16:
move $2,$0
L.7:
lw $23,16($sp)
lw $30,20($sp)
lw $31,24($sp)
addu $sp,$sp,32
j $31
.end getword
.globl isletter
.text
.align 2; .ent isletter
isletter:
$fp4=0
.frame $sp,0,$31
blt $4,65,L.19
bgt $4,90,L.19
addu $4,$4,32
L.19:
blt $4,97,L.21
bgt $4,122,L.21
move $2,$4
b L.18
L.21:
move $2,$0
L.18:
j $31
.end isletter
.globl lookup
.text
.align 2; .ent lookup
lookup:
$fp5=32
.frame $sp,32,$31
addu $sp,$sp,-32
.mask 0xc0000000,-12
sw $30,16($sp)
sw $31,20($sp)
sw $4,32($sp)
move $30,$5
lw $25,($30)
beq $25,$0,L.24
lw $4,$fp5+0($sp)
lw $25,($30)
lw $5,12($25)
jal strcmp  # int
sw $2,$fp5-4($sp)
lw $25,$fp5-4($sp)
bge $25,$0,L.26
lw $4,$fp5+0($sp)
lw $25,($30)
addu $5,$25,4
jal lookup  # int
b L.23
L.26:
lw $25,$fp5-4($sp)
ble $25,$0,L.28
lw $4,$fp5+0($sp)
lw $25,($30)
addu $5,$25,8
jal lookup  # int
b L.23
L.28:
lw $2,($30)
b L.23
L.24:
lw $25,next
blt $25,2000,L.30
la $4,L.32
jal err  # int
L.30:
lw $25,next
sll $25,$25,4
sw $0,words($25)
lw $25,next
sll $25,$25,4
sw $0,words+8($25)
sw $0,words+4($25)
lw $4,$fp5+0($sp)
jal strlen  # int
addu $4,$2,1
jal malloc  # int
lw $25,next
sll $25,$25,4
move $24,$2
sw $24,words+12($25)
lw $25,next
sll $25,$25,4
lw $25,words+12($25)
bne $25,$0,L.36
la $4,L.39
jal err  # int
L.36:
lw $25,next
sll $25,$25,4
lw $4,words+12($25)
lw $5,$fp5+0($sp)
jal strcpy  # int
lw $25,next
addu $24,$25,1
sw $24,next
sll $25,$25,4
la $25,words($25)
sw $25,($30)
move $2,$25
L.23:
lw $30,16($sp)
lw $31,20($sp)
addu $sp,$sp,32
j $31
.end lookup
.globl tprint
.text
.align 2; .ent tprint
tprint:
$fp6=24
.frame $sp,24,$31
addu $sp,$sp,-24
.mask 0xc0000000,-4
sw $30,16($sp)
sw $31,20($sp)
move $30,$4
beq $30,$0,L.42
lw $4,4($30)
jal tprint  # int
la $4,L.44
lw $5,($30)
lw $6,12($30)
jal printf  # int
lw $4,8($30)
jal tprint  # int
L.42:
L.41:
lw $30,16($sp)
lw $31,20($sp)
addu $sp,$sp,24
j $31
.end tprint
.globl strcmp
.text
.align 2; .ent strcmp
strcmp:
$fp7=0
.frame $sp,0,$31
b L.47
L.46:
move $25,$4
addu $4,$25,1
lb $25,($25)
bne $25,$0,L.49
move $2,$0
b L.45
L.49:
addu $5,$5,1
L.47:
lb $25,($4)
lb $24,($5)
beq $25,$24,L.46
lb $25,($4)
bne $25,$0,L.51
li $2,-1
b L.45
L.51:
lb $25,($5)
bne $25,$0,L.53
li $2,1
b L.45
L.53:
lb $25,($4)
lb $24,($5)
subu $2,$25,$24
L.45:
j $31
.end strcmp
.globl next
.comm next,4
.globl words
.comm words,32000
.rdata
L.44:.ascii "%d\011%s\012\000"
L.39:.ascii "out of word storage\000"
L.32:.ascii "out of node storage\000"
L.6:.ascii "? %s\012\000"
