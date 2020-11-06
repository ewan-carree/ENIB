//////////////////////////////////
//	Prog.cpp
//	2020-11-06 14:49:50.292837
//	carree
//////////////////////////////////

#include "color.hpp"
#include "image.hpp"

void test_color()
{
	tp2::Color c1;
	tp2::Color red{255,0,0};

	c1[1] = 165;
	tp2::Color g = grey(red); // We use adl to call grey thanks to to type of red.
	const tp2::Color noir;
	std::cout << c1 << std::endl;
	std::cout << red << std::endl;
	std::cout << g << std::endl;
	std::cout << noir[1] << std::endl;


}


int main(int argc, char const *argv[])
{
	test_color();
	return 0;
}
