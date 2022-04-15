//
// sudoku_move.h
// sudoku
//

#ifndef SUDOKU_MOVE_H
#define SUDOKU_MOVE_H

#include <iostream>
#include <sstream>
#include <deque>
#include <list>
#include <memory>

#include "sudoku_id.h"

namespace sudoku {
namespace game {

class Move {
  
public:
  Move(int row, int column, int value) :
      Move(row, column, value, util::Const::_CONST_MOVEWEIGHT_MAXWEIGHT) {
  }

  Move(int row, int column, int value, int weight) :
      _row(row), _column(column), _value(value), _weight(weight) {
  }

  virtual ~Move() {
  }

  Move(const Move &move) :
      _row(move._row), _column(move._column), _value(move._value), _weight(
          move._weight) {
  }

  Move& operator=(const Move &move) {
    this->_row = move._row;
    this->_column = move._column;
    this->_value = move._value;
    this->_weight = move._weight;

    return (*this);
  }

  inline int row() const {
    return this->_row;
  }

  inline int column() const {
    return this->_column;
  }

  inline int value() const {
    return this->_value;
  }

  inline operator const std::string() const {
    std::ostringstream os;

    if (this->_row == -1 && this->_column == -1 && this->_value == -1) {
      os << "-";
    } else {
      os << "[" << (this->_row + 1) << "," << (this->_column + 1) << " ("
          << (game::cell::Id::fromXY(_row, _column)) << ") " << this->weight()
          << "] -> " << this->_value << "";
    }

    return os.str();
  }

  inline static const Move& empty() {
    static const Move move(-1, -1, -1);

    return move;
  }

  inline bool isempty() const {
    return this->_column == -1 && this->_row == -1 && this->_value == -1;
  }

  inline bool operator==(const Move &move) const {
    return this->_row == move._row && this->_column == move._column
        && this->_value == move._value && this->_weight == move._weight;
  }

  inline bool operator<(const Move &move) const {
    if (this->_weight < move._weight) {
      return true;
    }

    if (this->_weight > move._weight) {
      return false;
    }

    if (this->_row < move._row) {
      return true;
    }

    if (this->_row > move._row) {
      return false;
    }

    if (this->_column < move._column) {
      return true;
    }

    if (this->_column > move._column) {
      return false;
    }

    return this->_value < move._value;
  }

  inline bool operator>(const Move &move) const {
    return (!this->operator<(move)) && (!operator==(move));
  }

  inline int weight() const {
    return this->_weight;
  }

  inline void weight(int weight) {
    this->_weight = weight;
  }

private:
  int _row;
  int _column;
  int _value;
  int _weight;

};

inline std::ostream& operator<<(std::ostream &os, const game::Move &move) {
  os << static_cast<std::ostringstream>(move).str();

  return os;
}

inline std::ostream& operator<<(std::ostream &os,
    const std::shared_ptr<sudoku::game::Move> &move) {
  os << static_cast<std::ostringstream>(*move).str();

  return os;
}

inline std::ostream& operator<<(std::ostream &os,
    const std::vector<game::Move> &moves) {
  os << "{ ";

  for (const auto &move : moves) {
    os << move << " ";
  }

  os << "}" << std::endl;

  return os;
}

} // ns game
} // bs sudoku

#endif /* SUDOKU_ID_H */
