//----------------------------------------------------------------------------

#ifndef S5LOO_KNIGHT_HPP
#define S5LOO_KNIGHT_HPP

#include "character.hpp"
#include <utility>

namespace s5loo {

class Knight final: public Character
	{
		private:
		double dexterity_;

		public:
		Knight() = default;
		Knight(std::string name, double lifePoints, double dexterity) : Character{std::move(name), lifePoints}, dexterity_{dexterity} {};

        double defend(double d) override {return Character::defend(d) - dexterity_ / 100;}
        double damage() override final;

		
	};

    inline double Knight::damage()
    {
        auto damage = rndGen_->real(dexterity_);
        if (damage > 60 * 100 / dexterity_)
        {
            dexterity_ += 18;
        }
        
        return damage;
    }

} // namespace s5loo

#endif // S5LOO_KNIGHT_HPP

//----------------------------------------------------------------------------
