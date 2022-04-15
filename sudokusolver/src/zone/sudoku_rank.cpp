//
// sudoku_rank.cpp
// sudoku
//

#include <cassert>

#include "sudoku_rank.h"
#include "sudoku_cell.h"

namespace sudoku
{
namespace zone
{

Rank::Rank(int id, int size, const util::single_rank_array& cells) : Zone(id), _cells(new util::single_rank_array()) {
  
  if (cells.size() == _cells->size() && size == util::Const::_CONST_CELLS_IN_RANK)
  {
    std::copy_n(cells.begin(), util::Const::_CONST_CELLS_IN_RANK, _cells->begin());
    
    _inited = true;
  }
  else
  {
    assert(!"rank setup sizes wrong bug. please fix");
  }
}

bool Rank::solved(int cellId, int cellValue, const util::all_cells_array& allCells) const {
  // no constraints really and not used
  return true;
}

} // ns zone
} // ns sudoku
