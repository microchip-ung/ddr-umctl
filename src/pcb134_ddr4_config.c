// SPDX-License-Identifier: (GPL-2.0+ OR MIT)
/*
 * Copyright (C) 2023 Microchip Technology Inc. and its subsidiaries.
 *
 */

#include <ddr_config.h>

const struct ddr_config pcb134_ddr4_ddr_config = {
	.info = {
		.name = "pcb134_ddr4 2023-04-14-15:27:53 3374f09751e3-dirty",
		.speed = 1667,
		.size = 0x80000000,
		.bus_width = 32,
	},
	.main = {
		.crcparctl1 = 0x00001091,
		.dbictl = 0x00000001,
		.dfimisc = 0x00000000,
		.dfitmg0 = 0x038d820c,
		.dfitmg1 = 0x00040201,
		.dfiupd0 = 0x40400003,
		.dfiupd1 = 0x004000ff,
		.ecccfg0 = 0x00000004,
		.init0 = 0x00020196,
		.init1 = 0x00a20000,
		.init3 = 0x08200501,
		.init4 = 0x10080200,
		.init5 = 0x00110004,
		.init6 = 0x00000401,
		.init7 = 0x00000419,
		.mstr = 0x41040010,
		.pccfg = 0x00000000,
		.pwrctl = 0x00000000,
		.rfshctl0 = 0x00210020,
		.rfshctl3 = 0x00000000,
		.sbrctl = 0x0000ff10,
	},

	.timing = {
		.dramtmg0 = 0x130a0e0e,
		.dramtmg1 = 0x00050315,
		.dramtmg12 = 0x00000010,
		.dramtmg2 = 0x0709050f,
		.dramtmg3 = 0x0050400c,
		.dramtmg4 = 0x06030306,
		.dramtmg5 = 0x05050303,
		.dramtmg8 = 0x03020a04,
		.dramtmg9 = 0x0003020d,
		.odtcfg = 0x0700060c,
		.rfshtmg = 0x0062006d,
	},

	.mapping = {
		.addrmap0 = 0x0000001f,
		.addrmap1 = 0x003f1717,
		.addrmap2 = 0x00000000,
		.addrmap3 = 0x00000000,
		.addrmap4 = 0x00001f1f,
		.addrmap5 = 0x04040404,
		.addrmap6 = 0x0f040404,
		.addrmap7 = 0x00000f0f,
		.addrmap8 = 0x00001919,
	},

	.phy = {
		.dcr = 0x0000040c,
		.dsgcr = 0x0064401b,
		.dtcr0 = 0x8000b0cf,
		.dtcr1 = 0x00010237,
		.dxccr = 0x00c01884,
		.pgcr2 = 0x00000b22,
		.schcr1 = 0x00000000,
		.zq0pr = 0x0007bb09,
		.zq1pr = 0x0007fb2b,
		.zq2pr = 0x0007fb2b,
		.zqcr = 0x03058e00,
	},

	.phy_timing = {
		.dtpr0 = 0x051d0b07,
		.dtpr1 = 0x28140018,
		.dtpr2 = 0x000500e1,
		.dtpr3 = 0x02550101,
		.dtpr4 = 0x00d90805,
		.dtpr5 = 0x00290c07,
		.ptr0 = 0x3421a0d0,
		.ptr1 = 0x51618ea6,
		.ptr2 = 0x00083def,
		.ptr3 = 0x0e165800,
		.ptr4 = 0x10028800,
	},

};
