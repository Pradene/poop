#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "Vector2.hpp"
#include <exception>
#include <iomanip>
#include <iostream>
#include <vector>

class Graph {
public:
  class InvalidDimensionException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Invalid dimension"; }
  };

  class InvalidPositionException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Invalid position"; }
  };

  Graph(float width, float height);

  void addPoint(const Vector2 &point);

  void display(std::ostream &os) const;

private:
  std::vector<Vector2> _points;
  int _width;
  int _height;

  bool hasPointAt(int x, int y) const;

  friend std::ostream &operator<<(std::ostream &os, const Graph &graph);
};

#endif
