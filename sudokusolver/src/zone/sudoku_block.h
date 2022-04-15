//
// sudoku_block.h
// sudoku
//

#ifndef SUDOKU_BLOCK_H
#define SUDOKU_BLOCK_H

#include "sudoku_zone.h"
#include "sudoku_const.h"

namespace sudoku {
namespace zone {

class Block: public game::Zone {
  
public:
  Block(int id, int size, const util::single_block_array &cells);

  virtual ~Block() {
  }

  inline size_t size() const override
  {
    return _cells->size();
  }

  virtual bool solved(int cellId, int cellValue,
      const util::all_cells_array &allCells) const override;

  inline const std::shared_ptr<util::single_block_array> cells() const {
    return _cells;
  }

private:
  std::shared_ptr<util::single_block_array> _cells;
};

} // ns zone
} // ns sudoku

#endif /* SUDOKU_BLOCK_H */
