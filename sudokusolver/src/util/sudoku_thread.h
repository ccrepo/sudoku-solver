//
// sudoku_thread.h
// sudoku
//

#ifndef SUDOKU_THREAD_H
#define SUDOKU_THREAD_H

#include <thread>
#include <atomic>

#include "sudoku_system.h"
#include "sudoku_configuration.h"
#include "sudoku_log.h"

namespace sudoku {
namespace util {

class Thread {
  
public:
  Thread(void (*fp)()) :
      _thread(fp) {
  }

  virtual ~Thread() {
    Thread::shutdown();

    _thread.join();
  }

  static void shutdown() {
    Thread::_exit.store(true);
  }

  static bool exit() {
    return static_cast<bool>(Thread::_exit);
  }

private:
  std::thread _thread;
  static std::atomic<bool> _exit;

private:
  Thread(const Thread&) = delete;
  Thread& operator=(const Thread&) = delete;

};

} // ns util
} // ns sudoku

#endif /* SUDOKU_THREAD_H */
