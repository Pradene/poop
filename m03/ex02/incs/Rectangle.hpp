#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Shape.hpp"

class Rectangle: public Shape {
private:
    float _width;
    float _height;

public:
    Rectangle(float width, float height): _width(width), _height(height) {}
    ~Rectangle() {}

    float area() const {
        return _width * _height;
    }

    float perimeter() const {
        return (_width + _height) * 2.0f;
    }
};


#endif // RECTANGLE_HPP