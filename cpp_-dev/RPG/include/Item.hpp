#include <map>
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
    std::map<Effct, int> baseStats;

  public:
    /**
     * Construct an Item object.
     *
     * @param name The name of the item.
     * @param type The type of the item.
     * @param description The description of the item.
     * @param effct The effect of the item.
     * @param value The value of the item.
     */
    Item (std::string name, OwnerType type, std::string description,
          std::map<Effct, int> baseStats)
        : name (name), type (type), description (description),
          baseStats (baseStats)
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
    GetBaseStat (Effct target)
    {
        if (baseStats.count (target))
            {
                return baseStats.at (target);
            }
        return 0;
    }
};

class Equipment : public Item
{
  protected:
    std::vector<Affix> affixes;

  public:
    /**
     * Construct an Equipment object.
     *
     * @param name The name of the equipment.
     * @param type The type of the equipment.
     * @param description The description of the equipment.
     * @param effct The effect of the equipment.
     * @param value The value of the equipment.
     */
    Equipment (std::string name, OwnerType type, std::string description,
               std::map<Effct, int> stats)
        : Item (name, type, description, stats)
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

    int
    GetItemTotalBonus (Effct targetEffct) const
    {
        int total{};
        if (baseStats.count (targetEffct))
            {
                total += baseStats.at (targetEffct);
            }

        for (const auto &affix : affixes)
            {
                if (affix.effctInAffix == targetEffct)
                    {
                        total += affix.value;
                    }
            }
        return total;
    }

    std::string
    ShowDetail () const override
    {
        std::string returnedAffix{};
        std::string info{};

        for (const auto &affix : affixes)
            {
                returnedAffix += affix.toString () + "\n";
            }
        returnedAffix += description;

        switch (type)
            {
            case OwnerType::Hero:
                info = Item::GetName () + "-> Hero" + "\n";
            case OwnerType::Monster:
                info = Item::GetName () + "-> Monster" + "\n";
            default:
                return "Unknow";
            }

        for (auto const &[key, val] : baseStats)
            {
                switch (key)
                    {
                    case Effct::Attack:
                        info += "Attack" + std::to_string (val);
                    case Effct::Defense:
                        info += "Defense" + std::to_string (val);
                    case Effct::MagicPower:
                        info += "MagicPower" + std::to_string (val);
                    case Effct::MagicDefense:
                        info += "MagicDefense" + std::to_string (val);
                    case Effct::Health:
                        info += "hp" + std::to_string (val);
                    case Effct::Armor:
                        info += "Armor" + std::to_string (val);
                    default:
                        info += "Unknow";
                    }
            }
    }
};

class HeroEquipment : public Equipment
{
  public:
    /**
     * Construct a HeroEquipment object.
     *
     * @param name The name of the equipment.
     * @param description The description of the equipment.
     * @param effct The effect of the equipment.
     * @param value The value of the equipment.
     */
    HeroEquipment (std::string name, std::string description,
                   std::map<Effct, int> baseStats)
        : Equipment (name, OwnerType::Hero, description, baseStats)
    {
    }
};

class MonsterEquipment : public Equipment
{
  public:
    /**
     * Construct a MonsterEquipment object.
     *
     * @param name The name of the equipment.
     * @param description The description of the equipment.
     * @param effct The effect of the equipment.
     * @param value The value of the equipment.
     */
    MonsterEquipment (std::string name, std::string description,
                      std::map<Effct, int> baseStats)
        : Equipment (name, OwnerType::Monster, description, baseStats)
    {
    }
};
