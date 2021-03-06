      SUBROUTINE FIXLAB(ND)
C
C     ROUTINE SETS END-OF-DEF-STMT NO FOR LABELS
C     WHEN CALLED BY END STMT, FIXES ALL LABEL DEFS YET UNBOUND
C     TO THE END OF PGM STMT NO.  WHEN CALLED BY DO STMT
C     FIXES UP ALL LABELS AT THE LEVEL OF THE CURRENT
C     DO TO END-OF-DO STMT NO;  ND TRUE MEANS AN END STMT CALLED FIXLAB
C
      LOGICAL ND
      INTEGER DOLIST, DOPT, BNEXT, SYMHD, DSA, PDSA
      COMMON /CTABL/ LDSA, PDSA, DSA(5000)
      COMMON /DOS/ DOPT, LDO, DOLIST(192)
      COMMON /FACTS/ NAME, NOST, ITYP, IASF
      COMMON /TABL/ NEXT, LABHD, SYMHD, BNEXT
      LEV = -DOPT/6
      I = LABHD
   10 IF (I.EQ.0) RETURN
      K = IGATT1(I,2)
      IF (K.NE.1) GO TO 30
      K = IGATT1(I,1)
      IF (K.NE.1) GO TO 30
      K = DSA(I+2)
      IF (ND) GO TO 20
      IF (DSA(K+1).EQ.LEV) DSA(K+1) = NOST
      GO TO 30
   20 IF (DSA(K+1).LE.0) DSA(K+1) = NOST
   30 I = DSA(I+3)
      GO TO 10
      END
