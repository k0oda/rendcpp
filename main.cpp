#include "rend.h"

using rend::Screen;

#define BACKGROUND '-'

int main(int argc, char const *argv[])
{
    Screen screen(60, 120);

    unsigned short x_center = screen.get_x_center();
    unsigned short y_center = screen.get_y_center();

    char ch;            // User input symbol
    int y_offset = 0;
    int x_offset = 0;

    // Centering player
    int player_x = x_center;
    int player_y = y_center;

    for (int i = 0; i < 120; i++)
    {
        screen.fill_frame(i, BACKGROUND);
        screen.edit_frame(i, x_center, y_center, '[');
        screen.edit_frame(i, x_center + 1, y_center, ']');
    }
    screen.render(5);

    while (true)
    {
        y_offset = 0;
        x_offset = 0;

        system("stty raw");
        ch = getchar();
        if (ch != 0)
        {
            switch(ch)
            {
                case 'w':
                    y_offset = -1;
                    break;
                case 's':
                    y_offset = 1;
                    break;
                case 'a':
                    x_offset = -1;
                    break;
                case 'd':
                    x_offset = 1;
                    break;
                case 'q':
                    system("clear");
                    return 0;
            }
        }
        system("stty cooked");

        player_x += x_offset;
        player_y += y_offset;

        for (int i = 0; i < 120; i++)
        {
            screen.edit_frame(i, player_x - x_offset, player_y - y_offset, BACKGROUND);
            screen.edit_frame(i, player_x - x_offset + 1, player_y - y_offset, BACKGROUND);

            screen.edit_frame(i, player_x, player_y, '[');
            screen.edit_frame(i, player_x + 1, player_y, ']');
        }
        screen.render(1);
        ch = 0;
    }

    return 0;
}
