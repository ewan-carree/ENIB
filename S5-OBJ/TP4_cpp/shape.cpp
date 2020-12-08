#include "shape.hpp"

namespace tp4
{

    void Shape::move(double width, double height, double dt)
    {
        const auto radius = boundingSphere();
        x_ += sx_*dt;
        y_ += sy_*dt;
        if(x_-radius<0) { x_=radius; sx_=-sx_;}
        if(x_+radius>=width) {x_=width-radius; sx_=-sx_;}
        if(y_-radius<0) { y_=radius; sy_=-sy_;}
        if(y_+radius>=height) {y_=height-radius; sy_=-sy_;}
    }

} //tp4
