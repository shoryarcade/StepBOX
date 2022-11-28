#pragma once

#include <stdint.h>
#include "device.h"

class Keyboard : public Device
{
    uint8_t keycode[6] = {0};

    bool pressedB1;
    bool pressedB2;
    bool pressedB3;
    bool pressedB4;
    bool pressedB5;
    bool pressedB6;
    bool pressedB7;
    bool pressedB8;
    bool pressedB9;
    bool pressedB10;
    bool pressedB11;
    bool pressedB12;
    bool pressedB13;

    bool pressedTouch;
    bool pressedShare;
    bool pressedSelect;
    bool pressedStart;

    bool pressedUp;
    bool pressedDown;
    bool pressedLeft;
    bool pressedRight;
    // clang-format off

public:
    Keyboard(){};

    bool alive();
    void setup();
    void fetch();
    void report();
};
