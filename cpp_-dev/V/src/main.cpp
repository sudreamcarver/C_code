#include <iostream>

class shape
{
  public:
    shape () {}
    void
    printIdentity ()
    {
        std::cout << "I am a shape" << std::endl;
    }
};

class circle : public shape
{
};

int
main ()
{
    {
        circle S;
        S.printIdentity ();
    }
}
