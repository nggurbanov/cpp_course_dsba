///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for a Problem: Pointers - Copy Array
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Write a program that reads an array of integers from the standard input,
/// creates a new array, copies the elements from the original array to the new
/// array using pointers, and then prints the new array.
///
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for a Problem: Pointers - Copy Array
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Write a program that reads an array of integers from the standard input,
/// creates a new array, copies the elements from the original array to the new
/// array using pointers, and then prints the new array.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

int main() {
  int n;
  std::cout << "Enter the number of elements in the array: ";
  std::cin >> n;

  int *originalArray = new int[n];
  int *newArray = new int[n];

  std::cout << "Enter the elements of the array:" << std::endl;
  for (int i = 0; i < n; i++) {
    std::cin >> originalArray[i];
  }

  int *ptrOriginal = originalArray;
  int *ptrNew = newArray;
  for (int i = 0; i < n; i++) {
    *(ptrNew + i) = *(ptrOriginal + i);
  }

  std::cout << "New array elements are:" << std::endl;
  for (int i = 0; i < n; i++) {
    std::cout << newArray[i] << " ";
  }
  std::cout << std::endl;

  delete[] originalArray;
  delete[] newArray;

  return 0;
}
