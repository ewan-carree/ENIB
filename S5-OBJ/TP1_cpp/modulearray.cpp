#include "modulearray.hpp"

namespace tp1
{

	void fillArray(str15& a1)
	{
		std::cout << "We modify the string table" << std::endl;
		std::default_random_engine rndGen{std::random_device{}()};
		std::uniform_int_distribution<int> lengthDistrib{3, 6};
		std::uniform_int_distribution<char> charDistrib{'a', 'e'};

		for (int i = 0; i < int(a1.size()); ++i)
		{
			std::string word;
			for (int i = 0; i < lengthDistrib(rndGen); ++i)
			{
				word += charDistrib(rndGen);
			}

			a1[i] = word;
		}
	}

	void printArray(const str15& a1)
	{
		if (a1[0].size() != 0)
		{
			std::cout << "Table of string : ";
			for (const auto &elem: a1)
			{
				std::cout << elem << " ";
			}
			std::cout << std::endl;
		}
		else
		{
			std::cout << "Table of string is empty!" << std::endl;
		}

	}

	bool isPalindrome(const std::string s1)
	{
		if (s1.size() == 0)
		{
			return true;
		}

		for (int i = 0; i < int(s1.size()/2); ++i)
		{
			if (s1[i] != s1[s1.size() - 1 - i])
			{
				return false;
			}
		}

		return true;
	}



} //tp1
