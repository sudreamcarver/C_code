#include <string>

enum class OwnerType
{
    Hero,
    Monster
};

struct Affix
{
    std::string name;
    int value;

    std::string
    toString (std::string description) const
    {
        std::string sign = (value > 0) ? "+" : "";

        return description + "->" + name + " " + sign + std::to_string (value);
    }
};

class Item
{
  protected:
    std::string name;
    OwnerType ownerType;

  public:
    Item (std::string name, OwnerType type) : name (name), ownerType (type) {}
    virtual ~Item () = default;

    virtual void ShowDetail () = 0;

    auto
    GetType () const
    {
        return ownerType;
    }

    auto
    GetName () const
    {
        return name;
    }
};
