#include "main_application.h"
#include <atmega8/atmega8.h>

int main()
{
  MainApplication app(new AtMega8());
  app.exec();
  return 0;
}

