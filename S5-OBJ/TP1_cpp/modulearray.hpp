#ifndef MODULEARRAY_HPP
#define MODULEARRAY_HPP

#include <array>
#include <vector>
#include <string>
#include <stdexcept> //runtime_error
#include <iostream>
#include <utility> // std::move()

namespace tp1
{
	using str15 =  std::array<std::string, 15>;

	void fillArray(str15& a1);
	void printArray(const str15& a1);
	bool isPalindrome(const std::string s1);

} //tp1c
#endif //MODULEARRAY_HPP