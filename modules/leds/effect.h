#pragma once

#include <string>

#include "effect.h"
#include "ws2812b.hpp"

using namespace ws2812b;

class Effect
{
protected:
    Led *led;

public:
    Effect(Led *led)
    {
        this->led = led;
    };

    virtual void show(uint32_t *counter, uint8_t start, uint8_t end, string color) = 0;
};