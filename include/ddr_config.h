/*
 * Copyright (C) 2021 Microchip Technology Inc. and its subsidiaries.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _DDR_CONFIG_H
#define _DDR_CONFIG_H

#include <stdint.h>

struct ddr_config {
    struct {
        uint32 crcparctl1;
        uint32 dbictl;
        uint32 dfimisc;
        uint32 dfitmg0;
        uint32 dfitmg1;
        uint32 dfiupd0;
        uint32 dfiupd1;
        uint32 ecccfg0;
        uint32 init0;
        uint32 init1;
        uint32 init3;
        uint32 init4;
        uint32 init5;
        uint32 init6;
        uint32 init7;
        uint32 mstr;
        uint32 pccfg;
        uint32 pwrctl;
        uint32 rfshctl0;
        uint32 rfshctl3;
    } main;
    struct {
        uint32 dramtmg0;
        uint32 dramtmg1;
        uint32 dramtmg12;
        uint32 dramtmg2;
        uint32 dramtmg3;
        uint32 dramtmg4;
        uint32 dramtmg5;
        uint32 dramtmg8;
        uint32 dramtmg9;
        uint32 odtcfg;
        uint32 rfshtmg;
    } timing;
    struct {
        uint32 addrmap0;
        uint32 addrmap1;
        uint32 addrmap2;
        uint32 addrmap3;
        uint32 addrmap4;
        uint32 addrmap5;
        uint32 addrmap6;
        uint32 addrmap7;
        uint32 addrmap8;
    } mapping;
    struct {
        uint32 dcr;
        uint32 dsgcr;
        uint32 dtcr0;
        uint32 dtcr1;
        uint32 dxccr;
        uint32 pgcr2;
        uint32 schcr1;
        uint32 zq0pr;
        uint32 zq1pr;
        uint32 zq2pr;
        uint32 zqcr;
    } phy;
    struct {
        uint32 dtpr0;
        uint32 dtpr1;
        uint32 dtpr2;
        uint32 dtpr3;
        uint32 dtpr4;
        uint32 dtpr5;
        uint32 mr0;
        uint32 mr1;
        uint32 mr2;
        uint32 mr3;
        uint32 mr4;
        uint32 mr5;
        uint32 mr6;
        uint32 ptr0;
        uint32 ptr1;
        uint32 ptr2;
        uint32 ptr3;
        uint32 ptr4;
    } phy_timing;
};

#endif /* _DDR_CONFIG_H */
