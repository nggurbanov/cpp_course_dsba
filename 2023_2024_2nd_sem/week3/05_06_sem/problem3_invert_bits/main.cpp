///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for a Problem: Bit Manipulation - Bitwise Complement
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Write a program that takes an integer n as input and performs bitwise
/// complement (inverts all bits) on it. Print the resulting number in binary
/// and decimal forms.
///
///////////////////////////////////////////////////////////////////////////////

#include <bitset>
#include <iostream>

int main() {
  int n;
  std::cin >> n;
  int complement = ~n;
  std::cout << "Binary: " << std::bitset<32>(complement) << std::endl;
  std::cout << "Decimal: " << complement << std::endl;
  return 0;
}
