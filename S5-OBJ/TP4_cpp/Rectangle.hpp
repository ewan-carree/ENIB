#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <vector>
#include <string>
#include <stdexcept> //runtime_error
#include <iostream>
#include <utility> // std::move()
#include "SFML/Graphics.hpp"
#include <tuple>
#include <exception>

#include "color.hpp"
#include "shape.hpp"

namespace tp3
{
	class Rectangle : public tp4::Shape
	{
		private:
		double width_, height_;
		double angularSpeed_, angle_;

		void angle(double new_angle);

		public:
		Rectangle(int win_height, int win_width, double x, double y, double sx, double sy, double rec_width, double rec_height, Color color, double angularSpeed = 0.0);

		Rectangle(const Rectangle &) = default; //constructeur par recopie
		Rectangle(Rectangle &&) = default; //constructeur par déplacement
		Rectangle& operator=(const Rectangle &) = default; //affectation par recopie
		Rectangle& operator=(Rectangle &&) = default; //affectation par déplacement
		~Rectangle() = default; //destructeur

		std::tuple<double,double> size() const;
		double angle() const;
	};

	inline std::tuple<double,double> Rectangle::size() const {return {width_, height_};}
	inline double Rectangle::angle() const {return angle_;}

//	void draw(const Rectangle& r1, sf::RenderWindow& window);

/*
	inline std::ostream& operator<<(std::ostream& os, const Rectangle& r)
	{
		os <<;
		return os;
	}
*/

} //tp3
#endif //RECTANGLE_HPP