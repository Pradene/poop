#ifndef TRANSMISSION_HPP
#define TRANSMISSION_HPP

#include <iostream>

class Transmission {
private:
  int _gear;
  int _gearNumber;

public:
  Transmission(int gearNumber) : _gear(0), _gearNumber(gearNumber) {}
  void shiftUp() {
    if (_gear <= -1) {
      std::cout << "Cannot shift up from reverse. Shift to neutral first.\n";
      return;
    } else if (_gear >= _gearNumber) {
      std::cout << "Cannot shift up, max gear\n";
      return;
    } else {
      _gear++;
      std::cout << "Shifted up to gear " << _gear << std::endl;
    }
  }

  void shiftDown() {
    if (_gear > 0) {
      _gear--;
      std::cout << "Shifted down to gear " << _gear << std::endl;
    } else if (_gear == 0) {
      std::cout << "Already in neutral. Shift to reverse if needed.\n";
    } else {
      std::cout << "Already in reverse. Cannot shift down further.\n";
    }
  }

  void reverse() {
    if (_gear == 0) {
      _gear = -1;
      std::cout << "Shifted to reverse.\n";
    } else {
      std::cout << "Cannot shift to reverse unless in neutral.\n";
    }
  }
};

#endif // TRANSMISSION_HPP
