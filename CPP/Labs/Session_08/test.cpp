#include <iostream>
#include <vector>
#include <function>

void print(std::vector<int> vec, std::function<void(int)> func)
{
    for (auto i : vec)
    {
        func(i);
    }
}

int main(void)
{
    std::vector<int> vec = {1, 2, 3, 4, 5};

    auto myLambda = [] (int x) {std::cout << x << std::endl; };

    std::function<int(int)> fn1 = myLambda;

    print(vec, fn1);

    return 0;
}