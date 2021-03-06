.text
.globl _main
.align 2
_main:link a6,#-24
moveml #0x2090,a6@(-12)
lea L6:l,a5
jra L5
L2:
movb a5@,d4
extbl d4
movl d4,sp@
jbsr _backslash:l
movl #L7,sp@
movb a5@,d4
extbl d4
movl d4,sp@(4)
movl d0,sp@(8)
jbsr _printf:l
L3:
addql #1,a5
L5:
tstb a5@; jne L2
jbsr _f:l
jbsr _g:l
jbsr _h:l
movl #16777216,d7
jra L11
L8:
movl d7,sp@
jbsr _big:l
L9:
addl #16777216,d7
L11:
movl d7,d4; andl #0x7000000,d4
tstl d4; jne L8
jbsr _limit:l
clrl d0
L1:
moveml a6@(-12),#0x2090
unlk a6
rts
.globl _backslash
.align 2
_backslash:link a6,#-4
moveml #0x10,a6@(-4)
movl a6@(8),d4
cmpl #110,d4; jeq L17
cmpl #110,d4; jgt L21
movl a6@(8),d4
cmpl #102,d4; jeq L16
cmpl #102,d4; jgt L13
cmpl #98,a6@(8); jeq L15
jra L13
L21:
movl a6@(8),d4
cmpl #114,d4; jeq L18
cmpl #116,d4; jeq L19
cmpl #118,d4; jeq L20
jra L13
L15:
movl #8,d0
jra L12
L16:
movl #12,d0
jra L12
L17:
movl #10,d0
jra L12
L18:
movl #13,d0
jra L12
L19:
movl #9,d0
jra L12
L20:
movl #11,d0
jra L12
L13:
movl a6@(8),d0
L12:
moveml a6@(-4),#0x10
unlk a6
rts
.globl _f
.align 2
_f:link a6,#-24
moveml #0x4e0,a6@(-16)
clrl d6
movl #L23,sp@
jbsr _printf:l
clrl d7
L24:
movl d7,d5
cmpl #1,d7; jlt L28
cmpl #20,d7; jgt L28
movl @(L41-4:l,d7:l:4),a2
jra a2@
L41:
.align 2; .long L30
.align 2; .long L31
.align 2; .long L28
.align 2; .long L28
.align 2; .long L28
.align 2; .long L28
.align 2; .long L32
.align 2; .long L33
.align 2; .long L34
.align 2; .long L28
.align 2; .long L28
.align 2; .long L28
.align 2; .long L28
.align 2; .long L28
.align 2; .long L28
.align 2; .long L35
.align 2; .long L36
.align 2; .long L37
.align 2; .long L38
.align 2; .long L39
L30:
movl d7,d6
jra L29
L31:
movl d7,d6
jra L29
L32:
movl d7,d6
jra L29
L33:
movl d7,d6
jra L29
L34:
movl d7,d6
jra L29
L35:
movl d7,d6
jra L29
L36:
movl d7,d6
jra L29
L37:
movl d7,d6
jra L29
L38:
movl d7,d6
jra L29
L39:
movl d7,d6
L28:
L29:
movl #L43,sp@
movl d6,sp@(4)
jbsr _printf:l
L25:
addql #1,d7
cmpl #20,d7; jle L24
L22:
moveml a6@(-16),#0x4e0
unlk a6
rts
.globl _g
.align 2
_g:link a6,#-16
moveml #0x480,a6@(-8)
movl #L45,sp@
jbsr _printf:l
movl #1,d7
L46:
cmpl #1001,d7; jlt L64
cmpl #1004,d7; jgt L63
movl @(L65-4004:l,d7:l:4),a2
jra a2@
L65:
.align 2; .long L59
.align 2; .long L59
.align 2; .long L59
.align 2; .long L59
L64:
cmpl #1,d7; jlt L50
cmpl #8,d7; jgt L50
movl @(L68-4:l,d7:l:4),a2
jra a2@
L68:
.align 2; .long L52
.align 2; .long L52
.align 2; .long L54
.align 2; .long L54
.align 2; .long L54
.align 2; .long L56
.align 2; .long L56
.align 2; .long L56
L67:
L63:
cmpl #3001,d7; jlt L50
cmpl #3004,d7; jgt L50
movl @(L71-12004:l,d7:l:4),a2
jra a2@
L71:
.align 2; .long L61
.align 2; .long L61
.align 2; .long L61
.align 2; .long L61
L52:
movl #L53,sp@
movl d7,sp@(4)
jbsr _printf:l
jra L51
L54:
movl #L55,sp@
movl d7,sp@(4)
jbsr _printf:l
jra L51
L56:
movl #L57,sp@
movl d7,sp@(4)
jbsr _printf:l
L50:
movl #L58,sp@
movl d7,sp@(4)
jbsr _printf:l
jra L51
L59:
movl #L60,sp@
movl d7,sp@(4)
jbsr _printf:l
jra L51
L61:
movl #L62,sp@
movl d7,sp@(4)
jbsr _printf:l
L51:
L47:
addql #1,d7
cmpl #10,d7; jle L46
L44:
moveml a6@(-8),#0x480
unlk a6
rts
.globl _h
.align 2
_h:link a6,#-16
moveml #0xc0,a6@(-8)
clrl d6
movl #L74,sp@
jbsr _printf:l
movl #1,d7
L75:
cmpl #128,d7; jeq L81
cmpl #128,d7; jgt L94
cmpl #16,d7; jeq L83
cmpl #16,d7; jgt L95
cmpl #8,d7; jeq L84
jra L79
L95:
cmpl #120,d7; jeq L85
jra L79
L94:
cmpl #280,d7; jeq L86
cmpl #280,d7; jgt L96
cmpl #264,d7; jeq L87
cmpl #264,d7; jgt L97
cmpl #248,d7; jeq L88
jra L79
L97:
cmpl #272,d7; jeq L89
jra L79
L96:
cmpl #304,d7; jeq L90
cmpl #304,d7; jgt L98
cmpl #296,d7; jeq L91
cmpl #296,d7; jgt L79
cmpl #288,d7; jeq L92
jra L79
L98:
cmpl #312,d7; jeq L93
jra L79
L79:
addql #1,d6
jra L76
L81:
movl #L82,sp@
movl d7,sp@(4)
jbsr _printf:l
jra L80
L83:
movl #L82,sp@
movl d7,sp@(4)
jbsr _printf:l
jra L80
L84:
movl #L82,sp@
movl d7,sp@(4)
jbsr _printf:l
jra L80
L85:
movl #L82,sp@
movl d7,sp@(4)
jbsr _printf:l
jra L80
L86:
movl #L82,sp@
movl d7,sp@(4)
jbsr _printf:l
jra L80
L87:
movl #L82,sp@
movl d7,sp@(4)
jbsr _printf:l
jra L80
L88:
movl #L82,sp@
movl d7,sp@(4)
jbsr _printf:l
jra L80
L89:
movl #L82,sp@
movl d7,sp@(4)
jbsr _printf:l
jra L80
L90:
movl #L82,sp@
movl d7,sp@(4)
jbsr _printf:l
jra L80
L91:
movl #L82,sp@
movl d7,sp@(4)
jbsr _printf:l
jra L80
L92:
movl #L82,sp@
movl d7,sp@(4)
jbsr _printf:l
jra L80
L93:
movl #L82,sp@
movl d7,sp@(4)
jbsr _printf:l
L80:
L76:
addql #1,d7
cmpl #500,d7; jle L75
movl #L99,sp@
movl d6,sp@(4)
jbsr _printf:l
L73:
moveml a6@(-8),#0xc0
unlk a6
rts
.globl _big
.align 2
_big:link a6,#-16
moveml #0x90,a6@(-8)
movl a6@(8),d4
andl #0x6000000,d4
movl d4,d7
cmpl #33554432,d7; jeq L106
cmpl #33554432,d7; jgt L109
cmpl #-2,d7; jeq L104
cmpl #-1,d7; jeq L104
tstl d7; jeq L104
jra L101
L109:
cmpl #67108864,d7; jeq L107
jra L101
L104:
movl #L105,sp@
movl a6@(8),sp@(4)
jbsr _printf:l
jra L102
L106:
movl #L105,sp@
movl a6@(8),sp@(4)
jbsr _printf:l
jra L102
L107:
movl #L105,sp@
movl a6@(8),sp@(4)
jbsr _printf:l
jra L102
L101:
movl #L108,sp@
movl a6@(8),sp@(4)
jbsr _printf:l
L102:
L100:
moveml a6@(-8),#0x90
unlk a6
rts
.globl _limit
.align 2
_limit:link a6,#-20
moveml #0x498,a6@(-16)
movl #-2147483648,d7
L111:
cmpl #-2147483648,d7; jlt L115
cmpl #-2147483644,d7; jgt L115
movl d7,d4; asll #2,d4
movl #-2147483648,d3
asll #2,d3
subl d3,d4
movl @(L129:l,d4:l:1),a2
jra a2@
L129:
.align 2; .long L117
.align 2; .long L119
.align 2; .long L121
.align 2; .long L123
.align 2; .long L125
L117:
movl #L118,sp@
jbsr _printf:l
jra L116
L119:
movl #L120,sp@
jbsr _printf:l
jra L116
L121:
movl #L122,sp@
jbsr _printf:l
jra L116
L123:
movl #L124,sp@
jbsr _printf:l
jra L116
L125:
movl #L126,sp@
jbsr _printf:l
jra L116
L115:
movl #L127,sp@
jbsr _printf:l
L116:
L112:
addql #1,d7
cmpl #-2147483643,d7; jle L111
movl #2147483647,d7
L130:
cmpl #2147483643,d7; jlt L134
cmpl #2147483647,d7; jgt L134
movl d7,d4; asll #2,d4
movl #2147483643,d3
asll #2,d3
subl d3,d4
movl @(L142:l,d4:l:1),a2
jra a2@
L142:
.align 2; .long L140
.align 2; .long L139
.align 2; .long L138
.align 2; .long L137
.align 2; .long L136
L136:
movl #L118,sp@
jbsr _printf:l
jra L135
L137:
movl #L120,sp@
jbsr _printf:l
jra L135
L138:
movl #L122,sp@
jbsr _printf:l
jra L135
L139:
movl #L124,sp@
jbsr _printf:l
jra L135
L140:
movl #L126,sp@
jbsr _printf:l
jra L135
L134:
movl #L127,sp@
jbsr _printf:l
L135:
L131:
subql #1,d7
cmpl #2147483642,d7; jge L130
L110:
moveml a6@(-16),#0x498
unlk a6
rts
.text
.align 2; L127:.byte 53,10,0
.align 2; L126:.byte 52,10,0
.align 2; L124:.byte 51,10,0
.align 2; L122:.byte 50,10,0
.align 2; L120:.byte 49,10,0
.align 2; L118:.byte 48,10,0
.align 2; L108:.ascii "x = 0x%x (default)\012\000"
.align 2; L105:.ascii "x = 0x%x\012\000"
.align 2; L99:.ascii "%d defaults\012\000"
.align 2; L82:.ascii "i = %d\012\000"
.align 2; L74:.byte 104,58,10,0
.align 2; L62:.ascii "6 %d\012\000"
.align 2; L60:.ascii "5 %d\012\000"
.align 2; L58:.ascii "d %d\012\000"
.align 2; L57:.ascii "3 %d\012\000"
.align 2; L55:.ascii "2 %d\012\000"
.align 2; L53:.ascii "1 %d\012\000"
.align 2; L45:.byte 103,58,10,0
.align 2; L43:.ascii "x = %d\012\000"
.align 2; L23:.byte 102,58,10,0
.align 2; L7:.ascii "%c = 0x%x\012\000"
.align 2; L6:.ascii "bfnrtvx\000"
