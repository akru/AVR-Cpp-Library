#include <atmega8/atmega8.h>
#include <avr/io.h>
#include <avr/iom8.h>

AtMega8::AtMega8()
{
}

void AtMega8::pinMode( Pin pin, bool mode )
{
  if ( mode )
  {
    char pinMask = ( 1 << pin.pin );
    switch ( pin.port )
    {
    case PORT_B:
      DDRB |= pinMask;
      break;
    case PORT_C:
      DDRC |= pinMask;
      break;
    case PORT_D:
      DDRD |= pinMask;
      break;
    }
  }
}

void AtMega8::digitalWrite( Pin pin, bool state )
{
  char pinMask = ( 1 << pin.pin );
  if ( state )
  {
    switch ( pin.port )
    {
    case PORT_B:
      PORTB |= pinMask;
      break;
    case PORT_C:
      PORTC |= pinMask;
      break;
    case PORT_D:
      PORTD |= pinMask;
      break;
    }
  }
  else
  {
    switch ( pin.port )
    {
    case PORT_B:
      PORTB &= ~pinMask;
      break;
    case PORT_C:
      PORTC &= ~pinMask;
      break;
    case PORT_D:
      PORTD &= ~pinMask;
      break;
    }
  }
}
