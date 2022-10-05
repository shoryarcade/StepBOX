#include <stdint.h>

#include "device.h"
#include "bsp/board.h"

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
