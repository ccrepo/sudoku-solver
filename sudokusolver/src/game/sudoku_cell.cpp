//
// sudoku_cell.cpp
// sudoku
//

#include <sstream>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <vector>

#include "sudoku_const.h"
#include "sudoku_value.h"
#include "sudoku_log.h"
#include "sudoku_configuration.h"
#include "sudoku_zones.h"
#include "sudoku_block.h"
#include "sudoku_row.h"
#include "sudoku_column.h"
#include "sudoku_cell.h"

namespace sudoku {
namespace game {

bool Cell::solved(const std::shared_ptr<Zones> &zones,
    const util::all_cells_array &cells) const {
  
  int id = this->_id.id();
  int value = this->_value;

  const std::shared_ptr<zone::Block> block = zones->blocks()->operator[](
      this->blockNo());
  const std::shared_ptr<zone::Row> row = zones->rows()->operator[](
      this->rowNo());
  const std::shared_ptr<zone::Column> column = zones->columns()->operator[](
      this->columnNo());

  if (!block->solved(id, value, cells) || !row->solved(id, value, cells)
      || !column->solved(id, value, cells)) {
    return false;
  }

  return true;
}

} // ns game
} // ns sudoku
