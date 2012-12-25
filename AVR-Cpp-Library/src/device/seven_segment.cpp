#include <device/seven_segment.h>

SevenSegment::SevenSegment( Application *parentApp )
  : ExternalDeviceAbstract( 8 )
{
  parent = parentApp;
}

void SevenSegment::upAll()
{
  pinUp(0);
  pinUp(1);
  pinUp(2);
  pinUp(3);
  pinUp(4);
  pinUp(5);
  pinUp(6);
  pinUp(7);
}

void SevenSegment::downAll()
{
  pinDown(0);
  pinDown(1);
  pinDown(2);
  pinDown(3);
  pinDown(4);
  pinDown(5);
  pinDown(6);
  pinDown(7);
}

void SevenSegment::print (char num)
{
  downAll();
  switch (num)
  {
    case 0:
      pinUp(1);
      pinUp(2);
      pinUp(3);
      pinUp(4);
      pinUp(6);
      pinUp(7);
      break;
    case 1:
      pinUp(1);
      pinUp(2);
      break;
    case 2:
      pinUp(1);
      pinUp(3);
      pinUp(5);
      pinUp(6);
      pinUp(7);
      break;
    case 3:
      pinUp(1);
      pinUp(2);
      pinUp(3);
      pinUp(5);
      pinUp(6);
      break;
    case 4:
      pinUp(1);
      pinUp(2);
      pinUp(4);
      pinUp(5);
      break;
    case 5:
      pinUp(2);
      pinUp(3);
      pinUp(4);
      pinUp(5);
      pinUp(6);
      break;
    case 6:
      pinUp(2);
      pinUp(3);
      pinUp(4);
      pinUp(5);
      pinUp(6);
      pinUp(7);
      break;
    case 7:
      pinUp(1);
      pinUp(2);
      pinUp(3);
      break;
    case 8:
      pinUp(1);
      pinUp(2);
      pinUp(3);
      pinUp(4);
      pinUp(5);
      pinUp(6);
      pinUp(7);
      break;
    case 9:
      pinUp(1);
      pinUp(2);
      pinUp(3);
      pinUp(4);
      pinUp(5);
      pinUp(6);
  }
}
