      SUBROUTINE MULNOSF(H,L,IP,SD,A,RS1,RS2,R)
C
      INCLUDE 'timsac_f.h'
C
C     PROGRAM 5.3.3   MULTIPLE UNOISE
C-----------------------------------------------------------------------
C     ** DESIGNED BY H. AKAIKE, THE INSTITUTE OF STATISTICAL MATHEMATICS
C     ** PROGRAMMED BY E. ARAHATA, THE INSTITUTE OF STATISTICAL MATHEMAT
C         TOKYO
C     ** DATE OF THE LATEST REVISION: MARCH 25, 1977
C     ** THIS PROGRAM WAS ORIGINALLY PUBLISHED IN
C         "DAINAMIKKU SISTEMU NO TOKEI-TEKI KAISEKI TO SEIGYO (STATISTICA
C         ANALYSIS AND CONTROL OF DYNAMIC SYSTEMS)" BY H. AKAIKE AND
C         T. NAKAGAWA, SAIENSU-SHA, TOKYO, 1972 (IN JAPANESE)
C-----------------------------------------------------------------------
C     THIS PROGRAM COMPUTES RELATIVE POWER CONTRIBUTIONS IN DIFFERENTIAL
C     AND INTEGRATED FORM, ASSUMING THE ORTHOGONALITY BETWEEN NOISE
C     SOURCES.
C     THE PROGRAM OPERATES ON THE OUTPUT OF PROGRAM 5.3.2 FPEC WITH
C     IL=0.
C     THE RESULTS ARE GIVEN AT FREQUIENCIES I/(2*H).
C
cc      !DEC$ ATTRIBUTES DLLEXPORT :: MULNOSF
c      USE DFLIB
C
cxx      IMPLICIT REAL*8(A-H,O-W)
cxx      IMPLICIT COMPLEX*16(X-Z)
cxx      INTEGER H,H1
c      COMMON G,GR,GI,LG,H,JJF
c      DIMENSION SD(10,10),A(30,10,10),X(10,10)
c      DIMENSION G(31),RS(10,10),R(10,10)
cxx      DIMENSION SD(IP,IP),A(L,IP,IP),X(IP,IP)
cxx      DIMENSION G(L+1),RS1(IP,IP),RS2(IP,IP,H+1),R(IP,IP,H+1)
      INTEGER :: H, L, IP
      REAL(8) :: SD(IP,IP), A(L,IP,IP), RS1(IP,IP), RS2(IP,IP,H+1),
     1           R(IP,IP,H+1)
      INTEGER :: H1
      REAL(8) :: G(L+1), GR, GI, CST0, CST1
      COMPLEX(kind(0d0)) :: X(IP,IP), XDET
C     INPUT / OUTPUT DATA FILE OPEN
c	CALL SETWND
c	CALL FLOPN2(NFL)
c	IF (NFL.EQ.0) GO TO 999
C     ABSOLUTE DIMENSIONS USED FOR SUBROUTINE CALL
c      MJ0=30
c      MJ1=10
      CST0=0.0D-00
      CST1=1.0D-00
C     H SPECIFICATION
c      READ(5,1) H
C     READING THE OUTPUT OF PROGRAM 5.3.2 FPEC WITH IL=0
c      READ(5,1) N,L,IP
C     SD INPUT
c      CALL REMATX(SD,IP,IP,1,MJ1,MJ1)
C     A INPUT
c      CALL REMAT3(A,L,IP,IP,1,MJ0,MJ1,MJ1)
cxx  310 H1=H+1
      H1=H+1
C     SD NORMALIZATION
cxx      DO 100 I=1,IP
      DO 101 I=1,IP
      DO 100 J=1,IP
c  100 RS(I,J)=SD(I,J)/DSQRT(SD(I,I)*SD(J,J))
cxx  100 RS1(I,J)=SD(I,J)/DSQRT(SD(I,I)*SD(J,J))
      RS1(I,J)=SD(I,J)/DSQRT(SD(I,I)*SD(J,J))
  100 CONTINUE
  101 CONTINUE
C     INITIAL CONDITION PRINT OUT
c      WRITE(6,59)
c      WRITE(6,60)
c      WRITE(6,61) H,N,L,IP
c      WRITE(6,161)
c      CALL SUBMPR(SD,IP,IP,MJ1,MJ1)
C     NORMALIZED SD PRINT OUT
c      WRITE(6,162)
c      CALL SUBMPR(RS,IP,IP,MJ1,MJ1)
c      CALL SUBMPR(RS,IP,IP,IP,IP)
C     A PRINT OUT
c      WRITE(6,420)
c      CALL PRMAT3(A,L,IP,IP,0,MJ0,MJ1,MJ1)
cxx  410 DO 10 JF=1,H1
      DO 10 JF=1,H1
      JJF=JF
C     AF COMPUTATION
      DO 40 II=1,IP
      DO 41 JJ=1,IP
      IF(II.NE.JJ) GO TO 42
      G(1)=CST1
      GO TO 43
   42 G(1)=CST0
   43 DO 45 I=1,L
      I1=I+1
cxx   45 G(I1)=-A(I,II,JJ)
      G(I1)=-A(I,II,JJ)
   45 CONTINUE
cxx   44 LG=L
      LG=L
c      CALL FGER1
      CALL FGER1(G,GR,GI,LG,H,JJF)
      X(II,JJ)=DCMPLX(GR,GI)
   41 CONTINUE
   40 CONTINUE
C     INVERSE OF AF (COMPLEX) COMPUTATION
c      CALL INVDET(X,XDET,IP,MJ1)
c      CALL INVDET(X,XDET,IP)
      CALL INVDETC(X,XDET,IP)
C     RELATIVE POWER CONTRIBUTIONS COMPUTATION
c      CALL SUBNOS(X,SD,IP,RS,R,MJ1)
c      CALL SUBNOS(X,SD,IP,RS,R,IP)
      CALL SUBNOS(X,SD,IP,RS2(1,1,JF),R(1,1,JF),IP)
C     RELATIVE POWER CONTRIBUTIONS PRINT OUT
c      JFM1=JF-1
c      WRITE(6,65) JFM1
c      WRITE(6,165)
c      CALL SUBMPR(RS,IP,IP,10,10)
c      WRITE(6,166)
c      CALL SUBMPR(R,IP,IP,10,10)
   10 CONTINUE
c	CALL FLCLS2(NFL)
c  999 CONTINUE
      RETURN
c    1 FORMAT(10I5)
c    2 FORMAT(4D20.10)
c   59 FORMAT(1H ,31HPROGRAM 5.3.3   MULTIPLE UNOISE)
c   60 FORMAT(1H ,17HINITIAL CONDITION)
c   61 FORMAT(1H ,2HH=,I5,5X,2HN=,I5,5X,2HL=,I5,5X,3HIP=,I5)
c  161 FORMAT(/1H ,7HSD(I,J))
c  162 FORMAT(/1H ,13HNORMALIZED SD)
c  420 FORMAT(/1H ,6HA(I,J))
c   65 FORMAT(///1H ,2HF=,I5)
c  165 FORMAT(/1H ,40HDIFFERENTIAL RELATIVE POWER CONTRIBUTION)
c  166 FORMAT(/1H ,38HINTEGRATED RELATIVE POWER CONTRIBUTION)
      END SUBROUTINE
