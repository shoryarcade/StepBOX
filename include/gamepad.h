#pragma once

#include <stdint.h>
#include <map>
#include "device.h"
#include "encoder.hpp"

using namespace std;
using namespace encoder;

#define GAMEPAD_NUMBER_OF_HATS 4
#define GAMEPAD_NUMBER_OF_BUTTONS 17

#define BUTTON_UP GAMEPAD_HAT_UP
#define BUTTON_DOWN GAMEPAD_HAT_DOWN
#define BUTTON_LEFT GAMEPAD_HAT_LEFT
#define BUTTON_RIGHT GAMEPAD_HAT_RIGHT

#define STICK1_UP GAMEPAD_BUTTON_Y
#define STICK1_DOWN GAMEPAD_BUTTON_Y
#define STICK1_LEFT GAMEPAD_BUTTON_X
#define STICK1_RIGHT GAMEPAD_BUTTON_X

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

// clang-format off
#define HID_REPORT_DESCRIPTION_GAMEPAD(...) \
  HID_USAGE_PAGE ( HID_USAGE_PAGE_DESKTOP     )                 ,\
  HID_USAGE      ( HID_USAGE_DESKTOP_GAMEPAD  )                 ,\
  HID_COLLECTION ( HID_COLLECTION_APPLICATION )                 ,\
    /* Report ID if any */\
    __VA_ARGS__ \
    /* 8 bit X, Y, Z, Rz, Rx, Ry (min -127, max 127 ) */ \
    HID_USAGE_PAGE   ( HID_USAGE_PAGE_DESKTOP                 ) ,\
    HID_USAGE        ( HID_USAGE_DESKTOP_X                    ) ,\
    HID_USAGE        ( HID_USAGE_DESKTOP_Y                    ) ,\
    HID_USAGE        ( HID_USAGE_DESKTOP_Z                    ) ,\
    HID_USAGE        ( HID_USAGE_DESKTOP_RZ                   ) ,\
    HID_USAGE        ( HID_USAGE_DESKTOP_RX                   ) ,\
    HID_USAGE        ( HID_USAGE_DESKTOP_RY                   ) ,\
    HID_LOGICAL_MIN  ( 0x81                                   ) ,\
    HID_LOGICAL_MAX  ( 0x7f                                   ) ,\
    HID_REPORT_COUNT ( 6                                      ) ,\
    HID_REPORT_SIZE  ( 8                                      ) ,\
    HID_INPUT        ( HID_DATA | HID_VARIABLE | HID_ABSOLUTE ) ,\
    /* 8 bit DPad/Hat Button Map  */ \
    HID_USAGE_PAGE   ( HID_USAGE_PAGE_DESKTOP                 ) ,\
    HID_USAGE        ( HID_USAGE_DESKTOP_HAT_SWITCH           ) ,\
    HID_LOGICAL_MIN  ( 1                                      ) ,\
    HID_LOGICAL_MAX  ( 8                                      ) ,\
    HID_PHYSICAL_MIN ( 0                                      ) ,\
    HID_PHYSICAL_MAX_N ( 315, 2                               ) ,\
    HID_REPORT_COUNT ( 1                                      ) ,\
    HID_REPORT_SIZE  ( 8                                      ) ,\
    HID_INPUT        ( HID_DATA | HID_VARIABLE | HID_ABSOLUTE ) ,\
    /* 16 bit Button Map */ \
    HID_USAGE_PAGE   ( HID_USAGE_PAGE_BUTTON                  ) ,\
    HID_USAGE_MIN    ( 1                                      ) ,\
    HID_USAGE_MAX    ( GAMEPAD_NUMBER_OF_BUTTONS              ) ,\
    HID_LOGICAL_MIN  ( 0                                      ) ,\
    HID_LOGICAL_MAX  ( 1                                      ) ,\
    HID_REPORT_COUNT ( 32                                     ) ,\
    HID_REPORT_SIZE  ( 1                                      ) ,\
    HID_INPUT        ( HID_DATA | HID_VARIABLE | HID_ABSOLUTE ) ,\
  HID_COLLECTION_END \
// clang-format on


class Gamepad : public Device
{
    int8_t horizontal, vertical;
    uint32_t hats, buttons;
    Encoder *enc_l, *enc_r;

public:
    Gamepad(){};

    bool alive();
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