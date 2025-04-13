#include "Worker.hpp"
#include "Registry.hpp"
#include <algorithm>

Worker::Worker() {}
Worker::~Worker() {}

const std::vector<Tool *> &Worker::getTools() const { return _tools; }

void Worker::removeTool(Tool *tool) {
  std::vector<Tool *>::iterator it =
      std::find(_tools.begin(), _tools.end(), tool);
  if (it == _tools.end()) {
    return;
  }
  ToolRegistry::getInstance()->removeOwnership(tool);
  _tools.erase(it);
}

void Worker::addTool(Tool *tool) {
  Worker *currentOwner = ToolRegistry::getInstance()->getOwner(tool);
  if (currentOwner != NULL && currentOwner != this) {
    currentOwner->removeTool(tool);
  }

  ToolRegistry::getInstance()->registerOwnership(tool, this);
  _tools.push_back(tool);
}

void Worker::addWorkshop(Workshop *workshop) { _workshop.push_back(workshop); }

void Worker::removeWorkshop(Workshop *workshop) {
  std::vector<Workshop *>::iterator it =
      std::find(_workshop.begin(), _workshop.end(), workshop);
  if (it == _workshop.end()) {
    return;
  }
  _workshop.erase(it);
}

void Worker::useTools() {
  for (std::vector<Tool *>::iterator it = _tools.begin(); it != _tools.end();
       ++it) {
    (*it)->use();
  }
}

void Worker::work() {}
