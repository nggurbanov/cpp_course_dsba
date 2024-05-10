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
#include <cmath>
#include <iostream>

// Base class Shape:
// Contains the x and y coordinates of the shape's center.
// Declares the virtual area() function to calculate area.
class Shape {
protected:
  double x, y;

public:
  virtual double area() = 0;
  Shape(double x = 0, double y = 0) : x(x), y(y) {}
};

// Derived class Circle:
// Inherits Shape.
// Adds the radius property.
// Implements the area() function to calculate the area of a circle.
class Circle : public Shape {
private:
  double radius;

public:
  Circle(double x, double y, double radius) : Shape(x, y), radius(radius) {}
  double area() override { return M_PI * radius * radius; }
};

// Rectangle derived class:
// Inherits Shape.
// Adds width and height properties.
// Implements the area() function to calculate the area of a rectangle.
class Rectangle : public Shape {
private:
  double width, height;

public:
  Rectangle(double x, double y, double width, double height) : Shape(x, y), width(width), height(height) {}
  double area() override { return width * height; }
};

int main() {
  Circle krug(1, 2, 2);
  std::cout << "Area of circle: " << krug.area() << std::endl;

  Rectangle pravougaonik(0, 0, 2, 5);
  std::cout << "Area of rectangle: " << pravougaonik.area() << std::endl;

  return 0;
}
