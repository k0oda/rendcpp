#include "rend.h"

rend::Screen::Screen(unsigned int scr_height, unsigned int scr_width, unsigned int scr_FPS, unsigned int frames_count)
{
    height = scr_height;
    width = scr_width;
    FPS = scr_FPS;
    frame_time = 1 / (float) FPS;
    
    frame_list.resize(frames_count);
    for (int i = 0; i < frame_list.size(); i++)
    {
        frame_list[i].resize(height);
        for (int j = 0; j < height; j++)
        {
            frame_list[i][j].resize(width);
        }
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

void rend::Screen::render_frame(std::vector<std::vector<char>> frame)
{
    std::string output_str;

    std::cout << "\033[1;1H";   // Reset cursor position
    for (int i = 0; i < this->height; i++)
    {
        for (int j = 0; j < this->width; j++)
        {
            std::cout << frame[i][j];
        }
        std::cout << std::endl;
    }
}

        {
            sleep(1);
            frame_counter = 0;
        }
    }
}