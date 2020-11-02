//////////////////////////////////
//	Prog.cpp
//	2020-11-02 10:10:34.714876
//	carree
//////////////////////////////////

#include "modulearray.hpp"
#include "modulevector.hpp"

void test_array()
{
	tp1::str15 a1;

	tp1::printArray(a1);
	tp1::fillArray(a1);
	tp1::printArray(a1);

	for (const auto& elem : a1)
	{
		std::cout << elem << '=' << tp1::isPalindrome(elem) << std::endl;
	}
}

void test_vector()
{
	auto v1 = tp1::makeVector(6);
	tp1::printVector(v1);
	auto [average, standard_deviation, median] = tp1::dataVector(v1);
	std::cout << "average : " << average << ", standard_deviation : " << standard_deviation << ", median : " << median << std::endl;
}



int main(int argc, char const *argv[])
{
	std::cout << "~~~~~~" << __func__ << "~~~~~~" << std::endl;

	test_array();
	test_vector();

	return 0;
}
