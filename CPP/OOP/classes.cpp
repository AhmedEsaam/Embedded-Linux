#include <iostream>

using namespace std;

class MyClass
{
public:
    MyClass()       // default constructor
    {
        var1 = 0;
        var2 = 3;
        std::cout << "default constructor" << endl;

    }

    MyClass(int x, int y)
    {
        var1 = x;
        var2 = y;
        std::cout << "parametarised constructor" << endl;
    }

private:
    int var1;
    int var2;
};

int main(void)
{

    MyClass Obj;

    int x = 5;
    int y = 5;
    MyClass Obj2(x, y);

    

    return 0;
}