#include "modulevector.hpp"

namespace tp1
{

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

		double average{0.};
		for (const auto &elem : v1)
		{
			average += elem;
		}
		average /= int(v1.size());

		double standard_deviation{0.};
		for (const auto& elem : v1)
		{
			standard_deviation += (elem - average) * (elem - average);
		}
		standard_deviation /= (int(v1.size())+1);




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

		return {std::move(average), std::move(standard_deviation), std::move(median)};
	}



} //tp1

