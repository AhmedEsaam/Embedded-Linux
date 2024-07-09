# C++ - Session 04 Notes - Modern C++ P2

## Structs

* You can basically use struct the same as you use classes, However it's not recommended to use it as classes. The most common use of structs is as a **data structure**.

### Similarities between **Structs** and **Classes**

In both structs and classes:

1. You can make constructor and destructor
2. functions
3. Access specifiers (private, public, protected)

### Differences between **Structs** and **Classes**

### Struct Example

```cpp
// Struct as a data struct
struct Employee
{
    char firstInitial{};
    char lastInitial{};
    int employeeNumber{};                        
}

Employee Mohamed{'h','s', 4};
```

```cpp
// Struct as a class blueprint
struct Employee
{
    char firstInitial{};
    char lastInitial{};
    int employeeNumber{};  

    /* Copy Constructor */
    Employee(const Employee &other)
    {
        firstInitial = other.firstInitial; 
        lastInitial = other.lastInitial;
        employeeNumber = other.employeeNumber;
    }             

    void getSalary()
    {

    }
}

Employee Mohamed{'h','s', 4};   // you can't use this unless you define a parametarised constructor
```

## Enums

* The size of enum is integer (compiler dependent)

### Unscoped Enum

```cpp
enum e : int8_t
{
    fisrt, second, third
}

e val = second;

if(val == 1);   // val is implicitly converted to integer => this works
```

### Scoped Enum (Class)

```cpp
enum class E : 
{
    fisrt, second, third
}

e val = second;

if(val == 1);           // This will not work as val is of type 'enum'
if(val == E::second);   // This will work

// You must cast the class enum value to use it as integer
int myInt{static_cast<int>(third)};     // Okay
```

* Class enum is handy if you changed the values in the enum class. As the dependent code will not change.

---

## Containers Classes

Encapsulated classes of containers with elevant attributes and methods.

### Array

```cpp
#include <array>

std::array<int, 5> arr {1, 2, 3, 4, 5};

int size = arr.size();      // 5

int item = arr.at(3);
cout << item << endl;

for(auto val : arr)
{
    cout << val << endl;
}

```

### String

* `string` is better than c-style string in that it has more functions and easy to deal with strings.

```cpp
std::string str {"hossam"};

str = "Hi";

// string size
cout << str.length() << endl;
cout << str.size() << endl;

// append
str.append(" Mutafa");
str += "!";
```

---

## Function Overloading

### Function Signature

1. Function Name
2. Number of Arguments
3. Type of parameters
4. const or volatile
5. Reference or pointer

Note: **The return type** is not considered as one of the signature differences.

```cpp
void print(void)
{
    std::cout << "print(void)" << std::endl;
}

void print(int x)
{
    std::cout << "print(" << x << ")" << std::endl;
}

int main()
{
    print();
    print(5);

    return 0;
}
```

* **Note:** if the argument types does not match the call, the compiler may do an implicit cast for passed arguments to fit the types

```cpp
void print(int x, int y)
{
    ...
}

void print(double x, int y)
{
    ...
}

int main()
{
    print('a', 5);      // will work. As 'a' will be casted to int

    print(2.225f, 5);   // will work. As 2.225f will be casted to double
    
    return 0;
}
```

---

## Templates

Templates is a way for generic programming.

```cpp
template <typename T>
void print(T var)
{

}
```

* **Note:** If you want to pass two different data types, you need to provide two typenames (as the **compiler will resolve a typename to only one data type**)

```cpp
template <typename T>
T max(T a, T b)
{
    return (a > b)? a : b;
}

```

```cpp
template <typename T1, typename T2>
void setPair(T1 first, T2 second)
{

}

int main()
{
    std::cout << setPair<int, double>(6, 5.36) << endl;
    std::cout << setPair<int, double>('a', 5.36f) << endl;  // will make implicit casting to match types to the template types    

    return 0;
}
```

* To make an exception of a certain data type to make the template not accepts it:

```cpp
void setPair(std::string, std::string) = delete;

// to delete the function where only the first arg is string and the second is any type
template <typename T1, typename T2>
void print(std::string, T2) = delete;

template <typename T1, typename T2>
void print(T1 a, T2 b)
{
    std::cout << a << b << std::endl;
};

int main()
{
    print<int, int>(5, 6);
    print<std::string, int>("a", 6);    // Compiler Error

    return 0;
}
```

* You can do that in a class to prohibit the compiler from creating the default constructor:

```cpp
class myClass
{
    myClass() = delete;

    myClass(int var1, int var2)
    {

    }
}
```

* To restrict the template to specific data types

```cpp
template<std::same_as<int> T>       // c++20
T max(T a, T b)
{
    return (a > b)? a : b;
}
```

---

## Name Mangling

Is the process in which the compiler change the name of the functions with differenet signature or a template function to make different implementation.

* You can see these different names in the debug symbols.
