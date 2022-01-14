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

static void wait_reg_set(const struct umctl_drv *drv,
			 uintptr_t reg, uint32_t mask, int usec)
{
	drv->timeout_set_us(usec);
	while ((drv->mmio_read_32(reg) & mask) == 0) {
		if (drv->timeout_elapsed()) {
			DEBUG("Timeout waiting for %p mask %08x set", (void*)reg, mask);
			assert(false);
		}
	}
}

static void wait_reg_clr(const struct umctl_drv *drv,
			 uintptr_t reg, uint32_t mask, int usec)
{
	drv->timeout_set_us(usec);
	while ((drv->mmio_read_32(reg) & mask) != 0) {
		if (drv->timeout_elapsed()) {
			DEBUG("Timeout waiting for %p mask %08x clr", (void*)reg, mask);
			assert(false);
		}
	}
}

static void set_regs(const struct umctl_drv *drv,
		     const void *cfg,
		     const struct reg_desc *reg,
		     size_t ct)
{
	int i;

	for (i = 0; i < ct; i++) {
		uint32_t val = ((const uint32_t *)cfg)[reg[i].par_offset >> 2];
		drv->mmio_write_32(reg[i].reg_addr, val);
	}
}

static void ecc_enable_scrubbing(const struct umctl_drv *drv)
{
	DEBUG("Enable ECC scrubbing\n");

        /* 1.  Disable AXI port. port_en = 0 */
	mmio_clrbits_32(drv, DDR_UMCTL2_PCTRL_0, PCTRL_0_PORT_EN);

        /* 2. scrub_mode = 1 */
	mmio_setbits_32(drv, DDR_UMCTL2_SBRCTL, SBRCTL_SCRUB_MODE);

        /* 3. scrub_interval = 0 */
	mmio_clrbits_32(drv, DDR_UMCTL2_SBRCTL, SBRCTL_SCRUB_MODE);

        /* 4. Data pattern = 0 */
	drv->mmio_write_32(DDR_UMCTL2_SBRWDATA0, 0);

        /* 5. (skip) */

        /* 6. Enable SBR programming */
	mmio_setbits_32(drv, DDR_UMCTL2_SBRCTL, SBRCTL_SCRUB_EN);

        /* 7. Poll SBRSTAT.scrub_done */
	wait_reg_set(drv, DDR_UMCTL2_SBRSTAT, SBRSTAT_SCRUB_DONE, 1000);

        /* 8. Poll SBRSTAT.scrub_busy */
	wait_reg_clr(drv, DDR_UMCTL2_SBRSTAT, SBRSTAT_SCRUB_BUSY, 1000);

        /* 9. Disable SBR programming */
	mmio_clrbits_32(drv, DDR_UMCTL2_SBRCTL, SBRCTL_SCRUB_EN);
#if 0
        /* 10. Normal scrub operation, mode = 0, interval = 100 */
        wr_fld_r_r (DDR_UMCTL2, UMCTL2_MP, SBRCTL, SCRUB_MODE, 0);
        wr_fld_r_r (DDR_UMCTL2, UMCTL2_MP, SBRCTL, SCRUB_INTERVAL, 100);
        /* 11. Enable SBR progeramming again  */
        wr_fld_r_r (DDR_UMCTL2, UMCTL2_MP, SBRCTL, SCRUB_EN, 1);
#endif

        /* 12. Enable AXI port */
	mmio_setbits_32(drv, DDR_UMCTL2_PCTRL_0, PCTRL_0_PORT_EN);

	DEBUG("Enabled ECC scrubbing\n");
}

int ddr_init(const struct umctl_drv *drv, const struct ddr_config *cfg)
{

        VERBOSE("name = %s\n", cfg->info.name);
        VERBOSE("speed = %d kHz\n", cfg->info.speed);
        VERBOSE("size  = %zdM\n", cfg->info.size / 1024 / 1024);

	/* Reset, start clocks at desired speed */
	drv->reset(drv, cfg, true);

	/* Set up controller registers */
	set_regs(drv, &cfg->main, ddr_main_reg, ARRAY_SIZE(ddr_main_reg));
	set_regs(drv, &cfg->timing, ddr_timing_reg, ARRAY_SIZE(ddr_timing_reg));
	set_regs(drv, &cfg->mapping, ddr_mapping_reg, ARRAY_SIZE(ddr_mapping_reg));

	/* Release reset */
	drv->reset(drv, cfg, false);

	set_regs(drv, &cfg->phy, ddr_phy_reg, ARRAY_SIZE(ddr_phy_reg));
	set_regs(drv, &cfg->phy_timing, ddr_phy_timing_reg, ARRAY_SIZE(ddr_phy_timing_reg));

	if (cfg->main.ecccfg0 & ECCCFG0_ECC_MODE)
		ecc_enable_scrubbing(drv);

	return 0;
}
