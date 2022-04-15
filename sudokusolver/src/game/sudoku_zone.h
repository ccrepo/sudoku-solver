//
// sudoku_zone.h
// sudoku
//

#ifndef SUDOKU_ZONE_H
#define SUDOKU_ZONE_H

#include <vector>
#include <memory>
#include <string>
#include <variant>

#include "sudoku_const.h"
#include "sudoku_collection.h"

namespace sudoku {
namespace zone {
class Block;
class Row;
class Column;
class Rank;
class Stack;
}

namespace game {

class Cells;

class Zone {
  
public:
  virtual ~Zone() {
  }

  virtual size_t size() const = 0;

  inline bool inited() const {
    return _inited;
  }

  virtual bool solved(int id, int value,
      const util::all_cells_array &cells) const = 0;

protected:
  Zone(int id) :
      _inited(false) {
  }

private:
  Zone() = delete;
  
protected:
  bool _inited;

};

} // ns game
} // ns sudoku

#endif /* SUDOKU_ZONE_H */
