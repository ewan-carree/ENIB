//////////////////////////////////
//	Prog.cpp
//	2020-25-05
//	ewan carree
//////////////////////////////////

#include "generic.hpp"

void test_generic()
{
	std::cout << "~~~~" << __func__ << "~~~~" << std::endl;
	exam::MinMax v1{3.6,18.2};
	exam::MinMax v2{-11,11};

	double valeur1 = 1.8;
	int valeur2 = 2;
	std::vector<double> resultv1 = v1.generate(v1,std::move(valeur1));
	std::vector<int> resultv2 = v2.generate(v2,std::move(valeur2));

	const auto show=[&](const auto &seq)
	{
	  for(const auto &e: seq)
	  {
	    std::cout << e << ' ';
	  }
	  std::cout << '\n';
	};

	show(resultv1);
	show(resultv2);

	//std::vector<double> result = v1.extract_right(resultv1,10.9);
	//show(result);



}



int main(int argc, char const *argv[])
{
	test_generic();
	return 0;
}