! single-user bootstrap
HALT
UNJAM
INIT
! memory controller interleaving, for two controllers
D 20002000 101
D 20002004 4000
D 20004000 101
D 20004004 4000
LOAD/ST:FA00 UDA.ROM
D SP 200
D R1 01         ! first unibus adapter, second uda50 address
D R3 0          ! unit 0
D R5 0          ! multi-user
START FA02
                                                                                                                                                                                         