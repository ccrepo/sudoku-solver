//
// sudoku_stack.cpp
// sudoku
//

#include <cassert>

#include "sudoku_stack.h"

namespace sudoku {
namespace zone {

Stack::Stack(int id, int size, const util::single_stack_array &cells) :
    Zone(id), _cells(new util::single_stack_array()) {
  
  if (cells.size() == _cells->size()
      && size == util::Const::_CONST_CELLS_IN_STACK) {
    std::copy_n(cells.begin(), util::Const::_CONST_CELLS_IN_STACK,
        _cells->begin());
    _inited = true;
  } else {
    assert(!"stack setup sizes wrong bug. please fix");
  }
}

bool Stack::solved(int cellId, int cellValue,
    const util::all_cells_array &allCells) const {
  // no constraints really and not used
  return true;
}

} // ns zone
} // ns sudoku
