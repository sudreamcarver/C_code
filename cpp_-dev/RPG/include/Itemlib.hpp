#pragma once
#include "Item.hpp"
#include <map>
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
    }
};
