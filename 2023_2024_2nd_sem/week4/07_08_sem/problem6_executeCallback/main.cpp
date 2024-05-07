///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem: Execute Callback
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a function `void executeCallback(void (*callback)())` that takes a
/// function pointer and executes the callback function.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

// Function prototype
void callback();

// Function to execute the callback
void executeCallback(void (*callback)()) { callback(); }

// Callback function
void callback() { std::cout << "Callback function executed!" << std::endl; }

int main() {
  executeCallback(callback);

  return 0;
}