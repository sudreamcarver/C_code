#include "Inventory.hpp"
#include <iostream>
#include <string>

/**
 * @brief Adds a certain number of items to the inventory.
 *
 * @param name The name of the item to add.
 * @param count The number of items to add.
 */
void Inventory::addItem(const std::string &name, int count) {
  items[name] += count;
  std::cout << "Added " << count << " " << name << "(s)." << std::endl;
}

/**
 * @brief Removes a certain number of items from the inventory.
 *
 * If the item is not found, it will print a message and do nothing.
 * If the item count reaches 0 or below after removal, it will print a message and remove the item from the inventory.
 * If the item count is above 0 after removal, it will print a message with the number of items removed.
 *
 * @param name The name of the item to remove.
 * @param count The number of items to remove.
 */
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

/**
 * @brief Displays all items in the inventory.
 *
 * This function will print the current inventory state with the item name and count.
 */
void Inventory::showAll() {
  std::cout << "\n--- Inventory List ---" << std::endl;
  for (const auto &pair : items) {
    std::cout << pair.first << ": " << pair.second << std::endl;
  }
  std::cout << "----------------------" << std::endl;
}
