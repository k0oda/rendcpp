#include <iostream>
#include <unistd.h>

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char const *argv[])
{
    const int height = 15;
    const int width = 15;

    system("clear");

void init_scr(char screen[][width]);

int main(int argc, char const *argv[])
{
    char screen[height][width];

    init_scr(screen);

    unsigned int counter = 0;

    while (true)                    // Infinite render
    {
        if (counter <= 60)
        {
            system("clear");
            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    cout << screen[i][j];
                }
                cout << endl;
            }
            counter++;
        } else
        {
            sleep(1);
            counter = 0;
        }
    }
    return 0;
}

void init_scr(char screen[][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            screen[i][j] = '#';
        }
    }
}
