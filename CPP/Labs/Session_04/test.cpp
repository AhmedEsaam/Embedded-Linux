#include <iostream>
#include <array>

using namespace std;

int main(void)
{

    std::array<int, 5> arr{1, 2, 3, 4, 5};

    int size = arr.size(); // 5
    cout << size << endl;

    int item = arr.at(3);
    cout << item << endl;

    for (auto val : arr)
    {
        cout << val << endl;
    }

    // Check if an element exists in the array

    std::string str{"hossam"};

    str = "Hi";

    // string size
    cout << str.length() << endl;
    cout << str.size() << endl;

    // append
    str.append(" Mustafa");
    str += "!";

    cout << str << endl;

    return 0;
}