#ifndef EXTERNAL_INTERRUPT_ABSTRACT_H
#define EXTERNAL_INTERRUPT_ABSTRACT_H

#include <callback.h>

class ExternalInterruptAbstract
{
public:
  virtual void connect(CallbackAbstract *callback, char INTn) = 0;
};

#endif // EXTERNAL_INTERRUPT_ABSTRACT_H
