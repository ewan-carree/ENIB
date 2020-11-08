#include "image.hpp"

namespace tp2
{
	Image::Image(std::string name, int width, int height, bool rdmPix) : name_{name}, width_{width}, height_{height}, pixels_{}
	{
		int size = height*width;
		//pixels_.resize(size);

		if (!rdmPix)
		{
			for (int i = 0; i < size; ++i)
			{
				pixels_.push_back(Color());
			}
		}

		else
		{
			std::default_random_engine rndGen{std::random_device{}()};
			std::uniform_int_distribution<int> component{0, 255};
			for (int i = 0; i < size; ++i)
			{
				pixels_.push_back(Color(uchar(component(rndGen)), uchar(component(rndGen)), uchar(component(rndGen))));
			}
			
		}
	}

	std::ostream& operator<<(std::ostream& os, const Image& i1)
	{
		os << i1.name() << std::endl << i1.width() << ' ' << i1.height() << std::endl;
		for (int i = 0; i < size(i1); i++)
		{
			os << i1[i] << std::endl;
		}

		return os;
	}

} //tp2
