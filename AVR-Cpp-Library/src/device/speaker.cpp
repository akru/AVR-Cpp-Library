#include <device/speaker.h>

Speaker::Speaker(Application *parent)
    : ExternalDeviceAbstract(1),
    timer(parent->mcu->timer()), mode(MODE_SLEEP), fCounter(0), dCounter(0)
{
    timer->connect(this);
}

void Speaker::run(unsigned int newFreq, unsigned int newDuration)
{
    if (!busy())
    {
        freq = newFreq;
        duration = newDuration;
        mode = MODE_SWITCH;
    }
}

void Speaker::_interrupt()
{
    switch (mode)
    {
    case MODE_SLEEP:
        break;
    case MODE_IDLE:
        ++fCounter;
        if (fCounter == freq)
            mode = MODE_SWITCH;
        break;
    case MODE_SWITCH:
        if (dCounter < duration)
        {
            if (state)
            {
                pinUp(0);
                state = 0;
            }
            else
            {
                pinDown(0);
                state = 1;
            }
            fCounter = 0;
            mode = MODE_IDLE;
            ++dCounter;
        }
        else
            mode = MODE_SLEEP;
        break;
    }
}
