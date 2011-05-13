#ifndef ANALOG_DIGITAL_CONVERTER_ABSTRACT_H
#define ANALOG_DIGITAL_CONVERTER_ABSTRACT_H

class AnalogDigitalConverterAbstract
{
public:
  virtual int convert( char channel ) = 0;
};

#endif // ANALOG_DIGITAL_CONVERTER_ABSTRACT_H
