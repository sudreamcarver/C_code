#include <cstddef>
#include <iostream>
#include <iterator>
#include <ostream>
#include <vector>

std::vector<int>
generate_fibonacci (size_t n)
{
    std::vector<int> result{};
    result.push_back (0);
    result.push_back (1);
    for (size_t i{ 0 }; i < n - 2; i++)
        {
            int nowGenerate = result[i] + result[i + 1];
            result.push_back (nowGenerate);
        }
    return result;
}

int
main ()
{
    size_t numWanted{};
    std::vector<int> result{};
    std::cout << "How many num U want?"
              << std::endl; // cout means "character out"
    std::cin >> numWanted;

    if (numWanted == 0)
        {
            return 0;
        }
    else if (numWanted == 1)
        {
            std::cout << 0;
        }
    else if (numWanted == 2)
        {
            std::cout << 0 << "," << 1;
        }
    else
        {
            result = generate_fibonacci (numWanted);
            size_t numInResult{ result.size () };
            for (size_t i{ 0 }; i < numInResult; i++)
                {
                    std::cout << result[i] << ",";
                }
        }

    return 0;
}
