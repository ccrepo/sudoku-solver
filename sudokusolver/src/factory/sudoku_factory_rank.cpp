//
// sudoku_factory_rank.cpp
// sudoku
//

#include "sudoku_const.h"
#include "sudoku_factory.h"
#include "sudoku_rank.h"
#include "sudoku_collection.h"
#include "sudoku_board.h"
#include "sudoku_cells.h"

namespace sudoku {
namespace zone {

template<>
bool Factory<util::all_ranks_array, zone::Rank>::init(
    const std::shared_ptr<game::Cells> &cells,
    std::shared_ptr<util::all_ranks_array> &zone) {
  if (cells->size()
      != (util::Const::_CONST_CELLS_IN_RANK * util::Const::_CONST_TOTAL_RANKS)) {
    return false;
  }

  util::all_ranks_array ranks;

  util::single_rank_array rank[util::Const::_CONST_TOTAL_RANKS];

  std::for_each(cells->cells().begin(), cells->cells().end(),
      [&rank](const auto &cell) {
        auto info(cell->rankInfo());
        rank[std::get < 0 > (info)][std::get < 1 > (info)] = cell->id().id();
      });

  for (int rank_index(0); rank_index < util::Const::_CONST_TOTAL_RANKS;
      rank_index++) {
    ranks[rank_index] = std::shared_ptr < zone::Rank
        > (new Rank(rank_index, util::Const::_CONST_CELLS_IN_RANK,
            rank[rank_index]));

    if (!ranks[rank_index]->inited()) {
      return false;
    }
  }

  std::copy_n(ranks.begin(), util::Const::_CONST_TOTAL_RANKS, zone->begin());

  return true;
}

} // ns zone
} // ns sudoku

