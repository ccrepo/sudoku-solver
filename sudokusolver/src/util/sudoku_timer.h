//
// sudoku_timer.h
// sudoku
//

#ifndef SUDOKU_TIMER_H
#define SUDOKU_TIMER_H

#include "sudoku_time.h"

namespace sudoku {
namespace util {

class Timer {
  
public:
  Timer(const std::shared_ptr<long long> &result) :
      _result(result), _start(sudoku::util::Time::ts()) {
  }

  virtual ~Timer() {
    if (std::shared_ptr<long long> result = _result.lock()) {
      (*result) = sudoku::util::Time::ts() - this->_start;
    }
  }

private:
  std::weak_ptr<long long> _result;
  const long long _start;

private:
  Timer(const Timer&) = delete;
  Timer& operator=(const Timer&) = delete;

};

} // ns util
} // ns sudoku

#endif /* SUDOKU_TIMER_H */
