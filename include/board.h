#pragma once

#define BOARD_PIN_OFFSET 2
#define BOARD_LAST_PIN 27
#define BOARD_TOGGLE_MODE_PIN 10

/* OMRON E6B2-CWZ6C */
#define BOARD_ENCODER_PPR 400

#define BOARD_LEFT_ENCODER_OUT_A 14
#define BOARD_LEFT_ENCODER_OUT_B 15
#define BOARD_RIGHT_ENCODER_OUT_A 16
#define BOARD_RIGHT_ENCODER_OUT_B 17

class Board
{
public:
    Board();

    void pooling();
    bool keyboardMode();
};