///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a function to find and replace all occurrences of a word in a file.
///
///////////////////////////////////////////////////////////////////////////////

#include <fstream> // For fstream
#include <sstream> // For stringstream

void findAndReplaceInFile(const std::string &filePath,
                          const std::string &toFind,
                          const std::string &toReplace) {
  std::ifstream inputFile(filePath);
  std::stringstream buffer;
  std::string line;

  while (std::getline(inputFile, line)) {
    size_t startPos = 0;
    while ((startPos = line.find(toFind, startPos)) != std::string::npos) {
      line.replace(startPos, toFind.length(), toReplace);
      startPos += toReplace.length();
    }
    buffer << line << '\n';
  }

  inputFile.close();

  std::ofstream outputFile(filePath);
  outputFile << buffer.rdbuf();
  outputFile.close();
}

int main() {
  findAndReplaceInFile("file.txt", "oldWord", "newWord");
  return 0;
}