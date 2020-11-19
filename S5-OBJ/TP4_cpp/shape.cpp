#include "shape.hpp"

namespace tp4
{

    void Shape::move(double width, double height, double dt)
    {
        x_ = x_ + sx_*dt; 
        y_ = y_ + sy_*dt;
    }

} //tp4
