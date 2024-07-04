#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int size = 0;
    cin >> size;
    char **arr = (char **)calloc(size, sizeof(char *));
    
    for (int i = 0; i < size; ++i)
    {
        char buffer[100];
        arr[i] = (char *)calloc(strlen(buffer) + 1, sizeof(char));
        cin >> *(arr + i);
    }

    for (int i = 0; i < size; ++i)
    {
        cout << *(arr + i) << "\n";
    }

    for(int i = 0; i < size; ++i)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}