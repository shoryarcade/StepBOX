#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"

#include "ws2812b.hpp"
#include "ws2812b.pio.h"

#define LED_CLOCK_RATE 800000

namespace ws2812b
{

    uint32_t rgb(uint8_t r, uint8_t g, uint8_t b)
    {
        return ((uint32_t)(r) << 8) |
               ((uint32_t)(g) << 16) |
               (uint32_t)(b);
    }

    Led::Led(PIO pio, int sm, int pin, int length)
    {
        this->pio = pio;
        this->sm = sm;
        this->pin = pin;
        this->length = length;

        stdio_init_all();

        uint offset = pio_add_program(pio, &ws2812_program);
        ws2812_program_init(this->pio, this->sm, offset, this->pin, LED_CLOCK_RATE, false);

        this->reset();
    };

    void Led::putPixel(uint32_t rgb)
    {
        pio_sm_put_blocking(this->pio, this->sm, rgb << 8u);
    }

    void Led::reset()
    {
        for (int i = 0; i < this->length; i++)
            this->putPixel(rgb(0, 0, 0));
    }

}