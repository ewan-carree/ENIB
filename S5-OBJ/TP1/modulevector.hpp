#ifndef MODULEVECTOR_HPP
#define MODULEVECTOR_HPP

#include <vector>
#include <string>
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

	intvec makeVector(const int count, const int nMin = 10, const int nMax = 100);
	void printVector(const intvec& v1);
	std::tuple<double, double, double> dataVector(const intvec& v1);



} //tp1
#endif //MODULEVECTOR_HPP