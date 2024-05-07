///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a program to copy a binary file to another file in reverse byte order.
///////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>

void reverseCopyBinaryFile(const std::string &inputFilePath,
                           const std::string &outputFilePath) {
  std::ifstream inputFile(inputFilePath, std::ios::binary);
  std::ofstream outputFile(outputFilePath, std::ios::binary);

  if (inputFile.is_open() && outputFile.is_open()) {
    inputFile.seekg(0, std::ios::end);
    std::streamsize size = inputFile.tellg();
    inputFile.seekg(0, std::ios::beg);

    std::vector<char> buffer(size);
    inputFile.read(buffer.data(), size);

    for (int i = size - 1; i >= 0; --i) {
      outputFile.put(buffer[i]);
    }

    inputFile.close();
    outputFile.close();
  }
}

int main() {
  reverseCopyBinaryFile("input_binary.bin", "output_reversed.bin");
  return 0;
}
