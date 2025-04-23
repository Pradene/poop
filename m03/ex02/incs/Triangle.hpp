#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Shape.hpp"
#include "Point.hpp"

class Triangle: public Shape {
private:
    Point _a;
    Point _b;
    Point _c;

public:
    Triangle(Point a, Point b, Point c): _a(a), _b(b), _c(c) {}
    ~Triangle() {}

    float area() const {
        return 0.5f * fabs((_b._x - _a._x)*(_c._y - _a._y) - (_c._x - _a._x)*(_b._y - _a._y));
    }
};


#endif // TRIANGLE_HPP