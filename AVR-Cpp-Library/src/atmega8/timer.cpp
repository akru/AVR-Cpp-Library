#include <atmega8/timer.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <signal.h>

namespace TimerInterrupt
{
signal TO_0;
}

Timer::Timer()
{
  cli();
  TCCR0 |= ( 1 << CS00 );
  TIMSK |= ( 1 << TOIE0 );
  sei();
}

void Timer::connect( CallbackAbstract *callback )
{
  TimerInterrupt::TO_0.connect( callback );
}


ISR( TIMER0_OVF_vect )
{
  TimerInterrupt::TO_0.em();
}
