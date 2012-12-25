#ifndef THERMOCONTROLLER_H
#define THERMOCONTROLLER_H

#include <application.h>
#include <device/button.h>
#include <device/led.h>
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
    void toggleLed();
};

#endif // THERMOCONTROLLER_H
