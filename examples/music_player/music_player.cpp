#include "music_player.h"
#include <atmega8/atmega8.h>

MusicPlayer::MusicPlayer()
{
    mcu = new AtMega8();
    sp = new Speaker( this );
    sp2 = new Speaker( this );
    sp->setPin(0, PC_4, PORT_C, WRITE);
    sp2->setPin(0, PC_5, PORT_C, WRITE);
}

void MusicPlayer::exec()
{
    for (;;)
    {
        sample1();
        sample1();
        sample1();
        sample2();
        sample3();
        sample3();
        sample3();
        sample3();
        sample3();
        sample3();
        sample2();
    }
}


void MusicPlayer::sample1()
{
    sp->run(100, 100);
    sp2->run(20, 50);
    while(sp2->busy());
    sp2->run(30, 50);
    while(sp2->busy());
    sp2->run(40, 50);
    while(sp2->busy());
    while(sp->busy());
    sp->run(200, 100);
    sp2->run(400, 5);
    while(sp->busy());
    sp->run(200, 50);
    sp2->run(400, 4);
    while(sp2->busy());
    sp2->run(200, 2);
    while(sp->busy());
    sp->run(400, 25);
    while(sp->busy());
    sp->run(500, 25);
    while(sp->busy());
    sp->run(600, 25);
    while(sp->busy());
}

void MusicPlayer::sample2()
{
    sp->run(100, 100);
    sp2->run(70, 1000);
    while(sp->busy());
    sp->run(100, 100);
    while(sp->busy());
    sp->run(10, 1000);
    while(sp->busy());
    sp->run(100, 100);
    while(sp->busy());
    sp->run(10, 1000);
    while(sp->busy());
    sp->run(100, 100);
    while(sp->busy());
    sp->run(10, 1000);
    while(sp2->busy());
    sp2->run(40, 1000);
    while(sp2->busy());
}

void MusicPlayer::sample3()
{
    sp->run(700, 20);
    sp2->run(100, 40);
    while(sp2->busy());
    sp2->run(200, 20);
    while(sp2->busy());
    sp2->run(50, 200);
    while(sp2->busy());
    sp->run(600, 10);
    while(sp->busy());
    sp->run(500, 10);
    while(sp->busy());
    sp->run(400, 10);
    while(sp->busy());
    sp->run(600, 10);
    while(sp->busy());
    sp->run(400, 10);
    while(sp->busy());
    sp->run(10, 100);
    while(sp->busy());
}
