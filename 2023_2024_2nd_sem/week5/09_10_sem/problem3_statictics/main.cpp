///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Write a program to count the number of lines, words, and characters in a
/// text file.
///
///////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>
#include <sstream>

/*    !!DISCLAIMER!!
It is not specified what to count as characters, words and lines. So, my code
considers:
- Every new "char" type object as CHARACTER.
- Every new sequence of latin alphabet characters as a WORD.
- Every line in a file, even empty lines, as LINES.

P.S. Empty file is considered to have 1 line with no characters and words.
*/

void countFileStatistics(const std::string &filePath, int *line_counter,
                         int *word_counter, int *char_counter) {
  std::ifstream input(filePath);
  char c;
  bool wordStarted = 0;
  while (input.get(c)) {
    (*char_counter)++;
    if (isalpha(c)) {
      if (not wordStarted)
        (*word_counter)++;
      wordStarted = 1;
    } else {
      wordStarted = 0;
      if (c == '\n')
        (*line_counter)++;
    }
  }
}

int main() {
  int *line_counter = new int(1);
  int *word_counter = new int(0);
  int *char_counter = new int(0);
  countFileStatistics("file.txt", line_counter, word_counter, char_counter);
  std::cout << "Input file contains:" << std::endl;
  std::cout << *char_counter << " characters" << std::endl;
  std::cout << *word_counter << " words" << std::endl;
  std::cout << *line_counter << " lines" << std::endl;
  return 0;
}