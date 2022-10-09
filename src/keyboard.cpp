#include "tusb.h"
#include "pico/stdlib.h"

#include "keyboard.h"
#include "usb_descriptors.h"

void Keyboard::setup()
{
}

void Keyboard::fetch()
{
    keys = ~gpio_get_all();

    // clang-format off
    pressedB1  = !gpio_get(2);
    pressedB2  = !gpio_get(3);
    pressedB5  = !gpio_get(6);
    pressedB6  = !gpio_get(7);
    // clang-format on
}

void Keyboard::report()
{
    if (!tud_hid_ready())
        return;

    if (keys != 0)
    {
        uint8_t keycode[6] = {0};

        // clang-format off
        if (pressedB1)  keycode[0] = HID_KEY_W;
        if (pressedB2)  keycode[1] = HID_KEY_E;
        if (pressedB5)  keycode[2] = HID_KEY_O;
        if (pressedB6)  keycode[3] = HID_KEY_P;

        tud_hid_keyboard_report(REPORT_ID_KEYBOARD, 0, keycode);
        // clang-format on
    }
    else
    {
        // send empty key report if previously has key pressed
        tud_hid_keyboard_report(REPORT_ID_KEYBOARD, 0, NULL);
    }
}
