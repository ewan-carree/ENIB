#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <vector>
#include <string.h>
#include <stdexcept> //runtime_error
#include <iostream>
#include <utility> // std::move()
#include <random>

#include "color.hpp"

namespace tp2
{
	using colvec = std::vector<Color>;

	class Image
	{
		private:
		std::string name_;
		int width_, height_;
		colvec pixels_;

		public:
		Image(std::string name, int width, int height, bool rdmPix = true);

		Image() = default;    // constructeur par défaut
		Image(const Image&) = delete;
		Image(Image&&) = default;
		Image& operator=(const Image&) = delete;
		Image& operator=(Image&&) = default;
		~Image() = default;

		
	};

	/*inline std::ostream& operator<<(std::ostream& os, const Image& i1)
	{
		os << i1.name_ << std::endl << i1.width_ << ' ' << i1.height_ << std::endl;
		for (const auto& pixel : i1.pixels_)
		{
			os << pixel << std::endl;
		}

		return os;*/
	}
} //tp2
#endif //IMAGE_HPP