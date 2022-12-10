#pragma once

#include "gamepad.h"

class Module
{
public:
    Module(){};

    virtual void setup() = 0;
    virtual void run(State *state) = 0;
};