// rp2040 led blink

#include <stdio.h>
#include <stdint.h>

#include "iolib/gpio.h"
#include "iolib/utils.h"
#include "config.h"

int main()
{
    iolib::init();
    iolib::setup();

    while (true)
    {
        iolib::set_gpio(LED_BUILTIN, iolib::GPIO_HIGH);
        iolib::sleep(1000);
        iolib::set_gpio(LED_BUILTIN, iolib::GPIO_LOW);
        iolib::sleep(1000);
    }

    return 0;
}