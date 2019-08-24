#include "rend.h"

using rend::height;
using rend::width;
using rend::init_scr;
using rend::render;

int main(int argc, char const *argv[])
{
    char screen[height][width];

    init_scr(screen);
    render(screen, -1);

    return 0;
}
