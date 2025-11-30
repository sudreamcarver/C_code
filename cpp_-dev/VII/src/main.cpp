#include <iostream>

class shape
{
  public:
    shape () {}

    virtual ~shape () = default;

    virtual void
    printIdentity ()
    {
        std::cout << "I am a shape" << std::endl;
    }
};

class circle : public shape
{
  public:
    void
    printIdentity () override
    {
        std::cout << "I am a circle" << std::endl;
    }
};

int
main ()
{
    {
        circle S;
        S.printIdentity ();
    }
}
