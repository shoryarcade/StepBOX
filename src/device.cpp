#include "bsp/board.h"

#include "device.h"

// Report every 10ms
bool Device::alive(void)
{
    const uint32_t interval_ms = 1;
    static uint32_t start_ms = 0;

    if (board_millis() - start_ms < interval_ms)
        return false; // not enough time

    start_ms += interval_ms;

    uint32_t const btn = board_button_read();

    // Remote wakeup
    if (tud_suspended() && btn)
    {
        tud_remote_wakeup();
        return false;
    };

    return true;
}

void Device::listen()
{
    if (alive())
    {
        fetch();
        report();
    }
}