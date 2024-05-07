///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for a Problem: Pointers - Count Elements
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Write a program that reads an array of integers from the standard input and
/// counts the number of elements in the array using pointers. Print the count.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

void plus100(int *arr, int n) {
  for (int i = 0; i < n; i++)
    arr[i] += 100;
}

int main() {
  int n;
  std::cin >> n;
  int *arr = new int[n];
  for (int i = 0; i < n; i++)
    std::cin >> arr[i];
  int *ptr = arr;
  int count = 0;
  while (ptr < arr + n) {
    count++;
    ptr++;
  }
  std::cout << "Count: " << count << '\n';
  delete[] arr;
  return 0;
}
