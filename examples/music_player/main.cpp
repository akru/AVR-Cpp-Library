#include "music_player.h"
#include <atmega8/atmega8.h>

int main()
{
  MusicPlayer app(new AtMega8());
  app.exec();
  return 0;
}

