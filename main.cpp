#include "rend.h"

using rend::Screen;

#define BACKGROUND '-'

int main(int argc, char const *argv[])
{
    Screen screen(50, 100, 60, 120);

    for (int i = 0; i < 120; i++)
    {
        screen.fill_frame(i, BACKGROUND);
        screen.edit_frame(i, 50, 25, '[');
        screen.edit_frame(i, 51, 25, ']');
    }
    screen.render(5);

    while (true)
    {
        for (int i = 0; i < 120; i++)
        {
            screen.edit_frame(i, 50, 26, BACKGROUND);
            screen.edit_frame(i, 51, 26, BACKGROUND);
            screen.edit_frame(i, 50, 25, '[');
            screen.edit_frame(i, 51, 25, ']');
        }
        screen.render(5);

        for (int i = 0; i < 120; i++)
        {
            screen.edit_frame(i, 50, 25, BACKGROUND);
            screen.edit_frame(i, 51, 25, BACKGROUND);
            screen.edit_frame(i, 50, 26, '[');
            screen.edit_frame(i, 51, 26, ']');
        }
        screen.render(5);
    }

    return 0;
}
