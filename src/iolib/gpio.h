#pragma once

#include <stdint.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "config.h"

namespace iolib
{
    enum gpio_dir
    {
        GPIO_INPUT = GPIO_IN,
        GPIO_OUTPUT = GPIO_OUT
    };

    enum gpio_level
    {
        GPIO_LOW = 0,
        GPIO_HIGH = 1
    };

    inline void init() // Initialize the GPIO
    {
        stdio_init_all();
    }
    inline void setup() // Setup led pins etc.
    {
        gpio_init(LED_BUILTIN);
        gpio_set_dir(LED_BUILTIN, GPIO_OUTPUT);
    }
    inline void gpio_mode(uint gpio, iolib::gpio_dir dir) // Initialize a GPIO pin
    {
        gpio_init(gpio);
        gpio_set_dir(gpio, dir);
    }
    inline void set_gpio(uint gpio, iolib::gpio_level value) // Set a GPIO pin to a value
    {
        gpio_put(gpio, value);
    }
}