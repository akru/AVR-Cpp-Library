#ifndef SIGNAL_H
#define SIGNAL_H

#include <vector.h>
#include <callback.h>

class signal
{
public:
  signal()
    : stack(0)
  {}
  void connect(CallbackAbstract *callback)
  {
    stack = new vector<CallbackAbstract *>(callback, stack);
  }
  void em()
  {
    vector<CallbackAbstract *> *tmp = stack;
    while (tmp)
    {
      tmp->item->run();
      tmp = tmp->next;
    }
  }
private:
  vector<CallbackAbstract *> *stack;
};

#endif // SIGNAL_H
