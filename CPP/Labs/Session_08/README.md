# C++ - Session 08 Notes - Modern C++ P6

## Lambda Expressions

Lambda expressions are anonymous functions commonly used with standard libraries.

It is used as a callback function instead of function pointers.

Syntax:

```txt
[Capture list] (parameters) -> return type
{
    ...
}
```

* Compiler is smart enough to deduce the return type of the lambda function.

### Note

* Captured variables are treated as `const` by default, we can use `mutable` to mutate them.
* Captured **reference variables** are **implicitly mutable**.
* variables inside the lambda functions are always `static`.
* **Static variables** in the wider scope **can be accessed** inside the lambda function.

### Lambda Functions can be stored in avariable

```cpp

int x = 20, w = 30;
int y = 7;
static int z = 10;

auto myLFunc = [x, &w](int y, int u = 5) mutable -> void
{
    x++;    // static (captured vars are treated as const, so we use 'mutable')
    y++;    // static (passed argument) 
    u++;    // static (initialized passed argument)
    w++;    // static (captured reference vars are implicitly mutable)
    z++;    // outside static vars can be accessed inside the lambda function
};

myLFunc(1); // local x = 21, local y = 8, reference w = 31, outside static z = 11
myLFunc(1); // local x = 22, local y = 9, reference w = 32, outside static z = 12

/* The scope outside */
// x = 20   // unchanged
// y = 7    // unchanged

// w = 32   // changed
// z = 11   // changed
```

* **Note:**

```cpp
int x = 5, y = 6;
int u = 9;

auto fun = [ = ] {};        // '=' capture all vars by value
auto fun = [ & ] {};        // '&' capture all vars by reference
auto fun = [ = , &u ] {};   // x and y captured by value, and u by refernce
```

### The compiler treats the lambda function as a class

```cpp
class _Lambda_32
{
    static int z = 10;

private:
    // capture list vars
    int x;
    int &w;

public:
    // functor : is a function object with overloaded paranthesis ()
    inline operator() (int y)
    {
        // code
    }

}

_Lambda_32(y, 5);
```

### To pass a lambda function

```cpp
std::function<int(int)> fn1 = myLambda;

void func( std::function<int(int)> fn2 = myLambda );
```

### Example 1: on using Lambda as a function argument

```cpp
std::vector<int> vec - {1, 2, 3, 4, 5};

std::for_each(vec.begin(), vec.end(), [](int x) { std::cout << x << << std::endl; })
```

### Example 2: using lambda as a callback function

```cpp
void print(std::vector<int> vec, std::function<void(int)> func)
{
    for (auto i : vec)
    {
        func(i);
    }
}

int main(void)
{
    std::vector<int> vec = {1, 2, 3, 4, 5};

    auto myLambda = [] (int x) {std::cout << x << std::endl; };

    std::function<int(int)> fn1 = myLambda;

    print(vec, fn1);

    return 0;
}
```

---

## Algorithms

You can directly use one of the standard algorithms in the `algorithm` library like `std::sort()` and `std::find()`.

---

## Exceptions

An exception is a **Run-Time Error** that can be handles through **Exception Handling**.

Exception handling is done using three keywords:

* `throw`: fires an exception of a specific type in a specific position.
* `try`: checks for exceptions in the enclosed code.
* `catch`: corrects/handles the exception.

```cpp
int x;

std::cin >> x;

try
{
    std::cout << 100 / x;
    
}
catch (std::exception e)
{
    std::cout << "You cannot divide by zero";
}

```

* **Note:** `std::exception` is a general class that throws exceptions on run-time errors which halt the running process.

```cpp
try
{
    throw 100;  // or in a function that is being called here.
    
}
catch (int myException m)
{
    std::cout << "I caught the exception";
}
```

### Example

```cpp
double squareRoot(int val)
{
    if (val < 0)
    {
        throw std::string("you cannot take square for negative numbers");

        return 0;
    }
    sqrt(val);
}

int main(void)
{
    int var = 0;

    try
    {
        squareRoot(var);            // a string exception is throwed in the call
        ...                         // any code here will not run if the above code throws an exception       
    }
    catch(const std::string& ex)    //pass ex by refernce or use std::string_view
    {
        std::cout << ex;
    }

    return 0;
}
```

* We can use more than one catch:

```cpp
try
{
    throw 5;
}
catch (double)
{
    std::cerr << "We catched an exception of type double" << std::endl;
    
}
catch (int)
{
    std::cerr << "We catched an exception of type int" << std::endl;
    
}
catch ( ... )      // Catch any type of exception
{
    std::cerr << "We catched an exception" << std::endl;
    
}
```

---

### Stack Unwinding

* `RAII`: Resource Aquisition Initialization (Any defined container handles its dynamic allocated memory by freeing it when out of scopes).

* Always use standard library containers as they achieve `RAII` as they handles there allocated memory, so no need to worry about non-executed freeing memory in the `try` blocks.

* **Note:** the throwed exception is not stored in stack, because the function can go out of scope but the exception is passed to the calling function of this function.

#### Example of `main()` calling `func_1()` calling `func_2()` calling `func_3()`

| **Stack** | **Code** | **What happens to the throwed exception?** | **What happens to allocated memory?** |
| :----: | :-- | :-- | :-- |
| **main()** | | | |
| **func_1()** | contains a **catch** for `double` | the throwed `double` exception is catched here | |
| **func_2()** | contains a **catch** for `int` | the `double` exception is not catched, so goes to the calling **func_1()** and the rest of **func_2()** is not executed | if the rest code frees an allocated memory, it will not be freed |
| **func_3()** | contains a **catch** for `double` | the `double` exception goes to the calling **func_2()** and the rest of **func_3()** is not executed | if the rest code frees an allocated memory, it will not be freed |

* **IMPORTANT:** always use `try` and `catch` im the main() function to catch any throwed error.
  * If you did not, may be a throwed exception that has not been handled which causes the remained code still be in stack after the termination of the application. And that is **compiler dependent**.

### An Exception Class

You can define an exception class to make the exception carries more than one data variable, each tells a specific info about the exception.

* **Note:** The exception objects must be copyable (do not delete the copy constructor in your created exception class). So as to allow the exception to be copied when copying an object that throws this exception.

* **Note:** In inheritance, to rethrow an exception just use the `throw` keyword without arguments.

* You can use `noexept` with the function to signal the compiler that this function does not throw an exception:

```cpp
void func() noexcept 
{

}
```
