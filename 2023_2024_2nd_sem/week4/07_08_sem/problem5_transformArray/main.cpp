///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem: Array Transformation
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a function `void transformArray(int* arr, int size, int
/// (*transform)(int))` that applies a transformation function to each element
/// of an array.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

// Transformation function prototype
int transform(int value);

// Function to apply transformation to an array
void transformArray(int *arr, int size, int (*transform_func)(int)) {
  for (int i = 0; i < size; ++i) {
    arr[i] = transform_func(arr[i]);
  }
}

// Transformation function: square the input
int transform(int value) { return value * value; }

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int size = sizeof(arr) / sizeof(arr[0]);

  transformArray(arr, size, transform);

  for (int i = 0; i < size; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}