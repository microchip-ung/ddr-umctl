/*
 * Copyright (C) 2022 Microchip Technology Inc. and its subsidiaries.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stddef.h>

#include <ddr_init.h>
#include <ddr_reg.h>

extern void ddr_reset(const struct umctl_drv *drv, const struct ddr_config *cfg , bool assert);

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
			VERBOSE("Timeout waiting for %p mask %08x set", (void*)reg, mask);
			PANIC("wait_reg_set");
		}
	}
}

static void wait_reg_clr(uintptr_t reg, uint32_t mask, int usec)
{
	ddr_timeout_t t = timeout_set_us(usec);
	while ((mmio_read_32(reg) & mask) != 0) {
		if (timeout_elapsed(&t)) {
			VERBOSE("Timeout waiting for %p mask %08x clr", (void*)reg, mask);
			PANIC("wait_reg_clr");
		}
	}
}

static void wait_operating_mode(uint32_t mode, int usec)
{
	ddr_timeout_t t = timeout_set_us(usec);
	while ((FIELD_GET(STAT_OPERATING_MODE,
			  mmio_read_32(DDR_UMCTL2_STAT))) != mode) {
		if (timeout_elapsed(&t)) {
			VERBOSE("Timeout waiting for mode %d", mode);
			PANIC("wait_operating_mode");
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
	TRACE("Enable ECC scrubbing\n");

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
	wait_reg_set(DDR_UMCTL2_SBRSTAT, SBRSTAT_SCRUB_DONE, 10);

        /* 8. Poll SBRSTAT.scrub_busy */
	wait_reg_clr(DDR_UMCTL2_SBRSTAT, SBRSTAT_SCRUB_BUSY, 10);

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

	TRACE("Enabled ECC scrubbing\n");
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
			PANIC("PHY IDONE timeout\n");
		}

		for (i = 0; i < ARRAY_SIZE(phyerr); i++) {
			if (pgsr & phyerr[i].mask) {
				NOTICE("PHYERR: %s", phyerr[i].desc);
				error++;
			}
		}

	} while((pgsr & PGSR0_IDONE) == 0 && error == 0);
}

static void ddr_phy_init(const struct umctl_drv *drv, uint32_t mode)
{
	mode |= PIR_INIT;

	TRACE("ddr_phy_init:start\n");

	/* Now, kick PHY */
	mmio_write_32(DDR_PHY_PIR, mode);

	VERBOSE("pir = 0x%x -> 0x%x\n", mode, mmio_read_32(DDR_PHY_PIR));

        /* Need to wait 10 configuration clock before start polling */
        usleep(10);

	wait_phy_idone(drv);

	TRACE("ddr_phy_init:done\n");
}

static void PHY_initialization(const struct umctl_drv *drv)
{
	/* write PHY initialization register for Write leveling, DQS
	 * gate training, Write_latency adjustment
	 */
	ddr_phy_init(drv, PIR_PHYRST | PIR_DRAMRST | PIR_DRAMINIT);
}

static void DRAM_initialization_by_memctrl(const struct umctl_drv *drv)
{
	/* write PHY initialization register for SDRAM initialization */
	ddr_phy_init(drv, PIR_CTLDINIT);
}

int ddr_init(const struct umctl_drv *drv, const struct ddr_config *cfg)
{
	TRACE("ddr_init:start\n");

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

	/* PHY initialization: PLL initialization, Delay line
	 * calibration, PHY reset and Impedance Calibration
	 */
	ddr_phy_init(drv, PIR_ZCAL | PIR_PLLINIT | PIR_DCAL | PIR_PHYRST);

	/* PHY FIFO reset */
	mmio_setbits_32(DDR_PHY_PGCR0, PGCR0_PHYFRST);

	PHY_initialization(drv);

	DRAM_initialization_by_memctrl(drv);

	/* Signal SW_DONE */
	mmio_clrbits_32(DDR_UMCTL2_SWCTL, SWCTL_SW_DONE);

	/* ...?... */
	mmio_setbits_32(DDR_UMCTL2_DFIMISC, DFIMISC_DFI_INIT_COMPLETE_EN);
	mmio_setbits_32(DDR_UMCTL2_SWCTL, SWCTL_SW_DONE);

	/* wait for SWSTAT.sw_done_ack to become set */
	wait_reg_set(DDR_UMCTL2_SWSTAT, SWSTAT_SW_DONE_ACK, 100);

	/* wait for STAT.operating_mode to become "normal" */
	wait_operating_mode(1, 100);

	if (cfg->main.ecccfg0 & ECCCFG0_ECC_MODE)
		ecc_enable_scrubbing(drv);

	TRACE("ddr_init:done\n");

	return 0;
}
