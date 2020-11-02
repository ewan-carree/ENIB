#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <random>
#include <cmath>
#include "struct.hpp"

namespace exam{

#if 0
Gravity::Gravity(double x, double y, double z)
: Gravity{} // delegating constructor
{
  if(const double sqrMag=x*x+y*y+z*z; // square magnitude of input vector
     sqrMag!=0.0) // overwrite default values only if input vector is not null
  {
    const double factor=MAGNITUDE/std::sqrt(sqrMag);
    xyz={x*factor, y*factor, z*factor}; // adjust magnitude
  }
}

double
magnitude(const exam::Gravity &g)
{
  return std::sqrt(g.xyz[0]*g.xyz[0]+g.xyz[1]*g.xyz[1]+g.xyz[2]*g.xyz[2]);
}

#else

Gravity::Gravity(double x, double y, double z) // Gravity::Gravity signifie que la fonction gravity appartient au spacenae Gravity qui est ici la structure dans laquelle la fonction est encapsulée
: Gravity{} // delegating constructor
{
  if(const double sqrMag=x*x+y*y+z*z; // square magnitude of input vector
     sqrMag!=0.0) // overwrite default values only if input vector is not null
  {
    const double factor=MAGNITUDE/std::sqrt(sqrMag);
    xyz_={x*factor, y*factor, z*factor}; // adjust magnitude
  }
}

double
magnitude(const exam::Gravity &g)
{
  return std::sqrt(g.x()*g.x()+g.y()*g.y()+g.z()*g.z()); // une fonction membre ne nécessite pas de exam:: ou Gravity:: c'est implicite
}

void Gravity::reverse(){
	for (int i = 0; i < 3; ++i)
	{
		xyz_[i] = -1*xyz_[i];
	}
}

Gravity opposite(const Gravity &g){
	Gravity result = g;
	result.reverse();
	return result;
}

void Gravity::set_(double value,
              double &changed)
{
  value=std::max(-MAGNITUDE, std::min(MAGNITUDE, value));
  changed=value;
  double sqrRemaining=0.0;
  for(const auto &elem: xyz_)
  {
    if(&elem!=&changed)
    {
      sqrRemaining+=elem*elem;
    }
  }
  if(sqrRemaining!=0.0)
  {
    const double sqrExpected=MAGNITUDE*MAGNITUDE-value*value;
    const double factor=std::sqrt(sqrExpected/sqrRemaining);
    for(auto &elem: xyz_)
    {
      if(&elem!=&changed)
      {
        elem*=factor;
      }
    }
  }
}

std::ostream &
operator<<(std::ostream &output,
           const Gravity &g)
{
  return output << "{"  << g.x()
                << ", " << g.y()
                << ", " << g.z() << "}";
}

#endif

Book::Book(std::vector<std::string> words)
: words_{std::move(words)}
, letter_count_{0}
{
  for(const auto &elem: words_)
  {
    letter_count_+=int(size(elem));
  }
}

Book::Book(int wordCount,
           int maxLength)
: words_{}
, letter_count_{0}
{
  std::default_random_engine rndGen{std::random_device{}()};
  std::uniform_int_distribution<int> lengthDistrib{1, maxLength};
  std::uniform_int_distribution<int> charDistrib{'A', 'Z'};
  words_.reserve(wordCount);
  for(int i=0; i<wordCount; ++i)
  {
    const int length=lengthDistrib(rndGen);
    std::string s;
    s.reserve(length);
    for(int j=0; j<length; ++j)
    {
      s+=char(charDistrib(rndGen));
    }
    words_.emplace_back(std::move(s));
    letter_count_+=length;
  }
}

SchoolBag::SchoolBag(const SchoolBag &rhs)
: english_{rhs.english_.words()}
, italian_{rhs.italian_.words()}
{
  // nothing more to be done
}


//règle à suivre constamment pour les opérateurs : type de retour du type de la classe constante + return *this
SchoolBag&
SchoolBag::operator=(const SchoolBag &rhs)
{
  english_=Book{rhs.english_.words()};
  italian_=Book{rhs.italian_.words()};
  return *this;
}

}