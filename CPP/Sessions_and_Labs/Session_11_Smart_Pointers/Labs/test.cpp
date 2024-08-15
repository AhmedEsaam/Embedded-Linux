#include <iostream>
#include <memory>
class MyClass
{
};

int main()
{
    /* ------------------------------------------------------- */
    /* Unique Point */
    std::unique_ptr<int> uPtr(new int(100));

    // Recommended - More efficient
    std::unique_ptr<MyClass> uPtr2 = std::make_unique<MyClass>(100);

    // not allowed as the unique pointer must not share the address with other pointer (it must move the ownership)
    // std::unique_ptr<int> uPtr = new int(100);    // Error

    /* ------------------------------------------------------- */
    /* Shared Pointer */
    std::shared_ptr<int> sPtr1(new int(100));
    std::shared_ptr<int> sPtr2(new int(50));
    sPtr1 = sPtr2; // Allowed;

    // Recommended - more effiecient
    std::shared_ptr<MyClass> sPtr2 = std::make_shared<MyClass>(100);

    sPtr1.use_count();


    /* ------------------------------------------------------- */
    /* Shared Pointer */
    return 0;
}
