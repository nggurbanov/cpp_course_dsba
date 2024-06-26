////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem 2: "Length of a C-string (strlen)".
/// \author     Sergey Shershakov
/// \version    0.1.0
/// \date       19.01.2021
///             This code is for educational purposes of the course
///             "Introduction to programming" provided by the Faculty of
///             Computer Science at the Higher School of Economics.
///
/// Count the length of a C-style string variable initialized with a
/// string
/// literal (implement strlen() ).
///
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

int main() {
  const char *str = "Hello, World!";
  std::cout << strlen(str) << std::endl;
  return 0;
}
