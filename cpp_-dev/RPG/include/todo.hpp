#include <vector>
// ... 之前的 Item 类定义 ...

// 1. 中间层：装备类
class Equipment : public Item
{
  protected:
    // TODO: 定义一个 vector 存 Affix
    std::vector<Affix> affixes;

  public:
    // TODO: 构造函数
    // 注意：这里需要把 name 和 type 传给 Item(name, type)
    Equipment (std::string name, OwnerType type)... {}

    // TODO: 添加词条的方法
    void
    addAffix (std::string affixName, int value)
    {
        // push_back ...
    }

    // TODO: 核心！重写展示详情
    void
    showDetail () const override
    {
        // 1. 打印名字 (可以利用 getOwnerType() 判断打印 "Hero" 还是 "Monster")

        // 2. 遍历 affixes 打印每个词条
    }
};

// 2. 终极子类：勇者装备
class HeroEquipment : public Equipment
{
  public:
    // TODO: 构造函数
    // 这里的关键是：只传 name，但是给父类传 OwnerType::Hero
    HeroEquipment (std::string name)... {}
};

// 3. 终极子类：魔物装备
class MonsterEquipment : public Equipment
{
  public:
    // TODO: 构造函数
    // 给父类传 OwnerType::Monster
    MonsterEquipment (std::string name)... {}
};
