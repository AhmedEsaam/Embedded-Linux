#include <iostream>
#include <array>
#include <cstdlib>
#include <string>

class Vertex
{
private:
    int x, y;

public:
    Vertex() : x(0), y(0)
    {
    }

    Vertex(int x, int y) : x(x), y(y)
    {
    }

    void setX()
    {
        x = rand() % (101 - (-100)) - 100;
    }

    void setY()
    {
        y = rand() % (101 - (-100)) - 100;
    }

    int getX() const
    {
        return x;
    }

    int getY() const
    {
        return y;
    }

    std::string stringVertex()
    {
        return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }
};

int main(void)
{
    /* Defining an std::array of 5 Vertex objects */
    std::array<Vertex, 5> vArr;

    /* Printing the 5 Verteces using class setters and string formatting functions */
    for (int i = 0; i < vArr.size(); ++i)
    {
        vArr[i].setX();
        vArr[i].setY();
        std::cout << "Vertex " << i << ": " << vArr[i].stringVertex() << std::endl;
    }

    return 0;
}