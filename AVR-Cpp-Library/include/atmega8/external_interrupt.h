#ifndef EXTERNAL_INTERRUPT_H
#define EXTERNAL_INTERRUPT_H

#include <interrupt_abstract.h>
#include <external_interrupt_abstract.h>

class ExternalInterrupt :
      public ExternalInterruptAbstract
{
public:
  ExternalInterrupt();
  void connect( InterruptAbstract *interruptClass, char numInterrupt );
};

#endif // EXTERNAL_INTERRUPT_H
