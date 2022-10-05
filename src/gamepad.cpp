#include "stepbox.h"
#include "gamepad.h"

#include "tusb.h"
#include "pico/stdlib.h"

void Gamepad::setup()
{
    for (int pin = 0; pin < GAMEPAD_NUMBER_OF_PINS; pin++)
    {
        gpio_init(pin);
        gpio_set_dir(pin, GPIO_IN);
        gpio_pull_up(pin);
    }
}

void Gamepad::fetch()
{
    // clang-format off
    uint32_t values = ~gpio_get_all();

    hats = 0
        | ((values & (1 << 21) ? GAMEPAD_HAT_UP : 0))
        | ((values & (1 << 20) ? GAMEPAD_HAT_LEFT : 0))
        | ((values & (1 << 19) ? GAMEPAD_HAT_RIGHT : 0))
        | ((values & (1 << 18) ? GAMEPAD_HAT_DOWN : 0))
    ;

    buttons = 0
        | ((values & (1 << 0) ? GAMEPAD_BUTTON_0 : 0))
        | ((values & (1 << 1) ? GAMEPAD_BUTTON_1 : 0))
        | ((values & (1 << 2) ? GAMEPAD_BUTTON_2 : 0))
        | ((values & (1 << 3) ? GAMEPAD_BUTTON_3 : 0))
        | ((values & (1 << 4) ? GAMEPAD_BUTTON_4 : 0))
        | ((values & (1 << 5) ? GAMEPAD_BUTTON_5 : 0))
        | ((values & (1 << 6) ? GAMEPAD_BUTTON_6 : 0))
        | ((values & (1 << 7) ? GAMEPAD_BUTTON_7 : 0))
        | ((values & (1 << 8) ? GAMEPAD_BUTTON_8 : 0))
        | ((values & (1 << 9) ? GAMEPAD_BUTTON_9 : 0))
        | ((values & (1 << 10) ? GAMEPAD_BUTTON_10 : 0))
        | ((values & (1 << 11) ? GAMEPAD_BUTTON_11 : 0))
        | ((values & (1 << 12) ? GAMEPAD_BUTTON_12 : 0))
        | ((values & (1 << 13) ? GAMEPAD_BUTTON_13 : 0))
        | ((values & (1 << 14) ? GAMEPAD_BUTTON_14 : 0))
        | ((values & (1 << 15) ? GAMEPAD_BUTTON_15 : 0))
        | ((values & (1 << 16) ? GAMEPAD_BUTTON_16 : 0))
    ;
    // clang-format on
}

void Gamepad::report()
{
    if (!tud_hid_ready())
        return;

    hid_gamepad_report_t report =
        {
            .x = 0,
            .y = 0,
            .z = 0,
            .rz = 0,
            .rx = 0,
            .ry = 0,
            .hat = 0,
            .buttons = 0};

    report.hat = hats;
    report.buttons = buttons;

    tud_hid_report(1, &report, sizeof(report));
}

bool Gamepad::pressedButton(uint32_t button)
{
    return ((buttons & button) == button || (hats & button) == button);
}

// clang-format off
bool Gamepad::pressedUp()    { return pressedButton(GAMEPAD_HAT_UP);    }
bool Gamepad::pressedDown()  { return pressedButton(GAMEPAD_HAT_DOWN);  }
bool Gamepad::pressedLeft()  { return pressedButton(GAMEPAD_HAT_LEFT);  }
bool Gamepad::pressedRight() { return pressedButton(GAMEPAD_HAT_RIGHT); }

bool Gamepad::pressedB1()    { return pressedButton(GAMEPAD_BUTTON_0);  }
bool Gamepad::pressedB2()    { return pressedButton(GAMEPAD_BUTTON_1);  }
bool Gamepad::pressedB3()    { return pressedButton(GAMEPAD_BUTTON_2);  }
bool Gamepad::pressedB4()    { return pressedButton(GAMEPAD_BUTTON_3);  }
bool Gamepad::pressedB5()    { return pressedButton(GAMEPAD_BUTTON_4);  }
bool Gamepad::pressedB6()    { return pressedButton(GAMEPAD_BUTTON_5);  }
bool Gamepad::pressedB7()    { return pressedButton(GAMEPAD_BUTTON_6);  }
bool Gamepad::pressedB8()    { return pressedButton(GAMEPAD_BUTTON_7);  }
bool Gamepad::pressedB9()    { return pressedButton(GAMEPAD_BUTTON_8);  }
bool Gamepad::pressedB10()   { return pressedButton(GAMEPAD_BUTTON_9);  }
bool Gamepad::pressedB11()   { return pressedButton(GAMEPAD_BUTTON_10); }
bool Gamepad::pressedB12()   { return pressedButton(GAMEPAD_BUTTON_11); }
bool Gamepad::pressedB13()   { return pressedButton(GAMEPAD_BUTTON_12); }
bool Gamepad::pressedB14()   { return pressedButton(GAMEPAD_BUTTON_13); }
bool Gamepad::pressedB15()   { return pressedButton(GAMEPAD_BUTTON_14); }
bool Gamepad::pressedB16()   { return pressedButton(GAMEPAD_BUTTON_15); }

bool Gamepad::pressedB17()   { return pressedButton(GAMEPAD_BUTTON_16); }
bool Gamepad::pressedB18()   { return pressedButton(GAMEPAD_BUTTON_17); }
bool Gamepad::pressedB19()   { return pressedButton(GAMEPAD_BUTTON_18); }
bool Gamepad::pressedB20()   { return pressedButton(GAMEPAD_BUTTON_19); }
bool Gamepad::pressedB21()   { return pressedButton(GAMEPAD_BUTTON_20); }
bool Gamepad::pressedB22()   { return pressedButton(GAMEPAD_BUTTON_21); }
bool Gamepad::pressedB23()   { return pressedButton(GAMEPAD_BUTTON_22); }
bool Gamepad::pressedB24()   { return pressedButton(GAMEPAD_BUTTON_23); }
bool Gamepad::pressedB25()   { return pressedButton(GAMEPAD_BUTTON_24); }
bool Gamepad::pressedB26()   { return pressedButton(GAMEPAD_BUTTON_25); }
bool Gamepad::pressedB27()   { return pressedButton(GAMEPAD_BUTTON_26); }
bool Gamepad::pressedB28()   { return pressedButton(GAMEPAD_BUTTON_27); }
bool Gamepad::pressedB29()   { return pressedButton(GAMEPAD_BUTTON_28); }
bool Gamepad::pressedB30()   { return pressedButton(GAMEPAD_BUTTON_29); }
bool Gamepad::pressedB31()   { return pressedButton(GAMEPAD_BUTTON_30); }
bool Gamepad::pressedB32()   { return pressedButton(GAMEPAD_BUTTON_31); }
// clang-format on