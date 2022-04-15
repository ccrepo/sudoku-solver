//
// sudoku_rank.h
// sudoku
//

#ifndef SUDOKU_RANK_H
#define SUDOKU_RANK_H

#include "sudoku_zone.h"
#include "sudoku_const.h"

namespace sudoku {
namespace zone {

class Rank: public game::Zone {

public:
  Rank(int id, int size, const util::single_rank_array &cells);

  virtual ~Rank() {
  }

  inline size_t size() const override {
    return _cells->size();
  }

  virtual bool solved(int cellId, int cellValue,
      const util::all_cells_array &allCells) const override;

  inline const std::shared_ptr<util::single_rank_array> cells() const {
    return _cells;
  }

private:
  std::shared_ptr<util::single_rank_array> _cells;

};

} // ns zone
} // ns sudoku

#endif /* SUDOKU_RANK_H */
