#include "circle.hpp"

namespace tp3
{
    Circle::Circle(int height, int width, double x, double y, double sx, double sy, double radius, Color color) : 
    tp4::Shape(std::clamp(x, radius, width-radius), std::clamp(y, radius, height-radius), sx, sy, std::move(color)), 
    radius_{radius} { } 

/*
    void draw(const Circle& circ, sf::RenderWindow& win)
        {
            const auto r = (float)circ.radius();
            sf::CircleShape s{r};

            const Color& c = circ.color();
            s.setFillColor(sf::Color(c[0], c[1], c[2]));
            s.setOrigin(r, r);
            auto [x, y] = circ.position();
            s.setPosition(float(x),float(y));
            win.draw(s); 
        }
*/
} //tp3

