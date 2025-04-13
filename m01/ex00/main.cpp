#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

class Workshop;
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

public:
  Tool() : _numberOfUses(0) {}
  virtual ~Tool() {}
  virtual void use() = 0;
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

class ToolRegistry {
private:
  std::map<Tool *, Worker *> _toolOwnership;

  // Singleton pattern
  static ToolRegistry *_instance;
  ToolRegistry() {}

public:
  static ToolRegistry *getInstance() {
    if (_instance == NULL) {
      _instance = new ToolRegistry();
    }
    return _instance;
  }

  Worker *getOwner(Tool *tool) {
    if (_toolOwnership.find(tool) != _toolOwnership.end()) {
      return _toolOwnership[tool];
    }
    return NULL;
  }

  void registerOwnership(Tool *tool, Worker *worker) {
    _toolOwnership[tool] = worker;
  }

  void removeOwnership(Tool *tool) { _toolOwnership.erase(tool); }
};

ToolRegistry *ToolRegistry::_instance = NULL;

class Worker {
private:
  Position _position;
  Statistic _statistic;
  std::vector<Tool *> _tools;
  std::vector<Workshop *> _workshop;

public:
  Worker() {}
  ~Worker() {}

  const std::vector<Tool *> &getTools() const { return _tools; }

  void removeTool(Tool *tool) {
    std::vector<Tool *>::iterator it =
        std::find(_tools.begin(), _tools.end(), tool);
    if (it == _tools.end()) {
      return;
    }
    ToolRegistry::getInstance()->removeOwnership(tool);
    _tools.erase(it);
  }

  void addTool(Tool *tool) {
    Worker *currentOwner = ToolRegistry::getInstance()->getOwner(tool);
    if (currentOwner != NULL && currentOwner != this) {
      currentOwner->removeTool(tool);
    }

    ToolRegistry::getInstance()->registerOwnership(tool, this);
    _tools.push_back(tool);
  }

  void addWorkshop(Workshop *workshop) { _workshop.push_back(workshop); }

  void removeWorkshop(Workshop *workshop) {
    std::vector<Workshop *>::iterator it =
        std::find(_workshop.begin(), _workshop.end(), workshop);
    if (it == _workshop.end()) {
      return;
    }
    _workshop.erase(it);
  }

  void useTools() {
    for (std::vector<Tool *>::iterator it = _tools.begin(); it != _tools.end();
         ++it) {
      (*it)->use();
    }
  }

  template <typename ToolType> ToolType *getTool() const {
    for (std::vector<Tool *>::const_iterator it = _tools.begin();
         it != _tools.end(); ++it) {
      ToolType *tool = dynamic_cast<ToolType *>(*it);
      if (tool != NULL) {
        return tool;
      }
    }
    return NULL;
  }

  void work() {}
};

class Workshop {
private:
  std::vector<Worker *> _workers;

public:
  Workshop() {}
  ~Workshop() {}

  void addWorker(Worker *worker) {
    worker->addWorkshop(this);
    _workers.push_back(worker);
  }

  void removeWorker(Worker *worker) {
    std::vector<Worker *>::iterator it =
        std::find(_workers.begin(), _workers.end(), worker);
    if (it == _workers.end()) {
      return;
    }
    worker->removeWorkshop(this);
    _workers.erase(it);
  }

  void executeWorkDay() {
    for (std::vector<Worker *>::iterator it = _workers.begin();
         it != _workers.end(); ++it) {
      (*it)->work();
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
  std::cout << worker1.getTool<Hammer>() << std::endl;

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
