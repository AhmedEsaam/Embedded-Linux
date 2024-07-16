#include <iostream>
#include <string>

class Solution
{
public:
    std::string addStrings(std::string num1, std::string num2)
    {
        int n1 = 0, n2 = 0, sum;
        std::string str_sum, digit;

        for (int i = num1.size() - 1, factor = 1; i >= 0; --i, factor *= 10)
        {
            n1 += (num1[i] - '0') * factor;
        }

        for (int i = num2.size() - 1, factor = 1; i >= 0; --i, factor *= 10)
        {
            n2 += (num2[i] - '0') * factor;
        }

        sum = n1 + n2;

        if (sum == 0)
        {
            str_sum = "0";
        }

        while (sum > 0)
        {
            digit = (sum % 10) + '0';
            str_sum = digit + str_sum;
            sum /= 10;
        }

        return str_sum;
    }
};

int main()
{
    Solution sol;
    std::cout << sol.addStrings("11", "123") << std::endl;

    return 0;
}