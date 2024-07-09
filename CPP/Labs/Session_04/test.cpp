#include <iostream>

void print(void)
{
    std::cout << "print(void)" << std::endl;
}

void print(int x)
{
    std::cout << "print(" << x << ")" << std::endl;
}

template <typename T1, typename T2>
void setPair(T1 first, T2 second)
{
}

template <typename T1, typename T2>
void print(std::string, T2) = delete;

template <typename T1, typename T2>
void print(T1 a, T2 b)
{
    std::cout << a << b << std::endl;
};

int main()
{
    print();
    print(5);

    print<int, int>(5, 6);
    // print<std::string, int>("a", 6);

    

    return 0;
}