#include <iostream>
#include <string>

// 定义常用的颜色代码
const std::string RED_TXT = "\033[31m";
const std::string GREEN_TXT = "\033[32m";
const std::string BLUE_TXT = "\033[34m";
const std::string YELLOW_TXT = "\033[33m";
const std::string RESET = "\033[0m";

const std::string RED_BG = "\033[41m";
const std::string WHITE_TXT = "\033[97m";

int
main ()
{
    std::cout << "--- Color Test ---"
              << std::endl; // cout means "character out"

    std::cout << RED_TXT << "Enemy took 50 damage!" << RESET << std::endl;
    std::cout << GREEN_TXT << "Hero recovered 20 HP" << RESET << std::endl;
    std::cout << BLUE_TXT << "Mana restored." << RESET << std::endl;

    std::cout << "Status: " << GREEN_TXT << "[HEALTHY]" << RESET
              << " | Mode: " << RED_TXT << "[COMBAT]" << RESET << std::endl;

    std::cout << "\n";

    std::cout << RED_BG << WHITE_TXT << " CRITICAL ERROR " << RESET
              << std::endl;
    return 0;
}
