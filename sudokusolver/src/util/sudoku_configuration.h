//
// sudoku_configuration.h
// sudoku
//

#ifndef SUDOKU_CONFIGURATION_H
#define SUDOKU_CONFIGURATION_H

#include <iostream>

#include "sudoku_system.h"
#include "sudoku_const.h"
#include "sudoku_value.h"

namespace sudoku {
namespace util {

class ILogger;

class LogFatal;
class LogError;
class LogWarn;
class LogInfo;
class LogDebug;
class LogTrace;

template<typename T> class Logger;

// This needs to read from a file or command line. 
class Configuration {
  
private:
  Configuration() {
  }

  static Configuration *_configuration;

public:
  virtual ~Configuration() {
  }

  static Configuration* configuration() {
    return _configuration;
  }

  inline bool isValid() const {
    return true;
  }

  inline const std::string& level() const {
    static const std::string value(
        util::Value::lowercase(
            util::Value::trim(
                util::system::getenv(util::Const::_CONST_ENVVAR_LOGLEVEL))));

    return value;
  }

  inline bool isLevelTrace() const {
    static const bool level(
        this->level() == util::Const::_CONST_ENVVAR_LOGLEVEL_TRACE);

    return level;
  }

  inline bool isLevelDebug() const {
    static const bool level(
        this->level() == util::Const::_CONST_ENVVAR_LOGLEVEL_DEBUG);

    return level;
  }

  inline bool isLevelInfo() const {
    static const bool level(
        this->level() == util::Const::_CONST_ENVVAR_LOGLEVEL_INFO);

    return level;
  }

  inline bool isLevelWarn() const {
    static const bool level(
        this->level() == util::Const::_CONST_ENVVAR_LOGLEVEL_WARN);

    return level;
  }

  inline bool isLevelError() const {
    static const bool level(
        this->level() == util::Const::_CONST_ENVVAR_LOGLEVEL_ERROR);

    return level;
  }

  inline bool isLevelFatal() const {
    static const bool level(
        this->level() == util::Const::_CONST_ENVVAR_LOGLEVEL_FATAL);

    return level;
  }

private:
  Configuration(const Configuration&) = delete;
  Configuration& operator=(const Configuration&) = delete;
};

} // ns util
} // ns sudoku

#endif /* SUDOKU_CONFIGURATION_H */

