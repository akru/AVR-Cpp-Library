#include <device/button.h>

Button::Button( Application *parentApp )
    : ExternalDeviceAbstract( 1 )
{
  parent = parentApp;
  externalInterrupt = parent->mcu->externalInterrupt();
}

void Button::onClick( void ( *cback )() )
{
  callback = cback;
}

void Button::setINT( char numInt )
{
  pinUp( 0 );
  externalInterrupt->connect( this, numInt );
}

void Button::_interrupt()
{
  if ( callback )
    callback();
}
