#pragma once

#define GAMEPAD_MANUFACTURER "Shorywood"
#define GAMEPAD_PRODUCT "StepBOX Controller"
#define GAMEPAD_SERIAL "123456"

class Device
{
public:
    Device(){};

    bool alive();
    void listen();

    virtual void setup() = 0;

    virtual void fetch() = 0;
    virtual void report() = 0;
};