//----------------------------------------------------------------------------

#ifndef S5LOO_JDR_HPP
#define S5LOO_JDR_HPP

#include "character.hpp"
#include <vector>

#include <memory>

namespace s5loo {

class JDR
{
    private:
        RndGen rndGen_;
        std::vector<std::unique_ptr<Character>> badFolks_;
        std::vector<std::unique_ptr<Character>> goodFolks_;
        bool goodFolksStart_;

    public:
        JDR() : rndGen_{}, badFolks_{}, goodFolks_{}, goodFolksStart_{rndGen_.boolean()} {}

		JDR(const JDR &) = default; //constructeur par recopie
		JDR(JDR &&) = default; //constructeur par déplacement
		JDR& operator=(const JDR &) = default; //affectation par recopie
		JDR& operator=(JDR &&) = default; //affectation par déplacement
		virtual ~JDR() = default; //destructeur

        void addGood(std::unique_ptr<Character> c) {c->rndGen(rndGen_); goodFolks_.emplace_back(std::move(c));}
        void addBad(std::unique_ptr<Character> c) {c->rndGen(rndGen_); badFolks_.emplace_back(std::move(c));}
        void run();
        void printTeams();

    
};

inline void JDR::printTeams()
{
    std::cout << "good folks : ";
    for (const auto & elem : goodFolks_)
    {
        std::cout << elem->name() << " ";
    }
    std::cout << std::endl;

    std::cout << "bad folks : ";
    for (const auto & elem : badFolks_)
    {
        std::cout << elem->name() << " ";
    }
    std::cout << std::endl;
}

inline void JDR::run()
{
    printTeams();

    while (true)
    {
        auto indexA = rndGen_.index(goodFolks_);
        auto indexB = rndGen_.index(badFolks_);

        if (goodFolksStart_)
        {
            goodFolks_[indexA]->attack(*badFolks_[indexB]);
            badFolks_[indexB]->attack(*goodFolks_[indexA]);
        }
        else
        {
            badFolks_[indexB]->attack(*goodFolks_[indexA]);
            goodFolks_[indexA]->attack(*badFolks_[indexB]);
        }

        if (!badFolks_[indexB]->isAlive())
        {
            badFolks_.erase(cbegin(badFolks_) + indexB);
        }

        if (!goodFolks_[indexA]->isAlive())
        {
            goodFolks_.erase(cbegin(goodFolks_) + indexA);
        }

        printTeams();

        if (goodFolks_.empty() || badFolks_.empty())
        {
            break;
        }
    }

}

} // namespace s5loo

#endif // S5LOO_JDR_HPP

//----------------------------------------------------------------------------
