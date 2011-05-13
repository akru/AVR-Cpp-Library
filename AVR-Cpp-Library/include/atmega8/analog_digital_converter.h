#ifndef ANALOG_DIGITAL_CONVERTER_H
#define ANALOG_DIGITAL_CONVERTER_H

#include <analog_digital_converter_abstract.h>

class AnalogDigitalConverter :
      public AnalogDigitalConverterAbstract
{
public:
  AnalogDigitalConverter();
  int convert( char channel );
private:
  char mode;
};

#endif // ANALOG_DIGITAL_CONVERTER_H
