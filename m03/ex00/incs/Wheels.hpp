#ifndef WHEELS_HPP
#define WHEELS_HPP

#include "utils.hpp"
#include <iostream>

class Wheels {
private:
  float _angle;

public:
  Wheels() : _angle(0.0f) {}
  void turn(float angle) {
    _angle += clamp(angle, -45.0f, 45.0f);
    std::cout << "Wheels angle is now: " << _angle << std::endl;
  }
  void straighten() {
    _angle = 0.0f;
    std::cout << "Put wheels straight" << std::endl;
  }
};

#endif // WHEELS_HPP
