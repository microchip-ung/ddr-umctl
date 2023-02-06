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

#include <common.h>

extern const struct ddr_config pcb134_ddr4_ddr_config;
extern const struct ddr_config pcb135_ddr3_ddr_config;

#if defined(STANDALONE)
static bool pcb134 = true;
int main(int argc, char **argv)
#else
int ddr_setup(bool pcb134)
#endif
{
	const struct ddr_config *cfg = pcb134 ? &pcb134_ddr4_ddr_config : &pcb135_ddr3_ddr_config;
	return ddr_init(cfg);
}
