      SUBROUTINE PRNTID(ID,ARGCNT)
C     PRINT VARIABLE NAMES
      INTEGER ID(4,1),ARGCNT
      INTEGER ALFA(52),ALFB(52),ALFL,CASE
      INTEGER DDT,ERR,FMT,LCT(4),LIN(1024),LPT(6),RIO,WIO,RTE,WTE,HIO
      INTEGER SYM,SYN(4),BUF(256),CHAR,FLP(2),FIN,FUN,LHS,RHS,RAN(2)
      COMMON /ALFS/ ALFA,ALFB,ALFL,CASE
      COMMON /IOP/ DDT,ERR,FMT,LCT,LIN,LPT,RIO,WIO,RTE,WTE,HIO
      COMMON /COM/ SYM,SYN,BUF,CHAR,FLP,FIN,FUN,LHS,RHS,RAN
      INTEGER EQUAL
      DATA EQUAL/46/
      J1 = 1
   10 J2 = MIN0(J1+7,IABS(ARGCNT))
      L = 0
      DO 15 J = J1,J2
      DO 15 I = 1, 4
      K = ID(I,J)+1
      L = L+1
      BUF(L) = ALFA(K)
   15 CONTINUE
      IF (ARGCNT .EQ. -1) L=L+1
      IF (ARGCNT .EQ. -1) BUF(L) = ALFA(EQUAL+1)
      WRITE(WTE,20) (BUF(I),I=1,L)
      IF (WIO .NE. 0) WRITE(WIO,20) (BUF(I),I=1,L)
   20 FORMAT(0X,8(4A1,2H  ))
      J1 = J1+8
      IF (J1 .LE. IABS(ARGCNT)) GO TO 10
      RETURN
      END