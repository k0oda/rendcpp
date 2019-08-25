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

void rend::Screen::fill_frame(unsigned int frame_index, char fill_sym)
{
    for (int i = 0; i < this->height; i++)
    {
        for (int j = 0; j < this->width; j++)
        {
            this->frame_list[frame_index][i][j] = fill_sym;
        }
    }
}

void rend::Screen::render_frame(std::vector<std::vector<char>> frame)
{
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

void rend::Screen::render(int repeat)
{
    unsigned int counter = 0;

    system("clear");
    system("setterm -cursor off");  // Hide cursor
    while (counter <= repeat)
    {
        for (std::vector<std::vector<char>> frame : frame_list)
        {
            sleep(frame_time);
            this->render_frame(frame);
        }
        counter++;
    }
    system("setterm -cursor on");   // Show cursor
}