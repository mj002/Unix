      SUBROUTINE LIST
      INTEGER STMT, PSTMT
      LOGICAL ERR, SYSERR, ABORT, IDLIST, IDO, FINDO
      LOGICAL SIO
      COMMON /INPUT/ NSTMT, PSTMT, STMT(1327)
      COMMON /DETECT/ ERR, SYSERR, ABORT
      COMMON /LISTDO/ LPT, LEN, LS(64)
C
C     ROUTINE PROCESSES THE LIST CONSTRUCT, USED IN I-O STMTS
C     LEV USED TO COUNT PARENTHESES LEVELS
C
      SIO = .FALSE.
      LPT = LEN + 1
      FINDO = .FALSE.
      ICNT = 0
      LEV = 0
   10 IF (STMT(PSTMT).NE.65) GO TO 20
      LEV = LEV + 1
      IF (LEV.GT.ICNT) ICNT = ICNT + 1
      PSTMT = PSTMT + 1
      GO TO 10
   20 IF (PSTMT.GE.NSTMT) GO TO 120
C
C     ALLOW <ID>=ARRAY,ARRAY ELE., VARIABLE
C
      IF (.NOT.IDLIST(IDO)) GO TO 130
C
C     FALSE RETURN SIGNIFIES ERROR IN IDLIST
C     TRUE RETURN SIGNIFIES NO ERROR IN IDLIST
C     IDO = .TRUE. MEANS , <DOSPEC> IS NEXT
C     IDO = .FALSE. MEANS AT END-OF-STMT, ", (" , OR ")"
C
C      FOUND <DOSPEC> )
C
      IF (SYSERR) GO TO 130
      IF (.NOT.IDO) GO TO 30
      PSTMT = PSTMT + 1
      GO TO 100
C
C      FOUND END OF SIMPLE LIST "( <IDLIST> )"
C
   30 IF (STMT(PSTMT).EQ.62) GO TO 60
   40 IF (PSTMT.NE.NSTMT) GO TO 50
C
C     AT END OF STMT
C
      IF (FINDO) CALL LDOVAR
      IF (LEV.NE.0) GO TO 120
      GO TO 130
C
C      NEED "," AND NEW <LIST> CONSTRUCT
C
   50 IF (STMT(PSTMT).NE.68) GO TO 120
      PSTMT = PSTMT + 1
      GO TO 10
C
C     MUST CHECK FOR ILLEGALLY NESTED SIMPLE LISTS
C     SIMPLE LIST= ( <IDLIST> )
C     ICNT COUNTAINS LEVEL OF LAST SIMPLE LIST WITHIN A
C      PARENTHESIZED EXPRESSION
C
   60 SIO = .TRUE.
      IF (LEV.EQ.0) GO TO 120
      PSTMT = PSTMT + 1
      IF (ICNT.LE.LEV) GO TO 80
   70 CALL ERROR1(28H ILLEGAL PARENTHESES NESTING, 28)
      GO TO 130
   80 LEV = LEV - 1
      IF (LEV) 120, 110, 90
C
C     CHECK FOR CONSTRUCT FOLLOWING <DOSPEC>
C
   90 IF (STMT(PSTMT).EQ.62) GO TO 70
      IF (STMT(PSTMT).NE.68) GO TO 120
      CALL NEXTOK(PSTMT+1, K2, K)
      IF (K.NE.0 .OR. STMT(K2).NE.63) GO TO 40
      PSTMT = PSTMT + 1
C
C     LOOK FOR DOSPEC
C
  100 CALL DOSPEC(0, K2, .TRUE.)
      IF (SYSERR .OR. ERR) GO TO 130
      FINDO = .TRUE.
      IF (STMT(K2).NE.62) GO TO 120
      PSTMT = K2 + 1
      IF (ICNT.GT.LEV) ICNT = ICNT - 1
      GO TO 80
C
C     CHECK NESTED DOSPECS IN LIST
C
  110 IF (LEV.NE.0 .OR. .NOT.FINDO) GO TO 40
      FINDO = .FALSE.
      CALL LDOVAR
      LPT = LEN + 1
      GO TO 40
  120 CALL ERROR1(20H ILLEGAL PUNCTUATION, 20)
      IF (FINDO) CALL LDOVAR
  130 IF (SIO) CALL ERROR1(34H REDUNDANT PARENTHESES ARE ILLEGAL, 34)
      RETURN
      END
