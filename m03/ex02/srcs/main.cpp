#include <iostream>

#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Triangle.hpp"

int main() {
    Circle      c0(3.0f);
    Rectangle   r0(3.0f, 4.0f);
    Triangle    t0(Point(0.0f, 0.0f), Point(1.0f, 0.0f), Point(0.0f, 1.0f));

    std::cout << "c0 area: " << c0.area() << std::endl;
    std::cout << "c0 perimeter: " << c0.perimeter() << std::endl;
    std::cout << "r0 area: " << r0.area() << std::endl;
    std::cout << "r0 perimeter: " << r0.perimeter() << std::endl;
    std::cout << "t0 area: " << t0.area() << std::endl;
    std::cout << "t0 perimeter: " << t0.perimeter() << std::endl;

    return 0;
}