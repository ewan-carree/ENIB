#ifndef STUCT2_HPP
#define STRUCT2_HPP

#include <array>
#include <vector>
#include <string>

namespace exam{
class SchoolBag
{
public:

  SchoolBag(Book english={},
            Book italian={})
  : english_{std::move(english)}
  , italian_{std::move(italian)}
  {
    // nothing more to be done
  }

  const Book &
  english()
  {
    return english_;
  }

  const Book &
  italian()
  {
    return italian_;
  }

private:
  Book english_;
  Book italian_;
};

}

#endif