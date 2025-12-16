#pragma once
#include "Item.hpp"
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct Attributes
{
    std::string name{};
    OwnerType characterType{ OwnerType::Hero };
    int attack{};
    int defense{};
    int MagicPower{};
    int MagicDefense{};
    int armor{};
    int nowhp{};
    int maxhp{};
};

class Character
{
  protected:
    Attributes baseCharacterAttributes;
    Attributes currentCharacterAttributes;

    std::vector<std::shared_ptr<Equipment>> equipedItem;

  public:
    Character (const Attributes &abstruct)
        : baseCharacterAttributes (abstruct),
          currentCharacterAttributes (abstruct), equipedItem{}
    {
    }

    virtual ~Character () = default;

    bool
    isDead () const
    {
        if (currentCharacterAttributes.nowhp <= 0)
            {
                return true;
            }
        return false;
    }

    std::string
    getName () const
    {
        return baseCharacterAttributes.name;
    }

    int
    CalculateIncomingDamage (int rawDamage, bool isPhysical)
    {
        int finalDamage{ 0 };
        if (isPhysical)
            {
                int damageAfterDefense
                    = rawDamage - currentCharacterAttributes.defense;

                int armorReduction = currentCharacterAttributes.armor / 4;

                finalDamage = damageAfterDefense - armorReduction;
            }
        else
            {
                finalDamage
                    = rawDamage - currentCharacterAttributes.MagicDefense;
            }
        return std::max (1, finalDamage);
    }
    void
    takeDamage (int actualDamage)
    {
        currentCharacterAttributes.nowhp -= actualDamage;
        std::cout << getName () << " took " << actualDamage << " damage!"
                  << " (HP: " << currentCharacterAttributes.nowhp << ")"
                  << std::endl;
    }

    int
    GetRolledAttack ()
    {
        double randomFactor
            = 0.9 + (static_cast<double> (std::rand ()) / RAND_MAX) * 0.2; //?
        return static_cast<int> (currentCharacterAttributes.attack
                                 * randomFactor);
    }

    int
    GetRolledMagicPower () const
    {
        double randomFactor
            = 0.9 + (static_cast<double> (std::rand ()) / RAND_MAX) * 0.2;
        return static_cast<int> (currentCharacterAttributes.MagicPower
                                 * randomFactor);
    }

    void
    ReCalculateCharacterStats ()
    {
        currentCharacterAttributes = baseCharacterAttributes;
        for (const auto &equiped : equipedItem)
            {
                currentCharacterAttributes.attack
                    += equiped->GetItemTotalBonus (Effct::Attack);
                currentCharacterAttributes.defense
                    += equiped->GetItemTotalBonus (Effct::Defense);
                currentCharacterAttributes.MagicPower
                    += equiped->GetItemTotalBonus (Effct::MagicPower);
                currentCharacterAttributes.MagicDefense
                    += equiped->GetItemTotalBonus (Effct::MagicDefense);
                currentCharacterAttributes.maxhp
                    += equiped->GetItemTotalBonus (Effct::Health);
                currentCharacterAttributes.armor
                    += equiped->GetItemTotalBonus (Effct::Armor);
            }
    }

    void
    ShowCharacterDetail ()
    {
        std::cout << "----Character Details----" << std::endl;
        if (baseCharacterAttributes.characterType == OwnerType::Hero)
            {
                std::cout << "name: " << baseCharacterAttributes.name
                          << " -> Hero \n"
                          << "Attack: " << currentCharacterAttributes.attack
                          << "\n"
                          << "Defense: " << currentCharacterAttributes.defense
                          << "\n"
                          << "MagicPower: "
                          << currentCharacterAttributes.MagicPower << "\n"
                          << "MagicDefense: "
                          << currentCharacterAttributes.MagicDefense << "\n"
                          << "Armor: " << currentCharacterAttributes.armor
                          << "\n"
                          << "HP: (" << currentCharacterAttributes.nowhp << "/"
                          << currentCharacterAttributes.maxhp << ")"
                          << std::endl;
            }
    }

    void
    Equip (std::shared_ptr<Equipment> item)
    {
        if (!item)
            {
                return;
            }
        equipedItem.push_back (item);
        std::cout << getName () << " equipped " << item->GetName ()
                  << std::endl;
        ReCalculateCharacterStats ();
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
        std::cout << baseCharacterAttributes.name << " swings a sword at "
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
        std::cout << currentCharacterAttributes.name << " bites "
                  << target.getName () << " fiercely!" << std::endl;
        target.takeDamage (
            target.CalculateIncomingDamage (this->GetRolledAttack (), 1));
    }
};
