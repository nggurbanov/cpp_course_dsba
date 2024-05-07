///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a program to read the content of a text file and write its content in
/// reverse order to another file.
///////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void reverseFileContent(const std::string &inputFilePath,
                        const std::string &outputFilePath) {
  std::ifstream inputFile(inputFilePath);
  std::ofstream outputFile(outputFilePath);
  std::vector<std::string> lines;
  std::string line;

  while (std::getline(inputFile, line)) {
    lines.push_back(line);
  }

  inputFile.close();

  for (int i = lines.size() - 1; i >= 0; --i) {
    outputFile << lines[i] << '\n';
  }

  outputFile.close();
}

int main() {
  reverseFileContent("input.txt", "output_reversed.txt");
  return 0;
}
