#include <iostream>

class Resource
{
  public:
    Resource () { std::cout << "Resource acquired." << std::endl; }
    ~Resource () { std::cout << "Resource released." << std::endl; }
};

int
main ()
{
    {
        Resource r;
        std::cout << "some thing happend here." << std::endl;
    }
    return 0;
}
