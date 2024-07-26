#include <iostream>
#include <string>

int main()
{
    /* Provided text */
    std::string text = {"The cycle of life is a cycle of cycles"};

    /* Replace all occurances of the word "cycle" with "circle "*/
    while (text.find("cycle") != std::string::npos)
    {
        text.replace(text.find("cycle"), 5, "circle");
    }

    /* Insert the word "great " before the first word "circle" */
    int index = text.find("circle", index);

    text.insert(index, "great ");

    /* Insert the word "never-ending " before the second word "circle" */
    index += std::string("great ").size() + 1;
    index = text.find("circle", index);

    text.insert(index, "never-ending ");

    /* Print text */
    std::cout << text << std::endl;

    return 0;
}