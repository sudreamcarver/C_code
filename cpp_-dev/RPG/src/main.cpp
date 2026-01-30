#include "Item.hpp"
#include "Itemlib.hpp"
#include "UIManager.hpp"
#include "character.hpp"
#include <Input.hpp>
#include <ctime>
#include <iostream>

int
main ()
{
    std::srand (static_cast<unsigned int> (std::time (nullptr)));

    UIManager UI;

    // 1. 初始化
    ItemLibrary lib;
    Attributes baseStats
        = { "Luca", OwnerType::Hero, 10, 5, 0, 0, 0, 100, 100 };
    Warrior hero (baseStats);

    // 2. 制造装备
    auto sword = std::static_pointer_cast<Equipment> (lib.CreatItem ("sword"));
    auto armor
        = std::static_pointer_cast<Equipment> (lib.CreatItem ("IronArmor"));

    // 3. 给剑添加额外的词条 (比如附魔)
    if (sword)
        {
            sword->addAffix ("FireEnchant", 5, Effct::Attack);
            sword->addAffix ("HPADD", 5, Effct::Health);
        }

    // // 4. 穿装备前打印
    // std::cout << "--- Before Equip ---" << std::endl;
    // std::cout << "Attack: " << hero.GetRolledAttack ()
    //           << std::endl; // 应该是 10 左右
    //
    // // 5. 穿装备
    // hero.Equip (sword); // 攻 +10, 词条 +5
    // hero.Equip (armor); // 甲 +10
    //
    // // 6. 穿装备后打印
    // std::cout << "\n--- After Equip ---" << std::endl;
    // // 基础10 + 剑10 + 词条5 = 25
    // std::cout << "Attack: " << hero.GetRolledAttack () << std::endl;
    //
    // // 7. 打印装备详情验证 Switch 是否修好
    // std::cout << "\n--- Sword Details ---" << std::endl;
    // std::cout << sword->ShowDetail () << std::endl;
    // hero.ShowCharacterDetail ();

    return 0;
}
