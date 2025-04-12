#include <iostream>

class Worker;
class Tool;
class Shovel;
class Hammer;

struct Position {
  int _x;
  int _y;
  int _z;
};

struct Statistic {
  int _level;
  int _exp;
};

class Tool {
protected:
  size_t _numberOfUses;
  Worker *_owner;

public:
  Tool() : _numberOfUses(0), _owner(NULL) {}
  virtual ~Tool() {}
  virtual void use() = 0;

  Worker *getOwner() const { return _owner; }
  void setOwner(Worker *owner) { _owner = owner; }
};

class Shovel : public Tool {
public:
  Shovel() {}
  ~Shovel() {}

  void use() {
    _numberOfUses += 1;
    std::cout << "Use shovel" << std::endl;
  }
};

class Hammer : public Tool {
public:
  Hammer() {}
  ~Hammer() {}

  void use() {
    _numberOfUses += 1;
    std::cout << "Use hammer" << std::endl;
  }
};

class Worker {
private:
  Position _position;
  Statistic _statistic;
  Tool *_tool;

public:
  Worker() {}
  ~Worker() {}

  Tool *getTool() { return _tool; }
  void removeTool() { _tool = NULL; }
  void addTool(Tool *tool) {
    Worker *owner = tool->getOwner();
    if (owner != NULL) {
      owner->removeTool();
    }

    _tool = tool;
    _tool->setOwner(this);
  }
  void useTool() {
    if (_tool == NULL) {
      return;
    }
    _tool->use();
  }
};

int main() {
  Worker worker1 = Worker();
  Worker worker2 = Worker();
  Shovel shovel = Shovel();
  Hammer hammer = Hammer();

  worker1.addTool(&shovel);
  std::cout << worker1.getTool() << std::endl;
  worker1.useTool();
  worker2.addTool(&shovel);
  std::cout << worker1.getTool() << std::endl;
  worker1.addTool(&hammer);
  std::cout << worker1.getTool() << std::endl;

  return 0;
}
