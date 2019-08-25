#include "rend.h"

using rend::Screen;

int main(int argc, char const *argv[])
{
    Screen screen(15, 15, 60);

    screen.init_scr();
    screen.render(-1);

    return 0;
}
