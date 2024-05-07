/*******************************************************************************
 *  Workshop 2/Task 2
 *
 *  Studying input, output, conditions and simple loops.
 *
 *  A program outputs a formatted multiplication table for n numbers.
 *
 *  Example. For n = 3, the output is:
 *
 *      1   2   3
 *  1   1   2   3
 *  2   2   4   6
 *  3   3   6   9
 *
 *  1) Ask a user to input a boundary n for the table.
 *  2) Check whether n is in the range [1; 10] using if statement. Otherwise
 *     output the following message: "Wrong argument", and terminate the
 *program. 3) Output a table row by row using for-loop statement. Use tabs to
 *separate individual values. 4) Modify the program. Use while-loop statement.
 *
 ******************************************************************************/

#include <iostream>

int main() {
  std::cout << "Hello world!\n";

  int n;
  std::cout << "Enter the boundary n for the table: ";
  std::cin >> n;

  if (n < 1 || n > 10) {
    std::cout << "Wrong argument\n";
    return 0;
  }

  std::cout << "\nMultiplication table using for-loop:\n";
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      std::cout << i * j << '\t';
    }
    std::cout << '\n';
  }

  std::cout << "\nMultiplication table using while-loop:\n";
  int i = 1, j;
  while (i <= n) {
    j = 1;
    while (j <= n) {
      std::cout << i * j << '\t';
      j++;
    }
    std::cout << '\n';
    i++;
  }

  return 0;
}
