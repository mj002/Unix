      SUBROUTINE IODER(V, NV, TSTART, TSTOP, DT, D, ERROR, ERRPAR,
     1   INMI, DA, HANDLE)
      INTEGER NV
      EXTERNAL D, ERROR, INMI, DA, HANDLE
      REAL V(NV), TSTART, TSTOP, DT, ERRPAR(2)
      INTEGER I, N(100), KEEJAC, KMAX, MMAX, IZAP
      INTEGER IRCS, KINIT, MINIT, MAXIT
      REAL HFRACT, BETA, FZAP, RZAP, GAMMA, DELTA
      REAL EGIVE, THETA
      LOGICAL USENFD, USENGJ, USENNS, ERPUTS, LZAP, XPOLY
C THE SECOND, ROUTINE, LEVEL OF IODE.
C RETRIEVE THE VALUES TO BE USED.
      CALL IODEV(-1, THETA, RZAP, IZAP, LZAP)
      CALL IODEV(-2, BETA, RZAP, IZAP, LZAP)
      CALL IODEV(-3, GAMMA, RZAP, IZAP, LZAP)
      CALL IODEV(-4, DELTA, RZAP, IZAP, LZAP)
      CALL IODEV(-1001, FZAP, HFRACT, IZAP, LZAP)
      CALL IODEV(-1002, FZAP, EGIVE, IZAP, LZAP)
      CALL IODEV(-2001, FZAP, RZAP, KEEJAC, LZAP)
      CALL IODEV(-2002, FZAP, RZAP, MINIT, LZAP)
      CALL IODEV(-2003, FZAP, RZAP, MAXIT, LZAP)
      CALL IODEV(-2004, FZAP, RZAP, KMAX, LZAP)
      CALL IODEV(-2005, FZAP, RZAP, KINIT, LZAP)
      CALL IODEV(-2006, FZAP, RZAP, MMAX, LZAP)
      CALL IODEV(-2007, FZAP, RZAP, IRCS, LZAP)
      CALL IODEV(-3001, FZAP, RZAP, IZAP, XPOLY)
      CALL IODEV(-3002, FZAP, RZAP, IZAP, ERPUTS)
      CALL IODEV(-3003, FZAP, RZAP, IZAP, USENGJ)
      CALL IODEV(-3004, FZAP, RZAP, IZAP, USENNS)
      CALL IODEV(-3005, FZAP, RZAP, IZAP, USENFD)
C TEST FOR ERRORS.
C/6S
C     IF (KMAX .LT. 1) CALL SETERR(18H IODE4 - KMAX.LT.1, 18, 8, 2)
C     IF (MMAX .LT. KMAX+2) CALL SETERR(23H IODE4 - MMAX.LT.KMAX+2, 23
C    1   , 14, 2)
C/7S
      IF (KMAX .LT. 1) CALL SETERR(' IODE4 - KMAX.LT.1', 18, 8, 2)
      IF (MMAX .LT. KMAX+2) CALL SETERR(' IODE4 - MMAX.LT.KMAX+2', 23
     1   , 14, 2)
C/
      DO  1 I = 1, MMAX
         CALL IODEV(-(I+4000), FZAP, RZAP, N(I), LZAP)
   1     CONTINUE
C TEST N FOR MONOTONICITY.
      DO  2 I = 2, MMAX
C/6S
C        IF (N(I) .LE. N(I-1)) CALL SETERR(
C    1      37H IODE4 - N IS NOT MONOTONE INCREASING, 37, 16, 2)
C/7S
         IF (N(I) .LE. N(I-1)) CALL SETERR(
     1      ' IODE4 - N IS NOT MONOTONE INCREASING', 37, 16, 2)
C/
   2     CONTINUE
      CALL IODE4(V, NV, TSTART, TSTOP, DT, D, THETA, KEEJAC, MINIT,
     1   MAXIT, USENGJ, USENNS, USENFD, BETA, GAMMA, DELTA, N, MMAX,
     2   HFRACT, EGIVE, KMAX, XPOLY, KINIT, IRCS, ERROR, ERRPAR, ERPUTS,
     3   INMI, DA, HANDLE)
      RETURN
      END