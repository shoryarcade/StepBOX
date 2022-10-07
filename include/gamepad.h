#pragma once

#include <stdint.h>
#include "device.h"

#define BUTTON_UP GAMEPAD_HAT_UP
#define BUTTON_DOWN GAMEPAD_HAT_DOWN
#define BUTTON_LEFT GAMEPAD_HAT_LEFT
#define BUTTON_RIGHT GAMEPAD_HAT_RIGHT

#define BUTTON_01 GAMEPAD_BUTTON_0
#define BUTTON_02 GAMEPAD_BUTTON_1
#define BUTTON_03 GAMEPAD_BUTTON_2
#define BUTTON_04 GAMEPAD_BUTTON_3
#define BUTTON_05 GAMEPAD_BUTTON_4
#define BUTTON_06 GAMEPAD_BUTTON_5
#define BUTTON_07 GAMEPAD_BUTTON_6
#define BUTTON_08 GAMEPAD_BUTTON_7
#define BUTTON_09 GAMEPAD_BUTTON_8
#define BUTTON_10 GAMEPAD_BUTTON_9
#define BUTTON_11 GAMEPAD_BUTTON_10
#define BUTTON_12 GAMEPAD_BUTTON_11
#define BUTTON_13 GAMEPAD_BUTTON_12

#define BUTTON_TOUCH GAMEPAD_BUTTON_13
#define BUTTON_SHARE GAMEPAD_BUTTON_14
#define BUTTON_SELECT GAMEPAD_BUTTON_15
#define BUTTON_START GAMEPAD_BUTTON_16

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

    bool pressedTouch();
    bool pressedShare();
    bool pressedSelect();
    bool pressedStart();
};