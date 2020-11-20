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

		//Shape() : Shape(/* parameters */) { }
		Shape(double x, double y, double sx, double sy, tp3::Color color) : x_{x}, y_{y}, sx_{sx}, sy_{sy}, color_{color} { }

		Shape(const Shape &) = default; //constructeur par recopie
		Shape(Shape &&) = default; //constructeur par déplacement
		Shape& operator=(const Shape &) = default; //affectation par recopie
		Shape& operator=(Shape &&) = default; //affectation par déplacement
		virtual ~Shape() = default; //destructeur

		public:
		std::tuple<double, double> position() const {return {std::move(x_), std::move(y_)};}
		tp3::Color color() const {return color_;}

		void move(double width, double height, double dt);

		
	};

	/*inline std::ostream& operator<<(std::ostream& os, const Shape& s)
	{
		os << ;
		return os;
	}*/
	
} //tp4
#endif //SHAPE_HPP