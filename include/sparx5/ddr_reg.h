/*
 * Copyright (C) 2022 Microchip Technology Inc. and its subsidiaries.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __DDR_REG_H
#define __DDR_REG_H

#include <ddr_platform.h>

#define CLKGEN_LCPLL1_DDR_CLK_CFG 0x611100010
#define  LCPLL1_DDR_CLK_CFG_DDR_CLK_DIV GENMASK_32(7, 0)
#define  LCPLL1_DDR_CLK_CFG_DDR_PRE_DIV GENMASK_32(10, 8)
#define  LCPLL1_DDR_CLK_CFG_DDR_ROT_DIR BIT_32(11)
#define  LCPLL1_DDR_CLK_CFG_DDR_ROT_SEL GENMASK_32(13, 12)
#define  LCPLL1_DDR_CLK_CFG_DDR_ROT_ENA BIT_32(14)
#define  LCPLL1_DDR_CLK_CFG_DDR_CLK_ENA BIT_32(15)

#define CPU_RESET                0x600000080
#define  RESET_VCORE_RST          BIT_32(9)
#define  RESET_CPU_CORE_0_WARM_RST BIT_32(8)
#define  RESET_CPU_CORE_1_WARM_RST BIT_32(7)
#define  RESET_PROC_DBG_RST       BIT_32(6)
#define  RESET_CPU_L2_RST         BIT_32(5)
#define  RESET_MEM_RST            BIT_32(4)
#define  RESET_WDT_FORCE_RST      BIT_32(3)
#define  RESET_CPU_CORE_0_COLD_RST BIT_32(2)
#define  RESET_CPU_CORE_1_COLD_RST BIT_32(1)
#define  RESET_GIC_RST            BIT_32(0)

#define CPU_DDRCTRL_CLK          0x6000002c0
#define  DDRCTRL_CLK_DDR_CLK_ENA  BIT_32(0)
#define  DDRCTRL_CLK_DDR_AXI_CLK_ENA BIT_32(1)
#define  DDRCTRL_CLK_DDR_APB_CLK_ENA BIT_32(2)
#define  DDRCTRL_CLK_DDRPHY_CTL_CLK_ENA BIT_32(3)
#define  DDRCTRL_CLK_DDRPHY_APB_CLK_ENA BIT_32(4)

#define CPU_DDRCTRL_RST          0x6000002c4
#define  DDRCTRL_RST_DDRC_RST     BIT_32(0)
#define  DDRCTRL_RST_DDR_AXI_RST  BIT_32(1)
#define  DDRCTRL_RST_DDR_APB_RST  BIT_32(2)
#define  DDRCTRL_RST_DDRPHY_CTL_RST BIT_32(3)
#define  DDRCTRL_RST_DDRPHY_APB_RST BIT_32(4)

#define DDR_PHY_RIDR             0x600108000
#define  RIDR_PUBID               GENMASK_32(11, 0)
#define  RIDR_PHYID               GENMASK_32(23, 12)
#define  RIDR_UDRID               GENMASK_32(31, 24)

#define DDR_PHY_PIR              0x600108004
#define  PIR_INIT                 BIT_32(0)
#define  PIR_ZCAL                 BIT_32(1)
#define  PIR_CA                   BIT_32(2)
#define  PIR_RESERVED_3           BIT_32(3)
#define  PIR_PLLINIT              BIT_32(4)
#define  PIR_DCAL                 BIT_32(5)
#define  PIR_PHYRST               BIT_32(6)
#define  PIR_DRAMRST              BIT_32(7)
#define  PIR_DRAMINIT             BIT_32(8)
#define  PIR_WL                   BIT_32(9)
#define  PIR_QSGATE               BIT_32(10)
#define  PIR_WLADJ                BIT_32(11)
#define  PIR_RDDSKW               BIT_32(12)
#define  PIR_WRDSKW               BIT_32(13)
#define  PIR_RDEYE                BIT_32(14)
#define  PIR_WREYE                BIT_32(15)
#define  PIR_SRD                  BIT_32(16)
#define  PIR_VREF                 BIT_32(17)
#define  PIR_CTLDINIT             BIT_32(18)
#define  PIR_RDIMMINIT            BIT_32(19)
#define  PIR_RESERVED_28_20       GENMASK_32(28, 20)
#define  PIR_DCALPSE              BIT_32(29)
#define  PIR_ZCALBYP              BIT_32(30)
#define  PIR_RESERVED_31          BIT_32(31)

#define DDR_PHY_CGCR             0x600108008
#define  CGCR_GICGEN              BIT_32(0)
#define  CGCR_CFGICGEN            BIT_32(1)
#define  CGCR_INITICGEN           BIT_32(2)
#define  CGCR_TRAINICGEN          BIT_32(3)
#define  CGCR_BISTICGEN           BIT_32(4)
#define  CGCR_DCUICGEN            BIT_32(5)
#define  CGCR_SCHICGEN            BIT_32(6)
#define  CGCR_DFIICGEN            BIT_32(7)
#define  CGCR_RESERVED_31_8       GENMASK_32(31, 8)

#define DDR_PHY_CGCR1            0x60010800c
#define  CGCR1_GATEACCTLCLK       BIT_32(0)
#define  CGCR1_GATEACDDRCLK       BIT_32(1)
#define  CGCR1_GATEACRDCLK        BIT_32(2)
#define  CGCR1_GATEDXCTLCLK       GENMASK_32(11, 3)
#define  CGCR1_GATEDXDDRCLK       GENMASK_32(20, 12)
#define  CGCR1_GATEDXRDCLK        GENMASK_32(29, 21)
#define  CGCR1_RESERVED_31_30     GENMASK_32(31, 30)

#define DDR_PHY_PGCR0            0x600108010
#define  PGCR0_ICPC               BIT_32(0)
#define  PGCR0_CLRZCAL            BIT_32(1)
#define  PGCR0_PLLFSMBYP          BIT_32(2)
#define  PGCR0_INITFSMBYP         BIT_32(3)
#define  PGCR0_CLRPERR            BIT_32(4)
#define  PGCR0_CLRTSTAT           BIT_32(5)
#define  PGCR0_DLTMODE            BIT_32(6)
#define  PGCR0_DLTST              BIT_32(7)
#define  PGCR0_OSCEN              BIT_32(8)
#define  PGCR0_OSCDIV             GENMASK_32(12, 9)
#define  PGCR0_ACWLPON            BIT_32(13)
#define  PGCR0_DTOSEL             GENMASK_32(18, 14)
#define  PGCR0_OSCWDL             GENMASK_32(20, 19)
#define  PGCR0_RESERVED_21        BIT_32(21)
#define  PGCR0_OSCWDDL            GENMASK_32(23, 22)
#define  PGCR0_OSCACDL            GENMASK_32(25, 24)
#define  PGCR0_PHYFRST            BIT_32(26)
#define  PGCR0_X4OSCWDL           GENMASK_32(28, 27)
#define  PGCR0_X4OSCWDDL          GENMASK_32(30, 29)
#define  PGCR0_ADCP               BIT_32(31)

#define DDR_PHY_PGCR1            0x600108014
#define  PGCR1_DTOMODE            BIT_32(0)
#define  PGCR1_WLMODE             BIT_32(1)
#define  PGCR1_WLSTEP             BIT_32(2)
#define  PGCR1_WLUNCRT            BIT_32(3)
#define  PGCR1_DDLBYPMODE         GENMASK_32(5, 4)
#define  PGCR1_PUBMODE            BIT_32(6)
#define  PGCR1_IODDRM             GENMASK_32(8, 7)
#define  PGCR1_MDLEN              BIT_32(9)
#define  PGCR1_LPFEN              BIT_32(10)
#define  PGCR1_LPFDEPTH           GENMASK_32(12, 11)
#define  PGCR1_FDEPTH             GENMASK_32(14, 13)
#define  PGCR1_DUALCHN            BIT_32(15)
#define  PGCR1_ACPDDC             BIT_32(16)
#define  PGCR1_LPMSTRC0           BIT_32(17)
#define  PGCR1_UPDMSTRC0          BIT_32(18)
#define  PGCR1_PRCFG_EN           BIT_32(19)
#define  PGCR1_LRDIMMST           BIT_32(20)
#define  PGCR1_ACVLDDLY           GENMASK_32(23, 21)
#define  PGCR1_ACVLDTRN           BIT_32(24)
#define  PGCR1_PHYHRST            BIT_32(25)
#define  PGCR1_DLYLDTM            BIT_32(26)
#define  PGCR1_IOLB               BIT_32(27)
#define  PGCR1_LBDQSS             BIT_32(28)
#define  PGCR1_LBGDQS             GENMASK_32(30, 29)
#define  PGCR1_LBMODE             BIT_32(31)

#define DDR_PHY_PGCR2            0x600108018
#define  PGCR2_TREFPRD            GENMASK_32(17, 0)
#define  PGCR2_CSNCIDMUX          BIT_32(18)
#define  PGCR2_FXDLAT             BIT_32(19)
#define  PGCR2_DTPMXTMR           GENMASK_32(27, 20)
#define  PGCR2_FXDLATINCR         BIT_32(28)
#define  PGCR2_RFSHMODE           GENMASK_32(30, 29)
#define  PGCR2_RESERVED_31        BIT_32(31)

#define DDR_PHY_PGCR3            0x60010801c
#define  PGCR3_CLKLEVEL           GENMASK_32(1, 0)
#define  PGCR3_DISRST             BIT_32(2)
#define  PGCR3_RDMODE             GENMASK_32(4, 3)
#define  PGCR3_RDBICL             GENMASK_32(7, 5)
#define  PGCR3_RESERVED_8         BIT_32(8)
#define  PGCR3_LPACCTLCLKGEN      BIT_32(9)
#define  PGCR3_LPACDDRCLKGEN      BIT_32(10)
#define  PGCR3_LPACRDCLKGEN       BIT_32(11)
#define  PGCR3_DISACOE            BIT_32(12)
#define  PGCR3_LPDXCTLCLKGEN      BIT_32(13)
#define  PGCR3_LPDXDDRCLKGEN      BIT_32(14)
#define  PGCR3_LPDXRDCLKGEN       BIT_32(15)
#define  PGCR3_CKEN               GENMASK_32(23, 16)
#define  PGCR3_PRFBYP             BIT_32(24)
#define  PGCR3_WDBI               BIT_32(25)
#define  PGCR3_RDBI               BIT_32(26)
#define  PGCR3_RDBICLSEL          BIT_32(27)
#define  PGCR3_LPWAKEUP_THRSH     GENMASK_32(31, 28)

#define DDR_PHY_PGCR4            0x600108020
#define  PGCR4_DXDDLBYP           GENMASK_32(15, 0)
#define  PGCR4_DXDDLLD            GENMASK_32(20, 16)
#define  PGCR4_RESERVED_22_21     GENMASK_32(22, 21)
#define  PGCR4_ACVLDTRNP          BIT_32(23)
#define  PGCR4_ACDDLBYP           GENMASK_32(28, 24)
#define  PGCR4_ACDDLLD            BIT_32(29)
#define  PGCR4_ACDCCBYP           BIT_32(30)
#define  PGCR4_ACRDMODE           BIT_32(31)

#define DDR_PHY_PGCR5            0x600108024
#define  PGCR5_FRQCHANGE          BIT_32(0)
#define  PGCR5_FRQACT             BIT_32(1)
#define  PGCR5_FFCDCAL            BIT_32(2)
#define  PGCR5_FFCDFIEN           BIT_32(3)
#define  PGCR5_RESERVED_11_4      GENMASK_32(11, 4)
#define  PGCR5_FRQBSEL            GENMASK_32(15, 12)
#define  PGCR5_FRQAT              GENMASK_32(23, 16)
#define  PGCR5_FRQBT              GENMASK_32(31, 24)

#define DDR_PHY_PGCR6            0x600108028
#define  PGCR6_INHVT              BIT_32(0)
#define  PGCR6_FVT                BIT_32(1)
#define  PGCR6_RESERVED_2         BIT_32(2)
#define  PGCR6_PARBVT             BIT_32(3)
#define  PGCR6_ACTNBVT            BIT_32(4)
#define  PGCR6_A17BVT             BIT_32(5)
#define  PGCR6_A16BVT             BIT_32(6)
#define  PGCR6_CIDBVT             BIT_32(7)
#define  PGCR6_CKBVT              BIT_32(8)
#define  PGCR6_CSNBVT             BIT_32(9)
#define  PGCR6_CKEBVT             BIT_32(10)
#define  PGCR6_ODTBVT             BIT_32(11)
#define  PGCR6_A9_0BVT            BIT_32(12)
#define  PGCR6_ACDLVT             BIT_32(13)
#define  PGCR6_A15_10BVT          BIT_32(14)
#define  PGCR6_BABVT              BIT_32(15)
#define  PGCR6_DLDLMT             GENMASK_32(23, 16)
#define  PGCR6_RESERVED_31_24     GENMASK_32(31, 24)

#define DDR_PHY_PGCR7            0x60010802c
#define  PGCR7_ACTMODE            BIT_32(0)
#define  PGCR7_ACDTOSEL           BIT_32(1)
#define  PGCR7_ACRSVD_2           BIT_32(2)
#define  PGCR7_ACDLDT             BIT_32(3)
#define  PGCR7_ACRCLKMD           BIT_32(4)
#define  PGCR7_ACCALCLK           BIT_32(5)
#define  PGCR7_ACDTOMUX           BIT_32(6)
#define  PGCR7_CKNSTOPL           BIT_32(7)
#define  PGCR7_RESERVED_15_8      GENMASK_32(15, 8)
#define  PGCR7_DXTMODE            BIT_32(16)
#define  PGCR7_DXGDBYP            BIT_32(17)
#define  PGCR7_DXQSDBYP           BIT_32(18)
#define  PGCR7_DXDDLLDT           BIT_32(19)
#define  PGCR7_DXGSMD             BIT_32(20)
#define  PGCR7_DXDTOSEL           GENMASK_32(22, 21)
#define  PGCR7_DXQSGSEL           BIT_32(23)
#define  PGCR7_DXRCLKMD           BIT_32(24)
#define  PGCR7_DXCALCLK           BIT_32(25)
#define  PGCR7_DXDTOMUX           BIT_32(26)
#define  PGCR7_DXRSVD             GENMASK_32(30, 27)
#define  PGCR7_WRPSTEX            BIT_32(31)

#define DDR_PHY_PGCR8            0x600108030
#define  PGCR8_DCALSVAL           GENMASK_32(8, 0)
#define  PGCR8_DCALTYPE           BIT_32(9)
#define  PGCR8_RESERVED_31_10     GENMASK_32(31, 10)

#define DDR_PHY_PGSR0            0x600108034
#define  PGSR0_IDONE              BIT_32(0)
#define  PGSR0_PLDONE             BIT_32(1)
#define  PGSR0_DCDONE             BIT_32(2)
#define  PGSR0_ZCDONE             BIT_32(3)
#define  PGSR0_DIDONE             BIT_32(4)
#define  PGSR0_WLDONE             BIT_32(5)
#define  PGSR0_QSGDONE            BIT_32(6)
#define  PGSR0_WLADONE            BIT_32(7)
#define  PGSR0_RDDONE             BIT_32(8)
#define  PGSR0_WDDONE             BIT_32(9)
#define  PGSR0_REDONE             BIT_32(10)
#define  PGSR0_WEDONE             BIT_32(11)
#define  PGSR0_CADONE             BIT_32(12)
#define  PGSR0_SRDDONE            BIT_32(13)
#define  PGSR0_VDONE              BIT_32(14)
#define  PGSR0_RESERVED_18_15     GENMASK_32(18, 15)
#define  PGSR0_VERR               BIT_32(19)
#define  PGSR0_ZCERR              BIT_32(20)
#define  PGSR0_WLERR              BIT_32(21)
#define  PGSR0_QSGERR             BIT_32(22)
#define  PGSR0_WLAERR             BIT_32(23)
#define  PGSR0_RDERR              BIT_32(24)
#define  PGSR0_WDERR              BIT_32(25)
#define  PGSR0_REERR              BIT_32(26)
#define  PGSR0_WEERR              BIT_32(27)
#define  PGSR0_CAERR              BIT_32(28)
#define  PGSR0_CAWRN              BIT_32(29)
#define  PGSR0_SRDERR             BIT_32(30)
#define  PGSR0_APLOCK             BIT_32(31)

#define DDR_PHY_PGSR1            0x600108038
#define  PGSR1_DLTDONE            BIT_32(0)
#define  PGSR1_DLTCODE            GENMASK_32(24, 1)
#define  PGSR1_RESERVED_28_25     GENMASK_32(28, 25)
#define  PGSR1_FFCDONE            BIT_32(29)
#define  PGSR1_VTSTOP             BIT_32(30)
#define  PGSR1_PARERR             BIT_32(31)

#define DDR_PHY_PTR0             0x600108040
#define  PTR0_TPHYRST             GENMASK_32(5, 0)
#define  PTR0_TPLLGS              GENMASK_32(20, 6)
#define  PTR0_TPLLPD              GENMASK_32(31, 21)

#define DDR_PHY_PTR1             0x600108044
#define  PTR1_TPLLRST             GENMASK_32(12, 0)
#define  PTR1_RESERVED_14_13      GENMASK_32(14, 13)
#define  PTR1_TPLLLOCK            GENMASK_32(31, 15)

#define DDR_PHY_PTR2             0x600108048
#define  PTR2_TCALON              GENMASK_32(4, 0)
#define  PTR2_TCALS               GENMASK_32(9, 5)
#define  PTR2_TCALH               GENMASK_32(14, 10)
#define  PTR2_TWLDLYS             GENMASK_32(19, 15)
#define  PTR2_RESERVED_31_20      GENMASK_32(31, 20)

#define DDR_PHY_PTR3             0x60010804c
#define  PTR3_TDINIT0             GENMASK_32(19, 0)
#define  PTR3_TDINIT1             GENMASK_32(29, 20)
#define  PTR3_RESERVED_31_30      GENMASK_32(31, 30)

#define DDR_PHY_PTR4             0x600108050
#define  PTR4_TDINIT2             GENMASK_32(17, 0)
#define  PTR4_TDINIT3             GENMASK_32(28, 18)
#define  PTR4_RESERVED_31_29      GENMASK_32(31, 29)

#define DDR_PHY_PTR5             0x600108054
#define  PTR5_TPLLFFCGS           GENMASK_32(11, 0)
#define  PTR5_RESERVED_13_12      GENMASK_32(13, 12)
#define  PTR5_TPLLFFCRGS          GENMASK_32(23, 14)
#define  PTR5_RESERVED_25_24      GENMASK_32(25, 24)
#define  PTR5_TPLLFRQSEL          GENMASK_32(31, 26)

#define DDR_PHY_PTR6             0x600108058
#define  PTR6_TPLLRLCK1           GENMASK_32(13, 0)
#define  PTR6_RESERVED_31_14      GENMASK_32(31, 14)

#define DDR_PHY_PLLCR0           0x600108068
#define  PLLCR0_DTC               GENMASK_32(3, 0)
#define  PLLCR0_ATC               GENMASK_32(7, 4)
#define  PLLCR0_ATOEN             GENMASK_32(11, 8)
#define  PLLCR0_GSHIFT            BIT_32(12)
#define  PLLCR0_CPIC              GENMASK_32(16, 13)
#define  PLLCR0_CPPC              GENMASK_32(22, 17)
#define  PLLCR0_RLOCKM            BIT_32(23)
#define  PLLCR0_FRQSEL            GENMASK_32(27, 24)
#define  PLLCR0_RSTOPM            BIT_32(28)
#define  PLLCR0_PLLPD             BIT_32(29)
#define  PLLCR0_PLLRST            BIT_32(30)
#define  PLLCR0_PLLBYP            BIT_32(31)

#define DDR_PHY_PLLCR1           0x60010806c
#define  PLLCR1_LOCKDS            BIT_32(0)
#define  PLLCR1_LOCKCS            BIT_32(1)
#define  PLLCR1_LOCKPS            BIT_32(2)
#define  PLLCR1_BYPVDD            BIT_32(3)
#define  PLLCR1_BYPVREGDIG        BIT_32(4)
#define  PLLCR1_BYPVREGCP         BIT_32(5)
#define  PLLCR1_RESERVED_15_6     GENMASK_32(15, 6)
#define  PLLCR1_PLLPROG           GENMASK_32(31, 16)

#define DDR_PHY_PLLCR2           0x600108070
#define  PLLCR2_PLLCTRL_31_0      GENMASK_32(31, 0)

#define DDR_PHY_PLLCR3           0x600108074
#define  PLLCR3_PLLCTRL_63_32     GENMASK_32(31, 0)

#define DDR_PHY_PLLCR4           0x600108078
#define  PLLCR4_PLLCTRL_95_64     GENMASK_32(31, 0)

#define DDR_PHY_PLLCR5           0x60010807c
#define  PLLCR5_PLLCTRL_103_96    GENMASK_32(7, 0)
#define  PLLCR5_RESERVED_31_8     GENMASK_32(31, 8)

#define DDR_PHY_PLLCR            0x600108080
#define  PLLCR_DTC                GENMASK_32(2, 0)
#define  PLLCR_ATC                GENMASK_32(6, 3)
#define  PLLCR_ATOEN              GENMASK_32(10, 7)
#define  PLLCR_GSHIFT             BIT_32(11)
#define  PLLCR_CPIC               GENMASK_32(13, 12)
#define  PLLCR_CPPC               GENMASK_32(17, 14)
#define  PLLCR_RGSHIFT            BIT_32(18)
#define  PLLCR_FRQSEL             GENMASK_32(20, 19)
#define  PLLCR_RGVINT             BIT_32(21)
#define  PLLCR_LOCKDS             BIT_32(22)
#define  PLLCR_LOCKCS             BIT_32(23)
#define  PLLCR_LOCKPS             BIT_32(24)
#define  PLLCR_RESERVED_28_25     GENMASK_32(28, 25)
#define  PLLCR_PLLPD              BIT_32(29)
#define  PLLCR_PLLRST             BIT_32(30)
#define  PLLCR_PLLBYP             BIT_32(31)

#define DDR_PHY_DXCCR            0x600108088
#define  DXCCR_DXODT              BIT_32(0)
#define  DXCCR_DXIOM              BIT_32(1)
#define  DXCCR_MDLEN              BIT_32(2)
#define  DXCCR_DQSGLB             GENMASK_32(4, 3)
#define  DXCCR_DQSRES             GENMASK_32(8, 5)
#define  DXCCR_DQSNRES            GENMASK_32(12, 9)
#define  DXCCR_DXSR               GENMASK_32(14, 13)
#define  DXCCR_MSBUDQ             GENMASK_32(17, 15)
#define  DXCCR_RESERVED_20_18     GENMASK_32(20, 18)
#define  DXCCR_UDQIOM             BIT_32(21)
#define  DXCCR_QSCNTEN            BIT_32(22)
#define  DXCCR_DXDCCBYP           BIT_32(23)
#define  DXCCR_RESERVED_28_24     GENMASK_32(28, 24)
#define  DXCCR_RKLOOP             BIT_32(29)
#define  DXCCR_X4DQSMD            BIT_32(30)
#define  DXCCR_X4MODE             BIT_32(31)

#define DDR_PHY_DSGCR            0x600108090
#define  DSGCR_PUREN              BIT_32(0)
#define  DSGCR_BDISEN             BIT_32(1)
#define  DSGCR_CTLZUEN            BIT_32(2)
#define  DSGCR_LPIOPD             BIT_32(3)
#define  DSGCR_LPPLLPD            BIT_32(4)
#define  DSGCR_CUAEN              BIT_32(5)
#define  DSGCR_DQSGX              GENMASK_32(7, 6)
#define  DSGCR_PUAD               GENMASK_32(11, 8)
#define  DSGCR_DTOODT             BIT_32(12)
#define  DSGCR_RESERVED_13        BIT_32(13)
#define  DSGCR_DTOPDR             BIT_32(14)
#define  DSGCR_DTOIOM             BIT_32(15)
#define  DSGCR_DTOOE              BIT_32(16)
#define  DSGCR_ATOAE              BIT_32(17)
#define  DSGCR_WRRMODE            BIT_32(18)
#define  DSGCR_SDRMODE            GENMASK_32(20, 19)
#define  DSGCR_RSTOE              BIT_32(21)
#define  DSGCR_RRRMODE            BIT_32(22)
#define  DSGCR_PHYZUEN            BIT_32(23)
#define  DSGCR_RESERVED_31_24     GENMASK_32(31, 24)

#define DDR_PHY_ODTCR            0x600108098
#define  ODTCR_RDODT              GENMASK_32(11, 0)
#define  ODTCR_RESERVED_15_12     GENMASK_32(15, 12)
#define  ODTCR_WRODT              GENMASK_32(27, 16)
#define  ODTCR_RESERVED_31_28     GENMASK_32(31, 28)

#define DDR_PHY_AACR             0x6001080a0
#define  AACR_AATR                GENMASK_32(29, 0)
#define  AACR_AAENC               BIT_32(30)
#define  AACR_AAOENC              BIT_32(31)

#define DDR_PHY_GPR0             0x6001080c0
#define  GPR0_GPR0                GENMASK_32(31, 0)

#define DDR_PHY_GPR1             0x6001080c4
#define  GPR1_GPR1                GENMASK_32(31, 0)

#define DDR_PHY_DCR              0x600108100
#define  DCR_DDRMD                GENMASK_32(2, 0)
#define  DCR_DDR8BNK              BIT_32(3)
#define  DCR_PDQ                  GENMASK_32(6, 4)
#define  DCR_MPRDQ                BIT_32(7)
#define  DCR_DDRTYPE              GENMASK_32(9, 8)
#define  DCR_BYTEMASK             GENMASK_32(17, 10)
#define  DCR_RESERVED_26_18       GENMASK_32(26, 18)
#define  DCR_NOSRA                BIT_32(27)
#define  DCR_DDR2T                BIT_32(28)
#define  DCR_UDIMM                BIT_32(29)
#define  DCR_UBG                  BIT_32(30)
#define  DCR_RESERVED_31          BIT_32(31)

#define DDR_PHY_DTPR0            0x600108110
#define  DTPR0_TRTP               GENMASK_32(3, 0)
#define  DTPR0_RESERVED_7_4       GENMASK_32(7, 4)
#define  DTPR0_TRP                GENMASK_32(14, 8)
#define  DTPR0_RESERVED_15        BIT_32(15)
#define  DTPR0_TRAS               GENMASK_32(22, 16)
#define  DTPR0_RESERVED_23        BIT_32(23)
#define  DTPR0_TRRD               GENMASK_32(29, 24)
#define  DTPR0_RESERVED_31_30     GENMASK_32(31, 30)

#define DDR_PHY_DTPR1            0x600108114
#define  DTPR1_TMRD               GENMASK_32(4, 0)
#define  DTPR1_RESERVED_7_5       GENMASK_32(7, 5)
#define  DTPR1_TMOD               GENMASK_32(10, 8)
#define  DTPR1_RESERVED_15_11     GENMASK_32(15, 11)
#define  DTPR1_TFAW               GENMASK_32(23, 16)
#define  DTPR1_TWLMRD             GENMASK_32(29, 24)
#define  DTPR1_RESERVED_31_30     GENMASK_32(31, 30)

#define DDR_PHY_DTPR2            0x600108118
#define  DTPR2_TXS                GENMASK_32(9, 0)
#define  DTPR2_RESERVED_15_10     GENMASK_32(15, 10)
#define  DTPR2_TCKE               GENMASK_32(19, 16)
#define  DTPR2_RESERVED_23_20     GENMASK_32(23, 20)
#define  DTPR2_TRTODT             BIT_32(24)
#define  DTPR2_RESERVED_27_25     GENMASK_32(27, 25)
#define  DTPR2_TRTW               BIT_32(28)
#define  DTPR2_RESERVED_31_29     GENMASK_32(31, 29)

#define DDR_PHY_DTPR3            0x60010811c
#define  DTPR3_TDQSCK             GENMASK_32(2, 0)
#define  DTPR3_RESERVED_7_3       GENMASK_32(7, 3)
#define  DTPR3_TDQSCKMAX          GENMASK_32(10, 8)
#define  DTPR3_RESERVED_15_11     GENMASK_32(15, 11)
#define  DTPR3_TDLLK              GENMASK_32(25, 16)
#define  DTPR3_TCCD               GENMASK_32(28, 26)
#define  DTPR3_TOFDX              GENMASK_32(31, 29)

#define DDR_PHY_DTPR4            0x600108120
#define  DTPR4_TXP                GENMASK_32(4, 0)
#define  DTPR4_RESERVED_7_5       GENMASK_32(7, 5)
#define  DTPR4_TWLO               GENMASK_32(11, 8)
#define  DTPR4_RESERVED_15_12     GENMASK_32(15, 12)
#define  DTPR4_TRFC               GENMASK_32(25, 16)
#define  DTPR4_RESERVED_27_26     GENMASK_32(27, 26)
#define  DTPR4_TAOND_TAOFD        GENMASK_32(29, 28)
#define  DTPR4_RESERVED_31_30     GENMASK_32(31, 30)

#define DDR_PHY_DTPR5            0x600108124
#define  DTPR5_TWTR               GENMASK_32(4, 0)
#define  DTPR5_RESERVED_7_5       GENMASK_32(7, 5)
#define  DTPR5_TRCD               GENMASK_32(14, 8)
#define  DTPR5_RESERVED_15        BIT_32(15)
#define  DTPR5_TRC                GENMASK_32(23, 16)
#define  DTPR5_RESERVED_31_24     GENMASK_32(31, 24)

#define DDR_PHY_DTPR6            0x600108128
#define  DTPR6_PUBRL              GENMASK_32(5, 0)
#define  DTPR6_RESERVED_7_6       GENMASK_32(7, 6)
#define  DTPR6_PUBWL              GENMASK_32(13, 8)
#define  DTPR6_RESERVED_29_14     GENMASK_32(29, 14)
#define  DTPR6_PUBRLEN            BIT_32(30)
#define  DTPR6_PUBWLEN            BIT_32(31)

#define DDR_PHY_RDIMMGCR0        0x600108140
#define  RDIMMGCR0_RDIMM          BIT_32(0)
#define  RDIMMGCR0_ERRNOREG       BIT_32(1)
#define  RDIMMGCR0_SOPERR         BIT_32(2)
#define  RDIMMGCR0_PERRDIS        BIT_32(3)
#define  RDIMMGCR0_RESERVED_13_4  GENMASK_32(13, 4)
#define  RDIMMGCR0_PARINODT       BIT_32(14)
#define  RDIMMGCR0_RESERVED_15    BIT_32(15)
#define  RDIMMGCR0_PARINPDR       BIT_32(16)
#define  RDIMMGCR0_PARINIOM       BIT_32(17)
#define  RDIMMGCR0_LRDIMM         BIT_32(18)
#define  RDIMMGCR0_ERROUTODT      BIT_32(19)
#define  RDIMMGCR0_RESERVED_20    BIT_32(20)
#define  RDIMMGCR0_ERROUTPDR      BIT_32(21)
#define  RDIMMGCR0_ERROUTIOM      BIT_32(22)
#define  RDIMMGCR0_ERROUTOE       BIT_32(23)
#define  RDIMMGCR0_RDIMMODT       BIT_32(24)
#define  RDIMMGCR0_RESERVED_25    BIT_32(25)
#define  RDIMMGCR0_RDIMMPDR       BIT_32(26)
#define  RDIMMGCR0_RDIMMIOM       BIT_32(27)
#define  RDIMMGCR0_QCSENOE        BIT_32(28)
#define  RDIMMGCR0_MIRROROE       BIT_32(29)
#define  RDIMMGCR0_QCSEN          BIT_32(30)
#define  RDIMMGCR0_MIRROR         BIT_32(31)

#define DDR_PHY_RDIMMGCR1        0x600108144
#define  RDIMMGCR1_TBCSTAB        GENMASK_32(13, 0)
#define  RDIMMGCR1_RESERVED_15_14 GENMASK_32(15, 14)
#define  RDIMMGCR1_TBCMRD         GENMASK_32(18, 16)
#define  RDIMMGCR1_RESERVED_19    BIT_32(19)
#define  RDIMMGCR1_TBCMRD_L       GENMASK_32(22, 20)
#define  RDIMMGCR1_RESERVED_23    BIT_32(23)
#define  RDIMMGCR1_TBCMRD_L2      GENMASK_32(26, 24)
#define  RDIMMGCR1_RESERVED_27    BIT_32(27)
#define  RDIMMGCR1_A17BID         GENMASK_32(31, 28)

#define DDR_PHY_RDIMMGCR2        0x600108148
#define  RDIMMGCR2_CRINT          GENMASK_32(31, 0)

#define DDR_PHY_RDIMMCR0         0x600108150
#define  RDIMMCR0_RC0             GENMASK_32(3, 0)
#define  RDIMMCR0_RC1             GENMASK_32(7, 4)
#define  RDIMMCR0_RC2             GENMASK_32(11, 8)
#define  RDIMMCR0_RC3             GENMASK_32(15, 12)
#define  RDIMMCR0_RC4             GENMASK_32(19, 16)
#define  RDIMMCR0_RC5             GENMASK_32(23, 20)
#define  RDIMMCR0_RC6             GENMASK_32(27, 24)
#define  RDIMMCR0_RC7             GENMASK_32(31, 28)

#define DDR_PHY_RDIMMCR0_DDR4    0x600108150
#define  RDIMMCR0_DDR4_RC0        GENMASK_32(3, 0)
#define  RDIMMCR0_DDR4_RC1        GENMASK_32(7, 4)
#define  RDIMMCR0_DDR4_RC2        GENMASK_32(11, 8)
#define  RDIMMCR0_DDR4_RC3        GENMASK_32(15, 12)
#define  RDIMMCR0_DDR4_RC4        GENMASK_32(19, 16)
#define  RDIMMCR0_DDR4_RC5        GENMASK_32(23, 20)
#define  RDIMMCR0_DDR4_RC6        GENMASK_32(27, 24)
#define  RDIMMCR0_DDR4_RC7        GENMASK_32(31, 28)

#define DDR_PHY_RDIMMCR1         0x600108154
#define  RDIMMCR1_RC8             GENMASK_32(3, 0)
#define  RDIMMCR1_RC9             GENMASK_32(7, 4)
#define  RDIMMCR1_RC10            GENMASK_32(11, 8)
#define  RDIMMCR1_RC11            GENMASK_32(15, 12)
#define  RDIMMCR1_RC12            GENMASK_32(19, 16)
#define  RDIMMCR1_RC13            GENMASK_32(23, 20)
#define  RDIMMCR1_RC14            GENMASK_32(27, 24)
#define  RDIMMCR1_RC15            GENMASK_32(31, 28)

#define DDR_PHY_RDIMMCR1_DDR4    0x600108154
#define  RDIMMCR1_DDR4_RC8        GENMASK_32(3, 0)
#define  RDIMMCR1_DDR4_RC9        GENMASK_32(7, 4)
#define  RDIMMCR1_DDR4_RC10       GENMASK_32(11, 8)
#define  RDIMMCR1_DDR4_RC11       GENMASK_32(15, 12)
#define  RDIMMCR1_DDR4_RC12       GENMASK_32(19, 16)
#define  RDIMMCR1_DDR4_RC13       GENMASK_32(23, 20)
#define  RDIMMCR1_DDR4_RC14       GENMASK_32(27, 24)
#define  RDIMMCR1_DDR4_RC15       GENMASK_32(31, 28)

#define DDR_PHY_RDIMMCR2         0x600108158
#define  RDIMMCR2_RC1X            GENMASK_32(7, 0)
#define  RDIMMCR2_RC2X            GENMASK_32(15, 8)
#define  RDIMMCR2_RC3X            GENMASK_32(23, 16)
#define  RDIMMCR2_RC4X            GENMASK_32(31, 24)

#define DDR_PHY_RDIMMCR3         0x60010815c
#define  RDIMMCR3_RC5X            GENMASK_32(7, 0)
#define  RDIMMCR3_RC6X            GENMASK_32(15, 8)
#define  RDIMMCR3_RC7X            GENMASK_32(23, 16)
#define  RDIMMCR3_RC8X            GENMASK_32(31, 24)

#define DDR_PHY_RDIMMCR4         0x600108160
#define  RDIMMCR4_RC9X            GENMASK_32(7, 0)
#define  RDIMMCR4_RCAX            GENMASK_32(15, 8)
#define  RDIMMCR4_RCBX            GENMASK_32(23, 16)
#define  RDIMMCR4_RCXX            GENMASK_32(31, 24)

#define DDR_PHY_SCHCR0           0x600108168
#define  SCHCR0_SCHTRIG           GENMASK_32(3, 0)
#define  SCHCR0_CMD               GENMASK_32(7, 4)
#define  SCHCR0_SP_CMD            GENMASK_32(11, 8)
#define  SCHCR0_RESERVED_13_12    GENMASK_32(13, 12)
#define  SCHCR0_SCHDQV            GENMASK_32(31, 14)

#define DDR_PHY_SCHCR1           0x60010816c
#define  SCHCR1_RESERVED_1_0      GENMASK_32(1, 0)
#define  SCHCR1_ALLRANK           BIT_32(2)
#define  SCHCR1_RESERVED_3        BIT_32(3)
#define  SCHCR1_SCBK              GENMASK_32(5, 4)
#define  SCHCR1_SCBG              GENMASK_32(7, 6)
#define  SCHCR1_SCADDR            GENMASK_32(27, 8)
#define  SCHCR1_SCRNK             GENMASK_32(31, 28)

#define DDR_PHY_MR0              0x600108180
#define  MR0_BL                   GENMASK_32(1, 0)
#define  MR0_CL_2                 BIT_32(2)
#define  MR0_BT                   BIT_32(3)
#define  MR0_CL_6_4               GENMASK_32(6, 4)
#define  MR0_TM                   BIT_32(7)
#define  MR0_DR                   BIT_32(8)
#define  MR0_WR                   GENMASK_32(11, 9)
#define  MR0_PD                   BIT_32(12)
#define  MR0_RSVD_15_13           GENMASK_32(15, 13)
#define  MR0_RESERVED_31_16       GENMASK_32(31, 16)

#define DDR_PHY_MR0_DDR4         0x600108180
#define  MR0_DDR4_BL              GENMASK_32(1, 0)
#define  MR0_DDR4_CL_2            BIT_32(2)
#define  MR0_DDR4_BT              BIT_32(3)
#define  MR0_DDR4_CL_6_4          GENMASK_32(6, 4)
#define  MR0_DDR4_TM              BIT_32(7)
#define  MR0_DDR4_DR              BIT_32(8)
#define  MR0_DDR4_WR_11_9         GENMASK_32(11, 9)
#define  MR0_DDR4_CL_12           BIT_32(12)
#define  MR0_DDR4_WR_13           BIT_32(13)
#define  MR0_DDR4_RSVD_15_14      GENMASK_32(15, 14)
#define  MR0_DDR4_RESERVED_31_16  GENMASK_32(31, 16)

#define DDR_PHY_MR0_LPDDR2       0x600108180
#define  MR0_LPDDR2_RSVD_15_0     GENMASK_32(15, 0)
#define  MR0_LPDDR2_RESERVED_31_16 GENMASK_32(31, 16)

#define DDR_PHY_MR0_LPDDR3       0x600108180
#define  MR0_LPDDR3_RSVD_15_0     GENMASK_32(15, 0)
#define  MR0_LPDDR3_RESERVED_31_16 GENMASK_32(31, 16)

#define DDR_PHY_MR1              0x600108184
#define  MR1_DE                   BIT_32(0)
#define  MR1_DIC_1                BIT_32(1)
#define  MR1_RTT_2                BIT_32(2)
#define  MR1_AL                   GENMASK_32(4, 3)
#define  MR1_DIC_5                BIT_32(5)
#define  MR1_RTT_6                BIT_32(6)
#define  MR1_LEVEL                BIT_32(7)
#define  MR1_RSVD_8               BIT_32(8)
#define  MR1_RTT_9                BIT_32(9)
#define  MR1_RSVD_10              BIT_32(10)
#define  MR1_TDQS                 BIT_32(11)
#define  MR1_QOFF                 BIT_32(12)
#define  MR1_RSVD_15_13           GENMASK_32(15, 13)
#define  MR1_RESERVED_31_16       GENMASK_32(31, 16)

#define DDR_PHY_MR1_DDR4         0x600108184
#define  MR1_DDR4_DE              BIT_32(0)
#define  MR1_DDR4_DIC             GENMASK_32(2, 1)
#define  MR1_DDR4_AL              GENMASK_32(4, 3)
#define  MR1_DDR4_RSVD_6_5        GENMASK_32(6, 5)
#define  MR1_DDR4_LEVEL           BIT_32(7)
#define  MR1_DDR4_RTT             GENMASK_32(10, 8)
#define  MR1_DDR4_TDQS            BIT_32(11)
#define  MR1_DDR4_QOFF            BIT_32(12)
#define  MR1_DDR4_RSVD_15_13      GENMASK_32(15, 13)
#define  MR1_DDR4_RESERVED_31_16  GENMASK_32(31, 16)

#define DDR_PHY_MR1_LPDDR2       0x600108184
#define  MR1_LPDDR2_BL            GENMASK_32(2, 0)
#define  MR1_LPDDR2_BT            BIT_32(3)
#define  MR1_LPDDR2_WC            BIT_32(4)
#define  MR1_LPDDR2_NWR           GENMASK_32(7, 5)
#define  MR1_LPDDR2_RSVD_15_8     GENMASK_32(15, 8)
#define  MR1_LPDDR2_RESERVED_31_16 GENMASK_32(31, 16)

#define DDR_PHY_MR1_LPDDR3       0x600108184
#define  MR1_LPDDR3_BL            GENMASK_32(2, 0)
#define  MR1_LPDDR3_BT            BIT_32(3)
#define  MR1_LPDDR3_WC            BIT_32(4)
#define  MR1_LPDDR3_NWR           GENMASK_32(7, 5)
#define  MR1_LPDDR3_RSVD_15_8     GENMASK_32(15, 8)
#define  MR1_LPDDR3_RESERVED_31_16 GENMASK_32(31, 16)

#define DDR_PHY_MR2              0x600108188
#define  MR2_PASR                 GENMASK_32(2, 0)
#define  MR2_CWL                  GENMASK_32(5, 3)
#define  MR2_ASR                  BIT_32(6)
#define  MR2_SRT                  BIT_32(7)
#define  MR2_RSVD_8               BIT_32(8)
#define  MR2_RTT_WR               GENMASK_32(10, 9)
#define  MR2_RSVD_15_11           GENMASK_32(15, 11)
#define  MR2_RESERVED_31_16       GENMASK_32(31, 16)

#define DDR_PHY_MR2_DDR4         0x600108188
#define  MR2_DDR4_RSVD_2_0        GENMASK_32(2, 0)
#define  MR2_DDR4_CWL             GENMASK_32(5, 3)
#define  MR2_DDR4_LPASR           GENMASK_32(7, 6)
#define  MR2_DDR4_RSVD_8          BIT_32(8)
#define  MR2_DDR4_RTT_WR          GENMASK_32(10, 9)
#define  MR2_DDR4_RSVD_11         BIT_32(11)
#define  MR2_DDR4_WRCRC           BIT_32(12)
#define  MR2_DDR4_RSVD_15_13      GENMASK_32(15, 13)
#define  MR2_DDR4_RESERVED_31_16  GENMASK_32(31, 16)

#define DDR_PHY_MR2_LPDDR2       0x600108188
#define  MR2_LPDDR2_RL_WL         GENMASK_32(3, 0)
#define  MR2_LPDDR2_RSVD_15_4     GENMASK_32(15, 4)
#define  MR2_LPDDR2_RESERVED_31_16 GENMASK_32(31, 16)

#define DDR_PHY_MR2_LPDDR3       0x600108188
#define  MR2_LPDDR3_RL_WL         GENMASK_32(3, 0)
#define  MR2_LPDDR3_NWRE          BIT_32(4)
#define  MR2_LPDDR3_RSVD_5        BIT_32(5)
#define  MR2_LPDDR3_WLSEL         BIT_32(6)
#define  MR2_LPDDR3_WRLVL         BIT_32(7)
#define  MR2_LPDDR3_RSVD_15_8     GENMASK_32(15, 8)
#define  MR2_LPDDR3_RESERVED_31_16 GENMASK_32(31, 16)

#define DDR_PHY_MR3              0x60010818c
#define  MR3_MPRLOC               GENMASK_32(1, 0)
#define  MR3_MPR                  BIT_32(2)
#define  MR3_RSVD_15_3            GENMASK_32(15, 3)
#define  MR3_RESERVED_31_16       GENMASK_32(31, 16)

#define DDR_PHY_MR3_DDR4         0x60010818c
#define  MR3_DDR4_MPRPSEL         GENMASK_32(1, 0)
#define  MR3_DDR4_MPRO            BIT_32(2)
#define  MR3_DDR4_GDM             BIT_32(3)
#define  MR3_DDR4_PDA             BIT_32(4)
#define  MR3_DDR4_TSR             BIT_32(5)
#define  MR3_DDR4_FGRM            GENMASK_32(8, 6)
#define  MR3_DDR4_WCL             GENMASK_32(10, 9)
#define  MR3_DDR4_MPRRF           GENMASK_32(12, 11)
#define  MR3_DDR4_RSVD_15_13      GENMASK_32(15, 13)
#define  MR3_DDR4_RESERVED_31_16  GENMASK_32(31, 16)

#define DDR_PHY_MR3_LPDDR2       0x60010818c
#define  MR3_LPDDR2_DS            GENMASK_32(3, 0)
#define  MR3_LPDDR2_RSVD_15_4     GENMASK_32(15, 4)
#define  MR3_LPDDR2_RESERVED_31_16 GENMASK_32(31, 16)

#define DDR_PHY_MR3_LPDDR3       0x60010818c
#define  MR3_LPDDR3_DS            GENMASK_32(3, 0)
#define  MR3_LPDDR3_RSVD_15_4     GENMASK_32(15, 4)
#define  MR3_LPDDR3_RESERVED_31_16 GENMASK_32(31, 16)

#define DDR_PHY_MR4              0x600108190
#define  MR4_RSVD_15_0            GENMASK_32(15, 0)
#define  MR4_RESERVED_31_16       GENMASK_32(31, 16)

#define DDR_PHY_MR4_DDR4         0x600108190
#define  MR4_DDR4_RSVD_0          BIT_32(0)
#define  MR4_DDR4_MPDM            BIT_32(1)
#define  MR4_DDR4_TCRR            BIT_32(2)
#define  MR4_DDR4_TCRM            BIT_32(3)
#define  MR4_DDR4_IVM             BIT_32(4)
#define  MR4_DDR4_RSVD_5          BIT_32(5)
#define  MR4_DDR4_CS2CMDL         GENMASK_32(8, 6)
#define  MR4_DDR4_SRA             BIT_32(9)
#define  MR4_DDR4_RPTM            BIT_32(10)
#define  MR4_DDR4_RDP             BIT_32(11)
#define  MR4_DDR4_WRP             BIT_32(12)
#define  MR4_DDR4_RSVD_15_13      GENMASK_32(15, 13)
#define  MR4_DDR4_RESERVED_31_16  GENMASK_32(31, 16)

#define DDR_PHY_MR4_LPDDR2       0x600108190
#define  MR4_LPDDR2_RSVD_15_0     GENMASK_32(15, 0)
#define  MR4_LPDDR2_RESERVED_31_16 GENMASK_32(31, 16)

#define DDR_PHY_MR4_LPDDR3       0x600108190
#define  MR4_LPDDR3_RSVD_15_0     GENMASK_32(15, 0)
#define  MR4_LPDDR3_RESERVED_31_16 GENMASK_32(31, 16)

#define DDR_PHY_MR5              0x600108194
#define  MR5_RSVD_15_0            GENMASK_32(15, 0)
#define  MR5_RESERVED_31_16       GENMASK_32(31, 16)

#define DDR_PHY_MR5_DDR4         0x600108194
#define  MR5_DDR4_CAPM            GENMASK_32(2, 0)
#define  MR5_DDR4_CRCEC           BIT_32(3)
#define  MR5_DDR4_CAPES           BIT_32(4)
#define  MR5_DDR4_ODTIBPD         BIT_32(5)
#define  MR5_DDR4_RTTPARK         GENMASK_32(8, 6)
#define  MR5_DDR4_CAPPE           BIT_32(9)
#define  MR5_DDR4_DM              BIT_32(10)
#define  MR5_DDR4_WDBI            BIT_32(11)
#define  MR5_DDR4_RDBI            BIT_32(12)
#define  MR5_DDR4_RSVD_15_13      GENMASK_32(15, 13)
#define  MR5_DDR4_RESERVED_31_16  GENMASK_32(31, 16)

#define DDR_PHY_MR5_LPDDR2       0x600108194
#define  MR5_LPDDR2_RSVD_15_0     GENMASK_32(15, 0)
#define  MR5_LPDDR2_RESERVED_31_16 GENMASK_32(31, 16)

#define DDR_PHY_MR5_LPDDR3       0x600108194
#define  MR5_LPDDR3_RSVD_15_0     GENMASK_32(15, 0)
#define  MR5_LPDDR3_RESERVED_31_16 GENMASK_32(31, 16)

#define DDR_PHY_MR6              0x600108198
#define  MR6_RSVD_15_0            GENMASK_32(15, 0)
#define  MR6_RESERVED_31_16       GENMASK_32(31, 16)

#define DDR_PHY_MR6_DDR4         0x600108198
#define  MR6_DDR4_VDQTVAL         GENMASK_32(5, 0)
#define  MR6_DDR4_VDQTRG          BIT_32(6)
#define  MR6_DDR4_VDDQTEN         BIT_32(7)
#define  MR6_DDR4_RSVD_9_8        GENMASK_32(9, 8)
#define  MR6_DDR4_TCCD_L          GENMASK_32(12, 10)
#define  MR6_DDR4_RSVD_15_13      GENMASK_32(15, 13)
#define  MR6_DDR4_RESERVED_31_16  GENMASK_32(31, 16)

#define DDR_PHY_MR6_LPDDR2       0x600108198
#define  MR6_LPDDR2_RSVD_15_0     GENMASK_32(15, 0)
#define  MR6_LPDDR2_RESERVED_31_16 GENMASK_32(31, 16)

#define DDR_PHY_MR6_LPDDR3       0x600108198
#define  MR6_LPDDR3_RSVD_15_0     GENMASK_32(15, 0)
#define  MR6_LPDDR3_RESERVED_31_16 GENMASK_32(31, 16)

#define DDR_PHY_MR7              0x60010819c
#define  MR7_RSVD_15_0            GENMASK_32(15, 0)
#define  MR7_RESERVED_31_16       GENMASK_32(31, 16)

#define DDR_PHY_MR7_DDR4         0x60010819c
#define  MR7_DDR4_RSVD_15_0       GENMASK_32(15, 0)
#define  MR7_DDR4_RESERVED_31_16  GENMASK_32(31, 16)

#define DDR_PHY_MR7_LPDDR2       0x60010819c
#define  MR7_LPDDR2_RSVD_15_0     GENMASK_32(15, 0)
#define  MR7_LPDDR2_RESERVED_31_16 GENMASK_32(31, 16)

#define DDR_PHY_MR7_LPDDR3       0x60010819c
#define  MR7_LPDDR3_RSVD_15_0     GENMASK_32(15, 0)
#define  MR7_LPDDR3_RESERVED_31_16 GENMASK_32(31, 16)

#define DDR_PHY_MR11             0x6001081ac
#define  MR11_RSVD_15_0           GENMASK_32(15, 0)
#define  MR11_RESERVED_31_16      GENMASK_32(31, 16)

#define DDR_PHY_MR11_DDR4        0x6001081ac
#define  MR11_DDR4_RSVD_15_0      GENMASK_32(15, 0)
#define  MR11_DDR4_RESERVED_31_16 GENMASK_32(31, 16)

#define DDR_PHY_MR11_LPDDR2      0x6001081ac
#define  MR11_LPDDR2_RSVD_15_0    GENMASK_32(15, 0)
#define  MR11_LPDDR2_RESERVED_31_16 GENMASK_32(31, 16)

#define DDR_PHY_MR11_LPDDR3      0x6001081ac
#define  MR11_LPDDR3_DQODT        GENMASK_32(1, 0)
#define  MR11_LPDDR3_PDCTL        BIT_32(2)
#define  MR11_LPDDR3_RSVD_15_0    GENMASK_32(15, 3)
#define  MR11_LPDDR3_RESERVED_31_16 GENMASK_32(31, 16)

#define DDR_PHY_DTCR0            0x600108200
#define  DTCR0_DTRPTN             GENMASK_32(3, 0)
#define  DTCR0_RESERVED_5_4       GENMASK_32(5, 4)
#define  DTCR0_DTMPR              BIT_32(6)
#define  DTCR0_DTCMPD             BIT_32(7)
#define  DTCR0_RESERVED_10_8      GENMASK_32(10, 8)
#define  DTCR0_DTDBS4             BIT_32(11)
#define  DTCR0_DTWBDDM            BIT_32(12)
#define  DTCR0_DTBDC              BIT_32(13)
#define  DTCR0_DTRDBITR           GENMASK_32(15, 14)
#define  DTCR0_DTDBS              GENMASK_32(19, 16)
#define  DTCR0_DTDEN              BIT_32(20)
#define  DTCR0_DTDSTP             BIT_32(21)
#define  DTCR0_DTEXD              BIT_32(22)
#define  DTCR0_DTEXG              BIT_32(23)
#define  DTCR0_DTDRS              GENMASK_32(25, 24)
#define  DTCR0_RESERVED_27_26     GENMASK_32(27, 26)
#define  DTCR0_RFSHDT             GENMASK_32(31, 28)

#define DDR_PHY_DTCR1            0x600108204
#define  DTCR1_BSTEN              BIT_32(0)
#define  DTCR1_RDLVLEN            BIT_32(1)
#define  DTCR1_RDPRMBL_TRN        BIT_32(2)
#define  DTCR1_RESERVED_3         BIT_32(3)
#define  DTCR1_RDLVLGS            GENMASK_32(6, 4)
#define  DTCR1_RESERVED_7         BIT_32(7)
#define  DTCR1_RDLVLGDIFF         GENMASK_32(10, 8)
#define  DTCR1_RESERVED_11        BIT_32(11)
#define  DTCR1_DTRANK             GENMASK_32(13, 12)
#define  DTCR1_RESERVED_15_14     GENMASK_32(15, 14)
#define  DTCR1_RANKEN             GENMASK_32(17, 16)
#define  DTCR1_RANKEN_RSVD        GENMASK_32(31, 18)

#define DDR_PHY_DTAR0            0x600108208
#define  DTAR0_DTROW              GENMASK_32(17, 0)
#define  DTAR0_RESERVED_19_18     GENMASK_32(19, 18)
#define  DTAR0_DTBGBK0            GENMASK_32(23, 20)
#define  DTAR0_DTBGBK1            GENMASK_32(27, 24)
#define  DTAR0_MPRLOC             GENMASK_32(29, 28)
#define  DTAR0_RESERVED_31_30     GENMASK_32(31, 30)

#define DDR_PHY_DTAR1            0x60010820c
#define  DTAR1_DTCOL0             GENMASK_32(8, 0)
#define  DTAR1_RESERVED_15_9      GENMASK_32(15, 9)
#define  DTAR1_DTCOL1             GENMASK_32(24, 16)
#define  DTAR1_RESERVED_31_25     GENMASK_32(31, 25)

#define DDR_PHY_DTAR2            0x600108210
#define  DTAR2_DTCOL2             GENMASK_32(8, 0)
#define  DTAR2_RESERVED_15_9      GENMASK_32(15, 9)
#define  DTAR2_DTCOL3             GENMASK_32(24, 16)
#define  DTAR2_RESERVED_31_25     GENMASK_32(31, 25)

#define DDR_PHY_DTDR0            0x600108218
#define  DTDR0_DTBYTE0            GENMASK_32(7, 0)
#define  DTDR0_DTBYTE1            GENMASK_32(15, 8)
#define  DTDR0_DTBYTE2            GENMASK_32(23, 16)
#define  DTDR0_DTBYTE3            GENMASK_32(31, 24)

#define DDR_PHY_DTDR1            0x60010821c
#define  DTDR1_DTBYTE4            GENMASK_32(7, 0)
#define  DTDR1_DTBYTE5            GENMASK_32(15, 8)
#define  DTDR1_DTBYTE6            GENMASK_32(23, 16)
#define  DTDR1_DTBYTE7            GENMASK_32(31, 24)

#define DDR_PHY_UDDR0            0x600108220
#define  UDDR0_UDBEAT0            GENMASK_32(7, 0)
#define  UDDR0_UDBEAT1            GENMASK_32(15, 8)
#define  UDDR0_UDBEAT2            GENMASK_32(23, 16)
#define  UDDR0_UDBEAT3            GENMASK_32(31, 24)

#define DDR_PHY_UDDR1            0x600108224
#define  UDDR1_UDBEAT4            GENMASK_32(7, 0)
#define  UDDR1_UDBEAT5            GENMASK_32(15, 8)
#define  UDDR1_UDBEAT6            GENMASK_32(23, 16)
#define  UDDR1_UDBEAT7            GENMASK_32(31, 24)

#define DDR_PHY_DTEDR0           0x600108230
#define  DTEDR0_DTWLMN            GENMASK_32(8, 0)
#define  DTEDR0_DTWLMX            GENMASK_32(17, 9)
#define  DTEDR0_DTWBMN            GENMASK_32(23, 18)
#define  DTEDR0_DTWBMX            GENMASK_32(29, 24)
#define  DTEDR0_RESERVED_31_30    GENMASK_32(31, 30)

#define DDR_PHY_DTEDR1           0x600108234
#define  DTEDR1_DTRLMN            GENMASK_32(8, 0)
#define  DTEDR1_DTRLMX            GENMASK_32(17, 9)
#define  DTEDR1_DTRBMN            GENMASK_32(23, 18)
#define  DTEDR1_DTRBMX            GENMASK_32(29, 24)
#define  DTEDR1_RESERVED_31_30    GENMASK_32(31, 30)

#define DDR_PHY_DTEDR2           0x600108238
#define  DTEDR2_DTRLMN            GENMASK_32(8, 0)
#define  DTEDR2_DTRLMX            GENMASK_32(17, 9)
#define  DTEDR2_DTRBMN            GENMASK_32(23, 18)
#define  DTEDR2_DTRBMX            GENMASK_32(29, 24)
#define  DTEDR2_RESERVED_31_30    GENMASK_32(31, 30)

#define DDR_PHY_VTDR             0x60010823c
#define  VTDR_DVREFMN             GENMASK_32(5, 0)
#define  VTDR_RESERVED_7_6        GENMASK_32(7, 6)
#define  VTDR_DVREFMX             GENMASK_32(13, 8)
#define  VTDR_RESERVED_15_14      GENMASK_32(15, 14)
#define  VTDR_HVREFMN             GENMASK_32(21, 16)
#define  VTDR_RESERVED_23_22      GENMASK_32(23, 22)
#define  VTDR_HVREFMX             GENMASK_32(29, 24)
#define  VTDR_RESERVED_31_30      GENMASK_32(31, 30)

#define DDR_PHY_CATR0            0x600108240
#define  CATR0_CA1BYTE0           GENMASK_32(3, 0)
#define  CATR0_CA1BYTE1           GENMASK_32(7, 4)
#define  CATR0_CAADR              GENMASK_32(12, 8)
#define  CATR0_RESERVED_15_13     GENMASK_32(15, 13)
#define  CATR0_CACD               GENMASK_32(20, 16)
#define  CATR0_RESERVED_31_21     GENMASK_32(31, 21)

#define DDR_PHY_CATR1            0x600108244
#define  CATR1_CAENT              GENMASK_32(3, 0)
#define  CATR1_CAEXT              GENMASK_32(7, 4)
#define  CATR1_CACKEL             GENMASK_32(11, 8)
#define  CATR1_CACKEH             GENMASK_32(15, 12)
#define  CATR1_CAMRZ              GENMASK_32(19, 16)
#define  CATR1_CA0BYTE0           GENMASK_32(23, 20)
#define  CATR1_CA0BYTE1           GENMASK_32(27, 24)
#define  CATR1_RESERVED_31_28     GENMASK_32(31, 28)

#define DDR_PHY_DQSDR0           0x600108250
#define  DQSDR0_DFTDTEN           BIT_32(0)
#define  DQSDR0_DFTDTMODE         BIT_32(1)
#define  DQSDR0_DFTUPMODE         GENMASK_32(3, 2)
#define  DQSDR0_DFTGPULSE         BIT_32(4)
#define  DQSDR0_DFTSRMODE         BIT_32(5)
#define  DQSDR0_DFTPDMODE         BIT_32(6)
#define  DQSDR0_RESERVED_7        BIT_32(7)
#define  DQSDR0_DFTUPDRD          GENMASK_32(11, 8)
#define  DQSDR0_PHYUPDRD          GENMASK_32(15, 12)
#define  DQSDR0_CTLUPDRD          GENMASK_32(19, 16)
#define  DQSDR0_DFTRDSPC          GENMASK_32(21, 20)
#define  DQSDR0_DFTIDLRD          GENMASK_32(25, 22)
#define  DQSDR0_DFTDDLUP          BIT_32(26)
#define  DQSDR0_DFTZQUP           BIT_32(27)
#define  DQSDR0_DFTDLY            GENMASK_32(31, 28)

#define DDR_PHY_DQSDR1           0x600108254
#define  DQSDR1_DFTRDIDLC         GENMASK_32(7, 0)
#define  DQSDR1_DFTRDB2BC         GENMASK_32(15, 8)
#define  DQSDR1_DFTRDIDLF         GENMASK_32(19, 16)
#define  DQSDR1_DFTRDB2BF         GENMASK_32(23, 20)
#define  DQSDR1_PUDFTUP           BIT_32(24)
#define  DQSDR1_CUDFTUP           BIT_32(25)
#define  DQSDR1_DFTB2BRD          GENMASK_32(29, 26)
#define  DQSDR1_RESERVED_31_30    GENMASK_32(31, 30)

#define DDR_PHY_DQSDR2           0x600108258
#define  DQSDR2_DFTMNTPRD         GENMASK_32(15, 0)
#define  DQSDR2_DFTTHRSH          GENMASK_32(23, 16)
#define  DQSDR2_RESERVED_31_24    GENMASK_32(31, 24)

#define DDR_PHY_DCUAR            0x600108300
#define  DCUAR_CWADDR_W           GENMASK_32(3, 0)
#define  DCUAR_CSADDR_W           GENMASK_32(7, 4)
#define  DCUAR_CSEL               GENMASK_32(9, 8)
#define  DCUAR_INCA               BIT_32(10)
#define  DCUAR_ATYPE              BIT_32(11)
#define  DCUAR_CWADDR_R           GENMASK_32(15, 12)
#define  DCUAR_CSADDR_R           GENMASK_32(19, 16)
#define  DCUAR_RESERVED_31_20     GENMASK_32(31, 20)

#define DDR_PHY_DCUDR            0x600108304
#define  DCUDR_CDATA              GENMASK_32(31, 0)

#define DDR_PHY_DCURR            0x600108308
#define  DCURR_DINST              GENMASK_32(3, 0)
#define  DCURR_SADDR              GENMASK_32(7, 4)
#define  DCURR_EADDR              GENMASK_32(11, 8)
#define  DCURR_NFAIL              GENMASK_32(19, 12)
#define  DCURR_SONF               BIT_32(20)
#define  DCURR_SCOF               BIT_32(21)
#define  DCURR_RCEN               BIT_32(22)
#define  DCURR_XCEN               BIT_32(23)
#define  DCURR_RESERVED_31_24     GENMASK_32(31, 24)

#define DDR_PHY_DCULR            0x60010830c
#define  DCULR_LSADDR             GENMASK_32(3, 0)
#define  DCULR_LEADDR             GENMASK_32(7, 4)
#define  DCULR_LCNT               GENMASK_32(15, 8)
#define  DCULR_LINF               BIT_32(16)
#define  DCULR_IDA                BIT_32(17)
#define  DCULR_RESERVED_27_18     GENMASK_32(27, 18)
#define  DCULR_XLEADDR            GENMASK_32(31, 28)

#define DDR_PHY_DCUGCR           0x600108310
#define  DCUGCR_RCSW              GENMASK_32(15, 0)
#define  DCUGCR_RESERVED_31_16    GENMASK_32(31, 16)

#define DDR_PHY_DCUTPR           0x600108314
#define  DCUTPR_TDCUT0            GENMASK_32(7, 0)
#define  DCUTPR_TDCUT1            GENMASK_32(15, 8)
#define  DCUTPR_TDCUT2            GENMASK_32(23, 16)
#define  DCUTPR_RESERVED_31_24    GENMASK_32(31, 24)

#define DDR_PHY_DCUSR0           0x600108318
#define  DCUSR0_RDONE             BIT_32(0)
#define  DCUSR0_CFAIL             BIT_32(1)
#define  DCUSR0_CFULL             BIT_32(2)
#define  DCUSR0_RESERVED_31_3     GENMASK_32(31, 3)

#define DDR_PHY_DCUSR1           0x60010831c
#define  DCUSR1_RDCNT             GENMASK_32(15, 0)
#define  DCUSR1_FLCNT             GENMASK_32(23, 16)
#define  DCUSR1_LPCNT             GENMASK_32(31, 24)

#define DDR_PHY_BISTRR           0x600108400
#define  BISTRR_BINST             GENMASK_32(2, 0)
#define  BISTRR_BMODE             BIT_32(3)
#define  BISTRR_BINF              BIT_32(4)
#define  BISTRR_NFAIL             GENMASK_32(12, 5)
#define  BISTRR_BSONF             BIT_32(13)
#define  BISTRR_BDXEN             BIT_32(14)
#define  BISTRR_BACEN             BIT_32(15)
#define  BISTRR_BDMEN             BIT_32(16)
#define  BISTRR_BDPAT             GENMASK_32(21, 17)
#define  BISTRR_BDXSEL            GENMASK_32(25, 22)
#define  BISTRR_BCKSEL            GENMASK_32(27, 26)
#define  BISTRR_BCCSEL            GENMASK_32(29, 28)
#define  BISTRR_BSOMA             BIT_32(30)
#define  BISTRR_RESERVED_31       BIT_32(31)

#define DDR_PHY_BISTWCR          0x600108404
#define  BISTWCR_BWCNT            GENMASK_32(15, 0)
#define  BISTWCR_RESERVED_31_16   GENMASK_32(31, 16)

#define DDR_PHY_BISTMSKR0        0x600108408
#define  BISTMSKR0_AMSK           GENMASK_32(17, 0)
#define  BISTMSKR0_RESERVED_18    BIT_32(18)
#define  BISTMSKR0_ACTMSK         BIT_32(19)
#define  BISTMSKR0_CSMSK          GENMASK_32(21, 20)
#define  BISTMSKR0_CSMSK_RSVD     GENMASK_32(31, 22)

#define DDR_PHY_BISTMSKR1        0x60010840c
#define  BISTMSKR1_X4DMMSK        GENMASK_32(3, 0)
#define  BISTMSKR1_BAMSK          GENMASK_32(7, 4)
#define  BISTMSKR1_CKEMSK         GENMASK_32(9, 8)
#define  BISTMSKR1_CKEMSK_RSVD    GENMASK_32(15, 10)
#define  BISTMSKR1_ODTMSK         GENMASK_32(17, 16)
#define  BISTMSKR1_ODTMSK_RSVD    GENMASK_32(23, 18)
#define  BISTMSKR1_CIDMSK         BIT_32(24)
#define  BISTMSKR1_CIDMSK_RSVD    GENMASK_32(26, 25)
#define  BISTMSKR1_PARINMSK       BIT_32(27)
#define  BISTMSKR1_DMMSK          GENMASK_32(31, 28)

#define DDR_PHY_BISTMSKR2        0x600108410
#define  BISTMSKR2_DQMSK          GENMASK_32(31, 0)

#define DDR_PHY_BISTLSR          0x600108414
#define  BISTLSR_SEED             GENMASK_32(31, 0)

#define DDR_PHY_BISTAR0          0x600108418
#define  BISTAR0_BCOL             GENMASK_32(11, 0)
#define  BISTAR0_RESERVED_27_12   GENMASK_32(27, 12)
#define  BISTAR0_BBANK            GENMASK_32(31, 28)

#define DDR_PHY_BISTAR1          0x60010841c
#define  BISTAR1_BRANK            GENMASK_32(3, 0)
#define  BISTAR1_BAINC            GENMASK_32(15, 4)
#define  BISTAR1_BMRANK           GENMASK_32(19, 16)
#define  BISTAR1_RESERVED_31_20   GENMASK_32(31, 20)

#define DDR_PHY_BISTAR2          0x600108420
#define  BISTAR2_BMCOL            GENMASK_32(11, 0)
#define  BISTAR2_RESERVED_27_12   GENMASK_32(27, 12)
#define  BISTAR2_BMBANK           GENMASK_32(31, 28)

#define DDR_PHY_BISTAR3          0x600108424
#define  BISTAR3_BROW             GENMASK_32(17, 0)
#define  BISTAR3_RESERVED_31_18   GENMASK_32(31, 18)

#define DDR_PHY_BISTAR4          0x600108428
#define  BISTAR4_BMROW            GENMASK_32(17, 0)
#define  BISTAR4_RESERVED_31_18   GENMASK_32(31, 18)

#define DDR_PHY_BISTUDPR         0x60010842c
#define  BISTUDPR_BUDP0           GENMASK_32(15, 0)
#define  BISTUDPR_BUDP1           GENMASK_32(31, 16)

#define DDR_PHY_BISTGSR          0x600108430
#define  BISTGSR_BDONE            BIT_32(0)
#define  BISTGSR_BACERR           BIT_32(1)
#define  BISTGSR_BDXERR           GENMASK_32(10, 2)
#define  BISTGSR_X4DMBER          GENMASK_32(14, 11)
#define  BISTGSR_RESERVED_19_15   GENMASK_32(19, 15)
#define  BISTGSR_DMBER            GENMASK_32(23, 20)
#define  BISTGSR_RESERVED_27_24   GENMASK_32(27, 24)
#define  BISTGSR_RASBER           BIT_32(28)
#define  BISTGSR_RESERVED_29      BIT_32(29)
#define  BISTGSR_PARBER           BIT_32(30)
#define  BISTGSR_RESERVED_31      BIT_32(31)

#define DDR_PHY_BISTWER0         0x600108434
#define  BISTWER0_ACWER           GENMASK_32(17, 0)
#define  BISTWER0_RESERVED_31_18  GENMASK_32(31, 18)

#define DDR_PHY_BISTWER1         0x600108438
#define  BISTWER1_DXWER           GENMASK_32(15, 0)
#define  BISTWER1_RESERVED_31_16  GENMASK_32(31, 16)

#define DDR_PHY_BISTBER0         0x60010843c
#define  BISTBER0_ABER            GENMASK_32(15, 0)
#define  BISTBER0_RESERVED_31_16  GENMASK_32(31, 16)

#define DDR_PHY_BISTBER1         0x600108440
#define  BISTBER1_BABER           GENMASK_32(3, 0)
#define  BISTBER1_RESERVED_7_4    GENMASK_32(7, 4)
#define  BISTBER1_CSBER           GENMASK_32(19, 8)
#define  BISTBER1_RESERVED_31_20  GENMASK_32(31, 20)

#define DDR_PHY_BISTBER2         0x600108444
#define  BISTBER2_DQBER0          GENMASK_32(15, 0)
#define  BISTBER2_RESERVED_31_16  GENMASK_32(31, 16)

#define DDR_PHY_BISTBER3         0x600108448
#define  BISTBER3_DQBER1          GENMASK_32(15, 0)
#define  BISTBER3_RESERVED_31_16  GENMASK_32(31, 16)

#define DDR_PHY_BISTBER4         0x60010844c
#define  BISTBER4_ABER            GENMASK_32(1, 0)
#define  BISTBER4_RESERVED_7_2    GENMASK_32(7, 2)
#define  BISTBER4_CIDBER          GENMASK_32(10, 8)
#define  BISTBER4_RESERVED_31_11  GENMASK_32(31, 11)

#define DDR_PHY_BISTWCSR         0x600108450
#define  BISTWCSR_ACWCNT          GENMASK_32(15, 0)
#define  BISTWCSR_DXWCNT          GENMASK_32(31, 16)

#define DDR_PHY_BISTFWR0         0x600108454
#define  BISTFWR0_AWEBS           GENMASK_32(17, 0)
#define  BISTFWR0_ACTWEBS         BIT_32(18)
#define  BISTFWR0_RESERVED_19     BIT_32(19)
#define  BISTFWR0_CSWEBS          GENMASK_32(31, 20)

#define DDR_PHY_BISTFWR1         0x600108458
#define  BISTFWR1_CKEWEBS         GENMASK_32(7, 0)
#define  BISTFWR1_ODTWEBS         GENMASK_32(15, 8)
#define  BISTFWR1_BAWEBS          GENMASK_32(19, 16)
#define  BISTFWR1_CIDWEBS         GENMASK_32(22, 20)
#define  BISTFWR1_RESERVED_23     BIT_32(23)
#define  BISTFWR1_X4DMWEBS        GENMASK_32(27, 24)
#define  BISTFWR1_DMWEBS          GENMASK_32(31, 28)

#define DDR_PHY_BISTFWR2         0x60010845c
#define  BISTFWR2_DQWEBS          GENMASK_32(31, 0)

#define DDR_PHY_BISTBER5         0x600108460
#define  BISTBER5_CKEBER          GENMASK_32(7, 0)
#define  BISTBER5_RESERVED_15_8   GENMASK_32(15, 8)
#define  BISTBER5_ODTBER          GENMASK_32(23, 16)
#define  BISTBER5_RESERVED_31_24  GENMASK_32(31, 24)

#define DDR_PHY_RANKIDR          0x6001084dc
#define  RANKIDR_RANKWID          GENMASK_32(3, 0)
#define  RANKIDR_RESERVED_15_4    GENMASK_32(15, 4)
#define  RANKIDR_RANKRID          GENMASK_32(19, 16)
#define  RANKIDR_RESERVED_31_20   GENMASK_32(31, 20)

#define DDR_PHY_RIOCR0           0x6001084e0
#define  RIOCR0_CSODT             GENMASK_32(1, 0)
#define  RIOCR0_CSODT_RSVD        GENMASK_32(11, 2)
#define  RIOCR0_RESERVED_15_12    GENMASK_32(15, 12)
#define  RIOCR0_CSPDR             GENMASK_32(17, 16)
#define  RIOCR0_CSPDR_RSVD        GENMASK_32(27, 18)
#define  RIOCR0_RESERVED_31_28    GENMASK_32(31, 28)

#define DDR_PHY_RIOCR1           0x6001084e4
#define  RIOCR1_CKEODT            GENMASK_32(1, 0)
#define  RIOCR1_CKEODT_RSVD       GENMASK_32(7, 2)
#define  RIOCR1_CKEPDR            GENMASK_32(9, 8)
#define  RIOCR1_CKEPDR_RSVD       GENMASK_32(15, 10)
#define  RIOCR1_ODTODT            GENMASK_32(17, 16)
#define  RIOCR1_ODTODT_RSVD       GENMASK_32(23, 18)
#define  RIOCR1_ODTPDR            GENMASK_32(25, 24)
#define  RIOCR1_ODTPDR_RSVD       GENMASK_32(31, 26)

#define DDR_PHY_RIOCR2           0x6001084e8
#define  RIOCR2_CSOEMODE          GENMASK_32(3, 0)
#define  RIOCR2_CSOEMODE_RSVD     GENMASK_32(23, 4)
#define  RIOCR2_COEMODE           GENMASK_32(25, 24)
#define  RIOCR2_COEMODE_RSVD      GENMASK_32(29, 26)
#define  RIOCR2_RESERVED_31_30    GENMASK_32(31, 30)

#define DDR_PHY_RIOCR3           0x6001084ec
#define  RIOCR3_RESERVED_31_0     GENMASK_32(31, 0)

#define DDR_PHY_RIOCR4           0x6001084f0
#define  RIOCR4_CKEOEMODE         GENMASK_32(3, 0)
#define  RIOCR4_CKEOEMODE_RSVD    GENMASK_32(15, 4)
#define  RIOCR4_RESERVED_31_16    GENMASK_32(31, 16)

#define DDR_PHY_RIOCR5           0x6001084f4
#define  RIOCR5_ODTOEMODE         GENMASK_32(3, 0)
#define  RIOCR5_ODTOEMODE_RSVD    GENMASK_32(15, 4)
#define  RIOCR5_RESERVED_31_16    GENMASK_32(31, 16)

#define DDR_PHY_ACIOCR0          0x600108500
#define  ACIOCR0_ACIOM            BIT_32(0)
#define  ACIOCR0_RESERVED_1       BIT_32(1)
#define  ACIOCR0_ACODT            BIT_32(2)
#define  ACIOCR0_RESERVED_3       BIT_32(3)
#define  ACIOCR0_ACPDR            BIT_32(4)
#define  ACIOCR0_CKODT            BIT_32(5)
#define  ACIOCR0_CKODT_RSVD       GENMASK_32(8, 6)
#define  ACIOCR0_RESERVED_9       BIT_32(9)
#define  ACIOCR0_CKPDR            BIT_32(10)
#define  ACIOCR0_CKPDR_RSVD       GENMASK_32(13, 11)
#define  ACIOCR0_RESERVED_25_14   GENMASK_32(25, 14)
#define  ACIOCR0_RSTODT           BIT_32(26)
#define  ACIOCR0_RESERVED_27      BIT_32(27)
#define  ACIOCR0_RSTPDR           BIT_32(28)
#define  ACIOCR0_RSTIOM           BIT_32(29)
#define  ACIOCR0_ACSR             GENMASK_32(31, 30)

#define DDR_PHY_ACIOCR1          0x600108504
#define  ACIOCR1_AOEMODE          GENMASK_32(31, 0)

#define DDR_PHY_ACIOCR2          0x600108508
#define  ACIOCR2_RESERVED_31_0    GENMASK_32(31, 0)

#define DDR_PHY_ACIOCR3          0x60010850c
#define  ACIOCR3_CKOEMODE         GENMASK_32(1, 0)
#define  ACIOCR3_CKOEMODE_RSVD    GENMASK_32(7, 2)
#define  ACIOCR3_RESERVED_15_8    GENMASK_32(15, 8)
#define  ACIOCR3_ACTOEMODE        GENMASK_32(17, 16)
#define  ACIOCR3_A16OEMODE        GENMASK_32(19, 18)
#define  ACIOCR3_A17OEMODE        GENMASK_32(21, 20)
#define  ACIOCR3_BAOEMODE         GENMASK_32(25, 22)
#define  ACIOCR3_BGOEMODE         GENMASK_32(29, 26)
#define  ACIOCR3_PAROEMODE        GENMASK_32(31, 30)

#define DDR_PHY_ACIOCR4          0x600108510
#define  ACIOCR4_RESERVED_31_0    GENMASK_32(31, 0)

#define DDR_PHY_IOVCR0           0x600108520
#define  IOVCR0_ACVREFISEL        GENMASK_32(5, 0)
#define  IOVCR0_RESERVED_7_6      GENMASK_32(7, 6)
#define  IOVCR0_ACVREFSSEL        GENMASK_32(13, 8)
#define  IOVCR0_RESERVED_15_14    GENMASK_32(15, 14)
#define  IOVCR0_ACVREFESEL        GENMASK_32(21, 16)
#define  IOVCR0_RESERVED_23_22    GENMASK_32(23, 22)
#define  IOVCR0_ACVREFIEN         BIT_32(24)
#define  IOVCR0_ACVREFSEN         BIT_32(25)
#define  IOVCR0_ACVREFEEN         GENMASK_32(27, 26)
#define  IOVCR0_ACVREFPEN         BIT_32(28)
#define  IOVCR0_ACVREFIOM         GENMASK_32(31, 29)

#define DDR_PHY_IOVCR1           0x600108524
#define  IOVCR1_ZQVREFISEL        GENMASK_32(5, 0)
#define  IOVCR1_RESERVED_7_6      GENMASK_32(7, 6)
#define  IOVCR1_ZQVREFIEN         BIT_32(8)
#define  IOVCR1_ZQVREFPEN         BIT_32(9)
#define  IOVCR1_RESERVED_31_10    GENMASK_32(31, 10)

#define DDR_PHY_VTCR0            0x600108528
#define  VTCR0_DVINIT             GENMASK_32(5, 0)
#define  VTCR0_DVMIN              GENMASK_32(11, 6)
#define  VTCR0_DVMAX              GENMASK_32(17, 12)
#define  VTCR0_DVSS               GENMASK_32(21, 18)
#define  VTCR0_RESERVED_26_22     GENMASK_32(26, 22)
#define  VTCR0_PDAEN              BIT_32(27)
#define  VTCR0_DVEN               BIT_32(28)
#define  VTCR0_TVREF              GENMASK_32(31, 29)

#define DDR_PHY_VTCR1            0x60010852c
#define  VTCR1_HVIO               BIT_32(0)
#define  VTCR1_HVEN               BIT_32(1)
#define  VTCR1_ENUM               BIT_32(2)
#define  VTCR1_EOFF               GENMASK_32(4, 3)
#define  VTCR1_TVREFIO            GENMASK_32(7, 5)
#define  VTCR1_SHREN              BIT_32(8)
#define  VTCR1_SHRNK              GENMASK_32(10, 9)
#define  VTCR1_RESERVED_11        BIT_32(11)
#define  VTCR1_VWCR               GENMASK_32(15, 12)
#define  VTCR1_HVMIN              GENMASK_32(21, 16)
#define  VTCR1_HVMAX              GENMASK_32(27, 22)
#define  VTCR1_HVSS               GENMASK_32(31, 28)

#define DDR_PHY_ACBDLR0          0x600108540
#define  ACBDLR0_CK0BD            GENMASK_32(5, 0)
#define  ACBDLR0_RESERVED_7_6     GENMASK_32(7, 6)
#define  ACBDLR0_CK1BD            GENMASK_32(13, 8)
#define  ACBDLR0_RESERVED_15_14   GENMASK_32(15, 14)
#define  ACBDLR0_CK2BD            GENMASK_32(21, 16)
#define  ACBDLR0_RESERVED_23_22   GENMASK_32(23, 22)
#define  ACBDLR0_CK3BD            GENMASK_32(29, 24)
#define  ACBDLR0_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_ACBDLR1          0x600108544
#define  ACBDLR1_ACTBD            GENMASK_32(5, 0)
#define  ACBDLR1_RESERVED_7_6     GENMASK_32(7, 6)
#define  ACBDLR1_A17BD            GENMASK_32(13, 8)
#define  ACBDLR1_RESERVED_15_14   GENMASK_32(15, 14)
#define  ACBDLR1_A16BD            GENMASK_32(21, 16)
#define  ACBDLR1_RESERVED_23_22   GENMASK_32(23, 22)
#define  ACBDLR1_PARBD            GENMASK_32(29, 24)
#define  ACBDLR1_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_ACBDLR2          0x600108548
#define  ACBDLR2_BA0BD            GENMASK_32(5, 0)
#define  ACBDLR2_RESERVED_7_6     GENMASK_32(7, 6)
#define  ACBDLR2_BA1BD            GENMASK_32(13, 8)
#define  ACBDLR2_RESERVED_15_14   GENMASK_32(15, 14)
#define  ACBDLR2_BG0BD            GENMASK_32(21, 16)
#define  ACBDLR2_RESERVED_23_22   GENMASK_32(23, 22)
#define  ACBDLR2_BG1BD            GENMASK_32(29, 24)
#define  ACBDLR2_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_ACBDLR3          0x60010854c
#define  ACBDLR3_CS0BD            GENMASK_32(5, 0)
#define  ACBDLR3_RESERVED_7_6     GENMASK_32(7, 6)
#define  ACBDLR3_CS1BD            GENMASK_32(13, 8)
#define  ACBDLR3_RESERVED_15_14   GENMASK_32(15, 14)
#define  ACBDLR3_CS2BD            GENMASK_32(21, 16)
#define  ACBDLR3_RESERVED_23_22   GENMASK_32(23, 22)
#define  ACBDLR3_CS3BD            GENMASK_32(29, 24)
#define  ACBDLR3_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_ACBDLR4          0x600108550
#define  ACBDLR4_ODT0BD           GENMASK_32(5, 0)
#define  ACBDLR4_RESERVED_7_6     GENMASK_32(7, 6)
#define  ACBDLR4_ODT1BD           GENMASK_32(13, 8)
#define  ACBDLR4_RESERVED_15_14   GENMASK_32(15, 14)
#define  ACBDLR4_ODT2BD           GENMASK_32(21, 16)
#define  ACBDLR4_RESERVED_23_22   GENMASK_32(23, 22)
#define  ACBDLR4_ODT3BD           GENMASK_32(29, 24)
#define  ACBDLR4_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_ACBDLR5          0x600108554
#define  ACBDLR5_CKE0BD           GENMASK_32(5, 0)
#define  ACBDLR5_RESERVED_7_6     GENMASK_32(7, 6)
#define  ACBDLR5_CKE1BD           GENMASK_32(13, 8)
#define  ACBDLR5_RESERVED_15_14   GENMASK_32(15, 14)
#define  ACBDLR5_CKE2BD           GENMASK_32(21, 16)
#define  ACBDLR5_RESERVED_23_22   GENMASK_32(23, 22)
#define  ACBDLR5_CKE3BD           GENMASK_32(29, 24)
#define  ACBDLR5_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_ACBDLR6          0x600108558
#define  ACBDLR6_A00BD            GENMASK_32(5, 0)
#define  ACBDLR6_RESERVED_7_6     GENMASK_32(7, 6)
#define  ACBDLR6_A01BD            GENMASK_32(13, 8)
#define  ACBDLR6_RESERVED_15_14   GENMASK_32(15, 14)
#define  ACBDLR6_A02BD            GENMASK_32(21, 16)
#define  ACBDLR6_RESERVED_23_22   GENMASK_32(23, 22)
#define  ACBDLR6_A03BD            GENMASK_32(29, 24)
#define  ACBDLR6_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_ACBDLR7          0x60010855c
#define  ACBDLR7_A04BD            GENMASK_32(5, 0)
#define  ACBDLR7_RESERVED_7_6     GENMASK_32(7, 6)
#define  ACBDLR7_A05BD            GENMASK_32(13, 8)
#define  ACBDLR7_RESERVED_15_14   GENMASK_32(15, 14)
#define  ACBDLR7_A06BD            GENMASK_32(21, 16)
#define  ACBDLR7_RESERVED_23_22   GENMASK_32(23, 22)
#define  ACBDLR7_A07BD            GENMASK_32(29, 24)
#define  ACBDLR7_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_ACBDLR8          0x600108560
#define  ACBDLR8_A08BD            GENMASK_32(5, 0)
#define  ACBDLR8_RESERVED_7_6     GENMASK_32(7, 6)
#define  ACBDLR8_A09BD            GENMASK_32(13, 8)
#define  ACBDLR8_RESERVED_15_14   GENMASK_32(15, 14)
#define  ACBDLR8_A10BD            GENMASK_32(21, 16)
#define  ACBDLR8_RESERVED_23_22   GENMASK_32(23, 22)
#define  ACBDLR8_A11BD            GENMASK_32(29, 24)
#define  ACBDLR8_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_ACBDLR9          0x600108564
#define  ACBDLR9_A12BD            GENMASK_32(5, 0)
#define  ACBDLR9_RESERVED_7_6     GENMASK_32(7, 6)
#define  ACBDLR9_A13BD            GENMASK_32(13, 8)
#define  ACBDLR9_RESERVED_15_14   GENMASK_32(15, 14)
#define  ACBDLR9_A14BD            GENMASK_32(21, 16)
#define  ACBDLR9_RESERVED_23_22   GENMASK_32(23, 22)
#define  ACBDLR9_A15BD            GENMASK_32(29, 24)
#define  ACBDLR9_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_ACBDLR10         0x600108568
#define  ACBDLR10_RESERVED_7_0    GENMASK_32(7, 0)
#define  ACBDLR10_CID0BD          GENMASK_32(13, 8)
#define  ACBDLR10_RESERVED_15_14  GENMASK_32(15, 14)
#define  ACBDLR10_CID1BD          GENMASK_32(21, 16)
#define  ACBDLR10_RESERVED_23_22  GENMASK_32(23, 22)
#define  ACBDLR10_CID2BD          GENMASK_32(29, 24)
#define  ACBDLR10_RESERVED_31_30  GENMASK_32(31, 30)

#define DDR_PHY_ACBDLR11         0x60010856c
#define  ACBDLR11_CS4BD           GENMASK_32(5, 0)
#define  ACBDLR11_RESERVED_7_6    GENMASK_32(7, 6)
#define  ACBDLR11_CS5BD           GENMASK_32(13, 8)
#define  ACBDLR11_RESERVED_15_14  GENMASK_32(15, 14)
#define  ACBDLR11_CS6BD           GENMASK_32(21, 16)
#define  ACBDLR11_RESERVED_23_22  GENMASK_32(23, 22)
#define  ACBDLR11_CS7BD           GENMASK_32(29, 24)
#define  ACBDLR11_RESERVED_31_30  GENMASK_32(31, 30)

#define DDR_PHY_ACBDLR12         0x600108570
#define  ACBDLR12_CS8BD           GENMASK_32(5, 0)
#define  ACBDLR12_RESERVED_7_6    GENMASK_32(7, 6)
#define  ACBDLR12_CS9BD           GENMASK_32(13, 8)
#define  ACBDLR12_RESERVED_15_14  GENMASK_32(15, 14)
#define  ACBDLR12_CS10BD          GENMASK_32(21, 16)
#define  ACBDLR12_RESERVED_23_22  GENMASK_32(23, 22)
#define  ACBDLR12_CS11BD          GENMASK_32(29, 24)
#define  ACBDLR12_RESERVED_31_30  GENMASK_32(31, 30)

#define DDR_PHY_ACBDLR13         0x600108574
#define  ACBDLR13_ODT4BD          GENMASK_32(5, 0)
#define  ACBDLR13_RESERVED_7_6    GENMASK_32(7, 6)
#define  ACBDLR13_ODT5BD          GENMASK_32(13, 8)
#define  ACBDLR13_RESERVED_15_14  GENMASK_32(15, 14)
#define  ACBDLR13_ODT6BD          GENMASK_32(21, 16)
#define  ACBDLR13_RESERVED_23_22  GENMASK_32(23, 22)
#define  ACBDLR13_ODT7BD          GENMASK_32(29, 24)
#define  ACBDLR13_RESERVED_31_30  GENMASK_32(31, 30)

#define DDR_PHY_ACBDLR14         0x600108578
#define  ACBDLR14_CKE4BD          GENMASK_32(5, 0)
#define  ACBDLR14_RESERVED_7_6    GENMASK_32(7, 6)
#define  ACBDLR14_CKE5BD          GENMASK_32(13, 8)
#define  ACBDLR14_RESERVED_15_14  GENMASK_32(15, 14)
#define  ACBDLR14_CKE6BD          GENMASK_32(21, 16)
#define  ACBDLR14_RESERVED_23_22  GENMASK_32(23, 22)
#define  ACBDLR14_CKE7BD          GENMASK_32(29, 24)
#define  ACBDLR14_RESERVED_31_30  GENMASK_32(31, 30)

#define DDR_PHY_ACLCDLR          0x600108580
#define  ACLCDLR_ACD              GENMASK_32(8, 0)
#define  ACLCDLR_RESERVED_31_9    GENMASK_32(31, 9)

#define DDR_PHY_ACMDLR0          0x6001085a0
#define  ACMDLR0_IPRD             GENMASK_32(8, 0)
#define  ACMDLR0_RESERVED_15_9    GENMASK_32(15, 9)
#define  ACMDLR0_TPRD             GENMASK_32(24, 16)
#define  ACMDLR0_RESERVED_31_25   GENMASK_32(31, 25)

#define DDR_PHY_ACMDLR1          0x6001085a4
#define  ACMDLR1_MDLD             GENMASK_32(8, 0)
#define  ACMDLR1_RESERVED_31_9    GENMASK_32(31, 9)

#define DDR_PHY_ZQCR             0x600108680
#define  ZQCR_RESERVED_0          BIT_32(0)
#define  ZQCR_TERM_OFF            BIT_32(1)
#define  ZQCR_ZQPD                BIT_32(2)
#define  ZQCR_RESERVED_7_3        GENMASK_32(7, 3)
#define  ZQCR_PGWAIT              GENMASK_32(10, 8)
#define  ZQCR_ZCALT               GENMASK_32(13, 11)
#define  ZQCR_AVGMAX              GENMASK_32(15, 14)
#define  ZQCR_AVGEN               BIT_32(16)
#define  ZQCR_IODLMT              GENMASK_32(23, 17)
#define  ZQCR_ASYM_DRV_EN         BIT_32(24)
#define  ZQCR_PU_ODT_ONLY         BIT_32(25)
#define  ZQCR_DIS_NON_LIN_COMP    BIT_32(26)
#define  ZQCR_FORCE_ZCAL_VT_UPDATE BIT_32(27)
#define  ZQCR_ZCTRL_UPPER         GENMASK_32(31, 28)

#define DDR_PHY_ZQ0PR            0x600108684
#define  ZQ0PR_ZQDIV              GENMASK_32(7, 0)
#define  ZQ0PR_ZPROG_ASYM_DRV_PU  GENMASK_32(11, 8)
#define  ZQ0PR_ZPROG_ASYM_DRV_PD  GENMASK_32(15, 12)
#define  ZQ0PR_ZPROG_PU_ODT_ONLY  GENMASK_32(19, 16)
#define  ZQ0PR_PU_DRV_ADJUST      GENMASK_32(21, 20)
#define  ZQ0PR_PD_DRV_ADJUST      GENMASK_32(23, 22)
#define  ZQ0PR_ZCTRL_UPPER        GENMASK_32(27, 24)
#define  ZQ0PR_RESERVED_31_28     GENMASK_32(31, 28)

#define DDR_PHY_ZQ0DR            0x600108688
#define  ZQ0DR_ZDATA              GENMASK_32(27, 0)
#define  ZQ0DR_RESERVED_28        BIT_32(28)
#define  ZQ0DR_ZSEGBYP            BIT_32(29)
#define  ZQ0DR_ODT_ZDEN           BIT_32(30)
#define  ZQ0DR_DRV_ZDEN           BIT_32(31)

#define DDR_PHY_ZQ0SR            0x60010868c
#define  ZQ0SR_ZPD                GENMASK_32(1, 0)
#define  ZQ0SR_ZPU                GENMASK_32(3, 2)
#define  ZQ0SR_OPD                GENMASK_32(5, 4)
#define  ZQ0SR_OPU                GENMASK_32(7, 6)
#define  ZQ0SR_ZERR               BIT_32(8)
#define  ZQ0SR_ZDONE              BIT_32(9)
#define  ZQ0SR_PU_DRV_SAT         BIT_32(10)
#define  ZQ0SR_PD_DRV_SAT         BIT_32(11)
#define  ZQ0SR_RESERVED_31_12     GENMASK_32(31, 12)

#define DDR_PHY_ZQ1PR            0x600108694
#define  ZQ1PR_ZQDIV              GENMASK_32(7, 0)
#define  ZQ1PR_ZPROG_ASYM_DRV_PU  GENMASK_32(11, 8)
#define  ZQ1PR_ZPROG_ASYM_DRV_PD  GENMASK_32(15, 12)
#define  ZQ1PR_ZPROG_PU_ODT_ONLY  GENMASK_32(19, 16)
#define  ZQ1PR_PU_DRV_ADJUST      GENMASK_32(21, 20)
#define  ZQ1PR_PD_DRV_ADJUST      GENMASK_32(23, 22)
#define  ZQ1PR_ZCTRL_UPPER        GENMASK_32(27, 24)
#define  ZQ1PR_RESERVED_31_28     GENMASK_32(31, 28)

#define DDR_PHY_ZQ1DR            0x600108698
#define  ZQ1DR_ZDATA              GENMASK_32(27, 0)
#define  ZQ1DR_RESERVED_28        BIT_32(28)
#define  ZQ1DR_ZSEGBYP            BIT_32(29)
#define  ZQ1DR_ODT_ZDEN           BIT_32(30)
#define  ZQ1DR_DRV_ZDEN           BIT_32(31)

#define DDR_PHY_ZQ1SR            0x60010869c
#define  ZQ1SR_ZPD                GENMASK_32(1, 0)
#define  ZQ1SR_ZPU                GENMASK_32(3, 2)
#define  ZQ1SR_OPD                GENMASK_32(5, 4)
#define  ZQ1SR_OPU                GENMASK_32(7, 6)
#define  ZQ1SR_ZERR               BIT_32(8)
#define  ZQ1SR_ZDONE              BIT_32(9)
#define  ZQ1SR_PU_DRV_SAT         BIT_32(10)
#define  ZQ1SR_PD_DRV_SAT         BIT_32(11)
#define  ZQ1SR_RESERVED_31_12     GENMASK_32(31, 12)

#define DDR_PHY_ZQ2PR            0x6001086a4
#define  ZQ2PR_ZQDIV              GENMASK_32(7, 0)
#define  ZQ2PR_ZPROG_ASYM_DRV_PU  GENMASK_32(11, 8)
#define  ZQ2PR_ZPROG_ASYM_DRV_PD  GENMASK_32(15, 12)
#define  ZQ2PR_ZPROG_PU_ODT_ONLY  GENMASK_32(19, 16)
#define  ZQ2PR_PU_DRV_ADJUST      GENMASK_32(21, 20)
#define  ZQ2PR_PD_DRV_ADJUST      GENMASK_32(23, 22)
#define  ZQ2PR_ZCTRL_UPPER        GENMASK_32(27, 24)
#define  ZQ2PR_RESERVED_31_28     GENMASK_32(31, 28)

#define DDR_PHY_ZQ2DR            0x6001086a8
#define  ZQ2DR_ZDATA              GENMASK_32(27, 0)
#define  ZQ2DR_RESERVED_28        BIT_32(28)
#define  ZQ2DR_ZSEGBYP            BIT_32(29)
#define  ZQ2DR_ODT_ZDEN           BIT_32(30)
#define  ZQ2DR_DRV_ZDEN           BIT_32(31)

#define DDR_PHY_ZQ2SR            0x6001086ac
#define  ZQ2SR_ZPD                GENMASK_32(1, 0)
#define  ZQ2SR_ZPU                GENMASK_32(3, 2)
#define  ZQ2SR_OPD                GENMASK_32(5, 4)
#define  ZQ2SR_OPU                GENMASK_32(7, 6)
#define  ZQ2SR_ZERR               BIT_32(8)
#define  ZQ2SR_ZDONE              BIT_32(9)
#define  ZQ2SR_PU_DRV_SAT         BIT_32(10)
#define  ZQ2SR_PD_DRV_SAT         BIT_32(11)
#define  ZQ2SR_RESERVED_31_12     GENMASK_32(31, 12)

#define DDR_PHY_ZQ3PR            0x6001086b4
#define  ZQ3PR_ZQDIV              GENMASK_32(7, 0)
#define  ZQ3PR_ZPROG_ASYM_DRV_PU  GENMASK_32(11, 8)
#define  ZQ3PR_ZPROG_ASYM_DRV_PD  GENMASK_32(15, 12)
#define  ZQ3PR_ZPROG_PU_ODT_ONLY  GENMASK_32(19, 16)
#define  ZQ3PR_PU_DRV_ADJUST      GENMASK_32(21, 20)
#define  ZQ3PR_PD_DRV_ADJUST      GENMASK_32(23, 22)
#define  ZQ3PR_ZCTRL_UPPER        GENMASK_32(27, 24)
#define  ZQ3PR_RESERVED_31_28     GENMASK_32(31, 28)

#define DDR_PHY_ZQ3DR            0x6001086b8
#define  ZQ3DR_ZDATA              GENMASK_32(27, 0)
#define  ZQ3DR_RESERVED_28        BIT_32(28)
#define  ZQ3DR_ZSEGBYP            BIT_32(29)
#define  ZQ3DR_ODT_ZDEN           BIT_32(30)
#define  ZQ3DR_DRV_ZDEN           BIT_32(31)

#define DDR_PHY_ZQ3SR            0x6001086bc
#define  ZQ3SR_ZPD                GENMASK_32(1, 0)
#define  ZQ3SR_ZPU                GENMASK_32(3, 2)
#define  ZQ3SR_OPD                GENMASK_32(5, 4)
#define  ZQ3SR_OPU                GENMASK_32(7, 6)
#define  ZQ3SR_ZERR               BIT_32(8)
#define  ZQ3SR_ZDONE              BIT_32(9)
#define  ZQ3SR_PU_DRV_SAT         BIT_32(10)
#define  ZQ3SR_PD_DRV_SAT         BIT_32(11)
#define  ZQ3SR_RESERVED_31_12     GENMASK_32(31, 12)

#define DDR_PHY_DX0GCR0          0x600108700
#define  DX0GCR0_DXEN             BIT_32(0)
#define  DX0GCR0_DXIOM            BIT_32(1)
#define  DX0GCR0_DQSGOE           BIT_32(2)
#define  DX0GCR0_DQSGODT          BIT_32(3)
#define  DX0GCR0_RESERVED_4       BIT_32(4)
#define  DX0GCR0_DQSGPDR          BIT_32(5)
#define  DX0GCR0_RESERVED_6       BIT_32(6)
#define  DX0GCR0_PDRAL            GENMASK_32(8, 7)
#define  DX0GCR0_RTTOH            GENMASK_32(10, 9)
#define  DX0GCR0_RTTOAL           BIT_32(11)
#define  DX0GCR0_DQSSEPDR         BIT_32(12)
#define  DX0GCR0_DQSNSEPDR        BIT_32(13)
#define  DX0GCR0_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX0GCR0_PLLRST           BIT_32(16)
#define  DX0GCR0_PLLPD            BIT_32(17)
#define  DX0GCR0_GSHIFT           BIT_32(18)
#define  DX0GCR0_PLLBYP           BIT_32(19)
#define  DX0GCR0_RDDLY            GENMASK_32(23, 20)
#define  DX0GCR0_RESERVED_29_24   GENMASK_32(29, 24)
#define  DX0GCR0_MDLEN            BIT_32(30)
#define  DX0GCR0_CALBYP           BIT_32(31)

#define DDR_PHY_DX0GCR1          0x600108704
#define  DX0GCR1_RESERVED_15_0    GENMASK_32(15, 0)
#define  DX0GCR1_DXPDRMODE        GENMASK_32(31, 16)

#define DDR_PHY_DX0GCR2          0x600108708
#define  DX0GCR2_DXTEMODE         GENMASK_32(15, 0)
#define  DX0GCR2_DXOEMODE         GENMASK_32(31, 16)

#define DDR_PHY_DX0GCR3          0x60010870c
#define  DX0GCR3_RESERVED_1_0     GENMASK_32(1, 0)
#define  DX0GCR3_DSPDRMODE        GENMASK_32(3, 2)
#define  DX0GCR3_DSTEMODE         GENMASK_32(5, 4)
#define  DX0GCR3_DSOEMODE         GENMASK_32(7, 6)
#define  DX0GCR3_RESERVED_9_8     GENMASK_32(9, 8)
#define  DX0GCR3_DMPDRMODE        GENMASK_32(11, 10)
#define  DX0GCR3_DMTEMODE         GENMASK_32(13, 12)
#define  DX0GCR3_DMOEMODE         GENMASK_32(15, 14)
#define  DX0GCR3_RESERVED_17_16   GENMASK_32(17, 16)
#define  DX0GCR3_OEBVT            BIT_32(18)
#define  DX0GCR3_PDRBVT           BIT_32(19)
#define  DX0GCR3_TEBVT            BIT_32(20)
#define  DX0GCR3_WDSBVT           BIT_32(21)
#define  DX0GCR3_RDSBVT           BIT_32(22)
#define  DX0GCR3_RGSLVT           BIT_32(23)
#define  DX0GCR3_WLLVT            BIT_32(24)
#define  DX0GCR3_WDLVT            BIT_32(25)
#define  DX0GCR3_RDLVT            BIT_32(26)
#define  DX0GCR3_RGLVT            BIT_32(27)
#define  DX0GCR3_WDBVT            BIT_32(28)
#define  DX0GCR3_RDBVT            BIT_32(29)
#define  DX0GCR3_WDMBVT           BIT_32(30)
#define  DX0GCR3_RDMBVT           BIT_32(31)

#define DDR_PHY_DX0GCR4          0x600108710
#define  DX0GCR4_DXREFIMON        GENMASK_32(1, 0)
#define  DX0GCR4_DXREFIEN         GENMASK_32(5, 2)
#define  DX0GCR4_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX0GCR4_DXREFSSEL        GENMASK_32(13, 8)
#define  DX0GCR4_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX0GCR4_DXREFESEL        GENMASK_32(21, 16)
#define  DX0GCR4_RESERVED_24_22   GENMASK_32(24, 22)
#define  DX0GCR4_DXREFSEN         BIT_32(25)
#define  DX0GCR4_DXREFEEN         GENMASK_32(27, 26)
#define  DX0GCR4_DXREFPEN         BIT_32(28)
#define  DX0GCR4_DXREFIOM         GENMASK_32(31, 29)

#define DDR_PHY_DX0GCR5          0x600108714
#define  DX0GCR5_DXREFISELR0      GENMASK_32(5, 0)
#define  DX0GCR5_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX0GCR5_DXREFISELR1      GENMASK_32(13, 8)
#define  DX0GCR5_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX0GCR5_DXREFISELR2      GENMASK_32(21, 16)
#define  DX0GCR5_RESERVED_23_22   GENMASK_32(23, 22)
#define  DX0GCR5_DXREFISELR3      GENMASK_32(29, 24)
#define  DX0GCR5_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX0GCR6          0x600108718
#define  DX0GCR6_DXDQVREFR0       GENMASK_32(5, 0)
#define  DX0GCR6_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX0GCR6_DXDQVREFR1       GENMASK_32(13, 8)
#define  DX0GCR6_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX0GCR6_DXDQVREFR2       GENMASK_32(21, 16)
#define  DX0GCR6_RESERVED_23_22   GENMASK_32(23, 22)
#define  DX0GCR6_DXDQVREFR3       GENMASK_32(29, 24)
#define  DX0GCR6_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX0GCR7          0x60010871c
#define  DX0GCR7_RESERVED_1_0     GENMASK_32(1, 0)
#define  DX0GCR7_X4DSPDRMODE      GENMASK_32(3, 2)
#define  DX0GCR7_X4DSTEMODE       GENMASK_32(5, 4)
#define  DX0GCR7_X4DSOEMODE       GENMASK_32(7, 6)
#define  DX0GCR7_RESERVED_9_8     GENMASK_32(9, 8)
#define  DX0GCR7_X4DXPDRMODE      GENMASK_32(11, 10)
#define  DX0GCR7_X4DXTEMODE       GENMASK_32(13, 12)
#define  DX0GCR7_X4DXOEMODE       GENMASK_32(15, 14)
#define  DX0GCR7_X4DQSGOE         BIT_32(16)
#define  DX0GCR7_X4DQSGODT        BIT_32(17)
#define  DX0GCR7_RESERVED_18      BIT_32(18)
#define  DX0GCR7_X4DQSGPDR        BIT_32(19)
#define  DX0GCR7_RESERVED_20      BIT_32(20)
#define  DX0GCR7_X4DQSSEPDR       BIT_32(21)
#define  DX0GCR7_X4DQSNSEPDR      BIT_32(22)
#define  DX0GCR7_X4RTTOH          GENMASK_32(24, 23)
#define  DX0GCR7_X4RTTOAL         BIT_32(25)
#define  DX0GCR7_X4RDDLY          GENMASK_32(29, 26)
#define  DX0GCR7_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX0GCR8          0x600108720
#define  DX0GCR8_X4DXREFISELR0    GENMASK_32(5, 0)
#define  DX0GCR8_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX0GCR8_X4DXREFISELR1    GENMASK_32(13, 8)
#define  DX0GCR8_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX0GCR8_X4DXREFISELR2    GENMASK_32(21, 16)
#define  DX0GCR8_RESERVED_23_22   GENMASK_32(23, 22)
#define  DX0GCR8_X4DXREFISELR3    GENMASK_32(29, 24)
#define  DX0GCR8_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX0GCR9          0x600108724
#define  DX0GCR9_X4DXDQVREFR0     GENMASK_32(5, 0)
#define  DX0GCR9_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX0GCR9_X4DXDQVREFR1     GENMASK_32(13, 8)
#define  DX0GCR9_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX0GCR9_X4DXDQVREFR2     GENMASK_32(21, 16)
#define  DX0GCR9_RESERVED_23_22   GENMASK_32(23, 22)
#define  DX0GCR9_X4DXDQVREFR3     GENMASK_32(29, 24)
#define  DX0GCR9_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX0BDLR0         0x600108740
#define  DX0BDLR0_DQ0WBD          GENMASK_32(5, 0)
#define  DX0BDLR0_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX0BDLR0_DQ1WBD          GENMASK_32(13, 8)
#define  DX0BDLR0_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX0BDLR0_DQ2WBD          GENMASK_32(21, 16)
#define  DX0BDLR0_RESERVED_23_22  GENMASK_32(23, 22)
#define  DX0BDLR0_DQ3WBD          GENMASK_32(29, 24)
#define  DX0BDLR0_RESERVED_31_30  GENMASK_32(31, 30)

#define DDR_PHY_DX0BDLR1         0x600108744
#define  DX0BDLR1_DQ4WBD          GENMASK_32(5, 0)
#define  DX0BDLR1_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX0BDLR1_DQ5WBD          GENMASK_32(13, 8)
#define  DX0BDLR1_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX0BDLR1_DQ6WBD          GENMASK_32(21, 16)
#define  DX0BDLR1_RESERVED_23_22  GENMASK_32(23, 22)
#define  DX0BDLR1_DQ7WBD          GENMASK_32(29, 24)
#define  DX0BDLR1_RESERVED_31_30  GENMASK_32(31, 30)

#define DDR_PHY_DX0BDLR2         0x600108748
#define  DX0BDLR2_DMWBD           GENMASK_32(5, 0)
#define  DX0BDLR2_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX0BDLR2_DSWBD           GENMASK_32(13, 8)
#define  DX0BDLR2_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX0BDLR2_DSOEBD          GENMASK_32(21, 16)
#define  DX0BDLR2_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX0BDLR3         0x600108750
#define  DX0BDLR3_DQ0RBD          GENMASK_32(5, 0)
#define  DX0BDLR3_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX0BDLR3_DQ1RBD          GENMASK_32(13, 8)
#define  DX0BDLR3_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX0BDLR3_DQ2RBD          GENMASK_32(21, 16)
#define  DX0BDLR3_RESERVED_23_22  GENMASK_32(23, 22)
#define  DX0BDLR3_DQ3RBD          GENMASK_32(29, 24)
#define  DX0BDLR3_RESERVED_31_30  GENMASK_32(31, 30)

#define DDR_PHY_DX0BDLR4         0x600108754
#define  DX0BDLR4_DQ4RBD          GENMASK_32(5, 0)
#define  DX0BDLR4_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX0BDLR4_DQ5RBD          GENMASK_32(13, 8)
#define  DX0BDLR4_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX0BDLR4_DQ6RBD          GENMASK_32(21, 16)
#define  DX0BDLR4_RESERVED_23_22  GENMASK_32(23, 22)
#define  DX0BDLR4_DQ7RBD          GENMASK_32(29, 24)
#define  DX0BDLR4_RESERVED_31_30  GENMASK_32(31, 30)

#define DDR_PHY_DX0BDLR5         0x600108758
#define  DX0BDLR5_DMRBD           GENMASK_32(5, 0)
#define  DX0BDLR5_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX0BDLR5_DSRBD           GENMASK_32(13, 8)
#define  DX0BDLR5_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX0BDLR5_DSNRBD          GENMASK_32(21, 16)
#define  DX0BDLR5_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX0BDLR6         0x600108760
#define  DX0BDLR6_RESERVED_7_0    GENMASK_32(7, 0)
#define  DX0BDLR6_PDRBD           GENMASK_32(13, 8)
#define  DX0BDLR6_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX0BDLR6_TERBD           GENMASK_32(21, 16)
#define  DX0BDLR6_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX0BDLR7         0x600108764
#define  DX0BDLR7_X4DMWBD         GENMASK_32(5, 0)
#define  DX0BDLR7_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX0BDLR7_X4DSWBD         GENMASK_32(13, 8)
#define  DX0BDLR7_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX0BDLR7_X4DSOEBD        GENMASK_32(21, 16)
#define  DX0BDLR7_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX0BDLR8         0x600108768
#define  DX0BDLR8_X4DMRBD         GENMASK_32(5, 0)
#define  DX0BDLR8_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX0BDLR8_X4DSRBD         GENMASK_32(13, 8)
#define  DX0BDLR8_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX0BDLR8_X4DSNRBD        GENMASK_32(21, 16)
#define  DX0BDLR8_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX0BDLR9         0x60010876c
#define  DX0BDLR9_RESERVED_7_0    GENMASK_32(7, 0)
#define  DX0BDLR9_X4PDRBD         GENMASK_32(13, 8)
#define  DX0BDLR9_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX0BDLR9_X4TERBD         GENMASK_32(21, 16)
#define  DX0BDLR9_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX0LCDLR0        0x600108780
#define  DX0LCDLR0_WLD            GENMASK_32(8, 0)
#define  DX0LCDLR0_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX0LCDLR0_X4WLD          GENMASK_32(24, 16)
#define  DX0LCDLR0_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX0LCDLR1        0x600108784
#define  DX0LCDLR1_WDQD           GENMASK_32(8, 0)
#define  DX0LCDLR1_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX0LCDLR1_X4WDQD         GENMASK_32(24, 16)
#define  DX0LCDLR1_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX0LCDLR2        0x600108788
#define  DX0LCDLR2_DQSGD          GENMASK_32(8, 0)
#define  DX0LCDLR2_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX0LCDLR2_X4DQSGD        GENMASK_32(24, 16)
#define  DX0LCDLR2_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX0LCDLR3        0x60010878c
#define  DX0LCDLR3_RDQSD          GENMASK_32(8, 0)
#define  DX0LCDLR3_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX0LCDLR3_X4RDQSD        GENMASK_32(24, 16)
#define  DX0LCDLR3_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX0LCDLR4        0x600108790
#define  DX0LCDLR4_RDQSND         GENMASK_32(8, 0)
#define  DX0LCDLR4_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX0LCDLR4_X4RDQSND       GENMASK_32(24, 16)
#define  DX0LCDLR4_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX0LCDLR5        0x600108794
#define  DX0LCDLR5_DQSGSD         GENMASK_32(8, 0)
#define  DX0LCDLR5_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX0LCDLR5_X4DQSGSD       GENMASK_32(24, 16)
#define  DX0LCDLR5_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX0MDLR0         0x6001087a0
#define  DX0MDLR0_IPRD            GENMASK_32(8, 0)
#define  DX0MDLR0_RESERVED_15_9   GENMASK_32(15, 9)
#define  DX0MDLR0_TPRD            GENMASK_32(24, 16)
#define  DX0MDLR0_RESERVED_31_25  GENMASK_32(31, 25)

#define DDR_PHY_DX0MDLR1         0x6001087a4
#define  DX0MDLR1_MDLD            GENMASK_32(8, 0)
#define  DX0MDLR1_RESERVED_31_9   GENMASK_32(31, 9)

#define DDR_PHY_DX0GTR0          0x6001087c0
#define  DX0GTR0_DGSL             GENMASK_32(4, 0)
#define  DX0GTR0_RESERVED_7_5     GENMASK_32(7, 5)
#define  DX0GTR0_X4DGSL           GENMASK_32(12, 8)
#define  DX0GTR0_RESERVED_15_13   GENMASK_32(15, 13)
#define  DX0GTR0_WLSL             GENMASK_32(19, 16)
#define  DX0GTR0_X4WLSL           GENMASK_32(23, 20)
#define  DX0GTR0_RESERVED_31_24   GENMASK_32(31, 24)

#define DDR_PHY_DX0RSR0          0x6001087d0
#define  DX0RSR0_QSGERR           GENMASK_32(15, 0)
#define  DX0RSR0_X4QSGERR         GENMASK_32(31, 16)

#define DDR_PHY_DX0RSR1          0x6001087d4
#define  DX0RSR1_RDLVLERR         GENMASK_32(15, 0)
#define  DX0RSR1_X4RDLVLERR       GENMASK_32(31, 16)

#define DDR_PHY_DX0RSR2          0x6001087d8
#define  DX0RSR2_WLAWN            GENMASK_32(15, 0)
#define  DX0RSR2_X4WLAWN          GENMASK_32(31, 16)

#define DDR_PHY_DX0RSR3          0x6001087dc
#define  DX0RSR3_WLAERR           GENMASK_32(15, 0)
#define  DX0RSR3_X4WLAERR         GENMASK_32(31, 16)

#define DDR_PHY_DX0GSR0          0x6001087e0
#define  DX0GSR0_WDQCAL           BIT_32(0)
#define  DX0GSR0_RDQSCAL          BIT_32(1)
#define  DX0GSR0_RDQSNCAL         BIT_32(2)
#define  DX0GSR0_GDQSCAL          BIT_32(3)
#define  DX0GSR0_WLCAL            BIT_32(4)
#define  DX0GSR0_WLDONE           BIT_32(5)
#define  DX0GSR0_WLERR            BIT_32(6)
#define  DX0GSR0_WLPRD            GENMASK_32(15, 7)
#define  DX0GSR0_DPLOCK           BIT_32(16)
#define  DX0GSR0_GDQSPRD          GENMASK_32(25, 17)
#define  DX0GSR0_RESERVED_29_26   GENMASK_32(29, 26)
#define  DX0GSR0_WLDQ             BIT_32(30)
#define  DX0GSR0_RESERVED_31      BIT_32(31)

#define DDR_PHY_DX0GSR1          0x6001087e4
#define  DX0GSR1_DLTDONE          BIT_32(0)
#define  DX0GSR1_DLTCODE          GENMASK_32(24, 1)
#define  DX0GSR1_RESERVED_31_25   GENMASK_32(31, 25)

#define DDR_PHY_DX0GSR2          0x6001087e8
#define  DX0GSR2_RDERR            BIT_32(0)
#define  DX0GSR2_RDWN             BIT_32(1)
#define  DX0GSR2_WDERR            BIT_32(2)
#define  DX0GSR2_WDWN             BIT_32(3)
#define  DX0GSR2_REERR            BIT_32(4)
#define  DX0GSR2_REWN             BIT_32(5)
#define  DX0GSR2_WEERR            BIT_32(6)
#define  DX0GSR2_WEWN             BIT_32(7)
#define  DX0GSR2_ESTAT            GENMASK_32(11, 8)
#define  DX0GSR2_DBDQ             GENMASK_32(19, 12)
#define  DX0GSR2_SRDERR           BIT_32(20)
#define  DX0GSR2_RESERVED_21      BIT_32(21)
#define  DX0GSR2_GSDQSCAL         BIT_32(22)
#define  DX0GSR2_GSDQSPRD         GENMASK_32(31, 23)

#define DDR_PHY_DX0GSR3          0x6001087ec
#define  DX0GSR3_SRDPC            GENMASK_32(1, 0)
#define  DX0GSR3_RESERVED_7_2     GENMASK_32(7, 2)
#define  DX0GSR3_HVERR            GENMASK_32(11, 8)
#define  DX0GSR3_HVWRN            GENMASK_32(15, 12)
#define  DX0GSR3_DVERR            GENMASK_32(19, 16)
#define  DX0GSR3_DVWRN            GENMASK_32(23, 20)
#define  DX0GSR3_ESTAT            GENMASK_32(26, 24)
#define  DX0GSR3_RESERVED_31_27   GENMASK_32(31, 27)

#define DDR_PHY_DX0GSR4          0x6001087f0
#define  DX0GSR4_X4WDQCAL         BIT_32(0)
#define  DX0GSR4_X4RDQSCAL        BIT_32(1)
#define  DX0GSR4_X4RDQSNCAL       BIT_32(2)
#define  DX0GSR4_X4GDQSCAL        BIT_32(3)
#define  DX0GSR4_X4WLCAL          BIT_32(4)
#define  DX0GSR4_X4WLDONE         BIT_32(5)
#define  DX0GSR4_X4WLERR          BIT_32(6)
#define  DX0GSR4_X4WLPRD          GENMASK_32(15, 7)
#define  DX0GSR4_X4DPLOCK         BIT_32(16)
#define  DX0GSR4_X4GDQSPRD        GENMASK_32(25, 17)
#define  DX0GSR4_RESERVED_29_26   GENMASK_32(29, 26)
#define  DX0GSR4_X4WLDQ           BIT_32(30)
#define  DX0GSR4_RESERVED_31      BIT_32(31)

#define DDR_PHY_DX0GSR5          0x6001087f4
#define  DX0GSR5_X4RDERR          BIT_32(0)
#define  DX0GSR5_X4RDWN           BIT_32(1)
#define  DX0GSR5_X4WDERR          BIT_32(2)
#define  DX0GSR5_X4WDWN           BIT_32(3)
#define  DX0GSR5_X4REERR          BIT_32(4)
#define  DX0GSR5_X4REWN           BIT_32(5)
#define  DX0GSR5_X4WEERR          BIT_32(6)
#define  DX0GSR5_X4WEWN           BIT_32(7)
#define  DX0GSR5_X4ESTAT          GENMASK_32(11, 8)
#define  DX0GSR5_RESERVED_19_12   GENMASK_32(19, 12)
#define  DX0GSR5_X4SRDERR         BIT_32(20)
#define  DX0GSR5_RESERVED_21      BIT_32(21)
#define  DX0GSR5_X4GSDQSCAL       BIT_32(22)
#define  DX0GSR5_X4GSDQSPRD       GENMASK_32(31, 23)

#define DDR_PHY_DX0GSR6          0x6001087f8
#define  DX0GSR6_RESERVED_1_0     GENMASK_32(1, 0)
#define  DX0GSR6_X4SRDPC          GENMASK_32(3, 2)
#define  DX0GSR6_RESERVED_7_4     GENMASK_32(7, 4)
#define  DX0GSR6_X4HVERR          GENMASK_32(11, 8)
#define  DX0GSR6_X4HVWRN          GENMASK_32(15, 12)
#define  DX0GSR6_X4DVERR          GENMASK_32(19, 16)
#define  DX0GSR6_X4DVWRN          GENMASK_32(23, 20)
#define  DX0GSR6_RESERVED_31_24   GENMASK_32(31, 24)

#define DDR_PHY_DX1GCR0          0x600108800
#define  DX1GCR0_DXEN             BIT_32(0)
#define  DX1GCR0_DXIOM            BIT_32(1)
#define  DX1GCR0_DQSGOE           BIT_32(2)
#define  DX1GCR0_DQSGODT          BIT_32(3)
#define  DX1GCR0_RESERVED_4       BIT_32(4)
#define  DX1GCR0_DQSGPDR          BIT_32(5)
#define  DX1GCR0_RESERVED_6       BIT_32(6)
#define  DX1GCR0_PDRAL            GENMASK_32(8, 7)
#define  DX1GCR0_RTTOH            GENMASK_32(10, 9)
#define  DX1GCR0_RTTOAL           BIT_32(11)
#define  DX1GCR0_DQSSEPDR         BIT_32(12)
#define  DX1GCR0_DQSNSEPDR        BIT_32(13)
#define  DX1GCR0_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX1GCR0_PLLRST           BIT_32(16)
#define  DX1GCR0_PLLPD            BIT_32(17)
#define  DX1GCR0_GSHIFT           BIT_32(18)
#define  DX1GCR0_PLLBYP           BIT_32(19)
#define  DX1GCR0_RDDLY            GENMASK_32(23, 20)
#define  DX1GCR0_RESERVED_29_24   GENMASK_32(29, 24)
#define  DX1GCR0_MDLEN            BIT_32(30)
#define  DX1GCR0_CALBYP           BIT_32(31)

#define DDR_PHY_DX1GCR1          0x600108804
#define  DX1GCR1_RESERVED_15_0    GENMASK_32(15, 0)
#define  DX1GCR1_DXPDRMODE        GENMASK_32(31, 16)

#define DDR_PHY_DX1GCR2          0x600108808
#define  DX1GCR2_DXTEMODE         GENMASK_32(15, 0)
#define  DX1GCR2_DXOEMODE         GENMASK_32(31, 16)

#define DDR_PHY_DX1GCR3          0x60010880c
#define  DX1GCR3_RESERVED_1_0     GENMASK_32(1, 0)
#define  DX1GCR3_DSPDRMODE        GENMASK_32(3, 2)
#define  DX1GCR3_DSTEMODE         GENMASK_32(5, 4)
#define  DX1GCR3_DSOEMODE         GENMASK_32(7, 6)
#define  DX1GCR3_RESERVED_9_8     GENMASK_32(9, 8)
#define  DX1GCR3_DMPDRMODE        GENMASK_32(11, 10)
#define  DX1GCR3_DMTEMODE         GENMASK_32(13, 12)
#define  DX1GCR3_DMOEMODE         GENMASK_32(15, 14)
#define  DX1GCR3_RESERVED_17_16   GENMASK_32(17, 16)
#define  DX1GCR3_OEBVT            BIT_32(18)
#define  DX1GCR3_PDRBVT           BIT_32(19)
#define  DX1GCR3_TEBVT            BIT_32(20)
#define  DX1GCR3_WDSBVT           BIT_32(21)
#define  DX1GCR3_RDSBVT           BIT_32(22)
#define  DX1GCR3_RGSLVT           BIT_32(23)
#define  DX1GCR3_WLLVT            BIT_32(24)
#define  DX1GCR3_WDLVT            BIT_32(25)
#define  DX1GCR3_RDLVT            BIT_32(26)
#define  DX1GCR3_RGLVT            BIT_32(27)
#define  DX1GCR3_WDBVT            BIT_32(28)
#define  DX1GCR3_RDBVT            BIT_32(29)
#define  DX1GCR3_WDMBVT           BIT_32(30)
#define  DX1GCR3_RDMBVT           BIT_32(31)

#define DDR_PHY_DX1GCR4          0x600108810
#define  DX1GCR4_DXREFIMON        GENMASK_32(1, 0)
#define  DX1GCR4_DXREFIEN         GENMASK_32(5, 2)
#define  DX1GCR4_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX1GCR4_DXREFSSEL        GENMASK_32(13, 8)
#define  DX1GCR4_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX1GCR4_DXREFESEL        GENMASK_32(21, 16)
#define  DX1GCR4_RESERVED_24_22   GENMASK_32(24, 22)
#define  DX1GCR4_DXREFSEN         BIT_32(25)
#define  DX1GCR4_DXREFEEN         GENMASK_32(27, 26)
#define  DX1GCR4_DXREFPEN         BIT_32(28)
#define  DX1GCR4_DXREFIOM         GENMASK_32(31, 29)

#define DDR_PHY_DX1GCR5          0x600108814
#define  DX1GCR5_DXREFISELR0      GENMASK_32(5, 0)
#define  DX1GCR5_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX1GCR5_DXREFISELR1      GENMASK_32(13, 8)
#define  DX1GCR5_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX1GCR5_DXREFISELR2      GENMASK_32(21, 16)
#define  DX1GCR5_RESERVED_23_22   GENMASK_32(23, 22)
#define  DX1GCR5_DXREFISELR3      GENMASK_32(29, 24)
#define  DX1GCR5_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX1GCR6          0x600108818
#define  DX1GCR6_DXDQVREFR0       GENMASK_32(5, 0)
#define  DX1GCR6_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX1GCR6_DXDQVREFR1       GENMASK_32(13, 8)
#define  DX1GCR6_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX1GCR6_DXDQVREFR2       GENMASK_32(21, 16)
#define  DX1GCR6_RESERVED_23_22   GENMASK_32(23, 22)
#define  DX1GCR6_DXDQVREFR3       GENMASK_32(29, 24)
#define  DX1GCR6_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX1GCR7          0x60010881c
#define  DX1GCR7_RESERVED_1_0     GENMASK_32(1, 0)
#define  DX1GCR7_X4DSPDRMODE      GENMASK_32(3, 2)
#define  DX1GCR7_X4DSTEMODE       GENMASK_32(5, 4)
#define  DX1GCR7_X4DSOEMODE       GENMASK_32(7, 6)
#define  DX1GCR7_RESERVED_9_8     GENMASK_32(9, 8)
#define  DX1GCR7_X4DXPDRMODE      GENMASK_32(11, 10)
#define  DX1GCR7_X4DXTEMODE       GENMASK_32(13, 12)
#define  DX1GCR7_X4DXOEMODE       GENMASK_32(15, 14)
#define  DX1GCR7_X4DQSGOE         BIT_32(16)
#define  DX1GCR7_X4DQSGODT        BIT_32(17)
#define  DX1GCR7_RESERVED_18      BIT_32(18)
#define  DX1GCR7_X4DQSGPDR        BIT_32(19)
#define  DX1GCR7_RESERVED_20      BIT_32(20)
#define  DX1GCR7_X4DQSSEPDR       BIT_32(21)
#define  DX1GCR7_X4DQSNSEPDR      BIT_32(22)
#define  DX1GCR7_X4RTTOH          GENMASK_32(24, 23)
#define  DX1GCR7_X4RTTOAL         BIT_32(25)
#define  DX1GCR7_X4RDDLY          GENMASK_32(29, 26)
#define  DX1GCR7_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX1GCR8          0x600108820
#define  DX1GCR8_X4DXREFISELR0    GENMASK_32(5, 0)
#define  DX1GCR8_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX1GCR8_X4DXREFISELR1    GENMASK_32(13, 8)
#define  DX1GCR8_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX1GCR8_X4DXREFISELR2    GENMASK_32(21, 16)
#define  DX1GCR8_RESERVED_23_22   GENMASK_32(23, 22)
#define  DX1GCR8_X4DXREFISELR3    GENMASK_32(29, 24)
#define  DX1GCR8_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX1GCR9          0x600108824
#define  DX1GCR9_X4DXDQVREFR0     GENMASK_32(5, 0)
#define  DX1GCR9_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX1GCR9_X4DXDQVREFR1     GENMASK_32(13, 8)
#define  DX1GCR9_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX1GCR9_X4DXDQVREFR2     GENMASK_32(21, 16)
#define  DX1GCR9_RESERVED_23_22   GENMASK_32(23, 22)
#define  DX1GCR9_X4DXDQVREFR3     GENMASK_32(29, 24)
#define  DX1GCR9_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX1BDLR0         0x600108840
#define  DX1BDLR0_DQ0WBD          GENMASK_32(5, 0)
#define  DX1BDLR0_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX1BDLR0_DQ1WBD          GENMASK_32(13, 8)
#define  DX1BDLR0_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX1BDLR0_DQ2WBD          GENMASK_32(21, 16)
#define  DX1BDLR0_RESERVED_23_22  GENMASK_32(23, 22)
#define  DX1BDLR0_DQ3WBD          GENMASK_32(29, 24)
#define  DX1BDLR0_RESERVED_31_30  GENMASK_32(31, 30)

#define DDR_PHY_DX1BDLR1         0x600108844
#define  DX1BDLR1_DQ4WBD          GENMASK_32(5, 0)
#define  DX1BDLR1_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX1BDLR1_DQ5WBD          GENMASK_32(13, 8)
#define  DX1BDLR1_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX1BDLR1_DQ6WBD          GENMASK_32(21, 16)
#define  DX1BDLR1_RESERVED_23_22  GENMASK_32(23, 22)
#define  DX1BDLR1_DQ7WBD          GENMASK_32(29, 24)
#define  DX1BDLR1_RESERVED_31_30  GENMASK_32(31, 30)

#define DDR_PHY_DX1BDLR2         0x600108848
#define  DX1BDLR2_DMWBD           GENMASK_32(5, 0)
#define  DX1BDLR2_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX1BDLR2_DSWBD           GENMASK_32(13, 8)
#define  DX1BDLR2_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX1BDLR2_DSOEBD          GENMASK_32(21, 16)
#define  DX1BDLR2_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX1BDLR3         0x600108850
#define  DX1BDLR3_DQ0RBD          GENMASK_32(5, 0)
#define  DX1BDLR3_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX1BDLR3_DQ1RBD          GENMASK_32(13, 8)
#define  DX1BDLR3_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX1BDLR3_DQ2RBD          GENMASK_32(21, 16)
#define  DX1BDLR3_RESERVED_23_22  GENMASK_32(23, 22)
#define  DX1BDLR3_DQ3RBD          GENMASK_32(29, 24)
#define  DX1BDLR3_RESERVED_31_30  GENMASK_32(31, 30)

#define DDR_PHY_DX1BDLR4         0x600108854
#define  DX1BDLR4_DQ4RBD          GENMASK_32(5, 0)
#define  DX1BDLR4_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX1BDLR4_DQ5RBD          GENMASK_32(13, 8)
#define  DX1BDLR4_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX1BDLR4_DQ6RBD          GENMASK_32(21, 16)
#define  DX1BDLR4_RESERVED_23_22  GENMASK_32(23, 22)
#define  DX1BDLR4_DQ7RBD          GENMASK_32(29, 24)
#define  DX1BDLR4_RESERVED_31_30  GENMASK_32(31, 30)

#define DDR_PHY_DX1BDLR5         0x600108858
#define  DX1BDLR5_DMRBD           GENMASK_32(5, 0)
#define  DX1BDLR5_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX1BDLR5_DSRBD           GENMASK_32(13, 8)
#define  DX1BDLR5_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX1BDLR5_DSNRBD          GENMASK_32(21, 16)
#define  DX1BDLR5_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX1BDLR6         0x600108860
#define  DX1BDLR6_RESERVED_7_0    GENMASK_32(7, 0)
#define  DX1BDLR6_PDRBD           GENMASK_32(13, 8)
#define  DX1BDLR6_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX1BDLR6_TERBD           GENMASK_32(21, 16)
#define  DX1BDLR6_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX1BDLR7         0x600108864
#define  DX1BDLR7_X4DMWBD         GENMASK_32(5, 0)
#define  DX1BDLR7_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX1BDLR7_X4DSWBD         GENMASK_32(13, 8)
#define  DX1BDLR7_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX1BDLR7_X4DSOEBD        GENMASK_32(21, 16)
#define  DX1BDLR7_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX1BDLR8         0x600108868
#define  DX1BDLR8_X4DMRBD         GENMASK_32(5, 0)
#define  DX1BDLR8_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX1BDLR8_X4DSRBD         GENMASK_32(13, 8)
#define  DX1BDLR8_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX1BDLR8_X4DSNRBD        GENMASK_32(21, 16)
#define  DX1BDLR8_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX1BDLR9         0x60010886c
#define  DX1BDLR9_RESERVED_7_0    GENMASK_32(7, 0)
#define  DX1BDLR9_X4PDRBD         GENMASK_32(13, 8)
#define  DX1BDLR9_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX1BDLR9_X4TERBD         GENMASK_32(21, 16)
#define  DX1BDLR9_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX1LCDLR0        0x600108880
#define  DX1LCDLR0_WLD            GENMASK_32(8, 0)
#define  DX1LCDLR0_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX1LCDLR0_X4WLD          GENMASK_32(24, 16)
#define  DX1LCDLR0_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX1LCDLR1        0x600108884
#define  DX1LCDLR1_WDQD           GENMASK_32(8, 0)
#define  DX1LCDLR1_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX1LCDLR1_X4WDQD         GENMASK_32(24, 16)
#define  DX1LCDLR1_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX1LCDLR2        0x600108888
#define  DX1LCDLR2_DQSGD          GENMASK_32(8, 0)
#define  DX1LCDLR2_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX1LCDLR2_X4DQSGD        GENMASK_32(24, 16)
#define  DX1LCDLR2_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX1LCDLR3        0x60010888c
#define  DX1LCDLR3_RDQSD          GENMASK_32(8, 0)
#define  DX1LCDLR3_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX1LCDLR3_X4RDQSD        GENMASK_32(24, 16)
#define  DX1LCDLR3_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX1LCDLR4        0x600108890
#define  DX1LCDLR4_RDQSND         GENMASK_32(8, 0)
#define  DX1LCDLR4_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX1LCDLR4_X4RDQSND       GENMASK_32(24, 16)
#define  DX1LCDLR4_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX1LCDLR5        0x600108894
#define  DX1LCDLR5_DQSGSD         GENMASK_32(8, 0)
#define  DX1LCDLR5_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX1LCDLR5_X4DQSGSD       GENMASK_32(24, 16)
#define  DX1LCDLR5_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX1MDLR0         0x6001088a0
#define  DX1MDLR0_IPRD            GENMASK_32(8, 0)
#define  DX1MDLR0_RESERVED_15_9   GENMASK_32(15, 9)
#define  DX1MDLR0_TPRD            GENMASK_32(24, 16)
#define  DX1MDLR0_RESERVED_31_25  GENMASK_32(31, 25)

#define DDR_PHY_DX1MDLR1         0x6001088a4
#define  DX1MDLR1_MDLD            GENMASK_32(8, 0)
#define  DX1MDLR1_RESERVED_31_9   GENMASK_32(31, 9)

#define DDR_PHY_DX1GTR0          0x6001088c0
#define  DX1GTR0_DGSL             GENMASK_32(4, 0)
#define  DX1GTR0_RESERVED_7_5     GENMASK_32(7, 5)
#define  DX1GTR0_X4DGSL           GENMASK_32(12, 8)
#define  DX1GTR0_RESERVED_15_13   GENMASK_32(15, 13)
#define  DX1GTR0_WLSL             GENMASK_32(19, 16)
#define  DX1GTR0_X4WLSL           GENMASK_32(23, 20)
#define  DX1GTR0_RESERVED_31_24   GENMASK_32(31, 24)

#define DDR_PHY_DX1RSR0          0x6001088d0
#define  DX1RSR0_QSGERR           GENMASK_32(15, 0)
#define  DX1RSR0_X4QSGERR         GENMASK_32(31, 16)

#define DDR_PHY_DX1RSR1          0x6001088d4
#define  DX1RSR1_RDLVLERR         GENMASK_32(15, 0)
#define  DX1RSR1_X4RDLVLERR       GENMASK_32(31, 16)

#define DDR_PHY_DX1RSR2          0x6001088d8
#define  DX1RSR2_WLAWN            GENMASK_32(15, 0)
#define  DX1RSR2_X4WLAWN          GENMASK_32(31, 16)

#define DDR_PHY_DX1RSR3          0x6001088dc
#define  DX1RSR3_WLAERR           GENMASK_32(15, 0)
#define  DX1RSR3_X4WLAERR         GENMASK_32(31, 16)

#define DDR_PHY_DX1GSR0          0x6001088e0
#define  DX1GSR0_WDQCAL           BIT_32(0)
#define  DX1GSR0_RDQSCAL          BIT_32(1)
#define  DX1GSR0_RDQSNCAL         BIT_32(2)
#define  DX1GSR0_GDQSCAL          BIT_32(3)
#define  DX1GSR0_WLCAL            BIT_32(4)
#define  DX1GSR0_WLDONE           BIT_32(5)
#define  DX1GSR0_WLERR            BIT_32(6)
#define  DX1GSR0_WLPRD            GENMASK_32(15, 7)
#define  DX1GSR0_DPLOCK           BIT_32(16)
#define  DX1GSR0_GDQSPRD          GENMASK_32(25, 17)
#define  DX1GSR0_RESERVED_29_26   GENMASK_32(29, 26)
#define  DX1GSR0_WLDQ             BIT_32(30)
#define  DX1GSR0_RESERVED_31      BIT_32(31)

#define DDR_PHY_DX1GSR1          0x6001088e4
#define  DX1GSR1_DLTDONE          BIT_32(0)
#define  DX1GSR1_DLTCODE          GENMASK_32(24, 1)
#define  DX1GSR1_RESERVED_31_25   GENMASK_32(31, 25)

#define DDR_PHY_DX1GSR2          0x6001088e8
#define  DX1GSR2_RDERR            BIT_32(0)
#define  DX1GSR2_RDWN             BIT_32(1)
#define  DX1GSR2_WDERR            BIT_32(2)
#define  DX1GSR2_WDWN             BIT_32(3)
#define  DX1GSR2_REERR            BIT_32(4)
#define  DX1GSR2_REWN             BIT_32(5)
#define  DX1GSR2_WEERR            BIT_32(6)
#define  DX1GSR2_WEWN             BIT_32(7)
#define  DX1GSR2_ESTAT            GENMASK_32(11, 8)
#define  DX1GSR2_DBDQ             GENMASK_32(19, 12)
#define  DX1GSR2_SRDERR           BIT_32(20)
#define  DX1GSR2_RESERVED_21      BIT_32(21)
#define  DX1GSR2_GSDQSCAL         BIT_32(22)
#define  DX1GSR2_GSDQSPRD         GENMASK_32(31, 23)

#define DDR_PHY_DX1GSR3          0x6001088ec
#define  DX1GSR3_SRDPC            GENMASK_32(1, 0)
#define  DX1GSR3_RESERVED_7_2     GENMASK_32(7, 2)
#define  DX1GSR3_HVERR            GENMASK_32(11, 8)
#define  DX1GSR3_HVWRN            GENMASK_32(15, 12)
#define  DX1GSR3_DVERR            GENMASK_32(19, 16)
#define  DX1GSR3_DVWRN            GENMASK_32(23, 20)
#define  DX1GSR3_ESTAT            GENMASK_32(26, 24)
#define  DX1GSR3_RESERVED_31_27   GENMASK_32(31, 27)

#define DDR_PHY_DX1GSR4          0x6001088f0
#define  DX1GSR4_X4WDQCAL         BIT_32(0)
#define  DX1GSR4_X4RDQSCAL        BIT_32(1)
#define  DX1GSR4_X4RDQSNCAL       BIT_32(2)
#define  DX1GSR4_X4GDQSCAL        BIT_32(3)
#define  DX1GSR4_X4WLCAL          BIT_32(4)
#define  DX1GSR4_X4WLDONE         BIT_32(5)
#define  DX1GSR4_X4WLERR          BIT_32(6)
#define  DX1GSR4_X4WLPRD          GENMASK_32(15, 7)
#define  DX1GSR4_X4DPLOCK         BIT_32(16)
#define  DX1GSR4_X4GDQSPRD        GENMASK_32(25, 17)
#define  DX1GSR4_RESERVED_29_26   GENMASK_32(29, 26)
#define  DX1GSR4_X4WLDQ           BIT_32(30)
#define  DX1GSR4_RESERVED_31      BIT_32(31)

#define DDR_PHY_DX1GSR5          0x6001088f4
#define  DX1GSR5_X4RDERR          BIT_32(0)
#define  DX1GSR5_X4RDWN           BIT_32(1)
#define  DX1GSR5_X4WDERR          BIT_32(2)
#define  DX1GSR5_X4WDWN           BIT_32(3)
#define  DX1GSR5_X4REERR          BIT_32(4)
#define  DX1GSR5_X4REWN           BIT_32(5)
#define  DX1GSR5_X4WEERR          BIT_32(6)
#define  DX1GSR5_X4WEWN           BIT_32(7)
#define  DX1GSR5_X4ESTAT          GENMASK_32(11, 8)
#define  DX1GSR5_RESERVED_19_12   GENMASK_32(19, 12)
#define  DX1GSR5_X4SRDERR         BIT_32(20)
#define  DX1GSR5_RESERVED_21      BIT_32(21)
#define  DX1GSR5_X4GSDQSCAL       BIT_32(22)
#define  DX1GSR5_X4GSDQSPRD       GENMASK_32(31, 23)

#define DDR_PHY_DX1GSR6          0x6001088f8
#define  DX1GSR6_RESERVED_1_0     GENMASK_32(1, 0)
#define  DX1GSR6_X4SRDPC          GENMASK_32(3, 2)
#define  DX1GSR6_RESERVED_7_4     GENMASK_32(7, 4)
#define  DX1GSR6_X4HVERR          GENMASK_32(11, 8)
#define  DX1GSR6_X4HVWRN          GENMASK_32(15, 12)
#define  DX1GSR6_X4DVERR          GENMASK_32(19, 16)
#define  DX1GSR6_X4DVWRN          GENMASK_32(23, 20)
#define  DX1GSR6_RESERVED_31_24   GENMASK_32(31, 24)

#define DDR_PHY_DX2GCR0          0x600108900
#define  DX2GCR0_DXEN             BIT_32(0)
#define  DX2GCR0_DXIOM            BIT_32(1)
#define  DX2GCR0_DQSGOE           BIT_32(2)
#define  DX2GCR0_DQSGODT          BIT_32(3)
#define  DX2GCR0_RESERVED_4       BIT_32(4)
#define  DX2GCR0_DQSGPDR          BIT_32(5)
#define  DX2GCR0_RESERVED_6       BIT_32(6)
#define  DX2GCR0_PDRAL            GENMASK_32(8, 7)
#define  DX2GCR0_RTTOH            GENMASK_32(10, 9)
#define  DX2GCR0_RTTOAL           BIT_32(11)
#define  DX2GCR0_DQSSEPDR         BIT_32(12)
#define  DX2GCR0_DQSNSEPDR        BIT_32(13)
#define  DX2GCR0_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX2GCR0_PLLRST           BIT_32(16)
#define  DX2GCR0_PLLPD            BIT_32(17)
#define  DX2GCR0_GSHIFT           BIT_32(18)
#define  DX2GCR0_PLLBYP           BIT_32(19)
#define  DX2GCR0_RDDLY            GENMASK_32(23, 20)
#define  DX2GCR0_RESERVED_29_24   GENMASK_32(29, 24)
#define  DX2GCR0_MDLEN            BIT_32(30)
#define  DX2GCR0_CALBYP           BIT_32(31)

#define DDR_PHY_DX2GCR1          0x600108904
#define  DX2GCR1_RESERVED_15_0    GENMASK_32(15, 0)
#define  DX2GCR1_DXPDRMODE        GENMASK_32(31, 16)

#define DDR_PHY_DX2GCR2          0x600108908
#define  DX2GCR2_DXTEMODE         GENMASK_32(15, 0)
#define  DX2GCR2_DXOEMODE         GENMASK_32(31, 16)

#define DDR_PHY_DX2GCR3          0x60010890c
#define  DX2GCR3_RESERVED_1_0     GENMASK_32(1, 0)
#define  DX2GCR3_DSPDRMODE        GENMASK_32(3, 2)
#define  DX2GCR3_DSTEMODE         GENMASK_32(5, 4)
#define  DX2GCR3_DSOEMODE         GENMASK_32(7, 6)
#define  DX2GCR3_RESERVED_9_8     GENMASK_32(9, 8)
#define  DX2GCR3_DMPDRMODE        GENMASK_32(11, 10)
#define  DX2GCR3_DMTEMODE         GENMASK_32(13, 12)
#define  DX2GCR3_DMOEMODE         GENMASK_32(15, 14)
#define  DX2GCR3_RESERVED_17_16   GENMASK_32(17, 16)
#define  DX2GCR3_OEBVT            BIT_32(18)
#define  DX2GCR3_PDRBVT           BIT_32(19)
#define  DX2GCR3_TEBVT            BIT_32(20)
#define  DX2GCR3_WDSBVT           BIT_32(21)
#define  DX2GCR3_RDSBVT           BIT_32(22)
#define  DX2GCR3_RGSLVT           BIT_32(23)
#define  DX2GCR3_WLLVT            BIT_32(24)
#define  DX2GCR3_WDLVT            BIT_32(25)
#define  DX2GCR3_RDLVT            BIT_32(26)
#define  DX2GCR3_RGLVT            BIT_32(27)
#define  DX2GCR3_WDBVT            BIT_32(28)
#define  DX2GCR3_RDBVT            BIT_32(29)
#define  DX2GCR3_WDMBVT           BIT_32(30)
#define  DX2GCR3_RDMBVT           BIT_32(31)

#define DDR_PHY_DX2GCR4          0x600108910
#define  DX2GCR4_DXREFIMON        GENMASK_32(1, 0)
#define  DX2GCR4_DXREFIEN         GENMASK_32(5, 2)
#define  DX2GCR4_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX2GCR4_DXREFSSEL        GENMASK_32(13, 8)
#define  DX2GCR4_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX2GCR4_DXREFESEL        GENMASK_32(21, 16)
#define  DX2GCR4_RESERVED_24_22   GENMASK_32(24, 22)
#define  DX2GCR4_DXREFSEN         BIT_32(25)
#define  DX2GCR4_DXREFEEN         GENMASK_32(27, 26)
#define  DX2GCR4_DXREFPEN         BIT_32(28)
#define  DX2GCR4_DXREFIOM         GENMASK_32(31, 29)

#define DDR_PHY_DX2GCR5          0x600108914
#define  DX2GCR5_DXREFISELR0      GENMASK_32(5, 0)
#define  DX2GCR5_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX2GCR5_DXREFISELR1      GENMASK_32(13, 8)
#define  DX2GCR5_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX2GCR5_DXREFISELR2      GENMASK_32(21, 16)
#define  DX2GCR5_RESERVED_23_22   GENMASK_32(23, 22)
#define  DX2GCR5_DXREFISELR3      GENMASK_32(29, 24)
#define  DX2GCR5_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX2GCR6          0x600108918
#define  DX2GCR6_DXDQVREFR0       GENMASK_32(5, 0)
#define  DX2GCR6_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX2GCR6_DXDQVREFR1       GENMASK_32(13, 8)
#define  DX2GCR6_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX2GCR6_DXDQVREFR2       GENMASK_32(21, 16)
#define  DX2GCR6_RESERVED_23_22   GENMASK_32(23, 22)
#define  DX2GCR6_DXDQVREFR3       GENMASK_32(29, 24)
#define  DX2GCR6_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX2GCR7          0x60010891c
#define  DX2GCR7_RESERVED_1_0     GENMASK_32(1, 0)
#define  DX2GCR7_X4DSPDRMODE      GENMASK_32(3, 2)
#define  DX2GCR7_X4DSTEMODE       GENMASK_32(5, 4)
#define  DX2GCR7_X4DSOEMODE       GENMASK_32(7, 6)
#define  DX2GCR7_RESERVED_9_8     GENMASK_32(9, 8)
#define  DX2GCR7_X4DXPDRMODE      GENMASK_32(11, 10)
#define  DX2GCR7_X4DXTEMODE       GENMASK_32(13, 12)
#define  DX2GCR7_X4DXOEMODE       GENMASK_32(15, 14)
#define  DX2GCR7_X4DQSGOE         BIT_32(16)
#define  DX2GCR7_X4DQSGODT        BIT_32(17)
#define  DX2GCR7_RESERVED_18      BIT_32(18)
#define  DX2GCR7_X4DQSGPDR        BIT_32(19)
#define  DX2GCR7_RESERVED_20      BIT_32(20)
#define  DX2GCR7_X4DQSSEPDR       BIT_32(21)
#define  DX2GCR7_X4DQSNSEPDR      BIT_32(22)
#define  DX2GCR7_X4RTTOH          GENMASK_32(24, 23)
#define  DX2GCR7_X4RTTOAL         BIT_32(25)
#define  DX2GCR7_X4RDDLY          GENMASK_32(29, 26)
#define  DX2GCR7_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX2GCR8          0x600108920
#define  DX2GCR8_X4DXREFISELR0    GENMASK_32(5, 0)
#define  DX2GCR8_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX2GCR8_X4DXREFISELR1    GENMASK_32(13, 8)
#define  DX2GCR8_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX2GCR8_X4DXREFISELR2    GENMASK_32(21, 16)
#define  DX2GCR8_RESERVED_23_22   GENMASK_32(23, 22)
#define  DX2GCR8_X4DXREFISELR3    GENMASK_32(29, 24)
#define  DX2GCR8_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX2GCR9          0x600108924
#define  DX2GCR9_X4DXDQVREFR0     GENMASK_32(5, 0)
#define  DX2GCR9_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX2GCR9_X4DXDQVREFR1     GENMASK_32(13, 8)
#define  DX2GCR9_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX2GCR9_X4DXDQVREFR2     GENMASK_32(21, 16)
#define  DX2GCR9_RESERVED_23_22   GENMASK_32(23, 22)
#define  DX2GCR9_X4DXDQVREFR3     GENMASK_32(29, 24)
#define  DX2GCR9_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX2BDLR0         0x600108940
#define  DX2BDLR0_DQ0WBD          GENMASK_32(5, 0)
#define  DX2BDLR0_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX2BDLR0_DQ1WBD          GENMASK_32(13, 8)
#define  DX2BDLR0_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX2BDLR0_DQ2WBD          GENMASK_32(21, 16)
#define  DX2BDLR0_RESERVED_23_22  GENMASK_32(23, 22)
#define  DX2BDLR0_DQ3WBD          GENMASK_32(29, 24)
#define  DX2BDLR0_RESERVED_31_30  GENMASK_32(31, 30)

#define DDR_PHY_DX2BDLR1         0x600108944
#define  DX2BDLR1_DQ4WBD          GENMASK_32(5, 0)
#define  DX2BDLR1_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX2BDLR1_DQ5WBD          GENMASK_32(13, 8)
#define  DX2BDLR1_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX2BDLR1_DQ6WBD          GENMASK_32(21, 16)
#define  DX2BDLR1_RESERVED_23_22  GENMASK_32(23, 22)
#define  DX2BDLR1_DQ7WBD          GENMASK_32(29, 24)
#define  DX2BDLR1_RESERVED_31_30  GENMASK_32(31, 30)

#define DDR_PHY_DX2BDLR2         0x600108948
#define  DX2BDLR2_DMWBD           GENMASK_32(5, 0)
#define  DX2BDLR2_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX2BDLR2_DSWBD           GENMASK_32(13, 8)
#define  DX2BDLR2_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX2BDLR2_DSOEBD          GENMASK_32(21, 16)
#define  DX2BDLR2_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX2BDLR3         0x600108950
#define  DX2BDLR3_DQ0RBD          GENMASK_32(5, 0)
#define  DX2BDLR3_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX2BDLR3_DQ1RBD          GENMASK_32(13, 8)
#define  DX2BDLR3_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX2BDLR3_DQ2RBD          GENMASK_32(21, 16)
#define  DX2BDLR3_RESERVED_23_22  GENMASK_32(23, 22)
#define  DX2BDLR3_DQ3RBD          GENMASK_32(29, 24)
#define  DX2BDLR3_RESERVED_31_30  GENMASK_32(31, 30)

#define DDR_PHY_DX2BDLR4         0x600108954
#define  DX2BDLR4_DQ4RBD          GENMASK_32(5, 0)
#define  DX2BDLR4_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX2BDLR4_DQ5RBD          GENMASK_32(13, 8)
#define  DX2BDLR4_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX2BDLR4_DQ6RBD          GENMASK_32(21, 16)
#define  DX2BDLR4_RESERVED_23_22  GENMASK_32(23, 22)
#define  DX2BDLR4_DQ7RBD          GENMASK_32(29, 24)
#define  DX2BDLR4_RESERVED_31_30  GENMASK_32(31, 30)

#define DDR_PHY_DX2BDLR5         0x600108958
#define  DX2BDLR5_DMRBD           GENMASK_32(5, 0)
#define  DX2BDLR5_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX2BDLR5_DSRBD           GENMASK_32(13, 8)
#define  DX2BDLR5_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX2BDLR5_DSNRBD          GENMASK_32(21, 16)
#define  DX2BDLR5_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX2BDLR6         0x600108960
#define  DX2BDLR6_RESERVED_7_0    GENMASK_32(7, 0)
#define  DX2BDLR6_PDRBD           GENMASK_32(13, 8)
#define  DX2BDLR6_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX2BDLR6_TERBD           GENMASK_32(21, 16)
#define  DX2BDLR6_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX2BDLR7         0x600108964
#define  DX2BDLR7_X4DMWBD         GENMASK_32(5, 0)
#define  DX2BDLR7_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX2BDLR7_X4DSWBD         GENMASK_32(13, 8)
#define  DX2BDLR7_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX2BDLR7_X4DSOEBD        GENMASK_32(21, 16)
#define  DX2BDLR7_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX2BDLR8         0x600108968
#define  DX2BDLR8_X4DMRBD         GENMASK_32(5, 0)
#define  DX2BDLR8_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX2BDLR8_X4DSRBD         GENMASK_32(13, 8)
#define  DX2BDLR8_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX2BDLR8_X4DSNRBD        GENMASK_32(21, 16)
#define  DX2BDLR8_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX2BDLR9         0x60010896c
#define  DX2BDLR9_RESERVED_7_0    GENMASK_32(7, 0)
#define  DX2BDLR9_X4PDRBD         GENMASK_32(13, 8)
#define  DX2BDLR9_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX2BDLR9_X4TERBD         GENMASK_32(21, 16)
#define  DX2BDLR9_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX2LCDLR0        0x600108980
#define  DX2LCDLR0_WLD            GENMASK_32(8, 0)
#define  DX2LCDLR0_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX2LCDLR0_X4WLD          GENMASK_32(24, 16)
#define  DX2LCDLR0_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX2LCDLR1        0x600108984
#define  DX2LCDLR1_WDQD           GENMASK_32(8, 0)
#define  DX2LCDLR1_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX2LCDLR1_X4WDQD         GENMASK_32(24, 16)
#define  DX2LCDLR1_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX2LCDLR2        0x600108988
#define  DX2LCDLR2_DQSGD          GENMASK_32(8, 0)
#define  DX2LCDLR2_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX2LCDLR2_X4DQSGD        GENMASK_32(24, 16)
#define  DX2LCDLR2_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX2LCDLR3        0x60010898c
#define  DX2LCDLR3_RDQSD          GENMASK_32(8, 0)
#define  DX2LCDLR3_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX2LCDLR3_X4RDQSD        GENMASK_32(24, 16)
#define  DX2LCDLR3_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX2LCDLR4        0x600108990
#define  DX2LCDLR4_RDQSND         GENMASK_32(8, 0)
#define  DX2LCDLR4_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX2LCDLR4_X4RDQSND       GENMASK_32(24, 16)
#define  DX2LCDLR4_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX2LCDLR5        0x600108994
#define  DX2LCDLR5_DQSGSD         GENMASK_32(8, 0)
#define  DX2LCDLR5_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX2LCDLR5_X4DQSGSD       GENMASK_32(24, 16)
#define  DX2LCDLR5_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX2MDLR0         0x6001089a0
#define  DX2MDLR0_IPRD            GENMASK_32(8, 0)
#define  DX2MDLR0_RESERVED_15_9   GENMASK_32(15, 9)
#define  DX2MDLR0_TPRD            GENMASK_32(24, 16)
#define  DX2MDLR0_RESERVED_31_25  GENMASK_32(31, 25)

#define DDR_PHY_DX2MDLR1         0x6001089a4
#define  DX2MDLR1_MDLD            GENMASK_32(8, 0)
#define  DX2MDLR1_RESERVED_31_9   GENMASK_32(31, 9)

#define DDR_PHY_DX2GTR0          0x6001089c0
#define  DX2GTR0_DGSL             GENMASK_32(4, 0)
#define  DX2GTR0_RESERVED_7_5     GENMASK_32(7, 5)
#define  DX2GTR0_X4DGSL           GENMASK_32(12, 8)
#define  DX2GTR0_RESERVED_15_13   GENMASK_32(15, 13)
#define  DX2GTR0_WLSL             GENMASK_32(19, 16)
#define  DX2GTR0_X4WLSL           GENMASK_32(23, 20)
#define  DX2GTR0_RESERVED_31_24   GENMASK_32(31, 24)

#define DDR_PHY_DX2RSR0          0x6001089d0
#define  DX2RSR0_QSGERR           GENMASK_32(15, 0)
#define  DX2RSR0_X4QSGERR         GENMASK_32(31, 16)

#define DDR_PHY_DX2RSR1          0x6001089d4
#define  DX2RSR1_RDLVLERR         GENMASK_32(15, 0)
#define  DX2RSR1_X4RDLVLERR       GENMASK_32(31, 16)

#define DDR_PHY_DX2RSR2          0x6001089d8
#define  DX2RSR2_WLAWN            GENMASK_32(15, 0)
#define  DX2RSR2_X4WLAWN          GENMASK_32(31, 16)

#define DDR_PHY_DX2RSR3          0x6001089dc
#define  DX2RSR3_WLAERR           GENMASK_32(15, 0)
#define  DX2RSR3_X4WLAERR         GENMASK_32(31, 16)

#define DDR_PHY_DX2GSR0          0x6001089e0
#define  DX2GSR0_WDQCAL           BIT_32(0)
#define  DX2GSR0_RDQSCAL          BIT_32(1)
#define  DX2GSR0_RDQSNCAL         BIT_32(2)
#define  DX2GSR0_GDQSCAL          BIT_32(3)
#define  DX2GSR0_WLCAL            BIT_32(4)
#define  DX2GSR0_WLDONE           BIT_32(5)
#define  DX2GSR0_WLERR            BIT_32(6)
#define  DX2GSR0_WLPRD            GENMASK_32(15, 7)
#define  DX2GSR0_DPLOCK           BIT_32(16)
#define  DX2GSR0_GDQSPRD          GENMASK_32(25, 17)
#define  DX2GSR0_RESERVED_29_26   GENMASK_32(29, 26)
#define  DX2GSR0_WLDQ             BIT_32(30)
#define  DX2GSR0_RESERVED_31      BIT_32(31)

#define DDR_PHY_DX2GSR1          0x6001089e4
#define  DX2GSR1_DLTDONE          BIT_32(0)
#define  DX2GSR1_DLTCODE          GENMASK_32(24, 1)
#define  DX2GSR1_RESERVED_31_25   GENMASK_32(31, 25)

#define DDR_PHY_DX2GSR2          0x6001089e8
#define  DX2GSR2_RDERR            BIT_32(0)
#define  DX2GSR2_RDWN             BIT_32(1)
#define  DX2GSR2_WDERR            BIT_32(2)
#define  DX2GSR2_WDWN             BIT_32(3)
#define  DX2GSR2_REERR            BIT_32(4)
#define  DX2GSR2_REWN             BIT_32(5)
#define  DX2GSR2_WEERR            BIT_32(6)
#define  DX2GSR2_WEWN             BIT_32(7)
#define  DX2GSR2_ESTAT            GENMASK_32(11, 8)
#define  DX2GSR2_DBDQ             GENMASK_32(19, 12)
#define  DX2GSR2_SRDERR           BIT_32(20)
#define  DX2GSR2_RESERVED_21      BIT_32(21)
#define  DX2GSR2_GSDQSCAL         BIT_32(22)
#define  DX2GSR2_GSDQSPRD         GENMASK_32(31, 23)

#define DDR_PHY_DX2GSR3          0x6001089ec
#define  DX2GSR3_SRDPC            GENMASK_32(1, 0)
#define  DX2GSR3_RESERVED_7_2     GENMASK_32(7, 2)
#define  DX2GSR3_HVERR            GENMASK_32(11, 8)
#define  DX2GSR3_HVWRN            GENMASK_32(15, 12)
#define  DX2GSR3_DVERR            GENMASK_32(19, 16)
#define  DX2GSR3_DVWRN            GENMASK_32(23, 20)
#define  DX2GSR3_ESTAT            GENMASK_32(26, 24)
#define  DX2GSR3_RESERVED_31_27   GENMASK_32(31, 27)

#define DDR_PHY_DX2GSR4          0x6001089f0
#define  DX2GSR4_X4WDQCAL         BIT_32(0)
#define  DX2GSR4_X4RDQSCAL        BIT_32(1)
#define  DX2GSR4_X4RDQSNCAL       BIT_32(2)
#define  DX2GSR4_X4GDQSCAL        BIT_32(3)
#define  DX2GSR4_X4WLCAL          BIT_32(4)
#define  DX2GSR4_X4WLDONE         BIT_32(5)
#define  DX2GSR4_X4WLERR          BIT_32(6)
#define  DX2GSR4_X4WLPRD          GENMASK_32(15, 7)
#define  DX2GSR4_X4DPLOCK         BIT_32(16)
#define  DX2GSR4_X4GDQSPRD        GENMASK_32(25, 17)
#define  DX2GSR4_RESERVED_29_26   GENMASK_32(29, 26)
#define  DX2GSR4_X4WLDQ           BIT_32(30)
#define  DX2GSR4_RESERVED_31      BIT_32(31)

#define DDR_PHY_DX2GSR5          0x6001089f4
#define  DX2GSR5_X4RDERR          BIT_32(0)
#define  DX2GSR5_X4RDWN           BIT_32(1)
#define  DX2GSR5_X4WDERR          BIT_32(2)
#define  DX2GSR5_X4WDWN           BIT_32(3)
#define  DX2GSR5_X4REERR          BIT_32(4)
#define  DX2GSR5_X4REWN           BIT_32(5)
#define  DX2GSR5_X4WEERR          BIT_32(6)
#define  DX2GSR5_X4WEWN           BIT_32(7)
#define  DX2GSR5_X4ESTAT          GENMASK_32(11, 8)
#define  DX2GSR5_RESERVED_19_12   GENMASK_32(19, 12)
#define  DX2GSR5_X4SRDERR         BIT_32(20)
#define  DX2GSR5_RESERVED_21      BIT_32(21)
#define  DX2GSR5_X4GSDQSCAL       BIT_32(22)
#define  DX2GSR5_X4GSDQSPRD       GENMASK_32(31, 23)

#define DDR_PHY_DX2GSR6          0x6001089f8
#define  DX2GSR6_RESERVED_1_0     GENMASK_32(1, 0)
#define  DX2GSR6_X4SRDPC          GENMASK_32(3, 2)
#define  DX2GSR6_RESERVED_7_4     GENMASK_32(7, 4)
#define  DX2GSR6_X4HVERR          GENMASK_32(11, 8)
#define  DX2GSR6_X4HVWRN          GENMASK_32(15, 12)
#define  DX2GSR6_X4DVERR          GENMASK_32(19, 16)
#define  DX2GSR6_X4DVWRN          GENMASK_32(23, 20)
#define  DX2GSR6_RESERVED_31_24   GENMASK_32(31, 24)

#define DDR_PHY_DX3GCR0          0x600108a00
#define  DX3GCR0_DXEN             BIT_32(0)
#define  DX3GCR0_DXIOM            BIT_32(1)
#define  DX3GCR0_DQSGOE           BIT_32(2)
#define  DX3GCR0_DQSGODT          BIT_32(3)
#define  DX3GCR0_RESERVED_4       BIT_32(4)
#define  DX3GCR0_DQSGPDR          BIT_32(5)
#define  DX3GCR0_RESERVED_6       BIT_32(6)
#define  DX3GCR0_PDRAL            GENMASK_32(8, 7)
#define  DX3GCR0_RTTOH            GENMASK_32(10, 9)
#define  DX3GCR0_RTTOAL           BIT_32(11)
#define  DX3GCR0_DQSSEPDR         BIT_32(12)
#define  DX3GCR0_DQSNSEPDR        BIT_32(13)
#define  DX3GCR0_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX3GCR0_PLLRST           BIT_32(16)
#define  DX3GCR0_PLLPD            BIT_32(17)
#define  DX3GCR0_GSHIFT           BIT_32(18)
#define  DX3GCR0_PLLBYP           BIT_32(19)
#define  DX3GCR0_RDDLY            GENMASK_32(23, 20)
#define  DX3GCR0_RESERVED_29_24   GENMASK_32(29, 24)
#define  DX3GCR0_MDLEN            BIT_32(30)
#define  DX3GCR0_CALBYP           BIT_32(31)

#define DDR_PHY_DX3GCR1          0x600108a04
#define  DX3GCR1_RESERVED_15_0    GENMASK_32(15, 0)
#define  DX3GCR1_DXPDRMODE        GENMASK_32(31, 16)

#define DDR_PHY_DX3GCR2          0x600108a08
#define  DX3GCR2_DXTEMODE         GENMASK_32(15, 0)
#define  DX3GCR2_DXOEMODE         GENMASK_32(31, 16)

#define DDR_PHY_DX3GCR3          0x600108a0c
#define  DX3GCR3_RESERVED_1_0     GENMASK_32(1, 0)
#define  DX3GCR3_DSPDRMODE        GENMASK_32(3, 2)
#define  DX3GCR3_DSTEMODE         GENMASK_32(5, 4)
#define  DX3GCR3_DSOEMODE         GENMASK_32(7, 6)
#define  DX3GCR3_RESERVED_9_8     GENMASK_32(9, 8)
#define  DX3GCR3_DMPDRMODE        GENMASK_32(11, 10)
#define  DX3GCR3_DMTEMODE         GENMASK_32(13, 12)
#define  DX3GCR3_DMOEMODE         GENMASK_32(15, 14)
#define  DX3GCR3_RESERVED_17_16   GENMASK_32(17, 16)
#define  DX3GCR3_OEBVT            BIT_32(18)
#define  DX3GCR3_PDRBVT           BIT_32(19)
#define  DX3GCR3_TEBVT            BIT_32(20)
#define  DX3GCR3_WDSBVT           BIT_32(21)
#define  DX3GCR3_RDSBVT           BIT_32(22)
#define  DX3GCR3_RGSLVT           BIT_32(23)
#define  DX3GCR3_WLLVT            BIT_32(24)
#define  DX3GCR3_WDLVT            BIT_32(25)
#define  DX3GCR3_RDLVT            BIT_32(26)
#define  DX3GCR3_RGLVT            BIT_32(27)
#define  DX3GCR3_WDBVT            BIT_32(28)
#define  DX3GCR3_RDBVT            BIT_32(29)
#define  DX3GCR3_WDMBVT           BIT_32(30)
#define  DX3GCR3_RDMBVT           BIT_32(31)

#define DDR_PHY_DX3GCR4          0x600108a10
#define  DX3GCR4_DXREFIMON        GENMASK_32(1, 0)
#define  DX3GCR4_DXREFIEN         GENMASK_32(5, 2)
#define  DX3GCR4_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX3GCR4_DXREFSSEL        GENMASK_32(13, 8)
#define  DX3GCR4_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX3GCR4_DXREFESEL        GENMASK_32(21, 16)
#define  DX3GCR4_RESERVED_24_22   GENMASK_32(24, 22)
#define  DX3GCR4_DXREFSEN         BIT_32(25)
#define  DX3GCR4_DXREFEEN         GENMASK_32(27, 26)
#define  DX3GCR4_DXREFPEN         BIT_32(28)
#define  DX3GCR4_DXREFIOM         GENMASK_32(31, 29)

#define DDR_PHY_DX3GCR5          0x600108a14
#define  DX3GCR5_DXREFISELR0      GENMASK_32(5, 0)
#define  DX3GCR5_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX3GCR5_DXREFISELR1      GENMASK_32(13, 8)
#define  DX3GCR5_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX3GCR5_DXREFISELR2      GENMASK_32(21, 16)
#define  DX3GCR5_RESERVED_23_22   GENMASK_32(23, 22)
#define  DX3GCR5_DXREFISELR3      GENMASK_32(29, 24)
#define  DX3GCR5_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX3GCR6          0x600108a18
#define  DX3GCR6_DXDQVREFR0       GENMASK_32(5, 0)
#define  DX3GCR6_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX3GCR6_DXDQVREFR1       GENMASK_32(13, 8)
#define  DX3GCR6_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX3GCR6_DXDQVREFR2       GENMASK_32(21, 16)
#define  DX3GCR6_RESERVED_23_22   GENMASK_32(23, 22)
#define  DX3GCR6_DXDQVREFR3       GENMASK_32(29, 24)
#define  DX3GCR6_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX3GCR7          0x600108a1c
#define  DX3GCR7_RESERVED_1_0     GENMASK_32(1, 0)
#define  DX3GCR7_X4DSPDRMODE      GENMASK_32(3, 2)
#define  DX3GCR7_X4DSTEMODE       GENMASK_32(5, 4)
#define  DX3GCR7_X4DSOEMODE       GENMASK_32(7, 6)
#define  DX3GCR7_RESERVED_9_8     GENMASK_32(9, 8)
#define  DX3GCR7_X4DXPDRMODE      GENMASK_32(11, 10)
#define  DX3GCR7_X4DXTEMODE       GENMASK_32(13, 12)
#define  DX3GCR7_X4DXOEMODE       GENMASK_32(15, 14)
#define  DX3GCR7_X4DQSGOE         BIT_32(16)
#define  DX3GCR7_X4DQSGODT        BIT_32(17)
#define  DX3GCR7_RESERVED_18      BIT_32(18)
#define  DX3GCR7_X4DQSGPDR        BIT_32(19)
#define  DX3GCR7_RESERVED_20      BIT_32(20)
#define  DX3GCR7_X4DQSSEPDR       BIT_32(21)
#define  DX3GCR7_X4DQSNSEPDR      BIT_32(22)
#define  DX3GCR7_X4RTTOH          GENMASK_32(24, 23)
#define  DX3GCR7_X4RTTOAL         BIT_32(25)
#define  DX3GCR7_X4RDDLY          GENMASK_32(29, 26)
#define  DX3GCR7_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX3GCR8          0x600108a20
#define  DX3GCR8_X4DXREFISELR0    GENMASK_32(5, 0)
#define  DX3GCR8_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX3GCR8_X4DXREFISELR1    GENMASK_32(13, 8)
#define  DX3GCR8_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX3GCR8_X4DXREFISELR2    GENMASK_32(21, 16)
#define  DX3GCR8_RESERVED_23_22   GENMASK_32(23, 22)
#define  DX3GCR8_X4DXREFISELR3    GENMASK_32(29, 24)
#define  DX3GCR8_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX3GCR9          0x600108a24
#define  DX3GCR9_X4DXDQVREFR0     GENMASK_32(5, 0)
#define  DX3GCR9_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX3GCR9_X4DXDQVREFR1     GENMASK_32(13, 8)
#define  DX3GCR9_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX3GCR9_X4DXDQVREFR2     GENMASK_32(21, 16)
#define  DX3GCR9_RESERVED_23_22   GENMASK_32(23, 22)
#define  DX3GCR9_X4DXDQVREFR3     GENMASK_32(29, 24)
#define  DX3GCR9_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX3BDLR0         0x600108a40
#define  DX3BDLR0_DQ0WBD          GENMASK_32(5, 0)
#define  DX3BDLR0_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX3BDLR0_DQ1WBD          GENMASK_32(13, 8)
#define  DX3BDLR0_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX3BDLR0_DQ2WBD          GENMASK_32(21, 16)
#define  DX3BDLR0_RESERVED_23_22  GENMASK_32(23, 22)
#define  DX3BDLR0_DQ3WBD          GENMASK_32(29, 24)
#define  DX3BDLR0_RESERVED_31_30  GENMASK_32(31, 30)

#define DDR_PHY_DX3BDLR1         0x600108a44
#define  DX3BDLR1_DQ4WBD          GENMASK_32(5, 0)
#define  DX3BDLR1_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX3BDLR1_DQ5WBD          GENMASK_32(13, 8)
#define  DX3BDLR1_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX3BDLR1_DQ6WBD          GENMASK_32(21, 16)
#define  DX3BDLR1_RESERVED_23_22  GENMASK_32(23, 22)
#define  DX3BDLR1_DQ7WBD          GENMASK_32(29, 24)
#define  DX3BDLR1_RESERVED_31_30  GENMASK_32(31, 30)

#define DDR_PHY_DX3BDLR2         0x600108a48
#define  DX3BDLR2_DMWBD           GENMASK_32(5, 0)
#define  DX3BDLR2_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX3BDLR2_DSWBD           GENMASK_32(13, 8)
#define  DX3BDLR2_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX3BDLR2_DSOEBD          GENMASK_32(21, 16)
#define  DX3BDLR2_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX3BDLR3         0x600108a50
#define  DX3BDLR3_DQ0RBD          GENMASK_32(5, 0)
#define  DX3BDLR3_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX3BDLR3_DQ1RBD          GENMASK_32(13, 8)
#define  DX3BDLR3_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX3BDLR3_DQ2RBD          GENMASK_32(21, 16)
#define  DX3BDLR3_RESERVED_23_22  GENMASK_32(23, 22)
#define  DX3BDLR3_DQ3RBD          GENMASK_32(29, 24)
#define  DX3BDLR3_RESERVED_31_30  GENMASK_32(31, 30)

#define DDR_PHY_DX3BDLR4         0x600108a54
#define  DX3BDLR4_DQ4RBD          GENMASK_32(5, 0)
#define  DX3BDLR4_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX3BDLR4_DQ5RBD          GENMASK_32(13, 8)
#define  DX3BDLR4_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX3BDLR4_DQ6RBD          GENMASK_32(21, 16)
#define  DX3BDLR4_RESERVED_23_22  GENMASK_32(23, 22)
#define  DX3BDLR4_DQ7RBD          GENMASK_32(29, 24)
#define  DX3BDLR4_RESERVED_31_30  GENMASK_32(31, 30)

#define DDR_PHY_DX3BDLR5         0x600108a58
#define  DX3BDLR5_DMRBD           GENMASK_32(5, 0)
#define  DX3BDLR5_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX3BDLR5_DSRBD           GENMASK_32(13, 8)
#define  DX3BDLR5_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX3BDLR5_DSNRBD          GENMASK_32(21, 16)
#define  DX3BDLR5_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX3BDLR6         0x600108a60
#define  DX3BDLR6_RESERVED_7_0    GENMASK_32(7, 0)
#define  DX3BDLR6_PDRBD           GENMASK_32(13, 8)
#define  DX3BDLR6_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX3BDLR6_TERBD           GENMASK_32(21, 16)
#define  DX3BDLR6_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX3BDLR7         0x600108a64
#define  DX3BDLR7_X4DMWBD         GENMASK_32(5, 0)
#define  DX3BDLR7_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX3BDLR7_X4DSWBD         GENMASK_32(13, 8)
#define  DX3BDLR7_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX3BDLR7_X4DSOEBD        GENMASK_32(21, 16)
#define  DX3BDLR7_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX3BDLR8         0x600108a68
#define  DX3BDLR8_X4DMRBD         GENMASK_32(5, 0)
#define  DX3BDLR8_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX3BDLR8_X4DSRBD         GENMASK_32(13, 8)
#define  DX3BDLR8_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX3BDLR8_X4DSNRBD        GENMASK_32(21, 16)
#define  DX3BDLR8_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX3BDLR9         0x600108a6c
#define  DX3BDLR9_RESERVED_7_0    GENMASK_32(7, 0)
#define  DX3BDLR9_X4PDRBD         GENMASK_32(13, 8)
#define  DX3BDLR9_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX3BDLR9_X4TERBD         GENMASK_32(21, 16)
#define  DX3BDLR9_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX3LCDLR0        0x600108a80
#define  DX3LCDLR0_WLD            GENMASK_32(8, 0)
#define  DX3LCDLR0_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX3LCDLR0_X4WLD          GENMASK_32(24, 16)
#define  DX3LCDLR0_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX3LCDLR1        0x600108a84
#define  DX3LCDLR1_WDQD           GENMASK_32(8, 0)
#define  DX3LCDLR1_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX3LCDLR1_X4WDQD         GENMASK_32(24, 16)
#define  DX3LCDLR1_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX3LCDLR2        0x600108a88
#define  DX3LCDLR2_DQSGD          GENMASK_32(8, 0)
#define  DX3LCDLR2_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX3LCDLR2_X4DQSGD        GENMASK_32(24, 16)
#define  DX3LCDLR2_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX3LCDLR3        0x600108a8c
#define  DX3LCDLR3_RDQSD          GENMASK_32(8, 0)
#define  DX3LCDLR3_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX3LCDLR3_X4RDQSD        GENMASK_32(24, 16)
#define  DX3LCDLR3_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX3LCDLR4        0x600108a90
#define  DX3LCDLR4_RDQSND         GENMASK_32(8, 0)
#define  DX3LCDLR4_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX3LCDLR4_X4RDQSND       GENMASK_32(24, 16)
#define  DX3LCDLR4_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX3LCDLR5        0x600108a94
#define  DX3LCDLR5_DQSGSD         GENMASK_32(8, 0)
#define  DX3LCDLR5_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX3LCDLR5_X4DQSGSD       GENMASK_32(24, 16)
#define  DX3LCDLR5_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX3MDLR0         0x600108aa0
#define  DX3MDLR0_IPRD            GENMASK_32(8, 0)
#define  DX3MDLR0_RESERVED_15_9   GENMASK_32(15, 9)
#define  DX3MDLR0_TPRD            GENMASK_32(24, 16)
#define  DX3MDLR0_RESERVED_31_25  GENMASK_32(31, 25)

#define DDR_PHY_DX3MDLR1         0x600108aa4
#define  DX3MDLR1_MDLD            GENMASK_32(8, 0)
#define  DX3MDLR1_RESERVED_31_9   GENMASK_32(31, 9)

#define DDR_PHY_DX3GTR0          0x600108ac0
#define  DX3GTR0_DGSL             GENMASK_32(4, 0)
#define  DX3GTR0_RESERVED_7_5     GENMASK_32(7, 5)
#define  DX3GTR0_X4DGSL           GENMASK_32(12, 8)
#define  DX3GTR0_RESERVED_15_13   GENMASK_32(15, 13)
#define  DX3GTR0_WLSL             GENMASK_32(19, 16)
#define  DX3GTR0_X4WLSL           GENMASK_32(23, 20)
#define  DX3GTR0_RESERVED_31_24   GENMASK_32(31, 24)

#define DDR_PHY_DX3RSR0          0x600108ad0
#define  DX3RSR0_QSGERR           GENMASK_32(15, 0)
#define  DX3RSR0_X4QSGERR         GENMASK_32(31, 16)

#define DDR_PHY_DX3RSR1          0x600108ad4
#define  DX3RSR1_RDLVLERR         GENMASK_32(15, 0)
#define  DX3RSR1_X4RDLVLERR       GENMASK_32(31, 16)

#define DDR_PHY_DX3RSR2          0x600108ad8
#define  DX3RSR2_WLAWN            GENMASK_32(15, 0)
#define  DX3RSR2_X4WLAWN          GENMASK_32(31, 16)

#define DDR_PHY_DX3RSR3          0x600108adc
#define  DX3RSR3_WLAERR           GENMASK_32(15, 0)
#define  DX3RSR3_X4WLAERR         GENMASK_32(31, 16)

#define DDR_PHY_DX3GSR0          0x600108ae0
#define  DX3GSR0_WDQCAL           BIT_32(0)
#define  DX3GSR0_RDQSCAL          BIT_32(1)
#define  DX3GSR0_RDQSNCAL         BIT_32(2)
#define  DX3GSR0_GDQSCAL          BIT_32(3)
#define  DX3GSR0_WLCAL            BIT_32(4)
#define  DX3GSR0_WLDONE           BIT_32(5)
#define  DX3GSR0_WLERR            BIT_32(6)
#define  DX3GSR0_WLPRD            GENMASK_32(15, 7)
#define  DX3GSR0_DPLOCK           BIT_32(16)
#define  DX3GSR0_GDQSPRD          GENMASK_32(25, 17)
#define  DX3GSR0_RESERVED_29_26   GENMASK_32(29, 26)
#define  DX3GSR0_WLDQ             BIT_32(30)
#define  DX3GSR0_RESERVED_31      BIT_32(31)

#define DDR_PHY_DX3GSR1          0x600108ae4
#define  DX3GSR1_DLTDONE          BIT_32(0)
#define  DX3GSR1_DLTCODE          GENMASK_32(24, 1)
#define  DX3GSR1_RESERVED_31_25   GENMASK_32(31, 25)

#define DDR_PHY_DX3GSR2          0x600108ae8
#define  DX3GSR2_RDERR            BIT_32(0)
#define  DX3GSR2_RDWN             BIT_32(1)
#define  DX3GSR2_WDERR            BIT_32(2)
#define  DX3GSR2_WDWN             BIT_32(3)
#define  DX3GSR2_REERR            BIT_32(4)
#define  DX3GSR2_REWN             BIT_32(5)
#define  DX3GSR2_WEERR            BIT_32(6)
#define  DX3GSR2_WEWN             BIT_32(7)
#define  DX3GSR2_ESTAT            GENMASK_32(11, 8)
#define  DX3GSR2_DBDQ             GENMASK_32(19, 12)
#define  DX3GSR2_SRDERR           BIT_32(20)
#define  DX3GSR2_RESERVED_21      BIT_32(21)
#define  DX3GSR2_GSDQSCAL         BIT_32(22)
#define  DX3GSR2_GSDQSPRD         GENMASK_32(31, 23)

#define DDR_PHY_DX3GSR3          0x600108aec
#define  DX3GSR3_SRDPC            GENMASK_32(1, 0)
#define  DX3GSR3_RESERVED_7_2     GENMASK_32(7, 2)
#define  DX3GSR3_HVERR            GENMASK_32(11, 8)
#define  DX3GSR3_HVWRN            GENMASK_32(15, 12)
#define  DX3GSR3_DVERR            GENMASK_32(19, 16)
#define  DX3GSR3_DVWRN            GENMASK_32(23, 20)
#define  DX3GSR3_ESTAT            GENMASK_32(26, 24)
#define  DX3GSR3_RESERVED_31_27   GENMASK_32(31, 27)

#define DDR_PHY_DX3GSR4          0x600108af0
#define  DX3GSR4_X4WDQCAL         BIT_32(0)
#define  DX3GSR4_X4RDQSCAL        BIT_32(1)
#define  DX3GSR4_X4RDQSNCAL       BIT_32(2)
#define  DX3GSR4_X4GDQSCAL        BIT_32(3)
#define  DX3GSR4_X4WLCAL          BIT_32(4)
#define  DX3GSR4_X4WLDONE         BIT_32(5)
#define  DX3GSR4_X4WLERR          BIT_32(6)
#define  DX3GSR4_X4WLPRD          GENMASK_32(15, 7)
#define  DX3GSR4_X4DPLOCK         BIT_32(16)
#define  DX3GSR4_X4GDQSPRD        GENMASK_32(25, 17)
#define  DX3GSR4_RESERVED_29_26   GENMASK_32(29, 26)
#define  DX3GSR4_X4WLDQ           BIT_32(30)
#define  DX3GSR4_RESERVED_31      BIT_32(31)

#define DDR_PHY_DX3GSR5          0x600108af4
#define  DX3GSR5_X4RDERR          BIT_32(0)
#define  DX3GSR5_X4RDWN           BIT_32(1)
#define  DX3GSR5_X4WDERR          BIT_32(2)
#define  DX3GSR5_X4WDWN           BIT_32(3)
#define  DX3GSR5_X4REERR          BIT_32(4)
#define  DX3GSR5_X4REWN           BIT_32(5)
#define  DX3GSR5_X4WEERR          BIT_32(6)
#define  DX3GSR5_X4WEWN           BIT_32(7)
#define  DX3GSR5_X4ESTAT          GENMASK_32(11, 8)
#define  DX3GSR5_RESERVED_19_12   GENMASK_32(19, 12)
#define  DX3GSR5_X4SRDERR         BIT_32(20)
#define  DX3GSR5_RESERVED_21      BIT_32(21)
#define  DX3GSR5_X4GSDQSCAL       BIT_32(22)
#define  DX3GSR5_X4GSDQSPRD       GENMASK_32(31, 23)

#define DDR_PHY_DX3GSR6          0x600108af8
#define  DX3GSR6_RESERVED_1_0     GENMASK_32(1, 0)
#define  DX3GSR6_X4SRDPC          GENMASK_32(3, 2)
#define  DX3GSR6_RESERVED_7_4     GENMASK_32(7, 4)
#define  DX3GSR6_X4HVERR          GENMASK_32(11, 8)
#define  DX3GSR6_X4HVWRN          GENMASK_32(15, 12)
#define  DX3GSR6_X4DVERR          GENMASK_32(19, 16)
#define  DX3GSR6_X4DVWRN          GENMASK_32(23, 20)
#define  DX3GSR6_RESERVED_31_24   GENMASK_32(31, 24)

#define DDR_PHY_DX4GCR0          0x600108b00
#define  DX4GCR0_DXEN             BIT_32(0)
#define  DX4GCR0_DXIOM            BIT_32(1)
#define  DX4GCR0_DQSGOE           BIT_32(2)
#define  DX4GCR0_DQSGODT          BIT_32(3)
#define  DX4GCR0_RESERVED_4       BIT_32(4)
#define  DX4GCR0_DQSGPDR          BIT_32(5)
#define  DX4GCR0_RESERVED_6       BIT_32(6)
#define  DX4GCR0_PDRAL            GENMASK_32(8, 7)
#define  DX4GCR0_RTTOH            GENMASK_32(10, 9)
#define  DX4GCR0_RTTOAL           BIT_32(11)
#define  DX4GCR0_DQSSEPDR         BIT_32(12)
#define  DX4GCR0_DQSNSEPDR        BIT_32(13)
#define  DX4GCR0_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX4GCR0_PLLRST           BIT_32(16)
#define  DX4GCR0_PLLPD            BIT_32(17)
#define  DX4GCR0_GSHIFT           BIT_32(18)
#define  DX4GCR0_PLLBYP           BIT_32(19)
#define  DX4GCR0_RDDLY            GENMASK_32(23, 20)
#define  DX4GCR0_RESERVED_29_24   GENMASK_32(29, 24)
#define  DX4GCR0_MDLEN            BIT_32(30)
#define  DX4GCR0_CALBYP           BIT_32(31)

#define DDR_PHY_DX4GCR1          0x600108b04
#define  DX4GCR1_RESERVED_15_0    GENMASK_32(15, 0)
#define  DX4GCR1_DXPDRMODE        GENMASK_32(31, 16)

#define DDR_PHY_DX4GCR2          0x600108b08
#define  DX4GCR2_DXTEMODE         GENMASK_32(15, 0)
#define  DX4GCR2_DXOEMODE         GENMASK_32(31, 16)

#define DDR_PHY_DX4GCR3          0x600108b0c
#define  DX4GCR3_RESERVED_1_0     GENMASK_32(1, 0)
#define  DX4GCR3_DSPDRMODE        GENMASK_32(3, 2)
#define  DX4GCR3_DSTEMODE         GENMASK_32(5, 4)
#define  DX4GCR3_DSOEMODE         GENMASK_32(7, 6)
#define  DX4GCR3_RESERVED_9_8     GENMASK_32(9, 8)
#define  DX4GCR3_DMPDRMODE        GENMASK_32(11, 10)
#define  DX4GCR3_DMTEMODE         GENMASK_32(13, 12)
#define  DX4GCR3_DMOEMODE         GENMASK_32(15, 14)
#define  DX4GCR3_RESERVED_17_16   GENMASK_32(17, 16)
#define  DX4GCR3_OEBVT            BIT_32(18)
#define  DX4GCR3_PDRBVT           BIT_32(19)
#define  DX4GCR3_TEBVT            BIT_32(20)
#define  DX4GCR3_WDSBVT           BIT_32(21)
#define  DX4GCR3_RDSBVT           BIT_32(22)
#define  DX4GCR3_RGSLVT           BIT_32(23)
#define  DX4GCR3_WLLVT            BIT_32(24)
#define  DX4GCR3_WDLVT            BIT_32(25)
#define  DX4GCR3_RDLVT            BIT_32(26)
#define  DX4GCR3_RGLVT            BIT_32(27)
#define  DX4GCR3_WDBVT            BIT_32(28)
#define  DX4GCR3_RDBVT            BIT_32(29)
#define  DX4GCR3_WDMBVT           BIT_32(30)
#define  DX4GCR3_RDMBVT           BIT_32(31)

#define DDR_PHY_DX4GCR4          0x600108b10
#define  DX4GCR4_DXREFIMON        GENMASK_32(1, 0)
#define  DX4GCR4_DXREFIEN         GENMASK_32(5, 2)
#define  DX4GCR4_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX4GCR4_DXREFSSEL        GENMASK_32(13, 8)
#define  DX4GCR4_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX4GCR4_DXREFESEL        GENMASK_32(21, 16)
#define  DX4GCR4_RESERVED_24_22   GENMASK_32(24, 22)
#define  DX4GCR4_DXREFSEN         BIT_32(25)
#define  DX4GCR4_DXREFEEN         GENMASK_32(27, 26)
#define  DX4GCR4_DXREFPEN         BIT_32(28)
#define  DX4GCR4_DXREFIOM         GENMASK_32(31, 29)

#define DDR_PHY_DX4GCR5          0x600108b14
#define  DX4GCR5_DXREFISELR0      GENMASK_32(5, 0)
#define  DX4GCR5_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX4GCR5_DXREFISELR1      GENMASK_32(13, 8)
#define  DX4GCR5_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX4GCR5_DXREFISELR2      GENMASK_32(21, 16)
#define  DX4GCR5_RESERVED_23_22   GENMASK_32(23, 22)
#define  DX4GCR5_DXREFISELR3      GENMASK_32(29, 24)
#define  DX4GCR5_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX4GCR6          0x600108b18
#define  DX4GCR6_DXDQVREFR0       GENMASK_32(5, 0)
#define  DX4GCR6_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX4GCR6_DXDQVREFR1       GENMASK_32(13, 8)
#define  DX4GCR6_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX4GCR6_DXDQVREFR2       GENMASK_32(21, 16)
#define  DX4GCR6_RESERVED_23_22   GENMASK_32(23, 22)
#define  DX4GCR6_DXDQVREFR3       GENMASK_32(29, 24)
#define  DX4GCR6_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX4GCR7          0x600108b1c
#define  DX4GCR7_RESERVED_1_0     GENMASK_32(1, 0)
#define  DX4GCR7_X4DSPDRMODE      GENMASK_32(3, 2)
#define  DX4GCR7_X4DSTEMODE       GENMASK_32(5, 4)
#define  DX4GCR7_X4DSOEMODE       GENMASK_32(7, 6)
#define  DX4GCR7_RESERVED_9_8     GENMASK_32(9, 8)
#define  DX4GCR7_X4DXPDRMODE      GENMASK_32(11, 10)
#define  DX4GCR7_X4DXTEMODE       GENMASK_32(13, 12)
#define  DX4GCR7_X4DXOEMODE       GENMASK_32(15, 14)
#define  DX4GCR7_X4DQSGOE         BIT_32(16)
#define  DX4GCR7_X4DQSGODT        BIT_32(17)
#define  DX4GCR7_RESERVED_18      BIT_32(18)
#define  DX4GCR7_X4DQSGPDR        BIT_32(19)
#define  DX4GCR7_RESERVED_20      BIT_32(20)
#define  DX4GCR7_X4DQSSEPDR       BIT_32(21)
#define  DX4GCR7_X4DQSNSEPDR      BIT_32(22)
#define  DX4GCR7_X4RTTOH          GENMASK_32(24, 23)
#define  DX4GCR7_X4RTTOAL         BIT_32(25)
#define  DX4GCR7_X4RDDLY          GENMASK_32(29, 26)
#define  DX4GCR7_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX4GCR8          0x600108b20
#define  DX4GCR8_X4DXREFISELR0    GENMASK_32(5, 0)
#define  DX4GCR8_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX4GCR8_X4DXREFISELR1    GENMASK_32(13, 8)
#define  DX4GCR8_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX4GCR8_X4DXREFISELR2    GENMASK_32(21, 16)
#define  DX4GCR8_RESERVED_23_22   GENMASK_32(23, 22)
#define  DX4GCR8_X4DXREFISELR3    GENMASK_32(29, 24)
#define  DX4GCR8_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX4GCR9          0x600108b24
#define  DX4GCR9_X4DXDQVREFR0     GENMASK_32(5, 0)
#define  DX4GCR9_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX4GCR9_X4DXDQVREFR1     GENMASK_32(13, 8)
#define  DX4GCR9_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX4GCR9_X4DXDQVREFR2     GENMASK_32(21, 16)
#define  DX4GCR9_RESERVED_23_22   GENMASK_32(23, 22)
#define  DX4GCR9_X4DXDQVREFR3     GENMASK_32(29, 24)
#define  DX4GCR9_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX4BDLR0         0x600108b40
#define  DX4BDLR0_DQ0WBD          GENMASK_32(5, 0)
#define  DX4BDLR0_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX4BDLR0_DQ1WBD          GENMASK_32(13, 8)
#define  DX4BDLR0_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX4BDLR0_DQ2WBD          GENMASK_32(21, 16)
#define  DX4BDLR0_RESERVED_23_22  GENMASK_32(23, 22)
#define  DX4BDLR0_DQ3WBD          GENMASK_32(29, 24)
#define  DX4BDLR0_RESERVED_31_30  GENMASK_32(31, 30)

#define DDR_PHY_DX4BDLR1         0x600108b44
#define  DX4BDLR1_DQ4WBD          GENMASK_32(5, 0)
#define  DX4BDLR1_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX4BDLR1_DQ5WBD          GENMASK_32(13, 8)
#define  DX4BDLR1_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX4BDLR1_DQ6WBD          GENMASK_32(21, 16)
#define  DX4BDLR1_RESERVED_23_22  GENMASK_32(23, 22)
#define  DX4BDLR1_DQ7WBD          GENMASK_32(29, 24)
#define  DX4BDLR1_RESERVED_31_30  GENMASK_32(31, 30)

#define DDR_PHY_DX4BDLR2         0x600108b48
#define  DX4BDLR2_DMWBD           GENMASK_32(5, 0)
#define  DX4BDLR2_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX4BDLR2_DSWBD           GENMASK_32(13, 8)
#define  DX4BDLR2_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX4BDLR2_DSOEBD          GENMASK_32(21, 16)
#define  DX4BDLR2_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX4BDLR3         0x600108b50
#define  DX4BDLR3_DQ0RBD          GENMASK_32(5, 0)
#define  DX4BDLR3_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX4BDLR3_DQ1RBD          GENMASK_32(13, 8)
#define  DX4BDLR3_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX4BDLR3_DQ2RBD          GENMASK_32(21, 16)
#define  DX4BDLR3_RESERVED_23_22  GENMASK_32(23, 22)
#define  DX4BDLR3_DQ3RBD          GENMASK_32(29, 24)
#define  DX4BDLR3_RESERVED_31_30  GENMASK_32(31, 30)

#define DDR_PHY_DX4BDLR4         0x600108b54
#define  DX4BDLR4_DQ4RBD          GENMASK_32(5, 0)
#define  DX4BDLR4_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX4BDLR4_DQ5RBD          GENMASK_32(13, 8)
#define  DX4BDLR4_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX4BDLR4_DQ6RBD          GENMASK_32(21, 16)
#define  DX4BDLR4_RESERVED_23_22  GENMASK_32(23, 22)
#define  DX4BDLR4_DQ7RBD          GENMASK_32(29, 24)
#define  DX4BDLR4_RESERVED_31_30  GENMASK_32(31, 30)

#define DDR_PHY_DX4BDLR5         0x600108b58
#define  DX4BDLR5_DMRBD           GENMASK_32(5, 0)
#define  DX4BDLR5_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX4BDLR5_DSRBD           GENMASK_32(13, 8)
#define  DX4BDLR5_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX4BDLR5_DSNRBD          GENMASK_32(21, 16)
#define  DX4BDLR5_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX4BDLR6         0x600108b60
#define  DX4BDLR6_RESERVED_7_0    GENMASK_32(7, 0)
#define  DX4BDLR6_PDRBD           GENMASK_32(13, 8)
#define  DX4BDLR6_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX4BDLR6_TERBD           GENMASK_32(21, 16)
#define  DX4BDLR6_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX4BDLR7         0x600108b64
#define  DX4BDLR7_X4DMWBD         GENMASK_32(5, 0)
#define  DX4BDLR7_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX4BDLR7_X4DSWBD         GENMASK_32(13, 8)
#define  DX4BDLR7_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX4BDLR7_X4DSOEBD        GENMASK_32(21, 16)
#define  DX4BDLR7_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX4BDLR8         0x600108b68
#define  DX4BDLR8_X4DMRBD         GENMASK_32(5, 0)
#define  DX4BDLR8_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX4BDLR8_X4DSRBD         GENMASK_32(13, 8)
#define  DX4BDLR8_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX4BDLR8_X4DSNRBD        GENMASK_32(21, 16)
#define  DX4BDLR8_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX4BDLR9         0x600108b6c
#define  DX4BDLR9_RESERVED_7_0    GENMASK_32(7, 0)
#define  DX4BDLR9_X4PDRBD         GENMASK_32(13, 8)
#define  DX4BDLR9_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX4BDLR9_X4TERBD         GENMASK_32(21, 16)
#define  DX4BDLR9_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX4LCDLR0        0x600108b80
#define  DX4LCDLR0_WLD            GENMASK_32(8, 0)
#define  DX4LCDLR0_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX4LCDLR0_X4WLD          GENMASK_32(24, 16)
#define  DX4LCDLR0_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX4LCDLR1        0x600108b84
#define  DX4LCDLR1_WDQD           GENMASK_32(8, 0)
#define  DX4LCDLR1_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX4LCDLR1_X4WDQD         GENMASK_32(24, 16)
#define  DX4LCDLR1_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX4LCDLR2        0x600108b88
#define  DX4LCDLR2_DQSGD          GENMASK_32(8, 0)
#define  DX4LCDLR2_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX4LCDLR2_X4DQSGD        GENMASK_32(24, 16)
#define  DX4LCDLR2_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX4LCDLR3        0x600108b8c
#define  DX4LCDLR3_RDQSD          GENMASK_32(8, 0)
#define  DX4LCDLR3_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX4LCDLR3_X4RDQSD        GENMASK_32(24, 16)
#define  DX4LCDLR3_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX4LCDLR4        0x600108b90
#define  DX4LCDLR4_RDQSND         GENMASK_32(8, 0)
#define  DX4LCDLR4_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX4LCDLR4_X4RDQSND       GENMASK_32(24, 16)
#define  DX4LCDLR4_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX4LCDLR5        0x600108b94
#define  DX4LCDLR5_DQSGSD         GENMASK_32(8, 0)
#define  DX4LCDLR5_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX4LCDLR5_X4DQSGSD       GENMASK_32(24, 16)
#define  DX4LCDLR5_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX4MDLR0         0x600108ba0
#define  DX4MDLR0_IPRD            GENMASK_32(8, 0)
#define  DX4MDLR0_RESERVED_15_9   GENMASK_32(15, 9)
#define  DX4MDLR0_TPRD            GENMASK_32(24, 16)
#define  DX4MDLR0_RESERVED_31_25  GENMASK_32(31, 25)

#define DDR_PHY_DX4MDLR1         0x600108ba4
#define  DX4MDLR1_MDLD            GENMASK_32(8, 0)
#define  DX4MDLR1_RESERVED_31_9   GENMASK_32(31, 9)

#define DDR_PHY_DX4GTR0          0x600108bc0
#define  DX4GTR0_DGSL             GENMASK_32(4, 0)
#define  DX4GTR0_RESERVED_7_5     GENMASK_32(7, 5)
#define  DX4GTR0_X4DGSL           GENMASK_32(12, 8)
#define  DX4GTR0_RESERVED_15_13   GENMASK_32(15, 13)
#define  DX4GTR0_WLSL             GENMASK_32(19, 16)
#define  DX4GTR0_X4WLSL           GENMASK_32(23, 20)
#define  DX4GTR0_RESERVED_31_24   GENMASK_32(31, 24)

#define DDR_PHY_DX4RSR0          0x600108bd0
#define  DX4RSR0_QSGERR           GENMASK_32(15, 0)
#define  DX4RSR0_X4QSGERR         GENMASK_32(31, 16)

#define DDR_PHY_DX4RSR1          0x600108bd4
#define  DX4RSR1_RDLVLERR         GENMASK_32(15, 0)
#define  DX4RSR1_X4RDLVLERR       GENMASK_32(31, 16)

#define DDR_PHY_DX4RSR2          0x600108bd8
#define  DX4RSR2_WLAWN            GENMASK_32(15, 0)
#define  DX4RSR2_X4WLAWN          GENMASK_32(31, 16)

#define DDR_PHY_DX4RSR3          0x600108bdc
#define  DX4RSR3_WLAERR           GENMASK_32(15, 0)
#define  DX4RSR3_X4WLAERR         GENMASK_32(31, 16)

#define DDR_PHY_DX4GSR0          0x600108be0
#define  DX4GSR0_WDQCAL           BIT_32(0)
#define  DX4GSR0_RDQSCAL          BIT_32(1)
#define  DX4GSR0_RDQSNCAL         BIT_32(2)
#define  DX4GSR0_GDQSCAL          BIT_32(3)
#define  DX4GSR0_WLCAL            BIT_32(4)
#define  DX4GSR0_WLDONE           BIT_32(5)
#define  DX4GSR0_WLERR            BIT_32(6)
#define  DX4GSR0_WLPRD            GENMASK_32(15, 7)
#define  DX4GSR0_DPLOCK           BIT_32(16)
#define  DX4GSR0_GDQSPRD          GENMASK_32(25, 17)
#define  DX4GSR0_RESERVED_29_26   GENMASK_32(29, 26)
#define  DX4GSR0_WLDQ             BIT_32(30)
#define  DX4GSR0_RESERVED_31      BIT_32(31)

#define DDR_PHY_DX4GSR1          0x600108be4
#define  DX4GSR1_DLTDONE          BIT_32(0)
#define  DX4GSR1_DLTCODE          GENMASK_32(24, 1)
#define  DX4GSR1_RESERVED_31_25   GENMASK_32(31, 25)

#define DDR_PHY_DX4GSR2          0x600108be8
#define  DX4GSR2_RDERR            BIT_32(0)
#define  DX4GSR2_RDWN             BIT_32(1)
#define  DX4GSR2_WDERR            BIT_32(2)
#define  DX4GSR2_WDWN             BIT_32(3)
#define  DX4GSR2_REERR            BIT_32(4)
#define  DX4GSR2_REWN             BIT_32(5)
#define  DX4GSR2_WEERR            BIT_32(6)
#define  DX4GSR2_WEWN             BIT_32(7)
#define  DX4GSR2_ESTAT            GENMASK_32(11, 8)
#define  DX4GSR2_DBDQ             GENMASK_32(19, 12)
#define  DX4GSR2_SRDERR           BIT_32(20)
#define  DX4GSR2_RESERVED_21      BIT_32(21)
#define  DX4GSR2_GSDQSCAL         BIT_32(22)
#define  DX4GSR2_GSDQSPRD         GENMASK_32(31, 23)

#define DDR_PHY_DX4GSR3          0x600108bec
#define  DX4GSR3_SRDPC            GENMASK_32(1, 0)
#define  DX4GSR3_RESERVED_7_2     GENMASK_32(7, 2)
#define  DX4GSR3_HVERR            GENMASK_32(11, 8)
#define  DX4GSR3_HVWRN            GENMASK_32(15, 12)
#define  DX4GSR3_DVERR            GENMASK_32(19, 16)
#define  DX4GSR3_DVWRN            GENMASK_32(23, 20)
#define  DX4GSR3_ESTAT            GENMASK_32(26, 24)
#define  DX4GSR3_RESERVED_31_27   GENMASK_32(31, 27)

#define DDR_PHY_DX4GSR4          0x600108bf0
#define  DX4GSR4_X4WDQCAL         BIT_32(0)
#define  DX4GSR4_X4RDQSCAL        BIT_32(1)
#define  DX4GSR4_X4RDQSNCAL       BIT_32(2)
#define  DX4GSR4_X4GDQSCAL        BIT_32(3)
#define  DX4GSR4_X4WLCAL          BIT_32(4)
#define  DX4GSR4_X4WLDONE         BIT_32(5)
#define  DX4GSR4_X4WLERR          BIT_32(6)
#define  DX4GSR4_X4WLPRD          GENMASK_32(15, 7)
#define  DX4GSR4_X4DPLOCK         BIT_32(16)
#define  DX4GSR4_X4GDQSPRD        GENMASK_32(25, 17)
#define  DX4GSR4_RESERVED_29_26   GENMASK_32(29, 26)
#define  DX4GSR4_X4WLDQ           BIT_32(30)
#define  DX4GSR4_RESERVED_31      BIT_32(31)

#define DDR_PHY_DX4GSR5          0x600108bf4
#define  DX4GSR5_X4RDERR          BIT_32(0)
#define  DX4GSR5_X4RDWN           BIT_32(1)
#define  DX4GSR5_X4WDERR          BIT_32(2)
#define  DX4GSR5_X4WDWN           BIT_32(3)
#define  DX4GSR5_X4REERR          BIT_32(4)
#define  DX4GSR5_X4REWN           BIT_32(5)
#define  DX4GSR5_X4WEERR          BIT_32(6)
#define  DX4GSR5_X4WEWN           BIT_32(7)
#define  DX4GSR5_X4ESTAT          GENMASK_32(11, 8)
#define  DX4GSR5_RESERVED_19_12   GENMASK_32(19, 12)
#define  DX4GSR5_X4SRDERR         BIT_32(20)
#define  DX4GSR5_RESERVED_21      BIT_32(21)
#define  DX4GSR5_X4GSDQSCAL       BIT_32(22)
#define  DX4GSR5_X4GSDQSPRD       GENMASK_32(31, 23)

#define DDR_PHY_DX4GSR6          0x600108bf8
#define  DX4GSR6_RESERVED_1_0     GENMASK_32(1, 0)
#define  DX4GSR6_X4SRDPC          GENMASK_32(3, 2)
#define  DX4GSR6_RESERVED_7_4     GENMASK_32(7, 4)
#define  DX4GSR6_X4HVERR          GENMASK_32(11, 8)
#define  DX4GSR6_X4HVWRN          GENMASK_32(15, 12)
#define  DX4GSR6_X4DVERR          GENMASK_32(19, 16)
#define  DX4GSR6_X4DVWRN          GENMASK_32(23, 20)
#define  DX4GSR6_RESERVED_31_24   GENMASK_32(31, 24)

#define DDR_PHY_DX5GCR0          0x600108c00
#define  DX5GCR0_DXEN             BIT_32(0)
#define  DX5GCR0_DXIOM            BIT_32(1)
#define  DX5GCR0_DQSGOE           BIT_32(2)
#define  DX5GCR0_DQSGODT          BIT_32(3)
#define  DX5GCR0_RESERVED_4       BIT_32(4)
#define  DX5GCR0_DQSGPDR          BIT_32(5)
#define  DX5GCR0_RESERVED_6       BIT_32(6)
#define  DX5GCR0_PDRAL            GENMASK_32(8, 7)
#define  DX5GCR0_RTTOH            GENMASK_32(10, 9)
#define  DX5GCR0_RTTOAL           BIT_32(11)
#define  DX5GCR0_DQSSEPDR         BIT_32(12)
#define  DX5GCR0_DQSNSEPDR        BIT_32(13)
#define  DX5GCR0_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX5GCR0_PLLRST           BIT_32(16)
#define  DX5GCR0_PLLPD            BIT_32(17)
#define  DX5GCR0_GSHIFT           BIT_32(18)
#define  DX5GCR0_PLLBYP           BIT_32(19)
#define  DX5GCR0_RDDLY            GENMASK_32(23, 20)
#define  DX5GCR0_RESERVED_29_24   GENMASK_32(29, 24)
#define  DX5GCR0_MDLEN            BIT_32(30)
#define  DX5GCR0_CALBYP           BIT_32(31)

#define DDR_PHY_DX5GCR1          0x600108c04
#define  DX5GCR1_RESERVED_15_0    GENMASK_32(15, 0)
#define  DX5GCR1_DXPDRMODE        GENMASK_32(31, 16)

#define DDR_PHY_DX5GCR2          0x600108c08
#define  DX5GCR2_DXTEMODE         GENMASK_32(15, 0)
#define  DX5GCR2_DXOEMODE         GENMASK_32(31, 16)

#define DDR_PHY_DX5GCR3          0x600108c0c
#define  DX5GCR3_RESERVED_1_0     GENMASK_32(1, 0)
#define  DX5GCR3_DSPDRMODE        GENMASK_32(3, 2)
#define  DX5GCR3_DSTEMODE         GENMASK_32(5, 4)
#define  DX5GCR3_DSOEMODE         GENMASK_32(7, 6)
#define  DX5GCR3_RESERVED_9_8     GENMASK_32(9, 8)
#define  DX5GCR3_DMPDRMODE        GENMASK_32(11, 10)
#define  DX5GCR3_DMTEMODE         GENMASK_32(13, 12)
#define  DX5GCR3_DMOEMODE         GENMASK_32(15, 14)
#define  DX5GCR3_RESERVED_17_16   GENMASK_32(17, 16)
#define  DX5GCR3_OEBVT            BIT_32(18)
#define  DX5GCR3_PDRBVT           BIT_32(19)
#define  DX5GCR3_TEBVT            BIT_32(20)
#define  DX5GCR3_WDSBVT           BIT_32(21)
#define  DX5GCR3_RDSBVT           BIT_32(22)
#define  DX5GCR3_RGSLVT           BIT_32(23)
#define  DX5GCR3_WLLVT            BIT_32(24)
#define  DX5GCR3_WDLVT            BIT_32(25)
#define  DX5GCR3_RDLVT            BIT_32(26)
#define  DX5GCR3_RGLVT            BIT_32(27)
#define  DX5GCR3_WDBVT            BIT_32(28)
#define  DX5GCR3_RDBVT            BIT_32(29)
#define  DX5GCR3_WDMBVT           BIT_32(30)
#define  DX5GCR3_RDMBVT           BIT_32(31)

#define DDR_PHY_DX5GCR4          0x600108c10
#define  DX5GCR4_DXREFIMON        GENMASK_32(1, 0)
#define  DX5GCR4_DXREFIEN         GENMASK_32(5, 2)
#define  DX5GCR4_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX5GCR4_DXREFSSEL        GENMASK_32(13, 8)
#define  DX5GCR4_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX5GCR4_DXREFESEL        GENMASK_32(21, 16)
#define  DX5GCR4_RESERVED_24_22   GENMASK_32(24, 22)
#define  DX5GCR4_DXREFSEN         BIT_32(25)
#define  DX5GCR4_DXREFEEN         GENMASK_32(27, 26)
#define  DX5GCR4_DXREFPEN         BIT_32(28)
#define  DX5GCR4_DXREFIOM         GENMASK_32(31, 29)

#define DDR_PHY_DX5GCR5          0x600108c14
#define  DX5GCR5_DXREFISELR0      GENMASK_32(5, 0)
#define  DX5GCR5_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX5GCR5_DXREFISELR1      GENMASK_32(13, 8)
#define  DX5GCR5_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX5GCR5_DXREFISELR2      GENMASK_32(21, 16)
#define  DX5GCR5_RESERVED_23_22   GENMASK_32(23, 22)
#define  DX5GCR5_DXREFISELR3      GENMASK_32(29, 24)
#define  DX5GCR5_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX5GCR6          0x600108c18
#define  DX5GCR6_DXDQVREFR0       GENMASK_32(5, 0)
#define  DX5GCR6_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX5GCR6_DXDQVREFR1       GENMASK_32(13, 8)
#define  DX5GCR6_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX5GCR6_DXDQVREFR2       GENMASK_32(21, 16)
#define  DX5GCR6_RESERVED_23_22   GENMASK_32(23, 22)
#define  DX5GCR6_DXDQVREFR3       GENMASK_32(29, 24)
#define  DX5GCR6_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX5GCR7          0x600108c1c
#define  DX5GCR7_RESERVED_1_0     GENMASK_32(1, 0)
#define  DX5GCR7_X4DSPDRMODE      GENMASK_32(3, 2)
#define  DX5GCR7_X4DSTEMODE       GENMASK_32(5, 4)
#define  DX5GCR7_X4DSOEMODE       GENMASK_32(7, 6)
#define  DX5GCR7_RESERVED_9_8     GENMASK_32(9, 8)
#define  DX5GCR7_X4DXPDRMODE      GENMASK_32(11, 10)
#define  DX5GCR7_X4DXTEMODE       GENMASK_32(13, 12)
#define  DX5GCR7_X4DXOEMODE       GENMASK_32(15, 14)
#define  DX5GCR7_X4DQSGOE         BIT_32(16)
#define  DX5GCR7_X4DQSGODT        BIT_32(17)
#define  DX5GCR7_RESERVED_18      BIT_32(18)
#define  DX5GCR7_X4DQSGPDR        BIT_32(19)
#define  DX5GCR7_RESERVED_20      BIT_32(20)
#define  DX5GCR7_X4DQSSEPDR       BIT_32(21)
#define  DX5GCR7_X4DQSNSEPDR      BIT_32(22)
#define  DX5GCR7_X4RTTOH          GENMASK_32(24, 23)
#define  DX5GCR7_X4RTTOAL         BIT_32(25)
#define  DX5GCR7_X4RDDLY          GENMASK_32(29, 26)
#define  DX5GCR7_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX5GCR8          0x600108c20
#define  DX5GCR8_X4DXREFISELR0    GENMASK_32(5, 0)
#define  DX5GCR8_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX5GCR8_X4DXREFISELR1    GENMASK_32(13, 8)
#define  DX5GCR8_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX5GCR8_X4DXREFISELR2    GENMASK_32(21, 16)
#define  DX5GCR8_RESERVED_23_22   GENMASK_32(23, 22)
#define  DX5GCR8_X4DXREFISELR3    GENMASK_32(29, 24)
#define  DX5GCR8_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX5GCR9          0x600108c24
#define  DX5GCR9_X4DXDQVREFR0     GENMASK_32(5, 0)
#define  DX5GCR9_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX5GCR9_X4DXDQVREFR1     GENMASK_32(13, 8)
#define  DX5GCR9_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX5GCR9_X4DXDQVREFR2     GENMASK_32(21, 16)
#define  DX5GCR9_RESERVED_23_22   GENMASK_32(23, 22)
#define  DX5GCR9_X4DXDQVREFR3     GENMASK_32(29, 24)
#define  DX5GCR9_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX5BDLR0         0x600108c40
#define  DX5BDLR0_DQ0WBD          GENMASK_32(5, 0)
#define  DX5BDLR0_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX5BDLR0_DQ1WBD          GENMASK_32(13, 8)
#define  DX5BDLR0_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX5BDLR0_DQ2WBD          GENMASK_32(21, 16)
#define  DX5BDLR0_RESERVED_23_22  GENMASK_32(23, 22)
#define  DX5BDLR0_DQ3WBD          GENMASK_32(29, 24)
#define  DX5BDLR0_RESERVED_31_30  GENMASK_32(31, 30)

#define DDR_PHY_DX5BDLR1         0x600108c44
#define  DX5BDLR1_DQ4WBD          GENMASK_32(5, 0)
#define  DX5BDLR1_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX5BDLR1_DQ5WBD          GENMASK_32(13, 8)
#define  DX5BDLR1_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX5BDLR1_DQ6WBD          GENMASK_32(21, 16)
#define  DX5BDLR1_RESERVED_23_22  GENMASK_32(23, 22)
#define  DX5BDLR1_DQ7WBD          GENMASK_32(29, 24)
#define  DX5BDLR1_RESERVED_31_30  GENMASK_32(31, 30)

#define DDR_PHY_DX5BDLR2         0x600108c48
#define  DX5BDLR2_DMWBD           GENMASK_32(5, 0)
#define  DX5BDLR2_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX5BDLR2_DSWBD           GENMASK_32(13, 8)
#define  DX5BDLR2_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX5BDLR2_DSOEBD          GENMASK_32(21, 16)
#define  DX5BDLR2_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX5BDLR3         0x600108c50
#define  DX5BDLR3_DQ0RBD          GENMASK_32(5, 0)
#define  DX5BDLR3_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX5BDLR3_DQ1RBD          GENMASK_32(13, 8)
#define  DX5BDLR3_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX5BDLR3_DQ2RBD          GENMASK_32(21, 16)
#define  DX5BDLR3_RESERVED_23_22  GENMASK_32(23, 22)
#define  DX5BDLR3_DQ3RBD          GENMASK_32(29, 24)
#define  DX5BDLR3_RESERVED_31_30  GENMASK_32(31, 30)

#define DDR_PHY_DX5BDLR4         0x600108c54
#define  DX5BDLR4_DQ4RBD          GENMASK_32(5, 0)
#define  DX5BDLR4_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX5BDLR4_DQ5RBD          GENMASK_32(13, 8)
#define  DX5BDLR4_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX5BDLR4_DQ6RBD          GENMASK_32(21, 16)
#define  DX5BDLR4_RESERVED_23_22  GENMASK_32(23, 22)
#define  DX5BDLR4_DQ7RBD          GENMASK_32(29, 24)
#define  DX5BDLR4_RESERVED_31_30  GENMASK_32(31, 30)

#define DDR_PHY_DX5BDLR5         0x600108c58
#define  DX5BDLR5_DMRBD           GENMASK_32(5, 0)
#define  DX5BDLR5_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX5BDLR5_DSRBD           GENMASK_32(13, 8)
#define  DX5BDLR5_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX5BDLR5_DSNRBD          GENMASK_32(21, 16)
#define  DX5BDLR5_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX5BDLR6         0x600108c60
#define  DX5BDLR6_RESERVED_7_0    GENMASK_32(7, 0)
#define  DX5BDLR6_PDRBD           GENMASK_32(13, 8)
#define  DX5BDLR6_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX5BDLR6_TERBD           GENMASK_32(21, 16)
#define  DX5BDLR6_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX5BDLR7         0x600108c64
#define  DX5BDLR7_X4DMWBD         GENMASK_32(5, 0)
#define  DX5BDLR7_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX5BDLR7_X4DSWBD         GENMASK_32(13, 8)
#define  DX5BDLR7_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX5BDLR7_X4DSOEBD        GENMASK_32(21, 16)
#define  DX5BDLR7_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX5BDLR8         0x600108c68
#define  DX5BDLR8_X4DMRBD         GENMASK_32(5, 0)
#define  DX5BDLR8_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX5BDLR8_X4DSRBD         GENMASK_32(13, 8)
#define  DX5BDLR8_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX5BDLR8_X4DSNRBD        GENMASK_32(21, 16)
#define  DX5BDLR8_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX5BDLR9         0x600108c6c
#define  DX5BDLR9_RESERVED_7_0    GENMASK_32(7, 0)
#define  DX5BDLR9_X4PDRBD         GENMASK_32(13, 8)
#define  DX5BDLR9_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX5BDLR9_X4TERBD         GENMASK_32(21, 16)
#define  DX5BDLR9_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX5LCDLR0        0x600108c80
#define  DX5LCDLR0_WLD            GENMASK_32(8, 0)
#define  DX5LCDLR0_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX5LCDLR0_X4WLD          GENMASK_32(24, 16)
#define  DX5LCDLR0_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX5LCDLR1        0x600108c84
#define  DX5LCDLR1_WDQD           GENMASK_32(8, 0)
#define  DX5LCDLR1_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX5LCDLR1_X4WDQD         GENMASK_32(24, 16)
#define  DX5LCDLR1_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX5LCDLR2        0x600108c88
#define  DX5LCDLR2_DQSGD          GENMASK_32(8, 0)
#define  DX5LCDLR2_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX5LCDLR2_X4DQSGD        GENMASK_32(24, 16)
#define  DX5LCDLR2_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX5LCDLR3        0x600108c8c
#define  DX5LCDLR3_RDQSD          GENMASK_32(8, 0)
#define  DX5LCDLR3_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX5LCDLR3_X4RDQSD        GENMASK_32(24, 16)
#define  DX5LCDLR3_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX5LCDLR4        0x600108c90
#define  DX5LCDLR4_RDQSND         GENMASK_32(8, 0)
#define  DX5LCDLR4_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX5LCDLR4_X4RDQSND       GENMASK_32(24, 16)
#define  DX5LCDLR4_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX5LCDLR5        0x600108c94
#define  DX5LCDLR5_DQSGSD         GENMASK_32(8, 0)
#define  DX5LCDLR5_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX5LCDLR5_X4DQSGSD       GENMASK_32(24, 16)
#define  DX5LCDLR5_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX5MDLR0         0x600108ca0
#define  DX5MDLR0_IPRD            GENMASK_32(8, 0)
#define  DX5MDLR0_RESERVED_15_9   GENMASK_32(15, 9)
#define  DX5MDLR0_TPRD            GENMASK_32(24, 16)
#define  DX5MDLR0_RESERVED_31_25  GENMASK_32(31, 25)

#define DDR_PHY_DX5MDLR1         0x600108ca4
#define  DX5MDLR1_MDLD            GENMASK_32(8, 0)
#define  DX5MDLR1_RESERVED_31_9   GENMASK_32(31, 9)

#define DDR_PHY_DX5GTR0          0x600108cc0
#define  DX5GTR0_DGSL             GENMASK_32(4, 0)
#define  DX5GTR0_RESERVED_7_5     GENMASK_32(7, 5)
#define  DX5GTR0_X4DGSL           GENMASK_32(12, 8)
#define  DX5GTR0_RESERVED_15_13   GENMASK_32(15, 13)
#define  DX5GTR0_WLSL             GENMASK_32(19, 16)
#define  DX5GTR0_X4WLSL           GENMASK_32(23, 20)
#define  DX5GTR0_RESERVED_31_24   GENMASK_32(31, 24)

#define DDR_PHY_DX5RSR0          0x600108cd0
#define  DX5RSR0_QSGERR           GENMASK_32(15, 0)
#define  DX5RSR0_X4QSGERR         GENMASK_32(31, 16)

#define DDR_PHY_DX5RSR1          0x600108cd4
#define  DX5RSR1_RDLVLERR         GENMASK_32(15, 0)
#define  DX5RSR1_X4RDLVLERR       GENMASK_32(31, 16)

#define DDR_PHY_DX5RSR2          0x600108cd8
#define  DX5RSR2_WLAWN            GENMASK_32(15, 0)
#define  DX5RSR2_X4WLAWN          GENMASK_32(31, 16)

#define DDR_PHY_DX5RSR3          0x600108cdc
#define  DX5RSR3_WLAERR           GENMASK_32(15, 0)
#define  DX5RSR3_X4WLAERR         GENMASK_32(31, 16)

#define DDR_PHY_DX5GSR0          0x600108ce0
#define  DX5GSR0_WDQCAL           BIT_32(0)
#define  DX5GSR0_RDQSCAL          BIT_32(1)
#define  DX5GSR0_RDQSNCAL         BIT_32(2)
#define  DX5GSR0_GDQSCAL          BIT_32(3)
#define  DX5GSR0_WLCAL            BIT_32(4)
#define  DX5GSR0_WLDONE           BIT_32(5)
#define  DX5GSR0_WLERR            BIT_32(6)
#define  DX5GSR0_WLPRD            GENMASK_32(15, 7)
#define  DX5GSR0_DPLOCK           BIT_32(16)
#define  DX5GSR0_GDQSPRD          GENMASK_32(25, 17)
#define  DX5GSR0_RESERVED_29_26   GENMASK_32(29, 26)
#define  DX5GSR0_WLDQ             BIT_32(30)
#define  DX5GSR0_RESERVED_31      BIT_32(31)

#define DDR_PHY_DX5GSR1          0x600108ce4
#define  DX5GSR1_DLTDONE          BIT_32(0)
#define  DX5GSR1_DLTCODE          GENMASK_32(24, 1)
#define  DX5GSR1_RESERVED_31_25   GENMASK_32(31, 25)

#define DDR_PHY_DX5GSR2          0x600108ce8
#define  DX5GSR2_RDERR            BIT_32(0)
#define  DX5GSR2_RDWN             BIT_32(1)
#define  DX5GSR2_WDERR            BIT_32(2)
#define  DX5GSR2_WDWN             BIT_32(3)
#define  DX5GSR2_REERR            BIT_32(4)
#define  DX5GSR2_REWN             BIT_32(5)
#define  DX5GSR2_WEERR            BIT_32(6)
#define  DX5GSR2_WEWN             BIT_32(7)
#define  DX5GSR2_ESTAT            GENMASK_32(11, 8)
#define  DX5GSR2_DBDQ             GENMASK_32(19, 12)
#define  DX5GSR2_SRDERR           BIT_32(20)
#define  DX5GSR2_RESERVED_21      BIT_32(21)
#define  DX5GSR2_GSDQSCAL         BIT_32(22)
#define  DX5GSR2_GSDQSPRD         GENMASK_32(31, 23)

#define DDR_PHY_DX5GSR3          0x600108cec
#define  DX5GSR3_SRDPC            GENMASK_32(1, 0)
#define  DX5GSR3_RESERVED_7_2     GENMASK_32(7, 2)
#define  DX5GSR3_HVERR            GENMASK_32(11, 8)
#define  DX5GSR3_HVWRN            GENMASK_32(15, 12)
#define  DX5GSR3_DVERR            GENMASK_32(19, 16)
#define  DX5GSR3_DVWRN            GENMASK_32(23, 20)
#define  DX5GSR3_ESTAT            GENMASK_32(26, 24)
#define  DX5GSR3_RESERVED_31_27   GENMASK_32(31, 27)

#define DDR_PHY_DX5GSR4          0x600108cf0
#define  DX5GSR4_X4WDQCAL         BIT_32(0)
#define  DX5GSR4_X4RDQSCAL        BIT_32(1)
#define  DX5GSR4_X4RDQSNCAL       BIT_32(2)
#define  DX5GSR4_X4GDQSCAL        BIT_32(3)
#define  DX5GSR4_X4WLCAL          BIT_32(4)
#define  DX5GSR4_X4WLDONE         BIT_32(5)
#define  DX5GSR4_X4WLERR          BIT_32(6)
#define  DX5GSR4_X4WLPRD          GENMASK_32(15, 7)
#define  DX5GSR4_X4DPLOCK         BIT_32(16)
#define  DX5GSR4_X4GDQSPRD        GENMASK_32(25, 17)
#define  DX5GSR4_RESERVED_29_26   GENMASK_32(29, 26)
#define  DX5GSR4_X4WLDQ           BIT_32(30)
#define  DX5GSR4_RESERVED_31      BIT_32(31)

#define DDR_PHY_DX5GSR5          0x600108cf4
#define  DX5GSR5_X4RDERR          BIT_32(0)
#define  DX5GSR5_X4RDWN           BIT_32(1)
#define  DX5GSR5_X4WDERR          BIT_32(2)
#define  DX5GSR5_X4WDWN           BIT_32(3)
#define  DX5GSR5_X4REERR          BIT_32(4)
#define  DX5GSR5_X4REWN           BIT_32(5)
#define  DX5GSR5_X4WEERR          BIT_32(6)
#define  DX5GSR5_X4WEWN           BIT_32(7)
#define  DX5GSR5_X4ESTAT          GENMASK_32(11, 8)
#define  DX5GSR5_RESERVED_19_12   GENMASK_32(19, 12)
#define  DX5GSR5_X4SRDERR         BIT_32(20)
#define  DX5GSR5_RESERVED_21      BIT_32(21)
#define  DX5GSR5_X4GSDQSCAL       BIT_32(22)
#define  DX5GSR5_X4GSDQSPRD       GENMASK_32(31, 23)

#define DDR_PHY_DX5GSR6          0x600108cf8
#define  DX5GSR6_RESERVED_1_0     GENMASK_32(1, 0)
#define  DX5GSR6_X4SRDPC          GENMASK_32(3, 2)
#define  DX5GSR6_RESERVED_7_4     GENMASK_32(7, 4)
#define  DX5GSR6_X4HVERR          GENMASK_32(11, 8)
#define  DX5GSR6_X4HVWRN          GENMASK_32(15, 12)
#define  DX5GSR6_X4DVERR          GENMASK_32(19, 16)
#define  DX5GSR6_X4DVWRN          GENMASK_32(23, 20)
#define  DX5GSR6_RESERVED_31_24   GENMASK_32(31, 24)

#define DDR_PHY_DX6GCR0          0x600108d00
#define  DX6GCR0_DXEN             BIT_32(0)
#define  DX6GCR0_DXIOM            BIT_32(1)
#define  DX6GCR0_DQSGOE           BIT_32(2)
#define  DX6GCR0_DQSGODT          BIT_32(3)
#define  DX6GCR0_RESERVED_4       BIT_32(4)
#define  DX6GCR0_DQSGPDR          BIT_32(5)
#define  DX6GCR0_RESERVED_6       BIT_32(6)
#define  DX6GCR0_PDRAL            GENMASK_32(8, 7)
#define  DX6GCR0_RTTOH            GENMASK_32(10, 9)
#define  DX6GCR0_RTTOAL           BIT_32(11)
#define  DX6GCR0_DQSSEPDR         BIT_32(12)
#define  DX6GCR0_DQSNSEPDR        BIT_32(13)
#define  DX6GCR0_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX6GCR0_PLLRST           BIT_32(16)
#define  DX6GCR0_PLLPD            BIT_32(17)
#define  DX6GCR0_GSHIFT           BIT_32(18)
#define  DX6GCR0_PLLBYP           BIT_32(19)
#define  DX6GCR0_RDDLY            GENMASK_32(23, 20)
#define  DX6GCR0_RESERVED_29_24   GENMASK_32(29, 24)
#define  DX6GCR0_MDLEN            BIT_32(30)
#define  DX6GCR0_CALBYP           BIT_32(31)

#define DDR_PHY_DX6GCR1          0x600108d04
#define  DX6GCR1_RESERVED_15_0    GENMASK_32(15, 0)
#define  DX6GCR1_DXPDRMODE        GENMASK_32(31, 16)

#define DDR_PHY_DX6GCR2          0x600108d08
#define  DX6GCR2_DXTEMODE         GENMASK_32(15, 0)
#define  DX6GCR2_DXOEMODE         GENMASK_32(31, 16)

#define DDR_PHY_DX6GCR3          0x600108d0c
#define  DX6GCR3_RESERVED_1_0     GENMASK_32(1, 0)
#define  DX6GCR3_DSPDRMODE        GENMASK_32(3, 2)
#define  DX6GCR3_DSTEMODE         GENMASK_32(5, 4)
#define  DX6GCR3_DSOEMODE         GENMASK_32(7, 6)
#define  DX6GCR3_RESERVED_9_8     GENMASK_32(9, 8)
#define  DX6GCR3_DMPDRMODE        GENMASK_32(11, 10)
#define  DX6GCR3_DMTEMODE         GENMASK_32(13, 12)
#define  DX6GCR3_DMOEMODE         GENMASK_32(15, 14)
#define  DX6GCR3_RESERVED_17_16   GENMASK_32(17, 16)
#define  DX6GCR3_OEBVT            BIT_32(18)
#define  DX6GCR3_PDRBVT           BIT_32(19)
#define  DX6GCR3_TEBVT            BIT_32(20)
#define  DX6GCR3_WDSBVT           BIT_32(21)
#define  DX6GCR3_RDSBVT           BIT_32(22)
#define  DX6GCR3_RGSLVT           BIT_32(23)
#define  DX6GCR3_WLLVT            BIT_32(24)
#define  DX6GCR3_WDLVT            BIT_32(25)
#define  DX6GCR3_RDLVT            BIT_32(26)
#define  DX6GCR3_RGLVT            BIT_32(27)
#define  DX6GCR3_WDBVT            BIT_32(28)
#define  DX6GCR3_RDBVT            BIT_32(29)
#define  DX6GCR3_WDMBVT           BIT_32(30)
#define  DX6GCR3_RDMBVT           BIT_32(31)

#define DDR_PHY_DX6GCR4          0x600108d10
#define  DX6GCR4_DXREFIMON        GENMASK_32(1, 0)
#define  DX6GCR4_DXREFIEN         GENMASK_32(5, 2)
#define  DX6GCR4_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX6GCR4_DXREFSSEL        GENMASK_32(13, 8)
#define  DX6GCR4_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX6GCR4_DXREFESEL        GENMASK_32(21, 16)
#define  DX6GCR4_RESERVED_24_22   GENMASK_32(24, 22)
#define  DX6GCR4_DXREFSEN         BIT_32(25)
#define  DX6GCR4_DXREFEEN         GENMASK_32(27, 26)
#define  DX6GCR4_DXREFPEN         BIT_32(28)
#define  DX6GCR4_DXREFIOM         GENMASK_32(31, 29)

#define DDR_PHY_DX6GCR5          0x600108d14
#define  DX6GCR5_DXREFISELR0      GENMASK_32(5, 0)
#define  DX6GCR5_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX6GCR5_DXREFISELR1      GENMASK_32(13, 8)
#define  DX6GCR5_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX6GCR5_DXREFISELR2      GENMASK_32(21, 16)
#define  DX6GCR5_RESERVED_23_22   GENMASK_32(23, 22)
#define  DX6GCR5_DXREFISELR3      GENMASK_32(29, 24)
#define  DX6GCR5_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX6GCR6          0x600108d18
#define  DX6GCR6_DXDQVREFR0       GENMASK_32(5, 0)
#define  DX6GCR6_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX6GCR6_DXDQVREFR1       GENMASK_32(13, 8)
#define  DX6GCR6_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX6GCR6_DXDQVREFR2       GENMASK_32(21, 16)
#define  DX6GCR6_RESERVED_23_22   GENMASK_32(23, 22)
#define  DX6GCR6_DXDQVREFR3       GENMASK_32(29, 24)
#define  DX6GCR6_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX6GCR7          0x600108d1c
#define  DX6GCR7_RESERVED_1_0     GENMASK_32(1, 0)
#define  DX6GCR7_X4DSPDRMODE      GENMASK_32(3, 2)
#define  DX6GCR7_X4DSTEMODE       GENMASK_32(5, 4)
#define  DX6GCR7_X4DSOEMODE       GENMASK_32(7, 6)
#define  DX6GCR7_RESERVED_9_8     GENMASK_32(9, 8)
#define  DX6GCR7_X4DXPDRMODE      GENMASK_32(11, 10)
#define  DX6GCR7_X4DXTEMODE       GENMASK_32(13, 12)
#define  DX6GCR7_X4DXOEMODE       GENMASK_32(15, 14)
#define  DX6GCR7_X4DQSGOE         BIT_32(16)
#define  DX6GCR7_X4DQSGODT        BIT_32(17)
#define  DX6GCR7_RESERVED_18      BIT_32(18)
#define  DX6GCR7_X4DQSGPDR        BIT_32(19)
#define  DX6GCR7_RESERVED_20      BIT_32(20)
#define  DX6GCR7_X4DQSSEPDR       BIT_32(21)
#define  DX6GCR7_X4DQSNSEPDR      BIT_32(22)
#define  DX6GCR7_X4RTTOH          GENMASK_32(24, 23)
#define  DX6GCR7_X4RTTOAL         BIT_32(25)
#define  DX6GCR7_X4RDDLY          GENMASK_32(29, 26)
#define  DX6GCR7_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX6GCR8          0x600108d20
#define  DX6GCR8_X4DXREFISELR0    GENMASK_32(5, 0)
#define  DX6GCR8_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX6GCR8_X4DXREFISELR1    GENMASK_32(13, 8)
#define  DX6GCR8_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX6GCR8_X4DXREFISELR2    GENMASK_32(21, 16)
#define  DX6GCR8_RESERVED_23_22   GENMASK_32(23, 22)
#define  DX6GCR8_X4DXREFISELR3    GENMASK_32(29, 24)
#define  DX6GCR8_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX6GCR9          0x600108d24
#define  DX6GCR9_X4DXDQVREFR0     GENMASK_32(5, 0)
#define  DX6GCR9_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX6GCR9_X4DXDQVREFR1     GENMASK_32(13, 8)
#define  DX6GCR9_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX6GCR9_X4DXDQVREFR2     GENMASK_32(21, 16)
#define  DX6GCR9_RESERVED_23_22   GENMASK_32(23, 22)
#define  DX6GCR9_X4DXDQVREFR3     GENMASK_32(29, 24)
#define  DX6GCR9_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX6BDLR0         0x600108d40
#define  DX6BDLR0_DQ0WBD          GENMASK_32(5, 0)
#define  DX6BDLR0_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX6BDLR0_DQ1WBD          GENMASK_32(13, 8)
#define  DX6BDLR0_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX6BDLR0_DQ2WBD          GENMASK_32(21, 16)
#define  DX6BDLR0_RESERVED_23_22  GENMASK_32(23, 22)
#define  DX6BDLR0_DQ3WBD          GENMASK_32(29, 24)
#define  DX6BDLR0_RESERVED_31_30  GENMASK_32(31, 30)

#define DDR_PHY_DX6BDLR1         0x600108d44
#define  DX6BDLR1_DQ4WBD          GENMASK_32(5, 0)
#define  DX6BDLR1_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX6BDLR1_DQ5WBD          GENMASK_32(13, 8)
#define  DX6BDLR1_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX6BDLR1_DQ6WBD          GENMASK_32(21, 16)
#define  DX6BDLR1_RESERVED_23_22  GENMASK_32(23, 22)
#define  DX6BDLR1_DQ7WBD          GENMASK_32(29, 24)
#define  DX6BDLR1_RESERVED_31_30  GENMASK_32(31, 30)

#define DDR_PHY_DX6BDLR2         0x600108d48
#define  DX6BDLR2_DMWBD           GENMASK_32(5, 0)
#define  DX6BDLR2_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX6BDLR2_DSWBD           GENMASK_32(13, 8)
#define  DX6BDLR2_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX6BDLR2_DSOEBD          GENMASK_32(21, 16)
#define  DX6BDLR2_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX6BDLR3         0x600108d50
#define  DX6BDLR3_DQ0RBD          GENMASK_32(5, 0)
#define  DX6BDLR3_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX6BDLR3_DQ1RBD          GENMASK_32(13, 8)
#define  DX6BDLR3_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX6BDLR3_DQ2RBD          GENMASK_32(21, 16)
#define  DX6BDLR3_RESERVED_23_22  GENMASK_32(23, 22)
#define  DX6BDLR3_DQ3RBD          GENMASK_32(29, 24)
#define  DX6BDLR3_RESERVED_31_30  GENMASK_32(31, 30)

#define DDR_PHY_DX6BDLR4         0x600108d54
#define  DX6BDLR4_DQ4RBD          GENMASK_32(5, 0)
#define  DX6BDLR4_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX6BDLR4_DQ5RBD          GENMASK_32(13, 8)
#define  DX6BDLR4_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX6BDLR4_DQ6RBD          GENMASK_32(21, 16)
#define  DX6BDLR4_RESERVED_23_22  GENMASK_32(23, 22)
#define  DX6BDLR4_DQ7RBD          GENMASK_32(29, 24)
#define  DX6BDLR4_RESERVED_31_30  GENMASK_32(31, 30)

#define DDR_PHY_DX6BDLR5         0x600108d58
#define  DX6BDLR5_DMRBD           GENMASK_32(5, 0)
#define  DX6BDLR5_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX6BDLR5_DSRBD           GENMASK_32(13, 8)
#define  DX6BDLR5_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX6BDLR5_DSNRBD          GENMASK_32(21, 16)
#define  DX6BDLR5_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX6BDLR6         0x600108d60
#define  DX6BDLR6_RESERVED_7_0    GENMASK_32(7, 0)
#define  DX6BDLR6_PDRBD           GENMASK_32(13, 8)
#define  DX6BDLR6_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX6BDLR6_TERBD           GENMASK_32(21, 16)
#define  DX6BDLR6_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX6BDLR7         0x600108d64
#define  DX6BDLR7_X4DMWBD         GENMASK_32(5, 0)
#define  DX6BDLR7_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX6BDLR7_X4DSWBD         GENMASK_32(13, 8)
#define  DX6BDLR7_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX6BDLR7_X4DSOEBD        GENMASK_32(21, 16)
#define  DX6BDLR7_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX6BDLR8         0x600108d68
#define  DX6BDLR8_X4DMRBD         GENMASK_32(5, 0)
#define  DX6BDLR8_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX6BDLR8_X4DSRBD         GENMASK_32(13, 8)
#define  DX6BDLR8_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX6BDLR8_X4DSNRBD        GENMASK_32(21, 16)
#define  DX6BDLR8_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX6BDLR9         0x600108d6c
#define  DX6BDLR9_RESERVED_7_0    GENMASK_32(7, 0)
#define  DX6BDLR9_X4PDRBD         GENMASK_32(13, 8)
#define  DX6BDLR9_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX6BDLR9_X4TERBD         GENMASK_32(21, 16)
#define  DX6BDLR9_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX6LCDLR0        0x600108d80
#define  DX6LCDLR0_WLD            GENMASK_32(8, 0)
#define  DX6LCDLR0_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX6LCDLR0_X4WLD          GENMASK_32(24, 16)
#define  DX6LCDLR0_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX6LCDLR1        0x600108d84
#define  DX6LCDLR1_WDQD           GENMASK_32(8, 0)
#define  DX6LCDLR1_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX6LCDLR1_X4WDQD         GENMASK_32(24, 16)
#define  DX6LCDLR1_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX6LCDLR2        0x600108d88
#define  DX6LCDLR2_DQSGD          GENMASK_32(8, 0)
#define  DX6LCDLR2_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX6LCDLR2_X4DQSGD        GENMASK_32(24, 16)
#define  DX6LCDLR2_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX6LCDLR3        0x600108d8c
#define  DX6LCDLR3_RDQSD          GENMASK_32(8, 0)
#define  DX6LCDLR3_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX6LCDLR3_X4RDQSD        GENMASK_32(24, 16)
#define  DX6LCDLR3_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX6LCDLR4        0x600108d90
#define  DX6LCDLR4_RDQSND         GENMASK_32(8, 0)
#define  DX6LCDLR4_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX6LCDLR4_X4RDQSND       GENMASK_32(24, 16)
#define  DX6LCDLR4_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX6LCDLR5        0x600108d94
#define  DX6LCDLR5_DQSGSD         GENMASK_32(8, 0)
#define  DX6LCDLR5_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX6LCDLR5_X4DQSGSD       GENMASK_32(24, 16)
#define  DX6LCDLR5_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX6MDLR0         0x600108da0
#define  DX6MDLR0_IPRD            GENMASK_32(8, 0)
#define  DX6MDLR0_RESERVED_15_9   GENMASK_32(15, 9)
#define  DX6MDLR0_TPRD            GENMASK_32(24, 16)
#define  DX6MDLR0_RESERVED_31_25  GENMASK_32(31, 25)

#define DDR_PHY_DX6MDLR1         0x600108da4
#define  DX6MDLR1_MDLD            GENMASK_32(8, 0)
#define  DX6MDLR1_RESERVED_31_9   GENMASK_32(31, 9)

#define DDR_PHY_DX6GTR0          0x600108dc0
#define  DX6GTR0_DGSL             GENMASK_32(4, 0)
#define  DX6GTR0_RESERVED_7_5     GENMASK_32(7, 5)
#define  DX6GTR0_X4DGSL           GENMASK_32(12, 8)
#define  DX6GTR0_RESERVED_15_13   GENMASK_32(15, 13)
#define  DX6GTR0_WLSL             GENMASK_32(19, 16)
#define  DX6GTR0_X4WLSL           GENMASK_32(23, 20)
#define  DX6GTR0_RESERVED_31_24   GENMASK_32(31, 24)

#define DDR_PHY_DX6RSR0          0x600108dd0
#define  DX6RSR0_QSGERR           GENMASK_32(15, 0)
#define  DX6RSR0_X4QSGERR         GENMASK_32(31, 16)

#define DDR_PHY_DX6RSR1          0x600108dd4
#define  DX6RSR1_RDLVLERR         GENMASK_32(15, 0)
#define  DX6RSR1_X4RDLVLERR       GENMASK_32(31, 16)

#define DDR_PHY_DX6RSR2          0x600108dd8
#define  DX6RSR2_WLAWN            GENMASK_32(15, 0)
#define  DX6RSR2_X4WLAWN          GENMASK_32(31, 16)

#define DDR_PHY_DX6RSR3          0x600108ddc
#define  DX6RSR3_WLAERR           GENMASK_32(15, 0)
#define  DX6RSR3_X4WLAERR         GENMASK_32(31, 16)

#define DDR_PHY_DX6GSR0          0x600108de0
#define  DX6GSR0_WDQCAL           BIT_32(0)
#define  DX6GSR0_RDQSCAL          BIT_32(1)
#define  DX6GSR0_RDQSNCAL         BIT_32(2)
#define  DX6GSR0_GDQSCAL          BIT_32(3)
#define  DX6GSR0_WLCAL            BIT_32(4)
#define  DX6GSR0_WLDONE           BIT_32(5)
#define  DX6GSR0_WLERR            BIT_32(6)
#define  DX6GSR0_WLPRD            GENMASK_32(15, 7)
#define  DX6GSR0_DPLOCK           BIT_32(16)
#define  DX6GSR0_GDQSPRD          GENMASK_32(25, 17)
#define  DX6GSR0_RESERVED_29_26   GENMASK_32(29, 26)
#define  DX6GSR0_WLDQ             BIT_32(30)
#define  DX6GSR0_RESERVED_31      BIT_32(31)

#define DDR_PHY_DX6GSR1          0x600108de4
#define  DX6GSR1_DLTDONE          BIT_32(0)
#define  DX6GSR1_DLTCODE          GENMASK_32(24, 1)
#define  DX6GSR1_RESERVED_31_25   GENMASK_32(31, 25)

#define DDR_PHY_DX6GSR2          0x600108de8
#define  DX6GSR2_RDERR            BIT_32(0)
#define  DX6GSR2_RDWN             BIT_32(1)
#define  DX6GSR2_WDERR            BIT_32(2)
#define  DX6GSR2_WDWN             BIT_32(3)
#define  DX6GSR2_REERR            BIT_32(4)
#define  DX6GSR2_REWN             BIT_32(5)
#define  DX6GSR2_WEERR            BIT_32(6)
#define  DX6GSR2_WEWN             BIT_32(7)
#define  DX6GSR2_ESTAT            GENMASK_32(11, 8)
#define  DX6GSR2_DBDQ             GENMASK_32(19, 12)
#define  DX6GSR2_SRDERR           BIT_32(20)
#define  DX6GSR2_RESERVED_21      BIT_32(21)
#define  DX6GSR2_GSDQSCAL         BIT_32(22)
#define  DX6GSR2_GSDQSPRD         GENMASK_32(31, 23)

#define DDR_PHY_DX6GSR3          0x600108dec
#define  DX6GSR3_SRDPC            GENMASK_32(1, 0)
#define  DX6GSR3_RESERVED_7_2     GENMASK_32(7, 2)
#define  DX6GSR3_HVERR            GENMASK_32(11, 8)
#define  DX6GSR3_HVWRN            GENMASK_32(15, 12)
#define  DX6GSR3_DVERR            GENMASK_32(19, 16)
#define  DX6GSR3_DVWRN            GENMASK_32(23, 20)
#define  DX6GSR3_ESTAT            GENMASK_32(26, 24)
#define  DX6GSR3_RESERVED_31_27   GENMASK_32(31, 27)

#define DDR_PHY_DX6GSR4          0x600108df0
#define  DX6GSR4_X4WDQCAL         BIT_32(0)
#define  DX6GSR4_X4RDQSCAL        BIT_32(1)
#define  DX6GSR4_X4RDQSNCAL       BIT_32(2)
#define  DX6GSR4_X4GDQSCAL        BIT_32(3)
#define  DX6GSR4_X4WLCAL          BIT_32(4)
#define  DX6GSR4_X4WLDONE         BIT_32(5)
#define  DX6GSR4_X4WLERR          BIT_32(6)
#define  DX6GSR4_X4WLPRD          GENMASK_32(15, 7)
#define  DX6GSR4_X4DPLOCK         BIT_32(16)
#define  DX6GSR4_X4GDQSPRD        GENMASK_32(25, 17)
#define  DX6GSR4_RESERVED_29_26   GENMASK_32(29, 26)
#define  DX6GSR4_X4WLDQ           BIT_32(30)
#define  DX6GSR4_RESERVED_31      BIT_32(31)

#define DDR_PHY_DX6GSR5          0x600108df4
#define  DX6GSR5_X4RDERR          BIT_32(0)
#define  DX6GSR5_X4RDWN           BIT_32(1)
#define  DX6GSR5_X4WDERR          BIT_32(2)
#define  DX6GSR5_X4WDWN           BIT_32(3)
#define  DX6GSR5_X4REERR          BIT_32(4)
#define  DX6GSR5_X4REWN           BIT_32(5)
#define  DX6GSR5_X4WEERR          BIT_32(6)
#define  DX6GSR5_X4WEWN           BIT_32(7)
#define  DX6GSR5_X4ESTAT          GENMASK_32(11, 8)
#define  DX6GSR5_RESERVED_19_12   GENMASK_32(19, 12)
#define  DX6GSR5_X4SRDERR         BIT_32(20)
#define  DX6GSR5_RESERVED_21      BIT_32(21)
#define  DX6GSR5_X4GSDQSCAL       BIT_32(22)
#define  DX6GSR5_X4GSDQSPRD       GENMASK_32(31, 23)

#define DDR_PHY_DX6GSR6          0x600108df8
#define  DX6GSR6_RESERVED_1_0     GENMASK_32(1, 0)
#define  DX6GSR6_X4SRDPC          GENMASK_32(3, 2)
#define  DX6GSR6_RESERVED_7_4     GENMASK_32(7, 4)
#define  DX6GSR6_X4HVERR          GENMASK_32(11, 8)
#define  DX6GSR6_X4HVWRN          GENMASK_32(15, 12)
#define  DX6GSR6_X4DVERR          GENMASK_32(19, 16)
#define  DX6GSR6_X4DVWRN          GENMASK_32(23, 20)
#define  DX6GSR6_RESERVED_31_24   GENMASK_32(31, 24)

#define DDR_PHY_DX7GCR0          0x600108e00
#define  DX7GCR0_DXEN             BIT_32(0)
#define  DX7GCR0_DXIOM            BIT_32(1)
#define  DX7GCR0_DQSGOE           BIT_32(2)
#define  DX7GCR0_DQSGODT          BIT_32(3)
#define  DX7GCR0_RESERVED_4       BIT_32(4)
#define  DX7GCR0_DQSGPDR          BIT_32(5)
#define  DX7GCR0_RESERVED_6       BIT_32(6)
#define  DX7GCR0_PDRAL            GENMASK_32(8, 7)
#define  DX7GCR0_RTTOH            GENMASK_32(10, 9)
#define  DX7GCR0_RTTOAL           BIT_32(11)
#define  DX7GCR0_DQSSEPDR         BIT_32(12)
#define  DX7GCR0_DQSNSEPDR        BIT_32(13)
#define  DX7GCR0_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX7GCR0_PLLRST           BIT_32(16)
#define  DX7GCR0_PLLPD            BIT_32(17)
#define  DX7GCR0_GSHIFT           BIT_32(18)
#define  DX7GCR0_PLLBYP           BIT_32(19)
#define  DX7GCR0_RDDLY            GENMASK_32(23, 20)
#define  DX7GCR0_RESERVED_29_24   GENMASK_32(29, 24)
#define  DX7GCR0_MDLEN            BIT_32(30)
#define  DX7GCR0_CALBYP           BIT_32(31)

#define DDR_PHY_DX7GCR1          0x600108e04
#define  DX7GCR1_RESERVED_15_0    GENMASK_32(15, 0)
#define  DX7GCR1_DXPDRMODE        GENMASK_32(31, 16)

#define DDR_PHY_DX7GCR2          0x600108e08
#define  DX7GCR2_DXTEMODE         GENMASK_32(15, 0)
#define  DX7GCR2_DXOEMODE         GENMASK_32(31, 16)

#define DDR_PHY_DX7GCR3          0x600108e0c
#define  DX7GCR3_RESERVED_1_0     GENMASK_32(1, 0)
#define  DX7GCR3_DSPDRMODE        GENMASK_32(3, 2)
#define  DX7GCR3_DSTEMODE         GENMASK_32(5, 4)
#define  DX7GCR3_DSOEMODE         GENMASK_32(7, 6)
#define  DX7GCR3_RESERVED_9_8     GENMASK_32(9, 8)
#define  DX7GCR3_DMPDRMODE        GENMASK_32(11, 10)
#define  DX7GCR3_DMTEMODE         GENMASK_32(13, 12)
#define  DX7GCR3_DMOEMODE         GENMASK_32(15, 14)
#define  DX7GCR3_RESERVED_17_16   GENMASK_32(17, 16)
#define  DX7GCR3_OEBVT            BIT_32(18)
#define  DX7GCR3_PDRBVT           BIT_32(19)
#define  DX7GCR3_TEBVT            BIT_32(20)
#define  DX7GCR3_WDSBVT           BIT_32(21)
#define  DX7GCR3_RDSBVT           BIT_32(22)
#define  DX7GCR3_RGSLVT           BIT_32(23)
#define  DX7GCR3_WLLVT            BIT_32(24)
#define  DX7GCR3_WDLVT            BIT_32(25)
#define  DX7GCR3_RDLVT            BIT_32(26)
#define  DX7GCR3_RGLVT            BIT_32(27)
#define  DX7GCR3_WDBVT            BIT_32(28)
#define  DX7GCR3_RDBVT            BIT_32(29)
#define  DX7GCR3_WDMBVT           BIT_32(30)
#define  DX7GCR3_RDMBVT           BIT_32(31)

#define DDR_PHY_DX7GCR4          0x600108e10
#define  DX7GCR4_DXREFIMON        GENMASK_32(1, 0)
#define  DX7GCR4_DXREFIEN         GENMASK_32(5, 2)
#define  DX7GCR4_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX7GCR4_DXREFSSEL        GENMASK_32(13, 8)
#define  DX7GCR4_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX7GCR4_DXREFESEL        GENMASK_32(21, 16)
#define  DX7GCR4_RESERVED_24_22   GENMASK_32(24, 22)
#define  DX7GCR4_DXREFSEN         BIT_32(25)
#define  DX7GCR4_DXREFEEN         GENMASK_32(27, 26)
#define  DX7GCR4_DXREFPEN         BIT_32(28)
#define  DX7GCR4_DXREFIOM         GENMASK_32(31, 29)

#define DDR_PHY_DX7GCR5          0x600108e14
#define  DX7GCR5_DXREFISELR0      GENMASK_32(5, 0)
#define  DX7GCR5_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX7GCR5_DXREFISELR1      GENMASK_32(13, 8)
#define  DX7GCR5_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX7GCR5_DXREFISELR2      GENMASK_32(21, 16)
#define  DX7GCR5_RESERVED_23_22   GENMASK_32(23, 22)
#define  DX7GCR5_DXREFISELR3      GENMASK_32(29, 24)
#define  DX7GCR5_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX7GCR6          0x600108e18
#define  DX7GCR6_DXDQVREFR0       GENMASK_32(5, 0)
#define  DX7GCR6_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX7GCR6_DXDQVREFR1       GENMASK_32(13, 8)
#define  DX7GCR6_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX7GCR6_DXDQVREFR2       GENMASK_32(21, 16)
#define  DX7GCR6_RESERVED_23_22   GENMASK_32(23, 22)
#define  DX7GCR6_DXDQVREFR3       GENMASK_32(29, 24)
#define  DX7GCR6_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX7GCR7          0x600108e1c
#define  DX7GCR7_RESERVED_1_0     GENMASK_32(1, 0)
#define  DX7GCR7_X4DSPDRMODE      GENMASK_32(3, 2)
#define  DX7GCR7_X4DSTEMODE       GENMASK_32(5, 4)
#define  DX7GCR7_X4DSOEMODE       GENMASK_32(7, 6)
#define  DX7GCR7_RESERVED_9_8     GENMASK_32(9, 8)
#define  DX7GCR7_X4DXPDRMODE      GENMASK_32(11, 10)
#define  DX7GCR7_X4DXTEMODE       GENMASK_32(13, 12)
#define  DX7GCR7_X4DXOEMODE       GENMASK_32(15, 14)
#define  DX7GCR7_X4DQSGOE         BIT_32(16)
#define  DX7GCR7_X4DQSGODT        BIT_32(17)
#define  DX7GCR7_RESERVED_18      BIT_32(18)
#define  DX7GCR7_X4DQSGPDR        BIT_32(19)
#define  DX7GCR7_RESERVED_20      BIT_32(20)
#define  DX7GCR7_X4DQSSEPDR       BIT_32(21)
#define  DX7GCR7_X4DQSNSEPDR      BIT_32(22)
#define  DX7GCR7_X4RTTOH          GENMASK_32(24, 23)
#define  DX7GCR7_X4RTTOAL         BIT_32(25)
#define  DX7GCR7_X4RDDLY          GENMASK_32(29, 26)
#define  DX7GCR7_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX7GCR8          0x600108e20
#define  DX7GCR8_X4DXREFISELR0    GENMASK_32(5, 0)
#define  DX7GCR8_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX7GCR8_X4DXREFISELR1    GENMASK_32(13, 8)
#define  DX7GCR8_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX7GCR8_X4DXREFISELR2    GENMASK_32(21, 16)
#define  DX7GCR8_RESERVED_23_22   GENMASK_32(23, 22)
#define  DX7GCR8_X4DXREFISELR3    GENMASK_32(29, 24)
#define  DX7GCR8_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX7GCR9          0x600108e24
#define  DX7GCR9_X4DXDQVREFR0     GENMASK_32(5, 0)
#define  DX7GCR9_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX7GCR9_X4DXDQVREFR1     GENMASK_32(13, 8)
#define  DX7GCR9_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX7GCR9_X4DXDQVREFR2     GENMASK_32(21, 16)
#define  DX7GCR9_RESERVED_23_22   GENMASK_32(23, 22)
#define  DX7GCR9_X4DXDQVREFR3     GENMASK_32(29, 24)
#define  DX7GCR9_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX7BDLR0         0x600108e40
#define  DX7BDLR0_DQ0WBD          GENMASK_32(5, 0)
#define  DX7BDLR0_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX7BDLR0_DQ1WBD          GENMASK_32(13, 8)
#define  DX7BDLR0_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX7BDLR0_DQ2WBD          GENMASK_32(21, 16)
#define  DX7BDLR0_RESERVED_23_22  GENMASK_32(23, 22)
#define  DX7BDLR0_DQ3WBD          GENMASK_32(29, 24)
#define  DX7BDLR0_RESERVED_31_30  GENMASK_32(31, 30)

#define DDR_PHY_DX7BDLR1         0x600108e44
#define  DX7BDLR1_DQ4WBD          GENMASK_32(5, 0)
#define  DX7BDLR1_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX7BDLR1_DQ5WBD          GENMASK_32(13, 8)
#define  DX7BDLR1_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX7BDLR1_DQ6WBD          GENMASK_32(21, 16)
#define  DX7BDLR1_RESERVED_23_22  GENMASK_32(23, 22)
#define  DX7BDLR1_DQ7WBD          GENMASK_32(29, 24)
#define  DX7BDLR1_RESERVED_31_30  GENMASK_32(31, 30)

#define DDR_PHY_DX7BDLR2         0x600108e48
#define  DX7BDLR2_DMWBD           GENMASK_32(5, 0)
#define  DX7BDLR2_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX7BDLR2_DSWBD           GENMASK_32(13, 8)
#define  DX7BDLR2_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX7BDLR2_DSOEBD          GENMASK_32(21, 16)
#define  DX7BDLR2_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX7BDLR3         0x600108e50
#define  DX7BDLR3_DQ0RBD          GENMASK_32(5, 0)
#define  DX7BDLR3_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX7BDLR3_DQ1RBD          GENMASK_32(13, 8)
#define  DX7BDLR3_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX7BDLR3_DQ2RBD          GENMASK_32(21, 16)
#define  DX7BDLR3_RESERVED_23_22  GENMASK_32(23, 22)
#define  DX7BDLR3_DQ3RBD          GENMASK_32(29, 24)
#define  DX7BDLR3_RESERVED_31_30  GENMASK_32(31, 30)

#define DDR_PHY_DX7BDLR4         0x600108e54
#define  DX7BDLR4_DQ4RBD          GENMASK_32(5, 0)
#define  DX7BDLR4_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX7BDLR4_DQ5RBD          GENMASK_32(13, 8)
#define  DX7BDLR4_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX7BDLR4_DQ6RBD          GENMASK_32(21, 16)
#define  DX7BDLR4_RESERVED_23_22  GENMASK_32(23, 22)
#define  DX7BDLR4_DQ7RBD          GENMASK_32(29, 24)
#define  DX7BDLR4_RESERVED_31_30  GENMASK_32(31, 30)

#define DDR_PHY_DX7BDLR5         0x600108e58
#define  DX7BDLR5_DMRBD           GENMASK_32(5, 0)
#define  DX7BDLR5_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX7BDLR5_DSRBD           GENMASK_32(13, 8)
#define  DX7BDLR5_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX7BDLR5_DSNRBD          GENMASK_32(21, 16)
#define  DX7BDLR5_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX7BDLR6         0x600108e60
#define  DX7BDLR6_RESERVED_7_0    GENMASK_32(7, 0)
#define  DX7BDLR6_PDRBD           GENMASK_32(13, 8)
#define  DX7BDLR6_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX7BDLR6_TERBD           GENMASK_32(21, 16)
#define  DX7BDLR6_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX7BDLR7         0x600108e64
#define  DX7BDLR7_X4DMWBD         GENMASK_32(5, 0)
#define  DX7BDLR7_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX7BDLR7_X4DSWBD         GENMASK_32(13, 8)
#define  DX7BDLR7_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX7BDLR7_X4DSOEBD        GENMASK_32(21, 16)
#define  DX7BDLR7_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX7BDLR8         0x600108e68
#define  DX7BDLR8_X4DMRBD         GENMASK_32(5, 0)
#define  DX7BDLR8_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX7BDLR8_X4DSRBD         GENMASK_32(13, 8)
#define  DX7BDLR8_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX7BDLR8_X4DSNRBD        GENMASK_32(21, 16)
#define  DX7BDLR8_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX7BDLR9         0x600108e6c
#define  DX7BDLR9_RESERVED_7_0    GENMASK_32(7, 0)
#define  DX7BDLR9_X4PDRBD         GENMASK_32(13, 8)
#define  DX7BDLR9_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX7BDLR9_X4TERBD         GENMASK_32(21, 16)
#define  DX7BDLR9_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX7LCDLR0        0x600108e80
#define  DX7LCDLR0_WLD            GENMASK_32(8, 0)
#define  DX7LCDLR0_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX7LCDLR0_X4WLD          GENMASK_32(24, 16)
#define  DX7LCDLR0_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX7LCDLR1        0x600108e84
#define  DX7LCDLR1_WDQD           GENMASK_32(8, 0)
#define  DX7LCDLR1_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX7LCDLR1_X4WDQD         GENMASK_32(24, 16)
#define  DX7LCDLR1_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX7LCDLR2        0x600108e88
#define  DX7LCDLR2_DQSGD          GENMASK_32(8, 0)
#define  DX7LCDLR2_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX7LCDLR2_X4DQSGD        GENMASK_32(24, 16)
#define  DX7LCDLR2_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX7LCDLR3        0x600108e8c
#define  DX7LCDLR3_RDQSD          GENMASK_32(8, 0)
#define  DX7LCDLR3_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX7LCDLR3_X4RDQSD        GENMASK_32(24, 16)
#define  DX7LCDLR3_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX7LCDLR4        0x600108e90
#define  DX7LCDLR4_RDQSND         GENMASK_32(8, 0)
#define  DX7LCDLR4_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX7LCDLR4_X4RDQSND       GENMASK_32(24, 16)
#define  DX7LCDLR4_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX7LCDLR5        0x600108e94
#define  DX7LCDLR5_DQSGSD         GENMASK_32(8, 0)
#define  DX7LCDLR5_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX7LCDLR5_X4DQSGSD       GENMASK_32(24, 16)
#define  DX7LCDLR5_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX7MDLR0         0x600108ea0
#define  DX7MDLR0_IPRD            GENMASK_32(8, 0)
#define  DX7MDLR0_RESERVED_15_9   GENMASK_32(15, 9)
#define  DX7MDLR0_TPRD            GENMASK_32(24, 16)
#define  DX7MDLR0_RESERVED_31_25  GENMASK_32(31, 25)

#define DDR_PHY_DX7MDLR1         0x600108ea4
#define  DX7MDLR1_MDLD            GENMASK_32(8, 0)
#define  DX7MDLR1_RESERVED_31_9   GENMASK_32(31, 9)

#define DDR_PHY_DX7GTR0          0x600108ec0
#define  DX7GTR0_DGSL             GENMASK_32(4, 0)
#define  DX7GTR0_RESERVED_7_5     GENMASK_32(7, 5)
#define  DX7GTR0_X4DGSL           GENMASK_32(12, 8)
#define  DX7GTR0_RESERVED_15_13   GENMASK_32(15, 13)
#define  DX7GTR0_WLSL             GENMASK_32(19, 16)
#define  DX7GTR0_X4WLSL           GENMASK_32(23, 20)
#define  DX7GTR0_RESERVED_31_24   GENMASK_32(31, 24)

#define DDR_PHY_DX7RSR0          0x600108ed0
#define  DX7RSR0_QSGERR           GENMASK_32(15, 0)
#define  DX7RSR0_X4QSGERR         GENMASK_32(31, 16)

#define DDR_PHY_DX7RSR1          0x600108ed4
#define  DX7RSR1_RDLVLERR         GENMASK_32(15, 0)
#define  DX7RSR1_X4RDLVLERR       GENMASK_32(31, 16)

#define DDR_PHY_DX7RSR2          0x600108ed8
#define  DX7RSR2_WLAWN            GENMASK_32(15, 0)
#define  DX7RSR2_X4WLAWN          GENMASK_32(31, 16)

#define DDR_PHY_DX7RSR3          0x600108edc
#define  DX7RSR3_WLAERR           GENMASK_32(15, 0)
#define  DX7RSR3_X4WLAERR         GENMASK_32(31, 16)

#define DDR_PHY_DX7GSR0          0x600108ee0
#define  DX7GSR0_WDQCAL           BIT_32(0)
#define  DX7GSR0_RDQSCAL          BIT_32(1)
#define  DX7GSR0_RDQSNCAL         BIT_32(2)
#define  DX7GSR0_GDQSCAL          BIT_32(3)
#define  DX7GSR0_WLCAL            BIT_32(4)
#define  DX7GSR0_WLDONE           BIT_32(5)
#define  DX7GSR0_WLERR            BIT_32(6)
#define  DX7GSR0_WLPRD            GENMASK_32(15, 7)
#define  DX7GSR0_DPLOCK           BIT_32(16)
#define  DX7GSR0_GDQSPRD          GENMASK_32(25, 17)
#define  DX7GSR0_RESERVED_29_26   GENMASK_32(29, 26)
#define  DX7GSR0_WLDQ             BIT_32(30)
#define  DX7GSR0_RESERVED_31      BIT_32(31)

#define DDR_PHY_DX7GSR1          0x600108ee4
#define  DX7GSR1_DLTDONE          BIT_32(0)
#define  DX7GSR1_DLTCODE          GENMASK_32(24, 1)
#define  DX7GSR1_RESERVED_31_25   GENMASK_32(31, 25)

#define DDR_PHY_DX7GSR2          0x600108ee8
#define  DX7GSR2_RDERR            BIT_32(0)
#define  DX7GSR2_RDWN             BIT_32(1)
#define  DX7GSR2_WDERR            BIT_32(2)
#define  DX7GSR2_WDWN             BIT_32(3)
#define  DX7GSR2_REERR            BIT_32(4)
#define  DX7GSR2_REWN             BIT_32(5)
#define  DX7GSR2_WEERR            BIT_32(6)
#define  DX7GSR2_WEWN             BIT_32(7)
#define  DX7GSR2_ESTAT            GENMASK_32(11, 8)
#define  DX7GSR2_DBDQ             GENMASK_32(19, 12)
#define  DX7GSR2_SRDERR           BIT_32(20)
#define  DX7GSR2_RESERVED_21      BIT_32(21)
#define  DX7GSR2_GSDQSCAL         BIT_32(22)
#define  DX7GSR2_GSDQSPRD         GENMASK_32(31, 23)

#define DDR_PHY_DX7GSR3          0x600108eec
#define  DX7GSR3_SRDPC            GENMASK_32(1, 0)
#define  DX7GSR3_RESERVED_7_2     GENMASK_32(7, 2)
#define  DX7GSR3_HVERR            GENMASK_32(11, 8)
#define  DX7GSR3_HVWRN            GENMASK_32(15, 12)
#define  DX7GSR3_DVERR            GENMASK_32(19, 16)
#define  DX7GSR3_DVWRN            GENMASK_32(23, 20)
#define  DX7GSR3_ESTAT            GENMASK_32(26, 24)
#define  DX7GSR3_RESERVED_31_27   GENMASK_32(31, 27)

#define DDR_PHY_DX7GSR4          0x600108ef0
#define  DX7GSR4_X4WDQCAL         BIT_32(0)
#define  DX7GSR4_X4RDQSCAL        BIT_32(1)
#define  DX7GSR4_X4RDQSNCAL       BIT_32(2)
#define  DX7GSR4_X4GDQSCAL        BIT_32(3)
#define  DX7GSR4_X4WLCAL          BIT_32(4)
#define  DX7GSR4_X4WLDONE         BIT_32(5)
#define  DX7GSR4_X4WLERR          BIT_32(6)
#define  DX7GSR4_X4WLPRD          GENMASK_32(15, 7)
#define  DX7GSR4_X4DPLOCK         BIT_32(16)
#define  DX7GSR4_X4GDQSPRD        GENMASK_32(25, 17)
#define  DX7GSR4_RESERVED_29_26   GENMASK_32(29, 26)
#define  DX7GSR4_X4WLDQ           BIT_32(30)
#define  DX7GSR4_RESERVED_31      BIT_32(31)

#define DDR_PHY_DX7GSR5          0x600108ef4
#define  DX7GSR5_X4RDERR          BIT_32(0)
#define  DX7GSR5_X4RDWN           BIT_32(1)
#define  DX7GSR5_X4WDERR          BIT_32(2)
#define  DX7GSR5_X4WDWN           BIT_32(3)
#define  DX7GSR5_X4REERR          BIT_32(4)
#define  DX7GSR5_X4REWN           BIT_32(5)
#define  DX7GSR5_X4WEERR          BIT_32(6)
#define  DX7GSR5_X4WEWN           BIT_32(7)
#define  DX7GSR5_X4ESTAT          GENMASK_32(11, 8)
#define  DX7GSR5_RESERVED_19_12   GENMASK_32(19, 12)
#define  DX7GSR5_X4SRDERR         BIT_32(20)
#define  DX7GSR5_RESERVED_21      BIT_32(21)
#define  DX7GSR5_X4GSDQSCAL       BIT_32(22)
#define  DX7GSR5_X4GSDQSPRD       GENMASK_32(31, 23)

#define DDR_PHY_DX7GSR6          0x600108ef8
#define  DX7GSR6_RESERVED_1_0     GENMASK_32(1, 0)
#define  DX7GSR6_X4SRDPC          GENMASK_32(3, 2)
#define  DX7GSR6_RESERVED_7_4     GENMASK_32(7, 4)
#define  DX7GSR6_X4HVERR          GENMASK_32(11, 8)
#define  DX7GSR6_X4HVWRN          GENMASK_32(15, 12)
#define  DX7GSR6_X4DVERR          GENMASK_32(19, 16)
#define  DX7GSR6_X4DVWRN          GENMASK_32(23, 20)
#define  DX7GSR6_RESERVED_31_24   GENMASK_32(31, 24)

#define DDR_PHY_DX8GCR0          0x600108f00
#define  DX8GCR0_DXEN             BIT_32(0)
#define  DX8GCR0_DXIOM            BIT_32(1)
#define  DX8GCR0_DQSGOE           BIT_32(2)
#define  DX8GCR0_DQSGODT          BIT_32(3)
#define  DX8GCR0_RESERVED_4       BIT_32(4)
#define  DX8GCR0_DQSGPDR          BIT_32(5)
#define  DX8GCR0_RESERVED_6       BIT_32(6)
#define  DX8GCR0_PDRAL            GENMASK_32(8, 7)
#define  DX8GCR0_RTTOH            GENMASK_32(10, 9)
#define  DX8GCR0_RTTOAL           BIT_32(11)
#define  DX8GCR0_DQSSEPDR         BIT_32(12)
#define  DX8GCR0_DQSNSEPDR        BIT_32(13)
#define  DX8GCR0_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX8GCR0_PLLRST           BIT_32(16)
#define  DX8GCR0_PLLPD            BIT_32(17)
#define  DX8GCR0_GSHIFT           BIT_32(18)
#define  DX8GCR0_PLLBYP           BIT_32(19)
#define  DX8GCR0_RDDLY            GENMASK_32(23, 20)
#define  DX8GCR0_RESERVED_29_24   GENMASK_32(29, 24)
#define  DX8GCR0_MDLEN            BIT_32(30)
#define  DX8GCR0_CALBYP           BIT_32(31)

#define DDR_PHY_DX8GCR1          0x600108f04
#define  DX8GCR1_RESERVED_15_0    GENMASK_32(15, 0)
#define  DX8GCR1_DXPDRMODE        GENMASK_32(31, 16)

#define DDR_PHY_DX8GCR2          0x600108f08
#define  DX8GCR2_DXTEMODE         GENMASK_32(15, 0)
#define  DX8GCR2_DXOEMODE         GENMASK_32(31, 16)

#define DDR_PHY_DX8GCR3          0x600108f0c
#define  DX8GCR3_RESERVED_1_0     GENMASK_32(1, 0)
#define  DX8GCR3_DSPDRMODE        GENMASK_32(3, 2)
#define  DX8GCR3_DSTEMODE         GENMASK_32(5, 4)
#define  DX8GCR3_DSOEMODE         GENMASK_32(7, 6)
#define  DX8GCR3_RESERVED_9_8     GENMASK_32(9, 8)
#define  DX8GCR3_DMPDRMODE        GENMASK_32(11, 10)
#define  DX8GCR3_DMTEMODE         GENMASK_32(13, 12)
#define  DX8GCR3_DMOEMODE         GENMASK_32(15, 14)
#define  DX8GCR3_RESERVED_17_16   GENMASK_32(17, 16)
#define  DX8GCR3_OEBVT            BIT_32(18)
#define  DX8GCR3_PDRBVT           BIT_32(19)
#define  DX8GCR3_TEBVT            BIT_32(20)
#define  DX8GCR3_WDSBVT           BIT_32(21)
#define  DX8GCR3_RDSBVT           BIT_32(22)
#define  DX8GCR3_RGSLVT           BIT_32(23)
#define  DX8GCR3_WLLVT            BIT_32(24)
#define  DX8GCR3_WDLVT            BIT_32(25)
#define  DX8GCR3_RDLVT            BIT_32(26)
#define  DX8GCR3_RGLVT            BIT_32(27)
#define  DX8GCR3_WDBVT            BIT_32(28)
#define  DX8GCR3_RDBVT            BIT_32(29)
#define  DX8GCR3_WDMBVT           BIT_32(30)
#define  DX8GCR3_RDMBVT           BIT_32(31)

#define DDR_PHY_DX8GCR4          0x600108f10
#define  DX8GCR4_DXREFIMON        GENMASK_32(1, 0)
#define  DX8GCR4_DXREFIEN         GENMASK_32(5, 2)
#define  DX8GCR4_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX8GCR4_DXREFSSEL        GENMASK_32(13, 8)
#define  DX8GCR4_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX8GCR4_DXREFESEL        GENMASK_32(21, 16)
#define  DX8GCR4_RESERVED_24_22   GENMASK_32(24, 22)
#define  DX8GCR4_DXREFSEN         BIT_32(25)
#define  DX8GCR4_DXREFEEN         GENMASK_32(27, 26)
#define  DX8GCR4_DXREFPEN         BIT_32(28)
#define  DX8GCR4_DXREFIOM         GENMASK_32(31, 29)

#define DDR_PHY_DX8GCR5          0x600108f14
#define  DX8GCR5_DXREFISELR0      GENMASK_32(5, 0)
#define  DX8GCR5_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX8GCR5_DXREFISELR1      GENMASK_32(13, 8)
#define  DX8GCR5_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX8GCR5_DXREFISELR2      GENMASK_32(21, 16)
#define  DX8GCR5_RESERVED_23_22   GENMASK_32(23, 22)
#define  DX8GCR5_DXREFISELR3      GENMASK_32(29, 24)
#define  DX8GCR5_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX8GCR6          0x600108f18
#define  DX8GCR6_DXDQVREFR0       GENMASK_32(5, 0)
#define  DX8GCR6_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX8GCR6_DXDQVREFR1       GENMASK_32(13, 8)
#define  DX8GCR6_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX8GCR6_DXDQVREFR2       GENMASK_32(21, 16)
#define  DX8GCR6_RESERVED_23_22   GENMASK_32(23, 22)
#define  DX8GCR6_DXDQVREFR3       GENMASK_32(29, 24)
#define  DX8GCR6_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX8GCR7          0x600108f1c
#define  DX8GCR7_RESERVED_1_0     GENMASK_32(1, 0)
#define  DX8GCR7_X4DSPDRMODE      GENMASK_32(3, 2)
#define  DX8GCR7_X4DSTEMODE       GENMASK_32(5, 4)
#define  DX8GCR7_X4DSOEMODE       GENMASK_32(7, 6)
#define  DX8GCR7_RESERVED_9_8     GENMASK_32(9, 8)
#define  DX8GCR7_X4DXPDRMODE      GENMASK_32(11, 10)
#define  DX8GCR7_X4DXTEMODE       GENMASK_32(13, 12)
#define  DX8GCR7_X4DXOEMODE       GENMASK_32(15, 14)
#define  DX8GCR7_X4DQSGOE         BIT_32(16)
#define  DX8GCR7_X4DQSGODT        BIT_32(17)
#define  DX8GCR7_RESERVED_18      BIT_32(18)
#define  DX8GCR7_X4DQSGPDR        BIT_32(19)
#define  DX8GCR7_RESERVED_20      BIT_32(20)
#define  DX8GCR7_X4DQSSEPDR       BIT_32(21)
#define  DX8GCR7_X4DQSNSEPDR      BIT_32(22)
#define  DX8GCR7_X4RTTOH          GENMASK_32(24, 23)
#define  DX8GCR7_X4RTTOAL         BIT_32(25)
#define  DX8GCR7_X4RDDLY          GENMASK_32(29, 26)
#define  DX8GCR7_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX8GCR8          0x600108f20
#define  DX8GCR8_X4DXREFISELR0    GENMASK_32(5, 0)
#define  DX8GCR8_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX8GCR8_X4DXREFISELR1    GENMASK_32(13, 8)
#define  DX8GCR8_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX8GCR8_X4DXREFISELR2    GENMASK_32(21, 16)
#define  DX8GCR8_RESERVED_23_22   GENMASK_32(23, 22)
#define  DX8GCR8_X4DXREFISELR3    GENMASK_32(29, 24)
#define  DX8GCR8_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX8GCR9          0x600108f24
#define  DX8GCR9_X4DXDQVREFR0     GENMASK_32(5, 0)
#define  DX8GCR9_RESERVED_7_6     GENMASK_32(7, 6)
#define  DX8GCR9_X4DXDQVREFR1     GENMASK_32(13, 8)
#define  DX8GCR9_RESERVED_15_14   GENMASK_32(15, 14)
#define  DX8GCR9_X4DXDQVREFR2     GENMASK_32(21, 16)
#define  DX8GCR9_RESERVED_23_22   GENMASK_32(23, 22)
#define  DX8GCR9_X4DXDQVREFR3     GENMASK_32(29, 24)
#define  DX8GCR9_RESERVED_31_30   GENMASK_32(31, 30)

#define DDR_PHY_DX8BDLR0         0x600108f40
#define  DX8BDLR0_DQ0WBD          GENMASK_32(5, 0)
#define  DX8BDLR0_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX8BDLR0_DQ1WBD          GENMASK_32(13, 8)
#define  DX8BDLR0_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX8BDLR0_DQ2WBD          GENMASK_32(21, 16)
#define  DX8BDLR0_RESERVED_23_22  GENMASK_32(23, 22)
#define  DX8BDLR0_DQ3WBD          GENMASK_32(29, 24)
#define  DX8BDLR0_RESERVED_31_30  GENMASK_32(31, 30)

#define DDR_PHY_DX8BDLR1         0x600108f44
#define  DX8BDLR1_DQ4WBD          GENMASK_32(5, 0)
#define  DX8BDLR1_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX8BDLR1_DQ5WBD          GENMASK_32(13, 8)
#define  DX8BDLR1_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX8BDLR1_DQ6WBD          GENMASK_32(21, 16)
#define  DX8BDLR1_RESERVED_23_22  GENMASK_32(23, 22)
#define  DX8BDLR1_DQ7WBD          GENMASK_32(29, 24)
#define  DX8BDLR1_RESERVED_31_30  GENMASK_32(31, 30)

#define DDR_PHY_DX8BDLR2         0x600108f48
#define  DX8BDLR2_DMWBD           GENMASK_32(5, 0)
#define  DX8BDLR2_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX8BDLR2_DSWBD           GENMASK_32(13, 8)
#define  DX8BDLR2_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX8BDLR2_DSOEBD          GENMASK_32(21, 16)
#define  DX8BDLR2_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX8BDLR3         0x600108f50
#define  DX8BDLR3_DQ0RBD          GENMASK_32(5, 0)
#define  DX8BDLR3_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX8BDLR3_DQ1RBD          GENMASK_32(13, 8)
#define  DX8BDLR3_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX8BDLR3_DQ2RBD          GENMASK_32(21, 16)
#define  DX8BDLR3_RESERVED_23_22  GENMASK_32(23, 22)
#define  DX8BDLR3_DQ3RBD          GENMASK_32(29, 24)
#define  DX8BDLR3_RESERVED_31_30  GENMASK_32(31, 30)

#define DDR_PHY_DX8BDLR4         0x600108f54
#define  DX8BDLR4_DQ4RBD          GENMASK_32(5, 0)
#define  DX8BDLR4_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX8BDLR4_DQ5RBD          GENMASK_32(13, 8)
#define  DX8BDLR4_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX8BDLR4_DQ6RBD          GENMASK_32(21, 16)
#define  DX8BDLR4_RESERVED_23_22  GENMASK_32(23, 22)
#define  DX8BDLR4_DQ7RBD          GENMASK_32(29, 24)
#define  DX8BDLR4_RESERVED_31_30  GENMASK_32(31, 30)

#define DDR_PHY_DX8BDLR5         0x600108f58
#define  DX8BDLR5_DMRBD           GENMASK_32(5, 0)
#define  DX8BDLR5_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX8BDLR5_DSRBD           GENMASK_32(13, 8)
#define  DX8BDLR5_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX8BDLR5_DSNRBD          GENMASK_32(21, 16)
#define  DX8BDLR5_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX8BDLR6         0x600108f60
#define  DX8BDLR6_RESERVED_7_0    GENMASK_32(7, 0)
#define  DX8BDLR6_PDRBD           GENMASK_32(13, 8)
#define  DX8BDLR6_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX8BDLR6_TERBD           GENMASK_32(21, 16)
#define  DX8BDLR6_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX8BDLR7         0x600108f64
#define  DX8BDLR7_X4DMWBD         GENMASK_32(5, 0)
#define  DX8BDLR7_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX8BDLR7_X4DSWBD         GENMASK_32(13, 8)
#define  DX8BDLR7_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX8BDLR7_X4DSOEBD        GENMASK_32(21, 16)
#define  DX8BDLR7_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX8BDLR8         0x600108f68
#define  DX8BDLR8_X4DMRBD         GENMASK_32(5, 0)
#define  DX8BDLR8_RESERVED_7_6    GENMASK_32(7, 6)
#define  DX8BDLR8_X4DSRBD         GENMASK_32(13, 8)
#define  DX8BDLR8_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX8BDLR8_X4DSNRBD        GENMASK_32(21, 16)
#define  DX8BDLR8_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX8BDLR9         0x600108f6c
#define  DX8BDLR9_RESERVED_7_0    GENMASK_32(7, 0)
#define  DX8BDLR9_X4PDRBD         GENMASK_32(13, 8)
#define  DX8BDLR9_RESERVED_15_14  GENMASK_32(15, 14)
#define  DX8BDLR9_X4TERBD         GENMASK_32(21, 16)
#define  DX8BDLR9_RESERVED_31_22  GENMASK_32(31, 22)

#define DDR_PHY_DX8LCDLR0        0x600108f80
#define  DX8LCDLR0_WLD            GENMASK_32(8, 0)
#define  DX8LCDLR0_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX8LCDLR0_X4WLD          GENMASK_32(24, 16)
#define  DX8LCDLR0_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX8LCDLR1        0x600108f84
#define  DX8LCDLR1_WDQD           GENMASK_32(8, 0)
#define  DX8LCDLR1_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX8LCDLR1_X4WDQD         GENMASK_32(24, 16)
#define  DX8LCDLR1_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX8LCDLR2        0x600108f88
#define  DX8LCDLR2_DQSGD          GENMASK_32(8, 0)
#define  DX8LCDLR2_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX8LCDLR2_X4DQSGD        GENMASK_32(24, 16)
#define  DX8LCDLR2_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX8LCDLR3        0x600108f8c
#define  DX8LCDLR3_RDQSD          GENMASK_32(8, 0)
#define  DX8LCDLR3_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX8LCDLR3_X4RDQSD        GENMASK_32(24, 16)
#define  DX8LCDLR3_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX8LCDLR4        0x600108f90
#define  DX8LCDLR4_RDQSND         GENMASK_32(8, 0)
#define  DX8LCDLR4_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX8LCDLR4_X4RDQSND       GENMASK_32(24, 16)
#define  DX8LCDLR4_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX8LCDLR5        0x600108f94
#define  DX8LCDLR5_DQSGSD         GENMASK_32(8, 0)
#define  DX8LCDLR5_RESERVED_15_9  GENMASK_32(15, 9)
#define  DX8LCDLR5_X4DQSGSD       GENMASK_32(24, 16)
#define  DX8LCDLR5_RESERVED_31_25 GENMASK_32(31, 25)

#define DDR_PHY_DX8MDLR0         0x600108fa0
#define  DX8MDLR0_IPRD            GENMASK_32(8, 0)
#define  DX8MDLR0_RESERVED_15_9   GENMASK_32(15, 9)
#define  DX8MDLR0_TPRD            GENMASK_32(24, 16)
#define  DX8MDLR0_RESERVED_31_25  GENMASK_32(31, 25)

#define DDR_PHY_DX8MDLR1         0x600108fa4
#define  DX8MDLR1_MDLD            GENMASK_32(8, 0)
#define  DX8MDLR1_RESERVED_31_9   GENMASK_32(31, 9)

#define DDR_PHY_DX8GTR0          0x600108fc0
#define  DX8GTR0_DGSL             GENMASK_32(4, 0)
#define  DX8GTR0_RESERVED_7_5     GENMASK_32(7, 5)
#define  DX8GTR0_X4DGSL           GENMASK_32(12, 8)
#define  DX8GTR0_RESERVED_15_13   GENMASK_32(15, 13)
#define  DX8GTR0_WLSL             GENMASK_32(19, 16)
#define  DX8GTR0_X4WLSL           GENMASK_32(23, 20)
#define  DX8GTR0_RESERVED_31_24   GENMASK_32(31, 24)

#define DDR_PHY_DX8RSR0          0x600108fd0
#define  DX8RSR0_QSGERR           GENMASK_32(15, 0)
#define  DX8RSR0_X4QSGERR         GENMASK_32(31, 16)

#define DDR_PHY_DX8RSR1          0x600108fd4
#define  DX8RSR1_RDLVLERR         GENMASK_32(15, 0)
#define  DX8RSR1_X4RDLVLERR       GENMASK_32(31, 16)

#define DDR_PHY_DX8RSR2          0x600108fd8
#define  DX8RSR2_WLAWN            GENMASK_32(15, 0)
#define  DX8RSR2_X4WLAWN          GENMASK_32(31, 16)

#define DDR_PHY_DX8RSR3          0x600108fdc
#define  DX8RSR3_WLAERR           GENMASK_32(15, 0)
#define  DX8RSR3_X4WLAERR         GENMASK_32(31, 16)

#define DDR_PHY_DX8GSR0          0x600108fe0
#define  DX8GSR0_WDQCAL           BIT_32(0)
#define  DX8GSR0_RDQSCAL          BIT_32(1)
#define  DX8GSR0_RDQSNCAL         BIT_32(2)
#define  DX8GSR0_GDQSCAL          BIT_32(3)
#define  DX8GSR0_WLCAL            BIT_32(4)
#define  DX8GSR0_WLDONE           BIT_32(5)
#define  DX8GSR0_WLERR            BIT_32(6)
#define  DX8GSR0_WLPRD            GENMASK_32(15, 7)
#define  DX8GSR0_DPLOCK           BIT_32(16)
#define  DX8GSR0_GDQSPRD          GENMASK_32(25, 17)
#define  DX8GSR0_RESERVED_29_26   GENMASK_32(29, 26)
#define  DX8GSR0_WLDQ             BIT_32(30)
#define  DX8GSR0_RESERVED_31      BIT_32(31)

#define DDR_PHY_DX8GSR1          0x600108fe4
#define  DX8GSR1_DLTDONE          BIT_32(0)
#define  DX8GSR1_DLTCODE          GENMASK_32(24, 1)
#define  DX8GSR1_RESERVED_31_25   GENMASK_32(31, 25)

#define DDR_PHY_DX8GSR2          0x600108fe8
#define  DX8GSR2_RDERR            BIT_32(0)
#define  DX8GSR2_RDWN             BIT_32(1)
#define  DX8GSR2_WDERR            BIT_32(2)
#define  DX8GSR2_WDWN             BIT_32(3)
#define  DX8GSR2_REERR            BIT_32(4)
#define  DX8GSR2_REWN             BIT_32(5)
#define  DX8GSR2_WEERR            BIT_32(6)
#define  DX8GSR2_WEWN             BIT_32(7)
#define  DX8GSR2_ESTAT            GENMASK_32(11, 8)
#define  DX8GSR2_DBDQ             GENMASK_32(19, 12)
#define  DX8GSR2_SRDERR           BIT_32(20)
#define  DX8GSR2_RESERVED_21      BIT_32(21)
#define  DX8GSR2_GSDQSCAL         BIT_32(22)
#define  DX8GSR2_GSDQSPRD         GENMASK_32(31, 23)

#define DDR_PHY_DX8GSR3          0x600108fec
#define  DX8GSR3_SRDPC            GENMASK_32(1, 0)
#define  DX8GSR3_RESERVED_7_2     GENMASK_32(7, 2)
#define  DX8GSR3_HVERR            GENMASK_32(11, 8)
#define  DX8GSR3_HVWRN            GENMASK_32(15, 12)
#define  DX8GSR3_DVERR            GENMASK_32(19, 16)
#define  DX8GSR3_DVWRN            GENMASK_32(23, 20)
#define  DX8GSR3_ESTAT            GENMASK_32(26, 24)
#define  DX8GSR3_RESERVED_31_27   GENMASK_32(31, 27)

#define DDR_PHY_DX8GSR4          0x600108ff0
#define  DX8GSR4_X4WDQCAL         BIT_32(0)
#define  DX8GSR4_X4RDQSCAL        BIT_32(1)
#define  DX8GSR4_X4RDQSNCAL       BIT_32(2)
#define  DX8GSR4_X4GDQSCAL        BIT_32(3)
#define  DX8GSR4_X4WLCAL          BIT_32(4)
#define  DX8GSR4_X4WLDONE         BIT_32(5)
#define  DX8GSR4_X4WLERR          BIT_32(6)
#define  DX8GSR4_X4WLPRD          GENMASK_32(15, 7)
#define  DX8GSR4_X4DPLOCK         BIT_32(16)
#define  DX8GSR4_X4GDQSPRD        GENMASK_32(25, 17)
#define  DX8GSR4_RESERVED_29_26   GENMASK_32(29, 26)
#define  DX8GSR4_X4WLDQ           BIT_32(30)
#define  DX8GSR4_RESERVED_31      BIT_32(31)

#define DDR_PHY_DX8GSR5          0x600108ff4
#define  DX8GSR5_X4RDERR          BIT_32(0)
#define  DX8GSR5_X4RDWN           BIT_32(1)
#define  DX8GSR5_X4WDERR          BIT_32(2)
#define  DX8GSR5_X4WDWN           BIT_32(3)
#define  DX8GSR5_X4REERR          BIT_32(4)
#define  DX8GSR5_X4REWN           BIT_32(5)
#define  DX8GSR5_X4WEERR          BIT_32(6)
#define  DX8GSR5_X4WEWN           BIT_32(7)
#define  DX8GSR5_X4ESTAT          GENMASK_32(11, 8)
#define  DX8GSR5_RESERVED_19_12   GENMASK_32(19, 12)
#define  DX8GSR5_X4SRDERR         BIT_32(20)
#define  DX8GSR5_RESERVED_21      BIT_32(21)
#define  DX8GSR5_X4GSDQSCAL       BIT_32(22)
#define  DX8GSR5_X4GSDQSPRD       GENMASK_32(31, 23)

#define DDR_PHY_DX8GSR6          0x600108ff8
#define  DX8GSR6_RESERVED_1_0     GENMASK_32(1, 0)
#define  DX8GSR6_X4SRDPC          GENMASK_32(3, 2)
#define  DX8GSR6_RESERVED_7_4     GENMASK_32(7, 4)
#define  DX8GSR6_X4HVERR          GENMASK_32(11, 8)
#define  DX8GSR6_X4HVWRN          GENMASK_32(15, 12)
#define  DX8GSR6_X4DVERR          GENMASK_32(19, 16)
#define  DX8GSR6_X4DVWRN          GENMASK_32(23, 20)
#define  DX8GSR6_RESERVED_31_24   GENMASK_32(31, 24)

#define DDR_UMCTL2_MSTR          0x600107000
#define  MSTR_DDR3                BIT_32(0)
#define  MSTR_LPDDR2              BIT_32(2)
#define  MSTR_LPDDR3              BIT_32(3)
#define  MSTR_DDR4                BIT_32(4)
#define  MSTR_BURSTCHOP           BIT_32(9)
#define  MSTR_EN_2T_TIMING_MODE   BIT_32(10)
#define  MSTR_GEARDOWN_MODE       BIT_32(11)
#define  MSTR_DATA_BUS_WIDTH      GENMASK_32(13, 12)
#define  MSTR_DLL_OFF_MODE        BIT_32(15)
#define  MSTR_BURST_RDWR          GENMASK_32(19, 16)
#define  MSTR_ACTIVE_RANKS        GENMASK_32(25, 24)
#define  MSTR_DEVICE_CONFIG       GENMASK_32(31, 30)

#define DDR_UMCTL2_STAT          0x600107004
#define  STAT_OPERATING_MODE      GENMASK_32(2, 0)
#define  STAT_SELFREF_TYPE        GENMASK_32(5, 4)
#define  STAT_SELFREF_CAM_NOT_EMPTY BIT_32(12)

#define DDR_UMCTL2_MRCTRL0       0x600107010
#define  MRCTRL0_MR_TYPE          BIT_32(0)
#define  MRCTRL0_MPR_EN           BIT_32(1)
#define  MRCTRL0_PDA_EN           BIT_32(2)
#define  MRCTRL0_SW_INIT_INT      BIT_32(3)
#define  MRCTRL0_MR_RANK          GENMASK_32(5, 4)
#define  MRCTRL0_MR_ADDR          GENMASK_32(15, 12)
#define  MRCTRL0_PBA_MODE         BIT_32(30)
#define  MRCTRL0_MR_WR            BIT_32(31)

#define DDR_UMCTL2_MRCTRL1       0x600107014
#define  MRCTRL1_MR_DATA          GENMASK_32(17, 0)

#define DDR_UMCTL2_MRSTAT        0x600107018
#define  MRSTAT_MR_WR_BUSY        BIT_32(0)
#define  MRSTAT_PDA_DONE          BIT_32(8)

#define DDR_UMCTL2_MRCTRL2       0x60010701c
#define  MRCTRL2_MR_DEVICE_SEL    GENMASK_32(31, 0)

#define DDR_UMCTL2_DERATEEN      0x600107020
#define  DERATEEN_DERATE_ENABLE   BIT_32(0)
#define  DERATEEN_DERATE_VALUE    GENMASK_32(2, 1)
#define  DERATEEN_DERATE_BYTE     GENMASK_32(7, 4)

#define DDR_UMCTL2_DERATEINT     0x600107024
#define  DERATEINT_MR4_READ_INTERVAL GENMASK_32(31, 0)

#define DDR_UMCTL2_PWRCTL        0x600107030
#define  PWRCTL_SELFREF_EN        BIT_32(0)
#define  PWRCTL_POWERDOWN_EN      BIT_32(1)
#define  PWRCTL_DEEPPOWERDOWN_EN  BIT_32(2)
#define  PWRCTL_EN_DFI_DRAM_CLK_DISABLE BIT_32(3)
#define  PWRCTL_MPSM_EN           BIT_32(4)
#define  PWRCTL_SELFREF_SW        BIT_32(5)
#define  PWRCTL_DIS_CAM_DRAIN_SELFREF BIT_32(7)

#define DDR_UMCTL2_PWRTMG        0x600107034
#define  PWRTMG_POWERDOWN_TO_X32  GENMASK_32(4, 0)
#define  PWRTMG_T_DPD_X4096       GENMASK_32(15, 8)
#define  PWRTMG_SELFREF_TO_X32    GENMASK_32(23, 16)

#define DDR_UMCTL2_HWLPCTL       0x600107038
#define  HWLPCTL_HW_LP_EN         BIT_32(0)
#define  HWLPCTL_HW_LP_EXIT_IDLE_EN BIT_32(1)
#define  HWLPCTL_HW_LP_IDLE_X32   GENMASK_32(27, 16)

#define DDR_UMCTL2_RFSHCTL0      0x600107050
#define  RFSHCTL0_PER_BANK_REFRESH BIT_32(2)
#define  RFSHCTL0_REFRESH_BURST   GENMASK_32(8, 4)
#define  RFSHCTL0_REFRESH_TO_X32  GENMASK_32(16, 12)
#define  RFSHCTL0_REFRESH_MARGIN  GENMASK_32(23, 20)

#define DDR_UMCTL2_RFSHCTL1      0x600107054
#define  RFSHCTL1_REFRESH_TIMER0_START_VALUE_X32 GENMASK_32(11, 0)
#define  RFSHCTL1_REFRESH_TIMER1_START_VALUE_X32 GENMASK_32(27, 16)

#define DDR_UMCTL2_RFSHCTL3      0x600107060
#define  RFSHCTL3_DIS_AUTO_REFRESH BIT_32(0)
#define  RFSHCTL3_REFRESH_UPDATE_LEVEL BIT_32(1)
#define  RFSHCTL3_REFRESH_MODE    GENMASK_32(6, 4)

#define DDR_UMCTL2_RFSHTMG       0x600107064
#define  RFSHTMG_T_RFC_MIN        GENMASK_32(9, 0)
#define  RFSHTMG_LPDDR3_TREFBW_EN BIT_32(15)
#define  RFSHTMG_T_RFC_NOM_X32    GENMASK_32(27, 16)

#define DDR_UMCTL2_ECCCFG0       0x600107070
#define  ECCCFG0_ECC_MODE         GENMASK_32(2, 0)
#define  ECCCFG0_DIS_SCRUB        BIT_32(4)

#define DDR_UMCTL2_ECCCFG1       0x600107074
#define  ECCCFG1_DATA_POISON_EN   BIT_32(0)
#define  ECCCFG1_DATA_POISON_BIT  BIT_32(1)

#define DDR_UMCTL2_ECCSTAT       0x600107078
#define  ECCSTAT_ECC_CORRECTED_BIT_NUM GENMASK_32(6, 0)
#define  ECCSTAT_ECC_CORRECTED_ERR GENMASK_32(11, 8)
#define  ECCSTAT_ECC_UNCORRECTED_ERR GENMASK_32(19, 16)

#define DDR_UMCTL2_ECCCLR        0x60010707c
#define  ECCCLR_ECC_CLR_CORR_ERR  BIT_32(0)
#define  ECCCLR_ECC_CLR_UNCORR_ERR BIT_32(1)
#define  ECCCLR_ECC_CLR_CORR_ERR_CNT BIT_32(2)
#define  ECCCLR_ECC_CLR_UNCORR_ERR_CNT BIT_32(3)

#define DDR_UMCTL2_ECCERRCNT     0x600107080
#define  ECCERRCNT_ECC_CORR_ERR_CNT GENMASK_32(15, 0)
#define  ECCERRCNT_ECC_UNCORR_ERR_CNT GENMASK_32(31, 16)

#define DDR_UMCTL2_ECCCADDR0     0x600107084
#define  ECCCADDR0_ECC_CORR_ROW   GENMASK_32(17, 0)
#define  ECCCADDR0_ECC_CORR_RANK  BIT_32(24)

#define DDR_UMCTL2_ECCCADDR1     0x600107088
#define  ECCCADDR1_ECC_CORR_COL   GENMASK_32(11, 0)
#define  ECCCADDR1_ECC_CORR_BANK  GENMASK_32(18, 16)
#define  ECCCADDR1_ECC_CORR_BG    GENMASK_32(25, 24)

#define DDR_UMCTL2_ECCCSYN0      0x60010708c
#define  ECCCSYN0_ECC_CORR_SYNDROMES_31_0 GENMASK_32(31, 0)

#define DDR_UMCTL2_ECCCSYN2      0x600107094
#define  ECCCSYN2_ECC_CORR_SYNDROMES_71_64 GENMASK_32(7, 0)

#define DDR_UMCTL2_ECCBITMASK0   0x600107098
#define  ECCBITMASK0_ECC_CORR_BIT_MASK_31_0 GENMASK_32(31, 0)

#define DDR_UMCTL2_ECCBITMASK2   0x6001070a0
#define  ECCBITMASK2_ECC_CORR_BIT_MASK_71_64 GENMASK_32(7, 0)

#define DDR_UMCTL2_ECCUADDR0     0x6001070a4
#define  ECCUADDR0_ECC_UNCORR_ROW GENMASK_32(17, 0)
#define  ECCUADDR0_ECC_UNCORR_RANK BIT_32(24)

#define DDR_UMCTL2_ECCUADDR1     0x6001070a8
#define  ECCUADDR1_ECC_UNCORR_COL GENMASK_32(11, 0)
#define  ECCUADDR1_ECC_UNCORR_BANK GENMASK_32(18, 16)
#define  ECCUADDR1_ECC_UNCORR_BG  GENMASK_32(25, 24)

#define DDR_UMCTL2_ECCUSYN0      0x6001070ac
#define  ECCUSYN0_ECC_UNCORR_SYNDROMES_31_0 GENMASK_32(31, 0)

#define DDR_UMCTL2_ECCUSYN2      0x6001070b4
#define  ECCUSYN2_ECC_UNCORR_SYNDROMES_71_64 GENMASK_32(7, 0)

#define DDR_UMCTL2_ECCPOISONADDR0 0x6001070b8
#define  ECCPOISONADDR0_ECC_POISON_COL GENMASK_32(11, 0)
#define  ECCPOISONADDR0_ECC_POISON_RANK BIT_32(24)

#define DDR_UMCTL2_ECCPOISONADDR1 0x6001070bc
#define  ECCPOISONADDR1_ECC_POISON_ROW GENMASK_32(17, 0)
#define  ECCPOISONADDR1_ECC_POISON_BANK GENMASK_32(26, 24)
#define  ECCPOISONADDR1_ECC_POISON_BG GENMASK_32(29, 28)

#define DDR_UMCTL2_CRCPARCTL0    0x6001070c0
#define  CRCPARCTL0_DFI_ALERT_ERR_INT_EN BIT_32(0)
#define  CRCPARCTL0_DFI_ALERT_ERR_INT_CLR BIT_32(1)
#define  CRCPARCTL0_DFI_ALERT_ERR_CNT_CLR BIT_32(2)

#define DDR_UMCTL2_CRCPARCTL1    0x6001070c4
#define  CRCPARCTL1_PARITY_ENABLE BIT_32(0)
#define  CRCPARCTL1_CRC_ENABLE    BIT_32(4)
#define  CRCPARCTL1_CRC_INC_DM    BIT_32(7)
#define  CRCPARCTL1_CAPARITY_DISABLE_BEFORE_SR BIT_32(12)

#define DDR_UMCTL2_CRCPARSTAT    0x6001070cc
#define  CRCPARSTAT_DFI_ALERT_ERR_CNT GENMASK_32(15, 0)
#define  CRCPARSTAT_DFI_ALERT_ERR_INT BIT_32(16)

#define DDR_UMCTL2_INIT0         0x6001070d0
#define  INIT0_PRE_CKE_X1024      GENMASK_32(11, 0)
#define  INIT0_POST_CKE_X1024     GENMASK_32(25, 16)
#define  INIT0_SKIP_DRAM_INIT     GENMASK_32(31, 30)

#define DDR_UMCTL2_INIT1         0x6001070d4
#define  INIT1_PRE_OCD_X32        GENMASK_32(3, 0)
#define  INIT1_DRAM_RSTN_X1024    GENMASK_32(24, 16)

#define DDR_UMCTL2_INIT2         0x6001070d8
#define  INIT2_MIN_STABLE_CLOCK_X1 GENMASK_32(3, 0)
#define  INIT2_IDLE_AFTER_RESET_X32 GENMASK_32(15, 8)

#define DDR_UMCTL2_INIT3         0x6001070dc
#define  INIT3_EMR                GENMASK_32(15, 0)
#define  INIT3_MR                 GENMASK_32(31, 16)

#define DDR_UMCTL2_INIT4         0x6001070e0
#define  INIT4_EMR3               GENMASK_32(15, 0)
#define  INIT4_EMR2               GENMASK_32(31, 16)

#define DDR_UMCTL2_INIT5         0x6001070e4
#define  INIT5_MAX_AUTO_INIT_X1024 GENMASK_32(9, 0)
#define  INIT5_DEV_ZQINIT_X32     GENMASK_32(23, 16)

#define DDR_UMCTL2_INIT6         0x6001070e8
#define  INIT6_MR5                GENMASK_32(15, 0)
#define  INIT6_MR4                GENMASK_32(31, 16)

#define DDR_UMCTL2_INIT7         0x6001070ec
#define  INIT7_MR6                GENMASK_32(15, 0)

#define DDR_UMCTL2_DIMMCTL       0x6001070f0
#define  DIMMCTL_DIMM_STAGGER_CS_EN BIT_32(0)
#define  DIMMCTL_DIMM_ADDR_MIRR_EN BIT_32(1)
#define  DIMMCTL_DIMM_OUTPUT_INV_EN BIT_32(2)
#define  DIMMCTL_MRS_A17_EN       BIT_32(3)
#define  DIMMCTL_MRS_BG1_EN       BIT_32(4)
#define  DIMMCTL_DIMM_DIS_BG_MIRRORING BIT_32(5)
#define  DIMMCTL_LRDIMM_BCOM_CMD_PROT BIT_32(6)

#define DDR_UMCTL2_RANKCTL       0x6001070f4
#define  RANKCTL_MAX_RANK_RD      GENMASK_32(3, 0)
#define  RANKCTL_DIFF_RANK_RD_GAP GENMASK_32(7, 4)
#define  RANKCTL_DIFF_RANK_WR_GAP GENMASK_32(11, 8)

#define DDR_UMCTL2_DRAMTMG0      0x600107100
#define  DRAMTMG0_T_RAS_MIN       GENMASK_32(5, 0)
#define  DRAMTMG0_T_RAS_MAX       GENMASK_32(14, 8)
#define  DRAMTMG0_T_FAW           GENMASK_32(21, 16)
#define  DRAMTMG0_WR2PRE          GENMASK_32(30, 24)

#define DDR_UMCTL2_DRAMTMG1      0x600107104
#define  DRAMTMG1_T_RC            GENMASK_32(6, 0)
#define  DRAMTMG1_RD2PRE          GENMASK_32(13, 8)
#define  DRAMTMG1_T_XP            GENMASK_32(20, 16)

#define DDR_UMCTL2_DRAMTMG2      0x600107108
#define  DRAMTMG2_WR2RD           GENMASK_32(5, 0)
#define  DRAMTMG2_RD2WR           GENMASK_32(13, 8)
#define  DRAMTMG2_READ_LATENCY    GENMASK_32(21, 16)
#define  DRAMTMG2_WRITE_LATENCY   GENMASK_32(29, 24)

#define DDR_UMCTL2_DRAMTMG3      0x60010710c
#define  DRAMTMG3_T_MOD           GENMASK_32(9, 0)
#define  DRAMTMG3_T_MRD           GENMASK_32(17, 12)
#define  DRAMTMG3_T_MRW           GENMASK_32(29, 20)

#define DDR_UMCTL2_DRAMTMG4      0x600107110
#define  DRAMTMG4_T_RP            GENMASK_32(4, 0)
#define  DRAMTMG4_T_RRD           GENMASK_32(11, 8)
#define  DRAMTMG4_T_CCD           GENMASK_32(19, 16)
#define  DRAMTMG4_T_RCD           GENMASK_32(28, 24)

#define DDR_UMCTL2_DRAMTMG5      0x600107114
#define  DRAMTMG5_T_CKE           GENMASK_32(4, 0)
#define  DRAMTMG5_T_CKESR         GENMASK_32(13, 8)
#define  DRAMTMG5_T_CKSRE         GENMASK_32(19, 16)
#define  DRAMTMG5_T_CKSRX         GENMASK_32(27, 24)

#define DDR_UMCTL2_DRAMTMG6      0x600107118
#define  DRAMTMG6_T_CKCSX         GENMASK_32(3, 0)
#define  DRAMTMG6_T_CKDPDX        GENMASK_32(19, 16)
#define  DRAMTMG6_T_CKDPDE        GENMASK_32(27, 24)

#define DDR_UMCTL2_DRAMTMG7      0x60010711c
#define  DRAMTMG7_T_CKPDX         GENMASK_32(3, 0)
#define  DRAMTMG7_T_CKPDE         GENMASK_32(11, 8)

#define DDR_UMCTL2_DRAMTMG8      0x600107120
#define  DRAMTMG8_T_XS_X32        GENMASK_32(6, 0)
#define  DRAMTMG8_T_XS_DLL_X32    GENMASK_32(14, 8)
#define  DRAMTMG8_T_XS_ABORT_X32  GENMASK_32(22, 16)
#define  DRAMTMG8_T_XS_FAST_X32   GENMASK_32(30, 24)

#define DDR_UMCTL2_DRAMTMG9      0x600107124
#define  DRAMTMG9_WR2RD_S         GENMASK_32(5, 0)
#define  DRAMTMG9_T_RRD_S         GENMASK_32(11, 8)
#define  DRAMTMG9_T_CCD_S         GENMASK_32(18, 16)
#define  DRAMTMG9_DDR4_WR_PREAMBLE BIT_32(30)

#define DDR_UMCTL2_DRAMTMG10     0x600107128
#define  DRAMTMG10_T_GEAR_HOLD    GENMASK_32(1, 0)
#define  DRAMTMG10_T_GEAR_SETUP   GENMASK_32(3, 2)
#define  DRAMTMG10_T_CMD_GEAR     GENMASK_32(12, 8)
#define  DRAMTMG10_T_SYNC_GEAR    GENMASK_32(20, 16)

#define DDR_UMCTL2_DRAMTMG11     0x60010712c
#define  DRAMTMG11_T_CKMPE        GENMASK_32(4, 0)
#define  DRAMTMG11_T_MPX_S        GENMASK_32(9, 8)
#define  DRAMTMG11_T_MPX_LH       GENMASK_32(20, 16)
#define  DRAMTMG11_POST_MPSM_GAP_X32 GENMASK_32(30, 24)

#define DDR_UMCTL2_DRAMTMG12     0x600107130
#define  DRAMTMG12_T_MRD_PDA      GENMASK_32(4, 0)

#define DDR_UMCTL2_DRAMTMG14     0x600107138
#define  DRAMTMG14_T_XSR          GENMASK_32(11, 0)

#define DDR_UMCTL2_DRAMTMG15     0x60010713c
#define  DRAMTMG15_T_STAB_X32     GENMASK_32(7, 0)
#define  DRAMTMG15_EN_DFI_LP_T_STAB BIT_32(31)

#define DDR_UMCTL2_ZQCTL0        0x600107180
#define  ZQCTL0_T_ZQ_SHORT_NOP    GENMASK_32(9, 0)
#define  ZQCTL0_T_ZQ_LONG_NOP     GENMASK_32(26, 16)
#define  ZQCTL0_DIS_MPSMX_ZQCL    BIT_32(28)
#define  ZQCTL0_ZQ_RESISTOR_SHARED BIT_32(29)
#define  ZQCTL0_DIS_SRX_ZQCL      BIT_32(30)
#define  ZQCTL0_DIS_AUTO_ZQ       BIT_32(31)

#define DDR_UMCTL2_ZQCTL1        0x600107184
#define  ZQCTL1_T_ZQ_SHORT_INTERVAL_X1024 GENMASK_32(19, 0)
#define  ZQCTL1_T_ZQ_RESET_NOP    GENMASK_32(29, 20)

#define DDR_UMCTL2_ZQCTL2        0x600107188
#define  ZQCTL2_ZQ_RESET          BIT_32(0)

#define DDR_UMCTL2_ZQSTAT        0x60010718c
#define  ZQSTAT_ZQ_RESET_BUSY     BIT_32(0)

#define DDR_UMCTL2_DFITMG0       0x600107190
#define  DFITMG0_DFI_TPHY_WRLAT   GENMASK_32(5, 0)
#define  DFITMG0_DFI_TPHY_WRDATA  GENMASK_32(13, 8)
#define  DFITMG0_DFI_WRDATA_USE_DFI_PHY_CLK BIT_32(15)
#define  DFITMG0_DFI_T_RDDATA_EN  GENMASK_32(22, 16)
#define  DFITMG0_DFI_RDDATA_USE_DFI_PHY_CLK BIT_32(23)
#define  DFITMG0_DFI_T_CTRL_DELAY GENMASK_32(28, 24)

#define DDR_UMCTL2_DFITMG1       0x600107194
#define  DFITMG1_DFI_T_DRAM_CLK_ENABLE GENMASK_32(4, 0)
#define  DFITMG1_DFI_T_DRAM_CLK_DISABLE GENMASK_32(12, 8)
#define  DFITMG1_DFI_T_WRDATA_DELAY GENMASK_32(20, 16)
#define  DFITMG1_DFI_T_PARIN_LAT  GENMASK_32(25, 24)
#define  DFITMG1_DFI_T_CMD_LAT    GENMASK_32(31, 28)

#define DDR_UMCTL2_DFILPCFG0     0x600107198
#define  DFILPCFG0_DFI_LP_EN_PD   BIT_32(0)
#define  DFILPCFG0_DFI_LP_WAKEUP_PD GENMASK_32(7, 4)
#define  DFILPCFG0_DFI_LP_EN_SR   BIT_32(8)
#define  DFILPCFG0_DFI_LP_WAKEUP_SR GENMASK_32(15, 12)
#define  DFILPCFG0_DFI_LP_EN_DPD  BIT_32(16)
#define  DFILPCFG0_DFI_LP_WAKEUP_DPD GENMASK_32(23, 20)
#define  DFILPCFG0_DFI_TLP_RESP   GENMASK_32(28, 24)

#define DDR_UMCTL2_DFILPCFG1     0x60010719c
#define  DFILPCFG1_DFI_LP_EN_MPSM BIT_32(0)
#define  DFILPCFG1_DFI_LP_WAKEUP_MPSM GENMASK_32(7, 4)

#define DDR_UMCTL2_DFIUPD0       0x6001071a0
#define  DFIUPD0_DFI_T_CTRLUP_MIN GENMASK_32(9, 0)
#define  DFIUPD0_DFI_T_CTRLUP_MAX GENMASK_32(25, 16)
#define  DFIUPD0_CTRLUPD_PRE_SRX  BIT_32(29)
#define  DFIUPD0_DIS_AUTO_CTRLUPD_SRX BIT_32(30)
#define  DFIUPD0_DIS_AUTO_CTRLUPD BIT_32(31)

#define DDR_UMCTL2_DFIUPD1       0x6001071a4
#define  DFIUPD1_DFI_T_CTRLUPD_INTERVAL_MAX_X1024 GENMASK_32(7, 0)
#define  DFIUPD1_DFI_T_CTRLUPD_INTERVAL_MIN_X1024 GENMASK_32(23, 16)

#define DDR_UMCTL2_DFIUPD2       0x6001071a8
#define  DFIUPD2_DFI_PHYUPD_EN    BIT_32(31)

#define DDR_UMCTL2_DFIMISC       0x6001071b0
#define  DFIMISC_DFI_INIT_COMPLETE_EN BIT_32(0)
#define  DFIMISC_PHY_DBI_MODE     BIT_32(1)
#define  DFIMISC_CTL_IDLE_EN      BIT_32(4)
#define  DFIMISC_DFI_INIT_START   BIT_32(5)
#define  DFIMISC_DFI_FREQUENCY    GENMASK_32(12, 8)

#define DDR_UMCTL2_DFITMG3       0x6001071b8
#define  DFITMG3_DFI_T_GEARDOWN_DELAY GENMASK_32(4, 0)

#define DDR_UMCTL2_DFISTAT       0x6001071bc
#define  DFISTAT_DFI_INIT_COMPLETE BIT_32(0)
#define  DFISTAT_DFI_LP_ACK       BIT_32(1)

#define DDR_UMCTL2_DBICTL        0x6001071c0
#define  DBICTL_DM_EN             BIT_32(0)
#define  DBICTL_WR_DBI_EN         BIT_32(1)
#define  DBICTL_RD_DBI_EN         BIT_32(2)

#define DDR_UMCTL2_DFIPHYMSTR    0x6001071c4
#define  DFIPHYMSTR_DFI_PHYMSTR_EN BIT_32(0)

#define DDR_UMCTL2_ADDRMAP0      0x600107200
#define  ADDRMAP0_ADDRMAP_CS_BIT0 GENMASK_32(4, 0)

#define DDR_UMCTL2_ADDRMAP1      0x600107204
#define  ADDRMAP1_ADDRMAP_BANK_B0 GENMASK_32(5, 0)
#define  ADDRMAP1_ADDRMAP_BANK_B1 GENMASK_32(13, 8)
#define  ADDRMAP1_ADDRMAP_BANK_B2 GENMASK_32(21, 16)

#define DDR_UMCTL2_ADDRMAP2      0x600107208
#define  ADDRMAP2_ADDRMAP_COL_B2  GENMASK_32(3, 0)
#define  ADDRMAP2_ADDRMAP_COL_B3  GENMASK_32(11, 8)
#define  ADDRMAP2_ADDRMAP_COL_B4  GENMASK_32(19, 16)
#define  ADDRMAP2_ADDRMAP_COL_B5  GENMASK_32(27, 24)

#define DDR_UMCTL2_ADDRMAP3      0x60010720c
#define  ADDRMAP3_ADDRMAP_COL_B6  GENMASK_32(3, 0)
#define  ADDRMAP3_ADDRMAP_COL_B7  GENMASK_32(12, 8)
#define  ADDRMAP3_ADDRMAP_COL_B8  GENMASK_32(20, 16)
#define  ADDRMAP3_ADDRMAP_COL_B9  GENMASK_32(28, 24)

#define DDR_UMCTL2_ADDRMAP4      0x600107210
#define  ADDRMAP4_ADDRMAP_COL_B10 GENMASK_32(4, 0)
#define  ADDRMAP4_ADDRMAP_COL_B11 GENMASK_32(12, 8)

#define DDR_UMCTL2_ADDRMAP5      0x600107214
#define  ADDRMAP5_ADDRMAP_ROW_B0  GENMASK_32(3, 0)
#define  ADDRMAP5_ADDRMAP_ROW_B1  GENMASK_32(11, 8)
#define  ADDRMAP5_ADDRMAP_ROW_B2_10 GENMASK_32(19, 16)
#define  ADDRMAP5_ADDRMAP_ROW_B11 GENMASK_32(27, 24)

#define DDR_UMCTL2_ADDRMAP6      0x600107218
#define  ADDRMAP6_ADDRMAP_ROW_B12 GENMASK_32(3, 0)
#define  ADDRMAP6_ADDRMAP_ROW_B13 GENMASK_32(11, 8)
#define  ADDRMAP6_ADDRMAP_ROW_B14 GENMASK_32(19, 16)
#define  ADDRMAP6_ADDRMAP_ROW_B15 GENMASK_32(27, 24)
#define  ADDRMAP6_LPDDR3_6GB_12GB BIT_32(31)

#define DDR_UMCTL2_ADDRMAP7      0x60010721c
#define  ADDRMAP7_ADDRMAP_ROW_B16 GENMASK_32(3, 0)
#define  ADDRMAP7_ADDRMAP_ROW_B17 GENMASK_32(11, 8)

#define DDR_UMCTL2_ADDRMAP8      0x600107220
#define  ADDRMAP8_ADDRMAP_BG_B0   GENMASK_32(5, 0)
#define  ADDRMAP8_ADDRMAP_BG_B1   GENMASK_32(13, 8)

#define DDR_UMCTL2_ADDRMAP9      0x600107224
#define  ADDRMAP9_ADDRMAP_ROW_B2  GENMASK_32(3, 0)
#define  ADDRMAP9_ADDRMAP_ROW_B3  GENMASK_32(11, 8)
#define  ADDRMAP9_ADDRMAP_ROW_B4  GENMASK_32(19, 16)
#define  ADDRMAP9_ADDRMAP_ROW_B5  GENMASK_32(27, 24)

#define DDR_UMCTL2_ADDRMAP10     0x600107228
#define  ADDRMAP10_ADDRMAP_ROW_B6 GENMASK_32(3, 0)
#define  ADDRMAP10_ADDRMAP_ROW_B7 GENMASK_32(11, 8)
#define  ADDRMAP10_ADDRMAP_ROW_B8 GENMASK_32(19, 16)
#define  ADDRMAP10_ADDRMAP_ROW_B9 GENMASK_32(27, 24)

#define DDR_UMCTL2_ADDRMAP11     0x60010722c
#define  ADDRMAP11_ADDRMAP_ROW_B10 GENMASK_32(3, 0)

#define DDR_UMCTL2_ODTCFG        0x600107240
#define  ODTCFG_RD_ODT_DELAY      GENMASK_32(6, 2)
#define  ODTCFG_RD_ODT_HOLD       GENMASK_32(11, 8)
#define  ODTCFG_WR_ODT_DELAY      GENMASK_32(20, 16)
#define  ODTCFG_WR_ODT_HOLD       GENMASK_32(27, 24)

#define DDR_UMCTL2_ODTMAP        0x600107244
#define  ODTMAP_RANK0_WR_ODT      GENMASK_32(1, 0)
#define  ODTMAP_RANK0_RD_ODT      GENMASK_32(5, 4)
#define  ODTMAP_RANK1_WR_ODT      GENMASK_32(9, 8)
#define  ODTMAP_RANK1_RD_ODT      GENMASK_32(13, 12)

#define DDR_UMCTL2_SCHED         0x600107250
#define  SCHED_FORCE_LOW_PRI_N    BIT_32(0)
#define  SCHED_PREFER_WRITE       BIT_32(1)
#define  SCHED_PAGECLOSE          BIT_32(2)
#define  SCHED_LPR_NUM_ENTRIES    GENMASK_32(11, 8)
#define  SCHED_GO2CRITICAL_HYSTERESIS GENMASK_32(23, 16)
#define  SCHED_RDWR_IDLE_GAP      GENMASK_32(30, 24)

#define DDR_UMCTL2_SCHED1        0x600107254
#define  SCHED1_PAGECLOSE_TIMER   GENMASK_32(7, 0)

#define DDR_UMCTL2_PERFHPR1      0x60010725c
#define  PERFHPR1_HPR_MAX_STARVE  GENMASK_32(15, 0)
#define  PERFHPR1_HPR_XACT_RUN_LENGTH GENMASK_32(31, 24)

#define DDR_UMCTL2_PERFLPR1      0x600107264
#define  PERFLPR1_LPR_MAX_STARVE  GENMASK_32(15, 0)
#define  PERFLPR1_LPR_XACT_RUN_LENGTH GENMASK_32(31, 24)

#define DDR_UMCTL2_PERFWR1       0x60010726c
#define  PERFWR1_W_MAX_STARVE     GENMASK_32(15, 0)
#define  PERFWR1_W_XACT_RUN_LENGTH GENMASK_32(31, 24)

#define DDR_UMCTL2_DBG0          0x600107300
#define  DBG0_DIS_WC              BIT_32(0)
#define  DBG0_DIS_COLLISION_PAGE_OPT BIT_32(4)

#define DDR_UMCTL2_DBG1          0x600107304
#define  DBG1_DIS_DQ              BIT_32(0)
#define  DBG1_DIS_HIF             BIT_32(1)

#define DDR_UMCTL2_DBGCAM        0x600107308
#define  DBGCAM_DBG_HPR_Q_DEPTH   GENMASK_32(4, 0)
#define  DBGCAM_DBG_LPR_Q_DEPTH   GENMASK_32(12, 8)
#define  DBGCAM_DBG_W_Q_DEPTH     GENMASK_32(20, 16)
#define  DBGCAM_DBG_STALL         BIT_32(24)
#define  DBGCAM_DBG_RD_Q_EMPTY    BIT_32(25)
#define  DBGCAM_DBG_WR_Q_EMPTY    BIT_32(26)
#define  DBGCAM_RD_DATA_PIPELINE_EMPTY BIT_32(28)
#define  DBGCAM_WR_DATA_PIPELINE_EMPTY BIT_32(29)

#define DDR_UMCTL2_DBGCMD        0x60010730c
#define  DBGCMD_RANK0_REFRESH     BIT_32(0)
#define  DBGCMD_RANK1_REFRESH     BIT_32(1)
#define  DBGCMD_ZQ_CALIB_SHORT    BIT_32(4)
#define  DBGCMD_CTRLUPD           BIT_32(5)

#define DDR_UMCTL2_DBGSTAT       0x600107310
#define  DBGSTAT_RANK0_REFRESH_BUSY BIT_32(0)
#define  DBGSTAT_RANK1_REFRESH_BUSY BIT_32(1)
#define  DBGSTAT_ZQ_CALIB_SHORT_BUSY BIT_32(4)
#define  DBGSTAT_CTRLUPD_BUSY     BIT_32(5)

#define DDR_UMCTL2_SWCTL         0x600107320
#define  SWCTL_SW_DONE            BIT_32(0)

#define DDR_UMCTL2_SWSTAT        0x600107324
#define  SWSTAT_SW_DONE_ACK       BIT_32(0)

#define DDR_UMCTL2_POISONCFG     0x60010736c
#define  POISONCFG_WR_POISON_SLVERR_EN BIT_32(0)
#define  POISONCFG_WR_POISON_INTR_EN BIT_32(4)
#define  POISONCFG_WR_POISON_INTR_CLR BIT_32(8)
#define  POISONCFG_RD_POISON_SLVERR_EN BIT_32(16)
#define  POISONCFG_RD_POISON_INTR_EN BIT_32(20)
#define  POISONCFG_RD_POISON_INTR_CLR BIT_32(24)

#define DDR_UMCTL2_POISONSTAT    0x600107370
#define  POISONSTAT_WR_POISON_INTR_0 BIT_32(0)
#define  POISONSTAT_RD_POISON_INTR_0 BIT_32(16)

#define DDR_UMCTL2_ADVECCINDEX   0x600107374
#define  ADVECCINDEX_ECC_SYNDROME_SEL GENMASK_32(2, 0)
#define  ADVECCINDEX_ECC_ERR_SYMBOL_SEL GENMASK_32(4, 3)
#define  ADVECCINDEX_ECC_POISON_BEATS_SEL GENMASK_32(8, 5)

#define DDR_UMCTL2_ECCPOISONPAT0 0x60010737c
#define  ECCPOISONPAT0_ECC_POISON_DATA_31_0 GENMASK_32(31, 0)

#define DDR_UMCTL2_ECCPOISONPAT2 0x600107384
#define  ECCPOISONPAT2_ECC_POISON_DATA_71_64 GENMASK_32(7, 0)

#define DDR_UMCTL2_PSTAT         0x6001073fc
#define  PSTAT_RD_PORT_BUSY_0     BIT_32(0)
#define  PSTAT_WR_PORT_BUSY_0     BIT_32(16)

#define DDR_UMCTL2_PCCFG         0x600107400
#define  PCCFG_GO2CRITICAL_EN     BIT_32(0)
#define  PCCFG_PAGEMATCH_LIMIT    BIT_32(4)
#define  PCCFG_BL_EXP_MODE        BIT_32(8)

#define DDR_UMCTL2_PCFGR_0       0x600107404
#define  PCFGR_0_RD_PORT_PRIORITY GENMASK_32(9, 0)
#define  PCFGR_0_RD_PORT_AGING_EN BIT_32(12)
#define  PCFGR_0_RD_PORT_URGENT_EN BIT_32(13)
#define  PCFGR_0_RD_PORT_PAGEMATCH_EN BIT_32(14)

#define DDR_UMCTL2_PCFGW_0       0x600107408
#define  PCFGW_0_WR_PORT_PRIORITY GENMASK_32(9, 0)
#define  PCFGW_0_WR_PORT_AGING_EN BIT_32(12)
#define  PCFGW_0_WR_PORT_URGENT_EN BIT_32(13)
#define  PCFGW_0_WR_PORT_PAGEMATCH_EN BIT_32(14)

#define DDR_UMCTL2_PCTRL_0       0x600107490
#define  PCTRL_0_PORT_EN          BIT_32(0)

#define DDR_UMCTL2_PCFGQOS0_0    0x600107494
#define  PCFGQOS0_0_RQOS_MAP_LEVEL1 GENMASK_32(3, 0)
#define  PCFGQOS0_0_RQOS_MAP_REGION0 GENMASK_32(17, 16)
#define  PCFGQOS0_0_RQOS_MAP_REGION1 GENMASK_32(21, 20)

#define DDR_UMCTL2_SBRCTL        0x600107f24
#define  SBRCTL_SCRUB_EN          BIT_32(0)
#define  SBRCTL_SCRUB_DURING_LOWPOWER BIT_32(1)
#define  SBRCTL_SCRUB_MODE        BIT_32(2)
#define  SBRCTL_SCRUB_BURST       GENMASK_32(6, 4)
#define  SBRCTL_SCRUB_INTERVAL    GENMASK_32(20, 8)

#define DDR_UMCTL2_SBRSTAT       0x600107f28
#define  SBRSTAT_SCRUB_BUSY       BIT_32(0)
#define  SBRSTAT_SCRUB_DONE       BIT_32(1)

#define DDR_UMCTL2_SBRWDATA0     0x600107f2c
#define  SBRWDATA0_SCRUB_PATTERN0 GENMASK_32(31, 0)


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
