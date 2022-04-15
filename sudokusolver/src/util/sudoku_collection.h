//
// sudoku_collection.h
// sudoku
//

#ifndef SUDOKU_COLLECTION_H
#define SUDOKU_COLLECTION_H

#include <memory>
#include <vector>
#include <array>
#include <tuple>
#include <map>
#include <string>

namespace sudoku {
namespace game {
class Zone;
class Cell;
}

namespace zone {
class Block;
class Row;
class Column;
class Rank;
class Stack;
}

namespace util {

typedef std::vector<std::shared_ptr<game::Cell>> cell_vector;
typedef std::vector<std::shared_ptr<game::Zone>> zone_vector;

typedef std::array<std::shared_ptr<game::Cell>, util::Const::_CONST_TOTAL_CELLS> all_cells_array;

typedef std::array<std::shared_ptr<zone::Block>,
    util::Const::_CONST_TOTAL_BLOCKS> all_blocks_array;
typedef std::array<std::shared_ptr<zone::Row>, util::Const::_CONST_TOTAL_ROWS> all_rows_array;
typedef std::array<std::shared_ptr<zone::Column>,
    util::Const::_CONST_TOTAL_COLUMNS> all_columns_array;
typedef std::array<std::shared_ptr<zone::Rank>, util::Const::_CONST_TOTAL_RANKS> all_ranks_array;
typedef std::array<std::shared_ptr<zone::Stack>,
    util::Const::_CONST_TOTAL_STACKS> all_stacks_array;

typedef std::array<int, util::Const::_CONST_CELLS_IN_BLOCK> single_block_array;
typedef std::array<int, util::Const::_CONST_CELLS_IN_ROW> single_row_array;
typedef std::array<int, util::Const::_CONST_CELLS_IN_COLUMN> single_column_array;
typedef std::array<int, util::Const::_CONST_CELLS_IN_RANK> single_rank_array;
typedef std::array<int, util::Const::_CONST_CELLS_IN_STACK> single_stack_array;

class Collection {
  
public:
  template<typename T, typename U, typename ... Args>
  static std::shared_ptr<T> shared_ptr_collection(int count,
      const Args &... args) {
    std::shared_ptr < T > collection(new T());

    collection->reserve(count);

    while ((count--) > 0) {
      collection->emplace_back(new U(args...));
    }

    return collection;
  }

private:
  Collection() = delete;

};

} // ns util
} // ns sudoku

#endif /* SUDOKU_COLLECTION_H */
