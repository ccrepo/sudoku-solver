//
// sudoku_block.cpp
// sudoku
//

#include <cassert>

#include "sudoku_block.h"
#include "sudoku_cells.h"

namespace sudoku {
namespace zone {

Block::Block(int id, int size, const util::single_block_array &cells) :
    Zone(id), _cells(new util::single_block_array()) {
  if (cells.size() == _cells->size()
      && size == util::Const::_CONST_CELLS_IN_BLOCK) {
    std::copy_n(cells.begin(), util::Const::_CONST_CELLS_IN_BLOCK,
        _cells->begin());
    _inited = true;
  } else {
    assert(!"block setup sizes wrong bug. please fix");
  }
}

bool Block::solved(int cellId, int cellValue,
    const util::all_cells_array &allCells) const {
  return std::all_of(this->_cells->begin(), this->_cells->end(),
      [&cellId, &cellValue, &allCells](int listCellId) {
        if (cellId != listCellId) {
          return cellValue != allCells[listCellId]->value();
        }

        return true;
      });
}

} // ns zone
} // ns sudoku
