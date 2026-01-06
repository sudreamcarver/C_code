#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

int
main ()
{
    const int NAME_WIDTH = 15;
    const int TYPE_WIDTH = 10;
    const int DMG_WIDTH = 8;

    std::cout << "+" << std::string (37, '-') << "+" << std::endl;
    std::cout << "| " << std::left << std::setw (NAME_WIDTH) << "Name"
              << std::left << std::setw (TYPE_WIDTH) << "Type" << std::right
              << std::setw (DMG_WIDTH) << "Damage" << " |" << std::endl;
    std::cout << "+" << std::string (37, '-') << "+" << std::endl;

    std::string names[] = { "Iron Sword", "Great Axe", "Dagger" };
    std::string types[] = { "Weapon", "Weapon", "Weapon" };
    int damages[] = { 15, 45, 8 };

    for (int i = 0; i < 3; ++i)
        {
            std::cout << "| " << std::left << std::setw (NAME_WIDTH)
                      << names[i] << std::left << std::setw (TYPE_WIDTH)
                      << types[i] << std::right << std::setw (DMG_WIDTH)
                      << damages[i] << " |" << std::endl;
        }

    std::cout << "+" << std::string (37, '-') << std::endl;

    return 0;
}
