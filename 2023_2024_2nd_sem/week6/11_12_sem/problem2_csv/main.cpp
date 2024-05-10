///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Create program to read data from a CSV file (comma separated) 
/// and calculate the average value in each column. Separate into function
///
///////////////////////////////////////////////////////////////////////////////

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

void calculateAverages(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file) {
        std::cerr << "Failed to open file" << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);
    std::istringstream iss(line);
    std::string value;
    int numColumns = 0;
    while (std::getline(iss, value, ',')) {
        numColumns++;
    }

    std::vector<std::vector<double>> columns(numColumns);
    while (std::getline(file, line)) {
        iss.str(line);
        iss.clear();
        for (int i = 0; i < numColumns; i++) {
            std::getline(iss, value, ',');
            columns[i].push_back(std::stod(value));
        }
    }

    for (int i = 0; i < numColumns; i++) {
        double sum = 0.0;
        for (double val : columns[i]) {
            sum += val;
        }
        double average = sum / columns[i].size();
        std::cout << "Average of column " << i + 1 << ": " << average << std::endl;
    }
}

int main() {
    calculateAverages("data.csv");
    return 0;
}