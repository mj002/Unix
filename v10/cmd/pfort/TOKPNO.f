      LOGICAL FUNCTION TOKPNO(K1, K2, LL)
C
C     ROUTINE RECOGNIZES A POSITIVE INTEGER CONSTANT
C     IN STMT(K1)-STMT(K2-1), AND RETURNS ITS VALUE IN LL
C
      INTEGER STMT, PSTMT
      COMMON /INPUT/ NSTMT, PSTMT, STMT(1327)
      TOKPNO = .FALSE.
      CALL NEXTOK(K1, K2, K)
      IF (K.NE.1) RETURN
      K=K2-1
      LL = 0
      DO 10 KK=K1,K
        LL = 10 * LL + STMT(KK)
   10 CONTINUE
      IF (LL.GT.0) TOKPNO = .TRUE.
      RETURN
      END
