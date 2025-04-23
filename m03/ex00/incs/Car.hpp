#ifndef CAR_HPP
#define CAR_HPP

#include "Brake.hpp"
#include "Engine.hpp"
#include "Transmission.hpp"
#include "Wheels.hpp"

class Car {
private:
  Engine _engine;
  Brake _brake;
  float _speed;
  Transmission _transmission;
  Wheels _wheels;

public:
  Car() : _transmission(6) {}
  ~Car() {}

  void start() { _engine.start(); }
  void stop() { _engine.stop(); }
  void accelerate(float speed) { _engine.accelerate(_speed, speed); }
  void applyForce(float force) { _brake.applyForce(_speed, force); }
  void applyEmergencyForce() { _brake.applyEmergencyForce(_speed); }
  void shiftUp() { _transmission.shiftUp(); }
  void shiftDown() { _transmission.shiftDown(); }
  void reverse() { _transmission.reverse(); }
  void turnWheels(float angle) { _wheels.turn(angle); }
  void straighenWheels() { _wheels.straighten(); }
};

#endif // CAR_HPP
