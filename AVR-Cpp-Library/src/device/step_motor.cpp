#include <device/step_motor.h>

StepMotor::StepMotor( Application *parentApp )
    : ExternalDeviceAbstract( 4 ), crntPin( 0 ), mode( MODE_SLEEP )
{
  parent = parentApp;
  timer = parent->mcu()->timer();
  c = new Callback<StepMotor>(this, &StepMotor::_interrupt);
  timer->connect( c );
}

void StepMotor::step( StepInfo sInfo )
{
  if ( !busy() )
  {
    stepInfo = sInfo;
    mode = MODE_READY;
  }
}

void StepMotor::_interrupt()
{
  switch ( mode )
  {
  case MODE_SLEEP:
    break;

  case MODE_READY:
    mode = MODE_SWITCH;
    crntStep = 0;
    break;

  case MODE_IDLE:
    if ( !interruptCounter )
    {
      pinUp( crntPin );
    }
    if ( interruptCounter == stepInfo.speed * 1024 )
    {
      pinDown( crntPin );
      mode = MODE_SWITCH;
    }
    ++interruptCounter;
    break;

  case MODE_SWITCH:
    if ( crntStep < stepInfo.steps )
    {
      if ( stepInfo.direction )
      {
        if ( crntPin < 3 )
          ++crntPin;
        else
          crntPin = 0;
      }
      else
      {
        if ( crntPin > 0 )
          --crntPin;
        else
          crntPin = 3;
      }
      interruptCounter = 0;
      mode = MODE_IDLE;
      ++crntStep;
    }
    else
    {
      mode = MODE_SLEEP;
    }
    break;
  }
}

bool StepMotor::busy()
{
  if ( mode )
    return 1;
  else
    return 0;
}
