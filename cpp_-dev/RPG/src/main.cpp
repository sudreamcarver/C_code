#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Character
{
  protected:
    std::string name;
    int hp;
    int demage;

  public:
    Character (std::string name, int hp, int demage)
        : name (name), hp (hp), demage (demage)
    {
    }

    virtual ~Character () = default;

    bool
    isDead ()
    {
        if (hp <= 0)
            {
                return true;
            }
        return false;
    }

    std::string
    getName ()
    {
        return name;
    }

    void
    demaged (int demaged_value)
    {
        hp -= demaged_value;
        std::cout << getName () << "was demaged hp - " << demaged_value
                  << std::endl;
    }

    // force subclass do this func
    virtual void attack (Character &target) = 0;
};

class Warrior : public Character
{
  public:
    Warrior (std::string n, int h, int d) : Character (n, h, d) {}

    void
    attack (Character &target) override
    {
        std::cout << name << " swings a sword at " << target.getName () << "!"
                  << std::endl;
        target.demaged (demage);
    }
};

class Monster : public Character
{
  public:
    Monster (std::string n, int h, int d) : Character (n, h, d) {}
    void
    attack (Character &target) override
    {
        std::cout << name << " using jaw at " << target.getName () << "!"
                  << std::endl;
        target.demaged (demage);
    }
};

int
main ()
{
    std::vector<std::unique_ptr<Character>> fighters{};

    // add Character
    fighters.push_back (std::make_unique<Monster> ("Goblin", 1000, 5));
    fighters.push_back (std::make_unique<Warrior> ("luca", 100, 12));
    fighters.push_back (std::make_unique<Warrior> ("Chrono", 120, 6));

    for (const auto &fighter : fighters)
        {
            if (fighter != fighters[0])
                {
                    fighter->attack (*fighters[0]);
                }
        }

    return 0;
}
