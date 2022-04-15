//
// sudoku_factory_row.cpp
// sudoku
//

#include "sudoku_const.h"
#include "sudoku_factory.h"
#include "sudoku_row.h"
#include "sudoku_collection.h"
#include "sudoku_board.h"
#include "sudoku_cells.h"

namespace sudoku {
namespace zone {

template<>
bool Factory<util::all_rows_array, zone::Row>::init(
    const std::shared_ptr<game::Cells> &cells,
    std::shared_ptr<util::all_rows_array> &zone) {
  
  if (cells->size()
      != (util::Const::_CONST_CELLS_IN_ROW * util::Const::_CONST_TOTAL_ROWS)) {
    return false;
  }

  util::all_rows_array rows;

  util::single_row_array row[util::Const::_CONST_TOTAL_ROWS];

  std::for_each(cells->cells().begin(), cells->cells().end(),
      [&row](const auto &cell) {
        auto info(cell->rowInfo());
        row[std::get < 0 > (info)][std::get < 1 > (info)] = cell->id().id();
      });

  for (int row_index(0); row_index < util::Const::_CONST_TOTAL_ROWS;
      row_index++) {
    rows[row_index] =
        std::shared_ptr < zone::Row
            > (new Row(row_index, util::Const::_CONST_CELLS_IN_ROW,
                row[row_index]));

    if (!rows[row_index]->inited()) {
      return false;
    }
  }

  std::copy_n(rows.begin(), util::Const::_CONST_TOTAL_ROWS, zone->begin());

  return true;
}

} // ns zone
} // ns sudoku

