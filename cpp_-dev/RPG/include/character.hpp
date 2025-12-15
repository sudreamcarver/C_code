#include "Item.hpp"
#include <algorithm>
#include <iostream>
#include <string>
struct Attributes
{
    std::string name;
    OwnerType characterType;
    int attack;
    int defense;
    int MagicPower;
    int MagicDefense;
    int armor;
    int hp;
};

class Character
{
  protected:
    Attributes characterAbstruct;

  public:
    Character (const Attributes &abstruct) : characterAbstruct (abstruct) {}

    virtual ~Character () = default;

    bool
    isDead () const
    {
        if (characterAbstruct.hp <= 0)
            {
                return true;
            }
        return false;
    }

    std::string
    getName () const
    {
        return characterAbstruct.name;
    }

    int
    CalculateIncomingDamage (int rawDamage, bool isPhysical)
    {
        int finalDamage{ 0 };
        if (isPhysical)
            {
                int damageAfterDefense = rawDamage - characterAbstruct.defense;
                int armorReduction = characterAbstruct.armor / 4;
                finalDamage = damageAfterDefense - armorReduction;
            }
        else
            {
                finalDamage = rawDamage - characterAbstruct.MagicDefense;
            }
        return std::max (1, finalDamage);
    }
    void
    takeDamage (int actualDamage)
    {
        characterAbstruct.hp -= actualDamage;
        std::cout << getName () << " took " << actualDamage << " damage!"
                  << " (HP: " << characterAbstruct.hp << ")" << std::endl;
    }

    int
    GetRolledAttack ()
    {
        double randomFactor
            = 0.9 + (static_cast<double> (std::rand ()) / RAND_MAX) * 0.2;
        return static_cast<int> (characterAbstruct.attack * randomFactor);
    }

    int
    GetRolledMagicPower () const
    {
        double randomFactor
            = 0.9 + (static_cast<double> (std::rand ()) / RAND_MAX) * 0.2;
        return static_cast<int> (characterAbstruct.MagicPower * randomFactor);
    }

    // force subclass do this func
    virtual void attack (Character &target) = 0;
};

class Warrior : public Character
{
  public:
    Warrior (Attributes characterAbstruct) : Character (characterAbstruct) {}

    void
    attack (Character &target) override
    {
        std::cout << characterAbstruct.name << " swings a sword at "
                  << target.getName () << "!" << std::endl;
        target.takeDamage (
            target.CalculateIncomingDamage (this->GetRolledAttack (), 1));
    }
};

class Monster : public Character
{
  public:
    Monster (Attributes characterAbstruct) : Character (characterAbstruct) {}
    void
    attack (Character &target) override
    {
        std::cout << characterAbstruct.name << " bites " << target.getName ()
                  << " fiercely!" << std::endl;
        target.takeDamage (
            target.CalculateIncomingDamage (this->GetRolledAttack (), 1));
    }
};
