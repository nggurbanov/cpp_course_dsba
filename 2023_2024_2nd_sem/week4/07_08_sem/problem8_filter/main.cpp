///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem: Filter Array
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a function `int* filter(int* arr, int size, int& newSize, bool
/// (*filterFunc)(int))` that filters an array based on a predicate function and
/// returns a new array.
///
///////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <iostream>

bool isEven(int num) { return num % 2 == 0; }

int *filter(int *arr, int size, int &newSize, bool (*filterFunc)(int)) {
  int *filteredArr = new int[size];
  int filteredIndex = 0;
  for (int i = 0; i < size; ++i) {
    if (filterFunc(arr[i])) {
      filteredArr[filteredIndex++] = arr[i];
    }
  }
  newSize = filteredIndex;
  return filteredArr;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int size = sizeof(arr) / sizeof(arr[0]);
  int *filteredArr;
  int newSize;

  filteredArr = filter(arr, size, newSize, isEven);

  for (int i = 0; i < newSize; ++i) {
    std::cout << filteredArr[i] << " ";
  }
  std::cout << std::endl;

  delete[] filteredArr;

  return 0;
}