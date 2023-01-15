# StepBOX Firmware

StepBOX is a custom rhythm gamepad based on the RP2040 (Raspberry Pico) microcontroller. The gamepad is recognized through DirectInput Driver on Windows, Mac & Linux.

## Layout

The layout was designed with 13 face buttons + 4 auxiliaries ones (touch, share, select and start)

```
                       [14] [15] [16] [17]
▛▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▜
▘                                        ▝
▘    [1]  [2]   [3]   [4]    [5]  [6]    ▝
▘                                        ▝
▘      [7]  [8]    [9]    [10]  [11]     ▝
▘                                        ▝
▘              [12]   [13]               ▝
▘                                        ▝
▙▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▟
```

## Layout by Game

These are our layout recommendations (per lanes) for the following games

- **Dance Dance Revolution** ( StepMania )

```
                               ⚪ ⚪ ⚪ ⚪
▛▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▜
▘                                        ▝
▘      ⚪  ⚪   ⚪    ⚪    ⚪  ⚪       ▝
▘                                        ▝
▘        ⚫  ⚫    ⚪    ⚫  ⚫          ▝             Left - Down - Up - Right
▘                                        ▝
▘               ⚪    ⚪                 ▝                  [Back] - [Enter]
▘                                        ▝
▙▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▟

```

- **Pump It Up** ( StepPrime )

```
                               ⚪ ⚪ ⚪ ⚪
▛▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▜
▘                                        ▝
▘      ⚪  ⚪   ⚫    ⚫    ⚪  ⚪       ▝                Up-Left  -  Up-Right
▘                                        ▝
▘        ⚪  ⚪    ⚫    ⚪  ⚪          ▝                      Center
▘                                        ▝
▘               ⚫    ⚫                 ▝               Down-Left -  Down-Right
▘                                        ▝
▙▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▟
```

- **Sound Voltex** ( KShootMania, unnamed-sdvx-clone )

```
                               ⚪ ⚪ ⚪ ⚪
▛▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▝▜
▘                                        ▝
▘      ⚫  ⚫   ⚪    ⚪    ⚫  ⚫       ▝   VOL-L                                   VOL-R
▘                                        ▝
▘        ⚫  ⚫    ⚪    ⚫  ⚫          ▝       BT-A    BT-B   [START]   BT-C    BT-D
▘                                        ▝
▘               ⚫    ⚫                 ▝           FX-L                     FX-R
▘                                        ▝
▙▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▟
```

## Features

- Selectable input modes (DirectInput, DirectInput + Keyboard)
- 17 full re-assignable buttons
- Less than 1 ms of input latency

## Input Modes

The default input mode replicates the behavior of a gamepad with 4 hats and 17 buttons. During the development of the StepBOX, we faced across a scenario where in _KShootMania_ buttons `1` `2` `5` `6` can be set as left and right lasers normally but in _unnamed-sdvx-clone_ it requires a real knob.

We get around this problem by implementing a composite-device that behaves both as a gamepad and as a keyboard. In this way, when activating **Keyboard Mode** some buttons also triggers some ASCII keys:

```
[1] -> W
[2] -> E

[5] -> O
[6] -> P
```

#### How to enable Keyboard Mode

1. Unplug your StepBOX from USB;
1. Hold the button `16` (Select) and plug your device again;
1. The onboard LED should be on indicating the new mode.

## Installation

Prebuilt `uf2` files are available in the [Releases](https://github.com/shoryarcade/StepBOX/releases) section for the following boards and controllers:

- ~~[Shory Board]()~~ (**not available yet**)
- [Raspberry Pi Pico]() and other RP2040 boards

Instructions for a Raspberry Pi Pico.

1. Download the latest `StepBOX.uf2` file from the [Releases](https://github.com/shoryarcade/StepBOX/releases) section for your board (e.g. `StepBOX-RaspberryPiPico.uf2` for the Raspberry Pi Pico);
1. Unplug your Pico;
1. Hold the BOOTSEL button on the Pico and plug into your computer. A new removable drive named `RPI-RP2` should appear in your file explorer;
1. Drag and drop the `StepBOX.uf2` file into the removable drive. This will flash the board.
1. The board is now running the StepBOX firmware and will appear as a controller on your computer.

## Wiring Diagram

![wiring diagram](assets/rp2040-diagram.png)

### StepBOX

| Button | RP2040 Pin | Description |
| :----: | :--------: | :---------: |
| BT-01  |   PIN-02   |    Left     |
| BT-02  |   PIN-03   |    Down     |
| BT-03  |   PIN-04   |     Up      |
| BT-04  |   PIN-05   |    Right    |
| BT-05  |   PIN-06   |   Up-Left   |
| BT-06  |   PIN-07   |  Up-Right   |
| BT-07  |   PIN-08   |  Down-Left  |
| BT-08  |   PIN-09   | Down-Right  |
| BT-09  |   PIN-22   |   Middle    |
| BT-10  |   PIN-10   |  Vol-L (-)  |
| BT-11  |   PIN-11   |  Vol-L (+)  |
| BT-12  |   PIN-12   |  Vol-R (-)  |
| BT-13  |   PIN-13   |  Vol-R (+)  |
| BT-14  |   PIN-21   |  Touchpad   |
| BT-15  |   PIN-20   |    Share    |
| BT-16  |   PIN-19   |   Select    |
| BT-17  |   PIN-18   |    Start    |

### ShoryVoltex

| Button | RP2040 Pin |  Description   |
| :----: | :--------: | :------------: |
|  BT-A  |   PIN-02   |                |
|  BT-B  |   PIN-03   |                |
|  BT-C  |   PIN-04   |                |
|  BT-D  |   PIN-05   |                |
|  FX-L  |   PIN-08   |                |
|  FX-R  |   PIN-09   |                |
| START  |   PIN-18   |                |
| VOL-L  |   PIN-14   | Output A (CLK) |
| VOL-L  |   PIN-15   | Output B (DT)  |
| VOL-R  |   PIN-16   | Output A (CLK) |
| VOL-R  |   PIN-17   | Output B (DT)  |
| AUX-1  |   PIN-19   |     Select     |
| AUX-2  |   PIN-20   |     Share      |
|        |   PIN-26   |    Left LED    |
|        |   PIN-27   |   Right LED    |
|        |   PIN-28   |   Middle LED   |

## Support (Discord)

If you like to discuss features, issues or anything else related to Shory products please [create an issue](https://github.com/shoryarcade/StepBOX/issues/new) or join the [Shory Discord Channel](https://discord.gg/kGekqHdRrn).
