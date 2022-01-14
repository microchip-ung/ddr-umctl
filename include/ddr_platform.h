/*
 * Copyright (C) 2021 Microchip Technology Inc. and its subsidiaries.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __DDR_PLATFORM_H
#define __DDR_PLATFORM_H

#include <stdint.h>

#if !defined(ARRAY_SIZE)
# define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))
#endif

#if !defined(DEBUG)
# define DEBUG(x...) printf(x)
#endif

#if !defined(VERBOSE)
# define VERBOSE(x...) printf(x)
#endif

#if !defined(NOTICE)
# define NOTICE(x...) printf(x)
#endif

#if !defined(BIT_32)
# if defined(BIT)
#  define BIT_32(x)	BIT(x)
# else
#  define BIT_32(x)	(1 << x)
# endif
#endif

#if !defined(GENMASK_32)
# if defined(GENMASK)
#  define GENMASK_32(h, l)	GENMASK(x)
# else
#  define GENMASK_32(h, l)	(((1 << (1 + h - l)) - 1) << l)
# endif
#endif

static inline void usleep(int usec)
{
	/* NOP */
}

typedef uint32_t ddr_timeout_t;

static inline ddr_timeout_t timeout_set_us(uint32_t val)
{
	return (ddr_timeout_t) val;
}

static inline bool timeout_elapsed(ddr_timeout_t *timeout)
{
	if (*timeout == 0)
		return true;
	--*timeout;
	return false;
}

static inline uint32_t mmio_read_32(uintptr_t addr)
{
	DEBUG("Read 0x%08lx\n", addr);
	return 0;
}

static	inline void mmio_write_32(uintptr_t addr, uint32_t val)
{
	DEBUG("Write 0x%08lx = %08x\n", addr, val);
}

static inline void mmio_setbits_32(uintptr_t addr, uint32_t set)
{
	DEBUG("Write 0x%08lx - set = %08x\n", addr, set);
	mmio_write_32(addr, mmio_read_32(addr) | set);
}

static inline void mmio_clrbits_32(uintptr_t addr, uint32_t clr)
{
	DEBUG("Write 0x%08lx - clr = %08x\n", addr, clr);
	mmio_write_32(addr, mmio_read_32(addr) & ~clr);
}

static inline void mmio_clrsetbits_32(uintptr_t addr, uint32_t clr, uint32_t set)
{
	DEBUG("Write 0x%08lx - clrset = %08x, %08x\n", addr, clr, set);
	mmio_write_32(addr, (mmio_read_32(addr) & ~clr) | set);
}

#endif /* __DDR_PLATFORM_H */
