///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem: Calculate the Area of a Circle
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a function `double circleArea(double radius)` that calculates and
/// returns the area of a circle given its radius.
///
///////////////////////////////////////////////////////////////////////////////

#include <cmath>
#include <iostream>

double circleArea(double radius) { return M_PI * std::pow(radius, 2); }

int main() {
  double radius = 5.0;
  double area = circleArea(radius);
  std::cout << "The area of the circle with radius " << radius << " is " << area
            << std::endl;
  return 0;
}