#include <iostream>

/*
You are tasked with creating a program to manage a database 
of students' information. Each student record consists of the 
following fields: name, age, and grade. You need to implement 
a structure to represent a student record, including various 
overloaded operators for comparison and input/output operations.

In the main program, you should provide functionality to read 
student records from a file, add new records, delete existing 
records, modify records, and display all records. Additionally, 
you should implement the ability to save the updated database 
to a file.

Furthermore, you are required to store the collection of student 
records in a container such as a vector or any other appropriate 
container provided by the Standard Template Library (STL).

Your program should support the following operations:

Reading student records from a file and storing them in the database.
Adding a new student record to the database.
Deleting an existing student record from the database.
Modifying the information of an existing student record.
Displaying all student records.
Saving the updated database to a file.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

struct Student {
    std::string name;
    int age;
    double grade;

    friend std::istream& operator>>(std::istream& in, Student& student) {
        in >> student.name >> student.age >> student.grade;
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Student& student) {
        out << "Name: " << student.name << ", Age: " << student.age << ", Grade: " << student.grade;
        return out;
    }
};

void readRecordsFromFile(const std::string& filename, std::vector<Student>& students) {
    std::ifstream infile(filename);
    if (infile.is_open()) {
        Student temp;
        while (infile >> temp) {
            students.push_back(temp);
        }
        infile.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

void addRecord(std::vector<Student>& students) {
    Student newStudent;
    std::cout << "Enter the name, age, and grade of the new student: ";
    std::cin >> newStudent;
    students.push_back(newStudent);
    std::cout << "New student added: " << newStudent << std::endl;
}

void deleteRecord(std::vector<Student>& students, int index) {
    if (index >= 0 && index < students.size()) {
        std::cout << "Deleting student: " << students[index] << std::endl;
        students.erase(students.begin() + index);
    } else {
        std::cerr << "Invalid index: " << index << std::endl;
    }
}

void modifyRecord(std::vector<Student>& students, int index) {
    if (index >= 0 && index < students.size()) {
        Student modifiedStudent;
        std::cout << "Enter the new name, age, and grade for student at index " << index << ": ";
        std::cin >> modifiedStudent;
        students[index] = modifiedStudent;
        std::cout << "Student modified: " << students[index] << std::endl;
    } else {
        std::cerr << "Invalid index: " << index << std::endl;
    }
}

void displayRecords(const std::vector<Student>& students) {
    for (const auto& student : students) {
        std::cout << student << std::endl;
    }
}

void writeRecordsToFile(const std::string& filename, const std::vector<Student>& students) {
    std::ofstream outfile(filename);
    if (outfile.is_open()) {
        for (const auto& student : students) {
            outfile << student << '\n';
        }
        outfile.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

int main() {
    std::vector<Student> students;

    readRecordsFromFile("students.txt", students);

    addRecord(students);
    deleteRecord(students, 1);
    modifyRecord(students, 2);
    displayRecords(students);

    writeRecordsToFile("updated_students.txt", students);

    return 0;
}
