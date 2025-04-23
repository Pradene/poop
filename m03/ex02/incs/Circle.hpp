#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Shape.hpp"

class Circle: public Shape {
private:
    float _radius;

public:
    Circle(float radius): _radius(radius) {}
    ~Circle() {}

    float area() const {
        return M_PI * powf(_radius, 2.0f);
    }

    float perimeter() const {
        return 2.0f * M_PI * _radius;
    }
};


#endif // CIRCLE_HPP