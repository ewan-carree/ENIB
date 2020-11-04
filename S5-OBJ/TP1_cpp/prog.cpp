//////////////////////////////////
//	Prog.cpp
//	2020-11-02 10:10:34.714876
//	carree
//////////////////////////////////

#include "modulearray.hpp"
#include "modulevector.hpp"
#include <exception>

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

void test_vector(const std::string& s1)
{
	try
	{
		int extracted_int = std::stoi(s1);
		std::cout << extracted_int << std::endl;
	}	
	catch(const std::invalid_argument &e)
    	{
      		std::cerr << "<" << s1 << "> does not look like an integer!" << std::endl;
    	}
    	catch(const std::exception &e)
    	{
      		std::cerr << "integer conversion failure on <" << s1 << ">: " << e.what() << ". You must enter an integer";
      		std::exit(0);
    	}

	auto v1 = tp1::makeVector(6);
	tp1::printVector(v1);
	auto [average, standard_deviation, median] = tp1::dataVector(v1);
	std::cout << "average : " << average << ", standard_deviation : " << standard_deviation << ", median : " << median << std::endl;
}


int main(int argc, char const *argv[])
{
	std::cout << argv[1] << std::endl;
	
	std::cout << "~~~~~~" << __func__ << "~~~~~~" << std::endl;

	if (strcmp(argv[1], "array") == 0)
	{
		test_array();
	}

	else if (strcmp(argv[1], "vector") == 0)
	{
		test_vector(argv[2]);
	}

	else
	{
		std::cerr << "Precise the test you want to do" << std::endl;
	}
	

	std::cout << "\n~~~~~~" << __func__ << "~~~~~~" << std::endl;

	return 0;
}



