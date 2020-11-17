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

namespace tp3
{
	class Rectangle
	{
		private:
		double x_, y_;
		double sx_, sy_;
		double width_, height_;
		Color color_;
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
		std::tuple<double, double> position() const;
		Color color() const;
		double angle() const;

		void move(double width, double height, double dt);
	};

	inline std::tuple<double,double> Rectangle::size() const {return {width_, height_};}
	inline std::tuple<double, double> Rectangle::position() const {return {std::move(x_), std::move(y_)};}
	inline Color Rectangle::color() const {return color_;}
	inline double Rectangle::angle() const {return angle_;}

	void draw(const Rectangle& r1, sf::RenderWindow& window);

/*
	inline std::ostream& operator<<(std::ostream& os, const Rectangle& r)
	{
		os <<;
		return os;
	}
*/

} //tp3
#endif //RECTANGLE_HPP