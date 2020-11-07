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

void test_simple_image()
{
	tp2::Image img1{"random",5,3};
	tp2::Image img2{"black",3,4,false};

	//std::cout << img1 << std::endl;
	//std::cout << img2 << std::endl;
}


int main(int argc, char const *argv[])
{
	if (argc > 1)
	{
		if (strcmp(argv[1], "color") == 0)
		{
			test_color();
		}

		else if (strcmp(argv[1], "simple_image") == 0)
		{
			test_simple_image();
		}

		else
		{
			std::cerr << "You didn't enter a correct test" << std::endl;
		}
	}

	else
	{
		std::cerr << "Precise the test you want to do" << std::endl;
	}

	return 0;
}
