///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Develop a program to append content to the end of an existing file without
/// overwriting its current content.
///////////////////////////////////////////////////////////////////////////////

#include <fstream>
#include <iostream>
#include <string>

void appendToFile(const std::string &filePath, const std::string &content) {
  std::ofstream file(filePath, std::ios_base::app);
  if (file.is_open()) {
    file << content;
    file.close();
  }
}

int main() {
  appendToFile("existing_file.txt", "Appended content.\n");
  return 0;
}
