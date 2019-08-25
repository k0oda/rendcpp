#include "rend.h"
#include "sys/ioctl.h"

using rend::Screen;

#define BACKGROUND '-'

int main(int argc, char const *argv[])
{
    winsize w;

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    // Optimizing screen size
    w.ws_col--;
    w.ws_row--;

    unsigned short x_center = w.ws_col / 2;
    unsigned short y_center = w.ws_row / 2;

    Screen screen(w.ws_row, w.ws_col, 60, 120);

    for (int i = 0; i < 120; i++)
    {
        screen.fill_frame(i, BACKGROUND);
        screen.edit_frame(i, x_center, y_center, '[');
        screen.edit_frame(i, x_center + 1, y_center, ']');
    }
    screen.render(5);

    while (true)
    {
        for (int i = 0; i < 120; i++)
        {
            screen.edit_frame(i, x_center, y_center + 1, BACKGROUND);
            screen.edit_frame(i, x_center + 1, y_center + 1, BACKGROUND);

            screen.edit_frame(i, x_center, y_center, '[');
            screen.edit_frame(i, x_center + 1, y_center, ']');
        }
        screen.render(5);

        for (int i = 0; i < 120; i++)
        {
            screen.edit_frame(i, x_center, y_center, BACKGROUND);
            screen.edit_frame(i, x_center + 1, y_center, BACKGROUND);

            screen.edit_frame(i, x_center, y_center + 1, '[');
            screen.edit_frame(i, x_center + 1, y_center + 1, ']');
        }
        screen.render(5);
    }

    return 0;
}
