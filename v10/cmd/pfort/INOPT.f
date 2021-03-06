      SUBROUTINE INOPT(CARD)
      INTEGER S(8), CARD(80), J(5)
      LOGICAL OPT, P1ERR
      COMMON /OPTNS/ OPT(5), P1ERR
      DATA S(1), S(2), S(3), S(4), S(5), S(6), S(7) /1HS,1HR,1HP,1HL,
     *    1HC,1H,,1HN/, S(8) /1H /
C
C     OPT(1) IF TRUE, PRINT SYMBOL TABLE
C      IF FALSE, NOSYMBOL TABLE PRINTED
C     OPT(2) IF TRUE, PRINT CROSS REFERENCES
C      IF FALSE, NO REFS PRINTED
C     OPT(3) IF TRUE, DO PASS 2; ELSE DO NOT
C     OPT(4) IF TRUE GET LISTING OF PGM; ELSE DO NOT
C      OPT(5) IF TRUE, COMPILE PGM AFTER PROCESSING; ELSE DO NOT
C     SET OPTIONS FROM CARD READ IN BY "IN"
C     P2 IS TURNED OFF ONLY ONCE A RUN;  IT CANNOT BE TURNED ON AGAIN
C     OPTIONS CARD IS ONLY ACCEPTED IF SYNTAX ON CARD IS OK
C     SYNTAX IS C* FOLLOWED BY AT LEAST ONE OPTION OF THEFORM
C     OPT BLANKS, OPT N, AT LEAST ONE OF (S,R,P,L,C), OPT BLANKS
C     WHERE OPTIONS ARE SEPARATEDBY COMMAS
C
      DO 10 I=1,5
        J(I) = 0
   10 CONTINUE
      IP = 2
   20 IP = IP + 1
      IF (IP.GE.73) GO TO 60
C      DEBLANK LEADING BLANKS
      IF (CARD(IP).EQ.S(8)) GO TO 20
      L = 1
C
C     CHECK FOR NEGATIVE
C
      IF (CARD(IP).NE.S(7)) GO TO 30
      L = -1
      IP = IP + 1
      IF (IP.GE.73) GO TO 60
   30 DO 40 I=1,5
        IF (S(I).NE.CARD(IP)) GO TO 40
        J(I) = J(I) + L
        GO TO 50
   40 CONTINUE
      GOTO 100
C
C     FLUSH BLANKS TO NEXT COMMA
C
   50 IP = IP + 1
      IF (IP.GE.73) GO TO 60
      IF (CARD(IP).EQ.S(6)) GO TO 20
      IF(CARD(IP).NE.S(8)) GOTO 100
      GO TO 50
   60 DO 90 K=1,5
        IF (J(K)) 70, 90, 80
   70   OPT(K) = .FALSE.
        GO TO 90
C     DO NOT LET USER TURN ON PASS2 AFTER WE TURN IT OFF
   80   IF (K.EQ.3 .AND. .NOT.OPT(3)) GO TO 90
        OPT(K) = .TRUE.
   90 CONTINUE
 100  RETURN
      END
