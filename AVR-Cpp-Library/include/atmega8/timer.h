#ifndef TIMER_H
#define TIMER_H

#include <interrupt_abstract.h>
#include <timer_abstract.h>

class Timer :
      public TimerAbstract
{
public:
  Timer();
  void connect( InterruptAbstract *interruptClass );
};

#endif // TIMER_H
