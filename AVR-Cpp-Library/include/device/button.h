#ifndef BUTTON_H
#define BUTTON_H

#include <external_device_abstract.h>
#include <external_interrupt_abstract.h>
#include <application.h>
#include <callback.h>

class Button :
      public ExternalDeviceAbstract
{
public:
  Button( Application *parentApp );
  void click( CallbackAbstract *callback );
  void setINT( char INTn );
private:
  CallbackAbstract *cback;
};

#endif // BUTTON_H
