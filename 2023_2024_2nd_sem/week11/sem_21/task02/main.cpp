
/*
Create a programming task that involves designing a class hierarchy for geometric shapes, specifically
 circles and rectangles, with the capability to calculate their area. At the base of this hierarchy is
 an abstract class named `Shape`, which includes protected variables `x` and `y` representing the coordinates
 of the shape's center, and a pure virtual method `area()` for calculating the area. Derived from `Shape`
 are the classes `Circle` and `Rectangle`, each implementing the `area()` method according to their unique
 properties: radius for the circle and width and height for the rectangle. In the main function of the program,
 instances of a circle and a rectangle are to be created, their areas calculated, and the results displayed on
 the screen. Afterward, the allocated memory should be properly freed. The task is to write the necessary
 classes and the main function, adhering to the principles of inheritance and polymorphism in C++.
 * */

#include <cmath>
#include <iostream>

const double PI = 3.1415;

class Shape {
protected:
  double x, y;

public:
  Shape(double x = 0.0, double y = 0.0) : x(x), y(y) {}
  virtual double area() const = 0;
  virtual ~Shape() {}
};

class Circle : public Shape {
private:
  double radius;

public:
  Circle(double x, double y, double radius) : Shape(x, y), radius(radius) {}
  double area() const override {
    return PI * radius * radius;
  }
};

class Rectangle : public Shape {
private:
  double width, height;

public:
  Rectangle(double x, double y, double width, double height) : Shape(x, y), width(width), height(height) {}
  double area() const override {
    return width * height;
  }
};

int main() {
  Circle* circle = new Circle(0.0, 0.0, 5.0);
  Rectangle* rectangle = new Rectangle(0.0, 0.0, 4.0, 6.0);

  Shape* shapes[] = {circle, rectangle};

  for (Shape* shape : shapes) {
    std::cout << "Area of shape: " << shape->area() << std::endl;
  }

  delete circle;
  delete rectangle;

  return 0;
}

