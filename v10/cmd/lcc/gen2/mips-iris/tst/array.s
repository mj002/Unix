.set reorder
.text
.globl main
.text
.align 2; .ent main
main:
$fp1=80
.frame $sp,80,$31
addu $sp,$sp,-80
.mask 0xc0c00000,-52
sw $22,16($sp)
sw $23,20($sp)
sw $30,24($sp)
sw $31,28($sp)
move $23,$0
L.2:
move $30,$0
L.6:
sll $25,$30,2
sll $24,$23,4
la $24,x($24)
addu $25,$25,$24
li $24,1000
mul $24,$24,$23
addu $24,$24,$30
sw $24,($25)
L.7:
addu $30,$30,1
blt $30,4,L.6
sll $25,$23,2
sll $24,$23,4
la $24,x($24)
sw $24,y($25)
L.3:
addu $23,$23,1
blt $23,3,L.2
jal f  # int
move $23,$0
L.10:
sll $25,$23,4
la $24,$fp1-48($sp)
addu $25,$25,$24
move $22,$25
sll $24,$23,2
sw $25,y($24)
move $30,$0
L.14:
sll $25,$30,2
addu $24,$25,$22
sll $15,$23,4
la $15,x($15)
addu $25,$25,$15
lw $25,($25)
sw $25,($24)
L.15:
addu $30,$30,1
blt $30,4,L.14
L.11:
addu $23,$23,1
blt $23,3,L.10
la $4,$fp1-48($sp)
la $5,y
jal g  # int
move $2,$0
L.1:
lw $22,16($sp)
lw $23,20($sp)
lw $30,24($sp)
lw $31,28($sp)
addu $sp,$sp,80
j $31
.end main
.globl f
.text
.align 2; .ent f
f:
$fp2=32
.frame $sp,32,$31
addu $sp,$sp,-32
.mask 0xc0800000,-8
sw $23,16($sp)
sw $30,20($sp)
sw $31,24($sp)
move $23,$0
L.19:
move $30,$0
L.23:
la $4,L.27
sll $25,$30,2
sll $24,$23,4
la $24,x($24)
addu $25,$25,$24
lw $5,($25)
jal printf  # int
L.24:
addu $30,$30,1
blt $30,4,L.23
L.20:
addu $23,$23,1
blt $23,3,L.19
la $4,L.28
jal printf  # int
move $23,$0
L.29:
move $30,$0
L.33:
la $4,L.27
sll $25,$30,2
sll $24,$23,2
lw $24,y($24)
addu $25,$25,$24
lw $5,($25)
jal printf  # int
L.34:
addu $30,$30,1
blt $30,4,L.33
L.30:
addu $23,$23,1
blt $23,3,L.29
la $4,L.28
jal printf  # int
L.18:
lw $23,16($sp)
lw $30,20($sp)
lw $31,24($sp)
addu $sp,$sp,32
j $31
.end f
.globl g
.text
.align 2; .ent g
g:
$fp3=40
.frame $sp,40,$31
addu $sp,$sp,-40
.mask 0xc0e00000,-8
sw $21,16($sp)
sw $22,20($sp)
sw $23,24($sp)
sw $30,28($sp)
sw $31,32($sp)
move $30,$4
move $23,$5
move $21,$0
L.38:
move $22,$0
L.42:
la $4,L.27
sll $25,$22,2
sll $24,$21,4
addu $24,$24,$30
addu $25,$25,$24
lw $5,($25)
jal printf  # int
L.43:
addu $22,$22,1
blt $22,4,L.42
L.39:
addu $21,$21,1
blt $21,3,L.38
la $4,L.28
jal printf  # int
move $21,$0
L.46:
move $22,$0
L.50:
la $4,L.27
sll $25,$22,2
sll $24,$21,2
addu $24,$24,$23
lw $24,($24)
addu $25,$25,$24
lw $5,($25)
jal printf  # int
L.51:
addu $22,$22,1
blt $22,4,L.50
L.47:
addu $21,$21,1
blt $21,3,L.46
la $4,L.28
jal printf  # int
L.37:
lw $21,16($sp)
lw $22,20($sp)
lw $23,24($sp)
lw $30,28($sp)
lw $31,32($sp)
addu $sp,$sp,40
j $31
.end g
.globl y
.comm y,12
.globl x
.comm x,48
.rdata
L.28:.byte 10,0
L.27:.ascii " %d\000"
