//
// sudoku_column.h
// sudoku
//

#ifndef SUDOKU_COLUMN_H
#define SUDOKU_COLUMN_H

#include "sudoku_zone.h"
#include "sudoku_const.h"

namespace sudoku {
namespace zone {

class Column: public game::Zone {
  
public:
  Column(int id, int size, const util::single_column_array &cells);

  virtual ~Column() {
  }

  inline size_t size() const override
  {
    return _cells->size();
  }

  virtual bool solved(int cellId, int cellValue,
      const util::all_cells_array &allCells) const override;

  inline const std::shared_ptr<util::single_column_array> cells() const {
    return _cells;
  }

private:
  std::shared_ptr<util::single_column_array> _cells;

};

} // ns zone
} // ns sudoku

#endif /* SUDOKU_COLUMN_H */
