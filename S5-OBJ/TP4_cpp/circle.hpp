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
#include "shape.hpp"


namespace tp3
{
	class Circle : public tp4::Shape
	{
		private:
		double radius_;

		public:
		Circle(int height, int width, double x, double y, double sx, double sy, double radius, Color color);

		Circle(const Circle &) = default; //constructeur par recopie
		Circle(Circle &&) = default; //constructeur par déplacement
		Circle& operator=(const Circle &) = default; //affectation par recopie
		Circle& operator=(Circle &&) = default; //affectation par déplacement
		virtual ~Circle() = default; //destructeur

		double radius() const {return radius_;}
	};

/*
	inline std::ostream& operator<<(std::ostream& os, const Circle& c)
	{
		const auto [x, y] = c.position();
		os << "Position : " << x << ',' << y << std::endl;
		return os;
	}*/

	void draw(const Circle& c1, sf::RenderWindow& window);


} //tp3
#endif //CIRCLE_HPP