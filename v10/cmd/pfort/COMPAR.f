      LOGICAL FUNCTION COMPAR(A, B)
      INTEGER SYMLEN, A(2), B(2)
      COMMON /PARAMS/ INUT, I1, NOCHAR, SYMLEN, I2, I3, I4
C
C     ROUTINE TESTS TWO IDENTIFIERS FOR SAMENESS; RETURNS TRUE IF
C     SAME, ELSE FALSE
C
      DO 10 I=1,SYMLEN
        IF (A(I).NE.B(I)) GO TO 30
   10 CONTINUE
      COMPAR = .TRUE.
   20 RETURN
   30 COMPAR = .FALSE.
      GO TO 20
      END
