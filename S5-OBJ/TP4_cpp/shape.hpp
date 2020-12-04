#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <vector>
#include <string>
#include <stdexcept> //runtime_error
#include <iostream>
#include <utility> // std::move()
#include <tuple>

#include "color.hpp"

namespace tp4
{
	class Shape
	{
		protected:
		double x_, y_;
		double sx_, sy_;
		tp3::Color color_;

		Shape(double x, double y, double sx, double sy, tp3::Color color) : x_{x}, y_{y}, sx_{sx}, sy_{sy}, color_{color} { }

		Shape(const Shape &) = delete; //constructeur par recopie
		Shape(Shape &&) = delete; //constructeur par déplacement
		Shape& operator=(const Shape &) = delete; //affectation par recopie
		Shape& operator=(Shape &&) = delete; //affectation par déplacement
		virtual ~Shape() = default; //destructeur

		public:
		std::tuple<double, double> position() const {return {std::move(x_), std::move(y_)};}
		tp3::Color color() const {return color_;}

		virtual void move(double width, double height, double dt);
		virtual void draw(sf::RenderWindow& win) = 0;
		
	};

	/*inline std::ostream& operator<<(std::ostream& os, const Shape& s)
	{
		os << ;
		return os;
	}*/
	
} //tp4
#endif //SHAPE_HPP