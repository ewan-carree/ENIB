#ifndef STUCT_HPP
#define STRUCT_HPP

#include <array>
#include <vector>
#include <string>

#define MAGNITUDE 9.81

namespace exam {

struct Init0
{
  int a;
  double b;
};

struct Init1 
{
  int a{10};
  double b{10.0};
};

struct Init2 
{
  int a;
  double b;

  Init2() 
  : a{100}
  , b{100.0}
  {
    //empty body
  }
};

struct Init3 
{
  int a;
  double b;

  Init3(int a_,double b_)
  :a{a_}
  ,b{b_}
  {
    //empty body
  }

  #if 1 // enable/disable during experimentation

  Init3()
  : Init3{10'000,10'000.0} // delegating constructor
  {
    // (empty) constructor body
  }

  #endif
};

#if 0
struct Gravity
{
  // stattic constexpr double MAGNITUDE{9.81}; // autre type pour définir g seulement pour cette struct
  std::array<double,3> xyz;

  Gravity()
  : xyz{{0.0,0.0,-MAGNITUDE}}
  {

  }

  Gravity(double x, double y, double z);
};

std::ostream &
operator<<(std::ostream &output,
           const Gravity &g);

double
magnitude(const exam::Gravity &g);

#else

class Gravity
{
  
  private :
  std::array<double,3> xyz_; // le "_" indique que c'est privé pour un relecteur
  void set_(double value,double &changed); //Nous estimons qu'elle ne sert qu'un besoin lié à l'organisation interne du type structuré ; c'est la raison pour laquelle nous la rendons inaccessible au reste du code du programme
 
  public :
  Gravity()
  : xyz_{{0.0,0.0,-MAGNITUDE}}
  {

  }

  Gravity(double x, double y, double z);

  // une fonction membre ne nécessite pas de exam:: ou Gravity:: c'est implicite
  double z() const // Une fonction membre qui ne fait que consulter l'état de la donnée qu'elle concerne, sans la modifier, doit être qualifiée de const
  {
    return xyz_[2];
  }
  double y() const
  {
    return xyz_[1];
  }
  double x() const
  {
    return xyz_[0];
  }

  void reverse();

  void setZ(double z)
  {
    set_(z, xyz_[2]);
  }
  void setY(double y)
  {
    set_(y, xyz_[1]);
  }
  void setX(double x)
  {
    set_(x, xyz_[0]);
  }

};

std::ostream &
operator<<(std::ostream &output,
           const Gravity &g);

double magnitude(const exam::Gravity &g);

exam::Gravity opposite(const exam::Gravity &g);


class Book
{
public:

  Book(std::vector<std::string> words={});

  Book(int wordCount,
       int maxLength);

  int
  word_count() const
  {
    return int(words_.size());
  }

  int
  letter_count() const
  {
    return letter_count_;
  }

  const std::vector<std::string> &
  words() const
  {
    return words_;
  }

  Book(const Book &) =delete;
  Book(Book &&) =default;
  Book & operator=(const Book &) =delete;
  Book & operator=(Book &&) =default;
  ~Book() =default;

private:
  std::vector<std::string> words_;
  int letter_count_;
};



#endif

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
  english() const
  {
    return english_;
  }

  const Book &
  italian() const
  {
    return italian_;
  }

  //-- provide copy --
  SchoolBag(const SchoolBag &rhs);
  SchoolBag& operator=(const SchoolBag &rhs);

  //-- default move is suitable --
  SchoolBag(SchoolBag &&) =default;
  SchoolBag & operator=(SchoolBag &&) =default;

  //-- default destruction is suitable --
  ~SchoolBag() =default;

private:
  Book english_;
  Book italian_;
};


}

#endif