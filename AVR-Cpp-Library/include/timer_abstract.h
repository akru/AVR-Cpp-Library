#ifndef TIMER_ABSTRACT_H
#define TIMER_ABSTRACT_H

#include <callback.h>

class TimerAbstract
{
public:
  virtual void connect( CallbackAbstract *callback ) = 0;
};

#endif // TIMER_ABSTRACT_H
