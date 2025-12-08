#pragma once
#include <map>
#include <string>

class Inventory
{
  private:
    std::map<std::string, int> items;

  public:
    void addItem (const std::string &name, int count);
    void removeItem (const std::string &name, int count);
    void showAll ();
};
