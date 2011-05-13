#ifndef DRIVE_H
#define DRIVE_H

#include <interrupt_abstract.h>
#include <external_device_abstract.h>
#include <timer_abstract.h>
#include <application.h>

#define MODE_SLEEP   0
#define MODE_READY   1
#define MODE_IDLE    2
#define MODE_SWITCH  3

#define DIRECTION_LEFT   1
#define DIRECTION_RIGHT  0

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
      public ExternalDeviceAbstract,
      public InterruptAbstract
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
};

#endif // DRIVE_H
