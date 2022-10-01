#include <stdint.h>

#include "device.h"
#include "bsp/board.h"

// Every 10ms, we will sent 1 report,
// tud_hid_report_complete_cb() is used to send the next report after previous one is complete

void Device::alive(void)
{
    // Poll every 10ms
    const uint32_t interval_ms = 10;
    static uint32_t start_ms = 0;

    if (board_millis() - start_ms < interval_ms)
        return; // not enough time

    start_ms += interval_ms;

    uint32_t const btn = board_button_read();

    // Remote wakeup
    if (tud_suspended() && btn)
    {
        // Wake up host if we are in suspend mode
        // and REMOTE_WAKEUP feature is enabled by host
        tud_remote_wakeup();
    }
}

// Invoked when sent REPORT successfully to host
// Application can use this to send the next report
// Note: For composite reports, report[0] is report ID
// void tud_hid_report_complete_cb(uint8_t instance, uint8_t const *report, uint8_t len)
// {
//     (void)instance;
//     (void)len;

//     uint8_t next_report_id = report[0] + 1;

//     if (next_report_id < REPORT_ID_COUNT)
//     {
//         send_hid_report(next_report_id, 0, board_button_read());
//     }
// }
