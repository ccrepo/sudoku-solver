//
// sudokusolver.cpp
// sudoku
//

//
// This code is a sodoku puzzle solver.
//

#include <iostream>
#include <thread>

#include "sudoku_argument.h"
#include "sudoku_log.h"
#include "sudoku_game.h"
#include "sudoku_time.h"
#include "sudoku_thread.h"
#include "sudoku_timer.h"

int main(int argc, const char *argv[]) {
  
  std::shared_ptr<long long> ms(std::make_shared<long long>(0));

  sudoku::util::Thread updater(sudoku::util::Time::update);

  if (sudoku::util::Logger < sudoku::util::LogDebug > ::isLevelOn()) {
    LOGGER_TRACE("LOGGER_TRACE on");
    LOGGER_DEBUG("LOGGER_DEBUG on");
    LOGGER_INFO("LOGGER_INFO  on");
    LOGGER_WARN("LOGGER_WARN  on");
    LOGGER_ERROR("LOGGER_ERROR on");
    LOGGER_FATAL("LOGGER_FATAL on");
  }

  if (!sudoku::util::Argument::init(argc, argv)) {
    LOGGER_ERROR("arguments failed");

    sudoku::util::Argument::help();

    return 1;
  }

  if (sudoku::util::Argument::argument()->terminate()) {
    if (sudoku::util::Argument::argument()->result()) {
      LOGGER_ERROR("bad arguments");
    }

    sudoku::util::Argument::help();

    return sudoku::util::Argument::argument()->result();
  }

  sudoku::game::Game game(sudoku::util::Argument::argument()->filename());

  LOGGER_DEBUG("start position", game);

  if (!game.inited()) {
    LOGGER_ERROR("could NOT init sudoku");
    return 1;
  }

  bool solved(false);

  {
    sudoku::util::Timer timer(ms);

    if (!(solved = game.solve())) {
      LOGGER_ERROR("incident while solving sudoku");
    }
  }

  if ((solved = game.solved())) {
    LOGGER_INFO("sudoku solved!!");
  } else {
    LOGGER_ERROR("sudoku NOT solved");
  }

  LOGGER_INFO("final position", game);

  LOGGER_INFO("solution time: ", *ms, "ms");

  LOGGER_INFO("boards examined: ", game.nodescreated());

  return solved ? 0 : 1;
}

