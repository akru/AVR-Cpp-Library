#ifndef THERMOCONTROLLER_H
#define THERMOCONTROLLER_H

#include <application.h>
#include <device/button.h>
#include <device/led.h>
#include <device/seven_segment.h>
#include <mcu_abstract.h>
#include <callback.h>

class ThermoController :
        public Application
{
public:
    ThermoController(McuAbstract *mcu);
    void exec();
    void terminate()
    {}
private:
    Callback<ThermoController> *c1, *c2;
    Button *b1, *b2;
    Led *statusLed;
    SevenSegment *sevseg;
    void toggleLed();
    void toggleSevseg();
    char counter;
};

#endif // THERMOCONTROLLER_H
