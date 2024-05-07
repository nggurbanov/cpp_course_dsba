///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a program that removes all blank lines from a text file and writes the
/// result to a new file.
///
///////////////////////////////////////////////////////////////////////////////

#include <fstream>
#include <iostream>
#include <string>

void removeBlankLines(const std::string &inputFilePath,
                      const std::string &outputFilePath) {
  std::ifstream inputFile(inputFilePath);
  std::ofstream outputFile(outputFilePath);
  std::string line;

  while (std::getline(inputFile, line)) {
    if (!line.empty()) {
      outputFile << line << '\n';
    }
  }

  inputFile.close();
  outputFile.close();
}

int main() {
  removeBlankLines("input.txt", "output.txt");
  return 0;
}