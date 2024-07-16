#include <iostream>

template <typename T>
class DynamicArray
{
private:
    T *array;
    int capacity, currentSize;

public:
    // Constructors

    DynamicArray() : capacity(1), currentSize(0)
    {
        array = new T[capacity];
    }

    DynamicArray(int size) : capacity(size), currentSize(0)
    {
        array = new T[capacity];
    }

    DynamicArray(int size, int value) : capacity(size), currentSize(size)
    {
        array = new T[capacity];

        for (int i = 0; i < capacity; ++i)
        {
            array[i] = value;
        }
    }

    DynamicArray(int size, std::initializer_list<T> values) : capacity(size)
    {
        array = new T[capacity];

        int i = 0;

        for (T val : values)
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

        array = new T[capacity];

        for (int i = 0; i < currentSize; ++i)
        {
            array[i] = arr.array[i];
        }
    }

    // Functions

    void resize()
    {
        capacity *= 2;
        T *tmp = new T[capacity];

        for (int i = 0; i < currentSize; ++i)
        {
            tmp[i] = array[i];
        }
        delete[] array;
        array = tmp;
    }

    void pushBack(T value)
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
            T val = array[currentSize - 1];

            array[currentSize - 1] = 0;

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

    void insertAt(int index, T value)
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

    void insertMiddle(T value)
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
    /*** Working with Integers --------------------------------------------------------------*/

    std::cout << "********** Working with Integers **************" << std::endl;

    /* Push 5 values */
    DynamicArray<int> dynArr;
    dynArr.pushBack(5);
    dynArr.pushBack(3);
    dynArr.pushBack(2);
    dynArr.pushBack(1);
    dynArr.insertAt(2, 6);
    std::cout << "pushing 5 values:" << std::endl;
    dynArr.print();
    std::cout << "cap = " << dynArr.size() << std::endl;
    std::cout << "current size = " << dynArr.current_size() << std::endl;

    /* Pop 1 value */
    dynArr.popBack();
    std::cout << std::endl
              << "poping 1 value:" << std::endl;
    dynArr.print();
    std::cout << "cap = " << dynArr.size() << std::endl;
    std::cout << "current size = " << dynArr.current_size() << std::endl;

    /* Push at the middle */
    dynArr.insertMiddle(10);
    std::cout << std::endl
              << "pushing 1 value at the middle:" << std::endl;
    dynArr.print();
    std::cout << "cap = " << dynArr.size() << std::endl;
    std::cout << "current size = " << dynArr.current_size() << std::endl;

    /* Remove at index 1 */
    dynArr.removeAt(1);
    std::cout << std::endl
              << "remove value at index 1:" << std::endl;
    dynArr.print();
    std::cout << "cap = " << dynArr.size() << std::endl;
    std::cout << "current size = " << dynArr.current_size() << std::endl;

    /* Copying the dynamic array into a new one */
    DynamicArray dynArr2 = dynArr;
    std::cout << std::endl
              << "Copying the dynamic array:" << std::endl;
    dynArr2.print();
    std::cout << "cap = " << dynArr2.size() << std::endl;
    std::cout << "current size = " << dynArr2.current_size() << std::endl;

    /* Creating a dynamic array with initial values of zeros */
    DynamicArray<int> dynArr_initialized(3, 0);
    std::cout << std::endl
              << "Creating the dynamic array with 0 values" << std::endl;
    dynArr_initialized.print();
    std::cout << "cap = " << dynArr_initialized.size() << std::endl;
    std::cout << "current size = " << dynArr_initialized.current_size() << std::endl;

    /* Using the initializer list to initilaize the dynamic array */
    DynamicArray dynArr3(5, std::initializer_list<int>{1, 2, 3});
    std::cout << std::endl
              << "initialize with an initializer list:" << std::endl;
    dynArr3.print();
    std::cout << "cap = " << dynArr3.size() << std::endl;
    std::cout << "current size = " << dynArr3.current_size() << std::endl;

    /*** Working with Doubles -------------------------------------------------------------*/

    std::cout << std::endl
              << "********** Working with Doubles **************" << std::endl;

    DynamicArray<double> dynDbArr;

    dynDbArr.pushBack(1.5);
    dynDbArr.pushBack(4.6);
    dynDbArr.pushBack(7.12);
    dynDbArr.pushBack(1.6);
    dynDbArr.insertAt(3, 0.5);

    std::cout << "pushing 5 values:" << std::endl;
    dynDbArr.print();
    std::cout << "cap = " << dynDbArr.size() << std::endl;
    std::cout << "current size = " << dynDbArr.current_size() << std::endl;

    /* Remove at index 1 */
    dynDbArr.removeAt(1);
    std::cout << std::endl
              << "remove value at index 1:" << std::endl;
    dynDbArr.print();
    std::cout << "cap = " << dynDbArr.size() << std::endl;
    std::cout << "current size = " << dynDbArr.current_size() << std::endl;

    /* Push at the middle */
    dynDbArr.insertMiddle(14.65);
    std::cout << std::endl
              << "pushing 1 value at the middle:" << std::endl;
    dynDbArr.print();
    std::cout << "cap = " << dynDbArr.size() << std::endl;
    std::cout << "current size = " << dynDbArr.current_size() << std::endl;

    /*** Working with Characters -------------------------------------------------------------*/

    std::cout << std::endl
              << "********** Working with Characters **************" << std::endl;

    DynamicArray<char> dynChArr;

    dynChArr.pushBack('a');
    dynChArr.pushBack('b');
    dynChArr.pushBack('f');
    dynChArr.pushBack('d');
    dynChArr.insertAt(3, 'y');

    std::cout << "pushing 5 values:" << std::endl;
    dynChArr.print();
    std::cout << "cap = " << dynChArr.size() << std::endl;
    std::cout << "current size = " << dynChArr.current_size() << std::endl;

    /* Remove at index 1 */
    dynChArr.removeAt(1);
    std::cout << std::endl
              << "remove value at index 1:" << std::endl;
    dynChArr.print();
    std::cout << "cap = " << dynChArr.size() << std::endl;
    std::cout << "current size = " << dynChArr.current_size() << std::endl;

    /* Push at the middle */
    dynChArr.insertMiddle('z');
    std::cout << std::endl
              << "pushing 1 value at the middle:" << std::endl;
    dynChArr.print();
    std::cout << "cap = " << dynChArr.size() << std::endl;
    std::cout << "current size = " << dynChArr.current_size() << std::endl;
    return 0;
}