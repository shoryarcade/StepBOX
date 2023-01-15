#include "leds.h"
#include "colors.h"
#include "phasing.h"

int32_t phasing(string color, int32_t index);

void Phasing::show(uint32_t *counter, uint8_t start, uint8_t end, string color)
{
    this->current = *counter;
    this->reseter = (this->counter == this->current) ? this->reseter + 1 : 0;
    this->counter = this->current;

    if (this->reseter >= TURN_OFF_AFTER_N_CYCLES)
    {
        for (int i = start; i < end; i++)
            this->led->putPixel(BLACK);
    }
    else
    {
        for (int i = start; i < end; i++)
        {
            int padder = i * (MAX_SPECTRUM / MIDDLE_ZONE);
            this->led->putPixel(phasing(color, (*counter + padder) % MAX_SPECTRUM));
        }
    }
}

int32_t phasing(string color, int32_t index)
{
    switch (index %= MAX_SPECTRUM)
    {
    case 0 ... 5:
        return (color == "pink" ? PINK1 : BLUE1);

    case 6 ... 10:
        return (color == "pink" ? PINK2 : BLUE2);

    case 11 ... 20:
        return (color == "pink" ? PINK3 : BLUE3);

    case 21 ... 30:
        return (color == "pink" ? PINK2 : BLUE2);

    case 31 ... 40:
        return (color == "pink" ? PINK1 : BLUE1);

    default:
        return BLACK;
    }
}
