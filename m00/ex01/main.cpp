#include "Graph.hpp"
#include <exception>
#include <iostream>

int main() {
  try {
    std::cout << "Small Graph (6x6):" << std::endl;
    Graph smallGraph(6, 6);
    smallGraph.addPoint(Vector2(0, 0));
    smallGraph.addPoint(Vector2(2, 2));
    smallGraph.addPoint(Vector2(2, 4));
    smallGraph.addPoint(Vector2(4, 2));
    std::cout << smallGraph << std::endl;

    std::cout << "Larger Graph (15x12):" << std::endl;
    Graph largeGraph(15, 12);
    largeGraph.addPoint(Vector2(0, 0));
    largeGraph.addPoint(Vector2(5, 5));
    largeGraph.addPoint(Vector2(10, 10));
    largeGraph.addPoint(Vector2(14, 11));
    largeGraph.addPoint(Vector2(7, 3));
    std::cout << largeGraph;
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  return 0;
}
