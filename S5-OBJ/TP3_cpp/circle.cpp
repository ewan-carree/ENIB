#include "circle.hpp"

namespace tp3
{
    Circle::Circle(int height, int width, double x, double y, double sx, double sy, double radius, Color color) : 
    x_{std::clamp(x, radius, width-radius)}, 
    y_{std::clamp(y, radius, height-radius)}, 
    sx_{sx}, sy_{sy}, radius_{radius}, color_{std::move(color)} { } 

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
    
    void Circle::move(double width, double height, double dt)
    {
        x_ = x_ + sx_*dt; 
        y_ = y_ + sy_*dt;

        if (x_ < radius_ || x_ > width-radius_)
        {
            sx_ = -sx_;
            sy_ = 0.;
        }
        if (y_ < radius_ || y_ > height-radius_)
        {
            sy_ = -sy_;
            sx_ = 0.;
        }
    }

} //tp3


