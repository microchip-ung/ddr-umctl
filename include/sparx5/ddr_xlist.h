/*
 * Copyright (C) 2023 Microchip Technology Inc. and its subsidiaries.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __DDR_XLIST_H
#define __DDR_XLIST_H

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
        X(sbrctl, DDR_UMCTL2_SBRCTL, main)	\

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
        X(ptr0, DDR_PHY_PTR0, phy_timing)	\
        X(ptr1, DDR_PHY_PTR1, phy_timing)	\
        X(ptr2, DDR_PHY_PTR2, phy_timing)	\
        X(ptr3, DDR_PHY_PTR3, phy_timing)	\
        X(ptr4, DDR_PHY_PTR4, phy_timing)	\


#endif /* __DDR_XLIST_H */
