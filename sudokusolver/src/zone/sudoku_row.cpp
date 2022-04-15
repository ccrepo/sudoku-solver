//
// sudoku_row.cpp
// sudoku
//

#include <cassert>

#include "sudoku_row.h"
#include "sudoku_cell.h"

namespace sudoku {
namespace zone {

Row::Row(int id, int size, const util::single_row_array &cells) :
    Zone(id), _cells(new util::single_row_array()) {
  if (cells.size() == _cells->size()
      && size == util::Const::_CONST_CELLS_IN_ROW) {
    std::copy_n(cells.begin(), util::Const::_CONST_CELLS_IN_ROW,
        _cells->begin());
    _inited = true;
  } else {
    assert(!"row setup sizes wrong bug. please fix");
  }
}

bool Row::solved(int cellId, int cellValue,
    const util::all_cells_array &allCells) const {
  return std::all_of(this->_cells->begin(), this->_cells->end(),
      [&cellId, &cellValue, &allCells](int listCellId) {
        if (cellId != listCellId) {
          return cellValue != allCells[listCellId]->value();
        }

        return true; // value will be there same so ignore
      });
}

} // ns zone
} // ns sudoku
