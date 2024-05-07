///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for a Problem: Bit Manipulation - Set Bit
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Write a program that takes an integer n and a position k as input. The
/// program should set (change to 1) the k-th bit of the integer n and print the
/// resulting number in binary and decimal forms.
///
///////////////////////////////////////////////////////////////////////////////

#include <bitset>
#include <iostream>

int main() {
  int n, k;
  std::cin >> n >> k;

  n |= (1 << (k - 1));

  std::cout << "Binary: " << std::bitset<32>(n) << "\n";
  std::cout << "Decimal: " << n << "\n";

  return 0;
}
