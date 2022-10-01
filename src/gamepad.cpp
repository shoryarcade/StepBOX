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
