#include <iostream>

namespace DynamicAlloc
{
    int ** create2DArray(int rows, int cols)
    {
        int ** arr = new int*[rows];

        for (int i = 0; i < rows; ++i)
        {
            arr[i] = new int[cols];
        }

        return arr;
    }

    void delete2DArray(int** arr, int rows)
    {
        for (int i = 0; i < rows; ++i)
        {
            delete [] arr[i];
        }

        delete [] arr;
        
        arr = nullptr;
    }
};


int main(void)
{
    const int ROWS = 3, COLS = 5;
    int **arr = DynamicAlloc::create2DArray(ROWS, COLS);
    DynamicAlloc::delete2DArray(arr, ROWS);

    return 0;
}