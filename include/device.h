#pragma once

#define GAMEPAD_MANUFACTURER "Shory"
#define GAMEPAD_PRODUCT "StepBOX Controller"
#define GAMEPAD_SERIAL "123456"

class Device
{
public:
    Device(){};

    uint32_t values;

    bool alive();
    void loop();

    virtual void setup() = 0;

    virtual void fetch() = 0;
    virtual void report() = 0;
};