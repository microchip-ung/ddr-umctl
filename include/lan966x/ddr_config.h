/*
 * Copyright (C) 2022 Microchip Technology Inc. and its subsidiaries.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _DDR_CONFIG_H
#define _DDR_CONFIG_H

#include <stddef.h>
#include <stdint.h>

struct ddr_config {
	struct config_ddr_info {
		char name[128];
		uint32_t speed;		/* in kHZ */
		size_t size;		/* Memory size in byte = col * row * width */
		uint32_t bus_width;	/* SDRAM Controller Bus Width */
	} info;
	struct config_ddr_main {
		uint32_t dfimisc;
		uint32_t dfitmg0;
		uint32_t dfitmg1;
		uint32_t dfiupd0;
		uint32_t dfiupd1;
		uint32_t ecccfg0;
		uint32_t init0;
		uint32_t init1;
		uint32_t init3;
		uint32_t init4;
		uint32_t init5;
		uint32_t mstr;
		uint32_t pccfg;
		uint32_t pwrctl;
		uint32_t rfshctl0;
		uint32_t rfshctl3;
		uint32_t sbrctl;
	} main;
	struct config_ddr_timing {
		uint32_t dramtmg0;
		uint32_t dramtmg1;
		uint32_t dramtmg2;
		uint32_t dramtmg3;
		uint32_t dramtmg4;
		uint32_t dramtmg5;
		uint32_t dramtmg8;
		uint32_t odtcfg;
		uint32_t rfshtmg;
	} timing;
	struct config_ddr_mapping {
		uint32_t addrmap0;
		uint32_t addrmap1;
		uint32_t addrmap2;
		uint32_t addrmap3;
		uint32_t addrmap4;
		uint32_t addrmap5;
		uint32_t addrmap6;
	} mapping;
	struct config_ddr_phy {
		uint32_t dcr;
		uint32_t dsgcr;
		uint32_t dtcr;
		uint32_t dxccr;
		uint32_t pgcr2;
		uint32_t zq0cr0;
		uint32_t zq0cr1;
		uint32_t zq1cr0;
		uint32_t zq1cr1;
	} phy;
	struct config_ddr_phy_timing {
		uint32_t dtpr0;
		uint32_t dtpr1;
		uint32_t dtpr2;
		uint32_t ptr0;
		uint32_t ptr1;
		uint32_t ptr2;
		uint32_t ptr3;
		uint32_t ptr4;
	} phy_timing;
};

#endif /* _DDR_CONFIG_H */
