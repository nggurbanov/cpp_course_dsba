#include <iostream>

/*
You work as an analyst in a company that sells electronics. You are provided 
with monthly sales of products for a year in the form of a vector, where each 
element of the vector represents the sales amount for a month. Your task is 
to analyze the data and perform the following operations:

Find the total sales volume for the year.
Determine the month with the maximum sales volume. If there are multiple months 
with the maximum sales, output the first one.
Calculate the average monthly sales.
Determine whether the sales in each month exceed the average monthly sales. 
For each month, output true or false accordingly.
Find the number of months with sales below the average.

Input Data
Vector std::vector<int> sales = {12000, 15000, 13000, 19000, 17000, 16000, 
                                 18000, 21000, 20000, 17000, 22000, 19000};, 
where each element represents the sales amount for a month.

Tasks to Implement
Implement a function to calculate the total sales volume for the year.
Implement a function to find the month with the maximum sales volume.
Calculate the average monthly sales.
Determine whether the sales in each month exceed the average monthly sales, 
and output the corresponding true or false values.
Find the number of months with sales below the average.

Total sales volume for the year: 204000
Month with maximum sales volume: 11
Average monthly sales: 17000
Sales above average: false false false true true false true true true true true true
Number of months with sales below average: 3

*/

#include <iostream>
#include <vector>

int calculateTotalSales(const std::vector<int>& sales) {
  int total = 0;
  for (const int& sale : sales) {
    total += sale;
  }
  return total;
}

int findMaxSalesMonth(const std::vector<int>& sales) {
  int maxIndex = 0;
  for (size_t i = 1; i < sales.size(); ++i) {
    if (sales[i] > sales[maxIndex]) {
      maxIndex = i;
    }
  }
  return maxIndex;
}

double calculateAverageSales(const std::vector<int>& sales) {
  int total = calculateTotalSales(sales);
  return static_cast<double>(total) / sales.size();
}

void checkSalesAboveAverage(const std::vector<int>& sales) {
  double average = calculateAverageSales(sales);
  for (const int& sale : sales) {
    std::cout << (sale > average ? "true " : "false ");
  }
  std::cout << std::endl;
}

int findMonthsBelowAverage(const std::vector<int>& sales) {
  int belowAverage = 0;
  double average = calculateAverageSales(sales);
  for (const int& sale : sales) {
    if (sale < average) {
      belowAverage++;
    }
  }
  return belowAverage;
}

int main() {
  std::vector<int> sales = {12000, 15000, 13000, 19000, 17000, 16000,
                            18000, 21000, 20000, 17000, 22000, 19000};

  int totalSales = calculateTotalSales(sales);
  std::cout << "Total sales volume for the year: " << totalSales << std::endl;

  int maxSalesMonth = findMaxSalesMonth(sales);
  std::cout << "Month with maximum sales volume: " << maxSalesMonth << std::endl;

  double averageSales = calculateAverageSales(sales);
  std::cout << "Average monthly sales: " << averageSales << std::endl;

  std::cout << "Sales above average: ";
  checkSalesAboveAverage(sales);

  int belowAverageMonths = findMonthsBelowAverage(sales);
  std::cout << "Number of months with sales below average: " << belowAverageMonths << std::endl;

  return 0;
}
