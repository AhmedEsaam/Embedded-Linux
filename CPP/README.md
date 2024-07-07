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

```cpp
// allocating int
int * p = new int {5};
delete ptr;

// allocating array of ints
int * arr = new int[5]{1, 2, 3, 4, 5};
delete[] arr;

// allocating 2-D array
int ** arr_2d = new int*[5]     // the arr_2d pointer resides in stack but points to pointers in heap
                                // every one of them points to memory in heap

// Deallocating the 2-D array.
// First, use for loop to delete the pointers in the arr_2d array
// Second, deallocate the 2-D array.
delete[] arr_2d;
```

* When creating an object with `new`, it calls the constructor.
* if you used `malloc` instead, it'll not call the constructor. It only allocates memory.

```cpp
MyClass * Hussam = new MyClass();   // calls the constructor
```

* To delete allocated memory properly

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

## References

* Professional C++, 6th Edition by Marc Gregoire (**Book**)

* C++ Insights (**site**)         -> reduce code to simplified code

* Compiler Explorer (**site**)    -> reduce code to assemply
