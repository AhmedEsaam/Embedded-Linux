# C++ - Session 07 Notes - Modern C++ P5

## I/O Straems

* `cin` invokes a system call which is a **wrapper function** that notifies the kernel that a reading from the keyboard is expected.

```cpp
std::string var;

cin >> var;
```

### Output Types

| Unbuffered Output | Buffered Output |
| :--- | :--- |
| instant printing character by character on the creen | Data is saved into a buffer container, then printed as a whole |
| Used in I/O files, network and standard output streams | used in debugging |

### Manipulators

#### For output

```cpp
using namespace std;

cout << setw(5) << setfill('*') << right << "hello";

cout << setprecision(3) << fixed << 44.123;     // 44.123   // fixed means: always put the floating point
cout << setprecision(3) << 44.123;              // 44.1
```

#### For input

```cpp
cin >> set(10) >> buf;

cin.get(buf, 10);
```

* **Note:** std::endl: inserts a newline character and flushes the stream.

##### Example

```cpp
#include <iostream>
#include <iomanip>

int main()
{
    int value = 5;
    double newValue = value * 1.1;

    std::cout << std::setw(5) << std::setfill('*') << std::right << newValue << std::endl;

    return 0;
}
```

---

## Files I/O

```cpp
#include <fstream>

std::ofstream out{"test.txt", std::ios::out};   // mode: out by default
if (!out)
{
    std::cerr << "Error opening output file" << std::endl;
}

out << "Hello";

out.close();

std::fstream fio;
fio.open("example.txt", std::ios::in | std::ios::out);
```
