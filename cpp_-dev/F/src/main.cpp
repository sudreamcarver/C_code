#include <iostream>

int
main ()
{
    int num{};
    std::cout << "Enter a num:";

    std::cin >> num;
    num = 2 * num;
    std::cout << "double that number is " << num << "\n";

    return 0;
}
