# OOP - Session 02

## Operator Overloading

```cpp
#include <iostream>

class MyClass
{
private:
    int x, y;

public:
    MyClass(int x = 0, int y = 0) : x(x), y(y) {}

    void print()
    {
        std::cout << x << ' ' << y << std::endl;
    }

    // Member function
    MyClass operator+(const MyClass &obj2) const
    {
        int tmpX, tmpY;
        tmpX = x + obj2.x;
        tmpY = y + obj2.y;
        // R-Value
        return MyClass{tmpX, tmpY};
    }
};

int main(void)
{
    MyClass obj1{2, 3}, obj2{1, 4}, obj3;

    obj3 = obj1 + obj2;

    obj3.print();
    

    return 0;
}
```

* **Side Note:**

```cpp
int* add(int x)
{
    int h = 10;
    return &h;  // you here return a dangling pointer of unallocated memory
}
```

* You can create a standalone function operator overloader

```cpp
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
};

// A stand alone function that can operate on the MyClass argument (but it does not have access to its private or protected data)
MyClass operator+(const MyClass &obj, int x)
{
    int tmpX;
    tmpX = obj.x + x;
    return MyClass{tmpX, obj.y};
}

int main(void)
{
    MyClass obj1{2, 3}, obj2;

    obj2 = obj1 + 5;

    obj2.print();

    return 0;
}
```

* Using Operator Overloading on `[]` to return member array data

```cpp

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

int main(void)
{
    
    Cars cars;

    std::cout << cars[2] << std::endl;

    return 0;
}
```

### Prefix and Postfix

```cpp
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

    // Prefix (0returns an L-Value)
    MyClass &operator++()
    {
        x++;
        return *this;
    }

    // Postfix (Returns an L-Value)
    MyClass operator++(int)
    {
        MyClass tmp = *this;
        x++;
        return tmp;
    }
};

int main(void)
{
    MyClass obj1, obj2;

    obj1 = obj2++;
    obj1.print();

    obj1 = ++obj2;
    obj1.print();

    obj1++ = obj2;
    obj1.print();


    return 0;
}
```

---

## Move Semantics

* Using a doublr reference to initialize a new variable

```cpp
int x = 5;
int &&var = 2 + 3 + x;
```

* Normally it is created a tmp variable to calculate (2 + 3 + x), then copying its value to var.
* But when using the double reference, the var address will be equal to tmp directly without copying tmp value (it might be an object with many data members).

* **tmp** value is considered a **pr-value** (you can see it as the tmp is initially an r-value that got promoted to l-value)

```cpp
void func(int a)
{
    std::cout << "normal" << std::endl;
}
void func2(int &a)
{
    std::cout << "medium" << std::endl;
}
void func3(const int &a)    // const int &a : accepts r-value but you CANNOT alter its value
{
    std::cout << "High" << std::endl;
}
void func4(int&& var)       // int && var : accepts r-value but you CAN alter its value
{
    var = 10;
    func2(var);
}

int main(void)
{
    int x = 10;
    const int y = 5;
    int&& var = 2 + 3 + x;

    func(10);       // Ok
    func(x);        // ok, x an l-value implicitly casted to r-value
    func(y);        // ok, x an l-value implicitly casted to r-value

    // func2(10);   // Error: must pass an L-Value
    func2(x);       // Ok.
    // func(y);     // Error: argument type must be const as y

    func3(10);      // Ok, you can pass an L-Value or R-Value
    func3(x);       // Ok
    func3(y);       // Ok

    func4(10);
    func4(x);
    func4(y);
    func4(var);

    return 0;
}
```

* **Note:** Passing by refernce does not require you to make any further checking in the argument like you would do with passing pointers as you have to check for the null pointer before using it.


