/*
 * MIT License
 *
 * Copyright (c) 2022 Shory (shory.com.br)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include <math.h>
#include <string>
#include <vector>

#include "pico/stdlib.h"
#include "bsp/board.h"
#include "pico/multicore.h"
#include "pico/util/queue.h"

#include "board.h"
#include "gamepad.h"
#include "keyboard.h"

#include "module.h"
#include "leds.h"

queue_t stateQueue;

void core1()
{
    vector<Module *> modules = {
        new Leds(),
    };

    for (auto module : modules)
        module->setup();

    while (true)
    {
        static State snapshot;

        if (queue_try_remove(&stateQueue, &snapshot))
        {
            for (auto module : modules)
                module->run(&snapshot);
        }
    }
}

int main(void)
{
    Board *board = new Board();

    Gamepad *gamepad = new Gamepad();
    gamepad->setup();

    queue_init(&stateQueue, sizeof(State), 1);

    Keyboard *keyboard;
    bool keyboardMode = board->keyboardMode();

    if (keyboardMode)
    {
        board_led_on();

        keyboard = new Keyboard();
        keyboard->setup();
    }

    multicore_launch_core1(core1);

    while (true)
    {
        board->keepAlive();

        if (!board->isReady())
            continue;

        gamepad->loop();

        if (keyboardMode)
            keyboard->loop();

        if (queue_is_empty(&stateQueue))
        {
            static State snapshot;
            memcpy(&snapshot, gamepad->getState(), sizeof(State));
            queue_try_add(&stateQueue, &snapshot);
        }
    }

    return 0;
}
