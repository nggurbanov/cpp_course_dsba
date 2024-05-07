///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a function to read a file containing integers
/// separated by spaces or newlines, sum these integers, and write the result to
/// another file.
///////////////////////////////////////////////////////////////////////////////

#include <cmath>
#include <fstream>
#include <iostream>

int sumIntegersInFile(const std::string &inputFilePath,
                      const std::string &outputFilePath) {
  std::ifstream inFile(inputFilePath);
  int result = 0;
  int c;
  while (inFile >> c) {
    result += c;
  }
  std::ofstream outFile(outputFilePath);
  outFile << result;
  std::cout << "Result is already at destination file. It is: " << result
            << std::endl;
  return 0;
}

int main() {
  sumIntegersInFile("input.txt", "output.txt");
  return 0;
}