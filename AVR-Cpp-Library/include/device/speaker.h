#ifndef SPEAKER_H
#define SPEAKER_H

#include <external_device_abstract.h>
#include <application.h>
#include <timer_abstract.h>
#include <callback.h>

class Speaker :
      public ExternalDeviceAbstract
{
public:
  Speaker( Application *parent );
  void _interrupt();
  void run( unsigned int newFreq, unsigned int newDuration );
  bool busy();

private:
  TimerAbstract *timer;
  char mode;
  bool state;
  unsigned int freq, duration, fCounter, dCounter;
  static const char MODE_SLEEP   = 0;
  static const char MODE_IDLE    = 1;
  static const char MODE_SWITCH  = 2;
  Callback<Speaker> *c;
};

#endif // SPEAKER_H
