# C++ - Session 06 Notes - Modern C++ P4

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

```cpp
#include <vector>

std::vector<int> v = {1, 2, 3, 4, 5};

std::vector v2(5);      // 5 elements

std::vector v3(5, 0);   // 5 elements initialized with zero

v.push_back(value);
v.pop_back(value);

v.insert();
v.erase();
v.resize();

//2-d vector 
std::vector<std::vector<int>> v2d = {{1, 2, 3},
                                    {4, 5}};

v2d[0].push_back(20);
v2d.push_back({11,12,13});      // weak performance because of reallocating vector
```
