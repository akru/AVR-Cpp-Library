#include "main_application.h"
#include <atmega8/io_def.h>

MainApplication::MainApplication(McuAbstract *mcu)
  : Application(mcu)
{
  red = new Led( this );
  green = new Led( this );
  left = new Button( this );
  right = new Button( this );
  sm = new StepMotor( this );
  sensor = new SensorAngle( this );

  /*  Initialisation  */
  red->setPin( 0, PB_6, PORT_B, WRITE );      // Red LED
  green->setPin( 0, PB_7, PORT_B, WRITE );    // Green LED
  left->setPin( 0, PD_2, PORT_D, READ );      // Left Button
  right->setPin( 0, PD_3, PORT_D, READ );     // Right Button
  sm->setPin( 0, PB_0, PORT_B, WRITE );       // Step Drive
  sm->setPin( 1, PD_7, PORT_D, WRITE );       //
  sm->setPin( 2, PD_6, PORT_D, WRITE );       //
  sm->setPin( 3, PD_5, PORT_D, WRITE );       //
  sensor->setPin( 0, PC_1, PORT_C, WRITE );   // Sensor Angle
  sensor->setPin( 1, PC_2, PORT_C, READ );    //
  sensor->setPin( 2, PC_3, PORT_C, WRITE );   //
  /* Initialisation end  */

  //left.onClick(&savePosition);
  //right.onClick();
}

void MainApplication::exec()
{
  red->on();
  sm->step( StepInfo( 4, 10, DIRECTION_LEFT ) );
  while ( sm->busy() );
  sm->step( StepInfo( 4, 10, DIRECTION_RIGHT ) );
  while ( sm->busy() );
  red->off();
  green->on();

  for ( ;; )
  {
      if ( sensor->getError() > 100 )
      {
        red->on();
        sm->step( StepInfo( 1, 10, DIRECTION_LEFT ) );
        while ( sm->busy() );
        red->off();
        sensor->savePosition();
      }
      if ( sensor->getError() < -100 )
      {
        red->on();
        sm->step( StepInfo( 1, 10, DIRECTION_RIGHT ) );
        while ( sm->busy() );
        red->off();
        sensor->savePosition();
      }
  }
}
