#ifndef BRAKE_HPP
#define BRAKE_HPP

#include "utils.hpp"
#include <iostream>

class Brake {
private:
public:
  Brake() {}
  ~Brake() {}

  void applyForce(float &speed, float force) {
    speed *= (1 - clamp(force, 0.0f, 1.0f));
    std::cout << "Break with force: " << force << std::endl;
  }
  void applyEmergencyForce(float &speed) { applyForce(speed, 1.0f); }
};

#endif // BRAKE_HPP
