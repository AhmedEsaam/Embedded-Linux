# C++ Search Topics

## Fragmentation

Means that a specific part in memory that you can't access. As if you want to allocated some size nd the free locations required are fragmanted in memory.

### External Fragmentation

* Fragmentation is handled by the OS (but it presents an overhead for the system).

### Internal Fragmentation

* When you allocate memory that is not used (wasted memory).
* You need to optimize your code to avoid that.
* Or use appropriate data structures for each case.

---

## Stack Buffer Overflow

* Happens when a function allocates a bigger size in memory stack than intended.
* Hackers can exploits that to inject code into stack to get executed that may cause harm to the sytem by passing it to a function that take a pointer to character.

* You can counter that by checking the size of the input.

```cpp
#include <iostream>

void func(char* str)
{
    char* myString;
    strcpy(mString, str);

    /*
    Execution
    */
}

int main()
{
    func("program");

    /* You can check the size of the string to make sure that it's not a long code not a simple string input*/

    return 0
}
```

---

## Stack Canary?

---

## Tearing

## False Sharing

## Banker's Algorithm

## Future & Promise
