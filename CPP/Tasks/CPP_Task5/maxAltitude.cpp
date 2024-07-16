#include <iostream>
#include <vector>

class Solution
{
public:
    int largestAltitude(std::vector<int> &gain)
    {

        int max_alt = 0, last_alt = 0, altitude;

        for (int &val : gain)
        {
            altitude = last_alt + val;

            if (altitude > max_alt)
            {
                max_alt = altitude;
            }

            last_alt = altitude;
        }

        return max_alt;
    }
};

int main()
{
    Solution sol;

    std::vector<int> gains = {-5, 1, 5, 0, -7};

    std::cout << sol.largestAltitude(gains) << std::endl;

    return 0;
}