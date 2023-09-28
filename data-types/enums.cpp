#include <cstdlib>
#include <iostream>

enum LogLevel : int {
  LogLevelError = 0,
  LogLevelWarn = 1,
  LogLevelInfo = 2,
};

class Logger {
 private:
  LogLevel level;

 public:
  Logger() { this->level = LogLevelInfo; }
  void setLogLevel(LogLevel level) { this->level = level; }
  void log(LogLevel level, std::string msg) {
    if (this->level >= level) {
      std::cout << msg << std::endl;
    }
  }
  void logError(std::string msg) { log(LogLevelError, msg); }
  void logWarn(std::string msg) { log(LogLevelWarn, msg); }
  void logInfo(std::string msg) { log(LogLevelInfo, msg); }
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
