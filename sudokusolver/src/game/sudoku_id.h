//
// sudoku_id.h
// sudoku
//

#ifndef SUDOKU_ID_H
#define SUDOKU_ID_H

#include <array>

#include "sudoku_const.h"

namespace sudoku {
namespace game {
namespace cell {

class Id {
  
public:
  Id() :
      _id(0) {
  }

  explicit Id(int id) :
      _id(id) {
  }

  virtual ~Id() {
  }

  Id(const Id &id) :
      _id(id._id) {
  }

  Id& operator=(const Id &id) {
    this->_id = id._id;
    return (*this);
  }

  int id() const {
    return this->_id;
  }

  //

  inline int blockNo() const {
    return std::get < 0 > (this->blockInfo());
  }

  inline int rowNo() const {
    return std::get < 0 > (this->rowInfo());
  }

  inline int columnNo() const {
    return std::get < 0 > (this->columnInfo());
  }

  inline int rankNo() const {
    return std::get < 0 > (this->rankInfo());
  }

  inline int stackNo() const {
    return std::get < 0 > (this->stackInfo());
  }

  //

  std::tuple<int, int> blockInfo() const {
    static std::array<bool, util::Const::_CONST_TOTAL_CELLS> flags;
    static std::tuple<int, int> cache[util::Const::_CONST_TOTAL_CELLS];

    if (!flags[this->_id]) {
      // TODO simplify calc
      cache[this->_id] = std::tuple<int, int> { (((this->_id
          / util::Const::_CONST_CELLS_IN_ROW)
          / util::Const::_CONST_BLOCKS_IN_COL)
          * (util::Const::_CONST_CELLS_IN_BLOCK_ROW))
          + ((this->_id % util::Const::_CONST_CELLS_IN_ROW)
              / (util::Const::_CONST_CELLS_IN_BLOCK_ROW)), ((this->_id
          / util::Const::_CONST_CELLS_IN_ROW)
          * (util::Const::_CONST_CELLS_IN_BLOCK_ROW)
          + (this->_id % util::Const::_CONST_CELLS_IN_ROW)
              % (util::Const::_CONST_CELLS_IN_BLOCK_ROW))
          % util::Const::_CONST_CELLS_IN_BLOCK };

      flags[this->_id] = true;
    }

    return cache[this->_id];
  }

  inline std::tuple<int, int> rowInfo() const {
    static std::array<bool, util::Const::_CONST_TOTAL_CELLS> flags;
    static std::tuple<int, int> cache[util::Const::_CONST_TOTAL_CELLS];

    if (!flags[this->_id]) {
      cache[this->_id] = std::tuple<int, int> { (this->_id
          / util::Const::_CONST_CELLS_IN_ROW), this->_id
          % util::Const::_CONST_CELLS_IN_ROW };

      flags[this->_id] = true;
    }

    return cache[this->_id];
  }

  inline std::tuple<int, int> columnInfo() const {
    static std::array<bool, util::Const::_CONST_TOTAL_CELLS> flags;
    static std::tuple<int, int> cache[util::Const::_CONST_TOTAL_CELLS];

    if (!flags[this->_id]) {
      cache[this->_id] = std::tuple<int, int> { (this->_id
          % util::Const::_CONST_CELLS_IN_ROW), this->_id
          / util::Const::_CONST_CELLS_IN_ROW };

      flags[this->_id] = true;
    }

    return cache[this->_id];
  }

  inline std::tuple<int, int> rankInfo() const {
    static std::array<bool, util::Const::_CONST_TOTAL_CELLS> flags;
    static std::tuple<int, int> cache[util::Const::_CONST_TOTAL_CELLS];

    if (!flags[this->_id]) {
      cache[this->_id] = std::tuple<int, int> { (this->_id
          / util::Const::_CONST_CELLS_IN_RANK), this->_id
          % util::Const::_CONST_CELLS_IN_RANK };

      flags[this->_id] = true;
    }

    return cache[this->_id];
  }

  inline std::tuple<int, int> stackInfo() const {
    static std::array<bool, util::Const::_CONST_TOTAL_CELLS> flags;
    static std::tuple<int, int> cache[util::Const::_CONST_TOTAL_CELLS];

    if (!flags[this->_id]) {
      // TODO simplify calc
      cache[this->_id] = std::tuple<int, int> { (this->_id
          % util::Const::_CONST_CELLS_IN_ROW)
          / (util::Const::_CONST_CELLS_IN_ROW
              / util::Const::_CONST_STACKS_IN_ROW), ((this->_id
          / util::Const::_CONST_CELLS_IN_ROW)
          * (util::Const::_CONST_CELLS_IN_ROW
              / util::Const::_CONST_STACKS_IN_ROW))
          + (this->_id % util::Const::_CONST_STACKS_IN_ROW) };

      flags[this->_id] = true;
    }

    return cache[this->_id];
  }

  inline static int fromBlock(int block, int offset) {
    return (block * util::Const::_CONST_CELLS_IN_BLOCK) + offset;
  }

  inline static int fromRow(int row, int offset) {
    return (row * util::Const::_CONST_CELLS_IN_ROW) + offset;
  }

  inline static int fromColumn(int column, int offset) {
    return (column * util::Const::_CONST_CELLS_IN_COLUMN) + offset;
  }

  inline static int fromRank(int rank, int offset) {
    return (rank * util::Const::_CONST_CELLS_IN_RANK) + offset;
  }

  inline static int fromStack(int stack, int offset) {
    return (stack * util::Const::_CONST_CELLS_IN_STACK) + offset;
  }

  inline static int fromXY(int row, int column) {
    return (row * util::Const::_CONST_BOARD_SIZE) + column;
  }

  inline std::ostream& operator<<(std::ostream &os) {
    os << this->_id;
    return os;
  }

private:
  int _id;

};

extern std::ostream& operator<<(std::ostream &os,
    const sudoku::game::cell::Id &id);

} // ns cell
} // ns game
} // bs sudoku

#endif /* SUDOKU_ID_H */
