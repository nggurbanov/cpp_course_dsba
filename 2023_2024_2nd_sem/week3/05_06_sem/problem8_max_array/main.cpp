///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for a Problem: Pointers - Find Maximum Element
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Write a program that reads an array of integers from the standard input and
/// finds the maximum element using pointers. Print the maximum element.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

int main() {
  int n;
  std::cin >> n;
  int *arr = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  int *max_ptr = arr;
  for (int i = 1; i < n; i++) {
    if (*max_ptr < arr[i]) {
      max_ptr = &arr[i];
    }
  }
  std::cout << *max_ptr << '\n';
  delete[] arr;
  return 0;
}
