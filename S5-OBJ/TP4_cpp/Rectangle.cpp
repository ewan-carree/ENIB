#include "Rectangle.hpp"

namespace tp3
{

    Rectangle::Rectangle(int win_height, int win_width, double x, double y, double sx, double sy, double rec_width, double rec_height, Color color, double angularSpeed) :
    tp4::Shape{std::clamp(x, 0., win_width-rec_width), std::clamp(y, 0., win_height-rec_height), sx, sy, std::move(color)}, 
    width_{rec_width}, 
    height_{rec_height}, 
    angularSpeed_{angularSpeed}, 
    angle_{0.} { } 

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
        tp4::Shape::move(width, height, dt);
        angle(angle_ + angularSpeed_*dt);
    }


    void Rectangle::draw(sf::RenderWindow& win) const
        {
        auto [w, h] = size();  
        sf::RectangleShape s{sf::Vector2f{(float)w, (float)h}};  

        auto c = color(); 
        s.setFillColor(sf::Color{c[0], c[1], c[2]}); 

        s.setOrigin(0., 0.); 

        auto [x, y] = position(); 
        s.setPosition(float(x), float(y));   
        s.setRotation(float(angle())); 

        win.draw(s);
        }

    double Rectangle::boundingSphere() const
    {
        double hypothenus = sqrt(pow(width_, 2) + pow(height_, 2));
        return hypothenus/2;
    }


} //tp3
