#include <iostream>

class Solution {
public:
    int addDigits(int num) {
        if (num < 10)
        {
            return num;
        }
        else
        {
            int digit, sum = 0;
            while(num > 0)
            {
                digit = num % 10;
                sum += digit;
                num = (num - digit) / 10;
            }
            return addDigits(sum);
        }
    }
};

int main(void)
{
    Solution sol;

    std:: cout << sol.addDigits(38) << std::endl;

    return 0;
}