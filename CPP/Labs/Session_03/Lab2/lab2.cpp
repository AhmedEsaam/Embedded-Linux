#include <iostream>

namespace DynamicAlloc
{
    int ** create2DArray(int size)
    {
        int ** arr = new int*[size];
        return arr;
    }

    void delete2DArray(int** arr, int size)
    {
        for (int i = 0; i < size; ++i)
        {
            delete [] arr[i];
        }

        delete [] arr;
        
        arr = nullptr;
    }
};


int main(void)
{
    const int SIZE = 5;
    int **arr = DynamicAlloc::create2DArray(SIZE);
    DynamicAlloc::delete2DArray(arr, SIZE);

    return 0;
}