#ifndef BUTTON_H
#define BUTTON_H

#include <external_device_abstract.h>
#include <external_interrupt_abstract.h>
#include <interrupt_abstract.h>
#include <application.h>

class Button :
      public ExternalDeviceAbstract,
      public InterruptAbstract
{
public:
  Button( Application *parentApp );
  void onClick( void ( *cback )() );
  void setINT( char numInt );
  void _interrupt();

private:
  ExternalInterruptAbstract *externalInterrupt;
  void ( *callback )();
};

#endif // BUTTON_H
