#pragma once

#include <stdint.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "config.h"

namespace iolib
{
    inline void sleep(uint32_t ms)
    {
        sleep_ms(ms);
    }

    inline void sleep_us(uint32_t us)
    {
        sleep_us(us);
    }
}