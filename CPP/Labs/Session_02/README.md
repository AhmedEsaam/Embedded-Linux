# Session Notes

```cpp

#include <iostream>
using namespace std;

/* RTE depends on callback function (function pointers) */

/* Sort function*/
void sort(void *base, size_t ntimes, size_t size, int (*compare)(const void *, const void *))
{
    qsort(base, ntimes, size, compare);
}

/* Function pointer typedef for event handler func */
typedef void (*EventHandler)(void *);

/* Function pointer to a 2d array that returns an array of integers */
typedef int* (*CallbackFunc)(int** arr_2d, int arr_size, int* row_size, int (*func)(int*, int));

```

## How to return more than 1 value from a function

1. by pointer
2. by struct
3. static array
4. combine them in one big var using shit bits

* File system is defined based on the passing of the function operations.
