#ifndef REND_H
#define REND_H

#include <iostream>
#include <unistd.h>

namespace rend
{
    // Screen size
    const int height = 15;
    const int width = 15;

    // Frames Per Second
    const int FPS = 60;

    void init_scr(char screen[][width]);
    void render(char screen[][width], int repeat=1);
}

#endif