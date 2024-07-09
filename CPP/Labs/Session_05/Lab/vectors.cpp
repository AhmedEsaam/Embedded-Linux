#include <iostream>

class DynamicArray
{
private:
    int *array;
    int capacity, currentSize;

public:
    // Constructors

    DynamicArray() : capacity(1), currentSize(0)
    {
        array = new int[capacity];
    }

    DynamicArray(int size) : capacity(size), currentSize(0)
    {
        array = new int[capacity];
    }

    DynamicArray(int size, int value) : capacity(size), currentSize(size)
    {
        array = new int[capacity];

        for (int i = 0; i < capacity; ++i)
        {
            array[i] = value;
        }
    }

    DynamicArray(int size, std::initializer_list<int> values) : capacity(size)
    {
        array = new int[capacity];

        int i = 0;

        for (int val : values)
        {
            array[i] = val;
            i++;
        }

        currentSize = i;
    }

    DynamicArray(const DynamicArray &arr)
    {
        capacity = arr.capacity;
        currentSize = arr.currentSize;

        array = new int[capacity];

        for (int i = 0; i < currentSize; ++i)
        {
            array[i] = arr.array[i];
        }
    }

    // Functions

    void resize()
    {
        capacity *= 2;
        int *tmp = new int[capacity];

        for (int i = 0; i < currentSize; ++i)
        {
            tmp[i] = array[i];
        }
        delete[] array;
        array = tmp;
    }

    void pushBack(int value)
    {
        if (currentSize == capacity)
        {
            resize();
        }

        array[currentSize] = value;
        currentSize++;
    }

    void popBack()
    {
        if (currentSize != 0)
        {
            int val = array[currentSize - 1];

            array[currentSize - 1] = 0; // ?

            currentSize--;
        }
    }

    void removeAt(int index)
    {
        for (int i = index; i < currentSize - 1; ++i)
        {
            array[i] = array[i + 1];
        }

        currentSize--;
    }

    void insertAt(int index, int value)
    {
        if (currentSize == capacity)
        {
            resize();
        }

        for (int i = currentSize; i > index; --i)
        {
            array[i] = array[i - 1];
        }

        array[index] = value;
        currentSize++;
    }

    void insertMiddle(int value)
    {
        int index = currentSize / 2;

        insertAt(index, value);
    }

    void removeMiddle()
    {
        int index = currentSize / 2;

        removeAt(index);
    }

    int size() const
    {
        return capacity;
    }

    int current_size() const
    {
        return currentSize;
    }

    void print() const
    {
        for (int i = 0; i < currentSize; ++i)
        {
            std::cout << "array[" << i << "] = " << array[i] << std::endl;
        }
    }
};

int main(void)
{
    DynamicArray dynArr;

    std::cout << "pushing 5 values:" << std::endl;

    dynArr.pushBack(5);
    dynArr.pushBack(3);
    dynArr.pushBack(2);
    dynArr.pushBack(1);
    dynArr.pushBack(6);
    dynArr.print();
    std::cout << "size = " << dynArr.size() << std::endl;
    std::cout << "current size = " << dynArr.current_size() << std::endl;

    std::cout << std::endl
              << "poping 1 value:" << std::endl;
    dynArr.popBack();
    dynArr.print();
    std::cout << "size = " << dynArr.size() << std::endl;
    std::cout << "current size = " << dynArr.current_size() << std::endl;

    std::cout << std::endl
              << "pushing 1 value at the middle:" << std::endl;
    dynArr.insertMiddle(10);
    dynArr.print();
    std::cout << "size = " << dynArr.size() << std::endl;
    std::cout << "current size = " << dynArr.current_size() << std::endl;

    std::cout << std::endl
              << "remove value at index 1:" << std::endl;
    dynArr.removeAt(1);
    dynArr.print();
    std::cout << "size = " << dynArr.size() << std::endl;
    std::cout << "current size = " << dynArr.current_size() << std::endl;


    return 0;
}