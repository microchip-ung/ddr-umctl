/*
 * Copyright (C) 2022 Microchip Technology Inc. and its subsidiaries.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __DDR_REG_H
#define __DDR_REG_H

#include <ddr_platform.h>

#define CPU_RESET                0xe00c0084
#define  RESET_VCORE_RST          BIT_32(7)
#define  RESET_CPU_CORE_0_WARM_RST BIT_32(6)
#define  RESET_PROC_DBG_RST       BIT_32(5)
#define  RESET_JTAG_RST           BIT_32(4)
#define  RESET_CPU_L2_RST         BIT_32(3)
#define  RESET_MEM_RST            BIT_32(2)
#define  RESET_WDT_FORCE_RST      BIT_32(1)
#define  RESET_CPU_CORE_0_COLD_RST BIT_32(0)

#define CPU_DDRCTRL_CLK          0xe00c02b0
#define  DDRCTRL_CLK_RAM_RING_ENA BIT_32(7)
#define  DDRCTRL_CLK_DDRPHY_APB_CLK_ENA BIT_32(6)
#define  DDRCTRL_CLK_DDRPHY_CTL_CLK_ENA BIT_32(5)
#define  DDRCTRL_CLK_DDR_APB_CLK_ENA BIT_32(4)
#define  DDRCTRL_CLK_DDR_AXI2_CLK_ENA BIT_32(3)
#define  DDRCTRL_CLK_DDR_AXI1_CLK_ENA BIT_32(2)
#define  DDRCTRL_CLK_DDR_AXI0_CLK_ENA BIT_32(1)
#define  DDRCTRL_CLK_DDR_CLK_ENA  BIT_32(0)

#define CPU_DDRCTRL_RST          0xe00c02b4
#define  DDRCTRL_RST_DDRPHY_APB_RST BIT_32(7)
#define  DDRCTRL_RST_FPGA_DDRPHY_SOFT_RST BIT_32(6)
#define  DDRCTRL_RST_DDRPHY_CTL_RST BIT_32(5)
#define  DDRCTRL_RST_DDR_APB_RST  BIT_32(4)
#define  DDRCTRL_RST_DDR_AXI2_RST BIT_32(3)
#define  DDRCTRL_RST_DDR_AXI1_RST BIT_32(2)
#define  DDRCTRL_RST_DDR_AXI0_RST BIT_32(1)
#define  DDRCTRL_RST_DDRC_RST     BIT_32(0)

#define DDR_PHY_RIDR             0xe0084000
#define  RIDR_UDRID               GENMASK_32(31, 24)
#define  RIDR_PHYID               GENMASK_32(23, 12)
#define  RIDR_PUBID               GENMASK_32(11, 0)

#define DDR_PHY_PIR              0xe0084004
#define  PIR_INITBYP              BIT_32(31)
#define  PIR_ZCALBYP              BIT_32(30)
#define  PIR_DCALBYP              BIT_32(29)
#define  PIR_LOCKBYP              BIT_32(28)
#define  PIR_CLRSR                BIT_32(27)
#define  PIR_RDIMMINIT            BIT_32(19)
#define  PIR_CTLDINIT             BIT_32(18)
#define  PIR_PLLBYP               BIT_32(17)
#define  PIR_ICPC                 BIT_32(16)
#define  PIR_WREYE                BIT_32(15)
#define  PIR_RDEYE                BIT_32(14)
#define  PIR_WRDSKW               BIT_32(13)
#define  PIR_RDDSKW               BIT_32(12)
#define  PIR_WLADJ                BIT_32(11)
#define  PIR_QSGATE               BIT_32(10)
#define  PIR_WL                   BIT_32(9)
#define  PIR_DRAMINIT             BIT_32(8)
#define  PIR_DRAMRST              BIT_32(7)
#define  PIR_PHYRST               BIT_32(6)
#define  PIR_DCAL                 BIT_32(5)
#define  PIR_PLLINIT              BIT_32(4)
#define  PIR_ZCAL                 BIT_32(1)
#define  PIR_INIT                 BIT_32(0)

#define DDR_PHY_PGCR0            0xe0084008
#define  PGCR0_CKEN               GENMASK_32(31, 26)
#define  PGCR0_PUBMODE            BIT_32(25)
#define  PGCR0_DTOSEL             GENMASK_32(18, 14)
#define  PGCR0_OSCWDL             GENMASK_32(13, 12)
#define  PGCR0_OSCDIV             GENMASK_32(11, 9)
#define  PGCR0_OSCEN              BIT_32(8)
#define  PGCR0_DLTST              BIT_32(7)
#define  PGCR0_DLTMODE            BIT_32(6)
#define  PGCR0_RDBVT              BIT_32(5)
#define  PGCR0_WDBVT              BIT_32(4)
#define  PGCR0_RGLVT              BIT_32(3)
#define  PGCR0_RDLVT              BIT_32(2)
#define  PGCR0_WDLVT              BIT_32(1)
#define  PGCR0_WLLVT              BIT_32(0)

#define DDR_PHY_PGCR1            0xe008400c
#define  PGCR1_LBMODE             BIT_32(31)
#define  PGCR1_LBGDQS             GENMASK_32(30, 29)
#define  PGCR1_LBDQSS             BIT_32(28)
#define  PGCR1_IOLB               BIT_32(27)
#define  PGCR1_INHVT              BIT_32(26)
#define  PGCR1_DXHRST             BIT_32(25)
#define  PGCR1_ZCKSEL             GENMASK_32(24, 23)
#define  PGCR1_DLDLMT             GENMASK_32(22, 15)
#define  PGCR1_FDEPTH             GENMASK_32(14, 13)
#define  PGCR1_LPFDEPTH           GENMASK_32(12, 11)
#define  PGCR1_LPFEN              BIT_32(10)
#define  PGCR1_MDLEN              BIT_32(9)
#define  PGCR1_WLSELT             BIT_32(6)
#define  PGCR1_ACHRST             BIT_32(5)
#define  PGCR1_WSLOPT             BIT_32(4)
#define  PGCR1_WLSTEP             BIT_32(2)
#define  PGCR1_WLMODE             BIT_32(1)
#define  PGCR1_PDDISDX            BIT_32(0)

#define DDR_PHY_PGSR0            0xe0084010
#define  PGSR0_APLOCK             BIT_32(31)
#define  PGSR0_PLDONE_CHN         GENMASK_32(29, 28)
#define  PGSR0_WEERR              BIT_32(27)
#define  PGSR0_REERR              BIT_32(26)
#define  PGSR0_WDERR              BIT_32(25)
#define  PGSR0_RDERR              BIT_32(24)
#define  PGSR0_WLAERR             BIT_32(23)
#define  PGSR0_QSGERR             BIT_32(22)
#define  PGSR0_WLERR              BIT_32(21)
#define  PGSR0_ZCERR              BIT_32(20)
#define  PGSR0_WEDONE             BIT_32(11)
#define  PGSR0_REDONE             BIT_32(10)
#define  PGSR0_WDDONE             BIT_32(9)
#define  PGSR0_RDDONE             BIT_32(8)
#define  PGSR0_WLADONE            BIT_32(7)
#define  PGSR0_QSGDONE            BIT_32(6)
#define  PGSR0_WLDONE             BIT_32(5)
#define  PGSR0_DIDONE             BIT_32(4)
#define  PGSR0_ZCDONE             BIT_32(3)
#define  PGSR0_DCDONE             BIT_32(2)
#define  PGSR0_PLDONE             BIT_32(1)
#define  PGSR0_IDONE              BIT_32(0)

#define DDR_PHY_PGSR1            0xe0084014
#define  PGSR1_PARERR             BIT_32(31)
#define  PGSR1_VTSTOP             BIT_32(30)
#define  PGSR1_DLTCODE            GENMASK_32(24, 1)
#define  PGSR1_DLTDONE            BIT_32(0)

#define DDR_PHY_PLLCR            0xe0084018
#define  PLLCR_PLLBYP             BIT_32(31)
#define  PLLCR_PLLRST             BIT_32(30)
#define  PLLCR_PLLPD              BIT_32(29)
#define  PLLCR_FRQSEL             GENMASK_32(19, 18)
#define  PLLCR_QPMODE             BIT_32(17)
#define  PLLCR_CPPC               GENMASK_32(16, 13)
#define  PLLCR_CPIC               GENMASK_32(12, 11)
#define  PLLCR_GSHIFT             BIT_32(10)
#define  PLLCR_ATOEN              GENMASK_32(9, 6)
#define  PLLCR_ATC                GENMASK_32(5, 2)
#define  PLLCR_DTC                GENMASK_32(1, 0)

#define DDR_PHY_PTR0             0xe008401c
#define  PTR0_TPLLPD              GENMASK_32(31, 21)
#define  PTR0_TPLLGS              GENMASK_32(20, 6)
#define  PTR0_TPHYRST             GENMASK_32(5, 0)

#define DDR_PHY_PTR1             0xe0084020
#define  PTR1_TPLLLOCK            GENMASK_32(31, 16)
#define  PTR1_TPLLRST             GENMASK_32(12, 0)

#define DDR_PHY_PTR2             0xe0084024
#define  PTR2_TWLDLYS             GENMASK_32(19, 15)
#define  PTR2_TCALH               GENMASK_32(14, 10)
#define  PTR2_TCALS               GENMASK_32(9, 5)
#define  PTR2_TCALON              GENMASK_32(4, 0)

#define DDR_PHY_PTR3             0xe0084028
#define  PTR3_TDINIT1             GENMASK_32(29, 20)
#define  PTR3_TDINIT0             GENMASK_32(19, 0)

#define DDR_PHY_PTR4             0xe008402c
#define  PTR4_TDINIT3             GENMASK_32(27, 18)
#define  PTR4_TDINIT2             GENMASK_32(17, 0)

#define DDR_PHY_ACMDLR           0xe0084030
#define  ACMDLR_MDLD              GENMASK_32(23, 16)
#define  ACMDLR_TPRD              GENMASK_32(15, 8)
#define  ACMDLR_IPRD              GENMASK_32(7, 0)

#define DDR_PHY_ACBDLR           0xe0084034
#define  ACBDLR_ACBD              GENMASK_32(23, 18)
#define  ACBDLR_CK2BD             GENMASK_32(17, 12)
#define  ACBDLR_CK1BD             GENMASK_32(11, 6)
#define  ACBDLR_CK0BD             GENMASK_32(5, 0)

#define DDR_PHY_ACIOCR           0xe0084038
#define  ACIOCR_RSTIOM            BIT_32(29)
#define  ACIOCR_RSTPDR            BIT_32(28)
#define  ACIOCR_RSTPDD            BIT_32(27)
#define  ACIOCR_RSTODT            BIT_32(26)
#define  ACIOCR_RANKPDR           GENMASK_32(25, 22)
#define  ACIOCR_CSPDD             GENMASK_32(21, 18)
#define  ACIOCR_RANKODT           GENMASK_32(17, 14)
#define  ACIOCR_CKPDR             GENMASK_32(13, 11)
#define  ACIOCR_CKPDD             GENMASK_32(10, 8)
#define  ACIOCR_CKODT             GENMASK_32(7, 5)
#define  ACIOCR_ACPDR             BIT_32(4)
#define  ACIOCR_ACPDD             BIT_32(3)
#define  ACIOCR_ACODT             BIT_32(2)
#define  ACIOCR_AC0E              BIT_32(1)
#define  ACIOCR_ACIOM             BIT_32(0)

#define DDR_PHY_DXCCR            0xe008403c
#define  DXCCR_DDPDRCDO           GENMASK_32(31, 28)
#define  DXCCR_DDPDDCDO           GENMASK_32(27, 24)
#define  DXCCR_DYNDXPDR           BIT_32(23)
#define  DXCCR_DYNDXPDD           BIT_32(22)
#define  DXCCR_UDQIOM             BIT_32(21)
#define  DXCCR_UDQPDR             BIT_32(20)
#define  DXCCR_UDQPDD             BIT_32(19)
#define  DXCCR_UDQODT             BIT_32(18)
#define  DXCCR_MSBUDQ             GENMASK_32(17, 15)
#define  DXCCR_DQSNRES            GENMASK_32(12, 9)
#define  DXCCR_DQSRES             GENMASK_32(8, 5)
#define  DXCCR_DXPDR              BIT_32(4)
#define  DXCCR_DXPDD              BIT_32(3)
#define  DXCCR_MDLEN              BIT_32(2)
#define  DXCCR_DXIOM              BIT_32(1)
#define  DXCCR_DXODT              BIT_32(0)

#define DDR_PHY_DSGCR            0xe0084040
#define  DSGCR_CKEOE              BIT_32(31)
#define  DSGCR_RSTOE              BIT_32(30)
#define  DSGCR_ODTOE              BIT_32(29)
#define  DSGCR_CKOE               BIT_32(28)
#define  DSGCR_ODTPDD             GENMASK_32(27, 24)
#define  DSGCR_CKEPDD             GENMASK_32(23, 20)
#define  DSGCR_SDRMODE            BIT_32(19)
#define  DSGCR_RRMODE             BIT_32(18)
#define  DSGCR_ATOAE              BIT_32(17)
#define  DSGCR_DTOOE              BIT_32(16)
#define  DSGCR_DTOIOM             BIT_32(15)
#define  DSGCR_DTOPDR             BIT_32(14)
#define  DSGCR_DTOPDD             BIT_32(13)
#define  DSGCR_DTOODT             BIT_32(12)
#define  DSGCR_PUAD               GENMASK_32(11, 8)
#define  DSGCR_BRRMODE            BIT_32(7)
#define  DSGCR_DQSGX              BIT_32(6)
#define  DSGCR_CUAEN              BIT_32(5)
#define  DSGCR_LPPLLPD            BIT_32(4)
#define  DSGCR_LPIOPD             BIT_32(3)
#define  DSGCR_ZUEN               BIT_32(2)
#define  DSGCR_BDISEN             BIT_32(1)
#define  DSGCR_PUREN              BIT_32(0)

#define DDR_PHY_DCR              0xe0084044
#define  DCR_UDIMM                BIT_32(29)
#define  DCR_DDR2T                BIT_32(28)
#define  DCR_NOSRA                BIT_32(27)
#define  DCR_BYTEMASK             GENMASK_32(17, 10)
#define  DCR_MPRDQ                BIT_32(7)
#define  DCR_PDQ                  GENMASK_32(6, 4)
#define  DCR_DDR8BNK              BIT_32(3)
#define  DCR_DDRMD                GENMASK_32(2, 0)

#define DDR_PHY_DTPR0            0xe0084048
#define  DTPR0_TRC                GENMASK_32(31, 26)
#define  DTPR0_TRRD               GENMASK_32(25, 22)
#define  DTPR0_TRAS               GENMASK_32(21, 16)
#define  DTPR0_TRCD               GENMASK_32(15, 12)
#define  DTPR0_TRP                GENMASK_32(11, 8)
#define  DTPR0_TWTR               GENMASK_32(7, 4)
#define  DTPR0_TRTP               GENMASK_32(3, 0)

#define DDR_PHY_DTPR1            0xe008404c
#define  DTPR1_TAON_OFF_D         GENMASK_32(31, 30)
#define  DTPR1_TWLO               GENMASK_32(29, 26)
#define  DTPR1_TWLMRD             GENMASK_32(25, 20)
#define  DTPR1_TRFC               GENMASK_32(19, 11)
#define  DTPR1_TFAW               GENMASK_32(10, 5)
#define  DTPR1_TMOD               GENMASK_32(4, 2)
#define  DTPR1_TMRD               GENMASK_32(1, 0)

#define DDR_PHY_DTPR2            0xe0084050
#define  DTPR2_TCCD               BIT_32(31)
#define  DTPR2_TRTW               BIT_32(30)
#define  DTPR2_TRTODT             BIT_32(29)
#define  DTPR2_TDLLK              GENMASK_32(28, 19)
#define  DTPR2_TCKE               GENMASK_32(18, 15)
#define  DTPR2_TXP                GENMASK_32(14, 10)
#define  DTPR2_TXS                GENMASK_32(9, 0)

#define DDR_PHY_MR0              0xe0084054
#define  MR0_RSVD_15_13           GENMASK_32(15, 13)
#define  MR0_PD                   BIT_32(12)
#define  MR0_WR                   GENMASK_32(11, 9)
#define  MR0_DR                   BIT_32(8)
#define  MR0_TM                   BIT_32(7)
#define  MR0_CL_6_4               GENMASK_32(6, 4)
#define  MR0_BT                   BIT_32(3)
#define  MR0_CL_2                 BIT_32(2)
#define  MR0_BL                   GENMASK_32(1, 0)

#define DDR_PHY_MR1              0xe0084058
#define  MR1_RSVD_15_13           GENMASK_32(15, 13)
#define  MR1_QOFF                 BIT_32(12)
#define  MR1_TDQS                 BIT_32(11)
#define  MR1_RSVD_10              BIT_32(10)
#define  MR1_RTT_9                BIT_32(9)
#define  MR1_DE_RSVD_8            BIT_32(8)
#define  MR1_LEVEL                BIT_32(7)
#define  MR1_RTT_6                BIT_32(6)
#define  MR1_DIC_5                BIT_32(5)
#define  MR1_AL                   GENMASK_32(4, 3)
#define  MR1_RTT_2                BIT_32(2)
#define  MR1_DIC_1                BIT_32(1)
#define  MR1_DE                   BIT_32(0)

#define DDR_PHY_MR2              0xe008405c
#define  MR2_RSVD_15_11           GENMASK_32(15, 11)
#define  MR2_RTT_WR               GENMASK_32(10, 9)
#define  MR2_RSVD_8               BIT_32(8)
#define  MR2_SRT                  BIT_32(7)
#define  MR2_ASR                  BIT_32(6)
#define  MR2_CWL                  GENMASK_32(5, 3)
#define  MR2_PASR                 GENMASK_32(2, 0)

#define DDR_PHY_MR3              0xe0084060
#define  MR3_RSVD_15_3            GENMASK_32(15, 3)
#define  MR3_MPR                  BIT_32(2)
#define  MR3_MPRLOC               GENMASK_32(1, 0)

#define DDR_PHY_ODTCR            0xe0084064
#define  ODTCR_WRODT              GENMASK_32(31, 16)
#define  ODTCR_RDODT              GENMASK_32(15, 0)

#define DDR_PHY_DTCR             0xe0084068
#define  DTCR_RFSHDT              GENMASK_32(31, 28)
#define  DTCR_RANKEN              GENMASK_32(27, 24)
#define  DTCR_DTEXD               BIT_32(22)
#define  DTCR_DTDSTP              BIT_32(21)
#define  DTCR_DTDEN               BIT_32(20)
#define  DTCR_DTDBS               GENMASK_32(19, 16)
#define  DTCR_DTWDQMO             BIT_32(14)
#define  DTCR_DTBDC               BIT_32(13)
#define  DTCR_DTWBDDM             BIT_32(12)
#define  DTCR_DTWDQM              GENMASK_32(11, 8)
#define  DTCR_DTCMPD              BIT_32(7)
#define  DTCR_DTMPR               BIT_32(6)
#define  DTCR_DTRANK              GENMASK_32(5, 4)
#define  DTCR_DTRPTN              GENMASK_32(3, 0)

#define DDR_PHY_DTAR0            0xe008406c
#define  DTAR0_DTBANK             GENMASK_32(30, 28)
#define  DTAR0_DTROW              GENMASK_32(27, 12)
#define  DTAR0_DTCOL              GENMASK_32(11, 0)

#define DDR_PHY_DTAR1            0xe0084070
#define  DTAR1_DTBANK             GENMASK_32(30, 28)
#define  DTAR1_DTROW              GENMASK_32(27, 12)
#define  DTAR1_DTCOL              GENMASK_32(11, 0)

#define DDR_PHY_DTAR2            0xe0084074
#define  DTAR2_DTBANK             GENMASK_32(30, 28)
#define  DTAR2_DTROW              GENMASK_32(27, 12)
#define  DTAR2_DTCOL              GENMASK_32(11, 0)

#define DDR_PHY_DTAR3            0xe0084078
#define  DTAR3_DTBANK             GENMASK_32(30, 28)
#define  DTAR3_DTROW              GENMASK_32(27, 12)
#define  DTAR3_DTCOL              GENMASK_32(11, 0)

#define DDR_PHY_DTDR0            0xe008407c
#define  DTDR0_DTBYTE3            GENMASK_32(31, 24)
#define  DTDR0_DTBYTE2            GENMASK_32(23, 16)
#define  DTDR0_DTBYTE1            GENMASK_32(15, 8)
#define  DTDR0_DTBYTE0            GENMASK_32(7, 0)

#define DDR_PHY_DTDR1            0xe0084080
#define  DTDR1_DTBYTE7            GENMASK_32(31, 24)
#define  DTDR1_DTBYTE6            GENMASK_32(23, 16)
#define  DTDR1_DTBYTE5            GENMASK_32(15, 8)
#define  DTDR1_DTBYTE4            GENMASK_32(7, 0)

#define DDR_PHY_DTEDR0           0xe0084084
#define  DTEDR0_DTWBMX            GENMASK_32(31, 24)
#define  DTEDR0_DTWBMN            GENMASK_32(23, 16)
#define  DTEDR0_DTWLMX            GENMASK_32(15, 8)
#define  DTEDR0_DTWLMN            GENMASK_32(7, 0)

#define DDR_PHY_DTEDR1           0xe0084088
#define  DTEDR1_DTRBMX            GENMASK_32(31, 24)
#define  DTEDR1_DTRBMN            GENMASK_32(23, 16)
#define  DTEDR1_DTRLMX            GENMASK_32(15, 8)
#define  DTEDR1_DTRLMN            GENMASK_32(7, 0)

#define DDR_PHY_PGCR2            0xe008408c
#define  PGCR2_DYNACPDD           BIT_32(31)
#define  PGCR2_LPMSTRC0           BIT_32(30)
#define  PGCR2_ACPDDC             BIT_32(29)
#define  PGCR2_SHRAC              BIT_32(28)
#define  PGCR2_DTPMXTMR           GENMASK_32(27, 20)
#define  PGCR2_FXDLAT             BIT_32(19)
#define  PGCR2_NOBUB              BIT_32(18)
#define  PGCR2_TREFPRD            GENMASK_32(17, 0)

#define DDR_PHY_RDIMMGCR0        0xe00840b0
#define  RDIMMGCR0_MIRROR         BIT_32(31)
#define  RDIMMGCR0_QCSEN          BIT_32(30)
#define  RDIMMGCR0_MIRROROE       BIT_32(29)
#define  RDIMMGCR0_QCSENOE        BIT_32(28)
#define  RDIMMGCR0_RDIMMIOM       BIT_32(27)
#define  RDIMMGCR0_RDIMMPDR       BIT_32(26)
#define  RDIMMGCR0_RDIMMPDD       BIT_32(25)
#define  RDIMMGCR0_RDIMMODT       BIT_32(24)
#define  RDIMMGCR0_ERROUTOE       BIT_32(23)
#define  RDIMMGCR0_ERROUTIOM      BIT_32(22)
#define  RDIMMGCR0_ERROUTPDR      BIT_32(21)
#define  RDIMMGCR0_ERROUTPDD      BIT_32(20)
#define  RDIMMGCR0_ERROUTODT      BIT_32(19)
#define  RDIMMGCR0_PARINOE        BIT_32(18)
#define  RDIMMGCR0_PARINIOM       BIT_32(17)
#define  RDIMMGCR0_PARINPDR       BIT_32(16)
#define  RDIMMGCR0_PARINPDD       BIT_32(15)
#define  RDIMMGCR0_PARINODT       BIT_32(14)
#define  RDIMMGCR0_SOPERR         BIT_32(2)
#define  RDIMMGCR0_ERRNOREG       BIT_32(1)
#define  RDIMMGCR0_RDIMM          BIT_32(0)

#define DDR_PHY_RDIMMGCR1        0xe00840b4
#define  RDIMMGCR1_CRINIT         GENMASK_32(31, 16)
#define  RDIMMGCR1_TBCMRD         GENMASK_32(14, 12)
#define  RDIMMGCR1_TBCSTAB        GENMASK_32(11, 0)

#define DDR_PHY_RDIMMCR0         0xe00840b8
#define  RDIMMCR0_RC7             GENMASK_32(31, 28)
#define  RDIMMCR0_RC6             GENMASK_32(27, 24)
#define  RDIMMCR0_RC5             GENMASK_32(23, 20)
#define  RDIMMCR0_RC4             GENMASK_32(19, 16)
#define  RDIMMCR0_RC3             GENMASK_32(15, 12)
#define  RDIMMCR0_RC2             GENMASK_32(11, 8)
#define  RDIMMCR0_RC1             GENMASK_32(7, 4)
#define  RDIMMCR0_RC0             GENMASK_32(3, 0)

#define DDR_PHY_RDIMMCR1         0xe00840bc
#define  RDIMMCR1_RC15            GENMASK_32(31, 28)
#define  RDIMMCR1_RC14            GENMASK_32(27, 24)
#define  RDIMMCR1_RC13            GENMASK_32(23, 20)
#define  RDIMMCR1_RC12            GENMASK_32(19, 16)
#define  RDIMMCR1_RC11            GENMASK_32(15, 12)
#define  RDIMMCR1_RC10            GENMASK_32(11, 8)
#define  RDIMMCR1_RC9             GENMASK_32(7, 4)
#define  RDIMMCR1_RC8             GENMASK_32(3, 0)

#define DDR_PHY_DCUAR            0xe00840c0
#define  DCUAR_ATYPE              BIT_32(11)
#define  DCUAR_INCA               BIT_32(10)
#define  DCUAR_CSEL               GENMASK_32(9, 8)
#define  DCUAR_CSADDR             GENMASK_32(7, 4)
#define  DCUAR_CWADDR             GENMASK_32(3, 0)

#define DDR_PHY_DCUDR            0xe00840c4
#define  DCUDR_CDATA              GENMASK_32(31, 0)

#define DDR_PHY_DCURR            0xe00840c8
#define  DCURR_XCEN               BIT_32(23)
#define  DCURR_RCEN               BIT_32(22)
#define  DCURR_SCOF               BIT_32(21)
#define  DCURR_SONF               BIT_32(20)
#define  DCURR_NFAIL              GENMASK_32(19, 12)
#define  DCURR_EADDR              GENMASK_32(11, 8)
#define  DCURR_SADDR              GENMASK_32(7, 4)
#define  DCURR_DINST              GENMASK_32(3, 0)

#define DDR_PHY_DCULR            0xe00840cc
#define  DCULR_XLEADDR            GENMASK_32(31, 28)
#define  DCULR_IDA                BIT_32(17)
#define  DCULR_LINF               BIT_32(16)
#define  DCULR_LCNT               GENMASK_32(15, 8)
#define  DCULR_LEADDR             GENMASK_32(7, 4)
#define  DCULR_LSADDR             GENMASK_32(3, 0)

#define DDR_PHY_DCUGCR           0xe00840d0
#define  DCUGCR_RCSW              GENMASK_32(15, 0)

#define DDR_PHY_DCUTPR           0xe00840d4
#define  DCUTPR_TDCUT3            GENMASK_32(31, 24)
#define  DCUTPR_TDCUT2            GENMASK_32(23, 16)
#define  DCUTPR_TDCUT1            GENMASK_32(15, 8)
#define  DCUTPR_TDCUT0            GENMASK_32(7, 0)

#define DDR_PHY_DCUSR0           0xe00840d8
#define  DCUSR0_CFULL             BIT_32(2)
#define  DCUSR0_CFAIL             BIT_32(1)
#define  DCUSR0_RDONE             BIT_32(0)

#define DDR_PHY_DCUSR1           0xe00840dc
#define  DCUSR1_LPCNT             GENMASK_32(31, 24)
#define  DCUSR1_FLCNT             GENMASK_32(23, 16)
#define  DCUSR1_RDCNT             GENMASK_32(15, 0)

#define DDR_PHY_BISTRR           0xe0084100
#define  BISTRR_BCCSEL            GENMASK_32(26, 25)
#define  BISTRR_BCKSEL            GENMASK_32(24, 23)
#define  BISTRR_BDXSEL            GENMASK_32(22, 19)
#define  BISTRR_BDPAT             GENMASK_32(18, 17)
#define  BISTRR_BDMEN             BIT_32(16)
#define  BISTRR_BACEN             BIT_32(15)
#define  BISTRR_BDXEN             BIT_32(14)
#define  BISTRR_BSONF             BIT_32(13)
#define  BISTRR_NFAIL             GENMASK_32(12, 5)
#define  BISTRR_BINF              BIT_32(4)
#define  BISTRR_BMODE             BIT_32(3)
#define  BISTRR_BINST             GENMASK_32(2, 0)

#define DDR_PHY_BISTWCR          0xe0084104
#define  BISTWCR_BWCNT            GENMASK_32(15, 0)

#define DDR_PHY_BISTMSKR0        0xe0084108
#define  BISTMSKR0_ODTMSK         GENMASK_32(31, 28)
#define  BISTMSKR0_CSMSK          GENMASK_32(27, 24)
#define  BISTMSKR0_CKEMSK         GENMASK_32(23, 20)
#define  BISTMSKR0_WEMSK          BIT_32(19)
#define  BISTMSKR0_BAMSK          GENMASK_32(18, 16)
#define  BISTMSKR0_AMSK           GENMASK_32(15, 0)

#define DDR_PHY_BISTMSKR1        0xe008410c
#define  BISTMSKR1_DMMSK          GENMASK_32(31, 28)
#define  BISTMSKR1_PARMSK         BIT_32(27)
#define  BISTMSKR1_CASMSK         BIT_32(1)
#define  BISTMSKR1_RASMSK         BIT_32(0)

#define DDR_PHY_BISTMSKR2        0xe0084110
#define  BISTMSKR2_DQMSK          GENMASK_32(31, 0)

#define DDR_PHY_BISTLSR          0xe0084114
#define  BISTLSR_SEED             GENMASK_32(31, 0)

#define DDR_PHY_BISTAR0          0xe0084118
#define  BISTAR0_BBANK            GENMASK_32(31, 28)
#define  BISTAR0_BROW             GENMASK_32(27, 12)
#define  BISTAR0_BCOL             GENMASK_32(11, 0)

#define DDR_PHY_BISTAR1          0xe008411c
#define  BISTAR1_BAINC            GENMASK_32(15, 4)
#define  BISTAR1_BMRANK           GENMASK_32(3, 2)
#define  BISTAR1_BRANK            GENMASK_32(1, 0)

#define DDR_PHY_BISTAR2          0xe0084120
#define  BISTAR2_BMBANK           GENMASK_32(30, 28)
#define  BISTAR2_BMROW            GENMASK_32(27, 12)
#define  BISTAR2_BMCOL            GENMASK_32(11, 0)

#define DDR_PHY_BISTUDPR         0xe0084124
#define  BISTUDPR_BUDP1           GENMASK_32(31, 16)
#define  BISTUDPR_BUDP0           GENMASK_32(15, 0)

#define DDR_PHY_BISTGSR          0xe0084128
#define  BISTGSR_CASBER           GENMASK_32(31, 30)
#define  BISTGSR_RASBER           GENMASK_32(29, 28)
#define  BISTGSR_DMBER            GENMASK_32(27, 20)
#define  BISTGSR_PARBER           GENMASK_32(17, 16)
#define  BISTGSR_BDXERR           BIT_32(2)
#define  BISTGSR_BACERR           BIT_32(1)
#define  BISTGSR_BDONE            BIT_32(0)

#define DDR_PHY_BISTWER          0xe008412c
#define  BISTWER_DXWER            GENMASK_32(31, 16)
#define  BISTWER_ACWER            GENMASK_32(15, 0)

#define DDR_PHY_BISTBER0         0xe0084130
#define  BISTBER0_ABER            GENMASK_32(31, 0)

#define DDR_PHY_BISTBER1         0xe0084134
#define  BISTBER1_ODTBER          GENMASK_32(31, 24)
#define  BISTBER1_CSBER           GENMASK_32(23, 16)
#define  BISTBER1_CKEBER          GENMASK_32(15, 8)
#define  BISTBER1_WEBER           GENMASK_32(7, 6)
#define  BISTBER1_BABER           GENMASK_32(5, 0)

#define DDR_PHY_BISTBER2         0xe0084138
#define  BISTBER2_DQBER0          GENMASK_32(31, 0)

#define DDR_PHY_BISTBER3         0xe008413c
#define  BISTBER3_DQBER1          GENMASK_32(31, 0)

#define DDR_PHY_BISTWCSR         0xe0084140
#define  BISTWCSR_DXWCNT          GENMASK_32(31, 16)
#define  BISTWCSR_ACWCNT          GENMASK_32(15, 0)

#define DDR_PHY_BISTFWR0         0xe0084144
#define  BISTFWR0_ODTWEBS         GENMASK_32(31, 28)
#define  BISTFWR0_CSWEBS          GENMASK_32(27, 24)
#define  BISTFWR0_CKEWEBS         GENMASK_32(23, 20)
#define  BISTFWR0_WEWEBS          BIT_32(19)
#define  BISTFWR0_BAWEBS          GENMASK_32(18, 16)
#define  BISTFWR0_AWEBS           GENMASK_32(15, 0)

#define DDR_PHY_BISTFWR1         0xe0084148
#define  BISTFWR1_DMWEBS          GENMASK_32(31, 28)
#define  BISTFWR1_PARWEBS         BIT_32(26)
#define  BISTFWR1_CASWEBS         BIT_32(1)
#define  BISTFWR1_RASWEBS         BIT_32(0)

#define DDR_PHY_BISTFWR2         0xe008414c
#define  BISTFWR2_DQWEBS          GENMASK_32(31, 0)

#define DDR_PHY_AACR             0xe0084174
#define  AACR_AAOENC              BIT_32(31)
#define  AACR_AAENC               BIT_32(30)
#define  AACR_AATR                GENMASK_32(29, 0)

#define DDR_PHY_ZQ0CR0           0xe0084180
#define  ZQ0CR0_ZQ0_ZQPD          BIT_32(31)
#define  ZQ0CR0_ZQ0_ZCALEN        BIT_32(30)
#define  ZQ0CR0_ZQ0_ZCALBYP       BIT_32(29)
#define  ZQ0CR0_ZQ0_ZDEN          BIT_32(28)
#define  ZQ0CR0_ZQ0_ZDATA         GENMASK_32(27, 0)

#define DDR_PHY_ZQ0CR1           0xe0084184
#define  ZQ0CR1_ZQ0_DFIPU1        BIT_32(17)
#define  ZQ0CR1_ZQ0_DFIPU0        BIT_32(16)
#define  ZQ0CR1_ZQ0_DFICCU        BIT_32(14)
#define  ZQ0CR1_ZQ0_DFICU1        BIT_32(13)
#define  ZQ0CR1_ZQ0_DFICU0        BIT_32(12)
#define  ZQ0CR1_ZQ0_ZPROG         GENMASK_32(7, 0)

#define DDR_PHY_ZQ0SR0           0xe0084188
#define  ZQ0SR0_ZQ0_ZDONE         BIT_32(31)
#define  ZQ0SR0_ZQ0_ZERR          BIT_32(30)
#define  ZQ0SR0_ZQ0_ZCTRL         GENMASK_32(27, 0)

#define DDR_PHY_ZQ0SR1           0xe008418c
#define  ZQ0SR1_ZQ0_OPU           GENMASK_32(7, 6)
#define  ZQ0SR1_ZQ0_OPD           GENMASK_32(5, 4)
#define  ZQ0SR1_ZQ0_ZPU           GENMASK_32(3, 2)
#define  ZQ0SR1_ZQ0_ZPD           GENMASK_32(1, 0)

#define DDR_PHY_ZQ1CR0           0xe0084190
#define  ZQ1CR0_ZQ1_ZQPD          BIT_32(31)
#define  ZQ1CR0_ZQ1_ZCALEN        BIT_32(30)
#define  ZQ1CR0_ZQ1_ZCALBYP       BIT_32(29)
#define  ZQ1CR0_ZQ1_ZDEN          BIT_32(28)
#define  ZQ1CR0_ZQ1_ZDATA         GENMASK_32(27, 0)

#define DDR_PHY_ZQ1CR1           0xe0084194
#define  ZQ1CR1_ZQ1_DFIPU1        BIT_32(17)
#define  ZQ1CR1_ZQ1_DFIPU0        BIT_32(16)
#define  ZQ1CR1_ZQ1_DFICCU        BIT_32(14)
#define  ZQ1CR1_ZQ1_DFICU1        BIT_32(13)
#define  ZQ1CR1_ZQ1_DFICU0        BIT_32(12)
#define  ZQ1CR1_ZQ1_ZPROG         GENMASK_32(7, 0)

#define DDR_PHY_ZQ1SR0           0xe0084198
#define  ZQ1SR0_ZQ1_ZDONE         BIT_32(31)
#define  ZQ1SR0_ZQ1_ZERR          BIT_32(30)
#define  ZQ1SR0_ZQ1_ZCTRL         GENMASK_32(27, 0)

#define DDR_PHY_ZQ1SR1           0xe008419c
#define  ZQ1SR1_ZQ1_OPU           GENMASK_32(7, 6)
#define  ZQ1SR1_ZQ1_OPD           GENMASK_32(5, 4)
#define  ZQ1SR1_ZQ1_ZPU           GENMASK_32(3, 2)
#define  ZQ1SR1_ZQ1_ZPD           GENMASK_32(1, 0)

#define DDR_PHY_DX0GCR           0xe00841c0
#define  DX0GCR_DX0_CALBYP        BIT_32(31)
#define  DX0GCR_DX0_MDLEN         BIT_32(30)
#define  DX0GCR_DX0_WLRKEN        GENMASK_32(29, 26)
#define  DX0GCR_DX0_PLLBYP        BIT_32(19)
#define  DX0GCR_DX0_GSHIFT        BIT_32(18)
#define  DX0GCR_DX0_PLLPD         BIT_32(17)
#define  DX0GCR_DX0_PLLRST        BIT_32(16)
#define  DX0GCR_DX0_DXOEO         GENMASK_32(15, 14)
#define  DX0GCR_DX0_RTTOAL        BIT_32(13)
#define  DX0GCR_DX0_RTTOH         GENMASK_32(12, 11)
#define  DX0GCR_DX0_DQRTT         BIT_32(10)
#define  DX0GCR_DX0_DQSRTT        BIT_32(9)
#define  DX0GCR_DX0_DSEN          GENMASK_32(8, 7)
#define  DX0GCR_DX0_DQSRPD        BIT_32(6)
#define  DX0GCR_DX0_DXPDR         BIT_32(5)
#define  DX0GCR_DX0_DXPDD         BIT_32(4)
#define  DX0GCR_DX0_DXIOM         BIT_32(3)
#define  DX0GCR_DX0_DQODT         BIT_32(2)
#define  DX0GCR_DX0_DQSODT        BIT_32(1)
#define  DX0GCR_DX0_DXEN          BIT_32(0)

#define DDR_PHY_DX0GSR0          0xe00841c4
#define  DX0GSR0_DX0_WLDQ         BIT_32(28)
#define  DX0GSR0_DX0_QSGERR       GENMASK_32(27, 24)
#define  DX0GSR0_DX0_GDQSPRD      GENMASK_32(23, 16)
#define  DX0GSR0_DX0_DPLOCK       BIT_32(15)
#define  DX0GSR0_DX0_WLPRD        GENMASK_32(14, 7)
#define  DX0GSR0_DX0_WLERR        BIT_32(6)
#define  DX0GSR0_DX0_WLDONE       BIT_32(5)
#define  DX0GSR0_DX0_WLCAL        BIT_32(4)
#define  DX0GSR0_DX0_GDQSCAL      BIT_32(3)
#define  DX0GSR0_DX0_RDQSCAL      BIT_32(1)
#define  DX0GSR0_DX0_WDQCAL       BIT_32(0)

#define DDR_PHY_DX0GSR1          0xe00841c8
#define  DX0GSR1_DX0_DLTCODE      GENMASK_32(24, 1)
#define  DX0GSR1_DX0_DLTDONE      BIT_32(0)

#define DDR_PHY_DX0BDLR0         0xe00841cc
#define  DX0BDLR0_DX0_DQ4WBD      GENMASK_32(29, 24)
#define  DX0BDLR0_DX0_DQ3WBD      GENMASK_32(23, 18)
#define  DX0BDLR0_DX0_DQ2WBD      GENMASK_32(17, 12)
#define  DX0BDLR0_DX0_DQ1WBD      GENMASK_32(11, 6)
#define  DX0BDLR0_DX0_DQ0WBD      GENMASK_32(5, 0)

#define DDR_PHY_DX0BDLR1         0xe00841d0
#define  DX0BDLR1_DX0_DSWBD       GENMASK_32(29, 24)
#define  DX0BDLR1_DX0_DMWBD       GENMASK_32(23, 18)
#define  DX0BDLR1_DX0_DQ7WBD      GENMASK_32(17, 12)
#define  DX0BDLR1_DX0_DQ6WBD      GENMASK_32(11, 6)
#define  DX0BDLR1_DX0_DQ5WBD      GENMASK_32(5, 0)

#define DDR_PHY_DX0BDLR2         0xe00841d4
#define  DX0BDLR2_DX0_DSRBD       GENMASK_32(17, 12)
#define  DX0BDLR2_DX0_DQOEBD      GENMASK_32(11, 6)
#define  DX0BDLR2_DX0_DSOEBD      GENMASK_32(5, 0)

#define DDR_PHY_DX0BDLR3         0xe00841d8
#define  DX0BDLR3_DX0_DQ4RBD      GENMASK_32(29, 24)
#define  DX0BDLR3_DX0_DQ3RBD      GENMASK_32(23, 18)
#define  DX0BDLR3_DX0_DQ2RBD      GENMASK_32(17, 12)
#define  DX0BDLR3_DX0_DQ1RBD      GENMASK_32(11, 6)
#define  DX0BDLR3_DX0_DQ0RBD      GENMASK_32(5, 0)

#define DDR_PHY_DX0BDLR4         0xe00841dc
#define  DX0BDLR4_DX0_DMRBD       GENMASK_32(23, 18)
#define  DX0BDLR4_DX0_DQ7RBD      GENMASK_32(17, 12)
#define  DX0BDLR4_DX0_DQ6RBD      GENMASK_32(11, 6)
#define  DX0BDLR4_DX0_DQ5RBD      GENMASK_32(5, 0)

#define DDR_PHY_DX0LCDLR0        0xe00841e0
#define  DX0LCDLR0_DX0_R3WLD      GENMASK_32(31, 24)
#define  DX0LCDLR0_DX0_R2WLD      GENMASK_32(23, 16)
#define  DX0LCDLR0_DX0_R1WLD      GENMASK_32(15, 8)
#define  DX0LCDLR0_DX0_R0WLD      GENMASK_32(7, 0)

#define DDR_PHY_DX0LCDLR1        0xe00841e4
#define  DX0LCDLR1_DX0_RDQSD      GENMASK_32(15, 8)
#define  DX0LCDLR1_DX0_WDQD       GENMASK_32(7, 0)

#define DDR_PHY_DX0LCDLR2        0xe00841e8
#define  DX0LCDLR2_DX0_R3DQSGD    GENMASK_32(31, 24)
#define  DX0LCDLR2_DX0_R2DQSGD    GENMASK_32(23, 16)
#define  DX0LCDLR2_DX0_R1DQSGD    GENMASK_32(15, 8)
#define  DX0LCDLR2_DX0_R0DQSGD    GENMASK_32(7, 0)

#define DDR_PHY_DX0MDLR          0xe00841ec
#define  DX0MDLR_DX0_MDLD         GENMASK_32(23, 16)
#define  DX0MDLR_DX0_TPRD         GENMASK_32(15, 8)
#define  DX0MDLR_DX0_IPRD         GENMASK_32(7, 0)

#define DDR_PHY_DX0GTR           0xe00841f0
#define  DX0GTR_DX0_WLSL          GENMASK_32(19, 12)
#define  DX0GTR_DX0_DGSL          GENMASK_32(11, 0)

#define DDR_PHY_DX0GSR2          0xe00841f4
#define  DX0GSR2_DX0_ESTAT        GENMASK_32(11, 8)
#define  DX0GSR2_DX0_WEWN         BIT_32(7)
#define  DX0GSR2_DX0_WEERR        BIT_32(6)
#define  DX0GSR2_DX0_REWN         BIT_32(5)
#define  DX0GSR2_DX0_REERR        BIT_32(4)
#define  DX0GSR2_DX0_WDWN         BIT_32(3)
#define  DX0GSR2_DX0_WDERR        BIT_32(2)
#define  DX0GSR2_DX0_RDWN         BIT_32(1)
#define  DX0GSR2_DX0_RDERR        BIT_32(0)

#define DDR_PHY_DX1GCR           0xe0084200
#define  DX1GCR_DX1_CALBYP        BIT_32(31)
#define  DX1GCR_DX1_MDLEN         BIT_32(30)
#define  DX1GCR_DX1_WLRKEN        GENMASK_32(29, 26)
#define  DX1GCR_DX1_PLLBYP        BIT_32(19)
#define  DX1GCR_DX1_GSHIFT        BIT_32(18)
#define  DX1GCR_DX1_PLLPD         BIT_32(17)
#define  DX1GCR_DX1_PLLRST        BIT_32(16)
#define  DX1GCR_DX1_DXOEO         GENMASK_32(15, 14)
#define  DX1GCR_DX1_RTTOAL        BIT_32(13)
#define  DX1GCR_DX1_RTTOH         GENMASK_32(12, 11)
#define  DX1GCR_DX1_DQRTT         BIT_32(10)
#define  DX1GCR_DX1_DQSRTT        BIT_32(9)
#define  DX1GCR_DX1_DSEN          GENMASK_32(8, 7)
#define  DX1GCR_DX1_DQSRPD        BIT_32(6)
#define  DX1GCR_DX1_DXPDR         BIT_32(5)
#define  DX1GCR_DX1_DXPDD         BIT_32(4)
#define  DX1GCR_DX1_DXIOM         BIT_32(3)
#define  DX1GCR_DX1_DQODT         BIT_32(2)
#define  DX1GCR_DX1_DQSODT        BIT_32(1)
#define  DX1GCR_DX1_DXEN          BIT_32(0)

#define DDR_PHY_DX1GSR0          0xe0084204
#define  DX1GSR0_DX1_WLDQ         BIT_32(28)
#define  DX1GSR0_DX1_QSGERR       GENMASK_32(27, 24)
#define  DX1GSR0_DX1_GDQSPRD      GENMASK_32(23, 16)
#define  DX1GSR0_DX1_DPLOCK       BIT_32(15)
#define  DX1GSR0_DX1_WLPRD        GENMASK_32(14, 7)
#define  DX1GSR0_DX1_WLERR        BIT_32(6)
#define  DX1GSR0_DX1_WLDONE       BIT_32(5)
#define  DX1GSR0_DX1_WLCAL        BIT_32(4)
#define  DX1GSR0_DX1_GDQSCAL      BIT_32(3)
#define  DX1GSR0_DX1_RDQSCAL      BIT_32(1)
#define  DX1GSR0_DX1_WDQCAL       BIT_32(0)

#define DDR_PHY_DX1GSR1          0xe0084208
#define  DX1GSR1_DX1_DLTCODE      GENMASK_32(24, 1)
#define  DX1GSR1_DX1_DLTDONE      BIT_32(0)

#define DDR_PHY_DX1BDLR0         0xe008420c
#define  DX1BDLR0_DX1_DQ4WBD      GENMASK_32(29, 24)
#define  DX1BDLR0_DX1_DQ3WBD      GENMASK_32(23, 18)
#define  DX1BDLR0_DX1_DQ2WBD      GENMASK_32(17, 12)
#define  DX1BDLR0_DX1_DQ1WBD      GENMASK_32(11, 6)
#define  DX1BDLR0_DX1_DQ0WBD      GENMASK_32(5, 0)

#define DDR_PHY_DX1BDLR1         0xe0084210
#define  DX1BDLR1_DX1_DSWBD       GENMASK_32(29, 24)
#define  DX1BDLR1_DX1_DMWBD       GENMASK_32(23, 18)
#define  DX1BDLR1_DX1_DQ7WBD      GENMASK_32(17, 12)
#define  DX1BDLR1_DX1_DQ6WBD      GENMASK_32(11, 6)
#define  DX1BDLR1_DX1_DQ5WBD      GENMASK_32(5, 0)

#define DDR_PHY_DX1BDLR2         0xe0084214
#define  DX1BDLR2_DX1_DSRBD       GENMASK_32(17, 12)
#define  DX1BDLR2_DX1_DQOEBD      GENMASK_32(11, 6)
#define  DX1BDLR2_DX1_DSOEBD      GENMASK_32(5, 0)

#define DDR_PHY_DX1BDLR3         0xe0084218
#define  DX1BDLR3_DX1_DQ4RBD      GENMASK_32(29, 24)
#define  DX1BDLR3_DX1_DQ3RBD      GENMASK_32(23, 18)
#define  DX1BDLR3_DX1_DQ2RBD      GENMASK_32(17, 12)
#define  DX1BDLR3_DX1_DQ1RBD      GENMASK_32(11, 6)
#define  DX1BDLR3_DX1_DQ0RBD      GENMASK_32(5, 0)

#define DDR_PHY_DX1BDLR4         0xe008421c
#define  DX1BDLR4_DX1_DMRBD       GENMASK_32(23, 18)
#define  DX1BDLR4_DX1_DQ7RBD      GENMASK_32(17, 12)
#define  DX1BDLR4_DX1_DQ6RBD      GENMASK_32(11, 6)
#define  DX1BDLR4_DX1_DQ5RBD      GENMASK_32(5, 0)

#define DDR_PHY_DX1LCDLR0        0xe0084220
#define  DX1LCDLR0_DX1_R3WLD      GENMASK_32(31, 24)
#define  DX1LCDLR0_DX1_R2WLD      GENMASK_32(23, 16)
#define  DX1LCDLR0_DX1_R1WLD      GENMASK_32(15, 8)
#define  DX1LCDLR0_DX1_R0WLD      GENMASK_32(7, 0)

#define DDR_PHY_DX1LCDLR1        0xe0084224
#define  DX1LCDLR1_DX1_RDQSD      GENMASK_32(15, 8)
#define  DX1LCDLR1_DX1_WDQD       GENMASK_32(7, 0)

#define DDR_PHY_DX1LCDLR2        0xe0084228
#define  DX1LCDLR2_DX1_R3DQSGD    GENMASK_32(31, 24)
#define  DX1LCDLR2_DX1_R2DQSGD    GENMASK_32(23, 16)
#define  DX1LCDLR2_DX1_R1DQSGD    GENMASK_32(15, 8)
#define  DX1LCDLR2_DX1_R0DQSGD    GENMASK_32(7, 0)

#define DDR_PHY_DX1MDLR          0xe008422c
#define  DX1MDLR_DX1_MDLD         GENMASK_32(23, 16)
#define  DX1MDLR_DX1_TPRD         GENMASK_32(15, 8)
#define  DX1MDLR_DX1_IPRD         GENMASK_32(7, 0)

#define DDR_PHY_DX1GTR           0xe0084230
#define  DX1GTR_DX1_WLSL          GENMASK_32(19, 12)
#define  DX1GTR_DX1_DGSL          GENMASK_32(11, 0)

#define DDR_PHY_DX1GSR2          0xe0084234
#define  DX1GSR2_DX1_ESTAT        GENMASK_32(11, 8)
#define  DX1GSR2_DX1_WEWN         BIT_32(7)
#define  DX1GSR2_DX1_WEERR        BIT_32(6)
#define  DX1GSR2_DX1_REWN         BIT_32(5)
#define  DX1GSR2_DX1_REERR        BIT_32(4)
#define  DX1GSR2_DX1_WDWN         BIT_32(3)
#define  DX1GSR2_DX1_WDERR        BIT_32(2)
#define  DX1GSR2_DX1_RDWN         BIT_32(1)
#define  DX1GSR2_DX1_RDERR        BIT_32(0)

#define DDR_UMCTL2_MSTR          0xe0080000
#define  MSTR_ACTIVE_RANKS        GENMASK_32(25, 24)
#define  MSTR_BURST_RDWR          GENMASK_32(19, 16)
#define  MSTR_DLL_OFF_MODE        BIT_32(15)
#define  MSTR_DATA_BUS_WIDTH      GENMASK_32(13, 12)
#define  MSTR_EN_2T_TIMING_MODE   BIT_32(10)
#define  MSTR_BURSTCHOP           BIT_32(9)
#define  MSTR_DDR3                BIT_32(0)

#define DDR_UMCTL2_STAT          0xe0080004
#define  STAT_SELFREF_CAM_NOT_EMPTY BIT_32(12)
#define  STAT_SELFREF_TYPE        GENMASK_32(5, 4)
#define  STAT_OPERATING_MODE      GENMASK_32(1, 0)

#define DDR_UMCTL2_MRCTRL0       0xe0080010
#define  MRCTRL0_MR_WR            BIT_32(31)
#define  MRCTRL0_MR_ADDR          GENMASK_32(15, 12)
#define  MRCTRL0_MR_RANK          GENMASK_32(5, 4)

#define DDR_UMCTL2_MRCTRL1       0xe0080014
#define  MRCTRL1_MR_DATA          GENMASK_32(15, 0)

#define DDR_UMCTL2_MRSTAT        0xe0080018
#define  MRSTAT_MR_WR_BUSY        BIT_32(0)

#define DDR_UMCTL2_PWRCTL        0xe0080030
#define  PWRCTL_DIS_CAM_DRAIN_SELFREF BIT_32(7)
#define  PWRCTL_SELFREF_SW        BIT_32(5)
#define  PWRCTL_EN_DFI_DRAM_CLK_DISABLE BIT_32(3)
#define  PWRCTL_POWERDOWN_EN      BIT_32(1)
#define  PWRCTL_SELFREF_EN        BIT_32(0)

#define DDR_UMCTL2_PWRTMG        0xe0080034
#define  PWRTMG_SELFREF_TO_X32    GENMASK_32(23, 16)
#define  PWRTMG_POWERDOWN_TO_X32  GENMASK_32(4, 0)

#define DDR_UMCTL2_HWLPCTL       0xe0080038
#define  HWLPCTL_HW_LP_IDLE_X32   GENMASK_32(27, 16)
#define  HWLPCTL_HW_LP_EXIT_IDLE_EN BIT_32(1)
#define  HWLPCTL_HW_LP_EN         BIT_32(0)

#define DDR_UMCTL2_RFSHCTL0      0xe0080050
#define  RFSHCTL0_REFRESH_MARGIN  GENMASK_32(23, 20)
#define  RFSHCTL0_REFRESH_TO_X1_X32 GENMASK_32(16, 12)
#define  RFSHCTL0_REFRESH_BURST   GENMASK_32(9, 4)

#define DDR_UMCTL2_RFSHCTL1      0xe0080054
#define  RFSHCTL1_REFRESH_TIMER1_START_VALUE_X32 GENMASK_32(27, 16)
#define  RFSHCTL1_REFRESH_TIMER0_START_VALUE_X32 GENMASK_32(11, 0)

#define DDR_UMCTL2_RFSHCTL3      0xe0080060
#define  RFSHCTL3_REFRESH_UPDATE_LEVEL BIT_32(1)
#define  RFSHCTL3_DIS_AUTO_REFRESH BIT_32(0)

#define DDR_UMCTL2_RFSHTMG       0xe0080064
#define  RFSHTMG_T_RFC_NOM_X1_X32 GENMASK_32(27, 16)
#define  RFSHTMG_T_RFC_MIN        GENMASK_32(9, 0)

#define DDR_UMCTL2_ECCCFG0       0xe0080070
#define  ECCCFG0_ECC_REGION_MAP_GRANU GENMASK_32(31, 30)
#define  ECCCFG0_ECC_REGION_MAP_OTHER BIT_32(29)
#define  ECCCFG0_ECC_AP_ERR_THRESHOLD BIT_32(24)
#define  ECCCFG0_BLK_CHANNEL_IDLE_TIME_X32 GENMASK_32(21, 16)
#define  ECCCFG0_ECC_REGION_MAP   GENMASK_32(14, 8)
#define  ECCCFG0_ECC_REGION_REMAP_EN BIT_32(7)
#define  ECCCFG0_ECC_AP_EN        BIT_32(6)
#define  ECCCFG0_DIS_SCRUB        BIT_32(4)
#define  ECCCFG0_ECC_MODE         GENMASK_32(2, 0)

#define DDR_UMCTL2_ECCCFG1       0xe0080074
#define  ECCCFG1_ACTIVE_BLK_CHANNEL GENMASK_32(12, 8)
#define  ECCCFG1_BLK_CHANNEL_ACTIVE_TERM BIT_32(7)
#define  ECCCFG1_ECC_REGION_WASTE_LOCK BIT_32(5)
#define  ECCCFG1_ECC_REGION_PARITY_LOCK BIT_32(4)
#define  ECCCFG1_DATA_POISON_BIT  BIT_32(1)
#define  ECCCFG1_DATA_POISON_EN   BIT_32(0)

#define DDR_UMCTL2_ECCSTAT       0xe0080078
#define  ECCSTAT_ECC_UNCORRECTED_ERR BIT_32(16)
#define  ECCSTAT_ECC_CORRECTED_ERR BIT_32(8)
#define  ECCSTAT_ECC_CORRECTED_BIT_NUM GENMASK_32(6, 0)

#define DDR_UMCTL2_ECCCTL        0xe008007c
#define  ECCCTL_ECC_AP_ERR_INTR_FORCE BIT_32(18)
#define  ECCCTL_ECC_UNCORRECTED_ERR_INTR_FORCE BIT_32(17)
#define  ECCCTL_ECC_CORRECTED_ERR_INTR_FORCE BIT_32(16)
#define  ECCCTL_ECC_AP_ERR_INTR_EN BIT_32(10)
#define  ECCCTL_ECC_UNCORRECTED_ERR_INTR_EN BIT_32(9)
#define  ECCCTL_ECC_CORRECTED_ERR_INTR_EN BIT_32(8)
#define  ECCCTL_ECC_AP_ERR_INTR_CLR BIT_32(4)
#define  ECCCTL_ECC_UNCORR_ERR_CNT_CLR BIT_32(3)
#define  ECCCTL_ECC_CORR_ERR_CNT_CLR BIT_32(2)
#define  ECCCTL_ECC_UNCORRECTED_ERR_CLR BIT_32(1)
#define  ECCCTL_ECC_CORRECTED_ERR_CLR BIT_32(0)

#define DDR_UMCTL2_ECCERRCNT     0xe0080080
#define  ECCERRCNT_ECC_UNCORR_ERR_CNT GENMASK_32(31, 16)
#define  ECCERRCNT_ECC_CORR_ERR_CNT GENMASK_32(15, 0)

#define DDR_UMCTL2_ECCCADDR0     0xe0080084
#define  ECCCADDR0_ECC_CORR_RANK  BIT_32(24)
#define  ECCCADDR0_ECC_CORR_ROW   GENMASK_32(15, 0)

#define DDR_UMCTL2_ECCCADDR1     0xe0080088
#define  ECCCADDR1_ECC_CORR_BANK  GENMASK_32(18, 16)
#define  ECCCADDR1_ECC_CORR_COL   GENMASK_32(11, 0)

#define DDR_UMCTL2_ECCCSYN0      0xe008008c
#define  ECCCSYN0_ECC_CORR_SYNDROMES_31_0 GENMASK_32(31, 0)

#define DDR_UMCTL2_ECCCSYN1      0xe0080090
#define  ECCCSYN1_ECC_CORR_SYNDROMES_63_32 GENMASK_32(31, 0)

#define DDR_UMCTL2_ECCCSYN2      0xe0080094
#define  ECCCSYN2_ECC_CORR_SYNDROMES_71_64 GENMASK_32(7, 0)

#define DDR_UMCTL2_ECCBITMASK0   0xe0080098
#define  ECCBITMASK0_ECC_CORR_BIT_MASK_31_0 GENMASK_32(31, 0)

#define DDR_UMCTL2_ECCBITMASK1   0xe008009c
#define  ECCBITMASK1_ECC_CORR_BIT_MASK_63_32 GENMASK_32(31, 0)

#define DDR_UMCTL2_ECCBITMASK2   0xe00800a0
#define  ECCBITMASK2_ECC_CORR_BIT_MASK_71_64 GENMASK_32(7, 0)

#define DDR_UMCTL2_ECCUADDR0     0xe00800a4
#define  ECCUADDR0_ECC_UNCORR_RANK BIT_32(24)
#define  ECCUADDR0_ECC_UNCORR_ROW GENMASK_32(15, 0)

#define DDR_UMCTL2_ECCUADDR1     0xe00800a8
#define  ECCUADDR1_ECC_UNCORR_BANK GENMASK_32(18, 16)
#define  ECCUADDR1_ECC_UNCORR_COL GENMASK_32(11, 0)

#define DDR_UMCTL2_ECCUSYN0      0xe00800ac
#define  ECCUSYN0_ECC_UNCORR_SYNDROMES_31_0 GENMASK_32(31, 0)

#define DDR_UMCTL2_ECCUSYN1      0xe00800b0
#define  ECCUSYN1_ECC_UNCORR_SYNDROMES_63_32 GENMASK_32(31, 0)

#define DDR_UMCTL2_ECCUSYN2      0xe00800b4
#define  ECCUSYN2_ECC_UNCORR_SYNDROMES_71_64 GENMASK_32(7, 0)

#define DDR_UMCTL2_ECCPOISONADDR0 0xe00800b8
#define  ECCPOISONADDR0_ECC_POISON_RANK BIT_32(24)
#define  ECCPOISONADDR0_ECC_POISON_COL GENMASK_32(11, 0)

#define DDR_UMCTL2_ECCPOISONADDR1 0xe00800bc
#define  ECCPOISONADDR1_ECC_POISON_BANK GENMASK_32(26, 24)
#define  ECCPOISONADDR1_ECC_POISON_ROW GENMASK_32(15, 0)

#define DDR_UMCTL2_CRCPARCTL0    0xe00800c0
#define  CRCPARCTL0_DFI_ALERT_ERR_CNT_CLR BIT_32(2)
#define  CRCPARCTL0_DFI_ALERT_ERR_INT_CLR BIT_32(1)
#define  CRCPARCTL0_DFI_ALERT_ERR_INT_EN BIT_32(0)

#define DDR_UMCTL2_CRCPARSTAT    0xe00800cc
#define  CRCPARSTAT_DFI_ALERT_ERR_INT BIT_32(16)
#define  CRCPARSTAT_DFI_ALERT_ERR_CNT GENMASK_32(15, 0)

#define DDR_UMCTL2_INIT0         0xe00800d0
#define  INIT0_SKIP_DRAM_INIT     GENMASK_32(31, 30)
#define  INIT0_POST_CKE_X1024     GENMASK_32(25, 16)
#define  INIT0_PRE_CKE_X1024      GENMASK_32(11, 0)

#define DDR_UMCTL2_INIT1         0xe00800d4
#define  INIT1_DRAM_RSTN_X1024    GENMASK_32(24, 16)
#define  INIT1_PRE_OCD_X32        GENMASK_32(3, 0)

#define DDR_UMCTL2_INIT3         0xe00800dc
#define  INIT3_MR                 GENMASK_32(31, 16)
#define  INIT3_EMR                GENMASK_32(15, 0)

#define DDR_UMCTL2_INIT4         0xe00800e0
#define  INIT4_EMR2               GENMASK_32(31, 16)
#define  INIT4_EMR3               GENMASK_32(15, 0)

#define DDR_UMCTL2_INIT5         0xe00800e4
#define  INIT5_DEV_ZQINIT_X32     GENMASK_32(23, 16)

#define DDR_UMCTL2_DIMMCTL       0xe00800f0
#define  DIMMCTL_DIMM_ADDR_MIRR_EN BIT_32(1)
#define  DIMMCTL_DIMM_STAGGER_CS_EN BIT_32(0)

#define DDR_UMCTL2_RANKCTL       0xe00800f4
#define  RANKCTL_DIFF_RANK_WR_GAP_MSB BIT_32(26)
#define  RANKCTL_DIFF_RANK_RD_GAP_MSB BIT_32(24)
#define  RANKCTL_MAX_RANK_WR      GENMASK_32(15, 12)
#define  RANKCTL_DIFF_RANK_WR_GAP GENMASK_32(11, 8)
#define  RANKCTL_DIFF_RANK_RD_GAP GENMASK_32(7, 4)
#define  RANKCTL_MAX_RANK_RD      GENMASK_32(3, 0)

#define DDR_UMCTL2_DRAMTMG0      0xe0080100
#define  DRAMTMG0_WR2PRE          GENMASK_32(30, 24)
#define  DRAMTMG0_T_FAW           GENMASK_32(21, 16)
#define  DRAMTMG0_T_RAS_MAX       GENMASK_32(14, 8)
#define  DRAMTMG0_T_RAS_MIN       GENMASK_32(5, 0)

#define DDR_UMCTL2_DRAMTMG1      0xe0080104
#define  DRAMTMG1_T_XP            GENMASK_32(20, 16)
#define  DRAMTMG1_RD2PRE          GENMASK_32(13, 8)
#define  DRAMTMG1_T_RC            GENMASK_32(6, 0)

#define DDR_UMCTL2_DRAMTMG2      0xe0080108
#define  DRAMTMG2_RD2WR           GENMASK_32(13, 8)
#define  DRAMTMG2_WR2RD           GENMASK_32(5, 0)

#define DDR_UMCTL2_DRAMTMG3      0xe008010c
#define  DRAMTMG3_T_MRD           GENMASK_32(17, 12)
#define  DRAMTMG3_T_MOD           GENMASK_32(9, 0)

#define DDR_UMCTL2_DRAMTMG4      0xe0080110
#define  DRAMTMG4_T_RCD           GENMASK_32(28, 24)
#define  DRAMTMG4_T_CCD           GENMASK_32(19, 16)
#define  DRAMTMG4_T_RRD           GENMASK_32(11, 8)
#define  DRAMTMG4_T_RP            GENMASK_32(4, 0)

#define DDR_UMCTL2_DRAMTMG5      0xe0080114
#define  DRAMTMG5_T_CKSRX         GENMASK_32(27, 24)
#define  DRAMTMG5_T_CKSRE         GENMASK_32(22, 16)
#define  DRAMTMG5_T_CKESR         GENMASK_32(13, 8)
#define  DRAMTMG5_T_CKE           GENMASK_32(4, 0)

#define DDR_UMCTL2_DRAMTMG8      0xe0080120
#define  DRAMTMG8_T_XS_DLL_X32    GENMASK_32(14, 8)
#define  DRAMTMG8_T_XS_X32        GENMASK_32(6, 0)

#define DDR_UMCTL2_DRAMTMG15     0xe008013c
#define  DRAMTMG15_EN_DFI_LP_T_STAB BIT_32(31)
#define  DRAMTMG15_T_STAB_X32     GENMASK_32(7, 0)

#define DDR_UMCTL2_ZQCTL0        0xe0080180
#define  ZQCTL0_DIS_AUTO_ZQ       BIT_32(31)
#define  ZQCTL0_DIS_SRX_ZQCL      BIT_32(30)
#define  ZQCTL0_ZQ_RESISTOR_SHARED BIT_32(29)
#define  ZQCTL0_T_ZQ_LONG_NOP     GENMASK_32(26, 16)
#define  ZQCTL0_T_ZQ_SHORT_NOP    GENMASK_32(9, 0)

#define DDR_UMCTL2_ZQCTL1        0xe0080184
#define  ZQCTL1_T_ZQ_SHORT_INTERVAL_X1024 GENMASK_32(19, 0)

#define DDR_UMCTL2_DFITMG0       0xe0080190
#define  DFITMG0_DFI_T_CTRL_DELAY GENMASK_32(28, 24)
#define  DFITMG0_DFI_RDDATA_USE_DFI_PHY_CLK BIT_32(23)
#define  DFITMG0_DFI_T_RDDATA_EN  GENMASK_32(22, 16)
#define  DFITMG0_DFI_WRDATA_USE_DFI_PHY_CLK BIT_32(15)
#define  DFITMG0_DFI_TPHY_WRDATA  GENMASK_32(13, 8)
#define  DFITMG0_DFI_TPHY_WRLAT   GENMASK_32(5, 0)

#define DDR_UMCTL2_DFITMG1       0xe0080194
#define  DFITMG1_DFI_T_PARIN_LAT  GENMASK_32(25, 24)
#define  DFITMG1_DFI_T_WRDATA_DELAY GENMASK_32(20, 16)
#define  DFITMG1_DFI_T_DRAM_CLK_DISABLE GENMASK_32(12, 8)
#define  DFITMG1_DFI_T_DRAM_CLK_ENABLE GENMASK_32(4, 0)

#define DDR_UMCTL2_DFILPCFG0     0xe0080198
#define  DFILPCFG0_DFI_TLP_RESP   GENMASK_32(28, 24)
#define  DFILPCFG0_DFI_LP_WAKEUP_SR GENMASK_32(15, 12)
#define  DFILPCFG0_DFI_LP_EN_SR   BIT_32(8)
#define  DFILPCFG0_DFI_LP_WAKEUP_PD GENMASK_32(7, 4)
#define  DFILPCFG0_DFI_LP_EN_PD   BIT_32(0)

#define DDR_UMCTL2_DFIUPD0       0xe00801a0
#define  DFIUPD0_DIS_AUTO_CTRLUPD BIT_32(31)
#define  DFIUPD0_DIS_AUTO_CTRLUPD_SRX BIT_32(30)
#define  DFIUPD0_CTRLUPD_PRE_SRX  BIT_32(29)
#define  DFIUPD0_DFI_T_CTRLUP_MAX GENMASK_32(25, 16)
#define  DFIUPD0_DFI_T_CTRLUP_MIN GENMASK_32(9, 0)

#define DDR_UMCTL2_DFIUPD1       0xe00801a4
#define  DFIUPD1_DFI_T_CTRLUPD_INTERVAL_MIN_X1024 GENMASK_32(23, 16)
#define  DFIUPD1_DFI_T_CTRLUPD_INTERVAL_MAX_X1024 GENMASK_32(7, 0)

#define DDR_UMCTL2_DFIUPD2       0xe00801a8
#define  DFIUPD2_DFI_PHYUPD_EN    BIT_32(31)

#define DDR_UMCTL2_DFIMISC       0xe00801b0
#define  DFIMISC_DFI_FREQUENCY    GENMASK_32(12, 8)
#define  DFIMISC_DFI_INIT_START   BIT_32(5)
#define  DFIMISC_CTL_IDLE_EN      BIT_32(4)
#define  DFIMISC_DFI_INIT_COMPLETE_EN BIT_32(0)

#define DDR_UMCTL2_DFISTAT       0xe00801bc
#define  DFISTAT_DFI_LP_ACK       BIT_32(1)
#define  DFISTAT_DFI_INIT_COMPLETE BIT_32(0)

#define DDR_UMCTL2_DFIPHYMSTR    0xe00801c4
#define  DFIPHYMSTR_DFI_PHYMSTR_BLK_REF_X32 GENMASK_32(31, 24)
#define  DFIPHYMSTR_DFI_PHYMSTR_EN BIT_32(0)

#define DDR_UMCTL2_ADDRMAP0      0xe0080200
#define  ADDRMAP0_ADDRMAP_CS_BIT0 GENMASK_32(4, 0)

#define DDR_UMCTL2_ADDRMAP1      0xe0080204
#define  ADDRMAP1_ADDRMAP_BANK_B2 GENMASK_32(21, 16)
#define  ADDRMAP1_ADDRMAP_BANK_B1 GENMASK_32(13, 8)
#define  ADDRMAP1_ADDRMAP_BANK_B0 GENMASK_32(5, 0)

#define DDR_UMCTL2_ADDRMAP2      0xe0080208
#define  ADDRMAP2_ADDRMAP_COL_B5  GENMASK_32(27, 24)
#define  ADDRMAP2_ADDRMAP_COL_B4  GENMASK_32(19, 16)
#define  ADDRMAP2_ADDRMAP_COL_B3  GENMASK_32(12, 8)
#define  ADDRMAP2_ADDRMAP_COL_B2  GENMASK_32(3, 0)

#define DDR_UMCTL2_ADDRMAP3      0xe008020c
#define  ADDRMAP3_ADDRMAP_COL_B9  GENMASK_32(28, 24)
#define  ADDRMAP3_ADDRMAP_COL_B8  GENMASK_32(20, 16)
#define  ADDRMAP3_ADDRMAP_COL_B7  GENMASK_32(12, 8)
#define  ADDRMAP3_ADDRMAP_COL_B6  GENMASK_32(4, 0)

#define DDR_UMCTL2_ADDRMAP4      0xe0080210
#define  ADDRMAP4_ADDRMAP_COL_B11 GENMASK_32(12, 8)
#define  ADDRMAP4_ADDRMAP_COL_B10 GENMASK_32(4, 0)

#define DDR_UMCTL2_ADDRMAP5      0xe0080214
#define  ADDRMAP5_ADDRMAP_ROW_B11 GENMASK_32(27, 24)
#define  ADDRMAP5_ADDRMAP_ROW_B2_10 GENMASK_32(19, 16)
#define  ADDRMAP5_ADDRMAP_ROW_B1  GENMASK_32(11, 8)
#define  ADDRMAP5_ADDRMAP_ROW_B0  GENMASK_32(3, 0)

#define DDR_UMCTL2_ADDRMAP6      0xe0080218
#define  ADDRMAP6_ADDRMAP_ROW_B15 GENMASK_32(27, 24)
#define  ADDRMAP6_ADDRMAP_ROW_B14 GENMASK_32(19, 16)
#define  ADDRMAP6_ADDRMAP_ROW_B13 GENMASK_32(11, 8)
#define  ADDRMAP6_ADDRMAP_ROW_B12 GENMASK_32(3, 0)

#define DDR_UMCTL2_ADDRMAP9      0xe0080224
#define  ADDRMAP9_ADDRMAP_ROW_B5  GENMASK_32(27, 24)
#define  ADDRMAP9_ADDRMAP_ROW_B4  GENMASK_32(19, 16)
#define  ADDRMAP9_ADDRMAP_ROW_B3  GENMASK_32(11, 8)
#define  ADDRMAP9_ADDRMAP_ROW_B2  GENMASK_32(3, 0)

#define DDR_UMCTL2_ADDRMAP10     0xe0080228
#define  ADDRMAP10_ADDRMAP_ROW_B9 GENMASK_32(27, 24)
#define  ADDRMAP10_ADDRMAP_ROW_B8 GENMASK_32(19, 16)
#define  ADDRMAP10_ADDRMAP_ROW_B7 GENMASK_32(11, 8)
#define  ADDRMAP10_ADDRMAP_ROW_B6 GENMASK_32(3, 0)

#define DDR_UMCTL2_ADDRMAP11     0xe008022c
#define  ADDRMAP11_ADDRMAP_ROW_B10 GENMASK_32(3, 0)

#define DDR_UMCTL2_ODTCFG        0xe0080240
#define  ODTCFG_WR_ODT_HOLD       GENMASK_32(27, 24)
#define  ODTCFG_WR_ODT_DELAY      GENMASK_32(20, 16)
#define  ODTCFG_RD_ODT_HOLD       GENMASK_32(11, 8)
#define  ODTCFG_RD_ODT_DELAY      GENMASK_32(6, 2)

#define DDR_UMCTL2_ODTMAP        0xe0080244
#define  ODTMAP_RANK1_RD_ODT      GENMASK_32(13, 12)
#define  ODTMAP_RANK1_WR_ODT      GENMASK_32(9, 8)
#define  ODTMAP_RANK0_RD_ODT      GENMASK_32(5, 4)
#define  ODTMAP_RANK0_WR_ODT      GENMASK_32(1, 0)

#define DDR_UMCTL2_SCHED         0xe0080250
#define  SCHED_RDWR_IDLE_GAP      GENMASK_32(30, 24)
#define  SCHED_GO2CRITICAL_HYSTERESIS GENMASK_32(23, 16)
#define  SCHED_LPR_NUM_ENTRIES    GENMASK_32(12, 8)
#define  SCHED_AUTOPRE_RMW        BIT_32(7)
#define  SCHED_PAGECLOSE          BIT_32(2)
#define  SCHED_PREFER_WRITE       BIT_32(1)
#define  SCHED_DIS_OPT_WRECC_COLLISION_FLUSH BIT_32(0)

#define DDR_UMCTL2_SCHED1        0xe0080254
#define  SCHED1_PAGECLOSE_TIMER   GENMASK_32(7, 0)

#define DDR_UMCTL2_PERFHPR1      0xe008025c
#define  PERFHPR1_HPR_XACT_RUN_LENGTH GENMASK_32(31, 24)
#define  PERFHPR1_HPR_MAX_STARVE  GENMASK_32(15, 0)

#define DDR_UMCTL2_PERFLPR1      0xe0080264
#define  PERFLPR1_LPR_XACT_RUN_LENGTH GENMASK_32(31, 24)
#define  PERFLPR1_LPR_MAX_STARVE  GENMASK_32(15, 0)

#define DDR_UMCTL2_PERFWR1       0xe008026c
#define  PERFWR1_W_XACT_RUN_LENGTH GENMASK_32(31, 24)
#define  PERFWR1_W_MAX_STARVE     GENMASK_32(15, 0)

#define DDR_UMCTL2_DBG0          0xe0080300
#define  DBG0_DIS_MAX_RANK_WR_OPT BIT_32(7)
#define  DBG0_DIS_MAX_RANK_RD_OPT BIT_32(6)
#define  DBG0_DIS_COLLISION_PAGE_OPT BIT_32(4)
#define  DBG0_DIS_WC              BIT_32(0)

#define DDR_UMCTL2_DBG1          0xe0080304
#define  DBG1_DIS_HIF             BIT_32(1)
#define  DBG1_DIS_DQ              BIT_32(0)

#define DDR_UMCTL2_DBGCAM        0xe0080308
#define  DBGCAM_WR_DATA_PIPELINE_EMPTY BIT_32(29)
#define  DBGCAM_RD_DATA_PIPELINE_EMPTY BIT_32(28)
#define  DBGCAM_DBG_WR_Q_EMPTY    BIT_32(26)
#define  DBGCAM_DBG_RD_Q_EMPTY    BIT_32(25)
#define  DBGCAM_DBG_STALL         BIT_32(24)
#define  DBGCAM_DBG_W_Q_DEPTH     GENMASK_32(21, 16)
#define  DBGCAM_DBG_LPR_Q_DEPTH   GENMASK_32(13, 8)
#define  DBGCAM_DBG_HPR_Q_DEPTH   GENMASK_32(5, 0)

#define DDR_UMCTL2_DBGCMD        0xe008030c
#define  DBGCMD_CTRLUPD           BIT_32(5)
#define  DBGCMD_ZQ_CALIB_SHORT    BIT_32(4)
#define  DBGCMD_RANK1_REFRESH     BIT_32(1)
#define  DBGCMD_RANK0_REFRESH     BIT_32(0)

#define DDR_UMCTL2_DBGSTAT       0xe0080310
#define  DBGSTAT_CTRLUPD_BUSY     BIT_32(5)
#define  DBGSTAT_ZQ_CALIB_SHORT_BUSY BIT_32(4)
#define  DBGSTAT_RANK1_REFRESH_BUSY BIT_32(1)
#define  DBGSTAT_RANK0_REFRESH_BUSY BIT_32(0)

#define DDR_UMCTL2_DBGCAM1       0xe0080318
#define  DBGCAM1_DBG_WRECC_Q_DEPTH GENMASK_32(5, 0)

#define DDR_UMCTL2_SWCTL         0xe0080320
#define  SWCTL_SW_DONE            BIT_32(0)

#define DDR_UMCTL2_SWSTAT        0xe0080324
#define  SWSTAT_SW_DONE_ACK       BIT_32(0)

#define DDR_UMCTL2_SWCTLSTATIC   0xe0080328
#define  SWCTLSTATIC_SW_STATIC_UNLOCK BIT_32(0)

#define DDR_UMCTL2_POISONCFG     0xe008036c
#define  POISONCFG_RD_POISON_INTR_CLR BIT_32(24)
#define  POISONCFG_RD_POISON_INTR_EN BIT_32(20)
#define  POISONCFG_RD_POISON_SLVERR_EN BIT_32(16)
#define  POISONCFG_WR_POISON_INTR_CLR BIT_32(8)
#define  POISONCFG_WR_POISON_INTR_EN BIT_32(4)
#define  POISONCFG_WR_POISON_SLVERR_EN BIT_32(0)

#define DDR_UMCTL2_POISONSTAT    0xe0080370
#define  POISONSTAT_RD_POISON_INTR_2 BIT_32(18)
#define  POISONSTAT_RD_POISON_INTR_1 BIT_32(17)
#define  POISONSTAT_RD_POISON_INTR_0 BIT_32(16)
#define  POISONSTAT_WR_POISON_INTR_2 BIT_32(2)
#define  POISONSTAT_WR_POISON_INTR_1 BIT_32(1)
#define  POISONSTAT_WR_POISON_INTR_0 BIT_32(0)

#define DDR_UMCTL2_ADVECCINDEX   0xe0080374
#define  ADVECCINDEX_ECC_POISON_BEATS_SEL GENMASK_32(8, 5)
#define  ADVECCINDEX_ECC_ERR_SYMBOL_SEL GENMASK_32(4, 3)
#define  ADVECCINDEX_ECC_SYNDROME_SEL GENMASK_32(2, 0)

#define DDR_UMCTL2_ECCPOISONPAT0 0xe008037c
#define  ECCPOISONPAT0_ECC_POISON_DATA_31_0 GENMASK_32(31, 0)

#define DDR_UMCTL2_ECCPOISONPAT2 0xe0080384
#define  ECCPOISONPAT2_ECC_POISON_DATA_71_64 GENMASK_32(7, 0)

#define DDR_UMCTL2_ECCAPSTAT     0xe0080388
#define  ECCAPSTAT_ECC_AP_ERR     BIT_32(0)

#define DDR_UMCTL2_PSTAT         0xe00803fc
#define  PSTAT_WR_PORT_BUSY_2     BIT_32(18)
#define  PSTAT_WR_PORT_BUSY_1     BIT_32(17)
#define  PSTAT_WR_PORT_BUSY_0     BIT_32(16)
#define  PSTAT_RD_PORT_BUSY_2     BIT_32(2)
#define  PSTAT_RD_PORT_BUSY_1     BIT_32(1)
#define  PSTAT_RD_PORT_BUSY_0     BIT_32(0)

#define DDR_UMCTL2_PCCFG         0xe0080400
#define  PCCFG_BL_EXP_MODE        BIT_32(8)
#define  PCCFG_PAGEMATCH_LIMIT    BIT_32(4)
#define  PCCFG_GO2CRITICAL_EN     BIT_32(0)

#define DDR_UMCTL2_PCFGR_0       0xe0080404
#define  PCFGR_0_RD_PORT_PAGEMATCH_EN BIT_32(14)
#define  PCFGR_0_RD_PORT_URGENT_EN BIT_32(13)
#define  PCFGR_0_RD_PORT_AGING_EN BIT_32(12)
#define  PCFGR_0_RD_PORT_PRIORITY GENMASK_32(9, 0)

#define DDR_UMCTL2_PCFGW_0       0xe0080408
#define  PCFGW_0_WR_PORT_PAGEMATCH_EN BIT_32(14)
#define  PCFGW_0_WR_PORT_URGENT_EN BIT_32(13)
#define  PCFGW_0_WR_PORT_AGING_EN BIT_32(12)
#define  PCFGW_0_WR_PORT_PRIORITY GENMASK_32(9, 0)

#define DDR_UMCTL2_PCTRL_0       0xe0080490
#define  PCTRL_0_PORT_EN          BIT_32(0)

#define DDR_UMCTL2_PCFGQOS0_0    0xe0080494
#define  PCFGQOS0_0_RQOS_MAP_REGION1 GENMASK_32(21, 20)
#define  PCFGQOS0_0_RQOS_MAP_REGION0 GENMASK_32(17, 16)
#define  PCFGQOS0_0_RQOS_MAP_LEVEL1 GENMASK_32(3, 0)

#define DDR_UMCTL2_PCFGQOS1_0    0xe0080498
#define  PCFGQOS1_0_RQOS_MAP_TIMEOUTR GENMASK_32(26, 16)
#define  PCFGQOS1_0_RQOS_MAP_TIMEOUTB GENMASK_32(10, 0)

#define DDR_UMCTL2_PCFGWQOS0_0   0xe008049c
#define  PCFGWQOS0_0_WQOS_MAP_REGION2 GENMASK_32(25, 24)
#define  PCFGWQOS0_0_WQOS_MAP_REGION1 GENMASK_32(21, 20)
#define  PCFGWQOS0_0_WQOS_MAP_REGION0 GENMASK_32(17, 16)
#define  PCFGWQOS0_0_WQOS_MAP_LEVEL2 GENMASK_32(11, 8)
#define  PCFGWQOS0_0_WQOS_MAP_LEVEL1 GENMASK_32(3, 0)

#define DDR_UMCTL2_PCFGWQOS1_0   0xe00804a0
#define  PCFGWQOS1_0_WQOS_MAP_TIMEOUT2 GENMASK_32(26, 16)
#define  PCFGWQOS1_0_WQOS_MAP_TIMEOUT1 GENMASK_32(10, 0)

#define DDR_UMCTL2_PCFGR_1       0xe00804b4
#define  PCFGR_1_RD_PORT_PAGEMATCH_EN BIT_32(14)
#define  PCFGR_1_RD_PORT_URGENT_EN BIT_32(13)
#define  PCFGR_1_RD_PORT_AGING_EN BIT_32(12)
#define  PCFGR_1_RD_PORT_PRIORITY GENMASK_32(9, 0)

#define DDR_UMCTL2_PCFGW_1       0xe00804b8
#define  PCFGW_1_WR_PORT_PAGEMATCH_EN BIT_32(14)
#define  PCFGW_1_WR_PORT_URGENT_EN BIT_32(13)
#define  PCFGW_1_WR_PORT_AGING_EN BIT_32(12)
#define  PCFGW_1_WR_PORT_PRIORITY GENMASK_32(9, 0)

#define DDR_UMCTL2_PCTRL_1       0xe0080540
#define  PCTRL_1_PORT_EN          BIT_32(0)

#define DDR_UMCTL2_PCFGQOS0_1    0xe0080544
#define  PCFGQOS0_1_RQOS_MAP_REGION1 GENMASK_32(21, 20)
#define  PCFGQOS0_1_RQOS_MAP_REGION0 GENMASK_32(17, 16)
#define  PCFGQOS0_1_RQOS_MAP_LEVEL1 GENMASK_32(3, 0)

#define DDR_UMCTL2_PCFGQOS1_1    0xe0080548
#define  PCFGQOS1_1_RQOS_MAP_TIMEOUTR GENMASK_32(26, 16)
#define  PCFGQOS1_1_RQOS_MAP_TIMEOUTB GENMASK_32(10, 0)

#define DDR_UMCTL2_PCFGWQOS0_1   0xe008054c
#define  PCFGWQOS0_1_WQOS_MAP_REGION2 GENMASK_32(25, 24)
#define  PCFGWQOS0_1_WQOS_MAP_REGION1 GENMASK_32(21, 20)
#define  PCFGWQOS0_1_WQOS_MAP_REGION0 GENMASK_32(17, 16)
#define  PCFGWQOS0_1_WQOS_MAP_LEVEL2 GENMASK_32(11, 8)
#define  PCFGWQOS0_1_WQOS_MAP_LEVEL1 GENMASK_32(3, 0)

#define DDR_UMCTL2_PCFGWQOS1_1   0xe0080550
#define  PCFGWQOS1_1_WQOS_MAP_TIMEOUT2 GENMASK_32(26, 16)
#define  PCFGWQOS1_1_WQOS_MAP_TIMEOUT1 GENMASK_32(10, 0)

#define DDR_UMCTL2_PCFGR_2       0xe0080564
#define  PCFGR_2_RD_PORT_PAGEMATCH_EN BIT_32(14)
#define  PCFGR_2_RD_PORT_URGENT_EN BIT_32(13)
#define  PCFGR_2_RD_PORT_AGING_EN BIT_32(12)
#define  PCFGR_2_RD_PORT_PRIORITY GENMASK_32(9, 0)

#define DDR_UMCTL2_PCFGW_2       0xe0080568
#define  PCFGW_2_WR_PORT_PAGEMATCH_EN BIT_32(14)
#define  PCFGW_2_WR_PORT_URGENT_EN BIT_32(13)
#define  PCFGW_2_WR_PORT_AGING_EN BIT_32(12)
#define  PCFGW_2_WR_PORT_PRIORITY GENMASK_32(9, 0)

#define DDR_UMCTL2_PCTRL_2       0xe00805f0
#define  PCTRL_2_PORT_EN          BIT_32(0)

#define DDR_UMCTL2_PCFGQOS0_2    0xe00805f4
#define  PCFGQOS0_2_RQOS_MAP_REGION1 GENMASK_32(21, 20)
#define  PCFGQOS0_2_RQOS_MAP_REGION0 GENMASK_32(17, 16)
#define  PCFGQOS0_2_RQOS_MAP_LEVEL1 GENMASK_32(3, 0)

#define DDR_UMCTL2_PCFGQOS1_2    0xe00805f8
#define  PCFGQOS1_2_RQOS_MAP_TIMEOUTR GENMASK_32(26, 16)
#define  PCFGQOS1_2_RQOS_MAP_TIMEOUTB GENMASK_32(10, 0)

#define DDR_UMCTL2_PCFGWQOS0_2   0xe00805fc
#define  PCFGWQOS0_2_WQOS_MAP_REGION2 GENMASK_32(25, 24)
#define  PCFGWQOS0_2_WQOS_MAP_REGION1 GENMASK_32(21, 20)
#define  PCFGWQOS0_2_WQOS_MAP_REGION0 GENMASK_32(17, 16)
#define  PCFGWQOS0_2_WQOS_MAP_LEVEL2 GENMASK_32(11, 8)
#define  PCFGWQOS0_2_WQOS_MAP_LEVEL1 GENMASK_32(3, 0)

#define DDR_UMCTL2_PCFGWQOS1_2   0xe0080600
#define  PCFGWQOS1_2_WQOS_MAP_TIMEOUT2 GENMASK_32(26, 16)
#define  PCFGWQOS1_2_WQOS_MAP_TIMEOUT1 GENMASK_32(10, 0)

#define DDR_UMCTL2_SARBASE0      0xe0080f04
#define  SARBASE0_BASE_ADDR       GENMASK_32(2, 0)

#define DDR_UMCTL2_SARSIZE0      0xe0080f08
#define  SARSIZE0_NBLOCKS         GENMASK_32(7, 0)

#define DDR_UMCTL2_SBRCTL        0xe0080f24
#define  SBRCTL_SCRUB_INTERVAL    GENMASK_32(20, 8)
#define  SBRCTL_SCRUB_BURST       GENMASK_32(6, 4)
#define  SBRCTL_SCRUB_MODE        BIT_32(2)
#define  SBRCTL_SCRUB_DURING_LOWPOWER BIT_32(1)
#define  SBRCTL_SCRUB_EN          BIT_32(0)

#define DDR_UMCTL2_SBRSTAT       0xe0080f28
#define  SBRSTAT_SCRUB_DONE       BIT_32(1)
#define  SBRSTAT_SCRUB_BUSY       BIT_32(0)

#define DDR_UMCTL2_SBRWDATA0     0xe0080f2c
#define  SBRWDATA0_SCRUB_PATTERN0 GENMASK_32(31, 0)

#define DDR_UMCTL2_SBRSTART0     0xe0080f38
#define  SBRSTART0_SBR_ADDRESS_START_MASK_0 GENMASK_32(31, 0)

#define DDR_UMCTL2_SBRSTART1     0xe0080f3c
#define  SBRSTART1_SBR_ADDRESS_START_MASK_1 GENMASK_32(3, 0)

#define DDR_UMCTL2_SBRRANGE0     0xe0080f40
#define  SBRRANGE0_SBR_ADDRESS_RANGE_MASK_0 GENMASK_32(31, 0)

#define DDR_UMCTL2_SBRRANGE1     0xe0080f44
#define  SBRRANGE1_SBR_ADDRESS_RANGE_MASK_1 GENMASK_32(3, 0)

#define DDR_UMCTL2_UMCTL2_VER_NUMBER 0xe0080ff0
#define  UMCTL2_VER_NUMBER_VER_NUMBER GENMASK_32(31, 0)

#define DDR_UMCTL2_UMCTL2_VER_TYPE 0xe0080ff4
#define  UMCTL2_VER_TYPE_VER_TYPE GENMASK_32(31, 0)


#endif /* __DDR_REG_H */
