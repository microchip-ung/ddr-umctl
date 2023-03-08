// SPDX-License-Identifier: (GPL-2.0+ OR MIT)
/*
 * Copyright (C) 2023 Microchip Technology Inc. and its subsidiaries.
 *
 */

#include <ddr_config.h>

const struct ddr_config pcb134_ddr4_ddr_config = {
	.info = {
		.name = "pcb134_ddr4 2023-03-08-09:50:54 5dfeeccbe640-dirty",
		.speed = 1667,
		.size = 0x80000000,
		.bus_width = 32,
	},
	.main = {
		.crcparctl1 = 0x00001000,
		.dbictl = 0x00000001,
		.dfimisc = 0x00000000,
		.dfitmg0 = 0x03898208,
		.dfitmg1 = 0x00040201,
		.dfiupd0 = 0x40400003,
		.dfiupd1 = 0x004000ff,
		.ecccfg0 = 0x00000004,
		.init0 = 0x00020196,
		.init1 = 0x00a20000,
		.init3 = 0x04200501,
		.init4 = 0x00080200,
		.init5 = 0x00110004,
		.init6 = 0x00000400,
		.init7 = 0x00000499,
		.mstr = 0x41040010,
		.pccfg = 0x00000000,
		.pwrctl = 0x00000000,
		.rfshctl0 = 0x00210010,
		.rfshctl3 = 0x00000000,
	},

	.timing = {
		.dramtmg0 = 0x0e0b1f10,
		.dramtmg1 = 0x00030317,
		.dramtmg12 = 0x00000010,
		.dramtmg2 = 0x0507050b,
		.dramtmg3 = 0x0050400c,
		.dramtmg4 = 0x07030307,
		.dramtmg5 = 0x05050303,
		.dramtmg8 = 0x03020a04,
		.dramtmg9 = 0x00030209,
		.odtcfg = 0x0600060c,
		.rfshtmg = 0x0071007a,
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
		.pgcr2 = 0x0000fe3e,
		.schcr1 = 0x00000000,
		.zq0pr = 0x0007bb09,
		.zq1pr = 0x0007fb2b,
		.zq2pr = 0x0007fb2b,
		.zqcr = 0x03058e00,
	},

	.phy_timing = {
		.dtpr0 = 0x05200c07,
		.dtpr1 = 0x28160018,
		.dtpr2 = 0x000500fc,
		.dtpr3 = 0x02550101,
		.dtpr4 = 0x00f30806,
		.dtpr5 = 0x002e0d07,
		.mr0 = 0x00000420,
		.mr1 = 0x00000501,
		.mr2 = 0x00000008,
		.mr3 = 0x00000200,
		.mr4 = 0x00000800,
		.mr5 = 0x00000400,
		.mr6 = 0x00000499,
		.ptr0 = 0x3421a0d0,
		.ptr1 = 0x51618ea6,
		.ptr2 = 0x00083def,
		.ptr3 = 0x0fc65800,
		.ptr4 = 0x10028800,
	},

};
