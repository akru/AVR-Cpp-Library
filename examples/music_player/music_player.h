#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <application.h>
#include <mcu_abstract.h>
#include <device/speaker.h>

class MusicPlayer :
        public Application
{
public:
  MusicPlayer(McuAbstract *mcu);
  void exec();
  void terminate()
  {}
private:
  Speaker *sp;
  Speaker *sp2;
  void sample1();
  void sample2();
  void sample3();
};

#endif // MUSICPLAYER_H
