#include <iostream>

int
main ()
{
    double num1{};
    double num2{};
    char operation{};
    std::cout << "enter num1"; // cout means "character out"
    std::cin >> num1;

    std::cout << "enter num2"; // cout means "character out"
    std::cin >> num2;

    std::cout << "enter operator"; // cout means "character out"
    std::cin >> operation;

    switch (operation)
        {
        case '+':
            std::cout << num1 + num2;
            break;
        case '-':
            std::cout << num1 - num2;
            break;
        case '*':
            std::cout << num1 * num2;
            break;
        case '/':
            if (num2 == 0)
                {
                    std::cout << "in '/' num2 cant be 0 ";
                    return 0;
                }
            std::cout << num1 / num2;
        }

    return 0;
}
