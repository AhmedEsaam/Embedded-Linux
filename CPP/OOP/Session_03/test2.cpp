#include <iostream>

class Example
{
public:
    int x, y;

    Example() = default;

    Example(int x, int y) : x(x), y(y) {}

    Example(const Example &obj) // for copy
    {
    }

    Example(Example &&obj)
    {
    }
};

void func(int a)
{
    std::cout << "normal" << std::endl;
}
void func2(int &a)
{
    std::cout << "medium" << std::endl;
}
void func2(const int &a) // const int &a : accepts r-value but you CANNOT alter its value
{
    std::cout << "High" << std::endl;
}
void func2(int &&var) // int && var : accepts r-value but you CAN alter its value
{
    std::cout << "Ultra" << std::endl;
    var = 10;
    func2(var);
}
void func2(Example &&var) // int && var : accepts r-value but you CAN alter its value
{
    std::cout << "Ultra" << std::endl;
    var = 10;
    func2(var);
}

int main(void)
{
    int x = 10;
    const int y = 5;
    int &&var = 2 + 3 + x;

    // func(10); // Ok
    // func(x);  // ok, x an l-value implicitly casted to r-value
    // func(y);  // ok, x an l-value implicitly casted to r-value

    // func2(10);   // Error: must pass an L-Value
    // func2(x); // Ok.
    // func(y);     // Error: argument type must be const as y

    // func3(10); // Ok, you can pass an L-Value or R-Value
    // func3(x);  // Ok
    // func3(y);  // Ok

    func2(10);
    func2(x);
    func2(y);
    func2(var);

    return 0;
}