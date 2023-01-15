#pragma once

namespace ws2812b
{
    uint32_t rgb(uint8_t r, uint8_t g, uint8_t b);

    class Led
    {
    private:
        PIO pio;
        int sm, pin, length;

    public:
        Led(PIO pio, int sm, int pin, int length);

        void reset();
        void putPixel(uint32_t rgb);
    };

}