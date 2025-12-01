#include <iostream>
#include <memory>

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
        std::unique_ptr<Resource> ptr = std::make_unique<Resource> ();
    }
    return 0;
}
