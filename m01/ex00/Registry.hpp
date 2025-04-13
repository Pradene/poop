#ifndef TOOL_REGISTRY_HPP
#define TOOL_REGISTRY_HPP

#include <map>

class Tool;
class Worker;

class ToolRegistry {
private:
  std::map<Tool *, Worker *> _toolOwnership;
  static ToolRegistry *_instance;
  ToolRegistry();

public:
  static ToolRegistry *getInstance();
  Worker *getOwner(Tool *tool);
  void registerOwnership(Tool *tool, Worker *worker);
  void removeOwnership(Tool *tool);
};

#endif // TOOL_REGISTRY_HPP
