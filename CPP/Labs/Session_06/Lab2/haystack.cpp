#include <iostream>
#include <string>
#include <string_view>

std::string haystack(std::string source, std::string_view needle, std::string_view replacement)
{
    auto index = source.find(needle);

    while (index != std::string::npos)
    {
        source.replace(index, needle.size(), replacement);
        index = source.find(needle, index + replacement.size());
    }

    return source;
}

int main()
{
    std::string str = {"The cycle of life is a cycle of cycles"};

    std::string needle = {"cycle"};
    std::string replacement = {"circle"};

    std::string out = haystack(str, needle, replacement);

    std::cout << out << std::endl;

    return 0;
}