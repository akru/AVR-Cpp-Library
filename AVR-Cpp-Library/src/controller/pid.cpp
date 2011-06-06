#include <controller/pid.h>

float PID::getOutput( float error )
{
  float output, derivative;
  integral += error;
  derivative = error - previousError;
  output = ( Kp * error ) + ( Ki * integral ) + ( Kd * derivative );
  previousError = error;
  return output;
}
