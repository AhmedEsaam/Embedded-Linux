#include <iostream>
#include <array>

class Pair
{
private:
    int first, second;

public:
    Pair() : first(0), second(0)
    {
    }

    Pair(int x, int y) : first(x), second(y)
    {
    }

    int getFirst()
    {
        return first;
    }

    int getSecond()
    {
        return second;
    }

    void setFirst(int f)
    {
        first = f;
    }

    void setSecond(int s)
    {
        second = s;
    }

    void setPairs(int f, int s)
    {
        first = f;
        second = s;
    }

    void swap()
    {
        int tmp;
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

    Pair p;

    p.setFirst(5);
    p.setSecond(3);

    std::cout << "first: " << p.getFirst() << ", second: " << p.getSecond() << std::endl;

    // Array of pairs
    std::cout << std::endl << "*** Array of Pairs ***" << std::endl;

    std::array<Pair, 3> pArr;

    for (int i = 0; i < pArr.size(); ++i)
    {
        pArr[i].setPairs(i, i + 2);
    }

    // printing array 
    for (int i = 0; i < pArr.size(); ++i)
    {
        std::cout << "pair[" << i << "] = ";
        pArr[i].printPair();
    }

    return 0;
}