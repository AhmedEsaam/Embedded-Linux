# C++ - Session 05 Notes - Modern C++ P3

## Initialiser List

### The Uniform initialisation

* Prevent narrowing (prevent implicit casting)

```cpp
int myVar {5.7};      // initialiser list
```

### Initialiser list provided by C++

* You can't iterate on a normal array with a for ranged loop.

* Comes handy when we want to pass a list we don't know the size of.

* Works by an `iterator` with `.begin` and `.end`.

```cpp
void fun(std::initializer_list<int> myList)
{
    for(auto value : myList)        // 'for' ranged loop
    {
        std::cout << value;
    }
}

int main()
{

    fun(new int[]{1, 2, 3, 4, 5});

    return 0;
}

```

* **Note:** The for ranged loop will work on containers including the normal array but not the dynamically allocated array as it can't specify its size, begin, end.

### Initialiser List Template

```cpp
template <typename T>
void fun(std::initializer_list<T> myList)
{

}
```

---

## Default Function Argumnets

* Before calling the function, the passing arguments will be resolved into the function arguments.

* Start giving default arguments with the **right most argumnets**.

```cpp
void sum(int x = 0, int y = 0)
{
    return x + y;
}

int main()
{
    sum(1, 2);

    sum();      // will work normally (x = 0, y = 0)

    sum(70);

    return 0;
}

```

* The compiler will start assiggning values starting from the left.

```cpp
void sum2(int x, int y, int z = 0, int w = 0)
{
    return x + y + z + w;
}

int main(void)
{
    sum2(2, 3);    // x = 2, y = 3, z = 0, w = 0

    return 0;
}
```

* **Note:** You must specify the default args only in the function declaration, not the definition.

```cpp
void sum(int x = 10, int y = 9, int z = 0, int w = 0);

void sum(int x, int y, int z, int w)
{

}
```

### Avoid Ambiguity

* Default Argumnets provide only one implementation (there is no function overloading here)

* The compiler will insert default args at function call

* The compiler will not know which function to call.

```cpp
void print(int x = 50);
void print(int x, int y, int z = 0);

int main(void)
{
    print(1, 2);
    print(1);       // ambiguous, which one to call?!

    return 0;
}
```

---

## Constant Expression

* In C, you can overwrite a local const variable by a pointer.

* In C++, you can't do that.

```cpp
const int x = 1;

const int const* y = &x;    // const ptr pointing to const data
```

* `constexpr` will resolve in compile-time unless their is an expression that requires to be resolved in run-time (like cin).

* `constexpr` will take more time in compilation.

```cpp
constexpr int var = 5;

constexpr int fun(constexpr int v)
{
    ...

    return ;
}

int main(void)
{
    constexpr int myX = fun(30);    // this whole line is resolved in compile-time

    return 0;
}
```

* Use `constexpr` to make the application more responsive in run time in expense of the compile-time.

### `const` vs `constexpr`

| **const** | **constexpr** |
| :---- | :---- |
| resolved in run-time | resolved in compile time |
| used with variables, pointers or functions | used with variables, functions, or `constexpr` if-statemnet |

* const as return of function is not useful unless its a const ptr

```cpp
const int getvalue()
{
    return 42;
}

int main(void)
{
    int x = getValue();     // works properly

    return 0;
}
```

---

## L-value and R-value

Important in move semantics.

### lvalue

Any evaluated expression that **have an address**.

```cpp
int x = 20;

// Note:
auto val = "is it lvalue?"; //.. evaluates to const char
// any c-style string is an l-value
```

### rvalue

Any value with **no address** (like literals)

```cpp

// you can't do this:
// 20 = x;

obj = MyClass();        // MyClass() is an rvalue of user defined type

```

---

## Reference

* The Reference is an alias.

```cpp
int x = 20;
int& ref = x;       // ref (lvalue reference) is an alias of x
ref = 70;           // x = 70;

int y = 5;
ref = y;            // x = y;
```

* The reference does not occupy a space but it sometimes does in which you can view the reference as a dereferenced const pointer.

### Passing by reference

```cpp
void print(int& var)
{
    var++;
    std::cout << var;
}

int main(void)
{
    int c = 0;
    print(c);   // c = 1
    print(c);   // c = 2

    return 0;
}
```

* If you instead use a pointer, you might pass a nullptr, but passing by reference will not allow that as it expects an lvalue.

* Use PAssing by address with arrays and use passing by reference to pass other types.

### **lvalue** reference and **rvalue** reference

```cpp
// lvalue reference
int x = 20
int& ref = x;
//or
auto& ref = x;


// rvalue reference (used with move semantics)
int&& ref = 5;


// Note: the reference must be initialized when declared
// int& ref;   //error
```

* You can make a reference to a pointer. But it's not useful.

```cpp
int x = 0;
int* p = &x;

int*& pRef = p;
*pRef = 5;
```

### const reference

```cpp
const int& ref = 5;
```

* Ypu can use it to make a function argumnet that can bind to an lvalue or an rvalue

```cpp
void print(const int& ref)
{
    std::cout << ref;
}

int main(void)
{
    int x = 20;
    print(x);       // you can pass an lvalue

    print(20);      // ypu can pass an rvalue to the same function

    return 0;
}
```

### Dangling Reference

* reference has lifetime when it's binded varibale is deleted.

```cpp
int x = 20;
int var = new int {5};
int& ref = var;

delete var;
// the 'ref' is now a dangling reference 
```
