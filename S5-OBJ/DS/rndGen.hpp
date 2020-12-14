//----------------------------------------------------------------------------

#ifndef S5LOO_RNDGEN_HPP
#define S5LOO_RNDGEN_HPP

#include <random>
#include <chrono>
#include <vector>
#include <string>

namespace s5loo {

class RndGen
{
public:

  RndGen()
  : generator_{}
  , names_{}
  {
    const auto t=std::chrono::system_clock::now().time_since_epoch().count();
    generator_.seed(static_cast<unsigned int>(t));
  }

  int // random value in [0; count)
  integer(int count)
  {
    std::uniform_int_distribution<int> distr{0, count-1};
    return distr(generator_);
  }

  bool // true or false
  boolean()
  {
    return integer(2)==0;
  }

  double // random value in [0.0; 1.0]
  real(double range=1.0)
  {
    std::uniform_real_distribution<double> distr{0.0, range};
    return distr(generator_);
  }

  template<typename T>
  int // random index or -1
  index(const std::vector<T> &v)
  {
    return empty(v) ? -1 : integer(static_cast<int>(size(v)));
  }

  std::string
  name()
  {
    if(names_.empty())
    {
      names_={"Jack", "Landy", "Bob", "Kate", "Harry", "Nick", "Phil",
              "Marge", "Marck", "Luke", "Elly", "Sue", "Lisa", "Carol",
              "Mandy", "Hugo", "Julia", "Margo", "Arthur", "Ricky", "Alex",
              "Tony", "Tim", "Astrid", "Hiccup", "Tom", "Lea"};
    }
    const auto idx=index(names_);
    const auto name=std::move(names_[idx]);
    names_.erase(cbegin(names_)+idx);
    return name;
  }

  double
  lifePoints()
  {
    return 30.0+real(60.0);
  }

  double
  dexterity()
  {
    return 50.0+real(30.0);
  }

  double
  mana()
  {
    return 50.0+30.0*real();
  }

private:
  std::default_random_engine generator_;
  std::vector<std::string> names_;
};

} // namespace s5loo

#endif // S5LOO_RNDGEN_HPP

//----------------------------------------------------------------------------
