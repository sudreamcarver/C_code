#include <array>
#include <cstddef>
#include <iostream>

int
main ()
{
    std::array<int, 5> arr;
    for (std::size_t i = 0; i < arr.size (); i++)
        {
            std::cout << arr[i] << "\n" << std::endl;
        }

    arr.at (1) = 99;

    return 0;
}
