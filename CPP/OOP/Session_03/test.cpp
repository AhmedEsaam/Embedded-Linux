#include <iostream>

class MyClass
{
public:
    int x, y;

public:
    MyClass(int x = 0, int y = 0) : x(x), y(y) {}

    void print()
    {
        std::cout << x << ' ' << y << std::endl;
    }

    MyClass operator+(const MyClass &obj) const
    {
        int tmpX, tmpY;
        tmpX = x + obj.x;
        tmpY = y + obj.y;
        return MyClass{tmpX, tmpY};
    }

    // Prefix
    MyClass &operator++()
    {
        x++;
        return *this;
    }

    // Postfix
    MyClass operator++(int)
    {
        MyClass tmp = *this;
        x++;
        return tmp;
    }
};

MyClass operator+(const MyClass &obj, int x)
{
    int tmpX;
    tmpX = obj.x + x;
    return MyClass{tmpX, obj.y};
}

class Cars
{
private:
    int arr[5]{1, 2, 3, 4, 5};

public:
    int operator[](const int index) const
    {
        return arr[index];
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
void func3(const int &a)
{
    std::cout << "High" << std::endl;
}

int main(void)
{
    int x = 10;
    const int y = 5;

    func(10);   
    func(x);
    func(y);    

    // func2(10);   // Error: must pass an L-Value
    func2(x); // Ok.
    // func(y);     // Error: argument type must be const as y

    func3(10); // Ok, you can pass an L-Value or R-Value
    func3(x);  // Ok
    func3(y);  // Ok

    // MyClass obj1{2, 3}, obj2{1, 4}, obj3;

    // obj3 = obj1 + obj2;

    // obj3.print();

    // obj3 = obj1 + 5;

    // obj3.print();

    // Cars cars;

    // std::cout << cars[2] << std::endl;

    // ------------------------

    MyClass obj1, obj2;

    obj1 = obj2++;

    obj1.print();

    obj1 = ++obj2;

    obj1.print();

    // postfix return an L-Value
    obj1++ = obj2;

    obj1.print();

    return 0;
}