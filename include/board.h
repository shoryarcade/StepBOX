#pragma once

#include <stdint.h>

#define BOARD_PIN_OFFSET 2
#define BOARD_LAST_PIN 27
#define BOARD_TOGGLE_MODE_PIN 10

/* OMRON E6B2-CWZ6C */
#define BOARD_ENCODER_PPR 400
#define BOARD_ENCODER_CPR BOARD_ENCODER_PPR * 4

#define BOARD_LEFT_ENCODER_OUT_A 14
#define BOARD_LEFT_ENCODER_OUT_B 15
#define BOARD_RIGHT_ENCODER_OUT_A 16
#define BOARD_RIGHT_ENCODER_OUT_B 17

/* LEDSTRIP WS2812B */
#define BOARD_MIDDLE_LEDSTRIP_LEN 18
#define BOARD_MIDDLE_LEDSTRIP_PIN 28

#define BOARD_DEBOUNCE_MS_TIME 1000

class Board
{
private:
    uint64_t lastRun;

public:
    Board();

    bool isReady();
    void keepAlive();
    bool keyboardMode();
};