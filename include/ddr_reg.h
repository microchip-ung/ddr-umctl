/*
 * Copyright (C) 2021 Microchip Technology Inc. and its subsidiaries.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __DDR_REG_H
#define __DDR_REG_H

#include <stdint.h>

#define DDR_PHY_RIDR             0x600108000
#define DDR_PHY_PIR              0x600108004
#define DDR_PHY_CGCR             0x600108008
#define DDR_PHY_CGCR1            0x60010800c
#define DDR_PHY_PGCR0            0x600108010
#define DDR_PHY_PGCR1            0x600108014
#define DDR_PHY_PGCR2            0x600108018
#define DDR_PHY_PGCR3            0x60010801c
#define DDR_PHY_PGCR4            0x600108020
#define DDR_PHY_PGCR5            0x600108024
#define DDR_PHY_PGCR6            0x600108028
#define DDR_PHY_PGCR7            0x60010802c
#define DDR_PHY_PGCR8            0x600108030
#define DDR_PHY_PGSR0            0x600108034
#define DDR_PHY_PGSR1            0x600108038
#define DDR_PHY_PTR0             0x600108040
#define DDR_PHY_PTR1             0x600108044
#define DDR_PHY_PTR2             0x600108048
#define DDR_PHY_PTR3             0x60010804c
#define DDR_PHY_PTR4             0x600108050
#define DDR_PHY_PTR5             0x600108054
#define DDR_PHY_PTR6             0x600108058
#define DDR_PHY_PLLCR0           0x600108068
#define DDR_PHY_PLLCR1           0x60010806c
#define DDR_PHY_PLLCR2           0x600108070
#define DDR_PHY_PLLCR3           0x600108074
#define DDR_PHY_PLLCR4           0x600108078
#define DDR_PHY_PLLCR5           0x60010807c
#define DDR_PHY_PLLCR            0x600108080
#define DDR_PHY_DXCCR            0x600108088
#define DDR_PHY_DSGCR            0x600108090
#define DDR_PHY_ODTCR            0x600108098
#define DDR_PHY_AACR             0x6001080a0
#define DDR_PHY_GPR0             0x6001080c0
#define DDR_PHY_GPR1             0x6001080c4
#define DDR_PHY_DCR              0x600108100
#define DDR_PHY_DTPR0            0x600108110
#define DDR_PHY_DTPR1            0x600108114
#define DDR_PHY_DTPR2            0x600108118
#define DDR_PHY_DTPR3            0x60010811c
#define DDR_PHY_DTPR4            0x600108120
#define DDR_PHY_DTPR5            0x600108124
#define DDR_PHY_DTPR6            0x600108128
#define DDR_PHY_RDIMMGCR0        0x600108140
#define DDR_PHY_RDIMMGCR1        0x600108144
#define DDR_PHY_RDIMMGCR2        0x600108148
#define DDR_PHY_RDIMMCR0         0x600108150
#define DDR_PHY_RDIMMCR0_DDR4    0x600108150
#define DDR_PHY_RDIMMCR1         0x600108154
#define DDR_PHY_RDIMMCR1_DDR4    0x600108154
#define DDR_PHY_RDIMMCR2         0x600108158
#define DDR_PHY_RDIMMCR3         0x60010815c
#define DDR_PHY_RDIMMCR4         0x600108160
#define DDR_PHY_SCHCR0           0x600108168
#define DDR_PHY_SCHCR1           0x60010816c
#define DDR_PHY_MR0              0x600108180
#define DDR_PHY_MR0_DDR4         0x600108180
#define DDR_PHY_MR0_LPDDR2       0x600108180
#define DDR_PHY_MR0_LPDDR3       0x600108180
#define DDR_PHY_MR1              0x600108184
#define DDR_PHY_MR1_DDR4         0x600108184
#define DDR_PHY_MR1_LPDDR2       0x600108184
#define DDR_PHY_MR1_LPDDR3       0x600108184
#define DDR_PHY_MR2              0x600108188
#define DDR_PHY_MR2_DDR4         0x600108188
#define DDR_PHY_MR2_LPDDR2       0x600108188
#define DDR_PHY_MR2_LPDDR3       0x600108188
#define DDR_PHY_MR3              0x60010818c
#define DDR_PHY_MR3_DDR4         0x60010818c
#define DDR_PHY_MR3_LPDDR2       0x60010818c
#define DDR_PHY_MR3_LPDDR3       0x60010818c
#define DDR_PHY_MR4              0x600108190
#define DDR_PHY_MR4_DDR4         0x600108190
#define DDR_PHY_MR4_LPDDR2       0x600108190
#define DDR_PHY_MR4_LPDDR3       0x600108190
#define DDR_PHY_MR5              0x600108194
#define DDR_PHY_MR5_DDR4         0x600108194
#define DDR_PHY_MR5_LPDDR2       0x600108194
#define DDR_PHY_MR5_LPDDR3       0x600108194
#define DDR_PHY_MR6              0x600108198
#define DDR_PHY_MR6_DDR4         0x600108198
#define DDR_PHY_MR6_LPDDR2       0x600108198
#define DDR_PHY_MR6_LPDDR3       0x600108198
#define DDR_PHY_MR7              0x60010819c
#define DDR_PHY_MR7_DDR4         0x60010819c
#define DDR_PHY_MR7_LPDDR2       0x60010819c
#define DDR_PHY_MR7_LPDDR3       0x60010819c
#define DDR_PHY_MR11             0x6001081ac
#define DDR_PHY_MR11_DDR4        0x6001081ac
#define DDR_PHY_MR11_LPDDR2      0x6001081ac
#define DDR_PHY_MR11_LPDDR3      0x6001081ac
#define DDR_PHY_DTCR0            0x600108200
#define DDR_PHY_DTCR1            0x600108204
#define DDR_PHY_DTAR0            0x600108208
#define DDR_PHY_DTAR1            0x60010820c
#define DDR_PHY_DTAR2            0x600108210
#define DDR_PHY_DTDR0            0x600108218
#define DDR_PHY_DTDR1            0x60010821c
#define DDR_PHY_UDDR0            0x600108220
#define DDR_PHY_UDDR1            0x600108224
#define DDR_PHY_DTEDR0           0x600108230
#define DDR_PHY_DTEDR1           0x600108234
#define DDR_PHY_DTEDR2           0x600108238
#define DDR_PHY_VTDR             0x60010823c
#define DDR_PHY_CATR0            0x600108240
#define DDR_PHY_CATR1            0x600108244
#define DDR_PHY_DQSDR0           0x600108250
#define DDR_PHY_DQSDR1           0x600108254
#define DDR_PHY_DQSDR2           0x600108258
#define DDR_PHY_DCUAR            0x600108300
#define DDR_PHY_DCUDR            0x600108304
#define DDR_PHY_DCURR            0x600108308
#define DDR_PHY_DCULR            0x60010830c
#define DDR_PHY_DCUGCR           0x600108310
#define DDR_PHY_DCUTPR           0x600108314
#define DDR_PHY_DCUSR0           0x600108318
#define DDR_PHY_DCUSR1           0x60010831c
#define DDR_PHY_BISTRR           0x600108400
#define DDR_PHY_BISTWCR          0x600108404
#define DDR_PHY_BISTMSKR0        0x600108408
#define DDR_PHY_BISTMSKR1        0x60010840c
#define DDR_PHY_BISTMSKR2        0x600108410
#define DDR_PHY_BISTLSR          0x600108414
#define DDR_PHY_BISTAR0          0x600108418
#define DDR_PHY_BISTAR1          0x60010841c
#define DDR_PHY_BISTAR2          0x600108420
#define DDR_PHY_BISTAR3          0x600108424
#define DDR_PHY_BISTAR4          0x600108428
#define DDR_PHY_BISTUDPR         0x60010842c
#define DDR_PHY_BISTGSR          0x600108430
#define DDR_PHY_BISTWER0         0x600108434
#define DDR_PHY_BISTWER1         0x600108438
#define DDR_PHY_BISTBER0         0x60010843c
#define DDR_PHY_BISTBER1         0x600108440
#define DDR_PHY_BISTBER2         0x600108444
#define DDR_PHY_BISTBER3         0x600108448
#define DDR_PHY_BISTBER4         0x60010844c
#define DDR_PHY_BISTWCSR         0x600108450
#define DDR_PHY_BISTFWR0         0x600108454
#define DDR_PHY_BISTFWR1         0x600108458
#define DDR_PHY_BISTFWR2         0x60010845c
#define DDR_PHY_BISTBER5         0x600108460
#define DDR_PHY_RANKIDR          0x6001084dc
#define DDR_PHY_RIOCR0           0x6001084e0
#define DDR_PHY_RIOCR1           0x6001084e4
#define DDR_PHY_RIOCR2           0x6001084e8
#define DDR_PHY_RIOCR3           0x6001084ec
#define DDR_PHY_RIOCR4           0x6001084f0
#define DDR_PHY_RIOCR5           0x6001084f4
#define DDR_PHY_ACIOCR0          0x600108500
#define DDR_PHY_ACIOCR1          0x600108504
#define DDR_PHY_ACIOCR2          0x600108508
#define DDR_PHY_ACIOCR3          0x60010850c
#define DDR_PHY_ACIOCR4          0x600108510
#define DDR_PHY_IOVCR0           0x600108520
#define DDR_PHY_IOVCR1           0x600108524
#define DDR_PHY_VTCR0            0x600108528
#define DDR_PHY_VTCR1            0x60010852c
#define DDR_PHY_ACBDLR0          0x600108540
#define DDR_PHY_ACBDLR1          0x600108544
#define DDR_PHY_ACBDLR2          0x600108548
#define DDR_PHY_ACBDLR3          0x60010854c
#define DDR_PHY_ACBDLR4          0x600108550
#define DDR_PHY_ACBDLR5          0x600108554
#define DDR_PHY_ACBDLR6          0x600108558
#define DDR_PHY_ACBDLR7          0x60010855c
#define DDR_PHY_ACBDLR8          0x600108560
#define DDR_PHY_ACBDLR9          0x600108564
#define DDR_PHY_ACBDLR10         0x600108568
#define DDR_PHY_ACBDLR11         0x60010856c
#define DDR_PHY_ACBDLR12         0x600108570
#define DDR_PHY_ACBDLR13         0x600108574
#define DDR_PHY_ACBDLR14         0x600108578
#define DDR_PHY_ACLCDLR          0x600108580
#define DDR_PHY_ACMDLR0          0x6001085a0
#define DDR_PHY_ACMDLR1          0x6001085a4
#define DDR_PHY_ZQCR             0x600108680
#define DDR_PHY_ZQ0PR            0x600108684
#define DDR_PHY_ZQ0DR            0x600108688
#define DDR_PHY_ZQ0SR            0x60010868c
#define DDR_PHY_ZQ1PR            0x600108694
#define DDR_PHY_ZQ1DR            0x600108698
#define DDR_PHY_ZQ1SR            0x60010869c
#define DDR_PHY_ZQ2PR            0x6001086a4
#define DDR_PHY_ZQ2DR            0x6001086a8
#define DDR_PHY_ZQ2SR            0x6001086ac
#define DDR_PHY_ZQ3PR            0x6001086b4
#define DDR_PHY_ZQ3DR            0x6001086b8
#define DDR_PHY_ZQ3SR            0x6001086bc
#define DDR_PHY_DX0GCR0          0x600108700
#define DDR_PHY_DX0GCR1          0x600108704
#define DDR_PHY_DX0GCR2          0x600108708
#define DDR_PHY_DX0GCR3          0x60010870c
#define DDR_PHY_DX0GCR4          0x600108710
#define DDR_PHY_DX0GCR5          0x600108714
#define DDR_PHY_DX0GCR6          0x600108718
#define DDR_PHY_DX0GCR7          0x60010871c
#define DDR_PHY_DX0GCR8          0x600108720
#define DDR_PHY_DX0GCR9          0x600108724
#define DDR_PHY_DX0BDLR0         0x600108740
#define DDR_PHY_DX0BDLR1         0x600108744
#define DDR_PHY_DX0BDLR2         0x600108748
#define DDR_PHY_DX0BDLR3         0x600108750
#define DDR_PHY_DX0BDLR4         0x600108754
#define DDR_PHY_DX0BDLR5         0x600108758
#define DDR_PHY_DX0BDLR6         0x600108760
#define DDR_PHY_DX0BDLR7         0x600108764
#define DDR_PHY_DX0BDLR8         0x600108768
#define DDR_PHY_DX0BDLR9         0x60010876c
#define DDR_PHY_DX0LCDLR0        0x600108780
#define DDR_PHY_DX0LCDLR1        0x600108784
#define DDR_PHY_DX0LCDLR2        0x600108788
#define DDR_PHY_DX0LCDLR3        0x60010878c
#define DDR_PHY_DX0LCDLR4        0x600108790
#define DDR_PHY_DX0LCDLR5        0x600108794
#define DDR_PHY_DX0MDLR0         0x6001087a0
#define DDR_PHY_DX0MDLR1         0x6001087a4
#define DDR_PHY_DX0GTR0          0x6001087c0
#define DDR_PHY_DX0RSR0          0x6001087d0
#define DDR_PHY_DX0RSR1          0x6001087d4
#define DDR_PHY_DX0RSR2          0x6001087d8
#define DDR_PHY_DX0RSR3          0x6001087dc
#define DDR_PHY_DX0GSR0          0x6001087e0
#define DDR_PHY_DX0GSR1          0x6001087e4
#define DDR_PHY_DX0GSR2          0x6001087e8
#define DDR_PHY_DX0GSR3          0x6001087ec
#define DDR_PHY_DX0GSR4          0x6001087f0
#define DDR_PHY_DX0GSR5          0x6001087f4
#define DDR_PHY_DX0GSR6          0x6001087f8
#define DDR_PHY_DX1GCR0          0x600108800
#define DDR_PHY_DX1GCR1          0x600108804
#define DDR_PHY_DX1GCR2          0x600108808
#define DDR_PHY_DX1GCR3          0x60010880c
#define DDR_PHY_DX1GCR4          0x600108810
#define DDR_PHY_DX1GCR5          0x600108814
#define DDR_PHY_DX1GCR6          0x600108818
#define DDR_PHY_DX1GCR7          0x60010881c
#define DDR_PHY_DX1GCR8          0x600108820
#define DDR_PHY_DX1GCR9          0x600108824
#define DDR_PHY_DX1BDLR0         0x600108840
#define DDR_PHY_DX1BDLR1         0x600108844
#define DDR_PHY_DX1BDLR2         0x600108848
#define DDR_PHY_DX1BDLR3         0x600108850
#define DDR_PHY_DX1BDLR4         0x600108854
#define DDR_PHY_DX1BDLR5         0x600108858
#define DDR_PHY_DX1BDLR6         0x600108860
#define DDR_PHY_DX1BDLR7         0x600108864
#define DDR_PHY_DX1BDLR8         0x600108868
#define DDR_PHY_DX1BDLR9         0x60010886c
#define DDR_PHY_DX1LCDLR0        0x600108880
#define DDR_PHY_DX1LCDLR1        0x600108884
#define DDR_PHY_DX1LCDLR2        0x600108888
#define DDR_PHY_DX1LCDLR3        0x60010888c
#define DDR_PHY_DX1LCDLR4        0x600108890
#define DDR_PHY_DX1LCDLR5        0x600108894
#define DDR_PHY_DX1MDLR0         0x6001088a0
#define DDR_PHY_DX1MDLR1         0x6001088a4
#define DDR_PHY_DX1GTR0          0x6001088c0
#define DDR_PHY_DX1RSR0          0x6001088d0
#define DDR_PHY_DX1RSR1          0x6001088d4
#define DDR_PHY_DX1RSR2          0x6001088d8
#define DDR_PHY_DX1RSR3          0x6001088dc
#define DDR_PHY_DX1GSR0          0x6001088e0
#define DDR_PHY_DX1GSR1          0x6001088e4
#define DDR_PHY_DX1GSR2          0x6001088e8
#define DDR_PHY_DX1GSR3          0x6001088ec
#define DDR_PHY_DX1GSR4          0x6001088f0
#define DDR_PHY_DX1GSR5          0x6001088f4
#define DDR_PHY_DX1GSR6          0x6001088f8
#define DDR_PHY_DX2GCR0          0x600108900
#define DDR_PHY_DX2GCR1          0x600108904
#define DDR_PHY_DX2GCR2          0x600108908
#define DDR_PHY_DX2GCR3          0x60010890c
#define DDR_PHY_DX2GCR4          0x600108910
#define DDR_PHY_DX2GCR5          0x600108914
#define DDR_PHY_DX2GCR6          0x600108918
#define DDR_PHY_DX2GCR7          0x60010891c
#define DDR_PHY_DX2GCR8          0x600108920
#define DDR_PHY_DX2GCR9          0x600108924
#define DDR_PHY_DX2BDLR0         0x600108940
#define DDR_PHY_DX2BDLR1         0x600108944
#define DDR_PHY_DX2BDLR2         0x600108948
#define DDR_PHY_DX2BDLR3         0x600108950
#define DDR_PHY_DX2BDLR4         0x600108954
#define DDR_PHY_DX2BDLR5         0x600108958
#define DDR_PHY_DX2BDLR6         0x600108960
#define DDR_PHY_DX2BDLR7         0x600108964
#define DDR_PHY_DX2BDLR8         0x600108968
#define DDR_PHY_DX2BDLR9         0x60010896c
#define DDR_PHY_DX2LCDLR0        0x600108980
#define DDR_PHY_DX2LCDLR1        0x600108984
#define DDR_PHY_DX2LCDLR2        0x600108988
#define DDR_PHY_DX2LCDLR3        0x60010898c
#define DDR_PHY_DX2LCDLR4        0x600108990
#define DDR_PHY_DX2LCDLR5        0x600108994
#define DDR_PHY_DX2MDLR0         0x6001089a0
#define DDR_PHY_DX2MDLR1         0x6001089a4
#define DDR_PHY_DX2GTR0          0x6001089c0
#define DDR_PHY_DX2RSR0          0x6001089d0
#define DDR_PHY_DX2RSR1          0x6001089d4
#define DDR_PHY_DX2RSR2          0x6001089d8
#define DDR_PHY_DX2RSR3          0x6001089dc
#define DDR_PHY_DX2GSR0          0x6001089e0
#define DDR_PHY_DX2GSR1          0x6001089e4
#define DDR_PHY_DX2GSR2          0x6001089e8
#define DDR_PHY_DX2GSR3          0x6001089ec
#define DDR_PHY_DX2GSR4          0x6001089f0
#define DDR_PHY_DX2GSR5          0x6001089f4
#define DDR_PHY_DX2GSR6          0x6001089f8
#define DDR_PHY_DX3GCR0          0x600108a00
#define DDR_PHY_DX3GCR1          0x600108a04
#define DDR_PHY_DX3GCR2          0x600108a08
#define DDR_PHY_DX3GCR3          0x600108a0c
#define DDR_PHY_DX3GCR4          0x600108a10
#define DDR_PHY_DX3GCR5          0x600108a14
#define DDR_PHY_DX3GCR6          0x600108a18
#define DDR_PHY_DX3GCR7          0x600108a1c
#define DDR_PHY_DX3GCR8          0x600108a20
#define DDR_PHY_DX3GCR9          0x600108a24
#define DDR_PHY_DX3BDLR0         0x600108a40
#define DDR_PHY_DX3BDLR1         0x600108a44
#define DDR_PHY_DX3BDLR2         0x600108a48
#define DDR_PHY_DX3BDLR3         0x600108a50
#define DDR_PHY_DX3BDLR4         0x600108a54
#define DDR_PHY_DX3BDLR5         0x600108a58
#define DDR_PHY_DX3BDLR6         0x600108a60
#define DDR_PHY_DX3BDLR7         0x600108a64
#define DDR_PHY_DX3BDLR8         0x600108a68
#define DDR_PHY_DX3BDLR9         0x600108a6c
#define DDR_PHY_DX3LCDLR0        0x600108a80
#define DDR_PHY_DX3LCDLR1        0x600108a84
#define DDR_PHY_DX3LCDLR2        0x600108a88
#define DDR_PHY_DX3LCDLR3        0x600108a8c
#define DDR_PHY_DX3LCDLR4        0x600108a90
#define DDR_PHY_DX3LCDLR5        0x600108a94
#define DDR_PHY_DX3MDLR0         0x600108aa0
#define DDR_PHY_DX3MDLR1         0x600108aa4
#define DDR_PHY_DX3GTR0          0x600108ac0
#define DDR_PHY_DX3RSR0          0x600108ad0
#define DDR_PHY_DX3RSR1          0x600108ad4
#define DDR_PHY_DX3RSR2          0x600108ad8
#define DDR_PHY_DX3RSR3          0x600108adc
#define DDR_PHY_DX3GSR0          0x600108ae0
#define DDR_PHY_DX3GSR1          0x600108ae4
#define DDR_PHY_DX3GSR2          0x600108ae8
#define DDR_PHY_DX3GSR3          0x600108aec
#define DDR_PHY_DX3GSR4          0x600108af0
#define DDR_PHY_DX3GSR5          0x600108af4
#define DDR_PHY_DX3GSR6          0x600108af8
#define DDR_PHY_DX4GCR0          0x600108b00
#define DDR_PHY_DX4GCR1          0x600108b04
#define DDR_PHY_DX4GCR2          0x600108b08
#define DDR_PHY_DX4GCR3          0x600108b0c
#define DDR_PHY_DX4GCR4          0x600108b10
#define DDR_PHY_DX4GCR5          0x600108b14
#define DDR_PHY_DX4GCR6          0x600108b18
#define DDR_PHY_DX4GCR7          0x600108b1c
#define DDR_PHY_DX4GCR8          0x600108b20
#define DDR_PHY_DX4GCR9          0x600108b24
#define DDR_PHY_DX4BDLR0         0x600108b40
#define DDR_PHY_DX4BDLR1         0x600108b44
#define DDR_PHY_DX4BDLR2         0x600108b48
#define DDR_PHY_DX4BDLR3         0x600108b50
#define DDR_PHY_DX4BDLR4         0x600108b54
#define DDR_PHY_DX4BDLR5         0x600108b58
#define DDR_PHY_DX4BDLR6         0x600108b60
#define DDR_PHY_DX4BDLR7         0x600108b64
#define DDR_PHY_DX4BDLR8         0x600108b68
#define DDR_PHY_DX4BDLR9         0x600108b6c
#define DDR_PHY_DX4LCDLR0        0x600108b80
#define DDR_PHY_DX4LCDLR1        0x600108b84
#define DDR_PHY_DX4LCDLR2        0x600108b88
#define DDR_PHY_DX4LCDLR3        0x600108b8c
#define DDR_PHY_DX4LCDLR4        0x600108b90
#define DDR_PHY_DX4LCDLR5        0x600108b94
#define DDR_PHY_DX4MDLR0         0x600108ba0
#define DDR_PHY_DX4MDLR1         0x600108ba4
#define DDR_PHY_DX4GTR0          0x600108bc0
#define DDR_PHY_DX4RSR0          0x600108bd0
#define DDR_PHY_DX4RSR1          0x600108bd4
#define DDR_PHY_DX4RSR2          0x600108bd8
#define DDR_PHY_DX4RSR3          0x600108bdc
#define DDR_PHY_DX4GSR0          0x600108be0
#define DDR_PHY_DX4GSR1          0x600108be4
#define DDR_PHY_DX4GSR2          0x600108be8
#define DDR_PHY_DX4GSR3          0x600108bec
#define DDR_PHY_DX4GSR4          0x600108bf0
#define DDR_PHY_DX4GSR5          0x600108bf4
#define DDR_PHY_DX4GSR6          0x600108bf8
#define DDR_PHY_DX5GCR0          0x600108c00
#define DDR_PHY_DX5GCR1          0x600108c04
#define DDR_PHY_DX5GCR2          0x600108c08
#define DDR_PHY_DX5GCR3          0x600108c0c
#define DDR_PHY_DX5GCR4          0x600108c10
#define DDR_PHY_DX5GCR5          0x600108c14
#define DDR_PHY_DX5GCR6          0x600108c18
#define DDR_PHY_DX5GCR7          0x600108c1c
#define DDR_PHY_DX5GCR8          0x600108c20
#define DDR_PHY_DX5GCR9          0x600108c24
#define DDR_PHY_DX5BDLR0         0x600108c40
#define DDR_PHY_DX5BDLR1         0x600108c44
#define DDR_PHY_DX5BDLR2         0x600108c48
#define DDR_PHY_DX5BDLR3         0x600108c50
#define DDR_PHY_DX5BDLR4         0x600108c54
#define DDR_PHY_DX5BDLR5         0x600108c58
#define DDR_PHY_DX5BDLR6         0x600108c60
#define DDR_PHY_DX5BDLR7         0x600108c64
#define DDR_PHY_DX5BDLR8         0x600108c68
#define DDR_PHY_DX5BDLR9         0x600108c6c
#define DDR_PHY_DX5LCDLR0        0x600108c80
#define DDR_PHY_DX5LCDLR1        0x600108c84
#define DDR_PHY_DX5LCDLR2        0x600108c88
#define DDR_PHY_DX5LCDLR3        0x600108c8c
#define DDR_PHY_DX5LCDLR4        0x600108c90
#define DDR_PHY_DX5LCDLR5        0x600108c94
#define DDR_PHY_DX5MDLR0         0x600108ca0
#define DDR_PHY_DX5MDLR1         0x600108ca4
#define DDR_PHY_DX5GTR0          0x600108cc0
#define DDR_PHY_DX5RSR0          0x600108cd0
#define DDR_PHY_DX5RSR1          0x600108cd4
#define DDR_PHY_DX5RSR2          0x600108cd8
#define DDR_PHY_DX5RSR3          0x600108cdc
#define DDR_PHY_DX5GSR0          0x600108ce0
#define DDR_PHY_DX5GSR1          0x600108ce4
#define DDR_PHY_DX5GSR2          0x600108ce8
#define DDR_PHY_DX5GSR3          0x600108cec
#define DDR_PHY_DX5GSR4          0x600108cf0
#define DDR_PHY_DX5GSR5          0x600108cf4
#define DDR_PHY_DX5GSR6          0x600108cf8
#define DDR_PHY_DX6GCR0          0x600108d00
#define DDR_PHY_DX6GCR1          0x600108d04
#define DDR_PHY_DX6GCR2          0x600108d08
#define DDR_PHY_DX6GCR3          0x600108d0c
#define DDR_PHY_DX6GCR4          0x600108d10
#define DDR_PHY_DX6GCR5          0x600108d14
#define DDR_PHY_DX6GCR6          0x600108d18
#define DDR_PHY_DX6GCR7          0x600108d1c
#define DDR_PHY_DX6GCR8          0x600108d20
#define DDR_PHY_DX6GCR9          0x600108d24
#define DDR_PHY_DX6BDLR0         0x600108d40
#define DDR_PHY_DX6BDLR1         0x600108d44
#define DDR_PHY_DX6BDLR2         0x600108d48
#define DDR_PHY_DX6BDLR3         0x600108d50
#define DDR_PHY_DX6BDLR4         0x600108d54
#define DDR_PHY_DX6BDLR5         0x600108d58
#define DDR_PHY_DX6BDLR6         0x600108d60
#define DDR_PHY_DX6BDLR7         0x600108d64
#define DDR_PHY_DX6BDLR8         0x600108d68
#define DDR_PHY_DX6BDLR9         0x600108d6c
#define DDR_PHY_DX6LCDLR0        0x600108d80
#define DDR_PHY_DX6LCDLR1        0x600108d84
#define DDR_PHY_DX6LCDLR2        0x600108d88
#define DDR_PHY_DX6LCDLR3        0x600108d8c
#define DDR_PHY_DX6LCDLR4        0x600108d90
#define DDR_PHY_DX6LCDLR5        0x600108d94
#define DDR_PHY_DX6MDLR0         0x600108da0
#define DDR_PHY_DX6MDLR1         0x600108da4
#define DDR_PHY_DX6GTR0          0x600108dc0
#define DDR_PHY_DX6RSR0          0x600108dd0
#define DDR_PHY_DX6RSR1          0x600108dd4
#define DDR_PHY_DX6RSR2          0x600108dd8
#define DDR_PHY_DX6RSR3          0x600108ddc
#define DDR_PHY_DX6GSR0          0x600108de0
#define DDR_PHY_DX6GSR1          0x600108de4
#define DDR_PHY_DX6GSR2          0x600108de8
#define DDR_PHY_DX6GSR3          0x600108dec
#define DDR_PHY_DX6GSR4          0x600108df0
#define DDR_PHY_DX6GSR5          0x600108df4
#define DDR_PHY_DX6GSR6          0x600108df8
#define DDR_PHY_DX7GCR0          0x600108e00
#define DDR_PHY_DX7GCR1          0x600108e04
#define DDR_PHY_DX7GCR2          0x600108e08
#define DDR_PHY_DX7GCR3          0x600108e0c
#define DDR_PHY_DX7GCR4          0x600108e10
#define DDR_PHY_DX7GCR5          0x600108e14
#define DDR_PHY_DX7GCR6          0x600108e18
#define DDR_PHY_DX7GCR7          0x600108e1c
#define DDR_PHY_DX7GCR8          0x600108e20
#define DDR_PHY_DX7GCR9          0x600108e24
#define DDR_PHY_DX7BDLR0         0x600108e40
#define DDR_PHY_DX7BDLR1         0x600108e44
#define DDR_PHY_DX7BDLR2         0x600108e48
#define DDR_PHY_DX7BDLR3         0x600108e50
#define DDR_PHY_DX7BDLR4         0x600108e54
#define DDR_PHY_DX7BDLR5         0x600108e58
#define DDR_PHY_DX7BDLR6         0x600108e60
#define DDR_PHY_DX7BDLR7         0x600108e64
#define DDR_PHY_DX7BDLR8         0x600108e68
#define DDR_PHY_DX7BDLR9         0x600108e6c
#define DDR_PHY_DX7LCDLR0        0x600108e80
#define DDR_PHY_DX7LCDLR1        0x600108e84
#define DDR_PHY_DX7LCDLR2        0x600108e88
#define DDR_PHY_DX7LCDLR3        0x600108e8c
#define DDR_PHY_DX7LCDLR4        0x600108e90
#define DDR_PHY_DX7LCDLR5        0x600108e94
#define DDR_PHY_DX7MDLR0         0x600108ea0
#define DDR_PHY_DX7MDLR1         0x600108ea4
#define DDR_PHY_DX7GTR0          0x600108ec0
#define DDR_PHY_DX7RSR0          0x600108ed0
#define DDR_PHY_DX7RSR1          0x600108ed4
#define DDR_PHY_DX7RSR2          0x600108ed8
#define DDR_PHY_DX7RSR3          0x600108edc
#define DDR_PHY_DX7GSR0          0x600108ee0
#define DDR_PHY_DX7GSR1          0x600108ee4
#define DDR_PHY_DX7GSR2          0x600108ee8
#define DDR_PHY_DX7GSR3          0x600108eec
#define DDR_PHY_DX7GSR4          0x600108ef0
#define DDR_PHY_DX7GSR5          0x600108ef4
#define DDR_PHY_DX7GSR6          0x600108ef8
#define DDR_PHY_DX8GCR0          0x600108f00
#define DDR_PHY_DX8GCR1          0x600108f04
#define DDR_PHY_DX8GCR2          0x600108f08
#define DDR_PHY_DX8GCR3          0x600108f0c
#define DDR_PHY_DX8GCR4          0x600108f10
#define DDR_PHY_DX8GCR5          0x600108f14
#define DDR_PHY_DX8GCR6          0x600108f18
#define DDR_PHY_DX8GCR7          0x600108f1c
#define DDR_PHY_DX8GCR8          0x600108f20
#define DDR_PHY_DX8GCR9          0x600108f24
#define DDR_PHY_DX8BDLR0         0x600108f40
#define DDR_PHY_DX8BDLR1         0x600108f44
#define DDR_PHY_DX8BDLR2         0x600108f48
#define DDR_PHY_DX8BDLR3         0x600108f50
#define DDR_PHY_DX8BDLR4         0x600108f54
#define DDR_PHY_DX8BDLR5         0x600108f58
#define DDR_PHY_DX8BDLR6         0x600108f60
#define DDR_PHY_DX8BDLR7         0x600108f64
#define DDR_PHY_DX8BDLR8         0x600108f68
#define DDR_PHY_DX8BDLR9         0x600108f6c
#define DDR_PHY_DX8LCDLR0        0x600108f80
#define DDR_PHY_DX8LCDLR1        0x600108f84
#define DDR_PHY_DX8LCDLR2        0x600108f88
#define DDR_PHY_DX8LCDLR3        0x600108f8c
#define DDR_PHY_DX8LCDLR4        0x600108f90
#define DDR_PHY_DX8LCDLR5        0x600108f94
#define DDR_PHY_DX8MDLR0         0x600108fa0
#define DDR_PHY_DX8MDLR1         0x600108fa4
#define DDR_PHY_DX8GTR0          0x600108fc0
#define DDR_PHY_DX8RSR0          0x600108fd0
#define DDR_PHY_DX8RSR1          0x600108fd4
#define DDR_PHY_DX8RSR2          0x600108fd8
#define DDR_PHY_DX8RSR3          0x600108fdc
#define DDR_PHY_DX8GSR0          0x600108fe0
#define DDR_PHY_DX8GSR1          0x600108fe4
#define DDR_PHY_DX8GSR2          0x600108fe8
#define DDR_PHY_DX8GSR3          0x600108fec
#define DDR_PHY_DX8GSR4          0x600108ff0
#define DDR_PHY_DX8GSR5          0x600108ff4
#define DDR_PHY_DX8GSR6          0x600108ff8
#define DDR_UMCTL2_MSTR          0x600107000
#define DDR_UMCTL2_STAT          0x600107004
#define DDR_UMCTL2_MRCTRL0       0x600107010
#define DDR_UMCTL2_MRCTRL1       0x600107014
#define DDR_UMCTL2_MRSTAT        0x600107018
#define DDR_UMCTL2_MRCTRL2       0x60010701c
#define DDR_UMCTL2_DERATEEN      0x600107020
#define DDR_UMCTL2_DERATEINT     0x600107024
#define DDR_UMCTL2_PWRCTL        0x600107030
#define DDR_UMCTL2_PWRTMG        0x600107034
#define DDR_UMCTL2_HWLPCTL       0x600107038
#define DDR_UMCTL2_RFSHCTL0      0x600107050
#define DDR_UMCTL2_RFSHCTL1      0x600107054
#define DDR_UMCTL2_RFSHCTL3      0x600107060
#define DDR_UMCTL2_RFSHTMG       0x600107064
#define DDR_UMCTL2_ECCCFG0       0x600107070
#define DDR_UMCTL2_ECCCFG1       0x600107074
#define DDR_UMCTL2_ECCSTAT       0x600107078
#define DDR_UMCTL2_ECCCLR        0x60010707c
#define DDR_UMCTL2_ECCERRCNT     0x600107080
#define DDR_UMCTL2_ECCCADDR0     0x600107084
#define DDR_UMCTL2_ECCCADDR1     0x600107088
#define DDR_UMCTL2_ECCCSYN0      0x60010708c
#define DDR_UMCTL2_ECCCSYN2      0x600107094
#define DDR_UMCTL2_ECCBITMASK0   0x600107098
#define DDR_UMCTL2_ECCBITMASK2   0x6001070a0
#define DDR_UMCTL2_ECCUADDR0     0x6001070a4
#define DDR_UMCTL2_ECCUADDR1     0x6001070a8
#define DDR_UMCTL2_ECCUSYN0      0x6001070ac
#define DDR_UMCTL2_ECCUSYN2      0x6001070b4
#define DDR_UMCTL2_ECCPOISONADDR0 0x6001070b8
#define DDR_UMCTL2_ECCPOISONADDR1 0x6001070bc
#define DDR_UMCTL2_CRCPARCTL0    0x6001070c0
#define DDR_UMCTL2_CRCPARCTL1    0x6001070c4
#define DDR_UMCTL2_CRCPARSTAT    0x6001070cc
#define DDR_UMCTL2_INIT0         0x6001070d0
#define DDR_UMCTL2_INIT1         0x6001070d4
#define DDR_UMCTL2_INIT2         0x6001070d8
#define DDR_UMCTL2_INIT3         0x6001070dc
#define DDR_UMCTL2_INIT4         0x6001070e0
#define DDR_UMCTL2_INIT5         0x6001070e4
#define DDR_UMCTL2_INIT6         0x6001070e8
#define DDR_UMCTL2_INIT7         0x6001070ec
#define DDR_UMCTL2_DIMMCTL       0x6001070f0
#define DDR_UMCTL2_RANKCTL       0x6001070f4
#define DDR_UMCTL2_DRAMTMG0      0x600107100
#define DDR_UMCTL2_DRAMTMG1      0x600107104
#define DDR_UMCTL2_DRAMTMG2      0x600107108
#define DDR_UMCTL2_DRAMTMG3      0x60010710c
#define DDR_UMCTL2_DRAMTMG4      0x600107110
#define DDR_UMCTL2_DRAMTMG5      0x600107114
#define DDR_UMCTL2_DRAMTMG6      0x600107118
#define DDR_UMCTL2_DRAMTMG7      0x60010711c
#define DDR_UMCTL2_DRAMTMG8      0x600107120
#define DDR_UMCTL2_DRAMTMG9      0x600107124
#define DDR_UMCTL2_DRAMTMG10     0x600107128
#define DDR_UMCTL2_DRAMTMG11     0x60010712c
#define DDR_UMCTL2_DRAMTMG12     0x600107130
#define DDR_UMCTL2_DRAMTMG14     0x600107138
#define DDR_UMCTL2_DRAMTMG15     0x60010713c
#define DDR_UMCTL2_ZQCTL0        0x600107180
#define DDR_UMCTL2_ZQCTL1        0x600107184
#define DDR_UMCTL2_ZQCTL2        0x600107188
#define DDR_UMCTL2_ZQSTAT        0x60010718c
#define DDR_UMCTL2_DFITMG0       0x600107190
#define DDR_UMCTL2_DFITMG1       0x600107194
#define DDR_UMCTL2_DFILPCFG0     0x600107198
#define DDR_UMCTL2_DFILPCFG1     0x60010719c
#define DDR_UMCTL2_DFIUPD0       0x6001071a0
#define DDR_UMCTL2_DFIUPD1       0x6001071a4
#define DDR_UMCTL2_DFIUPD2       0x6001071a8
#define DDR_UMCTL2_DFIMISC       0x6001071b0
#define DDR_UMCTL2_DFITMG3       0x6001071b8
#define DDR_UMCTL2_DFISTAT       0x6001071bc
#define DDR_UMCTL2_DBICTL        0x6001071c0
#define DDR_UMCTL2_DFIPHYMSTR    0x6001071c4
#define DDR_UMCTL2_ADDRMAP0      0x600107200
#define DDR_UMCTL2_ADDRMAP1      0x600107204
#define DDR_UMCTL2_ADDRMAP2      0x600107208
#define DDR_UMCTL2_ADDRMAP3      0x60010720c
#define DDR_UMCTL2_ADDRMAP4      0x600107210
#define DDR_UMCTL2_ADDRMAP5      0x600107214
#define DDR_UMCTL2_ADDRMAP6      0x600107218
#define DDR_UMCTL2_ADDRMAP7      0x60010721c
#define DDR_UMCTL2_ADDRMAP8      0x600107220
#define DDR_UMCTL2_ADDRMAP9      0x600107224
#define DDR_UMCTL2_ADDRMAP10     0x600107228
#define DDR_UMCTL2_ADDRMAP11     0x60010722c
#define DDR_UMCTL2_ODTCFG        0x600107240
#define DDR_UMCTL2_ODTMAP        0x600107244
#define DDR_UMCTL2_SCHED         0x600107250
#define DDR_UMCTL2_SCHED1        0x600107254
#define DDR_UMCTL2_PERFHPR1      0x60010725c
#define DDR_UMCTL2_PERFLPR1      0x600107264
#define DDR_UMCTL2_PERFWR1       0x60010726c
#define DDR_UMCTL2_DBG0          0x600107300
#define DDR_UMCTL2_DBG1          0x600107304
#define DDR_UMCTL2_DBGCAM        0x600107308
#define DDR_UMCTL2_DBGCMD        0x60010730c
#define DDR_UMCTL2_DBGSTAT       0x600107310
#define DDR_UMCTL2_SWCTL         0x600107320
#define DDR_UMCTL2_SWSTAT        0x600107324
#define DDR_UMCTL2_POISONCFG     0x60010736c
#define DDR_UMCTL2_POISONSTAT    0x600107370
#define DDR_UMCTL2_ADVECCINDEX   0x600107374
#define DDR_UMCTL2_ECCPOISONPAT0 0x60010737c
#define DDR_UMCTL2_ECCPOISONPAT2 0x600107384
#define DDR_UMCTL2_PSTAT         0x6001073fc
#define DDR_UMCTL2_PCCFG         0x600107400
#define DDR_UMCTL2_PCFGR_0       0x600107404
#define DDR_UMCTL2_PCFGW_0       0x600107408
#define DDR_UMCTL2_PCTRL_0       0x600107490
#define DDR_UMCTL2_PCFGQOS0_0    0x600107494
#define DDR_UMCTL2_SBRCTL        0x600107f24
#define DDR_UMCTL2_SBRSTAT       0x600107f28
#define DDR_UMCTL2_SBRWDATA0     0x600107f2c

#define XLIST_DDR_MAIN \
        X(crcparctl1, DDR_UMCTL2_CRCPARCTL1, main)	\
        X(dbictl, DDR_UMCTL2_DBICTL, main)	\
        X(dfimisc, DDR_UMCTL2_DFIMISC, main)	\
        X(dfitmg0, DDR_UMCTL2_DFITMG0, main)	\
        X(dfitmg1, DDR_UMCTL2_DFITMG1, main)	\
        X(dfiupd0, DDR_UMCTL2_DFIUPD0, main)	\
        X(dfiupd1, DDR_UMCTL2_DFIUPD1, main)	\
        X(ecccfg0, DDR_UMCTL2_ECCCFG0, main)	\
        X(init0, DDR_UMCTL2_INIT0, main)	\
        X(init1, DDR_UMCTL2_INIT1, main)	\
        X(init3, DDR_UMCTL2_INIT3, main)	\
        X(init4, DDR_UMCTL2_INIT4, main)	\
        X(init5, DDR_UMCTL2_INIT5, main)	\
        X(init6, DDR_UMCTL2_INIT6, main)	\
        X(init7, DDR_UMCTL2_INIT7, main)	\
        X(mstr, DDR_UMCTL2_MSTR, main)	\
        X(pccfg, DDR_UMCTL2_PCCFG, main)	\
        X(pwrctl, DDR_UMCTL2_PWRCTL, main)	\
        X(rfshctl0, DDR_UMCTL2_RFSHCTL0, main)	\
        X(rfshctl3, DDR_UMCTL2_RFSHCTL3, main)	\

#define XLIST_DDR_TIMING \
        X(dramtmg0, DDR_UMCTL2_DRAMTMG0, timing)	\
        X(dramtmg1, DDR_UMCTL2_DRAMTMG1, timing)	\
        X(dramtmg12, DDR_UMCTL2_DRAMTMG12, timing)	\
        X(dramtmg2, DDR_UMCTL2_DRAMTMG2, timing)	\
        X(dramtmg3, DDR_UMCTL2_DRAMTMG3, timing)	\
        X(dramtmg4, DDR_UMCTL2_DRAMTMG4, timing)	\
        X(dramtmg5, DDR_UMCTL2_DRAMTMG5, timing)	\
        X(dramtmg8, DDR_UMCTL2_DRAMTMG8, timing)	\
        X(dramtmg9, DDR_UMCTL2_DRAMTMG9, timing)	\
        X(odtcfg, DDR_UMCTL2_ODTCFG, timing)	\
        X(rfshtmg, DDR_UMCTL2_RFSHTMG, timing)	\

#define XLIST_DDR_MAPPING \
        X(addrmap0, DDR_UMCTL2_ADDRMAP0, mapping)	\
        X(addrmap1, DDR_UMCTL2_ADDRMAP1, mapping)	\
        X(addrmap2, DDR_UMCTL2_ADDRMAP2, mapping)	\
        X(addrmap3, DDR_UMCTL2_ADDRMAP3, mapping)	\
        X(addrmap4, DDR_UMCTL2_ADDRMAP4, mapping)	\
        X(addrmap5, DDR_UMCTL2_ADDRMAP5, mapping)	\
        X(addrmap6, DDR_UMCTL2_ADDRMAP6, mapping)	\
        X(addrmap7, DDR_UMCTL2_ADDRMAP7, mapping)	\
        X(addrmap8, DDR_UMCTL2_ADDRMAP8, mapping)	\

#define XLIST_DDR_PHY \
        X(dcr, DDR_PHY_DCR, phy)	\
        X(dsgcr, DDR_PHY_DSGCR, phy)	\
        X(dtcr0, DDR_PHY_DTCR0, phy)	\
        X(dtcr1, DDR_PHY_DTCR1, phy)	\
        X(dxccr, DDR_PHY_DXCCR, phy)	\
        X(pgcr2, DDR_PHY_PGCR2, phy)	\
        X(schcr1, DDR_PHY_SCHCR1, phy)	\
        X(zq0pr, DDR_PHY_ZQ0PR, phy)	\
        X(zq1pr, DDR_PHY_ZQ1PR, phy)	\
        X(zq2pr, DDR_PHY_ZQ2PR, phy)	\
        X(zqcr, DDR_PHY_ZQCR, phy)	\

#define XLIST_DDR_PHY_TIMING \
        X(dtpr0, DDR_PHY_DTPR0, phy_timing)	\
        X(dtpr1, DDR_PHY_DTPR1, phy_timing)	\
        X(dtpr2, DDR_PHY_DTPR2, phy_timing)	\
        X(dtpr3, DDR_PHY_DTPR3, phy_timing)	\
        X(dtpr4, DDR_PHY_DTPR4, phy_timing)	\
        X(dtpr5, DDR_PHY_DTPR5, phy_timing)	\
        X(mr0, DDR_PHY_MR0, phy_timing)	\
        X(mr1, DDR_PHY_MR1, phy_timing)	\
        X(mr2, DDR_PHY_MR2, phy_timing)	\
        X(mr3, DDR_PHY_MR3, phy_timing)	\
        X(mr4, DDR_PHY_MR4, phy_timing)	\
        X(mr5, DDR_PHY_MR5, phy_timing)	\
        X(mr6, DDR_PHY_MR6, phy_timing)	\
        X(ptr0, DDR_PHY_PTR0, phy_timing)	\
        X(ptr1, DDR_PHY_PTR1, phy_timing)	\
        X(ptr2, DDR_PHY_PTR2, phy_timing)	\
        X(ptr3, DDR_PHY_PTR3, phy_timing)	\
        X(ptr4, DDR_PHY_PTR4, phy_timing)	\


#endif /* __DDR_REG_H */
