#include "thermo_controller.h"
#include <atmega8/atmega8.h>

int main()
{
  ThermoController app(new AtMega8());
  app.exec();
  return 0;
}

