#ifndef PID_H
#define PID_H

class PID
{
public:
  PID( float Kp )
      : Kp( Kp ), Ki( 0 ), Kd( 0 ), previousError( 0 ), integral( 0 )
  {}
  PID( float Kp, float Ki )
      : Kp( Kp ), Ki( Ki ), Kd( 0 ), previousError( 0 ), integral( 0 )
  {}
  PID( float Kp, float Ki, float Kd )
      : Kp( Kp ), Ki( Ki ), Kd( Kd ), previousError( 0 ), integral( 0 )
  {}
  float getOutput( float error );
private:
  float Kp, Ki, Kd;
  int previousError, integral;
};

#endif // PID_H
