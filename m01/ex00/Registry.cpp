#include "Registry.hpp"
#include "Worker.hpp"

ToolRegistry *ToolRegistry::_instance = NULL;

ToolRegistry::ToolRegistry() {}

ToolRegistry *ToolRegistry::getInstance() {
  if (_instance == NULL) {
    _instance = new ToolRegistry();
  }
  return _instance;
}

Worker *ToolRegistry::getOwner(Tool *tool) {
  if (_toolOwnership.find(tool) != _toolOwnership.end()) {
    return _toolOwnership[tool];
  }
  return NULL;
}

void ToolRegistry::registerOwnership(Tool *tool, Worker *worker) {
  _toolOwnership[tool] = worker;
}

void ToolRegistry::removeOwnership(Tool *tool) { _toolOwnership.erase(tool); }
