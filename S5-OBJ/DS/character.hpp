//----------------------------------------------------------------------------

#ifndef S5LOO_CHARACTER_HPP
#define S5LOO_CHARACTER_HPP

#include "rndGen.hpp"
#include <utility>

#include <iostream>

namespace s5loo {

class Character
{
    protected:
        RndGen *rndGen_;

    private:
		std::string name_;
        double lifePoints_;

	public:
		Character() = default;
		Character(std::string name, double lifePoints) : rndGen_{nullptr}, name_{std::move(name)}, lifePoints_{lifePoints} {};

		Character(const Character &) = delete; //constructeur par recopie
		Character(Character &&) = delete; //constructeur par déplacement
		Character& operator=(const Character &) = delete; //affectation par recopie
		Character& operator=(Character &&) = delete; //affectation par déplacement
		virtual ~Character() = default; //destructeur

        std::string name() const {return name_;}
        bool isAlive() const {return lifePoints_ > 0? true : false;}
        std::string toString() const {return name_ + " LifePoints : " + std::to_string(lifePoints_);}
        void rndGen(RndGen & rndGen) {rndGen_ = & rndGen;}

        virtual double defend(double d) {return rndGen_->real(d);}
        void isAttacked(double damages) {lifePoints_ -= defend(damages);}
        virtual double damage() = 0;
        void attack(Character& c);
};

inline void Character::attack(Character& c)
{
    auto d = damage();
    c.isAttacked(d);
    std::cout << name() << " attack on : " << c.name() << " --> " << (c.isAlive()? "alive" : "dead") << std::endl;
}
		
        

} // namespace s5loo

#endif // S5LOO_CHARACTER_HPP

//----------------------------------------------------------------------------
