#include "thermo_controller.h"
#include <atmega8/io_def.h>

ThermoController::ThermoController (McuAbstract *mcu)
  : Application(mcu)
{
    statusLed = new Led(this);
    statusLed->setPin(0, PD_6, PORT_D, WRITE);

    b1 = new Button(this);
    b1->setPin(0, PD_2, PORT_D, READ);
    b1->setINT(0);
    c1 = new Callback<ThermoController>(this, &ThermoController::toggleLed);
    b1->click(c1);

//    b2 = new Button(this);
//    b2->setPin(0, PD_3, PORT_D, READ);
//    b2->setINT(1);
//    b2->click(&ThermoController::toggleLed);
}

void ThermoController::exec ()
{
    for (;;) {}
}

void ThermoController::toggleLed ()
{
    if (statusLed->status())
        statusLed->off();
    else
        statusLed->on();
}
