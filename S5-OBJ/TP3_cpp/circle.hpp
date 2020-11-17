#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <vector>
#include <string>
#include <stdexcept> //runtime_error
#include <iostream>
#include <utility> // std::move()
#include <tuple>

#include "color.hpp"
#include "SFML/Graphics.hpp"


namespace tp3
{
	class Circle
	{
		private:
		double x_, y_;
		double sx_, sy_;
		double radius_;
		Color color_;

		public:
		//Circle() : Circle(/* parameters */) { }
		Circle(int height, int width, double x, double y, double sx, double sy, double radius, Color color);

		Circle(const Circle &) = default; //constructeur par recopie
		Circle(Circle &&) = default; //constructeur par déplacement
		Circle& operator=(const Circle &) = default; //affectation par recopie
		Circle& operator=(Circle &&) = default; //affectation par déplacement
		~Circle() = default; //destructeur

		std::tuple<double, double> position() const {return {std::move(x_), std::move(y_)};}
		double radius() const {return radius_;}
		Color color() const {return color_;}

		void move(double width, double height, double dt);
	};


	inline std::ostream& operator<<(std::ostream& os, const Circle& c)
	{
		const auto [x, y] = c.position();
		os << "Position : " << x << ',' << y << std::endl;
		return os;
	}

	void draw(const Circle& c1, sf::RenderWindow& window);


} //tp3
#endif //CIRCLE_HPP