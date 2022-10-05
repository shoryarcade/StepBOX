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

    bool pressedButton(uint32_t button);

    bool pressedUp();
    bool pressedDown();
    bool pressedLeft();
    bool pressedRight();

    bool pressedB1();
    bool pressedB2();
    bool pressedB3();
    bool pressedB4();
    bool pressedB5();
    bool pressedB6();
    bool pressedB7();
    bool pressedB8();
    bool pressedB9();
    bool pressedB10();
    bool pressedB11();
    bool pressedB12();
    bool pressedB13();
    bool pressedB14();
    bool pressedB15();
    bool pressedB16();

    bool pressedB17();
    bool pressedB18();
    bool pressedB19();
    bool pressedB20();
    bool pressedB21();
    bool pressedB22();
    bool pressedB23();
    bool pressedB24();
    bool pressedB25();
    bool pressedB26();
    bool pressedB27();
    bool pressedB28();
    bool pressedB29();
    bool pressedB30();
    bool pressedB31();
    bool pressedB32();
};