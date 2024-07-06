#include <stdio.h>

int binary_search (int* arr, int size, int item)
{
	int mid ,first=0, last=size-1;
	while(first <= last)
	{
		mid = first + (last - first)/2;
		if(arr[mid] == item)
		{
			return mid;
		}
		if(arr[mid] < item)
		{
			first =mid + 1;
		}
		else
		{
			last =mid-1;
		}
		
	}

	return -1;
}

int main()
{
    const int SIZE = 11;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int element = 8;
    int index = binary_search(arr, SIZE, element);
    printf("%d\n", index);
    return 0;
}