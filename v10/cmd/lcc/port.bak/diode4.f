      SUBROUTINE DIODE4(V, NV, TSTART, TSTOP, DT, D, THETA,
     1   KEEJAC, MINIT, MAXIT, USENGJ, USENNS, USENFD, BETA, GAMMA,
     2   DELTA, N, MMAX, HFRACT, EGIVE, KMAX, XPOLY, KINIT, IRCS, ERROR,
     3   ERRPAR, ERPUTS, INMI, DA, HANDLE)
      INTEGER MMAX, NV
      EXTERNAL D, ERROR, INMI, DA, HANDLE
      INTEGER KEEJAC, MINIT, MAXIT, N(MMAX), KMAX, KINIT
      INTEGER IRCS
      REAL HFRACT, EGIVE, ERRPAR(2)
      LOGICAL USENGJ, USENNS, USENFD, XPOLY, ERPUTS, DA
      DOUBLE PRECISION V(NV), TSTART, TSTOP, DT, THETA, BETA
      DOUBLE PRECISION GAMMA, DELTA
      COMMON /CSTAK/ DS
      DOUBLE PRECISION DS(500)
      COMMON /D10DEY/ WV, RV, IV, LV
      INTEGER IV(40)
      REAL RV(30)
      LOGICAL LV(20)
      DOUBLE PRECISION WV(30)
      COMMON /D10DET/ TGOOD
      DOUBLE PRECISION TGOOD
      COMMON /D1ODES/ IMEM
      INTEGER IMEM
      COMMON /D10DER/ STATS
      INTEGER STATS(9)
      COMMON /D1ODEM/ THETAC, EGIVEC, MINITC, MAXITC, KEEACC, IRCSC
      INTEGER MINITC, MAXITC, KEEACC, IRCSC
      REAL EGIVEC
      DOUBLE PRECISION THETAC
      COMMON /D1ODEL/ ERPTSC
      LOGICAL ERPTSC
      COMMON /DIODEJ/ AJ, BJ, GETACC, NEEUMC
      LOGICAL GETACC, NEEUMC
      DOUBLE PRECISION AJ, BJ
      COMMON /D1ODEG/ TJ, DTJ, GETJAC, SEPATE, USEGJC, USENSC, USEFDC
      LOGICAL GETJAC, SEPATE, USEGJC, USENSC, USEFDC
      DOUBLE PRECISION TJ, DTJ
      COMMON /D1ODEF/ FNUM
      INTEGER FNUM
      COMMON /DIODEF/ FAILED
      LOGICAL FAILED
      EXTERNAL D1ODEE, D1ODEH, D1ODEP, D1ODEN
      INTEGER ISTKGT, NERROR, I, NERR, IS(1000), IVOLD
      REAL RS(1000)
      LOGICAL LS(1000)
      DOUBLE PRECISION DABS, WS(500)
      LOGICAL TEMP
      EQUIVALENCE (DS(1), WS(1), RS(1), IS(1), LS(1))
C THE BOTTOM LEVEL OF IODES.
C SCRATCH SPACE ALLOCATED -
C     S(DIODE3) = S(D1ODES) +
C LONG REAL WORDS +
C                 MMAX
C INTEGER WORDS.
C THE PORT LIBRARY STACK AND ITS ALIASES.
      IF (TSTART .EQ. TSTOP) RETURN
      CALL ENTER(1)
C CHECK THE INPUT FOR ERRORS.
C/6S
C     IF (NV .LE. 0) CALL SETERR(16HDIODE4 - NV.LE.0, 16, 1, 2)
C     IF (TSTART+DT .EQ. TSTART) CALL SETERR(
C    1   31HDIODE4 - INPUT VALUE OF DT IS 0, 31, 2, 2)
C     IF ((DT/DABS(DT))*(TSTOP-TSTART) .LE. 0D0) CALL SETERR(
C    1   45HDIODE4 - INPUT VALUE OF DT HAS THE WRONG SIGN, 45, 3, 2)
C     IF (THETA .LT. 0D0 .OR. THETA .GT. 1D0) CALL SETERR(
C    1   27HDIODE4 - THETA NOT IN (0,1), 27, 4, 2)
C     IF (KEEJAC .LT. 0 .OR. KEEJAC .GT. 5) CALL SETERR(
C    1   37HDIODE4 - KEEPJAC NOT ONE OF (0,...,5), 37, 5, 2)
C     IF (MINIT .LT. 1) CALL SETERR(19HDIODE4 - MINIT.LT.1, 19, 6, 2)
C     IF (MAXIT .LT. 1) CALL SETERR(19HDIODE4 - MAXIT.LT.1, 19, 7, 2)
C     IF (KMAX .LT. 1) CALL SETERR(18HDIODE4 - KMAX.LT.1, 18, 8, 2)
C/7S
      IF (NV .LE. 0) CALL SETERR('DIODE4 - NV.LE.0', 16, 1, 2)
      IF (TSTART+DT .EQ. TSTART) CALL SETERR(
     1   'DIODE4 - INPUT VALUE OF DT IS 0', 31, 2, 2)
      IF ((DT/DABS(DT))*(TSTOP-TSTART) .LE. 0D0) CALL SETERR(
     1   'DIODE4 - INPUT VALUE OF DT HAS THE WRONG SIGN', 45, 3, 2)
      IF (THETA .LT. 0D0 .OR. THETA .GT. 1D0) CALL SETERR(
     1   'DIODE4 - THETA NOT IN (0,1)', 27, 4, 2)
      IF (KEEJAC .LT. 0 .OR. KEEJAC .GT. 5) CALL SETERR(
     1   'DIODE4 - KEEPJAC NOT ONE OF (0,...,5)', 37, 5, 2)
      IF (MINIT .LT. 1) CALL SETERR('DIODE4 - MINIT.LT.1', 19, 6, 2)
      IF (MAXIT .LT. 1) CALL SETERR('DIODE4 - MAXIT.LT.1', 19, 7, 2)
      IF (KMAX .LT. 1) CALL SETERR('DIODE4 - KMAX.LT.1', 18, 8, 2)
C/
      TEMP = KINIT .LT. 1
      IF (.NOT. TEMP) TEMP = KINIT .GT. KMAX
C/6S
C     IF (TEMP) CALL SETERR(34HDIODE4 - KINIT NOT IN (1,...,KMAX), 34, 9
C    1   , 2)
C     IF (BETA .LE. 0D0) CALL SETERR(19HDIODE4 - BETA .LE.0, 19, 10, 2)
C     IF (GAMMA .LE. 0D0) CALL SETERR(20HDIODE4 - GAMMA .LE.0, 20, 11, 2
C    1   )
C     IF (DELTA .LT. 0D0) CALL SETERR(20HDIODE4 - DELTA .LT.0, 20, 12, 2
C    1   )
C     IF (BETA+GAMMA-DELTA .LE. 0D0) CALL SETERR(
C    1   30HDIODE4 - BETA+GAMMA-DELTA.LE.0, 30, 13, 2)
C     IF (MMAX .LT. KMAX+2) CALL SETERR(23HDIODE4 - MMAX.LT.KMAX+2, 23
C    1   , 14, 2)
C     IF (N(1) .LT. 1) CALL SETERR(18HDIODE4 - N(1).LT.1, 18, 15, 2)
C/7S
      IF (TEMP) CALL SETERR('DIODE4 - KINIT NOT IN (1,...,KMAX)', 34, 9
     1   , 2)
      IF (BETA .LE. 0D0) CALL SETERR('DIODE4 - BETA .LE.0', 19, 10, 2)
      IF (GAMMA .LE. 0D0) CALL SETERR('DIODE4 - GAMMA .LE.0', 20, 11, 2
     1   )
      IF (DELTA .LT. 0D0) CALL SETERR('DIODE4 - DELTA .LT.0', 20, 12, 2
     1   )
      IF (BETA+GAMMA-DELTA .LE. 0D0) CALL SETERR(
     1   'DIODE4 - BETA+GAMMA-DELTA.LE.0', 30, 13, 2)
      IF (MMAX .LT. KMAX+2) CALL SETERR('DIODE4 - MMAX.LT.KMAX+2', 23
     1   , 14, 2)
      IF (N(1) .LT. 1) CALL SETERR('DIODE4 - N(1).LT.1', 18, 15, 2)
C/
      DO  1 I = 2, MMAX
C/6S
C        IF (N(I) .LE. N(I-1)) CALL SETERR(
C    1      37HDIODE4 - N IS NOT MONOTONE INCREASING, 37, 16, 2)
C/7S
         IF (N(I) .LE. N(I-1)) CALL SETERR(
     1      'DIODE4 - N IS NOT MONOTONE INCREASING', 37, 16, 2)
C/
   1     CONTINUE
C/6S
C     IF (HFRACT .LE. 0.) CALL SETERR(20HDIODE4 - HFRACT.LE.0, 20, 17, 2
C    1   )
C     IF (EGIVE .LT. 1.) CALL SETERR(21HDIODE4 - EGIVE .LT. 1, 21, 18, 2
C    1   )
C/7S
      IF (HFRACT .LE. 0.) CALL SETERR('DIODE4 - HFRACT.LE.0', 20, 17, 2
     1   )
      IF (EGIVE .LT. 1.) CALL SETERR('DIODE4 - EGIVE .LT. 1', 21, 18, 2
     1   )
C/
      ERPTSC = ERPUTS
      EGIVEC = EGIVE
      IRCSC = IRCS
      THETAC = THETA
      MINITC = MINIT
      MAXITC = MAXIT
      KEEACC = KEEJAC
      IF (KEEJAC .EQ. 1 .AND. MAXIT .EQ. 1) KEEACC = 0
C SAME AS L.B.E.
      SEPATE = KEEACC .GT. 1
      USEGJC = USENGJ
      USENSC = USENNS
      USEFDC = USENFD
      IF (KEEACC .LT. 3) GOTO 2
         GETJAC = .TRUE.
         TJ = TSTART
         GOTO  5
   2     IF (KEEJAC .NE. 2) GOTO 3
            TJ = TSTOP
C CANNOT BE TSTART.
            GOTO  4
   3        TJ = TSTART
C CANNOT BE TSTART+THETA*DT/N.
   4     CONTINUE
   5  DTJ = 0
C START WITH NO ERROR STATES.
      FNUM = 0
C FLAG DA WORK-SPACE AS UN-ALLOCATED.
      IMEM = 0
C GET SPACE FOR DA.
      IF (DA(V, V, NV, TSTART, DT, D, V, TJ, DTJ, GETJAC, SEPATE,
     1   USENGJ, USENNS, USENFD, 0, -1, FNUM, THETA, IRCS, KEEACC))
     2   CONTINUE
C/6S
C     IF (IMEM .LE. 0) CALL SETERR(
C    1   52HDIODE4 - DIODED FAILED TO INITIALIZE COMMON /D1ODES/, 52,
C    2   19, 2)
C/7S
      IF (IMEM .LE. 0) CALL SETERR(
     1   'DIODE4 - DIODED FAILED TO INITIALIZE COMMON /D1ODES/', 52,
     2   19, 2)
C/
      TGOOD = TSTART
      IVOLD = ISTKGT(NV, 4)
      CALL MOVEFD(NV, V, WS(IVOLD))
C TELL STATS ROUTINE IN IODE.
      CALL D1ODEX(STATS, 1)
      CALL D10DEX(TSTART, TSTOP, D1ODEP, D1ODEN, DA, D, BETA, GAMMA,
     1   DELTA, WS(IVOLD), NV, DT, N, KMAX, MMAX, XPOLY, D1ODEE, ERROR
     2   , ERRPAR, INMI, D1ODEH, HANDLE, 0.9E0, HFRACT, KINIT)
C TELL STATS ROUTINE OUT OF IODE.
      CALL D1ODEX(STATS, -1)
      CALL MOVEFD(NV, WS(IVOLD), V)
      TSTOP = TGOOD
C CAPTURE THE ERROR NUMBER, IF ANY.
      NERR = NERROR(NERR)
      IF (NERR .NE. 15) GOTO 6
         CALL ERROFF
C/6S
C        CALL SETERR(13HDIODE4 - DT=0, 13, 1000, 1)
C/7S
         CALL SETERR('DIODE4 - DT=0', 13, 1000, 1)
C/
   6  IF (NERR .NE. 16) GOTO 7
         CALL ERROFF
C/6S
C        CALL SETERR(32HDIODE4 - DT=0 RETURNED BY HANDLE, 32, 1001, 1)
C/7S
         CALL SETERR('DIODE4 - DT=0 RETURNED BY HANDLE', 32, 1001, 1)
C/
   7  IF (NERR .NE. 17) GOTO 8
         CALL ERROFF
C/6S
C        CALL SETERR(45HDIODE4 - DT RETURNED BY HANDLE HAS WRONG SIGN,
C    1      45, 1002, 1)
C/7S
         CALL SETERR('DIODE4 - DT RETURNED BY HANDLE HAS WRONG SIGN',
     1      45, 1002, 1)
C/
   8  IF (NERR .NE. 18) GOTO 9
         CALL ERROFF
C/6S
C        CALL SETERR(46HDIODE4 - CANNOT RAISE DT IN HANDLE WHEN FAILED
C    1      , 46, 1003, 1)
C/7S
         CALL SETERR('DIODE4 - CANNOT RAISE DT IN HANDLE WHEN FAILED'
     1      , 46, 1003, 1)
C/
   9  IF (NERR .NE. 19) GOTO 10
         CALL ERROFF
C/6S
C        CALL SETERR(36HDIODE4 - E(I).LE.0 RETURNED BY ERROR, 36, 1004
C    1      , 1)
C/7S
         CALL SETERR('DIODE4 - E(I).LE.0 RETURNED BY ERROR', 36, 1004
     1      , 1)
C/
  10  IF (NERR .NE. 15) GOTO 15
         IF (FNUM .NE. 1) GOTO 11
            CALL ERROFF
C/6S
C           CALL SETERR(18HDIODE4 - D FAILURE, 18, 1005, 1)
C/7S
            CALL SETERR('DIODE4 - D FAILURE', 18, 1005, 1)
C/
  11     IF (FNUM .NE. 2) GOTO 12
            CALL ERROFF
C/6S
C           CALL SETERR(26HDIODE4 - SINGULAR JACOBIAN, 26, 1006, 1)
C/7S
            CALL SETERR('DIODE4 - SINGULAR JACOBIAN', 26, 1006, 1)
C/
  12     IF (FNUM .NE. 3) GOTO 13
            CALL ERROFF
C/6S
C           CALL SETERR(
C    1         45HDIODE4 - TOO MANY NEWTON ITERATIONS PREDICTED, 45,
C    2         1007, 1)
C/7S
            CALL SETERR(
     1         'DIODE4 - TOO MANY NEWTON ITERATIONS PREDICTED', 45,
     2         1007, 1)
C/
  13     IF (FNUM .NE. 4) GOTO 14
            CALL ERROFF
C/6S
C           CALL SETERR(42HDIODE4 - TOO MANY NEWTON ITERATIONS NEEDED,
C    1         42, 1008, 1)
C/7S
            CALL SETERR('DIODE4 - TOO MANY NEWTON ITERATIONS NEEDED',
     1         42, 1008, 1)
C/
  14     CONTINUE
  15  CALL LEAVE
      RETURN
      END
