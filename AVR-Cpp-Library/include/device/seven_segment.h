#ifndef SEVEN_SEGMENT_H
#define SEVEN_SEGMENT_H

#include <external_device_abstract.h>
#include <application.h>

class SevenSegment
    : public ExternalDeviceAbstract
{
public:
  SevenSegment( Application *parentApp );
  void upAll();
  void downAll();
  void print(char num);
};

#endif // SEVEN_SEGMENT_H
