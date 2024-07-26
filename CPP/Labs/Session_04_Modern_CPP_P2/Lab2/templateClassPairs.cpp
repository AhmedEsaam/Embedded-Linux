#include <iostream>
#include <array>

template <typename T>
class Pair
{
private:
    T first, second;

public:
    Pair() : first(0), second(0)
    {
    }

    Pair(T x, T y) : first(x), second(y)
    {
    }

    T getFirst()
    {
        return first;
    }

    T getSecond()
    {
        return second;
    }

    void setFirst(T f)
    {
        first = f;
    }

    void setSecond(T s)
    {
        second = s;
    }

    void setPairs(T f, T s)
    {
        first = f;
        second = s;
    }

    void swap()
    {
        T tmp;
        tmp = first;
        first = second;
        second = tmp;
    }

    void printPair()
    {
        std::cout << "first: " << first << ", second: " << second << std::endl;
    }
};

int main(void)
{
    // One pair
    std::cout << "*** One Pair ***" << std::endl;

    Pair<int> p;

    p.setFirst(5);
    p.setSecond(3);

    std::cout << "first: " << p.getFirst() << ", second: " << p.getSecond() << std::endl;

    // Array of pairs
    std::cout << std::endl
              << "*** Array of Pairs ***" << std::endl;

    std::array<Pair<int>, 3> pArr;

    for (int i = 0; i < pArr.size(); ++i)
    {
        pArr[i].setPairs(i, i + 2);
    }

    // prTing array
    for (int i = 0; i < pArr.size(); ++i)
    {
        std::cout << "pair[" << i << "] = ";
        pArr[i].printPair();
    }

    return 0;
}