#include "Graph.hpp"
#include <iomanip>
#include <iostream>
#include <vector>

Graph::Graph(float width, float height) {
  if (width <= 0.0f || height <= 0.0f) {
    throw InvalidDimensionException();
  }
  _width = static_cast<int>(width);
  _height = static_cast<int>(height);
}

void Graph::addPoint(const Vector2 &point) {
  if (point.getIntX() < 0 || point.getIntX() >= _width || point.getIntY() < 0 ||
      point.getIntY() >= _height) {
    throw InvalidPositionException();
  }
  _points.push_back(point);
}

// Helper function to calculate the number of digits in an integer
int getDigitCount(int number) {
  if (number == 0) {
    return 1;
  }

  int count = 0;
  while (number > 0) {
    ++count;
    number /= 10;
  }
  return count;
}

void Graph::display(std::ostream &os) const {
  int rowNumWidth = getDigitCount(_height - 1);
  int colNumWidth = getDigitCount(_width - 1);

  for (int y = _height - 1; y >= 0; --y) {
    os << "& " << std::setw(rowNumWidth) << y << " ";

    for (int x = 0; x < _width; ++x) {
      if (hasPointAt(x, y)) {
        os << "x";
      } else {
        os << ".";
      }

      os << std::string(colNumWidth, ' ');
    }
    os << std::endl;
  }

  os << "& " << std::string(rowNumWidth + 1, ' ');
  for (int x = 0; x < _width; ++x) {
    os << std::setw(colNumWidth) << x << " ";
  }
  os << std::endl;
}

bool Graph::hasPointAt(int x, int y) const {
  std::vector<Vector2>::const_iterator it;
  for (it = _points.begin(); it != _points.end(); ++it) {
    if (it->getIntX() == x && it->getIntY() == y) {
      return true;
    }
  }
  return false;
}

std::ostream &operator<<(std::ostream &os, const Graph &graph) {
  graph.display(os);
  return os;
}
