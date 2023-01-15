#include "tusb.h"
#include "pico/stdlib.h"

#include "board.h"
#include "gamepad.h"
#include "usb_descriptors.h"

State *Gamepad::getState()
{
    return state;
}

void Gamepad::setup()
{
    pin_pair pins_l = {
        BOARD_LEFT_ENCODER_OUT_A,
        BOARD_LEFT_ENCODER_OUT_B,
    };

    pin_pair pins_r = {
        BOARD_RIGHT_ENCODER_OUT_A,
        BOARD_RIGHT_ENCODER_OUT_B,
    };

    enc_l = new Encoder(pio0, 0, pins_l, BOARD_LAST_PIN, NORMAL_DIR, BOARD_ENCODER_CPR);
    enc_r = new Encoder(pio0, 2, pins_r, BOARD_LAST_PIN, NORMAL_DIR, BOARD_ENCODER_CPR);

    enc_l->init();
    enc_r->init();
}

void Gamepad::fetch()
{
    // clang-format off
    values = ~gpio_get_all();

    state->hats = 0;

    state->vol_l = enc_l->count();
    state->vol_r = enc_r->count();

    state->buttons = 0
        | ((values & (1 << 2) ? BUTTON_01 : 0))
        | ((values & (1 << 3) ? BUTTON_02 : 0))
        | ((values & (1 << 4) ? BUTTON_03 : 0))
        | ((values & (1 << 5) ? BUTTON_04 : 0))
        | ((values & (1 << 6) ? BUTTON_05 : 0))
        | ((values & (1 << 7) ? BUTTON_06 : 0))
        | ((values & (1 << 8) ? BUTTON_07 : 0))
        | ((values & (1 << 9) ? BUTTON_08 : 0))
        | ((values & (1 << 22) ? BUTTON_09 : 0))
        | ((values & (1 << 10) ? BUTTON_10 : 0))
        | ((values & (1 << 11) ? BUTTON_11 : 0))
        | ((values & (1 << 12) ? BUTTON_12 : 0))
        | ((values & (1 << 13) ? BUTTON_13 : 0))

        | ((values & (1 << 21) ? BUTTON_TOUCH : 0))
        | ((values & (1 << 20) ? BUTTON_SHARE : 0))
        | ((values & (1 << 19) ? BUTTON_SELECT : 0))
        | ((values & (1 << 18) ? BUTTON_START : 0))
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
            .hat = 0,
            .buttons = 0};

    report.x = state->vol_l;
    report.y = state->vol_r;
    report.hat = state->hats;
    report.buttons = state->buttons;

    tud_hid_report(REPORT_ID_GAMEPAD, &report, sizeof(report));
}

bool Gamepad::pressedButton(uint32_t button)
{
    return ((state->buttons & button) == button || (state->hats & button) == button);
}

// clang-format off
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