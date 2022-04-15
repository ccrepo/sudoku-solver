//
// sudoku_variadic.h
// sudoku
//

#ifndef SUDOKU_VARIADIC_H
#define SUDOKU_VARIADIC_H

#include <iostream>
#include <sstream>

#include "sudoku_system.h"
#include "sudoku_configuration.h"
#include "sudoku_log.h"

namespace sudoku {
namespace util {

class LogFatal;
class LogError;
class LogWarn;
class LogInfo;
class LogDebug;
class LogTrace;

namespace macro {

inline std::ostringstream& operator<<(std::ostringstream &os,
    const std::ostringstream &s) {
  os << s.str();

  return os;
}

template<typename T>
void log(std::ostringstream &os, const T &t) {
  os << t;
}

template<typename T, typename ... Args>
void log(std::ostringstream &os, const T &t, const Args &... args) {
  os << t;

  macro::log<Args...>(os, args...);
}

template<typename T, typename ... Args>
void log(util::Logger<T> &logger, const char *file, int lineno,
    const char *function, const Args &... args) {
  std::ostringstream os;

  os << file << ":" << lineno << "(" << function << ") ";

  macro::log<Args...>(os, args...);

  logger << os.str() << util::endl<T> << util::flush<T>;
}

#define LOGGER_TRACE(...) {                                                \
if (sudoku::util::Logger<sudoku::util::LogTrace>::isLevelOn())             \
{                                                                          \
constexpr const char* basename(sudoku::util::system::basename(__FILE__));  \
sudoku::util::macro::log<sudoku::util::LogTrace>                           \
(sudoku::util::trace, basename,                                            \
__LINE__, __FUNCTION__, __VA_ARGS__);                                      \
}                                                                          \
}

#define LOGGER_DEBUG(...) {                                                \
if (sudoku::util::Logger<sudoku::util::LogDebug>::isLevelOn())             \
{                                                                          \
constexpr const char* basename(sudoku::util::system::basename(__FILE__));  \
sudoku::util::macro::log<sudoku::util::LogDebug>                           \
(sudoku::util::debug, basename,                                            \
__LINE__, __FUNCTION__, __VA_ARGS__);                                      \
}                                                                          \
}

#define LOGGER_INFO(...) {                                                 \
if (sudoku::util::Logger<sudoku::util::LogInfo>::isLevelOn())              \
{                                                                          \
constexpr const char* basename(sudoku::util::system::basename(__FILE__));  \
sudoku::util::macro::log<sudoku::util::LogInfo>                            \
(sudoku::util::info, basename,                                             \
__LINE__, __FUNCTION__, __VA_ARGS__);                                      \
}                                                                          \
}

#define LOGGER_WARN(...) {                                                 \
if (sudoku::util::Logger<sudoku::util::LogWarn>::isLevelOn())              \
{                                                                          \
constexpr const char* basename(sudoku::util::system::basename(__FILE__));  \
sudoku::util::macro::log<sudoku::util::LogWarn>                            \
(sudoku::util::warn, basename,                                             \
__LINE__, __FUNCTION__, __VA_ARGS__);                                      \
}                                                                          \
}

#define LOGGER_ERROR(...) {                                                \
if (sudoku::util::Logger<sudoku::util::LogError>::isLevelOn())             \
{                                                                          \
constexpr const char* basename(sudoku::util::system::basename(__FILE__));  \
sudoku::util::macro::log<sudoku::util::LogError>                           \
(sudoku::util::error, basename,                                            \
__LINE__, __FUNCTION__, __VA_ARGS__);                                      \
}                                                                          \
}

#define LOGGER_FATAL(...) {                                                \
if (sudoku::util::Logger<sudoku::util::LogFatal>::isLevelOn())             \
{                                                                          \
constexpr const char* basename(sudoku::util::system::basename(__FILE__));  \
sudoku::util::macro::log<sudoku::util::LogFatal>                           \
(sudoku::util::fatal, basename,                                            \
__LINE__, __FUNCTION__, __VA_ARGS__);                                      \
}                                                                          \
}

} // ns macro
} // ns util
} // ns sudoku

#endif // SUDOKU_VARIADIC_H
