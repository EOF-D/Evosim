#ifndef EVOSIM_LOGGER_HPP
#define EVOSIM_LOGGER_HPP

#include <iostream>
#include <string>
#include <ctime>

namespace logger {

  // Log levels
  enum LogLevel { DEBUG, INFO, WARNING, ERROR };

  // Log function
  inline void log(LogLevel level, const std::string& message) {
    // Get the current time
    std::time_t currentTime = std::time(0);
    std::tm* localTime = std::localtime(&currentTime);

    // Format the timestamp
    char timestamp[20];
    std::strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localTime);

    // Define log level string
    const char* levelStr;
    switch (level) {
      case DEBUG:
        levelStr = "DEBUG";
        break;
      case INFO:
        levelStr = "INFO";
        break;
      case WARNING:
        levelStr = "WARNING";
        break;
      case ERROR:
        levelStr = "ERROR";
        break;
      default:
        levelStr = "UNKNOWN";
        break;
    }

    // Print the log message with timestamp and log level to the console
    std::cerr << "[" << timestamp << "] " << levelStr << ": " << message
              << std::endl;
  }

  // Convenience functions for specific log levels
  inline void debug(const std::string& message) { log(DEBUG, message); }
  inline void info(const std::string& message) { log(INFO, message); }
  inline void warn(const std::string& message) { log(WARNING, message); }
  inline void error(const std::string& message) { log(ERROR, message); }

}  // namespace logger

#endif  // EVOSIM_LOGGER_HPP
