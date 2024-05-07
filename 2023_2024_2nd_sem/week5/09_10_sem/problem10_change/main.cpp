///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a program that reads a text file, converts all lowercase letters to
/// uppercase, and writes the result to a new file.
///////////////////////////////////////////////////////////////////////////////

#include <cctype> // For toupper()
#include <fstream>
#include <iostream>

void convertToLowercase(const std::string &inputFilePath,
                        const std::string &outputFilePath) {
  std::ifstream inputFile(inputFilePath);
  std::ofstream outputFile(outputFilePath);

  if (inputFile.is_open() && outputFile.is_open()) {
    std::string line;
    while (std::getline(inputFile, line)) {
      for (char &c : line) {
        c = toupper(c);
      }
      outputFile << line << '\n';
    }
    inputFile.close();
    outputFile.close();
  }
}

int main() {
  convertToLowercase("input.txt", "output_uppercase.txt");
  return 0;
}
