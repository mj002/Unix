      SUBROUTINE TYPST2(ASSMT)
      INTEGER PSTMT, STMT
      LOGICAL EQUALS, ASSMT
      COMMON /INPUT/ NSTMT, PSTMT, STMT(1327)
C
C     ALGORITHM FOR IDENTIFYING ASSIGNMENT STMTS:
C
      EQUALS = .FALSE.
      LEVEL = 0
      IGP = 0
C
C     62.....)     63.....=     65.....(     68.....,
C
      DO 40 I=PSTMT,NSTMT
        IF (STMT(I).EQ.65) LEVEL = LEVEL + 1
        IF (STMT(I).NE.62) GO TO 10
        LEVEL = LEVEL - 1
        IF (EQUALS) GO TO 40
        IF (LEVEL.EQ.0) IGP = IGP + 1
        IF (IGP.EQ.1 .AND. LEVEL.EQ.0 .AND. STMT(I+1).NE.63) GO TO 60
        GO TO 40
   10   IF (LEVEL) 50, 20, 30
   20   IF (STMT(I).EQ.68) GO TO 60
        IF (STMT(I).EQ.63) EQUALS = .TRUE.
        GO TO 40
   30   IF (STMT(I).EQ.63) GO TO 60
   40 CONTINUE
      IF (.NOT.EQUALS) GO TO 60
      ASSMT = .TRUE.
   50 RETURN
   60 ASSMT = .FALSE.
      GO TO 50
      END
