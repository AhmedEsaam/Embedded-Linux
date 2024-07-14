# C++ - Session 05 Notes - Modern C++ P3

## Strings and String-View

```cpp
std::string str = {"hello"}; // str has a pointer in stack and data is in heap
str = {"No"};

str += {"Yes"};

std::string v* = new std::string {"hello"}; 
// v has a pointer in stack and data is in heap
```

### Strings Essential Functions

```cpp
std::string str;

str.replace(first, cnt, str);
str.replace(0, 5, "New String");

str.find(str, pos);     // returns index of the first occurance or std::string::npos

str.substr(pos, len);   // returns the substring from pos for the len
```

### String View

* Use it to pass strings.

```cpp
#include <string_view>
std::string_view str;   // resembles string pointer, but cannot mutate 

// you can use it to return a "text" from a function.

void func(std::string_view& str)    // more efficient than 'const reference'
{

}
```

---

## Vectors and Arrays
