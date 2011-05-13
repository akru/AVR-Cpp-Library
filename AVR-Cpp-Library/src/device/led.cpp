#include <device/led.h>

Led::Led( Application *parentApp )
    : ExternalDeviceAbstract( 1 )
{
  parent = parentApp;
}

void Led::on()
{
  pinUp( 0 );
}

void Led::off()
{
  pinDown( 0 );
}
