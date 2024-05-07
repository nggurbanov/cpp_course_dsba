///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for a Problem: Pointers - Sum of Two Numbers
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Write a program that reads two integers from the standard input and
/// calculates their sum using pointers. Print the result.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

int main() {
  int num1, num2;
  int *ptr1 = &num1;
  int *ptr2 = &num2;

  std::cin >> *ptr1 >> *ptr2;

  int sum = *ptr1 + *ptr2;

  std::cout << "Sum: " << sum << "\n";

  return 0;
}
