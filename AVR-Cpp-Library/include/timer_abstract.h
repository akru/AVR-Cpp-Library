#ifndef TIMER_ABSTRACT_H
#define TIMER_ABSTRACT_H

#include <interrupt_abstract.h>

class TimerAbstract
{
public:
  virtual void connect( InterruptAbstract *interruptClass ) = 0;
};

#endif // TIMER_ABSTRACT_H
