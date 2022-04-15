//
// sudoku_cellarray.h
// sudoku
//

#ifndef SUDOKU_CELLCONTROLLER_H
#define SUDOKU_CELLCONTROLLER_H

#include <memory>
#include <array>
#include <vector>

#include "sudoku_const.h"
#include "sudoku_collection.h"
#include "sudoku_cell.h"
#include "sudoku_sequence.h"

namespace sudoku {
namespace game {

class Game;
class Board;

class Cells: private util::Sequence, public std::enable_shared_from_this<Cells> {
public:

  Cells() :
      Sequence(), _cells(), _inited(false) {
    auto cells { util::Collection::shared_ptr_collection<util::cell_vector,
        Cell, Sequence>(util::Const::_CONST_TOTAL_CELLS,
        static_cast<Sequence&>(*this)) };

    if (cells->size() == _cells.size()) {
      std::copy_n(cells->begin(), util::Const::_CONST_TOTAL_CELLS,
          _cells.begin());

      _inited = true;
    }
  }

  Cells(const game::Cells &cells) :
      _cells(), _inited(false) {
    std::copy_n(cells.cells().begin(), util::Const::_CONST_TOTAL_CELLS,
        _cells.begin());

    _inited = true;
  }

  virtual ~Cells() {
  }

  inline size_t size() const {
    return _cells.size();
  }

  inline const util::all_cells_array& cells() const {
    return _cells;
  }

  inline util::all_cells_array& cells() {
    return _cells;
  }

  inline bool inited() const {
    return _inited;
  }

  Cells& operator=(const game::Cells &cells) {
    std::copy_n(cells.cells().begin(), util::Const::_CONST_TOTAL_CELLS,
        this->_cells.begin());

    _inited = true;

    return (*this);
  }

private:
  util::all_cells_array _cells;
  bool _inited;

};

} // ns game
} // ns sudoku

#endif // SUDOKU_CELLCONTROLLER_H
