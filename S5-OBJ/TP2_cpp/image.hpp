#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <vector>
#include <string.h>
#include <stdexcept> //runtime_error
#include <iostream>
#include <utility> // std::move()
#include <random>
#include <fstream>

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
		Image(std::string path);

		Image() = default;    // constructeur par défaut
		Image(const Image&) = delete;
		Image(Image&&) = default;
		Image& operator=(const Image&) = delete;
		Image& operator=(Image&&) = default;
		~Image() = default;

		Color operator[](int i) const;

		std::string name() const;
		int width() const;
		int height() const;

		
	};

	inline std::string Image::name() const {return name_;}
	inline int Image::width() const {return width_;}
	inline int Image::height() const {return height_;}

	inline int size(const Image &img) { return img.width()*img.height();}

	inline Color Image::operator[](int i) const 
	{
		if(i<width_*height_) return pixels_[i];
		else throw std::out_of_range("out of range");
	}

	std::ostream& operator<<(std::ostream& os, const Image& i1);

	std::string imageName(std::string path);

	void save(const Image& i1);

} //tp2
#endif //IMAGE_HPP