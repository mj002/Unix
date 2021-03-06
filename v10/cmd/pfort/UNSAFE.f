      SUBROUTINE UNSAFE
C
C     ROUTINE READS IN ALL DIRECT AND INDIRECT REFS FOR THE CURRENT
C     PGM-UNIT; CHECKS FOR THE 3 UNSAFE REFS
C
      LOGICAL IBR
      INTEGER PLAT, PDSA, DSA, SYMLEN, PREF, REF, INREF, FINDCM
      COMMON /CREF/ LREF, PREF, REF(100)
      COMMON /GRAPH/ LLAT, PLAT, LAT(6000)
      COMMON /FACTS/ NAME, I1, I2, IASF
      COMMON /PARAMS/ I3, I4, I5, SYMLEN, I6, I7, I8
      COMMON /CTABL/ LDSA, PDSA, DSA(5000)
   10 IF (INREF(I7).LE.0) RETURN
C     CHECK FOR REF WITHOUT ARGS
      I = REF(1)
      IF (I.EQ.0) GO TO 10
      LL = REF(2)
      L = LL + SYMLEN + 1
      L = LAT(L)
C
C     LPOINTS TO DUMMY ARGUMENT IN LAT
C
      DO 70 K=1,I,2
        J = 4 + K
        IF (REF(J).EQ.0) GO TO 20
        N = IGATT1(REF(J),8)
        IF (N.EQ.10 .OR. N.EQ.4) GO TO 30
        GO TO 60
C
C     LOOK FOR EXPRESSION BEING MATCHED TO AN ARG WHICH
C     IS SET; TYPE 1 UNSAFE REF
C
   20   IF (IGATT2(L,5).EQ.0) GO TO 60
        CALL ERROR2(
     *      56H EXPRESSION MATCHED TO POSSIBLY SET ARG IN REFERENCE TO ,
     *  56, LAT(LL), 1, 1, 0)
      CALL ERROR2(24H TYPE 1 UNSAFE REFERENCE, 24, REF(3), -1, 0, 1)
        GO TO 60
C
C     CHECK FOR ACTUAL ARG IN COMMON BEING SENT DOWN WHERE RTNE
C     BENEATH CHANGES ARG OR COMMON REGION
C     TYPE 3 UNSAFE REFERENCE
C
   30   N = IGATT1(REF(J),2)
        IF (N.NE.1) GO TO 40
C
C     SEE IF  ACTUAL IS AN ARRAY
C
        N = IGATT2(L,7)
        IF (N.NE.0) GO TO 40
        N = REF(J) + 2
        N = DSA(N)
        N = DSA(N+1) + 4
        N = FINDCM(DSA(N))
        NN = LL + SYMLEN + 2
        NN = MATCH(LAT(NN),2,N)
        IF (NN.EQ.0) GO TO 40
        N = IGATT2(L,5)
        IF (N.EQ.0 .AND. LAT(NN+1).EQ.0) GO TO 40
        CALL ERROR2(42H ARG OR COMMON MAY BE SET BY REFERENCE TO , 42,
     *  LAT(LL), 1, 1, 0)
      CALL ERROR2(24H TYPE 3 UNSAFE REFERENCE, 24, REF(3), -1, 0, 1)
C
C     CHECK FOR DO CONTROL VAR OR LIMIT MATCHED
C     TO DUMMY ARG POSSIBLY SET
C
   40   NN = IGATT2(L,5)
        IF (NN.EQ.0) GO TO 60
        NN = REF(J+1)/32
        IF (NN.NE.1) GO TO 50
        CALL ERROR2(
     *      51H DO CONTROL VARIABLE OR LIMIT CAN BE SET IN REF TO , 51,
     *  LAT(LL), 1, 1, 0)
      CALL ERROR2(1H1, 0, REF(3), -1, 0, 1)
C
C     CHECK FOR ADJUSTIBLE DIMENSION VARIABLE MATCHED TO DUMMY
C     ARG POSSIBLY SET
C
   50   NN = REF(J+1)/64
        IF (NN.NE.1) GO TO 60
        CALL ERROR2(
     *      52H ADJUSTIBLE DIMENSION VARIABLE CAN BE SET IN REF TO ,
     *  52, LAT(LL), 1, 1, 0)
      CALL ERROR2(1H1, 0, REF(3), -1, 0, 1)
   60   L = LAT(L+3)
   70 CONTINUE
C
C     CHECK FOR SAME ACTUAL ARG SENT DOWN FOR DIFFERENT DUMMY-ARGS
C     AND ONE OF DUMMIES MAY BE SET
C
C     TYPE 2 UNSAFE REFERENCE
      IF (REF(1).LE.2) GO TO 130
      LR = LL + SYMLEN + 1
      LR = LAT(LR)
C
C     OUTER LOOP GOES TO NEXT TO LAST ARG
C
      I = REF(1) + 3
      II = I - 2
      DO 120 K=5,II,2
        J = REF(K)
        IF (J.EQ.0) GO TO 110
        JBR = IGATT1(J,8)
        IF (JBR.NE.10 .AND. JBR.NE.4) GO TO 110
        L = LAT(LR+3)
        MM = K + 2
        DO 100 M=MM,I,2
          IF (REF(M).NE.J) GO TO 90
C
C     HAVE TWO ACTUALS MAPPED ONTO DIFFERENT DUMMIES
C
C     IF BOTH DUMMIES ARE ARRAYS OR BOTH ARE UNSET, NO UNSAFE
      IF( IGATT2(L,7).NE.0 .AND. IGATT2(LR,7).NE.0 ) GOTO 90
      IF( IGATT2(L,5).EQ.0 .AND. IGATT2(LR,5).EQ.0 ) GOTO 90
 80   CALL ERROR2(64
     *H ACTUAL ARG ASSOCIATED WITH 2 DUMMY ARGS POSSIBLY SET IN REF TO
     *, 64, LAT(LL), 1, 1, 0)
      CALL ERROR2(24H TYPE 2 UNSAFE REFERENCE, 24, REF(3), -1, 0, 1)
   90     L = LAT(L+3)
  100   CONTINUE
  110   LR = LAT(LR+3)
  120 CONTINUE
C
C     CHECK FOR EXTERNAL FCNS WITHIN ASF-DEFS WHICH CONTAIN
C     ASF-DUMMIES AND WHICH SET THEIR ARGS
C
  130 IF (REF(4).NE.1) GO TO 10
      II = REF(1) + 3
      IBR = .FALSE.
      DO 140 K=5,II,2
        J = REF(K)
        IF (J.EQ.0) GO TO 140
        IF (IGATT1(J,8).EQ.1) IBR = .TRUE.
  140 CONTINUE
      IF (.NOT.IBR) GO TO 10
C
C     SEE IF EXTERNAL FCN SETS ANY OF ITS ARGS
C
      K = LL + SYMLEN + 1
      K = LAT(K)
      II = REF(1)/2
      DO 150 L=1,II
        IF (IGATT2(K,8).EQ.10 .AND. IGATT2(K,5).EQ.1) IBR = .FALSE.
  150 CONTINUE
      IF (IBR) GO TO 10
      CALL ERROR2(37H ILLEGAL USAGE OF ASF-DUMMY IN REF TO, 37,
     *  LAT(LL), 1, 1, 0)
      CALL ERROR2(1H , 0, REF(3), -1 ,0, 1)
      GO TO 10
      END
