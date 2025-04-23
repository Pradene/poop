#ifndef WORKSHOP_HPP
#define WORKSHOP_HPP

#include <vector>

class Worker;

class Workshop {
private:
  std::vector<Worker *> _workers;

public:
  Workshop();
  ~Workshop();

  void addWorker(Worker *worker);
  void removeWorker(Worker *worker);
  void executeWorkday();
};

#endif // WORKSHOP_HPP
