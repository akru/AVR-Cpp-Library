#ifndef ATMEGA8_H
#define ATMEGA8_H

#include <mcu_abstract.h>
#include <external_device_abstract.h>
#include <timer_abstract.h>
#include <analog_digital_converter_abstract.h>
#include <external_interrupt_abstract.h>
#include "analog_digital_converter.h"
#include "external_interrupt.h"
#include "timer.h"
#include "io_def.h"

class AtMega8 :
      public McuAbstract
{
public:
  AtMega8();
  TimerAbstract * timer()
  {
    return &_timer;
  }
  AnalogDigitalConverterAbstract * adc()
  {
    return &_adc;
  }
  ExternalInterruptAbstract * externalInterrupt()
  {
    return &_externalInterrupt;
  }
  void digitalWrite( Pin pin, bool state );
  void pinMode( Pin pin, bool mode );

private:
  Timer _timer;
  AnalogDigitalConverter _adc;
  ExternalInterrupt _externalInterrupt;
};

#endif // ATMEGA8_H
