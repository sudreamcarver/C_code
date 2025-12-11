#include "Inventory.hpp"
#include <iostream>
#include <string>

void Inventory::addItem(const std::string &name, int count) {
  items[name] += count;
  std::cout << "Added " << count << " " << name << "(s)." << std::endl;
}

void Inventory::removeItem(const std::string &name, int count) {
  if (items.count(name) == 0) {
    std::cout << "Item not found!" << std::endl;
    return;
  }

  items[name] -= count;

  if (items.count(name) <= 0) {
    std::cout << "Item run out" << name << "removed" << std::endl;
    items.erase(name);
  }

  else {
    std::cout << "Removed " << count << " " << name << "(s)." << std::endl;
  }
}

void Inventory::showAll() {
  std::cout << "\n--- Inventory List ---" << std::endl;
  for (const auto &pair : items) {
    std::cout << pair.first << ": " << pair.second << std::endl;
  }
  std::cout << "----------------------" << std::endl;
}
