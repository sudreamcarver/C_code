#include <iostream>
#include <memory>
#include <utility>

std::unique_ptr<int>
creatValue (int valer)
{
    std::unique_ptr<int> ptr = std::make_unique<int> ();
    *ptr = valer;
    return ptr;
}

int
main ()
{
    std::unique_ptr<int> ptr1{};
    std::unique_ptr<int> ptr2{};
    ptr1 = creatValue (99);
    ptr2 = std::move (ptr1);
    if (ptr1 == nullptr)
        {
            std::cout << "ptr1 is nullptr." << std::endl;
        }
    std::cout << "value in ptr2 is:" << *ptr2 << std::endl;

    return 0;
}
