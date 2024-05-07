///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for a Problem: Sum digits
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Write a program that takes a number and
/// find sum of digits recursively.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

int sum_digits(int n) {
  if (n == 0) {
    return 0;
  }
  return n % 10 + sum_digits(n / 10);
}

int main() {
  int number;
  std::cout << "Enter a number: ";
  std::cin >> number;
  std::cout << "Sum of digits: " << sum_digits(number) << std::endl;
  return 0;
}