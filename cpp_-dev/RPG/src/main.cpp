#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Character {
protected:
  std::string name;
  int hp;
  int damage;

public:
  Character(std::string name, int hp, int damage)
      : name(name), hp(hp), damage(damage) {}

  virtual ~Character() = default;

  bool isDead() const {
    if (hp <= 0) {
      return true;
    }
    return false;
  }

  std::string getName() const { return name; }

  void takeDamage(int takeDamage_value) {
    hp -= takeDamage_value;
    std::cout << getName() << " took damage:" << takeDamage_value
              << " (Remaining HP: " << hp << ")" << std::endl;
  }

  // force subclass do this func
  virtual void attack(Character &target) = 0;
};

class Warrior : public Character {
public:
  Warrior(std::string n, int h, int d) : Character(n, h, d) {}

  void attack(Character &target) override {
    std::cout << name << " swings a sword at " << target.getName() << "!"
              << std::endl;
    target.takeDamage(damage);
  }
};

class Monster : public Character {
public:
  Monster(std::string n, int h, int d) : Character(n, h, d) {}
  void attack(Character &target) override {
    std::cout << name << " bites " << target.getName() << " fiercely!"
              << std::endl;
    target.takeDamage(damage);
  }
};

int main() {
  std::srand(static_cast<unsigned int>(std::time(nullptr)));
  std::vector<std::unique_ptr<Character>> fighters{};

  // add Character
  fighters.push_back(std::make_unique<Monster>("Goblin", 500, 12));

  fighters.push_back(std::make_unique<Warrior>("Luca", 100, 12));
  fighters.push_back(std::make_unique<Warrior>("Chrono", 120, 6));
  fighters.push_back(std::make_unique<Warrior>("Marle", 80, 20));

  int round{1};

  while (!fighters[0]->isDead()) // if_alive
  {
    std::cout << "\n--- Round " << round << " ---" << std::endl;

    // attack boss
    for (size_t i{1}; i < fighters.size(); ++i) {
      if (!fighters[i]->isDead()) // if_alive
      {
        fighters[i]->attack(*fighters[0]); //?
      }
      if (fighters[0]->isDead()) // if_dead
      {
        break;
      }
    }

    // boss dead,break
    if (fighters[0]->isDead()) {
      break;
    }

    bool allHeroDead{true};
    for (size_t i{1}; i < fighters.size(); ++i) {
      if (!fighters[i]->isDead()) // if_alive
      {
        allHeroDead = false;
      }
    }
    if (allHeroDead) {
      break;
    }

    std::cout << ">>> Boss Counter-Attack! <<<" << std::endl;

    int heroCount = static_cast<int>(fighters.size()) - 1;
    int targetIndex = (std::rand() % heroCount) + 1; //?

    if (!fighters[static_cast<size_t>(targetIndex)]->isDead()) // if_alive
    {
      fighters[0]->attack(*fighters[static_cast<size_t>(targetIndex)]);
    } else {
      std::cout << "The Boss attacks the corpse of "
                << fighters[static_cast<size_t>(targetIndex)]->getName()
                << "..." << std::endl;
    }
    round++;
  }

  std::cout << "\n=== BATTLE ENDED ===" << std::endl;
  if (fighters[0]->isDead()) // if_dead
  {
    std::cout << "Victory! The Goblin King has been defeated!" << std::endl;
  } else {
    std::cout << "Defeat... The party was wiped out." << std::endl;
  }

  return 0;
}
