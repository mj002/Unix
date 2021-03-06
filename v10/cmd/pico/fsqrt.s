#
#	fsqrt - crude but quick floating point square root (single precision)
#	D.P.Mitchell  82/04/18.
#
	.text
	.align	1
	.globl	_fsqrt
	.globl	_ftable
_fsqrt:
	.word	0x0000
	movl	4(ap),r1
	extzv	$5,$10,r1,r0		# look up first approximation
	jeql	1f
	movl	_ftable[r0],r0
	divf3	r0,r1,r2		# one step of Newton's method
	addf2	r2,r0
	subw2	$0200,r0		# divide by two
	divf2	r0,r1			# second step of Newton's method
	addf2	r1,r0
	subw2	$0200,r0
1:	ret

	.data
	.align	2
_ftable:
	.long	0x00000000
	.long	0x00000000
	.long	0x00000000
	.long	0x00000000
	.long	0xc3b62087
	.long	0x17e32096
	.long	0x2b2b20a3
	.long	0x456f20af
	.long	0x000020c0
	.long	0x439520d4
	.long	0xc15a20e6
	.long	0xdef620f7
	.long	0xc3b62107
	.long	0x17e32116
	.long	0x2b2b2123
	.long	0x456f212f
	.long	0x00002140
	.long	0x43952154
	.long	0xc15a2166
	.long	0xdef62177
	.long	0xc3b62187
	.long	0x17e32196
	.long	0x2b2b21a3
	.long	0x456f21af
	.long	0x000021c0
	.long	0x439521d4
	.long	0xc15a21e6
	.long	0xdef621f7
	.long	0xc3b62207
	.long	0x17e32216
	.long	0x2b2b2223
	.long	0x456f222f
	.long	0x00002240
	.long	0x43952254
	.long	0xc15a2266
	.long	0xdef62277
	.long	0xc3b62287
	.long	0x17e32296
	.long	0x2b2b22a3
	.long	0x456f22af
	.long	0x000022c0
	.long	0x439522d4
	.long	0xc15a22e6
	.long	0xdef622f7
	.long	0xc3b62307
	.long	0x17e32316
	.long	0x2b2b2323
	.long	0x456f232f
	.long	0x00002340
	.long	0x43952354
	.long	0xc15a2366
	.long	0xdef62377
	.long	0xc3b62387
	.long	0x17e32396
	.long	0x2b2b23a3
	.long	0x456f23af
	.long	0x000023c0
	.long	0x439523d4
	.long	0xc15a23e6
	.long	0xdef623f7
	.long	0xc3b62407
	.long	0x17e32416
	.long	0x2b2b2423
	.long	0x456f242f
	.long	0x00002440
	.long	0x43952454
	.long	0xc15a2466
	.long	0xdef62477
	.long	0xc3b62487
	.long	0x17e32496
	.long	0x2b2b24a3
	.long	0x456f24af
	.long	0x000024c0
	.long	0x439524d4
	.long	0xc15a24e6
	.long	0xdef624f7
	.long	0xc3b62507
	.long	0x17e32516
	.long	0x2b2b2523
	.long	0x456f252f
	.long	0x00002540
	.long	0x43952554
	.long	0xc15a2566
	.long	0xdef62577
	.long	0xc3b62587
	.long	0x17e32596
	.long	0x2b2b25a3
	.long	0x456f25af
	.long	0x000025c0
	.long	0x439525d4
	.long	0xc15a25e6
	.long	0xdef625f7
	.long	0xc3b62607
	.long	0x17e32616
	.long	0x2b2b2623
	.long	0x456f262f
	.long	0x00002640
	.long	0x43952654
	.long	0xc15a2666
	.long	0xdef62677
	.long	0xc3b62687
	.long	0x17e32696
	.long	0x2b2b26a3
	.long	0x456f26af
	.long	0x000026c0
	.long	0x439526d4
	.long	0xc15a26e6
	.long	0xdef626f7
	.long	0xc3b62707
	.long	0x17e32716
	.long	0x2b2b2723
	.long	0x456f272f
	.long	0x00002740
	.long	0x43952754
	.long	0xc15a2766
	.long	0xdef62777
	.long	0xc3b62787
	.long	0x17e32796
	.long	0x2b2b27a3
	.long	0x456f27af
	.long	0x000027c0
	.long	0x439527d4
	.long	0xc15a27e6
	.long	0xdef627f7
	.long	0xc3b62807
	.long	0x17e32816
	.long	0x2b2b2823
	.long	0x456f282f
	.long	0x00002840
	.long	0x43952854
	.long	0xc15a2866
	.long	0xdef62877
	.long	0xc3b62887
	.long	0x17e32896
	.long	0x2b2b28a3
	.long	0x456f28af
	.long	0x000028c0
	.long	0x439528d4
	.long	0xc15a28e6
	.long	0xdef628f7
	.long	0xc3b62907
	.long	0x17e32916
	.long	0x2b2b2923
	.long	0x456f292f
	.long	0x00002940
	.long	0x43952954
	.long	0xc15a2966
	.long	0xdef62977
	.long	0xc3b62987
	.long	0x17e32996
	.long	0x2b2b29a3
	.long	0x456f29af
	.long	0x000029c0
	.long	0x439529d4
	.long	0xc15a29e6
	.long	0xdef629f7
	.long	0xc3b62a07
	.long	0x17e32a16
	.long	0x2b2b2a23
	.long	0x456f2a2f
	.long	0x00002a40
	.long	0x43952a54
	.long	0xc15a2a66
	.long	0xdef62a77
	.long	0xc3b62a87
	.long	0x17e32a96
	.long	0x2b2b2aa3
	.long	0x456f2aaf
	.long	0x00002ac0
	.long	0x43952ad4
	.long	0xc15a2ae6
	.long	0xdef62af7
	.long	0xc3b62b07
	.long	0x17e32b16
	.long	0x2b2b2b23
	.long	0x456f2b2f
	.long	0x00002b40
	.long	0x43952b54
	.long	0xc15a2b66
	.long	0xdef62b77
	.long	0xc3b62b87
	.long	0x17e32b96
	.long	0x2b2b2ba3
	.long	0x456f2baf
	.long	0x00002bc0
	.long	0x43952bd4
	.long	0xc15a2be6
	.long	0xdef62bf7
	.long	0xc3b62c07
	.long	0x17e32c16
	.long	0x2b2b2c23
	.long	0x456f2c2f
	.long	0x00002c40
	.long	0x43952c54
	.long	0xc15a2c66
	.long	0xdef62c77
	.long	0xc3b62c87
	.long	0x17e32c96
	.long	0x2b2b2ca3
	.long	0x456f2caf
	.long	0x00002cc0
	.long	0x43952cd4
	.long	0xc15a2ce6
	.long	0xdef62cf7
	.long	0xc3b62d07
	.long	0x17e32d16
	.long	0x2b2b2d23
	.long	0x456f2d2f
	.long	0x00002d40
	.long	0x43952d54
	.long	0xc15a2d66
	.long	0xdef62d77
	.long	0xc3b62d87
	.long	0x17e32d96
	.long	0x2b2b2da3
	.long	0x456f2daf
	.long	0x00002dc0
	.long	0x43952dd4
	.long	0xc15a2de6
	.long	0xdef62df7
	.long	0xc3b62e07
	.long	0x17e32e16
	.long	0x2b2b2e23
	.long	0x456f2e2f
	.long	0x00002e40
	.long	0x43952e54
	.long	0xc15a2e66
	.long	0xdef62e77
	.long	0xc3b62e87
	.long	0x17e32e96
	.long	0x2b2b2ea3
	.long	0x456f2eaf
	.long	0x00002ec0
	.long	0x43952ed4
	.long	0xc15a2ee6
	.long	0xdef62ef7
	.long	0xc3b62f07
	.long	0x17e32f16
	.long	0x2b2b2f23
	.long	0x456f2f2f
	.long	0x00002f40
	.long	0x43952f54
	.long	0xc15a2f66
	.long	0xdef62f77
	.long	0xc3b62f87
	.long	0x17e32f96
	.long	0x2b2b2fa3
	.long	0x456f2faf
	.long	0x00002fc0
	.long	0x43952fd4
	.long	0xc15a2fe6
	.long	0xdef62ff7
	.long	0xc3b63007
	.long	0x17e33016
	.long	0x2b2b3023
	.long	0x456f302f
	.long	0x00003040
	.long	0x43953054
	.long	0xc15a3066
	.long	0xdef63077
	.long	0xc3b63087
	.long	0x17e33096
	.long	0x2b2b30a3
	.long	0x456f30af
	.long	0x000030c0
	.long	0x439530d4
	.long	0xc15a30e6
	.long	0xdef630f7
	.long	0xc3b63107
	.long	0x17e33116
	.long	0x2b2b3123
	.long	0x456f312f
	.long	0x00003140
	.long	0x43953154
	.long	0xc15a3166
	.long	0xdef63177
	.long	0xc3b63187
	.long	0x17e33196
	.long	0x2b2b31a3
	.long	0x456f31af
	.long	0x000031c0
	.long	0x439531d4
	.long	0xc15a31e6
	.long	0xdef631f7
	.long	0xc3b63207
	.long	0x17e33216
	.long	0x2b2b3223
	.long	0x456f322f
	.long	0x00003240
	.long	0x43953254
	.long	0xc15a3266
	.long	0xdef63277
	.long	0xc3b63287
	.long	0x17e33296
	.long	0x2b2b32a3
	.long	0x456f32af
	.long	0x000032c0
	.long	0x439532d4
	.long	0xc15a32e6
	.long	0xdef632f7
	.long	0xc3b63307
	.long	0x17e33316
	.long	0x2b2b3323
	.long	0x456f332f
	.long	0x00003340
	.long	0x43953354
	.long	0xc15a3366
	.long	0xdef63377
	.long	0xc3b63387
	.long	0x17e33396
	.long	0x2b2b33a3
	.long	0x456f33af
	.long	0x000033c0
	.long	0x439533d4
	.long	0xc15a33e6
	.long	0xdef633f7
	.long	0xc3b63407
	.long	0x17e33416
	.long	0x2b2b3423
	.long	0x456f342f
	.long	0x00003440
	.long	0x43953454
	.long	0xc15a3466
	.long	0xdef63477
	.long	0xc3b63487
	.long	0x17e33496
	.long	0x2b2b34a3
	.long	0x456f34af
	.long	0x000034c0
	.long	0x439534d4
	.long	0xc15a34e6
	.long	0xdef634f7
	.long	0xc3b63507
	.long	0x17e33516
	.long	0x2b2b3523
	.long	0x456f352f
	.long	0x00003540
	.long	0x43953554
	.long	0xc15a3566
	.long	0xdef63577
	.long	0xc3b63587
	.long	0x17e33596
	.long	0x2b2b35a3
	.long	0x456f35af
	.long	0x000035c0
	.long	0x439535d4
	.long	0xc15a35e6
	.long	0xdef635f7
	.long	0xc3b63607
	.long	0x17e33616
	.long	0x2b2b3623
	.long	0x456f362f
	.long	0x00003640
	.long	0x43953654
	.long	0xc15a3666
	.long	0xdef63677
	.long	0xc3b63687
	.long	0x17e33696
	.long	0x2b2b36a3
	.long	0x456f36af
	.long	0x000036c0
	.long	0x439536d4
	.long	0xc15a36e6
	.long	0xdef636f7
	.long	0xc3b63707
	.long	0x17e33716
	.long	0x2b2b3723
	.long	0x456f372f
	.long	0x00003740
	.long	0x43953754
	.long	0xc15a3766
	.long	0xdef63777
	.long	0xc3b63787
	.long	0x17e33796
	.long	0x2b2b37a3
	.long	0x456f37af
	.long	0x000037c0
	.long	0x439537d4
	.long	0xc15a37e6
	.long	0xdef637f7
	.long	0xc3b63807
	.long	0x17e33816
	.long	0x2b2b3823
	.long	0x456f382f
	.long	0x00003840
	.long	0x43953854
	.long	0xc15a3866
	.long	0xdef63877
	.long	0xc3b63887
	.long	0x17e33896
	.long	0x2b2b38a3
	.long	0x456f38af
	.long	0x000038c0
	.long	0x439538d4
	.long	0xc15a38e6
	.long	0xdef638f7
	.long	0xc3b63907
	.long	0x17e33916
	.long	0x2b2b3923
	.long	0x456f392f
	.long	0x00003940
	.long	0x43953954
	.long	0xc15a3966
	.long	0xdef63977
	.long	0xc3b63987
	.long	0x17e33996
	.long	0x2b2b39a3
	.long	0x456f39af
	.long	0x000039c0
	.long	0x439539d4
	.long	0xc15a39e6
	.long	0xdef639f7
	.long	0xc3b63a07
	.long	0x17e33a16
	.long	0x2b2b3a23
	.long	0x456f3a2f
	.long	0x00003a40
	.long	0x43953a54
	.long	0xc15a3a66
	.long	0xdef63a77
	.long	0xc3b63a87
	.long	0x17e33a96
	.long	0x2b2b3aa3
	.long	0x456f3aaf
	.long	0x00003ac0
	.long	0x43953ad4
	.long	0xc15a3ae6
	.long	0xdef63af7
	.long	0xc3b63b07
	.long	0x17e33b16
	.long	0x2b2b3b23
	.long	0x456f3b2f
	.long	0x00003b40
	.long	0x43953b54
	.long	0xc15a3b66
	.long	0xdef63b77
	.long	0xc3b63b87
	.long	0x17e33b96
	.long	0x2b2b3ba3
	.long	0x456f3baf
	.long	0x00003bc0
	.long	0x43953bd4
	.long	0xc15a3be6
	.long	0xdef63bf7
	.long	0xc3b63c07
	.long	0x17e33c16
	.long	0x2b2b3c23
	.long	0x456f3c2f
	.long	0x00003c40
	.long	0x43953c54
	.long	0xc15a3c66
	.long	0xdef63c77
	.long	0xc3b63c87
	.long	0x17e33c96
	.long	0x2b2b3ca3
	.long	0x456f3caf
	.long	0x00003cc0
	.long	0x43953cd4
	.long	0xc15a3ce6
	.long	0xdef63cf7
	.long	0xc3b63d07
	.long	0x17e33d16
	.long	0x2b2b3d23
	.long	0x456f3d2f
	.long	0x00003d40
	.long	0x43953d54
	.long	0xc15a3d66
	.long	0xdef63d77
	.long	0xc3b63d87
	.long	0x17e33d96
	.long	0x2b2b3da3
	.long	0x456f3daf
	.long	0x00003dc0
	.long	0x43953dd4
	.long	0xc15a3de6
	.long	0xdef63df7
	.long	0xc3b63e07
	.long	0x17e33e16
	.long	0x2b2b3e23
	.long	0x456f3e2f
	.long	0x00003e40
	.long	0x43953e54
	.long	0xc15a3e66
	.long	0xdef63e77
	.long	0xc3b63e87
	.long	0x17e33e96
	.long	0x2b2b3ea3
	.long	0x456f3eaf
	.long	0x00003ec0
	.long	0x43953ed4
	.long	0xc15a3ee6
	.long	0xdef63ef7
	.long	0xc3b63f07
	.long	0x17e33f16
	.long	0x2b2b3f23
	.long	0x456f3f2f
	.long	0x00003f40
	.long	0x43953f54
	.long	0xc15a3f66
	.long	0xdef63f77
	.long	0xc3b63f87
	.long	0x17e33f96
	.long	0x2b2b3fa3
	.long	0x456f3faf
	.long	0x00003fc0
	.long	0x43953fd4
	.long	0xc15a3fe6
	.long	0xdef63ff7
	.long	0xc3b64007
	.long	0x17e34016
	.long	0x2b2b4023
	.long	0x456f402f
	.long	0x00004040
	.long	0x43954054
	.long	0xc15a4066
	.long	0xdef64077
	.long	0xc3b64087
	.long	0x17e34096
	.long	0x2b2b40a3
	.long	0x456f40af
	.long	0x000040c0
	.long	0x439540d4
	.long	0xc15a40e6
	.long	0xdef640f7
	.long	0xc3b64107
	.long	0x17e34116
	.long	0x2b2b4123
	.long	0x456f412f
	.long	0x00004140
	.long	0x43954154
	.long	0xc15a4166
	.long	0xdef64177
	.long	0xc3b64187
	.long	0x17e34196
	.long	0x2b2b41a3
	.long	0x456f41af
	.long	0x000041c0
	.long	0x439541d4
	.long	0xc15a41e6
	.long	0xdef641f7
	.long	0xc3b64207
	.long	0x17e34216
	.long	0x2b2b4223
	.long	0x456f422f
	.long	0x00004240
	.long	0x43954254
	.long	0xc15a4266
	.long	0xdef64277
	.long	0xc3b64287
	.long	0x17e34296
	.long	0x2b2b42a3
	.long	0x456f42af
	.long	0x000042c0
	.long	0x439542d4
	.long	0xc15a42e6
	.long	0xdef642f7
	.long	0xc3b64307
	.long	0x17e34316
	.long	0x2b2b4323
	.long	0x456f432f
	.long	0x00004340
	.long	0x43954354
	.long	0xc15a4366
	.long	0xdef64377
	.long	0xc3b64387
	.long	0x17e34396
	.long	0x2b2b43a3
	.long	0x456f43af
	.long	0x000043c0
	.long	0x439543d4
	.long	0xc15a43e6
	.long	0xdef643f7
	.long	0xc3b64407
	.long	0x17e34416
	.long	0x2b2b4423
	.long	0x456f442f
	.long	0x00004440
	.long	0x43954454
	.long	0xc15a4466
	.long	0xdef64477
	.long	0xc3b64487
	.long	0x17e34496
	.long	0x2b2b44a3
	.long	0x456f44af
	.long	0x000044c0
	.long	0x439544d4
	.long	0xc15a44e6
	.long	0xdef644f7
	.long	0xc3b64507
	.long	0x17e34516
	.long	0x2b2b4523
	.long	0x456f452f
	.long	0x00004540
	.long	0x43954554
	.long	0xc15a4566
	.long	0xdef64577
	.long	0xc3b64587
	.long	0x17e34596
	.long	0x2b2b45a3
	.long	0x456f45af
	.long	0x000045c0
	.long	0x439545d4
	.long	0xc15a45e6
	.long	0xdef645f7
	.long	0xc3b64607
	.long	0x17e34616
	.long	0x2b2b4623
	.long	0x456f462f
	.long	0x00004640
	.long	0x43954654
	.long	0xc15a4666
	.long	0xdef64677
	.long	0xc3b64687
	.long	0x17e34696
	.long	0x2b2b46a3
	.long	0x456f46af
	.long	0x000046c0
	.long	0x439546d4
	.long	0xc15a46e6
	.long	0xdef646f7
	.long	0xc3b64707
	.long	0x17e34716
	.long	0x2b2b4723
	.long	0x456f472f
	.long	0x00004740
	.long	0x43954754
	.long	0xc15a4766
	.long	0xdef64777
	.long	0xc3b64787
	.long	0x17e34796
	.long	0x2b2b47a3
	.long	0x456f47af
	.long	0x000047c0
	.long	0x439547d4
	.long	0xc15a47e6
	.long	0xdef647f7
	.long	0xc3b64807
	.long	0x17e34816
	.long	0x2b2b4823
	.long	0x456f482f
	.long	0x00004840
	.long	0x43954854
	.long	0xc15a4866
	.long	0xdef64877
	.long	0xc3b64887
	.long	0x17e34896
	.long	0x2b2b48a3
	.long	0x456f48af
	.long	0x000048c0
	.long	0x439548d4
	.long	0xc15a48e6
	.long	0xdef648f7
	.long	0xc3b64907
	.long	0x17e34916
	.long	0x2b2b4923
	.long	0x456f492f
	.long	0x00004940
	.long	0x43954954
	.long	0xc15a4966
	.long	0xdef64977
	.long	0xc3b64987
	.long	0x17e34996
	.long	0x2b2b49a3
	.long	0x456f49af
	.long	0x000049c0
	.long	0x439549d4
	.long	0xc15a49e6
	.long	0xdef649f7
	.long	0xc3b64a07
	.long	0x17e34a16
	.long	0x2b2b4a23
	.long	0x456f4a2f
	.long	0x00004a40
	.long	0x43954a54
	.long	0xc15a4a66
	.long	0xdef64a77
	.long	0xc3b64a87
	.long	0x17e34a96
	.long	0x2b2b4aa3
	.long	0x456f4aaf
	.long	0x00004ac0
	.long	0x43954ad4
	.long	0xc15a4ae6
	.long	0xdef64af7
	.long	0xc3b64b07
	.long	0x17e34b16
	.long	0x2b2b4b23
	.long	0x456f4b2f
	.long	0x00004b40
	.long	0x43954b54
	.long	0xc15a4b66
	.long	0xdef64b77
	.long	0xc3b64b87
	.long	0x17e34b96
	.long	0x2b2b4ba3
	.long	0x456f4baf
	.long	0x00004bc0
	.long	0x43954bd4
	.long	0xc15a4be6
	.long	0xdef64bf7
	.long	0xc3b64c07
	.long	0x17e34c16
	.long	0x2b2b4c23
	.long	0x456f4c2f
	.long	0x00004c40
	.long	0x43954c54
	.long	0xc15a4c66
	.long	0xdef64c77
	.long	0xc3b64c87
	.long	0x17e34c96
	.long	0x2b2b4ca3
	.long	0x456f4caf
	.long	0x00004cc0
	.long	0x43954cd4
	.long	0xc15a4ce6
	.long	0xdef64cf7
	.long	0xc3b64d07
	.long	0x17e34d16
	.long	0x2b2b4d23
	.long	0x456f4d2f
	.long	0x00004d40
	.long	0x43954d54
	.long	0xc15a4d66
	.long	0xdef64d77
	.long	0xc3b64d87
	.long	0x17e34d96
	.long	0x2b2b4da3
	.long	0x456f4daf
	.long	0x00004dc0
	.long	0x43954dd4
	.long	0xc15a4de6
	.long	0xdef64df7
	.long	0xc3b64e07
	.long	0x17e34e16
	.long	0x2b2b4e23
	.long	0x456f4e2f
	.long	0x00004e40
	.long	0x43954e54
	.long	0xc15a4e66
	.long	0xdef64e77
	.long	0xc3b64e87
	.long	0x17e34e96
	.long	0x2b2b4ea3
	.long	0x456f4eaf
	.long	0x00004ec0
	.long	0x43954ed4
	.long	0xc15a4ee6
	.long	0xdef64ef7
	.long	0xc3b64f07
	.long	0x17e34f16
	.long	0x2b2b4f23
	.long	0x456f4f2f
	.long	0x00004f40
	.long	0x43954f54
	.long	0xc15a4f66
	.long	0xdef64f77
	.long	0xc3b64f87
	.long	0x17e34f96
	.long	0x2b2b4fa3
	.long	0x456f4faf
	.long	0x00004fc0
	.long	0x43954fd4
	.long	0xc15a4fe6
	.long	0xdef64ff7
	.long	0xc3b65007
	.long	0x17e35016
	.long	0x2b2b5023
	.long	0x456f502f
	.long	0x00005040
	.long	0x43955054
	.long	0xc15a5066
	.long	0xdef65077
	.long	0xc3b65087
	.long	0x17e35096
	.long	0x2b2b50a3
	.long	0x456f50af
	.long	0x000050c0
	.long	0x439550d4
	.long	0xc15a50e6
	.long	0xdef650f7
	.long	0xc3b65107
	.long	0x17e35116
	.long	0x2b2b5123
	.long	0x456f512f
	.long	0x00005140
	.long	0x43955154
	.long	0xc15a5166
	.long	0xdef65177
	.long	0xc3b65187
	.long	0x17e35196
	.long	0x2b2b51a3
	.long	0x456f51af
	.long	0x000051c0
	.long	0x439551d4
	.long	0xc15a51e6
	.long	0xdef651f7
	.long	0xc3b65207
	.long	0x17e35216
	.long	0x2b2b5223
	.long	0x456f522f
	.long	0x00005240
	.long	0x43955254
	.long	0xc15a5266
	.long	0xdef65277
	.long	0xc3b65287
	.long	0x17e35296
	.long	0x2b2b52a3
	.long	0x456f52af
	.long	0x000052c0
	.long	0x439552d4
	.long	0xc15a52e6
	.long	0xdef652f7
	.long	0xc3b65307
	.long	0x17e35316
	.long	0x2b2b5323
	.long	0x456f532f
	.long	0x00005340
	.long	0x43955354
	.long	0xc15a5366
	.long	0xdef65377
	.long	0xc3b65387
	.long	0x17e35396
	.long	0x2b2b53a3
	.long	0x456f53af
	.long	0x000053c0
	.long	0x439553d4
	.long	0xc15a53e6
	.long	0xdef653f7
	.long	0xc3b65407
	.long	0x17e35416
	.long	0x2b2b5423
	.long	0x456f542f
	.long	0x00005440
	.long	0x43955454
	.long	0xc15a5466
	.long	0xdef65477
	.long	0xc3b65487
	.long	0x17e35496
	.long	0x2b2b54a3
	.long	0x456f54af
	.long	0x000054c0
	.long	0x439554d4
	.long	0xc15a54e6
	.long	0xdef654f7
	.long	0xc3b65507
	.long	0x17e35516
	.long	0x2b2b5523
	.long	0x456f552f
	.long	0x00005540
	.long	0x43955554
	.long	0xc15a5566
	.long	0xdef65577
	.long	0xc3b65587
	.long	0x17e35596
	.long	0x2b2b55a3
	.long	0x456f55af
	.long	0x000055c0
	.long	0x439555d4
	.long	0xc15a55e6
	.long	0xdef655f7
	.long	0xc3b65607
	.long	0x17e35616
	.long	0x2b2b5623
	.long	0x456f562f
	.long	0x00005640
	.long	0x43955654
	.long	0xc15a5666
	.long	0xdef65677
	.long	0xc3b65687
	.long	0x17e35696
	.long	0x2b2b56a3
	.long	0x456f56af
	.long	0x000056c0
	.long	0x439556d4
	.long	0xc15a56e6
	.long	0xdef656f7
	.long	0xc3b65707
	.long	0x17e35716
	.long	0x2b2b5723
	.long	0x456f572f
	.long	0x00005740
	.long	0x43955754
	.long	0xc15a5766
	.long	0xdef65777
	.long	0xc3b65787
	.long	0x17e35796
	.long	0x2b2b57a3
	.long	0x456f57af
	.long	0x000057c0
	.long	0x439557d4
	.long	0xc15a57e6
	.long	0xdef657f7
	.long	0xc3b65807
	.long	0x17e35816
	.long	0x2b2b5823
	.long	0x456f582f
	.long	0x00005840
	.long	0x43955854
	.long	0xc15a5866
	.long	0xdef65877
	.long	0xc3b65887
	.long	0x17e35896
	.long	0x2b2b58a3
	.long	0x456f58af
	.long	0x000058c0
	.long	0x439558d4
	.long	0xc15a58e6
	.long	0xdef658f7
	.long	0xc3b65907
	.long	0x17e35916
	.long	0x2b2b5923
	.long	0x456f592f
	.long	0x00005940
	.long	0x43955954
	.long	0xc15a5966
	.long	0xdef65977
	.long	0xc3b65987
	.long	0x17e35996
	.long	0x2b2b59a3
	.long	0x456f59af
	.long	0x000059c0
	.long	0x439559d4
	.long	0xc15a59e6
	.long	0xdef659f7
	.long	0xc3b65a07
	.long	0x17e35a16
	.long	0x2b2b5a23
	.long	0x456f5a2f
	.long	0x00005a40
	.long	0x43955a54
	.long	0xc15a5a66
	.long	0xdef65a77
	.long	0xc3b65a87
	.long	0x17e35a96
	.long	0x2b2b5aa3
	.long	0x456f5aaf
	.long	0x00005ac0
	.long	0x43955ad4
	.long	0xc15a5ae6
	.long	0xdef65af7
	.long	0xc3b65b07
	.long	0x17e35b16
	.long	0x2b2b5b23
	.long	0x456f5b2f
	.long	0x00005b40
	.long	0x43955b54
	.long	0xc15a5b66
	.long	0xdef65b77
	.long	0xc3b65b87
	.long	0x17e35b96
	.long	0x2b2b5ba3
	.long	0x456f5baf
	.long	0x00005bc0
	.long	0x43955bd4
	.long	0xc15a5be6
	.long	0xdef65bf7
	.long	0xc3b65c07
	.long	0x17e35c16
	.long	0x2b2b5c23
	.long	0x456f5c2f
	.long	0x00005c40
	.long	0x43955c54
	.long	0xc15a5c66
	.long	0xdef65c77
	.long	0xc3b65c87
	.long	0x17e35c96
	.long	0x2b2b5ca3
	.long	0x456f5caf
	.long	0x00005cc0
	.long	0x43955cd4
	.long	0xc15a5ce6
	.long	0xdef65cf7
	.long	0xc3b65d07
	.long	0x17e35d16
	.long	0x2b2b5d23
	.long	0x456f5d2f
	.long	0x00005d40
	.long	0x43955d54
	.long	0xc15a5d66
	.long	0xdef65d77
	.long	0xc3b65d87
	.long	0x17e35d96
	.long	0x2b2b5da3
	.long	0x456f5daf
	.long	0x00005dc0
	.long	0x43955dd4
	.long	0xc15a5de6
	.long	0xdef65df7
	.long	0xc3b65e07
	.long	0x17e35e16
	.long	0x2b2b5e23
	.long	0x456f5e2f
	.long	0x00005e40
	.long	0x43955e54
	.long	0xc15a5e66
	.long	0xdef65e77
	.long	0xc3b65e87
	.long	0x17e35e96
	.long	0x2b2b5ea3
	.long	0x456f5eaf
	.long	0x00005ec0
	.long	0x43955ed4
	.long	0xc15a5ee6
	.long	0xdef65ef7
	.long	0xc3b65f07
	.long	0x17e35f16
	.long	0x2b2b5f23
	.long	0x456f5f2f
	.long	0x00005f40
	.long	0x43955f54
	.long	0xc15a5f66
	.long	0xdef65f77
	.long	0xc3b65f87
	.long	0x17e35f96
	.long	0x2b2b5fa3
	.long	0x456f5faf
	.long	0x00005fc0
	.long	0x43955fd4
	.long	0xc15a5fe6
	.long	0xdef65ff7
	.long	0xc3b66007
	.long	0x17e36016
	.long	0x2b2b6023
	.long	0x456f602f
