/*
 * Copyright (C) 2021 Microchip Technology Inc. and its subsidiaries.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stddef.h>
#include <stdio.h>
#include <ddr_init.h>

struct umctl_drv drv = {};
const struct ddr_config cfg = {};

static	uint32_t mmio_read_32(uintptr_t addr)
{
	return 0;
}

static	void     mmio_write_32(uintptr_t addr, uint32_t val)
{
	DEBUG("Write 0x%08lx = %08x\n", addr, val);
}

static	void     mmio_setbits_32(uintptr_t addr, uint32_t val)
{
	DEBUG("Write 0x%08lx - set = %08x\n", addr, val);
}

static	void     mmio_clrbits_32(uintptr_t addr, uint32_t val)
{
	DEBUG("Write 0x%08lx - clr = %08x\n", addr, val);
}

static	void     mmio_clrsetbits_32(uintptr_t addr, uint32_t clr, uint32_t set)
{
	DEBUG("Write 0x%08lx - clrset = %08x, %08x\n", addr, clr, set);
}

int main(int argc, char **argv)
{
	drv.mmio_read_32 = mmio_read_32;
	drv.mmio_write_32 = mmio_write_32;
	drv.mmio_setbits_32 = mmio_setbits_32;
	drv.mmio_clrbits_32 = mmio_clrbits_32;
	drv.mmio_clrsetbits_32 = mmio_clrsetbits_32;
	return ddr_init(&drv, &cfg);
}
