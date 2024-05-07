////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem 3: "Reading text strings using getline".
/// \author     Sergey Shershakov
/// \version    0.1.0
/// \date       19.01.2021
///             This code is for educational purposes of the course
///             "Introduction to programming" provided by the Faculty of
///             Computer Science at the Higher School of Economics.
///
/// Train reading text string with spaces and other special symbol using
/// cin.getline() for c-strings and std::getline() for std::string-s.
/// Then, consider the “read lines until first empty line” idiom.
///
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

int main() {
  const int MAX_LENGTH = 100;
  char c_string[MAX_LENGTH];
  std::cout << "Enter a line of text (C-string): ";
  std::cin.getline(c_string, MAX_LENGTH);
  std::cout << "You entered: " << c_string << std::endl;

  std::string str;
  std::cout << "Enter a line of text (std::string): ";
  std::getline(std::cin, str);
  std::cout << "You entered: " << str << std::endl;

  std::cout << "Enter lines of text (std::string), press enter on an empty "
               "line to stop: "
            << std::endl;
  while (std::getline(std::cin, str) && !str.empty()) {
    std::cout << "You entered: " << str << std::endl;
  }

  return 0;
}
