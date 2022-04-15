//
// sudoku_row.h
// sudoku
//

#ifndef SUDOKU_ROW_H
#define SUDOKU_ROW_H

#include "sudoku_zone.h"
#include "sudoku_const.h"

namespace sudoku {
namespace zone {

class Row: public game::Zone {
  
public:
  Row(int id, int size, const util::single_row_array &cells);

  virtual ~Row() {
  }

  inline size_t size() const override
  {
    return _cells->size();
  }

  virtual bool solved(int cellId, int cellValue,
      const util::all_cells_array &allCells) const override;

  inline const std::shared_ptr<util::single_row_array> cells() const {
    return _cells;
  }

private:
  std::shared_ptr<util::single_row_array> _cells;

};

} // ns zone
} // ns sudoku

#endif /* SUDOKU_ROW_H */
