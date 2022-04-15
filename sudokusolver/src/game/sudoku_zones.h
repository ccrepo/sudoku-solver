//
// sudoku_zones.h
// sudoku
//

#ifndef SUDOKU_ZONES_H
#define SUDOKU_ZONES_H

#include <memory>

#include "sudoku_zone.h"
#include "sudoku_const.h"
#include "sudoku_collection.h"

namespace sudoku {
namespace game {

class Board;
class Cells;

class Zones {
  
public:
  Zones(const std::shared_ptr<Cells> &cells);

  virtual ~Zones() {
  }

  inline bool inited() const {
    return _inited;
  }

  inline const std::shared_ptr<util::all_blocks_array>& blocks() const {
    return this->_blocks;
  }

  inline const std::shared_ptr<util::all_rows_array>& rows() const {
    return this->_rows;
  }

  inline const std::shared_ptr<util::all_columns_array>& columns() const {
    return this->_columns;
  }

  inline const std::shared_ptr<util::all_ranks_array>& ranks() const {
    return this->_ranks;
  }

  inline const std::shared_ptr<util::all_stacks_array>& stacks() const {
    return this->_stacks;
  }

private:
  // TODO - not happy with the way these are used. Need to move more functions into this class and reuse !!!
  std::shared_ptr<util::all_blocks_array> _blocks;
  std::shared_ptr<util::all_rows_array> _rows;
  std::shared_ptr<util::all_columns_array> _columns;
  std::shared_ptr<util::all_ranks_array> _ranks;
  std::shared_ptr<util::all_stacks_array> _stacks;

private:
  bool _inited;

private:
  Zones(const Zones&) = delete;
  Zones& operator=(const Zones&) = delete;
};

} // ns game
} // ns sudoku

#endif // SUDOKU_ZONES_H

