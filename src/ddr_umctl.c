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

static bool wait_reg_set(uintptr_t reg, uint32_t mask, int usec)
{
	ddr_timeout_t t = timeout_set_us(usec);
	while ((mmio_read_32(reg) & mask) == 0) {
		if (timeout_elapsed(&t)) {
			VERBOSE("Timeout waiting for %p mask %08x set\n", (void*)reg, mask);
			return true;
		}
	}
	return false;
}

static bool wait_reg_clr(uintptr_t reg, uint32_t mask, int usec)
{
	ddr_timeout_t t = timeout_set_us(usec);
	while ((mmio_read_32(reg) & mask) != 0) {
		if (timeout_elapsed(&t)) {
			VERBOSE("Timeout waiting for %p mask %08x clr\n", (void*)reg, mask);
			return true;
		}
	}
	return false;
}

static void wait_operating_mode(uint32_t mode, int usec)
{
	ddr_timeout_t t = timeout_set_us(usec);
	while ((FIELD_GET(STAT_OPERATING_MODE,
			  mmio_read_32(DDR_UMCTL2_STAT))) != mode) {
		if (timeout_elapsed(&t)) {
			VERBOSE("Timeout waiting for mode %d\n", mode);
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

static void set_static_ctl(void)
{
	mmio_write_32(DDR_UMCTL2_RFSHCTL1,
		      FIELD_PREP(RFSHCTL1_REFRESH_TIMER0_START_VALUE_X32, 0x20) |
		      FIELD_PREP(RFSHCTL1_REFRESH_TIMER1_START_VALUE_X32, 0x40));
	mmio_clrsetbits_32(DDR_UMCTL2_RANKCTL,
			   RANKCTL_DIFF_RANK_RD_GAP | RANKCTL_DIFF_RANK_WR_GAP,
			   FIELD_PREP(RANKCTL_DIFF_RANK_RD_GAP, 2) |
			   FIELD_PREP(RANKCTL_DIFF_RANK_WR_GAP, 2));
	/* Disabling update request initiated by DDR controller during
	 * DDR initialization */
	mmio_setbits_32(DDR_UMCTL2_DFIUPD0,
			DFIUPD0_DIS_AUTO_CTRLUPD_SRX | DFIUPD0_DIS_AUTO_CTRLUPD);
}

static void set_static_phy(const struct ddr_config *cfg)
{
	mmio_clrsetbits_32(DDR_PHY_PGCR1,
			   PGCR1_IODDRM,
			   FIELD_PREP(PGCR1_IODDRM, 1));
	mmio_clrsetbits_32(DDR_PHY_PGCR7,
			   PGCR7_WRPSTEX,
			   FIELD_PREP(PGCR7_WRPSTEX, 1));
	/* Disabling PHY initiated update request during DDR
	 * initialization */
	mmio_clrbits_32(DDR_PHY_DSGCR, DSGCR_PUREN);
	// # Disable un-used byte lanes by writing DXnGCR0[0] = 1'b0 (DXEN).
	if (cfg->info.dq_bits_used == 32) {
		mmio_clrbits_32(DDR_PHY_DX4GCR0, DX4GCR0_DXEN);
	} else if (cfg->info.dq_bits_used == 16) {
		mmio_clrbits_32(DDR_PHY_DX2GCR0, DX2GCR0_DXEN);
		mmio_clrbits_32(DDR_PHY_DX3GCR0, DX3GCR0_DXEN);
		mmio_clrbits_32(DDR_PHY_DX4GCR0, DX4GCR0_DXEN);
	}

	/* To capture valid read data for rank0 */
	mmio_clrsetbits_32(DDR_PHY_RANKIDR, RANKIDR_RANKWID,
			   FIELD_PREP(RANKIDR_RANKWID, 0));
#define SET_DGSEL(n)							\
	mmio_clrsetbits_32(DDR_PHY_DX ## n ## GTR0, DX ## n ## GTR0_DGSL, \
			   FIELD_PREP(DX ## n ## GTR0_DGSL, 0x2))
	SET_DGSEL(0);
	SET_DGSEL(1);
	SET_DGSEL(2);
	SET_DGSEL(3);
	SET_DGSEL(4);

	/* To capture valid read data for rank1 */
	mmio_clrsetbits_32(DDR_PHY_RANKIDR, RANKIDR_RANKWID,
			   FIELD_PREP(RANKIDR_RANKWID, 1));
	SET_DGSEL(0);
	SET_DGSEL(1);
	SET_DGSEL(2);
	SET_DGSEL(3);
	SET_DGSEL(4);
#undef SET_DGSEL

	/* VREF IO control register */
	mmio_setbits_32(DDR_PHY_IOVCR0,
			IOVCR0_ACVREFIEN | IOVCR0_ACVREFSEN | IOVCR0_ACVREFPEN);
	mmio_setbits_32(DDR_PHY_IOVCR1, IOVCR1_ZQVREFPEN);
}

static void ecc_enable_scrubbing(const struct umctl_drv *drv)
{
	TRACE("Enable ECC scrubbing\n");

        /* 1.  Disable AXI port. port_en = 0 */
	mmio_clrbits_32(DDR_UMCTL2_PCTRL_0, PCTRL_0_PORT_EN);

        /* 2. scrub_mode = 1 */
	mmio_setbits_32(DDR_UMCTL2_SBRCTL, SBRCTL_SCRUB_MODE);

        /* 3. scrub_interval = 0 */
	mmio_clrbits_32(DDR_UMCTL2_SBRCTL, SBRCTL_SCRUB_INTERVAL);

        /* 4. Data pattern = 0 */
	mmio_write_32(DDR_UMCTL2_SBRWDATA0, 0);

        /* 5. (skip) */

        /* 6. Enable SBR programming */
	mmio_setbits_32(DDR_UMCTL2_SBRCTL, SBRCTL_SCRUB_EN);

        /* 7. Poll SBRSTAT.scrub_done */
	if (wait_reg_set(DDR_UMCTL2_SBRSTAT, SBRSTAT_SCRUB_DONE, 10000))
		PANIC("Timeout SBRSTAT.scrub_done set");

        /* 8. Poll SBRSTAT.scrub_busy */
	if (wait_reg_clr(DDR_UMCTL2_SBRSTAT, SBRSTAT_SCRUB_BUSY, 10000))
		PANIC("Timeout SBRSTAT.scrub_busy clear");

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

static void phy_fifo_reset(void)
{
	mmio_clrbits_32(DDR_PHY_PGCR0, PGCR0_PHYFRST);
	usleep(1);
	mmio_setbits_32(DDR_PHY_PGCR0, PGCR0_PHYFRST);
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
	/* PHY initialization: PLL initialization, Delay line
	 * calibration, PHY reset and Impedance Calibration
	 */
	ddr_phy_init(drv, PIR_ZCAL | PIR_PLLINIT | PIR_DCAL | PIR_PHYRST);
}

static void DRAM_initialization_by_memctrl(const struct umctl_drv *drv)
{
	/* write PHY initialization register for SDRAM initialization */
	ddr_phy_init(drv, PIR_CTLDINIT);
}

static void sw_done_start(void)
{
	/* Enter quasi-dynamic mode */
	mmio_write_32(DDR_UMCTL2_SWCTL, 0);
}

static void sw_done_ack(void)
{
	TRACE("sw_done_ack:enter\n");

	/* Signal we're done */
	mmio_write_32(DDR_UMCTL2_SWCTL, SWCTL_SW_DONE);

	/* wait for SWSTAT.sw_done_ack to become set */
	if (wait_reg_set(DDR_UMCTL2_SWSTAT, SWSTAT_SW_DONE_ACK, 100))
		PANIC("Timout SWSTAT.sw_done_ack set");

	TRACE("sw_done_ack:exit\n");
}

static void ddr_disable_refresh(const struct umctl_drv *drv)
{
	sw_done_start();
	mmio_setbits_32(DDR_UMCTL2_RFSHCTL3, RFSHCTL3_DIS_AUTO_REFRESH);
	mmio_clrbits_32(DDR_UMCTL2_PWRCTL, PWRCTL_POWERDOWN_EN);
	mmio_clrbits_32(DDR_UMCTL2_DFIMISC, DFIMISC_DFI_INIT_COMPLETE_EN);
	sw_done_ack();
}

static void ddr_restore_refresh(const struct umctl_drv *drv, uint32_t rfshctl3)
{
	sw_done_start();
	if ((rfshctl3 & RFSHCTL3_DIS_AUTO_REFRESH) == 0)
		mmio_clrbits_32(DDR_UMCTL2_RFSHCTL3, RFSHCTL3_DIS_AUTO_REFRESH);
	if (rfshctl3 & PWRCTL_POWERDOWN_EN)
		mmio_setbits_32(DDR_UMCTL2_PWRCTL, PWRCTL_POWERDOWN_EN);
	mmio_setbits_32(DDR_UMCTL2_DFIMISC, DFIMISC_DFI_INIT_COMPLETE_EN);
	sw_done_ack();
}

static void VREF_Training_Setup(void)
{
	/* Disable refresh during training */
	mmio_clrbits_32(DDR_PHY_DTCR0, DTCR0_RFSHDT);
	/* Program user programmable data pattern */
	mmio_write_32(DDR_PHY_BISTUDPR, 0xA5A5A5A5);
	/* Program BIST address registers BISTAR0-4 to define the
	 * memory location used during VREF training
	 */
	/* BIST Col 16/64/256/512, BIST Bank 0-3 */
	mmio_write_32(DDR_PHY_BISTAR0,
		      FIELD_PREP(BISTAR0_BCOL, 16) |
		      FIELD_PREP(BISTAR0_BBANK, 0));
	/* BIST Addr Inc 32/128/256/512 */
	mmio_clrsetbits_32(DDR_PHY_BISTAR1, BISTAR1_BAINC,
			   FIELD_PREP(BISTAR1_BAINC, 0));
	/* BIST Row 0-15 */
	mmio_clrsetbits_32(DDR_PHY_BISTAR3, BISTAR3_BROW,
			   FIELD_PREP(BISTAR3_BROW, 0));
	/* Program HOST VREF initial setting to approx. 76.25% of VDDQ */
#define DEF_REFISEL 0x19
#define SET_REFISEL(n) \
	mmio_clrsetbits_32(DDR_PHY_DX ## n ## GCR5, DX ## n ## GCR5_DXREFISELR0, \
			   FIELD_PREP(DX ## n ## GCR5_DXREFISELR0, DEF_REFISEL))
	SET_REFISEL(0);
	SET_REFISEL(1);
	SET_REFISEL(2);
	SET_REFISEL(3);
	SET_REFISEL(4);
#undef SET_REFISEL
	mmio_clrsetbits_32(DDR_PHY_VTCR0, VTCR0_DVINIT,
			   FIELD_PREP(VTCR0_DVINIT, DEF_REFISEL));
#undef DEF_REFISEL
	mmio_clrsetbits_32(DDR_PHY_VTCR1,
			   VTCR1_ENUM | VTCR1_HVSS | VTCR1_VWCR,
			   VTCR1_ENUM | FIELD_PREP(VTCR1_HVSS, 1) | FIELD_PREP(VTCR1_VWCR, 0xF));
}

static void do_data_training(const struct umctl_drv *drv, const struct ddr_config *cfg)
{
	bool ddr4 = !!(cfg->main.mstr & MSTR_DDR4);
	uint32_t w, m;

	TRACE("do_data_training:enter\n");

	/* Disable Auto refresh and power down before training */
	ddr_disable_refresh(drv);

	/* Write leveling, DQS gate training, Write_latency adjustment must be executed in
	 * asynchronous read mode. After these training are finished, then static read mode
	 * can be set and rest of the training can be executed with a second PIR register.
	 */

	/* By default asynchronous read mode is set : PGCR3.RDMODE = 2'b00 */
	w = mmio_read_32(DDR_PHY_PGCR3);
	if (FIELD_GET(PGCR3_RDMODE, w) != 0) {
		DEBUG("pgcr3: %08x\n", w);
		PANIC("RDMODE not zero");
	}

	/* As per PUB databook (page no. 601), it is recommended to
	 * seed appropriate group of BDLs with a value of x4 or x8
	 * prior to the execution of the data training
	 */
	mmio_write_32(DDR_PHY_DX0BDLR0, 0x08080808);
	mmio_write_32(DDR_PHY_DX0BDLR1, 0x08080808);
	mmio_write_32(DDR_PHY_DX0BDLR2, 0x080808);
	mmio_write_32(DDR_PHY_DX1BDLR0, 0x08080808);
	mmio_write_32(DDR_PHY_DX1BDLR1, 0x08080808);
	mmio_write_32(DDR_PHY_DX1BDLR2, 0x080808);
	if (cfg->info.dq_bits_used == 32 || cfg->info.dq_bits_used == 40) {
		mmio_write_32(DDR_PHY_DX2BDLR0, 0x08080808);
		mmio_write_32(DDR_PHY_DX2BDLR1, 0x08080808);
		mmio_write_32(DDR_PHY_DX2BDLR2, 0x080808);
		mmio_write_32(DDR_PHY_DX3BDLR0, 0x08080808);
		mmio_write_32(DDR_PHY_DX3BDLR1, 0x08080808);
		mmio_write_32(DDR_PHY_DX3BDLR2, 0x080808);
	}
	if (cfg->info.dq_bits_used == 40) {
		mmio_write_32(DDR_PHY_DX4BDLR0, 0x08080808);
		mmio_write_32(DDR_PHY_DX4BDLR1, 0x08080808);
		mmio_write_32(DDR_PHY_DX4BDLR2, 0x080808);
	}

	/* PHY FIFO reset (???) */
	phy_fifo_reset();

	/* write PHY initialization register for Write leveling, DQS
	 * gate training, Write_latency adjustment
	 */
	ddr_phy_init(drv,  PIR_WL | PIR_QSGATE | PIR_WLADJ);

	/* Static read training must be performed in static read mode.
	 * read/write bit Deskew, read/write Eye Centering training,
	 * VREF training can be performed in static read mode or
	 * asynchronous read mode.
	 */
	mmio_clrsetbits_32(DDR_PHY_PGCR3, PGCR3_RDMODE,
			   FIELD_PREP(PGCR3_RDMODE, 1)); /* XXX: PGCR3.RDMODE = 2'b011 ??? */

	/* Now, actual data training */
	w = PIR_SRD | PIR_WREYE | PIR_RDEYE | PIR_WRDSKW | PIR_RDDSKW;
	if (ddr4) {
		/* VREF training as well */
		w |= PIR_VREF;
		VREF_Training_Setup();
	}
	ddr_phy_init(drv, w);

	w = mmio_read_32(DDR_PHY_PGSR0);
	m = GENMASK_32(11, 0) | PGSR0_SRDDONE | PGSR0_APLOCK; /* *DONE ex CADONE, VDONE */
	if (ddr4)
		m |= PGSR0_VDONE;
	if ((w & m) != m) {
		VERBOSE("pgsr0: got %08x, want %08x\n", w, m);
		PANIC("data training error");
	}

	ddr_restore_refresh(drv, cfg->main.rfshctl3);

	/* Reenabling uMCTL2 initiated update request after executing
	 * DDR initization. Reference: DDR4 MultiPHY PUB databook
	 * (3.11a) PIR.INIT description (pg no. 114)
	 */
	sw_done_start();
	mmio_clrbits_32(DDR_UMCTL2_DFIUPD0, DFIUPD0_DIS_AUTO_CTRLUPD);
	sw_done_ack();

	/* Reenabling PHY update Request after executing DDR
	 * initization. Reference: DDR4 MultiPHY PUB databook (3.11a)
	 * PIR.INIT description (pg no. 114)
	 */
	mmio_setbits_32(DDR_PHY_DSGCR, DSGCR_PUREN);

	/* Enable AXI port */
	mmio_setbits_32(DDR_UMCTL2_PCTRL_0, PCTRL_0_PORT_EN);

	/* Settle */
	usleep(10);

	TRACE("do_data_training:exit\n");
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

	/* Static controller settings */
	set_static_ctl();

	/* Release reset */
	drv->reset(drv, cfg, false);

	usleep(10);

	/* Set PHY registers */
	set_regs(&cfg->phy, ddr_phy_reg, ARRAY_SIZE(ddr_phy_reg));
	set_regs(&cfg->phy_timing, ddr_phy_timing_reg, ARRAY_SIZE(ddr_phy_timing_reg));

	/* Static PHY settings */
	set_static_phy(cfg);

	/* PHY FIFO reset (???) */
	phy_fifo_reset();

	PHY_initialization(drv);

	DRAM_initialization_by_memctrl(drv);

	/* Start quasi-dynamic programming */
	sw_done_start();

	/* PHY initialization complete enable: trigger SDRAM initialisation */
	mmio_setbits_32(DDR_UMCTL2_DFIMISC, DFIMISC_DFI_INIT_COMPLETE_EN);

	/* Signal quasi-dynamic phase end, await ack */
	sw_done_ack();

	/* wait for STAT.operating_mode to become "normal" */
	wait_operating_mode(1, 100);

	do_data_training(drv, cfg);

	if (cfg->main.ecccfg0 & ECCCFG0_ECC_MODE)
		ecc_enable_scrubbing(drv);

	TRACE("ddr_init:done\n");

	return 0;
}
