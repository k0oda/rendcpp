#ifndef REND_H
#define REND_H

#include <iostream>
#include <unistd.h>


namespace rend
{
    class Screen
    {
    private:
        // Screen size and Frames Per Second
        int height, width, FPS;

    // Frames Per Second
    const int FPS = 60;

    public:
        Screen(unsigned int scr_height, unsigned int scr_width, unsigned int scr_FPS);
        void init_scr();
        void render(int repeat=1);
    };
}

#endif