///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Create a function that copies the content of one file to another file.
///
///////////////////////////////////////////////////////////////////////////////
#include <fstream>

void copyFile(const std::string &sourceFilePath,
              const std::string &destinationFilePath) {
  std::ifstream inFile(sourceFilePath);
  std::ofstream outFile(destinationFilePath);
  std::string line;
  while (getline(inFile, line)) {
    outFile << line << std::endl;
  }
}

int main() {
  copyFile("source.txt", "destination.txt");
  return 0;
}