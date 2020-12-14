//----------------------------------------------------------------------------

#ifndef S5LOO_DRUID_HPP
#define S5LOO_DRUID_HPP

#include "character.hpp"

namespace s5loo {

class Druid final : public Character
{
    private:
    double mana_;

    public:
    Druid() = default;
	Druid(std::string name, double lifePoints, double dexterity) : Character{std::move(name), lifePoints}, mana_{dexterity} {};
    
    double damage() override final;
};

inline double Druid::damage()
{
    auto damage = rndGen_->real(mana_);
    if (damage > 100 * 60 / mana_)
    {
        mana_ += 10;
    }

    return damage;
}

} // namespace s5loo

#endif // S5LOO_DRUID_HPP

//----------------------------------------------------------------------------
