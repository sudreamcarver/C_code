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
    std::map<Effct, int> baseStats;
};

class ItemLibrary
{
  private:
    std::map<std::string, ItemBluePrint> bluePrint;

  public:
    /**
     * This class represents a library of item blueprints.
     */
    ItemLibrary ()
    {
        bluePrint["sword"] = {
            "sword", OwnerType::Hero, "a sword", { { Effct::Attack, 10 } }
        };
        bluePrint["GoblinClub"] = { "GoblinClub",
                                    OwnerType::Monster,
                                    "A dirty wooden club.",
                                    { { Effct::Attack, 10 } } };
        bluePrint["IronArmor"] = { "IronArmor",
                                   OwnerType::Hero,
                                   "Standard soldier armor",
                                   { { Effct::Armor, 10 } } };
    }

    /**
     * @brief Creates a new item in the item blueprints.
     *
     * @param id The name of the item to create.
     *
     */
    void
    DefineItem (const std::string &id, const ItemBluePrint &bp)
    {
        bluePrint[id] = bp;
    }
    /**
     * @brief Creates a new item using the item blueprints.
     *
     * @param itemName The name of the item to create.
     *
     * @return A shared pointer to the newly created item. If the item is not
     * found, nullptr is returned.
     */
    /**
     * If the item is found, it will return a shared pointer to the newly
     * created item. If the item is not found, it will print an error message
     * and return nullptr.
     */
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
                    bp.name, bp.description, bp.baseStats);
            }
        else if (bp.type == OwnerType::Monster)
            {
                return std::make_shared<MonsterEquipment> (
                    bp.name, bp.description, bp.baseStats);
            }
        return nullptr;
    }
};
