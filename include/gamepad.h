#pragma once

#include <stdint.h>
#include <device.h>

class Gamepad : public Device
{
    uint32_t hats, buttons;

public:
    Gamepad(){};

    void setup();
    void fetch();
    void report();
};