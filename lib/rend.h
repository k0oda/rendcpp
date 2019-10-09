#ifndef REND_H
#define REND_H

#include <iostream>
#include <vector>
#include <unistd.h>
#include <sys/ioctl.h>

#define HOME "\033[1;1H"

namespace rend
{
    class Screen
    {
    private:
        // Screen size and Frames Per Second
        int height, width, FPS;

        // Time to print one frame
        float frame_time;

        winsize terminal_size;
        unsigned short x_center = terminal_size.ws_col / 2;
        unsigned short y_center = terminal_size.ws_row / 2;

        std::vector<std::vector<std::vector<char>>> frame_list;

        void render_frame(std::vector<std::vector<char>> frame, std::vector<std::vector<char>> prev_frame = std::vector<std::vector<char>>());

    public:
        Screen(unsigned int scr_FPS, unsigned int frames_count, unsigned int scr_height=0, unsigned int scr_width=0);

        unsigned short get_x_center();
        unsigned short get_y_center();

        // Fill frame by symbol
        void fill_frame(unsigned int frame_index, char fill_sym=' ');
        
        // Edit frame's symbol by coordinate
        void edit_frame(unsigned int frame_index, unsigned int x, unsigned int y, char sym=' ');

        // Start rendering process (print all frames from frame_list)
        void render(int repeat=1);
    };
}

#endif