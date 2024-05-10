// User class: The base class from which the
// all other classes are inherited. Includes
// basic information about the user (for example, name).

// Employee class: Derived from User, representing
// employee. Adds a level of access to resources specific
// for staff.

// Manager class: Derived from User, representing a manager.
// Managers have a higher level of access than regular ones
// employees, and can manage department resources.

// Administrator class: Derived class that should inherit
// properties and methods from both Employee and Manager. Administrators
// have the highest level of access allowing them to manage resources
// at all levels.

// Implement a class system using virtual inheritance,
// to solve the problem of diamond-shaped inheritance and correctly
// organize a hierarchy of classes User, Employee, Manager and
//Administrator. Every class must provide a method
// accessResources() demonstrating the user's access level.

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class User {
protected:
    string name;

public:
    static int count;
    User(string name) : name(name) { count++; }
    virtual void accessResources() const {
        cout << name << " has basic user access." << endl;
    }
    virtual ~User() {}
};
int User::count = 0;

// Employee class derived from User using virtual inheritance
class Employee : virtual public User {
public:
    Employee(string name) : User(name) {}
    void accessResources() const override {
        cout << name << " has basic employee access." << endl;
    }
    virtual ~Employee() {}
};

// Manager class derived from User using virtual inheritance
class Manager : virtual public User {
public:
    Manager(string name) : User(name) {}
    void accessResources() const override {
        cout << name << " has basic manager access." << endl;
    }
    virtual ~Manager() {}
};

// Administrator class derived from Employee and Manager using virtual inheritance
class Administrator : public Employee, public Manager {
public:
    Administrator(string name) : User(name), Employee(name), Manager(name) {}
    void accessResources() const override {
        cout << name << " has administrator access." << endl;
    }
    virtual ~Administrator() {}
};

string generateName() {
    size_t size = rand() % 7 + 3; // 3 to 9 letters
    string name = "";
    for (int i = 0; i < size; ++i) {
        name += char(rand() % 26 + 'a');
    }
    return name;
}

int main() {
    srand(time(0));
    cout << User::count << '\n';
    vector<User*> v;
    for (int i = 0; i < 10; ++i) {
        int num = rand() % 3;
        if (num == 0) {
            v.push_back(new Employee(generateName()));
        } else if (num == 1) {
            v.push_back(new Administrator(generateName()));
        } else if (num == 2) {
            v.push_back(new Manager(generateName()));
        }
        v[i]->accessResources();
    }
    cout << User::count << '\n';

    // Free memory
    for (User* user : v) {
        delete user;
    }

    return 0;
}
