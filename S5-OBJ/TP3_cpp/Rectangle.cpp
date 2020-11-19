#include "Rectangle.hpp"

namespace tp3
{

    Rectangle::Rectangle(int win_height, int win_width, double x, double y, double sx, double sy, double rec_width, double rec_height, Color color, double angularSpeed) : 
    x_{std::clamp(x, 0., win_width-rec_width)}, 
    y_{std::clamp(y, 0., win_height-rec_height)}, 
    sx_{sx}, sy_{sy}, width_{rec_width}, height_{rec_height}, color_{std::move(color)}, angularSpeed_{angularSpeed}, angle_{0.} { } 

    void Rectangle::angle(double new_angle)
    {
        if (new_angle > -180. && new_angle < 180.)
        {
            angle_ = new_angle;
        }
        else if (new_angle < -180.)
        {
            angle_ = new_angle + 360.;
        }
        else
        {
            angle_ = new_angle - 360.;
        }
    }

    void Rectangle::move(double width, double height, double dt)
    {
        x_ = x_ + sx_*dt; 
        y_ = y_ + sy_*dt;

        angle(angle_ + angularSpeed_*dt);

        if (x_ < 0. || x_ > width-width_)
        {
            sx_ = -sx_;
        }
        if (y_ < 0. || y_ > height-height_)
        {
            sy_ = -sy_;
        }
    }

    void draw(const Rectangle& r1, sf::RenderWindow& win)
        {
        auto [w, h] = r1.size();  
        sf::RectangleShape s{sf::Vector2f{(float)w, (float)h}};  

        auto c = r1.color(); 
        s.setFillColor(sf::Color{c[0], c[1], c[2]}); 

        s.setOrigin(0., 0.); 

        auto [x, y] = r1.position(); 
        s.setPosition(float(x), float(y));   
        s.setRotation(float(r1.angle())); 

        win.draw(s);
        }

} //tp3
