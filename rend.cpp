#include "rend.h"

rend::Screen::Screen(unsigned int scr_height, unsigned int scr_width, unsigned int scr_FPS)
{
    height = scr_height;
    width = scr_width;
    FPS = scr_FPS;
    frame_time = 1 / (float) FPS;
    
    screen.resize(height);
    for (int i = 0; i < height; i++)
    {
        screen[i].resize(width);
    }
}

void rend::Screen::init_scr()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            this->screen[i][j] = '#';
        }
    }
}

void rend::Screen::render(int repeat)
{
    unsigned int frame_counter = 0;

    system("clear");
    for (unsigned int repeat_counter = 0; repeat_counter <= repeat; repeat_counter++)
    {
        if (frame_counter <= this->FPS)
        {
            system("clear");
            for (int i = 0; i < this->height; i++)
            {
                for (int j = 0; j < this->width; j++)
                {
                    std::cout << screen[i][j];
                }
                std::cout << std::endl;
            }
            frame_counter++;
        } else
        {
            sleep(1);
            frame_counter = 0;
        }
    }
}