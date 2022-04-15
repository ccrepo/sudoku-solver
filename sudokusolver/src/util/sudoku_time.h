//
// sudoku_time.h
// sudoku
//

#ifndef SUDOKU_TIME_H
#define SUDOKU_TIME_H

#include <string>
#include <mutex>

#include <chrono>
using namespace std::chrono_literals;

template<typename T1, typename T2>
using mul = std::ratio_multiply<T1, T2>;

#include <ctime>
#include <iomanip>
#include <sstream>
#include <tuple>
#include <cassert>
#include <thread>
#include <string>
#include <atomic>
#include <iostream>

#include "sudoku_const.h"
#include "sudoku_thread.h"

namespace sudoku {
namespace util {

class Time {
  
public:
  static void update() {
    while (!Thread::exit()) {
      std::string time = util::Time::generate();

      {
        std::unique_lock < std::mutex > lock(sudoku::util::Time::_mutex);

        _time = time;
      }

      sudoku::util::Time::sleep(util::Const::_CONST_THREADING_LONGSLEEP);
    }
  }

  inline static std::string timestamp() {
    while (true) {
      {
        std::unique_lock < std::mutex > lock(sudoku::util::Time::_mutex);

        if (!util::Time::_time.empty()) {
          return util::Time::_time;
        }
      }

      sudoku::util::Time::sleep(util::Const::_CONST_THREADING_SHORTSLEEP);
    }
  }

  inline static long long ts() {
    static auto epoch = std::chrono::system_clock::from_time_t(0);

    return std::chrono::duration_cast < std::chrono::milliseconds
        > (std::chrono::system_clock::now() - epoch).count();
  }

  inline static void sleep(unsigned int milliseconds) {
    try {
      std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
    } catch (...) {
    }
  }

private:
  inline static std::string generate() {
    auto ts { std::chrono::system_clock::to_time_t(
        std::chrono::system_clock::now()) };

    std::ostringstream os;

    //os << std::put_time(std::localtime(&ts), "%Y%m%d %H:%M:%S");
    os << std::put_time(std::localtime(&ts), "%H:%M:%S");

    return os.str();
  }

private:
  Time() = delete;

private:
  static std::mutex _mutex;
  static std::string _time;

};

} // ns util
} // ns sudoku

#endif /* SUDOKU_TIME_H */
