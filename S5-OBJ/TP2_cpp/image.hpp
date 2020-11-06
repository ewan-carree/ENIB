#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <vector>
#include <string>
#include <stdexcept> //runtime_error
#include <iostream>
#include <utility> // std::move()
#include <color.hpp>

namespace tp2
{
	using colvec = std::std::vector<Color>;

	class Image
	{
		private:
		std::string name_;
		int width_, height_;
		colvec pixels_;

		public:

		
	};
} //tp2
#endif //IMAGE_HPP