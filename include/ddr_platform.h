/*
 * Copyright (C) 2021 Microchip Technology Inc. and its subsidiaries.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __DDR_PLATFORM_H
#define __DDR_PLATFORM_H

#include <stdint.h>

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

#endif /* __DDR_PLATFORM_H */
