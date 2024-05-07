/*******************************************************************************
 * Workshop 2/Task 1
 * Studying properties of some basic datatypes.
 *
 * Use operator sizeof to explore size of all important basic datatypes:
 *  char, short, int, long, long long, double, bool
 *
 * For storing results use named variables of size_t for some types from the
 * list above.
 * Also, try to create complex expressions for output formatted results to
 * std::cout.
 *
 ******************************************************************************/

#include <iostream>

int main() {
  std::cout << "Hello world!";

  // TODO: place your code starting from this line
  size_t charSize = sizeof(char);
  size_t shortSize = sizeof(short);
  size_t intSize = sizeof(int);
  size_t longSize = sizeof(long);
  size_t longLongSize = sizeof(long long);
  size_t doubleSize = sizeof(double);
  size_t boolSize = sizeof(bool);

  std::cout << "\nSize of char: " << charSize << " bytes";
  std::cout << "\nSize of short: " << shortSize << " bytes";
  std::cout << "\nSize of int: " << intSize << " bytes";
  std::cout << "\nSize of long: " << longSize << " bytes";
  std::cout << "\nSize of long long: " << longLongSize << " bytes";
  std::cout << "\nSize of double: " << doubleSize << " bytes";
  std::cout << "\nSize of bool: " << boolSize << " bytes";

  return 0;
}