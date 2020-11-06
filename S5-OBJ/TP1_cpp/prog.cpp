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

	std::cout << std::endl;

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
		std::cout << "Extracted int : " << extracted_int << std::endl;
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

	auto nb_even = tp1::numEven(v1);
	std::cout << "Number of even inside the int vector : " << nb_even << std::endl;

	auto [average, standard_deviation, median] = tp1::dataVector(v1);
	std::cout << "average : " << average << ", standard_deviation : " << standard_deviation << ", median : " << median << std::endl;
}

void test_operator()
{
	/*auto v1 = tp1::makeVector(6);
	auto v2 = tp1::makeVector(6);

	//v1 += v2;

	//auto v3 = v1 + v2;

	tp1::printVector(v3);*/
}


int main(int argc, char const *argv[])
{
	std::cout << "~~~~~~" << __func__ << "~~~~~~" << std::endl;

	if (argc > 1)
	{
		if (strcmp(argv[1], "array") == 0)
		{
			test_array();
		}

		else if (strcmp(argv[1], "vector") == 0)
		{
			if (argv[2])
			{
				test_vector(argv[2]);
			}
			else
			{
				test_vector("0");
			}
			
		}
		/*
		else if (strcmp(argv[1], "operator") == 0)
		{
			test_operator();
		}*/
	}

	else
	{
		std::cerr << "Precise the test you want to do" << std::endl;
	}
	

	std::cout << "\n~~~~~~" << __func__ << "~~~~~~" << std::endl;

	return 0;
}



