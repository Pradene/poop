#ifndef SHAPE_HPP
#define SHAPE_HPP

#define _USE_MATH_DEFINES

#include <cmath>

class Shape {
public:
    virtual ~Shape() {}
    virtual float area() const = 0;
};

#endif // SHAPE_HPP