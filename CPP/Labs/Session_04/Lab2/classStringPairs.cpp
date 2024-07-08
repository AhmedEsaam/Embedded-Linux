#include <iostream>
#include <array>
#include <string>

class Pair
{
private:
    std::string first, second;

public:
    Pair() : first(""), second("")
    {
    }

    Pair(std::string x, std::string y) : first(x), second(y)
    {
    }

    std::string getFirst()
    {
        return first;
    }

    std::string getSecond()
    {
        return second;
    }

    void setFirst(std::string f)
    {
        first = f;
    }

    void setSecond(std::string s)
    {
        second = s;
    }

    void setPairs(std::string f, std::string s)
    {
        first = f;
        second = s;
    }

    void swap()
    {
        std::string tmp;
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

    p.setFirst("lemon");
    p.setSecond("yellow");

    std::cout << "first: " << p.getFirst() << ", second: " << p.getSecond() << std::endl;

    // Array of pairs
    std::cout << std::endl
              << "*** Array of Pairs ***" << std::endl;

    std::array<Pair, 3> pArr;

    for (int i = 0; i < pArr.size(); ++i)
    {
        pArr[i].setPairs("a", "b");
    }

    // prstd::stringing array
    for (int i = 0; i < pArr.size(); ++i)
    {
        std::cout << "pair[" << i << "] = ";
        pArr[i].printPair();
    }

    return 0;
}