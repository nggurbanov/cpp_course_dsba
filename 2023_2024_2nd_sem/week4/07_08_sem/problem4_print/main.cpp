///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem: Print Data
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write overloaded functions `void print(int)` and `void print(double)` that
/// print an integer and a double, respectively.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

void print(int value) { std::cout << "Integer: " << value << std::endl; }

void print(double value) { std::cout << "Double: " << value << std::endl; }

int main() {
  int i = 42;
  double d = 3.14;

  print(i);
  print(d);

  return 0;
}