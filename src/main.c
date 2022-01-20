/*
 * Copyright (C) 2022 Microchip Technology Inc. and its subsidiaries.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stddef.h>
#include <stdio.h>
#include <ddr_init.h>
#include <ddr_platform.h>
#include <ddr_reg.h>

extern void ddr_reset(const struct umctl_drv *drv, const struct ddr_config *cfg , bool assert);

static struct umctl_drv drv = { .reset = ddr_reset, };

const struct ddr_config pcb134_cfg = {
	.info = { "PCB134 DDR3 with ECC", 416, 4UL * 1024UL * 1024UL * 1024UL, 40 },
	.main = {
		.crcparctl1 = 0x00001000,
		.dbictl = 0x00000001,
		.dfimisc = 0x00000001,
		.dfitmg0 = 0x0389820a,
		.dfitmg1 = 0x00040201,
		.dfiupd0 = 0x40400003,
		.dfiupd1 = 0x004000ff,
		.ecccfg0 = 0x00000004,
		.init0 = 0x000100f4,
		.init1 = 0x00610000,
		.init3 = 0x04200501,
		.init4 = 0x02180000,
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
		.dramtmg0 = 0x0f0b2210,
		.dramtmg1 = 0x00030418,
		.dramtmg12 = 0x00000010,
		.dramtmg2 = 0x0607040c,
		.dramtmg3 = 0x0050400c,
		.dramtmg4 = 0x07030307,
		.dramtmg5 = 0x05050303,
		.dramtmg8 = 0x03020c05,
		.dramtmg9 = 0x0002020a,
		.odtcfg = 0x06000604,
		.rfshtmg = 0x00320082,
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
		.dsgcr = 0x0064403b & ~DSGCR_PUREN,
		.dtcr0 = 0x0000b0cf,
		.dtcr1 = 0x00010237,
		.dxccr = 0x00c01884,
		.pgcr2 = 0x000110a8,
		.schcr1 = 0x00000000,
		.zq0pr = 0x0007bb09,
		.zq1pr = 0x0007fb2b,
		.zq2pr = 0x0007fb2b,
		.zqcr = 0x03058f00,
	},
	.phy_timing = {
		.dtpr0 = 0x06210d08,
		.dtpr1 = 0x28150008,
		.dtpr2 = 0x0005010e,
		.dtpr3 = 0x03000101,
		.dtpr4 = 0x01040806,
		.dtpr5 = 0x00300d08,
		.mr0 = 0x00000420,
		.mr1 = 0x00000501,
		.mr2 = 0x00000218,
		.mr3 = 0x00000000,
		.mr4 = 0x00000000,
		.mr5 = 0x00000400,
		.mr6 = 0x00000499,
		.ptr0 = 0x3e81f410,
		.ptr1 = 0x1d4c1194,
		.ptr2 = 0x00083def,
		.ptr3 = 0x10e7a120,
		.ptr4 = 0x10030d40,
	},
};

const struct ddr_config pcb135_cfg = {
	.info = { "PCB135 DDR4 with ECC", 416, 4UL * 1024UL * 1024UL * 1024UL, 40 },
	.main = {
		.crcparctl1 = 0x00001000,
		.dbictl = 0x00000001,
		.dfimisc = 0x00000001,
		.dfitmg0 = 0x03898207,
		.dfitmg1 = 0x00040201,
		.dfiupd0 = 0x40400003,
		.dfiupd1 = 0x004000ff,
		.ecccfg0 = 0x00000004,
		.init0 = 0x000200cc,
		.init1 = 0x00520000,
		.init3 = 0x1f140004,
		.init4 = 0x00200000,
		.init5 = 0x000a0004,
		.init6 = 0x00000000,
		.init7 = 0x00000000,
		.mstr = 0x41040401,
		.pccfg = 0x00000000,
		.pwrctl = 0x00000000,
		.rfshctl0 = 0x00210010,
		.rfshctl3 = 0x00000000,
	},
	.timing = {
		.dramtmg0 = 0x0e0c1c0f,
		.dramtmg1 = 0x00030414,
		.dramtmg12 = 0x00000010,
		.dramtmg2 = 0x0305050a,
		.dramtmg3 = 0x00502007,
		.dramtmg4 = 0x06020307,
		.dramtmg5 = 0x05050303,
		.dramtmg8 = 0x05050804,
		.dramtmg9 = 0x0004040d,
		.odtcfg = 0x06000610,
		.rfshtmg = 0x0065006d,
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
		.dsgcr = 0x0064403b & ~DSGCR_PUREN,
		.dtcr0 = 0x2000b0cf,
		.dtcr1 = 0x00010237,
		.dxccr = 0x00c01884,
		.pgcr2 = 0x0000e2f4,
		.schcr1 = 0x00000000,
		.zq0pr = 0x0007bb09,
		.zq1pr = 0x0007bb2d,
		.zq2pr = 0x0007bb2d,
		.zqcr = 0x04058e00,
	},
	.phy_timing = {
		.dtpr0 = 0x051d0c07,
		.dtpr1 = 0x28170104,
		.dtpr2 = 0x000600e1,
		.dtpr3 = 0x02000101,
		.dtpr4 = 0x00d90814,
		.dtpr5 = 0x00280c07,
		.mr0 = 0x00001f14,
		.mr1 = 0x00000004,
		.mr2 = 0x00000020,
		.mr3 = 0x00000000,
		.mr4 = 0x00000000,
		.mr5 = 0x00000400,
		.mr6 = 0x00000400,
		.ptr0 = 0x3481a910,
		.ptr1 = 0x186a104a,
		.ptr2 = 0x00083def,
		.ptr3 = 0x0e165b9b,
		.ptr4 = 0x085a8917,
	}
};

#if defined(STANDALONE)
int main(int argc, char **argv)
#else
int ddr_setup(void)
#endif
{
	return ddr_init(&drv, &pcb134_cfg);
}
