#ifndef LED_H
#define LED_H

#include <external_device_abstract.h>
#include <application.h>

class Led :
      public ExternalDeviceAbstract
{
public:
  Led( Application *parentApp );
  void on();
  void off();
};

#endif // LED_H
