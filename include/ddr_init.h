/*
 * Copyright (C) 2021 Microchip Technology Inc. and its subsidiaries.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _DDR_INIT_H
#define _DDR_INIT_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <ddr_config.h>

#if !defined(ARRAY_SIZE)
#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))
#endif

#if !defined(DEBUG)
#define DEBUG(x...) printf(x)
#endif

struct umctl_drv {
	uint32_t (*mmio_read_32)      (uintptr_t addr);
	void     (*mmio_write_32)     (uintptr_t addr, uint32_t val);
	void     (*timeout_set_us)    (uint32_t val);
	bool     (*timeout_elapsed)   (void);
};

int ddr_init(const struct umctl_drv *drv, const struct ddr_config *cfg);

#endif /* _DDR_INIT_H */
