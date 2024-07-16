#include <iostream>
#include <string>
#include <algorithm>

class Solution
{
public:
    void bubbleSort(std::string &str)
    {
        char tmp;

        for (int i = 0; i < str.size() - 1; ++i)
        {
            for (int j = i + 1; j < str.size(); ++j)
            {
                if (str[i] > str[j])
                {
                    tmp = str[i];
                    str[i] = str[j];
                    str[j] = tmp;
                }
            }
        }
    }

    bool isAnagram(std::string s, std::string t)
    {

        bubbleSort(s);
        bubbleSort(t);

        return (s == t);
    }
};

int main()
{
    Solution sol;

    std::string str = (sol.isAnagram("anagram", "nagaram")) ? "True" : "False";

    std::cout << str << std::endl;

    return 0;
}