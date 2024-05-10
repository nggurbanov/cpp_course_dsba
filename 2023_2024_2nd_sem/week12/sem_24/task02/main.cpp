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

class User {
 public:
  User(const std::string& name) : name_(name) {}

  virtual void accessResources() const {
    std::cout << name_ << " has basic access to resources.\n";
  }

 protected:
  std::string name_;
};

class Employee : public virtual User {
 public:
  Employee(const std::string& name, int level)
      : User(name), level_(level) {}

  void accessResources() const override {
    std::cout << name_ << " has level " << level_
              << " access to employee resources.\n";
  }

 protected:
  int level_;
};

class Manager : public virtual User {
 public:
  Manager(const std::string& name) : User(name) {}

  void accessResources() const override {
    std::cout << name_ << " has access to manage department resources.\n";
  }
};

class Administrator : public Employee, public Manager {
 public:
  Administrator(const std::string& name, int level)
      : User(name), Employee(name, level), Manager(name) {}

  void accessResources() const override {
    std::cout << name_ << " has the highest level of access to all resources.\n";
  }
};

int main() {
  User user("Alice");
  user.accessResources();

  Employee employee("Bob", 1);
  employee.accessResources();

  Manager manager("Charlie");
  manager.accessResources();

  Administrator administrator("Dave", 10);
  administrator.accessResources();

  return 0;
}
