// SPDX-License-Identifier: (GPL-2.0+ OR MIT)
/*
 * Copyright (C) 2023 Microchip Technology Inc. and its subsidiaries.
 *
 */

#include <ddr_config.h>

const struct ddr_config pcb135_ddr3_ddr_config = {
	.info = {
		.name = "pcb135_ddr3 2023-04-14-15:27:53 3374f09751e3-dirty",
		.speed = 1667,
		.size = 0x80000000,
		.bus_width = 32,
	},
	.main = {
		.crcparctl1 = 0x00001000,
		.dbictl = 0x00000001,
		.dfimisc = 0x00000000,
		.dfitmg0 = 0x03898207,
		.dfitmg1 = 0x00040201,
		.dfiupd0 = 0x40400003,
		.dfiupd1 = 0x004000ff,
		.ecccfg0 = 0x00000004,
		.init0 = 0x00020196,
		.init1 = 0x00a20000,
		.init3 = 0x11140004,
		.init4 = 0x00200000,
		.init5 = 0x000b0004,
		.init6 = 0x00000000,
		.init7 = 0x00000000,
		.mstr = 0x01040401,
		.pccfg = 0x00000000,
		.pwrctl = 0x00000000,
		.rfshctl0 = 0x00210020,
		.rfshctl3 = 0x00000000,
		.sbrctl = 0x0000ff10,
	},

	.timing = {
		.dramtmg0 = 0x0f111011,
		.dramtmg1 = 0x00030517,
		.dramtmg12 = 0x00000010,
		.dramtmg2 = 0x0305050b,
		.dramtmg3 = 0x0050400c,
		.dramtmg4 = 0x07020307,
		.dramtmg5 = 0x05050303,
		.dramtmg8 = 0x03030804,
		.dramtmg9 = 0x0004040d,
		.odtcfg = 0x06000610,
		.rfshtmg = 0x0062007a,
	},

	.mapping = {
		.addrmap0 = 0x0000001f,
		.addrmap1 = 0x00181818,
		.addrmap2 = 0x00000000,
		.addrmap3 = 0x00000000,
		.addrmap4 = 0x00001f1f,
		.addrmap5 = 0x04040404,
		.addrmap6 = 0x04040404,
		.addrmap7 = 0x00000f0f,
		.addrmap8 = 0x00003f3f,
	},

	.phy = {
		.dcr = 0x1000040b,
		.dsgcr = 0x0064401b,
		.dtcr0 = 0x8000b0cf,
		.dtcr1 = 0x00010237,
		.dxccr = 0x00c01884,
		.pgcr2 = 0x00000caa,
		.schcr1 = 0x00000000,
		.zq0pr = 0x0007bb09,
		.zq1pr = 0x0007bb2d,
		.zq2pr = 0x0007bb2d,
		.zqcr = 0x04058e00,
	},

	.phy_timing = {
		.dtpr0 = 0x06200d08,
		.dtpr1 = 0x28210304,
		.dtpr2 = 0x000600fd,
		.dtpr3 = 0x02000101,
		.dtpr4 = 0x00f30817,
		.dtpr5 = 0x002d0d08,
		.ptr0 = 0x3421a0d0,
		.ptr1 = 0x51618ea6,
		.ptr2 = 0x00083def,
		.ptr3 = 0x0fd65800,
		.ptr4 = 0x095a8800,
	},

};
