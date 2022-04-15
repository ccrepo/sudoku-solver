//
// sudoku_zones.cpp
// sudoku
//

#include <cassert>

#include "sudoku_zones.h"
#include "sudoku_factory.h"
#include "sudoku_collection.h"

#include "sudoku_block.h"
#include "sudoku_row.h"
#include "sudoku_column.h"
#include "sudoku_rank.h"
#include "sudoku_stack.h"

namespace sudoku {
namespace game {

Zones::Zones(const std::shared_ptr<Cells> &cells) :
    _blocks(new util::all_blocks_array()), _rows(new util::all_rows_array()), _columns(
        new util::all_columns_array()), _ranks(new util::all_ranks_array()), _stacks(
        new util::all_stacks_array()), _inited(false) {
  
  if (zone::Factory<util::all_blocks_array, zone::Block>::init(cells, _blocks)
      && zone::Factory<util::all_rows_array, zone::Row>::init(cells, _rows)
      && zone::Factory<util::all_columns_array, zone::Column>::init(cells,
          _columns)
      && zone::Factory<util::all_ranks_array, zone::Rank>::init(cells, _ranks)
      && zone::Factory<util::all_stacks_array, zone::Stack>::init(cells,
          _stacks)) {
    if (std::all_of(_blocks->begin(), _blocks->end(), [](const auto &item) {
      return item->inited();
    }) && std::all_of(_rows->begin(), _rows->end(), [](const auto &item) {
      return item->inited();
    }) && std::all_of(_columns->begin(), _columns->end(), [](const auto &item) {
      return item->inited();
    }) && std::all_of(_ranks->begin(), _ranks->end(), [](const auto &item) {
      return item->inited();
    }) && std::all_of(_stacks->begin(), _stacks->end(), [](const auto &item) {
      return item->inited();
    }))
    {

      _inited = true;
    } else {
      assert(!"util::Zones setup failed[1]. please fix");
    }
  } else {
    assert(!"util::Zones setup failed[2]. please fix");
  }
}

} // ns game
} // ns sudoku

