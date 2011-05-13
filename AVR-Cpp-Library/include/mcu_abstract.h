#ifndef MCU_ABSTRACT_H
#define MCU_ABSTRACT_H

#include <timer_abstract.h>
#include <analog_digital_converter_abstract.h>
#include <external_interrupt_abstract.h>

class Pin
{
public:
  char pin, port;
};

class McuAbstract
{
public:
  virtual TimerAbstract * timer() = 0;
  virtual AnalogDigitalConverterAbstract * adc() = 0;
  virtual ExternalInterruptAbstract * externalInterrupt() = 0;
  virtual void digitalWrite( Pin pin, bool state ) = 0;
  virtual void pinMode( Pin pin, bool mode ) = 0;
};

#endif // MCU_ABSTRACT_H
