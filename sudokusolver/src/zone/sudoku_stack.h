//
// sudoku_stack.h
// sudoku
//

#ifndef SUDOKU_STACK_H
#define SUDOKU_STACK_H

#include "sudoku_zone.h"
#include "sudoku_const.h"

namespace sudoku {
namespace zone {

class Stack: public game::Zone {
  
public:
  Stack(int id, int size, const util::single_stack_array &cells);

  virtual ~Stack() {
  }

  inline size_t size() const override {
    return _cells->size();
  }

  virtual bool solved(int cellId, int cellValue,
      const util::all_cells_array &allCells) const override;

  inline const std::shared_ptr<util::single_stack_array> cells() const {
    return _cells;
  }

private:
  std::shared_ptr<util::single_stack_array> _cells;

};

} // ns zone
} // ns sudoku

#endif /* SUDOKU_STACK_H */
