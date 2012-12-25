#include <atmega8/external_interrupt.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <signal.h>

namespace ExtInterrupt
{
signal INT_0;
signal INT_1;
}

ExternalInterrupt::ExternalInterrupt()
{
  cli();
  MCUCR |= ( 1 << ISC00 ) | ( 1 << ISC01 ) | ( 1 << ISC11 ) | ( 1 << ISC10 );
  GICR |= ( 1 << INT0 ) | ( 1 << INT1 );
  sei();
}

void ExternalInterrupt::connect( CallbackAbstract *callback, char INTn )
{
  switch ( INTn )
  {
  case 0:
    ExtInterrupt::INT_0.connect(callback);
    break;
  case 1:
    ExtInterrupt::INT_1.connect(callback);
    break;
  }
}

ISR( INT0_vect )
{
  ExtInterrupt::INT_0.em();
}

ISR( INT1_vect )
{
  ExtInterrupt::INT_1.em();
}
