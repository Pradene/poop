#include "Tool.hpp"
#include "Worker.hpp"
#include <iostream>

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
