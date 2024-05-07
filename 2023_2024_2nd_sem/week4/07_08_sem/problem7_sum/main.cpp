///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem: Sum of Numbers
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a variadic function `int sum(int count, ...)` that returns the sum of
/// 'count' numbers.
///
///////////////////////////////////////////////////////////////////////////////

#include <cstdarg>
#include <iostream>

int sum(int count, ...) {
  va_list args;
  va_start(args, count);
  int result = 0;
  for (int i = 0; i < count; ++i) {
    result += va_arg(args, int);
  }
  va_end(args);
  return result;
}

int main() {
  int total = sum(5, 1, 2, 3, 4, 5);
  std::cout << "Total: " << total << std::endl;

  return 0;
}