#include <iostream>
#include <vector>
#include <exception>
#include <string>
#include <sstream>
#include <iomanip>

class Vector2 {
  private:
    float _x;
    float _y;
  public:
    Vector2(float x = 0.0f, float y = 0.0f) : _x(x), _y(y) {}

    float getX() const { return _x; }
    float getY() const { return _y; }

    int getIntX() const { return static_cast<int>(_x); }
    int getIntY() const { return static_cast<int>(_y); }
};

class Graph {
  public:
    class InvalidDimensionException : public std::exception {
      public:
        virtual const char* what() const throw() { 
          return "Invalid dimension"; 
        }
    };

    class InvalidPositionException : public std::exception {
      public:
        virtual const char* what() const throw() { 
          return "Invalid position"; 
        }
    };

    Graph(float width, float height) {
      if (width <= 0.0f || height <= 0.0f) {
        throw InvalidDimensionException();
      }
      _width = static_cast<int>(width);
      _height = static_cast<int>(height);
    }

    void addPoint(const Vector2& point) {
      if (point.getIntX() < 0 || point.getIntX() >= _width || 
          point.getIntY() < 0 || point.getIntY() >= _height) {
        throw InvalidPositionException();
      }
      _points.push_back(point);
    }

    void display(std::ostream& os) const {
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

  private:
    std::vector<Vector2> _points;
    int _width;
    int _height;

    // Maybe improve this code by creating a map for points
    bool hasPointAt(int x, int y) const {
      std::vector<Vector2>::const_iterator it;
      for (it = _points.begin(); it != _points.end(); ++it) {
        if (it->getIntX() == x && it->getIntY() == y) {
          return true;
        }
      }
      return false;
    }

    // Helper function to calculate the number of digits in an integer
    static int getDigitCount(int number) {
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

    friend std::ostream& operator<<(std::ostream& os, const Graph& graph);
};

std::ostream& operator<<(std::ostream& os, const Graph& graph) {
  graph.display(os);
  return os;
}

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
  }
  catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  return 0;
}
