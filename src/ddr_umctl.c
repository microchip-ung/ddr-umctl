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

static const struct reg_desc ddr_reg[] = {
XLIST_DDR_MAIN
};

static void set_regs(const struct umctl_drv *drv,
		     const void *cfg,
		     const struct reg_desc *reg,
		     size_t ct)
{
	int i;

	DEBUG("In %s\n", __FUNCTION__);

	for (i = 0; i < ct; i++) {
		uint32_t val = ((const uint32_t *)cfg)[reg[i].par_offset >> 2];
		drv->mmio_write_32(reg[i].reg_addr, val);
	}
}

int ddr_init(const struct umctl_drv *drv, const struct ddr_config *cfg)
{
	set_regs(drv, &cfg->main, ddr_reg, ARRAY_SIZE(ddr_reg));

	return 0;
}
