///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Read a single integer n from the file. In another file, write a matrix filled 
/// in the following way:
/// 1   2   3   4
/// 12  13  14  5
/// 11  16  15  6
/// 10  9   8   7
///
///////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>
#include <sstream> 

void countFileStatistics(const std::string& filePath) {
    std::ifstream inputFile(filePath);
    int n;
    inputFile >> n;
    inputFile.close();

    std::ofstream outputFile("output.txt");

    int count = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i % 2 == 0) {
                outputFile << count++ << " ";
            } else {
                outputFile << n * n - count + 1 << " ";
                count++;
            }
        }
        outputFile << "\n";
    }
    outputFile.close();
}

int main() {
    countFileStatistics("file.txt");
    return 0;
}