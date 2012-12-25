#include "thermo_controller.h"
#include <atmega8/io_def.h>

ThermoController::ThermoController (McuAbstract *mcu)
  : Application(mcu)
{
    statusLed = new Led(this);
    statusLed->setPin(0, PD_6, PORT_D, WRITE);

    sevseg = new SevenSegment(this);
    sevseg->setPin(0, PC_6, PORT_C, WRITE);
    sevseg->setPin(1, PC_5, PORT_C, WRITE);
    sevseg->setPin(2, PC_4, PORT_C, WRITE);
    sevseg->setPin(3, PC_3, PORT_C, WRITE);
    sevseg->setPin(4, PC_2, PORT_C, WRITE);
    sevseg->setPin(5, PC_1, PORT_C, WRITE);
    sevseg->setPin(6, PC_0, PORT_C, WRITE);
    sevseg->setPin(7, PD_7, PORT_D, WRITE);

    b1 = new Button(this);
    b1->setPin(0, PD_2, PORT_D, READ);
    b1->setINT(0);
    c1 = new Callback<ThermoController>(this, &ThermoController::toggleLed);
    b1->click(c1);

    b2 = new Button(this);
    b2->setPin(0, PD_3, PORT_D, READ);
    b2->setINT(1);
    c2 = new Callback<ThermoController>(this, &ThermoController::toggleSevseg);
    b2->click(c2);
}

void ThermoController::exec ()
{
    for (;;) {}
}

void ThermoController::toggleLed ()
{
    if (statusLed->status())
    {
        statusLed->off();
        sevseg->downAll();
    }
    else
    {
        statusLed->on();
        sevseg->upAll();
    }
}

void ThermoController::toggleSevseg()
{
  sevseg->print(counter++);
  if (counter > 9)
    counter = 0;
}
