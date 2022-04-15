//
// sudoku_log.h
// sudoku
//

#ifndef SUDOKU_LOG_H
#define SUDOKU_LOG_H

#include <iostream>
#include <sstream>

namespace sudoku {
namespace util {

template<typename T>
class Logger;

template<typename T>
class LoggerAccessor;

class LogFatal;
class LogError;
class LogWarn;
class LogInfo;
class LogDebug;
class LogTrace;

template<typename T>
Logger<T>& endl(Logger<T> &l) {
  std::ostringstream os;
  os << std::endl;
  l << os.str();
  return l;
}

template<typename T>
Logger<T>& flush(Logger<T> &l) {
  l.doFlush();
  return l;
}

class ILogger {
  
private:
  ILogger(const ILogger&) = delete;
  ILogger& operator=(const ILogger&) = delete;

protected:
  ILogger();

  virtual ~ILogger() {
  }

  template<typename T>
  bool flush(const char *prefix);

  template<typename T>
  bool clear();

  template<typename T, typename U>
  bool stream(const U &data);

  bool _flush;

  static bool isNoLevelOn();
};

template<typename T>
class Logger: private ILogger {
  
private:
  Logger(const Logger<T>&) = delete;
  Logger<T>& operator=(const Logger<T>&) = delete;

  Logger() :
      ILogger() {
  }

  virtual ~Logger();

  static Logger<T> logger;

private:
  friend class LoggerAccessor<T> ;
  friend Logger<T>& util::flush<>(Logger<T> &logger);
  friend Logger<T>& util::endl<>(Logger<T> &logger);

public:
  template<typename U>
  Logger<T>& operator<<(const U &u) {
    ILogger::stream<T, U>(u);
    return (*this);
  }

  Logger<T>& operator<<(Logger<T>& (*fp)(Logger<T> &logger)) {
    return fp(*this);
  }

  bool doFlush();

  constexpr const char* getPrefix() const;

  static bool isLevelOn();
};

extern Logger<LogFatal> &fatal;
extern Logger<LogError> &error;
extern Logger<LogWarn> &warn;
extern Logger<LogInfo> &info;
extern Logger<LogDebug> &debug;
extern Logger<LogTrace> &trace;

template Logger<LogFatal>& endl(Logger<LogFatal> &logger);
template Logger<LogError>& endl(Logger<LogError> &logger);
template Logger<LogWarn>& endl(Logger<LogWarn> &logger);
template Logger<LogInfo>& endl(Logger<LogInfo> &logger);
template Logger<LogDebug>& endl(Logger<LogDebug> &logger);
template Logger<LogTrace>& endl(Logger<LogTrace> &logger);

template Logger<LogFatal>& flush(Logger<LogFatal> &logger);
template Logger<LogError>& flush(Logger<LogError> &logger);
template Logger<LogWarn>& flush(Logger<LogWarn> &logger);
template Logger<LogInfo>& flush(Logger<LogInfo> &logger);
template Logger<LogDebug>& flush(Logger<LogDebug> &logger);
template Logger<LogTrace>& flush(Logger<LogTrace> &logger);

} // ns util
} // ns sudoku

#include "sudoku_variadic.h" // leave this here!

#endif /* SUDOKU_LOG_H */

