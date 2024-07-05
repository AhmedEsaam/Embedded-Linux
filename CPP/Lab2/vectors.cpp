#include <iostream>
using namespace std;

struct Vector
{
    int *arr;
    int size;
    int capacity ;
};

Vector* init(int size)
{
    Vector vec;
    vec.arr = (int *)calloc(size, sizeof(int));
    return &vec;
}

void insert(Vector *vec, int val, int index)
{
    int *tmp = (int *)realloc(vec->arr, vec->size * 2 * sizeof(int));
    vec->size *= 2;

    for (int i = vec->capacity - 1; i >= index; --i)
    {
        vec->arr[i + 1] = vec->arr[i];
    }

    vec->arr[index] = val;
    (vec->capacity)++;
}

void delete_element(Vector *vec, int index)
{
    for (int i = index; i < vec->capacity; ++i)
    {
        vec->arr[i] = vec->arr[i + 1];
    }
    (vec->capacity)--;
}

void print(Vector *vec)
{
    for (int i = 0; i < vec->capacity; i++)
    {
        cout << vec->arr[i];
    }
}

void print_at(Vector *vec, int index)
{
    if (index >= 0 && index < vec->capacity)
    {
        cout << vec->arr[index];
    }
    else
    {
        cout << "Out of boundary";
    }
}

int main()
{
    Vector * v = init(10);
    insert(v, 5, 0);
    print(v);

    return 0;
}