#include <atmega8/external_interrupt.h>
#include <avr/io.h>
#include <avr/iom8.h>
#include <avr/interrupt.h>

namespace ExtInterrupt
{
InterruptAbstract * INT_0 = 0;
InterruptAbstract * INT_1 = 0;
}

ExternalInterrupt::ExternalInterrupt()
{
  cli();
  MCUCR |= ( 1 << ISC00 ) | ( 1 << ISC01 ) | ( 1 << ISC11 ) | ( 1 << ISC10 );
  GICR |= ( 1 << INT0 ) | ( 1 << INT1 );
  sei();
}

void ExternalInterrupt::connect( InterruptAbstract *interruptClass, char numInterrupt )
{
  switch ( numInterrupt )
  {
  case 0:
    ExtInterrupt::INT_0 = interruptClass;
    break;
  case 1:
    ExtInterrupt::INT_1 = interruptClass;
    break;
  }
}

ISR( INT0_vect )
{
  if ( ExtInterrupt::INT_0 )
    ExtInterrupt::INT_0->_interrupt();
}

ISR( INT1_vect )
{
  if ( ExtInterrupt::INT_1 )
    ExtInterrupt::INT_1->_interrupt();
}
