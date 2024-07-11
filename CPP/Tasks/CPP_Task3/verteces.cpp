#include <iostream>
#include <cstdlib>

/* Declaring Vertex Structure */
struct Vertex
{
    int x, y;
};

int main()
{
    int a, b;
    Vertex vArr[5];

    /* For every Vertex, generate random x and y */
    for (int i = 0; i < 5; ++i)
    {
        /* random number in the range [-100, 100] */
        /*
            rand() % the range (max - min) will generate a number between 0 and (max - min)
            Then take that and add min. This will yoeld a number with minimum (min) and maximum (max)
        */
        a = rand() % (101 - (-100)) - 100;
        b = rand() % (101 - (-100)) - 100;

        /* Assgning the random values to verrex x and y */
        vArr[i].x = a;
        vArr[i].y = b;

        /* Printing each vertex */
        std::cout << "Vertex" << i << ": (" << vArr[i].x << ", " << vArr[i].y << ")" << std::endl;
    }

    return 0;
}