#include <string>
#include <vector>

// 物品源自
enum class OwnerType
{
    Hero,
    Monster
};

enum class Effct
{
    Attack,       // 攻击力
    Defense,      // 防御力
    MagicPower,   // 魔法攻击
    MagicDefense, // 法术防御
    Health,       // 生命值
    Armor         // 护甲
};
//
// 词条
struct Affix
{
    std::string name;
    Effct effctInAffix;
    int value;

    std::string
    toString () const
    {
        std::string sign = (value > 0) ? "+" : "";

        return name + "->" + GetEffctInAffix () + sign
               + std::to_string (value);
    }
    std::string
    GetEffctInAffix () const
    {
        switch (effctInAffix)
            {
            case Effct::Attack:
                return "Attack";
            case Effct::Defense:
                return "Defense";
            case Effct::MagicPower:
                return "MagicPower";
            case Effct::MagicDefense:
                return "MagicDefense";
            case Effct::Health:
                return "Health";
            case Effct::Armor:
                return "Armor";
            default:
                return "Unknow";
            }
    }
};

class Item
{
  protected:
    std::string name;
    OwnerType type;
    std::string description;
    Effct effct;
    int value;

  public:
    Item (std::string name, OwnerType type, std::string description,
          Effct effct, int value)
        : name (name), type (type), description (description), effct (effct),
          value (value)
    {
    }
    virtual ~Item () = default;

    virtual std::string ShowDetail () const = 0;

    auto
    GetType () const
    {
        return type;
    }

    auto
    GetName () const
    {
        return name;
    }
    auto
    GetDescriptison () const
    {
        return description;
    }
    auto
    GetEffct () const
    {
        return effct;
    }
    auto
    GetValue ()
    {
        return value;
    }
};

class Equipment : public Item
{
  protected:
    std::vector<Affix> affixes;

  public:
    Equipment (std::string name, OwnerType type, std::string description,
               Effct effct, int value)
        : Item (name, type, description, effct, value)
    {
    }

    void
    addAffix (std::string affixName, int value, Effct affixEffct)
    {
        Affix affix;
        affix.name = affixName;
        affix.value = value;
        affix.effctInAffix = affixEffct;
        affixes.push_back (affix);
    }

    std::string
    ShowDetail () const override
    {
        std::string returnedAffix{};
        for (const auto &affix : affixes)
            {
                returnedAffix += affix.toString () + "\n";
            }
        returnedAffix += description;

        switch (type)
            {
            case OwnerType::Hero:
                return Item::GetName () + "-> Hero" + "\n" + returnedAffix;
            case OwnerType::Monster:
                return Item::GetName () + "-> Monster" + "\n" + returnedAffix;
            default:
                return "Unknow";
            }
    }
};

class HeroEquipment : public Equipment
{
  public:
    HeroEquipment (std::string name, std::string description, Effct effct,
                   int value)
        : Equipment (name, OwnerType::Hero, description, effct, value)
    {
    }
};

class MonsterEquipment : public Equipment
{
  public:
    MonsterEquipment (std::string name, std::string description, Effct effct,
                      int value)
        : Equipment (name, OwnerType::Monster, description, effct, value)
    {
    }
};
