//
// sudoku_log.cpp
// sudoku
//

#include <sstream>

#include "sudoku_configuration.h"
#include "sudoku_log.h"
#include "sudoku_time.h"

namespace sudoku {
namespace util {

template<typename T>
std::ostringstream* buffer();

template<typename T>
class LoggerAccessor {
public:
  static Logger<T>& get() {
    return Logger < T > ::logger;
  }
};

template<typename T>
Logger<T> Logger<T>::logger;

Logger<LogFatal> &fatal { LoggerAccessor<LogFatal>::get() };
Logger<LogError> &error { LoggerAccessor<LogError>::get() };
Logger<LogWarn> &warn { LoggerAccessor<LogWarn>::get() };
Logger<LogInfo> &info { LoggerAccessor<LogInfo>::get() };
Logger<LogDebug> &debug { LoggerAccessor<LogDebug>::get() };
Logger<LogTrace> &trace { LoggerAccessor<LogTrace>::get() };

template<typename T, typename U>
bool ILogger::stream(const U &data) {
  static bool isLevel(Logger < T > ::isLevelOn());

  if (isLevel) {
    *(util::buffer<T>()) << data;
  }

  return true;
}

template<typename T>
bool Logger<T>::doFlush() {
  static bool isLevel(Logger < T > ::isLevelOn());

  if (isLevel) {
    this->flush < T > (this->getPrefix());
  } else {
    this->clear<T>();
  }

  return true;
}

template<>
constexpr const char* Logger<LogFatal>::getPrefix() const {
  return sudoku::util::Const::_CONST_ENVVAR_LOGLEVEL_FATAL;
}

template<>
constexpr const char* Logger<LogError>::getPrefix() const {
  return sudoku::util::Const::_CONST_ENVVAR_LOGLEVEL_ERROR;
}

template<>
constexpr const char* Logger<LogWarn>::getPrefix() const {
  return sudoku::util::Const::_CONST_ENVVAR_LOGLEVEL_WARN;
}

template<>
constexpr const char* Logger<LogTrace>::getPrefix() const {
  return sudoku::util::Const::_CONST_ENVVAR_LOGLEVEL_TRACE;
}

template<>
constexpr const char* Logger<LogInfo>::getPrefix() const {
  return sudoku::util::Const::_CONST_ENVVAR_LOGLEVEL_INFO;
}

template<>
constexpr const char* Logger<LogDebug>::getPrefix() const {
  return sudoku::util::Const::_CONST_ENVVAR_LOGLEVEL_DEBUG;
}

template<typename T>
Logger<T>::~Logger() {
  if (_flush) {
    this->flush < T > (this->getPrefix());
  }
}

ILogger::ILogger() :
    _flush { true } {
  std::cout.flush();
}

template<typename T>
bool ILogger::flush(const char *prefix) {
  if (util::buffer<T>()->str().length() > 0) {
    std::cout << Time::timestamp() << "[" << prefix << "] "
        << util::buffer<T>()->str();

    //std::cout.flush();
  }

  return ILogger::clear<T>();
}

template<typename T>
bool ILogger::clear() {
  util::buffer<T>()->clear();
  util::buffer<T>()->str("");

  return true;
}

bool ILogger::isNoLevelOn() {
  static const bool isLevel(
      static_cast<int>(Configuration::configuration()->isLevelTrace())
          + // NOTE: '+' intentional - instead of '&'
          static_cast<int>(Configuration::configuration()->isLevelDebug())
          + static_cast<int>(Configuration::configuration()->isLevelInfo())
          + static_cast<int>(Configuration::configuration()->isLevelWarn())
          + static_cast<int>(Configuration::configuration()->isLevelError())
          + static_cast<int>(Configuration::configuration()->isLevelFatal())
          == 0);

  return isLevel;
}

template<>
bool Logger<LogTrace>::isLevelOn() {
  static const bool isLevel(Configuration::configuration()->isLevelTrace());

  return isLevel;
}

template<>
bool Logger<LogDebug>::isLevelOn() {
  static const bool isLevel(
      Configuration::configuration()->isLevelDebug()
          || sudoku::util::Logger < sudoku::util::LogTrace > ::isLevelOn());

  return isLevel;
}

template<>
bool Logger<LogInfo>::isLevelOn() {
  static const bool isLevel(
      isNoLevelOn() ?
          true :
          (Configuration::configuration()->isLevelInfo()
              || sudoku::util::Logger < sudoku::util::LogDebug > ::isLevelOn()));

  return isLevel;
}

template<>
bool Logger<LogWarn>::isLevelOn() {
  static const bool isLevel(
      isNoLevelOn() ?
          true :
          (Configuration::configuration()->isLevelWarn()
              || sudoku::util::Logger < sudoku::util::LogInfo > ::isLevelOn()));

  return isLevel;
}

template<>
bool Logger<LogError>::isLevelOn() {
  static const bool isLevel(
      isNoLevelOn() ?
          true :
          (Configuration::configuration()->isLevelError()
              || sudoku::util::Logger < sudoku::util::LogWarn > ::isLevelOn()));

  return isLevel;
}

template<>
bool Logger<LogFatal>::isLevelOn() {
  static const bool isLevel(
      isNoLevelOn() ?
          true :
          (Configuration::configuration()->isLevelFatal()
              || sudoku::util::Logger < sudoku::util::LogError > ::isLevelOn()));

  return isLevel;
}

template<typename T>
std::ostringstream* buffer() {
  static std::ostringstream *buffer(new std::ostringstream()); // releaased when program exits. skeletal example of hiding impl

  return buffer;
}

} // ns util
} // ns sudoku

