///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for a Problem: Bit Manipulation - Check Bit
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Write a program that reads an integer n and a position k from the standard
/// input. The program should check whether the k-th bit of n is set to 1 (i.e.,
/// it prints "Yes" or "No" accordingly).
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

int main() {
  int n, k;
  std::cin >> n >> k;

  if ((n & (1 << (k - 1))) != 0)
    std::cout << "Yes\n";
  else
    std::cout << "No\n";

  return 0;
}
