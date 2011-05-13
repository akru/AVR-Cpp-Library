#ifndef SENSOR_ANGLE_H
#define SENSOR_ANGLE_H

#include <external_device_abstract.h>
#include <analog_digital_converter_abstract.h>
#include <application.h>

class SensorAngle :
      public ExternalDeviceAbstract
{
public:
  SensorAngle( Application *parent );
  void savePosition();
  int getError();

private:
  AnalogDigitalConverterAbstract *adc;
  int getPosition();
  char mode;
  unsigned int savedPos, crntPos;
};

#endif // SENSOR_ANGLE_H
