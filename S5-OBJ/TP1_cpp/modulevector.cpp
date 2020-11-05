#include "modulevector.hpp"

namespace tp1
{

	double Math_function::average(const intvec& v1)
	{
		double average{0.};
		for (const auto &elem : v1)
		{
			average += elem;
		}
		average /= int(v1.size());
		return average;
	}

	double Math_function::standard_deviation(const double variance)
	{
		return sqrt(variance);
	}

	double Math_function::median(const intvec& v1)
	{
		double median{0.};
		intvec v2 = v1;
		std::sort(v2.begin(), v2.end());
		printVector(v2);

		if (int(v2.size())%2 == 0) //pair
		{
			median = double((v2[int(v2.size() / 2) - 1] + v2[int(v2.size() / 2)]) / 2.);
		}

		else // impair
		{
			median = v2[int(int(v2.size())/2.)];
		}

		return median;
	}

	double Math_function::variance(const intvec& v1, const double average)
	{
		doublevec v2;
		for (const auto &elem : v1)
		{
			v2.push_back((double)elem);
		}

		for (auto& elem : v2)
		{
			elem -= average;
			elem *= elem;
		}

		double variance{0.};

		for (const auto& elem : v2)
		{
			variance += elem;
		}

		return variance/(int(v2.size()) - 1);
	}

	intvec makeVector(const int count, const int nMin, const int nMax)
	{
		intvec v1;

		for (int i = 0; i < count; ++i)
		{
			int randNum = rand()%(nMax-nMin + 1) + nMin;
			v1.push_back(randNum);
		}
		
		return v1;
	}

	void printVector(const intvec& v1)
	{
		for (const auto &integer : v1)
		{
			std::cout << '{' << integer << '}' << ' ';
		}

		std::cout << std::endl;
	}

	std::tuple<double, double, double> dataVector(const intvec& v1)
	{
		assert(int(v1.size()) != 0);

		auto average = Math_function::average(v1);
		auto variance = Math_function::variance(v1, average);
		auto standard_deviation = Math_function::standard_deviation(variance);
		auto median = Math_function::median(v1);	

		return {std::move(average), std::move(standard_deviation), std::move(median)};
	}

	int numEven(const intvec& v1)
	{
		int result{0};

		for (const auto &elem : v1)
		{
			if (elem % 2 == 0)
			{
				++result;
			}
		}
		return result;
	}

	/*
	intvec& operator+=(const intvec& v2)
	{
		for (const auto& elem : v2)
		{
			*this.push_back(elem);
		}

		return *this;
	}

	intvec operator+(intvec const& v1, intvec const& v2)
	{
		auto result = makeVector(6);
		return result;
	}*/



} //tp1

