/*
 * Copyright (C) 2021 Microchip Technology Inc. and its subsidiaries.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __DDR_PLATFORM_H
#define __DDR_PLATFORM_H

#include <assert.h>
#include <stdint.h>
#include <stdarg.h>

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

#if !defined(TRACE)
# define TRACE(s) puts(s)
#endif

#if !defined(PANIC)
# define PANIC(s...) _panic(s)
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
#  define GENMASK_32(h, l)	GENMASK(h, l)
# else
#  define GENMASK_32(h, l)	(((1 << (1 + h - l)) - 1) << l)
# endif
#endif

static inline void _panic(char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	vprintf(fmt, ap);
	va_end(ap);
	assert(false);
}

static inline void ddr_nsleep(int nsec)
{
	/* NOP */
}

static inline void ddr_usleep(int usec)
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

#if !defined(FIELD_PREP)
#define __bf_shf(x) (__builtin_ffsll(x) - 1)
#define FIELD_PREP(_mask, _val)						\
	({								\
		((typeof(_mask))(_val) << __bf_shf(_mask)) & (_mask);	\
	})
#endif

#if !defined(FIELD_GET)
#define FIELD_GET(_mask, _reg)                                          \
        ({                                                              \
                (typeof(_mask))(((_reg) & (_mask)) >> __bf_shf(_mask)); \
        })
#endif

#endif /* __DDR_PLATFORM_H */
