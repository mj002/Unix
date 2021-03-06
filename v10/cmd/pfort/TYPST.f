      SUBROUTINE TYPST(ITYP, KK, KL)
      INTEGER PSTMT, K(186), KI(30), STMT, CODE, KT(30)
      LOGICAL ERR, SYSERR, ASSMT, ABORT
      COMMON /INPUT/ NSTMT, PSTMT, STMT(1327)
      COMMON /DETECT/ ERR, SYSERR, ABORT
      COMMON /STS/ K, KI, KT
C
C*****STS
C     K(*) (INT) ARRAY CONTAINS A TABLE OF INTERNAL CODES FOR EACH
C     "KEYWORD" IN FORTRAN STMTS
C     KI(*) (INT) ARRAY CONTAINING NUMBER OF CHARACTERS IN EACH
C     KEYWORD IN K
C     KT(*)  (INT) ARRAY CONTAINING CLASS OF EACH STMT IN K
C     (SEE PU FOR FURTHER DOC OF IGP -CLASS)
C     TEST IF ITS AN ASSIGNMENT; IF SO ITYP = 30
C     ELSE SEARCH K ARRAY FOR STMT;  ITYP CONTAINS CODED
C     TYPE OF STMT; KK CONTAINS GENERAL CLASS OF STMTS IT FALLS IN
C     KL IS COUNT OF NUMBER OF LETTERS IN FIRST WORD OF STMT
C
      CALL TYPST2(ASSMT)
      IF (ASSMT) GO TO 40
      J = 1
      CODE = 0
   10 I = PSTMT
      CODE = CODE + 1
      L = J + KI(CODE) - 1
      DO 20 LL=J,L
        IF (STMT(I).NE.K(LL)) GO TO 30
        I = I + 1
   20 CONTINUE
      ITYP = CODE
      KK = KT(CODE)
      KL = KI(CODE)
      RETURN
   30 J = L + 1
      IF (CODE.LT.29) GO TO 10
      ERR = .TRUE.
      RETURN
   40 ITYP = 30
      KK = KT(30)
      KL = 0
      RETURN
      END
