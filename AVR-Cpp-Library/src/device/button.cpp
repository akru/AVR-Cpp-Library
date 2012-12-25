#include <device/button.h>

Button::Button( Application *parentApp )
    : ExternalDeviceAbstract( 1 )
{
  parent = parentApp;
}

void Button::click( CallbackAbstract *callback )
{
  cback = callback;
}

void Button::setINT(char INTn )
{
  pinUp( 0 );
  parent->mcu()->externalInterrupt()->connect(cback, INTn);
}

