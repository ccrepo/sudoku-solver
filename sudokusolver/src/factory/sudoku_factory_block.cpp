//
// sudoku_factory_block.cpp
// sudoku
//

#include "sudoku_const.h"
#include "sudoku_factory.h"
#include "sudoku_block.h"
#include "sudoku_collection.h"
#include "sudoku_board.h"
#include "sudoku_cells.h"

namespace sudoku {
namespace zone {

template<>
bool Factory<util::all_blocks_array, zone::Block>::init(
    const std::shared_ptr<game::Cells> &cells,
    std::shared_ptr<util::all_blocks_array> &zone) {
  if (cells->size()
      != (util::Const::_CONST_CELLS_IN_BLOCK * util::Const::_CONST_TOTAL_BLOCKS)) {
    return false;
  }

  util::all_blocks_array blocks;

  util::single_block_array block[util::Const::_CONST_TOTAL_BLOCKS];

  std::for_each(cells->cells().begin(), cells->cells().end(),
      [&block](const auto &cell) {
        auto info(cell->blockInfo());
        block[std::get < 0 > (info)][std::get < 1 > (info)] = cell->id().id();
      });

  for (int block_index(0); block_index < util::Const::_CONST_TOTAL_BLOCKS;
      block_index++) {
    blocks[block_index] = std::shared_ptr < zone::Block
        > (new Block(block_index, util::Const::_CONST_CELLS_IN_BLOCK,
            block[block_index]));

    if (!blocks[block_index]->inited()) {
      return false;
    }
  }

  std::copy_n(blocks.begin(), util::Const::_CONST_TOTAL_BLOCKS, zone->begin());

  return true;
}

} // ns zone
} // ns sudoku

