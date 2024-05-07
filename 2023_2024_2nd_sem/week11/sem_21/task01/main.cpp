#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>
#include <vector>

// Implement a class system to represent various
// geometric shapes and calculation of their area.

// Base class Shape:
// Contains the x and y coordinates of the shape's center.
// Declares the area() function to calculate area.
// Derived class Circle:
// Inherits Shape.
// Adds the radius property.
// Implements the area() function to calculate the area of a circle.
// Rectangle derived class:
// Inherits Shape.
// Adds width and height properties.
// Implements the area() function to calculate the area of a rectangle.

class Shape {
private:
  double x, y;

public:
  virtual double area() {};
  Shape(int x, int y) { x = x, y = y; }
};

class Circle : public Shape {
private:
  double r;

public:
  double area() { return M_PI * r * r; }
  Shape(double x, double y, double r) { x = x, y = y; };
};

class Rectangle : public Shape {
private:
  double width, height;

public:
  double area() { return width * height; }
  void setDim(int x, int y) {
    width = x;
    height = y;
  }
};

int main() {
  Circle krug(1, 2);
  krug.setRadius(2);
  std::cout << krug.area() << std::endl;

  Rectangle p;
  p.setDim(2, 5);
  std::cout << p.area() << std::endl;
}
