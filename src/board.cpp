#include "bsp/board.h"
#include "pico/stdlib.h"

#include "board.h"

Board::Board()
{
    lastRun = time_us_64();

    board_init();
    tusb_init();

    // Initialize GPIO from 02-27 (except for the internal 25 one)
    for (int pin = BOARD_PIN_OFFSET; pin <= BOARD_LAST_PIN; pin++)
    {
        if (
            pin != PICO_DEFAULT_LED_PIN && pin != BOARD_LEFT_ENCODER_OUT_A && pin != BOARD_LEFT_ENCODER_OUT_B && pin != BOARD_RIGHT_ENCODER_OUT_A && pin != BOARD_RIGHT_ENCODER_OUT_B)
        {
            gpio_init(pin);
            gpio_set_dir(pin, GPIO_IN);
            gpio_pull_up(pin);
        }
    }
}

bool Board::keyboardMode()
{
    return !gpio_get(BOARD_TOGGLE_MODE_PIN);
}

void Board::keepAlive()
{
    // tinyusb
    tud_task();
}

bool Board::isReady()
{
    bool ready = (time_us_64() - this->lastRun) >= BOARD_DEBOUNCE_MS_TIME;

    if (!ready)
        return false;

    lastRun = time_us_64();
    return true;
}