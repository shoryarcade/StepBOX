#include "tusb.h"
#include "pico/stdlib.h"

#include "keyboard.h"
#include "usb_descriptors.h"

void Keyboard::setup()
{
}

void Keyboard::fetch()
{
    values = ~gpio_get_all();

    // clang-format off
    pressedB10  = !gpio_get(10);
    pressedB11  = !gpio_get(11);
    pressedB12  = !gpio_get(12);
    pressedB13  = !gpio_get(13);
    // clang-format on
}

void Keyboard::report()
{
    if (!tud_hid_ready())
        return;

    if (values != 0)
    {
        uint8_t keycode[6] = {0};

        // clang-format off
        if (pressedB10)  keycode[0] = HID_KEY_W;
        if (pressedB11)  keycode[1] = HID_KEY_E;
        if (pressedB12)  keycode[2] = HID_KEY_O;
        if (pressedB13)  keycode[3] = HID_KEY_P;

        tud_hid_keyboard_report(REPORT_ID_KEYBOARD, 0, keycode);
        // clang-format on
    }
    else
    {
        // send empty key report if previously has key pressed
        tud_hid_keyboard_report(REPORT_ID_KEYBOARD, 0, NULL);
    }
}
