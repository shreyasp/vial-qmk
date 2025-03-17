/* keyboards/gmmk/gmmk3/p65/ansi/keymaps/vial/mcuconf.h */
#pragma once

#include_next <mcuconf.h>

#undef WB32_SPI_USE_QSPI
#define WB32_SPI_USE_QSPI TRUE

#undef WB32_SPI_USE_SPIM2
#define WB32_SPI_USE_SPIM2 TRUE
