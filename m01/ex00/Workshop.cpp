#include "Workshop.hpp"
#include "Worker.hpp"
#include <algorithm>

Workshop::Workshop() {}
Workshop::~Workshop() {}

void Workshop::addWorker(Worker *worker) {
  worker->addWorkshop(this);
  _workers.push_back(worker);
}

void Workshop::removeWorker(Worker *worker) {
  std::vector<Worker *>::iterator it =
      std::find(_workers.begin(), _workers.end(), worker);
  if (it == _workers.end()) {
    return;
  }
  worker->removeWorkshop(this);
  _workers.erase(it);
}

void Workshop::executeWorkDay() {
  for (std::vector<Worker *>::iterator it = _workers.begin();
       it != _workers.end(); ++it) {
    (*it)->work();
  }
}
