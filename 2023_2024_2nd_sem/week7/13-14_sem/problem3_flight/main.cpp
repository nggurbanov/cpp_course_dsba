///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Describe the “Flight” structure with flight identifier fields,
/// departure airport, destination airport and departure time
/// (structure “Time”). Write a function that takes as input
/// vector of flights and airport name displaying information
/// first about all flights arriving at the specified airport, and then
/// about all flights departing from this airport.
///

#include <iostream>
#include <vector>
#include <string>

struct Time {
    int hours;
    int minutes;
    int seconds;

    Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {}
};

struct Flight {
    std::string id;
    std::string departureAirport;
    std::string destinationAirport;
    Time departureTime;

    Flight(const std::string& i, const std::string& d, const std::string& a, const Time& t)
        : id(i), departureAirport(d), destinationAirport(a), departureTime(t) {}
};

void displayFlights(const std::vector<Flight>& flights, const std::string& airport) {
    std::cout << "Arrivals at " << airport << ":" << std::endl;
    for (const auto& flight : flights) {
        if (flight.destinationAirport == airport) {
            std::cout << "  " << flight.id << " from " << flight.departureAirport
                      << " at " << flight.departureTime.hours << ":"
                      << flight.departureTime.minutes << ":"
                      << flight.departureTime.seconds << std::endl;
        }
    }

    std::cout << "Departures from " << airport << ":" << std::endl;
    for (const auto& flight : flights) {
        if (flight.departureAirport == airport) {
            std::cout << "  " << flight.id << " to " << flight.destinationAirport
                      << " at " << flight.departureTime.hours << ":"
                      << flight.departureTime.minutes << ":"
                      << flight.departureTime.seconds << std::endl;
        }
    }
}

int main() {
    Time t1(10, 20, 30);
    Time t2(12, 30, 40);
    Time t3(14, 40, 50);

    Flight f1("F1", "City1", "City2", t1);
    Flight f2("F2", "City2", "City3", t2);
    Flight f3("F3", "City3", "City2", t3);

    std::vector<Flight> flights { f1, f2, f3 };

    displayFlights(flights, "City2");

    return 0;
}

