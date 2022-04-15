//
// sudoku_factory_block.cpp
// sudoku
//

#include "sudoku_const.h"
#include "sudoku_factory.h"
#include "sudoku_column.h"
#include "sudoku_collection.h"
#include "sudoku_board.h"
#include "sudoku_cells.h"

namespace sudoku {
namespace zone {

template<>
bool Factory<util::all_columns_array, zone::Column>::init(
    const std::shared_ptr<game::Cells> &cells,
    std::shared_ptr<util::all_columns_array> &zone) {
  if (cells->size()
      != (util::Const::_CONST_CELLS_IN_COLUMN
          * util::Const::_CONST_TOTAL_COLUMNS)) {
    return false;
  }

  util::all_columns_array columns;

  util::single_column_array column[util::Const::_CONST_TOTAL_COLUMNS];

  std::for_each(cells->cells().begin(), cells->cells().end(),
      [&column](const auto &cell) {
        auto info(cell->columnInfo());
        column[std::get < 0 > (info)][std::get < 1 > (info)] = cell->id().id();
      });

  for (int column_index(0); column_index < util::Const::_CONST_TOTAL_COLUMNS;
      column_index++) {
    columns[column_index] = std::shared_ptr < zone::Column
        > (new Column(column_index, util::Const::_CONST_CELLS_IN_COLUMN,
            column[column_index]));

    if (!columns[column_index]->inited()) {
      return false;
    }
  }

  std::copy_n(columns.begin(), util::Const::_CONST_TOTAL_COLUMNS,
      zone->begin());

  return true;
}

} // ns zone
} // ns sudoku

