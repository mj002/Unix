!
! POWER FAIL AND OTHER DISASTER RESTART
!
! NOTE: THIS SCRIPT KNOWS WHICH IS THE PRIMARY DISK BOOTSTRAP!
!
E/Q R0
E/Q R0
HALT
E/ID 0/N:3F
E 20002000/N:2
E 20004000/N:2
E 20006000/N:7
E 20008000/N:7
E 20010000/N:7
E PSL
E R0/NE:F
E SP
E/V @ /NE:40
UNJAM
INIT
!DEPOSIT 20002000 101	! ENABLE INTERLEAVE FOR TR #1 MEMORY CONTROLLER
!DEPOSIT 20002004 4000	! FORCE 0 STARTING ADDRESS
!DEPOSIT 20004000 101	! ENABLE INTERLEAVE FOR TR #2 MEMORY CONTROLLER
!DEPOSIT 20004004 4000	! FORCE 0 STARTING ADDRESS
LOAD BOOT
D R11 0			! AUTO-RESTART PARAMETERS - 0=GO MULTI
D R10 0			! DEVICE CHOICE: (HP=0,UP=2,RK=3)
START 2
                                                                                                                                                                                                                                                                                                                                                                                                     