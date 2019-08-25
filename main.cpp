#include "rend.h"

using rend::Screen;

int main(int argc, char const *argv[])
{
    Screen screen(50, 100, 60, 120);

    for (int i = 0; i < 120; i++)
    {
        screen.fill_frame(i);
    }
    screen.render(120);

    for (int i = 0; i < 120; i++)
    {
        screen.fill_frame(i, '*');
    }
    screen.render(-1);

    return 0;
}
