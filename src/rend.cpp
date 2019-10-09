#include "rend.h"

rend::Screen::Screen(unsigned int scr_FPS, unsigned int frames_count, unsigned int scr_height, unsigned int scr_width)
{
    FPS = scr_FPS;
    frame_time = 1 / (float) FPS;

    if (scr_height and scr_width > 0)
    {
        height = scr_height;
        width = scr_width;
    } else
    {
        // Get size of terminal window
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &terminal_size);

        // Optimizing screen size
        terminal_size.ws_col--;
        terminal_size.ws_row--;

        height = terminal_size.ws_row;
        width = terminal_size.ws_col;
    }

    x_center = width / 2;
    y_center = height / 2;

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

unsigned short rend::Screen::get_x_center()
{
    return this->x_center;
}

unsigned short rend::Screen::get_y_center()
{
    return this->y_center;
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

void rend::Screen::edit_frame(unsigned int frame_index, unsigned int x, unsigned int y, char sym)
{
    this->frame_list[frame_index][y][x] = sym;
}

void rend::Screen::render_frame(std::vector<std::vector<char>> frame, std::vector<std::vector<char>> prev_frame)
{
    std::cout << HOME;   // Reset cursor position

    if(prev_frame.empty())
    {
        for (int i = 0; i < this->height; i++)
        {
            for (int j = 0; j < this->width; j++)
            {
                std::cout << frame[i][j];
            }
            std::cout << std::endl;
        }
    } else
    {
        for (int y = 0; y < this->height; y++)
        {
            if(prev_frame[y] != frame[y])
            {
                for (int x = 0; x < this->width; x++)
                {
                    if(prev_frame[y][x] != frame[y][x])
                    {
                        std::cout << "\033[" << y << ";" << x << "H";   // Move cursor to y;x position
                        std::cout << frame[y][x];
                    }
                }
            }
        }
    }
}

void rend::Screen::render(int repeat)
{
    unsigned int counter = 0;

    system("setterm -cursor off");  // Hide cursor
    while (counter <= repeat)
    {
        for (int i = 0; i < this->frame_list.size(); i++)
        {
            sleep(frame_time);
            if(i == 0)
            {
                this->render_frame(this->frame_list[i]);
            } else
            {
                this->render_frame(this->frame_list[i], this->frame_list[i - 1]);
            }
        }
        counter++;
    }
    system("setterm -cursor on");   // Show cursor
}