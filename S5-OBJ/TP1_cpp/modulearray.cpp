#include "modulearray.hpp"

namespace tp1
{

	void fillArray(str15& a1)
	{
		a1 = {"hi", "hello", "anna", "kayak", "21:12", "goodbye"};
	}

	void printArray(const str15& a1)
	{
		for (const auto &elem: a1)
		{
			std::cout << elem << " ";
		}
		std::cout << std::endl;
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
