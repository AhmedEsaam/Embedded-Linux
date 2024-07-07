# C++

## Namespace

* A block where you can write code.
* Allows you to define more than one function with the same signature.

```cpp
{
    void fun()
    {
        cout << "ffrom func" << endl;
    }
}

int main()
{
    myNS::func();
}
```

* When calling a function, the namespace name can be omitted if you use `using namespace` followed by the name of the namespace in the beginning of your block of code.

```cpp
using namespace myNS;
```

### Why you don't want to use `using namespace`?

* Because in big applications, you might have for example the `std` functions and classes defined in another namespace with different implementation.

* This would creat **ambiguity** when you put `using namespace` for both namespaces, as the compiler would not know which implementation to call.

### Unnamed namespace

* The most common case to use it is to craete private code to this file that cannot be accessed outside.
* All identifiers inside it will have private internal linkage.

```cpp
namespace
{
    int var;
    void f()
    {
        ...
    }
}

int main()
{
    f();
}
```

## Type Alias

* Alias of types (like `typedef`)

```cpp
using uint32 = int;     // instead of 'typedef'

uint32 var;
```

* Alias of nested namespaces

```cpp
namespace MyFTP = MyLibraries::Networking::FTP;
```

---

## Initialization

There are 4 types of initialization:

### 1. Copy init

* Don't use it!

```cpp
int x = 5;
```

### 2. Direct init

```cpp
int y(6);
```

### 3. list (uniform) init

* Don't allow implicit conversions as it make type checking.

```cpp
int y{7};
int y = {7};

int x = 80.8;   // will run but truncates the value without error
int x {80.8};   // will make type checking

// unnitialized
int x{};
```

### 4. Aggregate init

```cpp

.name = 7;
.age = 25

```

---

## For Loops

### For Ranges (iterators)

* Used with containers to quickly iterate over elements

```cpp
int arr = {1, 2, 3, 4};

// 'val' is the iterator, 'arr' is the init list
for(int val : arr)
{
    std::cout << val << endl;
}
```

---

## Dynamic Allocation (`new`, `delete`)

* Don't use `malloc`.
* `new` is an operator not a function. Which means that the compiler handles it **without context switching**.
* `new` returns **exception** if failed to allocate memory.
* `delete` **calls the destructor**, while `free` **doesn't call the destructor**

### Allocating int

```cpp
int * p = new int {5};
delete ptr;
```

### Allocating array of ints

```cpp
int * arr = new int[5]{1, 2, 3, 4, 5};
delete[] arr;
```

### Allocating 2-D array

```cpp
// the arr_2d pointer resides in stack but points to pointers in heap. Every one of them points to memory in heap
int ** arr_2d = new int*[rows]
for (int i = 0; i < rows; ++i)
{
    arr_2d[i] = new int[cols];
}
```

### Deallocating the 2-D array

```cpp
// First, use for loop to delete the pointers in the arr_2d array
for (int i = 0; i < rows; ++i)
{
    delete [] arr_2d[i];
}
// Second, deallocate the 2-D array.
delete [] arr_2d;
// Make the 2-D array pointer equal Null
arr_2d = nullptr;
```

### Notes

* When creating an object with `new`, it calls the constructor.
* if you used `malloc` instead, it'll not call the constructor. It only allocates memory.

```cpp
MyClass * Hussam = new MyClass();   // calls the constructor
```

### To delete allocated memory properly

```cpp
int * ptr = new int(5);
delete ptr;     // deallocate memory
ptr = nullptr;  // null the pointer

delete ptr;     // if you did this, nothing will happen (safe) despite 'delete' is used with allocated memory in heap and ptr is in stack (it's handled by the compiler)
```

### Example

```cpp
int **arr CString = new int*[5];

for (int i = 0; i < 5; ++i)
{
    arr_CString[i] = new int[5];
}

// Freeing the 2-D array
for (int i = 0; i < 5; ++i)
{
    delete [] arr_CStrings[i];
}

delete arr_CStrings;

```

* **Note:** You can handle deallocations using **smart pointers**.
* **Note:** C++ doesn't have garbage collector.

---

## Static casting

* Better as it does type checking

```cpp
float var;
static_cast<int> var;
```

---

## Linkage and Scope

### No Linkage

* Like **local** variables.

### Internal Linkage

* Private definitions (Like **static variables**, namespaces, etc.)

### External Linkage

* Any definitions visible withing the whole application (Like **Global** variables.)

---

## Type Inference

Allows the compiler to automatically infer the type of the object

### Using `auto` keyword

* Used with complex data types, in `lambda function`, and `for ranged`

```cpp
auto x = 20.5;      // compiler will define x as double 
```

* Checks the type of the object. Used with `templates`.

```cpp
const string message { "Test" };

const string& foo() { return message;}

const auto& f2 { foo() };

for(auto v : {1, 2, 3, 4, 5})
{
    cout << v;
}
```

### Using `decltype()`

```cpp
#include <typeinfo>

int x {123};

decltype(x) y {456};

cout << typeid(y).name();   // prints 'i' : stands for integer
```

---

## References

* Professional C++, 6th Edition by Marc Gregoire (**Book**)

* C++ Insights (**site**)         -> reduce code to simplified code

* Compiler Explorer (**site**)    -> reduce code to assemply

---

## Pair (std::pair)

is a Template Container with two elemnts (can take two different data types).

```cpp
std::pair x {1, 2.2};
cout << x.first;
cout << x.second;

std::pair<int, double> y {5, 2.2};
cout << y.first;
cout << y.second;

std::make_pair<int, double> y {8, 2.2};
```

---

## Structuredd Binding (with `auto`)

```cpp
int values[] {10, 20, 30};

auto [x, y, z] { values };
```
