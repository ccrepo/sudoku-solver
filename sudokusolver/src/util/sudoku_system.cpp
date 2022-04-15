//
// sudoku_system.cpp
// sudoku
//

#include <cstring>

#include "sudoku_system.h"

namespace sudoku {
namespace util {
namespace system {

std::string getenv(const std::string &name) {
  
  char *value { std::getenv(name.c_str()) };

  if (value != nullptr && strlen(value)) {
    return std::string(value);
  }

  return std::string();
}

} // ns system
} // ns util
} // ns sudoku

