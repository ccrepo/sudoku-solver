//
// sudoku_system.h
// sudoku
//

#ifndef SUDOKU_SYSTEM_H
#define SUDOKU_SYSTEM_H

#include <string>

#ifdef _WIN64
  //define something for Windows (64-bit)
  #include "sudoku_generic.h"
#elif _WIN32
  //define something for Windows (32-bit)
  #include "sudoku_generic.h"
#elif __APPLE__
    #include <TargetConditionals.h>
  #if TARGET_OS_IPHONE && TARGET_OS_SIMULATOR
    // define something for simulator
    // (although, checking for TARGET_OS_IPHONE should not be required).
    #include "sudoku_generic.h"
  #elif TARGET_OS_IPHONE && TARGET_OS_MACCATALYST
    // define something for Mac's Catalyst
    #include "sudoku_generic.h"
  #elif TARGET_OS_IPHONE
    // define something for iphone
    #include "sudoku_generic.h"
  #else
    #define TARGET_OS_OSX 1
    #include "sudoku_macos.h"
  #endif
#elif __linux
  // linux
  #include "sudoku_linux.h"
#elif __unix // all unices not caught above
  // Unix
  #include "sudoku_generic.h"
#elif __posix
  // POSIX
  #include "sudoku_generic.h"
#else
static_assert(0, "platform NOT suppprted :)");
#endif

#ifdef SUDOKUSOLVER_MAKEDEPENDS
  #include "sudoku_generic.h"
  #include "sudoku_linux.h"
  #include "sudoku_macos.h"
#endif

namespace sudoku {
namespace util {
namespace system {

std::string getenv(const std::string &name);

} // ns system
} // ns util
} // ns sudoku

#endif /* SUDOKU_SYSTEM_H */

