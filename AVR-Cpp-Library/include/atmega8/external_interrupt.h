#ifndef EXTERNAL_INTERRUPT_H
#define EXTERNAL_INTERRUPT_H

#include <external_interrupt_abstract.h>
#include <callback.h>

class ExternalInterrupt :
      public ExternalInterruptAbstract
{
public:
  ExternalInterrupt();
  void connect( CallbackAbstract *callback, char INTn );
};

#endif // EXTERNAL_INTERRUPT_H
