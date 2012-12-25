#ifndef CALLBACK_H
#define CALLBACK_H

class CallbackAbstract
{
public:
  virtual void run() = 0;
};

template<class T>
class Callback
    : public CallbackAbstract
{
public:
  Callback(T* inst, void (T::*cback)())
    : instance(inst), callback(cback)
  {}
  void run()
  {
    (instance->*callback)();
  }
private:
  T *instance;
  void (T::*callback)();
};

#endif // CALLBACK_H
