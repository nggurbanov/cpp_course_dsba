///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a program that reads information about company employees (name, position, salary) 
/// from a text file and increases the salary of each employee by 10%, writing the updated 
/// information to a new file.
/// Write two functions: for txt and csv file.
///////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

void processTxtFile(const std::string& inputFilePath, const std::string& outputFilePath) {
    std::ifstream inputFile(inputFilePath);
    std::ofstream outputFile(outputFilePath);

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string name, position;
        double salary;
        iss >> name >> position >> salary;

        salary *= 1.1;

        outputFile << name << " " << position << " " << salary << "\n";
    }

    inputFile.close();
    outputFile.close();
}

void processCsvFile(const std::string& inputFilePath, const std::string& outputFilePath) {
    std::ifstream inputFile(inputFilePath);
    std::ofstream outputFile(outputFilePath);

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string name, position;
        double salary;
        std::getline(iss, name, ',');
        std::getline(iss, position, ',');
        iss >> salary;

        salary *= 1.1;

        outputFile << name << "," << position << "," << salary << "\n";
    }

    inputFile.close();
    outputFile.close();
}

int main() {
    processTxtFile("input.txt", "output_txt.txt");
    processCsvFile("input.csv", "output_csv.csv");
    return 0;
}