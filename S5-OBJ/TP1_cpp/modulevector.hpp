#ifndef MODULEVECTOR_HPP
#define MODULEVECTOR_HPP

#include <vector>
#include <string.h>
#include <stdexcept> //runtime_error
#include <iostream>
#include <utility> // std::move()
#include <tuple>
#include <cassert>
#include <algorithm>
#include <cmath>

namespace tp1
{
	using intvec = std::vector<int>;
	using doublevec = std::vector<double>;

	intvec makeVector(const int count, const int nMin = 10, const int nMax = 100);
	void printVector(const intvec& v1);
	std::tuple<double, double, double> dataVector(const intvec& v1);

	class Math_function
	{
	public:
		static double average(const intvec& v1);
		static double standard_deviation(const double variance);
		static double median(const intvec& v1);
		static double variance(const intvec& v1, const double average);
	};



} //tp1
#endif //MODULEVECTOR_HPP