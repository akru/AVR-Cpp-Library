#include <device/button.h>

Button::Button( Application *parentApp )
    : ExternalDeviceAbstract( 1 )
{
  parent = parentApp;
}

void Button::click( CallbackAbstract *callback )
{
  pinUp( 0 );
  parent->mcu()->externalInterrupt()->connect(callback, INTn);
}

