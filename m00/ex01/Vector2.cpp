#include "Vector2.hpp"

Vector2::Vector2(float x, float y) : _x(x), _y(y) {}

float Vector2::getX() const { return _x; }
float Vector2::getY() const { return _y; }

int Vector2::getIntX() const { return static_cast<int>(_x); }
int Vector2::getIntY() const { return static_cast<int>(_y); }
