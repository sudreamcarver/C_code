#include <iostream>
#include <string>
#include <vector>

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

    virtual void ShowDetail () const = 0;

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

class Equipment : public Item
{
  protected:
    std::vector<Affix> affixes;

  public:
    Equipment (std::string name, OwnerType Type) : Item (name, Type) {}

    void
    addAffix (std::string affixName, int value)
    {
        Affix affix;
        affix.name = affixName;
        affix.value = value;
        affixes.push_back (affix);
    }

    void
    ShowDetail () const override
    {
        Item::GetType ();
        Item::GetName ();
        std::cout << Item::GetName () << "\n" << std::endl;
        std::cout << Item::GetType () << std::endl;
    }
};

class HeroEquipment : public Equipment
{
  public:
    HeroEquipment (std::string name) : Equipment (name, OwnerType::Hero) {}
};

class MonsterEquipment : public Equipment
{
  public:
    MonsterEquipment (std::string name) : Equipment (name, OwnerType::Monster)
    {
    }
};
