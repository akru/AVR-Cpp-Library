#ifndef EXTERNAL_INTERRUPT_ABSTRACT_H
#define EXTERNAL_INTERRUPT_ABSTRACT_H

#include <interrupt_abstract.h>

class ExternalInterruptAbstract
{
public:
  virtual void connect( InterruptAbstract *interruptClass, char numInterrupt ) = 0;
};

#endif // EXTERNAL_INTERRUPT_ABSTRACT_H
