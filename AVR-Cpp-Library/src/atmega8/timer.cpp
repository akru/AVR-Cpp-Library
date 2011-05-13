#include <atmega8/timer.h>
#include <list.h>
#include <avr/io.h>
#include <avr/iom8.h>
#include <avr/interrupt.h>

namespace TimerInterrupt
{
List<InterruptAbstract *> TO_0;
}

Timer::Timer()
{
  cli();
  TCCR0 |= ( 1 << CS02 ) | ( 1 << CS00 );
  TIMSK |= ( 1 << TOIE0 );
  sei();
}

void Timer::connect( InterruptAbstract *interruptClass )
{
  TimerInterrupt::TO_0.push( interruptClass );
}


ISR( TIMER0_OVF_vect )
{
  if ( !TimerInterrupt::TO_0.empty() )
  {
    ListItem<InterruptAbstract *> * tmp =
      TimerInterrupt::TO_0.getBegin();
    do
    {
      tmp->data->_interrupt();
      tmp = tmp->next;
    }
    while ( tmp );
  }
}
