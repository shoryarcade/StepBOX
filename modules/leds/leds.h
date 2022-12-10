#pragma once

#include "board.h"

#include "module.h"
#include "effect.h"
#include "phasing.h"
#include "leds.h"

#include "ws2812b.hpp"

#define MIDDLE_ZONE BOARD_MIDDLE_LEDSTRIP_LEN / 2
#define MAX_SPECTRUM MIDDLE_ZONE * 10
#define SLEEP_CYCLE_NS 400
#define TURN_OFF_AFTER_N_CYCLES 1600

using namespace ws2812b;

class Leds : public Module
{
private:
    Led *led;
    Effect *blue, *pink;

    uint32_t counter_l, counter_r = 0;

public:
    void setup();
    void run(State *state);
};