#pragma once
#include "Item.hpp"
#include <iostream>
#include <map>
#include <memory>
#include <string>

struct ItemBluePrint
{
    std::string name;
    OwnerType type;
    std::string description;
    Effct effct;
    int value;
};

class ItemLibrary
{
  private:
    std::map<std::string, ItemBluePrint> bluePrint;

  public:
    ItemLibrary ()
    {
        bluePrint["sword"]
            = { "sword", OwnerType::Hero, "a sword", Effct::Attack, 10 };
        bluePrint["GoblinClub"]
            = { "GoblinClub", OwnerType::Monster, "A dirty wooden club.",
                Effct::Attack, 12 };
        bluePrint["IronArmor"]
            = { "IronArmor", OwnerType::Hero, "Standard soldier armor",
                Effct::Armor, 10 };
    }
    void
    DefineItem (const std::string &id, const ItemBluePrint &bp)
    {
        bluePrint[id] = bp;
    }
    std::shared_ptr<Item>
    CreatItem (const std::string &itemName)
    {
        auto it = bluePrint.find (itemName);
        if (it == bluePrint.end ())
            {
                std::cout << "[Error] Item not found:" << itemName
                          << std::endl;
                return nullptr;
            }

        const ItemBluePrint &bp = it->second;

        if (bp.type == OwnerType::Hero)
            {
                return std::make_shared<HeroEquipment> (
                    bp.name, bp.description, bp.effct, bp.value);
            }
        else if (bp.type == OwnerType::Monster)
            {
                return std::make_shared<MonsterEquipment> (
                    bp.name, bp.description, bp.effct, bp.value);
            }
        return nullptr;
    }
};
