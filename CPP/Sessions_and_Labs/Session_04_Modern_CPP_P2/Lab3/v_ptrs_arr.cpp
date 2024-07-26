#include <iostream>
#include <string>

enum class Type
{
    INT,
    DOUBLE,
    CHAR
};

class VPointerArray
{
private:
    void **vpArr;
    int size;

public:
    VPointerArray(int s) : size(s)
    {
        vpArr = new void *[size];
    }

    void setValue(void *pVal, int index)
    {
        vpArr[index] = pVal;
    }

    void *getValue(int index)
    {
        return vpArr[index];
    }

    int getSize()
    {
        return size;
    }

    Type getDataType(int index)
    {
        if (typeid(vpArr[index]) == typeid(int *))
        {
            return Type::INT;
        }

        if (typeid(vpArr[index]) == typeid(double *))
        {
            return Type::DOUBLE;
        }

        if (typeid(vpArr[index]) == typeid(char *))
        {
            return Type::CHAR;
        }
    }

    void printDataTypes()
    {
        Type t;

        for (int i = 0; i < size; ++i)
        {
            t = getDataType(i);
            switch (t)
            {
            case Type::INT:
                std::cout << "int" << std::endl;
                break;

            case Type::DOUBLE:
                std::cout << "double" << std::endl;
                break;

            case Type::CHAR:
                std::cout << "char" << std::endl;
                break;

            default:
                break;
            }
        }
    }

    ~VPointerArray()
    {
        delete[] vpArr;
    }
};

int main()
{

    VPointerArray arr(5);

    int x = 5, y = 6;
    int *pInt1 = &x;
    int *pInt2 = &y;

    arr.setValue(pInt1, 4);
    arr.setValue(pInt2, 3);

    return 0;
}