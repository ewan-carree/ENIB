//----------------------------------------------------------------------------

#include "jdr.hpp"
#include "knight.hpp"
#include "druid.hpp"

#include <iostream>

int 
main()
{
  s5loo::RndGen rndGen;

  s5loo::JDR jdr;

  for (int i = 0; i < 3; i++)
  {
    jdr.addGood(std::make_unique<s5loo::Knight>(rndGen.name(), rndGen.lifePoints(), rndGen.dexterity()));
    jdr.addBad(std::make_unique<s5loo::Knight>(rndGen.name(), rndGen.lifePoints(), rndGen.dexterity()));
    jdr.addGood(std::make_unique<s5loo::Druid>(rndGen.name(), rndGen.lifePoints(), rndGen.mana()));
    jdr.addBad(std::make_unique<s5loo::Druid>(rndGen.name(), rndGen.lifePoints(), rndGen.mana()));
  }

  jdr.run();

  return 0;
}

//----------------------------------------------------------------------------
