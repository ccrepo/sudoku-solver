//
// sudoku_value.h
// sudoku
//

#ifndef SUDOKU_VALUE_H
#define SUDOKU_VALUE_H

#include <algorithm>
#include <string>
#include <sstream>
#include <cassert>

#include "sudoku_const.h"

namespace sudoku {
namespace util {

class Value {
  
public:
  enum VALUE_TYPE {
    VALUE_TYPE_INIT, VALUE_TYPE_PLAY
  };

  static inline bool isInitValue(const std::string &value) {
    char c(' ');

    return (value.length() == 1) && (c = value[0])
        && (c >= util::Const::_CONST_SUDOKU_MININIT_ASCHAR)
        && (c <= util::Const::_CONST_SUDOKU_MAXINIT_ASCHAR);
  }

  static inline bool isPlayValue(int value) {
    return (value >= util::Const::_CONST_SUDOKU_MINPLAY_ASINT)
        && (value <= util::Const::_CONST_SUDOKU_MAXPLAY_ASINT);
  }

  static inline bool isPlayValue(const std::string &value) {
    char c(' ');

    return (value.length() == 1) && (c = value[0])
        && (c >= util::Const::_CONST_SUDOKU_MINPLAY_ASCHAR)
        && (c <= util::Const::_CONST_SUDOKU_MAXPLAY_ASCHAR);
  }

  static inline int asInt(const std::string &v, VALUE_TYPE type =
      VALUE_TYPE_PLAY) {
    if ((type == Value::VALUE_TYPE_INIT && !isInitValue(v))
        || (type == Value::VALUE_TYPE_PLAY && !isPlayValue(v))) {
      return 0;
    }

    return Value::asInt(v[0]);
  }

  static inline int asInt(char v) {
    if (v >= '0' && v <= '9') {
      return static_cast<int>(v) - static_cast<int>('0');
    }

    assert(
        !"should not reach here as all valid values must already be in mapping");
    return 0;
  }

  static inline std::string ltrim(const std::string &original) {
    std::string copy(original);

    copy.erase(copy.begin(), std::find_if(copy.begin(), copy.end(), [](char c) {
      return !std::isspace(c);
    }));

    return copy;
  }

  static inline std::string rtrim(const std::string &original) {
    std::string copy(original);

    copy.erase(std::find_if(copy.rbegin(), copy.rend(), [](char c) {
      return !std::isspace(c);
    }).base(), copy.end());

    return copy;
  }

  static inline std::string trim(const std::string &s) {
    return Value::ltrim(Value::rtrim(s));
  }

  static inline std::string lowercase(const std::string &original) {
    std::string copy(original);

    std::transform(copy.begin(), copy.end(), copy.begin(), ::tolower);

    return copy;
  }

private:
  Value() = delete;
};

} // ns util
} // ns sudoku

#endif /* SUDOKU_VALUE_H */
