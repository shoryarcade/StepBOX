#include <string>

#include "board.h"

#include "leds.h"
#include "phasing.h"

#include "gamepad.h"

#include "ws2812b.hpp"

using namespace ws2812b;

void Leds::setup()
{
    this->led = new Led(pio1, 3, BOARD_MIDDLE_LEDSTRIP_PIN, BOARD_MIDDLE_LEDSTRIP_LEN);

    this->blue = new Phasing(this->led);
    this->pink = new Phasing(this->led);

    sleep_us(4 * SLEEP_CYCLE_NS);
}

void Leds::run(State *state)
{
    this->counter_l = 1 + (state->vol_l * -1);
    this->counter_r = 1 + (state->vol_r * -1);

    this->blue->show(&this->counter_l, 0, MIDDLE_ZONE, "blue");
    this->pink->show(&this->counter_r, MIDDLE_ZONE, BOARD_MIDDLE_LEDSTRIP_LEN, "pink");

    sleep_us(SLEEP_CYCLE_NS);
}