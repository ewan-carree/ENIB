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
#include <cmath>

#include "color.hpp"
#include "shape.hpp"

namespace tp3
{
	class Rectangle final : public tp4::Shape
	{
		private:
		double width_, height_;
		double angularSpeed_, angle_;

		void angle(double new_angle);

		public:
		Rectangle() = default;
		Rectangle(int win_height, int win_width, double x, double y, double sx, double sy, double rec_width, double rec_height, Color color, double angularSpeed = 0.0);

		std::tuple<double,double> size() const;
		double angle() const;

		void move(double width, double height, double dt) override;

		void draw(sf::RenderWindow& win) const override;
		double boundingSphere() const override;
	};

	inline std::tuple<double,double> Rectangle::size() const {return {width_, height_};}
	inline double Rectangle::angle() const {return angle_;}

	

/*
	inline std::ostream& operator<<(std::ostream& os, const Rectangle& r)
	{
		os <<;
		return os;
	}
*/

} //tp3
#endif //RECTANGLE_HPP