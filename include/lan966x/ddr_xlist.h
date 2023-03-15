/*
 * Copyright (C) 2023 Microchip Technology Inc. and its subsidiaries.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __DDR_XLIST_H
#define __DDR_XLIST_H

#define XLIST_DDR_MAIN \
        X(dfimisc, DDR_UMCTL2_DFIMISC, main)	\
        X(dfitmg0, DDR_UMCTL2_DFITMG0, main)	\
        X(dfitmg1, DDR_UMCTL2_DFITMG1, main)	\
        X(dfiupd0, DDR_UMCTL2_DFIUPD0, main)	\
        X(dfiupd1, DDR_UMCTL2_DFIUPD1, main)	\
        X(ecccfg0, DDR_UMCTL2_ECCCFG0, main)	\
        X(init0, DDR_UMCTL2_INIT0, main)	\
        X(init1, DDR_UMCTL2_INIT1, main)	\
        X(init5, DDR_UMCTL2_INIT5, main)	\
        X(mstr, DDR_UMCTL2_MSTR, main)	\
        X(pccfg, DDR_UMCTL2_PCCFG, main)	\
        X(pwrctl, DDR_UMCTL2_PWRCTL, main)	\
        X(rfshctl0, DDR_UMCTL2_RFSHCTL0, main)	\
        X(rfshctl3, DDR_UMCTL2_RFSHCTL3, main)	\

#define XLIST_DDR_TIMING \
        X(dramtmg0, DDR_UMCTL2_DRAMTMG0, timing)	\
        X(dramtmg1, DDR_UMCTL2_DRAMTMG1, timing)	\
        X(dramtmg2, DDR_UMCTL2_DRAMTMG2, timing)	\
        X(dramtmg3, DDR_UMCTL2_DRAMTMG3, timing)	\
        X(dramtmg4, DDR_UMCTL2_DRAMTMG4, timing)	\
        X(dramtmg5, DDR_UMCTL2_DRAMTMG5, timing)	\
        X(dramtmg8, DDR_UMCTL2_DRAMTMG8, timing)	\
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

#define XLIST_DDR_PHY \
        X(dcr, DDR_PHY_DCR, phy)	\
        X(dsgcr, DDR_PHY_DSGCR, phy)	\
        X(dtcr, DDR_PHY_DTCR, phy)	\
        X(dxccr, DDR_PHY_DXCCR, phy)	\
        X(pgcr2, DDR_PHY_PGCR2, phy)	\
        X(zq0cr0, DDR_PHY_ZQ0CR0, phy)	\
        X(zq0cr1, DDR_PHY_ZQ0CR1, phy)	\
        X(zq1cr0, DDR_PHY_ZQ1CR0, phy)	\
        X(zq1cr1, DDR_PHY_ZQ1CR1, phy)	\

#define XLIST_DDR_PHY_TIMING \
        X(dtpr0, DDR_PHY_DTPR0, phy_timing)	\
        X(dtpr1, DDR_PHY_DTPR1, phy_timing)	\
        X(dtpr2, DDR_PHY_DTPR2, phy_timing)	\
        X(mr0, DDR_PHY_MR0, phy_timing)	\
        X(mr1, DDR_PHY_MR1, phy_timing)	\
        X(mr2, DDR_PHY_MR2, phy_timing)	\
        X(mr3, DDR_PHY_MR3, phy_timing)	\
        X(ptr0, DDR_PHY_PTR0, phy_timing)	\
        X(ptr1, DDR_PHY_PTR1, phy_timing)	\
        X(ptr2, DDR_PHY_PTR2, phy_timing)	\
        X(ptr3, DDR_PHY_PTR3, phy_timing)	\
        X(ptr4, DDR_PHY_PTR4, phy_timing)	\


#endif /* __DDR_XLIST_H */
