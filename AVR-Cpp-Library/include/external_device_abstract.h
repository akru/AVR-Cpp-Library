#ifndef EXTERNAL_DEVICE_ABSTRACT_H
#define EXTERNAL_DEVICE_ABSTRACT_H

#include <stdlib.h>
#include <application.h>

class ExternalDeviceAbstract
{
public:
  ExternalDeviceAbstract( size_t numPins )
      : pins( new Pin[numPins] ), numPins( numPins )
  {}
  void setPin( size_t index, char pin, char port, char mode )
  {
    pins[index].pin = pin;
    pins[index].port = port;
    parent->mcu()->pinMode( pins[index], mode );
  }

protected:
  inline void pinUp( size_t index )
  {
    parent->mcu()->digitalWrite( pins[index], 1 );
  }
  inline void pinDown( size_t index )
  {
    parent->mcu()->digitalWrite( pins[index], 0 );
  }
  inline bool pinState (size_t index )
  {
    return parent->mcu()->digitalRead( pins[index] );
  }
  inline char getRealPin( size_t index )
  {
    return pins[index].pin;
  }
  Application *parent;

private:
  Pin *pins;
  char numPins;
};

#endif // EXTERNAL_DEVICE_ABSTRACT_H
