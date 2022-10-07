#include "bsp/board.h"
#include "pico/stdlib.h"

#include "device.h"
#include "stepbox.h"

Device::Device()
{
    // Initialize GPIO from 02-27 (except for the internal 25 one)
    for (int pin = BOARD_PIN_OFFSET; pin <= BOARD_LAST_PIN; pin++)
    {
        if (pin != PICO_DEFAULT_LED_PIN)
        {
            gpio_init(pin);
            gpio_set_dir(pin, GPIO_IN);
            gpio_pull_up(pin);
        }
    }
}

// Report every 10ms
void Device::alive(void)
{
    const uint32_t interval_ms = 10;
    static uint32_t start_ms = 0;

    if (board_millis() - start_ms < interval_ms)
        return; // not enough time

    start_ms += interval_ms;

    uint32_t const btn = board_button_read();

    // Remote wakeup
    if (tud_suspended() && btn)
        tud_remote_wakeup();
}
