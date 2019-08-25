#ifndef REND_H
#define REND_H

#include <iostream>
#include <vector>
#include <unistd.h>


namespace rend
{
    class Screen
    {
    private:
        // Screen size and Frames Per Second
        int height, width, FPS;
        float frame_time;

        std::vector<std::vector<char>> frame;
        std::vector<std::vector<std::vector<char>>> frame_list;

        void render_frame(std::vector<std::vector<char>> frame);

    public:
        Screen(unsigned int scr_height, unsigned int scr_width, unsigned int scr_FPS, unsigned int frames_count);
        void fill_frame(unsigned int frame_index, char fill_sym='#');
        void edit_frame(unsigned int frame_index, unsigned int x, unsigned int y, char sym=' ');
        void render(int repeat=1);
    };
}

#endif