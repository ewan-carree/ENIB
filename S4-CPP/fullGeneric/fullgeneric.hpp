#ifndef FULLGENERIC_HPP
#define FULLGENERIC_HPP

#include <vector>
#include <string>
#include <stdexcept> //runtime_error
#include <iostream>
#include <utility> // std::move()
#include <algorithm> //fonctions génériques
#include <array>

namespace exam
{
	#if 0 // both arguments have the same type

	template<typename T>
	inline
	T
	avg(const T &a,
	    const T &b)
	{
	  return (a+b)/2;
	}

	#else

	template<typename T1,
	         typename T2>
	inline
	auto
	avg(const T1 &a,
	    const T2 &b)
	{
	  return (a+b)/2;
	}

	#endif

	inline
	std::string
	avg(const std::string &a,
	    const std::string &b)
	{
	  const int sza=int(size(a));
	  const int szb=int(size(b));
	  const int sz=avg(sza, szb);
	  std::string result;
	  for(int i=0; int(size(result))<sz; ++i)
	  {
	    if(i<sza)
	    {
	      result+=a[i];
	    }
	    if(i<szb)
	    {
	      result+=b[i];
	    }
	  }
	  return result;
	}

	template<typename T>
	inline
	auto
	avg(const T &a,
	    const std::string &b)
	{
	  using std::to_string;
	  return avg(to_string(a), b);
	}

	template<typename T>
	inline
	auto
	avg(const std::string &a,
	    const T &b)
	{
	  using std::to_string;
	  return avg(a, to_string(b));
	}
} //exam
#endif //FULLGENERIC_HPP