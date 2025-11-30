#include <cstddef>
#include <iostream>
#include <vector>

class IntergerList
{
  public:
    IntergerList () : target{}
    {
        int inserted{};
        int sum{};
        std::cin >> inserted;
        add (inserted);
        sum = getValue ();
        std::cout << sum;
    }
    void
    add (int value)
    {
        target.push_back (value);
    }
    int
    getValue ()
    {
        size_t length{};
        int sum{};
        length = target.size ();
        for (size_t i{ 0 }; i < length; i++)
            {
                sum += target[i];
            }
        return sum;
    }
    ~IntergerList () { std::cout << "released"; }

  private:
    std::vector<int> target;
};

int
main ()
{
    {
        IntergerList i;
    }

    return 0;
}
