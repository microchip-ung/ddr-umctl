/*
 * Copyright (C) 2022 Microchip Technology Inc. and its subsidiaries.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <assert.h>
#include <stddef.h>

#include <ddr_init.h>
#include <ddr_reg.h>

struct reg_desc {
        const char *name;
	uintptr_t reg_addr;
        uint8_t par_offset;     /* Offset for parameter array */
};

#define X(x, y, z)							\
        {                                               		\
                .name = #x,                             		\
		.reg_addr  = y,						\
		.par_offset = offsetof(struct config_ddr_##z, x),	\
        },

static const struct reg_desc ddr_main_reg[] = {
XLIST_DDR_MAIN
};

static const struct reg_desc ddr_timing_reg[] = {
XLIST_DDR_TIMING
};

static const struct reg_desc ddr_mapping_reg[] = {
XLIST_DDR_MAPPING
};

static const struct reg_desc ddr_phy_reg[] = {
XLIST_DDR_PHY
};

static const struct reg_desc ddr_phy_timing_reg[] = {
XLIST_DDR_PHY_TIMING
};

static void wait_reg_set(uintptr_t reg, uint32_t mask, int usec)
{
	ddr_timeout_t t = timeout_set_us(usec);
	while ((mmio_read_32(reg) & mask) == 0) {
		if (timeout_elapsed(&t)) {
			DEBUG("Timeout waiting for %p mask %08x set", (void*)reg, mask);
			assert(false);
		}
	}
}

static void wait_reg_clr(uintptr_t reg, uint32_t mask, int usec)
{
	ddr_timeout_t t = timeout_set_us(usec);
	while ((mmio_read_32(reg) & mask) != 0) {
		if (timeout_elapsed(&t)) {
			DEBUG("Timeout waiting for %p mask %08x clr", (void*)reg, mask);
			assert(false);
		}
	}
}

static void set_regs(const void *cfg,
		     const struct reg_desc *reg,
		     size_t ct)
{
	int i;

	for (i = 0; i < ct; i++) {
		uint32_t val = ((const uint32_t *)cfg)[reg[i].par_offset >> 2];
		mmio_write_32(reg[i].reg_addr, val);
	}
}

static void ecc_enable_scrubbing(const struct umctl_drv *drv)
{
	DEBUG("Enable ECC scrubbing\n");

        /* 1.  Disable AXI port. port_en = 0 */
	mmio_clrbits_32(DDR_UMCTL2_PCTRL_0, PCTRL_0_PORT_EN);

        /* 2. scrub_mode = 1 */
	mmio_setbits_32(DDR_UMCTL2_SBRCTL, SBRCTL_SCRUB_MODE);

        /* 3. scrub_interval = 0 */
	mmio_clrbits_32(DDR_UMCTL2_SBRCTL, SBRCTL_SCRUB_MODE);

        /* 4. Data pattern = 0 */
	mmio_write_32(DDR_UMCTL2_SBRWDATA0, 0);

        /* 5. (skip) */

        /* 6. Enable SBR programming */
	mmio_setbits_32(DDR_UMCTL2_SBRCTL, SBRCTL_SCRUB_EN);

        /* 7. Poll SBRSTAT.scrub_done */
	wait_reg_set(DDR_UMCTL2_SBRSTAT, SBRSTAT_SCRUB_DONE, 1000);

        /* 8. Poll SBRSTAT.scrub_busy */
	wait_reg_clr(DDR_UMCTL2_SBRSTAT, SBRSTAT_SCRUB_BUSY, 1000);

        /* 9. Disable SBR programming */
	mmio_clrbits_32(DDR_UMCTL2_SBRCTL, SBRCTL_SCRUB_EN);
#if 0
        /* 10. Normal scrub operation, mode = 0, interval = 100 */
        wr_fld_r_r (DDR_UMCTL2, UMCTL2_MP, SBRCTL, SCRUB_MODE, 0);
        wr_fld_r_r (DDR_UMCTL2, UMCTL2_MP, SBRCTL, SCRUB_INTERVAL, 100);
        /* 11. Enable SBR progeramming again  */
        wr_fld_r_r (DDR_UMCTL2, UMCTL2_MP, SBRCTL, SCRUB_EN, 1);
#endif

        /* 12. Enable AXI port */
	mmio_setbits_32(DDR_UMCTL2_PCTRL_0, PCTRL_0_PORT_EN);

	DEBUG("Enabled ECC scrubbing\n");
}

static void wait_phy_idone(const struct umctl_drv *drv)
{
	uint32_t pgsr;
        int i, error = 0;
	ddr_timeout_t t;
	static const struct {
		uint32_t mask;
		const char *desc;
	} phyerr[] = {
		{ PGSR0_VERR, "VREF Training Error" },
		{ PGSR0_ZCERR, "Impedance Calibration Error" },
		{ PGSR0_WLERR, "Write Leveling Error" },
		{ PGSR0_QSGERR, "DQS Gate Training Error" },
		{ PGSR0_WLAERR, "Write Leveling Adjustment Error" },
		{ PGSR0_RDERR, "Read Bit Deskew Error" },
		{ PGSR0_WDERR, "Write Bit Deskew Error" },
		{ PGSR0_REERR, "Read Eye Training Error" },
		{ PGSR0_WEERR, "Write Eye Training Error" },
		{ PGSR0_CAERR, "CA Training Error" },
		// { PGSR0_CAWRN, "CA Training Warning" },
		{ PGSR0_SRDERR, "Static Read Error" },
	};

	t = timeout_set_us(100);

	do {
		pgsr = mmio_read_32(DDR_PHY_PGSR0);

		if (timeout_elapsed(&t)) {
			NOTICE("PHY IDONE timeout\n");
			assert(false);
		}

		for (i = 0; i < ARRAY_SIZE(phyerr); i++) {
			if (pgsr & phyerr[i].mask) {
				NOTICE("PHYERR: %s", phyerr[i].desc);
				error++;
			}
		}

	} while((pgsr & PGSR0_IDONE) == 0 && error == 0);
}

int ddr_init(const struct umctl_drv *drv, const struct ddr_config *cfg)
{

        VERBOSE("name = %s\n", cfg->info.name);
        VERBOSE("speed = %d kHz\n", cfg->info.speed);
        VERBOSE("size  = %zdM\n", cfg->info.size / 1024 / 1024);

	/* Reset, start clocks at desired speed */
	drv->reset(drv, cfg, true);

	/* Set up controller registers */
	set_regs(&cfg->main, ddr_main_reg, ARRAY_SIZE(ddr_main_reg));
	set_regs(&cfg->timing, ddr_timing_reg, ARRAY_SIZE(ddr_timing_reg));
	set_regs(&cfg->mapping, ddr_mapping_reg, ARRAY_SIZE(ddr_mapping_reg));

	/* Release reset */
	drv->reset(drv, cfg, false);

	/* Set PHY registers */
	set_regs(&cfg->phy, ddr_phy_reg, ARRAY_SIZE(ddr_phy_reg));
	set_regs(&cfg->phy_timing, ddr_phy_timing_reg, ARRAY_SIZE(ddr_phy_timing_reg));

	/* Init PHY */

	/* PHY initialization: PLL initialization, Delay line
	 * calibration, PHY reset and Impedence Calibration
	 */
	mmio_write_32(DDR_PHY_PIR,
		      PIR_INIT | PIR_ZCAL | PIR_PLLINIT | PIR_DCAL | PIR_PHYRST);

	wait_phy_idone(drv);

	if (cfg->main.ecccfg0 & ECCCFG0_ECC_MODE)
		ecc_enable_scrubbing(drv);

	return 0;
}
