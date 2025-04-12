#include <algorithm>
#include <iostream>
#include <vector>

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
  std::vector<Tool *> _tools;

public:
  Worker() {}
  ~Worker() {}

  const std::vector<Tool *> &getTools() const { return _tools; }

  void removeTool(Tool *tool) {
    std::vector<Tool *>::iterator it =
        std::find(_tools.begin(), _tools.end(), tool);
    if (it != _tools.end()) {
      (*it)->setOwner(NULL);
      _tools.erase(it);
    }
  }

  void addTool(Tool *tool) {
    Worker *owner = tool->getOwner();
    if (owner != NULL) {
      owner->removeTool(tool);
    }

    _tools.push_back(tool);
    tool->setOwner(this);
  }

  void useTools() {
    for (std::vector<Tool *>::iterator it = _tools.begin(); it != _tools.end();
         ++it) {
      (*it)->use();
    }
  }
};

int main() {
  Worker worker1;
  Worker worker2;
  Shovel shovel;
  Hammer hammer;

  worker1.addTool(&shovel);
  worker1.addTool(&hammer);

  std::cout << "worker1 tools count: " << worker1.getTools().size()
            << std::endl;
  worker1.useTools();

  worker2.addTool(&shovel);

  std::cout << "worker1 tools count: " << worker1.getTools().size()
            << std::endl;
  std::cout << "worker2 tools count: " << worker2.getTools().size()
            << std::endl;

  return 0;
}
