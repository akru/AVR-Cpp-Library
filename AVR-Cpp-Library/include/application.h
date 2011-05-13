#ifndef APPLICATION_H
#define APPLICATION_H

#include <mcu_abstract.h>

class Application
{
public:
  Application( Application *parent = 0 )
      : parent( parent )
  {
    if ( parent )
      mcu = parent->mcu;
  }
  virtual void exec() = 0;
  virtual void terminate() = 0;
  McuAbstract *mcu;
private:
  Application *parent;
};

#endif // APPLICATION_H
