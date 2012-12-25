#ifndef TIMER_H
#define TIMER_H

#include <timer_abstract.h>
#include <callback.h>

class Timer :
    public TimerAbstract
{
public:
  Timer();
  void connect( CallbackAbstract *callback );
};

#endif // TIMER_H
