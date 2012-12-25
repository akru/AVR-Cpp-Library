#ifndef MAIN_APPLICATION_H
#define MAIN_APPLICATION_H

#include <application.h>
#include <device/led.h>
#include <device/button.h>
#include <device/step_motor.h>
#include <device/sensor_angle.h>
#include <mcu_abstract.h>

class MainApplication :
      public Application
{
public:
  MainApplication(McuAbstract *mcu);
  void exec();
  void terminate()
  {}
private:
  Led *red, *green;
  Button *left, *right;
  StepMotor *sm;
  SensorAngle *sensor;
};

#endif // MAIN_APPLICATION_H
