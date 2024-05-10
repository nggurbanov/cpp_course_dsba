///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       14.02.2024
///
/// TASK DESCRIPTION
///
///////////////////////////////////////////////////////////////////////////////

/*
Describe the “Time” structure with three fields: hours, minutes
and seconds. Define a subtraction operation such that
the result is an object of type time containing
how much time is between the first and second event. If
the second event is later than the first, the answer should be equal to
zero, otherwise return a time structure containing the difference
between these events (hours, minutes, seconds).
*/

#include <iostream>

struct Time {
    int hours;
    int minutes;
    int seconds;

    Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {}

    Time operator-(const Time& other) const {
        int totalSeconds1 = hours * 3600 + minutes * 60 + seconds;
        int totalSeconds2 = other.hours * 3600 + other.minutes * 60 + other.seconds;

        if (totalSeconds1 < totalSeconds2) {
            return Time(0, 0, 0);
        } else {
            int diffSeconds = totalSeconds1 - totalSeconds2;
            return Time(diffSeconds / 3600, (diffSeconds % 3600) / 60, diffSeconds % 60);
        }
    }
};

int main() {
    Time t1(10, 20, 30);
    Time t2(9, 30, 40);

    Time diff = t1 - t2;

    std::cout << "Difference: " << diff.hours << " hours " << diff.minutes << " minutes " << diff.seconds << " seconds" << std::endl;

    return 0;
}

