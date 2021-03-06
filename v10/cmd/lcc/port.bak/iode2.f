      SUBROUTINE IODE2(V, NV, TSTART, TSTOP, DT, D, EQUIL, KMAX,
     1   XPOLY, KINIT, ERROR, ERRPAR, ERPUTS, HANDLE)
      INTEGER NV
      EXTERNAL D, ERROR, HANDLE
      INTEGER KMAX, KINIT
      REAL V(NV), TSTART, TSTOP, DT, ERRPAR(2)
      LOGICAL EQUIL, XPOLY, ERPUTS
      EXTERNAL IODED, IODEN
      INTEGER KEEJAC, MINIT, MAXIT
      REAL THETA
C THE THIRD LEVEL OF IODES.
C CHECK THE INPUT FOR ERRORS.
      IF (.NOT. EQUIL) GOTO 1
         THETA = 1
         GOTO  2
   1     THETA = 0.5E0
   2  KEEJAC = 0
      MINIT = 10
      MAXIT = 15
      CALL IODE3(V, NV, TSTART, TSTOP, DT, D, THETA, KEEJAC, MINIT,
     1   MAXIT, KMAX, XPOLY, KINIT, ERROR, ERRPAR, ERPUTS, IODEN, IODED,
     2   HANDLE)
      RETURN
      END
