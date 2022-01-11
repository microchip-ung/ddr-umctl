#include <stddef.h>
#include <ddr_config.h>

struct reg_desc {
        const char *name;
        uint8_t par_offset;     /* Offset for parameter array */
};

#define X(x, y)								\
        {                                               		\
                .name = #x,                             		\
		.par_offset = offsetof(struct config_ddr_##y, x),	\
        },

static const struct reg_desc ddr_reg[] = {
XLIST_DDR_MAIN
};

int ddr_init(void)
{
	return 0;
}
