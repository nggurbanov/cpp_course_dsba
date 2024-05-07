////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem 8: "Enhanced Multiplication Table".
/// \author     Sergey Shershakov
/// \version    0.1.0
/// \date       19.01.2021
///             This code is for educational purposes of the course
///             "Introduction to programming" provided by the Faculty of
///             Computer Science at the Higher School of Economics.
///
/// Modification of the Problem 7 (Multiplication Table), where a user can
/// repeat a solution multiple times (with using the “do..while” loop).
///
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

int main() {
  int m, n;
  char answer;

  do {
    std::cout << "Enter the number of rows (1 <= m <= 8): ";
    std::cin >> m;
    std::cout << "Enter the number of columns (1 <= n <= 8): ";
    std::cin >> n;

    std::cout << '\t';
    for (short i = 1; i < n + 1; ++i) {
      std::cout << i << '\t';
    }
    std::cout << '\n';

    for (size_t i = 1; i < m + 1; ++i) {
      for (size_t j = 0; j < n + 1; ++j) {
        if (j != 0)
          std::cout << i * j << '\t';
        else
          std::cout << i << '\t';
      }
      std::cout << '\n';
    }

    std::cout << "Do you want to repeat the solution (y/n)? ";
    std::cin >> answer;
  } while (answer == 'y' || answer == 'Y');

  return 0;
}
