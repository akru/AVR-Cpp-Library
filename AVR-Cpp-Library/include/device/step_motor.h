#ifndef DRIVE_H
#define DRIVE_H

#include <external_device_abstract.h>
#include <timer_abstract.h>
#include <application.h>
#include <callback.h>

const char DIRECTION_LEFT  = 1;
const char DIRECTION_RIGHT = 0;

class StepInfo
{
public:
  StepInfo()
  {};
  StepInfo( char steps, char speed, char direction )
      : steps( steps ), speed( speed ), direction( direction )
  {}
  char steps, speed, direction;
};

class StepMotor :
      public ExternalDeviceAbstract
{
public:
  StepMotor( Application *parentApp );
  void step( StepInfo sInfo );
  void _interrupt();
  bool busy();

private:
  TimerAbstract *timer;
  StepInfo stepInfo;
  char crntPin;
  char crntStep;
  char mode;
  int interruptCounter;
  static const char MODE_SLEEP   = 0;
  static const char MODE_READY   = 1;
  static const char MODE_IDLE    = 2;
  static const char MODE_SWITCH  = 3;
  Callback<StepMotor> *c;
};

#endif // DRIVE_H
