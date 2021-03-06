      SUBROUTINE RCSC(A, M, N, R, C, RC)
      INTEGER M, N
      INTEGER RC(N)
      REAL A(M, N), R(M), C(N)
      INTEGER I, J, RD2
      REAL AIJ, ABS, AAIJ, L, S, D1
      REAL D2, AMAX1, R1MACH
      DATA S/0E0/
      DATA L/0E0/
C TO GET THE COLUMN SCALE FACTOR FOR (1/R)*A.
C/6S
C     IF (M .LT. 1) CALL SETERR(16H RCSC - M .LT. 1, 16, 1, 2)
C     IF (N .LT. 1) CALL SETERR(16H RCSC - N .LT. 1, 16, 2, 2)
C/7S
      IF (M .LT. 1) CALL SETERR(' RCSC - M .LT. 1', 16, 1, 2)
      IF (N .LT. 1) CALL SETERR(' RCSC - N .LT. 1', 16, 2, 2)
C/
      IF (S .NE. 0.) GOTO 1
         S = R1MACH(1)
         L = R1MACH(2)
   1  DO  2 I = 1, M
         IF (R(I) .EQ. 0.) GOTO  2
C/6S
C        IF (R(I) .LT. S .OR. R(I) .GT. L) CALL SETERR(
C    1      36H RCSC - MUST HAVE S .LE. R(I) .LE. L, 36, 3, 2)
C/7S
         IF (R(I) .LT. S .OR. R(I) .GT. L) CALL SETERR(
     1      ' RCSC - MUST HAVE S .LE. R(I) .LE. L', 36, 3, 2)
C/
   2     CONTINUE
      DO  18 J = 1, N
         D2 = 0
C -1 = UNDERFLOW, 0 = IN-RANGE, +1 = OVERFLOW.
         RD2 = -1
         DO  17 I = 1, M
            AIJ = A(I, J)
            AAIJ = ABS(AIJ)
            D1 = R(I)
            IF (AIJ .EQ. 0. .OR. D1 .EQ. 0.) GOTO  17
            IF (D1 .GE. 1.) GOTO 9
               IF (AAIJ .LE. D1*L) GOTO 3
                  IF (RD2 .LT. 1) D2 = 0
C CHECK FOR OVERFLOW.
C OVERFLOW.
                  RD2 = 1
                  D2 = AMAX1(D2, AAIJ*(S/D1))
                  GOTO  8
   3              IF (RD2 .LE. 0) GOTO 4
                     GOTO  17
C THIS ELEMENT IS IN-RANGE.
C ALREADY OVERFLOWED, NO EFFECT.
   4                 IF (RD2 .NE. 0) GOTO 5
                        D2 = AMAX1(D2, AAIJ/D1)
                        GOTO  6
   5                    RD2 = 0
C RD2 = -1.
                        D2 = AAIJ/D1
   6              CONTINUE
   7              CONTINUE
   8           CONTINUE
               GOTO  16
   9           IF (AAIJ .GE. D1*S) GOTO 10
                  IF (RD2 .GE. 0) GOTO  17
C ELEMENT UNDERFLOW, D1 >= 1.
C NO-EFFECT.
                  D2 = AMAX1(D2, AAIJ*(L/D1))
                  GOTO  15
  10              IF (RD2 .LE. 0) GOTO 11
                     GOTO  17
C IN-RANGE.
C NO-EFFECT.
  11                 IF (RD2 .NE. 0) GOTO 12
                        D2 = AMAX1(D2, AAIJ/D1)
                        GOTO  13
  12                    RD2 = 0
C UNDERFLOWED SO FAR.
                        D2 = AAIJ/D1
  13              CONTINUE
  14              CONTINUE
  15        CONTINUE
  16        CONTINUE
  17        CONTINUE
         C(J) = D2
         RC(J) = RD2
  18     CONTINUE
      RETURN
      END
