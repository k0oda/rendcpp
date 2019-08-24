#include "rend.h"

void rend::init_scr(char screen[][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            screen[i][j] = '#';
        }
    }
}

void rend::render(char screen[][width], int repeat)
{
    unsigned int frame_counter = 0;

    system("clear");
    for (unsigned int repeat_counter = 0; repeat_counter <= repeat; repeat_counter++)
    {
        if (frame_counter <= FPS)
        {
            system("clear");
            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < width; j++)
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