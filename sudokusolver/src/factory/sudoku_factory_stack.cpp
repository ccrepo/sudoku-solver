//
// sudoku_factory_stack.cpp
// sudoku
//

#include "sudoku_const.h"
#include "sudoku_factory.h"
#include "sudoku_stack.h"
#include "sudoku_collection.h"
#include "sudoku_board.h"
#include "sudoku_cells.h"

namespace sudoku {
namespace zone {

template<>
bool Factory<util::all_stacks_array, zone::Stack>::init(
    const std::shared_ptr<game::Cells> &cells,
    std::shared_ptr<util::all_stacks_array> &zone) {
  
  if (cells->size()
      != (util::Const::_CONST_CELLS_IN_STACK * util::Const::_CONST_TOTAL_STACKS)) {
    return false;
  }

  util::all_stacks_array stacks;

  util::single_stack_array stack[util::Const::_CONST_TOTAL_STACKS];

  std::for_each(cells->cells().begin(), cells->cells().end(),
      [&stack](const auto &cell) {
        auto info(cell->stackInfo());
        stack[std::get < 0 > (info)][std::get < 1 > (info)] = cell->id().id();
      });

  for (int stack_index(0); stack_index < util::Const::_CONST_TOTAL_STACKS;
      stack_index++) {
    stacks[stack_index] = std::shared_ptr < zone::Stack
        > (new Stack(stack_index, util::Const::_CONST_CELLS_IN_STACK,
            stack[stack_index]));

    if (!stacks[stack_index]->inited()) {
      return false;
    }
  }

  std::copy_n(stacks.begin(), util::Const::_CONST_TOTAL_STACKS, zone->begin());

  return true;
}

} // ns zone
} // ns sudoku

