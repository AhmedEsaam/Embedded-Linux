#include <iostream>

class RCC
{
protected:
    int x, y;
};

class GPIO : public RCC
{
    int x;

    int getRCC_x()
    {
        return RCC::x;
    }
};

class Example 
{
    private:
    int x;

    friend class MyClass;

    friend void function(Example e);
};

void function(Example e)      // function() is friend to the Example class, so, it can access private members
{
    std::cout << e.x << std::endl;
}

class MyClass
{
private:
    Example obj;                // MyClass has access to obj private members

public:
    int getX()
    {
        return obj.x;
    }
};

int main()
{
    

    return 0;
}