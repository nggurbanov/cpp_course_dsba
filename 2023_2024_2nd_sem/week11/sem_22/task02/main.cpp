/*
Develop a flexible logging system that supports logging messages to different outputs: a file, a database,
 and a network. Your task is to design a base `Logger` class with a virtual method for logging messages. Then,
 extend this base class with three specific logger types:

1. **FileLogger** - logs messages to a file. It should append messages to the specified file, opening the file in
 append mode. If the file cannot be opened, the system should report an error.

2. **DatabaseLogger** - simulates logging to a database by outputting a message to the console indicating that the
 logging is being done to a database.

3. **NetworkLogger** - simulates logging to a network location by outputting a message to the console indicating that
 the logging is being done over a network.

To manage the creation of logger objects, implement a `LoggerFactory` class with a method `createLogger` that takes
 an enum value indicating the desired logger type and returns a logger object of that type. The factory should support
 creating objects of types `FileLogger`, `DatabaseLogger`, and `NetworkLogger`.

In the main function, demonstrate the usage of your logging system by creating one logger of each type and logging a
 message to show how each logger type handles the message.

Ensure your implementation:
- Follows the principles of object-oriented design, particularly polymorphism for the logging functionality.
- Manages resources properly, especially file handles in the `FileLogger`.
- Provides meaningful output to the console to indicate where the message is being logged for the `DatabaseLogger`
 and `NetworkLogger`.

This task will test your ability to use polymorphism, design patterns (specifically, the Factory Method), and resource
 management in C++.
 * */

#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>

enum class LoggerType {
  FILE,
  DATABASE,
  NETWORK
};

class Logger {
public:
  virtual ~Logger() = default;
  virtual void logMessage(const std::string& message) = 0;
};

class FileLogger : public Logger {
public:
  FileLogger(const std::string& filename) : filename_(filename) {}

  void logMessage(const std::string& message) override {
    std::ofstream file(filename_, std::ios_base::app);
    if (!file.is_open()) {
      std::cerr << "Error opening file: " << filename_ << std::endl;
      return;
    }
    file << getTimestamp() << " - " << message << std::endl;
  }

private:
  std::string filename_;
};

class DatabaseLogger : public Logger {
public:
  void logMessage(const std::string& message) override {
    std::cout << "Logging to database: " << message << std::endl;
  }
};

class NetworkLogger : public Logger {
public:
  void logMessage(const std::string& message) override {
    std::cout << "Logging over network: " << message << std::endl;
  }
};

class LoggerFactory {
public:
  static std::unique_ptr<Logger> createLogger(LoggerType type, const std::string& filename = "") {
    switch (type) {
      case LoggerType::FILE:
        return std::make_unique<FileLogger>(filename);
      case LoggerType::DATABASE:
        return std::make_unique<DatabaseLogger>();
      case LoggerType::NETWORK:
        return std::make_unique<NetworkLogger>();
      default:
        throw std::invalid_argument("Invalid logger type");
    }
  }
};

std::string getTimestamp() {
  auto now = std::chrono::system_clock::now();
  auto timeSinceEpoch = now.time_since_epoch();
  auto secondsSinceEpoch = std::chrono::duration_cast<std::chrono::seconds>(timeSinceEpoch).count();
  std::time_t time = std::time_t(secondsSinceEpoch);
  std::stringstream ss;
  ss << std::put_time(std::gmtime(&time), "%Y-%m-%d %H:%M:%S");
  return ss.str();
}

int main() {
  auto fileLogger = LoggerFactory::createLogger(LoggerType::FILE, "log.txt");
  fileLogger->logMessage("This is a file logging message.");

  auto databaseLogger = LoggerFactory::createLogger(LoggerType::DATABASE);
  databaseLogger->logMessage("This is a database logging message.");

  auto networkLogger = LoggerFactory::createLogger(LoggerType::NETWORK);
  networkLogger->logMessage("This is a network logging message.");

  return 0;
}
