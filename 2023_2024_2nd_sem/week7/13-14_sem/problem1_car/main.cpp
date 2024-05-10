///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       14.02.2024
///
/// TASK DESCRIPTION
///
///////////////////////////////////////////////////////////////////////////////

/*
Car
Define a Car struct with private attributes
for year of manufacture (year), color (color),
number of doors (count_doors), fuel level
(fuel_level) and mileage (mileage).
Implement a constructor to initialize these
attributes. Fuel level and mileage must be
the default values are 50.0 and 0.0 respectively.
Implement the drive(double distance) method.
which reduces the fuel level depending on
distance traveled and increases mileage.
  Assume that the car consumes 1 liter
  fuel for 10 km.
Implement the refuel(double amount) method to
  add fuel to the tank.
Add a stop() method that prints a message
that the car has been stopped.
Implement an info() method that prints information
about the car: year of manufacture, color, number of doors,
fuel level and mileage.
Implement methods to change colors
car and obtaining current color values,
fuel level and mileage.
In the main function, create several Car objects with different characteristics.
Test all class methods to make sure they work correctly. Try walking some distance, refueling the car, changing its color and then displaying information about it.
*/

#include <iostream>
#include <string>

struct Car {
    private:
        int year;
        std::string color;
        int count_doors;
        double fuel_level;
        double mileage;
    public:
        Car(int y, std::string c, int d, double f = 50.0, double dis = 0.0) {
            year = y;
            color = c;
            count_doors = d;
            fuel_level = f;
            mileage = dis;
        };
        void drive(double distance) {
            fuel_level -= distance / 10;
            if (fuel_level < 0) {
                fuel_level = 0;
                std::cout << "Car has been stopped. Out of fuel.\n";
            } else {
                mileage += distance;
            }
        };
        void refuel(double amount) {
            fuel_level += amount;
        };
        void stop() {
            std::cout << "Car has been stopped.\n";
        };
        void info() {
            std::cout << "Year: " << year << "\n";
            std::cout << "Color: " << color << "\n";
            std::cout << "Number of doors: " << count_doors << "\n";
            std::cout << "Fuel level: " << fuel_level << "\n";
            std::cout << "Mileage: " << mileage << "\n";
        };
        void set_color(std::string c) {
            color = c;
        };
        std::string get_color() {
            return color;
        };
        double get_fuel_level() {
            return fuel_level;
        };
        double get_mileage() {
            return mileage;
        };
};

int main() {
    Car car1(2010, "black", 5);
    car1.info();
    car1.drive(100);
    car1.info();
    car1.refuel(20);
    car1.info();
    car1.set_color("red");
    std::cout << "Car color: " << car1.get_color() << "\n";
    Car car2(2022, "white", 3);
    car2.info();
    car2.drive(200);
    car2.info();
    return 0;
}
