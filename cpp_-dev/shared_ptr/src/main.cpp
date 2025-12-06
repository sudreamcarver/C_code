#include <iostream>
#include <memory>
#include <ostream>

class Resoure
{
  public:
    Resoure () { std::cout << "source are required." << std::endl; }
    ~Resoure () { std::cout << "source are released." << std::endl; }
};
int
main ()
{
    std::shared_ptr<Resoure> sPtr = std::make_shared<Resoure> ();
    std::cout << "before copy" << sPtr.use_count () << std::endl;
    {
        std::shared_ptr<Resoure> sPtr1 = sPtr;
        std::cout << "copyed" << sPtr.use_count () << std::endl;
    }
    std::cout << "end copy" << sPtr.use_count () << std::endl;
    return 0;
}
