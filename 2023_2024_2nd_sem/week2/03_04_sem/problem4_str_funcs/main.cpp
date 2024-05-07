////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem 4: "Some functions for dealing with
/// strings". \author     Sergey Shershakov \version    0.1.0
/// \date       19.01.2021
///             This code is for educational purposes of the course
///             "Introduction to programming" provided by the Faculty of
///             Computer Science at the Higher School of Economics.
///
/// Try to use functions for dealing with strings:
/// 1) strcmp, strlen for c-strings;
/// 2) string:: size(), length(), operator<, operator+, operator= etc for
///    std::string-s.
///
////////////////////////////////////////////////////////////////////////////////

#include <cstring>
#include <iostream>
#include <string>

int main() {
  const char *c_string1 = "Hello, World!";
  const char *c_string2 = "Hello, World!";
  int length = strlen(c_string1);
  int comparison = strcmp(c_string1, c_string2);
  std::cout << "Length of c-string1: " << length << std::endl;
  std::cout << "Comparison of c-string1 and c-string2: " << comparison
            << std::endl;

  std::string str1 = "Hello, World!";
  std::string str2 = "Hello, World!";
  int size = str1.size();
  int length2 = str1.length();
  bool comparison2 = str1 < str2;
  std::string concatenation = str1 + " " + str2;
  str1 = concatenation;
  std::cout << "Size of str1: " << size << std::endl;
  std::cout << "Length of str1: " << length2 << std::endl;
  std::cout << "Comparison of str1 and str2: " << comparison2 << std::endl;
  std::cout << "Concatenation of str1 and str2: " << concatenation << std::endl;
  std::cout << "New value of str1: " << str1 << std::endl;

  return 0;
}
