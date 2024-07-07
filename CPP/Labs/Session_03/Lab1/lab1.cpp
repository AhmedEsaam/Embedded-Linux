#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

namespace MathFunctions
{
    void print(double num)
    {
        std::cout << sqrt(num) << std::endl;
    }
};

namespace StringFunctions
{
    void print(std::string strr, std::string type)
    {
        std::string str = strr;
        if(type == "lower")
        {
            std::transform(str.begin(), str.end(), str.begin(), ::tolower);
            std::cout << str << std::endl;
        }
        else if(type == "upper")
        {
            std::transform(str.begin(), str.end(), str.begin(), ::toupper);
            std::cout << str << std::endl;
        }
    }
};

namespace ArrayFunctions
{
    void print(int arr[], int size)
    {
        for (int i = size - 1; i >= 0; --i)
        {
            std::cout << arr[i] << std::endl;
        }
    }
}

int main()
{
    double doubleVar = {25.0};
    std::string str = {"Hello"};
    std::string type1 = {"lower"};
    std::string type2 = {"upper"};
    int arr[] = {1, 2, 3, 4, 5};

    MathFunctions::print(doubleVar);
    StringFunctions::print(str, type1);
    StringFunctions::print(str, type2);
    ArrayFunctions::print(arr, 5);
    return 0;
}
