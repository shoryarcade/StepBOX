#pragma once

#include "effect.h"

class Phasing : public Effect
{
private:
    uint32_t counter, current, reseter = 0;

protected:
    using Effect::Effect;

public:
    void show(uint32_t *counter, uint8_t start, uint8_t end, string color);
};