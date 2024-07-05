/*
 * ----------------------------------------------------------------------------------
 * Filename		:	Lab3.cpp
 *
 * Author		:	Ahmed Essam El-Mogy
 * Created on	:	Jul 4th, 2024
 * ----------------------------------------------------------------------------------
 */

/* Lab Description:
    Write a program that uses Function pointer to a function that takes:
        - 2D array of integers
        - its size
        - an array of row sizes
        - a callback function
    and returns an array of integers
*/

#include <iostream>

using namespace std;

/* The Pointer to Function Declaration */
int* (*CallbackFunc)(int** arr_2d, int arr_size, int* row_sizes, int (*func)(int*, int));

/* The function that operates on 1-D arrays */
int accumilate(int* arr, int size)
{
    int i, sum = 0;

    for (i = 0; i < size; ++i)
    {
        sum += *(arr + i);
    }

    return sum;
}

/* An Implementation of the CallbackFunction */
int* CallbackFunction(int** arr_2d, int arr_size, int* row_sizes, int (*func)(int*, int))
{
    int* result = (int*)malloc(arr_size * sizeof(int));

    for (int i = 0; i < arr_size; ++i)
    {
        result[i] = func(arr_2d[i], row_sizes[i]);
    }

    return result;
}


int main(void)
{
    /* Initializing the 1-D arrays */
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {6, 7, 8, 9};
    int arr3[] = {10, 11, 12};
    int arr4[] = {5, 7, 9};

    /* Initializing the 2-D Array */
    const int ARR_SIZE = 4;

    int* arr_2d[4] = {arr1, arr2, arr3, arr4};

    /* Initializing the row sizes array */
    int row_sizes[4] = { 5, 4, 3, 3};

    /* Setting the Callback Function */
    CallbackFunc = CallbackFunction;

    /* Calling the Callback Function and storing the resulting pointer to a pointer to int */
    int* result = CallbackFunc(arr_2d, ARR_SIZE, row_sizes, accumilate);

    /* Printing the resulting arry of accumilated arrays */
    for (int i = 0; i < ARR_SIZE; ++i)
    {
        cout << "Sum of array " << i + 1  << " = " << *(result + i) << endl;
    }

    /* Freeing the allocated memory */
    free(result);
    
    return 0;
}
