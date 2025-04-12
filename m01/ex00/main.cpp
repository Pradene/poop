#include <iostream>

class Worker;
class Shovel;

struct Position {
  int _x;
  int _y;
  int _z;
};

struct Statistic {
  int _level;
  int _exp;
};

class Shovel {
private:
  size_t _numberOfUses;
  Worker *_owner;

public:
  Shovel() : _numberOfUses(0), _owner(NULL) {}
  ~Shovel() {}

  void use() { _numberOfUses += 1; }
  Worker *getOwner() const { return _owner; }
  void setOwner(Worker *owner) { _owner = owner; }
};

class Worker {
private:
  Position _position;
  Statistic _statistic;
  Shovel *_shovel;

public:
  Worker() {}
  ~Worker() {}

  Shovel *getShovel() { return _shovel; }
  void removeShovel() { _shovel = NULL; }
  void addShovel(Shovel *shovel) {
    Worker *owner = shovel->getOwner();
    if (owner != NULL) {
      owner->removeShovel();
    }

    _shovel = shovel;
    _shovel->setOwner(this);
  }
};

int main() {
  Worker worker1 = Worker();
  Worker worker2 = Worker();
  Shovel shovel = Shovel();

  worker1.addShovel(&shovel);
  std::cout << worker1.getShovel() << std::endl;
  worker2.addShovel(&shovel);
  std::cout << worker1.getShovel() << std::endl;

  return 0;
}
