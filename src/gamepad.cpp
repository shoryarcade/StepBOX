#include "tusb.h"
#include "pico/stdlib.h"

#include "gamepad.h"
#include "usb_descriptors.h"

void Gamepad::setup()
{
}

void Gamepad::fetch()
{

    // clang-format off
    uint32_t values = ~gpio_get_all();

    hats = 0
        | ((values & (1 << 21) ? BUTTON_UP : 0))
        | ((values & (1 << 20) ? BUTTON_DOWN : 0))
        | ((values & (1 << 19) ? BUTTON_LEFT : 0))
        | ((values & (1 << 18) ? BUTTON_RIGHT : 0))
    ;

    buttons = 0
        | ((values & (1 << 2) ? BUTTON_01 : 0))
        | ((values & (1 << 3) ? BUTTON_02 : 0))
        | ((values & (1 << 4) ? BUTTON_03 : 0))
        | ((values & (1 << 5) ? BUTTON_04 : 0))
        | ((values & (1 << 6) ? BUTTON_05 : 0))
        | ((values & (1 << 7) ? BUTTON_06 : 0))
        | ((values & (1 << 8) ? BUTTON_07 : 0))
        | ((values & (1 << 9) ? BUTTON_08 : 0))
        | ((values & (1 << 10) ? BUTTON_09 : 0))
        | ((values & (1 << 11) ? BUTTON_10 : 0))
        | ((values & (1 << 12) ? BUTTON_11 : 0))
        | ((values & (1 << 13) ? BUTTON_12 : 0))
        | ((values & (1 << 14) ? BUTTON_13 : 0))

        | ((values & (1 << 26) ? BUTTON_TOUCH : 0))
        | ((values & (1 << 27) ? BUTTON_SHARE : 0))
        | ((values & (1 << 16) ? BUTTON_SELECT : 0))
        | ((values & (1 << 27) ? BUTTON_START : 0))
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

    tud_hid_report(REPORT_ID_GAMEPAD, &report, sizeof(report));
}

bool Gamepad::pressedButton(uint32_t button)
{
    return ((buttons & button) == button || (hats & button) == button);
}

// clang-format off
bool Gamepad::pressedUp()     { return pressedButton(BUTTON_UP); }
bool Gamepad::pressedDown()   { return pressedButton(BUTTON_DOWN); }
bool Gamepad::pressedLeft()   { return pressedButton(BUTTON_LEFT); }
bool Gamepad::pressedRight()  { return pressedButton(BUTTON_RIGHT); }

bool Gamepad::pressedB1()     { return pressedButton(BUTTON_01); }
bool Gamepad::pressedB2()     { return pressedButton(BUTTON_02); }
bool Gamepad::pressedB3()     { return pressedButton(BUTTON_03); }
bool Gamepad::pressedB4()     { return pressedButton(BUTTON_04); }
bool Gamepad::pressedB5()     { return pressedButton(BUTTON_05); }
bool Gamepad::pressedB6()     { return pressedButton(BUTTON_06); }
bool Gamepad::pressedB7()     { return pressedButton(BUTTON_07); }
bool Gamepad::pressedB8()     { return pressedButton(BUTTON_08); }
bool Gamepad::pressedB9()     { return pressedButton(BUTTON_09); }
bool Gamepad::pressedB10()    { return pressedButton(BUTTON_10); }
bool Gamepad::pressedB11()    { return pressedButton(BUTTON_11); }
bool Gamepad::pressedB12()    { return pressedButton(BUTTON_12); }
bool Gamepad::pressedB13()    { return pressedButton(BUTTON_13); }

bool Gamepad::pressedTouch()  { return pressedButton(BUTTON_TOUCH); }
bool Gamepad::pressedShare()  { return pressedButton(BUTTON_SHARE); }
bool Gamepad::pressedSelect() { return pressedButton(BUTTON_SELECT); }
bool Gamepad::pressedStart()  { return pressedButton(BUTTON_START); }
// clang-format on