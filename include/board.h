#pragma once

#define BOARD_PIN_OFFSET 2
#define BOARD_LAST_PIN 27
#define BOARD_TOGGLE_MODE_PIN 10

class Board
{
public:
    Board();

    void pooling();
    bool keyboardMode();
};