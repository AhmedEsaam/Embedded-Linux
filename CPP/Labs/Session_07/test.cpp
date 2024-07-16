#include <iostream>
#include <iomanip>

int main()
{
    int value = 5;
    double newValue = value * 1.1;

    std::cout << std::setw(5) << std::setfill('*') << std::right << newValue << std::endl;

    return 0;
}