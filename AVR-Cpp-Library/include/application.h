#ifndef APPLICATION_H
#define APPLICATION_H

#include <mcu_abstract.h>

class Application
{
public:
  Application( McuAbstract *mcu )
    : _mcu ( mcu )
  {}
  virtual void exec() = 0;
  virtual void terminate() = 0;
  McuAbstract *mcu()
  {
    return _mcu;
  }
private:
  McuAbstract *_mcu;
};

#endif // APPLICATION_H
