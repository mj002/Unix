      LOGICAL FUNCTION INSYM(IDUM,II)
      INTEGER OUTUT, OUTUT2, OUTUT3, SYMHD, PDSA, SYMLEN, DSA, BNEXT
      COMMON /PARAMS/ INUT, OUTUT, NOCHAR, SYMLEN, OUTUT2, OUTUT3, I1
      COMMON /TABL/ NEXT, LABHD, SYMHD, BNEXT
      COMMON /FACTS/ NAME, NOST, ITYP, IASF
      COMMON /CTABL/ LDSA, PDSA, DSA(5000)
C
C     ROUTINE TO INPUT SYMBOL TABLE; RETURNS TRUE FOR SUCCESSFUL, ELSE
C     FALSE. KCODE=1 FOR TABLE, 3 FOR DUMMY TABLE, 4 FOR EOF
C     DUMMY TABLE CAUSES REFS FOR THIS PU TO BE FLUSHED IF
C     IDUM NE 0
C
 5    READ(OUTUT2) PDSA, KCODE, (DSA(I),I=1,PDSA)
      IF (KCODE-3) 10, 40, 30
   10 NAME = DSA(PDSA-2)
      SYMHD = DSA(PDSA-1)
      LABHD = DSA(PDSA)
      PDSA = PDSA - 3
      INSYM = .TRUE.
   20 RETURN
   30 INSYM = .FALSE.
      GO TO 20
C     FLUSH REFS FOR DUMMY TABLE IF IDUM NONZERO
 40   IF(IDUM.EQ.0) GOTO 5
 50   IF(INREF(IDUM)) 60, 60, 50
C     WRITE END OF REFS FOR DUMMY REFS IF II NE 0; ELSE GOT TO
C     NEXT SYMBOL TABLE
 60   IF(II.EQ.0) GOTO 5
      L = 1
      K = 3
      WRITE(II) L,K,L
      GOTO 5
      END
