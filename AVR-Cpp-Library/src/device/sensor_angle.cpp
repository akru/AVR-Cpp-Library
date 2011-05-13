#include <device/sensor_angle.h>

SensorAngle::SensorAngle( Application *parentApp )
    : ExternalDeviceAbstract( 3 ), mode( 0 )
{
  parent = parentApp;
  adc = parent->mcu->adc();
  pinUp( 0 );
}

void SensorAngle::savePosition()
{
  savedPos = getPosition();
}

int SensorAngle::getError()
{
  return savedPos - getPosition();
}

int SensorAngle::getPosition()
{
  int pin0V, pin1V, pin2V;
  pin0V = adc->convert( getRealPin( 0 ) );
  pin1V = adc->convert( getRealPin( 1 ) );
  pin2V = adc->convert( getRealPin( 2 ) );
  return pin0V - pin1V - pin2V;
}
