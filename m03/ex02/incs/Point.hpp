#ifndef POINT_HPP
#define POINT_HPP

struct Point {
    float _x;
    float _y;

    Point(float x, float y): _x(x), _y(y) {}

    float distanceTo(const Point& other) const {
        return sqrtf(powf(other._x - _x, 2.0f) + powf(other._y - _y, 2.0f));
    }
};

#endif // POINT_HPP