#include <cstddef>
#include <iostream>
#include <vector>

class IntergerList
{
  public:
    IntergerList () : target{} {}

    void
    add (int value)
    {
        target.push_back (value);
    }

    int
    getValue () const
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
    int inserted{};
    int sum{};
    std::cin >> inserted;
    {
        IntergerList i;
        i.add (inserted);
        sum = i.getValue ();
    }
    std::cout << sum;

    return 0;
}
