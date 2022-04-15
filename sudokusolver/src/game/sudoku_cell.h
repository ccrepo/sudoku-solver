//
// sudoku_cell.h
// sudoku
//

#ifndef SUDOKU_CELL_H
#define SUDOKU_CELL_H

#include <vector>
#include <memory>
#include <iostream>

#include "sudoku_math.h"
#include "sudoku_id.h"
#include "sudoku_collection.h"
#include "sudoku_log.h"

namespace sudoku {
namespace util {
class Collection;
}

namespace game {

class Board;
class Zones;

class Cell {
  
public:
  Cell(const cell::Id &id) :
      _id(id), _value(0), _options(), _option_count(_options.size()) {
    std::fill(_options.begin(), _options.end(), true);
  }

  explicit Cell(int id) :
      _id(id), _value(0), _options(), _option_count(_options.size()) {
    std::fill(_options.begin(), _options.end(), true);
  }

  Cell(const Cell &cell) :
      _id(cell._id), _value(cell._value), _options(), _option_count(
          cell._option_count) {
    std::copy(cell._options.begin(), cell._options.end(),
        this->_options.begin());
  }

  Cell(int id, int value, size_t option_count,
      const std::array<bool, util::Const::_CONST_LEGALSYMBOLS_SIZE - 1> &options,
      int exclude = 0) :
      _id(id), _value(value), _options(options), _option_count(option_count) {
    if (exclude > 0) {
      if (this->_options[exclude - 1]) {
        this->_options[exclude - 1] = false;

        this->_option_count--;
      }
    } else if (value > 0 && _option_count) {
      for (size_t i(0); i < _options.size(); i++) {
        if (this->_options[i]) {
          this->_options[i] = false;

          this->_option_count--;
        }
      }
    }
  }

  Cell& operator=(const Cell &cell) {
    this->_id = cell._id;
    this->_value = cell._value;
    this->_option_count = cell._option_count;

    std::copy(cell._options.begin(), cell._options.end(),
        this->_options.begin());

    return (*this);
  }

  virtual ~Cell() {
  }

  inline const cell::Id& id() const {
    return this->_id;
  }

  inline int value() const {
    return this->_value;
  }

  inline const std::array<bool, util::Const::_CONST_LEGALSYMBOLS_SIZE - 1>& options() const {
    return this->_options;
  }

  inline int option() const {
    for (size_t i(0); i < _options.size(); i++) {
      if (_options[i]) {
        return i + 1;
      }
    }

    return 0;
  }

  inline size_t option_count() const {
    return this->_option_count;
  }

  inline operator const std::string() const {
    std::ostringstream os;

    os << this->value();

    if (sudoku::util::Logger < sudoku::util::LogDebug > ::isLevelOn()) {
      os << " [";
      std::for_each(_options.begin(), _options.end(), [&os](bool b) {
        os << b;
      });
      os << "/" << this->option_count() << "]";
    }

    return os.str();
  }

  bool solved(const std::shared_ptr<Zones> &zones,
      const util::all_cells_array &cells) const;

  //

  inline int rowNo() const {
    return this->_id.rowNo();
  }

  inline int columnNo() const {
    return this->_id.columnNo();
  }

  inline int blockNo() const {
    return this->_id.blockNo();
  }

  inline int rankNo() const {
    return this->_id.rankNo();
  }

  inline int stackNo() const {
    return this->_id.stackNo();
  }

  //

  inline std::tuple<int, int> rowInfo() const {
    return this->_id.rowInfo();
  }

  inline std::tuple<int, int> columnInfo() const {
    return this->_id.columnInfo();
  }

  inline std::tuple<int, int> blockInfo() const {
    return this->_id.blockInfo();
  }

  inline std::tuple<int, int> rankInfo() const {
    return this->_id.rankInfo();
  }

  inline std::tuple<int, int> stackInfo() const {
    return this->_id.stackInfo();
  }

  inline int encoding() const {
    return _encoding;
  }

private:
  cell::Id _id;
  int _value;
  std::array<bool, util::Const::_CONST_LEGALSYMBOLS_SIZE - 1> _options;
  size_t _option_count;
  int _encoding;

};

} // ns game
} // ns sudoku

#endif /* SUDOKU_CELL_H */
