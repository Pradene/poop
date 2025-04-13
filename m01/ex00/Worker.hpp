#ifndef WORKER_HPP
#define WORKER_HPP

#include "Tool.hpp"
#include <vector>

class Workshop;

struct Position {
  int _x;
  int _y;
  int _z;
};

struct Statistic {
  int _level;
  int _exp;
};

class Worker {
private:
  Position _position;
  Statistic _statistic;
  std::vector<Tool *> _tools;
  std::vector<Workshop *> _workshop;

public:
  Worker();
  ~Worker();

  const std::vector<Tool *> &getTools() const;
  void removeTool(Tool *tool);
  void addTool(Tool *tool);
  void addWorkshop(Workshop *workshop);
  void removeWorkshop(Workshop *workshop);
  void useTools();
  void work();

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
};

#endif // WORKER_HPP
