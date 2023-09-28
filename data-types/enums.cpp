#include <cstdlib>
#include <iostream>

enum LogLevel : int {
  LogLevelError = 0,
  LogLevelWarn = 1,
  LogLevelInfo = 2,
};

class Logger {
 private:
  LogLevel logLevel;

 public:
  Logger() { this->logLevel = LogLevelInfo; }
  void setLogLevel(LogLevel level) { this->logLevel = level; }
  void log(LogLevel level, const std::string &msg) {
    if (this->logLevel >= level) {
      std::cout << msg << std::endl;
    }
  }
  void logError(const std::string &msg) { log(LogLevelError, msg); }
  void logWarn(const std::string &msg) { log(LogLevelWarn, msg); }
  void logInfo(const std::string &msg) { log(LogLevelInfo, msg); }
};

int main(int argc, char **argv) {
  Logger l;
  l.setLogLevel(LogLevelWarn);
  l.logInfo("Info message");
  l.logWarn("Warn message");
  l.logError("Error message");

  l.setLogLevel(LogLevelInfo);
  l.logInfo("Info message");
  l.logWarn("Warn message");
  l.logError("Error message");
  return EXIT_SUCCESS;
}
