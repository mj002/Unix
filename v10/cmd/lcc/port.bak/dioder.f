      SUBROUTINE DIODER(V, NV, TSTART, TSTOP, DT, D, ERROR,
     1   ERRPAR, INMI, DA, HANDLE)
      INTEGER NV
      EXTERNAL D, ERROR, INMI, DA, HANDLE
      REAL ERRPAR(2)
      DOUBLE PRECISION V(NV), TSTART, TSTOP, DT
      INTEGER I, N(100), KEEJAC, KMAX, MMAX, IZAP
      INTEGER IRCS, KINIT, MINIT, MAXIT
      REAL HFRACT, RZAP, EGIVE
      LOGICAL USENFD, USENGJ, USENNS, ERPUTS, LZAP, XPOLY
      DOUBLE PRECISION BETA, FZAP, GAMMA, DELTA, THETA
C THE SECOND, ROUTINE, LEVEL OF DIODE.
C RETRIEVE THE VALUES TO BE USED.
      CALL DIODEV(-1, THETA, RZAP, IZAP, LZAP)
      CALL DIODEV(-2, BETA, RZAP, IZAP, LZAP)
      CALL DIODEV(-3, GAMMA, RZAP, IZAP, LZAP)
      CALL DIODEV(-4, DELTA, RZAP, IZAP, LZAP)
      CALL DIODEV(-1001, FZAP, HFRACT, IZAP, LZAP)
      CALL DIODEV(-1002, FZAP, EGIVE, IZAP, LZAP)
      CALL DIODEV(-2001, FZAP, RZAP, KEEJAC, LZAP)
      CALL DIODEV(-2002, FZAP, RZAP, MINIT, LZAP)
      CALL DIODEV(-2003, FZAP, RZAP, MAXIT, LZAP)
      CALL DIODEV(-2004, FZAP, RZAP, KMAX, LZAP)
      CALL DIODEV(-2005, FZAP, RZAP, KINIT, LZAP)
      CALL DIODEV(-2006, FZAP, RZAP, MMAX, LZAP)
      CALL DIODEV(-2007, FZAP, RZAP, IRCS, LZAP)
      CALL DIODEV(-3001, FZAP, RZAP, IZAP, XPOLY)
      CALL DIODEV(-3002, FZAP, RZAP, IZAP, ERPUTS)
      CALL DIODEV(-3003, FZAP, RZAP, IZAP, USENGJ)
      CALL DIODEV(-3004, FZAP, RZAP, IZAP, USENNS)
      CALL DIODEV(-3005, FZAP, RZAP, IZAP, USENFD)
C TEST FOR ERRORS.
C/6S
C     IF (KMAX .LT. 1) CALL SETERR(18HDIODE4 - KMAX.LT.1, 18, 8, 2)
C     IF (MMAX .LT. KMAX+2) CALL SETERR(23HDIODE4 - MMAX.LT.KMAX+2, 23
C    1   , 14, 2)
C/7S
      IF (KMAX .LT. 1) CALL SETERR('DIODE4 - KMAX.LT.1', 18, 8, 2)
      IF (MMAX .LT. KMAX+2) CALL SETERR('DIODE4 - MMAX.LT.KMAX+2', 23
     1   , 14, 2)
C/
      DO  1 I = 1, MMAX
         CALL DIODEV(-(I+4000), FZAP, RZAP, N(I), LZAP)
   1     CONTINUE
C TEST N FOR MONOTONICITY.
      DO  2 I = 2, MMAX
C/6S
C        IF (N(I) .LE. N(I-1)) CALL SETERR(
C    1      37HDIODE4 - N IS NOT MONOTONE INCREASING, 37, 16, 2)
C/7S
         IF (N(I) .LE. N(I-1)) CALL SETERR(
     1      'DIODE4 - N IS NOT MONOTONE INCREASING', 37, 16, 2)
C/
   2     CONTINUE
      CALL DIODE4(V, NV, TSTART, TSTOP, DT, D, THETA, KEEJAC, MINIT,
     1   MAXIT, USENGJ, USENNS, USENFD, BETA, GAMMA, DELTA, N, MMAX,
     2   HFRACT, EGIVE, KMAX, XPOLY, KINIT, IRCS, ERROR, ERRPAR, ERPUTS,
     3   INMI, DA, HANDLE)
      RETURN
      END
