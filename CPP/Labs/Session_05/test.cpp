#include <iostream>
// #include <initializer_list>

// template <typename T>
void fun(std::initializer_list<int> myList)
{
    for(auto value : myList)        // 'for' ranged loop
    {
        std::cout << value;
    }
}

int main()
{

    fun({1, 2, 3, 4, 5});

    // fun(new int[]{1, 2, 3, 4, 5});

     int x = 5;
    x = 7;

    return 0;
}