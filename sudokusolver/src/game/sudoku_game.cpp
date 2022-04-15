//
// sudoku_game.cpp
// sudoku
//

#include <sstream>
#include <fstream>

#include "sudoku_log.h"
#include "sudoku_game.h"
#include "sudoku_value.h"

namespace sudoku {
namespace game {

bool Game::load(OUT std::deque<game::Move>& loaded) {
  
  LOGGER_INFO("reading data in ", this->_filename);

  std::string line;
  std::ifstream handle(this->_filename);

  if (!handle) {
    LOGGER_ERROR("unable to open and read file");
    return false;
  }

  int row(0);

  while (std::getline(handle, line) && ++row) {
    
    int column(0);

    std::istringstream values(line);
    std::string value;

    static int id(0);

    while (values >> value &&
        util::Value::isInitValue(value) &&
        ++column) {
      
      if ((id+1) > util::Const::_CONST_TOTAL_CELLS) {
        LOGGER_ERROR("invalid cell count");
        handle.close();
        return false;
      }

      if (util::Value::isPlayValue(value)) {
        loaded.push_back(game::Move(row-1, column-1, util::Value::asInt(value[0]), util::Const::_CONST_MOVEWEIGHT_LOADED));
      }
      else {
        if (!util::Value::isInitValue(value))
        {
          LOGGER_ERROR("invalid cell value of ", value, " at (row, cel) (", row, ",", column, ")");
          handle.close();
          return false;
        }
      }
    }

    if (column != util::Const::_CONST_BOARD_SIZE) {
      LOGGER_ERROR("invalid column data on line ", row);
      handle.close();
      return false;
    }

    ++id;
  }

  if (row != util::Const::_CONST_BOARD_SIZE) {
    LOGGER_ERROR("invalid row count");
    handle.close();
    return false;
  }

  LOGGER_DEBUG("finished read");
  handle.close();
  return true;
}

bool Game::solve() {
  
  if (!this->_inited) {
    LOGGER_ERROR("tree init had failed");
    return false;
  }

  std::deque < game::Move > loaded;

  if (!this->load(loaded)) {
    LOGGER_ERROR("could NOT load sudoku");
    return false;
  }

  if (!_tree->solve(loaded, this->_zones)) {
    LOGGER_ERROR("tree solve failed ");
    return false;
  }

  if (_tree->failed()) {
    LOGGER_ERROR("tree is failed");
    return false;
  }

  if (_tree->solved(this->_zones)) {
    LOGGER_DEBUG("tree is solved");
    return true;
  }

  return false;
}

} // ns game
} // bs sudoku
