#include <iostream>

int
main ()
{
    int value{ 42 };
    int *ptr{};
    ptr = &value;
    *ptr = 99;
    std::cout << value;
    return 0;
}
