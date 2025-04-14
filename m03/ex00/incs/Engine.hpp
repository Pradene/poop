#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <iostream>

class Engine {
private:
  bool _started;

public:
  Engine() : _started(false) {}
  ~Engine() {}

  void start() { _started = true; }
  void stop() { _started = false; }
  void accelerate(float &speed, float acceleration) {
    if (_started == false) {
      speed = 0;
      std::cout << "Cannot accelerate car is not started" << std::endl;
    } else {
      speed += acceleration;
      std::cout << "Accelerate, speed is now: " << speed << std::endl;
    }
  }
};

#endif // ENGINE_HPP
