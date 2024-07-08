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
