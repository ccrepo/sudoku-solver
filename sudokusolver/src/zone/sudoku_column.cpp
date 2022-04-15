//
// sudoku_column.cpp
// sudoku
//

#include <cassert>

#include "sudoku_column.h"
#include "sudoku_cell.h"
#include "sudoku_log.h"

namespace sudoku {
namespace zone {

Column::Column(int id, int size, const util::single_column_array &cells) :
    Zone(id), _cells(new util::single_column_array()) {
  if (cells.size() == _cells->size()
      && size == util::Const::_CONST_CELLS_IN_COLUMN) {
    std::copy_n(cells.begin(), util::Const::_CONST_CELLS_IN_COLUMN,
        _cells->begin());
    _inited = true;
  } else {
    assert(!"column setup sizes wrong bug. please fix");
  }
}

bool Column::solved(int cellId, int cellValue,
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
